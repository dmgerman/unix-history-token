begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implementation of the textdomain(3) function    Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.    Written by Ulrich Drepper<drepper@gnu.ai.mit.edu>, 1995.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|defined
name|STDC_HEADERS
operator|||
name|defined
name|_LIBC
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

begin_if
if|#
directive|if
name|defined
name|STDC_HEADERS
operator|||
name|defined
name|HAVE_STRING_H
operator|||
name|defined
name|_LIBC
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

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|Dst
parameter_list|,
name|Src
parameter_list|,
name|Num
parameter_list|)
value|bcopy (Src, Dst, Num)
end_define

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
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"libgettext.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ end of prolog @@ */
end_comment

begin_comment
comment|/* Name of the default text domain.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|_nl_default_default_domain
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default text domain in which entries for gettext(3) are to be found.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_nl_current_default_domain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Names for the libintl functions are a problem.  They must not clash    with existing names and they should follow ANSI C.  But this source    code is also used in GNU C Library where the names have a __    prefix.  So we have to make a difference here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_define
define|#
directive|define
name|TEXTDOMAIN
value|__textdomain
end_define

begin_define
define|#
directive|define
name|strdup
parameter_list|(
name|str
parameter_list|)
value|__strdup (str)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEXTDOMAIN
value|textdomain__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set the current default message catalog to DOMAINNAME.    If DOMAINNAME is null, return the current default.    If DOMAINNAME is "", reset to the default of "messages".  */
end_comment

begin_function
name|char
modifier|*
name|TEXTDOMAIN
parameter_list|(
name|domainname
parameter_list|)
specifier|const
name|char
modifier|*
name|domainname
decl_stmt|;
block|{
name|char
modifier|*
name|old
decl_stmt|;
comment|/* A NULL pointer requests the current setting.  */
if|if
condition|(
name|domainname
operator|==
name|NULL
condition|)
return|return
operator|(
name|char
operator|*
operator|)
name|_nl_current_default_domain
return|;
name|old
operator|=
operator|(
name|char
operator|*
operator|)
name|_nl_current_default_domain
expr_stmt|;
comment|/* If domain name is the null string set to default domain "messages".  */
if|if
condition|(
name|domainname
index|[
literal|0
index|]
operator|==
literal|'\0'
operator|||
name|strcmp
argument_list|(
name|domainname
argument_list|,
name|_nl_default_default_domain
argument_list|)
operator|==
literal|0
condition|)
name|_nl_current_default_domain
operator|=
name|_nl_default_default_domain
expr_stmt|;
else|else
block|{
comment|/* If the following malloc fails `_nl_current_default_domain' 	 will be NULL.  This value will be returned and so signals we 	 are out of core.  */
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|defined
name|HAVE_STRDUP
name|_nl_current_default_domain
operator|=
name|strdup
argument_list|(
name|domainname
argument_list|)
expr_stmt|;
else|#
directive|else
name|size_t
name|len
init|=
name|strlen
argument_list|(
name|domainname
argument_list|)
operator|+
literal|1
decl_stmt|;
name|char
modifier|*
name|cp
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
name|cp
operator|!=
name|NULL
condition|)
name|memcpy
argument_list|(
name|cp
argument_list|,
name|domainname
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|_nl_current_default_domain
operator|=
name|cp
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|old
operator|!=
name|_nl_default_default_domain
condition|)
name|free
argument_list|(
name|old
argument_list|)
expr_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
name|_nl_current_default_domain
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_comment
comment|/* Alias for function name in GNU C Library.  */
end_comment

begin_expr_stmt
name|weak_alias
argument_list|(
name|__textdomain
argument_list|,
name|textdomain
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

