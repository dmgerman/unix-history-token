begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Vxworks PowerPC version.    Copyright (C) 1996, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file just exists to give specs for the PowerPC running on VxWorks.  */
end_comment

begin_comment
comment|/* Reset defaults */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_OS_DEFAULT_SPEC
value|"%(cpp_os_vxworks)"
end_define

begin_undef
undef|#
directive|undef
name|LIB_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_DEFAULT_SPEC
value|"%(lib_vxworks)"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_DEFAULT_SPEC
value|"%(startfile_vxworks)"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_DEFAULT_SPEC
value|"%(endfile_vxworks)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_START_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_START_DEFAULT_SPEC
value|"%(link_start_vxworks)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_OS_DEFAULT_SPEC
value|"%(link_os_vxworks)"
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
value|"\ -D__vxworks -D__vxworks__ -Asystem=vxworks -Asystem=embedded \ -Acpu=powerpc -Amachine=powerpc"
end_define

begin_comment
comment|/* Don't define _LITTLE_ENDIAN or _BIG_ENDIAN */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_ENDIAN_BIG_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ENDIAN_BIG_SPEC
value|"-D__BIG_ENDIAN__ -Amachine=bigendian"
end_define

begin_undef
undef|#
directive|undef
name|CPP_ENDIAN_LITTLE_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ENDIAN_LITTLE_SPEC
value|"-D__LITTLE_ENDIAN__ -Amachine=littleendian"
end_define

begin_comment
comment|/* We use stabs-in-elf for debugging */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

end_unit

