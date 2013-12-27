begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default initializers for a generic GCC target.    Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007    Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_comment
comment|/* See target.h for a description of what this file contains and how to    use it.     We want to have non-NULL default definitions of all hook functions,    even if they do nothing.  */
end_comment

begin_comment
comment|/* Note that if one of these macros must be defined in an OS .h file    rather than the .c file, then we need to wrap the default    definition in a #ifndef, since files include tm.h before this one.  */
end_comment

begin_comment
comment|/* Assembler output.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_OPEN_PAREN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_OPEN_PAREN
value|"("
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_CLOSE_PAREN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_CLOSE_PAREN
value|")"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ASM_BYTE_OP
value|"\t.byte\t"
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_ALIGNED_HI_OP
value|"\t.short\t"
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_ALIGNED_SI_OP
value|"\t.long\t"
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_ALIGNED_DI_OP
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_ALIGNED_TI_OP
value|NULL
end_define

begin_comment
comment|/* GAS and SYSV4 assemblers accept these.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OBJECT_FORMAT_ELF
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_HI_OP
value|"\t.2byte\t"
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_SI_OP
value|"\t.4byte\t"
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_DI_OP
value|"\t.8byte\t"
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_TI_OP
value|NULL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_HI_OP
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_SI_OP
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_DI_OP
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_TI_OP
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJECT_FORMAT_ELF */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_INTEGER
value|default_assemble_integer
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_GLOBALIZE_LABEL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_GLOBALIZE_LABEL
value|default_globalize_label
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_EMIT_UNWIND_LABEL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_EMIT_UNWIND_LABEL
value|default_emit_unwind_label
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_EMIT_EXCEPT_TABLE_LABEL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_EMIT_EXCEPT_TABLE_LABEL
value|default_emit_except_table_label
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_UNWIND_EMIT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_UNWIND_EMIT
value|default_unwind_emit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_INTERNAL_LABEL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_INTERNAL_LABEL
value|default_internal_label
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ARM_TTYPE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_TTYPE
value|hook_bool_rtx_false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_ASSEMBLE_VISIBILITY
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_ASSEMBLE_VISIBILITY
value|default_assemble_visibility
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ASM_FUNCTION_PROLOGUE
value|default_function_pro_epilogue
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FUNCTION_EPILOGUE
value|default_function_pro_epilogue
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FUNCTION_END_PROLOGUE
value|no_asm_to_stream
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FUNCTION_BEGIN_EPILOGUE
value|no_asm_to_stream
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_RELOC_RW_MASK
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_RELOC_RW_MASK
value|default_reloc_rw_mask
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_SELECT_SECTION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_SECTION
value|default_select_section
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_UNIQUE_SECTION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_UNIQUE_SECTION
value|default_unique_section
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_FUNCTION_RODATA_SECTION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_FUNCTION_RODATA_SECTION
value|default_function_rodata_section
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_SELECT_RTX_SECTION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_RTX_SECTION
value|default_select_rtx_section
end_define

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
name|TARGET_ASM_CONSTRUCTOR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_COLLECT2
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|CTORS_SECTION_ASM_OP
end_ifdef

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|default_ctor_section_asm_out_constructor
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_ASM_NAMED_SECTION
end_ifdef

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|default_named_section_asm_out_constructor
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|default_stabs_asm_out_constructor
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|TARGET_ASM_DESTRUCTOR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_COLLECT2
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DTORS_SECTION_ASM_OP
end_ifdef

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|default_dtor_section_asm_out_destructor
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_ASM_NAMED_SECTION
end_ifdef

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|default_named_section_asm_out_destructor
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|default_stabs_asm_out_destructor
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ASM_OUTPUT_MI_THUNK
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_CAN_OUTPUT_MI_THUNK
value|hook_bool_tree_hwi_hwi_tree_false
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_HAVE_CTORS_DTORS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_ASM_CONSTRUCTOR
argument_list|)
operator|&&
name|defined
argument_list|(
name|TARGET_ASM_DESTRUCTOR
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_HAVE_CTORS_DTORS
value|true
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_HAVE_CTORS_DTORS
value|false
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_HAVE_SWITCHABLE_BSS_SECTIONS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_HAVE_SWITCHABLE_BSS_SECTIONS
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_INIT_SECTIONS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_INIT_SECTIONS
value|hook_void_void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_ASM_NAMED_SECTION
end_ifdef

begin_define
define|#
directive|define
name|TARGET_HAVE_NAMED_SECTIONS
value|true
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|default_no_named_section
end_define

begin_define
define|#
directive|define
name|TARGET_HAVE_NAMED_SECTIONS
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_INVALID_WITHIN_DOLOOP
end_ifndef

begin_define
define|#
directive|define
name|TARGET_INVALID_WITHIN_DOLOOP
value|default_invalid_within_doloop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VALID_DLLIMPORT_ATTRIBUTE_P
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VALID_DLLIMPORT_ATTRIBUTE_P
value|hook_bool_tree_true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_HAVE_TLS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_HAVE_TLS
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_HAVE_SRODATA_SECTION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_HAVE_SRODATA_SECTION
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_TERMINATE_DW2_EH_FRAME_INFO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|EH_FRAME_SECTION_NAME
end_ifdef

begin_define
define|#
directive|define
name|TARGET_TERMINATE_DW2_EH_FRAME_INFO
value|false
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_TERMINATE_DW2_EH_FRAME_INFO
value|true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_DWARF_REGISTER_SPAN
value|hook_rtx_rtx_null
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_FILE_START
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START
value|default_file_start
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_FILE_END
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|hook_void_void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_EXTRA_LIVE_ON_ENTRY
end_ifndef

begin_define
define|#
directive|define
name|TARGET_EXTRA_LIVE_ON_ENTRY
value|hook_void_bitmap
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_FILE_START_APP_OFF
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_APP_OFF
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_EXTERNAL_LIBCALL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_EXTERNAL_LIBCALL
value|default_external_libcall
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_MARK_DECL_PRESERVED
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_MARK_DECL_PRESERVED
value|hook_void_constcharptr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_OUTPUT_ANCHOR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_OUTPUT_DEF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_ASM_OUTPUT_ANCHOR
value|default_asm_output_anchor
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ASM_OUTPUT_ANCHOR
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_OUTPUT_DWARF_DTPREL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_OUTPUT_DWARF_DTPREL
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ASM_ALIGNED_INT_OP
define|\
value|{TARGET_ASM_ALIGNED_HI_OP,		\ 			TARGET_ASM_ALIGNED_SI_OP,		\ 			TARGET_ASM_ALIGNED_DI_OP,		\ 			TARGET_ASM_ALIGNED_TI_OP}
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNALIGNED_INT_OP
define|\
value|{TARGET_ASM_UNALIGNED_HI_OP,		\ 			TARGET_ASM_UNALIGNED_SI_OP,		\ 			TARGET_ASM_UNALIGNED_DI_OP,		\ 			TARGET_ASM_UNALIGNED_TI_OP}
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_OUT
value|{TARGET_ASM_OPEN_PAREN,			\ 			TARGET_ASM_CLOSE_PAREN,			\ 			TARGET_ASM_BYTE_OP,			\ 			TARGET_ASM_ALIGNED_INT_OP,		\ 			TARGET_ASM_UNALIGNED_INT_OP,		\ 			TARGET_ASM_INTEGER,			\ 			TARGET_ASM_GLOBALIZE_LABEL,		\                         TARGET_ASM_EMIT_UNWIND_LABEL,           \ 			TARGET_ASM_EMIT_EXCEPT_TABLE_LABEL,	\ 			TARGET_UNWIND_EMIT,			\ 			TARGET_ASM_INTERNAL_LABEL,		\ 			TARGET_ASM_TTYPE,			\ 			TARGET_ASM_ASSEMBLE_VISIBILITY,		\ 			TARGET_ASM_FUNCTION_PROLOGUE,		\ 			TARGET_ASM_FUNCTION_END_PROLOGUE,	\ 			TARGET_ASM_FUNCTION_BEGIN_EPILOGUE,	\ 			TARGET_ASM_FUNCTION_EPILOGUE,		\ 			TARGET_ASM_INIT_SECTIONS,		\ 			TARGET_ASM_NAMED_SECTION,		\ 			TARGET_ASM_RELOC_RW_MASK,		\ 			TARGET_ASM_SELECT_SECTION,		\ 			TARGET_ASM_SELECT_RTX_SECTION,		\ 			TARGET_ASM_UNIQUE_SECTION,		\ 			TARGET_ASM_FUNCTION_RODATA_SECTION,	\ 			TARGET_ASM_CONSTRUCTOR,			\ 			TARGET_ASM_DESTRUCTOR,                  \                         TARGET_ASM_OUTPUT_MI_THUNK,             \                         TARGET_ASM_CAN_OUTPUT_MI_THUNK,         \                         TARGET_ASM_FILE_START,                  \                         TARGET_ASM_FILE_END,			\ 			TARGET_ASM_EXTERNAL_LIBCALL,            \                         TARGET_ASM_MARK_DECL_PRESERVED,		\ 			TARGET_ASM_OUTPUT_ANCHOR,		\ 			TARGET_ASM_OUTPUT_DWARF_DTPREL}
end_define

begin_comment
comment|/* Scheduler hooks.  All of these default to null pointers, which    haifa-sched.c looks for and handles.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SCHED_ADJUST_COST
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_ADJUST_PRIORITY
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_ISSUE_RATE
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_VARIABLE_ISSUE
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_INIT
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_FINISH
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_INIT_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_FINISH_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_REORDER
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_REORDER2
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_DEPENDENCIES_EVALUATION_HOOK
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_INIT_DFA_PRE_CYCLE_INSN
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_DFA_PRE_CYCLE_INSN
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_INIT_DFA_POST_CYCLE_INSN
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_DFA_POST_CYCLE_INSN
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD_GUARD
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_DFA_NEW_CYCLE
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_IS_COSTLY_DEPENDENCE
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_ADJUST_COST_2
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_H_I_D_EXTENDED
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_SPECULATE_INSN
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_NEEDS_BLOCK_P
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_GEN_CHECK
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD_GUARD_SPEC
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_SET_SCHED_FLAGS
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED
define|\
value|{TARGET_SCHED_ADJUST_COST,					\    TARGET_SCHED_ADJUST_PRIORITY,				\    TARGET_SCHED_ISSUE_RATE,					\    TARGET_SCHED_VARIABLE_ISSUE,					\    TARGET_SCHED_INIT,						\    TARGET_SCHED_FINISH,						\    TARGET_SCHED_INIT_GLOBAL,					\    TARGET_SCHED_FINISH_GLOBAL,					\    TARGET_SCHED_REORDER,					\    TARGET_SCHED_REORDER2,					\    TARGET_SCHED_DEPENDENCIES_EVALUATION_HOOK,			\    TARGET_SCHED_INIT_DFA_PRE_CYCLE_INSN,			\    TARGET_SCHED_DFA_PRE_CYCLE_INSN,				\    TARGET_SCHED_INIT_DFA_POST_CYCLE_INSN,			\    TARGET_SCHED_DFA_POST_CYCLE_INSN,				\    TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD,		\    TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD_GUARD,	\    TARGET_SCHED_DFA_NEW_CYCLE,					\    TARGET_SCHED_IS_COSTLY_DEPENDENCE,                           \    TARGET_SCHED_ADJUST_COST_2,                                  \    TARGET_SCHED_H_I_D_EXTENDED,					\    TARGET_SCHED_SPECULATE_INSN,                                 \    TARGET_SCHED_NEEDS_BLOCK_P,                                  \    TARGET_SCHED_GEN_CHECK,                                      \    TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD_GUARD_SPEC, \    TARGET_SCHED_SET_SCHED_FLAGS}
end_define

begin_define
define|#
directive|define
name|TARGET_VECTORIZE_BUILTIN_MASK_FOR_LOAD
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_VECTOR_ALIGNMENT_REACHABLE
define|\
value|default_builtin_vector_alignment_reachable
end_define

begin_define
define|#
directive|define
name|TARGET_VECTORIZE
define|\
value|{TARGET_VECTORIZE_BUILTIN_MASK_FOR_LOAD,				\    TARGET_VECTOR_ALIGNMENT_REACHABLE}
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT_TARGET_FLAGS
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_HANDLE_OPTION
value|hook_bool_size_t_constcharptr_int_true
end_define

begin_comment
comment|/* In except.c */
end_comment

begin_define
define|#
directive|define
name|TARGET_EH_RETURN_FILTER_MODE
value|default_eh_return_filter_mode
end_define

begin_comment
comment|/* In tree.c.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MERGE_DECL_ATTRIBUTES
value|merge_decl_attributes
end_define

begin_define
define|#
directive|define
name|TARGET_MERGE_TYPE_ATTRIBUTES
value|merge_type_attributes
end_define

begin_define
define|#
directive|define
name|TARGET_ATTRIBUTE_TABLE
value|NULL
end_define

begin_comment
comment|/* In cse.c.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ADDRESS_COST
value|default_address_cost
end_define

begin_comment
comment|/* In builtins.c.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_INIT_BUILTINS
value|hook_void_void
end_define

begin_define
define|#
directive|define
name|TARGET_EXPAND_BUILTIN
value|default_expand_builtin
end_define

begin_define
define|#
directive|define
name|TARGET_RESOLVE_OVERLOADED_BUILTIN
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_FOLD_BUILTIN
value|hook_tree_tree_tree_bool_null
end_define

begin_comment
comment|/* In varasm.c.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_SECTION_TYPE_FLAGS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_SECTION_TYPE_FLAGS
value|default_section_type_flags
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_STRIP_NAME_ENCODING
end_ifndef

begin_define
define|#
directive|define
name|TARGET_STRIP_NAME_ENCODING
value|default_strip_name_encoding
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BINDS_LOCAL_P
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BINDS_LOCAL_P
value|default_binds_local_p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_SHIFT_TRUNCATION_MASK
end_ifndef

begin_define
define|#
directive|define
name|TARGET_SHIFT_TRUNCATION_MASK
value|default_shift_truncation_mask
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_MIN_DIVISIONS_FOR_RECIP_MUL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_MIN_DIVISIONS_FOR_RECIP_MUL
value|default_min_divisions_for_recip_mul
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_MODE_REP_EXTENDED
end_ifndef

begin_define
define|#
directive|define
name|TARGET_MODE_REP_EXTENDED
value|default_mode_rep_extended
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VALID_POINTER_MODE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VALID_POINTER_MODE
value|default_valid_pointer_mode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_SCALAR_MODE_SUPPORTED_P
end_ifndef

begin_define
define|#
directive|define
name|TARGET_SCALAR_MODE_SUPPORTED_P
value|default_scalar_mode_supported_p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DECIMAL_FLOAT_SUPPORTED_P
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DECIMAL_FLOAT_SUPPORTED_P
value|default_decimal_float_supported_p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VECTOR_MODE_SUPPORTED_P
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VECTOR_MODE_SUPPORTED_P
value|hook_bool_mode_false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VECTOR_OPAQUE_P
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VECTOR_OPAQUE_P
value|hook_bool_tree_false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In hooks.c.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CANNOT_MODIFY_JUMPS_P
value|hook_bool_void_false
end_define

begin_define
define|#
directive|define
name|TARGET_BRANCH_TARGET_REGISTER_CLASS
value|hook_int_void_no_regs
end_define

begin_define
define|#
directive|define
name|TARGET_BRANCH_TARGET_REGISTER_CALLEE_SAVED
value|hook_bool_bool_false
end_define

begin_define
define|#
directive|define
name|TARGET_CANNOT_FORCE_CONST_MEM
value|hook_bool_rtx_false
end_define

begin_define
define|#
directive|define
name|TARGET_CANNOT_COPY_INSN_P
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_COMMUTATIVE_P
value|hook_bool_rtx_commutative_p
end_define

begin_define
define|#
directive|define
name|TARGET_DELEGITIMIZE_ADDRESS
value|hook_rtx_rtx_identity
end_define

begin_define
define|#
directive|define
name|TARGET_USE_BLOCKS_FOR_CONSTANT_P
value|hook_bool_mode_rtx_false
end_define

begin_define
define|#
directive|define
name|TARGET_MIN_ANCHOR_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_MAX_ANCHOR_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_USE_ANCHORS_FOR_SYMBOL_P
value|default_use_anchors_for_symbol_p
end_define

begin_define
define|#
directive|define
name|TARGET_FUNCTION_OK_FOR_SIBCALL
value|hook_bool_tree_tree_false
end_define

begin_define
define|#
directive|define
name|TARGET_COMP_TYPE_ATTRIBUTES
value|hook_int_tree_tree_1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_SET_DEFAULT_TYPE_ATTRIBUTES
end_ifndef

begin_define
define|#
directive|define
name|TARGET_SET_DEFAULT_TYPE_ATTRIBUTES
value|hook_void_tree
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_INSERT_ATTRIBUTES
value|hook_void_tree_treeptr
end_define

begin_define
define|#
directive|define
name|TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P
value|hook_bool_tree_false
end_define

begin_define
define|#
directive|define
name|TARGET_MS_BITFIELD_LAYOUT_P
value|hook_bool_tree_false
end_define

begin_define
define|#
directive|define
name|TARGET_ALIGN_ANON_BITFIELD
value|hook_bool_void_false
end_define

begin_define
define|#
directive|define
name|TARGET_NARROW_VOLATILE_BITFIELD
value|hook_bool_void_false
end_define

begin_define
define|#
directive|define
name|TARGET_RTX_COSTS
value|hook_bool_rtx_int_int_intp_false
end_define

begin_define
define|#
directive|define
name|TARGET_MANGLE_FUNDAMENTAL_TYPE
value|hook_constcharptr_tree_null
end_define

begin_define
define|#
directive|define
name|TARGET_ALLOCATE_INITIAL_VALUE
value|NULL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_INIT_LIBFUNCS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_INIT_LIBFUNCS
value|hook_void_void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_IN_SMALL_DATA_P
end_ifndef

begin_define
define|#
directive|define
name|TARGET_IN_SMALL_DATA_P
value|hook_bool_tree_false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ENCODE_SECTION_INFO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ENCODE_SECTION_INFO
value|default_encode_section_info
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_INVALID_ARG_FOR_UNPROTOTYPED_FN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_INVALID_ARG_FOR_UNPROTOTYPED_FN
value|hook_invalid_arg_for_unprototyped_fn
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_INVALID_CONVERSION
value|hook_constcharptr_tree_tree_null
end_define

begin_define
define|#
directive|define
name|TARGET_INVALID_UNARY_OP
value|hook_constcharptr_int_tree_null
end_define

begin_define
define|#
directive|define
name|TARGET_INVALID_BINARY_OP
value|hook_constcharptr_int_tree_tree_null
end_define

begin_define
define|#
directive|define
name|TARGET_FIXED_CONDITION_CODE_REGS
value|hook_bool_uintp_uintp_false
end_define

begin_define
define|#
directive|define
name|TARGET_CC_MODES_COMPATIBLE
value|default_cc_modes_compatible
end_define

begin_define
define|#
directive|define
name|TARGET_MACHINE_DEPENDENT_REORG
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_BUILD_BUILTIN_VA_LIST
value|std_build_builtin_va_list
end_define

begin_define
define|#
directive|define
name|TARGET_GET_PCH_VALIDITY
value|default_get_pch_validity
end_define

begin_define
define|#
directive|define
name|TARGET_PCH_VALID_P
value|default_pch_valid_p
end_define

begin_define
define|#
directive|define
name|TARGET_CHECK_PCH_TARGET_FLAGS
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT_SHORT_ENUMS
value|hook_bool_void_false
end_define

begin_define
define|#
directive|define
name|TARGET_BUILTIN_SETJMP_FRAME_VALUE
value|default_builtin_setjmp_frame_value
end_define

begin_define
define|#
directive|define
name|TARGET_MD_ASM_CLOBBERS
value|hook_tree_tree_tree_tree_3rd_identity
end_define

begin_define
define|#
directive|define
name|TARGET_DWARF_CALLING_CONVENTION
value|hook_int_tree_0
end_define

begin_define
define|#
directive|define
name|TARGET_DWARF_HANDLE_FRAME_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_STDARG_OPTIMIZE_HOOK
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_STACK_PROTECT_GUARD
value|default_stack_protect_guard
end_define

begin_define
define|#
directive|define
name|TARGET_STACK_PROTECT_FAIL
value|default_external_stack_protect_fail
end_define

begin_define
define|#
directive|define
name|TARGET_ARM_EABI_UNWINDER
value|false
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_FUNCTION_ARGS
value|hook_bool_tree_false
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_FUNCTION_RETURN
value|hook_bool_tree_false
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_PROTOTYPES
value|hook_bool_tree_false
end_define

begin_define
define|#
directive|define
name|TARGET_STRUCT_VALUE_RTX
value|hook_rtx_tree_int_null
end_define

begin_define
define|#
directive|define
name|TARGET_RETURN_IN_MEMORY
value|default_return_in_memory
end_define

begin_define
define|#
directive|define
name|TARGET_RETURN_IN_MSB
value|hook_bool_tree_false
end_define

begin_define
define|#
directive|define
name|TARGET_EXPAND_BUILTIN_SAVEREGS
value|default_expand_builtin_saveregs
end_define

begin_define
define|#
directive|define
name|TARGET_SETUP_INCOMING_VARARGS
value|default_setup_incoming_varargs
end_define

begin_define
define|#
directive|define
name|TARGET_STRICT_ARGUMENT_NAMING
value|hook_bool_CUMULATIVE_ARGS_false
end_define

begin_define
define|#
directive|define
name|TARGET_PRETEND_OUTGOING_VARARGS_NAMED
define|\
value|default_pretend_outgoing_varargs_named
end_define

begin_define
define|#
directive|define
name|TARGET_SPLIT_COMPLEX_ARG
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_GIMPLIFY_VA_ARG_EXPR
value|std_gimplify_va_arg_expr
end_define

begin_define
define|#
directive|define
name|TARGET_PASS_BY_REFERENCE
value|hook_bool_CUMULATIVE_ARGS_mode_tree_bool_false
end_define

begin_define
define|#
directive|define
name|TARGET_RELAXED_ORDERING
value|false
end_define

begin_define
define|#
directive|define
name|TARGET_MUST_PASS_IN_STACK
value|must_pass_in_stack_var_size_or_pad
end_define

begin_define
define|#
directive|define
name|TARGET_CALLEE_COPIES
value|hook_bool_CUMULATIVE_ARGS_mode_tree_bool_false
end_define

begin_define
define|#
directive|define
name|TARGET_ARG_PARTIAL_BYTES
value|hook_int_CUMULATIVE_ARGS_mode_tree_bool_0
end_define

begin_define
define|#
directive|define
name|TARGET_FUNCTION_VALUE
value|default_function_value
end_define

begin_define
define|#
directive|define
name|TARGET_INTERNAL_ARG_POINTER
value|default_internal_arg_pointer
end_define

begin_define
define|#
directive|define
name|TARGET_CALLS
value|{						\    TARGET_PROMOTE_FUNCTION_ARGS,				\    TARGET_PROMOTE_FUNCTION_RETURN,				\    TARGET_PROMOTE_PROTOTYPES,					\    TARGET_STRUCT_VALUE_RTX,					\    TARGET_RETURN_IN_MEMORY,					\    TARGET_RETURN_IN_MSB,					\    TARGET_PASS_BY_REFERENCE,					\    TARGET_EXPAND_BUILTIN_SAVEREGS,				\    TARGET_SETUP_INCOMING_VARARGS,				\    TARGET_STRICT_ARGUMENT_NAMING,				\    TARGET_PRETEND_OUTGOING_VARARGS_NAMED,			\    TARGET_SPLIT_COMPLEX_ARG,					\    TARGET_MUST_PASS_IN_STACK,					\    TARGET_CALLEE_COPIES,					\    TARGET_ARG_PARTIAL_BYTES,					\    TARGET_INVALID_ARG_FOR_UNPROTOTYPED_FN,			\    TARGET_FUNCTION_VALUE,					\    TARGET_INTERNAL_ARG_POINTER					\    }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_UNWIND_TABLES_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_UNWIND_TABLES_DEFAULT
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_HANDLE_PRAGMA_REDEFINE_EXTNAME
end_ifndef

begin_define
define|#
directive|define
name|TARGET_HANDLE_PRAGMA_REDEFINE_EXTNAME
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_HANDLE_PRAGMA_EXTERN_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|TARGET_HANDLE_PRAGMA_EXTERN_PREFIX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_SECONDARY_RELOAD
end_ifndef

begin_define
define|#
directive|define
name|TARGET_SECONDARY_RELOAD
value|default_secondary_reload
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C++ specific.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_GUARD_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_GUARD_TYPE
value|default_cxx_guard_type
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_GUARD_MASK_BIT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_GUARD_MASK_BIT
value|hook_bool_void_false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_GET_COOKIE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_GET_COOKIE_SIZE
value|default_cxx_get_cookie_size
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_COOKIE_HAS_SIZE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_COOKIE_HAS_SIZE
value|hook_bool_void_false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_IMPORT_EXPORT_CLASS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_IMPORT_EXPORT_CLASS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_CDTOR_RETURNS_THIS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_CDTOR_RETURNS_THIS
value|hook_bool_void_false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_KEY_METHOD_MAY_BE_INLINE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_KEY_METHOD_MAY_BE_INLINE
value|hook_bool_void_true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_DETERMINE_CLASS_DATA_VISIBILITY
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_DETERMINE_CLASS_DATA_VISIBILITY
value|hook_void_tree
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_CLASS_DATA_ALWAYS_COMDAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_CLASS_DATA_ALWAYS_COMDAT
value|hook_bool_void_true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_LIBRARY_RTTI_COMDAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_LIBRARY_RTTI_COMDAT
value|hook_bool_void_true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_USE_AEABI_ATEXIT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_USE_AEABI_ATEXIT
value|hook_bool_void_false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CXX_ADJUST_CLASS_AT_DEFINITION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CXX_ADJUST_CLASS_AT_DEFINITION
value|hook_void_tree
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_CXX
define|\
value|{						\     TARGET_CXX_GUARD_TYPE,			\     TARGET_CXX_GUARD_MASK_BIT,			\     TARGET_CXX_GET_COOKIE_SIZE,			\     TARGET_CXX_COOKIE_HAS_SIZE,			\     TARGET_CXX_IMPORT_EXPORT_CLASS,		\     TARGET_CXX_CDTOR_RETURNS_THIS,		\     TARGET_CXX_KEY_METHOD_MAY_BE_INLINE,	\     TARGET_CXX_DETERMINE_CLASS_DATA_VISIBILITY,	\     TARGET_CXX_CLASS_DATA_ALWAYS_COMDAT,        \     TARGET_CXX_LIBRARY_RTTI_COMDAT,	        \     TARGET_CXX_USE_AEABI_ATEXIT,		\     TARGET_CXX_ADJUST_CLASS_AT_DEFINITION	\   }
end_define

begin_comment
comment|/* The whole shebang.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_INITIALIZER
define|\
value|{						\   TARGET_ASM_OUT,				\   TARGET_SCHED,					\   TARGET_VECTORIZE,				\   TARGET_DEFAULT_TARGET_FLAGS,			\   TARGET_HANDLE_OPTION,				\   TARGET_EH_RETURN_FILTER_MODE,			\   TARGET_MERGE_DECL_ATTRIBUTES,			\   TARGET_MERGE_TYPE_ATTRIBUTES,			\   TARGET_ATTRIBUTE_TABLE,			\   TARGET_COMP_TYPE_ATTRIBUTES,			\   TARGET_SET_DEFAULT_TYPE_ATTRIBUTES,		\   TARGET_INSERT_ATTRIBUTES,			\   TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P,	\   TARGET_MS_BITFIELD_LAYOUT_P,			\   TARGET_DECIMAL_FLOAT_SUPPORTED_P,		\   TARGET_ALIGN_ANON_BITFIELD,			\   TARGET_NARROW_VOLATILE_BITFIELD,		\   TARGET_INIT_BUILTINS,				\   TARGET_EXPAND_BUILTIN,			\   TARGET_RESOLVE_OVERLOADED_BUILTIN,		\   TARGET_FOLD_BUILTIN,				\   TARGET_MANGLE_FUNDAMENTAL_TYPE,		\   TARGET_INIT_LIBFUNCS,				\   TARGET_SECTION_TYPE_FLAGS,			\   TARGET_CANNOT_MODIFY_JUMPS_P,			\   TARGET_BRANCH_TARGET_REGISTER_CLASS,		\   TARGET_BRANCH_TARGET_REGISTER_CALLEE_SAVED,	\   TARGET_CANNOT_FORCE_CONST_MEM,		\   TARGET_CANNOT_COPY_INSN_P,			\   TARGET_COMMUTATIVE_P,				\   TARGET_DELEGITIMIZE_ADDRESS,			\   TARGET_USE_BLOCKS_FOR_CONSTANT_P,		\   TARGET_MIN_ANCHOR_OFFSET,			\   TARGET_MAX_ANCHOR_OFFSET,			\   TARGET_USE_ANCHORS_FOR_SYMBOL_P,		\   TARGET_FUNCTION_OK_FOR_SIBCALL,		\   TARGET_IN_SMALL_DATA_P,			\   TARGET_BINDS_LOCAL_P,				\   TARGET_ENCODE_SECTION_INFO,			\   TARGET_STRIP_NAME_ENCODING,			\   TARGET_SHIFT_TRUNCATION_MASK,			\   TARGET_MIN_DIVISIONS_FOR_RECIP_MUL,		\   TARGET_MODE_REP_EXTENDED,			\   TARGET_VALID_POINTER_MODE,                    \   TARGET_SCALAR_MODE_SUPPORTED_P,		\   TARGET_VECTOR_MODE_SUPPORTED_P,               \   TARGET_VECTOR_OPAQUE_P,			\   TARGET_RTX_COSTS,				\   TARGET_ADDRESS_COST,				\   TARGET_ALLOCATE_INITIAL_VALUE,		\   TARGET_DWARF_REGISTER_SPAN,                   \   TARGET_FIXED_CONDITION_CODE_REGS,		\   TARGET_CC_MODES_COMPATIBLE,			\   TARGET_MACHINE_DEPENDENT_REORG,		\   TARGET_BUILD_BUILTIN_VA_LIST,			\   TARGET_GIMPLIFY_VA_ARG_EXPR,			\   TARGET_GET_PCH_VALIDITY,			\   TARGET_PCH_VALID_P,				\   TARGET_CHECK_PCH_TARGET_FLAGS,		\   TARGET_DEFAULT_SHORT_ENUMS,			\   TARGET_BUILTIN_SETJMP_FRAME_VALUE,		\   TARGET_MD_ASM_CLOBBERS,			\   TARGET_DWARF_CALLING_CONVENTION,              \   TARGET_DWARF_HANDLE_FRAME_UNSPEC,		\   TARGET_STDARG_OPTIMIZE_HOOK,			\   TARGET_STACK_PROTECT_GUARD,			\   TARGET_STACK_PROTECT_FAIL,			\   TARGET_INVALID_WITHIN_DOLOOP,			\   TARGET_VALID_DLLIMPORT_ATTRIBUTE_P,		\   TARGET_CALLS,					\   TARGET_INVALID_CONVERSION,			\   TARGET_INVALID_UNARY_OP,			\   TARGET_INVALID_BINARY_OP,			\   TARGET_SECONDARY_RELOAD,			\   TARGET_CXX,					\   TARGET_EXTRA_LIVE_ON_ENTRY,                    \   TARGET_UNWIND_TABLES_DEFAULT,			\   TARGET_HAVE_NAMED_SECTIONS,			\   TARGET_HAVE_SWITCHABLE_BSS_SECTIONS,		\   TARGET_HAVE_CTORS_DTORS,			\   TARGET_HAVE_TLS,				\   TARGET_HAVE_SRODATA_SECTION,			\   TARGET_TERMINATE_DW2_EH_FRAME_INFO,		\   TARGET_ASM_FILE_START_APP_OFF,		\   TARGET_ASM_FILE_START_FILE_DIRECTIVE,		\   TARGET_HANDLE_PRAGMA_REDEFINE_EXTNAME,	\   TARGET_HANDLE_PRAGMA_EXTERN_PREFIX,		\   TARGET_RELAXED_ORDERING,			\   TARGET_ARM_EABI_UNWINDER			\ }
end_define

begin_include
include|#
directive|include
file|"hooks.h"
end_include

begin_include
include|#
directive|include
file|"targhooks.h"
end_include

end_unit

