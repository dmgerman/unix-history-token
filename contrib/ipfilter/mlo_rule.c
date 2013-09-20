begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  */
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
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
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
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
file|<netinet/tcpip.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_include
include|#
directive|include
file|"ip_compat.h"
end_include

begin_include
include|#
directive|include
file|"ip_fil.h"
end_include

begin_include
include|#
directive|include
file|"ip_rules.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LKM
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|ipfruleaction
name|__P
argument_list|(
operator|(
expr|struct
name|lkm_table
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipfrule
name|__P
argument_list|(
operator|(
expr|struct
name|lkm_table
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MOD_MISC
argument_list|(
literal|"IPFilter Rules"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|ipfrule
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|,
name|ver
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|,
name|ver
decl_stmt|;
block|{
name|DISPATCH
argument_list|(
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|ipfruleaction
argument_list|,
name|ipfruleaction
argument_list|,
name|ipfruleaction
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|lkmexists
name|__P
argument_list|(
operator|(
expr|struct
name|lkm_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in /sys/kern/kern_lkm.c */
end_comment

begin_function
specifier|static
name|int
name|ipfruleaction
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|;
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|LKM_E_LOAD
case|:
if|if
condition|(
name|lkmexists
argument_list|(
name|lkmtp
argument_list|)
condition|)
return|return
name|EEXIST
return|;
name|err
operator|=
name|ipfrule_add
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
name|ipf_refcnt
operator|++
expr_stmt|;
break|break;
case|case
name|LKM_E_UNLOAD
case|:
name|err
operator|=
name|ipfrule_remove
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
name|ipf_refcnt
operator|--
expr_stmt|;
break|break;
case|case
name|LKM_E_STAT
case|:
break|break;
default|default:
name|err
operator|=
name|EIO
expr_stmt|;
break|break;
block|}
return|return
name|err
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPFILTER_LKM */
end_comment

end_unit

