begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INFINIBAND_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_INFINIBAND_TYPES_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|int8_t
name|s8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|__s8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|__u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|__s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|__s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|__s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__le16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__be16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__le32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__le64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__be64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INFINIBAND_TYPES_H_ */
end_comment

end_unit

