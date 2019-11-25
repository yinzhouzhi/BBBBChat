#pragma once
#include<afxsock.h>
#include"CMySocket.h"
class CMySocket :
	public CAsyncSocket
{
public:
	CMySocket();
	virtual ~CMySocket();
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};

