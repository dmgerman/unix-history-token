begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: ipsec.c,v 1.33 2003/07/25 09:54:32 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005 NTT Multimedia Communications Laboratories, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, 1998, and 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1983, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char sccsid[] = "@(#)inet.c	8.5 (Berkeley) 5/24/95";
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC
end_ifdef

begin_include
include|#
directive|include
file|<netipsec/ipsec.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ah_var.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/esp_var.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ipcomp_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<libxo/xo.h>
end_include

begin_include
include|#
directive|include
file|"netstat.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC
end_ifdef

begin_struct
struct|struct
name|val2str
block|{
name|int
name|val
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|val2str
name|ipsec_ahnames
index|[]
init|=
block|{
block|{
name|SADB_AALG_NONE
block|,
literal|"none"
block|, }
block|,
block|{
name|SADB_AALG_MD5HMAC
block|,
literal|"hmac-md5"
block|, }
block|,
block|{
name|SADB_AALG_SHA1HMAC
block|,
literal|"hmac-sha1"
block|, }
block|,
block|{
name|SADB_X_AALG_MD5
block|,
literal|"md5"
block|, }
block|,
block|{
name|SADB_X_AALG_SHA
block|,
literal|"sha"
block|, }
block|,
block|{
name|SADB_X_AALG_NULL
block|,
literal|"null"
block|, }
block|,
ifdef|#
directive|ifdef
name|SADB_X_AALG_SHA2_256
block|{
name|SADB_X_AALG_SHA2_256
block|,
literal|"hmac-sha2-256"
block|, }
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SADB_X_AALG_SHA2_384
block|{
name|SADB_X_AALG_SHA2_384
block|,
literal|"hmac-sha2-384"
block|, }
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SADB_X_AALG_SHA2_512
block|{
name|SADB_X_AALG_SHA2_512
block|,
literal|"hmac-sha2-512"
block|, }
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SADB_X_AALG_RIPEMD160HMAC
block|{
name|SADB_X_AALG_RIPEMD160HMAC
block|,
literal|"hmac-ripemd160"
block|, }
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SADB_X_AALG_AES_XCBC_MAC
block|{
name|SADB_X_AALG_AES_XCBC_MAC
block|,
literal|"aes-xcbc-mac"
block|, }
block|,
endif|#
directive|endif
block|{
operator|-
literal|1
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|val2str
name|ipsec_espnames
index|[]
init|=
block|{
block|{
name|SADB_EALG_NONE
block|,
literal|"none"
block|, }
block|,
block|{
name|SADB_EALG_DESCBC
block|,
literal|"des-cbc"
block|, }
block|,
block|{
name|SADB_EALG_3DESCBC
block|,
literal|"3des-cbc"
block|, }
block|,
block|{
name|SADB_EALG_NULL
block|,
literal|"null"
block|, }
block|,
block|{
name|SADB_X_EALG_CAST128CBC
block|,
literal|"cast128-cbc"
block|, }
block|,
block|{
name|SADB_X_EALG_BLOWFISHCBC
block|,
literal|"blowfish-cbc"
block|, }
block|,
ifdef|#
directive|ifdef
name|SADB_X_EALG_RIJNDAELCBC
block|{
name|SADB_X_EALG_RIJNDAELCBC
block|,
literal|"rijndael-cbc"
block|, }
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SADB_X_EALG_AESCTR
block|{
name|SADB_X_EALG_AESCTR
block|,
literal|"aes-ctr"
block|, }
block|,
endif|#
directive|endif
block|{
operator|-
literal|1
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|val2str
name|ipsec_compnames
index|[]
init|=
block|{
block|{
name|SADB_X_CALG_NONE
block|,
literal|"none"
block|, }
block|,
block|{
name|SADB_X_CALG_OUI
block|,
literal|"oui"
block|, }
block|,
block|{
name|SADB_X_CALG_DEFLATE
block|,
literal|"deflate"
block|, }
block|,
block|{
name|SADB_X_CALG_LZS
block|,
literal|"lzs"
block|, }
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|print_ipsecstats
parameter_list|(
specifier|const
name|struct
name|ipsecstat
modifier|*
name|ipsecstat
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|print_ipsecstats
parameter_list|(
specifier|const
name|struct
name|ipsecstat
modifier|*
name|ipsecstat
parameter_list|)
block|{
name|xo_open_container
argument_list|(
literal|"ipsec-statistics"
argument_list|)
expr_stmt|;
define|#
directive|define
name|p
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|if (ipsecstat->f || sflag<= 1) \ 	xo_emit(m, (uintmax_t)ipsecstat->f, plural(ipsecstat->f))
name|p
argument_list|(
name|ips_in_polvio
argument_list|,
literal|"\t{:dropped-policy-violation/%ju} "
literal|"{N:/inbound packet%s violated process security policy}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_in_nomem
argument_list|,
literal|"\t{:dropped-no-memory/%ju} "
literal|"{N:/inbound packet%s failed due to insufficient memory}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_in_inval
argument_list|,
literal|"\t{:dropped-invalid/%ju} "
literal|"{N:/invalid inbound packet%s}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_out_polvio
argument_list|,
literal|"\t{:discarded-policy-violation/%ju} "
literal|"{N:/outbound packet%s violated process security policy}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_out_nosa
argument_list|,
literal|"\t{:discarded-no-sa/%ju} "
literal|"{N:/outbound packet%s with no SA available}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_out_nomem
argument_list|,
literal|"\t{:discarded-no-memory/%ju} "
literal|"{N:/outbound packet%s failed due to insufficient memory}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_out_noroute
argument_list|,
literal|"\t{:discarded-no-route/%ju} "
literal|"{N:/outbound packet%s with no route available}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_out_inval
argument_list|,
literal|"\t{:discarded-invalid/%ju} "
literal|"{N:/invalid outbound packet%s}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_out_bundlesa
argument_list|,
literal|"\t{:send-bundled-sa/%ju} "
literal|"{N:/outbound packet%s with bundled SAs}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_mbcoalesced
argument_list|,
literal|"\t{:mbufs-coalesced-during-clone/%ju} "
literal|"{N:/mbuf%s coalesced during clone}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_clcoalesced
argument_list|,
literal|"\t{:clusters-coalesced-during-clone/%ju} "
literal|"{N:/cluster%s coalesced during clone}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_clcopied
argument_list|,
literal|"\t{:clusters-copied-during-clone/%ju} "
literal|"{N:/cluster%s copied during clone}\n"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ips_mbinserted
argument_list|,
literal|"\t{:mbufs-inserted/%ju} "
literal|"{N:/mbuf%s inserted during makespace}\n"
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|p
name|xo_close_container
argument_list|(
literal|"ipsec-statistics"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ipsec_stats
parameter_list|(
name|u_long
name|off
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|af1
name|__unused
parameter_list|,
name|int
name|proto
name|__unused
parameter_list|)
block|{
name|struct
name|ipsecstat
name|ipsecstat
decl_stmt|;
if|if
condition|(
name|off
operator|==
literal|0
condition|)
return|return;
name|xo_emit
argument_list|(
literal|"{T:/%s}:\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|kread_counters
argument_list|(
name|off
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|ipsecstat
argument_list|,
sizeof|sizeof
argument_list|(
name|ipsecstat
argument_list|)
argument_list|)
expr_stmt|;
name|print_ipsecstats
argument_list|(
operator|&
name|ipsecstat
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|static
name|void
name|print_ahstats
parameter_list|(
specifier|const
name|struct
name|ahstat
modifier|*
name|ahstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_espstats
parameter_list|(
specifier|const
name|struct
name|espstat
modifier|*
name|espstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_ipcompstats
parameter_list|(
specifier|const
name|struct
name|ipcompstat
modifier|*
name|ipcompstat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Dump IPSEC statistics structure.  */
end_comment

begin_function
specifier|static
name|void
name|ipsec_hist_new
parameter_list|(
specifier|const
name|uint64_t
modifier|*
name|hist
parameter_list|,
name|size_t
name|histmax
parameter_list|,
specifier|const
name|struct
name|val2str
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|char
modifier|*
name|cname
parameter_list|)
block|{
name|int
name|first
decl_stmt|;
name|size_t
name|proto
decl_stmt|;
specifier|const
name|struct
name|val2str
modifier|*
name|p
decl_stmt|;
name|first
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|proto
operator|=
literal|0
init|;
name|proto
operator|<
name|histmax
condition|;
name|proto
operator|++
control|)
block|{
if|if
condition|(
name|hist
index|[
name|proto
index|]
operator|<=
literal|0
condition|)
continue|continue;
if|if
condition|(
name|first
condition|)
block|{
name|xo_open_list
argument_list|(
name|cname
argument_list|)
expr_stmt|;
name|xo_emit
argument_list|(
literal|"\t{T:/%s histogram}:\n"
argument_list|,
name|title
argument_list|)
expr_stmt|;
name|first
operator|=
literal|0
expr_stmt|;
block|}
name|xo_open_instance
argument_list|(
name|cname
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
name|name
init|;
name|p
operator|&&
name|p
operator|->
name|str
condition|;
name|p
operator|++
control|)
block|{
if|if
condition|(
name|p
operator|->
name|val
operator|==
operator|(
name|int
operator|)
name|proto
condition|)
break|break;
block|}
if|if
condition|(
name|p
operator|&&
name|p
operator|->
name|str
condition|)
block|{
name|xo_emit
argument_list|(
literal|"\t\t{k:name}: {:count/%ju}\n"
argument_list|,
name|p
operator|->
name|str
argument_list|,
operator|(
name|uintmax_t
operator|)
name|hist
index|[
name|proto
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|xo_emit
argument_list|(
literal|"\t\t#{k:name/%lu}: {:count/%ju}\n"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|proto
argument_list|,
operator|(
name|uintmax_t
operator|)
name|hist
index|[
name|proto
index|]
argument_list|)
expr_stmt|;
block|}
name|xo_close_instance
argument_list|(
name|cname
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|first
condition|)
name|xo_close_list
argument_list|(
name|cname
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_ahstats
parameter_list|(
specifier|const
name|struct
name|ahstat
modifier|*
name|ahstat
parameter_list|)
block|{
name|xo_open_container
argument_list|(
literal|"ah-statictics"
argument_list|)
expr_stmt|;
define|#
directive|define
name|p
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|)
value|if (ahstat->f || sflag<= 1) \ 	xo_emit("\t{:" n "/%ju} {N:/" m "}\n",	\ 	    (uintmax_t)ahstat->f, plural(ahstat->f))
define|#
directive|define
name|hist
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
define|\
value|ipsec_hist_new((f), sizeof(f)/sizeof(f[0]), (n), (t), (c))
name|p
argument_list|(
name|ahs_hdrops
argument_list|,
literal|"dropped-short-header"
argument_list|,
literal|"packet%s shorter than header shows"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_nopf
argument_list|,
literal|"dropped-bad-protocol"
argument_list|,
literal|"packet%s dropped; protocol family not supported"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_notdb
argument_list|,
literal|"dropped-no-tdb"
argument_list|,
literal|"packet%s dropped; no TDB"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_badkcr
argument_list|,
literal|"dropped-bad-kcr"
argument_list|,
literal|"packet%s dropped; bad KCR"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_qfull
argument_list|,
literal|"dropped-queue-full"
argument_list|,
literal|"packet%s dropped; queue full"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_noxform
argument_list|,
literal|"dropped-no-transform"
argument_list|,
literal|"packet%s dropped; no transform"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_wrap
argument_list|,
literal|"replay-counter-wraps"
argument_list|,
literal|"replay counter wrap%s"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_badauth
argument_list|,
literal|"dropped-bad-auth"
argument_list|,
literal|"packet%s dropped; bad authentication detected"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_badauthl
argument_list|,
literal|"dropped-bad-auth-level"
argument_list|,
literal|"packet%s dropped; bad authentication length"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_replay
argument_list|,
literal|"possile-replay-detected"
argument_list|,
literal|"possible replay packet%s detected"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_input
argument_list|,
literal|"received-packets"
argument_list|,
literal|"packet%s in"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_output
argument_list|,
literal|"send-packets"
argument_list|,
literal|"packet%s out"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_invalid
argument_list|,
literal|"dropped-bad-tdb"
argument_list|,
literal|"packet%s dropped; invalid TDB"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_ibytes
argument_list|,
literal|"received-bytes"
argument_list|,
literal|"byte%s in"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_obytes
argument_list|,
literal|"send-bytes"
argument_list|,
literal|"byte%s out"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_toobig
argument_list|,
literal|"dropped-too-large"
argument_list|,
literal|"packet%s dropped; larger than IP_MAXPACKET"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_pdrops
argument_list|,
literal|"dropped-policy-violation"
argument_list|,
literal|"packet%s blocked due to policy"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_crypto
argument_list|,
literal|"crypto-failures"
argument_list|,
literal|"crypto processing failure%s"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ahs_tunnel
argument_list|,
literal|"tunnel-failures"
argument_list|,
literal|"tunnel sanity check failure%s"
argument_list|)
expr_stmt|;
name|hist
argument_list|(
name|ahstat
operator|->
name|ahs_hist
argument_list|,
name|ipsec_ahnames
argument_list|,
literal|"AH output"
argument_list|,
literal|"ah-output-histogram"
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|p
undef|#
directive|undef
name|hist
name|xo_close_container
argument_list|(
literal|"ah-statictics"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ah_stats
parameter_list|(
name|u_long
name|off
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|family
name|__unused
parameter_list|,
name|int
name|proto
name|__unused
parameter_list|)
block|{
name|struct
name|ahstat
name|ahstat
decl_stmt|;
if|if
condition|(
name|off
operator|==
literal|0
condition|)
return|return;
name|xo_emit
argument_list|(
literal|"{T:/%s}:\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|kread_counters
argument_list|(
name|off
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|ahstat
argument_list|,
sizeof|sizeof
argument_list|(
name|ahstat
argument_list|)
argument_list|)
expr_stmt|;
name|print_ahstats
argument_list|(
operator|&
name|ahstat
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_espstats
parameter_list|(
specifier|const
name|struct
name|espstat
modifier|*
name|espstat
parameter_list|)
block|{
name|xo_open_container
argument_list|(
literal|"esp-statictics"
argument_list|)
expr_stmt|;
define|#
directive|define
name|p
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|)
value|if (espstat->f || sflag<= 1)	\ 	xo_emit("\t{:" n "/%ju} {N:/" m "}\n",		\ 	    (uintmax_t)espstat->f, plural(espstat->f))
define|#
directive|define
name|hist
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
define|\
value|ipsec_hist_new((f), sizeof(f)/sizeof(f[0]), (n), (t), (c));
name|p
argument_list|(
name|esps_hdrops
argument_list|,
literal|"dropped-short-header"
argument_list|,
literal|"packet%s shorter than header shows"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_nopf
argument_list|,
literal|"dropped-bad-protocol"
argument_list|,
literal|"packet%s dropped; protocol family not supported"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_notdb
argument_list|,
literal|"dropped-no-tdb"
argument_list|,
literal|"packet%s dropped; no TDB"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_badkcr
argument_list|,
literal|"dropped-bad-kcr"
argument_list|,
literal|"packet%s dropped; bad KCR"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_qfull
argument_list|,
literal|"dropped-queue-full"
argument_list|,
literal|"packet%s dropped; queue full"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_noxform
argument_list|,
literal|"dropped-no-transform"
argument_list|,
literal|"packet%s dropped; no transform"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_badilen
argument_list|,
literal|"dropped-bad-length"
argument_list|,
literal|"packet%s dropped; bad ilen"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_wrap
argument_list|,
literal|"replay-counter-wraps"
argument_list|,
literal|"replay counter wrap%s"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_badenc
argument_list|,
literal|"dropped-bad-crypto"
argument_list|,
literal|"packet%s dropped; bad encryption detected"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_badauth
argument_list|,
literal|"dropped-bad-auth"
argument_list|,
literal|"packet%s dropped; bad authentication detected"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_replay
argument_list|,
literal|"possible-replay-detected"
argument_list|,
literal|"possible replay packet%s detected"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_input
argument_list|,
literal|"received-packets"
argument_list|,
literal|"packet%s in"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_output
argument_list|,
literal|"sent-packets"
argument_list|,
literal|"packet%s out"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_invalid
argument_list|,
literal|"dropped-bad-tdb"
argument_list|,
literal|"packet%s dropped; invalid TDB"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_ibytes
argument_list|,
literal|"receieve-bytes"
argument_list|,
literal|"byte%s in"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_obytes
argument_list|,
literal|"sent-bytes"
argument_list|,
literal|"byte%s out"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_toobig
argument_list|,
literal|"dropped-too-large"
argument_list|,
literal|"packet%s dropped; larger than IP_MAXPACKET"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_pdrops
argument_list|,
literal|"dropped-policy-violation"
argument_list|,
literal|"packet%s blocked due to policy"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_crypto
argument_list|,
literal|"crypto-failures"
argument_list|,
literal|"crypto processing failure%s"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|esps_tunnel
argument_list|,
literal|"tunnel-failures"
argument_list|,
literal|"tunnel sanity check failure%s"
argument_list|)
expr_stmt|;
name|hist
argument_list|(
name|espstat
operator|->
name|esps_hist
argument_list|,
name|ipsec_espnames
argument_list|,
literal|"ESP output"
argument_list|,
literal|"esp-output-histogram"
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|p
undef|#
directive|undef
name|hist
name|xo_close_container
argument_list|(
literal|"esp-statictics"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|esp_stats
parameter_list|(
name|u_long
name|off
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|family
name|__unused
parameter_list|,
name|int
name|proto
name|__unused
parameter_list|)
block|{
name|struct
name|espstat
name|espstat
decl_stmt|;
if|if
condition|(
name|off
operator|==
literal|0
condition|)
return|return;
name|xo_emit
argument_list|(
literal|"{T:/%s}:\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|kread_counters
argument_list|(
name|off
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|espstat
argument_list|,
sizeof|sizeof
argument_list|(
name|espstat
argument_list|)
argument_list|)
expr_stmt|;
name|print_espstats
argument_list|(
operator|&
name|espstat
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_ipcompstats
parameter_list|(
specifier|const
name|struct
name|ipcompstat
modifier|*
name|ipcompstat
parameter_list|)
block|{
name|xo_open_container
argument_list|(
literal|"ipcomp-statictics"
argument_list|)
expr_stmt|;
define|#
directive|define
name|p
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|)
value|if (ipcompstat->f || sflag<= 1)	\ 	xo_emit("\t{:" n "/%ju} {N:/" m "}\n",		\ 	    (uintmax_t)ipcompstat->f, plural(ipcompstat->f))
define|#
directive|define
name|hist
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
define|\
value|ipsec_hist_new((f), sizeof(f)/sizeof(f[0]), (n), (t), (c));
name|p
argument_list|(
name|ipcomps_hdrops
argument_list|,
literal|"dropped-short-header"
argument_list|,
literal|"packet%s shorter than header shows"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_nopf
argument_list|,
literal|"dropped-bad-protocol"
argument_list|,
literal|"packet%s dropped; protocol family not supported"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_notdb
argument_list|,
literal|"dropped-no-tdb"
argument_list|,
literal|"packet%s dropped; no TDB"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_badkcr
argument_list|,
literal|"dropped-bad-kcr"
argument_list|,
literal|"packet%s dropped; bad KCR"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_qfull
argument_list|,
literal|"dropped-queue-full"
argument_list|,
literal|"packet%s dropped; queue full"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_noxform
argument_list|,
literal|"dropped-no-transform"
argument_list|,
literal|"packet%s dropped; no transform"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_wrap
argument_list|,
literal|"replay-counter-wraps"
argument_list|,
literal|"replay counter wrap%s"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_input
argument_list|,
literal|"receieve-packets"
argument_list|,
literal|"packet%s in"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_output
argument_list|,
literal|"sent-packets"
argument_list|,
literal|"packet%s out"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_invalid
argument_list|,
literal|"dropped-bad-tdb"
argument_list|,
literal|"packet%s dropped; invalid TDB"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_ibytes
argument_list|,
literal|"receieved-bytes"
argument_list|,
literal|"byte%s in"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_obytes
argument_list|,
literal|"sent-bytes"
argument_list|,
literal|"byte%s out"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_toobig
argument_list|,
literal|"dropped-too-large"
argument_list|,
literal|"packet%s dropped; larger than IP_MAXPACKET"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_pdrops
argument_list|,
literal|"dropped-policy-violation"
argument_list|,
literal|"packet%s blocked due to policy"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_crypto
argument_list|,
literal|"crypto-failure"
argument_list|,
literal|"crypto processing failure%s"
argument_list|)
expr_stmt|;
name|hist
argument_list|(
name|ipcompstat
operator|->
name|ipcomps_hist
argument_list|,
name|ipsec_compnames
argument_list|,
literal|"COMP output"
argument_list|,
literal|"comp-output-histogram"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_threshold
argument_list|,
literal|"sent-uncompressed-small-packets"
argument_list|,
literal|"packet%s sent uncompressed; size< compr. algo. threshold"
argument_list|)
expr_stmt|;
name|p
argument_list|(
name|ipcomps_uncompr
argument_list|,
literal|"sent-uncompressed-useless-packets"
argument_list|,
literal|"packet%s sent uncompressed; compression was useless"
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|p
undef|#
directive|undef
name|hist
name|xo_close_container
argument_list|(
literal|"ipcomp-statictics"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ipcomp_stats
parameter_list|(
name|u_long
name|off
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|family
name|__unused
parameter_list|,
name|int
name|proto
name|__unused
parameter_list|)
block|{
name|struct
name|ipcompstat
name|ipcompstat
decl_stmt|;
if|if
condition|(
name|off
operator|==
literal|0
condition|)
return|return;
name|xo_emit
argument_list|(
literal|"{T:/%s}:\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|kread_counters
argument_list|(
name|off
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|ipcompstat
argument_list|,
sizeof|sizeof
argument_list|(
name|ipcompstat
argument_list|)
argument_list|)
expr_stmt|;
name|print_ipcompstats
argument_list|(
operator|&
name|ipcompstat
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*IPSEC*/
end_comment

end_unit

