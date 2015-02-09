begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnResources.h ----------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//++
end_comment

begin_comment
comment|// File:        MICmnResources.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmnResources interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment: Compilers:  Visual C++ 12.
end_comment

begin_comment
comment|//                          gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//              Libraries:  See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:   None.
end_comment

begin_comment
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// Third party headers
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIUtilSingletonBase.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI string test data resource definitions. These IDs match up with
end_comment

begin_comment
comment|//          actual string data in a map internal to CMICmnResources.
end_comment

begin_comment
comment|//          *** Be sure to update ms_pResourceId2TextData[] array ****
end_comment

begin_enum
enum|enum
block|{
name|IDS_PROJNAME
init|=
literal|1
block|,
name|IDS_MI_VERSION_DESCRIPTION_DEBUG
block|,
name|IDS_MI_VERSION_DESCRIPTION
block|,
name|IDS_MI_APPNAME_SHORT
block|,
name|IDS_MI_APPNAME_LONG
block|,
name|IDS_MI_APP_FILEPATHNAME
block|,
name|IDS_MI_APP_ARGS
block|,
name|IDE_MI_VERSION_GDB
block|,
name|IDS_UTIL_FILE_ERR_INVALID_PATHNAME
block|,
name|IDS_UTIL_FILE_ERR_OPENING_FILE
block|,
name|IDS_UTIL_FILE_ERR_OPENING_FILE_UNKNOWN
block|,
name|IDE_UTIL_FILE_ERR_WRITING_FILE
block|,
name|IDE_UTIL_FILE_ERR_WRITING_NOTOPEN
block|,
name|IDS_RESOURCES_ERR_STRING_NOT_FOUND
block|,
name|IDS_RESOURCES_ERR_STRING_TABLE_INVALID
block|,
name|IDS_MI_CLIENT_MSG
block|,
name|IDS_LOG_MSG_CREATION_DATE
block|,
name|IDS_LOG_MSG_FILE_LOGGER_PATH
block|,
name|IDS_LOG_MSG_VERSION
block|,
name|IDS_LOG_ERR_FILE_LOGGER_DISABLED
block|,
name|IDS_LOG_MEDIUM_ERR_INIT
block|,
name|IDS_LOG_MEDIUM_ERR_WRITE_ANY
block|,
name|IDS_LOG_MEDIUM_ERR_WRITE_MEDIUMFAIL
block|,
name|IDE_MEDIUMFILE_ERR_GET_FILE_PATHNAME_SYS
block|,
name|IDS_MEDIUMFILE_NAME
block|,
name|IDS_MEDIUMFILE_ERR_INVALID_PATH
block|,
name|IDS_MEDIUMFILE_ERR_FILE_HEADER
block|,
name|IDS_MEDIUMFILE_NAME_LOG
block|,
name|IDE_OS_ERR_UNKNOWN
block|,
name|IDE_OS_ERR_RETRIEVING
block|,
name|IDS_DRIVERMGR_DRIVER_ERR_INIT
block|,
name|IDE_MEDIUMSTDERR_NAME
block|,
name|IDE_MEDIUMSTDOUT_NAME
block|,
name|IDE_MI_APP_EXIT_OK
block|,
name|IDE_MI_APP_EXIT_WITH_PROBLEM
block|,
name|IDE_MI_APP_EXIT_WITH_PROBLEM_NO_LOG
block|,
name|IDE_MI_APP_DESCRIPTION
block|,
name|IDE_MI_APP_INFORMATION
block|,
name|IDE_MI_APP_ARG_USAGE
block|,
name|IDE_MI_APP_ARG_HELP
block|,
name|IDE_MI_APP_ARG_VERSION
block|,
name|IDE_MI_APP_ARG_VERSION_LONG
block|,
name|IDE_MI_APP_ARG_INTERPRETER
block|,
name|IDE_MI_APP_ARG_EXECUTEABLE
block|,
name|IDE_MI_APP_ARG_APP_LOG
block|,
name|IDE_MI_APP_ARG_EXAMPLE
block|,
name|IDE_MI_APP_ARG_EXECUTABLE
block|,
name|IDS_STDIN_ERR_INVALID_PROMPT
block|,
name|IDS_STDIN_ERR_THREAD_CREATION_FAILED
block|,
name|IDS_STDIN_ERR_THREAD_DELETE
block|,
name|IDS_STDIN_ERR_CHKING_BYTE_AVAILABLE
block|,
name|IDS_STDIN_INPUT_CTRL_CHARS
block|,
name|IDS_CMD_QUIT_HELP
block|,
name|IDS_THREADMGR_ERR_THREAD_ID_INVALID
block|,
name|IDS_THREADMGR_ERR_THREAD_FAIL_CREATE
block|,
name|IDS_THREADMGR_ERR_THREAD_ID_NOT_FOUND
block|,
name|IDS_THREADMGR_ERR_THREAD_STILL_ALIVE
block|,
name|IDS_FALLTHRU_DRIVER_CMD_RECEIVED
block|,
name|IDS_CMDFACTORY_ERR_INVALID_CMD_NAME
block|,
name|IDS_CMDFACTORY_ERR_INVALID_CMD_CR8FN
block|,
name|IDS_CMDFACTORY_ERR_CMD_NOT_REGISTERED
block|,
name|IDS_CMDFACTORY_ERR_CMD_ALREADY_REGED
block|,
name|IDS_CMDMGR_ERR_CMD_FAILED_CREATE
block|,
name|IDS_CMDMGR_ERR_CMD_INVOKER
block|,
name|IDS_PROCESS_SIGNAL_RECEIVED
block|,
name|IDS_MI_INIT_ERR_LOG
block|,
name|IDS_MI_INIT_ERR_RESOURCES
block|,
name|IDS_MI_INIT_ERR_INIT
block|,
name|IDS_MI_INIT_ERR_STREAMSTDIN
block|,
name|IDS_MI_INIT_ERR_STREAMSTDIN_OSHANDLER
block|,
name|IDS_MI_INIT_ERR_OS_STDIN_HANDLER
block|,
name|IDS_MI_INIT_ERR_STREAMSTDOUT
block|,
name|IDS_MI_INIT_ERR_STREAMSTDERR
block|,
name|IDS_MI_INIT_ERR_FALLTHRUDRIVER
block|,
name|IDS_MI_INIT_ERR_THREADMGR
block|,
name|IDS_MI_INIT_ERR_CMDINTERPRETER
block|,
name|IDS_MI_INIT_ERR_CMDMGR
block|,
name|IDS_MI_INIT_ERR_CMDFACTORY
block|,
name|IDS_MI_INIT_ERR_CMDINVOKER
block|,
name|IDS_MI_INIT_ERR_CMDMONITOR
block|,
name|IDS_MI_INIT_ERR_LLDBDEBUGGER
block|,
name|IDS_MI_INIT_ERR_DRIVERMGR
block|,
name|IDS_MI_INIT_ERR_DRIVER
block|,
name|IDS_MI_INIT_ERR_OUTOFBANDHANDLER
block|,
name|IDS_MI_INIT_ERR_DEBUGSESSIONINFO
block|,
name|IDS_MI_INIT_ERR_THREADMANAGER
block|,
name|IDS_MI_INIT_ERR_CLIENT_USING_DRIVER
block|,
name|IDS_MI_INIT_ERR_LOCAL_DEBUG_SESSION
block|,
name|IDS_CODE_ERR_INVALID_PARAMETER_VALUE
block|,
name|IDS_CODE_ERR_INVALID_PARAM_NULL_POINTER
block|,
name|IDS_CODE_ERR_INVALID_ENUMERATION_VALUE
block|,
name|IDS_LLDBDEBUGGER_ERR_INVALIDLISTENER
block|,
name|IDS_LLDBDEBUGGER_ERR_INVALIDDEBUGGER
block|,
name|IDS_LLDBDEBUGGER_ERR_CLIENTDRIVER
block|,
name|IDS_LLDBDEBUGGER_ERR_STARTLISTENER
block|,
name|IDS_LLDBDEBUGGER_ERR_THREADCREATIONFAIL
block|,
name|IDS_LLDBDEBUGGER_ERR_THREAD_DELETE
block|,
name|IDS_LLDBDEBUGGER_ERR_INVALIDBROADCASTER
block|,
name|IDS_LLDBDEBUGGER_ERR_INVALIDCLIENTNAME
block|,
name|IDS_LLDBDEBUGGER_ERR_CLIENTNOTREGISTERD
block|,
name|IDS_LLDBDEBUGGER_ERR_STOPLISTENER
block|,
name|IDS_LLDBDEBUGGER_ERR_BROARDCASTER_NAME
block|,
name|IDS_LLDBDEBUGGER_WRN_UNKNOWN_EVENT
block|,
name|IDS_LLDBOUTOFBAND_ERR_UNKNOWN_EVENT
block|,
name|IDS_LLDBOUTOFBAND_ERR_PROCESS_INVALID
block|,
name|IDS_LLDBOUTOFBAND_ERR_BRKPT_NOTFOUND
block|,
name|IDS_LLDBOUTOFBAND_ERR_BRKPT_INFO_GET
block|,
name|IDS_LLDBOUTOFBAND_ERR_BRKPT_INFO_SET
block|,
name|IDS_LLDBOUTOFBAND_ERR_FORM_MI_RESPONSE
block|,
name|IDS_LLDBOUTOFBAND_ERR_FRAME_INFO_GET
block|,
name|IDS_LLDBOUTOFBAND_ERR_SETNEWDRIVERSTATE
block|,
name|IDS_LLDBOUTOFBAND_ERR_BRKPT_CNT_EXCEEDED
block|,
name|IDS_DBGSESSION_ERR_SHARED_DATA_RELEASE
block|,
name|IDS_DBGSESSION_ERR_SHARED_DATA_ADD
block|,
name|IDS_MI_SHTDWN_ERR_LOG
block|,
name|IDS_MI_SHUTDOWN_ERR
block|,
name|IDE_MI_SHTDWN_ERR_RESOURCES
block|,
name|IDE_MI_SHTDWN_ERR_STREAMSTDIN
block|,
name|IDS_MI_SHTDWN_ERR_OS_STDIN_HANDLER
block|,
name|IDS_MI_SHTDWN_ERR_STREAMSTDOUT
block|,
name|IDS_MI_SHTDWN_ERR_STREAMSTDERR
block|,
name|IDS_MI_SHTDWN_ERR_THREADMGR
block|,
name|IDS_MI_SHTDWN_ERR_CMDINTERPRETER
block|,
name|IDS_MI_SHTDWN_ERR_CMDMGR
block|,
name|IDS_MI_SHTDWN_ERR_CMDFACTORY
block|,
name|IDS_MI_SHTDWN_ERR_CMDINVOKER
block|,
name|IDS_MI_SHTDWN_ERR_CMDMONITOR
block|,
name|IDS_MI_SHTDWN_ERR_LLDBDEBUGGER
block|,
name|IDS_MI_SHTDWN_ERR_DRIVERMGR
block|,
name|IDS_MI_SHTDWN_ERR_DRIVER
block|,
name|IDS_MI_SHTDWN_ERR_OUTOFBANDHANDLER
block|,
name|IDS_MI_SHTDWN_ERR_DEBUGSESSIONINFO
block|,
name|IDE_MI_SHTDWN_ERR_THREADMANAGER
block|,
name|IDS_DRIVER_ERR_PARSE_ARGS
block|,
name|IDS_DRIVER_ERR_PARSE_ARGS_UNKNOWN
block|,
name|IDS_DRIVER_ERR_CURRENT_NOT_SET
block|,
name|IDS_DRIVER_ERR_NON_REGISTERED
block|,
name|IDS_DRIVER_SAY_DRIVER_USING
block|,
name|IDS_DRIVER_ERR_ID_INVALID
block|,
name|IDS_DRIVER_ERR_FALLTHRU_DRIVER_ERR
block|,
name|IDS_DRIVER_CMD_RECEIVED
block|,
name|IDS_DRIVER_CMD_NOT_IN_FACTORY
block|,
name|IDS_DRIVER_ERR_DRIVER_STATE_ERROR
block|,
name|IDS_DRIVER_ERR_MAINLOOP
block|,
name|IDS_DRIVER_ERR_LOCAL_DEBUG_NOT_IMPL
block|,
name|IDS_DRIVER_ERR_LOCAL_DEBUG_INIT
block|,
name|IDS_DRIVER_WAITING_STDIN_DATA
block|,
name|IDS_STDOUT_ERR_NOT_ALL_DATA_WRITTEN
block|,
name|IDS_STDERR_ERR_NOT_ALL_DATA_WRITTEN
block|,
name|IDS_CMD_ARGS_ERR_N_OPTIONS_REQUIRED
block|,
name|IDS_CMD_ARGS_ERR_OPTION_NOT_FOUND
block|,
name|IDS_CMD_ARGS_ERR_VALIDATION_MANDATORY
block|,
name|IDS_CMD_ARGS_ERR_VALIDATION_INVALID
block|,
name|IDS_CMD_ARGS_ERR_VALIDATION_MAN_INVALID
block|,
name|IDS_CMD_ARGS_ERR_VALIDATION_MISSING_INF
block|,
name|IDS_CMD_ARGS_ERR_CONTEXT_NOT_ALL_EATTEN
block|,
name|IDS_CMD_ARGS_ERR_PREFIX_MSG
block|,
name|IDS_VARIANT_ERR_USED_BASECLASS
block|,
name|IDS_VARIANT_ERR_MAP_KEY_INVALID
block|,
name|IDS_WORD_INVALIDBRKTS
block|,
name|IDS_WORD_NONE
block|,
name|IDS_WORD_NOT
block|,
name|IDS_WORD_INVALIDEMPTY
block|,
name|IDS_WORD_INVALIDNULLPTR
block|,
name|IDS_WORD_UNKNOWNBRKTS
block|,
name|IDS_WORD_NOT_IMPLEMENTED
block|,
name|IDS_WORD_NOT_IMPLEMENTED_BRKTS
block|,
name|IDS_WORD_UNKNOWNTYPE_BRKTS
block|,
name|IDS_WORD_ERR_MSG_NOT_IMPLEMENTED_BRKTS
block|,
name|IDS_CMD_ERR_N_OPTIONS_REQUIRED
block|,
name|IDS_CMD_ERR_OPTION_NOT_FOUND
block|,
name|IDS_CMD_ERR_ARGS
block|,
name|IDS_CMD_WRN_ARGS_NOT_HANDLED
block|,
name|IDS_CMD_ERR_FNFAILED
block|,
name|IDS_CMD_ERR_SHARED_DATA_NOT_FOUND
block|,
name|IDS_CMD_ERR_LLDBPROCESS_DETACH
block|,
name|IDS_CMD_ERR_SETWKDIR
block|,
name|IDS_CMD_ERR_INVALID_TARGET
block|,
name|IDS_CMD_ERR_INVALID_TARGET_CURRENT
block|,
name|IDS_CMD_ERR_INVALID_TARGET_TYPE
block|,
name|IDS_CMD_ERR_INVALID_TARGET_PLUGIN
block|,
name|IDS_CMD_ERR_CONNECT_TO_TARGET
block|,
name|IDS_CMD_ERR_INVALID_TARGETPLUGINCURRENT
block|,
name|IDS_CMD_ERR_NOT_IMPLEMENTED
block|,
name|IDS_CMD_ERR_NOT_IMPLEMENTED_DEPRECATED
block|,
name|IDS_CMD_ERR_CREATE_TARGET
block|,
name|IDS_CMD_ERR_BRKPT_LOCATION_FORMAT
block|,
name|IDS_CMD_ERR_BRKPT_INVALID
block|,
name|IDS_CMD_ERR_BRKPT_CNT_EXCEEDED
block|,
name|IDS_CMD_ERR_SOME_ERROR
block|,
name|IDS_CMD_ERR_THREAD_INVALID
block|,
name|IDS_CMD_ERR_THREAD_FRAME_RANGE_INVALID
block|,
name|IDS_CMD_ERR_FRAME_INVALID
block|,
name|IDS_CMD_ERR_VARIABLE_DOESNOTEXIST
block|,
name|IDS_CMD_ERR_VARIABLE_ENUM_INVALID
block|,
name|IDS_CMD_ERR_VARIABLE_EXPRESSIONPATH
block|,
name|IDS_CMD_ERR_VARIABLE_CREATION_FAILED
block|,
name|IDS_CMD_ERR_CMD_RUN_BUT_NO_ACTION
block|,
name|IDS_CMD_ERR_EVENT_HANDLED_BUT_NO_ACTION
block|,
name|IDS_CMD_ERR_DISASM_ADDR_START_INVALID
block|,
name|IDS_CMD_ERR_DISASM_ADDR_END_INVALID
block|,
name|IDS_CMD_ERR_MEMORY_ALLOC_FAILURE
block|,
name|IDS_CMD_ERR_LLDB_ERR_NOT_READ_WHOLE_BLK
block|,
name|IDS_CMD_ERR_LLDB_ERR_READ_MEM_BYTES
block|,
name|IDS_CMD_ERR_INVALID_PROCESS
block|,
name|IDS_CMD_ERR_INVALID_PRINT_VALUES
block|,
name|IDS_CMD_ERR_INVALID_FORMAT_TYPE
block|,
name|IDS_CMD_ERR_BRKPT_INFO_OBJ_NOT_FOUND
block|,
name|IDS_CMD_ERR_LLDB_ERR_WRITE_MEM_BYTES
block|,
name|IDS_CMD_ERR_LLDB_ERR_NOT_WRITE_WHOLEBLK
block|,
name|IDS_CMD_ERR_SET_NEW_DRIVER_STATE
block|,
name|IDS_CMD_ERR_INFO_PRINTFN_NOT_FOUND
block|,
name|IDS_CMD_ERR_INFO_PRINTFN_FAILED
block|,
name|IDS_CMD_ERR_GDBSET_OPT_SOLIBSEARCHPATH
block|}
enum|;
end_enum

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code implementation class. Handle application resources
end_comment

begin_comment
comment|//          and locality.
end_comment

begin_comment
comment|//          Singleton class.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 29/01/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnResources
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnResources
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnResources
operator|>
expr_stmt|;
comment|// Methods:
name|public
label|:
name|bool
name|Initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|Shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|CMIUtilString
name|GetString
argument_list|(
specifier|const
name|MIuint
name|vResourceId
argument_list|)
decl|const
decl_stmt|;
name|bool
name|HasString
argument_list|(
specifier|const
name|MIuint
name|vResourceId
argument_list|)
decl|const
decl_stmt|;
comment|// Typedef:
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|MIuint
operator|,
specifier|const
name|MIchar
operator|*
operator|>
name|MapRscrIdToTextData_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|MIuint
operator|,
specifier|const
name|MIchar
operator|*
operator|>
name|MapPairRscrIdToTextData_t
expr_stmt|;
comment|// Enumerations:
name|private
label|:
enum|enum
name|Buffer_e
block|{
name|eBufferSize
init|=
literal|2048
block|}
enum|;
comment|// Structs:
name|private
label|:
struct|struct
name|SRsrcTextData
block|{
name|MIuint
name|id
decl_stmt|;
specifier|const
name|MIchar
modifier|*
name|pTextData
decl_stmt|;
block|}
struct|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnResources
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnResources
argument_list|(
specifier|const
name|CMICmnResources
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnResources
operator|&
operator|)
decl_stmt|;
name|bool
name|GetStringFromResource
argument_list|(
specifier|const
name|MIuint
name|vResourceId
argument_list|,
name|CMIUtilString
operator|&
name|vrwResourceString
argument_list|)
decl|const
decl_stmt|;
name|bool
name|ReadResourceStringData
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnResources
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
specifier|static
specifier|const
name|SRsrcTextData
name|ms_pResourceId2TextData
index|[]
decl_stmt|;
comment|//
name|MIuint
name|m_nResourceId2TextDataSize
decl_stmt|;
name|MapRscrIdToTextData_t
name|m_mapRscrIdToTextData
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//++ =========================================================================
end_comment

begin_comment
comment|// Details: Macro short cut for retrieving a text data resource
end_comment

begin_comment
comment|//--
end_comment

begin_define
define|#
directive|define
name|MIRSRC
parameter_list|(
name|x
parameter_list|)
value|CMICmnResources::Instance().GetString(x).c_str()
end_define

end_unit

