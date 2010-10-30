begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implementation of the textdomain(3) function.    Copyright (C) 1995-1998, 2000, 2001, 2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

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
file|"libgnuintl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gettextP.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_comment
comment|/* We have to handle multi-threaded applications.  */
end_comment

begin_include
include|#
directive|include
file|<bits/libc-lock.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Provide dummy implementation if this is outside glibc.  */
end_comment

begin_define
define|#
directive|define
name|__libc_rwlock_define
parameter_list|(
name|CLASS
parameter_list|,
name|NAME
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__libc_rwlock_wrlock
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__libc_rwlock_unlock
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The internal variables in the standalone libintl.a must have different    names than the internal variables in GNU libc, otherwise programs    using libintl.a cannot be linked statically.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|_LIBC
end_if

begin_define
define|#
directive|define
name|_nl_default_default_domain
value|libintl_nl_default_default_domain
end_define

begin_define
define|#
directive|define
name|_nl_current_default_domain
value|libintl_nl_current_default_domain
end_define

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
name|attribute_hidden
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
name|attribute_hidden
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

begin_ifndef
ifndef|#
directive|ifndef
name|strdup
end_ifndef

begin_define
define|#
directive|define
name|strdup
parameter_list|(
name|str
parameter_list|)
value|__strdup (str)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEXTDOMAIN
value|libintl_textdomain
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Lock variable to protect the global data in the gettext implementation.  */
end_comment

begin_macro
name|__libc_rwlock_define
argument_list|(
argument|extern
argument_list|,
argument|_nl_state_lock attribute_hidden
argument_list|)
end_macro

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
name|new_domain
decl_stmt|;
name|char
modifier|*
name|old_domain
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
name|__libc_rwlock_wrlock
argument_list|(
name|_nl_state_lock
argument_list|)
expr_stmt|;
name|old_domain
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
block|{
name|_nl_current_default_domain
operator|=
name|_nl_default_default_domain
expr_stmt|;
name|new_domain
operator|=
operator|(
name|char
operator|*
operator|)
name|_nl_current_default_domain
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|domainname
argument_list|,
name|old_domain
argument_list|)
operator|==
literal|0
condition|)
comment|/* This can happen and people will use it to signal that some        environment variable changed.  */
name|new_domain
operator|=
name|old_domain
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
name|new_domain
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
name|new_domain
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|new_domain
operator|!=
name|NULL
condition|)
name|memcpy
argument_list|(
name|new_domain
argument_list|,
name|domainname
argument_list|,
name|len
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|new_domain
operator|!=
name|NULL
condition|)
name|_nl_current_default_domain
operator|=
name|new_domain
expr_stmt|;
block|}
comment|/* We use this possibility to signal a change of the loaded catalogs      since this is most likely the case and there is no other easy we      to do it.  Do it only when the call was successful.  */
if|if
condition|(
name|new_domain
operator|!=
name|NULL
condition|)
block|{
operator|++
name|_nl_msg_cat_cntr
expr_stmt|;
if|if
condition|(
name|old_domain
operator|!=
name|new_domain
operator|&&
name|old_domain
operator|!=
name|_nl_default_default_domain
condition|)
name|free
argument_list|(
name|old_domain
argument_list|)
expr_stmt|;
block|}
name|__libc_rwlock_unlock
argument_list|(
name|_nl_state_lock
argument_list|)
expr_stmt|;
return|return
name|new_domain
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

