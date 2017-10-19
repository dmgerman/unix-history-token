begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2016 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: ql_ioctl.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QL_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_QL_IOCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|qla_reg_val
block|{
name|uint16_t
name|rd
decl_stmt|;
name|uint16_t
name|direct
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_reg_val
name|qla_reg_val_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_rd_flash
block|{
name|uint32_t
name|off
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_rd_flash
name|qla_rd_flash_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_wr_flash
block|{
name|uint32_t
name|off
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|void
modifier|*
name|buffer
decl_stmt|;
name|uint32_t
name|pattern
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_wr_flash
name|qla_wr_flash_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_erase_flash
block|{
name|uint32_t
name|off
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_erase_flash
name|qla_erase_flash_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_rd_pci_ids
block|{
name|uint16_t
name|ven_id
decl_stmt|;
name|uint16_t
name|dev_id
decl_stmt|;
name|uint16_t
name|subsys_ven_id
decl_stmt|;
name|uint16_t
name|subsys_dev_id
decl_stmt|;
name|uint8_t
name|rev_id
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_rd_pci_ids
name|qla_rd_pci_ids_t
typedef|;
end_typedef

begin_comment
comment|/*  * structure encapsulating the value to read/write from/to offchip (MS) memory  */
end_comment

begin_struct
struct|struct
name|qla_offchip_mem_val
block|{
name|uint16_t
name|rd
decl_stmt|;
name|uint64_t
name|off
decl_stmt|;
name|uint32_t
name|data_lo
decl_stmt|;
name|uint32_t
name|data_hi
decl_stmt|;
name|uint32_t
name|data_ulo
decl_stmt|;
name|uint32_t
name|data_uhi
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_offchip_mem_val
name|qla_offchip_mem_val_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_rd_fw_dump
block|{
name|uint16_t
name|pci_func
decl_stmt|;
name|uint32_t
name|minidump_size
decl_stmt|;
name|void
modifier|*
name|minidump
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_rd_fw_dump
name|qla_rd_fw_dump_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_drvr_state_tx
block|{
name|uint64_t
name|base_p_addr
decl_stmt|;
name|uint64_t
name|cons_p_addr
decl_stmt|;
name|uint32_t
name|tx_prod_reg
decl_stmt|;
name|uint32_t
name|tx_cntxt_id
decl_stmt|;
name|uint32_t
name|txr_free
decl_stmt|;
name|uint32_t
name|txr_next
decl_stmt|;
name|uint32_t
name|txr_comp
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_drvr_state_tx
name|qla_drvr_state_tx_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_drvr_state_sds
block|{
name|uint32_t
name|sdsr_next
decl_stmt|;
comment|/* next entry in SDS ring to process */
name|uint32_t
name|sds_consumer
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_drvr_state_sds
name|qla_drvr_state_sds_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_drvr_state_rx
block|{
name|uint32_t
name|prod_std
decl_stmt|;
name|uint32_t
name|rx_next
decl_stmt|;
comment|/* next standard rcv ring to arm fw */
empty_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_drvr_state_rx
name|qla_drvr_state_rx_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_drvr_state_hdr
block|{
name|uint32_t
name|drvr_version_major
decl_stmt|;
name|uint32_t
name|drvr_version_minor
decl_stmt|;
name|uint32_t
name|drvr_version_build
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|link_speed
decl_stmt|;
name|uint16_t
name|cable_length
decl_stmt|;
name|uint32_t
name|cable_oui
decl_stmt|;
name|uint8_t
name|link_up
decl_stmt|;
name|uint8_t
name|module_type
decl_stmt|;
name|uint8_t
name|link_faults
decl_stmt|;
name|uint32_t
name|rcv_intr_coalesce
decl_stmt|;
name|uint32_t
name|xmt_intr_coalesce
decl_stmt|;
name|uint32_t
name|tx_state_offset
decl_stmt|;
comment|/* size = sizeof (qla_drvr_state_tx_t) * num_tx_rings */
name|uint32_t
name|rx_state_offset
decl_stmt|;
comment|/* size = sizeof (qla_drvr_state_rx_t) * num_rx_rings */
name|uint32_t
name|sds_state_offset
decl_stmt|;
comment|/* size = sizeof (qla_drvr_state_sds_t) * num_sds_rings */
name|uint32_t
name|num_tx_rings
decl_stmt|;
comment|/* number of tx rings */
name|uint32_t
name|txr_size
decl_stmt|;
comment|/* size of each tx ring in bytes */
name|uint32_t
name|txr_entries
decl_stmt|;
comment|/* number of descriptors in each tx ring */
name|uint32_t
name|txr_offset
decl_stmt|;
comment|/* start of tx ring [0 - #rings] content */
name|uint32_t
name|num_rx_rings
decl_stmt|;
comment|/* number of rx rings */
name|uint32_t
name|rxr_size
decl_stmt|;
comment|/* size of each rx ring in bytes */
name|uint32_t
name|rxr_entries
decl_stmt|;
comment|/* number of descriptors in each rx ring */
name|uint32_t
name|rxr_offset
decl_stmt|;
comment|/* start of rx ring [0 - #rings] content */
name|uint32_t
name|num_sds_rings
decl_stmt|;
comment|/* number of sds rings */
name|uint32_t
name|sds_ring_size
decl_stmt|;
comment|/* size of each sds ring in bytes */
name|uint32_t
name|sds_entries
decl_stmt|;
comment|/* number of descriptors in each sds ring */
name|uint32_t
name|sds_offset
decl_stmt|;
comment|/* start of sds ring [0 - #rings] content */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_drvr_state_hdr
name|qla_drvr_state_hdr_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_driver_state
block|{
name|uint32_t
name|size
decl_stmt|;
name|void
modifier|*
name|buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_driver_state
name|qla_driver_state_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read/Write Register  */
end_comment

begin_define
define|#
directive|define
name|QLA_RDWR_REG
value|_IOWR('q', 1, qla_reg_val_t)
end_define

begin_comment
comment|/*  * Read Flash  */
end_comment

begin_define
define|#
directive|define
name|QLA_RD_FLASH
value|_IOWR('q', 2, qla_rd_flash_t)
end_define

begin_comment
comment|/*  * Write Flash  */
end_comment

begin_define
define|#
directive|define
name|QLA_WR_FLASH
value|_IOWR('q', 3, qla_wr_flash_t)
end_define

begin_comment
comment|/*  * Read Offchip (MS) Memory  */
end_comment

begin_define
define|#
directive|define
name|QLA_RDWR_MS_MEM
value|_IOWR('q', 4, qla_offchip_mem_val_t)
end_define

begin_comment
comment|/*  * Erase Flash  */
end_comment

begin_define
define|#
directive|define
name|QLA_ERASE_FLASH
value|_IOWR('q', 5, qla_erase_flash_t)
end_define

begin_comment
comment|/*  * Read PCI IDs   */
end_comment

begin_define
define|#
directive|define
name|QLA_RD_PCI_IDS
value|_IOWR('q', 6, qla_rd_pci_ids_t)
end_define

begin_comment
comment|/*  * Read Minidump Template Size  */
end_comment

begin_define
define|#
directive|define
name|QLA_RD_FW_DUMP_SIZE
value|_IOWR('q', 7, qla_rd_fw_dump_t)
end_define

begin_comment
comment|/*  * Read Minidump Template  */
end_comment

begin_define
define|#
directive|define
name|QLA_RD_FW_DUMP
value|_IOWR('q', 8, qla_rd_fw_dump_t)
end_define

begin_comment
comment|/*  * Read Driver State  */
end_comment

begin_define
define|#
directive|define
name|QLA_RD_DRVR_STATE
value|_IOWR('q', 9, qla_driver_state_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QL_IOCTL_H_ */
end_comment

end_unit

