begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Marvell Semiconductor, Inc.  * Copyright (c) 2007 Sam Leffler, Errno Consulting  * Copyright (c) 2008 Weongyo Jeong<weongyo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MALOHAL_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MALOHAL_H
end_define

begin_define
define|#
directive|define
name|MALO_NUM_TX_QUEUES
value|1
end_define

begin_define
define|#
directive|define
name|MALO_MAX_TXWCB_QUEUES
value|MALO_NUM_TX_QUEUES
end_define

begin_comment
comment|/* size of f/w command buffer */
end_comment

begin_define
define|#
directive|define
name|MALO_CMDBUF_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|MALO_FW_CHECK_USECS
value|(5 * 1000)
end_define

begin_comment
comment|/* 5ms */
end_comment

begin_define
define|#
directive|define
name|MALO_FW_MAX_NUM_CHECKS
value|200
end_define

begin_comment
comment|/*  * Calibration data builtin to the firmware.  The firmware image  * has a single set of calibration tables that we retrieve right  * after download.  This can be overriden by the driver (e.g. for  * a different regdomain and/or tx power setup).  */
end_comment

begin_struct
struct|struct
name|malo_hal_caldata
block|{
comment|/* pt is short for `power target'.  */
define|#
directive|define
name|MALO_PWTAGETRATETABLE20M
value|(14 * 4)
name|uint8_t
name|pt_ratetable_20m
index|[
name|MALO_PWTAGETRATETABLE20M
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get Hardware/Firmware capabilities.  */
end_comment

begin_struct
struct|struct
name|malo_hal_hwspec
block|{
name|uint8_t
name|hwversion
decl_stmt|;
comment|/* version of the HW */
name|uint8_t
name|hostinterface
decl_stmt|;
comment|/* host interface */
name|uint16_t
name|maxnum_wcb
decl_stmt|;
comment|/* max # of WCB FW handles */
comment|/* max # of mcast addresses FW handles*/
name|uint16_t
name|maxnum_mcaddr
decl_stmt|;
name|uint16_t
name|maxnum_tx_wcb
decl_stmt|;
comment|/* max # of tx descs per WCB */
comment|/* MAC address programmed in HW */
name|uint8_t
name|macaddr
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|regioncode
decl_stmt|;
comment|/* EEPROM region code */
name|uint16_t
name|num_antenna
decl_stmt|;
comment|/* Number of antenna used */
name|uint32_t
name|fw_releasenum
decl_stmt|;
comment|/* firmware release number */
name|uint32_t
name|wcbbase0
decl_stmt|;
name|uint32_t
name|rxdesc_read
decl_stmt|;
name|uint32_t
name|rxdesc_write
decl_stmt|;
name|uint32_t
name|ul_fw_awakecookie
decl_stmt|;
name|uint32_t
name|wcbbase
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Supply tx/rx dma-related settings to the firmware.  */
end_comment

begin_struct
struct|struct
name|malo_hal_txrxdma
block|{
name|uint32_t
name|maxnum_wcb
decl_stmt|;
comment|/* max # of WCB FW handles */
name|uint32_t
name|maxnum_txwcb
decl_stmt|;
comment|/* max # of tx descs per WCB */
name|uint32_t
name|rxdesc_read
decl_stmt|;
name|uint32_t
name|rxdesc_write
decl_stmt|;
name|uint32_t
name|wcbbase
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get Hardware Statistics.  *  * Items marked with ! are deprecated and not ever updated.  In  * some cases this is because work has been moved to the host (e.g.  * rx defragmentation).  *  * XXX low/up cases.  */
end_comment

begin_struct
struct|struct
name|malo_hal_hwstats
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

begin_comment
comment|/*  * Set Antenna Configuration (legacy operation).  *  * The RX antenna can be selected using the the bitmask  * ant (bit 0 = antenna 1, bit 1 = antenna 2, etc.)  * (diversity?XXX)  */
end_comment

begin_enum
enum|enum
name|malo_hal_antenna
block|{
name|MHA_ANTENNATYPE_RX
init|=
literal|1
block|,
name|MHA_ANTENNATYPE_TX
init|=
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Set Radio Configuration.  *  * onoff != 0 turns radio on; otherwise off.  * if radio is enabled, the preamble is set too.  */
end_comment

begin_enum
enum|enum
name|malo_hal_preamble
block|{
name|MHP_LONG_PREAMBLE
init|=
literal|1
block|,
name|MHP_SHORT_PREAMBLE
init|=
literal|3
block|,
name|MHP_AUTO_PREAMBLE
init|=
literal|5
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|malo_hal_channel_flags
block|{
name|uint32_t
name|freqband
range|:
literal|6
decl_stmt|,
define|#
directive|define
name|MALO_FREQ_BAND_2DOT4GHZ
value|0x1
range|:
literal|26
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|malo_hal_channel
block|{
name|uint32_t
name|channel
decl_stmt|;
name|struct
name|malo_hal_channel_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|malo_hal_txrate
block|{
name|uint8_t
name|mcastrate
decl_stmt|;
comment|/* rate for multicast frames */
name|uint8_t
name|mgtrate
decl_stmt|;
comment|/* rate for management frames */
struct|struct
block|{
name|uint8_t
name|trycount
decl_stmt|;
comment|/* try this many times */
name|uint8_t
name|rate
decl_stmt|;
comment|/* use this tx rate */
block|}
name|rateseries
index|[
literal|4
index|]
struct|;
comment|/* rate series */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|malo_hal
block|{
name|device_t
name|mh_dev
decl_stmt|;
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
name|int
name|mh_flags
decl_stmt|;
define|#
directive|define
name|MHF_CALDATA
value|0x0001
comment|/* cal data retrieved */
define|#
directive|define
name|MHF_FWHANG
value|0x0002
comment|/* fw appears hung */
name|char
name|mh_mtxname
index|[
literal|12
index|]
decl_stmt|;
name|struct
name|mtx
name|mh_mtx
decl_stmt|;
name|bus_dma_tag_t
name|mh_dmat
decl_stmt|;
comment|/* bus DMA tag for cmd buffer */
name|bus_dmamap_t
name|mh_dmamap
decl_stmt|;
comment|/* DMA map for cmd buffer */
name|uint16_t
modifier|*
name|mh_cmdbuf
decl_stmt|;
comment|/* f/w cmd buffer */
name|bus_addr_t
name|mh_cmdaddr
decl_stmt|;
comment|/* physaddr of cmd buffer */
name|struct
name|malo_hal_caldata
name|mh_caldata
decl_stmt|;
name|int
name|mh_debug
decl_stmt|;
define|#
directive|define
name|MALO_HAL_DEBUG_SENDCMD
value|0x00000001
define|#
directive|define
name|MALO_HAL_DEBUG_CMDDONE
value|0x00000002
define|#
directive|define
name|MALO_HAL_DEBUG_IGNHANG
value|0X00000004
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MALO_HAL_LOCK
parameter_list|(
name|mh
parameter_list|)
value|mtx_lock(&mh->mh_mtx)
end_define

begin_define
define|#
directive|define
name|MALO_HAL_LOCK_ASSERT
parameter_list|(
name|mh
parameter_list|)
value|mtx_assert(&mh->mh_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|MALO_HAL_UNLOCK
parameter_list|(
name|mh
parameter_list|)
value|mtx_unlock(&mh->mh_mtx)
end_define

begin_function_decl
name|struct
name|malo_hal
modifier|*
name|malo_hal_attach
parameter_list|(
name|device_t
parameter_list|,
name|uint16_t
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_space_tag_t
parameter_list|,
name|bus_dma_tag_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_fwload
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_gethwspecs
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|struct
name|malo_hal_hwspec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malo_hal_detach
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malo_hal_intrset
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_setantenna
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|enum
name|malo_hal_antenna
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_setradio
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|malo_hal_preamble
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_setchannel
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|malo_hal_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_setmaxtxpwr
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_settxpower
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|malo_hal_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_setpromisc
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_setassocid
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[]
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malo_hal_txstart
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malo_hal_getisr
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malo_hal_cmddone
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_prescan
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_postscan
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_set_slot
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_set_rate
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_hal_setmcast
parameter_list|(
name|struct
name|malo_hal
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|uint8_t
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

