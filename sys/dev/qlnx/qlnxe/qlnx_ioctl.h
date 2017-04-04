begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLNX_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLNX_IOCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|QLNX_MAX_HW_FUNCS
value|2
end_define

begin_comment
comment|/*  * Read grcdump and grcdump size  */
end_comment

begin_struct
struct|struct
name|qlnx_grcdump
block|{
name|uint16_t
name|pci_func
decl_stmt|;
name|uint32_t
name|grcdump_size
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|void
modifier|*
name|grcdump
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|uint32_t
name|grcdump_dwords
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_grcdump
name|qlnx_grcdump_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read idle_chk and idle_chk size  */
end_comment

begin_struct
struct|struct
name|qlnx_idle_chk
block|{
name|uint16_t
name|pci_func
decl_stmt|;
name|uint32_t
name|idle_chk_size
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|void
modifier|*
name|idle_chk
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|uint32_t
name|idle_chk_dwords
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_idle_chk
name|qlnx_idle_chk_t
typedef|;
end_typedef

begin_comment
comment|/*  * Retrive traces  */
end_comment

begin_struct
struct|struct
name|qlnx_trace
block|{
name|uint16_t
name|pci_func
decl_stmt|;
name|uint16_t
name|cmd
decl_stmt|;
define|#
directive|define
name|QLNX_MCP_TRACE
value|0x01
define|#
directive|define
name|QLNX_REG_FIFO
value|0x02
define|#
directive|define
name|QLNX_IGU_FIFO
value|0x03
define|#
directive|define
name|QLNX_PROTECTION_OVERRIDE
value|0x04
define|#
directive|define
name|QLNX_FW_ASSERTS
value|0x05
name|uint32_t
name|size
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|void
modifier|*
name|buffer
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|uint32_t
name|dwords
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_trace
name|qlnx_trace_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read driver info  */
end_comment

begin_define
define|#
directive|define
name|QLNX_DRV_INFO_NAME_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|QLNX_DRV_INFO_VERSION_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|QLNX_DRV_INFO_MFW_VERSION_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|QLNX_DRV_INFO_STORMFW_VERSION_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|QLNX_DRV_INFO_BUS_INFO_LENGTH
value|32
end_define

begin_struct
struct|struct
name|qlnx_drvinfo
block|{
name|char
name|drv_name
index|[
name|QLNX_DRV_INFO_NAME_LENGTH
index|]
decl_stmt|;
name|char
name|drv_version
index|[
name|QLNX_DRV_INFO_VERSION_LENGTH
index|]
decl_stmt|;
name|char
name|mfw_version
index|[
name|QLNX_DRV_INFO_MFW_VERSION_LENGTH
index|]
decl_stmt|;
name|char
name|stormfw_version
index|[
name|QLNX_DRV_INFO_STORMFW_VERSION_LENGTH
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
name|QLNX_DRV_INFO_BUS_INFO_LENGTH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_drvinfo
name|qlnx_drvinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read Device Setting  */
end_comment

begin_struct
struct|struct
name|qlnx_dev_setting
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
name|qlnx_dev_setting
name|qlnx_dev_setting_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get Registers  */
end_comment

begin_struct
struct|struct
name|qlnx_get_regs
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
name|qlnx_get_regs
name|qlnx_get_regs_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get/Set NVRAM  */
end_comment

begin_struct
struct|struct
name|qlnx_nvram
block|{
name|uint32_t
name|cmd
decl_stmt|;
define|#
directive|define
name|QLNX_NVRAM_CMD_WRITE_NVRAM
value|0x01
define|#
directive|define
name|QLNX_NVRAM_CMD_READ_NVRAM
value|0x02
define|#
directive|define
name|QLNX_NVRAM_CMD_SET_SECURE_MODE
value|0x03
define|#
directive|define
name|QLNX_NVRAM_CMD_DEL_FILE
value|0x04
define|#
directive|define
name|QLNX_NVRAM_CMD_PUT_FILE_BEGIN
value|0x05
define|#
directive|define
name|QLNX_NVRAM_CMD_GET_NVRAM_RESP
value|0x06
define|#
directive|define
name|QLNX_NVRAM_CMD_PUT_FILE_DATA
value|0x07
name|void
modifier|*
name|data
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|data_len
decl_stmt|;
name|uint32_t
name|magic
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_nvram
name|qlnx_nvram_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get/Set Device registers  */
end_comment

begin_struct
struct|struct
name|qlnx_reg_rd_wr
block|{
name|uint32_t
name|cmd
decl_stmt|;
define|#
directive|define
name|QLNX_REG_READ_CMD
value|0x01
define|#
directive|define
name|QLNX_REG_WRITE_CMD
value|0x02
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
name|uint32_t
name|access_type
decl_stmt|;
define|#
directive|define
name|QLNX_REG_ACCESS_DIRECT
value|0x01
define|#
directive|define
name|QLNX_REG_ACCESS_INDIRECT
value|0x02
name|uint32_t
name|hwfn_index
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_reg_rd_wr
name|qlnx_reg_rd_wr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read/Write PCI Configuration  */
end_comment

begin_struct
struct|struct
name|qlnx_pcicfg_rd_wr
block|{
name|uint32_t
name|cmd
decl_stmt|;
define|#
directive|define
name|QLNX_PCICFG_READ
value|0x01
define|#
directive|define
name|QLNX_PCICFG_WRITE
value|0x02
name|uint32_t
name|reg
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
name|uint32_t
name|width
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_pcicfg_rd_wr
name|qlnx_pcicfg_rd_wr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read MAC address  */
end_comment

begin_struct
struct|struct
name|qlnx_perm_mac_addr
block|{
name|char
name|addr
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
name|qlnx_perm_mac_addr
name|qlnx_perm_mac_addr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read STORM statistics registers  */
end_comment

begin_struct
struct|struct
name|qlnx_storm_stats
block|{
comment|/* xstorm */
name|uint32_t
name|xstorm_active_cycles
decl_stmt|;
name|uint32_t
name|xstorm_stall_cycles
decl_stmt|;
name|uint32_t
name|xstorm_sleeping_cycles
decl_stmt|;
name|uint32_t
name|xstorm_inactive_cycles
decl_stmt|;
comment|/* ystorm */
name|uint32_t
name|ystorm_active_cycles
decl_stmt|;
name|uint32_t
name|ystorm_stall_cycles
decl_stmt|;
name|uint32_t
name|ystorm_sleeping_cycles
decl_stmt|;
name|uint32_t
name|ystorm_inactive_cycles
decl_stmt|;
comment|/* pstorm */
name|uint32_t
name|pstorm_active_cycles
decl_stmt|;
name|uint32_t
name|pstorm_stall_cycles
decl_stmt|;
name|uint32_t
name|pstorm_sleeping_cycles
decl_stmt|;
name|uint32_t
name|pstorm_inactive_cycles
decl_stmt|;
comment|/* tstorm */
name|uint32_t
name|tstorm_active_cycles
decl_stmt|;
name|uint32_t
name|tstorm_stall_cycles
decl_stmt|;
name|uint32_t
name|tstorm_sleeping_cycles
decl_stmt|;
name|uint32_t
name|tstorm_inactive_cycles
decl_stmt|;
comment|/* mstorm */
name|uint32_t
name|mstorm_active_cycles
decl_stmt|;
name|uint32_t
name|mstorm_stall_cycles
decl_stmt|;
name|uint32_t
name|mstorm_sleeping_cycles
decl_stmt|;
name|uint32_t
name|mstorm_inactive_cycles
decl_stmt|;
comment|/* ustorm */
name|uint32_t
name|ustorm_active_cycles
decl_stmt|;
name|uint32_t
name|ustorm_stall_cycles
decl_stmt|;
name|uint32_t
name|ustorm_sleeping_cycles
decl_stmt|;
name|uint32_t
name|ustorm_inactive_cycles
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_storm_stats
name|qlnx_storm_stats_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QLNX_STORM_STATS_SAMPLES_PER_HWFN
value|(10000)
end_define

begin_define
define|#
directive|define
name|QLNX_STORM_STATS_BYTES_PER_HWFN
value|(sizeof(qlnx_storm_stats_t) * \ 		QLNX_STORM_STATS_SAMPLES_PER_HWFN)
end_define

begin_struct
struct|struct
name|qlnx_storm_stats_dump
block|{
name|int
name|num_hwfns
decl_stmt|;
name|int
name|num_samples
decl_stmt|;
name|void
modifier|*
name|buffer
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_storm_stats_dump
name|qlnx_storm_stats_dump_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read grcdump size  */
end_comment

begin_define
define|#
directive|define
name|QLNX_GRC_DUMP_SIZE
value|_IOWR('q', 1, qlnx_grcdump_t)
end_define

begin_comment
comment|/*  * Read grcdump  */
end_comment

begin_define
define|#
directive|define
name|QLNX_GRC_DUMP
value|_IOWR('q', 2, qlnx_grcdump_t)
end_define

begin_comment
comment|/*  * Read idle_chk size  */
end_comment

begin_define
define|#
directive|define
name|QLNX_IDLE_CHK_SIZE
value|_IOWR('q', 3, qlnx_idle_chk_t)
end_define

begin_comment
comment|/*  * Read idle_chk  */
end_comment

begin_define
define|#
directive|define
name|QLNX_IDLE_CHK
value|_IOWR('q', 4, qlnx_idle_chk_t)
end_define

begin_comment
comment|/*  * Read driver info  */
end_comment

begin_define
define|#
directive|define
name|QLNX_DRV_INFO
value|_IOWR('q', 5, qlnx_drvinfo_t)
end_define

begin_comment
comment|/*  * Read Device Setting  */
end_comment

begin_define
define|#
directive|define
name|QLNX_DEV_SETTING
value|_IOR('q', 6, qlnx_dev_setting_t)
end_define

begin_comment
comment|/*  * Get Registers  */
end_comment

begin_define
define|#
directive|define
name|QLNX_GET_REGS
value|_IOR('q', 7, qlnx_get_regs_t)
end_define

begin_comment
comment|/*  * Get/Set NVRAM  */
end_comment

begin_define
define|#
directive|define
name|QLNX_NVRAM
value|_IOWR('q', 8, qlnx_nvram_t)
end_define

begin_comment
comment|/*  * Get/Set Device registers  */
end_comment

begin_define
define|#
directive|define
name|QLNX_RD_WR_REG
value|_IOWR('q', 9, qlnx_reg_rd_wr_t)
end_define

begin_comment
comment|/*  * Read/Write PCI Configuration  */
end_comment

begin_define
define|#
directive|define
name|QLNX_RD_WR_PCICFG
value|_IOWR('q', 10, qlnx_pcicfg_rd_wr_t)
end_define

begin_comment
comment|/*  * Read MAC address  */
end_comment

begin_define
define|#
directive|define
name|QLNX_MAC_ADDR
value|_IOWR('q', 11, qlnx_perm_mac_addr_t)
end_define

begin_comment
comment|/*  * Read STORM statistics  */
end_comment

begin_define
define|#
directive|define
name|QLNX_STORM_STATS
value|_IOWR('q', 12, qlnx_storm_stats_dump_t)
end_define

begin_comment
comment|/*  * Read trace size  */
end_comment

begin_define
define|#
directive|define
name|QLNX_TRACE_SIZE
value|_IOWR('q', 13, qlnx_trace_t)
end_define

begin_comment
comment|/*  * Read trace  */
end_comment

begin_define
define|#
directive|define
name|QLNX_TRACE
value|_IOWR('q', 14, qlnx_trace_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLNX_IOCTL_H_ */
end_comment

end_unit

