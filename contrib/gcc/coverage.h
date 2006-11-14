begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coverage.h - Defines data exported from coverage.c    Copyright (C) 1998, 1999, 2000, 2001, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_COVERAGE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_COVERAGE_H
end_define

begin_include
include|#
directive|include
file|"gcov-io.h"
end_include

begin_function_decl
specifier|extern
name|void
name|coverage_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coverage_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coverage_read_counts_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Complete the coverage information for the current function. Once    per function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|coverage_end_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Start outputting coverage information for the current    function. Repeatable per function.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|coverage_begin_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate some counters. Repeatable per function.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|coverage_counter_alloc
parameter_list|(
name|unsigned
comment|/*counter*/
parameter_list|,
name|unsigned
comment|/*num*/
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use a counter from the most recent allocation.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|coverage_counter_ref
parameter_list|(
name|unsigned
comment|/*counter*/
parameter_list|,
name|unsigned
comment|/*num*/
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get all the counters for the current function.  */
end_comment

begin_function_decl
specifier|extern
name|gcov_type
modifier|*
name|get_coverage_counts
parameter_list|(
name|unsigned
comment|/*counter*/
parameter_list|,
name|unsigned
comment|/*expected*/
parameter_list|,
specifier|const
name|struct
name|gcov_ctr_summary
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

