begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_pthread_wrappers.h ----------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of *Sanitizer runtime.
end_comment

begin_comment
comment|// It provides handy wrappers for thread manipulation, that:
end_comment

begin_comment
comment|//  a) assert on any failure rather than returning an error code
end_comment

begin_comment
comment|//  b) defines pthread-like interface on platforms where where<pthread.h>
end_comment

begin_comment
comment|//     is not supplied by default.
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
name|SANITIZER_PTHREAD_WRAPPERS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_PTHREAD_WRAPPERS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_test_utils.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_comment
comment|// Simply forward the arguments and check that the pthread functions succeed.
end_comment

begin_define
define|#
directive|define
name|PTHREAD_CREATE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|ASSERT_EQ(0, pthread_create(a, b, c, d))
end_define

begin_define
define|#
directive|define
name|PTHREAD_JOIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ASSERT_EQ(0, pthread_join(a, b))
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|HANDLE
name|pthread_t
typedef|;
end_typedef

begin_struct
struct|struct
name|PthreadHelperCreateThreadInfo
block|{
name|void
modifier|*
function_decl|(
modifier|*
name|start_routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|inline
name|DWORD
name|WINAPI
name|PthreadHelperThreadProc
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|PthreadHelperCreateThreadInfo
modifier|*
name|start_data
init|=
name|reinterpret_cast
operator|<
name|PthreadHelperCreateThreadInfo
operator|*
operator|>
operator|(
name|arg
operator|)
decl_stmt|;
name|void
modifier|*
name|ret
init|=
call|(
name|start_data
operator|->
name|start_routine
call|)
argument_list|(
name|start_data
operator|->
name|arg
argument_list|)
decl_stmt|;
name|delete
name|start_data
decl_stmt|;
return|return
operator|(
name|DWORD
operator|)
name|ret
return|;
block|}
end_function

begin_function
specifier|inline
name|void
name|PTHREAD_CREATE
parameter_list|(
name|pthread_t
modifier|*
name|thread
parameter_list|,
name|void
modifier|*
name|attr
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|start_routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|ASSERT_EQ
argument_list|(
literal|0
argument_list|,
name|attr
argument_list|)
operator|<<
literal|"Thread attributes are not supported yet."
expr_stmt|;
name|PthreadHelperCreateThreadInfo
modifier|*
name|data
init|=
name|new
name|PthreadHelperCreateThreadInfo
decl_stmt|;
name|data
operator|->
name|start_routine
operator|=
name|start_routine
expr_stmt|;
name|data
operator|->
name|arg
operator|=
name|arg
expr_stmt|;
operator|*
name|thread
operator|=
name|CreateThread
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|PthreadHelperThreadProc
argument_list|,
name|data
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ASSERT_NE
argument_list|(
name|nullptr
argument_list|,
operator|*
name|thread
argument_list|)
operator|<<
literal|"Failed to create a thread."
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|PTHREAD_JOIN
parameter_list|(
name|pthread_t
name|thread
parameter_list|,
name|void
modifier|*
modifier|*
name|value_ptr
parameter_list|)
block|{
name|ASSERT_EQ
argument_list|(
literal|0
argument_list|,
name|value_ptr
argument_list|)
operator|<<
literal|"Nonzero value_ptr is not supported yet."
expr_stmt|;
name|ASSERT_EQ
argument_list|(
name|WAIT_OBJECT_0
argument_list|,
name|WaitForSingleObject
argument_list|(
name|thread
argument_list|,
name|INFINITE
argument_list|)
argument_list|)
expr_stmt|;
name|ASSERT_NE
argument_list|(
literal|0
argument_list|,
name|CloseHandle
argument_list|(
name|thread
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|pthread_exit
parameter_list|(
name|void
modifier|*
name|retval
parameter_list|)
block|{
name|ASSERT_EQ
argument_list|(
literal|0
argument_list|,
name|retval
argument_list|)
operator|<<
literal|"Nonzero retval is not supported yet."
expr_stmt|;
name|ExitThread
argument_list|(
operator|(
name|DWORD
operator|)
name|retval
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN32
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_PTHREAD_WRAPPERS_H
end_comment

end_unit

