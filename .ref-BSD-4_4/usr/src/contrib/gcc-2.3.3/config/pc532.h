begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    PC532 with National 32532.    Copyright (C) 1990 Free Software Foundation, Inc.    Contributed by Jukka Virtanen<jtv@hut.fi>, Jyrki Kuoppala<jkp@cs.hut.fi>,    Tatu Yl|nen<ylo@ngs.fi>, Johannes Helander<jvh@cs.hut.fi>.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ns32k.h"
end_include

begin_comment
comment|/* Compile for the floating point unit& 32532 by default;    also presume SB is zero */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|25
end_define

begin_comment
comment|/* Write DBX debugging info for gdb to read */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Use the re-entrant and potentially faster method */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_STATIC_STRUCT_RETURN
end_undef

begin_comment
comment|/* 32-bit alignment for efficiency */
end_comment

begin_undef
undef|#
directive|undef
name|POINTER_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|POINTER_BOUNDARY
value|32
end_define

begin_comment
comment|/* 32-bit alignment for efficiency */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|32
end_define

begin_comment
comment|/* 32532 spec says it can handle any alignment.  Rumor from tm-ns32k.h    tells this might not be actually true (but it's for 32032, perhaps    National has fixed the bug for 32532).  You might have to change this    if the bug still exists. */
end_comment

begin_undef
undef|#
directive|undef
name|STRICT_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|0
end_define

begin_comment
comment|/* Maybe someone needs to know which processor we're running on */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dns32000 -Dns32532 -Dpc532 -Dunix"
end_define

begin_comment
comment|/* Use pc relative addressing whenever possible,    it's more efficient than absolute (ns32k.c)    You have to fix a bug in gas 1.38.1 to make this work with gas,    patch available from jkp@cs.hut.fi. */
end_comment

begin_define
define|#
directive|define
name|PC_RELATIVE
end_define

begin_comment
comment|/* Operand of bsr or jsr should be just the address.  */
end_comment

begin_define
define|#
directive|define
name|CALL_MEMREF_IMPLICIT
end_define

begin_comment
comment|/* movd insns may have floating point constant operands.  */
end_comment

begin_define
define|#
directive|define
name|MOVD_FLOAT_OK
end_define

begin_comment
comment|/* Every address needs to use a base reg.  */
end_comment

begin_define
define|#
directive|define
name|BASE_REG_NEEDED
end_define

end_unit

