begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implementation of the dngettext(3) function.    Copyright (C) 1995-1997, 2000-2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
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
file|"gettextP.h"
end_include

begin_include
include|#
directive|include
file|<locale.h>
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
name|DNGETTEXT
value|__dngettext
end_define

begin_define
define|#
directive|define
name|DCNGETTEXT
value|__dcngettext
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DNGETTEXT
value|libintl_dngettext
end_define

begin_define
define|#
directive|define
name|DCNGETTEXT
value|libintl_dcngettext
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Look up MSGID in the DOMAINNAME message catalog of the current    LC_MESSAGES locale and skip message according to the plural form.  */
end_comment

begin_function
name|char
modifier|*
name|DNGETTEXT
parameter_list|(
name|domainname
parameter_list|,
name|msgid1
parameter_list|,
name|msgid2
parameter_list|,
name|n
parameter_list|)
specifier|const
name|char
modifier|*
name|domainname
decl_stmt|;
specifier|const
name|char
modifier|*
name|msgid1
decl_stmt|;
specifier|const
name|char
modifier|*
name|msgid2
decl_stmt|;
name|unsigned
name|long
name|int
name|n
decl_stmt|;
block|{
return|return
name|DCNGETTEXT
argument_list|(
name|domainname
argument_list|,
name|msgid1
argument_list|,
name|msgid2
argument_list|,
name|n
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
name|__dngettext
argument_list|,
name|dngettext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

