begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2003 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_define
define|#
directive|define
name|KERNEL
value|1
end_define

begin_define
define|#
directive|define
name|_KERNEL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/errno.h>
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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeout.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
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
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/byteorder.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/dditypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/kmem.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_include
include|#
directive|include
file|<net/af.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<netinet/ip.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<netinet/ip_icmp.h>
end_include

begin_include
include|#
directive|include
file|"netinet/ip_compat.h"
end_include

begin_include
include|#
directive|include
file|<netinet/tcpip.h>
end_include

begin_include
include|#
directive|include
file|"netinet/ip_fil.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_nat.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_frag.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_state.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_auth.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_proxy.h"
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

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|IPFILTER_LKM
end_ifndef

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|callout_handle
name|fr_slowtimer_ch
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
name|__NetBSD_Version__
operator|>=
literal|104230000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|callout
name|fr_slowtimer_ch
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/timeout.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|timeout
name|fr_slowtimer_ch
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END OF INCLUDES */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ip_frag.c	1.11 3/24/96 (C) 1993-2000 Darren Reed"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#)$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* static const char rcsid[] = "@(#)Id: ip_frag.c,v 2.77 2004/01/27 00:24:54 darrenr Exp"; */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
name|ipfr_list
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
modifier|*
name|ipfr_tail
init|=
operator|&
name|ipfr_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
modifier|*
name|ipfr_heads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
name|ipfr_natlist
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
modifier|*
name|ipfr_nattail
init|=
operator|&
name|ipfr_natlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
modifier|*
name|ipfr_nattab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
name|ipfr_ipidlist
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
modifier|*
name|ipfr_ipidtail
init|=
operator|&
name|ipfr_ipidlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
modifier|*
name|ipfr_ipidtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfrstat_t
name|ipfr_stats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipfr_inuse
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipfr_size
init|=
name|IPFT_SIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fr_ipfrttl
init|=
literal|120
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 60 seconds */
end_comment

begin_decl_stmt
name|int
name|fr_frag_lock
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fr_frag_init
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|fr_ticks
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
name|ipfr_newfrag
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|,
name|ipfr_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
name|fr_fraglookup
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ipfr_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|fr_fragdelete
name|__P
argument_list|(
operator|(
name|ipfr_t
operator|*
operator|,
name|ipfr_t
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_fraginit                                                 */
end_comment

begin_comment
comment|/* Returns:     int - 0 == success, -1 == error                             */
end_comment

begin_comment
comment|/* Parameters:  Nil                                                         */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Initialise the hash tables for the fragment cache lookups.               */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|fr_fraginit
parameter_list|()
block|{
name|KMALLOCS
argument_list|(
name|ipfr_heads
argument_list|,
name|ipfr_t
operator|*
operator|*
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ipfr_heads
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ipfr_heads
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|KMALLOCS
argument_list|(
name|ipfr_nattab
argument_list|,
name|ipfr_t
operator|*
operator|*
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ipfr_nattab
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ipfr_nattab
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|KMALLOCS
argument_list|(
name|ipfr_ipidtab
argument_list|,
name|ipfr_t
operator|*
operator|*
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ipfr_ipidtab
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ipfr_ipidtab
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|RWLOCK_INIT
argument_list|(
operator|&
name|ipf_frag
argument_list|,
literal|"ipf fragment rwlock"
argument_list|)
expr_stmt|;
name|fr_frag_init
operator|=
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_fragunload                                               */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  Nil                                                         */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Free all memory allocated whilst running and from initialisation.        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|fr_fragunload
parameter_list|()
block|{
if|if
condition|(
name|fr_frag_init
operator|==
literal|1
condition|)
block|{
name|fr_fragclear
argument_list|()
expr_stmt|;
name|RW_DESTROY
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
name|fr_frag_init
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|ipfr_heads
operator|!=
name|NULL
condition|)
name|KFREES
argument_list|(
name|ipfr_heads
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|ipfr_heads
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|ipfr_nattab
operator|!=
name|NULL
condition|)
name|KFREES
argument_list|(
name|ipfr_nattab
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|ipfr_nattab
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|ipfr_ipidtab
operator|!=
name|NULL
condition|)
name|KFREES
argument_list|(
name|ipfr_ipidtab
argument_list|,
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|ipfr_ipidtab
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_fragstats                                                */
end_comment

begin_comment
comment|/* Returns:     ipfrstat_t* - pointer to struct with current frag stats     */
end_comment

begin_comment
comment|/* Parameters:  Nil                                                         */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Updates ipfr_stats with current information and returns a pointer to it  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|ipfrstat_t
modifier|*
name|fr_fragstats
parameter_list|()
block|{
name|ipfr_stats
operator|.
name|ifs_table
operator|=
name|ipfr_heads
expr_stmt|;
name|ipfr_stats
operator|.
name|ifs_nattab
operator|=
name|ipfr_nattab
expr_stmt|;
name|ipfr_stats
operator|.
name|ifs_inuse
operator|=
name|ipfr_inuse
expr_stmt|;
return|return
operator|&
name|ipfr_stats
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipfr_newfrag                                                */
end_comment

begin_comment
comment|/* Returns:     ipfr_t * - pointer to fragment cache state info or NULL     */
end_comment

begin_comment
comment|/* Parameters:  fin(I)   - pointer to packet information                    */
end_comment

begin_comment
comment|/*              table(I) - pointer to frag table to add to                  */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Add a new entry to the fragment cache, registering it as having come     */
end_comment

begin_comment
comment|/* through this box, with the result of the filter operation.               */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|ipfr_t
modifier|*
name|ipfr_newfrag
parameter_list|(
name|fin
parameter_list|,
name|pass
parameter_list|,
name|table
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|u_32_t
name|pass
decl_stmt|;
name|ipfr_t
modifier|*
name|table
index|[]
decl_stmt|;
block|{
name|ipfr_t
modifier|*
name|fra
decl_stmt|,
name|frag
decl_stmt|;
name|u_int
name|idx
decl_stmt|,
name|off
decl_stmt|;
name|ip_t
modifier|*
name|ip
decl_stmt|;
if|if
condition|(
name|ipfr_inuse
operator|>=
name|IPFT_SIZE
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_flx
operator|&
operator|(
name|FI_FRAG
operator||
name|FI_BAD
operator|)
operator|)
operator|!=
name|FI_FRAG
condition|)
return|return
name|NULL
return|;
name|ip
operator|=
name|fin
operator|->
name|fin_ip
expr_stmt|;
if|if
condition|(
name|pass
operator|&
name|FR_FRSTRICT
condition|)
if|if
condition|(
operator|(
name|ip
operator|->
name|ip_off
operator|&
name|IP_OFFMASK
operator|)
operator|!=
literal|0
condition|)
return|return
name|NULL
return|;
name|frag
operator|.
name|ipfr_p
operator|=
name|ip
operator|->
name|ip_p
expr_stmt|;
name|idx
operator|=
name|ip
operator|->
name|ip_p
expr_stmt|;
name|frag
operator|.
name|ipfr_id
operator|=
name|ip
operator|->
name|ip_id
expr_stmt|;
name|idx
operator|+=
name|ip
operator|->
name|ip_id
expr_stmt|;
name|frag
operator|.
name|ipfr_tos
operator|=
name|ip
operator|->
name|ip_tos
expr_stmt|;
name|frag
operator|.
name|ipfr_src
operator|.
name|s_addr
operator|=
name|ip
operator|->
name|ip_src
operator|.
name|s_addr
expr_stmt|;
name|idx
operator|+=
name|ip
operator|->
name|ip_src
operator|.
name|s_addr
expr_stmt|;
name|frag
operator|.
name|ipfr_dst
operator|.
name|s_addr
operator|=
name|ip
operator|->
name|ip_dst
operator|.
name|s_addr
expr_stmt|;
name|idx
operator|+=
name|ip
operator|->
name|ip_dst
operator|.
name|s_addr
expr_stmt|;
name|frag
operator|.
name|ipfr_ifp
operator|=
name|fin
operator|->
name|fin_ifp
expr_stmt|;
name|idx
operator|*=
literal|127
expr_stmt|;
name|idx
operator|%=
name|IPFT_SIZE
expr_stmt|;
name|frag
operator|.
name|ipfr_optmsk
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_optmsk
operator|&
name|IPF_OPTCOPY
expr_stmt|;
name|frag
operator|.
name|ipfr_secmsk
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_secmsk
expr_stmt|;
name|frag
operator|.
name|ipfr_auth
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_auth
expr_stmt|;
comment|/* 	 * first, make sure it isn't already there... 	 */
for|for
control|(
name|fra
operator|=
name|table
index|[
name|idx
index|]
init|;
operator|(
name|fra
operator|!=
name|NULL
operator|)
condition|;
name|fra
operator|=
name|fra
operator|->
name|ipfr_hnext
control|)
if|if
condition|(
operator|!
name|bcmp
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|frag
operator|.
name|ipfr_ifp
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|fra
operator|->
name|ipfr_ifp
argument_list|,
name|IPFR_CMPSZ
argument_list|)
condition|)
block|{
name|ipfr_stats
operator|.
name|ifs_exists
operator|++
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|/* 	 * allocate some memory, if possible, if not, just record that we 	 * failed to do so. 	 */
name|KMALLOC
argument_list|(
name|fra
argument_list|,
name|ipfr_t
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|fra
operator|==
name|NULL
condition|)
block|{
name|ipfr_stats
operator|.
name|ifs_nomem
operator|++
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
operator|(
name|fra
operator|->
name|ipfr_rule
operator|=
name|fin
operator|->
name|fin_fr
operator|)
operator|!=
name|NULL
condition|)
name|fin
operator|->
name|fin_fr
operator|->
name|fr_ref
operator|++
expr_stmt|;
comment|/* 	 * Insert the fragment into the fragment table, copy the struct used 	 * in the search using bcopy rather than reassign each field. 	 * Set the ttl to the default. 	 */
if|if
condition|(
operator|(
name|fra
operator|->
name|ipfr_hnext
operator|=
name|table
index|[
name|idx
index|]
operator|)
operator|!=
name|NULL
condition|)
name|table
index|[
name|idx
index|]
operator|->
name|ipfr_hprev
operator|=
operator|&
name|fra
operator|->
name|ipfr_hnext
expr_stmt|;
name|fra
operator|->
name|ipfr_hprev
operator|=
name|table
operator|+
name|idx
expr_stmt|;
name|fra
operator|->
name|ipfr_data
operator|=
name|NULL
expr_stmt|;
name|table
index|[
name|idx
index|]
operator|=
name|fra
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|frag
operator|.
name|ipfr_ifp
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|fra
operator|->
name|ipfr_ifp
argument_list|,
name|IPFR_CMPSZ
argument_list|)
expr_stmt|;
name|fra
operator|->
name|ipfr_ttl
operator|=
name|fr_ticks
operator|+
name|fr_ipfrttl
expr_stmt|;
comment|/* 	 * Compute the offset of the expected start of the next packet. 	 */
name|off
operator|=
name|ip
operator|->
name|ip_off
operator|&
name|IP_OFFMASK
expr_stmt|;
if|if
condition|(
name|off
operator|==
literal|0
condition|)
name|fra
operator|->
name|ipfr_seen0
operator|=
literal|1
expr_stmt|;
name|fra
operator|->
name|ipfr_off
operator|=
name|off
operator|+
operator|(
name|fin
operator|->
name|fin_dlen
operator|>>
literal|3
operator|)
expr_stmt|;
name|fra
operator|->
name|ipfr_pass
operator|=
name|pass
expr_stmt|;
name|ipfr_stats
operator|.
name|ifs_new
operator|++
expr_stmt|;
name|ipfr_inuse
operator|++
expr_stmt|;
return|return
name|fra
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_newfrag                                                  */
end_comment

begin_comment
comment|/* Returns:     int - 0 == success, -1 == error                             */
end_comment

begin_comment
comment|/* Parameters:  fin(I)  - pointer to packet information                     */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Add a new entry to the fragment cache table based on the current packet  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|fr_newfrag
parameter_list|(
name|fin
parameter_list|,
name|pass
parameter_list|)
name|u_32_t
name|pass
decl_stmt|;
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
block|{
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_v
operator|!=
literal|4
operator|)
operator|||
operator|(
name|fr_frag_lock
operator|!=
literal|0
operator|)
condition|)
return|return
operator|-
literal|1
return|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
name|fra
operator|=
name|ipfr_newfrag
argument_list|(
name|fin
argument_list|,
name|pass
argument_list|,
name|ipfr_heads
argument_list|)
expr_stmt|;
if|if
condition|(
name|fra
operator|!=
name|NULL
condition|)
block|{
operator|*
name|ipfr_tail
operator|=
name|fra
expr_stmt|;
name|fra
operator|->
name|ipfr_prev
operator|=
name|ipfr_tail
expr_stmt|;
name|ipfr_tail
operator|=
operator|&
name|fra
operator|->
name|ipfr_next
expr_stmt|;
if|if
condition|(
name|ipfr_list
operator|==
name|NULL
condition|)
name|ipfr_list
operator|=
name|fra
expr_stmt|;
name|fra
operator|->
name|ipfr_next
operator|=
name|NULL
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
return|return
name|fra
condition|?
literal|0
else|:
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_nat_newfrag                                              */
end_comment

begin_comment
comment|/* Returns:     int - 0 == success, -1 == error                             */
end_comment

begin_comment
comment|/* Parameters:  fin(I)  - pointer to packet information                     */
end_comment

begin_comment
comment|/*              nat(I)  - pointer to NAT structure                          */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Create a new NAT fragment cache entry based on the current packet and    */
end_comment

begin_comment
comment|/* the NAT structure for this "session".                                    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|fr_nat_newfrag
parameter_list|(
name|fin
parameter_list|,
name|pass
parameter_list|,
name|nat
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|u_32_t
name|pass
decl_stmt|;
name|nat_t
modifier|*
name|nat
decl_stmt|;
block|{
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_v
operator|!=
literal|4
operator|)
operator|||
operator|(
name|fr_frag_lock
operator|!=
literal|0
operator|)
condition|)
return|return
literal|0
return|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
name|fra
operator|=
name|ipfr_newfrag
argument_list|(
name|fin
argument_list|,
name|pass
argument_list|,
name|ipfr_nattab
argument_list|)
expr_stmt|;
if|if
condition|(
name|fra
operator|!=
name|NULL
condition|)
block|{
name|fra
operator|->
name|ipfr_data
operator|=
name|nat
expr_stmt|;
name|nat
operator|->
name|nat_data
operator|=
name|fra
expr_stmt|;
operator|*
name|ipfr_nattail
operator|=
name|fra
expr_stmt|;
name|fra
operator|->
name|ipfr_prev
operator|=
name|ipfr_nattail
expr_stmt|;
name|ipfr_nattail
operator|=
operator|&
name|fra
operator|->
name|ipfr_next
expr_stmt|;
name|fra
operator|->
name|ipfr_next
operator|=
name|NULL
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
return|return
name|fra
condition|?
literal|0
else|:
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_ipid_newfrag                                             */
end_comment

begin_comment
comment|/* Returns:     int - 0 == success, -1 == error                             */
end_comment

begin_comment
comment|/* Parameters:  fin(I)  - pointer to packet information                     */
end_comment

begin_comment
comment|/*              ipid(I) - new IP ID for this fragmented packet              */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Create a new fragment cache entry for this packet and store, as a data   */
end_comment

begin_comment
comment|/* pointer, the new IP ID value.                                            */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|fr_ipid_newfrag
parameter_list|(
name|fin
parameter_list|,
name|ipid
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|u_32_t
name|ipid
decl_stmt|;
block|{
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_v
operator|!=
literal|4
operator|)
operator|||
operator|(
name|fr_frag_lock
operator|)
condition|)
return|return
literal|0
return|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_ipidfrag
argument_list|)
expr_stmt|;
name|fra
operator|=
name|ipfr_newfrag
argument_list|(
name|fin
argument_list|,
literal|0
argument_list|,
name|ipfr_ipidtab
argument_list|)
expr_stmt|;
if|if
condition|(
name|fra
operator|!=
name|NULL
condition|)
block|{
name|fra
operator|->
name|ipfr_data
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
name|ipid
expr_stmt|;
operator|*
name|ipfr_ipidtail
operator|=
name|fra
expr_stmt|;
name|fra
operator|->
name|ipfr_prev
operator|=
name|ipfr_ipidtail
expr_stmt|;
name|ipfr_ipidtail
operator|=
operator|&
name|fra
operator|->
name|ipfr_next
expr_stmt|;
name|fra
operator|->
name|ipfr_next
operator|=
name|NULL
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_ipidfrag
argument_list|)
expr_stmt|;
return|return
name|fra
condition|?
literal|0
else|:
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_fraglookup                                               */
end_comment

begin_comment
comment|/* Returns:     ipfr_t * - pointer to ipfr_t structure if there's a         */
end_comment

begin_comment
comment|/*                         matching entry in the frag table, else NULL      */
end_comment

begin_comment
comment|/* Parameters:  fin(I)   - pointer to packet information                    */
end_comment

begin_comment
comment|/*              table(I) - pointer to fragment cache table to search        */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Check the fragment cache to see if there is already a record of this     */
end_comment

begin_comment
comment|/* packet with its filter result known.                                     */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|ipfr_t
modifier|*
name|fr_fraglookup
parameter_list|(
name|fin
parameter_list|,
name|table
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|ipfr_t
modifier|*
name|table
index|[]
decl_stmt|;
block|{
name|ipfr_t
modifier|*
name|f
decl_stmt|,
name|frag
decl_stmt|;
name|u_int
name|idx
decl_stmt|;
name|ip_t
modifier|*
name|ip
decl_stmt|;
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_flx
operator|&
operator|(
name|FI_FRAG
operator||
name|FI_BAD
operator|)
operator|)
operator|!=
name|FI_FRAG
condition|)
return|return
name|NULL
return|;
comment|/* 	 * For fragments, we record protocol, packet id, TOS and both IP#'s 	 * (these should all be the same for all fragments of a packet). 	 * 	 * build up a hash value to index the table with. 	 */
name|ip
operator|=
name|fin
operator|->
name|fin_ip
expr_stmt|;
name|frag
operator|.
name|ipfr_p
operator|=
name|ip
operator|->
name|ip_p
expr_stmt|;
name|idx
operator|=
name|ip
operator|->
name|ip_p
expr_stmt|;
name|frag
operator|.
name|ipfr_id
operator|=
name|ip
operator|->
name|ip_id
expr_stmt|;
name|idx
operator|+=
name|ip
operator|->
name|ip_id
expr_stmt|;
name|frag
operator|.
name|ipfr_tos
operator|=
name|ip
operator|->
name|ip_tos
expr_stmt|;
name|frag
operator|.
name|ipfr_src
operator|.
name|s_addr
operator|=
name|ip
operator|->
name|ip_src
operator|.
name|s_addr
expr_stmt|;
name|idx
operator|+=
name|ip
operator|->
name|ip_src
operator|.
name|s_addr
expr_stmt|;
name|frag
operator|.
name|ipfr_dst
operator|.
name|s_addr
operator|=
name|ip
operator|->
name|ip_dst
operator|.
name|s_addr
expr_stmt|;
name|idx
operator|+=
name|ip
operator|->
name|ip_dst
operator|.
name|s_addr
expr_stmt|;
name|frag
operator|.
name|ipfr_ifp
operator|=
name|fin
operator|->
name|fin_ifp
expr_stmt|;
name|idx
operator|*=
literal|127
expr_stmt|;
name|idx
operator|%=
name|IPFT_SIZE
expr_stmt|;
name|frag
operator|.
name|ipfr_optmsk
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_optmsk
operator|&
name|IPF_OPTCOPY
expr_stmt|;
name|frag
operator|.
name|ipfr_secmsk
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_secmsk
expr_stmt|;
name|frag
operator|.
name|ipfr_auth
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_auth
expr_stmt|;
comment|/* 	 * check the table, careful to only compare the right amount of data 	 */
for|for
control|(
name|f
operator|=
name|table
index|[
name|idx
index|]
init|;
name|f
condition|;
name|f
operator|=
name|f
operator|->
name|ipfr_hnext
control|)
if|if
condition|(
operator|!
name|bcmp
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|frag
operator|.
name|ipfr_ifp
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|f
operator|->
name|ipfr_ifp
argument_list|,
name|IPFR_CMPSZ
argument_list|)
condition|)
block|{
name|u_short
name|off
decl_stmt|;
comment|/* 			 * We don't want to let short packets match because 			 * they could be compromising the security of other 			 * rules that want to match on layer 4 fields (and 			 * can't because they have been fragmented off.) 			 * Why do this check here?  The counter acts as an 			 * indicator of this kind of attack, whereas if it was 			 * elsewhere, it wouldn't know if other matching 			 * packets had been seen. 			 */
if|if
condition|(
name|fin
operator|->
name|fin_flx
operator|&
name|FI_SHORT
condition|)
block|{
name|ATOMIC_INCL
argument_list|(
name|ipfr_stats
operator|.
name|ifs_short
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/* 			 * XXX - We really need to be guarding against the 			 * retransmission of (src,dst,id,offset-range) here 			 * because a fragmented packet is never resent with 			 * the same IP ID# (or shouldn't). 			 */
name|off
operator|=
name|ip
operator|->
name|ip_off
operator|&
name|IP_OFFMASK
expr_stmt|;
if|if
condition|(
name|f
operator|->
name|ipfr_seen0
condition|)
block|{
if|if
condition|(
name|off
operator|==
literal|0
condition|)
block|{
name|ATOMIC_INCL
argument_list|(
name|ipfr_stats
operator|.
name|ifs_retrans0
argument_list|)
expr_stmt|;
continue|continue;
block|}
block|}
elseif|else
if|if
condition|(
name|off
operator|==
literal|0
condition|)
name|f
operator|->
name|ipfr_seen0
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|f
operator|!=
name|table
index|[
name|idx
index|]
condition|)
block|{
name|ipfr_t
modifier|*
modifier|*
name|fp
decl_stmt|;
comment|/* 				 * Move fragment info. to the top of the list 				 * to speed up searches.  First, delink... 				 */
name|fp
operator|=
name|f
operator|->
name|ipfr_hprev
expr_stmt|;
operator|(
operator|*
name|fp
operator|)
operator|=
name|f
operator|->
name|ipfr_hnext
expr_stmt|;
if|if
condition|(
name|f
operator|->
name|ipfr_hnext
operator|!=
name|NULL
condition|)
name|f
operator|->
name|ipfr_hnext
operator|->
name|ipfr_hprev
operator|=
name|fp
expr_stmt|;
comment|/* 				 * Then put back at the top of the chain. 				 */
name|f
operator|->
name|ipfr_hnext
operator|=
name|table
index|[
name|idx
index|]
expr_stmt|;
name|table
index|[
name|idx
index|]
operator|->
name|ipfr_hprev
operator|=
operator|&
name|f
operator|->
name|ipfr_hnext
expr_stmt|;
name|f
operator|->
name|ipfr_hprev
operator|=
name|table
operator|+
name|idx
expr_stmt|;
name|table
index|[
name|idx
index|]
operator|=
name|f
expr_stmt|;
block|}
comment|/* 			 * If we've follwed the fragments, and this is the 			 * last (in order), shrink expiration time. 			 */
if|if
condition|(
name|off
operator|==
name|f
operator|->
name|ipfr_off
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|ip
operator|->
name|ip_off
operator|&
name|IP_MF
operator|)
condition|)
name|f
operator|->
name|ipfr_ttl
operator|=
name|fr_ticks
operator|+
literal|1
expr_stmt|;
name|f
operator|->
name|ipfr_off
operator|=
operator|(
name|fin
operator|->
name|fin_dlen
operator|>>
literal|3
operator|)
operator|+
name|off
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|f
operator|->
name|ipfr_pass
operator|&
name|FR_FRSTRICT
condition|)
continue|continue;
name|ATOMIC_INCL
argument_list|(
name|ipfr_stats
operator|.
name|ifs_hits
argument_list|)
expr_stmt|;
return|return
name|f
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_nat_knownfrag                                            */
end_comment

begin_comment
comment|/* Returns:     nat_t* - pointer to 'parent' NAT structure if frag table    */
end_comment

begin_comment
comment|/*                       match found, else NULL                             */
end_comment

begin_comment
comment|/* Parameters:  fin(I)  - pointer to packet information                     */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Functional interface for NAT lookups of the NAT fragment cache           */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|nat_t
modifier|*
name|fr_nat_knownfrag
parameter_list|(
name|fin
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
block|{
name|nat_t
modifier|*
name|nat
decl_stmt|;
name|ipfr_t
modifier|*
name|ipf
decl_stmt|;
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_v
operator|!=
literal|4
operator|)
operator|||
operator|(
name|fr_frag_lock
operator|)
operator|||
operator|!
name|ipfr_natlist
condition|)
return|return
name|NULL
return|;
name|READ_ENTER
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
name|ipf
operator|=
name|fr_fraglookup
argument_list|(
name|fin
argument_list|,
name|ipfr_nattab
argument_list|)
expr_stmt|;
if|if
condition|(
name|ipf
operator|!=
name|NULL
condition|)
block|{
name|nat
operator|=
name|ipf
operator|->
name|ipfr_data
expr_stmt|;
comment|/* 		 * This is the last fragment for this packet. 		 */
if|if
condition|(
operator|(
name|ipf
operator|->
name|ipfr_ttl
operator|==
name|fr_ticks
operator|+
literal|1
operator|)
operator|&&
operator|(
name|nat
operator|!=
name|NULL
operator|)
condition|)
block|{
name|nat
operator|->
name|nat_data
operator|=
name|NULL
expr_stmt|;
name|ipf
operator|->
name|ipfr_data
operator|=
name|NULL
expr_stmt|;
block|}
block|}
else|else
name|nat
operator|=
name|NULL
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
return|return
name|nat
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_ipid_knownfrag                                           */
end_comment

begin_comment
comment|/* Returns:     u_32_t - IPv4 ID for this packet if match found, else       */
end_comment

begin_comment
comment|/*                       return 0xfffffff to indicate no match.             */
end_comment

begin_comment
comment|/* Parameters:  fin(I) - pointer to packet information                      */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Functional interface for IP ID lookups of the IP ID fragment cache       */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|u_32_t
name|fr_ipid_knownfrag
parameter_list|(
name|fin
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
block|{
name|ipfr_t
modifier|*
name|ipf
decl_stmt|;
name|u_32_t
name|id
decl_stmt|;
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_v
operator|!=
literal|4
operator|)
operator|||
operator|(
name|fr_frag_lock
operator|)
operator|||
operator|!
name|ipfr_ipidlist
condition|)
return|return
literal|0xffffffff
return|;
name|READ_ENTER
argument_list|(
operator|&
name|ipf_ipidfrag
argument_list|)
expr_stmt|;
name|ipf
operator|=
name|fr_fraglookup
argument_list|(
name|fin
argument_list|,
name|ipfr_ipidtab
argument_list|)
expr_stmt|;
if|if
condition|(
name|ipf
operator|!=
name|NULL
condition|)
name|id
operator|=
operator|(
name|u_32_t
operator|)
operator|(
name|uintptr_t
operator|)
name|ipf
operator|->
name|ipfr_data
expr_stmt|;
else|else
name|id
operator|=
literal|0xffffffff
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_ipidfrag
argument_list|)
expr_stmt|;
return|return
name|id
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_knownfrag                                                */
end_comment

begin_comment
comment|/* Returns:     frentry_t* - pointer to filter rule if a match is found in  */
end_comment

begin_comment
comment|/*                           the frag cache table, else NULL.               */
end_comment

begin_comment
comment|/* Parameters:  fin(I)   - pointer to packet information                    */
end_comment

begin_comment
comment|/*              passp(O) - pointer to where to store rule flags resturned   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Functional interface for normal lookups of the fragment cache.  If a     */
end_comment

begin_comment
comment|/* match is found, return the rule pointer and flags from the rule, except  */
end_comment

begin_comment
comment|/* that if FR_LOGFIRST is set, reset FR_LOG.                                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|frentry_t
modifier|*
name|fr_knownfrag
parameter_list|(
name|fin
parameter_list|,
name|passp
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|u_32_t
modifier|*
name|passp
decl_stmt|;
block|{
name|frentry_t
modifier|*
name|fr
init|=
name|NULL
decl_stmt|;
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
name|u_32_t
name|pass
decl_stmt|;
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_v
operator|!=
literal|4
operator|)
operator|||
operator|(
name|fr_frag_lock
operator|)
operator|||
operator|(
name|ipfr_list
operator|==
name|NULL
operator|)
condition|)
return|return
name|NULL
return|;
name|READ_ENTER
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
name|fra
operator|=
name|fr_fraglookup
argument_list|(
name|fin
argument_list|,
name|ipfr_heads
argument_list|)
expr_stmt|;
if|if
condition|(
name|fra
operator|!=
name|NULL
condition|)
block|{
name|fr
operator|=
name|fra
operator|->
name|ipfr_rule
expr_stmt|;
name|fin
operator|->
name|fin_fr
operator|=
name|fr
expr_stmt|;
if|if
condition|(
name|fr
operator|!=
name|NULL
condition|)
block|{
name|pass
operator|=
name|fr
operator|->
name|fr_flags
expr_stmt|;
if|if
condition|(
operator|(
name|pass
operator|&
name|FR_LOGFIRST
operator|)
operator|!=
literal|0
condition|)
name|pass
operator|&=
operator|~
operator|(
name|FR_LOGFIRST
operator||
name|FR_LOG
operator|)
expr_stmt|;
operator|*
name|passp
operator|=
name|pass
expr_stmt|;
block|}
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
return|return
name|fr
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_forget                                                   */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  ptr(I) - pointer to data structure                          */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Search through all of the fragment cache entries and wherever a pointer  */
end_comment

begin_comment
comment|/* is found to match ptr, reset it to NULL.                                 */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|fr_forget
parameter_list|(
name|ptr
parameter_list|)
name|void
modifier|*
name|ptr
decl_stmt|;
block|{
name|ipfr_t
modifier|*
name|fr
decl_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
for|for
control|(
name|fr
operator|=
name|ipfr_list
init|;
name|fr
condition|;
name|fr
operator|=
name|fr
operator|->
name|ipfr_next
control|)
if|if
condition|(
name|fr
operator|->
name|ipfr_data
operator|==
name|ptr
condition|)
name|fr
operator|->
name|ipfr_data
operator|=
name|NULL
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_forgetnat                                                */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  ptr(I) - pointer to data structure                          */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Search through all of the fragment cache entries for NAT and wherever a  */
end_comment

begin_comment
comment|/* pointer  is found to match ptr, reset it to NULL.                        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|fr_forgetnat
parameter_list|(
name|ptr
parameter_list|)
name|void
modifier|*
name|ptr
decl_stmt|;
block|{
name|ipfr_t
modifier|*
name|fr
decl_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
for|for
control|(
name|fr
operator|=
name|ipfr_natlist
init|;
name|fr
condition|;
name|fr
operator|=
name|fr
operator|->
name|ipfr_next
control|)
if|if
condition|(
name|fr
operator|->
name|ipfr_data
operator|==
name|ptr
condition|)
name|fr
operator|->
name|ipfr_data
operator|=
name|NULL
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_fragdelete                                               */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  fra(I)   - pointer to fragment structure to delete          */
end_comment

begin_comment
comment|/*              tail(IO) - pointer to the pointer to the tail of the frag   */
end_comment

begin_comment
comment|/*                         list                                             */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Remove a fragment cache table entry from the table& list.  Also free    */
end_comment

begin_comment
comment|/* the filter rule it is associated with it if it is no longer used as a    */
end_comment

begin_comment
comment|/* result of decreasing the reference count.                                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|fr_fragdelete
parameter_list|(
name|fra
parameter_list|,
name|tail
parameter_list|)
name|ipfr_t
modifier|*
name|fra
decl_stmt|,
decl|*
modifier|*
modifier|*
name|tail
decl_stmt|;
end_function

begin_block
block|{
name|frentry_t
modifier|*
name|fr
decl_stmt|;
name|fr
operator|=
name|fra
operator|->
name|ipfr_rule
expr_stmt|;
if|if
condition|(
name|fr
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|fr_derefrule
argument_list|(
operator|&
name|fr
argument_list|)
expr_stmt|;
if|if
condition|(
name|fra
operator|->
name|ipfr_next
condition|)
name|fra
operator|->
name|ipfr_next
operator|->
name|ipfr_prev
operator|=
name|fra
operator|->
name|ipfr_prev
expr_stmt|;
operator|*
name|fra
operator|->
name|ipfr_prev
operator|=
name|fra
operator|->
name|ipfr_next
expr_stmt|;
if|if
condition|(
operator|*
name|tail
operator|==
operator|&
name|fra
operator|->
name|ipfr_next
condition|)
operator|*
name|tail
operator|=
name|fra
operator|->
name|ipfr_prev
expr_stmt|;
if|if
condition|(
name|fra
operator|->
name|ipfr_hnext
condition|)
name|fra
operator|->
name|ipfr_hnext
operator|->
name|ipfr_hprev
operator|=
name|fra
operator|->
name|ipfr_hprev
expr_stmt|;
operator|*
name|fra
operator|->
name|ipfr_hprev
operator|=
name|fra
operator|->
name|ipfr_hnext
expr_stmt|;
name|KFREE
argument_list|(
name|fra
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_fragclear                                                */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  Nil                                                         */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Free memory in use by fragment state information kept.  Do the normal    */
end_comment

begin_comment
comment|/* fragment state stuff first and then the NAT-fragment table.              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|fr_fragclear
parameter_list|()
block|{
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
name|nat_t
modifier|*
name|nat
decl_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|fra
operator|=
name|ipfr_list
operator|)
operator|!=
name|NULL
condition|)
name|fr_fragdelete
argument_list|(
name|fra
argument_list|,
operator|&
name|ipfr_tail
argument_list|)
expr_stmt|;
name|ipfr_tail
operator|=
operator|&
name|ipfr_list
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_nat
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|fra
operator|=
name|ipfr_natlist
operator|)
operator|!=
name|NULL
condition|)
block|{
name|nat
operator|=
name|fra
operator|->
name|ipfr_data
expr_stmt|;
if|if
condition|(
name|nat
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|nat
operator|->
name|nat_data
operator|==
name|fra
condition|)
name|nat
operator|->
name|nat_data
operator|=
name|NULL
expr_stmt|;
block|}
name|fr_fragdelete
argument_list|(
name|fra
argument_list|,
operator|&
name|ipfr_nattail
argument_list|)
expr_stmt|;
block|}
name|ipfr_nattail
operator|=
operator|&
name|ipfr_natlist
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_nat
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_fragexpire                                               */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  Nil                                                         */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Expire entries in the fragment cache table that have been there too long */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|fr_fragexpire
parameter_list|()
block|{
name|ipfr_t
modifier|*
modifier|*
name|fp
decl_stmt|,
modifier|*
name|fra
decl_stmt|;
name|nat_t
modifier|*
name|nat
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|USE_SPL
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
name|int
name|s
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|fr_frag_lock
condition|)
return|return;
name|SPL_NET
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
comment|/* 	 * Go through the entire table, looking for entries to expire, 	 * which is indicated by the ttl being less than or equal to fr_ticks. 	 */
for|for
control|(
name|fp
operator|=
operator|&
name|ipfr_list
init|;
operator|(
operator|(
name|fra
operator|=
operator|*
name|fp
operator|)
operator|!=
name|NULL
operator|)
condition|;
control|)
block|{
if|if
condition|(
name|fra
operator|->
name|ipfr_ttl
operator|>
name|fr_ticks
condition|)
break|break;
name|fr_fragdelete
argument_list|(
name|fra
argument_list|,
operator|&
name|ipfr_tail
argument_list|)
expr_stmt|;
name|ipfr_stats
operator|.
name|ifs_expire
operator|++
expr_stmt|;
name|ipfr_inuse
operator|--
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_frag
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_ipidfrag
argument_list|)
expr_stmt|;
for|for
control|(
name|fp
operator|=
operator|&
name|ipfr_ipidlist
init|;
operator|(
operator|(
name|fra
operator|=
operator|*
name|fp
operator|)
operator|!=
name|NULL
operator|)
condition|;
control|)
block|{
if|if
condition|(
name|fra
operator|->
name|ipfr_ttl
operator|>
name|fr_ticks
condition|)
break|break;
name|fr_fragdelete
argument_list|(
name|fra
argument_list|,
operator|&
name|ipfr_ipidtail
argument_list|)
expr_stmt|;
name|ipfr_stats
operator|.
name|ifs_expire
operator|++
expr_stmt|;
name|ipfr_inuse
operator|--
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_ipidfrag
argument_list|)
expr_stmt|;
comment|/* 	 * Same again for the NAT table, except that if the structure also 	 * still points to a NAT structure, and the NAT structure points back 	 * at the one to be free'd, NULL the reference from the NAT struct. 	 * NOTE: We need to grab both mutex's early, and in this order so as 	 * to prevent a deadlock if both try to expire at the same time. 	 */
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_nat
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
for|for
control|(
name|fp
operator|=
operator|&
name|ipfr_natlist
init|;
operator|(
operator|(
name|fra
operator|=
operator|*
name|fp
operator|)
operator|!=
name|NULL
operator|)
condition|;
control|)
block|{
if|if
condition|(
name|fra
operator|->
name|ipfr_ttl
operator|>
name|fr_ticks
condition|)
break|break;
name|nat
operator|=
name|fra
operator|->
name|ipfr_data
expr_stmt|;
if|if
condition|(
name|nat
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|nat
operator|->
name|nat_data
operator|==
name|fra
condition|)
name|nat
operator|->
name|nat_data
operator|=
name|NULL
expr_stmt|;
block|}
name|fr_fragdelete
argument_list|(
name|fra
argument_list|,
operator|&
name|ipfr_nattail
argument_list|)
expr_stmt|;
name|ipfr_stats
operator|.
name|ifs_expire
operator|++
expr_stmt|;
name|ipfr_inuse
operator|--
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_natfrag
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_nat
argument_list|)
expr_stmt|;
name|SPL_X
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    fr_slowtimer                                                */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  Nil                                                         */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Slowly expire held state for fragments.  Timeouts are set * in           */
end_comment

begin_comment
comment|/* expectation of this being called twice per second.                       */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
operator|(
operator|!
name|SOLARIS
operator|&&
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|(
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|)
end_if

begin_decl_stmt
name|void
name|fr_slowtimer
name|__P
argument_list|(
operator|(
name|void
operator|*
name|ptr
operator|)
argument_list|)
else|#
directive|else
name|int
name|fr_slowtimer
argument_list|()
endif|#
directive|endif
block|{
name|READ_ENTER
argument_list|(
operator|&
name|ipf_global
argument_list|)
expr_stmt|;
name|fr_fragexpire
argument_list|()
expr_stmt|;
name|fr_timeoutstate
argument_list|()
expr_stmt|;
name|fr_natexpire
argument_list|()
expr_stmt|;
name|fr_authexpire
argument_list|()
expr_stmt|;
name|fr_ticks
operator|++
expr_stmt|;
if|if
condition|(
name|fr_running
operator|<=
literal|0
condition|)
goto|goto
name|done
goto|;
ifdef|#
directive|ifdef
name|_KERNEL
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
name|__NetBSD_Version__
operator|>=
literal|104240000
operator|)
name|callout_reset
argument_list|(
operator|&
name|fr_slowtimer_ch
argument_list|,
name|hz
operator|/
literal|2
argument_list|,
name|fr_slowtimer
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
name|timeout_add
argument_list|(
operator|&
name|fr_slowtimer_ch
argument_list|,
name|hz
operator|/
literal|2
argument_list|)
expr_stmt|;
else|#
directive|else
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
name|fr_slowtimer_ch
operator|=
name|timeout
argument_list|(
name|fr_slowtimer
argument_list|,
name|NULL
argument_list|,
name|hz
operator|/
literal|2
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|linux
empty_stmt|;
else|#
directive|else
name|timeout
argument_list|(
name|fr_slowtimer
argument_list|,
name|NULL
argument_list|,
name|hz
operator|/
literal|2
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* FreeBSD */
endif|#
directive|endif
comment|/* OpenBSD */
endif|#
directive|endif
comment|/* NetBSD */
endif|#
directive|endif
name|done
label|:
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ipf_global
argument_list|)
expr_stmt|;
if|#
directive|if
operator|(
name|BSD
operator|<
literal|199103
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SOLARIS&& !defined(__hpux)&& !defined(__sgi) */
end_comment

end_unit

