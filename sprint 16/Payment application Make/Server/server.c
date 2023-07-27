#include "server.h"
//Implement server-side accounts database
//Create a global array of ST_accountsDB_t for the valid accounts' database.
ST_accountsDB_t accountsDB[ACCOUNTS_DB_SIZE]={
        {2000.0, RUNNING, "8989374615436850"},
        {1000.0, BLOCKED, "1025358796325690"},
        {1000.0, RUNNING, "9856874521563250"},
        {5000.0, BLOCKED, "1234567891234560"},
        {300.00, RUNNING, "9632569547856965"},
        {1250.0, BLOCKED, "0526842055286340"},
        {1500.5, RUNNING, "4521478332156640"},
        {8000.0, BLOCKED, "3695214854623250"},
        {8000.1, RUNNING, "6523158469753250"},
        {100000.0,BLOCKED,"8956302301546840"}
};
//Implement server-side transactions database
//Create a global array of ST_transaction_t.
ST_transaction_t transaction[TRANSACTIONS_DB_SIZE]={0};

//global variable to keep track number of transaction saved
static uint32_t Inc_Number=0;
//this function will take card data and validate if the account related to this card exists or not.
//It checks if the PAN exists or not in the server's database (searches for the card PAN in the DB).
EN_serverError_t isValidAccount(ST_cardData_t *cardData,ST_accountsDB_t *accountRefrence) 
{
  for (int x = 0; x < ACCOUNTS_DB_SIZE; x++) {
    if (strcmp((const char *)cardData->primaryAccountNumber,
               (const char *)accountsDB[x].primaryAccountNumber) == 0) {
      *accountRefrence = accountsDB[x];
      return SERVER_OK;
    }
  }
  return ACCOUNT_NOT_FOUND;
}

/*
This function takes a reference to the account into the database and verifies if it is blocked or not
If the account is running it will return SERVER_OK, else if the account is blocked it will return BLOCKED_ACCOUNT.
*/
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
    if(accountRefrence->state == RUNNING)
        return SERVER_OK;
    return BLOCKED_ACCOUNT;
}

/*
This function will take terminal data and a reference to the account in the database
and check if the account has a sufficient amount to withdraw or not
It checks if the transaction's amount is available or not.
*/
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence)
{
    if(accountRefrence->balance < termData->transAmount){
        return LOW_BALANCE;
    }
    return SERVER_OK;
}

//This function prints all transactions found in the transactions DB
void listSavedTransactions(void)
{
    uint8_t count=0;
    if(Inc_Number == 0){
        printf("<<<<No transactions found>>>>\n");
        return;
    } else{
        while(count<Inc_Number)
        {
            printf("#########################\n");
            printf("Transaction Sequence Number:%d\n",transaction[count].transactionSequenceNumber);
            printf("Transaction Date:%s\n",transaction[count].terminalData.transactionDate);
            printf("Transaction Amount:%f\n",transaction[count].terminalData.transAmount);
            switch (transaction[count].transState)
            {
                case APPROVED:
                    printf("Transaction State:APPROVED\n");
                    break;
                case DECLINED_INSUFFECIENT_FUND:
                    printf("Transaction State:INSUFFECIENT_FUND\n");
                    break;
                case DECLINED_STOLEN_CARD:
                    printf("Transaction State:STOLEN_CARD\n");
                    break;
                case FRAUD_CARD:
                    printf("Transaction State:FRAUD_CARD\n");
                    break;
                case INTERNAL_SERVER_ERROR:
                    printf("Transaction State:INTERNAL_SERVER_ERROR\n");
                    break;
                default:
                    printf("Transaction State:NOT AVAILABLE\n");
                    break;

            }
            printf("Terminal Max Amount:%f\n",transaction[count].terminalData.maxTransAmount);
            printf("Card holder Name:%s\n",transaction[count].cardHolderData.cardHolderName);
            printf("PAN:%s\n",transaction[count].cardHolderData.primaryAccountNumber);
            printf("Card Expiration Date:%s\n",transaction[count].cardHolderData.cardExpirationDate);
            printf("#########################\n");
            count++;
        }
    }

}



/*
This function will store all transaction data in the transactions database.
It gives a sequence number to a transaction, this number is incremented once a transaction is
processed into the server, you must check the last sequence number in the server to give the
new transaction a new sequence number
*/
EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    if(Inc_Number < TRANSACTIONS_DB_SIZE)
    {
        strncpy((char *)transaction[Inc_Number].cardHolderData.cardExpirationDate , (char *)transData->cardHolderData.cardExpirationDate,sizeof(transData->cardHolderData.cardExpirationDate));
        strncpy((char *)transaction[Inc_Number].cardHolderData.cardHolderName , (char *)transData->cardHolderData.cardHolderName,sizeof(transData->cardHolderData.cardHolderName));
        memcpy(transaction[Inc_Number].cardHolderData.primaryAccountNumber , transData->cardHolderData.primaryAccountNumber,sizeof(transData->cardHolderData.primaryAccountNumber));
        memcpy(transaction[Inc_Number].terminalData.transactionDate , transData->terminalData.transactionDate,sizeof (float));
        transaction[Inc_Number].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;
        transaction[Inc_Number].terminalData.transAmount = transData->terminalData.transAmount;
        transaction[Inc_Number].transState=transData->transState;
        transaction[Inc_Number].transactionSequenceNumber=Inc_Number;
        Inc_Number++;
        return SERVER_OK;
    }
    else
        return SAVING_FAILED;
}

//This function will take all transaction data and validate its data
//It checks the account details and amount availability.
EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{

    ST_accountsDB_t account_ref;

    if(isValidAccount(&(transData->cardHolderData),&account_ref) != SERVER_OK) {
        transData->transState = FRAUD_CARD;
        return FRAUD_CARD;
    }
    if(isBlockedAccount(&account_ref) != SERVER_OK) {
        transData->transState = DECLINED_STOLEN_CARD;
        return DECLINED_STOLEN_CARD;
    }
    if(isAmountAvailable(&(transData->terminalData),&account_ref) != SERVER_OK) {
        transData->transState = DECLINED_INSUFFECIENT_FUND;
        return DECLINED_INSUFFECIENT_FUND;
    }
    transData->transState = APPROVED;
    if(saveTransaction(transData) != SERVER_OK) {
        return INTERNAL_SERVER_ERROR;
    }
    account_ref.balance -= transData->terminalData.transAmount;

    for(int x=0; x < ACCOUNTS_DB_SIZE; x++)
    {
        if(strcmp((const char *)account_ref.primaryAccountNumber ,(const char *)accountsDB[x].primaryAccountNumber) == 0){
            accountsDB[x].balance = account_ref.balance;
            return APPROVED;
        }
    }

    return INTERNAL_SERVER_ERROR;

}


void isValidAccountTest(void)
{
    ST_accountsDB_t ref;
    ST_cardData_t test;			//8989374615436850,1025358796325690
    uint32_t result;
    strcpy((char *)test.primaryAccountNumber,"1234");
    result=isValidAccount(&test,&ref);
    if(result==0)
    {
        printf("balance=%f\n",ref.balance);
        printf("PAN=%s\n",ref.primaryAccountNumber);
        switch(ref.state)
        {
            case RUNNING:
                printf("account status:running");
                break;
            case BLOCKED:
                printf("account status:blocked");
                break;
        }
    }
    else
    {
        printf("account don't exist");
    }
}


void isBlockedAccountTest(void)
{
    EN_serverError_t result;
    ST_accountsDB_t accountRefernce;
    ST_cardData_t test={"hazem","8989374615436850","12345"};		//8989374615436850,1025358796325690
    result=isValidAccount(&test,&accountRefernce);
    if(result==SERVER_OK)
    {
        result=isBlockedAccount(&accountRefernce);
        if(result==SERVER_OK)
            printf("account status:running");
        else if(result == BLOCKED_ACCOUNT)
            printf("account status:blocked");
    }
    else
        printf("account don't exist");
}


void isAmountAvailableTest(void)
{
    EN_serverError_t result;
    ST_accountsDB_t accountRefernce;
    ST_cardData_t test={"hazem","8989374615436850","12345"};		//8989374615436850,1025358796325690
    ST_terminalData_t terminalRefernce={200,100,"31/3/2023"};
    result=isValidAccount(&test,&accountRefernce);
    if(result==SERVER_OK)
    {
        result=isAmountAvailable(&terminalRefernce, &accountRefernce);
        if(result==SERVER_OK)
            printf("amount available");
        else if(result == LOW_BALANCE)
            printf("no sufficient amount available");
    }
    else
        printf("account don't exist");

}

void saveTransactionTest(void)
{
    EN_serverError_t result;
    ST_transaction_t transactionTest;

    strcpy((char *)transactionTest.cardHolderData.cardHolderName,"hazem ashraf");
    strcpy((char *)transactionTest.cardHolderData.cardExpirationDate,"05/25");
    strcpy((char *)transactionTest.cardHolderData.primaryAccountNumber,"7894561231234568");
    transactionTest.terminalData.maxTransAmount=5000;
    transactionTest.terminalData.transAmount=8500;
    strcpy((char *)transactionTest.terminalData.transactionDate,"31/3/2023");
    transactionTest.transState=DECLINED_STOLEN_CARD;
    result=saveTransaction(&transactionTest);
    if(result==SERVER_OK)
        printf("saving success\n");
    else
        printf("saving failed\n");
    listSavedTransactions();
}


void recieveTransactionDataTest(void)
{
    EN_transState_t result;
    ST_transaction_t transactionTest;
    strcpy((char *)transactionTest.cardHolderData.cardHolderName,"hazem ashraf");
    strcpy((char *)transactionTest.cardHolderData.cardExpirationDate,"05/25");
    strcpy((char *)transactionTest.cardHolderData.primaryAccountNumber,"9856874521563250");
    strcpy((char *)transactionTest.terminalData.transactionDate,"31/3/2023");
    transactionTest.terminalData.maxTransAmount=5000;
    transactionTest.terminalData.transAmount=1000;
    result=recieveTransactionData(&transactionTest);
    if(result==SERVER_OK)
        printf("saving success\n");
    else
        printf("saving failed\n");
    strcpy((char *)transactionTest.cardHolderData.cardHolderName,"hazem ashraf");
    strcpy((char *)transactionTest.cardHolderData.cardExpirationDate,"05/25");
    strcpy((char *)transactionTest.cardHolderData.primaryAccountNumber,"9856874521563250");
    strcpy((char *)transactionTest.terminalData.transactionDate,"31/3/2023");
    transactionTest.terminalData.maxTransAmount=5000;
    transactionTest.terminalData.transAmount=1000;
    result=recieveTransactionData(&transactionTest);
    if(result==SERVER_OK)
        printf("saving success\n");
    else
        printf("saving failed\n");
    strcpy((char *)transactionTest.cardHolderData.cardHolderName,"hazem ashraf");
    strcpy((char *)transactionTest.cardHolderData.cardExpirationDate,"05/25");
    strcpy((char *)transactionTest.cardHolderData.primaryAccountNumber,"8989374615436850");
    strcpy((char *)transactionTest.terminalData.transactionDate,"31/3/2023");
    transactionTest.terminalData.maxTransAmount=5000;
    transactionTest.terminalData.transAmount=200;
    result=recieveTransactionData(&transactionTest);
    if(result==SERVER_OK)
        printf("saving success\n");
    else
        printf("saving failed\n");
    listSavedTransactions();
}
