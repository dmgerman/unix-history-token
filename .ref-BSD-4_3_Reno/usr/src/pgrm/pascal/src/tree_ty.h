begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)tree_ty.h	5.1 (Berkeley) 6/5/85  */
end_comment

begin_typedef
typedef|typedef
struct|struct
comment|/* T_FORU, T_FORD */
block|{
name|int
name|line_no
decl_stmt|;
comment|/* line number of for */
name|struct
name|tnode
modifier|*
name|init_asg
decl_stmt|;
comment|/* initialization */
name|struct
name|tnode
modifier|*
name|term_expr
decl_stmt|;
comment|/* termination expresssion */
name|struct
name|tnode
modifier|*
name|for_stmnt
decl_stmt|;
comment|/* for statement */
block|}
name|FOR_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_ASGN */
block|{
name|int
name|line_no
decl_stmt|;
comment|/* line number of := */
name|struct
name|tnode
modifier|*
name|lhs_var
decl_stmt|;
name|struct
name|tnode
modifier|*
name|rhs_expr
decl_stmt|;
block|}
name|ASG_NODE
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|PTREE
end_ifndef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_VAR */
block|{
name|int
name|line_no
decl_stmt|;
name|char
modifier|*
name|cptr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|qual
decl_stmt|;
comment|/* list node */
block|}
name|VAR_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_FIELD */
block|{
name|char
modifier|*
name|id_ptr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|other
decl_stmt|;
block|}
name|FIELD_NODE
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
comment|/* T_VAR */
block|{
name|int
name|line_no
decl_stmt|;
name|char
modifier|*
name|cptr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|qual
decl_stmt|;
name|struct
name|nl
modifier|*
name|nl_entry
decl_stmt|;
block|}
name|VAR_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_FIELD */
block|{
name|char
modifier|*
name|id_ptr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|other
decl_stmt|;
name|struct
name|nl
modifier|*
name|nl_entry
decl_stmt|;
block|}
name|FIELD_NODE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
comment|/* T_MOD, T_MULT, T_DIVD, T_DIV, 					   T_AND, T_ADD, T_SUB, T_OR, 					   T_EQ, T_LT, T_GT, T_NE, T_LE 					   T_GE, T_IN */
block|{
name|int
name|const_tag
decl_stmt|;
name|struct
name|tnode
modifier|*
name|lhs
decl_stmt|;
name|struct
name|tnode
modifier|*
name|rhs
decl_stmt|;
block|}
name|EXPR_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_LISTPP */
block|{
name|struct
name|tnode
modifier|*
name|list
decl_stmt|;
comment|/* check the types on these, 			    this is used in pclvalue and lvalue */
name|struct
name|tnode
modifier|*
name|next
decl_stmt|;
block|}
name|LIST_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_IF, T_IFEL, T_IFX */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|cond_expr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|then_stmnt
decl_stmt|;
name|struct
name|tnode
modifier|*
name|else_stmnt
decl_stmt|;
block|}
name|IF_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_MINUS, T_PLUS, T_NOT */
block|{
name|int
name|const_tag
decl_stmt|;
name|struct
name|tnode
modifier|*
name|expr
decl_stmt|;
block|}
name|UN_EXPR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_PDEC, T_FDEC, T_PROG */
block|{
name|int
name|line_no
decl_stmt|;
name|char
modifier|*
name|id_ptr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|param_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|type
decl_stmt|;
block|}
name|P_DEC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_PVAL, T_PVAR */
block|{
name|struct
name|tnode
modifier|*
name|id_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|type
decl_stmt|;
block|}
name|PARAM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_PFUNC, T_PPROC */
block|{
name|struct
name|tnode
modifier|*
name|id_list
decl_stmt|,
modifier|*
name|type
decl_stmt|,
modifier|*
name|param_list
decl_stmt|;
name|int
name|line_no
decl_stmt|;
block|}
name|PFUNC_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_NIL */
block|{
name|int
name|const_tag
decl_stmt|;
block|}
name|NIL_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_STRNG, T_INT, T_FINT, T_BINT */
block|{
name|int
name|const_tag
decl_stmt|;
name|char
modifier|*
name|cptr
decl_stmt|;
block|}
name|CONST_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_CSTRNG, T_ID, T_CFINT, T_CINT, T_CBINT */
block|{
name|char
modifier|*
name|cptr
decl_stmt|;
block|}
name|CHAR_CONST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_PLUSC, T_MINUSC */
block|{
name|struct
name|tnode
modifier|*
name|number
decl_stmt|;
block|}
name|SIGN_CONST
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|PTREE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|line_no
expr|struct
name|tnode
operator|*
name|type
expr_stmt|;
name|struct
name|nl
modifier|*
name|nl_entry
decl_stmt|;
block|}
name|COMP_TY
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
comment|/* T_TYPACK, T_TYSCAL, T_TYFILE, T_TYSET, T_TYREC */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|type
decl_stmt|;
block|}
name|COMP_TY
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
comment|/* T_TYPTR */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|id_node
decl_stmt|;
block|}
name|PTR_TY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_TYRANG */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|const1
decl_stmt|;
name|struct
name|tnode
modifier|*
name|const2
decl_stmt|;
block|}
name|RANG_TY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_TYCRANG */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|lwb_var
decl_stmt|;
name|struct
name|tnode
modifier|*
name|upb_var
decl_stmt|;
name|struct
name|tnode
modifier|*
name|type
decl_stmt|;
block|}
name|CRANG_TY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_TYARY, T_TYCARY */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|type_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|type
decl_stmt|;
block|}
name|ARY_TY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_TYVARNT */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|const_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|fld_list
decl_stmt|;
block|}
name|TYVARNT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_TYVARPT */
block|{
name|int
name|line_no
decl_stmt|;
name|char
modifier|*
name|cptr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|type_id
decl_stmt|;
name|struct
name|tnode
modifier|*
name|var_list
decl_stmt|;
block|}
name|VARPT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_CSTAT */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|const_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|stmnt
decl_stmt|;
block|}
name|C_STMNT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_BSTL, T_BLOCK */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|stmnt_list
decl_stmt|;
block|}
name|STMNT_BLCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_FLDLST */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|fix_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|variant
decl_stmt|;
block|}
name|FLDLST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_RFIELD */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|id_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|type
decl_stmt|;
block|}
name|RFIELD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_LABEL */
block|{
name|int
name|line_no
decl_stmt|;
name|char
modifier|*
name|lbl_ptr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|stmnt
decl_stmt|;
block|}
name|LABEL_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_GOTO */
block|{
name|int
name|line_no
decl_stmt|;
name|char
modifier|*
name|lbl_ptr
decl_stmt|;
block|}
name|GOTO_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_PCALL, T_FCALL */
block|{
name|int
name|line_no
decl_stmt|;
name|char
modifier|*
name|proc_id
decl_stmt|;
name|struct
name|tnode
modifier|*
name|arg
decl_stmt|;
block|}
name|PCALL_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_CASE, T_WHILE */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|expr
decl_stmt|;
name|struct
name|tnode
modifier|*
name|stmnt_list
decl_stmt|;
block|}
name|WHI_CAS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_WITH */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|var_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|stmnt
decl_stmt|;
block|}
name|WITH_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_REPEAT */
block|{
name|int
name|line_no
decl_stmt|;
name|struct
name|tnode
modifier|*
name|stmnt_list
decl_stmt|;
name|struct
name|tnode
modifier|*
name|term_expr
decl_stmt|;
block|}
name|REPEAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_RANG */
block|{
name|struct
name|tnode
modifier|*
name|expr1
decl_stmt|;
name|struct
name|tnode
modifier|*
name|expr2
decl_stmt|;
block|}
name|RANG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_CSET */
block|{
name|int
name|const_tag
decl_stmt|;
name|struct
name|tnode
modifier|*
name|el_list
decl_stmt|;
block|}
name|CSET_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_ARY */
block|{
name|struct
name|tnode
modifier|*
name|expr_list
decl_stmt|;
block|}
name|ARY_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_WEXPR */
block|{
name|struct
name|tnode
modifier|*
name|expr1
decl_stmt|;
name|struct
name|tnode
modifier|*
name|expr2
decl_stmt|;
name|struct
name|tnode
modifier|*
name|expr3
decl_stmt|;
block|}
name|WEXPR_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* T_TYID */
block|{
name|int
name|line_no
decl_stmt|;
name|char
modifier|*
name|idptr
decl_stmt|;
block|}
name|TYID_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* anything with linenumber in first field */
block|{
name|int
name|line_no
decl_stmt|;
block|}
name|LINED
typedef|;
end_typedef

begin_struct
struct|struct
name|tnode
block|{
name|int
name|tag
decl_stmt|;
union|union
block|{
name|FOR_NODE
name|t_for_node
decl_stmt|;
name|ASG_NODE
name|t_asg_node
decl_stmt|;
name|VAR_NODE
name|t_var_node
decl_stmt|;
name|EXPR_NODE
name|t_expr_node
decl_stmt|;
name|LIST_NODE
name|t_list_node
decl_stmt|;
name|IF_NODE
name|t_if_node
decl_stmt|;
name|UN_EXPR
name|t_un_expr
decl_stmt|;
name|P_DEC
name|t_p_dec
decl_stmt|;
name|PARAM
name|t_param
decl_stmt|;
name|PFUNC_NODE
name|t_pfunc_node
decl_stmt|;
name|NIL_NODE
name|t_nil_node
decl_stmt|;
name|CONST_NODE
name|t_const_node
decl_stmt|;
name|CHAR_CONST
name|t_char_const
decl_stmt|;
name|SIGN_CONST
name|t_sign_const
decl_stmt|;
name|COMP_TY
name|t_comp_ty
decl_stmt|;
name|PTR_TY
name|t_ptr_ty
decl_stmt|;
name|RANG_TY
name|t_rang_ty
decl_stmt|;
name|CRANG_TY
name|t_crang_ty
decl_stmt|;
name|ARY_TY
name|t_ary_ty
decl_stmt|;
name|VARPT
name|t_varpt
decl_stmt|;
name|TYVARNT
name|t_tyvarnt
decl_stmt|;
name|C_STMNT
name|t_c_stmnt
decl_stmt|;
name|STMNT_BLCK
name|t_stmnt_blck
decl_stmt|;
name|FLDLST
name|t_fldlst
decl_stmt|;
name|RFIELD
name|t_rfield
decl_stmt|;
name|LABEL_NODE
name|t_label_node
decl_stmt|;
name|PCALL_NODE
name|t_pcall_node
decl_stmt|;
name|WHI_CAS
name|t_whi_cas
decl_stmt|;
name|WITH_NODE
name|t_with_node
decl_stmt|;
name|REPEAT
name|t_repeat
decl_stmt|;
name|RANG
name|t_rang
decl_stmt|;
name|CSET_NODE
name|t_cset_node
decl_stmt|;
name|ARY_NODE
name|t_ary_node
decl_stmt|;
name|WEXPR_NODE
name|t_wexpr_node
decl_stmt|;
name|FIELD_NODE
name|t_field_node
decl_stmt|;
name|TYID_NODE
name|t_tyid_node
decl_stmt|;
name|LINED
name|t_lined
decl_stmt|;
name|GOTO_NODE
name|t_goto_node
decl_stmt|;
block|}
name|tree_ele
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|for_node
value|tree_ele.t_for_node
end_define

begin_define
define|#
directive|define
name|asg_node
value|tree_ele.t_asg_node
end_define

begin_define
define|#
directive|define
name|var_node
value|tree_ele.t_var_node
end_define

begin_define
define|#
directive|define
name|expr_node
value|tree_ele.t_expr_node
end_define

begin_define
define|#
directive|define
name|list_node
value|tree_ele.t_list_node
end_define

begin_define
define|#
directive|define
name|if_node
value|tree_ele.t_if_node
end_define

begin_define
define|#
directive|define
name|un_expr
value|tree_ele.t_un_expr
end_define

begin_define
define|#
directive|define
name|p_dec
value|tree_ele.t_p_dec
end_define

begin_define
define|#
directive|define
name|param
value|tree_ele.t_param
end_define

begin_define
define|#
directive|define
name|pfunc_node
value|tree_ele.t_pfunc_node
end_define

begin_define
define|#
directive|define
name|nil_node
value|tree_ele.t_nil_node
end_define

begin_define
define|#
directive|define
name|const_node
value|tree_ele.t_const_node
end_define

begin_define
define|#
directive|define
name|char_const
value|tree_ele.t_char_const
end_define

begin_define
define|#
directive|define
name|sign_const
value|tree_ele.t_sign_const
end_define

begin_define
define|#
directive|define
name|comp_ty
value|tree_ele.t_comp_ty
end_define

begin_define
define|#
directive|define
name|ptr_ty
value|tree_ele.t_ptr_ty
end_define

begin_define
define|#
directive|define
name|rang_ty
value|tree_ele.t_rang_ty
end_define

begin_define
define|#
directive|define
name|crang_ty
value|tree_ele.t_crang_ty
end_define

begin_define
define|#
directive|define
name|ary_ty
value|tree_ele.t_ary_ty
end_define

begin_define
define|#
directive|define
name|varpt
value|tree_ele.t_varpt
end_define

begin_define
define|#
directive|define
name|tyvarnt
value|tree_ele.t_tyvarnt
end_define

begin_define
define|#
directive|define
name|c_stmnt
value|tree_ele.t_c_stmnt
end_define

begin_define
define|#
directive|define
name|stmnt_blck
value|tree_ele.t_stmnt_blck
end_define

begin_define
define|#
directive|define
name|fldlst
value|tree_ele.t_fldlst
end_define

begin_define
define|#
directive|define
name|rfield
value|tree_ele.t_rfield
end_define

begin_define
define|#
directive|define
name|label_node
value|tree_ele.t_label_node
end_define

begin_define
define|#
directive|define
name|pcall_node
value|tree_ele.t_pcall_node
end_define

begin_define
define|#
directive|define
name|whi_cas
value|tree_ele.t_whi_cas
end_define

begin_define
define|#
directive|define
name|with_node
value|tree_ele.t_with_node
end_define

begin_define
define|#
directive|define
name|repeat
value|tree_ele.t_repeat
end_define

begin_define
define|#
directive|define
name|rang
value|tree_ele.t_rang
end_define

begin_define
define|#
directive|define
name|cset_node
value|tree_ele.t_cset_node
end_define

begin_define
define|#
directive|define
name|ary_node
value|tree_ele.t_ary_node
end_define

begin_define
define|#
directive|define
name|wexpr_node
value|tree_ele.t_wexpr_node
end_define

begin_define
define|#
directive|define
name|field_node
value|tree_ele.t_field_node
end_define

begin_define
define|#
directive|define
name|tyid_node
value|tree_ele.t_tyid_node
end_define

begin_define
define|#
directive|define
name|lined
value|tree_ele.t_lined
end_define

begin_define
define|#
directive|define
name|goto_node
value|tree_ele.t_goto_node
end_define

end_unit

