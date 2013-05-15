begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2014 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|template_size
decl_stmt|;
name|void
modifier|*
name|md_template
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QL_IOCTL_H_ */
end_comment

end_unit

