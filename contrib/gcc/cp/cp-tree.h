begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for C++ parsing and type checking.    Copyright (C) 1987, 92-97, 1998, 1999 Free Software Foundation, Inc.    Hacked by Michael Tiemann (tiemann@cygnus.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CP_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|_CP_TREE_H
end_define

begin_comment
comment|/* Usage of TREE_LANG_FLAG_?:    0: BINFO_MARKED (BINFO nodes).       COMPOUND_STMT_NO_SCOPE (in COMPOUND_STMT).       NEW_EXPR_USE_GLOBAL (in NEW_EXPR).       DELETE_EXPR_USE_GLOBAL (in DELETE_EXPR).       LOOKUP_EXPR_GLOBAL (in LOOKUP_EXPR).       TREE_NEGATED_INT (in INTEGER_CST).       TREE_INDIRECT_USING (in NAMESPACE_DECL).       IDENTIFIER_MARKED (used by search routines).       LOCAL_BINDING_P (in CPLUS_BINDING)    1: IDENTIFIER_VIRTUAL_P.       TI_PENDING_TEMPLATE_FLAG.       TEMPLATE_PARMS_FOR_INLINE.       DELETE_EXPR_USE_VEC (in DELETE_EXPR).       (TREE_CALLS_NEW) (in _EXPR or _REF) (commented-out).       TYPE_USES_COMPLEX_INHERITANCE (in _TYPE).       C_DECLARED_LABEL_FLAG.       INHERITED_VALUE_BINDING_P (in CPLUS_BINDING)       BASELINK_P (in TREE_LIST)    2: IDENTIFIER_OPNAME_P.       BINFO_VBASE_MARKED.       BINFO_FIELDS_MARKED.       TYPE_VIRTUAL_P.    3: TYPE_USES_VIRTUAL_BASECLASSES (in a class TYPE).       BINFO_VTABLE_PATH_MARKED.       BINFO_PUSHDECLS_MARKED.       (TREE_REFERENCE_EXPR) (in NON_LVALUE_EXPR) (commented-out).    4: BINFO_NEW_VTABLE_MARKED.       TREE_HAS_CONSTRUCTOR (in INDIRECT_REF, SAVE_EXPR, CONSTRUCTOR,           or FIELD_DECL).    5: TYPE_USES_PVBASES (in a class TYPE).    6: Not used.     Usage of TYPE_LANG_FLAG_?:    0: C_TYPE_FIELDS_READONLY (in RECORD_TYPE or UNION_TYPE).    1: TYPE_HAS_CONSTRUCTOR.    2: TYPE_HAS_DESTRUCTOR.    3: TYPE_FOR_JAVA.    4: TYPE_NEEDS_DESTRUCTOR.    5: IS_AGGR_TYPE.    6: TYPE_BUILT_IN.     Usage of DECL_LANG_FLAG_?:    0: DECL_ERROR_REPORTED (in VAR_DECL).       DECL_TEMPLATE_PARM_P (in CONST_DECL, TYPE_DECL, or TEMPLATE_DECL)    1: C_TYPEDEF_EXPLICITLY_SIGNED (in TYPE_DECL).       DECL_TEMPLATE_INSTANTIATED (in a VAR_DECL or a FUNCTION_DECL)    2: DECL_THIS_EXTERN (in VAR_DECL or FUNCTION_DECL).    3: DECL_IN_AGGR_P.    4: DECL_MAYBE_TEMPLATE.    5: DECL_INTERFACE_KNOWN.    6: DECL_THIS_STATIC (in VAR_DECL or FUNCTION_DECL).    7: DECL_DEAD_FOR_LOCAL (in VAR_DECL).     Usage of language-independent fields in a language-dependent manner:        TYPE_ALIAS_SET      This field is used by TYPENAME_TYPEs, TEMPLATE_TYPE_PARMs, and so      forth as a substitute for the mark bits provided in `lang_type'.      At present, only the six low-order bits are used.     TYPE_BINFO      For an ENUMERAL_TYPE, this is ENUM_TEMPLATE_INFO.      For a TYPENAME_TYPE, this is TYPENAME_TYPE_FULLNAME.      For a TEMPLATE_TEMPLATE_PARM, this is      TEMPLATE_TEMPLATE_PARM_TEMPLATE_INFO.     DECL_SAVED_INSNS/DECL_FIELD_SIZE      For a static VAR_DECL, this is DECL_INIT_PRIORITY. */
end_comment

begin_comment
comment|/* Language-dependent contents of an identifier.  */
end_comment

begin_struct
struct|struct
name|lang_identifier
block|{
name|struct
name|tree_identifier
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
block|}
name|flagged_type_tree
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|common
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|tree_common
argument_list|)
index|]
decl_stmt|;
name|struct
name|rtx_def
modifier|*
name|rtl
decl_stmt|;
comment|/* Unused, but required to match up with what 			   the middle-end expects.  */
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
name|char
name|common
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|tree_common
argument_list|)
index|]
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
value|TREE_LANG_FLAG_0(NODE)
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
value|TREE_LANG_FLAG_1(NODE)
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
value|(((struct tree_binding*)NODE)->scope.scope)
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
value|(((struct tree_binding*)NODE)->value)
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
value|TREE_TYPE(NODE)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_GLOBAL_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|namespace_binding (NODE, global_namespace)
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
value|set_namespace_binding (NODE, global_namespace, VAL)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_NAMESPACE_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|namespace_binding (NODE, current_namespace)
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
value|set_namespace_binding (NODE, current_namespace, VAL)
end_define

begin_struct
struct|struct
name|tree_binding
block|{
name|char
name|common
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|tree_common
argument_list|)
index|]
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
value|(((struct tree_overload*)NODE)->function)
end_define

begin_define
define|#
directive|define
name|OVL_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_CHAIN(NODE)
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
value|((TREE_CODE(NODE)==OVERLOAD) ? OVL_FUNCTION(NODE) : NODE)
end_define

begin_define
define|#
directive|define
name|OVL_NEXT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_CODE(NODE)==OVERLOAD) ? TREE_CHAIN(NODE) : NULL_TREE)
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
value|TREE_USED(NODE)
end_define

begin_struct
struct|struct
name|tree_overload
block|{
name|char
name|common
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|tree_common
argument_list|)
index|]
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
value|(TREE_CODE ((NODE)) == TREE_LIST&& TREE_LANG_FLAG_1 ((NODE)))
end_define

begin_define
define|#
directive|define
name|SET_BASELINK_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_1 ((NODE)) = 1)
end_define

begin_define
define|#
directive|define
name|WRAPPER_PTR
parameter_list|(
name|NODE
parameter_list|)
value|(((struct tree_wrapper*)NODE)->u.ptr)
end_define

begin_define
define|#
directive|define
name|WRAPPER_INT
parameter_list|(
name|NODE
parameter_list|)
value|(((struct tree_wrapper*)NODE)->u.i)
end_define

begin_struct
struct|struct
name|tree_wrapper
block|{
name|char
name|common
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|tree_common
argument_list|)
index|]
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
value|(((struct tree_srcloc*)NODE)->filename)
end_define

begin_define
define|#
directive|define
name|SRCLOC_LINE
parameter_list|(
name|NODE
parameter_list|)
value|(((struct tree_srcloc*)NODE)->linenum)
end_define

begin_struct
struct|struct
name|tree_srcloc
block|{
name|char
name|common
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|tree_common
argument_list|)
index|]
decl_stmt|;
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
comment|/* To identify to the debug emitters if it should pay attention to the    flag `-Wtemplate-debugging'.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TEMPLATES
value|1
end_define

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
value|(((struct lang_identifier *)(NODE))->namespace_bindings)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((struct lang_identifier *)(NODE))->class_template_info)
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
value|(((struct lang_identifier*) (NODE))->bindings)
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
value|(IDENTIFIER_BINDING (NODE) 			\    ? BINDING_VALUE (IDENTIFIER_BINDING (NODE))	\    : NULL_TREE)
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
value|(((struct lang_identifier *) (NODE))->class_value)
end_define

begin_comment
comment|/* The amount of time used by the file whose special "time identifier"    is NODE, represented as an INTEGER_CST.  See get_time_identifier.  */
end_comment

begin_define
define|#
directive|define
name|TIME_IDENTIFIER_TIME
parameter_list|(
name|NODE
parameter_list|)
value|IDENTIFIER_BINDING(NODE)
end_define

begin_comment
comment|/* For a "time identifier" this is a INTEGER_CST.  The    TREE_INT_CST_LOW is 1 if the corresponding file is "interface only".    The TRE_INT_CST_HIGH is 1 if it is "interface unknown".  */
end_comment

begin_define
define|#
directive|define
name|TIME_IDENTIFIER_FILEINFO
parameter_list|(
name|NODE
parameter_list|)
value|IDENTIFIER_CLASS_VALUE (NODE)
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
value|(identifier_type_value(NODE))
end_define

begin_define
define|#
directive|define
name|REAL_IDENTIFIER_TYPE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_TYPE (NODE))
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
value|(TREE_TYPE (NODE) = TYPE)
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
value|(((struct lang_identifier *)(NODE))->x \    ? ((struct lang_identifier *)(NODE))->x->NAME : 0)
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
value|(((struct lang_identifier *)(NODE))->x == 0				    \    ? ((struct lang_identifier *)(NODE))->x				    \       = (struct lang_id2 *)perm_calloc (1, sizeof (struct lang_id2)) : 0,   \    ((struct lang_identifier *)(NODE))->x->NAME = (VALUE))
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_LABEL_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|LANG_ID_FIELD(label_value, NODE)
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
value|SET_LANG_ID(NODE, VALUE, label_value)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_IMPLICIT_DECL
parameter_list|(
name|NODE
parameter_list|)
value|LANG_ID_FIELD(implicit_decl, NODE)
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
value|SET_LANG_ID(NODE, VALUE, implicit_decl)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_ERROR_LOCUS
parameter_list|(
name|NODE
parameter_list|)
value|LANG_ID_FIELD(error_locus, NODE)
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
value|SET_LANG_ID(NODE, VALUE, error_locus)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1(NODE)
end_define

begin_comment
comment|/* Nonzero if this identifier is the prefix for a mangled C++ operator name.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_OPNAME_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_2(NODE)
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
value|(! strncmp (IDENTIFIER_POINTER (NODE),		\               OPERATOR_TYPENAME_FORMAT,			\ 	      strlen (OPERATOR_TYPENAME_FORMAT)))
end_define

begin_comment
comment|/* Nonzero means reject anything that ANSI standard C forbids.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pedantic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is read-only.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_READONLY
parameter_list|(
name|type
parameter_list|)
value|TYPE_LANG_FLAG_0 (type)
end_define

begin_comment
comment|/* Record in each node resulting from a binary operator    what operator was specified for it.  */
end_comment

begin_define
define|#
directive|define
name|C_EXP_ORIGINAL_CODE
parameter_list|(
name|exp
parameter_list|)
value|((enum tree_code) TREE_COMPLEXITY (exp))
end_define

begin_comment
comment|/* Store a value in that field.  */
end_comment

begin_define
define|#
directive|define
name|C_SET_EXP_ORIGINAL_CODE
parameter_list|(
name|exp
parameter_list|,
name|code
parameter_list|)
define|\
value|(TREE_COMPLEXITY (exp) = (int)(code))
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

begin_decl_stmt
specifier|extern
name|tree
name|double_type_node
decl_stmt|,
name|long_double_type_node
decl_stmt|,
name|float_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|char_type_node
decl_stmt|,
name|unsigned_char_type_node
decl_stmt|,
name|signed_char_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ptrdiff_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|short_integer_type_node
decl_stmt|,
name|short_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_integer_type_node
decl_stmt|,
name|long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_long_integer_type_node
decl_stmt|,
name|long_long_unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|string_type_node
decl_stmt|,
name|char_array_type_node
decl_stmt|,
name|int_array_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|wchar_array_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|wchar_type_node
decl_stmt|,
name|signed_wchar_type_node
decl_stmt|,
name|unsigned_wchar_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_float_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_long_double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intQI_type_node
decl_stmt|,
name|unsigned_intQI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intHI_type_node
decl_stmt|,
name|unsigned_intHI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intSI_type_node
decl_stmt|,
name|unsigned_intSI_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|intDI_type_node
decl_stmt|,
name|unsigned_intDI_type_node
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|>=
literal|64
end_if

begin_decl_stmt
specifier|extern
name|tree
name|intTI_type_node
decl_stmt|,
name|unsigned_intTI_type_node
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|tree
name|java_byte_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|java_short_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|java_int_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|java_long_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|java_float_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|java_double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|java_char_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|java_boolean_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_null
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_function_return_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_namespace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|global_namespace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ridpointers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ansi_opname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ansi_assopname
index|[]
decl_stmt|;
end_decl_stmt

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
comment|/* Nonzero means allow type mismatches in conditional expressions;    just make their values `void'.   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_cond_mismatch
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
comment|/* Nonzero means warn about usage of long long when `-pedantic'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_long_long
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
comment|/* Nonzero means warn about function definitions that default the return type    or that use a null return and have a return-type other than void.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_return_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means give string constants the type `const char *', as mandated    by the standard.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_const_strings
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
comment|/* Nonzero means warn about sizeof(function) or addition/subtraction    of function pointers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_pointer_arith
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about suggesting putting in ()'s.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_parentheses
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
comment|/* Warn about *printf or *scanf format/argument anomalies.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_format
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
comment|/* Non-zero means warn when a function is declared extern and later inline.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_extern_inline
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
comment|/* Nonzero means to treat bitfields as unsigned unless they say `signed'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_signed_bitfields
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3 means write out only virtuals function tables `defined'    in this implementation file.    2 means write out only specific virtual function tables    and give them (C) public access.    1 means write out virtual function tables and give them    (C) public access.    0 means write out virtual function tables and give them    (C) static access (default).    -1 means declare virtual function tables extern.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|write_virtuals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True for more efficient but incompatible (not fully tested)    vtable implementation (using thunks).    0 is old behavior; 1 is new behavior; 3 adds vlist arguments;    2 is 3 plus backwards-compatibility to 1.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_vtable_thunks
decl_stmt|,
name|flag_vtable_thunks_compat
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
comment|/* Nonzero means enable obscure ANSI features and disable GNU extensions    that might cause ANSI-compliant code to be miscompiled.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ansi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means recognize and handle signature language constructs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_handle_signatures
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
comment|/* The name-mangling scheme to use.  Versions of gcc before 2.8 use    version 0.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|name_mangling_version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that guiding declarations are allowed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_guiding_decls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if squashed mangling is to be performed.     This uses the B and K codes to reference previously seen class types     and class qualifiers.       */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_do_squangling
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
comment|/* Nonzero means do not consider empty argument prototype to mean function    takes no arguments.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_strict_prototype
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
comment|/* Nonzero if we want to obey access control semantics.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_access_control
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
name|__DUMMY
init|=
name|LAST_AND_UNUSED_TREE_CODE
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
value|(IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (TYPE_NAME  (NODE))))
end_define

begin_define
define|#
directive|define
name|TYPE_ASSEMBLER_NAME_LENGTH
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_LENGTH (DECL_ASSEMBLER_NAME (TYPE_NAME (NODE))))
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
comment|/* Nonzero if T is a class (or struct or union) type.  Also nonzero    for template type parameters and typename types.  Despite its name,    this macro has nothing to do with the definition of aggregate given    in the standard.  Think of this macro as MAYBE_CLASS_TYPE_P.  */
end_comment

begin_define
define|#
directive|define
name|IS_AGGR_TYPE
parameter_list|(
name|t
parameter_list|)
define|\
value|(TREE_CODE (t) == TEMPLATE_TYPE_PARM 		\    || TREE_CODE (t) == TYPENAME_TYPE 		\    || TREE_CODE (t) == TYPEOF_TYPE		\    || TYPE_LANG_FLAG_5 (t))
end_define

begin_comment
comment|/* Set IS_AGGR_TYPE for T to VAL.  T must be a class, struct, or     union type.  */
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
name|t
parameter_list|)
define|\
value|(IS_AGGR_TYPE_CODE (TREE_CODE (t))&& IS_AGGR_TYPE (t))
end_define

begin_define
define|#
directive|define
name|IS_AGGR_TYPE_CODE
parameter_list|(
name|t
parameter_list|)
value|(t == RECORD_TYPE || t == UNION_TYPE)
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
value|(TREE_CODE (TYPE1) == TREE_CODE (TYPE2)	\&& IS_AGGR_TYPE (TYPE1)&IS_AGGR_TYPE (TYPE2))
end_define

begin_define
define|#
directive|define
name|IS_OVERLOAD_TYPE
parameter_list|(
name|t
parameter_list|)
define|\
value|(IS_AGGR_TYPE (t) || TREE_CODE (t) == ENUMERAL_TYPE)
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
value|TYPE_LANG_FLAG_6(NODE)
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
value|TYPE_LANG_FLAG_3(NODE)
end_define

begin_comment
comment|/* The type qualifiers for this type, including the qualifiers on the    elements for an array type.  */
end_comment

begin_define
define|#
directive|define
name|CP_TYPE_QUALS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_CODE (NODE) != ARRAY_TYPE) 		\    ? TYPE_QUALS (NODE) : cp_type_quals (NODE))
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
value|((CP_TYPE_QUALS (NODE)& TYPE_QUAL_CONST) != 0)
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
value|((CP_TYPE_QUALS (NODE)& TYPE_QUAL_VOLATILE) != 0)
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
value|((CP_TYPE_QUALS (NODE)& TYPE_QUAL_RESTRICT) != 0)
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
value|((CP_TYPE_QUALS (NODE)& (TYPE_QUAL_CONST | TYPE_QUAL_VOLATILE))	\    == TYPE_QUAL_CONST)
end_define

begin_define
define|#
directive|define
name|DELTA_FROM_VTABLE_ENTRY
parameter_list|(
name|ENTRY
parameter_list|)
define|\
value|(!flag_vtable_thunks ? \      TREE_VALUE (CONSTRUCTOR_ELTS (ENTRY)) \    : TREE_CODE (TREE_OPERAND ((ENTRY), 0)) != THUNK_DECL ? integer_zero_node \    : build_int_2 (THUNK_DELTA (TREE_OPERAND ((ENTRY), 0)), 0))
end_define

begin_comment
comment|/* Virtual function addresses can be gotten from a virtual function    table entry using this macro.  */
end_comment

begin_define
define|#
directive|define
name|FNADDR_FROM_VTABLE_ENTRY
parameter_list|(
name|ENTRY
parameter_list|)
define|\
value|(!flag_vtable_thunks ? \      TREE_VALUE (TREE_CHAIN (TREE_CHAIN (CONSTRUCTOR_ELTS (ENTRY)))) \    : TREE_CODE (TREE_OPERAND ((ENTRY), 0)) != THUNK_DECL ? (ENTRY) \    : DECL_INITIAL (TREE_OPERAND ((ENTRY), 0)))
end_define

begin_define
define|#
directive|define
name|SET_FNADDR_FROM_VTABLE_ENTRY
parameter_list|(
name|ENTRY
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(TREE_VALUE (TREE_CHAIN (TREE_CHAIN (CONSTRUCTOR_ELTS (ENTRY)))) = (VALUE))
end_define

begin_define
define|#
directive|define
name|FUNCTION_ARG_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CHAIN (TYPE_ARG_TYPES (TREE_TYPE (NODE))))
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
value|(((CODE) == TREE_CODE (NODE)			\&& IS_AGGR_TYPE (TREE_TYPE (NODE)))	\    || IS_AGGR_TYPE (NODE))
end_define

begin_comment
comment|/* Nonzero iff TYPE is uniquely derived from PARENT.  Under MI, PARENT can    be an ambiguous base class of TYPE, and this macro will be false.  */
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
value|(get_base_distance (PARENT, TYPE, 0, (tree *)0)>= 0)
end_define

begin_define
define|#
directive|define
name|ACCESSIBLY_DERIVED_FROM_P
parameter_list|(
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
value|(get_base_distance (PARENT, TYPE, -1, (tree *)0)>= 0)
end_define

begin_define
define|#
directive|define
name|ACCESSIBLY_UNIQUELY_DERIVED_P
parameter_list|(
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
value|(get_base_distance (PARENT, TYPE, 1, (tree *)0)>= 0)
end_define

begin_define
define|#
directive|define
name|DERIVED_FROM_P
parameter_list|(
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
value|(get_base_distance (PARENT, TYPE, 0, (tree *)0) != -1)
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
struct|struct
block|{
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
name|anon_union
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_nonpublic_ctor
range|:
literal|2
decl_stmt|;
name|unsigned
name|has_nonpublic_assign_ref
range|:
literal|2
decl_stmt|;
name|unsigned
name|vtable_needs_writing
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_assign_ref
range|:
literal|1
decl_stmt|;
name|unsigned
name|gets_new
range|:
literal|2
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
name|vec_delete_takes_size
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
name|is_signature
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_signature_pointer
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_signature_reference
range|:
literal|1
decl_stmt|;
name|unsigned
name|has_opaque_typedecls
range|:
literal|1
decl_stmt|;
name|unsigned
name|sigtable_has_been_generated
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
name|has_mutable
range|:
literal|1
decl_stmt|;
name|unsigned
name|com_interface
range|:
literal|1
decl_stmt|;
comment|/* When adding a flag here, consider whether or not it ought to 	 apply to a template instance if it applies to the template. 	 If so, make sure to copy it in instantiate_class_template!  */
comment|/* The MIPS compiler gets it wrong if this struct also 	 does not fill out to a multiple of 4 bytes.  Add a 	 member `dummy' with new bits if you go over the edge.  */
name|unsigned
name|dummy
range|:
literal|10
decl_stmt|;
block|}
name|type_flags
struct|;
name|int
name|vsize
decl_stmt|;
name|int
name|vfield_parent
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vfields
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vbases
decl_stmt|;
name|union
name|tree_node
modifier|*
name|tags
decl_stmt|;
name|union
name|tree_node
modifier|*
name|search_slot
decl_stmt|;
name|unsigned
name|char
name|align
decl_stmt|;
comment|/* Room for another three unsigned chars.  */
name|union
name|tree_node
modifier|*
name|size
decl_stmt|;
name|union
name|tree_node
modifier|*
name|abstract_virtuals
decl_stmt|;
name|union
name|tree_node
modifier|*
name|friend_classes
decl_stmt|;
name|union
name|tree_node
modifier|*
name|rtti
decl_stmt|;
name|union
name|tree_node
modifier|*
name|methods
decl_stmt|;
name|union
name|tree_node
modifier|*
name|signature
decl_stmt|;
name|union
name|tree_node
modifier|*
name|signature_pointer_to
decl_stmt|;
name|union
name|tree_node
modifier|*
name|signature_reference_to
decl_stmt|;
name|union
name|tree_node
modifier|*
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.use_template)
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
value|(TYPE_NONCOPIED_PARTS (NODE))
end_define

begin_comment
comment|/* Nonzero for _CLASSTYPE means that operator new and delete are defined,    respectively.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_GETS_NEW
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_new)
end_define

begin_define
define|#
directive|define
name|TYPE_GETS_DELETE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.gets_delete)
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
comment|/* Nonzero for _CLASSTYPE means that operator vec delete is defined and    takes the optional size_t argument.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_VEC_DELETE_TAKES_SIZE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.vec_delete_takes_size)
end_define

begin_define
define|#
directive|define
name|TYPE_VEC_NEW_USES_COOKIE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_NEEDS_DESTRUCTOR (NODE) \    || (TYPE_LANG_SPECIFIC (NODE)&& TYPE_VEC_DELETE_TAKES_SIZE (NODE)))
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_type_conversion)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_CONST_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_const_assign_ref)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_init_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_CONST_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_const_init_ref)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.being_defined)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.redefined)
end_define

begin_comment
comment|/* Nonzero means that this type is a signature.  */
end_comment

begin_define
define|#
directive|define
name|IS_SIGNATURE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)?TYPE_LANG_SPECIFIC(NODE)->type_flags.is_signature:0)
end_define

begin_define
define|#
directive|define
name|SET_SIGNATURE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.is_signature=1)
end_define

begin_define
define|#
directive|define
name|CLEAR_SIGNATURE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.is_signature=0)
end_define

begin_comment
comment|/* Nonzero means that this type is a signature pointer type.  */
end_comment

begin_define
define|#
directive|define
name|IS_SIGNATURE_POINTER
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.is_signature_pointer)
end_define

begin_comment
comment|/* Nonzero means that this type is a signature reference type.  */
end_comment

begin_define
define|#
directive|define
name|IS_SIGNATURE_REFERENCE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.is_signature_reference)
end_define

begin_comment
comment|/* Nonzero means that this signature contains opaque type declarations.  */
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_HAS_OPAQUE_TYPEDECLS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_opaque_typedecls)
end_define

begin_comment
comment|/* Nonzero means that a signature table has been generated    for this signature.  */
end_comment

begin_define
define|#
directive|define
name|SIGTABLE_HAS_BEEN_GENERATED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.sigtable_has_been_generated)
end_define

begin_comment
comment|/* If NODE is a class, this is the signature type that contains NODE's    signature after it has been computed using sigof().  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SIGNATURE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->signature)
end_define

begin_comment
comment|/* If NODE is a signature pointer or signature reference, this is the    signature type the pointer/reference points to.  */
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->signature)
end_define

begin_comment
comment|/* If NODE is a signature, this is a vector of all methods defined    in the signature or in its base types together with their default    implementations.  */
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_METHOD_VEC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->signature)
end_define

begin_comment
comment|/* If NODE is a signature, this is the _TYPE node that contains NODE's    signature pointer type.  */
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_POINTER_TO
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->signature_pointer_to)
end_define

begin_comment
comment|/* If NODE is a signature, this is the _TYPE node that contains NODE's    signature reference type.  */
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_REFERENCE_TO
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->signature_reference_to)
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
value|(TYPE_LANG_SPECIFIC(NODE)->rtti)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_call_overloaded)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_array_ref_overloaded)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_arrow_overloaded)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.uses_multiple_inheritance)
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
value|(TREE_LANG_FLAG_3(NODE))
end_define

begin_comment
comment|/* Nonzero means that this _CLASSTYPE uses polymorphic virtual bases.    This flag is set only when we use vtable thunks.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_PVBASES
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_5(NODE))
end_define

begin_comment
comment|/* Vector member functions defined in this class.  Each element is    either a FUNCTION_DECL, a TEMPLATE_DECL, or an OVERLOAD.  All    functions with the same name end up in the same slot.  The first    two elements are for constructors, and destructors, respectively.    These are followed by ordinary member functions.  There may be    empty entries at the end of the vector.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_METHOD_VEC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->methods)
end_define

begin_comment
comment|/* The first type conversion operator in the class (the others can be    searched with TREE_CHAIN), or the first non-constructor function if    there are no type conversion operators.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_FIRST_CONVERSION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_VEC_LENGTH (CLASSTYPE_METHOD_VEC (NODE))> 2 \     ? TREE_VEC_ELT (CLASSTYPE_METHOD_VEC (NODE), 2) \     : NULL_TREE;
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
value|(((CLASS_TYPE_P (NODE) ? TYPE_LANG_SPECIFIC (NODE)->type_flags.marks	\      : TYPE_ALIAS_SET (NODE))& (1<< N)) != 0)
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
value|(CLASS_TYPE_P (NODE)							\    ? (TYPE_LANG_SPECIFIC (NODE)->type_flags.marks |= (1<< (N)))	\    : (TYPE_ALIAS_SET (NODE) |= (1<< (N))))
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
value|(CLASS_TYPE_P (NODE)							\    ? (TYPE_LANG_SPECIFIC (NODE)->type_flags.marks&= ~(1<< (N)))	\    : (TYPE_ALIAS_SET (NODE)&= ~(1<< (N))))
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
value|CLASSTYPE_MARKED_N(NODE, 0)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N(NODE, 1)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N(NODE, 2)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N(NODE, 3)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N(NODE, 4)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED_N(NODE, 5)
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
value|SET_CLASSTYPE_MARKED_N(NODE, 0)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N(NODE, 0)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N(NODE, 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED2
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N(NODE, 1)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N(NODE, 2)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED3
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N(NODE, 2)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N(NODE, 3)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED4
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N(NODE, 3)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N(NODE, 4)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED5
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N(NODE, 4)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED_N(NODE, 5)
end_define

begin_define
define|#
directive|define
name|CLEAR_CLASSTYPE_MARKED6
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED_N(NODE, 5)
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
value|(TYPE_LANG_SPECIFIC(NODE)->tags)
end_define

begin_comment
comment|/* If this class has any bases, this is the number of the base class from    which our VFIELD is based, -1 otherwise.  If this class has no base    classes, this is not used.    In D : B1, B2, PARENT would be 0, if D's vtable came from B1,    1, if D's vtable came from B2.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VFIELD_PARENT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vfield_parent)
end_define

begin_comment
comment|/* Remove when done merging.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VFIELD
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_VFIELD(NODE)
end_define

begin_comment
comment|/* The number of virtual functions defined for this    _CLASSTYPE node.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VSIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vsize)
end_define

begin_comment
comment|/* The list of binfos of virtual base classes that this type uses.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VBASECLASSES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vbases)
end_define

begin_comment
comment|/* The virtual function pointer fields that this type contains.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VFIELDS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->vfields)
end_define

begin_comment
comment|/* Number of baseclasses defined for this type.    0 means no base classes.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_N_BASECLASSES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_BINFO_BASETYPES (NODE) ? TREE_VEC_LENGTH (TYPE_BINFO_BASETYPES(NODE)) : 0)
end_define

begin_comment
comment|/* Used for keeping search-specific information.  Any search routine    which uses this must define what exactly this slot is used for.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SEARCH_SLOT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->search_slot)
end_define

begin_comment
comment|/* These are the size, mode and alignment of the type without its    virtual base classes, for when we use this type as a base itself.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->size)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->align)
end_define

begin_comment
comment|/* A cons list of virtual functions which cannot be inherited by    derived classes.  When deriving from this type, the derived    class must provide its own definition for each of these functions.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_ABSTRACT_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->abstract_virtuals)
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
value|(TYPE_LANG_SPECIFIC (NODE)->type_flags.got_semicolon)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.needs_virtual_reinit)
end_define

begin_comment
comment|/* Nonzero means that if this type has virtual functions, that    the virtual function table will be written out.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_VTABLE_NEEDS_WRITING
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.vtable_needs_writing)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_default_ctor)
end_define

begin_comment
comment|/* Nonzero means the type declared a ctor as private or protected.  We    use this to make sure we don't try to generate a copy ctor for a     class that has a member of type NODE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_NONPUBLIC_CTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_nonpublic_ctor)
end_define

begin_comment
comment|/* Ditto, for operator=.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HAS_NONPUBLIC_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_nonpublic_assign_ref)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_mutable)
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
comment|/* Nonzero means that this type is meant for communication via COM.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_COM_INTERFACE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.com_interface)
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
value|(TYPE_LANG_SPECIFIC(NODE)->friend_classes)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.declared_class)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.const_needs_init)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.ref_needs_init)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_only)
end_define

begin_comment
comment|/* Same as above, but for classes whose purpose we do not know.  */
end_comment

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_UNKNOWN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_unknown)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_INTERFACE_KNOWN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_unknown == 0)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_unknown = !!(X))
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_INTERFACE_UNKNOWN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_unknown = 1)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_INTERFACE_KNOWN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.interface_unknown = 0)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.debug_requested)
end_define

begin_escape
end_escape

begin_comment
comment|/* Additional macros for inheritance information.  */
end_comment

begin_comment
comment|/* The BINFO_INHERITANCE_CHAIN is used opposite to the description in    gcc/tree.h.  In particular if D is derived from B then the BINFO    for B (in D) will have a BINFO_INHERITANCE_CHAIN pointing to    D.  In tree.h, this pointer is described as pointing in other    direction.  There is a different BINFO for each path to a virtual    base; BINFOs for virtual bases are not shared.  In addition, shared    versions of each of the virtual class BINFOs are stored in    CLASSTYPE_VBASECLASSES.     We use TREE_VIA_PROTECTED and TREE_VIA_PUBLIC, but private    inheritance is indicated by the absence of the other two flags, not    by TREE_VIAR_PRIVATE, which is unused.     The TREE_CHAIN is for scratch space in search.c.  */
end_comment

begin_comment
comment|/* Nonzero means marked by DFS or BFS search, including searches    by `get_binfo' and `get_base_distance'.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED(BINFO_TYPE(NODE)):TREE_LANG_FLAG_0(NODE))
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
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_0(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_0(NODE)=0))
end_define

begin_comment
comment|/* Nonzero means marked in search through virtual inheritance hierarchy.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VBASE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_comment
comment|/* Modifier macros */
end_comment

begin_define
define|#
directive|define
name|SET_BINFO_VBASE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|SET_CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_VBASE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|CLEAR_CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
end_define

begin_comment
comment|/* Nonzero means marked in search for members or member functions.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_FIELDS_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED2 (BINFO_TYPE (NODE)):TREE_LANG_FLAG_2(NODE))
end_define

begin_define
define|#
directive|define
name|SET_BINFO_FIELDS_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED2(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_2(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_FIELDS_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED2(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_2(NODE)=0))
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
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):TREE_LANG_FLAG_3(NODE))
end_define

begin_define
define|#
directive|define
name|SET_BINFO_VTABLE_PATH_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_3(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_VTABLE_PATH_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_3(NODE)=0))
end_define

begin_comment
comment|/* Nonzero means that this class has a new vtable.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):TREE_LANG_FLAG_4(NODE))
end_define

begin_define
define|#
directive|define
name|SET_BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_4(NODE)=1))
end_define

begin_define
define|#
directive|define
name|CLEAR_BINFO_NEW_VTABLE_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_4(NODE)=0))
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
value|(VF_BINFO_VALUE (NODE) ? BINFO_TYPE (VF_BINFO_VALUE (NODE)) : NULL_TREE)
end_define

begin_comment
comment|/* Get the value of the top-most type that's `normal' for the vfield.  */
end_comment

begin_define
define|#
directive|define
name|VF_NORMAL_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_TYPE (NODE)
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
value|((NODE)->common.unsigned_flag)
end_define

begin_comment
comment|/* overloaded! */
end_comment

begin_comment
comment|/* For FUNCTION_TYPE or METHOD_TYPE, a list of the exceptions that    this type can raise.  Each TREE_VALUE is a _TYPE.  The TREE_VALUE    will be NULL_TREE to indicate a throw specification of `(...)', or,    equivalently, no throw specification.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_RAISES_EXCEPTIONS
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_NONCOPIED_PARTS (NODE)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.level)
end_define

begin_escape
end_escape

begin_comment
comment|/* If a DECL has DECL_LANG_SPECIFIC, it is either a lang_decl_flags or    a lang_decl (which has lang_decl_flags as its initial prefix).  A    FUNCTION_DECL, NAMESPACE_DECL, TYPE_DECL, or USING_DECL may have a    full lang_decl.  A FIELD_DECL, or a static data member VAR_DECL,    will have only lang_decl_flags.  Thus, one should only access the    members of lang_decl that are not in lang_decl_flags for DECLs that    are not FIELD_DECLs or VAR_DECLs.  */
end_comment

begin_struct
struct|struct
name|lang_decl_flags
block|{
ifdef|#
directive|ifdef
name|ONLY_INT_FIELDS
name|int
name|language
range|:
literal|8
decl_stmt|;
else|#
directive|else
name|enum
name|languages
name|language
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
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
name|const_memfunc
range|:
literal|1
decl_stmt|;
name|unsigned
name|volatile_memfunc
range|:
literal|1
decl_stmt|;
name|unsigned
name|abstract_virtual
range|:
literal|1
decl_stmt|;
name|unsigned
name|permanent_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|mutable_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_default_implementation
range|:
literal|1
decl_stmt|;
name|unsigned
name|saved_inline
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
name|declared_inline
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
name|bitfield
range|:
literal|1
decl_stmt|;
name|unsigned
name|defined_in_class
range|:
literal|1
decl_stmt|;
name|unsigned
name|constructor_for_vbase_attr
range|:
literal|2
decl_stmt|;
name|unsigned
name|dummy
range|:
literal|3
decl_stmt|;
name|tree
name|access
decl_stmt|;
name|tree
name|context
decl_stmt|;
name|tree
name|memfunc_pointer_to
decl_stmt|;
name|tree
name|template_info
decl_stmt|;
name|struct
name|binding_level
modifier|*
name|level
decl_stmt|;
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
name|main_decl_variant
decl_stmt|;
name|tree
name|befriending_classes
decl_stmt|;
name|struct
name|pending_inline
modifier|*
name|pending_inline_info
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Non-zero if NODE is a _DECL with TREE_READONLY set.  */
end_comment

begin_define
define|#
directive|define
name|TREE_READONLY_DECL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_READONLY (NODE)&& TREE_CODE_CLASS (TREE_CODE (NODE)) == 'd')
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
value|(DECL_RTL (NODE) != NULL_RTX&& GET_CODE (DECL_RTL (NODE)) == MEM)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: return the language in which this decl    was declared.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LANGUAGE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.language)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_attr)
end_define

begin_comment
comment|/* There ought to be a better way to find out whether or not something is    a destructor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DESTRUCTOR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DESTRUCTOR_NAME_P (DECL_ASSEMBLER_NAME (NODE))	\&& DECL_LANGUAGE (NODE) == lang_cplusplus)
end_define

begin_define
define|#
directive|define
name|DECL_CONV_FN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_TYPENAME_P (DECL_NAME (NODE))&& TREE_TYPE (DECL_NAME (NODE)))
end_define

begin_define
define|#
directive|define
name|CONSTRUCTOR_FOR_VBASE
value|1
end_define

begin_define
define|#
directive|define
name|CONSTRUCTOR_FOR_PVBASE
value|2
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_FOR_PVBASE
value|3
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that this function is a con/destructor    for an object with virtual baseclasses.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTOR_FOR_VBASE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_for_vbase_attr)
end_define

begin_comment
comment|/* Nonzero means that this function is a constructor for an object    with virtual baseclasses.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTOR_FOR_VBASE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONSTRUCTOR_FOR_VBASE (NODE) == CONSTRUCTOR_FOR_VBASE)
end_define

begin_comment
comment|/* Nonzero means that this function is a constructor for an object    with virtual baseclasses which have virtual functions.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONSTRUCTOR_FOR_PVBASE_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_for_vbase_attr == CONSTRUCTOR_FOR_PVBASE)
end_define

begin_comment
comment|/* Nonzero means that this function is a destructor for an object    with virtual baseclasses which have virtual functions.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DESTRUCTOR_FOR_PVBASE_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_for_vbase_attr == DESTRUCTOR_FOR_PVBASE)
end_define

begin_comment
comment|/* Nonzero means that this function is a wrapper around a PVBASE ctor.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VLIST_CTOR_WRAPPER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CONSTRUCTOR_FOR_VBASE_P (NODE)&& DECL_VLIST_CTOR_WRAPPED (NODE)\&& TREE_CODE (DECL_VLIST_CTOR_WRAPPED (NODE)) == FUNCTION_DECL \&& DECL_CONSTRUCTOR_FOR_PVBASE_P (DECL_VLIST_CTOR_WRAPPED (NODE)))
end_define

begin_comment
comment|/* Refers to original function that NODE wraps.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VLIST_CTOR_WRAPPED
parameter_list|(
name|NODE
parameter_list|)
value|DECL_MEMFUNC_POINTER_TO (NODE)
end_define

begin_comment
comment|/* Non-zero for a FUNCTION_DECL that declares a type-info function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TINFO_FN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == FUNCTION_DECL				\&& DECL_ARTIFICIAL (NODE)					\&& DECL_LANG_SPECIFIC(NODE)->decl_flags.mutable_flag)
end_define

begin_comment
comment|/* Mark NODE as a type-info function.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_TINFO_FN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC((NODE))->decl_flags.mutable_flag = 1)
end_define

begin_comment
comment|/* For FUNCTION_DECLs: nonzero means that this function is a default    implementation of a signature method.  */
end_comment

begin_define
define|#
directive|define
name|IS_DEFAULT_IMPLEMENTATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.is_default_implementation)
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
value|(DECL_LANG_FLAG_3(NODE))
end_define

begin_comment
comment|/* Nonzero if the DECL was defined in the class definition itself,    rather than outside the class.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DEFINED_IN_CLASS_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (DECL)->decl_flags.defined_in_class)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.friend_attr)
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
value|(DECL_LANG_SPECIFIC(NODE)->befriending_classes)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.static_function)
end_define

begin_comment
comment|/* Nonzero for a class member means that it is shared between all objects    of that class.  */
end_comment

begin_define
define|#
directive|define
name|SHARED_MEMBER_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == VAR_DECL || TREE_CODE (NODE) == TYPE_DECL \    || TREE_CODE (NODE) == CONST_DECL)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.const_memfunc)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.volatile_memfunc)
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
value|((TREE_CODE (NODE) == FUNCTION_DECL 		\&& DECL_NONSTATIC_MEMBER_FUNCTION_P (NODE))	\    || TREE_CODE (NODE) == FIELD_DECL)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.mutable_flag)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.nonconverting)
end_define

begin_comment
comment|/* Nonzero for FUNCTION_DECL means that this member function    exists as part of an abstract class's interface.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ABSTRACT_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.abstract_virtual)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.needs_final_overrider)
end_define

begin_comment
comment|/* Nonzero if allocated on permanent_obstack.  */
end_comment

begin_define
define|#
directive|define
name|LANG_DECL_PERMANENT
parameter_list|(
name|LANGDECL
parameter_list|)
value|((LANGDECL)->decl_flags.permanent_attr)
end_define

begin_comment
comment|/* The _TYPE context in which this _DECL appears.  This field holds the    class where a virtual function instance is actually defined, and the    lexical scope of a friend function defined in a class body. */
end_comment

begin_define
define|#
directive|define
name|DECL_CLASS_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.context)
end_define

begin_define
define|#
directive|define
name|DECL_REAL_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_CODE (NODE) == FUNCTION_DECL&& DECL_FUNCTION_MEMBER_P (NODE)) \    ? DECL_CLASS_CONTEXT (NODE) : CP_DECL_CONTEXT (NODE))
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
value|DECL_CONTEXT (NODE)
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
value|(DECL_CONTEXT (NODE) == NULL_TREE \    || TREE_CODE (DECL_CONTEXT (NODE)) == NAMESPACE_DECL)
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
value|(DECL_CONTEXT (NODE) \&& TREE_CODE_CLASS (TREE_CODE (DECL_CONTEXT (NODE))) == 't')
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
comment|/* For a NAMESPACE_DECL: the list of using namespace directives    The PURPOSE is the used namespace, the value is the namespace    that is the common ancestor. */
end_comment

begin_define
define|#
directive|define
name|DECL_NAMESPACE_USING
parameter_list|(
name|NODE
parameter_list|)
value|DECL_VINDEX(NODE)
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
value|DECL_INITIAL (NODE)
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
value|DECL_ABSTRACT_ORIGIN (NODE)
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
comment|/* In a non-local VAR_DECL with static storage duration, this is the    initialization priority.  If this value is zero, the NODE will be    initialized at the DEFAULT_INIT_PRIORITY.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INIT_PRIORITY
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_FIELD_SIZE ((NODE)))
end_define

begin_comment
comment|/* In a TREE_LIST concatenating using directives, indicate indirekt    directives  */
end_comment

begin_define
define|#
directive|define
name|TREE_INDIRECT_USING
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.lang_flag_0)
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
value|DECL_RESULT(NODE)
end_define

begin_comment
comment|/* Points back to the decl which caused this lang_decl to be allocated.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MAIN_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->main_decl_variant)
end_define

begin_comment
comment|/* For a FUNCTION_DECL: if this function was declared inline inside of    a class declaration, this is where the text for the function is    squirreled away.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PENDING_INLINE_INFO
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->pending_inline_info)
end_define

begin_comment
comment|/* True if on the saved_inlines (see decl2.c) list.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SAVED_INLINE
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC(DECL)->decl_flags.saved_inline)
end_define

begin_comment
comment|/* For a FUNCTION_DECL: if this function was declared inside a signature    declaration, this is the corresponding member function pointer that was    created for it.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MEMFUNC_POINTER_TO
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.memfunc_pointer_to)
end_define

begin_comment
comment|/* For a FIELD_DECL: this points to the signature member function from    which this signature member function pointer was created.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MEMFUNC_POINTING_TO
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.memfunc_pointer_to)
end_define

begin_comment
comment|/* For a VAR_DECL or FUNCTION_DECL: template-specific information.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_INFO
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.template_info)
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
value|(TYPE_LANG_SPECIFIC(NODE)->template_info)
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
value|(TYPE_BINFO (NODE))
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
value|(TYPE_BINFO (NODE))
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
value|(TREE_CODE (NODE) == ENUMERAL_TYPE			\    ? ENUM_TEMPLATE_INFO (NODE) : 			\    (TREE_CODE (NODE) == TEMPLATE_TEMPLATE_PARM		\     ? TEMPLATE_TEMPLATE_PARM_TEMPLATE_INFO (NODE)	\     : CLASSTYPE_TEMPLATE_INFO (NODE)))
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
value|(TREE_CODE (NODE) == ENUMERAL_TYPE 		\    ? (ENUM_TEMPLATE_INFO (NODE) = VAL) 		\    : (CLASSTYPE_TEMPLATE_INFO (NODE) = VAL))
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
name|TI_SPEC_INFO
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CHAIN (NODE))
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
comment|/* The TEMPLATE_DECL instantiated or specialized by NODE.  This    TEMPLATE_DECL will be the immediate parent, not the most general    template.  For example, in:        template<class T> struct S { template<class U> void f(U); }     the FUNCTION_DECL for S<int>::f<double> will have, as its    DECL_TI_TEMPLATE, `template<class U> S<int>::f<U>'.      As a special case, for a member friend template of a template    class, this value will not be a TEMPLATE_DECL, but rather a    LOOKUP_EXPR or IDENTIFIER_NODE indicating the name of the template    and any explicit template arguments provided.  For example, in:       template<class T> struct S { friend void f<int>(int, double); }     the DECL_TI_TEMPLATE will be a LOOKUP_EXPR for `f' and the    DECL_TI_ARGS will be {int}.  */
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
name|CLASSTYPE_TI_SPEC_INFO
parameter_list|(
name|NODE
parameter_list|)
value|TI_SPEC_INFO (CLASSTYPE_TEMPLATE_INFO (NODE))
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
comment|/* Like DECL_TI_ARGS, , but for an ENUMERAL_, RECORD_, or UNION_TYPE.  */
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
value|TREE_VALUE(NODE)
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

begin_define
define|#
directive|define
name|DECL_SAVED_TREE
parameter_list|(
name|NODE
parameter_list|)
value|DECL_MEMFUNC_POINTER_TO (NODE)
end_define

begin_define
define|#
directive|define
name|COMPOUND_STMT_NO_SCOPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
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
value|TYPE_BINFO (NODE)
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
comment|/* Nonzero in INTEGER_CST means that this int is negative by dint of    using a twos-complement negated operand.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NEGATED_INT
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_0 (NODE))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* UNUSED */
end_comment

begin_comment
comment|/* Nonzero in any kind of _EXPR or _REF node means that it is a call    to a storage allocation routine.  If, later, alternate storage    is found to hold the object, this call can be ignored.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CALLS_NEW
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1 (NODE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero in any kind of _TYPE that uses multiple inheritance    or virtual baseclasses.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USES_COMPLEX_INHERITANCE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_1 (NODE))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* UNUSED */
end_comment

begin_comment
comment|/* Nonzero in IDENTIFIER_NODE means that this name is not the name the user    gave; it's a DECL_NESTED_TYPENAME.  Someone may want to set this on    mangled function names, too, but it isn't currently.  */
end_comment

begin_define
define|#
directive|define
name|TREE_MANGLED
parameter_list|(
name|NODE
parameter_list|)
value|(FOO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* UNUSED */
end_comment

begin_comment
comment|/* Nonzero in IDENTIFIER_NODE means that this name is overloaded, and    should be looked up in a non-standard way.  */
end_comment

begin_define
define|#
directive|define
name|DECL_OVERLOADED
parameter_list|(
name|NODE
parameter_list|)
value|(FOO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if this (non-TYPE)_DECL has its virtual attribute set.    For a FUNCTION_DECL, this is when the function is a virtual function.    For a VAR_DECL, this is when the variable is a virtual function table.    For a FIELD_DECL, when the field is the field for the virtual function table.    For an IDENTIFIER_NODE, nonzero if any function with this name    has been declared virtual.     For a _TYPE if it uses virtual functions (or is derived from    one that does).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_2 (NODE))
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
value|DECL_LANG_FLAG_7 (NODE)
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
value|DECL_LANG_FLAG_0 (NODE)
end_define

begin_comment
comment|/* This _DECL represents a compiler-generated entity.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_ARTIFICIAL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_ARTIFICIAL (NODE) = 1)
end_define

begin_comment
comment|/* Record whether a typedef for type `int' was actually `signed int'.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPEDEF_EXPLICITLY_SIGNED
parameter_list|(
name|exp
parameter_list|)
value|DECL_LANG_FLAG_1 ((exp))
end_define

begin_comment
comment|/* In a FIELD_DECL, nonzero if the decl was originally a bitfield.  */
end_comment

begin_define
define|#
directive|define
name|DECL_C_BIT_FIELD
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)&& DECL_LANG_SPECIFIC (NODE)->decl_flags.bitfield)
end_define

begin_define
define|#
directive|define
name|SET_DECL_C_BIT_FIELD
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.bitfield = 1)
end_define

begin_comment
comment|/* Nonzero if the type T promotes to itself.    ANSI C states explicitly the list of types that promote;    in particular, short promotes to int even if they have the same width.  */
end_comment

begin_define
define|#
directive|define
name|C_PROMOTING_INTEGER_TYPE_P
parameter_list|(
name|t
parameter_list|)
define|\
value|(TREE_CODE ((t)) == INTEGER_TYPE				\&& (TYPE_MAIN_VARIANT (t) == char_type_node			\        || TYPE_MAIN_VARIANT (t) == signed_char_type_node	\        || TYPE_MAIN_VARIANT (t) == unsigned_char_type_node	\        || TYPE_MAIN_VARIANT (t) == short_integer_type_node	\        || TYPE_MAIN_VARIANT (t) == short_unsigned_type_node))
end_define

begin_define
define|#
directive|define
name|INTEGRAL_CODE_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(CODE == INTEGER_TYPE || CODE == ENUMERAL_TYPE || CODE == BOOLEAN_TYPE)
end_define

begin_define
define|#
directive|define
name|ARITHMETIC_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
value|(INTEGRAL_TYPE_P (TYPE) || FLOAT_TYPE_P (TYPE))
end_define

begin_comment
comment|/* Mark which labels are explicitly declared.    These may be shadowed, and may be referenced from nested functions.  */
end_comment

begin_define
define|#
directive|define
name|C_DECLARED_LABEL_FLAG
parameter_list|(
name|label
parameter_list|)
value|TREE_LANG_FLAG_1 (label)
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
value|(TYPE_LANG_FLAG_1(NODE))
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
value|(TREE_LANG_FLAG_4(NODE))
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Indicates that a NON_LVALUE_EXPR came from a C++ reference.    Used to generate more helpful error message in case somebody    tries to take its address.  */
end_comment

begin_define
define|#
directive|define
name|TREE_REFERENCE_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_3(NODE))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(TYPE_LANG_FLAG_2(NODE))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Nonzero for _TYPE node means that creating an object of this type    will involve a call to a constructor.  This can apply to objects    of ARRAY_TYPE if the type of the elements needs a constructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NEEDS_CONSTRUCTING
parameter_list|(
name|NODE
parameter_list|)
value|... defined in ../tree.h ...
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(TYPE_LANG_SPECIFIC (NODE)->type_flags.non_aggregate)
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
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_real_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_COMPLEX_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_complex_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_ABSTRACT_ASSIGN_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_abstract_assign_ref)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_COMPLEX_INIT_REF
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.has_complex_init_ref)
end_define

begin_comment
comment|/* Nonzero for _TYPE node means that destroying an object of this type    will involve a call to a destructor.  This can apply to objects    of ARRAY_TYPE is the type of the elements needs a destructor.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NEEDS_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_FLAG_4(NODE))
end_define

begin_comment
comment|/* Nonzero for class type means that initialization of this type can use    a bitwise copy.  */
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
value|(TREE_CODE(NODE) == RECORD_TYPE&& TYPE_PTRMEMFUNC_FLAG (NODE))
end_define

begin_define
define|#
directive|define
name|TYPE_PTRMEMFUNC_FLAG
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC(NODE)->type_flags.ptrmemfunc_flag)
end_define

begin_comment
comment|/* A pointer-to-function member type looks like:     struct {      short __delta;      short __index;      union {        P __pfn;        short __delta2;      } __pfn_or_delta2;    };     where P is a POINTER_TYPE to a METHOD_TYPE appropriate for the    pointer to member.  The fields are used as follows:       If __INDEX is -1, then the function to call is non-virtual, and      is located at the address given by __PFN.       If __INDEX is zero, then this a NULL pointer-to-member.       Otherwise, the function to call is virtual.  Then, __DELTA2 gives      the offset from an instance of the object to the virtual function      table, and __INDEX - 1 is the index into the vtable to use to      find the function.       The value to use for the THIS parameter is the address of the      object plus __DELTA.     For example, given:       struct B1 {        int i;      };       struct B2 {        double d;        void f();      };       struct S : public B1, B2 {};     the pointer-to-member for `&S::f' looks like:       { 4, -1, {&f__2B2 } };     The `4' means that given an `S*' you have to add 4 bytes to get to    the address of the `B2*'.  Then, the -1 indicates that this is a    non-virtual function.  Of course, `&f__2B2' is the name of that    function.     (Of course, the exactl values may differ depending on the mangling    scheme, sizes of types, and such.).  */
end_comment

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
value|(TREE_TYPE (TYPE_FIELDS (TREE_TYPE (TREE_CHAIN (TREE_CHAIN (TYPE_FIELDS (NODE)))))))
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
value|((tree)TYPE_LANG_SPECIFIC(NODE))
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
value|(TYPE_LANG_SPECIFIC(NODE) = ((struct lang_type *)(void*)(VALUE)))
end_define

begin_comment
comment|/* These are to get the delta2 and pfn fields from a TYPE_PTRMEMFUNC_P.  */
end_comment

begin_define
define|#
directive|define
name|DELTA2_FROM_PTRMEMFUNC
parameter_list|(
name|NODE
parameter_list|)
value|delta2_from_ptrmemfunc ((NODE))
end_define

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
value|(TYPE_PTRMEM_P (TREE_TYPE (NODE)) 			  \     ? TYPE_OFFSET_BASETYPE (TREE_TYPE (TREE_TYPE (NODE))) \     : TYPE_PTRMEMFUNC_OBJECT_TYPE (TREE_TYPE (NODE)))
end_define

begin_comment
comment|/* For a pointer-to-member constant `X::Y' this is the _DECL for     `Y'.  */
end_comment

begin_define
define|#
directive|define
name|PTRMEM_CST_MEMBER
parameter_list|(
name|NODE
parameter_list|)
value|(((ptrmem_cst_t) NODE)->member)
end_define

begin_comment
comment|/* Nonzero for VAR_DECL and FUNCTION_DECL node means that `extern' was    specified in its declaration.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THIS_EXTERN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_2(NODE))
end_define

begin_comment
comment|/* Nonzero for VAR_DECL and FUNCTION_DECL node means that `static' was    specified in its declaration.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THIS_STATIC
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_FLAG_6(NODE))
end_define

begin_comment
comment|/* Nonzero in FUNCTION_DECL means it is really an operator.    Just used to communicate formatting information to dbxout.c.  */
end_comment

begin_define
define|#
directive|define
name|DECL_OPERATOR
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.operator_attr)
end_define

begin_define
define|#
directive|define
name|ANON_UNION_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_NAME (NODE) == 0)
end_define

begin_comment
comment|/* Nonzero if TYPE is an anonymous union type.  We have to use a flag for    this because "A union for which objects or pointers are declared is not    an anonymous union" [class.union].  */
end_comment

begin_define
define|#
directive|define
name|ANON_UNION_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)				\&& TYPE_LANG_SPECIFIC (NODE)->type_flags.anon_union)
end_define

begin_define
define|#
directive|define
name|SET_ANON_UNION_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_LANG_SPECIFIC (NODE)->type_flags.anon_union = 1)
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* C++: A derived class may be able to directly use the virtual    function table of a base class.  When it does so, it may    still have a decl node used to access the virtual function    table (so that variables of this type can initialize their    virtual function table pointers by name).  When such thievery    is committed, know exactly which base class's virtual function    table is the one being stolen.  This effectively computes the    transitive closure.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VPARENT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.arguments)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TYPE_WAS_ANONYMOUS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_LANG_SPECIFIC (NODE)->type_flags.was_anonymous)
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.access)
end_define

begin_comment
comment|/* C++: all of these are overloaded!    These apply to PARM_DECLs and VAR_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|DECL_REFERENCE_SLOT
parameter_list|(
name|NODE
parameter_list|)
value|((tree)(NODE)->decl.arguments)
end_define

begin_define
define|#
directive|define
name|SET_DECL_REFERENCE_SLOT
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
value|((NODE)->decl.arguments=VAL)
end_define

begin_comment
comment|/* Accessor macros for C++ template decl nodes.  */
end_comment

begin_comment
comment|/* The DECL_TEMPLATE_PARMS are a list.  The TREE_PURPOSE of each node    is a INT_CST whose TREE_INT_CST_HIGH indicates the level of the    template parameters, with 1 being the outermost set of template    parameters.  The TREE_VALUE is a vector, whose elements are the    template parameters at each level.  Each element in the vector is a    TREE_LIST, whose TREE_VALUE is a PARM_DECL (if the parameter is a    non-type parameter), or a TYPE_DECL (if the parameter is a type    parameter).  The TREE_PURPOSE is the default value, if any.  The    TEMPLATE_PARM_INDEX for the parameter is avilable as the    DECL_INITIAL (for a PARM_DECL) or as the TREE_TYPE (for a    TYPE_DECL).  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_ARGUMENTS(NODE)
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
value|DECL_RESULT(NODE)
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
value|DECL_VINDEX(NODE)
end_define

begin_comment
comment|/* For a function template, the DECL_TEMPLATE_SPECIALIZATIONS lists    contains all instantiations and specializations of the function,    including partial instantiations.  For a partial instantiation    which is a specialization, this list holds only full    specializations of the template that are instantiations of the    partial instantiation.  For example, given:        template<class T> struct S {         template<class U> void f(U); 	template<> void f(T);        };     the `S<int>::f<int>(int)' function will appear on the    DECL_TEMPLATE_SPECIALIZATIONS list for both `template<class T>    template<class U> void S<T>::f(U)' and `template<class T> void    S<int>::f(T)'.  In the latter case, however, it will have only the    innermost set of arguments (T, in this case).  The DECL_TI_TEMPLATE    for the function declaration will point at the specialization, not    the fully general template.     For a class template, this list contains the partial    specializations of this template.  (Full specializations are not    recorded on this list.)  The TREE_PURPOSE holds the innermost    arguments used in the partial specialization (e.g., for `template<class T> struct S<T*, int>' this will be `T*'.)  The TREE_VALUE    holds the innermost template parameters for the specialization    (e.g., `T' in the example above.)  The TREE_TYPE is the _TYPE node    for the partial specialization.     This list is not used for static variable templates.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TEMPLATE_SPECIALIZATIONS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_SIZE(NODE)
end_define

begin_define
define|#
directive|define
name|DECL_TEMPLATE_INJECT
parameter_list|(
name|NODE
parameter_list|)
value|DECL_INITIAL(NODE)
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
value|DECL_LANG_FLAG_0 (NODE)
end_define

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
value|(DECL_PRIMARY_TEMPLATE (NODE) == NODE)
end_define

begin_define
define|#
directive|define
name|CLASSTYPE_TEMPLATE_LEVEL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_INT_CST_HIGH (TREE_PURPOSE (CLASSTYPE_TI_TEMPLATE (NODE))))
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
value|(DECL_LANG_SPECIFIC(NODE)->decl_flags.use_template)
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
value|(CLASSTYPE_USE_TEMPLATE(NODE) == 1)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_IMPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE(NODE) = 1)
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
value|(CLASSTYPE_USE_TEMPLATE(NODE) == 3)
end_define

begin_define
define|#
directive|define
name|SET_CLASSTYPE_EXPLICIT_INSTANTIATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CLASSTYPE_USE_TEMPLATE(NODE) = 3)
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
value|(TYPE_LANG_SPECIFIC (TYPE)->type_flags.is_partial_instantiation)
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
value|DECL_LANG_FLAG_1(NODE)
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
name|DECL_THIS_INLINE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_SPECIFIC (NODE)->decl_flags.declared_inline)
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

begin_define
define|#
directive|define
name|THUNK_DELTA
parameter_list|(
name|DECL
parameter_list|)
value|((DECL)->decl.frame_size.i)
end_define

begin_comment
comment|/* ...and for unexpanded-parameterized-type nodes.  */
end_comment

begin_define
define|#
directive|define
name|UPT_TEMPLATE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_PURPOSE(TYPE_VALUES(NODE))
end_define

begin_define
define|#
directive|define
name|UPT_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VALUE(TYPE_VALUES(NODE))
end_define

begin_comment
comment|/* An un-parsed default argument looks like an identifier.  */
end_comment

begin_define
define|#
directive|define
name|DEFARG_NODE_CHECK
parameter_list|(
name|t
parameter_list|)
value|TREE_CHECK(t, DEFAULT_ARG)
end_define

begin_define
define|#
directive|define
name|DEFARG_LENGTH
parameter_list|(
name|NODE
parameter_list|)
value|(DEFARG_NODE_CHECK(NODE)->identifier.length)
end_define

begin_define
define|#
directive|define
name|DEFARG_POINTER
parameter_list|(
name|NODE
parameter_list|)
value|(DEFARG_NODE_CHECK(NODE)->identifier.pointer)
end_define

begin_define
define|#
directive|define
name|builtin_function
parameter_list|(
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|CODE
parameter_list|,
name|LIBNAME
parameter_list|)
define|\
value|define_function (NAME, TYPE, CODE, (void (*) PROTO((tree)))pushdecl, LIBNAME)
end_define

begin_comment
comment|/* These macros provide convenient access to the various _STMT nodes    created when parsing template declarations.  */
end_comment

begin_define
define|#
directive|define
name|IF_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|THEN_CLAUSE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|ELSE_CLAUSE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 2)
end_define

begin_define
define|#
directive|define
name|WHILE_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|WHILE_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|DO_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|DO_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|RETURN_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|EXPR_STMT_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|FOR_INIT_STMT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|FOR_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|FOR_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 2)
end_define

begin_define
define|#
directive|define
name|FOR_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 3)
end_define

begin_define
define|#
directive|define
name|SWITCH_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|SWITCH_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|CASE_LOW
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|CASE_HIGH
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|GOTO_DESTINATION
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|TRY_STMTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|TRY_HANDLERS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|HANDLER_PARMS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|HANDLER_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|COMPOUND_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|ASM_CV_QUAL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|ASM_STRING
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 2)
end_define

begin_define
define|#
directive|define
name|ASM_INPUTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 3)
end_define

begin_define
define|#
directive|define
name|ASM_CLOBBERS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 4)
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
block|,
name|signature_type
block|}
enum|;
end_enum

begin_comment
comment|/* Zero means prototype weakly, as in ANSI C (no args means nothing).    Each language context defines how this variable should be set.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strict_prototype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strict_prototypes_lang_c
decl_stmt|,
name|strict_prototypes_lang_cplusplus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that if a label exists, and no other identifier    applies, use the value of the label.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_labels_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to collect statistics which might be expensive    and to print them when we are done.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_detailed_statistics
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
comment|/* Non-zero means warn if a non-templatized friend function is    declared in a templatized class. This behavior is warned about with    flag_guiding_decls in do_friend. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nontemplate_friend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in c-common.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|declare_function_name
name|PROTO
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
name|decl_attributes
name|PROTO
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
name|init_function_format_info
name|PROTO
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
name|record_function_format
name|PROTO
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
name|check_function_format
name|PROTO
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

begin_comment
comment|/* Print an error message for invalid operands to arith operation CODE.    NOP_EXPR is used as a special case (see truthvalue_conversion).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|binary_op_error
name|PROTO
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
name|cp_build_qualified_type
name|PROTO
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
name|canonical_type_variant
name|PROTO
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
name|c_expand_expr_stmt
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Validate the expression after `case' and apply default promotions.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|check_case_value
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Concatenate a list of STRING_CST nodes into one STRING_CST.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|combine_strings
name|PROTO
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
name|constant_expression_warning
name|PROTO
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
name|convert_and_check
name|PROTO
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
name|overflow_warning
name|PROTO
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
name|unsigned_conversion_warning
name|PROTO
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
name|c_apply_type_quals_to_decl
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read the rest of the current #-directive line.  */
end_comment

begin_if
if|#
directive|if
name|USE_CPPLIB
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_directive_line
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_DIRECTIVE_LINE
parameter_list|()
value|get_directive_line ()
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_directive_line
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_DIRECTIVE_LINE
parameter_list|()
value|get_directive_line (finput)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Subroutine of build_binary_op, used for comparison operations.    See if the operands have both been converted from subword integer types    and, if so, perhaps change them both back to their original type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|shorten_compare
name|PROTO
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|tree
operator|*
operator|,
name|tree
operator|*
operator|,
expr|enum
name|tree_code
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prepare expr to be an argument of a TRUTH_NOT_EXPR,    or validate its data type for an `if' or `while' statement or ?..: exp.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|truthvalue_conversion
name|PROTO
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
name|type_for_mode
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|type_for_size
name|PROTO
argument_list|(
operator|(
name|unsigned
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_get_alias_set
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in decl{2}.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|void_list_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|void_zero_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|default_function_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|vtable_entry_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|sigtable_entry_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|__t_desc_type_node
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern tree __tp_desc_type_node;
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|tree
name|__access_mode_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|__bltn_desc_type_node
decl_stmt|,
name|__user_desc_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|__class_desc_type_node
decl_stmt|,
name|__attr_desc_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|__ptr_desc_type_node
decl_stmt|,
name|__func_desc_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|__ptmf_desc_type_node
decl_stmt|,
name|__ptmd_desc_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|type_info_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|class_star_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|this_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ctor_identifier
decl_stmt|,
name|dtor_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|pfn_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|index_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|delta_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|delta2_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|pfn_or_delta2_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|tag_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|vt_off_identifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|in_charge_identifier
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A node that is a list (length 1) of error_mark_nodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|error_mark_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ptr_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|class_type_node
decl_stmt|,
name|record_type_node
decl_stmt|,
name|union_type_node
decl_stmt|,
name|enum_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|unknown_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|opaque_type_node
decl_stmt|,
name|signature_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|vlist_identifier
decl_stmt|,
name|vlist_type_node
decl_stmt|,
name|vlist_zero_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Node for "pointer to (virtual) function".    This may be distinct from ptr_type_node so gdb can distinguish them.  */
end_comment

begin_define
define|#
directive|define
name|vfunc_ptr_type_node
define|\
value|(flag_vtable_thunks ? vtable_entry_type : ptr_type_node)
end_define

begin_comment
comment|/* The type of a vtbl, i.e., an array of vtable entries.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|vtbl_type_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The type of a class vtbl pointer, i.e., a pointer to a vtable entry.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|vtbl_ptr_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|delta_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|std_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|long_long_integer_type_node
decl_stmt|,
name|long_long_unsigned_type_node
decl_stmt|;
end_decl_stmt

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
name|boolean_type_node
decl_stmt|,
name|boolean_true_node
decl_stmt|,
name|boolean_false_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|null_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|anonymous_namespace_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The FUNCTION_DECL for the default `::operator delete'.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|global_delete_fndecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in pt.c  */
end_comment

begin_comment
comment|/* These values are used for the `STRICT' parameter to type_unfication and    fn_type_unification.  Their meanings are described with the    documentation for fn_type_unification.  */
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

begin_decl_stmt
specifier|extern
name|tree
name|current_template_parms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|processing_template_decl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|last_tree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The template currently being instantiated, and where the instantiation    was triggered.  */
end_comment

begin_struct
struct|struct
name|tinst_level
block|{
name|tree
name|decl
decl_stmt|;
name|int
name|line
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|struct
name|tinst_level
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|minimal_parse_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|maybe_print_template_context
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in class.c */
end_comment

begin_comment
comment|/* When parsing a class definition, the access specifier most recently    given by the user, or, if no access specifier was given, the    default value appropriate for the kind of class (i.e., struct,    class, or union).  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_access_specifier
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_class_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_class_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_class_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|previous_class_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_class_ref
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_class_depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_lang_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|lang_name_cplusplus
decl_stmt|,
name|lang_name_c
decl_stmt|,
name|lang_name_java
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The low-water mark on the class-cache obstack.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|class_cache_firstobj
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
comment|/* in init.c  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|global_base_init_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|current_base_init_list
decl_stmt|,
name|current_member_init_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_just_assigned_this
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_parms_stored
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Here's where we control how name mangling takes place.  */
end_comment

begin_define
define|#
directive|define
name|OPERATOR_ASSIGN_FORMAT
value|"__a%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_FORMAT
value|"__%s"
end_define

begin_define
define|#
directive|define
name|OPERATOR_TYPENAME_FORMAT
value|"__op"
end_define

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
name|DESTRUCTOR_DECL_PREFIX
value|"_$_"
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
name|VTABLE_NAME_FORMAT
value|(flag_vtable_thunks ? "__vt_%s" : "_vt$%s")
end_define

begin_define
define|#
directive|define
name|VCTABLE_NAME
value|"__vc$"
end_define

begin_define
define|#
directive|define
name|VLIST_NAME_FORMAT
value|"__vl$%s"
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
name|VBASE_NAME
value|"_vb$"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_FORMAT
value|"_vb$%s"
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
name|DESTRUCTOR_DECL_PREFIX
value|"_._"
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
name|VTABLE_NAME_FORMAT
value|(flag_vtable_thunks ? "__vt_%s" : "_vt.%s")
end_define

begin_define
define|#
directive|define
name|VCTABLE_NAME
value|"__vc."
end_define

begin_define
define|#
directive|define
name|VLIST_NAME_FORMAT
value|"__vl.%s"
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
name|VBASE_NAME
value|"_vb."
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_FORMAT
value|"_vb.%s"
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
name|DESTRUCTOR_DECL_PREFIX
value|"__destr_"
end_define

begin_define
define|#
directive|define
name|DESTRUCTOR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), DESTRUCTOR_DECL_PREFIX, \ 	     sizeof (DESTRUCTOR_DECL_PREFIX) - 1))
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
name|VTABLE_NAME_FORMAT
value|(flag_vtable_thunks ? "__vt_%s" : "_vt_%s")
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
name|VCTABLE_NAME
value|"__vc_"
end_define

begin_define
define|#
directive|define
name|VLIST_NAME_FORMAT
value|"__vl_%s"
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
value|"_vptr_%s"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME
value|"__vb_"
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), VBASE_NAME, \ 	     sizeof (VBASE_NAME) - 1))
end_define

begin_define
define|#
directive|define
name|VBASE_NAME_FORMAT
value|"__vb_%s"
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

begin_define
define|#
directive|define
name|ANON_PARMNAME_FORMAT
value|"__%d"
end_define

begin_define
define|#
directive|define
name|ANON_PARMNAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == '_' \&& IDENTIFIER_POINTER (ID_NODE)[1] == '_' \&& IDENTIFIER_POINTER (ID_NODE)[2]<= '9')
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
name|DESTRUCTOR_NAME_FORMAT
value|"~%s"
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
name|VLIST_NAME
value|"__vlist"
end_define

begin_define
define|#
directive|define
name|VLIST1_NAME
value|"__vlist1"
end_define

begin_define
define|#
directive|define
name|VLIST_TYPE_NAME
value|"6_Vlist"
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
name|VTABLE_INDEX_NAME
value|"__index"
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
name|VTABLE_DELTA2_NAME
value|"__delta2"
end_define

begin_define
define|#
directive|define
name|SIGNATURE_FIELD_NAME
value|"__s_"
end_define

begin_define
define|#
directive|define
name|SIGNATURE_FIELD_NAME_FORMAT
value|"__s_%s"
end_define

begin_define
define|#
directive|define
name|SIGNATURE_OPTR_NAME
value|"__optr"
end_define

begin_define
define|#
directive|define
name|SIGNATURE_SPTR_NAME
value|"__sptr"
end_define

begin_define
define|#
directive|define
name|SIGNATURE_POINTER_NAME
value|"__sp_"
end_define

begin_define
define|#
directive|define
name|SIGNATURE_POINTER_NAME_FORMAT
value|"__%s%s%ssp_%s"
end_define

begin_define
define|#
directive|define
name|SIGNATURE_REFERENCE_NAME
value|"__sr_"
end_define

begin_define
define|#
directive|define
name|SIGNATURE_REFERENCE_NAME_FORMAT
value|"__%s%s%ssr_%s"
end_define

begin_define
define|#
directive|define
name|SIGTABLE_PTR_TYPE
value|"__sigtbl_ptr_type"
end_define

begin_define
define|#
directive|define
name|SIGTABLE_NAME_FORMAT
value|"__st_%s_%s"
end_define

begin_define
define|#
directive|define
name|SIGTABLE_NAME_FORMAT_LONG
value|"__st_%s_%s_%d"
end_define

begin_define
define|#
directive|define
name|SIGTABLE_TAG_NAME
value|"__tag"
end_define

begin_define
define|#
directive|define
name|SIGTABLE_VB_OFF_NAME
value|"__vb_off"
end_define

begin_define
define|#
directive|define
name|SIGTABLE_VT_OFF_NAME
value|"__vt_off"
end_define

begin_define
define|#
directive|define
name|EXCEPTION_CLEANUP_NAME
value|"exception cleanup"
end_define

begin_define
define|#
directive|define
name|THIS_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(strcmp(IDENTIFIER_POINTER (ID_NODE), "this") == 0)
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
name|DESTRUCTOR_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[1] == JOINER \&& IDENTIFIER_POINTER (ID_NODE)[2] == '_')
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
name|VBASE_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[1] == 'v' \&& IDENTIFIER_POINTER (ID_NODE)[2] == 'b' \&& IDENTIFIER_POINTER (ID_NODE)[3] == JOINER)
end_define

begin_define
define|#
directive|define
name|TEMP_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(!strncmp (IDENTIFIER_POINTER (ID_NODE), AUTO_TEMP_NAME, sizeof (AUTO_TEMP_NAME)-1))
end_define

begin_define
define|#
directive|define
name|VFIELD_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
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

begin_define
define|#
directive|define
name|ANON_PARMNAME_FORMAT
value|"_%d"
end_define

begin_define
define|#
directive|define
name|ANON_PARMNAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
value|(IDENTIFIER_POINTER (ID_NODE)[0] == '_' \&& IDENTIFIER_POINTER (ID_NODE)[1]<= '9')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NO_DOLLAR_IN_LABEL) || !defined(NO_DOT_IN_LABEL) */
end_comment

begin_comment
comment|/* Store the vbase pointer field name for type TYPE into pointer BUF.  */
end_comment

begin_define
define|#
directive|define
name|FORMAT_VBASE_NAME
parameter_list|(
name|BUF
parameter_list|,
name|TYPE
parameter_list|)
value|do { 				\   char *wbuf = (char *) alloca (TYPE_ASSEMBLER_NAME_LENGTH (TYPE)	\ 			 + sizeof (VBASE_NAME) + 1);			\   sprintf (wbuf, VBASE_NAME_FORMAT, TYPE_ASSEMBLER_NAME_STRING (TYPE));	\   (BUF) = wbuf;								\ } while (0)
end_define

begin_comment
comment|/* Returns non-zero iff ID_NODE is an IDENTIFIER_NODE whose name is    `main'.  */
end_comment

begin_define
define|#
directive|define
name|MAIN_NAME_P
parameter_list|(
name|ID_NODE
parameter_list|)
define|\
value|(strcmp (IDENTIFIER_POINTER (ID_NODE), "main") == 0)
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
value|(TREE_CODE (NODE) == FUNCTION_DECL			\&& DECL_LANGUAGE (NODE) == lang_c	 		\&& DECL_NAME (NODE) != NULL_TREE			\&& MAIN_NAME_P (DECL_NAME (NODE)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the sets of attributes that member functions and baseclasses    can have.  These are sensible combinations of {public,private,protected}    cross {virtual,non-virtual}.  */
end_comment

begin_comment
comment|/* in class.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|access_default_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|access_public_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|access_protected_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|access_private_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|access_default_virtual_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|access_public_virtual_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|access_protected_virtual_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 6 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|access_private_virtual_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 7 */
end_comment

begin_comment
comment|/* Things for handling inline functions.  */
end_comment

begin_struct
struct|struct
name|pending_inline
block|{
name|struct
name|pending_inline
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next in chain */
name|int
name|lineno
decl_stmt|;
comment|/* line number we got the text from */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* name of file we were processing */
name|tree
name|fndecl
decl_stmt|;
comment|/* FUNCTION_DECL that brought us here */
name|int
name|token
decl_stmt|;
comment|/* token we were scanning */
name|int
name|token_value
decl_stmt|;
comment|/* value of token we were scanning (YYSTYPE) */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* pointer to character stream */
name|int
name|len
decl_stmt|;
comment|/* length of stream */
name|unsigned
name|int
name|can_free
range|:
literal|1
decl_stmt|;
comment|/* free this after we're done with it? */
name|unsigned
name|int
name|deja_vu
range|:
literal|1
decl_stmt|;
comment|/* set iff we don't want to see it again.  */
name|unsigned
name|int
name|interface
range|:
literal|2
decl_stmt|;
comment|/* 0=interface 1=unknown 2=implementation */
block|}
struct|;
end_struct

begin_comment
comment|/* in method.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pending_inline
modifier|*
name|pending_inlines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Positive values means that we cannot make optimizing assumptions about    `this'.  Negative values means we know `this' to be of static type.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_this_is_variable
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
comment|/* Nonzero to enable experimental ABI changes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_new_abi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero to not ignore namespace std. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_honor_std
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
comment|/* The following two can be derived from the previous one */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_class_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IDENTIFIER_NODE: name of current class */
end_comment

begin_comment
comment|/* Some macros for char-based bitfields.  */
end_comment

begin_define
define|#
directive|define
name|B_SET
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3] |= (1<< (x&7)))
end_define

begin_define
define|#
directive|define
name|B_CLR
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3]&= ~(1<< (x&7)))
end_define

begin_define
define|#
directive|define
name|B_TST
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|(a[x>>3]& (1<< (x&7)))
end_define

begin_comment
comment|/* These are uses as bits in flags passed to build_method_call    to control its error reporting behavior.     LOOKUP_PROTECT means flag access violations.    LOOKUP_COMPLAIN mean complain if no suitable member function      matching the arguments is found.    LOOKUP_NORMAL is just a combination of these two.    LOOKUP_NONVIRTUAL means make a direct call to the member function found    LOOKUP_GLOBAL means search through the space of overloaded functions,      as well as the space of member functions.    LOOKUP_HAS_IN_CHARGE means that the "in charge" variable is already      in the parameter list.    LOOKUP_HAS_VLIST means that the "vlist" variable is already in       the parameter list.    LOOKUP_ONLYCONVERTING means that non-conversion constructors are not tried.    DIRECT_BIND means that if a temporary is created, it should be created so      that it lives as long as the current variable bindings; otherwise it      only lives until the end of the complete-expression.    LOOKUP_SPECULATIVELY means return NULL_TREE if we cannot find what we are      after.  Note, LOOKUP_COMPLAIN is checked and error messages printed      before LOOKUP_SPECULATIVELY is checked.    LOOKUP_NO_CONVERSION means that user-defined conversions are not      permitted.  Built-in conversions are permitted.    LOOKUP_DESTRUCTOR means explicit call to destructor.    LOOKUP_NO_TEMP_BIND means temporaries will not be bound to references.     These are used in global lookup to support elaborated types and    qualifiers.        LOOKUP_PREFER_TYPES means not to accept objects, and possibly namespaces.    LOOKUP_PREFER_NAMESPACES means not to accept objects, and possibly types.    LOOKUP_PREFER_BOTH means class-or-namespace-name.    LOOKUP_TEMPLATES_EXPECTED means that class templates also count      as types.  */
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

begin_comment
comment|/* #define LOOKUP_UNUSED (4) */
end_comment

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
name|LOOKUP_HAS_IN_CHARGE
value|(32)
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
name|LOOKUP_HAS_VLIST
value|(16384)
end_define

begin_define
define|#
directive|define
name|LOOKUP_NAMESPACES_ONLY
parameter_list|(
name|f
parameter_list|)
define|\
value|(((f)& LOOKUP_PREFER_NAMESPACES)&& !((f)& LOOKUP_PREFER_TYPES))
end_define

begin_define
define|#
directive|define
name|LOOKUP_TYPES_ONLY
parameter_list|(
name|f
parameter_list|)
define|\
value|(!((f)& LOOKUP_PREFER_NAMESPACES)&& ((f)& LOOKUP_PREFER_TYPES))
end_define

begin_define
define|#
directive|define
name|LOOKUP_QUALIFIERS_ONLY
parameter_list|(
name|f
parameter_list|)
value|((f)& LOOKUP_PREFER_BOTH)
end_define

begin_comment
comment|/* These flags are used by the conversion code.    CONV_IMPLICIT   :  Perform implicit conversions (standard and user-defined).    CONV_STATIC     :  Perform the explicit conversions for static_cast.    CONV_CONST      :  Perform the explicit conversions for const_cast.    CONV_REINTERPRET:  Perform the explicit conversions for reinterpret_cast.    CONV_PRIVATE    :  Perform upcasts to private bases.    CONV_FORCE_TEMP :  Require a new temporary when converting to the same    		      aggregate type.  */
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
comment|/* Returns nonzero iff TYPE1 and TYPE2 are the same type, in the usual    sense of `same'.  */
end_comment

begin_define
define|#
directive|define
name|same_type_p
parameter_list|(
name|type1
parameter_list|,
name|type2
parameter_list|)
define|\
value|comptypes ((type1), (type2), COMPARE_STRICT)
end_define

begin_comment
comment|/* Returns nonzero iff TYPE1 and TYPE2 are the same type, or if TYPE2    is derived from TYPE1, or if TYPE2 is a pointer (reference) to a    class derived from the type pointed to (referred to) by TYPE1.  */
end_comment

begin_define
define|#
directive|define
name|same_or_base_type_p
parameter_list|(
name|type1
parameter_list|,
name|type2
parameter_list|)
define|\
value|comptypes ((type1), (type2), COMPARE_BASE)
end_define

begin_comment
comment|/* These macros are used to access a TEMPLATE_PARM_INDEX.  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE_PARM_IDX
parameter_list|(
name|NODE
parameter_list|)
value|(((template_parm_index*) NODE)->index)
end_define

begin_define
define|#
directive|define
name|TEMPLATE_PARM_LEVEL
parameter_list|(
name|NODE
parameter_list|)
value|(((template_parm_index*) NODE)->level)
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
value|(((template_parm_index*) NODE)->orig_level)
end_define

begin_define
define|#
directive|define
name|TEMPLATE_PARM_DECL
parameter_list|(
name|NODE
parameter_list|)
value|(((template_parm_index*) NODE)->decl)
end_define

begin_comment
comment|/* These macros are for accessing the fields of TEMPLATE_TYPE_PARM     and TEMPLATE_TEMPLATE_PARM nodes.  */
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
comment|/* in lex.c  */
end_comment

begin_comment
comment|/* Indexed by TREE_CODE, these tables give C-looking names to    operators represented by TREE_CODES.  For example,    opname_tab[(int) MINUS_EXPR] == "-".  */
end_comment

begin_decl_stmt
specifier|extern
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

begin_escape
end_escape

begin_comment
comment|/* in call.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|check_dtor_name
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|resolve_scope_to_name
name|PROTO
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
name|PROTO
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
name|build_addr_func
name|PROTO
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
name|PROTO
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
name|build_method_call
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|build_op_new_call
name|PROTO
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
name|build_op_delete_call
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|convert_arg_to_ellipsis
name|PROTO
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
name|PROTO
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
name|build_vbase_path
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|*
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
name|add_method
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
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
name|int
name|currently_open_class
name|PROTO
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
name|get_vfield_offset
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|finish_struct_1
name|PROTO
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
name|resolves_to_fixed_type_p
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|print_class_statistics
name|PROTO
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
name|push_cache_obstack
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|HOST_WIDE_INT
name|skip_rtti_stuff
name|PROTO
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
name|void
name|build_self_reference
name|PROTO
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
name|warn_hidden
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* in cvt.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|convert_to_reference
name|PROTO
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
name|PROTO
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
name|convert_pointer_to_real
name|PROTO
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
name|convert_pointer_to
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|convert
name|PROTO
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
name|convert_force
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* decl.c */
end_comment

begin_comment
comment|/* resume_binding_level */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_identifier_local_value
name|PROTO
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
name|global_bindings_p
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|kept_level_p
name|PROTO
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
name|declare_parm_level
name|PROTO
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
name|declare_pseudo_global_level
name|PROTO
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
name|pseudo_global_level_p
name|PROTO
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
name|PROTO
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
name|pushlevel
name|PROTO
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
name|note_level_for_for
name|PROTO
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
name|pushlevel_temporary
name|PROTO
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
name|poplevel
name|PROTO
argument_list|(
operator|(
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
name|resume_level
name|PROTO
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
name|PROTO
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
name|insert_block
name|PROTO
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
name|PROTO
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
name|set_block
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|maybe_push_to_top_level
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|pushdecl
name|PROTO
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
name|pushdecl_top_level
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern void pushdecl_nonclass_level		PROTO((tree));
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|tree
name|pushdecl_namespace_level
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|lookup_label
name|PROTO
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
name|shadow_label
name|PROTO
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
name|PROTO
argument_list|(
operator|(
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
name|push_switch
name|PROTO
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
name|pop_switch
name|PROTO
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
name|define_case_label
name|PROTO
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
name|getdecls
name|PROTO
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
name|gettags
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern void set_current_level_tags_transparency	PROTO((int));
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|tree
name|binding_for_name
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|lookup_name_nonclass
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|lookup_using_namespace
name|PROTO
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
name|qualified_lookup_using_namespace
name|PROTO
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
name|auto_function
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
expr|enum
name|built_in_function
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_decl_processing
name|PROTO
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
name|init_type_desc
name|PROTO
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
name|define_function
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|tree
operator|,
expr|enum
name|built_in_function
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|tree
argument_list|)
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
name|check_tag_decl
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finish_decl
name|PROTO
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
name|expand_static_init
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|copy_args_p
name|PROTO
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
name|PROTO
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
name|PROTO
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

begin_decl_stmt
specifier|extern
name|tree
name|xref_tag
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|finish_enum
name|PROTO
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
name|build_enumerator
name|PROTO
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
name|PROTO
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
name|expand_start_early_try_stmts
name|PROTO
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
name|store_parm_decls
name|PROTO
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
name|store_return_init
name|PROTO
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
name|finish_function
name|PROTO
argument_list|(
operator|(
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
name|tree
name|start_method
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|maybe_build_cleanup_and_delete
name|PROTO
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
name|maybe_build_cleanup
name|PROTO
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
name|cplus_expand_expr_stmt
name|PROTO
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
name|PROTO
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
name|push_cp_function_context
name|PROTO
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
name|pop_cp_function_context
name|PROTO
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
name|in_function_p
name|PROTO
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
name|replace_defarg
name|PROTO
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
name|print_other_binding_stack
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|*
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
name|void
name|fixup_anonymous_union
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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

begin_comment
comment|/* in decl2.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|check_java_method
name|PROTO
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
name|lang_decode_option
name|PROTO
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
name|tree
name|grok_method_quals
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|grok_alignof
name|PROTO
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
name|grok_array_decl
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|copy_assignment_arg_p
name|PROTO
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
name|cplus_decl_attributes
name|PROTO
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
name|constructor_name_full
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|mark_inline_for_output
name|PROTO
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
name|clear_temp_name
name|PROTO
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
name|get_temp_name
name|PROTO
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
name|get_temp_regvar
name|PROTO
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
name|finish_anon_union
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|import_export_class
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|check_cp_case_value
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|lookup_arg_dependent
name|PROTO
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
name|PROTO
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in errfn.c */
end_comment

begin_comment
comment|/* The cp_* functions aren't suitable for ATTRIBUTE_PRINTF. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cp_error
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_error_at
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_warning
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
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
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_pedwarn
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
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
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_compiler_error
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_sprintf
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cp_deprecated
name|PROTO
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
comment|/* in error.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_error
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fndecl_as_string
name|PROTO
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
name|char
modifier|*
name|type_as_string
name|PROTO
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
name|char
modifier|*
name|type_as_string_real
name|PROTO
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|args_as_string
name|PROTO
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
name|char
modifier|*
name|decl_as_string
name|PROTO
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
name|char
modifier|*
name|expr_as_string
name|PROTO
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
name|char
modifier|*
name|code_as_string
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|language_as_string
name|PROTO
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
name|char
modifier|*
name|parm_as_string
name|PROTO
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
name|char
modifier|*
name|op_as_string
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|assop_as_string
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cv_as_string
name|PROTO
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
name|char
modifier|*
name|lang_decl_name
name|PROTO
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
name|char
modifier|*
name|cp_file_of
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
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
name|PROTO
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
name|expand_start_catch_block
name|PROTO
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
name|expand_end_catch_block
name|PROTO
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
name|PROTO
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
name|expand_start_eh_spec
name|PROTO
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
name|expand_exception_blocks
name|PROTO
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
name|start_anon_func
name|PROTO
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
name|end_anon_func
name|PROTO
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
name|expand_throw
name|PROTO
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
name|build_throw
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|void
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
name|PROTO
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
name|fixup_result_decl
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
expr|struct
name|rtx_def
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|extract_init
name|PROTO
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
name|do_case
name|PROTO
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
comment|/* friend.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|is_friend
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|add_friends
name|PROTO
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
name|do_friend
name|PROTO
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
name|PROTO
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
name|expand_direct_vtbls_init
name|PROTO
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
name|void
name|emit_base_init
name|PROTO
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
name|check_base_init
name|PROTO
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
name|expand_member_init
name|PROTO
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
name|expand_aggr_init
name|PROTO
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
name|is_aggr_typedef
name|PROTO
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
name|is_aggr_type
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|decl_constant_value
name|PROTO
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
name|PROTO
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
name|build_new_1
name|PROTO
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
name|expand_vec_init
name|PROTO
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
name|tree
name|build_x_delete
name|PROTO
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
name|PROTO
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_vbase_delete
name|PROTO
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
name|PROTO
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
name|tree
name|build_base_dtor_call
name|PROTO
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
name|init_vlist
name|PROTO
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
name|char
modifier|*
name|file_name_nondirectory
name|PROTO
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
name|tree
name|make_pointer_declarator
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|char
modifier|*
name|operator_name_string
name|PROTO
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
name|lang_init
name|PROTO
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
name|lang_finish
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern void reinit_lang_specific		PROTO((void));
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|reinit_parse_for_function
name|PROTO
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
name|print_parse_statistics
name|PROTO
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
name|extract_interface_info
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pending_input
modifier|*
name|save_pending_input
name|PROTO
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
name|restore_pending_input
name|PROTO
argument_list|(
operator|(
expr|struct
name|pending_input
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yyungetc
name|PROTO
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
name|reinit_parse_for_method
name|PROTO
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
name|void
name|reinit_parse_for_block
name|PROTO
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|cons_up_default_function
name|PROTO
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
name|check_for_missing_semicolon
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|identifier_type
name|PROTO
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
name|see_typename
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|real_yylex
name|PROTO
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
name|is_rid
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|build_lang_field_decl
name|PROTO
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
name|copy_lang_decl
name|PROTO
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
name|make_lang_type
name|PROTO
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
name|dump_time_statistics
name|PROTO
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
name|compiler_error
name|PVPROTO
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
name|PROTO
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
name|PROTO
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
name|maybe_snarf_defarg
name|PROTO
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
name|snarf_defarg
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|identifier_type
name|PROTO
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
name|yyhook
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
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
name|PROTO
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
name|do_inline_function_hair
name|PROTO
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
name|char
modifier|*
name|build_overload_name
name|PROTO
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

begin_decl_stmt
specifier|extern
name|tree
name|build_static_name
name|PROTO
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
name|build_decl_overload
name|PROTO
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
name|build_decl_overload_real
name|PROTO
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
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_mangled_name_for_decl
name|PROTO
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
name|build_typename_overload
name|PROTO
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
name|build_overload_with_type
name|PROTO
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
name|build_destructor_name
name|PROTO
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
name|build_opfncall
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|emit_thunk
name|PROTO
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
name|synthesize_method
name|PROTO
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
name|get_id_2
name|PROTO
argument_list|(
operator|(
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
name|get_vlist_vtable_id
name|PROTO
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
comment|/* in pt.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|check_template_shadow
name|PROTO
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
name|innermost_args
name|PROTO
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
name|tsubst
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|tree
name|lookup_template_function
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|overload_template_name
name|PROTO
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
name|fn_type_unification
name|PROTO
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tinst_level
modifier|*
name|tinst_for_decl
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|mark_class_instantiated
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|instantiate_decl
name|PROTO
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
name|do_poplevel
name|PROTO
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
name|get_bindings
name|PROTO
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

begin_comment
comment|/* CONT ... */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_tree
name|PROTO
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
name|begin_tree
name|PROTO
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
name|end_tree
name|PROTO
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
name|add_maybe_template
name|PROTO
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
name|pop_tinst_level
name|PROTO
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
name|PROTO
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
name|do_pushlevel
name|PROTO
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
name|is_member_template
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|print_candidates
name|PROTO
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
name|PROTO
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
name|processing_specialization
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|processing_explicit_instantiation
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|get_tinfo_fn_dynamic
name|PROTO
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
name|build_typeid
name|PROTO
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
name|build_x_typeid
name|PROTO
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
name|get_tinfo_fn
name|PROTO
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
name|get_tinfo_fn_unused
name|PROTO
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
name|PROTO
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
name|get_typeid_1
name|PROTO
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
name|PROTO
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
name|synthesize_tinfo_fn
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in search.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|types_overlap_p
name|PROTO
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
name|PROTO
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
name|get_binfo
name|PROTO
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
name|get_base_distance
name|PROTO
argument_list|(
operator|(
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
name|accessible_p
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|lookup_nested_tag
name|PROTO
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
name|get_matching_virtual
name|PROTO
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
name|get_abstract_virtuals
name|PROTO
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
name|init_vbase_pointers
name|PROTO
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
name|expand_indirect_vtbls_init
name|PROTO
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
name|clear_search_slots
name|PROTO
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
name|get_vbase_types
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|lookup_conversions
name|PROTO
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
name|PROTO
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
name|dfs_walk
name|PROTO
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
name|dfs_unmark
name|PROTO
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
name|PROTO
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

begin_comment
comment|/* in semantics.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|finish_expr_stmt
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|finish_return_stmt
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|finish_break_stmt
name|PROTO
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
name|finish_continue_stmt
name|PROTO
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
name|begin_switch_stmt
name|PROTO
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
name|finish_switch_cond
name|PROTO
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
name|finish_switch_stmt
name|PROTO
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
name|finish_case_label
name|PROTO
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
name|finish_goto_stmt
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|finish_handler_sequence
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|begin_compound_stmt
name|PROTO
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
name|PROTO
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
name|void
name|finish_asm_stmt
name|PROTO
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
name|finish_parenthesized_expr
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|finish_call_expr
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|finish_label_address_expr
name|PROTO
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
name|finish_unary_op_expr
name|PROTO
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
name|PROTO
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
name|begin_new_placement
name|PROTO
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
name|finish_new_placement
name|PROTO
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
name|begin_function_definition
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|finish_member_declaration
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in sig.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_signature_pointer_type
name|PROTO
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
name|build_signature_reference_type
name|PROTO
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
name|build_signature_pointer_constructor
name|PROTO
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
name|build_signature_method_call
name|PROTO
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
name|build_optr_ref
name|PROTO
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
name|append_signature_fields
name|PROTO
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
name|PROTO
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
name|peekyylex
name|PROTO
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
name|yylex
name|PROTO
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
name|PROTO
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

begin_comment
comment|/* in tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pod_type_p
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|real_lvalue_p
name|PROTO
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
name|PVPROTO
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
name|PVPROTO
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
name|min_tree_cons
name|PROTO
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
name|lvalue_p
name|PROTO
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
name|lvalue_or_else
name|PROTO
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
name|build_cplus_new
name|PROTO
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
name|PROTO
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
name|break_out_cleanups
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|layout_basetypes
name|PROTO
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
name|build_vbase_pointer_fields
name|PROTO
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
name|build_base_fields
name|PROTO
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
name|hash_tree_cons
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|binfo_value
name|PROTO
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
name|reverse_path
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|binding_init
name|PROTO
argument_list|(
operator|(
expr|struct
name|tree_binding
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bound_pmf_p
name|PROTO
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
name|PROTO
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
name|scratch_ovl_cons
name|PROTO
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
name|ovl_member
name|PROTO
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
name|PROTO
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
name|fnaddr_from_vtable_entry
name|PROTO
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
name|function_arg_chain
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|char
modifier|*
name|lang_printable_name
name|PROTO
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
name|PROTO
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
name|copy_template_template_parm
name|PROTO
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
name|copy_to_permanent
name|PROTO
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
name|permanent_p
name|PROTO
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
name|print_lang_statistics
name|PROTO
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
name|__eprintf
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|unsigned
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
name|array_type_nelts_total
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|hack_decl_function_context
name|PROTO
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
name|decl_namespace_context
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|make_temp_vec
name|PROTO
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
name|build_ptr_wrapper
name|PROTO
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
name|build_expr_ptr_wrapper
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|can_free
name|PROTO
argument_list|(
operator|(
expr|struct
name|obstack
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
name|mapcar
name|PROTO
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
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|no_linkage_check
name|PROTO
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
name|PROTO
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
name|push_expression_obstack
name|PROTO
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
name|build_dummy_object
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|search_tree
name|PROTO
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
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cp_valid_lang_attribute
name|PROTO
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
name|make_ptrmem_cst
name|PROTO
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
name|scratchalloc
value|expralloc
end_define

begin_define
define|#
directive|define
name|scratch_tree_cons
value|expr_tree_cons
end_define

begin_define
define|#
directive|define
name|build_scratch_list
value|build_expr_list
end_define

begin_define
define|#
directive|define
name|make_scratch_vec
value|make_temp_vec
end_define

begin_define
define|#
directive|define
name|push_scratch_obstack
value|push_expression_obstack
end_define

begin_comment
comment|/* in typeck.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|string_conv_p
name|PROTO
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
name|condition_conversion
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|require_complete_type_in_void
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|fntype_p
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|common_type
name|PROTO
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
name|compexcepttypes
name|PROTO
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
name|comptypes
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|comp_target_types
name|PROTO
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
name|comp_cv_qualification
name|PROTO
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
name|PROTO
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
name|self_promoting_args_p
name|PROTO
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
name|unsigned_type
name|PROTO
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
name|signed_type
name|PROTO
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
name|signed_or_unsigned_type
name|PROTO
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
name|expr_sizeof
name|PROTO
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
name|c_sizeof
name|PROTO
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
name|PROTO
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
name|c_alignof
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|default_conversion
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|build_function_call
name|PROTO
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
name|build_function_call_maybe
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|build_binary_op
name|PROTO
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
name|build_binary_op_nodefault
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|tree
operator|,
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
name|build_x_unary_op
name|PROTO
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
name|build_unary_op
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
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
name|unary_complex_lvalue
name|PROTO
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
name|int
name|mark_addressable
name|PROTO
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
name|build_x_conditional_expr
name|PROTO
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
name|build_conditional_expr
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|convert_for_initialization
name|PROTO
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
name|void
name|c_expand_asm_operands
name|PROTO
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
name|void
name|c_expand_return
name|PROTO
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
name|c_expand_start_case
name|PROTO
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
name|comp_ptr_ttypes
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|expand_ptrmemfunc_cst
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|*
operator|,
name|tree
operator|*
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
name|delta2_from_ptrmemfunc
name|PROTO
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
name|pfn_from_ptrmemfunc
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in typeck2.c */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|error_not_base_type
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|void
name|abstract_virtuals_error
name|PROTO
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
name|signature_error
name|PROTO
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
name|incomplete_type_error
name|PROTO
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
name|my_friendly_abort
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|my_friendly_assert
name|PROTO
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
name|tree
name|store_init_value
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|char
modifier|*
name|enum_name_string
name|PROTO
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
name|report_case_error
name|PROTO
argument_list|(
operator|(
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
name|void
name|check_for_new_type
name|PROTO
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
name|initializer_constant_valid_p
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* -- end of C++ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _CP_TREE_H */
end_comment

end_unit

