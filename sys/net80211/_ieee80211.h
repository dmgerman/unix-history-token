begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2005 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211__IEEE80211_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211__IEEE80211_H_
end_define

begin_enum
enum|enum
name|ieee80211_phytype
block|{
name|IEEE80211_T_DS
block|,
comment|/* direct sequence spread spectrum */
name|IEEE80211_T_FH
block|,
comment|/* frequency hopping */
name|IEEE80211_T_OFDM
block|,
comment|/* frequency division multiplexing */
name|IEEE80211_T_TURBO
block|,
comment|/* high rate OFDM, aka turbo mode */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_T_CCK
value|IEEE80211_T_DS
end_define

begin_comment
comment|/* more common nomenclature */
end_comment

begin_comment
comment|/* XXX not really a mode; there are really multiple PHY's */
end_comment

begin_enum
enum|enum
name|ieee80211_phymode
block|{
name|IEEE80211_MODE_AUTO
init|=
literal|0
block|,
comment|/* autoselect */
name|IEEE80211_MODE_11A
init|=
literal|1
block|,
comment|/* 5GHz, OFDM */
name|IEEE80211_MODE_11B
init|=
literal|2
block|,
comment|/* 2GHz, CCK */
name|IEEE80211_MODE_11G
init|=
literal|3
block|,
comment|/* 2GHz, OFDM */
name|IEEE80211_MODE_FH
init|=
literal|4
block|,
comment|/* 2GHz, GFSK */
name|IEEE80211_MODE_TURBO_A
init|=
literal|5
block|,
comment|/* 5GHz, OFDM, 2x clock */
name|IEEE80211_MODE_TURBO_G
init|=
literal|6
block|,
comment|/* 2GHz, OFDM, 2x clock */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_MODE_MAX
value|(IEEE80211_MODE_TURBO_G+1)
end_define

begin_enum
enum|enum
name|ieee80211_opmode
block|{
name|IEEE80211_M_STA
init|=
literal|1
block|,
comment|/* infrastructure station */
name|IEEE80211_M_IBSS
init|=
literal|0
block|,
comment|/* IBSS (adhoc) station */
name|IEEE80211_M_AHDEMO
init|=
literal|3
block|,
comment|/* Old lucent compatible adhoc demo */
name|IEEE80211_M_HOSTAP
init|=
literal|6
block|,
comment|/* Software Access Point */
name|IEEE80211_M_MONITOR
init|=
literal|8
comment|/* Monitor mode */
block|}
enum|;
end_enum

begin_comment
comment|/*  * 802.11g protection mode.  */
end_comment

begin_enum
enum|enum
name|ieee80211_protmode
block|{
name|IEEE80211_PROT_NONE
init|=
literal|0
block|,
comment|/* no protection */
name|IEEE80211_PROT_CTSONLY
init|=
literal|1
block|,
comment|/* CTS to self */
name|IEEE80211_PROT_RTSCTS
init|=
literal|2
block|,
comment|/* RTS-CTS */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Authentication mode.  */
end_comment

begin_enum
enum|enum
name|ieee80211_authmode
block|{
name|IEEE80211_AUTH_NONE
init|=
literal|0
block|,
name|IEEE80211_AUTH_OPEN
init|=
literal|1
block|,
comment|/* open */
name|IEEE80211_AUTH_SHARED
init|=
literal|2
block|,
comment|/* shared-key */
name|IEEE80211_AUTH_8021X
init|=
literal|3
block|,
comment|/* 802.1x */
name|IEEE80211_AUTH_AUTO
init|=
literal|4
block|,
comment|/* auto-select/accept */
comment|/* NB: these are used only for ioctls */
name|IEEE80211_AUTH_WPA
init|=
literal|5
block|,
comment|/* WPA/RSN w/ 802.1x/PSK */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Roaming mode is effectively who controls the operation  * of the 802.11 state machine when operating as a station.  * State transitions are controlled either by the driver  * (typically when management frames are processed by the  * hardware/firmware), the host (auto/normal operation of  * the 802.11 layer), or explicitly through ioctl requests  * when applications like wpa_supplicant want control.  */
end_comment

begin_enum
enum|enum
name|ieee80211_roamingmode
block|{
name|IEEE80211_ROAMING_DEVICE
init|=
literal|0
block|,
comment|/* driver/hardware control */
name|IEEE80211_ROAMING_AUTO
init|=
literal|1
block|,
comment|/* 802.11 layer control */
name|IEEE80211_ROAMING_MANUAL
init|=
literal|2
block|,
comment|/* application control */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Channels are specified by frequency and attributes.  */
end_comment

begin_struct
struct|struct
name|ieee80211_channel
block|{
name|u_int16_t
name|ic_freq
decl_stmt|;
comment|/* setting in Mhz */
name|u_int16_t
name|ic_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_CHAN_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_BYTES
value|32
end_define

begin_comment
comment|/* howmany(IEEE80211_CHAN_MAX, NBBY) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ANY
value|0xffff
end_define

begin_comment
comment|/* token for ``any channel'' */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ANYC
define|\
value|((struct ieee80211_channel *) IEEE80211_CHAN_ANY)
end_define

begin_comment
comment|/* bits 0-3 are for private use by drivers */
end_comment

begin_comment
comment|/* channel attributes */
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

begin_define
define|#
directive|define
name|IEEE80211_CHAN_GSM
value|0x1000
end_define

begin_comment
comment|/* 900 MHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HALF
value|0x4000
end_define

begin_comment
comment|/* Half rate channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_QUARTER
value|0x8000
end_define

begin_comment
comment|/* Quarter rate channel */
end_comment

begin_comment
comment|/*  * Useful combinations of channel characteristics.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_FHSS
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_GFSK)
end_define

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
name|IEEE80211_CHAN_PUREG
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_OFDM)
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
name|IEEE80211_CHAN_T
define|\
value|(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM | IEEE80211_CHAN_TURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_108G
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_OFDM | IEEE80211_CHAN_TURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ALL
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_GFSK | \ 	 IEEE80211_CHAN_CCK | IEEE80211_CHAN_OFDM | IEEE80211_CHAN_DYN)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ALLTURBO
define|\
value|(IEEE80211_CHAN_ALL | IEEE80211_CHAN_TURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_FHSS
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_FHSS) == IEEE80211_CHAN_FHSS)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_A
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_A) == IEEE80211_CHAN_A)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_B
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_B) == IEEE80211_CHAN_B)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_PUREG
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_PUREG) == IEEE80211_CHAN_PUREG)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_G
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_G) == IEEE80211_CHAN_G)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_ANYG
parameter_list|(
name|_c
parameter_list|)
define|\
value|(IEEE80211_IS_CHAN_PUREG(_c) || IEEE80211_IS_CHAN_G(_c))
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_T
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_T) == IEEE80211_CHAN_T)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_108G
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_108G) == IEEE80211_CHAN_108G)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_2GHZ
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_2GHZ) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_5GHZ
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_5GHZ) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_OFDM
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_OFDM) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_CCK
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_CCK) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_GFSK
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_GFSK) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_HALF
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_HALF) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_QUARTER
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_QUARTER) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_FULL
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& (IEEE80211_CHAN_QUARTER | IEEE80211_CHAN_HALF)) == 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_GSM
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_GSM) != 0)
end_define

begin_comment
comment|/* ni_chan encoding for FH phy */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FH_CHANMOD
value|80
end_define

begin_define
define|#
directive|define
name|IEEE80211_FH_CHAN
parameter_list|(
name|set
parameter_list|,
name|pat
parameter_list|)
value|(((set)-1)*IEEE80211_FH_CHANMOD+(pat))
end_define

begin_define
define|#
directive|define
name|IEEE80211_FH_CHANSET
parameter_list|(
name|chan
parameter_list|)
value|((chan)/IEEE80211_FH_CHANMOD+1)
end_define

begin_define
define|#
directive|define
name|IEEE80211_FH_CHANPAT
parameter_list|(
name|chan
parameter_list|)
value|((chan)%IEEE80211_FH_CHANMOD)
end_define

begin_comment
comment|/*  * 802.11 rate set.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RATE_SIZE
value|8
end_define

begin_comment
comment|/* 802.11 standard */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RATE_MAXSIZE
value|15
end_define

begin_comment
comment|/* max rates we'll handle */
end_comment

begin_struct
struct|struct
name|ieee80211_rateset
block|{
name|u_int8_t
name|rs_nrates
decl_stmt|;
name|u_int8_t
name|rs_rates
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211__IEEE80211_H_ */
end_comment

end_unit

