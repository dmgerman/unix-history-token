begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Typecode definitions for Bytecode Interpreter.    Copyright (C) 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TYPECODE_H
end_ifndef

begin_define
define|#
directive|define
name|TYPECODE_H
end_define

begin_enum
enum|enum
name|typecode
block|{
define|#
directive|define
name|DEFTYPECODE
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|MACHMODE
parameter_list|,
name|TYPE
parameter_list|)
value|CODE,
include|#
directive|include
file|"bc-typecd.def"
undef|#
directive|undef
name|DEFTYPECODE
name|LAST_AND_UNUSED_TYPECODE
block|}
enum|;
end_enum

begin_comment
comment|/* Determine if a given type is integer.  */
end_comment

begin_define
define|#
directive|define
name|TYPECODE_INTEGER_P
parameter_list|(
name|TYPECODE
parameter_list|)
value|((int) (TYPECODE)< (int) SFcode)
end_define

begin_comment
comment|/* Determine if a given type is unsigned.  */
end_comment

begin_define
define|#
directive|define
name|TYPECODE_UNSIGNED_P
parameter_list|(
name|TYPECODE
parameter_list|)
define|\
value|(TYPECODE_INTEGER_P(TYPECODE)&& (int) (TYPECODE)& 1)
end_define

begin_comment
comment|/* Determine if a given type is signed.  */
end_comment

begin_define
define|#
directive|define
name|TYPECODE_SIGNED_P
parameter_list|(
name|TYPECODE
parameter_list|)
define|\
value|(TYPECODE_INTEGER_P(TYPECODE)&& !((int) (TYPECODE)& 1))
end_define

begin_comment
comment|/* Determine if a given type is floating.  */
end_comment

begin_define
define|#
directive|define
name|TYPECODE_FLOAT_P
parameter_list|(
name|TYPECODE
parameter_list|)
define|\
value|((int) (TYPECODE)< (int) Pcode&& !TYPECODE_INTEGER_P(TYPECODE))
end_define

begin_comment
comment|/* Determine if the given type is arithmetic. */
end_comment

begin_define
define|#
directive|define
name|TYPECODE_ARITH_P
parameter_list|(
name|TYPECODE
parameter_list|)
define|\
value|(TYPECODE_INTEGER_P(TYPECODE) || TYPECODE_FLOAT_P(TYPECODE))
end_define

begin_define
define|#
directive|define
name|NUM_TYPECODES
value|((int) LAST_AND_UNUSED_TYPECODE)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

