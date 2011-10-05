begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2006 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* asn1 templates */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TEMPLATE_H__
end_ifndef

begin_define
define|#
directive|define
name|__TEMPLATE_H__
end_define

begin_comment
comment|/* tag:  *  0..20 tag  * 21     type  * 22..23 class  * 24..27 flags  * 28..31 op  */
end_comment

begin_comment
comment|/* parse:  *  0..11 type  * 12..23 unused  * 24..27 flags  * 28..31 op  */
end_comment

begin_define
define|#
directive|define
name|A1_OP_MASK
value|(0xf0000000)
end_define

begin_define
define|#
directive|define
name|A1_OP_TYPE
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|A1_OP_TYPE_EXTERN
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|A1_OP_TAG
value|(0x30000000)
end_define

begin_define
define|#
directive|define
name|A1_OP_PARSE
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|A1_OP_SEQOF
value|(0x50000000)
end_define

begin_define
define|#
directive|define
name|A1_OP_SETOF
value|(0x60000000)
end_define

begin_define
define|#
directive|define
name|A1_OP_BMEMBER
value|(0x70000000)
end_define

begin_define
define|#
directive|define
name|A1_OP_CHOICE
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|A1_FLAG_MASK
value|(0x0f000000)
end_define

begin_define
define|#
directive|define
name|A1_FLAG_OPTIONAL
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|A1_FLAG_IMPLICIT
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|A1_TAG_T
parameter_list|(
name|CLASS
parameter_list|,
name|TYPE
parameter_list|,
name|TAG
parameter_list|)
value|((A1_OP_TAG) | (((CLASS)<< 22) | ((TYPE)<< 21) | (TAG)))
end_define

begin_define
define|#
directive|define
name|A1_TAG_CLASS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x3)
end_define

begin_define
define|#
directive|define
name|A1_TAG_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|A1_TAG_TAG
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1fffff)
end_define

begin_define
define|#
directive|define
name|A1_TAG_LEN
parameter_list|(
name|t
parameter_list|)
value|((uintptr_t)(t)->ptr)
end_define

begin_define
define|#
directive|define
name|A1_HEADER_LEN
parameter_list|(
name|t
parameter_list|)
value|((uintptr_t)(t)->ptr)
end_define

begin_define
define|#
directive|define
name|A1_PARSE_T
parameter_list|(
name|type
parameter_list|)
value|((A1_OP_PARSE) | (type))
end_define

begin_define
define|#
directive|define
name|A1_PARSE_TYPE_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|A1_PARSE_TYPE
parameter_list|(
name|x
parameter_list|)
value|(A1_PARSE_TYPE_MASK& (x))
end_define

begin_define
define|#
directive|define
name|A1_PF_INDEFINTE
value|0x1
end_define

begin_define
define|#
directive|define
name|A1_PF_ALLOW_BER
value|0x2
end_define

begin_define
define|#
directive|define
name|A1_HF_PRESERVE
value|0x1
end_define

begin_define
define|#
directive|define
name|A1_HF_ELLIPSIS
value|0x2
end_define

begin_define
define|#
directive|define
name|A1_HBF_RFC1510
value|0x1
end_define

begin_struct
struct|struct
name|asn1_template
block|{
name|uint32_t
name|tt
decl_stmt|;
name|size_t
name|offset
decl_stmt|;
specifier|const
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|asn1_type_decode
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|asn1_type_encode
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|asn1_type_length
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|asn1_type_release
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|asn1_type_copy
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|asn1_type_func
block|{
name|asn1_type_encode
name|encode
decl_stmt|;
name|asn1_type_decode
name|decode
decl_stmt|;
name|asn1_type_length
name|length
decl_stmt|;
name|asn1_type_copy
name|copy
decl_stmt|;
name|asn1_type_release
name|release
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|template_of
block|{
name|unsigned
name|int
name|len
decl_stmt|;
name|void
modifier|*
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|template_types
block|{
name|A1T_IMEMBER
init|=
literal|0
block|,
name|A1T_HEIM_INTEGER
block|,
name|A1T_INTEGER
block|,
name|A1T_UNSIGNED
block|,
name|A1T_GENERAL_STRING
block|,
name|A1T_OCTET_STRING
block|,
name|A1T_OCTET_STRING_BER
block|,
name|A1T_IA5_STRING
block|,
name|A1T_BMP_STRING
block|,
name|A1T_UNIVERSAL_STRING
block|,
name|A1T_PRINTABLE_STRING
block|,
name|A1T_VISIBLE_STRING
block|,
name|A1T_UTF8_STRING
block|,
name|A1T_GENERALIZED_TIME
block|,
name|A1T_UTC_TIME
block|,
name|A1T_HEIM_BIT_STRING
block|,
name|A1T_BOOLEAN
block|,
name|A1T_OID
block|,
name|A1T_TELETEX_STRING
block|,
name|A1T_NULL
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

