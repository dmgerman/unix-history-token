begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/* @(#)cache.h 1.4 69/12/31 SMI */
end_comment

begin_comment
comment|/*  * ld.so directory caching  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * Shared object lookup performance in the run-time link editor is   * enhanced through the use of caches for directories that the editor  * searches.  A given "cache" describes the contents of a single directory,  * and each cache entry contains the canonical name for a shared object  * as well as its absolute pathname.  *  * Within a cache, "pointers" are really relative addresses to some absolute  * address (often the base address of the containing database).  */
end_comment

begin_define
define|#
directive|define
name|CACHE_FILE
value|"/etc/ld.so.cache"
end_define

begin_comment
comment|/* file where it is stored */
end_comment

begin_comment
comment|/*  * Relative pointer macros.  */
end_comment

begin_define
define|#
directive|define
name|RELPTR
parameter_list|(
name|base
parameter_list|,
name|absptr
parameter_list|)
value|((long)(absptr) - (long)(base))
end_define

begin_define
define|#
directive|define
name|AP
parameter_list|(
name|base
parameter_list|)
value|((caddr_t)base)
end_define

begin_comment
comment|/*  * Definitions for cache structures.  */
end_comment

begin_define
define|#
directive|define
name|DB_HASH
value|11
end_define

begin_comment
comment|/* number of hash buckets in caches */
end_comment

begin_define
define|#
directive|define
name|LD_CACHE_MAGIC
value|0x041155
end_define

begin_comment
comment|/* cookie to identify data structure */
end_comment

begin_define
define|#
directive|define
name|LD_CACHE_VERSION
value|0
end_define

begin_comment
comment|/* version number of cache structure*/
end_comment

begin_struct
struct|struct
name|dbe
block|{
comment|/* element of a directory cache */
name|long
name|dbe_next
decl_stmt|;
comment|/* (rp) next element on this list */
name|long
name|dbe_lop
decl_stmt|;
comment|/* (rp) canonical name for object */
name|long
name|dbe_name
decl_stmt|;
comment|/* (rp) absolute name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|db
block|{
comment|/* directory cache database */
name|long
name|db_name
decl_stmt|;
comment|/* (rp) directory contained here */
name|struct
name|dbe
name|db_hash
index|[
name|DB_HASH
index|]
decl_stmt|;
comment|/* hash buckets */
name|caddr_t
name|db_chain
decl_stmt|;
comment|/* private to database mapping */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbf
block|{
comment|/* cache file image */
name|long
name|dbf_magic
decl_stmt|;
comment|/* identifying cookie */
name|long
name|dbf_version
decl_stmt|;
comment|/* version no. of these dbs */
name|long
name|dbf_machtype
decl_stmt|;
comment|/* machine type */
name|long
name|dbf_db
decl_stmt|;
comment|/* directory cache dbs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structures used to describe and access a database.  */
end_comment

begin_struct
struct|struct
name|dbd
block|{
comment|/* data base descriptor */
name|struct
name|dbd
modifier|*
name|dbd_next
decl_stmt|;
comment|/* next one on this list */
name|struct
name|db
modifier|*
name|dbd_db
decl_stmt|;
comment|/* data base described by this */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dd
block|{
comment|/* directory descriptor */
name|struct
name|dd
modifier|*
name|dd_next
decl_stmt|;
comment|/* next one on this list */
name|struct
name|db
modifier|*
name|dd_db
decl_stmt|;
comment|/* data base described by this */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interfaces imported/exported by the lookup code.  */
end_comment

begin_function_decl
name|caddr_t
function_decl|(
modifier|*
name|db_malloc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* allocator for relative objects */
end_comment

begin_function_decl
name|caddr_t
function_decl|(
modifier|*
name|heap_malloc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* allocator for general objects */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|is_secure
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tells whether censorship in force */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|use_cache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use existing cache? */
end_comment

begin_decl_stmt
specifier|extern
name|caddr_t
name|db_base
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|lo_lookup
parameter_list|(
comment|/* lop, lmp */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* name for link_object */
end_comment

begin_function_decl
name|struct
name|db
modifier|*
name|lo_cache
parameter_list|(
comment|/* cp */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* obtain cache for directory name */
end_comment

begin_function_decl
name|void
name|lo_flush
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* foreach dir get a new database */
end_comment

begin_function_decl
name|void
name|dbd_flush
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* delete the dbs that came from  					   ld.so.cache */
end_comment

end_unit

