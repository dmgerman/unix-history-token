begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is obj-generic.h    Copyright (C) 1987-1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * This file is obj-generic.h and is intended to be a template for  * object format specific header files.  */
end_comment

begin_comment
comment|/* define an obj specific macro off which target cpu back ends may key. */
end_comment

begin_define
define|#
directive|define
name|OBJ_GENERIC
value|1
end_define

begin_comment
comment|/* include whatever target cpu is appropriate. */
end_comment

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_comment
comment|/*  * SYMBOLS  */
end_comment

begin_comment
comment|/*  * If your object format needs to reorder symbols, define this.  When  * defined, symbols are kept on a doubly linked list and functions are  * made available for push, insert, append, and delete.  If not defined,  * symbols are kept on a singly linked list, only the append and clear  * facilities are available, and they are macros.  */
end_comment

begin_comment
comment|/* #define SYMBOLS_NEED_PACKPOINTERS */
end_comment

begin_comment
comment|/*  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|nothing
decl_stmt|;
block|}
name|obj_symbol_type
typedef|;
end_typedef

begin_comment
comment|/* should be the format's symbol structure */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|object_headers
typedef|;
end_typedef

begin_comment
comment|/* symbols have names */
end_comment

begin_define
define|#
directive|define
name|S_GET_NAME
parameter_list|(
name|s
parameter_list|)
value|("foo")
end_define

begin_comment
comment|/* get the name of a symbolP */
end_comment

begin_define
define|#
directive|define
name|S_SET_NAME
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|;
end_define

begin_comment
comment|/* symbols have segments */
end_comment

begin_define
define|#
directive|define
name|S_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|(SEG_UNKNOWN)
end_define

begin_define
define|#
directive|define
name|S_SET_SEGMENT
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|;
end_define

begin_comment
comment|/* symbols have a value */
end_comment

begin_define
define|#
directive|define
name|S_GET_VALUE
parameter_list|(
name|s
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|S_SET_VALUE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|;
end_define

begin_comment
comment|/* symbols may be external */
end_comment

begin_define
define|#
directive|define
name|S_IS_EXTERNAL
parameter_list|(
name|s
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|S_SET_EXTERNAL
parameter_list|(
name|s
parameter_list|)
value|;
end_define

begin_comment
comment|/* symbols may or may not be defined */
end_comment

begin_define
define|#
directive|define
name|S_IS_DEFINED
parameter_list|(
name|s
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|OBJ_EMIT_LINENO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_comment
comment|/* must be *something*.  This no-op's it out. */
end_comment

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of obj-generic.h */
end_comment

end_unit

