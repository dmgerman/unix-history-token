begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 david d `zoo' zuhn  * Copyright (c) 1994 Free Software Foundation, Inc.  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with this  CVS source distribution.  *   * version.c - the CVS version number  */
end_comment

begin_include
include|#
directive|include
file|"cvs.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|version_string
init|=
literal|"Concurrent Versions System (CVS) 1.11"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|config_string
init|=
literal|" (client/server)\n"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|config_string
init|=
literal|" (client)\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|config_string
init|=
literal|" (server)\n"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|config_string
init|=
literal|"\n"
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

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|version_usage
index|[]
init|=
block|{
literal|"Usage: %s %s\n"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|version
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|argc
operator|==
operator|-
literal|1
condition|)
name|usage
argument_list|(
name|version_usage
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
if|if
condition|(
name|client_active
condition|)
operator|(
name|void
operator|)
name|fputs
argument_list|(
literal|"Client: "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Having the year here is a good idea, so people have        some idea of how long ago their version of CVS was        released.  */
operator|(
name|void
operator|)
name|fputs
argument_list|(
name|version_string
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fputs
argument_list|(
name|config_string
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
if|if
condition|(
name|client_active
condition|)
block|{
operator|(
name|void
operator|)
name|fputs
argument_list|(
literal|"Server: "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|start_server
argument_list|()
expr_stmt|;
if|if
condition|(
name|supported_request
argument_list|(
literal|"version"
argument_list|)
condition|)
name|send_to_server
argument_list|(
literal|"version\012"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
block|{
name|send_to_server
argument_list|(
literal|"noop\012"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"(unknown)\n"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
name|err
operator|=
name|get_responses_and_close
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|err
return|;
block|}
end_function

end_unit

