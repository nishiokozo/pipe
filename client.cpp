#include <Windows.h>
#include <iostream>

int main()
{
    HANDLE pipeHandle = CreateFile(
    	TEXT("\\\\.\\pipe\\mynamedpipe"), 
    	GENERIC_READ, 
    	0, 
    	NULL, 
    	OPEN_EXISTING, 
    	0, 
    	NULL
    );
    if (pipeHandle == INVALID_HANDLE_VALUE)
    {
        std::cout << "パイプ作成に失敗" << std::endl;
        return 0 ;
    }

    std::cout << "サーバーから受信開始" << std::endl;

    // 文字列受信
    char recvBuffer[256];    //受信バッファ
    do
    {
        recvBuffer[0] = '\0';
        DWORD readBytes;
        ReadFile(pipeHandle, recvBuffer, sizeof(recvBuffer), &readBytes, NULL);
        if (recvBuffer[0] == '\0')
        {
            continue;
        }
        recvBuffer[readBytes] = '\0';
        std::cout << "受信: " << recvBuffer << std::endl;
    } while (strcmp(recvBuffer, "End") != 0);

    CloseHandle(pipeHandle);
}