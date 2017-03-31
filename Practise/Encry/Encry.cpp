#include "stdafx.h"
#include "AES.h"

int main(int argc, char* argv[])
{
	//AESHelper::AESEncryptDirFiles("C:\\Users\\zhoukb\\Desktop\\姜维","1234",false);
	//bool isRIght=AESHelper::AESDEcryptDirFiles("C:\\Users\\user\\Desktop\\测试", "1234", false);
	//cout << isRIght << endl;
	//AESHelper::EncryCurrentDir("1234");
	bool isRight=AESHelper::DecryCurrentDir("1234");
	//cout << isRight << endl;
	system("pause");
	return 0;
}