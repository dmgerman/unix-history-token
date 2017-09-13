begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_urtwn.c,v 1.16 2011/02/10 17:26:40 jakemsr Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2014 Kevin Lo<kevlo@FreeBSD.org>  * Copyright (c) 2015-2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IF_RTWN_RIDX_H
end_ifndef

begin_define
define|#
directive|define
name|IF_RTWN_RIDX_H
end_define

begin_comment
comment|/* HW rate indices. */
end_comment

begin_define
define|#
directive|define
name|RTWN_RIDX_CCK1
value|0
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_CCK2
value|1
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_CCK55
value|2
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_CCK11
value|3
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_OFDM6
value|4
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_OFDM9
value|5
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_OFDM12
value|6
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_OFDM18
value|7
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_OFDM24
value|8
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_OFDM36
value|9
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_OFDM48
value|10
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_OFDM54
value|11
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_HT_MCS
parameter_list|(
name|i
parameter_list|)
value|(12 + (i))
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_COUNT
value|28
end_define

begin_define
define|#
directive|define
name|RTWN_RIDX_UNKNOWN
value|(uint8_t)-1
end_define

begin_define
define|#
directive|define
name|RTWN_RATE_IS_CCK
parameter_list|(
name|rate
parameter_list|)
value|((rate)<= RTWN_RIDX_CCK11)
end_define

begin_define
define|#
directive|define
name|RTWN_RATE_IS_OFDM
parameter_list|(
name|rate
parameter_list|)
define|\
value|((rate)>= RTWN_RIDX_OFDM6&& (rate) != RTWN_RIDX_UNKNOWN)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|ridx2rate
index|[]
init|=
block|{
literal|2
block|,
literal|4
block|,
literal|11
block|,
literal|22
block|,
literal|12
block|,
literal|18
block|,
literal|24
block|,
literal|36
block|,
literal|48
block|,
literal|72
block|,
literal|96
block|,
literal|108
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|uint8_t
name|rate2ridx
parameter_list|(
name|uint8_t
name|rate
parameter_list|)
block|{
if|if
condition|(
name|rate
operator|&
name|IEEE80211_RATE_MCS
condition|)
block|{
comment|/* 11n rates start at idx 12 */
return|return
operator|(
operator|(
name|rate
operator|&
literal|0xf
operator|)
operator|+
literal|12
operator|)
return|;
block|}
switch|switch
condition|(
name|rate
condition|)
block|{
comment|/* 11g */
case|case
literal|12
case|:
return|return
literal|4
return|;
case|case
literal|18
case|:
return|return
literal|5
return|;
case|case
literal|24
case|:
return|return
literal|6
return|;
case|case
literal|36
case|:
return|return
literal|7
return|;
case|case
literal|48
case|:
return|return
literal|8
return|;
case|case
literal|72
case|:
return|return
literal|9
return|;
case|case
literal|96
case|:
return|return
literal|10
return|;
case|case
literal|108
case|:
return|return
literal|11
return|;
comment|/* 11b */
case|case
literal|2
case|:
return|return
literal|0
return|;
case|case
literal|4
case|:
return|return
literal|1
return|;
case|case
literal|11
case|:
return|return
literal|2
return|;
case|case
literal|22
case|:
return|return
literal|3
return|;
default|default:
return|return
name|RTWN_RIDX_UNKNOWN
return|;
block|}
block|}
end_function

begin_comment
comment|/* XXX move to net80211 */
end_comment

begin_function
specifier|static
name|__inline__
name|uint8_t
name|rtwn_ctl_mcsrate
parameter_list|(
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|rt
parameter_list|,
name|uint8_t
name|ridx
parameter_list|)
block|{
name|uint8_t
name|cix
decl_stmt|,
name|rate
decl_stmt|;
comment|/* Check if we are using MCS rate. */
name|KASSERT
argument_list|(
name|ridx
operator|>=
name|RTWN_RIDX_HT_MCS
argument_list|(
literal|0
argument_list|)
operator|&&
name|ridx
operator|!=
name|RTWN_RIDX_UNKNOWN
argument_list|,
operator|(
literal|"bad mcs rate index %d"
operator|,
name|ridx
operator|)
argument_list|)
expr_stmt|;
name|rate
operator|=
operator|(
name|ridx
operator|-
name|RTWN_RIDX_HT_MCS
argument_list|(
literal|0
argument_list|)
operator|)
operator||
name|IEEE80211_RATE_MCS
expr_stmt|;
name|cix
operator|=
name|rt
operator|->
name|info
index|[
name|rt
operator|->
name|rateCodeToIndex
index|[
name|rate
index|]
index|]
operator|.
name|ctlRateIndex
expr_stmt|;
name|KASSERT
argument_list|(
name|cix
operator|!=
operator|(
name|uint8_t
operator|)
operator|-
literal|1
argument_list|,
operator|(
literal|"rate %d (%d) has no info"
operator|,
name|rate
operator|,
name|ridx
operator|)
argument_list|)
expr_stmt|;
return|return
name|rt
operator|->
name|info
index|[
name|cix
index|]
operator|.
name|dot11Rate
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_RTWN_RIDX_H */
end_comment

end_unit

