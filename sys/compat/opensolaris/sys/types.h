begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_TYPES_H_
end_define

begin_comment
comment|/*  * This is a bag of dirty hacks to keep things compiling.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_empty
empty|#include_next<sys/types.h>
end_empty

begin_define
define|#
directive|define
name|MAXNAMELEN
value|256
end_define

begin_typedef
typedef|typedef
name|struct
name|timespec
name|timestruc_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|B_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|B_TRUE
value|1
end_define

begin_typedef
typedef|typedef
name|short
name|index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|off_t
name|offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ptrdiff_t
typedef|;
end_typedef

begin_comment
comment|/* pointer difference */
end_comment

begin_typedef
typedef|typedef
name|void
name|pathname_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|longlong_t
name|offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_longlong_t
name|u_offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|upad64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|timespec
name|timespec_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|pri_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|daddr32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|time32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_longlong_t
name|diskaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ushort_t
name|o_mode_t
typedef|;
end_typedef

begin_comment
comment|/* old file attribute type */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_SYS_TYPES_H_ */
end_comment

end_unit

