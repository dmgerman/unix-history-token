begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INFINIBAND_BYTEORDER_H_
end_ifndef

begin_define
define|#
directive|define
name|_INFINIBAND_BYTEORDER_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|cpu_to_le64
value|htole64
end_define

begin_define
define|#
directive|define
name|le64_to_cpu
value|le64toh
end_define

begin_define
define|#
directive|define
name|cpu_to_le32
value|htole32
end_define

begin_define
define|#
directive|define
name|le32_to_cpu
value|le32toh
end_define

begin_define
define|#
directive|define
name|cpu_to_le16
value|htole16
end_define

begin_define
define|#
directive|define
name|le16_to_cpu
value|le16toh
end_define

begin_define
define|#
directive|define
name|cpu_to_be64
value|htobe64
end_define

begin_define
define|#
directive|define
name|be64_to_cpu
value|be64toh
end_define

begin_define
define|#
directive|define
name|cpu_to_be32
value|htobe32
end_define

begin_define
define|#
directive|define
name|be32_to_cpu
value|be32toh
end_define

begin_define
define|#
directive|define
name|cpu_to_be16
value|htobe16
end_define

begin_define
define|#
directive|define
name|be16_to_cpu
value|be16toh
end_define

begin_define
define|#
directive|define
name|__be16_to_cpu
value|be16toh
end_define

begin_define
define|#
directive|define
name|cpu_to_le64p
parameter_list|(
name|x
parameter_list|)
value|htole64(*((uint64_t *)x))
end_define

begin_define
define|#
directive|define
name|le64_to_cpup
parameter_list|(
name|x
parameter_list|)
value|le64toh(*((uint64_t *)x))
end_define

begin_define
define|#
directive|define
name|cpu_to_le32p
parameter_list|(
name|x
parameter_list|)
value|htole32(*((uint32_t *)x))
end_define

begin_define
define|#
directive|define
name|le32_to_cpup
parameter_list|(
name|x
parameter_list|)
value|le32toh(*((uint32_t *)x))
end_define

begin_define
define|#
directive|define
name|cpu_to_le16p
parameter_list|(
name|x
parameter_list|)
value|htole16(*((uint16_t *)x))
end_define

begin_define
define|#
directive|define
name|le16_to_cpup
parameter_list|(
name|x
parameter_list|)
value|le16toh(*((uint16_t *)x))
end_define

begin_define
define|#
directive|define
name|cpu_to_be64p
parameter_list|(
name|x
parameter_list|)
value|htobe64(*((uint64_t *)x))
end_define

begin_define
define|#
directive|define
name|be64_to_cpup
parameter_list|(
name|x
parameter_list|)
value|be64toh(*((uint64_t *)x))
end_define

begin_define
define|#
directive|define
name|cpu_to_be32p
parameter_list|(
name|x
parameter_list|)
value|htobe32(*((uint32_t *)x))
end_define

begin_define
define|#
directive|define
name|be32_to_cpup
parameter_list|(
name|x
parameter_list|)
value|be32toh(*((uint32_t *)x))
end_define

begin_define
define|#
directive|define
name|cpu_to_be16p
parameter_list|(
name|x
parameter_list|)
value|htobe16(*((uint16_t *)x))
end_define

begin_define
define|#
directive|define
name|be16_to_cpup
parameter_list|(
name|x
parameter_list|)
value|be16toh(*((uint16_t *)x))
end_define

begin_define
define|#
directive|define
name|cpu_to_le64s
parameter_list|(
name|x
parameter_list|)
value|do { *((uint64_t *)x) = cpu_to_le64p((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|le64_to_cpus
parameter_list|(
name|x
parameter_list|)
value|do { *((uint64_t *)x) = le64_to_cpup((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|cpu_to_le32s
parameter_list|(
name|x
parameter_list|)
value|do { *((uint32_t *)x) = cpu_to_le32p((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|le32_to_cpus
parameter_list|(
name|x
parameter_list|)
value|do { *((uint32_t *)x) = le32_to_cpup((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|cpu_to_le16s
parameter_list|(
name|x
parameter_list|)
value|do { *((uint16_t *)x) = cpu_to_le16p((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|le16_to_cpus
parameter_list|(
name|x
parameter_list|)
value|do { *((uint16_t *)x) = le16_to_cpup((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|cpu_to_be64s
parameter_list|(
name|x
parameter_list|)
value|do { *((uint64_t *)x) = cpu_to_be64p((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|be64_to_cpus
parameter_list|(
name|x
parameter_list|)
value|do { *((uint64_t *)x) = be64_to_cpup((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|cpu_to_be32s
parameter_list|(
name|x
parameter_list|)
value|do { *((uint32_t *)x) = cpu_to_be32p((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|be32_to_cpus
parameter_list|(
name|x
parameter_list|)
value|do { *((uint32_t *)x) = be32_to_cpup((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|cpu_to_be16s
parameter_list|(
name|x
parameter_list|)
value|do { *((uint16_t *)x) = cpu_to_be16p((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|be16_to_cpus
parameter_list|(
name|x
parameter_list|)
value|do { *((uint16_t *)x) = be16_to_cpup((x)) } while (0)
end_define

begin_define
define|#
directive|define
name|swab16
value|bswap16
end_define

begin_define
define|#
directive|define
name|swab32
value|bswap32
end_define

begin_define
define|#
directive|define
name|swab64
value|bswap64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INFINIBAND_BYTEORDER_H_ */
end_comment

end_unit

