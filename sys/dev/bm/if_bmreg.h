begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1991-1998 by Open Software Foundation, Inc.  *              All Rights Reserved  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both the copyright notice and this permission notice appear in  * supporting documentation.  *  * OSF DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * IN NO EVENT SHALL OSF BE LIABLE FOR ANY SPECIAL, INDIRECT, OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN ACTION OF CONTRACT,  * NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Copyright 2003 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * BMAC resource indices  */
end_comment

begin_define
define|#
directive|define
name|BM_MAIN_REGISTERS
value|0
end_define

begin_define
define|#
directive|define
name|BM_TXDMA_REGISTERS
value|1
end_define

begin_define
define|#
directive|define
name|BM_RXDMA_REGISTERS
value|2
end_define

begin_define
define|#
directive|define
name|BM_MAIN_INTERRUPT
value|0
end_define

begin_define
define|#
directive|define
name|BM_TXDMA_INTERRUPT
value|1
end_define

begin_define
define|#
directive|define
name|BM_RXDMA_INTERRUPT
value|2
end_define

begin_comment
comment|/*  * BMAC/BMAC+ register offsets  */
end_comment

begin_define
define|#
directive|define
name|BM_TX_IFC
value|0x0000
end_define

begin_comment
comment|/* interface control */
end_comment

begin_define
define|#
directive|define
name|BM_TXFIFO_CSR
value|0x0100
end_define

begin_comment
comment|/* TX FIFO control/status */
end_comment

begin_define
define|#
directive|define
name|BM_TX_THRESH
value|0x0110
end_define

begin_comment
comment|/* TX threshold */
end_comment

begin_define
define|#
directive|define
name|BM_RXFIFO_CSR
value|0x0120
end_define

begin_comment
comment|/* receive FIFO control/status */
end_comment

begin_define
define|#
directive|define
name|BM_MEMADD
value|0x0130
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|BM_MEMDATA_HI
value|0x0140
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|BM_MEMDATA_LO
value|0x0150
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|BM_XCVR
value|0x0160
end_define

begin_comment
comment|/* transceiver control register */
end_comment

begin_define
define|#
directive|define
name|BM_CHIPID
value|0x0170
end_define

begin_comment
comment|/* chip ID */
end_comment

begin_define
define|#
directive|define
name|BM_MII_CSR
value|0x0180
end_define

begin_comment
comment|/* MII control register */
end_comment

begin_define
define|#
directive|define
name|BM_SROM_CSR
value|0x0190
end_define

begin_comment
comment|/* unused, OFW provides enet addr */
end_comment

begin_define
define|#
directive|define
name|BM_TX_PTR
value|0x01A0
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|BM_RX_PTR
value|0x01B0
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|BM_STATUS
value|0x01C0
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|BM_INTR_DISABLE
value|0x0200
end_define

begin_comment
comment|/* interrupt control register */
end_comment

begin_define
define|#
directive|define
name|BM_TX_RESET
value|0x0420
end_define

begin_comment
comment|/* TX reset */
end_comment

begin_define
define|#
directive|define
name|BM_TX_CONFIG
value|0x0430
end_define

begin_comment
comment|/* TX config */
end_comment

begin_define
define|#
directive|define
name|BM_IPG1
value|0x0440
end_define

begin_comment
comment|/* inter-packet gap hi */
end_comment

begin_define
define|#
directive|define
name|BM_IPG2
value|0x0450
end_define

begin_comment
comment|/* inter-packet gap lo */
end_comment

begin_define
define|#
directive|define
name|BM_TX_ALIMIT
value|0x0460
end_define

begin_comment
comment|/* TX attempt limit */
end_comment

begin_define
define|#
directive|define
name|BM_TX_STIME
value|0x0470
end_define

begin_comment
comment|/* TX slot time */
end_comment

begin_define
define|#
directive|define
name|BM_TX_PASIZE
value|0x0480
end_define

begin_comment
comment|/* TX preamble size */
end_comment

begin_define
define|#
directive|define
name|BM_TX_PAPAT
value|0x0490
end_define

begin_comment
comment|/* TX preamble pattern */
end_comment

begin_define
define|#
directive|define
name|BM_TX_SFD
value|0x04A0
end_define

begin_comment
comment|/* TX start-frame delimiter */
end_comment

begin_define
define|#
directive|define
name|BM_JAMSIZE
value|0x04B0
end_define

begin_comment
comment|/* collision jam size */
end_comment

begin_define
define|#
directive|define
name|BM_TX_MAXLEN
value|0x04C0
end_define

begin_comment
comment|/* max TX packet length */
end_comment

begin_define
define|#
directive|define
name|BM_TX_MINLEN
value|0x04D0
end_define

begin_comment
comment|/* min TX packet length */
end_comment

begin_define
define|#
directive|define
name|BM_TX_PEAKCNT
value|0x04E0
end_define

begin_comment
comment|/* TX peak attempts count */
end_comment

begin_define
define|#
directive|define
name|BM_TX_DCNT
value|0x04F0
end_define

begin_comment
comment|/* TX defer timer */
end_comment

begin_define
define|#
directive|define
name|BM_TX_NCCNT
value|0x0500
end_define

begin_comment
comment|/* TX normal collision cnt */
end_comment

begin_define
define|#
directive|define
name|BM_TX_FCCNT
value|0x0510
end_define

begin_comment
comment|/* TX first collision cnt */
end_comment

begin_define
define|#
directive|define
name|BM_TX_EXCNT
value|0x0520
end_define

begin_comment
comment|/* TX excess collision cnt */
end_comment

begin_define
define|#
directive|define
name|BM_TX_LTCNT
value|0x0530
end_define

begin_comment
comment|/* TX late collision cnt */
end_comment

begin_define
define|#
directive|define
name|BM_TX_RANDSEED
value|0x0540
end_define

begin_comment
comment|/* TX random seed */
end_comment

begin_define
define|#
directive|define
name|BM_TXSM
value|0x0550
end_define

begin_comment
comment|/* TX state machine */
end_comment

begin_define
define|#
directive|define
name|BM_RX_RESET
value|0x0620
end_define

begin_comment
comment|/* RX reset */
end_comment

begin_define
define|#
directive|define
name|BM_RX_CONFIG
value|0x0630
end_define

begin_comment
comment|/* RX config */
end_comment

begin_define
define|#
directive|define
name|BM_RX_MAXLEN
value|0x0640
end_define

begin_comment
comment|/* max RX packet length */
end_comment

begin_define
define|#
directive|define
name|BM_RX_MINLEN
value|0x0650
end_define

begin_comment
comment|/* min RX packet length */
end_comment

begin_define
define|#
directive|define
name|BM_MACADDR2
value|0x0660
end_define

begin_comment
comment|/* MAC address */
end_comment

begin_define
define|#
directive|define
name|BM_MACADDR1
value|0x0670
end_define

begin_define
define|#
directive|define
name|BM_MACADDR0
value|0x0680
end_define

begin_define
define|#
directive|define
name|BM_RX_FRCNT
value|0x0690
end_define

begin_comment
comment|/* RX frame count */
end_comment

begin_define
define|#
directive|define
name|BM_RX_LECNT
value|0x06A0
end_define

begin_comment
comment|/* RX too-long frame count */
end_comment

begin_define
define|#
directive|define
name|BM_RX_AECNT
value|0x06B0
end_define

begin_comment
comment|/* RX misaligned frame count */
end_comment

begin_define
define|#
directive|define
name|BM_RX_FECNT
value|0x06C0
end_define

begin_comment
comment|/* RX CRC error count */
end_comment

begin_define
define|#
directive|define
name|BM_RXSM
value|0x06D0
end_define

begin_comment
comment|/* RX state machine */
end_comment

begin_define
define|#
directive|define
name|BM_RXCV
value|0x06E0
end_define

begin_comment
comment|/* RX code violations */
end_comment

begin_define
define|#
directive|define
name|BM_HASHTAB3
value|0x0700
end_define

begin_comment
comment|/* Address hash table */
end_comment

begin_define
define|#
directive|define
name|BM_HASHTAB2
value|0x0710
end_define

begin_define
define|#
directive|define
name|BM_HASHTAB1
value|0x0720
end_define

begin_define
define|#
directive|define
name|BM_HASHTAB0
value|0x0730
end_define

begin_define
define|#
directive|define
name|BM_AFILTER2
value|0x0740
end_define

begin_comment
comment|/* Address filter */
end_comment

begin_define
define|#
directive|define
name|BM_AFILTER1
value|0x0750
end_define

begin_define
define|#
directive|define
name|BM_AFILTER0
value|0x0760
end_define

begin_define
define|#
directive|define
name|BM_AFILTER_MASK
value|0x0770
end_define

begin_comment
comment|/*  * MII control register bits  */
end_comment

begin_define
define|#
directive|define
name|BM_MII_CLK
value|0x0001
end_define

begin_comment
comment|/* MDIO clock */
end_comment

begin_define
define|#
directive|define
name|BM_MII_DATAOUT
value|0x0002
end_define

begin_comment
comment|/* MDIO data out */
end_comment

begin_define
define|#
directive|define
name|BM_MII_OENABLE
value|0x0004
end_define

begin_comment
comment|/* MDIO output enable */
end_comment

begin_define
define|#
directive|define
name|BM_MII_DATAIN
value|0x0008
end_define

begin_comment
comment|/* MDIO data in */
end_comment

begin_comment
comment|/*  * MII constants  */
end_comment

begin_define
define|#
directive|define
name|BM_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|BM_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|BM_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|BM_MII_TURNAROUND
value|0x02
end_define

begin_comment
comment|/*  * Various flags  */
end_comment

begin_define
define|#
directive|define
name|BM_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|BM_CRC_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|BM_HASH_FILTER_ENABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|BM_REJECT_OWN_PKTS
value|0x0800
end_define

begin_define
define|#
directive|define
name|BM_PROMISC
value|0x0040
end_define

begin_define
define|#
directive|define
name|BM_TX_FULLDPX
value|0x0200
end_define

begin_define
define|#
directive|define
name|BM_TX_IGNORECOLL
value|0x0040
end_define

begin_define
define|#
directive|define
name|BM_INTR_PKT_RX
value|0x0001
end_define

begin_define
define|#
directive|define
name|BM_INTR_PKT_TX
value|0x0100
end_define

begin_define
define|#
directive|define
name|BM_INTR_TX_UNDERRUN
value|0x0200
end_define

begin_define
define|#
directive|define
name|BM_INTR_NORMAL
value|~(BM_INTR_PKT_TX | BM_INTR_TX_UNDERRUN)
end_define

begin_define
define|#
directive|define
name|BM_INTR_NONE
value|0xffff
end_define

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
value|bus_write_4(sc->sc_memr, reg, val)
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
value|bus_write_2(sc->sc_memr, reg, val)
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
value|bus_write_1(sc->sc_memr, reg, val)
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
value|bus_read_4(sc->sc_memr, reg)
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
value|bus_read_2(sc->sc_memr, reg)
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
value|bus_read_1(sc->sc_memr, reg)
end_define

end_unit

