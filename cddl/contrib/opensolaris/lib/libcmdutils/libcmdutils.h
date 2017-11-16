begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 RackTop Systems.  */
end_comment

begin_comment
comment|/*  * Copyright 2017 Joyent, Inc.  */
end_comment

begin_comment
comment|/*  * Declarations for the functions in libcmdutils.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCMDUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCMDUTILS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|illumos
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LP64
argument_list|)
operator|&&
expr|\
operator|!
operator|(
operator|(
name|_FILE_OFFSET_BITS
operator|==
literal|64
operator|)
operator|||
name|defined
argument_list|(
name|_LARGEFILE64_SOURCE
argument_list|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"libcmdutils.h can only be used in a largefile compilation environment"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is a private header file.  Applications should not directly include  * this file.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|illumos
end_ifdef

begin_include
include|#
directive|include
file|<attr.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/avl.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<libnvpair.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* extended system attribute support */
define|#
directive|define
name|_NOT_SATTR
value|0
define|#
directive|define
name|_RO_SATTR
value|1
define|#
directive|define
name|_RW_SATTR
value|2
define|#
directive|define
name|MAXMAPSIZE
value|(1024*1024*8)
comment|/* map at most 8MB */
define|#
directive|define
name|SMALLFILESIZE
value|(32*1024)
comment|/* don't use mmap on little file */
comment|/* Type used for a node containing a device id and inode number */
if|#
directive|if
name|defined
argument_list|(
name|_LP64
argument_list|)
operator|||
operator|(
name|_FILE_OFFSET_BITS
operator|==
literal|64
operator|)
typedef|typedef
struct|struct
name|tree_node
block|{
name|dev_t
name|node_dev
decl_stmt|;
name|ino_t
name|node_ino
decl_stmt|;
name|avl_node_t
name|avl_link
decl_stmt|;
block|}
name|tree_node_t
typedef|;
else|#
directive|else
typedef|typedef
struct|struct
name|tree_node
block|{
name|dev_t
name|node_dev
decl_stmt|;
name|ino64_t
name|node_ino
decl_stmt|;
name|avl_node_t
name|avl_link
decl_stmt|;
block|}
name|tree_node_t
typedef|;
endif|#
directive|endif
comment|/* extended system attribute support */
comment|/* Determine if a file is the name of an extended system attribute file */
specifier|extern
name|int
name|sysattr_type
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Determine if the underlying file system supports system attributes */
specifier|extern
name|int
name|sysattr_support
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Copies the content of the source file to the target file */
if|#
directive|if
name|defined
argument_list|(
name|_LP64
argument_list|)
operator|||
operator|(
name|_FILE_OFFSET_BITS
operator|==
literal|64
operator|)
specifier|extern
name|int
name|writefile
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|int
name|writefile
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|stat64
modifier|*
parameter_list|,
name|struct
name|stat64
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* Gets file descriptors of the source and target attribute files */
specifier|extern
name|int
name|get_attrdirs
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/* Move extended attribute and extended system attribute */
specifier|extern
name|int
name|mv_xattrs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Returns non default extended system attribute list */
specifier|extern
name|nvlist_t
modifier|*
name|sysattr_list
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* avltree */
comment|/*  * Used to compare two nodes.  We are attempting to match the 1st  * argument (node) against the 2nd argument (a node which  * is already in the search tree).  */
specifier|extern
name|int
name|tnode_compare
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Used to add a single node (containing the input device id and  * inode number) to the specified search tree.  The calling  * application must set the tree pointer to NULL before calling  * add_tnode() for the first time.  */
if|#
directive|if
name|defined
argument_list|(
name|_LP64
argument_list|)
operator|||
operator|(
name|_FILE_OFFSET_BITS
operator|==
literal|64
operator|)
specifier|extern
name|int
name|add_tnode
parameter_list|(
name|avl_tree_t
modifier|*
modifier|*
parameter_list|,
name|dev_t
parameter_list|,
name|ino_t
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|int
name|add_tnode
parameter_list|(
name|avl_tree_t
modifier|*
modifier|*
parameter_list|,
name|dev_t
parameter_list|,
name|ino64_t
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/*  * Used to destroy a whole tree (all nodes) without rebalancing.  * The calling application is responsible for setting the tree  * pointer to NULL upon return.  */
specifier|extern
name|void
name|destroy_tree
parameter_list|(
name|avl_tree_t
modifier|*
parameter_list|)
function_decl|;
comment|/* user/group id helpers */
comment|/*  * Used to get the next available user id in given range.  */
specifier|extern
name|int
name|findnextuid
parameter_list|(
name|uid_t
parameter_list|,
name|uid_t
parameter_list|,
name|uid_t
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Used to get the next available group id in given range.  */
specifier|extern
name|int
name|findnextgid
parameter_list|(
name|gid_t
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
comment|/* dynamic string utilities */
typedef|typedef
name|struct
name|custr
name|custr_t
typedef|;
comment|/*  * Allocate and free a "custr_t" dynamic string object.  Returns 0 on success  * and -1 otherwise.  */
specifier|extern
name|int
name|custr_alloc
parameter_list|(
name|custr_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|custr_free
parameter_list|(
name|custr_t
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Allocate a "custr_t" dynamic string object that operates on a fixed external  * buffer.  */
specifier|extern
name|int
name|custr_alloc_buf
parameter_list|(
name|custr_t
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/*  * Append a single character, or a NUL-terminated string of characters, to a  * dynamic string.  Returns 0 on success and -1 otherwise.  The dynamic string  * will be unmodified if the function returns -1.  */
specifier|extern
name|int
name|custr_appendc
parameter_list|(
name|custr_t
modifier|*
parameter_list|,
name|char
parameter_list|)
function_decl|;
specifier|extern
name|int
name|custr_append
parameter_list|(
name|custr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Append a format string and arguments as though the contents were being parsed  * through snprintf. Returns 0 on success and -1 otherwise.  The dynamic string  * will be unmodified if the function returns -1.  */
specifier|extern
name|int
name|custr_append_printf
parameter_list|(
name|custr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|custr_append_vprintf
parameter_list|(
name|custr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
comment|/*  * Determine the length in bytes, not including the NUL terminator, of the  * dynamic string.  */
specifier|extern
name|size_t
name|custr_len
parameter_list|(
name|custr_t
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Clear the contents of a dynamic string.  Does not free the underlying  * memory.  */
specifier|extern
name|void
name|custr_reset
parameter_list|(
name|custr_t
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Retrieve a const pointer to a NUL-terminated string version of the contents  * of the dynamic string.  Storage for this string should not be freed, and  * the pointer will be invalidated by any mutations to the dynamic string.  */
specifier|extern
specifier|const
name|char
modifier|*
name|custr_cstr
parameter_list|(
name|custr_t
modifier|*
name|str
parameter_list|)
function_decl|;
define|#
directive|define
name|NN_DIVISOR_1000
value|(1U<< 0)
comment|/* Minimum size for the output of nicenum, including NULL */
define|#
directive|define
name|NN_NUMBUF_SZ
value|(6)
name|void
name|nicenum
parameter_list|(
name|uint64_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
name|nicenum_scale
parameter_list|(
name|uint64_t
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBCMDUTILS_H */
end_comment

end_unit

