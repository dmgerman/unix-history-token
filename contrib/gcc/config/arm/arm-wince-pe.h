begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for ARM with PE obj format running under the WinCE operating system.     Copyright (C) 1999, 2000 Free Software Foundation, Inc.     This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|ARM_WINCE
value|1
end_define

begin_include
include|#
directive|include
file|"pe.h"
end_include

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/WinCE/PE)", stderr);
end_define

begin_comment
comment|/* The next three definitions are defined in pe.h,    undefined in arm/arm-pe.h and then redefined back here!  */
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
value|"-lcoredll -lcorelibc"
end_define

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|""
end_define

begin_define
define|#
directive|define
name|LIBSTDCXX
value|"-lc"
end_define

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

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|CPP_APCS_PC_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_APCS_PC_DEFAULT_SPEC
value|"-D__APCS_32__"
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{!mapcs-32:%{!mapcs-26:-mapcs-32}}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"			\ %{mbig-endian:-EB}			\ %{mcpu=*:-m%*}				\ %{march=*:-m%*}				\ %{mapcs-*:-mapcs-%*}			\ %{mthumb-interwork:-mthumb-interwork}	\ %{!mapcs-32:%{!mapcs-26:-mapcs-32}}	\ "
end_define

begin_comment
comment|/* WinCE headers require -DARM */
end_comment

begin_undef
undef|#
directive|undef
name|PE_SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|PE_SUBTARGET_CPP_SPEC
value|"-D__pe__ -DARM -D__unaligned=__attribute__((aligned(1))) "
end_define

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

end_unit

