begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The host_hooks data structure.    Copyright 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_HOST_HOOKS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_HOST_HOOKS_H
end_define

begin_struct
struct|struct
name|host_hooks
block|{
name|void
function_decl|(
modifier|*
name|extra_signals
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|gt_pch_get_address
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|gt_pch_use_address
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* Whenever you add entries here, make sure you adjust hosthooks-def.h.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Each host provides its own.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|host_hooks
name|host_hooks
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_LANG_HOOKS_H */
end_comment

end_unit

