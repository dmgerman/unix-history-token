begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: makefs.h,v 1.14 2004/06/20 22:20:18 jmc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Luke Mewburn for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project by  *      Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MAKEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_MAKEFS_H
end_define

begin_if
if|#
directive|if
name|HAVE_NBTOOL_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"nbtool_config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_FLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_GEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_MTIMENSEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STATVFS_F_IOSIZE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_BIRTHTIME
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_comment
comment|/*  * fsnode -  *	a component of the tree; contains a filename, a pointer to  *	fsinode, optional symlink name, and tree pointers  *  * fsinode -   *	equivalent to an inode, containing target file system inode number,  *	refcount (nlink), and stat buffer  *  * A tree of fsnodes looks like this:  *  *	name	"."		"bin"		"netbsd"  *	type	S_IFDIR		S_IFDIR		S_IFREG  *	next>>		NULL  *	parent	NULL		NULL		NULL  *	child	NULL		  v  *  *	name			"."		"ls"  *	type			S_IFDIR		S_IFREG  *	next>		NULL  *	parent			  ^		^ (to "bin")  *	child			NULL		NULL  *  * Notes:  *	-   first always points to first entry, at current level, which  *	    must be "." when the tree has been built; during build it may  *	    not be if "." hasn't yet been found by readdir(2).  */
end_comment

begin_enum
enum|enum
name|fi_flags
block|{
name|FI_SIZED
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* inode sized */
name|FI_ALLOCATED
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* fsinode->ino allocated */
name|FI_WRITTEN
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* inode written */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|ino
decl_stmt|;
comment|/* inode number used on target fs */
name|uint32_t
name|nlink
decl_stmt|;
comment|/* number of links to this entry */
name|enum
name|fi_flags
name|flags
decl_stmt|;
comment|/* flags used by fs specific code */
name|struct
name|stat
name|st
decl_stmt|;
comment|/* stat entry */
block|}
name|fsinode
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_fsnode
block|{
name|struct
name|_fsnode
modifier|*
name|parent
decl_stmt|;
comment|/* parent (NULL if root) */
name|struct
name|_fsnode
modifier|*
name|child
decl_stmt|;
comment|/* child (if type == S_IFDIR) */
name|struct
name|_fsnode
modifier|*
name|next
decl_stmt|;
comment|/* next */
name|struct
name|_fsnode
modifier|*
name|first
decl_stmt|;
comment|/* first node of current level (".") */
name|uint32_t
name|type
decl_stmt|;
comment|/* type of entry */
name|fsinode
modifier|*
name|inode
decl_stmt|;
comment|/* actual inode data */
name|char
modifier|*
name|symlink
decl_stmt|;
comment|/* symlink target */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* file name */
name|int
name|flags
decl_stmt|;
comment|/* misc flags */
block|}
name|fsnode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FSNODE_F_HASSPEC
value|0x01
end_define

begin_comment
comment|/* fsnode has a spec entry */
end_comment

begin_comment
comment|/*  * fsinfo_t - contains various settings and parameters pertaining to  * the image, including current settings, global options, and fs  * specific options  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* current settings */
name|off_t
name|size
decl_stmt|;
comment|/* total size */
name|off_t
name|inodes
decl_stmt|;
comment|/* number of inodes */
name|uint32_t
name|curinode
decl_stmt|;
comment|/* current inode */
comment|/* image settings */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor of image */
name|void
modifier|*
name|superblock
decl_stmt|;
comment|/* superblock */
name|int
name|onlyspec
decl_stmt|;
comment|/* only add entries in specfile */
comment|/* global options */
name|off_t
name|minsize
decl_stmt|;
comment|/* minimum size image should be */
name|off_t
name|maxsize
decl_stmt|;
comment|/* maximum size image can be */
name|off_t
name|freefiles
decl_stmt|;
comment|/* free file entries to leave */
name|int
name|freefilepc
decl_stmt|;
comment|/* free file % */
name|off_t
name|freeblocks
decl_stmt|;
comment|/* free blocks to leave */
name|int
name|freeblockpc
decl_stmt|;
comment|/* free block % */
name|int
name|needswap
decl_stmt|;
comment|/* non-zero if byte swapping needed */
name|int
name|sectorsize
decl_stmt|;
comment|/* sector size */
comment|/* ffs specific options */
name|int
name|bsize
decl_stmt|;
comment|/* block size */
name|int
name|fsize
decl_stmt|;
comment|/* fragment size */
name|int
name|cpg
decl_stmt|;
comment|/* cylinders per group */
name|int
name|cpgflg
decl_stmt|;
comment|/* cpg was specified by user */
name|int
name|density
decl_stmt|;
comment|/* bytes per inode */
name|int
name|ntracks
decl_stmt|;
comment|/* number of tracks */
name|int
name|nsectors
decl_stmt|;
comment|/* number of sectors */
name|int
name|rpm
decl_stmt|;
comment|/* rpm */
name|int
name|minfree
decl_stmt|;
comment|/* free space threshold */
name|int
name|optimization
decl_stmt|;
comment|/* optimization (space or time) */
name|int
name|maxcontig
decl_stmt|;
comment|/* max contiguous blocks to allocate */
name|int
name|rotdelay
decl_stmt|;
comment|/* rotational delay between blocks */
name|int
name|maxbpg
decl_stmt|;
comment|/* maximum blocks per file in a cyl group */
name|int
name|nrpos
decl_stmt|;
comment|/* # of distinguished rotational positions */
name|int
name|avgfilesize
decl_stmt|;
comment|/* expected average file size */
name|int
name|avgfpdir
decl_stmt|;
comment|/* expected # of files per directory */
name|int
name|version
decl_stmt|;
comment|/* filesystem version (1 = FFS, 2 = UFS2) */
name|int
name|maxbsize
decl_stmt|;
comment|/* maximum extent size */
name|int
name|maxblkspercg
decl_stmt|;
comment|/* max # of blocks per cylinder group */
comment|/* XXX: support `old' file systems ? */
block|}
name|fsinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * option_t - contains option name, description, pointer to location to store  * result, and range checks for the result. Used to simplify fs specific  * option setting  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* option name */
name|int
modifier|*
name|value
decl_stmt|;
comment|/* where to stuff the value */
name|int
name|minimum
decl_stmt|;
comment|/* minimum for value */
name|int
name|maximum
decl_stmt|;
comment|/* maximum for value */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* option description */
block|}
name|option_t
typedef|;
end_typedef

begin_function_decl
name|void
name|apply_specfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_fsnodes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|inode_type
parameter_list|(
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_option
parameter_list|(
name|option_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|fsnode
modifier|*
name|walk_dir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffs_parse_opts
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|fsinfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffs_makefs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|,
name|fsinfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timespec
name|start_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * If -x is specified, we want to exclude nodes which do not appear  * in the spec file.  */
end_comment

begin_define
define|#
directive|define
name|FSNODE_EXCLUDE_P
parameter_list|(
name|opts
parameter_list|,
name|fsnode
parameter_list|)
define|\
value|((opts)->onlyspec != 0&& ((fsnode)->flags& FSNODE_F_HASSPEC) == 0)
end_define

begin_define
define|#
directive|define
name|DEBUG_TIME
value|0x00000001
end_define

begin_comment
comment|/* debug bits 1..3 unused at this time */
end_comment

begin_define
define|#
directive|define
name|DEBUG_WALK_DIR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DEBUG_WALK_DIR_NODE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DEBUG_WALK_DIR_LINKCHECK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DEBUG_DUMP_FSNODES
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DEBUG_DUMP_FSNODES_VERBOSE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_PARSE_OPTS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_MAKEFS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_VALIDATE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_CREATE_IMAGE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_SIZE_DIR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_SIZE_DIR_NODE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_SIZE_DIR_ADD_DIRENT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_POPULATE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_POPULATE_DIRBUF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_POPULATE_NODE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_WRITE_FILE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_WRITE_FILE_BLOCK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_MAKE_DIRBUF
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DEBUG_FS_WRITE_INODE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DEBUG_BUF_BREAD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DEBUG_BUF_BWRITE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DEBUG_BUF_GETBLK
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DEBUG_APPLY_SPECFILE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DEBUG_APPLY_SPECENTRY
value|0x08000000
end_define

begin_define
define|#
directive|define
name|TIMER_START
parameter_list|(
name|x
parameter_list|)
define|\
value|if (debug& DEBUG_TIME)			\ 		gettimeofday(&(x), NULL)
end_define

begin_define
define|#
directive|define
name|TIMER_RESULTS
parameter_list|(
name|x
parameter_list|,
name|d
parameter_list|)
define|\
value|if (debug& DEBUG_TIME) {			\ 		struct timeval end, td;			\ 		gettimeofday(&end, NULL);		\ 		timersub(&end,&(x),&td);		\ 		printf("%s took %ld.%06ld seconds\n",	\ 		    (d), td.tv_sec, td.tv_usec);	\ 	}
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_FSTYPE
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_FSTYPE
value|"ffs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	ffs specific settings  *	---------------------  */
end_comment

begin_define
define|#
directive|define
name|FFS_EI
end_define

begin_comment
comment|/* for opposite endian support in ffs headers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAKEFS_H */
end_comment

end_unit

