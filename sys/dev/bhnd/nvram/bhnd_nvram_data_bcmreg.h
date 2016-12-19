begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_BCMREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_BCMREG_H_
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_GET_BITS
parameter_list|(
name|_value
parameter_list|,
name|_field
parameter_list|)
define|\
value|((_value& _field ## _MASK)>> _field ## _SHIFT)
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_SET_BITS
parameter_list|(
name|_value
parameter_list|,
name|_field
parameter_list|,
name|_bits
parameter_list|)
define|\
value|((_value& ~(_field ## _MASK)) |			\ 	    (((_bits)<< _field ## _SHIFT)& _field ## _MASK))
end_define

begin_comment
comment|/* BCM NVRAM header fields */
end_comment

begin_define
define|#
directive|define
name|BCM_NVRAM_MAGIC
value|0x48534C46
end_define

begin_comment
comment|/* 'FLSH' */
end_comment

begin_define
define|#
directive|define
name|BCM_NVRAM_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CRC_SKIP
value|9
end_define

begin_comment
comment|/* skip magic, size, and crc8 */
end_comment

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_CRC_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_CRC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_VER_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_VER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_VER_DEFAULT
value|1
end_define

begin_comment
comment|/* default version */
end_comment

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_SDRAM_INIT_FIELD
value|cfg0
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_SDRAM_INIT_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_SDRAM_INIT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_SDRAM_INIT_VAR
value|"sdram_init"
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG0_SDRAM_INIT_FMT
value|"0x%04x"
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_CFG_FIELD
value|cfg1
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_CFG_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_CFG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_CFG_VAR
value|"sdram_config"
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_CFG_FMT
value|"0x%04x"
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_REFRESH_FIELD
value|cfg1
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_REFRESH_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_REFRESH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_REFRESH_VAR
value|"sdram_refresh"
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_CFG1_SDRAM_REFRESH_FMT
value|"0x%04x"
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_SDRAM_NCDL_FIELD
value|sdram_ncdl
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_SDRAM_NCDL_MASK
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_SDRAM_NCDL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_SDRAM_NCDL_VAR
value|"sdram_ncdl"
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_SDRAM_NCDL_FMT
value|"0x%08x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_BCMREG_H_ */
end_comment

end_unit

