begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WITH_IRIX_PROJECT
argument_list|)
operator|||
name|defined
argument_list|(
name|WITH_IRIX_JOBS
argument_list|)
operator|||
name|defined
argument_list|(
name|WITH_IRIX_ARRAY
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_IRIX_PROJECT
end_ifdef

begin_include
include|#
directive|include
file|<proj.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_IRIX_PROJECT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_IRIX_JOBS
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_IRIX_AUDIT
end_ifdef

begin_include
include|#
directive|include
file|<sat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_IRIX_AUDIT */
end_comment

begin_function
name|void
name|irix_setusercontext
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|WITH_IRIX_PROJECT
name|prid_t
name|projid
decl_stmt|;
endif|#
directive|endif
comment|/* WITH_IRIX_PROJECT */
ifdef|#
directive|ifdef
name|WITH_IRIX_JOBS
name|jid_t
name|jid
init|=
literal|0
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|WITH_IRIX_ARRAY
name|int
name|jid
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
comment|/* WITH_IRIX_ARRAY */
endif|#
directive|endif
comment|/* WITH_IRIX_JOBS */
ifdef|#
directive|ifdef
name|WITH_IRIX_JOBS
name|jid
operator|=
name|jlimit_startjob
argument_list|(
name|pw
operator|->
name|pw_name
argument_list|,
name|pw
operator|->
name|pw_uid
argument_list|,
literal|"interactive"
argument_list|)
expr_stmt|;
if|if
condition|(
name|jid
operator|==
operator|-
literal|1
condition|)
name|fatal
argument_list|(
literal|"Failed to create job container: %.100s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* WITH_IRIX_JOBS */
ifdef|#
directive|ifdef
name|WITH_IRIX_ARRAY
comment|/* initialize array session */
if|if
condition|(
name|jid
operator|==
literal|0
operator|&&
name|newarraysess
argument_list|()
operator|!=
literal|0
condition|)
name|fatal
argument_list|(
literal|"Failed to set up new array session: %.100s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* WITH_IRIX_ARRAY */
ifdef|#
directive|ifdef
name|WITH_IRIX_PROJECT
comment|/* initialize irix project info */
if|if
condition|(
operator|(
name|projid
operator|=
name|getdfltprojuser
argument_list|(
name|pw
operator|->
name|pw_name
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|debug
argument_list|(
literal|"Failed to get project id, using projid 0"
argument_list|)
expr_stmt|;
name|projid
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|setprid
argument_list|(
name|projid
argument_list|)
condition|)
name|fatal
argument_list|(
literal|"Failed to initialize project %d for %s: %.100s"
argument_list|,
operator|(
name|int
operator|)
name|projid
argument_list|,
name|pw
operator|->
name|pw_name
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* WITH_IRIX_PROJECT */
ifdef|#
directive|ifdef
name|WITH_IRIX_AUDIT
if|if
condition|(
name|sysconf
argument_list|(
name|_SC_AUDIT
argument_list|)
condition|)
block|{
name|debug
argument_list|(
literal|"Setting sat id to %d"
argument_list|,
operator|(
name|int
operator|)
name|pw
operator|->
name|pw_uid
argument_list|)
expr_stmt|;
if|if
condition|(
name|satsetid
argument_list|(
name|pw
operator|->
name|pw_uid
argument_list|)
condition|)
name|debug
argument_list|(
literal|"error setting satid: %.100s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* WITH_IRIX_AUDIT */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(WITH_IRIX_PROJECT) || defined(WITH_IRIX_JOBS) || defined(WITH_IRIX_ARRAY) */
end_comment

end_unit

