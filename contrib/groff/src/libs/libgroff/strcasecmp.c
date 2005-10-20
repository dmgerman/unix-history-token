begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strcasecmp.c -- case insensitive string comparator    Copyright (C) 1998, 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|LENGTH_LIMIT
end_ifdef

begin_define
define|#
directive|define
name|STRXCASECMP_FUNCTION
value|strncasecmp
end_define

begin_define
define|#
directive|define
name|STRXCASECMP_DECLARE_N
value|, size_t n
end_define

begin_define
define|#
directive|define
name|LENGTH_LIMIT_EXPR
parameter_list|(
name|Expr
parameter_list|)
value|Expr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRXCASECMP_FUNCTION
value|strcasecmp
end_define

begin_define
define|#
directive|define
name|STRXCASECMP_DECLARE_N
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|LENGTH_LIMIT_EXPR
parameter_list|(
name|Expr
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|Ch
parameter_list|)
value|(isupper (Ch) ? tolower (Ch) : (Ch))
end_define

begin_comment
comment|/* Compare {{no more than N characters of }}strings S1 and S2,    ignoring case, returning less than, equal to or    greater than zero if S1 is lexicographically less    than, equal to or greater than S2.  */
end_comment

begin_function
name|int
name|STRXCASECMP_FUNCTION
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
name|STRXCASECMP_DECLARE_N
parameter_list|)
block|{
specifier|register
specifier|const
name|unsigned
name|char
modifier|*
name|p1
init|=
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|s1
decl_stmt|;
specifier|register
specifier|const
name|unsigned
name|char
modifier|*
name|p2
init|=
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|s2
decl_stmt|;
name|unsigned
name|char
name|c1
decl_stmt|,
name|c2
decl_stmt|;
if|if
condition|(
name|p1
operator|==
name|p2
operator|||
name|LENGTH_LIMIT_EXPR
argument_list|(
name|n
operator|==
literal|0
argument_list|)
condition|)
return|return
literal|0
return|;
do|do
block|{
name|c1
operator|=
name|TOLOWER
argument_list|(
operator|*
name|p1
argument_list|)
expr_stmt|;
name|c2
operator|=
name|TOLOWER
argument_list|(
operator|*
name|p2
argument_list|)
expr_stmt|;
if|if
condition|(
name|LENGTH_LIMIT_EXPR
argument_list|(
operator|--
name|n
operator|==
literal|0
argument_list|)
operator|||
name|c1
operator|==
literal|'\0'
condition|)
break|break;
operator|++
name|p1
expr_stmt|;
operator|++
name|p2
expr_stmt|;
block|}
do|while
condition|(
name|c1
operator|==
name|c2
condition|)
do|;
return|return
name|c1
operator|-
name|c2
return|;
block|}
end_function

end_unit

