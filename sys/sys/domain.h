begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)domain.h	7.4 (Berkeley) 6/28/90  *	$Id: domain.h,v 1.2 1993/10/16 17:16:39 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DOMAIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DOMAIN_H_
value|1
end_define

begin_comment
comment|/*  * Structure per communications domain.  */
end_comment

begin_struct
struct|struct
name|domain
block|{
name|int
name|dom_family
decl_stmt|;
comment|/* AF_xxx */
name|char
modifier|*
name|dom_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dom_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* initialize domain data structures */
name|int
function_decl|(
modifier|*
name|dom_externalize
function_decl|)
parameter_list|()
function_decl|;
comment|/* externalize access rights */
name|int
function_decl|(
modifier|*
name|dom_dispose
function_decl|)
parameter_list|()
function_decl|;
comment|/* dispose of internalized rights */
name|struct
name|protosw
modifier|*
name|dom_protosw
decl_stmt|,
modifier|*
name|dom_protoswNPROTOSW
decl_stmt|;
name|struct
name|domain
modifier|*
name|dom_next
decl_stmt|;
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
name|domain
modifier|*
name|domains
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
comment|/* _SYS_DOMAIN_H_ */
end_comment

end_unit

