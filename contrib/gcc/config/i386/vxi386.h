begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  VxWorks i386 version.    Copyright (C) 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_CPU_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_CPU_SPEC
value|"\ -Asystem=unix -Acpu=i386 -Amachine=i386 \ %{!ansi:-Di386} -D__i386 -D__i386__ \ %{march=i386:-DCPU=I80386} \ %{march=i486:-DCPU=I80486 %(cpp_486)} \ %{march=pentium:-DCPU=PENTIUM -DCPU_VARIANT=PENTIUM %(cpp_586)} \ %{march=pentiumpro:-DCPU=PENTIUM -DCPU_VARIANT=PENTIUMPRO %(cpp_686)} \ %{!march=*: \  %{mcpu=i386:-DCPU=I80386} \  %{mcpu=i486:-DCPU=I80486 %(cpp_486)} %{m486:-DCPU=I80486 %(cpp_486)} \  %{mpentium:-DCPU=PENTIUM -DCPU_VARIANT=PENTIUM %(cpp_586)} \  %{mcpu=pentium:-DCPU=PENTIUM -DCPU_VARIANT=PENTIUM %(cpp_586)} \  %{mpentiumpro:-DCPU=PENTIUM -DCPU_VARIANT=PENTIUMPRO %(cpp_686)} \  %{mcpu=pentiumpro:-DCPU=PENTIUM -DCPU_VARIANT=PENTIUMPRO %(cpp_686)} \  %{!mcpu*:%{!m486:%{!mpentium*:-DCPU=I80386 %(cpp_cpu_default)}}}}"
end_define

begin_include
include|#
directive|include
file|"i386/i386-aout.h"
end_include

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
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
value|"-D__vxworks"
end_define

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
comment|/* VxWorks uses object files, not loadable images.  make linker just    combine objects.  */
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
value|"-r"
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
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|""
end_define

end_unit

