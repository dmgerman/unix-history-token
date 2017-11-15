begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Hidetoshi Shimokawa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the acknowledgement as bellow:  *  *    This product includes software developed by K. Kobayashi and H. Shimokawa  *  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|MAX_OHCI
value|5
end_define

begin_define
define|#
directive|define
name|CROMSIZE
value|0x400
end_define

begin_struct
struct|struct
name|fw_eui64
block|{
name|uint32_t
name|hi
decl_stmt|,
name|lo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fwohci_softc
block|{
name|uint32_t
name|locator
decl_stmt|;
name|uint32_t
name|devid
decl_stmt|;
name|uint32_t
name|base_addr
decl_stmt|;
name|uint32_t
name|bus_id
decl_stmt|;
name|uint32_t
name|handle
decl_stmt|;
name|int32_t
name|state
decl_stmt|;
name|struct
name|crom_src_buf
modifier|*
name|crom_src_buf
decl_stmt|;
name|struct
name|crom_src
modifier|*
name|crom_src
decl_stmt|;
name|struct
name|crom_chunk
modifier|*
name|crom_root
decl_stmt|;
name|struct
name|fw_eui64
name|eui
decl_stmt|;
name|int
name|speed
decl_stmt|;
name|int
name|maxrec
decl_stmt|;
name|uint32_t
modifier|*
name|config_rom
decl_stmt|;
name|char
name|config_rom_buf
index|[
name|CROMSIZE
operator|*
literal|2
index|]
decl_stmt|;
comment|/* double size for alignment */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|fwohci_init
parameter_list|(
name|struct
name|fwohci_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fwohci_ibr
parameter_list|(
name|struct
name|fwohci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fwohci_poll
parameter_list|(
name|struct
name|fwohci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FWOHCI_STATE_DEAD
value|(-1)
end_define

begin_define
define|#
directive|define
name|FWOHCI_STATE_INIT
value|0
end_define

begin_define
define|#
directive|define
name|FWOHCI_STATE_ENABLED
value|1
end_define

begin_define
define|#
directive|define
name|FWOHCI_STATE_BUSRESET
value|2
end_define

begin_define
define|#
directive|define
name|FWOHCI_STATE_NORMAL
value|3
end_define

begin_define
define|#
directive|define
name|OREAD
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|)
value|(*(volatile uint32_t *)((f)->handle + (o)))
end_define

begin_define
define|#
directive|define
name|OWRITE
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|(*(volatile uint32_t *)((f)->handle + (o)) = (v))
end_define

begin_define
define|#
directive|define
name|OHCI_VERSION
value|0x00
end_define

begin_define
define|#
directive|define
name|OHCI_ATRETRY
value|0x08
end_define

begin_define
define|#
directive|define
name|OHCI_CROMHDR
value|0x18
end_define

begin_define
define|#
directive|define
name|OHCI_BUS_ID
value|0x1c
end_define

begin_define
define|#
directive|define
name|OHCI_BUS_OPT
value|0x20
end_define

begin_define
define|#
directive|define
name|OHCI_BUSIRMC
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|OHCI_BUSCMC
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|OHCI_BUSISC
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|OHCI_BUSBMC
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|OHCI_BUSPMC
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|OHCI_BUSFNC
value|OHCI_BUSIRMC | OHCI_BUSCMC | OHCI_BUSISC |\ 				OHCI_BUSBMC | OHCI_BUSPMC
end_define

begin_define
define|#
directive|define
name|OHCI_EUID_HI
value|0x24
end_define

begin_define
define|#
directive|define
name|OHCI_EUID_LO
value|0x28
end_define

begin_define
define|#
directive|define
name|OHCI_CROMPTR
value|0x34
end_define

begin_define
define|#
directive|define
name|OHCI_HCCCTL
value|0x50
end_define

begin_define
define|#
directive|define
name|OHCI_HCCCTLCLR
value|0x54
end_define

begin_define
define|#
directive|define
name|OHCI_AREQHI
value|0x100
end_define

begin_define
define|#
directive|define
name|OHCI_AREQHICLR
value|0x104
end_define

begin_define
define|#
directive|define
name|OHCI_AREQLO
value|0x108
end_define

begin_define
define|#
directive|define
name|OHCI_AREQLOCLR
value|0x10c
end_define

begin_define
define|#
directive|define
name|OHCI_PREQHI
value|0x110
end_define

begin_define
define|#
directive|define
name|OHCI_PREQHICLR
value|0x114
end_define

begin_define
define|#
directive|define
name|OHCI_PREQLO
value|0x118
end_define

begin_define
define|#
directive|define
name|OHCI_PREQLOCLR
value|0x11c
end_define

begin_define
define|#
directive|define
name|OHCI_PREQUPPER
value|0x120
end_define

begin_define
define|#
directive|define
name|OHCI_SID_BUF
value|0x64
end_define

begin_define
define|#
directive|define
name|OHCI_SID_CNT
value|0x68
end_define

begin_define
define|#
directive|define
name|OHCI_SID_ERR
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|OHCI_SID_CNT_MASK
value|0xffc
end_define

begin_define
define|#
directive|define
name|OHCI_IT_STAT
value|0x90
end_define

begin_define
define|#
directive|define
name|OHCI_IT_STATCLR
value|0x94
end_define

begin_define
define|#
directive|define
name|OHCI_IT_MASK
value|0x98
end_define

begin_define
define|#
directive|define
name|OHCI_IT_MASKCLR
value|0x9c
end_define

begin_define
define|#
directive|define
name|OHCI_IR_STAT
value|0xa0
end_define

begin_define
define|#
directive|define
name|OHCI_IR_STATCLR
value|0xa4
end_define

begin_define
define|#
directive|define
name|OHCI_IR_MASK
value|0xa8
end_define

begin_define
define|#
directive|define
name|OHCI_IR_MASKCLR
value|0xac
end_define

begin_define
define|#
directive|define
name|OHCI_LNKCTL
value|0xe0
end_define

begin_define
define|#
directive|define
name|OHCI_LNKCTLCLR
value|0xe4
end_define

begin_define
define|#
directive|define
name|OHCI_PHYACCESS
value|0xec
end_define

begin_define
define|#
directive|define
name|OHCI_CYCLETIMER
value|0xf0
end_define

begin_define
define|#
directive|define
name|OHCI_DMACTL
parameter_list|(
name|off
parameter_list|)
value|(off)
end_define

begin_define
define|#
directive|define
name|OHCI_DMACTLCLR
parameter_list|(
name|off
parameter_list|)
value|(off + 4)
end_define

begin_define
define|#
directive|define
name|OHCI_DMACMD
parameter_list|(
name|off
parameter_list|)
value|(off + 0xc)
end_define

begin_define
define|#
directive|define
name|OHCI_DMAMATCH
parameter_list|(
name|off
parameter_list|)
value|(off + 0x10)
end_define

begin_define
define|#
directive|define
name|OHCI_ATQOFF
value|0x180
end_define

begin_define
define|#
directive|define
name|OHCI_ATQCTL
value|OHCI_ATQOFF
end_define

begin_define
define|#
directive|define
name|OHCI_ATQCTLCLR
value|(OHCI_ATQOFF + 4)
end_define

begin_define
define|#
directive|define
name|OHCI_ATQCMD
value|(OHCI_ATQOFF + 0xc)
end_define

begin_define
define|#
directive|define
name|OHCI_ATQMATCH
value|(OHCI_ATQOFF + 0x10)
end_define

begin_define
define|#
directive|define
name|OHCI_ATSOFF
value|0x1a0
end_define

begin_define
define|#
directive|define
name|OHCI_ATSCTL
value|OHCI_ATSOFF
end_define

begin_define
define|#
directive|define
name|OHCI_ATSCTLCLR
value|(OHCI_ATSOFF + 4)
end_define

begin_define
define|#
directive|define
name|OHCI_ATSCMD
value|(OHCI_ATSOFF + 0xc)
end_define

begin_define
define|#
directive|define
name|OHCI_ATSMATCH
value|(OHCI_ATSOFF + 0x10)
end_define

begin_define
define|#
directive|define
name|OHCI_ARQOFF
value|0x1c0
end_define

begin_define
define|#
directive|define
name|OHCI_ARQCTL
value|OHCI_ARQOFF
end_define

begin_define
define|#
directive|define
name|OHCI_ARQCTLCLR
value|(OHCI_ARQOFF + 4)
end_define

begin_define
define|#
directive|define
name|OHCI_ARQCMD
value|(OHCI_ARQOFF + 0xc)
end_define

begin_define
define|#
directive|define
name|OHCI_ARQMATCH
value|(OHCI_ARQOFF + 0x10)
end_define

begin_define
define|#
directive|define
name|OHCI_ARSOFF
value|0x1e0
end_define

begin_define
define|#
directive|define
name|OHCI_ARSCTL
value|OHCI_ARSOFF
end_define

begin_define
define|#
directive|define
name|OHCI_ARSCTLCLR
value|(OHCI_ARSOFF + 4)
end_define

begin_define
define|#
directive|define
name|OHCI_ARSCMD
value|(OHCI_ARSOFF + 0xc)
end_define

begin_define
define|#
directive|define
name|OHCI_ARSMATCH
value|(OHCI_ARSOFF + 0x10)
end_define

begin_define
define|#
directive|define
name|OHCI_ITOFF
parameter_list|(
name|CH
parameter_list|)
value|(0x200 + 0x10 * (CH))
end_define

begin_define
define|#
directive|define
name|OHCI_ITCTL
parameter_list|(
name|CH
parameter_list|)
value|(OHCI_ITOFF(CH))
end_define

begin_define
define|#
directive|define
name|OHCI_ITCTLCLR
parameter_list|(
name|CH
parameter_list|)
value|(OHCI_ITOFF(CH) + 4)
end_define

begin_define
define|#
directive|define
name|OHCI_ITCMD
parameter_list|(
name|CH
parameter_list|)
value|(OHCI_ITOFF(CH) + 0xc)
end_define

begin_define
define|#
directive|define
name|OHCI_IROFF
parameter_list|(
name|CH
parameter_list|)
value|(0x400 + 0x20 * (CH))
end_define

begin_define
define|#
directive|define
name|OHCI_IRCTL
parameter_list|(
name|CH
parameter_list|)
value|(OHCI_IROFF(CH))
end_define

begin_define
define|#
directive|define
name|OHCI_IRCTLCLR
parameter_list|(
name|CH
parameter_list|)
value|(OHCI_IROFF(CH) + 4)
end_define

begin_define
define|#
directive|define
name|OHCI_IRCMD
parameter_list|(
name|CH
parameter_list|)
value|(OHCI_IROFF(CH) + 0xc)
end_define

begin_define
define|#
directive|define
name|OHCI_IRMATCH
parameter_list|(
name|CH
parameter_list|)
value|(OHCI_IROFF(CH) + 0x10)
end_define

end_unit

