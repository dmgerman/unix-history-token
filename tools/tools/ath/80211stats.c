begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * 80211stats [-i interface]  * (default interface is ath0).  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"../../../sys/net80211/ieee80211_ioctl.h"
end_include

begin_function
specifier|static
name|void
name|printstats
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
specifier|const
name|struct
name|ieee80211_stats
modifier|*
name|stats
parameter_list|)
block|{
define|#
directive|define
name|N
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a) / sizeof(a[0]))
define|#
directive|define
name|STAT
parameter_list|(
name|x
parameter_list|,
name|fmt
parameter_list|)
define|\
value|if (stats->is_##x) fprintf(fd, "%u " fmt "\n", stats->is_##x)
name|STAT
argument_list|(
name|rx_badversion
argument_list|,
literal|"rx frame with bad version"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_tooshort
argument_list|,
literal|"rx frame too short"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_wrongbss
argument_list|,
literal|"rx from wrong bssid"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_dup
argument_list|,
literal|"rx discard 'cuz dup"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_wrongdir
argument_list|,
literal|"rx w/ wrong direction"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_mcastecho
argument_list|,
literal|"rx discard 'cuz mcast echo"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_notassoc
argument_list|,
literal|"rx discard 'cuz sta !assoc"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_nowep
argument_list|,
literal|"rx w/ wep but wep !config"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_wepfail
argument_list|,
literal|"rx wep processing failed"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_decap
argument_list|,
literal|"rx decapsulation failed"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_mgtdiscard
argument_list|,
literal|"rx discard mgt frames"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_ctl
argument_list|,
literal|"rx discard ctrl frames"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_rstoobig
argument_list|,
literal|"rx rate set truncated"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_elem_missing
argument_list|,
literal|"rx required element missing"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_elem_toobig
argument_list|,
literal|"rx element too big"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_elem_toosmall
argument_list|,
literal|"rx element too small"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_elem_unknown
argument_list|,
literal|"rx element unknown"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_badchan
argument_list|,
literal|"rx frame w/ invalid chan"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_chanmismatch
argument_list|,
literal|"rx frame chan mismatch"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_nodealloc
argument_list|,
literal|"nodes allocated (rx)"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_ssidmismatch
argument_list|,
literal|"rx frame ssid mismatch"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_auth_unsupported
argument_list|,
literal|"rx w/ unsupported auth alg"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_auth_fail
argument_list|,
literal|"rx sta auth failure"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_assoc_bss
argument_list|,
literal|"rx assoc from wrong bssid"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_assoc_notauth
argument_list|,
literal|"rx assoc w/o auth"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_assoc_capmismatch
argument_list|,
literal|"rx assoc w/ cap mismatch"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_assoc_norate
argument_list|,
literal|"rx assoc w/ no rate match"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_deauth
argument_list|,
literal|"rx deauthentication"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_disassoc
argument_list|,
literal|"rx disassociation"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_badsubtype
argument_list|,
literal|"rx frame w/ unknown subtype"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_nombuf
argument_list|,
literal|"rx failed for lack of mbuf"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_decryptcrc
argument_list|,
literal|"rx decrypt failed on crc"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_ahdemo_mgt
argument_list|,
literal|"rx discard mgmt frame received in ahdoc demo mode"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|rx_bad_auth
argument_list|,
literal|"rx bad authentication request"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|tx_nombuf
argument_list|,
literal|"tx failed for lack of mbuf"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|tx_nonode
argument_list|,
literal|"tx failed for no node"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|tx_unknownmgt
argument_list|,
literal|"tx of unknown mgt frame"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|scan_active
argument_list|,
literal|"active scans started"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|scan_passive
argument_list|,
literal|"passive scans started"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|node_timeout
argument_list|,
literal|"nodes timed out inactivity"
argument_list|)
expr_stmt|;
name|STAT
argument_list|(
name|crypto_nomem
argument_list|,
literal|"malloc failure of rc4 context"
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|STAT
undef|#
directive|undef
name|N
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|struct
name|ifreq
name|ifr
decl_stmt|;
name|struct
name|ieee80211_stats
name|stats
decl_stmt|;
name|s
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"socket"
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
name|argc
operator|-=
literal|1
operator|,
name|argv
operator|+=
literal|1
expr_stmt|;
block|}
else|else
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
literal|"ath0"
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|stats
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCG80211STATS
argument_list|,
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
name|ifr
operator|.
name|ifr_name
argument_list|)
expr_stmt|;
name|printstats
argument_list|(
name|stdout
argument_list|,
operator|&
name|stats
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

