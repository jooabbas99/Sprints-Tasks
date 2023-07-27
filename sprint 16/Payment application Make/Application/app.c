
//
// Created by Youssef Abbas on 29/03/2023.
//

#include "app.h"
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
/*
 *      APPLICATION FLOW
 *      STEP 1: GET CARD INFORMATION
 *              - READ CARDHOLDER NAME
 *              - GET EXPIRATION DATE
 *              - GET CARD PAN
 *      STEP 2: SETUP TERMINAL INFO
 *              - CHECK CARD EXPIRATION
 *              - GET TRANSACTION AMOUNT
 *              - CHECK FOR EXCEEDED AMOUNT (INTERNAL FOR TERMINAL)
 *      STEP 3 : REQUEST TRANSACTION FROM SERVER (BANK)
 *              - CHECK ACCOUNT VALIDATION
 *              - CHECK AMOUNT AVAILABILITY IN ACCOUNT
 *              - UPDATE ACCOUNT BALANCE
 *              - STORE TRANSACTION
 */


/*
 * TEST 1
 * As a bank customer have an account and has a valid and not expired card,
 * I want to withdraw an amount of money less than the maximum allowed and less than or equal to the amount in my balance,
 * so that I am expecting that the transaction is approved and my account balance is reduced by the withdrawn amount.
 * {2000.0, RUNNING, "8989374615436850"},
 *
 * TEST 2
 * As a bank customer have an account,
 * that has a valid and not expired card,
 * I want to withdraw an amount of money that exceeds the maximum allowed amount
 * so that I am expecting the transaction declined.
 *{8000.1, RUNNING, "6523158469753250"},
 *
 * TEST 3
 * As a bank customer have an account and has a valid and not expired card,
 * I want to withdraw an amount of money less than the maximum allowed and larger than the amount in my balance
 * so that I am expecting that the transaction declined.
 *{300.00, RUNNING, "9632569547856965"},
 *
 * TEST 4
 * As a bank customer have an account and a valid but expired card,
 * I want to withdraw an amount of money so that I expect that the transaction declined
 * {1500.5, RUNNING, "4521478332156640"},
 *
 * TEST 5
 * As a bank customer have an account and has a valid and not expired but stolen card,
 * I want to block anyone from using my card so that I am expecting that any transaction made by this card is declined.
 *{100000.0,BLOCKED,"8956302301546840"}
 */
void appStart(){
    while (1){
        float max_amount ;

        // Define Variables and data
        ST_transaction_t transactionData;

        // CARD
        printf("\n\t\t\t\tNew Transaction\n");
        while(getCardHolderName(&transactionData.cardHolderData)==WRONG_NAME){
            printf("WRONG NAME FORMAT\n");
        }
        while(getCardExpiryDate(&transactionData.cardHolderData)==WRONG_EXP_DATE){
            printf("WRONG_EXP_DATE\n");
        }
        while(getCardPAN(&transactionData.cardHolderData)==WRONG_PAN){
            printf("WRONG_PAN\n");
        }
        // TERMINAL
        // set terminal maxaamount
        do{
            printf("Setup MAX AMOUNT for POS Device :");
            scanf(" %f",&max_amount);
        } while (setMaxAmount(&transactionData.terminalData,max_amount) == INVALID_MAX_AMOUNT);

        // get transaction date
        while(getTransactionDate(&transactionData.terminalData)==WRONG_DATE) {
            printf("WRONG_DATE\n");
        }
        // check card expires
        if(isCardExpired(&transactionData.cardHolderData,&transactionData.terminalData)!=TERMINAL_OK){
            printf("TRANSACTION DECLINED : EXPIRED_CARD\n");
            continue;
        }

        // get transaction amount

        while(getTransactionAmount(&transactionData.terminalData)==INVALID_AMOUNT) {
            printf("INVALID_AMOUNT\n");
        }
        // check if amount exceeded

        if(isBelowMaxAmount(&transactionData.terminalData)==EXCEED_MAX_AMOUNT){
            printf("EXCEED_MAX_AMOUNT\n");
            continue;
        }

        // SERVER
        // check account validation
        switch (recieveTransactionData(&transactionData)) {
            case FRAUD_CARD:
                printf("FRAUD_CARD\n");
                break;
            case DECLINED_STOLEN_CARD:
                printf("DECLINED_STOLEN_CARD\n");
                break;
            case DECLINED_INSUFFECIENT_FUND:
                printf("DECLINED_INSUFFECIENT_FUND\n");
                break;
            case INTERNAL_SERVER_ERROR:
                printf("INTERNAL_SERVER_ERROR\n");
                break;
            case APPROVED:
                printf("APPROVED\n");
                listSavedTransactions();
                break;
            default:
                printf("SERVER ERROR\n");
                break;
        }

    }

}
