begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|WI_DELAY
value|5
end_define

begin_define
define|#
directive|define
name|WI_TIMEOUT
value|(500000/WI_DELAY)
end_define

begin_comment
comment|/* 500 ms */
end_comment

begin_define
define|#
directive|define
name|WI_PORT0
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|WI_PORT1
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|WI_PORT2
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|WI_PORT3
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|WI_PORT4
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|WI_PORT5
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|WI_PCI_LMEMRES
value|0x10
end_define

begin_comment
comment|/* PCI Memory (native PCI implementations) */
end_comment

begin_define
define|#
directive|define
name|WI_PCI_LOCALRES
value|0x14
end_define

begin_comment
comment|/* The PLX chip's local registers */
end_comment

begin_define
define|#
directive|define
name|WI_PCI_MEMRES
value|0x18
end_define

begin_comment
comment|/* The PCCard's attribute memory */
end_comment

begin_define
define|#
directive|define
name|WI_PCI_IORES
value|0x1C
end_define

begin_comment
comment|/* The PCCard's I/O space */
end_comment

begin_define
define|#
directive|define
name|WI_LOCAL_INTCSR
value|0x4c
end_define

begin_define
define|#
directive|define
name|WI_LOCAL_INTEN
value|0x40
end_define

begin_define
define|#
directive|define
name|WI_HFA384X_SWSUPPORT0_OFF
value|0x28
end_define

begin_define
define|#
directive|define
name|WI_PRISM2STA_MAGIC
value|0x4A2D
end_define

begin_define
define|#
directive|define
name|WI_HFA384X_PCICOR_OFF
value|0x26
end_define

begin_comment
comment|/* Default port: 0 (only 0 exists on stations) */
end_comment

begin_define
define|#
directive|define
name|WI_DEFAULT_PORT
value|WI_PORT0
end_define

begin_comment
comment|/* Default network name: ANY */
end_comment

begin_comment
comment|/*  * [sommerfeld 1999/07/15] Changed from "ANY" to ""; according to Bill Fenner,  * ANY is used in MS driver user interfaces, while "" is used over the  * wire..  */
end_comment

begin_define
define|#
directive|define
name|WI_DEFAULT_NETNAME
value|""
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_AP_DENSITY
value|1
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_RTS_THRESH
value|2347
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_DATALEN
value|2304
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_CREATE_IBSS
value|0
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_PM_ENABLED
value|0
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_MAX_SLEEP
value|100
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_ROAMING
value|1
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_AUTHTYPE
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|OS_STRING_NAME
value|"NetBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|OS_STRING_NAME
value|"FreeBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_define
define|#
directive|define
name|OS_STRING_NAME
value|"OpenBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WI_DEFAULT_NODENAME
value|OS_STRING_NAME " WaveLAN/IEEE node"
end_define

begin_define
define|#
directive|define
name|WI_DEFAULT_IBSS
value|OS_STRING_NAME " IBSS"
end_define

begin_define
define|#
directive|define
name|WI_BUS_PCCARD
value|0
end_define

begin_comment
comment|/* pccard device */
end_comment

begin_define
define|#
directive|define
name|WI_BUS_PCI_PLX
value|1
end_define

begin_comment
comment|/* PCI card w/ PLX PCI/PCMICA bridge */
end_comment

begin_define
define|#
directive|define
name|WI_BUS_PCI_NATIVE
value|2
end_define

begin_comment
comment|/* native PCI device (Prism 2.5) */
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
value|bus_space_write_4((sc)->wi_btag, (sc)->wi_bhandle, 	\ 	    (sc)->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg)*2 : (reg), val)
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
value|bus_space_write_2((sc)->wi_btag, (sc)->wi_bhandle,	\  	    (sc)->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg)*2 : (reg), val)
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
value|bus_space_write_1((sc)->wi_btag, (sc)->wi_bhandle,	\  	    (sc)->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg)*2 : (reg), val)
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
value|bus_space_read_4((sc)->wi_btag, (sc)->wi_bhandle,	\  	    (sc)->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg)*2 : (reg))
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
value|bus_space_read_2((sc)->wi_btag, (sc)->wi_bhandle,	\  	    (sc)->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg)*2 : (reg))
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
value|bus_space_read_1((sc)->wi_btag, (sc)->wi_bhandle,	\  	    (sc)->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg)*2 : (reg))
end_define

begin_define
define|#
directive|define
name|CSM_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->wi_bmemtag, (sc)->wi_bmemhandle, off, val)
end_define

begin_define
define|#
directive|define
name|CSM_READ_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|bus_space_read_1((sc)->wi_bmemtag, (sc)->wi_bmemhandle, off)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_STREAM_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_stream_2(sc->wi_btag, sc->wi_bhandle,	\ 	    (sc->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg) * 2 : (reg)), val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_MULTI_STREAM_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_stream_2(sc->wi_btag, sc->wi_bhandle,	\ 	    (sc->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg) * 2 : (reg)), val, count)
end_define

begin_define
define|#
directive|define
name|CSR_READ_STREAM_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_stream_2(sc->wi_btag, sc->wi_bhandle,	\ 	    (sc->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg) * 2 : (reg)))
end_define

begin_define
define|#
directive|define
name|CSR_READ_MULTI_STREAM_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|buf
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_stream_2(sc->wi_btag, sc->wi_bhandle,	\ 	    (sc->wi_bus_type == WI_BUS_PCI_NATIVE ? (reg) * 2 : (reg)), buf, count)
end_define

begin_comment
comment|/*  * The WaveLAN/IEEE cards contain an 802.11 MAC controller which Lucent  * calls 'Hermes.' In typical fashion, getting documentation about this  * controller is about as easy as squeezing blood from a stone. Here  * is more or less what I know:  *  * - The Hermes controller is firmware driven, and the host interacts  *   with the Hermes via a firmware interface, which can change.  *  * - The Hermes is described in a document called: "Hermes Firmware  *   WaveLAN/IEEE Station Functions," document #010245, which of course  *   Lucent will not release without an NDA.  *  * - Lucent has created a library called HCF (Hardware Control Functions)  *   though which it wants developers to interact with the card. The HCF  *   is needlessly complex, ill conceived and badly documented. Actually,  *   the comments in the HCP code itself aren't bad, but the publically  *   available manual that comes with it is awful, probably due largely to  *   the fact that it has been emasculated in order to hide information  *   that Lucent wants to keep proprietary. The purpose of the HCF seems  *   to be to insulate the driver programmer from the Hermes itself so that  *   Lucent has an excuse not to release programming in for it.  *  * - Lucent only makes available documentation and code for 'HCF Light'  *   which is a stripped down version of HCF with certain features not  *   implemented, most notably support for 802.11 frames.  *  * - The HCF code which I have seen blows goats. Whoever decided to  *   use a 132 column format should be shot.  *  * Rather than actually use the Lucent HCF library, I have stripped all  * the useful information from it and used it to create a driver in the  * usual BSD form. Note: I don't want to hear anybody whining about the  * fact that the Lucent code is GPLed and mine isn't. I did not actually  * put any of Lucent's code in this driver: I only used it as a reference  * to obtain information about the underlying hardware. The Hermes  * programming interface is not GPLed, so bite me.  */
end_comment

begin_comment
comment|/*  * Size of Hermes& Prism2 I/O space.  */
end_comment

begin_define
define|#
directive|define
name|WI_IOSIZ
value|0x40
end_define

begin_comment
comment|/*  * Hermes& Prism2 register definitions   */
end_comment

begin_comment
comment|/* Hermes command/status registers. */
end_comment

begin_define
define|#
directive|define
name|WI_COMMAND
value|0x00
end_define

begin_define
define|#
directive|define
name|WI_PARAM0
value|0x02
end_define

begin_define
define|#
directive|define
name|WI_PARAM1
value|0x04
end_define

begin_define
define|#
directive|define
name|WI_PARAM2
value|0x06
end_define

begin_define
define|#
directive|define
name|WI_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|WI_RESP0
value|0x0A
end_define

begin_define
define|#
directive|define
name|WI_RESP1
value|0x0C
end_define

begin_define
define|#
directive|define
name|WI_RESP2
value|0x0E
end_define

begin_comment
comment|/* Command register values. */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_BUSY
value|0x8000
end_define

begin_comment
comment|/* busy bit */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_INI
value|0x0000
end_define

begin_comment
comment|/* initialize */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_ENABLE
value|0x0001
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_DISABLE
value|0x0002
end_define

begin_comment
comment|/* disable */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_DIAG
value|0x0003
end_define

begin_define
define|#
directive|define
name|WI_CMD_ALLOC_MEM
value|0x000A
end_define

begin_comment
comment|/* allocate NIC memory */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_TX
value|0x000B
end_define

begin_comment
comment|/* transmit */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_NOTIFY
value|0x0010
end_define

begin_define
define|#
directive|define
name|WI_CMD_INQUIRE
value|0x0011
end_define

begin_define
define|#
directive|define
name|WI_CMD_ACCESS
value|0x0021
end_define

begin_define
define|#
directive|define
name|WI_CMD_ACCESS_WRITE
value|0x0121
end_define

begin_define
define|#
directive|define
name|WI_CMD_PROGRAM
value|0x0022
end_define

begin_define
define|#
directive|define
name|WI_CMD_READEE
value|0x0030
end_define

begin_comment
comment|/* symbol only */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_READMIF
value|0x0030
end_define

begin_comment
comment|/* prism2 */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_WRITEMIF
value|0x0031
end_define

begin_comment
comment|/* prism2 */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_DEBUG
value|0x0038
end_define

begin_comment
comment|/* Various test commands */
end_comment

begin_define
define|#
directive|define
name|WI_CMD_CODE_MASK
value|0x003F
end_define

begin_comment
comment|/*  * Various cmd test stuff.  */
end_comment

begin_define
define|#
directive|define
name|WI_TEST_MONITOR
value|0x0B
end_define

begin_define
define|#
directive|define
name|WI_TEST_STOP
value|0x0F
end_define

begin_define
define|#
directive|define
name|WI_TEST_CFG_BITS
value|0x15
end_define

begin_define
define|#
directive|define
name|WI_TEST_CFG_BIT_ALC
value|0x08
end_define

begin_comment
comment|/*  * Reclaim qualifier bit, applicable to the  * TX and INQUIRE commands.  */
end_comment

begin_define
define|#
directive|define
name|WI_RECLAIM
value|0x0100
end_define

begin_comment
comment|/* reclaim NIC memory */
end_comment

begin_comment
comment|/*  * ACCESS command qualifier bits.  */
end_comment

begin_define
define|#
directive|define
name|WI_ACCESS_READ
value|0x0000
end_define

begin_define
define|#
directive|define
name|WI_ACCESS_WRITE
value|0x0100
end_define

begin_comment
comment|/*  * PROGRAM command qualifier bits.  */
end_comment

begin_define
define|#
directive|define
name|WI_PROGRAM_DISABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|WI_PROGRAM_ENABLE_RAM
value|0x0100
end_define

begin_define
define|#
directive|define
name|WI_PROGRAM_ENABLE_NVRAM
value|0x0200
end_define

begin_define
define|#
directive|define
name|WI_PROGRAM_NVRAM
value|0x0300
end_define

begin_comment
comment|/* Status register values */
end_comment

begin_define
define|#
directive|define
name|WI_STAT_CMD_CODE
value|0x003F
end_define

begin_define
define|#
directive|define
name|WI_STAT_DIAG_ERR
value|0x0100
end_define

begin_define
define|#
directive|define
name|WI_STAT_INQ_ERR
value|0x0500
end_define

begin_define
define|#
directive|define
name|WI_STAT_CMD_RESULT
value|0x7F00
end_define

begin_comment
comment|/* memory handle management registers */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_FID
value|0x10
end_define

begin_define
define|#
directive|define
name|WI_RX_FID
value|0x20
end_define

begin_define
define|#
directive|define
name|WI_ALLOC_FID
value|0x22
end_define

begin_define
define|#
directive|define
name|WI_TX_CMP_FID
value|0x24
end_define

begin_comment
comment|/*  * Buffer Access Path (BAP) registers.  * These are I/O channels. I believe you can use each one for  * any desired purpose independently of the other. In general  * though, we use BAP1 for reading and writing LTV records and  * reading received data frames, and BAP0 for writing transmit  * frames. This is a convention though, not a rule.  */
end_comment

begin_define
define|#
directive|define
name|WI_SEL0
value|0x18
end_define

begin_define
define|#
directive|define
name|WI_SEL1
value|0x1A
end_define

begin_define
define|#
directive|define
name|WI_OFF0
value|0x1C
end_define

begin_define
define|#
directive|define
name|WI_OFF1
value|0x1E
end_define

begin_define
define|#
directive|define
name|WI_DATA0
value|0x36
end_define

begin_define
define|#
directive|define
name|WI_DATA1
value|0x38
end_define

begin_define
define|#
directive|define
name|WI_BAP0
value|WI_DATA0
end_define

begin_define
define|#
directive|define
name|WI_BAP1
value|WI_DATA1
end_define

begin_define
define|#
directive|define
name|WI_OFF_BUSY
value|0x8000
end_define

begin_define
define|#
directive|define
name|WI_OFF_ERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|WI_OFF_DATAOFF
value|0x0FFF
end_define

begin_comment
comment|/* Event registers */
end_comment

begin_define
define|#
directive|define
name|WI_EVENT_STAT
value|0x30
end_define

begin_comment
comment|/* Event status */
end_comment

begin_define
define|#
directive|define
name|WI_INT_EN
value|0x32
end_define

begin_comment
comment|/* Interrupt enable/disable */
end_comment

begin_define
define|#
directive|define
name|WI_EVENT_ACK
value|0x34
end_define

begin_comment
comment|/* Ack event */
end_comment

begin_comment
comment|/* Events */
end_comment

begin_define
define|#
directive|define
name|WI_EV_TICK
value|0x8000
end_define

begin_comment
comment|/* aux timer tick */
end_comment

begin_define
define|#
directive|define
name|WI_EV_RES
value|0x4000
end_define

begin_comment
comment|/* controller h/w error (time out) */
end_comment

begin_define
define|#
directive|define
name|WI_EV_INFO_DROP
value|0x2000
end_define

begin_comment
comment|/* no RAM to build unsolicited frame */
end_comment

begin_define
define|#
directive|define
name|WI_EV_NO_CARD
value|0x0800
end_define

begin_comment
comment|/* card removed (hunh?) */
end_comment

begin_define
define|#
directive|define
name|WI_EV_DUIF_RX
value|0x0400
end_define

begin_comment
comment|/* wavelan management packet received */
end_comment

begin_define
define|#
directive|define
name|WI_EV_INFO
value|0x0080
end_define

begin_comment
comment|/* async info frame */
end_comment

begin_define
define|#
directive|define
name|WI_EV_CMD
value|0x0010
end_define

begin_comment
comment|/* command completed */
end_comment

begin_define
define|#
directive|define
name|WI_EV_ALLOC
value|0x0008
end_define

begin_comment
comment|/* async alloc/reclaim completed */
end_comment

begin_define
define|#
directive|define
name|WI_EV_TX_EXC
value|0x0004
end_define

begin_comment
comment|/* async xmit completed with failure */
end_comment

begin_define
define|#
directive|define
name|WI_EV_TX
value|0x0002
end_define

begin_comment
comment|/* async xmit completed succesfully */
end_comment

begin_define
define|#
directive|define
name|WI_EV_RX
value|0x0001
end_define

begin_comment
comment|/* async rx completed */
end_comment

begin_comment
comment|/* Host software registers */
end_comment

begin_define
define|#
directive|define
name|WI_SW0
value|0x28
end_define

begin_define
define|#
directive|define
name|WI_SW1
value|0x2A
end_define

begin_define
define|#
directive|define
name|WI_SW2
value|0x2C
end_define

begin_define
define|#
directive|define
name|WI_SW3
value|0x2E
end_define

begin_comment
comment|/* does not appear in Prism2 */
end_comment

begin_define
define|#
directive|define
name|WI_CNTL
value|0x14
end_define

begin_define
define|#
directive|define
name|WI_CNTL_AUX_ENA
value|0xC000
end_define

begin_define
define|#
directive|define
name|WI_CNTL_AUX_ENA_STAT
value|0xC000
end_define

begin_define
define|#
directive|define
name|WI_CNTL_AUX_DIS_STAT
value|0x0000
end_define

begin_define
define|#
directive|define
name|WI_CNTL_AUX_ENA_CNTL
value|0x8000
end_define

begin_define
define|#
directive|define
name|WI_CNTL_AUX_DIS_CNTL
value|0x4000
end_define

begin_define
define|#
directive|define
name|WI_AUX_PAGE
value|0x3A
end_define

begin_define
define|#
directive|define
name|WI_AUX_OFFSET
value|0x3C
end_define

begin_define
define|#
directive|define
name|WI_AUX_DATA
value|0x3E
end_define

begin_define
define|#
directive|define
name|WI_AUX_PGSZ
value|128
end_define

begin_define
define|#
directive|define
name|WI_AUX_KEY0
value|0xfe01
end_define

begin_define
define|#
directive|define
name|WI_AUX_KEY1
value|0xdc23
end_define

begin_define
define|#
directive|define
name|WI_AUX_KEY2
value|0xba45
end_define

begin_define
define|#
directive|define
name|WI_COR
value|0x40
end_define

begin_comment
comment|/* only for Symbol */
end_comment

begin_define
define|#
directive|define
name|WI_COR_RESET
value|0x0080
end_define

begin_define
define|#
directive|define
name|WI_COR_IOMODE
value|0x0041
end_define

begin_define
define|#
directive|define
name|WI_HCR
value|0x42
end_define

begin_comment
comment|/* only for Symbol */
end_comment

begin_define
define|#
directive|define
name|WI_HCR_4WIRE
value|0x0010
end_define

begin_define
define|#
directive|define
name|WI_HCR_RUN
value|0x0007
end_define

begin_define
define|#
directive|define
name|WI_HCR_HOLD
value|0x000f
end_define

begin_define
define|#
directive|define
name|WI_HCR_EEHOLD
value|0x00ce
end_define

begin_define
define|#
directive|define
name|WI_COR_OFFSET
value|0x3e0
end_define

begin_comment
comment|/* OK for PCI, must be bogus for pccard */
end_comment

begin_define
define|#
directive|define
name|WI_COR_VALUE
value|0x41
end_define

begin_comment
comment|/*  * One form of communication with the Hermes is with what Lucent calls  * LTV records, where LTV stands for Length, Type and Value. The length  * and type are 16 bits and are in native byte order. The value is in  * multiples of 16 bits and is in little endian byte order.  */
end_comment

begin_struct
struct|struct
name|wi_lt_hdr
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
comment|/* value is vary depends on resource id */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Download buffer location and length (0xFD01).  */
end_comment

begin_struct
struct|struct
name|wi_dnld_buf
block|{
name|u_int16_t
name|wi_buf_pg
decl_stmt|;
comment|/* page addr of intermediate dl buf*/
name|u_int16_t
name|wi_buf_off
decl_stmt|;
comment|/* offset of idb */
name|u_int16_t
name|wi_buf_len
decl_stmt|;
comment|/* len of idb */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mem sizes (0xFD02).  */
end_comment

begin_struct
struct|struct
name|wi_memsz
block|{
name|u_int16_t
name|wi_mem_ram
decl_stmt|;
name|u_int16_t
name|wi_mem_nvram
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NIC Identification (0xFD0B, 0xFD20)  */
end_comment

begin_struct
struct|struct
name|wi_ver
block|{
name|u_int16_t
name|wi_ver
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* define card ident */
end_comment

begin_define
define|#
directive|define
name|WI_NIC_LUCENT_ID
value|0x0001
end_define

begin_define
define|#
directive|define
name|WI_NIC_LUCENT_STR
value|"Lucent Technologies, WaveLAN/IEEE"
end_define

begin_define
define|#
directive|define
name|WI_NIC_SONY_ID
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_NIC_SONY_STR
value|"Sony WaveLAN/IEEE"
end_define

begin_define
define|#
directive|define
name|WI_NIC_LUCENT_EMB_ID
value|0x0005
end_define

begin_define
define|#
directive|define
name|WI_NIC_LUCENT_EMB_STR
value|"Lucent Embedded WaveLAN/IEEE"
end_define

begin_define
define|#
directive|define
name|WI_NIC_EVB2_ID
value|0x8000
end_define

begin_define
define|#
directive|define
name|WI_NIC_EVB2_STR
value|"RF:PRISM2 MAC:HFA3841"
end_define

begin_define
define|#
directive|define
name|WI_NIC_HWB3763_ID
value|0x8001
end_define

begin_define
define|#
directive|define
name|WI_NIC_HWB3763_STR
value|"RF:PRISM2 MAC:HFA3841 CARD:HWB3763 rev.B"
end_define

begin_define
define|#
directive|define
name|WI_NIC_HWB3163_ID
value|0x8002
end_define

begin_define
define|#
directive|define
name|WI_NIC_HWB3163_STR
value|"RF:PRISM2 MAC:HFA3841 CARD:HWB3163 rev.A"
end_define

begin_define
define|#
directive|define
name|WI_NIC_HWB3163B_ID
value|0x8003
end_define

begin_define
define|#
directive|define
name|WI_NIC_HWB3163B_STR
value|"RF:PRISM2 MAC:HFA3841 CARD:HWB3163 rev.B"
end_define

begin_define
define|#
directive|define
name|WI_NIC_EVB3_ID
value|0x8004
end_define

begin_define
define|#
directive|define
name|WI_NIC_EVB3_STR
value|"RF:PRISM2 MAC:HFA3842 CARD:HFA3842 EVAL"
end_define

begin_define
define|#
directive|define
name|WI_NIC_HWB1153_ID
value|0x8007
end_define

begin_define
define|#
directive|define
name|WI_NIC_HWB1153_STR
value|"RF:PRISM1 MAC:HFA3841 CARD:HWB1153"
end_define

begin_define
define|#
directive|define
name|WI_NIC_P2_SST_ID
value|0x8008
end_define

begin_comment
comment|/* Prism2 with SST flush */
end_comment

begin_define
define|#
directive|define
name|WI_NIC_P2_SST_STR
value|"RF:PRISM2 MAC:HFA3841 CARD:HWB3163-SST-flash"
end_define

begin_define
define|#
directive|define
name|WI_NIC_EVB2_SST_ID
value|0x8009
end_define

begin_define
define|#
directive|define
name|WI_NIC_EVB2_SST_STR
value|"RF:PRISM2 MAC:HFA3841 CARD:HWB3163-SST-flash"
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_EVA_ID
value|0x800A
end_define

begin_comment
comment|/* 3842 Evaluation Board */
end_comment

begin_define
define|#
directive|define
name|WI_NIC_3842_EVA_STR
value|"RF:PRISM2 MAC:HFA3842 CARD:HFA3842 EVAL"
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_PCMCIA_AMD_ID
value|0x800B
end_define

begin_comment
comment|/* Prism2.5 PCMCIA */
end_comment

begin_define
define|#
directive|define
name|WI_NIC_3842_PCMCIA_SST_ID
value|0x800C
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_PCMCIA_ATL_ID
value|0x800D
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_PCMCIA_ATS_ID
value|0x800E
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_PCMCIA_STR
value|"RF:PRISM2.5 MAC:ISL3873"
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_MINI_AMD_ID
value|0x8012
end_define

begin_comment
comment|/* Prism2.5 Mini-PCI */
end_comment

begin_define
define|#
directive|define
name|WI_NIC_3842_MINI_SST_ID
value|0x8013
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_MINI_ATL_ID
value|0x8014
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_MINI_ATS_ID
value|0x8015
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_MINI_STR
value|"RF:PRISM2.5 MAC:ISL3874A(Mini-PCI)"
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_PCI_AMD_ID
value|0x8016
end_define

begin_comment
comment|/* Prism2.5 PCI-bridge */
end_comment

begin_define
define|#
directive|define
name|WI_NIC_3842_PCI_SST_ID
value|0x8017
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_PCI_ATL_ID
value|0x8018
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_PCI_ATS_ID
value|0x8019
end_define

begin_define
define|#
directive|define
name|WI_NIC_3842_PCI_STR
value|"RF:PRISM2.5 MAC:ISL3874A(PCI-bridge)"
end_define

begin_define
define|#
directive|define
name|WI_NIC_P3_PCMCIA_AMD_ID
value|0x801A
end_define

begin_comment
comment|/* Prism3 PCMCIA */
end_comment

begin_define
define|#
directive|define
name|WI_NIC_P3_PCMCIA_SST_ID
value|0x801B
end_define

begin_define
define|#
directive|define
name|WI_NIC_P3_PCMCIA_ATL_ID
value|0x801C
end_define

begin_define
define|#
directive|define
name|WI_NIC_P3_PCMCIA_ATS_ID
value|0x801D
end_define

begin_define
define|#
directive|define
name|WI_NIC_P3_PCMCIA_STR
value|"RF:PRISM3(PCMCIA)"
end_define

begin_define
define|#
directive|define
name|WI_NIC_P3_MINI_AMD_ID
value|0x8021
end_define

begin_comment
comment|/* Prism3 Mini-PCI */
end_comment

begin_define
define|#
directive|define
name|WI_NIC_P3_MINI_SST_ID
value|0x8022
end_define

begin_define
define|#
directive|define
name|WI_NIC_P3_MINI_ATL_ID
value|0x8023
end_define

begin_define
define|#
directive|define
name|WI_NIC_P3_MINI_ATS_ID
value|0x8024
end_define

begin_define
define|#
directive|define
name|WI_NIC_P3_MINI_STR
value|"RF:PRISM3(Mini-PCI)"
end_define

begin_comment
comment|/*  * List of intended regulatory domains (0xFD11).  */
end_comment

begin_struct
struct|struct
name|wi_ltv_domains
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|u_int16_t
name|wi_num_dom
decl_stmt|;
name|u_int8_t
name|wi_domains
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * CIS struct (0xFD13).  */
end_comment

begin_struct
struct|struct
name|wi_cis
block|{
name|u_int16_t
name|wi_cis
index|[
literal|240
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Communications quality (0xFD43).  */
end_comment

begin_struct
struct|struct
name|wi_commqual
block|{
name|u_int16_t
name|wi_coms_qual
decl_stmt|;
name|u_int16_t
name|wi_sig_lvl
decl_stmt|;
name|u_int16_t
name|wi_noise_lvl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Actual system scale thresholds (0xFC06, 0xFD46).  */
end_comment

begin_struct
struct|struct
name|wi_scalethresh
block|{
name|u_int16_t
name|wi_energy_detect
decl_stmt|;
name|u_int16_t
name|wi_carrier_detect
decl_stmt|;
name|u_int16_t
name|wi_defer
decl_stmt|;
name|u_int16_t
name|wi_cell_search
decl_stmt|;
name|u_int16_t
name|wi_out_of_range
decl_stmt|;
name|u_int16_t
name|wi_delta_snr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PCF info struct (0xFD87).  */
end_comment

begin_struct
struct|struct
name|wi_pcf
block|{
name|u_int16_t
name|wi_medium_occupancy_limit
decl_stmt|;
name|u_int16_t
name|wi_cfp_period
decl_stmt|;
name|u_int16_t
name|wi_cfp_max_duration
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Connection control characteristics. (0xFC00)  * 0 == IBSS (802.11 compliant mode) (Only PRISM2)  * 1 == Basic Service Set (BSS)  * 2 == Wireless Distribudion System (WDS)  * 3 == Pseudo IBSS   *	(Only PRISM2; not 802.11 compliant mode, testing use only)  * 6 == HOST AP (Only PRISM2)  */
end_comment

begin_define
define|#
directive|define
name|WI_PORTTYPE_IBSS
value|0x0
end_define

begin_define
define|#
directive|define
name|WI_PORTTYPE_BSS
value|0x1
end_define

begin_define
define|#
directive|define
name|WI_PORTTYPE_WDS
value|0x2
end_define

begin_define
define|#
directive|define
name|WI_PORTTYPE_ADHOC
value|0x3
end_define

begin_define
define|#
directive|define
name|WI_PORTTYPE_HOSTAP
value|0x6
end_define

begin_comment
comment|/*  * Mac addresses. (0xFC01, 0xFC08)  */
end_comment

begin_struct
struct|struct
name|wi_macaddr
block|{
name|u_int8_t
name|wi_mac_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Station set identification (SSID). (0xFC02, 0xFC04)  */
end_comment

begin_struct
struct|struct
name|wi_ssid
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int8_t
name|wi_ssid
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Set our station name. (0xFC0E)  */
end_comment

begin_struct
struct|struct
name|wi_nodename
block|{
name|u_int16_t
name|wi_nodelen
decl_stmt|;
name|u_int8_t
name|wi_nodename
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Multicast addresses to be put in filter. We're  * allowed up to 16 addresses in the filter. (0xFC80)  */
end_comment

begin_struct
struct|struct
name|wi_mcast
block|{
name|struct
name|ether_addr
name|wi_mcast
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Join request. (0xFCE2)  */
end_comment

begin_struct
struct|struct
name|wi_joinreq
block|{
name|struct
name|ether_addr
name|wi_bssid
decl_stmt|;
name|u_int16_t
name|wi_chan
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * supported rates. (0xFCB4)  */
end_comment

begin_define
define|#
directive|define
name|WI_SUPPRATES_1M
value|0x0001
end_define

begin_define
define|#
directive|define
name|WI_SUPPRATES_2M
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_SUPPRATES_5M
value|0x0004
end_define

begin_define
define|#
directive|define
name|WI_SUPPRATES_11M
value|0x0008
end_define

begin_define
define|#
directive|define
name|WI_RATES_BITS
value|"\20\0011M\0022M\0035.5M\00411M"
end_define

begin_comment
comment|/*  * Information frame types.  */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_NOTIFY
value|0xF000
end_define

begin_comment
comment|/* Handover address */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_COUNTERS
value|0xF100
end_define

begin_comment
comment|/* Statistics counters */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_SCAN_RESULTS
value|0xF101
end_define

begin_comment
comment|/* Scan results */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_HOST_SCAN_RESULTS
value|0xF104
end_define

begin_comment
comment|/* Scan results */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_LINK_STAT
value|0xF200
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_LINK_STAT_CONNECTED
value|1
end_define

begin_define
define|#
directive|define
name|WI_INFO_LINK_STAT_DISCONNECTED
value|2
end_define

begin_define
define|#
directive|define
name|WI_INFO_LINK_STAT_AP_CHG
value|3
end_define

begin_comment
comment|/* AP Change */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_LINK_STAT_AP_OOR
value|4
end_define

begin_comment
comment|/* AP Out Of Range */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_LINK_STAT_AP_INR
value|5
end_define

begin_comment
comment|/* AP In Range */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_LINK_STAT_ASSOC_FAILED
value|6
end_define

begin_define
define|#
directive|define
name|WI_INFO_ASSOC_STAT
value|0xF201
end_define

begin_comment
comment|/* Association status */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_AUTH_REQUEST
value|0xF202
end_define

begin_comment
comment|/* Authentication Request (AP) */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_POWERSAVE_COUNT
value|0xF203
end_define

begin_comment
comment|/* PowerSave User Count (AP) */
end_comment

begin_struct
struct|struct
name|wi_assoc
block|{
name|u_int16_t
name|wi_assoc_stat
decl_stmt|;
comment|/* Association Status */
define|#
directive|define
name|ASSOC
value|1
define|#
directive|define
name|REASSOC
value|2
define|#
directive|define
name|DISASSOC
value|3
define|#
directive|define
name|ASSOCFAIL
value|4
define|#
directive|define
name|AUTHFAIL
value|5
name|u_int8_t
name|wi_assoc_sta
index|[
literal|6
index|]
decl_stmt|;
comment|/* Station Address */
name|u_int8_t
name|wi_assoc_osta
index|[
literal|6
index|]
decl_stmt|;
comment|/* OLD Station Address */
name|u_int16_t
name|wi_assoc_reason
decl_stmt|;
comment|/* Reason */
name|u_int16_t
name|wi_assoc_reserve
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scan Results of Prism2 chip  */
end_comment

begin_struct
struct|struct
name|wi_scan_header
block|{
name|u_int16_t
name|wi_reserve
decl_stmt|;
comment|/* future use */
name|u_int16_t
name|wi_reason
decl_stmt|;
comment|/* The reason this scan was initiated 						   1: Host initiated 						   2: Firmware initiated 						   3: Inquiry request from host */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wi_scan_data_p2
block|{
name|u_int16_t
name|wi_chid
decl_stmt|;
comment|/* BSS Channel ID from Probe Res.(PR)*/
name|u_int16_t
name|wi_noise
decl_stmt|;
comment|/* Average Noise Level of the PR */
name|u_int16_t
name|wi_signal
decl_stmt|;
comment|/* Signal Level on the PR */
name|u_int8_t
name|wi_bssid
index|[
literal|6
index|]
decl_stmt|;
comment|/* MACaddress of BSS responder from PR */
name|u_int16_t
name|wi_interval
decl_stmt|;
comment|/* BSS beacon interval */
name|u_int16_t
name|wi_capinfo
decl_stmt|;
comment|/* BSS Capability Information 						   IEEE Std 802.11(1997) ,see 7.3.1.4 */
name|u_int16_t
name|wi_namelen
decl_stmt|;
comment|/* Length of SSID strings */
name|u_int8_t
name|wi_name
index|[
literal|32
index|]
decl_stmt|;
comment|/* SSID strings */
name|u_int16_t
name|wi_suprate
index|[
literal|5
index|]
decl_stmt|;
comment|/* Supported Rates element from the PR 						   IEEE Std 802.11(1997) ,see 7.3.2.2 */
name|u_int16_t
name|wi_rate
decl_stmt|;
comment|/* Data rate of the PR */
define|#
directive|define
name|WI_APRATE_1
value|0x0A
comment|/* 1 Mbps */
define|#
directive|define
name|WI_APRATE_2
value|0x14
comment|/* 2 Mbps */
define|#
directive|define
name|WI_APRATE_5
value|0x37
comment|/* 5.5 Mbps */
define|#
directive|define
name|WI_APRATE_11
value|0x6E
comment|/* 11 Mbps */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scan Results of Lucent chip  */
end_comment

begin_struct
struct|struct
name|wi_scan_data
block|{
name|u_int16_t
name|wi_chid
decl_stmt|;
comment|/* BSS Channel ID from PR */
name|u_int16_t
name|wi_noise
decl_stmt|;
comment|/* Average Noise Level of the PR */
name|u_int16_t
name|wi_signal
decl_stmt|;
comment|/* Signal Level on the PR */
name|u_int8_t
name|wi_bssid
index|[
literal|6
index|]
decl_stmt|;
comment|/* MACaddress of BSS responder from PR */
name|u_int16_t
name|wi_interval
decl_stmt|;
comment|/* BSS beacon interval */
name|u_int16_t
name|wi_capinfo
decl_stmt|;
comment|/* BSS Capability Information 						   IEEE Std 802.11(1997) ,see 7.3.1.4 */
name|u_int16_t
name|wi_namelen
decl_stmt|;
comment|/* Length of SSID strings */
name|u_int8_t
name|wi_name
index|[
literal|32
index|]
decl_stmt|;
comment|/* SSID strings */
block|}
struct|;
end_struct

begin_comment
comment|/*  * transmit/receive frame structure  */
end_comment

begin_struct
struct|struct
name|wi_frame
block|{
name|u_int16_t
name|wi_status
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|wi_rx_tstamp1
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|wi_rx_tstamp0
decl_stmt|;
comment|/* 0x04 */
name|u_int8_t
name|wi_rx_silence
decl_stmt|;
comment|/* 0x06 */
name|u_int8_t
name|wi_rx_signal
decl_stmt|;
comment|/* 0x07 */
name|u_int8_t
name|wi_rx_rate
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|wi_rx_flow
decl_stmt|;
comment|/* 0x09 */
name|u_int8_t
name|wi_tx_rtry
decl_stmt|;
comment|/* 0x0a */
comment|/* Prism2 AP Only */
name|u_int8_t
name|wi_tx_rate
decl_stmt|;
comment|/* 0x0b */
comment|/* Prism2 AP Only */
name|u_int16_t
name|wi_tx_ctl
decl_stmt|;
comment|/* 0x0c */
name|struct
name|ieee80211_frame_addr4
name|wi_whdr
decl_stmt|;
comment|/* 0x0e */
name|u_int16_t
name|wi_dat_len
decl_stmt|;
comment|/* 0x2c */
name|struct
name|ether_header
name|wi_ehdr
decl_stmt|;
comment|/* 0x2e */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Tx Status Field */
end_comment

begin_define
define|#
directive|define
name|WI_TXSTAT_RET_ERR
value|0x0001
end_define

begin_define
define|#
directive|define
name|WI_TXSTAT_AGED_ERR
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_TXSTAT_DISCONNECT
value|0x0004
end_define

begin_define
define|#
directive|define
name|WI_TXSTAT_FORM_ERR
value|0x0008
end_define

begin_comment
comment|/* Rx Status Field */
end_comment

begin_define
define|#
directive|define
name|WI_STAT_BADCRC
value|0x0001
end_define

begin_define
define|#
directive|define
name|WI_STAT_UNDECRYPTABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_STAT_ERRSTAT
value|0x0003
end_define

begin_define
define|#
directive|define
name|WI_STAT_MAC_PORT
value|0x0700
end_define

begin_define
define|#
directive|define
name|WI_STAT_PCF
value|0x1000
end_define

begin_define
define|#
directive|define
name|WI_RXSTAT_MSG_TYPE
value|0xE000
end_define

begin_define
define|#
directive|define
name|WI_STAT_1042
value|0x2000
end_define

begin_comment
comment|/* RFC1042 encoded */
end_comment

begin_define
define|#
directive|define
name|WI_STAT_TUNNEL
value|0x4000
end_define

begin_comment
comment|/* Bridge-tunnel encoded */
end_comment

begin_define
define|#
directive|define
name|WI_STAT_WMP_MSG
value|0x6000
end_define

begin_comment
comment|/* WaveLAN-II management protocol */
end_comment

begin_define
define|#
directive|define
name|WI_STAT_MGMT
value|0x8000
end_define

begin_comment
comment|/* 802.11b management frames */
end_comment

begin_define
define|#
directive|define
name|WI_ENC_TX_E_II
value|0x0E
end_define

begin_define
define|#
directive|define
name|WI_ENC_TX_1042
value|0x00
end_define

begin_define
define|#
directive|define
name|WI_ENC_TX_TUNNEL
value|0xF8
end_define

begin_comment
comment|/* TxControl Field (enhanced) */
end_comment

begin_define
define|#
directive|define
name|WI_TXCNTL_TX_OK
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_TXCNTL_TX_EX
value|0x0004
end_define

begin_define
define|#
directive|define
name|WI_TXCNTL_STRUCT_TYPE
value|0x0018
end_define

begin_define
define|#
directive|define
name|WI_ENC_TX_802_3
value|0x00
end_define

begin_define
define|#
directive|define
name|WI_ENC_TX_802_11
value|0x08
end_define

begin_define
define|#
directive|define
name|WI_TXCNTL_ALTRTRY
value|0x0020
end_define

begin_define
define|#
directive|define
name|WI_TXCNTL_NOCRYPT
value|0x0080
end_define

begin_comment
comment|/*  * HFA3861/3863 (BBP) Control Registers  */
end_comment

begin_define
define|#
directive|define
name|WI_HFA386X_CR_A_D_TEST_MODES2
value|0x1A
end_define

begin_define
define|#
directive|define
name|WI_HFA386X_CR_MANUAL_TX_POWER
value|0x3E
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE80211_RADIOTAP_F_CFP
end_ifdef

begin_comment
comment|/*  * Radio capture format for Prism.  */
end_comment

begin_define
define|#
directive|define
name|WI_RX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) | \ 	 (1<< IEEE80211_RADIOTAP_RATE) | \ 	 (1<< IEEE80211_RADIOTAP_CHANNEL) | \ 	 (1<< IEEE80211_RADIOTAP_DB_ANTSIGNAL) | \ 	 (1<< IEEE80211_RADIOTAP_DB_ANTNOISE))
end_define

begin_struct
struct|struct
name|wi_rx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wr_ihdr
decl_stmt|;
name|u_int8_t
name|wr_flags
decl_stmt|;
name|u_int8_t
name|wr_rate
decl_stmt|;
name|u_int16_t
name|wr_chan_freq
decl_stmt|;
name|u_int16_t
name|wr_chan_flags
decl_stmt|;
name|u_int8_t
name|wr_antsignal
decl_stmt|;
name|u_int8_t
name|wr_antnoise
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_TX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) | \ 	 (1<< IEEE80211_RADIOTAP_RATE) | \ 	 (1<< IEEE80211_RADIOTAP_CHANNEL))
end_define

begin_struct
struct|struct
name|wi_tx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wt_ihdr
decl_stmt|;
name|u_int8_t
name|wt_flags
decl_stmt|;
name|u_int8_t
name|wt_rate
decl_stmt|;
name|u_int16_t
name|wt_chan_freq
decl_stmt|;
name|u_int16_t
name|wt_chan_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE80211_RADIOTAP_F_CFP */
end_comment

end_unit

