begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* asintl.h - gas-specific header for gettext code.    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.     Written by Tom Tromey<tromey@cygnus.com>     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

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
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gettext_noop
end_ifdef

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|gettext_noop (String)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
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
name|gettext
parameter_list|(
name|Msgid
parameter_list|)
value|(Msgid)
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
name|textdomain
parameter_list|(
name|Domainname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domainname
parameter_list|,
name|Dirname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

