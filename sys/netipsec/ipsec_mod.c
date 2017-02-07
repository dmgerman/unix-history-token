begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|"opt_ipsec.h"
end_include

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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
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
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/rmlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockopt.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ipsec.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ipsec6.h>
end_include

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

begin_include
include|#
directive|include
file|<netipsec/ipsec_support.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ipsec_methods
name|ipv4_methods
init|=
block|{
operator|.
name|input
operator|=
name|ipsec4_input
block|,
operator|.
name|forward
operator|=
name|ipsec4_forward
block|,
operator|.
name|output
operator|=
name|ipsec4_output
block|,
operator|.
name|pcbctl
operator|=
name|ipsec4_pcbctl
block|,
operator|.
name|capability
operator|=
name|ipsec4_capability
block|,
operator|.
name|check_policy
operator|=
name|ipsec4_in_reject
block|,
operator|.
name|hdrsize
operator|=
name|ipsec_hdrsiz_inpcb
block|,
operator|.
name|udp_input
operator|=
name|udp_ipsec_input
block|,
operator|.
name|udp_pcbctl
operator|=
name|udp_ipsec_pcbctl
block|, }
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|KLD_MODULE
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ipsec_support
name|ipv4_ipsec
init|=
block|{
operator|.
name|enabled
operator|=
name|IPSEC_MODULE_ENABLED
block|,
operator|.
name|methods
operator|=
operator|&
name|ipv4_methods
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|ipsec_support
modifier|*
specifier|const
name|ipv4_ipsec_support
init|=
operator|&
name|ipv4_ipsec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KLD_MODULE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ipsec_methods
name|ipv6_methods
init|=
block|{
operator|.
name|input
operator|=
name|ipsec6_input
block|,
operator|.
name|forward
operator|=
name|ipsec6_forward
block|,
operator|.
name|output
operator|=
name|ipsec6_output
block|,
operator|.
name|pcbctl
operator|=
name|ipsec6_pcbctl
block|,
operator|.
name|capability
operator|=
name|ipsec6_capability
block|,
operator|.
name|check_policy
operator|=
name|ipsec6_in_reject
block|,
operator|.
name|hdrsize
operator|=
name|ipsec_hdrsiz_inpcb
block|, }
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|KLD_MODULE
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ipsec_support
name|ipv6_ipsec
init|=
block|{
operator|.
name|enabled
operator|=
name|IPSEC_MODULE_ENABLED
block|,
operator|.
name|methods
operator|=
operator|&
name|ipv6_methods
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|ipsec_support
modifier|*
specifier|const
name|ipv6_ipsec_support
init|=
operator|&
name|ipv6_ipsec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KLD_MODULE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_comment
comment|/*  * Always register ipsec module.  * Even when IPsec is build in the kernel, we need to have  * module registered. This will prevent to load ipsec.ko.  */
end_comment

begin_function
specifier|static
name|int
name|ipsec_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
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
comment|/* All xforms are registered via SYSINIT */
if|if
condition|(
operator|!
name|ipsec_initialized
argument_list|()
condition|)
return|return
operator|(
name|ENOMEM
operator|)
return|;
ifdef|#
directive|ifdef
name|KLD_MODULE
ifdef|#
directive|ifdef
name|INET
name|ipsec_support_enable
argument_list|(
name|ipv4_ipsec_support
argument_list|,
operator|&
name|ipv4_methods
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INET6
name|ipsec_support_enable
argument_list|(
name|ipv6_ipsec_support
argument_list|,
operator|&
name|ipv6_methods
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* KLD_MODULE */
break|break;
case|case
name|MOD_UNLOAD
case|:
comment|/* All xforms are unregistered via SYSUNINIT */
ifdef|#
directive|ifdef
name|KLD_MODULE
ifdef|#
directive|ifdef
name|INET
name|ipsec_support_disable
argument_list|(
name|ipv4_ipsec_support
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INET6
name|ipsec_support_disable
argument_list|(
name|ipv6_ipsec_support
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* KLD_MODULE */
break|break;
default|default:
return|return
operator|(
name|EOPNOTSUPP
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

begin_decl_stmt
specifier|static
name|moduledata_t
name|ipsec_mod
init|=
block|{
literal|"ipsec"
block|,
name|ipsec_modevent
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|ipsec
argument_list|,
name|ipsec_mod
argument_list|,
name|SI_SUB_PROTO_DOMAIN
argument_list|,
name|SI_ORDER_ANY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ipsec
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KLD_MODULE
end_ifdef

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ipsec
argument_list|,
name|ipsec_support
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

