begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for linux.    Copyright (C) 1992 Free Software Foundation, Inc. This file is part of GDB. This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TM_LINUX_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|TM_LINUX_H
value|1
end_define

begin_comment
comment|/* number of traps that happen between exec'ing the shell  * to run an inferior, and when we finally get to  * the inferior code.  This is 2 on most implementations.  */
end_comment

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
end_define

begin_include
include|#
directive|include
file|"tm-i386v.h"
end_include

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (TM_LINUX_H) */
end_comment

end_unit

