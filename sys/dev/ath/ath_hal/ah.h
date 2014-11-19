begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_H_
end_define

begin_comment
comment|/*  * Atheros Hardware Access Layer  *  * Clients of the HAL call ath_hal_attach to obtain a reference to an ath_hal  * structure for use with the device.  Hardware-related operations that  * follow must call back into the HAL through interface, supplying the  * reference as the first parameter.  */
end_comment

begin_include
include|#
directive|include
file|"ah_osdep.h"
end_include

begin_comment
comment|/*  * The maximum number of TX/RX chains supported.  * This is intended to be used by various statistics gathering operations  * (NF, RSSI, EVM).  */
end_comment

begin_define
define|#
directive|define
name|AH_MAX_CHAINS
value|3
end_define

begin_define
define|#
directive|define
name|AH_MIMO_MAX_EVM_PILOTS
value|6
end_define

begin_comment
comment|/*  * __ahdecl is analogous to _cdecl; it defines the calling  * convention used within the HAL.  For most systems this  * can just default to be empty and the compiler will (should)  * use _cdecl.  For systems where _cdecl is not compatible this  * must be defined.  See linux/ah_osdep.h for an example.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ahdecl
end_ifndef

begin_define
define|#
directive|define
name|__ahdecl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Status codes that may be returned by the HAL.  Note that  * interfaces that return a status code set it only when an  * error occurs--i.e. you cannot check it for success.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_OK
init|=
literal|0
block|,
comment|/* No error */
name|HAL_ENXIO
init|=
literal|1
block|,
comment|/* No hardware present */
name|HAL_ENOMEM
init|=
literal|2
block|,
comment|/* Memory allocation failed */
name|HAL_EIO
init|=
literal|3
block|,
comment|/* Hardware didn't respond as expected */
name|HAL_EEMAGIC
init|=
literal|4
block|,
comment|/* EEPROM magic number invalid */
name|HAL_EEVERSION
init|=
literal|5
block|,
comment|/* EEPROM version invalid */
name|HAL_EELOCKED
init|=
literal|6
block|,
comment|/* EEPROM unreadable */
name|HAL_EEBADSUM
init|=
literal|7
block|,
comment|/* EEPROM checksum invalid */
name|HAL_EEREAD
init|=
literal|8
block|,
comment|/* EEPROM read problem */
name|HAL_EEBADMAC
init|=
literal|9
block|,
comment|/* EEPROM mac address invalid */
name|HAL_EESIZE
init|=
literal|10
block|,
comment|/* EEPROM size not supported */
name|HAL_EEWRITE
init|=
literal|11
block|,
comment|/* Attempt to change write-locked EEPROM */
name|HAL_EINVAL
init|=
literal|12
block|,
comment|/* Invalid parameter to function */
name|HAL_ENOTSUPP
init|=
literal|13
block|,
comment|/* Hardware revision not supported */
name|HAL_ESELFTEST
init|=
literal|14
block|,
comment|/* Hardware self-test failed */
name|HAL_EINPROGRESS
init|=
literal|15
block|,
comment|/* Operation incomplete */
name|HAL_EEBADREG
init|=
literal|16
block|,
comment|/* EEPROM invalid regulatory contents */
name|HAL_EEBADCC
init|=
literal|17
block|,
comment|/* EEPROM invalid country code */
name|HAL_INV_PMODE
init|=
literal|18
block|,
comment|/* Couldn't bring out of sleep state */
block|}
name|HAL_STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AH_FALSE
init|=
literal|0
block|,
comment|/* NB: lots of code assumes false is zero */
name|AH_TRUE
init|=
literal|1
block|, }
name|HAL_BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_CAP_REG_DMN
init|=
literal|0
block|,
comment|/* current regulatory domain */
name|HAL_CAP_CIPHER
init|=
literal|1
block|,
comment|/* hardware supports cipher */
name|HAL_CAP_TKIP_MIC
init|=
literal|2
block|,
comment|/* handle TKIP MIC in hardware */
name|HAL_CAP_TKIP_SPLIT
init|=
literal|3
block|,
comment|/* hardware TKIP uses split keys */
name|HAL_CAP_PHYCOUNTERS
init|=
literal|4
block|,
comment|/* hardware PHY error counters */
name|HAL_CAP_DIVERSITY
init|=
literal|5
block|,
comment|/* hardware supports fast diversity */
name|HAL_CAP_KEYCACHE_SIZE
init|=
literal|6
block|,
comment|/* number of entries in key cache */
name|HAL_CAP_NUM_TXQUEUES
init|=
literal|7
block|,
comment|/* number of hardware xmit queues */
name|HAL_CAP_VEOL
init|=
literal|9
block|,
comment|/* hardware supports virtual EOL */
name|HAL_CAP_PSPOLL
init|=
literal|10
block|,
comment|/* hardware has working PS-Poll support */
name|HAL_CAP_DIAG
init|=
literal|11
block|,
comment|/* hardware diagnostic support */
name|HAL_CAP_COMPRESSION
init|=
literal|12
block|,
comment|/* hardware supports compression */
name|HAL_CAP_BURST
init|=
literal|13
block|,
comment|/* hardware supports packet bursting */
name|HAL_CAP_FASTFRAME
init|=
literal|14
block|,
comment|/* hardware supoprts fast frames */
name|HAL_CAP_TXPOW
init|=
literal|15
block|,
comment|/* global tx power limit  */
name|HAL_CAP_TPC
init|=
literal|16
block|,
comment|/* per-packet tx power control  */
name|HAL_CAP_PHYDIAG
init|=
literal|17
block|,
comment|/* hardware phy error diagnostic */
name|HAL_CAP_BSSIDMASK
init|=
literal|18
block|,
comment|/* hardware supports bssid mask */
name|HAL_CAP_MCAST_KEYSRCH
init|=
literal|19
block|,
comment|/* hardware has multicast key search */
name|HAL_CAP_TSF_ADJUST
init|=
literal|20
block|,
comment|/* hardware has beacon tsf adjust */
comment|/* 21 was HAL_CAP_XR */
name|HAL_CAP_WME_TKIPMIC
init|=
literal|22
block|,
comment|/* hardware can support TKIP MIC when WMM is turned on */
comment|/* 23 was HAL_CAP_CHAN_HALFRATE */
comment|/* 24 was HAL_CAP_CHAN_QUARTERRATE */
name|HAL_CAP_RFSILENT
init|=
literal|25
block|,
comment|/* hardware has rfsilent support  */
name|HAL_CAP_TPC_ACK
init|=
literal|26
block|,
comment|/* ack txpower with per-packet tpc */
name|HAL_CAP_TPC_CTS
init|=
literal|27
block|,
comment|/* cts txpower with per-packet tpc */
name|HAL_CAP_11D
init|=
literal|28
block|,
comment|/* 11d beacon support for changing cc */
name|HAL_CAP_PCIE_PS
init|=
literal|29
block|,
name|HAL_CAP_HT
init|=
literal|30
block|,
comment|/* hardware can support HT */
name|HAL_CAP_GTXTO
init|=
literal|31
block|,
comment|/* hardware supports global tx timeout */
name|HAL_CAP_FAST_CC
init|=
literal|32
block|,
comment|/* hardware supports fast channel change */
name|HAL_CAP_TX_CHAINMASK
init|=
literal|33
block|,
comment|/* mask of TX chains supported */
name|HAL_CAP_RX_CHAINMASK
init|=
literal|34
block|,
comment|/* mask of RX chains supported */
name|HAL_CAP_NUM_GPIO_PINS
init|=
literal|36
block|,
comment|/* number of GPIO pins */
name|HAL_CAP_CST
init|=
literal|38
block|,
comment|/* hardware supports carrier sense timeout */
name|HAL_CAP_RIFS_RX
init|=
literal|39
block|,
name|HAL_CAP_RIFS_TX
init|=
literal|40
block|,
name|HAL_CAP_FORCE_PPM
init|=
literal|41
block|,
name|HAL_CAP_RTS_AGGR_LIMIT
init|=
literal|42
block|,
comment|/* aggregation limit with RTS */
name|HAL_CAP_4ADDR_AGGR
init|=
literal|43
block|,
comment|/* hardware is capable of 4addr aggregation */
name|HAL_CAP_DFS_DMN
init|=
literal|44
block|,
comment|/* current DFS domain */
name|HAL_CAP_EXT_CHAN_DFS
init|=
literal|45
block|,
comment|/* DFS support for extension channel */
name|HAL_CAP_COMBINED_RADAR_RSSI
init|=
literal|46
block|,
comment|/* Is combined RSSI for radar accurate */
name|HAL_CAP_AUTO_SLEEP
init|=
literal|48
block|,
comment|/* hardware can go to network sleep 					   automatically after waking up to receive TIM */
name|HAL_CAP_MBSSID_AGGR_SUPPORT
init|=
literal|49
block|,
comment|/* Support for mBSSID Aggregation */
name|HAL_CAP_SPLIT_4KB_TRANS
init|=
literal|50
block|,
comment|/* hardware supports descriptors straddling a 4k page boundary */
name|HAL_CAP_REG_FLAG
init|=
literal|51
block|,
comment|/* Regulatory domain flags */
name|HAL_CAP_BB_RIFS_HANG
init|=
literal|52
block|,
name|HAL_CAP_RIFS_RX_ENABLED
init|=
literal|53
block|,
name|HAL_CAP_BB_DFS_HANG
init|=
literal|54
block|,
name|HAL_CAP_RX_STBC
init|=
literal|58
block|,
name|HAL_CAP_TX_STBC
init|=
literal|59
block|,
name|HAL_CAP_BT_COEX
init|=
literal|60
block|,
comment|/* hardware is capable of bluetooth coexistence */
name|HAL_CAP_DYNAMIC_SMPS
init|=
literal|61
block|,
comment|/* Dynamic MIMO Power Save hardware support */
name|HAL_CAP_DS
init|=
literal|67
block|,
comment|/* 2 stream */
name|HAL_CAP_BB_RX_CLEAR_STUCK_HANG
init|=
literal|68
block|,
name|HAL_CAP_MAC_HANG
init|=
literal|69
block|,
comment|/* can MAC hang */
name|HAL_CAP_MFP
init|=
literal|70
block|,
comment|/* Management Frame Protection in hardware */
name|HAL_CAP_TS
init|=
literal|72
block|,
comment|/* 3 stream */
name|HAL_CAP_ENHANCED_DMA_SUPPORT
init|=
literal|75
block|,
comment|/* DMA FIFO support */
name|HAL_CAP_NUM_TXMAPS
init|=
literal|76
block|,
comment|/* Number of buffers in a transmit descriptor */
name|HAL_CAP_TXDESCLEN
init|=
literal|77
block|,
comment|/* Length of transmit descriptor */
name|HAL_CAP_TXSTATUSLEN
init|=
literal|78
block|,
comment|/* Length of transmit status descriptor */
name|HAL_CAP_RXSTATUSLEN
init|=
literal|79
block|,
comment|/* Length of transmit status descriptor */
name|HAL_CAP_RXFIFODEPTH
init|=
literal|80
block|,
comment|/* Receive hardware FIFO depth */
name|HAL_CAP_RXBUFSIZE
init|=
literal|81
block|,
comment|/* Receive Buffer Length */
name|HAL_CAP_NUM_MR_RETRIES
init|=
literal|82
block|,
comment|/* limit on multirate retries */
name|HAL_CAP_OL_PWRCTRL
init|=
literal|84
block|,
comment|/* Open loop TX power control */
name|HAL_CAP_SPECTRAL_SCAN
init|=
literal|90
block|,
comment|/* Hardware supports spectral scan */
name|HAL_CAP_BB_PANIC_WATCHDOG
init|=
literal|92
block|,
name|HAL_CAP_HT20_SGI
init|=
literal|96
block|,
comment|/* hardware supports HT20 short GI */
name|HAL_CAP_LDPC
init|=
literal|99
block|,
name|HAL_CAP_RXTSTAMP_PREC
init|=
literal|100
block|,
comment|/* rx desc tstamp precision (bits) */
name|HAL_CAP_ANT_DIV_COMB
init|=
literal|105
block|,
comment|/* Enable antenna diversity/combining */
name|HAL_CAP_PHYRESTART_CLR_WAR
init|=
literal|106
block|,
comment|/* in some cases, clear phy restart to fix bb hang */
name|HAL_CAP_ENTERPRISE_MODE
init|=
literal|107
block|,
comment|/* Enterprise mode features */
name|HAL_CAP_LDPCWAR
init|=
literal|108
block|,
name|HAL_CAP_CHANNEL_SWITCH_TIME_USEC
init|=
literal|109
block|,
comment|/* Channel change time, usec */
name|HAL_CAP_ENABLE_APM
init|=
literal|110
block|,
comment|/* APM enabled */
name|HAL_CAP_PCIE_LCR_EXTSYNC_EN
init|=
literal|111
block|,
name|HAL_CAP_PCIE_LCR_OFFSET
init|=
literal|112
block|,
name|HAL_CAP_ENHANCED_DFS_SUPPORT
init|=
literal|117
block|,
comment|/* hardware supports enhanced DFS */
name|HAL_CAP_MCI
init|=
literal|118
block|,
name|HAL_CAP_SMARTANTENNA
init|=
literal|119
block|,
name|HAL_CAP_TRAFFIC_FAST_RECOVER
init|=
literal|120
block|,
name|HAL_CAP_TX_DIVERSITY
init|=
literal|121
block|,
name|HAL_CAP_CRDC
init|=
literal|122
block|,
comment|/* The following are private to the FreeBSD HAL (224 onward) */
name|HAL_CAP_INTMIT
init|=
literal|229
block|,
comment|/* interference mitigation */
name|HAL_CAP_RXORN_FATAL
init|=
literal|230
block|,
comment|/* HAL_INT_RXORN treated as fatal */
name|HAL_CAP_BB_HANG
init|=
literal|235
block|,
comment|/* can baseband hang */
name|HAL_CAP_INTRMASK
init|=
literal|237
block|,
comment|/* bitmask of supported interrupts */
name|HAL_CAP_BSSIDMATCH
init|=
literal|238
block|,
comment|/* hardware has disable bssid match */
name|HAL_CAP_STREAMS
init|=
literal|239
block|,
comment|/* how many 802.11n spatial streams are available */
name|HAL_CAP_RXDESC_SELFLINK
init|=
literal|242
block|,
comment|/* support a self-linked tail RX descriptor */
name|HAL_CAP_LONG_RXDESC_TSF
init|=
literal|243
block|,
comment|/* hardware supports 32bit TSF in RX descriptor */
name|HAL_CAP_BB_READ_WAR
init|=
literal|244
block|,
comment|/* baseband read WAR */
name|HAL_CAP_SERIALISE_WAR
init|=
literal|245
block|,
comment|/* serialise register access on PCI */
name|HAL_CAP_ENFORCE_TXOP
init|=
literal|246
block|,
comment|/* Enforce TXOP if supported */
name|HAL_CAP_RX_LNA_MIXING
init|=
literal|247
block|,
comment|/* RX hardware uses LNA mixing */
name|HAL_CAP_DO_MYBEACON
init|=
literal|248
block|,
comment|/* Supports HAL_RX_FILTER_MYBEACON */
block|}
name|HAL_CAPABILITY_TYPE
typedef|;
end_typedef

begin_comment
comment|/*   * "States" for setting the LED.  These correspond to  * the possible 802.11 operational states and there may  * be a many-to-one mapping between these states and the  * actual hardware state for the LED's (i.e. the hardware  * may have fewer states).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_LED_INIT
init|=
literal|0
block|,
name|HAL_LED_SCAN
init|=
literal|1
block|,
name|HAL_LED_AUTH
init|=
literal|2
block|,
name|HAL_LED_ASSOC
init|=
literal|3
block|,
name|HAL_LED_RUN
init|=
literal|4
block|}
name|HAL_LED_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit queue types/numbers.  These are used to tag  * each transmit queue in the hardware and to identify a set  * of transmit queues for operations such as start/stop dma.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_TX_QUEUE_INACTIVE
init|=
literal|0
block|,
comment|/* queue is inactive/unused */
name|HAL_TX_QUEUE_DATA
init|=
literal|1
block|,
comment|/* data xmit q's */
name|HAL_TX_QUEUE_BEACON
init|=
literal|2
block|,
comment|/* beacon xmit q */
name|HAL_TX_QUEUE_CAB
init|=
literal|3
block|,
comment|/* "crap after beacon" xmit q */
name|HAL_TX_QUEUE_UAPSD
init|=
literal|4
block|,
comment|/* u-apsd power save xmit q */
name|HAL_TX_QUEUE_PSPOLL
init|=
literal|5
block|,
comment|/* power save poll xmit q */
name|HAL_TX_QUEUE_CFEND
init|=
literal|6
block|,
name|HAL_TX_QUEUE_PAPRD
init|=
literal|7
block|, }
name|HAL_TX_QUEUE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_NUM_TX_QUEUES
value|10
end_define

begin_comment
comment|/* max possible # of queues */
end_comment

begin_comment
comment|/*  * Receive queue types.  These are used to tag  * each transmit queue in the hardware and to identify a set  * of transmit queues for operations such as start/stop dma.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_RX_QUEUE_HP
init|=
literal|0
block|,
comment|/* high priority recv queue */
name|HAL_RX_QUEUE_LP
init|=
literal|1
block|,
comment|/* low priority recv queue */
block|}
name|HAL_RX_QUEUE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_NUM_RX_QUEUES
value|2
end_define

begin_comment
comment|/* max possible # of queues */
end_comment

begin_define
define|#
directive|define
name|HAL_TXFIFO_DEPTH
value|8
end_define

begin_comment
comment|/* transmit fifo depth */
end_comment

begin_comment
comment|/*  * Transmit queue subtype.  These map directly to  * WME Access Categories (except for UPSD).  Refer  * to Table 5 of the WME spec.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_WME_AC_BK
init|=
literal|0
block|,
comment|/* background access category */
name|HAL_WME_AC_BE
init|=
literal|1
block|,
comment|/* best effort access category*/
name|HAL_WME_AC_VI
init|=
literal|2
block|,
comment|/* video access category */
name|HAL_WME_AC_VO
init|=
literal|3
block|,
comment|/* voice access category */
name|HAL_WME_UPSD
init|=
literal|4
block|,
comment|/* uplink power save */
block|}
name|HAL_TX_QUEUE_SUBTYPE
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit queue flags that control various  * operational parameters.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* 	 * Per queue interrupt enables.  When set the associated 	 * interrupt may be delivered for packets sent through 	 * the queue.  Without these enabled no interrupts will 	 * be delivered for transmits through the queue. 	 */
name|HAL_TXQ_TXOKINT_ENABLE
init|=
literal|0x0001
block|,
comment|/* enable TXOK interrupt */
name|HAL_TXQ_TXERRINT_ENABLE
init|=
literal|0x0001
block|,
comment|/* enable TXERR interrupt */
name|HAL_TXQ_TXDESCINT_ENABLE
init|=
literal|0x0002
block|,
comment|/* enable TXDESC interrupt */
name|HAL_TXQ_TXEOLINT_ENABLE
init|=
literal|0x0004
block|,
comment|/* enable TXEOL interrupt */
name|HAL_TXQ_TXURNINT_ENABLE
init|=
literal|0x0008
block|,
comment|/* enable TXURN interrupt */
comment|/* 	 * Enable hardware compression for packets sent through 	 * the queue.  The compression buffer must be setup and 	 * packets must have a key entry marked in the tx descriptor. 	 */
name|HAL_TXQ_COMPRESSION_ENABLE
init|=
literal|0x0010
block|,
comment|/* enable h/w compression */
comment|/* 	 * Disable queue when veol is hit or ready time expires. 	 * By default the queue is disabled only on reaching the 	 * physical end of queue (i.e. a null link ptr in the 	 * descriptor chain). 	 */
name|HAL_TXQ_RDYTIME_EXP_POLICY_ENABLE
init|=
literal|0x0020
block|,
comment|/* 	 * Schedule frames on delivery of a DBA (DMA Beacon Alert) 	 * event.  Frames will be transmitted only when this timer 	 * fires, e.g to transmit a beacon in ap or adhoc modes. 	 */
name|HAL_TXQ_DBA_GATED
init|=
literal|0x0040
block|,
comment|/* schedule based on DBA */
comment|/* 	 * Each transmit queue has a counter that is incremented 	 * each time the queue is enabled and decremented when 	 * the list of frames to transmit is traversed (or when 	 * the ready time for the queue expires).  This counter 	 * must be non-zero for frames to be scheduled for 	 * transmission.  The following controls disable bumping 	 * this counter under certain conditions.  Typically this 	 * is used to gate frames based on the contents of another 	 * queue (e.g. CAB traffic may only follow a beacon frame). 	 * These are meaningful only when frames are scheduled 	 * with a non-ASAP policy (e.g. DBA-gated). 	 */
name|HAL_TXQ_CBR_DIS_QEMPTY
init|=
literal|0x0080
block|,
comment|/* disable on this q empty */
name|HAL_TXQ_CBR_DIS_BEMPTY
init|=
literal|0x0100
block|,
comment|/* disable on beacon q empty */
comment|/* 	 * Fragment burst backoff policy.  Normally the no backoff 	 * is done after a successful transmission, the next fragment 	 * is sent at SIFS.  If this flag is set backoff is done 	 * after each fragment, regardless whether it was ack'd or 	 * not, after the backoff count reaches zero a normal channel 	 * access procedure is done before the next transmit (i.e. 	 * wait AIFS instead of SIFS). 	 */
name|HAL_TXQ_FRAG_BURST_BACKOFF_ENABLE
init|=
literal|0x00800000
block|,
comment|/* 	 * Disable post-tx backoff following each frame. 	 */
name|HAL_TXQ_BACKOFF_DISABLE
init|=
literal|0x00010000
block|,
comment|/* disable post backoff  */
comment|/* 	 * DCU arbiter lockout control.  This controls how 	 * lower priority tx queues are handled with respect to 	 * to a specific queue when multiple queues have frames 	 * to send.  No lockout means lower priority queues arbitrate 	 * concurrently with this queue.  Intra-frame lockout 	 * means lower priority queues are locked out until the 	 * current frame transmits (e.g. including backoffs and bursting). 	 * Global lockout means nothing lower can arbitrary so 	 * long as there is traffic activity on this queue (frames, 	 * backoff, etc). 	 */
name|HAL_TXQ_ARB_LOCKOUT_INTRA
init|=
literal|0x00020000
block|,
comment|/* intra-frame lockout */
name|HAL_TXQ_ARB_LOCKOUT_GLOBAL
init|=
literal|0x00040000
block|,
comment|/* full lockout s */
name|HAL_TXQ_IGNORE_VIRTCOL
init|=
literal|0x00080000
block|,
comment|/* ignore virt collisions */
name|HAL_TXQ_SEQNUM_INC_DIS
init|=
literal|0x00100000
block|,
comment|/* disable seqnum increment */
block|}
name|HAL_TX_QUEUE_FLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|tqi_ver
decl_stmt|;
comment|/* hal TXQ version */
name|HAL_TX_QUEUE_SUBTYPE
name|tqi_subtype
decl_stmt|;
comment|/* subtype if applicable */
name|HAL_TX_QUEUE_FLAGS
name|tqi_qflags
decl_stmt|;
comment|/* flags (see above) */
name|uint32_t
name|tqi_priority
decl_stmt|;
comment|/* (not used) */
name|uint32_t
name|tqi_aifs
decl_stmt|;
comment|/* aifs */
name|uint32_t
name|tqi_cwmin
decl_stmt|;
comment|/* cwMin */
name|uint32_t
name|tqi_cwmax
decl_stmt|;
comment|/* cwMax */
name|uint16_t
name|tqi_shretry
decl_stmt|;
comment|/* rts retry limit */
name|uint16_t
name|tqi_lgretry
decl_stmt|;
comment|/* long retry limit (not used)*/
name|uint32_t
name|tqi_cbrPeriod
decl_stmt|;
comment|/* CBR period (us) */
name|uint32_t
name|tqi_cbrOverflowLimit
decl_stmt|;
comment|/* threshold for CBROVF int */
name|uint32_t
name|tqi_burstTime
decl_stmt|;
comment|/* max burst duration (us) */
name|uint32_t
name|tqi_readyTime
decl_stmt|;
comment|/* frame schedule time (us) */
name|uint32_t
name|tqi_compBuf
decl_stmt|;
comment|/* comp buffer phys addr */
block|}
name|HAL_TXQ_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_TQI_NONVAL
value|0xffff
end_define

begin_comment
comment|/* token to use for aifs, cwmin, cwmax */
end_comment

begin_define
define|#
directive|define
name|HAL_TXQ_USEDEFAULT
value|((uint32_t) -1)
end_define

begin_comment
comment|/* compression definitions */
end_comment

begin_define
define|#
directive|define
name|HAL_COMP_BUF_MAX_SIZE
value|9216
end_define

begin_comment
comment|/* 9K */
end_comment

begin_define
define|#
directive|define
name|HAL_COMP_BUF_ALIGN_SIZE
value|512
end_define

begin_comment
comment|/*  * Transmit packet types.  This belongs in ah_desc.h, but  * is here so we can give a proper type to various parameters  * (and not require everyone include the file).  *  * NB: These values are intentionally assigned for  *     direct use when setting up h/w descriptors.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_PKT_TYPE_NORMAL
init|=
literal|0
block|,
name|HAL_PKT_TYPE_ATIM
init|=
literal|1
block|,
name|HAL_PKT_TYPE_PSPOLL
init|=
literal|2
block|,
name|HAL_PKT_TYPE_BEACON
init|=
literal|3
block|,
name|HAL_PKT_TYPE_PROBE_RESP
init|=
literal|4
block|,
name|HAL_PKT_TYPE_CHIRP
init|=
literal|5
block|,
name|HAL_PKT_TYPE_GRP_POLL
init|=
literal|6
block|,
name|HAL_PKT_TYPE_AMPDU
init|=
literal|7
block|, }
name|HAL_PKT_TYPE
typedef|;
end_typedef

begin_comment
comment|/* Rx Filter Frame Types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* 	 * These bits correspond to AR_RX_FILTER for all chips. 	 * Not all bits are supported by all chips. 	 */
name|HAL_RX_FILTER_UCAST
init|=
literal|0x00000001
block|,
comment|/* Allow unicast frames */
name|HAL_RX_FILTER_MCAST
init|=
literal|0x00000002
block|,
comment|/* Allow multicast frames */
name|HAL_RX_FILTER_BCAST
init|=
literal|0x00000004
block|,
comment|/* Allow broadcast frames */
name|HAL_RX_FILTER_CONTROL
init|=
literal|0x00000008
block|,
comment|/* Allow control frames */
name|HAL_RX_FILTER_BEACON
init|=
literal|0x00000010
block|,
comment|/* Allow beacon frames */
name|HAL_RX_FILTER_PROM
init|=
literal|0x00000020
block|,
comment|/* Promiscuous mode */
name|HAL_RX_FILTER_PROBEREQ
init|=
literal|0x00000080
block|,
comment|/* Allow probe request frames */
name|HAL_RX_FILTER_PHYERR
init|=
literal|0x00000100
block|,
comment|/* Allow phy errors */
name|HAL_RX_FILTER_MYBEACON
init|=
literal|0x00000200
block|,
comment|/* Filter beacons other than mine */
name|HAL_RX_FILTER_COMPBAR
init|=
literal|0x00000400
block|,
comment|/* Allow compressed BAR */
name|HAL_RX_FILTER_COMP_BA
init|=
literal|0x00000800
block|,
comment|/* Allow compressed blockack */
name|HAL_RX_FILTER_PHYRADAR
init|=
literal|0x00002000
block|,
comment|/* Allow phy radar errors */
name|HAL_RX_FILTER_PSPOLL
init|=
literal|0x00004000
block|,
comment|/* Allow PS-POLL frames */
name|HAL_RX_FILTER_MCAST_BCAST_ALL
init|=
literal|0x00008000
block|,
comment|/* Allow all mcast/bcast frames */
comment|/* 	 * Magic RX filter flags that aren't targetting hardware bits 	 * but instead the HAL sets individual bits - eg PHYERR will result 	 * in OFDM/CCK timing error frames being received. 	 */
name|HAL_RX_FILTER_BSSID
init|=
literal|0x40000000
block|,
comment|/* Disable BSSID match */
block|}
name|HAL_RX_FILTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_PM_AWAKE
init|=
literal|0
block|,
name|HAL_PM_FULL_SLEEP
init|=
literal|1
block|,
name|HAL_PM_NETWORK_SLEEP
init|=
literal|2
block|,
name|HAL_PM_UNDEFINED
init|=
literal|3
block|}
name|HAL_POWER_MODE
typedef|;
end_typedef

begin_comment
comment|/*  * Enterprise mode flags  */
end_comment

begin_define
define|#
directive|define
name|AH_ENT_DUAL_BAND_DISABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AH_ENT_CHAIN2_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AH_ENT_5MHZ_DISABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AH_ENT_10MHZ_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AH_ENT_49GHZ_DISABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AH_ENT_LOOPBACK_DISABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AH_ENT_TPC_PERF_DISABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AH_ENT_MIN_PKT_SIZE_DISABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AH_ENT_SPECTRAL_PRECISION
value|0x00000300
end_define

begin_define
define|#
directive|define
name|AH_ENT_SPECTRAL_PRECISION_S
value|8
end_define

begin_define
define|#
directive|define
name|AH_ENT_RTSCTS_DELIM_WAR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AH_FIRST_DESC_NDELIMS
value|60
end_define

begin_comment
comment|/*  * NOTE WELL:  * These are mapped to take advantage of the common locations for many of  * the bits on all of the currently supported MAC chips. This is to make  * the ISR as efficient as possible, while still abstracting HW differences.  * When new hardware breaks this commonality this enumerated type, as well  * as the HAL functions using it, must be modified. All values are directly  * mapped unless commented otherwise.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_INT_RX
init|=
literal|0x00000001
block|,
comment|/* Non-common mapping */
name|HAL_INT_RXDESC
init|=
literal|0x00000002
block|,
comment|/* Legacy mapping */
name|HAL_INT_RXERR
init|=
literal|0x00000004
block|,
name|HAL_INT_RXHP
init|=
literal|0x00000001
block|,
comment|/* EDMA */
name|HAL_INT_RXLP
init|=
literal|0x00000002
block|,
comment|/* EDMA */
name|HAL_INT_RXNOFRM
init|=
literal|0x00000008
block|,
name|HAL_INT_RXEOL
init|=
literal|0x00000010
block|,
name|HAL_INT_RXORN
init|=
literal|0x00000020
block|,
name|HAL_INT_TX
init|=
literal|0x00000040
block|,
comment|/* Non-common mapping */
name|HAL_INT_TXDESC
init|=
literal|0x00000080
block|,
name|HAL_INT_TIM_TIMER
init|=
literal|0x00000100
block|,
name|HAL_INT_MCI
init|=
literal|0x00000200
block|,
name|HAL_INT_BBPANIC
init|=
literal|0x00000400
block|,
name|HAL_INT_TXURN
init|=
literal|0x00000800
block|,
name|HAL_INT_MIB
init|=
literal|0x00001000
block|,
name|HAL_INT_RXPHY
init|=
literal|0x00004000
block|,
name|HAL_INT_RXKCM
init|=
literal|0x00008000
block|,
name|HAL_INT_SWBA
init|=
literal|0x00010000
block|,
name|HAL_INT_BRSSI
init|=
literal|0x00020000
block|,
name|HAL_INT_BMISS
init|=
literal|0x00040000
block|,
name|HAL_INT_BNR
init|=
literal|0x00100000
block|,
name|HAL_INT_TIM
init|=
literal|0x00200000
block|,
comment|/* Non-common mapping */
name|HAL_INT_DTIM
init|=
literal|0x00400000
block|,
comment|/* Non-common mapping */
name|HAL_INT_DTIMSYNC
init|=
literal|0x00800000
block|,
comment|/* Non-common mapping */
name|HAL_INT_GPIO
init|=
literal|0x01000000
block|,
name|HAL_INT_CABEND
init|=
literal|0x02000000
block|,
comment|/* Non-common mapping */
name|HAL_INT_TSFOOR
init|=
literal|0x04000000
block|,
comment|/* Non-common mapping */
name|HAL_INT_TBTT
init|=
literal|0x08000000
block|,
comment|/* Non-common mapping */
comment|/* Atheros ref driver has a generic timer interrupt now..*/
name|HAL_INT_GENTIMER
init|=
literal|0x08000000
block|,
comment|/* Non-common mapping */
name|HAL_INT_CST
init|=
literal|0x10000000
block|,
comment|/* Non-common mapping */
name|HAL_INT_GTT
init|=
literal|0x20000000
block|,
comment|/* Non-common mapping */
name|HAL_INT_FATAL
init|=
literal|0x40000000
block|,
comment|/* Non-common mapping */
define|#
directive|define
name|HAL_INT_GLOBAL
value|0x80000000
comment|/* Set/clear IER */
name|HAL_INT_BMISC
init|=
name|HAL_INT_TIM
operator||
name|HAL_INT_DTIM
operator||
name|HAL_INT_DTIMSYNC
operator||
name|HAL_INT_CABEND
operator||
name|HAL_INT_TBTT
block|,
comment|/* Interrupt bits that map directly to ISR/IMR bits */
name|HAL_INT_COMMON
init|=
name|HAL_INT_RXNOFRM
operator||
name|HAL_INT_RXDESC
operator||
name|HAL_INT_RXEOL
operator||
name|HAL_INT_RXORN
operator||
name|HAL_INT_TXDESC
operator||
name|HAL_INT_TXURN
operator||
name|HAL_INT_MIB
operator||
name|HAL_INT_RXPHY
operator||
name|HAL_INT_RXKCM
operator||
name|HAL_INT_SWBA
operator||
name|HAL_INT_BMISS
operator||
name|HAL_INT_BRSSI
operator||
name|HAL_INT_BNR
operator||
name|HAL_INT_GPIO
block|, }
name|HAL_INT
typedef|;
end_typedef

begin_comment
comment|/*  * MSI vector assignments  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_MSIVEC_MISC
init|=
literal|0
block|,
name|HAL_MSIVEC_TX
init|=
literal|1
block|,
name|HAL_MSIVEC_RXLP
init|=
literal|2
block|,
name|HAL_MSIVEC_RXHP
init|=
literal|3
block|, }
name|HAL_MSIVEC
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_INT_LINE
init|=
literal|0
block|,
name|HAL_INT_MSI
init|=
literal|1
block|, }
name|HAL_INT_TYPE
typedef|;
end_typedef

begin_comment
comment|/* For interrupt mitigation registers */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_INT_RX_FIRSTPKT
init|=
literal|0
block|,
name|HAL_INT_RX_LASTPKT
block|,
name|HAL_INT_TX_FIRSTPKT
block|,
name|HAL_INT_TX_LASTPKT
block|,
name|HAL_INT_THRESHOLD
block|}
name|HAL_INT_MITIGATION
typedef|;
end_typedef

begin_comment
comment|/* XXX this is duplicate information! */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|cyclecnt_diff
decl_stmt|;
comment|/* delta cycle count */
name|u_int32_t
name|rxclr_cnt
decl_stmt|;
comment|/* rx clear count */
name|u_int32_t
name|txframecnt_diff
decl_stmt|;
comment|/* delta tx frame count */
name|u_int32_t
name|rxframecnt_diff
decl_stmt|;
comment|/* delta rx frame count */
name|u_int32_t
name|listen_time
decl_stmt|;
comment|/* listen time in msec - time for which ch is free */
name|u_int32_t
name|ofdmphyerr_cnt
decl_stmt|;
comment|/* OFDM err count since last reset */
name|u_int32_t
name|cckphyerr_cnt
decl_stmt|;
comment|/* CCK err count since last reset */
name|u_int32_t
name|ofdmphyerrcnt_diff
decl_stmt|;
comment|/* delta OFDM Phy Error Count */
name|HAL_BOOL
name|valid
decl_stmt|;
comment|/* if the stats are valid*/
block|}
name|HAL_ANISTATS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|txctl_offset
decl_stmt|;
name|u_int8_t
name|txctl_numwords
decl_stmt|;
name|u_int8_t
name|txstatus_offset
decl_stmt|;
name|u_int8_t
name|txstatus_numwords
decl_stmt|;
name|u_int8_t
name|rxctl_offset
decl_stmt|;
name|u_int8_t
name|rxctl_numwords
decl_stmt|;
name|u_int8_t
name|rxstatus_offset
decl_stmt|;
name|u_int8_t
name|rxstatus_numwords
decl_stmt|;
name|u_int8_t
name|macRevision
decl_stmt|;
block|}
name|HAL_DESC_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_GPIO_OUTPUT_MUX_AS_OUTPUT
init|=
literal|0
block|,
name|HAL_GPIO_OUTPUT_MUX_PCIE_ATTENTION_LED
init|=
literal|1
block|,
name|HAL_GPIO_OUTPUT_MUX_PCIE_POWER_LED
init|=
literal|2
block|,
name|HAL_GPIO_OUTPUT_MUX_MAC_NETWORK_LED
init|=
literal|3
block|,
name|HAL_GPIO_OUTPUT_MUX_MAC_POWER_LED
init|=
literal|4
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_WLAN_ACTIVE
init|=
literal|5
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_TX_FRAME
init|=
literal|6
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_MCI_WLAN_DATA
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_MCI_WLAN_CLK
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_MCI_BT_DATA
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_MCI_BT_CLK
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_WL_IN_TX
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_WL_IN_RX
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_BT_IN_TX
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_BT_IN_RX
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_RUCKUS_STROBE
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_RUCKUS_DATA
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_SMARTANT_CTRL0
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_SMARTANT_CTRL1
block|,
name|HAL_GPIO_OUTPUT_MUX_AS_SMARTANT_CTRL2
block|,
name|HAL_GPIO_OUTPUT_MUX_NUM_ENTRIES
block|}
name|HAL_GPIO_MUX_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_GPIO_INTR_LOW
init|=
literal|0
block|,
name|HAL_GPIO_INTR_HIGH
init|=
literal|1
block|,
name|HAL_GPIO_INTR_DISABLE
init|=
literal|2
block|}
name|HAL_GPIO_INTR_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|halCounters
block|{
name|u_int32_t
name|tx_frame_count
decl_stmt|;
name|u_int32_t
name|rx_frame_count
decl_stmt|;
name|u_int32_t
name|rx_clear_count
decl_stmt|;
name|u_int32_t
name|cycle_count
decl_stmt|;
name|u_int8_t
name|is_rx_active
decl_stmt|;
comment|// true (1) or false (0)
name|u_int8_t
name|is_tx_active
decl_stmt|;
comment|// true (1) or false (0)
block|}
name|HAL_COUNTERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_RFGAIN_INACTIVE
init|=
literal|0
block|,
name|HAL_RFGAIN_READ_REQUESTED
init|=
literal|1
block|,
name|HAL_RFGAIN_NEED_CHANGE
init|=
literal|2
block|}
name|HAL_RFGAIN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|HAL_CTRY_CODE
typedef|;
end_typedef

begin_comment
comment|/* country code */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|HAL_REG_DOMAIN
typedef|;
end_typedef

begin_comment
comment|/* regulatory domain code */
end_comment

begin_define
define|#
directive|define
name|HAL_ANTENNA_MIN_MODE
value|0
end_define

begin_define
define|#
directive|define
name|HAL_ANTENNA_FIXED_A
value|1
end_define

begin_define
define|#
directive|define
name|HAL_ANTENNA_FIXED_B
value|2
end_define

begin_define
define|#
directive|define
name|HAL_ANTENNA_MAX_MODE
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|ackrcv_bad
decl_stmt|;
name|uint32_t
name|rts_bad
decl_stmt|;
name|uint32_t
name|rts_good
decl_stmt|;
name|uint32_t
name|fcs_bad
decl_stmt|;
name|uint32_t
name|beacons
decl_stmt|;
block|}
name|HAL_MIB_STATS
typedef|;
end_typedef

begin_comment
comment|/*  * These bits represent what's in ah_currentRDext.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|REG_EXT_FCC_MIDBAND
init|=
literal|0
block|,
name|REG_EXT_JAPAN_MIDBAND
init|=
literal|1
block|,
name|REG_EXT_FCC_DFS_HT40
init|=
literal|2
block|,
name|REG_EXT_JAPAN_NONDFS_HT40
init|=
literal|3
block|,
name|REG_EXT_JAPAN_DFS_HT40
init|=
literal|4
block|}
name|REG_EXT_BITMAP
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|HAL_MODE_11A
init|=
literal|0x001
block|,
comment|/* 11a channels */
name|HAL_MODE_TURBO
init|=
literal|0x002
block|,
comment|/* 11a turbo-only channels */
name|HAL_MODE_11B
init|=
literal|0x004
block|,
comment|/* 11b channels */
name|HAL_MODE_PUREG
init|=
literal|0x008
block|,
comment|/* 11g channels (OFDM only) */
ifdef|#
directive|ifdef
name|notdef
name|HAL_MODE_11G
init|=
literal|0x010
block|,
comment|/* 11g channels (OFDM/CCK) */
else|#
directive|else
name|HAL_MODE_11G
init|=
literal|0x008
block|,
comment|/* XXX historical */
endif|#
directive|endif
name|HAL_MODE_108G
init|=
literal|0x020
block|,
comment|/* 11g+Turbo channels */
name|HAL_MODE_108A
init|=
literal|0x040
block|,
comment|/* 11a+Turbo channels */
name|HAL_MODE_11A_HALF_RATE
init|=
literal|0x200
block|,
comment|/* 11a half width channels */
name|HAL_MODE_11A_QUARTER_RATE
init|=
literal|0x400
block|,
comment|/* 11a quarter width channels */
name|HAL_MODE_11G_HALF_RATE
init|=
literal|0x800
block|,
comment|/* 11g half width channels */
name|HAL_MODE_11G_QUARTER_RATE
init|=
literal|0x1000
block|,
comment|/* 11g quarter width channels */
name|HAL_MODE_11NG_HT20
init|=
literal|0x008000
block|,
name|HAL_MODE_11NA_HT20
init|=
literal|0x010000
block|,
name|HAL_MODE_11NG_HT40PLUS
init|=
literal|0x020000
block|,
name|HAL_MODE_11NG_HT40MINUS
init|=
literal|0x040000
block|,
name|HAL_MODE_11NA_HT40PLUS
init|=
literal|0x080000
block|,
name|HAL_MODE_11NA_HT40MINUS
init|=
literal|0x100000
block|,
name|HAL_MODE_ALL
init|=
literal|0xffffff
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rateCount
decl_stmt|;
comment|/* NB: for proper padding */
name|uint8_t
name|rateCodeToIndex
index|[
literal|256
index|]
decl_stmt|;
comment|/* back mapping */
struct|struct
block|{
name|uint8_t
name|valid
decl_stmt|;
comment|/* valid for rate control use */
name|uint8_t
name|phy
decl_stmt|;
comment|/* CCK/OFDM/XR */
name|uint32_t
name|rateKbps
decl_stmt|;
comment|/* transfer rate in kbs */
name|uint8_t
name|rateCode
decl_stmt|;
comment|/* rate for h/w descriptors */
name|uint8_t
name|shortPreamble
decl_stmt|;
comment|/* mask for enabling short 						 * preamble in CCK rate code */
name|uint8_t
name|dot11Rate
decl_stmt|;
comment|/* value for supported rates 						 * info element of MLME */
name|uint8_t
name|controlRate
decl_stmt|;
comment|/* index of next lower basic 						 * rate; used for dur. calcs */
name|uint16_t
name|lpAckDuration
decl_stmt|;
comment|/* long preamble ACK duration */
name|uint16_t
name|spAckDuration
decl_stmt|;
comment|/* short preamble ACK duration*/
block|}
name|info
index|[
literal|64
index|]
struct|;
block|}
name|HAL_RATE_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|rs_count
decl_stmt|;
comment|/* number of valid entries */
name|uint8_t
name|rs_rates
index|[
literal|64
index|]
decl_stmt|;
comment|/* rates */
block|}
name|HAL_RATE_SET
typedef|;
end_typedef

begin_comment
comment|/*  * 802.11n specific structures and enums  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_CHAINTYPE_TX
init|=
literal|1
block|,
comment|/* Tx chain type */
name|HAL_CHAINTYPE_RX
init|=
literal|2
block|,
comment|/* RX chain type */
block|}
name|HAL_CHAIN_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|Tries
decl_stmt|;
name|u_int
name|Rate
decl_stmt|;
comment|/* hardware rate code */
name|u_int
name|RateIndex
decl_stmt|;
comment|/* rate series table index */
name|u_int
name|PktDuration
decl_stmt|;
name|u_int
name|ChSel
decl_stmt|;
name|u_int
name|RateFlags
decl_stmt|;
define|#
directive|define
name|HAL_RATESERIES_RTS_CTS
value|0x0001
comment|/* use rts/cts w/this series */
define|#
directive|define
name|HAL_RATESERIES_2040
value|0x0002
comment|/* use ext channel for series */
define|#
directive|define
name|HAL_RATESERIES_HALFGI
value|0x0004
comment|/* use half-gi for series */
define|#
directive|define
name|HAL_RATESERIES_STBC
value|0x0008
comment|/* use STBC for series */
name|u_int
name|tx_power_cap
decl_stmt|;
comment|/* in 1/2 dBm units XXX TODO */
block|}
name|HAL_11N_RATE_SERIES
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_HT_MACMODE_20
init|=
literal|0
block|,
comment|/* 20 MHz operation */
name|HAL_HT_MACMODE_2040
init|=
literal|1
block|,
comment|/* 20/40 MHz operation */
block|}
name|HAL_HT_MACMODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_HT_PHYMODE_20
init|=
literal|0
block|,
comment|/* 20 MHz operation */
name|HAL_HT_PHYMODE_2040
init|=
literal|1
block|,
comment|/* 20/40 MHz operation */
block|}
name|HAL_HT_PHYMODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_HT_EXTPROTSPACING_20
init|=
literal|0
block|,
comment|/* 20 MHz spacing */
name|HAL_HT_EXTPROTSPACING_25
init|=
literal|1
block|,
comment|/* 25 MHz spacing */
block|}
name|HAL_HT_EXTPROTSPACING
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_RX_CLEAR_CTL_LOW
init|=
literal|0x1
block|,
comment|/* force control channel to appear busy */
name|HAL_RX_CLEAR_EXT_LOW
init|=
literal|0x2
block|,
comment|/* force extension channel to appear busy */
block|}
name|HAL_HT_RXCLEAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_FREQ_BAND_5GHZ
init|=
literal|0
block|,
name|HAL_FREQ_BAND_2GHZ
init|=
literal|1
block|, }
name|HAL_FREQ_BAND
typedef|;
end_typedef

begin_comment
comment|/*  * Antenna switch control.  By default antenna selection  * enables multiple (2) antenna use.  To force use of the  * A or B antenna only specify a fixed setting.  Fixing  * the antenna will also disable any diversity support.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_ANT_VARIABLE
init|=
literal|0
block|,
comment|/* variable by programming */
name|HAL_ANT_FIXED_A
init|=
literal|1
block|,
comment|/* fixed antenna A */
name|HAL_ANT_FIXED_B
init|=
literal|2
block|,
comment|/* fixed antenna B */
block|}
name|HAL_ANT_SETTING
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_M_STA
init|=
literal|1
block|,
comment|/* infrastructure station */
name|HAL_M_IBSS
init|=
literal|0
block|,
comment|/* IBSS (adhoc) station */
name|HAL_M_HOSTAP
init|=
literal|6
block|,
comment|/* Software Access Point */
name|HAL_M_MONITOR
init|=
literal|8
comment|/* Monitor mode */
block|}
name|HAL_OPMODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|kv_type
decl_stmt|;
comment|/* one of HAL_CIPHER */
name|uint8_t
name|kv_apsd
decl_stmt|;
comment|/* Mask for APSD enabled ACs */
name|uint16_t
name|kv_len
decl_stmt|;
comment|/* length in bits */
name|uint8_t
name|kv_val
index|[
literal|16
index|]
decl_stmt|;
comment|/* enough for 128-bit keys */
name|uint8_t
name|kv_mic
index|[
literal|8
index|]
decl_stmt|;
comment|/* TKIP MIC key */
name|uint8_t
name|kv_txmic
index|[
literal|8
index|]
decl_stmt|;
comment|/* TKIP TX MIC key (optional) */
block|}
name|HAL_KEYVAL
typedef|;
end_typedef

begin_comment
comment|/*  * This is the TX descriptor field which marks the key padding requirement.  * The naming is unfortunately unclear.  */
end_comment

begin_define
define|#
directive|define
name|AH_KEYTYPE_MASK
value|0x0F
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_KEY_TYPE_CLEAR
block|,
name|HAL_KEY_TYPE_WEP
block|,
name|HAL_KEY_TYPE_AES
block|,
name|HAL_KEY_TYPE_TKIP
block|, }
name|HAL_KEY_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_CIPHER_WEP
init|=
literal|0
block|,
name|HAL_CIPHER_AES_OCB
init|=
literal|1
block|,
name|HAL_CIPHER_AES_CCM
init|=
literal|2
block|,
name|HAL_CIPHER_CKIP
init|=
literal|3
block|,
name|HAL_CIPHER_TKIP
init|=
literal|4
block|,
name|HAL_CIPHER_CLR
init|=
literal|5
block|,
comment|/* no encryption */
name|HAL_CIPHER_MIC
init|=
literal|127
comment|/* TKIP-MIC, not a cipher */
block|}
name|HAL_CIPHER
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|HAL_SLOT_TIME_6
init|=
literal|6
block|,
comment|/* NB: for turbo mode */
name|HAL_SLOT_TIME_9
init|=
literal|9
block|,
name|HAL_SLOT_TIME_20
init|=
literal|20
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Per-station beacon timer state.  Note that the specified  * beacon interval (given in TU's) can also include flags  * to force a TSF reset and to enable the beacon xmit logic.  * If bs_cfpmaxduration is non-zero the hardware is setup to  * coexist with a PCF-capable AP.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|bs_nexttbtt
decl_stmt|;
comment|/* next beacon in TU */
name|uint32_t
name|bs_nextdtim
decl_stmt|;
comment|/* next DTIM in TU */
name|uint32_t
name|bs_intval
decl_stmt|;
comment|/* beacon interval+flags */
comment|/*  * HAL_BEACON_PERIOD, HAL_BEACON_ENA and HAL_BEACON_RESET_TSF  * are all 1:1 correspondances with the pre-11n chip AR_BEACON  * register.  */
define|#
directive|define
name|HAL_BEACON_PERIOD
value|0x0000ffff
comment|/* beacon interval period */
define|#
directive|define
name|HAL_BEACON_PERIOD_TU8
value|0x0007ffff
comment|/* beacon interval, tu/8 */
define|#
directive|define
name|HAL_BEACON_ENA
value|0x00800000
comment|/* beacon xmit enable */
define|#
directive|define
name|HAL_BEACON_RESET_TSF
value|0x01000000
comment|/* clear TSF */
define|#
directive|define
name|HAL_TSFOOR_THRESHOLD
value|0x00004240
comment|/* TSF OOR thresh (16k uS) */
name|uint32_t
name|bs_dtimperiod
decl_stmt|;
name|uint16_t
name|bs_cfpperiod
decl_stmt|;
comment|/* CFP period in TU */
name|uint16_t
name|bs_cfpmaxduration
decl_stmt|;
comment|/* max CFP duration in TU */
name|uint32_t
name|bs_cfpnext
decl_stmt|;
comment|/* next CFP in TU */
name|uint16_t
name|bs_timoffset
decl_stmt|;
comment|/* byte offset to TIM bitmap */
name|uint16_t
name|bs_bmissthreshold
decl_stmt|;
comment|/* beacon miss threshold */
name|uint32_t
name|bs_sleepduration
decl_stmt|;
comment|/* max sleep duration */
name|uint32_t
name|bs_tsfoor_threshold
decl_stmt|;
comment|/* TSF out of range threshold */
block|}
name|HAL_BEACON_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Like HAL_BEACON_STATE but for non-station mode setup.  * NB: see above flag definitions for bt_intval.   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|bt_intval
decl_stmt|;
comment|/* beacon interval+flags */
name|uint32_t
name|bt_nexttbtt
decl_stmt|;
comment|/* next beacon in TU */
name|uint32_t
name|bt_nextatim
decl_stmt|;
comment|/* next ATIM in TU */
name|uint32_t
name|bt_nextdba
decl_stmt|;
comment|/* next DBA in 1/8th TU */
name|uint32_t
name|bt_nextswba
decl_stmt|;
comment|/* next SWBA in 1/8th TU */
name|uint32_t
name|bt_flags
decl_stmt|;
comment|/* timer enables */
define|#
directive|define
name|HAL_BEACON_TBTT_EN
value|0x00000001
define|#
directive|define
name|HAL_BEACON_DBA_EN
value|0x00000002
define|#
directive|define
name|HAL_BEACON_SWBA_EN
value|0x00000004
block|}
name|HAL_BEACON_TIMERS
typedef|;
end_typedef

begin_comment
comment|/*  * Per-node statistics maintained by the driver for use in  * optimizing signal quality and other operational aspects.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|ns_avgbrssi
decl_stmt|;
comment|/* average beacon rssi */
name|uint32_t
name|ns_avgrssi
decl_stmt|;
comment|/* average data rssi */
name|uint32_t
name|ns_avgtxrssi
decl_stmt|;
comment|/* average tx rssi */
block|}
name|HAL_NODE_STATS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_RSSI_EP_MULTIPLIER
value|(1<<7)
end_define

begin_comment
comment|/* pow2 to optimize out * and / */
end_comment

begin_struct_decl
struct_decl|struct
name|ath_desc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_tx_status
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_rx_status
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_channel
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * This is a channel survey sample entry.  *  * The AR5212 ANI routines fill these samples. The ANI code then uses it  * when calculating listen time; it is also exported via a diagnostic  * API.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|seq_num
decl_stmt|;
name|uint32_t
name|tx_busy
decl_stmt|;
name|uint32_t
name|rx_busy
decl_stmt|;
name|uint32_t
name|chan_busy
decl_stmt|;
name|uint32_t
name|ext_chan_busy
decl_stmt|;
name|uint32_t
name|cycle_count
decl_stmt|;
comment|/* XXX TODO */
name|uint32_t
name|ofdm_phyerr_count
decl_stmt|;
name|uint32_t
name|cck_phyerr_count
decl_stmt|;
block|}
name|HAL_SURVEY_SAMPLE
typedef|;
end_typedef

begin_comment
comment|/*  * This provides 3.2 seconds of sample space given an  * ANI time of 1/10th of a second. This may not be enough!  */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_SURVEY_SAMPLE_COUNT
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|HAL_SURVEY_SAMPLE
name|samples
index|[
name|CHANNEL_SURVEY_SAMPLE_COUNT
index|]
decl_stmt|;
name|uint32_t
name|cur_sample
decl_stmt|;
comment|/* current sample in sequence */
name|uint32_t
name|cur_seq
decl_stmt|;
comment|/* current sequence number */
block|}
name|HAL_CHANNEL_SURVEY
typedef|;
end_typedef

begin_comment
comment|/*  * ANI commands.  *  * These are used both internally and externally via the diagnostic  * API.  *  * Note that this is NOT the ANI commands being used via the INTMIT  * capability - that has a different mapping for some reason.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_ANI_PRESENT
init|=
literal|0
block|,
comment|/* is ANI support present */
name|HAL_ANI_NOISE_IMMUNITY_LEVEL
init|=
literal|1
block|,
comment|/* set level */
name|HAL_ANI_OFDM_WEAK_SIGNAL_DETECTION
init|=
literal|2
block|,
comment|/* enable/disable */
name|HAL_ANI_CCK_WEAK_SIGNAL_THR
init|=
literal|3
block|,
comment|/* enable/disable */
name|HAL_ANI_FIRSTEP_LEVEL
init|=
literal|4
block|,
comment|/* set level */
name|HAL_ANI_SPUR_IMMUNITY_LEVEL
init|=
literal|5
block|,
comment|/* set level */
name|HAL_ANI_MODE
init|=
literal|6
block|,
comment|/* 0 => manual, 1 => auto (XXX do not change) */
name|HAL_ANI_PHYERR_RESET
init|=
literal|7
block|,
comment|/* reset phy error stats */
name|HAL_ANI_MRC_CCK
init|=
literal|8
block|, }
name|HAL_ANI_CMD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_ANI_ALL
value|0xffffffff
end_define

begin_comment
comment|/*  * This is the layout of the ANI INTMIT capability.  *  * Notice that the command values differ to HAL_ANI_CMD.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_CAP_INTMIT_PRESENT
init|=
literal|0
block|,
name|HAL_CAP_INTMIT_ENABLE
init|=
literal|1
block|,
name|HAL_CAP_INTMIT_NOISE_IMMUNITY_LEVEL
init|=
literal|2
block|,
name|HAL_CAP_INTMIT_OFDM_WEAK_SIGNAL_LEVEL
init|=
literal|3
block|,
name|HAL_CAP_INTMIT_CCK_WEAK_SIGNAL_THR
init|=
literal|4
block|,
name|HAL_CAP_INTMIT_FIRSTEP_LEVEL
init|=
literal|5
block|,
name|HAL_CAP_INTMIT_SPUR_IMMUNITY_LEVEL
init|=
literal|6
block|}
name|HAL_CAP_INTMIT_CMD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|pe_firpwr
decl_stmt|;
comment|/* FIR pwr out threshold */
name|int32_t
name|pe_rrssi
decl_stmt|;
comment|/* Radar rssi thresh */
name|int32_t
name|pe_height
decl_stmt|;
comment|/* Pulse height thresh */
name|int32_t
name|pe_prssi
decl_stmt|;
comment|/* Pulse rssi thresh */
name|int32_t
name|pe_inband
decl_stmt|;
comment|/* Inband thresh */
comment|/* The following params are only for AR5413 and later */
name|u_int32_t
name|pe_relpwr
decl_stmt|;
comment|/* Relative power threshold in 0.5dB steps */
name|u_int32_t
name|pe_relstep
decl_stmt|;
comment|/* Pulse Relative step threshold in 0.5dB steps */
name|u_int32_t
name|pe_maxlen
decl_stmt|;
comment|/* Max length of radar sign in 0.8us units */
name|int32_t
name|pe_usefir128
decl_stmt|;
comment|/* Use the average in-band power measured over 128 cycles */
name|int32_t
name|pe_blockradar
decl_stmt|;
comment|/* 					 * Enable to block radar check if pkt detect is done via OFDM 					 * weak signal detect or pkt is detected immediately after tx 					 * to rx transition 					 */
name|int32_t
name|pe_enmaxrssi
decl_stmt|;
comment|/* 					 * Enable to use the max rssi instead of the last rssi during 					 * fine gain changes for radar detection 					 */
name|int32_t
name|pe_extchannel
decl_stmt|;
comment|/* Enable DFS on ext channel */
name|int32_t
name|pe_enabled
decl_stmt|;
comment|/* Whether radar detection is enabled */
name|int32_t
name|pe_enrelpwr
decl_stmt|;
name|int32_t
name|pe_en_relstep_check
decl_stmt|;
block|}
name|HAL_PHYERR_PARAM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_PHYERR_PARAM_NOVAL
value|65535
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|ss_fft_period
decl_stmt|;
comment|/* Skip interval for FFT reports */
name|u_int16_t
name|ss_period
decl_stmt|;
comment|/* Spectral scan period */
name|u_int16_t
name|ss_count
decl_stmt|;
comment|/* # of reports to return from ss_active */
name|u_int16_t
name|ss_short_report
decl_stmt|;
comment|/* Set to report ony 1 set of FFT results */
name|u_int8_t
name|radar_bin_thresh_sel
decl_stmt|;
comment|/* strong signal radar FFT threshold configuration */
name|u_int16_t
name|ss_spectral_pri
decl_stmt|;
comment|/* are we doing a noise power cal ? */
name|int8_t
name|ss_nf_cal
index|[
name|AH_MAX_CHAINS
operator|*
literal|2
index|]
decl_stmt|;
comment|/* nf calibrated values for ctl+ext from eeprom */
name|int8_t
name|ss_nf_pwr
index|[
name|AH_MAX_CHAINS
operator|*
literal|2
index|]
decl_stmt|;
comment|/* nf pwr values for ctl+ext from eeprom */
name|int32_t
name|ss_nf_temp_data
decl_stmt|;
comment|/* temperature data taken during nf scan */
name|int
name|ss_enabled
decl_stmt|;
name|int
name|ss_active
decl_stmt|;
block|}
name|HAL_SPECTRAL_PARAM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_SPECTRAL_PARAM_NOVAL
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|HAL_SPECTRAL_PARAM_ENABLE
value|0x8000
end_define

begin_comment
comment|/* Enable/Disable if applicable */
end_comment

begin_comment
comment|/*  * DFS operating mode flags.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_DFS_UNINIT_DOMAIN
init|=
literal|0
block|,
comment|/* Uninitialized dfs domain */
name|HAL_DFS_FCC_DOMAIN
init|=
literal|1
block|,
comment|/* FCC3 dfs domain */
name|HAL_DFS_ETSI_DOMAIN
init|=
literal|2
block|,
comment|/* ETSI dfs domain */
name|HAL_DFS_MKK4_DOMAIN
init|=
literal|3
block|,
comment|/* Japan dfs domain */
block|}
name|HAL_DFS_DOMAIN
typedef|;
end_typedef

begin_comment
comment|/*  * MFP decryption options for initializing the MAC.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_MFP_QOSDATA
init|=
literal|0
block|,
comment|/* Decrypt MFP frames like QoS data frames. All chips before Merlin. */
name|HAL_MFP_PASSTHRU
block|,
comment|/* Don't decrypt MFP frames at all. Passthrough */
name|HAL_MFP_HW_CRYPTO
comment|/* hardware decryption enabled. Merlin can do it. */
block|}
name|HAL_MFP_OPT_T
typedef|;
end_typedef

begin_comment
comment|/* LNA config supported */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_ANT_DIV_COMB_LNA1_MINUS_LNA2
init|=
literal|0
block|,
name|HAL_ANT_DIV_COMB_LNA2
init|=
literal|1
block|,
name|HAL_ANT_DIV_COMB_LNA1
init|=
literal|2
block|,
name|HAL_ANT_DIV_COMB_LNA1_PLUS_LNA2
init|=
literal|3
block|, }
name|HAL_ANT_DIV_COMB_LNA_CONF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|main_lna_conf
decl_stmt|;
name|u_int8_t
name|alt_lna_conf
decl_stmt|;
name|u_int8_t
name|fast_div_bias
decl_stmt|;
name|u_int8_t
name|main_gaintb
decl_stmt|;
name|u_int8_t
name|alt_gaintb
decl_stmt|;
name|u_int8_t
name|antdiv_configgroup
decl_stmt|;
name|int8_t
name|lna1_lna2_delta
decl_stmt|;
block|}
name|HAL_ANT_COMB_CONFIG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEFAULT_ANTDIV_CONFIG_GROUP
value|0x00
end_define

begin_define
define|#
directive|define
name|HAL_ANTDIV_CONFIG_GROUP_1
value|0x01
end_define

begin_define
define|#
directive|define
name|HAL_ANTDIV_CONFIG_GROUP_2
value|0x02
end_define

begin_define
define|#
directive|define
name|HAL_ANTDIV_CONFIG_GROUP_3
value|0x03
end_define

begin_comment
comment|/*  * Flag for setting QUIET period  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_QUIET_DISABLE
init|=
literal|0x0
block|,
name|HAL_QUIET_ENABLE
init|=
literal|0x1
block|,
name|HAL_QUIET_ADD_CURRENT_TSF
init|=
literal|0x2
block|,
comment|/* add current TSF to next_start offset */
name|HAL_QUIET_ADD_SWBA_RESP_TIME
init|=
literal|0x4
block|,
comment|/* add beacon response time to next_start offset */
block|}
name|HAL_QUIET_FLAG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_DFS_EVENT_PRICH
value|0x0000001
end_define

begin_define
define|#
directive|define
name|HAL_DFS_EVENT_EXTCH
value|0x0000002
end_define

begin_define
define|#
directive|define
name|HAL_DFS_EVENT_EXTEARLY
value|0x0000004
end_define

begin_define
define|#
directive|define
name|HAL_DFS_EVENT_ISDC
value|0x0000008
end_define

begin_struct
struct|struct
name|hal_dfs_event
block|{
name|uint64_t
name|re_full_ts
decl_stmt|;
comment|/* 64-bit full timestamp from interrupt time */
name|uint32_t
name|re_ts
decl_stmt|;
comment|/* Original 15 bit recv timestamp */
name|uint8_t
name|re_rssi
decl_stmt|;
comment|/* rssi of radar event */
name|uint8_t
name|re_dur
decl_stmt|;
comment|/* duration of radar pulse */
name|uint32_t
name|re_flags
decl_stmt|;
comment|/* Flags (see above) */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hal_dfs_event
name|HAL_DFS_EVENT
typedef|;
end_typedef

begin_comment
comment|/*  * Generic Timer domain  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_GEN_TIMER_TSF
init|=
literal|0
block|,
name|HAL_GEN_TIMER_TSF2
block|,
name|HAL_GEN_TIMER_TSF_ANY
block|}
name|HAL_GEN_TIMER_DOMAIN
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_RESET_NONE
init|=
literal|0x0
block|,
name|HAL_RESET_BBPANIC
init|=
literal|0x1
block|, }
name|HAL_RESET_TYPE
typedef|;
end_typedef

begin_comment
comment|/*  * BT Co-existence definitions  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_MODULE_CSR_BC4
init|=
literal|0
block|,
comment|/* CSR BlueCore v4 */
name|HAL_BT_MODULE_JANUS
init|=
literal|1
block|,
comment|/* Kite + Valkyrie combo */
name|HAL_BT_MODULE_HELIUS
init|=
literal|2
block|,
comment|/* Kiwi + Valkyrie combo */
name|HAL_MAX_BT_MODULES
block|}
name|HAL_BT_MODULE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|HAL_BT_MODULE
name|bt_module
decl_stmt|;
name|u_int8_t
name|bt_coex_config
decl_stmt|;
name|u_int8_t
name|bt_gpio_bt_active
decl_stmt|;
name|u_int8_t
name|bt_gpio_bt_priority
decl_stmt|;
name|u_int8_t
name|bt_gpio_wlan_active
decl_stmt|;
name|u_int8_t
name|bt_active_polarity
decl_stmt|;
name|HAL_BOOL
name|bt_single_ant
decl_stmt|;
name|u_int8_t
name|bt_dutyCycle
decl_stmt|;
name|u_int8_t
name|bt_isolation
decl_stmt|;
name|u_int8_t
name|bt_period
decl_stmt|;
block|}
name|HAL_BT_COEX_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_COEX_MODE_LEGACY
init|=
literal|0
block|,
comment|/* legacy rx_clear mode */
name|HAL_BT_COEX_MODE_UNSLOTTED
init|=
literal|1
block|,
comment|/* untimed/unslotted mode */
name|HAL_BT_COEX_MODE_SLOTTED
init|=
literal|2
block|,
comment|/* slotted mode */
name|HAL_BT_COEX_MODE_DISALBED
init|=
literal|3
block|,
comment|/* coexistence disabled */
block|}
name|HAL_BT_COEX_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_COEX_CFG_NONE
block|,
comment|/* No bt coex enabled */
name|HAL_BT_COEX_CFG_2WIRE_2CH
block|,
comment|/* 2-wire with 2 chains */
name|HAL_BT_COEX_CFG_2WIRE_CH1
block|,
comment|/* 2-wire with ch1 */
name|HAL_BT_COEX_CFG_2WIRE_CH0
block|,
comment|/* 2-wire with ch0 */
name|HAL_BT_COEX_CFG_3WIRE
block|,
comment|/* 3-wire */
name|HAL_BT_COEX_CFG_MCI
comment|/* MCI */
block|}
name|HAL_BT_COEX_CFG
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_COEX_SET_ACK_PWR
init|=
literal|0
block|,
comment|/* Change ACK power setting */
name|HAL_BT_COEX_LOWER_TX_PWR
block|,
comment|/* Change transmit power */
name|HAL_BT_COEX_ANTENNA_DIVERSITY
block|,
comment|/* Enable RX diversity for Kite */
name|HAL_BT_COEX_MCI_MAX_TX_PWR
block|,
comment|/* Set max tx power for concurrent tx */
name|HAL_BT_COEX_MCI_FTP_STOMP_RX
block|,
comment|/* Use a different weight for stomp low */
block|}
name|HAL_BT_COEX_SET_PARAMETER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_LOW_ACK_PWR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_LOWER_TX_PWR
value|0x00000002
end_define

begin_comment
comment|/* Check Rx Diversity is allowed */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_ANT_DIV_ALLOW
value|0x00000004
end_define

begin_comment
comment|/* Check Diversity is on or off */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_ANT_DIV_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL1_ENABLE
value|0x0b
end_define

begin_comment
comment|/* main: LNA1, alt: LNA2 */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL2_ENABLE
value|0x09
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL1_FIXED_A
value|0x04
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL2_FIXED_A
value|0x09
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL1_FIXED_B
value|0x02
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL2_FIXED_B
value|0x06
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ISOLATION_FOR_NO_COEX
value|30
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANT_DIV_SWITCH_COM
value|0x66666666
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_HELIUS_CHAINMASK
value|0x02
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_LOW_ACK_POWER
value|0x0
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_HIGH_ACK_POWER
value|0x3f3f3f
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_COEX_NO_STOMP
init|=
literal|0
block|,
name|HAL_BT_COEX_STOMP_ALL
block|,
name|HAL_BT_COEX_STOMP_LOW
block|,
name|HAL_BT_COEX_STOMP_NONE
block|,
name|HAL_BT_COEX_STOMP_ALL_FORCE
block|,
name|HAL_BT_COEX_STOMP_LOW_FORCE
block|, }
name|HAL_BT_COEX_STOMP_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* extend rx_clear after tx/rx to protect the burst (in usec). */
name|u_int8_t
name|bt_time_extend
decl_stmt|;
comment|/* 	 * extend rx_clear as long as txsm is 	 * transmitting or waiting for ack. 	 */
name|HAL_BOOL
name|bt_txstate_extend
decl_stmt|;
comment|/* 	 * extend rx_clear so that when tx_frame 	 * is asserted, rx_clear will drop. 	 */
name|HAL_BOOL
name|bt_txframe_extend
decl_stmt|;
comment|/* 	 * coexistence mode 	 */
name|HAL_BT_COEX_MODE
name|bt_mode
decl_stmt|;
comment|/* 	 * treat BT high priority traffic as 	 * a quiet collision 	 */
name|HAL_BOOL
name|bt_quiet_collision
decl_stmt|;
comment|/* 	 * invert rx_clear as WLAN_ACTIVE 	 */
name|HAL_BOOL
name|bt_rxclear_polarity
decl_stmt|;
comment|/* 	 * slotted mode only. indicate the time in usec 	 * from the rising edge of BT_ACTIVE to the time 	 * BT_PRIORITY can be sampled to indicate priority. 	 */
name|u_int8_t
name|bt_priority_time
decl_stmt|;
comment|/* 	 * slotted mode only. indicate the time in usec 	 * from the rising edge of BT_ACTIVE to the time 	 * BT_PRIORITY can be sampled to indicate tx/rx and 	 * BT_FREQ is sampled. 	 */
name|u_int8_t
name|bt_first_slot_time
decl_stmt|;
comment|/* 	 * slotted mode only. rx_clear and bt_ant decision 	 * will be held the entire time that BT_ACTIVE is asserted, 	 * otherwise the decision is made before every slot boundry. 	 */
name|HAL_BOOL
name|bt_hold_rxclear
decl_stmt|;
block|}
name|HAL_BT_COEX_CONFIG
typedef|;
end_typedef

begin_struct
struct|struct
name|hal_bb_panic_info
block|{
name|u_int32_t
name|status
decl_stmt|;
name|u_int32_t
name|tsf
decl_stmt|;
name|u_int32_t
name|phy_panic_wd_ctl1
decl_stmt|;
name|u_int32_t
name|phy_panic_wd_ctl2
decl_stmt|;
name|u_int32_t
name|phy_gen_ctrl
decl_stmt|;
name|u_int32_t
name|rxc_pcnt
decl_stmt|;
name|u_int32_t
name|rxf_pcnt
decl_stmt|;
name|u_int32_t
name|txf_pcnt
decl_stmt|;
name|u_int32_t
name|cycles
decl_stmt|;
name|u_int32_t
name|wd
decl_stmt|;
name|u_int32_t
name|det
decl_stmt|;
name|u_int32_t
name|rdar
decl_stmt|;
name|u_int32_t
name|r_odfm
decl_stmt|;
name|u_int32_t
name|r_cck
decl_stmt|;
name|u_int32_t
name|t_odfm
decl_stmt|;
name|u_int32_t
name|t_cck
decl_stmt|;
name|u_int32_t
name|agc
decl_stmt|;
name|u_int32_t
name|src
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Serialize Register Access Mode */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SER_REG_MODE_OFF
init|=
literal|0
block|,
name|SER_REG_MODE_ON
init|=
literal|1
block|,
name|SER_REG_MODE_AUTO
init|=
literal|2
block|, }
name|SER_REG_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|ah_debug
decl_stmt|;
comment|/* only used if AH_DEBUG is defined */
name|int
name|ah_ar5416_biasadj
decl_stmt|;
comment|/* enable AR2133 radio specific bias fiddling */
comment|/* NB: these are deprecated; they exist for now for compatibility */
name|int
name|ah_dma_beacon_response_time
decl_stmt|;
comment|/* in TU's */
name|int
name|ah_sw_beacon_response_time
decl_stmt|;
comment|/* in TU's */
name|int
name|ah_additional_swba_backoff
decl_stmt|;
comment|/* in TU's */
name|int
name|ah_force_full_reset
decl_stmt|;
comment|/* force full chip reset rather then warm reset */
name|int
name|ah_serialise_reg_war
decl_stmt|;
comment|/* force serialisation of register IO */
comment|/* XXX these don't belong here, they're just for the ar9300  HAL port effort */
name|int
name|ath_hal_desc_tpc
decl_stmt|;
comment|/* Per-packet TPC */
name|int
name|ath_hal_sta_update_tx_pwr_enable
decl_stmt|;
comment|/* GreenTX */
name|int
name|ath_hal_sta_update_tx_pwr_enable_S1
decl_stmt|;
comment|/* GreenTX */
name|int
name|ath_hal_sta_update_tx_pwr_enable_S2
decl_stmt|;
comment|/* GreenTX */
name|int
name|ath_hal_sta_update_tx_pwr_enable_S3
decl_stmt|;
comment|/* GreenTX */
comment|/* I'm not sure what the default values for these should be */
name|int
name|ath_hal_pll_pwr_save
decl_stmt|;
name|int
name|ath_hal_pcie_power_save_enable
decl_stmt|;
name|int
name|ath_hal_intr_mitigation_rx
decl_stmt|;
name|int
name|ath_hal_intr_mitigation_tx
decl_stmt|;
name|int
name|ath_hal_pcie_clock_req
decl_stmt|;
define|#
directive|define
name|AR_PCIE_PLL_PWRSAVE_CONTROL
value|(1<<0)
define|#
directive|define
name|AR_PCIE_PLL_PWRSAVE_ON_D3
value|(1<<1)
define|#
directive|define
name|AR_PCIE_PLL_PWRSAVE_ON_D0
value|(1<<2)
name|int
name|ath_hal_pcie_waen
decl_stmt|;
name|int
name|ath_hal_pcie_ser_des_write
decl_stmt|;
comment|/* these are important for correct AR9300 behaviour */
name|int
name|ath_hal_ht_enable
decl_stmt|;
comment|/* needs to be enabled for AR9300 HT */
name|int
name|ath_hal_diversity_control
decl_stmt|;
name|int
name|ath_hal_antenna_switch_swap
decl_stmt|;
name|int
name|ath_hal_ext_lna_ctl_gpio
decl_stmt|;
name|int
name|ath_hal_spur_mode
decl_stmt|;
name|int
name|ath_hal_6mb_ack
decl_stmt|;
comment|/* should set this to 1 for 11a/11na? */
name|int
name|ath_hal_enable_msi
decl_stmt|;
comment|/* enable MSI interrupts (needed?) */
name|int
name|ath_hal_beacon_filter_interval
decl_stmt|;
comment|/* ok to be 0 for now? */
comment|/* For now, set this to 0 - net80211 needs to know about hardware MFP support */
name|int
name|ath_hal_mfp_support
decl_stmt|;
name|int
name|ath_hal_enable_ani
decl_stmt|;
comment|/* should set this.. */
name|int
name|ath_hal_cwm_ignore_ext_cca
decl_stmt|;
name|int
name|ath_hal_show_bb_panic
decl_stmt|;
name|int
name|ath_hal_ant_ctrl_comm2g_switch_enable
decl_stmt|;
name|int
name|ath_hal_ext_atten_margin_cfg
decl_stmt|;
name|int
name|ath_hal_min_gainidx
decl_stmt|;
name|int
name|ath_hal_war70c
decl_stmt|;
name|uint32_t
name|ath_hal_mci_config
decl_stmt|;
block|}
name|HAL_OPS_CONFIG
typedef|;
end_typedef

begin_comment
comment|/*  * Hardware Access Layer (HAL) API.  *  * Clients of the HAL call ath_hal_attach to obtain a reference to an  * ath_hal structure for use with the device.  Hardware-related operations  * that follow must call back into the HAL through interface, supplying  * the reference as the first parameter.  Note that before using the  * reference returned by ath_hal_attach the caller should verify the  * ABI version number.  */
end_comment

begin_struct
struct|struct
name|ath_hal
block|{
name|uint32_t
name|ah_magic
decl_stmt|;
comment|/* consistency check magic number */
name|uint16_t
name|ah_devid
decl_stmt|;
comment|/* PCI device ID */
name|uint16_t
name|ah_subvendorid
decl_stmt|;
comment|/* PCI subvendor ID */
name|HAL_SOFTC
name|ah_sc
decl_stmt|;
comment|/* back pointer to driver/os state */
name|HAL_BUS_TAG
name|ah_st
decl_stmt|;
comment|/* params for register r+w */
name|HAL_BUS_HANDLE
name|ah_sh
decl_stmt|;
name|HAL_CTRY_CODE
name|ah_countryCode
decl_stmt|;
name|uint32_t
name|ah_macVersion
decl_stmt|;
comment|/* MAC version id */
name|uint16_t
name|ah_macRev
decl_stmt|;
comment|/* MAC revision */
name|uint16_t
name|ah_phyRev
decl_stmt|;
comment|/* PHY revision */
comment|/* NB: when only one radio is present the rev is in 5Ghz */
name|uint16_t
name|ah_analog5GhzRev
decl_stmt|;
comment|/* 5GHz radio revision */
name|uint16_t
name|ah_analog2GhzRev
decl_stmt|;
comment|/* 2GHz radio revision */
name|uint16_t
modifier|*
name|ah_eepromdata
decl_stmt|;
comment|/* eeprom buffer, if needed */
name|uint32_t
name|ah_intrstate
index|[
literal|8
index|]
decl_stmt|;
comment|/* last int state */
name|uint32_t
name|ah_syncstate
decl_stmt|;
comment|/* last sync intr state */
comment|/* Current powerstate from HAL calls */
name|HAL_POWER_MODE
name|ah_powerMode
decl_stmt|;
name|HAL_OPS_CONFIG
name|ah_config
decl_stmt|;
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|__ahdecl
function_decl|(
modifier|*
name|ah_getRateTable
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|mode
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_detach
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
comment|/* Reset functions */
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_reset
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_OPMODE
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|HAL_BOOL
name|bChannelChange
parameter_list|,
name|HAL_STATUS
modifier|*
name|status
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_phyDisable
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_disable
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_configPCIE
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_BOOL
name|restore
parameter_list|,
name|HAL_BOOL
name|power_off
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_disablePCIE
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setPCUConfig
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_perCalibration
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|HAL_BOOL
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_perCalibrationN
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|u_int
name|chainMask
parameter_list|,
name|HAL_BOOL
name|longCal
parameter_list|,
name|HAL_BOOL
modifier|*
name|isCalDone
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_resetCalValid
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setTxPower
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setTxPowerLimit
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setBoardValues
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
comment|/* Transmit functions */
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_updateTxTrigLevel
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_BOOL
name|incTrigLevel
parameter_list|)
function_decl|;
name|int
name|__ahdecl
function_decl|(
modifier|*
name|ah_setupTxQueue
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_TX_QUEUE
parameter_list|,
specifier|const
name|HAL_TXQ_INFO
modifier|*
name|qInfo
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setTxQueueProps
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
name|q
parameter_list|,
specifier|const
name|HAL_TXQ_INFO
modifier|*
name|qInfo
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTxQueueProps
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
name|q
parameter_list|,
name|HAL_TXQ_INFO
modifier|*
name|qInfo
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_releaseTxQueue
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_resetTxQueue
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|)
function_decl|;
name|uint32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTxDP
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setTxDP
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|uint32_t
name|txdp
parameter_list|)
function_decl|;
name|uint32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_numTxPending
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|q
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_startTxDma
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_stopTxDma
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setupTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int
name|pktLen
parameter_list|,
name|u_int
name|hdrLen
parameter_list|,
name|HAL_PKT_TYPE
name|type
parameter_list|,
name|u_int
name|txPower
parameter_list|,
name|u_int
name|txRate0
parameter_list|,
name|u_int
name|txTries0
parameter_list|,
name|u_int
name|keyIx
parameter_list|,
name|u_int
name|antMode
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|u_int
name|rtsctsRate
parameter_list|,
name|u_int
name|rtsctsDuration
parameter_list|,
name|u_int
name|compicvLen
parameter_list|,
name|u_int
name|compivLen
parameter_list|,
name|u_int
name|comp
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setupXTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int
name|txRate1
parameter_list|,
name|u_int
name|txTries1
parameter_list|,
name|u_int
name|txRate2
parameter_list|,
name|u_int
name|txTries2
parameter_list|,
name|u_int
name|txRate3
parameter_list|,
name|u_int
name|txTries3
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_fillTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|HAL_DMA_ADDR
modifier|*
name|bufAddrList
parameter_list|,
name|uint32_t
modifier|*
name|segLenList
parameter_list|,
name|u_int
name|descId
parameter_list|,
name|u_int
name|qcuId
parameter_list|,
name|HAL_BOOL
name|firstSeg
parameter_list|,
name|HAL_BOOL
name|lastSeg
parameter_list|,
specifier|const
name|struct
name|ath_desc
modifier|*
parameter_list|)
function_decl|;
name|HAL_STATUS
name|__ahdecl
function_decl|(
modifier|*
name|ah_procTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|struct
name|ath_tx_status
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTxIntrQueue
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_reqTxIntrDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTxCompletionRates
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ath_desc
modifier|*
name|ds
parameter_list|,
name|int
modifier|*
name|rates
parameter_list|,
name|int
modifier|*
name|tries
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setTxDescLink
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|uint32_t
name|link
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTxDescLink
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|uint32_t
modifier|*
name|link
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTxDescLinkPtr
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|uint32_t
modifier|*
modifier|*
name|linkptr
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setupTxStatusRing
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|void
modifier|*
name|ts_start
parameter_list|,
name|uint32_t
name|ts_paddr_start
parameter_list|,
name|uint16_t
name|size
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTxRawTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
comment|/* Receive Functions */
name|uint32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getRxDP
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_RX_QUEUE
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setRxDP
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|rxdp
parameter_list|,
name|HAL_RX_QUEUE
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_enableReceive
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_stopDmaReceive
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_startPcuReceive
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_stopPcuReceive
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setMulticastFilter
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|filter0
parameter_list|,
name|uint32_t
name|filter1
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setMulticastFilterIndex
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|index
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_clrMulticastFilterIndex
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|index
parameter_list|)
function_decl|;
name|uint32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getRxFilter
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setRxFilter
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setupRxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
name|HAL_STATUS
name|__ahdecl
function_decl|(
modifier|*
name|ah_procRxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|uint32_t
name|phyAddr
parameter_list|,
name|struct
name|ath_desc
modifier|*
name|next
parameter_list|,
name|uint64_t
name|tsf
parameter_list|,
name|struct
name|ath_rx_status
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_rxMonitor
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|HAL_NODE_STATS
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_aniPoll
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_procMibEvent
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|HAL_NODE_STATS
modifier|*
parameter_list|)
function_decl|;
comment|/* Misc Functions */
name|HAL_STATUS
name|__ahdecl
function_decl|(
modifier|*
name|ah_getCapability
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_CAPABILITY_TYPE
parameter_list|,
name|uint32_t
name|capability
parameter_list|,
name|uint32_t
modifier|*
name|result
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setCapability
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_CAPABILITY_TYPE
parameter_list|,
name|uint32_t
name|capability
parameter_list|,
name|uint32_t
name|setting
parameter_list|,
name|HAL_STATUS
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_getDiagState
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
name|request
parameter_list|,
specifier|const
name|void
modifier|*
name|args
parameter_list|,
name|uint32_t
name|argsize
parameter_list|,
name|void
modifier|*
modifier|*
name|result
parameter_list|,
name|uint32_t
modifier|*
name|resultsize
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_getMacAddress
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setMacAddress
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_getBssIdMask
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setBssIdMask
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setRegulatoryDomain
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|HAL_STATUS
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setLedState
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_LED_STATE
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_writeAssocid
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|bssid
parameter_list|,
name|uint16_t
name|assocId
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_gpioCfgOutput
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|gpio
parameter_list|,
name|HAL_GPIO_MUX_TYPE
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_gpioCfgInput
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|gpio
parameter_list|)
function_decl|;
name|uint32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_gpioGet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|gpio
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_gpioSet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|gpio
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_gpioSetIntr
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|uint32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTsf32
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|uint64_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getTsf64
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setTsf64
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_resetTsf
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_detectCardPresent
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_updateMibCounters
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_MIB_STATS
modifier|*
parameter_list|)
function_decl|;
name|HAL_RFGAIN
name|__ahdecl
function_decl|(
modifier|*
name|ah_getRfGain
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|u_int
name|__ahdecl
function_decl|(
modifier|*
name|ah_getDefAntenna
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setDefAntenna
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|HAL_ANT_SETTING
name|__ahdecl
function_decl|(
modifier|*
name|ah_getAntennaSwitch
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setAntennaSwitch
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_ANT_SETTING
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setSifsTime
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|u_int
name|__ahdecl
function_decl|(
modifier|*
name|ah_getSifsTime
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setSlotTime
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|u_int
name|__ahdecl
function_decl|(
modifier|*
name|ah_getSlotTime
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setAckTimeout
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|u_int
name|__ahdecl
function_decl|(
modifier|*
name|ah_getAckTimeout
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setAckCTSRate
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|u_int
name|__ahdecl
function_decl|(
modifier|*
name|ah_getAckCTSRate
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setCTSTimeout
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|u_int
name|__ahdecl
function_decl|(
modifier|*
name|ah_getCTSTimeout
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setDecompMask
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setCoverageClass
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|HAL_STATUS
name|__ahdecl
function_decl|(
modifier|*
name|ah_setQuiet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|uint32_t
name|period
parameter_list|,
name|uint32_t
name|duration
parameter_list|,
name|uint32_t
name|nextStart
parameter_list|,
name|HAL_QUIET_FLAG
name|flag
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setChainMasks
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/* DFS functions */
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_enableDfs
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_PHYERR_PARAM
modifier|*
name|pe
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_getDfsThresh
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_PHYERR_PARAM
modifier|*
name|pe
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_getDfsDefaultThresh
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_PHYERR_PARAM
modifier|*
name|pe
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_procRadarEvent
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_rx_status
modifier|*
name|rxs
parameter_list|,
name|uint64_t
name|fulltsf
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|HAL_DFS_EVENT
modifier|*
name|event
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_isFastClockEnabled
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
comment|/* Spectral Scan functions */
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_spectralConfigure
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_SPECTRAL_PARAM
modifier|*
name|sp
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_spectralGetConfig
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_SPECTRAL_PARAM
modifier|*
name|sp
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_spectralStart
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_spectralStop
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_spectralIsEnabled
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_spectralIsActive
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
comment|/* XXX getNfPri() and getNfExt() */
comment|/* Key Cache Functions */
name|uint32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getKeyCacheSize
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_resetKeyCacheEntry
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_isKeyCacheEntryValid
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setKeyCacheEntry
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
specifier|const
name|HAL_KEYVAL
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setKeyCacheEntryMac
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
comment|/* Power Management Functions */
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setPowerMode
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_POWER_MODE
name|mode
parameter_list|,
name|int
name|setChip
parameter_list|)
function_decl|;
name|HAL_POWER_MODE
name|__ahdecl
function_decl|(
modifier|*
name|ah_getPowerMode
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|int16_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getChanNoise
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
comment|/* Beacon Management Functions */
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setBeaconTimers
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|HAL_BEACON_TIMERS
modifier|*
parameter_list|)
function_decl|;
comment|/* NB: deprecated, use ah_setBeaconTimers instead */
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_beaconInit
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
name|nexttbtt
parameter_list|,
name|uint32_t
name|intval
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_setStationBeaconTimers
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|HAL_BEACON_STATE
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_resetStationBeaconTimers
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|uint64_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getNextTBTT
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
comment|/* 802.11n Functions */
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_chainTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|HAL_DMA_ADDR
modifier|*
name|bufAddrList
parameter_list|,
name|uint32_t
modifier|*
name|segLenList
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|HAL_PKT_TYPE
parameter_list|,
name|u_int
parameter_list|,
name|HAL_CIPHER
parameter_list|,
name|uint8_t
parameter_list|,
name|HAL_BOOL
parameter_list|,
name|HAL_BOOL
parameter_list|,
name|HAL_BOOL
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setupFirstTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_setupLastTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
specifier|const
name|struct
name|ath_desc
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nRateScenario
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|HAL_11N_RATE_SERIES
index|[]
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
comment|/* 	 * The next 4 (set11ntxdesc -> set11naggrlast) are specific 	 * to the EDMA HAL.  Descriptors are chained together by 	 * using filltxdesc (not ChainTxDesc) and then setting the 	 * aggregate flags appropriately using first/middle/last. 	 */
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nTxDesc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|HAL_PKT_TYPE
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nAggrFirst
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nAggrMiddle
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nAggrLast
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_clr11nAggr
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nBurstDuration
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nVirtMoreFrag
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_getMibCycleCounts
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_SURVEY_SAMPLE
modifier|*
parameter_list|)
function_decl|;
name|uint32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_get11nExtBusy
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nMac2040
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_HT_MACMODE
parameter_list|)
function_decl|;
name|HAL_HT_RXCLEAR
name|__ahdecl
function_decl|(
modifier|*
name|ah_get11nRxClear
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_set11nRxClear
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_HT_RXCLEAR
parameter_list|)
function_decl|;
comment|/* Interrupt functions */
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_isInterruptPending
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_getPendingInterrupts
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_INT
modifier|*
parameter_list|)
function_decl|;
name|HAL_INT
name|__ahdecl
function_decl|(
modifier|*
name|ah_getInterrupts
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|HAL_INT
name|__ahdecl
function_decl|(
modifier|*
name|ah_setInterrupts
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_INT
parameter_list|)
function_decl|;
comment|/* Bluetooth Coexistence functions */
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_btCoexSetInfo
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_BT_COEX_INFO
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_btCoexSetConfig
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_BT_COEX_CONFIG
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_btCoexSetQcuThresh
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_btCoexSetWeights
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_btCoexSetBmissThresh
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_btCoexSetParameter
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_btCoexDisable
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
name|int
name|__ahdecl
function_decl|(
modifier|*
name|ah_btCoexEnable
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
comment|/* LNA diversity configuration */
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_divLnaConfGet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_ANT_COMB_CONFIG
modifier|*
parameter_list|)
function_decl|;
name|void
name|__ahdecl
function_decl|(
modifier|*
name|ah_divLnaConfSet
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_ANT_COMB_CONFIG
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * Check the PCI vendor ID and device ID against Atheros' values  * and return a printable description for any Atheros hardware.  * AH_NULL is returned if the ID's do not describe Atheros hardware.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|__ahdecl
name|ath_hal_probe
parameter_list|(
name|uint16_t
name|vendorid
parameter_list|,
name|uint16_t
name|devid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach the HAL for use with the specified device.  The device is  * defined by the PCI device ID.  The caller provides an opaque pointer  * to an upper-layer data structure (HAL_SOFTC) that is stored in the  * HAL state block for later use.  Hardware register accesses are done  * using the specified bus tag and handle.  On successful return a  * reference to a state block is returned that must be supplied in all  * subsequent HAL calls.  Storage associated with this reference is  * dynamically allocated and must be freed by calling the ah_detach  * method when the client is done.  If the attach operation fails a  * null (AH_NULL) reference will be returned and a status code will  * be returned if the status parameter is non-zero.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|ath_hal
modifier|*
name|__ahdecl
name|ath_hal_attach
parameter_list|(
name|uint16_t
name|devid
parameter_list|,
name|HAL_SOFTC
parameter_list|,
name|HAL_BUS_TAG
parameter_list|,
name|HAL_BUS_HANDLE
parameter_list|,
name|uint16_t
modifier|*
name|eepromdata
parameter_list|,
name|HAL_OPS_CONFIG
modifier|*
name|ah_config
parameter_list|,
name|HAL_STATUS
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|ath_hal_mac_name
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|ath_hal_rf_name
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Regulatory interfaces.  Drivers should use ath_hal_init_channels to  * request a set of channels for a particular country code and/or  * regulatory domain.  If CTRY_DEFAULT and SKU_NONE are specified then  * this list is constructed according to the contents of the EEPROM.  * ath_hal_getchannels acts similarly but does not alter the operating  * state; this can be used to collect information for a particular  * regulatory configuration.  Finally ath_hal_set_channels installs a  * channel list constructed outside the driver.  The HAL will adopt the  * channel list and setup internal state according to the specified  * regulatory configuration (e.g. conformance test limits).  *  * For all interfaces the channel list is returned in the supplied array.  * maxchans defines the maximum size of this array.  nchans contains the  * actual number of channels returned.  If a problem occurred then a  * status code != HAL_OK is returned.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ieee80211_channel
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Return a list of channels according to the specified regulatory.  */
end_comment

begin_function_decl
specifier|extern
name|HAL_STATUS
name|__ahdecl
name|ath_hal_getchannels
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chans
parameter_list|,
name|u_int
name|maxchans
parameter_list|,
name|int
modifier|*
name|nchans
parameter_list|,
name|u_int
name|modeSelect
parameter_list|,
name|HAL_CTRY_CODE
name|cc
parameter_list|,
name|HAL_REG_DOMAIN
name|regDmn
parameter_list|,
name|HAL_BOOL
name|enableExtendedChannels
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a list of channels and install it as the current operating  * regulatory list.  */
end_comment

begin_function_decl
specifier|extern
name|HAL_STATUS
name|__ahdecl
name|ath_hal_init_channels
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chans
parameter_list|,
name|u_int
name|maxchans
parameter_list|,
name|int
modifier|*
name|nchans
parameter_list|,
name|u_int
name|modeSelect
parameter_list|,
name|HAL_CTRY_CODE
name|cc
parameter_list|,
name|HAL_REG_DOMAIN
name|rd
parameter_list|,
name|HAL_BOOL
name|enableExtendedChannels
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Install the list of channels as the current operating regulatory  * and setup related state according to the country code and sku.  */
end_comment

begin_function_decl
specifier|extern
name|HAL_STATUS
name|__ahdecl
name|ath_hal_set_channels
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chans
parameter_list|,
name|int
name|nchans
parameter_list|,
name|HAL_CTRY_CODE
name|cc
parameter_list|,
name|HAL_REG_DOMAIN
name|regDmn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Fetch the ctl/ext noise floor values reported by a MIMO  * radio. Returns 1 for valid results, 0 for invalid channel.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__ahdecl
name|ath_hal_get_mimo_chan_noise
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|,
name|int16_t
modifier|*
name|nf_ctl
parameter_list|,
name|int16_t
modifier|*
name|nf_ext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Calibrate noise floor data following a channel scan or similar.  * This must be called prior retrieving noise floor data.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__ahdecl
name|ath_hal_process_noisefloor
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return bit mask of wireless modes supported by the hardware.  */
end_comment

begin_function_decl
specifier|extern
name|u_int
name|__ahdecl
name|ath_hal_getwirelessmodes
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the HAL wireless mode for the given channel.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ath_hal_get_curmode
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Calculate the packet TX time for a legacy or 11n frame  */
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|__ahdecl
name|ath_hal_pkt_txtime
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|rates
parameter_list|,
name|uint32_t
name|frameLen
parameter_list|,
name|uint16_t
name|rateix
parameter_list|,
name|HAL_BOOL
name|isht40
parameter_list|,
name|HAL_BOOL
name|shortPreamble
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Calculate the duration of an 11n frame.  */
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|__ahdecl
name|ath_computedur_ht
parameter_list|(
name|uint32_t
name|frameLen
parameter_list|,
name|uint16_t
name|rate
parameter_list|,
name|int
name|streams
parameter_list|,
name|HAL_BOOL
name|isht40
parameter_list|,
name|HAL_BOOL
name|isShortGI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Calculate the transmit duration of a legacy frame.  */
end_comment

begin_function_decl
specifier|extern
name|uint16_t
name|__ahdecl
name|ath_hal_computetxtime
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|rates
parameter_list|,
name|uint32_t
name|frameLen
parameter_list|,
name|uint16_t
name|rateix
parameter_list|,
name|HAL_BOOL
name|shortPreamble
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Adjust the TSF.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__ahdecl
name|ath_hal_adjusttsf
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int32_t
name|tsfdelta
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable or disable CCA.  */
end_comment

begin_function_decl
name|void
name|__ahdecl
name|ath_hal_setcca
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|ena
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get CCA setting.  */
end_comment

begin_function_decl
name|int
name|__ahdecl
name|ath_hal_getcca
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read EEPROM data from ah_eepromdata  */
end_comment

begin_function_decl
name|HAL_BOOL
name|__ahdecl
name|ath_hal_EepromDataRead
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|off
parameter_list|,
name|uint16_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * For now, simply pass through MFP frames.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int32_t
name|ath_hal_get_mfp_qos
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
block|{
comment|//return AH_PRIVATE(ah)->ah_mfp_qos;
return|return
name|HAL_MFP_QOSDATA
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_H_ */
end_comment

end_unit

