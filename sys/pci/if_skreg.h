begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * SysKonnect PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|SK_VENDORID
value|0x1148
end_define

begin_comment
comment|/*  * SK-NET gigabit ethernet device ID  */
end_comment

begin_define
define|#
directive|define
name|SK_DEVICEID_GE
value|0x4300
end_define

begin_comment
comment|/*  * GEnesis registers. The GEnesis chip has a 256-byte I/O window  * but internally it has a 16K register space. This 16K space is  * divided into 128-byte blocks. The first 128 bytes of the I/O  * window represent the first block, which is permanently mapped  * at the start of the window. The other 127 blocks can be mapped  * to the second 128 bytes of the I/O window by setting the desired  * block value in the RAP register in block 0. Not all of the 127  * blocks are actually used. Most registers are 32 bits wide, but  * there are a few 16-bit and 8-bit ones as well.  */
end_comment

begin_comment
comment|/* Start of remappable register window. */
end_comment

begin_define
define|#
directive|define
name|SK_WIN_BASE
value|0x0080
end_define

begin_comment
comment|/* Size of a window */
end_comment

begin_define
define|#
directive|define
name|SK_WIN_LEN
value|0x80
end_define

begin_define
define|#
directive|define
name|SK_WIN_MASK
value|0x3F80
end_define

begin_define
define|#
directive|define
name|SK_REG_MASK
value|0x7F
end_define

begin_comment
comment|/* Compute the window of a given register (for the RAP register) */
end_comment

begin_define
define|#
directive|define
name|SK_WIN
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& SK_WIN_MASK) / SK_WIN_LEN)
end_define

begin_comment
comment|/* Compute the relative offset of a register within the window */
end_comment

begin_define
define|#
directive|define
name|SK_REG
parameter_list|(
name|reg
parameter_list|)
value|((reg)& SK_REG_MASK)
end_define

begin_define
define|#
directive|define
name|SK_PORT_A
value|0
end_define

begin_define
define|#
directive|define
name|SK_PORT_B
value|1
end_define

begin_comment
comment|/*  * Compute offset of port-specific register. Since there are two  * ports, there are two of some GEnesis modules (e.g. two sets of  * DMA queues, two sets of FIFO control registers, etc...). Normally,  * the block for port 0 is at offset 0x0 and the block for port 1 is  * at offset 0x80 (i.e. the next page over). However for the transmit  * BMUs and RAMbuffers, there are two blocks for each port: one for  * the sync transmit queue and one for the async queue (which we don't  * use). However instead of ordering them like this:  * TX sync 1 / TX sync 2 / TX async 1 / TX async 2  * SysKonnect has instead ordered them like this:  * TX sync 1 / TX async 1 / TX sync 2 / TX async 2  * This means that when referencing the TX BMU and RAMbuffer registers,  * we have to double the block offset (0x80 * 2) in order to reach the  * second queue. This prevents us from using the same formula  * (sk_port * 0x80) to compute the offsets for all of the port-specific  * blocks: we need an extra offset for the BMU and RAMbuffer registers.  * The simplest thing is to provide an extra argument to these macros:  * the 'skip' parameter. The 'skip' value is the number of extra pages  * for skip when computing the port0/port1 offsets. For most registers,  * the skip value is 0; for the BMU and RAMbuffer registers, it's 1.  */
end_comment

begin_define
define|#
directive|define
name|SK_IF_READ_4
parameter_list|(
name|sc_if
parameter_list|,
name|skip
parameter_list|,
name|reg
parameter_list|)
define|\
value|sk_win_read_4(sc_if->sk_softc, reg +	\ 	((sc_if->sk_port * (skip + 1)) * SK_WIN_LEN))
end_define

begin_define
define|#
directive|define
name|SK_IF_READ_2
parameter_list|(
name|sc_if
parameter_list|,
name|skip
parameter_list|,
name|reg
parameter_list|)
define|\
value|sk_win_read_2(sc_if->sk_softc, reg + 	\ 	((sc_if->sk_port * (skip + 1)) * SK_WIN_LEN))
end_define

begin_define
define|#
directive|define
name|SK_IF_READ_1
parameter_list|(
name|sc_if
parameter_list|,
name|skip
parameter_list|,
name|reg
parameter_list|)
define|\
value|sk_win_read_1(sc_if->sk_softc, reg +	\ 	((sc_if->sk_port * (skip + 1)) * SK_WIN_LEN))
end_define

begin_define
define|#
directive|define
name|SK_IF_WRITE_4
parameter_list|(
name|sc_if
parameter_list|,
name|skip
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_win_write_4(sc_if->sk_softc,		\ 	reg + ((sc_if->sk_port * (skip + 1)) * SK_WIN_LEN), val)
end_define

begin_define
define|#
directive|define
name|SK_IF_WRITE_2
parameter_list|(
name|sc_if
parameter_list|,
name|skip
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_win_write_2(sc_if->sk_softc,		\ 	reg + ((sc_if->sk_port * (skip + 1)) * SK_WIN_LEN), val)
end_define

begin_define
define|#
directive|define
name|SK_IF_WRITE_1
parameter_list|(
name|sc_if
parameter_list|,
name|skip
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_win_write_1(sc_if->sk_softc,		\ 	reg + ((sc_if->sk_port * (skip + 1)) * SK_WIN_LEN), val)
end_define

begin_comment
comment|/* Block 0 registers, permanently mapped at iobase. */
end_comment

begin_define
define|#
directive|define
name|SK_RAP
value|0x0000
end_define

begin_define
define|#
directive|define
name|SK_CSR
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_LED
value|0x0006
end_define

begin_define
define|#
directive|define
name|SK_ISR
value|0x0008
end_define

begin_comment
comment|/* interrupt source */
end_comment

begin_define
define|#
directive|define
name|SK_IMR
value|0x000C
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|SK_IESR
value|0x0010
end_define

begin_comment
comment|/* interrupt hardware error source */
end_comment

begin_define
define|#
directive|define
name|SK_IEMR
value|0x0014
end_define

begin_comment
comment|/* interrupt hardware error mask */
end_comment

begin_define
define|#
directive|define
name|SK_ISSR
value|0x0018
end_define

begin_comment
comment|/* special interrupt source */
end_comment

begin_define
define|#
directive|define
name|SK_XM_IMR0
value|0x0020
end_define

begin_define
define|#
directive|define
name|SK_XM_ISR0
value|0x0028
end_define

begin_define
define|#
directive|define
name|SK_XM_PHYADDR0
value|0x0030
end_define

begin_define
define|#
directive|define
name|SK_XM_PHYDATA0
value|0x0034
end_define

begin_define
define|#
directive|define
name|SK_XM_IMR1
value|0x0040
end_define

begin_define
define|#
directive|define
name|SK_XM_ISR1
value|0x0048
end_define

begin_define
define|#
directive|define
name|SK_XM_PHYADDR1
value|0x0050
end_define

begin_define
define|#
directive|define
name|SK_XM_PHYDATA1
value|0x0054
end_define

begin_define
define|#
directive|define
name|SK_BMU_RX_CSR0
value|0x0060
end_define

begin_define
define|#
directive|define
name|SK_BMU_RX_CSR1
value|0x0064
end_define

begin_define
define|#
directive|define
name|SK_BMU_TXS_CSR0
value|0x0068
end_define

begin_define
define|#
directive|define
name|SK_BMU_TXA_CSR0
value|0x006C
end_define

begin_define
define|#
directive|define
name|SK_BMU_TXS_CSR1
value|0x0070
end_define

begin_define
define|#
directive|define
name|SK_BMU_TXA_CSR1
value|0x0074
end_define

begin_comment
comment|/* SK_CSR register */
end_comment

begin_define
define|#
directive|define
name|SK_CSR_SW_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_CSR_SW_UNRESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_CSR_MASTER_RESET
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_CSR_MASTER_UNRESET
value|0x0008
end_define

begin_define
define|#
directive|define
name|SK_CSR_MASTER_STOP
value|0x0010
end_define

begin_define
define|#
directive|define
name|SK_CSR_MASTER_DONE
value|0x0020
end_define

begin_define
define|#
directive|define
name|SK_CSR_SW_IRQ_CLEAR
value|0x0040
end_define

begin_define
define|#
directive|define
name|SK_CSR_SW_IRQ_SET
value|0x0080
end_define

begin_define
define|#
directive|define
name|SK_CSR_SLOTSIZE
value|0x0100
end_define

begin_comment
comment|/* 1 == 64 bits, 0 == 32 */
end_comment

begin_define
define|#
directive|define
name|SK_CSR_BUSCLOCK
value|0x0200
end_define

begin_comment
comment|/* 1 == 33/66 Mhz, = 33 */
end_comment

begin_comment
comment|/* SK_LED register */
end_comment

begin_define
define|#
directive|define
name|SK_LED_GREEN_OFF
value|0x01
end_define

begin_define
define|#
directive|define
name|SK_LED_GREEN_ON
value|0x02
end_define

begin_comment
comment|/* SK_ISR register */
end_comment

begin_define
define|#
directive|define
name|SK_ISR_TX2_AS_CHECK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX2_AS_EOF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX2_AS_EOB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX2_S_CHECK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX2_S_EOF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX2_S_EOB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX1_AS_CHECK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX1_AS_EOF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX1_AS_EOB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX1_S_CHECK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX1_S_EOF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX1_S_EOB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SK_ISR_RX2_CHECK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SK_ISR_RX2_EOF
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SK_ISR_RX2_EOB
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SK_ISR_RX1_CHECK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SK_ISR_RX1_EOF
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SK_ISR_RX1_EOB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SK_ISR_LINK2_OFLOW
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SK_ISR_MAC2
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SK_ISR_LINK1_OFLOW
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SK_ISR_MAC1
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SK_ISR_TIMER
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SK_ISR_EXTERNAL_REG
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SK_ISR_SW
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SK_ISR_I2C_RDY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX2_TIMEO
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SK_ISR_TX1_TIMEO
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SK_ISR_RX2_TIMEO
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SK_ISR_RX1_TIMEO
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SK_ISR_RSVD
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SK_ISR_HWERR
value|0x80000000
end_define

begin_comment
comment|/* SK_IMR register */
end_comment

begin_define
define|#
directive|define
name|SK_IMR_TX2_AS_CHECK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX2_AS_EOF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX2_AS_EOB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX2_S_CHECK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX2_S_EOF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX2_S_EOB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX1_AS_CHECK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX1_AS_EOF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX1_AS_EOB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX1_S_CHECK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX1_S_EOF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX1_S_EOB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SK_IMR_RX2_CHECK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SK_IMR_RX2_EOF
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SK_IMR_RX2_EOB
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SK_IMR_RX1_CHECK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SK_IMR_RX1_EOF
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SK_IMR_RX1_EOB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SK_IMR_LINK2_OFLOW
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SK_IMR_MAC2
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SK_IMR_LINK1_OFLOW
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SK_IMR_MAC1
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SK_IMR_TIMER
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SK_IMR_EXTERNAL_REG
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SK_IMR_SW
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SK_IMR_I2C_RDY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX2_TIMEO
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SK_IMR_TX1_TIMEO
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SK_IMR_RX2_TIMEO
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SK_IMR_RX1_TIMEO
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SK_IMR_RSVD
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SK_IMR_HWERR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SK_INTRS1
define|\
value|(SK_IMR_RX1_EOF|SK_IMR_TX1_S_EOF|SK_IMR_MAC1)
end_define

begin_define
define|#
directive|define
name|SK_INTRS2
define|\
value|(SK_IMR_RX2_EOF|SK_IMR_TX2_S_EOF|SK_IMR_MAC2)
end_define

begin_comment
comment|/* SK_IESR register */
end_comment

begin_define
define|#
directive|define
name|SK_IESR_PAR_RX2
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_IESR_PAR_RX1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_IESR_PAR_MAC2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_IESR_PAR_MAC1
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_IESR_PAR_WR_RAM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_IESR_PAR_RD_RAM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_IESR_NO_TSTAMP_MAC2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_IESR_NO_TSTAMO_MAC1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_IESR_NO_STS_MAC2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_IESR_NO_STS_MAC1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_IESR_IRQ_STS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SK_IESR_MASTERERR
value|0x00000800
end_define

begin_comment
comment|/* SK_IEMR register */
end_comment

begin_define
define|#
directive|define
name|SK_IEMR_PAR_RX2
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_IEMR_PAR_RX1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_IEMR_PAR_MAC2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_IEMR_PAR_MAC1
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_IEMR_PAR_WR_RAM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_IEMR_PAR_RD_RAM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_IEMR_NO_TSTAMP_MAC2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_IEMR_NO_TSTAMO_MAC1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_IEMR_NO_STS_MAC2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_IEMR_NO_STS_MAC1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_IEMR_IRQ_STS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SK_IEMR_MASTERERR
value|0x00000800
end_define

begin_comment
comment|/* Block 2 */
end_comment

begin_define
define|#
directive|define
name|SK_MAC0_0
value|0x0100
end_define

begin_define
define|#
directive|define
name|SK_MAC0_1
value|0x0104
end_define

begin_define
define|#
directive|define
name|SK_MAC1_0
value|0x0108
end_define

begin_define
define|#
directive|define
name|SK_MAC1_1
value|0x010C
end_define

begin_define
define|#
directive|define
name|SK_MAC2_0
value|0x0110
end_define

begin_define
define|#
directive|define
name|SK_MAC2_1
value|0x0114
end_define

begin_define
define|#
directive|define
name|SK_CONNTYPE
value|0x0118
end_define

begin_define
define|#
directive|define
name|SK_PMDTYPE
value|0x0119
end_define

begin_define
define|#
directive|define
name|SK_CONFIG
value|0x011A
end_define

begin_define
define|#
directive|define
name|SK_CHIPVER
value|0x011B
end_define

begin_define
define|#
directive|define
name|SK_EPROM0
value|0x011C
end_define

begin_define
define|#
directive|define
name|SK_EPROM1
value|0x011D
end_define

begin_define
define|#
directive|define
name|SK_EPROM2
value|0x011E
end_define

begin_define
define|#
directive|define
name|SK_EPROM3
value|0x011F
end_define

begin_define
define|#
directive|define
name|SK_EP_ADDR
value|0x0120
end_define

begin_define
define|#
directive|define
name|SK_EP_DATA
value|0x0124
end_define

begin_define
define|#
directive|define
name|SK_EP_LOADCTL
value|0x0128
end_define

begin_define
define|#
directive|define
name|SK_EP_LOADTST
value|0x0129
end_define

begin_define
define|#
directive|define
name|SK_TIMERINIT
value|0x0130
end_define

begin_define
define|#
directive|define
name|SK_TIMER
value|0x0134
end_define

begin_define
define|#
directive|define
name|SK_TIMERCTL
value|0x0138
end_define

begin_define
define|#
directive|define
name|SK_TIMERTST
value|0x0139
end_define

begin_define
define|#
directive|define
name|SK_IMTIMERINIT
value|0x0140
end_define

begin_define
define|#
directive|define
name|SK_IMTIMER
value|0x0144
end_define

begin_define
define|#
directive|define
name|SK_IMTIMERCTL
value|0x0148
end_define

begin_define
define|#
directive|define
name|SK_IMTIMERTST
value|0x0149
end_define

begin_define
define|#
directive|define
name|SK_IMMR
value|0x014C
end_define

begin_define
define|#
directive|define
name|SK_IHWEMR
value|0x0150
end_define

begin_define
define|#
directive|define
name|SK_TESTCTL1
value|0x0158
end_define

begin_define
define|#
directive|define
name|SK_TESTCTL2
value|0x0159
end_define

begin_define
define|#
directive|define
name|SK_GPIO
value|0x015C
end_define

begin_define
define|#
directive|define
name|SK_I2CHWCTL
value|0x0160
end_define

begin_define
define|#
directive|define
name|SK_I2CHWDATA
value|0x0164
end_define

begin_define
define|#
directive|define
name|SK_I2CHWIRQ
value|0x0168
end_define

begin_define
define|#
directive|define
name|SK_I2CSW
value|0x016C
end_define

begin_define
define|#
directive|define
name|SK_BLNKINIT
value|0x0170
end_define

begin_define
define|#
directive|define
name|SK_BLNKCOUNT
value|0x0174
end_define

begin_define
define|#
directive|define
name|SK_BLNKCTL
value|0x0178
end_define

begin_define
define|#
directive|define
name|SK_BLNKSTS
value|0x0179
end_define

begin_define
define|#
directive|define
name|SK_BLNKTST
value|0x017A
end_define

begin_define
define|#
directive|define
name|SK_IMCTL_STOP
value|0x02
end_define

begin_define
define|#
directive|define
name|SK_IMCTL_START
value|0x04
end_define

begin_define
define|#
directive|define
name|SK_IMTIMER_TICKS
value|54
end_define

begin_define
define|#
directive|define
name|SK_IM_USECS
parameter_list|(
name|x
parameter_list|)
value|((x) * SK_IMTIMER_TICKS)
end_define

begin_comment
comment|/*  * The SK_EPROM0 register contains a byte that describes the  * amount of SRAM mounted on the NIC. The value also tells if  * the chips are 64K or 128K. This affects the RAMbuffer address  * offset that we need to use.  */
end_comment

begin_define
define|#
directive|define
name|SK_RAMSIZE_512K_64
value|0x1
end_define

begin_define
define|#
directive|define
name|SK_RAMSIZE_1024K_128
value|0x2
end_define

begin_define
define|#
directive|define
name|SK_RAMSIZE_1024K_64
value|0x3
end_define

begin_define
define|#
directive|define
name|SK_RAMSIZE_2048K_128
value|0x4
end_define

begin_define
define|#
directive|define
name|SK_RBOFF_0
value|0x0
end_define

begin_define
define|#
directive|define
name|SK_RBOFF_80000
value|0x80000
end_define

begin_comment
comment|/*  * SK_EEPROM1 contains the PHY type, which may be XMAC for  * fiber-based cards or BCOM for 1000baseT cards with a Broadcom  * PHY.  */
end_comment

begin_define
define|#
directive|define
name|SK_PHYTYPE_XMAC
value|0
end_define

begin_comment
comment|/* integeated XMAC II PHY */
end_comment

begin_define
define|#
directive|define
name|SK_PHYTYPE_BCOM
value|1
end_define

begin_comment
comment|/* Broadcom BCM5400 */
end_comment

begin_define
define|#
directive|define
name|SK_PHYTYPE_LONE
value|2
end_define

begin_comment
comment|/* Level One LXT1000 */
end_comment

begin_define
define|#
directive|define
name|SK_PHYTYPE_NAT
value|3
end_define

begin_comment
comment|/* National DP83891 */
end_comment

begin_comment
comment|/*  * PHY addresses.  */
end_comment

begin_define
define|#
directive|define
name|SK_PHYADDR_XMAC
value|0x0
end_define

begin_define
define|#
directive|define
name|SK_PHYADDR_BCOM
value|0x1
end_define

begin_define
define|#
directive|define
name|SK_PHYADDR_LONE
value|0x3
end_define

begin_define
define|#
directive|define
name|SK_PHYADDR_NAT
value|0x0
end_define

begin_define
define|#
directive|define
name|SK_CONFIG_SINGLEMAC
value|0x01
end_define

begin_define
define|#
directive|define
name|SK_CONFIG_DIS_DSL_CLK
value|0x02
end_define

begin_define
define|#
directive|define
name|SK_PMD_1000BASELX
value|0x4C
end_define

begin_define
define|#
directive|define
name|SK_PMD_1000BASESX
value|0x53
end_define

begin_define
define|#
directive|define
name|SK_PMD_1000BASECX
value|0x43
end_define

begin_define
define|#
directive|define
name|SK_PMD_1000BASETX
value|0x54
end_define

begin_comment
comment|/* GPIO bits */
end_comment

begin_define
define|#
directive|define
name|SK_GPIO_DAT0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT8
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DAT9
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR3
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR4
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR5
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR6
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR7
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR8
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SK_GPIO_DIR9
value|0x02000000
end_define

begin_comment
comment|/* Block 3 Ram interface and MAC arbiter registers */
end_comment

begin_define
define|#
directive|define
name|SK_RAMADDR
value|0x0180
end_define

begin_define
define|#
directive|define
name|SK_RAMDATA0
value|0x0184
end_define

begin_define
define|#
directive|define
name|SK_RAMDATA1
value|0x0188
end_define

begin_define
define|#
directive|define
name|SK_TO0
value|0x0190
end_define

begin_define
define|#
directive|define
name|SK_TO1
value|0x0191
end_define

begin_define
define|#
directive|define
name|SK_TO2
value|0x0192
end_define

begin_define
define|#
directive|define
name|SK_TO3
value|0x0193
end_define

begin_define
define|#
directive|define
name|SK_TO4
value|0x0194
end_define

begin_define
define|#
directive|define
name|SK_TO5
value|0x0195
end_define

begin_define
define|#
directive|define
name|SK_TO6
value|0x0196
end_define

begin_define
define|#
directive|define
name|SK_TO7
value|0x0197
end_define

begin_define
define|#
directive|define
name|SK_TO8
value|0x0198
end_define

begin_define
define|#
directive|define
name|SK_TO9
value|0x0199
end_define

begin_define
define|#
directive|define
name|SK_TO10
value|0x019A
end_define

begin_define
define|#
directive|define
name|SK_TO11
value|0x019B
end_define

begin_define
define|#
directive|define
name|SK_RITIMEO_TMR
value|0x019C
end_define

begin_define
define|#
directive|define
name|SK_RAMCTL
value|0x01A0
end_define

begin_define
define|#
directive|define
name|SK_RITIMER_TST
value|0x01A2
end_define

begin_define
define|#
directive|define
name|SK_RAMCTL_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_RAMCTL_UNRESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_RAMCTL_CLR_IRQ_WPAR
value|0x0100
end_define

begin_define
define|#
directive|define
name|SK_RAMCTL_CLR_IRQ_RPAR
value|0x0200
end_define

begin_comment
comment|/* Mac arbiter registers */
end_comment

begin_define
define|#
directive|define
name|SK_MINIT_RX1
value|0x01B0
end_define

begin_define
define|#
directive|define
name|SK_MINIT_RX2
value|0x01B1
end_define

begin_define
define|#
directive|define
name|SK_MINIT_TX1
value|0x01B2
end_define

begin_define
define|#
directive|define
name|SK_MINIT_TX2
value|0x01B3
end_define

begin_define
define|#
directive|define
name|SK_MTIMEO_RX1
value|0x01B4
end_define

begin_define
define|#
directive|define
name|SK_MTIMEO_RX2
value|0x01B5
end_define

begin_define
define|#
directive|define
name|SK_MTIMEO_TX1
value|0x01B6
end_define

begin_define
define|#
directive|define
name|SK_MTIEMO_TX2
value|0x01B7
end_define

begin_define
define|#
directive|define
name|SK_MACARB_CTL
value|0x01B8
end_define

begin_define
define|#
directive|define
name|SK_MTIMER_TST
value|0x01BA
end_define

begin_define
define|#
directive|define
name|SK_RCINIT_RX1
value|0x01C0
end_define

begin_define
define|#
directive|define
name|SK_RCINIT_RX2
value|0x01C1
end_define

begin_define
define|#
directive|define
name|SK_RCINIT_TX1
value|0x01C2
end_define

begin_define
define|#
directive|define
name|SK_RCINIT_TX2
value|0x01C3
end_define

begin_define
define|#
directive|define
name|SK_RCTIMEO_RX1
value|0x01C4
end_define

begin_define
define|#
directive|define
name|SK_RCTIMEO_RX2
value|0x01C5
end_define

begin_define
define|#
directive|define
name|SK_RCTIMEO_TX1
value|0x01C6
end_define

begin_define
define|#
directive|define
name|SK_RCTIMEO_TX2
value|0x01C7
end_define

begin_define
define|#
directive|define
name|SK_RECOVERY_CTL
value|0x01C8
end_define

begin_define
define|#
directive|define
name|SK_RCTIMER_TST
value|0x01CA
end_define

begin_comment
comment|/* Packet arbiter registers */
end_comment

begin_define
define|#
directive|define
name|SK_RXPA1_TINIT
value|0x01D0
end_define

begin_define
define|#
directive|define
name|SK_RXPA2_TINIT
value|0x01D4
end_define

begin_define
define|#
directive|define
name|SK_TXPA1_TINIT
value|0x01D8
end_define

begin_define
define|#
directive|define
name|SK_TXPA2_TINIT
value|0x01DC
end_define

begin_define
define|#
directive|define
name|SK_RXPA1_TIMEO
value|0x01E0
end_define

begin_define
define|#
directive|define
name|SK_RXPA2_TIMEO
value|0x01E4
end_define

begin_define
define|#
directive|define
name|SK_TXPA1_TIMEO
value|0x01E8
end_define

begin_define
define|#
directive|define
name|SK_TXPA2_TIMEO
value|0x01EC
end_define

begin_define
define|#
directive|define
name|SK_PKTARB_CTL
value|0x01F0
end_define

begin_define
define|#
directive|define
name|SK_PKTATB_TST
value|0x01F2
end_define

begin_define
define|#
directive|define
name|SK_PKTARB_TIMEOUT
value|0x2000
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_UNRESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_RXTO1_OFF
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_RXTO1_ON
value|0x0008
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_RXTO2_OFF
value|0x0010
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_RXTO2_ON
value|0x0020
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_TXTO1_OFF
value|0x0040
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_TXTO1_ON
value|0x0080
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_TXTO2_OFF
value|0x0100
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_TXTO2_ON
value|0x0200
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_CLR_IRQ_RXTO1
value|0x0400
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_CLR_IRQ_RXTO2
value|0x0800
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_CLR_IRQ_TXTO1
value|0x1000
end_define

begin_define
define|#
directive|define
name|SK_PKTARBCTL_CLR_IRQ_TXTO2
value|0x2000
end_define

begin_define
define|#
directive|define
name|SK_MINIT_XMAC_B2
value|54
end_define

begin_define
define|#
directive|define
name|SK_MINIT_XMAC_C1
value|63
end_define

begin_define
define|#
directive|define
name|SK_MACARBCTL_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_MACARBCTL_UNRESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_MACARBCTL_FASTOE_OFF
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_MACARBCRL_FASTOE_ON
value|0x0008
end_define

begin_define
define|#
directive|define
name|SK_RCINIT_XMAC_B2
value|54
end_define

begin_define
define|#
directive|define
name|SK_RCINIT_XMAC_C1
value|0
end_define

begin_define
define|#
directive|define
name|SK_RECOVERYCTL_RX1_OFF
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_RECOVERYCTL_RX1_ON
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_RECOVERYCTL_RX2_OFF
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_RECOVERYCTL_RX2_ON
value|0x0008
end_define

begin_define
define|#
directive|define
name|SK_RECOVERYCTL_TX1_OFF
value|0x0010
end_define

begin_define
define|#
directive|define
name|SK_RECOVERYCTL_TX1_ON
value|0x0020
end_define

begin_define
define|#
directive|define
name|SK_RECOVERYCTL_TX2_OFF
value|0x0040
end_define

begin_define
define|#
directive|define
name|SK_RECOVERYCTL_TX2_ON
value|0x0080
end_define

begin_define
define|#
directive|define
name|SK_RECOVERY_XMAC_B2
define|\
value|(SK_RECOVERYCTL_RX1_ON|SK_RECOVERYCTL_RX2_ON|	\ 	SK_RECOVERYCTL_TX1_ON|SK_RECOVERYCTL_TX2_ON)
end_define

begin_define
define|#
directive|define
name|SK_RECOVERY_XMAC_C1
define|\
value|(SK_RECOVERYCTL_RX1_OFF|SK_RECOVERYCTL_RX2_OFF|	\ 	SK_RECOVERYCTL_TX1_OFF|SK_RECOVERYCTL_TX2_OFF)
end_define

begin_comment
comment|/* Block 4 -- TX Arbiter MAC 1 */
end_comment

begin_define
define|#
directive|define
name|SK_TXAR1_TIMERINIT
value|0x0200
end_define

begin_define
define|#
directive|define
name|SK_TXAR1_TIMERVAL
value|0x0204
end_define

begin_define
define|#
directive|define
name|SK_TXAR1_LIMITINIT
value|0x0208
end_define

begin_define
define|#
directive|define
name|SK_TXAR1_LIMITCNT
value|0x020C
end_define

begin_define
define|#
directive|define
name|SK_TXAR1_COUNTERCTL
value|0x0210
end_define

begin_define
define|#
directive|define
name|SK_TXAR1_COUNTERTST
value|0x0212
end_define

begin_define
define|#
directive|define
name|SK_TXAR1_COUNTERSTS
value|0x0212
end_define

begin_comment
comment|/* Block 5 -- TX Arbiter MAC 2 */
end_comment

begin_define
define|#
directive|define
name|SK_TXAR2_TIMERINIT
value|0x0280
end_define

begin_define
define|#
directive|define
name|SK_TXAR2_TIMERVAL
value|0x0284
end_define

begin_define
define|#
directive|define
name|SK_TXAR2_LIMITINIT
value|0x0288
end_define

begin_define
define|#
directive|define
name|SK_TXAR2_LIMITCNT
value|0x028C
end_define

begin_define
define|#
directive|define
name|SK_TXAR2_COUNTERCTL
value|0x0290
end_define

begin_define
define|#
directive|define
name|SK_TXAR2_COUNTERTST
value|0x0291
end_define

begin_define
define|#
directive|define
name|SK_TXAR2_COUNTERSTS
value|0x0292
end_define

begin_define
define|#
directive|define
name|SK_TXARCTL_OFF
value|0x01
end_define

begin_define
define|#
directive|define
name|SK_TXARCTL_ON
value|0x02
end_define

begin_define
define|#
directive|define
name|SK_TXARCTL_RATECTL_OFF
value|0x04
end_define

begin_define
define|#
directive|define
name|SK_TXARCTL_RATECTL_ON
value|0x08
end_define

begin_define
define|#
directive|define
name|SK_TXARCTL_ALLOC_OFF
value|0x10
end_define

begin_define
define|#
directive|define
name|SK_TXARCTL_ALLOC_ON
value|0x20
end_define

begin_define
define|#
directive|define
name|SK_TXARCTL_FSYNC_OFF
value|0x40
end_define

begin_define
define|#
directive|define
name|SK_TXARCTL_FSYNC_ON
value|0x80
end_define

begin_comment
comment|/* Block 6 -- External registers */
end_comment

begin_define
define|#
directive|define
name|SK_EXTREG_BASE
value|0x300
end_define

begin_define
define|#
directive|define
name|SK_EXTREG_END
value|0x37C
end_define

begin_comment
comment|/* Block 7 -- PCI config registers */
end_comment

begin_define
define|#
directive|define
name|SK_PCI_BASE
value|0x0380
end_define

begin_define
define|#
directive|define
name|SK_PCI_END
value|0x03FC
end_define

begin_comment
comment|/* Compute offset of mirrored PCI register */
end_comment

begin_define
define|#
directive|define
name|SK_PCI_REG
parameter_list|(
name|reg
parameter_list|)
value|((reg) + SK_PCI_BASE)
end_define

begin_comment
comment|/* Block 8 -- RX queue 1 */
end_comment

begin_define
define|#
directive|define
name|SK_RXQ1_BUFCNT
value|0x0400
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_BUFCTL
value|0x0402
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_NEXTDESC
value|0x0404
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_RXBUF_LO
value|0x0408
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_RXBUF_HI
value|0x040C
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_RXSTAT
value|0x0410
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_TIMESTAMP
value|0x0414
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CSUM1
value|0x0418
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CSUM2
value|0x041A
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CSUM1_START
value|0x041C
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CSUM2_START
value|0x041E
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CURADDR_LO
value|0x0420
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CURADDR_HI
value|0x0424
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CURCNT_LO
value|0x0428
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CURCNT_HI
value|0x042C
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_CURBYTES
value|0x0430
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_BMU_CSR
value|0x0434
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_WATERMARK
value|0x0438
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_FLAG
value|0x043A
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_TEST1
value|0x043C
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_TEST2
value|0x0440
end_define

begin_define
define|#
directive|define
name|SK_RXQ1_TEST3
value|0x0444
end_define

begin_comment
comment|/* Block 9 -- RX queue 2 */
end_comment

begin_define
define|#
directive|define
name|SK_RXQ2_BUFCNT
value|0x0480
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_BUFCTL
value|0x0482
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_NEXTDESC
value|0x0484
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_RXBUF_LO
value|0x0488
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_RXBUF_HI
value|0x048C
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_RXSTAT
value|0x0490
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_TIMESTAMP
value|0x0494
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CSUM1
value|0x0498
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CSUM2
value|0x049A
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CSUM1_START
value|0x049C
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CSUM2_START
value|0x049E
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CURADDR_LO
value|0x04A0
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CURADDR_HI
value|0x04A4
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CURCNT_LO
value|0x04A8
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CURCNT_HI
value|0x04AC
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_CURBYTES
value|0x04B0
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_BMU_CSR
value|0x04B4
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_WATERMARK
value|0x04B8
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_FLAG
value|0x04BA
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_TEST1
value|0x04BC
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_TEST2
value|0x04C0
end_define

begin_define
define|#
directive|define
name|SK_RXQ2_TEST3
value|0x04C4
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_CLR_IRQ_ERR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_CLR_IRQ_EOF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_CLR_IRQ_EOB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_CLR_IRQ_PAR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_RX_START
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_RX_STOP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_POLL_OFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_POLL_ON
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_TRANSFER_SM_RESET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_TRANSFER_SM_UNRESET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_DESCWR_SM_RESET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_DESCWR_SM_UNRESET
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_DESCRD_SM_RESET
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_DESCRD_SM_UNRESET
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_SUPERVISOR_SM_RESET
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_SUPERVISOR_SM_UNRESET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_PFI_SM_RESET
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_PFI_SM_UNRESET
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_FIFO_RESET
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_FIFO_UNRESET
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_DESC_RESET
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_DESC_UNRESET
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_SUPERVISOR_IDLE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_ONLINE
define|\
value|(SK_RXBMU_TRANSFER_SM_UNRESET|SK_RXBMU_DESCWR_SM_UNRESET|	\ 	SK_RXBMU_DESCRD_SM_UNRESET|SK_RXBMU_SUPERVISOR_SM_UNRESET|	\ 	SK_RXBMU_PFI_SM_UNRESET|SK_RXBMU_FIFO_UNRESET|			\ 	SK_RXBMU_DESC_UNRESET)
end_define

begin_define
define|#
directive|define
name|SK_RXBMU_OFFLINE
define|\
value|(SK_RXBMU_TRANSFER_SM_RESET|SK_RXBMU_DESCWR_SM_RESET|	\ 	SK_RXBMU_DESCRD_SM_RESET|SK_RXBMU_SUPERVISOR_SM_RESET|	\ 	SK_RXBMU_PFI_SM_RESET|SK_RXBMU_FIFO_RESET|		\ 	SK_RXBMU_DESC_RESET)
end_define

begin_comment
comment|/* Block 12 -- TX sync queue 1 */
end_comment

begin_define
define|#
directive|define
name|SK_TXQS1_BUFCNT
value|0x0600
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_BUFCTL
value|0x0602
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_NEXTDESC
value|0x0604
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_RXBUF_LO
value|0x0608
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_RXBUF_HI
value|0x060C
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_RXSTAT
value|0x0610
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_CSUM_STARTVAL
value|0x0614
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_CSUM_STARTPOS
value|0x0618
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_CSUM_WRITEPOS
value|0x061A
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_CURADDR_LO
value|0x0620
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_CURADDR_HI
value|0x0624
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_CURCNT_LO
value|0x0628
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_CURCNT_HI
value|0x062C
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_CURBYTES
value|0x0630
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_BMU_CSR
value|0x0634
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_WATERMARK
value|0x0638
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_FLAG
value|0x063A
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_TEST1
value|0x063C
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_TEST2
value|0x0640
end_define

begin_define
define|#
directive|define
name|SK_TXQS1_TEST3
value|0x0644
end_define

begin_comment
comment|/* Block 13 -- TX async queue 1 */
end_comment

begin_define
define|#
directive|define
name|SK_TXQA1_BUFCNT
value|0x0680
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_BUFCTL
value|0x0682
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_NEXTDESC
value|0x0684
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_RXBUF_LO
value|0x0688
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_RXBUF_HI
value|0x068C
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_RXSTAT
value|0x0690
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_CSUM_STARTVAL
value|0x0694
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_CSUM_STARTPOS
value|0x0698
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_CSUM_WRITEPOS
value|0x069A
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_CURADDR_LO
value|0x06A0
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_CURADDR_HI
value|0x06A4
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_CURCNT_LO
value|0x06A8
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_CURCNT_HI
value|0x06AC
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_CURBYTES
value|0x06B0
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_BMU_CSR
value|0x06B4
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_WATERMARK
value|0x06B8
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_FLAG
value|0x06BA
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_TEST1
value|0x06BC
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_TEST2
value|0x06C0
end_define

begin_define
define|#
directive|define
name|SK_TXQA1_TEST3
value|0x06C4
end_define

begin_comment
comment|/* Block 14 -- TX sync queue 2 */
end_comment

begin_define
define|#
directive|define
name|SK_TXQS2_BUFCNT
value|0x0700
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_BUFCTL
value|0x0702
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_NEXTDESC
value|0x0704
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_RXBUF_LO
value|0x0708
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_RXBUF_HI
value|0x070C
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_RXSTAT
value|0x0710
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_CSUM_STARTVAL
value|0x0714
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_CSUM_STARTPOS
value|0x0718
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_CSUM_WRITEPOS
value|0x071A
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_CURADDR_LO
value|0x0720
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_CURADDR_HI
value|0x0724
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_CURCNT_LO
value|0x0728
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_CURCNT_HI
value|0x072C
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_CURBYTES
value|0x0730
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_BMU_CSR
value|0x0734
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_WATERMARK
value|0x0738
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_FLAG
value|0x073A
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_TEST1
value|0x073C
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_TEST2
value|0x0740
end_define

begin_define
define|#
directive|define
name|SK_TXQS2_TEST3
value|0x0744
end_define

begin_comment
comment|/* Block 15 -- TX async queue 2 */
end_comment

begin_define
define|#
directive|define
name|SK_TXQA2_BUFCNT
value|0x0780
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_BUFCTL
value|0x0782
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_NEXTDESC
value|0x0784
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_RXBUF_LO
value|0x0788
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_RXBUF_HI
value|0x078C
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_RXSTAT
value|0x0790
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_CSUM_STARTVAL
value|0x0794
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_CSUM_STARTPOS
value|0x0798
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_CSUM_WRITEPOS
value|0x079A
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_CURADDR_LO
value|0x07A0
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_CURADDR_HI
value|0x07A4
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_CURCNT_LO
value|0x07A8
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_CURCNT_HI
value|0x07AC
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_CURBYTES
value|0x07B0
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_BMU_CSR
value|0x07B4
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_WATERMARK
value|0x07B8
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_FLAG
value|0x07BA
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_TEST1
value|0x07BC
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_TEST2
value|0x07C0
end_define

begin_define
define|#
directive|define
name|SK_TXQA2_TEST3
value|0x07C4
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_CLR_IRQ_ERR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_CLR_IRQ_EOF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_CLR_IRQ_EOB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_TX_START
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_TX_STOP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_POLL_OFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_POLL_ON
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_TRANSFER_SM_RESET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_TRANSFER_SM_UNRESET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_DESCWR_SM_RESET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_DESCWR_SM_UNRESET
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_DESCRD_SM_RESET
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_DESCRD_SM_UNRESET
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_SUPERVISOR_SM_RESET
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_SUPERVISOR_SM_UNRESET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_PFI_SM_RESET
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_PFI_SM_UNRESET
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_FIFO_RESET
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_FIFO_UNRESET
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_DESC_RESET
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_DESC_UNRESET
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_SUPERVISOR_IDLE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_ONLINE
define|\
value|(SK_TXBMU_TRANSFER_SM_UNRESET|SK_TXBMU_DESCWR_SM_UNRESET|	\ 	SK_TXBMU_DESCRD_SM_UNRESET|SK_TXBMU_SUPERVISOR_SM_UNRESET|	\ 	SK_TXBMU_PFI_SM_UNRESET|SK_TXBMU_FIFO_UNRESET|			\ 	SK_TXBMU_DESC_UNRESET)
end_define

begin_define
define|#
directive|define
name|SK_TXBMU_OFFLINE
define|\
value|(SK_TXBMU_TRANSFER_SM_RESET|SK_TXBMU_DESCWR_SM_RESET|	\ 	SK_TXBMU_DESCRD_SM_RESET|SK_TXBMU_SUPERVISOR_SM_RESET|	\ 	SK_TXBMU_PFI_SM_RESET|SK_TXBMU_FIFO_RESET|		\ 	SK_TXBMU_DESC_RESET)
end_define

begin_comment
comment|/* Block 16 -- Receive RAMbuffer 1 */
end_comment

begin_define
define|#
directive|define
name|SK_RXRB1_START
value|0x0800
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_END
value|0x0804
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_WR_PTR
value|0x0808
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_RD_PTR
value|0x080C
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_UTHR_PAUSE
value|0x0810
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_LTHR_PAUSE
value|0x0814
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_UTHR_HIPRIO
value|0x0818
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_UTHR_LOPRIO
value|0x081C
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_PKTCNT
value|0x0820
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_LVL
value|0x0824
end_define

begin_define
define|#
directive|define
name|SK_RXRB1_CTLTST
value|0x0828
end_define

begin_comment
comment|/* Block 17 -- Receive RAMbuffer 2 */
end_comment

begin_define
define|#
directive|define
name|SK_RXRB2_START
value|0x0880
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_END
value|0x0884
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_WR_PTR
value|0x0888
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_RD_PTR
value|0x088C
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_UTHR_PAUSE
value|0x0890
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_LTHR_PAUSE
value|0x0894
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_UTHR_HIPRIO
value|0x0898
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_UTHR_LOPRIO
value|0x089C
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_PKTCNT
value|0x08A0
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_LVL
value|0x08A4
end_define

begin_define
define|#
directive|define
name|SK_RXRB2_CTLTST
value|0x08A8
end_define

begin_comment
comment|/* Block 20 -- Sync. Transmit RAMbuffer 1 */
end_comment

begin_define
define|#
directive|define
name|SK_TXRBS1_START
value|0x0A00
end_define

begin_define
define|#
directive|define
name|SK_TXRBS1_END
value|0x0A04
end_define

begin_define
define|#
directive|define
name|SK_TXRBS1_WR_PTR
value|0x0A08
end_define

begin_define
define|#
directive|define
name|SK_TXRBS1_RD_PTR
value|0x0A0C
end_define

begin_define
define|#
directive|define
name|SK_TXRBS1_PKTCNT
value|0x0A20
end_define

begin_define
define|#
directive|define
name|SK_TXRBS1_LVL
value|0x0A24
end_define

begin_define
define|#
directive|define
name|SK_TXRBS1_CTLTST
value|0x0A28
end_define

begin_comment
comment|/* Block 21 -- Async. Transmit RAMbuffer 1 */
end_comment

begin_define
define|#
directive|define
name|SK_TXRBA1_START
value|0x0A80
end_define

begin_define
define|#
directive|define
name|SK_TXRBA1_END
value|0x0A84
end_define

begin_define
define|#
directive|define
name|SK_TXRBA1_WR_PTR
value|0x0A88
end_define

begin_define
define|#
directive|define
name|SK_TXRBA1_RD_PTR
value|0x0A8C
end_define

begin_define
define|#
directive|define
name|SK_TXRBA1_PKTCNT
value|0x0AA0
end_define

begin_define
define|#
directive|define
name|SK_TXRBA1_LVL
value|0x0AA4
end_define

begin_define
define|#
directive|define
name|SK_TXRBA1_CTLTST
value|0x0AA8
end_define

begin_comment
comment|/* Block 22 -- Sync. Transmit RAMbuffer 2 */
end_comment

begin_define
define|#
directive|define
name|SK_TXRBS2_START
value|0x0B00
end_define

begin_define
define|#
directive|define
name|SK_TXRBS2_END
value|0x0B04
end_define

begin_define
define|#
directive|define
name|SK_TXRBS2_WR_PTR
value|0x0B08
end_define

begin_define
define|#
directive|define
name|SK_TXRBS2_RD_PTR
value|0x0B0C
end_define

begin_define
define|#
directive|define
name|SK_TXRBS2_PKTCNT
value|0x0B20
end_define

begin_define
define|#
directive|define
name|SK_TXRBS2_LVL
value|0x0B24
end_define

begin_define
define|#
directive|define
name|SK_TXRBS2_CTLTST
value|0x0B28
end_define

begin_comment
comment|/* Block 23 -- Async. Transmit RAMbuffer 2 */
end_comment

begin_define
define|#
directive|define
name|SK_TXRBA2_START
value|0x0B80
end_define

begin_define
define|#
directive|define
name|SK_TXRBA2_END
value|0x0B84
end_define

begin_define
define|#
directive|define
name|SK_TXRBA2_WR_PTR
value|0x0B88
end_define

begin_define
define|#
directive|define
name|SK_TXRBA2_RD_PTR
value|0x0B8C
end_define

begin_define
define|#
directive|define
name|SK_TXRBA2_PKTCNT
value|0x0BA0
end_define

begin_define
define|#
directive|define
name|SK_TXRBA2_LVL
value|0x0BA4
end_define

begin_define
define|#
directive|define
name|SK_TXRBA2_CTLTST
value|0x0BA8
end_define

begin_define
define|#
directive|define
name|SK_RBCTL_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_RBCTL_UNRESET
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_RBCTL_OFF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_RBCTL_ON
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_RBCTL_STORENFWD_OFF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_RBCTL_STORENFWD_ON
value|0x00000020
end_define

begin_comment
comment|/* Block 24 -- RX MAC FIFO 1 regisrers and LINK_SYNC counter */
end_comment

begin_define
define|#
directive|define
name|SK_RXF1_END
value|0x0C00
end_define

begin_define
define|#
directive|define
name|SK_RXF1_WPTR
value|0x0C04
end_define

begin_define
define|#
directive|define
name|SK_RXF1_RPTR
value|0x0C0C
end_define

begin_define
define|#
directive|define
name|SK_RXF1_PKTCNT
value|0x0C10
end_define

begin_define
define|#
directive|define
name|SK_RXF1_LVL
value|0x0C14
end_define

begin_define
define|#
directive|define
name|SK_RXF1_MACCTL
value|0x0C18
end_define

begin_define
define|#
directive|define
name|SK_RXF1_CTL
value|0x0C1C
end_define

begin_define
define|#
directive|define
name|SK_RXLED1_CNTINIT
value|0x0C20
end_define

begin_define
define|#
directive|define
name|SK_RXLED1_COUNTER
value|0x0C24
end_define

begin_define
define|#
directive|define
name|SK_RXLED1_CTL
value|0x0C28
end_define

begin_define
define|#
directive|define
name|SK_RXLED1_TST
value|0x0C29
end_define

begin_define
define|#
directive|define
name|SK_LINK_SYNC1_CINIT
value|0x0C30
end_define

begin_define
define|#
directive|define
name|SK_LINK_SYNC1_COUNTER
value|0x0C34
end_define

begin_define
define|#
directive|define
name|SK_LINK_SYNC1_CTL
value|0x0C38
end_define

begin_define
define|#
directive|define
name|SK_LINK_SYNC1_TST
value|0x0C39
end_define

begin_define
define|#
directive|define
name|SK_LINKLED1_CTL
value|0x0C3C
end_define

begin_define
define|#
directive|define
name|SK_FIFO_END
value|0x3F
end_define

begin_comment
comment|/* Block 25 -- RX MAC FIFO 2 regisrers and LINK_SYNC counter */
end_comment

begin_define
define|#
directive|define
name|SK_RXF2_END
value|0x0C80
end_define

begin_define
define|#
directive|define
name|SK_RXF2_WPTR
value|0x0C84
end_define

begin_define
define|#
directive|define
name|SK_RXF2_RPTR
value|0x0C8C
end_define

begin_define
define|#
directive|define
name|SK_RXF2_PKTCNT
value|0x0C90
end_define

begin_define
define|#
directive|define
name|SK_RXF2_LVL
value|0x0C94
end_define

begin_define
define|#
directive|define
name|SK_RXF2_MACCTL
value|0x0C98
end_define

begin_define
define|#
directive|define
name|SK_RXF2_CTL
value|0x0C9C
end_define

begin_define
define|#
directive|define
name|SK_RXLED2_CNTINIT
value|0x0CA0
end_define

begin_define
define|#
directive|define
name|SK_RXLED2_COUNTER
value|0x0CA4
end_define

begin_define
define|#
directive|define
name|SK_RXLED2_CTL
value|0x0CA8
end_define

begin_define
define|#
directive|define
name|SK_RXLED2_TST
value|0x0CA9
end_define

begin_define
define|#
directive|define
name|SK_LINK_SYNC2_CINIT
value|0x0CB0
end_define

begin_define
define|#
directive|define
name|SK_LINK_SYNC2_COUNTER
value|0x0CB4
end_define

begin_define
define|#
directive|define
name|SK_LINK_SYNC2_CTL
value|0x0CB8
end_define

begin_define
define|#
directive|define
name|SK_LINK_SYNC2_TST
value|0x0CB9
end_define

begin_define
define|#
directive|define
name|SK_LINKLED2_CTL
value|0x0CBC
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_CLR_IRQ_NOSTS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_CLR_IRQ_NOTSTAMP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_TSTAMP_OFF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_RSTAMP_ON
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_FLUSH_OFF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_FLUSH_ON
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_PAUSE_OFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_PAUSE_ON
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_AFULL_OFF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_AFULL_ON
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_VALIDTIME_PATCH_OFF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_VALIDTIME_PATCH_ON
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_RXRDY_PATCH_OFF
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_RXRDY_PATCH_ON
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_STS_TIMEO
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|SK_RXMACCTL_TSTAMP_TIMEO
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|SK_RXLEDCTL_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_RXLEDCTL_COUNTER_STOP
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_RXLEDCTL_COUNTER_START
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_LINKLED_OFF
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_LINKLED_ON
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_LINKLED_LINKSYNC_OFF
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_LINKLED_LINKSYNC_ON
value|0x0008
end_define

begin_define
define|#
directive|define
name|SK_LINKLED_BLINK_OFF
value|0x0010
end_define

begin_define
define|#
directive|define
name|SK_LINKLED_BLINK_ON
value|0x0020
end_define

begin_comment
comment|/* Block 26 -- TX MAC FIFO 1 regisrers  */
end_comment

begin_define
define|#
directive|define
name|SK_TXF1_END
value|0x0D00
end_define

begin_define
define|#
directive|define
name|SK_TXF1_WPTR
value|0x0D04
end_define

begin_define
define|#
directive|define
name|SK_TXF1_RPTR
value|0x0D0C
end_define

begin_define
define|#
directive|define
name|SK_TXF1_PKTCNT
value|0x0D10
end_define

begin_define
define|#
directive|define
name|SK_TXF1_LVL
value|0x0D14
end_define

begin_define
define|#
directive|define
name|SK_TXF1_MACCTL
value|0x0D18
end_define

begin_define
define|#
directive|define
name|SK_TXF1_CTL
value|0x0D1C
end_define

begin_define
define|#
directive|define
name|SK_TXLED1_CNTINIT
value|0x0D20
end_define

begin_define
define|#
directive|define
name|SK_TXLED1_COUNTER
value|0x0D24
end_define

begin_define
define|#
directive|define
name|SK_TXLED1_CTL
value|0x0D28
end_define

begin_define
define|#
directive|define
name|SK_TXLED1_TST
value|0x0D29
end_define

begin_comment
comment|/* Block 27 -- TX MAC FIFO 2 regisrers  */
end_comment

begin_define
define|#
directive|define
name|SK_TXF2_END
value|0x0D80
end_define

begin_define
define|#
directive|define
name|SK_TXF2_WPTR
value|0x0D84
end_define

begin_define
define|#
directive|define
name|SK_TXF2_RPTR
value|0x0D8C
end_define

begin_define
define|#
directive|define
name|SK_TXF2_PKTCNT
value|0x0D90
end_define

begin_define
define|#
directive|define
name|SK_TXF2_LVL
value|0x0D94
end_define

begin_define
define|#
directive|define
name|SK_TXF2_MACCTL
value|0x0D98
end_define

begin_define
define|#
directive|define
name|SK_TXF2_CTL
value|0x0D9C
end_define

begin_define
define|#
directive|define
name|SK_TXLED2_CNTINIT
value|0x0DA0
end_define

begin_define
define|#
directive|define
name|SK_TXLED2_COUNTER
value|0x0DA4
end_define

begin_define
define|#
directive|define
name|SK_TXLED2_CTL
value|0x0DA8
end_define

begin_define
define|#
directive|define
name|SK_TXLED2_TST
value|0x0DA9
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_XMAC_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_XMAC_UNRESET
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_LOOP_OFF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_LOOP_ON
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_FLUSH_OFF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_FLUSH_ON
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_WAITEMPTY_OFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_WAITEMPTY_ON
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_AFULL_OFF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_AFULL_ON
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_TXRDY_PATCH_OFF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_RXRDY_PATCH_ON
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_PKT_RECOVERY_OFF
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_PKT_RECOVERY_ON
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_CLR_IRQ_PERR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SK_TXMACCTL_WAITAFTERFLUSH
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SK_TXLEDCTL_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_TXLEDCTL_COUNTER_STOP
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_TXLEDCTL_COUNTER_START
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_FIFO_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SK_FIFO_UNRESET
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SK_FIFO_OFF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SK_FIFO_ON
value|0x00000008
end_define

begin_comment
comment|/* Block 0x40 to 0x4F -- XMAC 1 registers */
end_comment

begin_define
define|#
directive|define
name|SK_XMAC1_BASE
value|0x2000
end_define

begin_define
define|#
directive|define
name|SK_XMAC1_END
value|0x23FF
end_define

begin_comment
comment|/* Block 0x60 to 0x6F -- XMAC 2 registers */
end_comment

begin_define
define|#
directive|define
name|SK_XMAC2_BASE
value|0x3000
end_define

begin_define
define|#
directive|define
name|SK_XMAC2_END
value|0x33FF
end_define

begin_comment
comment|/* Compute relative offset of an XMAC register in the XMAC window(s). */
end_comment

begin_define
define|#
directive|define
name|SK_XMAC_REG
parameter_list|(
name|reg
parameter_list|,
name|mac
parameter_list|)
value|(((reg) * 2) + SK_XMAC1_BASE + \ 	(mac * (SK_XMAC2_BASE - SK_XMAC1_BASE)))
end_define

begin_define
define|#
directive|define
name|SK_XM_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|(sk_win_read_2(sc->sk_softc,				\ 	SK_XMAC_REG(reg, sc->sk_port))& 0xFFFF) |		\ 	((sk_win_read_2(sc->sk_softc,				\ 	SK_XMAC_REG(reg + 2, sc->sk_port))<< 16)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|SK_XM_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_win_write_2(sc->sk_softc,				\ 	SK_XMAC_REG(reg, sc->sk_port), ((val)& 0xFFFF));	\ 	sk_win_write_2(sc->sk_softc,				\ 	SK_XMAC_REG(reg + 2, sc->sk_port), ((val)>> 16)& 0xFFFF);
end_define

begin_define
define|#
directive|define
name|SK_XM_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|sk_win_read_2(sc->sk_softc, SK_XMAC_REG(reg, sc->sk_port))
end_define

begin_define
define|#
directive|define
name|SK_XM_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_win_write_2(sc->sk_softc, SK_XMAC_REG(reg, sc->sk_port), val)
end_define

begin_define
define|#
directive|define
name|SK_XM_SETBIT_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|SK_XM_WRITE_4(sc, reg, (SK_XM_READ_4(sc, reg)) | (x))
end_define

begin_define
define|#
directive|define
name|SK_XM_CLRBIT_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|SK_XM_WRITE_4(sc, reg, (SK_XM_READ_4(sc, reg))& ~(x))
end_define

begin_define
define|#
directive|define
name|SK_XM_SETBIT_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|SK_XM_WRITE_2(sc, reg, (SK_XM_READ_2(sc, reg)) | (x))
end_define

begin_define
define|#
directive|define
name|SK_XM_CLRBIT_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|SK_XM_WRITE_2(sc, reg, (SK_XM_READ_2(sc, reg))& ~(x))
end_define

begin_comment
comment|/*  * The default FIFO threshold on the XMAC II is 4 bytes. On  * dual port NICs, this often leads to transmit underruns, so we  * bump the threshold a little.  */
end_comment

begin_define
define|#
directive|define
name|SK_XM_TX_FIFOTHRESH
value|512
end_define

begin_define
define|#
directive|define
name|SK_PCI_VENDOR_ID
value|0x0000
end_define

begin_define
define|#
directive|define
name|SK_PCI_DEVICE_ID
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_PCI_COMMAND
value|0x0004
end_define

begin_define
define|#
directive|define
name|SK_PCI_STATUS
value|0x0006
end_define

begin_define
define|#
directive|define
name|SK_PCI_REVID
value|0x0008
end_define

begin_define
define|#
directive|define
name|SK_PCI_CLASSCODE
value|0x0009
end_define

begin_define
define|#
directive|define
name|SK_PCI_CACHELEN
value|0x000C
end_define

begin_define
define|#
directive|define
name|SK_PCI_LATENCY_TIMER
value|0x000D
end_define

begin_define
define|#
directive|define
name|SK_PCI_HEADER_TYPE
value|0x000E
end_define

begin_define
define|#
directive|define
name|SK_PCI_LOMEM
value|0x0010
end_define

begin_define
define|#
directive|define
name|SK_PCI_LOIO
value|0x0014
end_define

begin_define
define|#
directive|define
name|SK_PCI_SUBVEN_ID
value|0x002C
end_define

begin_define
define|#
directive|define
name|SK_PCI_SYBSYS_ID
value|0x002E
end_define

begin_define
define|#
directive|define
name|SK_PCI_BIOSROM
value|0x0030
end_define

begin_define
define|#
directive|define
name|SK_PCI_INTLINE
value|0x003C
end_define

begin_define
define|#
directive|define
name|SK_PCI_INTPIN
value|0x003D
end_define

begin_define
define|#
directive|define
name|SK_PCI_MINGNT
value|0x003E
end_define

begin_define
define|#
directive|define
name|SK_PCI_MINLAT
value|0x003F
end_define

begin_comment
comment|/* device specific PCI registers */
end_comment

begin_define
define|#
directive|define
name|SK_PCI_OURREG1
value|0x0040
end_define

begin_define
define|#
directive|define
name|SK_PCI_OURREG2
value|0x0044
end_define

begin_define
define|#
directive|define
name|SK_PCI_CAPID
value|0x0048
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|SK_PCI_NEXTPTR
value|0x0049
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|SK_PCI_PWRMGMTCAP
value|0x004A
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|SK_PCI_PWRMGMTCTRL
value|0x004C
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|SK_PCI_PME_EVENT
value|0x004F
end_define

begin_define
define|#
directive|define
name|SK_PCI_VPD_CAPID
value|0x0050
end_define

begin_define
define|#
directive|define
name|SK_PCI_VPD_NEXTPTR
value|0x0051
end_define

begin_define
define|#
directive|define
name|SK_PCI_VPD_ADDR
value|0x0052
end_define

begin_define
define|#
directive|define
name|SK_PCI_VPD_DATA
value|0x0054
end_define

begin_define
define|#
directive|define
name|SK_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|SK_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|SK_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|SK_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|SK_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|SK_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|SK_PME_STATUS
value|0x8000
end_define

begin_comment
comment|/*  * VPD flag bit. Set to 0 to initiate a read, will become 1 when  * read is complete. Set to 1 to initiate a write, will become 0  * when write is finished.  */
end_comment

begin_define
define|#
directive|define
name|SK_VPD_FLAG
value|0x8000
end_define

begin_comment
comment|/* VPD structures */
end_comment

begin_struct
struct|struct
name|vpd_res
block|{
name|u_int8_t
name|vr_id
decl_stmt|;
name|u_int8_t
name|vr_len
decl_stmt|;
name|u_int8_t
name|vr_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vpd_key
block|{
name|char
name|vk_key
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|vk_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VPD_RES_ID
value|0x82
end_define

begin_comment
comment|/* ID string */
end_comment

begin_define
define|#
directive|define
name|VPD_RES_READ
value|0x90
end_define

begin_comment
comment|/* start of read only area */
end_comment

begin_define
define|#
directive|define
name|VPD_RES_WRITE
value|0x81
end_define

begin_comment
comment|/* start of read/write area */
end_comment

begin_define
define|#
directive|define
name|VPD_RES_END
value|0x78
end_define

begin_comment
comment|/* end tag */
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
value|bus_space_write_4(sc->sk_btag, sc->sk_bhandle, reg, val)
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
value|bus_space_write_2(sc->sk_btag, sc->sk_bhandle, reg, val)
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
value|bus_space_write_1(sc->sk_btag, sc->sk_bhandle, reg, val)
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
value|bus_space_read_4(sc->sk_btag, sc->sk_bhandle, reg)
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
value|bus_space_read_2(sc->sk_btag, sc->sk_bhandle, reg)
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
value|bus_space_read_1(sc->sk_btag, sc->sk_bhandle, reg)
end_define

begin_struct
struct|struct
name|sk_type
block|{
name|u_int16_t
name|sk_vid
decl_stmt|;
name|u_int16_t
name|sk_did
decl_stmt|;
name|char
modifier|*
name|sk_name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RX queue descriptor data structure */
end_comment

begin_struct
struct|struct
name|sk_rx_desc
block|{
name|u_int32_t
name|sk_ctl
decl_stmt|;
name|u_int32_t
name|sk_next
decl_stmt|;
name|u_int32_t
name|sk_data_lo
decl_stmt|;
name|u_int32_t
name|sk_data_hi
decl_stmt|;
name|u_int32_t
name|sk_xmac_rxstat
decl_stmt|;
name|u_int32_t
name|sk_timestamp
decl_stmt|;
name|u_int16_t
name|sk_csum2
decl_stmt|;
name|u_int16_t
name|sk_csum1
decl_stmt|;
name|u_int16_t
name|sk_csum2_start
decl_stmt|;
name|u_int16_t
name|sk_csum1_start
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SK_OPCODE_DEFAULT
value|0x00550000
end_define

begin_define
define|#
directive|define
name|SK_OPCODE_CSUM
value|0x00560000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_LEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_OPCODE
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_TSTAMP_VALID
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_STATUS_VALID
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_DEV0
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_EOF_INTR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_EOB_INTR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_LASTFRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_FIRSTFRAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SK_RXCTL_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SK_RXSTAT
define|\
value|(SK_OPCODE_DEFAULT|SK_RXCTL_EOF_INTR|SK_RXCTL_LASTFRAG| \ 	 SK_RXCTL_FIRSTFRAG|SK_RXCTL_OWN)
end_define

begin_struct
struct|struct
name|sk_tx_desc
block|{
name|u_int32_t
name|sk_ctl
decl_stmt|;
name|u_int32_t
name|sk_next
decl_stmt|;
name|u_int32_t
name|sk_data_lo
decl_stmt|;
name|u_int32_t
name|sk_data_hi
decl_stmt|;
name|u_int32_t
name|sk_xmac_txstat
decl_stmt|;
name|u_int16_t
name|sk_rsvd0
decl_stmt|;
name|u_int16_t
name|sk_csum_startval
decl_stmt|;
name|u_int16_t
name|sk_csum_startpos
decl_stmt|;
name|u_int16_t
name|sk_csum_writepos
decl_stmt|;
name|u_int32_t
name|sk_rsvd1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SK_TXCTL_LEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_OPCODE
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_SW
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_NOCRC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_STORENFWD
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_EOF_INTR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_EOB_INTR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_LASTFRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_FIRSTFRAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SK_TXCTL_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SK_TXSTAT
define|\
value|(SK_OPCODE_DEFAULT|SK_TXCTL_EOF_INTR|SK_TXCTL_LASTFRAG|SK_TXCTL_OWN)
end_define

begin_define
define|#
directive|define
name|SK_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|(x)& 0x0000FFFF;
end_define

begin_define
define|#
directive|define
name|SK_TXBYTES
value|SK_RXBYTES
end_define

begin_define
define|#
directive|define
name|SK_TX_RING_CNT
value|512
end_define

begin_define
define|#
directive|define
name|SK_RX_RING_CNT
value|256
end_define

begin_comment
comment|/*  * Jumbo buffer stuff. Note that we must allocate more jumbo  * buffers than there are descriptors in the receive ring. This  * is because we don't know how long it will take for a packet  * to be released after we hand it off to the upper protocol  * layers. To be safe, we allocate 1.5 times the number of  * receive descriptors.  */
end_comment

begin_define
define|#
directive|define
name|SK_JUMBO_FRAMELEN
value|9018
end_define

begin_define
define|#
directive|define
name|SK_JUMBO_MTU
value|(SK_JUMBO_FRAMELEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|SK_JSLOTS
value|384
end_define

begin_define
define|#
directive|define
name|SK_JRAWLEN
value|(SK_JUMBO_FRAMELEN + ETHER_ALIGN + sizeof(u_int64_t))
end_define

begin_define
define|#
directive|define
name|SK_JLEN
value|(SK_JRAWLEN + (sizeof(u_int64_t) - \ 	(SK_JRAWLEN % sizeof(u_int64_t))))
end_define

begin_define
define|#
directive|define
name|SK_MCLBYTES
value|(SK_JLEN - sizeof(u_int64_t))
end_define

begin_define
define|#
directive|define
name|SK_JPAGESZ
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|SK_RESID
value|(SK_JPAGESZ - (SK_JLEN * SK_JSLOTS) % SK_JPAGESZ)
end_define

begin_define
define|#
directive|define
name|SK_JMEM
value|((SK_JLEN * SK_JSLOTS) + SK_RESID)
end_define

begin_struct
struct|struct
name|sk_jslot
block|{
name|caddr_t
name|sk_buf
decl_stmt|;
name|int
name|sk_inuse
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sk_jpool_entry
block|{
name|int
name|slot
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|sk_jpool_entry
argument_list|)
name|jpool_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sk_chain
block|{
name|void
modifier|*
name|sk_desc
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|sk_mbuf
decl_stmt|;
name|struct
name|sk_chain
modifier|*
name|sk_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sk_chain_data
block|{
name|struct
name|sk_chain
name|sk_tx_chain
index|[
name|SK_TX_RING_CNT
index|]
decl_stmt|;
name|struct
name|sk_chain
name|sk_rx_chain
index|[
name|SK_RX_RING_CNT
index|]
decl_stmt|;
name|int
name|sk_tx_prod
decl_stmt|;
name|int
name|sk_tx_cons
decl_stmt|;
name|int
name|sk_tx_cnt
decl_stmt|;
name|int
name|sk_rx_prod
decl_stmt|;
name|int
name|sk_rx_cons
decl_stmt|;
name|int
name|sk_rx_cnt
decl_stmt|;
comment|/* Stick the jumbo mem management stuff here too. */
name|struct
name|sk_jslot
name|sk_jslots
index|[
name|SK_JSLOTS
index|]
decl_stmt|;
name|void
modifier|*
name|sk_jumbo_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sk_ring_data
block|{
name|struct
name|sk_tx_desc
name|sk_tx_ring
index|[
name|SK_TX_RING_CNT
index|]
decl_stmt|;
name|struct
name|sk_rx_desc
name|sk_rx_ring
index|[
name|SK_RX_RING_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sk_bcom_hack
block|{
name|int
name|reg
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SK_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_comment
comment|/* Forward decl. */
end_comment

begin_struct_decl
struct_decl|struct
name|sk_if_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/* Softc for the GEnesis controller. */
end_comment

begin_struct
struct|struct
name|sk_softc
block|{
name|bus_space_handle_t
name|sk_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|sk_btag
decl_stmt|;
comment|/* bus space tag */
name|void
modifier|*
name|sk_intrhand
decl_stmt|;
comment|/* irq handler handle */
name|struct
name|resource
modifier|*
name|sk_irq
decl_stmt|;
comment|/* IRQ resource handle */
name|struct
name|resource
modifier|*
name|sk_res
decl_stmt|;
comment|/* I/O or shared mem handle */
name|u_int8_t
name|sk_unit
decl_stmt|;
comment|/* controller number */
name|u_int8_t
name|sk_type
decl_stmt|;
name|char
modifier|*
name|sk_vpd_prodname
decl_stmt|;
name|char
modifier|*
name|sk_vpd_readonly
decl_stmt|;
name|u_int32_t
name|sk_rboff
decl_stmt|;
comment|/* RAMbuffer offset */
name|u_int32_t
name|sk_ramsize
decl_stmt|;
comment|/* amount of RAM on NIC */
name|u_int32_t
name|sk_pmd
decl_stmt|;
comment|/* physical media type */
name|u_int32_t
name|sk_intrmask
decl_stmt|;
name|struct
name|sk_if_softc
modifier|*
name|sk_if
index|[
literal|2
index|]
decl_stmt|;
name|device_t
name|sk_devs
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Softc for each logical interface */
end_comment

begin_struct
struct|struct
name|sk_if_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|device_t
name|sk_miibus
decl_stmt|;
name|u_int8_t
name|sk_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|sk_port
decl_stmt|;
comment|/* port # on controller */
name|u_int8_t
name|sk_xmac_rev
decl_stmt|;
comment|/* XMAC chip rev (B2 or C1) */
name|u_int32_t
name|sk_rx_ramstart
decl_stmt|;
name|u_int32_t
name|sk_rx_ramend
decl_stmt|;
name|u_int32_t
name|sk_tx_ramstart
decl_stmt|;
name|u_int32_t
name|sk_tx_ramend
decl_stmt|;
name|int
name|sk_phytype
decl_stmt|;
name|int
name|sk_phyaddr
decl_stmt|;
name|device_t
name|sk_dev
decl_stmt|;
name|int
name|sk_cnt
decl_stmt|;
name|int
name|sk_link
decl_stmt|;
name|struct
name|callout_handle
name|sk_tick_ch
decl_stmt|;
name|struct
name|sk_chain_data
name|sk_cdata
decl_stmt|;
name|struct
name|sk_ring_data
modifier|*
name|sk_rdata
decl_stmt|;
name|struct
name|sk_softc
modifier|*
name|sk_softc
decl_stmt|;
comment|/* parent controller */
name|int
name|sk_tx_bmu
decl_stmt|;
comment|/* TX BMU register */
name|int
name|sk_if_flags
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__sk_jfreehead
argument_list|,
argument|sk_jpool_entry
argument_list|)
name|sk_jfree_listhead
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__sk_jinusehead
argument_list|,
argument|sk_jpool_entry
argument_list|)
name|sk_jinuse_listhead
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SK_MAXUNIT
value|256
end_define

begin_define
define|#
directive|define
name|SK_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

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
value|alpha_XXX_dmamap((vm_offset_t)va)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

