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
	char szRecvBuf[SEND_MAX_BUF] = { 0 };
	//���øó�Ա�������մ��׽��ֵ����ݡ�
	Receive(szRecvBuf, SEND_MAX_BUF, 0);
	TRACE("#####Server Receive=%s", szRecvBuf);

	//��ʾszRecvBuf
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);
	//3 ��ʾ���б��
#if 0
	CString strShow = _T("���յ�: ");
	CString strTime;
	dlg->m_tm = CTime::GetCurrentTime();
	strTime = dlg->m_tm.Format("%X ");

	//��ʽ���:2019-11-17 ���յ�: ����
	strShow = strTime + strShow;
	strShow += strRecvMsg;
#endif
	CString strShow;
	CString strInfo = _T("�ͻ���:");
	CString strMsg = _T("");
	strShow = dlg->CatShowString(strInfo, strRecvMsg);
	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnReceive(nErrorCode);
}