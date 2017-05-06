begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007, Juniper Networks, Inc.  * Copyright (c) 2012-2013, SRI International  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * (FA8750-10-C-0237) ("CTSRD"), as part of the DARPA CRASH research  * programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_CFI_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_CFI_REG_H_
end_define

begin_struct
struct|struct
name|cfi_qry
block|{
name|u_char
name|reserved
index|[
literal|16
index|]
decl_stmt|;
name|u_char
name|ident
index|[
literal|3
index|]
decl_stmt|;
comment|/* "QRY" */
name|u_char
name|pri_vend
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|pri_vend_eqt
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|alt_vend
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|alt_vend_eqt
index|[
literal|2
index|]
decl_stmt|;
comment|/* System Interface Information. */
name|u_char
name|min_vcc
decl_stmt|;
name|u_char
name|max_vcc
decl_stmt|;
name|u_char
name|min_vpp
decl_stmt|;
name|u_char
name|max_vpp
decl_stmt|;
name|u_char
name|tto_byte_write
decl_stmt|;
comment|/* 2**n microseconds. */
name|u_char
name|tto_buf_write
decl_stmt|;
comment|/* 2**n microseconds. */
name|u_char
name|tto_block_erase
decl_stmt|;
comment|/* 2**n milliseconds. */
name|u_char
name|tto_chip_erase
decl_stmt|;
comment|/* 2**n milliseconds. */
name|u_char
name|mto_byte_write
decl_stmt|;
comment|/* 2**n times typical t/o. */
name|u_char
name|mto_buf_write
decl_stmt|;
comment|/* 2**n times typical t/o. */
name|u_char
name|mto_block_erase
decl_stmt|;
comment|/* 2**n times typical t/o. */
name|u_char
name|mto_chip_erase
decl_stmt|;
comment|/* 2**n times typical t/o. */
comment|/* Device Geometry Definition. */
name|u_char
name|size
decl_stmt|;
comment|/* 2**n bytes. */
name|u_char
name|iface
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|max_buf_write_size
index|[
literal|2
index|]
decl_stmt|;
comment|/* 2**n. */
name|u_char
name|nregions
decl_stmt|;
comment|/* Number of erase regions. */
name|u_char
name|region
index|[
literal|4
index|]
decl_stmt|;
comment|/* Single entry. */
comment|/* Additional entries follow. */
comment|/* Primary Vendor-specific Extended Query table follows. */
comment|/* Alternate Vendor-specific Extended Query table follows. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CFI_QRY_CMD_ADDR
value|0x55
end_define

begin_define
define|#
directive|define
name|CFI_QRY_CMD_DATA
value|0x98
end_define

begin_define
define|#
directive|define
name|CFI_QRY_IDENT
value|offsetof(struct cfi_qry, ident)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_VEND
value|offsetof(struct cfi_qry, pri_vend)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_TTO_WRITE
value|offsetof(struct cfi_qry, tto_byte_write)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_TTO_BUFWRITE
value|offsetof(struct cfi_qry, tto_buf_write)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_TTO_ERASE
value|offsetof(struct cfi_qry, tto_block_erase)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_MTO_WRITE
value|offsetof(struct cfi_qry, mto_byte_write)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_MTO_BUFWRITE
value|offsetof(struct cfi_qry, mto_buf_write)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_MTO_ERASE
value|offsetof(struct cfi_qry, mto_block_erase)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_SIZE
value|offsetof(struct cfi_qry, size)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_IFACE
value|offsetof(struct cfi_qry, iface)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_MAXBUF
value|offsetof(struct cfi_qry, max_buf_write_size)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_NREGIONS
value|offsetof(struct cfi_qry, nregions)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_REGION0
value|offsetof(struct cfi_qry, region)
end_define

begin_define
define|#
directive|define
name|CFI_QRY_REGION
parameter_list|(
name|x
parameter_list|)
value|(CFI_QRY_REGION0 + (x) * 4)
end_define

begin_define
define|#
directive|define
name|CFI_VEND_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|CFI_VEND_INTEL_ECS
value|0x0001
end_define

begin_define
define|#
directive|define
name|CFI_VEND_AMD_SCS
value|0x0002
end_define

begin_define
define|#
directive|define
name|CFI_VEND_INTEL_SCS
value|0x0003
end_define

begin_define
define|#
directive|define
name|CFI_VEND_AMD_ECS
value|0x0004
end_define

begin_define
define|#
directive|define
name|CFI_VEND_MITSUBISHI_SCS
value|0x0100
end_define

begin_define
define|#
directive|define
name|CFI_VEND_MITSUBISHI_ECS
value|0x0101
end_define

begin_define
define|#
directive|define
name|CFI_IFACE_X8
value|0x0000
end_define

begin_define
define|#
directive|define
name|CFI_IFACE_X16
value|0x0001
end_define

begin_define
define|#
directive|define
name|CFI_IFACE_X8X16
value|0x0002
end_define

begin_define
define|#
directive|define
name|CFI_IFACE_X32
value|0x0003
end_define

begin_define
define|#
directive|define
name|CFI_IFACE_X16X32
value|0x0005
end_define

begin_comment
comment|/* Standard Command Set (aka Basic Command Set) */
end_comment

begin_define
define|#
directive|define
name|CFI_BCS_BLOCK_ERASE
value|0x20
end_define

begin_define
define|#
directive|define
name|CFI_BCS_PROGRAM
value|0x40
end_define

begin_define
define|#
directive|define
name|CFI_BCS_CLEAR_STATUS
value|0x50
end_define

begin_define
define|#
directive|define
name|CFI_BCS_READ_STATUS
value|0x70
end_define

begin_define
define|#
directive|define
name|CFI_BCS_ERASE_SUSPEND
value|0xb0
end_define

begin_define
define|#
directive|define
name|CFI_BCS_ERASE_RESUME
value|0xd0
end_define

begin_comment
comment|/* Equals CONFIRM */
end_comment

begin_define
define|#
directive|define
name|CFI_BCS_CONFIRM
value|0xd0
end_define

begin_define
define|#
directive|define
name|CFI_BCS_BUF_PROG_SETUP
value|0xe8
end_define

begin_define
define|#
directive|define
name|CFI_BCS_READ_ARRAY
value|0xff
end_define

begin_define
define|#
directive|define
name|CFI_BCS_READ_ARRAY2
value|0xf0
end_define

begin_comment
comment|/* Intel commands. */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_LB
value|0x01
end_define

begin_comment
comment|/* Lock Block */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_LBS
value|0x60
end_define

begin_comment
comment|/* Lock Block Setup */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_READ_ID
value|0x90
end_define

begin_comment
comment|/* Read Identifier */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_PP_SETUP
value|0xc0
end_define

begin_comment
comment|/* Protection Program Setup */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_UB
value|0xd0
end_define

begin_comment
comment|/* Unlock Block */
end_comment

begin_comment
comment|/* NB: these are addresses for 16-bit accesses */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_PLR
value|0x80
end_define

begin_comment
comment|/* Protection Lock Register */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_PR
parameter_list|(
name|n
parameter_list|)
value|(0x81+(n))
end_define

begin_comment
comment|/* Protection Register */
end_comment

begin_comment
comment|/* Status register definitions */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_STATUS_WSMS
value|0x0080
end_define

begin_comment
comment|/* Write Machine Status */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_STATUS_ESS
value|0x0040
end_define

begin_comment
comment|/* Erase Suspend Status */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_STATUS_ECLBS
value|0x0020
end_define

begin_comment
comment|/* Erase and Clear Lock-Bit Status */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_STATUS_PSLBS
value|0x0010
end_define

begin_comment
comment|/* Program and Set Lock-Bit Status */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_STATUS_VPENS
value|0x0008
end_define

begin_comment
comment|/* Programming Voltage Status */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_STATUS_PSS
value|0x0004
end_define

begin_comment
comment|/* Program Suspend Status */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_STATUS_DPS
value|0x0002
end_define

begin_comment
comment|/* Device Protect Status */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_STATUS_RSVD
value|0x0001
end_define

begin_comment
comment|/* reserved */
end_comment

begin_comment
comment|/* eXtended Status register definitions */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_XSTATUS_WBS
value|0x8000
end_define

begin_comment
comment|/* Write Buffer Status */
end_comment

begin_define
define|#
directive|define
name|CFI_INTEL_XSTATUS_RSVD
value|0x7f00
end_define

begin_comment
comment|/* reserved */
end_comment

begin_comment
comment|/* AMD commands. */
end_comment

begin_define
define|#
directive|define
name|CFI_AMD_BLOCK_ERASE
value|0x30
end_define

begin_define
define|#
directive|define
name|CFI_AMD_UNLOCK_ACK
value|0x55
end_define

begin_define
define|#
directive|define
name|CFI_AMD_ERASE_SECTOR
value|0x80
end_define

begin_define
define|#
directive|define
name|CFI_AMD_PROGRAM
value|0xa0
end_define

begin_define
define|#
directive|define
name|CFI_AMD_UNLOCK
value|0xaa
end_define

begin_define
define|#
directive|define
name|AMD_ADDR_START
value|0xaaa
end_define

begin_define
define|#
directive|define
name|AMD_ADDR_ACK
value|0x555
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_CFI_REG_H_ */
end_comment

end_unit

