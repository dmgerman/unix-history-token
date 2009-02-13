begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for variables relating to reading the source file.    Used by parsers, lexical analyzers, and error message routines.    Copyright (C) 1993, 1997, 1998, 2000, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_INPUT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_INPUT_H
end_define

begin_include
include|#
directive|include
file|"line-map.h"
end_include

begin_decl_stmt
specifier|extern
name|struct
name|line_maps
name|line_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The location for declarations in "<built-in>" */
end_comment

begin_define
define|#
directive|define
name|BUILTINS_LOCATION
value|((source_location) 2)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MAPPED_LOCATION
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The name of the source file involved.  */
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
comment|/* The line-location in the source file.  */
name|int
name|line
decl_stmt|;
name|int
name|column
decl_stmt|;
block|}
name|expanded_location
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|expanded_location
name|expand_location
parameter_list|(
name|source_location
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UNKNOWN_LOCATION
value|((source_location) 0)
end_define

begin_typedef
typedef|typedef
name|source_location
name|location_t
typedef|;
end_typedef

begin_comment
comment|/* deprecated typedef */
end_comment

begin_typedef
typedef|typedef
name|source_location
name|source_locus
typedef|;
end_typedef

begin_comment
comment|/* to be removed */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! USE_MAPPED_LOCATION */
end_comment

begin_decl_stmt
name|struct
name|location_s
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The name of the source file involved.  */
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
comment|/* The line-location in the source file.  */
name|int
name|line
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|location_s
name|expanded_location
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|location_s
name|location_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|location_t
modifier|*
name|source_locus
typedef|;
end_typedef

begin_define
define|#
directive|define
name|expand_location
parameter_list|(
name|FILELINE
parameter_list|)
value|(FILELINE)
end_define

begin_decl_stmt
specifier|extern
name|location_t
name|unknown_location
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNKNOWN_LOCATION
value|unknown_location
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_MAPPED_LOCATION */
end_comment

begin_struct
struct|struct
name|file_stack
block|{
name|struct
name|file_stack
modifier|*
name|next
decl_stmt|;
name|location_t
name|location
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Top-level source file.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|main_input_filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|location_t
name|input_location
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MAPPED_LOCATION
end_ifdef

begin_function_decl
specifier|extern
name|void
name|push_srcloc
parameter_list|(
name|location_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! USE_MAPPED_LOCATION */
end_comment

begin_function_decl
specifier|extern
name|void
name|push_srcloc
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_MAPPED_LOCATION */
end_comment

begin_function_decl
specifier|extern
name|void
name|pop_srcloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restore_input_file_stack
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LOCATION_FILE
parameter_list|(
name|LOC
parameter_list|)
value|((expand_location (LOC)).file)
end_define

begin_define
define|#
directive|define
name|LOCATION_LINE
parameter_list|(
name|LOC
parameter_list|)
value|((expand_location (LOC)).line)
end_define

begin_define
define|#
directive|define
name|input_line
value|LOCATION_LINE(input_location)
end_define

begin_define
define|#
directive|define
name|input_filename
value|LOCATION_FILE(input_location)
end_define

begin_comment
comment|/* Stack of currently pending input files.    The line member is not accurate for the innermost file on the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|file_stack
modifier|*
name|input_file_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Incremented on each change to input_file_stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|input_file_stack_tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of bits available for input_file_stack_tick.  */
end_comment

begin_define
define|#
directive|define
name|INPUT_FILE_STACK_BITS
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

