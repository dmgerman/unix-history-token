begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2002 Katsushi Kobayashi and Hidetoshi Shimokawa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the acknowledgement as bellow:  *  *    This product includes software developed by K. Kobayashi and H. Shimokawa  *  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|CSRTYPE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CSRTYPE_MASK
value|(3<< CSRTYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CSRTYPE_I
value|(0<< CSRTYPE_SHIFT)
end_define

begin_comment
comment|/* Immediate */
end_comment

begin_define
define|#
directive|define
name|CSRTYPE_C
value|(1<< CSRTYPE_SHIFT)
end_define

begin_comment
comment|/* CSR offset */
end_comment

begin_define
define|#
directive|define
name|CSRTYPE_L
value|(2<< CSRTYPE_SHIFT)
end_define

begin_comment
comment|/* Leaf */
end_comment

begin_define
define|#
directive|define
name|CSRTYPE_D
value|(3<< CSRTYPE_SHIFT)
end_define

begin_comment
comment|/* Directory */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|CSRKEY_DESC
value|0x01
end_define

begin_comment
comment|/* Descriptor */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_BDINFO
value|0x02
end_define

begin_comment
comment|/* Bus_Dependent_Info */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_VENDOR
value|0x03
end_define

begin_comment
comment|/* Vendor */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_HW
value|0x04
end_define

begin_comment
comment|/* Hardware_Version */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_MODULE
value|0x07
end_define

begin_comment
comment|/* Module */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_NCAP
value|0x0c
end_define

begin_comment
comment|/* Node_Capabilities */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_EUI64
value|0x0d
end_define

begin_comment
comment|/* EUI_64 */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_UNIT
value|0x11
end_define

begin_comment
comment|/* Unit */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_SPEC
value|0x12
end_define

begin_comment
comment|/* Specifier_ID */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_VER
value|0x13
end_define

begin_comment
comment|/* Version */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_DINFO
value|0x14
end_define

begin_comment
comment|/* Dependent_Info */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_ULOC
value|0x15
end_define

begin_comment
comment|/* Unit_Location */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_MODEL
value|0x17
end_define

begin_comment
comment|/* Model */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_INST
value|0x18
end_define

begin_comment
comment|/* Instance */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_KEYW
value|0x19
end_define

begin_comment
comment|/* Keyword */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_FEAT
value|0x1a
end_define

begin_comment
comment|/* Feature */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_EROM
value|0x1b
end_define

begin_comment
comment|/* Extended_ROM */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_EKSID
value|0x1c
end_define

begin_comment
comment|/* Extended_Key_Specifier_ID */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_EKEY
value|0x1d
end_define

begin_comment
comment|/* Extended_Key */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_EDATA
value|0x1e
end_define

begin_comment
comment|/* Extended_Data */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_MDESC
value|0x1f
end_define

begin_comment
comment|/* Modifiable_Descriptor */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_DID
value|0x20
end_define

begin_comment
comment|/* Directory_ID */
end_comment

begin_define
define|#
directive|define
name|CSRKEY_REV
value|0x21
end_define

begin_comment
comment|/* Revision */
end_comment

begin_define
define|#
directive|define
name|CROM_TEXTLEAF
value|(CSRTYPE_L | CSRKEY_DESC)
end_define

begin_comment
comment|/* 0x81 */
end_comment

begin_define
define|#
directive|define
name|CROM_LUN
value|(CSRTYPE_I | CSRKEY_DINFO)
end_define

begin_comment
comment|/* 0x14 */
end_comment

begin_comment
comment|/* ??? #define CSRKEY_MVID	0x3 #define CSRKEY_NUNQ	0x8d #define CSRKEY_NPWR	0x30 */
end_comment

begin_define
define|#
directive|define
name|CSRVAL_1394TA
value|0x00a02d
end_define

begin_define
define|#
directive|define
name|CSRVAL_ANSIT10
value|0x00609e
end_define

begin_define
define|#
directive|define
name|CSR_PROTAVC
value|0x010001
end_define

begin_define
define|#
directive|define
name|CSR_PROTCAL
value|0x010002
end_define

begin_define
define|#
directive|define
name|CSR_PROTEHS
value|0x010004
end_define

begin_define
define|#
directive|define
name|CSR_PROTHAVI
value|0x010008
end_define

begin_define
define|#
directive|define
name|CSR_PROTCAM104
value|0x000100
end_define

begin_define
define|#
directive|define
name|CSR_PROTCAM120
value|0x000101
end_define

begin_define
define|#
directive|define
name|CSR_PROTCAM130
value|0x000102
end_define

begin_define
define|#
directive|define
name|CSR_PROTDPP
value|0x0a6be2
end_define

begin_define
define|#
directive|define
name|CSR_PROTIICP
value|0x4b661f
end_define

begin_define
define|#
directive|define
name|CSRVAL_T10SBP2
value|0x010483
end_define

begin_struct
struct|struct
name|csrreg
block|{
name|u_int32_t
name|val
range|:
literal|24
decl_stmt|,
name|key
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|csrhdr
block|{
name|u_int32_t
name|crc
range|:
literal|16
decl_stmt|,
name|crc_len
range|:
literal|8
decl_stmt|,
name|info_len
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|csrdirectory
block|{
name|u_int32_t
name|crc
range|:
literal|16
decl_stmt|,
name|crc_len
range|:
literal|16
decl_stmt|;
name|struct
name|csrreg
name|entry
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|csrtext
block|{
name|u_int32_t
name|crc
range|:
literal|16
decl_stmt|,
name|crc_len
range|:
literal|16
decl_stmt|;
name|u_int32_t
name|spec_id
range|:
literal|24
decl_stmt|,
name|spec_type
range|:
literal|8
decl_stmt|;
name|u_int32_t
name|lang_id
decl_stmt|;
name|u_int32_t
name|text
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|businfo
block|{
name|u_int32_t
name|crc
range|:
literal|16
decl_stmt|,
name|crc_len
range|:
literal|8
decl_stmt|,
range|:
literal|12
decl_stmt|,
name|max_rec
range|:
literal|4
decl_stmt|,
name|clk_acc
range|:
literal|8
decl_stmt|,
range|:
literal|4
decl_stmt|,
name|bmc
range|:
literal|1
decl_stmt|,
name|isc
range|:
literal|1
decl_stmt|,
name|cmc
range|:
literal|1
decl_stmt|,
name|irmc
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|c_id_hi
range|:
literal|8
decl_stmt|,
name|v_id
range|:
literal|24
decl_stmt|;
name|u_int32_t
name|c_id_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CROM_MAX_DEPTH
value|10
end_define

begin_struct
struct|struct
name|crom_ptr
block|{
name|struct
name|csrdirectory
modifier|*
name|dir
decl_stmt|;
name|int
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|crom_context
block|{
name|int
name|depth
decl_stmt|;
name|struct
name|crom_ptr
name|stack
index|[
name|CROM_MAX_DEPTH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|crom_init_context
parameter_list|(
name|struct
name|crom_context
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|csrreg
modifier|*
name|crom_get
parameter_list|(
name|struct
name|crom_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|crom_next
parameter_list|(
name|struct
name|crom_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|crom_parse_text
parameter_list|(
name|struct
name|crom_context
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|crom_crc
parameter_list|(
name|u_int32_t
modifier|*
name|r
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|csrreg
modifier|*
name|crom_search_key
parameter_list|(
name|struct
name|crom_context
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|char
modifier|*
name|crom_desc
parameter_list|(
name|struct
name|crom_context
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

