begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default macros to initialize the lang_hooks data structure.    Copyright 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_HOST_HOOKS_DEF_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_HOST_HOOKS_DEF_H
end_define

begin_include
include|#
directive|include
file|"hooks.h"
end_include

begin_define
define|#
directive|define
name|HOST_HOOKS_EXTRA_SIGNALS
value|hook_void_void
end_define

begin_if
if|#
directive|if
name|HAVE_MMAP_FILE
end_if

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_GET_ADDRESS
value|mmap_gt_pch_get_address
end_define

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_USE_ADDRESS
value|mmap_gt_pch_use_address
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_GET_ADDRESS
value|default_gt_pch_get_address
end_define

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_USE_ADDRESS
value|default_gt_pch_use_address
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
modifier|*
name|default_gt_pch_get_address
parameter_list|(
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|default_gt_pch_use_address
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|mmap_gt_pch_get_address
parameter_list|(
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mmap_gt_pch_use_address
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The structure is defined in hosthooks.h.  */
end_comment

begin_define
define|#
directive|define
name|HOST_HOOKS_INITIALIZER
value|{		\   HOST_HOOKS_EXTRA_SIGNALS,			\   HOST_HOOKS_GT_PCH_GET_ADDRESS,		\   HOST_HOOKS_GT_PCH_USE_ADDRESS			\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_HOST_HOOKS_DEF_H */
end_comment

end_unit

