begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_OS_PAL_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_OS_PAL_H
end_define

begin_expr_stmt
name|__EXTERN_BEGIN_DECLS
comment|/* --------------------------- platform switch ------------------------------ */
comment|/* platform specific header */
include|#
directive|include
file|<dev/vxge/vxge-osdep.h>
define|#
directive|define
name|IN
define|#
directive|define
name|OUT
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VXGE_OS_PLATFORM_64BIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VXGE_OS_PLATFORM_32BIT
argument_list|)
error|#
directive|error
literal|"either 32bit or 64bit switch must be defined!"
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VXGE_OS_HOST_LITTLE_ENDIAN
argument_list|)
error|#
directive|error
literal|"either little endian or big endian switch must be defined!"
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_PLATFORM_64BIT
argument_list|)
define|#
directive|define
name|VXGE_OS_MEMORY_DEADCODE_PAT
value|0x5a5a5a5a5a5a5a5a
else|#
directive|else
define|#
directive|define
name|VXGE_OS_MEMORY_DEADCODE_PAT
value|0x5a5a5a5a
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|VXGE_DEBUG_ASSERT
argument_list|)
comment|/*  * vxge_assert  * @test: C-condition to check  * @fmt: printf like format string  *  * This function implements traditional assert. By default assertions  * are enabled. It can be disabled by defining VXGE_DEBUG_ASSERT macro in  * compilation  * time.  */
define|#
directive|define
name|vxge_assert
parameter_list|(
name|test
parameter_list|)
value|{ \ 	if (!(test)) vxge_os_bug("bad cond: "#test" at %s:%d\n", \ 	__FILE__, __LINE__); }
else|#
directive|else
define|#
directive|define
name|vxge_assert
parameter_list|(
name|test
parameter_list|)
endif|#
directive|endif
comment|/* end of VXGE_DEBUG_ASSERT */
name|__EXTERN_END_DECLS
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_OS_PAL_H */
end_comment

end_unit

