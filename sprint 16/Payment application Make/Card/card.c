

//
// Created by Sara Mohamed.
//

#include "card.h"
EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
    printf("Pleas enter cardholder name : \n# Max letters is 24 and min is 20 #\n");
    fgets((char *)cardData->cardHolderName,sizeof(cardData->cardHolderName), stdin);
    int8_t nameSize = strlen((char *)cardData->cardHolderName);
    if(nameSize > 24 || nameSize < 20)
        return WRONG_NAME;
    return CARD_OK;
}


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
    printf("Pleas enter card expiry date : \n# Format MM/YY #\n");
    fgets((char *)cardData->cardExpirationDate,sizeof(cardData->cardExpirationDate), stdin);
    int8_t dateSize = strlen((const char *)cardData->cardExpirationDate);

    if(dateSize != 5 ){
        return WRONG_EXP_DATE;
    }
    // check formatting MM/YY
    regex_t regex;
    int reti;
    reti = regcomp(&regex, "^[0-9]{2}/[0-9]{2}$", REG_EXTENDED);
    reti = regexec(&regex, (const char *)cardData->cardExpirationDate, 0, NULL, 0);
    regfree(&regex);
    if (reti) {
        return WRONG_EXP_DATE;
    }
    return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData){
    printf("Pleas enter Primary Account Number : \n# 16~19 Numbers #\n");
    fgets((char *)cardData->primaryAccountNumber,sizeof(cardData->cardExpirationDate), stdin);
    int8_t PANSize = strlen((char *)cardData->primaryAccountNumber);

    if(PANSize > 19 || PANSize < 16 ){
        return WRONG_PAN;
    }
    // check formatting Numeric
    regex_t regex;
    int reti;
    reti = regcomp(&regex, "^[0-9]+$", REG_EXTENDED);
    reti = regexec(&regex, (const char *) cardData->primaryAccountNumber, 0, NULL, 0);
    regfree(&regex);
    if (reti) {
        return WRONG_PAN;
    }
    return CARD_OK;

}
