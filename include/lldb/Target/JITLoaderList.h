begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- JITLoaderList.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_JITLoaderList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_JITLoaderList_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
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
comment|//----------------------------------------------------------------------
comment|/// @class JITLoaderList JITLoaderList.h "lldb/Target/JITLoaderList.h"
comment|///
comment|/// Class used by the Process to hold a list of its JITLoaders.
comment|//----------------------------------------------------------------------
name|class
name|JITLoaderList
block|{
name|public
label|:
name|JITLoaderList
argument_list|()
expr_stmt|;
operator|~
name|JITLoaderList
argument_list|()
expr_stmt|;
name|void
name|Append
argument_list|(
specifier|const
name|lldb
operator|::
name|JITLoaderSP
operator|&
name|jit_loader_sp
argument_list|)
decl_stmt|;
name|void
name|Remove
argument_list|(
specifier|const
name|lldb
operator|::
name|JITLoaderSP
operator|&
name|jit_loader_sp
argument_list|)
decl_stmt|;
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|JITLoaderSP
name|GetLoaderAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
name|void
name|DidLaunch
parameter_list|()
function_decl|;
name|void
name|DidAttach
parameter_list|()
function_decl|;
name|void
name|ModulesDidLoad
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|JITLoaderSP
operator|>
name|m_jit_loaders_vec
expr_stmt|;
name|lldb_private
operator|::
name|Mutex
name|m_jit_loaders_mutex
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
comment|// liblldb_JITLoaderList_h_
end_comment

end_unit

