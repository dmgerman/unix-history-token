begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-1998 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  */
end_comment

begin_comment
comment|/* #pragma ident   "@(#)solaris.c	1.12 6/5/96 (C) 1995 Darren Reed"*/
end_comment

begin_comment
comment|/*typedef unsigned int spustate_t;*/
end_comment

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cmn_err.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/moddefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/io.h>
end_include

begin_include
include|#
directive|include
file|<sys/wsio.h>
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
file|<sys/byteorder.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/af.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

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
file|<netinet/if_ether.h>
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
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcpip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_icmp.h>
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

begin_comment
comment|/*  * Driver Header  */
end_comment

begin_decl_stmt
specifier|static
name|drv_info_t
name|ipf_drv_info
init|=
block|{
literal|"IP Filter Rules"
block|,
comment|/* type */
literal|"pseudo"
block|,
comment|/* class */
name|DRV_PSEUDO
operator||
name|DRV_SAVE_CONF
operator||
name|DRV_MP_SAFE
block|,
comment|/* flags */
operator|-
literal|1
block|,
comment|/* b_major */
operator|-
literal|1
block|,
comment|/* c_major */
name|NULL
block|,
comment|/* cdio */
name|NULL
block|,
comment|/* gio_private */
name|NULL
block|,
comment|/* cdio_private */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mod_operations
name|gio_mod_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|drv_info_t
name|ipf_drv_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mod_conf_data
name|ipf_conf_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mod_type_data
name|ipf_drv_link
init|=
block|{
name|IPL_VERSION
block|,
operator|(
name|void
operator|*
operator|)
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|modlink
name|ipf_mod_link
index|[]
init|=
block|{
block|{
operator|&
name|gio_mod_ops
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|ipf_drv_link
block|}
block|,
block|{
name|NULL
block|,
operator|(
name|void
operator|*
operator|)
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|modwrapper
name|ipf_wrapper
init|=
block|{
name|MODREV
block|,
name|ipf_load
block|,
name|ipf_unload
block|,
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|NULL
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|ipf_conf_data
block|,
name|ipf_mod_link
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|ipf_load
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
name|ipfrule_add
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|i
condition|)
name|fr_refcnt
operator|--
expr_stmt|;
ifdef|#
directive|ifdef
name|IPFDEBUG
name|printf
argument_list|(
literal|"IP Filter Rules: ipfrule_add() = %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|i
condition|)
name|cmn_err
argument_list|(
name|CE_CONT
argument_list|,
literal|"IP Filter Rules: Loaded\n"
argument_list|)
expr_stmt|;
return|return
name|i
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ipf_unload
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
name|ipfrule_remove
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|i
condition|)
name|fr_refcnt
operator|--
expr_stmt|;
ifdef|#
directive|ifdef
name|IPFDEBUG
name|printf
argument_list|(
literal|"IP Filter Rules: ipfrule_remove() = %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|i
condition|)
name|cmn_err
argument_list|(
name|CE_CONT
argument_list|,
literal|"IP Filter Rules: Unloaded\n"
argument_list|)
expr_stmt|;
return|return
name|i
return|;
block|}
end_function

end_unit

