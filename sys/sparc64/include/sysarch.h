begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/include/sysarch.h,v 1.14 2000/09/21  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Architecture specific syscalls (sparc64)  */
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
name|SPARC_UTRAP_INSTALL
value|1
end_define

begin_struct
struct|struct
name|sparc_utrap_install_args
block|{
name|int
name|num
decl_stmt|;
specifier|const
name|struct
name|sparc_utrap_args
modifier|*
name|handlers
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sparc_utrap_args
block|{
name|utrap_entry_t
name|type
decl_stmt|;
name|utrap_handler_t
name|new_precise
decl_stmt|;
name|utrap_handler_t
name|new_deferred
decl_stmt|;
name|utrap_handler_t
modifier|*
name|old_precise
decl_stmt|;
name|utrap_handler_t
modifier|*
name|old_deferred
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
name|__sparc_utrap_install
parameter_list|(
name|utrap_entry_t
name|type
parameter_list|,
name|utrap_handler_t
name|new_precise
parameter_list|,
name|utrap_handler_t
name|new_deferred
parameter_list|,
name|utrap_handler_t
modifier|*
name|old_precise
parameter_list|,
name|utrap_handler_t
modifier|*
name|old_deferred
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

