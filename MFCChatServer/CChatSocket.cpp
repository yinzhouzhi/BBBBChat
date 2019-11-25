#include "pch.h"
#include "CChatSocket.h"
#include"MFCChatServer.h"
#include"MFCChatServerDlg.h"
//接收端
CChatSocket::CChatSocket() {

}
CChatSocket::~CChatSocket() {

}
void CChatSocket::OnReceive(int nErrorCode) {
	//1接收数据到szRecvBuf
	TRACE("#####Server OnReceive");
	CMFCChatServerDlg* dlg = (CMFCChatServerDlg*)AfxGetApp()->GetMainWnd();
	char szRecvBuf[SEND_MAX_BUF] = { 0 };
	//调用该成员函数接收从套接字的数据。
	Receive(szRecvBuf, SEND_MAX_BUF, 0);
	TRACE("#####Server Receive=%s", szRecvBuf);

	//显示szRecvBuf
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);
	//3 显示到列表框
#if 0
	CString strShow = _T("接收到: ");
	CString strTime;
	dlg->m_tm = CTime::GetCurrentTime();
	strTime = dlg->m_tm.Format("%X ");

	//格式大概:2019-11-17 接收到: 内容
	strShow = strTime + strShow;
	strShow += strRecvMsg;
#endif
	CString strShow;
	CString strInfo = _T("客户端:");
	CString strMsg = _T("");
	strShow = dlg->CatShowString(strInfo, strRecvMsg);
	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnReceive(nErrorCode);
}