begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386, Mach 3.0, OSF 1/MK    Copyright 1992, 1993, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Until OSF switches to a newer Mach kernel that has  * a different get_emul_vector() interface.  */
end_comment

begin_define
define|#
directive|define
name|MK67
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386m3.h"
end_include

begin_comment
comment|/* FIMXE: kettenis/2000-03-26: On OSF 1, `long double' is equivalent    to `double'.  However, I'm not sure what is the consequence of:     #define TARGET_LONG_DOUBLE_FORMAT TARGET_DOUBLE_FORMAT    #define TARGET_LONG_DOUBLE_BIT TARGET_DOUBLE_BIT     So I'll go with the current status quo instead.  It looks like this    target won't compile anyway.  Perhaps it should be obsoleted?  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_LONG_DOUBLE_FORMAT
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_LONG_DOUBLE_BIT
end_undef

end_unit

