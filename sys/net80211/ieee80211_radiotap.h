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

begin_comment
comment|/*  * The radio capture header precedes the 802.11 header.  *  * Note well: all radiotap fields are little-endian.  */
end_comment

begin_struct
struct|struct
name|ieee80211_radiotap_header
block|{
name|u_int8_t
name|it_version
decl_stmt|;
comment|/* Version 0. Only increases 					 * for drastic changes, 					 * introduction of compatible 					 * new fields does not count. 					 */
name|u_int8_t
name|it_pad
decl_stmt|;
name|u_int16_t
name|it_len
decl_stmt|;
comment|/* length of the whole 					 * header in bytes, including 					 * it_version, it_pad, 					 * it_len, and data fields. 					 */
name|u_int32_t
name|it_present
decl_stmt|;
comment|/* A bitmap telling which 					 * fields are present. Set bit 31 					 * (0x80000000) to extend the 					 * bitmap by another 32 bits. 					 * Additional extensions are made 					 * by setting bit 31. 					 */
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
comment|/*  * Name                                 Data type       Units  * ----                                 ---------       -----  *  * IEEE80211_RADIOTAP_TSFT              u_int64_t       microseconds  *  *      Value in microseconds of the MAC's 64-bit 802.11 Time  *      Synchronization Function timer when the first bit of the  *      MPDU arrived at the MAC. For received frames, only.  *  * IEEE80211_RADIOTAP_CHANNEL           2 x u_int16_t   MHz, bitmap  *  *      Tx/Rx frequency in MHz, followed by flags (see below).  *  * IEEE80211_RADIOTAP_FHSS              u_int16_t       see below  *  *      For frequency-hopping radios, the hop set (first byte)  *      and pattern (second byte).  *  * IEEE80211_RADIOTAP_RATE              u_int8_t        500kb/s  *  *      Tx/Rx data rate  *  * IEEE80211_RADIOTAP_DBM_ANTSIGNAL     int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      RF signal power at the antenna, decibel difference from  *      one milliwatt.  *  * IEEE80211_RADIOTAP_DBM_ANTNOISE      int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      RF noise power at the antenna, decibel difference from one  *      milliwatt.  *  * IEEE80211_RADIOTAP_DB_ANTSIGNAL      u_int8_t        decibel (dB)  *  *      RF signal power at the antenna, decibel difference from an  *      arbitrary, fixed reference.  *  * IEEE80211_RADIOTAP_DB_ANTNOISE       u_int8_t        decibel (dB)  *  *      RF noise power at the antenna, decibel difference from an  *      arbitrary, fixed reference point.  *  * IEEE80211_RADIOTAP_LOCK_QUALITY      u_int16_t       unitless  *  *      Quality of Barker code lock. Unitless. Monotonically  *      nondecreasing with "better" lock strength. Called "Signal  *      Quality" in datasheets.  (Is there a standard way to measure  *      this?)  *  * IEEE80211_RADIOTAP_TX_ATTENUATION    u_int16_t       unitless  *  *      Transmit power expressed as unitless distance from max  *      power set at factory calibration.  0 is max power.  *      Monotonically nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DB_TX_ATTENUATION u_int16_t       decibels (dB)  *  *      Transmit power expressed as decibel distance from max power  *      set at factory calibration.  0 is max power.  Monotonically  *      nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DBM_TX_POWER      int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      Transmit power expressed as dBm (decibels from a 1 milliwatt  *      reference). This is the absolute power level measured at  *      the antenna port.  *  * IEEE80211_RADIOTAP_FLAGS             u_int8_t        bitmap  *  *      Properties of transmitted and received frames. See flags  *      defined below.  *  * IEEE80211_RADIOTAP_ANTENNA           u_int8_t        antenna index  *  *      Unitless indication of the Rx/Tx antenna for this packet.  *      The first antenna is antenna 0.  */
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
comment|/* Channel flags. */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TURBO
value|0x0010
end_define

begin_comment
comment|/* Turbo channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_CCK
value|0x0020
end_define

begin_comment
comment|/* CCK channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_OFDM
value|0x0040
end_define

begin_comment
comment|/* OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_2GHZ
value|0x0080
end_define

begin_comment
comment|/* 2 GHz spectrum channel. */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_5GHZ
value|0x0100
end_define

begin_comment
comment|/* 5 GHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PASSIVE
value|0x0200
end_define

begin_comment
comment|/* Only passive scan allowed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_DYN
value|0x0400
end_define

begin_comment
comment|/* Dynamic CCK-OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_GFSK
value|0x0800
end_define

begin_comment
comment|/* GFSK channel (FHSS PHY) */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET80211_IEEE80211_RADIOTAP_H_ */
end_comment

end_unit

