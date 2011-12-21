begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD: src/usr.bin/tar/tree.h,v 1.4 2008/11/27 05:49:52 kientzle Exp $  */
end_comment

begin_comment
comment|/*-  * A set of routines for traversing directory trees.  * Similar in concept to the fts library, but with a few  * important differences:  *    * Uses less memory.  In particular, fts stores an entire directory  *      in memory at a time.  This package only keeps enough subdirectory  *      information in memory to track the traversal.  Information  *      about non-directories is discarded as soon as possible.  *    * Supports very deep logical traversals.  The fts package  *      uses "non-chdir" approach for logical traversals.  This  *      package does use a chdir approach for logical traversals  *      and can therefore handle pathnames much longer than PATH_MAX.  *    * Supports deep physical traversals "out of the box."  *      Due to the memory optimizations above, there's no need to  *      limit dir names to 32k.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_struct_decl
struct_decl|struct
name|tree
struct_decl|;
end_struct_decl

begin_comment
comment|/* Initiate/terminate a tree traversal. */
end_comment

begin_function_decl
name|struct
name|tree
modifier|*
name|tree_open
parameter_list|(
specifier|const
name|char
modifier|*
comment|/* pathname */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tree_close
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tree_next() returns Zero if there is no next entry, non-zero if  * there is.  Note that directories are visited three times.  * Directories are always visited first as part of enumerating their  * parent; that is a "regular" visit.  If tree_descend() is invoked at  * that time, the directory is added to a work list and will  * subsequently be visited two more times: once just after descending  * into the directory ("postdescent") and again just after ascending  * back to the parent ("postascent").  *  * TREE_ERROR_DIR is returned if the descent failed (because the  * directory couldn't be opened, for instance).  This is returned  * instead of TREE_POSTDESCENT/TREE_POSTASCENT.  TREE_ERROR_DIR is not a  * fatal error, but it does imply that the relevant subtree won't be  * visited.  TREE_ERROR_FATAL is returned for an error that left the  * traversal completely hosed.  Right now, this is only returned for  * chdir() failures during ascent.  */
end_comment

begin_define
define|#
directive|define
name|TREE_REGULAR
value|1
end_define

begin_define
define|#
directive|define
name|TREE_POSTDESCENT
value|2
end_define

begin_define
define|#
directive|define
name|TREE_POSTASCENT
value|3
end_define

begin_define
define|#
directive|define
name|TREE_ERROR_DIR
value|-1
end_define

begin_define
define|#
directive|define
name|TREE_ERROR_FATAL
value|-2
end_define

begin_function_decl
name|int
name|tree_next
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Errno value associated with the last traversal error. */
end_comment

begin_function_decl
name|int
name|tree_errno
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Request that current entry be visited.  If you invoke it on every  * directory, you'll get a physical traversal.  This is ignored if the  * current entry isn't a directory or a link to a directory.  So, if  * you invoke this on every returned path, you'll get a full logical  * traversal.  */
end_comment

begin_function_decl
name|void
name|tree_descend
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return information about the current entry.  */
end_comment

begin_comment
comment|/* Current depth in the traversal. */
end_comment

begin_function_decl
name|int
name|tree_current_depth
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The current full pathname, length of the full pathname, and a name  * that can be used to access the file.  Because tree does use chdir  * extensively, the access path is almost never the same as the full  * current path.  *  * TODO: Flesh out this interface to provide other information.  In  * particular, Windows can provide file size, mode, and some permission  * information without invoking stat() at all.  *  * TODO: On platforms that support it, use openat()-style operations  * to eliminate the chdir() operations entirely while still supporting  * arbitrarily deep traversals.  This makes access_path troublesome to  * support, of course, which means we'll need a rich enough interface  * that clients can function without it.  (In particular, we'll need  * tree_current_open() that returns an open file descriptor.)  *  * TODO: Provide tree_current_archive_entry().  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|tree_current_path
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|tree_current_pathlen
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|tree_current_access_path
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Request the lstat() or stat() data for the current path.  Since the  * tree package needs to do some of this anyway, and caches the  * results, you should take advantage of it here if you need it rather  * than make a redundant stat() or lstat() call of your own.  */
end_comment

begin_function_decl
specifier|const
name|struct
name|stat
modifier|*
name|tree_current_stat
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|stat
modifier|*
name|tree_current_lstat
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following functions use tricks to avoid a certain number of  * stat()/lstat() calls. */
end_comment

begin_comment
comment|/* "is_physical_dir" is equivalent to S_ISDIR(tree_current_lstat()->st_mode) */
end_comment

begin_function_decl
name|int
name|tree_current_is_physical_dir
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* "is_physical_link" is equivalent to S_ISLNK(tree_current_lstat()->st_mode) */
end_comment

begin_function_decl
name|int
name|tree_current_is_physical_link
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* "is_dir" is equivalent to S_ISDIR(tree_current_stat()->st_mode) */
end_comment

begin_function_decl
name|int
name|tree_current_is_dir
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For testing/debugging: Dump the internal status to the given filehandle. */
end_comment

begin_function_decl
name|void
name|tree_dump
parameter_list|(
name|struct
name|tree
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

