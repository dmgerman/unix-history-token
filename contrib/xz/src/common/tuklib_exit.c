begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_exit.c
end_comment

begin_comment
comment|/// \brief      Close stdout and stderr, and exit
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"tuklib_common.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"tuklib_gettext.h"
end_include

begin_include
include|#
directive|include
file|"tuklib_progname.h"
end_include

begin_include
include|#
directive|include
file|"tuklib_exit.h"
end_include

begin_function
specifier|extern
name|void
name|tuklib_exit
parameter_list|(
name|int
name|status
parameter_list|,
name|int
name|err_status
parameter_list|,
name|int
name|show_error
parameter_list|)
block|{
if|if
condition|(
name|status
operator|!=
name|err_status
condition|)
block|{
comment|// Close stdout. If something goes wrong,
comment|// print an error message to stderr.
specifier|const
name|int
name|ferror_err
init|=
name|ferror
argument_list|(
name|stdout
argument_list|)
decl_stmt|;
specifier|const
name|int
name|fclose_err
init|=
name|fclose
argument_list|(
name|stdout
argument_list|)
decl_stmt|;
if|if
condition|(
name|ferror_err
operator|||
name|fclose_err
condition|)
block|{
name|status
operator|=
name|err_status
expr_stmt|;
comment|// If it was fclose() that failed, we have the reason
comment|// in errno. If only ferror() indicated an error,
comment|// we have no idea what the reason was.
if|if
condition|(
name|show_error
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s: %s\n"
argument_list|,
name|progname
argument_list|,
name|_
argument_list|(
literal|"Writing to standard "
literal|"output failed"
argument_list|)
argument_list|,
name|fclose_err
condition|?
name|strerror
argument_list|(
name|errno
argument_list|)
else|:
name|_
argument_list|(
literal|"Unknown error"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|status
operator|!=
name|err_status
condition|)
block|{
comment|// Close stderr. If something goes wrong, there's
comment|// nothing where we could print an error message.
comment|// Just set the exit status.
specifier|const
name|int
name|ferror_err
init|=
name|ferror
argument_list|(
name|stderr
argument_list|)
decl_stmt|;
specifier|const
name|int
name|fclose_err
init|=
name|fclose
argument_list|(
name|stderr
argument_list|)
decl_stmt|;
if|if
condition|(
name|fclose_err
operator|||
name|ferror_err
condition|)
name|status
operator|=
name|err_status
expr_stmt|;
block|}
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

