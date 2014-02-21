begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* NetBSD: ieee802_11_radio.h,v 1.2 2006/02/26 03:04:03 dyoung Exp  */
end_comment

begin_comment
comment|/* $Header: /tcpdump/master/tcpdump/ieee802_11_radio.h,v 1.3 2007-08-29 02:31:44 mcr Exp $ */
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
comment|/* A generic radio capture format is desirable. It must be  * rigidly defined (e.g., units for fields should be given),  * and easily extensible.  *  * The following is an extensible radio capture format. It is  * based on a bitmap indicating which fields are present.  *  * I am trying to describe precisely what the application programmer  * should expect in the following, and for that reason I tell the  * units and origin of each measurement (where it applies), or else I  * use sufficiently weaselly language ("is a monotonically nondecreasing  * function of...") that I cannot set false expectations for lawyerly  * readers.  */
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
struct|;
end_struct

begin_comment
comment|/* Name                                 Data type       Units  * ----                                 ---------       -----  *  * IEEE80211_RADIOTAP_TSFT              u_int64_t       microseconds  *  *      Value in microseconds of the MAC's 64-bit 802.11 Time  *      Synchronization Function timer when the first bit of the  *      MPDU arrived at the MAC. For received frames, only.  *  * IEEE80211_RADIOTAP_CHANNEL           2 x u_int16_t   MHz, bitmap  *  *      Tx/Rx frequency in MHz, followed by flags (see below).  *	Note that IEEE80211_RADIOTAP_XCHANNEL must be used to  *	represent an HT channel as there is not enough room in  *	the flags word.  *  * IEEE80211_RADIOTAP_FHSS              u_int16_t       see below  *  *      For frequency-hopping radios, the hop set (first byte)  *      and pattern (second byte).  *  * IEEE80211_RADIOTAP_RATE              u_int8_t        500kb/s or index  *  *      Tx/Rx data rate.  If bit 0x80 is set then it represents an  *	an MCS index and not an IEEE rate.  *  * IEEE80211_RADIOTAP_DBM_ANTSIGNAL     int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      RF signal power at the antenna, decibel difference from  *      one milliwatt.  *  * IEEE80211_RADIOTAP_DBM_ANTNOISE      int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      RF noise power at the antenna, decibel difference from one  *      milliwatt.  *  * IEEE80211_RADIOTAP_DB_ANTSIGNAL      u_int8_t        decibel (dB)  *  *      RF signal power at the antenna, decibel difference from an  *      arbitrary, fixed reference.  *  * IEEE80211_RADIOTAP_DB_ANTNOISE       u_int8_t        decibel (dB)  *  *      RF noise power at the antenna, decibel difference from an  *      arbitrary, fixed reference point.  *  * IEEE80211_RADIOTAP_LOCK_QUALITY      u_int16_t       unitless  *  *      Quality of Barker code lock. Unitless. Monotonically  *      nondecreasing with "better" lock strength. Called "Signal  *      Quality" in datasheets.  (Is there a standard way to measure  *      this?)  *  * IEEE80211_RADIOTAP_TX_ATTENUATION    u_int16_t       unitless  *  *      Transmit power expressed as unitless distance from max  *      power set at factory calibration.  0 is max power.  *      Monotonically nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DB_TX_ATTENUATION u_int16_t       decibels (dB)  *  *      Transmit power expressed as decibel distance from max power  *      set at factory calibration.  0 is max power.  Monotonically  *      nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DBM_TX_POWER      int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      Transmit power expressed as dBm (decibels from a 1 milliwatt  *      reference). This is the absolute power level measured at  *      the antenna port.  *  * IEEE80211_RADIOTAP_FLAGS             u_int8_t        bitmap  *  *      Properties of transmitted and received frames. See flags  *      defined below.  *  * IEEE80211_RADIOTAP_ANTENNA           u_int8_t        antenna index  *  *      Unitless indication of the Rx/Tx antenna for this packet.  *      The first antenna is antenna 0.  *  * IEEE80211_RADIOTAP_RX_FLAGS          u_int16_t       bitmap  *  *     Properties of received frames. See flags defined below.  *  * IEEE80211_RADIOTAP_XCHANNEL          u_int32_t	bitmap  *					u_int16_t	MHz  *					u_int8_t	channel number  *					u_int8_t	.5 dBm  *  *	Extended channel specification: flags (see below) followed by  *	frequency in MHz, the corresponding IEEE channel number, and  *	finally the maximum regulatory transmit power cap in .5 dBm  *	units.  This property supersedes IEEE80211_RADIOTAP_CHANNEL  *	and only one of the two should be present.  *  * IEEE80211_RADIOTAP_MCS		u_int8_t	known  *					u_int8_t	flags  *					u_int8_t	mcs  *  *	Bitset indicating which fields have known values, followed  *	by bitset of flag values, followed by the MCS rate index as  *	in IEEE 802.11n.  *  * IEEE80211_RADIOTAP_VENDOR_NAMESPACE  *					u_int8_t  OUI[3]  *                                   u_int8_t  subspace  *                                   u_int16_t length  *  *     The Vendor Namespace Field contains three sub-fields. The first  *     sub-field is 3 bytes long. It contains the vendor's IEEE 802  *     Organizationally Unique Identifier (OUI). The fourth byte is a  *     vendor-specific "namespace selector."  *  */
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
name|IEEE80211_RADIOTAP_RX_FLAGS
init|=
literal|14
block|,
comment|/* NB: gap for netbsd definitions */
name|IEEE80211_RADIOTAP_XCHANNEL
init|=
literal|18
block|,
name|IEEE80211_RADIOTAP_MCS
init|=
literal|19
block|,
name|IEEE80211_RADIOTAP_NAMESPACE
init|=
literal|29
block|,
name|IEEE80211_RADIOTAP_VENDOR_NAMESPACE
init|=
literal|30
block|,
name|IEEE80211_RADIOTAP_EXT
init|=
literal|31
block|}
enum|;
end_enum

begin_comment
comment|/* channel attributes */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TURBO
value|0x00010
end_define

begin_comment
comment|/* Turbo channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_CCK
value|0x00020
end_define

begin_comment
comment|/* CCK channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_OFDM
value|0x00040
end_define

begin_comment
comment|/* OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_2GHZ
value|0x00080
end_define

begin_comment
comment|/* 2 GHz spectrum channel. */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_5GHZ
value|0x00100
end_define

begin_comment
comment|/* 5 GHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PASSIVE
value|0x00200
end_define

begin_comment
comment|/* Only passive scan allowed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_DYN
value|0x00400
end_define

begin_comment
comment|/* Dynamic CCK-OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_GFSK
value|0x00800
end_define

begin_comment
comment|/* GFSK channel (FHSS PHY) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_GSM
value|0x01000
end_define

begin_comment
comment|/* 900 MHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_STURBO
value|0x02000
end_define

begin_comment
comment|/* 11a static turbo channel only */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HALF
value|0x04000
end_define

begin_comment
comment|/* Half rate channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_QUARTER
value|0x08000
end_define

begin_comment
comment|/* Quarter rate channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT20
value|0x10000
end_define

begin_comment
comment|/* HT 20 channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT40U
value|0x20000
end_define

begin_comment
comment|/* HT 40 channel w/ ext above */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT40D
value|0x40000
end_define

begin_comment
comment|/* HT 40 channel w/ ext below */
end_comment

begin_comment
comment|/* Useful combinations of channel characteristics, borrowed from Ethereal */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_A
define|\
value|(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_B
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_CCK)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_G
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_DYN)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TA
define|\
value|(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM | IEEE80211_CHAN_TURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TG
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_DYN  | IEEE80211_CHAN_TURBO)
end_define

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

begin_comment
comment|/* For IEEE80211_RADIOTAP_RX_FLAGS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_RX_BADFCS
value|0x0001
end_define

begin_comment
comment|/* frame failed crc check */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_RX_PLCP_CRC
value|0x0002
end_define

begin_comment
comment|/* frame failed PLCP CRC check */
end_comment

begin_comment
comment|/* For IEEE80211_RADIOTAP_MCS known */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_KNOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_MCS_INDEX_KNOWN
value|0x02
end_define

begin_comment
comment|/* MCS index field */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_GUARD_INTERVAL_KNOWN
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HT_FORMAT_KNOWN
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_FEC_TYPE_KNOWN
value|0x10
end_define

begin_comment
comment|/* For IEEE80211_RADIOTAP_MCS flags */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_20
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_40
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_20L
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_20U
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_SHORT_GI
value|0x04
end_define

begin_comment
comment|/* short guard interval */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HT_GREENFIELD
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_FEC_LDPC
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_IEEE80211RADIOTAP_H_ */
end_comment

end_unit

