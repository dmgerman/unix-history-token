begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Manage register sets.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGSET_H
end_ifndef

begin_define
define|#
directive|define
name|REGSET_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_comment
comment|/* Data structure describing a register set.  */
end_comment

begin_struct
struct|struct
name|regset
block|{
comment|/* Data pointer for private use by the methods below, presumably      providing some sort of description of the register set.  */
specifier|const
name|void
modifier|*
name|descr
decl_stmt|;
comment|/* Function supplying a register set to a register cache.  */
name|void
function_decl|(
modifier|*
name|supply_regset
function_decl|)
parameter_list|(
specifier|const
name|struct
name|regset
modifier|*
parameter_list|,
name|struct
name|regcache
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* regset.h */
end_comment

end_unit

