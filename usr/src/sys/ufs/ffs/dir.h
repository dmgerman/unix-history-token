begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)dir.h	7.7 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIR_
end_ifndef

begin_define
define|#
directive|define
name|_DIR_
end_define

begin_comment
comment|/*  * A directory consists of some number of blocks of DIRBLKSIZ  * bytes, where DIRBLKSIZ is chosen such that it can be transferred  * to disk in a single atomic operation (e.g. 512 bytes on most machines).  *  * Each DIRBLKSIZ byte block contains some number of directory entry  * structures, which are of variable length.  Each directory entry has  * a struct direct at the front of it, containing its inode number,  * the length of the entry, and the length of the name contained in  * the entry.  These are followed by the name padded to a 4 byte boundary  * with null bytes.  All names are guaranteed null terminated.  * The maximum length of a name in a directory is MAXNAMLEN.  *  * The macro DIRSIZ(dp) gives the amount of space required to represent  * a directory entry.  Free space in a directory is represented by  * entries which have dp->d_reclen> DIRSIZ(dp).  All DIRBLKSIZ bytes  * in a directory block are claimed by the directory entries.  This  * usually results in the last entry in a directory having a large  * dp->d_reclen.  When entries are deleted from a directory, the  * space is returned to the previous entry in the same directory  * block by increasing its dp->d_reclen.  If the first entry of  * a directory block is free, then its dp->d_ino is set to 0.  * Entries other than the first in a directory do not normally have  * dp->d_ino set to 0.  */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|DEV_BSIZE
end_define

begin_define
define|#
directive|define
name|MAXNAMLEN
value|255
end_define

begin_struct
struct|struct
name|direct
block|{
name|u_long
name|d_ino
decl_stmt|;
comment|/* inode number of entry */
name|u_short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|u_short
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name with length<= MAXNAMLEN */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The DIRSIZ macro gives the minimum record length which will hold  * the directory entry.  This requires the amount of space in struct direct  * without the d_name field, plus enough space for the name with a terminating  * null byte (dp->d_namlen+1), rounded up to a 4 byte boundary.  */
end_comment

begin_undef
undef|#
directive|undef
name|DIRSIZ
end_undef

begin_define
define|#
directive|define
name|DIRSIZ
parameter_list|(
name|dp
parameter_list|)
define|\
value|((sizeof (struct direct) - (MAXNAMLEN+1)) + (((dp)->d_namlen+1 + 3)&~ 3))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Template for manipulating directories.  * Should use struct direct's, but the name field  * is MAXNAMLEN - 1, and this just won't do.  */
end_comment

begin_struct
struct|struct
name|dirtemplate
block|{
name|u_long
name|dot_ino
decl_stmt|;
name|short
name|dot_reclen
decl_stmt|;
name|short
name|dot_namlen
decl_stmt|;
name|char
name|dot_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* must be multiple of 4 */
name|u_long
name|dotdot_ino
decl_stmt|;
name|short
name|dotdot_reclen
decl_stmt|;
name|short
name|dotdot_namlen
decl_stmt|;
name|char
name|dotdot_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* ditto */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following information should be obtained from<dirent.h>  * and is provided solely (and temporarily) for backward compatibility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|d_fileno
value|d_ino
end_define

begin_comment
comment|/* compatibility with POSIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_BSIZE
end_ifndef

begin_define
define|#
directive|define
name|DEV_BSIZE
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for library routines operating on directories.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dirdesc
block|{
name|int
name|dd_fd
decl_stmt|;
name|long
name|dd_loc
decl_stmt|;
name|long
name|dd_size
decl_stmt|;
name|char
name|dd_buf
index|[
name|DIRBLKSIZ
index|]
decl_stmt|;
block|}
name|DIR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dirfd
parameter_list|(
name|dirp
parameter_list|)
value|((dirp)->dd_fd)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|DIR
modifier|*
name|opendir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|direct
modifier|*
name|readdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|telldir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|seekdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|closedir
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|long
name|_rewinddir
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
define|\
value|_seekdir((dirp), _rewinddir); \ 	_rewinddir = telldir(dirp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIR_ */
end_comment

end_unit

