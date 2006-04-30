begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SAL_H_
end_define

begin_struct
struct|struct
name|sal_system_table
block|{
name|char
name|sal_signature
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|SAL_SIGNATURE
value|"SST_"
name|u_int32_t
name|sal_length
decl_stmt|;
name|u_int8_t
name|sal_rev
index|[
literal|2
index|]
decl_stmt|;
name|u_int16_t
name|sal_entry_count
decl_stmt|;
name|u_int8_t
name|sal_checksum
decl_stmt|;
name|u_int8_t
name|sal_reserved1
index|[
literal|7
index|]
decl_stmt|;
name|u_int8_t
name|sal_a_version
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|sal_b_version
index|[
literal|2
index|]
decl_stmt|;
name|char
name|sal_oem_id
index|[
literal|32
index|]
decl_stmt|;
name|char
name|sal_product_id
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|sal_reserved2
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sal_entrypoint_descriptor
block|{
name|u_int8_t
name|sale_type
decl_stmt|;
comment|/* == 0 */
name|u_int8_t
name|sale_reserved1
index|[
literal|7
index|]
decl_stmt|;
name|u_int64_t
name|sale_pal_proc
decl_stmt|;
name|u_int64_t
name|sale_sal_proc
decl_stmt|;
name|u_int64_t
name|sale_sal_gp
decl_stmt|;
name|u_int8_t
name|sale_reserved2
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sal_memory_descriptor
block|{
name|u_int8_t
name|sale_type
decl_stmt|;
comment|/* == 1 */
name|u_int8_t
name|sale_need_virtual
decl_stmt|;
name|u_int8_t
name|sale_current_attribute
decl_stmt|;
name|u_int8_t
name|sale_access_rights
decl_stmt|;
name|u_int8_t
name|sale_supported_attributes
decl_stmt|;
name|u_int8_t
name|sale_reserved1
decl_stmt|;
name|u_int8_t
name|sale_memory_type
index|[
literal|2
index|]
decl_stmt|;
name|u_int64_t
name|sale_physical_address
decl_stmt|;
name|u_int32_t
name|sale_length
decl_stmt|;
name|u_int8_t
name|sale_reserved2
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sal_platform_descriptor
block|{
name|u_int8_t
name|sale_type
decl_stmt|;
comment|/* == 2 */
name|u_int8_t
name|sale_features
decl_stmt|;
name|u_int8_t
name|sale_reserved
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sal_tr_descriptor
block|{
name|u_int8_t
name|sale_type
decl_stmt|;
comment|/* == 3 */
name|u_int8_t
name|sale_register_type
decl_stmt|;
name|u_int8_t
name|sale_register_number
decl_stmt|;
name|u_int8_t
name|sale_reserved1
index|[
literal|5
index|]
decl_stmt|;
name|u_int64_t
name|sale_virtual_address
decl_stmt|;
name|u_int64_t
name|sale_page_size
decl_stmt|;
name|u_int8_t
name|sale_reserved2
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sal_ptc_cache_descriptor
block|{
name|u_int8_t
name|sale_type
decl_stmt|;
comment|/* == 4 */
name|u_int8_t
name|sale_reserved
index|[
literal|3
index|]
decl_stmt|;
name|u_int32_t
name|sale_domains
decl_stmt|;
name|u_int64_t
name|sale_address
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sal_ap_wakeup_descriptor
block|{
name|u_int8_t
name|sale_type
decl_stmt|;
comment|/* == 5 */
name|u_int8_t
name|sale_mechanism
decl_stmt|;
name|u_int8_t
name|sale_reserved
index|[
literal|6
index|]
decl_stmt|;
name|u_int64_t
name|sale_vector
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SAL Procedure numbers.  */
end_comment

begin_define
define|#
directive|define
name|SAL_SET_VECTORS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SAL_GET_STATE_INFO
value|0x01000001
end_define

begin_define
define|#
directive|define
name|SAL_GET_STATE_INFO_SIZE
value|0x01000002
end_define

begin_define
define|#
directive|define
name|SAL_CLEAR_STATE_INFO
value|0x01000003
end_define

begin_define
define|#
directive|define
name|SAL_MC_RENDEZ
value|0x01000004
end_define

begin_define
define|#
directive|define
name|SAL_MC_SET_PARAMS
value|0x01000005
end_define

begin_define
define|#
directive|define
name|SAL_REGISTER_PHYSICAL_ADDR
value|0x01000006
end_define

begin_define
define|#
directive|define
name|SAL_CACHE_FLUSH
value|0x01000008
end_define

begin_define
define|#
directive|define
name|SAL_CACHE_INIT
value|0x01000009
end_define

begin_define
define|#
directive|define
name|SAL_PCI_CONFIG_READ
value|0x01000010
end_define

begin_define
define|#
directive|define
name|SAL_PCI_CONFIG_WRITE
value|0x01000011
end_define

begin_define
define|#
directive|define
name|SAL_FREQ_BASE
value|0x01000012
end_define

begin_define
define|#
directive|define
name|SAL_UPDATE_PAL
value|0x01000020
end_define

begin_comment
comment|/* SAL_SET_VECTORS event handler types */
end_comment

begin_define
define|#
directive|define
name|SAL_OS_MCA
value|0
end_define

begin_define
define|#
directive|define
name|SAL_OS_INIT
value|1
end_define

begin_define
define|#
directive|define
name|SAL_OS_BOOT_RENDEZ
value|2
end_define

begin_comment
comment|/* SAL_GET_STATE_INFO, SAL_GET_STATE_INFO_SIZE types */
end_comment

begin_define
define|#
directive|define
name|SAL_INFO_MCA
value|0
end_define

begin_define
define|#
directive|define
name|SAL_INFO_INIT
value|1
end_define

begin_define
define|#
directive|define
name|SAL_INFO_CMC
value|2
end_define

begin_define
define|#
directive|define
name|SAL_INFO_CPE
value|3
end_define

begin_define
define|#
directive|define
name|SAL_INFO_TYPES
value|4
end_define

begin_comment
comment|/* number of types we know about */
end_comment

begin_struct
struct|struct
name|ia64_sal_result
block|{
name|int64_t
name|sal_status
decl_stmt|;
name|u_int64_t
name|sal_result
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ia64_sal_result
name|sal_entry_t
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|sal_entry_t
modifier|*
name|ia64_sal_entry
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ia64_sal_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SAL_H_ */
end_comment

end_unit

