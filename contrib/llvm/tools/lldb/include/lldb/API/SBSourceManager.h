begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBSourceManager.h ---------------------------------------*- C++ -*-===//
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
name|LLDB_SBSourceManager_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBSourceManager_h_
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

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBSourceManager
block|{
name|public
label|:
name|SBSourceManager
argument_list|(
specifier|const
name|SBDebugger
operator|&
name|debugger
argument_list|)
expr_stmt|;
name|SBSourceManager
argument_list|(
specifier|const
name|SBTarget
operator|&
name|target
argument_list|)
expr_stmt|;
name|SBSourceManager
argument_list|(
specifier|const
name|SBSourceManager
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBSourceManager
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBSourceManager
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBSourceManager
operator|&
name|rhs
operator|)
expr_stmt|;
name|size_t
name|DisplaySourceLinesWithLineNumbers
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|file
argument_list|,
name|uint32_t
name|line
argument_list|,
name|uint32_t
name|context_before
argument_list|,
name|uint32_t
name|context_after
argument_list|,
specifier|const
name|char
operator|*
name|current_line_cstr
argument_list|,
name|lldb
operator|::
name|SBStream
operator|&
name|s
argument_list|)
decl_stmt|;
name|protected
label|:
name|friend
name|class
name|SBCommandInterpreter
decl_stmt|;
name|friend
name|class
name|SBDebugger
decl_stmt|;
name|SBSourceManager
argument_list|(
name|lldb_private
operator|::
name|SourceManager
operator|*
name|source_manager
argument_list|)
expr_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|SourceManagerImpl
operator|>
name|m_opaque_ap
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
comment|// LLDB_SBSourceManager_h_
end_comment

end_unit

