begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for Vax.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* #defines that need visibility everywhere.  */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/* target machine dependencies.    tm.h is a symbolic link to the actual target specific file.   */
end_comment

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_comment
comment|/* This describes the machine the compiler is hosted on.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BITS_PER_CHAR
value|8
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_SHORT
value|16
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_INT
value|32
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|32
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONGLONG
value|64
end_define

begin_define
define|#
directive|define
name|HOST_FLOAT_FORMAT
value|VAX_FLOAT_FORMAT
end_define

begin_define
define|#
directive|define
name|SUCCESS_EXIT_CODE
value|1
end_define

begin_define
define|#
directive|define
name|FATAL_EXIT_CODE
value|(44 | 0x10000000)
end_define

begin_comment
comment|/* Failure, and no DCL message.  */
end_comment

begin_comment
comment|/* A couple of conditionals for execution machine are controlled here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_define
define|#
directive|define
name|VMS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* not present, at least in VAX-11 C (VMS) v2.2 */
end_comment

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If compiled with GNU C, use the built-in alloca */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|"///not used with VMS///"
end_define

begin_comment
comment|/* nonsense string for now */
end_comment

begin_comment
comment|/* and define a local equivalent (sort of) for unlink */
end_comment

begin_define
define|#
directive|define
name|unlink
value|remove
end_define

begin_comment
comment|/* Specify the list of include file directories.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{									\   { "GNU_GXX_INCLUDE:", 1},						\   { "GNU_CC_INCLUDE:", 0},
comment|/* GNU includes */
value|\   { "SYS$SYSROOT:[SYSLIB.]", 0},
comment|/* VAX-11 "C" includes */
value|\   { ".", 0},
comment|/* Make normal VMS filespecs work.  */
value|\   { 0, 0}								\ }
end_define

begin_comment
comment|/* Under VMS a directory specification can be enclosed either in square    brackets or in angle brackets.  Thus we need to check both.  This    macro is used to help compare filenames in cp-lex.c.     We also need to make sure that the names are all lower case, because    we must be able to compare filenames to determine if a file implements    a class.  */
end_comment

begin_define
define|#
directive|define
name|FILE_NAME_NONDIRECTORY
parameter_list|(
name|C
parameter_list|)
define|\
value|({								\    char * pnt_ = (C), * pnt1_;					\    pnt1_ = pnt_ - 1;						\    while (*++pnt1_)						\      if ((*pnt1_>= 'A'&& *pnt1_<= 'Z')) *pnt1_ |= 0x20;	\    pnt1_ = rindex (pnt_, ']'); 					\    pnt1_ = (pnt1_ == 0 ? rindex (pnt_, '>') : pnt1_);		\    pnt1_ = (pnt1_ == 0 ? rindex (pnt_, ':') : pnt1_);		\    (pnt1_ == 0 ? pnt_ : pnt1_ + 1);				\  })
end_define

begin_comment
comment|/* Macro to generate the name of the cross reference file.  The standard    one does not work, since it was written assuming that the conventions    of a unix style filesystem will work on the host system.  */
end_comment

begin_define
define|#
directive|define
name|XREF_FILE_NAME
parameter_list|(
name|BUFF
parameter_list|,
name|NAME
parameter_list|)
define|\
value|s = FILE_NAME_NONDIRECTORY (NAME);			\   if (s == NAME) sprintf(BUFF, "%s_gxref", NAME);	\   else {						\     strcpy(BUFF, NAME);					\     strcat(BUFF, "_gxref");				\   }
end_define

begin_comment
comment|/* Macro that is used in cp-xref.c to determine whether a file name is    absolute or not.  */
end_comment

begin_define
define|#
directive|define
name|FILE_NAME_ABSOLUTE_P
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(FILE_NAME_NONDIRECTORY (NAME) != (&NAME[1]))
end_define

begin_comment
comment|/* FILE_NAME_JOINER is defined to be the characters that are inserted between     a directory name and a filename in order to make an absolute file    specification.  Under VMS the directory specification contains all of the    required characters, so we define this to be a null string.  */
end_comment

begin_define
define|#
directive|define
name|FILE_NAME_JOINER
value|""
end_define

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|VAXC
end_ifdef

begin_comment
comment|/* Customizations/kludges for building with DEC's VAX C compiler    rather than GCC.  */
end_comment

begin_define
define|#
directive|define
name|NO_SYS_PARAMS_H
end_define

begin_comment
comment|/* don't have<sys/params.h> */
end_comment

begin_define
define|#
directive|define
name|NO_STAB_H
end_define

begin_comment
comment|/* don't have<stab.h> */
end_comment

begin_define
define|#
directive|define
name|USE_C_ALLOCA
end_define

begin_comment
comment|/* using alloca.c */
end_comment

begin_define
define|#
directive|define
name|QSORT_WORKAROUND
end_define

begin_comment
comment|/* do not use VAXCRTL's qsort */
end_comment

begin_comment
comment|/* use ANSI/SYSV style byte manipulation routines instead of BSD ones */
end_comment

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|)
value|memcpy((d),(s),(n))
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|d
parameter_list|,
name|n
parameter_list|)
value|memset((d),0,(n))
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|,
name|n
parameter_list|)
value|memcmp((l),(r),(n))
end_define

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_comment
comment|/* rename all too-long external symbol names to avoid warnings */
end_comment

begin_define
define|#
directive|define
name|check_for_full_enumeration_handling
value|check_for_full_enum_handling
end_define

begin_define
define|#
directive|define
name|current_function_contains_functions
value|curfunc_contains_functions
end_define

begin_define
define|#
directive|define
name|current_function_epilogue_delay_list
value|curfunc_epilogue_delay_list
end_define

begin_define
define|#
directive|define
name|current_function_has_nonlocal_label
value|curfunc_has_nonlocal_label
end_define

begin_define
define|#
directive|define
name|current_function_internal_arg_pointer
value|curfunc_internal_arg_pointer
end_define

begin_define
define|#
directive|define
name|current_function_outgoing_args_size
value|curfunc_outgoing_args_size
end_define

begin_define
define|#
directive|define
name|current_function_pretend_args_size
value|curfunc_pretend_args_size
end_define

begin_define
define|#
directive|define
name|current_function_returns_pcc_struct
value|curfunc_returns_pcc_struct
end_define

begin_define
define|#
directive|define
name|current_function_returns_pointer
value|curfunc_returns_pointer
end_define

begin_define
define|#
directive|define
name|current_function_uses_const_pool
value|curfunc_uses_const_pool
end_define

begin_define
define|#
directive|define
name|current_function_uses_pic_offset_table
value|curfunc_uses_pic_offset_table
end_define

begin_define
define|#
directive|define
name|expand_start_loop_continue_elsewhere
value|expnd_start_loop_cont_elsewhere
end_define

begin_define
define|#
directive|define
name|flag_schedule_insns_after_reload
value|flag_sched_insns_after_reload
end_define

begin_define
define|#
directive|define
name|maybe_building_objc_message_expr
value|maybe_building_objc_msg_expr
end_define

begin_define
define|#
directive|define
name|reg_overlap_mentioned_for_reload_p
value|reg_overlap_mtnd_for_reload_p
end_define

begin_define
define|#
directive|define
name|reposition_prologue_and_epilogue_notes
value|repos_prolog_and_epilog_notes
end_define

begin_define
define|#
directive|define
name|rtx_equal_function_value_matters
value|rtx_equal_func_value_matters
end_define

begin_define
define|#
directive|define
name|set_new_first_and_last_label_num
value|set_new_first_and_last_lbl_num
end_define

begin_define
define|#
directive|define
name|thread_prologue_and_epilogue_insns
value|thread_prolog_and_epilog_insns
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We need to avoid the library qsort routine, due to a serious bug    in VAXCRTL.  (Sorting anything with size that's not a multiple of 4    after having previously sorted something that was a multiple of 4    can produce wrong results and result in data corruption.)  We'll    use our own substitute (in vax.c) instead.  */
end_comment

begin_comment
comment|/* #define QSORT_WORKAROUND */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QSORT_WORKAROUND
end_ifdef

begin_define
define|#
directive|define
name|qsort
value|not_qsort
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

