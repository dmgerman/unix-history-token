begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: krb5_locl.h,v 1.63 1999/12/02 17:05:11 joda Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KRB5_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__KRB5_LOCL_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
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
name|HAVE_SYS_IOCTL_H
argument_list|)
operator|&&
name|SunOS
operator|!=
literal|40
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN6_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET6_IN6_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/in6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_struct_decl
struct_decl|struct
name|ether_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_dl
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_NAMESER_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<parse_time.h>
end_include

begin_include
include|#
directive|include
file|<base64.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL_DES_H
end_ifdef

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL_MD4_H
end_ifdef

begin_include
include|#
directive|include
file|<openssl/md4.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<md4.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL_MD5_H
end_ifdef

begin_include
include|#
directive|include
file|<openssl/md5.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL_SHA_H
end_ifdef

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sha.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL_RC4_H
end_ifdef

begin_include
include|#
directive|include
file|<openssl/rc4.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<rc4.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<asn1.h>
end_include

begin_include
include|#
directive|include
file|<der.h>
end_include

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_include
include|#
directive|include
file|<krb5_err.h>
end_include

begin_include
include|#
directive|include
file|<asn1_err.h>
end_include

begin_include
include|#
directive|include
file|<krb5-private.h>
end_include

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(X) = calloc((N), sizeof(*(X)))
end_define

begin_define
define|#
directive|define
name|ALLOC_SEQ
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|do { (X)->len = (N); ALLOC((X)->val, (N)); } while(0)
end_define

begin_comment
comment|/* should this be public? */
end_comment

begin_define
define|#
directive|define
name|KEYTAB_DEFAULT
value|"FILE:/etc/krb5.keytab"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0
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
comment|/* __KRB5_LOCL_H__ */
end_comment

end_unit

