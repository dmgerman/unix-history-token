begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* prsvunix.c */
end_comment

begin_comment
comment|/* This file contains the UNIX-specific parts of the "elvprsv" program. */
end_comment

begin_if
if|#
directive|if
name|OSK
end_if

begin_define
define|#
directive|define
name|ELVPRSV
end_define

begin_include
include|#
directive|include
file|"osk.c"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__386BSD__
end_ifndef

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This variable is used to add extra error messages for mail sent to root */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function returns the login name of the owner of a file */
end_comment

begin_function
name|char
modifier|*
name|ownername
parameter_list|(
name|filename
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* name of a file */
block|{
name|struct
name|stat
name|st
decl_stmt|;
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
comment|/* stat the file, to get its uid */
if|if
condition|(
name|stat
argument_list|(
name|filename
argument_list|,
operator|&
name|st
argument_list|)
operator|<
literal|0
condition|)
block|{
name|ps
operator|=
literal|"stat() failed"
expr_stmt|;
return|return
literal|"root"
return|;
block|}
comment|/* get the /etc/passwd entry for that user */
name|pw
operator|=
name|getpwuid
argument_list|(
name|st
operator|.
name|st_uid
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pw
condition|)
block|{
name|ps
operator|=
literal|"uid not found in password file"
expr_stmt|;
return|return
literal|"root"
return|;
block|}
comment|/* return the user's name */
return|return
name|pw
operator|->
name|pw_name
return|;
block|}
end_function

begin_comment
comment|/* This function sends a mail message to a given user, saying that a file  * has been preserved.  */
end_comment

begin_function
name|void
name|mail
parameter_list|(
name|user
parameter_list|,
name|file
parameter_list|,
name|when
parameter_list|)
name|char
modifier|*
name|user
decl_stmt|;
comment|/* name of user who should receive the mail */
name|char
modifier|*
name|file
decl_stmt|;
comment|/* name of original text file that was preserved */
name|char
modifier|*
name|when
decl_stmt|;
comment|/* description of why the file was preserved */
block|{
name|char
name|cmd
index|[
literal|80
index|]
decl_stmt|;
comment|/* buffer used for constructing a "mail" command */
name|FILE
modifier|*
name|m
decl_stmt|,
modifier|*
name|popen
argument_list|()
decl_stmt|;
comment|/* stream used for giving text to the "mail" program */
name|char
modifier|*
name|base
decl_stmt|;
comment|/* basename of the file */
comment|/* separate the directory name from the basename. */
for|for
control|(
name|base
operator|=
name|file
operator|+
name|strlen
argument_list|(
name|file
argument_list|)
init|;
operator|--
name|base
operator|>
name|file
operator|&&
operator|*
name|base
operator|!=
name|SLASH
condition|;
control|)
block|{ 	}
if|if
condition|(
operator|*
name|base
operator|==
name|SLASH
condition|)
block|{
operator|*
name|base
operator|++
operator|=
literal|'\0'
expr_stmt|;
block|}
comment|/* for anonymous buffers, pretend the name was "foo" */
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|base
argument_list|,
literal|"*"
argument_list|)
condition|)
block|{
name|base
operator|=
literal|"foo"
expr_stmt|;
block|}
comment|/* open a pipe to the "mail" program */
if|#
directive|if
name|OSK
name|sprintf
argument_list|(
name|cmd
argument_list|,
literal|"mail \"-s=%s preserved!\" %s"
argument_list|,
name|base
argument_list|,
name|user
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* ANY_UNIX */
name|sprintf
argument_list|(
name|cmd
argument_list|,
literal|"mail %s>/dev/null 2>/dev/null"
argument_list|,
name|user
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m
operator|=
name|popen
argument_list|(
name|cmd
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m
condition|)
block|{
comment|/* Can't send mail!  Hope the user figures it out. */
return|return;
block|}
comment|/* Tell the user that the file was preserved */
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"A version of your file \"%s%c%s\"\n"
argument_list|,
name|file
argument_list|,
name|SLASH
argument_list|,
name|base
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"was preserved when %s.\n"
argument_list|,
name|when
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"To recover this file, do the following:\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
if|#
directive|if
name|OSK
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"     chd %s\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* ANY_UNIX */
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"     cd %s\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"     elvisrecover %s\n"
argument_list|,
name|base
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"With fond wishes for a speedy recovery,\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"                                    Elvis\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ps
condition|)
block|{
name|fprintf
argument_list|(
name|m
argument_list|,
literal|"\nP.S. %s\n"
argument_list|,
name|ps
argument_list|)
expr_stmt|;
name|ps
operator|=
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
block|}
comment|/* close the stream */
name|pclose
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

