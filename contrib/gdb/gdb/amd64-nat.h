begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for AMD64.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMD64_NAT_H
end_ifndef

begin_define
define|#
directive|define
name|AMD64_NAT_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_comment
comment|/* General-purpose register set description for native 32-bit code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|amd64_native_gregset32_reg_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|amd64_native_gregset32_num_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* General-purpose register set description for native 64-bit code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|amd64_native_gregset64_reg_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|amd64_native_gregset64_num_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return whether the native general-purpose register set supplies    register REGNUM.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|amd64_native_gregset_supplies_p
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Supply register REGNUM, whose contents are store in BUF, to    REGCACHE.  If REGNUM is -1, supply all appropriate registers.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|amd64_supply_native_gregset
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
specifier|const
name|void
modifier|*
name|gregs
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Collect register REGNUM from REGCACHE and store its contents in    GREGS.  If REGNUM is -1, collect and store all appropriate    registers.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|amd64_collect_native_gregset
parameter_list|(
specifier|const
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|void
modifier|*
name|gregs
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* amd64-nat.h */
end_comment

end_unit

