begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_comment
comment|/*  * 29/12/94 Added code from Marc Huber<huber@fzi.de> to allow it to allocate  * its own major char number! Way cool patch!  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD__
operator|>
literal|1
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LKM
end_ifdef

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_define
define|#
directive|define
name|ACTUALLY_LKM_NOT_KERNEL
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/osreldate.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|220000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEVFS
end_ifdef

begin_include
include|#
directive|include
file|<sys/devfsext.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DEVFS*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199506
end_if

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|199511
operator|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD__
operator|>
literal|1
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_include
include|#
directive|include
file|"netinet/ip_compat.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_fil.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_rules.h"
end_include

begin_decl_stmt
name|int
name|xxxinit
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|||
operator|(
name|__FreeBSD_version
operator|<
literal|220000
operator|)
end_if

begin_expr_stmt
name|MOD_DEV
argument_list|(
name|IPL_VERSION
argument_list|,
name|LM_DT_CHAR
argument_list|,
operator|-
literal|1
argument_list|,
operator|&
name|ipldevsw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|ipfrule_ioctl
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|<
literal|220000
operator|)
end_if

begin_function
name|int
name|xxxinit
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
name|ipfrule_ioctl
argument_list|,
name|ipfrule_ioctl
argument_list|,
name|ipfrule_ioctl
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __FREEBSD_version>= 220000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LKM
end_ifdef

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
end_if

begin_expr_stmt
name|MOD_MISC
argument_list|(
name|ipfrule
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|MOD_DECL
argument_list|(
name|ipfrule
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|struct
name|lkm_misc
name|_module
init|=
block|{
name|LM_MISC
block|,
name|LKM_VERSION
block|,
literal|"IP Filter rules"
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
name|MOD_DISPATCH
argument_list|(
name|ipfrule
argument_list|,
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|ipfrule_ioctl
argument_list|,
name|ipfrule_ioctl
argument_list|,
name|ipfrule_ioctl
argument_list|)
expr_stmt|;
else|#
directive|else
name|DISPATCH
argument_list|(
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|ipfrule_ioctl
argument_list|,
name|ipfrule_ioctl
argument_list|,
name|ipfrule_ioctl
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPFILTER_LKM */
end_comment

begin_function
name|int
name|ipfrule_load
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
return|return
name|ipfrule_add
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|ipfrule_unload
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
return|return
name|ipfrule_remove
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ipfrule_ioctl
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
name|ipfrule_load
argument_list|(
name|lkmtp
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
name|fr_refcnt
operator|++
expr_stmt|;
break|break;
case|case
name|LKM_E_UNLOAD
case|:
name|err
operator|=
name|ipfrule_unload
argument_list|(
name|lkmtp
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
name|fr_refcnt
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
comment|/* _FreeBSD_version */
end_comment

end_unit

