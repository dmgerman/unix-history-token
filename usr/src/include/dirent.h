begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dirent.h	5.9 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIRENT_
end_ifndef

begin_define
define|#
directive|define
name|_DIRENT_
end_define

begin_comment
comment|/*  * A directory entry has a struct direct at the front of it, containing its  * inode number, the length of the entry, and the length of the name  * contained in the entry.  These are followed by the name padded to a 4  * byte boundary with null bytes.  All names are guaranteed null terminated.  * The maximum length of a name in a directory is MAXNAMLEN.  */
end_comment

begin_struct
struct|struct
name|dirent
block|{
name|u_long
name|d_fileno
decl_stmt|;
comment|/* file number of entry */
name|u_short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|u_short
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
name|char
name|d_name
index|[
literal|255
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
else|#
directive|else
define|#
directive|define
name|MAXNAMLEN
value|255
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|DIR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|d_ino
value|d_fileno
end_define

begin_comment
comment|/* backward compatibility */
end_comment

begin_comment
comment|/* definitions for library routines operating on directories. */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|1024
end_define

begin_comment
comment|/* structure describing an open directory. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dirdesc
block|{
name|int
name|dd_fd
decl_stmt|;
comment|/* file descriptor associated with directory */
name|long
name|dd_loc
decl_stmt|;
comment|/* offset in current buffer */
name|long
name|dd_size
decl_stmt|;
comment|/* amount of data returned by getdirentries */
name|char
modifier|*
name|dd_buf
decl_stmt|;
comment|/* data buffer */
name|int
name|dd_len
decl_stmt|;
comment|/* size of data buffer */
name|long
name|dd_seek
decl_stmt|;
comment|/* magic cookie returned by getdirentries */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|DIR
modifier|*
name|opendir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rewindir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|closedir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_function_decl
specifier|extern
name|long
name|telldir
parameter_list|(
specifier|const
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|seekdir
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|scandir
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
expr|struct
name|direct
operator|*
operator|(
operator|*
index|[]
operator|)
argument_list|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|direct
operator|*
argument_list|)
argument_list|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|alphasort
parameter_list|(
specifier|const
name|struct
name|direct
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|direct
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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
name|dirent
modifier|*
name|readdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rewinddir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|closedir
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

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
name|int
name|scandir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alphasort
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIRENT_ */
end_comment

end_unit

