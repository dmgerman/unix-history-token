begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for C parsing and type checking.    Copyright (C) 1987, 1993, 1994, 1995, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_C_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_C_TREE_H
end_define

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_include
include|#
directive|include
file|"diagnostic.h"
end_include

begin_comment
comment|/* struct lang_identifier is private to c-decl.c, but langhooks.c needs to    know how big it is.  This is sanity-checked in c-decl.c.  */
end_comment

begin_define
define|#
directive|define
name|C_SIZEOF_STRUCT_LANG_IDENTIFIER
define|\
value|(sizeof (struct c_common_identifier) + 3 * sizeof (void *))
end_define

begin_comment
comment|/* Language-specific declaration information.  */
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
name|char
name|dummy
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
value|TREE_LANG_FLAG_1 (TYPE)
end_define

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is volatile.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_FIELDS_VOLATILE
parameter_list|(
name|TYPE
parameter_list|)
value|TREE_LANG_FLAG_2 (TYPE)
end_define

begin_comment
comment|/* In a RECORD_TYPE or UNION_TYPE or ENUMERAL_TYPE    nonzero if the definition of the type has already started.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_BEING_DEFINED
parameter_list|(
name|TYPE
parameter_list|)
value|TYPE_LANG_FLAG_0 (TYPE)
end_define

begin_comment
comment|/* In an incomplete RECORD_TYPE or UNION_TYPE, a list of variable    declarations whose type would be completed by completing that type.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_INCOMPLETE_VARS
parameter_list|(
name|TYPE
parameter_list|)
value|TYPE_VFIELD (TYPE)
end_define

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
value|TREE_LANG_FLAG_0 (ID)
end_define

begin_decl_stmt
name|struct
name|lang_type
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* In a RECORD_TYPE, a sorted array of the fields of the type.  */
name|struct
name|sorted_fields_type
modifier|*
name|GTY
argument_list|(
operator|(
name|reorder
argument_list|(
literal|"resort_sorted_fields"
argument_list|)
operator|)
argument_list|)
name|s
decl_stmt|;
comment|/* In an ENUMERAL_TYPE, the min and max values.  */
name|tree
name|enum_min
decl_stmt|;
name|tree
name|enum_max
decl_stmt|;
comment|/* In a RECORD_TYPE, information specific to Objective-C, such      as a list of adopted protocols or a pointer to a corresponding      @interface.  See objc/objc-act.h for details.  */
name|tree
name|objc_info
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Record whether a type or decl was written with nonconstant size.    Note that TYPE_SIZE may have simplified to a constant.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_VARIABLE_SIZE
parameter_list|(
name|TYPE
parameter_list|)
value|TYPE_LANG_FLAG_1 (TYPE)
end_define

begin_define
define|#
directive|define
name|C_DECL_VARIABLE_SIZE
parameter_list|(
name|TYPE
parameter_list|)
value|DECL_LANG_FLAG_0 (TYPE)
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
comment|/* For a FUNCTION_DECL, nonzero if it was defined without an explicit    return type.  */
end_comment

begin_define
define|#
directive|define
name|C_FUNCTION_IMPLICIT_INT
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_1 (EXP)
end_define

begin_comment
comment|/* For a FUNCTION_DECL, nonzero if it was an implicit declaration.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_IMPLICIT
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_2 (EXP)
end_define

begin_comment
comment|/* For FUNCTION_DECLs, evaluates true if the decl is built-in but has    been declared.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_DECLARED_BUILTIN
parameter_list|(
name|EXP
parameter_list|)
define|\
value|DECL_LANG_FLAG_3 (FUNCTION_DECL_CHECK (EXP))
end_define

begin_comment
comment|/* For FUNCTION_DECLs, evaluates true if the decl is built-in, has a    built-in prototype and does not have a non-built-in prototype.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_BUILTIN_PROTOTYPE
parameter_list|(
name|EXP
parameter_list|)
define|\
value|DECL_LANG_FLAG_6 (FUNCTION_DECL_CHECK (EXP))
end_define

begin_comment
comment|/* Record whether a decl was declared register.  This is strictly a    front-end flag, whereas DECL_REGISTER is used for code generation;    they may differ for structures with volatile fields.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_REGISTER
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_4 (EXP)
end_define

begin_comment
comment|/* Record whether a decl was used in an expression anywhere except an    unevaluated operand of sizeof / typeof / alignof.  This is only    used for functions declared static but not defined, though outside    sizeof and typeof it is set for other function decls as well.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_USED
parameter_list|(
name|EXP
parameter_list|)
value|DECL_LANG_FLAG_5 (FUNCTION_DECL_CHECK (EXP))
end_define

begin_comment
comment|/* Record whether a label was defined in a statement expression which    has finished and so can no longer be jumped to.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_UNJUMPABLE_STMT_EXPR
parameter_list|(
name|EXP
parameter_list|)
define|\
value|DECL_LANG_FLAG_6 (LABEL_DECL_CHECK (EXP))
end_define

begin_comment
comment|/* Record whether a label was the subject of a goto from outside the    current level of statement expression nesting and so cannot be    defined right now.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_UNDEFINABLE_STMT_EXPR
parameter_list|(
name|EXP
parameter_list|)
define|\
value|DECL_LANG_FLAG_7 (LABEL_DECL_CHECK (EXP))
end_define

begin_comment
comment|/* Record whether a label was defined in the scope of an identifier    with variably modified type which has finished and so can no longer    be jumped to.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_UNJUMPABLE_VM
parameter_list|(
name|EXP
parameter_list|)
define|\
value|DECL_LANG_FLAG_3 (LABEL_DECL_CHECK (EXP))
end_define

begin_comment
comment|/* Record whether a label was the subject of a goto from outside the    current level of scopes of identifiers with variably modified type    and so cannot be defined right now.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_UNDEFINABLE_VM
parameter_list|(
name|EXP
parameter_list|)
define|\
value|DECL_LANG_FLAG_5 (LABEL_DECL_CHECK (EXP))
end_define

begin_comment
comment|/* Record whether a variable has been declared threadprivate by    #pragma omp threadprivate.  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_THREADPRIVATE_P
parameter_list|(
name|DECL
parameter_list|)
value|DECL_LANG_FLAG_3 (VAR_DECL_CHECK (DECL))
end_define

begin_comment
comment|/* Nonzero for a decl which either doesn't exist or isn't a prototype.    N.B. Could be simplified if all built-in decls had complete prototypes    (but this is presently difficult because some of them need FILE*).  */
end_comment

begin_define
define|#
directive|define
name|C_DECL_ISNT_PROTOTYPE
parameter_list|(
name|EXP
parameter_list|)
define|\
value|(EXP == 0					\ 	|| (TYPE_ARG_TYPES (TREE_TYPE (EXP)) == 0	\&& !DECL_BUILT_IN (EXP)))
end_define

begin_comment
comment|/* For FUNCTION_TYPE, a hidden list of types of arguments.  The same as    TYPE_ARG_TYPES for functions with prototypes, but created for functions    without prototypes.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ACTUAL_ARG_TYPES
parameter_list|(
name|NODE
parameter_list|)
value|TYPE_LANG_SLOT_1 (NODE)
end_define

begin_comment
comment|/* Record parser information about an expression that is irrelevant    for code generation alongside a tree representing its value.  */
end_comment

begin_struct
struct|struct
name|c_expr
block|{
comment|/* The value of the expression.  */
name|tree
name|value
decl_stmt|;
comment|/* Record the original binary operator of an expression, which may      have been changed by fold, STRING_CST for unparenthesized string      constants, or ERROR_MARK for other expressions (including      parenthesized expressions).  */
name|enum
name|tree_code
name|original_code
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A kind of type specifier.  Note that this information is currently    only used to distinguish tag definitions, tag references and typeof    uses.  */
end_comment

begin_enum
enum|enum
name|c_typespec_kind
block|{
comment|/* A reserved keyword type specifier.  */
name|ctsk_resword
block|,
comment|/* A reference to a tag, previously declared, such as "struct foo".      This includes where the previous declaration was as a different      kind of tag, in which case this is only valid if shadowing that      tag in an inner scope.  */
name|ctsk_tagref
block|,
comment|/* A reference to a tag, not previously declared in a visible      scope.  */
name|ctsk_tagfirstref
block|,
comment|/* A definition of a tag such as "struct foo { int a; }".  */
name|ctsk_tagdef
block|,
comment|/* A typedef name.  */
name|ctsk_typedef
block|,
comment|/* An ObjC-specific kind of type specifier.  */
name|ctsk_objc
block|,
comment|/* A typeof specifier.  */
name|ctsk_typeof
block|}
enum|;
end_enum

begin_comment
comment|/* A type specifier: this structure is created in the parser and    passed to declspecs_add_type only.  */
end_comment

begin_struct
struct|struct
name|c_typespec
block|{
comment|/* What kind of type specifier this is.  */
name|enum
name|c_typespec_kind
name|kind
decl_stmt|;
comment|/* The specifier itself.  */
name|tree
name|spec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A storage class specifier.  */
end_comment

begin_enum
enum|enum
name|c_storage_class
block|{
name|csc_none
block|,
name|csc_auto
block|,
name|csc_extern
block|,
name|csc_register
block|,
name|csc_static
block|,
name|csc_typedef
block|}
enum|;
end_enum

begin_comment
comment|/* A type specifier keyword "void", "_Bool", "char", "int", "float",    "double", or none of these.  */
end_comment

begin_enum
enum|enum
name|c_typespec_keyword
block|{
name|cts_none
block|,
name|cts_void
block|,
name|cts_bool
block|,
name|cts_char
block|,
name|cts_int
block|,
name|cts_float
block|,
name|cts_double
block|,
name|cts_dfloat32
block|,
name|cts_dfloat64
block|,
name|cts_dfloat128
block|}
enum|;
end_enum

begin_comment
comment|/* A sequence of declaration specifiers in C.  */
end_comment

begin_struct
struct|struct
name|c_declspecs
block|{
comment|/* The type specified, if a single type specifier such as a struct,      union or enum specifier, typedef name or typeof specifies the      whole type, or NULL_TREE if none or a keyword such as "void" or      "char" is used.  Does not include qualifiers.  */
name|tree
name|type
decl_stmt|;
comment|/* The attributes from a typedef decl.  */
name|tree
name|decl_attr
decl_stmt|;
comment|/* When parsing, the attributes.  Outside the parser, this will be      NULL; attributes (possibly from multiple lists) will be passed      separately.  */
name|tree
name|attrs
decl_stmt|;
comment|/* Any type specifier keyword used such as "int", not reflecting      modifiers such as "short", or cts_none if none.  */
name|enum
name|c_typespec_keyword
name|typespec_word
decl_stmt|;
comment|/* The storage class specifier, or csc_none if none.  */
name|enum
name|c_storage_class
name|storage_class
decl_stmt|;
comment|/* Whether any declaration specifiers have been seen at all.  */
name|BOOL_BITFIELD
name|declspecs_seen_p
range|:
literal|1
decl_stmt|;
comment|/* Whether a type specifier has been seen.  */
name|BOOL_BITFIELD
name|type_seen_p
range|:
literal|1
decl_stmt|;
comment|/* Whether something other than a storage class specifier or      attribute has been seen.  This is used to warn for the      obsolescent usage of storage class specifiers other than at the      start of the list.  (Doing this properly would require function      specifiers to be handled separately from storage class      specifiers.)  */
name|BOOL_BITFIELD
name|non_sc_seen_p
range|:
literal|1
decl_stmt|;
comment|/* Whether the type is specified by a typedef or typeof name.  */
name|BOOL_BITFIELD
name|typedef_p
range|:
literal|1
decl_stmt|;
comment|/* Whether a struct, union or enum type either had its content      defined by a type specifier in the list or was the first visible      declaration of its tag.  */
name|BOOL_BITFIELD
name|tag_defined_p
range|:
literal|1
decl_stmt|;
comment|/* Whether the type is explicitly "signed" or specified by a typedef      whose type is explicitly "signed".  */
name|BOOL_BITFIELD
name|explicit_signed_p
range|:
literal|1
decl_stmt|;
comment|/* Whether the specifiers include a deprecated typedef.  */
name|BOOL_BITFIELD
name|deprecated_p
range|:
literal|1
decl_stmt|;
comment|/* APPLE LOCAL begin "unavailable" attribute (radar 2809697) */
comment|/* Whether the specifiers include a unavailable typedef.  */
name|BOOL_BITFIELD
name|unavailable_p
range|:
literal|1
decl_stmt|;
comment|/* APPLE LOCAL end "unavailable" attribute (radar 2809697) */
comment|/* Whether the type defaulted to "int" because there were no type      specifiers.  */
name|BOOL_BITFIELD
name|default_int_p
decl_stmt|;
comment|/* Whether "long" was specified.  */
name|BOOL_BITFIELD
name|long_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "long" was specified more than once.  */
name|BOOL_BITFIELD
name|long_long_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "short" was specified.  */
name|BOOL_BITFIELD
name|short_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "signed" was specified.  */
name|BOOL_BITFIELD
name|signed_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "unsigned" was specified.  */
name|BOOL_BITFIELD
name|unsigned_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "complex" was specified.  */
name|BOOL_BITFIELD
name|complex_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "inline" was specified.  */
name|BOOL_BITFIELD
name|inline_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "__thread" was specified.  */
name|BOOL_BITFIELD
name|thread_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "const" was specified.  */
name|BOOL_BITFIELD
name|const_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "volatile" was specified.  */
name|BOOL_BITFIELD
name|volatile_p
range|:
literal|1
decl_stmt|;
comment|/* Whether "restrict" was specified.  */
name|BOOL_BITFIELD
name|restrict_p
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The various kinds of declarators in C.  */
end_comment

begin_enum
enum|enum
name|c_declarator_kind
block|{
comment|/* An identifier.  */
name|cdk_id
block|,
comment|/* A function.  */
name|cdk_function
block|,
comment|/* An array.  */
name|cdk_array
block|,
comment|/* A pointer.  */
name|cdk_pointer
block|,
comment|/* Parenthesized declarator with nested attributes.  */
name|cdk_attrs
block|}
enum|;
end_enum

begin_comment
comment|/* Information about the parameters in a function declarator.  */
end_comment

begin_struct
struct|struct
name|c_arg_info
block|{
comment|/* A list of parameter decls.  */
name|tree
name|parms
decl_stmt|;
comment|/* A list of structure, union and enum tags defined.  */
name|tree
name|tags
decl_stmt|;
comment|/* A list of argument types to go in the FUNCTION_TYPE.  */
name|tree
name|types
decl_stmt|;
comment|/* A list of non-parameter decls (notably enumeration constants)      defined with the parameters.  */
name|tree
name|others
decl_stmt|;
comment|/* A list of VLA sizes from the parameters.  In a function      definition, these are used to ensure that side-effects in sizes      of arrays converted to pointers (such as a parameter int i[n++])      take place; otherwise, they are ignored.  */
name|tree
name|pending_sizes
decl_stmt|;
comment|/* True when these arguments had [*].  */
name|BOOL_BITFIELD
name|had_vla_unspec
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A declarator.  */
end_comment

begin_struct
struct|struct
name|c_declarator
block|{
comment|/* The kind of declarator.  */
name|enum
name|c_declarator_kind
name|kind
decl_stmt|;
comment|/* Except for cdk_id, the contained declarator.  For cdk_id, NULL.  */
name|struct
name|c_declarator
modifier|*
name|declarator
decl_stmt|;
name|location_t
name|id_loc
decl_stmt|;
comment|/* Currently only set for cdk_id. */
union|union
block|{
comment|/* For identifiers, an IDENTIFIER_NODE or NULL_TREE if an abstract        declarator.  */
name|tree
name|id
decl_stmt|;
comment|/* For functions.  */
name|struct
name|c_arg_info
modifier|*
name|arg_info
decl_stmt|;
comment|/* For arrays.  */
struct|struct
block|{
comment|/* The array dimension, or NULL for [] and [*].  */
name|tree
name|dimen
decl_stmt|;
comment|/* The qualifiers inside [].  */
name|int
name|quals
decl_stmt|;
comment|/* The attributes (currently ignored) inside [].  */
name|tree
name|attrs
decl_stmt|;
comment|/* Whether [static] was used.  */
name|BOOL_BITFIELD
name|static_p
range|:
literal|1
decl_stmt|;
comment|/* Whether [*] was used.  */
name|BOOL_BITFIELD
name|vla_unspec_p
range|:
literal|1
decl_stmt|;
block|}
name|array
struct|;
comment|/* For pointers, the qualifiers on the pointer type.  */
name|int
name|pointer_quals
decl_stmt|;
comment|/* For attributes.  */
name|tree
name|attrs
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* A type name.  */
end_comment

begin_struct
struct|struct
name|c_type_name
block|{
comment|/* The declaration specifiers.  */
name|struct
name|c_declspecs
modifier|*
name|specs
decl_stmt|;
comment|/* The declarator.  */
name|struct
name|c_declarator
modifier|*
name|declarator
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A parameter.  */
end_comment

begin_struct
struct|struct
name|c_parm
block|{
comment|/* The declaration specifiers, minus any prefix attributes.  */
name|struct
name|c_declspecs
modifier|*
name|specs
decl_stmt|;
comment|/* The attributes.  */
name|tree
name|attrs
decl_stmt|;
comment|/* The declarator.  */
name|struct
name|c_declarator
modifier|*
name|declarator
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Save and restore the variables in this file and elsewhere    that keep track of the progress of compilation of the current function.    Used for nested functions.  */
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
name|x_break_label
decl_stmt|;
name|tree
name|x_cont_label
decl_stmt|;
name|struct
name|c_switch
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|x_switch_stack
decl_stmt|;
name|struct
name|c_arg_info
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|arg_info
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
name|warn_about_return_type
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Save lists of labels used or defined in particular contexts.    Allocated on the parser obstack.  */
end_comment

begin_struct
struct|struct
name|c_label_list
block|{
comment|/* The label at the head of the list.  */
name|tree
name|label
decl_stmt|;
comment|/* The rest of the list.  */
name|struct
name|c_label_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Statement expression context.  */
end_comment

begin_struct
struct|struct
name|c_label_context_se
block|{
comment|/* The labels defined at this level of nesting.  */
name|struct
name|c_label_list
modifier|*
name|labels_def
decl_stmt|;
comment|/* The labels used at this level of nesting.  */
name|struct
name|c_label_list
modifier|*
name|labels_used
decl_stmt|;
comment|/* The next outermost context.  */
name|struct
name|c_label_context_se
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Context of variably modified declarations.  */
end_comment

begin_struct
struct|struct
name|c_label_context_vm
block|{
comment|/* The labels defined at this level of nesting.  */
name|struct
name|c_label_list
modifier|*
name|labels_def
decl_stmt|;
comment|/* The labels used at this level of nesting.  */
name|struct
name|c_label_list
modifier|*
name|labels_used
decl_stmt|;
comment|/* The scope of this context.  Multiple contexts may be at the same      numbered scope, since each variably modified declaration starts a      new context.  */
name|unsigned
name|scope
decl_stmt|;
comment|/* The next outermost context.  */
name|struct
name|c_label_context_vm
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* in c-parser.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_parse_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in c-aux-info.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|gen_aux_info_record
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in c-decl.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|obstack
name|parser_obstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_break_label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|c_cont_label
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|global_bindings_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_scope
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pop_scope
parameter_list|(
name|void
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
name|void
name|c_expand_body
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_init_decl_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_dup_lang_specific_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_print_identifier
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
name|int
name|quals_from_declspecs
parameter_list|(
specifier|const
name|struct
name|c_declspecs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declarator
modifier|*
name|build_array_declarator
parameter_list|(
name|tree
parameter_list|,
name|struct
name|c_declspecs
modifier|*
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
name|build_enumerator
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
name|check_for_loop_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_forward_parm_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|declare_parm_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|undeclared_variable
parameter_list|(
name|tree
parameter_list|,
name|location_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|declare_label
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
name|c_maybe_initialize_eh
parameter_list|(
name|void
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
name|tree
name|finish_enum
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
name|finish_function
parameter_list|(
name|void
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
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_arg_info
modifier|*
name|get_parm_info
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|grokfield
parameter_list|(
name|struct
name|c_declarator
modifier|*
parameter_list|,
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|groktypename
parameter_list|(
name|struct
name|c_type_name
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|grokparm
parameter_list|(
specifier|const
name|struct
name|c_parm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|implicitly_declare
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|keep_next_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pending_xref_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_push_function_context
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
name|c_pop_function_context
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
name|push_parm_decl
parameter_list|(
specifier|const
name|struct
name|c_parm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declarator
modifier|*
name|set_array_declarator_inner
parameter_list|(
name|struct
name|c_declarator
modifier|*
parameter_list|,
name|struct
name|c_declarator
modifier|*
parameter_list|,
name|bool
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
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|enum
name|built_in_class
parameter_list|,
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
name|void
name|shadow_tag
parameter_list|(
specifier|const
name|struct
name|c_declspecs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|shadow_tag_warned
parameter_list|(
specifier|const
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|int
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
name|int
name|start_function
parameter_list|(
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|struct
name|c_declarator
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_decl
parameter_list|(
name|struct
name|c_declarator
modifier|*
parameter_list|,
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|start_struct
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
name|void
name|store_parm_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|store_parm_decls_from
parameter_list|(
name|struct
name|c_arg_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|xref_tag
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
name|struct
name|c_typespec
name|parser_xref_tag
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
name|int
name|c_expand_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_parm
modifier|*
name|build_c_parm
parameter_list|(
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|struct
name|c_declarator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declarator
modifier|*
name|build_attrs_declarator
parameter_list|(
name|tree
parameter_list|,
name|struct
name|c_declarator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declarator
modifier|*
name|build_function_declarator
parameter_list|(
name|struct
name|c_arg_info
modifier|*
parameter_list|,
name|struct
name|c_declarator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declarator
modifier|*
name|build_id_declarator
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declarator
modifier|*
name|make_pointer_declarator
parameter_list|(
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|struct
name|c_declarator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declspecs
modifier|*
name|build_null_declspecs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declspecs
modifier|*
name|declspecs_add_qual
parameter_list|(
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declspecs
modifier|*
name|declspecs_add_type
parameter_list|(
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|struct
name|c_typespec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declspecs
modifier|*
name|declspecs_add_scspec
parameter_list|(
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declspecs
modifier|*
name|declspecs_add_attrs
parameter_list|(
name|struct
name|c_declspecs
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_declspecs
modifier|*
name|finish_declspecs
parameter_list|(
name|struct
name|c_declspecs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in c-objc-common.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|c_disregard_inline_limits
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_cannot_inline_tree_fn
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_objc_common_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_missing_noreturn_ok_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_objc_common_truthvalue_conversion
parameter_list|(
name|tree
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_warn_unused_global_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_initialize_diagnostics
parameter_list|(
name|diagnostic_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_vla_unspec_p
parameter_list|(
name|tree
name|x
parameter_list|,
name|tree
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|c_build_type_variant
parameter_list|(
name|TYPE
parameter_list|,
name|CONST_P
parameter_list|,
name|VOLATILE_P
parameter_list|)
define|\
value|c_build_qualified_type ((TYPE),				  \ 			  ((CONST_P) ? TYPE_QUAL_CONST : 0) |	  \ 			  ((VOLATILE_P) ? TYPE_QUAL_VOLATILE : 0))
end_define

begin_comment
comment|/* in c-typeck.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in_alignof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_sizeof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_typeof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|c_switch
modifier|*
name|c_switch_stack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|c_label_context_se
modifier|*
name|label_context_stack_se
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|c_label_context_vm
modifier|*
name|label_context_stack_vm
decl_stmt|;
end_decl_stmt

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
name|int
name|same_translation_unit_p
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
name|comptypes
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
name|c_vla_type_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_mark_addressable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_incomplete_type_error
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
name|c_type_promotes_to
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_expr
name|default_function_array_conversion
parameter_list|(
name|struct
name|c_expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|composite_type
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
name|build_component_ref
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
name|build_external_ref
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|location_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_maybe_used
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_expr
name|c_expr_sizeof_expr
parameter_list|(
name|struct
name|c_expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_expr
name|c_expr_sizeof_type
parameter_list|(
name|struct
name|c_type_name
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_expr
name|parser_build_unary_op
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|struct
name|c_expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_expr
name|parser_build_binary_op
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|struct
name|c_expr
parameter_list|,
name|struct
name|c_expr
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
name|c_cast_expr
parameter_list|(
name|struct
name|c_type_name
modifier|*
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
name|void
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
name|void
name|error_init
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
name|pedwarn_init
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
name|maybe_warn_string_init
parameter_list|(
name|tree
parameter_list|,
name|struct
name|c_expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_init
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
name|finish_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|really_start_incremental_init
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_init_level
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|c_expr
name|pop_init_level
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_init_index
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
name|set_init_label
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process_init_element
parameter_list|(
name|struct
name|c_expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_compound_literal
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
name|c_start_case
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_finish_case
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_asm_expr
parameter_list|(
name|tree
parameter_list|,
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
name|build_asm_stmt
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
name|c_convert_parm_for_inlining
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
name|int
name|c_types_compatible_p
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
name|c_begin_compound_stmt
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_end_compound_stmt
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
name|c_finish_if_stmt
parameter_list|(
name|location_t
parameter_list|,
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

begin_comment
comment|/* APPLE LOCAL begin for-fsf-4_4 3274130 5295549 */
end_comment

begin_function_decl
unit|\
specifier|extern
name|void
name|c_finish_loop
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
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL end for-fsf-4_4 3274130 5295549 */
end_comment

begin_function_decl
unit|\
specifier|extern
name|tree
name|c_begin_stmt_expr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_stmt_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_process_expr_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_expr_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_return
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_bc_stmt
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_goto_label
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_goto_ptr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_begin_vm_scope
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_end_vm_scope
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_expr_to_decl
parameter_list|(
name|tree
parameter_list|,
name|bool
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_begin_omp_parallel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_omp_parallel
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
name|c_finish_omp_clauses
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a return statement that specifies a return value is seen.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a return statement with no argument is seen.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to 0 at beginning of a function definition, set to 1 if    a call to a noreturn function is seen.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_abnormally
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we are reading code that came from a system header file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|system_header_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True means global_bindings_p should return false even if the scope stack    says we are in file scope.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|c_override_global_bindings_to_false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True means we've initialized exception handling.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|c_eh_initialized_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In c-decl.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_finish_incomplete_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_write_global_declarations
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In order for the format checking to accept the C frontend    diagnostic framework extensions, you must include this file before    toplev.h, not after.  */
end_comment

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
name|ATTRIBUTE_GCC_CDIAG
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|__attribute__ ((__format__ (GCC_DIAG_STYLE, m ,n))) ATTRIBUTE_NONNULL(m)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_GCC_CDIAG
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
name|pedwarn_c90
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTRIBUTE_GCC_CDIAG
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|pedwarn_c99
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTRIBUTE_GCC_CDIAG
parameter_list|(
function_decl|1
operator|,
function_decl|2
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
comment|/* ! GCC_C_TREE_H */
end_comment

end_unit

