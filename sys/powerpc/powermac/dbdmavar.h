begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Nathan Whitehorn  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_POWERMAC_DBDMAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_POWERMAC_DBDMAVAR_H_
end_define

begin_struct
struct|struct
name|dbdma_command
block|{
name|uint8_t
name|cmd
range|:
literal|4
decl_stmt|;
comment|/* DBDMA command */
name|uint8_t
name|_resd1
range|:
literal|1
decl_stmt|;
name|uint8_t
name|key
range|:
literal|3
decl_stmt|;
comment|/* Stream number, or 6 for KEY_SYSTEM */
name|uint8_t
name|_resd2
range|:
literal|2
decl_stmt|;
comment|/* Interrupt, branch, and wait flags */
name|uint8_t
name|intr
range|:
literal|2
decl_stmt|;
name|uint8_t
name|branch
range|:
literal|2
decl_stmt|;
name|uint8_t
name|wait
range|:
literal|2
decl_stmt|;
name|uint16_t
name|reqCount
decl_stmt|;
comment|/* Bytes to transfer */
name|uint32_t
name|address
decl_stmt|;
comment|/* 32-bit system physical address */
name|uint32_t
name|cmdDep
decl_stmt|;
comment|/* Branch address or quad word to load/store */
name|uint16_t
name|xferStatus
decl_stmt|;
comment|/* Contents of channel status after completion */
name|uint16_t
name|resCount
decl_stmt|;
comment|/* Number of residual bytes outstanding */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbdma_channel
block|{
name|struct
name|resource
modifier|*
name|sc_regs
decl_stmt|;
name|u_int
name|sc_off
decl_stmt|;
name|struct
name|dbdma_command
modifier|*
name|sc_slots
decl_stmt|;
name|int
name|sc_nslots
decl_stmt|;
name|bus_addr_t
name|sc_slots_pa
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmatag
decl_stmt|;
name|bus_dmamap_t
name|sc_dmamap
decl_stmt|;
name|uint32_t
name|sc_saved_regs
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*    DBDMA registers are found at 0x8000 + n*0x100 in the macio register space,    and are laid out as follows within each block:  	    Address:			Description:		Length (bytes):    0x000 			Channel Control 	4    0x004 			Channel Status		4    0x00C			Command Phys Addr	4    0x010			Interrupt Select	4    0x014			Branch Select		4    0x018			Wait Select		4 */
end_comment

begin_define
define|#
directive|define
name|CHAN_CONTROL_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|CHAN_STATUS_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|CHAN_CMDPTR_HI
value|0x08
end_define

begin_define
define|#
directive|define
name|CHAN_CMDPTR
value|0x0C
end_define

begin_define
define|#
directive|define
name|CHAN_INTR_SELECT
value|0x10
end_define

begin_define
define|#
directive|define
name|CHAN_BRANCH_SELECT
value|0x14
end_define

begin_define
define|#
directive|define
name|CHAN_WAIT_SELECT
value|0x18
end_define

begin_comment
comment|/* Channel control is the write channel to channel status, the upper 16 bits    are a mask of which bytes to change */
end_comment

begin_define
define|#
directive|define
name|DBDMA_REG_MASK_SHIFT
value|16
end_define

begin_comment
comment|/* Status bits 0-7 are device dependent status bits */
end_comment

begin_comment
comment|/*    The Interrupt/Branch/Wait Select triggers the corresponding condition bits    in the event that (select.mask& device dependent status) == select.value     They are defined a follows: 	Byte 1: Reserved 	Byte 2: Mask 	Byte 3: Reserved 	Byte 4: Value */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_POWERMAC_DBDMAVAR_H_ */
end_comment

end_unit

