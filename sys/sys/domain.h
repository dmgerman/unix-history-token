begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)domain.h	8.1 (Berkeley) 6/2/93  * $Id$  */
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
end_define

begin_comment
comment|/*  * Structure per communications domain.  */
end_comment

begin_comment
comment|/*  * Forward structure declarations for function prototypes [sic].  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

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
name|void
argument_list|(
argument|*dom_init
argument_list|)
comment|/* initialize domain data structures */
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*dom_externalize
argument_list|)
comment|/* externalize access rights */
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*dom_dispose
argument_list|)
comment|/* dispose of internalized rights */
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
expr_stmt|;
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
name|int
argument_list|(
argument|*dom_rtattach
argument_list|)
comment|/* initialize routing table */
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
name|dom_rtoffset
decl_stmt|;
comment|/* an arg to rtattach, in bits */
name|int
name|dom_maxrtkey
decl_stmt|;
comment|/* for routing layer */
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

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|localdomain
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DOMAIN_SET
parameter_list|(
name|name
parameter_list|)
define|\
value|DATA_SET(domain_set, name ## domain);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

