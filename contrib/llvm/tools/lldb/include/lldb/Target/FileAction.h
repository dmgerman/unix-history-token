begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessLaunchInfo.h -------------------------------------*- C++ -*-===//
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
name|liblldb_Target_FileAction_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Target_FileAction_h
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|FileAction
block|{
name|public
label|:
enum|enum
name|Action
block|{
name|eFileActionNone
block|,
name|eFileActionClose
block|,
name|eFileActionDuplicate
block|,
name|eFileActionOpen
block|}
enum|;
name|FileAction
argument_list|()
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|bool
name|Close
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
name|bool
name|Duplicate
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|dup_fd
parameter_list|)
function_decl|;
name|bool
name|Open
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bool
name|read
parameter_list|,
name|bool
name|write
parameter_list|)
function_decl|;
name|int
name|GetFD
argument_list|()
specifier|const
block|{
return|return
name|m_fd
return|;
block|}
name|Action
name|GetAction
argument_list|()
specifier|const
block|{
return|return
name|m_action
return|;
block|}
name|int
name|GetActionArgument
argument_list|()
specifier|const
block|{
return|return
name|m_arg
return|;
block|}
specifier|const
name|char
operator|*
name|GetPath
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|Action
name|m_action
decl_stmt|;
comment|// The action for this file
name|int
name|m_fd
decl_stmt|;
comment|// An existing file descriptor
name|int
name|m_arg
decl_stmt|;
comment|// oflag for eFileActionOpen*, dup_fd for eFileActionDuplicate
name|std
operator|::
name|string
name|m_path
expr_stmt|;
comment|// A file path to use for opening after fork or posix_spawn
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

