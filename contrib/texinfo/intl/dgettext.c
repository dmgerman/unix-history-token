begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dgettext.c -- implementation of the dgettext(3) function    Copyright (C) 1995 Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|HAVE_LOCALE_H
operator|||
name|defined
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

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
name|DGETTEXT
value|__dgettext
end_define

begin_define
define|#
directive|define
name|DCGETTEXT
value|__dcgettext
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DGETTEXT
value|dgettext__
end_define

begin_define
define|#
directive|define
name|DCGETTEXT
value|dcgettext__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Look up MSGID in the DOMAINNAME message catalog of the current    LC_MESSAGES locale.  */
end_comment

begin_function
name|char
modifier|*
name|DGETTEXT
parameter_list|(
name|domainname
parameter_list|,
name|msgid
parameter_list|)
specifier|const
name|char
modifier|*
name|domainname
decl_stmt|;
specifier|const
name|char
modifier|*
name|msgid
decl_stmt|;
block|{
return|return
name|DCGETTEXT
argument_list|(
name|domainname
argument_list|,
name|msgid
argument_list|,
name|LC_MESSAGES
argument_list|)
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
name|__dgettext
argument_list|,
name|dgettext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

