begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 - 2001 John Hay.  * Copyright (c) 1996 SDL Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_SRREGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_SRREGS_H_
end_define

begin_define
define|#
directive|define
name|NCHAN
value|2
end_define

begin_comment
comment|/* A HD64570 chip have 2 channels */
end_comment

begin_define
define|#
directive|define
name|SR_BUF_SIZ
value|512
end_define

begin_define
define|#
directive|define
name|SR_TX_BLOCKS
value|2
end_define

begin_comment
comment|/* Sepperate sets of tx buffers */
end_comment

begin_define
define|#
directive|define
name|SR_CRD_N2
value|1
end_define

begin_define
define|#
directive|define
name|SR_CRD_N2PCI
value|2
end_define

begin_comment
comment|/*  * RISCom/N2 ISA card.  */
end_comment

begin_define
define|#
directive|define
name|SRC_IO_SIZ
value|0x10
end_define

begin_comment
comment|/* Actually a lie. It uses a lot more. */
end_comment

begin_define
define|#
directive|define
name|SRC_WIN_SIZ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SRC_WIN_MSK
value|(SRC_WIN_SIZ - 1)
end_define

begin_define
define|#
directive|define
name|SRC_WIN_SHFT
value|14
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_NCHAN_MSK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_0_CLK_MSK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_0_EXT_CLK
value|0x00000000
end_define

begin_comment
comment|/* External RX clock shared by TX */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_0_EXT_SEP_CLK
value|0x00000010
end_define

begin_comment
comment|/* Sepperate external clocks */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_0_INT_CLK
value|0x00000020
end_define

begin_comment
comment|/* Internal clock */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_1_CLK_MSK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_1_EXT_CLK
value|0x00000000
end_define

begin_comment
comment|/* External RX clock shared by TX */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_1_EXT_SEP_CLK
value|0x00000040
end_define

begin_comment
comment|/* Sepperate external clocks */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_1_INT_CLK
value|0x00000080
end_define

begin_comment
comment|/* Internal clock */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_CLK_SHFT
value|4
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_CLK_CHAN_SHFT
value|2
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_EXT_CLK
value|0x00000000
end_define

begin_comment
comment|/* External RX clock shared by TX */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_EXT_SEP_CLK
value|0x00000001
end_define

begin_comment
comment|/* Sepperate external clocks */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_INT_CLK
value|0x00000002
end_define

begin_comment
comment|/* Internal clock */
end_comment

begin_define
define|#
directive|define
name|SR_PCR
value|0x00
end_define

begin_comment
comment|/* RW, PC Control Register */
end_comment

begin_define
define|#
directive|define
name|SR_BAR
value|0x02
end_define

begin_comment
comment|/* RW, Base Address Register */
end_comment

begin_define
define|#
directive|define
name|SR_PSR
value|0x04
end_define

begin_comment
comment|/* RW, Page Scan Register */
end_comment

begin_define
define|#
directive|define
name|SR_MCR
value|0x06
end_define

begin_comment
comment|/* RW, Modem Control Register */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_SCARUN
value|0x01
end_define

begin_comment
comment|/* !Reset */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_EN_VPM
value|0x02
end_define

begin_comment
comment|/* Running above 1M */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_MEM_WIN
value|0x04
end_define

begin_comment
comment|/* Open memory window */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_ISA16
value|0x08
end_define

begin_comment
comment|/* 16 bit ISA mode */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_16M_SEL
value|0xF0
end_define

begin_comment
comment|/* A20-A23 Addresses */
end_comment

begin_define
define|#
directive|define
name|SR_PSR_PG_SEL
value|0x1F
end_define

begin_comment
comment|/* Page 0 - 31 select */
end_comment

begin_define
define|#
directive|define
name|SR_PG_MSK
value|0x1F
end_define

begin_define
define|#
directive|define
name|SR_PSR_WIN_SIZ
value|0x60
end_define

begin_comment
comment|/* Window size select */
end_comment

begin_define
define|#
directive|define
name|SR_PSR_WIN_16K
value|0x00
end_define

begin_define
define|#
directive|define
name|SR_PSR_WIN_32K
value|0x20
end_define

begin_define
define|#
directive|define
name|SR_PSR_WIN_64K
value|0x40
end_define

begin_define
define|#
directive|define
name|SR_PSR_WIN_128K
value|0x60
end_define

begin_define
define|#
directive|define
name|SR_PSR_EN_SCA_DMA
value|0x80
end_define

begin_comment
comment|/* Enable the SCA DMA */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_DTR0
value|0x01
end_define

begin_comment
comment|/* Deactivate DTR0 */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_DTR1
value|0x02
end_define

begin_comment
comment|/* Deactivate DTR1 */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_DSR0
value|0x04
end_define

begin_comment
comment|/* DSR0 Status */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_DSR1
value|0x08
end_define

begin_comment
comment|/* DSR1 Status */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_TE0
value|0x10
end_define

begin_comment
comment|/* Enable RS422 TXD */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_TE1
value|0x20
end_define

begin_comment
comment|/* Enable RS422 TXD */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_ETC0
value|0x40
end_define

begin_comment
comment|/* Enable Ext Clock out */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_ETC1
value|0x80
end_define

begin_comment
comment|/* Enable Ext Clock out */
end_comment

begin_comment
comment|/*  * RISCom/N2 PCI card.  */
end_comment

begin_define
define|#
directive|define
name|SR_FECR
value|0x0200
end_define

begin_comment
comment|/* Front End Control Register */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_ETC0
value|0x0001
end_define

begin_comment
comment|/* Enable Ext Clock out */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_ETC1
value|0x0002
end_define

begin_comment
comment|/* Enable Ext Clock out */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_TE0
value|0x0004
end_define

begin_comment
comment|/* Enable RS422 TXD */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_TE1
value|0x0008
end_define

begin_comment
comment|/* Enable RS422 TXD */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_GPO0
value|0x0010
end_define

begin_comment
comment|/* General Purpose Output */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_GPO1
value|0x0020
end_define

begin_comment
comment|/* General Purpose Output */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_DTR0
value|0x0040
end_define

begin_comment
comment|/* 0 for active, 1 for inactive */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_DTR1
value|0x0080
end_define

begin_comment
comment|/* 0 for active, 1 for inactive */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_DSR0
value|0x0100
end_define

begin_comment
comment|/* DSR0 Status */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_ID0
value|0x0E00
end_define

begin_comment
comment|/* ID of channel 0 */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_DSR1
value|0x1000
end_define

begin_comment
comment|/* DSR1 Status */
end_comment

begin_define
define|#
directive|define
name|SR_FECR_ID1
value|0xE000
end_define

begin_comment
comment|/* ID of channel 1 */
end_comment

begin_define
define|#
directive|define
name|SR_FE_ID_V35
value|0x00
end_define

begin_comment
comment|/* V.35 Interface */
end_comment

begin_define
define|#
directive|define
name|SR_FE_ID_RS232
value|0x01
end_define

begin_comment
comment|/* RS232 Interface */
end_comment

begin_define
define|#
directive|define
name|SR_FE_ID_TEST
value|0x02
end_define

begin_comment
comment|/* Test Board */
end_comment

begin_define
define|#
directive|define
name|SR_FE_ID_RS422
value|0x03
end_define

begin_comment
comment|/* RS422 Interface */
end_comment

begin_define
define|#
directive|define
name|SR_FE_ID_HSSI
value|0x05
end_define

begin_comment
comment|/* HSSI Interface */
end_comment

begin_define
define|#
directive|define
name|SR_FE_ID_X21
value|0x06
end_define

begin_comment
comment|/* X.21 Interface */
end_comment

begin_define
define|#
directive|define
name|SR_FE_ID_NONE
value|0x07
end_define

begin_comment
comment|/* No card present */
end_comment

begin_define
define|#
directive|define
name|SR_FE_ID0_SHFT
value|9
end_define

begin_define
define|#
directive|define
name|SR_FE_ID1_SHFT
value|13
end_define

begin_comment
comment|/*  * These macros are used to hide the difference between the way the  * ISA N2 cards and the PCI N2 cards access the Hitachi 64570 SCA.  */
end_comment

begin_define
define|#
directive|define
name|SRC_GET8
parameter_list|(
name|hc
parameter_list|,
name|off
parameter_list|)
value|(*hc->src_get8)(hc,(uintptr_t)&off)
end_define

begin_define
define|#
directive|define
name|SRC_GET16
parameter_list|(
name|hc
parameter_list|,
name|off
parameter_list|)
value|(*hc->src_get16)(hc,(uintptr_t)&off)
end_define

begin_define
define|#
directive|define
name|SRC_PUT8
parameter_list|(
name|hc
parameter_list|,
name|off
parameter_list|,
name|d
parameter_list|)
value|(*hc->src_put8)(hc,(uintptr_t)&off,d)
end_define

begin_define
define|#
directive|define
name|SRC_PUT16
parameter_list|(
name|hc
parameter_list|,
name|off
parameter_list|,
name|d
parameter_list|)
value|(*hc->src_put16)(hc,(uintptr_t)&off,d)
end_define

begin_comment
comment|/*  * These macros enable/disable the DPRAM and select the correct  * DPRAM page.  */
end_comment

begin_define
define|#
directive|define
name|SRC_GET_WIN
parameter_list|(
name|addr
parameter_list|)
value|((addr>> SRC_WIN_SHFT)& SR_PG_MSK)
end_define

begin_define
define|#
directive|define
name|SRC_SET_ON
parameter_list|(
name|hc
parameter_list|)
value|sr_outb(hc, SR_PCR,			     \ 					SR_PCR_MEM_WIN | sr_inb(hc, SR_PCR))
end_define

begin_define
define|#
directive|define
name|SRC_SET_MEM
parameter_list|(
name|hc
parameter_list|,
name|win
parameter_list|)
value|sr_outb(hc, SR_PSR, SRC_GET_WIN(win) |	     \ 					(sr_inb(hc, SR_PSR)& ~SR_PG_MSK))
end_define

begin_define
define|#
directive|define
name|SRC_SET_OFF
parameter_list|(
name|hc
parameter_list|)
value|sr_outb(hc, SR_PCR,			     \ 					~SR_PCR_MEM_WIN& sr_inb(hc, SR_PCR))
end_define

begin_comment
comment|/*  * Define the hardware (card information) structure needed to keep  * track of the device itself... There is only one per card.  */
end_comment

begin_struct
struct|struct
name|sr_hardc
block|{
name|struct
name|sr_softc
modifier|*
name|sc
decl_stmt|;
comment|/* software channels */
name|int
name|cunit
decl_stmt|;
comment|/* card w/in system */
name|u_short
name|iobase
decl_stmt|;
comment|/* I/O Base Address */
name|int
name|cardtype
decl_stmt|;
name|int
name|numports
decl_stmt|;
comment|/* # of ports on cd */
name|int
name|mempages
decl_stmt|;
name|u_int
name|memsize
decl_stmt|;
comment|/* DPRAM size: bytes */
name|u_int
name|winmsk
decl_stmt|;
name|vm_offset_t
name|mem_pstart
decl_stmt|;
comment|/* start of buffer */
name|caddr_t
name|mem_start
decl_stmt|;
comment|/* start of DP RAM */
name|caddr_t
name|mem_end
decl_stmt|;
comment|/* end of DP RAM */
name|sca_regs
modifier|*
name|sca
decl_stmt|;
comment|/* register array */
name|bus_space_tag_t
name|bt_ioport
decl_stmt|;
name|bus_space_tag_t
name|bt_memory
decl_stmt|;
name|bus_space_handle_t
name|bh_ioport
decl_stmt|;
name|bus_space_handle_t
name|bh_memory
decl_stmt|;
name|int
name|rid_ioport
decl_stmt|;
name|int
name|rid_memory
decl_stmt|;
name|int
name|rid_plx_memory
decl_stmt|;
name|int
name|rid_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_ioport
decl_stmt|;
comment|/* resource for port range */
name|struct
name|resource
modifier|*
name|res_memory
decl_stmt|;
comment|/* resource for mem range */
name|struct
name|resource
modifier|*
name|res_plx_memory
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_irq
decl_stmt|;
comment|/* resource for irq range */
name|void
modifier|*
name|intr_cookie
decl_stmt|;
comment|/* 	 * We vectorize the following functions to allow re-use between the 	 * ISA card's needs and those of the PCI card. 	 */
name|void
function_decl|(
modifier|*
name|src_put8
function_decl|)
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|src_put16
function_decl|)
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
name|u_int
function_decl|(
modifier|*
name|src_get8
function_decl|)
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
name|u_int
function_decl|(
modifier|*
name|src_get16
function_decl|)
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|sr_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|sr_allocate_ioport
parameter_list|(
name|device_t
name|device
parameter_list|,
name|int
name|rid
parameter_list|,
name|u_long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_allocate_irq
parameter_list|(
name|device_t
name|device
parameter_list|,
name|int
name|rid
parameter_list|,
name|u_long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_allocate_memory
parameter_list|(
name|device_t
name|device
parameter_list|,
name|int
name|rid
parameter_list|,
name|u_long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_allocate_plx_memory
parameter_list|(
name|device_t
name|device
parameter_list|,
name|int
name|rid
parameter_list|,
name|u_long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_deallocate_resources
parameter_list|(
name|device_t
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_attach
parameter_list|(
name|device_t
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_detach
parameter_list|(
name|device_t
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sr_inb
parameter_list|(
name|hc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((hc)->bt_ioport, (hc)->bh_ioport, (port))
end_define

begin_define
define|#
directive|define
name|sr_outb
parameter_list|(
name|hc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((hc)->bt_ioport, (hc)->bh_ioport, (port), (value))
end_define

begin_define
define|#
directive|define
name|sr_read_fecr
parameter_list|(
name|hc
parameter_list|)
define|\
value|bus_space_read_4((hc)->bt_memory, (hc)->bh_memory, SR_FECR)
end_define

begin_define
define|#
directive|define
name|sr_write_fecr
parameter_list|(
name|hc
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4((hc)->bt_memory, (hc)->bh_memory, SR_FECR, (value))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_SRREGS_H_ */
end_comment

end_unit

