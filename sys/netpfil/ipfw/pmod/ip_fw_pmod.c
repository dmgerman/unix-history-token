begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Yandex LLC  * Copyright (c) 2017 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
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
file|<net/vnet.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_fw.h>
end_include

begin_include
include|#
directive|include
file|<netpfil/ipfw/ip_fw_private.h>
end_include

begin_include
include|#
directive|include
file|<netpfil/ipfw/pmod/pmod.h>
end_include

begin_function
specifier|static
name|int
name|vnet_ipfw_pmod_init
parameter_list|(
specifier|const
name|void
modifier|*
name|arg
name|__unused
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
name|tcpmod_init
argument_list|(
operator|&
name|V_layer3_chain
argument_list|,
name|IS_DEFAULT_VNET
argument_list|(
name|curvnet
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vnet_ipfw_pmod_uninit
parameter_list|(
specifier|const
name|void
modifier|*
name|arg
name|__unused
parameter_list|)
block|{
name|tcpmod_uninit
argument_list|(
operator|&
name|V_layer3_chain
argument_list|,
name|IS_DEFAULT_VNET
argument_list|(
name|curvnet
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ipfw_pmod_modevent
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
case|case
name|MOD_UNLOAD
case|:
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
name|ipfw_pmod_mod
init|=
block|{
literal|"ipfw_pmod"
block|,
name|ipfw_pmod_modevent
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define startup order. */
end_comment

begin_define
define|#
directive|define
name|IPFW_PMOD_SI_SUB_FIREWALL
value|SI_SUB_PROTO_IFATTACHDOMAIN
end_define

begin_define
define|#
directive|define
name|IPFW_PMOD_MODEVENT_ORDER
value|(SI_ORDER_ANY - 128)
end_define

begin_comment
comment|/* after ipfw */
end_comment

begin_define
define|#
directive|define
name|IPFW_PMOD_MODULE_ORDER
value|(IPFW_PMOD_MODEVENT_ORDER + 1)
end_define

begin_define
define|#
directive|define
name|IPFW_PMOD_VNET_ORDER
value|(IPFW_PMOD_MODEVENT_ORDER + 2)
end_define

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|ipfw_pmod
argument_list|,
name|ipfw_pmod_mod
argument_list|,
name|IPFW_PMOD_SI_SUB_FIREWALL
argument_list|,
name|IPFW_PMOD_MODULE_ORDER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ipfw_pmod
argument_list|,
name|ipfw
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ipfw_pmod
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_SYSINIT
argument_list|(
name|vnet_ipfw_pmod_init
argument_list|,
name|IPFW_PMOD_SI_SUB_FIREWALL
argument_list|,
name|IPFW_PMOD_VNET_ORDER
argument_list|,
name|vnet_ipfw_pmod_init
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_SYSUNINIT
argument_list|(
name|vnet_ipfw_pmod_uninit
argument_list|,
name|IPFW_PMOD_SI_SUB_FIREWALL
argument_list|,
name|IPFW_PMOD_VNET_ORDER
argument_list|,
name|vnet_ipfw_pmod_uninit
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

