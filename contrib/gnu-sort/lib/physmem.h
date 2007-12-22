begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Calculate the size of physical memory.     Copyright (C) 2000, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PHYSMEM_H_
end_ifndef

begin_define
define|#
directive|define
name|PHYSMEM_H_
value|1
end_define

begin_function_decl
name|double
name|physmem_total
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|physmem_available
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PHYSMEM_H_ */
end_comment

end_unit

