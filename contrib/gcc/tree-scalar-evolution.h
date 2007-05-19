begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Scalar evolution detector.    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Sebastian Pop<s.pop@laposte.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_SCALAR_EVOLUTION_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_SCALAR_EVOLUTION_H
end_define

begin_function_decl
specifier|extern
name|tree
name|number_of_iterations_in_loop
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_loop_exit_condition
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scev_initialize
parameter_list|(
name|struct
name|loops
modifier|*
name|loops
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scev_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scev_finalize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|analyze_scalar_evolution
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|instantiate_parameters
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gather_stats_on_scev_database
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scev_analysis
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|scev_const_prop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|simple_iv
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|affine_iv
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_SCALAR_EVOLUTION_H  */
end_comment

end_unit

