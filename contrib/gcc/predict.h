begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file contains the definitions and documentation for the    builtins used in the GNU compiler.    Copyright (C) 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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

begin_decl_stmt
specifier|extern
name|void
name|predict_insn_def
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|br_predictor
operator|,
expr|enum
name|prediction
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|predict_insn
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|br_predictor
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Avoid unneeded dependency on basic_block.h  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BASIC_BLOCK
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|predict_edge
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
expr|enum
name|br_predictor
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|predict_edge_def
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
expr|enum
name|br_predictor
operator|,
expr|enum
name|prediction
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

