begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadLauncher.h -----------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|lldb_Host_ThreadLauncher_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_ThreadLauncher_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadLauncher
block|{
name|public
label|:
specifier|static
name|HostThread
name|LaunchThread
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
name|lldb
operator|::
name|thread_func_t
name|thread_function
argument_list|,
name|lldb
operator|::
name|thread_arg_t
name|thread_arg
argument_list|,
name|Status
operator|*
name|error_ptr
argument_list|,
name|size_t
name|min_stack_byte_size
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|// Minimum stack size in bytes,
comment|// set stack size to zero for
comment|// default platform thread stack
comment|// size
struct|struct
name|HostThreadCreateInfo
block|{
name|std
operator|::
name|string
name|thread_name
expr_stmt|;
name|lldb
operator|::
name|thread_func_t
name|thread_fptr
expr_stmt|;
name|lldb
operator|::
name|thread_arg_t
name|thread_arg
expr_stmt|;
name|HostThreadCreateInfo
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::thread_func_t fptr
argument_list|,
argument|lldb::thread_arg_t arg
argument_list|)
block|:
name|thread_name
argument_list|(
name|name
condition|?
name|name
else|:
literal|""
argument_list|)
operator|,
name|thread_fptr
argument_list|(
name|fptr
argument_list|)
operator|,
name|thread_arg
argument_list|(
argument|arg
argument_list|)
block|{}
block|}
struct|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

