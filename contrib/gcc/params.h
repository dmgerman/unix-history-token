begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* params.h - Run-time parameters.    Copyright (C) 2001 Free Software Foundation, Inc.    Written by Mark Mitchell<mark@codesourcery.com>.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This module provides a means for setting integral parameters    dynamically.  Instead of encoding magic numbers in various places,    use this module to organize all the magic numbers in a single    place.  The values of the parameters can be set on the    command-line, thereby providing a way to control the amount of    effort spent on particular optimization passes, or otherwise tune    the behavior of the compiler.     Since their values can be set on the command-line, these parameters    should not be used for non-dynamic memory allocation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_PARAMS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_PARAMS_H
end_define

begin_comment
comment|/* No parameter shall have this value.  */
end_comment

begin_define
define|#
directive|define
name|INVALID_PARAM_VAL
value|(-1)
end_define

begin_comment
comment|/* The information associated with each parameter.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|param_info
block|{
comment|/* The name used with the `--param<name>=<value>' switch to set this      value.  */
specifier|const
name|char
modifier|*
specifier|const
name|option
decl_stmt|;
comment|/* The associated value.  */
name|int
name|value
decl_stmt|;
comment|/* A short description of the option.  */
specifier|const
name|char
modifier|*
specifier|const
name|help
decl_stmt|;
block|}
name|param_info
typedef|;
end_typedef

begin_comment
comment|/* An array containing the compiler parameters and their current    values.  */
end_comment

begin_decl_stmt
specifier|extern
name|param_info
modifier|*
name|compiler_params
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add the N PARAMS to the current list of compiler parameters.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_params
name|PARAMS
argument_list|(
operator|(
specifier|const
name|param_info
name|params
index|[]
operator|,
name|size_t
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the VALUE associated with the parameter given by NAME.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_param_value
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|int
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The parameters in use by language-independent code.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|compiler_param
block|{
define|#
directive|define
name|DEFPARAM
parameter_list|(
name|enumerator
parameter_list|,
name|option
parameter_list|,
name|msgid
parameter_list|,
define|default) \   enumerator,
include|#
directive|include
file|"params.def"
undef|#
directive|undef
name|DEFPARAM
name|LAST_PARAM
block|}
name|compiler_param
typedef|;
end_typedef

begin_comment
comment|/* The value of the parameter given by ENUM.  */
end_comment

begin_define
define|#
directive|define
name|PARAM_VALUE
parameter_list|(
name|ENUM
parameter_list|)
define|\
value|(compiler_params[(int) ENUM].value)
end_define

begin_comment
comment|/* Macros for the various parameters.  */
end_comment

begin_define
define|#
directive|define
name|MAX_INLINE_INSNS
define|\
value|PARAM_VALUE (PARAM_MAX_INLINE_INSNS)
end_define

begin_define
define|#
directive|define
name|MAX_DELAY_SLOT_INSN_SEARCH
define|\
value|PARAM_VALUE (PARAM_MAX_DELAY_SLOT_INSN_SEARCH)
end_define

begin_define
define|#
directive|define
name|MAX_DELAY_SLOT_LIVE_SEARCH
define|\
value|PARAM_VALUE (PARAM_MAX_DELAY_SLOT_LIVE_SEARCH)
end_define

begin_define
define|#
directive|define
name|MAX_PENDING_LIST_LENGTH
define|\
value|PARAM_VALUE (PARAM_MAX_PENDING_LIST_LENGTH)
end_define

begin_define
define|#
directive|define
name|MAX_GCSE_MEMORY
define|\
value|((size_t) PARAM_VALUE (PARAM_MAX_GCSE_MEMORY))
end_define

begin_define
define|#
directive|define
name|MAX_GCSE_PASSES
define|\
value|PARAM_VALUE (PARAM_MAX_GCSE_PASSES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_PARAMS_H */
end_comment

end_unit

