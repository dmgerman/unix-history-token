begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Video54 Technologies, Inc.  * Copyright (c) 2004-2005 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

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

begin_comment
comment|/*  * External authenticator placeholder module.  *  * This support is optional; it is only used when the 802.11 layer's  * authentication mode is set to use 802.1x or WPA is enabled separately  * (for WPA-PSK).  If compiled as a module this code does not need  * to be present unless 802.1x/WPA is in use.  *  * The authenticator hooks into the 802.11 layer.  At present we use none  * of the available callbacks--the user mode authenticator process works  * entirely from messages about stations joining and leaving.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<sys/module.h>
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
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_comment
comment|/*  * One module handles everything for now.  May want  * to split things up for embedded applications.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ieee80211_authenticator
name|xauth
init|=
block|{
operator|.
name|ia_name
operator|=
literal|"external"
block|,
operator|.
name|ia_attach
operator|=
name|NULL
block|,
operator|.
name|ia_detach
operator|=
name|NULL
block|,
operator|.
name|ia_node_join
operator|=
name|NULL
block|,
operator|.
name|ia_node_leave
operator|=
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Module glue.  */
end_comment

begin_function
specifier|static
name|int
name|wlan_xauth_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|unused
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|MOD_LOAD
case|:
name|ieee80211_authenticator_register
argument_list|(
name|IEEE80211_AUTH_8021X
argument_list|,
operator|&
name|xauth
argument_list|)
expr_stmt|;
name|ieee80211_authenticator_register
argument_list|(
name|IEEE80211_AUTH_WPA
argument_list|,
operator|&
name|xauth
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
case|case
name|MOD_UNLOAD
case|:
name|ieee80211_authenticator_unregister
argument_list|(
name|IEEE80211_AUTH_8021X
argument_list|)
expr_stmt|;
name|ieee80211_authenticator_unregister
argument_list|(
name|IEEE80211_AUTH_WPA
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|EINVAL
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|moduledata_t
name|wlan_xauth_mod
init|=
block|{
literal|"wlan_xauth"
block|,
name|wlan_xauth_modevent
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|wlan_xauth
argument_list|,
name|wlan_xauth_mod
argument_list|,
name|SI_SUB_DRIVERS
argument_list|,
name|SI_ORDER_FIRST
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|wlan_xauth
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|wlan_xauth
argument_list|,
name|wlan
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

