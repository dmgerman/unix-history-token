begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIO_RSS_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIO_RSS_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RSS
end_ifdef

begin_include
include|#
directive|include
file|<net/rss_config.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_rss.h>
end_include

begin_define
define|#
directive|define
name|LIO_RSS_TABLE_SZ
value|128
end_define

begin_define
define|#
directive|define
name|LIO_RSS_KEY_SZ
value|40
end_define

begin_struct
struct|struct
name|lio_rss_params
block|{
define|#
directive|define
name|LIO_RSS_PARAM_SIZE
value|16
struct|struct
name|param
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|uint64_t
name|flags
range|:
literal|16
decl_stmt|;
name|uint64_t
name|hashinfo
range|:
literal|32
decl_stmt|;
name|uint64_t
name|itablesize
range|:
literal|16
decl_stmt|;
name|uint64_t
name|hashkeysize
range|:
literal|16
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|48
decl_stmt|;
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|itablesize
range|:
literal|16
decl_stmt|;
name|uint64_t
name|hashinfo
range|:
literal|32
decl_stmt|;
name|uint64_t
name|flags
range|:
literal|16
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|48
decl_stmt|;
name|uint64_t
name|hashkeysize
range|:
literal|16
decl_stmt|;
else|#
directive|else
error|#
directive|error
error|Undefined BYTE_ORDER
endif|#
directive|endif
block|}
name|param
struct|;
name|uint8_t
name|itable
index|[
name|LIO_RSS_TABLE_SZ
index|]
decl_stmt|;
name|uint8_t
name|key
index|[
name|LIO_RSS_KEY_SZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_rss_params_set
block|{
name|uint8_t
name|key
index|[
name|LIO_RSS_KEY_SZ
index|]
decl_stmt|;
name|uint8_t
name|fw_itable
index|[
name|LIO_RSS_TABLE_SZ
index|]
decl_stmt|;
name|uint64_t
name|hashinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSS */
end_comment

begin_define
define|#
directive|define
name|LIO_RSS_HASH_IPV4
value|0x100
end_define

begin_define
define|#
directive|define
name|LIO_RSS_HASH_TCP_IPV4
value|0x200
end_define

begin_define
define|#
directive|define
name|LIO_RSS_HASH_IPV6
value|0x400
end_define

begin_define
define|#
directive|define
name|LIO_RSS_HASH_IPV6_EX
value|0x800
end_define

begin_define
define|#
directive|define
name|LIO_RSS_HASH_TCP_IPV6
value|0x1000
end_define

begin_define
define|#
directive|define
name|LIO_RSS_HASH_TCP_IPV6_EX
value|0x2000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIO_RSS_H__ */
end_comment

end_unit

