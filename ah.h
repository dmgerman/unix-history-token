begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2006 Sam Leffler, Errno Consulting, Atheros  * Communications, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the following conditions are met:  * 1. The materials contained herein are unmodified and are used  *    unmodified.  * 2. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following NO  *    ''WARRANTY'' disclaimer below (''Disclaimer''), without  *    modification.  * 3. Redistributions in binary form must reproduce at minimum a  *    disclaimer similar to the Disclaimer below and any redistribution  *    must be conditioned upon including a substantially similar  *    Disclaimer requirement for further binary redistribution.  * 4. Neither the names of the above-listed copyright holders nor the  *    names of any contributors may be used to endorse or promote  *    product derived from this software without specific prior written  *    permission.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT,  * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE  * FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGES.  *  * $Id: //depot/sw/branches/sam_hal/ah.h#19 $  */
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

begin_comment
comment|/*  * Bus i/o type definitions.  We define a platform-independent  * set of types that are mapped to platform-dependent data for  * register read/write operations.  We use types that are large  * enough to hold a pointer; smaller data should fit and only  * require type coercion to work.  Larger data can be stored  * elsewhere and a reference passed for the bus tag and/or handle.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|HAL_SOFTC
typedef|;
end_typedef

begin_comment
comment|/* pointer to driver/OS state */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|HAL_BUS_TAG
typedef|;
end_typedef

begin_comment
comment|/* opaque bus i/o id tag */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|HAL_BUS_HANDLE
typedef|;
end_typedef

begin_comment
comment|/* opaque bus i/o handle */
end_comment

begin_include
include|#
directive|include
file|"ah_osdep.h"
end_include

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
name|HAL_CAP_XR
init|=
literal|21
block|,
comment|/* hardware has XR support  */
name|HAL_CAP_WME_TKIPMIC
init|=
literal|22
block|,
comment|/* hardware can support TKIP MIC when WMM is turned on */
name|HAL_CAP_CHAN_HALFRATE
init|=
literal|23
block|,
comment|/* hardware can support half rate channels */
name|HAL_CAP_CHAN_QUARTERRATE
init|=
literal|24
block|,
comment|/* hardware can support quarter rate channels */
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
name|HAL_CAP_INTMIT
init|=
literal|29
block|,
comment|/* interference mitigation */
name|HAL_CAP_RXORN_FATAL
init|=
literal|30
block|,
comment|/* HAL_INT_RXORN treated as fatal */
name|HAL_CAP_RXTSTAMP_PREC
init|=
literal|34
block|,
comment|/* rx desc tstamp precision (bits) */
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
block|}
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
name|HAL_XR_DATA
init|=
literal|5
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
name|u_int32_t
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
name|u_int32_t
name|tqi_priority
decl_stmt|;
comment|/* (not used) */
name|u_int32_t
name|tqi_aifs
decl_stmt|;
comment|/* aifs */
name|u_int32_t
name|tqi_cwmin
decl_stmt|;
comment|/* cwMin */
name|u_int32_t
name|tqi_cwmax
decl_stmt|;
comment|/* cwMax */
name|u_int16_t
name|tqi_shretry
decl_stmt|;
comment|/* rts retry limit */
name|u_int16_t
name|tqi_lgretry
decl_stmt|;
comment|/* long retry limit (not used)*/
name|u_int32_t
name|tqi_cbrPeriod
decl_stmt|;
comment|/* CBR period (us) */
name|u_int32_t
name|tqi_cbrOverflowLimit
decl_stmt|;
comment|/* threshold for CBROVF int */
name|u_int32_t
name|tqi_burstTime
decl_stmt|;
comment|/* max burst duration (us) */
name|u_int32_t
name|tqi_readyTime
decl_stmt|;
comment|/* frame schedule time (us) */
name|u_int32_t
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
value|((u_int32_t) -1)
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
name|HAL_RX_FILTER_XRPOLL
init|=
literal|0x00000040
block|,
comment|/* Allow XR poll frmae */
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
name|HAL_RX_FILTER_PHYRADAR
init|=
literal|0x00000200
block|,
comment|/* Allow phy radar errors*/
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
name|HAL_INT_BMISS
init|=
literal|0x00040000
block|,
name|HAL_INT_BNR
init|=
literal|0x00100000
block|,
comment|/* Non-common mapping */
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
name|HAL_INT_TXURN
operator||
name|HAL_INT_TXDESC
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
name|HAL_INT_GPIO
block|, }
name|HAL_INT
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

begin_comment
comment|/*  * Channels are specified by frequency.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|channel
decl_stmt|;
comment|/* setting in Mhz */
name|u_int16_t
name|channelFlags
decl_stmt|;
comment|/* see below */
name|u_int8_t
name|privFlags
decl_stmt|;
name|int8_t
name|maxRegTxPower
decl_stmt|;
comment|/* max regulatory tx power in dBm */
name|int8_t
name|maxTxPower
decl_stmt|;
comment|/* max true tx power in 0.5 dBm */
name|int8_t
name|minTxPower
decl_stmt|;
comment|/* min true tx power in 0.5 dBm */
block|}
name|HAL_CHANNEL
typedef|;
end_typedef

begin_comment
comment|/* channelFlags */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_CW_INT
value|0x0002
end_define

begin_comment
comment|/* CW interference detected on channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_TURBO
value|0x0010
end_define

begin_comment
comment|/* Turbo Channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_CCK
value|0x0020
end_define

begin_comment
comment|/* CCK channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_OFDM
value|0x0040
end_define

begin_comment
comment|/* OFDM channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_2GHZ
value|0x0080
end_define

begin_comment
comment|/* 2 GHz spectrum channel. */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_5GHZ
value|0x0100
end_define

begin_comment
comment|/* 5 GHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_PASSIVE
value|0x0200
end_define

begin_comment
comment|/* Only passive scan allowed in the channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_DYN
value|0x0400
end_define

begin_comment
comment|/* dynamic CCK-OFDM channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_XR
value|0x0800
end_define

begin_comment
comment|/* XR channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_STURBO
value|0x2000
end_define

begin_comment
comment|/* Static turbo, no 11a-only usage */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_HALF
value|0x4000
end_define

begin_comment
comment|/* Half rate channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_QUARTER
value|0x8000
end_define

begin_comment
comment|/* Quarter rate channel */
end_comment

begin_comment
comment|/* privFlags */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_INTERFERENCE
value|0x01
end_define

begin_comment
comment|/* Software use: channel interference  				        used for as AR as well as RADAR  				        interference detection */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_DFS
value|0x02
end_define

begin_comment
comment|/* DFS required on channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_4MS_LIMIT
value|0x04
end_define

begin_comment
comment|/* 4msec packet limit on this channel */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_DFS_CLEAR
value|0x08
end_define

begin_comment
comment|/* if channel has been checked for DFS */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_A
value|(CHANNEL_5GHZ|CHANNEL_OFDM)
end_define

begin_define
define|#
directive|define
name|CHANNEL_B
value|(CHANNEL_2GHZ|CHANNEL_CCK)
end_define

begin_define
define|#
directive|define
name|CHANNEL_PUREG
value|(CHANNEL_2GHZ|CHANNEL_OFDM)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|CHANNEL_G
value|(CHANNEL_2GHZ|CHANNEL_DYN)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHANNEL_G
value|(CHANNEL_2GHZ|CHANNEL_OFDM)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHANNEL_T
value|(CHANNEL_5GHZ|CHANNEL_OFDM|CHANNEL_TURBO)
end_define

begin_define
define|#
directive|define
name|CHANNEL_ST
value|(CHANNEL_T|CHANNEL_STURBO)
end_define

begin_define
define|#
directive|define
name|CHANNEL_108G
value|(CHANNEL_2GHZ|CHANNEL_OFDM|CHANNEL_TURBO)
end_define

begin_define
define|#
directive|define
name|CHANNEL_108A
value|CHANNEL_T
end_define

begin_define
define|#
directive|define
name|CHANNEL_X
value|(CHANNEL_5GHZ|CHANNEL_OFDM|CHANNEL_XR)
end_define

begin_define
define|#
directive|define
name|CHANNEL_ALL
define|\
value|(CHANNEL_OFDM|CHANNEL_CCK| CHANNEL_2GHZ | CHANNEL_5GHZ | CHANNEL_TURBO)
end_define

begin_define
define|#
directive|define
name|CHANNEL_ALL_NOTURBO
value|(CHANNEL_ALL&~ CHANNEL_TURBO)
end_define

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
name|u_int32_t
name|ackrcv_bad
decl_stmt|;
name|u_int32_t
name|rts_bad
decl_stmt|;
name|u_int32_t
name|rts_good
decl_stmt|;
name|u_int32_t
name|fcs_bad
decl_stmt|;
name|u_int32_t
name|beacons
decl_stmt|;
block|}
name|HAL_MIB_STATS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|HAL_CTRY_CODE
typedef|;
end_typedef

begin_comment
comment|/* country code */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|HAL_REG_DOMAIN
typedef|;
end_typedef

begin_comment
comment|/* regulatory domain code */
end_comment

begin_enum
enum|enum
block|{
name|CTRY_DEBUG
init|=
literal|0x1ff
block|,
comment|/* debug country code */
name|CTRY_DEFAULT
init|=
literal|0
comment|/* default country code */
block|}
enum|;
end_enum

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
comment|/* 11a+Turbo channels */
name|HAL_MODE_108A
init|=
literal|0x040
block|,
comment|/* 11g+Turbo channels */
name|HAL_MODE_XR
init|=
literal|0x100
block|,
comment|/* XR channels */
name|HAL_MODE_11A_HALF_RATE
init|=
literal|0x200
block|,
comment|/* 11A half rate channels */
name|HAL_MODE_11A_QUARTER_RATE
init|=
literal|0x400
block|,
comment|/* 11A quarter rate channels */
name|HAL_MODE_ALL
init|=
literal|0xfff
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
name|u_int8_t
name|rateCodeToIndex
index|[
literal|32
index|]
decl_stmt|;
comment|/* back mapping */
struct|struct
block|{
name|u_int8_t
name|valid
decl_stmt|;
comment|/* valid for rate control use */
name|u_int8_t
name|phy
decl_stmt|;
comment|/* CCK/OFDM/XR */
name|u_int16_t
name|rateKbps
decl_stmt|;
comment|/* transfer rate in kbs */
name|u_int8_t
name|rateCode
decl_stmt|;
comment|/* rate for h/w descriptors */
name|u_int8_t
name|shortPreamble
decl_stmt|;
comment|/* mask for enabling short 						 * preamble in CCK rate code */
name|u_int8_t
name|dot11Rate
decl_stmt|;
comment|/* value for supported rates 						 * info element of MLME */
name|u_int8_t
name|controlRate
decl_stmt|;
comment|/* index of next lower basic 						 * rate; used for dur. calcs */
name|u_int16_t
name|lpAckDuration
decl_stmt|;
comment|/* long preamble ACK duration */
name|u_int16_t
name|spAckDuration
decl_stmt|;
comment|/* short preamble ACK duration*/
block|}
name|info
index|[
literal|32
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
name|u_int8_t
name|rs_rates
index|[
literal|32
index|]
decl_stmt|;
comment|/* rates */
block|}
name|HAL_RATE_SET
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
name|u_int8_t
name|kv_type
decl_stmt|;
comment|/* one of HAL_CIPHER */
name|u_int8_t
name|kv_pad
decl_stmt|;
name|u_int16_t
name|kv_len
decl_stmt|;
comment|/* length in bits */
name|u_int8_t
name|kv_val
index|[
literal|16
index|]
decl_stmt|;
comment|/* enough for 128-bit keys */
name|u_int8_t
name|kv_mic
index|[
literal|8
index|]
decl_stmt|;
comment|/* TKIP MIC key */
name|u_int8_t
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
name|u_int32_t
name|bs_nexttbtt
decl_stmt|;
comment|/* next beacon in TU */
name|u_int32_t
name|bs_nextdtim
decl_stmt|;
comment|/* next DTIM in TU */
name|u_int32_t
name|bs_intval
decl_stmt|;
comment|/* beacon interval+flags */
define|#
directive|define
name|HAL_BEACON_PERIOD
value|0x0000ffff
comment|/* beacon interval period */
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
name|u_int32_t
name|bs_dtimperiod
decl_stmt|;
name|u_int16_t
name|bs_cfpperiod
decl_stmt|;
comment|/* CFP period in TU */
name|u_int16_t
name|bs_cfpmaxduration
decl_stmt|;
comment|/* max CFP duration in TU */
name|u_int32_t
name|bs_cfpnext
decl_stmt|;
comment|/* next CFP in TU */
name|u_int16_t
name|bs_timoffset
decl_stmt|;
comment|/* byte offset to TIM bitmap */
name|u_int16_t
name|bs_bmissthreshold
decl_stmt|;
comment|/* beacon miss threshold */
name|u_int32_t
name|bs_sleepduration
decl_stmt|;
comment|/* max sleep duration */
block|}
name|HAL_BEACON_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Like HAL_BEACON_STATE but for non-station mode setup.  * NB: see above flag definitions   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|bt_intval
decl_stmt|;
comment|/* beacon interval+flags */
name|u_int32_t
name|bt_nexttbtt
decl_stmt|;
comment|/* next beacon in TU */
name|u_int32_t
name|bt_nextatim
decl_stmt|;
comment|/* next ATIM in TU */
name|u_int32_t
name|bt_nextdba
decl_stmt|;
comment|/* next DBA in 1/8th TU */
name|u_int32_t
name|bt_nextswba
decl_stmt|;
comment|/* next SWBA in 1/8th TU */
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
name|u_int32_t
name|ns_avgbrssi
decl_stmt|;
comment|/* average beacon rssi */
name|u_int32_t
name|ns_avgrssi
decl_stmt|;
comment|/* average data rssi */
name|u_int32_t
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

begin_comment
comment|/*  * Hardware Access Layer (HAL) API.  *  * Clients of the HAL call ath_hal_attach to obtain a reference to an  * ath_hal structure for use with the device.  Hardware-related operations  * that follow must call back into the HAL through interface, supplying  * the reference as the first parameter.  Note that before using the  * reference returned by ath_hal_attach the caller should verify the  * ABI version number.  */
end_comment

begin_struct
struct|struct
name|ath_hal
block|{
name|u_int32_t
name|ah_magic
decl_stmt|;
comment|/* consistency check magic number */
name|u_int32_t
name|ah_abi
decl_stmt|;
comment|/* HAL ABI version */
define|#
directive|define
name|HAL_ABI_VERSION
value|0x06102600
comment|/* YYMMDDnn */
name|u_int16_t
name|ah_devid
decl_stmt|;
comment|/* PCI device ID */
name|u_int16_t
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
name|u_int32_t
name|ah_macVersion
decl_stmt|;
comment|/* MAC version id */
name|u_int16_t
name|ah_macRev
decl_stmt|;
comment|/* MAC revision */
name|u_int16_t
name|ah_phyRev
decl_stmt|;
comment|/* PHY revision */
comment|/* NB: when only one radio is present the rev is in 5Ghz */
name|u_int16_t
name|ah_analog5GhzRev
decl_stmt|;
comment|/* 5GHz radio revision */
name|u_int16_t
name|ah_analog2GhzRev
decl_stmt|;
comment|/* 2GHz radio revision */
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
name|HAL_CHANNEL
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
name|HAL_CHANNEL
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
name|ah_setTxPowerLimit
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
comment|/* DFS support */
name|HAL_BOOL
name|__ahdecl
function_decl|(
modifier|*
name|ah_radarWait
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_CHANNEL
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
name|u_int32_t
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
name|u_int32_t
name|txdp
parameter_list|)
function_decl|;
name|u_int32_t
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
name|u_int
name|segLen
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
name|u_int32_t
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
comment|/* Receive Functions */
name|u_int32_t
name|__ahdecl
function_decl|(
modifier|*
name|ah_getRxDP
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
name|ah_setRxDP
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int32_t
name|rxdp
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
name|u_int32_t
name|filter0
parameter_list|,
name|u_int32_t
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
name|u_int32_t
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
name|u_int32_t
name|index
parameter_list|)
function_decl|;
name|u_int32_t
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
name|u_int32_t
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
name|u_int32_t
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
name|u_int32_t
name|phyAddr
parameter_list|,
name|struct
name|ath_desc
modifier|*
name|next
parameter_list|,
name|u_int64_t
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
name|HAL_CHANNEL
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
name|u_int32_t
name|capability
parameter_list|,
name|u_int32_t
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
name|u_int32_t
name|capability
parameter_list|,
name|u_int32_t
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
name|u_int32_t
name|argsize
parameter_list|,
name|void
modifier|*
modifier|*
name|result
parameter_list|,
name|u_int32_t
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
name|u_int8_t
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
name|u_int8_t
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
name|u_int8_t
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
name|u_int8_t
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
name|u_int16_t
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
name|u_int8_t
modifier|*
name|bssid
parameter_list|,
name|u_int16_t
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
name|u_int32_t
name|gpio
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
name|u_int32_t
name|gpio
parameter_list|)
function_decl|;
name|u_int32_t
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
name|u_int32_t
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
name|u_int32_t
name|gpio
parameter_list|,
name|u_int32_t
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
name|u_int32_t
parameter_list|)
function_decl|;
name|u_int32_t
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
name|u_int64_t
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
name|u_int16_t
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
name|u_int8_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Key Cache Functions */
name|u_int32_t
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
name|u_int16_t
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
name|u_int16_t
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
name|u_int16_t
parameter_list|,
specifier|const
name|HAL_KEYVAL
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
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
name|u_int16_t
parameter_list|,
specifier|const
name|u_int8_t
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
name|HAL_CHANNEL
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
name|u_int32_t
name|nexttbtt
parameter_list|,
name|u_int32_t
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
name|u_int16_t
name|vendorid
parameter_list|,
name|u_int16_t
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
name|u_int16_t
name|devid
parameter_list|,
name|HAL_SOFTC
parameter_list|,
name|HAL_BUS_TAG
parameter_list|,
name|HAL_BUS_HANDLE
parameter_list|,
name|HAL_STATUS
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the Vendor ID for Vendor SKU's which can modify the  * channel properties returned by ath_hal_init_channels.  * Return AH_TRUE if set succeeds  */
end_comment

begin_function_decl
specifier|extern
name|HAL_BOOL
name|__ahdecl
name|ath_hal_setvendor
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a list of channels available for use with the hardware.  * The list is based on what the hardware is capable of, the specified  * country code, the modeSelect mask, and whether or not outdoor  * channels are to be permitted.  *  * The channel list is returned in the supplied array.  maxchans  * defines the maximum size of this array.  nchans contains the actual  * number of channels returned.  If a problem occurred or there were  * no channels that met the criteria then AH_FALSE is returned.  */
end_comment

begin_function_decl
specifier|extern
name|HAL_BOOL
name|__ahdecl
name|ath_hal_init_channels
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_CHANNEL
modifier|*
name|chans
parameter_list|,
name|u_int
name|maxchans
parameter_list|,
name|u_int
modifier|*
name|nchans
parameter_list|,
name|u_int8_t
modifier|*
name|regclassids
parameter_list|,
name|u_int
name|maxregids
parameter_list|,
name|u_int
modifier|*
name|nregids
parameter_list|,
name|HAL_CTRY_CODE
name|cc
parameter_list|,
name|u_int16_t
name|modeSelect
parameter_list|,
name|HAL_BOOL
name|enableOutdoor
parameter_list|,
name|HAL_BOOL
name|enableExtendedChannels
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
parameter_list|,
name|HAL_CTRY_CODE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return rate table for specified mode (11a, 11b, 11g, etc).  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|__ahdecl
name|ath_hal_getratetable
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Calculate the transmit duration of a frame.  */
end_comment

begin_function_decl
specifier|extern
name|u_int16_t
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
name|u_int32_t
name|frameLen
parameter_list|,
name|u_int16_t
name|rateix
parameter_list|,
name|HAL_BOOL
name|shortPreamble
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return if device is public safety.  */
end_comment

begin_function_decl
specifier|extern
name|HAL_BOOL
name|__ahdecl
name|ath_hal_ispublicsafetysku
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert between IEEE channel number and channel frequency  * using the specified channel flags; e.g. CHANNEL_2GHZ.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__ahdecl
name|ath_hal_mhz2ieee
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|mhz
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a version string for the HAL release.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ath_hal_version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return a NULL-terminated array of build/configuration options.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ath_hal_buildopts
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_H_ */
end_comment

end_unit

