// system include
#include <string.h>
#include <stdlib.h> // atoi();

// local include
#include "DbHandler.h"
#include "../../../../../../../Library/Android/sdk/ndk-bundle/platforms/android-23/arch-arm/usr/include/jni.h"


sqlite3 *db = 0;



DbHandler::DbHandler()
{


}

DbHandler::~DbHandler()
{


}

int DbHandler::dbOpen()
{

  int ret = 0;
  
  ret = sqlite3_open(dbName, &db);

  if( ret ){
	  LOGD("sqlite3_open fail");
	sqlite3_close(db);


    return FAIL;
  }

	LOGD("sqlite3_open success");
  return SUCCESS;
}

/**
	Descrition

	The callback function may be NULL, even for queries.
	A NULL callback is not an error. 
	It just means that no callback will be invoked.

*/


int DbHandler::addDeviceToDB()
{

	char *zErrMsg = 0;
	int ret = 0;

	//insert를 하기 위해서 db 파일을 열 수는 없음. db 파일을 읽을 수는 있으나 쓸 수는 없음. 파일 권한과는 별개의 문제인 듯함. db 파일은 앱 내부 메모리로 복사한 다음 처리하고 다시 해당 경로로 복사하는 방법
	//을 사용해야 할 것 같음.
	ret = sqlite3_exec(db, "insert into deviceinfo (deviceType,protocolCompany,deviceCount, UartPort) values (\"퍼킹 두리안\",\"wang\",\"1\", \"kong\")" ,0, 0, &zErrMsg);
	sqlite3_close(db);
	if( ret != SQLITE_OK ){
		LOGD(zErrMsg);
		sqlite3_free(zErrMsg);

		LOGD("addDeviceToDB fail");
		return FAIL;
	}


	LOGD("addDeviceToDB success");
	return SUCCESS;
}


int DbHandler::getDbDeviceInfo()
{

	char *zErrMsg = 0;
	int ret = 0;

	ret = sqlite3_exec(db, "select * from deviceinfo" , DbHandler::callback, 0, &zErrMsg);
	sqlite3_close(db);
	if( ret != SQLITE_OK ){
		LOGD(zErrMsg);
		sqlite3_free(zErrMsg);
		LOGD("getDbDeviceInfo fail");

		return FAIL;
	}


	LOGD("getDbDeviceInfo success");
	return SUCCESS;
}




int DbHandler::removeDeviceOnDB()
{

    char *zErrMsg = 0;
	int ret = 0;	

	ret = sqlite3_exec(db, "select * from deviceinfo" , DbHandler::callback, 0, &zErrMsg);
	sqlite3_close(db);
    if( ret != SQLITE_OK ){
		LOGD(zErrMsg);
	     sqlite3_free(zErrMsg);
		LOGD("removeDeviceOnDB fail");

		 return FAIL;
	}


	LOGD("removeDeviceOnDB success");
	return SUCCESS;
}


int DbHandler::callback(void *NotUsed, int columnCount, char ** columnContents, char ** columnName)
{

	LOGD("callback 들어옴");


	for(int index = 0; index < columnCount; index++ ) {
		LOGD(columnContents[index]);
	}




	
	return dbOk;
}


DbHandler::DbHandler(JNIEnv *env) {
 mEnv = env;
}
