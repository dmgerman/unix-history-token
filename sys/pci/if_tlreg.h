begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|tl_type
block|{
name|u_int16_t
name|tl_vid
decl_stmt|;
name|u_int16_t
name|tl_did
decl_stmt|;
name|char
modifier|*
name|tl_name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ThunderLAN TX/RX list format. The TX and RX lists are pretty much  * identical: the list begins with a 32-bit forward pointer which points  * at the next list in the chain, followed by 16 bits for the total  * frame size, and a 16 bit status field. This is followed by a series  * of 10 32-bit data count/data address pairs that point to the fragments  * that make up the complete frame.  */
end_comment

begin_define
define|#
directive|define
name|TL_MAXFRAGS
value|10
end_define

begin_define
define|#
directive|define
name|TL_RX_LIST_CNT
value|20
end_define

begin_define
define|#
directive|define
name|TL_TX_LIST_CNT
value|20
end_define

begin_define
define|#
directive|define
name|TL_MIN_FRAMELEN
value|64
end_define

begin_struct
struct|struct
name|tl_frag
block|{
name|u_int32_t
name|tlist_dcnt
decl_stmt|;
name|u_int32_t
name|tlist_dadr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tl_list
block|{
name|u_int32_t
name|tlist_fptr
decl_stmt|;
comment|/* phys address of next list */
name|u_int16_t
name|tlist_cstat
decl_stmt|;
comment|/* status word */
name|u_int16_t
name|tlist_frsize
decl_stmt|;
comment|/* size of data in frame */
name|struct
name|tl_frag
name|tl_frag
index|[
name|TL_MAXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is a special case of an RX list. By setting the One_Frag  * bit in the NETCONFIG register, the driver can force the ThunderLAN  * chip to use only one fragment when DMAing RX frames.  */
end_comment

begin_struct
struct|struct
name|tl_list_onefrag
block|{
name|u_int32_t
name|tlist_fptr
decl_stmt|;
name|u_int16_t
name|tlist_cstat
decl_stmt|;
name|u_int16_t
name|tlist_frsize
decl_stmt|;
name|struct
name|tl_frag
name|tl_frag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tl_list_data
block|{
name|struct
name|tl_list_onefrag
name|tl_rx_list
index|[
name|TL_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|tl_list
name|tl_tx_list
index|[
name|TL_TX_LIST_CNT
index|]
decl_stmt|;
name|unsigned
name|char
name|tl_pad
index|[
name|TL_MIN_FRAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tl_chain
block|{
name|struct
name|tl_list
modifier|*
name|tl_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tl_mbuf
decl_stmt|;
name|struct
name|tl_chain
modifier|*
name|tl_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tl_chain_onefrag
block|{
name|struct
name|tl_list_onefrag
modifier|*
name|tl_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tl_mbuf
decl_stmt|;
name|struct
name|tl_chain_onefrag
modifier|*
name|tl_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tl_chain_data
block|{
name|struct
name|tl_chain_onefrag
name|tl_rx_chain
index|[
name|TL_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|tl_chain
name|tl_tx_chain
index|[
name|TL_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|tl_chain_onefrag
modifier|*
name|tl_rx_head
decl_stmt|;
name|struct
name|tl_chain_onefrag
modifier|*
name|tl_rx_tail
decl_stmt|;
name|struct
name|tl_chain
modifier|*
name|tl_tx_head
decl_stmt|;
name|struct
name|tl_chain
modifier|*
name|tl_tx_tail
decl_stmt|;
name|struct
name|tl_chain
modifier|*
name|tl_tx_free
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tl_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* media info */
name|bus_space_handle_t
name|tl_bhandle
decl_stmt|;
name|bus_space_tag_t
name|tl_btag
decl_stmt|;
name|struct
name|tl_type
modifier|*
name|tl_dinfo
decl_stmt|;
comment|/* ThunderLAN adapter info */
name|struct
name|tl_type
modifier|*
name|tl_pinfo
decl_stmt|;
comment|/* PHY info struct */
name|u_int8_t
name|tl_ctlr
decl_stmt|;
comment|/* chip number */
name|u_int8_t
name|tl_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|tl_eeaddr
decl_stmt|;
name|u_int8_t
name|tl_phy_addr
decl_stmt|;
comment|/* PHY address */
name|u_int8_t
name|tl_tx_pend
decl_stmt|;
comment|/* TX pending */
name|u_int8_t
name|tl_want_auto
decl_stmt|;
comment|/* autoneg scheduled */
name|u_int8_t
name|tl_autoneg
decl_stmt|;
comment|/* autoneg in progress */
name|u_int16_t
name|tl_phy_sts
decl_stmt|;
comment|/* PHY status */
name|u_int16_t
name|tl_phy_vid
decl_stmt|;
comment|/* PHY vendor ID */
name|u_int16_t
name|tl_phy_did
decl_stmt|;
comment|/* PHY device ID */
name|caddr_t
name|tl_ldata_ptr
decl_stmt|;
name|struct
name|tl_list_data
modifier|*
name|tl_ldata
decl_stmt|;
comment|/* TX/RX lists and mbufs */
name|struct
name|tl_chain_data
name|tl_cdata
decl_stmt|;
name|u_int8_t
name|tl_txeoc
decl_stmt|;
name|u_int8_t
name|tl_bitrate
decl_stmt|;
name|struct
name|callout_handle
name|tl_stat_ch
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit interrupt threshold.  */
end_comment

begin_define
define|#
directive|define
name|TX_THR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TL_FLAG_FORCEDELAY
value|1
end_define

begin_define
define|#
directive|define
name|TL_FLAG_SCHEDDELAY
value|2
end_define

begin_define
define|#
directive|define
name|TL_FLAG_DELAYTIMEO
value|3
end_define

begin_comment
comment|/*  * The ThunderLAN supports up to 32 PHYs.  */
end_comment

begin_define
define|#
directive|define
name|TL_PHYADDR_MIN
value|0x00
end_define

begin_define
define|#
directive|define
name|TL_PHYADDR_MAX
value|0x1F
end_define

begin_define
define|#
directive|define
name|PHY_UNKNOWN
value|6
end_define

begin_define
define|#
directive|define
name|TL_PHYS_IDLE
value|-1
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * The ThunderLAN controller is made by Texas Instruments. The  * manual indicates that if the EEPROM checksum fails, the PCI  * vendor and device ID registers will be loaded with TI-specific  * values.  */
end_comment

begin_define
define|#
directive|define
name|TI_VENDORID
value|0x104C
end_define

begin_define
define|#
directive|define
name|TI_DEVICEID_THUNDERLAN
value|0x0500
end_define

begin_comment
comment|/*  * Known PHY Ids. According to the Level 1 documentation (which is  * very nice, incidentally), here's how they work:  *  * The PHY identifier register #1 is composed of bits 3 through 18  * of the OUI. (First 16-bit word.)  * The PHY identifier register #2 is composed of bits 19 through 24  * if the OUI.  * This is followed by 6 bits containing the manufacturer's model  * number.  * Lastly, there are 4 bits for the manufacturer's revision number.  *  * Honestly, there are a lot of these that don't make any sense; the  * only way to be really sure is to look at the data sheets.  */
end_comment

begin_comment
comment|/*  * Texas Instruments PHY identifiers  *  * The ThunderLAN manual has a curious and confusing error in it.  * In chapter 7, which describes PHYs, it says that TI PHYs have  * the following ID codes, where xx denotes a revision:  *  * 0x4000501xx			internal 10baseT PHY  * 0x4000502xx			TNETE211 100VG-AnyLan PMI  *  * The problem here is that these are not valid 32-bit hex numbers:  * there's one digit too many. My guess is that they mean the internal  * 10baseT PHY is 0x4000501x and the TNETE211 is 0x4000502x since these  * are the only numbers that make sense.  */
end_comment

begin_define
define|#
directive|define
name|TI_PHY_VENDORID
value|0x4000
end_define

begin_define
define|#
directive|define
name|TI_PHY_10BT
value|0x501F
end_define

begin_define
define|#
directive|define
name|TI_PHY_100VGPMI
value|0x502F
end_define

begin_comment
comment|/*  * These ID values are for the NS DP83840A 10/100 PHY  */
end_comment

begin_define
define|#
directive|define
name|NS_PHY_VENDORID
value|0x2000
end_define

begin_define
define|#
directive|define
name|NS_PHY_83840A
value|0x5C0F
end_define

begin_comment
comment|/*  * Level 1 10/100 PHY  */
end_comment

begin_define
define|#
directive|define
name|LEVEL1_PHY_VENDORID
value|0x7810
end_define

begin_define
define|#
directive|define
name|LEVEL1_PHY_LXT970
value|0x000F
end_define

begin_comment
comment|/*  * Intel 82555 10/100 PHY  */
end_comment

begin_define
define|#
directive|define
name|INTEL_PHY_VENDORID
value|0x0A28
end_define

begin_define
define|#
directive|define
name|INTEL_PHY_82555
value|0x015F
end_define

begin_comment
comment|/*  * SEEQ 80220 10/100 PHY  */
end_comment

begin_define
define|#
directive|define
name|SEEQ_PHY_VENDORID
value|0x0016
end_define

begin_define
define|#
directive|define
name|SEEQ_PHY_80220
value|0xF83F
end_define

begin_comment
comment|/*  * These are the PCI vendor and device IDs for Compaq ethernet  * adapters based on the ThunderLAN controller.  */
end_comment

begin_define
define|#
directive|define
name|COMPAQ_VENDORID
value|0x0E11
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETEL_10_100
value|0xAE32
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETEL_UNKNOWN
value|0xAE33
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETEL_10
value|0xAE34
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETFLEX_3P_INTEGRATED
value|0xAE35
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETEL_10_100_DUAL
value|0xAE40
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETEL_10_100_PROLIANT
value|0xAE43
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETEL_10_100_EMBEDDED
value|0xB011
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETEL_10_T2_UTP_COAX
value|0xB012
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETEL_10_100_TX_UTP
value|0xB030
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETFLEX_3P
value|0xF130
end_define

begin_define
define|#
directive|define
name|COMPAQ_DEVICEID_NETFLEX_3P_BNC
value|0xF150
end_define

begin_comment
comment|/*  * These are the PCI vendor and device IDs for Olicom  * adapters based on the ThunderLAN controller.  */
end_comment

begin_define
define|#
directive|define
name|OLICOM_VENDORID
value|0x108D
end_define

begin_define
define|#
directive|define
name|OLICOM_DEVICEID_OC2183
value|0x0013
end_define

begin_define
define|#
directive|define
name|OLICOM_DEVICEID_OC2325
value|0x0012
end_define

begin_define
define|#
directive|define
name|OLICOM_DEVICEID_OC2326
value|0x0014
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base  */
end_comment

begin_define
define|#
directive|define
name|TL_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|TL_PCI_LOMEM
value|0x14
end_define

begin_comment
comment|/*  * PCI latency timer (it's actually 0x0D, but we want a value  * that's longword aligned).  */
end_comment

begin_define
define|#
directive|define
name|TL_PCI_LATENCY_TIMER
value|0x0C
end_define

begin_define
define|#
directive|define
name|TL_DIO_ADDR_INC
value|0x8000
end_define

begin_comment
comment|/* Increment addr on each read */
end_comment

begin_define
define|#
directive|define
name|TL_DIO_RAM_SEL
value|0x4000
end_define

begin_comment
comment|/* RAM address select */
end_comment

begin_define
define|#
directive|define
name|TL_DIO_ADDR_MASK
value|0x3FFF
end_define

begin_comment
comment|/* address bits mask */
end_comment

begin_comment
comment|/*  * Interrupt types  */
end_comment

begin_define
define|#
directive|define
name|TL_INTR_INVALID
value|0x0
end_define

begin_define
define|#
directive|define
name|TL_INTR_TXEOF
value|0x1
end_define

begin_define
define|#
directive|define
name|TL_INTR_STATOFLOW
value|0x2
end_define

begin_define
define|#
directive|define
name|TL_INTR_RXEOF
value|0x3
end_define

begin_define
define|#
directive|define
name|TL_INTR_DUMMY
value|0x4
end_define

begin_define
define|#
directive|define
name|TL_INTR_TXEOC
value|0x5
end_define

begin_define
define|#
directive|define
name|TL_INTR_ADCHK
value|0x6
end_define

begin_define
define|#
directive|define
name|TL_INTR_RXEOC
value|0x7
end_define

begin_define
define|#
directive|define
name|TL_INT_MASK
value|0x001C
end_define

begin_define
define|#
directive|define
name|TL_VEC_MASK
value|0x1FE0
end_define

begin_comment
comment|/*  * Host command register bits  */
end_comment

begin_define
define|#
directive|define
name|TL_CMD_GO
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TL_CMD_STOP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL7
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL6
value|0x08000000
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL5
value|0x04000000
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL4
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL3
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL2
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL1
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL0
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TL_CMD_EOC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TL_CMD_RT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TL_CMD_NES
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TL_CMD_ZERO0
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TL_CMD_ZERO1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TL_CMD_ADRST
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TL_CMD_LDTMR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TL_CMD_LDTHR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TL_CMD_REQINT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TL_CMD_INTSOFF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TL_CMD_INTSON
value|0x00000400
end_define

begin_define
define|#
directive|define
name|TL_CMD_RSVD0
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TL_CMD_RSVD1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TL_CMD_CHSEL_MASK
value|0x01FE0000
end_define

begin_define
define|#
directive|define
name|TL_CMD_ACK_MASK
value|0xFF
end_define

begin_comment
comment|/*  * EEPROM address where station address resides.  */
end_comment

begin_define
define|#
directive|define
name|TL_EEPROM_EADDR
value|0x83
end_define

begin_define
define|#
directive|define
name|TL_EEPROM_EADDR2
value|0x99
end_define

begin_define
define|#
directive|define
name|TL_EEPROM_EADDR3
value|0xAF
end_define

begin_define
define|#
directive|define
name|TL_EEPROM_EADDR_OC
value|0xF8
end_define

begin_comment
comment|/* Olicom cards use a different 					   address than Compaqs. */
end_comment

begin_comment
comment|/*  * ThunderLAN host command register offsets.  * (Can be accessed either by IO ports or memory map.)  */
end_comment

begin_define
define|#
directive|define
name|TL_HOSTCMD
value|0x00
end_define

begin_define
define|#
directive|define
name|TL_CH_PARM
value|0x04
end_define

begin_define
define|#
directive|define
name|TL_DIO_ADDR
value|0x08
end_define

begin_define
define|#
directive|define
name|TL_HOST_INT
value|0x0A
end_define

begin_define
define|#
directive|define
name|TL_DIO_DATA
value|0x0C
end_define

begin_comment
comment|/*  * ThunderLAN internal registers  */
end_comment

begin_define
define|#
directive|define
name|TL_NETCMD
value|0x00
end_define

begin_define
define|#
directive|define
name|TL_NETSIO
value|0x01
end_define

begin_define
define|#
directive|define
name|TL_NETSTS
value|0x02
end_define

begin_define
define|#
directive|define
name|TL_NETMASK
value|0x03
end_define

begin_define
define|#
directive|define
name|TL_NETCONFIG
value|0x04
end_define

begin_define
define|#
directive|define
name|TL_MANTEST
value|0x06
end_define

begin_define
define|#
directive|define
name|TL_VENID_LSB
value|0x08
end_define

begin_define
define|#
directive|define
name|TL_VENID_MSB
value|0x09
end_define

begin_define
define|#
directive|define
name|TL_DEVID_LSB
value|0x0A
end_define

begin_define
define|#
directive|define
name|TL_DEVID_MSB
value|0x0B
end_define

begin_define
define|#
directive|define
name|TL_REVISION
value|0x0C
end_define

begin_define
define|#
directive|define
name|TL_SUBCLASS
value|0x0D
end_define

begin_define
define|#
directive|define
name|TL_MINLAT
value|0x0E
end_define

begin_define
define|#
directive|define
name|TL_MAXLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|TL_AREG0_B5
value|0x10
end_define

begin_define
define|#
directive|define
name|TL_AREG0_B4
value|0x11
end_define

begin_define
define|#
directive|define
name|TL_AREG0_B3
value|0x12
end_define

begin_define
define|#
directive|define
name|TL_AREG0_B2
value|0x13
end_define

begin_define
define|#
directive|define
name|TL_AREG0_B1
value|0x14
end_define

begin_define
define|#
directive|define
name|TL_AREG0_B0
value|0x15
end_define

begin_define
define|#
directive|define
name|TL_AREG1_B5
value|0x16
end_define

begin_define
define|#
directive|define
name|TL_AREG1_B4
value|0x17
end_define

begin_define
define|#
directive|define
name|TL_AREG1_B3
value|0x18
end_define

begin_define
define|#
directive|define
name|TL_AREG1_B2
value|0x19
end_define

begin_define
define|#
directive|define
name|TL_AREG1_B1
value|0x1A
end_define

begin_define
define|#
directive|define
name|TL_AREG1_B0
value|0x1B
end_define

begin_define
define|#
directive|define
name|TL_AREG2_B5
value|0x1C
end_define

begin_define
define|#
directive|define
name|TL_AREG2_B4
value|0x1D
end_define

begin_define
define|#
directive|define
name|TL_AREG2_B3
value|0x1E
end_define

begin_define
define|#
directive|define
name|TL_AREG2_B2
value|0x1F
end_define

begin_define
define|#
directive|define
name|TL_AREG2_B1
value|0x20
end_define

begin_define
define|#
directive|define
name|TL_AREG2_B0
value|0x21
end_define

begin_define
define|#
directive|define
name|TL_AREG3_B5
value|0x22
end_define

begin_define
define|#
directive|define
name|TL_AREG3_B4
value|0x23
end_define

begin_define
define|#
directive|define
name|TL_AREG3_B3
value|0x24
end_define

begin_define
define|#
directive|define
name|TL_AREG3_B2
value|0x25
end_define

begin_define
define|#
directive|define
name|TL_AREG3_B1
value|0x26
end_define

begin_define
define|#
directive|define
name|TL_AREG3_B0
value|0x27
end_define

begin_define
define|#
directive|define
name|TL_HASH1
value|0x28
end_define

begin_define
define|#
directive|define
name|TL_HASH2
value|0x2C
end_define

begin_define
define|#
directive|define
name|TL_TXGOODFRAMES
value|0x30
end_define

begin_define
define|#
directive|define
name|TL_TXUNDERRUN
value|0x33
end_define

begin_define
define|#
directive|define
name|TL_RXGOODFRAMES
value|0x34
end_define

begin_define
define|#
directive|define
name|TL_RXOVERRUN
value|0x37
end_define

begin_define
define|#
directive|define
name|TL_DEFEREDTX
value|0x38
end_define

begin_define
define|#
directive|define
name|TL_CRCERROR
value|0x3A
end_define

begin_define
define|#
directive|define
name|TL_CODEERROR
value|0x3B
end_define

begin_define
define|#
directive|define
name|TL_MULTICOLTX
value|0x3C
end_define

begin_define
define|#
directive|define
name|TL_SINGLECOLTX
value|0x3E
end_define

begin_define
define|#
directive|define
name|TL_EXCESSIVECOL
value|0x40
end_define

begin_define
define|#
directive|define
name|TL_LATECOL
value|0x41
end_define

begin_define
define|#
directive|define
name|TL_CARRIERLOSS
value|0x42
end_define

begin_define
define|#
directive|define
name|TL_ACOMMIT
value|0x43
end_define

begin_define
define|#
directive|define
name|TL_LDREG
value|0x44
end_define

begin_define
define|#
directive|define
name|TL_BSIZEREG
value|0x45
end_define

begin_define
define|#
directive|define
name|TL_MAXRX
value|0x46
end_define

begin_comment
comment|/*  * ThunderLAN SIO register bits  */
end_comment

begin_define
define|#
directive|define
name|TL_SIO_MINTEN
value|0x80
end_define

begin_define
define|#
directive|define
name|TL_SIO_ECLOK
value|0x40
end_define

begin_define
define|#
directive|define
name|TL_SIO_ETXEN
value|0x20
end_define

begin_define
define|#
directive|define
name|TL_SIO_EDATA
value|0x10
end_define

begin_define
define|#
directive|define
name|TL_SIO_NMRST
value|0x08
end_define

begin_define
define|#
directive|define
name|TL_SIO_MCLK
value|0x04
end_define

begin_define
define|#
directive|define
name|TL_SIO_MTXEN
value|0x02
end_define

begin_define
define|#
directive|define
name|TL_SIO_MDATA
value|0x01
end_define

begin_comment
comment|/*  * Thunderlan NETCONFIG bits  */
end_comment

begin_define
define|#
directive|define
name|TL_CFG_RCLKTEST
value|0x8000
end_define

begin_define
define|#
directive|define
name|TL_CFG_TCLKTEST
value|0x4000
end_define

begin_define
define|#
directive|define
name|TL_CFG_BITRATE
value|0x2000
end_define

begin_define
define|#
directive|define
name|TL_CFG_RXCRC
value|0x1000
end_define

begin_define
define|#
directive|define
name|TL_CFG_PEF
value|0x0800
end_define

begin_define
define|#
directive|define
name|TL_CFG_ONEFRAG
value|0x0400
end_define

begin_define
define|#
directive|define
name|TL_CFG_ONECHAN
value|0x0200
end_define

begin_define
define|#
directive|define
name|TL_CFG_MTEST
value|0x0100
end_define

begin_define
define|#
directive|define
name|TL_CFG_PHYEN
value|0x0080
end_define

begin_define
define|#
directive|define
name|TL_CFG_MACSEL6
value|0x0040
end_define

begin_define
define|#
directive|define
name|TL_CFG_MACSEL5
value|0x0020
end_define

begin_define
define|#
directive|define
name|TL_CFG_MACSEL4
value|0x0010
end_define

begin_define
define|#
directive|define
name|TL_CFG_MACSEL3
value|0x0008
end_define

begin_define
define|#
directive|define
name|TL_CFG_MACSEL2
value|0x0004
end_define

begin_define
define|#
directive|define
name|TL_CFG_MACSEL1
value|0x0002
end_define

begin_define
define|#
directive|define
name|TL_CFG_MACSEL0
value|0x0001
end_define

begin_comment
comment|/*  * ThunderLAN NETSTS bits  */
end_comment

begin_define
define|#
directive|define
name|TL_STS_MIRQ
value|0x80
end_define

begin_define
define|#
directive|define
name|TL_STS_HBEAT
value|0x40
end_define

begin_define
define|#
directive|define
name|TL_STS_TXSTOP
value|0x20
end_define

begin_define
define|#
directive|define
name|TL_STS_RXSTOP
value|0x10
end_define

begin_comment
comment|/*  * ThunderLAN NETCMD bits  */
end_comment

begin_define
define|#
directive|define
name|TL_CMD_NRESET
value|0x80
end_define

begin_define
define|#
directive|define
name|TL_CMD_NWRAP
value|0x40
end_define

begin_define
define|#
directive|define
name|TL_CMD_CSF
value|0x20
end_define

begin_define
define|#
directive|define
name|TL_CMD_CAF
value|0x10
end_define

begin_define
define|#
directive|define
name|TL_CMD_NOBRX
value|0x08
end_define

begin_define
define|#
directive|define
name|TL_CMD_DUPLEX
value|0x04
end_define

begin_define
define|#
directive|define
name|TL_CMD_TRFRAM
value|0x02
end_define

begin_define
define|#
directive|define
name|TL_CMD_TXPACE
value|0x01
end_define

begin_comment
comment|/*  * ThunderLAN NETMASK bits  */
end_comment

begin_define
define|#
directive|define
name|TL_MASK_MASK7
value|0x80
end_define

begin_define
define|#
directive|define
name|TL_MASK_MASK6
value|0x40
end_define

begin_define
define|#
directive|define
name|TL_MASK_MASK5
value|0x20
end_define

begin_define
define|#
directive|define
name|TL_MASK_MASK4
value|0x10
end_define

begin_comment
comment|/*  * MII frame format  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_DOESNT_ALLOW_BITFIELDS
end_ifdef

begin_struct
struct|struct
name|tl_mii_frame
block|{
name|u_int16_t
name|mii_stdelim
range|:
literal|2
decl_stmt|,
name|mii_opcode
range|:
literal|2
decl_stmt|,
name|mii_phyaddr
range|:
literal|5
decl_stmt|,
name|mii_regaddr
range|:
literal|5
decl_stmt|,
name|mii_turnaround
range|:
literal|2
decl_stmt|;
name|u_int16_t
name|mii_data
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|tl_mii_frame
block|{
name|u_int8_t
name|mii_stdelim
decl_stmt|;
name|u_int8_t
name|mii_opcode
decl_stmt|;
name|u_int8_t
name|mii_phyaddr
decl_stmt|;
name|u_int8_t
name|mii_regaddr
decl_stmt|;
name|u_int8_t
name|mii_turnaround
decl_stmt|;
name|u_int16_t
name|mii_data
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * MII constants  */
end_comment

begin_define
define|#
directive|define
name|TL_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|TL_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|TL_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|TL_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|TL_LAST_FRAG
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_UNUSED
value|0x8000
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_FRAMECMP
value|0x4000
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_READY
value|0x3000
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_UNUSED13
value|0x2000
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_UNUSED12
value|0x1000
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_EOC
value|0x0800
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_RXERROR
value|0x0400
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_PASSCRC
value|0x0200
end_define

begin_define
define|#
directive|define
name|TL_CSTAT_DPRIO
value|0x0100
end_define

begin_define
define|#
directive|define
name|TL_FRAME_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|tl_tx_goodframes
parameter_list|(
name|x
parameter_list|)
value|(x.tl_txstat& TL_FRAME_MASK)
end_define

begin_define
define|#
directive|define
name|tl_tx_underrun
parameter_list|(
name|x
parameter_list|)
value|((x.tl_txstat& ~TL_FRAME_MASK)>> 24)
end_define

begin_define
define|#
directive|define
name|tl_rx_goodframes
parameter_list|(
name|x
parameter_list|)
value|(x.tl_rxstat& TL_FRAME_MASK)
end_define

begin_define
define|#
directive|define
name|tl_rx_overrun
parameter_list|(
name|x
parameter_list|)
value|((x.tl_rxstat& ~TL_FRAME_MASK)>> 24)
end_define

begin_struct
struct|struct
name|tl_stats
block|{
name|u_int32_t
name|tl_txstat
decl_stmt|;
name|u_int32_t
name|tl_rxstat
decl_stmt|;
name|u_int16_t
name|tl_deferred
decl_stmt|;
name|u_int8_t
name|tl_crc_errors
decl_stmt|;
name|u_int8_t
name|tl_code_errors
decl_stmt|;
name|u_int16_t
name|tl_tx_multi_collision
decl_stmt|;
name|u_int16_t
name|tl_tx_single_collision
decl_stmt|;
name|u_int8_t
name|tl_excessive_collision
decl_stmt|;
name|u_int8_t
name|tl_late_collision
decl_stmt|;
name|u_int8_t
name|tl_carrier_loss
decl_stmt|;
name|u_int8_t
name|acommit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ACOMMIT register bits. These are used only when a bitrate  * PHY is selected ('bitrate' bit in netconfig register is set).  */
end_comment

begin_define
define|#
directive|define
name|TL_AC_MTXER
value|0x01
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|TL_AC_MTXD1
value|0x02
end_define

begin_comment
comment|/* 0 == 10baseT 1 == AUI */
end_comment

begin_define
define|#
directive|define
name|TL_AC_MTXD2
value|0x04
end_define

begin_comment
comment|/* loopback disable */
end_comment

begin_define
define|#
directive|define
name|TL_AC_MTXD3
value|0x08
end_define

begin_comment
comment|/* full duplex disable */
end_comment

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->tl_btag, sc->tl_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(sc->tl_btag, sc->tl_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->tl_btag, sc->tl_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->tl_btag, sc->tl_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2(sc->tl_btag, sc->tl_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1(sc->tl_btag, sc->tl_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CMD_PUT
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|CSR_WRITE_4(sc, TL_HOSTCMD, x)
end_define

begin_define
define|#
directive|define
name|CMD_SET
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, TL_HOSTCMD, CSR_READ_4(sc, TL_HOSTCMD) | (x))
end_define

begin_define
define|#
directive|define
name|CMD_CLR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, TL_HOSTCMD, CSR_READ_4(sc, TL_HOSTCMD)& ~(x))
end_define

begin_comment
comment|/*  * ThunderLAN adapters typically have a serial EEPROM containing  * configuration information. The main reason we're interested in  * it is because it also contains the adapters's station address.  *  * Access to the EEPROM is a bit goofy since it is a serial device:  * you have to do reads and writes one bit at a time. The state of  * the DATA bit can only change while the CLOCK line is held low.  * Transactions work basically like this:  *  * 1) Send the EEPROM_START sequence to prepare the EEPROM for  *    accepting commands. This pulls the clock high, sets  *    the data bit to 0, enables transmission to the EEPROM,  *    pulls the data bit up to 1, then pulls the clock low.  *    The idea is to do a 0 to 1 transition of the data bit  *    while the clock pin is held high.  *  * 2) To write a bit to the EEPROM, set the TXENABLE bit, then  *    set the EDATA bit to send a 1 or clear it to send a 0.  *    Finally, set and then clear ECLOK. Strobing the clock  *    transmits the bit. After 8 bits have been written, the  *    EEPROM should respond with an ACK, which should be read.  *  * 3) To read a bit from the EEPROM, clear the TXENABLE bit,  *    then set ECLOK. The bit can then be read by reading EDATA.  *    ECLOCK should then be cleared again. This can be repeated  *    8 times to read a whole byte, after which the   *  * 4) We need to send the address byte to the EEPROM. For this  *    we have to send the write control byte to the EEPROM to  *    tell it to accept data. The byte is 0xA0. The EEPROM should  *    ack this. The address byte can be send after that.  *  * 5) Now we have to tell the EEPROM to send us data. For that we  *    have to transmit the read control byte, which is 0xA1. This  *    byte should also be acked. We can then read the data bits  *    from the EEPROM.  *  * 6) When we're all finished, send the EEPROM_STOP sequence.  *  * Note that we use the ThunderLAN's NetSio register to access the  * EEPROM, however there is an alternate method. There is a PCI NVRAM  * register at PCI offset 0xB4 which can also be used with minor changes.  * The difference is that access to PCI registers via pci_conf_read()  * and pci_conf_write() is done using programmed I/O, which we want to  * avoid.  */
end_comment

begin_comment
comment|/*  * Note that EEPROM_START leaves transmission enabled.  */
end_comment

begin_define
define|#
directive|define
name|EEPROM_START
define|\
value|tl_dio_setbit(sc, TL_NETSIO, TL_SIO_ECLOK);
comment|/* Pull clock pin high */
value|\ 	tl_dio_setbit(sc, TL_NETSIO, TL_SIO_EDATA);
comment|/* Set DATA bit to 1 */
value|\ 	tl_dio_setbit(sc, TL_NETSIO, TL_SIO_ETXEN);
comment|/* Enable xmit to write bit */
value|\ 	tl_dio_clrbit(sc, TL_NETSIO, TL_SIO_EDATA);
comment|/* Pull DATA bit to 0 again */
value|\ 	tl_dio_clrbit(sc, TL_NETSIO, TL_SIO_ECLOK);
end_define

begin_comment
comment|/* Pull clock low again */
end_comment

begin_comment
comment|/*  * EEPROM_STOP ends access to the EEPROM and clears the ETXEN bit so  * that no further data can be written to the EEPROM I/O pin.  */
end_comment

begin_define
define|#
directive|define
name|EEPROM_STOP
define|\
value|tl_dio_clrbit(sc, TL_NETSIO, TL_SIO_ETXEN);
comment|/* Disable xmit */
value|\ 	tl_dio_clrbit(sc, TL_NETSIO, TL_SIO_EDATA);
comment|/* Pull DATA to 0 */
value|\ 	tl_dio_setbit(sc, TL_NETSIO, TL_SIO_ECLOK);
comment|/* Pull clock high */
value|\ 	tl_dio_setbit(sc, TL_NETSIO, TL_SIO_ETXEN);
comment|/* Enable xmit */
value|\ 	tl_dio_setbit(sc, TL_NETSIO, TL_SIO_EDATA);
comment|/* Toggle DATA to 1 */
value|\ 	tl_dio_clrbit(sc, TL_NETSIO, TL_SIO_ETXEN);
comment|/* Disable xmit. */
value|\ 	tl_dio_clrbit(sc, TL_NETSIO, TL_SIO_ECLOK);
end_define

begin_comment
comment|/* Pull clock low again */
end_comment

begin_comment
comment|/*  * These are the register definitions for the PHY (physical layer  * interface chip).  * The ThunderLAN chip has a built-in 10Mb/sec PHY which may be used  * in some configurations. The Compaq 10/100 cards based on the ThunderLAN  * use a National Semiconductor DP83840A PHY. The generic BMCR and BMSR  * layouts for both PHYs are identical, however some of the bits are not  * used by the ThunderLAN's internal PHY (most notably those dealing with  * switching between 10 and 100Mb/sec speeds). Since Both PHYs use the  * same bits, we #define them with generic names here.  */
end_comment

begin_comment
comment|/*  * PHY BMCR Basic Mode Control Register  */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_LOOPBK
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_SPEEDSEL
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGENBL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD0
value|0x0800
end_define

begin_comment
comment|/* write as zero */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_PWRDOWN
value|0x0800
end_define

begin_comment
comment|/* tlan internal PHY only */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_ISOLATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGRSTR
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_COLLTEST
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD1
value|0x0040
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD2
value|0x0020
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD3
value|0x0010
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD4
value|0x0008
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD5
value|0x0004
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD6
value|0x0002
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD7
value|0x0001
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_comment
comment|/*  * RESET: 1 == software reset, 0 == normal operation  * Resets status and control registers to default values.  * Relatches all hardware config values.  *  * LOOPBK: 1 == loopback operation enabled, 0 == normal operation  *  * SPEEDSEL: 1 == 100Mb/s, 0 == 10Mb/s  * Link speed is selected byt his bit or if auto-negotiation if bit  * 12 (AUTONEGENBL) is set (in which case the value of this register  * is ignored).  *  * AUTONEGENBL: 1 == Autonegotiation enabled, 0 == Autonegotiation disabled  * Bits 8 and 13 are ignored when autoneg is set, otherwise bits 8 and 13  * determine speed and mode. Should be cleared and then set if PHY configured  * for no autoneg on startup.  *  * ISOLATE: 1 == isolate PHY from MII, 0 == normal operation  *  * AUTONEGRSTR: 1 == restart autonegotiation, 0 = normal operation  *  * DUPLEX: 1 == full duplex mode, 0 == half duplex mode  *  * COLLTEST: 1 == collision test enabled, 0 == normal operation  */
end_comment

begin_comment
comment|/*   * PHY, BMSR Basic Mode Status Register   */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BT4
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXFULL
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXHALF
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_10BTFULL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_10BTHALF
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD1
value|0x0400
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD2
value|0x0200
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD3
value|0x0100
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD4
value|0x0080
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_MFPRESUP
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_AUTONEGCOMP
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_REMFAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_CANAUTONEG
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_LINKSTAT
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_JABBER
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_EXTENDED
value|0x0001
end_define

begin_define
define|#
directive|define
name|PHY_CTL_IGLINK
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_CTL_SWAPOL
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_CTL_AUISEL
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_CTL_SQEEN
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_CTL_MTEST
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_CTL_NFEW
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_CTL_INTEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_CTL_TINT
value|0x0001
end_define

begin_define
define|#
directive|define
name|TL_PHY_GENCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|TL_PHY_GENSTS
value|0x01
end_define

begin_comment
comment|/*  * PHY Generic Identifier Register, hi bits  */
end_comment

begin_define
define|#
directive|define
name|TL_PHY_VENID
value|0x02
end_define

begin_comment
comment|/*  * PHY Generic Identifier Register, lo bits  */
end_comment

begin_define
define|#
directive|define
name|TL_PHY_DEVID
value|0x03
end_define

begin_define
define|#
directive|define
name|TL_PHY_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|TL_PHY_LPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|TL_PHY_ANEXP
value|0x06
end_define

begin_define
define|#
directive|define
name|TL_PHY_PHYID
value|0x10
end_define

begin_define
define|#
directive|define
name|TL_PHY_CTL
value|0x11
end_define

begin_define
define|#
directive|define
name|TL_PHY_STS
value|0x12
end_define

begin_define
define|#
directive|define
name|TL_LPAR_RMFLT
value|0x2000
end_define

begin_define
define|#
directive|define
name|TL_LPAR_RSVD0
value|0x1000
end_define

begin_define
define|#
directive|define
name|TL_LPAR_RSVD1
value|0x0800
end_define

begin_define
define|#
directive|define
name|TL_LPAR_100BT4
value|0x0400
end_define

begin_define
define|#
directive|define
name|TL_LPAR_100BTXFULL
value|0x0200
end_define

begin_define
define|#
directive|define
name|TL_LPAR_100BTXHALF
value|0x0100
end_define

begin_define
define|#
directive|define
name|TL_LPAR_10BTFULL
value|0x0080
end_define

begin_define
define|#
directive|define
name|TL_LPAR_10BTHALF
value|0x0040
end_define

begin_comment
comment|/*  * PHY Antoneg advertisement register.  */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR
value|TL_PHY_ANAR
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_NEXTPAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD0
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_TLRFLT
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD1
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_RSVD_RSDV2
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_RSVD_RSVD3
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BT4
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXFULL
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXHALF
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_10BTFULL
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_10BTHALF
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO4
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO3
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO2
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_AHAR_PROTO1
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_AHAR_PROTO0
value|0x0001
end_define

begin_comment
comment|/*  * DP83840 PHY, PCS Confifguration Register  */
end_comment

begin_define
define|#
directive|define
name|TL_DP83840_PCS
value|0x17
end_define

begin_define
define|#
directive|define
name|TL_DP83840_PCS_LED4_MODE
value|0x0002
end_define

begin_define
define|#
directive|define
name|TL_DP83840_PCS_F_CONNECT
value|0x0020
end_define

begin_define
define|#
directive|define
name|TL_DP83840_PCS_BIT8
value|0x0100
end_define

begin_define
define|#
directive|define
name|TL_DP83840_PCS_BIT10
value|0x0400
end_define

begin_comment
comment|/*  * DP83840 PHY, PAR register  */
end_comment

begin_define
define|#
directive|define
name|TL_DP83840_PAR
value|0x19
end_define

begin_define
define|#
directive|define
name|PAR_RSVD0
value|0x8000
end_define

begin_define
define|#
directive|define
name|PAR_RSVD1
value|0x4000
end_define

begin_define
define|#
directive|define
name|PAR_RSVD2
value|0x2000
end_define

begin_define
define|#
directive|define
name|PAR_RSVD3
value|0x1000
end_define

begin_define
define|#
directive|define
name|PAR_DIS_CRS_JAB
value|0x0800
end_define

begin_define
define|#
directive|define
name|PAR_AN_EN_STAT
value|0x0400
end_define

begin_define
define|#
directive|define
name|PAR_RSVD4
value|0x0200
end_define

begin_define
define|#
directive|define
name|PAR_FEFI_EN
value|0x0100
end_define

begin_define
define|#
directive|define
name|PAR_DUPLEX_STAT
value|0x0080
end_define

begin_define
define|#
directive|define
name|PAR_SPEED_10
value|0x0040
end_define

begin_define
define|#
directive|define
name|PAR_CIM_STATUS
value|0x0020
end_define

begin_define
define|#
directive|define
name|PAR_PHYADDR4
value|0x0010
end_define

begin_define
define|#
directive|define
name|PAR_PHYADDR3
value|0x0008
end_define

begin_define
define|#
directive|define
name|PAR_PHYADDR2
value|0x0004
end_define

begin_define
define|#
directive|define
name|PAR_PHYADDR1
value|0x0002
end_define

begin_define
define|#
directive|define
name|PAR_PHYADDR0
value|0x0001
end_define

begin_comment
comment|/*  * Microchip Technology 24Cxx EEPROM control bytes  */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CTL_READ
value|0xA1
end_define

begin_comment
comment|/* 0101 0001 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CTL_WRITE
value|0xA0
end_define

begin_comment
comment|/* 0101 0000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_undef
undef|#
directive|undef
name|vtophys
end_undef

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|(pmap_kextract(((vm_offset_t) (va))) \ 					+ 1*1024*1024*1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

