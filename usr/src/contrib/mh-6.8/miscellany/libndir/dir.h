begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dir.h	4.4	82/07/25	*/
end_comment

begin_comment
comment|/*  * A directory consists of some number of blocks of DIRBLKSIZ  * bytes, where DIRBLKSIZ is chosen such that it can be transferred  * to disk in a single atomic operation (e.g. 512 bytes on most machines).  *  * Each DIRBLKSIZ byte block contains some number of directory entry  * structures, which are of variable length.  Each directory entry has  * a struct direct at the front of it, containing its inode number,  * the length of the entry, and the length of the name contained in  * the entry.  These are followed by the name padded to a 4 byte boundary  * with null bytes.  All names are guaranteed null terminated.  * The maximum length of a name in a directory is MAXNAMLEN.  *  * The macro DIRSIZ(dp) gives the amount of space required to represent  * a directory entry.  Free space in a directory is represented by  * entries which have dp->d_reclen>= DIRSIZ(dp).  All DIRBLKSIZ bytes  * in a directory block are claimed by the directory entries.  This  * usually results in the last entry in a directory having a large  * dp->d_reclen.  When entries are deleted from a directory, the  * space is returned to the previous entry in the same directory  * block by increasing its dp->d_reclen.  If the first entry of  * a directory block is free, then its dp->d_ino is set to 0.  * Entries other than the first in a directory do not normally have  * dp->d_ino set to 0.  */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|512
end_define

begin_define
define|#
directive|define
name|MAXNAMLEN
value|255
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|u_long
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* name must be no longer than this */
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

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

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

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
value|seekdir((dirp), (long)0)
end_define

begin_function_decl
specifier|extern
name|void
name|closedir
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

