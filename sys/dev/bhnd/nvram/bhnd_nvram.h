begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/**  * NVRAM data sources supported by bhnd(4) devices.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_NVRAM_SRC_OTP
block|,
comment|/**< On-chip one-time-programmable 				  *  memory. */
name|BHND_NVRAM_SRC_FLASH
block|,
comment|/**< External flash */
name|BHND_NVRAM_SRC_SPROM
block|,
comment|/**< External serial EEPROM. */
name|BHND_NVRAM_SRC_UNKNOWN
comment|/**< No NVRAM source is directly 				  *  attached. 				  * 				  *  This will be returned by ChipCommon 				  *  revisions (rev<= 31) used in early 				  *  chipsets that vend SPROM/OTP via the 				  *  native host bridge interface. 				  * 				  *  For example, PCMCIA cards may vend 				  *  Broadcom NVRAM data via their standard CIS 				  *  table, and earlier PCI(e) devices map 				  *  SPROM statically into PCI BARs, and the 				  *  control registers into PCI config space. 				   				  *  This will also be returned on later 				  *  devices that are attached via PCI(e) to 				  *  BHND SoCs, but do not include an attached 				  *  SPROM, or programmed OTP. On such SoCs, 				  *  NVRAM configuration for individual devices 				  *  is provided by a common platform NVRAM 				  *  device. 				  */
block|}
name|bhnd_nvram_src
typedef|;
end_typedef

begin_comment
comment|/**  * NVRAM data types.  *   * @internal  *   * All primitive (non-array) constants should be representable as a 4-bit  * integer (e.g. 0-15) to support SPROM_OPCODE_TYPE_IMM encoding as used by  * nvram_map_gen.awk.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_NVRAM_TYPE_UINT8
init|=
literal|0
block|,
comment|/**< unsigned 8-bit integer */
name|BHND_NVRAM_TYPE_UINT16
init|=
literal|1
block|,
comment|/**< unsigned 16-bit integer */
name|BHND_NVRAM_TYPE_UINT32
init|=
literal|2
block|,
comment|/**< unsigned 32-bit integer */
name|BHND_NVRAM_TYPE_UINT64
init|=
literal|3
block|,
comment|/**< signed 64-bit integer */
name|BHND_NVRAM_TYPE_INT8
init|=
literal|4
block|,
comment|/**< signed 8-bit integer */
name|BHND_NVRAM_TYPE_INT16
init|=
literal|5
block|,
comment|/**< signed 16-bit integer */
name|BHND_NVRAM_TYPE_INT32
init|=
literal|6
block|,
comment|/**< signed 32-bit integer */
name|BHND_NVRAM_TYPE_INT64
init|=
literal|7
block|,
comment|/**< signed 64-bit integer */
name|BHND_NVRAM_TYPE_CHAR
init|=
literal|8
block|,
comment|/**< ASCII/UTF-8 character */
name|BHND_NVRAM_TYPE_STRING
init|=
literal|9
block|,
comment|/**< ASCII/UTF-8 NUL-terminated 						     string */
comment|/* 10-15 reserved for primitive (non-array) types */
name|BHND_NVRAM_TYPE_UINT8_ARRAY
init|=
literal|16
block|,
comment|/**< array of uint8 integers */
name|BHND_NVRAM_TYPE_UINT16_ARRAY
init|=
literal|17
block|,
comment|/**< array of uint16 integers */
name|BHND_NVRAM_TYPE_UINT32_ARRAY
init|=
literal|18
block|,
comment|/**< array of uint32 integers */
name|BHND_NVRAM_TYPE_UINT64_ARRAY
init|=
literal|19
block|,
comment|/**< array of uint64 integers */
name|BHND_NVRAM_TYPE_INT8_ARRAY
init|=
literal|20
block|,
comment|/**< array of int8 integers */
name|BHND_NVRAM_TYPE_INT16_ARRAY
init|=
literal|21
block|,
comment|/**< array of int16 integers */
name|BHND_NVRAM_TYPE_INT32_ARRAY
init|=
literal|22
block|,
comment|/**< array of int32 integers */
name|BHND_NVRAM_TYPE_INT64_ARRAY
init|=
literal|23
block|,
comment|/**< array of int64 integers */
name|BHND_NVRAM_TYPE_CHAR_ARRAY
init|=
literal|24
block|,
comment|/**< array of ASCII/UTF-8 						     characters */
name|BHND_NVRAM_TYPE_STRING_ARRAY
init|=
literal|25
block|,
comment|/**< array of ASCII/UTF-8 						     NUL-terminated strings */
block|}
name|bhnd_nvram_type
typedef|;
end_typedef

begin_function_decl
name|bool
name|bhnd_nvram_is_signed_type
parameter_list|(
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_nvram_is_unsigned_type
parameter_list|(
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_nvram_is_int_type
parameter_list|(
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_nvram_is_array_type
parameter_list|(
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvram_type
name|bhnd_nvram_base_type
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
name|bhnd_nvram_type_name
parameter_list|(
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

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
name|size_t
name|bhnd_nvram_type_host_align
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
name|bhnd_nvram_string_array_next
parameter_list|(
specifier|const
name|char
modifier|*
name|inp
parameter_list|,
name|size_t
name|ilen
parameter_list|,
specifier|const
name|char
modifier|*
name|prev
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_H_ */
end_comment

end_unit

