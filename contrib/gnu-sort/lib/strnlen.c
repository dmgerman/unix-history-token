begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Find the length of STRING, but scan at most MAXLEN characters.    Copyright (C) 1996, 1997, 1998, 2000-2003 Free Software Foundation, Inc.    This file is part of the GNU C Library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_undef
undef|#
directive|undef
name|strnlen
end_undef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_undef
undef|#
directive|undef
name|__strnlen
end_undef

begin_undef
undef|#
directive|undef
name|strnlen
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_define
define|#
directive|define
name|strnlen
value|rpl_strnlen
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|weak_alias
end_ifndef

begin_define
define|#
directive|define
name|__strnlen
value|strnlen
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Find the length of STRING, but scan at most MAXLEN characters.    If no '\0' terminator is found in that many characters, return MAXLEN.  */
end_comment

begin_function
name|size_t
name|__strnlen
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|end
init|=
name|memchr
argument_list|(
name|string
argument_list|,
literal|'\0'
argument_list|,
name|maxlen
argument_list|)
decl_stmt|;
return|return
name|end
condition|?
call|(
name|size_t
call|)
argument_list|(
name|end
operator|-
name|string
argument_list|)
else|:
name|maxlen
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
argument|__strnlen
argument_list|,
argument|strnlen
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

