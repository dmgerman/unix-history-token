begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Tim L. Tucker.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_wereg.h	7.1 (Berkeley) 5/9/91  *  * PATCHES MAGIC                LEVEL   PATCH THAT GOT US HERE  * --------------------         -----   ----------------------  * CURRENT PATCH LEVEL:         1       00100  * --------------------         -----   ----------------------  *  * 20 Sep 92	Barry Lustig		WD8013 16 bit mode -- enable  *						with "options WD8013".  */
end_comment

begin_comment
comment|/*  * Western Digital 8003 ethernet/starlan adapter   */
end_comment

begin_comment
comment|/*  * Memory Select Register (MSR)  */
end_comment

begin_union
union|union
name|we_mem_sel
block|{
struct|struct
name|memory_decode
block|{
name|u_char
name|msd_addr
range|:
literal|6
decl_stmt|,
comment|/* Memory decode bits		*/
name|msd_enable
range|:
literal|1
decl_stmt|,
comment|/* Memory (RAM) enable		*/
name|msd_reset
range|:
literal|1
decl_stmt|;
comment|/* Software reset 		*/
block|}
name|msd_decode
struct|;
define|#
directive|define
name|ms_addr
value|msd_decode.msd_addr
define|#
directive|define
name|ms_enable
value|msd_decode.msd_enable
define|#
directive|define
name|ms_reset
value|msd_decode.msd_reset
name|u_char
name|ms_byte
decl_stmt|;
comment|/* entire byte			*/
block|}
union|;
end_union

begin_comment
comment|/* 20 Sep 92*/
end_comment

begin_comment
comment|/*  * LA Address Register (LAAR)  */
end_comment

begin_union
union|union
name|we_laar
block|{
struct|struct
name|lan_addr_reg
block|{
name|u_char
name|addr_l19_b
range|:
literal|1
decl_stmt|,
comment|/* Address Line 19 for enabling    */
comment|/* 16 bit NIC access to shared RAM */
name|unused_b
range|:
literal|5
decl_stmt|,
comment|/* unused (or unknown) bits        */
name|lan_16_en_b
range|:
literal|1
decl_stmt|,
comment|/* Enables 16bit shrd RAM for LAN  */
name|mem_16_en_b
range|:
literal|1
decl_stmt|;
comment|/* Enables 16bit shrd RAM for host */
block|}
name|laar_decode
struct|;
define|#
directive|define
name|addr_l19
value|laar_decode.addr_l19_b
define|#
directive|define
name|lan_16_en
value|laar_decode.lan_16_en_b
define|#
directive|define
name|mem_16_en
value|laar_decode.mem_16_en_b
name|u_char
name|laar_byte
decl_stmt|;
comment|/* entire byte                  */
block|}
union|;
end_union

begin_comment
comment|/*  * receive ring discriptor  *  * The National Semiconductor DS8390 Network interface controller uses  * the following receive ring headers.  The way this works is that the  * memory on the interface card is chopped up into 256 bytes blocks.  * A contiguous portion of those blocks are marked for receive packets  * by setting start and end block #'s in the NIC.  For each packet that  * is put into the receive ring, one of these headers (4 bytes each) is  * tacked onto the front.  */
end_comment

begin_struct
struct|struct
name|we_ring
block|{
struct|struct
name|wer_status
block|{
comment|/* received packet status	*/
name|u_char
name|rs_prx
range|:
literal|1
decl_stmt|,
comment|/* packet received intack	*/
name|rs_crc
range|:
literal|1
decl_stmt|,
comment|/* crc error		*/
name|rs_fae
range|:
literal|1
decl_stmt|,
comment|/* frame alignment error	*/
name|rs_fo
range|:
literal|1
decl_stmt|,
comment|/* fifo overrun		*/
name|rs_mpa
range|:
literal|1
decl_stmt|,
comment|/* packet received intack	*/
name|rs_phy
range|:
literal|1
decl_stmt|,
comment|/* packet received intack	*/
name|rs_dis
range|:
literal|1
decl_stmt|,
comment|/* packet received intack	*/
name|rs_dfr
range|:
literal|1
decl_stmt|;
comment|/* packet received intack	*/
block|}
name|we_rcv_status
struct|;
comment|/* received packet status	*/
name|u_char
name|we_next_packet
decl_stmt|;
comment|/* pointer to next packet	*/
name|u_short
name|we_count
decl_stmt|;
comment|/* bytes in packet (length + 4)	*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command word definition  */
end_comment

begin_union
union|union
name|we_command
block|{
struct|struct
name|command_decode
block|{
name|u_char
name|csd_stp
range|:
literal|1
decl_stmt|,
comment|/* STOP!			*/
name|csd_sta
range|:
literal|1
decl_stmt|,
comment|/* START!			*/
name|csd_txp
range|:
literal|1
decl_stmt|,
comment|/* Transmit packet		*/
name|csd_rd
range|:
literal|3
decl_stmt|,
comment|/* Remote DMA command		*/
name|csd_ps
range|:
literal|2
decl_stmt|;
comment|/* Page select			*/
block|}
name|csd_decode
struct|;
define|#
directive|define
name|cs_stp
value|csd_decode.csd_stp
define|#
directive|define
name|cs_sta
value|csd_decode.csd_sta
define|#
directive|define
name|cs_txp
value|csd_decode.csd_txp
define|#
directive|define
name|cs_rd
value|csd_decode.csd_rd
define|#
directive|define
name|cs_ps
value|csd_decode.csd_ps
name|u_char
name|cs_byte
decl_stmt|;
comment|/* entire command byte		*/
block|}
union|;
end_union

begin_comment
comment|/*  * Interrupt status definition  */
end_comment

begin_union
union|union
name|we_interrupt
block|{
struct|struct
name|interrupt_decode
block|{
name|u_char
name|isd_prx
range|:
literal|1
decl_stmt|,
comment|/* Packet received		*/
name|isd_ptx
range|:
literal|1
decl_stmt|,
comment|/* Packet transmitted		*/
name|isd_rxe
range|:
literal|1
decl_stmt|,
comment|/* Receive error		*/
name|isd_txe
range|:
literal|1
decl_stmt|,
comment|/* Transmit error		*/
name|isd_ovw
range|:
literal|1
decl_stmt|,
comment|/* Overwrite warning		*/
name|isd_cnt
range|:
literal|1
decl_stmt|,
comment|/* Counter overflow		*/
name|isd_rdc
range|:
literal|1
decl_stmt|,
comment|/* Remote DMA complete		*/
name|isd_rst
range|:
literal|1
decl_stmt|;
comment|/* Reset status			*/
block|}
name|isd_decode
struct|;
define|#
directive|define
name|is_prx
value|isd_decode.isd_prx
define|#
directive|define
name|is_ptx
value|isd_decode.isd_ptx
define|#
directive|define
name|is_rxe
value|isd_decode.isd_rxe
define|#
directive|define
name|is_txe
value|isd_decode.isd_txe
define|#
directive|define
name|is_ovw
value|isd_decode.isd_ovw
define|#
directive|define
name|is_cnt
value|isd_decode.isd_cnt
define|#
directive|define
name|is_rdc
value|isd_decode.isd_rdc
define|#
directive|define
name|is_rst
value|isd_decode.isd_rst
name|u_char
name|is_byte
decl_stmt|;
comment|/* entire interrupt byte	*/
block|}
union|;
end_union

begin_comment
comment|/*  * Status word definition (transmit)  */
end_comment

begin_union
union|union
name|wet_status
block|{
struct|struct
name|tstat
block|{
name|u_char
name|tsd_ptx
range|:
literal|1
decl_stmt|,
comment|/* Packet transmitted intack	*/
name|tsd_dfr
range|:
literal|1
decl_stmt|,
comment|/* Non deferred transmition	*/
name|tsd_col
range|:
literal|1
decl_stmt|,
comment|/* Transmit Collided		*/
name|tsd_abt
range|:
literal|1
decl_stmt|,
comment|/* Transmit Aborted (coll> 16)	*/
name|tsd_crs
range|:
literal|1
decl_stmt|,
comment|/* Carrier Sense Lost		*/
name|tsd_fu
range|:
literal|1
decl_stmt|,
comment|/* Fifo Underrun		*/
name|tsd_chd
range|:
literal|1
decl_stmt|,
comment|/* CD Heartbeat			*/
name|tsd_owc
range|:
literal|1
decl_stmt|;
comment|/* Out of Window Collision	*/
block|}
name|tsd_decode
struct|;
define|#
directive|define
name|ts_ptx
value|tsd_decode.tsd_ptx
define|#
directive|define
name|ts_dfr
value|tsd_decode.tsd_dfr
define|#
directive|define
name|ts_col
value|tsd_decode.tsd_col
define|#
directive|define
name|ts_abt
value|tsd_decode.tsd_abt
define|#
directive|define
name|ts_crs
value|tsd_decode.tsd_crs
define|#
directive|define
name|ts_fu
value|tsd_decode.tsd_fu
define|#
directive|define
name|ts_chd
value|tsd_decode.tsd_chd
define|#
directive|define
name|ts_owc
value|tsd_decode.tsd_owc
name|u_char
name|ts_byte
decl_stmt|;
comment|/* entire transmit byte		*/
block|}
union|;
end_union

begin_comment
comment|/*  * General constant definitions  */
end_comment

begin_comment
comment|/* Bits in the REGE register */
end_comment

begin_define
define|#
directive|define
name|WD_MICROCHANEL
value|0x80
end_define

begin_comment
comment|/* Microchannel bus (vs. isa) */
end_comment

begin_define
define|#
directive|define
name|WD_LARGERAM
value|0x40
end_define

begin_comment
comment|/* Large RAM */
end_comment

begin_define
define|#
directive|define
name|WD_SOFTCONFIG
value|0x20
end_define

begin_comment
comment|/* Soft config */
end_comment

begin_define
define|#
directive|define
name|WD_REVMASK
value|0x1e
end_define

begin_comment
comment|/* Revision mask */
end_comment

begin_define
define|#
directive|define
name|WD_ETHERNET
value|0x01
end_define

begin_comment
comment|/* Ethernet (vs. Starlan) */
end_comment

begin_define
define|#
directive|define
name|WD_CHECKSUM
value|0xFF
end_define

begin_comment
comment|/* Checksum byte		*/
end_comment

begin_define
define|#
directive|define
name|WD_PAGE_SIZE
value|256
end_define

begin_comment
comment|/* Size of RAM pages in bytes	*/
end_comment

begin_define
define|#
directive|define
name|WD_TXBUF_SIZE
value|6
end_define

begin_comment
comment|/* Size of TX buffer in pages	*/
end_comment

begin_define
define|#
directive|define
name|WD_ROM_OFFSET
value|8
end_define

begin_comment
comment|/* i/o base offset to ROM	*/
end_comment

begin_define
define|#
directive|define
name|WD_IO_PORTS
value|32
end_define

begin_comment
comment|/* # of i/o addresses used	*/
end_comment

begin_define
define|#
directive|define
name|WD_NIC_OFFSET
value|16
end_define

begin_comment
comment|/* i/o base offset to NIC	*/
end_comment

begin_comment
comment|/*  * Page register offset values  */
end_comment

begin_define
define|#
directive|define
name|WD_P0_COMMAND
value|0x00
end_define

begin_comment
comment|/* Command register 		*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_PSTART
value|0x01
end_define

begin_comment
comment|/* Page Start register		*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_PSTOP
value|0x02
end_define

begin_comment
comment|/* Page Stop register		*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_BNRY
value|0x03
end_define

begin_comment
comment|/* Boundary Pointer		*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_TSR
value|0x04
end_define

begin_comment
comment|/* Transmit Status (read-only)	*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_TPSR
value|WD_P0_TSR
end_define

begin_comment
comment|/* Transmit Page (write-only)	*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_TBCR0
value|0x05
end_define

begin_comment
comment|/* Transmit Byte count, low  WO	*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_TBCR1
value|0x06
end_define

begin_comment
comment|/* Transmit Byte count, high WO	*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_ISR
value|0x07
end_define

begin_comment
comment|/* Interrupt status register	*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_RBCR0
value|0x0A
end_define

begin_comment
comment|/* Remote byte count low     WO	*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_RBCR1
value|0x0B
end_define

begin_comment
comment|/* Remote byte count high    WO	*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_RSR
value|0x0C
end_define

begin_comment
comment|/* Receive status            RO	*/
end_comment

begin_define
define|#
directive|define
name|WD_P0_RCR
value|WD_P0_RSR
end_define

begin_comment
comment|/* Receive configuration     WO */
end_comment

begin_define
define|#
directive|define
name|WD_P0_TCR
value|0x0D
end_define

begin_comment
comment|/* Transmit configuration    WO */
end_comment

begin_define
define|#
directive|define
name|WD_P0_DCR
value|0x0E
end_define

begin_comment
comment|/* Data configuration	     WO */
end_comment

begin_define
define|#
directive|define
name|WD_P0_IMR
value|0x0F
end_define

begin_comment
comment|/* Interrupt masks	     WO	*/
end_comment

begin_define
define|#
directive|define
name|WD_P1_COMMAND
value|0x00
end_define

begin_comment
comment|/* Command register 		*/
end_comment

begin_define
define|#
directive|define
name|WD_P1_PAR0
value|0x01
end_define

begin_comment
comment|/* Physical address register 0	*/
end_comment

begin_define
define|#
directive|define
name|WD_P1_PAR1
value|0x02
end_define

begin_comment
comment|/* Physical address register 1	*/
end_comment

begin_define
define|#
directive|define
name|WD_P1_PAR2
value|0x03
end_define

begin_comment
comment|/* Physical address register 2	*/
end_comment

begin_define
define|#
directive|define
name|WD_P1_PAR3
value|0x04
end_define

begin_comment
comment|/* Physical address register 3	*/
end_comment

begin_define
define|#
directive|define
name|WD_P1_PAR4
value|0x05
end_define

begin_comment
comment|/* Physical address register 4	*/
end_comment

begin_define
define|#
directive|define
name|WD_P1_PAR5
value|0x06
end_define

begin_comment
comment|/* Physical address register 5	*/
end_comment

begin_define
define|#
directive|define
name|WD_P1_CURR
value|0x07
end_define

begin_comment
comment|/* Current page (receive unit)  */
end_comment

begin_define
define|#
directive|define
name|WD_P1_MAR0
value|0x08
end_define

begin_comment
comment|/* Multicast address register 0	*/
end_comment

begin_comment
comment|/*  * Configuration constants (receive unit)  */
end_comment

begin_define
define|#
directive|define
name|WD_R_SEP
value|0x01
end_define

begin_comment
comment|/* Save error packets		*/
end_comment

begin_define
define|#
directive|define
name|WD_R_AR
value|0x02
end_define

begin_comment
comment|/* Accept Runt packets		*/
end_comment

begin_define
define|#
directive|define
name|WD_R_AB
value|0x04
end_define

begin_comment
comment|/* Accept Broadcast packets	*/
end_comment

begin_define
define|#
directive|define
name|WD_R_AM
value|0x08
end_define

begin_comment
comment|/* Accept Multicast packets	*/
end_comment

begin_define
define|#
directive|define
name|WD_R_PRO
value|0x10
end_define

begin_comment
comment|/* Promiscuous physical		*/
end_comment

begin_define
define|#
directive|define
name|WD_R_MON
value|0x20
end_define

begin_comment
comment|/* Monitor mode			*/
end_comment

begin_define
define|#
directive|define
name|WD_R_RES1
value|0x40
end_define

begin_comment
comment|/* reserved...			*/
end_comment

begin_define
define|#
directive|define
name|WD_R_RES2
value|0x80
end_define

begin_comment
comment|/* reserved...			*/
end_comment

begin_define
define|#
directive|define
name|WD_R_CONFIG
value|(WD_R_AB)
end_define

begin_comment
comment|/*  * Configuration constants (transmit unit)  */
end_comment

begin_define
define|#
directive|define
name|WD_T_CRC
value|0x01
end_define

begin_comment
comment|/* Inhibit CRC			*/
end_comment

begin_define
define|#
directive|define
name|WD_T_LB0
value|0x02
end_define

begin_comment
comment|/* Encoded Loopback Control	*/
end_comment

begin_define
define|#
directive|define
name|WD_T_LB1
value|0x04
end_define

begin_comment
comment|/* Encoded Loopback Control	*/
end_comment

begin_define
define|#
directive|define
name|WD_T_ATD
value|0x08
end_define

begin_comment
comment|/* Auto Transmit Disable	*/
end_comment

begin_define
define|#
directive|define
name|WD_T_OFST
value|0x10
end_define

begin_comment
comment|/* Collision Offset Enable	*/
end_comment

begin_define
define|#
directive|define
name|WD_T_RES1
value|0x20
end_define

begin_comment
comment|/* reserved...			*/
end_comment

begin_define
define|#
directive|define
name|WD_T_RES2
value|0x40
end_define

begin_comment
comment|/* reserved...			*/
end_comment

begin_define
define|#
directive|define
name|WD_T_RES3
value|0x80
end_define

begin_comment
comment|/* reserved...			*/
end_comment

begin_define
define|#
directive|define
name|WD_T_CONFIG
value|(0)
end_define

begin_comment
comment|/*  * Configuration constants (data unit)  */
end_comment

begin_define
define|#
directive|define
name|WD_D_WTS
value|0x01
end_define

begin_comment
comment|/* Word Transfer Select		*/
end_comment

begin_define
define|#
directive|define
name|WD_D_BOS
value|0x02
end_define

begin_comment
comment|/* Byte Order Select		*/
end_comment

begin_define
define|#
directive|define
name|WD_D_LAS
value|0x04
end_define

begin_comment
comment|/* Long Address Select		*/
end_comment

begin_define
define|#
directive|define
name|WD_D_BMS
value|0x08
end_define

begin_comment
comment|/* Burst Mode Select		*/
end_comment

begin_define
define|#
directive|define
name|WD_D_AR
value|0x10
end_define

begin_comment
comment|/* Autoinitialize Remote	*/
end_comment

begin_define
define|#
directive|define
name|WD_D_FT0
value|0x20
end_define

begin_comment
comment|/* Fifo Threshold Select	*/
end_comment

begin_define
define|#
directive|define
name|WD_D_FT1
value|0x40
end_define

begin_comment
comment|/* Fifo Threshold Select	*/
end_comment

begin_define
define|#
directive|define
name|WD_D_RES
value|0x80
end_define

begin_comment
comment|/* reserved...			*/
end_comment

begin_define
define|#
directive|define
name|WD_D_CONFIG
value|(WD_D_FT1|WD_D_BMS)
end_define

begin_define
define|#
directive|define
name|WD_D_CONFIG16
value|(WD_D_FT1|WD_D_BMS|WD_D_LAS|WD_D_WTS)
end_define

begin_comment
comment|/* 20 Sep 92*/
end_comment

begin_comment
comment|/*  * Configuration constants (interrupt mask register)  */
end_comment

begin_define
define|#
directive|define
name|WD_I_PRXE
value|0x01
end_define

begin_comment
comment|/* Packet received enable	*/
end_comment

begin_define
define|#
directive|define
name|WD_I_PTXE
value|0x02
end_define

begin_comment
comment|/* Packet transmitted enable	*/
end_comment

begin_define
define|#
directive|define
name|WD_I_RXEE
value|0x04
end_define

begin_comment
comment|/* Receive error enable		*/
end_comment

begin_define
define|#
directive|define
name|WD_I_TXEE
value|0x08
end_define

begin_comment
comment|/* Transmit error enable	*/
end_comment

begin_define
define|#
directive|define
name|WD_I_OVWE
value|0x10
end_define

begin_comment
comment|/* Overwrite warning enable	*/
end_comment

begin_define
define|#
directive|define
name|WD_I_CNTE
value|0x20
end_define

begin_comment
comment|/* Counter overflow enable	*/
end_comment

begin_define
define|#
directive|define
name|WD_I_RDCE
value|0x40
end_define

begin_comment
comment|/* Dma complete enable		*/
end_comment

begin_define
define|#
directive|define
name|WD_I_RES
value|0x80
end_define

begin_comment
comment|/* reserved...			*/
end_comment

begin_define
define|#
directive|define
name|WD_I_CONFIG
value|(WD_I_PRXE|WD_I_PTXE|WD_I_RXEE|WD_I_TXEE)
end_define

end_unit

