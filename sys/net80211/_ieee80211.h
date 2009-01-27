begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * 802.11 implementation definitions.  *  * NB: this file is used by applications.  */
end_comment

begin_comment
comment|/*  * PHY type; mostly used to identify FH phys.  */
end_comment

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
name|IEEE80211_T_HT
block|,
comment|/* high throughput */
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
comment|/*  * PHY mode; this is not really a mode as multi-mode devices  * have multiple PHY's.  Mode is mostly used as a shorthand  * for constraining which channels to consider in setting up  * operation.  Modes used to be used more extensively when  * channels were identified as IEEE channel numbers.  */
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
name|IEEE80211_MODE_STURBO_A
init|=
literal|7
block|,
comment|/* 5GHz, OFDM, 2x clock, static */
name|IEEE80211_MODE_11NA
init|=
literal|8
block|,
comment|/* 5GHz, w/ HT */
name|IEEE80211_MODE_11NG
init|=
literal|9
block|,
comment|/* 2GHz, w/ HT */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_MODE_MAX
value|(IEEE80211_MODE_11NG+1)
end_define

begin_comment
comment|/*  * Operating mode.  Devices do not necessarily support  * all modes; they indicate which are supported in their  * capabilities.  */
end_comment

begin_enum
enum|enum
name|ieee80211_opmode
block|{
name|IEEE80211_M_IBSS
init|=
literal|0
block|,
comment|/* IBSS (adhoc) station */
name|IEEE80211_M_STA
init|=
literal|1
block|,
comment|/* infrastructure station */
name|IEEE80211_M_WDS
init|=
literal|2
block|,
comment|/* WDS link */
name|IEEE80211_M_AHDEMO
init|=
literal|3
block|,
comment|/* Old lucent compatible adhoc demo */
name|IEEE80211_M_HOSTAP
init|=
literal|4
block|,
comment|/* Software Access Point */
name|IEEE80211_M_MONITOR
init|=
literal|5
block|,
comment|/* Monitor mode */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_OPMODE_MAX
value|(IEEE80211_M_MONITOR+1)
end_define

begin_comment
comment|/*  * 802.11g/802.11n protection mode.  */
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
comment|/*  * Authentication mode.  The open and shared key authentication  * modes are implemented within the 802.11 layer.  802.1x and  * WPA/802.11i are implemented in user mode by setting the  * 802.11 layer into IEEE80211_AUTH_8021X and deferring  * authentication to user space programs.  */
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
name|uint32_t
name|ic_flags
decl_stmt|;
comment|/* see below */
name|uint16_t
name|ic_freq
decl_stmt|;
comment|/* setting in Mhz */
name|uint8_t
name|ic_ieee
decl_stmt|;
comment|/* IEEE channel number */
name|int8_t
name|ic_maxregpower
decl_stmt|;
comment|/* maximum regulatory tx power in dBm */
name|int8_t
name|ic_maxpower
decl_stmt|;
comment|/* maximum tx power in .5 dBm */
name|int8_t
name|ic_minpower
decl_stmt|;
comment|/* minimum tx power in .5 dBm */
name|uint8_t
name|ic_state
decl_stmt|;
comment|/* dynamic state */
name|uint8_t
name|ic_extieee
decl_stmt|;
comment|/* HT40 extension channel number */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_CHAN_MAX
value|256
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
comment|/* channel attributes */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PRIV0
value|0x00000001
end_define

begin_comment
comment|/* driver private bit 0 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PRIV1
value|0x00000002
end_define

begin_comment
comment|/* driver private bit 1 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PRIV2
value|0x00000004
end_define

begin_comment
comment|/* driver private bit 2 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PRIV3
value|0x00000008
end_define

begin_comment
comment|/* driver private bit 3 */
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

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT20
value|0x00010000
end_define

begin_comment
comment|/* HT 20 channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT40U
value|0x00020000
end_define

begin_comment
comment|/* HT 40 channel w/ ext above */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT40D
value|0x00040000
end_define

begin_comment
comment|/* HT 40 channel w/ ext below */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_DFS
value|0x00080000
end_define

begin_comment
comment|/* DFS required */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_4MSXMIT
value|0x00100000
end_define

begin_comment
comment|/* 4ms limit on frame length */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_NOADHOC
value|0x00200000
end_define

begin_comment
comment|/* adhoc mode not allowed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_NOHOSTAP
value|0x00400000
end_define

begin_comment
comment|/* hostap mode not allowed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_11D
value|0x00800000
end_define

begin_comment
comment|/* 802.11d required */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT40
value|(IEEE80211_CHAN_HT40U | IEEE80211_CHAN_HT40D)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT
value|(IEEE80211_CHAN_HT20 | IEEE80211_CHAN_HT40)
end_define

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
name|IEEE80211_CHAN_108A
define|\
value|(IEEE80211_CHAN_A | IEEE80211_CHAN_TURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_108G
define|\
value|(IEEE80211_CHAN_PUREG | IEEE80211_CHAN_TURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ST
define|\
value|(IEEE80211_CHAN_108A | IEEE80211_CHAN_STURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ALL
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_GFSK | \ 	 IEEE80211_CHAN_CCK | IEEE80211_CHAN_OFDM | IEEE80211_CHAN_DYN | \ 	 IEEE80211_CHAN_HALF | IEEE80211_CHAN_QUARTER | \ 	 IEEE80211_CHAN_HT)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ALLTURBO
define|\
value|(IEEE80211_CHAN_ALL | IEEE80211_CHAN_TURBO | IEEE80211_CHAN_STURBO)
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
name|IEEE80211_IS_CHAN_ST
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_ST) == IEEE80211_CHAN_ST)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_108A
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_108A) == IEEE80211_CHAN_108A)
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
name|IEEE80211_IS_CHAN_PASSIVE
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_PASSIVE) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_OFDM
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& (IEEE80211_CHAN_OFDM | IEEE80211_CHAN_DYN)) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_CCK
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& (IEEE80211_CHAN_CCK | IEEE80211_CHAN_DYN)) != 0)
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
name|IEEE80211_IS_CHAN_TURBO
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_TURBO) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_STURBO
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_STURBO) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_DTURBO
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& \ 	(IEEE80211_CHAN_TURBO | IEEE80211_CHAN_STURBO)) == IEEE80211_CHAN_TURBO)
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

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_HT
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_HT) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_HT20
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_HT20) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_HT40
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_HT40) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_HT40U
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_HT40U) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_HT40D
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_HT40D) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_HTA
parameter_list|(
name|_c
parameter_list|)
define|\
value|(IEEE80211_IS_CHAN_5GHZ(_c)&& \ 	 ((_c)->ic_flags& IEEE80211_CHAN_HT) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_HTG
parameter_list|(
name|_c
parameter_list|)
define|\
value|(IEEE80211_IS_CHAN_2GHZ(_c)&& \ 	 ((_c)->ic_flags& IEEE80211_CHAN_HT) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_DFS
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_DFS) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_NOADHOC
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_NOADHOC) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_NOHOSTAP
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_NOHOSTAP) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_11D
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_11D) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN2IEEE
parameter_list|(
name|_c
parameter_list|)
value|(_c)->ic_ieee
end_define

begin_comment
comment|/* dynamic state */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHANSTATE_RADAR
value|0x01
end_define

begin_comment
comment|/* radar detected */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHANSTATE_CACDONE
value|0x02
end_define

begin_comment
comment|/* CAC completed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHANSTATE_CWINT
value|0x04
end_define

begin_comment
comment|/* interference detected */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHANSTATE_NORADAR
value|0x10
end_define

begin_comment
comment|/* post notify on radar clear */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_RADAR
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_state& IEEE80211_CHANSTATE_RADAR) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_CACDONE
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_state& IEEE80211_CHANSTATE_CACDONE) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_CWINT
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_state& IEEE80211_CHANSTATE_CWINT) != 0)
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

begin_define
define|#
directive|define
name|IEEE80211_TID_SIZE
value|(WME_NUM_TID+1)
end_define

begin_comment
comment|/* WME TID's +1 for non-QoS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NONQOS_TID
value|WME_NUM_TID
end_define

begin_comment
comment|/* index for non-QoS sta */
end_comment

begin_comment
comment|/*  * The 802.11 spec says at most 2007 stations may be  * associated at once.  For most AP's this is way more  * than is feasible so we use a default of 128.  This  * number may be overridden by the driver and/or by  * user configuration but may not be less than IEEE80211_AID_MIN.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_AID_DEF
value|128
end_define

begin_define
define|#
directive|define
name|IEEE80211_AID_MIN
value|16
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
name|uint8_t
name|rs_nrates
decl_stmt|;
name|uint8_t
name|rs_rates
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 802.11n variant of ieee80211_rateset.  Instead of  * legacy rates the entries are MCS rates.  We define  * the structure such that it can be used interchangeably  * with an ieee80211_rateset (modulo structure size).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTRATE_MAXSIZE
value|127
end_define

begin_struct
struct|struct
name|ieee80211_htrateset
block|{
name|uint8_t
name|rs_nrates
decl_stmt|;
name|uint8_t
name|rs_rates
index|[
name|IEEE80211_HTRATE_MAXSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_RATE_MCS
value|0x80
end_define

begin_comment
comment|/*  * Per-mode transmit parameters/controls visible to user space.  * These can be used to set fixed transmit rate for all operating  * modes or on a per-client basis according to the capabilities  * of the client (e.g. an 11b client associated to an 11g ap).  *  * MCS are distinguished from legacy rates by or'ing in 0x80.  */
end_comment

begin_struct
struct|struct
name|ieee80211_txparam
block|{
name|uint8_t
name|ucastrate
decl_stmt|;
comment|/* ucast data rate (legacy/MCS|0x80) */
name|uint8_t
name|mgmtrate
decl_stmt|;
comment|/* mgmt frame rate (legacy/MCS|0x80) */
name|uint8_t
name|mcastrate
decl_stmt|;
comment|/* multicast rate (legacy/MCS|0x80) */
name|uint8_t
name|maxretry
decl_stmt|;
comment|/* max unicast data retry count */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-mode roaming state visible to user space.  There are two  * thresholds that control whether roaming is considered; when  * either is exceeded the 802.11 layer will check the scan cache  * for another AP.  If the cache is stale then a scan may be  * triggered.  */
end_comment

begin_struct
struct|struct
name|ieee80211_roamparam
block|{
name|int8_t
name|rssi
decl_stmt|;
comment|/* rssi thresh (.5 dBm) */
name|uint8_t
name|rate
decl_stmt|;
comment|/* tx rate thresh (.5 Mb/s or MCS) */
name|uint16_t
name|pad
decl_stmt|;
comment|/* reserve */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Regulatory Information.  */
end_comment

begin_struct
struct|struct
name|ieee80211_regdomain
block|{
name|uint16_t
name|regdomain
decl_stmt|;
comment|/* SKU */
name|uint16_t
name|country
decl_stmt|;
comment|/* ISO country code */
name|uint8_t
name|location
decl_stmt|;
comment|/* I (indoor), O (outdoor), other */
name|uint8_t
name|ecm
decl_stmt|;
comment|/* Extended Channel Mode */
name|char
name|isocc
index|[
literal|2
index|]
decl_stmt|;
comment|/* country code string */
name|short
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MIMO antenna/radio state.  */
end_comment

begin_struct
struct|struct
name|ieee80211_mimo_info
block|{
name|int8_t
name|rssi
index|[
literal|3
index|]
decl_stmt|;
comment|/* per-antenna rssi */
name|int8_t
name|noise
index|[
literal|3
index|]
decl_stmt|;
comment|/* per-antenna noise floor */
name|uint32_t
name|evm
index|[
literal|3
index|]
decl_stmt|;
comment|/* EVM data */
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

