begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)map.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Resource allocation maps.  *  * Associated routines manage sub-allocation of an address space using  * an array of segment descriptors.  The first element of this array  * is a map structure, describing the arrays extent and the name  * of the controlled object.  Each additional structure represents  * a free segment of the address space.  *  * A call to rminit initializes a resource map and may also be used  * to free some address space for the map.  Subsequent calls to rmalloc  * and rmfree allocate and free space in the resource map.  If the resource  * map becomes too fragmented to be described in the available space,  * then some of the resource is discarded.  This may lead to critical  * shortages, but is better than not checking (as the previous versions  * of these routines did) or giving up and calling panic().  The routines  * could use linked lists and call a memory allocator when they run  * out of space, but that would not solve the out of space problem when  * called at interrupt time.  *  * N.B.: The address 0 in the resource address space is not available  * as it is used internally by the resource map routines.  */
end_comment

begin_struct
struct|struct
name|map
block|{
name|struct
name|mapent
modifier|*
name|m_limit
decl_stmt|;
comment|/* address of last slot in map */
name|char
modifier|*
name|m_name
decl_stmt|;
comment|/* name of resource, for messages */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mapent
block|{
name|int
name|m_size
decl_stmt|;
comment|/* size of this segment of the map */
name|int
name|m_addr
decl_stmt|;
comment|/* start of segment */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|ARGMAPSIZE
value|16
end_define

begin_decl_stmt
name|struct
name|map
modifier|*
name|kmemmap
decl_stmt|,
modifier|*
name|mbmap
decl_stmt|,
modifier|*
name|swapmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nswapmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|rmalloc
name|__P
argument_list|(
operator|(
expr|struct
name|map
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rmfree
name|__P
argument_list|(
operator|(
expr|struct
name|map
operator|*
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rminit
name|__P
argument_list|(
operator|(
expr|struct
name|map
operator|*
operator|,
name|long
operator|,
name|long
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

