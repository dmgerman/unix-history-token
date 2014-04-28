begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Bernhard Schmidt<bschmidt@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
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
file|<sys/sysctl.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_ratectl.h>
end_include

begin_function
specifier|static
name|void
name|none_init
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|none_deinit
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
block|{
name|free
argument_list|(
name|vap
operator|->
name|iv_rs
argument_list|,
name|M_80211_RATECTL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|none_node_init
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|)
block|{
name|ni
operator|->
name|ni_txrate
operator|=
name|ni
operator|->
name|ni_rates
operator|.
name|rs_rates
index|[
literal|0
index|]
operator|&
name|IEEE80211_RATE_VAL
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|none_node_deinit
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|int
name|none_rate
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|void
modifier|*
name|arg
name|__unused
parameter_list|,
name|uint32_t
name|iarg
name|__unused
parameter_list|)
block|{
name|int
name|rix
init|=
literal|0
decl_stmt|;
name|ni
operator|->
name|ni_txrate
operator|=
name|ni
operator|->
name|ni_rates
operator|.
name|rs_rates
index|[
name|rix
index|]
operator|&
name|IEEE80211_RATE_VAL
expr_stmt|;
return|return
name|rix
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|none_tx_complete
parameter_list|(
specifier|const
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
specifier|const
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|int
name|ok
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|void
modifier|*
name|arg2
name|__unused
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|none_tx_update
parameter_list|(
specifier|const
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
specifier|const
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|,
name|void
modifier|*
name|arg3
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|none_setinterval
parameter_list|(
specifier|const
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|int
name|msecs
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* number of references from net80211 layer */
end_comment

begin_decl_stmt
specifier|static
name|int
name|nrefs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ieee80211_ratectl
name|none
init|=
block|{
operator|.
name|ir_name
operator|=
literal|"none"
block|,
operator|.
name|ir_attach
operator|=
name|NULL
block|,
operator|.
name|ir_detach
operator|=
name|NULL
block|,
operator|.
name|ir_init
operator|=
name|none_init
block|,
operator|.
name|ir_deinit
operator|=
name|none_deinit
block|,
operator|.
name|ir_node_init
operator|=
name|none_node_init
block|,
operator|.
name|ir_node_deinit
operator|=
name|none_node_deinit
block|,
operator|.
name|ir_rate
operator|=
name|none_rate
block|,
operator|.
name|ir_tx_complete
operator|=
name|none_tx_complete
block|,
operator|.
name|ir_tx_update
operator|=
name|none_tx_update
block|,
operator|.
name|ir_setinterval
operator|=
name|none_setinterval
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|IEEE80211_RATECTL_MODULE
argument_list|(
name|ratectl_none
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|IEEE80211_RATECTL_ALG
argument_list|(
name|none
argument_list|,
name|IEEE80211_RATECTL_NONE
argument_list|,
name|none
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

