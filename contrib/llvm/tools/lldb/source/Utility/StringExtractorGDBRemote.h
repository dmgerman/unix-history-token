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

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"Utility/StringExtractor.h"
end_include

begin_decl_stmt
name|class
name|StringExtractorGDBRemote
range|:
name|public
name|StringExtractor
block|{
name|public
operator|:
name|StringExtractorGDBRemote
argument_list|()
operator|:
name|StringExtractor
argument_list|()
block|{     }
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
argument|cstr
argument_list|)
block|{     }
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
argument|rhs
argument_list|)
block|{     }
name|virtual
operator|~
name|StringExtractorGDBRemote
argument_list|()
block|{     }
expr|enum
name|ServerPacketType
block|{
name|eServerPacketType_nack
operator|=
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
name|eServerPacketType_qGroupName
block|,
name|eServerPacketType_qHostInfo
block|,
name|eServerPacketType_qLaunchGDBServer
block|,
name|eServerPacketType_qKillSpawnedProcess
block|,
name|eServerPacketType_qLaunchSuccess
block|,
name|eServerPacketType_qProcessInfoPID
block|,
name|eServerPacketType_qSpeedTest
block|,
name|eServerPacketType_qUserName
block|,
name|eServerPacketType_qGetWorkingDir
block|,
name|eServerPacketType_QEnvironment
block|,
name|eServerPacketType_QLaunchArch
block|,
name|eServerPacketType_QSetDisableASLR
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
name|eServerPacketType_Z
block|,
name|eServerPacketType_z
block|,
name|eServerPacketType__M
block|,
name|eServerPacketType__m
block|,     }
block|;
name|ServerPacketType
name|GetServerPacketType
argument_list|()
specifier|const
block|;      enum
name|ResponseType
block|{
name|eUnsupported
operator|=
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
block|;
name|ResponseType
name|GetResponseType
argument_list|()
specifier|const
block|;
name|bool
name|IsOKResponse
argument_list|()
specifier|const
block|;
name|bool
name|IsUnsupportedResponse
argument_list|()
specifier|const
block|;
name|bool
name|IsNormalResponse
argument_list|()
specifier|const
block|;
name|bool
name|IsErrorResponse
argument_list|()
specifier|const
block|;
comment|// Returns zero if the packet isn't a EXX packet where XX are two hex
comment|// digits. Otherwise the error encoded in XX is returned.
name|uint8_t
name|GetError
argument_list|()
block|;
name|size_t
name|GetEscapedBinaryData
argument_list|(
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// utility_StringExtractorGDBRemote_h_
end_comment

end_unit

