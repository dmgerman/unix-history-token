begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Exception Handling interface routines.    Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.    Contributed by Mike Stump<mrs@cygnus.com>.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_struct_decl
struct_decl|struct
name|function
struct_decl|;
end_struct_decl

begin_comment
comment|/* Per-function EH data.  Used only in except.c, but GC and others    manipulate pointers to the opaque type.  */
end_comment

begin_struct_decl
struct_decl|struct
name|eh_status
struct_decl|;
end_struct_decl

begin_comment
comment|/* Internal structure describing a region.  */
end_comment

begin_struct_decl
struct_decl|struct
name|eh_region
struct_decl|;
end_struct_decl

begin_comment
comment|/* Test: is exception handling turned on?  */
end_comment

begin_function_decl
specifier|extern
name|int
name|doing_eh
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Note that the current EH region (if any) may contain a throw, or a    call to a function which itself may contain a throw.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|note_eh_region_may_contain_throw
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|note_current_region_may_contain_throw
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Invokes CALLBACK for every exception handler label.  Only used by old    loop hackery; should not be used by new code.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|for_each_eh_label
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|rtx
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Invokes CALLBACK for every exception region in the current function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|for_each_eh_region
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine if the given INSN can throw an exception.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|can_throw_internal_1
parameter_list|(
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|can_throw_internal
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|can_throw_external_1
parameter_list|(
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|can_throw_external
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set TREE_NOTHROW and cfun->all_throwers_are_sibcalls.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|set_nothrow_function_flags
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* After initial rtl generation, call back to finish generating    exception support code.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|finish_eh_generation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_eh
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_eh_for_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|reachable_handlers
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_remove_eh_handler
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|convert_from_eh_region_ranges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|convert_to_eh_region_ranges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_exception_handler_labels
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|current_function_has_exception_handlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_function_exception_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_builtin_unwind_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_builtin_eh_return_data_regno
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_builtin_extract_return_addr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_builtin_init_dwarf_reg_sizes
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_builtin_frob_return_addr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_builtin_dwarf_sp_column
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_builtin_eh_return
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_eh_return
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_builtin_extend_pointer
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_exception_pointer
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_exception_filter
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|tree
function_decl|(
modifier|*
name|duplicate_eh_regions_map
function_decl|)
parameter_list|(
name|tree
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|duplicate_eh_regions
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|duplicate_eh_regions_map
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sjlj_emit_function_exit_after
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_init_unwind_resume_libfunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|eh_region
modifier|*
name|gen_eh_region_cleanup
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|,
name|struct
name|eh_region
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|eh_region
modifier|*
name|gen_eh_region_try
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|eh_region
modifier|*
name|gen_eh_region_catch
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|eh_region
modifier|*
name|gen_eh_region_allowed
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|eh_region
modifier|*
name|gen_eh_region_must_not_throw
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_eh_region_number
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|get_eh_region_may_contain_throw
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_eh_region_tree_label
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_eh_region_tree_label
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|foreach_reachable_handler
parameter_list|(
name|int
parameter_list|,
name|bool
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|eh_region
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|collect_eh_region_array
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_resx_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|verify_eh_tree
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_eh_tree
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|eh_region_outer_p
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|eh_region_outermost
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tree-eh.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_stmt_to_eh_region_fn
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|remove_stmt_from_eh_region_fn
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lookup_stmt_eh_region_fn
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lookup_stmt_eh_region
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|verify_eh_edges
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If non-NULL, this is a function that returns an expression to be    executed if an unhandled exception is propagated out of a cleanup    region.  For example, in C++, an exception thrown by a destructor    during stack unwinding is required to result in a call to    `std::terminate', so the C++ version of this function returns a    CALL_EXPR for `std::terminate'.  */
end_comment

begin_function_decl
specifier|extern
name|tree
function_decl|(
modifier|*
name|lang_protect_cleanup_actions
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if type A catches type B.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|lang_eh_type_covers
function_decl|)
parameter_list|(
name|tree
name|a
parameter_list|,
name|tree
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map a type to a runtime object to match type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
function_decl|(
modifier|*
name|lang_eh_runtime_type
function_decl|)
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Just because the user configured --with-sjlj-exceptions=no doesn't    mean that we can use call frame exceptions.  Detect that the target    has appropriate support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MUST_USE_SJLJ_EXCEPTIONS
end_ifndef

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|EH_RETURN_DATA_REGNO
argument_list|)
expr|\
operator|&&
operator|(
name|defined
argument_list|(
name|TARGET_UNWIND_INFO
argument_list|)
expr|\
operator|||
operator|(
name|DWARF2_UNWIND_INFO
expr|\
operator|&&
operator|(
name|defined
argument_list|(
name|EH_RETURN_HANDLER_RTX
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|HAVE_eh_return
argument_list|)
operator|)
operator|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|MUST_USE_SJLJ_EXCEPTIONS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MUST_USE_SJLJ_EXCEPTIONS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_SJLJ_EXCEPTIONS
end_ifdef

begin_if
if|#
directive|if
name|CONFIG_SJLJ_EXCEPTIONS
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|USING_SJLJ_EXCEPTIONS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CONFIG_SJLJ_EXCEPTIONS
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|USING_SJLJ_EXCEPTIONS
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|EH_RETURN_DATA_REGNO
end_ifndef

begin_error
error|#
directive|error
literal|"EH_RETURN_DATA_REGNO required"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EH_RETURN_HANDLER_RTX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_eh_return
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"EH_RETURN_HANDLER_RTX or eh_return required"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DWARF2_UNWIND_INFO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_UNWIND_INFO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"{DWARF2,TARGET}_UNWIND_INFO required"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USING_SJLJ_EXCEPTIONS
value|MUST_USE_SJLJ_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|throw_stmt_node
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|tree
name|stmt
decl_stmt|;
name|int
name|region_nr
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|struct
name|htab
modifier|*
name|get_eh_throw_stmt_table
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_eh_throw_stmt_table
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|struct
name|htab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
end_ifdef

begin_function_decl
specifier|extern
name|void
name|verify_eh_throw_table_statements
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

