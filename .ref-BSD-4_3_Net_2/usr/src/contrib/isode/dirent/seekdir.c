begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	seekdir -- reposition a directory stream  	last edit:	24-May-1987	D A Gwyn  	An unsuccessful seekdir() will in general alter the current 	directory position; beware.  	NOTE:	4.nBSD directory compaction makes seekdir()& telldir() 		practically impossible to do right.  Avoid using them! */
end_comment

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"usr.dirent.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|GETDENTS
end_ifndef

begin_function_decl
specifier|extern
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

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

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_comment
comment|/* Boolean data type */
end_comment

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_function
name|void
name|seekdir
parameter_list|(
name|dirp
parameter_list|,
name|loc
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* stream from opendir() */
specifier|register
name|off_t
name|loc
decl_stmt|;
comment|/* position from telldir() */
block|{
specifier|register
name|bool
name|rewind
decl_stmt|;
comment|/* "start over when stymied" flag */
if|if
condition|(
name|dirp
operator|==
name|NULL
operator|||
name|dirp
operator|->
name|dd_buf
operator|==
name|NULL
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return;
comment|/* invalid pointer */
block|}
comment|/* A (struct dirent)'s d_off is an invented quantity on 4.nBSD 	   NFS-supporting systems, so it is not safe to lseek() to it. */
comment|/* Monotonicity of d_off is heavily exploited in the following. */
comment|/* This algorithm is tuned for modest directory sizes.  For 	   huge directories, it might be more efficient to read blocks 	   until the first d_off is too large, then back up one block, 	   or even to use binary search on the directory blocks.  I 	   doubt that the extra code for that would be worthwhile. */
if|if
condition|(
name|dirp
operator|->
name|dd_loc
operator|>=
name|dirp
operator|->
name|dd_size
comment|/* invalid index */
operator|||
operator|(
operator|(
expr|struct
name|dirent
operator|*
operator|)
operator|&
name|dirp
operator|->
name|dd_buf
index|[
name|dirp
operator|->
name|dd_loc
index|]
operator|)
operator|->
name|d_off
operator|>
name|loc
comment|/* too far along in buffer */
condition|)
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
comment|/* reset to beginning of buffer */
comment|/* else save time by starting at current dirp->dd_loc */
for|for
control|(
name|rewind
operator|=
name|true
init|;
condition|;
control|)
block|{
specifier|register
name|struct
name|dirent
modifier|*
name|dp
decl_stmt|;
comment|/* See whether the matching entry is in the current buffer. */
if|if
condition|(
operator|(
name|dirp
operator|->
name|dd_loc
operator|<
name|dirp
operator|->
name|dd_size
comment|/* valid index */
operator|||
name|readdir
argument_list|(
name|dirp
argument_list|)
operator|!=
name|NULL
comment|/* next buffer read */
operator|&&
operator|(
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
operator|,
name|true
operator|)
comment|/* beginning of buffer set */
operator|)
operator|&&
operator|(
name|dp
operator|=
operator|(
expr|struct
name|dirent
operator|*
operator|)
operator|&
name|dirp
operator|->
name|dd_buf
index|[
name|dirp
operator|->
name|dd_loc
index|]
operator|)
operator|->
name|d_off
operator|<=
name|loc
comment|/* match possible in this buffer */
condition|)
block|{
for|for
control|(
comment|/* dp initialized above */
init|;
operator|(
name|char
operator|*
operator|)
name|dp
operator|<
operator|&
name|dirp
operator|->
name|dd_buf
index|[
name|dirp
operator|->
name|dd_size
index|]
condition|;
name|dp
operator|=
operator|(
expr|struct
name|dirent
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|dp
operator|+
name|dp
operator|->
name|d_reclen
operator|)
control|)
if|if
condition|(
name|dp
operator|->
name|d_off
operator|==
name|loc
condition|)
block|{
comment|/* found it! */
name|dirp
operator|->
name|dd_loc
operator|=
operator|(
name|char
operator|*
operator|)
name|dp
operator|-
name|dirp
operator|->
name|dd_buf
expr_stmt|;
return|return;
block|}
name|rewind
operator|=
name|false
expr_stmt|;
comment|/* no point in backing up later */
name|dirp
operator|->
name|dd_loc
operator|=
name|dirp
operator|->
name|dd_size
expr_stmt|;
comment|/* set end of buffer */
block|}
elseif|else
comment|/* whole buffer past matching entry */
if|if
condition|(
operator|!
name|rewind
condition|)
block|{
comment|/* no point in searching further */
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return;
comment|/* no entry at specified loc */
block|}
else|else
block|{
comment|/* rewind directory and start over */
name|rewind
operator|=
name|false
expr_stmt|;
comment|/* but only once! */
name|dirp
operator|->
name|dd_loc
operator|=
name|dirp
operator|->
name|dd_size
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
operator|(
name|off_t
operator|)
literal|0
argument_list|,
name|SEEK_SET
argument_list|)
operator|!=
literal|0
condition|)
return|return;
comment|/* errno already set (EBADF) */
if|if
condition|(
name|loc
operator|==
literal|0
condition|)
return|return;
comment|/* save time */
block|}
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|_seekdir_stub
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

