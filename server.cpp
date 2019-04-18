#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	char buf[256];
	HANDLE hdl = CreateNamedPipe(
		TEXT("\\\\.\\pipe\\mynamedpipe"),
		PIPE_ACCESS_OUTBOUND, 
		PIPE_TYPE_MESSAGE,
		1,
		sizeof(buf),
		sizeof(buf),
		1000, 
		NULL
	);
	if (hdl == INVALID_HANDLE_VALUE)
	{
		std::cout << "パイプ作成に失敗" << std::endl;
		return 1;
	}

	std::cout << "クライアント起動待ち.." << std::endl;
	ConnectNamedPipe(hdl, NULL);

	buf[0] = '\0';
	do
	{
		std::cout << "送信する文字を入力(Endで終了): ";
		std::cin >> buf;
		DWORD dwResult;
		WriteFile( hdl, buf, strlen(buf) + 1, &dwResult, NULL);
	} while (strcmp(buf, "End") != 0);

	CloseHandle(hdl);
}
/*

*/
