begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stw.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       stw.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_f_stw
end_ifndef

begin_define
define|#
directive|define
name|_H_f_stw
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffestw_
modifier|*
name|ffestw
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffestw_case_
modifier|*
name|ffestwCase
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffestw_select_
modifier|*
name|ffestwSelect
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ffestwShriek
function_decl|)
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"bld.h"
end_include

begin_include
include|#
directive|include
file|"com.h"
end_include

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"lab.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"stv.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_include
include|#
directive|include
file|"where.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffestw_
block|{
name|ffestw
name|next_
decl_stmt|;
comment|/* Next (unused) block, or NULL. */
name|ffestw
name|previous_
decl_stmt|;
comment|/* Previous block, NULL if this is NIL state. */
name|ffestw
name|top_do_
decl_stmt|;
comment|/* Previous or current DO state, or NULL. */
name|unsigned
name|long
name|blocknum_
decl_stmt|;
comment|/* Block # w/in procedure/program. */
name|ffestwShriek
name|shriek_
decl_stmt|;
comment|/* Call me to pop block in a hurry. */
name|ffesymbol
name|sym_
decl_stmt|;
comment|/* Related symbol (if there is one). */
name|ffelexToken
name|name_
decl_stmt|;
comment|/* Construct name (IFTHEN, SELECT, DO only). */
name|ffestwSelect
name|select_
decl_stmt|;
comment|/* Info for SELECT CASE blocks. */
name|ffelab
name|label_
decl_stmt|;
comment|/* For DO blocks w/labels, the target label. */
name|ffesymbol
name|do_iter_var_
decl_stmt|;
comment|/* For iter DO blocks, the iter var or NULL. */
name|ffelexToken
name|do_iter_var_t_
decl_stmt|;
comment|/* The token for do_iter_var. */
name|ffewhereLine
name|line_
decl_stmt|;
comment|/* Where first token of statement triggering 				   state */
name|ffewhereColumn
name|col_
decl_stmt|;
comment|/* was seen in source file. */
name|int
name|uses_
decl_stmt|;
comment|/* # uses (new+use-kill calls). */
name|ffestvState
name|state_
decl_stmt|;
name|int
name|substate_
decl_stmt|;
comment|/* Used on a per-block-state basis. */
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
name|struct
name|nesting
modifier|*
name|do_hook_
decl_stmt|;
comment|/* backend id for given loop (EXIT/CYCLE). */
name|tree
name|do_tvar_
decl_stmt|;
comment|/* tree form of do_iter_var. */
name|tree
name|do_incr_saved_
decl_stmt|;
comment|/* tree SAVED_EXPR of incr expr. */
name|tree
name|do_count_var_
decl_stmt|;
comment|/* tree of countdown variable. */
name|tree
name|select_texpr_
decl_stmt|;
comment|/* tree for end case. */
name|bool
name|select_break_
decl_stmt|;
comment|/* TRUE when CASE should start with gen 				   "break;". */
name|int
name|ifthen_fake_else_
decl_stmt|;
comment|/* Number of fake `else' introductions.  */
endif|#
directive|endif
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffestw_case_
block|{
name|ffestwCase
name|next_rel
decl_stmt|;
comment|/* Next case range in relational order. */
name|ffestwCase
name|previous_rel
decl_stmt|;
comment|/* Previous case range in relational order. */
name|ffestwCase
name|next_stmt
decl_stmt|;
comment|/* Next range in stmt or first in next stmt. */
name|ffestwCase
name|previous_stmt
decl_stmt|;
comment|/* Previous range. */
name|ffebldConstant
name|low
decl_stmt|;
comment|/* Low value in range. */
name|ffebldConstant
name|high
decl_stmt|;
comment|/* High value in range. */
name|unsigned
name|long
name|casenum
decl_stmt|;
comment|/* CASE stmt index for this range/value. */
name|ffelexToken
name|t
decl_stmt|;
comment|/* Token for this range/value; ffestc only. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffestw_select_
block|{
name|ffestwCase
name|first_rel
decl_stmt|;
comment|/* First CASE range (after low) in order. */
name|ffestwCase
name|last_rel
decl_stmt|;
comment|/* Last CASE range (before high) in order. */
name|ffestwCase
name|first_stmt
decl_stmt|;
comment|/* First range in first CASE stmt. */
name|ffestwCase
name|last_stmt
decl_stmt|;
comment|/* Last range in last CASE stmt. */
name|mallocPool
name|pool
decl_stmt|;
comment|/* Pool in which this and all cases are 				   allocated. */
name|unsigned
name|long
name|cases
decl_stmt|;
comment|/* Number of CASE stmts seen so far. */
name|ffelexToken
name|t
decl_stmt|;
comment|/* First token of selected expression; ffestc 				   only. */
name|ffeinfoBasictype
name|type
decl_stmt|;
comment|/* Basic type (integer, character, or 				   logical). */
name|ffeinfoKindtype
name|kindtype
decl_stmt|;
comment|/* Kind type. */
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|ffestw
name|ffestw_stack_top_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffestw_display_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestw_kill
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestw_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestw
name|ffestw_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestw
name|ffestw_pop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestw
name|ffestw_push
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestw
name|ffestw_update
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestw
name|ffestw_use
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffestw_blocknum
parameter_list|(
name|b
parameter_list|)
value|((b)->blocknum_)
end_define

begin_define
define|#
directive|define
name|ffestw_col
parameter_list|(
name|b
parameter_list|)
value|((b)->col_)
end_define

begin_define
define|#
directive|define
name|ffestw_do_count_var
parameter_list|(
name|b
parameter_list|)
value|((b)->do_count_var_)
end_define

begin_define
define|#
directive|define
name|ffestw_do_hook
parameter_list|(
name|b
parameter_list|)
value|((b)->do_hook_)
end_define

begin_define
define|#
directive|define
name|ffestw_do_incr_saved
parameter_list|(
name|b
parameter_list|)
value|((b)->do_incr_saved_)
end_define

begin_define
define|#
directive|define
name|ffestw_do_iter_var
parameter_list|(
name|b
parameter_list|)
value|((b)->do_iter_var_)
end_define

begin_define
define|#
directive|define
name|ffestw_do_iter_var_t
parameter_list|(
name|b
parameter_list|)
value|((b)->do_iter_var_t_)
end_define

begin_define
define|#
directive|define
name|ffestw_do_tvar
parameter_list|(
name|b
parameter_list|)
value|((b)->do_tvar_)
end_define

begin_define
define|#
directive|define
name|ffestw_ifthen_fake_else
parameter_list|(
name|b
parameter_list|)
value|((b)->ifthen_fake_else_)
end_define

begin_define
define|#
directive|define
name|ffestw_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_label
parameter_list|(
name|b
parameter_list|)
value|((b)->label_)
end_define

begin_define
define|#
directive|define
name|ffestw_line
parameter_list|(
name|b
parameter_list|)
value|((b)->line_)
end_define

begin_define
define|#
directive|define
name|ffestw_name
parameter_list|(
name|b
parameter_list|)
value|((b)->name_)
end_define

begin_define
define|#
directive|define
name|ffestw_previous
parameter_list|(
name|b
parameter_list|)
value|((b)->previous_)
end_define

begin_define
define|#
directive|define
name|ffestw_select
parameter_list|(
name|b
parameter_list|)
value|((b)->select_)
end_define

begin_define
define|#
directive|define
name|ffestw_select_break
parameter_list|(
name|b
parameter_list|)
value|((b)->select_break_)
end_define

begin_define
define|#
directive|define
name|ffestw_select_texpr
parameter_list|(
name|b
parameter_list|)
value|((b)->select_texpr_)
end_define

begin_define
define|#
directive|define
name|ffestw_set_blocknum
parameter_list|(
name|b
parameter_list|,
name|bl
parameter_list|)
value|((b)->blocknum_ = (bl))
end_define

begin_define
define|#
directive|define
name|ffestw_set_col
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|)
value|((b)->col_ = (c))
end_define

begin_define
define|#
directive|define
name|ffestw_set_do_count_var
parameter_list|(
name|b
parameter_list|,
name|d
parameter_list|)
value|((b)->do_count_var_ = (d))
end_define

begin_define
define|#
directive|define
name|ffestw_set_do_hook
parameter_list|(
name|b
parameter_list|,
name|d
parameter_list|)
value|((b)->do_hook_ = (d))
end_define

begin_define
define|#
directive|define
name|ffestw_set_do_incr_saved
parameter_list|(
name|b
parameter_list|,
name|d
parameter_list|)
value|((b)->do_incr_saved_ = (d))
end_define

begin_define
define|#
directive|define
name|ffestw_set_do_iter_var
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|((b)->do_iter_var_ = (v))
end_define

begin_define
define|#
directive|define
name|ffestw_set_do_iter_var_t
parameter_list|(
name|b
parameter_list|,
name|t
parameter_list|)
value|((b)->do_iter_var_t_ = (t))
end_define

begin_define
define|#
directive|define
name|ffestw_set_do_tvar
parameter_list|(
name|b
parameter_list|,
name|d
parameter_list|)
value|((b)->do_tvar_ = (d))
end_define

begin_define
define|#
directive|define
name|ffestw_set_ifthen_fake_else
parameter_list|(
name|b
parameter_list|,
name|e
parameter_list|)
value|((b)->ifthen_fake_else_ = (e))
end_define

begin_define
define|#
directive|define
name|ffestw_set_label
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|)
value|((b)->label_ = (l))
end_define

begin_define
define|#
directive|define
name|ffestw_set_line
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|)
value|((b)->line_ = (l))
end_define

begin_define
define|#
directive|define
name|ffestw_set_name
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->name_ = (n))
end_define

begin_define
define|#
directive|define
name|ffestw_set_select
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|((b)->select_ = (s))
end_define

begin_define
define|#
directive|define
name|ffestw_set_select_break
parameter_list|(
name|b
parameter_list|,
name|br
parameter_list|)
value|((b)->select_break_ = (br))
end_define

begin_define
define|#
directive|define
name|ffestw_set_select_texpr
parameter_list|(
name|b
parameter_list|,
name|t
parameter_list|)
value|((b)->select_texpr_ = (t))
end_define

begin_define
define|#
directive|define
name|ffestw_set_shriek
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|((b)->shriek_ = (s))
end_define

begin_define
define|#
directive|define
name|ffestw_set_state
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|((b)->state_ = (s))
end_define

begin_define
define|#
directive|define
name|ffestw_set_substate
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|((b)->substate_ = (s))
end_define

begin_define
define|#
directive|define
name|ffestw_set_sym
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|((b)->sym_= (s))
end_define

begin_define
define|#
directive|define
name|ffestw_set_top_do
parameter_list|(
name|b
parameter_list|,
name|t
parameter_list|)
value|((b)->top_do_ = (t))
end_define

begin_define
define|#
directive|define
name|ffestw_shriek
parameter_list|(
name|b
parameter_list|)
value|((b)->shriek_)
end_define

begin_define
define|#
directive|define
name|ffestw_stack_top
parameter_list|()
value|ffestw_stack_top_
end_define

begin_define
define|#
directive|define
name|ffestw_state
parameter_list|(
name|b
parameter_list|)
value|((b)->state_)
end_define

begin_define
define|#
directive|define
name|ffestw_substate
parameter_list|(
name|b
parameter_list|)
value|((b)->substate_)
end_define

begin_define
define|#
directive|define
name|ffestw_sym
parameter_list|(
name|b
parameter_list|)
value|((b)->sym_)
end_define

begin_define
define|#
directive|define
name|ffestw_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestw_top_do
parameter_list|(
name|b
parameter_list|)
value|((b)->top_do_)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

