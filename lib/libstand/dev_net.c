begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: dev_net.c,v 1.12 1997/12/10 20:38:37 gwr Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Gordon W. Ross.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This module implements a "raw device" interface suitable for  * use by the stand-alone I/O library NFS code.  This interface  * does not support any "block" access, and exists only for the  * purpose of initializing the network interface, getting boot  * parameters, and performing the NFS mount.  *  * At open time, this does:  *  * find interface      - netif_open()  * RARP for IP address - rarp_getipaddress()  * RPC/bootparams      - callrpc(d, RPC_BOOTPARAMS, ...)  * RPC/mountd          - nfs_mount(sock, ip, path)  *  * the root file handle from mountd is saved in a global  * for use by the NFS open code (NFS/lookup).  */
end_comment

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|"stand.h"
end_include

begin_include
include|#
directive|include
file|"net.h"
end_include

begin_include
include|#
directive|include
file|"netif.h"
end_include

begin_include
include|#
directive|include
file|"nfs.h"
end_include

begin_include
include|#
directive|include
file|"bootparam.h"
end_include

begin_include
include|#
directive|include
file|"dev_net.h"
end_include

begin_decl_stmt
specifier|static
name|int
name|netdev_sock
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|netdev_opens
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|net_getparams
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|net_print
parameter_list|(
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|devsw
name|netdev
init|=
block|{
literal|"net"
block|,
name|DEVT_NET
block|,
name|net_init
block|,
name|net_strategy
block|,
name|net_open
block|,
name|net_close
block|,
name|noioctl
name|net_print
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Print stuff about our net 'device'.  */
end_comment

begin_function
specifier|static
name|void
name|net_print
parameter_list|(
name|int
name|verbose
parameter_list|)
block|{
name|pager_output
argument_list|(
literal|"    net:  network interface"
argument_list|)
expr_stmt|;
comment|/* XXX much more verbose stuff here */
block|}
end_function

begin_comment
comment|/*  * Called by devopen after it sets f->f_dev to our devsw entry.  * This opens the low-level device and sets f->f_devdata.  * This is declared with variable arguments...  */
end_comment

begin_function
name|int
name|net_open
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|vdev
parameter_list|)
block|{
name|char
modifier|*
name|devname
decl_stmt|;
comment|/* Device part of file name (or NULL). */
name|int
name|error
init|=
literal|0
decl_stmt|;
name|devname
operator|=
name|vdev
expr_stmt|;
ifdef|#
directive|ifdef
name|NETIF_DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"net_open: %s\n"
argument_list|,
name|devname
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* On first open, do netif open, mount, etc. */
if|if
condition|(
name|netdev_opens
operator|==
literal|0
condition|)
block|{
comment|/* Find network interface. */
if|if
condition|(
name|netdev_sock
operator|<
literal|0
condition|)
block|{
name|netdev_sock
operator|=
name|netif_open
argument_list|(
name|devname
argument_list|)
expr_stmt|;
if|if
condition|(
name|netdev_sock
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"net_open: netif_open() failed\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"net_open: netif_open() succeeded\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rootip
operator|.
name|s_addr
operator|==
literal|0
condition|)
block|{
comment|/* Get root IP address, and path, etc. */
name|error
operator|=
name|net_getparams
argument_list|(
name|netdev_sock
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
comment|/* getparams makes its own noise */
name|netif_close
argument_list|(
name|netdev_sock
argument_list|)
expr_stmt|;
name|netdev_sock
operator|=
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
block|}
block|}
name|netdev_opens
operator|++
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
name|int
name|net_close
parameter_list|(
name|f
parameter_list|)
name|struct
name|open_file
modifier|*
name|f
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|NETIF_DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"net_close: opens=%d\n"
argument_list|,
name|netdev_opens
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* On last close, do netif close, etc. */
name|f
operator|->
name|f_devdata
operator|=
name|NULL
expr_stmt|;
comment|/* Extra close call? */
if|if
condition|(
name|netdev_opens
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|netdev_opens
operator|--
expr_stmt|;
comment|/* Not last close? */
if|if
condition|(
name|netdev_opens
operator|>
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|rootip
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|netdev_sock
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"net_close: calling netif_close()\n"
argument_list|)
expr_stmt|;
name|netif_close
argument_list|(
name|netdev_sock
argument_list|)
expr_stmt|;
name|netdev_sock
operator|=
operator|-
literal|1
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|net_ioctl
parameter_list|()
block|{
return|return
name|EIO
return|;
block|}
end_function

begin_function
name|int
name|net_strategy
parameter_list|()
block|{
return|return
name|EIO
return|;
block|}
end_function

begin_comment
comment|/*  * Get info for NFS boot: our IP address, our hostname,  * server IP address, and our root path on the server.  * There are two ways to do this:  The old, Sun way,  * and the more modern, BOOTP way. (RFC951, RFC1048)  *  * The default is to use the Sun bootparams RPC  * (because that is what the kernel will do).  * MD code can make try_bootp initialied data,  * which will override this common definition.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_BOOTP
end_ifdef

begin_decl_stmt
name|int
name|try_bootp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|bootp
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|int
name|net_getparams
parameter_list|(
name|sock
parameter_list|)
name|int
name|sock
decl_stmt|;
block|{
name|char
name|buf
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|n_long
name|smask
decl_stmt|;
ifdef|#
directive|ifdef
name|SUPPORT_BOOTP
comment|/* 	 * Try to get boot info using BOOTP.  If we succeed, then 	 * the server IP address, gateway, and root path will all 	 * be initialized.  If any remain uninitialized, we will 	 * use RARP and RPC/bootparam (the Sun way) to get them. 	 */
if|if
condition|(
name|try_bootp
condition|)
name|bootp
argument_list|(
name|sock
argument_list|)
expr_stmt|;
if|if
condition|(
name|myip
operator|.
name|s_addr
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"net_open: BOOTP failed, trying RARP/RPC...\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Use RARP to get our IP address.  This also sets our 	 * netmask to the "natural" default for our address. 	 */
if|if
condition|(
name|rarp_getipaddress
argument_list|(
name|sock
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"net_open: RARP failed\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
name|printf
argument_list|(
literal|"net_open: client addr: %s\n"
argument_list|,
name|inet_ntoa
argument_list|(
name|myip
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Get our hostname, server IP address, gateway. */
if|if
condition|(
name|bp_whoami
argument_list|(
name|sock
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"net_open: bootparam/whoami RPC failed\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
name|printf
argument_list|(
literal|"net_open: client name: %s\n"
argument_list|,
name|hostname
argument_list|)
expr_stmt|;
comment|/* 	 * Ignore the gateway from whoami (unreliable). 	 * Use the "gateway" parameter instead. 	 */
name|smask
operator|=
literal|0
expr_stmt|;
name|gateip
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|bp_getfile
argument_list|(
name|sock
argument_list|,
literal|"gateway"
argument_list|,
operator|&
name|gateip
argument_list|,
name|buf
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* Got it!  Parse the netmask. */
name|smask
operator|=
name|ip_convertaddr
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|smask
condition|)
block|{
name|netmask
operator|=
name|smask
expr_stmt|;
name|printf
argument_list|(
literal|"net_open: subnet mask: %s\n"
argument_list|,
name|intoa
argument_list|(
name|netmask
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|gateip
operator|.
name|s_addr
condition|)
name|printf
argument_list|(
literal|"net_open: net gateway: %s\n"
argument_list|,
name|inet_ntoa
argument_list|(
name|gateip
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Get the root server and pathname. */
if|if
condition|(
name|bp_getfile
argument_list|(
name|sock
argument_list|,
literal|"root"
argument_list|,
operator|&
name|rootip
argument_list|,
name|rootpath
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"net_open: bootparam/getfile RPC failed\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
name|printf
argument_list|(
literal|"net_open: server addr: %s\n"
argument_list|,
name|inet_ntoa
argument_list|(
name|rootip
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"net_open: server path: %s\n"
argument_list|,
name|rootpath
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

