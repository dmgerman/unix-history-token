begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001-2005, Intel Corporation.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Intel Corporation nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_XSCALE_IF_NPEREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_XSCALE_IF_NPEREG_H
end_define

begin_comment
comment|/*  * NPE/NPE tx/rx descriptor format.  This is just the area  * shared with ucode running in the NPE; the driver-specific  * state is defined in the driver.  The shared area must be  * cacheline-aligned.  We allocate NPE_MAXSEG "descriptors"  * per buffer; this allows us to do minimal s/g.  The number  * of descriptors can be expanded but doing so uses memory  * so should be done with care.  *  * The driver sets up buffers in uncached memory.  */
end_comment

begin_define
define|#
directive|define
name|NPE_MAXSEG
value|3
end_define

begin_comment
comment|/* empirically selected */
end_comment

begin_struct
struct|struct
name|npehwbuf
block|{
struct|struct
block|{
comment|/* NPE shared area, cacheline aligned */
name|uint32_t
name|next
decl_stmt|;
comment|/* phys addr of next segment */
name|uint32_t
name|len
decl_stmt|;
comment|/* buffer/segment length (bytes) */
name|uint32_t
name|data
decl_stmt|;
comment|/* phys addr of data segment */
name|uint32_t
name|pad
index|[
literal|5
index|]
decl_stmt|;
comment|/* pad to cacheline */
block|}
name|ix_ne
index|[
name|NPE_MAXSEG
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* NPE ID's */
end_comment

begin_define
define|#
directive|define
name|NPE_A
value|0
end_define

begin_define
define|#
directive|define
name|NPE_B
value|1
end_define

begin_define
define|#
directive|define
name|NPE_C
value|2
end_define

begin_define
define|#
directive|define
name|NPE_MAX
value|(NPE_C+1)
end_define

begin_define
define|#
directive|define
name|NPE_PORTS_MAX
value|2
end_define

begin_comment
comment|/* logical ports */
end_comment

begin_define
define|#
directive|define
name|NPE_FRAME_SIZE_DEFAULT
value|1536
end_define

begin_define
define|#
directive|define
name|NPE_FRAME_SIZE_MAX
value|(65536-64)
end_define

begin_define
define|#
directive|define
name|NPE_FRAME_SIZE_MIN
value|64
end_define

begin_comment
comment|/*  * Queue Manager-related definitions.  *  * These define the layout of 32-bit Q entries passed  * between the host cpu and the NPE's.  */
end_comment

begin_define
define|#
directive|define
name|NPE_QM_Q_NPE
parameter_list|(
name|e
parameter_list|)
value|(((e)>>0)&0x3)
end_define

begin_comment
comment|/* NPE ID */
end_comment

begin_define
define|#
directive|define
name|NPE_QM_Q_PORT
parameter_list|(
name|e
parameter_list|)
value|(((e)>>3)&0x1)
end_define

begin_comment
comment|/* Port ID */
end_comment

begin_define
define|#
directive|define
name|NPE_QM_Q_PRIO
parameter_list|(
name|e
parameter_list|)
value|(((e)>>0)&0x3)
end_define

begin_comment
comment|/* 802.1d priority */
end_comment

begin_define
define|#
directive|define
name|NPE_QM_Q_ADDR
parameter_list|(
name|e
parameter_list|)
value|((e)&0xfffffffe0)
end_define

begin_comment
comment|/* phys address */
end_comment

begin_comment
comment|/*  * Host->NPE requests written to the shared mailbox.  * The NPE writes the same value back as an ACK.  */
end_comment

begin_define
define|#
directive|define
name|NPE_GETSTATUS
value|0x00
end_define

begin_comment
comment|/* get firmware revision */
end_comment

begin_define
define|#
directive|define
name|NPE_SETPORTADDRESS
value|0x01
end_define

begin_comment
comment|/* set port id and mac address */
end_comment

begin_define
define|#
directive|define
name|NPE_GETMACADDRDB
value|0x02
end_define

begin_comment
comment|/* upload filter database */
end_comment

begin_define
define|#
directive|define
name|NPE_SETMACADDRDB
value|0x03
end_define

begin_comment
comment|/* download filter database */
end_comment

begin_define
define|#
directive|define
name|NPE_GETSTATS
value|0x04
end_define

begin_comment
comment|/* get statistics */
end_comment

begin_define
define|#
directive|define
name|NPE_RESETSTATS
value|0x05
end_define

begin_comment
comment|/* reset stats + return result */
end_comment

begin_define
define|#
directive|define
name|NPE_SETMAXFRAME
value|0x06
end_define

begin_comment
comment|/* configure max tx/rx frame lengths */
end_comment

begin_define
define|#
directive|define
name|NPE_SETRXTAGMODE
value|0x07
end_define

begin_comment
comment|/* configure VLAN rx operating mode */
end_comment

begin_define
define|#
directive|define
name|NPE_SETDEFRXVID
value|0x08
end_define

begin_comment
comment|/* set def VLAN tag + traffic class */
end_comment

begin_define
define|#
directive|define
name|NPE_SETRXQOSENTRY
value|0x0b
end_define

begin_comment
comment|/* map user pri -> QoS class+rx qid */
end_comment

begin_define
define|#
directive|define
name|NPE_SETFIREWALLMODE
value|0x0e
end_define

begin_comment
comment|/* config firewall services */
end_comment

begin_define
define|#
directive|define
name|NPE_SETLOOPBACK
value|0x12
end_define

begin_comment
comment|/* enable/disable loopback */
end_comment

begin_comment
comment|/* ... XXX more */
end_comment

begin_define
define|#
directive|define
name|NPE_MAC_MSGID_SHL
value|24
end_define

begin_define
define|#
directive|define
name|NPE_MAC_PORTID_SHL
value|16
end_define

begin_comment
comment|/*  * MAC register definitions; see section  * 15.2 of the Intel Developers Manual.  */
end_comment

begin_define
define|#
directive|define
name|NPE_MAC_TX_CNTRL1
value|0x000
end_define

begin_define
define|#
directive|define
name|NPE_MAC_TX_CNTRL2
value|0x004
end_define

begin_define
define|#
directive|define
name|NPE_MAC_RX_CNTRL1
value|0x010
end_define

begin_define
define|#
directive|define
name|NPE_MAC_RX_CNTRL2
value|0x014
end_define

begin_define
define|#
directive|define
name|NPE_MAC_RANDOM_SEED
value|0x020
end_define

begin_define
define|#
directive|define
name|NPE_MAC_THRESH_P_EMPTY
value|0x030
end_define

begin_define
define|#
directive|define
name|NPE_MAC_THRESH_P_FULL
value|0x038
end_define

begin_define
define|#
directive|define
name|NPE_MAC_BUF_SIZE_TX
value|0x040
end_define

begin_define
define|#
directive|define
name|NPE_MAC_TX_DEFER
value|0x050
end_define

begin_define
define|#
directive|define
name|NPE_MAC_RX_DEFER
value|0x054
end_define

begin_define
define|#
directive|define
name|NPE_MAC_TX_TWO_DEFER_1
value|0x060
end_define

begin_define
define|#
directive|define
name|NPE_MAC_TX_TWO_DEFER_2
value|0x064
end_define

begin_define
define|#
directive|define
name|NPE_MAC_SLOT_TIME
value|0x070
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_CMD_1
value|0x080
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_CMD_2
value|0x084
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_CMD_3
value|0x088
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_CMD_4
value|0x08c
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_STS_1
value|0x090
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_STS_2
value|0x094
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_STS_3
value|0x098
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_STS_4
value|0x09c
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_MASK_1
value|0x0A0
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_MASK_2
value|0x0A4
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_MASK_3
value|0x0A8
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_MASK_4
value|0x0AC
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_MASK_5
value|0x0B0
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_MASK_6
value|0x0B4
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_1
value|0x0C0
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_2
value|0x0C4
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_3
value|0x0C8
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_4
value|0x0CC
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_5
value|0x0D0
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_6
value|0x0D4
end_define

begin_define
define|#
directive|define
name|NPE_MAC_INT_CLK_THRESH
value|0x0E0
end_define

begin_define
define|#
directive|define
name|NPE_MAC_UNI_ADDR_1
value|0x0F0
end_define

begin_define
define|#
directive|define
name|NPE_MAC_UNI_ADDR_2
value|0x0F4
end_define

begin_define
define|#
directive|define
name|NPE_MAC_UNI_ADDR_3
value|0x0F8
end_define

begin_define
define|#
directive|define
name|NPE_MAC_UNI_ADDR_4
value|0x0FC
end_define

begin_define
define|#
directive|define
name|NPE_MAC_UNI_ADDR_5
value|0x100
end_define

begin_define
define|#
directive|define
name|NPE_MAC_UNI_ADDR_6
value|0x104
end_define

begin_define
define|#
directive|define
name|NPE_MAC_CORE_CNTRL
value|0x1FC
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR_MASK
parameter_list|(
name|i
parameter_list|)
value|(NPE_MAC_ADDR_MASK_1 + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|NPE_MAC_ADDR
parameter_list|(
name|i
parameter_list|)
value|(NPE_MAC_ADDR_1 + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|NPE_MAC_UNI_ADDR
parameter_list|(
name|i
parameter_list|)
value|(NPE_MAC_UNI_ADDR_1 + ((i)<<2))
end_define

begin_comment
comment|/*  * Bit definitions  */
end_comment

begin_comment
comment|/* TX Control Register 1*/
end_comment

begin_define
define|#
directive|define
name|NPE_TX_CNTRL1_TX_EN
value|0x01
end_define

begin_comment
comment|/* enable TX engine */
end_comment

begin_define
define|#
directive|define
name|NPE_TX_CNTRL1_DUPLEX
value|0x02
end_define

begin_comment
comment|/* select half duplex */
end_comment

begin_define
define|#
directive|define
name|NPE_TX_CNTRL1_RETRY
value|0x04
end_define

begin_comment
comment|/* auto-retry on collision */
end_comment

begin_define
define|#
directive|define
name|NPE_TX_CNTRL1_PAD_EN
value|0x08
end_define

begin_comment
comment|/* pad frames<64 bytes */
end_comment

begin_define
define|#
directive|define
name|NPE_TX_CNTRL1_FCS_EN
value|0x10
end_define

begin_comment
comment|/* append FCS */
end_comment

begin_define
define|#
directive|define
name|NPE_TX_CNTRL1_2DEFER
value|0x20
end_define

begin_comment
comment|/* select 2-part deferral */
end_comment

begin_define
define|#
directive|define
name|NPE_TX_CNTRL1_RMII
value|0x40
end_define

begin_comment
comment|/* TX Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|NPE_TX_CNTRL2_RETRIES_MASK
value|0xf
end_define

begin_comment
comment|/* max retry count */
end_comment

begin_comment
comment|/* RX Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL1_RX_EN
value|0x01
end_define

begin_comment
comment|/* enable RX engine */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL1_PADSTRIP_EN
value|0x02
end_define

begin_comment
comment|/* strip frame padding */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL1_CRC_EN
value|0x04
end_define

begin_comment
comment|/* include CRC in RX frame */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL1_PAUSE_EN
value|0x08
end_define

begin_comment
comment|/* detect Pause frames */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL1_LOOP_EN
value|0x10
end_define

begin_comment
comment|/* loopback tx/rx */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL1_ADDR_FLTR_EN
value|0x20
end_define

begin_comment
comment|/* enable address filtering */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL1_RX_RUNT_EN
value|0x40
end_define

begin_comment
comment|/* enable RX of runt frames */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL1_BCAST_DIS
value|0x80
end_define

begin_comment
comment|/* discard broadcast frames */
end_comment

begin_comment
comment|/* RX Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|NPE_RX_CNTRL2_DEFER_EN
value|0x01
end_define

begin_comment
comment|/* Core Control Register */
end_comment

begin_define
define|#
directive|define
name|NPE_CORE_RESET
value|0x01
end_define

begin_comment
comment|/* MAC reset state */
end_comment

begin_define
define|#
directive|define
name|NPE_CORE_RX_FIFO_FLUSH
value|0x02
end_define

begin_comment
comment|/* flush RX FIFO */
end_comment

begin_define
define|#
directive|define
name|NPE_CORE_TX_FIFO_FLUSH
value|0x04
end_define

begin_comment
comment|/* flush TX FIFO */
end_comment

begin_define
define|#
directive|define
name|NPE_CORE_SEND_JAM
value|0x08
end_define

begin_comment
comment|/* send JAM on packet RX */
end_comment

begin_define
define|#
directive|define
name|NPE_CORE_MDC_EN
value|0x10
end_define

begin_comment
comment|/* IXP42X drives MDC clock */
end_comment

begin_comment
comment|/*  * Stat block returned by NPE with NPE_GETSTATS msg.  */
end_comment

begin_struct
struct|struct
name|npestats
block|{
name|uint32_t
name|dot3StatsAlignmentErrors
decl_stmt|;
name|uint32_t
name|dot3StatsFCSErrors
decl_stmt|;
name|uint32_t
name|dot3StatsInternalMacReceiveErrors
decl_stmt|;
name|uint32_t
name|RxOverrunDiscards
decl_stmt|;
name|uint32_t
name|RxLearnedEntryDiscards
decl_stmt|;
name|uint32_t
name|RxLargeFramesDiscards
decl_stmt|;
name|uint32_t
name|RxSTPBlockedDiscards
decl_stmt|;
name|uint32_t
name|RxVLANTypeFilterDiscards
decl_stmt|;
name|uint32_t
name|RxVLANIdFilterDiscards
decl_stmt|;
name|uint32_t
name|RxInvalidSourceDiscards
decl_stmt|;
name|uint32_t
name|RxBlackListDiscards
decl_stmt|;
name|uint32_t
name|RxWhiteListDiscards
decl_stmt|;
name|uint32_t
name|RxUnderflowEntryDiscards
decl_stmt|;
name|uint32_t
name|dot3StatsSingleCollisionFrames
decl_stmt|;
name|uint32_t
name|dot3StatsMultipleCollisionFrames
decl_stmt|;
name|uint32_t
name|dot3StatsDeferredTransmissions
decl_stmt|;
name|uint32_t
name|dot3StatsLateCollisions
decl_stmt|;
name|uint32_t
name|dot3StatsExcessiveCollisions
decl_stmt|;
name|uint32_t
name|dot3StatsInternalMacTransmitErrors
decl_stmt|;
name|uint32_t
name|dot3StatsCarrierSenseErrors
decl_stmt|;
name|uint32_t
name|TxLargeFrameDiscards
decl_stmt|;
name|uint32_t
name|TxVLANIdFilterDiscards
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Default values  */
end_comment

begin_define
define|#
directive|define
name|NPE_MAC_INT_CLK_THRESH_DEFAULT
value|0x1
end_define

begin_define
define|#
directive|define
name|NPE_MAC_RESET_DELAY
value|1
end_define

begin_comment
comment|/* This value applies to RMII */
end_comment

begin_define
define|#
directive|define
name|NPE_MAC_SLOT_TIME_RMII_DEFAULT
value|0xFF
end_define

begin_comment
comment|/*  * MII definitions - these have been verified against the LXT971 and LXT972 PHYs  */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_REG_SHL
value|16
end_define

begin_define
define|#
directive|define
name|NPE_MII_ADDR_SHL
value|21
end_define

begin_comment
comment|/* NB: shorthands for mii bus mdio routines */
end_comment

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_CMD
value|NPE_MAC_MDIO_CMD_1
end_define

begin_define
define|#
directive|define
name|NPE_MAC_MDIO_STS
value|NPE_MAC_MDIO_STS_1
end_define

begin_define
define|#
directive|define
name|NPE_MII_GO
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|NPE_MII_WRITE
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|NPE_MII_TIMEOUT_10TH_SECS
value|5
end_define

begin_define
define|#
directive|define
name|NPE_MII_10TH_SEC_IN_MILLIS
value|100
end_define

begin_define
define|#
directive|define
name|NPE_MII_READ_FAIL
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|NPE_MII_PHY_DEF_DELAY
value|300
end_define

begin_comment
comment|/* max delay before link up, etc. */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_PHY_NO_DELAY
value|0x0
end_define

begin_comment
comment|/* do not delay */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_PHY_NULL
value|0xff
end_define

begin_comment
comment|/* PHY is not present */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_PHY_DEF_ADDR
value|0x0
end_define

begin_comment
comment|/* default PHY's logical address */
end_comment

begin_comment
comment|/* Register definition */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_CTRL_REG
value|0x0
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_STAT_REG
value|0x1
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_PHY_ID1_REG
value|0x2
end_define

begin_comment
comment|/* PHY identifier 1 Register */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_PHY_ID2_REG
value|0x3
end_define

begin_comment
comment|/* PHY identifier 2 Register */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_AN_ADS_REG
value|0x4
end_define

begin_comment
comment|/* Auto-Negotiation 	  */
end_comment

begin_comment
comment|/* Advertisement Register */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_AN_PRTN_REG
value|0x5
end_define

begin_comment
comment|/* Auto-Negotiation 	    */
end_comment

begin_comment
comment|/* partner ability Register */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_AN_EXP_REG
value|0x6
end_define

begin_comment
comment|/* Auto-Negotiation   */
end_comment

begin_comment
comment|/* Expansion Register */
end_comment

begin_define
define|#
directive|define
name|NPE_MII_AN_NEXT_REG
value|0x7
end_define

begin_comment
comment|/* Auto-Negotiation 	       */
end_comment

begin_comment
comment|/* next-page transmit Register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_XSCALE_IF_NPEREG_H */
end_comment

end_unit

