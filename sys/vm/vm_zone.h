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
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|vm_zone
block|{
name|struct
name|mtx
name|zmtx
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
comment|/* NOTE: zent is protected by the subsystem lock, *not* by zmtx */
name|SLIST_ENTRY
argument_list|(
argument|vm_zone
argument_list|)
name|zent
expr_stmt|;
comment|/* singly-linked list of zones */
block|}
typedef|*
name|vm_zone_t
typedef|;
end_typedef

begin_function_decl
name|void
name|vm_zone_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_zone_init2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|zinitna
parameter_list|(
name|vm_zone_t
name|z
parameter_list|,
name|struct
name|vm_object
modifier|*
name|obj
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|nentries
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|zalloc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_zone_t
name|zinit
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|nentries
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|zalloc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|zbootinit
parameter_list|(
name|vm_zone_t
name|z
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|item
parameter_list|,
name|int
name|nitems
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|zdestroy
parameter_list|(
name|vm_zone_t
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|zalloc
parameter_list|(
name|vm_zone_t
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|zfree
parameter_list|(
name|vm_zone_t
name|z
parameter_list|,
name|void
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ZONE_H */
end_comment

end_unit

