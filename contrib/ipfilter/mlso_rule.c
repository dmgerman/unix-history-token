begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)$Id$"
end_pragma

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/modctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/open.h>
end_include

begin_include
include|#
directive|include
file|<sys/kmem.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/cmn_err.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/cred.h>
end_include

begin_include
include|#
directive|include
file|<sys/dditypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/autoconf.h>
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
file|<sys/dlpi.h>
end_include

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|6
end_if

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/ddi.h>
end_include

begin_include
include|#
directive|include
file|<sys/sunddi.h>
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
name|char
name|_depends_on
index|[]
init|=
literal|"drv/ipf"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipf_main_softc_t
name|ipfmain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mod_ops
name|mod_miscops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|modlmisc
name|ipfrulemod
init|=
block|{
operator|&
name|mod_miscops
block|,
literal|"IP Filter rules"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|modlinkage
name|modlink1
init|=
block|{
name|MODREV_1
block|,
operator|&
name|ipfrulemod
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|_init
parameter_list|()
block|{
name|int
name|ipfruleinst
decl_stmt|;
name|ipfruleinst
operator|=
name|mod_install
argument_list|(
operator|&
name|modlink1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|IPFRULEDEBUG
name|cmn_err
argument_list|(
name|CE_NOTE
argument_list|,
literal|"IP Filter Rules: _init() = %d"
argument_list|,
name|ipfruleinst
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ipfruleinst
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|ipfmain
operator|.
name|ipf_running
operator|>=
literal|0
condition|)
block|{
name|ipfruleinst
operator|=
name|ipfrule_add
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|ipfruleinst
condition|)
name|ipfmain
operator|.
name|ipf_refcnt
operator|++
expr_stmt|;
else|else
block|{
name|cmn_err
argument_list|(
name|CE_NOTE
argument_list|,
literal|"IP Filter Rules: ipfrule_add failed"
argument_list|)
expr_stmt|;
name|ipfruleinst
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
else|else
name|ipfruleinst
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|ipfruleinst
operator|==
literal|0
condition|)
name|cmn_err
argument_list|(
name|CE_CONT
argument_list|,
literal|"IP Filter Rules: loaded\n"
argument_list|)
expr_stmt|;
return|return
name|ipfruleinst
return|;
block|}
end_function

begin_function
name|int
name|_fini
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ipfruleinst
decl_stmt|;
name|ipfruleinst
operator|=
name|mod_remove
argument_list|(
operator|&
name|modlink1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|IPFRULEDEBUG
name|cmn_err
argument_list|(
name|CE_NOTE
argument_list|,
literal|"IP Filter Rules: _fini() = %d"
argument_list|,
name|ipfruleinst
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ipfruleinst
operator|==
literal|0
condition|)
block|{
name|ipfruleinst
operator|=
name|ipfrule_remove
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|ipfruleinst
condition|)
name|ipfmain
operator|.
name|ipf_refcnt
operator|--
expr_stmt|;
else|else
name|ipfruleinst
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|ipfruleinst
operator|==
literal|0
condition|)
name|cmn_err
argument_list|(
name|CE_CONT
argument_list|,
literal|"IP Filter Rules: unloaded\n"
argument_list|)
expr_stmt|;
return|return
name|ipfruleinst
return|;
block|}
end_function

begin_function
name|int
name|_info
parameter_list|(
name|modinfop
parameter_list|)
name|struct
name|modinfo
modifier|*
name|modinfop
decl_stmt|;
block|{
name|int
name|ipfruleinst
decl_stmt|;
name|ipfruleinst
operator|=
name|mod_info
argument_list|(
operator|&
name|modlink1
argument_list|,
name|modinfop
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|IPFRULEDEBUG
name|cmn_err
argument_list|(
name|CE_NOTE
argument_list|,
literal|"IP Filter Rules: _info(%x) = %x"
argument_list|,
name|modinfop
argument_list|,
name|ipfruleinst
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|ipfruleinst
return|;
block|}
end_function

end_unit

