begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*<dir.h> -- definitions for 4.2BSD-compatible directory access  	last edit:	09-Jul-1983	D A Gwyn */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|FAB$C_BID
end_ifndef

begin_include
include|#
directive|include
file|<fab.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NAM$C_BID
end_ifndef

begin_include
include|#
directive|include
file|<nam.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RMS$_SUC
end_ifndef

begin_include
include|#
directive|include
file|<rmsdef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"dir.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|512
end_define

begin_comment
comment|/* size of directory block */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|(DIR$S_NAME + 7)
end_define

begin_comment
comment|/* 80 plus room for version #.  */
end_comment

begin_define
define|#
directive|define
name|MAXFULLSPEC
value|NAM$C_MAXRSS
end_define

begin_comment
comment|/* Maximum full spec */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXNAMLEN
value|15
end_define

begin_comment
comment|/* maximum filename length */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_comment
comment|/* NOTE:  MAXNAMLEN must be one less than a multiple of 4 */
end_comment

begin_struct
struct|struct
name|direct
comment|/* data from readdir() */
block|{
name|long
name|d_ino
decl_stmt|;
comment|/* inode number of entry */
name|unsigned
name|short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|unsigned
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
comment|/* name of file */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dd_fd
decl_stmt|;
comment|/* file descriptor */
name|int
name|dd_loc
decl_stmt|;
comment|/* offset in block */
name|int
name|dd_size
decl_stmt|;
comment|/* amount of valid data */
name|char
name|dd_buf
index|[
name|DIRBLKSIZ
index|]
decl_stmt|;
comment|/* directory block */
block|}
name|DIR
typedef|;
end_typedef

begin_comment
comment|/* stream data from opendir() */
end_comment

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

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
value|seekdir( dirp, 0L )
end_define

end_unit

