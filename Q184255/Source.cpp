#include<iostream>
#include<string>
#include<fstream>
#include<assert.h>
#include<Windows.h>
using namespace std;

int UnicodeToANSI(char * pDes, const wchar_t * pSrc)
{
	assert(pDes != NULL);
	assert(pSrc != NULL);
	int nLen = ::WideCharToMultiByte(CP_ACP, 0, pSrc, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
	{
		return -1;
	}
	return ::WideCharToMultiByte(CP_ACP, 0, pSrc, -1, pDes, nLen, NULL, NULL);
}
int main()
{
	const int maxbytes = 50;
	wchar_t wbuf[2];
	memset(wbuf, 0, sizeof(wchar_t) * 2);
	FILE *fp = NULL;
	FILE *outf = NULL;
	fopen_s(&fp, "D:\\Program Files\\新东方背单词5\\3K.txt", "rb");  //unicode text file
	fopen_s(&outf, "D:\\Program Files\\新东方背单词5\\test.txt", "w");  //ansi text file
	if (fp != NULL)//&&outf!=NULL)
	{
		fseek(fp, sizeof(wchar_t), 0);
		while (1)
		{
			char temp[2] = { 0 };
			fread(wbuf, sizeof(wchar_t), 1, fp);
			UnicodeToANSI(temp, wbuf);
			wchar_t widec = '!';
			if (wbuf[0] == widec)
			{
				break;
			}
			//cout << temp;
			fputs(temp, outf);
			memset(wbuf, 0, sizeof(wchar_t) * 2);
		}
	}
	memset(wbuf, 0, sizeof(wchar_t) * 2);
	fclose(fp);
	fclose(outf);
	return 0;
}