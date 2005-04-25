begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2002-2003 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
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
file|<string.h>
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

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__osf__
end_ifdef

begin_include
include|#
directive|include
file|<net/radix.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"radix_ipf_local.h"
end_include

begin_define
define|#
directive|define
name|_RADIX_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

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
file|"netinet/ip_lookup.h"
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
literal|"@(#)Id: ip_lookup.c,v 2.35.2.5 2004/07/06 11:16:25 darrenr Exp"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LOOKUP
end_ifdef

begin_decl_stmt
name|int
name|ip_lookup_inited
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|iplookup_addnode
name|__P
argument_list|(
operator|(
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|iplookup_delnode
name|__P
argument_list|(
operator|(
name|caddr_t
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|iplookup_addtable
name|__P
argument_list|(
operator|(
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|iplookup_deltable
name|__P
argument_list|(
operator|(
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|iplookup_stats
name|__P
argument_list|(
operator|(
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|iplookup_flush
name|__P
argument_list|(
operator|(
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    iplookup_init                                               */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  Nil                                                         */
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
name|ip_lookup_init
parameter_list|()
block|{
if|if
condition|(
name|ip_pool_init
argument_list|()
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
name|RWLOCK_INIT
argument_list|(
operator|&
name|ip_poolrw
argument_list|,
literal|"ip pool rwlock"
argument_list|)
expr_stmt|;
name|ip_lookup_inited
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
comment|/* Function:    iplookup_unload                                             */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  Nil                                                         */
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
comment|/* ip_lookup_init() can be called again, safely.                            */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ip_lookup_unload
parameter_list|()
block|{
name|ip_pool_fini
argument_list|()
expr_stmt|;
name|fr_htable_unload
argument_list|()
expr_stmt|;
if|if
condition|(
name|ip_lookup_inited
operator|==
literal|1
condition|)
block|{
name|RW_DESTROY
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
name|ip_lookup_inited
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    iplookup_ioctl                                              */
end_comment

begin_comment
comment|/* Returns:     int      - 0 = success, else error                          */
end_comment

begin_comment
comment|/* Parameters:  data(IO) - pointer to ioctl data to be copied to/from user  */
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
name|ip_lookup_ioctl
parameter_list|(
name|data
parameter_list|,
name|cmd
parameter_list|,
name|mode
parameter_list|)
name|caddr_t
name|data
decl_stmt|;
name|ioctlcmd_t
name|cmd
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
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
name|MENTAT
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_SPL
argument_list|)
name|int
name|s
decl_stmt|;
endif|#
directive|endif
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
name|ip_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|iplookup_addnode
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ip_poolrw
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
name|ip_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|iplookup_delnode
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPADDTABLE
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|iplookup_addtable
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPDELTABLE
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|iplookup_deltable
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ip_poolrw
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
name|ip_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|iplookup_stats
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCLOOKUPFLUSH
case|:
name|WRITE_ENTER
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
name|err
operator|=
name|iplookup_flush
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
break|break;
default|default :
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
comment|/* Function:    iplookup_addnode                                            */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  data(I) - pointer to data from ioctl call                   */
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
name|iplookup_addnode
parameter_list|(
name|data
parameter_list|)
name|caddr_t
name|data
decl_stmt|;
block|{
name|ip_pool_node_t
name|node
decl_stmt|,
modifier|*
name|m
decl_stmt|;
name|iplookupop_t
name|op
decl_stmt|;
name|iphtable_t
modifier|*
name|iph
decl_stmt|;
name|iphtent_t
name|hte
decl_stmt|;
name|ip_pool_t
modifier|*
name|p
decl_stmt|;
name|int
name|err
decl_stmt|;
name|err
operator|=
literal|0
expr_stmt|;
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
switch|switch
condition|(
name|op
operator|.
name|iplo_type
condition|)
block|{
case|case
name|IPLT_POOL
case|:
if|if
condition|(
name|op
operator|.
name|iplo_size
operator|!=
sizeof|sizeof
argument_list|(
name|node
argument_list|)
condition|)
return|return
name|EINVAL
return|;
name|err
operator|=
name|COPYIN
argument_list|(
name|op
operator|.
name|iplo_struct
argument_list|,
operator|&
name|node
argument_list|,
sizeof|sizeof
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
name|EFAULT
return|;
name|p
operator|=
name|ip_pool_find
argument_list|(
name|op
operator|.
name|iplo_unit
argument_list|,
name|op
operator|.
name|iplo_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
return|return
name|ESRCH
return|;
comment|/* 		 * add an entry to a pool - return an error if it already 		 * exists remove an entry from a pool - if it exists 		 * - in both cases, the pool *must* exist! 		 */
name|m
operator|=
name|ip_pool_findeq
argument_list|(
name|p
argument_list|,
operator|&
name|node
operator|.
name|ipn_addr
argument_list|,
operator|&
name|node
operator|.
name|ipn_mask
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
return|return
name|EEXIST
return|;
name|err
operator|=
name|ip_pool_insert
argument_list|(
name|p
argument_list|,
operator|&
name|node
operator|.
name|ipn_addr
operator|.
name|adf_addr
argument_list|,
operator|&
name|node
operator|.
name|ipn_mask
operator|.
name|adf_addr
argument_list|,
name|node
operator|.
name|ipn_info
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLT_HASH
case|:
if|if
condition|(
name|op
operator|.
name|iplo_size
operator|!=
sizeof|sizeof
argument_list|(
name|hte
argument_list|)
condition|)
return|return
name|EINVAL
return|;
name|err
operator|=
name|COPYIN
argument_list|(
name|op
operator|.
name|iplo_struct
argument_list|,
operator|&
name|hte
argument_list|,
sizeof|sizeof
argument_list|(
name|hte
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
name|EFAULT
return|;
name|iph
operator|=
name|fr_findhtable
argument_list|(
name|op
operator|.
name|iplo_unit
argument_list|,
name|op
operator|.
name|iplo_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|iph
operator|==
name|NULL
condition|)
return|return
name|ESRCH
return|;
name|err
operator|=
name|fr_addhtent
argument_list|(
name|iph
argument_list|,
operator|&
name|hte
argument_list|)
expr_stmt|;
break|break;
default|default :
name|err
operator|=
name|EINVAL
expr_stmt|;
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
comment|/* Function:    iplookup_delnode                                            */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  data(I) - pointer to data from ioctl call                   */
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
name|iplookup_delnode
parameter_list|(
name|data
parameter_list|)
name|caddr_t
name|data
decl_stmt|;
block|{
name|ip_pool_node_t
name|node
decl_stmt|,
modifier|*
name|m
decl_stmt|;
name|iplookupop_t
name|op
decl_stmt|;
name|iphtable_t
modifier|*
name|iph
decl_stmt|;
name|iphtent_t
name|hte
decl_stmt|;
name|ip_pool_t
modifier|*
name|p
decl_stmt|;
name|int
name|err
decl_stmt|;
name|err
operator|=
literal|0
expr_stmt|;
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
switch|switch
condition|(
name|op
operator|.
name|iplo_type
condition|)
block|{
case|case
name|IPLT_POOL
case|:
if|if
condition|(
name|op
operator|.
name|iplo_size
operator|!=
sizeof|sizeof
argument_list|(
name|node
argument_list|)
condition|)
return|return
name|EINVAL
return|;
name|err
operator|=
name|COPYIN
argument_list|(
name|op
operator|.
name|iplo_struct
argument_list|,
operator|&
name|node
argument_list|,
sizeof|sizeof
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
name|EFAULT
return|;
name|p
operator|=
name|ip_pool_find
argument_list|(
name|op
operator|.
name|iplo_unit
argument_list|,
name|op
operator|.
name|iplo_name
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p
condition|)
return|return
name|ESRCH
return|;
name|m
operator|=
name|ip_pool_findeq
argument_list|(
name|p
argument_list|,
operator|&
name|node
operator|.
name|ipn_addr
argument_list|,
operator|&
name|node
operator|.
name|ipn_mask
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
return|return
name|ENOENT
return|;
name|err
operator|=
name|ip_pool_remove
argument_list|(
name|p
argument_list|,
name|m
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLT_HASH
case|:
if|if
condition|(
name|op
operator|.
name|iplo_size
operator|!=
sizeof|sizeof
argument_list|(
name|hte
argument_list|)
condition|)
return|return
name|EINVAL
return|;
name|err
operator|=
name|COPYIN
argument_list|(
name|op
operator|.
name|iplo_struct
argument_list|,
operator|&
name|hte
argument_list|,
sizeof|sizeof
argument_list|(
name|hte
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
name|EFAULT
return|;
name|iph
operator|=
name|fr_findhtable
argument_list|(
name|op
operator|.
name|iplo_unit
argument_list|,
name|op
operator|.
name|iplo_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|iph
operator|==
name|NULL
condition|)
return|return
name|ESRCH
return|;
name|err
operator|=
name|fr_delhtent
argument_list|(
name|iph
argument_list|,
operator|&
name|hte
argument_list|)
expr_stmt|;
break|break;
default|default :
name|err
operator|=
name|EINVAL
expr_stmt|;
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
comment|/* Function:    iplookup_addtable                                           */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  data(I) - pointer to data from ioctl call                   */
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
name|iplookup_addtable
parameter_list|(
name|data
parameter_list|)
name|caddr_t
name|data
decl_stmt|;
block|{
name|iplookupop_t
name|op
decl_stmt|;
name|int
name|err
decl_stmt|;
name|err
operator|=
literal|0
expr_stmt|;
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
switch|switch
condition|(
name|op
operator|.
name|iplo_type
condition|)
block|{
case|case
name|IPLT_POOL
case|:
if|if
condition|(
name|ip_pool_find
argument_list|(
name|op
operator|.
name|iplo_unit
argument_list|,
name|op
operator|.
name|iplo_name
argument_list|)
operator|!=
name|NULL
condition|)
name|err
operator|=
name|EEXIST
expr_stmt|;
else|else
name|err
operator|=
name|ip_pool_create
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLT_HASH
case|:
if|if
condition|(
name|fr_findhtable
argument_list|(
name|op
operator|.
name|iplo_unit
argument_list|,
name|op
operator|.
name|iplo_name
argument_list|)
operator|!=
name|NULL
condition|)
name|err
operator|=
name|EEXIST
expr_stmt|;
else|else
name|err
operator|=
name|fr_newhtable
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
break|break;
default|default :
name|err
operator|=
name|EINVAL
expr_stmt|;
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
comment|/* Function:    iplookup_deltable                                           */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  data(I) - pointer to data from ioctl call                   */
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
name|iplookup_deltable
parameter_list|(
name|data
parameter_list|)
name|caddr_t
name|data
decl_stmt|;
block|{
name|iplookupop_t
name|op
decl_stmt|;
name|int
name|err
decl_stmt|;
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
if|if
condition|(
name|op
operator|.
name|iplo_arg
operator|&
name|IPLT_ANON
condition|)
name|op
operator|.
name|iplo_arg
operator|&=
name|IPLT_ANON
expr_stmt|;
comment|/* 	 * create a new pool - fail if one already exists with 	 * the same # 	 */
switch|switch
condition|(
name|op
operator|.
name|iplo_type
condition|)
block|{
case|case
name|IPLT_POOL
case|:
name|err
operator|=
name|ip_pool_destroy
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLT_HASH
case|:
name|err
operator|=
name|fr_removehtable
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
break|break;
default|default :
name|err
operator|=
name|EINVAL
expr_stmt|;
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
comment|/* Function:    iplookup_stats                                              */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  data(I) - pointer to data from ioctl call                   */
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
name|iplookup_stats
parameter_list|(
name|data
parameter_list|)
name|caddr_t
name|data
decl_stmt|;
block|{
name|iplookupop_t
name|op
decl_stmt|;
name|int
name|err
decl_stmt|;
name|err
operator|=
literal|0
expr_stmt|;
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
switch|switch
condition|(
name|op
operator|.
name|iplo_type
condition|)
block|{
case|case
name|IPLT_POOL
case|:
name|err
operator|=
name|ip_pool_statistics
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLT_HASH
case|:
name|err
operator|=
name|fr_gethtablestat
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
break|break;
default|default :
name|err
operator|=
name|EINVAL
expr_stmt|;
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
comment|/* Function:    iplookup_flush                                              */
end_comment

begin_comment
comment|/* Returns:     int     - 0 = success, else error                           */
end_comment

begin_comment
comment|/* Parameters:  data(I) - pointer to data from ioctl call                   */
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
name|iplookup_flush
parameter_list|(
name|data
parameter_list|)
name|caddr_t
name|data
decl_stmt|;
block|{
name|int
name|err
decl_stmt|,
name|unit
decl_stmt|,
name|num
decl_stmt|,
name|type
decl_stmt|;
name|iplookupflush_t
name|flush
decl_stmt|;
name|err
operator|=
literal|0
expr_stmt|;
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
return|return
name|EINVAL
return|;
name|type
operator|=
name|flush
operator|.
name|iplf_type
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
name|num
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|IPLT_POOL
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
operator|=
name|ip_pool_flush
argument_list|(
operator|&
name|flush
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|type
operator|==
name|IPLT_HASH
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
name|fr_flushhtable
argument_list|(
operator|&
name|flush
argument_list|)
expr_stmt|;
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
name|COPYOUT
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
block|}
return|return
name|err
return|;
block|}
end_function

begin_function
name|void
name|ip_lookup_deref
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|)
name|int
name|type
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|{
if|if
condition|(
name|ptr
operator|==
name|NULL
condition|)
return|return;
name|WRITE_ENTER
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|IPLT_POOL
case|:
name|ip_pool_deref
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLT_HASH
case|:
name|fr_derefhtable
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
break|break;
block|}
name|RWLOCK_EXIT
argument_list|(
operator|&
name|ip_poolrw
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IPFILTER_LOOKUP */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|ip_lookup_ioctl
parameter_list|(
name|data
parameter_list|,
name|cmd
parameter_list|,
name|mode
parameter_list|)
name|caddr_t
name|data
decl_stmt|;
name|ioctlcmd_t
name|cmd
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|{
return|return
name|EIO
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPFILTER_LOOKUP */
end_comment

end_unit

