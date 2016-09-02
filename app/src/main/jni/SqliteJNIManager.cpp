//
// Created by Next on 2016/8/12.
//

#include "com_commax_sqlitejnitest_SqliteJNIManager.h"
#include "db/DbHandler.h"

JNIEXPORT void JNICALL Java_com_commax_sqlitejnitest_SqliteJNIManager_readAllDevices
        (JNIEnv *env, jclass type) {

    DbHandler* dbHandler = new DbHandler(env);
    dbHandler->dbOpen();
    dbHandler->getDbDeviceInfo();

}


JNIEXPORT void JNICALL Java_com_commax_sqlitejnitest_SqliteJNIManager_addDeviceToDB
        (JNIEnv *env, jclass type) {
    LOGD("Java_com_commax_sqlitejnitest_SqliteJNIManager_addDeviceToDB 호출");


    //이 파일을 제외한 다른 클래스는 Android.mk에 선언하지 않아도 됨.



    //클래스의 객체를 생성해서 메소드 호출하는 방법
    //PacketRouter* packetRouter = new PacketRouter();
    //packetRouter->getString();




    //클래스의 static 메소드를 호출하는 방법
    //PacketRouter::getString();
    //헤더파일에 char static * getString(); 이렇게 static으로 선언해야 함.









    //(*env)->NewStringUTF(env, packetRouter->getString()); 이렇게 사용하면 오류발생하고
    //env->NewStringUTF(packetRouter->getString()); 이렇게 env에 파라미터는 하나여야 함





    //PacketRouter* packetRouter = new PacketRouter();
    DbHandler* dbHandler = new DbHandler(env);
    dbHandler->dbOpen();
    dbHandler->addDeviceToDB();

}

/*
 * Class:     om_commax_sqlitejnitest_SqliteJNIManager
 * Method:    doAdd
 * Signature: (II)I
 */
JNIEXPORT void JNICALL Java_com_commax_sqlitejnitest_SqliteJNIManager_removeDeviceOnDB
        (JNIEnv *env, jclass type) {
    DbHandler* dbHandler = new DbHandler(env);
    dbHandler->dbOpen();
    dbHandler->removeDeviceOnDB();


}






