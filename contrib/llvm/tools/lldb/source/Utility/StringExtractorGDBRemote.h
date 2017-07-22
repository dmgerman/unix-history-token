begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StringExtractorGDBRemote.h ------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|utility_StringExtractorGDBRemote_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_StringExtractorGDBRemote_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StringExtractor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint8_t
end_comment

begin_decl_stmt
name|class
name|StringExtractorGDBRemote
range|:
name|public
name|StringExtractor
block|{
name|public
operator|:
typedef|typedef
name|bool
function_decl|(
modifier|*
name|ResponseValidatorCallback
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|StringExtractorGDBRemote
modifier|&
name|response
parameter_list|)
function_decl|;
name|StringExtractorGDBRemote
argument_list|()
operator|:
name|StringExtractor
argument_list|()
block|,
name|m_validator
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|StringExtractorGDBRemote
argument_list|(
argument|llvm::StringRef str
argument_list|)
operator|:
name|StringExtractor
argument_list|(
name|str
argument_list|)
decl_stmt|,
name|m_validator
argument_list|(
name|nullptr
argument_list|)
block|{}
end_decl_stmt

begin_expr_stmt
name|StringExtractorGDBRemote
argument_list|(
specifier|const
name|char
operator|*
name|cstr
argument_list|)
operator|:
name|StringExtractor
argument_list|(
name|cstr
argument_list|)
operator|,
name|m_validator
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|StringExtractorGDBRemote
argument_list|(
specifier|const
name|StringExtractorGDBRemote
operator|&
name|rhs
argument_list|)
operator|:
name|StringExtractor
argument_list|(
name|rhs
argument_list|)
operator|,
name|m_validator
argument_list|(
argument|rhs.m_validator
argument_list|)
block|{}
name|virtual
operator|~
name|StringExtractorGDBRemote
argument_list|()
block|{}
name|bool
name|ValidateResponse
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|CopyResponseValidator
parameter_list|(
specifier|const
name|StringExtractorGDBRemote
modifier|&
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetResponseValidator
parameter_list|(
name|ResponseValidatorCallback
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetResponseValidatorToOKErrorNotSupported
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetResponseValidatorToASCIIHexBytes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetResponseValidatorToJSON
parameter_list|()
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ServerPacketType
block|{
name|eServerPacketType_nack
init|=
literal|0
block|,
name|eServerPacketType_ack
block|,
name|eServerPacketType_invalid
block|,
name|eServerPacketType_unimplemented
block|,
name|eServerPacketType_interrupt
block|,
comment|// CTRL+c packet or "\x03"
name|eServerPacketType_A
block|,
comment|// Program arguments packet
name|eServerPacketType_qfProcessInfo
block|,
name|eServerPacketType_qsProcessInfo
block|,
name|eServerPacketType_qC
block|,
name|eServerPacketType_qEcho
block|,
name|eServerPacketType_qGroupName
block|,
name|eServerPacketType_qHostInfo
block|,
name|eServerPacketType_qLaunchGDBServer
block|,
name|eServerPacketType_qQueryGDBServer
block|,
name|eServerPacketType_qKillSpawnedProcess
block|,
name|eServerPacketType_qLaunchSuccess
block|,
name|eServerPacketType_qModuleInfo
block|,
name|eServerPacketType_qProcessInfoPID
block|,
name|eServerPacketType_qSpeedTest
block|,
name|eServerPacketType_qUserName
block|,
name|eServerPacketType_qGetWorkingDir
block|,
name|eServerPacketType_qFileLoadAddress
block|,
name|eServerPacketType_QEnvironment
block|,
name|eServerPacketType_QEnableErrorStrings
block|,
name|eServerPacketType_QLaunchArch
block|,
name|eServerPacketType_QSetDisableASLR
block|,
name|eServerPacketType_QSetDetachOnError
block|,
name|eServerPacketType_QSetSTDIN
block|,
name|eServerPacketType_QSetSTDOUT
block|,
name|eServerPacketType_QSetSTDERR
block|,
name|eServerPacketType_QSetWorkingDir
block|,
name|eServerPacketType_QStartNoAckMode
block|,
name|eServerPacketType_qPlatform_shell
block|,
name|eServerPacketType_qPlatform_mkdir
block|,
name|eServerPacketType_qPlatform_chmod
block|,
name|eServerPacketType_vFile_open
block|,
name|eServerPacketType_vFile_close
block|,
name|eServerPacketType_vFile_pread
block|,
name|eServerPacketType_vFile_pwrite
block|,
name|eServerPacketType_vFile_size
block|,
name|eServerPacketType_vFile_mode
block|,
name|eServerPacketType_vFile_exists
block|,
name|eServerPacketType_vFile_md5
block|,
name|eServerPacketType_vFile_stat
block|,
name|eServerPacketType_vFile_symlink
block|,
name|eServerPacketType_vFile_unlink
block|,
comment|// debug server packages
name|eServerPacketType_QEnvironmentHexEncoded
block|,
name|eServerPacketType_QListThreadsInStopReply
block|,
name|eServerPacketType_QPassSignals
block|,
name|eServerPacketType_QRestoreRegisterState
block|,
name|eServerPacketType_QSaveRegisterState
block|,
name|eServerPacketType_QSetLogging
block|,
name|eServerPacketType_QSetMaxPacketSize
block|,
name|eServerPacketType_QSetMaxPayloadSize
block|,
name|eServerPacketType_QSetEnableAsyncProfiling
block|,
name|eServerPacketType_QSyncThreadState
block|,
name|eServerPacketType_QThreadSuffixSupported
block|,
name|eServerPacketType_jThreadsInfo
block|,
name|eServerPacketType_qsThreadInfo
block|,
name|eServerPacketType_qfThreadInfo
block|,
name|eServerPacketType_qGetPid
block|,
name|eServerPacketType_qGetProfileData
block|,
name|eServerPacketType_qGDBServerVersion
block|,
name|eServerPacketType_qMemoryRegionInfo
block|,
name|eServerPacketType_qMemoryRegionInfoSupported
block|,
name|eServerPacketType_qProcessInfo
block|,
name|eServerPacketType_qRcmd
block|,
name|eServerPacketType_qRegisterInfo
block|,
name|eServerPacketType_qShlibInfoAddr
block|,
name|eServerPacketType_qStepPacketSupported
block|,
name|eServerPacketType_qSupported
block|,
name|eServerPacketType_qSyncThreadStateSupported
block|,
name|eServerPacketType_qThreadExtraInfo
block|,
name|eServerPacketType_qThreadStopInfo
block|,
name|eServerPacketType_qVAttachOrWaitSupported
block|,
name|eServerPacketType_qWatchpointSupportInfo
block|,
name|eServerPacketType_qWatchpointSupportInfoSupported
block|,
name|eServerPacketType_qXfer_auxv_read
block|,
name|eServerPacketType_jSignalsInfo
block|,
name|eServerPacketType_jModulesInfo
block|,
name|eServerPacketType_vAttach
block|,
name|eServerPacketType_vAttachWait
block|,
name|eServerPacketType_vAttachOrWait
block|,
name|eServerPacketType_vAttachName
block|,
name|eServerPacketType_vCont
block|,
name|eServerPacketType_vCont_actions
block|,
comment|// vCont?
name|eServerPacketType_stop_reason
block|,
comment|// '?'
name|eServerPacketType_c
block|,
name|eServerPacketType_C
block|,
name|eServerPacketType_D
block|,
name|eServerPacketType_g
block|,
name|eServerPacketType_G
block|,
name|eServerPacketType_H
block|,
name|eServerPacketType_I
block|,
comment|// stdin notification
name|eServerPacketType_k
block|,
name|eServerPacketType_m
block|,
name|eServerPacketType_M
block|,
name|eServerPacketType_p
block|,
name|eServerPacketType_P
block|,
name|eServerPacketType_s
block|,
name|eServerPacketType_S
block|,
name|eServerPacketType_T
block|,
name|eServerPacketType_x
block|,
name|eServerPacketType_X
block|,
name|eServerPacketType_Z
block|,
name|eServerPacketType_z
block|,
name|eServerPacketType__M
block|,
name|eServerPacketType__m
block|,
name|eServerPacketType_notify
block|,
comment|// '%' notification
name|eServerPacketType_jTraceStart
block|,
name|eServerPacketType_jTraceBufferRead
block|,
name|eServerPacketType_jTraceMetaRead
block|,
name|eServerPacketType_jTraceStop
block|,
name|eServerPacketType_jTraceConfigRead
block|,   }
enum|;
end_enum

begin_expr_stmt
name|ServerPacketType
name|GetServerPacketType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|ResponseType
block|{
name|eUnsupported
init|=
literal|0
block|,
name|eAck
block|,
name|eNack
block|,
name|eError
block|,
name|eOK
block|,
name|eResponse
block|}
enum|;
end_enum

begin_expr_stmt
name|ResponseType
name|GetResponseType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsOKResponse
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsUnsupportedResponse
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsNormalResponse
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsErrorResponse
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns zero if the packet isn't a EXX packet where XX are two hex
end_comment

begin_comment
comment|// digits. Otherwise the error encoded in XX is returned.
end_comment

begin_function_decl
name|uint8_t
name|GetError
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb_private
operator|::
name|Status
name|GetStatus
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|size_t
name|GetEscapedBinaryData
argument_list|(
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|ResponseValidatorCallback
name|m_validator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|m_validator_baton
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// utility_StringExtractorGDBRemote_h_
end_comment

end_unit

