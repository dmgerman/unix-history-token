begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Output variables, constants and external declarations, for GNU compiler.    Copyright (C) 2001 Free Software Foundation, Inc.    Contributed by Douglas Rupp (rupp@gnat.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Defaults to BITS_PER_WORD, e.g. 64 which is what is wanted.   This is incompatible with DEC C, but matches DEC Ada */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_TYPE_SIZE
end_undef

begin_comment
comment|/* Defaults to "long int" */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|POINTERS_EXTEND_UNSIGNED
end_undef

begin_undef
undef|#
directive|undef
name|POINTER_SIZE
end_undef

begin_define
define|#
directive|define
name|POINTER_SIZE
value|64
end_define

end_unit

