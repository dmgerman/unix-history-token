begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ftruncate emulations that work on some System V's.    This file is in the public domain.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|F_CHSIZE
end_ifdef

begin_function
name|int
name|ftruncate
parameter_list|(
name|int
name|fd
parameter_list|,
name|off_t
name|length
parameter_list|)
block|{
return|return
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_CHSIZE
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not F_CHSIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|F_FREESP
end_ifdef

begin_comment
comment|/* By William Kucharski<kucharsk@netcom.com>.  */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|ftruncate
parameter_list|(
name|int
name|fd
parameter_list|,
name|off_t
name|length
parameter_list|)
block|{
name|struct
name|flock
name|fl
decl_stmt|;
name|struct
name|stat
name|filebuf
decl_stmt|;
if|if
condition|(
name|fstat
argument_list|(
name|fd
argument_list|,
operator|&
name|filebuf
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|filebuf
operator|.
name|st_size
operator|<
name|length
condition|)
block|{
comment|/* Extend file length. */
if|if
condition|(
name|lseek
argument_list|(
name|fd
argument_list|,
operator|(
name|length
operator|-
literal|1
operator|)
argument_list|,
name|SEEK_SET
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Write a "0" byte. */
if|if
condition|(
name|write
argument_list|(
name|fd
argument_list|,
literal|""
argument_list|,
literal|1
argument_list|)
operator|!=
literal|1
condition|)
return|return
operator|-
literal|1
return|;
block|}
else|else
block|{
comment|/* Truncate length. */
name|fl
operator|.
name|l_whence
operator|=
literal|0
expr_stmt|;
name|fl
operator|.
name|l_len
operator|=
literal|0
expr_stmt|;
name|fl
operator|.
name|l_start
operator|=
name|length
expr_stmt|;
name|fl
operator|.
name|l_type
operator|=
name|F_WRLCK
expr_stmt|;
comment|/* write lock on file space */
comment|/* This relies on the *undocumented* F_FREESP argument to fcntl, 	 which truncates the file so that it ends at the position 	 indicated by fl.l_start.  Will minor miracles never cease?  */
if|if
condition|(
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_FREESP
argument_list|,
operator|&
name|fl
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not F_CHSIZE nor F_FREESP */
end_comment

begin_if
if|#
directive|if
name|HAVE_CHSIZE
end_if

begin_function
name|int
name|ftruncate
parameter_list|(
name|int
name|fd
parameter_list|,
name|off_t
name|length
parameter_list|)
block|{
return|return
name|chsize
argument_list|(
name|fd
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not F_CHSIZE nor F_FREESP nor HAVE_CHSIZE */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|ftruncate
parameter_list|(
name|int
name|fd
parameter_list|,
name|off_t
name|length
parameter_list|)
block|{
name|errno
operator|=
name|EIO
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_CHSIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not F_FREESP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not F_CHSIZE */
end_comment

end_unit

