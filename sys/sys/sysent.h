begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: sysent.h,v 1.3 1995/02/14 19:23:20 sos Exp $  */
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
value|1
end_define

begin_struct
struct|struct
name|sysent
block|{
comment|/* system call table */
name|int
name|sy_narg
decl_stmt|;
comment|/* number of arguments */
name|int
function_decl|(
modifier|*
name|sy_call
function_decl|)
parameter_list|()
function_decl|;
comment|/* implementing function */
block|}
struct|;
end_struct

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
name|unsigned
name|int
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
comment|/* size of signal translation table */
name|int
modifier|*
name|sv_errtbl
decl_stmt|;
comment|/* errno translation table */
name|int
function_decl|(
modifier|*
name|sv_fixup
function_decl|)
parameter_list|()
function_decl|;
comment|/* stack fixup function */
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
comment|/* _SYS_SYSENT_H_ */
end_comment

end_unit

