begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ++Copyright++ 1983, 1993  * -  * Copyright (c) 1983, 1993  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/*  *	@(#)inet.h	8.1 (Berkeley) 6/2/93  *	$Id: inet.h,v 8.8 1999/05/14 18:16:54 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INET_H_
end_ifndef

begin_define
define|#
directive|define
name|_INET_H_
end_define

begin_comment
comment|/* External definitions for functions in inet(3) */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|)
operator|||
operator|(
name|BSD
operator|<
literal|199306
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/bitypes.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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
name|inet_cidr_ntop
value|__inet_cidr_ntop
end_define

begin_define
define|#
directive|define
name|inet_cidr_pton
value|__inet_cidr_pton
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

begin_decl_stmt
name|__BEGIN_DECLS
name|unsigned
name|long
name|inet_addr
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inet_aton
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|inet_lnaof
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|in_addr
name|inet_makeaddr
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|inet_neta
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|inet_netof
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|inet_network
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|inet_net_ntop
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inet_net_pton
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|inet_cidr_ntop
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inet_cidr_pton
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*const*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|inet_ntoa
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inet_pton
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|inet_ntop
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|inet_nsap_addr
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|inet_nsap_ntoa
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|char
operator|*
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

begin_comment
comment|/* !_INET_H_ */
end_comment

end_unit

