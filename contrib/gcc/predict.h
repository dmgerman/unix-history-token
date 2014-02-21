begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for branch prediction routines in the GNU compiler.    Copyright (C) 2001, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_PREDICT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_PREDICT_H
end_define

begin_define
define|#
directive|define
name|DEF_PREDICTOR
parameter_list|(
name|ENUM
parameter_list|,
name|NAME
parameter_list|,
name|HITRATE
parameter_list|,
name|FLAGS
parameter_list|)
value|ENUM,
end_define

begin_enum
enum|enum
name|br_predictor
block|{
include|#
directive|include
file|"predict.def"
comment|/* Upper bound on non-language-specific builtins.  */
name|END_PREDICTORS
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEF_PREDICTOR
end_undef

begin_enum
enum|enum
name|prediction
block|{
name|NOT_TAKEN
block|,
name|TAKEN
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|predict_insn_def
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|br_predictor
parameter_list|,
name|enum
name|prediction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|counts_to_freqs
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
comment|/* GCC_PREDICT_H */
end_comment

end_unit

