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

begin_define
define|#
directive|define
name|LBC_IVAR_DEVTYPE
value|1
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
comment|/* Device types. */
end_comment

begin_define
define|#
directive|define
name|LBC_DEVTYPE_CFI
value|1
end_define

begin_define
define|#
directive|define
name|LBC_DEVTYPE_RTC
value|2
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
value|(OCP85XX_LBC_OFF + (8 * n))
end_define

begin_define
define|#
directive|define
name|LBC85XX_OR
parameter_list|(
name|n
parameter_list|)
value|(OCP85XX_LBC_OFF + 4 + (8 * n))
end_define

begin_define
define|#
directive|define
name|LBC85XX_LBCR
value|(OCP85XX_LBC_OFF + 0xd0)
end_define

begin_define
define|#
directive|define
name|LBC85XX_LCRR
value|(OCP85XX_LBC_OFF + 0xd4)
end_define

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
name|lbc_resource
block|{
name|int
name|lbr_devtype
decl_stmt|;
comment|/* LBC device type */
name|int
name|lbr_unit
decl_stmt|;
comment|/* Resource table entry number */
name|vm_paddr_t
name|lbr_base_addr
decl_stmt|;
comment|/* Device mem region base address */
name|size_t
name|lbr_size
decl_stmt|;
comment|/* Device mem region size */
name|int
name|lbr_port_size
decl_stmt|;
comment|/* Data bus width */
name|uint8_t
name|lbr_msel
decl_stmt|;
comment|/* LBC machine select */
name|uint8_t
name|lbr_decc
decl_stmt|;
comment|/* Data error checking mode */
name|uint8_t
name|lbr_atom
decl_stmt|;
comment|/* Atomic operation mode */
name|uint8_t
name|lbr_wp
decl_stmt|;
comment|/* Write protect */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|lbc_resource
name|mpc85xx_lbc_resources
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_LBC_H_ */
end_comment

end_unit

