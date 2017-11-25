begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (C) 2011 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * Provide an implementation of __aeabi_unwind_cpp_pr{0,1,2}. These are  * required by libc but are implemented in libgcc_eh.a which we don't link  * against. The libgcc_eh.a version will be called so we call abort to  * check this.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
name|void
name|__aeabi_unwind_cpp_pr0
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__aeabi_unwind_cpp_pr1
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__aeabi_unwind_cpp_pr2
argument_list|(
name|void
argument_list|)
name|__hidden
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|__aeabi_unwind_cpp_pr0
parameter_list|(
name|void
parameter_list|)
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__aeabi_unwind_cpp_pr1
parameter_list|(
name|void
parameter_list|)
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__aeabi_unwind_cpp_pr2
parameter_list|(
name|void
parameter_list|)
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

