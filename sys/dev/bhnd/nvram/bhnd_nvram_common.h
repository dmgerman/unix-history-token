begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_COMMON_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram.h"
end_include

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_tuple
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_varmap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhnd_nvram_vardefn
struct_decl|;
end_struct_decl

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_BHND_NVRAM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint8_t
name|bhnd_nvram_crc8_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BHND_NVRAM_CRC8_INITIAL
value|0xFF
end_define

begin_comment
comment|/**< Initial bhnd_nvram_crc8 value */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_CRC8_VALID
value|0x9F
end_define

begin_comment
comment|/**< Valid CRC-8 checksum */
end_comment

begin_define
define|#
directive|define
name|BHND_SPROMREV_MAX
value|UINT8_MAX
end_define

begin_comment
comment|/**< maximum supported SPROM revision */
end_comment

begin_comment
comment|/** NVRAM data type string representations */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_NVRAM_SFMT_HEX
init|=
literal|1
block|,
comment|/**< hex format */
name|BHND_NVRAM_SFMT_DEC
init|=
literal|2
block|,
comment|/**< decimal format */
name|BHND_NVRAM_SFMT_MACADDR
init|=
literal|3
block|,
comment|/**< mac address (canonical form, hex octets, 					     separated with ':') */
name|BHND_NVRAM_SFMT_LEDDC
init|=
literal|4
block|,
comment|/**< LED PWM duty-cycle (2 bytes -- on/off) */
name|BHND_NVRAM_SFMT_CCODE
init|=
literal|5
comment|/**< count code format (2-3 ASCII chars, or hex string) */
block|}
name|bhnd_nvram_sfmt
typedef|;
end_typedef

begin_function_decl
name|size_t
name|bhnd_nvram_type_width
parameter_list|(
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_nvram_type_fmt
parameter_list|(
name|bhnd_nvram_type
name|type
parameter_list|,
name|bhnd_nvram_sfmt
name|sfmt
parameter_list|,
name|size_t
name|elem_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhnd_nvram_vardefn
modifier|*
name|bhnd_nvram_find_vardefn
parameter_list|(
specifier|const
name|char
modifier|*
name|varname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_nvram_validate_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|name_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_parse_octet_string
parameter_list|(
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|size_t
name|value_len
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_varmap_init
parameter_list|(
name|struct
name|bhnd_nvram_varmap
modifier|*
name|map
parameter_list|,
name|size_t
name|nelements
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvram_varmap_free
parameter_list|(
name|struct
name|bhnd_nvram_varmap
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_varmap_add
parameter_list|(
name|struct
name|bhnd_nvram_varmap
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|size_t
name|value_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_varmap_remove
parameter_list|(
name|struct
name|bhnd_nvram_varmap
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_nvram_tuple
modifier|*
name|bhnd_nvram_varmap_find
parameter_list|(
name|struct
name|bhnd_nvram_varmap
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|name_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_nvram_varmap_contains
parameter_list|(
name|struct
name|bhnd_nvram_varmap
modifier|*
name|map
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|name_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_nvram_tuple
modifier|*
name|bhnd_nvram_tuple_alloc
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvram_tuple_free
parameter_list|(
name|struct
name|bhnd_nvram_tuple
modifier|*
name|tuple
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** NVRAM variable flags */
end_comment

begin_enum
enum|enum
block|{
name|BHND_NVRAM_VF_ARRAY
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/**< variable is an array */
name|BHND_NVRAM_VF_MFGINT
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/**< mfg-internal variable; should not be externally visible */
name|BHND_NVRAM_VF_IGNALL1
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
comment|/**< hide variable if its value has all bits set. */
block|}
enum|;
end_enum

begin_comment
comment|/** SPROM revision compatibility declaration */
end_comment

begin_struct
struct|struct
name|bhnd_sprom_compat
block|{
name|uint8_t
name|first
decl_stmt|;
comment|/**< first compatible SPROM revision */
name|uint8_t
name|last
decl_stmt|;
comment|/**< last compatible SPROM revision, or BHND_SPROMREV_MAX */
block|}
struct|;
end_struct

begin_comment
comment|/** SPROM value descriptor */
end_comment

begin_struct
struct|struct
name|bhnd_sprom_offset
block|{
name|uint16_t
name|offset
decl_stmt|;
comment|/**< byte offset within SPROM */
name|bool
name|cont
range|:
literal|1
decl_stmt|;
comment|/**< value should be bitwise OR'd with the 				  *  previous offset descriptor */
name|bhnd_nvram_type
name|type
range|:
literal|7
decl_stmt|;
comment|/**< data type */
name|int8_t
name|shift
decl_stmt|;
comment|/**< shift to be applied to the value */
name|uint32_t
name|mask
decl_stmt|;
comment|/**< mask to be applied to the value(s) */
block|}
struct|;
end_struct

begin_comment
comment|/** SPROM-specific variable definition */
end_comment

begin_struct
struct|struct
name|bhnd_sprom_vardefn
block|{
name|struct
name|bhnd_sprom_compat
name|compat
decl_stmt|;
comment|/**< sprom compatibility declaration */
specifier|const
name|struct
name|bhnd_sprom_offset
modifier|*
name|offsets
decl_stmt|;
comment|/**< offset descriptors */
name|size_t
name|num_offsets
decl_stmt|;
comment|/**< number of offset descriptors */
block|}
struct|;
end_struct

begin_comment
comment|/** NVRAM variable definition */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_vardefn
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< variable name */
name|bhnd_nvram_type
name|type
decl_stmt|;
comment|/**< base data type */
name|bhnd_nvram_sfmt
name|sfmt
decl_stmt|;
comment|/**< string format */
name|uint32_t
name|flags
decl_stmt|;
comment|/**< BHND_NVRAM_VF_* flags */
specifier|const
name|struct
name|bhnd_sprom_vardefn
modifier|*
name|sp_defs
decl_stmt|;
comment|/**< SPROM-specific variable definitions */
name|size_t
name|num_sp_defs
decl_stmt|;
comment|/**< number of sprom definitions */
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM value tuple.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_tuple
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< variable name. */
name|size_t
name|name_len
decl_stmt|;
comment|/**< variable length. */
name|char
modifier|*
name|value
decl_stmt|;
comment|/**< value, or NULL if this tuple represents variable 				     deletion */
name|size_t
name|value_len
decl_stmt|;
comment|/**< value length. */
name|LIST_ENTRY
argument_list|(
argument|bhnd_nvram_tuple
argument_list|)
name|t_link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bhnd_nvram_tuples
argument_list|,
name|bhnd_nvram_tuple
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/** NVRAM tuple hash table */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_varmap
block|{
name|struct
name|bhnd_nvram_tuples
modifier|*
name|table
decl_stmt|;
comment|/**< hash buckets */
name|u_long
name|mask
decl_stmt|;
comment|/**< hash index mask */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Calculate CRC-8 over @p buf.  *   * @param buf input buffer  * @param size buffer size  * @param crc last computed crc, or BHND_NVRAM_CRC8_INITIAL  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|bhnd_nvram_crc8
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint8_t
name|crc
parameter_list|)
block|{
specifier|const
name|uint8_t
modifier|*
name|p
init|=
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
name|buf
decl_stmt|;
while|while
condition|(
name|size
operator|--
condition|)
name|crc
operator|=
name|bhnd_nvram_crc8_tab
index|[
operator|(
name|crc
operator|^
operator|*
name|p
operator|++
operator|)
index|]
expr_stmt|;
return|return
operator|(
name|crc
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_COMMON_H_ */
end_comment

end_unit

