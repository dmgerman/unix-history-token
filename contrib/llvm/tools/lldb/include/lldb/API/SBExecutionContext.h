begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBExecutionContext.h -----------------------------------------*- C++ -*-===//
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
name|LLDB_SBExecutionContext_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBExecutionContext_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBExecutionContext
block|{
name|friend
name|class
name|SBCommandInterpreter
decl_stmt|;
name|public
label|:
name|SBExecutionContext
argument_list|()
expr_stmt|;
name|SBExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|SBExecutionContext
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|SBExecutionContext
argument_list|(
argument|lldb::ExecutionContextRefSP exe_ctx_ref_sp
argument_list|)
empty_stmt|;
name|SBExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|SBTarget
operator|&
name|target
argument_list|)
expr_stmt|;
name|SBExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|SBProcess
operator|&
name|process
argument_list|)
expr_stmt|;
name|SBExecutionContext
argument_list|(
argument|lldb::SBThread thread
argument_list|)
empty_stmt|;
comment|// can't be a const& because SBThread::get() isn't itself a const function
name|SBExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|frame
argument_list|)
expr_stmt|;
operator|~
name|SBExecutionContext
argument_list|()
expr_stmt|;
specifier|const
name|SBExecutionContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|lldb
operator|::
name|SBExecutionContext
operator|&
name|rhs
operator|)
decl_stmt|;
name|SBTarget
name|GetTarget
argument_list|()
specifier|const
expr_stmt|;
name|SBProcess
name|GetProcess
argument_list|()
specifier|const
expr_stmt|;
name|SBThread
name|GetThread
argument_list|()
specifier|const
expr_stmt|;
name|SBFrame
name|GetFrame
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|ExecutionContextRefSP
operator|&
name|GetSP
argument_list|()
specifier|const
expr_stmt|;
name|void
name|reset
argument_list|(
name|lldb
operator|::
name|ExecutionContextRefSP
operator|&
name|event_sp
argument_list|)
decl_stmt|;
name|lldb_private
operator|::
name|ExecutionContextRef
operator|*
name|get
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|mutable
name|lldb
operator|::
name|ExecutionContextRefSP
name|m_exe_ctx_sp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBExecutionContext_h_
end_comment

end_unit

