begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015-2016 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BXE_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_BXE_IOCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|bxe_grcdump
block|{
name|uint16_t
name|pci_func
decl_stmt|;
name|uint32_t
name|grcdump_size
decl_stmt|;
name|void
modifier|*
name|grcdump
decl_stmt|;
name|uint32_t
name|grcdump_dwords
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bxe_grcdump
name|bxe_grcdump_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BXE_DRV_NAME_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|BXE_DRV_VERSION_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|BXE_MFW_VERSION_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|BXE_STORMFW_VERSION_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|BXE_BUS_INFO_LENGTH
value|32
end_define

begin_struct
struct|struct
name|bxe_drvinfo
block|{
name|char
name|drv_name
index|[
name|BXE_DRV_NAME_LENGTH
index|]
decl_stmt|;
name|char
name|drv_version
index|[
name|BXE_DRV_VERSION_LENGTH
index|]
decl_stmt|;
name|char
name|mfw_version
index|[
name|BXE_MFW_VERSION_LENGTH
index|]
decl_stmt|;
name|char
name|stormfw_version
index|[
name|BXE_STORMFW_VERSION_LENGTH
index|]
decl_stmt|;
name|uint32_t
name|eeprom_dump_len
decl_stmt|;
comment|/* in bytes */
name|uint32_t
name|reg_dump_len
decl_stmt|;
comment|/* in bytes */
name|char
name|bus_info
index|[
name|BXE_BUS_INFO_LENGTH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bxe_drvinfo
name|bxe_drvinfo_t
typedef|;
end_typedef

begin_struct
struct|struct
name|bxe_dev_setting
block|{
name|uint32_t
name|supported
decl_stmt|;
comment|/* Features this interface supports */
name|uint32_t
name|advertising
decl_stmt|;
comment|/* Features this interface advertises */
name|uint32_t
name|speed
decl_stmt|;
comment|/* The forced speed, 10Mb, 100Mb, gigabit */
name|uint32_t
name|duplex
decl_stmt|;
comment|/* Duplex, half or full */
name|uint32_t
name|port
decl_stmt|;
comment|/* Which connector port */
name|uint32_t
name|phy_address
decl_stmt|;
comment|/* port number*/
name|uint32_t
name|autoneg
decl_stmt|;
comment|/* Enable or disable autonegotiation */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bxe_dev_setting
name|bxe_dev_setting_t
typedef|;
end_typedef

begin_struct
struct|struct
name|bxe_get_regs
block|{
name|void
modifier|*
name|reg_buf
decl_stmt|;
name|uint32_t
name|reg_buf_len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bxe_get_regs
name|bxe_get_regs_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BXE_EEPROM_MAX_DATA_LEN
value|524288
end_define

begin_struct
struct|struct
name|bxe_eeprom
block|{
name|uint32_t
name|eeprom_cmd
decl_stmt|;
define|#
directive|define
name|BXE_EEPROM_CMD_SET_EEPROM
value|0x01
define|#
directive|define
name|BXE_EEPROM_CMD_GET_EEPROM
value|0x02
name|void
modifier|*
name|eeprom_data
decl_stmt|;
name|uint32_t
name|eeprom_offset
decl_stmt|;
name|uint32_t
name|eeprom_data_len
decl_stmt|;
name|uint32_t
name|eeprom_magic
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bxe_eeprom
name|bxe_eeprom_t
typedef|;
end_typedef

begin_struct
struct|struct
name|bxe_reg_rdw
block|{
name|uint32_t
name|reg_cmd
decl_stmt|;
define|#
directive|define
name|BXE_READ_REG_CMD
value|0x01
define|#
directive|define
name|BXE_WRITE_REG_CMD
value|0x02
name|uint32_t
name|reg_id
decl_stmt|;
name|uint32_t
name|reg_val
decl_stmt|;
name|uint32_t
name|reg_access_type
decl_stmt|;
define|#
directive|define
name|BXE_REG_ACCESS_DIRECT
value|0x01
define|#
directive|define
name|BXE_REG_ACCESS_INDIRECT
value|0x02
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bxe_reg_rdw
name|bxe_reg_rdw_t
typedef|;
end_typedef

begin_struct
struct|struct
name|bxe_pcicfg_rdw
block|{
name|uint32_t
name|cfg_cmd
decl_stmt|;
define|#
directive|define
name|BXE_READ_PCICFG
value|0x01
define|#
directive|define
name|BXE_WRITE_PCICFG
value|0x01
name|uint32_t
name|cfg_id
decl_stmt|;
name|uint32_t
name|cfg_val
decl_stmt|;
name|uint32_t
name|cfg_width
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bxe_pcicfg_rdw
name|bxe_pcicfg_rdw_t
typedef|;
end_typedef

begin_struct
struct|struct
name|bxe_perm_mac_addr
block|{
name|char
name|mac_addr_str
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bxe_perm_mac_addr
name|bxe_perm_mac_addr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read grcdump size  */
end_comment

begin_define
define|#
directive|define
name|BXE_GRC_DUMP_SIZE
value|_IOWR('e', 1, bxe_grcdump_t)
end_define

begin_comment
comment|/*  * Read grcdump  */
end_comment

begin_define
define|#
directive|define
name|BXE_GRC_DUMP
value|_IOWR('e', 2, bxe_grcdump_t)
end_define

begin_comment
comment|/*  * Read driver info  */
end_comment

begin_define
define|#
directive|define
name|BXE_DRV_INFO
value|_IOR('e', 3, bxe_drvinfo_t)
end_define

begin_comment
comment|/*  * Read Device Setting  */
end_comment

begin_define
define|#
directive|define
name|BXE_DEV_SETTING
value|_IOR('e', 4, bxe_dev_setting_t)
end_define

begin_comment
comment|/*  * Get Registers  */
end_comment

begin_define
define|#
directive|define
name|BXE_GET_REGS
value|_IOR('e', 5, bxe_get_regs_t)
end_define

begin_comment
comment|/*  * Get/Set EEPROM  */
end_comment

begin_define
define|#
directive|define
name|BXE_EEPROM
value|_IOWR('e', 6, bxe_eeprom_t)
end_define

begin_comment
comment|/*  * read/write a register  */
end_comment

begin_define
define|#
directive|define
name|BXE_RDW_REG
value|_IOWR('e', 7, bxe_reg_rdw_t)
end_define

begin_comment
comment|/*  * read/write PCIcfg  */
end_comment

begin_define
define|#
directive|define
name|BXE_RDW_PCICFG
value|_IOWR('e', 8, bxe_reg_rdw_t)
end_define

begin_comment
comment|/*  * get permanent mac address  */
end_comment

begin_define
define|#
directive|define
name|BXE_MAC_ADDR
value|_IOWR('e', 9, bxe_perm_mac_addr_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLNX_IOCTL_H_ */
end_comment

end_unit

