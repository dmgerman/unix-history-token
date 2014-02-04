begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for c-common.c.    Copyright (C) 1987, 1993, 1994, 1995, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
comment|/* Usage of TREE_LANG_FLAG_?:    0: TREE_NEGATED_INT (in INTEGER_CST).       IDENTIFIER_MARKED (used by search routines).       DECL_PRETTY_FUNCTION_P (in VAR_DECL)    1: C_DECLARED_LABEL_FLAG (in LABEL_DECL)       STATEMENT_LIST_STMT_EXPR (in STATEMENT_LIST)    2: unused    3: STATEMENT_LIST_HAS_LABEL (in STATEMENT_LIST)    4: unused */
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
name|RID_CHOOSE_EXPR
block|,
name|RID_TYPES_COMPATIBLE_P
block|,
name|RID_DFLOAT32
block|,
name|RID_DFLOAT64
block|,
name|RID_DFLOAT128
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
value|((unsigned int) (rid)>= (unsigned int) RID_FIRST_AT&& \    (unsigned int) (rid)<= (unsigned int) RID_LAST_AT)
end_define

begin_define
define|#
directive|define
name|OBJC_IS_PQ_KEYWORD
parameter_list|(
name|rid
parameter_list|)
define|\
value|((unsigned int) (rid)>= (unsigned int) RID_FIRST_PQ&& \    (unsigned int) (rid)<= (unsigned int) RID_LAST_PQ)
end_define

begin_comment
comment|/* The elements of `ridpointers' are identifier nodes for the reserved    type names and storage classes.  It is indexed by a RID_... value.  */
end_comment

begin_extern
extern|extern GTY ((length (
literal|"(int) RID_MAX"
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
name|CTI_NULL
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

begin_comment
comment|/* The node for C++ `__null'.  */
end_comment

begin_define
define|#
directive|define
name|null_node
value|c_global_trees[CTI_NULL]
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
comment|/* The current statement list being collected.  */
name|tree
name|x_cur_stmt_list
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* When building a statement-tree, this is the current statement list    being collected.  It's TREE_CHAIN is a back-pointer to the previous    statement list.  */
end_comment

begin_define
define|#
directive|define
name|cur_stmt_list
value|(current_stmt_tree ()->x_cur_stmt_list)
end_define

begin_comment
comment|/* Language-specific hooks.  */
end_comment

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

begin_comment
comment|/* If non-NULL, this function is called after a precompile header file    is loaded.  */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|lang_post_pch_load
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_file_scope
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_file_scope
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
name|push_stmt_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|pop_stmt_list
parameter_list|(
name|tree
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
name|push_cleanup
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
name|pushdecl_top_level
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
name|int
name|c_expand_decl
parameter_list|(
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

begin_function_decl
specifier|extern
name|bool
name|has_c_linkage
parameter_list|(
name|tree
name|decl
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
comment|/* Nonzero means that we generate NeXT setjmp based exceptions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_objc_sjlj_exceptions
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
comment|/* Nonzero means process PCH files while preprocessing.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|flag_pch_preprocess
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
comment|/* Nonzero means allow implicit conversions between vectors with    differing numbers of subparts and/or differing element types.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_lax_vector_conversions
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
comment|/* C/ObjC language option variables.  */
end_comment

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
comment|/* Nonzero means that we have builtin functions, and main is an int.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_hosted
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
comment|/* Nonzero to use __cxa_get_exception_ptr in the C++ exception-handling    logic.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_use_cxa_get_exception_ptr
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
comment|/* Nonzero (the default) means to generate thread-safe code for    initializing local statics.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_threadsafe_statics
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
comment|/* Warn about using __null (as NULL in C++) as sentinel.  For code compiled    with GCC this doesn't matter as __null is guaranteed to have the right    size.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_strict_null_sentinel
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
name|c_build_bitfield_integer_type
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|int
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
name|bool
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
name|bool
name|strict_aliasing_warning
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
name|empty_body_warning
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
name|bool
name|c_determine_visibility
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|same_scalar_type_ignoring_signedness
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
name|c_sizeof
parameter_list|(
name|T
parameter_list|)
value|c_sizeof_or_alignof_type (T, true, 1)
end_define

begin_define
define|#
directive|define
name|c_alignof
parameter_list|(
name|T
parameter_list|)
value|c_sizeof_or_alignof_type (T, false, 1)
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
name|set_builtin_user_assembler_name
parameter_list|(
name|tree
name|decl
parameter_list|,
specifier|const
name|char
modifier|*
name|asmspec
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
name|void
name|set_compound_literal_name
parameter_list|(
name|tree
name|decl
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

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|c_common_to_target_charset
parameter_list|(
name|HOST_WIDE_INT
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
comment|/* Nonzero if a given STATEMENT_LIST represents the outermost binding    if a statement expression.  */
end_comment

begin_define
define|#
directive|define
name|STATEMENT_LIST_STMT_EXPR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_1 (STATEMENT_LIST_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if a label has been added to the statement list.  */
end_comment

begin_define
define|#
directive|define
name|STATEMENT_LIST_HAS_LABEL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_LANG_FLAG_3 (STATEMENT_LIST_CHECK (NODE))
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
value|DECL_EXPR_DECL (COMPOUND_LITERAL_EXPR_DECL_STMT (NODE))
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
name|tree
name|perform_integral_promotions
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These functions must be defined by each front-end which implements    a variant of the C language.  They are used by port files.  */
end_comment

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
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_do_switch_warnings
parameter_list|(
name|splay_tree
parameter_list|,
name|location_t
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
name|resolve_overloaded_builtin
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
name|tree
name|lookup_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|vector_types_convertible_p
parameter_list|(
name|tree
name|t1
parameter_list|,
name|tree
name|t2
parameter_list|,
name|bool
name|emit_lax_note
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
name|tree
name|c_staticp
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

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
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
comment|/* Flags used only by C++.      INTERFACE_ONLY nonzero means that we are in an "interface" section      of the compiler.  INTERFACE_UNKNOWN nonzero means we cannot trust      the value of INTERFACE_ONLY.  If INTERFACE_UNKNOWN is zero and      INTERFACE_ONLY is zero, it means that we are responsible for      exporting definitions that others might need.  */
name|short
name|interface_only
decl_stmt|;
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
name|c_warn_unused_result
parameter_list|(
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|verify_sequence_points
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_offsetof
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Places where an lvalue, or modifiable lvalue, may be required.    Used to select diagnostic messages in lvalue_error and    readonly_error.  */
end_comment

begin_enum
enum|enum
name|lvalue_use
block|{
name|lv_assign
block|,
name|lv_increment
block|,
name|lv_decrement
block|,
name|lv_addressof
block|,
name|lv_asm
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|lvalue_error
parameter_list|(
name|enum
name|lvalue_use
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|complete_array_type
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
name|builtin_type_for_size
parameter_list|(
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|warn_array_subscript_with_type_char
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|warn_about_parentheses
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In c-gimplify.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|c_genericize
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|c_gimplify_expr
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
name|tree
name|c_build_bind_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In c-pch.c  */
end_comment

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
name|c_common_pch_pragma
parameter_list|(
name|cpp_reader
modifier|*
name|pfile
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
name|c_common_print_pch_checksum
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In *-checksum.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|executable_checksum
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

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
comment|/* Objective-C / Objective-C++ entry points.  */
end_comment

begin_comment
comment|/* The following ObjC/ObjC++ functions are called by the C and/or C++    front-ends; they all must have corresponding stubs in stub-objc.c.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|objc_is_class_name
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
name|objc_is_reserved_word
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|objc_compare_types
parameter_list|(
name|tree
parameter_list|,
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
name|objc_volatilize_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|objc_type_quals_match
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
name|objc_rewrite_function_call
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
name|objc_message_selector
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_lookup_ivar
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
name|objc_clear_super_receiver
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|objc_is_public
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
name|objc_is_id
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_declare_alias
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
name|objc_declare_class
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_declare_protocols
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_build_message_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_finish_message_expr
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
name|objc_build_selector_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_build_protocol_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_build_encode_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_build_string_object
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_get_protocol_qualified_type
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
name|objc_get_class_reference
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_get_class_ivars
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_start_class_interface
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
name|objc_start_category_interface
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
name|objc_start_protocol
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
name|objc_continue_interface
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_finish_interface
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_start_class_implementation
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
name|objc_start_category_implementation
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
name|objc_continue_implementation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_finish_implementation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_set_visibility
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_set_method_type
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_build_method_signature
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
name|void
name|objc_add_method_declaration
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_start_method_definition
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_finish_method_definition
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_add_instance_variable
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_build_keyword_decl
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
name|objc_build_throw_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_begin_try_stmt
parameter_list|(
name|location_t
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_finish_try_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_begin_catch_clause
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_finish_catch_clause
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_build_finally_clause
parameter_list|(
name|location_t
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_build_synchronized
parameter_list|(
name|location_t
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
name|objc_static_init_needed_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_generate_static_init_call
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|objc_generate_write_barrier
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

begin_comment
comment|/* The following are provided by the C and C++ front-ends, and called by    ObjC/ObjC++.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|objc_get_current_scope
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

begin_function_decl
specifier|extern
name|bool
name|check_missing_format_attribute
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In c-omp.c  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|c_finish_omp_master
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_omp_critical
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
name|c_finish_omp_ordered
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|c_finish_omp_barrier
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_omp_atomic
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
name|c_finish_omp_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_finish_omp_for
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
name|c_split_parallel_clauses
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
name|enum
name|omp_clause_default_kind
name|c_omp_predetermined_sharing
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Not in c-omp.c; provided by the front end.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|c_omp_sharing_predetermined
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_omp_remap_decl
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In order for the format checking to accept the C frontend    diagnostic framework extensions, you must include this file before    toplev.h, not after.  The C front end formats are a subset of those    for C++, so they are the appropriate set to use in common code;    cp-tree.h overrides this for C++.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DIAG_STYLE
end_ifndef

begin_define
define|#
directive|define
name|GCC_DIAG_STYLE
value|__gcc_cdiag__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_C_COMMON_H */
end_comment

end_unit

