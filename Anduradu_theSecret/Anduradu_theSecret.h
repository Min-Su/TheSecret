
// Anduradu_theSecret.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CAnduradu_theSecretApp:
// �� Ŭ������ ������ ���ؼ��� Anduradu_theSecret.cpp�� �����Ͻʽÿ�.
//

class CAnduradu_theSecretApp : public CWinApp
{
public:
	CAnduradu_theSecretApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CAnduradu_theSecretApp theApp;