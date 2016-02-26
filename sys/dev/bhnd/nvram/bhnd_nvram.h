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

begin_comment
comment|/**  * NVRAM data sources supported by bhnd(4) devices.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_NVRAM_SRC_CIS
block|,
comment|/**< Default CIS source; this may 				  *  apply, for example, to PCMCIA cards 				  *  vending Broadcom NVRAM data via 				  *  their standard CIS table. */
name|BHND_NVRAM_SRC_OTP
block|,
comment|/**< On-chip one-time-programmable 				  *  memory. */
name|BHND_NVRAM_SRC_NFLASH
block|,
comment|/**< External flash device accessible 				  *  via on-chip flash core, such 				  *  as the NAND/QSPI controller cores 				  *  used on Northstar devices to access 				  *  NVRAM. */
name|BHND_NVRAM_SRC_SPROM
block|,
comment|/**< External serial EEPROM. */
name|BHND_NVRAM_SRC_NONE
comment|/**< No NVRAM source is directly 				  *  attached. This is used on devices 				  *  attached via PCI(e) to BHND SoCs, 				  *  where to avoid unnecessary flash 				  *  hardware, NVRAM configuration for 				  *  individual devices is provided by 				  *  hardware attached to the SoC 				  *  itself. 				  */
block|}
name|bhnd_nvram_src_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_H_ */
end_comment

end_unit

