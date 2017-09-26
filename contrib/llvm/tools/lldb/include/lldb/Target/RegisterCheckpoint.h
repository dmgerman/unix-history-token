begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterCheckpoint.h ------------------------------------*- C++ -*-===//
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
name|liblldb_RegisterCheckpoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterCheckpoint_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Target/StackID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// Inherit from UserID in case pushing/popping all register values can be
comment|// done using a 64 bit integer that holds a baton/cookie instead of actually
comment|// having to read all register values into a buffer
name|class
name|RegisterCheckpoint
range|:
name|public
name|UserID
block|{
name|public
operator|:
expr|enum
name|class
name|Reason
block|{
comment|// An expression is about to be run on the thread if the protocol that
comment|// talks to the debuggee supports checkpointing the registers using a
comment|// push/pop then the UserID base class in the RegisterCheckpoint can
comment|// be used to store the baton/cookie that refers to the remote saved
comment|// state.
name|eExpression
block|,
comment|// The register checkpoint wants the raw register bytes, so they must
comment|// be read into m_data_sp, or the save/restore checkpoint should fail.
name|eDataBackup
block|}
block|;
name|RegisterCheckpoint
argument_list|(
argument|Reason reason
argument_list|)
operator|:
name|UserID
argument_list|(
literal|0
argument_list|)
block|,
name|m_data_sp
argument_list|()
block|,
name|m_reason
argument_list|(
argument|reason
argument_list|)
block|{}
operator|~
name|RegisterCheckpoint
argument_list|()
block|{}
name|lldb
operator|::
name|DataBufferSP
operator|&
name|GetData
argument_list|()
block|{
return|return
name|m_data_sp
return|;
block|}
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|GetData
argument_list|()
specifier|const
block|{
return|return
name|m_data_sp
return|;
block|}
name|protected
operator|:
name|lldb
operator|::
name|DataBufferSP
name|m_data_sp
block|;
name|Reason
name|m_reason
block|;
comment|// Make RegisterCheckpointSP if you wish to share the data in this class.
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RegisterCheckpoint
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterCheckpoint_h_
end_comment

end_unit

