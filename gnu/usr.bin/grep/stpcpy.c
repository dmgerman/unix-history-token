begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stpcpy.c -- copy a string and return pointer to end of new string    Copyright (C) 1992, 1995, 1997, 1998 Free Software Foundation, Inc.     NOTE: The canonical source of this file is maintained with the GNU C Library.    Bugs can be reported to bug-glibc@prep.ai.mit.edu.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any    later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.  */
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

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_undef
undef|#
directive|undef
name|__stpcpy
end_undef

begin_undef
undef|#
directive|undef
name|stpcpy
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|weak_alias
end_ifndef

begin_define
define|#
directive|define
name|__stpcpy
value|stpcpy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Copy SRC to DEST, returning the address of the terminating '\0' in DEST.  */
end_comment

begin_function
name|char
modifier|*
name|__stpcpy
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
specifier|register
name|char
modifier|*
name|d
init|=
name|dest
decl_stmt|;
specifier|register
specifier|const
name|char
modifier|*
name|s
init|=
name|src
decl_stmt|;
do|do
operator|*
name|d
operator|++
operator|=
operator|*
name|s
expr_stmt|;
do|while
condition|(
operator|*
name|s
operator|++
operator|!=
literal|'\0'
condition|)
do|;
return|return
name|d
operator|-
literal|1
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|weak_alias
end_ifdef

begin_macro
name|weak_alias
argument_list|(
argument|__stpcpy
argument_list|,
argument|stpcpy
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

