begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: ndir.h,v 3.0 1991/09/09 20:23:31 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_NDIR
end_ifdef

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_NDIR
end_ifdef

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_DIR
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_DIRENT
end_ifdef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_define
define|#
directive|define
name|direct
value|dirent
end_define

begin_else
else|#
directive|else
end_else

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

begin_decl_stmt
specifier|extern
name|DIR
modifier|*
name|opendir
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|direct
modifier|*
name|readdir
name|_
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|telldir
name|_
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|seekdir
name|_
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
value|seekdir((dirp), (long)0)
end_define

begin_decl_stmt
specifier|extern
name|void
name|closedir
name|_
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

