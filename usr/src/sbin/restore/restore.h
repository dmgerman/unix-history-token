begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)restore.h	5.9 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<ufs/dinode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/fs.h>
end_include

begin_comment
comment|/*  * Flags  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cvtflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert from old to new tape format */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set input block size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print out debugging info */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restore heirarchies */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restore by name instead of inode number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do not write the disk */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print out actions taken */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* always try to recover from tape errors */
end_comment

begin_comment
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dumpmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map of inodes on this dump tape */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|clrimap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map of inodes to be deleted */
end_comment

begin_decl_stmt
specifier|extern
name|ino_t
name|maxino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* highest numbered inode in this file system */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dumpnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of the dump on this tape */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|volno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current volume being read */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|ntrec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of TP_BSIZE records per tape block */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|dumptime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time that this dump begins */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|dumpdate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time that this dump was made */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|command
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* opration being performed */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|terminal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for the terminal input */
end_comment

begin_comment
comment|/*  * Each file in the file system is described by one of these entries  */
end_comment

begin_struct
struct|struct
name|entry
block|{
name|char
modifier|*
name|e_name
decl_stmt|;
comment|/* the current name of this entry */
name|u_char
name|e_namlen
decl_stmt|;
comment|/* length of this name */
name|char
name|e_type
decl_stmt|;
comment|/* type of this entry, see below */
name|short
name|e_flags
decl_stmt|;
comment|/* status flags, see below */
name|ino_t
name|e_ino
decl_stmt|;
comment|/* inode number in previous file sys */
name|long
name|e_index
decl_stmt|;
comment|/* unique index (for dumpped table) */
name|struct
name|entry
modifier|*
name|e_parent
decl_stmt|;
comment|/* pointer to parent directory (..) */
name|struct
name|entry
modifier|*
name|e_sibling
decl_stmt|;
comment|/* next element in this directory (.) */
name|struct
name|entry
modifier|*
name|e_links
decl_stmt|;
comment|/* hard links to this inode */
name|struct
name|entry
modifier|*
name|e_entries
decl_stmt|;
comment|/* for directories, their entries */
name|struct
name|entry
modifier|*
name|e_next
decl_stmt|;
comment|/* hash chain list */
block|}
struct|;
end_struct

begin_comment
comment|/* types */
end_comment

begin_define
define|#
directive|define
name|LEAF
value|1
end_define

begin_comment
comment|/* non-directory entry */
end_comment

begin_define
define|#
directive|define
name|NODE
value|2
end_define

begin_comment
comment|/* directory entry */
end_comment

begin_define
define|#
directive|define
name|LINK
value|4
end_define

begin_comment
comment|/* synthesized type, stripped by addentry */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|EXTRACT
value|0x0001
end_define

begin_comment
comment|/* entry is to be replaced from the tape */
end_comment

begin_define
define|#
directive|define
name|NEW
value|0x0002
end_define

begin_comment
comment|/* a new entry to be extracted */
end_comment

begin_define
define|#
directive|define
name|KEEP
value|0x0004
end_define

begin_comment
comment|/* entry is not to change */
end_comment

begin_define
define|#
directive|define
name|REMOVED
value|0x0010
end_define

begin_comment
comment|/* entry has been removed */
end_comment

begin_define
define|#
directive|define
name|TMPNAME
value|0x0020
end_define

begin_comment
comment|/* entry has been given a temporary name */
end_comment

begin_define
define|#
directive|define
name|EXISTED
value|0x0040
end_define

begin_comment
comment|/* directory already existed during extract */
end_comment

begin_comment
comment|/*  * functions defined on entry structs  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|entry
modifier|*
name|lookupino
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|entry
modifier|*
name|lookupname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|entry
modifier|*
name|lookupparent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|entry
modifier|*
name|addentry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|myname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|savename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|gentempname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|flagvalues
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ino_t
name|lowerbnd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ino_t
name|upperbnd
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NIL
value|((struct entry *)(0))
end_define

begin_comment
comment|/*  * Constants associated with entry structs  */
end_comment

begin_define
define|#
directive|define
name|HARDLINK
value|1
end_define

begin_define
define|#
directive|define
name|SYMLINK
value|2
end_define

begin_define
define|#
directive|define
name|TMPHDR
value|"RSTTMP"
end_define

begin_comment
comment|/*  * The entry describes the next file available on the tape  */
end_comment

begin_struct
struct|struct
name|context
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of file */
name|ino_t
name|ino
decl_stmt|;
comment|/* inumber of file */
name|struct
name|dinode
modifier|*
name|dip
decl_stmt|;
comment|/* pointer to inode */
name|char
name|action
decl_stmt|;
comment|/* action being taken on this file */
block|}
name|curfile
struct|;
end_struct

begin_comment
comment|/* actions */
end_comment

begin_define
define|#
directive|define
name|USING
value|1
end_define

begin_comment
comment|/* extracting from the tape */
end_comment

begin_define
define|#
directive|define
name|SKIP
value|2
end_define

begin_comment
comment|/* skipping */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN
value|3
end_define

begin_comment
comment|/* disposition or starting point is unknown */
end_comment

begin_comment
comment|/*  * Definitions for library routines operating on directories.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dirdesc
name|DIR
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|DIR
modifier|*
name|rst_opendir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|direct
modifier|*
name|rst_readdir
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Other exported routines  */
end_comment

begin_function_decl
specifier|extern
name|ino_t
name|psearch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ino_t
name|dirlookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|listfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|deletefile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|addfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|nodeupdates
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|verifyfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strncat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fgets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Useful macros  */
end_comment

begin_define
define|#
directive|define
name|MWORD
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|)
value|(m[(unsigned)(i-1)/NBBY])
end_define

begin_define
define|#
directive|define
name|MBIT
parameter_list|(
name|i
parameter_list|)
value|(1<<((unsigned)(i-1)%NBBY))
end_define

begin_define
define|#
directive|define
name|BIS
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|(MWORD(w,i) |=  MBIT(i))
end_define

begin_define
define|#
directive|define
name|BIC
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|(MWORD(w,i)&= ~MBIT(i))
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|(MWORD(w,i)& MBIT(i))
end_define

begin_define
define|#
directive|define
name|dprintf
value|if (dflag) fprintf
end_define

begin_define
define|#
directive|define
name|vprintf
value|if (vflag) fprintf
end_define

begin_define
define|#
directive|define
name|GOOD
value|1
end_define

begin_define
define|#
directive|define
name|FAIL
value|0
end_define

end_unit

