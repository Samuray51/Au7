#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "netapi32.lib")

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <lm.h>
#include <sddl.h>               /* for ConvertSidToStringSid function */

int wmain()
{
	DWORD dwLevel = 1;

	LPUSER_INFO_0 pBuf = NULL;
	LPUSER_INFO_1 pBuf1 = NULL;


	NET_API_STATUS nStatus;

	LPTSTR sStringSid = NULL;

	int i = 0;

	wchar_t mas[21];
	wprintf(L"Input username:\n");
	while (mas[i - 1] != '\n') 
	{
		wscanf_s(L"%c", &mas[i], 1);
		i++;
	}
	mas[i - 1] = '\0';

	nStatus = NetUserGetInfo(NULL, mas, dwLevel, (LPBYTE *)& pBuf);

	if (nStatus == NERR_Success)
	{
		if (pBuf != NULL)
		{
			pBuf1 = (LPUSER_INFO_1)pBuf;
			wprintf(L"\tUser account name: %s\n", pBuf1->usri1_name);
			wprintf(L"\tPassword age (days): %d\n", pBuf1->usri1_password_age/86400);
			wprintf(L"\tPrivilege level: %d — ", pBuf1->usri1_priv);
			if (pBuf1->usri1_priv == 1)
				printf("Simple user\n");
			else if (pBuf1->usri1_priv == 2)
				printf("Administrator!\n");
			else
				printf("Guest\n");
		}
		else
			fprintf(stderr, "NetUserGetinfo failed with error: %d\n", nStatus);
		if (pBuf != NULL)
			NetApiBufferFree(pBuf);
	}
	system("pause");
	return 0;
}