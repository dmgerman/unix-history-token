begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default macros to initialize an rtl_hooks data structure.    Copyright 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_RTL_HOOKS_DEF_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_RTL_HOOKS_DEF_H
end_define

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_define
define|#
directive|define
name|RTL_HOOKS_GEN_LOWPART
value|gen_lowpart_general
end_define

begin_define
define|#
directive|define
name|RTL_HOOKS_GEN_LOWPART_NO_EMIT
value|gen_lowpart_no_emit_general
end_define

begin_define
define|#
directive|define
name|RTL_HOOKS_REG_NONZERO_REG_BITS
value|reg_nonzero_bits_general
end_define

begin_define
define|#
directive|define
name|RTL_HOOKS_REG_NUM_SIGN_BIT_COPIES
value|reg_num_sign_bit_copies_general
end_define

begin_define
define|#
directive|define
name|RTL_HOOKS_REG_TRUNCATED_TO_MODE
value|reg_truncated_to_mode_general
end_define

begin_comment
comment|/* The structure is defined in rtl.h.  */
end_comment

begin_define
define|#
directive|define
name|RTL_HOOKS_INITIALIZER
value|{			\   RTL_HOOKS_GEN_LOWPART,			\   RTL_HOOKS_GEN_LOWPART_NO_EMIT,		\   RTL_HOOKS_REG_NONZERO_REG_BITS,		\   RTL_HOOKS_REG_NUM_SIGN_BIT_COPIES,		\   RTL_HOOKS_REG_TRUNCATED_TO_MODE,		\ }
end_define

begin_function_decl
specifier|extern
name|rtx
name|gen_lowpart_general
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_lowpart_no_emit_general
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|reg_nonzero_bits_general
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|reg_num_sign_bit_copies_general
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|reg_truncated_to_mode_general
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_RTL_HOOKS_DEF_H */
end_comment

end_unit

