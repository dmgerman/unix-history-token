begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmalloc.c -- malloc with out of memory checking    Copyright (C) 1990, 91, 92, 93, 94 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

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
name|__STDC__
end_if

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID
value|char
end_define

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
name|VOID
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
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

begin_comment
comment|/* This is for other GNU distributions with internationalized messages.    The GNU C Library itself does not yet support such messages.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_LIBINTL_H
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|msgid
parameter_list|)
value|(msgid)
end_define

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

begin_comment
comment|/* Exit value when the requested amount of memory is not available.    The caller may set it to some other value.  */
end_comment

begin_decl_stmt
name|int
name|xmalloc_exit_failure
init|=
name|EXIT_FAILURE
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|(
name|HAVE_VPRINTF
operator|||
name|HAVE_DOPRNT
operator|)
end_if

begin_function_decl
name|void
name|error
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|VOID
modifier|*
name|fixup_null_alloc
parameter_list|(
name|n
parameter_list|)
name|size_t
name|n
decl_stmt|;
block|{
name|VOID
modifier|*
name|p
decl_stmt|;
name|p
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
name|p
operator|=
name|malloc
argument_list|(
operator|(
name|size_t
operator|)
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
name|error
argument_list|(
name|xmalloc_exit_failure
argument_list|,
literal|0
argument_list|,
name|gettext
argument_list|(
literal|"Memory exhausted"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* Allocate N bytes of memory dynamically, with error checking.  */
end_comment

begin_function
name|VOID
modifier|*
name|xmalloc
parameter_list|(
name|n
parameter_list|)
name|size_t
name|n
decl_stmt|;
block|{
name|VOID
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
name|p
operator|=
name|fixup_null_alloc
argument_list|(
name|n
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* Change the size of an allocated block of memory P to N bytes,    with error checking.    If P is NULL, run xmalloc.  */
end_comment

begin_function
name|VOID
modifier|*
name|xrealloc
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
name|VOID
modifier|*
name|p
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
if|if
condition|(
name|p
operator|==
literal|0
condition|)
return|return
name|xmalloc
argument_list|(
name|n
argument_list|)
return|;
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
name|p
operator|=
name|fixup_null_alloc
argument_list|(
name|n
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

end_unit

