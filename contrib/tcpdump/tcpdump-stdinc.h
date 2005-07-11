begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 - 2003  * NetGroup, Politecnico di Torino (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * @(#) $Header: /tcpdump/master/tcpdump/tcpdump-stdinc.h,v 1.12 2005/03/27 01:35:45 guy Exp $ (LBL)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Include the appropriate OS header files on Windows and various flavors  * of UNIX, and also define some additional items and include various  * non-OS header files on Windows, and; this isolates most of the platform  * differences to this one file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tcpdump_stdinc_h
end_ifndef

begin_define
define|#
directive|define
name|tcpdump_stdinc_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|"bittypes.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|"IP6_misc.h"
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<net/netdb.h>
end_include

begin_comment
comment|/* in wpcap's Win32/include */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__WATCOMC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|toascii
end_undef

begin_define
define|#
directive|define
name|isascii
value|__isascii
end_define

begin_define
define|#
directive|define
name|toascii
value|__toascii
end_define

begin_define
define|#
directive|define
name|stat
value|_stat
end_define

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_define
define|#
directive|define
name|fstat
value|_fstat
end_define

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|_O_RDONLY
end_define

begin_typedef
typedef|typedef
name|short
name|ino_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINGW32__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MINGW32__
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Protos for missing/x.c functions (ideally<missing/addrinfo.h>  * should be used, but it clashes with<ws2tcpip.h>).  */
end_comment

begin_function_decl
specifier|extern
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
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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

begin_function_decl
specifier|extern
name|int
name|inet_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|struct
name|in_addr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|INET6_ADDRSTRLEN
end_ifndef

begin_define
define|#
directive|define
name|INET6_ADDRSTRLEN
value|46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|toascii
end_ifndef

begin_define
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x7f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|caddr_t
end_ifndef

begin_typedef
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* caddr_t */
end_comment

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|64
end_define

begin_define
define|#
directive|define
name|NI_MAXHOST
value|1025
end_define

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_define
define|#
directive|define
name|vsnprintf
value|_vsnprintf
end_define

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WIN32 */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_BITYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/bitypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* concession to AIX */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_include
include|#
directive|include
file|"ip6.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|FOPEN_READ_TXT
value|"rt"
end_define

begin_define
define|#
directive|define
name|FOPEN_READ_BIN
value|"rb"
end_define

begin_define
define|#
directive|define
name|FOPEN_WRITE_TXT
value|"wt"
end_define

begin_define
define|#
directive|define
name|FOPEN_WRITE_BIN
value|"wb"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FOPEN_READ_TXT
value|"r"
end_define

begin_define
define|#
directive|define
name|FOPEN_READ_BIN
value|FOPEN_READ_TXT
end_define

begin_define
define|#
directive|define
name|FOPEN_WRITE_TXT
value|"w"
end_define

begin_define
define|#
directive|define
name|FOPEN_WRITE_BIN
value|FOPEN_WRITE_TXT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INET_ADDRSTRLEN
end_ifndef

begin_define
define|#
directive|define
name|INET_ADDRSTRLEN
value|16
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
comment|/* tcpdump_stdinc_h */
end_comment

end_unit

