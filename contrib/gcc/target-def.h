begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default initializers for a generic GCC target.    Copyright (C) 2001 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
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
operator|||
name|defined
argument_list|(
name|OBJECT_FORMAT_ROSE
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
comment|/* OBJECT_FORMAT_ELF || OBJECT_FORMAT_ROSE */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_INTEGER
value|default_assemble_integer
end_define

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
value|{TARGET_ASM_OPEN_PAREN,			\ 			TARGET_ASM_CLOSE_PAREN,			\ 			TARGET_ASM_BYTE_OP,			\ 			TARGET_ASM_ALIGNED_INT_OP,		\ 			TARGET_ASM_UNALIGNED_INT_OP,		\ 			TARGET_ASM_INTEGER,			\ 			TARGET_ASM_FUNCTION_PROLOGUE,		\ 			TARGET_ASM_FUNCTION_END_PROLOGUE,	\ 			TARGET_ASM_FUNCTION_BEGIN_EPILOGUE,	\ 			TARGET_ASM_FUNCTION_EPILOGUE,		\ 			TARGET_ASM_NAMED_SECTION,		\ 			TARGET_ASM_EXCEPTION_SECTION,		\ 			TARGET_ASM_EH_FRAME_SECTION,		\ 			TARGET_ASM_CONSTRUCTOR,			\ 			TARGET_ASM_DESTRUCTOR}
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
name|TARGET_SCHED_CYCLE_DISPLAY
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED
value|{TARGET_SCHED_ADJUST_COST,	\ 			 TARGET_SCHED_ADJUST_PRIORITY,	\ 			 TARGET_SCHED_ISSUE_RATE,	\ 			 TARGET_SCHED_VARIABLE_ISSUE,	\ 			 TARGET_SCHED_INIT,		\ 			 TARGET_SCHED_FINISH,		\ 			 TARGET_SCHED_REORDER,		\ 			 TARGET_SCHED_REORDER2,		\ 			 TARGET_SCHED_CYCLE_DISPLAY}
end_define

begin_comment
comment|/* All in tree.c.  */
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
value|default_target_attribute_table
end_define

begin_define
define|#
directive|define
name|TARGET_COMP_TYPE_ATTRIBUTES
value|default_comp_type_attributes
end_define

begin_define
define|#
directive|define
name|TARGET_SET_DEFAULT_TYPE_ATTRIBUTES
value|default_set_default_type_attributes
end_define

begin_define
define|#
directive|define
name|TARGET_INSERT_ATTRIBUTES
value|default_insert_attributes
end_define

begin_define
define|#
directive|define
name|TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P
value|default_function_attribute_inlinable_p
end_define

begin_comment
comment|/* In builtins.c.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_INIT_BUILTINS
value|default_init_builtins
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

begin_comment
comment|/* The whole shebang.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_INITIALIZER
define|\
value|{						\   TARGET_ASM_OUT,				\   TARGET_SCHED,					\   TARGET_MERGE_DECL_ATTRIBUTES,			\   TARGET_MERGE_TYPE_ATTRIBUTES,			\   TARGET_ATTRIBUTE_TABLE,			\   TARGET_COMP_TYPE_ATTRIBUTES,			\   TARGET_SET_DEFAULT_TYPE_ATTRIBUTES,		\   TARGET_INSERT_ATTRIBUTES,			\   TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P,	\   TARGET_INIT_BUILTINS,				\   TARGET_EXPAND_BUILTIN,			\   TARGET_SECTION_TYPE_FLAGS,			\   TARGET_HAVE_NAMED_SECTIONS,			\   TARGET_HAVE_CTORS_DTORS			\ }
end_define

end_unit

