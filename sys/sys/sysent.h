begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: sysent.h,v 1.14 1997/02/22 09:46:03 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSENT_H_
end_define

begin_typedef
typedef|typedef
name|int
name|sy_call_t
name|__P
typedef|((struct
name|proc
modifier|*
typedef|,
name|void
modifier|*
typedef|));
end_typedef

begin_struct
struct|struct
name|sysent
block|{
comment|/* system call table */
name|int
name|sy_narg
decl_stmt|;
comment|/* number of arguments */
name|sy_call_t
modifier|*
name|sy_call
decl_stmt|;
comment|/* implementing function */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCARG
parameter_list|(
name|p
parameter_list|,
name|k
parameter_list|)
value|((p)->k)
end_define

begin_comment
comment|/* get arg from args pointer */
end_comment

begin_comment
comment|/* placeholder till we integrate rest of lite2 syscallargs changes XXX */
end_comment

begin_struct_decl
struct_decl|struct
name|image_params
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|sysentvec
block|{
name|int
name|sv_size
decl_stmt|;
comment|/* number of entries */
name|struct
name|sysent
modifier|*
name|sv_table
decl_stmt|;
comment|/* pointer to sysent */
name|u_int
name|sv_mask
decl_stmt|;
comment|/* optional mask to index */
name|int
name|sv_sigsize
decl_stmt|;
comment|/* size of signal translation table */
name|int
modifier|*
name|sv_sigtbl
decl_stmt|;
comment|/* signal translation table */
name|int
name|sv_errsize
decl_stmt|;
comment|/* size of errno translation table */
name|int
modifier|*
name|sv_errtbl
decl_stmt|;
comment|/* errno translation table */
name|int
argument_list|(
argument|*sv_fixup
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|*
operator|,
expr|struct
name|image_params
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* stack fixup function */
name|void
argument_list|(
argument|*sv_sendsig
argument_list|)
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|,
name|int
operator|,
name|int
operator|,
name|u_long
operator|)
argument_list|)
expr_stmt|;
comment|/* send signal */
name|char
modifier|*
name|sv_sigcode
decl_stmt|;
comment|/* start of sigtramp code */
name|int
modifier|*
name|sv_szsigcode
decl_stmt|;
comment|/* size of sigtramp code */
name|void
argument_list|(
argument|*sv_prepsyscall
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|trapframe
operator|*
operator|,
name|int
operator|*
operator|,
name|u_int
operator|*
operator|,
name|caddr_t
operator|*
operator|)
argument_list|)
expr_stmt|;
name|char
modifier|*
name|sv_name
decl_stmt|;
comment|/* name of binary type */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|sysentvec
name|aout_sysvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sysent
name|sysent
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SYSENT_H_ */
end_comment

end_unit

