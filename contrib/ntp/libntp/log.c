begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Microsoft Developer Support Copyright (c) 1993 Microsoft Corporation. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|"messages.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_define
define|#
directive|define
name|PERR
parameter_list|(
name|bSuccess
parameter_list|,
name|api
parameter_list|)
value|{if(!(bSuccess)) printf("%s: Error %d from %s \     on line %d\n", __FILE__, GetLastError(), api, __LINE__);}
end_define

begin_comment
comment|/********************************************************************* * FUNCTION: addSourceToRegistry(void)                                * *                                                                    * * PURPOSE: Add a source name key, message DLL name value, and        * *          message type supported value to the registry              * *                                                                    * * INPUT: source name, path of message DLL                            * *                                                                    * * RETURNS: none                                                      * *********************************************************************/
end_comment

begin_function
name|void
name|addSourceToRegistry
parameter_list|(
name|LPSTR
name|pszAppname
parameter_list|,
name|LPSTR
name|pszMsgDLL
parameter_list|)
block|{
name|HKEY
name|hk
decl_stmt|;
comment|/* registry key handle */
name|DWORD
name|dwData
decl_stmt|;
name|BOOL
name|bSuccess
decl_stmt|;
comment|/* When an application uses the RegisterEventSource or OpenEventLog      function to get a handle of an event log, the event loggging service      searches for the specified source name in the registry. You can add a      new source name to the registry by opening a new registry subkey      under the Application key and adding registry values to the new      subkey. */
comment|/* Create a new key for our application */
name|bSuccess
operator|=
name|RegCreateKey
argument_list|(
name|HKEY_LOCAL_MACHINE
argument_list|,
literal|"SYSTEM\\CurrentControlSet\\Services\\EventLog\\Application\\NTP"
argument_list|,
operator|&
name|hk
argument_list|)
expr_stmt|;
name|PERR
argument_list|(
name|bSuccess
operator|==
name|ERROR_SUCCESS
argument_list|,
literal|"RegCreateKey"
argument_list|)
expr_stmt|;
comment|/* Add the Event-ID message-file name to the subkey. */
name|bSuccess
operator|=
name|RegSetValueEx
argument_list|(
name|hk
argument_list|,
comment|/* subkey handle         */
literal|"EventMessageFile"
argument_list|,
comment|/* value name            */
literal|0
argument_list|,
comment|/* must be zero          */
name|REG_EXPAND_SZ
argument_list|,
comment|/* value type            */
operator|(
name|LPBYTE
operator|)
name|pszMsgDLL
argument_list|,
comment|/* address of value data */
name|strlen
argument_list|(
name|pszMsgDLL
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* length of value data  */
name|PERR
argument_list|(
name|bSuccess
operator|==
name|ERROR_SUCCESS
argument_list|,
literal|"RegSetValueEx"
argument_list|)
expr_stmt|;
comment|/* Set the supported types flags and addit to the subkey. */
name|dwData
operator|=
name|EVENTLOG_ERROR_TYPE
operator||
name|EVENTLOG_WARNING_TYPE
operator||
name|EVENTLOG_INFORMATION_TYPE
expr_stmt|;
name|bSuccess
operator|=
name|RegSetValueEx
argument_list|(
name|hk
argument_list|,
comment|/* subkey handle                */
literal|"TypesSupported"
argument_list|,
comment|/* value name                   */
literal|0
argument_list|,
comment|/* must be zero                 */
name|REG_DWORD
argument_list|,
comment|/* value type                   */
operator|(
name|LPBYTE
operator|)
operator|&
name|dwData
argument_list|,
comment|/* address of value data        */
sizeof|sizeof
argument_list|(
name|DWORD
argument_list|)
argument_list|)
expr_stmt|;
comment|/* length of value data         */
name|PERR
argument_list|(
name|bSuccess
operator|==
name|ERROR_SUCCESS
argument_list|,
literal|"RegSetValueEx"
argument_list|)
expr_stmt|;
name|RegCloseKey
argument_list|(
name|hk
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/********************************************************************* * FUNCTION: reportAnEvent(DWORD dwIdEvent, WORD cStrings,            * *                         LPTSTR *ppszStrings);                      * *                                                                    * * PURPOSE: add the event to the event log                            * *                                                                    * * INPUT: the event ID to report in the log, the number of insert     * *        strings, and an array of null-terminated insert strings     * *                                                                    * * RETURNS: none                                                      * *********************************************************************/
end_comment

begin_function
name|void
name|reportAnIEvent
parameter_list|(
name|DWORD
name|dwIdEvent
parameter_list|,
name|WORD
name|cStrings
parameter_list|,
name|LPTSTR
modifier|*
name|pszStrings
parameter_list|)
block|{
name|HANDLE
name|hAppLog
decl_stmt|;
name|BOOL
name|bSuccess
decl_stmt|;
comment|/* Get a handle to the Application event log */
name|hAppLog
operator|=
name|RegisterEventSource
argument_list|(
name|NULL
argument_list|,
comment|/* use local machine      */
literal|"NTP"
argument_list|)
expr_stmt|;
comment|/* source name                 */
name|PERR
argument_list|(
name|hAppLog
argument_list|,
literal|"RegisterEventSource"
argument_list|)
expr_stmt|;
comment|/* Now report the event, which will add this event to the event log */
name|bSuccess
operator|=
name|ReportEvent
argument_list|(
name|hAppLog
argument_list|,
comment|/* event-log handle            */
name|EVENTLOG_INFORMATION_TYPE
argument_list|,
comment|/* event type                  */
literal|0
argument_list|,
comment|/* category zero               */
name|dwIdEvent
argument_list|,
comment|/* event ID                    */
name|NULL
argument_list|,
comment|/* no user SID                 */
name|cStrings
argument_list|,
comment|/* number of substitution strings     */
literal|0
argument_list|,
comment|/* no binary data              */
name|pszStrings
argument_list|,
comment|/* string array                */
name|NULL
argument_list|)
expr_stmt|;
comment|/* address of data             */
name|PERR
argument_list|(
name|bSuccess
argument_list|,
literal|"ReportEvent"
argument_list|)
expr_stmt|;
name|DeregisterEventSource
argument_list|(
name|hAppLog
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|void
name|reportAnWEvent
parameter_list|(
name|DWORD
name|dwIdEvent
parameter_list|,
name|WORD
name|cStrings
parameter_list|,
name|LPTSTR
modifier|*
name|pszStrings
parameter_list|)
block|{
name|HANDLE
name|hAppLog
decl_stmt|;
name|BOOL
name|bSuccess
decl_stmt|;
comment|/* Get a handle to the Application event log */
name|hAppLog
operator|=
name|RegisterEventSource
argument_list|(
name|NULL
argument_list|,
comment|/* use local machine      */
literal|"NTP"
argument_list|)
expr_stmt|;
comment|/* source name                 */
name|PERR
argument_list|(
name|hAppLog
argument_list|,
literal|"RegisterEventSource"
argument_list|)
expr_stmt|;
comment|/* Now report the event, which will add this event to the event log */
name|bSuccess
operator|=
name|ReportEvent
argument_list|(
name|hAppLog
argument_list|,
comment|/* event-log handle            */
name|EVENTLOG_WARNING_TYPE
argument_list|,
comment|/* event type                  */
literal|0
argument_list|,
comment|/* category zero               */
name|dwIdEvent
argument_list|,
comment|/* event ID                    */
name|NULL
argument_list|,
comment|/* no user SID                 */
name|cStrings
argument_list|,
comment|/* number of substitution strings     */
literal|0
argument_list|,
comment|/* no binary data              */
name|pszStrings
argument_list|,
comment|/* string array                */
name|NULL
argument_list|)
expr_stmt|;
comment|/* address of data             */
name|PERR
argument_list|(
name|bSuccess
argument_list|,
literal|"ReportEvent"
argument_list|)
expr_stmt|;
name|DeregisterEventSource
argument_list|(
name|hAppLog
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|void
name|reportAnEEvent
parameter_list|(
name|DWORD
name|dwIdEvent
parameter_list|,
name|WORD
name|cStrings
parameter_list|,
name|LPTSTR
modifier|*
name|pszStrings
parameter_list|)
block|{
name|HANDLE
name|hAppLog
decl_stmt|;
name|BOOL
name|bSuccess
decl_stmt|;
comment|/* Get a handle to the Application event log */
name|hAppLog
operator|=
name|RegisterEventSource
argument_list|(
name|NULL
argument_list|,
comment|/* use local machine      */
literal|"NTP"
argument_list|)
expr_stmt|;
comment|/* source name                 */
name|PERR
argument_list|(
name|hAppLog
argument_list|,
literal|"RegisterEventSource"
argument_list|)
expr_stmt|;
comment|/* Now report the event, which will add this event to the event log */
name|bSuccess
operator|=
name|ReportEvent
argument_list|(
name|hAppLog
argument_list|,
comment|/* event-log handle            */
name|EVENTLOG_ERROR_TYPE
argument_list|,
comment|/* event type                  */
literal|0
argument_list|,
comment|/* category zero               */
name|dwIdEvent
argument_list|,
comment|/* event ID                    */
name|NULL
argument_list|,
comment|/* no user SID                 */
name|cStrings
argument_list|,
comment|/* number of substitution strings     */
literal|0
argument_list|,
comment|/* no binary data              */
name|pszStrings
argument_list|,
comment|/* string array                */
name|NULL
argument_list|)
expr_stmt|;
comment|/* address of data             */
name|PERR
argument_list|(
name|bSuccess
argument_list|,
literal|"ReportEvent"
argument_list|)
expr_stmt|;
name|DeregisterEventSource
argument_list|(
name|hAppLog
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

