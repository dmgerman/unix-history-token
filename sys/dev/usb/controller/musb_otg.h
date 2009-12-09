begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This header file defines the registers of the Mentor Graphics USB OnTheGo  * Inventra chip.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MUSB2_OTG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MUSB2_OTG_H_
end_define

begin_define
define|#
directive|define
name|MUSB2_MAX_DEVICES
value|(USB_MIN_DEVICES + 1)
end_define

begin_comment
comment|/* Common registers */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_FADDR
value|0x0000
end_define

begin_comment
comment|/* function address register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_FADDR
value|0x7F
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_POWER
value|0x0001
end_define

begin_comment
comment|/* power register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_SUSPM_ENA
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_SUSPMODE
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_RESUME
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_RESET
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_HSMODE
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_HSENAB
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_SOFTC
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_ISOUPD
value|0x80
end_define

begin_comment
comment|/* Endpoint interrupt handling */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_INTTX
value|0x0002
end_define

begin_comment
comment|/* transmit interrupt register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_INTRX
value|0x0004
end_define

begin_comment
comment|/* receive interrupt register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_INTTXE
value|0x0006
end_define

begin_comment
comment|/* transmit interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_INTRXE
value|0x0008
end_define

begin_comment
comment|/* receive interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_EPINT
parameter_list|(
name|epn
parameter_list|)
value|(1<< (epn))
end_define

begin_comment
comment|/* epn = [0..15] */
end_comment

begin_comment
comment|/* Common interrupt handling */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_INTUSB
value|0x000A
end_define

begin_comment
comment|/* USB interrupt register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_ISUSP
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_IRESUME
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_IRESET
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_IBABBLE
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_ISOF
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_ICONN
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_IDISC
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_ISESSRQ
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_IVBUSERR
value|0x80
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_INTUSBE
value|0x000B
end_define

begin_comment
comment|/* USB interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_FRAME
value|0x000C
end_define

begin_comment
comment|/* USB frame register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_FRAME
value|0x3FF
end_define

begin_comment
comment|/* 0..1023 */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_EPINDEX
value|0x000E
end_define

begin_comment
comment|/* endpoint index register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_EPINDEX
value|0x0F
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TESTMODE
value|0x000F
end_define

begin_comment
comment|/* test mode register */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_TSE0_NAK
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TJ
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TK
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TPACKET
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TFORCE_HS
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TFORCE_LS
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TFIFO_ACC
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TFORCE_HC
value|0x80
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_INDEXED_CSR
value|0x0010
end_define

begin_comment
comment|/* EP control status register offset */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_TXMAXP
value|(0x0000 + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXMAXP
value|(0x0004 + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_PKTSIZE
value|0x03FF
end_define

begin_comment
comment|/* in bytes, should be even */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_PKTMULT
value|0xFC00
end_define

begin_comment
comment|/* HS packet multiplier: 0..2 */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_TXCSRL
value|(0x0002 + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXPKTRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXFIFONEMPTY
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXUNDERRUN
value|0x04
end_define

begin_comment
comment|/* Device Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXERROR
value|0x04
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXFFLUSH
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXSENDSTALL
value|0x10
end_define

begin_comment
comment|/* Device Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXSETUPPKT
value|0x10
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXSENTSTALL
value|0x20
end_define

begin_comment
comment|/* Device Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXSTALLED
value|0x20
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXDT_CLR
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_TXINCOMP
value|0x80
end_define

begin_comment
comment|/* Device Side Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_RXPKTRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_TXPKTRDY
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_SENTSTALL
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_DATAEND
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_SETUPEND
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_SENDSTALL
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_RXPKTRDY_CLR
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_SETUPEND_CLR
value|0x80
end_define

begin_comment
comment|/* Host Side Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_RXSTALL
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_SETUPPKT
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_ERROR
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_REQPKT
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_STATUSPKT
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0L_NAKTIMO
value|0x80
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TXCSRH
value|(0x0003 + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_TXDT_VAL
value|0x01
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_TXDT_WR
value|0x02
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_TXDMAREQMODE
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_TXDT_SWITCH
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_TXDMAREQENA
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXMODE
value|0x00
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_TXMODE
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_TXISO
value|0x40
end_define

begin_comment
comment|/* Device Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_TXAUTOSET
value|0x80
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0H_FFLUSH
value|0x01
end_define

begin_comment
comment|/* Device Side flush FIFO */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0H_DT
value|0x02
end_define

begin_comment
comment|/* Host Side data toggle */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0H_DT_SET
value|0x04
end_define

begin_comment
comment|/* Host Side */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSR0H_PING_DIS
value|0x08
end_define

begin_comment
comment|/* Host Side */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_RXCSRL
value|(0x0006 + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXPKTRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXFIFOFULL
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXOVERRUN
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXDATAERR
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXFFLUSH
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXSENDSTALL
value|0x20
end_define

begin_comment
comment|/* Device Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXREQPKT
value|0x20
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXSENTSTALL
value|0x40
end_define

begin_comment
comment|/* Device Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXSTALL
value|0x40
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRL_RXDT_CLR
value|0x80
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXCSRH
value|(0x0007 + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXINCOMP
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXDT_VAL
value|0x02
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXDT_SET
value|0x04
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXDMAREQMODE
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXNYET
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXDMAREQENA
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXISO
value|0x40
end_define

begin_comment
comment|/* Device Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXAUTOREQ
value|0x40
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CSRH_RXAUTOCLEAR
value|0x80
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXCOUNT
value|(0x0008 + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_RXCOUNT
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TXTI
value|(0x000A + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXTI
value|(0x000C + MUSB2_REG_INDEXED_CSR)
end_define

begin_comment
comment|/* Host Mode */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_SPEED
value|0xC0
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_SPEED_LO
value|0xC0
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_SPEED_FS
value|0x80
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_SPEED_HS
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_PROTO_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_PROTO_ISOC
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_PROTO_BULK
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_PROTO_INTR
value|0x30
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TI_EP_NUM
value|0x0F
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TXNAKLIMIT
value|(0x000B
comment|/* EPN=0 */
value|+ MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXNAKLIMIT
value|(0x000D
comment|/* EPN=0 */
value|+ MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_NAKLIMIT
value|0xFF
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_FSIZE
value|(0x000F + MUSB2_REG_INDEXED_CSR)
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_RX_FSIZE
value|0xF0
end_define

begin_comment
comment|/* 3..13, 2**n bytes */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_TX_FSIZE
value|0x0F
end_define

begin_comment
comment|/* 3..13, 2**n bytes */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_EPFIFO
parameter_list|(
name|n
parameter_list|)
value|(0x0020 + (4*(n)))
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_CONFDATA
value|(0x000F + MUSB2_REG_INDEXED_CSR)
end_define

begin_comment
comment|/* EPN=0 */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_CD_UTMI_DW
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CD_SOFTCONE
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CD_DYNFIFOSZ
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CD_HBTXE
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CD_HBRXE
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CD_BIGEND
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CD_MPTXE
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_CD_MPRXE
value|0x80
end_define

begin_comment
comment|/* Various registers */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_DEVCTL
value|0x0060
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_SESS
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_HOSTREQ
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_HOSTMD
value|0x04
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_VBUS0
value|0x08
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_VBUS1
value|0x10
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_LSDEV
value|0x20
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_FSDEV
value|0x40
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_BDEV
value|0x80
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_MISC
value|0x0061
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_RXEDMA
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_TXEDMA
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TXFIFOSZ
value|0x0062
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXFIFOSZ
value|0x0063
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_FIFODB
value|0x10
end_define

begin_comment
comment|/* set if double buffering, r/w */
end_comment

begin_define
define|#
directive|define
name|MUSB2_MASK_FIFOSZ
value|0x0F
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_8
value|0
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_16
value|1
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_32
value|2
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_64
value|3
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_128
value|4
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_256
value|5
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_512
value|6
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_1024
value|7
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_2048
value|8
end_define

begin_define
define|#
directive|define
name|MUSB2_VAL_FIFOSZ_4096
value|9
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TXFIFOADD
value|0x0064
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXFIFOADD
value|0x0066
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_FIFOADD
value|0xFFF
end_define

begin_comment
comment|/* unit is 8-bytes */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_VSTATUS
value|0x0068
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_VCONTROL
value|0x0068
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_HWVERS
value|0x006C
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_ULPI_BASE
value|0x0070
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_EPINFO
value|0x0078
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_NRXEP
value|0xF0
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_NTXEP
value|0x0F
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RAMINFO
value|0x0079
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_LINKINFO
value|0x007A
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_VPLEN
value|0x007B
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_VPLEN
value|0xFF
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_HS_EOF1
value|0x007C
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_FS_EOF1
value|0x007D
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_LS_EOF1
value|0x007E
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_SOFT_RST
value|0x007F
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_SRST
value|0x01
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_SRSTX
value|0x02
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RQPKTCOUNT
parameter_list|(
name|n
parameter_list|)
value|(0x0300 + (4*(n))
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXDBDIS
value|0x0340
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TXDBDIS
value|0x0342
end_define

begin_define
define|#
directive|define
name|MUSB2_MASK_DB
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_comment
comment|/* disable double buffer, n = [0..15] */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_CHIRPTO
value|0x0344
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_HSRESUM
value|0x0346
end_define

begin_comment
comment|/* Host Mode only registers */
end_comment

begin_define
define|#
directive|define
name|MUSB2_REG_TXFADDR
parameter_list|(
name|n
parameter_list|)
value|(0x0080 + (8*(n)))
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TXHADDR
parameter_list|(
name|n
parameter_list|)
value|(0x0082 + (8*(n)))
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_TXHUBPORT
parameter_list|(
name|n
parameter_list|)
value|(0x0083 + (8*(n)))
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXFADDR
parameter_list|(
name|n
parameter_list|)
value|(0x0084 + (8*(n)))
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXHADDR
parameter_list|(
name|n
parameter_list|)
value|(0x0086 + (8*(n)))
end_define

begin_define
define|#
directive|define
name|MUSB2_REG_RXHPORT
parameter_list|(
name|n
parameter_list|)
value|(0x0087 + (8*(n)))
end_define

begin_define
define|#
directive|define
name|MUSB2_EP_MAX
value|16
end_define

begin_comment
comment|/* maximum number of endpoints */
end_comment

begin_define
define|#
directive|define
name|MUSB2_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_io_tag, (sc)->sc_io_hdl, reg)
end_define

begin_define
define|#
directive|define
name|MUSB2_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, data)
end_define

begin_define
define|#
directive|define
name|MUSB2_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_io_tag, (sc)->sc_io_hdl, reg)
end_define

begin_define
define|#
directive|define
name|MUSB2_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, data)
end_define

begin_struct_decl
struct_decl|struct
name|musbotg_td
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|musbotg_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|musbotg_cmd_t
function_decl|)
parameter_list|(
name|struct
name|musbotg_td
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|musbotg_dma
block|{
name|struct
name|musbotg_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
name|dma_chan
decl_stmt|;
name|uint8_t
name|busy
range|:
literal|1
decl_stmt|;
name|uint8_t
name|complete
range|:
literal|1
decl_stmt|;
name|uint8_t
name|error
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|musbotg_td
block|{
name|struct
name|musbotg_td
modifier|*
name|obj_next
decl_stmt|;
name|musbotg_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|remainder
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
comment|/* packet_size * mult */
name|uint8_t
name|ep_no
decl_stmt|;
name|uint8_t
name|error
range|:
literal|1
decl_stmt|;
name|uint8_t
name|alt_next
range|:
literal|1
decl_stmt|;
name|uint8_t
name|short_pkt
range|:
literal|1
decl_stmt|;
name|uint8_t
name|support_multi_buffer
range|:
literal|1
decl_stmt|;
name|uint8_t
name|did_stall
range|:
literal|1
decl_stmt|;
name|uint8_t
name|dma_enabled
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|musbotg_std_temp
block|{
name|musbotg_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|struct
name|musbotg_td
modifier|*
name|td
decl_stmt|;
name|struct
name|musbotg_td
modifier|*
name|td_next
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
name|uint8_t
name|short_pkt
decl_stmt|;
comment|/*          * short_pkt = 0: transfer should be short terminated          * short_pkt = 1: transfer should not be short terminated          */
name|uint8_t
name|setup_alt_next
decl_stmt|;
name|uint8_t
name|did_stall
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|musbotg_config_desc
block|{
name|struct
name|usb_config_descriptor
name|confd
decl_stmt|;
name|struct
name|usb_interface_descriptor
name|ifcd
decl_stmt|;
name|struct
name|usb_endpoint_descriptor
name|endpd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|musbotg_hub_temp
block|{
name|uWord
name|wValue
decl_stmt|;
name|struct
name|usb_port_status
name|ps
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|musbotg_flags
block|{
name|uint8_t
name|change_connect
range|:
literal|1
decl_stmt|;
name|uint8_t
name|change_suspend
range|:
literal|1
decl_stmt|;
name|uint8_t
name|status_suspend
range|:
literal|1
decl_stmt|;
comment|/* set if suspended */
name|uint8_t
name|status_vbus
range|:
literal|1
decl_stmt|;
comment|/* set if present */
name|uint8_t
name|status_bus_reset
range|:
literal|1
decl_stmt|;
comment|/* set if reset complete */
name|uint8_t
name|status_high_speed
range|:
literal|1
decl_stmt|;
comment|/* set if High Speed is selected */
name|uint8_t
name|remote_wakeup
range|:
literal|1
decl_stmt|;
name|uint8_t
name|self_powered
range|:
literal|1
decl_stmt|;
name|uint8_t
name|clocks_off
range|:
literal|1
decl_stmt|;
name|uint8_t
name|port_powered
range|:
literal|1
decl_stmt|;
name|uint8_t
name|port_enabled
range|:
literal|1
decl_stmt|;
name|uint8_t
name|d_pulled_up
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|musbotg_softc
block|{
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
name|union
name|musbotg_hub_temp
name|sc_hub_temp
decl_stmt|;
name|struct
name|usb_hw_ep_profile
name|sc_hw_ep_profile
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|MUSB2_MAX_DEVICES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_io_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|void
modifier|*
name|sc_intr_hdl
decl_stmt|;
name|bus_size_t
name|sc_io_size
decl_stmt|;
name|bus_space_tag_t
name|sc_io_tag
decl_stmt|;
name|bus_space_handle_t
name|sc_io_hdl
decl_stmt|;
name|void
function_decl|(
modifier|*
name|sc_clocks_on
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_clocks_off
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|sc_clocks_arg
decl_stmt|;
name|uint32_t
name|sc_bounce_buf
index|[
operator|(
literal|1024
operator|*
literal|3
operator|)
operator|/
literal|4
index|]
decl_stmt|;
comment|/* bounce buffer */
name|uint8_t
name|sc_ep_max
decl_stmt|;
comment|/* maximum number of RX and TX 					 * endpoints supported */
name|uint8_t
name|sc_rt_addr
decl_stmt|;
comment|/* root HUB address */
name|uint8_t
name|sc_dv_addr
decl_stmt|;
comment|/* device address */
name|uint8_t
name|sc_conf
decl_stmt|;
comment|/* root HUB config */
name|uint8_t
name|sc_ep0_busy
decl_stmt|;
comment|/* set if ep0 is busy */
name|uint8_t
name|sc_ep0_cmd
decl_stmt|;
comment|/* pending commands */
name|uint8_t
name|sc_conf_data
decl_stmt|;
comment|/* copy of hardware register */
name|uint8_t
name|sc_hub_idata
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|musbotg_flags
name|sc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|usb_error_t
name|musbotg_init
parameter_list|(
name|struct
name|musbotg_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|musbotg_uninit
parameter_list|(
name|struct
name|musbotg_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|musbotg_suspend
parameter_list|(
name|struct
name|musbotg_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|musbotg_resume
parameter_list|(
name|struct
name|musbotg_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|musbotg_interrupt
parameter_list|(
name|struct
name|musbotg_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|musbotg_vbus_interrupt
parameter_list|(
name|struct
name|musbotg_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|is_on
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MUSB2_OTG_H_ */
end_comment

end_unit

