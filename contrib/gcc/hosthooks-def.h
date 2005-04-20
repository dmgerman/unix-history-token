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

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_GET_ADDRESS
value|hook_voidp_size_t_null
end_define

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_USE_ADDRESS
value|hook_bool_voidp_size_t_false
end_define

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

