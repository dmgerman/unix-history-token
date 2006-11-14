begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for transformations based on profile information for values.    Copyright (C) 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
name|histogram_value
block|{
name|rtx
name|value
decl_stmt|;
comment|/* The value to profile.  */
name|enum
name|machine_mode
name|mode
decl_stmt|;
comment|/* And its mode.  */
name|rtx
name|seq
decl_stmt|;
comment|/* Insns required to count the profiled value.  */
name|rtx
name|insn
decl_stmt|;
comment|/* Insn before that to measure.  */
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
name|int
name|steps
decl_stmt|;
comment|/* Number of values in it.  */
name|int
name|may_be_less
decl_stmt|;
comment|/* May the value be below?  */
name|int
name|may_be_more
decl_stmt|;
comment|/* Or above.  */
block|}
name|intvl
struct|;
comment|/* Interval histogram data.  */
struct|struct
block|{
name|int
name|may_be_other
decl_stmt|;
comment|/* If the value may be non-positive or not 2^k.  */
block|}
name|pow2
struct|;
comment|/* Power of 2 histogram data.  */
block|}
name|hdata
union|;
comment|/* Profiled information specific data.  */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|find_values_to_profile
parameter_list|(
name|unsigned
modifier|*
parameter_list|,
name|struct
name|histogram_value
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_profiled_values
parameter_list|(
name|unsigned
parameter_list|,
name|struct
name|histogram_value
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

end_unit

