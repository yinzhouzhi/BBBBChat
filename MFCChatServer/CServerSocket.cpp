#include "pch.h"
#include "CServerSocket.h"
#include"MFCChatServer.h"
#include"MFCChatServerDlg.h"

CServerSocket::CServerSocket() {

}
CServerSocket::~CServerSocket() {

}
 void CServerSocket::OnAccept(int nErrorCode) {
	 TRACE("####OnAccept");
	 CMFCChatServerDlg *dlg=(CMFCChatServerDlg*)AfxGetApp()->GetMainWnd();
	
	dlg->m_chat = new CChatSocket;

	 Accept(*(dlg->m_chat));
#if 0
	 CString str;
	 dlg->m_tm = CTime::GetCurrentTime();//��ȡʵʱʱ��
	 str = dlg->m_tm.Format("%X ");
	 str += _T("��ͻ������ӳɹ�");
	 dlg->m_list.AddString(str);
#endif
	 CString strShow;
	 CString strInfo = _T("");
	 CString strMsg = _T("��ͻ������ӳɹ�...");
	 strShow = dlg->CatShowString(strInfo, strMsg);
	 dlg->m_list.AddString(strShow);
	 dlg->m_list.UpdateData(FALSE);

	 CAsyncSocket::OnAccept(nErrorCode);
}