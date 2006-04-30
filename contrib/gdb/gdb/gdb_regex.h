begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable<regex.h>.    Copyright 2000, 2001, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_REGEX_H
end_ifndef

begin_define
define|#
directive|define
name|GDB_REGEX_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_INCLUDED_REGEX
end_ifdef

begin_include
include|#
directive|include
file|"xregex.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Request 4.2 BSD regex functions.  */
end_comment

begin_define
define|#
directive|define
name|_REGEX_RE_COMP
end_define

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not GDB_REGEX_H */
end_comment

end_unit

