begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b2exp.h,v 1.4 85/08/22 16:42:25 timo Exp $ */
end_comment

begin_comment
comment|/* General definitions for parsing expressions */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|parsed
decl_stmt|,
name|prop
decl_stmt|,
name|trim
decl_stmt|;
name|intlet
name|state
decl_stmt|,
name|level
decl_stmt|,
name|field
decl_stmt|;
name|value
name|comp
decl_stmt|;
block|}
name|expadm
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|prop
decl_stmt|,
name|trim
decl_stmt|;
name|intlet
name|level
decl_stmt|,
name|field
decl_stmt|;
name|parsetree
name|node
decl_stmt|;
block|}
name|unpadm
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Parsed
parameter_list|(
name|adm
parameter_list|)
value|((adm)->parsed)
end_define

begin_define
define|#
directive|define
name|Prop
parameter_list|(
name|adm
parameter_list|)
value|((adm)->prop)
end_define

begin_define
define|#
directive|define
name|Trim
parameter_list|(
name|adm
parameter_list|)
value|((adm)->trim)
end_define

begin_define
define|#
directive|define
name|State
parameter_list|(
name|adm
parameter_list|)
value|((adm)->state)
end_define

begin_define
define|#
directive|define
name|Level
parameter_list|(
name|adm
parameter_list|)
value|((adm)->level)
end_define

begin_define
define|#
directive|define
name|N_fld
parameter_list|(
name|adm
parameter_list|)
value|((adm)->field)
end_define

begin_define
define|#
directive|define
name|Unp_comp
parameter_list|(
name|adm
parameter_list|)
value|((adm)->comp)
end_define

begin_define
define|#
directive|define
name|Node
parameter_list|(
name|adm
parameter_list|)
value|((adm)->node)
end_define

begin_comment
comment|/* ********************************************************************	*/
end_comment

begin_comment
comment|/* Levels:								*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_define
define|#
directive|define
name|L_bottom
value|0
end_define

begin_define
define|#
directive|define
name|L_term
value|1
end_define

begin_comment
comment|/* plus, minus, join */
end_comment

begin_define
define|#
directive|define
name|L_factor
value|2
end_define

begin_comment
comment|/* times, over */
end_comment

begin_define
define|#
directive|define
name|L_power
value|3
end_define

begin_comment
comment|/* power */
end_comment

begin_define
define|#
directive|define
name|L_number
value|4
end_define

begin_comment
comment|/* number  */
end_comment

begin_define
define|#
directive|define
name|L_expr
value|5
end_define

begin_comment
comment|/* tag, repeat_text, center, (left|right)_adjust */
end_comment

begin_define
define|#
directive|define
name|Prio
define|\
value|MESS(1900, "cannot determine priorities; use ( and ) to resolve")
end_define

begin_comment
comment|/* ******************************************************************** */
end_comment

begin_comment
comment|/* States:								*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_define
define|#
directive|define
name|S_t
value|1
end_define

begin_define
define|#
directive|define
name|S_tt
value|2
end_define

begin_define
define|#
directive|define
name|S_else
value|3
end_define

begin_comment
comment|/* ******************************************************************** */
end_comment

begin_function_decl
name|bool
name|b_about
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_numtor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_denomtor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_plus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_minus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_number
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_behead
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_curtail
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_USED
end_ifdef

begin_function_decl
name|bool
name|b_times
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_over
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_power
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_join
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_reptext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_center
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_leftadj
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|b_rightadj
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

