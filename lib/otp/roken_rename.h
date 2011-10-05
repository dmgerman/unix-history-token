begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|rk_snprintf
value|_otp_snprintf
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
name|rk_asprintf
value|_otp_asprintf
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
name|rk_asnprintf
value|_otp_asnprintf
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
name|rk_vasprintf
value|_otp_vasprintf
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
name|rk_vasnprintf
value|_otp_vasnprintf
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
name|rk_vsnprintf
value|_otp_vsnprintf
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
name|rk_strcasecmp
value|_otp_strcasecmp
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
name|rk_strncasecmp
value|_otp_strncasecmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLWR
end_ifndef

begin_define
define|#
directive|define
name|rk_strlwr
value|_otp_strlwr
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
name|rk_strlcat
value|_otp_strlcat
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
name|rk_strlcpy
value|_otp_strlcpy
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
comment|/* __roken_rename_h__ */
end_comment

end_unit

