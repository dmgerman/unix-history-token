begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)ndir.h	1.7	10/7/87	*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HP9K5
argument_list|)
end_if

begin_comment
comment|/* He should have included it instead of this, but prevent confusion */
end_comment

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* other */
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
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|long
name|d_ino
decl_stmt|;
comment|/* inode number of entry */
name|short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|short
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

begin_ifdef
ifdef|#
directive|ifdef
name|DIRSIZ
end_ifdef

begin_undef
undef|#
directive|undef
name|DIRSIZ
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIRSIZ */
end_comment

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
name|void
name|closedir
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* other */
end_comment

end_unit

