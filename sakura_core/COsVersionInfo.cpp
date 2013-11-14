/*!	@file
	@brief COsVersionInfo
*/
/*
	Copyright (C) 2013, novice

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose, 
	including commercial applications, and to alter it and redistribute it 
	freely, subject to the following restrictions:

		1. The origin of this software must not be misrepresented;
		   you must not claim that you wrote the original software.
		   If you use this software in a product, an acknowledgment
		   in the product documentation would be appreciated but is
		   not required.

		2. Altered source versions must be plainly marked as such, 
		   and must not be misrepresented as being the original software.

		3. This notice may not be removed or altered from any source
		   distribution.
*/

#include "StdAfx.h"
#include "COsVersionInfo.h"
#include "RegKey.h"

// COsVersionInfo�̓���static�ϐ��̒�`
//	��������IsValidVersion()�ōs��
BOOL	 		COsVersionInfo::m_bSuccess;
OSVERSIONINFO	COsVersionInfo::m_cOsVersionInfo;
bool			COsVersionInfo::m_bWine;

/*!
	���������s��(�����̓_�~�[)
	�ďo�͊�{1��̂�
*/
COsVersionInfo::COsVersionInfo( bool pbStart )
{
	memset( &m_cOsVersionInfo, 0, sizeof( m_cOsVersionInfo ) );
	m_cOsVersionInfo.dwOSVersionInfoSize = sizeof( m_cOsVersionInfo );
	m_bSuccess = ::GetVersionEx( &m_cOsVersionInfo );

	CRegKey reg;
	if( ERROR_SUCCESS == reg.Open(HKEY_CURRENT_USER, _T("Software\\Wine\\Debug"), KEY_READ)  ){
		m_bWine = true;
	}else{
		m_bWine = false;
	}
}
