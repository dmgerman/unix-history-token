begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Architecture specific syscalls (AMD64)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SYSARCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SYSARCH_H_
end_define

begin_define
define|#
directive|define
name|I386_GET_LDT
value|0
end_define

begin_define
define|#
directive|define
name|I386_SET_LDT
value|1
end_define

begin_define
define|#
directive|define
name|LDT_AUTO_ALLOC
value|0xffffffff
end_define

begin_comment
comment|/* I386_IOPL */
end_comment

begin_define
define|#
directive|define
name|I386_GET_IOPERM
value|3
end_define

begin_define
define|#
directive|define
name|I386_SET_IOPERM
value|4
end_define

begin_comment
comment|/* XXX Not implementable #define I386_VM86	6 */
end_comment

begin_define
define|#
directive|define
name|I386_GET_FSBASE
value|7
end_define

begin_define
define|#
directive|define
name|I386_SET_FSBASE
value|8
end_define

begin_define
define|#
directive|define
name|I386_GET_GSBASE
value|9
end_define

begin_define
define|#
directive|define
name|I386_SET_GSBASE
value|10
end_define

begin_comment
comment|/* Leave space for 0-127 for to avoid translating syscalls */
end_comment

begin_define
define|#
directive|define
name|AMD64_GET_FSBASE
value|128
end_define

begin_define
define|#
directive|define
name|AMD64_SET_FSBASE
value|129
end_define

begin_define
define|#
directive|define
name|AMD64_GET_GSBASE
value|130
end_define

begin_define
define|#
directive|define
name|AMD64_SET_GSBASE
value|131
end_define

begin_struct
struct|struct
name|i386_ldt_args
block|{
name|unsigned
name|int
name|start
decl_stmt|;
name|struct
name|user_segment_descriptor
modifier|*
name|descs
name|__packed
decl_stmt|;
name|unsigned
name|int
name|num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i386_ioperm_args
block|{
name|unsigned
name|int
name|start
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
name|int
name|enable
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|amd64_get_fsbase
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|amd64_get_gsbase
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|amd64_set_fsbase
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|amd64_set_gsbase
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysarch
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SYSARCH_H_ */
end_comment

end_unit

