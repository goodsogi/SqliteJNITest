
/******************************************************
  NAME     : DbHandler.H
  Coded by : �� ����
  Revision : 1.0
  Date     : 2007/02/24 ~


*/

// sqlite3

#ifndef __DbHandler_H__
#define __DbHandler_H__

#include "sqlite3.h"
#include "../log.h"
#include "../../../../../../../Library/Android/sdk/ndk-bundle/platforms/android-23/arch-arm/usr/include/jni.h"


#include <stdio.h>
#include <string.h> // strcmp
#include <stdlib.h> // atoi

#include <pthread.h>



#define SUCCESS 1
#define FAIL 0


#define dbName "/user/app/bin/standard_ver2.0.db"


const int unsigned dbOk = 0;

class DbHandler {

	
	public:

		DbHandler();

	DbHandler(_JNIEnv *pEnv);

	~DbHandler();
		
		static int callback(void *, int , char ** , char **);

		static int dbOpen();


		static int getDbDeviceInfo();


	_JNIEnv *mEnv;

	int addDeviceToDB();

	int removeDeviceOnDB();
};

#endif

