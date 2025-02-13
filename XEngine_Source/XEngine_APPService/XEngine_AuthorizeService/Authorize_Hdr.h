﻿#pragma once
#ifdef _WINDOWS
#include <Windows.h>
#include <tchar.h>
#else
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <signal.h>
#include <errno.h>
#include <thread>
#include <list>
#include <string>
using namespace std;
#include <XEngine_Include/XEngine_CommHdr.h>
#include <XEngine_Include/XEngine_Types.h>
#include <XEngine_Include/XEngine_ProtocolHdr.h>
#include <XEngine_Include/XEngine_BaseLib/BaseLib_Define.h>
#include <XEngine_Include/XEngine_BaseLib/BaseLib_Error.h>
#include <XEngine_Include/XEngine_Core/NetCore_Define.h>
#include <XEngine_Include/XEngine_Core/NetCore_Error.h>
#include <XEngine_Include/XEngine_Core/ManagePool_Define.h>
#include <XEngine_Include/XEngine_Core/ManagePool_Error.h>
#include <XEngine_Include/XEngine_Core/OPenSsl_Define.h>
#include <XEngine_Include/XEngine_Core/OPenSsl_Error.h>
#include <XEngine_Include/XEngine_Client/APIClient_Define.h>
#include <XEngine_Include/XEngine_Client/APIClient_Error.h>
#include <XEngine_Include/XEngine_HelpComponents/XLog_Define.h>
#include <XEngine_Include/XEngine_HelpComponents/XLog_Error.h>
#include <XEngine_Include/XEngine_HelpComponents/Packets_Define.h>
#include <XEngine_Include/XEngine_HelpComponents/Packets_Error.h>
#include <XEngine_Include/XEngine_HelpComponents/Authorize_Define.h>
#include <XEngine_Include/XEngine_HelpComponents/Authorize_Error.h>
#include <XEngine_Include/XEngine_RfcComponents/WSProtocol_Define.h>
#include <XEngine_Include/XEngine_RfcComponents/WSProtocol_Error.h>
#include <XEngine_Include/XEngine_RfcComponents/HttpProtocol_Define.h>
#include <XEngine_Include/XEngine_RfcComponents/HttpProtocol_Error.h>
#include "../../XAuth_Protocol.h"
#include "../../AuthorizeModule_Configure/Config_Define.h"
#include "../../AuthorizeModule_Configure/Config_Error.h"
#include "../../AuthorizeModule_Database/Database_Define.h"
#include "../../AuthorizeModule_Database/Database_Error.h"
#include "../../AuthorizeModule_Session/Session_Define.h"
#include "../../AuthorizeModule_Session/Session_Error.h"
#include "../../AuthorizeModule_Protocol/Protocol_Define.h"
#include "../../AuthorizeModule_Protocol/Protocol_Error.h"
#include "../../AuthorizeModule_Help/AuthHelp_Define.h"
#include "../../AuthorizeModule_Help/AuthHelp_Error.h"
#include "../../XEngine_Depend/XEngine_Module/XEngine_InfoReport/InfoReport_Define.h"
#include "../../XEngine_Depend/XEngine_Module/XEngine_InfoReport/InfoReport_Error.h"

extern bool bIsRun;
extern XHANDLE xhLog;
extern XHANDLE xhTCPSocket;
extern XHANDLE xhWSSocket;
extern XHANDLE xhHttpSocket;
extern XHANDLE xhTCPPacket;
extern XHANDLE xhWSPacket;
extern XHANDLE xhHttpPacket;
extern XHANDLE xhMemPool;
extern XHANDLE xhTCPPool;
extern XHANDLE xhWSPool;
extern XHANDLE xhHttpPool;
extern XENGINE_SERVICECONFIG st_AuthConfig;
extern XENGINE_FUNCTIONSWITCH st_FunSwitch;

#define XENGINE_AUTH_APP_NETTYPE_TCP 0
#define XENGINE_AUTH_APP_NETTYPE_WS 1
#define XENGINE_AUTH_APP_NETTYPE_HTTP 2
#define XENGINE_AUTH_MAX_BUFFER (1024 * 1024 * 10)

#include "Authorize_Config.h"
#include "Authorize_Net.h"
#include "Authorize_Task.h"
#include "Authorize_TCPTask.h"
#include "Authorize_WSTask.h"
#include "Authorize_HttpTask.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_User.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_Client.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_Serial.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_Pass.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_Switch.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_Banned.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_CDKey.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_Announcement.h"
#include "AuthorizeHTTP_Post/AuthorizeHTTP_Try.h"
#include "AuthorizeHTTP_Get/AuthorizeHTTP_Token.h"
#include "AuthorizeHTTP_Get/AuthorizeHTTP_DynamicCode.h"

#ifdef _MSC_BUILD
#ifdef _DEBUG
#ifdef _WIN64
#pragma comment(lib,"../../x64/Debug/AuthorizeModule_Configure.lib")
#pragma comment(lib,"../../x64/Debug/AuthorizeModule_Protocol.lib")
#pragma comment(lib,"../../x64/Debug/AuthorizeModule_Session.lib")
#pragma comment(lib,"../../x64/Debug/AuthorizeModule_Database.lib")
#pragma comment(lib,"../../x64/Debug/AuthorizeModule_Help.lib")
#pragma comment(lib,"../../x64/Debug/XEngine_InfoReport.lib")
#else
#pragma comment(lib,"../../Debug/AuthorizeModule_Configure.lib")
#pragma comment(lib,"../../Debug/AuthorizeModule_Protocol.lib")
#pragma comment(lib,"../../Debug/AuthorizeModule_Session.lib")
#pragma comment(lib,"../../Debug/AuthorizeModule_Database.lib")
#pragma comment(lib,"../../Debug/AuthorizeModule_Help.lib")
#pragma comment(lib,"../../Debug/XEngine_InfoReport.lib")
#endif
#else
#ifdef _WIN64
#pragma comment(lib,"../../x64/Release/AuthorizeModule_Configure.lib")
#pragma comment(lib,"../../x64/Release/AuthorizeModule_Protocol.lib")
#pragma comment(lib,"../../x64/Release/AuthorizeModule_Session.lib")
#pragma comment(lib,"../../x64/Release/AuthorizeModule_Database.lib")
#pragma comment(lib,"../../x64/Release/AuthorizeModule_Help.lib")
#pragma comment(lib,"../../x64/Release/XEngine_InfoReport.lib")
#else
#pragma comment(lib,"../../Release/AuthorizeModule_Configure.lib")
#pragma comment(lib,"../../Release/AuthorizeModule_Protocol.lib")
#pragma comment(lib,"../../Release/AuthorizeModule_Session.lib")
#pragma comment(lib,"../../Release/AuthorizeModule_Database.lib")
#pragma comment(lib,"../../Release/AuthorizeModule_Help.lib")
#pragma comment(lib,"../../Release/XEngine_InfoReport.lib")
#endif
#endif
#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"XEngine_BaseLib/XEngine_BaseLib.lib")
#pragma comment(lib,"XEngine_Core/XEngine_Core.lib")
#pragma comment(lib,"XEngine_Core/XEngine_ManagePool.lib")
#pragma comment(lib,"XEngine_Core/XEngine_OPenSsl.lib")
#pragma comment(lib,"XEngine_Client/XClient_APIHelp.lib")
#pragma comment(lib,"XEngine_HelpComponents/HelpComponents_XLog.lib")
#pragma comment(lib,"XEngine_HelpComponents/HelpComponents_Packets.lib")
#pragma comment(lib,"XEngine_HelpComponents/HelpComponents_Authorize.lib")
#pragma comment(lib,"XEngine_RfcComponents/RfcComponents_WSProtocol.lib")
#pragma comment(lib,"XEngine_RfcComponents/RfcComponents_HttpProtocol.lib")
#endif