begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|IF_RDPREG_H
end_ifndef

begin_define
define|#
directive|define
name|IF_RDPREG_H
value|1
end_define

begin_comment
comment|/*  * Copyright (c) 1998 Joerg Wunsch  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPERS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE DEVELOPERS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Part of the definitions here has been copied over from the REDP  * packet driver's REDPPD.INC file.  This provides us with the same  * set of acronyms as the packet driver is using.  *  * The packet driver had no copyright, and is believed to be in the  * public domain.  The author seems to be someone who calls himself  * "Chiu", so that's the only acknowledgment i can give here.  * Supposedly the author was someone from RealTek.  */
end_comment

begin_comment
comment|/*  * We're hanging upon an LPT port, thus suck in the lpt defs as well.  */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/lptreg.h>
end_include

begin_struct
struct|struct
name|rdphdr
block|{
comment|/* RTL8002 header that is prepended to the actual packet */
name|u_char
name|unused2
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|pktlen
decl_stmt|;
name|u_char
name|status
decl_stmt|;
comment|/* copy of RSR for this packet */
name|u_char
name|unused3
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  *    8 Data Modes are provided:  *  * 	+--------+---------------+-------------+  * 	|  Mode  |     Read	 |    Write    |  * 	+--------+---------------+-------------+  * 	|   0	 |   LptCtrl	 |   LptData   |  * 	+--------+---------------+-------------+  * 	|   1	 |   LptCtrl	 |   LptCtrl   |  * 	+--------+---------------+-------------+  * 	|   2	 |   LptCtrl*2	 |   LptData   |  * 	+--------+---------------+-------------+  * 	|   3	 |   LptCtrl*2	 |   LptCtrl   |  * 	+--------+---------------+-------------+  * 	|   4	 |   LptData	 |   LptData   |  * 	+--------+---------------+-------------+  * 	|   5	 |   LptData	 |   LptCtrl   |  * 	+--------+---------------+-------------+  * 	|   6	 |   LptData*2	 |   LptData   |  * 	+--------+---------------+-------------+  * 	|   7	 |   LptData*2	 |   LptCtrl   |  * 	+--------+---------------+-------------+  *  * Right now, this driver only implements mode 0 (which ought to work  * on any standard parallel interface).  *  */
end_comment

begin_comment
comment|/*  * Page 0 of EPLC registers  */
end_comment

begin_define
define|#
directive|define
name|IDR0
value|0x00
end_define

begin_comment
comment|/* Ethernet ID register (R/W) */
end_comment

begin_define
define|#
directive|define
name|IDR1
value|0x01
end_define

begin_define
define|#
directive|define
name|IDR2
value|0x02
end_define

begin_define
define|#
directive|define
name|IDR3
value|0x03
end_define

begin_define
define|#
directive|define
name|IDR4
value|0x04
end_define

begin_define
define|#
directive|define
name|IDR5
value|0x05
end_define

begin_define
define|#
directive|define
name|TBCR0
value|0x06
end_define

begin_comment
comment|/* transmit byte count (W), 11 bits valid */
end_comment

begin_define
define|#
directive|define
name|TBCR1
value|0x07
end_define

begin_define
define|#
directive|define
name|TSR
value|0x08
end_define

begin_comment
comment|/* transmit status (R), cleared upon next tx */
end_comment

begin_define
define|#
directive|define
name|TSR_TOK
value|1
end_define

begin_comment
comment|/* transmit OK */
end_comment

begin_define
define|#
directive|define
name|TSR_TABT
value|2
end_define

begin_comment
comment|/* transmit aborted (excessive collisions) */
end_comment

begin_define
define|#
directive|define
name|TSR_COL
value|4
end_define

begin_comment
comment|/* collision detected */
end_comment

begin_define
define|#
directive|define
name|TSR_CDH
value|8
end_define

begin_comment
comment|/* CD heartbeat detected */
end_comment

begin_define
define|#
directive|define
name|RSR
value|0x09
end_define

begin_comment
comment|/* 				 * receiver status (R), cleared upon next 				 * received packet (but stored in rx buffer 				 * header anyway) 				 */
end_comment

begin_define
define|#
directive|define
name|RSR_ROK
value|1
end_define

begin_comment
comment|/* receive OK */
end_comment

begin_define
define|#
directive|define
name|RSR_CRC
value|2
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|RSR_FA
value|4
end_define

begin_comment
comment|/* frame alignment error (not multiple of 8) */
end_comment

begin_define
define|#
directive|define
name|RSR_BUFO
value|0x10
end_define

begin_comment
comment|/* rx buffer overflow, packet discarded */
end_comment

begin_define
define|#
directive|define
name|RSR_PUN
value|0x20
end_define

begin_comment
comment|/* packet count underflow (jump command issued 				 * but rx buffer was empty) */
end_comment

begin_define
define|#
directive|define
name|RSR_POV
value|0x40
end_define

begin_comment
comment|/* packet count overflow (more than 254 (?) 				 * packets still in buffer) */
end_comment

begin_define
define|#
directive|define
name|ISR
value|0x0A
end_define

begin_comment
comment|/* interrupt status register (R), writing 				 * clears the written bits */
end_comment

begin_define
define|#
directive|define
name|ISR_TOK
value|1
end_define

begin_comment
comment|/* transmission OK (~ TSR_TOK) */
end_comment

begin_define
define|#
directive|define
name|ISR_TER
value|2
end_define

begin_comment
comment|/* transmitter error (~ TSR_TABT) */
end_comment

begin_define
define|#
directive|define
name|ISR_ROK
value|4
end_define

begin_comment
comment|/* receive OK (~ RSR_ROK) */
end_comment

begin_define
define|#
directive|define
name|ISR_RER
value|8
end_define

begin_comment
comment|/* receiver error (~ RSR_CRC|RSR_FA) */
end_comment

begin_define
define|#
directive|define
name|ISR_RBER
value|0x10
end_define

begin_comment
comment|/* rx buffer overflow (POV|PUN|BUFO) */
end_comment

begin_define
define|#
directive|define
name|IMR
value|0x0B
end_define

begin_comment
comment|/* interrupt mask register (R/W), bit as ISR */
end_comment

begin_define
define|#
directive|define
name|CMR1
value|0x0C
end_define

begin_comment
comment|/* command register 1 (R/W) */
end_comment

begin_define
define|#
directive|define
name|CMR1_BUFE
value|1
end_define

begin_comment
comment|/* (R) rx buffer empty */
end_comment

begin_define
define|#
directive|define
name|CMR1_IRQ
value|2
end_define

begin_comment
comment|/* (R) interrupt request */
end_comment

begin_define
define|#
directive|define
name|CMR1_TRA
value|4
end_define

begin_comment
comment|/* (R) transmission in progress */
end_comment

begin_comment
comment|/* (W) transmit start */
end_comment

begin_define
define|#
directive|define
name|CMR1_TE
value|0x10
end_define

begin_comment
comment|/* (R/W) transmitter enable */
end_comment

begin_define
define|#
directive|define
name|CMR1_RE
value|0x20
end_define

begin_comment
comment|/* (R/W) receiver enable */
end_comment

begin_define
define|#
directive|define
name|CMR1_RST
value|0x40
end_define

begin_comment
comment|/* (R/W) reset; sticks until reset completed */
end_comment

begin_define
define|#
directive|define
name|CMR1_RDPAC
value|1
end_define

begin_comment
comment|/* (W) `rx jump packet', prepare for reading 				 * next packet from ring buffer */
end_comment

begin_define
define|#
directive|define
name|CMR1_WRPAC
value|2
end_define

begin_comment
comment|/* (W) `tx jump packet', packet in tx buffer 				 * is complete and can be sent */
end_comment

begin_define
define|#
directive|define
name|CMR1_RETX
value|8
end_define

begin_comment
comment|/* (W) retransmit (must be accomp'ed by TRA) */
end_comment

begin_define
define|#
directive|define
name|CMR1_MUX
value|0x80
end_define

begin_comment
comment|/* (W) RTL8012: tell the printer MUX to 				 * connect the output pins to the host */
end_comment

begin_define
define|#
directive|define
name|CMR2
value|0x0D
end_define

begin_comment
comment|/* command register 2 (R/W) */
end_comment

begin_define
define|#
directive|define
name|CMR2_IRQOUT
value|1
end_define

begin_comment
comment|/* interrupt signal output enabled */
end_comment

begin_define
define|#
directive|define
name|CMR2_RAMTST
value|2
end_define

begin_comment
comment|/* enable RAM test */
end_comment

begin_define
define|#
directive|define
name|CMR2_PAGE
value|4
end_define

begin_comment
comment|/* select register page #1 */
end_comment

begin_define
define|#
directive|define
name|CMR2_IRQINV
value|8
end_define

begin_comment
comment|/* make active IRQ `low' */
end_comment

begin_define
define|#
directive|define
name|CMR2_AMbits
value|0x30
end_define

begin_comment
comment|/* address mode bits: */
end_comment

begin_define
define|#
directive|define
name|CMR2_AM_NONE
value|0x00
end_define

begin_comment
comment|/* 0: accept nothing */
end_comment

begin_define
define|#
directive|define
name|CMR2_AM_PHYS
value|0x10
end_define

begin_comment
comment|/* 1: only physical addr */
end_comment

begin_define
define|#
directive|define
name|CMR2_AM_PB
value|0x20
end_define

begin_comment
comment|/* 2: phys + broadcast */
end_comment

begin_define
define|#
directive|define
name|CMR2_AM_ALL
value|0x30
end_define

begin_comment
comment|/* 3: promiscuous */
end_comment

begin_define
define|#
directive|define
name|CMR2_LBK
value|0x40
end_define

begin_comment
comment|/* enable loopback */
end_comment

begin_define
define|#
directive|define
name|CMR2_SER
value|0x80
end_define

begin_comment
comment|/* save error packet */
end_comment

begin_define
define|#
directive|define
name|MAR
value|0x0E
end_define

begin_comment
comment|/* memory access register (?), used for 				 * remote DMA to the 8002's buffer */
end_comment

begin_define
define|#
directive|define
name|PNR
value|TBCR0
end_define

begin_comment
comment|/* received packet number (R) */
end_comment

begin_define
define|#
directive|define
name|COLR
value|TBCR1
end_define

begin_comment
comment|/* collision count (R) (4 bit valid) */
end_comment

begin_comment
comment|/*  * Page 1 of EPLC registers -- EEPROM control  */
end_comment

begin_define
define|#
directive|define
name|PCMR
value|TBCR0
end_define

begin_comment
comment|/* port command register */
end_comment

begin_comment
comment|/* bits for 93C46 control -- add HNib */
end_comment

begin_define
define|#
directive|define
name|PCMR_SK
value|0x04
end_define

begin_comment
comment|/* serial clock for EEPROM */
end_comment

begin_define
define|#
directive|define
name|PCMR_CS
value|0x02
end_define

begin_comment
comment|/* chip select for EEPROM */
end_comment

begin_define
define|#
directive|define
name|PCMR_DO
value|0x01
end_define

begin_comment
comment|/* DI to EEPROM */
end_comment

begin_comment
comment|/* EEPROM data, nibbles for 74S288, bits for 93C46 */
end_comment

begin_define
define|#
directive|define
name|PDR
value|TBCR1
end_define

begin_comment
comment|/* DO from EEPROM, only bit 0 valid for 				 * serial EEPROM */
end_comment

begin_comment
comment|/*  * The following definitionss define remote DMA command through LptCtrl  */
end_comment

begin_define
define|#
directive|define
name|ATFD
value|3
end_define

begin_comment
comment|/* ATFD bit in Lpt's Control register                */
end_comment

begin_comment
comment|/* -> ATFD bit is added for Xircom's MUX             */
end_comment

begin_define
define|#
directive|define
name|Ctrl_LNibRead
value|(0x08+ATFD)
end_define

begin_comment
comment|/* specify low  nibble               */
end_comment

begin_define
define|#
directive|define
name|Ctrl_HNibRead
value|(0+ATFD)
end_define

begin_comment
comment|/* specify high nibble               */
end_comment

begin_define
define|#
directive|define
name|Ctrl_SelData
value|(0x04+ATFD)
end_define

begin_comment
comment|/* not through LptCtrl but through   */
end_comment

begin_comment
comment|/* LptData                           */
end_comment

begin_define
define|#
directive|define
name|Ctrl_IRQEN
value|0x10
end_define

begin_comment
comment|/* set IRQEN of lpt control register */
end_comment

begin_comment
comment|/* Here define constants to construct the required read/write commands */
end_comment

begin_define
define|#
directive|define
name|WrAddr
value|0x40
end_define

begin_comment
comment|/* set address of EPLC write register   */
end_comment

begin_define
define|#
directive|define
name|RdAddr
value|0x0C0
end_define

begin_comment
comment|/* set address of EPLC read register    */
end_comment

begin_define
define|#
directive|define
name|EOR
value|0x20
end_define

begin_comment
comment|/* ORed to make 'end of read',set CSB=1 */
end_comment

begin_define
define|#
directive|define
name|EOW
value|0x0E0
end_define

begin_comment
comment|/* end of write, R/WB=A/DB=CSB=1        */
end_comment

begin_define
define|#
directive|define
name|EOC
value|0x0E0
end_define

begin_comment
comment|/* End Of r/w Command, R/WB=A/DB=CSB=1  */
end_comment

begin_define
define|#
directive|define
name|HNib
value|0x10
end_define

begin_define
define|#
directive|define
name|MkHi
parameter_list|(
name|value
parameter_list|)
value|(((value)>> 4) | HNib)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_RDPREG_H */
end_comment

end_unit

