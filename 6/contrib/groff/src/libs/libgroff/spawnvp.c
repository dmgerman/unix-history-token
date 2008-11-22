begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2004    Free Software Foundation, Inc.      Written by: Keith Marshall (keith.d.marshall@ntlworld.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin St - Fifth Floor, Boston, MA 02110-1301, USA. */
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PROCESS_H
end_ifdef

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
expr|\
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
name|_UWIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|__EMX__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPAWN_FUNCTION_WRAPPERS
value|1
end_define

begin_comment
comment|/* Define the default mechanism, and messages, for error reporting  * (user may substitute a preferred alternative, by defining his own  *  implementation of the macros REPORT_ERROR and ARGV_MALLOC_ERROR,  *  in the header file `nonposix.h').  */
end_comment

begin_include
include|#
directive|include
file|"nonposix.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|REPORT_ERROR
end_ifndef

begin_define
define|#
directive|define
name|REPORT_ERROR
parameter_list|(
name|WHY
parameter_list|)
value|fprintf(stderr, "%s:%s\n", program_name, WHY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARGV_MALLOC_ERROR
end_ifndef

begin_define
define|#
directive|define
name|ARGV_MALLOC_ERROR
value|"malloc: Allocation for 'argv' failed"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|quote_arg
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|purge_quoted_args
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|spawnvp_wrapper
parameter_list|(
name|int
name|mode
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|/* Invoke the system `spawnvp' service    * enclosing the passed arguments in double quotes, as required,    * so that the (broken) default parsing in the MSVC runtime doesn't    * split them at whitespace. */
name|char
modifier|*
modifier|*
name|quoted_argv
decl_stmt|;
comment|/* used to build a quoted local copy of `argv' */
name|int
name|i
decl_stmt|;
comment|/* used as an index into `argv' or `quoted_argv' */
name|int
name|status
init|=
operator|-
literal|1
decl_stmt|;
comment|/* initialise return code, in case we fail */
name|int
name|argc
init|=
literal|0
decl_stmt|;
comment|/* initialise argument count; may be none  */
comment|/* First count the number of arguments    * which are actually present in the passed `argv'. */
if|if
condition|(
name|argv
condition|)
for|for
control|(
name|quoted_argv
operator|=
name|argv
init|;
operator|*
name|quoted_argv
condition|;
operator|++
name|argc
operator|,
operator|++
name|quoted_argv
control|)
empty_stmt|;
comment|/* If we do not now have an argument count,    * then we must fall through and fail. */
if|if
condition|(
name|argc
condition|)
block|{
comment|/* We do have at least one argument:      * We will use a copy of the `argv', in which to do the quoting,      * so we must allocate space for it. */
if|if
condition|(
operator|(
name|quoted_argv
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|malloc
argument_list|(
operator|++
name|argc
operator|*
sizeof|sizeof
argument_list|(
name|char
operator|*
operator|*
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* If we didn't get enough space,        * then complain, and bail out gracefully. */
name|REPORT_ERROR
argument_list|(
name|ARGV_MALLOC_ERROR
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Now copy the passed `argv' into our new vector,      * quoting its contents as required. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|argc
condition|;
name|i
operator|++
control|)
name|quoted_argv
index|[
name|i
index|]
operator|=
name|quote_arg
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* Invoke the MSVC `spawnvp' service      * passing our now appropriately quoted copy of `argv'. */
name|status
operator|=
name|spawnvp
argument_list|(
name|mode
argument_list|,
name|path
argument_list|,
name|quoted_argv
argument_list|)
expr_stmt|;
comment|/* Clean up our memory allocations      * for the quoted copy of `argv', which is no longer required. */
name|purge_quoted_args
argument_list|(
name|quoted_argv
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|quoted_argv
argument_list|)
expr_stmt|;
block|}
comment|/* Finally,    * return the status code returned by `spawnvp',    * or a failure code if we fell through. */
return|return
name|status
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MSDOS__ || _WIN32 */
end_comment

begin_comment
comment|/* spawnvp.c: end of file */
end_comment

end_unit

