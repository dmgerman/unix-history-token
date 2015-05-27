begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 - 2005 NetGroup, Politecnico di Torino (Italy)  * Copyright (c) 2005 - 2009 CACE Technologies, Inc. Davis (California)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|"bittypes.h"
end_include

begin_include
include|#
directive|include
file|"IP6_misc.h"
end_include

begin_define
define|#
directive|define
name|caddr_t
value|char*
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

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
name|strdup
value|_strdup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

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

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|_UINTPTR_T_DEFINED
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uintptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|_W64
name|unsigned
name|int
name|uintptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_UINTPTR_T_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INTPTR_T_DEFINED
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_typedef
typedef|typedef
name|__int64
name|intptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|_W64
name|int
name|intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_INTPTR_T_DEFINED
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
comment|/*__MINGW32__*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pcap_stdinc_h */
end_comment

end_unit

