begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Convert string representation of a number into an intmax_t value.    Copyright 1999, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert. */
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
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

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
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
name|defined
name|__STDC__
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Verify a requirement at compile-time (unlike assert, which is runtime).  */
end_comment

begin_define
define|#
directive|define
name|verify
parameter_list|(
name|name
parameter_list|,
name|assertion
parameter_list|)
value|struct name { char a[(assertion) ? 1 : -1]; }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UNSIGNED
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRTOUL
end_ifndef

begin_expr_stmt
literal|"this configure-time declaration test was not run"
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL_STRTOUL
name|unsigned
name|long
name|strtoul
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRTOULL
end_ifndef

begin_expr_stmt
literal|"this configure-time declaration test was not run"
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL_STRTOULL
operator|&&
name|HAVE_UNSIGNED_LONG_LONG
name|unsigned
name|long
name|long
name|strtoull
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRTOL
end_ifndef

begin_expr_stmt
literal|"this configure-time declaration test was not run"
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL_STRTOL
name|long
name|strtol
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRTOLL
end_ifndef

begin_expr_stmt
literal|"this configure-time declaration test was not run"
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL_STRTOLL
operator|&&
name|HAVE_UNSIGNED_LONG_LONG
name|long
name|long
name|strtoll
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNSIGNED
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_LONG_LONG
end_undef

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|HAVE_UNSIGNED_LONG_LONG
end_define

begin_define
define|#
directive|define
name|INT
value|uintmax_t
end_define

begin_define
define|#
directive|define
name|strtoimax
value|strtoumax
end_define

begin_define
define|#
directive|define
name|strtol
value|strtoul
end_define

begin_define
define|#
directive|define
name|strtoll
value|strtoull
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT
value|intmax_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|INT
name|strtoimax
parameter_list|(
name|char
specifier|const
modifier|*
name|ptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
block|{
if|#
directive|if
name|HAVE_LONG_LONG
name|verify
argument_list|(
name|size_is_that_of_long_or_long_long
argument_list|,
operator|(
sizeof|sizeof
argument_list|(
name|INT
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|||
sizeof|sizeof
argument_list|(
name|INT
argument_list|)
operator|==
expr|sizeof
operator|(
name|long
name|long
operator|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|INT
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|long
argument_list|)
condition|)
return|return
name|strtoll
argument_list|(
name|ptr
argument_list|,
name|endptr
argument_list|,
name|base
argument_list|)
return|;
else|#
directive|else
name|verify
argument_list|(
name|size_is_that_of_long
argument_list|,
sizeof|sizeof
argument_list|(
name|INT
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|long
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|strtol
argument_list|(
name|ptr
argument_list|,
name|endptr
argument_list|,
name|base
argument_list|)
return|;
block|}
end_function

end_unit

