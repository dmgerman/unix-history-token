begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- InputReaderStack.h --------------------------------------*- C++ -*-===//
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
name|liblldb_InputReaderStack_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_InputReaderStack_h_
end_define

begin_include
include|#
directive|include
file|<stack>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|InputReaderStack
block|{
name|public
label|:
name|InputReaderStack
argument_list|()
expr_stmt|;
operator|~
name|InputReaderStack
argument_list|()
expr_stmt|;
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Push
argument_list|(
specifier|const
name|lldb
operator|::
name|InputReaderSP
operator|&
name|reader_sp
argument_list|)
decl_stmt|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|InputReaderSP
name|Top
argument_list|()
expr_stmt|;
name|void
name|Pop
parameter_list|()
function_decl|;
name|Mutex
modifier|&
name|GetStackMutex
parameter_list|()
function_decl|;
name|protected
label|:
name|std
operator|::
name|stack
operator|<
name|lldb
operator|::
name|InputReaderSP
operator|>
name|m_input_readers
expr_stmt|;
name|mutable
name|Mutex
name|m_input_readers_mutex
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|InputReaderStack
argument_list|)
expr_stmt|;
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

begin_comment
comment|// liblldb_InputReaderStack_h_
end_comment

end_unit

