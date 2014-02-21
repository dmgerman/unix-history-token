begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 David E. O'Brien<obrien@FreeBSD.org>  * Copyright (c) 2001 Mike Barcroft<mike@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__STDINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__STDINT_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_INT8_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__int8_t
name|int8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INT8_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INT16_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__int16_t
name|int16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INT16_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INT32_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__int32_t
name|int32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INT32_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INT64_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__int64_t
name|int64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INT64_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT8_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint8_t
name|uint8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT8_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|_UINT64_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint64_t
name|uint64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT64_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INTPTR_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__intptr_t
name|intptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INTPTR_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINTPTR_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uintptr_t
name|uintptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINTPTR_T_DECLARED
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
comment|/* !_SYS__STDINT_H_ */
end_comment

end_unit

