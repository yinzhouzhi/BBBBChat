#include "pch.h"
#include "CMySocket.h"
#include"MFCChatClientDlg.h"
#include"MFCChatClient.h"
#include"CMySocket.h"

CMySocket::CMySocket() {

}
CMySocket:: ~CMySocket() {

}

//�ص� ��д:Ҫ�������ǵ��Լ���Ƶ�������;:������
void CMySocket::OnConnect(int nErrorCode) {
	TRACE("####OnConnect");
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	#if 0
	CString str;
	dlg->m_tm=CTime::GetCurrentTime();//��ȡʵʱʱ��
	str = dlg->m_tm.Format("%X ");
	str += _T("����������ӳɹ�");
	dlg->m_list.AddString(str);
	
#endif
	CString strShow;
	CString strInfo = _T("");
	CString strMsg = _T("����������ӳɹ�...");
	strShow = dlg->CatShowString(strInfo, strMsg);
	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnConnect(nErrorCode);
 }

//�������ݵĻص�����
void CMySocket::OnReceive(int nErrorCode) {
	TRACE("####CMySocket OnReceive");
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	char szRecvBuf[SEND_MAX_BUF] = { 0 };
	//���øó�Ա�������մ��׽��ֵ�����
	Receive(szRecvBuf, SEND_MAX_BUF, 0);
	TRACE("#####Server Receive=%s", szRecvBuf);

	//��ʾszRecvBuf
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);
	//3 ��ʾ���б��
#if 0
	CString strShow = _T("�����: ");
	CString strTime;
	dlg->m_tm = CTime::GetCurrentTime();
	strTime = dlg->m_tm.Format("%X ");

	//��ʽ���:2019-11-17 ����˵�: ����
	strShow = strTime + strShow;
	strShow += strRecvMsg;
	dlg->m_list.AddString(strShow);
#endif
	CString strShow;
	CString strInfo = _T("�����:");
	CString strMsg = _T("");
	strShow = dlg->CatShowString(strInfo, strRecvMsg);
	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnReceive(nErrorCode);
}
