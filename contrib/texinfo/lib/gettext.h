begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Convenience header for conditional use of GNU<libintl.h>.    Copyright (C) 1995-1998, 2000-2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBGETTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBGETTEXT_H
value|1
end_define

begin_comment
comment|/* NLS can be disabled through the configure --disable-nls option.  */
end_comment

begin_if
if|#
directive|if
name|ENABLE_NLS
end_if

begin_comment
comment|/* Get declarations of GNU message catalog functions.  */
end_comment

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Disabled NLS.    The casts to 'const char *' serve the purpose of producing warnings    for invalid uses of the value returned from these functions.    On pre-ANSI systems without 'const', the config.h file is supposed to    contain "#define const".  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* no thanks, not ready to go const --karl, 26feb02 */
end_comment

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|Msgid
parameter_list|)
value|((const char *) (Msgid))
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|)
value|((const char *) (Msgid))
end_define

begin_define
define|#
directive|define
name|dcgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|,
name|Category
parameter_list|)
value|((const char *) (Msgid))
end_define

begin_define
define|#
directive|define
name|ngettext
parameter_list|(
name|Msgid1
parameter_list|,
name|Msgid2
parameter_list|,
name|N
parameter_list|)
define|\
value|((N) == 1 ? (const char *) (Msgid1) : (const char *) (Msgid2))
end_define

begin_define
define|#
directive|define
name|dngettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid1
parameter_list|,
name|Msgid2
parameter_list|,
name|N
parameter_list|)
define|\
value|((N) == 1 ? (const char *) (Msgid1) : (const char *) (Msgid2))
end_define

begin_define
define|#
directive|define
name|dcngettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid1
parameter_list|,
name|Msgid2
parameter_list|,
name|N
parameter_list|,
name|Category
parameter_list|)
define|\
value|((N) == 1 ? (const char *) (Msgid1) : (const char *) (Msgid2))
end_define

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domainname
parameter_list|)
value|((const char *) (Domainname))
end_define

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domainname
parameter_list|,
name|Dirname
parameter_list|)
value|((const char *) (Dirname))
end_define

begin_define
define|#
directive|define
name|bind_textdomain_codeset
parameter_list|(
name|Domainname
parameter_list|,
name|Codeset
parameter_list|)
value|((const char *) (Codeset))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not 0 */
end_comment

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|Msgid
parameter_list|)
value|((Msgid))
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dcgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|,
name|Category
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|ngettext
parameter_list|(
name|Msgid1
parameter_list|,
name|Msgid2
parameter_list|,
name|N
parameter_list|)
define|\
value|((N) == 1 ? (Msgid1) : (Msgid2))
end_define

begin_define
define|#
directive|define
name|dngettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid1
parameter_list|,
name|Msgid2
parameter_list|,
name|N
parameter_list|)
define|\
value|((N) == 1 ? (Msgid1) : (Msgid2))
end_define

begin_define
define|#
directive|define
name|dcngettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid1
parameter_list|,
name|Msgid2
parameter_list|,
name|N
parameter_list|,
name|Category
parameter_list|)
define|\
value|((N) == 1 ? (Msgid1) : (Msgid2))
end_define

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domainname
parameter_list|)
value|(Domainname)
end_define

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domainname
parameter_list|,
name|Dirname
parameter_list|)
value|(Dirname)
end_define

begin_define
define|#
directive|define
name|bind_textdomain_codeset
parameter_list|(
name|Domainname
parameter_list|,
name|Codeset
parameter_list|)
value|(Codeset)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A pseudo function call that serves as a marker for the automated    extraction of messages, but does not call gettext().  The run-time    translation is done at a different place in the code.    The argument, String, should be a literal string.  Concatenated strings    and other string expressions won't work.    The macro's expansion is not parenthesized, so that it is suitable as    initializer for static 'char[]' or 'const char[]' variables.  */
end_comment

begin_define
define|#
directive|define
name|gettext_noop
parameter_list|(
name|String
parameter_list|)
value|String
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBGETTEXT_H */
end_comment

end_unit

