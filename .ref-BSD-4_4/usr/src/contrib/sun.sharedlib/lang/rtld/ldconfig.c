begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/* @(#)ldconfig.c 1.10 91/03/17 SMI */
end_comment

begin_comment
comment|/*  * Copyright (c) 1991 by Sun Microsystems, Inc. */
end_comment

begin_expr_stmt
operator|*
operator|/
comment|/*  * ldconfig: build configuration information for ld.so.  */
include|#
directive|include
file|<stdio.h>
comment|/* I/O */
include|#
directive|include
file|<sys/mman.h>
comment|/* memory management */
include|#
directive|include
file|<sys/param.h>
comment|/* general system definitions */
include|#
directive|include
file|<sys/file.h>
comment|/* file I/O bits */
include|#
directive|include
file|<sys/exec.h>
include|#
directive|include
file|<link.h>
comment|/* link editor public */
include|#
directive|include
file|"cache.h"
comment|/* local caching information */
comment|/*  * Global storage and definitions.  */
define|#
directive|define
name|MAX_DB
value|(1024 * 1024)
comment|/* 1Mb database is the max */
name|int
name|fd
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* descriptor on database */
end_comment

begin_decl_stmt
name|caddr_t
name|db_base
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base address of last database */
end_comment

begin_decl_stmt
name|caddr_t
name|heap_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current file allocation */
end_comment

begin_decl_stmt
name|caddr_t
name|heap_base
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base address of file mapping */
end_comment

begin_decl_stmt
name|caddr_t
name|heap_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum file to allocate */
end_comment

begin_function_decl
name|void
name|build_cache
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* build a cache given directory */
end_comment

begin_decl_stmt
name|int
name|first
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if no first entry yet */
end_comment

begin_decl_stmt
name|struct
name|dbf
modifier|*
name|dbfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* working cache file pointer */
end_comment

begin_comment
comment|/*  * "Environmental" variables exported to the cache routines.  */
end_comment

begin_function_decl
specifier|extern
name|caddr_t
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* heap allocator */
end_comment

begin_function_decl
name|caddr_t
name|mmap_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* database allocator */
end_comment

begin_function_decl
name|int
name|false
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* says we're never secure */
end_comment

begin_decl_stmt
name|int
name|use_cache
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no previous database */
end_comment

begin_comment
comment|/*  * List of directories which are always in the cache.  Note: these need  * not be (nor are they) identical to the directories searched by default  * by the loader.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|default_directories
index|[]
init|=
block|{
literal|"/usr/lib"
block|,
literal|"/usr/5lib"
block|,
literal|"/usr/lib/fsoft"
block|,
literal|"/usr/lib/f68881"
block|,
literal|"/usr/lib/ffpa"
block|,
literal|"/usr/lib/fswitch"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Build a database by building over all arguments.  */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
comment|/* loop temporary */
name|char
modifier|*
name|fnp
decl_stmt|;
comment|/* temporary file name */
name|char
modifier|*
modifier|*
name|cpp
decl_stmt|;
comment|/* loop temporary */
comment|/* 	 * Initialize exported functions. 	 */
name|db_malloc
operator|=
name|mmap_alloc
expr_stmt|;
name|heap_malloc
operator|=
name|malloc
expr_stmt|;
name|is_secure
operator|=
name|false
expr_stmt|;
comment|/* 	 * Make a temporary file, map it in up to its maximum length. 	 */
name|fnp
operator|=
operator|(
name|char
operator|*
operator|)
name|mktemp
argument_list|(
literal|"/etc/ld.so.XXXXXX"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|fnp
argument_list|,
name|O_CREAT
operator||
name|O_RDWR
argument_list|,
literal|0644
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"ldconfig: open temporary"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|heap_base
operator|=
name|mmap
argument_list|(
literal|0
argument_list|,
name|MAX_DB
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_SHARED
argument_list|,
name|fd
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|(
name|caddr_t
operator|)
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"ldconfig: mmap"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|db_base
operator|=
name|heap_ptr
operator|=
name|heap_max
operator|=
name|heap_base
expr_stmt|;
name|dbfp
operator|=
operator|(
expr|struct
name|dbf
operator|*
operator|)
call|(
modifier|*
name|db_malloc
call|)
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|dbf
argument_list|)
argument_list|)
expr_stmt|;
name|dbfp
operator|->
name|dbf_magic
operator|=
name|LD_CACHE_MAGIC
expr_stmt|;
if|#
directive|if
name|TARGET
operator|==
name|SUN2
name|dbfp
operator|->
name|dbf_machtype
operator|=
name|M_68010
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|TARGET
operator|==
name|SUN3
name|dbfp
operator|->
name|dbf_machtype
operator|=
name|M_68020
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|TARGET
operator|==
name|SUN4
name|dbfp
operator|->
name|dbf_machtype
operator|=
name|M_SPARC
expr_stmt|;
endif|#
directive|endif
name|dbfp
operator|->
name|dbf_version
operator|=
name|LD_CACHE_VERSION
expr_stmt|;
comment|/* 	 * For each argument, create a database.   	 */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
name|i
operator|++
control|)
name|build_cache
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* 	 * Build a database for each of the default directories. 	 * Note that it is not an error for these directories to 	 * fail (they may not exist in all installations). 	 */
for|for
control|(
name|cpp
operator|=
name|default_directories
init|;
operator|*
name|cpp
condition|;
name|cpp
operator|++
control|)
name|build_cache
argument_list|(
operator|*
name|cpp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * Database built.  Close file, and rename it to be the "real" 	 * database.  However, if nothing every actually got cached, 	 * delete it instead. 	 */
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
if|if
condition|(
name|first
condition|)
block|{
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|fnp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rename
argument_list|(
name|fnp
argument_list|,
name|CACHE_FILE
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"ldconfig: rename"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

begin_comment
comment|/*  * Allocator for mmap arena.  */
end_comment

begin_function
name|caddr_t
name|mmap_alloc
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
name|caddr_t
name|a
decl_stmt|;
specifier|static
name|u_int
name|page_size
init|=
literal|0
decl_stmt|;
comment|/* 	 * Get value -- simply next address to allocate. 	 */
name|a
operator|=
name|heap_ptr
expr_stmt|;
comment|/* 	 * Architecture-dependent rounding. 	 */
ifdef|#
directive|ifdef
name|sparc
name|n
operator|=
name|round
argument_list|(
name|n
argument_list|,
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|sparc
ifdef|#
directive|ifdef
name|mc68000
name|n
operator|=
name|round
argument_list|(
name|n
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|mc68000
comment|/* 	 * If block to be allocated requires file extension, do so. 	 */
if|if
condition|(
operator|(
name|heap_ptr
operator|+
name|n
operator|)
operator|>=
name|heap_max
condition|)
block|{
if|if
condition|(
name|page_size
operator|==
literal|0
condition|)
name|page_size
operator|=
name|getpagesize
argument_list|()
expr_stmt|;
name|heap_max
operator|=
operator|(
name|caddr_t
operator|)
name|roundup
argument_list|(
operator|(
name|u_int
operator|)
name|heap_ptr
operator|+
name|n
argument_list|,
name|page_size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|heap_max
operator|-
name|heap_base
operator|)
operator|>
name|MAX_DB
condition|)
block|{
name|perror
argument_list|(
literal|"ldconfig: data base overflow"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ftruncate
argument_list|(
name|fd
argument_list|,
name|heap_max
operator|-
name|heap_base
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"ldconfig: ftruncate"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	 * Allocate full block, return starting address. 	 */
name|heap_ptr
operator|+=
name|n
expr_stmt|;
return|return
operator|(
name|a
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Call support routines to build a cache for the given directory.  */
end_comment

begin_function
name|void
name|build_cache
parameter_list|(
name|cp
parameter_list|,
name|flag_error
parameter_list|)
name|char
modifier|*
name|cp
decl_stmt|;
comment|/* directory to cache */
name|int
name|flag_error
decl_stmt|;
comment|/* true if errors to be flagged */
block|{
name|struct
name|db
modifier|*
name|dbp
decl_stmt|;
comment|/* working data base file */
if|if
condition|(
operator|(
name|dbp
operator|=
name|lo_cache
argument_list|(
name|cp
argument_list|)
operator|)
operator|==
operator|(
expr|struct
name|db
operator|*
operator|)
name|NULL
condition|)
block|{
if|if
condition|(
name|flag_error
condition|)
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ldconfig: directory %s not cached\n"
argument_list|,
name|cp
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|first
condition|)
block|{
name|dbfp
operator|->
name|dbf_db
operator|=
name|RELPTR
argument_list|(
name|dbfp
argument_list|,
name|dbp
argument_list|)
expr_stmt|;
name|db_base
operator|=
operator|(
name|caddr_t
operator|)
name|dbp
operator|=
operator|&
name|AP
argument_list|(
name|dbfp
argument_list|)
index|[
operator|(
name|int
operator|)
name|dbfp
operator|->
name|dbf_db
index|]
expr_stmt|;
name|first
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|dbp
operator|->
name|db_chain
operator|==
literal|0
condition|)
block|{
name|dbp
operator|->
name|db_chain
operator|=
call|(
name|caddr_t
call|)
argument_list|(
name|heap_ptr
operator|-
name|db_base
argument_list|)
expr_stmt|;
name|db_base
operator|=
name|heap_ptr
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Dummy test to say we're never using security checks.  */
end_comment

begin_function
name|int
name|false
parameter_list|()
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Rounding function.  */
end_comment

begin_macro
name|round
argument_list|(
argument|v
argument_list|,
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|int
name|v
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value to be rounded */
end_comment

begin_decl_stmt
name|int
name|r
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rounding point */
end_comment

begin_block
block|{
name|v
operator|+=
operator|--
name|r
expr_stmt|;
name|v
operator|&=
operator|~
name|r
expr_stmt|;
return|return
operator|(
name|v
operator|)
return|;
block|}
end_block

end_unit

