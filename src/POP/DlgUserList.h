#pragma once
#include "afxwin.h"

//#define WM_EB_SELECTED_EMP (WM_USER+0x10)
class CDlgViewContactInfo;

// CDlgUserList dialog
/*
 * 聊天成员列表显示窗口类
 * 用于群组聊天界面右边，显示群组成员（部门员工）名称，支持鼠标操作，进入一对一聊天界面；
 * 
*//////////////////////////////////////////////////////

class CDlgUserList : public CEbDialogBase
	//, public CTreeCallback
{
	DECLARE_DYNAMIC(CDlgUserList)

public:
	CDlgUserList(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgUserList();

	void SetCtrlColor(bool bInvalidate = true);

#ifdef USES_EBCOM_TEST
	void ChangeDepartmentInfo(IEB_GroupInfo* pGroupInfo);
	void OnUserEmpInfo(IEB_MemberInfo* pMemberInfo, bool bSort);
#else
	void ChangeDepartmentInfo(const EB_GroupInfo* pGroupInfo);
	int OnUserEmpInfo(const EB_MemberInfo* pMemberInfo, bool bSort);
#endif
	void LineStateChange(eb::bigint nUserId, EB_USER_LINE_STATE bLineState);
	void OnExitUser(eb::bigint nUserId,bool bExitDep);
	void OnEnterUser(eb::bigint nUserId, bool bSort);
	EB_CallInfo m_pCallInfo;
	void UpdateUserInfo(void);

// Dialog Data
	enum { IDD = IDD_DLG_USERLIST };

protected:
	CDlgViewContactInfo* m_pViewContactInfo;
	CLockMap<eb::bigint, CTreeItemInfo::pointer> m_pUserItem;		// uid->
#ifdef USES_EBCOM_TEST
	CComPtr<IEB_GroupInfo> m_pGroupInfo;
#else
	EB_GroupInfo m_pGroupInfo;
#endif

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CEdit m_editDescription;
	VividTree m_treeUsers;
	HTREEITEM m_hCurrentHotItem;
	CTraButton m_btnCallTrack;
	CTraButton m_btnEditEmpTrack;

	void RefreshEditDescription(void);
	void SelectItem(HTREEITEM hItem);
	void CallItem(HTREEITEM hItem);
	void EditEmployeeInfo(HTREEITEM hSelItem);
	LRESULT OnTreeItemDblclk(WPARAM wp, LPARAM lp);
	LRESULT OnTreeItemTrackHot(WPARAM wp, LPARAM lp);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//afx_msg void OnTvnSelchangedTreeUsers(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEnKillfocusEditDepDescription();
	afx_msg void OnEnSetfocusEditDepDescription();
	afx_msg void OnNMClickTreeUsers(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNMRClickTreeUsers(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDepartmentEdit();
	afx_msg void OnDepartmentDelEmp();
	afx_msg void OnDepartmentEditEmp();
	afx_msg void OnMemberDelAdminLevel();
	afx_msg void OnMemberAddAdminLevel();
	afx_msg void OnMemberAddForbidSpeech_10();
	afx_msg void OnMemberAddForbidSpeech_60();
	afx_msg void OnMemberAddForbidSpeech_720();
	afx_msg void OnMemberAddForbidSpeech_1440();
	afx_msg void OnMemberAddForbidSpeech_0();
	afx_msg void OnMemberDelForbidSpeech();
	afx_msg void OnMemberDelGroupForbidSpeech();
	afx_msg void OnMemberAddGroupForbidSpeech();
	afx_msg void OnCallUser();
	afx_msg void OnViewMsgRecord();
};
