begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IPA handling of references.    Copyright (C) 2004-2005 Free Software Foundation, Inc.    Contributed by Kenneth Zadeck<zadeck@naturalbridge.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_IPA_REFERENCE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_IPA_REFERENCE_H
end_define

begin_include
include|#
directive|include
file|"bitmap.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_comment
comment|/* The static variables defined within the compilation unit that are    loaded or stored directly by function that owns this structure.  */
end_comment

begin_struct
struct|struct
name|ipa_reference_local_vars_info_d
block|{
name|bitmap
name|statics_read
decl_stmt|;
name|bitmap
name|statics_written
decl_stmt|;
comment|/* Set when this function calls another function external to the      compilation unit or if the function has a asm clobber of memory.      In general, such calls are modeled as reading and writing all      variables (both bits on) but sometime there are attributes on the      called function so we can do better.  */
name|bool
name|calls_read_all
decl_stmt|;
name|bool
name|calls_write_all
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipa_reference_global_vars_info_d
block|{
name|bitmap
name|statics_read
decl_stmt|;
name|bitmap
name|statics_written
decl_stmt|;
name|bitmap
name|statics_not_read
decl_stmt|;
name|bitmap
name|statics_not_written
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Statics that are read and written by some set of functions. The    local ones are based on the loads and stores local to the function.    The global ones are based on the local info as well as the    transitive closure of the functions that are called.  The    structures are separated to allow the global structures to be    shared between several functions since every function within a    strongly connected component will have the same information.  This    sharing saves both time and space in the computation of the vectors    as well as their translation from decl_uid form to ann_uid    form.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ipa_reference_local_vars_info_d
modifier|*
name|ipa_reference_local_vars_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ipa_reference_global_vars_info_d
modifier|*
name|ipa_reference_global_vars_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ipa_reference_vars_info_d
block|{
name|ipa_reference_local_vars_info_t
name|local
decl_stmt|;
name|ipa_reference_global_vars_info_t
name|global
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ipa_reference_vars_info_d
modifier|*
name|ipa_reference_vars_info_t
typedef|;
end_typedef

begin_comment
comment|/* In ipa-reference.c  */
end_comment

begin_function_decl
name|bitmap
name|ipa_reference_get_read_local
parameter_list|(
name|tree
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bitmap
name|ipa_reference_get_written_local
parameter_list|(
name|tree
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bitmap
name|ipa_reference_get_read_global
parameter_list|(
name|tree
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bitmap
name|ipa_reference_get_written_global
parameter_list|(
name|tree
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bitmap
name|ipa_reference_get_not_read_global
parameter_list|(
name|tree
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bitmap
name|ipa_reference_get_not_written_global
parameter_list|(
name|tree
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_IPA_REFERENCE_H  */
end_comment

end_unit

