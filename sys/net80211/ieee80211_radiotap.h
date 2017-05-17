begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: ieee80211_radiotap.h,v 1.16 2007/01/06 05:51:15 dyoung Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003, 2004 David Young.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of David Young may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY DAVID YOUNG ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL DAVID  * YOUNG BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_RADIOTAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_RADIOTAP_H_
end_define

begin_comment
comment|/* A generic radio capture format is desirable. It must be  * rigidly defined (e.g., units for fields should be given),  * and easily extensible.  *  * The following is an extensible radio capture format. It is  * based on a bitmap indicating which fields are present.  *  * I am trying to describe precisely what the application programmer  * should expect in the following, and for that reason I tell the  * units and origin of each measurement (where it applies), or else I  * use sufficiently weaselly language ("is a monotonically nondecreasing  * function of...") that I cannot set false expectations for lawyerly  * readers.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|DLT_IEEE802_11_RADIO
end_ifndef

begin_define
define|#
directive|define
name|DLT_IEEE802_11_RADIO
value|127
end_define

begin_comment
comment|/* 802.11 plus WLAN header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__KERNEL__) || defined(_KERNEL) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_HDRLEN
value|64
end_define

begin_comment
comment|/* XXX deprecated */
end_comment

begin_struct
struct|struct
name|ieee80211_radiotap_vendor_header
block|{
name|uint8_t
name|vh_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 3 byte vendor OUI */
name|uint8_t
name|vh_sub_ns
decl_stmt|;
comment|/* Sub namespace of this section */
name|uint16_t
name|vh_skip_len
decl_stmt|;
comment|/* Length of this vendor section */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * The radio capture header precedes the 802.11 header.  *  * Note well: all radiotap fields are little-endian.  */
end_comment

begin_struct
struct|struct
name|ieee80211_radiotap_header
block|{
name|uint8_t
name|it_version
decl_stmt|;
comment|/* Version 0. Only increases 					 * for drastic changes, 					 * introduction of compatible 					 * new fields does not count. 					 */
name|uint8_t
name|it_pad
decl_stmt|;
name|uint16_t
name|it_len
decl_stmt|;
comment|/* length of the whole 					 * header in bytes, including 					 * it_version, it_pad, 					 * it_len, and data fields. 					 */
name|uint32_t
name|it_present
decl_stmt|;
comment|/* A bitmap telling which 					 * fields are present. Set bit 31 					 * (0x80000000) to extend the 					 * bitmap by another 32 bits. 					 * Additional extensions are made 					 * by setting bit 31. 					 */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Name                                 Data type       Units  * ----                                 ---------       -----  *  * IEEE80211_RADIOTAP_TSFT              uint64_t        microseconds  *  *      Value in microseconds of the MAC's 64-bit 802.11 Time  *      Synchronization Function timer when the first bit of the  *      MPDU arrived at the MAC. For received frames, only.  *  * IEEE80211_RADIOTAP_CHANNEL           2 x uint16_t    MHz, bitmap  *  *      Tx/Rx frequency in MHz, followed by flags (see below).  *  * IEEE80211_RADIOTAP_FHSS              uint16_t        see below  *  *      For frequency-hopping radios, the hop set (first byte)  *      and pattern (second byte).  *  * IEEE80211_RADIOTAP_RATE              uint8_t         500kb/s or index  *  *      Tx/Rx data rate.  If bit 0x80 is set then it represents an  *	an MCS index and not an IEEE rate.  *  * IEEE80211_RADIOTAP_DBM_ANTSIGNAL     int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      RF signal power at the antenna, decibel difference from  *      one milliwatt.  *  * IEEE80211_RADIOTAP_DBM_ANTNOISE      int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      RF noise power at the antenna, decibel difference from one  *      milliwatt.  *  * IEEE80211_RADIOTAP_DB_ANTSIGNAL      uint8_t         decibel (dB)  *  *      RF signal power at the antenna, decibel difference from an  *      arbitrary, fixed reference.  *  * IEEE80211_RADIOTAP_DB_ANTNOISE       uint8_t         decibel (dB)  *  *      RF noise power at the antenna, decibel difference from an  *      arbitrary, fixed reference point.  *  * IEEE80211_RADIOTAP_LOCK_QUALITY      uint16_t        unitless  *  *      Quality of Barker code lock. Unitless. Monotonically  *      nondecreasing with "better" lock strength. Called "Signal  *      Quality" in datasheets.  (Is there a standard way to measure  *      this?)  *  * IEEE80211_RADIOTAP_TX_ATTENUATION    uint16_t        unitless  *  *      Transmit power expressed as unitless distance from max  *      power set at factory calibration.  0 is max power.  *      Monotonically nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DB_TX_ATTENUATION uint16_t        decibels (dB)  *  *      Transmit power expressed as decibel distance from max power  *      set at factory calibration.  0 is max power.  Monotonically  *      nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DBM_TX_POWER      int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      Transmit power expressed as dBm (decibels from a 1 milliwatt  *      reference). This is the absolute power level measured at  *      the antenna port.  *  * IEEE80211_RADIOTAP_FLAGS             uint8_t         bitmap  *  *      Properties of transmitted and received frames. See flags  *      defined below.  *  * IEEE80211_RADIOTAP_ANTENNA           uint8_t         antenna index  *  *      Unitless indication of the Rx/Tx antenna for this packet.  *      The first antenna is antenna 0.  *  * IEEE80211_RADIOTAP_XCHANNEL          uint32_t        bitmap  *                                      uint16_t        MHz  *                                      uint8_t         channel number  *                                      int8_t          .5 dBm  *  *      Extended channel specification: flags (see below) followed by  *      frequency in MHz, the corresponding IEEE channel number, and  *      finally the maximum regulatory transmit power cap in .5 dBm  *      units.  This property supersedes IEEE80211_RADIOTAP_CHANNEL  *      and only one of the two should be present.  * IEEE80211_RADIOTAP_RX_FLAGS          guint16       bitmap  *  *     Properties of received frames. See flags defined below.  *  * IEEE80211_RADIOTAP_TX_FLAGS          guint16       bitmap  *  *     Properties of transmitted frames. See flags defined below.  *  * IEEE80211_RADIOTAP_RTS_RETRIES       u8           data  *  *     Number of rts retries a transmitted frame used.  *  * IEEE80211_RADIOTAP_DATA_RETRIES      u8           data  *  *     Number of unicast retries a transmitted frame used.  *  * IEEE80211_RADIOTAP_MCS       u8, u8, u8              unitless  *  *     Contains a bitmap of known fields/flags, the flags, and  *     the MCS index.  *  * IEEE80211_RADIOTAP_AMPDU_STATUS      u32, u16, u8, u8        unitlesss  *  *      Contains the AMPDU information for the subframe.  */
end_comment

begin_enum
enum|enum
name|ieee80211_radiotap_type
block|{
name|IEEE80211_RADIOTAP_TSFT
init|=
literal|0
block|,
name|IEEE80211_RADIOTAP_FLAGS
init|=
literal|1
block|,
name|IEEE80211_RADIOTAP_RATE
init|=
literal|2
block|,
name|IEEE80211_RADIOTAP_CHANNEL
init|=
literal|3
block|,
name|IEEE80211_RADIOTAP_FHSS
init|=
literal|4
block|,
name|IEEE80211_RADIOTAP_DBM_ANTSIGNAL
init|=
literal|5
block|,
name|IEEE80211_RADIOTAP_DBM_ANTNOISE
init|=
literal|6
block|,
name|IEEE80211_RADIOTAP_LOCK_QUALITY
init|=
literal|7
block|,
name|IEEE80211_RADIOTAP_TX_ATTENUATION
init|=
literal|8
block|,
name|IEEE80211_RADIOTAP_DB_TX_ATTENUATION
init|=
literal|9
block|,
name|IEEE80211_RADIOTAP_DBM_TX_POWER
init|=
literal|10
block|,
name|IEEE80211_RADIOTAP_ANTENNA
init|=
literal|11
block|,
name|IEEE80211_RADIOTAP_DB_ANTSIGNAL
init|=
literal|12
block|,
name|IEEE80211_RADIOTAP_DB_ANTNOISE
init|=
literal|13
block|,
comment|/* 	 * 14-17 are from Linux, they overlap the netbsd-specific 	 * fields. 	 */
name|IEEE80211_RADIOTAP_RX_FLAGS
init|=
literal|14
block|,
name|IEEE80211_RADIOTAP_TX_FLAGS
init|=
literal|15
block|,
name|IEEE80211_RADIOTAP_RTS_RETRIES
init|=
literal|16
block|,
name|IEEE80211_RADIOTAP_DATA_RETRIES
init|=
literal|17
block|,
name|IEEE80211_RADIOTAP_XCHANNEL
init|=
literal|18
block|,
name|IEEE80211_RADIOTAP_MCS
init|=
literal|19
block|,
name|IEEE80211_RADIOTAP_AMPDU_STATUS
init|=
literal|20
block|,
name|IEEE80211_RADIOTAP_VHT
init|=
literal|21
block|,
name|IEEE80211_RADIOTAP_RADIOTAP_NAMESPACE
init|=
literal|29
block|,
name|IEEE80211_RADIOTAP_VENDOREXT
init|=
literal|30
block|,
name|IEEE80211_RADIOTAP_EXT
init|=
literal|31
block|, }
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* channel attributes */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TURBO
value|0x00000010
end_define

begin_comment
comment|/* Turbo channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_CCK
value|0x00000020
end_define

begin_comment
comment|/* CCK channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_OFDM
value|0x00000040
end_define

begin_comment
comment|/* OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_2GHZ
value|0x00000080
end_define

begin_comment
comment|/* 2 GHz spectrum channel. */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_5GHZ
value|0x00000100
end_define

begin_comment
comment|/* 5 GHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PASSIVE
value|0x00000200
end_define

begin_comment
comment|/* Only passive scan allowed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_DYN
value|0x00000400
end_define

begin_comment
comment|/* Dynamic CCK-OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_GFSK
value|0x00000800
end_define

begin_comment
comment|/* GFSK channel (FHSS PHY) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_GSM
value|0x00001000
end_define

begin_comment
comment|/* 900 MHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_STURBO
value|0x00002000
end_define

begin_comment
comment|/* 11a static turbo channel only */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HALF
value|0x00004000
end_define

begin_comment
comment|/* Half rate channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_QUARTER
value|0x00008000
end_define

begin_comment
comment|/* Quarter rate channel */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/* For IEEE80211_RADIOTAP_FLAGS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_CFP
value|0x01
end_define

begin_comment
comment|/* sent/received 						 * during CFP 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_SHORTPRE
value|0x02
end_define

begin_comment
comment|/* sent/received 						 * with short 						 * preamble 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_WEP
value|0x04
end_define

begin_comment
comment|/* sent/received 						 * with WEP encryption 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_FRAG
value|0x08
end_define

begin_comment
comment|/* sent/received 						 * with fragmentation 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_FCS
value|0x10
end_define

begin_comment
comment|/* frame includes FCS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_DATAPAD
value|0x20
end_define

begin_comment
comment|/* frame has padding between 						 * 802.11 header and payload 						 * (to 32-bit boundary) 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_BADFCS
value|0x40
end_define

begin_comment
comment|/* does not pass FCS check */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_SHORTGI
value|0x80
end_define

begin_comment
comment|/* HT short GI */
end_comment

begin_comment
comment|/* For IEEE80211_RADIOTAP_RX_FLAGS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_RX_BADPLCP
value|0x0002
end_define

begin_comment
comment|/* bad PLCP */
end_comment

begin_comment
comment|/* For IEEE80211_RADIOTAP_TX_FLAGS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_TX_FAIL
value|0x0001
end_define

begin_comment
comment|/* failed due to excessive 						 * retries */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_TX_CTS
value|0x0002
end_define

begin_comment
comment|/* used cts 'protection' */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_TX_RTS
value|0x0004
end_define

begin_comment
comment|/* used rts/cts handshake */
end_comment

begin_comment
comment|/* For IEEE80211_RADIOTAP_MCS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HAVE_BW
value|0x01
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HAVE_MCS
value|0x02
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HAVE_GI
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HAVE_FMT
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HAVE_FEC
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HAVE_STBC
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HAVE_NESS
value|0x40
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_NESS_BIT1
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BW_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BW_20
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BW_40
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BW_20L
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BW_20U
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_SGI
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_FMT_GF
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_FEC_LDPC
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_1
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_2
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_3
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_NESS_BIT0
value|0x80
end_define

begin_comment
comment|/* For IEEE80211_RADIOTAP_AMPDU_STATUS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_AMPDU_REPORT_ZEROLEN
value|0x0001
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_AMPDU_IS_ZEROLEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_AMPDU_LAST_KNOWN
value|0x0004
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_AMPDU_IS_LAST
value|0x0008
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_AMPDU_DELIM_CRC_ERR
value|0x0010
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_AMPDU_DELIM_CRC_KNOWN
value|0x0020
end_define

begin_comment
comment|/* For IEEE80211_RADIOTAP_VHT */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_STBC
value|0x0001
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_TXOP_PS
value|0x0002
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_GI
value|0x0004
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_SGI_NSYM_DA
value|0x0008
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_LDPC_EXTRA
value|0x0010
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_BF
value|0x0020
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_BW
value|0x0040
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_GID
value|0x0080
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_HAVE_PAID
value|0x0100
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_STBC
value|0x01
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_TXOP_PS
value|0x02
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_SGI
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_SGI_NSYM_DA
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_LDPC_EXTRA
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BF
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_NSS
value|0x0f
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_MCS
value|0xf0
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_CODING_LDPC
value|0x01
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20
value|IEEE80211_RADIOTAP_MCS_BW_20
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_40
value|IEEE80211_RADIOTAP_MCS_BW_40
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20L
value|IEEE80211_RADIOTAP_MCS_BW_20L
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20U
value|IEEE80211_RADIOTAP_MCS_BW_20U
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_80
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_40L
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_40U
value|6
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20LL
value|7
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20LU
value|8
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20UL
value|9
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20UU
value|10
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_160
value|11
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_80L
value|12
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_80U
value|13
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_40LL
value|14
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_40LU
value|15
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_40UL
value|16
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_40UU
value|17
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20LLL
value|18
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20LLU
value|19
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20LUL
value|20
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20LUU
value|21
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20ULL
value|22
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20ULU
value|23
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20UUL
value|24
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_VHT_BW_20UUU
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET80211_IEEE80211_RADIOTAP_H_ */
end_comment

end_unit

