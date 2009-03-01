begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ASN.1 DER parsing  * Copyright (c) 2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASN1_H
end_ifndef

begin_define
define|#
directive|define
name|ASN1_H
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_EOC
value|0x00
end_define

begin_comment
comment|/* not used with DER */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_BOOLEAN
value|0x01
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_INTEGER
value|0x02
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_BITSTRING
value|0x03
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_OCTETSTRING
value|0x04
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_NULL
value|0x05
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_OID
value|0x06
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_OBJECT_DESCRIPTOR
value|0x07
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_EXTERNAL
value|0x08
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_REAL
value|0x09
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_ENUMERATED
value|0x0A
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_UTF8STRING
value|0x0C
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ANS1_TAG_RELATIVE_OID
value|0x0D
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_SEQUENCE
value|0x10
end_define

begin_comment
comment|/* shall be constructed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_SET
value|0x11
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_NUMERICSTRING
value|0x12
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_PRINTABLESTRING
value|0x13
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_TG1STRING
value|0x14
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_VIDEOTEXSTRING
value|0x15
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_IA5STRING
value|0x16
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_UTCTIME
value|0x17
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_GENERALIZEDTIME
value|0x18
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_GRAPHICSTRING
value|0x19
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_VISIBLESTRING
value|0x1A
end_define

begin_define
define|#
directive|define
name|ASN1_TAG_GENERALSTRING
value|0x1B
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_UNIVERSALSTRING
value|0x1C
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAG_BMPSTRING
value|0x1D
end_define

begin_comment
comment|/* not yet parsed */
end_comment

begin_define
define|#
directive|define
name|ASN1_CLASS_UNIVERSAL
value|0
end_define

begin_define
define|#
directive|define
name|ASN1_CLASS_APPLICATION
value|1
end_define

begin_define
define|#
directive|define
name|ASN1_CLASS_CONTEXT_SPECIFIC
value|2
end_define

begin_define
define|#
directive|define
name|ASN1_CLASS_PRIVATE
value|3
end_define

begin_struct
struct|struct
name|asn1_hdr
block|{
specifier|const
name|u8
modifier|*
name|payload
decl_stmt|;
name|u8
name|identifier
decl_stmt|,
name|class
decl_stmt|,
name|constructed
decl_stmt|;
name|unsigned
name|int
name|tag
decl_stmt|,
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ASN1_MAX_OID_LEN
value|20
end_define

begin_struct
struct|struct
name|asn1_oid
block|{
name|unsigned
name|long
name|oid
index|[
name|ASN1_MAX_OID_LEN
index|]
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|asn1_get_next
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|struct
name|asn1_hdr
modifier|*
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|asn1_get_oid
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|struct
name|asn1_oid
modifier|*
name|oid
parameter_list|,
specifier|const
name|u8
modifier|*
modifier|*
name|next
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|asn1_oid_to_str
parameter_list|(
name|struct
name|asn1_oid
modifier|*
name|oid
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|asn1_bit_string_to_long
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASN1_H */
end_comment

end_unit

