begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Vxworks SPARC version.    Copyright (C) 1994, 1996 Free Software Foundation, Inc.    Contributed by David Henkel-Wallace (gumby@cygnus.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Specify what to link with.  */
end_comment

begin_comment
comment|/* VxWorks does all the library stuff itself.  */
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
value|""
end_define

begin_comment
comment|/* Provide required defaults for linker -e.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{!nostdlib:%{!r*:%{!e*:-e start}}}"
end_define

begin_comment
comment|/* VxWorks provides the functionality of crt0.o and friends itself.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dsparc -Acpu=sparc -Amachine=sparc"
end_define

begin_comment
comment|/* Note that we define CPU here even if the user has specified -ansi.    This violates user namespace, but the VxWorks headers, and potentially    user code, all explicitly rely upon the definition of CPU in order to get    the proper processor information.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) -DCPU=SPARC"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"long int"
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"char"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|8
end_define

begin_comment
comment|/* US Software GOFAST library support.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SUBTARGET_OPTABS
end_undef

begin_define
define|#
directive|define
name|INIT_SUBTARGET_OPTABS
value|INIT_GOFAST_OPTABS
end_define

end_unit

