#include "stdafx.h"
#include "AES.h"
//加密某文件
void AESEncryptFile(string filePath, string _key)
{
	//从文件读取流
	unsigned char* key = (unsigned char*)const_cast<char*>(_key.c_str());
	unsigned char* buffer;
	long size;
	ifstream readStream(filePath, ios::binary | ios::out | ios::ate);// 
	size = readStream.tellg();
	readStream.seekg(0,ios::beg);
	buffer = new unsigned char[size];
	readStream.read((char*)buffer, size);
	readStream.close();

	//加密
	AES aes((unsigned char*)key);
	buffer = aes.Cipher(buffer);

	//将文件流写入新文件
	int dotIndex = filePath.rfind(".");
	string type = filePath.substr(dotIndex+1);
	int typeLength = type.length();
	string totalPath = filePath.substr(0, dotIndex)+"Encry.exe";
	totalPath.c_str();
	ofstream writeStream(totalPath, ios::binary | ios::ate | ios::out);
	writeStream << typeLength;
	writeStream.write((char*)type.c_str(),typeLength);
	writeStream.write((char*)buffer,size);
	writeStream.close();


	//从新文件中再次读取流
	int typeLength2;
	unsigned char* type2;
	unsigned char* binaryData;
	ifstream readStream2(totalPath, ios::binary | ios::out| ios::ate);
	int theLength = readStream2.tellg();//获得流长度
	readStream2.seekg(0, ios::beg);//复位
	readStream2 >> typeLength2;
	type2 = new unsigned char[typeLength2];
	readStream2.read((char*)type2, typeLength2);
	int position = readStream2.tellg();
	//readStream2.seekg(position, ios::beg);//这里有个坑，需要位移一位
	binaryData = new unsigned char[theLength- position];
	readStream2.read((char*)binaryData, theLength - position);
	readStream2.close();

	//解密
	binaryData = aes.InvCipher(binaryData);

	//将新文件流再次写入下个新文件
	ofstream writeStream2(filePath.substr(0, dotIndex)+ "Decry.exe", ios::binary | ios::ate | ios::out);
	writeStream2.write((char*)binaryData,theLength - position);
	writeStream2.close();


	delete[] buffer;
}
int main(int argc, char* argv[])
{
	AESEncryptFile("C:\\Users\\zhoukb\\Desktop\\测试\\JUCEGUIPractise.exe","1234");
	//cout << "请输入密码:" << endl;
	//string key = string();
	//cin >> key;
	//char* ckey=const_cast<char*>(key.c_str());	
	//AES aes((unsigned char*)ckey);

	//string hello = "hello world";
	//cout << "加密前字符串：" + hello << endl;
	//unsigned char* csHello = (unsigned char*)const_cast<char*>(hello.c_str());

	//unsigned char* encry = aes.Cipher(csHello);
	//string hello2 = string((char* )encry);
	//cout <<"加密后字符串："<< hello2 << endl;

	//unsigned char* decrypt = aes.InvCipher(encry);
	//string hello3 = string((char*)decrypt);
	//cout << "解密后字符串：" << hello3 << endl;

	system("pause");
	return 0;
}
