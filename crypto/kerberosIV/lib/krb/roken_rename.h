begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: roken_rename.h,v 1.8.2.1 2000/06/23 03:35:31 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__roken_rename_h__
end_ifndef

begin_define
define|#
directive|define
name|__roken_rename_h__
end_define

begin_comment
comment|/*  * Libroken routines that are added libkrb  */
end_comment

begin_define
define|#
directive|define
name|base64_decode
value|_krb_base64_decode
end_define

begin_define
define|#
directive|define
name|base64_encode
value|_krb_base64_encode
end_define

begin_define
define|#
directive|define
name|net_write
value|roken_net_write
end_define

begin_define
define|#
directive|define
name|net_read
value|roken_net_read
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FLOCK
end_ifndef

begin_define
define|#
directive|define
name|flock
value|_krb_flock
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETHOSTNAME
end_ifndef

begin_define
define|#
directive|define
name|gethostname
value|_krb_gethostname
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETTIMEOFDAY
end_ifndef

begin_define
define|#
directive|define
name|gettimeofday
value|_krb_gettimeofday
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETUID
end_ifndef

begin_define
define|#
directive|define
name|getuid
value|_krb_getuid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|snprintf
value|_krb_snprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ASPRINTF
end_ifndef

begin_define
define|#
directive|define
name|asprintf
value|_krb_asprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ASNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|asnprintf
value|_krb_asnprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VASPRINTF
end_ifndef

begin_define
define|#
directive|define
name|vasprintf
value|_krb_vasprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VASNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|vasnprintf
value|_krb_vasnprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VSNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|vsnprintf
value|_krb_vsnprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRCASECMP
end_ifndef

begin_define
define|#
directive|define
name|strcasecmp
value|_krb_strcasecmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRNCASECMP
end_ifndef

begin_define
define|#
directive|define
name|strncasecmp
value|_krb_strncasecmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRDUP
end_ifndef

begin_define
define|#
directive|define
name|strdup
value|_krb_strdup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCAT
end_ifndef

begin_define
define|#
directive|define
name|strlcat
value|_krb_strlcat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_define
define|#
directive|define
name|strlcpy
value|_krb_strlcpy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRNLEN
end_ifndef

begin_define
define|#
directive|define
name|strnlen
value|_krb_strnlen
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SWAB
end_ifndef

begin_define
define|#
directive|define
name|swab
value|_krb_swab
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRTOK_R
end_ifndef

begin_define
define|#
directive|define
name|strtok_r
value|_krb_strtok_r
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dns_free_data
value|_krb_dns_free_data
end_define

begin_define
define|#
directive|define
name|dns_lookup
value|_krb_dns_lookup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __roken_rename_h__ */
end_comment

end_unit

