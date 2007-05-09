begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_OSL_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|TW_OSL_TYPES_H
end_define

begin_comment
comment|/*  * typedefs shared between OSL and CL, and defined by OSL.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|TW_VOID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|TW_INT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|TW_UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|TW_INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|TW_UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|TW_INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|TW_UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|TW_INT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|TW_UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|time_t
name|TW_TIME
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mtx
name|TW_LOCK_HANDLE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_TYPES_H */
end_comment

end_unit

