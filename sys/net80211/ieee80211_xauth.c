begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Video54 Technologies, Inc.  * Copyright (c) 2004-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|"opt_wlan.h"
end_include

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
comment|/* XXX number of references from net80211 layer; needed for module code */
end_comment

begin_decl_stmt
specifier|static
name|int
name|nrefs
init|=
literal|0
decl_stmt|;
end_decl_stmt

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

begin_expr_stmt
name|IEEE80211_AUTH_MODULE
argument_list|(
name|xauth
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|IEEE80211_AUTH_ALG
argument_list|(
name|x8021x
argument_list|,
name|IEEE80211_AUTH_8021X
argument_list|,
name|xauth
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|IEEE80211_AUTH_ALG
argument_list|(
name|wpa
argument_list|,
name|IEEE80211_AUTH_WPA
argument_list|,
name|xauth
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

