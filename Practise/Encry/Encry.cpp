#include "stdafx.h"
#include "AES.h"
//加密某文件
void AESEncryptFile(string filePath, string _key)
{
	unsigned char* key = (unsigned char*)const_cast<char*>(_key.c_str());
	char* buffer;
	long size;
	ifstream readStream(filePath, ios::binary| ios::out | ios::ate);
	size = readStream.tellg();
	size -= 1;
	readStream.seekg(0,ios::beg);
	buffer = new char[size];
	readStream.read(buffer, size);
	readStream.close();

	cout <<"buffer长度："<<("%s", buffer) << endl;
	delete[] buffer;
}
int main(int argc, char* argv[])
{
	AESEncryptFile("C:\\Users\\zhoukb\\Desktop\\测试\\新建文本文档.txt","1234");
	/*cout << "请输入密码:" << endl;
	string key = string();
	cin >> key;
	char* ckey=const_cast<char*>(key.c_str());	
	AES aes((unsigned char*)ckey);

	string hello = "hello world";
	cout << "加密前字符串：" + hello << endl;
	unsigned char* csHello = (unsigned char*)const_cast<char*>(hello.c_str());

	unsigned char* encry = aes.Cipher(csHello);
	string hello2 = string((char* )encry);
	cout <<"加密后字符串："<< hello2 << endl;

	unsigned char* decrypt = aes.InvCipher(encry);
	string hello3 = string((char*)decrypt);
	cout << "解密后字符串：" << hello3 << endl;
*/

	system("pause");
	return 0;
}
