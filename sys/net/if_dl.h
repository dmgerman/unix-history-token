begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_dl.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_DL_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_DL_H_
end_define

begin_comment
comment|/*  * A Link-Level Sockaddr may specify the interface in one of two  * ways: either by means of a system-provided index number (computed  * anew and possibly differently on every reboot), or by a human-readable  * string such as "il0" (for managerial convenience).  *  * Census taking actions, such as something akin to SIOCGCONF would return  * both the index and the human name.  *  * High volume transactions (such as giving a link-level ``from'' address  * in a recvfrom or recvmsg call) may be likely only to provide the indexed  * form, (which requires fewer copy operations and less space).  *  * The form and interpretation  of the link-level address is purely a matter  * of convention between the device driver and its consumers; however, it is  * expected that all drivers for an interface of a given if_type will agree.  */
end_comment

begin_comment
comment|/*  * Structure of a Link-Level sockaddr:  */
end_comment

begin_struct
struct|struct
name|sockaddr_dl
block|{
name|u_char
name|sdl_len
decl_stmt|;
comment|/* Total length of sockaddr */
name|u_char
name|sdl_family
decl_stmt|;
comment|/* AF_LINK */
name|u_short
name|sdl_index
decl_stmt|;
comment|/* if != 0, system given index for interface */
name|u_char
name|sdl_type
decl_stmt|;
comment|/* interface type */
name|u_char
name|sdl_nlen
decl_stmt|;
comment|/* interface name length, no trailing 0 reqd. */
name|u_char
name|sdl_alen
decl_stmt|;
comment|/* link level address length */
name|u_char
name|sdl_slen
decl_stmt|;
comment|/* link layer selector length */
name|char
name|sdl_data
index|[
literal|12
index|]
decl_stmt|;
comment|/* minimum work area, can be larger; 				   contains both if name and ll address */
name|u_short
name|sdl_rcf
decl_stmt|;
comment|/* source routing control */
name|u_short
name|sdl_route
index|[
literal|16
index|]
decl_stmt|;
comment|/* source routing information */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LLADDR
parameter_list|(
name|s
parameter_list|)
value|((caddr_t)((s)->sdl_data + (s)->sdl_nlen))
end_define

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
name|void
name|link_addr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr_dl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|link_ntoa
parameter_list|(
specifier|const
name|struct
name|sockaddr_dl
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

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

