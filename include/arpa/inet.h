begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  *  *	@(#)inet.h	8.1 (Berkeley) 6/2/93  *	From: Id: inet.h,v 8.5 1997/01/29 08:48:09 vixie Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARPA_INET_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARPA_INET_H_
end_define

begin_comment
comment|/* External definitions for functions in inet(3), addr2ascii(3) */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_comment
comment|/* Required for byteorder(3) functions. */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_define
define|#
directive|define
name|INET_ADDRSTRLEN
value|16
end_define

begin_define
define|#
directive|define
name|INET6_ADDRSTRLEN
value|46
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT16_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint16_t
name|uint16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT16_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT32_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint32_t
name|uint32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT32_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IN_ADDR_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|uint32_t
name|in_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_IN_ADDR_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IN_PORT_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|uint16_t
name|in_port_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_IN_PORT_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_comment
comment|/*  * XXX socklen_t is used by a POSIX.1-2001 interface, but not required by  * POSIX.1-2001.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SOCKLEN_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SOCKLEN_T_
name|socklen_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SOCKLEN_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_STRUCT_IN_ADDR_DECLARED
end_ifndef

begin_struct
struct|struct
name|in_addr
block|{
name|in_addr_t
name|s_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_STRUCT_IN_ADDR_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX all new diversions!! argh!! */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|inet_addr
value|__inet_addr
end_define

begin_define
define|#
directive|define
name|inet_aton
value|__inet_aton
end_define

begin_define
define|#
directive|define
name|inet_lnaof
value|__inet_lnaof
end_define

begin_define
define|#
directive|define
name|inet_makeaddr
value|__inet_makeaddr
end_define

begin_define
define|#
directive|define
name|inet_neta
value|__inet_neta
end_define

begin_define
define|#
directive|define
name|inet_netof
value|__inet_netof
end_define

begin_define
define|#
directive|define
name|inet_network
value|__inet_network
end_define

begin_define
define|#
directive|define
name|inet_net_ntop
value|__inet_net_ntop
end_define

begin_define
define|#
directive|define
name|inet_net_pton
value|__inet_net_pton
end_define

begin_define
define|#
directive|define
name|inet_ntoa
value|__inet_ntoa
end_define

begin_define
define|#
directive|define
name|inet_pton
value|__inet_pton
end_define

begin_define
define|#
directive|define
name|inet_ntop
value|__inet_ntop
end_define

begin_define
define|#
directive|define
name|inet_nsap_addr
value|__inet_nsap_addr
end_define

begin_define
define|#
directive|define
name|inet_nsap_ntoa
value|__inet_nsap_ntoa
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_function_decl
name|__BEGIN_DECLS
ifndef|#
directive|ifndef
name|_BYTEORDER_PROTOTYPED
define|#
directive|define
name|_BYTEORDER_PROTOTYPED
name|uint32_t
name|htonl
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|htons
parameter_list|(
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ntohl
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ntohs
parameter_list|(
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|in_addr_t
name|inet_addr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|inet_ntop
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|socklen_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inet_pton
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|ascii2addr
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|addr2ascii
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inet_aton
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|in_addr_t
name|inet_lnaof
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|inet_makeaddr
parameter_list|(
name|in_addr_t
parameter_list|,
name|in_addr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_neta
parameter_list|(
name|in_addr_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|in_addr_t
name|inet_netof
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|in_addr_t
name|inet_network
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_net_ntop
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inet_net_pton
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|inet_nsap_addr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_nsap_ntoa
parameter_list|(
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_BYTEORDER_FUNC_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_BYTEORDER_FUNC_DEFINED
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|__htonl(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|__htons(x)
end_define

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|__ntohl(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|__ntohs(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ARPA_INET_H_ */
end_comment

end_unit

