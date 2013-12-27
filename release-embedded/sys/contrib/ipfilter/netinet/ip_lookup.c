begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PROTO_NET_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/types.h>
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|220000
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ipf.h"
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
file|"netinet/ip_lookup.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_pool.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_htable.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_dstlist.h"
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
name|rcsid
index|[]
init|=
literal|"@(#)$Id$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * In this file, ip_pool.c, ip_htable.c and ip_dstlist.c, you will find the  * range for unit is [-1,IPL_LOGMAX]. The -1 is considered to be a valid number  * and represents a "wildcard" or "all" units (IPL_LOGALL). The reason for not  * starting the numbering at 0 is because the numbers [0,IPL_LOGMAX] correspond  * to the minor device number for their respective device. Thus where there is  * array indexing on the unit, +1 is used to map [-1.IPL_LOGMAX] to  * [0.POOL_LOOKUP_MAX].  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ipf_lookup_addnode
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_lookup_delnode
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_lookup_addtable
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_lookup_deltable
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_lookup_stats
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_lookup_flush
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_lookup_iterate
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_lookup_deltok
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_BACKENDS
value|3
end_define

begin_decl_stmt
specifier|static
name|ipf_lookup_t
modifier|*
name|backends
index|[
name|MAX_BACKENDS
index|]
init|=
block|{
operator|&
name|ipf_pool_backend
block|,
operator|&
name|ipf_htable_backend
block|,
operator|&
name|ipf_dstlist_backend
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|ipf_lookup_softc_s
block|{
name|void
modifier|*
name|ipf_back
index|[
name|MAX_BACKENDS
index|]
decl_stmt|;
block|}
name|ipf_lookup_softc_t
typedef|;
end_typedef

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_init                                             */
end_comment

begin_comment
comment|/* Returns:     int      - 0 = success, else error                          */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Initialise all of the subcomponents of the lookup infrstructure.         */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
modifier|*
name|ipf_lookup_soft_create
parameter_list|(
name|softc
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|int
name|i
decl_stmt|;
name|KMALLOC
argument_list|(
name|softl
argument_list|,
name|ipf_lookup_softc_t
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|softl
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
name|softl
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|softl
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
block|{
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|=
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_create
operator|)
operator|(
name|softc
operator|)
expr_stmt|;
if|if
condition|(
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|==
name|NULL
condition|)
block|{
name|ipf_lookup_soft_destroy
argument_list|(
name|softc
argument_list|,
name|softl
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
block|}
return|return
name|softl
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_soft_init                                        */
end_comment

begin_comment
comment|/* Returns:     int      - 0 = success, else error                          */
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
comment|/* Initialise all of the subcomponents of the lookup infrstructure.         */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_lookup_soft_init
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
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
operator|(
name|ipf_lookup_softc_t
operator|*
operator|)
name|arg
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
control|)
block|{
name|err
operator|=
operator|(
operator|*
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_init
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
break|break;
block|}
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_soft_fini                                        */
end_comment

begin_comment
comment|/* Returns:     int      - 0 = success, else error                          */
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
comment|/* Call the fini function in each backend to cleanup all allocated data.    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_lookup_soft_fini
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
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
operator|(
name|ipf_lookup_softc_t
operator|*
operator|)
name|arg
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|!=
name|NULL
condition|)
operator|(
operator|*
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_fini
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_expire                                           */
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
comment|/* Step through each of the backends and call their expire functions,       */
end_comment

begin_comment
comment|/* allowing them to delete any lifetime limited data.                       */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ipf_lookup_expire
parameter_list|(
name|softc
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|int
name|i
decl_stmt|;
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
control|)
operator|(
operator|*
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_expire
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_softc_destroy                                    */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
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
comment|/* Free up all pool related memory that has been allocated whilst IPFilter  */
end_comment

begin_comment
comment|/* has been running.  Also, do any other deinitialisation required such     */
end_comment

begin_comment
comment|/* ipf_lookup_init() can be called again, safely.                           */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ipf_lookup_soft_destroy
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
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
operator|(
name|ipf_lookup_softc_t
operator|*
operator|)
name|arg
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|!=
name|NULL
condition|)
operator|(
operator|*
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_destroy
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|)
expr_stmt|;
block|}
name|KFREE
argument_list|(
name|softl
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_ioctl                                            */
end_comment

begin_comment
comment|/* Returns:     int      - 0 = success, else error                          */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              data(IO) - pointer to ioctl data to be copied to/from user  */
end_comment

begin_comment
comment|/*                         space.                                           */
end_comment

begin_comment
comment|/*              cmd(I)   - ioctl command number                             */
end_comment

begin_comment
comment|/*              mode(I)  - file mode bits used with open                    */
end_comment

begin_comment
comment|/*              uid(I)   - uid of process doing ioctl                       */
end_comment

begin_comment
comment|/*              ctx(I)   - pointer that represents context for uid          */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Handle ioctl commands sent to the ioctl device.  For the most part, this */
end_comment

begin_comment
comment|/* involves just calling another function to handle the specifics of each   */
end_comment

begin_comment
comment|/* command.                                                                 */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_lookup_ioctl
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|,
name|cmd
parameter_list|,
name|mode
parameter_list|,
name|uid
parameter_list|,
name|ctx
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|ioctlcmd_t
name|cmd
decl_stmt|;
name|int
name|mode
decl_stmt|,
name|uid
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
name|SPL_INT
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|mode
operator|=
name|mode
expr_stmt|;
comment|/* LINT */
name|SPL_NET
argument_list|(
name|s
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|SIOCLOOKUPADDNODE
case|:
case|case
name|SIOCLOOKUPADDNODEW
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|ipf_lookup_addnode
argument_list|(
name|softc
argument_list|,
name|data
argument_list|,
name|uid
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPDELNODE
case|:
case|case
name|SIOCLOOKUPDELNODEW
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|ipf_lookup_delnode
argument_list|(
name|softc
argument_list|,
name|data
argument_list|,
name|uid
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPADDTABLE
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|ipf_lookup_addtable
argument_list|(
name|softc
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPDELTABLE
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|ipf_lookup_deltable
argument_list|(
name|softc
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPSTAT
case|:
case|case
name|SIOCLOOKUPSTATW
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|ipf_lookup_stats
argument_list|(
name|softc
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPFLUSH
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|ipf_lookup_flush
argument_list|(
name|softc
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPITER
case|:
name|err
operator|=
name|ipf_lookup_iterate
argument_list|(
name|softc
argument_list|,
name|data
argument_list|,
name|uid
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCIPFDELTOK
case|:
name|err
operator|=
name|ipf_lookup_deltok
argument_list|(
name|softc
argument_list|,
name|data
argument_list|,
name|uid
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
break|break;
default|default :
name|IPFERROR
argument_list|(
literal|50001
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
name|SPL_X
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_addnode                                          */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I) - pointer to data from ioctl call                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Add a new data node to a lookup structure.  First, check to see if the   */
end_comment

begin_comment
comment|/* parent structure refered to by name exists and if it does, then go on to */
end_comment

begin_comment
comment|/* add a node to it.                                                        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_lookup_addnode
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|,
name|uid
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|int
name|uid
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|iplookupop_t
name|op
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|int
name|err
decl_stmt|;
name|int
name|i
decl_stmt|;
name|err
operator|=
name|BCOPYIN
argument_list|(
name|data
argument_list|,
operator|&
name|op
argument_list|,
sizeof|sizeof
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50002
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
if|if
condition|(
operator|(
name|op
operator|.
name|iplo_unit
operator|<
literal|0
operator|||
name|op
operator|.
name|iplo_unit
operator|>
name|IPL_LOGMAX
operator|)
operator|&&
operator|(
name|op
operator|.
name|iplo_unit
operator|!=
name|IPLT_ALL
operator|)
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50003
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|op
operator|.
name|iplo_name
index|[
sizeof|sizeof
argument_list|(
name|op
operator|.
name|iplo_name
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
block|{
if|if
condition|(
name|op
operator|.
name|iplo_type
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|err
operator|=
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_node_add
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
operator|&
name|op
operator|,
name|uid
operator|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|i
operator|==
name|MAX_BACKENDS
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50012
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_delnode                                          */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I) - pointer to data from ioctl call                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Delete a node from a lookup table by first looking for the table it is   */
end_comment

begin_comment
comment|/* in and then deleting the entry that gets found.                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_lookup_delnode
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|,
name|uid
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|int
name|uid
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|iplookupop_t
name|op
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|int
name|err
decl_stmt|;
name|int
name|i
decl_stmt|;
name|err
operator|=
name|BCOPYIN
argument_list|(
name|data
argument_list|,
operator|&
name|op
argument_list|,
sizeof|sizeof
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50042
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
if|if
condition|(
operator|(
name|op
operator|.
name|iplo_unit
operator|<
literal|0
operator|||
name|op
operator|.
name|iplo_unit
operator|>
name|IPL_LOGMAX
operator|)
operator|&&
operator|(
name|op
operator|.
name|iplo_unit
operator|!=
name|IPLT_ALL
operator|)
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50013
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|op
operator|.
name|iplo_name
index|[
sizeof|sizeof
argument_list|(
name|op
operator|.
name|iplo_name
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
block|{
if|if
condition|(
name|op
operator|.
name|iplo_type
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|err
operator|=
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_node_del
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
operator|&
name|op
operator|,
name|uid
operator|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|i
operator|==
name|MAX_BACKENDS
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50021
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_addtable                                         */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I) - pointer to data from ioctl call                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Create a new lookup table, if one doesn't already exist using the name   */
end_comment

begin_comment
comment|/* for this one.                                                            */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_lookup_addtable
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|iplookupop_t
name|op
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|int
name|err
decl_stmt|,
name|i
decl_stmt|;
name|err
operator|=
name|BCOPYIN
argument_list|(
name|data
argument_list|,
operator|&
name|op
argument_list|,
sizeof|sizeof
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50022
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
if|if
condition|(
operator|(
name|op
operator|.
name|iplo_unit
operator|<
literal|0
operator|||
name|op
operator|.
name|iplo_unit
operator|>
name|IPL_LOGMAX
operator|)
operator|&&
operator|(
name|op
operator|.
name|iplo_unit
operator|!=
name|IPLT_ALL
operator|)
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50023
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|op
operator|.
name|iplo_name
index|[
sizeof|sizeof
argument_list|(
name|op
operator|.
name|iplo_name
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
block|{
if|if
condition|(
name|op
operator|.
name|iplo_type
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|err
operator|=
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_table_add
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
operator|&
name|op
operator|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|i
operator|==
name|MAX_BACKENDS
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50026
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
block|}
comment|/* 	 * For anonymous pools, copy back the operation struct because in the 	 * case of success it will contain the new table's name. 	 */
if|if
condition|(
operator|(
name|err
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|(
name|op
operator|.
name|iplo_arg
operator|&
name|LOOKUP_ANON
operator|)
operator|!=
literal|0
operator|)
condition|)
block|{
name|err
operator|=
name|BCOPYOUT
argument_list|(
operator|&
name|op
argument_list|,
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50027
argument_list|)
expr_stmt|;
name|err
operator|=
name|EFAULT
expr_stmt|;
block|}
block|}
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_deltable                                         */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I) - pointer to data from ioctl call                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Decodes ioctl request to remove a particular hash table or pool and      */
end_comment

begin_comment
comment|/* calls the relevant function to do the cleanup.                           */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_lookup_deltable
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|iplookupop_t
name|op
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|int
name|err
decl_stmt|,
name|i
decl_stmt|;
name|err
operator|=
name|BCOPYIN
argument_list|(
name|data
argument_list|,
operator|&
name|op
argument_list|,
sizeof|sizeof
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50028
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
if|if
condition|(
operator|(
name|op
operator|.
name|iplo_unit
operator|<
literal|0
operator|||
name|op
operator|.
name|iplo_unit
operator|>
name|IPL_LOGMAX
operator|)
operator|&&
operator|(
name|op
operator|.
name|iplo_unit
operator|!=
name|IPLT_ALL
operator|)
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50029
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|op
operator|.
name|iplo_name
index|[
sizeof|sizeof
argument_list|(
name|op
operator|.
name|iplo_name
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
block|{
if|if
condition|(
name|op
operator|.
name|iplo_type
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|err
operator|=
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_table_del
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
operator|&
name|op
operator|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|i
operator|==
name|MAX_BACKENDS
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50030
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_stats                                            */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I) - pointer to data from ioctl call                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Copy statistical information from inside the kernel back to user space.  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_lookup_stats
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|iplookupop_t
name|op
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|int
name|err
decl_stmt|;
name|int
name|i
decl_stmt|;
name|err
operator|=
name|BCOPYIN
argument_list|(
name|data
argument_list|,
operator|&
name|op
argument_list|,
sizeof|sizeof
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50031
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
if|if
condition|(
operator|(
name|op
operator|.
name|iplo_unit
operator|<
literal|0
operator|||
name|op
operator|.
name|iplo_unit
operator|>
name|IPL_LOGMAX
operator|)
operator|&&
operator|(
name|op
operator|.
name|iplo_unit
operator|!=
name|IPLT_ALL
operator|)
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50032
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
block|{
if|if
condition|(
name|op
operator|.
name|iplo_type
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|err
operator|=
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_stats_get
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
operator|&
name|op
operator|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|i
operator|==
name|MAX_BACKENDS
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50033
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_flush                                            */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I) - pointer to data from ioctl call                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* A flush is called when we want to flush all the nodes from a particular  */
end_comment

begin_comment
comment|/* entry in the hash table/pool or want to remove all groups from those.    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_lookup_flush
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|int
name|err
decl_stmt|,
name|unit
decl_stmt|,
name|num
decl_stmt|,
name|type
decl_stmt|,
name|i
decl_stmt|;
name|iplookupflush_t
name|flush
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|err
operator|=
name|BCOPYIN
argument_list|(
name|data
argument_list|,
operator|&
name|flush
argument_list|,
sizeof|sizeof
argument_list|(
name|flush
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50034
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
name|unit
operator|=
name|flush
operator|.
name|iplf_unit
expr_stmt|;
if|if
condition|(
operator|(
name|unit
operator|<
literal|0
operator|||
name|unit
operator|>
name|IPL_LOGMAX
operator|)
operator|&&
operator|(
name|unit
operator|!=
name|IPLT_ALL
operator|)
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50035
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|flush
operator|.
name|iplf_name
index|[
sizeof|sizeof
argument_list|(
name|flush
operator|.
name|iplf_name
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|type
operator|=
name|flush
operator|.
name|iplf_type
expr_stmt|;
name|IPFERROR
argument_list|(
literal|50036
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
name|num
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
block|{
if|if
condition|(
name|type
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
operator|||
name|type
operator|==
name|IPLT_ALL
condition|)
block|{
name|err
operator|=
literal|0
expr_stmt|;
name|num
operator|+=
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_flush
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
operator|&
name|flush
operator|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|err
operator|==
literal|0
condition|)
block|{
name|flush
operator|.
name|iplf_count
operator|=
name|num
expr_stmt|;
name|err
operator|=
name|BCOPYOUT
argument_list|(
operator|&
name|flush
argument_list|,
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|flush
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50037
argument_list|)
expr_stmt|;
name|err
operator|=
name|EFAULT
expr_stmt|;
block|}
block|}
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_delref                                           */
end_comment

begin_comment
comment|/* Returns:     void                                                        */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              type(I) - table type to operate on                          */
end_comment

begin_comment
comment|/*              ptr(I)  - pointer to object to remove reference for         */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function organises calling the correct deref function for a given   */
end_comment

begin_comment
comment|/* type of object being passed into it.                                     */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ipf_lookup_deref
parameter_list|(
name|softc
parameter_list|,
name|type
parameter_list|,
name|ptr
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|int
name|type
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|ptr
operator|==
name|NULL
condition|)
return|return;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|type
operator|==
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_type
condition|)
block|{
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
operator|(
operator|*
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_table_deref
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
name|ptr
operator|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_iterate                                          */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I) - pointer to data from ioctl call                   */
end_comment

begin_comment
comment|/*              uid(I)  - uid of caller                                     */
end_comment

begin_comment
comment|/*              ctx(I)  - pointer to give the uid context                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Decodes ioctl request to step through either hash tables or pools.       */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_lookup_iterate
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|,
name|uid
parameter_list|,
name|ctx
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|int
name|uid
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|ipflookupiter_t
name|iter
decl_stmt|;
name|ipftoken_t
modifier|*
name|token
decl_stmt|;
name|int
name|err
decl_stmt|,
name|i
decl_stmt|;
name|SPL_INT
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|err
operator|=
name|ipf_inobj
argument_list|(
name|softc
argument_list|,
name|data
argument_list|,
name|NULL
argument_list|,
operator|&
name|iter
argument_list|,
name|IPFOBJ_LOOKUPITER
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
name|err
return|;
if|if
condition|(
name|iter
operator|.
name|ili_unit
operator|<
name|IPL_LOGALL
operator|&&
name|iter
operator|.
name|ili_unit
operator|>
name|IPL_LOGMAX
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50038
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
if|if
condition|(
name|iter
operator|.
name|ili_ival
operator|!=
name|IPFGENITER_LOOKUP
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50039
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|SPL_SCHED
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|token
operator|=
name|ipf_token_find
argument_list|(
name|softc
argument_list|,
name|iter
operator|.
name|ili_key
argument_list|,
name|uid
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
if|if
condition|(
name|token
operator|==
name|NULL
condition|)
block|{
name|SPL_X
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|IPFERROR
argument_list|(
literal|50040
argument_list|)
expr_stmt|;
return|return
name|ESRCH
return|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|iter
operator|.
name|ili_type
operator|==
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_type
condition|)
block|{
name|err
operator|=
operator|(
operator|*
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_iter_next
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
name|token
operator|,
operator|&
name|iter
operator|)
expr_stmt|;
break|break;
block|}
block|}
name|SPL_X
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|MAX_BACKENDS
condition|)
block|{
name|IPFERROR
argument_list|(
literal|50041
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
block|}
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_tokens
argument_list|)
expr_stmt|;
name|ipf_token_deref
argument_list|(
name|softc
argument_list|,
name|token
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_tokens
argument_list|)
expr_stmt|;
return|return
name|err
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_iterderef                                        */
end_comment

begin_comment
comment|/* Returns:     void                                                        */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              type(I)  - backend type to iterate through                  */
end_comment

begin_comment
comment|/*              data(I)  - pointer to data from ioctl call                  */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Decodes ioctl request to remove a particular hash table or pool and      */
end_comment

begin_comment
comment|/* calls the relevant function to do the cleanup.                           */
end_comment

begin_comment
comment|/* Because each of the backend types has a different data structure,        */
end_comment

begin_comment
comment|/* iteration is limited to one type at a time (i.e. it is not permitted to  */
end_comment

begin_comment
comment|/* go on from pool types to hash types as part of the "get next".)          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ipf_lookup_iterderef
parameter_list|(
name|softc
parameter_list|,
name|type
parameter_list|,
name|data
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|u_32_t
name|type
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|struct
name|iplookupiterkey
modifier|*
name|lkey
decl_stmt|;
name|iplookupiterkey_t
name|key
decl_stmt|;
name|int
name|i
decl_stmt|;
name|key
operator|.
name|ilik_key
operator|=
name|type
expr_stmt|;
name|lkey
operator|=
operator|&
name|key
operator|.
name|ilik_unstr
expr_stmt|;
if|if
condition|(
name|lkey
operator|->
name|ilik_ival
operator|!=
name|IPFGENITER_LOOKUP
condition|)
return|return;
name|WRITE_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|lkey
operator|->
name|ilik_type
operator|==
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_type
condition|)
block|{
operator|(
operator|*
name|backends
index|[
name|i
index|]
operator|->
name|ipfl_iter_deref
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
name|lkey
operator|->
name|ilik_otype
operator|,
name|lkey
operator|->
name|ilik_unit
operator|,
name|data
operator|)
expr_stmt|;
break|break;
block|}
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_deltok                                           */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              data(I) - pointer to data from ioctl call                   */
end_comment

begin_comment
comment|/*              uid(I)  - uid of caller                                     */
end_comment

begin_comment
comment|/*              ctx(I)  - pointer to give the uid context                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Deletes the token identified by the combination of (type,uid,ctx)        */
end_comment

begin_comment
comment|/* "key" is a combination of the table type, iterator type and the unit for */
end_comment

begin_comment
comment|/* which the token was being used.                                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_lookup_deltok
parameter_list|(
name|softc
parameter_list|,
name|data
parameter_list|,
name|uid
parameter_list|,
name|ctx
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|int
name|uid
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
block|{
name|int
name|error
decl_stmt|,
name|key
decl_stmt|;
name|SPL_INT
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|SPL_SCHED
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|error
operator|=
name|BCOPYIN
argument_list|(
name|data
argument_list|,
operator|&
name|key
argument_list|,
sizeof|sizeof
argument_list|(
name|key
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
condition|)
name|error
operator|=
name|ipf_token_del
argument_list|(
name|softc
argument_list|,
name|key
argument_list|,
name|uid
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
name|SPL_X
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_res_num                                          */
end_comment

begin_comment
comment|/* Returns:     void * - NULL = failure, else success.                      */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              unit(I)     - device for which this is for                  */
end_comment

begin_comment
comment|/*              type(I)     - type of lookup these parameters are for.      */
end_comment

begin_comment
comment|/*              number(I)   - table number to use when searching            */
end_comment

begin_comment
comment|/*              funcptr(IO) - pointer to pointer for storing IP address     */
end_comment

begin_comment
comment|/*                            searching function.                           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Search for the "table" number passed in amongst those configured for     */
end_comment

begin_comment
comment|/* that particular type.  If the type is recognised then the function to    */
end_comment

begin_comment
comment|/* call to do the IP address search will be change, regardless of whether   */
end_comment

begin_comment
comment|/* or not the "table" number exists.                                        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
modifier|*
name|ipf_lookup_res_num
parameter_list|(
name|softc
parameter_list|,
name|unit
parameter_list|,
name|type
parameter_list|,
name|number
parameter_list|,
name|funcptr
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|u_int
name|type
decl_stmt|;
name|u_int
name|number
decl_stmt|;
name|lookupfunc_t
modifier|*
name|funcptr
decl_stmt|;
block|{
name|char
name|name
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SNPRINTF
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
name|SNPRINTF
argument_list|(
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|,
literal|"%u"
argument_list|,
name|number
argument_list|)
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"%u"
argument_list|,
name|number
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|ipf_lookup_res_name
argument_list|(
name|softc
argument_list|,
name|unit
argument_list|,
name|type
argument_list|,
name|name
argument_list|,
name|funcptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_res_name                                         */
end_comment

begin_comment
comment|/* Returns:     void * - NULL = failure, else success.                      */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              unit(I)     - device for which this is for                  */
end_comment

begin_comment
comment|/*              type(I)     - type of lookup these parameters are for.      */
end_comment

begin_comment
comment|/*              name(I)     - table name to use when searching              */
end_comment

begin_comment
comment|/*              funcptr(IO) - pointer to pointer for storing IP address     */
end_comment

begin_comment
comment|/*                            searching function.                           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Search for the "table" number passed in amongst those configured for     */
end_comment

begin_comment
comment|/* that particular type.  If the type is recognised then the function to    */
end_comment

begin_comment
comment|/* call to do the IP address search will be changed, regardless of whether  */
end_comment

begin_comment
comment|/* or not the "table" number exists.                                        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
modifier|*
name|ipf_lookup_res_name
parameter_list|(
name|softc
parameter_list|,
name|unit
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|funcptr
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|u_int
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|lookupfunc_t
modifier|*
name|funcptr
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|void
modifier|*
name|ptr
init|=
name|NULL
decl_stmt|;
name|int
name|i
decl_stmt|;
name|READ_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
block|{
if|if
condition|(
name|type
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|ptr
operator|=
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_select_add_ref
operator|)
operator|(
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|,
name|unit
operator|,
name|name
operator|)
expr_stmt|;
if|if
condition|(
name|ptr
operator|!=
name|NULL
operator|&&
name|funcptr
operator|!=
name|NULL
condition|)
block|{
operator|*
name|funcptr
operator|=
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_addr_find
expr_stmt|;
block|}
break|break;
block|}
block|}
if|if
condition|(
name|i
operator|==
name|MAX_BACKENDS
condition|)
block|{
name|ptr
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|funcptr
operator|!=
name|NULL
condition|)
operator|*
name|funcptr
operator|=
name|NULL
expr_stmt|;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_find_htable                                      */
end_comment

begin_comment
comment|/* Returns:     void * - NULL = failure, else success.                      */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              unit(I)     - device for which this is for                  */
end_comment

begin_comment
comment|/*              name(I)     - table name to use when searching              */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* To support the group-map feature, where a hash table maps address        */
end_comment

begin_comment
comment|/* networks to rule group numbers, we need to expose a function that uses   */
end_comment

begin_comment
comment|/* only the hash table backend.                                             */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
modifier|*
name|ipf_lookup_find_htable
parameter_list|(
name|softc
parameter_list|,
name|unit
parameter_list|,
name|name
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|void
modifier|*
name|tab
init|=
name|NULL
decl_stmt|;
name|int
name|i
decl_stmt|;
name|READ_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
if|if
condition|(
name|IPLT_HASH
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|tab
operator|=
name|ipf_htable_find
argument_list|(
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
argument_list|,
name|unit
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
return|return
name|tab
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_lookup_sync                                             */
end_comment

begin_comment
comment|/* Returns:     void                                                        */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is the interface that the machine dependent sync functions */
end_comment

begin_comment
comment|/* call when a network interface name change occurs. It then calls the sync */
end_comment

begin_comment
comment|/* functions of the lookup implementations - if they have one.              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|ipf_lookup_sync
parameter_list|(
name|softc
parameter_list|,
name|ifp
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|ifp
decl_stmt|;
block|{
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|int
name|i
decl_stmt|;
name|READ_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
if|if
condition|(
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_sync
operator|!=
name|NULL
condition|)
operator|(
operator|*
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_sync
operator|)
operator|(
name|softc
operator|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
operator|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function
name|void
name|ipf_lookup_dump
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
name|ipf_lookup_softc_t
modifier|*
name|softl
init|=
name|softc
operator|->
name|ipf_lookup_soft
decl_stmt|;
name|ipf_lookup_t
modifier|*
modifier|*
name|l
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
if|if
condition|(
name|IPLT_POOL
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|ipf_pool_dump
argument_list|(
name|softc
argument_list|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
argument_list|)
expr_stmt|;
break|break;
block|}
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|l
operator|=
name|backends
init|;
name|i
operator|<
name|MAX_BACKENDS
condition|;
name|i
operator|++
operator|,
name|l
operator|++
control|)
if|if
condition|(
name|IPLT_HASH
operator|==
operator|(
operator|*
name|l
operator|)
operator|->
name|ipfl_type
condition|)
block|{
name|ipf_htable_dump
argument_list|(
name|softc
argument_list|,
name|softl
operator|->
name|ipf_back
index|[
name|i
index|]
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

