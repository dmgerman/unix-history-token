begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for c-common.c.    Copyright (C) 1987, 1993, 1994, 1995, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_C_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_C_COMMON_H
end_define

begin_include
include|#
directive|include
file|"splay-tree.h"
end_include

begin_include
include|#
directive|include
file|"cpplib.h"
end_include

begin_include
include|#
directive|include
file|"ggc.h"
end_include

begin_comment
comment|/* Usage of TREE_LANG_FLAG_?:    0: COMPOUND_STMT_NO_SCOPE (in COMPOUND_STMT).       TREE_NEGATED_INT (in INTEGER_CST).       IDENTIFIER_MARKED (used by search routines).       SCOPE_BEGIN_P (in SCOPE_STMT)       DECL_PRETTY_FUNCTION_P (in VAR_DECL)       NEW_FOR_SCOPE_P (in FOR_STMT)       ASM_INPUT_P (in ASM_STMT)       STMT_EXPR_NO_SCOPE (in STMT_EXPR)    1: C_DECLARED_LABEL_FLAG (in LABEL_DECL)       STMT_IS_FULL_EXPR_P (in _STMT)    2: STMT_LINENO_FOR_FN_P (in _STMT)    3: SCOPE_NO_CLEANUPS_P (in SCOPE_STMT)       COMPOUND_STMT_BODY_BLOCK (in COMPOUND_STMT)       STMT_EXPR_WARN_UNUSED_RESULT (in STMT_EXPR)    4: SCOPE_PARTIAL_P (in SCOPE_STMT) */
end_comment

begin_comment
comment|/* Reserved identifiers.  This is the union of all the keywords for C,    C++, and Objective-C.  All the type modifiers have to be in one    block at the beginning, because they are used as mask bits.  There    are 27 type modifiers; if we add many more we will have to redesign    the mask mechanism.  */
end_comment

begin_enum
enum|enum
name|rid
block|{
comment|/* Modifiers: */
comment|/* C, in empirical order of frequency.  */
name|RID_STATIC
init|=
literal|0
block|,
name|RID_UNSIGNED
block|,
name|RID_LONG
block|,
name|RID_CONST
block|,
name|RID_EXTERN
block|,
name|RID_REGISTER
block|,
name|RID_TYPEDEF
block|,
name|RID_SHORT
block|,
name|RID_INLINE
block|,
name|RID_VOLATILE
block|,
name|RID_SIGNED
block|,
name|RID_AUTO
block|,
name|RID_RESTRICT
block|,
comment|/* C extensions */
name|RID_COMPLEX
block|,
name|RID_THREAD
block|,
comment|/* C++ */
name|RID_FRIEND
block|,
name|RID_VIRTUAL
block|,
name|RID_EXPLICIT
block|,
name|RID_EXPORT
block|,
name|RID_MUTABLE
block|,
comment|/* ObjC */
name|RID_IN
block|,
name|RID_OUT
block|,
name|RID_INOUT
block|,
name|RID_BYCOPY
block|,
name|RID_BYREF
block|,
name|RID_ONEWAY
block|,
comment|/* C */
name|RID_INT
block|,
name|RID_CHAR
block|,
name|RID_FLOAT
block|,
name|RID_DOUBLE
block|,
name|RID_VOID
block|,
name|RID_ENUM
block|,
name|RID_STRUCT
block|,
name|RID_UNION
block|,
name|RID_IF
block|,
name|RID_ELSE
block|,
name|RID_WHILE
block|,
name|RID_DO
block|,
name|RID_FOR
block|,
name|RID_SWITCH
block|,
name|RID_CASE
block|,
name|RID_DEFAULT
block|,
name|RID_BREAK
block|,
name|RID_CONTINUE
block|,
name|RID_RETURN
block|,
name|RID_GOTO
block|,
name|RID_SIZEOF
block|,
comment|/* C extensions */
name|RID_ASM
block|,
name|RID_TYPEOF
block|,
name|RID_ALIGNOF
block|,
name|RID_ATTRIBUTE
block|,
name|RID_VA_ARG
block|,
name|RID_EXTENSION
block|,
name|RID_IMAGPART
block|,
name|RID_REALPART
block|,
name|RID_LABEL
block|,
name|RID_PTRBASE
block|,
name|RID_PTREXTENT
block|,
name|RID_PTRVALUE
block|,
name|RID_CHOOSE_EXPR
block|,
name|RID_TYPES_COMPATIBLE_P
block|,
comment|/* Too many ways of getting the name of a function as a string */
name|RID_FUNCTION_NAME
block|,
name|RID_PRETTY_FUNCTION_NAME
block|,
name|RID_C99_FUNCTION_NAME
block|,
comment|/* C++ */
name|RID_BOOL
block|,
name|RID_WCHAR
block|,
name|RID_CLASS
block|,
name|RID_PUBLIC
block|,
name|RID_PRIVATE
block|,
name|RID_PROTECTED
block|,
name|RID_TEMPLATE
block|,
name|RID_NULL
block|,
name|RID_CATCH
block|,
name|RID_DELETE
block|,
name|RID_FALSE
block|,
name|RID_NAMESPACE
block|,
name|RID_NEW
block|,
name|RID_OFFSETOF
block|,
name|RID_OPERATOR
block|,
name|RID_THIS
block|,
name|RID_THROW
block|,
name|RID_TRUE
block|,
name|RID_TRY
block|,
name|RID_TYPENAME
block|,
name|RID_TYPEID
block|,
name|RID_USING
block|,
comment|/* casts */
name|RID_CONSTCAST
block|,
name|RID_DYNCAST
block|,
name|RID_REINTCAST
block|,
name|RID_STATCAST
block|,
comment|/* Objective-C */
name|RID_ID
block|,
name|RID_AT_ENCODE
block|,
name|RID_AT_END
block|,
name|RID_AT_CLASS
block|,
name|RID_AT_ALIAS
block|,
name|RID_AT_DEFS
block|,
name|RID_AT_PRIVATE
block|,
name|RID_AT_PROTECTED
block|,
name|RID_AT_PUBLIC
block|,
name|RID_AT_PROTOCOL
block|,
name|RID_AT_SELECTOR
block|,
name|RID_AT_THROW
block|,
name|RID_AT_TRY
block|,
name|RID_AT_CATCH
block|,
name|RID_AT_FINALLY
block|,
name|RID_AT_SYNCHRONIZED
block|,
name|RID_AT_INTERFACE
block|,
name|RID_AT_IMPLEMENTATION
block|,
name|RID_MAX
block|,
name|RID_FIRST_MODIFIER
init|=
name|RID_STATIC
block|,
name|RID_LAST_MODIFIER
init|=
name|RID_ONEWAY
block|,
name|RID_FIRST_AT
init|=
name|RID_AT_ENCODE
block|,
name|RID_LAST_AT
init|=
name|RID_AT_IMPLEMENTATION
block|,
name|RID_FIRST_PQ
init|=
name|RID_IN
block|,
name|RID_LAST_PQ
init|=
name|RID_ONEWAY
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|OBJC_IS_AT_KEYWORD
parameter_list|(
name|rid
parameter_list|)
define|\
value|((unsigned int)(rid)>= (unsigned int)RID_FIRST_AT&& \    (unsigned int)(rid)<= (unsigned int)RID_LAST_AT)
end_define

begin_define
define|#
directive|define
name|OBJC_IS_PQ_KEYWORD
parameter_list|(
name|rid
parameter_list|)
define|\
value|((unsigned int)(rid)>= (unsigned int)RID_FIRST_PQ&& \    (unsigned int)(rid)<= (unsigned int)RID_LAST_PQ)
end_define

begin_comment
comment|/* The elements of `ridpointers' are identifier nodes for the reserved    type names and storage classes.  It is indexed by a RID_... value.  */
end_comment

begin_extern
extern|extern GTY ((length (
literal|"(int)RID_MAX"
end_extern

begin_decl_stmt
unit|)))
name|tree
modifier|*
name|ridpointers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard named or nameless data types of the C compiler.  */
end_comment

begin_enum
enum|enum
name|c_tree_index
block|{
name|CTI_WCHAR_TYPE
block|,
name|CTI_SIGNED_WCHAR_TYPE
block|,
name|CTI_UNSIGNED_WCHAR_TYPE
block|,
name|CTI_WINT_TYPE
block|,
name|CTI_SIGNED_SIZE_TYPE
block|,
comment|/* For format checking only.  */
name|CTI_UNSIGNED_PTRDIFF_TYPE
block|,
comment|/* For format checking only.  */
name|CTI_INTMAX_TYPE
block|,
name|CTI_UINTMAX_TYPE
block|,
name|CTI_WIDEST_INT_LIT_TYPE
block|,
name|CTI_WIDEST_UINT_LIT_TYPE
block|,
name|CTI_CHAR_ARRAY_TYPE
block|,
name|CTI_WCHAR_ARRAY_TYPE
block|,
name|CTI_INT_ARRAY_TYPE
block|,
name|CTI_STRING_TYPE
block|,
name|CTI_CONST_STRING_TYPE
block|,
comment|/* Type for boolean expressions (bool in C++, int in C).  */
name|CTI_TRUTHVALUE_TYPE
block|,
name|CTI_TRUTHVALUE_TRUE
block|,
name|CTI_TRUTHVALUE_FALSE
block|,
name|CTI_DEFAULT_FUNCTION_TYPE
block|,
name|CTI_G77_INTEGER_TYPE
block|,
name|CTI_G77_UINTEGER_TYPE
block|,
name|CTI_G77_LONGINT_TYPE
block|,
name|CTI_G77_ULONGINT_TYPE
block|,
comment|/* These are not types, but we have to look them up all the time.  */
name|CTI_FUNCTION_NAME_DECL
block|,
name|CTI_PRETTY_FUNCTION_NAME_DECL
block|,
name|CTI_C99_FUNCTION_NAME_DECL
block|,
name|CTI_SAVED_FUNCTION_NAME_DECLS
block|,
name|CTI_VOID_ZERO
block|,
name|CTI_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|C_RID_CODE
parameter_list|(
name|id
parameter_list|)
value|(((struct c_common_identifier *) (id))->node.rid_code)
end_define

begin_comment
comment|/* Identifier part common to the C front ends.  Inherits from    tree_identifier, despite appearances.  */
end_comment

begin_decl_stmt
name|struct
name|c_common_identifier
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
name|cpp_hashnode
name|node
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|wchar_type_node
value|c_global_trees[CTI_WCHAR_TYPE]
end_define

begin_define
define|#
directive|define
name|signed_wchar_type_node
value|c_global_trees[CTI_SIGNED_WCHAR_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_wchar_type_node
value|c_global_trees[CTI_UNSIGNED_WCHAR_TYPE]
end_define

begin_define
define|#
directive|define
name|wint_type_node
value|c_global_trees[CTI_WINT_TYPE]
end_define

begin_define
define|#
directive|define
name|signed_size_type_node
value|c_global_trees[CTI_SIGNED_SIZE_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_ptrdiff_type_node
value|c_global_trees[CTI_UNSIGNED_PTRDIFF_TYPE]
end_define

begin_define
define|#
directive|define
name|intmax_type_node
value|c_global_trees[CTI_INTMAX_TYPE]
end_define

begin_define
define|#
directive|define
name|uintmax_type_node
value|c_global_trees[CTI_UINTMAX_TYPE]
end_define

begin_define
define|#
directive|define
name|widest_integer_literal_type_node
value|c_global_trees[CTI_WIDEST_INT_LIT_TYPE]
end_define

begin_define
define|#
directive|define
name|widest_unsigned_literal_type_node
value|c_global_trees[CTI_WIDEST_UINT_LIT_TYPE]
end_define

begin_define
define|#
directive|define
name|truthvalue_type_node
value|c_global_trees[CTI_TRUTHVALUE_TYPE]
end_define

begin_define
define|#
directive|define
name|truthvalue_true_node
value|c_global_trees[CTI_TRUTHVALUE_TRUE]
end_define

begin_define
define|#
directive|define
name|truthvalue_false_node
value|c_global_trees[CTI_TRUTHVALUE_FALSE]
end_define

begin_define
define|#
directive|define
name|char_array_type_node
value|c_global_trees[CTI_CHAR_ARRAY_TYPE]
end_define

begin_define
define|#
directive|define
name|wchar_array_type_node
value|c_global_trees[CTI_WCHAR_ARRAY_TYPE]
end_define

begin_define
define|#
directive|define
name|int_array_type_node
value|c_global_trees[CTI_INT_ARRAY_TYPE]
end_define

begin_define
define|#
directive|define
name|string_type_node
value|c_global_trees[CTI_STRING_TYPE]
end_define

begin_define
define|#
directive|define
name|const_string_type_node
value|c_global_trees[CTI_CONST_STRING_TYPE]
end_define

begin_define
define|#
directive|define
name|default_function_type
value|c_global_trees[CTI_DEFAULT_FUNCTION_TYPE]
end_define

begin_comment
comment|/* g77 integer types, which which must be kept in sync with f/com.h */
end_comment

begin_define
define|#
directive|define
name|g77_integer_type_node
value|c_global_trees[CTI_G77_INTEGER_TYPE]
end_define

begin_define
define|#
directive|define
name|g77_uinteger_type_node
value|c_global_trees[CTI_G77_UINTEGER_TYPE]
end_define

begin_define
define|#
directive|define
name|g77_longint_type_node
value|c_global_trees[CTI_G77_LONGINT_TYPE]
end_define

begin_define
define|#
directive|define
name|g77_ulongint_type_node
value|c_global_trees[CTI_G77_ULONGINT_TYPE]
end_define

begin_define
define|#
directive|define
name|function_name_decl_node
value|c_global_trees[CTI_FUNCTION_NAME_DECL]
end_define

begin_define
define|#
directive|define
name|pretty_function_name_decl_node
value|c_global_trees[CTI_PRETTY_FUNCTION_NAME_DECL]
end_define

begin_define
define|#
directive|define
name|c99_function_name_decl_node
value|c_global_trees[CTI_C99_FUNCTION_NAME_DECL]
end_define

begin_define
define|#
directive|define
name|saved_function_name_decls
value|c_global_trees[CTI_SAVED_FUNCTION_NAME_DECLS]
end_define

begin_comment
comment|/* A node for `((void) 0)'.  */
end_comment

begin_define
define|#
directive|define
name|void_zero_node
value|c_global_trees[CTI_VOID_ZERO]
end_define

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|c_global_trees
index|[
name|CTI_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In a RECORD_TYPE, a sorted array of the fields of the type, not a    tree for size reasons.  */
end_comment

begin_decl_stmt
name|struct
name|sorted_fields_type
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|int
name|len
decl_stmt|;
name|tree
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%h.len"
argument_list|)
operator|)
argument_list|)
name|elts
index|[
literal|1
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
comment|/* Flag strings given by __FUNCTION__ and __PRETTY_FUNCTION__ for a    warning if they undergo concatenation.  */
end_comment

begin_define
define|#
directive|define
name|C_ARTIFICIAL_STRING_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
end_define

begin_typedef
typedef|typedef
enum|enum
name|c_language_kind
block|{
name|clk_c
init|=
literal|0
block|,
comment|/* C90, C94 or C99 */
name|clk_objc
init|=
literal|1
block|,
comment|/* clk_c with ObjC features.  */
name|clk_cxx
init|=
literal|2
block|,
comment|/* ANSI/ISO C++ */
name|clk_objcxx
init|=
literal|3
comment|/* clk_cxx with ObjC features.  */
block|}
name|c_language_kind
typedef|;
end_typedef

begin_comment
comment|/* To test for a specific language use c_language, defined by each    front end.  For "ObjC features" or "not C++" use the macros.  */
end_comment

begin_decl_stmt
specifier|extern
name|c_language_kind
name|c_language
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|c_dialect_cxx
parameter_list|()
value|(c_language& clk_cxx)
end_define

begin_define
define|#
directive|define
name|c_dialect_objc
parameter_list|()
value|(c_language& clk_objc)
end_define

begin_comment
comment|/* Information about a statement tree.  */
end_comment

begin_decl_stmt
name|struct
name|stmt_tree_s
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The last statement added to the tree.  */
name|tree
name|x_last_stmt
decl_stmt|;
comment|/* The type of the last expression statement.  (This information is      needed to implement the statement-expression extension.)  */
name|tree
name|x_last_expr_type
decl_stmt|;
comment|/* The last filename we recorded.  */
specifier|const
name|char
modifier|*
name|x_last_expr_filename
decl_stmt|;
comment|/* In C++, Nonzero if we should treat statements as full      expressions.  In particular, this variable is no-zero if at the      end of a statement we should destroy any temporaries created      during that statement.  Similarly, if, at the end of a block, we      should destroy any local variables in this block.  Normally, this      variable is nonzero, since those are the normal semantics of      C++.       However, in order to represent aggregate initialization code as      tree structure, we use statement-expressions.  The statements      within the statement expression should not result in cleanups      being run until the entire enclosing statement is complete.       This flag has no effect in C.  */
name|int
name|stmts_are_full_exprs_p
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|stmt_tree_s
modifier|*
name|stmt_tree
typedef|;
end_typedef

begin_comment
comment|/* Global state pertinent to the current function.  Some C dialects    extend this structure with additional fields.  */
end_comment

begin_decl_stmt
name|struct
name|c_language_function
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* While we are parsing the function, this contains information      about the statement-tree that we are building.  */
name|struct
name|stmt_tree_s
name|x_stmt_tree
decl_stmt|;
comment|/* The stack of SCOPE_STMTs for the current function.  */
name|tree
name|x_scope_stmt_stack
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* When building a statement-tree, this is the last statement added to    the tree.  */
end_comment

begin_define
define|#
directive|define
name|last_tree
value|(current_stmt_tree ()->x_last_stmt)
end_define

begin_comment
comment|/* The type of the last expression-statement we have seen.  */
end_comment

begin_define
define|#
directive|define
name|last_expr_type
value|(current_stmt_tree ()->x_last_expr_type)
end_define

begin_comment
comment|/* The name of the last file we have seen.  */
end_comment

begin_define
define|#
directive|define
name|last_expr_filename
value|(current_stmt_tree ()->x_last_expr_filename)
end_define

begin_comment
comment|/* LAST_TREE contains the last statement parsed.  These are chained    together through the TREE_CHAIN field, but often need to be    re-organized since the parse is performed bottom-up.  This macro    makes LAST_TREE the indicated SUBSTMT of STMT.  */
end_comment

begin_define
define|#
directive|define
name|RECHAIN_STMTS
parameter_list|(
name|stmt
parameter_list|,
name|substmt
parameter_list|)
define|\
value|do {						\     substmt = TREE_CHAIN (stmt);		\     TREE_CHAIN (stmt) = NULL_TREE;		\     last_tree = stmt;				\   } while (0)
end_define

begin_comment
comment|/* Language-specific hooks.  */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|lang_expand_stmt
function_decl|)
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|lang_expand_decl_stmt
function_decl|)
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|lang_expand_function_end
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Callback that determines if it's ok for a function to have no    noreturn attribute.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|lang_missing_noreturn_ok_p
function_decl|)
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|stmt_tree
name|current_stmt_tree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
modifier|*
name|current_scope_stmt_stack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|begin_stmt_tree
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|add_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_decl_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|add_scope_stmt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_stmt_tree
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|walk_stmt_tree
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|walk_tree_fn
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prep_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_begin_if_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_begin_while_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_finish_while_stmt_cond
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
name|field_decl_cmp
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

begin_function_decl
specifier|extern
name|void
name|resort_sorted_fields
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

begin_escape
end_escape

begin_comment
comment|/* Switches common to the C front ends.  */
end_comment

begin_comment
comment|/* Nonzero if prepreprocessing only.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_preprocess_only
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Zero means that faster, ...NonNil variants of objc_msgSend...    calls will be used in ObjC; passing nil receivers to such calls    will most likely result in crashes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_nil_receivers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that we will allow new ObjC exception syntax (@throw,    @try, etc.) in source code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_objc_exceptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that code generation will be altered to support    "zero-link" execution.  This currently affects ObjC only, but may    affect other languages in the future.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_zero_link
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means emit an '__OBJC, __image_info' for the current translation    unit.  It will inform the ObjC runtime that class definition(s) herein    contained are to replace one(s) previously loaded.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_replace_objc_classes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't output line number information.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|flag_no_line_commands
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero causes -E output not to be done, but directives such as    #define that have side effects are still obeyed.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|flag_no_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means dump macros in some fashion; contains the 'D', 'M' or    'N' of the command line switch.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|flag_dump_macros
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means pass #include lines through to the output.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|flag_dump_includes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The file name to which we should write a precompiled header, or    NULL if no header will be written in this compile.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|pch_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if an ISO standard was selected.  It rejects macros in the    user's namespace.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_iso
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if -undef was given.  It suppresses target built-in macros    and assertions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_undef
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't recognize the non-ANSI builtin functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_builtin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't recognize the non-ANSI builtin functions.    -ansi sets this.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_nonansi_builtin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means give `double' the same size as `float'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_short_double
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means give `wchar_t' the same size as `short'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_short_wchar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means allow Microsoft extensions without warnings or errors.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_ms_extensions
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
comment|/* Nonzero means give string constants the type `const char *', as mandated    by the standard.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_const_strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means to treat bitfields as signed unless they say `unsigned'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_signed_bitfields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|explicit_flag_signed_bitfields
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
comment|/* Warn about functions which might be candidates for format attributes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_missing_format_attribute
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means do not warn that K&R style main() is not a function prototype.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_bsd_no_warn_kr_main
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
comment|/* Nonzero means warn for any global function def    without separate previous prototype decl.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_missing_prototypes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if adding () is suggested.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_parentheses
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
comment|/* Warn about comparison of signed and unsigned values.    If -1, neither -Wsign-compare nor -Wno-sign-compare has been specified.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_sign_compare
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
comment|/* Warn about testing equality of floating point numbers.  */
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
comment|/* Warn if a type conversion is done that might have confusing results.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_conversion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about #pragma directives that are not recognized.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_unknown_pragmas
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tri state variable.  */
end_comment

begin_comment
comment|/* Warn about format/argument anomalies in calls to formatted I/O functions    (*printf, *scanf, strftime, strfmon, etc.).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about Y2K problems with strftime formats.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_format_y2k
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about excess arguments to formats.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_format_extra_args
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about zero-length formats.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_format_zero_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about non-literal format arguments.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_format_nonliteral
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about possible security problems with calls to format functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_format_security
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C/ObjC language option variables.  */
end_comment

begin_comment
comment|/* Nonzero means message about use of implicit function declarations;  1 means warning; 2 means error.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mesg_implicit_function_declaration
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means allow type mismatches in conditional expressions;    just make their values `void'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_cond_mismatch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means enable C89 Amendment 1 features.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_isoc94
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means use the ISO C99 dialect of C.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_isoc99
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means allow the BSD kernel printf enhancments.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_bsd_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that we have builtin functions, and main is an int.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_hosted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn when casting a function call to a type that does    not match the return type (e.g. (float)sqrt() or (anything*)malloc()    when there is no previous declaration of sqrt or malloc.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_bad_function_cast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about traditional constructs whose meanings changed in ANSI C.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_traditional
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn for a declaration found after a statement.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_declaration_after_statement
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn for non-prototype function decls    or non-prototyped defs without previous prototype.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_strict_prototypes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn for any global function def    without separate previous decl.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_missing_declarations
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about extern declarations of objects not at    file-scope level and about *all* declarations of functions (whether    extern or static) not at file-scope level.  Note that we exclude    implicit function declarations.  To get warnings about those, use    -Wimplicit.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nested_externs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if main is suspicious.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_main
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about possible violations of sequence point rules.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_sequence_point
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about uninitialized variable when it is initialized with itself.     For example: int i = i;, GCC will not warn about this when warn_init_self is nonzero.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_init_self
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means to warn about compile-time division by zero.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_div_by_zero
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about use of implicit int.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_implicit_int
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about NULL being passed to argument slots marked as requiring    non-NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nonnull
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about old-style parameter declaration.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_old_style_definition
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ObjC language option variables.  */
end_comment

begin_comment
comment|/* Open and close the file for outputting class declarations, if    requested (ObjC).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gen_declaration
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate code for GNU or NeXT runtime environment.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_next_runtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tells the compiler that this is a special run.  Do not perform any    compiling, instead we are to test some platform dependent features    and output a C header file with appropriate definitions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|print_struct_values
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ???.  Undocumented.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|constant_string_class_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if multiple methods are seen for the same selector, but with    different argument types.  Performs the check on the whole selector    table at the end of compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_selector
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if a @selector() is found, and no method with that selector    has been previously declared.  The check is done on each    @selector() as soon as it is found - so it warns about forward    declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_undeclared_selector
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if methods required by a protocol are not implemented in the     class adopting it.  When turned off, methods inherited to that    class are also considered implemented.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_protocol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C++ language option variables.  */
end_comment

begin_comment
comment|/* Nonzero means don't recognize any extension keywords.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_gnu_keywords
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
comment|/* Nonzero means that implicit instantiations will be emitted if needed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_implicit_templates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that implicit instantiations of inline templates will be    emitted if needed, even if instantiations of non-inline templates    aren't.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_implicit_inline_templates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means generate separate instantiation control files and    juggle them at link time.  */
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
comment|/* Nonzero means we should attempt to elide constructors when possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_elide_constructors
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
comment|/* Controls whether compiler generates 'type descriptor' that give    run-time type information.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_rtti
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to conserve space in the .o files.  We do this    by putting uninitialized data and runtime initialized data into    .common instead of .data at the expense of not flagging multiple    definitions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_conserve_space
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

begin_comment
comment|/* Nonzero if we want the new ISO rules for pushing a new scope for `for'    initialization variables.    0: Old rules, set by -fno-for-scope.    2: New ISO rules, set by -ffor-scope.    1: Try to implement new ISO rules, but with backup compatibility    (and warnings).  This is the default, for now.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_new_for_scope
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
comment|/* 0 means we want the preprocessor to not emit line directives for    the current working directory.  1 means we want it to do it.  -1    means we should decide depending on whether debugging information    is being emitted or not.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_working_directory
decl_stmt|;
end_decl_stmt

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
comment|/* Nonzero means warn about things that will change when compiling    with an ABI-compliant compiler.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_abi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about invalid uses of offsetof.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_invalid_offsetof
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
comment|/* Nonzero means warn in function declared in derived class has the    same name as a virtual in the base class, but fails to match the    type signature of any virtual function in the base class.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_overloaded_virtual
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn when declaring a class that has a non virtual    destructor, when it really ought to have a virtual one.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nonvdtor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn when the compiler will reorder code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_reorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn when synthesis behavior differs from Cfront's.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_synth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn when we convert a pointer to member function    into a pointer to (void or function).  */
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
comment|/* Nonzero means warn when an old-style cast is used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_old_style_cast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn when non-templatized friend functions are    declared within a template */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_nontemplate_friend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means complain about deprecated features.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_deprecated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum template instantiation depth.  This limit is rather    arbitrary, but it exists to limit the time it takes to notice    infinite template instantiations.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_tinst_depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means the expression being parsed will never be evaluated.    This is a count, since unevaluated expressions can nest.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|skip_evaluation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C types are partitioned into three subsets: object, function, and    incomplete types.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_OBJECT_P
parameter_list|(
name|type
parameter_list|)
define|\
value|(TREE_CODE (type) != FUNCTION_TYPE&& TYPE_SIZE (type))
end_define

begin_define
define|#
directive|define
name|C_TYPE_INCOMPLETE_P
parameter_list|(
name|type
parameter_list|)
define|\
value|(TREE_CODE (type) != FUNCTION_TYPE&& TYPE_SIZE (type) == 0)
end_define

begin_define
define|#
directive|define
name|C_TYPE_FUNCTION_P
parameter_list|(
name|type
parameter_list|)
define|\
value|(TREE_CODE (type) == FUNCTION_TYPE)
end_define

begin_comment
comment|/* For convenience we define a single macro to identify the class of    object or incomplete types.  */
end_comment

begin_define
define|#
directive|define
name|C_TYPE_OBJECT_OR_INCOMPLETE_P
parameter_list|(
name|type
parameter_list|)
define|\
value|(!C_TYPE_FUNCTION_P (type))
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
comment|/* Attribute table common to the C front ends.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|attribute_spec
name|c_common_attribute_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|attribute_spec
name|c_common_format_attribute_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to function to lazily generate the VAR_DECL for __FUNCTION__ etc.    ID is the identifier to use, NAME is the string.    TYPE_DEP indicates whether it depends on type of the function or not    (i.e. __PRETTY_FUNCTION__).  */
end_comment

begin_function_decl
specifier|extern
name|tree
function_decl|(
modifier|*
name|make_fname_decl
function_decl|)
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
name|identifier_global_value
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_builtin_type
parameter_list|(
name|enum
name|rid
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
name|tree
name|build_void_list_node
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_fname_decls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_fname_decls
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
name|fname_as_string
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fname_decl
parameter_list|(
name|unsigned
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_function_arguments
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
name|check_function_arguments_recurse
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_function_format
parameter_list|(
name|int
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
name|set_Wformat
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|handle_format_attribute
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|handle_format_arg_attribute
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_common_handle_option
parameter_list|(
name|size_t
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|arg
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_common_missing_argument
parameter_list|(
specifier|const
name|char
modifier|*
name|opt
parameter_list|,
name|size_t
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_common_type_for_mode
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_common_type_for_size
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_common_unsigned_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_common_signed_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_common_signed_or_unsigned_type
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
name|c_common_truthvalue_conversion
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_apply_type_quals_to_decl
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
name|c_sizeof_or_alignof_type
parameter_list|(
name|tree
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_alignof_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print an error message for invalid operands to arith operation CODE.    NOP_EXPR is used as a special case (see truthvalue_conversion).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|binary_op_error
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|tree
name|c_expand_expr_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_expand_start_cond
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_finish_then
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_expand_start_else
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_finish_else
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_expand_end_cond
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Validate the expression after `case' and apply default promotions.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|check_case_value
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fix_string_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|varray_head_tag
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|constant_expression_warning
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_and_check
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
name|overflow_warning
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unsigned_conversion_warning
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read the rest of the current #-directive line.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_directive_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_DIRECTIVE_LINE
parameter_list|()
value|get_directive_line ()
end_define

begin_define
define|#
directive|define
name|c_sizeof
parameter_list|(
name|T
parameter_list|)
value|c_sizeof_or_alignof_type (T, SIZEOF_EXPR, 1)
end_define

begin_define
define|#
directive|define
name|c_alignof
parameter_list|(
name|T
parameter_list|)
value|c_sizeof_or_alignof_type (T, ALIGNOF_EXPR, 1)
end_define

begin_comment
comment|/* Subroutine of build_binary_op, used for comparison operations.    See if the operands have both been converted from subword integer types    and, if so, perhaps change them both back to their original type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|shorten_compare
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|enum
name|tree_code
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pointer_int_sum
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
name|unsigned
name|int
name|min_precision
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add qualifiers to a type, in the fashion for C.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|c_build_qualified_type
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Build tree nodes and builtin functions common to both C and C++ language    frontends.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_common_nodes_and_builtins
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disable_builtin_function
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_va_arg
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|c_common_init_options
parameter_list|(
name|unsigned
name|int
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
name|bool
name|c_common_post_options
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_common_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_common_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_common_parse_file
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|c_common_get_alias_set
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_register_builtin_type
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
name|bool
name|c_promoting_integer_type_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|self_promoting_args_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|strip_array_types
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|strip_pointer_operator
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function resets the parsers' state in preparation for parsing    a new file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_reset_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is the basic parsing function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_parse_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is misnamed, it actually performs end-of-compilation processing.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|finish_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These macros provide convenient access to the various _STMT nodes.  */
end_comment

begin_comment
comment|/* Nonzero if this statement should be considered a full-expression,    i.e., if temporaries created during this statement should have    their destructors run at the end of this statement.  (In C, this    will always be false, since there are no destructors.)  */
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
comment|/* DO_STMT accessors. These give access to the condition of the do    statement and the body of the do statement, respectively.  */
end_comment

begin_define
define|#
directive|define
name|DO_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (DO_STMT_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|DO_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (DO_STMT_CHECK (NODE), 1)
end_define

begin_comment
comment|/* RETURN_STMT accessors. These give the expression associated with a    return statement, and whether it should be ignored when expanding    (as opposed to inlining).  */
end_comment

begin_define
define|#
directive|define
name|RETURN_STMT_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (RETURN_STMT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* EXPR_STMT accessor. This gives the expression associated with an    expression statement.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_STMT_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (EXPR_STMT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* FOR_STMT accessors. These give access to the init statement,    condition, update expression, and body of the for statement,    respectively.  */
end_comment

begin_define
define|#
directive|define
name|FOR_INIT_STMT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (FOR_STMT_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|FOR_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (FOR_STMT_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|FOR_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (FOR_STMT_CHECK (NODE), 2)
end_define

begin_define
define|#
directive|define
name|FOR_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (FOR_STMT_CHECK (NODE), 3)
end_define

begin_comment
comment|/* SWITCH_STMT accessors. These give access to the condition, body and    original condition type (before any compiler conversions)    of the switch statement, respectively.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SWITCH_STMT_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|SWITCH_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SWITCH_STMT_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|SWITCH_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SWITCH_STMT_CHECK (NODE), 2)
end_define

begin_comment
comment|/* CASE_LABEL accessors. These give access to the high and low values    of a case label, respectively.  */
end_comment

begin_define
define|#
directive|define
name|CASE_LOW
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CASE_LABEL_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|CASE_HIGH
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CASE_LABEL_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|CASE_LABEL_DECL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CASE_LABEL_CHECK (NODE), 2)
end_define

begin_comment
comment|/* GOTO_STMT accessor. This gives access to the label associated with    a goto statement.  */
end_comment

begin_define
define|#
directive|define
name|GOTO_DESTINATION
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (GOTO_STMT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* True for goto created artificially by the compiler.  */
end_comment

begin_define
define|#
directive|define
name|GOTO_FAKE_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_0 (GOTO_STMT_CHECK (NODE)))
end_define

begin_comment
comment|/* COMPOUND_STMT accessor. This gives access to the TREE_LIST of    statements associated with a compound statement. The result is the    first statement in the list. Succeeding nodes can be accessed by    calling TREE_CHAIN on a node in the list.  */
end_comment

begin_define
define|#
directive|define
name|COMPOUND_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (COMPOUND_STMT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* ASM_STMT accessors. ASM_STRING returns a STRING_CST for the    instruction (e.g., "mov x, y"). ASM_OUTPUTS, ASM_INPUTS, and    ASM_CLOBBERS represent the outputs, inputs, and clobbers for the    statement.  */
end_comment

begin_define
define|#
directive|define
name|ASM_CV_QUAL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_STMT_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|ASM_STRING
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_STMT_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_STMT_CHECK (NODE), 2)
end_define

begin_define
define|#
directive|define
name|ASM_INPUTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_STMT_CHECK (NODE), 3)
end_define

begin_define
define|#
directive|define
name|ASM_CLOBBERS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_STMT_CHECK (NODE), 4)
end_define

begin_comment
comment|/* DECL_STMT accessor. This gives access to the DECL associated with    the given declaration statement.  */
end_comment

begin_define
define|#
directive|define
name|DECL_STMT_DECL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (DECL_STMT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* STMT_EXPR accessor.  */
end_comment

begin_define
define|#
directive|define
name|STMT_EXPR_STMT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (STMT_EXPR_CHECK (NODE), 0)
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
comment|/* Nonzero if this statement-expression should cause warning if its result    is not used.  */
end_comment

begin_define
define|#
directive|define
name|STMT_EXPR_WARN_UNUSED_RESULT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_3 (STMT_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* LABEL_STMT accessor. This gives access to the label associated with    the given label statement.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_STMT_LABEL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (LABEL_STMT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* COMPOUND_LITERAL_EXPR accessors.  */
end_comment

begin_define
define|#
directive|define
name|COMPOUND_LITERAL_EXPR_DECL_STMT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (COMPOUND_LITERAL_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|COMPOUND_LITERAL_EXPR_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|DECL_STMT_DECL (COMPOUND_LITERAL_EXPR_DECL_STMT (NODE))
end_define

begin_comment
comment|/* Nonzero if this SCOPE_STMT is for the beginning of a scope.  */
end_comment

begin_define
define|#
directive|define
name|SCOPE_BEGIN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_0 (SCOPE_STMT_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero if this SCOPE_STMT is for the end of a scope.  */
end_comment

begin_define
define|#
directive|define
name|SCOPE_END_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(!SCOPE_BEGIN_P (SCOPE_STMT_CHECK (NODE)))
end_define

begin_comment
comment|/* The BLOCK containing the declarations contained in this scope.  */
end_comment

begin_define
define|#
directive|define
name|SCOPE_STMT_BLOCK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_OPERAND (SCOPE_STMT_CHECK (NODE), 0))
end_define

begin_comment
comment|/* Nonzero for a SCOPE_STMT if there were no variables in this scope.  */
end_comment

begin_define
define|#
directive|define
name|SCOPE_NULLIFIED_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(SCOPE_STMT_BLOCK ((NODE)) == NULL_TREE)
end_define

begin_comment
comment|/* Nonzero for a SCOPE_STMT which represents a lexical scope, but    which should be treated as non-existent from the point of view of    running cleanup actions.  */
end_comment

begin_define
define|#
directive|define
name|SCOPE_NO_CLEANUPS_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_3 (SCOPE_STMT_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero for a SCOPE_STMT if this statement is for a partial scope.    For example, in:       S s;      l:      S s2;      goto l;     there is (implicitly) a new scope after `l', even though there are    no curly braces.  In particular, when we hit the goto, we must    destroy s2 and then re-construct it.  For the implicit scope,    SCOPE_PARTIAL_P will be set.  */
end_comment

begin_define
define|#
directive|define
name|SCOPE_PARTIAL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_4 (SCOPE_STMT_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero for an ASM_STMT if the assembly statement is volatile.  */
end_comment

begin_define
define|#
directive|define
name|ASM_VOLATILE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(ASM_CV_QUAL (ASM_STMT_CHECK (NODE)) != NULL_TREE)
end_define

begin_comment
comment|/* The VAR_DECL to clean up in a CLEANUP_STMT.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (CLEANUP_STMT_CHECK (NODE), 0)
end_define

begin_comment
comment|/* The cleanup to run in a CLEANUP_STMT.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_EXPR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (CLEANUP_STMT_CHECK (NODE), 1)
end_define

begin_comment
comment|/* The filename we are changing to as of this FILE_STMT.  */
end_comment

begin_define
define|#
directive|define
name|FILE_STMT_FILENAME_NODE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_OPERAND (FILE_STMT_CHECK (NODE), 0))
end_define

begin_define
define|#
directive|define
name|FILE_STMT_FILENAME
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_POINTER (FILE_STMT_FILENAME_NODE (NODE)))
end_define

begin_comment
comment|/* The line-number at which a statement began.  But if    STMT_LINENO_FOR_FN_P does holds, then this macro gives the    line number for the end of the current function instead.  */
end_comment

begin_define
define|#
directive|define
name|STMT_LINENO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_COMPLEXITY ((NODE)))
end_define

begin_comment
comment|/* If nonzero, the STMT_LINENO for NODE is the line at which the    function ended.  */
end_comment

begin_define
define|#
directive|define
name|STMT_LINENO_FOR_FN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_LANG_FLAG_2 ((NODE)))
end_define

begin_comment
comment|/* Nonzero if we want the new ISO rules for pushing a new scope for `for'    initialization variables.  */
end_comment

begin_define
define|#
directive|define
name|NEW_FOR_SCOPE_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_0 (NODE))
end_define

begin_comment
comment|/* Nonzero if we want to create an ASM_INPUT instead of an    ASM_OPERAND with no operands.  */
end_comment

begin_define
define|#
directive|define
name|ASM_INPUT_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LANG_FLAG_0 (NODE))
end_define

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
name|c_tree_code
block|{
name|C_DUMMY_TREE_CODE
init|=
name|LAST_AND_UNUSED_TREE_CODE
block|,
include|#
directive|include
file|"c-common.def"
name|LAST_C_TREE_CODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_define
define|#
directive|define
name|c_common_stmt_codes
define|\
value|CLEANUP_STMT,	EXPR_STMT,	COMPOUND_STMT,	\    DECL_STMT,		IF_STMT,	FOR_STMT,	\    WHILE_STMT,		DO_STMT,	RETURN_STMT,	\    BREAK_STMT,		CONTINUE_STMT,	SCOPE_STMT,	\    SWITCH_STMT,		GOTO_STMT,	LABEL_STMT,	\    ASM_STMT,		FILE_STMT,	CASE_LABEL
end_define

begin_comment
comment|/* TRUE if a code represents a statement.  The front end init    langhook should take care of initialization of this array.  */
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

begin_define
define|#
directive|define
name|INIT_STATEMENT_CODES
parameter_list|(
name|STMT_CODES
parameter_list|)
define|\
value|do {								\     unsigned int i;						\     memset (&statement_code_p, 0, sizeof (statement_code_p));	\     for (i = 0; i< ARRAY_SIZE (STMT_CODES); i++)		\       statement_code_p[STMT_CODES[i]] = true;			\   } while (0)
end_define

begin_function_decl
specifier|extern
name|void
name|genrtl_do_pushlevel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_goto_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_expr_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_expr_stmt_value
parameter_list|(
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
name|void
name|genrtl_decl_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_if_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_while_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_do_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_return_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_for_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_break_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_continue_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_scope_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_switch_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_case_label
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_compound_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_asm_stmt
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|genrtl_cleanup_stmt
parameter_list|(
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
name|int
name|anon_aggr_type_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For a VAR_DECL that is an anonymous union, these are the various    sub-variables that make up the anonymous union.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ANON_UNION_ELEMS
parameter_list|(
name|NODE
parameter_list|)
value|DECL_ARGUMENTS ((NODE))
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
value|(DECL_LANG_FLAG_4 (FIELD_DECL_CHECK (NODE)) == 1)
end_define

begin_define
define|#
directive|define
name|SET_DECL_C_BIT_FIELD
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_4 (FIELD_DECL_CHECK (NODE)) = 1)
end_define

begin_define
define|#
directive|define
name|CLEAR_DECL_C_BIT_FIELD
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_LANG_FLAG_4 (FIELD_DECL_CHECK (NODE)) = 0)
end_define

begin_comment
comment|/* In a VAR_DECL, nonzero if the decl is a register variable with    an explicit asm specification.  */
end_comment

begin_define
define|#
directive|define
name|DECL_C_HARD_REGISTER
parameter_list|(
name|DECL
parameter_list|)
value|DECL_LANG_FLAG_4 (VAR_DECL_CHECK (DECL))
end_define

begin_function_decl
specifier|extern
name|void
name|emit_local_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_rtl_for_local_static
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|expand_cond
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_expand_return
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|do_case
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
name|build_stmt
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
name|build_case_label
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
name|build_continue_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_break_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_return_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|COMPOUND_STMT_NO_SCOPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0 (NODE)
end_define

begin_comment
comment|/* Used by the C++ frontend to mark the block around the member    initializers and cleanups.  */
end_comment

begin_define
define|#
directive|define
name|COMPOUND_STMT_BODY_BLOCK
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_3 (NODE)
end_define

begin_function_decl
specifier|extern
name|void
name|c_expand_asm_operands
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
name|location_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These functions must be defined by each front-end which implements    a variant of the C language.  They are used in c-common.c.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_unary_op
parameter_list|(
name|enum
name|tree_code
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
name|build_binary_op
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
name|int
name|lvalue_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|default_conversion
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given two integer or real types, return the type for their sum.    Given two compatible ANSI C types, returns the merged type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|common_type
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
name|expand_tree_builtin
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
name|decl_constant_value
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Handle increment and decrement of boolean types.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|boolean_increment
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Hook currently used only by the C++ front end to reset internal state    after entering or leaving a header file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|extract_interface_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|case_compare
parameter_list|(
name|splay_tree_key
parameter_list|,
name|splay_tree_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_add_case_label
parameter_list|(
name|splay_tree
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
name|build_function_call
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
name|finish_label_address_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Same function prototype, but the C and C++ front ends have    different implementations.  Used in c-common.c.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|lookup_label
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|c_expand_expr
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
name|int
name|c_safe_from_p
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_staticp
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_common_unsafe_for_reeval
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_c_lex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_cpp_builtins
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Positive if an implicit `extern "C"' scope has just been entered;    negative if such a scope has just been exited.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pending_lang_change
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Information recorded about each file examined during compilation.  */
end_comment

begin_struct
struct|struct
name|c_fileinfo
block|{
name|int
name|time
decl_stmt|;
comment|/* Time spent in the file.  */
name|short
name|interface_only
decl_stmt|;
comment|/* Flags - used only by C++ */
name|short
name|interface_unknown
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|c_fileinfo
modifier|*
name|get_fileinfo
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
name|dump_time_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_dump_tree
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
name|void
name|pch_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_common_valid_pch
parameter_list|(
name|cpp_reader
modifier|*
name|pfile
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_common_read_pch
parameter_list|(
name|cpp_reader
modifier|*
name|pfile
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_common_write_pch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_common_no_more_pch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|builtin_define_with_value
parameter_list|(
specifier|const
name|char
modifier|*
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
name|c_stddef_cpp_builtins
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fe_file_change
parameter_list|(
specifier|const
name|struct
name|line_map
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_estimate_num_insns
parameter_list|(
name|tree
name|decl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|c_decl_uninit
parameter_list|(
name|tree
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_parse_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|cpp_ttype
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following have been moved here from c-tree.h, since they're needed    in the ObjC++ world, too.  What is more, stub-objc.c could use a few    prototypes.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|lookup_interface
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|is_class_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_is_object_ptr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_check_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|objc_comptypes
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
name|objc_message_selector
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|lookup_objc_ivar
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|get_current_scope
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_mark_locals_volatile
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In c-ppoutput.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_pp_output
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|preprocess_file
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_file_change
parameter_list|(
specifier|const
name|struct
name|line_map
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_dir_change
parameter_list|(
name|cpp_reader
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_C_COMMON_H */
end_comment

end_unit

