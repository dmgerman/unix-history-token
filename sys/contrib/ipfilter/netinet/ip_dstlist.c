begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
file|<sys/file.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__KERNEL__
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
file|<stdlib.h>
end_include

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

begin_else
else|#
directive|else
end_else

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
name|NetBSD
argument_list|)
operator|&&
operator|(
name|__NetBSD_Version__
operator|>=
literal|104000000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/proc.h>
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
file|<sys/time.h>
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
operator|&&
operator|(
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
operator|)
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

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
file|<sys/malloc.h>
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
file|"netinet/ip_nat.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_lookup.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_dstlist.h"
end_include

begin_comment
comment|/* END OF INCLUDES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SYS_MD5_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"md5.h"
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
literal|"@(#)$Id: ip_dstlist.c,v 1.13.2.12 2012/07/20 08:40:19 darren_r Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|ipf_dstl_softc_s
block|{
name|ippool_dst_t
modifier|*
name|dstlist
index|[
name|LOOKUP_POOL_SZ
index|]
decl_stmt|;
name|ippool_dst_t
modifier|*
modifier|*
name|tails
index|[
name|LOOKUP_POOL_SZ
index|]
decl_stmt|;
name|ipf_dstl_stat_t
name|stats
decl_stmt|;
block|}
name|ipf_dstl_softc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|void
modifier|*
name|ipf_dstlist_soft_create
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_dstlist_soft_destroy
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
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
name|ipf_dstlist_soft_init
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_dstlist_soft_fini
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
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
name|ipf_dstlist_addr_find
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
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|size_t
name|ipf_dstlist_flush
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|iplookupflush_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_dstlist_iter_deref
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
name|ipf_dstlist_iter_next
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|ipftoken_t
operator|*
operator|,
name|ipflookupiter_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_dstlist_node_add
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|iplookupop_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_dstlist_node_del
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|iplookupop_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_dstlist_stats_get
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|iplookupop_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_dstlist_table_add
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|iplookupop_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_dstlist_table_del
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|iplookupop_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_dstlist_table_deref
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
modifier|*
name|ipf_dstlist_table_find
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_dstlist_table_free
name|__P
argument_list|(
operator|(
name|ipf_dstl_softc_t
operator|*
operator|,
name|ippool_dst_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_dstlist_table_remove
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_dstl_softc_t
operator|*
operator|,
name|ippool_dst_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_dstlist_table_clearnodes
name|__P
argument_list|(
operator|(
name|ipf_dstl_softc_t
operator|*
operator|,
name|ippool_dst_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ipf_dstnode_t
modifier|*
name|ipf_dstlist_select
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ippool_dst_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
modifier|*
name|ipf_dstlist_select_ref
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_dstlist_node_free
name|__P
argument_list|(
operator|(
name|ipf_dstl_softc_t
operator|*
operator|,
name|ippool_dst_t
operator|*
operator|,
name|ipf_dstnode_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ipf_dstlist_node_deref
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|ipf_dstnode_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_dstlist_expire
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ipf_dstlist_sync
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ipf_lookup_t
name|ipf_dstlist_backend
init|=
block|{
name|IPLT_DSTLIST
block|,
name|ipf_dstlist_soft_create
block|,
name|ipf_dstlist_soft_destroy
block|,
name|ipf_dstlist_soft_init
block|,
name|ipf_dstlist_soft_fini
block|,
name|ipf_dstlist_addr_find
block|,
name|ipf_dstlist_flush
block|,
name|ipf_dstlist_iter_deref
block|,
name|ipf_dstlist_iter_next
block|,
name|ipf_dstlist_node_add
block|,
name|ipf_dstlist_node_del
block|,
name|ipf_dstlist_stats_get
block|,
name|ipf_dstlist_table_add
block|,
name|ipf_dstlist_table_del
block|,
name|ipf_dstlist_table_deref
block|,
name|ipf_dstlist_table_find
block|,
name|ipf_dstlist_select_ref
block|,
name|ipf_dstlist_select_node
block|,
name|ipf_dstlist_expire
block|,
name|ipf_dstlist_sync
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_soft_create                                     */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Allocating a chunk of memory filled with 0's is enough for the current   */
end_comment

begin_comment
comment|/* soft context used with destination lists.                                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|ipf_dstlist_soft_create
parameter_list|(
name|softc
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
block|{
name|ipf_dstl_softc_t
modifier|*
name|softd
decl_stmt|;
name|int
name|i
decl_stmt|;
name|KMALLOC
argument_list|(
name|softd
argument_list|,
name|ipf_dstl_softc_t
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|softd
operator|==
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120028
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|softd
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|softd
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|IPL_LOGMAX
condition|;
name|i
operator|++
control|)
name|softd
operator|->
name|tails
index|[
name|i
index|]
operator|=
operator|&
name|softd
operator|->
name|dstlist
index|[
name|i
index|]
expr_stmt|;
return|return
name|softd
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_soft_destroy                                    */
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
comment|/* For destination lists, the only thing we have to do when destroying the  */
end_comment

begin_comment
comment|/* soft context is free it!                                                 */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_dstlist_soft_destroy
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
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|KFREE
argument_list|(
name|softd
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_soft_init                                       */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
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
comment|/* There is currently no soft context for destination list management.      */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_soft_init
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
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_soft_fini                                       */
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
comment|/* There is currently no soft context for destination list management.      */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_dstlist_soft_fini
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
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
operator|-
literal|1
init|;
name|i
operator|<=
name|IPL_LOGMAX
condition|;
name|i
operator|++
control|)
block|{
while|while
condition|(
name|softd
operator|->
name|dstlist
index|[
name|i
operator|+
literal|1
index|]
operator|!=
name|NULL
condition|)
block|{
name|ipf_dstlist_table_remove
argument_list|(
name|softc
argument_list|,
name|softd
argument_list|,
name|softd
operator|->
name|dstlist
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|ASSERT
argument_list|(
name|softd
operator|->
name|stats
operator|.
name|ipls_numderefnodes
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_addr_find                                       */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg1(I)  - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              arg2(I)  - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              arg3(I)  - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              arg4(I)  - pointer to local context to use                  */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* There is currently no such thing as searching a destination list for an  */
end_comment

begin_comment
comment|/* address so this function becomes a no-op. Its presence is required as    */
end_comment

begin_comment
comment|/* ipf_lookup_res_name() stores the "addr_find" function pointer in the     */
end_comment

begin_comment
comment|/* pointer passed in to it as funcptr, although it could be a generic null- */
end_comment

begin_comment
comment|/* op function rather than a specific one.                                  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_addr_find
parameter_list|(
name|softc
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg1
decl_stmt|,
decl|*
name|arg3
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|arg2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|arg4
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|-
literal|1
return|;
block|}
end_block

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_flush                                           */
end_comment

begin_comment
comment|/* Returns:     int      - number of objects deleted                        */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              fop(I)   - pointer to lookup flush operation data           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Flush all of the destination tables that match the data passed in with   */
end_comment

begin_comment
comment|/* the iplookupflush_t. There are two ways to match objects: the device for */
end_comment

begin_comment
comment|/* which they are to be used with and their name.                           */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|size_t
name|ipf_dstlist_flush
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|fop
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|iplookupflush_t
modifier|*
name|fop
decl_stmt|;
block|{
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|ippool_dst_t
modifier|*
name|node
decl_stmt|,
modifier|*
name|next
decl_stmt|;
name|int
name|n
decl_stmt|,
name|i
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
operator|,
name|i
operator|=
operator|-
literal|1
init|;
name|i
operator|<=
name|IPL_LOGMAX
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|fop
operator|->
name|iplf_unit
operator|!=
name|IPLT_ALL
operator|&&
name|fop
operator|->
name|iplf_unit
operator|!=
name|i
condition|)
continue|continue;
for|for
control|(
name|node
operator|=
name|softd
operator|->
name|dstlist
index|[
name|i
operator|+
literal|1
index|]
init|;
name|node
operator|!=
name|NULL
condition|;
name|node
operator|=
name|next
control|)
block|{
name|next
operator|=
name|node
operator|->
name|ipld_next
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|fop
operator|->
name|iplf_name
operator|!=
literal|'\0'
operator|)
operator|&&
name|strncmp
argument_list|(
name|fop
operator|->
name|iplf_name
argument_list|,
name|node
operator|->
name|ipld_name
argument_list|,
name|FR_GROUPLEN
argument_list|)
condition|)
continue|continue;
name|ipf_dstlist_table_remove
argument_list|(
name|softc
argument_list|,
name|softd
argument_list|,
name|node
argument_list|)
expr_stmt|;
name|n
operator|++
expr_stmt|;
block|}
block|}
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_iter_deref                                      */
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
comment|/*              otype(I) - type of data structure to iterate through        */
end_comment

begin_comment
comment|/*              unit(I)  - device we are working with                       */
end_comment

begin_comment
comment|/*              data(I)  - address of object in kernel space                */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is called when the iteration token is being free'd and is  */
end_comment

begin_comment
comment|/* responsible for dropping the reference count of the structure it points  */
end_comment

begin_comment
comment|/* to.                                                                      */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_iter_deref
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|otype
parameter_list|,
name|unit
parameter_list|,
name|data
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|int
name|otype
decl_stmt|,
name|unit
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|{
if|if
condition|(
name|data
operator|==
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120001
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
if|if
condition|(
name|unit
operator|<
operator|-
literal|1
operator|||
name|unit
operator|>
name|IPL_LOGMAX
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120002
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
switch|switch
condition|(
name|otype
condition|)
block|{
case|case
name|IPFLOOKUPITER_LIST
case|:
name|ipf_dstlist_table_deref
argument_list|(
name|softc
argument_list|,
name|arg
argument_list|,
operator|(
name|ippool_dst_t
operator|*
operator|)
name|data
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPFLOOKUPITER_NODE
case|:
name|ipf_dstlist_node_deref
argument_list|(
name|arg
argument_list|,
operator|(
name|ipf_dstnode_t
operator|*
operator|)
name|data
argument_list|)
expr_stmt|;
break|break;
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
comment|/* Function:    ipf_dstlist_iter_next                                       */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              op(I)    - pointer to lookup operation data                 */
end_comment

begin_comment
comment|/*              uid(I)   - uid of process doing the ioctl                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is responsible for either selecting the next destination   */
end_comment

begin_comment
comment|/* list or node on a destination list to be returned as a user process      */
end_comment

begin_comment
comment|/* iterates through the list of destination lists or nodes.                 */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_iter_next
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|token
parameter_list|,
name|iter
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|ipftoken_t
modifier|*
name|token
decl_stmt|;
name|ipflookupiter_t
modifier|*
name|iter
decl_stmt|;
block|{
name|ipf_dstnode_t
name|zn
decl_stmt|,
modifier|*
name|nextnode
init|=
name|NULL
decl_stmt|,
modifier|*
name|node
init|=
name|NULL
decl_stmt|;
name|ippool_dst_t
name|zero
decl_stmt|,
modifier|*
name|next
init|=
name|NULL
decl_stmt|,
modifier|*
name|dsttab
init|=
name|NULL
decl_stmt|;
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
name|void
modifier|*
name|hint
decl_stmt|;
switch|switch
condition|(
name|iter
operator|->
name|ili_otype
condition|)
block|{
case|case
name|IPFLOOKUPITER_LIST
case|:
name|dsttab
operator|=
name|token
operator|->
name|ipt_data
expr_stmt|;
if|if
condition|(
name|dsttab
operator|==
name|NULL
condition|)
block|{
name|next
operator|=
name|softd
operator|->
name|dstlist
index|[
operator|(
name|int
operator|)
name|iter
operator|->
name|ili_unit
operator|+
literal|1
index|]
expr_stmt|;
block|}
else|else
block|{
name|next
operator|=
name|dsttab
operator|->
name|ipld_next
expr_stmt|;
block|}
if|if
condition|(
name|next
operator|!=
name|NULL
condition|)
block|{
name|ATOMIC_INC32
argument_list|(
name|next
operator|->
name|ipld_ref
argument_list|)
expr_stmt|;
name|token
operator|->
name|ipt_data
operator|=
name|next
expr_stmt|;
name|hint
operator|=
name|next
operator|->
name|ipld_next
expr_stmt|;
block|}
else|else
block|{
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
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
name|hint
operator|=
name|NULL
expr_stmt|;
block|}
break|break;
case|case
name|IPFLOOKUPITER_NODE
case|:
name|node
operator|=
name|token
operator|->
name|ipt_data
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|NULL
condition|)
block|{
name|dsttab
operator|=
name|ipf_dstlist_table_find
argument_list|(
name|arg
argument_list|,
name|iter
operator|->
name|ili_unit
argument_list|,
name|iter
operator|->
name|ili_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|dsttab
operator|==
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120004
argument_list|)
expr_stmt|;
name|err
operator|=
name|ESRCH
expr_stmt|;
name|nextnode
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|dsttab
operator|->
name|ipld_dests
operator|==
name|NULL
condition|)
name|nextnode
operator|=
name|NULL
expr_stmt|;
else|else
name|nextnode
operator|=
operator|*
name|dsttab
operator|->
name|ipld_dests
expr_stmt|;
name|dsttab
operator|=
name|NULL
expr_stmt|;
block|}
block|}
else|else
block|{
name|nextnode
operator|=
name|node
operator|->
name|ipfd_next
expr_stmt|;
block|}
if|if
condition|(
name|nextnode
operator|!=
name|NULL
condition|)
block|{
name|MUTEX_ENTER
argument_list|(
operator|&
name|nextnode
operator|->
name|ipfd_lock
argument_list|)
expr_stmt|;
name|nextnode
operator|->
name|ipfd_ref
operator|++
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|nextnode
operator|->
name|ipfd_lock
argument_list|)
expr_stmt|;
name|token
operator|->
name|ipt_data
operator|=
name|nextnode
expr_stmt|;
name|hint
operator|=
name|nextnode
operator|->
name|ipfd_next
expr_stmt|;
block|}
else|else
block|{
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|zn
argument_list|,
sizeof|sizeof
argument_list|(
name|zn
argument_list|)
argument_list|)
expr_stmt|;
name|nextnode
operator|=
operator|&
name|zn
expr_stmt|;
name|token
operator|->
name|ipt_data
operator|=
name|NULL
expr_stmt|;
name|hint
operator|=
name|NULL
expr_stmt|;
block|}
break|break;
default|default :
name|IPFERROR
argument_list|(
literal|120003
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
name|err
return|;
switch|switch
condition|(
name|iter
operator|->
name|ili_otype
condition|)
block|{
case|case
name|IPFLOOKUPITER_LIST
case|:
if|if
condition|(
name|dsttab
operator|!=
name|NULL
condition|)
name|ipf_dstlist_table_deref
argument_list|(
name|softc
argument_list|,
name|arg
argument_list|,
name|dsttab
argument_list|)
expr_stmt|;
name|err
operator|=
name|COPYOUT
argument_list|(
name|next
argument_list|,
name|iter
operator|->
name|ili_data
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
name|err
operator|!=
literal|0
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120005
argument_list|)
expr_stmt|;
name|err
operator|=
name|EFAULT
expr_stmt|;
block|}
break|break;
case|case
name|IPFLOOKUPITER_NODE
case|:
if|if
condition|(
name|node
operator|!=
name|NULL
condition|)
name|ipf_dstlist_node_deref
argument_list|(
name|arg
argument_list|,
name|node
argument_list|)
expr_stmt|;
name|err
operator|=
name|COPYOUT
argument_list|(
name|nextnode
argument_list|,
name|iter
operator|->
name|ili_data
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|nextnode
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
literal|120006
argument_list|)
expr_stmt|;
name|err
operator|=
name|EFAULT
expr_stmt|;
block|}
break|break;
block|}
if|if
condition|(
name|hint
operator|==
name|NULL
condition|)
name|ipf_token_mark_complete
argument_list|(
name|token
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
comment|/* Function:    ipf_dstlist_node_add                                        */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              op(I)    - pointer to lookup operation data                 */
end_comment

begin_comment
comment|/*              uid(I)   - uid of process doing the ioctl                   */
end_comment

begin_comment
comment|/* Locks:       WRITE(ipf_poolrw)                                           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Add a new node to a destination list. To do this, we only copy in the    */
end_comment

begin_comment
comment|/* frdest_t structure because that contains the only data required from the */
end_comment

begin_comment
comment|/* application to create a new node. The frdest_t doesn't contain the name  */
end_comment

begin_comment
comment|/* itself. When loading filter rules, fd_name is a 'pointer' to the name.   */
end_comment

begin_comment
comment|/* In this case, the 'pointer' does not work, instead it is the length of   */
end_comment

begin_comment
comment|/* the name and the name is immediately following the frdest_t structure.   */
end_comment

begin_comment
comment|/* fd_name must include the trailing \0, so it should be strlen(str) + 1.   */
end_comment

begin_comment
comment|/* For simple sanity checking, an upper bound on the size of fd_name is     */
end_comment

begin_comment
comment|/* imposed - 128.                                                          */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_node_add
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|op
parameter_list|,
name|uid
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|iplookupop_t
modifier|*
name|op
decl_stmt|;
name|int
name|uid
decl_stmt|;
block|{
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|ipf_dstnode_t
modifier|*
name|node
decl_stmt|,
modifier|*
modifier|*
name|nodes
decl_stmt|;
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
name|frdest_t
name|dest
decl_stmt|;
name|int
name|err
decl_stmt|;
if|if
condition|(
name|op
operator|->
name|iplo_size
operator|<
sizeof|sizeof
argument_list|(
name|frdest_t
argument_list|)
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120007
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|err
operator|=
name|COPYIN
argument_list|(
name|op
operator|->
name|iplo_struct
argument_list|,
operator|&
name|dest
argument_list|,
sizeof|sizeof
argument_list|(
name|dest
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
literal|120009
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
name|d
operator|=
name|ipf_dstlist_table_find
argument_list|(
name|arg
argument_list|,
name|op
operator|->
name|iplo_unit
argument_list|,
name|op
operator|->
name|iplo_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|==
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120010
argument_list|)
expr_stmt|;
return|return
name|ESRCH
return|;
block|}
switch|switch
condition|(
name|dest
operator|.
name|fd_addr
operator|.
name|adf_family
condition|)
block|{
case|case
name|AF_INET
case|:
case|case
name|AF_INET6
case|:
break|break;
default|default :
name|IPFERROR
argument_list|(
literal|120019
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
if|if
condition|(
name|dest
operator|.
name|fd_name
operator|<
operator|-
literal|1
operator|||
name|dest
operator|.
name|fd_name
operator|>
literal|128
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120018
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|KMALLOCS
argument_list|(
name|node
argument_list|,
name|ipf_dstnode_t
operator|*
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|node
argument_list|)
operator|+
name|dest
operator|.
name|fd_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|NULL
condition|)
block|{
name|softd
operator|->
name|stats
operator|.
name|ipls_nomem
operator|++
expr_stmt|;
name|IPFERROR
argument_list|(
literal|120008
argument_list|)
expr_stmt|;
return|return
name|ENOMEM
return|;
block|}
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|node
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|node
argument_list|)
operator|+
name|dest
operator|.
name|fd_name
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|dest
argument_list|,
operator|&
name|node
operator|->
name|ipfd_dest
argument_list|,
sizeof|sizeof
argument_list|(
name|dest
argument_list|)
argument_list|)
expr_stmt|;
name|node
operator|->
name|ipfd_size
operator|=
sizeof|sizeof
argument_list|(
operator|*
name|node
argument_list|)
operator|+
name|dest
operator|.
name|fd_name
expr_stmt|;
if|if
condition|(
name|dest
operator|.
name|fd_name
operator|>
literal|0
condition|)
block|{
comment|/* 		 * fd_name starts out as the length of the string to copy 		 * in (including \0) and ends up being the offset from 		 * fd_names (0). 		 */
name|err
operator|=
name|COPYIN
argument_list|(
operator|(
name|char
operator|*
operator|)
name|op
operator|->
name|iplo_struct
operator|+
sizeof|sizeof
argument_list|(
name|dest
argument_list|)
argument_list|,
name|node
operator|->
name|ipfd_names
argument_list|,
name|dest
operator|.
name|fd_name
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
literal|120017
argument_list|)
expr_stmt|;
name|KFREES
argument_list|(
name|node
argument_list|,
name|node
operator|->
name|ipfd_size
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_name
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_name
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|ipld_nodes
operator|==
name|d
operator|->
name|ipld_maxnodes
condition|)
block|{
name|KMALLOCS
argument_list|(
name|nodes
argument_list|,
name|ipf_dstnode_t
operator|*
operator|*
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|nodes
argument_list|)
operator|*
operator|(
name|d
operator|->
name|ipld_maxnodes
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|nodes
operator|==
name|NULL
condition|)
block|{
name|softd
operator|->
name|stats
operator|.
name|ipls_nomem
operator|++
expr_stmt|;
name|IPFERROR
argument_list|(
literal|120022
argument_list|)
expr_stmt|;
name|KFREES
argument_list|(
name|node
argument_list|,
name|node
operator|->
name|ipfd_size
argument_list|)
expr_stmt|;
return|return
name|ENOMEM
return|;
block|}
if|if
condition|(
name|d
operator|->
name|ipld_dests
operator|!=
name|NULL
condition|)
block|{
name|bcopy
argument_list|(
name|d
operator|->
name|ipld_dests
argument_list|,
name|nodes
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|nodes
argument_list|)
operator|*
name|d
operator|->
name|ipld_maxnodes
argument_list|)
expr_stmt|;
name|KFREES
argument_list|(
name|d
operator|->
name|ipld_dests
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|nodes
argument_list|)
operator|*
name|d
operator|->
name|ipld_nodes
argument_list|)
expr_stmt|;
name|nodes
index|[
literal|0
index|]
operator|->
name|ipfd_pnext
operator|=
name|nodes
expr_stmt|;
block|}
name|d
operator|->
name|ipld_dests
operator|=
name|nodes
expr_stmt|;
name|d
operator|->
name|ipld_maxnodes
operator|++
expr_stmt|;
block|}
name|d
operator|->
name|ipld_dests
index|[
name|d
operator|->
name|ipld_nodes
index|]
operator|=
name|node
expr_stmt|;
name|d
operator|->
name|ipld_nodes
operator|++
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ipld_nodes
operator|==
literal|1
condition|)
block|{
name|node
operator|->
name|ipfd_pnext
operator|=
name|d
operator|->
name|ipld_dests
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|ipld_nodes
operator|>
literal|1
condition|)
block|{
name|node
operator|->
name|ipfd_pnext
operator|=
operator|&
name|d
operator|->
name|ipld_dests
index|[
name|d
operator|->
name|ipld_nodes
operator|-
literal|2
index|]
operator|->
name|ipfd_next
expr_stmt|;
block|}
operator|*
name|node
operator|->
name|ipfd_pnext
operator|=
name|node
expr_stmt|;
name|MUTEX_INIT
argument_list|(
operator|&
name|node
operator|->
name|ipfd_lock
argument_list|,
literal|"ipf dst node lock"
argument_list|)
expr_stmt|;
name|node
operator|->
name|ipfd_uid
operator|=
name|uid
expr_stmt|;
name|node
operator|->
name|ipfd_ref
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_name
operator|==
literal|0
condition|)
operator|(
name|void
operator|)
name|ipf_resolvedest
argument_list|(
name|softc
argument_list|,
name|node
operator|->
name|ipfd_names
argument_list|,
operator|&
name|node
operator|->
name|ipfd_dest
argument_list|,
name|AF_INET
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|USE_INET6
if|if
condition|(
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_name
operator|==
literal|0
operator|&&
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_ptr
operator|==
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
condition|)
operator|(
name|void
operator|)
name|ipf_resolvedest
argument_list|(
name|softc
argument_list|,
name|node
operator|->
name|ipfd_names
argument_list|,
operator|&
name|node
operator|->
name|ipfd_dest
argument_list|,
name|AF_INET6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|softd
operator|->
name|stats
operator|.
name|ipls_numnodes
operator|++
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
comment|/* Function:    ipf_dstlist_node_deref                                      */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
end_comment

begin_comment
comment|/* Parameters:  arg(I)  - pointer to local context to use                   */
end_comment

begin_comment
comment|/*              node(I) - pointer to destionation node to free              */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Dereference the use count by one. If it drops to zero then we can assume */
end_comment

begin_comment
comment|/* that it has been removed from any lists/tables and is ripe for freeing.  */
end_comment

begin_comment
comment|/* The pointer to context is required for the purpose of maintaining        */
end_comment

begin_comment
comment|/* statistics.                                                              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_node_deref
parameter_list|(
name|arg
parameter_list|,
name|node
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
name|ipf_dstnode_t
modifier|*
name|node
decl_stmt|;
block|{
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|int
name|ref
decl_stmt|;
name|MUTEX_ENTER
argument_list|(
operator|&
name|node
operator|->
name|ipfd_lock
argument_list|)
expr_stmt|;
name|ref
operator|=
operator|--
name|node
operator|->
name|ipfd_ref
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|node
operator|->
name|ipfd_lock
argument_list|)
expr_stmt|;
if|if
condition|(
name|ref
operator|>
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|(
name|node
operator|->
name|ipfd_flags
operator|&
name|IPDST_DELETE
operator|)
operator|!=
literal|0
condition|)
name|softd
operator|->
name|stats
operator|.
name|ipls_numderefnodes
operator|--
expr_stmt|;
name|MUTEX_DESTROY
argument_list|(
operator|&
name|node
operator|->
name|ipfd_lock
argument_list|)
expr_stmt|;
name|KFREES
argument_list|(
name|node
argument_list|,
name|node
operator|->
name|ipfd_size
argument_list|)
expr_stmt|;
name|softd
operator|->
name|stats
operator|.
name|ipls_numnodes
operator|--
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
comment|/* Function:    ipf_dstlist_node_del                                        */
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
comment|/*              op(I)    - pointer to lookup operation data                 */
end_comment

begin_comment
comment|/*              uid(I)   - uid of process doing the ioctl                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Look for a matching destination node on the named table and free it if   */
end_comment

begin_comment
comment|/* found. Because the name embedded in the frdest_t is variable in length,  */
end_comment

begin_comment
comment|/* it is necessary to allocate some memory locally, to complete this op.    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_node_del
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|op
parameter_list|,
name|uid
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|iplookupop_t
modifier|*
name|op
decl_stmt|;
name|int
name|uid
decl_stmt|;
block|{
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|ipf_dstnode_t
modifier|*
name|node
decl_stmt|;
name|frdest_t
name|frd
decl_stmt|,
modifier|*
name|temp
decl_stmt|;
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|int
name|err
decl_stmt|;
name|d
operator|=
name|ipf_dstlist_table_find
argument_list|(
name|arg
argument_list|,
name|op
operator|->
name|iplo_unit
argument_list|,
name|op
operator|->
name|iplo_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|==
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120012
argument_list|)
expr_stmt|;
return|return
name|ESRCH
return|;
block|}
name|err
operator|=
name|COPYIN
argument_list|(
name|op
operator|->
name|iplo_struct
argument_list|,
operator|&
name|frd
argument_list|,
sizeof|sizeof
argument_list|(
name|frd
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
literal|120011
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
name|size
operator|=
sizeof|sizeof
argument_list|(
operator|*
name|temp
argument_list|)
operator|+
name|frd
operator|.
name|fd_name
expr_stmt|;
name|KMALLOCS
argument_list|(
name|temp
argument_list|,
name|frdest_t
operator|*
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|temp
operator|==
name|NULL
condition|)
block|{
name|softd
operator|->
name|stats
operator|.
name|ipls_nomem
operator|++
expr_stmt|;
name|IPFERROR
argument_list|(
literal|120026
argument_list|)
expr_stmt|;
return|return
name|ENOMEM
return|;
block|}
name|err
operator|=
name|COPYIN
argument_list|(
name|op
operator|->
name|iplo_struct
argument_list|,
name|temp
argument_list|,
name|size
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
literal|120027
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
name|MUTEX_ENTER
argument_list|(
operator|&
name|d
operator|->
name|ipld_lock
argument_list|)
expr_stmt|;
for|for
control|(
name|node
operator|=
operator|*
name|d
operator|->
name|ipld_dests
init|;
name|node
operator|!=
name|NULL
condition|;
name|node
operator|=
name|node
operator|->
name|ipfd_next
control|)
block|{
if|if
condition|(
operator|(
name|uid
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|node
operator|->
name|ipfd_uid
operator|!=
name|uid
operator|)
condition|)
continue|continue;
if|if
condition|(
name|node
operator|->
name|ipfd_size
operator|!=
name|size
condition|)
continue|continue;
if|if
condition|(
operator|!
name|bcmp
argument_list|(
operator|&
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_ip6
argument_list|,
operator|&
name|frd
operator|.
name|fd_ip6
argument_list|,
name|size
operator|-
name|offsetof
argument_list|(
name|frdest_t
argument_list|,
name|fd_ip6
argument_list|)
argument_list|)
condition|)
block|{
name|ipf_dstlist_node_free
argument_list|(
name|softd
argument_list|,
name|d
argument_list|,
name|node
argument_list|)
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|d
operator|->
name|ipld_lock
argument_list|)
expr_stmt|;
name|KFREES
argument_list|(
name|temp
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
name|MUTEX_EXIT
argument_list|(
operator|&
name|d
operator|->
name|ipld_lock
argument_list|)
expr_stmt|;
name|KFREES
argument_list|(
name|temp
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
name|ESRCH
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_node_free                                       */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softd(I) - pointer to the destination list context          */
end_comment

begin_comment
comment|/*              d(I)     - pointer to destination list                      */
end_comment

begin_comment
comment|/*              node(I)  - pointer to node to free                          */
end_comment

begin_comment
comment|/* Locks:       MUTEX(ipld_lock) or WRITE(ipf_poolrw)                       */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Free the destination node by first removing it from any lists and then   */
end_comment

begin_comment
comment|/* checking if this was the last reference held to the object. While the    */
end_comment

begin_comment
comment|/* array of pointers to nodes is compacted, its size isn't reduced (by way  */
end_comment

begin_comment
comment|/* of allocating a new smaller one and copying) because the belief is that  */
end_comment

begin_comment
comment|/* it is likely the array will again reach that size.                       */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_dstlist_node_free
parameter_list|(
name|softd
parameter_list|,
name|d
parameter_list|,
name|node
parameter_list|)
name|ipf_dstl_softc_t
modifier|*
name|softd
decl_stmt|;
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
name|ipf_dstnode_t
modifier|*
name|node
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
comment|/* 	 * Compact the array of pointers to nodes. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|ipld_nodes
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|d
operator|->
name|ipld_dests
index|[
name|i
index|]
operator|==
name|node
condition|)
break|break;
if|if
condition|(
name|d
operator|->
name|ipld_nodes
operator|-
name|i
operator|>
literal|1
condition|)
block|{
name|bcopy
argument_list|(
operator|&
name|d
operator|->
name|ipld_dests
index|[
name|i
operator|+
literal|1
index|]
argument_list|,
operator|&
name|d
operator|->
name|ipld_dests
index|[
name|i
index|]
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|d
operator|->
name|ipld_dests
argument_list|)
operator|*
operator|(
name|d
operator|->
name|ipld_nodes
operator|-
name|i
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|ipld_nodes
operator|--
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|ipfd_pnext
operator|!=
name|NULL
condition|)
operator|*
name|node
operator|->
name|ipfd_pnext
operator|=
name|node
operator|->
name|ipfd_next
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|ipfd_next
operator|!=
name|NULL
condition|)
name|node
operator|->
name|ipfd_next
operator|->
name|ipfd_pnext
operator|=
name|node
operator|->
name|ipfd_pnext
expr_stmt|;
name|node
operator|->
name|ipfd_pnext
operator|=
name|NULL
expr_stmt|;
name|node
operator|->
name|ipfd_next
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|(
name|node
operator|->
name|ipfd_flags
operator|&
name|IPDST_DELETE
operator|)
operator|==
literal|0
condition|)
block|{
name|softd
operator|->
name|stats
operator|.
name|ipls_numderefnodes
operator|++
expr_stmt|;
name|node
operator|->
name|ipfd_flags
operator||=
name|IPDST_DELETE
expr_stmt|;
block|}
name|ipf_dstlist_node_deref
argument_list|(
name|softd
argument_list|,
name|node
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_stats_get                                       */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              op(I)    - pointer to lookup operation data                 */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Return the current statistics for destination lists. This may be for all */
end_comment

begin_comment
comment|/* of them or just information pertaining to a particular table.            */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_stats_get
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|op
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|iplookupop_t
modifier|*
name|op
decl_stmt|;
block|{
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|ipf_dstl_stat_t
name|stats
decl_stmt|;
name|int
name|unit
decl_stmt|,
name|i
decl_stmt|,
name|err
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|op
operator|->
name|iplo_size
operator|!=
sizeof|sizeof
argument_list|(
name|ipf_dstl_stat_t
argument_list|)
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120023
argument_list|)
expr_stmt|;
return|return
name|EINVAL
return|;
block|}
name|stats
operator|=
name|softd
operator|->
name|stats
expr_stmt|;
name|unit
operator|=
name|op
operator|->
name|iplo_unit
expr_stmt|;
if|if
condition|(
name|unit
operator|==
name|IPL_LOGALL
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|IPL_LOGMAX
condition|;
name|i
operator|++
control|)
name|stats
operator|.
name|ipls_list
index|[
name|i
index|]
operator|=
name|softd
operator|->
name|dstlist
index|[
name|i
index|]
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|unit
operator|>=
literal|0
operator|&&
name|unit
operator|<=
name|IPL_LOGMAX
condition|)
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
name|op
operator|->
name|iplo_name
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|ptr
operator|=
name|ipf_dstlist_table_find
argument_list|(
name|softd
argument_list|,
name|unit
argument_list|,
name|op
operator|->
name|iplo_name
argument_list|)
expr_stmt|;
else|else
name|ptr
operator|=
name|softd
operator|->
name|dstlist
index|[
name|unit
operator|+
literal|1
index|]
expr_stmt|;
name|stats
operator|.
name|ipls_list
index|[
name|unit
index|]
operator|=
name|ptr
expr_stmt|;
block|}
else|else
block|{
name|IPFERROR
argument_list|(
literal|120024
argument_list|)
expr_stmt|;
name|err
operator|=
name|EINVAL
expr_stmt|;
block|}
if|if
condition|(
name|err
operator|==
literal|0
condition|)
block|{
name|err
operator|=
name|COPYOUT
argument_list|(
operator|&
name|stats
argument_list|,
name|op
operator|->
name|iplo_struct
argument_list|,
sizeof|sizeof
argument_list|(
name|stats
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
literal|120025
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
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
comment|/* Function:    ipf_dstlist_table_add                                       */
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
comment|/*              op(I)    - pointer to lookup operation data                 */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Add a new destination table to the list of those available for the given */
end_comment

begin_comment
comment|/* device. Because we seldom operate on these objects (find/add/delete),    */
end_comment

begin_comment
comment|/* they are just kept in a simple linked list.                              */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_table_add
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|op
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|iplookupop_t
modifier|*
name|op
decl_stmt|;
block|{
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|ippool_dst_t
name|user
decl_stmt|,
modifier|*
name|d
decl_stmt|,
modifier|*
name|new
decl_stmt|;
name|int
name|unit
decl_stmt|,
name|err
decl_stmt|;
name|d
operator|=
name|ipf_dstlist_table_find
argument_list|(
name|arg
argument_list|,
name|op
operator|->
name|iplo_unit
argument_list|,
name|op
operator|->
name|iplo_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|!=
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120013
argument_list|)
expr_stmt|;
return|return
name|EEXIST
return|;
block|}
name|err
operator|=
name|COPYIN
argument_list|(
name|op
operator|->
name|iplo_struct
argument_list|,
operator|&
name|user
argument_list|,
sizeof|sizeof
argument_list|(
name|user
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
literal|120021
argument_list|)
expr_stmt|;
return|return
name|EFAULT
return|;
block|}
name|KMALLOC
argument_list|(
name|new
argument_list|,
name|ippool_dst_t
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|new
operator|==
name|NULL
condition|)
block|{
name|softd
operator|->
name|stats
operator|.
name|ipls_nomem
operator|++
expr_stmt|;
name|IPFERROR
argument_list|(
literal|120014
argument_list|)
expr_stmt|;
return|return
name|ENOMEM
return|;
block|}
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|new
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|new
argument_list|)
argument_list|)
expr_stmt|;
name|MUTEX_INIT
argument_list|(
operator|&
name|new
operator|->
name|ipld_lock
argument_list|,
literal|"ipf dst table lock"
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|new
operator|->
name|ipld_name
argument_list|,
name|op
operator|->
name|iplo_name
argument_list|,
name|FR_GROUPLEN
argument_list|)
expr_stmt|;
name|unit
operator|=
name|op
operator|->
name|iplo_unit
expr_stmt|;
name|new
operator|->
name|ipld_unit
operator|=
name|unit
expr_stmt|;
name|new
operator|->
name|ipld_policy
operator|=
name|user
operator|.
name|ipld_policy
expr_stmt|;
name|new
operator|->
name|ipld_seed
operator|=
name|ipf_random
argument_list|()
expr_stmt|;
name|new
operator|->
name|ipld_ref
operator|=
literal|1
expr_stmt|;
name|new
operator|->
name|ipld_pnext
operator|=
name|softd
operator|->
name|tails
index|[
name|unit
operator|+
literal|1
index|]
expr_stmt|;
operator|*
name|softd
operator|->
name|tails
index|[
name|unit
operator|+
literal|1
index|]
operator|=
name|new
expr_stmt|;
name|softd
operator|->
name|tails
index|[
name|unit
operator|+
literal|1
index|]
operator|=
operator|&
name|new
operator|->
name|ipld_next
expr_stmt|;
name|softd
operator|->
name|stats
operator|.
name|ipls_numlists
operator|++
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
comment|/* Function:    ipf_dstlist_table_del                                       */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              op(I)    - pointer to lookup operation data                 */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Find a named destinstion list table and delete it. If there are other    */
end_comment

begin_comment
comment|/* references to it, the caller isn't told.                                 */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_table_del
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|op
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|iplookupop_t
modifier|*
name|op
decl_stmt|;
block|{
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
name|d
operator|=
name|ipf_dstlist_table_find
argument_list|(
name|arg
argument_list|,
name|op
operator|->
name|iplo_unit
argument_list|,
name|op
operator|->
name|iplo_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|==
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120015
argument_list|)
expr_stmt|;
return|return
name|ESRCH
return|;
block|}
if|if
condition|(
name|d
operator|->
name|ipld_dests
operator|!=
name|NULL
condition|)
block|{
name|IPFERROR
argument_list|(
literal|120016
argument_list|)
expr_stmt|;
return|return
name|EBUSY
return|;
block|}
name|ipf_dstlist_table_remove
argument_list|(
name|softc
argument_list|,
name|arg
argument_list|,
name|d
argument_list|)
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
comment|/* Function:    ipf_dstlist_table_remove                                    */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              softd(I) - pointer to the destination list context          */
end_comment

begin_comment
comment|/*              d(I)     - pointer to destination list                      */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Remove a given destination list from existance. While the IPDST_DELETE   */
end_comment

begin_comment
comment|/* flag is set every time we call this function and the reference count is  */
end_comment

begin_comment
comment|/* non-zero, the "numdereflists" counter is always incremented because the  */
end_comment

begin_comment
comment|/* decision about whether it will be freed or not is not made here. This    */
end_comment

begin_comment
comment|/* means that the only action the code can take here is to treat it as if   */
end_comment

begin_comment
comment|/* it will become a detached.                                               */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_dstlist_table_remove
parameter_list|(
name|softc
parameter_list|,
name|softd
parameter_list|,
name|d
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|ipf_dstl_softc_t
modifier|*
name|softd
decl_stmt|;
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
block|{
if|if
condition|(
name|softd
operator|->
name|tails
index|[
name|d
operator|->
name|ipld_unit
operator|+
literal|1
index|]
operator|==
operator|&
name|d
operator|->
name|ipld_next
condition|)
name|softd
operator|->
name|tails
index|[
name|d
operator|->
name|ipld_unit
operator|+
literal|1
index|]
operator|=
name|d
operator|->
name|ipld_pnext
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ipld_pnext
operator|!=
name|NULL
condition|)
operator|*
name|d
operator|->
name|ipld_pnext
operator|=
name|d
operator|->
name|ipld_next
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ipld_next
operator|!=
name|NULL
condition|)
name|d
operator|->
name|ipld_next
operator|->
name|ipld_pnext
operator|=
name|d
operator|->
name|ipld_pnext
expr_stmt|;
name|d
operator|->
name|ipld_pnext
operator|=
name|NULL
expr_stmt|;
name|d
operator|->
name|ipld_next
operator|=
name|NULL
expr_stmt|;
name|ipf_dstlist_table_clearnodes
argument_list|(
name|softd
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|softd
operator|->
name|stats
operator|.
name|ipls_numdereflists
operator|++
expr_stmt|;
name|d
operator|->
name|ipld_flags
operator||=
name|IPDST_DELETE
expr_stmt|;
name|ipf_dstlist_table_deref
argument_list|(
name|softc
argument_list|,
name|softd
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_table_free                                      */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softd(I) - pointer to the destination list context          */
end_comment

begin_comment
comment|/*              d(I)   - pointer to destination list                        */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Free up a destination list data structure and any other memory that was  */
end_comment

begin_comment
comment|/* directly allocated as part of creating it. Individual destination list   */
end_comment

begin_comment
comment|/* nodes are not freed. It is assumed the caller will have already emptied  */
end_comment

begin_comment
comment|/* the destination list.                                                    */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_dstlist_table_free
parameter_list|(
name|softd
parameter_list|,
name|d
parameter_list|)
name|ipf_dstl_softc_t
modifier|*
name|softd
decl_stmt|;
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
block|{
name|MUTEX_DESTROY
argument_list|(
operator|&
name|d
operator|->
name|ipld_lock
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|d
operator|->
name|ipld_flags
operator|&
name|IPDST_DELETE
operator|)
operator|!=
literal|0
condition|)
name|softd
operator|->
name|stats
operator|.
name|ipls_numdereflists
operator|--
expr_stmt|;
name|softd
operator|->
name|stats
operator|.
name|ipls_numlists
operator|--
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ipld_dests
operator|!=
name|NULL
condition|)
block|{
name|KFREES
argument_list|(
name|d
operator|->
name|ipld_dests
argument_list|,
name|d
operator|->
name|ipld_maxnodes
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|d
operator|->
name|ipld_dests
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|KFREE
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_table_deref                                     */
end_comment

begin_comment
comment|/* Returns:     int - 0 = success, else error                               */
end_comment

begin_comment
comment|/* Parameters:  softc(I) - pointer to soft context main structure           */
end_comment

begin_comment
comment|/*              arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              op(I)    - pointer to lookup operation data                 */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Drops the reference count on a destination list table object and free's  */
end_comment

begin_comment
comment|/* it if 0 has been reached.                                                */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|int
name|ipf_dstlist_table_deref
parameter_list|(
name|softc
parameter_list|,
name|arg
parameter_list|,
name|table
parameter_list|)
name|ipf_main_softc_t
modifier|*
name|softc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|void
modifier|*
name|table
decl_stmt|;
block|{
name|ippool_dst_t
modifier|*
name|d
init|=
name|table
decl_stmt|;
name|d
operator|->
name|ipld_ref
operator|--
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ipld_ref
operator|>
literal|0
condition|)
return|return
name|d
operator|->
name|ipld_ref
return|;
name|ipf_dstlist_table_free
argument_list|(
name|arg
argument_list|,
name|d
argument_list|)
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
comment|/* Function:    ipf_dstlist_table_clearnodes                                */
end_comment

begin_comment
comment|/* Returns:     Nil                                                         */
end_comment

begin_comment
comment|/* Parameters:  softd(I) - pointer to the destination list context          */
end_comment

begin_comment
comment|/*              dst(I)   - pointer to destination list                      */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Free all of the destination nodes attached to the given table.           */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_dstlist_table_clearnodes
parameter_list|(
name|softd
parameter_list|,
name|dst
parameter_list|)
name|ipf_dstl_softc_t
modifier|*
name|softd
decl_stmt|;
name|ippool_dst_t
modifier|*
name|dst
decl_stmt|;
block|{
name|ipf_dstnode_t
modifier|*
name|node
decl_stmt|;
if|if
condition|(
name|dst
operator|->
name|ipld_dests
operator|==
name|NULL
condition|)
return|return;
while|while
condition|(
operator|(
name|node
operator|=
operator|*
name|dst
operator|->
name|ipld_dests
operator|)
operator|!=
name|NULL
condition|)
block|{
name|ipf_dstlist_node_free
argument_list|(
name|softd
argument_list|,
name|dst
argument_list|,
name|node
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_table_find                                      */
end_comment

begin_comment
comment|/* Returns:     int      - 0 = success, else error                          */
end_comment

begin_comment
comment|/* Parameters:  arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              unit(I)  - device we are working with                       */
end_comment

begin_comment
comment|/*              name(I)  - destination table name to find                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Return a pointer to a destination table that matches the unit+name that  */
end_comment

begin_comment
comment|/* is passed in.                                                            */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|ipf_dstlist_table_find
parameter_list|(
name|arg
parameter_list|,
name|unit
parameter_list|,
name|name
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
for|for
control|(
name|d
operator|=
name|softd
operator|->
name|dstlist
index|[
name|unit
operator|+
literal|1
index|]
init|;
name|d
operator|!=
name|NULL
condition|;
name|d
operator|=
name|d
operator|->
name|ipld_next
control|)
block|{
if|if
condition|(
operator|(
name|d
operator|->
name|ipld_unit
operator|==
name|unit
operator|)
operator|&&
operator|!
name|strncmp
argument_list|(
name|d
operator|->
name|ipld_name
argument_list|,
name|name
argument_list|,
name|FR_GROUPLEN
argument_list|)
condition|)
block|{
return|return
name|d
return|;
block|}
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
comment|/* Function:    ipf_dstlist_select_ref                                      */
end_comment

begin_comment
comment|/* Returns:     void *   - NULL = failure, else pointer to table            */
end_comment

begin_comment
comment|/* Parameters:  arg(I)   - pointer to local context to use                  */
end_comment

begin_comment
comment|/*              unit(I)  - device we are working with                       */
end_comment

begin_comment
comment|/*              name(I)  - destination table name to find                   */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Attempt to find a destination table that matches the name passed in and  */
end_comment

begin_comment
comment|/* if successful, bump up the reference count on it because we intend to    */
end_comment

begin_comment
comment|/* store the pointer to it somewhere else.                                  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|ipf_dstlist_select_ref
parameter_list|(
name|arg
parameter_list|,
name|unit
parameter_list|,
name|name
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
name|d
operator|=
name|ipf_dstlist_table_find
argument_list|(
name|arg
argument_list|,
name|unit
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|!=
name|NULL
condition|)
block|{
name|MUTEX_ENTER
argument_list|(
operator|&
name|d
operator|->
name|ipld_lock
argument_list|)
expr_stmt|;
name|d
operator|->
name|ipld_ref
operator|++
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|d
operator|->
name|ipld_lock
argument_list|)
expr_stmt|;
block|}
return|return
name|d
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_select                                          */
end_comment

begin_comment
comment|/* Returns:     void * - NULL = failure, else pointer to table              */
end_comment

begin_comment
comment|/* Parameters:  fin(I) - pointer to packet information                      */
end_comment

begin_comment
comment|/*              d(I)   - pointer to destination list                        */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Find the next node in the destination list to be used according to the   */
end_comment

begin_comment
comment|/* defined policy. Of these, "connection" is the most expensive policy to   */
end_comment

begin_comment
comment|/* implement as it always looks for the node with the least number of       */
end_comment

begin_comment
comment|/* connections associated with it.                                          */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* The hashes exclude the port numbers so that all protocols map to the     */
end_comment

begin_comment
comment|/* same destination. Otherwise, someone doing a ping would target a         */
end_comment

begin_comment
comment|/* different server than their TCP connection, etc. MD-5 is used to         */
end_comment

begin_comment
comment|/* transform the addressese into something random that the other end could  */
end_comment

begin_comment
comment|/* not easily guess and use in an attack. ipld_seed introduces an unknown   */
end_comment

begin_comment
comment|/* into the hash calculation to increase the difficult of an attacker       */
end_comment

begin_comment
comment|/* guessing the bucket.                                                     */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* One final comment: mixing different address families in a single pool    */
end_comment

begin_comment
comment|/* will currently result in failures as the address family of the node is   */
end_comment

begin_comment
comment|/* only matched up with that in the packet as the last step. While this can */
end_comment

begin_comment
comment|/* be coded around for the weighted connection and round-robin models, it   */
end_comment

begin_comment
comment|/* cannot be supported for the hash/random models as they do not search and */
end_comment

begin_comment
comment|/* nor is the algorithm conducive to searching.                             */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|ipf_dstnode_t
modifier|*
name|ipf_dstlist_select
parameter_list|(
name|fin
parameter_list|,
name|d
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|ippool_dst_t
modifier|*
name|d
decl_stmt|;
block|{
name|ipf_dstnode_t
modifier|*
name|node
decl_stmt|,
modifier|*
name|sel
decl_stmt|;
name|int
name|connects
decl_stmt|;
name|u_32_t
name|hash
index|[
literal|4
index|]
decl_stmt|;
name|MD5_CTX
name|ctx
decl_stmt|;
name|int
name|family
decl_stmt|;
name|int
name|x
decl_stmt|;
if|if
condition|(
name|d
operator|==
name|NULL
operator|||
name|d
operator|->
name|ipld_dests
operator|==
name|NULL
operator|||
operator|*
name|d
operator|->
name|ipld_dests
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|family
operator|=
name|fin
operator|->
name|fin_family
expr_stmt|;
name|MUTEX_ENTER
argument_list|(
operator|&
name|d
operator|->
name|ipld_lock
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|d
operator|->
name|ipld_policy
condition|)
block|{
case|case
name|IPLDP_ROUNDROBIN
case|:
name|sel
operator|=
name|d
operator|->
name|ipld_selected
expr_stmt|;
if|if
condition|(
name|sel
operator|==
name|NULL
condition|)
block|{
name|sel
operator|=
operator|*
name|d
operator|->
name|ipld_dests
expr_stmt|;
block|}
else|else
block|{
name|sel
operator|=
name|sel
operator|->
name|ipfd_next
expr_stmt|;
if|if
condition|(
name|sel
operator|==
name|NULL
condition|)
name|sel
operator|=
operator|*
name|d
operator|->
name|ipld_dests
expr_stmt|;
block|}
break|break;
case|case
name|IPLDP_CONNECTION
case|:
if|if
condition|(
name|d
operator|->
name|ipld_selected
operator|==
name|NULL
condition|)
block|{
name|sel
operator|=
operator|*
name|d
operator|->
name|ipld_dests
expr_stmt|;
break|break;
block|}
name|sel
operator|=
name|d
operator|->
name|ipld_selected
expr_stmt|;
name|connects
operator|=
literal|0x7fffffff
expr_stmt|;
name|node
operator|=
name|sel
operator|->
name|ipfd_next
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|NULL
condition|)
name|node
operator|=
operator|*
name|d
operator|->
name|ipld_dests
expr_stmt|;
while|while
condition|(
name|node
operator|!=
name|d
operator|->
name|ipld_selected
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|ipfd_states
operator|==
literal|0
condition|)
block|{
name|sel
operator|=
name|node
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|node
operator|->
name|ipfd_states
operator|<
name|connects
condition|)
block|{
name|sel
operator|=
name|node
expr_stmt|;
name|connects
operator|=
name|node
operator|->
name|ipfd_states
expr_stmt|;
block|}
name|node
operator|=
name|node
operator|->
name|ipfd_next
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|NULL
condition|)
name|node
operator|=
operator|*
name|d
operator|->
name|ipld_dests
expr_stmt|;
block|}
break|break;
case|case
name|IPLDP_RANDOM
case|:
name|x
operator|=
name|ipf_random
argument_list|()
operator|%
name|d
operator|->
name|ipld_nodes
expr_stmt|;
name|sel
operator|=
name|d
operator|->
name|ipld_dests
index|[
name|x
index|]
expr_stmt|;
break|break;
case|case
name|IPLDP_HASHED
case|:
name|MD5Init
argument_list|(
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
operator|&
name|d
operator|->
name|ipld_seed
argument_list|,
sizeof|sizeof
argument_list|(
name|d
operator|->
name|ipld_seed
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
operator|&
name|fin
operator|->
name|fin_src6
argument_list|,
sizeof|sizeof
argument_list|(
name|fin
operator|->
name|fin_src6
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
operator|&
name|fin
operator|->
name|fin_dst6
argument_list|,
sizeof|sizeof
argument_list|(
name|fin
operator|->
name|fin_dst6
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Final
argument_list|(
operator|(
name|u_char
operator|*
operator|)
name|hash
argument_list|,
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|x
operator|=
name|hash
index|[
literal|0
index|]
operator|%
name|d
operator|->
name|ipld_nodes
expr_stmt|;
name|sel
operator|=
name|d
operator|->
name|ipld_dests
index|[
name|x
index|]
expr_stmt|;
break|break;
case|case
name|IPLDP_SRCHASH
case|:
name|MD5Init
argument_list|(
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
operator|&
name|d
operator|->
name|ipld_seed
argument_list|,
sizeof|sizeof
argument_list|(
name|d
operator|->
name|ipld_seed
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
operator|&
name|fin
operator|->
name|fin_src6
argument_list|,
sizeof|sizeof
argument_list|(
name|fin
operator|->
name|fin_src6
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Final
argument_list|(
operator|(
name|u_char
operator|*
operator|)
name|hash
argument_list|,
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|x
operator|=
name|hash
index|[
literal|0
index|]
operator|%
name|d
operator|->
name|ipld_nodes
expr_stmt|;
name|sel
operator|=
name|d
operator|->
name|ipld_dests
index|[
name|x
index|]
expr_stmt|;
break|break;
case|case
name|IPLDP_DSTHASH
case|:
name|MD5Init
argument_list|(
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
operator|&
name|d
operator|->
name|ipld_seed
argument_list|,
sizeof|sizeof
argument_list|(
name|d
operator|->
name|ipld_seed
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
operator|&
name|fin
operator|->
name|fin_dst6
argument_list|,
sizeof|sizeof
argument_list|(
name|fin
operator|->
name|fin_dst6
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Final
argument_list|(
operator|(
name|u_char
operator|*
operator|)
name|hash
argument_list|,
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|x
operator|=
name|hash
index|[
literal|0
index|]
operator|%
name|d
operator|->
name|ipld_nodes
expr_stmt|;
name|sel
operator|=
name|d
operator|->
name|ipld_dests
index|[
name|x
index|]
expr_stmt|;
break|break;
default|default :
name|sel
operator|=
name|NULL
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|sel
operator|&&
name|sel
operator|->
name|ipfd_dest
operator|.
name|fd_addr
operator|.
name|adf_family
operator|!=
name|family
condition|)
name|sel
operator|=
name|NULL
expr_stmt|;
name|d
operator|->
name|ipld_selected
operator|=
name|sel
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|d
operator|->
name|ipld_lock
argument_list|)
expr_stmt|;
return|return
name|sel
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_select_node                                     */
end_comment

begin_comment
comment|/* Returns:     int      - -1 == failure, 0 == success                      */
end_comment

begin_comment
comment|/* Parameters:  fin(I)   - pointer to packet information                    */
end_comment

begin_comment
comment|/*              group(I) - destination pool to search                       */
end_comment

begin_comment
comment|/*              addr(I)  - pointer to store selected address                */
end_comment

begin_comment
comment|/*              pfdp(O)  - pointer to storage for selected destination node */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* This function is only responsible for obtaining the next IP address for  */
end_comment

begin_comment
comment|/* use and storing it in the caller's address space (addr). "addr" is only  */
end_comment

begin_comment
comment|/* used for storage if pfdp is NULL. No permanent reference is currently    */
end_comment

begin_comment
comment|/* kept on the node.                                                        */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|int
name|ipf_dstlist_select_node
parameter_list|(
name|fin
parameter_list|,
name|group
parameter_list|,
name|addr
parameter_list|,
name|pfdp
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|void
modifier|*
name|group
decl_stmt|;
name|u_32_t
modifier|*
name|addr
decl_stmt|;
name|frdest_t
modifier|*
name|pfdp
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|USE_MUTEXES
name|ipf_main_softc_t
modifier|*
name|softc
init|=
name|fin
operator|->
name|fin_main_soft
decl_stmt|;
endif|#
directive|endif
name|ippool_dst_t
modifier|*
name|d
init|=
name|group
decl_stmt|;
name|ipf_dstnode_t
modifier|*
name|node
decl_stmt|;
name|frdest_t
modifier|*
name|fdp
decl_stmt|;
name|READ_ENTER
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
name|node
operator|=
name|ipf_dstlist_select
argument_list|(
name|fin
argument_list|,
name|d
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|NULL
condition|)
block|{
name|RWLOCK_EXIT
argument_list|(
operator|&
name|softc
operator|->
name|ipf_poolrw
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|pfdp
operator|!=
name|NULL
condition|)
block|{
name|bcopy
argument_list|(
operator|&
name|node
operator|->
name|ipfd_dest
argument_list|,
name|pfdp
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|pfdp
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|fin
operator|->
name|fin_family
operator|==
name|AF_INET
condition|)
block|{
name|addr
index|[
literal|0
index|]
operator|=
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_addr
operator|.
name|adf_addr
operator|.
name|i6
index|[
literal|0
index|]
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|fin
operator|->
name|fin_family
operator|==
name|AF_INET6
condition|)
block|{
name|addr
index|[
literal|0
index|]
operator|=
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_addr
operator|.
name|adf_addr
operator|.
name|i6
index|[
literal|0
index|]
expr_stmt|;
name|addr
index|[
literal|1
index|]
operator|=
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_addr
operator|.
name|adf_addr
operator|.
name|i6
index|[
literal|1
index|]
expr_stmt|;
name|addr
index|[
literal|2
index|]
operator|=
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_addr
operator|.
name|adf_addr
operator|.
name|i6
index|[
literal|2
index|]
expr_stmt|;
name|addr
index|[
literal|3
index|]
operator|=
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_addr
operator|.
name|adf_addr
operator|.
name|i6
index|[
literal|3
index|]
expr_stmt|;
block|}
block|}
name|fdp
operator|=
operator|&
name|node
operator|->
name|ipfd_dest
expr_stmt|;
if|if
condition|(
name|fdp
operator|->
name|fd_ptr
operator|==
name|NULL
condition|)
name|fdp
operator|->
name|fd_ptr
operator|=
name|fin
operator|->
name|fin_ifp
expr_stmt|;
name|MUTEX_ENTER
argument_list|(
operator|&
name|node
operator|->
name|ipfd_lock
argument_list|)
expr_stmt|;
name|node
operator|->
name|ipfd_states
operator|++
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|node
operator|->
name|ipfd_lock
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
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_expire                                          */
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
comment|/* There are currently no objects to expire in destination lists.           */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
specifier|static
name|void
name|ipf_dstlist_expire
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
return|return;
block|}
end_function

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Function:    ipf_dstlist_sync                                            */
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
comment|/* When a network interface appears or disappears, we need to revalidate    */
end_comment

begin_comment
comment|/* all of the network interface names that have been configured as a target */
end_comment

begin_comment
comment|/* in a destination list.                                                   */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_function
name|void
name|ipf_dstlist_sync
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
name|ipf_dstl_softc_t
modifier|*
name|softd
init|=
name|arg
decl_stmt|;
name|ipf_dstnode_t
modifier|*
name|node
decl_stmt|;
name|ippool_dst_t
modifier|*
name|list
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|j
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|IPL_LOGMAX
condition|;
name|i
operator|++
control|)
block|{
for|for
control|(
name|list
operator|=
name|softd
operator|->
name|dstlist
index|[
name|i
index|]
init|;
name|list
operator|!=
name|NULL
condition|;
name|list
operator|=
name|list
operator|->
name|ipld_next
control|)
block|{
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|list
operator|->
name|ipld_maxnodes
condition|;
name|j
operator|++
control|)
block|{
name|node
operator|=
name|list
operator|->
name|ipld_dests
index|[
name|j
index|]
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|NULL
condition|)
continue|continue;
if|if
condition|(
name|node
operator|->
name|ipfd_dest
operator|.
name|fd_name
operator|==
operator|-
literal|1
condition|)
continue|continue;
operator|(
name|void
operator|)
name|ipf_resolvedest
argument_list|(
name|softc
argument_list|,
name|node
operator|->
name|ipfd_names
argument_list|,
operator|&
name|node
operator|->
name|ipfd_dest
argument_list|,
name|AF_INET
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function

end_unit

