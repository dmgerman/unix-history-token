begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998 John S. Dyson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *	notice immediately at the beginning of the file, without modification,  *	this list of conditions, and the following disclaimer.  * 2. Absolutely no warranty of function or purpose is made by the author  *	John S. Dyson.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ZONE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZONE_H
end_define

begin_define
define|#
directive|define
name|ZONE_INTERRUPT
value|1
end_define

begin_comment
comment|/* Use this if you need to allocate at int time */
end_comment

begin_define
define|#
directive|define
name|ZONE_BOOT
value|16
end_define

begin_comment
comment|/* This is an internal flag used by zbootinit */
end_comment

begin_include
include|#
directive|include
file|<machine/lock.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|vm_zone
block|{
name|struct
name|simplelock
name|zlock
decl_stmt|;
comment|/* lock for data structure */
name|void
modifier|*
name|zitems
decl_stmt|;
comment|/* linked list of items */
name|int
name|zfreecnt
decl_stmt|;
comment|/* free entries */
name|int
name|zfreemin
decl_stmt|;
comment|/* minimum number of free entries */
name|int
name|znalloc
decl_stmt|;
comment|/* number of allocations */
name|vm_offset_t
name|zkva
decl_stmt|;
comment|/* Base kva of zone */
name|int
name|zpagecount
decl_stmt|;
comment|/* Total # of allocated pages */
name|int
name|zpagemax
decl_stmt|;
comment|/* Max address space */
name|int
name|zmax
decl_stmt|;
comment|/* Max number of entries allocated */
name|int
name|ztotal
decl_stmt|;
comment|/* Total entries allocated now */
name|int
name|zsize
decl_stmt|;
comment|/* size of each entry */
name|int
name|zalloc
decl_stmt|;
comment|/* hint for # of pages to alloc */
name|int
name|zflags
decl_stmt|;
comment|/* flags for zone */
name|int
name|zallocflag
decl_stmt|;
comment|/* flag for allocation */
name|struct
name|vm_object
modifier|*
name|zobj
decl_stmt|;
comment|/* object to hold zone */
name|char
modifier|*
name|zname
decl_stmt|;
comment|/* name for diags */
name|struct
name|vm_zone
modifier|*
name|znext
decl_stmt|;
comment|/* list of zones for sysctl */
block|}
typedef|*
name|vm_zone_t
typedef|;
end_typedef

begin_decl_stmt
name|void
name|zerror
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_zone_t
name|zinit
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|size
operator|,
name|int
name|nentries
operator|,
name|int
name|flags
operator|,
name|int
name|zalloc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zinitna
name|__P
argument_list|(
operator|(
name|vm_zone_t
name|z
operator|,
expr|struct
name|vm_object
operator|*
name|obj
operator|,
name|char
operator|*
name|name
operator|,
name|int
name|size
operator|,
name|int
name|nentries
operator|,
name|int
name|flags
operator|,
name|int
name|zalloc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|zalloc
name|__P
argument_list|(
operator|(
name|vm_zone_t
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|zfree
name|__P
argument_list|(
operator|(
name|vm_zone_t
name|z
operator|,
name|void
operator|*
name|item
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|zalloci
name|__P
argument_list|(
operator|(
name|vm_zone_t
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|zfreei
name|__P
argument_list|(
operator|(
name|vm_zone_t
name|z
operator|,
name|void
operator|*
name|item
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|zbootinit
name|__P
argument_list|(
operator|(
name|vm_zone_t
name|z
operator|,
name|char
operator|*
name|name
operator|,
name|int
name|size
operator|,
name|void
operator|*
name|item
operator|,
name|int
name|nitems
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_zget
name|__P
argument_list|(
operator|(
name|vm_zone_t
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ZONE_H */
end_comment

end_unit

