begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003, 2004 David Young.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of David Young may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY DAVID YOUNG ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL DAVID  * YOUNG BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_IEEE80211RADIOTAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_IEEE80211RADIOTAP_H_
end_define

begin_comment
comment|/* A generic radio capture format is desirable. There is one for  * Linux, but it is neither rigidly defined (there were not even  * units given for some fields) nor easily extensible.  *  * I suggest the following extensible radio capture format. It is  * based on a bitmap indicating which fields are present.  *  * I am trying to describe precisely what the application programmer  * should expect in the following, and for that reason I tell the  * units and origin of each measurement (where it applies), or else I  * use sufficiently weaselly language ("is a monotonically nondecreasing  * function of...") that I cannot set false expectations for lawyerly  * readers.  */
end_comment

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

begin_comment
comment|/* The radio capture header precedes the 802.11 header. */
end_comment

begin_struct
struct|struct
name|ieee80211_radiotap_header
block|{
name|u_int8_t
name|it_version
decl_stmt|;
comment|/* Version 0. Only increases 					 * for drastic changes, 					 * introduction of compatible 					 * new LTVs does not count. 					 */
name|u_int8_t
name|it_pad
decl_stmt|;
name|u_int16_t
name|it_len
decl_stmt|;
comment|/* length of the whole 					 * header in bytes, including 					 * it_version, it_pad, 					 * it_len, and LTVs. 					 */
name|u_int32_t
name|it_present
decl_stmt|;
comment|/* A bitmap telling which 					 * fields are present. Set bit 31 					 * (0x80000000) to extend the 					 * bitmap by another 32 bits. 					 * Additional extensions are made 					 * by setting bit 31. 					 */
block|}
struct|;
end_struct

begin_comment
comment|/* Name                                 Data type       Units  * ----                                 ---------       -----  *  * IEEE80211_RADIOTAP_CHANNEL           u_int8_t	MHz  *  *      Tx/Rx channel number (for DSSS/OFDM/PBCC PHY)  *  * IEEE80211_RADIOTAP_FHSS              u_int16_t       see below  *  *      For frequency-hopping radios, the hop set (first byte)  *      and pattern (second byte).  *  * IEEE80211_RADIOTAP_RATE              u_int8_t	.5Mb/s  *  *      IEEE Tx/Rx data rate cookie (including basic rate flag)  *  * IEEE80211_RADIOTAP_DB_ANTSIGNAL      int16_t         decibel (dB)  *                *      RF signal power at the antenna, measured from a fixed,  *      arbitrary reference point.  *  * IEEE80211_RADIOTAP_DB_ANTNOISE       int16_t         decibel (dB)  *  *      RF noise power at the antenna in decibels from an arbitrary,  *      fixed reference point.  *  * IEEE80211_RADIOTAP_BARKER_CODE_LOCK  u_int16_t       unitless  *  *      Quality of Barker code lock. Unitless. Monotonically  *      nondecreasing with "better" lock strength. Called "Signal  *      Quality" in datasheets.  (Is there a standard way to measure  *      this?)  *  * IEEE80211_RADIOTAP_TX_ATTENUATION    u_int16_t       unitless  *  *      Transmit power expressed as unitless distance from max  *      power set at factory calibration.  0 is max power.  *      Monotonically nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DB_TX_ATTENUATION u_int16_t       decibels (dB)  *  *      Transmit power expressed as decibel distance from max power  *      set at factory calibration.  0 is max power.  Monotonically  *      nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DBM_TX_POWER      u_int16_t       decibels from  *                                                      milliwatt (dBm)  *  *      Transmit power expressed as dBm (decibels from a 1 milliwatt  *      reference). This is the absolute power level measured at  *      the antenna port.  *  * IEEE80211_RADIOTAP_TSFT              u_int64_t       microseconds  *  *      Value in microseconds of the MAC's 64-bit 802.11 Time  *      Synchronization Function timer when the first bit of the  *      MPDU arrived at the MAC. For received frames, only.  *      Little-endian byte order.  *  * IEEE80211_RADIOTAP_FLAGS             u_int16_t       bitmap  *  *      Properties of transmitted and received frames. See flags  *      defined below.  *  * IEEE80211_RADIOTAP_TIME              u_int32_t       microseconds  *  *      For radios that provide it: packet arrival time in  *      microseconds. Prism hardware will provide this, but it is  *      not known whether it marks the first or the last bit of  *      the frame. Nor is it known where that bit has arrived  *      (antenna, modem, MAC?) when the time is measured.  *  * IEEE80211_RADIOTAP_ANTENNA           u_int16_t       antenna index  *  *      Unitless indication of the Rx/Tx antenna for this packet.  *      The first antenna is antenna 0.  */
end_comment

begin_enum
enum|enum
name|ieee80211_radiotap_type
block|{
name|IEEE80211_RADIOTAP_PAD
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
name|IEEE80211_RADIOTAP_DB_ANTSIGNAL
init|=
literal|5
block|,
name|IEEE80211_RADIOTAP_DB_ANTNOISE
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
name|IEEE80211_RADIOTAP_TSFT
init|=
literal|12
block|,
name|IEEE80211_RADIOTAP_EXT
init|=
literal|31
block|,
name|IEEE80211_RADIOTAP_TIME
init|=
literal|32
block|}
enum|;
end_enum

begin_comment
comment|/* For IEEE80211_RADIOTAP_FLAGS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_CFP
value|0x0001
end_define

begin_comment
comment|/* sent/received 						 * during CFP 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_SHORTPRE
value|0x0002
end_define

begin_comment
comment|/* sent/received 						 * with short 						 * preamble 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_WEP
value|0x0004
end_define

begin_comment
comment|/* sent/received 						 * with WEP encryption 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_FRAG
value|0x0008
end_define

begin_comment
comment|/* sent/received 						 * with fragmentation 						 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_IEEE80211RADIOTAP_H_ */
end_comment

end_unit

