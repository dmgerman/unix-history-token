begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getpwd.c - get the working directory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_STAT_H
end_if

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prototype these in case the system headers don't provide them. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|getpwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_comment
comment|/* Virtually every UN*X system now in common use (except for pre-4.3-tahoe    BSD systems) now provides getcwd as called for by POSIX.  Allow for    the few exceptions to the general rule here.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GETCWD
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_GETWD
argument_list|)
end_if

begin_define
define|#
directive|define
name|getcwd
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|)
value|getwd(buf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|GUESSPATHLEN
value|(MAXPATHLEN + 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GUESSPATHLEN
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|)
operator|)
end_if

begin_comment
comment|/* Get the working directory.  Use the PWD environment variable if it's    set correctly, since this is faster and gives more uniform answers    to the user.  Yield the working directory if successful; otherwise,    yield 0 and set errno.  */
end_comment

begin_function
name|char
modifier|*
name|getpwd
parameter_list|()
block|{
specifier|static
name|char
modifier|*
name|pwd
decl_stmt|;
specifier|static
name|int
name|failure_errno
decl_stmt|;
name|char
modifier|*
name|p
init|=
name|pwd
decl_stmt|;
name|size_t
name|s
decl_stmt|;
name|struct
name|stat
name|dotstat
decl_stmt|,
name|pwdstat
decl_stmt|;
if|if
condition|(
operator|!
name|p
operator|&&
operator|!
operator|(
name|errno
operator|=
name|failure_errno
operator|)
condition|)
block|{
if|if
condition|(
operator|!
operator|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"PWD"
argument_list|)
operator|)
operator|!=
literal|0
operator|&&
operator|*
name|p
operator|==
literal|'/'
operator|&&
name|stat
argument_list|(
name|p
argument_list|,
operator|&
name|pwdstat
argument_list|)
operator|==
literal|0
operator|&&
name|stat
argument_list|(
literal|"."
argument_list|,
operator|&
name|dotstat
argument_list|)
operator|==
literal|0
operator|&&
name|dotstat
operator|.
name|st_ino
operator|==
name|pwdstat
operator|.
name|st_ino
operator|&&
name|dotstat
operator|.
name|st_dev
operator|==
name|pwdstat
operator|.
name|st_dev
operator|)
condition|)
comment|/* The shortcut didn't work.  Try the slow, ``sure'' way.  */
for|for
control|(
name|s
operator|=
name|GUESSPATHLEN
init|;
operator|!
name|getcwd
argument_list|(
name|p
operator|=
name|xmalloc
argument_list|(
name|s
argument_list|)
argument_list|,
name|s
argument_list|)
condition|;
name|s
operator|*=
literal|2
control|)
block|{
name|int
name|e
init|=
name|errno
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ERANGE
if|if
condition|(
name|e
operator|!=
name|ERANGE
condition|)
endif|#
directive|endif
block|{
name|errno
operator|=
name|failure_errno
operator|=
name|e
expr_stmt|;
name|p
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
comment|/* Cache the result.  This assumes that the program does 	 not invoke chdir between calls to getpwd.  */
name|pwd
operator|=
name|p
expr_stmt|;
block|}
return|return
name|p
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VMS || _WIN32&& !__CYGWIN__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|getpwd
parameter_list|()
block|{
specifier|static
name|char
modifier|*
name|pwd
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|pwd
condition|)
name|pwd
operator|=
name|getcwd
argument_list|(
name|xmalloc
argument_list|(
name|MAXPATHLEN
operator|+
literal|1
argument_list|)
argument_list|,
name|MAXPATHLEN
operator|+
literal|1
ifdef|#
directive|ifdef
name|VMS
argument_list|,
literal|0
endif|#
directive|endif
argument_list|)
expr_stmt|;
return|return
name|pwd
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS || _WIN32&& !__CYGWIN__ */
end_comment

end_unit

