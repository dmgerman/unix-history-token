begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_comment
comment|/*  * 29/12/94 Added code from Marc Huber<huber@fzi.de> to allow it to allocate  * its own major char number! Way cool patch!  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sundev/mbvar.h>
end_include

begin_include
include|#
directive|include
file|<sun/autoconf.h>
end_include

begin_include
include|#
directive|include
file|<sun/vddrv.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun4c
argument_list|)
operator|||
name|defined
argument_list|(
name|sun4m
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sun/openprom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<netinet/ip.h>
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
file|<net/if.h>
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

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xxxinit
name|__P
argument_list|(
operator|(
name|u_int
operator|,
expr|struct
name|vddrv
operator|*
operator|,
name|caddr_t
operator|,
expr|struct
name|vdstat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipl_major
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|sun4m
end_ifdef

begin_decl_stmt
name|struct
name|vdldrv
name|vd
init|=
block|{
name|VDMAGIC_USER
block|,
literal|"IP Filter rules"
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sun4m */
end_comment

begin_decl_stmt
name|struct
name|vdldrv
name|vd
init|=
block|{
name|VDMAGIC_USER
block|,
comment|/* magic */
literal|"IP Filter rules"
block|,
ifdef|#
directive|ifdef
name|sun4c
name|NULL
block|,
comment|/* dev_ops */
else|#
directive|else
name|NULL
block|,
comment|/* struct mb_ctlr *mb_ctlr */
name|NULL
block|,
comment|/* struct mb_driver *mb_driver */
name|NULL
block|,
comment|/* struct mb_device *mb_device */
literal|0
block|,
comment|/* num ctlrs */
literal|1
block|,
comment|/* numdevs */
endif|#
directive|endif
comment|/* sun4c */
name|NULL
block|,
comment|/* bdevsw */
name|NULL
block|,
comment|/* cdevsw */
literal|0
block|,
comment|/* block major */
literal|0
block|,
comment|/* char major */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun4m */
end_comment

begin_macro
name|xxxinit
argument_list|(
argument|fc
argument_list|,
argument|vdp
argument_list|,
argument|data
argument_list|,
argument|vds
argument_list|)
end_macro

begin_decl_stmt
name|u_int
name|fc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vddrv
modifier|*
name|vdp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vdstat
modifier|*
name|vds
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|vdioctl_load
modifier|*
name|vdi
init|=
operator|(
expr|struct
name|vdioctl_load
operator|*
operator|)
name|data
decl_stmt|;
name|int
name|err
decl_stmt|;
switch|switch
condition|(
name|fc
condition|)
block|{
case|case
name|VDLOAD
case|:
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
name|VDUNLOAD
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
name|VDSTAT
case|:
name|err
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
name|err
operator|=
name|EIO
expr_stmt|;
break|break;
block|}
block|}
end_block

end_unit

