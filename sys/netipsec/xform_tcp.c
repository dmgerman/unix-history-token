begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003 Bruce M. Simpson<bms@spc.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *   notice, this list of conditions and the following disclaimer in the  *   documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *   derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* TCP MD5 Signature Option (RFC2385) */
end_comment

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_var.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ipsec.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/xform.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ipsec6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netipsec/key.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/key_debug.h>
end_include

begin_comment
comment|/*  * Initialize a TCP-MD5 SA. Called when the SA is being set up.  *  * We don't need to set up the tdb prefixed fields, as we don't use the  * opencrypto code; we just perform a key length check.  *  * XXX: Currently we only allow a single 'magic' SPI to be used.  *  * This allows per-host granularity without affecting the userland  * interface, which is a simple socket option toggle switch,  * TCP_SIGNATURE_ENABLE.  *  * To allow per-service granularity requires that we have a means  * of mapping port to SPI. The mandated way of doing this is to  * use SPD entries to specify packet flows which get the TCP-MD5  * treatment, however the code to do this is currently unstable  * and unsuitable for production use.  *  * Therefore we use this compromise in the meantime.  */
end_comment

begin_function
specifier|static
name|int
name|tcpsignature_init
parameter_list|(
name|struct
name|secasvar
modifier|*
name|sav
parameter_list|,
name|struct
name|xformsw
modifier|*
name|xsp
parameter_list|)
block|{
name|int
name|keylen
decl_stmt|;
if|if
condition|(
name|sav
operator|->
name|spi
operator|!=
name|htonl
argument_list|(
name|TCP_SIG_SPI
argument_list|)
condition|)
block|{
name|DPRINTF
argument_list|(
operator|(
literal|"%s: SPI must be TCP_SIG_SPI (0x1000)\n"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
if|if
condition|(
name|sav
operator|->
name|alg_auth
operator|!=
name|SADB_X_AALG_TCP_MD5
condition|)
block|{
name|DPRINTF
argument_list|(
operator|(
literal|"%s: unsupported authentication algorithm %u\n"
operator|,
name|__func__
operator|,
name|sav
operator|->
name|alg_auth
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
if|if
condition|(
name|sav
operator|->
name|key_auth
operator|==
name|NULL
condition|)
block|{
name|DPRINTF
argument_list|(
operator|(
literal|"%s: no authentication key present\n"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
name|keylen
operator|=
name|_KEYLEN
argument_list|(
name|sav
operator|->
name|key_auth
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|keylen
operator|<
name|TCP_KEYLEN_MIN
operator|)
operator|||
operator|(
name|keylen
operator|>
name|TCP_KEYLEN_MAX
operator|)
condition|)
block|{
name|DPRINTF
argument_list|(
operator|(
literal|"%s: invalid key length %u\n"
operator|,
name|__func__
operator|,
name|keylen
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Paranoia.  *  * Called when the SA is deleted.  */
end_comment

begin_function
specifier|static
name|int
name|tcpsignature_zeroize
parameter_list|(
name|struct
name|secasvar
modifier|*
name|sav
parameter_list|)
block|{
if|if
condition|(
name|sav
operator|->
name|key_auth
condition|)
name|bzero
argument_list|(
name|_KEYBUF
argument_list|(
name|sav
operator|->
name|key_auth
argument_list|)
argument_list|,
name|_KEYLEN
argument_list|(
name|sav
operator|->
name|key_auth
argument_list|)
argument_list|)
expr_stmt|;
name|sav
operator|->
name|tdb_cryptoid
operator|=
literal|0
expr_stmt|;
name|sav
operator|->
name|tdb_authalgxform
operator|=
name|NULL
expr_stmt|;
name|sav
operator|->
name|tdb_xform
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Verify that an input packet passes authentication.  * Called from the ipsec layer.  * We do this from within tcp itself, so this routine is just a stub.  */
end_comment

begin_function
specifier|static
name|int
name|tcpsignature_input
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|secasvar
modifier|*
name|sav
parameter_list|,
name|int
name|skip
parameter_list|,
name|int
name|protoff
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Prepend the authentication header.  * Called from the ipsec layer.  * We do this from within tcp itself, so this routine is just a stub.  */
end_comment

begin_function
specifier|static
name|int
name|tcpsignature_output
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|ipsecrequest
modifier|*
name|isr
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|,
name|int
name|skip
parameter_list|,
name|int
name|protoff
parameter_list|)
block|{
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|struct
name|xformsw
name|tcpsignature_xformsw
init|=
block|{
name|XF_TCPSIGNATURE
block|,
name|XFT_AUTH
block|,
literal|"TCPMD5"
block|,
name|tcpsignature_init
block|,
name|tcpsignature_zeroize
block|,
name|tcpsignature_input
block|,
name|tcpsignature_output
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|tcpsignature_attach
parameter_list|(
name|void
parameter_list|)
block|{
name|xform_register
argument_list|(
operator|&
name|tcpsignature_xformsw
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|SYSINIT
argument_list|(
argument|tcpsignature_xform_init
argument_list|,
argument|SI_SUB_DRIVERS
argument_list|,
argument|SI_ORDER_FIRST
argument_list|,
argument|tcpsignature_attach
argument_list|,
argument|NULL
argument_list|)
end_macro

end_unit

