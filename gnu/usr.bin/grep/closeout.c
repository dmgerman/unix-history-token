begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* closeout.c - close standard output    Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_if
if|#
directive|if
name|ENABLE_NLS
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|Text
parameter_list|)
value|gettext (Text)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_
parameter_list|(
name|Text
parameter_list|)
value|Text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
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

begin_include
include|#
directive|include
file|"closeout.h"
end_include

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"quotearg.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|"__fpending.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|default_exit_status
init|=
name|EXIT_FAILURE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|file_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the value to be used for the exit status when close_stdout is called.    This is useful when it is not convenient to call close_stdout_status,    e.g., when close_stdout is called via atexit.  */
end_comment

begin_function
name|void
name|close_stdout_set_status
parameter_list|(
name|int
name|status
parameter_list|)
block|{
name|default_exit_status
operator|=
name|status
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Set the file name to be reported in the event an error is detected    by close_stdout_status.  */
end_comment

begin_function
name|void
name|close_stdout_set_file_name
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
block|{
name|file_name
operator|=
name|file
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Close standard output, exiting with status STATUS on failure.    If a program writes *anything* to stdout, that program should `fflush'    stdout and make sure that it succeeds before exiting.  Otherwise,    suppose that you go to the extreme of checking the return status    of every function that does an explicit write to stdout.  The last    printf can succeed in writing to the internal stream buffer, and yet    the fclose(stdout) could still fail (due e.g., to a disk full error)    when it tries to write out that buffered data.  Thus, you would be    left with an incomplete output file and the offending program would    exit successfully.     FIXME: note the fflush suggested above is implicit in the fclose    we actually do below.  Consider doing only the fflush and/or using    setvbuf to inhibit buffering.     Besides, it's wasteful to check the return value from every call    that writes to stdout -- just let the internal stream state record    the failure.  That's what the ferror test is checking below.     It's important to detect such failures and exit nonzero because many    tools (most notably `make' and other build-management systems) depend    on being able to detect failure in other tools via their exit status.  */
end_comment

begin_function
name|void
name|close_stdout_status
parameter_list|(
name|int
name|status
parameter_list|)
block|{
name|int
name|e
init|=
name|ferror
argument_list|(
name|stdout
argument_list|)
condition|?
literal|0
else|:
operator|-
literal|1
decl_stmt|;
if|#
directive|if
literal|0
block|if (__fpending (stdout) == 0)     return;
endif|#
directive|endif
if|if
condition|(
name|fclose
argument_list|(
name|stdout
argument_list|)
operator|!=
literal|0
condition|)
name|e
operator|=
name|errno
expr_stmt|;
if|if
condition|(
literal|0
operator|<
name|e
condition|)
block|{
name|char
specifier|const
modifier|*
name|write_error
init|=
name|_
argument_list|(
literal|"write error"
argument_list|)
decl_stmt|;
if|if
condition|(
name|file_name
condition|)
name|error
argument_list|(
name|status
argument_list|,
name|e
argument_list|,
literal|"%s: %s"
argument_list|,
name|quotearg_colon
argument_list|(
name|file_name
argument_list|)
argument_list|,
name|write_error
argument_list|)
expr_stmt|;
else|else
name|error
argument_list|(
name|status
argument_list|,
name|e
argument_list|,
literal|"%s"
argument_list|,
name|write_error
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Close standard output, exiting with status EXIT_FAILURE on failure.  */
end_comment

begin_function
name|void
name|close_stdout
parameter_list|(
name|void
parameter_list|)
block|{
name|close_stdout_status
argument_list|(
name|default_exit_status
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

