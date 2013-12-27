begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Darwin host-specific hook definitions.    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|darwin_gt_pch_get_address
parameter_list|(
name|size_t
name|sz
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|darwin_gt_pch_use_address
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|sz
parameter_list|,
name|int
name|fd
parameter_list|,
name|size_t
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|HOST_HOOKS_GT_PCH_GET_ADDRESS
end_undef

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_GET_ADDRESS
value|darwin_gt_pch_get_address
end_define

begin_undef
undef|#
directive|undef
name|HOST_HOOKS_GT_PCH_USE_ADDRESS
end_undef

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_USE_ADDRESS
value|darwin_gt_pch_use_address
end_define

end_unit

