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
name|eServerPacketType_qPlatform_RunCommand
block|,
name|eServerPacketType_qPlatform_IO_MkDir
block|,
name|eServerPacketType_vFile_Open
block|,
name|eServerPacketType_vFile_Close
block|,
name|eServerPacketType_vFile_pRead
block|,
name|eServerPacketType_vFile_pWrite
block|,
name|eServerPacketType_vFile_Size
block|,
name|eServerPacketType_vFile_Mode
block|,
name|eServerPacketType_vFile_Exists
block|,
name|eServerPacketType_vFile_MD5
block|,
name|eServerPacketType_vFile_Stat
block|}
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

