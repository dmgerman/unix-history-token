begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dir_name_max(dir) does the same as pathconf(dir, _PC_NAME_MAX) */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_VERSION
end_ifdef

begin_function
name|long
name|dir_name_max
parameter_list|(
name|dir
parameter_list|)
name|char
modifier|*
name|dir
decl_stmt|;
block|{
return|return
name|pathconf
argument_list|(
name|dir
argument_list|,
name|_PC_NAME_MAX
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not _POSIX_VERSION */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LIMITS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DIRENT_H
end_ifdef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_DIRENT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_DIR_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_DIR_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_DIRENT_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAME_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXNAMLEN
end_ifdef

begin_define
define|#
directive|define
name|NAME_MAX
value|MAXNAMLEN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MAXNAMLEN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAXNAMELEN
end_ifdef

begin_define
define|#
directive|define
name|NAME_MAX
value|MAXNAMELEN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MAXNAMELEN */
end_comment

begin_define
define|#
directive|define
name|NAME_MAX
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MAXNAMELEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MAXNAMLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NAME_MAX */
end_comment

begin_function
name|long
name|dir_name_max
parameter_list|(
name|dir
parameter_list|)
name|char
modifier|*
name|dir
decl_stmt|;
block|{
return|return
name|NAME_MAX
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _POSIX_VERSION */
end_comment

end_unit

