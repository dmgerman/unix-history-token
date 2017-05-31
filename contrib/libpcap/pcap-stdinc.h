begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 - 2005 NetGroup, Politecnico di Torino (Italy)  * Copyright (c) 2005 - 2009 CACE Technologies, Inc. Davis (California)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|pcap_stdinc_h
end_ifndef

begin_define
define|#
directive|define
name|pcap_stdinc_h
end_define

begin_comment
comment|/*  * Avoids a compiler warning in case this was already defined  * (someone defined _WINSOCKAPI_ when including 'windows.h', in order  * to prevent it from including 'winsock.h')  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WINSOCKAPI_
end_ifdef

begin_undef
undef|#
directive|undef
name|_WINSOCKAPI_
end_undef

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
file|<fcntl.h>
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
file|<ws2tcpip.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_comment
comment|/*    * MSVC.    */
end_comment

begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1800
end_if

begin_comment
comment|/*      * VS 2013 or newer; we have<inttypes.h>.      */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_define
define|#
directive|define
name|u_int8_t
value|uint8_t
end_define

begin_define
define|#
directive|define
name|u_int16_t
value|uint16_t
end_define

begin_define
define|#
directive|define
name|u_int32_t
value|uint32_t
end_define

begin_define
define|#
directive|define
name|u_int64_t
value|uint64_t
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*      * Earlier VS; we have to define this stuff ourselves.      */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT8_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|int8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT16_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|int16_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT32_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT64_T
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_EXTENSIONS
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|_int64
name|u_int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_int64
name|int64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _MSC_EXTENSIONS */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_elif

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

begin_comment
comment|/* pcap_stdinc_h */
end_comment

end_unit

