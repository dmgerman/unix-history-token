begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for C++ parsing and type checking.    Copyright (C) 1987, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@cygnus.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
file|"varray.h"
end_include

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
file|"c-common.h"
end_include

begin_comment
comment|/* Usage of TREE_LANG_FLAG_?:    0: BINFO_MARKED (BINFO nodes).       IDENTIFIER_MARKED (IDENTIFIER_NODEs)       NEW_EXPR_USE_GLOBAL (in NEW_EXPR).       DELETE_EXPR_USE_GLOBAL (in DELETE_EXPR).       LOOKUP_EXPR_GLOBAL (in LOOKUP_EXPR).       TREE_INDIRECT_USING (in NAMESPACE_DECL).       LOCAL_BINDING_P (in CPLUS_BINDING)       ICS_USER_FLAG (in _CONV)       CLEANUP_P (in TRY_BLOCK)       AGGR_INIT_VIA_CTOR_P (in AGGR_INIT_EXPR)       CTOR_BEGIN_P (in CTOR_STMT)       BV_USE_VCALL_INDEX_P (in the BINFO_VIRTUALS TREE_LIST)       PTRMEM_OK_P (in ADDR_EXPR, OFFSET_REF)       PARMLIST_ELLIPSIS_P (in PARMLIST)    1: IDENTIFIER_VIRTUAL_P.       TI_PENDING_TEMPLATE_FLAG.       TEMPLATE_PARMS_FOR_INLINE.       DELETE_EXPR_USE_VEC (in DELETE_EXPR).       (TREE_CALLS_NEW) (in _EXPR or _REF) (commented-out).       TYPE_BASE_CONVS_MAY_REQUIRE_CODE_P (in _TYPE).       INHERITED_VALUE_BINDING_P (in CPLUS_BINDING)       BASELINK_P (in TREE_LIST)       ICS_ELLIPSIS_FLAG (in _CONV)       BINFO_ACCESS (in BINFO)    2: IDENTIFIER_OPNAME_P.       TYPE_POLYMORHPIC_P (in _TYPE)       ICS_THIS_FLAG (in _CONV)       BINDING_HAS_LEVEL_P (in CPLUS_BINDING)       BINFO_LOST_PRIMARY_P (in BINFO)       TREE_PARMLIST (in TREE_LIST)    3: TYPE_USES_VIRTUAL_BASECLASSES (in a class TYPE).       BINFO_VTABLE_PATH_MARKED.       BINFO_PUSHDECLS_MARKED.       (TREE_REFERENCE_EXPR) (in NON_LVALUE_EXPR) (commented-out).       ICS_BAD_FLAG (in _CONV)       FN_TRY_BLOCK_P (in TRY_BLOCK)       IDENTIFIER_CTOR_OR_DTOR_P (in IDENTIFIER_NODE)    4: BINFO_NEW_VTABLE_MARKED.       TREE_HAS_CONSTRUCTOR (in INDIRECT_REF, SAVE_EXPR, CONSTRUCTOR,           or FIELD_DECL).       NEED_TEMPORARY_P (in REF_BIND, BASE_CONV)       IDENTIFIER_TYPENAME_P (in IDENTIFIER_NODE)    5: C_IS_RESERVED_WORD (in IDENTIFIER_NODE)    6: BINFO_ACCESS (in BINFO)     Usage of TYPE_LANG_FLAG_?:    0: C_TYPE_FIELDS_READONLY (in RECORD_TYPE or UNION_TYPE).    1: TYPE_HAS_CONSTRUCTOR.    2: TYPE_HAS_DESTRUCTOR.    3: TYPE_FOR_JAVA.    4: TYPE_HAS_NONTRIVIAL_DESTRUCTOR    5: IS_AGGR_TYPE.    6: TYPE_BUILT_IN.     Usage of DECL_LANG_FLAG_?:    0: DECL_ERROR_REPORTED (in VAR_DECL).       DECL_TEMPLATE_PARM_P (in PARM_DECL, CONST_DECL, TYPE_DECL, or TEMPLATE_DECL)       DECL_LOCAL_FUNCTION_P (in FUNCTION_DECL)       DECL_MUTABLE_P (in FIELD_DECL)    1: C_TYPEDEF_EXPLICITLY_SIGNED (in TYPE_DECL).       DECL_TEMPLATE_INSTANTIATED (in a VAR_DECL or a FUNCTION_DECL)       DECL_C_BITFIELD (in FIELD_DECL)    2: DECL_THIS_EXTERN (in VAR_DECL or FUNCTION_DECL).       DECL_IMPLICIT_TYPEDEF_P (in a TYPE_DECL)    3: DECL_IN_AGGR_P.    4: DECL_C_BIT_FIELD    5: DECL_INTERFACE_KNOWN.    6: DECL_THIS_STATIC (in VAR_DECL or FUNCTION_DECL).    7: DECL_DEAD_FOR_LOCAL (in VAR_DECL).       DECL_THUNK_P (in a member FUNCTION_DECL)     Usage of language-independent fields in a language-dependent manner:     TREE_USED      This field is BINFO_INDIRECT_PRIMARY_P in a BINFO.     TYPE_ALIAS_SET      This field is used by TYPENAME_TYPEs, TEMPLATE_TYPE_PARMs, and so      forth as a substitute for the mark bits provided in `lang_type'.      At present, only the six low-order bits are used.     TYPE_BINFO      For an ENUMERAL_TYPE, this is ENUM_TEMPLATE_INFO.      For a FUNCTION_TYPE or METHOD_TYPE, this is TYPE_RAISES_EXCEPTIONS    BINFO_VIRTUALS      For a binfo, this is a TREE_LIST.  The BV_DELTA of each node      gives the amount by which to adjust the `this' pointer when      calling the function.  If the method is an overriden version of a      base class method, then it is assumed that, prior to adjustment,      the this pointer points to an object of the base class.       The BV_VCALL_INDEX of each node, if non-NULL, gives the vtable      index of the vcall offset for this entry.  If      BV_USE_VCALL_INDEX_P then the corresponding vtable entry should      use a virtual thunk, as opposed to an ordinary thunk.       The BV_FN is the declaration for the virtual function itself.     BINFO_VTABLE      This is an expression with POINTER_TYPE that gives the value      to which the vptr should be initialized.  Use get_vtbl_decl_for_binfo      to extract the VAR_DECL for the complete vtable.     DECL_ARGUMENTS      For a VAR_DECL this is DECL_ANON_UNION_ELEMS.     DECL_VINDEX      This field is NULL for a non-virtual function.  For a virtual      function, it is eventually set to an INTEGER_CST indicating the      index in the vtable at which this function can be found.  When      a virtual function is declared, but before it is known what      function is overriden, this field is the error_mark_node.       Temporarily, it may be set to a TREE_LIST whose TREE_VALUE is      the virtual function this one overrides, and whose TREE_CHAIN is      the old DECL_VINDEX.  */
end_comment

begin_comment
comment|/* Language-specific tree checkers. */
end_comment

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
name|VAR_OR_FUNCTION_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|({  const tree __t = (NODE);					\     enum tree_code const __c = TREE_CODE(__t);			\     if (__c != VAR_DECL&& __c != FUNCTION_DECL)		\       tree_check_failed (__t, VAR_DECL, __FILE__, __LINE__,	\ 			 __FUNCTION__);				\     __t; })
end_define

begin_define
define|#
directive|define
name|VAR_FUNCTION_OR_PARM_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|({  const tree __t = (NODE);					\     enum tree_code const __c = TREE_CODE(__t);			\     if (__c != VAR_DECL						\&& __c != FUNCTION_DECL					\&& __c != PARM_DECL)					\       tree_check_failed (__t, VAR_DECL, __FILE__, __LINE__,	\ 			 __FUNCTION__);				\     __t; })
end_define

begin_define
define|#
directive|define
name|VAR_TEMPL_TYPE_OR_FUNCTION_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|({  const tree __t = (NODE);					\     enum tree_code const __c = TREE_CODE(__t);			\     if (__c != VAR_DECL						\&& __c != FUNCTION_DECL					\&& __c != TYPE_DECL					\&& __c != TEMPLATE_DECL)				\       tree_check_failed (__t, VAR_DECL, __FILE__, __LINE__,	\ 			 __FUNCTION__);				\     __t; })
end_define

begin_define
define|#
directive|define
name|RECORD_OR_UNION_TYPE_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|({  const tree __t = (NODE);					\     enum tree_code const __c = TREE_CODE(__t);			\     if (__c != RECORD_TYPE&& __c != UNION_TYPE)		\       tree_check_failed (__t, RECORD_TYPE, __FILE__, __LINE__,	\ 			 __FUNCTION__);				\     __t; })
end_define

begin_define
define|#
directive|define
name|BOUND_TEMPLATE_TEMPLATE_PARM_TYPE_CHECK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|({  const tree __t = (NODE);					\     enum tree_code const __c = TREE_CODE(__t);			\     if (__c != BOUND_TEMPLATE_TEMPLATE_PARM)			\       tree_check_failed (__t, BOUND_TEMPLATE_TEMPLATE_PARM,	\ 			 __FILE__, __LINE__, __FUNCTION__);	\     __t; })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not ENABLE_TREE_CHECKING, or not gcc */
end_comment

begin_define
define|#
directive|define
name|VAR_OR_FUNCTION_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|(NODE)
end_define

begin_define
define|#
directive|define
name|VAR_FUNCTION_OR_PARM_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|(NODE)
end_define

begin_define
define|#
directive|define
name|VAR_TEMPL_TYPE_OR_FUNCTION_DECL_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|(NODE)
end_define

begin_define
define|#
directive|define
name|RECORD_OR_UNION_TYPE_CHECK
parameter_list|(
name|NODE
parameter_list|)
value|(NODE)
end_define

begin_define
define|#
directive|define
name|BOUND_TEMPLATE_TEMPLATE_PARM_TYPE_CHECK
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
comment|/* ABI control.  */
end_comment

begin_comment
comment|/* Nonzero to use __cxa_atexit, rather than atexit, to register    destructors for local statics and global objects.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_use_cxa_atexit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means generate 'rtti' that give run-time type information.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_rtti
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to support huge (> 2^(sizeof(short)*8-1) bytes)    objects.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_huge_objects
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Language-dependent contents of an identifier.  */
end_comment

begin_struct
struct|struct
name|lang_identifier
block|{
name|struct
name|c_common_identifier
name|ignore
decl_stmt|;
name|tree
name|namespace_bindings
decl_stmt|;
name|tree
name|bindings
decl_stmt|;
name|tree
name|class_value
decl_stmt|;
name|tree
name|class_template_info
decl_stmt|;
name|struct
name|lang_id2
modifier|*
name|x
decl_stmt|;
block|}
struct|;
end_struct

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

begin_decl_stmt
specifier|extern
specifier|const
name|short
name|rid_to_yy
index|[
name|RID_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|C_RID_YYCODE
parameter_list|(
name|ID
parameter_list|)
value|rid_to_yy[C_RID_CODE (ID)]
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

begin_struct
struct|struct
name|lang_id2
block|{
name|tree
name|label_value
decl_stmt|,
name|implicit_decl
decl_stmt|;
name|tree
name|error_locus
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|tree
name|t
decl_stmt|;
name|int
name|new_type_flag
decl_stmt|;
name|tree
name|lookups
decl_stmt|;
block|}
name|flagged_type_tree
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
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
name|template_parm_index
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ptrmem_cst
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
typedef|*
name|ptrmem_cst_t
typedef|;
end_typedef

begin_comment
comment|/* Nonzero if this binding is for a local scope, as opposed to a class    or namespace scope.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_BINDING_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
end_define

begin_comment
comment|/* Nonzero if BINDING_VALUE is from a base class of the class which is    currently being defined.  */
end_comment

begin_define
define|#
directive|define
name|INHERITED_VALUE_BINDING_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1 (NODE)
end_define

begin_comment
comment|/* For a binding between a name and an entity at a non-local scope,    defines the scope where the binding is declared.  (Either a class    _TYPE node, or a NAMESPACE_DECL.)  This macro should be used only    for namespace-level bindings; on the IDENTIFIER_BINDING list    BINDING_LEVEL is used instead.  */
end_comment

begin_define
define|#
directive|define
name|BINDING_SCOPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct tree_binding*)CPLUS_BINDING_CHECK (NODE))->scope.scope)
end_define

begin_comment
comment|/* Nonzero if NODE has BINDING_LEVEL, rather than BINDING_SCOPE.  */
end_comment

begin_define
define|#
directive|define
name|BINDING_HAS_LEVEL_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_2 (NODE)
end_define

begin_comment
comment|/* This is the declaration bound to the name. Possible values:    variable, overloaded function, namespace, template, enumerator.  */
end_comment

begin_define
define|#
directive|define
name|BINDING_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct tree_binding*)CPLUS_BINDING_CHECK (NODE))->value)
end_define

begin_comment
comment|/* If name is bound to a type, this is the type (struct, union, enum).  */
end_comment

begin_define
define|#
directive|define
name|BINDING_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_TYPE (NODE)
end_define

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
name|CLEANUP_DECL
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
comment|/* Non-zero if we are presently building a statement tree, rather    than expanding each statement as we encounter it.  */
end_comment

begin_define
define|#
directive|define
name|building_stmt_tree
parameter_list|()
value|(last_tree != NULL_TREE)
end_define

begin_comment
comment|/* Returns non-zero iff NODE is a declaration for the global function    `main'.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAIN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_EXTERN_C_FUNCTION_P (NODE)                     \&& DECL_NAME (NODE) != NULL_TREE			\&& MAIN_NAME_P (DECL_NAME (NODE)))
end_define

begin_struct
struct|struct
name|tree_binding
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
union|union
block|{
name|tree
name|scope
decl_stmt|;
name|struct
name|binding_level
modifier|*
name|level
decl_stmt|;
block|}
name|scope
union|;
name|tree
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The overloaded FUNCTION_DECL. */
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
comment|/* Polymorphic access to FUNCTION and CHAIN. */
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
comment|/* If set, this was imported in a using declaration.    This is not to confuse with being used somewhere, which    is not important for this node. */
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

begin_struct
struct|struct
name|tree_overload
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|tree
name|function
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A `baselink' is a TREE_LIST whose TREE_PURPOSE is a BINFO    indicating a particular base class, and whose TREE_VALUE is a    (possibly overloaded) function from that base class.  */
end_comment

begin_define
define|#
directive|define
name|BASELINK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TREE_LIST&& TREE_LANG_FLAG_1 (NODE))
end_define

begin_define
define|#
directive|define
name|SET_BASELINK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_1 (NODE) = 1)
end_define

begin_define
define|#
directive|define
name|WRAPPER_PTR
parameter_list|(
name|NODE
parameter_list|)
value|(((struct tree_wrapper*)WRAPPER_CHECK (NODE))->u.ptr)
end_define

begin_define
define|#
directive|define
name|WRAPPER_INT
parameter_list|(
name|NODE
parameter_list|)
value|(((struct tree_wrapper*)WRAPPER_CHECK (NODE))->u.i)
end_define

begin_struct
struct|struct
name|tree_wrapper
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SRCLOC_FILE
parameter_list|(
name|NODE
parameter_list|)
value|(((struct tree_srcloc*)SRCLOC_CHECK (NODE))->filename)
end_define

begin_define
define|#
directive|define
name|SRCLOC_LINE
parameter_list|(
name|NODE
parameter_list|)
value|(((struct tree_srcloc*)SRCLOC_CHECK (NODE))->linenum)
end_define

begin_struct
struct|struct
name|tree_srcloc
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|linenum
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* The IDENTIFIER_BINDING is the innermost CPLUS_BINDING for the     identifier.  It's TREE_CHAIN is the next outermost binding.  Each     BINDING_VALUE is a DECL for the associated declaration.  Thus,     name lookup consists simply of pulling off the node at the front     of the list (modulo oddities for looking up the names of types,     and such.)  You can use BINDING_SCOPE or BINDING_LEVEL to     determine the scope that bound the name.  */
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
comment|/* The IDENTIFIER_VALUE is the value of the IDENTIFIER_BINDING, or    NULL_TREE if there is no binding.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_BINDING (NODE)			\    ? BINDING_VALUE (IDENTIFIER_BINDING (NODE))	\    : NULL_TREE)
end_define

begin_comment
comment|/* If IDENTIFIER_CLASS_VALUE is set, then NODE is bound in the current    class, and IDENTIFIER_CLASS_VALUE is the value binding.  This is    just a pointer to the BINDING_VALUE of one of the bindings in the    IDENTIFIER_BINDINGs list, so any time that this is non-NULL so is    IDENTIFIER_BINDING.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_CLASS_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LANG_IDENTIFIER_CAST (NODE)->class_value)
end_define

begin_comment
comment|/* TREE_TYPE only indicates on local and class scope the current    type. For namespace scope, the presence of a type in any namespace    is indicated with global_type_node, and the real type behind must    be found through lookup. */
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
name|LANG_ID_FIELD
parameter_list|(
name|NAME
parameter_list|,
name|NODE
parameter_list|)
define|\
value|(LANG_IDENTIFIER_CAST (NODE)->x			\    ? LANG_IDENTIFIER_CAST (NODE)->x->NAME : 0)
end_define

begin_define
define|#
directive|define
name|SET_LANG_ID
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|(LANG_IDENTIFIER_CAST (NODE)->x == 0				  	  \    ? LANG_IDENTIFIER_CAST (NODE)->x					  \       = (struct lang_id2 *)perm_calloc (1, sizeof (struct lang_id2)) : 0, \    LANG_IDENTIFIER_CAST (NODE)->x->NAME = (VALUE))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|LANG_ID_FIELD (label_value, NODE)
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
value|SET_LANG_ID (NODE, VALUE, label_value)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|LANG_ID_FIELD (implicit_decl, NODE)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|SET_LANG_ID (NODE, VALUE, implicit_decl)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|LANG_ID_FIELD (error_locus, NODE)
end_define

begin_define
define|#
directive|define
name|SET_IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|SET_LANG_ID (NODE, VALUE, error_locus)
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
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is read-only.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_READONLY
parameter_list|(
name|TYPE
parameter_list|)
value|TYPE_LANG_FLAG_0 (TYPE)
end_define

begin_comment
comment|/* Store a value in that field.  */
end_comment

begin_define
define|#
directive|define
name|C_SET_EXP_ORIGINAL_CODE
parameter_list|(
name|EXP
parameter_list|,
name|CODE
parameter_list|)
define|\
value|(TREE_COMPLEXITY (EXP) = (int)(CODE))
end_define

begin_escape
end_escape

begin_comment
comment|/* If non-zero, a VAR_DECL whose cleanup will cause a throw to the    next exception handler.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|exception_throw_decl
decl_stmt|;
end_decl_stmt

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
name|CPTI_TI_DESC_TYPE
block|,
name|CPTI_BLTN_DESC_TYPE
block|,
name|CPTI_PTR_DESC_TYPE
block|,
name|CPTI_ARY_DESC_TYPE
block|,
name|CPTI_FUNC_DESC_TYPE
block|,
name|CPTI_ENUM_DESC_TYPE
block|,
name|CPTI_CLASS_DESC_TYPE
block|,
name|CPTI_SI_CLASS_DESC_TYPE
block|,
name|CPTI_VMI_CLASS_DESC_TYPE
block|,
name|CPTI_PTM_DESC_TYPE
block|,
name|CPTI_BASE_DESC_TYPE
block|,
name|CPTI_CLASS_TYPE
block|,
name|CPTI_RECORD_TYPE
block|,
name|CPTI_UNION_TYPE
block|,
name|CPTI_ENUM_TYPE
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
name|CPTI_TYPE_INFO_TYPE
block|,
name|CPTI_TINFO_DECL_TYPE
block|,
name|CPTI_ABORT_FNDECL
block|,
name|CPTI_GLOBAL_DELETE_FNDECL
block|,
name|CPTI_AGGR_TAG
block|,
name|CPTI_ACCESS_DEFAULT
block|,
name|CPTI_ACCESS_PUBLIC
block|,
name|CPTI_ACCESS_PROTECTED
block|,
name|CPTI_ACCESS_PRIVATE
block|,
name|CPTI_ACCESS_DEFAULT_VIRTUAL
block|,
name|CPTI_ACCESS_PUBLIC_VIRTUAL
block|,
name|CPTI_ACCESS_PROTECTED_VIRTUAL
block|,
name|CPTI_ACCESS_PRIVATE_VIRTUAL
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
name|CPTI_NULL
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
name|CPTI_MAX
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
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
name|ti_desc_type_node
value|cp_global_trees[CPTI_TI_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|bltn_desc_type_node
value|cp_global_trees[CPTI_BLTN_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|ptr_desc_type_node
value|cp_global_trees[CPTI_PTR_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|ary_desc_type_node
value|cp_global_trees[CPTI_ARY_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|func_desc_type_node
value|cp_global_trees[CPTI_FUNC_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|enum_desc_type_node
value|cp_global_trees[CPTI_ENUM_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|class_desc_type_node
value|cp_global_trees[CPTI_CLASS_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|si_class_desc_type_node
value|cp_global_trees[CPTI_SI_CLASS_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|vmi_class_desc_type_node
value|cp_global_trees[CPTI_VMI_CLASS_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|ptm_desc_type_node
value|cp_global_trees[CPTI_PTM_DESC_TYPE]
end_define

begin_define
define|#
directive|define
name|base_desc_type_node
value|cp_global_trees[CPTI_BASE_DESC_TYPE]
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
name|record_type_node
value|cp_global_trees[CPTI_RECORD_TYPE]
end_define

begin_define
define|#
directive|define
name|union_type_node
value|cp_global_trees[CPTI_UNION_TYPE]
end_define

begin_define
define|#
directive|define
name|enum_type_node
value|cp_global_trees[CPTI_ENUM_TYPE]
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
name|type_info_type_node
value|cp_global_trees[CPTI_TYPE_INFO_TYPE]
end_define

begin_define
define|#
directive|define
name|tinfo_decl_type
value|cp_global_trees[CPTI_TINFO_DECL_TYPE]
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
comment|/* Define the sets of attributes that member functions and baseclasses    can have.  These are sensible combinations of {public,private,protected}    cross {virtual,non-virtual}.  */
end_comment

begin_define
define|#
directive|define
name|access_default_node
value|cp_global_trees[CPTI_ACCESS_DEFAULT]
end_define

begin_define
define|#
directive|define
name|access_public_node
value|cp_global_trees[CPTI_ACCESS_PUBLIC]
end_define

begin_define
define|#
directive|define
name|access_protected_node
value|cp_global_trees[CPTI_ACCESS_PROTECTED]
end_define

begin_define
define|#
directive|define
name|access_private_node
value|cp_global_trees[CPTI_ACCESS_PRIVATE]
end_define

begin_define
define|#
directive|define
name|access_default_virtual_node
value|cp_global_trees[CPTI_ACCESS_DEFAULT_VIRTUAL]
end_define

begin_define
define|#
directive|define
name|access_public_virtual_node
value|cp_global_trees[CPTI_ACCESS_PUBLIC_VIRTUAL]
end_define

begin_define
define|#
directive|define
name|access_protected_virtual_node
value|cp_global_trees[CPTI_ACCESS_PROTECTED_VIRTUAL]
end_define

begin_define
define|#
directive|define
name|access_private_virtual_node
value|cp_global_trees[CPTI_ACCESS_PRIVATE_VIRTUAL]
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
comment|/* The node for `__null'.  */
end_comment

begin_define
define|#
directive|define
name|null_node
value|cp_global_trees[CPTI_NULL]
end_define

begin_comment
comment|/* If non-NULL, a POINTER_TYPE equivalent to (java::lang::Class*). */
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
comment|/* Global state.  */
end_comment

begin_struct
struct|struct
name|saved_scope
block|{
name|tree
name|old_bindings
decl_stmt|;
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
name|varray_type
name|lang_base
decl_stmt|;
name|tree
name|lang_name
decl_stmt|;
name|tree
name|template_parms
decl_stmt|;
name|tree
name|x_previous_class_type
decl_stmt|;
name|tree
name|x_previous_class_values
decl_stmt|;
name|tree
name|x_saved_tree
decl_stmt|;
name|tree
name|incomplete
decl_stmt|;
name|tree
name|lookups
decl_stmt|;
name|HOST_WIDE_INT
name|x_processing_template_decl
decl_stmt|;
name|int
name|x_processing_specialization
decl_stmt|;
name|int
name|x_processing_explicit_instantiation
decl_stmt|;
name|int
name|need_pop_function_context
decl_stmt|;
name|struct
name|stmt_tree_s
name|x_stmt_tree
decl_stmt|;
name|struct
name|binding_level
modifier|*
name|class_bindings
decl_stmt|;
name|struct
name|binding_level
modifier|*
name|bindings
decl_stmt|;
name|struct
name|saved_scope
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* The stack for namespaces of current declarations. */
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
comment|/* _TYPE: the previous type that was a class */
end_comment

begin_define
define|#
directive|define
name|previous_class_type
value|scope_chain->x_previous_class_type
end_define

begin_comment
comment|/* This is a copy of the class_shadowed list of the previous class    binding contour when at global scope.  It's used to reset    IDENTIFIER_CLASS_VALUEs when entering another class scope (i.e. a    cache miss).  */
end_comment

begin_define
define|#
directive|define
name|previous_class_values
value|scope_chain->x_previous_class_values
end_define

begin_comment
comment|/* A list of the declarations with incomplete type at namespace scope.  */
end_comment

begin_define
define|#
directive|define
name|namespace_scope_incomplete
value|scope_chain->incomplete
end_define

begin_comment
comment|/* A list of private types mentioned, for deferred access checking.  */
end_comment

begin_define
define|#
directive|define
name|type_lookups
value|scope_chain->lookups
end_define

begin_decl_stmt
specifier|extern
name|struct
name|saved_scope
modifier|*
name|scope_chain
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|unparsed_text
struct_decl|;
end_struct_decl

begin_comment
comment|/* Global state pertinent to the current function.  */
end_comment

begin_struct
struct|struct
name|cp_language_function
block|{
name|struct
name|language_function
name|base
decl_stmt|;
name|tree
name|x_dtor_label
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
name|tree
modifier|*
name|x_vcalls_possible_p
decl_stmt|;
name|int
name|returns_value
decl_stmt|;
name|int
name|returns_null
decl_stmt|;
name|int
name|in_function_try_handler
decl_stmt|;
name|int
name|x_expanding_p
decl_stmt|;
name|struct
name|named_label_use_list
modifier|*
name|x_named_label_uses
decl_stmt|;
name|struct
name|named_label_list
modifier|*
name|x_named_labels
decl_stmt|;
name|struct
name|binding_level
modifier|*
name|bindings
decl_stmt|;
name|varray_type
name|x_local_names
decl_stmt|;
specifier|const
name|char
modifier|*
name|cannot_inline
decl_stmt|;
name|struct
name|unparsed_text
modifier|*
name|unparsed_inlines
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The current C++-specific per-function global variables.  */
end_comment

begin_define
define|#
directive|define
name|cp_function_chain
define|\
value|((struct cp_language_function *) (cfun->language))
end_define

begin_comment
comment|/* In a destructor, the point at which all derived class destroying    has been done, just before any base class destroying will be done.  */
end_comment

begin_define
define|#
directive|define
name|dtor_label
value|cp_function_chain->x_dtor_label
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
comment|/* In destructors, this is a pointer to a condition in an    if-statement.  If the pointed-to value is boolean_true_node, then    there may be virtual function calls in this destructor.  */
end_comment

begin_define
define|#
directive|define
name|current_vcalls_possible_p
value|cp_function_chain->x_vcalls_possible_p
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
comment|/* Non-zero if we should generate RTL for functions that we process.    When this is zero, we just accumulate tree structure, without    interacting with the back end.  */
end_comment

begin_define
define|#
directive|define
name|expanding_p
value|cp_function_chain->x_expanding_p
end_define

begin_comment
comment|/* Non-zero if we are in the semantic analysis phase for the current    function.  */
end_comment

begin_define
define|#
directive|define
name|doing_semantic_analysis_p
parameter_list|()
value|(!expanding_p)
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

begin_decl_stmt
specifier|extern
name|tree
name|global_namespace
decl_stmt|;
end_decl_stmt

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
comment|/* Nonzero means `$' can be in an identifier.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dollars_in_ident
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't recognize the keyword `asm'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_asm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't recognize any extended keywords.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_gnu_keywords
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means recognize the named operators from C++98.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_operator_names
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For cross referencing.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gnu_xref
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For environments where you can use GNU binutils (as, ld in particular).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gnu_binutils
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about implicit declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_implicit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn when all ctors or dtors are private, and the class    has no friends.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_ctor_dtor_privacy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about deprecated conversion from string constant to    `char *'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_write_strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about multiple (redundant) decls for the same single    variable or function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_redundant_decls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if initializer is not completely bracketed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_missing_braces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about comparison of signed and unsigned values.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_sign_compare
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about testing equality of floating point numbers. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_float_equal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about a subscript that has type char.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_char_subscripts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about pointer casts that can drop a type qualifier    from the pointer target type.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_cast_qual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about non virtual destructors in classes that have    virtual functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nonvdtor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means warn when we convert a pointer to member function    into a pointer to (void or function).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_pmf2ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about violation of some Effective C++ style rules.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_ecpp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn where overload resolution chooses a promotion from    unsigned to signed over a conversion to an unsigned of the same size.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_sign_promo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means warn when an old-style cast is used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_old_style_cast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means warn when the compiler will reorder code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_reorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means warn about deprecated features.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_deprecated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means to treat bitfields as unsigned unless they say `signed'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_signed_bitfields
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* INTERFACE_ONLY nonzero means that we are in an "interface"    section of the compiler.  INTERFACE_UNKNOWN nonzero means    we cannot trust the value of INTERFACE_ONLY.  If INTERFACE_UNKNOWN    is zero and INTERFACE_ONLY is zero, it means that we are responsible    for exporting definitions that others might need.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interface_only
decl_stmt|,
name|interface_unknown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we should attempt to elide constructors when possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_elide_constructors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means enable obscure standard features and disable GNU    extensions that might cause standard-compliant code to be    miscompiled.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ansi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that member functions defined in class scope are    inline by default.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_default_inline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means generate separate instantiation control files and juggle    them at link time.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_use_repository
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to issue diagnostics that the standard says are not    required.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_optional_diags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means output .vtable_{entry,inherit} for use in doing vtable gc.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_vtable_gc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means make the default pedwarns warnings instead of errors.    The value of this flag is ignored if -pedantic is specified.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_permissive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means to implement standard semantics for exception    specifications, calling unexpected if an exception is thrown that    doesn't match the specification.  Zero means to treat them as    assertions and optimize accordingly, but not check them.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_enforce_eh_specs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to obey access control semantics.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_access_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to check the return value of new and avoid calling    constructors if it is a null pointer.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_check_new
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|TYPE_ASSEMBLER_NAME_STRING
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (TYPE_NAME  (NODE))))
end_define

begin_define
define|#
directive|define
name|TYPE_ASSEMBLER_NAME_LENGTH
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_LENGTH (DECL_ASSEMBLER_NAME (TYPE_NAME (NODE))))
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
comment|/* Nonzero if T is a class (or struct or union) type.  Also nonzero    for template type parameters, typename types, and instantiated    template template parameters.  Despite its name,    this macro has nothing to do with the definition of aggregate given    in the standard.  Think of this macro as MAYBE_CLASS_TYPE_P.  */
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
value|(IS_AGGR_TYPE_CODE (TREE_CODE (T))&& IS_AGGR_TYPE (T))
end_define

begin_define
define|#
directive|define
name|IS_AGGR_TYPE_CODE
parameter_list|(
name|T
parameter_list|)
value|((T) == RECORD_TYPE || (T) == UNION_TYPE)
end_define

begin_define
define|#
directive|define
name|IS_AGGR_TYPE_2
parameter_list|(
name|TYPE1
parameter_list|,
name|TYPE2
parameter_list|)
define|\
value|(TREE_CODE (TYPE1) == TREE_CODE (TYPE2)	\&& IS_AGGR_TYPE (TYPE1)&& IS_AGGR_TYPE (TYPE2))
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
comment|/* In a *_TYPE, nonzero means a built-in type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BUILT_IN
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_LANG_FLAG_6 (NODE)
end_define

begin_comment
comment|/* True if this a "Java" type, defined in 'extern "Java"'. */
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
value|lookup_base ((TYPE), PARENT, ba_any, NULL)
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
value|lookup_base ((TYPE), (PARENT), ba_ignore | ba_quiet, NULL)
end_define

begin_comment
comment|/* Nonzero iff TYPE is accessible in the current scope and uniquely    derived from PARENT.  */
end_comment

begin_define
define|#
directive|define
name|ACCESSIBLY_UNIQUELY_DERIVED_P
parameter_list|(
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|lookup_base ((TYPE), (PARENT), ba_check | ba_quiet, NULL)
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
value|lookup_base ((TYPE), (PARENT),  ba_not_special | ba_quiet, NULL)
end_define

begin_escape
end_escape

begin_comment
comment|/* This structure provides additional information above and beyond    what is provide in the ordinary tree_type.  In the past, we used it    for the types of class types, template parameters types, typename    types, and so forth.  However, there can be many (tens to hundreds    of thousands) of template parameter types in a compilation, and    there's no need for this additional information in that case.    Therefore, we now use this data structure only for class types.     In the past, it was thought that there would be relatively few    class types.  However, in the presence of heavy use of templates,    many (i.e., thousands) of classes can easily be generated.    Therefore, we should endeavor to keep the size of this structure to    a minimum.  */
end_comment

begin_struct
struct|struct
name|lang_type
block|{
name|unsigned
name|char
name|align
decl_stmt|;
name|unsigned
name|has_type_conversion
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_init_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_default_ctor
range|:
literal|1
decl_stmt|;
name|unsigned
name|uses_multiple_inheritance
range|:
literal|1
decl_stmt|;
name|unsigned
name|const_needs_init
range|:
literal|1
decl_stmt|;
name|unsigned
name|ref_needs_init
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_const_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|anon_aggr
range|:
literal|1
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
name|has_call_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_array_ref_overloaded
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_arrow_overloaded
range|:
literal|1
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
name|needs_virtual_reinit
range|:
literal|1
decl_stmt|;
name|unsigned
name|marks
range|:
literal|6
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
name|being_defined
range|:
literal|1
decl_stmt|;
name|unsigned
name|redefined
range|:
literal|1
decl_stmt|;
name|unsigned
name|debug_requested
range|:
literal|1
decl_stmt|;
name|unsigned
name|use_template
range|:
literal|2
decl_stmt|;
name|unsigned
name|got_semicolon
range|:
literal|1
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
name|has_real_assign_ref
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
name|has_abstract_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|non_aggregate
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_partial_instantiation
range|:
literal|1
decl_stmt|;
name|unsigned
name|java_interface
range|:
literal|1
decl_stmt|;
comment|/* When adding a flag here, consider whether or not it ought to      apply to a template instance if it applies to the template.  If      so, make sure to copy it in instantiate_class_template!  */
comment|/* There are some bits left to fill out a 32-bit word.  Keep track      of this by updating the size of this bitfield whenever you add or      remove a flag.  */
name|unsigned
name|dummy
range|:
literal|8
decl_stmt|;
name|int
name|vsize
decl_stmt|;
name|tree
name|primary_base
decl_stmt|;
name|tree
name|vfields
decl_stmt|;
name|tree
name|vbases
decl_stmt|;
name|tree
name|tags
decl_stmt|;
name|tree
name|size
decl_stmt|;
name|tree
name|size_unit
decl_stmt|;
name|tree
name|pure_virtuals
decl_stmt|;
name|tree
name|friend_classes
decl_stmt|;
name|tree
name|rtti
decl_stmt|;
name|tree
name|methods
decl_stmt|;
name|tree
name|template_info
decl_stmt|;
name|tree
name|befriending_classes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Indicates whether or not (and how) a template was expanded for this class.      0=no information yet/non-template class      1=implicit template instantiation      2=explicit template specialization      3=explicit template instantiation  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_USE_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->use_template)
end_define

begin_comment
comment|/* Fields used for storing information before the class is defined.    After the class is defined, these fields hold other information.  */
end_comment

begin_comment
comment|/* List of friends which were defined inline in this class definition.  */
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
value|(TYPE_LANG_SPECIFIC (NODE)->gets_delete)
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
value|(CLASS_TYPE_P (NODE)					\&& TYPE_LANG_SPECIFIC (NODE)->vec_new_uses_cookie)
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
value|(TYPE_LANG_SPECIFIC (NODE)->has_type_conversion)
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
value|(TYPE_LANG_SPECIFIC (NODE)->has_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_CONST_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->has_const_assign_ref)
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
value|(TYPE_LANG_SPECIFIC (NODE)->has_init_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_CONST_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->has_const_init_ref)
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
value|(TYPE_LANG_SPECIFIC (NODE)->has_new)
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
value|(TYPE_LANG_SPECIFIC (NODE)->has_array_new)
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
value|(TYPE_LANG_SPECIFIC (NODE)->being_defined)
end_define

begin_comment
comment|/* Nonzero means that this type has been redefined.  In this case, if    convenient, don't reprocess any methods that appear in its redefinition.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_REDEFINED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->redefined)
end_define

begin_comment
comment|/* The is the basetype that contains NODE's rtti.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_RTTI
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->rtti)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator().  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_CALL_EXPR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->has_call_overloaded)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator[].  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_ARRAY_REF
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->has_array_ref_overloaded)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE node overloads operator->.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERLOADS_ARROW
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->has_arrow_overloaded)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE (or one of its ancestors) uses    multiple inheritance.  If this is 0 for the root of a type    hierarchy, then we can use more efficient search techniques.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_MULTIPLE_INHERITANCE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->uses_multiple_inheritance)
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE (or one of its ancestors) uses    virtual base classes.  If this is 0 for the root of a type    hierarchy, then we can use more efficient search techniques.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_VIRTUAL_BASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_3 (NODE))
end_define

begin_comment
comment|/* Vector member functions defined in this class.  Each element is    either a FUNCTION_DECL, a TEMPLATE_DECL, or an OVERLOAD.  All    functions with the same name end up in the same slot.  The first    two elements are for constructors, and destructors, respectively.    Any conversion operators are next, followed by ordinary member    functions.  There may be empty entries at the end of the vector.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_METHOD_VEC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->methods)
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
value|(TREE_VEC_ELT (CLASSTYPE_METHOD_VEC (NODE), CLASSTYPE_CONSTRUCTOR_SLOT))
end_define

begin_comment
comment|/* A FUNCTION_DECL for the destructor for NODE.  These are the    destructors that take an in-charge parameter.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_DESTRUCTORS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VEC_ELT (CLASSTYPE_METHOD_VEC (NODE), CLASSTYPE_DESTRUCTOR_SLOT))
end_define

begin_comment
comment|/* Mark bits for depth-first and breath-first searches.  */
end_comment

begin_comment
comment|/* Get the value of the Nth mark bit.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED_N
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
define|\
value|(((CLASS_TYPE_P (NODE) ? TYPE_LANG_SPECIFIC (NODE)->marks	\      : ((unsigned) TYPE_ALIAS_SET (NODE)))& (1<< (N))) != 0)
end_define

begin_comment
comment|/* Set the Nth mark bit.  */
end_comment

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED_N
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
define|\
value|(CLASS_TYPE_P (NODE)						\    ? (void) (TYPE_LANG_SPECIFIC (NODE)->marks |= (1<< (N)))	\    : (void) (TYPE_ALIAS_SET (NODE) |= (1<< (N))))
end_define

begin_comment
comment|/* Clear the Nth mark bit.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED_N
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
define|\
value|(CLASS_TYPE_P (NODE)						\    ? (void) (TYPE_LANG_SPECIFIC (NODE)->marks&= ~(1<< (N)))	\    : (void) (TYPE_ALIAS_SET (NODE)&= ~(1<< (N))))
end_define

begin_comment
comment|/* Get the value of the mark bits.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N (NODE, 0)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N (NODE, 1)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N (NODE, 2)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N (NODE, 3)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N (NODE, 4)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N (NODE, 5)
end_define

begin_comment
comment|/* Macros to modify the above flags */
end_comment

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N (NODE, 0)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N (NODE, 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N (NODE, 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N (NODE, 1)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N (NODE, 2)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N (NODE, 2)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N (NODE, 3)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N (NODE, 3)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N (NODE, 4)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N (NODE, 4)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N (NODE, 5)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N (NODE, 5)
end_define

begin_comment
comment|/* A list of the nested tag-types (class, struct, union, or enum)    found within this class.  The TREE_PURPOSE of each node is the name    of the type; the TREE_VALUE is the type itself.  This list includes    nested member class templates.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_TAGS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->tags)
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
value|(TYPE_LANG_SPECIFIC (NODE)->primary_base)
end_define

begin_comment
comment|/* The number of virtual functions present in this class' virtual    function table.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VSIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->vsize)
end_define

begin_comment
comment|/* A chain of BINFOs for the direct and indirect virtual base classes    that this type uses in a post-order depth-first left-to-right    order.  (In other words, these bases appear in the order that they    should be initialized.)  If a virtual base is primary, then the    primary copy will appear on this list.  Thus, the BINFOs on this    list are all "real"; they are the same BINFOs that will be    encountered when using dfs_unmarked_real_bases_queue_p and related    functions.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VBASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->vbases)
end_define

begin_comment
comment|/* For a non-virtual BINFO, the BINFO itself; for a virtual BINFO, the    binfo_for_vbase.  C is the most derived class for the hierarchy    containing BINFO.  */
end_comment

begin_define
define|#
directive|define
name|CANONICAL_BINFO
parameter_list|(
name|BINFO
parameter_list|,
name|C
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL (BINFO)			\    ? binfo_for_vbase (BINFO_TYPE (BINFO), C)	\    : (BINFO))
end_define

begin_comment
comment|/* Number of direct baseclasses of NODE.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_N_BASECLASSES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(BINFO_N_BASETYPES (TYPE_BINFO (NODE)))
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
value|(TYPE_LANG_SPECIFIC (NODE)->size)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->size_unit)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->align)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_USER_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->user_align)
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
comment|/* True if this a Java interface type, declared with     '__attribute__ ((java_interface))'. */
end_comment

begin_define
define|#
directive|define
name|TYPE_JAVA_INTERFACE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->java_interface)
end_define

begin_comment
comment|/* A cons list of virtual functions which cannot be inherited by    derived classes.  When deriving from this type, the derived    class must provide its own definition for each of these functions.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_PURE_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->pure_virtuals)
end_define

begin_comment
comment|/* Nonzero means that this aggr type has been `closed' by a semicolon.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_GOT_SEMICOLON
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->got_semicolon)
end_define

begin_comment
comment|/* Nonzero means that the main virtual function table pointer needs to be    set because base constructors have placed the wrong value there.    If this is zero, it means that they placed the right value there,    and there is no need to change it.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NEEDS_VIRTUAL_REINIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->needs_virtual_reinit)
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
value|(TYPE_LANG_SPECIFIC (NODE)->has_default_ctor)
end_define

begin_comment
comment|/* Nonzero means that this type contains a mutable member */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_HAS_MUTABLE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->has_mutable)
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
comment|/*  Nonzero means that this class type is a non-POD class.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_NON_POD_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->non_pod_class)
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
value|(TYPE_LANG_SPECIFIC (NODE)->nearly_empty_p)
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
value|(TYPE_LANG_SPECIFIC (NODE)->friend_classes)
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
value|(TYPE_LANG_SPECIFIC (NODE)->befriending_classes)
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
value|(TYPE_LANG_SPECIFIC (NODE)->declared_class)
end_define

begin_comment
comment|/* Nonzero if this class has const members which have no specified initialization.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_READONLY_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->const_needs_init)
end_define

begin_comment
comment|/* Nonzero if this class has ref members which have no specified initialization.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_REF_FIELDS_NEED_INIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->ref_needs_init)
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
value|(TYPE_LANG_SPECIFIC (NODE)->interface_only)
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
value|(TYPE_LANG_SPECIFIC (NODE)->interface_unknown == 0)
end_define

begin_comment
comment|/* The opposite of CLASSTYPE_INTERFANCE_KNOWN.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_UNKNOWN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->interface_unknown)
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
value|(TYPE_LANG_SPECIFIC (NODE)->interface_unknown = !!(X))
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_INTERFACE_UNKNOWN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->interface_unknown = 1)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_INTERFACE_KNOWN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->interface_unknown = 0)
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
value|(TYPE_LANG_SPECIFIC (NODE)->debug_requested)
end_define

begin_escape
end_escape

begin_comment
comment|/* Additional macros for inheritance information.  */
end_comment

begin_comment
comment|/* The BINFO_INHERITANCE_CHAIN is used opposite to the description in    gcc/tree.h.  In particular if D is derived from B then the BINFO    for B (in D) will have a BINFO_INHERITANCE_CHAIN pointing to    D.  In tree.h, this pointer is described as pointing in other    direction.  There is a different BINFO for each path to a virtual    base; BINFOs for virtual bases are not shared.     We use TREE_VIA_PROTECTED and TREE_VIA_PUBLIC, but private    inheritance is indicated by the absence of the other two flags, not    by TREE_VIA_PRIVATE, which is unused.  */
end_comment

begin_comment
comment|/* Mark the binfo, whether shared or not. Each instance of a virtual    base can be separately marked.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_UNSHARED_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
end_define

begin_comment
comment|/* Nonzero means marked by DFS or BFS search.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL (NODE)			\    ? CLASSTYPE_MARKED (BINFO_TYPE (NODE))	\    : TREE_LANG_FLAG_0 (NODE))
end_define

begin_comment
comment|/* Macros needed because of C compilers that don't allow conditional    expressions to be lvalues.  Grr!  */
end_comment

begin_define
define|#
directive|define
name|SET_BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL(NODE)			\    ? SET_CLASSTYPE_MARKED (BINFO_TYPE (NODE))	\    : (TREE_LANG_FLAG_0 (NODE) = 1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL (NODE)			\    ? CLEAR_CLASSTYPE_MARKED (BINFO_TYPE (NODE))	\    : (TREE_LANG_FLAG_0 (NODE) = 0))
end_define

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
define|\
value|(TREE_VIA_VIRTUAL (NODE)			\    ? CLASSTYPE_MARKED3 (BINFO_TYPE (NODE))	\    : TREE_LANG_FLAG_3 (NODE))
end_define

begin_define
define|#
directive|define
name|SET_BINFO_VTABLE_PATH_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL(NODE)			\    ? SET_CLASSTYPE_MARKED3 (BINFO_TYPE (NODE))	\    : (TREE_LANG_FLAG_3 (NODE) = 1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_VTABLE_PATH_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL (NODE)			\    ? CLEAR_CLASSTYPE_MARKED3 (BINFO_TYPE (NODE))\    : (TREE_LANG_FLAG_3 (NODE) = 0))
end_define

begin_comment
comment|/* Nonzero means B (a BINFO) has its own vtable.  Under the old ABI,    secondary vtables are sometimes shared.  Any copies will not have    this flag set.     B is part of the hierarchy dominated by C.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|B
parameter_list|,
name|C
parameter_list|)
define|\
value|(TREE_LANG_FLAG_4 (CANONICAL_BINFO (B, C)))
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
parameter_list|,
name|C
parameter_list|)
define|\
value|(BINFO_NEW_VTABLE_MARKED (B, C) = 1,					 \    my_friendly_assert (!BINFO_PRIMARY_P (B)				 \ 		       || TREE_VIA_VIRTUAL (B), 20000517),		 \    my_friendly_assert (CLASSTYPE_VFIELDS (BINFO_TYPE (B)) != NULL_TREE,  \ 		       20000517))
end_define

begin_comment
comment|/* Nonzero means this class has done dfs_pushdecls.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_PUSHDECLS_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_VTABLE_PATH_MARKED (NODE)
end_define

begin_define
define|#
directive|define
name|SET_BINFO_PUSHDECLS_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|SET_BINFO_VTABLE_PATH_MARKED (NODE)
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_PUSHDECLS_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_BINFO_VTABLE_PATH_MARKED (NODE)
end_define

begin_comment
comment|/* Nonzero if this BINFO is a primary base class.     In the TYPE_BINFO hierarchy, this flag is never set for a base    class of a non-primary virtual base.  This flag is only valid for    paths (given by BINFO_INHERITANCE_CHAIN) that really exist in the    final object.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_PRIMARY_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(BINFO_PRIMARY_BASE_OF (NODE) != NULL_TREE)
end_define

begin_comment
comment|/* The index in the VTT where this subobject's sub-VTT can be found.    NULL_TREE if there is no sub-VTT.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_SUBVTT_INDEX
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT (NODE, 8)
end_define

begin_comment
comment|/* The index in the VTT where the vptr for this subobject can be    found.  NULL_TREE if there is no secondary vptr in the VTT.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VPTR_INDEX
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT (NODE, 9)
end_define

begin_comment
comment|/* The binfo of which NODE is a primary base.  (This is different from    BINFO_INHERITANCE_CHAIN for virtual base because a virtual base is    sometimes a primary base for a class for which it is not an    immediate base.)  */
end_comment

begin_define
define|#
directive|define
name|BINFO_PRIMARY_BASE_OF
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT (NODE, 10)
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
value|TREE_LANG_FLAG_2 (NODE)
end_define

begin_comment
comment|/* Nonzero if this binfo is an indirect primary base, i.e. a virtual    base that is a primary base of some of other class in the    hierarchy.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_INDIRECT_PRIMARY_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_USED (NODE)
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
comment|/* Accessor macros for the vfield slots in structures.  */
end_comment

begin_comment
comment|/* The virtual function pointer fields that this type contains.  For a    vfield defined just for this class, or from a primary base, the    TREE_PURPOSE is NULL.  Otherwise, the TREE_PURPOSE is the BINFO for    the class containing the vfield.  The TREE_VALUE is the class where    the vfield was first defined.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VFIELDS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->vfields)
end_define

begin_comment
comment|/* Get the assoc info that caused this vfield to exist.  */
end_comment

begin_define
define|#
directive|define
name|VF_BINFO_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_PURPOSE (NODE)
end_define

begin_comment
comment|/* Get that same information as a _TYPE.  */
end_comment

begin_define
define|#
directive|define
name|VF_BASETYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VALUE (NODE)
end_define

begin_comment
comment|/* Get the value of the top-most type dominating the non-`normal' vfields.  */
end_comment

begin_define
define|#
directive|define
name|VF_DERIVED_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VF_BINFO_VALUE (NODE) ? BINFO_TYPE (VF_BINFO_VALUE (NODE)) : NULL_TREE)
end_define

begin_comment
comment|/* The number of bytes by which to adjust the `this' pointer when    calling this virtual function.  */
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
comment|/* If non-NULL, the vtable index at which to find the vcall offset    when calling this virtual function.  */
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

begin_comment
comment|/* Nonzero if we should use a virtual thunk for this entry.  */
end_comment

begin_define
define|#
directive|define
name|BV_USE_VCALL_INDEX_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_0 (NODE))
end_define

begin_escape
end_escape

begin_comment
comment|/* Nonzero for TREE_LIST node means that this list of things    is a list of parameters, as opposed to a list of expressions.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PARMLIST
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_2 (NODE))
end_define

begin_comment
comment|/* Nonzero for a parmlist means that this parmlist ended in ...  */
end_comment

begin_define
define|#
directive|define
name|PARMLIST_ELLIPSIS_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
end_define

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
value|TYPE_BINFO (NODE)
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
comment|/* If a DECL has DECL_LANG_SPECIFIC, it is either a lang_decl_flags or    a lang_decl (which has lang_decl_flags as its initial prefix).    This macro is nonzero for tree nodes whose DECL_LANG_SPECIFIC is    the full lang_decl, and not just lang_decl_flags.  */
end_comment

begin_define
define|#
directive|define
name|CAN_HAVE_FULL_LANG_DECL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(!(TREE_CODE (NODE) == VAR_DECL		\      || TREE_CODE (NODE) == CONST_DECL		\      || TREE_CODE (NODE) == FIELD_DECL		\      || TREE_CODE (NODE) == USING_DECL))
end_define

begin_struct
struct|struct
name|lang_decl_flags
block|{
name|struct
name|c_lang_decl
name|base
decl_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|languages
argument_list|)
name|language
label|:
literal|8
expr_stmt|;
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
name|needs_final_overrider
range|:
literal|1
decl_stmt|;
name|unsigned
name|initialized_in_class
range|:
literal|1
decl_stmt|;
name|unsigned
name|pending_inline_p
range|:
literal|1
decl_stmt|;
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
name|assignment_operator_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|anticipated_p
range|:
literal|1
decl_stmt|;
comment|/* Four unused bits.  */
union|union
block|{
comment|/* In a FUNCTION_DECL, VAR_DECL, TYPE_DECL, or TEMPLATE_DECL, this        is DECL_TEMPLATE_INFO.  */
name|tree
name|template_info
decl_stmt|;
comment|/* In a NAMESPACE_DECL, this is NAMESPACE_LEVEL.  */
name|struct
name|binding_level
modifier|*
name|level
decl_stmt|;
block|}
name|u
union|;
union|union
block|{
comment|/* This is DECL_ACCESS.  */
name|tree
name|access
decl_stmt|;
comment|/* For VAR_DECL in function, this is DECL_DISCRIMINATOR.  */
name|int
name|discriminator
decl_stmt|;
comment|/* In a namespace-scope FUNCTION_DECL, this is        GLOBAL_INIT_PRIORITY.  */
name|int
name|init_priority
decl_stmt|;
comment|/* In a FUNCTION_DECL for which DECL_THUNK_P holds, this is        THUNK_VCALL_OFFSET.  */
name|tree
name|vcall_offset
decl_stmt|;
block|}
name|u2
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lang_decl
block|{
name|struct
name|lang_decl_flags
name|decl_flags
decl_stmt|;
name|tree
name|befriending_classes
decl_stmt|;
comment|/* For a virtual FUNCTION_DECL, this is DECL_VIRTUAL_CONTEXT.  For a      non-virtual FUNCTION_DECL, this is DECL_FRIEND_CONTEXT.  */
name|tree
name|context
decl_stmt|;
comment|/* In a FUNCTION_DECL, this is DECL_CLONED_FUNCTION.  */
name|tree
name|cloned_function
decl_stmt|;
union|union
block|{
name|tree
name|sorted_fields
decl_stmt|;
name|struct
name|unparsed_text
modifier|*
name|pending_inline_info
decl_stmt|;
name|struct
name|cp_language_function
modifier|*
name|saved_language_function
decl_stmt|;
block|}
name|u
union|;
union|union
block|{
comment|/* In an overloaded operator, this is the value of        DECL_OVERLOADED_OPERATOR_P.  */
name|enum
name|tree_code
name|operator_code
decl_stmt|;
block|}
name|u2
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFARG_POINTER
parameter_list|(
name|NODE
parameter_list|)
value|(DEFAULT_ARG_CHECK (NODE)->identifier.id.str)
end_define

begin_comment
comment|/* DECL_NEEDED_P holds of a declaration when we need to emit its    definition.  This is true when the back-end tells us that    the symbol has been referenced in the generated code.  If, however,    we are not generating code, then it is also true when a symbol has    just been used somewhere, even if it's not really needed.  We need    anything that isn't comdat, but we don't know for sure whether or    not something is comdat until end-of-file.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NEEDED_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|((at_eof&& TREE_PUBLIC (DECL)&& !DECL_COMDAT (DECL))	\    || (DECL_ASSEMBLER_NAME_SET_P (DECL)				\&& TREE_SYMBOL_REFERENCED (DECL_ASSEMBLER_NAME (DECL)))	\    || (flag_syntax_only&& TREE_USED (DECL)))
end_define

begin_comment
comment|/* Non-zero iff DECL is memory-based.  The DECL_RTL of    certain const variables might be a CONST_INT, or a REG    in some cases.  We cannot use `memory_operand' as a test    here because on most RISC machines, a variable's address    is not, by itself, a legitimate address.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IN_MEMORY_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_RTL_SET_P (NODE)&& GET_CODE (DECL_RTL (NODE)) == MEM)
end_define

begin_comment
comment|/* For a FUNCTION_DECL or a VAR_DECL, the language linkage for the    declaration.  Some entities (like a member function in a local    class, or a local variable) do not have linkage at all, and this    macro should not be used in those cases.        Implementation note: A FUNCTION_DECL without DECL_LANG_SPECIFIC was    created by language-independent code, and has C linkage.  Most    VAR_DECLs have C++ linkage, and do not have DECL_LANG_SPECIFIC, but    we do create DECL_LANG_SPECIFIC for variables with non-C++ linkage.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LANGUAGE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE) 				\    ? DECL_LANG_SPECIFIC (NODE)->decl_flags.language	\    : (TREE_CODE (NODE) == FUNCTION_DECL			\       ? lang_c : lang_cplusplus))
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
comment|/* Nonzero if NODE (a FUNCTION_DECL) is a destructor, but not the    specialized in-charge constructor, in-charge deleting constructor,    or the the base destructor.  */
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
value|((TREE_CODE (NODE) == FUNCTION_DECL 		\     || TREE_CODE (NODE) == TEMPLATE_DECL)	\&& DECL_LANG_SPECIFIC (NODE)			\&& DECL_CLONED_FUNCTION (NODE) != NULL_TREE)
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
value|(DECL_LANG_SPECIFIC (NODE)->cloned_function)
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
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.u2.discriminator)
end_define

begin_comment
comment|/* Non-zero if the VTT parm has been added to NODE.  */
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
comment|/* Non-zero if NODE is a FUNCTION_DECL for which a VTT parameter is    required.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NEEDS_VTT_PARM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_USES_VIRTUAL_BASECLASSES (DECL_CONTEXT (NODE))	\&& (DECL_BASE_CONSTRUCTOR_P (NODE)			\        || DECL_BASE_DESTRUCTOR_P (NODE)))
end_define

begin_comment
comment|/* Non-zero if NODE is a user-defined conversion operator.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONV_FN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_TYPENAME_P (DECL_NAME (NODE)))
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
value|(DECL_LANG_SPECIFIC (NODE)->u2.operator_code = (CODE))
end_define

begin_comment
comment|/* If NODE is an overloaded operator, then this returns the TREE_CODE    associcated with the overloaded operator.    DECL_ASSIGNMENT_OPERATOR_P must also be checked to determine    whether or not NODE is an assignment operator.  If NODE is not an    overloaded operator, ERROR_MARK is returned.  Since the numerical    value of ERROR_MARK is zero, this macro can be used as a predicate    to test whether or not NODE is an overloaded operator.  */
end_comment

begin_define
define|#
directive|define
name|DECL_OVERLOADED_OPERATOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_OPNAME_P (DECL_NAME (NODE))		\    ? DECL_LANG_SPECIFIC (NODE)->u2.operator_code : ERROR_MARK)
end_define

begin_comment
comment|/* Non-zero if NODE is an assignment operator.  */
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
comment|/* Nonzero if NODE is an overloaded `operator delete[]' function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ARRAY_DELETE_OPERATOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_OVERLOADED_OPERATOR_P (NODE) == VEC_DELETE_EXPR)
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
comment|/* Nonzero if the DECL was initialized in the class definition itself,    rather than outside the class.  */
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
comment|/* Nonzero for FUNCTION_DECL means that this decl is just a    friend declaration, and should not be added to the list of    member functions for this class.  */
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
value|(DECL_LANG_SPECIFIC (NODE)->befriending_classes)
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
comment|/* Nonzero for FUNCTION_DECL means that this member function    must be overridden by derived classes.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NEEDS_FINAL_OVERRIDER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.needs_final_overrider)
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
value|(TREE_CODE (NODE) == FUNCTION_DECL		\&& DECL_LANG_FLAG_7 (NODE))
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
comment|/* Set DECL_THUNK_P for node.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_THUNK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_7 (NODE) = 1)
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
value|(TREE_LANG_FLAG_0 (NODE))
end_define

begin_comment
comment|/* The _TYPE context in which this _DECL appears.  This field holds the    class where a virtual function instance is actually defined. */
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
value|((DECL_FRIEND_P (NODE)&& !DECL_FUNCTION_MEMBER_P (NODE))	\    ? DECL_LANG_SPECIFIC (NODE)->context                         \    : NULL_TREE)
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
value|(DECL_LANG_SPECIFIC (NODE)->context = (CONTEXT))
end_define

begin_comment
comment|/* NULL_TREE in DECL_CONTEXT represents the global namespace. */
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
name|FROB_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE) == global_namespace ? NULL_TREE : (NODE))
end_define

begin_comment
comment|/* For a virtual function, the base where we find its vtable entry.    For a non-virtual function, the base where it is defined.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VIRTUAL_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->context)
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
comment|/* For a NAMESPACE_DECL: the list of using namespace directives    The PURPOSE is the used namespace, the value is the namespace    that is the common ancestor. */
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
comment|/* In a NAMESPACE_DECL, the DECL_INITIAL is used to record all users    of a namespace, to record the transitive closure of using namespace. */
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
comment|/* Non-zero if NODE is the std namespace.  */
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
comment|/* In a non-local VAR_DECL with static storage duration, this is the    initialization priority.  If this value is zero, the NODE will be    initialized at the DEFAULT_INIT_PRIORITY.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INIT_PRIORITY
parameter_list|(
name|NODE
parameter_list|)
value|(VAR_DECL_CHECK (NODE)->decl.u2.i)
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
value|DECL_RESULT_FLD(VAR_DECL_CHECK (NODE))
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
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.pending_inline_p)
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
value|(DECL_LANG_SPECIFIC (NODE)->u.pending_inline_info)
end_define

begin_comment
comment|/* For a TYPE_DECL: if this function has many fields, we'll sort them    and put them into a TREE_VEC. */
end_comment

begin_define
define|#
directive|define
name|DECL_SORTED_FIELDS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (TYPE_DECL_CHECK (NODE))->u.sorted_fields)
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
comment|/* For a VAR_DECL, FUNCTION_DECL, TYPE_DECL or TEMPLATE_DECL:    template-specific information.  */
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
value|(TYPE_LANG_SPECIFIC (RECORD_OR_UNION_TYPE_CHECK (NODE))->template_info)
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
value|(TYPE_BINFO (ENUMERAL_TYPE_CHECK (NODE)))
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
value|(TYPE_LANG_SPECIFIC (BOUND_TEMPLATE_TEMPLATE_PARM_TYPE_CHECK (NODE)) \    ->template_info)
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
comment|/* Non-zero if the template arguments is actually a vector of vectors,    rather than just a vector.  */
end_comment

begin_define
define|#
directive|define
name|TMPL_ARGS_HAVE_MULTIPLE_LEVELS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((NODE) != NULL_TREE						\&& TREE_CODE (NODE) == TREE_VEC				\&& TREE_VEC_LENGTH (NODE)> 0				\&& TREE_VEC_ELT (NODE, 0) != NULL_TREE			\&& TREE_CODE (TREE_VEC_ELT (NODE, 0)) == TREE_VEC)
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
comment|/* The LEVELth level of the template ARGS.  The outermost level of of    args is level 1, not level 0.  */
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
comment|/* Set the IDXth element in the LEVELth level of ARGS to VAL.  This    macro does not work with single-level argument vectors.  */
end_comment

begin_define
define|#
directive|define
name|SET_TMPL_ARG
parameter_list|(
name|ARGS
parameter_list|,
name|LEVEL
parameter_list|,
name|IDX
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(TREE_VEC_ELT (TREE_VEC_ELT ((ARGS), (LEVEL) - 1), (IDX)) = (VAL))
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
value|((NODE) == NULL_TREE ? 0				\    : (TREE_CODE (NODE) == TREE_VEC			\       ? TREE_VEC_LENGTH (NODE) : list_length (NODE)))
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
comment|/* The TEMPLATE_DECL instantiated or specialized by NODE.  This    TEMPLATE_DECL will be the immediate parent, not the most general    template.  For example, in:        template<class T> struct S { template<class U> void f(U); }     the FUNCTION_DECL for S<int>::f<double> will have, as its    DECL_TI_TEMPLATE, `template<class U> S<int>::f<U>'.     As a special case, for a member friend template of a template    class, this value will not be a TEMPLATE_DECL, but rather a    LOOKUP_EXPR, IDENTIFIER_NODE or OVERLOAD indicating the name of    the template and any explicit template arguments provided.  For    example, in:       template<class T> struct S { friend void f<int>(int, double); }     the DECL_TI_TEMPLATE will be a LOOKUP_EXPR for `f' and the    DECL_TI_ARGS will be {int}.  */
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

begin_define
define|#
directive|define
name|ENUM_TI_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TI_TEMPLATE (ENUM_TEMPLATE_INFO (NODE))
end_define

begin_define
define|#
directive|define
name|ENUM_TI_ARGS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TI_ARGS (ENUM_TEMPLATE_INFO (NODE))
end_define

begin_comment
comment|/* Like DECL_TI_TEMPLATE, but for an ENUMERAL_, RECORD_, or UNION_TYPE.  */
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
value|(DECL_LANG_SPECIFIC (FUNCTION_DECL_CHECK (NODE))->u.saved_language_function)
end_define

begin_define
define|#
directive|define
name|NEW_EXPR_USE_GLOBAL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
end_define

begin_define
define|#
directive|define
name|DELETE_EXPR_USE_GLOBAL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
end_define

begin_define
define|#
directive|define
name|DELETE_EXPR_USE_VEC
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1 (NODE)
end_define

begin_define
define|#
directive|define
name|LOOKUP_EXPR_GLOBAL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
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
value|(TYPE_FIELDS (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE is an implicit typename.  */
end_comment

begin_define
define|#
directive|define
name|IMPLICIT_TYPENAME_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TYPENAME_TYPE&& TREE_TYPE (NODE))
end_define

begin_comment
comment|/* Nonzero if NODE is a TYPE_DECL that should not be visible because    it is from a dependent base class.  */
end_comment

begin_define
define|#
directive|define
name|IMPLICIT_TYPENAME_TYPE_DECL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TYPE_DECL		\&& DECL_ARTIFICIAL (NODE)			\&& IMPLICIT_TYPENAME_P (TREE_TYPE (NODE)))
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
comment|/* Nonzero in any kind of _TYPE where conversions to base-classes may    involve pointer arithmetic.  If this is zero, then converting to    a base-class never requires changing the value of the pointer.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BASE_CONVS_MAY_REQUIRE_CODE_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1 (NODE))
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
value|(TYPE_POLYMORPHIC_P (NODE)			\    || TYPE_USES_VIRTUAL_BASECLASSES (NODE))
end_define

begin_decl_stmt
specifier|extern
name|int
name|flag_new_for_scope
decl_stmt|;
end_decl_stmt

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
comment|/* Nonzero if NODE is a FUNCTION_DECL for a built-in function, and we have    not yet seen a prototype for that function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ANTICIPATED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (DECL_CHECK (NODE))->decl_flags.anticipated_p)
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
comment|/* Returns non-zero if DECL has external linkage, as specified by the    language standard.  (This predicate may hold even when the    corresponding entity is not actually given external linkage in the    object file; see decl_linkage for details.)  */
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

begin_define
define|#
directive|define
name|INTEGRAL_CODE_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == INTEGER_TYPE || (CODE) == ENUMERAL_TYPE || (CODE) == BOOLEAN_TYPE)
end_define

begin_comment
comment|/* [basic.fundamental]     Types  bool, char, wchar_t, and the signed and unsigned integer types    are collectively called integral types.     Note that INTEGRAL_TYPE_P, as defined in tree.h, allows enumeration    types as well, which is incorrect in C++.  */
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
comment|/* [basic.fundamental]     Integral and floating types are collectively called arithmetic    types.  */
end_comment

begin_define
define|#
directive|define
name|ARITHMETIC_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(CP_INTEGRAL_TYPE_P (TYPE) || TREE_CODE (TYPE) == REAL_TYPE)
end_define

begin_comment
comment|/* Nonzero for _TYPE means that the _TYPE defines    at least one constructor.  */
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
comment|/* When appearing in an INDIRECT_REF, it means that the tree structure    underneath is actually a call to a constructor.  This is needed    when the constructor must initialize local storage (which can    be automatically destroyed), rather than allowing it to allocate    space from the heap.     When appearing in a SAVE_EXPR, it means that underneath    is a call to a constructor.     When appearing in a CONSTRUCTOR, it means that it was    a GNU C constructor expression.     When appearing in a FIELD_DECL, it means that this field    has been duly initialized in its constructor.  */
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

begin_define
define|#
directive|define
name|EMPTY_CONSTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CODE (NODE) == CONSTRUCTOR	   \&& CONSTRUCTOR_ELTS (NODE) == NULL_TREE \&& ! TREE_HAS_CONSTRUCTOR (NODE))
end_define

begin_comment
comment|/* Nonzero for _TYPE means that the _TYPE defines a destructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_FLAG_2 (NODE))
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
value|(TYPE_LANG_SPECIFIC (NODE)->non_aggregate)
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
name|TYPE_HAS_REAL_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->has_real_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_COMPLEX_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->has_complex_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_ABSTRACT_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->has_abstract_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_COMPLEX_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->has_complex_init_ref)
end_define

begin_comment
comment|/* Nonzero if TYPE has a trivial destructor.  From [class.dtor]:       A destructor is trivial if it is an implicitly declared      destructor and if:         - all of the direct base classes of its class have trivial          destructors,         - for all of the non-static data members of its class that are          of class type (or array thereof), each such class has a 	 trivial destructor.  */
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

begin_define
define|#
directive|define
name|TYPE_PTRMEM_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == POINTER_TYPE				\&& TREE_CODE (TREE_TYPE (NODE)) == OFFSET_TYPE)
end_define

begin_define
define|#
directive|define
name|TYPE_PTR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == POINTER_TYPE			\&& TREE_CODE (TREE_TYPE (NODE)) != OFFSET_TYPE)
end_define

begin_define
define|#
directive|define
name|TYPE_PTROB_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_PTR_P (NODE)&& TREE_CODE (TREE_TYPE (NODE)) != FUNCTION_TYPE	\&& TREE_CODE (TREE_TYPE (NODE)) != VOID_TYPE)
end_define

begin_define
define|#
directive|define
name|TYPE_PTROBV_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_PTR_P (NODE)&& TREE_CODE (TREE_TYPE (NODE)) != FUNCTION_TYPE)
end_define

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
value|(TYPE_LANG_SPECIFIC (NODE)->ptrmemfunc_flag)
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
value|TREE_LANG_FLAG_0 (NODE)
end_define

begin_comment
comment|/* A pointer-to-function member type looks like:       struct {        __P __pfn;        ptrdiff_t __delta;      };     If __pfn is NULL, it is a NULL pointer-to-member-function.       (Because the vtable is always the first thing in the object, we    don't need its offset.)  If the function is virtual, then PFN is    one plus twice the index into the vtable; otherwise, it is just a    pointer to the function.     Unfortunately, using the lowest bit of PFN doesn't work in    architectures that don't impose alignment requirements on function    addresses, or that use the lowest bit to tell one ISA from another,    for example.  For such architectures, we use the lowest bit of    DELTA instead of the lowest bit of the PFN, and DELTA will be    multiplied by 2.  */
end_comment

begin_enum
enum|enum
name|ptrmemfunc_vbit_where_t
block|{
name|ptrmemfunc_vbit_in_pfn
block|,
name|ptrmemfunc_vbit_in_delta
block|}
enum|;
end_enum

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
value|((tree)TYPE_LANG_SPECIFIC (NODE))
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
value|(TYPE_LANG_SPECIFIC (NODE) = ((struct lang_type *)(void*)(VALUE)))
end_define

begin_comment
comment|/* Returns the pfn field from a TYPE_PTRMEMFUNC_P.  */
end_comment

begin_define
define|#
directive|define
name|PFN_FROM_PTRMEMFUNC
parameter_list|(
name|NODE
parameter_list|)
value|pfn_from_ptrmemfunc ((NODE))
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
value|(TYPE_PTRMEM_P (NODE)					\    ? TYPE_OFFSET_BASETYPE (TREE_TYPE (NODE))		\    : TYPE_PTRMEMFUNC_OBJECT_TYPE (NODE))
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
value|(TYPE_PTRMEM_P (NODE)				\     ? TREE_TYPE (TREE_TYPE (NODE))			\     : TREE_TYPE (TYPE_PTRMEMFUNC_FN_TYPE (NODE)))
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
value|(CLASS_TYPE_P (NODE)&& TYPE_LANG_SPECIFIC (NODE)->anon_aggr)
end_define

begin_define
define|#
directive|define
name|SET_ANON_AGGR_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->anon_aggr = 1)
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
value|(TYPE_LANG_SPECIFIC (NODE)->was_anonymous)
end_define

begin_comment
comment|/* C++: all of these are overloaded!  These apply only to TYPE_DECLs.  */
end_comment

begin_comment
comment|/* The format of each node in the DECL_FRIENDLIST is as follows:     The TREE_PURPOSE will be the name of a function, i.e., an    IDENTIFIER_NODE.  The TREE_VALUE will be itself a TREE_LIST, the    list of functions with that name which are friends.  The    TREE_PURPOSE of each node in this sublist will be error_mark_node,    if the function was declared a friend individually, in which case    the TREE_VALUE will be the function_decl.  If, however, all    functions with a given name in a class were declared to be friends,    the TREE_PUROSE will be the class type, and the TREE_VALUE will be    NULL_TREE.  */
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
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.u2.access)
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
comment|/* If DECL_GLOBAL_CTOR_P or DECL_GLOBAL_DTOR_P holds, this macro    returns the initialization priority for the function.  Constructors    with lower numbers should be run first.  Destructors should be run    in the reverse order of constructors.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_INIT_PRIORITY
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.u2.init_priority)
end_define

begin_comment
comment|/* Accessor macros for C++ template decl nodes.  */
end_comment

begin_comment
comment|/* The DECL_TEMPLATE_PARMS are a list.  The TREE_PURPOSE of each node    is a INT_CST whose TREE_INT_CST_LOW indicates the level of the    template parameters, with 1 being the outermost set of template    parameters.  The TREE_VALUE is a vector, whose elements are the    template parameters at each level.  Each element in the vector is a    TREE_LIST, whose TREE_VALUE is a PARM_DECL (if the parameter is a    non-type parameter), or a TYPE_DECL (if the parameter is a type    parameter).  The TREE_PURPOSE is the default value, if any.  The    TEMPLATE_PARM_INDEX for the parameter is avilable as the    DECL_INITIAL (for a PARM_DECL) or as the TREE_TYPE (for a    TYPE_DECL).  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_ARGUMENTS (NODE)
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
comment|/* For a static member variable template, the    DECL_TEMPLATE_INSTANTIATIONS list contains the explicitly and    implicitly generated instantiations of the variable.  There are no    partial instantiations of static member variables, so all of these    will be full instantiations.     For a class template the DECL_TEMPLATE_INSTANTIATIONS lists holds    all instantiations and specializations of the class type, including    partial instantiations and partial specializations.     In both cases, the TREE_PURPOSE of each node contains the arguments    used; the TREE_VALUE contains the generated variable.  The template    arguments are always complete.  For example, given:        template<class T> struct S1 {         template<class U> struct S2 {}; 	template<class U> struct S2<U*> {};       };     the record for the partial specialization will contain, as its    argument list, { {T}, {U*} }, and will be on the    DECL_TEMPLATE_INSTANTIATIONS list for `template<class T> template<class U> struct S1<T>::S2'.     This list is not used for function templates.  */
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
comment|/* For a function template, the DECL_TEMPLATE_SPECIALIZATIONS lists    contains all instantiations and specializations of the function,    including partial instantiations.  For a partial instantiation    which is a specialization, this list holds only full    specializations of the template that are instantiations of the    partial instantiation.  For example, given:        template<class T> struct S {         template<class U> void f(U); 	template<> void f(T);       };     the `S<int>::f<int>(int)' function will appear on the    DECL_TEMPLATE_SPECIALIZATIONS list for both `template<class T>    template<class U> void S<T>::f(U)' and `template<class T> void    S<int>::f(T)'.  In the latter case, however, it will have only the    innermost set of arguments (T, in this case).  The DECL_TI_TEMPLATE    for the function declaration will point at the specialization, not    the fully general template.     For a class template, this list contains the partial    specializations of this template.  (Full specializations are not    recorded on this list.)  The TREE_PURPOSE holds the innermost    arguments used in the partial specialization (e.g., for `template<class T> struct S<T*, int>' this will be `T*'.)  The TREE_VALUE    holds the innermost template parameters for the specialization    (e.g., `T' in the example above.)  The TREE_TYPE is the _TYPE node    for the partial specialization.     This list is not used for static variable templates.  */
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
comment|/* Nonzero for a DECL which is actually a template parameter.  */
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

begin_define
define|#
directive|define
name|DECL_FUNCTION_TEMPLATE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == TEMPLATE_DECL \&& TREE_CODE (DECL_TEMPLATE_RESULT (NODE)) == FUNCTION_DECL)
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
value|(TREE_CODE (NODE) == TEMPLATE_DECL \&& TREE_CODE (DECL_TEMPLATE_RESULT (NODE)) == TYPE_DECL \&& !DECL_TEMPLATE_TEMPLATE_PARM_P (NODE))
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
comment|/* Nonzero if NODE is the typedef implicitly generated for a type when    the type is declared.  (In C++, `struct S {};' is roughly equivalent    to `struct S {}; typedef struct S S;' in C.  This macro will hold    for the typedef indicated in this example.  Note that in C++, there    is a second implicit typedef for each class, in the scope of `S'    itself, so that you can say `S::S'.  This macro does *not* hold for    those typedefs.  */
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
comment|/* Returns non-zero if NODE is a primary template.  */
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

begin_define
define|#
directive|define
name|CLASSTYPE_TEMPLATE_LEVEL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_INT_CST_LOW (TREE_PURPOSE (CLASSTYPE_TI_TEMPLATE (NODE))))
end_define

begin_comment
comment|/* Indicates whether or not (and how) a template was expanded for this    FUNCTION_DECL or VAR_DECL.      0=normal declaration, e.g. int min (int, int);      1=implicit template instantiation      2=explicit template specialization, e.g. int min<int> (int, int);      3=explicit template instantiation, e.g. template int min<int> (int, int);  */
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
comment|/* Non-zero if DECL is a friend function which is an instantiation    from the point of view of the compiler, but not from the point of    view of the language.  For example given:       template<class T> struct S { friend void f(T) {}; };    the declaration of `void f(int)' generated when S<int> is    instantiated will not be a DECL_TEMPLATE_INSTANTIATION, but will be    a DECL_FRIEND_PSUEDO_TEMPLATE_INSTANTIATION.  */
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
comment|/* Non-zero if TYPE is a partial instantiation of a template class,    i.e., an instantiation whose instantiation arguments involve    template types.  */
end_comment

begin_define
define|#
directive|define
name|PARTIAL_INSTANTIATION_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (TYPE)->is_partial_instantiation)
end_define

begin_comment
comment|/* Non-zero iff we are currently processing a declaration for an    entity with its own template parameter list, and which is not a    full specialization.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSING_REAL_TEMPLATE_DECL_P
parameter_list|()
define|\
value|(processing_template_decl> template_class_depth (current_class_type))
end_define

begin_comment
comment|/* This function may be a guiding decl for a template.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAYBE_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|DECL_LANG_FLAG_4 (NODE)
end_define

begin_comment
comment|/* Nonzero if this VAR_DECL or FUNCTION_DECL has already been    instantiated, i.e. its definition has been generated from the    pattern given in the the template.  */
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
comment|/* This function was declared inline.  This flag controls the linkage    semantics of 'inline'; whether or not the function is inlined is    controlled by DECL_INLINE.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DECLARED_INLINE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.base.declared_inline)
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
comment|/* A thunk is a stub function.     A thunk is an alternate entry point for an ordinary FUNCTION_DECL.    The address of the ordinary FUNCTION_DECL is given by the    DECL_INITIAL, which is always an ADDR_EXPR whose operand is a    FUNCTION_DECL.  The job of the thunk is to adjust the `this'    pointer before transferring control to the FUNCTION_DECL.     A thunk may perform either, or both, of the following operations:     o Adjust the `this' pointer by a constant offset.    o Adjust the `this' pointer by looking up a vcall-offset      in the vtable.     If both operations are performed, then the constant adjument to    `this' is performed first.     The constant adjustment is given by THUNK_DELTA.  If the    vcall-offset is required, the index into the vtable is given by    THUNK_VCALL_OFFSET.  */
end_comment

begin_comment
comment|/* An integer indicating how many bytes should be subtracted from the    `this' pointer when this function is called.  */
end_comment

begin_define
define|#
directive|define
name|THUNK_DELTA
parameter_list|(
name|DECL
parameter_list|)
value|(DECL_CHECK (DECL)->decl.u1.i)
end_define

begin_comment
comment|/* A tree indicating how many bytes should be subtracted from the    vtable for the `this' pointer to find the vcall offset.  (The vptr    is always located at offset zero from the f `this' pointer.)  If    NULL, then there is no vcall offset.  */
end_comment

begin_define
define|#
directive|define
name|THUNK_VCALL_OFFSET
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (DECL)->decl_flags.u2.vcall_offset)
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

begin_define
define|#
directive|define
name|SUBOBJECT_CLEANUP
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SUBOBJECT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* Nonzero if this CTOR_STMT is for the beginning of a constructor.  */
end_comment

begin_define
define|#
directive|define
name|CTOR_BEGIN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_0 (CTOR_STMT_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero if this CTOR_STMT is for the end of a constructor.  */
end_comment

begin_define
define|#
directive|define
name|CTOR_END_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(!CTOR_BEGIN_P (NODE))
end_define

begin_comment
comment|/* The parameters for a call-declarator.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DECLARATOR_PARMS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_PURPOSE (TREE_OPERAND (NODE, 1)))
end_define

begin_comment
comment|/* The cv-qualifiers for a call-declarator.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DECLARATOR_QUALS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VALUE (TREE_OPERAND (NODE, 1)))
end_define

begin_comment
comment|/* The exception-specification for a call-declarator.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DECLARATOR_EXCEPTION_SPEC
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_TYPE (NODE))
end_define

begin_comment
comment|/* An enumeration of the kind of tags that C++ accepts.  */
end_comment

begin_enum
enum|enum
name|tag_types
block|{
name|record_type
block|,
name|class_type
block|,
name|union_type
block|,
name|enum_type
block|}
enum|;
end_enum

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
block|}
name|cp_lvalue_kind
typedef|;
end_typedef

begin_comment
comment|/* The kinds of scopes we recognize.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|scope_kind
block|{
name|sk_template_parms
block|,
comment|/* A scope for template parameters.  */
name|sk_template_spec
comment|/* A scope corresponding to a template 			specialization.  There is never anything in 			this scope.  */
block|}
name|scope_kind
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
comment|/* The various kinds of linkage.  From [basic.link],            A name is said to have linkage when it might denote the same       object, reference, function, type, template, namespace or value       as a name introduced in another scope:        -- When a name has external linkage, the entity it denotes can          be referred to from scopes of other translation units or from 	 other scopes of the same translation unit.        -- When a name has internal linkage, the entity it denotes can          be referred to by names from other scopes in the same 	 translation unit.        -- When a name has no linkage, the entity it denotes cannot be          referred to by names from other scopes.  */
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
comment|/* Bitmask flags to pass to instantiate_type.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|instantiate_type_flags
block|{
name|itf_none
init|=
literal|0
block|,
comment|/* nothing special */
name|itf_complain
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* complain about errors */
name|itf_no_attributes
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* ignore attributes on comparisons */
name|itf_ptrmem_ok
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* pointers to member ok (internal use) */
block|}
name|instantiate_type_flags
typedef|;
end_typedef

begin_comment
comment|/* The kind of checking we can do looking in a class hierarchy. */
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
name|ba_ignore
init|=
literal|1
block|,
comment|/* Do not check access */
name|ba_check
init|=
literal|2
block|,
comment|/* Check access */
name|ba_not_special
init|=
literal|3
block|,
comment|/* Do not consider special privilege 		         current_class_type might give. */
name|ba_quiet
init|=
literal|4
block|,
comment|/* Do not issue error messages (bit mask).  */
block|}
name|base_access
typedef|;
end_typedef

begin_comment
comment|/* The kind of base we can find, looking in a class hierarchy.    Values<0 indicate we failed. */
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
comment|/* It is a proper base, but via a virtual 			     path. This might not be the canonical 			     binfo. */
block|}
name|base_kind
typedef|;
end_typedef

begin_comment
comment|/* Nonzero means allow Microsoft extensions without a pedwarn.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ms_extensions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means warn in function declared in derived class has the    same name as a virtual in the base class, but fails to match the    type signature of any virtual function in the base class.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_overloaded_virtual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about use of multicharacter literals.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_multichar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set by add_implicitly_declared_members() to keep those members from    being flagged as deprecated or reported as using deprecated    types.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|adding_implicit_members
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means warn if a non-templatized friend function is    declared in a templatized class. This behavior is warned about with    flag_guiding_decls in do_friend. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nontemplate_friend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in decl{2}.c */
end_comment

begin_comment
comment|/* A node that is a list (length 1) of error_mark_nodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|error_mark_list
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|tree
name|integer_two_node
decl_stmt|,
name|integer_three_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|anonymous_namespace_name
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
block|,
name|DEDUCE_ORDER
block|}
name|unification_kind_t
typedef|;
end_typedef

begin_comment
comment|/* Macros for operating on a template instantiation level node, represented    by an EXPR_WITH_FILE_LOCATION.  */
end_comment

begin_define
define|#
directive|define
name|TINST_DECL
parameter_list|(
name|NODE
parameter_list|)
value|EXPR_WFL_NODE (NODE)
end_define

begin_define
define|#
directive|define
name|TINST_LINE
parameter_list|(
name|NODE
parameter_list|)
value|EXPR_WFL_LINENO (NODE)
end_define

begin_define
define|#
directive|define
name|TINST_FILE
parameter_list|(
name|NODE
parameter_list|)
value|EXPR_WFL_FILENAME (NODE)
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
comment|/* Points to the name of that function. May not be the DECL_NAME    of CURRENT_FUNCTION_DECL due to overloading */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|original_function_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An array of all local classes present in this translation unit, in    declaration order.  */
end_comment

begin_decl_stmt
specifier|extern
name|varray_type
name|local_classes
decl_stmt|;
end_decl_stmt

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
name|VPTR_NAME
value|"$v"
end_define

begin_define
define|#
directive|define
name|THROW_NAME
value|"$eh_throw"
end_define

begin_define
define|#
directive|define
name|AUTO_VTABLE_NAME
value|"__vtbl$me__"
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
name|AUTO_TEMP_FORMAT
value|"_$tmp_%d"
end_define

begin_define
define|#
directive|define
name|VTABLE_BASE
value|"$vb"
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_PREFIX
value|"__vt_"
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
name|STATIC_NAME_FORMAT
value|"_%s$%s"
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
name|VPTR_NAME
value|".v"
end_define

begin_define
define|#
directive|define
name|THROW_NAME
value|".eh_throw"
end_define

begin_define
define|#
directive|define
name|AUTO_VTABLE_NAME
value|"__vtbl.me__"
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
name|AUTO_TEMP_FORMAT
value|"_.tmp_%d"
end_define

begin_define
define|#
directive|define
name|VTABLE_BASE
value|".vb"
end_define

begin_define
define|#
directive|define
name|VTABLE_NAME_PREFIX
value|"__vt_"
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
name|STATIC_NAME_FORMAT
value|"_%s.%s"
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
name|VPTR_NAME
value|"__vptr"
end_define

begin_define
define|#
directive|define
name|VPTR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), VPTR_NAME, sizeof (VPTR_NAME) - 1))
end_define

begin_define
define|#
directive|define
name|THROW_NAME
value|"__eh_throw"
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
name|AUTO_VTABLE_NAME
value|"__vtbl_me__"
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
name|AUTO_TEMP_FORMAT
value|"__tmp_%d"
end_define

begin_define
define|#
directive|define
name|VTABLE_BASE
value|"__vtb"
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
name|VTABLE_NAME_PREFIX
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
name|STATIC_NAME_FORMAT
value|"__static_%s_%s"
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
name|FILE_FUNCTION_PREFIX_LEN
value|9
end_define

begin_define
define|#
directive|define
name|CTOR_NAME
value|"__ct"
end_define

begin_define
define|#
directive|define
name|DTOR_NAME
value|"__dt"
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

begin_define
define|#
directive|define
name|EXCEPTION_CLEANUP_NAME
value|"exception cleanup"
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
name|VPTR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[1] == 'v')
end_define

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

begin_comment
comment|/* Returns non-zero iff NODE is a declaration for the global function    `main'.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAIN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_EXTERN_C_FUNCTION_P (NODE)                     \&& DECL_NAME (NODE) != NULL_TREE			\&& MAIN_NAME_P (DECL_NAME (NODE)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Things for handling inline functions.  */
end_comment

begin_comment
comment|/* Nonzero means do emit exported implementations of functions even if    they can be inlined.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_implement_inlines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means templates obey #pragma interface and implementation.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_external_templates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means templates are emitted where they are instantiated.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_alt_external_templates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means implicit template instantiations are emitted.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_implicit_templates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to emit defined symbols with common-like linkage as    weak symbols where possible, in order to conform to C++ semantics.    Otherwise, emit them as local symbols.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_weak
decl_stmt|;
end_decl_stmt

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
comment|/* Functions called along with real static constructors and destructors.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|static_ctors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
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
comment|/* Some macros for char-based bitfields.  */
end_comment

begin_define
define|#
directive|define
name|B_SET
parameter_list|(
name|A
parameter_list|,
name|X
parameter_list|)
value|((A)[(X)>>3] |=  (1<< ((X)&7)))
end_define

begin_define
define|#
directive|define
name|B_CLR
parameter_list|(
name|A
parameter_list|,
name|X
parameter_list|)
value|((A)[(X)>>3]&= ~(1<< ((X)&7)))
end_define

begin_define
define|#
directive|define
name|B_TST
parameter_list|(
name|A
parameter_list|,
name|X
parameter_list|)
value|((A)[(X)>>3]&   (1<< ((X)&7)))
end_define

begin_comment
comment|/* These are uses as bits in flags passed to build_method_call    to control its error reporting behavior.     LOOKUP_PROTECT means flag access violations.    LOOKUP_COMPLAIN mean complain if no suitable member function      matching the arguments is found.    LOOKUP_NORMAL is just a combination of these two.    LOOKUP_NONVIRTUAL means make a direct call to the member function found    LOOKUP_GLOBAL means search through the space of overloaded functions,      as well as the space of member functions.    LOOKUP_ONLYCONVERTING means that non-conversion constructors are not tried.    DIRECT_BIND means that if a temporary is created, it should be created so      that it lives as long as the current variable bindings; otherwise it      only lives until the end of the complete-expression.  It also forces      direct-initialization in cases where other parts of the compiler have      already generated a temporary, such as reference initialization and the      catch parameter.    LOOKUP_SPECULATIVELY means return NULL_TREE if we cannot find what we are      after.  Note, LOOKUP_COMPLAIN is checked and error messages printed      before LOOKUP_SPECULATIVELY is checked.    LOOKUP_NO_CONVERSION means that user-defined conversions are not      permitted.  Built-in conversions are permitted.    LOOKUP_DESTRUCTOR means explicit call to destructor.    LOOKUP_NO_TEMP_BIND means temporaries will not be bound to references.     These are used in global lookup to support elaborated types and    qualifiers.     LOOKUP_PREFER_TYPES means not to accept objects, and possibly namespaces.    LOOKUP_PREFER_NAMESPACES means not to accept objects, and possibly types.    LOOKUP_PREFER_BOTH means class-or-namespace-name.    LOOKUP_TEMPLATES_EXPECTED means that class templates also count      as types.  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP_PROTECT
value|(1)
end_define

begin_define
define|#
directive|define
name|LOOKUP_COMPLAIN
value|(2)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NORMAL
value|(3)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NONVIRTUAL
value|(8)
end_define

begin_define
define|#
directive|define
name|LOOKUP_GLOBAL
value|(16)
end_define

begin_define
define|#
directive|define
name|LOOKUP_SPECULATIVELY
value|(64)
end_define

begin_define
define|#
directive|define
name|LOOKUP_ONLYCONVERTING
value|(128)
end_define

begin_define
define|#
directive|define
name|DIRECT_BIND
value|(256)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NO_CONVERSION
value|(512)
end_define

begin_define
define|#
directive|define
name|LOOKUP_DESTRUCTOR
value|(512)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NO_TEMP_BIND
value|(1024)
end_define

begin_define
define|#
directive|define
name|LOOKUP_PREFER_TYPES
value|(2048)
end_define

begin_define
define|#
directive|define
name|LOOKUP_PREFER_NAMESPACES
value|(4096)
end_define

begin_define
define|#
directive|define
name|LOOKUP_PREFER_BOTH
value|(6144)
end_define

begin_define
define|#
directive|define
name|LOOKUP_TEMPLATES_EXPECTED
value|(8192)
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
name|CONV_STATIC_CAST
value|(CONV_IMPLICIT | CONV_STATIC | CONV_FORCE_TEMP)
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
name|WANT_ARITH
value|(WANT_INT | WANT_FLOAT)
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
comment|/* Check to see if the second type is 				   derived from the first, or if both 				   are pointers (or references) and 				   the types pointed to by the second 				   type is derived from the pointed to 				   by the first.  */
end_comment

begin_define
define|#
directive|define
name|COMPARE_RELAXED
value|2
end_define

begin_comment
comment|/* Like COMPARE_DERIVED, but in 				   reverse.  Also treat enmeration 				   types as the same as integer types 				   of the same width.  */
end_comment

begin_define
define|#
directive|define
name|COMPARE_REDECLARATION
value|4
end_define

begin_comment
comment|/* The comparsion is being done when 				   another declaration of an existing 				   entity is seen.  */
end_comment

begin_define
define|#
directive|define
name|COMPARE_NO_ATTRIBUTES
value|8
end_define

begin_comment
comment|/* The comparison should ignore 				   extra-linguistic type attributes.  */
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
value|(TYPE_FIELDS (NODE))
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
comment|/* These constants can used as bit flags in the process of tree formatting.     TFF_PLAIN_IDENTIFIER: unqualified part of a name.    TFF_SCOPE: include the class and namespace scope of the name.    TFF_CHASE_TYPEDEF: print the original type-id instead of the typedef-name.    TFF_DECL_SPECIFIERS: print decl-specifiers.    TFF_CLASS_KEY_OR_ENUM: precede a class-type name (resp. enum name) with        a class-key (resp. `enum').    TFF_RETURN_TYPE: include function return type.    TFF_FUNCTION_DEFAULT_ARGUMENTS: include function default parameter values.    TFF_EXCEPTION_SPECIFICATION: show function exception specification.    TFF_TEMPLATE_HEADER: show the template<...> header in a        template-declaration.    TFF_TEMPLATE_NAME: show only template-name.    TFF_EXPR_IN_PARENS: Parenthesize expressions.  */
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

begin_decl_stmt
specifier|extern
name|void
name|init_reswords
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
struct|struct
name|operator_name_info_t
block|{
comment|/* The IDENTIFIER_NODE for the operator.  */
name|tree
name|identifier
decl_stmt|;
comment|/* The name of the operator.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The mangled name of the operator.  */
specifier|const
name|char
modifier|*
name|mangled_name
decl_stmt|;
block|}
name|operator_name_info_t
typedef|;
end_typedef

begin_comment
comment|/* A mapping from tree codes to operator name information.  */
end_comment

begin_decl_stmt
specifier|extern
name|operator_name_info_t
name|operator_name_info
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Similar, but for assignment operators.  */
end_comment

begin_decl_stmt
specifier|extern
name|operator_name_info_t
name|assignment_operator_name_info
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in call.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|check_dtor_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_arglist_len_in_bytes
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_vfield_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_scoped_method_call
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_conditional_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_addr_func
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_call
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_method_call
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|null_ptr_cst_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sufficient_parms_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|type_decays_to
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_user_type_conversion
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_new_function_call
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_new_op
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|int
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_op_delete_call
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|can_convert
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|can_convert_arg
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|can_convert_arg_bad
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|enforce_access
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_default_arg
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_arg_to_ellipsis
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_va_arg
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_type_from_ellipsis
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_properly_derived_from
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|initialize_reference
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|strip_top_quals
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|perform_implicit_conversion
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in class.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_base_path
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_vbase_path
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_vtbl_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_vfn_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_vtable_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_method
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|currently_open_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|currently_open_derived_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|duplicate_tag_error
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_struct
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_struct_1
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|resolves_to_fixed_type_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_class_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_empty_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pushclass
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|popclass
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_nested_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_nested_class
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_lang_depth
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_lang_context
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_lang_context
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|instantiate_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
expr|enum
name|instantiate_type_flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_class_statistics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_print_statistics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_print_xnode
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_print_decl
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_print_type
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_print_identifier
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_set_yydebug
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|build_self_reference
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|same_signature_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warn_hidden
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_enclosing_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|is_base_of_enclosing_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unreverse_member_declarations
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|invalidate_class_lookup_cache
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_note_name_used_in_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_name_declared_in_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_vtbl_decl_for_binfo
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|in_charge_arg_for_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_vtt_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_primary_binfo
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in cvt.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|convert_to_reference
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_from_reference
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_lvalue
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ocp_convert
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_convert
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_to_void
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
comment|/*implicit context*/
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_force
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_type_conversion
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_expr_type_conversion
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|type_promotes_to
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|perform_qualification_conversions
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clone_function_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|adjust_clone_args
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* decl.c */
end_comment

begin_comment
comment|/* resume_binding_level */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cxx_init_decl_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|toplevel_bindings_p
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|namespace_bindings_p
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keep_next_level
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kept_level_p
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|template_parm_scope_p
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_class_shadows
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_push_cleanup_level
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_scope
name|PARAMS
argument_list|(
operator|(
name|scope_kind
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_scope
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_level_for_for
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_level_for_try
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_level_for_catch
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|resume_level
name|PARAMS
argument_list|(
operator|(
expr|struct
name|binding_level
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_block_current_level
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pushlevel_class
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|poplevel_class
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_binding_stack
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_binding_level
name|PARAMS
argument_list|(
operator|(
expr|struct
name|binding_level
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_namespace
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_namespace
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_nested_namespace
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_nested_namespace
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_push_to_top_level
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_to_top_level
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_from_top_level
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_switch
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_switch
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|identifier_type_value
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_identifier_type_value
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_everything
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pushtag
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_anon_name
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_anon_tags
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|decls_match
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|duplicate_decls
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|pushdecl_top_level
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pushdecl_class_level
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|pushdecl_namespace_level
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|push_using_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|push_using_directive
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_class_level_binding
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|implicitly_declare
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|declare_local_label
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|define_label
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_goto
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|define_case_label
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|binding_for_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|namespace_binding
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_namespace_binding
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_namespace_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_typename_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_typename_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_unbound_class_template
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_name_nonclass
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_function_nonclass
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_name_current_level
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_type_current_level
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_name_namespace_only
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_only_namespace_names
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|end_only_namespace_names
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|namespace_ancestor
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unqualified_namespace_lookup
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lookup_using_namespace
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|qualified_lookup_using_namespace
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_library_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_library_fn_ptr
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_cp_library_fn_ptr
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|push_library_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|push_void_library_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|push_throw_library_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|init_type_desc
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|check_tag_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|shadow_tag
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|groktypename
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|start_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|start_decl_1
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_finish_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_inject_for_scope_var
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initialize_local_var
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_static_init
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|start_handler_parms
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|complete_array_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_ptrmemfunc_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the grokdeclarator prototype is in decl.h */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|parmlist_is_exprlist
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|copy_fn_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|grok_special_member_properties
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|grok_ctor_properties
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|grok_op_properties
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|xref_tag
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|xref_tag_from_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xref_basetypes
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|start_enum
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_enum
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|build_enumerator
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|start_function
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_function_body
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_function_body
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_function
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|start_method
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_method
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hack_incomplete_structures
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_other_binding_stack
name|PARAMS
argument_list|(
operator|(
expr|struct
name|binding_level
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|revert_static_member_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fixup_anonymous_aggr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_static_variable_definition
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|compute_array_index_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_local_binding
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|push_class_binding
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|check_default_argument
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|push_overloaded_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_identifier_class_values
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|storetags
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vtable_decl_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vtype_decl_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sigtable_decl_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*walk_globals_pred
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*walk_globals_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|walk_globals
name|PARAMS
argument_list|(
operator|(
name|walk_globals_pred
operator|,
name|walk_globals_fn
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*walk_namespaces_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|walk_namespaces
name|PARAMS
argument_list|(
operator|(
name|walk_namespaces_fn
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wrapup_globals_for_namespace
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_namespace_decls
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|create_implicit_typedef
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|maybe_push_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_target_expr_with_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|local_variable_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nonstatic_local_decl_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|declare_global_var
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|register_dtor_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tmpl_spec_kind
name|current_tmpl_spec_kind
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_fname_init
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in decl2.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_decl2
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_java_method
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cxx_decode_option
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|grok_method_quals
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warn_if_unknown_interface
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|grok_x_components
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_retrofit_in_chrg
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_make_one_only
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|grokclassfn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
expr|enum
name|overload_flags
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|grok_array_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|delete_sanity
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|check_classfn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_member_template
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|grokfield
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|grokbitfield
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|groktypefield
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|grokoptypename
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cplus_decl_attributes
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|constructor_name_full
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|constructor_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|defer_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_anon_union
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_table
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_builtin_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|,
name|tree
operator|*
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|coerce_new_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|coerce_delete_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|comdat_linkage
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|import_export_vtable
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|import_export_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_cleanup
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|reparse_absdcl_as_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|reparse_absdcl_as_casts
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_expr_from_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|reparse_decl_as_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_decl_parsing
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_decl_namespace
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_decl_namespace
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_decl_namespace
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_decl_namespace
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_scope
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_scope
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_namespace_alias
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_toplevel_using_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_local_using_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|do_class_using_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_using_directive
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_default_args
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_used
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|handle_class_head
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_arg_dependent
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_static_data_member_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_artificial_parm
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_guard
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_guard_cond
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|set_guard
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in parse.y */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cp_parse_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_error_at
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|msgid
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_warning_at
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|msgid
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_pedwarn_at
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|msgid
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX Not i18n clean.  */
end_comment

begin_define
define|#
directive|define
name|cp_deprecated
parameter_list|(
name|STR
parameter_list|)
define|\
value|do {										\     if (warn_deprecated)							\       warning ("%s is deprecated, please see the documentation for details",	\ 	       (STR));								\   } while (0)
end_define

begin_comment
comment|/* in error.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_error
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|type_as_string
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|decl_as_string
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|expr_as_string
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|context_as_string
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|lang_decl_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cp_file_of
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_line_of
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|language_to_string
name|PARAMS
argument_list|(
operator|(
expr|enum
name|languages
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_instantiation_context
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in except.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_exception_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|expand_start_catch_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_end_catch_block
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_builtin_throw
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_eh_spec_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_exception_blocks
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_exc_ptr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_throw
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_all_runtime_matches
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nothrow_libfn_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_handlers
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|choose_personality_routine
name|PARAMS
argument_list|(
operator|(
expr|enum
name|languages
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in expr.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_cplus_expand
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|extract_init
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cplus_expand_constant
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* friend.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|is_friend
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|make_friend_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_friend
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|do_friend
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
expr|enum
name|overload_flags
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in init.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_init_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|emit_base_init
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|expand_member_init
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_aggr_init
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_aggr_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_aggr_from_typedef
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_type_value
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_member_call
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_offset_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|resolve_offset_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_new
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_vec_init
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_delete
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_delete
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|special_function_kind
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_base_cleanups
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_vbase_delete
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_vec_delete
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|special_function_kind
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|create_temporary_var
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_init_stmts
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_init_stmts
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initialize_vtbl_ptrs
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_java_class_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in input.c */
end_comment

begin_comment
comment|/* in lex.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|make_pointer_declarator
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_reference_declarator
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_call_declarator
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_quals_and_spec
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_parse_statistics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_pending_inlines
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|process_next_inline
name|PARAMS
argument_list|(
operator|(
expr|struct
name|unparsed_text
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yyungetc
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|snarf_method
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_for_missing_semicolon
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_got_semicolon
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_list_got_semicolon
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_pending_lang_change
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|see_typename
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|do_identifier
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|do_scoped_id
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|identifier_typedecl_value
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_lang_decl
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|retrofit_lang_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|copy_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|copy_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_make_lang_type
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_aggr_type
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|compiler_error
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yyerror
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_inline_text_obstack
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yyhook
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_type_qual_from_rid
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cxx_init
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_finish
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_init_options
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cxx_post_options
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in method.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_method
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_mangled_name_for_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_opfncall
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|int
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|hack_identifier
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_thunk
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|use_thunk
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|synthesize_method
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|implicitly_declare_fn
name|PARAMS
argument_list|(
operator|(
name|special_function_kind
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|skip_artificial_parms_for
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In optimize.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|optimize_function
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|calls_setjmp_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maybe_clone_body
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in pt.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_pt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_template_shadow
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_innermost_template_args
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|tsubst
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|tsubst_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|tsubst_copy
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_begin_member_template_processing
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_end_member_template_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_member_template_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_template_parm_list
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_specialization
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reset_specialization
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|end_specialization
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_explicit_instantiation
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|end_explicit_instantiation
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|check_explicit_specialization
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|process_template_parm
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|end_template_parm_list
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|end_template_decl
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_template_args
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|push_template_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|push_template_decl_real
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|redeclare_class_template
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_template_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_template_function
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|uses_template_parms
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|instantiate_class_template
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|instantiate_template
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fn_type_unification
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|unification_kind_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|tinst_for_decl
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_decl_instantiated
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|more_specialized
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_class_instantiated
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_decl_instantiation
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_type_instantiation
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|instantiate_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_bindings
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|push_tinst_level
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_tinst_level
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|more_specialized_class
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_member_template
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|template_parms_equal
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comp_template_parms
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|template_class_depth
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_specialization_of
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comp_template_args
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_process_partial_specialization
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_check_template_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|most_specialized_instantiation
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_candidates
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|instantiate_pending_templates
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|tsubst_default_argument
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|most_general_template
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_mostly_instantiated_function_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|*
operator|,
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|problematic_instantiation_changed
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_last_problematic_instantiation
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_instantiation
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|processing_template_parmlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in repo.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|repo_template_used
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|repo_template_instantiated
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_repo
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_repo
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in rtti.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_rtti_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_typeid
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_tinfo_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_typeid
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_dynamic_cast
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|emit_support_tinfos
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tinfo_decl_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|emit_tinfo_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in search.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|lookup_base
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|base_access
operator|,
name|base_kind
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|types_overlap_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_vbase
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_dynamic_cast_base_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|type_access_control
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|skip_type_access_control
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reset_type_access_control
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|accessible_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_field
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lookup_fnfields_1
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_fnfields
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_member
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|look_for_overrides
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|get_pure_virtuals
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|get_vbase_types
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_suppress_debug_info
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_debug_info_needed
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_class_decls
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_class_decls
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unuse_fields
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_search_statistics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_search_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reinit_search_statistics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_scope
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|at_function_scope_p
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|context_for_name_lookup
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lookup_conversions
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|binfo_for_vtable
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|binfo_from_vbase
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|look_for_overrides_here
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dfs_walk
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
argument_list|(
operator|*
argument_list|)
argument_list|(
name|tree
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|tree
argument_list|(
operator|*
argument_list|)
argument_list|(
name|tree
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dfs_walk_real
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
argument_list|(
operator|*
argument_list|)
argument_list|(
name|tree
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|tree
argument_list|(
operator|*
argument_list|)
argument_list|(
name|tree
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|tree
argument_list|(
operator|*
argument_list|)
argument_list|(
name|tree
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dfs_unmark
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|markedp
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unmarkedp
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dfs_skip_nonprimary_vbases_unmarkedp
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dfs_skip_nonprimary_vbases_markedp
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dfs_unmarked_real_bases_queue_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dfs_marked_real_bases_queue_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dfs_skip_vbases
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|marked_vtable_pathp
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unmarked_vtable_pathp
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|find_vbase_instance
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|binfo_for_vbase
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|binfo_via_virtual
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in semantics.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_cp_semantics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_expr_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_if_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_if_stmt_cond
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_then_clause
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_else_clause
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_else_clause
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_if_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_while_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_while_stmt_cond
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_while_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_do_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_do_body
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_do_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_return_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_for_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_for_init_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_for_cond
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_for_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_for_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_break_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_continue_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_switch_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_switch_cond
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_switch_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_case_label
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_goto_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_try_block
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_try_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_eh_spec_block
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_eh_spec_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_handler_sequence
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_function_try_block
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_function_try_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_function_handler_sequence
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_cleanup_try_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_handler
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_handler_parms
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_catch_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_handler
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_cleanup
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_compound_stmt
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_compound_stmt
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_asm_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_label_stmt
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_label_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_subobject
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_parenthesized_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_stmt_expr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_stmt_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_call_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_increment_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_this_expr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_object_call_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_qualified_object_call_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_pseudo_destructor_call_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_qualified_call_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_unary_op_expr
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_id_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|save_type_access_control
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|decl_type_access_control
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|begin_function_definition
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_constructor_declarator
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_declarator
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_translation_unit
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_template_type_parm
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_template_template_parm
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_parmlist
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_class_definition
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_class_definition
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_default_args
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_inline_definitions
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_inline_definitions
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_member_class_template
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_template_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_template_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|enter_scope_of
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_base_specifier
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_member_declaration
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_multiple_declarators
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_typeof
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_sizeof
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_alignof
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_decl_cleanup
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_named_return_value
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_body
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|nullify_returns_r
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|int
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_pushlevel
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|do_poplevel
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_mem_initializers
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setup_vtbl_ptr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_out_block
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|begin_global_stmt_expr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|finish_global_stmt_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in spew.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_spew
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_pending_inlines
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|peekyylex
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|arbitrate_lookup
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|frob_opname
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_snarf_defarg
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_defarg_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_pending_defargs
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|done_pending_defargs
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unprocessed_defarg_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|replace_defarg
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|end_input
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_tree
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pod_type_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|canonical_type_variant
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unshare_base_binfos
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|member_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cp_lvalue_kind
name|real_lvalue_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_min
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_min_nt
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_cplus_new
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_target_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|break_out_calls
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_cplus_method_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_cplus_staticfn_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_cplus_array_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|hash_tree_cons
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|hash_tree_chain
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|hash_chainon
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_binfo
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|reverse_path
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|count_functions
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_overloaded_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_first_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bound_pmf_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ovl_cons
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_overload
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|function_arg_chain
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|promotes_to_aggr_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_aggr_type_2
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|lang_printable_name
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_exception_variant
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|bind_template_template_parm
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|array_type_nelts_total
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|array_type_nelts_top
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|break_out_target_exprs
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_type_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|vec_binfo_member
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|decl_namespace_context
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lvalue_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|error_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_ptr_wrapper
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_int_wrapper
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_srcloc_here
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|varargs_function_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|really_overloaded_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_tree_equal
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|no_linkage_check
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_binfo
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_dummy_object
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|maybe_dummy_object
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_dummy_object
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|attribute_spec
name|cp_attribute_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|make_ptrmem_cst
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_build_qualified_type_real
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|cp_build_qualified_type_real ((TYPE), (QUALS),
comment|/*complain=*/
value|1)
end_define

begin_decl_stmt
specifier|extern
name|tree
name|build_shared_int_cst
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|special_function_kind
name|special_function_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|count_trees
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|char_type_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|verify_stmt_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|find_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|linkage_kind
name|decl_linkage
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_walk_subtrees
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|int
operator|*
operator|,
name|walk_tree_fn
operator|,
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_cannot_inline_tree_fn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_add_pending_fn_decls
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_is_overload_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_auto_var_in_fn_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_copy_res_decl_for_inlining
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|void
operator|*
operator|,
name|int
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_start_inlining
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_end_inlining
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in typeck.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|string_conv_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cp_truthvalue_conversion
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|condition_conversion
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|target_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|require_complete_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complete_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complete_type_or_else
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|type_unknown_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|commonparms
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|original_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comp_except_specs
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comptypes
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comp_target_types
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|compparms
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comp_cv_qualification
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comp_cv_qual_signature
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|expr_sizeof
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_sizeof_nowarn
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|inline_conversion
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|decay_conversion
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_object_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_component_ref_1
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_component_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_component_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_indirect_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_indirect_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_array_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_function_call
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_member_function_from_ptrfunc
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_function_call_real
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_function_call_maybe
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_arguments
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_binary_op
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_unary_op
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unary_complex_lvalue
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_conditional_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_compound_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_compound_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_static_cast
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_reinterpret_cast
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_const_cast
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_c_cast
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_modify_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
expr|enum
name|tree_code
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_modify_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
expr|enum
name|tree_code
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|dubious_conversion_warnings
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
specifier|const
name|char
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|convert_for_initialization
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comp_ptr_ttypes
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ptr_reasonably_similar
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_ptrmemfunc
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_type_quals
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_has_mutable_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|at_least_as_qualified_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|more_qualified_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_ptrmemfunc1
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_ptrmemfunc_cst
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|*
operator|,
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|pfn_from_ptrmemfunc
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|type_after_usual_arithmetic_conversions
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|composite_pointer_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|check_return_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* in typeck2.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|error_not_base_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|binfo_or_else
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|readonly_error
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|abstract_virtuals_error
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|my_friendly_assert
parameter_list|(
name|EXP
parameter_list|,
name|N
parameter_list|)
value|(void) \  (((EXP) == 0) ? (fancy_abort (__FILE__, __LINE__, __FUNCTION__), 0) : 0)
end_define

begin_decl_stmt
specifier|extern
name|tree
name|store_init_value
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|digest_init
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_scoped_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_x_arrow
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_m_component_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_functional_cast
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_for_new_type
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|flagged_type_tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|add_exception_specifier
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|merge_exception_specifiers
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in xref.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_begin
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_end
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_file
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_start_scope
name|PARAMS
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_end_scope
name|PARAMS
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_ref
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_call
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_function
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_assign
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_hier
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|GNU_xref_member
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in mangle.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_mangle
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mangle_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|mangle_type_string
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_typeinfo_for_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_typeinfo_string_for_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_vtbl_for_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_vtt_for_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_ctor_vtbl_for_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_thunk
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_conv_op_name_for_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_guard_variable
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|mangle_ref_init_variable
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in dump.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cp_dump_tree
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -- end of C++ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_CP_TREE_H */
end_comment

end_unit

