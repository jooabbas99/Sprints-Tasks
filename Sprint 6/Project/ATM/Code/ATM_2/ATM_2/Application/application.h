/*
 * application.h
 *
 * Created: 5/6/2023 10:16:37 AM
 *  Author: Youssef Abbas
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../Utilities/types.h"
#define CARD_INSERTED	1
#define CARD_REMOVED	0
#define  KEYS_NO_PRESS 12
#define ATM_BLOKED_MODE	1
#define ATM_NORMAL_MODE	0
#define INVALID_PIN	0
#define PIN_LENTH	4


#define ACCOUNTS_DB_SIZE 255
#define TRANSACTIONS_DB_SIZE 255
#define PAN_size 20
#define ACC_NOT_FOUNT	0
#define ACC_FOUND	1
typedef enum EN_accountState_t
{
	BLOCKED=0,
	RUNNING=1,
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
	float balance;
	EN_accountState_t en_state;
	uint8 primaryAccountNumber[PAN_size];
}ST_accountsDB_t;


void appInit(void);
void appStart(void);


#endif /* APPLICATION_H_ */