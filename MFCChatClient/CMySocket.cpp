#include "pch.h"
#include "CMySocket.h"
#include"MFCChatClientDlg.h"
#include"MFCChatClient.h"
CMySocket::CMySocket() {

}
CMySocket:: ~CMySocket() {

}

//�ص� ��д:Ҫ�������ǵ��Լ���Ƶ�������;:������
void CMySocket::OnConnect(int nErrorCode) {
	TRACE("####OnConnect");
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	CString str;
	dlg->m_tm=CTime::GetCurrentTime();//��ȡʵʱʱ��
	str = dlg->m_tm.Format("%X ");
	str += _T("����������ӳɹ�");
	dlg->m_list.AddString(str);
	CAsyncSocket::OnConnect(nErrorCode);
 }
void CMySocket::OnReceive(int nErrorCode) {
	TRACE("####OnReceive");
}
