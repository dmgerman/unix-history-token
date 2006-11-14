begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/lib/asn1.h,v 1.20 2005/10/05 16:43:11 brandt_h Exp $  *  * ASN.1 for SNMP  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|asn1_h_
end_ifndef

begin_define
define|#
directive|define
name|asn1_h_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|asn_buf
block|{
union|union
block|{
name|u_char
modifier|*
name|ptr
decl_stmt|;
specifier|const
name|u_char
modifier|*
name|cptr
decl_stmt|;
block|}
name|asn_u
union|;
name|size_t
name|asn_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|asn_cptr
value|asn_u.cptr
end_define

begin_define
define|#
directive|define
name|asn_ptr
value|asn_u.ptr
end_define

begin_comment
comment|/* these restrictions are in the SMI */
end_comment

begin_define
define|#
directive|define
name|ASN_MAXID
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|ASN_MAXOIDLEN
value|128
end_define

begin_comment
comment|/* the string needed for this (with trailing zero) */
end_comment

begin_define
define|#
directive|define
name|ASN_OIDSTRLEN
value|(ASN_MAXOIDLEN * (10 + 1) - 1 + 1)
end_define

begin_comment
comment|/* type of subidentifiers */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|asn_subid_t
typedef|;
end_typedef

begin_struct
struct|struct
name|asn_oid
block|{
name|u_int
name|len
decl_stmt|;
name|asn_subid_t
name|subs
index|[
name|ASN_MAXOIDLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|asn_err
block|{
comment|/* conversion was ok */
name|ASN_ERR_OK
init|=
literal|0
block|,
comment|/* conversion failed and stopped */
name|ASN_ERR_FAILED
init|=
literal|1
operator||
literal|0x1000
block|,
comment|/* length field bad, value skipped */
name|ASN_ERR_BADLEN
init|=
literal|2
block|,
comment|/* out of buffer, stopped */
name|ASN_ERR_EOBUF
init|=
literal|3
operator||
literal|0x1000
block|,
comment|/* length ok, but value is out of range */
name|ASN_ERR_RANGE
init|=
literal|4
block|,
comment|/* not the expected tag, stopped */
name|ASN_ERR_TAG
init|=
literal|5
operator||
literal|0x1000
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|ASN_ERR_STOPPED
parameter_list|(
name|E
parameter_list|)
value|(((E)& 0x1000) != 0)
end_define

begin_comment
comment|/* type for the length field of encoded values. The length is restricted  * to 65535, but using uint16_t would give conversion warnings on gcc */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|asn_len_t
typedef|;
end_typedef

begin_comment
comment|/* could be also uint16_t */
end_comment

begin_comment
comment|/* maximal length of a long length field without the length of the length */
end_comment

begin_define
define|#
directive|define
name|ASN_MAXLEN
value|65535
end_define

begin_define
define|#
directive|define
name|ASN_MAXLENLEN
value|2
end_define

begin_comment
comment|/* number of bytes in a length */
end_comment

begin_comment
comment|/* maximum size of an octet string as per SMIv2 */
end_comment

begin_define
define|#
directive|define
name|ASN_MAXOCTETSTRING
value|65535
end_define

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|asn_error
function_decl|)
parameter_list|(
specifier|const
name|struct
name|asn_buf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_header
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|asn_len_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_header
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|u_char
parameter_list|,
name|asn_len_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_temp_header
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|u_char
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_commit_header
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_integer_raw
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|asn_len_t
parameter_list|,
name|int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_integer
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_integer
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_octetstring_raw
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|asn_len_t
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_octetstring
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_octetstring
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_null_raw
parameter_list|(
name|struct
name|asn_buf
modifier|*
name|b
parameter_list|,
name|asn_len_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_null
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_null
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_exception
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_objid_raw
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|asn_len_t
parameter_list|,
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_objid
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_objid
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_sequence
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|asn_len_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_ipaddress_raw
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|asn_len_t
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_ipaddress
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_ipaddress
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_uint32_raw
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|asn_len_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_uint32
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|u_char
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_counter64_raw
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|asn_len_t
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_counter64
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_get_timeticks
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_put_timeticks
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|asn_skip
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|asn_len_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Utility functions for OIDs  */
end_comment

begin_comment
comment|/* get a sub-OID from the middle of another OID */
end_comment

begin_function_decl
name|void
name|asn_slice_oid
parameter_list|(
name|struct
name|asn_oid
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* append an OID to another one */
end_comment

begin_function_decl
name|void
name|asn_append_oid
parameter_list|(
name|struct
name|asn_oid
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* compare two OIDs */
end_comment

begin_function_decl
name|int
name|asn_compare_oid
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check whether the first is a suboid of the second one */
end_comment

begin_function_decl
name|int
name|asn_is_suboid
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* format an OID into a user buffer of size ASN_OIDSTRLEN */
end_comment

begin_function_decl
name|char
modifier|*
name|asn_oid2str_r
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* format an OID into a private static buffer */
end_comment

begin_function_decl
name|char
modifier|*
name|asn_oid2str
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|ASN_TYPE_BOOLEAN
init|=
literal|0x01
block|,
name|ASN_TYPE_INTEGER
init|=
literal|0x02
block|,
name|ASN_TYPE_BITSTRING
init|=
literal|0x03
block|,
name|ASN_TYPE_OCTETSTRING
init|=
literal|0x04
block|,
name|ASN_TYPE_NULL
init|=
literal|0x05
block|,
name|ASN_TYPE_OBJID
init|=
literal|0x06
block|,
name|ASN_TYPE_SEQUENCE
init|=
literal|0x10
block|,
name|ASN_TYPE_CONSTRUCTED
init|=
literal|0x20
block|,
name|ASN_CLASS_UNIVERSAL
init|=
literal|0x00
block|,
name|ASN_CLASS_APPLICATION
init|=
literal|0x40
block|,
name|ASN_CLASS_CONTEXT
init|=
literal|0x80
block|,
name|ASN_CLASS_PRIVATE
init|=
literal|0xc0
block|,
name|ASN_TYPE_MASK
init|=
literal|0x1f
block|,
name|ASN_APP_IPADDRESS
init|=
literal|0x00
block|,
name|ASN_APP_COUNTER
init|=
literal|0x01
block|,
name|ASN_APP_GAUGE
init|=
literal|0x02
block|,
name|ASN_APP_TIMETICKS
init|=
literal|0x03
block|,
name|ASN_APP_OPAQUE
init|=
literal|0x04
block|,
comment|/* not implemented */
name|ASN_APP_COUNTER64
init|=
literal|0x06
block|,
name|ASN_EXCEPT_NOSUCHOBJECT
init|=
literal|0x00
block|,
name|ASN_EXCEPT_NOSUCHINSTANCE
init|=
literal|0x01
block|,
name|ASN_EXCEPT_ENDOFMIBVIEW
init|=
literal|0x02
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

