begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1996, 1997, 1998, 2000, 2003 Free Software Foundation, Inc.     NOTE: The canonical source of this file is maintained with the GNU C Library.    Bugs can be reported to bug-glibc@prep.ai.mit.edu.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any    later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRNLEN
end_ifndef

begin_expr_stmt
literal|"this configure-time declaration test was not run"
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL_STRNLEN
name|size_t
name|strnlen
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__strndup
end_undef

begin_undef
undef|#
directive|undef
name|strndup
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|weak_alias
end_ifndef

begin_define
define|#
directive|define
name|__strndup
value|strndup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|__strndup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|size_t
name|len
init|=
name|strnlen
argument_list|(
name|s
argument_list|,
name|n
argument_list|)
decl_stmt|;
name|char
modifier|*
name|new
init|=
name|malloc
argument_list|(
name|len
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|new
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|new
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|memcpy
argument_list|(
name|new
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
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
argument|__strndup
argument_list|,
argument|strndup
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

