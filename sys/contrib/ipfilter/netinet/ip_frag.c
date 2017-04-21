begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
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
expr|\
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
operator|&&
operator|!
name|defined
argument_list|(
name|AIX
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
file|"netinet/ip_lookup.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_proxy.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_sync.h"
end_include

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
comment|/* static const char rcsid[] = "@(#)$Id: ip_frag.c,v 2.77.2.12 2007/09/20 12:51:51 darrenr Exp $"; */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MUTEXES
end_ifdef

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
name|ipfr_frag_new
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_frag_softc_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|,
name|ipfr_t
operator|*
operator|*
operator|,
name|ipfrwlock_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
name|ipf_frag_lookup
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_frag_softc_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|ipfr_t
operator|*
operator|*
operator|,
name|ipfrwlock_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_frag_deref
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|ipfr_t
operator|*
operator|*
operator|,
name|ipfrwlock_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_frag_next
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipftoken_t
operator|*
operator|,
name|ipfgeniter_t
operator|*
operator|,
name|ipfr_t
operator|*
operator|*
operator|,
name|ipfrwlock_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|ipfr_t
modifier|*
name|ipfr_frag_new
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_frag_softc_t
operator|*
operator|,
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
name|ipf_frag_lookup
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_frag_softc_t
operator|*
operator|,
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
name|ipf_frag_deref
name|__P
argument_list|(
operator|(
name|void
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
name|int
name|ipf_frag_next
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipftoken_t
operator|*
operator|,
name|ipfgeniter_t
operator|*
operator|,
name|ipfr_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
name|ipf_frag_delete
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
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

begin_decl_stmt
specifier|static
name|void
name|ipf_frag_free
name|__P
argument_list|(
operator|(
name|ipf_frag_softc_t
operator|*
operator|,
name|ipfr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|frentry_t
name|ipfr_block
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipftuneable_t
name|ipf_frag_tuneables
index|[]
init|=
block|{
block|{
block|{
operator|(
name|void
operator|*
operator|)
name|offsetof
argument_list|(
argument|ipf_frag_softc_t
argument_list|,
argument|ipfr_size
argument_list|)
block|}
block|,
literal|"frag_size"
block|,
literal|1
block|,
literal|0x7fffffff
block|,
name|stsizeof
argument_list|(
name|ipf_frag_softc_t
argument_list|,
name|ipfr_size
argument_list|)
block|,
name|IPFT_WRDISABLED
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
operator|(
name|void
operator|*
operator|)
name|offsetof
argument_list|(
argument|ipf_frag_softc_t
argument_list|,
argument|ipfr_ttl
argument_list|)
block|}
block|,
literal|"frag_ttl"
block|,
literal|1
block|,
literal|0x7fffffff
block|,
name|stsizeof
argument_list|(
name|ipf_frag_softc_t
argument_list|,
name|ipfr_ttl
argument_list|)
block|,
literal|0
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
name|NULL
block|}
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FBUMP
parameter_list|(
name|x
parameter_list|)
value|softf->ipfr_stats.x++
end_define

begin_define
define|#
directive|define
name|FBUMPD
parameter_list|(
name|x
parameter_list|)
value|do { softf->ipfr_stats.x++; DT(x); } while (0)
end_define

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_main_load                                          */
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
comment|/* Initialise the filter rule associted with blocked packets - everyone can */
end_comment

begin_comment
comment|/* use it.                                                                  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_frag_main_load
parameter_list|()
block|{
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|ipfr_block
argument_list|,
sizeof|sizeof
argument_list|(
name|ipfr_block
argument_list|)
argument_list|)
expr_stmt|;
name|ipfr_block
operator|.
name|fr_flags
operator|=
name|FR_BLOCK
operator||
name|FR_QUICK
expr_stmt|;
name|ipfr_block
operator|.
name|fr_ref
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
comment|/* Function:    ipf_frag_main_unload                                        */
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
comment|/* A null-op function that exists as a placeholder so that the flow in      */
end_comment

begin_comment
comment|/* other functions is obvious.                                              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_frag_main_unload
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_soft_create                                        */
end_comment

begin_comment
comment|/* Returns:     void *   - NULL = failure, else pointer to local context    */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Allocate a new soft context structure to track fragment related info.    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
modifier|*
name|ipf_frag_soft_create
parameter_list|(
name|softc
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
decl_stmt|;
name|KMALLOC
argument_list|(
name|softf
argument_list|,
name|ipf_frag_softc_t
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|softf
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|softf
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|softf
argument_list|)
argument_list|)
expr_stmt|;
name|RWLOCK_INIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_ipidfrag
argument_list|,
literal|"frag ipid lock"
argument_list|)
expr_stmt|;
name|RWLOCK_INIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_frag
argument_list|,
literal|"ipf fragment rwlock"
argument_list|)
expr_stmt|;
name|RWLOCK_INIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|,
literal|"ipf NAT fragment rwlock"
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipf_frag_tune
operator|=
name|ipf_tune_array_copy
argument_list|(
name|softf
argument_list|,
sizeof|sizeof
argument_list|(
name|ipf_frag_tuneables
argument_list|)
argument_list|,
name|ipf_frag_tuneables
argument_list|)
expr_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipf_frag_tune
operator|==
name|NULL
condition|)
block|{
name|ipf_frag_soft_destroy
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|ipf_tune_array_link
argument_list|(
name|softc
argument_list|,
name|softf
operator|->
name|ipf_frag_tune
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|ipf_frag_soft_destroy
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|softf
operator|->
name|ipfr_size
operator|=
name|IPFT_SIZE
expr_stmt|;
name|softf
operator|->
name|ipfr_ttl
operator|=
name|IPF_TTLVAL
argument_list|(
literal|60
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipfr_lock
operator|=
literal|1
expr_stmt|;
name|softf
operator|->
name|ipfr_tail
operator|=
operator|&
name|softf
operator|->
name|ipfr_list
expr_stmt|;
name|softf
operator|->
name|ipfr_nattail
operator|=
operator|&
name|softf
operator|->
name|ipfr_natlist
expr_stmt|;
name|softf
operator|->
name|ipfr_ipidtail
operator|=
operator|&
name|softf
operator|->
name|ipfr_ipidlist
expr_stmt|;
return|return
name|softf
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_soft_destroy                                       */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
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
name|void
name|ipf_frag_soft_destroy
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|arg
decl_stmt|;
name|RW_DESTROY
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_ipidfrag
argument_list|)
expr_stmt|;
name|RW_DESTROY
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_frag
argument_list|)
expr_stmt|;
name|RW_DESTROY
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipf_frag_tune
operator|!=
name|NULL
condition|)
block|{
name|ipf_tune_array_unlink
argument_list|(
name|softc
argument_list|,
name|softf
operator|->
name|ipf_frag_tune
argument_list|)
expr_stmt|;
name|KFREES
argument_list|(
name|softf
operator|->
name|ipf_frag_tune
argument_list|,
sizeof|sizeof
argument_list|(
name|ipf_frag_tuneables
argument_list|)
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipf_frag_tune
operator|=
name|NULL
expr_stmt|;
block|}
name|KFREE
argument_list|(
name|softf
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_soft_init                                          */
end_comment

begin_comment
comment|/* Returns:     int      - 0 == success, -1 == error                        */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
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

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|ipf_frag_soft_init
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|arg
decl_stmt|;
name|KMALLOCS
argument_list|(
name|softf
operator|->
name|ipfr_heads
argument_list|,
name|ipfr_t
operator|*
operator|*
argument_list|,
name|softf
operator|->
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
name|softf
operator|->
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
name|softf
operator|->
name|ipfr_heads
argument_list|,
name|softf
operator|->
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
name|softf
operator|->
name|ipfr_nattab
argument_list|,
name|ipfr_t
operator|*
operator|*
argument_list|,
name|softf
operator|->
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
name|softf
operator|->
name|ipfr_nattab
operator|==
name|NULL
condition|)
return|return
operator|-
literal|2
return|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|softf
operator|->
name|ipfr_nattab
argument_list|,
name|softf
operator|->
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
name|softf
operator|->
name|ipfr_ipidtab
argument_list|,
name|ipfr_t
operator|*
operator|*
argument_list|,
name|softf
operator|->
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
name|softf
operator|->
name|ipfr_ipidtab
operator|==
name|NULL
condition|)
return|return
operator|-
literal|3
return|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|softf
operator|->
name|ipfr_ipidtab
argument_list|,
name|softf
operator|->
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipfr_lock
operator|=
literal|0
expr_stmt|;
name|softf
operator|->
name|ipfr_inited
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
comment|/* Function:    ipf_frag_soft_fini                                          */
end_comment

begin_comment
comment|/* Returns:     int      - 0 == success, -1 == error                        */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
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
name|int
name|ipf_frag_soft_fini
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|arg
decl_stmt|;
name|softf
operator|->
name|ipfr_lock
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_inited
operator|==
literal|1
condition|)
block|{
name|ipf_frag_clear
argument_list|(
name|softc
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipfr_inited
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|softf
operator|->
name|ipfr_heads
operator|!=
name|NULL
condition|)
name|KFREES
argument_list|(
name|softf
operator|->
name|ipfr_heads
argument_list|,
name|softf
operator|->
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipfr_heads
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_nattab
operator|!=
name|NULL
condition|)
name|KFREES
argument_list|(
name|softf
operator|->
name|ipfr_nattab
argument_list|,
name|softf
operator|->
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipfr_nattab
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_ipidtab
operator|!=
name|NULL
condition|)
name|KFREES
argument_list|(
name|softf
operator|->
name|ipfr_ipidtab
argument_list|,
name|softf
operator|->
name|ipfr_size
operator|*
sizeof|sizeof
argument_list|(
name|ipfr_t
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipfr_ipidtab
operator|=
name|NULL
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
comment|/* Function:    ipf_frag_set_lock                                           */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  arg(I) - pointer to local context to use                    */
end_comment

begin_comment
comment|/*              tmp(I) - new value for lock                                 */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Stub function that allows for external manipulation of ipfr_lock         */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ipf_frag_setlock
parameter_list|(
name|arg
parameter_list|,
name|tmp
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
name|int
name|tmp
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|arg
decl_stmt|;
name|softf
operator|->
name|ipfr_lock
operator|=
name|tmp
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_stats                                              */
end_comment

begin_comment
comment|/* Returns:     ipfrstat_t* - pointer to struct with current frag stats     */
end_comment

begin_comment
comment|/* Parameters:  arg(I) - pointer to local context to use                    */
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
name|ipf_frag_stats
parameter_list|(
name|arg
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|arg
decl_stmt|;
name|softf
operator|->
name|ipfr_stats
operator|.
name|ifs_table
operator|=
name|softf
operator|->
name|ipfr_heads
expr_stmt|;
name|softf
operator|->
name|ipfr_stats
operator|.
name|ifs_nattab
operator|=
name|softf
operator|->
name|ipfr_nattab
expr_stmt|;
return|return
operator|&
name|softf
operator|->
name|ipfr_stats
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipfr_frag_new                                               */
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
comment|/*              lock(I)  - pointer to lock to get a write hold of           */
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
comment|/*                                                                          */
end_comment

begin_comment
comment|/* If this function succeeds, it returns with a write lock held on "lock".  */
end_comment

begin_comment
comment|/* If it fails, no lock is held on return.                                  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|ipfr_t
modifier|*
name|ipfr_frag_new
parameter_list|(
name|softc
parameter_list|,
name|softf
parameter_list|,
name|fin
parameter_list|,
name|pass
parameter_list|,
name|table
ifdef|#
directive|ifdef
name|USE_MUTEXES
parameter_list|,
name|lock
endif|#
directive|endif
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|ipf_frag_softc_t
modifier|*
name|softf
decl_stmt|;
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
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipfrwlock_t
modifier|*
name|lock
decl_stmt|;
endif|#
directive|endif
block|{
name|ipfr_t
modifier|*
name|fra
decl_stmt|,
name|frag
decl_stmt|,
modifier|*
name|fran
decl_stmt|;
name|u_int
name|idx
decl_stmt|,
name|off
decl_stmt|;
name|frentry_t
modifier|*
name|fr
decl_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_stats
operator|.
name|ifs_inuse
operator|>=
name|softf
operator|->
name|ipfr_size
condition|)
block|{
name|FBUMPD
argument_list|(
name|ifs_maximum
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
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
block|{
name|FBUMPD
argument_list|(
name|ifs_newbad
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|pass
operator|&
name|FR_FRSTRICT
condition|)
block|{
if|if
condition|(
name|fin
operator|->
name|fin_off
operator|!=
literal|0
condition|)
block|{
name|FBUMPD
argument_list|(
name|ifs_newrestrictnot0
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
block|}
name|frag
operator|.
name|ipfr_v
operator|=
name|fin
operator|->
name|fin_v
expr_stmt|;
name|idx
operator|=
name|fin
operator|->
name|fin_v
expr_stmt|;
name|frag
operator|.
name|ipfr_p
operator|=
name|fin
operator|->
name|fin_p
expr_stmt|;
name|idx
operator|+=
name|fin
operator|->
name|fin_p
expr_stmt|;
name|frag
operator|.
name|ipfr_id
operator|=
name|fin
operator|->
name|fin_id
expr_stmt|;
name|idx
operator|+=
name|fin
operator|->
name|fin_id
expr_stmt|;
name|frag
operator|.
name|ipfr_source
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_src
expr_stmt|;
name|idx
operator|+=
name|frag
operator|.
name|ipfr_src
operator|.
name|s_addr
expr_stmt|;
name|frag
operator|.
name|ipfr_dest
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_dst
expr_stmt|;
name|idx
operator|+=
name|frag
operator|.
name|ipfr_dst
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
name|softf
operator|->
name|ipfr_size
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
name|off
operator|=
name|fin
operator|->
name|fin_off
operator|>>
literal|3
expr_stmt|;
if|if
condition|(
name|off
operator|==
literal|0
condition|)
block|{
name|char
modifier|*
name|ptr
decl_stmt|;
name|int
name|end
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_INET6
if|if
condition|(
name|fin
operator|->
name|fin_v
operator|==
literal|6
condition|)
block|{
name|ptr
operator|=
operator|(
name|char
operator|*
operator|)
name|fin
operator|->
name|fin_fraghdr
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|ip6_frag
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|ptr
operator|=
name|fin
operator|->
name|fin_dp
expr_stmt|;
block|}
name|end
operator|=
name|fin
operator|->
name|fin_plen
operator|-
operator|(
name|ptr
operator|-
operator|(
name|char
operator|*
operator|)
name|fin
operator|->
name|fin_ip
operator|)
expr_stmt|;
name|frag
operator|.
name|ipfr_firstend
operator|=
name|end
operator|>>
literal|3
expr_stmt|;
block|}
else|else
block|{
name|frag
operator|.
name|ipfr_firstend
operator|=
literal|0
expr_stmt|;
block|}
comment|/* 	 * allocate some memory, if possible, if not, just record that we 	 * failed to do so. 	 */
name|KMALLOC
argument_list|(
name|fran
argument_list|,
name|ipfr_t
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|fran
operator|==
name|NULL
condition|)
block|{
name|FBUMPD
argument_list|(
name|ifs_nomem
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|WRITE_ENTER
argument_list|(
name|lock
argument_list|)
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
name|RWLOCK_EXIT
argument_list|(
name|lock
argument_list|)
expr_stmt|;
name|FBUMPD
argument_list|(
name|ifs_exists
argument_list|)
expr_stmt|;
name|KFREE
argument_list|(
name|fran
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|fra
operator|=
name|fran
expr_stmt|;
name|fran
operator|=
name|NULL
expr_stmt|;
name|fr
operator|=
name|fin
operator|->
name|fin_fr
expr_stmt|;
name|fra
operator|->
name|ipfr_rule
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
name|MUTEX_ENTER
argument_list|(
operator|&
name|fr
operator|->
name|fr_lock
argument_list|)
expr_stmt|;
name|fr
operator|->
name|fr_ref
operator|++
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|fr
operator|->
name|fr_lock
argument_list|)
expr_stmt|;
block|}
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
name|ipfr_v
operator|=
name|fin
operator|->
name|fin_v
expr_stmt|;
name|fra
operator|->
name|ipfr_ttl
operator|=
name|softc
operator|->
name|ipf_ticks
operator|+
name|softf
operator|->
name|ipfr_ttl
expr_stmt|;
name|fra
operator|->
name|ipfr_firstend
operator|=
name|frag
operator|.
name|ipfr_firstend
expr_stmt|;
comment|/* 	 * Compute the offset of the expected start of the next packet. 	 */
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
name|fra
operator|->
name|ipfr_ref
operator|=
literal|1
expr_stmt|;
name|fra
operator|->
name|ipfr_pkts
operator|=
literal|1
expr_stmt|;
name|fra
operator|->
name|ipfr_bytes
operator|=
name|fin
operator|->
name|fin_plen
expr_stmt|;
name|FBUMP
argument_list|(
name|ifs_inuse
argument_list|)
expr_stmt|;
name|FBUMP
argument_list|(
name|ifs_new
argument_list|)
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
comment|/* Function:    ipf_frag_new                                                */
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
name|ipf_frag_new
parameter_list|(
name|softc
parameter_list|,
name|fin
parameter_list|,
name|pass
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|u_32_t
name|pass
decl_stmt|;
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_lock
operator|!=
literal|0
condition|)
return|return
operator|-
literal|1
return|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|fra
operator|=
name|ipfr_frag_new
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|pass
argument_list|,
name|softf
operator|->
name|ipfr_heads
argument_list|,
operator|&
name|softc
operator|->
name|ipf_frag
argument_list|)
expr_stmt|;
else|#
directive|else
name|fra
operator|=
name|ipfr_frag_new
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|pass
argument_list|,
name|softf
operator|->
name|ipfr_heads
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|fra
operator|!=
name|NULL
condition|)
block|{
operator|*
name|softf
operator|->
name|ipfr_tail
operator|=
name|fra
expr_stmt|;
name|fra
operator|->
name|ipfr_prev
operator|=
name|softf
operator|->
name|ipfr_tail
expr_stmt|;
name|softf
operator|->
name|ipfr_tail
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
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_frag
argument_list|)
expr_stmt|;
block|}
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
comment|/* Function:    ipf_frag_natnew                                             */
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
name|ipf_frag_natnew
parameter_list|(
name|softc
parameter_list|,
name|fin
parameter_list|,
name|pass
parameter_list|,
name|nat
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
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
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_lock
operator|!=
literal|0
condition|)
return|return
literal|0
return|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|fra
operator|=
name|ipfr_frag_new
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|pass
argument_list|,
name|softf
operator|->
name|ipfr_nattab
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
else|#
directive|else
name|fra
operator|=
name|ipfr_frag_new
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|pass
argument_list|,
name|softf
operator|->
name|ipfr_nattab
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|softf
operator|->
name|ipfr_nattail
operator|=
name|fra
expr_stmt|;
name|fra
operator|->
name|ipfr_prev
operator|=
name|softf
operator|->
name|ipfr_nattail
expr_stmt|;
name|softf
operator|->
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
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_ipidnew                                            */
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
name|ipf_frag_ipidnew
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
name|ipf_main_softc_t
modifier|*
name|softc
init|=
name|fin
operator|->
name|fin_main_soft
decl_stmt|;
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_lock
condition|)
return|return
literal|0
return|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|fra
operator|=
name|ipfr_frag_new
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
literal|0
argument_list|,
name|softf
operator|->
name|ipfr_ipidtab
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_ipidfrag
argument_list|)
expr_stmt|;
else|#
directive|else
name|fra
operator|=
name|ipfr_frag_new
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
literal|0
argument_list|,
name|softf
operator|->
name|ipfr_ipidtab
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|intptr_t
operator|)
name|ipid
expr_stmt|;
operator|*
name|softf
operator|->
name|ipfr_ipidtail
operator|=
name|fra
expr_stmt|;
name|fra
operator|->
name|ipfr_prev
operator|=
name|softf
operator|->
name|ipfr_ipidtail
expr_stmt|;
name|softf
operator|->
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
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_ipidfrag
argument_list|)
expr_stmt|;
block|}
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
comment|/* Function:    ipf_frag_lookup                                             */
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
comment|/*                                                                          */
end_comment

begin_comment
comment|/* If this function succeeds, it returns with a write lock held on "lock".  */
end_comment

begin_comment
comment|/* If it fails, no lock is held on return.                                  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|ipfr_t
modifier|*
name|ipf_frag_lookup
parameter_list|(
name|softc
parameter_list|,
name|softf
parameter_list|,
name|fin
parameter_list|,
name|table
ifdef|#
directive|ifdef
name|USE_MUTEXES
parameter_list|,
name|lock
endif|#
directive|endif
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|ipf_frag_softc_t
modifier|*
name|softf
decl_stmt|;
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|ipfr_t
modifier|*
name|table
index|[]
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipfrwlock_t
modifier|*
name|lock
decl_stmt|;
endif|#
directive|endif
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
comment|/* 	 * We don't want to let short packets match because they could be 	 * compromising the security of other rules that want to match on 	 * layer 4 fields (and can't because they have been fragmented off.) 	 * Why do this check here?  The counter acts as an indicator of this 	 * kind of attack, whereas if it was elsewhere, it wouldn't know if 	 * other matching packets had been seen. 	 */
if|if
condition|(
name|fin
operator|->
name|fin_flx
operator|&
name|FI_SHORT
condition|)
block|{
name|FBUMPD
argument_list|(
name|ifs_short
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_flx
operator|&
name|FI_BAD
operator|)
operator|!=
literal|0
condition|)
block|{
name|FBUMPD
argument_list|(
name|ifs_bad
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|/* 	 * For fragments, we record protocol, packet id, TOS and both IP#'s 	 * (these should all be the same for all fragments of a packet). 	 * 	 * build up a hash value to index the table with. 	 */
name|frag
operator|.
name|ipfr_v
operator|=
name|fin
operator|->
name|fin_v
expr_stmt|;
name|idx
operator|=
name|fin
operator|->
name|fin_v
expr_stmt|;
name|frag
operator|.
name|ipfr_p
operator|=
name|fin
operator|->
name|fin_p
expr_stmt|;
name|idx
operator|+=
name|fin
operator|->
name|fin_p
expr_stmt|;
name|frag
operator|.
name|ipfr_id
operator|=
name|fin
operator|->
name|fin_id
expr_stmt|;
name|idx
operator|+=
name|fin
operator|->
name|fin_id
expr_stmt|;
name|frag
operator|.
name|ipfr_source
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_src
expr_stmt|;
name|idx
operator|+=
name|frag
operator|.
name|ipfr_src
operator|.
name|s_addr
expr_stmt|;
name|frag
operator|.
name|ipfr_dest
operator|=
name|fin
operator|->
name|fin_fi
operator|.
name|fi_dst
expr_stmt|;
name|idx
operator|+=
name|frag
operator|.
name|ipfr_dst
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
name|softf
operator|->
name|ipfr_size
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
name|READ_ENTER
argument_list|(
name|lock
argument_list|)
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
block|{
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
comment|/* 			 * XXX - We really need to be guarding against the 			 * retransmission of (src,dst,id,offset-range) here 			 * because a fragmented packet is never resent with 			 * the same IP ID# (or shouldn't). 			 */
name|off
operator|=
name|fin
operator|->
name|fin_off
operator|>>
literal|3
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
name|FBUMPD
argument_list|(
name|ifs_retrans0
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/* 				 * Case 3. See comment for frpr_fragment6. 				 */
if|if
condition|(
operator|(
name|f
operator|->
name|ipfr_firstend
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|off
operator|<
name|f
operator|->
name|ipfr_firstend
operator|)
condition|)
block|{
name|FBUMP
argument_list|(
name|ifs_overlap
argument_list|)
expr_stmt|;
name|DT2
argument_list|(
name|ifs_overlap
argument_list|,
name|u_short
argument_list|,
name|off
argument_list|,
name|ipfr_t
operator|*
argument_list|,
name|f
argument_list|)
expr_stmt|;
name|fin
operator|->
name|fin_flx
operator||=
name|FI_BAD
expr_stmt|;
break|break;
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
operator|&&
name|MUTEX_TRY_UPGRADE
argument_list|(
name|lock
argument_list|)
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
name|MUTEX_DOWNGRADE
argument_list|(
name|lock
argument_list|)
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
comment|/* 				 * Well, we could shrink the expiration time 				 * but only if every fragment has been seen 				 * in order upto this, the last. ipfr_badorder 				 * is used here to count those out of order 				 * and if it equals 0 when we get to the last 				 * fragment then we can assume all of the 				 * fragments have been seen and in order. 				 */
if|#
directive|if
literal|0
comment|/* 				 * Doing this properly requires moving it to 				 * the head of the list which is infesible. 				 */
block|if ((more == 0)&& (f->ipfr_badorder == 0)) 					f->ipfr_ttl = softc->ipf_ticks + 1;
endif|#
directive|endif
block|}
else|else
block|{
name|f
operator|->
name|ipfr_badorder
operator|++
expr_stmt|;
name|FBUMPD
argument_list|(
name|ifs_unordered
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|->
name|ipfr_pass
operator|&
name|FR_FRSTRICT
condition|)
block|{
name|FBUMPD
argument_list|(
name|ifs_strict
argument_list|)
expr_stmt|;
continue|continue;
block|}
block|}
name|f
operator|->
name|ipfr_pkts
operator|++
expr_stmt|;
name|f
operator|->
name|ipfr_bytes
operator|+=
name|fin
operator|->
name|fin_plen
expr_stmt|;
name|FBUMP
argument_list|(
name|ifs_hits
argument_list|)
expr_stmt|;
return|return
name|f
return|;
block|}
block|}
name|RWLOCK_EXIT
argument_list|(
name|lock
argument_list|)
expr_stmt|;
name|FBUMP
argument_list|(
name|ifs_miss
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_natknown                                           */
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
name|ipf_frag_natknown
parameter_list|(
name|fin
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
block|{
name|ipf_main_softc_t
modifier|*
name|softc
init|=
name|fin
operator|->
name|fin_main_soft
decl_stmt|;
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
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
name|softf
operator|->
name|ipfr_lock
operator|)
operator|||
operator|!
name|softf
operator|->
name|ipfr_natlist
condition|)
return|return
name|NULL
return|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipf
operator|=
name|ipf_frag_lookup
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|softf
operator|->
name|ipfr_nattab
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
else|#
directive|else
name|ipf
operator|=
name|ipf_frag_lookup
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|softf
operator|->
name|ipfr_nattab
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|softc
operator|->
name|ipf_ticks
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
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
block|}
else|else
name|nat
operator|=
name|NULL
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
comment|/* Function:    ipf_frag_ipidknown                                          */
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
name|ipf_frag_ipidknown
parameter_list|(
name|fin
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
block|{
name|ipf_main_softc_t
modifier|*
name|softc
init|=
name|fin
operator|->
name|fin_main_soft
decl_stmt|;
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
name|ipfr_t
modifier|*
name|ipf
decl_stmt|;
name|u_32_t
name|id
decl_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_lock
operator|||
operator|!
name|softf
operator|->
name|ipfr_ipidlist
condition|)
return|return
literal|0xffffffff
return|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipf
operator|=
name|ipf_frag_lookup
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|softf
operator|->
name|ipfr_ipidtab
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_ipidfrag
argument_list|)
expr_stmt|;
else|#
directive|else
name|ipf
operator|=
name|ipf_frag_lookup
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|softf
operator|->
name|ipfr_ipidtab
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ipf
operator|!=
name|NULL
condition|)
block|{
name|id
operator|=
operator|(
name|u_32_t
operator|)
operator|(
name|intptr_t
operator|)
name|ipf
operator|->
name|ipfr_data
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_ipidfrag
argument_list|)
expr_stmt|;
block|}
else|else
name|id
operator|=
literal|0xffffffff
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
comment|/* Function:    ipf_frag_known                                              */
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
name|ipf_frag_known
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
name|ipf_main_softc_t
modifier|*
name|softc
init|=
name|fin
operator|->
name|fin_main_soft
decl_stmt|;
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
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
name|softf
operator|->
name|ipfr_lock
operator|)
operator|||
operator|(
name|softf
operator|->
name|ipfr_list
operator|==
name|NULL
operator|)
condition|)
return|return
name|NULL
return|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|fra
operator|=
name|ipf_frag_lookup
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|softf
operator|->
name|ipfr_heads
argument_list|,
operator|&
name|softc
operator|->
name|ipf_frag
argument_list|)
expr_stmt|;
else|#
directive|else
name|fra
operator|=
name|ipf_frag_lookup
argument_list|(
name|softc
argument_list|,
name|softf
argument_list|,
name|fin
argument_list|,
name|softf
operator|->
name|ipfr_heads
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|fra
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|fin
operator|->
name|fin_flx
operator|&
name|FI_BAD
condition|)
block|{
name|fr
operator|=
operator|&
name|ipfr_block
expr_stmt|;
name|fin
operator|->
name|fin_reason
operator|=
name|FRB_BADFRAG
expr_stmt|;
block|}
else|else
block|{
name|fr
operator|=
name|fra
operator|->
name|ipfr_rule
expr_stmt|;
block|}
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
name|FR_KEEPSTATE
operator|)
operator|!=
literal|0
condition|)
block|{
name|fin
operator|->
name|fin_flx
operator||=
name|FI_STATE
expr_stmt|;
comment|/* 				 * Reset the keep state flag here so that we 				 * don't try and add a new state entry because 				 * of a match here. That leads to blocking of 				 * the packet later because the add fails. 				 */
name|pass
operator|&=
operator|~
name|FR_KEEPSTATE
expr_stmt|;
block|}
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
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_frag
argument_list|)
expr_stmt|;
block|}
return|return
name|fr
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_natforget                                          */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              ptr(I) - pointer to data structure                          */
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
name|ipf_frag_natforget
parameter_list|(
name|softc
parameter_list|,
name|ptr
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
name|ipfr_t
modifier|*
name|fr
decl_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
for|for
control|(
name|fr
operator|=
name|softf
operator|->
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
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_delete                                             */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              fra(I)   - pointer to fragment structure to delete          */
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
name|ipf_frag_delete
parameter_list|(
name|softc
parameter_list|,
name|fra
parameter_list|,
name|tail
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
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
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
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
if|if
condition|(
name|fra
operator|->
name|ipfr_rule
operator|!=
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|ipf_derefrule
argument_list|(
name|softc
argument_list|,
operator|&
name|fra
operator|->
name|ipfr_rule
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|fra
operator|->
name|ipfr_ref
operator|<=
literal|0
condition|)
name|ipf_frag_free
argument_list|(
name|softf
argument_list|,
name|fra
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_free                                               */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softf(I) - pointer to fragment context information          */
end_comment

begin_comment
comment|/*              fra(I)   - pointer to fragment structure to free            */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Free up a fragment cache entry and bump relevent statistics.             */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_frag_free
parameter_list|(
name|softf
parameter_list|,
name|fra
parameter_list|)
name|ipf_frag_softc_t
modifier|*
name|softf
decl_stmt|;
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
block|{
name|KFREE
argument_list|(
name|fra
argument_list|)
expr_stmt|;
name|FBUMP
argument_list|(
name|ifs_expire
argument_list|)
expr_stmt|;
name|softf
operator|->
name|ipfr_stats
operator|.
name|ifs_inuse
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_clear                                              */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
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
name|ipf_frag_clear
parameter_list|(
name|softc
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
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
name|softc
operator|->
name|ipf_frag
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|fra
operator|=
name|softf
operator|->
name|ipfr_list
operator|)
operator|!=
name|NULL
condition|)
block|{
name|fra
operator|->
name|ipfr_ref
operator|--
expr_stmt|;
name|ipf_frag_delete
argument_list|(
name|softc
argument_list|,
name|fra
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_tail
argument_list|)
expr_stmt|;
block|}
name|softf
operator|->
name|ipfr_tail
operator|=
operator|&
name|softf
operator|->
name|ipfr_list
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_frag
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_nat
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|fra
operator|=
name|softf
operator|->
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
name|fra
operator|->
name|ipfr_ref
operator|--
expr_stmt|;
name|ipf_frag_delete
argument_list|(
name|softc
argument_list|,
name|fra
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_nattail
argument_list|)
expr_stmt|;
block|}
name|softf
operator|->
name|ipfr_nattail
operator|=
operator|&
name|softf
operator|->
name|ipfr_natlist
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_nat
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_expire                                             */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
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
name|ipf_frag_expire
parameter_list|(
name|softc
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
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
name|SPL_INT
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|softf
operator|->
name|ipfr_lock
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
name|softc
operator|->
name|ipf_frag
argument_list|)
expr_stmt|;
comment|/* 	 * Go through the entire table, looking for entries to expire, 	 * which is indicated by the ttl being less than or equal to ipf_ticks. 	 */
for|for
control|(
name|fp
operator|=
operator|&
name|softf
operator|->
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
name|softc
operator|->
name|ipf_ticks
condition|)
break|break;
name|fra
operator|->
name|ipfr_ref
operator|--
expr_stmt|;
name|ipf_frag_delete
argument_list|(
name|softc
argument_list|,
name|fra
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_tail
argument_list|)
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_frag
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_ipidfrag
argument_list|)
expr_stmt|;
for|for
control|(
name|fp
operator|=
operator|&
name|softf
operator|->
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
name|softc
operator|->
name|ipf_ticks
condition|)
break|break;
name|fra
operator|->
name|ipfr_ref
operator|--
expr_stmt|;
name|ipf_frag_delete
argument_list|(
name|softc
argument_list|,
name|fra
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_ipidtail
argument_list|)
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_ipidfrag
argument_list|)
expr_stmt|;
comment|/* 	 * Same again for the NAT table, except that if the structure also 	 * still points to a NAT structure, and the NAT structure points back 	 * at the one to be free'd, NULL the reference from the NAT struct. 	 * NOTE: We need to grab both mutex's early, and in this order so as 	 * to prevent a deadlock if both try to expire at the same time. 	 * The extra if() statement here is because it locks out all NAT 	 * operations - no need to do that if there are no entries in this 	 * list, right? 	 */
if|if
condition|(
name|softf
operator|->
name|ipfr_natlist
operator|!=
name|NULL
condition|)
block|{
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_nat
argument_list|)
expr_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
for|for
control|(
name|fp
operator|=
operator|&
name|softf
operator|->
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
name|softc
operator|->
name|ipf_ticks
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
name|fra
operator|->
name|ipfr_ref
operator|--
expr_stmt|;
name|ipf_frag_delete
argument_list|(
name|softc
argument_list|,
name|fra
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_nattail
argument_list|)
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_nat
argument_list|)
expr_stmt|;
block|}
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
comment|/* Function:    ipf_frag_pkt_next                                           */
end_comment

begin_comment
comment|/* Returns:     int      - 0 == success, else error                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              token(I) - pointer to token information for this caller     */
end_comment

begin_comment
comment|/*              itp(I)   - pointer to generic iterator from caller          */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is used to step through the fragment cache list used for   */
end_comment

begin_comment
comment|/* filter rules. The hard work is done by the more generic ipf_frag_next.   */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_frag_pkt_next
parameter_list|(
name|softc
parameter_list|,
name|token
parameter_list|,
name|itp
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|ipftoken_t
modifier|*
name|token
decl_stmt|;
name|ipfgeniter_t
modifier|*
name|itp
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
return|return
name|ipf_frag_next
argument_list|(
name|softc
argument_list|,
name|token
argument_list|,
name|itp
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_list
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_frag
argument_list|)
return|;
else|#
directive|else
return|return
name|ipf_frag_next
argument_list|(
name|softc
argument_list|,
name|token
argument_list|,
name|itp
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_list
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_nat_next                                           */
end_comment

begin_comment
comment|/* Returns:     int      - 0 == success, else error                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              token(I) - pointer to token information for this caller     */
end_comment

begin_comment
comment|/*              itp(I)   - pointer to generic iterator from caller          */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is used to step through the fragment cache list used for   */
end_comment

begin_comment
comment|/* NAT. The hard work is done by the more generic ipf_frag_next.            */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_frag_nat_next
parameter_list|(
name|softc
parameter_list|,
name|token
parameter_list|,
name|itp
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|ipftoken_t
modifier|*
name|token
decl_stmt|;
name|ipfgeniter_t
modifier|*
name|itp
decl_stmt|;
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
empty_stmt|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
return|return
name|ipf_frag_next
argument_list|(
name|softc
argument_list|,
name|token
argument_list|,
name|itp
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_natlist
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
return|;
else|#
directive|else
return|return
name|ipf_frag_next
argument_list|(
name|softc
argument_list|,
name|token
argument_list|,
name|itp
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_natlist
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_next                                               */
end_comment

begin_comment
comment|/* Returns:     int      - 0 == success, else error                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              token(I) - pointer to token information for this caller     */
end_comment

begin_comment
comment|/*              itp(I)   - pointer to generic iterator from caller          */
end_comment

begin_comment
comment|/*              top(I)   - top of the fragment list                         */
end_comment

begin_comment
comment|/*              lock(I)  - fragment cache lock                              */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is used to interate through the list of entries in the     */
end_comment

begin_comment
comment|/* fragment cache.  It increases the reference count on the one currently   */
end_comment

begin_comment
comment|/* being returned so that the caller can come back and resume from it later.*/
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is used for both the NAT fragment cache as well as the ipf */
end_comment

begin_comment
comment|/* fragment cache - hence the reason for passing in top and lock.           */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_frag_next
parameter_list|(
name|softc
parameter_list|,
name|token
parameter_list|,
name|itp
parameter_list|,
name|top
ifdef|#
directive|ifdef
name|USE_MUTEXES
parameter_list|,
name|lock
endif|#
directive|endif
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|ipftoken_t
modifier|*
name|token
decl_stmt|;
name|ipfgeniter_t
modifier|*
name|itp
decl_stmt|;
name|ipfr_t
modifier|*
modifier|*
name|top
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipfrwlock_t
modifier|*
name|lock
decl_stmt|;
endif|#
directive|endif
block|{
name|ipfr_t
modifier|*
name|frag
decl_stmt|,
modifier|*
name|next
decl_stmt|,
name|zero
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|itp
operator|->
name|igi_data
operator|==
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|20001
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
if|if
condition|(
name|itp
operator|->
name|igi_nitems
operator|!=
literal|1
condition|)
block|{
name|IPFERROR
argument_list|(
literal|20003
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
name|frag
operator|=
name|token
operator|->
name|ipt_data
expr_stmt|;
name|READ_ENTER
argument_list|(
name|lock
argument_list|)
expr_stmt|;
if|if
condition|(
name|frag
operator|==
name|NULL
condition|)
name|next
operator|=
operator|*
name|top
expr_stmt|;
else|else
name|next
operator|=
name|frag
operator|->
name|ipfr_next
expr_stmt|;
if|if
condition|(
name|next
operator|!=
name|NULL
condition|)
block|{
name|ATOMIC_INC
argument_list|(
name|next
operator|->
name|ipfr_ref
argument_list|)
expr_stmt|;
name|token
operator|->
name|ipt_data
operator|=
name|next
expr_stmt|;
block|}
else|else
block|{
name|bzero
argument_list|(
operator|&
name|zero
argument_list|,
sizeof|sizeof
argument_list|(
name|zero
argument_list|)
argument_list|)
expr_stmt|;
name|next
operator|=
operator|&
name|zero
expr_stmt|;
name|token
operator|->
name|ipt_data
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|next
operator|->
name|ipfr_next
operator|==
name|NULL
condition|)
name|ipf_token_mark_complete
argument_list|(
name|token
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
name|lock
argument_list|)
expr_stmt|;
name|error
operator|=
name|COPYOUT
argument_list|(
name|next
argument_list|,
name|itp
operator|->
name|igi_data
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|next
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
name|IPFERROR
argument_list|(
literal|20002
argument_list|)
expr_stmt|;
if|if
condition|(
name|frag
operator|!=
name|NULL
condition|)
block|{
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipf_frag_deref
argument_list|(
name|softc
argument_list|,
operator|&
name|frag
argument_list|,
name|lock
argument_list|)
expr_stmt|;
else|#
directive|else
name|ipf_frag_deref
argument_list|(
name|softc
argument_list|,
operator|&
name|frag
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_pkt_deref                                          */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I)  - pointer to frag cache pointer                    */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is the external interface for dropping a reference to a    */
end_comment

begin_comment
comment|/* fragment cache entry used by filter rules.                               */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ipf_frag_pkt_deref
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|{
name|ipfr_t
modifier|*
modifier|*
name|frp
init|=
name|data
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
name|ipf_frag_deref
argument_list|(
name|softc
operator|->
name|ipf_frag_soft
argument_list|,
name|frp
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_frag
argument_list|)
expr_stmt|;
else|#
directive|else
name|ipf_frag_deref
argument_list|(
name|softc
operator|->
name|ipf_frag_soft
argument_list|,
name|frp
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_nat_deref                                          */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I)  - pointer to frag cache pointer                    */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is the external interface for dropping a reference to a    */
end_comment

begin_comment
comment|/* fragment cache entry used by NAT table entries.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ipf_frag_nat_deref
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|{
name|ipfr_t
modifier|*
modifier|*
name|frp
init|=
name|data
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|softc
operator|->
name|ipf_frag_soft
decl_stmt|;
name|ipf_frag_deref
argument_list|(
name|softc
operator|->
name|ipf_frag_soft
argument_list|,
name|frp
argument_list|,
operator|&
name|softf
operator|->
name|ipfr_natfrag
argument_list|)
expr_stmt|;
else|#
directive|else
name|ipf_frag_deref
argument_list|(
name|softc
operator|->
name|ipf_frag_soft
argument_list|,
name|frp
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_frag_deref                                              */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  frp(IO) - pointer to fragment structure to deference        */
end_comment

begin_comment
comment|/*              lock(I) - lock associated with the fragment                 */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function dereferences a fragment structure (ipfr_t).  The pointer   */
end_comment

begin_comment
comment|/* passed in will always be reset back to NULL, even if the structure is    */
end_comment

begin_comment
comment|/* not freed, to enforce the notion that the caller is no longer entitled   */
end_comment

begin_comment
comment|/* to use the pointer it is dropping the reference to.                      */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_frag_deref
parameter_list|(
name|arg
parameter_list|,
name|frp
ifdef|#
directive|ifdef
name|USE_MUTEXES
parameter_list|,
name|lock
endif|#
directive|endif
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
name|ipfr_t
modifier|*
modifier|*
name|frp
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipfrwlock_t
modifier|*
name|lock
decl_stmt|;
endif|#
directive|endif
block|{
name|ipf_frag_softc_t
modifier|*
name|softf
init|=
name|arg
decl_stmt|;
name|ipfr_t
modifier|*
name|fra
decl_stmt|;
name|fra
operator|=
operator|*
name|frp
expr_stmt|;
operator|*
name|frp
operator|=
name|NULL
expr_stmt|;
name|WRITE_ENTER
argument_list|(
name|lock
argument_list|)
expr_stmt|;
name|fra
operator|->
name|ipfr_ref
operator|--
expr_stmt|;
if|if
condition|(
name|fra
operator|->
name|ipfr_ref
operator|<=
literal|0
condition|)
name|ipf_frag_free
argument_list|(
name|softf
argument_list|,
name|fra
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
name|lock
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

