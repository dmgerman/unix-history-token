begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xstrtoumax.c -- A more useful interface to strtoumax.    Copyright (C) 1999, 2003, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|"xstrtol.h"
end_include

begin_define
define|#
directive|define
name|__strtol
value|strtoumax
end_define

begin_define
define|#
directive|define
name|__strtol_t
value|uintmax_t
end_define

begin_define
define|#
directive|define
name|__xstrtol
value|xstrtoumax
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UINTMAX_MAX
end_ifdef

begin_define
define|#
directive|define
name|STRTOL_T_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|STRTOL_T_MAXIMUM
value|UINTMAX_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xstrtol.c"
end_include

end_unit

