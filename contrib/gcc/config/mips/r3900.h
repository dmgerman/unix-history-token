begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of MIPS sub target machine for GNU compiler.    Toshiba r3900.  You should include mips.h after this.     Copyright (C) 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 2004    Free Software Foundation, Inc.    Contributed by Gavin Koch (gavin@cygnus.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_CPU_STRING_DEFAULT
value|"r3900"
end_define

begin_define
define|#
directive|define
name|MIPS_ISA_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ MULTILIB_ENDIAN_DEFAULT, "msoft-float" }
end_define

begin_comment
comment|/* We use the MIPS EABI by default.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_ABI_DEFAULT
value|ABI_EABI
end_define

begin_comment
comment|/* By default (if not mips-something-else) produce code for the r3900 */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_CC1_SPEC
value|"\ %{mhard-float:%e-mhard-float not supported} \ %{msingle-float:%{msoft-float: \   %e-msingle-float and -msoft-float cannot both be specified}}"
end_define

end_unit

