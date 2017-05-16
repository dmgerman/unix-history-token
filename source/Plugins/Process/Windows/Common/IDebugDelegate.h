begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IDebugDelegate.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Windows_IDebugDelegate_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_IDebugDelegate_H_
end_define

begin_include
include|#
directive|include
file|"ForwardDecl.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

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
name|Status
decl_stmt|;
name|class
name|HostThread
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// IDebugDelegate
comment|//
comment|// IDebugDelegate defines an interface which allows implementors to receive
comment|// notification of events that happen in a debugged process.
comment|//----------------------------------------------------------------------
name|class
name|IDebugDelegate
block|{
name|public
label|:
name|virtual
operator|~
name|IDebugDelegate
argument_list|()
block|{}
name|virtual
name|void
name|OnExitProcess
argument_list|(
argument|uint32_t exit_code
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|OnDebuggerConnected
argument_list|(
name|lldb
operator|::
name|addr_t
name|image_base
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|ExceptionResult
name|OnDebugException
parameter_list|(
name|bool
name|first_chance
parameter_list|,
specifier|const
name|ExceptionRecord
modifier|&
name|record
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|OnCreateThread
parameter_list|(
specifier|const
name|HostThread
modifier|&
name|thread
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|OnExitThread
argument_list|(
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|,
name|uint32_t
name|exit_code
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|OnLoadDll
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|lldb
operator|::
name|addr_t
name|module_addr
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|OnUnloadDll
argument_list|(
name|lldb
operator|::
name|addr_t
name|module_addr
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|OnDebugString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|string
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|OnDebuggerError
parameter_list|(
specifier|const
name|Status
modifier|&
name|error
parameter_list|,
name|uint32_t
name|type
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

