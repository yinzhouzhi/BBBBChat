#include "pch.h"
#include "CMySocket.h"
#include"MFCChatClientDlg.h"
#include"MFCChatClient.h"
#include"CMySocket.h"

CMySocket::CMySocket() {

}
CMySocket:: ~CMySocket() {

}

//回调 重写:要满足我们得自己设计的特殊用途:传参数
void CMySocket::OnConnect(int nErrorCode) {
	TRACE("####OnConnect");
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	#if 0
	CString str;
	dlg->m_tm=CTime::GetCurrentTime();//获取实时时间
	str = dlg->m_tm.Format("%X ");
	str += _T("与服务器连接成功");
	dlg->m_list.AddString(str);
	
#endif
	CString strShow;
	CString strInfo = _T("");
	CString strMsg = _T("与服务器连接成功...");
	strShow = dlg->CatShowString(strInfo, strMsg);
	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnConnect(nErrorCode);
 }

//接收数据的回调函数
void CMySocket::OnReceive(int nErrorCode) {
	TRACE("####CMySocket OnReceive");
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	char szRecvBuf[SEND_MAX_BUF] = { 0 };
	//调用该成员函数接收从套接字的数据
	Receive(szRecvBuf, SEND_MAX_BUF, 0);
	TRACE("#####Server Receive=%s", szRecvBuf);

	//显示szRecvBuf
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);
	//3 显示到列表框
#if 0
	CString strShow = _T("服务端: ");
	CString strTime;
	dlg->m_tm = CTime::GetCurrentTime();
	strTime = dlg->m_tm.Format("%X ");

	//格式大概:2019-11-17 服务端到: 内容
	strShow = strTime + strShow;
	strShow += strRecvMsg;
	dlg->m_list.AddString(strShow);
#endif
	CString strShow;
	CString strInfo = _T("服务端:");
	CString strMsg = _T("");
	strShow = dlg->CatShowString(strInfo, strRecvMsg);
	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnReceive(nErrorCode);
}
