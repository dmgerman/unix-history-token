begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for transformations based on profile information for values.    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_VALUE_PROF_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_VALUE_PROF_H
end_define

begin_comment
comment|/* Supported histogram types.  */
end_comment

begin_enum
enum|enum
name|hist_type
block|{
name|HIST_TYPE_INTERVAL
block|,
comment|/* Measures histogram of values inside a specified 			   interval.  */
name|HIST_TYPE_POW2
block|,
comment|/* Histogram of power of 2 values.  */
name|HIST_TYPE_SINGLE_VALUE
block|,
comment|/* Tries to identify the value that is (almost) 			   always constant.  */
name|HIST_TYPE_CONST_DELTA
comment|/* Tries to identify the (almost) always constant 			   difference between two evaluations of a value.  */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|COUNTER_FOR_HIST_TYPE
parameter_list|(
name|TYPE
parameter_list|)
value|((int) (TYPE) + GCOV_FIRST_VALUE_COUNTER)
end_define

begin_define
define|#
directive|define
name|HIST_TYPE_FOR_COUNTER
parameter_list|(
name|COUNTER
parameter_list|)
define|\
value|((enum hist_type) ((COUNTER) - GCOV_FIRST_VALUE_COUNTER))
end_define

begin_comment
comment|/* The value to measure.  */
end_comment

begin_struct
struct|struct
name|histogram_value_t
block|{
struct|struct
block|{
name|tree
name|value
decl_stmt|;
comment|/* The value to profile.  */
name|tree
name|stmt
decl_stmt|;
comment|/* Insn containing the value.  */
name|gcov_type
modifier|*
name|counters
decl_stmt|;
comment|/* Pointer to first counter.  */
name|struct
name|histogram_value_t
modifier|*
name|next
decl_stmt|;
comment|/* Linked list pointer.  */
block|}
name|hvalue
struct|;
name|enum
name|hist_type
name|type
decl_stmt|;
comment|/* Type of information to measure.  */
name|unsigned
name|n_counters
decl_stmt|;
comment|/* Number of required counters.  */
union|union
block|{
struct|struct
block|{
name|int
name|int_start
decl_stmt|;
comment|/* First value in interval.  */
name|unsigned
name|int
name|steps
decl_stmt|;
comment|/* Number of values in it.  */
block|}
name|intvl
struct|;
comment|/* Interval histogram data.  */
block|}
name|hdata
union|;
comment|/* Profiled information specific data.  */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|histogram_value_t
modifier|*
name|histogram_value
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|histogram_value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|histogram_value
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|VEC
argument_list|(
name|histogram_value
argument_list|,
name|heap
argument_list|)
operator|*
name|histogram_values
expr_stmt|;
end_typedef

begin_comment
comment|/* Hooks registration.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tree_register_value_prof_hooks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* IR-independent entry points.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|find_values_to_profile
parameter_list|(
name|histogram_values
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|value_profile_transformations
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* External declarations for edge-based profiling.  */
end_comment

begin_struct
struct|struct
name|profile_hooks
block|{
comment|/* Insert code to initialize edge profiler.  */
name|void
function_decl|(
modifier|*
name|init_edge_profiler
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Insert code to increment an edge count.  */
name|void
function_decl|(
modifier|*
name|gen_edge_profiler
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|edge
parameter_list|)
function_decl|;
comment|/* Insert code to increment the interval histogram counter.  */
name|void
function_decl|(
modifier|*
name|gen_interval_profiler
function_decl|)
parameter_list|(
name|histogram_value
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
comment|/* Insert code to increment the power of two histogram counter.  */
name|void
function_decl|(
modifier|*
name|gen_pow2_profiler
function_decl|)
parameter_list|(
name|histogram_value
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
comment|/* Insert code to find the most common value.  */
name|void
function_decl|(
modifier|*
name|gen_one_value_profiler
function_decl|)
parameter_list|(
name|histogram_value
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
comment|/* Insert code to find the most common value of a difference between two      evaluations of an expression.  */
name|void
function_decl|(
modifier|*
name|gen_const_delta_profiler
function_decl|)
parameter_list|(
name|histogram_value
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* In profile.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_branch_prob
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|branch_prob
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|end_branch_prob
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tree_register_profile_hooks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-profile.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|profile_hooks
name|tree_profile_hooks
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_VALUE_PROF_H */
end_comment

end_unit

