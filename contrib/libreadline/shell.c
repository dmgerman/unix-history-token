begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* shell.c -- readline utility functions that are normally provided by 	      bash when readline is linked as part of the shell. */
end_comment

begin_comment
comment|/* Copyright (C) 1997 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 1, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_define
define|#
directive|define
name|READLINE_LIBRARY
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
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
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_MINIX
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STDLIB_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ansi_stdlib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDLIB_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRING_H */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHELL
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|savestring
end_ifdef

begin_undef
undef|#
directive|undef
name|savestring
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Backwards compatibility, now that savestring has been removed from    all `public' readline header files. */
end_comment

begin_function
name|char
modifier|*
name|savestring
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|strcpy
argument_list|(
name|xmalloc
argument_list|(
literal|1
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
argument_list|)
argument_list|,
operator|(
name|s
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Does shell-like quoting using single quotes. */
end_comment

begin_function
name|char
modifier|*
name|single_quote
parameter_list|(
name|string
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
block|{
specifier|register
name|int
name|c
decl_stmt|;
name|char
modifier|*
name|result
decl_stmt|,
modifier|*
name|r
decl_stmt|,
modifier|*
name|s
decl_stmt|;
name|result
operator|=
operator|(
name|char
operator|*
operator|)
name|xmalloc
argument_list|(
literal|3
operator|+
operator|(
literal|3
operator|*
name|strlen
argument_list|(
name|string
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|r
operator|=
name|result
expr_stmt|;
operator|*
name|r
operator|++
operator|=
literal|'\''
expr_stmt|;
for|for
control|(
name|s
operator|=
name|string
init|;
name|s
operator|&&
operator|(
name|c
operator|=
operator|*
name|s
operator|)
condition|;
name|s
operator|++
control|)
block|{
operator|*
name|r
operator|++
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'\''
condition|)
block|{
operator|*
name|r
operator|++
operator|=
literal|'\\'
expr_stmt|;
comment|/* insert escaped single quote */
operator|*
name|r
operator|++
operator|=
literal|'\''
expr_stmt|;
operator|*
name|r
operator|++
operator|=
literal|'\''
expr_stmt|;
comment|/* start new quoted string */
block|}
block|}
operator|*
name|r
operator|++
operator|=
literal|'\''
expr_stmt|;
operator|*
name|r
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Set the environment variables LINES and COLUMNS to lines and cols,    respectively. */
end_comment

begin_function
name|void
name|set_lines_and_columns
parameter_list|(
name|lines
parameter_list|,
name|cols
parameter_list|)
name|int
name|lines
decl_stmt|,
name|cols
decl_stmt|;
block|{
name|char
modifier|*
name|b
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_PUTENV
argument_list|)
name|b
operator|=
name|xmalloc
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|b
argument_list|,
literal|"LINES=%d"
argument_list|,
name|lines
argument_list|)
expr_stmt|;
name|putenv
argument_list|(
name|b
argument_list|)
expr_stmt|;
name|b
operator|=
name|xmalloc
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|b
argument_list|,
literal|"COLUMNS=%d"
argument_list|,
name|cols
argument_list|)
expr_stmt|;
name|putenv
argument_list|(
name|b
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !HAVE_PUTENV */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SETENV
argument_list|)
name|b
operator|=
name|xmalloc
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|b
argument_list|,
literal|"%d"
argument_list|,
name|lines
argument_list|)
expr_stmt|;
name|setenv
argument_list|(
literal|"LINES"
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|b
operator|=
name|xmalloc
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|b
argument_list|,
literal|"%d"
argument_list|,
name|cols
argument_list|)
expr_stmt|;
name|setenv
argument_list|(
literal|"COLUMNS"
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SETENV */
endif|#
directive|endif
comment|/* !HAVE_PUTENV */
block|}
end_function

begin_function
name|char
modifier|*
name|get_env_value
parameter_list|(
name|varname
parameter_list|)
name|char
modifier|*
name|varname
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|getenv
argument_list|(
name|varname
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SHELL */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_string_value
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|get_env_value
parameter_list|(
name|varname
parameter_list|)
name|char
modifier|*
name|varname
decl_stmt|;
block|{
return|return
name|get_string_value
argument_list|(
name|varname
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHELL */
end_comment

end_unit

