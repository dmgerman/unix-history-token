begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for Darwin 8.0 and above (Mac OS X) systems.    Copyright (C) 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Machine dependent libraries.  Include libmx when compiling on    Darwin 7.0 and above, but before libSystem, since the functions are    actually in libSystem but for 7.x compatibility we want them to be    looked for in libmx first---but only do this if 7.x compatibility    is a concern, which it's not in 64-bit mode.  Include    libSystemStubs when compiling on (not necessarily for) 8.0 and    above and not 64-bit long double.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!static:\   %{!mlong-double-64:%{pg:-lSystemStubs_profile;:-lSystemStubs}} \   %{!m64:%:version-compar>< 10.3 10.4 mmacosx-version-min= -lmx)} -lSystem}"
end_define

end_unit

