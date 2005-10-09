begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Register protocol definition structures for the GNU Debugger    Copyright 2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGDEF_H
end_ifndef

begin_define
define|#
directive|define
name|REGDEF_H
end_define

begin_struct
struct|struct
name|reg
block|{
comment|/* The name of this register - NULL for pad entries.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* At the moment, both of the following bit counts must be divisible      by eight (to match the representation as two hex digits) and divisible      by the size of a byte (to match the layout of each register in      memory).  */
comment|/* The offset (in bits) of the value of this register in the buffer.  */
name|int
name|offset
decl_stmt|;
comment|/* The size (in bits) of the value of this register, as transmitted.  */
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Set the current remote protocol and register cache according to the array    ``regs'', with ``n'' elements.  */
end_comment

begin_function_decl
name|void
name|set_register_cache
parameter_list|(
name|struct
name|reg
modifier|*
name|regs
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REGDEF_H */
end_comment

end_unit

