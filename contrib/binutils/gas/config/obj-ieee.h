begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is obj-ieee.h    Copyright 1987, 1988, 1989, 1990, 1991, 1992, 2000    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|BFD
value|1
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|asymbol
name|sy
decl_stmt|;
name|int
name|seg
decl_stmt|;
block|}
name|obj_symbol_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|S_GET_NAME
parameter_list|(
name|s
parameter_list|)
value|(((s)->sy_symbol.sy.name))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|object_headers
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
value|1
end_define

begin_decl_stmt
name|int
name|lineno_rootP
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IEEE_STYLE
end_define

end_unit

