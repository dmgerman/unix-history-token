begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2008, Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_LBC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_LBC_H_
end_define

begin_comment
comment|/* Maximum number of devices on Local Bus */
end_comment

begin_define
define|#
directive|define
name|LBC_DEV_MAX
value|8
end_define

begin_comment
comment|/* Local access registers */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_BR
parameter_list|(
name|n
parameter_list|)
value|(0x0 + (8 * n))
end_define

begin_comment
comment|/* Base register 0-7 */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_OR
parameter_list|(
name|n
parameter_list|)
value|(0x4 + (8 * n))
end_define

begin_comment
comment|/* Options register 0-7 */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_MAR
value|0x068
end_define

begin_comment
comment|/* UPM address register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_MAMR
value|0x070
end_define

begin_comment
comment|/* UPMA mode register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_MBMR
value|0x074
end_define

begin_comment
comment|/* UPMB mode register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_MCMR
value|0x078
end_define

begin_comment
comment|/* UPMC mode register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_MRTPR
value|0x084
end_define

begin_comment
comment|/* Memory refresh timer prescaler */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_MDR
value|0x088
end_define

begin_comment
comment|/* UPM data register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LSOR
value|0x090
end_define

begin_comment
comment|/* Special operation initiation */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LURT
value|0x0a0
end_define

begin_comment
comment|/* UPM refresh timer */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LSRT
value|0x0a4
end_define

begin_comment
comment|/* SDRAM refresh timer */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LTESR
value|0x0b0
end_define

begin_comment
comment|/* Transfer error status register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LTEDR
value|0x0b4
end_define

begin_comment
comment|/* Transfer error disable register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LTEIR
value|0x0b8
end_define

begin_comment
comment|/* Transfer error interrupt register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LTEATR
value|0x0bc
end_define

begin_comment
comment|/* Transfer error attributes register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LTEAR
value|0x0c0
end_define

begin_comment
comment|/* Transfer error address register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LTECCR
value|0x0c4
end_define

begin_comment
comment|/* Transfer error ECC register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LBCR
value|0x0d0
end_define

begin_comment
comment|/* Configuration register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_LCRR
value|0x0d4
end_define

begin_comment
comment|/* Clock ratio register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FMR
value|0x0e0
end_define

begin_comment
comment|/* Flash mode register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FIR
value|0x0e4
end_define

begin_comment
comment|/* Flash instruction register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FCR
value|0x0e8
end_define

begin_comment
comment|/* Flash command register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FBAR
value|0x0ec
end_define

begin_comment
comment|/* Flash block address register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FPAR
value|0x0f0
end_define

begin_comment
comment|/* Flash page address register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FBCR
value|0x0f4
end_define

begin_comment
comment|/* Flash byte count register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FECC0
value|0x100
end_define

begin_comment
comment|/* Flash ECC block 0 register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FECC1
value|0x104
end_define

begin_comment
comment|/* Flash ECC block 0 register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FECC2
value|0x108
end_define

begin_comment
comment|/* Flash ECC block 0 register */
end_comment

begin_define
define|#
directive|define
name|LBC85XX_FECC3
value|0x10c
end_define

begin_comment
comment|/* Flash ECC block 0 register */
end_comment

begin_comment
comment|/* LBC machine select */
end_comment

begin_define
define|#
directive|define
name|LBCRES_MSEL_GPCM
value|0
end_define

begin_define
define|#
directive|define
name|LBCRES_MSEL_FCM
value|1
end_define

begin_define
define|#
directive|define
name|LBCRES_MSEL_UPMA
value|8
end_define

begin_define
define|#
directive|define
name|LBCRES_MSEL_UPMB
value|9
end_define

begin_define
define|#
directive|define
name|LBCRES_MSEL_UPMC
value|10
end_define

begin_comment
comment|/* LBC data error checking modes */
end_comment

begin_define
define|#
directive|define
name|LBCRES_DECC_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|LBCRES_DECC_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|LBCRES_DECC_RMW
value|2
end_define

begin_comment
comment|/* LBC atomic operation modes */
end_comment

begin_define
define|#
directive|define
name|LBCRES_ATOM_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|LBCRES_ATOM_RAWA
value|1
end_define

begin_define
define|#
directive|define
name|LBCRES_ATOM_WARA
value|2
end_define

begin_struct
struct|struct
name|lbc_memrange
block|{
name|vm_paddr_t
name|addr
decl_stmt|;
name|vm_size_t
name|size
decl_stmt|;
name|vm_offset_t
name|kva
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lbc_bank
block|{
name|vm_paddr_t
name|addr
decl_stmt|;
comment|/* physical addr of the bank */
name|vm_size_t
name|size
decl_stmt|;
comment|/* bank size */
name|vm_offset_t
name|kva
decl_stmt|;
comment|/* VA of the bank */
comment|/* 	 * XXX the following bank attributes do not have properties specified 	 * in the LBC DTS bindings yet (11.2009), so they are mainly a 	 * placeholder for future extensions. 	 */
name|int
name|width
decl_stmt|;
comment|/* data bus width */
name|uint8_t
name|msel
decl_stmt|;
comment|/* machine select */
name|uint8_t
name|atom
decl_stmt|;
comment|/* atomic op mode */
name|uint8_t
name|wp
decl_stmt|;
comment|/* write protect */
name|uint8_t
name|decc
decl_stmt|;
comment|/* data error checking */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lbc_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mres
decl_stmt|;
name|bus_space_handle_t
name|sc_bsh
decl_stmt|;
name|bus_space_tag_t
name|sc_bst
decl_stmt|;
name|int
name|sc_mrid
decl_stmt|;
name|int
name|sc_irid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_ires
decl_stmt|;
name|void
modifier|*
name|sc_icookie
decl_stmt|;
name|struct
name|rman
name|sc_rman
decl_stmt|;
name|int
name|sc_addr_cells
decl_stmt|;
name|int
name|sc_size_cells
decl_stmt|;
name|struct
name|lbc_memrange
name|sc_range
index|[
name|LBC_DEV_MAX
index|]
decl_stmt|;
name|struct
name|lbc_bank
name|sc_banks
index|[
name|LBC_DEV_MAX
index|]
decl_stmt|;
name|uint32_t
name|sc_ltesr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lbc_devinfo
block|{
name|struct
name|ofw_bus_devinfo
name|di_ofw
decl_stmt|;
name|struct
name|resource_list
name|di_res
decl_stmt|;
name|int
name|di_bank
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|uint32_t
name|lbc_read_reg
parameter_list|(
name|device_t
name|child
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lbc_write_reg
parameter_list|(
name|device_t
name|child
parameter_list|,
name|u_int
name|off
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_LBC_H_ */
end_comment

end_unit

