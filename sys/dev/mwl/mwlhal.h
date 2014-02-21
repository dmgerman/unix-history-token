begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2007-2009 Marvell Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MWL_HAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MWL_HAL_H_
end_define

begin_comment
comment|/*  * Hardware Access Layer for Marvell Wireless Devices.  */
end_comment

begin_define
define|#
directive|define
name|MWL_MBSS_SUPPORT
end_define

begin_comment
comment|/* enable multi-bss support */
end_comment

begin_comment
comment|/*  * Define total number of TX queues in the shared memory.  * This count includes the EDCA queues, Block Ack queues, and HCCA queues  * In addition to this, there could be a management packet queue some   * time in the future  */
end_comment

begin_define
define|#
directive|define
name|MWL_NUM_EDCA_QUEUES
value|4
end_define

begin_define
define|#
directive|define
name|MWL_NUM_HCCA_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|MWL_NUM_BA_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|MWL_NUM_MGMT_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|MWL_NUM_ACK_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|MWL_NUM_TX_QUEUES
define|\
value|(MWL_NUM_EDCA_QUEUES + MWL_NUM_HCCA_QUEUES + MWL_NUM_BA_QUEUES + \ 	 MWL_NUM_MGMT_QUEUES + MWL_NUM_ACK_QUEUES)
end_define

begin_define
define|#
directive|define
name|MWL_MAX_RXWCB_QUEUES
value|1
end_define

begin_define
define|#
directive|define
name|MWL_MAX_SUPPORTED_RATES
value|12
end_define

begin_define
define|#
directive|define
name|MWL_MAX_SUPPORTED_MCS
value|32
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|MWL_HAL_OK
block|}
name|MWL_HAL_STATUS
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit queue assignment.  */
end_comment

begin_enum
enum|enum
block|{
name|MWL_WME_AC_BK
init|=
literal|0
block|,
comment|/* background access category */
name|MWL_WME_AC_BE
init|=
literal|1
block|,
comment|/* best effort access category*/
name|MWL_WME_AC_VI
init|=
literal|2
block|,
comment|/* video access category */
name|MWL_WME_AC_VO
init|=
literal|3
block|,
comment|/* voice access category */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|device
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|mwl_hal
block|{
name|bus_space_handle_t
name|mh_ioh
decl_stmt|;
comment|/* BAR 1 copied from softc */
name|bus_space_tag_t
name|mh_iot
decl_stmt|;
name|uint32_t
name|mh_imask
decl_stmt|;
comment|/* interrupt mask */
comment|/* remainder is opaque to driver */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|mwl_hal
modifier|*
name|mwl_hal_attach
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
name|uint16_t
name|devid
parameter_list|,
name|bus_space_handle_t
name|ioh
parameter_list|,
name|bus_space_tag_t
name|iot
parameter_list|,
name|bus_dma_tag_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mwl_hal_detach
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Query whether multi-bss support is available/enabled.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_ismbsscapable
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|MWL_HAL_AP
block|,
name|MWL_HAL_STA
block|,
comment|/* infrastructure mode */
name|MWL_HAL_IBSS
comment|/* ibss/adhoc mode */
block|}
name|MWL_HAL_BSSTYPE
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|mwl_hal_vap
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|mwl_hal_vap
modifier|*
name|mwl_hal_newvap
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|MWL_HAL_BSSTYPE
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[
literal|6
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mwl_hal_delvap
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|MWL_HAL_DEBUG_SENDCMD
init|=
literal|0x00000001
block|,
name|MWL_HAL_DEBUG_CMDDONE
init|=
literal|0x00000002
block|,
name|MWL_HAL_DEBUG_IGNHANG
init|=
literal|0x00000004
block|, }
enum|;
end_enum

begin_function_decl
name|void
name|mwl_hal_setdebug
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_getdebug
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|freqLow
decl_stmt|,
name|freqHigh
decl_stmt|;
name|int
name|nchannels
decl_stmt|;
struct|struct
name|mwl_hal_channel
block|{
name|uint16_t
name|freq
decl_stmt|;
comment|/* channel center */
name|uint8_t
name|ieee
decl_stmt|;
comment|/* channel number */
name|int8_t
name|maxTxPow
decl_stmt|;
comment|/* max tx power (dBm) */
name|uint8_t
name|targetPowers
index|[
literal|4
index|]
decl_stmt|;
comment|/* target powers (dBm) */
define|#
directive|define
name|MWL_HAL_MAXCHAN
value|40
block|}
name|channels
index|[
name|MWL_HAL_MAXCHAN
index|]
struct|;
block|}
name|MWL_HAL_CHANNELINFO
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_getchannelinfo
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|int
name|band
parameter_list|,
name|int
name|chw
parameter_list|,
specifier|const
name|MWL_HAL_CHANNELINFO
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the current ISR setting and clear the cause.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mwl_hal_getisr
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|uint32_t
modifier|*
name|status
parameter_list|)
block|{
define|#
directive|define
name|MACREG_REG_A2H_INTERRUPT_CAUSE
value|0x00000C30
comment|// (From ARM to host)
define|#
directive|define
name|MACREG_REG_INT_CODE
value|0x00000C14
name|uint32_t
name|cause
decl_stmt|;
name|cause
operator|=
name|bus_space_read_4
argument_list|(
name|mh
operator|->
name|mh_iot
argument_list|,
name|mh
operator|->
name|mh_ioh
argument_list|,
name|MACREG_REG_A2H_INTERRUPT_CAUSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|cause
operator|==
literal|0xffffffff
condition|)
block|{
comment|/* card removed */
name|cause
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cause
operator|!=
literal|0
condition|)
block|{
comment|/* clear cause bits */
name|bus_space_write_4
argument_list|(
name|mh
operator|->
name|mh_iot
argument_list|,
name|mh
operator|->
name|mh_ioh
argument_list|,
name|MACREG_REG_A2H_INTERRUPT_CAUSE
argument_list|,
name|cause
operator|&
operator|~
name|mh
operator|->
name|mh_imask
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|bus_space_read_4
argument_list|(
name|mh
operator|->
name|mh_iot
argument_list|,
name|mh
operator|->
name|mh_ioh
argument_list|,
name|MACREG_REG_INT_CODE
argument_list|)
expr_stmt|;
name|cause
operator|&=
name|mh
operator|->
name|mh_imask
expr_stmt|;
block|}
operator|*
name|status
operator|=
name|cause
expr_stmt|;
undef|#
directive|undef
name|MACREG_REG_INT_CODE
undef|#
directive|undef
name|MACREG_REG_A2H_INTERRUPT_CAUSE
block|}
end_function

begin_function_decl
name|void
name|mwl_hal_intrset
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Kick the firmware to tell it there are new tx descriptors  * for processing.  The driver says what h/w q has work in  * case the f/w ever gets smarter.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mwl_hal_txstart
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|qnum
parameter_list|)
block|{
define|#
directive|define
name|MACREG_REG_H2A_INTERRUPT_EVENTS
value|0x00000C18
comment|// (From host to ARM)
define|#
directive|define
name|MACREG_H2ARIC_BIT_PPA_READY
value|0x00000001
comment|// bit 0
define|#
directive|define
name|MACREG_REG_INT_CODE
value|0x00000C14
name|bus_space_write_4
argument_list|(
name|mh
operator|->
name|mh_iot
argument_list|,
name|mh
operator|->
name|mh_ioh
argument_list|,
name|MACREG_REG_H2A_INTERRUPT_EVENTS
argument_list|,
name|MACREG_H2ARIC_BIT_PPA_READY
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|bus_space_read_4
argument_list|(
name|mh
operator|->
name|mh_iot
argument_list|,
name|mh
operator|->
name|mh_ioh
argument_list|,
name|MACREG_REG_INT_CODE
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|MACREG_REG_INT_CODE
undef|#
directive|undef
name|MACREG_H2ARIC_BIT_PPA_READY
undef|#
directive|undef
name|MACREG_REG_H2A_INTERRUPT_EVENTS
block|}
end_function

begin_function_decl
name|void
name|mwl_hal_cmddone
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|FreqBand
range|:
literal|6
decl_stmt|,
define|#
directive|define
name|MWL_FREQ_BAND_2DOT4GHZ
value|0x1
define|#
directive|define
name|MWL_FREQ_BAND_5GHZ
value|0x4
name|ChnlWidth
range|:
literal|5
decl_stmt|,
define|#
directive|define
name|MWL_CH_10_MHz_WIDTH
value|0x1
define|#
directive|define
name|MWL_CH_20_MHz_WIDTH
value|0x2
define|#
directive|define
name|MWL_CH_40_MHz_WIDTH
value|0x4
name|ExtChnlOffset
range|:
literal|2
decl_stmt|,
define|#
directive|define
name|MWL_EXT_CH_NONE
value|0x0
define|#
directive|define
name|MWL_EXT_CH_ABOVE_CTRL_CH
value|0x1
define|#
directive|define
name|MWL_EXT_CH_BELOW_CTRL_CH
value|0x3
range|:
literal|19
decl_stmt|;
comment|/* reserved */
block|}
name|MWL_HAL_CHANNEL_FLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|channel
decl_stmt|;
name|MWL_HAL_CHANNEL_FLAGS
name|channelFlags
decl_stmt|;
block|}
name|MWL_HAL_CHANNEL
typedef|;
end_typedef

begin_comment
comment|/*  * Get Hardware/Firmware capabilities.  */
end_comment

begin_struct
struct|struct
name|mwl_hal_hwspec
block|{
name|uint8_t
name|hwVersion
decl_stmt|;
comment|/* version of the HW */
name|uint8_t
name|hostInterface
decl_stmt|;
comment|/* host interface */
name|uint16_t
name|maxNumWCB
decl_stmt|;
comment|/* max # of WCB FW handles */
name|uint16_t
name|maxNumMCAddr
decl_stmt|;
comment|/* max # of mcast addresses FW handles*/
name|uint16_t
name|maxNumTxWcb
decl_stmt|;
comment|/* max # of tx descs per WCB */
name|uint8_t
name|macAddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* MAC address programmed in HW */
name|uint16_t
name|regionCode
decl_stmt|;
comment|/* EEPROM region code */
name|uint16_t
name|numAntennas
decl_stmt|;
comment|/* Number of antenna used */
name|uint32_t
name|fwReleaseNumber
decl_stmt|;
comment|/* firmware release number */
name|uint32_t
name|wcbBase0
decl_stmt|;
name|uint32_t
name|rxDescRead
decl_stmt|;
name|uint32_t
name|rxDescWrite
decl_stmt|;
name|uint32_t
name|ulFwAwakeCookie
decl_stmt|;
name|uint32_t
name|wcbBase
index|[
name|MWL_NUM_TX_QUEUES
operator|-
name|MWL_NUM_ACK_QUEUES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|mwl_hal_gethwspecs
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|struct
name|mwl_hal_hwspec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Supply tx/rx dma-related settings to the firmware.  */
end_comment

begin_struct
struct|struct
name|mwl_hal_txrxdma
block|{
name|uint32_t
name|maxNumWCB
decl_stmt|;
comment|/* max # of WCB FW handles */
name|uint32_t
name|maxNumTxWcb
decl_stmt|;
comment|/* max # of tx descs per WCB */
name|uint32_t
name|rxDescRead
decl_stmt|;
name|uint32_t
name|rxDescWrite
decl_stmt|;
name|uint32_t
name|wcbBase
index|[
name|MWL_NUM_TX_QUEUES
operator|-
name|MWL_NUM_ACK_QUEUES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|mwl_hal_sethwdma
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
specifier|const
name|struct
name|mwl_hal_txrxdma
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get Hardware Statistics.  *  * Items marked with ! are deprecated and not ever updated.  In  * some cases this is because work has been moved to the host (e.g.  * rx defragmentation).  */
end_comment

begin_struct
struct|struct
name|mwl_hal_hwstats
block|{
name|uint32_t
name|TxRetrySuccesses
decl_stmt|;
comment|/* tx success w/ 1 retry */
name|uint32_t
name|TxMultipleRetrySuccesses
decl_stmt|;
comment|/* tx success w/>1 retry */
name|uint32_t
name|TxFailures
decl_stmt|;
comment|/* tx fail due to no ACK */
name|uint32_t
name|RTSSuccesses
decl_stmt|;
comment|/* CTS rx'd for RTS */
name|uint32_t
name|RTSFailures
decl_stmt|;
comment|/* CTS not rx'd for RTS */
name|uint32_t
name|AckFailures
decl_stmt|;
comment|/* same as TxFailures */
name|uint32_t
name|RxDuplicateFrames
decl_stmt|;
comment|/* rx discard for dup seqno */
name|uint32_t
name|FCSErrorCount
decl_stmt|;
comment|/* rx discard for bad FCS */
name|uint32_t
name|TxWatchDogTimeouts
decl_stmt|;
comment|/* MAC tx hang (f/w recovery) */
name|uint32_t
name|RxOverflows
decl_stmt|;
comment|/* no f/w buffer for rx data */
name|uint32_t
name|RxFragErrors
decl_stmt|;
comment|/* !rx fail due to defrag */
name|uint32_t
name|RxMemErrors
decl_stmt|;
comment|/* out of mem or desc corrupted 						   in some way */
name|uint32_t
name|RxPointerErrors
decl_stmt|;
comment|/* MAC internal ptr problem */
name|uint32_t
name|TxUnderflows
decl_stmt|;
comment|/* !tx underflow on dma */
name|uint32_t
name|TxDone
decl_stmt|;
comment|/* MAC tx ops completed 						   (possibly w/ error) */
name|uint32_t
name|TxDoneBufTryPut
decl_stmt|;
comment|/* ! */
name|uint32_t
name|TxDoneBufPut
decl_stmt|;
comment|/* same as TxDone */
name|uint32_t
name|Wait4TxBuf
decl_stmt|;
comment|/* !no f/w buf avail when 						    supplied a tx descriptor */
name|uint32_t
name|TxAttempts
decl_stmt|;
comment|/* tx descriptors processed */
name|uint32_t
name|TxSuccesses
decl_stmt|;
comment|/* tx attempts successful */
name|uint32_t
name|TxFragments
decl_stmt|;
comment|/* tx with fragmentation */
name|uint32_t
name|TxMulticasts
decl_stmt|;
comment|/* tx multicast frames */
name|uint32_t
name|RxNonCtlPkts
decl_stmt|;
comment|/* rx non-control frames */
name|uint32_t
name|RxMulticasts
decl_stmt|;
comment|/* rx multicast frames */
name|uint32_t
name|RxUndecryptableFrames
decl_stmt|;
comment|/* rx failed due to crypto */
name|uint32_t
name|RxICVErrors
decl_stmt|;
comment|/* rx failed due to ICV check */
name|uint32_t
name|RxExcludedFrames
decl_stmt|;
comment|/* rx discarded, e.g. bssid */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|mwl_hal_gethwstats
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|struct
name|mwl_hal_hwstats
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set HT Guard Interval.  *  * GIType = 0:	enable long and short GI  * GIType = 1:	enable short GI  * GIType = 2:	enable long GI  */
end_comment

begin_function_decl
name|int
name|mwl_hal_sethtgi
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|int
name|GIType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set Radio Configuration.  *  * onoff != 0 turns radio on; otherwise off.  * if radio is enabled, the preamble is set too.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|WL_LONG_PREAMBLE
init|=
literal|1
block|,
name|WL_SHORT_PREAMBLE
init|=
literal|3
block|,
name|WL_AUTO_PREAMBLE
init|=
literal|5
block|, }
name|MWL_HAL_PREAMBLE
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_setradio
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|onoff
parameter_list|,
name|MWL_HAL_PREAMBLE
name|preamble
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set Antenna Configuration (legacy operation).  *  * The RX antenna can be selected using the bitmask  * ant (bit 0 = antenna 1, bit 1 = antenna 2, etc.)  * (diversity?XXX)  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|WL_ANTENNATYPE_RX
init|=
literal|1
block|,
name|WL_ANTENNATYPE_TX
init|=
literal|2
block|, }
name|MWL_HAL_ANTENNA
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_setantenna
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|MWL_HAL_ANTENNA
name|dirSet
parameter_list|,
name|int
name|ant
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the threshold for using RTS on TX.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setrtsthreshold
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|int
name|threshold
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the adapter to operate in infrastructure mode.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setinframode
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set Radar Detection Configuration.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DR_DFS_DISABLE
init|=
literal|0
block|,
name|DR_CHK_CHANNEL_AVAILABLE_START
init|=
literal|1
block|,
name|DR_CHK_CHANNEL_AVAILABLE_STOP
init|=
literal|2
block|,
name|DR_IN_SERVICE_MONITOR_START
init|=
literal|3
block|}
name|MWL_HAL_RADAR
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_setradardetection
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|MWL_HAL_RADAR
name|action
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the region code that selects the radar bin'ing agorithm.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setregioncode
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|regionCode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initiate an 802.11h-based channel switch.  The CSA ie  * is included in the next beacon(s) using the specified  * information and the firmware counts down until switch  * time after which it notifies the driver by delivering  * an interrupt with MACREG_A2HRIC_BIT_CHAN_SWITCH set in  * the cause register.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setchannelswitchie
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
specifier|const
name|MWL_HAL_CHANNEL
modifier|*
name|nextchan
parameter_list|,
name|uint32_t
name|mode
parameter_list|,
name|uint32_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set regdomain code (IEEE SKU).  */
end_comment

begin_enum
enum|enum
block|{
name|DOMAIN_CODE_FCC
init|=
literal|0x10
block|,
comment|/* USA */
name|DOMAIN_CODE_IC
init|=
literal|0x20
block|,
comment|/* Canda */
name|DOMAIN_CODE_ETSI
init|=
literal|0x30
block|,
comment|/* Europe */
name|DOMAIN_CODE_SPAIN
init|=
literal|0x31
block|,
comment|/* Spain */
name|DOMAIN_CODE_FRANCE
init|=
literal|0x32
block|,
comment|/* France */
name|DOMAIN_CODE_ETSI_131
init|=
literal|0x130
block|,
comment|/* ETSI w/ 1.3.1 radar type */
name|DOMAIN_CODE_MKK
init|=
literal|0x40
block|,
comment|/* Japan */
name|DOMAIN_CODE_MKK2
init|=
literal|0x41
block|,
comment|/* Japan w/ 10MHz chan spacing */
name|DOMAIN_CODE_DGT
init|=
literal|0x80
block|,
comment|/* Taiwan */
name|DOMAIN_CODE_AUS
init|=
literal|0x81
block|,
comment|/* Australia */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Transmit rate control.  Rate codes with bit 0x80 set are  * interpreted as MCS codes (this limits us to 0-127).  The  * transmit rate can be set to a single fixed rate or can  * be configured to start at an initial rate and drop based  * on retry counts.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|RATE_AUTO
init|=
literal|0
block|,
comment|/* rate selected by firmware */
name|RATE_FIXED
init|=
literal|2
block|,
comment|/* rate fixed */
name|RATE_FIXED_DROP
init|=
literal|1
block|,
comment|/* rate starts fixed but may drop */
block|}
name|MWL_HAL_TXRATE_HANDLING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|McastRate
decl_stmt|;
comment|/* rate for multicast frames */
define|#
directive|define
name|RATE_MCS
value|0x80
comment|/* rate is an MCS index */
name|uint8_t
name|MgtRate
decl_stmt|;
comment|/* rate for management frames */
struct|struct
block|{
name|uint8_t
name|TryCount
decl_stmt|;
comment|/* try this many times */
name|uint8_t
name|Rate
decl_stmt|;
comment|/* use this tx rate */
block|}
name|RateSeries
index|[
literal|4
index|]
struct|;
comment|/* rate series */
block|}
name|MWL_HAL_TXRATE
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_settxrate
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|MWL_HAL_TXRATE_HANDLING
name|handling
parameter_list|,
specifier|const
name|MWL_HAL_TXRATE
modifier|*
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NB: hack for setting rates while scanning */
end_comment

begin_function_decl
name|int
name|mwl_hal_settxrate_auto
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
specifier|const
name|MWL_HAL_TXRATE
modifier|*
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the Slot Time Configuration.  * NB: usecs must either be 9 or 20 for now.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setslottime
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|usecs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Adjust current transmit power settings according to powerLevel.  * This translates to low/medium/high use of the current tx power rate tables.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_adjusttxpower
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|uint32_t
name|powerLevel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the transmit power for the specified channel; the power  * is taken from the calibration data and capped according to  * the specified max tx power (in dBm).  */
end_comment

begin_function_decl
name|int
name|mwl_hal_settxpower
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
specifier|const
name|MWL_HAL_CHANNEL
modifier|*
parameter_list|,
name|uint8_t
name|maxtxpow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the Multicast Address Filter.  * A packed array addresses is specified.  */
end_comment

begin_define
define|#
directive|define
name|MWL_HAL_MCAST_MAX
value|32
end_define

begin_function_decl
name|int
name|mwl_hal_setmcast
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|nmc
parameter_list|,
specifier|const
name|uint8_t
name|macs
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Crypto Configuration.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pad
decl_stmt|;
name|uint16_t
name|keyTypeId
decl_stmt|;
define|#
directive|define
name|KEY_TYPE_ID_WEP
value|0
define|#
directive|define
name|KEY_TYPE_ID_TKIP
value|1
define|#
directive|define
name|KEY_TYPE_ID_AES
value|2
comment|/* AES-CCMP */
name|uint32_t
name|keyFlags
decl_stmt|;
define|#
directive|define
name|KEY_FLAG_INUSE
value|0x00000001
comment|/* indicate key is in use */
define|#
directive|define
name|KEY_FLAG_RXGROUPKEY
value|0x00000002
comment|/* Group key for RX only */
define|#
directive|define
name|KEY_FLAG_TXGROUPKEY
value|0x00000004
comment|/* Group key for TX */
define|#
directive|define
name|KEY_FLAG_PAIRWISE
value|0x00000008
comment|/* pairwise */
define|#
directive|define
name|KEY_FLAG_RXONLY
value|0x00000010
comment|/* only used for RX */
define|#
directive|define
name|KEY_FLAG_AUTHENTICATOR
value|0x00000020
comment|/* Key is for Authenticator */
define|#
directive|define
name|KEY_FLAG_TSC_VALID
value|0x00000040
comment|/* Sequence counters valid */
define|#
directive|define
name|KEY_FLAG_WEP_TXKEY
value|0x01000000
comment|/* Tx key for WEP */
define|#
directive|define
name|KEY_FLAG_MICKEY_VALID
value|0x02000000
comment|/* Tx/Rx MIC keys are valid */
name|uint32_t
name|keyIndex
decl_stmt|;
comment|/* for WEP only; actual key index */
name|uint16_t
name|keyLen
decl_stmt|;
comment|/* key size in bytes */
union|union
block|{
comment|/* key material, keyLen gives size */
name|uint8_t
name|wep
index|[
literal|16
index|]
decl_stmt|;
comment|/* enough for 128 bits */
name|uint8_t
name|aes
index|[
literal|16
index|]
decl_stmt|;
struct|struct
block|{
comment|/* NB: group or pairwise key is determined by keyFlags */
name|uint8_t
name|keyMaterial
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|txMic
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|rxMic
index|[
literal|8
index|]
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|low
decl_stmt|;
name|uint32_t
name|high
decl_stmt|;
block|}
name|rsc
struct|;
struct|struct
block|{
name|uint16_t
name|low
decl_stmt|;
name|uint32_t
name|high
decl_stmt|;
block|}
name|tsc
struct|;
block|}
name|__packed
name|tkip
struct|;
block|}
name|__packed
name|key
union|;
block|}
name|__packed
name|MWL_HAL_KEYVAL
typedef|;
end_typedef

begin_comment
comment|/*  * Plumb a unicast/group key.  The mac address identifies  * the station, use the broadcast address for group keys.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_keyset
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
specifier|const
name|MWL_HAL_KEYVAL
modifier|*
name|kv
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[
literal|6
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Plumb a unicast/group key.  The mac address identifies  * the station, use the broadcast address for group keys.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_keyreset
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
specifier|const
name|MWL_HAL_KEYVAL
modifier|*
name|kv
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[
literal|6
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the MAC address.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setmac
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|addr
index|[
literal|6
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the beacon frame contents.  The firmware will modify the  * frame only to add CSA and WME ie's and to fill in dynamic fields  * such as the sequence #..  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setbeacon
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Handle power save operation for AP operation when offloaded to  * the host (SET_HW_SPEC_HOST_POWERSAVE).  mwl_hal_setbss_powersave  * informs the firmware whether 1+ associated stations are in power  * save mode (it will then buffer mcast traffic). mwl_hal_setsta_powersave  * specifies a change in power save state for an associated station.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setpowersave_bss
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|uint8_t
name|nsta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_setpowersave_sta
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|uint16_t
name|aid
parameter_list|,
name|int
name|ena
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set Association Configuration for station operation.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setassocid
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|bssId
index|[
literal|6
index|]
parameter_list|,
name|uint16_t
name|assocId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the current channel.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setchannel
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
specifier|const
name|MWL_HAL_CHANNEL
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A-MPDU Block Ack (BA) stream support.  There are several  * streams that the driver must multiplex.  Once assigned  * to a station the driver queues frames to a corresponding  * transmit queue and the firmware handles all the work.  *  * XXX no way to find out how many streams are supported  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|data
index|[
literal|2
index|]
decl_stmt|;
comment|/* opaque data */
name|int
name|txq
decl_stmt|;
block|}
name|MWL_HAL_BASTREAM
typedef|;
end_typedef

begin_function_decl
specifier|const
name|MWL_HAL_BASTREAM
modifier|*
name|mwl_hal_bastream_alloc
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|int
name|ba_type
parameter_list|,
specifier|const
name|uint8_t
name|Macaddr
index|[
literal|6
index|]
parameter_list|,
name|uint8_t
name|Tid
parameter_list|,
name|uint8_t
name|ParamInfo
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|MWL_HAL_BASTREAM
modifier|*
name|mwl_hal_bastream_lookup
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_bastream_create
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
specifier|const
name|MWL_HAL_BASTREAM
modifier|*
parameter_list|,
name|int
name|BarThrs
parameter_list|,
name|int
name|WindowSize
parameter_list|,
name|uint16_t
name|seqno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_bastream_destroy
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
specifier|const
name|MWL_HAL_BASTREAM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_getwatchdogbitmap
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|uint8_t
name|bitmap
index|[
literal|1
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_bastream_get_seqno
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
specifier|const
name|MWL_HAL_BASTREAM
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|Macaddr
index|[
literal|6
index|]
parameter_list|,
name|uint16_t
modifier|*
name|pseqno
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* for sysctl hookup for debugging */
end_comment

begin_function_decl
name|void
name|mwl_hal_setbastreams
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_getbastreams
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set/get A-MPDU aggregation parameters.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setaggampduratemode
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|thresh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_getaggampduratemode
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|int
modifier|*
name|mode
parameter_list|,
name|int
modifier|*
name|thresh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Inform the firmware of a new association station.  * The address is the MAC address of the peer station.  * The AID is supplied sans the 0xc000 bits.  The station  * ID is defined by the caller.  The peer information must  * be supplied.  *  * NB: All values are in host byte order; any byte swapping  *     is handled by the hal.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|LegacyRateBitMap
decl_stmt|;
name|uint32_t
name|HTRateBitMap
decl_stmt|;
name|uint16_t
name|CapInfo
decl_stmt|;
name|uint16_t
name|HTCapabilitiesInfo
decl_stmt|;
name|uint8_t
name|MacHTParamInfo
decl_stmt|;
name|uint8_t
name|Rev
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|ControlChan
decl_stmt|;
name|uint8_t
name|AddChan
decl_stmt|;
name|uint8_t
name|OpMode
decl_stmt|;
name|uint8_t
name|stbc
decl_stmt|;
block|}
name|__packed
name|AddHtInfo
struct|;
block|}
name|__packed
name|MWL_HAL_PEERINFO
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_newstation
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|addr
index|[
literal|6
index|]
parameter_list|,
name|uint16_t
name|aid
parameter_list|,
name|uint16_t
name|sid
parameter_list|,
specifier|const
name|MWL_HAL_PEERINFO
modifier|*
parameter_list|,
name|int
name|isQosSta
parameter_list|,
name|int
name|wmeInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_delstation
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|addr
index|[
literal|6
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Prod the firmware to age packets on station power  * save queues and reap frames on the tx aggregation q's.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setkeepalive
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|AP_MODE_B_ONLY
init|=
literal|1
block|,
name|AP_MODE_G_ONLY
init|=
literal|2
block|,
name|AP_MODE_MIXED
init|=
literal|3
block|,
name|AP_MODE_N_ONLY
init|=
literal|4
block|,
name|AP_MODE_BandN
init|=
literal|5
block|,
name|AP_MODE_GandN
init|=
literal|6
block|,
name|AP_MODE_BandGandN
init|=
literal|7
block|,
name|AP_MODE_A_ONLY
init|=
literal|8
block|,
name|AP_MODE_AandG
init|=
literal|10
block|,
name|AP_MODE_AandN
init|=
literal|12
block|, }
name|MWL_HAL_APMODE
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_setapmode
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|MWL_HAL_APMODE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable/disable firmware operation.  mwl_hal_start is  * also used to sync state updates, e.g. beacon frame  * reconstruction after content changes.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_stop
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_start
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add/Remove station from Power Save TIM handling.  *  * If set is non-zero the AID is enabled, if zero it is removed.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_updatetim
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|uint16_t
name|aid
parameter_list|,
name|int
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable/disable 11g protection use.  This call specifies  * the ERP information element flags to use.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setgprot
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable/disable WMM support.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setwmm
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|onoff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Configure WMM EDCA parameters for the specified h/w ring.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setedcaparams
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|uint8_t
name|qnum
parameter_list|,
name|uint32_t
name|CWmin
parameter_list|,
name|uint32_t
name|CWmax
parameter_list|,
name|uint8_t
name|AIFSN
parameter_list|,
name|uint16_t
name|TXOPLimit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Configure rate adaptation for indooor/outdoor operation.  * XXX wtf?  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setrateadaptmode
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|uint16_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|CSMODE_CONSERVATIVE
init|=
literal|0
block|,
name|CSMODE_AGGRESSIVE
init|=
literal|1
block|,
name|CSMODE_AUTO_ENA
init|=
literal|2
block|,
name|CSMODE_AUTO_DIS
init|=
literal|3
block|, }
name|MWL_HAL_CSMODE
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_setcsmode
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|MWL_HAL_CSMODE
name|csmode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Configure 11n protection on/off.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HTPROTECT_NONE
init|=
literal|0
block|,
comment|/* disable */
name|HTPROTECT_OPT
init|=
literal|1
block|,
comment|/* optional */
name|HTPROTECT_HT20
init|=
literal|2
block|,
comment|/* protect only HT20 */
name|HTPROTECT_HT2040
init|=
literal|3
block|,
comment|/* protect HT20/40 */
name|HTPROTECT_AUTO
init|=
literal|4
block|,
comment|/* automatic */
block|}
name|MWL_HAL_HTPROTECT
typedef|;
end_typedef

begin_function_decl
name|int
name|mwl_hal_setnprot
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|MWL_HAL_HTPROTECT
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Configure 11n protection mechanism for when protection is enabled.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setnprotmode
parameter_list|(
name|struct
name|mwl_hal_vap
modifier|*
parameter_list|,
name|uint8_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable/disable Marvell "turbo mode"".  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setoptimizationlevel
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|int
name|onoff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set MIMO Power Save handling for a station; the enable and mode  * values come directly from the Action frame.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setmimops
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
specifier|const
name|uint8_t
name|addr
index|[
literal|6
index|]
parameter_list|,
name|uint8_t
name|enable
parameter_list|,
name|uint8_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Retrieve the region/country code from the EEPROM.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_getregioncode
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|uint8_t
modifier|*
name|countryCode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_GetBeacon
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|uint8_t
modifier|*
name|pBcn
parameter_list|,
name|uint16_t
modifier|*
name|pLen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_SetRifs
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|uint8_t
name|QNum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set/get promiscuous mode.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setpromisc
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|int
name|ena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_hal_getpromisc
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable/disable CF-End use.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setcfend
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|int
name|ena
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable/disable sta-mode DWDS use/operation.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_setdwds
parameter_list|(
name|struct
name|mwl_hal
modifier|*
parameter_list|,
name|int
name|ena
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Diagnostic interface.  This is an open-ended interface that  * is opaque to applications.  Diagnostic programs use this to  * retrieve internal data structures, etc.  There is no guarantee  * that calling conventions for calls other than MWL_DIAG_REVS  * are stable between HAL releases; a diagnostic application must  * use the HAL revision information to deal with ABI/API differences.  */
end_comment

begin_function_decl
name|int
name|mwl_hal_getdiagstate
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
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
end_function_decl

begin_function_decl
name|int
name|mwl_hal_fwload
parameter_list|(
name|struct
name|mwl_hal
modifier|*
name|mh
parameter_list|,
name|void
modifier|*
name|fwargs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MWL_HAL_H_ */
end_comment

end_unit

