begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1983, 1988, 1993  *     The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)netdb.h	8.1 (Berkeley) 6/2/93  *      netdb.h,v 1.4 1995/08/14 04:05:04 hjl Exp  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETDB_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_THREAD_SAFE_FUNCTIONS
argument_list|)
operator|||
name|defined
argument_list|(
name|_REENTRANT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<net/paths.h>
end_include

begin_define
define|#
directive|define
name|_PATH_HEQUIV
value|__PATH_ETC_INET"/hosts.equiv"
end_define

begin_define
define|#
directive|define
name|_PATH_HOSTS
value|__PATH_ETC_INET"/hosts"
end_define

begin_define
define|#
directive|define
name|_PATH_NETWORKS
value|__PATH_ETC_INET"/networks"
end_define

begin_define
define|#
directive|define
name|_PATH_PROTOCOLS
value|__PATH_ETC_INET"/protocols"
end_define

begin_define
define|#
directive|define
name|_PATH_SERVICES
value|__PATH_ETC_INET"/services"
end_define

begin_define
define|#
directive|define
name|_PATH_RESCONF
value|__PATH_ETC_INET"/resolv.conf"
end_define

begin_define
define|#
directive|define
name|_PATH_RPC
value|__PATH_ETC_INET"/rpc"
end_define

begin_struct
struct|struct
name|rpcent
block|{
name|char
modifier|*
name|r_name
decl_stmt|;
comment|/* name of server for this rpc program */
name|char
modifier|*
modifier|*
name|r_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|r_number
decl_stmt|;
comment|/* rpc program number */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_THREAD_SAFE_FUNCTIONS
argument_list|)
operator|||
name|defined
argument_list|(
name|_REENTRANT
argument_list|)
end_if

begin_define
define|#
directive|define
name|__NETDB_MAXALIASES
value|35
end_define

begin_define
define|#
directive|define
name|__NETDB_MAXADDRS
value|35
end_define

begin_comment
comment|/*  * Error return codes from gethostbyname() and gethostbyaddr()  * (left in extern int h_errno).  */
end_comment

begin_define
define|#
directive|define
name|h_errno
value|(*__h_errno_location ())
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|h_errno
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

begin_define
define|#
directive|define
name|NETDB_INTERNAL
value|-1
end_define

begin_comment
comment|/* see errno */
end_comment

begin_define
define|#
directive|define
name|NETDB_SUCCESS
value|0
end_define

begin_comment
comment|/* no problem */
end_comment

begin_comment
comment|//#include<features.h>
end_comment

begin_function_decl
name|void
name|endhostent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endnetent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endprotoent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endservent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endrpcent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetbyaddr
parameter_list|(
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* u_long? */
end_comment

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|getprotoent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|getservent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rpcent
modifier|*
name|getrpcent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rpcent
modifier|*
name|getrpcbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rpcent
modifier|*
name|getrpcbynumber
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|herror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sethostent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* void		sethostfile (const char *); */
end_comment

begin_function_decl
name|void
name|setnetent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setprotoent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setservent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setrpcent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_THREAD_SAFE_FUNCTIONS
argument_list|)
operator|||
name|defined
argument_list|(
name|_REENTRANT
argument_list|)
end_if

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyaddr_r
parameter_list|(
specifier|const
name|char
modifier|*
name|__addr
parameter_list|,
name|int
name|__length
parameter_list|,
name|int
name|__type
parameter_list|,
name|struct
name|hostent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|,
name|int
modifier|*
name|__h_errnop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyname_r
parameter_list|(
specifier|const
name|char
modifier|*
name|__name
parameter_list|,
name|struct
name|hostent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|,
name|int
modifier|*
name|__h_errnop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostent_r
parameter_list|(
name|struct
name|hostent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|,
name|int
modifier|*
name|__h_errnop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetbyaddr_r
parameter_list|(
name|long
name|__net
parameter_list|,
name|int
name|__type
parameter_list|,
name|struct
name|netent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetbyname_r
parameter_list|(
specifier|const
name|char
modifier|*
name|__name
parameter_list|,
name|struct
name|netent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetent_r
parameter_list|(
name|struct
name|netent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|getprotobyname_r
parameter_list|(
specifier|const
name|char
modifier|*
name|__name
parameter_list|,
name|struct
name|protoent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|getprotobynumber_r
parameter_list|(
name|int
name|__proto
parameter_list|,
name|struct
name|protoent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|getprotoent_r
parameter_list|(
name|struct
name|protoent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|getservbyname_r
parameter_list|(
specifier|const
name|char
modifier|*
name|__name
parameter_list|,
specifier|const
name|char
modifier|*
name|__proto
parameter_list|,
name|struct
name|servent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|getservbyport_r
parameter_list|(
name|int
name|__port
parameter_list|,
specifier|const
name|char
modifier|*
name|__proto
parameter_list|,
name|struct
name|servent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|getservent_r
parameter_list|(
name|struct
name|servent
modifier|*
name|__result
parameter_list|,
name|char
modifier|*
name|__buffer
parameter_list|,
name|int
name|__buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|__h_errno_location
parameter_list|(
name|void
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
comment|/* !_NETDB_H_ */
end_comment

end_unit

