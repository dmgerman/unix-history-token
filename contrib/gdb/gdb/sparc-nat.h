begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for SPARC.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPARC_NAT_H
end_ifndef

begin_define
define|#
directive|define
name|SPARC_NAT_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|sparc_gregset
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_gregset
modifier|*
name|sparc_gregset
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|sparc_supply_gregset
function_decl|)
parameter_list|(
specifier|const
name|struct
name|sparc_gregset
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|sparc_collect_gregset
function_decl|)
parameter_list|(
specifier|const
name|struct
name|sparc_gregset
modifier|*
parameter_list|,
specifier|const
name|struct
name|regcache
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|sparc_supply_fpregset
function_decl|)
parameter_list|(
name|struct
name|regcache
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|sparc_collect_fpregset
function_decl|)
parameter_list|(
specifier|const
name|struct
name|regcache
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|sparc_gregset_supplies_p
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|sparc_fpregset_supplies_p
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sparc32_gregset_supplies_p
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sparc32_fpregset_supplies_p
parameter_list|(
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
comment|/* sparc-nat.h */
end_comment

end_unit

