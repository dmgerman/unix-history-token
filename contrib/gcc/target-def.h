begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default initializers for a generic GCC target.    Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
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

begin_define
define|#
directive|define
name|TARGET_ASM_OPEN_PAREN
value|"("
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_CLOSE_PAREN
value|")"
end_define

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
name|TARGET_ASM_EXCEPTION_SECTION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_EXCEPTION_SECTION
value|default_exception_section
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ASM_EH_FRAME_SECTION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ASM_EH_FRAME_SECTION
value|default_eh_frame_section
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|{TARGET_ASM_OPEN_PAREN,			\ 			TARGET_ASM_CLOSE_PAREN,			\ 			TARGET_ASM_BYTE_OP,			\ 			TARGET_ASM_ALIGNED_INT_OP,		\ 			TARGET_ASM_UNALIGNED_INT_OP,		\ 			TARGET_ASM_INTEGER,			\ 			TARGET_ASM_GLOBALIZE_LABEL,		\ 			TARGET_ASM_INTERNAL_LABEL,		\ 			TARGET_ASM_ASSEMBLE_VISIBILITY,		\ 			TARGET_ASM_FUNCTION_PROLOGUE,		\ 			TARGET_ASM_FUNCTION_END_PROLOGUE,	\ 			TARGET_ASM_FUNCTION_BEGIN_EPILOGUE,	\ 			TARGET_ASM_FUNCTION_EPILOGUE,		\ 			TARGET_ASM_NAMED_SECTION,		\ 			TARGET_ASM_EXCEPTION_SECTION,		\ 			TARGET_ASM_EH_FRAME_SECTION,		\ 			TARGET_ASM_SELECT_SECTION,		\ 			TARGET_ASM_SELECT_RTX_SECTION,		\ 			TARGET_ASM_UNIQUE_SECTION,		\ 			TARGET_ASM_CONSTRUCTOR,			\ 			TARGET_ASM_DESTRUCTOR,                  \                         TARGET_ASM_OUTPUT_MI_THUNK,             \                         TARGET_ASM_CAN_OUTPUT_MI_THUNK,         \                         TARGET_ASM_FILE_START,                  \                         TARGET_ASM_FILE_END,			\ 			TARGET_ASM_EXTERNAL_LIBCALL}
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
name|TARGET_SCHED_USE_DFA_PIPELINE_INTERFACE
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
name|TARGET_SCHED_INIT_DFA_BUBBLES
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_DFA_BUBBLE
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
name|TARGET_SCHED
define|\
value|{TARGET_SCHED_ADJUST_COST,					\    TARGET_SCHED_ADJUST_PRIORITY,				\    TARGET_SCHED_ISSUE_RATE,					\    TARGET_SCHED_VARIABLE_ISSUE,					\    TARGET_SCHED_INIT,						\    TARGET_SCHED_FINISH,						\    TARGET_SCHED_REORDER,					\    TARGET_SCHED_REORDER2,					\    TARGET_SCHED_DEPENDENCIES_EVALUATION_HOOK,			\    TARGET_SCHED_USE_DFA_PIPELINE_INTERFACE,			\    TARGET_SCHED_INIT_DFA_PRE_CYCLE_INSN,			\    TARGET_SCHED_DFA_PRE_CYCLE_INSN,				\    TARGET_SCHED_INIT_DFA_POST_CYCLE_INSN,			\    TARGET_SCHED_DFA_POST_CYCLE_INSN,				\    TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD,		\    TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD_GUARD,	\    TARGET_SCHED_DFA_NEW_CYCLE,					\    TARGET_SCHED_INIT_DFA_BUBBLES,				\    TARGET_SCHED_DFA_BUBBLE,                                     \    TARGET_SCHED_IS_COSTLY_DEPENDENCE}
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
comment|/* In hook.c.  */
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
name|TARGET_DELEGITIMIZE_ADDRESS
value|hook_rtx_rtx_identity
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

begin_define
define|#
directive|define
name|TARGET_SET_DEFAULT_TYPE_ATTRIBUTES
value|hook_void_tree
end_define

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
name|TARGET_RTX_COSTS
value|hook_bool_rtx_int_int_intp_false
end_define

begin_define
define|#
directive|define
name|TARGET_MANGLE_FUNDAMENTAL_TYPE
value|hook_constcharptr_tree_null
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
name|TARGET_PROMOTE_FUNCTION_ARGS
value|default_promote_function_args
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_FUNCTION_RETURN
value|default_promote_function_return
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_PROTOTYPES
value|default_promote_prototypes
end_define

begin_define
define|#
directive|define
name|TARGET_STRUCT_VALUE_RTX
value|default_struct_value_rtx
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
value|default_strict_argument_naming
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
name|TARGET_CALLS
value|{						\    TARGET_PROMOTE_FUNCTION_ARGS,				\    TARGET_PROMOTE_FUNCTION_RETURN,				\    TARGET_PROMOTE_PROTOTYPES,					\    TARGET_STRUCT_VALUE_RTX,					\    TARGET_RETURN_IN_MEMORY,					\    TARGET_RETURN_IN_MSB,					\    TARGET_EXPAND_BUILTIN_SAVEREGS,				\    TARGET_SETUP_INCOMING_VARARGS,				\    TARGET_STRICT_ARGUMENT_NAMING,				\    TARGET_PRETEND_OUTGOING_VARARGS_NAMED,			\    TARGET_SPLIT_COMPLEX_ARG,					\    }
end_define

begin_comment
comment|/* The whole shebang.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_INITIALIZER
define|\
value|{						\   TARGET_ASM_OUT,				\   TARGET_SCHED,					\   TARGET_MERGE_DECL_ATTRIBUTES,			\   TARGET_MERGE_TYPE_ATTRIBUTES,			\   TARGET_ATTRIBUTE_TABLE,			\   TARGET_COMP_TYPE_ATTRIBUTES,			\   TARGET_SET_DEFAULT_TYPE_ATTRIBUTES,		\   TARGET_INSERT_ATTRIBUTES,			\   TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P,	\   TARGET_MS_BITFIELD_LAYOUT_P,			\   TARGET_INIT_BUILTINS,				\   TARGET_EXPAND_BUILTIN,			\   TARGET_MANGLE_FUNDAMENTAL_TYPE,		\   TARGET_INIT_LIBFUNCS,				\   TARGET_SECTION_TYPE_FLAGS,			\   TARGET_CANNOT_MODIFY_JUMPS_P,			\   TARGET_BRANCH_TARGET_REGISTER_CLASS,		\   TARGET_BRANCH_TARGET_REGISTER_CALLEE_SAVED,	\   TARGET_CANNOT_FORCE_CONST_MEM,		\   TARGET_CANNOT_COPY_INSN_P,			\   TARGET_DELEGITIMIZE_ADDRESS,			\   TARGET_FUNCTION_OK_FOR_SIBCALL,		\   TARGET_IN_SMALL_DATA_P,			\   TARGET_BINDS_LOCAL_P,				\   TARGET_ENCODE_SECTION_INFO,			\   TARGET_STRIP_NAME_ENCODING,			\   TARGET_VALID_POINTER_MODE,                    \   TARGET_VECTOR_OPAQUE_P,			\   TARGET_RTX_COSTS,				\   TARGET_ADDRESS_COST,				\   TARGET_DWARF_REGISTER_SPAN,                   \   TARGET_FIXED_CONDITION_CODE_REGS,		\   TARGET_CC_MODES_COMPATIBLE,			\   TARGET_MACHINE_DEPENDENT_REORG,		\   TARGET_BUILD_BUILTIN_VA_LIST,			\   TARGET_GET_PCH_VALIDITY,			\   TARGET_PCH_VALID_P,				\   TARGET_CALLS,					\   TARGET_HAVE_NAMED_SECTIONS,			\   TARGET_HAVE_CTORS_DTORS,			\   TARGET_HAVE_TLS,				\   TARGET_HAVE_SRODATA_SECTION,			\   TARGET_TERMINATE_DW2_EH_FRAME_INFO,		\   TARGET_ASM_FILE_START_APP_OFF,		\   TARGET_ASM_FILE_START_FILE_DIRECTIVE,		\ }
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

