begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Architecture specific syscalls (i386)  */
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
comment|/* xxxxx */
end_comment

begin_define
define|#
directive|define
name|I386_VM86
value|6
end_define

begin_struct
struct|struct
name|i386_ldt_args
block|{
name|int
name|start
decl_stmt|;
name|union
name|descriptor
modifier|*
name|descs
decl_stmt|;
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

begin_struct
struct|struct
name|i386_vm86_args
block|{
name|int
name|sub_op
decl_stmt|;
comment|/* sub-operation to perform */
name|char
modifier|*
name|sub_args
decl_stmt|;
comment|/* args */
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

begin_union_decl
union_decl|union
name|descriptor
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|dbreg
struct_decl|;
end_struct_decl

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|i386_get_ldt
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|union
name|descriptor
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i386_set_ldt
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|union
name|descriptor
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i386_get_ioperm
name|__P
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i386_set_ioperm
name|__P
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i386_vm86
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i386_set_watch
name|__P
argument_list|(
operator|(
name|int
name|watchnum
operator|,
name|unsigned
name|int
name|watchaddr
operator|,
name|int
name|size
operator|,
name|int
name|access
operator|,
expr|struct
name|dbreg
operator|*
name|d
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i386_clr_watch
name|__P
argument_list|(
operator|(
name|int
name|watchnum
operator|,
expr|struct
name|dbreg
operator|*
name|d
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

