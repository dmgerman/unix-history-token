begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from tahoe:	in_cksum.c	1.2	86/01/05  *	from:		@(#)in_cksum.c	1.3 (Berkeley) 1/19/91  *	from: Id: in_cksum.c,v 1.8 1995/12/03 18:35:19 bde Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IN_CKSUM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IN_CKSUM_H_
value|1
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * It it useful to have an Internet checksum routine which is inlineable  * and optimized specifically for the task of computing IP header checksums  * in the normal case (where there are no options and the header length is  * therefore always exactly five 32-bit words.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|in_cksum_update
parameter_list|(
name|struct
name|ip
modifier|*
name|ip
parameter_list|)
block|{
name|int
name|__tmpsum
decl_stmt|;
name|__tmpsum
operator|=
operator|(
name|int
operator|)
name|ntohs
argument_list|(
name|ip
operator|->
name|ip_sum
argument_list|)
operator|+
literal|256
expr_stmt|;
name|ip
operator|->
name|ip_sum
operator|=
name|htons
argument_list|(
name|__tmpsum
operator|+
operator|(
name|__tmpsum
operator|>>
literal|16
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|in_cksum_update
parameter_list|(
name|ip
parameter_list|)
define|\
value|do { \ 		int __tmpsum; \ 		__tmpsum = (int)ntohs(ip->ip_sum) + 256; \ 		ip->ip_sum = htons(__tmpsum + (__tmpsum>> 16)); \ 	} while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|in_psum_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|u_int
name|in_cksum_hdr
parameter_list|(
specifier|const
name|struct
name|ip
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|in_psum_t
name|in_cksum_partial
parameter_list|(
name|in_psum_t
name|psum
parameter_list|,
specifier|const
name|u_short
modifier|*
name|w
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_cksum_finalize
parameter_list|(
name|in_psum_t
name|psum
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IN_CKSUM_H_ */
end_comment

end_unit

