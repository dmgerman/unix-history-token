begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 using the GNU object file format.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Changes for 80386 by Pace Willisson (pace@prep.ai.mit.edu)  * July 1988  *   * i386gnu: COFF_ENCAPSULATE  */
end_comment

begin_define
define|#
directive|define
name|COFF_ENCAPSULATE
end_define

begin_include
include|#
directive|include
file|"m-i386.h"
end_include

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_undef
undef|#
directive|undef
name|COFF_FORMAT
end_undef

begin_define
define|#
directive|define
name|READ_DBX_FORMAT
end_define

end_unit

