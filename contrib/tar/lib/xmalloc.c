begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmalloc.c -- malloc with out of memory checking    Copyright (C) 1990-1999, 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_if
if|#
directive|if
name|STDC_HEADERS
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

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

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
name|textdomain
parameter_list|(
name|Domain
parameter_list|)
end_define

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

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|Text
parameter_list|)
value|Text
end_define

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"xalloc.h"
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DONE_WORKING_MALLOC_CHECK
end_ifndef

begin_expr_stmt
literal|"you must run the autoconf test for a properly working malloc -- see malloc.m4"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_DONE_WORKING_REALLOC_CHECK
literal|"you must run the autoconf test for a properly working realloc --see realloc.m4"
endif|#
directive|endif
comment|/* Exit value when the requested amount of memory is not available.    The caller may set it to some other value.  */
name|int
name|xalloc_exit_failure
operator|=
name|EXIT_FAILURE
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* If non NULL, call this function when memory is exhausted. */
end_comment

begin_macro
name|void
argument_list|(
argument|*xalloc_fail_func
argument_list|)
end_macro

begin_expr_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* If XALLOC_FAIL_FUNC is NULL, or does return, display this message    before exiting when memory is exhausted.  Goes through gettext. */
end_comment

begin_decl_stmt
name|char
specifier|const
name|xalloc_msg_memory_exhausted
index|[]
init|=
name|N_
argument_list|(
literal|"memory exhausted"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|xalloc_die
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|xalloc_fail_func
condition|)
call|(
modifier|*
name|xalloc_fail_func
call|)
argument_list|()
expr_stmt|;
name|error
argument_list|(
name|xalloc_exit_failure
argument_list|,
literal|0
argument_list|,
literal|"%s"
argument_list|,
name|_
argument_list|(
name|xalloc_msg_memory_exhausted
argument_list|)
argument_list|)
expr_stmt|;
comment|/* The `noreturn' cannot be given to error, since it may return if      its first argument is 0.  To help compilers understand the      xalloc_die does terminate, call exit. */
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Allocate N bytes of memory dynamically, with error checking.  */
end_comment

begin_function
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
name|n
parameter_list|)
block|{
name|void
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|malloc
argument_list|(
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* Change the size of an allocated block of memory P to N bytes,    with error checking.  */
end_comment

begin_function
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|p
operator|=
name|realloc
argument_list|(
name|p
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* Allocate memory for N elements of S bytes, with error checking.  */
end_comment

begin_function
name|void
modifier|*
name|xcalloc
parameter_list|(
name|size_t
name|n
parameter_list|,
name|size_t
name|s
parameter_list|)
block|{
name|void
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|calloc
argument_list|(
name|n
argument_list|,
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

end_unit

