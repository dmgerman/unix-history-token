begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Type based alias analysis.    Copyright (C) 2004 Free Software Foundation, Inc.    Contributed by Kenneth Zadeck<zadeck@naturalbridge.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_IPA_TYPE_ESCAPE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_IPA_TYPE_ESCAPE_H
end_define

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_function_decl
name|bool
name|ipa_type_escape_type_contained_p
parameter_list|(
name|tree
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ipa_type_escape_field_does_not_clobber_p
parameter_list|(
name|tree
name|record_type
parameter_list|,
name|tree
name|field_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipa_type_escape_star_count_of_interesting_type
parameter_list|(
name|tree
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipa_type_escape_star_count_of_interesting_or_array_type
parameter_list|(
name|tree
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_IPA_TYPE_ESCAPE_H  */
end_comment

end_unit

