begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"errarg.h"
end_include

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_include
include|#
directive|include
file|"stringclass.h"
end_include

begin_include
include|#
directive|include
file|"cset.h"
end_include

begin_include
include|#
directive|include
file|"cmap.h"
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_function_decl
name|unsigned
name|hash_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|next_size
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|string
name|capitalize_fields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|reverse_fields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|abbreviate_fields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|period_before_last_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|period_before_initial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|period_before_hyphen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|period_before_other
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|sort_fields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|annotation_field
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|annotation_macro
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|discard_fields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|articles
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|abbreviate_label_ranges
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|label_range_indicator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|date_as_label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|join_authors_exactly_two
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|join_authors_last_two
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|join_authors_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|separate_label_second_parts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|et_al
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|et_al_min_elide
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|et_al_min_total
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|compatible_flag
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|set_label_spec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_date_label_spec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_short_label_spec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|short_label_flag
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|clear_labels
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|command_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|errarg
modifier|&
name|arg1
init|=
name|empty_errarg
parameter_list|,
specifier|const
name|errarg
modifier|&
name|arg2
init|=
name|empty_errarg
parameter_list|,
specifier|const
name|errarg
modifier|&
name|arg3
init|=
name|empty_errarg
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|reference
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|compute_labels
parameter_list|(
name|reference
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

