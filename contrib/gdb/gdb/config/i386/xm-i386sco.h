begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro defintions for i386, running SCO Unix System V/386 3.2.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* In 3.2v4<sys/user.h> requires on<sys/dir.h>.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|"i386/xm-i386v.h"
end_include

begin_comment
comment|/* Apparently there is inconsistency among various System V's about what    the name of this field is.  */
end_comment

begin_define
define|#
directive|define
name|U_FPSTATE
parameter_list|(
name|u
parameter_list|)
value|u.u_fps.u_fpstate
end_define

begin_comment
comment|/* SCO 3.2v2 and later have job control.  */
end_comment

begin_comment
comment|/* SCO 3.2v4 I know has termios; I'm not sure about earlier versions.    GDB does not currently support the termio/job control combination.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TERMIO
end_undef

begin_define
define|#
directive|define
name|HAVE_TERMIOS
end_define

begin_comment
comment|/* SCO's assembler doesn't grok dollar signs in identifiers.    So we use dots instead.  This item must be coordinated with G++. */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUS_MARKER
end_undef

begin_define
define|#
directive|define
name|CPLUS_MARKER
value|'.'
end_define

begin_comment
comment|/* Use setpgid instead of setpgrp on SCO */
end_comment

begin_define
define|#
directive|define
name|NEED_POSIX_SETPGID
end_define

end_unit

