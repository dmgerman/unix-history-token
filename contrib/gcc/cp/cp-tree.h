begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for C++ parsing and type checking.    Copyright (C) 1987, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001, 2002, 2003, 2004, 2005, 2006  Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@cygnus.com)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CP_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CP_TREE_H
end_define

begin_include
include|#
directive|include
file|"ggc.h"
end_include

begin_include
include|#
directive|include
file|"function.h"
end_include

begin_include
include|#
directive|include
file|"hashtab.h"
end_include

begin_include
include|#
directive|include
file|"splay-tree.h"
end_include

begin_include
include|#
directive|include
file|"vec.h"
end_include

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_include
include|#
directive|include
file|"name-lookup.h"
end_include

begin_struct_decl
struct_decl|struct
name|diagnostic_context
struct_decl|;
end_struct_decl

begin_comment
comment|/* Usage of TREE_LANG_FLAG_?:    0: IDENTIFIER_MARKED (IDENTIFIER_NODEs)       NEW_EXPR_USE_GLOBAL (in NEW_EXPR).       DELETE_EXPR_USE_GLOBAL (in DELETE_EXPR).       COMPOUND_EXPR_OVERLOADED (in COMPOUND_EXPR).       TREE_INDIRECT_USING (in NAMESPACE_DECL).       CLEANUP_P (in TRY_BLOCK)       AGGR_INIT_VIA_CTOR_P (in AGGR_INIT_EXPR)       PTRMEM_OK_P (in ADDR_EXPR, OFFSET_REF)       PAREN_STRING_LITERAL (in STRING_CST)       DECL_PRETTY_FUNCTION_P (in VAR_DECL)       KOENIG_LOOKUP_P (in CALL_EXPR)       STATEMENT_LIST_NO_SCOPE (in STATEMENT_LIST).       EXPR_STMT_STMT_EXPR_RESULT (in EXPR_STMT)       STMT_EXPR_NO_SCOPE (in STMT_EXPR)       BIND_EXPR_TRY_BLOCK (in BIND_EXPR)       TYPENAME_IS_ENUM_P (in TYPENAME_TYPE)       REFERENCE_REF_P (in INDIRECT_EXPR)       QUALIFIED_NAME_IS_TEMPLATE (in SCOPE_REF)       OMP_ATOMIC_DEPENDENT_P (in OMP_ATOMIC)       OMP_FOR_GIMPLIFYING_P (in OMP_FOR)       BASELINK_QUALIFIED_P (in BASELINK)       TARGET_EXPR_IMPLICIT_P (in TARGET_EXPR)    1: IDENTIFIER_VIRTUAL_P (in IDENTIFIER_NODE)       TI_PENDING_TEMPLATE_FLAG.       TEMPLATE_PARMS_FOR_INLINE.       DELETE_EXPR_USE_VEC (in DELETE_EXPR).       (TREE_CALLS_NEW) (in _EXPR or _REF) (commented-out).       ICS_ELLIPSIS_FLAG (in _CONV)       DECL_INITIALIZED_P (in VAR_DECL)       TYPENAME_IS_CLASS_P (in TYPENAME_TYPE)       STMT_IS_FULL_EXPR_P (in _STMT)    2: IDENTIFIER_OPNAME_P (in IDENTIFIER_NODE)       ICS_THIS_FLAG (in _CONV)       DECL_INITIALIZED_BY_CONSTANT_EXPRESSION_P (in VAR_DECL)       STATEMENT_LIST_TRY_BLOCK (in STATEMENT_LIST)    3: (TREE_REFERENCE_EXPR) (in NON_LVALUE_EXPR) (commented-out).       ICS_BAD_FLAG (in _CONV)       FN_TRY_BLOCK_P (in TRY_BLOCK)       IDENTIFIER_CTOR_OR_DTOR_P (in IDENTIFIER_NODE)       BIND_EXPR_BODY_BLOCK (in BIND_EXPR)       DECL_NON_TRIVIALLY_INITIALIZED_P (in VAR_DECL)    4: TREE_HAS_CONSTRUCTOR (in INDIRECT_REF, SAVE_EXPR, CONSTRUCTOR, 	  or FIELD_DECL).       IDENTIFIER_TYPENAME_P (in IDENTIFIER_NODE)       DECL_TINFO_P (in VAR_DECL)    5: C_IS_RESERVED_WORD (in IDENTIFIER_NODE)       DECL_VTABLE_OR_VTT_P (in VAR_DECL)    6: IDENTIFIER_REPO_CHOSEN (in IDENTIFIER_NODE)       DECL_CONSTRUCTION_VTABLE_P (in VAR_DECL)       TYPE_MARKED_P (in _TYPE)     Usage of TYPE_LANG_FLAG_?:    0: TYPE_DEPENDENT_P    1: TYPE_HAS_CONSTRUCTOR.    2: Unused    3: TYPE_FOR_JAVA.    4: TYPE_HAS_NONTRIVIAL_DESTRUCTOR    5: IS_AGGR_TYPE.    6: TYPE_DEPENDENT_P_VALID     Usage of DECL_LANG_FLAG_?:    0: DECL_ERROR_REPORTED (in VAR_DECL).       DECL_TEMPLATE_PARM_P (in PARM_DECL, CONST_DECL, TYPE_DECL, or TEMPLATE_DECL)       DECL_LOCAL_FUNCTION_P (in FUNCTION_DECL)       DECL_MUTABLE_P (in FIELD_DECL)       DECL_DEPENDENT_P (in USING_DECL)    1: C_TYPEDEF_EXPLICITLY_SIGNED (in TYPE_DECL).       DECL_TEMPLATE_INSTANTIATED (in a VAR_DECL or a FUNCTION_DECL)       DECL_MEMBER_TEMPLATE_P (in TEMPLATE_DECL)    2: DECL_THIS_EXTERN (in VAR_DECL or FUNCTION_DECL).       DECL_IMPLICIT_TYPEDEF_P (in a TYPE_DECL)    3: DECL_IN_AGGR_P.    4: DECL_C_BIT_FIELD (in a FIELD_DECL)       DECL_ANON_UNION_VAR_P (in a VAR_DECL)       DECL_SELF_REFERENCE_P (in a TYPE_DECL)       DECL_INVALID_OVERRIDER_P (in a FUNCTION_DECL)    5: DECL_INTERFACE_KNOWN.    6: DECL_THIS_STATIC (in VAR_DECL or FUNCTION_DECL).       DECL_FIELD_IS_BASE (in FIELD_DECL)    7: DECL_DEAD_FOR_LOCAL (in VAR_DECL).       DECL_THUNK_P (in a member FUNCTION_DECL)     Usage of language-independent fields in a language-dependent manner:     TYPE_ALIAS_SET      This field is used by TYPENAME_TYPEs, TEMPLATE_TYPE_PARMs, and so      forth as a substitute for the mark bits provided in `lang_type'.      At present, only the six low-order bits are used.     TYPE_LANG_SLOT_1      For an ENUMERAL_TYPE, this is ENUM_TEMPLATE_INFO.      For a FUNCTION_TYPE or METHOD_TYPE, this is TYPE_RAISES_EXCEPTIONS    BINFO_VIRTUALS      For a binfo, this is a TREE_LIST.  There is an entry for each      virtual function declared either in BINFO or its direct and      indirect primary bases.       The BV_DELTA of each node gives the amount by which to adjust the      `this' pointer when calling the function.  If the method is an      overridden version of a base class method, then it is assumed      that, prior to adjustment, the this pointer points to an object      of the base class.       The BV_VCALL_INDEX of each node, if non-NULL, gives the vtable      index of the vcall offset for this entry.       The BV_FN is the declaration for the virtual function itself.     BINFO_VTABLE      This is an expression with POINTER_TYPE that gives the value      to which the vptr should be initialized.  Use get_vtbl_decl_for_binfo      to extract the VAR_DECL for the complete vtable.     DECL_ARGUMENTS      For a VAR_DECL this is DECL_ANON_UNION_ELEMS.     DECL_VINDEX      This field is NULL for a non-virtual function.  For a virtual      function, it is eventually set to an INTEGER_CST indicating the      index in the vtable at which this function can be found.  When      a virtual function is declared, but before it is known what      function is overridden, this field is the error_mark_node.       Temporarily, it may be set to a TREE_LIST whose TREE_VALUE is      the virtual function this one overrides, and whose TREE_CHAIN is      the old DECL_VINDEX.  */
end_comment

begin_comment
comment|/* Language-specific tree checkers.  */
end_comment

begin_define
define|#
directive|define
name|VAR_OR_FUNCTION_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_CHECK2(NODE,VAR_DECL,FUNCTION_DECL)
end_define

begin_define
define|#
directive|define
name|VAR_FUNCTION_OR_PARM_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_CHECK3(NODE,VAR_DECL,FUNCTION_DECL,PARM_DECL)
end_define

begin_define
define|#
directive|define
name|VAR_TEMPL_TYPE_OR_FUNCTION_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_CHECK4(NODE,VAR_DECL,FUNCTION_DECL,TYPE_DECL,TEMPLATE_DECL)
end_define

begin_define
define|#
directive|define
name|BOUND_TEMPLATE_TEMPLATE_PARM_TYPE_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_CHECK(NODE,BOUND_TEMPLATE_TEMPLATE_PARM)
end_define

begin_if
if|#
directive|if
name|defined
name|ENABLE_TREE_CHECKING
operator|&&
operator|(
name|GCC_VERSION
operator|>=
literal|2007
operator|)
end_if

begin_define
define|#
directive|define
name|NON_THUNK_FUNCTION_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|__extension__			\ ({  const tree __t = (NODE);						\     if (TREE_CODE (__t) != FUNCTION_DECL&&				\ 	TREE_CODE (__t) != TEMPLATE_DECL&& __t->decl_common.lang_specific	\&& __t->decl_common.lang_specific->decl_flags.thunk_p)			\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__, 0);	\     __t; })
end_define

begin_define
define|#
directive|define
name|THUNK_FUNCTION_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|__extension__			\ ({  const tree __t = (NODE);						\     if (TREE_CODE (__t) != FUNCTION_DECL || !__t->decl_common.lang_specific	\ 	|| !__t->decl_common.lang_specific->decl_flags.thunk_p)		\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__, 0);	\      __t; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NON_THUNK_FUNCTION_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|(NODE)
end_define

begin_define
define|#
directive|define
name|THUNK_FUNCTION_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|(NODE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Language-dependent contents of an identifier.  */
end_comment

begin_decl_stmt
name|struct
name|lang_identifier
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|c_common_identifier
name|c_common
decl_stmt|;
name|cxx_binding
modifier|*
name|namespace_bindings
decl_stmt|;
name|cxx_binding
modifier|*
name|bindings
decl_stmt|;
name|tree
name|class_template_info
decl_stmt|;
name|tree
name|label_value
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In an IDENTIFIER_NODE, nonzero if this identifier is actually a    keyword.  C_RID_CODE (node) is then the RID_* value of the keyword,    and C_RID_YYCODE is the token number wanted by Yacc.  */
end_comment

begin_define
define|#
directive|define
name|C_IS_RESERVED_WORD
parameter_list|(
name|ID
parameter_list|)
value|TREE_LANG_FLAG_5 (ID)
end_define

begin_define
define|#
directive|define
name|LANG_IDENTIFIER_CAST
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((struct lang_identifier*)IDENTIFIER_NODE_CHECK (NODE))
end_define

begin_decl_stmt
name|struct
name|template_parm_index_s
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|HOST_WIDE_INT
name|index
decl_stmt|;
name|HOST_WIDE_INT
name|level
decl_stmt|;
name|HOST_WIDE_INT
name|orig_level
decl_stmt|;
name|tree
name|decl
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|template_parm_index_s
name|template_parm_index
typedef|;
end_typedef

begin_decl_stmt
name|struct
name|tinst_level_s
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|tree
name|decl
decl_stmt|;
name|location_t
name|locus
decl_stmt|;
name|int
name|in_system_header_p
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|tinst_level_s
modifier|*
name|tinst_level_t
typedef|;
end_typedef

begin_decl_stmt
name|struct
name|ptrmem_cst
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
comment|/* This isn't used, but the middle-end expects all constants to have      this field.  */
name|rtx
name|rtl
decl_stmt|;
name|tree
name|member
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|ptrmem_cst
modifier|*
name|ptrmem_cst_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IDENTIFIER_GLOBAL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|namespace_binding ((NODE), global_namespace)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_GLOBAL_VALUE
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|set_namespace_binding ((NODE), global_namespace, (VAL))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_NAMESPACE_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|namespace_binding ((NODE), current_namespace)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_NAMESPACE_VALUE
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|set_namespace_binding ((NODE), current_namespace, (VAL))
end_define

begin_define
define|#
directive|define
name|CLEANUP_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (TRY_BLOCK_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|BIND_EXPR_TRY_BLOCK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (BIND_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* Used to mark the block around the member initializers and cleanups.  */
end_comment

begin_define
define|#
directive|define
name|BIND_EXPR_BODY_BLOCK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_3 (BIND_EXPR_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|FUNCTION_NEEDS_BODY_BLOCK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONSTRUCTOR_P (NODE) || DECL_DESTRUCTOR_P (NODE))
end_define

begin_define
define|#
directive|define
name|STATEMENT_LIST_NO_SCOPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (STATEMENT_LIST_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|STATEMENT_LIST_TRY_BLOCK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_2 (STATEMENT_LIST_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if this statement should be considered a full-expression,    i.e., if temporaries created during this statement should have    their destructors run at the end of this statement.  */
end_comment

begin_define
define|#
directive|define
name|STMT_IS_FULL_EXPR_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1 ((NODE))
end_define

begin_comment
comment|/* Marks the result of a statement expression.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_STMT_STMT_EXPR_RESULT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (EXPR_STMT_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if this statement-expression does not have an associated scope.  */
end_comment

begin_define
define|#
directive|define
name|STMT_EXPR_NO_SCOPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (STMT_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* Returns nonzero iff TYPE1 and TYPE2 are the same type, in the usual    sense of `same'.  */
end_comment

begin_define
define|#
directive|define
name|same_type_p
parameter_list|(
name|TYPE1
parameter_list|,
name|TYPE2
parameter_list|)
define|\
value|comptypes ((TYPE1), (TYPE2), COMPARE_STRICT)
end_define

begin_comment
comment|/* Returns nonzero iff TYPE1 and TYPE2 are the same type, ignoring    top-level qualifiers.  */
end_comment

begin_define
define|#
directive|define
name|same_type_ignoring_top_level_qualifiers_p
parameter_list|(
name|TYPE1
parameter_list|,
name|TYPE2
parameter_list|)
define|\
value|same_type_p (TYPE_MAIN_VARIANT (TYPE1), TYPE_MAIN_VARIANT (TYPE2))
end_define

begin_comment
comment|/* Nonzero if we are presently building a statement tree, rather    than expanding each statement as we encounter it.  */
end_comment

begin_define
define|#
directive|define
name|building_stmt_tree
parameter_list|()
value|(cur_stmt_list != NULL_TREE)
end_define

begin_comment
comment|/* Returns nonzero iff NODE is a declaration for the global function    `main'.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAIN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_EXTERN_C_FUNCTION_P (NODE)			\&& DECL_NAME (NODE) != NULL_TREE			\&& MAIN_NAME_P (DECL_NAME (NODE)))
end_define

begin_comment
comment|/* The overloaded FUNCTION_DECL.  */
end_comment

begin_define
define|#
directive|define
name|OVL_FUNCTION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct tree_overload*)OVERLOAD_CHECK (NODE))->function)
end_define

begin_define
define|#
directive|define
name|OVL_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_CHAIN (NODE)
end_define

begin_comment
comment|/* Polymorphic access to FUNCTION and CHAIN.  */
end_comment

begin_define
define|#
directive|define
name|OVL_CURRENT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_CODE (NODE) == OVERLOAD) ? OVL_FUNCTION (NODE) : (NODE))
end_define

begin_define
define|#
directive|define
name|OVL_NEXT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_CODE (NODE) == OVERLOAD) ? TREE_CHAIN (NODE) : NULL_TREE)
end_define

begin_comment
comment|/* If set, this was imported in a using declaration.    This is not to confuse with being used somewhere, which    is not important for this node.  */
end_comment

begin_define
define|#
directive|define
name|OVL_USED
parameter_list|(
name|NODE
parameter_list|)
value|TREE_USED (NODE)
end_define

begin_decl_stmt
name|struct
name|tree_overload
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|tree
name|function
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Returns true iff NODE is a BASELINK.  */
end_comment

begin_define
define|#
directive|define
name|BASELINK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == BASELINK)
end_define

begin_comment
comment|/* The BINFO indicating the base from which the BASELINK_FUNCTIONS came.  */
end_comment

begin_define
define|#
directive|define
name|BASELINK_BINFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct tree_baselink*) BASELINK_CHECK (NODE))->binfo)
end_define

begin_comment
comment|/* The functions referred to by the BASELINK; either a FUNCTION_DECL,    a TEMPLATE_DECL, an OVERLOAD, or a TEMPLATE_ID_EXPR.  */
end_comment

begin_define
define|#
directive|define
name|BASELINK_FUNCTIONS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct tree_baselink*) BASELINK_CHECK (NODE))->functions)
end_define

begin_comment
comment|/* The BINFO in which the search for the functions indicated by this baselink    began.  This base is used to determine the accessibility of functions    selected by overload resolution.  */
end_comment

begin_define
define|#
directive|define
name|BASELINK_ACCESS_BINFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct tree_baselink*) BASELINK_CHECK (NODE))->access_binfo)
end_define

begin_comment
comment|/* For a type-conversion operator, the BASELINK_OPTYPE indicates the type    to which the conversion should occur.  This value is important if    the BASELINK_FUNCTIONS include a template conversion operator --    the BASELINK_OPTYPE can be used to determine what type the user    requested.  */
end_comment

begin_define
define|#
directive|define
name|BASELINK_OPTYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CHAIN (BASELINK_CHECK (NODE)))
end_define

begin_comment
comment|/* Non-zero if this baselink was from a qualified lookup.  */
end_comment

begin_define
define|#
directive|define
name|BASELINK_QUALIFIED_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (BASELINK_CHECK (NODE))
end_define

begin_decl_stmt
name|struct
name|tree_baselink
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|tree
name|binfo
decl_stmt|;
name|tree
name|functions
decl_stmt|;
name|tree
name|access_binfo
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The different kinds of ids that we encounter.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cp_id_kind
block|{
comment|/* Not an id at all.  */
name|CP_ID_KIND_NONE
block|,
comment|/* An unqualified-id that is not a template-id.  */
name|CP_ID_KIND_UNQUALIFIED
block|,
comment|/* An unqualified-id that is a dependent name.  */
name|CP_ID_KIND_UNQUALIFIED_DEPENDENT
block|,
comment|/* An unqualified template-id.  */
name|CP_ID_KIND_TEMPLATE_ID
block|,
comment|/* A qualified-id.  */
name|CP_ID_KIND_QUALIFIED
block|}
name|cp_id_kind
typedef|;
end_typedef

begin_comment
comment|/* Macros for access to language-specific slots in an identifier.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_NAMESPACE_BINDINGS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_IDENTIFIER_CAST (NODE)->namespace_bindings)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_IDENTIFIER_CAST (NODE)->class_template_info)
end_define

begin_comment
comment|/* The IDENTIFIER_BINDING is the innermost cxx_binding for the     identifier.  It's PREVIOUS is the next outermost binding.  Each     VALUE field is a DECL for the associated declaration.  Thus,     name lookup consists simply of pulling off the node at the front     of the list (modulo oddities for looking up the names of types,     and such.)  You can use SCOPE field to determine the scope     that bound the name.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_BINDING
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_IDENTIFIER_CAST (NODE)->bindings)
end_define

begin_comment
comment|/* TREE_TYPE only indicates on local and class scope the current    type. For namespace scope, the presence of a type in any namespace    is indicated with global_type_node, and the real type behind must    be found through lookup.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|identifier_type_value (NODE)
end_define

begin_define
define|#
directive|define
name|REAL_IDENTIFIER_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_TYPE (NODE)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|,
name|TYPE
parameter_list|)
value|(TREE_TYPE (NODE) = (TYPE))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_HAS_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_TYPE_VALUE (NODE) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_IDENTIFIER_CAST (NODE)->label_value)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|IDENTIFIER_LABEL_VALUE (NODE) = (VALUE)
end_define

begin_comment
comment|/* Nonzero if this identifier is used as a virtual function name somewhere    (optimizes searches).  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1 (NODE)
end_define

begin_comment
comment|/* Nonzero if this identifier is the prefix for a mangled C++ operator    name.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_OPNAME_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_2 (NODE)
end_define

begin_comment
comment|/* Nonzero if this identifier is the name of a type-conversion    operator.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_TYPENAME_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_4 (NODE)
end_define

begin_comment
comment|/* Nonzero if this identifier is the name of a constructor or    destructor.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_CTOR_OR_DTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_3 (NODE)
end_define

begin_comment
comment|/* True iff NAME is the DECL_ASSEMBLER_NAME for an entity with vague    linkage which the prelinker has assigned to this translation    unit.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_REPO_CHOSEN
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(TREE_LANG_FLAG_6 (NAME))
end_define

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is read-only.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_READONLY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (TYPE)->fields_readonly)
end_define

begin_comment
comment|/* The tokens stored in the default argument.  */
end_comment

begin_define
define|#
directive|define
name|DEFARG_TOKENS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct tree_default_arg *)DEFAULT_ARG_CHECK (NODE))->tokens)
end_define

begin_define
define|#
directive|define
name|DEFARG_INSTANTIATIONS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct tree_default_arg *)DEFAULT_ARG_CHECK (NODE))->instantiations)
end_define

begin_decl_stmt
name|struct
name|tree_default_arg
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|struct
name|cp_token_cache
modifier|*
name|tokens
decl_stmt|;
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|instantiations
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_enum
enum|enum
name|cp_tree_node_structure_enum
block|{
name|TS_CP_GENERIC
block|,
name|TS_CP_IDENTIFIER
block|,
name|TS_CP_TPI
block|,
name|TS_CP_TINST_LEVEL
block|,
name|TS_CP_PTRMEM
block|,
name|TS_CP_BINDING
block|,
name|TS_CP_OVERLOAD
block|,
name|TS_CP_BASELINK
block|,
name|TS_CP_WRAPPER
block|,
name|TS_CP_DEFAULT_ARG
block|,
name|LAST_TS_CP_ENUM
block|}
enum|;
end_enum

begin_comment
comment|/* The resulting tree type.  */
end_comment

begin_decl_stmt
name|union
name|lang_tree_node
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"cp_tree_node_structure (&%h)"
argument_list|)
operator|,
name|chain_next
argument_list|(
literal|"(union lang_tree_node *)TREE_CHAIN (&%h.generic)"
argument_list|)
operator|)
argument_list|)
block|{
name|union
name|tree_node
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CP_GENERIC"
argument_list|)
operator|,
name|desc
argument_list|(
literal|"tree_node_structure (&%h)"
argument_list|)
operator|)
argument_list|)
name|generic
decl_stmt|;
name|struct
name|template_parm_index_s
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CP_TPI"
argument_list|)
operator|)
argument_list|)
name|tpi
decl_stmt|;
name|struct
name|tinst_level_s
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CP_TINST_LEVEL"
argument_list|)
operator|)
argument_list|)
name|tinst_level
decl_stmt|;
name|struct
name|ptrmem_cst
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CP_PTRMEM"
argument_list|)
operator|)
argument_list|)
name|ptrmem
decl_stmt|;
name|struct
name|tree_overload
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CP_OVERLOAD"
argument_list|)
operator|)
argument_list|)
name|overload
decl_stmt|;
name|struct
name|tree_baselink
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CP_BASELINK"
argument_list|)
operator|)
argument_list|)
name|baselink
decl_stmt|;
name|struct
name|tree_default_arg
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CP_DEFAULT_ARG"
argument_list|)
operator|)
argument_list|)
name|default_arg
decl_stmt|;
name|struct
name|lang_identifier
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CP_IDENTIFIER"
argument_list|)
operator|)
argument_list|)
name|identifier
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_enum
enum|enum
name|cp_tree_index
block|{
name|CPTI_JAVA_BYTE_TYPE
block|,
name|CPTI_JAVA_SHORT_TYPE
block|,
name|CPTI_JAVA_INT_TYPE
block|,
name|CPTI_JAVA_LONG_TYPE
block|,
name|CPTI_JAVA_FLOAT_TYPE
block|,
name|CPTI_JAVA_DOUBLE_TYPE
block|,
name|CPTI_JAVA_CHAR_TYPE
block|,
name|CPTI_JAVA_BOOLEAN_TYPE
block|,
name|CPTI_WCHAR_DECL
block|,
name|CPTI_VTABLE_ENTRY_TYPE
block|,
name|CPTI_DELTA_TYPE
block|,
name|CPTI_VTABLE_INDEX_TYPE
block|,
name|CPTI_CLEANUP_TYPE
block|,
name|CPTI_VTT_PARM_TYPE
block|,
name|CPTI_CLASS_TYPE
block|,
name|CPTI_UNKNOWN_TYPE
block|,
name|CPTI_VTBL_TYPE
block|,
name|CPTI_VTBL_PTR_TYPE
block|,
name|CPTI_STD
block|,
name|CPTI_ABI
block|,
name|CPTI_CONST_TYPE_INFO_TYPE
block|,
name|CPTI_TYPE_INFO_PTR_TYPE
block|,
name|CPTI_ABORT_FNDECL
block|,
name|CPTI_GLOBAL_DELETE_FNDECL
block|,
name|CPTI_AGGR_TAG
block|,
name|CPTI_CTOR_IDENTIFIER
block|,
name|CPTI_COMPLETE_CTOR_IDENTIFIER
block|,
name|CPTI_BASE_CTOR_IDENTIFIER
block|,
name|CPTI_DTOR_IDENTIFIER
block|,
name|CPTI_COMPLETE_DTOR_IDENTIFIER
block|,
name|CPTI_BASE_DTOR_IDENTIFIER
block|,
name|CPTI_DELETING_DTOR_IDENTIFIER
block|,
name|CPTI_DELTA_IDENTIFIER
block|,
name|CPTI_IN_CHARGE_IDENTIFIER
block|,
name|CPTI_VTT_PARM_IDENTIFIER
block|,
name|CPTI_NELTS_IDENTIFIER
block|,
name|CPTI_THIS_IDENTIFIER
block|,
name|CPTI_PFN_IDENTIFIER
block|,
name|CPTI_VPTR_IDENTIFIER
block|,
name|CPTI_STD_IDENTIFIER
block|,
name|CPTI_LANG_NAME_C
block|,
name|CPTI_LANG_NAME_CPLUSPLUS
block|,
name|CPTI_LANG_NAME_JAVA
block|,
name|CPTI_EMPTY_EXCEPT_SPEC
block|,
name|CPTI_JCLASS
block|,
name|CPTI_TERMINATE
block|,
name|CPTI_CALL_UNEXPECTED
block|,
name|CPTI_ATEXIT
block|,
name|CPTI_DSO_HANDLE
block|,
name|CPTI_DCAST
block|,
name|CPTI_KEYED_CLASSES
block|,
name|CPTI_MAX
block|}
enum|;
end_enum

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|cp_global_trees
index|[
name|CPTI_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|java_byte_type_node
value|cp_global_trees[CPTI_JAVA_BYTE_TYPE]
end_define

begin_define
define|#
directive|define
name|java_short_type_node
value|cp_global_trees[CPTI_JAVA_SHORT_TYPE]
end_define

begin_define
define|#
directive|define
name|java_int_type_node
value|cp_global_trees[CPTI_JAVA_INT_TYPE]
end_define

begin_define
define|#
directive|define
name|java_long_type_node
value|cp_global_trees[CPTI_JAVA_LONG_TYPE]
end_define

begin_define
define|#
directive|define
name|java_float_type_node
value|cp_global_trees[CPTI_JAVA_FLOAT_TYPE]
end_define

begin_define
define|#
directive|define
name|java_double_type_node
value|cp_global_trees[CPTI_JAVA_DOUBLE_TYPE]
end_define

begin_define
define|#
directive|define
name|java_char_type_node
value|cp_global_trees[CPTI_JAVA_CHAR_TYPE]
end_define

begin_define
define|#
directive|define
name|java_boolean_type_node
value|cp_global_trees[CPTI_JAVA_BOOLEAN_TYPE]
end_define

begin_define
define|#
directive|define
name|wchar_decl_node
value|cp_global_trees[CPTI_WCHAR_DECL]
end_define

begin_define
define|#
directive|define
name|vtable_entry_type
value|cp_global_trees[CPTI_VTABLE_ENTRY_TYPE]
end_define

begin_comment
comment|/* The type used to represent an offset by which to adjust the `this'    pointer in pointer-to-member types.  */
end_comment

begin_define
define|#
directive|define
name|delta_type_node
value|cp_global_trees[CPTI_DELTA_TYPE]
end_define

begin_comment
comment|/* The type used to represent an index into the vtable.  */
end_comment

begin_define
define|#
directive|define
name|vtable_index_type
value|cp_global_trees[CPTI_VTABLE_INDEX_TYPE]
end_define

begin_define
define|#
directive|define
name|class_type_node
value|cp_global_trees[CPTI_CLASS_TYPE]
end_define

begin_define
define|#
directive|define
name|unknown_type_node
value|cp_global_trees[CPTI_UNKNOWN_TYPE]
end_define

begin_define
define|#
directive|define
name|vtbl_type_node
value|cp_global_trees[CPTI_VTBL_TYPE]
end_define

begin_define
define|#
directive|define
name|vtbl_ptr_type_node
value|cp_global_trees[CPTI_VTBL_PTR_TYPE]
end_define

begin_define
define|#
directive|define
name|std_node
value|cp_global_trees[CPTI_STD]
end_define

begin_define
define|#
directive|define
name|abi_node
value|cp_global_trees[CPTI_ABI]
end_define

begin_define
define|#
directive|define
name|const_type_info_type_node
value|cp_global_trees[CPTI_CONST_TYPE_INFO_TYPE]
end_define

begin_define
define|#
directive|define
name|type_info_ptr_type
value|cp_global_trees[CPTI_TYPE_INFO_PTR_TYPE]
end_define

begin_define
define|#
directive|define
name|abort_fndecl
value|cp_global_trees[CPTI_ABORT_FNDECL]
end_define

begin_define
define|#
directive|define
name|global_delete_fndecl
value|cp_global_trees[CPTI_GLOBAL_DELETE_FNDECL]
end_define

begin_define
define|#
directive|define
name|current_aggr
value|cp_global_trees[CPTI_AGGR_TAG]
end_define

begin_comment
comment|/* We cache these tree nodes so as to call get_identifier less    frequently.  */
end_comment

begin_comment
comment|/* The name of a constructor that takes an in-charge parameter to    decide whether or not to construct virtual base classes.  */
end_comment

begin_define
define|#
directive|define
name|ctor_identifier
value|cp_global_trees[CPTI_CTOR_IDENTIFIER]
end_define

begin_comment
comment|/* The name of a constructor that constructs virtual base classes.  */
end_comment

begin_define
define|#
directive|define
name|complete_ctor_identifier
value|cp_global_trees[CPTI_COMPLETE_CTOR_IDENTIFIER]
end_define

begin_comment
comment|/* The name of a constructor that does not construct virtual base classes.  */
end_comment

begin_define
define|#
directive|define
name|base_ctor_identifier
value|cp_global_trees[CPTI_BASE_CTOR_IDENTIFIER]
end_define

begin_comment
comment|/* The name of a destructor that takes an in-charge parameter to    decide whether or not to destroy virtual base classes and whether    or not to delete the object.  */
end_comment

begin_define
define|#
directive|define
name|dtor_identifier
value|cp_global_trees[CPTI_DTOR_IDENTIFIER]
end_define

begin_comment
comment|/* The name of a destructor that destroys virtual base classes.  */
end_comment

begin_define
define|#
directive|define
name|complete_dtor_identifier
value|cp_global_trees[CPTI_COMPLETE_DTOR_IDENTIFIER]
end_define

begin_comment
comment|/* The name of a destructor that does not destroy virtual base    classes.  */
end_comment

begin_define
define|#
directive|define
name|base_dtor_identifier
value|cp_global_trees[CPTI_BASE_DTOR_IDENTIFIER]
end_define

begin_comment
comment|/* The name of a destructor that destroys virtual base classes, and    then deletes the entire object.  */
end_comment

begin_define
define|#
directive|define
name|deleting_dtor_identifier
value|cp_global_trees[CPTI_DELETING_DTOR_IDENTIFIER]
end_define

begin_define
define|#
directive|define
name|delta_identifier
value|cp_global_trees[CPTI_DELTA_IDENTIFIER]
end_define

begin_define
define|#
directive|define
name|in_charge_identifier
value|cp_global_trees[CPTI_IN_CHARGE_IDENTIFIER]
end_define

begin_comment
comment|/* The name of the parameter that contains a pointer to the VTT to use    for this subobject constructor or destructor.  */
end_comment

begin_define
define|#
directive|define
name|vtt_parm_identifier
value|cp_global_trees[CPTI_VTT_PARM_IDENTIFIER]
end_define

begin_define
define|#
directive|define
name|nelts_identifier
value|cp_global_trees[CPTI_NELTS_IDENTIFIER]
end_define

begin_define
define|#
directive|define
name|this_identifier
value|cp_global_trees[CPTI_THIS_IDENTIFIER]
end_define

begin_define
define|#
directive|define
name|pfn_identifier
value|cp_global_trees[CPTI_PFN_IDENTIFIER]
end_define

begin_define
define|#
directive|define
name|vptr_identifier
value|cp_global_trees[CPTI_VPTR_IDENTIFIER]
end_define

begin_comment
comment|/* The name of the std namespace.  */
end_comment

begin_define
define|#
directive|define
name|std_identifier
value|cp_global_trees[CPTI_STD_IDENTIFIER]
end_define

begin_define
define|#
directive|define
name|lang_name_c
value|cp_global_trees[CPTI_LANG_NAME_C]
end_define

begin_define
define|#
directive|define
name|lang_name_cplusplus
value|cp_global_trees[CPTI_LANG_NAME_CPLUSPLUS]
end_define

begin_define
define|#
directive|define
name|lang_name_java
value|cp_global_trees[CPTI_LANG_NAME_JAVA]
end_define

begin_comment
comment|/* Exception specifier used for throw().  */
end_comment

begin_define
define|#
directive|define
name|empty_except_spec
value|cp_global_trees[CPTI_EMPTY_EXCEPT_SPEC]
end_define

begin_comment
comment|/* If non-NULL, a POINTER_TYPE equivalent to (java::lang::Class*).  */
end_comment

begin_define
define|#
directive|define
name|jclass_node
value|cp_global_trees[CPTI_JCLASS]
end_define

begin_comment
comment|/* The declaration for `std::terminate'.  */
end_comment

begin_define
define|#
directive|define
name|terminate_node
value|cp_global_trees[CPTI_TERMINATE]
end_define

begin_comment
comment|/* The declaration for "__cxa_call_unexpected".  */
end_comment

begin_define
define|#
directive|define
name|call_unexpected_node
value|cp_global_trees[CPTI_CALL_UNEXPECTED]
end_define

begin_comment
comment|/* A pointer to `std::atexit'.  */
end_comment

begin_define
define|#
directive|define
name|atexit_node
value|cp_global_trees[CPTI_ATEXIT]
end_define

begin_comment
comment|/* A pointer to `__dso_handle'.  */
end_comment

begin_define
define|#
directive|define
name|dso_handle_node
value|cp_global_trees[CPTI_DSO_HANDLE]
end_define

begin_comment
comment|/* The declaration of the dynamic_cast runtime.  */
end_comment

begin_define
define|#
directive|define
name|dynamic_cast_node
value|cp_global_trees[CPTI_DCAST]
end_define

begin_comment
comment|/* The type of a destructor.  */
end_comment

begin_define
define|#
directive|define
name|cleanup_type
value|cp_global_trees[CPTI_CLEANUP_TYPE]
end_define

begin_comment
comment|/* The type of the vtt parameter passed to subobject constructors and    destructors.  */
end_comment

begin_define
define|#
directive|define
name|vtt_parm_type
value|cp_global_trees[CPTI_VTT_PARM_TYPE]
end_define

begin_comment
comment|/* A TREE_LIST of the dynamic classes whose vtables may have to be    emitted in this translation unit.  */
end_comment

begin_define
define|#
directive|define
name|keyed_classes
value|cp_global_trees[CPTI_KEYED_CLASSES]
end_define

begin_comment
comment|/* Node to indicate default access. This must be distinct from the    access nodes in tree.h.  */
end_comment

begin_define
define|#
directive|define
name|access_default_node
value|null_node
end_define

begin_comment
comment|/* Global state.  */
end_comment

begin_decl_stmt
name|struct
name|saved_scope
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|VEC
argument_list|(
name|cxx_saved_binding
argument_list|,
name|gc
argument_list|)
operator|*
name|old_bindings
expr_stmt|;
name|tree
name|old_namespace
decl_stmt|;
name|tree
name|decl_ns_list
decl_stmt|;
name|tree
name|class_name
decl_stmt|;
name|tree
name|class_type
decl_stmt|;
name|tree
name|access_specifier
decl_stmt|;
name|tree
name|function_decl
decl_stmt|;
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|lang_base
expr_stmt|;
name|tree
name|lang_name
decl_stmt|;
name|tree
name|template_parms
decl_stmt|;
name|struct
name|cp_binding_level
modifier|*
name|x_previous_class_level
decl_stmt|;
name|tree
name|x_saved_tree
decl_stmt|;
name|HOST_WIDE_INT
name|x_processing_template_decl
decl_stmt|;
name|int
name|x_processing_specialization
decl_stmt|;
name|bool
name|x_processing_explicit_instantiation
decl_stmt|;
name|int
name|need_pop_function_context
decl_stmt|;
name|bool
name|skip_evaluation
decl_stmt|;
name|struct
name|stmt_tree_s
name|x_stmt_tree
decl_stmt|;
name|struct
name|cp_binding_level
modifier|*
name|class_bindings
decl_stmt|;
name|struct
name|cp_binding_level
modifier|*
name|bindings
decl_stmt|;
name|struct
name|saved_scope
modifier|*
name|prev
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The current open namespace.  */
end_comment

begin_define
define|#
directive|define
name|current_namespace
value|scope_chain->old_namespace
end_define

begin_comment
comment|/* The stack for namespaces of current declarations.  */
end_comment

begin_define
define|#
directive|define
name|decl_namespace_list
value|scope_chain->decl_ns_list
end_define

begin_comment
comment|/* IDENTIFIER_NODE: name of current class */
end_comment

begin_define
define|#
directive|define
name|current_class_name
value|scope_chain->class_name
end_define

begin_comment
comment|/* _TYPE: the type of the current class */
end_comment

begin_define
define|#
directive|define
name|current_class_type
value|scope_chain->class_type
end_define

begin_comment
comment|/* When parsing a class definition, the access specifier most recently    given by the user, or, if no access specifier was given, the    default value appropriate for the kind of class (i.e., struct,    class, or union).  */
end_comment

begin_define
define|#
directive|define
name|current_access_specifier
value|scope_chain->access_specifier
end_define

begin_comment
comment|/* Pointer to the top of the language name stack.  */
end_comment

begin_define
define|#
directive|define
name|current_lang_base
value|scope_chain->lang_base
end_define

begin_define
define|#
directive|define
name|current_lang_name
value|scope_chain->lang_name
end_define

begin_comment
comment|/* Parsing a function declarator leaves a list of parameter names    or a chain or parameter decls here.  */
end_comment

begin_define
define|#
directive|define
name|current_template_parms
value|scope_chain->template_parms
end_define

begin_define
define|#
directive|define
name|processing_template_decl
value|scope_chain->x_processing_template_decl
end_define

begin_define
define|#
directive|define
name|processing_specialization
value|scope_chain->x_processing_specialization
end_define

begin_define
define|#
directive|define
name|processing_explicit_instantiation
value|scope_chain->x_processing_explicit_instantiation
end_define

begin_comment
comment|/* The cached class binding level, from the most recently exited    class, or NULL if none.  */
end_comment

begin_define
define|#
directive|define
name|previous_class_level
value|scope_chain->x_previous_class_level
end_define

begin_comment
comment|/* A list of private types mentioned, for deferred access checking.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|struct
name|saved_scope
modifier|*
name|scope_chain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cxx_int_tree_map
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|unsigned
name|int
name|uid
decl_stmt|;
name|tree
name|to
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|unsigned
name|int
name|cxx_int_tree_map_hash
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cxx_int_tree_map_eq
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Global state pertinent to the current function.  */
end_comment

begin_decl_stmt
name|struct
name|language_function
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|c_language_function
name|base
decl_stmt|;
name|tree
name|x_cdtor_label
decl_stmt|;
name|tree
name|x_current_class_ptr
decl_stmt|;
name|tree
name|x_current_class_ref
decl_stmt|;
name|tree
name|x_eh_spec_block
decl_stmt|;
name|tree
name|x_in_charge_parm
decl_stmt|;
name|tree
name|x_vtt_parm
decl_stmt|;
name|tree
name|x_return_value
decl_stmt|;
name|int
name|returns_value
decl_stmt|;
name|int
name|returns_null
decl_stmt|;
name|int
name|returns_abnormally
decl_stmt|;
name|int
name|in_function_try_handler
decl_stmt|;
name|int
name|in_base_initializer
decl_stmt|;
comment|/* True if this function can throw an exception.  */
name|BOOL_BITFIELD
name|can_throw
range|:
literal|1
decl_stmt|;
name|htab_t
name|GTY
argument_list|(
operator|(
name|param_is
argument_list|(
expr|struct
name|named_label_entry
argument_list|)
operator|)
argument_list|)
name|x_named_labels
decl_stmt|;
name|struct
name|cp_binding_level
modifier|*
name|bindings
decl_stmt|;
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|x_local_names
expr_stmt|;
name|htab_t
name|GTY
argument_list|(
operator|(
name|param_is
argument_list|(
expr|struct
name|cxx_int_tree_map
argument_list|)
operator|)
argument_list|)
name|extern_decl_map
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The current C++-specific per-function global variables.  */
end_comment

begin_define
define|#
directive|define
name|cp_function_chain
value|(cfun->language)
end_define

begin_comment
comment|/* In a constructor destructor, the point at which all derived class    destroying/construction has been has been done. Ie. just before a    constructor returns, or before any base class destroying will be done    in a destructor.  */
end_comment

begin_define
define|#
directive|define
name|cdtor_label
value|cp_function_chain->x_cdtor_label
end_define

begin_comment
comment|/* When we're processing a member function, current_class_ptr is the    PARM_DECL for the `this' pointer.  The current_class_ref is an    expression for `*this'.  */
end_comment

begin_define
define|#
directive|define
name|current_class_ptr
define|\
value|(cfun ? cp_function_chain->x_current_class_ptr : NULL_TREE)
end_define

begin_define
define|#
directive|define
name|current_class_ref
define|\
value|(cfun ? cp_function_chain->x_current_class_ref : NULL_TREE)
end_define

begin_comment
comment|/* The EH_SPEC_BLOCK for the exception-specifiers for the current    function, if any.  */
end_comment

begin_define
define|#
directive|define
name|current_eh_spec_block
value|cp_function_chain->x_eh_spec_block
end_define

begin_comment
comment|/* The `__in_chrg' parameter for the current function.  Only used for    constructors and destructors.  */
end_comment

begin_define
define|#
directive|define
name|current_in_charge_parm
value|cp_function_chain->x_in_charge_parm
end_define

begin_comment
comment|/* The `__vtt_parm' parameter for the current function.  Only used for    constructors and destructors.  */
end_comment

begin_define
define|#
directive|define
name|current_vtt_parm
value|cp_function_chain->x_vtt_parm
end_define

begin_comment
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a return statement that specifies a return value is seen.  */
end_comment

begin_define
define|#
directive|define
name|current_function_returns_value
value|cp_function_chain->returns_value
end_define

begin_comment
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a return statement with no argument is seen.  */
end_comment

begin_define
define|#
directive|define
name|current_function_returns_null
value|cp_function_chain->returns_null
end_define

begin_comment
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a call to a noreturn function is seen.  */
end_comment

begin_define
define|#
directive|define
name|current_function_returns_abnormally
define|\
value|cp_function_chain->returns_abnormally
end_define

begin_comment
comment|/* Nonzero if we are processing a base initializer.  Zero elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|in_base_initializer
value|cp_function_chain->in_base_initializer
end_define

begin_define
define|#
directive|define
name|in_function_try_handler
value|cp_function_chain->in_function_try_handler
end_define

begin_comment
comment|/* Expression always returned from function, or error_mark_node    otherwise, for use by the automatic named return value optimization.  */
end_comment

begin_define
define|#
directive|define
name|current_function_return_value
define|\
value|(cp_function_chain->x_return_value)
end_define

begin_comment
comment|/* True if NAME is the IDENTIFIER_NODE for an overloaded "operator    new" or "operator delete".  */
end_comment

begin_define
define|#
directive|define
name|NEW_DELETE_OPNAME_P
parameter_list|(
name|NAME
parameter_list|)
define|\
value|((NAME) == ansi_opname (NEW_EXPR)		\    || (NAME) == ansi_opname (VEC_NEW_EXPR)	\    || (NAME) == ansi_opname (DELETE_EXPR)	\    || (NAME) == ansi_opname (VEC_DELETE_EXPR))
end_define

begin_define
define|#
directive|define
name|ansi_opname
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(operator_name_info[(int) (CODE)].identifier)
end_define

begin_define
define|#
directive|define
name|ansi_assopname
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(assignment_operator_name_info[(int) (CODE)].identifier)
end_define

begin_comment
comment|/* True if NODE is an erroneous expression.  */
end_comment

begin_define
define|#
directive|define
name|error_operand_p
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((NODE) == error_mark_node					\    || ((NODE)&& TREE_TYPE ((NODE)) == error_mark_node))
end_define

begin_escape
end_escape

begin_comment
comment|/* C++ language-specific tree codes.  */
end_comment

begin_define
define|#
directive|define
name|DEFTREECODE
parameter_list|(
name|SYM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|LENGTH
parameter_list|)
value|SYM,
end_define

begin_enum
enum|enum
name|cplus_tree_code
block|{
name|CP_DUMMY_TREE_CODE
init|=
name|LAST_C_TREE_CODE
block|,
include|#
directive|include
file|"cp-tree.def"
name|LAST_CPLUS_TREE_CODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* TRUE if a tree code represents a statement.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|statement_code_p
index|[
name|MAX_TREE_CODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STATEMENT_CODE_P
parameter_list|(
name|CODE
parameter_list|)
value|statement_code_p[(int) (CODE)]
end_define

begin_enum
enum|enum
name|languages
block|{
name|lang_c
block|,
name|lang_cplusplus
block|,
name|lang_java
block|}
enum|;
end_enum

begin_comment
comment|/* Macros to make error reporting functions' lives easier.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_IDENTIFIER
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_NAME (TYPE_NAME (NODE)))
end_define

begin_define
define|#
directive|define
name|TYPE_LINKAGE_IDENTIFIER
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_IDENTIFIER (TYPE_MAIN_VARIANT (NODE)))
end_define

begin_define
define|#
directive|define
name|TYPE_NAME_STRING
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_POINTER (TYPE_IDENTIFIER (NODE)))
end_define

begin_define
define|#
directive|define
name|TYPE_NAME_LENGTH
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_LENGTH (TYPE_IDENTIFIER (NODE)))
end_define

begin_comment
comment|/* Nonzero if NODE has no name for linkage purposes.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ANONYMOUS_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TAGGED_TYPE_P (NODE)&& ANON_AGGRNAME_P (TYPE_LINKAGE_IDENTIFIER (NODE)))
end_define

begin_comment
comment|/* The _DECL for this _TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_MAIN_DECL
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_STUB_DECL (TYPE_MAIN_VARIANT (NODE)))
end_define

begin_comment
comment|/* Nonzero if T is a class (or struct or union) type.  Also nonzero    for template type parameters, typename types, and instantiated    template template parameters.  Despite its name,    this macro has nothing to do with the definition of aggregate given    in the standard.  Think of this macro as MAYBE_CLASS_TYPE_P.  Keep    these checks in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|IS_AGGR_TYPE
parameter_list|(
name|T
parameter_list|)
define|\
value|(TREE_CODE (T) == TEMPLATE_TYPE_PARM			\    || TREE_CODE (T) == TYPENAME_TYPE			\    || TREE_CODE (T) == TYPEOF_TYPE			\    || TREE_CODE (T) == BOUND_TEMPLATE_TEMPLATE_PARM	\    || TYPE_LANG_FLAG_5 (T))
end_define

begin_comment
comment|/* Set IS_AGGR_TYPE for T to VAL.  T must be a class, struct, or    union type.  */
end_comment

begin_define
define|#
directive|define
name|SET_IS_AGGR_TYPE
parameter_list|(
name|T
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(TYPE_LANG_FLAG_5 (T) = (VAL))
end_define

begin_comment
comment|/* Nonzero if T is a class type.  Zero for template type parameters,    typename types, and so forth.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_TYPE_P
parameter_list|(
name|T
parameter_list|)
define|\
value|(IS_AGGR_TYPE_CODE (TREE_CODE (T))&& TYPE_LANG_FLAG_5 (T))
end_define

begin_comment
comment|/* Keep these checks in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|IS_AGGR_TYPE_CODE
parameter_list|(
name|T
parameter_list|)
define|\
value|((T) == RECORD_TYPE || (T) == UNION_TYPE)
end_define

begin_define
define|#
directive|define
name|TAGGED_TYPE_P
parameter_list|(
name|T
parameter_list|)
define|\
value|(CLASS_TYPE_P (T) || TREE_CODE (T) == ENUMERAL_TYPE)
end_define

begin_define
define|#
directive|define
name|IS_OVERLOAD_TYPE
parameter_list|(
name|T
parameter_list|)
value|TAGGED_TYPE_P (T)
end_define

begin_comment
comment|/* True if this a "Java" type, defined in 'extern "Java"'.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_FOR_JAVA
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_LANG_FLAG_3 (NODE)
end_define

begin_comment
comment|/* True if this type is dependent.  This predicate is only valid if    TYPE_DEPENDENT_P_VALID is true.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_DEPENDENT_P
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_LANG_FLAG_0 (NODE)
end_define

begin_comment
comment|/* True if dependent_type_p has been called for this type, with the    result that TYPE_DEPENDENT_P is valid.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_DEPENDENT_P_VALID
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_LANG_FLAG_6(NODE)
end_define

begin_comment
comment|/* Nonzero if this type is const-qualified.  */
end_comment

begin_define
define|#
directive|define
name|CP_TYPE_CONST_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((cp_type_quals (NODE)& TYPE_QUAL_CONST) != 0)
end_define

begin_comment
comment|/* Nonzero if this type is volatile-qualified.  */
end_comment

begin_define
define|#
directive|define
name|CP_TYPE_VOLATILE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((cp_type_quals (NODE)& TYPE_QUAL_VOLATILE) != 0)
end_define

begin_comment
comment|/* Nonzero if this type is restrict-qualified.  */
end_comment

begin_define
define|#
directive|define
name|CP_TYPE_RESTRICT_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((cp_type_quals (NODE)& TYPE_QUAL_RESTRICT) != 0)
end_define

begin_comment
comment|/* Nonzero if this type is const-qualified, but not    volatile-qualified.  Other qualifiers are ignored.  This macro is    used to test whether or not it is OK to bind an rvalue to a    reference.  */
end_comment

begin_define
define|#
directive|define
name|CP_TYPE_CONST_NON_VOLATILE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((cp_type_quals (NODE)& (TYPE_QUAL_CONST | TYPE_QUAL_VOLATILE))	\    == TYPE_QUAL_CONST)
end_define

begin_define
define|#
directive|define
name|FUNCTION_ARG_CHAIN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_CHAIN (TYPE_ARG_TYPES (TREE_TYPE (NODE)))
end_define

begin_comment
comment|/* Given a FUNCTION_DECL, returns the first TREE_LIST out of TYPE_ARG_TYPES    which refers to a user-written parameter.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_FIRST_USER_PARMTYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|skip_artificial_parms_for ((NODE), TYPE_ARG_TYPES (TREE_TYPE (NODE)))
end_define

begin_comment
comment|/* Similarly, but for DECL_ARGUMENTS.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_FIRST_USER_PARM
parameter_list|(
name|NODE
parameter_list|)
define|\
value|skip_artificial_parms_for ((NODE), DECL_ARGUMENTS (NODE))
end_define

begin_define
define|#
directive|define
name|PROMOTES_TO_AGGR_TYPE
parameter_list|(
name|NODE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|(((CODE) == TREE_CODE (NODE)			\&& IS_AGGR_TYPE (TREE_TYPE (NODE)))		\    || IS_AGGR_TYPE (NODE))
end_define

begin_comment
comment|/* Nonzero iff TYPE is derived from PARENT. Ignores accessibility and    ambiguity issues.  */
end_comment

begin_define
define|#
directive|define
name|DERIVED_FROM_P
parameter_list|(
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(lookup_base ((TYPE), (PARENT), ba_any, NULL) != NULL_TREE)
end_define

begin_comment
comment|/* Nonzero iff TYPE is uniquely derived from PARENT. Ignores    accessibility.  */
end_comment

begin_define
define|#
directive|define
name|UNIQUELY_DERIVED_FROM_P
parameter_list|(
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(lookup_base ((TYPE), (PARENT), ba_unique | ba_quiet, NULL) != NULL_TREE)
end_define

begin_comment
comment|/* Nonzero iff TYPE is publicly& uniquely derived from PARENT.  */
end_comment

begin_define
define|#
directive|define
name|PUBLICLY_UNIQUELY_DERIVED_P
parameter_list|(
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(lookup_base ((TYPE), (PARENT), ba_ignore_scope | ba_check | ba_quiet, \ 		NULL) != NULL_TREE)
end_define

begin_comment
comment|/* Gives the visibility specification for a class type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VISIBILITY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|DECL_VISIBILITY (TYPE_NAME (TYPE))
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_VISIBILITY_SPECIFIED
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|DECL_VISIBILITY_SPECIFIED (TYPE_NAME (TYPE))
end_define

begin_typedef
typedef|typedef
name|struct
name|tree_pair_s
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|tree
name|purpose
block|;
name|tree
name|value
block|; }
end_typedef

begin_expr_stmt
name|tree_pair_s
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|tree_pair_s
modifier|*
name|tree_pair_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_O
argument_list|(
name|tree_pair_s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_O
argument_list|(
name|tree_pair_s
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* This is a few header flags for 'struct lang_type'.  Actually,    all but the first are used only for lang_type_class; they    are put in this structure to save space.  */
end_comment

begin_decl_stmt
name|struct
name|lang_type_header
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|BOOL_BITFIELD
name|is_lang_type_class
range|:
literal|1
decl_stmt|;
name|BOOL_BITFIELD
name|has_type_conversion
range|:
literal|1
decl_stmt|;
name|BOOL_BITFIELD
name|has_init_ref
range|:
literal|1
decl_stmt|;
name|BOOL_BITFIELD
name|has_default_ctor
range|:
literal|1
decl_stmt|;
name|BOOL_BITFIELD
name|const_needs_init
range|:
literal|1
decl_stmt|;
name|BOOL_BITFIELD
name|ref_needs_init
range|:
literal|1
decl_stmt|;
name|BOOL_BITFIELD
name|has_const_assign_ref
range|:
literal|1
decl_stmt|;
name|BOOL_BITFIELD
name|spare
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* This structure provides additional information above and beyond    what is provide in the ordinary tree_type.  In the past, we used it    for the types of class types, template parameters types, typename    types, and so forth.  However, there can be many (tens to hundreds    of thousands) of template parameter types in a compilation, and    there's no need for this additional information in that case.    Therefore, we now use this data structure only for class types.     In the past, it was thought that there would be relatively few    class types.  However, in the presence of heavy use of templates,    many (i.e., thousands) of classes can easily be generated.    Therefore, we should endeavor to keep the size of this structure to    a minimum.  */
end_comment

begin_decl_stmt
name|struct
name|lang_type_class
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|lang_type_header
name|h
decl_stmt|;
name|unsigned
name|char
name|align
decl_stmt|;
name|unsigned
name|has_mutable
range|:
literal|1
decl_stmt|;
name|unsigned
name|com_interface
range|:
literal|1
decl_stmt|;
name|unsigned
name|non_pod_class
range|:
literal|1
decl_stmt|;
name|unsigned
name|nearly_empty_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|user_align
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_new
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_array_new
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_delete
range|:
literal|2
decl_stmt|;
name|unsigned
name|interface_only
range|:
literal|1
decl_stmt|;
name|unsigned
name|interface_unknown
range|:
literal|1
decl_stmt|;
name|unsigned
name|contains_empty_class_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|anon_aggr
range|:
literal|1
decl_stmt|;
name|unsigned
name|non_zero_init
range|:
literal|1
decl_stmt|;
name|unsigned
name|empty_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|vec_new_uses_cookie
range|:
literal|1
decl_stmt|;
name|unsigned
name|declared_class
range|:
literal|1
decl_stmt|;
name|unsigned
name|diamond_shaped
range|:
literal|1
decl_stmt|;
name|unsigned
name|repeated_base
range|:
literal|1
decl_stmt|;
name|unsigned
name|being_defined
range|:
literal|1
decl_stmt|;
name|unsigned
name|java_interface
range|:
literal|1
decl_stmt|;
name|unsigned
name|debug_requested
range|:
literal|1
decl_stmt|;
name|unsigned
name|fields_readonly
range|:
literal|1
decl_stmt|;
name|unsigned
name|use_template
range|:
literal|2
decl_stmt|;
name|unsigned
name|ptrmemfunc_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|was_anonymous
range|:
literal|1
decl_stmt|;
name|unsigned
name|lazy_default_ctor
range|:
literal|1
decl_stmt|;
name|unsigned
name|lazy_copy_ctor
range|:
literal|1
decl_stmt|;
name|unsigned
name|lazy_assignment_op
range|:
literal|1
decl_stmt|;
name|unsigned
name|lazy_destructor
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_const_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_complex_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_complex_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|non_aggregate
range|:
literal|1
decl_stmt|;
comment|/* When adding a flag here, consider whether or not it ought to      apply to a template instance if it applies to the template.  If      so, make sure to copy it in instantiate_class_template!  */
comment|/* There are some bits left to fill out a 32-bit word.  Keep track      of this by updating the size of this bitfield whenever you add or      remove a flag.  */
name|unsigned
name|dummy
range|:
literal|12
decl_stmt|;
name|tree
name|primary_base
decl_stmt|;
name|VEC
argument_list|(
name|tree_pair_s
argument_list|,
name|gc
argument_list|)
operator|*
name|vcall_indices
expr_stmt|;
name|tree
name|vtables
decl_stmt|;
name|tree
name|typeinfo_var
decl_stmt|;
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|vbases
expr_stmt|;
name|binding_table
name|nested_udts
decl_stmt|;
name|tree
name|as_base
decl_stmt|;
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|pure_virtuals
expr_stmt|;
name|tree
name|friend_classes
decl_stmt|;
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|GTY
argument_list|(
argument|(reorder (
literal|"resort_type_method_vec"
argument|))
argument_list|)
name|methods
expr_stmt|;
name|tree
name|key_method
decl_stmt|;
name|tree
name|decl_list
decl_stmt|;
name|tree
name|template_info
decl_stmt|;
name|tree
name|befriending_classes
decl_stmt|;
comment|/* In a RECORD_TYPE, information specific to Objective-C++, such      as a list of adopted protocols or a pointer to a corresponding      @interface.  See objc/objc-act.h for details.  */
name|tree
name|objc_info
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|lang_type_ptrmem
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|lang_type_header
name|h
decl_stmt|;
name|tree
name|record
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|lang_type
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
union|union
name|lang_type_u
block|{
name|struct
name|lang_type_header
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|h
decl_stmt|;
name|struct
name|lang_type_class
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|c
decl_stmt|;
name|struct
name|lang_type_ptrmem
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|)
argument_list|)
name|ptrmem
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"%h.h.is_lang_type_class"
argument_list|)
operator|)
argument_list|)
name|u
union|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|defined
name|ENABLE_TREE_CHECKING
operator|&&
operator|(
name|GCC_VERSION
operator|>=
literal|2007
operator|)
end_if

begin_define
define|#
directive|define
name|LANG_TYPE_CLASS_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|__extension__		\ ({  struct lang_type *lt = TYPE_LANG_SPECIFIC (NODE);		\     if (! lt->u.h.is_lang_type_class)				\       lang_check_failed (__FILE__, __LINE__, __FUNCTION__);	\&lt->u.c; })
end_define

begin_define
define|#
directive|define
name|LANG_TYPE_PTRMEM_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|__extension__		\ ({  struct lang_type *lt = TYPE_LANG_SPECIFIC (NODE);		\     if (lt->u.h.is_lang_type_class)				\       lang_check_failed (__FILE__, __LINE__, __FUNCTION__);	\&lt->u.ptrmem; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LANG_TYPE_CLASS_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|(&TYPE_LANG_SPECIFIC (NODE)->u.c)
end_define

begin_define
define|#
directive|define
name|LANG_TYPE_PTRMEM_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|(&TYPE_LANG_SPECIFIC (NODE)->u.ptrmem)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENABLE_TREE_CHECKING */
end_comment

begin_comment
comment|/* Fields used for storing information before the class is defined.    After the class is defined, these fields hold other information.  */
end_comment

begin_comment
comment|/* VEC(tree) of friends which were defined inline in this class    definition.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INLINE_FRIENDS
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_PURE_VIRTUALS (NODE)
end_define

begin_comment
comment|/* Nonzero for _CLASSTYPE means that operator delete is defined.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_GETS_DELETE
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->gets_delete)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_REG_DELETE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_GETS_DELETE (NODE)& 1)
end_define

begin_comment
comment|/* Nonzero if `new NODE[x]' should cause the allocation of extra    storage to indicate how many array elements are in use.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_VEC_NEW_USES_COOKIE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASS_TYPE_P (NODE)					\&& LANG_TYPE_CLASS_CHECK (NODE)->vec_new_uses_cookie)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node defines ways of converting    itself to other types.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_CONVERSION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->h.has_type_conversion)
end_define

begin_comment
comment|/* Nonzero means that NODE (a class type) has a default constructor --    but that it has not yet been declared.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_LAZY_DEFAULT_CTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->lazy_default_ctor)
end_define

begin_comment
comment|/* Nonzero means that NODE (a class type) has a copy constructor --    but that it has not yet been declared.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_LAZY_COPY_CTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->lazy_copy_ctor)
end_define

begin_comment
comment|/* Nonzero means that NODE (a class type) has an assignment operator    -- but that it has not yet been declared.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_LAZY_ASSIGNMENT_OP
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->lazy_assignment_op)
end_define

begin_comment
comment|/* Nonzero means that NODE (a class type) has a destructor -- but that    it has not yet been declared.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_LAZY_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->lazy_destructor)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator=(X&).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->has_assign_ref)
end_define

begin_comment
comment|/* True iff the class type NODE has an "operator =" whose parameter    has a parameter of type "const X&".  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_CONST_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->h.has_const_assign_ref)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node has an X(X&) constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->h.has_init_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_CONST_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->has_const_init_ref)
end_define

begin_comment
comment|/* Nonzero if this class defines an overloaded operator new.  (An    operator new [] doesn't count.)  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_NEW_OPERATOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->has_new)
end_define

begin_comment
comment|/* Nonzero if this class defines an overloaded operator new[].  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_ARRAY_NEW_OPERATOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->has_array_new)
end_define

begin_comment
comment|/* Nonzero means that this type is being defined.  I.e., the left brace    starting the definition of this type has been seen.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BEING_DEFINED
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->being_defined)
end_define

begin_comment
comment|/* Mark bits for repeated base checks.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_MARKED_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_6 (TYPE_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if the class NODE has multiple paths to the same (virtual)    base object.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DIAMOND_SHAPED_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK(NODE)->diamond_shaped)
end_define

begin_comment
comment|/* Nonzero if the class NODE has multiple instances of the same base    type.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_REPEATED_BASE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK(NODE)->repeated_base)
end_define

begin_comment
comment|/* The member function with which the vtable will be emitted:    the first noninline non-pure-virtual member function.  NULL_TREE    if there is no key function or if this is a class template */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_KEY_METHOD
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->key_method)
end_define

begin_comment
comment|/* Vector member functions defined in this class.  Each element is    either a FUNCTION_DECL, a TEMPLATE_DECL, or an OVERLOAD.  All    functions with the same name end up in the same slot.  The first    two elements are for constructors, and destructors, respectively.    All template conversion operators to innermost template dependent    types are overloaded on the next slot, if they exist.  Note, the    names for these functions will not all be the same.  The    non-template conversion operators& templated conversions to    non-innermost template types are next, followed by ordinary member    functions.  There may be empty entries at the end of the vector.    The conversion operators are unsorted. The ordinary member    functions are sorted, once the class is complete.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_METHOD_VEC
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->methods)
end_define

begin_comment
comment|/* For class templates, this is a TREE_LIST of all member data,    functions, types, and friends in the order of declaration.    The TREE_PURPOSE of each TREE_LIST is NULL_TREE for a friend,    and the RECORD_TYPE for the class template otherwise.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DECL_LIST
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->decl_list)
end_define

begin_comment
comment|/* The slot in the CLASSTYPE_METHOD_VEC where constructors go.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_CONSTRUCTOR_SLOT
value|0
end_define

begin_comment
comment|/* The slot in the CLASSTYPE_METHOD_VEC where destructors go.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DESTRUCTOR_SLOT
value|1
end_define

begin_comment
comment|/* The first slot in the CLASSTYPE_METHOD_VEC where conversion    operators can appear.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_FIRST_CONVERSION_SLOT
value|2
end_define

begin_comment
comment|/* A FUNCTION_DECL or OVERLOAD for the constructors for NODE.  These    are the constructors that take an in-charge parameter.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_CONSTRUCTORS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VEC_index (tree, CLASSTYPE_METHOD_VEC (NODE), CLASSTYPE_CONSTRUCTOR_SLOT))
end_define

begin_comment
comment|/* A FUNCTION_DECL for the destructor for NODE.  These are the    destructors that take an in-charge parameter.  If    CLASSTYPE_LAZY_DESTRUCTOR is true, then this entry will be NULL    until the destructor is created with lazily_declare_fn.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DESTRUCTORS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_METHOD_VEC (NODE)						      \    ? VEC_index (tree, CLASSTYPE_METHOD_VEC (NODE), CLASSTYPE_DESTRUCTOR_SLOT) \    : NULL_TREE)
end_define

begin_comment
comment|/* A dictionary of the nested user-defined-types (class-types, or enums)    found within this class.  This table includes nested member class    templates.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NESTED_UTDS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->nested_udts)
end_define

begin_comment
comment|/* Nonzero if NODE has a primary base class, i.e., a base class with    which it shares the virtual function table pointer.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_HAS_PRIMARY_BASE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_PRIMARY_BINFO (NODE) != NULL_TREE)
end_define

begin_comment
comment|/* If non-NULL, this is the binfo for the primary base class, i.e.,    the base class which contains the virtual function table pointer    for this class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_PRIMARY_BINFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->primary_base)
end_define

begin_comment
comment|/* A vector of BINFOs for the direct and indirect virtual base classes    that this type uses in a post-order depth-first left-to-right    order.  (In other words, these bases appear in the order that they    should be initialized.)  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VBASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->vbases)
end_define

begin_comment
comment|/* The type corresponding to NODE when NODE is used as a base class,    i.e., NODE without virtual base classes.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_AS_BASE
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->as_base)
end_define

begin_comment
comment|/* True iff NODE is the CLASSTYPE_AS_BASE version of some type.  */
end_comment

begin_define
define|#
directive|define
name|IS_FAKE_BASE_TYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == RECORD_TYPE				\&& TYPE_CONTEXT (NODE)&& CLASS_TYPE_P (TYPE_CONTEXT (NODE))	\&& CLASSTYPE_AS_BASE (TYPE_CONTEXT (NODE)) == (NODE))
end_define

begin_comment
comment|/* These are the size and alignment of the type without its virtual    base classes, for when we use this type as a base itself.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_SIZE (CLASSTYPE_AS_BASE (NODE))
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_SIZE_UNIT (CLASSTYPE_AS_BASE (NODE))
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_ALIGN (CLASSTYPE_AS_BASE (NODE))
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_USER_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_USER_ALIGN (CLASSTYPE_AS_BASE (NODE))
end_define

begin_comment
comment|/* The alignment of NODE, without its virtual bases, in bytes.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_ALIGN_UNIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_ALIGN (NODE) / BITS_PER_UNIT)
end_define

begin_comment
comment|/* True if this a Java interface type, declared with    '__attribute__ ((java_interface))'.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_JAVA_INTERFACE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->java_interface)
end_define

begin_comment
comment|/* A VEC(tree) of virtual functions which cannot be inherited by    derived classes.  When deriving from this type, the derived    class must provide its own definition for each of these functions.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_PURE_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->pure_virtuals)
end_define

begin_comment
comment|/* Nonzero means that this type has an X() constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_DEFAULT_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->h.has_default_ctor)
end_define

begin_comment
comment|/* Nonzero means that this type contains a mutable member.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_HAS_MUTABLE
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->has_mutable)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_MUTABLE_P
parameter_list|(
name|NODE
parameter_list|)
value|(cp_has_mutable_p (NODE))
end_define

begin_comment
comment|/* Nonzero means that this class type is a non-POD class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NON_POD_P
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->non_pod_class)
end_define

begin_comment
comment|/* Nonzero means that this class contains pod types whose default    initialization is not a zero initialization (namely, pointers to    data members).  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NON_ZERO_INIT_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->non_zero_init)
end_define

begin_comment
comment|/* Nonzero if this class is "empty" in the sense of the C++ ABI.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_EMPTY_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->empty_p)
end_define

begin_comment
comment|/* Nonzero if this class is "nearly empty", i.e., contains only a    virtual function table pointer.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NEARLY_EMPTY_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->nearly_empty_p)
end_define

begin_comment
comment|/* Nonzero if this class contains an empty subobject.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_CONTAINS_EMPTY_CLASS_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->contains_empty_class_p)
end_define

begin_comment
comment|/* A list of class types of which this type is a friend.  The    TREE_VALUE is normally a TYPE, but will be a TEMPLATE_DECL in the    case of a template friend.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_FRIEND_CLASSES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->friend_classes)
end_define

begin_comment
comment|/* A list of the classes which grant friendship to this class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_BEFRIENDING_CLASSES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->befriending_classes)
end_define

begin_comment
comment|/* Say whether this node was declared as a "class" or a "struct".  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DECLARED_CLASS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->declared_class)
end_define

begin_comment
comment|/* Nonzero if this class has const members    which have no specified initialization.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_READONLY_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)				\    ? LANG_TYPE_CLASS_CHECK (NODE)->h.const_needs_init : 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_READONLY_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->h.const_needs_init = (VALUE))
end_define

begin_comment
comment|/* Nonzero if this class has ref members    which have no specified initialization.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_REF_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)				\    ? LANG_TYPE_CLASS_CHECK (NODE)->h.ref_needs_init : 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_REF_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->h.ref_needs_init = (VALUE))
end_define

begin_comment
comment|/* Nonzero if this class is included from a header file which employs    `#pragma interface', and it is not included in its implementation file.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_ONLY
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->interface_only)
end_define

begin_comment
comment|/* True if we have already determined whether or not vtables, VTTs,    typeinfo, and other similar per-class data should be emitted in    this translation unit.  This flag does not indicate whether or not    these items should be emitted; it only indicates that we know one    way or the other.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_KNOWN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->interface_unknown == 0)
end_define

begin_comment
comment|/* The opposite of CLASSTYPE_INTERFACE_KNOWN.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_UNKNOWN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->interface_unknown)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_INTERFACE_UNKNOWN_X
parameter_list|(
name|NODE
parameter_list|,
name|X
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->interface_unknown = !!(X))
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_INTERFACE_UNKNOWN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->interface_unknown = 1)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_INTERFACE_KNOWN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->interface_unknown = 0)
end_define

begin_comment
comment|/* Nonzero if a _DECL node requires us to output debug info for this class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DEBUG_REQUESTED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->debug_requested)
end_define

begin_escape
end_escape

begin_comment
comment|/* Additional macros for inheritance information.  */
end_comment

begin_comment
comment|/* Nonzero means that this class is on a path leading to a new vtable.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VTABLE_PATH_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_FLAG_1 (NODE)
end_define

begin_comment
comment|/* Nonzero means B (a BINFO) has its own vtable.  Any copies will not    have this flag set.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|B
parameter_list|)
value|(BINFO_FLAG_2 (B))
end_define

begin_comment
comment|/* Compare a BINFO_TYPE with another type for equality.  For a binfo,    this is functionally equivalent to using same_type_p, but    measurably faster.  At least one of the arguments must be a    BINFO_TYPE.  The other can be a BINFO_TYPE or a regular type.  If    BINFO_TYPE(T) ever stops being the main variant of the class the    binfo is for, this macro must change.  */
end_comment

begin_define
define|#
directive|define
name|SAME_BINFO_TYPE_P
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A) == (B))
end_define

begin_comment
comment|/* Any subobject that needs a new vtable must have a vptr and must not    be a non-virtual primary base (since it would then use the vtable from a    derived class and never become non-primary.)  */
end_comment

begin_define
define|#
directive|define
name|SET_BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|B
parameter_list|)
define|\
value|(BINFO_NEW_VTABLE_MARKED (B) = 1,					 \    gcc_assert (!BINFO_PRIMARY_P (B) || BINFO_VIRTUAL_P (B)),		 \    gcc_assert (TYPE_VFIELD (BINFO_TYPE (B))))
end_define

begin_comment
comment|/* Nonzero if this binfo is for a dependent base - one that should not    be searched.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_DEPENDENT_BASE_P
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_FLAG_3 (NODE)
end_define

begin_comment
comment|/* Nonzero if this binfo has lost its primary base binfo (because that    is a nearly-empty virtual base that has been taken by some other    base in the complete hierarchy.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_LOST_PRIMARY_P
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_FLAG_4 (NODE)
end_define

begin_comment
comment|/* Nonzero if this BINFO is a primary base class.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_PRIMARY_P
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_FLAG_5(NODE)
end_define

begin_comment
comment|/* Used by various search routines.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
end_define

begin_escape
end_escape

begin_comment
comment|/* A VEC(tree_pair_s) of the vcall indices associated with the class    NODE.  The PURPOSE of each element is a FUNCTION_DECL for a virtual    function.  The VALUE is the index into the virtual table where the    vcall offset for that function is stored, when NODE is a virtual    base.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VCALL_INDICES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->vcall_indices)
end_define

begin_comment
comment|/* The various vtables for the class NODE.  The primary vtable will be    first, followed by the construction vtables and VTT, if any.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VTABLES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->vtables)
end_define

begin_comment
comment|/* The std::type_info variable representing this class, or NULL if no    such variable has been created.  This field is only set for the    TYPE_MAIN_VARIANT of the class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_TYPEINFO_VAR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->typeinfo_var)
end_define

begin_comment
comment|/* Accessor macros for the BINFO_VIRTUALS list.  */
end_comment

begin_comment
comment|/* The number of bytes by which to adjust the `this' pointer when    calling this virtual function.  Subtract this value from the this    pointer. Always non-NULL, might be constant zero though.  */
end_comment

begin_define
define|#
directive|define
name|BV_DELTA
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_PURPOSE (NODE))
end_define

begin_comment
comment|/* If non-NULL, the vtable index at which to find the vcall offset    when calling this virtual function.  Add the value at that vtable    index to the this pointer.  */
end_comment

begin_define
define|#
directive|define
name|BV_VCALL_INDEX
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_TYPE (NODE))
end_define

begin_comment
comment|/* The function to call.  */
end_comment

begin_define
define|#
directive|define
name|BV_FN
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VALUE (NODE))
end_define

begin_escape
end_escape

begin_comment
comment|/* For FUNCTION_TYPE or METHOD_TYPE, a list of the exceptions that    this type can raise.  Each TREE_VALUE is a _TYPE.  The TREE_VALUE    will be NULL_TREE to indicate a throw specification of `()', or    no exceptions allowed.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_RAISES_EXCEPTIONS
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_LANG_SLOT_1 (NODE)
end_define

begin_comment
comment|/* For FUNCTION_TYPE or METHOD_TYPE, return 1 iff it is declared `throw()'.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NOTHROW_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_RAISES_EXCEPTIONS (NODE) \&& TREE_VALUE (TYPE_RAISES_EXCEPTIONS (NODE)) == NULL_TREE)
end_define

begin_comment
comment|/* The binding level associated with the namespace.  */
end_comment

begin_define
define|#
directive|define
name|NAMESPACE_LEVEL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.u.level)
end_define

begin_escape
end_escape

begin_comment
comment|/* If a DECL has DECL_LANG_SPECIFIC, it is either a lang_decl_flags or    a lang_decl (which has lang_decl_flags as its initial prefix).    This macro is nonzero for tree nodes whose DECL_LANG_SPECIFIC is    the full lang_decl, and not just lang_decl_flags.  Keep these    checks in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|CAN_HAVE_FULL_LANG_DECL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(!(TREE_CODE (NODE) == FIELD_DECL			\      || TREE_CODE (NODE) == VAR_DECL			\      || TREE_CODE (NODE) == CONST_DECL			\      || TREE_CODE (NODE) == USING_DECL))
end_define

begin_decl_stmt
name|struct
name|lang_decl_flags
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|ENUM_BITFIELD
argument_list|(
argument|languages
argument_list|)
name|language
label|:
literal|4
expr_stmt|;
name|unsigned
name|global_ctor_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|global_dtor_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|anticipated_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|template_conv_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|operator_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|constructor_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|destructor_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|friend_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|static_function
range|:
literal|1
decl_stmt|;
name|unsigned
name|pure_virtual
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_in_charge_parm_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_vtt_parm_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|deferred
range|:
literal|1
decl_stmt|;
name|unsigned
name|use_template
range|:
literal|2
decl_stmt|;
name|unsigned
name|nonconverting
range|:
literal|1
decl_stmt|;
name|unsigned
name|not_really_extern
range|:
literal|1
decl_stmt|;
name|unsigned
name|initialized_in_class
range|:
literal|1
decl_stmt|;
name|unsigned
name|assignment_operator_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|u1sel
range|:
literal|1
decl_stmt|;
name|unsigned
name|u2sel
range|:
literal|1
decl_stmt|;
name|unsigned
name|can_be_full
range|:
literal|1
decl_stmt|;
name|unsigned
name|thunk_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|this_thunk_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|repo_available_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|hidden_friend_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|threadprivate_p
range|:
literal|1
decl_stmt|;
comment|/* One unused bit.  */
union|union
name|lang_decl_u
block|{
comment|/* In a FUNCTION_DECL for which DECL_THUNK_P holds, this is        THUNK_ALIAS.        In a FUNCTION_DECL for which DECL_THUNK_P does not hold,        VAR_DECL, TYPE_DECL, or TEMPLATE_DECL, this is        DECL_TEMPLATE_INFO.  */
name|tree
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|)
argument_list|)
name|template_info
decl_stmt|;
comment|/* In a NAMESPACE_DECL, this is NAMESPACE_LEVEL.  */
name|struct
name|cp_binding_level
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|level
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"%1.u1sel"
argument_list|)
operator|)
argument_list|)
name|u
union|;
union|union
name|lang_decl_u2
block|{
comment|/* In a FUNCTION_DECL for which DECL_THUNK_P holds, this is        THUNK_VIRTUAL_OFFSET.        Otherwise this is DECL_ACCESS.  */
name|tree
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|)
argument_list|)
name|access
decl_stmt|;
comment|/* For VAR_DECL in function, this is DECL_DISCRIMINATOR.  */
name|int
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|discriminator
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"%1.u2sel"
argument_list|)
operator|)
argument_list|)
name|u2
union|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* sorted_fields is sorted based on a pointer, so we need to be able    to resort it if pointers get rearranged.  */
end_comment

begin_decl_stmt
name|struct
name|lang_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|lang_decl_flags
name|decl_flags
decl_stmt|;
union|union
name|lang_decl_u4
block|{
struct|struct
name|full_lang_decl
block|{
comment|/* In an overloaded operator, this is the value of 	   DECL_OVERLOADED_OPERATOR_P.  */
name|ENUM_BITFIELD
argument_list|(
argument|tree_code
argument_list|)
name|operator_code
label|:
literal|8
expr_stmt|;
name|unsigned
name|u3sel
range|:
literal|1
decl_stmt|;
name|unsigned
name|pending_inline_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|spare
range|:
literal|22
decl_stmt|;
comment|/* For a non-thunk function decl, this is a tree list of 	   friendly classes. For a thunk function decl, it is the 	   thunked to function decl.  */
name|tree
name|befriending_classes
decl_stmt|;
comment|/* For a non-virtual FUNCTION_DECL, this is 	   DECL_FRIEND_CONTEXT.  For a virtual FUNCTION_DECL for which 	   DECL_THIS_THUNK_P does not hold, this is DECL_THUNKS. Both 	   this pointer and result pointer adjusting thunks are 	   chained here.  This pointer thunks to return pointer thunks 	   will be chained on the return pointer thunk.  */
name|tree
name|context
decl_stmt|;
union|union
name|lang_decl_u5
block|{
comment|/* In a non-thunk FUNCTION_DECL or TEMPLATE_DECL, this is 	     DECL_CLONED_FUNCTION.  */
name|tree
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|)
argument_list|)
name|cloned_function
decl_stmt|;
comment|/* In a FUNCTION_DECL for which THUNK_P holds this is the 	     THUNK_FIXED_OFFSET.  */
name|HOST_WIDE_INT
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|fixed_offset
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"%0.decl_flags.thunk_p"
argument_list|)
operator|)
argument_list|)
name|u5
union|;
union|union
name|lang_decl_u3
block|{
name|struct
name|sorted_fields_type
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|,
name|reorder
argument_list|(
literal|"resort_sorted_fields"
argument_list|)
operator|)
argument_list|)
name|sorted_fields
decl_stmt|;
name|struct
name|cp_token_cache
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"2"
argument_list|)
operator|)
argument_list|)
name|pending_inline_info
decl_stmt|;
name|struct
name|language_function
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|saved_language_function
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"%1.u3sel + %1.pending_inline_p"
argument_list|)
operator|)
argument_list|)
name|u
union|;
block|}
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|f
struct|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"%1.decl_flags.can_be_full"
argument_list|)
operator|)
argument_list|)
name|u
union|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|defined
name|ENABLE_TREE_CHECKING
operator|&&
operator|(
name|GCC_VERSION
operator|>=
literal|2007
operator|)
end_if

begin_define
define|#
directive|define
name|LANG_DECL_U2_CHECK
parameter_list|(
name|NODE
parameter_list|,
name|TF
parameter_list|)
value|__extension__		\ ({  struct lang_decl *lt = DECL_LANG_SPECIFIC (NODE);		\     if (lt->decl_flags.u2sel != TF)				\       lang_check_failed (__FILE__, __LINE__, __FUNCTION__);	\&lt->decl_flags.u2; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LANG_DECL_U2_CHECK
parameter_list|(
name|NODE
parameter_list|,
name|TF
parameter_list|)
define|\
value|(&DECL_LANG_SPECIFIC (NODE)->decl_flags.u2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENABLE_TREE_CHECKING */
end_comment

begin_comment
comment|/* For a FUNCTION_DECL or a VAR_DECL, the language linkage for the    declaration.  Some entities (like a member function in a local    class, or a local variable) do not have linkage at all, and this    macro should not be used in those cases.     Implementation note: A FUNCTION_DECL without DECL_LANG_SPECIFIC was    created by language-independent code, and has C linkage.  Most    VAR_DECLs have C++ linkage, and do not have DECL_LANG_SPECIFIC, but    we do create DECL_LANG_SPECIFIC for variables with non-C++ linkage.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LANGUAGE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)				\    ? DECL_LANG_SPECIFIC (NODE)->decl_flags.language	\    : (TREE_CODE (NODE) == FUNCTION_DECL			\       ? lang_c : lang_cplusplus))
end_define

begin_comment
comment|/* Set the language linkage for NODE to LANGUAGE.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_LANGUAGE
parameter_list|(
name|NODE
parameter_list|,
name|LANGUAGE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.language = (LANGUAGE))
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that this function is a constructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.constructor_attr)
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a constructor for a complete    object.  */
end_comment

begin_define
define|#
directive|define
name|DECL_COMPLETE_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONSTRUCTOR_P (NODE)				\&& DECL_NAME (NODE) == complete_ctor_identifier)
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a constructor for a base    object.  */
end_comment

begin_define
define|#
directive|define
name|DECL_BASE_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONSTRUCTOR_P (NODE)			\&& DECL_NAME (NODE) == base_ctor_identifier)
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a constructor, but not either the    specialized in-charge constructor or the specialized not-in-charge    constructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAYBE_IN_CHARGE_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONSTRUCTOR_P (NODE)&& !DECL_CLONED_FUNCTION_P (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a copy constructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_COPY_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONSTRUCTOR_P (NODE)&& copy_fn_p (NODE)> 0)
end_define

begin_comment
comment|/* Nonzero if NODE is a destructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DESTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.destructor_attr)
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a destructor, but not the    specialized in-charge constructor, in-charge deleting constructor,    or the base destructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAYBE_IN_CHARGE_DESTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_DESTRUCTOR_P (NODE)&& !DECL_CLONED_FUNCTION_P (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a destructor for a complete    object.  */
end_comment

begin_define
define|#
directive|define
name|DECL_COMPLETE_DESTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_DESTRUCTOR_P (NODE)				\&& DECL_NAME (NODE) == complete_dtor_identifier)
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a destructor for a base    object.  */
end_comment

begin_define
define|#
directive|define
name|DECL_BASE_DESTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_DESTRUCTOR_P (NODE)			\&& DECL_NAME (NODE) == base_dtor_identifier)
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a destructor for a complete    object that deletes the object after it has been destroyed.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DELETING_DESTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_DESTRUCTOR_P (NODE)				\&& DECL_NAME (NODE) == deleting_dtor_identifier)
end_define

begin_comment
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a cloned constructor or    destructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CLONED_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_CODE (NODE) == FUNCTION_DECL			\     || TREE_CODE (NODE) == TEMPLATE_DECL)		\&& DECL_LANG_SPECIFIC (NODE)				\&& !DECL_LANG_SPECIFIC (NODE)->decl_flags.thunk_p	\&& DECL_CLONED_FUNCTION (NODE) != NULL_TREE)
end_define

begin_comment
comment|/* If DECL_CLONED_FUNCTION_P holds, this is the function that was    cloned.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CLONED_FUNCTION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NON_THUNK_FUNCTION_CHECK(NODE))->u.f.u5.cloned_function)
end_define

begin_comment
comment|/* Perform an action for each clone of FN, if FN is a function with    clones.  This macro should be used like:        FOR_EACH_CLONE (clone, fn) 	{ ... }    */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_CLONE
parameter_list|(
name|CLONE
parameter_list|,
name|FN
parameter_list|)
define|\
value|if (TREE_CODE (FN) == FUNCTION_DECL			\&& (DECL_MAYBE_IN_CHARGE_CONSTRUCTOR_P (FN)	\ 	  || DECL_MAYBE_IN_CHARGE_DESTRUCTOR_P (FN)))	\      for (CLONE = TREE_CHAIN (FN);			\ 	  CLONE&& DECL_CLONED_FUNCTION_P (CLONE);	\ 	  CLONE = TREE_CHAIN (CLONE))
end_define

begin_comment
comment|/* Nonzero if NODE has DECL_DISCRIMINATOR and not DECL_ACCESS.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DISCRIMINATOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == VAR_DECL		\&& DECL_FUNCTION_SCOPE_P (NODE))
end_define

begin_comment
comment|/* Discriminator for name mangling.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DISCRIMINATOR
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_DECL_U2_CHECK (NODE, 1)->discriminator)
end_define

begin_comment
comment|/* Nonzero if the VTT parm has been added to NODE.  */
end_comment

begin_define
define|#
directive|define
name|DECL_HAS_VTT_PARM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.has_vtt_parm_p)
end_define

begin_comment
comment|/* Nonzero if NODE is a FUNCTION_DECL for which a VTT parameter is    required.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NEEDS_VTT_PARM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_VBASECLASSES (DECL_CONTEXT (NODE))		\&& (DECL_BASE_CONSTRUCTOR_P (NODE)			\        || DECL_BASE_DESTRUCTOR_P (NODE)))
end_define

begin_comment
comment|/* Nonzero if NODE is a user-defined conversion operator.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONV_FN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_NAME (NODE)&& IDENTIFIER_TYPENAME_P (DECL_NAME (NODE)))
end_define

begin_comment
comment|/* If FN is a conversion operator, the type to which it converts.    Otherwise, NULL_TREE.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONV_FN_TYPE
parameter_list|(
name|FN
parameter_list|)
define|\
value|(DECL_CONV_FN_P (FN) ? TREE_TYPE (DECL_NAME (FN)) : NULL_TREE)
end_define

begin_comment
comment|/* Nonzero if NODE, which is a TEMPLATE_DECL, is a template    conversion operator to a type dependent on the innermost template    args.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_CONV_FN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.template_conv_p)
end_define

begin_comment
comment|/* Set the overloaded operator code for NODE to CODE.  */
end_comment

begin_define
define|#
directive|define
name|SET_OVERLOADED_OPERATOR_CODE
parameter_list|(
name|NODE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->u.f.operator_code = (CODE))
end_define

begin_comment
comment|/* If NODE is an overloaded operator, then this returns the TREE_CODE    associated with the overloaded operator.    DECL_ASSIGNMENT_OPERATOR_P must also be checked to determine    whether or not NODE is an assignment operator.  If NODE is not an    overloaded operator, ERROR_MARK is returned.  Since the numerical    value of ERROR_MARK is zero, this macro can be used as a predicate    to test whether or not NODE is an overloaded operator.  */
end_comment

begin_define
define|#
directive|define
name|DECL_OVERLOADED_OPERATOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_OPNAME_P (DECL_NAME (NODE))		\    ? DECL_LANG_SPECIFIC (NODE)->u.f.operator_code : ERROR_MARK)
end_define

begin_comment
comment|/* Nonzero if NODE is an assignment operator.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ASSIGNMENT_OPERATOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.assignment_operator_p)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that this function is a    constructor or a destructor with an extra in-charge parameter to    control whether or not virtual bases are constructed.  */
end_comment

begin_define
define|#
directive|define
name|DECL_HAS_IN_CHARGE_PARM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.has_in_charge_parm_p)
end_define

begin_comment
comment|/* Nonzero if DECL is a declaration of __builtin_constant_p.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IS_BUILTIN_CONSTANT_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == FUNCTION_DECL			\&& DECL_BUILT_IN_CLASS (NODE) == BUILT_IN_NORMAL	\&& DECL_FUNCTION_CODE (NODE) == BUILT_IN_CONSTANT_P)
end_define

begin_comment
comment|/* Nonzero for _DECL means that this decl appears in (or will appear    in) as a member in a RECORD_TYPE or UNION_TYPE node.  It is also for    detecting circularity in case members are multiply defined.  In the    case of a VAR_DECL, it is also used to determine how program storage    should be allocated.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IN_AGGR_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_3 (NODE))
end_define

begin_comment
comment|/* Nonzero for a VAR_DECL means that the variable's initialization (if    any) has been processed.  (In general, DECL_INITIALIZED_P is    !DECL_EXTERN, but static data members may be initialized even if    not defined.)  */
end_comment

begin_define
define|#
directive|define
name|DECL_INITIALIZED_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_1 (VAR_DECL_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero for a VAR_DECL iff an explicit initializer was provided.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NONTRIVIALLY_INITIALIZED_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_3 (VAR_DECL_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero for a VAR_DECL that was initialized with a    constant-expression.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INITIALIZED_BY_CONSTANT_EXPRESSION_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_2 (VAR_DECL_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero for a VAR_DECL that can be used in an integral constant    expression.        [expr.const]        An integral constant-expression can only involve ... const       variables of static or enumeration types initialized with       constant expressions ...     The standard does not require that the expression be non-volatile.    G++ implements the proposed correction in DR 457.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INTEGRAL_CONSTANT_VAR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == VAR_DECL				\&& CP_TYPE_CONST_NON_VOLATILE_P (TREE_TYPE (NODE))	\&& INTEGRAL_OR_ENUMERATION_TYPE_P (TREE_TYPE (NODE))	\&& DECL_INITIALIZED_BY_CONSTANT_EXPRESSION_P (NODE))
end_define

begin_comment
comment|/* Nonzero if the DECL was initialized in the class definition itself,    rather than outside the class.  This is used for both static member    VAR_DECLS, and FUNTION_DECLS that are defined in the class.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INITIALIZED_IN_CLASS_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (DECL)->decl_flags.initialized_in_class)
end_define

begin_comment
comment|/* Nonzero for DECL means that this decl is just a friend declaration,    and should not be added to the list of members for this class.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRIEND_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.friend_attr)
end_define

begin_comment
comment|/* A TREE_LIST of the types which have befriended this FUNCTION_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_BEFRIENDING_CLASSES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->u.f.befriending_classes)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this decl is a static    member function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_STATIC_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.static_function)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this decl is a non-static    member function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NONSTATIC_MEMBER_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (TREE_TYPE (NODE)) == METHOD_TYPE)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this decl is a member function    (static or non-static).  */
end_comment

begin_define
define|#
directive|define
name|DECL_FUNCTION_MEMBER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_NONSTATIC_MEMBER_FUNCTION_P (NODE) || DECL_STATIC_FUNCTION_P (NODE))
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    has `this' as const X *const.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONST_MEMFUNC_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_NONSTATIC_MEMBER_FUNCTION_P (NODE)				 \&& CP_TYPE_CONST_P (TREE_TYPE (TREE_VALUE				 \ 				  (TYPE_ARG_TYPES (TREE_TYPE (NODE))))))
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    has `this' as volatile X *const.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VOLATILE_MEMFUNC_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_NONSTATIC_MEMBER_FUNCTION_P (NODE)				 \&& CP_TYPE_VOLATILE_P (TREE_TYPE (TREE_VALUE				 \ 				  (TYPE_ARG_TYPES (TREE_TYPE (NODE))))))
end_define

begin_comment
comment|/* Nonzero for a DECL means that this member is a non-static member.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NONSTATIC_MEMBER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_CODE (NODE) == FUNCTION_DECL		\&& DECL_NONSTATIC_MEMBER_FUNCTION_P (NODE))	\    || TREE_CODE (NODE) == FIELD_DECL)
end_define

begin_comment
comment|/* Nonzero for _DECL means that this member object type    is mutable.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MUTABLE_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_0 (NODE))
end_define

begin_comment
comment|/* Nonzero for _DECL means that this constructor is a non-converting    constructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NONCONVERTING_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.nonconverting)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function is a pure    virtual function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PURE_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.pure_virtual)
end_define

begin_comment
comment|/* True (in a FUNCTION_DECL) if NODE is a virtual function that is an    invalid overrider for a function from a base class.  Once we have    complained about an invalid overrider we avoid complaining about it    again.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INVALID_OVERRIDER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_4 (NODE))
end_define

begin_comment
comment|/* The thunks associated with NODE, a FUNCTION_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THUNKS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->u.f.context)
end_define

begin_comment
comment|/* Nonzero if NODE is a thunk, rather than an ordinary function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THUNK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == FUNCTION_DECL		\&& DECL_LANG_SPECIFIC (NODE)			\&& DECL_LANG_SPECIFIC (NODE)->decl_flags.thunk_p)
end_define

begin_comment
comment|/* Set DECL_THUNK_P for node.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_THUNK_P
parameter_list|(
name|NODE
parameter_list|,
name|THIS_ADJUSTING
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.thunk_p = 1,		\    DECL_LANG_SPECIFIC (NODE)->u.f.u3sel = 1,			\    DECL_LANG_SPECIFIC (NODE)->decl_flags.this_thunk_p = (THIS_ADJUSTING))
end_define

begin_comment
comment|/* Nonzero if NODE is a this pointer adjusting thunk.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THIS_THUNK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_THUNK_P (NODE)&& DECL_LANG_SPECIFIC (NODE)->decl_flags.this_thunk_p)
end_define

begin_comment
comment|/* Nonzero if NODE is a result pointer adjusting thunk.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RESULT_THUNK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_THUNK_P (NODE)&& !DECL_LANG_SPECIFIC (NODE)->decl_flags.this_thunk_p)
end_define

begin_comment
comment|/* Nonzero if NODE is a FUNCTION_DECL, but not a thunk.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NON_THUNK_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == FUNCTION_DECL&& !DECL_THUNK_P (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE is `extern "C"'.  */
end_comment

begin_define
define|#
directive|define
name|DECL_EXTERN_C_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANGUAGE (NODE) == lang_c)
end_define

begin_comment
comment|/* Nonzero if NODE is an `extern "C"' function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_EXTERN_C_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_NON_THUNK_FUNCTION_P (NODE)&& DECL_EXTERN_C_P (NODE))
end_define

begin_comment
comment|/* True iff DECL is an entity with vague linkage whose definition is    available in this translation unit.  */
end_comment

begin_define
define|#
directive|define
name|DECL_REPO_AVAILABLE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.repo_available_p)
end_define

begin_comment
comment|/* Nonzero if this DECL is the __PRETTY_FUNCTION__ variable in a    template function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PRETTY_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_0 (VAR_DECL_CHECK (NODE)))
end_define

begin_comment
comment|/* The _TYPE context in which this _DECL appears.  This field holds the    class where a virtual function instance is actually defined.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CLASS_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CLASS_SCOPE_P (NODE) ? DECL_CONTEXT (NODE) : NULL_TREE)
end_define

begin_comment
comment|/* For a non-member friend function, the class (if any) in which this    friend was defined.  For example, given:       struct S { friend void f (); };     the DECL_FRIEND_CONTEXT for `f' will be `S'.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRIEND_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((DECL_FRIEND_P (NODE)&& !DECL_FUNCTION_MEMBER_P (NODE))	\    ? DECL_LANG_SPECIFIC (NODE)->u.f.context			\    : NULL_TREE)
end_define

begin_comment
comment|/* Set the DECL_FRIEND_CONTEXT for NODE to CONTEXT.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_FRIEND_CONTEXT
parameter_list|(
name|NODE
parameter_list|,
name|CONTEXT
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->u.f.context = (CONTEXT))
end_define

begin_comment
comment|/* NULL_TREE in DECL_CONTEXT represents the global namespace.  */
end_comment

begin_define
define|#
directive|define
name|CP_DECL_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONTEXT (NODE) ? DECL_CONTEXT (NODE) : global_namespace)
end_define

begin_define
define|#
directive|define
name|CP_TYPE_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_CONTEXT (NODE) ? TYPE_CONTEXT (NODE) : global_namespace)
end_define

begin_define
define|#
directive|define
name|FROB_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE) == global_namespace ? NULL_TREE : (NODE))
end_define

begin_comment
comment|/* 1 iff NODE has namespace scope, including the global namespace.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NAMESPACE_SCOPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(!DECL_TEMPLATE_PARM_P (NODE)					\&& TREE_CODE (CP_DECL_CONTEXT (NODE)) == NAMESPACE_DECL)
end_define

begin_define
define|#
directive|define
name|TYPE_NAMESPACE_SCOPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (CP_TYPE_CONTEXT (NODE)) == NAMESPACE_DECL)
end_define

begin_comment
comment|/* 1 iff NODE is a class member.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CLASS_SCOPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONTEXT (NODE)&& TYPE_P (DECL_CONTEXT (NODE)))
end_define

begin_define
define|#
directive|define
name|TYPE_CLASS_SCOPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_CONTEXT (NODE)&& TYPE_P (TYPE_CONTEXT (NODE)))
end_define

begin_comment
comment|/* 1 iff NODE is function-local.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FUNCTION_SCOPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONTEXT (NODE) \&& TREE_CODE (DECL_CONTEXT (NODE)) == FUNCTION_DECL)
end_define

begin_define
define|#
directive|define
name|TYPE_FUNCTION_SCOPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_CONTEXT (NODE) \&& TREE_CODE (TYPE_CONTEXT (NODE)) == FUNCTION_DECL)
end_define

begin_comment
comment|/* 1 iff VAR_DECL node NODE is a type-info decl.  This flag is set for    both the primary typeinfo object and the associated NTBS name.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TINFO_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_4 (VAR_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* 1 iff VAR_DECL node NODE is virtual table or VTT.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VTABLE_OR_VTT_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_5 (VAR_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* Returns 1 iff VAR_DECL is a construction virtual table.    DECL_VTABLE_OR_VTT_P will be true in this case and must be checked    before using this macro.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTION_VTABLE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_6 (VAR_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* 1 iff NODE is function-local, but for types.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_CLASS_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(decl_function_context (TYPE_MAIN_DECL (NODE)) != NULL_TREE)
end_define

begin_comment
comment|/* For a NAMESPACE_DECL: the list of using namespace directives    The PURPOSE is the used namespace, the value is the namespace    that is the common ancestor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NAMESPACE_USING
parameter_list|(
name|NODE
parameter_list|)
value|DECL_VINDEX (NAMESPACE_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* In a NAMESPACE_DECL, the DECL_INITIAL is used to record all users    of a namespace, to record the transitive closure of using namespace.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NAMESPACE_USERS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_INITIAL (NAMESPACE_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* In a NAMESPACE_DECL, the list of namespaces which have associated    themselves with this one.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NAMESPACE_ASSOCIATIONS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(NAMESPACE_DECL_CHECK (NODE)->decl_non_common.saved_tree)
end_define

begin_comment
comment|/* In a NAMESPACE_DECL, points to the original namespace if this is    a namespace alias.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NAMESPACE_ALIAS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|DECL_ABSTRACT_ORIGIN (NAMESPACE_DECL_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|ORIGINAL_NAMESPACE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_NAMESPACE_ALIAS (NODE) ? DECL_NAMESPACE_ALIAS (NODE) : (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE is the std namespace.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NAMESPACE_STD_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == NAMESPACE_DECL			\&& CP_DECL_CONTEXT (NODE) == global_namespace	\&& DECL_NAME (NODE) == std_identifier)
end_define

begin_comment
comment|/* In a TREE_LIST concatenating using directives, indicate indirect    directives  */
end_comment

begin_define
define|#
directive|define
name|TREE_INDIRECT_USING
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LIST_CHECK (NODE)->common.lang_flag_0)
end_define

begin_function_decl
specifier|extern
name|tree
name|decl_shadowed_for_var_lookup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|decl_shadowed_for_var_insert
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Non zero if this is a using decl for a dependent scope. */
end_comment

begin_define
define|#
directive|define
name|DECL_DEPENDENT_P
parameter_list|(
name|NODE
parameter_list|)
value|DECL_LANG_FLAG_0 (USING_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* The scope named in a using decl.  */
end_comment

begin_define
define|#
directive|define
name|USING_DECL_SCOPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_TYPE (USING_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* The decls named by a using decl.  */
end_comment

begin_define
define|#
directive|define
name|USING_DECL_DECLS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_INITIAL (USING_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* In a VAR_DECL, true if we have a shadowed local variable    in the shadowed var table for this VAR_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_HAS_SHADOWED_FOR_VAR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VAR_DECL_CHECK (NODE)->decl_with_vis.shadowed_for_var_p)
end_define

begin_comment
comment|/* In a VAR_DECL for a variable declared in a for statement,    this is the shadowed (local) variable.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SHADOWED_FOR_VAR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_HAS_SHADOWED_FOR_VAR_P(NODE) ? decl_shadowed_for_var_lookup (NODE) : NULL)
end_define

begin_define
define|#
directive|define
name|SET_DECL_SHADOWED_FOR_VAR
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(decl_shadowed_for_var_insert (NODE, VAL))
end_define

begin_comment
comment|/* In a FUNCTION_DECL, this is nonzero if this function was defined in    the class definition.  We have saved away the text of the function,    but have not yet processed it.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PENDING_INLINE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->u.f.pending_inline_p)
end_define

begin_comment
comment|/* If DECL_PENDING_INLINE_P holds, this is the saved text of the    function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PENDING_INLINE_INFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->u.f.u.pending_inline_info)
end_define

begin_comment
comment|/* For a TYPE_DECL: if this structure has many fields, we'll sort them    and put them into a TREE_VEC.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SORTED_FIELDS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (TYPE_DECL_CHECK (NODE))->u.f.u.sorted_fields)
end_define

begin_comment
comment|/* True if on the deferred_fns (see decl2.c) list.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DEFERRED_FN
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (DECL)->decl_flags.deferred)
end_define

begin_comment
comment|/* If non-NULL for a VAR_DECL, FUNCTION_DECL, TYPE_DECL or    TEMPLATE_DECL, the entity is either a template specialization (if    DECL_USE_TEMPLATE is non-zero) or the abstract instance of the    template itself.     In either case, DECL_TEMPLATE_INFO is a TREE_LIST, whose    TREE_PURPOSE is the TEMPLATE_DECL of which this entity is a    specialization or abstract instance.  The TREE_VALUE is the    template arguments used to specialize the template.        Consider:        template<typename T> struct S { friend void f(T) {} };     In this case, S<int>::f is, from the point of view of the compiler,    an instantiation of a template -- but, from the point of view of    the language, each instantiation of S results in a wholly unrelated    global function f.  In this case, DECL_TEMPLATE_INFO for S<int>::f    will be non-NULL, but DECL_USE_TEMPLATE will be zero.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_INFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (VAR_TEMPL_TYPE_OR_FUNCTION_DECL_CHECK (NODE)) \    ->decl_flags.u.template_info)
end_define

begin_comment
comment|/* For a VAR_DECL, indicates that the variable is actually a    non-static data member of anonymous union that has been promoted to    variable status.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ANON_UNION_VAR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_4 (VAR_DECL_CHECK (NODE)))
end_define

begin_comment
comment|/* Template information for a RECORD_TYPE or UNION_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_TEMPLATE_INFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (RECORD_OR_UNION_CHECK (NODE))->template_info)
end_define

begin_comment
comment|/* Template information for an ENUMERAL_TYPE.  Although an enumeration may    not be a primary template, it may be declared within the scope of a    primary template and the enumeration constants may depend on    non-type template parameters.  */
end_comment

begin_define
define|#
directive|define
name|ENUM_TEMPLATE_INFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SLOT_1 (ENUMERAL_TYPE_CHECK (NODE)))
end_define

begin_comment
comment|/* Template information for a template template parameter.  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE_TEMPLATE_PARM_TEMPLATE_INFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (BOUND_TEMPLATE_TEMPLATE_PARM_TYPE_CHECK (NODE)) \    ->template_info)
end_define

begin_comment
comment|/* Template information for an ENUMERAL_, RECORD_, or UNION_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_TEMPLATE_INFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == ENUMERAL_TYPE			\    ? ENUM_TEMPLATE_INFO (NODE) :			\    (TREE_CODE (NODE) == BOUND_TEMPLATE_TEMPLATE_PARM	\     ? TEMPLATE_TEMPLATE_PARM_TEMPLATE_INFO (NODE) :	\     (TYPE_LANG_SPECIFIC (NODE)				\      ? CLASSTYPE_TEMPLATE_INFO (NODE)			\      : NULL_TREE)))
end_define

begin_comment
comment|/* Set the template information for an ENUMERAL_, RECORD_, or    UNION_TYPE to VAL.  */
end_comment

begin_define
define|#
directive|define
name|SET_TYPE_TEMPLATE_INFO
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(TREE_CODE (NODE) == ENUMERAL_TYPE		\    ? (ENUM_TEMPLATE_INFO (NODE) = (VAL))	\    : (CLASSTYPE_TEMPLATE_INFO (NODE) = (VAL)))
end_define

begin_define
define|#
directive|define
name|TI_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_PURPOSE (NODE))
end_define

begin_define
define|#
directive|define
name|TI_ARGS
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VALUE (NODE))
end_define

begin_define
define|#
directive|define
name|TI_PENDING_TEMPLATE_FLAG
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1 (NODE)
end_define

begin_comment
comment|/* We use TREE_VECs to hold template arguments.  If there is only one    level of template arguments, then the TREE_VEC contains the    arguments directly.  If there is more than one level of template    arguments, then each entry in the TREE_VEC is itself a TREE_VEC,    containing the template arguments for a single level.  The first    entry in the outer TREE_VEC is the outermost level of template    parameters; the last is the innermost.     It is incorrect to ever form a template argument vector containing    only one level of arguments, but which is a TREE_VEC containing as    its only entry the TREE_VEC for that level.  */
end_comment

begin_comment
comment|/* Nonzero if the template arguments is actually a vector of vectors,    rather than just a vector.  */
end_comment

begin_define
define|#
directive|define
name|TMPL_ARGS_HAVE_MULTIPLE_LEVELS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(NODE&& TREE_VEC_ELT (NODE, 0)			\&& TREE_CODE (TREE_VEC_ELT (NODE, 0)) == TREE_VEC)
end_define

begin_comment
comment|/* The depth of a template argument vector.  When called directly by    the parser, we use a TREE_LIST rather than a TREE_VEC to represent    template arguments.  In fact, we may even see NULL_TREE if there    are no template arguments.  In both of those cases, there is only    one level of template arguments.  */
end_comment

begin_define
define|#
directive|define
name|TMPL_ARGS_DEPTH
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TMPL_ARGS_HAVE_MULTIPLE_LEVELS (NODE) ? TREE_VEC_LENGTH (NODE) : 1)
end_define

begin_comment
comment|/* The LEVELth level of the template ARGS.  The outermost level of    args is level 1, not level 0.  */
end_comment

begin_define
define|#
directive|define
name|TMPL_ARGS_LEVEL
parameter_list|(
name|ARGS
parameter_list|,
name|LEVEL
parameter_list|)
define|\
value|(TMPL_ARGS_HAVE_MULTIPLE_LEVELS (ARGS)	\    ? TREE_VEC_ELT (ARGS, (LEVEL) - 1) : (ARGS))
end_define

begin_comment
comment|/* Set the LEVELth level of the template ARGS to VAL.  This macro does    not work with single-level argument vectors.  */
end_comment

begin_define
define|#
directive|define
name|SET_TMPL_ARGS_LEVEL
parameter_list|(
name|ARGS
parameter_list|,
name|LEVEL
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(TREE_VEC_ELT (ARGS, (LEVEL) - 1) = (VAL))
end_define

begin_comment
comment|/* Accesses the IDXth parameter in the LEVELth level of the ARGS.  */
end_comment

begin_define
define|#
directive|define
name|TMPL_ARG
parameter_list|(
name|ARGS
parameter_list|,
name|LEVEL
parameter_list|,
name|IDX
parameter_list|)
define|\
value|(TREE_VEC_ELT (TMPL_ARGS_LEVEL (ARGS, LEVEL), IDX))
end_define

begin_comment
comment|/* Given a single level of template arguments in NODE, return the    number of arguments.  */
end_comment

begin_define
define|#
directive|define
name|NUM_TMPL_ARGS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VEC_LENGTH (NODE))
end_define

begin_comment
comment|/* Returns the innermost level of template arguments in ARGS.  */
end_comment

begin_define
define|#
directive|define
name|INNERMOST_TEMPLATE_ARGS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(get_innermost_template_args ((NODE), 1))
end_define

begin_comment
comment|/* The number of levels of template parameters given by NODE.  */
end_comment

begin_define
define|#
directive|define
name|TMPL_PARMS_DEPTH
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((HOST_WIDE_INT) TREE_INT_CST_LOW (TREE_PURPOSE (NODE)))
end_define

begin_comment
comment|/* The TEMPLATE_DECL instantiated or specialized by NODE.  This    TEMPLATE_DECL will be the immediate parent, not the most general    template.  For example, in:        template<class T> struct S { template<class U> void f(U); }     the FUNCTION_DECL for S<int>::f<double> will have, as its    DECL_TI_TEMPLATE, `template<class U> S<int>::f<U>'.     As a special case, for a member friend template of a template    class, this value will not be a TEMPLATE_DECL, but rather an    IDENTIFIER_NODE or OVERLOAD indicating the name of the template and    any explicit template arguments provided.  For example, in:       template<class T> struct S { friend void f<int>(int, double); }     the DECL_TI_TEMPLATE will be an IDENTIFIER_NODE for `f' and the    DECL_TI_ARGS will be {int}.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TI_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|TI_TEMPLATE (DECL_TEMPLATE_INFO (NODE))
end_define

begin_comment
comment|/* The template arguments used to obtain this decl from the most    general form of DECL_TI_TEMPLATE.  For the example given for    DECL_TI_TEMPLATE, the DECL_TI_ARGS will be {int, double}.  These    are always the full set of arguments required to instantiate this    declaration from the most general template specialized here.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TI_ARGS
parameter_list|(
name|NODE
parameter_list|)
value|TI_ARGS (DECL_TEMPLATE_INFO (NODE))
end_define

begin_comment
comment|/* The TEMPLATE_DECL associated with NODE, a class type.  Even if NODE    will be generated from a partial specialization, the TEMPLATE_DECL    referred to here will be the original template.  For example,    given:        template<typename T> struct S {};       template<typename T> struct S<T*> {};           the CLASSTPYE_TI_TEMPLATE for S<int*> will be S, not the S<T*>.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_TI_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|TI_TEMPLATE (CLASSTYPE_TEMPLATE_INFO (NODE))
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_TI_ARGS
parameter_list|(
name|NODE
parameter_list|)
value|TI_ARGS (CLASSTYPE_TEMPLATE_INFO (NODE))
end_define

begin_comment
comment|/* For a template instantiation TYPE, returns the TYPE corresponding    to the primary template.  Otherwise returns TYPE itself.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_PRIMARY_TEMPLATE_TYPE
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|((CLASSTYPE_USE_TEMPLATE ((TYPE))					\&& !CLASSTYPE_TEMPLATE_SPECIALIZATION ((TYPE)))			\    ? TREE_TYPE (DECL_TEMPLATE_RESULT (DECL_PRIMARY_TEMPLATE		\ 				      (CLASSTYPE_TI_TEMPLATE ((TYPE))))) \    : (TYPE))
end_define

begin_comment
comment|/* Like CLASS_TI_TEMPLATE, but also works for ENUMERAL_TYPEs.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_TI_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TI_TEMPLATE (TYPE_TEMPLATE_INFO (NODE)))
end_define

begin_comment
comment|/* Like DECL_TI_ARGS, but for an ENUMERAL_, RECORD_, or UNION_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_TI_ARGS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TI_ARGS (TYPE_TEMPLATE_INFO (NODE)))
end_define

begin_define
define|#
directive|define
name|INNERMOST_TEMPLATE_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VALUE (NODE)
end_define

begin_comment
comment|/* Nonzero if NODE (a TEMPLATE_DECL) is a member template, in the    sense of [temp.mem].  */
end_comment

begin_define
define|#
directive|define
name|DECL_MEMBER_TEMPLATE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_1 (TEMPLATE_DECL_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero if the NODE corresponds to the template parameters for a    member template, whose inline definition is being processed after    the class definition is complete.  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE_PARMS_FOR_INLINE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1 (NODE)
end_define

begin_comment
comment|/* In a FUNCTION_DECL, the saved language-specific per-function data.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SAVED_FUNCTION_DATA
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (FUNCTION_DECL_CHECK (NODE))	\    ->u.f.u.saved_language_function)
end_define

begin_comment
comment|/* Indicates an indirect_expr is for converting a reference.  */
end_comment

begin_define
define|#
directive|define
name|REFERENCE_REF_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (INDIRECT_REF_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|NEW_EXPR_USE_GLOBAL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (NEW_EXPR_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|DELETE_EXPR_USE_GLOBAL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (DELETE_EXPR_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|DELETE_EXPR_USE_VEC
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_1 (DELETE_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* Indicates that this is a non-dependent COMPOUND_EXPR which will    resolve to a function call.  */
end_comment

begin_define
define|#
directive|define
name|COMPOUND_EXPR_OVERLOADED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (COMPOUND_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* In a CALL_EXPR appearing in a template, true if Koenig lookup    should be performed at instantiation time.  */
end_comment

begin_define
define|#
directive|define
name|KOENIG_LOOKUP_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (CALL_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* Indicates whether a string literal has been parenthesized. Such    usages are disallowed in certain circumstances.  */
end_comment

begin_define
define|#
directive|define
name|PAREN_STRING_LITERAL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (STRING_CST_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if this AGGR_INIT_EXPR provides for initialization via a    constructor call, rather than an ordinary function call.  */
end_comment

begin_define
define|#
directive|define
name|AGGR_INIT_VIA_CTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (AGGR_INIT_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* The TYPE_MAIN_DECL for a class template type is a TYPE_DECL, not a    TEMPLATE_DECL.  This macro determines whether or not a given class    type is really a template type, as opposed to an instantiation or    specialization of one.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_IS_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_TEMPLATE_INFO (NODE)    \&& !CLASSTYPE_USE_TEMPLATE (NODE) \&& PRIMARY_TEMPLATE_P (CLASSTYPE_TI_TEMPLATE (NODE)))
end_define

begin_comment
comment|/* The name used by the user to name the typename type.  Typically,    this is an IDENTIFIER_NODE, and the same as the DECL_NAME on the    corresponding TYPE_DECL.  However, this may also be a    TEMPLATE_ID_EXPR if we had something like `typename X::Y<T>'.  */
end_comment

begin_define
define|#
directive|define
name|TYPENAME_TYPE_FULLNAME
parameter_list|(
name|NODE
parameter_list|)
value|(TYPENAME_TYPE_CHECK (NODE))->type.values
end_define

begin_comment
comment|/* True if a TYPENAME_TYPE was declared as an "enum".  */
end_comment

begin_define
define|#
directive|define
name|TYPENAME_IS_ENUM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_0 (TYPENAME_TYPE_CHECK (NODE)))
end_define

begin_comment
comment|/* True if a TYPENAME_TYPE was declared as a "class", "struct", or    "union".  */
end_comment

begin_define
define|#
directive|define
name|TYPENAME_IS_CLASS_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_1 (TYPENAME_TYPE_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero in INTEGER_CST means that this int is negative by dint of    using a twos-complement negated operand.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NEGATED_INT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (INTEGER_CST_CHECK (NODE))
end_define

begin_comment
comment|/* [class.virtual]     A class that declares or inherits a virtual function is called a    polymorphic class.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_POLYMORPHIC_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_2 (NODE))
end_define

begin_comment
comment|/* Nonzero if this class has a virtual function table pointer.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_CONTAINS_VPTR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_POLYMORPHIC_P (NODE) || CLASSTYPE_VBASECLASSES (NODE))
end_define

begin_comment
comment|/* This flag is true of a local VAR_DECL if it was declared in a for    statement, but we are no longer in the scope of the for.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DEAD_FOR_LOCAL
parameter_list|(
name|NODE
parameter_list|)
value|DECL_LANG_FLAG_7 (VAR_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* This flag is set on a VAR_DECL that is a DECL_DEAD_FOR_LOCAL    if we already emitted a warning about using it.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ERROR_REPORTED
parameter_list|(
name|NODE
parameter_list|)
value|DECL_LANG_FLAG_0 (VAR_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE is a FUNCTION_DECL (for a function with global    scope) declared in a local scope.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LOCAL_FUNCTION_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|DECL_LANG_FLAG_0 (FUNCTION_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE is a DECL which we know about but which has not    been explicitly declared, such as a built-in function or a friend    declared inside a class.  In the latter case DECL_HIDDEN_FRIEND_P    will be set.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ANTICIPATED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (DECL_COMMON_CHECK (NODE))->decl_flags.anticipated_p)
end_define

begin_comment
comment|/* Nonzero if NODE is a FUNCTION_DECL which was declared as a friend    within a class but has not been declared in the surrounding scope.    The function is invisible except via argument dependent lookup.  */
end_comment

begin_define
define|#
directive|define
name|DECL_HIDDEN_FRIEND_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (DECL_COMMON_CHECK (NODE))->decl_flags.hidden_friend_p)
end_define

begin_comment
comment|/* Nonzero if DECL has been declared threadprivate by    #pragma omp threadprivate.  */
end_comment

begin_define
define|#
directive|define
name|CP_DECL_THREADPRIVATE_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (VAR_DECL_CHECK (DECL))->decl_flags.threadprivate_p)
end_define

begin_comment
comment|/* Record whether a typedef for type `int' was actually `signed int'.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPEDEF_EXPLICITLY_SIGNED
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_1 (EXP)
end_define

begin_comment
comment|/* Returns nonzero if DECL has external linkage, as specified by the    language standard.  (This predicate may hold even when the    corresponding entity is not actually given external linkage in the    object file; see decl_linkage for details.)  */
end_comment

begin_define
define|#
directive|define
name|DECL_EXTERNAL_LINKAGE_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(decl_linkage (DECL) == lk_external)
end_define

begin_comment
comment|/* Keep these codes in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|INTEGRAL_CODE_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == ENUMERAL_TYPE	\    || (CODE) == BOOLEAN_TYPE	\    || (CODE) == INTEGER_TYPE)
end_define

begin_comment
comment|/* [basic.fundamental]     Types  bool, char, wchar_t, and the signed and unsigned integer types    are collectively called integral types.     Note that INTEGRAL_TYPE_P, as defined in tree.h, allows enumeration    types as well, which is incorrect in C++.  Keep these checks in    ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|CP_INTEGRAL_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == BOOLEAN_TYPE		\    || TREE_CODE (TYPE) == INTEGER_TYPE)
end_define

begin_comment
comment|/* Returns true if TYPE is an integral or enumeration name.  Keep    these checks in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|INTEGRAL_OR_ENUMERATION_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == ENUMERAL_TYPE || CP_INTEGRAL_TYPE_P (TYPE))
end_define

begin_comment
comment|/* [basic.fundamental]     Integral and floating types are collectively called arithmetic    types.       As a GNU extension, we also accept complex types.     Keep these checks in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|ARITHMETIC_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(CP_INTEGRAL_TYPE_P (TYPE) \    || TREE_CODE (TYPE) == REAL_TYPE \    || TREE_CODE (TYPE) == COMPLEX_TYPE)
end_define

begin_comment
comment|/* [basic.types]     Arithmetic types, enumeration types, pointer types, and    pointer-to-member types, are collectively called scalar types.        Keep these checks in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|SCALAR_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TYPE_PTRMEM_P (TYPE)				\    || TREE_CODE (TYPE) == ENUMERAL_TYPE		\    || ARITHMETIC_TYPE_P (TYPE)			\    || TYPE_PTR_P (TYPE)				\    || TYPE_PTRMEMFUNC_P (TYPE))
end_define

begin_comment
comment|/* [dcl.init.aggr]     An aggregate is an array or a class with no user-declared    constructors, no private or protected non-static data members, no    base classes, and no virtual functions.     As an extension, we also treat vectors as aggregates.  Keep these    checks in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|CP_AGGREGATE_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == VECTOR_TYPE				\    ||TREE_CODE (TYPE) == ARRAY_TYPE				\    || (CLASS_TYPE_P (TYPE)&& !CLASSTYPE_NON_AGGREGATE (TYPE)))
end_define

begin_comment
comment|/* Nonzero for a class type means that the class type has a    user-declared constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_FLAG_1 (NODE))
end_define

begin_comment
comment|/* When appearing in an INDIRECT_REF, it means that the tree structure    underneath is actually a call to a constructor.  This is needed    when the constructor must initialize local storage (which can    be automatically destroyed), rather than allowing it to allocate    space from the heap.     When appearing in a SAVE_EXPR, it means that underneath    is a call to a constructor.     When appearing in a CONSTRUCTOR, the expression is a    compound literal.     When appearing in a FIELD_DECL, it means that this field    has been duly initialized in its constructor.  */
end_comment

begin_define
define|#
directive|define
name|TREE_HAS_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_4 (NODE))
end_define

begin_comment
comment|/* True if NODE is a brace-enclosed initializer.  */
end_comment

begin_define
define|#
directive|define
name|BRACE_ENCLOSED_INITIALIZER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == CONSTRUCTOR&& !TREE_TYPE (NODE))
end_define

begin_comment
comment|/* True if NODE is a compound-literal, i.e., a brace-enclosed    initializer cast to a particular type.  */
end_comment

begin_define
define|#
directive|define
name|COMPOUND_LITERAL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == CONSTRUCTOR&& TREE_HAS_CONSTRUCTOR (NODE))
end_define

begin_define
define|#
directive|define
name|EMPTY_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CODE (NODE) == CONSTRUCTOR \&& VEC_empty (constructor_elt, \ 						 CONSTRUCTOR_ELTS (NODE)) \&& !TREE_HAS_CONSTRUCTOR (NODE))
end_define

begin_comment
comment|/* Nonzero means that an object of this type can not be initialized using    an initializer list.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NON_AGGREGATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->non_aggregate)
end_define

begin_define
define|#
directive|define
name|TYPE_NON_AGGREGATE_CLASS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IS_AGGR_TYPE (NODE)&& CLASSTYPE_NON_AGGREGATE (NODE))
end_define

begin_comment
comment|/* Nonzero if there is a user-defined X::op=(x&) for this class.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_COMPLEX_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->has_complex_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_COMPLEX_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->has_complex_init_ref)
end_define

begin_comment
comment|/* Nonzero if TYPE has a trivial destructor.  From [class.dtor]:       A destructor is trivial if it is an implicitly declared      destructor and if:         - all of the direct base classes of its class have trivial 	 destructors,         - for all of the non-static data members of its class that are 	 of class type (or array thereof), each such class has a 	 trivial destructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_TRIVIAL_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(!TYPE_HAS_NONTRIVIAL_DESTRUCTOR (NODE))
end_define

begin_comment
comment|/* Nonzero for _TYPE node means that this type does not have a trivial    destructor.  Therefore, destroying an object of this type will    involve a call to a destructor.  This can apply to objects of    ARRAY_TYPE is the type of the elements needs a destructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_NONTRIVIAL_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_FLAG_4 (NODE))
end_define

begin_comment
comment|/* Nonzero for class type means that copy initialization of this type can use    a bitwise copy.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_TRIVIAL_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_HAS_INIT_REF (NODE)&& ! TYPE_HAS_COMPLEX_INIT_REF (NODE))
end_define

begin_comment
comment|/* Nonzero for class type means that assignment of this type can use    a bitwise copy.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_TRIVIAL_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_HAS_ASSIGN_REF (NODE)&& ! TYPE_HAS_COMPLEX_ASSIGN_REF (NODE))
end_define

begin_comment
comment|/* Returns true if NODE is a pointer-to-data-member.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTRMEM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == OFFSET_TYPE)
end_define

begin_comment
comment|/* Returns true if NODE is a pointer.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == POINTER_TYPE)
end_define

begin_comment
comment|/* Returns true if NODE is an object type:       [basic.types]       An object type is a (possibly cv-qualified) type that is not a      function type, not a reference type, and not a void type.     Keep these checks in ascending order, for speed.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OBJ_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) != REFERENCE_TYPE		\&& TREE_CODE (NODE) != VOID_TYPE		\&& TREE_CODE (NODE) != FUNCTION_TYPE		\&& TREE_CODE (NODE) != METHOD_TYPE)
end_define

begin_comment
comment|/* Returns true if NODE is a pointer to an object.  Keep these checks    in ascending tree code order.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTROB_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_PTR_P (NODE)&& TYPE_OBJ_P (TREE_TYPE (NODE)))
end_define

begin_comment
comment|/* Returns true if NODE is a reference to an object.  Keep these checks    in ascending tree code order.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_REF_OBJ_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == REFERENCE_TYPE&& TYPE_OBJ_P (TREE_TYPE (NODE)))
end_define

begin_comment
comment|/* Returns true if NODE is a pointer to an object, or a pointer to    void.  Keep these checks in ascending tree code order.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTROBV_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_PTR_P (NODE)						\&& !(TREE_CODE (TREE_TYPE (NODE)) == FUNCTION_TYPE		\ 	|| TREE_CODE (TREE_TYPE (NODE)) == METHOD_TYPE))
end_define

begin_comment
comment|/* Returns true if NODE is a pointer to function.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTRFN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == POINTER_TYPE			\&& TREE_CODE (TREE_TYPE (NODE)) == FUNCTION_TYPE)
end_define

begin_comment
comment|/* Returns true if NODE is a reference to function.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_REFFN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == REFERENCE_TYPE			\&& TREE_CODE (TREE_TYPE (NODE)) == FUNCTION_TYPE)
end_define

begin_comment
comment|/* Nonzero for _TYPE node means that this type is a pointer to member    function type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTRMEMFUNC_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == RECORD_TYPE	\&& TYPE_LANG_SPECIFIC (NODE)		\&& TYPE_PTRMEMFUNC_FLAG (NODE))
end_define

begin_define
define|#
directive|define
name|TYPE_PTRMEMFUNC_FLAG
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->ptrmemfunc_flag)
end_define

begin_comment
comment|/* Returns true if NODE is a pointer-to-member.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTR_TO_MEMBER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_PTRMEM_P (NODE) || TYPE_PTRMEMFUNC_P (NODE))
end_define

begin_comment
comment|/* Indicates when overload resolution may resolve to a pointer to    member function. [expr.unary.op]/3 */
end_comment

begin_define
define|#
directive|define
name|PTRMEM_OK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (TREE_CHECK2 ((NODE), ADDR_EXPR, OFFSET_REF))
end_define

begin_comment
comment|/* Get the POINTER_TYPE to the METHOD_TYPE associated with this    pointer to member function.  TYPE_PTRMEMFUNC_P _must_ be true,    before using this macro.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTRMEMFUNC_FN_TYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_TYPE (TYPE_FIELDS (NODE)))
end_define

begin_comment
comment|/* Returns `A' for a type like `int (A::*)(double)' */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTRMEMFUNC_OBJECT_TYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TYPE_METHOD_BASETYPE (TREE_TYPE (TYPE_PTRMEMFUNC_FN_TYPE (NODE)))
end_define

begin_comment
comment|/* These are use to manipulate the canonical RECORD_TYPE from the    hashed POINTER_TYPE, and can only be used on the POINTER_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_GET_PTRMEMFUNC_TYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE) ? LANG_TYPE_PTRMEM_CHECK (NODE)->record : NULL)
end_define

begin_define
define|#
directive|define
name|TYPE_SET_PTRMEMFUNC_TYPE
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do {									\     if (TYPE_LANG_SPECIFIC (NODE) == NULL)				\       {									\ 	TYPE_LANG_SPECIFIC (NODE) = GGC_CNEWVAR				\ 	 (struct lang_type, sizeof (struct lang_type_ptrmem));		\ 	TYPE_LANG_SPECIFIC (NODE)->u.ptrmem.h.is_lang_type_class = 0;	\       }									\     TYPE_LANG_SPECIFIC (NODE)->u.ptrmem.record = (VALUE);		\   } while (0)
end_define

begin_comment
comment|/* For a pointer-to-member type of the form `T X::*', this is `X'.    For a type like `void (X::*)() const', this type is `X', not `const    X'.  To get at the `const X' you have to look at the    TYPE_PTRMEM_POINTED_TO_TYPE; there, the first parameter will have    type `const X*'.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTRMEM_CLASS_TYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_PTRMEM_P (NODE)					\    ? TYPE_OFFSET_BASETYPE (NODE)		\    : TYPE_PTRMEMFUNC_OBJECT_TYPE (NODE))
end_define

begin_comment
comment|/* For a pointer-to-member type of the form `T X::*', this is `T'.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PTRMEM_POINTED_TO_TYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_PTRMEM_P (NODE)				\     ? TREE_TYPE (NODE)					\     : TREE_TYPE (TYPE_PTRMEMFUNC_FN_TYPE (NODE)))
end_define

begin_comment
comment|/* For a pointer-to-member constant `X::Y' this is the RECORD_TYPE for    `X'.  */
end_comment

begin_define
define|#
directive|define
name|PTRMEM_CST_CLASS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TYPE_PTRMEM_CLASS_TYPE (TREE_TYPE (PTRMEM_CST_CHECK (NODE)))
end_define

begin_comment
comment|/* For a pointer-to-member constant `X::Y' this is the _DECL for    `Y'.  */
end_comment

begin_define
define|#
directive|define
name|PTRMEM_CST_MEMBER
parameter_list|(
name|NODE
parameter_list|)
value|(((ptrmem_cst_t)PTRMEM_CST_CHECK (NODE))->member)
end_define

begin_comment
comment|/* The expression in question for a TYPEOF_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPEOF_TYPE_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPEOF_TYPE_CHECK (NODE))->type.values
end_define

begin_comment
comment|/* Nonzero for VAR_DECL and FUNCTION_DECL node means that `extern' was    specified in its declaration.  This can also be set for an    erroneously declared PARM_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THIS_EXTERN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|DECL_LANG_FLAG_2 (VAR_FUNCTION_OR_PARM_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero for VAR_DECL and FUNCTION_DECL node means that `static' was    specified in its declaration.  This can also be set for an    erroneously declared PARM_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THIS_STATIC
parameter_list|(
name|NODE
parameter_list|)
define|\
value|DECL_LANG_FLAG_6 (VAR_FUNCTION_OR_PARM_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero for FIELD_DECL node means that this field is a base class    of the parent object, as opposed to a member field.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FIELD_IS_BASE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|DECL_LANG_FLAG_6 (FIELD_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if TYPE is an anonymous union or struct type.  We have to use a    flag for this because "A union for which objects or pointers are    declared is not an anonymous union" [class.union].  */
end_comment

begin_define
define|#
directive|define
name|ANON_AGGR_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASS_TYPE_P (NODE)&& LANG_TYPE_CLASS_CHECK (NODE)->anon_aggr)
end_define

begin_define
define|#
directive|define
name|SET_ANON_AGGR_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->anon_aggr = 1)
end_define

begin_comment
comment|/* Nonzero if TYPE is an anonymous union type.  */
end_comment

begin_define
define|#
directive|define
name|ANON_UNION_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == UNION_TYPE&& ANON_AGGR_TYPE_P (NODE))
end_define

begin_define
define|#
directive|define
name|UNKNOWN_TYPE
value|LANG_TYPE
end_define

begin_comment
comment|/* Define fields and accessors for nodes representing declared names.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_WAS_ANONYMOUS
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_TYPE_CLASS_CHECK (NODE)->was_anonymous)
end_define

begin_comment
comment|/* C++: all of these are overloaded!  These apply only to TYPE_DECLs.  */
end_comment

begin_comment
comment|/* The format of each node in the DECL_FRIENDLIST is as follows:     The TREE_PURPOSE will be the name of a function, i.e., an    IDENTIFIER_NODE.  The TREE_VALUE will be itself a TREE_LIST, whose    TREE_VALUEs are friends with the given name.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRIENDLIST
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_INITIAL (NODE))
end_define

begin_define
define|#
directive|define
name|FRIEND_NAME
parameter_list|(
name|LIST
parameter_list|)
value|(TREE_PURPOSE (LIST))
end_define

begin_define
define|#
directive|define
name|FRIEND_DECLS
parameter_list|(
name|LIST
parameter_list|)
value|(TREE_VALUE (LIST))
end_define

begin_comment
comment|/* The DECL_ACCESS, if non-NULL, is a TREE_LIST.  The TREE_PURPOSE of    each node is a type; the TREE_VALUE is the access granted for this    DECL in that type.  The DECL_ACCESS is set by access declarations.    For example, if a member that would normally be public in a    derived class is made protected, then the derived class and the    protected_access_node will appear in the DECL_ACCESS for the node.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ACCESS
parameter_list|(
name|NODE
parameter_list|)
value|(LANG_DECL_U2_CHECK (NODE, 0)->access)
end_define

begin_comment
comment|/* Nonzero if the FUNCTION_DECL is a global constructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_GLOBAL_CTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.global_ctor_p)
end_define

begin_comment
comment|/* Nonzero if the FUNCTION_DECL is a global destructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_GLOBAL_DTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.global_dtor_p)
end_define

begin_comment
comment|/* Accessor macros for C++ template decl nodes.  */
end_comment

begin_comment
comment|/* The DECL_TEMPLATE_PARMS are a list.  The TREE_PURPOSE of each node    is a INT_CST whose TREE_INT_CST_LOW indicates the level of the    template parameters, with 1 being the outermost set of template    parameters.  The TREE_VALUE is a vector, whose elements are the    template parameters at each level.  Each element in the vector is a    TREE_LIST, whose TREE_VALUE is a PARM_DECL (if the parameter is a    non-type parameter), or a TYPE_DECL (if the parameter is a type    parameter).  The TREE_PURPOSE is the default value, if any.  The    TEMPLATE_PARM_INDEX for the parameter is available as the    DECL_INITIAL (for a PARM_DECL) or as the TREE_TYPE (for a    TYPE_DECL).  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_NON_COMMON_CHECK (NODE)->decl_non_common.arguments
end_define

begin_define
define|#
directive|define
name|DECL_INNERMOST_TEMPLATE_PARMS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|INNERMOST_TEMPLATE_PARMS (DECL_TEMPLATE_PARMS (NODE))
end_define

begin_define
define|#
directive|define
name|DECL_NTPARMS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_VEC_LENGTH (DECL_INNERMOST_TEMPLATE_PARMS (NODE))
end_define

begin_comment
comment|/* For function, method, class-data templates.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_RESULT
parameter_list|(
name|NODE
parameter_list|)
value|DECL_RESULT_FLD (NODE)
end_define

begin_comment
comment|/* For a static member variable template, the    DECL_TEMPLATE_INSTANTIATIONS list contains the explicitly and    implicitly generated instantiations of the variable.  There are no    partial instantiations of static member variables, so all of these    will be full instantiations.     For a class template the DECL_TEMPLATE_INSTANTIATIONS lists holds    all instantiations and specializations of the class type, including    partial instantiations and partial specializations.     In both cases, the TREE_PURPOSE of each node contains the arguments    used; the TREE_VALUE contains the generated variable.  The template    arguments are always complete.  For example, given:        template<class T> struct S1 { 	template<class U> struct S2 {}; 	template<class U> struct S2<U*> {};       };     the record for the partial specialization will contain, as its    argument list, { {T}, {U*} }, and will be on the    DECL_TEMPLATE_INSTANTIATIONS list for `template<class T> template<class U> struct S1<T>::S2'.     This list is not used for function templates.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_INSTANTIATIONS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_VINDEX (NODE)
end_define

begin_comment
comment|/* For a function template, the DECL_TEMPLATE_SPECIALIZATIONS lists    contains all instantiations and specializations of the function,    including partial instantiations.  For a partial instantiation    which is a specialization, this list holds only full    specializations of the template that are instantiations of the    partial instantiation.  For example, given:        template<class T> struct S { 	template<class U> void f(U); 	template<> void f(T);       };     the `S<int>::f<int>(int)' function will appear on the    DECL_TEMPLATE_SPECIALIZATIONS list for both `template<class T>    template<class U> void S<T>::f(U)' and `template<class T> void    S<int>::f(T)'.  In the latter case, however, it will have only the    innermost set of arguments (T, in this case).  The DECL_TI_TEMPLATE    for the function declaration will point at the specialization, not    the fully general template.     For a class template, this list contains the partial    specializations of this template.  (Full specializations are not    recorded on this list.)  The TREE_PURPOSE holds the arguments used    in the partial specialization (e.g., for `template<class T> struct    S<T*, int>' this will be `T*'.)  The arguments will also include    any outer template arguments.  The TREE_VALUE holds the innermost    template parameters for the specialization (e.g., `T' in the    example above.)  The TREE_TYPE is the _TYPE node for the partial    specialization.     This list is not used for static variable templates.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_SPECIALIZATIONS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_SIZE (NODE)
end_define

begin_comment
comment|/* Nonzero for a DECL which is actually a template parameter.  Keep    these checks in ascending tree code order.   */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_PARM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_0 (NODE)			\&& (TREE_CODE (NODE) == CONST_DECL		\        || TREE_CODE (NODE) == PARM_DECL		\        || TREE_CODE (NODE) == TYPE_DECL		\        || TREE_CODE (NODE) == TEMPLATE_DECL))
end_define

begin_comment
comment|/* Mark NODE as a template parameter.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_TEMPLATE_PARM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_0 (NODE) = 1)
end_define

begin_comment
comment|/* Nonzero if NODE is a template template parameter.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_TEMPLATE_PARM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TEMPLATE_DECL&& DECL_TEMPLATE_PARM_P (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE is a TEMPLATE_DECL representing an    UNBOUND_CLASS_TEMPLATE tree node.  */
end_comment

begin_define
define|#
directive|define
name|DECL_UNBOUND_CLASS_TEMPLATE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TEMPLATE_DECL&& !DECL_TEMPLATE_RESULT (NODE))
end_define

begin_define
define|#
directive|define
name|DECL_FUNCTION_TEMPLATE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TEMPLATE_DECL \&& !DECL_UNBOUND_CLASS_TEMPLATE_P (NODE) \&& TREE_CODE (DECL_TEMPLATE_RESULT (NODE)) == FUNCTION_DECL)
end_define

begin_comment
comment|/* Nonzero for a DECL that represents a template class.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CLASS_TEMPLATE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TEMPLATE_DECL \&& !DECL_UNBOUND_CLASS_TEMPLATE_P (NODE) \&& TREE_CODE (DECL_TEMPLATE_RESULT (NODE)) == TYPE_DECL \&& !DECL_TEMPLATE_TEMPLATE_PARM_P (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE which declares a type.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DECLARES_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TYPE_DECL || DECL_CLASS_TEMPLATE_P (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE is the typedef implicitly generated for a type when    the type is declared.  In C++, `struct S {};' is roughly    equivalent to `struct S {}; typedef struct S S;' in C.    DECL_IMPLICIT_TYPEDEF_P will hold for the typedef indicated in this    example.  In C++, there is a second implicit typedef for each    class, in the scope of `S' itself, so that you can say `S::S'.    DECL_SELF_REFERENCE_P will hold for that second typedef.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IMPLICIT_TYPEDEF_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TYPE_DECL&& DECL_LANG_FLAG_2 (NODE))
end_define

begin_define
define|#
directive|define
name|SET_DECL_IMPLICIT_TYPEDEF_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_2 (NODE) = 1)
end_define

begin_define
define|#
directive|define
name|DECL_SELF_REFERENCE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TYPE_DECL&& DECL_LANG_FLAG_4 (NODE))
end_define

begin_define
define|#
directive|define
name|SET_DECL_SELF_REFERENCE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_4 (NODE) = 1)
end_define

begin_comment
comment|/* A `primary' template is one that has its own template header.  A    member function of a class template is a template, but not primary.    A member template is primary.  Friend templates are primary, too.  */
end_comment

begin_comment
comment|/* Returns the primary template corresponding to these parameters.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PRIMARY_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_TYPE (DECL_INNERMOST_TEMPLATE_PARMS (NODE)))
end_define

begin_comment
comment|/* Returns nonzero if NODE is a primary template.  */
end_comment

begin_define
define|#
directive|define
name|PRIMARY_TEMPLATE_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_PRIMARY_TEMPLATE (NODE) == (NODE))
end_define

begin_comment
comment|/* Non-zero iff NODE is a specialization of a template.  The value    indicates the type of specializations:       1=implicit instantiation       2=partial or explicit specialization, e.g.:          template<> int min<int> (int, int),       3=explicit instantiation, e.g.:            template int min<int> (int, int);     Note that NODE will be marked as a specialization even if the    template it is instantiating is not a primary template.  For    example, given:       template<typename T> struct O {         void f();        struct I {};       };         both O<int>::f and O<int>::I will be marked as instantiations.     If DECL_USE_TEMPLATE is non-zero, then DECL_TEMPLATE_INFO will also    be non-NULL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_USE_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.use_template)
end_define

begin_comment
comment|/* Like DECL_USE_TEMPLATE, but for class types.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_USE_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_TYPE_CLASS_CHECK (NODE)->use_template)
end_define

begin_comment
comment|/* True if NODE is a specialization of a primary template.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SPECIALIZATION_OF_PRIMARY_TEMPLATE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASS_TYPE_P (NODE)						\&& CLASSTYPE_USE_TEMPLATE (NODE)				\&& PRIMARY_TEMPLATE_P (CLASSTYPE_TI_TEMPLATE (arg)))
end_define

begin_define
define|#
directive|define
name|DECL_TEMPLATE_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_USE_TEMPLATE (NODE)& 1)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_TEMPLATE_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE (NODE)& 1)
end_define

begin_define
define|#
directive|define
name|DECL_TEMPLATE_SPECIALIZATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_USE_TEMPLATE (NODE) == 2)
end_define

begin_define
define|#
directive|define
name|SET_DECL_TEMPLATE_SPECIALIZATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_USE_TEMPLATE (NODE) = 2)
end_define

begin_comment
comment|/* Returns true for an explicit or partial specialization of a class    template.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_TEMPLATE_SPECIALIZATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE (NODE) == 2)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_TEMPLATE_SPECIALIZATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE (NODE) = 2)
end_define

begin_define
define|#
directive|define
name|DECL_IMPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_USE_TEMPLATE (NODE) == 1)
end_define

begin_define
define|#
directive|define
name|SET_DECL_IMPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_USE_TEMPLATE (NODE) = 1)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_IMPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE (NODE) == 1)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_IMPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE (NODE) = 1)
end_define

begin_define
define|#
directive|define
name|DECL_EXPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_USE_TEMPLATE (NODE) == 3)
end_define

begin_define
define|#
directive|define
name|SET_DECL_EXPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_USE_TEMPLATE (NODE) = 3)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_EXPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE (NODE) == 3)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_EXPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE (NODE) = 3)
end_define

begin_comment
comment|/* Nonzero if DECL is a friend function which is an instantiation    from the point of view of the compiler, but not from the point of    view of the language.  For example given:       template<class T> struct S { friend void f(T) {}; };    the declaration of `void f(int)' generated when S<int> is    instantiated will not be a DECL_TEMPLATE_INSTANTIATION, but will be    a DECL_FRIEND_PSUEDO_TEMPLATE_INSTANTIATION.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRIEND_PSEUDO_TEMPLATE_INSTANTIATION
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_TEMPLATE_INFO (DECL)&& !DECL_USE_TEMPLATE (DECL))
end_define

begin_comment
comment|/* Nonzero iff we are currently processing a declaration for an    entity with its own template parameter list, and which is not a    full specialization.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSING_REAL_TEMPLATE_DECL_P
parameter_list|()
define|\
value|(processing_template_decl> template_class_depth (current_scope ()))
end_define

begin_comment
comment|/* Nonzero if this VAR_DECL or FUNCTION_DECL has already been    instantiated, i.e. its definition has been generated from the    pattern given in the template.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_INSTANTIATED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|DECL_LANG_FLAG_1 (VAR_OR_FUNCTION_DECL_CHECK (NODE))
end_define

begin_comment
comment|/* We know what we're doing with this decl now.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INTERFACE_KNOWN
parameter_list|(
name|NODE
parameter_list|)
value|DECL_LANG_FLAG_5 (NODE)
end_define

begin_comment
comment|/* DECL_EXTERNAL must be set on a decl until the decl is actually emitted,    so that assemble_external will work properly.  So we have this flag to    tell us whether the decl is really not external.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NOT_REALLY_EXTERN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.not_really_extern)
end_define

begin_define
define|#
directive|define
name|DECL_REALLY_EXTERN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_EXTERNAL (NODE)&& ! DECL_NOT_REALLY_EXTERN (NODE))
end_define

begin_comment
comment|/* A thunk is a stub function.     A thunk is an alternate entry point for an ordinary FUNCTION_DECL.    The address of the ordinary FUNCTION_DECL is given by the    DECL_INITIAL, which is always an ADDR_EXPR whose operand is a    FUNCTION_DECL.  The job of the thunk is to either adjust the this    pointer before transferring control to the FUNCTION_DECL, or call    FUNCTION_DECL and then adjust the result value. Note, the result    pointer adjusting thunk must perform a call to the thunked    function, (or be implemented via passing some invisible parameter    to the thunked function, which is modified to perform the    adjustment just before returning).     A thunk may perform either, or both, of the following operations:     o Adjust the this or result pointer by a constant offset.    o Adjust the this or result pointer by looking up a vcall or vbase offset      in the vtable.     A this pointer adjusting thunk converts from a base to a derived    class, and hence adds the offsets. A result pointer adjusting thunk    converts from a derived class to a base, and hence subtracts the    offsets.  If both operations are performed, then the constant    adjustment is performed first for this pointer adjustment and last    for the result pointer adjustment.     The constant adjustment is given by THUNK_FIXED_OFFSET.  If the    vcall or vbase offset is required, THUNK_VIRTUAL_OFFSET is    used. For this pointer adjusting thunks, it is the vcall offset    into the vtable.  For result pointer adjusting thunks it is the    binfo of the virtual base to convert to.  Use that binfo's vbase    offset.     It is possible to have equivalent covariant thunks.  These are    distinct virtual covariant thunks whose vbase offsets happen to    have the same value.  THUNK_ALIAS is used to pick one as the    canonical thunk, which will get all the this pointer adjusting    thunks attached to it.  */
end_comment

begin_comment
comment|/* An integer indicating how many bytes should be subtracted from the    this or result pointer when this function is called.  */
end_comment

begin_define
define|#
directive|define
name|THUNK_FIXED_OFFSET
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (THUNK_FUNCTION_CHECK (DECL))->u.f.u5.fixed_offset)
end_define

begin_comment
comment|/* A tree indicating how to perform the virtual adjustment. For a this    adjusting thunk it is the number of bytes to be added to the vtable    to find the vcall offset. For a result adjusting thunk, it is the    binfo of the relevant virtual base.  If NULL, then there is no    virtual adjust.  (The vptr is always located at offset zero from    the this or result pointer.)  (If the covariant type is within the    class hierarchy being laid out, the vbase index is not yet known    at the point we need to create the thunks, hence the need to use    binfos.)  */
end_comment

begin_define
define|#
directive|define
name|THUNK_VIRTUAL_OFFSET
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(LANG_DECL_U2_CHECK (FUNCTION_DECL_CHECK (DECL), 0)->access)
end_define

begin_comment
comment|/* A thunk which is equivalent to another thunk.  */
end_comment

begin_define
define|#
directive|define
name|THUNK_ALIAS
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (FUNCTION_DECL_CHECK (DECL))->decl_flags.u.template_info)
end_define

begin_comment
comment|/* For thunk NODE, this is the FUNCTION_DECL thunked to.  It is    possible for the target to be a thunk too.  */
end_comment

begin_define
define|#
directive|define
name|THUNK_TARGET
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->u.f.befriending_classes)
end_define

begin_comment
comment|/* True for a SCOPE_REF iff the "template" keyword was used to    indicate that the qualified name denotes a template.  */
end_comment

begin_define
define|#
directive|define
name|QUALIFIED_NAME_IS_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_0 (SCOPE_REF_CHECK (NODE)))
end_define

begin_comment
comment|/* True for an OMP_ATOMIC that has dependent parameters.  These are stored    as bare LHS/RHS, and not as ADDR/RHS, as in the generic statement.  */
end_comment

begin_define
define|#
directive|define
name|OMP_ATOMIC_DEPENDENT_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_0 (OMP_ATOMIC_CHECK (NODE)))
end_define

begin_comment
comment|/* Used to store the operation code when OMP_ATOMIC_DEPENDENT_P is set.  */
end_comment

begin_define
define|#
directive|define
name|OMP_ATOMIC_CODE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(OMP_ATOMIC_CHECK (NODE)->exp.complexity)
end_define

begin_comment
comment|/* Used while gimplifying continue statements bound to OMP_FOR nodes.  */
end_comment

begin_define
define|#
directive|define
name|OMP_FOR_GIMPLIFYING_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_0 (OMP_FOR_CHECK (NODE)))
end_define

begin_comment
comment|/* A language-specific token attached to the OpenMP data clauses to    hold code (or code fragments) related to ctors, dtors, and op=.    See semantics.c for details.  */
end_comment

begin_define
define|#
directive|define
name|CP_OMP_CLAUSE_INFO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_TYPE (OMP_CLAUSE_RANGE_CHECK (NODE, OMP_CLAUSE_PRIVATE, \ 				     OMP_CLAUSE_COPYPRIVATE))
end_define

begin_comment
comment|/* These macros provide convenient access to the various _STMT nodes    created when parsing template declarations.  */
end_comment

begin_define
define|#
directive|define
name|TRY_STMTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (TRY_BLOCK_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|TRY_HANDLERS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (TRY_BLOCK_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|EH_SPEC_STMTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (EH_SPEC_BLOCK_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|EH_SPEC_RAISES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (EH_SPEC_BLOCK_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|USING_STMT_NAMESPACE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (USING_STMT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* Nonzero if this try block is a function try block.  */
end_comment

begin_define
define|#
directive|define
name|FN_TRY_BLOCK_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_3 (TRY_BLOCK_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|HANDLER_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (HANDLER_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|HANDLER_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (HANDLER_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|HANDLER_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_TYPE (HANDLER_CHECK (NODE))
end_define

begin_comment
comment|/* CLEANUP_STMT accessors.  The statement(s) covered, the cleanup to run    and the VAR_DECL for which this cleanup exists.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CLEANUP_STMT_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|CLEANUP_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CLEANUP_STMT_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|CLEANUP_DECL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CLEANUP_STMT_CHECK (NODE), 2)
end_define

begin_comment
comment|/* IF_STMT accessors. These give access to the condition of the if    statement, the then block of the if statement, and the else block    of the if statement if it exists.  */
end_comment

begin_define
define|#
directive|define
name|IF_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (IF_STMT_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|THEN_CLAUSE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (IF_STMT_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|ELSE_CLAUSE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (IF_STMT_CHECK (NODE), 2)
end_define

begin_comment
comment|/* WHILE_STMT accessors. These give access to the condition of the    while statement and the body of the while statement, respectively.  */
end_comment

begin_define
define|#
directive|define
name|WHILE_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (WHILE_STMT_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|WHILE_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (WHILE_STMT_CHECK (NODE), 1)
end_define

begin_comment
comment|/* APPLE LOCAL begin for-fsf-4_4 3274130 5295549 */
end_comment

begin_expr_stmt
unit|\
operator|#
name|define
name|WHILE_ATTRIBUTES
argument_list|(
argument|NODE
argument_list|)
name|TREE_OPERAND
argument_list|(
name|WHILE_STMT_CHECK
argument_list|(
name|NODE
argument_list|)
argument_list|,
literal|2
argument_list|)
comment|/* APPLE LOCAL end for-fsf-4_4 3274130 5295549 */
expr|\
comment|/* DO_STMT accessors. These give access to the condition of the do    statement and the body of the do statement, respectively.  */
define|#
directive|define
name|DO_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (DO_STMT_CHECK (NODE), 0)
define|#
directive|define
name|DO_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (DO_STMT_CHECK (NODE), 1)
comment|/* APPLE LOCAL begin for-fsf-4_4 3274130 5295549 */
expr|\
operator|#
name|define
name|DO_ATTRIBUTES
argument_list|(
argument|NODE
argument_list|)
name|TREE_OPERAND
argument_list|(
name|DO_STMT_CHECK
argument_list|(
name|NODE
argument_list|)
argument_list|,
literal|2
argument_list|)
comment|/* APPLE LOCAL begin C* language */
comment|/* Used as a flag to indicate synthesized inner do-while loop of a     foreach statement.  Used for generation of break/continue statement     of the loop. */
define|#
directive|define
name|DO_FOREACH
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (DO_STMT_CHECK (NODE), 3)
comment|/* APPLE LOCAL end C* language */
comment|/* APPLE LOCAL end for-fsf-4_4 3274130 5295549 */
expr|\
comment|/* FOR_STMT accessors. These give access to the init statement,    condition, update expression, and body of the for statement,    respectively.  */
define|#
directive|define
name|FOR_INIT_STMT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (FOR_STMT_CHECK (NODE), 0)
define|#
directive|define
name|FOR_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (FOR_STMT_CHECK (NODE), 1)
define|#
directive|define
name|FOR_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (FOR_STMT_CHECK (NODE), 2)
define|#
directive|define
name|FOR_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (FOR_STMT_CHECK (NODE), 3)
comment|/* APPLE LOCAL begin for-fsf-4_4 3274130 5295549 */
expr|\
operator|#
name|define
name|FOR_ATTRIBUTES
argument_list|(
argument|NODE
argument_list|)
name|TREE_OPERAND
argument_list|(
name|FOR_STMT_CHECK
argument_list|(
name|NODE
argument_list|)
argument_list|,
literal|4
argument_list|)
comment|/* APPLE LOCAL end for-fsf-4_4 3274130 5295549 */
expr|\
operator|#
name|define
name|SWITCH_STMT_COND
argument_list|(
argument|NODE
argument_list|)
name|TREE_OPERAND
argument_list|(
name|SWITCH_STMT_CHECK
argument_list|(
name|NODE
argument_list|)
argument_list|,
literal|0
argument_list|)
define|#
directive|define
name|SWITCH_STMT_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SWITCH_STMT_CHECK (NODE), 1)
define|#
directive|define
name|SWITCH_STMT_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SWITCH_STMT_CHECK (NODE), 2)
comment|/* STMT_EXPR accessor.  */
define|#
directive|define
name|STMT_EXPR_STMT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (STMT_EXPR_CHECK (NODE), 0)
comment|/* EXPR_STMT accessor. This gives the expression associated with an    expression statement.  */
define|#
directive|define
name|EXPR_STMT_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (EXPR_STMT_CHECK (NODE), 0)
comment|/* True if this TARGET_EXPR was created by build_cplus_new, and so we can    discard it if it isn't useful.  */
define|#
directive|define
name|TARGET_EXPR_IMPLICIT_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_0 (TARGET_EXPR_CHECK (NODE))
comment|/* An enumeration of the kind of tags that C++ accepts.  */
expr|enum
name|tag_types
block|{
name|none_type
operator|=
literal|0
block|,
comment|/* Not a tag type.  */
name|record_type
block|,
comment|/* "struct" types.  */
name|class_type
block|,
comment|/* "class" types.  */
name|union_type
block|,
comment|/* "union" types.  */
name|enum_type
block|,
comment|/* "enum" types.  */
name|typename_type
comment|/* "typename" types.  */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The various kinds of lvalues we distinguish.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cp_lvalue_kind
block|{
name|clk_none
init|=
literal|0
block|,
comment|/* Things that are not an lvalue.  */
name|clk_ordinary
init|=
literal|1
block|,
comment|/* An ordinary lvalue.  */
name|clk_class
init|=
literal|2
block|,
comment|/* An rvalue of class-type.  */
name|clk_bitfield
init|=
literal|4
block|,
comment|/* An lvalue for a bit-field.  */
name|clk_packed
init|=
literal|8
comment|/* An lvalue for a packed field.  */
block|}
name|cp_lvalue_kind
typedef|;
end_typedef

begin_comment
comment|/* Various kinds of template specialization, instantiation, etc.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|tmpl_spec_kind
block|{
name|tsk_none
block|,
comment|/* Not a template at all.  */
name|tsk_invalid_member_spec
block|,
comment|/* An explicit member template 			      specialization, but the enclosing 			      classes have not all been explicitly 			      specialized.  */
name|tsk_invalid_expl_inst
block|,
comment|/* An explicit instantiation containing 			      template parameter lists.  */
name|tsk_excessive_parms
block|,
comment|/* A template declaration with too many 			      template parameter lists.  */
name|tsk_insufficient_parms
block|,
comment|/* A template declaration with too few 			      parameter lists.  */
name|tsk_template
block|,
comment|/* A template declaration.  */
name|tsk_expl_spec
block|,
comment|/* An explicit specialization.  */
name|tsk_expl_inst
comment|/* An explicit instantiation.  */
block|}
name|tmpl_spec_kind
typedef|;
end_typedef

begin_comment
comment|/* The various kinds of access.  BINFO_ACCESS depends on these being    two bit quantities.  The numerical values are important; they are    used to initialize RTTI data structures, so changing them changes    the ABI.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|access_kind
block|{
name|ak_none
init|=
literal|0
block|,
comment|/* Inaccessible.  */
name|ak_public
init|=
literal|1
block|,
comment|/* Accessible, as a `public' thing.  */
name|ak_protected
init|=
literal|2
block|,
comment|/* Accessible, as a `protected' thing.  */
name|ak_private
init|=
literal|3
comment|/* Accessible, as a `private' thing.  */
block|}
name|access_kind
typedef|;
end_typedef

begin_comment
comment|/* The various kinds of special functions.  If you add to this list,    you should update special_function_p as well.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|special_function_kind
block|{
name|sfk_none
init|=
literal|0
block|,
comment|/* Not a special function.  This enumeral 			      must have value zero; see 			      special_function_p.  */
name|sfk_constructor
block|,
comment|/* A constructor.  */
name|sfk_copy_constructor
block|,
comment|/* A copy constructor.  */
name|sfk_assignment_operator
block|,
comment|/* An assignment operator.  */
name|sfk_destructor
block|,
comment|/* A destructor.  */
name|sfk_complete_destructor
block|,
comment|/* A destructor for complete objects.  */
name|sfk_base_destructor
block|,
comment|/* A destructor for base subobjects.  */
name|sfk_deleting_destructor
block|,
comment|/* A destructor for complete objects that 			      deletes the object after it has been 			      destroyed.  */
name|sfk_conversion
comment|/* A conversion operator.  */
block|}
name|special_function_kind
typedef|;
end_typedef

begin_comment
comment|/* The various kinds of linkage.  From [basic.link],        A name is said to have linkage when it might denote the same       object, reference, function, type, template, namespace or value       as a name introduced in another scope:        -- When a name has external linkage, the entity it denotes can 	 be referred to from scopes of other translation units or from 	 other scopes of the same translation unit.        -- When a name has internal linkage, the entity it denotes can 	 be referred to by names from other scopes in the same 	 translation unit.        -- When a name has no linkage, the entity it denotes cannot be 	 referred to by names from other scopes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|linkage_kind
block|{
name|lk_none
block|,
comment|/* No linkage.  */
name|lk_internal
block|,
comment|/* Internal linkage.  */
name|lk_external
comment|/* External linkage.  */
block|}
name|linkage_kind
typedef|;
end_typedef

begin_comment
comment|/* Bitmask flags to control type substitution.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|tsubst_flags_t
block|{
name|tf_none
init|=
literal|0
block|,
comment|/* nothing special */
name|tf_error
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* give error messages  */
name|tf_warning
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* give warnings too  */
name|tf_ignore_bad_quals
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* ignore bad cvr qualifiers */
name|tf_keep_type_decl
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* retain typedef type decls 				   (make_typename_type use) */
name|tf_ptrmem_ok
init|=
literal|1
operator|<<
literal|4
block|,
comment|/* pointers to member ok (internal 				   instantiate_type use) */
name|tf_user
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* found template must be a user template 				   (lookup_template_class use) */
name|tf_conv
init|=
literal|1
operator|<<
literal|6
block|,
comment|/* We are determining what kind of 				   conversion might be permissible, 				   not actually performing the 				   conversion.  */
comment|/* Convenient substitution flags combinations.  */
name|tf_warning_or_error
init|=
name|tf_warning
operator||
name|tf_error
block|}
name|tsubst_flags_t
typedef|;
end_typedef

begin_comment
comment|/* The kind of checking we can do looking in a class hierarchy.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|base_access
block|{
name|ba_any
init|=
literal|0
block|,
comment|/* Do not check access, allow an ambiguous base, 		      prefer a non-virtual base */
name|ba_unique
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* Must be a unique base.  */
name|ba_check_bit
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* Check access.  */
name|ba_check
init|=
name|ba_unique
operator||
name|ba_check_bit
block|,
name|ba_ignore_scope
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* Ignore access allowed by local scope.  */
name|ba_quiet
init|=
literal|1
operator|<<
literal|3
comment|/* Do not issue error messages.  */
block|}
name|base_access
typedef|;
end_typedef

begin_comment
comment|/* The various kinds of access check during parsing.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|deferring_kind
block|{
name|dk_no_deferred
init|=
literal|0
block|,
comment|/* Check access immediately */
name|dk_deferred
init|=
literal|1
block|,
comment|/* Deferred check */
name|dk_no_check
init|=
literal|2
comment|/* No access check */
block|}
name|deferring_kind
typedef|;
end_typedef

begin_comment
comment|/* The kind of base we can find, looking in a class hierarchy.    Values<0 indicate we failed.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|base_kind
block|{
name|bk_inaccessible
init|=
operator|-
literal|3
block|,
comment|/* The base is inaccessible */
name|bk_ambig
init|=
operator|-
literal|2
block|,
comment|/* The base is ambiguous */
name|bk_not_base
init|=
operator|-
literal|1
block|,
comment|/* It is not a base */
name|bk_same_type
init|=
literal|0
block|,
comment|/* It is the same type */
name|bk_proper_base
init|=
literal|1
block|,
comment|/* It is a proper base */
name|bk_via_virtual
init|=
literal|2
comment|/* It is a proper base, but via a virtual 			     path. This might not be the canonical 			     binfo.  */
block|}
name|base_kind
typedef|;
end_typedef

begin_comment
comment|/* Node for "pointer to (virtual) function".    This may be distinct from ptr_type_node so gdb can distinguish them.  */
end_comment

begin_define
define|#
directive|define
name|vfunc_ptr_type_node
value|vtable_entry_type
end_define

begin_comment
comment|/* For building calls to `delete'.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|integer_two_node
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|integer_three_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of function bodies which we are currently processing.    (Zero if we are at namespace scope, one inside the body of a    function, two inside the body of a function in a local class, etc.)  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|function_depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in pt.c  */
end_comment

begin_comment
comment|/* These values are used for the `STRICT' parameter to type_unification and    fn_type_unification.  Their meanings are described with the    documentation for fn_type_unification.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|unification_kind_t
block|{
name|DEDUCE_CALL
block|,
name|DEDUCE_CONV
block|,
name|DEDUCE_EXACT
block|}
name|unification_kind_t
typedef|;
end_typedef

begin_comment
comment|/* Macros for operating on a template instantiation level node.  */
end_comment

begin_define
define|#
directive|define
name|TINST_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((tinst_level_t) TINST_LEVEL_CHECK (NODE))->decl)
end_define

begin_define
define|#
directive|define
name|TINST_LOCATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((tinst_level_t) TINST_LEVEL_CHECK (NODE))->locus)
end_define

begin_define
define|#
directive|define
name|TINST_IN_SYSTEM_HEADER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((tinst_level_t) TINST_LEVEL_CHECK (NODE))->in_system_header_p)
end_define

begin_comment
comment|/* in class.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_class_depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An array of all local classes present in this translation unit, in    declaration order.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_expr_stmt
unit|))
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|local_classes
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/* Here's where we control how name mangling takes place.  */
end_comment

begin_comment
comment|/* Cannot use '$' up front, because this confuses gdb    (names beginning with '$' are gdb-local identifiers).     Note that all forms in which the '$' is significant are long enough    for direct indexing (meaning that if we know there is a '$'    at a particular location, we can index into the string at    any other location that provides distinguishing characters).  */
end_comment

begin_comment
comment|/* Define NO_DOLLAR_IN_LABEL in your favorite tm file if your assembler    doesn't allow '$' in symbol names.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DOLLAR_IN_LABEL
end_ifndef

begin_define
define|#
directive|define
name|JOINER
value|'$'
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_NAME
value|"_$tmp_"
end_define

begin_define
define|#
directive|define
name|VFIELD_BASE
value|"$vf"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME
value|"_vptr$"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_FORMAT
value|"_vptr$%s"
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_FORMAT
value|"$_%d"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_DOLLAR_IN_LABEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DOT_IN_LABEL
end_ifndef

begin_define
define|#
directive|define
name|JOINER
value|'.'
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_NAME
value|"_.tmp_"
end_define

begin_define
define|#
directive|define
name|VFIELD_BASE
value|".vf"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME
value|"_vptr."
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_FORMAT
value|"_vptr.%s"
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_FORMAT
value|"._%d"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_DOT_IN_LABEL */
end_comment

begin_define
define|#
directive|define
name|IN_CHARGE_NAME
value|"__in_chrg"
end_define

begin_define
define|#
directive|define
name|AUTO_TEMP_NAME
value|"__tmp_"
end_define

begin_define
define|#
directive|define
name|TEMP_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), AUTO_TEMP_NAME, \ 	     sizeof (AUTO_TEMP_NAME) - 1))
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME
value|"__vt_"
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), VTABLE_NAME, \ 	     sizeof (VTABLE_NAME) - 1))
end_define

begin_define
define|#
directive|define
name|VFIELD_BASE
value|"__vfb"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME
value|"__vptr_"
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), VFIELD_NAME, \ 	    sizeof (VFIELD_NAME) - 1))
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_FORMAT
value|"__vptr_%s"
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_PREFIX
value|"__anon_"
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), ANON_AGGRNAME_PREFIX, \ 	     sizeof (ANON_AGGRNAME_PREFIX) - 1))
end_define

begin_define
define|#
directive|define
name|ANON_AGGRNAME_FORMAT
value|"__anon_%d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_DOT_IN_LABEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_DOLLAR_IN_LABEL */
end_comment

begin_define
define|#
directive|define
name|THIS_NAME
value|"this"
end_define

begin_define
define|#
directive|define
name|IN_CHARGE_NAME
value|"__in_chrg"
end_define

begin_define
define|#
directive|define
name|VTBL_PTR_TYPE
value|"__vtbl_ptr_type"
end_define

begin_define
define|#
directive|define
name|VTABLE_DELTA_NAME
value|"__delta"
end_define

begin_define
define|#
directive|define
name|VTABLE_PFN_NAME
value|"__pfn"
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_DOLLAR_IN_LABEL
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|NO_DOT_IN_LABEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|VTABLE_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[1] == 'v' \&& IDENTIFIER_POINTER (ID_NODE)[2] == 't' \&& IDENTIFIER_POINTER (ID_NODE)[3] == JOINER)
end_define

begin_define
define|#
directive|define
name|TEMP_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), AUTO_TEMP_NAME, sizeof (AUTO_TEMP_NAME)-1))
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), VFIELD_NAME, sizeof(VFIELD_NAME)-1))
end_define

begin_comment
comment|/* For anonymous aggregate types, we need some sort of name to    hold on to.  In practice, this should not appear, but it should    not be harmful if it does.  */
end_comment

begin_define
define|#
directive|define
name|ANON_AGGRNAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[1] == '_')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NO_DOLLAR_IN_LABEL) || !defined(NO_DOT_IN_LABEL) */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Nonzero if we're done parsing and into end-of-file activities.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|at_eof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of namespace-scope objects which have constructors or    destructors which reside in the global scope.  The decl is stored    in the TREE_VALUE slot and the initializer is stored in the    TREE_PURPOSE slot.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|static_aggregates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions called along with real static constructors and destructors.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|static_ctors
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|static_dtors
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|overload_flags
block|{
name|NO_SPECIAL
init|=
literal|0
block|,
name|DTOR_FLAG
block|,
name|OP_FLAG
block|,
name|TYPENAME_FLAG
block|}
enum|;
end_enum

begin_comment
comment|/* These are uses as bits in flags passed to various functions to    control their behavior.  Despite the LOOKUP_ prefix, many of these    do not control name lookup.  ??? Functions using these flags should    probably be modified to accept explicit boolean flags for the    behaviors relevant to them.  */
end_comment

begin_comment
comment|/* Check for access violations.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_PROTECT
value|(1<< 0)
end_define

begin_comment
comment|/* Complain if no suitable member function matching the arguments is    found.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_COMPLAIN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NORMAL
value|(LOOKUP_PROTECT | LOOKUP_COMPLAIN)
end_define

begin_comment
comment|/* Even if the function found by lookup is a virtual function, it    should be called directly.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_NONVIRTUAL
value|(1<< 2)
end_define

begin_comment
comment|/* Non-converting (i.e., "explicit") constructors are not tried.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_ONLYCONVERTING
value|(1<< 3)
end_define

begin_comment
comment|/* If a temporary is created, it should be created so that it lives    as long as the current variable bindings; otherwise it only lives    until the end of the complete-expression.  It also forces    direct-initialization in cases where other parts of the compiler    have already generated a temporary, such as reference    initialization and the catch parameter.  */
end_comment

begin_define
define|#
directive|define
name|DIRECT_BIND
value|(1<< 4)
end_define

begin_comment
comment|/* User-defined conversions are not permitted.  (Built-in conversions    are permitted.)  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_NO_CONVERSION
value|(1<< 5)
end_define

begin_comment
comment|/* The user has explicitly called a destructor.  (Therefore, we do    not need to check that the object is non-NULL before calling the    destructor.)  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_DESTRUCTOR
value|(1<< 6)
end_define

begin_comment
comment|/* Do not permit references to bind to temporaries.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_NO_TEMP_BIND
value|(1<< 7)
end_define

begin_comment
comment|/* Do not accept objects, and possibly namespaces.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_PREFER_TYPES
value|(1<< 8)
end_define

begin_comment
comment|/* Do not accept objects, and possibly types.   */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_PREFER_NAMESPACES
value|(1<< 9)
end_define

begin_comment
comment|/* Accept types or namespaces.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_PREFER_BOTH
value|(LOOKUP_PREFER_TYPES | LOOKUP_PREFER_NAMESPACES)
end_define

begin_comment
comment|/* We are checking that a constructor can be called -- but we do not    actually plan to call it.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_CONSTRUCTOR_CALLABLE
value|(1<< 10)
end_define

begin_comment
comment|/* Return friend declarations and un-declared builtin functions.    (Normally, these entities are registered in the symbol table, but    not found by lookup.)  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_HIDDEN
value|(LOOKUP_CONSTRUCTOR_CALLABLE<< 1)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NAMESPACES_ONLY
parameter_list|(
name|F
parameter_list|)
define|\
value|(((F)& LOOKUP_PREFER_NAMESPACES)&& !((F)& LOOKUP_PREFER_TYPES))
end_define

begin_define
define|#
directive|define
name|LOOKUP_TYPES_ONLY
parameter_list|(
name|F
parameter_list|)
define|\
value|(!((F)& LOOKUP_PREFER_NAMESPACES)&& ((F)& LOOKUP_PREFER_TYPES))
end_define

begin_define
define|#
directive|define
name|LOOKUP_QUALIFIERS_ONLY
parameter_list|(
name|F
parameter_list|)
value|((F)& LOOKUP_PREFER_BOTH)
end_define

begin_comment
comment|/* These flags are used by the conversion code.    CONV_IMPLICIT   :  Perform implicit conversions (standard and user-defined).    CONV_STATIC     :  Perform the explicit conversions for static_cast.    CONV_CONST      :  Perform the explicit conversions for const_cast.    CONV_REINTERPRET:  Perform the explicit conversions for reinterpret_cast.    CONV_PRIVATE    :  Perform upcasts to private bases.    CONV_FORCE_TEMP :  Require a new temporary when converting to the same 		      aggregate type.  */
end_comment

begin_define
define|#
directive|define
name|CONV_IMPLICIT
value|1
end_define

begin_define
define|#
directive|define
name|CONV_STATIC
value|2
end_define

begin_define
define|#
directive|define
name|CONV_CONST
value|4
end_define

begin_define
define|#
directive|define
name|CONV_REINTERPRET
value|8
end_define

begin_define
define|#
directive|define
name|CONV_PRIVATE
value|16
end_define

begin_comment
comment|/* #define CONV_NONCONVERTING 32 */
end_comment

begin_define
define|#
directive|define
name|CONV_FORCE_TEMP
value|64
end_define

begin_define
define|#
directive|define
name|CONV_OLD_CONVERT
value|(CONV_IMPLICIT | CONV_STATIC | CONV_CONST \ 			  | CONV_REINTERPRET)
end_define

begin_define
define|#
directive|define
name|CONV_C_CAST
value|(CONV_IMPLICIT | CONV_STATIC | CONV_CONST \ 			  | CONV_REINTERPRET | CONV_PRIVATE | CONV_FORCE_TEMP)
end_define

begin_comment
comment|/* Used by build_expr_type_conversion to indicate which types are    acceptable as arguments to the expression under consideration.  */
end_comment

begin_define
define|#
directive|define
name|WANT_INT
value|1
end_define

begin_comment
comment|/* integer types, including bool */
end_comment

begin_define
define|#
directive|define
name|WANT_FLOAT
value|2
end_define

begin_comment
comment|/* floating point types */
end_comment

begin_define
define|#
directive|define
name|WANT_ENUM
value|4
end_define

begin_comment
comment|/* enumerated types */
end_comment

begin_define
define|#
directive|define
name|WANT_POINTER
value|8
end_define

begin_comment
comment|/* pointer types */
end_comment

begin_define
define|#
directive|define
name|WANT_NULL
value|16
end_define

begin_comment
comment|/* null pointer constant */
end_comment

begin_define
define|#
directive|define
name|WANT_VECTOR
value|32
end_define

begin_comment
comment|/* vector types */
end_comment

begin_define
define|#
directive|define
name|WANT_ARITH
value|(WANT_INT | WANT_FLOAT | WANT_VECTOR)
end_define

begin_comment
comment|/* Used with comptypes, and related functions, to guide type    comparison.  */
end_comment

begin_define
define|#
directive|define
name|COMPARE_STRICT
value|0
end_define

begin_comment
comment|/* Just check if the types are the 				   same.  */
end_comment

begin_define
define|#
directive|define
name|COMPARE_BASE
value|1
end_define

begin_comment
comment|/* Check to see if the second type is 				   derived from the first.  */
end_comment

begin_define
define|#
directive|define
name|COMPARE_DERIVED
value|2
end_define

begin_comment
comment|/* Like COMPARE_BASE, but in 				   reverse.  */
end_comment

begin_define
define|#
directive|define
name|COMPARE_REDECLARATION
value|4
end_define

begin_comment
comment|/* The comparison is being done when 				   another declaration of an existing 				   entity is seen.  */
end_comment

begin_comment
comment|/* Used with push_overloaded_decl.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_GLOBAL
value|0
end_define

begin_comment
comment|/* Push the DECL into namespace scope, 				   regardless of the current scope.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_LOCAL
value|1
end_define

begin_comment
comment|/* Push the DECL into the current 				   scope.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_USING
value|2
end_define

begin_comment
comment|/* We are pushing this DECL as the 				   result of a using declaration.  */
end_comment

begin_comment
comment|/* Used with start function.  */
end_comment

begin_define
define|#
directive|define
name|SF_DEFAULT
value|0
end_define

begin_comment
comment|/* No flags.  */
end_comment

begin_define
define|#
directive|define
name|SF_PRE_PARSED
value|1
end_define

begin_comment
comment|/* The function declaration has 				   already been parsed.  */
end_comment

begin_define
define|#
directive|define
name|SF_INCLASS_INLINE
value|2
end_define

begin_comment
comment|/* The function is an inline, defined 				   in the class body.  */
end_comment

begin_comment
comment|/* Returns nonzero iff TYPE1 and TYPE2 are the same type, or if TYPE2    is derived from TYPE1, or if TYPE2 is a pointer (reference) to a    class derived from the type pointed to (referred to) by TYPE1.  */
end_comment

begin_define
define|#
directive|define
name|same_or_base_type_p
parameter_list|(
name|TYPE1
parameter_list|,
name|TYPE2
parameter_list|)
define|\
value|comptypes ((TYPE1), (TYPE2), COMPARE_BASE)
end_define

begin_comment
comment|/* These macros are used to access a TEMPLATE_PARM_INDEX.  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE_PARM_INDEX_CAST
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((template_parm_index*)TEMPLATE_PARM_INDEX_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_PARM_IDX
parameter_list|(
name|NODE
parameter_list|)
value|(TEMPLATE_PARM_INDEX_CAST (NODE)->index)
end_define

begin_define
define|#
directive|define
name|TEMPLATE_PARM_LEVEL
parameter_list|(
name|NODE
parameter_list|)
value|(TEMPLATE_PARM_INDEX_CAST (NODE)->level)
end_define

begin_define
define|#
directive|define
name|TEMPLATE_PARM_DESCENDANTS
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CHAIN (NODE))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_PARM_ORIG_LEVEL
parameter_list|(
name|NODE
parameter_list|)
value|(TEMPLATE_PARM_INDEX_CAST (NODE)->orig_level)
end_define

begin_define
define|#
directive|define
name|TEMPLATE_PARM_DECL
parameter_list|(
name|NODE
parameter_list|)
value|(TEMPLATE_PARM_INDEX_CAST (NODE)->decl)
end_define

begin_comment
comment|/* These macros are for accessing the fields of TEMPLATE_TYPE_PARM,    TEMPLATE_TEMPLATE_PARM and BOUND_TEMPLATE_TEMPLATE_PARM nodes.  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE_TYPE_PARM_INDEX
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CHECK3 ((NODE), TEMPLATE_TYPE_PARM, TEMPLATE_TEMPLATE_PARM,	\ 		BOUND_TEMPLATE_TEMPLATE_PARM))->type.values
end_define

begin_define
define|#
directive|define
name|TEMPLATE_TYPE_IDX
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TEMPLATE_PARM_IDX (TEMPLATE_TYPE_PARM_INDEX (NODE)))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_TYPE_LEVEL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TEMPLATE_PARM_LEVEL (TEMPLATE_TYPE_PARM_INDEX (NODE)))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_TYPE_ORIG_LEVEL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TEMPLATE_PARM_ORIG_LEVEL (TEMPLATE_TYPE_PARM_INDEX (NODE)))
end_define

begin_define
define|#
directive|define
name|TEMPLATE_TYPE_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TEMPLATE_PARM_DECL (TEMPLATE_TYPE_PARM_INDEX (NODE)))
end_define

begin_comment
comment|/* These constants can used as bit flags in the process of tree formatting.     TFF_PLAIN_IDENTIFIER: unqualified part of a name.    TFF_SCOPE: include the class and namespace scope of the name.    TFF_CHASE_TYPEDEF: print the original type-id instead of the typedef-name.    TFF_DECL_SPECIFIERS: print decl-specifiers.    TFF_CLASS_KEY_OR_ENUM: precede a class-type name (resp. enum name) with        a class-key (resp. `enum').    TFF_RETURN_TYPE: include function return type.    TFF_FUNCTION_DEFAULT_ARGUMENTS: include function default parameter values.    TFF_EXCEPTION_SPECIFICATION: show function exception specification.    TFF_TEMPLATE_HEADER: show the template<...> header in a        template-declaration.    TFF_TEMPLATE_NAME: show only template-name.    TFF_EXPR_IN_PARENS: parenthesize expressions.    TFF_NO_FUNCTION_ARGUMENTS: don't show function arguments.  */
end_comment

begin_define
define|#
directive|define
name|TFF_PLAIN_IDENTIFIER
value|(0)
end_define

begin_define
define|#
directive|define
name|TFF_SCOPE
value|(1)
end_define

begin_define
define|#
directive|define
name|TFF_CHASE_TYPEDEF
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TFF_DECL_SPECIFIERS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TFF_CLASS_KEY_OR_ENUM
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TFF_RETURN_TYPE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TFF_FUNCTION_DEFAULT_ARGUMENTS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|TFF_EXCEPTION_SPECIFICATION
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|TFF_TEMPLATE_HEADER
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|TFF_TEMPLATE_NAME
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|TFF_EXPR_IN_PARENS
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|TFF_NO_FUNCTION_ARGUMENTS
value|(1<< 10)
end_define

begin_comment
comment|/* Returns the TEMPLATE_DECL associated to a TEMPLATE_TEMPLATE_PARM    node.  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE_TEMPLATE_PARM_TEMPLATE_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_CODE (NODE) == BOUND_TEMPLATE_TEMPLATE_PARM)	\    ? TYPE_TI_TEMPLATE (NODE)				\    : TYPE_NAME (NODE))
end_define

begin_comment
comment|/* in lex.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_reswords
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Indexed by TREE_CODE, these tables give C-looking names to    operators represented by TREE_CODES.  For example,    opname_tab[(int) MINUS_EXPR] == "-".  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
modifier|*
name|opname_tab
decl_stmt|,
modifier|*
modifier|*
name|assignop_tab
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|operator_name_info_t
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The IDENTIFIER_NODE for the operator.  */
name|tree
name|identifier
block|;
comment|/* The name of the operator.  */
specifier|const
name|char
modifier|*
name|name
block|;
comment|/* The mangled name of the operator.  */
specifier|const
name|char
modifier|*
name|mangled_name
block|;
comment|/* The arity of the operator.  */
name|int
name|arity
block|; }
end_typedef

begin_expr_stmt
name|operator_name_info_t
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* A mapping from tree codes to operator name information.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|operator_name_info_t
name|operator_name_info
index|[
operator|(
name|int
operator|)
name|LAST_CPLUS_TREE_CODE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Similar, but for assignment operators.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|operator_name_info_t
name|assignment_operator_name_info
index|[
operator|(
name|int
operator|)
name|LAST_CPLUS_TREE_CODE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A type-qualifier, or bitmask therefore, using the TYPE_QUAL    constants.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|cp_cv_quals
typedef|;
end_typedef

begin_comment
comment|/* A storage class.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cp_storage_class
block|{
comment|/* sc_none must be zero so that zeroing a cp_decl_specifier_seq      sets the storage_class field to sc_none.  */
name|sc_none
init|=
literal|0
block|,
name|sc_auto
block|,
name|sc_register
block|,
name|sc_static
block|,
name|sc_extern
block|,
name|sc_mutable
block|}
name|cp_storage_class
typedef|;
end_typedef

begin_comment
comment|/* An individual decl-specifier.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cp_decl_spec
block|{
name|ds_first
block|,
name|ds_signed
init|=
name|ds_first
block|,
name|ds_unsigned
block|,
name|ds_short
block|,
name|ds_long
block|,
name|ds_const
block|,
name|ds_volatile
block|,
name|ds_restrict
block|,
name|ds_inline
block|,
name|ds_virtual
block|,
name|ds_explicit
block|,
name|ds_friend
block|,
name|ds_typedef
block|,
name|ds_complex
block|,
name|ds_thread
block|,
name|ds_last
block|}
name|cp_decl_spec
typedef|;
end_typedef

begin_comment
comment|/* A decl-specifier-seq.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cp_decl_specifier_seq
block|{
comment|/* The number of times each of the keywords has been seen.  */
name|unsigned
name|specs
index|[
operator|(
name|int
operator|)
name|ds_last
index|]
decl_stmt|;
comment|/* The primary type, if any, given by the decl-specifier-seq.      Modifiers, like "short", "const", and "unsigned" are not      reflected here.  This field will be a TYPE, unless a typedef-name      was used, in which case it will be a TYPE_DECL.  */
name|tree
name|type
decl_stmt|;
comment|/* The attributes, if any, provided with the specifier sequence.  */
name|tree
name|attributes
decl_stmt|;
comment|/* If non-NULL, a built-in type that the user attempted to redefine      to some other type.  */
name|tree
name|redefined_builtin_type
decl_stmt|;
comment|/* The storage class specified -- or sc_none if no storage class was      explicitly specified.  */
name|cp_storage_class
name|storage_class
decl_stmt|;
comment|/* True iff TYPE_SPEC indicates a user-defined type.  */
name|BOOL_BITFIELD
name|user_defined_type_p
range|:
literal|1
decl_stmt|;
comment|/* True iff multiple types were (erroneously) specified for this      decl-specifier-seq.  */
name|BOOL_BITFIELD
name|multiple_types_p
range|:
literal|1
decl_stmt|;
comment|/* True iff multiple storage classes were (erroneously) specified      for this decl-specifier-seq or a combination of a storage class      with a typedef specifier.  */
name|BOOL_BITFIELD
name|conflicting_specifiers_p
range|:
literal|1
decl_stmt|;
comment|/* True iff at least one decl-specifier was found.  */
name|BOOL_BITFIELD
name|any_specifiers_p
range|:
literal|1
decl_stmt|;
comment|/* True iff "int" was explicitly provided.  */
name|BOOL_BITFIELD
name|explicit_int_p
range|:
literal|1
decl_stmt|;
comment|/* True iff "char" was explicitly provided.  */
name|BOOL_BITFIELD
name|explicit_char_p
range|:
literal|1
decl_stmt|;
block|}
name|cp_decl_specifier_seq
typedef|;
end_typedef

begin_comment
comment|/* The various kinds of declarators.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cp_declarator_kind
block|{
name|cdk_id
block|,
name|cdk_function
block|,
name|cdk_array
block|,
name|cdk_pointer
block|,
name|cdk_reference
block|,
name|cdk_ptrmem
block|,
name|cdk_error
block|}
name|cp_declarator_kind
typedef|;
end_typedef

begin_comment
comment|/* A declarator.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cp_declarator
name|cp_declarator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cp_parameter_declarator
name|cp_parameter_declarator
typedef|;
end_typedef

begin_comment
comment|/* A parameter, before it has been semantically analyzed.  */
end_comment

begin_struct
struct|struct
name|cp_parameter_declarator
block|{
comment|/* The next parameter, or NULL_TREE if none.  */
name|cp_parameter_declarator
modifier|*
name|next
decl_stmt|;
comment|/* The decl-specifiers-seq for the parameter.  */
name|cp_decl_specifier_seq
name|decl_specifiers
decl_stmt|;
comment|/* The declarator for the parameter.  */
name|cp_declarator
modifier|*
name|declarator
decl_stmt|;
comment|/* The default-argument expression, or NULL_TREE, if none.  */
name|tree
name|default_argument
decl_stmt|;
comment|/* True iff this is the first parameter in the list and the      parameter sequence ends with an ellipsis.  */
name|bool
name|ellipsis_p
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A declarator.  */
end_comment

begin_struct
struct|struct
name|cp_declarator
block|{
comment|/* The kind of declarator.  */
name|cp_declarator_kind
name|kind
decl_stmt|;
comment|/* Attributes that apply to this declarator.  */
name|tree
name|attributes
decl_stmt|;
comment|/* For all but cdk_id and cdk_error, the contained declarator.  For      cdk_id and cdk_error, guaranteed to be NULL.  */
name|cp_declarator
modifier|*
name|declarator
decl_stmt|;
name|location_t
name|id_loc
decl_stmt|;
comment|/* Currently only set for cdk_id. */
union|union
block|{
comment|/* For identifiers.  */
struct|struct
block|{
comment|/* If non-NULL, the qualifying scope (a NAMESPACE_DECL or 	 *_TYPE) for this identifier.  */
name|tree
name|qualifying_scope
decl_stmt|;
comment|/* The unqualified name of the entity -- an IDENTIFIER_NODE, 	 BIT_NOT_EXPR, or TEMPLATE_ID_EXPR.  */
name|tree
name|unqualified_name
decl_stmt|;
comment|/* If this is the name of a function, what kind of special 	 function (if any).  */
name|special_function_kind
name|sfk
decl_stmt|;
block|}
name|id
struct|;
comment|/* For functions.  */
struct|struct
block|{
comment|/* The parameters to the function.  */
name|cp_parameter_declarator
modifier|*
name|parameters
decl_stmt|;
comment|/* The cv-qualifiers for the function.  */
name|cp_cv_quals
name|qualifiers
decl_stmt|;
comment|/* The exception-specification for the function.  */
name|tree
name|exception_specification
decl_stmt|;
block|}
name|function
struct|;
comment|/* For arrays.  */
struct|struct
block|{
comment|/* The bounds to the array.  */
name|tree
name|bounds
decl_stmt|;
block|}
name|array
struct|;
comment|/* For cdk_pointer, cdk_reference, and cdk_ptrmem.  */
struct|struct
block|{
comment|/* The cv-qualifiers for the pointer.  */
name|cp_cv_quals
name|qualifiers
decl_stmt|;
comment|/* For cdk_ptrmem, the class type containing the member.  */
name|tree
name|class_type
decl_stmt|;
block|}
name|pointer
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* A parameter list indicating for a function with no parameters,    e.g  "int f(void)".  */
end_comment

begin_decl_stmt
specifier|extern
name|cp_parameter_declarator
modifier|*
name|no_parameters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in call.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|check_dtor_name
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vfield_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_conditional_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_addr_func
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_call
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|null_ptr_cst_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sufficient_parms_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|type_decays_to
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_user_type_conversion
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_new_function_call
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_operator_new_call
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_new_method_call
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_special_member_call
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_new_op
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_op_delete_call
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|can_convert
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|can_convert_arg
parameter_list|(
name|tree
parameter_list|,
name|tree
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
name|can_convert_arg_bad
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|enforce_access
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_default_arg
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_arg_to_ellipsis
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_va_arg
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_type_promotes_to
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|type_passed_as
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_for_arg_passing
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_properly_derived_from
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|initialize_reference
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_temporary_var_for_ref_to_temp
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|strip_top_quals
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|perform_implicit_conversion
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|perform_direct_initialization_if_possible
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|in_charge_arg_for_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cxx_call
parameter_list|(
name|tree
parameter_list|,
name|tree
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
name|validate_conversion_obstack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENABLE_CHECKING */
end_comment

begin_comment
comment|/* in class.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_base_path
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_to_base
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_to_base_statically
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vtbl_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vfn_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_vtable_decl
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resort_type_method_vec
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|gt_pointer_operator
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|add_method
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|currently_open_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|currently_open_derived_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_struct
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
name|finish_struct_1
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|resolves_to_fixed_type_p
parameter_list|(
name|tree
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_class_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_empty_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushclass
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|popclass
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_nested_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_nested_class
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|current_lang_depth
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_lang_context
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_lang_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|instantiate_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tsubst_flags_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_class_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cxx_print_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cxx_print_xnode
parameter_list|(
name|FILE
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
name|void
name|cxx_print_decl
parameter_list|(
name|FILE
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
name|void
name|cxx_print_type
parameter_list|(
name|FILE
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
name|void
name|cxx_print_identifier
parameter_list|(
name|FILE
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
name|void
name|cxx_print_error_function
parameter_list|(
name|struct
name|diagnostic_context
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|build_self_reference
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|same_signature_p
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
name|maybe_add_class_template_decl_list
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unreverse_member_declarations
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|invalidate_class_lookup_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_note_name_used_in_class
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
name|note_name_declared_in_class
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_vtbl_decl_for_binfo
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_thunks
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_fold_obj_type_ref
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
name|set_linkage_according_to_type
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
name|determine_key_method
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_for_override
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
name|push_class_stack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_class_stack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in cvt.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|convert_to_reference
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_from_reference
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|force_rvalue
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|ocp_convert
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_convert
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_to_void
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
comment|/*implicit context*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_force
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_expr_type_conversion
parameter_list|(
name|int
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|type_promotes_to
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|perform_qualification_conversions
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
name|clone_function_decl
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|adjust_clone_args
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* decl.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|poplevel
parameter_list|(
name|int
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
name|insert_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushdecl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushdecl_maybe_friend
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cxx_init_decl_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|cp_tree_node_structure_enum
name|cp_tree_node_structure
parameter_list|(
name|union
name|lang_tree_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cxx_mark_addressable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cxx_push_function_context
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
name|cxx_pop_function_context
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
name|maybe_push_cleanup_level
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_scope
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_switch
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_switch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushtag
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tag_scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_anon_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|decls_match
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|duplicate_decls
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushdecl_top_level_maybe_friend
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pushdecl_top_level_and_finish
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|declare_local_label
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|define_label
parameter_list|(
name|location_t
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_goto
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|check_omp_return
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_typename_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|enum
name|tag_types
parameter_list|,
name|tsubst_flags_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_unbound_class_template
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tsubst_flags_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_for_out_of_scope_variable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_library_fn
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_library_fn_ptr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cp_library_fn_ptr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|push_library_fn
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|push_void_library_fn
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|push_throw_library_fn
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_tag_decl
parameter_list|(
name|cp_decl_specifier_seq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|shadow_tag
parameter_list|(
name|cp_decl_specifier_seq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|groktypename
parameter_list|(
name|cp_decl_specifier_seq
modifier|*
parameter_list|,
specifier|const
name|cp_declarator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_decl
parameter_list|(
specifier|const
name|cp_declarator
modifier|*
parameter_list|,
name|cp_decl_specifier_seq
modifier|*
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_decl_1
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_finish_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cp_complete_array_type
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_ptrmemfunc_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_ptrmem_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the grokdeclarator prototype is in decl.h */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_this_parm
parameter_list|(
name|tree
parameter_list|,
name|cp_cv_quals
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|copy_fn_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_scope_of_declarator
parameter_list|(
specifier|const
name|cp_declarator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|grok_special_member_properties
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|grok_ctor_properties
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|grok_op_properties
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|xref_tag
parameter_list|(
name|enum
name|tag_types
parameter_list|,
name|tree
parameter_list|,
name|tag_scope
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|xref_tag_from_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tag_scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|xref_basetypes
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_enum
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_enum
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|build_enumerator
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_preparsed_function
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|start_function
parameter_list|(
name|cp_decl_specifier_seq
modifier|*
parameter_list|,
specifier|const
name|cp_declarator
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_function_body
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_function_body
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_function
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_method
parameter_list|(
name|cp_decl_specifier_seq
modifier|*
parameter_list|,
specifier|const
name|cp_declarator
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_method
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_register_incomplete_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|complete_vars
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_other_binding_stack
parameter_list|(
name|struct
name|cp_binding_level
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|revert_static_member_fn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fixup_anonymous_aggr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_static_variable_definition
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|compute_array_index_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_default_argument
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|walk_namespaces_fn
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
name|walk_namespaces
parameter_list|(
name|walk_namespaces_fn
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|wrapup_globals_for_namespace
parameter_list|(
name|tree
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|create_implicit_typedef
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|maybe_push_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|force_target_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_target_expr_with_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|local_variable_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nonstatic_local_decl_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|register_dtor_fn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tmpl_spec_kind
name|current_tmpl_spec_kind
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_fname_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|builtin_function
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|tree
name|type
parameter_list|,
name|int
name|code
parameter_list|,
name|enum
name|built_in_class
name|cl
parameter_list|,
specifier|const
name|char
modifier|*
name|libname
parameter_list|,
name|tree
name|attrs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_elaborated_type_specifier
parameter_list|(
name|enum
name|tag_types
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|warn_extern_redeclared_static
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|cxx_comdat_group
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cp_missing_noreturn_ok_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initialize_artificial_var
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_var_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|reshape_init
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in decl2.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|check_java_method
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_memfn_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|cp_cv_quals
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_retrofit_in_chrg
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_make_one_only
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|grokclassfn
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|enum
name|overload_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|grok_array_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|delete_sanity
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_classfn
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_member_template
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|grokfield
parameter_list|(
specifier|const
name|cp_declarator
modifier|*
parameter_list|,
name|cp_decl_specifier_seq
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|grokbitfield
parameter_list|(
specifier|const
name|cp_declarator
modifier|*
parameter_list|,
name|cp_decl_specifier_seq
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cplus_decl_attributes
parameter_list|(
name|tree
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
name|void
name|finish_anon_union
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_finish_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|coerce_new_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|coerce_delete_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|comdat_linkage
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|determine_visibility
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|constrain_class_visibility
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update_member_visibility
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|import_export_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cleanup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_offset_ref_call_from_tree
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
name|check_default_args
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_used
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_static_data_member_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_build_parm_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_guard
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_guard_cond
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|set_guard
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_callgraph_analyze_expr
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_needed
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|decl_needed_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|note_vague_linkage_fn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_artificial_parm
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in error.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|type_as_string
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|decl_as_string
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|expr_as_string
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|lang_decl_name
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|language_to_string
parameter_list|(
name|enum
name|languages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|class_key_or_enum_as_string
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_instantiation_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in except.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_exception_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|expand_start_catch_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_end_catch_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_exc_ptr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_throw
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nothrow_libfn_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_handlers
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|choose_personality_routine
parameter_list|(
name|enum
name|languages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|eh_type_info
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in expr.c */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|cxx_expand_expr
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|,
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cplus_expand_constant
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* friend.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|is_friend
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
name|make_friend_class
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_friend
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|do_friend
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|enum
name|overload_flags
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in init.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|expand_member_init
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|emit_mem_initializers
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_aggr_init
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_aggr_type
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_type_value
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_zero_init
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_offset_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_new
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vec_init
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_delete
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|special_function_kind
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
name|push_base_cleanups
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vec_delete
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|special_function_kind
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|create_temporary_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initialize_vtbl_ptrs
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_java_class_ref
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|integral_constant_value
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in lex.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|cxx_dup_lang_specific_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|yyungetc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|unqualified_name_lookup_error
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|unqualified_fn_lookup_error
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_lang_decl
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|retrofit_lang_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|copy_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|copy_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_make_type
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_aggr_type
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|yyhook
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cxx_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cxx_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|in_main_input_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in method.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_thunk
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_thunk
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|use_thunk
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|synthesize_method
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lazily_declare_fn
parameter_list|(
name|special_function_kind
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|skip_artificial_parms_for
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_alias_for
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In optimize.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|maybe_clone_body
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in pt.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|check_template_shadow
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_innermost_template_args
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_begin_member_template_processing
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_end_member_template_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_member_template_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|begin_template_parm_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|begin_specialization
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reset_specialization
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|end_specialization
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|begin_explicit_instantiation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|end_explicit_instantiation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_explicit_specialization
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|process_template_parm
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|end_template_parm_list
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|end_template_decl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|push_template_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|push_template_decl_real
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|redeclare_class_template
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_template_class
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|tsubst_flags_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_template_function
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uses_template_parms
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uses_template_parms_level
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|instantiate_class_template
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|instantiate_template
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tsubst_flags_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fn_type_unification
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|unification_kind_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_decl_instantiated
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|more_specialized_fn
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_decl_instantiation
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
name|do_type_instantiation
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tsubst_flags_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|instantiate_decl
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comp_template_parms
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|template_class_depth
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_specialization_of
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_specialization_of_friend
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comp_template_args
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|maybe_process_partial_specialization
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|most_specialized_instantiation
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_candidates
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|instantiate_pending_templates
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|tsubst_default_argument
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|tsubst_copy_and_build
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tsubst_flags_t
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|most_general_template
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_mostly_instantiated_function_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|problematic_instantiation_changed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_last_problematic_instantiation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|current_instantiation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|maybe_get_template_decl_from_type_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|processing_template_parmlist
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|bool
name|dependent_type_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|any_dependent_template_arguments_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|dependent_template_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|dependent_template_id_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|type_dependent_expression_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|any_type_dependent_arguments_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|value_dependent_expression_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|any_value_dependent_elements_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|resolve_typename_type
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|template_for_substitution
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_non_dependent_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_non_dependent_args
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|reregister_specialization
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_non_dependent_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|explicit_class_specialization_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|outermost_tinst_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in repo.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_repo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|repo_emit_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|repo_export_class_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_repo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in rtti.c */
end_comment

begin_comment
comment|/* A vector of all tinfo decls that haven't been emitted yet.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_expr_stmt
unit|))
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|unemitted_tinfo_decls
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|void
name|init_rtti_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_typeid
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_tinfo_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_typeid
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_dynamic_cast
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
name|emit_support_tinfos
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|emit_tinfo_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in search.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|accessible_base_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_base
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|base_access
parameter_list|,
name|base_kind
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|dcast_base_hint
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|accessible_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_field_1
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_field
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lookup_fnfields_1
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|class_method_index_for_fn
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_fnfields
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_member
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|look_for_overrides
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
name|get_pure_virtuals
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_suppress_debug_info
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|note_debug_info_needed
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_search_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reinit_search_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|current_scope
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|at_function_scope_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|at_class_scope_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|at_namespace_scope_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|context_for_name_lookup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_conversions
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|binfo_from_vbase
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|binfo_for_vbase
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|look_for_overrides_here
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|dfs_skip_bases
value|((tree)1)
end_define

begin_function_decl
specifier|extern
name|tree
name|dfs_walk_all
parameter_list|(
name|tree
parameter_list|,
name|tree
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|tree
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|tree
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|tree
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
name|tree
name|dfs_walk_once
parameter_list|(
name|tree
parameter_list|,
name|tree
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|tree
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|tree
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|tree
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
name|tree
name|binfo_via_virtual
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_baselink
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|adjust_result_of_qualified_name_lookup
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|copied_binfo
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|original_binfo
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shared_member_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The representation of a deferred access check.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|deferred_access_check
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The base class in which the declaration is referenced. */
name|tree
name|binfo
block|;
comment|/* The declaration whose access must be checked.  */
name|tree
name|decl
block|;
comment|/* The declaration that should be used in the error message.  */
name|tree
name|diag_decl
block|; }
end_typedef

begin_expr_stmt
name|deferred_access_check
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_O
argument_list|(
name|deferred_access_check
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_O
argument_list|(
name|deferred_access_check
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* in semantics.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|push_deferring_access_checks
parameter_list|(
name|deferring_kind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resume_deferring_access_checks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stop_deferring_access_checks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_deferring_access_checks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern VEC (deferred_access_check
operator|,
extern|gc
end_extern

begin_expr_stmt
unit|)
operator|*
name|get_deferred_access_checks
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|void
name|pop_to_parent_deferring_access_checks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|perform_access_checks
argument_list|(
name|VEC
argument_list|(
name|deferred_access_check
argument_list|,
name|gc
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|perform_deferred_access_checks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|perform_or_defer_access_check
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|stmts_are_full_exprs_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_cp_semantics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|do_poplevel
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_decl_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_expr_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_if_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_if_stmt_cond
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_then_clause
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|begin_else_clause
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_else_clause
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_if_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL begin for-fsf-4_4 3274130 5295549 */
end_comment

begin_function_decl
unit|\
specifier|extern
name|tree
name|begin_while_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL end for-fsf-4_4 3274130 5295549 */
end_comment

begin_function_decl
unit|\
specifier|extern
name|void
name|finish_while_stmt_cond
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
name|finish_while_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL begin for-fsf-4_4 3274130 5295549 */
end_comment

begin_function_decl
unit|\
specifier|extern
name|tree
name|begin_do_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL end for-fsf-4_4 3274130 5295549 */
end_comment

begin_function_decl
unit|\
specifier|extern
name|void
name|finish_do_body
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_do_stmt
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_return_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL begin for-fsf-4_4 3274130 5295549 */
end_comment

begin_function_decl
unit|\
specifier|extern
name|tree
name|begin_for_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL end for-fsf-4_4 3274130 5295549 */
end_comment

begin_function_decl
unit|\
specifier|extern
name|void
name|finish_for_init_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_for_cond
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
name|finish_for_expr
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
name|finish_for_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_break_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_continue_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_switch_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_switch_cond
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
name|finish_switch_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_case_label
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_goto_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_try_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_try_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_eh_spec_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_eh_spec_block
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
name|finish_handler_sequence
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_function_try_block
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_function_try_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_function_handler_sequence
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
name|finish_cleanup_try_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_handler_parms
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
name|finish_handler
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_cleanup
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|BCS_NO_SCOPE
init|=
literal|1
block|,
name|BCS_TRY_BLOCK
init|=
literal|2
block|,
name|BCS_FN_BODY
init|=
literal|4
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|tree
name|begin_compound_stmt
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_compound_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_asm_stmt
parameter_list|(
name|int
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_label_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_label_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_parenthesized_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_non_static_data_member
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_stmt_expr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_stmt_expr_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_stmt_expr
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|perform_koenig_lookup
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_call_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_increment_expr
parameter_list|(
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_this_expr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_pseudo_destructor_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_unary_op_expr
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|finish_compound_literal
argument_list|(
name|tree
argument_list|,
name|VEC
argument_list|(
name|constructor_elt
argument_list|,
name|gc
argument_list|)
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|finish_fname
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_translation_unit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_template_type_parm
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_template_template_parm
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_class_definition
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
name|finish_template_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_template_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_base_specifier
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_member_declaration
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qualified_name_lookup_error
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_template_keyword
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_id_expression
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|cp_id_kind
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|bool
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_typeof
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_offsetof
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_decl_cleanup
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
name|finish_eh_cleanup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_body
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_mem_initializers
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_template_template_default_arg
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_or_defer_fn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_accessibility_of_qualified_id
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_qualified_id_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|simplify_aggr_init_expr
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finalize_nrv
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|note_decl_for_pch
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_omp_clauses
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_omp_threadprivate
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_omp_structured_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_omp_structured_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|begin_omp_parallel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_omp_parallel
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_omp_for
parameter_list|(
name|location_t
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_omp_atomic
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_omp_barrier
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_omp_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|omp_clause_default_kind
name|cxx_omp_predetermined_sharing
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_omp_clause_default_ctor
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_omp_clause_copy_ctor
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_omp_clause_assign_op
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_omp_clause_dtor
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cxx_omp_privatize_by_reference
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|baselink_for_fns
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lang_check_failed
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|stabilize_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stabilize_call
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|stabilize_init
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|add_stmt_to_compound
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_maybe_build_cleanup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_tree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pod_type_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|class_tmpl_impl_spec_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|zero_init_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|canonical_type_variant
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|copy_binfo
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|member_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cp_lvalue_kind
name|real_lvalue_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|builtin_valid_in_constant_expr_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_min
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_min_nt
parameter_list|(
name|enum
name|tree_code
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_min_non_dep
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cplus_new
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_target_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_cplus_array_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|hash_tree_cons
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|hash_tree_chain
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_qualified_name
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_overloaded_fn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_first_fn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|ovl_cons
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_overload
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|cxx_printable_name
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_exception_variant
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|bind_template_template_parm
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|array_type_nelts_total
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|array_type_nelts_top
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|break_out_target_exprs
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_type_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|decl_namespace_context
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|decl_anon_ns_mem_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lvalue_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|error_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|varargs_function_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|really_overloaded_fn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cp_tree_equal
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|no_linkage_check
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_binfo
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_dummy_object
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|maybe_dummy_object
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_dummy_object
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|attribute_spec
name|cxx_attribute_table
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|make_ptrmem_cst
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_build_type_attribute_variant
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_build_qualified_type_real
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|tsubst_flags_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cp_build_qualified_type
parameter_list|(
name|TYPE
parameter_list|,
name|QUALS
parameter_list|)
define|\
value|cp_build_qualified_type_real ((TYPE), (QUALS), tf_warning_or_error)
end_define

begin_function_decl
specifier|extern
name|special_function_kind
name|special_function_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|count_trees
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|char_type_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|verify_stmt_tree
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|linkage_kind
name|decl_linkage
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_walk_subtrees
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|walk_tree_fn
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pointer_set_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cp_cannot_inline_tree_fn
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_add_pending_fn_decls
parameter_list|(
name|void
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cp_auto_var_in_fn_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_if_not_in_template
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|rvalue
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_bitfield_to_declared_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_save_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cast_valid_in_integral_constant_expression_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in typeck.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|string_conv_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_truthvalue_conversion
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|condition_conversion
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|require_complete_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|complete_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|complete_type_or_else
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|type_unknown_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|comp_except_specs
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|comptypes
parameter_list|(
name|tree
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
name|compparms
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comp_cv_qualification
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comp_cv_qual_signature
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_sizeof_or_alignof_expr
parameter_list|(
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_sizeof_or_alignof_type
parameter_list|(
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cxx_sizeof_nowarn
parameter_list|(
name|T
parameter_list|)
value|cxx_sizeof_or_alignof_type (T, SIZEOF_EXPR, false)
end_define

begin_function_decl
specifier|extern
name|tree
name|inline_conversion
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|is_bitfield_expr_with_lowered_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|unlowered_expr_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|decay_conversion
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_class_member_access_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|finish_class_member_access_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_indirect_ref
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_indirect_ref
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_array_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_member_function_from_ptrfunc
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_binary_op
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_unary_op
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|unary_complex_lvalue
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_conditional_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_compound_expr_from_list
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_compound_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_compound_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_static_cast
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_reinterpret_cast
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_const_cast
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_c_cast
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_modify_expr
parameter_list|(
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_modify_expr
parameter_list|(
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_for_initialization
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
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
name|int
name|comp_ptr_ttypes
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|comp_ptr_ttypes_const
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ptr_reasonably_similar
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_ptrmemfunc
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cp_type_quals
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cp_type_readonly
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cp_has_mutable_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|at_least_as_qualified_p
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
name|cp_apply_type_quals_to_decl
parameter_list|(
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_ptrmemfunc1
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_ptrmemfunc_cst
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|type_after_usual_arithmetic_conversions
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|composite_pointer_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|merge_types
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|check_return_expr
parameter_list|(
name|tree
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cp_build_binary_op
parameter_list|(
name|code
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|build_binary_op(code, arg1, arg2, 1)
end_define

begin_define
define|#
directive|define
name|cxx_sizeof
parameter_list|(
name|T
parameter_list|)
value|cxx_sizeof_or_alignof_type (T, SIZEOF_EXPR, true)
end_define

begin_function_decl
specifier|extern
name|tree
name|build_ptrmemfunc_access_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_address
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_nop
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|non_reference
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_anon_field
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|invalid_nonstatic_memfn_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_member_func_to_ptr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_ptrmem
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lvalue_or_else
parameter_list|(
name|tree
parameter_list|,
name|enum
name|lvalue_use
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lvalue_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in typeck2.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|require_complete_eh_spec_types
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
name|cxx_incomplete_type_diagnostic
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|cxx_incomplete_type_error
end_undef

begin_function_decl
specifier|extern
name|void
name|cxx_incomplete_type_error
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cxx_incomplete_type_error
parameter_list|(
name|V
parameter_list|,
name|T
parameter_list|)
define|\
value|(cxx_incomplete_type_diagnostic ((V), (T), 0))
end_define

begin_function_decl
specifier|extern
name|tree
name|error_not_base_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|binfo_or_else
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
name|readonly_error
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|complete_type_check_abstract
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|abstract_virtuals_error
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|store_init_value
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|digest_init
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_scoped_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_x_arrow
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_m_component_ref
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_functional_cast
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|add_exception_specifier
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|merge_exception_specifiers
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in mangle.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_mangle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mangle_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|mangle_type_string
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_typeinfo_for_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_typeinfo_string_for_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_vtbl_for_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_vtt_for_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_ctor_vtbl_for_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_thunk
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_conv_op_name_for_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_guard_variable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|mangle_ref_init_variable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in dump.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|cp_dump_tree
parameter_list|(
name|void
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In cp/cp-objcp-common.c.  */
end_comment

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|cxx_get_alias_set
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cxx_warn_unused_global_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cp_expr_size
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|cp_tree_size
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cp_var_mod_type_p
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
name|cxx_initialize_diagnostics
parameter_list|(
name|struct
name|diagnostic_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cxx_types_compatible_p
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
name|init_shadowed_var_for_decl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|cxx_staticp
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in cp-gimplify.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|cp_gimplify_expr
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_genericize
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* -- end of C++ */
end_comment

begin_comment
comment|/* In order for the format checking to accept the C++ frontend    diagnostic framework extensions, you must include this file before    toplev.h, not after.  We override the definition of GCC_DIAG_STYLE    in c-common.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|GCC_DIAG_STYLE
end_undef

begin_define
define|#
directive|define
name|GCC_DIAG_STYLE
value|__gcc_cxxdiag__
end_define

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|4001
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_GCC_CXXDIAG
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|__attribute__ ((__format__ (GCC_DIAG_STYLE, m, n))) ATTRIBUTE_NONNULL(m)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_GCC_CXXDIAG
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|ATTRIBUTE_NONNULL(m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|cp_cpp_error
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
modifier|*
parameter_list|)
function_decl|ATTRIBUTE_GCC_CXXDIAG
parameter_list|(
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_CP_TREE_H */
end_comment

end_unit

