begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* top.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995, 1996, 1997, 1999 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       top.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_TOP_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_TOP_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_enum
enum|enum
name|_ffe_case_
block|{
name|FFE_caseNONE
block|,
comment|/* No case conversion, match 				   case-insensitive. */
name|FFE_caseUPPER
block|,
comment|/* Convert lowercase to uppercase, match 				   upper. */
name|FFE_caseLOWER
block|,
comment|/* Convert uppercase to lowercase, match 				   lower. */
name|FFE_caseINITCAP
block|,
comment|/* Match InitialCap (no meaning for 				   conversion). */
name|FFE_case
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffe_case_
name|ffeCase
typedef|;
end_typedef

begin_enum
enum|enum
name|_ffeintrinsic_state_
block|{
comment|/* State of a family of intrinsics. NOTE: 				   order IS important, see 				   ffe_intrinsic_state_max (). */
name|FFE_intrinsicstateDELETED
block|,
comment|/* Doesn't exist at all. */
name|FFE_intrinsicstateDISABLED
block|,
comment|/* Diagnostic if used as intrinsic. */
name|FFE_intrinsicstateHIDDEN
block|,
comment|/* Exists only if INTRINSIC stmt. */
name|FFE_intrinsicstateENABLED
block|,
comment|/* Exists as normal. */
name|FFE_intrinsicstate
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffeintrinsic_state_
name|ffeIntrinsicState
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ffeCounter
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffeCounter_f
value|"l"
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ffeKwIndex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|ffeTokenLength
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffeTokenLength_f
value|"l"
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|ffeUnionLongPtr
typedef|;
end_typedef

begin_comment
comment|/* unused type to cover union of long and 				   ptr. */
end_comment

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"where.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_do_internal_checks_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_90_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_automatic_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_backslash_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_emulate_complex_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_underscoring_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_second_underscore_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_debug_kludge_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_dollar_ok_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_f2c_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_f2c_library_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_ffedebug_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_flatten_arrays_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_free_form_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_globals_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_init_local_zero_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_mainprog_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_onetrip_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_silent_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_typeless_boz_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_pedantic_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_saveall_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_ugly_args_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_ugly_assign_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_ugly_assumed_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_ugly_comma_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_ugly_complex_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_ugly_init_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_ugly_logint_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_version_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_vxt_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_warn_globals_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_warn_implicit_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_warn_surprising_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_is_zeros_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCase
name|ffe_case_intrin_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCase
name|ffe_case_match_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCase
name|ffe_case_source_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCase
name|ffe_case_symbol_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeIntrinsicState
name|ffe_intrinsic_state_badu77_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeIntrinsicState
name|ffe_intrinsic_state_gnu_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeIntrinsicState
name|ffe_intrinsic_state_f2c_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeIntrinsicState
name|ffe_intrinsic_state_f90_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeIntrinsicState
name|ffe_intrinsic_state_mil_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeIntrinsicState
name|ffe_intrinsic_state_unix_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeIntrinsicState
name|ffe_intrinsic_state_vxt_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ffe_fixed_line_length_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mallocPool
name|ffe_file_pool_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mallocPool
name|ffe_any_unit_pool_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mallocPool
name|ffe_program_unit_pool_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCounter
name|ffe_count_0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCounter
name|ffe_count_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCounter
name|ffe_count_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCounter
name|ffe_count_3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeCounter
name|ffe_count_4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_in_0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_in_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_in_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_in_3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffe_in_4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|int
name|ffe_decode_option
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_file
parameter_list|(
name|ffewhereFile
name|wf
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_init_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_init_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_init_3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_init_4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_terminate_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_terminate_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_terminate_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_terminate_3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffe_terminate_4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffe_case_intrin
parameter_list|()
value|ffe_case_intrin_
end_define

begin_define
define|#
directive|define
name|ffe_case_match
parameter_list|()
value|ffe_case_match_
end_define

begin_define
define|#
directive|define
name|ffe_case_source
parameter_list|()
value|ffe_case_source_
end_define

begin_define
define|#
directive|define
name|ffe_case_symbol
parameter_list|()
value|ffe_case_symbol_
end_define

begin_define
define|#
directive|define
name|ffe_intrinsic_state_badu77
parameter_list|()
value|ffe_intrinsic_state_badu77_
end_define

begin_define
define|#
directive|define
name|ffe_intrinsic_state_f2c
parameter_list|()
value|ffe_intrinsic_state_f2c_
end_define

begin_define
define|#
directive|define
name|ffe_intrinsic_state_f90
parameter_list|()
value|ffe_intrinsic_state_f90_
end_define

begin_define
define|#
directive|define
name|ffe_intrinsic_state_gnu
parameter_list|()
value|ffe_intrinsic_state_gnu_
end_define

begin_define
define|#
directive|define
name|ffe_intrinsic_state_mil
parameter_list|()
value|ffe_intrinsic_state_mil_
end_define

begin_define
define|#
directive|define
name|ffe_intrinsic_state_unix
parameter_list|()
value|ffe_intrinsic_state_unix_
end_define

begin_define
define|#
directive|define
name|ffe_intrinsic_state_vxt
parameter_list|()
value|ffe_intrinsic_state_vxt_
end_define

begin_define
define|#
directive|define
name|ffe_is_90
parameter_list|()
value|ffe_is_90_
end_define

begin_define
define|#
directive|define
name|ffe_is_automatic
parameter_list|()
value|ffe_is_automatic_
end_define

begin_define
define|#
directive|define
name|ffe_is_backslash
parameter_list|()
value|ffe_is_backslash_
end_define

begin_define
define|#
directive|define
name|ffe_is_debug_kludge
parameter_list|()
value|ffe_is_debug_kludge_
end_define

begin_define
define|#
directive|define
name|ffe_is_do_internal_checks
parameter_list|()
value|ffe_is_do_internal_checks_
end_define

begin_define
define|#
directive|define
name|ffe_is_dollar_ok
parameter_list|()
value|ffe_is_dollar_ok_
end_define

begin_define
define|#
directive|define
name|ffe_is_emulate_complex
parameter_list|()
value|ffe_is_emulate_complex_
end_define

begin_define
define|#
directive|define
name|ffe_is_f2c
parameter_list|()
value|ffe_is_f2c_
end_define

begin_define
define|#
directive|define
name|ffe_is_f2c_library
parameter_list|()
value|ffe_is_f2c_library_
end_define

begin_define
define|#
directive|define
name|ffe_is_ffedebug
parameter_list|()
value|ffe_is_ffedebug_
end_define

begin_define
define|#
directive|define
name|ffe_is_flatten_arrays
parameter_list|()
value|ffe_is_flatten_arrays_
end_define

begin_define
define|#
directive|define
name|ffe_is_free_form
parameter_list|()
value|ffe_is_free_form_
end_define

begin_define
define|#
directive|define
name|ffe_is_globals
parameter_list|()
value|ffe_is_globals_
end_define

begin_define
define|#
directive|define
name|ffe_is_init_local_zero
parameter_list|()
value|ffe_is_init_local_zero_
end_define

begin_define
define|#
directive|define
name|ffe_is_mainprog
parameter_list|()
value|ffe_is_mainprog_
end_define

begin_define
define|#
directive|define
name|ffe_is_onetrip
parameter_list|()
value|ffe_is_onetrip_
end_define

begin_define
define|#
directive|define
name|ffe_is_pedantic
parameter_list|()
value|ffe_is_pedantic_
end_define

begin_define
define|#
directive|define
name|ffe_is_pedantic_not_90
parameter_list|()
value|(ffe_is_pedantic_&& !ffe_is_90_)
end_define

begin_define
define|#
directive|define
name|ffe_is_saveall
parameter_list|()
value|ffe_is_saveall_
end_define

begin_define
define|#
directive|define
name|ffe_is_second_underscore
parameter_list|()
value|ffe_is_second_underscore_
end_define

begin_define
define|#
directive|define
name|ffe_is_silent
parameter_list|()
value|ffe_is_silent_
end_define

begin_define
define|#
directive|define
name|ffe_is_typeless_boz
parameter_list|()
value|ffe_is_typeless_boz_
end_define

begin_define
define|#
directive|define
name|ffe_is_ugly_args
parameter_list|()
value|ffe_is_ugly_args_
end_define

begin_define
define|#
directive|define
name|ffe_is_ugly_assign
parameter_list|()
value|ffe_is_ugly_assign_
end_define

begin_define
define|#
directive|define
name|ffe_is_ugly_assumed
parameter_list|()
value|ffe_is_ugly_assumed_
end_define

begin_define
define|#
directive|define
name|ffe_is_ugly_comma
parameter_list|()
value|ffe_is_ugly_comma_
end_define

begin_define
define|#
directive|define
name|ffe_is_ugly_complex
parameter_list|()
value|ffe_is_ugly_complex_
end_define

begin_define
define|#
directive|define
name|ffe_is_ugly_init
parameter_list|()
value|ffe_is_ugly_init_
end_define

begin_define
define|#
directive|define
name|ffe_is_ugly_logint
parameter_list|()
value|ffe_is_ugly_logint_
end_define

begin_define
define|#
directive|define
name|ffe_is_underscoring
parameter_list|()
value|ffe_is_underscoring_
end_define

begin_define
define|#
directive|define
name|ffe_is_version
parameter_list|()
value|ffe_is_version_
end_define

begin_define
define|#
directive|define
name|ffe_is_vxt
parameter_list|()
value|ffe_is_vxt_
end_define

begin_define
define|#
directive|define
name|ffe_is_warn_globals
parameter_list|()
value|ffe_is_warn_globals_
end_define

begin_define
define|#
directive|define
name|ffe_is_warn_implicit
parameter_list|()
value|ffe_is_warn_implicit_
end_define

begin_define
define|#
directive|define
name|ffe_is_warn_surprising
parameter_list|()
value|ffe_is_warn_surprising_
end_define

begin_define
define|#
directive|define
name|ffe_is_zeros
parameter_list|()
value|ffe_is_zeros_
end_define

begin_define
define|#
directive|define
name|ffe_fixed_line_length
parameter_list|()
value|ffe_fixed_line_length_
end_define

begin_define
define|#
directive|define
name|ffe_pool_file
parameter_list|()
value|(ffe_file_pool_)
end_define

begin_define
define|#
directive|define
name|ffe_pool_any_unit
parameter_list|()
value|(ffe_any_unit_pool_)
end_define

begin_define
define|#
directive|define
name|ffe_pool_program_unit
parameter_list|()
value|(ffe_program_unit_pool_)
end_define

begin_define
define|#
directive|define
name|ffe_set_case_intrin
parameter_list|(
name|f
parameter_list|)
value|(ffe_case_intrin_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_case_match
parameter_list|(
name|f
parameter_list|)
value|(ffe_case_match_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_case_source
parameter_list|(
name|f
parameter_list|)
value|(ffe_case_source_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_case_symbol
parameter_list|(
name|f
parameter_list|)
value|(ffe_case_symbol_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_intrinsic_state_badu77
parameter_list|(
name|s
parameter_list|)
value|(ffe_intrinsic_state_badu77_ = (s))
end_define

begin_define
define|#
directive|define
name|ffe_set_intrinsic_state_f2c
parameter_list|(
name|s
parameter_list|)
value|(ffe_intrinsic_state_f2c_ = (s))
end_define

begin_define
define|#
directive|define
name|ffe_set_intrinsic_state_f90
parameter_list|(
name|s
parameter_list|)
value|(ffe_intrinsic_state_f90_ = (s))
end_define

begin_define
define|#
directive|define
name|ffe_set_intrinsic_state_gnu
parameter_list|(
name|s
parameter_list|)
value|(ffe_intrinsic_state_gnu_ = (s))
end_define

begin_define
define|#
directive|define
name|ffe_set_intrinsic_state_mil
parameter_list|(
name|s
parameter_list|)
value|(ffe_intrinsic_state_mil_ = (s))
end_define

begin_define
define|#
directive|define
name|ffe_set_intrinsic_state_unix
parameter_list|(
name|s
parameter_list|)
value|(ffe_intrinsic_state_unix_ = (s))
end_define

begin_define
define|#
directive|define
name|ffe_set_intrinsic_state_vxt
parameter_list|(
name|s
parameter_list|)
value|(ffe_intrinsic_state_vxt_ = (s))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_90
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_90_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_automatic
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_automatic_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_backslash
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_backslash_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_debug_kludge
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_debug_kludge_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_do_internal_checks
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_do_internal_checks_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_dollar_ok
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_dollar_ok_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_emulate_complex
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_emulate_complex_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_f2c
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_f2c_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_f2c_library
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_f2c_library_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_ffedebug
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_ffedebug_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_flatten_arrays
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_flatten_arrays_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_free_form
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_free_form_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_globals
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_globals_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_init_local_zero
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_init_local_zero_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_mainprog
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_mainprog_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_onetrip
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_onetrip_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_pedantic
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_pedantic_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_saveall
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_saveall_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_second_underscore
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_second_underscore_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_silent
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_silent_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_typeless_boz
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_typeless_boz_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_ugly_args
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_ugly_args_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_ugly_assign
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_ugly_assign_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_ugly_assumed
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_ugly_assumed_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_ugly_comma
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_ugly_comma_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_ugly_complex
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_ugly_complex_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_ugly_init
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_ugly_init_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_ugly_logint
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_ugly_logint_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_underscoring
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_underscoring_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_version
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_version_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_vxt
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_vxt_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_warn_globals
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_warn_globals_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_warn_implicit
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_warn_implicit_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_warn_surprising
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_warn_surprising_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_is_zeros
parameter_list|(
name|f
parameter_list|)
value|(ffe_is_zeros_ = (f))
end_define

begin_define
define|#
directive|define
name|ffe_set_fixed_line_length
parameter_list|(
name|l
parameter_list|)
value|(ffe_fixed_line_length_ = (l))
end_define

begin_define
define|#
directive|define
name|ffe_state_max
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|((s1)> (s2) ? (s1) : (s2))
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_TOP_H */
end_comment

end_unit

