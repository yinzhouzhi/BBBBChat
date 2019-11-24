#include "pch.h"
#include "CMySocket.h"
#include"MFCChatClientDlg.h"
#include"MFCChatClient.h"
CMySocket::CMySocket() {

}
CMySocket:: ~CMySocket() {

}

//回调 重写:要满足我们得自己设计的特殊用途:传参数
void CMySocket::OnConnect(int nErrorCode) {
	TRACE("####OnConnect");
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	CString str;
	dlg->m_tm=CTime::GetCurrentTime();//获取实时时间
	str = dlg->m_tm.Format("%X ");
	str += _T("与服务器连接成功");
	dlg->m_list.AddString(str);
	CAsyncSocket::OnConnect(nErrorCode);
 }
void CMySocket::OnReceive(int nErrorCode) {
	TRACE("####OnReceive");
}
