begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|wi_counters
block|{
name|u_int32_t
name|wi_tx_unicast_frames
decl_stmt|;
name|u_int32_t
name|wi_tx_multicast_frames
decl_stmt|;
name|u_int32_t
name|wi_tx_fragments
decl_stmt|;
name|u_int32_t
name|wi_tx_unicast_octets
decl_stmt|;
name|u_int32_t
name|wi_tx_multicast_octets
decl_stmt|;
name|u_int32_t
name|wi_tx_deferred_xmits
decl_stmt|;
name|u_int32_t
name|wi_tx_single_retries
decl_stmt|;
name|u_int32_t
name|wi_tx_multi_retries
decl_stmt|;
name|u_int32_t
name|wi_tx_retry_limit
decl_stmt|;
name|u_int32_t
name|wi_tx_discards
decl_stmt|;
name|u_int32_t
name|wi_rx_unicast_frames
decl_stmt|;
name|u_int32_t
name|wi_rx_multicast_frames
decl_stmt|;
name|u_int32_t
name|wi_rx_fragments
decl_stmt|;
name|u_int32_t
name|wi_rx_unicast_octets
decl_stmt|;
name|u_int32_t
name|wi_rx_multicast_octets
decl_stmt|;
name|u_int32_t
name|wi_rx_fcs_errors
decl_stmt|;
name|u_int32_t
name|wi_rx_discards_nobuf
decl_stmt|;
name|u_int32_t
name|wi_tx_discards_wrong_sa
decl_stmt|;
name|u_int32_t
name|wi_rx_WEP_cant_decrypt
decl_stmt|;
name|u_int32_t
name|wi_rx_msg_in_msg_frags
decl_stmt|;
name|u_int32_t
name|wi_rx_msg_in_bad_msg_frags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Encryption controls. We can enable or disable encryption as  * well as specify up to 4 encryption keys. We can also specify  * which of the four keys will be used for transmit encryption.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_ENCRYPTION
value|0xFC20
end_define

begin_define
define|#
directive|define
name|WI_RID_AUTHTYPE
value|0xFC21
end_define

begin_define
define|#
directive|define
name|WI_RID_DEFLT_CRYPT_KEYS
value|0xFCB0
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_CRYPT_KEY
value|0xFCB1
end_define

begin_define
define|#
directive|define
name|WI_RID_WEP_AVAIL
value|0xFD4F
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_TX_CRYPT_KEY
value|0xFC23
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY0
value|0xFC24
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY1
value|0xFC25
end_define

begin_define
define|#
directive|define
name|WI_RID_MICROWAVE_OVEN
value|0xFC25
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY2
value|0xFC26
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY3
value|0xFC27
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_ENCRYPTION
value|0xFC28
end_define

begin_define
define|#
directive|define
name|WI_RID_ROAMING_MODE
value|0xFC2D
end_define

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE
value|0xFD44
end_define

begin_comment
comment|/* current TX rate */
end_comment

begin_struct
struct|struct
name|wi_key
block|{
name|u_int16_t
name|wi_keylen
decl_stmt|;
name|u_int8_t
name|wi_keydat
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wi_ltv_keys
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|struct
name|wi_key
name|wi_keys
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wi_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|int
name|wi_unit
decl_stmt|;
name|struct
name|resource
modifier|*
name|local
decl_stmt|;
name|int
name|local_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|iobase
decl_stmt|;
name|int
name|iobase_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
name|bus_space_handle_t
name|wi_localhandle
decl_stmt|;
name|bus_space_tag_t
name|wi_localtag
decl_stmt|;
name|bus_space_handle_t
name|wi_bhandle
decl_stmt|;
name|bus_space_tag_t
name|wi_btag
decl_stmt|;
name|bus_space_handle_t
name|wi_bmemhandle
decl_stmt|;
name|bus_space_tag_t
name|wi_bmemtag
decl_stmt|;
name|void
modifier|*
name|wi_intrhand
decl_stmt|;
name|int
name|wi_io_addr
decl_stmt|;
name|int
name|wi_tx_data_id
decl_stmt|;
name|int
name|wi_tx_mgmt_id
decl_stmt|;
name|int
name|wi_gone
decl_stmt|;
name|int
name|wi_if_flags
decl_stmt|;
name|u_int16_t
name|wi_ptype
decl_stmt|;
name|u_int16_t
name|wi_portnum
decl_stmt|;
name|u_int16_t
name|wi_max_data_len
decl_stmt|;
name|u_int16_t
name|wi_rts_thresh
decl_stmt|;
name|u_int16_t
name|wi_ap_density
decl_stmt|;
name|u_int16_t
name|wi_tx_rate
decl_stmt|;
name|u_int16_t
name|wi_create_ibss
decl_stmt|;
name|u_int16_t
name|wi_channel
decl_stmt|;
name|u_int16_t
name|wi_pm_enabled
decl_stmt|;
name|u_int16_t
name|wi_mor_enabled
decl_stmt|;
name|u_int16_t
name|wi_max_sleep
decl_stmt|;
name|u_int16_t
name|wi_authtype
decl_stmt|;
name|u_int16_t
name|wi_roaming
decl_stmt|;
name|char
name|wi_node_name
index|[
literal|32
index|]
decl_stmt|;
name|char
name|wi_net_name
index|[
literal|32
index|]
decl_stmt|;
name|char
name|wi_ibss_name
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|wi_txbuf
index|[
literal|1596
index|]
decl_stmt|;
name|struct
name|wi_counters
name|wi_stats
decl_stmt|;
name|int
name|wi_has_wep
decl_stmt|;
name|int
name|wi_use_wep
decl_stmt|;
name|int
name|wi_tx_key
decl_stmt|;
name|struct
name|wi_ltv_keys
name|wi_keys
decl_stmt|;
ifdef|#
directive|ifdef
name|WICACHE
name|int
name|wi_sigitems
decl_stmt|;
name|struct
name|wi_sigcache
name|wi_sigcache
index|[
name|MAXWICACHE
index|]
decl_stmt|;
name|int
name|wi_nextitem
decl_stmt|;
endif|#
directive|endif
name|struct
name|callout_handle
name|wi_stat_ch
decl_stmt|;
name|struct
name|mtx
name|wi_mtx
decl_stmt|;
name|int
name|wi_prism2
decl_stmt|;
name|int
name|wi_firmware_ver
decl_stmt|;
name|int
name|wi_nic_type
decl_stmt|;
name|int
name|wi_bus_type
decl_stmt|;
comment|/* Bus attachment type */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_LOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WI_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

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
value|0
end_define

begin_define
define|#
directive|define
name|WI_PORT1
value|1
end_define

begin_define
define|#
directive|define
name|WI_PORT2
value|2
end_define

begin_define
define|#
directive|define
name|WI_PORT3
value|3
end_define

begin_define
define|#
directive|define
name|WI_PORT4
value|4
end_define

begin_define
define|#
directive|define
name|WI_PORT5
value|5
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
value|(WI_PORT0<< 8)
end_define

begin_comment
comment|/* Default TX rate: 2Mbps, auto fallback */
end_comment

begin_define
define|#
directive|define
name|WI_DEFAULT_TX_RATE
value|3
end_define

begin_comment
comment|/* Default network name: empty string implies any */
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
name|WI_DEFAULT_CHAN
value|3
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

begin_comment
comment|/*  * The WaveLAN/IEEE cards contain an 802.11 MAC controller which Lucent  * calls 'Hermes.' In typical fashion, getting documentation about this  * controller is about as easy as squeezing blood from a stone. Here  * is more or less what I know:  *  * - The Hermes controller is firmware driven, and the host interacts  *   with the Hermes via a firmware interface, which can change.  *  * - The Hermes is described in a document called: "Hermes Firmware  *   WaveLAN/IEEE Station Functions," document #010245, which of course  *   Lucent will not release without an NDA.  *  * - Lucent has created a library called HCF (Hardware Control Functions)  *   though which it wants developers to interact with the card. The HCF  *   is needlessly complex, ill conceived and badly documented. Actually,  *   the comments in the HCP code itself aren't bad, but the publically  *   available manual that comes with it is awful, probably due largely to  *   the fact that it has been emasculated in order to hide information  *   that Lucent wants to keep proprietary. The purpose of the HCF seems  *   to be to insulate the driver programmer from the Hermes itself so that  *   Lucent has an excuse not to release programming in for it.  *  * - Lucent only makes available documentation and code for 'HCF Light'  *   which is a stripped down version of HCF with certain features not  *   implemented, most notably support for 802.11 frames.  *  * - The HCF code which I have seen blows goats. Whoever decided to  *   use a 132 column format should be shot.  *  * Rather than actually use the Lucent HCF library, I have stripped all  * the useful information from it and used it to create a driver in the  * usual BSD form. Note: I don't want to hear anybody whining about the  * fact that the Lucent code is GPLed and mine isn't. I did not actually  * put any of Lucent's code in this driver: I only used it as a reference  * to obtain information about the underlying hardware. The Hermes  * programming interface is not GPLed, so bite me.  */
end_comment

begin_comment
comment|/*  * Size of Hermes I/O space.  */
end_comment

begin_define
define|#
directive|define
name|WI_IOSIZ
value|0x40
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
name|WI_CMD_PROGRAM
value|0x0022
end_define

begin_define
define|#
directive|define
name|WI_CMD_CODE_MASK
value|0x003F
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

begin_define
define|#
directive|define
name|WI_INTRS
define|\
value|(WI_EV_RX|WI_EV_TX|WI_EV_TX_EXC|WI_EV_ALLOC|WI_EV_INFO|WI_EV_INFO_DROP)
end_define

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
name|WI_COR_OFFSET
value|0x3e0
end_define

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
name|wi_ltv_gen
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|u_int16_t
name|wi_val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wi_ltv_str
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|u_int16_t
name|wi_str
index|[
literal|17
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_SETVAL
parameter_list|(
name|recno
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\ 		struct wi_ltv_gen	g;	\ 						\ 		g.wi_len = 2;			\ 		g.wi_type = recno;		\ 		g.wi_val = val;			\ 		wi_write_record(sc,&g);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|WI_SETSTR
parameter_list|(
name|recno
parameter_list|,
name|str
parameter_list|)
define|\
value|do {							\ 		struct wi_ltv_str	s;			\ 		int			l;			\ 								\ 		l = (strlen(str) + 1)& ~0x1;			\ 		bzero((char *)&s, sizeof(s));			\ 		s.wi_len = (l / 2) + 2;				\ 		s.wi_type = recno;				\ 		s.wi_str[0] = strlen(str);			\ 		bcopy(str, (char *)&s.wi_str[1], strlen(str));	\ 		wi_write_record(sc, (struct wi_ltv_gen *)&s);	\ 	} while (0)
end_define

begin_comment
comment|/*  * Download buffer location and length (0xFD01).  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_DNLD_BUF
value|0xFD01
end_define

begin_struct
struct|struct
name|wi_ltv_dnld_buf
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
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

begin_define
define|#
directive|define
name|WI_RID_MEMSZ
value|0xFD02
end_define

begin_struct
struct|struct
name|wi_ltv_memsz
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
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
comment|/*  * NIC Identification (0xFD0B)  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CARDID
value|0xFD0B
end_define

begin_struct
struct|struct
name|wi_ltv_ver
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|u_int16_t
name|wi_ver
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|WI_NIC_LUCENT
value|0x0001
comment|/* Emperically derived */
define|#
directive|define
name|WI_NIC_LUCENT_ALT
value|0x0005
comment|/* Emperically derived */
define|#
directive|define
name|WI_NIC_EVB2
value|0x8000
define|#
directive|define
name|WI_NIC_HWB3763
value|0x8001
define|#
directive|define
name|WI_NIC_HWB3163
value|0x8002
define|#
directive|define
name|WI_NIC_HWB3163B
value|0x8003
define|#
directive|define
name|WI_NIC_EVB3
value|0x8004
define|#
directive|define
name|WI_NIC_HWB1153
value|0x8007
define|#
directive|define
name|WI_NIC_P2_SST
value|0x8008
comment|/* Prism2 with SST flush */
define|#
directive|define
name|WI_NIC_PRISM2_5
value|0x800C
define|#
directive|define
name|WI_NIC_3874A
value|0x8013
comment|/* Prism2.5 Mini-PCI */
block|}
struct|;
end_struct

begin_comment
comment|/*  * List of intended regulatory domains (0xFD11).  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_DOMAINS
value|0xFD11
end_define

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
name|wi_domains
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * CIS struct (0xFD13).  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CIS
value|0xFD13
end_define

begin_struct
struct|struct
name|wi_ltv_cis
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
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

begin_define
define|#
directive|define
name|WI_RID_COMMQUAL
value|0xFD43
end_define

begin_struct
struct|struct
name|wi_ltv_commqual
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
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
comment|/*  * Actual system scale thresholds (0xFD46).  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_SYSTEM_SCALE
value|0xFC06
end_define

begin_define
define|#
directive|define
name|WI_RID_SCALETHRESH
value|0xFD46
end_define

begin_struct
struct|struct
name|wi_ltv_scalethresh
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
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

begin_define
define|#
directive|define
name|WI_RID_PCF
value|0xFD87
end_define

begin_struct
struct|struct
name|wi_ltv_pcf
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
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
name|wi_range
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Connection control characteristics.  * 1 == Basic Service Set (BSS)  * 2 == Wireless Distribudion System (WDS)  * 3 == Pseudo IBSS  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PORTTYPE
value|0xFC00
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

begin_comment
comment|/*  * Mac addresses.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAC_NODE
value|0xFC01
end_define

begin_define
define|#
directive|define
name|WI_RID_MAC_WDS
value|0xFC08
end_define

begin_struct
struct|struct
name|wi_ltv_macaddr
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|u_int16_t
name|wi_mac_addr
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Station set identification (SSID).  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_DESIRED_SSID
value|0xFC02
end_define

begin_define
define|#
directive|define
name|WI_RID_OWN_SSID
value|0xFC04
end_define

begin_struct
struct|struct
name|wi_ltv_ssid
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|u_int16_t
name|wi_id
index|[
literal|17
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Set communications channel (radio frequency).  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_OWN_CHNL
value|0xFC03
end_define

begin_comment
comment|/*  * Frame data size.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAX_DATALEN
value|0xFC07
end_define

begin_comment
comment|/*  * ESS power management enable  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PM_ENABLED
value|0xFC09
end_define

begin_comment
comment|/*  * ESS max PM sleep internal  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAX_SLEEP
value|0xFC0C
end_define

begin_comment
comment|/*  * Set our station name.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_NODENAME
value|0xFC0E
end_define

begin_struct
struct|struct
name|wi_ltv_nodename
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|u_int16_t
name|wi_nodename
index|[
literal|17
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_RID_AUTH_CNTL
value|0xFC2A
end_define

begin_comment
comment|/*  * Multicast addresses to be put in filter. We're  * allowed up to 16 addresses in the filter.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MCAST
value|0xFC80
end_define

begin_struct
struct|struct
name|wi_ltv_mcast
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
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
comment|/*  * Create IBSS.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CREATE_IBSS
value|0xFC81
end_define

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH
value|0xFC82
end_define

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH
value|0xFC83
end_define

begin_comment
comment|/*  * TX rate control  * 0 == Fixed 1mbps  * 1 == Fixed 2mbps  * 2 == auto fallback  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_TX_RATE
value|0xFC84
end_define

begin_comment
comment|/*  * promiscuous mode.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PROMISC
value|0xFC85
end_define

begin_comment
comment|/*  * Auxiliary Timer tick interval  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_TICK_TIME
value|0xFCE0
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
name|WI_INFO_LINK_STAT
value|0xF200
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|WI_INFO_ASSOC_STAT
value|0xF201
end_define

begin_comment
comment|/* Association status */
end_comment

begin_comment
comment|/*  * Hermes transmit/receive frame structure  */
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
name|wi_rsvd0
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|wi_rsvd1
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|wi_q_info
decl_stmt|;
comment|/* 0x06 */
name|u_int16_t
name|wi_rsvd2
decl_stmt|;
comment|/* 0x08 */
name|u_int16_t
name|wi_rsvd3
decl_stmt|;
comment|/* 0x0A */
name|u_int16_t
name|wi_tx_ctl
decl_stmt|;
comment|/* 0x0C */
name|u_int16_t
name|wi_frame_ctl
decl_stmt|;
comment|/* 0x0E */
name|u_int16_t
name|wi_id
decl_stmt|;
comment|/* 0x10 */
name|u_int8_t
name|wi_addr1
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x12 */
name|u_int8_t
name|wi_addr2
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x18 */
name|u_int8_t
name|wi_addr3
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x1E */
name|u_int16_t
name|wi_seq_ctl
decl_stmt|;
comment|/* 0x24 */
name|u_int8_t
name|wi_addr4
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x26 */
name|u_int16_t
name|wi_dat_len
decl_stmt|;
comment|/* 0x2C */
name|u_int8_t
name|wi_dst_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x2E */
name|u_int8_t
name|wi_src_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x34 */
name|u_int16_t
name|wi_len
decl_stmt|;
comment|/* 0x3A */
name|u_int16_t
name|wi_dat
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x3C */
comment|/* SNAP header */
name|u_int16_t
name|wi_type
decl_stmt|;
comment|/* 0x42 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_802_3_OFFSET
value|0x2E
end_define

begin_define
define|#
directive|define
name|WI_802_11_OFFSET
value|0x44
end_define

begin_define
define|#
directive|define
name|WI_802_11_OFFSET_RAW
value|0x3C
end_define

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
name|WI_RXSTAT_MSG_TYPE
value|0xE000
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
value|0x11
end_define

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

begin_define
define|#
directive|define
name|WI_TXCNTL_MACPORT
value|0x00FF
end_define

begin_define
define|#
directive|define
name|WI_TXCNTL_STRUCTTYPE
value|0xFF00
end_define

begin_comment
comment|/*  * SNAP (sub-network access protocol) constants for transmission  * of IP datagrams over IEEE 802 networks, taken from RFC1042.  * We need these for the LLC/SNAP header fields in the TX/RX frame  * structure.  */
end_comment

begin_define
define|#
directive|define
name|WI_SNAP_K1
value|0xaa
end_define

begin_comment
comment|/* assigned global SAP for SNAP */
end_comment

begin_define
define|#
directive|define
name|WI_SNAP_K2
value|0x00
end_define

begin_define
define|#
directive|define
name|WI_SNAP_CONTROL
value|0x03
end_define

begin_comment
comment|/* unnumbered information format */
end_comment

begin_define
define|#
directive|define
name|WI_SNAP_WORD0
value|(WI_SNAP_K1 | (WI_SNAP_K1<< 8))
end_define

begin_define
define|#
directive|define
name|WI_SNAP_WORD1
value|(WI_SNAP_K2 | (WI_SNAP_CONTROL<< 8))
end_define

begin_define
define|#
directive|define
name|WI_SNAPHDR_LEN
value|0x6
end_define

end_unit

