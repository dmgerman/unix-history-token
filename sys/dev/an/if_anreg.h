begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|AN_TIMEOUT
value|65536
end_define

begin_comment
comment|/* Default network name:<empty string> */
end_comment

begin_define
define|#
directive|define
name|AN_DEFAULT_NETNAME
value|""
end_define

begin_comment
comment|/* The nodename must be less than 16 bytes */
end_comment

begin_define
define|#
directive|define
name|AN_DEFAULT_NODENAME
value|"FreeBSD"
end_define

begin_define
define|#
directive|define
name|AN_DEFAULT_IBSS
value|"FreeBSD IBSS"
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

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
value|bus_space_write_2(sc->an_btag, sc->an_bhandle, reg, val)
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
value|bus_space_read_2(sc->an_btag, sc->an_bhandle, reg)
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
value|bus_space_write_1(sc->an_btag, sc->an_bhandle, reg, val)
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
value|bus_space_read_1(sc->an_btag, sc->an_bhandle, reg)
end_define

begin_comment
comment|/*  * memory space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_MEM_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(sc->an_mem_btag, sc->an_mem_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_MEM_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2(sc->an_mem_btag, sc->an_mem_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_MEM_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->an_mem_btag, sc->an_mem_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_MEM_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1(sc->an_mem_btag, sc->an_mem_bhandle, reg)
end_define

begin_comment
comment|/*  * aux. memory space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_MEM_AUX_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->an_mem_aux_btag, sc->an_mem_aux_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_MEM_AUX_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->an_mem_aux_btag, sc->an_mem_aux_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_MEM_AUX_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->an_mem_aux_btag, sc->an_mem_aux_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_MEM_AUX_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1(sc->an_mem_aux_btag, sc->an_mem_aux_bhandle, reg)
end_define

begin_comment
comment|/*  * Size of Aironet I/O space.  */
end_comment

begin_define
define|#
directive|define
name|AN_IOSIZ
value|0x40
end_define

begin_comment
comment|/*  * Size of aux. memory space ... probably not needed DJA   */
end_comment

begin_define
define|#
directive|define
name|AN_AUX_MEM_SIZE
value|(256 * 1024)
end_define

begin_comment
comment|/*  * Hermes register definitions and what little I know about them.  */
end_comment

begin_comment
comment|/* Hermes command/status registers. */
end_comment

begin_define
define|#
directive|define
name|AN_COMMAND
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x00 : 0x00)
end_define

begin_define
define|#
directive|define
name|AN_PARAM0
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x04 : 0x02)
end_define

begin_define
define|#
directive|define
name|AN_PARAM1
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x08 : 0x04)
end_define

begin_define
define|#
directive|define
name|AN_PARAM2
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x0c : 0x06)
end_define

begin_define
define|#
directive|define
name|AN_STATUS
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x10 : 0x08)
end_define

begin_define
define|#
directive|define
name|AN_RESP0
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x14 : 0x0A)
end_define

begin_define
define|#
directive|define
name|AN_RESP1
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x18 : 0x0C)
end_define

begin_define
define|#
directive|define
name|AN_RESP2
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x1c : 0x0E)
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x20 : 0x10)
end_define

begin_comment
comment|/* Command register */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_BUSY
value|0x8000
end_define

begin_comment
comment|/* busy bit */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_NO_ACK
value|0x0080
end_define

begin_comment
comment|/* don't acknowledge command */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_CODE_MASK
value|0x003F
end_define

begin_define
define|#
directive|define
name|AN_CMD_QUAL_MASK
value|0x7F00
end_define

begin_comment
comment|/* Command codes */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_NOOP
value|0x0000
end_define

begin_comment
comment|/* no-op */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_ENABLE
value|0x0001
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_DISABLE
value|0x0002
end_define

begin_comment
comment|/* disable */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_FORCE_SYNCLOSS
value|0x0003
end_define

begin_comment
comment|/* force loss of sync */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_FW_RESTART
value|0x0004
end_define

begin_comment
comment|/* firmware restart */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_HOST_SLEEP
value|0x0005
end_define

begin_define
define|#
directive|define
name|AN_CMD_MAGIC_PKT
value|0x0006
end_define

begin_define
define|#
directive|define
name|AN_CMD_READCFG
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_CMD_SET_MODE
value|0x0009
end_define

begin_define
define|#
directive|define
name|AN_CMD_ALLOC_MEM
value|0x000A
end_define

begin_comment
comment|/* allocate NIC memory */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_TX
value|0x000B
end_define

begin_comment
comment|/* transmit */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_DEALLOC_MEM
value|0x000C
end_define

begin_define
define|#
directive|define
name|AN_CMD_NOOP2
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_CMD_ALLOC_DESC
value|0x0020
end_define

begin_define
define|#
directive|define
name|AN_CMD_ACCESS
value|0x0021
end_define

begin_define
define|#
directive|define
name|AN_CMD_ALLOC_BUF
value|0x0028
end_define

begin_define
define|#
directive|define
name|AN_CMD_PSP_NODES
value|0x0030
end_define

begin_define
define|#
directive|define
name|AN_CMD_SET_PHYREG
value|0x003E
end_define

begin_define
define|#
directive|define
name|AN_CMD_TX_TEST
value|0x003F
end_define

begin_define
define|#
directive|define
name|AN_CMD_SLEEP
value|0x0085
end_define

begin_define
define|#
directive|define
name|AN_CMD_SAVECFG
value|0x0108
end_define

begin_comment
comment|/*  * MPI 350 DMA descriptor information  */
end_comment

begin_define
define|#
directive|define
name|AN_DESCRIPTOR_TX
value|0x01
end_define

begin_define
define|#
directive|define
name|AN_DESCRIPTOR_RX
value|0x02
end_define

begin_define
define|#
directive|define
name|AN_DESCRIPTOR_TXCMP
value|0x04
end_define

begin_define
define|#
directive|define
name|AN_DESCRIPTOR_HOSTWRITE
value|0x08
end_define

begin_define
define|#
directive|define
name|AN_DESCRIPTOR_HOSTREAD
value|0x10
end_define

begin_define
define|#
directive|define
name|AN_DESCRIPTOR_HOSTRW
value|0x20
end_define

begin_define
define|#
directive|define
name|AN_MAX_RX_DESC
value|1
end_define

begin_define
define|#
directive|define
name|AN_MAX_TX_DESC
value|1
end_define

begin_define
define|#
directive|define
name|AN_HOSTBUFSIZ
value|1840
end_define

begin_struct
struct|struct
name|an_card_rid_desc
block|{
name|unsigned
name|an_rid
range|:
literal|16
decl_stmt|;
name|unsigned
name|an_len
range|:
literal|15
decl_stmt|;
name|unsigned
name|an_valid
range|:
literal|1
decl_stmt|;
name|u_int64_t
name|an_phys
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_card_rx_desc
block|{
name|unsigned
name|an_ctrl
range|:
literal|15
decl_stmt|;
name|unsigned
name|an_done
range|:
literal|1
decl_stmt|;
name|unsigned
name|an_len
range|:
literal|15
decl_stmt|;
name|unsigned
name|an_valid
range|:
literal|1
decl_stmt|;
name|u_int64_t
name|an_phys
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_card_tx_desc
block|{
name|unsigned
name|an_offset
range|:
literal|15
decl_stmt|;
name|unsigned
name|an_eoc
range|:
literal|1
decl_stmt|;
name|unsigned
name|an_len
range|:
literal|15
decl_stmt|;
name|unsigned
name|an_valid
range|:
literal|1
decl_stmt|;
name|u_int64_t
name|an_phys
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_RID_BUFFER_SIZE
value|AN_MAX_DATALEN
end_define

begin_define
define|#
directive|define
name|AN_RX_BUFFER_SIZE
value|AN_HOSTBUFSIZ
end_define

begin_define
define|#
directive|define
name|AN_TX_BUFFER_SIZE
value|AN_HOSTBUFSIZ
end_define

begin_comment
comment|/*#define AN_HOST_DESC_OFFSET	0xC sort of works */
end_comment

begin_define
define|#
directive|define
name|AN_HOST_DESC_OFFSET
value|0x800
end_define

begin_define
define|#
directive|define
name|AN_RX_DESC_OFFSET
value|(AN_HOST_DESC_OFFSET + \     sizeof(struct an_card_rid_desc))
end_define

begin_define
define|#
directive|define
name|AN_TX_DESC_OFFSET
value|(AN_RX_DESC_OFFSET + \     (AN_MAX_RX_DESC * sizeof(struct an_card_rx_desc)))
end_define

begin_struct
struct|struct
name|an_command
block|{
name|u_int16_t
name|an_cmd
decl_stmt|;
name|u_int16_t
name|an_parm0
decl_stmt|;
name|u_int16_t
name|an_parm1
decl_stmt|;
name|u_int16_t
name|an_parm2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_reply
block|{
name|u_int16_t
name|an_status
decl_stmt|;
name|u_int16_t
name|an_resp0
decl_stmt|;
name|u_int16_t
name|an_resp1
decl_stmt|;
name|u_int16_t
name|an_resp2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reclaim qualifier bit, applicable to the  * TX command.  */
end_comment

begin_define
define|#
directive|define
name|AN_RECLAIM
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
name|AN_ACCESS_READ
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_ACCESS_WRITE
value|0x0100
end_define

begin_comment
comment|/*  * PROGRAM command qualifier bits.  */
end_comment

begin_define
define|#
directive|define
name|AN_PROGRAM_DISABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_PROGRAM_ENABLE_RAM
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_PROGRAM_ENABLE_NVRAM
value|0x0200
end_define

begin_define
define|#
directive|define
name|AN_PROGRAM_NVRAM
value|0x0300
end_define

begin_comment
comment|/* Status register values */
end_comment

begin_define
define|#
directive|define
name|AN_STAT_CMD_CODE
value|0x003F
end_define

begin_define
define|#
directive|define
name|AN_STAT_CMD_RESULT
value|0x7F00
end_define

begin_comment
comment|/* Linkstat register */
end_comment

begin_define
define|#
directive|define
name|AN_LINKSTAT_ASSOCIATED
value|0x0400
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_AUTHFAIL
value|0x0300
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_ASSOC_FAIL
value|0x8400
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_DISASSOC
value|0x8200
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_DEAUTH
value|0x8100
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_TSF
value|0x8004
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_HOSTREQ
value|0x8003
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_AVGRETRY
value|0x8002
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_MAXRETRY
value|0x8001
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_MISSBEACON
value|0x8000
end_define

begin_comment
comment|/* memory handle management registers */
end_comment

begin_define
define|#
directive|define
name|AN_RX_FID
value|0x20
end_define

begin_define
define|#
directive|define
name|AN_ALLOC_FID
value|0x22
end_define

begin_define
define|#
directive|define
name|AN_TX_CMP_FID
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x1a : 0x24)
end_define

begin_comment
comment|/*  * Buffer Access Path (BAP) registers.  * These are I/O channels. I believe you can use each one for  * any desired purpose independently of the other. In general  * though, we use BAP1 for reading and writing LTV records and  * reading received data frames, and BAP0 for writing transmit  * frames. This is a convention though, not a rule.  */
end_comment

begin_define
define|#
directive|define
name|AN_SEL0
value|0x18
end_define

begin_define
define|#
directive|define
name|AN_SEL1
value|0x1A
end_define

begin_define
define|#
directive|define
name|AN_OFF0
value|0x1C
end_define

begin_define
define|#
directive|define
name|AN_OFF1
value|0x1E
end_define

begin_define
define|#
directive|define
name|AN_DATA0
value|0x36
end_define

begin_define
define|#
directive|define
name|AN_DATA1
value|0x38
end_define

begin_define
define|#
directive|define
name|AN_BAP0
value|AN_DATA0
end_define

begin_define
define|#
directive|define
name|AN_BAP1
value|AN_DATA1
end_define

begin_define
define|#
directive|define
name|AN_OFF_BUSY
value|0x8000
end_define

begin_define
define|#
directive|define
name|AN_OFF_ERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|AN_OFF_DONE
value|0x2000
end_define

begin_define
define|#
directive|define
name|AN_OFF_DATAOFF
value|0x0FFF
end_define

begin_comment
comment|/* Event registers */
end_comment

begin_define
define|#
directive|define
name|AN_EVENT_STAT
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x60 : 0x30)
end_define

begin_comment
comment|/* Event status */
end_comment

begin_define
define|#
directive|define
name|AN_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x64 : 0x32)
end_define

begin_comment
comment|/* Interrupt enable/ 							   disable */
end_comment

begin_define
define|#
directive|define
name|AN_EVENT_ACK
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x68 : 0x34)
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
name|AN_EV_CLR_STUCK_BUSY
value|0x4000
end_define

begin_comment
comment|/* clear stuck busy bit */
end_comment

begin_define
define|#
directive|define
name|AN_EV_WAKEREQUEST
value|0x2000
end_define

begin_comment
comment|/* awaken from PSP mode */
end_comment

begin_define
define|#
directive|define
name|AN_EV_MIC
value|0x1000
end_define

begin_comment
comment|/* Message Integrity Check*/
end_comment

begin_define
define|#
directive|define
name|AN_EV_AWAKE
value|0x0100
end_define

begin_comment
comment|/* station woke up from PSP mode*/
end_comment

begin_define
define|#
directive|define
name|AN_EV_LINKSTAT
value|0x0080
end_define

begin_comment
comment|/* link status available */
end_comment

begin_define
define|#
directive|define
name|AN_EV_CMD
value|0x0010
end_define

begin_comment
comment|/* command completed */
end_comment

begin_define
define|#
directive|define
name|AN_EV_ALLOC
value|0x0008
end_define

begin_comment
comment|/* async alloc/reclaim completed */
end_comment

begin_define
define|#
directive|define
name|AN_EV_TX_CPY
value|0x0400
end_define

begin_define
define|#
directive|define
name|AN_EV_TX_EXC
value|0x0004
end_define

begin_comment
comment|/* async xmit completed with failure */
end_comment

begin_define
define|#
directive|define
name|AN_EV_TX
value|0x0002
end_define

begin_comment
comment|/* async xmit completed succesfully */
end_comment

begin_define
define|#
directive|define
name|AN_EV_RX
value|0x0001
end_define

begin_comment
comment|/* async rx completed */
end_comment

begin_define
define|#
directive|define
name|AN_INTRS
parameter_list|(
name|x
parameter_list|)
define|\
value|( x ? (AN_EV_RX|AN_EV_TX|AN_EV_TX_EXC|AN_EV_TX_CPY|AN_EV_ALLOC \ 	       |AN_EV_LINKSTAT|AN_EV_MIC) \ 	  : \ 	      (AN_EV_RX|AN_EV_TX|AN_EV_TX_EXC|AN_EV_ALLOC \ 	       |AN_EV_LINKSTAT|AN_EV_MIC) \ 	      )
end_define

begin_comment
comment|/* Host software registers */
end_comment

begin_define
define|#
directive|define
name|AN_SW0
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x50 : 0x28)
end_define

begin_define
define|#
directive|define
name|AN_SW1
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x54 : 0x2A)
end_define

begin_define
define|#
directive|define
name|AN_SW2
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x58 : 0x2C)
end_define

begin_define
define|#
directive|define
name|AN_SW3
parameter_list|(
name|x
parameter_list|)
value|(x ? 0x5c : 0x2E)
end_define

begin_define
define|#
directive|define
name|AN_CNTL
value|0x14
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_ENA
value|0xC000
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_ENA_STAT
value|0xC000
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_DIS_STAT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_ENA_CNTL
value|0x8000
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_DIS_CNTL
value|0x4000
end_define

begin_define
define|#
directive|define
name|AN_AUX_PAGE
value|0x3A
end_define

begin_define
define|#
directive|define
name|AN_AUX_OFFSET
value|0x3C
end_define

begin_define
define|#
directive|define
name|AN_AUX_DATA
value|0x3E
end_define

begin_comment
comment|/*  * Length, Type, Value (LTV) record definitions and RID values.  */
end_comment

begin_struct
struct|struct
name|an_ltv_gen
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_DEF_SSID_LEN
value|7
end_define

begin_define
define|#
directive|define
name|AN_DEF_SSID
value|"tsunami"
end_define

begin_define
define|#
directive|define
name|AN_RXGAP_MAX
value|8
end_define

begin_comment
comment|/*  * Transmit frame structure.  */
end_comment

begin_struct
struct|struct
name|an_txframe
block|{
name|u_int32_t
name|an_tx_sw
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_tx_status
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|an_tx_payload_len
decl_stmt|;
comment|/* 0x06 */
name|u_int16_t
name|an_tx_ctl
decl_stmt|;
comment|/* 0x08 */
name|u_int16_t
name|an_tx_assoc_id
decl_stmt|;
comment|/* 0x0A */
name|u_int16_t
name|an_tx_retry
decl_stmt|;
comment|/* 0x0C */
name|u_int8_t
name|an_tx_assoc_cnt
decl_stmt|;
comment|/* 0x0E */
name|u_int8_t
name|an_tx_rate
decl_stmt|;
comment|/* 0x0F */
name|u_int8_t
name|an_tx_max_long_retries
decl_stmt|;
comment|/* 0x10 */
name|u_int8_t
name|an_tx_max_short_retries
decl_stmt|;
comment|/*0x11 */
name|u_int8_t
name|an_rsvd0
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x12 */
name|u_int16_t
name|an_frame_ctl
decl_stmt|;
comment|/* 0x14 */
name|u_int16_t
name|an_duration
decl_stmt|;
comment|/* 0x16 */
name|u_int8_t
name|an_addr1
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x18 */
name|u_int8_t
name|an_addr2
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x1E */
name|u_int8_t
name|an_addr3
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x24 */
name|u_int16_t
name|an_seq_ctl
decl_stmt|;
comment|/* 0x2A */
name|u_int8_t
name|an_addr4
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x2C */
name|u_int8_t
name|an_gaplen
decl_stmt|;
comment|/* 0x32 */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|an_rxframe_802_3
block|{
name|u_int16_t
name|an_rx_802_3_status
decl_stmt|;
comment|/* 0x34 */
name|u_int16_t
name|an_rx_802_3_payload_len
decl_stmt|;
comment|/* 0x36 */
name|u_int8_t
name|an_rx_dst_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x38 */
name|u_int8_t
name|an_rx_src_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x3E */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_RXGAP_MAX
value|8
end_define

begin_struct
struct|struct
name|an_txframe_802_3
block|{
comment|/*  * Transmit 802.3 header structure.  */
name|u_int16_t
name|an_tx_802_3_status
decl_stmt|;
comment|/* 0x34 */
name|u_int16_t
name|an_tx_802_3_payload_len
decl_stmt|;
comment|/* 0x36 */
name|u_int8_t
name|an_tx_dst_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x38 */
name|u_int8_t
name|an_tx_src_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x3E */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_TXSTAT_EXCESS_RETRY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_TXSTAT_LIFE_EXCEEDED
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_TXSTAT_AID_FAIL
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_TXSTAT_MAC_DISABLED
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_TXSTAT_ASSOC_LOST
value|0x0020
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_RSVD
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_TXOK_INTR
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_TXERR_INTR
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_HEADER_TYPE
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_PAYLOAD_TYPE
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_NORELEASE
value|0x0020
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_NORETRIES
value|0x0040
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_CLEAR_AID
value|0x0080
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_STRICT_ORDER
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_USE_RTS
value|0x0200
end_define

begin_define
define|#
directive|define
name|AN_HEADERTYPE_8023
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_HEADERTYPE_80211
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_PAYLOADTYPE_ETHER
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_PAYLOADTYPE_LLC
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_80211
define|\
value|(AN_TXCTL_TXOK_INTR|AN_TXCTL_TXERR_INTR|AN_HEADERTYPE_80211|	\ 	AN_PAYLOADTYPE_LLC|AN_TXCTL_NORELEASE)
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_8023
define|\
value|(AN_TXCTL_TXOK_INTR|AN_TXCTL_TXERR_INTR|AN_HEADERTYPE_8023|	\ 	AN_PAYLOADTYPE_ETHER|AN_TXCTL_NORELEASE)
end_define

begin_define
define|#
directive|define
name|AN_TXGAP_80211
value|0
end_define

begin_define
define|#
directive|define
name|AN_TXGAP_8023
value|0
end_define

begin_struct
struct|struct
name|an_802_3_hdr
block|{
name|u_int16_t
name|an_8023_status
decl_stmt|;
name|u_int16_t
name|an_8023_payload_len
decl_stmt|;
name|u_int8_t
name|an_8023_dst_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|an_8023_src_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|an_8023_dat
index|[
literal|3
index|]
decl_stmt|;
comment|/* SNAP header */
name|u_int16_t
name|an_8023_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_snap_hdr
block|{
name|u_int16_t
name|an_snap_dat
index|[
literal|3
index|]
decl_stmt|;
comment|/* SNAP header */
name|u_int16_t
name|an_snap_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_dma_alloc
block|{
name|u_int32_t
name|an_dma_paddr
decl_stmt|;
name|caddr_t
name|an_dma_vaddr
decl_stmt|;
name|bus_dmamap_t
name|an_dma_map
decl_stmt|;
name|bus_dma_segment_t
name|an_dma_seg
decl_stmt|;
name|bus_size_t
name|an_dma_size
decl_stmt|;
name|int
name|an_dma_nseg
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_TX_RING_CNT
value|4
end_define

begin_define
define|#
directive|define
name|AN_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_struct
struct|struct
name|an_tx_ring_data
block|{
name|u_int16_t
name|an_tx_fids
index|[
name|AN_TX_RING_CNT
index|]
decl_stmt|;
name|u_int16_t
name|an_tx_ring
index|[
name|AN_TX_RING_CNT
index|]
decl_stmt|;
name|int
name|an_tx_prod
decl_stmt|;
name|int
name|an_tx_cons
decl_stmt|;
name|int
name|an_tx_empty
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_softc
block|{
name|struct
name|ifnet
modifier|*
name|an_ifp
decl_stmt|;
name|int
name|port_rid
decl_stmt|;
comment|/* resource id for port range */
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
comment|/* resource for port range */
name|int
name|mem_rid
decl_stmt|;
comment|/* resource id for memory range */
name|int
name|mem_used
decl_stmt|;
comment|/* nonzero if memory used */
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
comment|/* resource for memory range */
name|int
name|mem_aux_rid
decl_stmt|;
comment|/* resource id for memory range */
name|int
name|mem_aux_used
decl_stmt|;
comment|/* nonzero if memory used */
name|struct
name|resource
modifier|*
name|mem_aux_res
decl_stmt|;
comment|/* resource for memory range */
name|int
name|irq_rid
decl_stmt|;
comment|/* resource id for irq */
name|void
modifier|*
name|irq_handle
decl_stmt|;
comment|/* handle for irq handler */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* resource for irq */
name|bus_space_handle_t
name|an_bhandle_p
decl_stmt|;
name|bus_space_handle_t
name|an_bhandle
decl_stmt|;
name|bus_space_tag_t
name|an_btag
decl_stmt|;
name|bus_space_handle_t
name|an_mem_bhandle
decl_stmt|;
name|bus_space_tag_t
name|an_mem_btag
decl_stmt|;
name|bus_space_handle_t
name|an_mem_aux_bhandle
decl_stmt|;
name|bus_space_tag_t
name|an_mem_aux_btag
decl_stmt|;
name|bus_dma_tag_t
name|an_dtag
decl_stmt|;
name|struct
name|an_ltv_genconfig
name|an_config
decl_stmt|;
name|struct
name|an_ltv_caps
name|an_caps
decl_stmt|;
name|struct
name|an_ltv_ssidlist_new
name|an_ssidlist
decl_stmt|;
name|struct
name|an_ltv_aplist
name|an_aplist
decl_stmt|;
name|struct
name|an_ltv_key
name|an_temp_keys
index|[
literal|4
index|]
decl_stmt|;
name|int
name|an_tx_rate
decl_stmt|;
name|int
name|an_rxmode
decl_stmt|;
name|int
name|an_gone
decl_stmt|;
name|int
name|an_if_flags
decl_stmt|;
name|u_int8_t
name|an_txbuf
index|[
literal|1536
index|]
decl_stmt|;
name|struct
name|an_tx_ring_data
name|an_rdata
decl_stmt|;
name|struct
name|an_ltv_stats
name|an_stats
decl_stmt|;
name|struct
name|an_ltv_status
name|an_status
decl_stmt|;
name|u_int8_t
name|an_associated
decl_stmt|;
ifdef|#
directive|ifdef
name|ANCACHE
name|int
name|an_sigitems
decl_stmt|;
name|struct
name|an_sigcache
name|an_sigcache
index|[
name|MAXANCACHE
index|]
decl_stmt|;
name|int
name|an_nextitem
decl_stmt|;
name|int
name|an_have_rssimap
decl_stmt|;
name|struct
name|an_ltv_rssi_map
name|an_rssimap
decl_stmt|;
endif|#
directive|endif
name|struct
name|callout
name|an_stat_ch
decl_stmt|;
name|struct
name|mtx
name|an_mtx
decl_stmt|;
name|device_t
name|an_dev
decl_stmt|;
name|struct
name|ifmedia
name|an_ifmedia
decl_stmt|;
name|int
name|an_monitor
decl_stmt|;
name|int
name|an_was_monitor
decl_stmt|;
name|u_char
name|buf_802_11
index|[
name|MCLBYTES
index|]
decl_stmt|;
name|struct
name|an_req
name|areq
decl_stmt|;
name|unsigned
name|short
modifier|*
name|an_flash_buffer
decl_stmt|;
name|int
name|mpi350
decl_stmt|;
name|struct
name|an_dma_alloc
name|an_rid_buffer
decl_stmt|;
name|struct
name|an_dma_alloc
name|an_rx_buffer
index|[
name|AN_MAX_RX_DESC
index|]
decl_stmt|;
name|struct
name|an_dma_alloc
name|an_tx_buffer
index|[
name|AN_MAX_TX_DESC
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->an_mtx)
end_define

begin_define
define|#
directive|define
name|AN_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->an_mtx)
end_define

begin_define
define|#
directive|define
name|AN_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->an_mtx, MA_OWNED)
end_define

begin_function_decl
name|void
name|an_release_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_alloc_port
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_alloc_memory
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_alloc_aux_memory
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_alloc_irq
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_pci_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_shutdown
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|an_resume
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_attach
parameter_list|(
name|struct
name|an_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|an_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|an_stop
parameter_list|(
name|struct
name|an_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_intr_t
name|an_intr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AN_802_3_OFFSET
value|0x2E
end_define

begin_define
define|#
directive|define
name|AN_802_11_OFFSET
value|0x44
end_define

begin_define
define|#
directive|define
name|AN_802_11_OFFSET_RAW
value|0x3C
end_define

begin_define
define|#
directive|define
name|AN_STAT_BADCRC
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_STAT_UNDECRYPTABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_STAT_ERRSTAT
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_STAT_MAC_PORT
value|0x0700
end_define

begin_define
define|#
directive|define
name|AN_STAT_1042
value|0x2000
end_define

begin_comment
comment|/* RFC1042 encoded */
end_comment

begin_define
define|#
directive|define
name|AN_STAT_TUNNEL
value|0x4000
end_define

begin_comment
comment|/* Bridge-tunnel encoded */
end_comment

begin_define
define|#
directive|define
name|AN_STAT_WMP_MSG
value|0x6000
end_define

begin_comment
comment|/* WaveLAN-II management protocol */
end_comment

begin_define
define|#
directive|define
name|AN_RXSTAT_MSG_TYPE
value|0xE000
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_802_3
value|0x00
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_802_11
value|0x11
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_E_II
value|0x0E
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_1042
value|0x00
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_TUNNEL
value|0xF8
end_define

begin_define
define|#
directive|define
name|AN_TXCNTL_MACPORT
value|0x00FF
end_define

begin_define
define|#
directive|define
name|AN_TXCNTL_STRUCTTYPE
value|0xFF00
end_define

begin_comment
comment|/*  * SNAP (sub-network access protocol) constants for transmission  * of IP datagrams over IEEE 802 networks, taken from RFC1042.  * We need these for the LLC/SNAP header fields in the TX/RX frame  * structure.  */
end_comment

begin_define
define|#
directive|define
name|AN_SNAP_K1
value|0xaa
end_define

begin_comment
comment|/* assigned global SAP for SNAP */
end_comment

begin_define
define|#
directive|define
name|AN_SNAP_K2
value|0x00
end_define

begin_define
define|#
directive|define
name|AN_SNAP_CONTROL
value|0x03
end_define

begin_comment
comment|/* unnumbered information format */
end_comment

begin_define
define|#
directive|define
name|AN_SNAP_WORD0
value|(AN_SNAP_K1 | (AN_SNAP_K1<< 8))
end_define

begin_define
define|#
directive|define
name|AN_SNAP_WORD1
value|(AN_SNAP_K2 | (AN_SNAP_CONTROL<< 8))
end_define

begin_define
define|#
directive|define
name|AN_SNAPHDR_LEN
value|0x6
end_define

end_unit

