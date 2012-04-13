begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Monthadar Al Jaberi, TerraNet AB  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
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
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<sys/jail.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_llc.h>
end_include

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_regdomain.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_comment
comment|/* cdevsw struct */
end_comment

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_comment
comment|/* uio struct */
end_comment

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

begin_include
include|#
directive|include
file|"if_wtapvar.h"
end_include

begin_include
include|#
directive|include
file|"if_wtapioctl.h"
end_include

begin_include
include|#
directive|include
file|"if_medium.h"
end_include

begin_include
include|#
directive|include
file|"wtap_hal/hal.h"
end_include

begin_comment
comment|/* WTAP PLUGINS */
end_comment

begin_include
include|#
directive|include
file|"plugins/visibility.h"
end_include

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_WTAP
argument_list|,
literal|"wtap"
argument_list|,
literal|"wtap wireless simulator"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_WTAP_PACKET
argument_list|,
literal|"wtap packet"
argument_list|,
literal|"wtap wireless simulator packet"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_WTAP_RXBUF
argument_list|,
literal|"wtap rxbuf"
argument_list|,
literal|"wtap wireless simulator recieve buffer"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_WTAP_PLUGIN
argument_list|,
literal|"wtap plugin"
argument_list|,
literal|"wtap wireless simulator plugin"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|struct
name|wtap_hal
modifier|*
name|hal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function prototypes */
end_comment

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|wtap_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cdev
modifier|*
name|sdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|wtap_cdevsw
init|=
block|{
operator|.
name|d_version
operator|=
name|D_VERSION
block|,
operator|.
name|d_flags
operator|=
literal|0
block|,
operator|.
name|d_ioctl
operator|=
name|wtap_ioctl
block|,
operator|.
name|d_name
operator|=
literal|"wtapctl"
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|wtap_ioctl
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|CURVNET_SET
argument_list|(
name|CRED_TO_VNET
argument_list|(
name|curthread
operator|->
name|td_ucred
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|WTAPIOCTLCRT
case|:
if|if
condition|(
name|new_wtap
argument_list|(
name|hal
argument_list|,
operator|*
operator|(
name|int
operator|*
operator|)
name|data
argument_list|)
condition|)
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
case|case
name|WTAPIOCTLDEL
case|:
if|if
condition|(
name|free_wtap
argument_list|(
name|hal
argument_list|,
operator|*
operator|(
name|int
operator|*
operator|)
name|data
argument_list|)
condition|)
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
default|default:
name|DWTAP_PRINTF
argument_list|(
literal|"Unkown WTAP IOCTL\n"
argument_list|)
expr_stmt|;
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
name|CURVNET_RESTORE
argument_list|()
expr_stmt|;
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/* The function called at load/unload. */
end_comment

begin_function
specifier|static
name|int
name|event_handler
parameter_list|(
name|module_t
name|module
parameter_list|,
name|int
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|visibility_plugin
modifier|*
name|plugin
decl_stmt|;
name|int
name|e
init|=
literal|0
decl_stmt|;
comment|/* Error, 0 for normal return status */
switch|switch
condition|(
name|event
condition|)
block|{
case|case
name|MOD_LOAD
case|:
name|sdev
operator|=
name|make_dev
argument_list|(
operator|&
name|wtap_cdevsw
argument_list|,
literal|0
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0600
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
literal|"wtapctl"
argument_list|)
expr_stmt|;
name|hal
operator|=
operator|(
expr|struct
name|wtap_hal
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|wtap_hal
argument_list|)
argument_list|,
name|M_WTAP
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|hal
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|wtap_hal
argument_list|)
argument_list|)
expr_stmt|;
name|init_hal
argument_list|(
name|hal
argument_list|)
expr_stmt|;
comment|/* Setting up a simple plugin */
name|plugin
operator|=
operator|(
expr|struct
name|visibility_plugin
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|visibility_plugin
argument_list|)
argument_list|,
name|M_WTAP_PLUGIN
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
name|plugin
operator|->
name|base
operator|.
name|wp_hal
operator|=
name|hal
expr_stmt|;
name|plugin
operator|->
name|base
operator|.
name|init
operator|=
name|visibility_init
expr_stmt|;
name|plugin
operator|->
name|base
operator|.
name|deinit
operator|=
name|visibility_deinit
expr_stmt|;
name|plugin
operator|->
name|base
operator|.
name|work
operator|=
name|visibility_work
expr_stmt|;
name|register_plugin
argument_list|(
name|hal
argument_list|,
operator|(
expr|struct
name|wtap_plugin
operator|*
operator|)
name|plugin
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Loaded wtap wireless simulator\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|destroy_dev
argument_list|(
name|sdev
argument_list|)
expr_stmt|;
name|deregister_plugin
argument_list|(
name|hal
argument_list|)
expr_stmt|;
name|deinit_hal
argument_list|(
name|hal
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|hal
argument_list|,
name|M_WTAP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Unloading wtap wireless simulator\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|e
operator|=
name|EOPNOTSUPP
expr_stmt|;
comment|/* Error, Operation Not Supported */
break|break;
block|}
return|return
operator|(
name|e
operator|)
return|;
block|}
end_function

begin_comment
comment|/* The second argument of DECLARE_MODULE. */
end_comment

begin_decl_stmt
specifier|static
name|moduledata_t
name|wtap_conf
init|=
block|{
literal|"wtap"
block|,
comment|/* module name */
name|event_handler
block|,
comment|/* event handler */
name|NULL
comment|/* extra data */
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|wtap
argument_list|,
name|wtap_conf
argument_list|,
name|SI_SUB_DRIVERS
argument_list|,
name|SI_ORDER_MIDDLE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|wtap
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

begin_comment
comment|/* 802.11 media layer */
end_comment

end_unit

