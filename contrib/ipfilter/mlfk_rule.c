begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * Id: mlfk_rule.c,v 2.4.4.2 2004/04/16 23:32:08 darrenr Exp  */
end_comment

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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
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
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ipl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_compat.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_fil.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_state.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_nat.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_auth.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_frag.h>
end_include

begin_include
include|#
directive|include
file|"ip_rules.h"
end_include

begin_function
specifier|static
name|int
name|ipfrule_modevent
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
name|int
name|error
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|MOD_LOAD
case|:
name|error
operator|=
name|ipfrule_add
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|fr_refcnt
operator|++
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
name|error
operator|=
name|ipfrule_remove
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|fr_refcnt
operator|--
expr_stmt|;
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
return|return
name|error
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|moduledata_t
name|ipfrulemod
init|=
block|{
literal|"ipfrule"
block|,
name|ipfrule_modevent
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|ipfrule
argument_list|,
name|ipfrulemod
argument_list|,
name|SI_SUB_PROTO_DOMAIN
argument_list|,
name|SI_ORDER_ANY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MODULE_DEPEND
end_ifdef

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ipfrule
argument_list|,
name|ipfilter
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

begin_ifdef
ifdef|#
directive|ifdef
name|MODULE_VERSION
end_ifdef

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ipfrule
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

