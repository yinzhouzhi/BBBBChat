#include "pch.h"
#include "CChatSocket.h"
#include"MFCChatServer.h"
#include"MFCChatServerDlg.h"
//���ն�
CChatSocket::CChatSocket() {

}
CChatSocket::~CChatSocket() {

}
void CChatSocket::OnReceive(int nErrorCode) {
	//1�������ݵ�szRecvBuf
	TRACE("#####Server OnReceive");
	CMFCChatServerDlg* dlg = (CMFCChatServerDlg*)AfxGetApp()->GetMainWnd();
	char szRecvBuf[200] = { 0 };
	Receive(szRecvBuf, 200, 0);
	TRACE("#####Server Receive=%s", szRecvBuf);

	//��ʾszRecvBuf
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);
	//3 ��ʾ���б��
	CString strShow = _T("���յ�: ");
	CString strTime;
	dlg->m_tm = CTime::GetCurrentTime();
	strTime = dlg->m_tm.Format("%X ");

	//��ʽ���:2019-11-17 ���յ�: ����
	strShow = strTime + strShow;
	strShow += strRecvMsg;
	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnReceive(nErrorCode);
}