begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	telldir -- report directory stream position  	last edit:	25-Apr-1987	D A Gwyn  	NOTE:	4.nBSD directory compaction makes seekdir()& telldir() 		practically impossible to do right.  Avoid using them! */
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
name|SEEK_CUR
end_ifndef

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|off_t
name|telldir
parameter_list|(
name|dirp
parameter_list|)
comment|/* return offset of next entry */
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* stream from opendir() */
block|{
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
return|return
operator|-
literal|1
return|;
comment|/* invalid pointer */
block|}
if|if
condition|(
name|dirp
operator|->
name|dd_loc
operator|<
name|dirp
operator|->
name|dd_size
condition|)
comment|/* valid index */
return|return
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
return|;
else|else
comment|/* beginning of next directory block */
return|return
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
name|SEEK_CUR
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|_telldir_stub
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

