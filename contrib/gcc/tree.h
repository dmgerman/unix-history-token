begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Front-end tree definitions for GNU compiler.    Copyright (C) 1989, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_H
end_define

begin_include
include|#
directive|include
file|"hashtab.h"
end_include

begin_include
include|#
directive|include
file|"machmode.h"
end_include

begin_include
include|#
directive|include
file|"input.h"
end_include

begin_include
include|#
directive|include
file|"statistics.h"
end_include

begin_include
include|#
directive|include
file|"vec.h"
end_include

begin_comment
comment|/* Codes of tree nodes */
end_comment

begin_define
define|#
directive|define
name|DEFTREECODE
parameter_list|(
name|SYM
parameter_list|,
name|STRING
parameter_list|,
name|TYPE
parameter_list|,
name|NARGS
parameter_list|)
value|SYM,
end_define

begin_enum
enum|enum
name|tree_code
block|{
include|#
directive|include
file|"tree.def"
name|LAST_AND_UNUSED_TREE_CODE
comment|/* A convenient way to get a value for 				   NUM_TREE_CODES.  */
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|tree_contains_struct
index|[
literal|256
index|]
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CODE_CONTAINS_STRUCT
parameter_list|(
name|CODE
parameter_list|,
name|STRUCT
parameter_list|)
value|(tree_contains_struct[(CODE)][(STRUCT)])
end_define

begin_comment
comment|/* Number of language-independent tree codes.  */
end_comment

begin_define
define|#
directive|define
name|NUM_TREE_CODES
value|((int) LAST_AND_UNUSED_TREE_CODE)
end_define

begin_comment
comment|/* Tree code classes.  */
end_comment

begin_comment
comment|/* Each tree_code has an associated code class represented by a    TREE_CODE_CLASS.  */
end_comment

begin_enum
enum|enum
name|tree_code_class
block|{
name|tcc_exceptional
block|,
comment|/* An exceptional code (fits no category).  */
name|tcc_constant
block|,
comment|/* A constant.  */
comment|/* Order of tcc_type and tcc_declaration is important.  */
name|tcc_type
block|,
comment|/* A type object code.  */
name|tcc_declaration
block|,
comment|/* A declaration (also serving as variable refs).  */
name|tcc_reference
block|,
comment|/* A reference to storage.  */
name|tcc_comparison
block|,
comment|/* A comparison expression.  */
name|tcc_unary
block|,
comment|/* A unary arithmetic expression.  */
name|tcc_binary
block|,
comment|/* A binary arithmetic expression.  */
name|tcc_statement
block|,
comment|/* A statement expression, which have side effects 		      but usually no interesting value.  */
name|tcc_expression
comment|/* Any other expression.  */
block|}
enum|;
end_enum

begin_comment
comment|/* Each tree code class has an associated string representation.    These must correspond to the tree_code_class entries.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|tree_code_class_strings
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns the string representing CLASS.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CODE_CLASS_STRING
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|tree_code_class_strings[(int) (CLASS)]
end_define

begin_define
define|#
directive|define
name|MAX_TREE_CODES
value|256
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|enum
name|tree_code_class
name|tree_code_type
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TREE_CODE_CLASS
parameter_list|(
name|CODE
parameter_list|)
value|tree_code_type[(int) (CODE)]
end_define

begin_comment
comment|/* Nonzero if CODE represents an exceptional code.  */
end_comment

begin_define
define|#
directive|define
name|EXCEPTIONAL_CLASS_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_exceptional)
end_define

begin_comment
comment|/* Nonzero if CODE represents a constant.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_CLASS_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_constant)
end_define

begin_comment
comment|/* Nonzero if CODE represents a type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_type)
end_define

begin_comment
comment|/* Nonzero if CODE represents a declaration.  */
end_comment

begin_define
define|#
directive|define
name|DECL_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_declaration)
end_define

begin_comment
comment|/* Nonzero if CODE represents a memory tag.  */
end_comment

begin_define
define|#
directive|define
name|MTAG_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE (CODE) == STRUCT_FIELD_TAG		\    || TREE_CODE (CODE) == NAME_MEMORY_TAG	\    || TREE_CODE (CODE) == SYMBOL_MEMORY_TAG)
end_define

begin_comment
comment|/* Nonzero if DECL represents a VAR_DECL or FUNCTION_DECL.  */
end_comment

begin_define
define|#
directive|define
name|VAR_OR_FUNCTION_DECL_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(TREE_CODE (DECL) == VAR_DECL || TREE_CODE (DECL) == FUNCTION_DECL)
end_define

begin_comment
comment|/* Nonzero if CODE represents a INDIRECT_REF.  Keep these checks in    ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|INDIRECT_REF_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE (CODE) == INDIRECT_REF \    || TREE_CODE (CODE) == ALIGN_INDIRECT_REF \    || TREE_CODE (CODE) == MISALIGNED_INDIRECT_REF)
end_define

begin_comment
comment|/* Nonzero if CODE represents a reference.  */
end_comment

begin_define
define|#
directive|define
name|REFERENCE_CLASS_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_reference)
end_define

begin_comment
comment|/* Nonzero if CODE represents a comparison.  */
end_comment

begin_define
define|#
directive|define
name|COMPARISON_CLASS_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_comparison)
end_define

begin_comment
comment|/* Nonzero if CODE represents a unary arithmetic expression.  */
end_comment

begin_define
define|#
directive|define
name|UNARY_CLASS_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_unary)
end_define

begin_comment
comment|/* Nonzero if CODE represents a binary arithmetic expression.  */
end_comment

begin_define
define|#
directive|define
name|BINARY_CLASS_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_binary)
end_define

begin_comment
comment|/* Nonzero if CODE represents a statement expression.  */
end_comment

begin_define
define|#
directive|define
name|STATEMENT_CLASS_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_statement)
end_define

begin_comment
comment|/* Nonzero if CODE represents any other expression.  */
end_comment

begin_define
define|#
directive|define
name|EXPRESSION_CLASS_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TREE_CODE_CLASS (TREE_CODE (CODE)) == tcc_expression)
end_define

begin_comment
comment|/* Returns nonzero iff CODE represents a type or declaration.  */
end_comment

begin_define
define|#
directive|define
name|IS_TYPE_OR_DECL_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(TYPE_P (CODE) || DECL_P (CODE))
end_define

begin_comment
comment|/* Returns nonzero iff CLASS is the tree-code class of an    expression.  */
end_comment

begin_define
define|#
directive|define
name|IS_EXPR_CODE_CLASS
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|((CLASS)>= tcc_reference&& (CLASS)<= tcc_expression)
end_define

begin_comment
comment|/* Returns nonzero iff NODE is an expression of some kind.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_P
parameter_list|(
name|NODE
parameter_list|)
value|IS_EXPR_CODE_CLASS (TREE_CODE_CLASS (TREE_CODE (NODE)))
end_define

begin_comment
comment|/* Returns nonzero iff NODE is an OpenMP directive.  */
end_comment

begin_define
define|#
directive|define
name|OMP_DIRECTIVE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CODE (NODE) == OMP_PARALLEL			\      || TREE_CODE (NODE) == OMP_FOR			\      || TREE_CODE (NODE) == OMP_SECTIONS		\      || TREE_CODE (NODE) == OMP_SINGLE			\      || TREE_CODE (NODE) == OMP_SECTION			\      || TREE_CODE (NODE) == OMP_MASTER			\      || TREE_CODE (NODE) == OMP_ORDERED			\      || TREE_CODE (NODE) == OMP_CRITICAL		\      || TREE_CODE (NODE) == OMP_RETURN			\      || TREE_CODE (NODE) == OMP_CONTINUE)
end_define

begin_comment
comment|/* Number of argument-words in each kind of tree-node.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|tree_code_length
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TREE_CODE_LENGTH
parameter_list|(
name|CODE
parameter_list|)
value|tree_code_length[(int) (CODE)]
end_define

begin_comment
comment|/* Names of tree components.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|tree_code_name
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A vectors of trees.  */
end_comment

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|tree
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|tree
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/* Classify which part of the compiler has defined a given builtin function.    Note that we assume below that this is no more than two bits.  */
end_comment

begin_enum
enum|enum
name|built_in_class
block|{
name|NOT_BUILT_IN
init|=
literal|0
block|,
name|BUILT_IN_FRONTEND
block|,
name|BUILT_IN_MD
block|,
name|BUILT_IN_NORMAL
block|}
enum|;
end_enum

begin_comment
comment|/* Names for the above.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|built_in_class_names
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Codes that identify the various built in functions    so that expand_call can identify them quickly.  */
end_comment

begin_define
define|#
directive|define
name|DEF_BUILTIN
parameter_list|(
name|ENUM
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|,
name|LT
parameter_list|,
name|B
parameter_list|,
name|F
parameter_list|,
name|NA
parameter_list|,
name|AT
parameter_list|,
name|IM
parameter_list|,
name|COND
parameter_list|)
value|ENUM,
end_define

begin_enum
enum|enum
name|built_in_function
block|{
include|#
directive|include
file|"builtins.def"
comment|/* Complex division routines in libgcc.  These are done via builtins      because emit_library_call_value can't handle complex values.  */
name|BUILT_IN_COMPLEX_MUL_MIN
block|,
name|BUILT_IN_COMPLEX_MUL_MAX
init|=
name|BUILT_IN_COMPLEX_MUL_MIN
operator|+
name|MAX_MODE_COMPLEX_FLOAT
operator|-
name|MIN_MODE_COMPLEX_FLOAT
block|,
name|BUILT_IN_COMPLEX_DIV_MIN
block|,
name|BUILT_IN_COMPLEX_DIV_MAX
init|=
name|BUILT_IN_COMPLEX_DIV_MIN
operator|+
name|MAX_MODE_COMPLEX_FLOAT
operator|-
name|MIN_MODE_COMPLEX_FLOAT
block|,
comment|/* Upper bound on non-language-specific builtins.  */
name|END_BUILTINS
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEF_BUILTIN
end_undef

begin_comment
comment|/* Names for the above.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|built_in_names
index|[
operator|(
name|int
operator|)
name|END_BUILTINS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Helper macros for math builtins.  */
end_comment

begin_define
define|#
directive|define
name|BUILTIN_EXP10_P
parameter_list|(
name|FN
parameter_list|)
define|\
value|((FN) == BUILT_IN_EXP10 || (FN) == BUILT_IN_EXP10F || (FN) == BUILT_IN_EXP10L \   || (FN) == BUILT_IN_POW10 || (FN) == BUILT_IN_POW10F || (FN) == BUILT_IN_POW10L)
end_define

begin_define
define|#
directive|define
name|BUILTIN_EXPONENT_P
parameter_list|(
name|FN
parameter_list|)
value|(BUILTIN_EXP10_P (FN) \   || (FN) == BUILT_IN_EXP || (FN) == BUILT_IN_EXPF || (FN) == BUILT_IN_EXPL \   || (FN) == BUILT_IN_EXP2 || (FN) == BUILT_IN_EXP2F || (FN) == BUILT_IN_EXP2L)
end_define

begin_define
define|#
directive|define
name|BUILTIN_SQRT_P
parameter_list|(
name|FN
parameter_list|)
define|\
value|((FN) == BUILT_IN_SQRT || (FN) == BUILT_IN_SQRTF || (FN) == BUILT_IN_SQRTL)
end_define

begin_define
define|#
directive|define
name|BUILTIN_CBRT_P
parameter_list|(
name|FN
parameter_list|)
define|\
value|((FN) == BUILT_IN_CBRT || (FN) == BUILT_IN_CBRTF || (FN) == BUILT_IN_CBRTL)
end_define

begin_define
define|#
directive|define
name|BUILTIN_ROOT_P
parameter_list|(
name|FN
parameter_list|)
value|(BUILTIN_SQRT_P (FN) || BUILTIN_CBRT_P (FN))
end_define

begin_define
define|#
directive|define
name|CASE_FLT_FN
parameter_list|(
name|FN
parameter_list|)
value|case FN: case FN##F: case FN##L
end_define

begin_define
define|#
directive|define
name|CASE_INT_FN
parameter_list|(
name|FN
parameter_list|)
value|case FN: case FN##L: case FN##LL
end_define

begin_comment
comment|/* An array of _DECL trees for the above.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|built_in_decls
index|[
operator|(
name|int
operator|)
name|END_BUILTINS
index|]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|implicit_built_in_decls
index|[
operator|(
name|int
operator|)
name|END_BUILTINS
index|]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* In an OMP_CLAUSE node.  */
end_comment

begin_comment
comment|/* Number of operands and names for each clause.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
specifier|const
name|char
name|omp_clause_num_ops
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|omp_clause_code_name
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clause codes.  Do not reorder, as this is used to index into the tables    omp_clause_num_ops and omp_clause_code_name.  */
end_comment

begin_enum
enum|enum
name|omp_clause_code
block|{
comment|/* Clause zero is special-cased inside the parser      (c_parser_omp_variable_list).  */
name|OMP_CLAUSE_ERROR
init|=
literal|0
block|,
comment|/* OpenMP clause: private (variable_list).  */
name|OMP_CLAUSE_PRIVATE
block|,
comment|/* OpenMP clause: shared (variable_list).  */
name|OMP_CLAUSE_SHARED
block|,
comment|/* OpenMP clause: firstprivate (variable_list).  */
name|OMP_CLAUSE_FIRSTPRIVATE
block|,
comment|/* OpenMP clause: lastprivate (variable_list).  */
name|OMP_CLAUSE_LASTPRIVATE
block|,
comment|/* OpenMP clause: reduction (operator:variable_list).      OMP_CLAUSE_REDUCTION_CODE: The tree_code of the operator.      Operand 1: OMP_CLAUSE_REDUCTION_INIT: Stmt-list to initialize the var.      Operand 2: OMP_CLAUSE_REDUCTION_MERGE: Stmt-list to merge private var                 into the shared one.      Operand 3: OMP_CLAUSE_REDUCTION_PLACEHOLDER: A dummy VAR_DECL                 placeholder used in OMP_CLAUSE_REDUCTION_MERGE.  */
name|OMP_CLAUSE_REDUCTION
block|,
comment|/* OpenMP clause: copyin (variable_list).  */
name|OMP_CLAUSE_COPYIN
block|,
comment|/* OpenMP clause: copyprivate (variable_list).  */
name|OMP_CLAUSE_COPYPRIVATE
block|,
comment|/* OpenMP clause: if (scalar-expression).  */
name|OMP_CLAUSE_IF
block|,
comment|/* OpenMP clause: num_threads (integer-expression).  */
name|OMP_CLAUSE_NUM_THREADS
block|,
comment|/* OpenMP clause: schedule.  */
name|OMP_CLAUSE_SCHEDULE
block|,
comment|/* OpenMP clause: nowait.  */
name|OMP_CLAUSE_NOWAIT
block|,
comment|/* OpenMP clause: ordered.  */
name|OMP_CLAUSE_ORDERED
block|,
comment|/* OpenMP clause: default.  */
name|OMP_CLAUSE_DEFAULT
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* The definition of tree nodes fills the next several pages.  */
end_comment

begin_comment
comment|/* A tree node can represent a data type, a variable, an expression    or a statement.  Each node has a TREE_CODE which says what kind of    thing it represents.  Some common codes are:    INTEGER_TYPE -- represents a type of integers.    ARRAY_TYPE -- represents a type of pointer.    VAR_DECL -- represents a declared variable.    INTEGER_CST -- represents a constant integer value.    PLUS_EXPR -- represents a sum (an expression).     As for the contents of a tree node: there are some fields    that all nodes share.  Each TREE_CODE has various special-purpose    fields as well.  The fields of a node are never accessed directly,    always through accessor macros.  */
end_comment

begin_comment
comment|/* Every kind of tree node starts with this structure,    so all nodes have these fields.     See the accessor macros, defined below, for documentation of the    fields.  */
end_comment

begin_union_decl
union_decl|union
name|tree_ann_d
union_decl|;
end_union_decl

begin_decl_stmt
name|struct
name|tree_common
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|tree
name|chain
decl_stmt|;
name|tree
name|type
decl_stmt|;
name|union
name|tree_ann_d
modifier|*
name|ann
decl_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|tree_code
argument_list|)
name|code
label|:
literal|8
expr_stmt|;
name|unsigned
name|side_effects_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|constant_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|addressable_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|volatile_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|readonly_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|unsigned_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|asm_written_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|nowarning_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|used_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|nothrow_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|static_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|public_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|private_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|protected_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|deprecated_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|invariant_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_0
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_1
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_2
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_3
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_4
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_5
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_6
range|:
literal|1
decl_stmt|;
name|unsigned
name|visited
range|:
literal|1
decl_stmt|;
comment|/* APPLE LOCAL "unavailable" attribute (Radar 2809697) --ilr */
name|unsigned
name|unavailable_flag
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The following table lists the uses of each of the above flags and    for which types of nodes they are defined.  Note that expressions    include decls.     addressable_flag:         TREE_ADDRESSABLE in 	   VAR_DECL, FUNCTION_DECL, FIELD_DECL, CONSTRUCTOR, LABEL_DECL, 	   ..._TYPE, IDENTIFIER_NODE. 	   In a STMT_EXPR, it means we want the result of the enclosed 	   expression.        CALL_EXPR_TAILCALL in CALL_EXPR        CASE_LOW_SEEN in CASE_LABEL_EXPR     static_flag:         TREE_STATIC in            VAR_DECL, FUNCTION_DECL, CONSTRUCTOR, ADDR_EXPR        BINFO_VIRTUAL_P in            TREE_BINFO        TREE_CONSTANT_OVERFLOW in            INTEGER_CST, REAL_CST, COMPLEX_CST, VECTOR_CST        TREE_SYMBOL_REFERENCED in            IDENTIFIER_NODE        CLEANUP_EH_ONLY in            TARGET_EXPR, WITH_CLEANUP_EXPR        ASM_INPUT_P in            ASM_EXPR        EH_FILTER_MUST_NOT_THROW in EH_FILTER_EXPR        TYPE_REF_CAN_ALIAS_ALL in            POINTER_TYPE, REFERENCE_TYPE        CASE_HIGH_SEEN in CASE_LABEL_EXPR     public_flag:         TREE_OVERFLOW in            INTEGER_CST, REAL_CST, COMPLEX_CST, VECTOR_CST        TREE_PUBLIC in            VAR_DECL or FUNCTION_DECL or IDENTIFIER_NODE        ASM_VOLATILE_P in            ASM_EXPR        TYPE_CACHED_VALUES_P in           ..._TYPE        SAVE_EXPR_RESOLVED_P in 	  SAVE_EXPR        OMP_CLAUSE_LASTPRIVATE_FIRSTPRIVATE in 	  OMP_CLAUSE_LASTPRIVATE        OMP_CLAUSE_PRIVATE_DEBUG in 	  OMP_CLAUSE_PRIVATE     private_flag:         TREE_PRIVATE in            ..._DECL        CALL_EXPR_RETURN_SLOT_OPT in            CALL_EXPR        DECL_BY_REFERENCE in            PARM_DECL, RESULT_DECL        OMP_RETURN_NOWAIT in 	   OMP_RETURN        OMP_SECTION_LAST in 	   OMP_SECTION        OMP_PARALLEL_COMBINED in 	   OMP_PARALLEL     protected_flag:         TREE_PROTECTED in            BLOCK 	   ..._DECL        CALL_FROM_THUNK_P in            CALL_EXPR     side_effects_flag:         TREE_SIDE_EFFECTS in            all expressions 	   all decls 	   all constants         FORCED_LABEL in 	   LABEL_DECL     volatile_flag:         TREE_THIS_VOLATILE in            all expressions        TYPE_VOLATILE in            ..._TYPE     readonly_flag:         TREE_READONLY in            all expressions        TYPE_READONLY in            ..._TYPE     constant_flag:         TREE_CONSTANT in            all expressions 	   all decls 	   all constants        TYPE_SIZES_GIMPLIFIED            ..._TYPE     unsigned_flag:         TYPE_UNSIGNED in            all types        DECL_UNSIGNED in            all decls        BIT_FIELD_REF_UNSIGNED in            BIT_FIELD_REF     asm_written_flag:         TREE_ASM_WRITTEN in            VAR_DECL, FUNCTION_DECL, RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE 	   BLOCK, SSA_NAME     used_flag:         TREE_USED in            expressions, IDENTIFIER_NODE     nothrow_flag:         TREE_NOTHROW in            CALL_EXPR, FUNCTION_DECL         TYPE_ALIGN_OK in 	   ..._TYPE         TREE_THIS_NOTRAP in           (ALIGN/MISALIGNED_)INDIRECT_REF, ARRAY_REF, ARRAY_RANGE_REF     deprecated_flag:  	TREE_DEPRECATED in 	   ..._DECL  	IDENTIFIER_TRANSPARENT_ALIAS in 	   IDENTIFIER_NODE     APPLE LOCAL begin "unavailable" attribute (Radar 2809697)    unavailable_flag:  	TREE_UNAVAILABLE in 	   ..._DECL    APPLE LOCAL end "unavailable" attribute (Radar 2809697)     visited:     	Used in tree traversals to mark visited nodes.     invariant_flag:  	TREE_INVARIANT in 	    all expressions.     nowarning_flag:         TREE_NO_WARNING in            ... any expr or decl node */
end_comment

begin_undef
undef|#
directive|undef
name|DEFTREESTRUCT
end_undef

begin_define
define|#
directive|define
name|DEFTREESTRUCT
parameter_list|(
name|ENUM
parameter_list|,
name|NAME
parameter_list|)
value|ENUM,
end_define

begin_enum
enum|enum
name|tree_node_structure_enum
block|{
include|#
directive|include
file|"treestruct.def"
name|LAST_TS_ENUM
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREESTRUCT
end_undef

begin_comment
comment|/* Define accessors for the fields that all tree nodes have    (though some fields are not used for all kinds of nodes).  */
end_comment

begin_comment
comment|/* The tree-code says what kind of node it is.    Codes are defined in tree.def.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CODE
parameter_list|(
name|NODE
parameter_list|)
value|((enum tree_code) (NODE)->common.code)
end_define

begin_define
define|#
directive|define
name|TREE_SET_CODE
parameter_list|(
name|NODE
parameter_list|,
name|VALUE
parameter_list|)
value|((NODE)->common.code = (VALUE))
end_define

begin_comment
comment|/* When checking is enabled, errors will be generated if a tree node    is accessed incorrectly. The macros die with a fatal error.  */
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
name|TREE_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|)
value|__extension__				\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) != (CODE))					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__, 	\ 			 (CODE), 0);					\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|)
value|__extension__				\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) == (CODE))					\       tree_not_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,	\ 			     (CODE), 0);				\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_CHECK2
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|)
value|__extension__			\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) != (CODE1)					\&& TREE_CODE (__t) != (CODE2))					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,		\  			 (CODE1), (CODE2), 0);				\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK2
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|)
value|__extension__			\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) == (CODE1)					\ 	|| TREE_CODE (__t) == (CODE2))					\       tree_not_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,	\ 			     (CODE1), (CODE2), 0);			\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_CHECK3
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|)
value|__extension__		\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) != (CODE1)					\&& TREE_CODE (__t) != (CODE2)					\&& TREE_CODE (__t) != (CODE3))					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,		\ 			     (CODE1), (CODE2), (CODE3), 0);		\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK3
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|)
value|__extension__		\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) == (CODE1)					\ 	|| TREE_CODE (__t) == (CODE2)					\ 	|| TREE_CODE (__t) == (CODE3))					\       tree_not_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,	\ 			     (CODE1), (CODE2), (CODE3), 0);		\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_CHECK4
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|,
name|CODE4
parameter_list|)
value|__extension__	\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) != (CODE1)					\&& TREE_CODE (__t) != (CODE2)					\&& TREE_CODE (__t) != (CODE3)					\&& TREE_CODE (__t) != (CODE4))					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,		\ 			     (CODE1), (CODE2), (CODE3), (CODE4), 0);	\     __t; })
end_define

begin_define
define|#
directive|define
name|NON_TREE_CHECK4
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|,
name|CODE4
parameter_list|)
value|__extension__	\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) == (CODE1)					\ 	|| TREE_CODE (__t) == (CODE2)					\ 	|| TREE_CODE (__t) == (CODE3)					\ 	|| TREE_CODE (__t) == (CODE4))					\       tree_not_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,	\ 			     (CODE1), (CODE2), (CODE3), (CODE4), 0);	\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_CHECK5
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|,
name|CODE4
parameter_list|,
name|CODE5
parameter_list|)
value|__extension__	\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) != (CODE1)					\&& TREE_CODE (__t) != (CODE2)					\&& TREE_CODE (__t) != (CODE3)					\&& TREE_CODE (__t) != (CODE4)					\&& TREE_CODE (__t) != (CODE5))					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,		\ 			     (CODE1), (CODE2), (CODE3), (CODE4), (CODE5), 0);\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK5
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|,
name|CODE4
parameter_list|,
name|CODE5
parameter_list|)
value|__extension__ \ ({  const tree __t = (T);						\     if (TREE_CODE (__t) == (CODE1)					\ 	|| TREE_CODE (__t) == (CODE2)					\ 	|| TREE_CODE (__t) == (CODE3)					\ 	|| TREE_CODE (__t) == (CODE4)					\ 	|| TREE_CODE (__t) == (CODE5))					\       tree_not_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,	\ 			     (CODE1), (CODE2), (CODE3), (CODE4), (CODE5), 0);\     __t; })
end_define

begin_define
define|#
directive|define
name|CONTAINS_STRUCT_CHECK
parameter_list|(
name|T
parameter_list|,
name|STRUCT
parameter_list|)
value|__extension__			\ ({  const tree __t = (T);						\   if (tree_contains_struct[TREE_CODE(__t)][(STRUCT)] != 1)		\       tree_contains_struct_check_failed (__t, (STRUCT), __FILE__, __LINE__,	\ 			       __FUNCTION__);				\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_CLASS_CHECK
parameter_list|(
name|T
parameter_list|,
name|CLASS
parameter_list|)
value|__extension__			\ ({  const tree __t = (T);						\     if (TREE_CODE_CLASS (TREE_CODE(__t)) != (CLASS))			\       tree_class_check_failed (__t, (CLASS), __FILE__, __LINE__,	\ 			       __FUNCTION__);				\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_RANGE_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|)
value|__extension__			\ ({  const tree __t = (T);						\     if (TREE_CODE (__t)< (CODE1) || TREE_CODE (__t)> (CODE2))		\       tree_range_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,	\ 			       (CODE1), (CODE2));			\     __t; })
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_SUBCODE_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|)
value|__extension__			\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) != OMP_CLAUSE)					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,  	\ 			 OMP_CLAUSE, 0);				\     if (__t->omp_clause.code != (CODE))					\       omp_clause_check_failed (__t, __FILE__, __LINE__, __FUNCTION__, 	\ 			       (CODE));					\     __t; })
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_RANGE_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|)
value|__extension__		\ ({  const tree __t = (T);						\     if (TREE_CODE (__t) != OMP_CLAUSE)					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,  	\ 			 OMP_CLAUSE, 0);				\     if ((int) __t->omp_clause.code< (int) (CODE1)			\         || (int) __t->omp_clause.code> (int) (CODE2))			\       omp_clause_range_check_failed (__t, __FILE__, __LINE__,		\ 				     __FUNCTION__, (CODE1), (CODE2));	\     __t; })
end_define

begin_comment
comment|/* These checks have to be special cased.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_CHECK
parameter_list|(
name|T
parameter_list|)
value|__extension__					\ ({  const tree __t = (T);						\     char const __c = TREE_CODE_CLASS (TREE_CODE (__t));			\     if (!IS_EXPR_CODE_CLASS (__c))					\       tree_class_check_failed (__t, tcc_expression, __FILE__, __LINE__,	\ 			       __FUNCTION__);				\     __t; })
end_define

begin_comment
comment|/* These checks have to be special cased.  */
end_comment

begin_define
define|#
directive|define
name|NON_TYPE_CHECK
parameter_list|(
name|T
parameter_list|)
value|__extension__					\ ({  const tree __t = (T);						\     if (TYPE_P (__t))							\       tree_not_class_check_failed (__t, tcc_type, __FILE__, __LINE__,	\ 				   __FUNCTION__);			\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_VEC_ELT_CHECK
parameter_list|(
name|T
parameter_list|,
name|I
parameter_list|)
value|__extension__				\ (*({const tree __t = (T);						\     const int __i = (I);						\     if (TREE_CODE (__t) != TREE_VEC)					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,		\   			 TREE_VEC, 0);					\     if (__i< 0 || __i>= __t->vec.length)				\       tree_vec_elt_check_failed (__i, __t->vec.length,			\ 				 __FILE__, __LINE__, __FUNCTION__);	\&__t->vec.a[__i]; }))
end_define

begin_define
define|#
directive|define
name|PHI_NODE_ELT_CHECK
parameter_list|(
name|t
parameter_list|,
name|i
parameter_list|)
value|__extension__				\ (*({const tree __t = t;							\     const int __i = (i);						\     if (TREE_CODE (__t) != PHI_NODE)					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,  	\ 			 PHI_NODE, 0);					\     if (__i< 0 || __i>= __t->phi.capacity)				\       phi_node_elt_check_failed (__i, __t->phi.num_args,		\ 				 __FILE__, __LINE__, __FUNCTION__);	\&__t->phi.a[__i]; }))
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_ELT_CHECK
parameter_list|(
name|t
parameter_list|,
name|i
parameter_list|)
value|__extension__			\ (*({const tree __t = t;							\     const int __i = (i);						\     if (TREE_CODE (__t) != OMP_CLAUSE)					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__,  	\ 			 OMP_CLAUSE, 0);				\     if (__i< 0 || __i>= omp_clause_num_ops [__t->omp_clause.code])	\       omp_clause_operand_check_failed (__i, __t, __FILE__, __LINE__,	\ 	                               __FUNCTION__);			\&__t->omp_clause.ops[__i]; }))
end_define

begin_comment
comment|/* Special checks for TREE_OPERANDs.  */
end_comment

begin_define
define|#
directive|define
name|TREE_OPERAND_CHECK
parameter_list|(
name|T
parameter_list|,
name|I
parameter_list|)
value|__extension__				\ (*({const tree __t = EXPR_CHECK (T);					\     const int __i = (I);						\     if (__i< 0 || __i>= TREE_CODE_LENGTH (TREE_CODE (__t)))		\       tree_operand_check_failed (__i, TREE_CODE (__t),			\ 				 __FILE__, __LINE__, __FUNCTION__);	\&__t->exp.operands[__i]; }))
end_define

begin_define
define|#
directive|define
name|TREE_OPERAND_CHECK_CODE
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|,
name|I
parameter_list|)
value|__extension__		\ (*({const tree __t = (T);						\     const int __i = (I);						\     if (TREE_CODE (__t) != CODE)					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__, (CODE), 0);\     if (__i< 0 || __i>= TREE_CODE_LENGTH (CODE))			\       tree_operand_check_failed (__i, (CODE),				\ 				 __FILE__, __LINE__, __FUNCTION__);	\&__t->exp.operands[__i]; }))
end_define

begin_define
define|#
directive|define
name|TREE_RTL_OPERAND_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|,
name|I
parameter_list|)
value|__extension__		\ (*(rtx *)								\  ({const tree __t = (T);						\     const int __i = (I);						\     if (TREE_CODE (__t) != (CODE))					\       tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__, (CODE), 0); \     if (__i< 0 || __i>= TREE_CODE_LENGTH ((CODE)))			\       tree_operand_check_failed (__i, (CODE),				\ 				 __FILE__, __LINE__, __FUNCTION__);	\&__t->exp.operands[__i]; }))
end_define

begin_decl_stmt
specifier|extern
name|void
name|tree_contains_struct_check_failed
argument_list|(
specifier|const
name|tree
argument_list|,
specifier|const
expr|enum
name|tree_node_structure_enum
argument_list|,
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

begin_decl_stmt
specifier|extern
name|void
name|tree_check_failed
argument_list|(
specifier|const
name|tree
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tree_not_check_failed
argument_list|(
specifier|const
name|tree
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tree_class_check_failed
argument_list|(
specifier|const
name|tree
argument_list|,
specifier|const
expr|enum
name|tree_code_class
argument_list|,
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
name|void
name|tree_range_check_failed
parameter_list|(
specifier|const
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|tree_not_class_check_failed
argument_list|(
specifier|const
name|tree
argument_list|,
specifier|const
expr|enum
name|tree_code_class
argument_list|,
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

begin_decl_stmt
specifier|extern
name|void
name|tree_vec_elt_check_failed
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
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

begin_decl_stmt
specifier|extern
name|void
name|phi_node_elt_check_failed
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
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

begin_decl_stmt
specifier|extern
name|void
name|tree_operand_check_failed
argument_list|(
name|int
argument_list|,
expr|enum
name|tree_code
argument_list|,
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

begin_decl_stmt
specifier|extern
name|void
name|omp_clause_check_failed
argument_list|(
specifier|const
name|tree
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
expr|enum
name|omp_clause_code
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|omp_clause_operand_check_failed
argument_list|(
name|int
argument_list|,
name|tree
argument_list|,
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

begin_decl_stmt
specifier|extern
name|void
name|omp_clause_range_check_failed
argument_list|(
specifier|const
name|tree
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
expr|enum
name|omp_clause_code
argument_list|,
expr|enum
name|omp_clause_code
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

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
name|CONTAINS_STRUCT_CHECK
parameter_list|(
name|T
parameter_list|,
name|ENUM
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_CHECK2
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK2
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_CHECK3
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK3
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_CHECK4
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|,
name|CODE4
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK4
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|,
name|CODE4
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_CHECK5
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|,
name|CODE4
parameter_list|,
name|CODE5
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_NOT_CHECK5
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|,
name|CODE3
parameter_list|,
name|CODE4
parameter_list|,
name|CODE5
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_CLASS_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_RANGE_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|EXPR_CHECK
parameter_list|(
name|T
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|NON_TYPE_CHECK
parameter_list|(
name|T
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|TREE_VEC_ELT_CHECK
parameter_list|(
name|T
parameter_list|,
name|I
parameter_list|)
value|((T)->vec.a[I])
end_define

begin_define
define|#
directive|define
name|TREE_OPERAND_CHECK
parameter_list|(
name|T
parameter_list|,
name|I
parameter_list|)
value|((T)->exp.operands[I])
end_define

begin_define
define|#
directive|define
name|TREE_OPERAND_CHECK_CODE
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|,
name|I
parameter_list|)
value|((T)->exp.operands[I])
end_define

begin_define
define|#
directive|define
name|TREE_RTL_OPERAND_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|,
name|I
parameter_list|)
value|(*(rtx *)&((T)->exp.operands[I]))
end_define

begin_define
define|#
directive|define
name|PHI_NODE_ELT_CHECK
parameter_list|(
name|T
parameter_list|,
name|i
parameter_list|)
value|((T)->phi.a[i])
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_ELT_CHECK
parameter_list|(
name|T
parameter_list|,
name|i
parameter_list|)
value|((T)->omp_clause.ops[i])
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_RANGE_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE1
parameter_list|,
name|CODE2
parameter_list|)
value|(T)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_SUBCODE_CHECK
parameter_list|(
name|T
parameter_list|,
name|CODE
parameter_list|)
value|(T)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TREE_BLOCK
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_CHECK (NODE)->exp.block)
end_define

begin_include
include|#
directive|include
file|"tree-check.h"
end_include

begin_define
define|#
directive|define
name|TYPE_CHECK
parameter_list|(
name|T
parameter_list|)
value|TREE_CLASS_CHECK (T, tcc_type)
end_define

begin_define
define|#
directive|define
name|DECL_MINIMAL_CHECK
parameter_list|(
name|T
parameter_list|)
value|CONTAINS_STRUCT_CHECK (T, TS_DECL_MINIMAL)
end_define

begin_define
define|#
directive|define
name|TREE_MEMORY_TAG_CHECK
parameter_list|(
name|T
parameter_list|)
value|CONTAINS_STRUCT_CHECK (T, TS_MEMORY_TAG)
end_define

begin_define
define|#
directive|define
name|DECL_COMMON_CHECK
parameter_list|(
name|T
parameter_list|)
value|CONTAINS_STRUCT_CHECK (T, TS_DECL_COMMON)
end_define

begin_define
define|#
directive|define
name|DECL_WRTL_CHECK
parameter_list|(
name|T
parameter_list|)
value|CONTAINS_STRUCT_CHECK (T, TS_DECL_WRTL)
end_define

begin_define
define|#
directive|define
name|DECL_WITH_VIS_CHECK
parameter_list|(
name|T
parameter_list|)
value|CONTAINS_STRUCT_CHECK (T, TS_DECL_WITH_VIS)
end_define

begin_define
define|#
directive|define
name|DECL_NON_COMMON_CHECK
parameter_list|(
name|T
parameter_list|)
value|CONTAINS_STRUCT_CHECK (T, TS_DECL_NON_COMMON)
end_define

begin_define
define|#
directive|define
name|CST_CHECK
parameter_list|(
name|T
parameter_list|)
value|TREE_CLASS_CHECK (T, tcc_constant)
end_define

begin_define
define|#
directive|define
name|STMT_CHECK
parameter_list|(
name|T
parameter_list|)
value|TREE_CLASS_CHECK (T, tcc_statement)
end_define

begin_define
define|#
directive|define
name|FUNC_OR_METHOD_CHECK
parameter_list|(
name|T
parameter_list|)
value|TREE_CHECK2 (T, FUNCTION_TYPE, METHOD_TYPE)
end_define

begin_define
define|#
directive|define
name|PTR_OR_REF_CHECK
parameter_list|(
name|T
parameter_list|)
value|TREE_CHECK2 (T, POINTER_TYPE, REFERENCE_TYPE)
end_define

begin_define
define|#
directive|define
name|RECORD_OR_UNION_CHECK
parameter_list|(
name|T
parameter_list|)
define|\
value|TREE_CHECK3 (T, RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE)
end_define

begin_define
define|#
directive|define
name|NOT_RECORD_OR_UNION_CHECK
parameter_list|(
name|T
parameter_list|)
define|\
value|TREE_NOT_CHECK3 (T, RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE)
end_define

begin_define
define|#
directive|define
name|NUMERICAL_TYPE_CHECK
parameter_list|(
name|T
parameter_list|)
define|\
value|TREE_CHECK4 (T, INTEGER_TYPE, ENUMERAL_TYPE, BOOLEAN_TYPE, REAL_TYPE)
end_define

begin_comment
comment|/* In all nodes that are expressions, this is the data type of the expression.    In POINTER_TYPE nodes, this is the type that the pointer points to.    In ARRAY_TYPE nodes, this is the type of the elements.    In VECTOR_TYPE nodes, this is the type of the elements.  */
end_comment

begin_define
define|#
directive|define
name|TREE_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.type)
end_define

begin_comment
comment|/* Here is how primitive or already-canonicalized types' hash codes    are made.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_HASH
parameter_list|(
name|TYPE
parameter_list|)
value|(TYPE_UID (TYPE))
end_define

begin_comment
comment|/* A simple hash function for an arbitrary tree node.  This must not be    used in hash tables which are saved to a PCH.  */
end_comment

begin_define
define|#
directive|define
name|TREE_HASH
parameter_list|(
name|NODE
parameter_list|)
value|((size_t) (NODE)& 0777777)
end_define

begin_comment
comment|/* Nodes are chained together for many purposes.    Types are chained together to record them for being output to the debugger    (see the function `chain_type').    Decls in the same scope are chained together to record the contents    of the scope.    Statement nodes for successive statements used to be chained together.    Often lists of things are represented by TREE_LIST nodes that    are chained together.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.chain)
end_define

begin_comment
comment|/* Given an expression as a tree, strip any NON_LVALUE_EXPRs and NOP_EXPRs    that don't change the machine mode.  */
end_comment

begin_define
define|#
directive|define
name|STRIP_NOPS
parameter_list|(
name|EXP
parameter_list|)
define|\
value|while ((TREE_CODE (EXP) == NOP_EXPR				\ 	  || TREE_CODE (EXP) == CONVERT_EXPR			\ 	  || TREE_CODE (EXP) == NON_LVALUE_EXPR)		\&& TREE_OPERAND (EXP, 0) != error_mark_node		\&& (TYPE_MODE (TREE_TYPE (EXP))			\ 	     == TYPE_MODE (TREE_TYPE (TREE_OPERAND (EXP, 0)))))	\     (EXP) = TREE_OPERAND (EXP, 0)
end_define

begin_comment
comment|/* Like STRIP_NOPS, but don't let the signedness change either.  */
end_comment

begin_define
define|#
directive|define
name|STRIP_SIGN_NOPS
parameter_list|(
name|EXP
parameter_list|)
define|\
value|while ((TREE_CODE (EXP) == NOP_EXPR				\ 	  || TREE_CODE (EXP) == CONVERT_EXPR			\ 	  || TREE_CODE (EXP) == NON_LVALUE_EXPR)		\&& TREE_OPERAND (EXP, 0) != error_mark_node		\&& (TYPE_MODE (TREE_TYPE (EXP))			\ 	     == TYPE_MODE (TREE_TYPE (TREE_OPERAND (EXP, 0))))	\&& (TYPE_UNSIGNED (TREE_TYPE (EXP))			\ 	     == TYPE_UNSIGNED (TREE_TYPE (TREE_OPERAND (EXP, 0))))) \     (EXP) = TREE_OPERAND (EXP, 0)
end_define

begin_comment
comment|/* Like STRIP_NOPS, but don't alter the TREE_TYPE either.  */
end_comment

begin_define
define|#
directive|define
name|STRIP_TYPE_NOPS
parameter_list|(
name|EXP
parameter_list|)
define|\
value|while ((TREE_CODE (EXP) == NOP_EXPR				\ 	  || TREE_CODE (EXP) == CONVERT_EXPR			\ 	  || TREE_CODE (EXP) == NON_LVALUE_EXPR)		\&& TREE_OPERAND (EXP, 0) != error_mark_node		\&& (TREE_TYPE (EXP)					\ 	     == TREE_TYPE (TREE_OPERAND (EXP, 0))))		\     (EXP) = TREE_OPERAND (EXP, 0)
end_define

begin_comment
comment|/* Remove unnecessary type conversions according to    tree_ssa_useless_type_conversion.  */
end_comment

begin_define
define|#
directive|define
name|STRIP_USELESS_TYPE_CONVERSION
parameter_list|(
name|EXP
parameter_list|)
define|\
value|while (tree_ssa_useless_type_conversion (EXP))			\ 	EXP = TREE_OPERAND (EXP, 0)
end_define

begin_comment
comment|/* Nonzero if TYPE represents an integral type.  Note that we do not    include COMPLEX types here.  Keep these checks in ascending code    order.  */
end_comment

begin_define
define|#
directive|define
name|INTEGRAL_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == ENUMERAL_TYPE  \    || TREE_CODE (TYPE) == BOOLEAN_TYPE \    || TREE_CODE (TYPE) == INTEGER_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents a scalar floating-point type.  */
end_comment

begin_define
define|#
directive|define
name|SCALAR_FLOAT_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
value|(TREE_CODE (TYPE) == REAL_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents a complex floating-point type.  */
end_comment

begin_define
define|#
directive|define
name|COMPLEX_FLOAT_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == COMPLEX_TYPE	\&& TREE_CODE (TREE_TYPE (TYPE)) == REAL_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents a vector floating-point type.  */
end_comment

begin_define
define|#
directive|define
name|VECTOR_FLOAT_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == VECTOR_TYPE	\&& TREE_CODE (TREE_TYPE (TYPE)) == REAL_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents a floating-point type, including complex    and vector floating-point types.  The vector and complex check does    not use the previous two macros to enable early folding.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(SCALAR_FLOAT_TYPE_P (TYPE)			\    || ((TREE_CODE (TYPE) == COMPLEX_TYPE 	\         || TREE_CODE (TYPE) == VECTOR_TYPE)	\&& SCALAR_FLOAT_TYPE_P (TREE_TYPE (TYPE))))
end_define

begin_comment
comment|/* Nonzero if TYPE represents a decimal floating-point type.  */
end_comment

begin_define
define|#
directive|define
name|DECIMAL_FLOAT_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(SCALAR_FLOAT_TYPE_P (TYPE)			\&& DECIMAL_FLOAT_MODE_P (TYPE_MODE (TYPE)))
end_define

begin_comment
comment|/* Nonzero if TYPE represents an aggregate (multi-component) type.    Keep these checks in ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|AGGREGATE_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == ARRAY_TYPE || TREE_CODE (TYPE) == RECORD_TYPE \    || TREE_CODE (TYPE) == UNION_TYPE || TREE_CODE (TYPE) == QUAL_UNION_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents a pointer or reference type.    (It should be renamed to INDIRECT_TYPE_P.)  Keep these checks in    ascending code order.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == POINTER_TYPE || TREE_CODE (TYPE) == REFERENCE_TYPE)
end_define

begin_comment
comment|/* Nonzero if this type is a complete type.  */
end_comment

begin_define
define|#
directive|define
name|COMPLETE_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_SIZE (NODE) != NULL_TREE)
end_define

begin_comment
comment|/* Nonzero if this type is the (possibly qualified) void type.  */
end_comment

begin_define
define|#
directive|define
name|VOID_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CODE (NODE) == VOID_TYPE)
end_define

begin_comment
comment|/* Nonzero if this type is complete or is cv void.  */
end_comment

begin_define
define|#
directive|define
name|COMPLETE_OR_VOID_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(COMPLETE_TYPE_P (NODE) || VOID_TYPE_P (NODE))
end_define

begin_comment
comment|/* Nonzero if this type is complete or is an array with unspecified bound.  */
end_comment

begin_define
define|#
directive|define
name|COMPLETE_OR_UNBOUND_ARRAY_TYPE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(COMPLETE_TYPE_P (TREE_CODE (NODE) == ARRAY_TYPE ? TREE_TYPE (NODE) : (NODE)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define many boolean fields that all tree nodes have.  */
end_comment

begin_comment
comment|/* In VAR_DECL nodes, nonzero means address of this is needed.    So it cannot be in a register.    In a FUNCTION_DECL, nonzero means its address is needed.    So it must be compiled even if it is an inline function.    In a FIELD_DECL node, it means that the programmer is permitted to    construct the address of this field.  This is used for aliasing    purposes: see record_component_aliases.    In CONSTRUCTOR nodes, it means object constructed must be in memory.    In LABEL_DECL nodes, it means a goto for this label has been seen    from a place outside all binding contours that restore stack levels.    In ..._TYPE nodes, it means that objects of this type must    be fully addressable.  This means that pieces of this    object cannot go into register parameters, for example.    In IDENTIFIER_NODEs, this means that some extern decl for this name    had its address taken.  That matters for inline functions.  */
end_comment

begin_define
define|#
directive|define
name|TREE_ADDRESSABLE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.addressable_flag)
end_define

begin_comment
comment|/* Set on a CALL_EXPR if the call is in a tail position, ie. just before the    exit of a function.  Calls for which this is true are candidates for tail    call optimizations.  */
end_comment

begin_define
define|#
directive|define
name|CALL_EXPR_TAILCALL
parameter_list|(
name|NODE
parameter_list|)
value|(CALL_EXPR_CHECK(NODE)->common.addressable_flag)
end_define

begin_comment
comment|/* Used as a temporary field on a CASE_LABEL_EXPR to indicate that the    CASE_LOW operand has been processed.  */
end_comment

begin_define
define|#
directive|define
name|CASE_LOW_SEEN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CASE_LABEL_EXPR_CHECK (NODE)->common.addressable_flag)
end_define

begin_comment
comment|/* In a VAR_DECL, nonzero means allocate static storage.    In a FUNCTION_DECL, nonzero if function has been defined.    In a CONSTRUCTOR, nonzero means allocate static storage.     ??? This is also used in lots of other nodes in unclear ways which    should be cleaned up some day.  */
end_comment

begin_define
define|#
directive|define
name|TREE_STATIC
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.static_flag)
end_define

begin_comment
comment|/* In a TARGET_EXPR, WITH_CLEANUP_EXPR, means that the pertinent cleanup    should only be executed if an exception is thrown, not on normal exit    of its scope.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_EH_ONLY
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.static_flag)
end_define

begin_comment
comment|/* Used as a temporary field on a CASE_LABEL_EXPR to indicate that the    CASE_HIGH operand has been processed.  */
end_comment

begin_define
define|#
directive|define
name|CASE_HIGH_SEEN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CASE_LABEL_EXPR_CHECK (NODE)->common.static_flag)
end_define

begin_comment
comment|/* In an expr node (usually a conversion) this means the node was made    implicitly and should not lead to any sort of warning.  In a decl node,    warnings concerning the decl should be suppressed.  This is used at    least for used-before-set warnings, and it set after one warning is    emitted.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NO_WARNING
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.nowarning_flag)
end_define

begin_comment
comment|/* In an INTEGER_CST, REAL_CST, COMPLEX_CST, or VECTOR_CST this means    there was an overflow in folding.  This is distinct from    TREE_OVERFLOW because ANSI C requires a diagnostic when overflows    occur in constant expressions.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CONSTANT_OVERFLOW
parameter_list|(
name|NODE
parameter_list|)
value|(CST_CHECK (NODE)->common.static_flag)
end_define

begin_comment
comment|/* In an IDENTIFIER_NODE, this means that assemble_name was called with    this string as an argument.  */
end_comment

begin_define
define|#
directive|define
name|TREE_SYMBOL_REFERENCED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_NODE_CHECK (NODE)->common.static_flag)
end_define

begin_comment
comment|/* Nonzero in a pointer or reference type means the data pointed to    by this type can alias anything.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_REF_CAN_ALIAS_ALL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(PTR_OR_REF_CHECK (NODE)->common.static_flag)
end_define

begin_comment
comment|/* In an INTEGER_CST, REAL_CST, COMPLEX_CST, or VECTOR_CST, this means    there was an overflow in folding, and no warning has been issued    for this subexpression.  TREE_OVERFLOW implies TREE_CONSTANT_OVERFLOW,    but not vice versa.  */
end_comment

begin_define
define|#
directive|define
name|TREE_OVERFLOW
parameter_list|(
name|NODE
parameter_list|)
value|(CST_CHECK (NODE)->common.public_flag)
end_define

begin_comment
comment|/* TREE_OVERFLOW can only be true for EXPR of CONSTANT_CLASS_P. */
end_comment

begin_define
define|#
directive|define
name|TREE_OVERFLOW_P
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|(CONSTANT_CLASS_P (EXPR)&& TREE_OVERFLOW (EXPR))
end_define

begin_comment
comment|/* In a VAR_DECL, FUNCTION_DECL, NAMESPACE_DECL or TYPE_DECL,    nonzero means name is to be accessible from outside this module.    In an IDENTIFIER_NODE, nonzero means an external declaration    accessible from outside this module was previously seen    for this name in an inner scope.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PUBLIC
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.public_flag)
end_define

begin_comment
comment|/* In a _TYPE, indicates whether TYPE_CACHED_VALUES contains a vector    of cached values, or is something else.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_CACHED_VALUES_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK(NODE)->common.public_flag)
end_define

begin_comment
comment|/* In a SAVE_EXPR, indicates that the original expression has already    been substituted with a VAR_DECL that contains the value.  */
end_comment

begin_define
define|#
directive|define
name|SAVE_EXPR_RESOLVED_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CHECK (NODE, SAVE_EXPR)->common.public_flag)
end_define

begin_comment
comment|/* In any expression, decl, or constant, nonzero means it has side effects or    reevaluation of the whole expression could produce a different value.    This is set if any subexpression is a function call, a side effect or a    reference to a volatile variable.  In a ..._DECL, this is set only if the    declaration said `volatile'.  This will never be set for a constant.  */
end_comment

begin_define
define|#
directive|define
name|TREE_SIDE_EFFECTS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(NON_TYPE_CHECK (NODE)->common.side_effects_flag)
end_define

begin_comment
comment|/* In a LABEL_DECL, nonzero means this label had its address taken    and therefore can never be deleted and is a jump target for    computed gotos.  */
end_comment

begin_define
define|#
directive|define
name|FORCED_LABEL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.side_effects_flag)
end_define

begin_comment
comment|/* Nonzero means this expression is volatile in the C sense:    its address should be of type `volatile WHATEVER *'.    In other words, the declared item is volatile qualified.    This is used in _DECL nodes and _REF nodes.    On a FUNCTION_DECL node, this means the function does not    return normally.  This is the same effect as setting    the attribute noreturn on the function in C.     In a ..._TYPE node, means this type is volatile-qualified.    But use TYPE_VOLATILE instead of this macro when the node is a type,    because eventually we may make that a different bit.     If this bit is set in an expression, so is TREE_SIDE_EFFECTS.  */
end_comment

begin_define
define|#
directive|define
name|TREE_THIS_VOLATILE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.volatile_flag)
end_define

begin_comment
comment|/* Nonzero means this node will not trap.  In an INDIRECT_REF, means    accessing the memory pointed to won't generate a trap.  However,    this only applies to an object when used appropriately: it doesn't    mean that writing a READONLY mem won't trap. Similarly for    ALIGN_INDIRECT_REF and MISALIGNED_INDIRECT_REF.     In ARRAY_REF and ARRAY_RANGE_REF means that we know that the index    (or slice of the array) always belongs to the range of the array.    I.e. that the access will not trap, provided that the access to    the base to the array will not trap.  */
end_comment

begin_define
define|#
directive|define
name|TREE_THIS_NOTRAP
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.nothrow_flag)
end_define

begin_comment
comment|/* In a VAR_DECL, PARM_DECL or FIELD_DECL, or any kind of ..._REF node,    nonzero means it may not be the lhs of an assignment.  */
end_comment

begin_define
define|#
directive|define
name|TREE_READONLY
parameter_list|(
name|NODE
parameter_list|)
value|(NON_TYPE_CHECK (NODE)->common.readonly_flag)
end_define

begin_comment
comment|/* Nonzero if NODE is a _DECL with TREE_READONLY set.  */
end_comment

begin_define
define|#
directive|define
name|TREE_READONLY_DECL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_P (NODE)&& TREE_READONLY (NODE))
end_define

begin_comment
comment|/* Value of expression is constant.  Always on in all ..._CST nodes.  May    also appear in an expression or decl where the value is constant.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CONSTANT
parameter_list|(
name|NODE
parameter_list|)
value|(NON_TYPE_CHECK (NODE)->common.constant_flag)
end_define

begin_comment
comment|/* Nonzero if NODE, a type, has had its sizes gimplified.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SIZES_GIMPLIFIED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->common.constant_flag)
end_define

begin_comment
comment|/* In a decl (most significantly a FIELD_DECL), means an unsigned field.  */
end_comment

begin_define
define|#
directive|define
name|DECL_UNSIGNED
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->common.unsigned_flag)
end_define

begin_comment
comment|/* In a BIT_FIELD_REF, means the bitfield is to be interpreted as unsigned.  */
end_comment

begin_define
define|#
directive|define
name|BIT_FIELD_REF_UNSIGNED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(BIT_FIELD_REF_CHECK (NODE)->common.unsigned_flag)
end_define

begin_comment
comment|/* In integral and pointer types, means an unsigned type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_UNSIGNED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->common.unsigned_flag)
end_define

begin_comment
comment|/* Nonzero in a VAR_DECL means assembler code has been written.    Nonzero in a FUNCTION_DECL means that the function has been compiled.    This is interesting in an inline function, since it might not need    to be compiled separately.    Nonzero in a RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE or ENUMERAL_TYPE    if the sdb debugging info for the type has been written.    In a BLOCK node, nonzero if reorder_blocks has already seen this block.    In an SSA_NAME node, nonzero if the SSA_NAME occurs in an abnormal    PHI node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_ASM_WRITTEN
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.asm_written_flag)
end_define

begin_comment
comment|/* Nonzero in a _DECL if the name is used in its scope.    Nonzero in an expr node means inhibit warning if value is unused.    In IDENTIFIER_NODEs, this means that some extern decl for this name    was used.    In a BLOCK, this means that the block contains variables that are used.  */
end_comment

begin_define
define|#
directive|define
name|TREE_USED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.used_flag)
end_define

begin_comment
comment|/* In a FUNCTION_DECL, nonzero means a call to the function cannot throw    an exception.  In a CALL_EXPR, nonzero means the call cannot throw.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NOTHROW
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.nothrow_flag)
end_define

begin_comment
comment|/* In a CALL_EXPR, means that it's safe to use the target of the call    expansion as the return slot for a call that returns in memory.  */
end_comment

begin_define
define|#
directive|define
name|CALL_EXPR_RETURN_SLOT_OPT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.private_flag)
end_define

begin_comment
comment|/* In a RESULT_DECL or PARM_DECL, means that it is passed by invisible    reference (and the TREE_TYPE is a pointer to the true type).  */
end_comment

begin_define
define|#
directive|define
name|DECL_BY_REFERENCE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->common.private_flag)
end_define

begin_comment
comment|/* In a CALL_EXPR, means that the call is the jump from a thunk to the    thunked-to function.  */
end_comment

begin_define
define|#
directive|define
name|CALL_FROM_THUNK_P
parameter_list|(
name|NODE
parameter_list|)
value|(CALL_EXPR_CHECK (NODE)->common.protected_flag)
end_define

begin_comment
comment|/* In a type, nonzero means that all objects of the type are guaranteed by the    language or front-end to be properly aligned, so we can indicate that a MEM    of this type is aligned at least to the alignment of the type, even if it    doesn't appear that it is.  We see this, for example, in object-oriented    languages where a tag field may show this is an object of a more-aligned    variant of the more generic type.     In an SSA_NAME node, nonzero if the SSA_NAME node is on the SSA_NAME    freelist.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ALIGN_OK
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->common.nothrow_flag)
end_define

begin_comment
comment|/* Used in classes in C++.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PRIVATE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.private_flag)
end_define

begin_comment
comment|/* Used in classes in C++.    In a BLOCK node, this is BLOCK_HANDLER_BLOCK.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PROTECTED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.protected_flag)
end_define

begin_comment
comment|/* Nonzero in a _DECL if the use of the name is defined as a    deprecated feature by __attribute__((deprecated)).  */
end_comment

begin_define
define|#
directive|define
name|TREE_DEPRECATED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((NODE)->common.deprecated_flag)
end_define

begin_comment
comment|/* APPLE LOCAL begin "unavailable" attribute (Radar 2809697) */
end_comment

begin_comment
comment|/* Nonzero in a IDENTIFIER_NODE if the use of the name is defined as a    unavailable feature by __attribute__((unavailable)).  */
end_comment

begin_define
define|#
directive|define
name|TREE_UNAVAILABLE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.unavailable_flag)
end_define

begin_comment
comment|/* APPLE LOCAL end "unavailable" attribute (Radar 2809697) */
end_comment

begin_comment
comment|/* Nonzero in an IDENTIFIER_NODE if the name is a local alias, whose    uses are to be substituted for uses of the TREE_CHAINed identifier.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_TRANSPARENT_ALIAS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_NODE_CHECK (NODE)->common.deprecated_flag)
end_define

begin_comment
comment|/* Value of expression is function invariant.  A strict subset of    TREE_CONSTANT, such an expression is constant over any one function    invocation, though not across different invocations.  May appear in    any expression node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_INVARIANT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.invariant_flag)
end_define

begin_comment
comment|/* These flags are available for each language front end to use internally.  */
end_comment

begin_define
define|#
directive|define
name|TREE_LANG_FLAG_0
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.lang_flag_0)
end_define

begin_define
define|#
directive|define
name|TREE_LANG_FLAG_1
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.lang_flag_1)
end_define

begin_define
define|#
directive|define
name|TREE_LANG_FLAG_2
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.lang_flag_2)
end_define

begin_define
define|#
directive|define
name|TREE_LANG_FLAG_3
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.lang_flag_3)
end_define

begin_define
define|#
directive|define
name|TREE_LANG_FLAG_4
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.lang_flag_4)
end_define

begin_define
define|#
directive|define
name|TREE_LANG_FLAG_5
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.lang_flag_5)
end_define

begin_define
define|#
directive|define
name|TREE_LANG_FLAG_6
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.lang_flag_6)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define additional fields and accessors for nodes representing constants.  */
end_comment

begin_comment
comment|/* In an INTEGER_CST node.  These two together make a 2-word integer.    If the data type is signed, the value is sign-extended to 2 words    even though not all of them may really be in use.    In an unsigned constant shorter than 2 words, the extra bits are 0.  */
end_comment

begin_define
define|#
directive|define
name|TREE_INT_CST
parameter_list|(
name|NODE
parameter_list|)
value|(INTEGER_CST_CHECK (NODE)->int_cst.int_cst)
end_define

begin_define
define|#
directive|define
name|TREE_INT_CST_LOW
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_INT_CST (NODE).low)
end_define

begin_define
define|#
directive|define
name|TREE_INT_CST_HIGH
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_INT_CST (NODE).high)
end_define

begin_define
define|#
directive|define
name|INT_CST_LT
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|(TREE_INT_CST_HIGH (A)< TREE_INT_CST_HIGH (B)	\    || (TREE_INT_CST_HIGH (A) == TREE_INT_CST_HIGH (B)	\&& TREE_INT_CST_LOW (A)< TREE_INT_CST_LOW (B)))
end_define

begin_define
define|#
directive|define
name|INT_CST_LT_UNSIGNED
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|(((unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (A)		\< (unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (B))		\    || (((unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (A)		\ 	== (unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (B))	\&& TREE_INT_CST_LOW (A)< TREE_INT_CST_LOW (B)))
end_define

begin_decl_stmt
name|struct
name|tree_int_cst
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
name|double_int
name|int_cst
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In a REAL_CST node.  struct real_value is an opaque entity, with    manipulators defined in real.h.  We don't want tree.h depending on    real.h and transitively on tm.h.  */
end_comment

begin_struct_decl
struct_decl|struct
name|real_value
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|TREE_REAL_CST_PTR
parameter_list|(
name|NODE
parameter_list|)
value|(REAL_CST_CHECK (NODE)->real_cst.real_cst_ptr)
end_define

begin_define
define|#
directive|define
name|TREE_REAL_CST
parameter_list|(
name|NODE
parameter_list|)
value|(*TREE_REAL_CST_PTR (NODE))
end_define

begin_decl_stmt
name|struct
name|tree_real_cst
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
name|real_value
modifier|*
name|real_cst_ptr
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In a STRING_CST */
end_comment

begin_define
define|#
directive|define
name|TREE_STRING_LENGTH
parameter_list|(
name|NODE
parameter_list|)
value|(STRING_CST_CHECK (NODE)->string.length)
end_define

begin_define
define|#
directive|define
name|TREE_STRING_POINTER
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((const char *)(STRING_CST_CHECK (NODE)->string.str))
end_define

begin_decl_stmt
name|struct
name|tree_string
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
name|int
name|length
decl_stmt|;
name|char
name|str
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
comment|/* In a COMPLEX_CST node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_REALPART
parameter_list|(
name|NODE
parameter_list|)
value|(COMPLEX_CST_CHECK (NODE)->complex.real)
end_define

begin_define
define|#
directive|define
name|TREE_IMAGPART
parameter_list|(
name|NODE
parameter_list|)
value|(COMPLEX_CST_CHECK (NODE)->complex.imag)
end_define

begin_decl_stmt
name|struct
name|tree_complex
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
name|real
decl_stmt|;
name|tree
name|imag
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In a VECTOR_CST node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VECTOR_CST_ELTS
parameter_list|(
name|NODE
parameter_list|)
value|(VECTOR_CST_CHECK (NODE)->vector.elements)
end_define

begin_decl_stmt
name|struct
name|tree_vector
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
name|elements
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_comment
comment|/* Define fields and accessors for some special-purpose tree nodes.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_LENGTH
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_NODE_CHECK (NODE)->identifier.id.len)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_POINTER
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((const char *) IDENTIFIER_NODE_CHECK (NODE)->identifier.id.str)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_HASH_VALUE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(IDENTIFIER_NODE_CHECK (NODE)->identifier.id.hash_value)
end_define

begin_comment
comment|/* Translate a hash table identifier pointer to a tree_identifier    pointer, and vice versa.  */
end_comment

begin_define
define|#
directive|define
name|HT_IDENT_TO_GCC_IDENT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((tree) ((char *) (NODE) - sizeof (struct tree_common)))
end_define

begin_define
define|#
directive|define
name|GCC_IDENT_TO_HT_IDENT
parameter_list|(
name|NODE
parameter_list|)
value|(&((struct tree_identifier *) (NODE))->id)
end_define

begin_decl_stmt
name|struct
name|tree_identifier
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
name|ht_identifier
name|id
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In a TREE_LIST node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PURPOSE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LIST_CHECK (NODE)->list.purpose)
end_define

begin_define
define|#
directive|define
name|TREE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_LIST_CHECK (NODE)->list.value)
end_define

begin_decl_stmt
name|struct
name|tree_list
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
name|purpose
decl_stmt|;
name|tree
name|value
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In a TREE_VEC node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VEC_LENGTH
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_VEC_CHECK (NODE)->vec.length)
end_define

begin_define
define|#
directive|define
name|TREE_VEC_END
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((void) TREE_VEC_CHECK (NODE),&((NODE)->vec.a[(NODE)->vec.length]))
end_define

begin_define
define|#
directive|define
name|TREE_VEC_ELT
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
value|TREE_VEC_ELT_CHECK (NODE, I)
end_define

begin_decl_stmt
name|struct
name|tree_vec
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
name|int
name|length
decl_stmt|;
name|tree
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"TREE_VEC_LENGTH ((tree)&%h)"
argument_list|)
operator|)
argument_list|)
name|a
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
comment|/* In a CONSTRUCTOR node.  */
end_comment

begin_define
define|#
directive|define
name|CONSTRUCTOR_ELTS
parameter_list|(
name|NODE
parameter_list|)
value|(CONSTRUCTOR_CHECK (NODE)->constructor.elts)
end_define

begin_comment
comment|/* Iterate through the vector V of CONSTRUCTOR_ELT elements, yielding the    value of each element (stored within VAL). IX must be a scratch variable    of unsigned integer type.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_CONSTRUCTOR_VALUE
parameter_list|(
name|V
parameter_list|,
name|IX
parameter_list|,
name|VAL
parameter_list|)
define|\
value|for (IX = 0; (IX>= VEC_length (constructor_elt, V)) \ 	       ? false \ 	       : ((VAL = VEC_index (constructor_elt, V, IX)->value), \ 	       true); \        (IX)++)
end_define

begin_comment
comment|/* Iterate through the vector V of CONSTRUCTOR_ELT elements, yielding both    the value of each element (stored within VAL) and its index (stored    within INDEX). IX must be a scratch variable of unsigned integer type.  */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_CONSTRUCTOR_ELT
parameter_list|(
name|V
parameter_list|,
name|IX
parameter_list|,
name|INDEX
parameter_list|,
name|VAL
parameter_list|)
define|\
value|for (IX = 0; (IX>= VEC_length (constructor_elt, V)) \ 	       ? false \ 	       : ((VAL = VEC_index (constructor_elt, V, IX)->value), \ 		  (INDEX = VEC_index (constructor_elt, V, IX)->index), \ 	       true); \        (IX)++)
end_define

begin_comment
comment|/* Append a new constructor element to V, with the specified INDEX and VAL.  */
end_comment

begin_define
define|#
directive|define
name|CONSTRUCTOR_APPEND_ELT
parameter_list|(
name|V
parameter_list|,
name|INDEX
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { \     constructor_elt *_ce___ = VEC_safe_push (constructor_elt, gc, V, NULL); \     _ce___->index = INDEX; \     _ce___->value = VALUE; \   } while (0)
end_define

begin_comment
comment|/* A single element of a CONSTRUCTOR. VALUE holds the actual value of the    element. INDEX can optionally design the position of VALUE: in arrays,    it is the index where VALUE has to be placed; in structures, it is the    FIELD_DECL of the member.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|constructor_elt_d
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|tree
name|index
block|;
name|tree
name|value
block|; }
end_typedef

begin_expr_stmt
name|constructor_elt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_O
argument_list|(
name|constructor_elt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_O
argument_list|(
name|constructor_elt
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|tree_constructor
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
name|VEC
argument_list|(
name|constructor_elt
argument_list|,
name|gc
argument_list|)
operator|*
name|elts
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Define fields and accessors for some nodes that represent expressions.  */
end_comment

begin_comment
comment|/* Nonzero if NODE is an empty statement (NOP_EXPR<0>).  */
end_comment

begin_define
define|#
directive|define
name|IS_EMPTY_STMT
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CODE (NODE) == NOP_EXPR \&& VOID_TYPE_P (TREE_TYPE (NODE)) \&& integer_zerop (TREE_OPERAND (NODE, 0)))
end_define

begin_comment
comment|/* In ordinary expression nodes.  */
end_comment

begin_define
define|#
directive|define
name|TREE_OPERAND
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
value|TREE_OPERAND_CHECK (NODE, I)
end_define

begin_define
define|#
directive|define
name|TREE_COMPLEXITY
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_CHECK (NODE)->exp.complexity)
end_define

begin_comment
comment|/* In a LOOP_EXPR node.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_EXPR_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND_CHECK_CODE (NODE, LOOP_EXPR, 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MAPPED_LOCATION
end_ifdef

begin_comment
comment|/* The source location of this expression.  Non-tree_exp nodes such as    decls and constants can be shared among multiple locations, so    return nothing.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_LOCATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(EXPR_P (NODE) ? (NODE)->exp.locus : UNKNOWN_LOCATION)
end_define

begin_define
define|#
directive|define
name|SET_EXPR_LOCATION
parameter_list|(
name|NODE
parameter_list|,
name|FROM
parameter_list|)
define|\
value|(EXPR_CHECK (NODE)->exp.locus = (FROM))
end_define

begin_define
define|#
directive|define
name|EXPR_HAS_LOCATION
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_LOCATION (NODE) != UNKNOWN_LOCATION)
end_define

begin_comment
comment|/* EXPR_LOCUS and SET_EXPR_LOCUS are deprecated.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_LOCUS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(EXPR_P (NODE) ?&(NODE)->exp.locus : (location_t *)NULL)
end_define

begin_define
define|#
directive|define
name|SET_EXPR_LOCUS
parameter_list|(
name|NODE
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { source_location *loc_tmp = FROM; \        EXPR_CHECK (NODE)->exp.locus \        = loc_tmp == NULL ? UNKNOWN_LOCATION : *loc_tmp; } while (0)
end_define

begin_define
define|#
directive|define
name|EXPR_FILENAME
parameter_list|(
name|NODE
parameter_list|)
define|\
value|LOCATION_FILE (EXPR_CHECK (NODE)->exp.locus)
end_define

begin_define
define|#
directive|define
name|EXPR_LINENO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|LOCATION_LINE (EXPR_CHECK (NODE)->exp.locus)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The source location of this expression.  Non-tree_exp nodes such as    decls and constants can be shared among multiple locations, so    return nothing.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_LOCUS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(EXPR_P (NODE) ? (NODE)->exp.locus : (location_t *)NULL)
end_define

begin_define
define|#
directive|define
name|SET_EXPR_LOCUS
parameter_list|(
name|NODE
parameter_list|,
name|FROM
parameter_list|)
define|\
value|(EXPR_CHECK (NODE)->exp.locus = (FROM))
end_define

begin_define
define|#
directive|define
name|SET_EXPR_LOCATION
parameter_list|(
name|NODE
parameter_list|,
name|FROM
parameter_list|)
value|annotate_with_locus (NODE, FROM)
end_define

begin_define
define|#
directive|define
name|EXPR_FILENAME
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(EXPR_CHECK (NODE)->exp.locus->file)
end_define

begin_define
define|#
directive|define
name|EXPR_LINENO
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(EXPR_CHECK (NODE)->exp.locus->line)
end_define

begin_define
define|#
directive|define
name|EXPR_HAS_LOCATION
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_LOCUS (NODE) != NULL)
end_define

begin_define
define|#
directive|define
name|EXPR_LOCATION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(EXPR_HAS_LOCATION(NODE) ? *(NODE)->exp.locus : UNKNOWN_LOCATION)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In a TARGET_EXPR node.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_EXPR_SLOT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND_CHECK_CODE (NODE, TARGET_EXPR, 0)
end_define

begin_define
define|#
directive|define
name|TARGET_EXPR_INITIAL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND_CHECK_CODE (NODE, TARGET_EXPR, 1)
end_define

begin_define
define|#
directive|define
name|TARGET_EXPR_CLEANUP
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND_CHECK_CODE (NODE, TARGET_EXPR, 2)
end_define

begin_comment
comment|/* DECL_EXPR accessor. This gives access to the DECL associated with    the given declaration statement.  */
end_comment

begin_define
define|#
directive|define
name|DECL_EXPR_DECL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (DECL_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|EXIT_EXPR_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (EXIT_EXPR_CHECK (NODE), 0)
end_define

begin_comment
comment|/* SWITCH_EXPR accessors. These give access to the condition, body and    original condition type (before any compiler conversions)    of the switch statement, respectively.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SWITCH_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|SWITCH_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SWITCH_EXPR_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|SWITCH_LABELS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SWITCH_EXPR_CHECK (NODE), 2)
end_define

begin_comment
comment|/* CASE_LABEL_EXPR accessors. These give access to the high and low values    of a case label, respectively.  */
end_comment

begin_define
define|#
directive|define
name|CASE_LOW
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CASE_LABEL_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|CASE_HIGH
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CASE_LABEL_EXPR_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|CASE_LABEL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CASE_LABEL_EXPR_CHECK (NODE), 2)
end_define

begin_comment
comment|/* The operands of a TARGET_MEM_REF.  */
end_comment

begin_define
define|#
directive|define
name|TMR_SYMBOL
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (TARGET_MEM_REF_CHECK (NODE), 0))
end_define

begin_define
define|#
directive|define
name|TMR_BASE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (TARGET_MEM_REF_CHECK (NODE), 1))
end_define

begin_define
define|#
directive|define
name|TMR_INDEX
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (TARGET_MEM_REF_CHECK (NODE), 2))
end_define

begin_define
define|#
directive|define
name|TMR_STEP
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (TARGET_MEM_REF_CHECK (NODE), 3))
end_define

begin_define
define|#
directive|define
name|TMR_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (TARGET_MEM_REF_CHECK (NODE), 4))
end_define

begin_define
define|#
directive|define
name|TMR_ORIGINAL
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (TARGET_MEM_REF_CHECK (NODE), 5))
end_define

begin_define
define|#
directive|define
name|TMR_TAG
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (TARGET_MEM_REF_CHECK (NODE), 6))
end_define

begin_comment
comment|/* The operands of a BIND_EXPR.  */
end_comment

begin_define
define|#
directive|define
name|BIND_EXPR_VARS
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (BIND_EXPR_CHECK (NODE), 0))
end_define

begin_define
define|#
directive|define
name|BIND_EXPR_BODY
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (BIND_EXPR_CHECK (NODE), 1))
end_define

begin_define
define|#
directive|define
name|BIND_EXPR_BLOCK
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (BIND_EXPR_CHECK (NODE), 2))
end_define

begin_comment
comment|/* GOTO_EXPR accessor. This gives access to the label associated with    a goto statement.  */
end_comment

begin_define
define|#
directive|define
name|GOTO_DESTINATION
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND ((NODE), 0)
end_define

begin_comment
comment|/* ASM_EXPR accessors. ASM_STRING returns a STRING_CST for the    instruction (e.g., "mov x, y"). ASM_OUTPUTS, ASM_INPUTS, and    ASM_CLOBBERS represent the outputs, inputs, and clobbers for the    statement.  */
end_comment

begin_define
define|#
directive|define
name|ASM_STRING
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_EXPR_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|ASM_INPUTS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_EXPR_CHECK (NODE), 2)
end_define

begin_define
define|#
directive|define
name|ASM_CLOBBERS
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASM_EXPR_CHECK (NODE), 3)
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
value|(TREE_STATIC (NODE))
end_define

begin_define
define|#
directive|define
name|ASM_VOLATILE_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_PUBLIC (NODE))
end_define

begin_comment
comment|/* COND_EXPR accessors.  */
end_comment

begin_define
define|#
directive|define
name|COND_EXPR_COND
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (COND_EXPR_CHECK (NODE), 0))
end_define

begin_define
define|#
directive|define
name|COND_EXPR_THEN
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (COND_EXPR_CHECK (NODE), 1))
end_define

begin_define
define|#
directive|define
name|COND_EXPR_ELSE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_OPERAND (COND_EXPR_CHECK (NODE), 2))
end_define

begin_comment
comment|/* LABEL_EXPR accessor. This gives access to the label associated with    the given label expression.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_EXPR_LABEL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (LABEL_EXPR_CHECK (NODE), 0)
end_define

begin_comment
comment|/* VDEF_EXPR accessors are specified in tree-flow.h, along with the other    accessors for SSA operands.  */
end_comment

begin_comment
comment|/* CATCH_EXPR accessors.  */
end_comment

begin_define
define|#
directive|define
name|CATCH_TYPES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CATCH_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|CATCH_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (CATCH_EXPR_CHECK (NODE), 1)
end_define

begin_comment
comment|/* EH_FILTER_EXPR accessors.  */
end_comment

begin_define
define|#
directive|define
name|EH_FILTER_TYPES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (EH_FILTER_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|EH_FILTER_FAILURE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (EH_FILTER_EXPR_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|EH_FILTER_MUST_NOT_THROW
parameter_list|(
name|NODE
parameter_list|)
value|TREE_STATIC (EH_FILTER_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* OBJ_TYPE_REF accessors.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_TYPE_REF_EXPR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OBJ_TYPE_REF_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OBJ_TYPE_REF_OBJECT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OBJ_TYPE_REF_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|OBJ_TYPE_REF_TOKEN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OBJ_TYPE_REF_CHECK (NODE), 2)
end_define

begin_comment
comment|/* ASSERT_EXPR accessors.  */
end_comment

begin_define
define|#
directive|define
name|ASSERT_EXPR_VAR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASSERT_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|ASSERT_EXPR_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (ASSERT_EXPR_CHECK (NODE), 1)
end_define

begin_comment
comment|/* OpenMP directive and clause accessors.  */
end_comment

begin_define
define|#
directive|define
name|OMP_BODY
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (TREE_RANGE_CHECK (NODE, OMP_PARALLEL, OMP_CRITICAL), 0)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (TREE_RANGE_CHECK (NODE, OMP_PARALLEL, OMP_SINGLE), 1)
end_define

begin_define
define|#
directive|define
name|OMP_PARALLEL_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_PARALLEL_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_PARALLEL_CLAUSES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_PARALLEL_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|OMP_PARALLEL_FN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_PARALLEL_CHECK (NODE), 2)
end_define

begin_define
define|#
directive|define
name|OMP_PARALLEL_DATA_ARG
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_PARALLEL_CHECK (NODE), 3)
end_define

begin_define
define|#
directive|define
name|OMP_FOR_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_FOR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_FOR_CLAUSES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_FOR_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|OMP_FOR_INIT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_FOR_CHECK (NODE), 2)
end_define

begin_define
define|#
directive|define
name|OMP_FOR_COND
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_FOR_CHECK (NODE), 3)
end_define

begin_define
define|#
directive|define
name|OMP_FOR_INCR
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_FOR_CHECK (NODE), 4)
end_define

begin_define
define|#
directive|define
name|OMP_FOR_PRE_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_FOR_CHECK (NODE), 5)
end_define

begin_define
define|#
directive|define
name|OMP_SECTIONS_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_SECTIONS_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_SECTIONS_CLAUSES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_SECTIONS_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|OMP_SECTION_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_SECTION_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_SINGLE_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_SINGLE_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_SINGLE_CLAUSES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_SINGLE_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|OMP_MASTER_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_MASTER_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_ORDERED_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_ORDERED_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_CRITICAL_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_CRITICAL_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_CRITICAL_NAME
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (OMP_CRITICAL_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_CHAIN (OMP_CLAUSE_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_DECL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|OMP_CLAUSE_OPERAND (OMP_CLAUSE_RANGE_CHECK (OMP_CLAUSE_CHECK (NODE),	\ 					      OMP_CLAUSE_PRIVATE,	\ 	                                      OMP_CLAUSE_COPYPRIVATE), 0)
end_define

begin_comment
comment|/* True on an OMP_SECTION statement that was the last lexical member.    This status is meaningful in the implementation of lastprivate.  */
end_comment

begin_define
define|#
directive|define
name|OMP_SECTION_LAST
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_PRIVATE (OMP_SECTION_CHECK (NODE))
end_define

begin_comment
comment|/* True on an OMP_RETURN statement if the return does not require a    thread synchronization via some sort of barrier.  The exact barrier    that would otherwise be emitted is dependent on the OMP statement    with which this return is associated.  */
end_comment

begin_define
define|#
directive|define
name|OMP_RETURN_NOWAIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_PRIVATE (OMP_RETURN_CHECK (NODE))
end_define

begin_comment
comment|/* True on an OMP_PARALLEL statement if it represents an explicit    combined parallel work-sharing constructs.  */
end_comment

begin_define
define|#
directive|define
name|OMP_PARALLEL_COMBINED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_PRIVATE (OMP_PARALLEL_CHECK (NODE))
end_define

begin_comment
comment|/* True on a PRIVATE clause if its decl is kept around for debugging    information only and its DECL_VALUE_EXPR is supposed to point    to what it has been remapped to.  */
end_comment

begin_define
define|#
directive|define
name|OMP_CLAUSE_PRIVATE_DEBUG
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_PUBLIC (OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_PRIVATE))
end_define

begin_comment
comment|/* True on a LASTPRIVATE clause if a FIRSTPRIVATE clause for the same    decl is present in the chain.  */
end_comment

begin_define
define|#
directive|define
name|OMP_CLAUSE_LASTPRIVATE_FIRSTPRIVATE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_PUBLIC (OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_LASTPRIVATE))
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_IF_EXPR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|OMP_CLAUSE_OPERAND (OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_IF), 0)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_NUM_THREADS_EXPR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|OMP_CLAUSE_OPERAND (OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_NUM_THREADS),0)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_SCHEDULE_CHUNK_EXPR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|OMP_CLAUSE_OPERAND (OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_SCHEDULE), 0)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_REDUCTION_CODE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_REDUCTION)->omp_clause.subcode.reduction_code)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_REDUCTION_INIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|OMP_CLAUSE_OPERAND (OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_REDUCTION), 1)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_REDUCTION_MERGE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|OMP_CLAUSE_OPERAND (OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_REDUCTION), 2)
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_REDUCTION_PLACEHOLDER
parameter_list|(
name|NODE
parameter_list|)
define|\
value|OMP_CLAUSE_OPERAND (OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_REDUCTION), 3)
end_define

begin_enum
enum|enum
name|omp_clause_schedule_kind
block|{
name|OMP_CLAUSE_SCHEDULE_STATIC
block|,
name|OMP_CLAUSE_SCHEDULE_DYNAMIC
block|,
name|OMP_CLAUSE_SCHEDULE_GUIDED
block|,
name|OMP_CLAUSE_SCHEDULE_RUNTIME
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|OMP_CLAUSE_SCHEDULE_KIND
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_SCHEDULE)->omp_clause.subcode.schedule_kind)
end_define

begin_enum
enum|enum
name|omp_clause_default_kind
block|{
name|OMP_CLAUSE_DEFAULT_UNSPECIFIED
block|,
name|OMP_CLAUSE_DEFAULT_SHARED
block|,
name|OMP_CLAUSE_DEFAULT_NONE
block|,
name|OMP_CLAUSE_DEFAULT_PRIVATE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|OMP_CLAUSE_DEFAULT_KIND
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(OMP_CLAUSE_SUBCODE_CHECK (NODE, OMP_CLAUSE_DEFAULT)->omp_clause.subcode.default_kind)
end_define

begin_decl_stmt
name|struct
name|tree_exp
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
name|source_locus
name|locus
decl_stmt|;
name|int
name|complexity
decl_stmt|;
name|tree
name|block
decl_stmt|;
name|tree
name|GTY
argument_list|(
operator|(
name|special
argument_list|(
literal|"tree_exp"
argument_list|)
operator|,
name|desc
argument_list|(
literal|"TREE_CODE ((tree)&%0)"
argument_list|)
operator|)
argument_list|)
name|operands
index|[
literal|1
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* SSA_NAME accessors.  */
end_comment

begin_comment
comment|/* Returns the variable being referenced.  Once released, this is the    only field that can be relied upon.  */
end_comment

begin_define
define|#
directive|define
name|SSA_NAME_VAR
parameter_list|(
name|NODE
parameter_list|)
value|SSA_NAME_CHECK (NODE)->ssa_name.var
end_define

begin_comment
comment|/* Returns the statement which defines this reference.   Note that    we use the same field when chaining SSA_NAME nodes together on    the SSA_NAME freelist.  */
end_comment

begin_define
define|#
directive|define
name|SSA_NAME_DEF_STMT
parameter_list|(
name|NODE
parameter_list|)
value|SSA_NAME_CHECK (NODE)->common.chain
end_define

begin_comment
comment|/* Returns the SSA version number of this SSA name.  Note that in    tree SSA, version numbers are not per variable and may be recycled.  */
end_comment

begin_define
define|#
directive|define
name|SSA_NAME_VERSION
parameter_list|(
name|NODE
parameter_list|)
value|SSA_NAME_CHECK (NODE)->ssa_name.version
end_define

begin_comment
comment|/* Nonzero if this SSA name occurs in an abnormal PHI.  SSA_NAMES are    never output, so we can safely use the ASM_WRITTEN_FLAG for this    status bit.  */
end_comment

begin_define
define|#
directive|define
name|SSA_NAME_OCCURS_IN_ABNORMAL_PHI
parameter_list|(
name|NODE
parameter_list|)
define|\
value|SSA_NAME_CHECK (NODE)->common.asm_written_flag
end_define

begin_comment
comment|/* Nonzero if this SSA_NAME expression is currently on the free list of    SSA_NAMES.  Using NOTHROW_FLAG seems reasonably safe since throwing    has no meaning for an SSA_NAME.  */
end_comment

begin_define
define|#
directive|define
name|SSA_NAME_IN_FREE_LIST
parameter_list|(
name|NODE
parameter_list|)
define|\
value|SSA_NAME_CHECK (NODE)->common.nothrow_flag
end_define

begin_comment
comment|/* Attributes for SSA_NAMEs for pointer-type variables.  */
end_comment

begin_define
define|#
directive|define
name|SSA_NAME_PTR_INFO
parameter_list|(
name|N
parameter_list|)
define|\
value|SSA_NAME_CHECK (N)->ssa_name.ptr_info
end_define

begin_comment
comment|/* Get the value of this SSA_NAME, if available.  */
end_comment

begin_define
define|#
directive|define
name|SSA_NAME_VALUE
parameter_list|(
name|N
parameter_list|)
define|\
value|SSA_NAME_CHECK (N)->ssa_name.value_handle
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_TREE_FLOW_H
end_ifndef

begin_struct_decl
struct_decl|struct
name|ptr_info_def
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Immediate use linking structure.  This structure is used for maintaining    a doubly linked list of uses of an SSA_NAME.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ssa_use_operand_d
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|ssa_use_operand_d
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|prev
block|;
name|struct
name|ssa_use_operand_d
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|next
block|;
name|tree
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|stmt
block|;
name|tree
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|use
block|; }
end_typedef

begin_expr_stmt
name|ssa_use_operand_t
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Return the immediate_use information for an SSA_NAME. */
end_comment

begin_define
define|#
directive|define
name|SSA_NAME_IMM_USE_NODE
parameter_list|(
name|NODE
parameter_list|)
value|SSA_NAME_CHECK (NODE)->ssa_name.imm_uses
end_define

begin_decl_stmt
name|struct
name|tree_ssa_name
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
comment|/* _DECL wrapped by this SSA name.  */
name|tree
name|var
decl_stmt|;
comment|/* SSA version number.  */
name|unsigned
name|int
name|version
decl_stmt|;
comment|/* Pointer attributes used for alias analysis.  */
name|struct
name|ptr_info_def
modifier|*
name|ptr_info
decl_stmt|;
comment|/* Value for SSA name used by various passes.       Right now only invariants are allowed to persist beyond a pass in      this field; in the future we will allow VALUE_HANDLEs to persist      as well.  */
name|tree
name|value_handle
decl_stmt|;
comment|/* Immediate uses list for this SSA_NAME.  */
name|struct
name|ssa_use_operand_d
name|imm_uses
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* In a PHI_NODE node.  */
end_comment

begin_comment
comment|/* These 2 macros should be considered off limits for use by developers.  If    you wish to access the use or def fields of a PHI_NODE in the SSA    optimizers, use the accessor macros found in tree-ssa-operands.h.    These two macros are to be used only by those accessor macros, and other    select places where we *absolutely* must take the address of the tree.  */
end_comment

begin_define
define|#
directive|define
name|PHI_RESULT_TREE
parameter_list|(
name|NODE
parameter_list|)
value|PHI_NODE_CHECK (NODE)->phi.result
end_define

begin_define
define|#
directive|define
name|PHI_ARG_DEF_TREE
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
value|PHI_NODE_ELT_CHECK (NODE, I).def
end_define

begin_comment
comment|/* PHI_NODEs for each basic block are chained together in a single linked    list.  The head of the list is linked from the block annotation, and    the link to the next PHI is in PHI_CHAIN.  */
end_comment

begin_define
define|#
directive|define
name|PHI_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_CHAIN (PHI_NODE_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|PHI_NUM_ARGS
parameter_list|(
name|NODE
parameter_list|)
value|PHI_NODE_CHECK (NODE)->phi.num_args
end_define

begin_define
define|#
directive|define
name|PHI_ARG_CAPACITY
parameter_list|(
name|NODE
parameter_list|)
value|PHI_NODE_CHECK (NODE)->phi.capacity
end_define

begin_define
define|#
directive|define
name|PHI_ARG_ELT
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
value|PHI_NODE_ELT_CHECK (NODE, I)
end_define

begin_define
define|#
directive|define
name|PHI_ARG_EDGE
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
value|(EDGE_PRED (PHI_BB ((NODE)), (I)))
end_define

begin_define
define|#
directive|define
name|PHI_BB
parameter_list|(
name|NODE
parameter_list|)
value|PHI_NODE_CHECK (NODE)->phi.bb
end_define

begin_define
define|#
directive|define
name|PHI_ARG_IMM_USE_NODE
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
value|PHI_NODE_ELT_CHECK (NODE, I).imm_use
end_define

begin_decl_stmt
name|struct
name|phi_arg_d
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* imm_use MUST be the first element in struct because we do some      pointer arithmetic with it.  See phi_arg_index_from_use.  */
name|struct
name|ssa_use_operand_d
name|imm_use
decl_stmt|;
name|tree
name|def
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|tree_phi_node
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
name|result
decl_stmt|;
name|int
name|num_args
decl_stmt|;
name|int
name|capacity
decl_stmt|;
comment|/* Basic block to that the phi node belongs.  */
name|struct
name|basic_block_def
modifier|*
name|bb
decl_stmt|;
comment|/* Arguments of the PHI node.  These are maintained in the same      order as predecessor edge vector BB->PREDS.  */
name|struct
name|phi_arg_d
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"((tree)&%h)->phi.num_args"
argument_list|)
operator|)
argument_list|)
name|a
index|[
literal|1
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_define
define|#
directive|define
name|OMP_CLAUSE_CODE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(OMP_CLAUSE_CHECK (NODE))->omp_clause.code
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_SET_CODE
parameter_list|(
name|NODE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|((OMP_CLAUSE_CHECK (NODE))->omp_clause.code = (CODE))
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_CODE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(OMP_CLAUSE_CHECK (NODE))->omp_clause.code
end_define

begin_define
define|#
directive|define
name|OMP_CLAUSE_OPERAND
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
define|\
value|OMP_CLAUSE_ELT_CHECK (NODE, I)
end_define

begin_decl_stmt
name|struct
name|tree_omp_clause
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
name|enum
name|omp_clause_code
name|code
decl_stmt|;
union|union
name|omp_clause_subcode
block|{
name|enum
name|omp_clause_default_kind
name|default_kind
decl_stmt|;
name|enum
name|omp_clause_schedule_kind
name|schedule_kind
decl_stmt|;
name|enum
name|tree_code
name|reduction_code
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|subcode
union|;
name|tree
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"omp_clause_num_ops[OMP_CLAUSE_CODE ((tree)&%h)]"
argument_list|)
operator|)
argument_list|)
name|ops
index|[
literal|1
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_struct_decl
struct_decl|struct
name|varray_head_tag
struct_decl|;
end_struct_decl

begin_comment
comment|/* In a BLOCK node.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_VARS
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.vars)
end_define

begin_define
define|#
directive|define
name|BLOCK_SUBBLOCKS
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.subblocks)
end_define

begin_define
define|#
directive|define
name|BLOCK_SUPERCONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.supercontext)
end_define

begin_comment
comment|/* Note: when changing this, make sure to find the places    that use chainon or nreverse.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_CHAIN (BLOCK_CHECK (NODE))
end_define

begin_define
define|#
directive|define
name|BLOCK_ABSTRACT_ORIGIN
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.abstract_origin)
end_define

begin_define
define|#
directive|define
name|BLOCK_ABSTRACT
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.abstract_flag)
end_define

begin_comment
comment|/* Nonzero means that this block is prepared to handle exceptions    listed in the BLOCK_VARS slot.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_HANDLER_BLOCK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(BLOCK_CHECK (NODE)->block.handler_block_flag)
end_define

begin_comment
comment|/* An index number for this block.  These values are not guaranteed to    be unique across functions -- whether or not they are depends on    the debugging output format in use.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_NUMBER
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.block_num)
end_define

begin_comment
comment|/* If block reordering splits a lexical block into discontiguous    address ranges, we'll make a copy of the original block.     Note that this is logically distinct from BLOCK_ABSTRACT_ORIGIN.    In that case, we have one source block that has been replicated    (through inlining or unrolling) into many logical blocks, and that    these logical blocks have different physical variables in them.     In this case, we have one logical block split into several    non-contiguous address ranges.  Most debug formats can't actually    represent this idea directly, so we fake it by creating multiple    logical blocks with the same variables in them.  However, for those    that do support non-contiguous regions, these allow the original    logical block to be reconstructed, along with the set of address    ranges.     One of the logical block fragments is arbitrarily chosen to be    the ORIGIN.  The other fragments will point to the origin via    BLOCK_FRAGMENT_ORIGIN; the origin itself will have this pointer    be null.  The list of fragments will be chained through    BLOCK_FRAGMENT_CHAIN from the origin.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_FRAGMENT_ORIGIN
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.fragment_origin)
end_define

begin_define
define|#
directive|define
name|BLOCK_FRAGMENT_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.fragment_chain)
end_define

begin_comment
comment|/* For an inlined function, this gives the location where it was called    from.  This is only set in the top level block, which corresponds to the    inlined function scope.  This is used in the debug output routines.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_SOURCE_LOCATION
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.locus)
end_define

begin_decl_stmt
name|struct
name|tree_block
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
name|unsigned
name|handler_block_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|abstract_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|block_num
range|:
literal|30
decl_stmt|;
name|tree
name|vars
decl_stmt|;
name|tree
name|subblocks
decl_stmt|;
name|tree
name|supercontext
decl_stmt|;
name|tree
name|abstract_origin
decl_stmt|;
name|tree
name|fragment_origin
decl_stmt|;
name|tree
name|fragment_chain
decl_stmt|;
name|location_t
name|locus
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* Define fields and accessors for nodes representing data types.  */
end_comment

begin_comment
comment|/* See tree.def for documentation of the use of these fields.    Look at the documentation of the various ..._TYPE tree codes.     Note that the type.values, type.minval, and type.maxval fields are    overloaded and used for different macros in different kinds of types.    Each macro must check to ensure the tree node is of the proper kind of    type.  Note also that some of the front-ends also overload these fields,    so they must be checked as well.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_UID
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.uid)
end_define

begin_define
define|#
directive|define
name|TYPE_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.size)
end_define

begin_define
define|#
directive|define
name|TYPE_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.size_unit)
end_define

begin_define
define|#
directive|define
name|TYPE_MODE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.mode)
end_define

begin_define
define|#
directive|define
name|TYPE_VALUES
parameter_list|(
name|NODE
parameter_list|)
value|(ENUMERAL_TYPE_CHECK (NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_DOMAIN
parameter_list|(
name|NODE
parameter_list|)
value|(ARRAY_TYPE_CHECK (NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELDS
parameter_list|(
name|NODE
parameter_list|)
value|(RECORD_OR_UNION_CHECK (NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_CACHED_VALUES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK(NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_ORIG_SIZE_TYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(INTEGER_TYPE_CHECK (NODE)->type.values		\   ? TREE_TYPE ((NODE)->type.values) : NULL_TREE)
end_define

begin_define
define|#
directive|define
name|TYPE_METHODS
parameter_list|(
name|NODE
parameter_list|)
value|(RECORD_OR_UNION_CHECK (NODE)->type.maxval)
end_define

begin_define
define|#
directive|define
name|TYPE_VFIELD
parameter_list|(
name|NODE
parameter_list|)
value|(RECORD_OR_UNION_CHECK (NODE)->type.minval)
end_define

begin_define
define|#
directive|define
name|TYPE_ARG_TYPES
parameter_list|(
name|NODE
parameter_list|)
value|(FUNC_OR_METHOD_CHECK (NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_METHOD_BASETYPE
parameter_list|(
name|NODE
parameter_list|)
value|(FUNC_OR_METHOD_CHECK (NODE)->type.maxval)
end_define

begin_define
define|#
directive|define
name|TYPE_OFFSET_BASETYPE
parameter_list|(
name|NODE
parameter_list|)
value|(OFFSET_TYPE_CHECK (NODE)->type.maxval)
end_define

begin_define
define|#
directive|define
name|TYPE_POINTER_TO
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.pointer_to)
end_define

begin_define
define|#
directive|define
name|TYPE_REFERENCE_TO
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.reference_to)
end_define

begin_define
define|#
directive|define
name|TYPE_NEXT_PTR_TO
parameter_list|(
name|NODE
parameter_list|)
value|(POINTER_TYPE_CHECK (NODE)->type.minval)
end_define

begin_define
define|#
directive|define
name|TYPE_NEXT_REF_TO
parameter_list|(
name|NODE
parameter_list|)
value|(REFERENCE_TYPE_CHECK (NODE)->type.minval)
end_define

begin_define
define|#
directive|define
name|TYPE_MIN_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(NUMERICAL_TYPE_CHECK (NODE)->type.minval)
end_define

begin_define
define|#
directive|define
name|TYPE_MAX_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(NUMERICAL_TYPE_CHECK (NODE)->type.maxval)
end_define

begin_define
define|#
directive|define
name|TYPE_PRECISION
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.precision)
end_define

begin_define
define|#
directive|define
name|TYPE_SYMTAB_ADDRESS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.symtab.address)
end_define

begin_define
define|#
directive|define
name|TYPE_SYMTAB_POINTER
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.symtab.pointer)
end_define

begin_define
define|#
directive|define
name|TYPE_SYMTAB_DIE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.symtab.die)
end_define

begin_define
define|#
directive|define
name|TYPE_NAME
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.name)
end_define

begin_define
define|#
directive|define
name|TYPE_NEXT_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.next_variant)
end_define

begin_define
define|#
directive|define
name|TYPE_MAIN_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.main_variant)
end_define

begin_define
define|#
directive|define
name|TYPE_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.context)
end_define

begin_define
define|#
directive|define
name|TYPE_LANG_SPECIFIC
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.lang_specific)
end_define

begin_comment
comment|/* For a VECTOR_TYPE node, this describes a different type which is emitted    in the debugging output.  We use this to describe a vector as a    structure containing an array.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_DEBUG_REPRESENTATION_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|(VECTOR_TYPE_CHECK (NODE)->type.values)
end_define

begin_comment
comment|/* For record and union types, information about this type, as a base type    for itself.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BINFO
parameter_list|(
name|NODE
parameter_list|)
value|(RECORD_OR_UNION_CHECK(NODE)->type.binfo)
end_define

begin_comment
comment|/* For non record and union types, used in a language-dependent way.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_LANG_SLOT_1
parameter_list|(
name|NODE
parameter_list|)
value|(NOT_RECORD_OR_UNION_CHECK(NODE)->type.binfo)
end_define

begin_comment
comment|/* The (language-specific) typed-based alias set for this type.    Objects whose TYPE_ALIAS_SETs are different cannot alias each    other.  If the TYPE_ALIAS_SET is -1, no alias set has yet been    assigned to this type.  If the TYPE_ALIAS_SET is 0, objects of this    type can alias objects of any type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ALIAS_SET
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.alias_set)
end_define

begin_comment
comment|/* Nonzero iff the typed-based alias set for this type has been    calculated.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ALIAS_SET_KNOWN_P
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.alias_set != -1)
end_define

begin_comment
comment|/* A TREE_LIST of IDENTIFIER nodes of the attributes that apply    to this type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ATTRIBUTES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.attributes)
end_define

begin_comment
comment|/* The alignment necessary for objects of this type.    The value is an int, measured in bits.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.align)
end_define

begin_comment
comment|/* 1 if the alignment for this type was requested by "aligned" attribute,    0 if it is the default for this type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_USER_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.user_align)
end_define

begin_comment
comment|/* The alignment for NODE, in bytes.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ALIGN_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_ALIGN (NODE) / BITS_PER_UNIT)
end_define

begin_comment
comment|/* If your language allows you to declare types, and you want debug info    for them, then you need to generate corresponding TYPE_DECL nodes.    These "stub" TYPE_DECL nodes have no name, and simply point at the    type node.  You then set the TYPE_STUB_DECL field of the type node    to point back at the TYPE_DECL node.  This allows the debug routines    to know that the two nodes represent the same type, so that we only    get one debug info record for them.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_STUB_DECL
parameter_list|(
name|NODE
parameter_list|)
value|TREE_CHAIN (NODE)
end_define

begin_comment
comment|/* In a RECORD_TYPE, UNION_TYPE or QUAL_UNION_TYPE, it means the type    has BLKmode only because it lacks the alignment requirement for    its size.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NO_FORCE_BLK
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.no_force_blk_flag)
end_define

begin_comment
comment|/* In an INTEGER_TYPE, it means the type represents a size.  We use    this both for validity checking and to permit optimizations that    are unsafe for other types.  Note that the C `size_t' type should    *not* have this flag set.  The `size_t' type is simply a typedef    for an ordinary integer type that happens to be the type of an    expression returned by `sizeof'; `size_t' has no special    properties.  Expressions whose type have TYPE_IS_SIZETYPE set are    always actual sizes.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_IS_SIZETYPE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(INTEGER_TYPE_CHECK (NODE)->type.no_force_blk_flag)
end_define

begin_comment
comment|/* In a FUNCTION_TYPE, indicates that the function returns with the stack    pointer depressed.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_RETURNS_STACK_DEPRESSED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_TYPE_CHECK (NODE)->type.no_force_blk_flag)
end_define

begin_comment
comment|/* Nonzero in a type considered volatile as a whole.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_VOLATILE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->common.volatile_flag)
end_define

begin_comment
comment|/* Means this type is const-qualified.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_READONLY
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->common.readonly_flag)
end_define

begin_comment
comment|/* If nonzero, this type is `restrict'-qualified, in the C sense of    the term.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_RESTRICT
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.restrict_flag)
end_define

begin_comment
comment|/* There is a TYPE_QUAL value for each type qualifier.  They can be    combined by bitwise-or to form the complete set of qualifiers for a    type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_UNQUALIFIED
value|0x0
end_define

begin_define
define|#
directive|define
name|TYPE_QUAL_CONST
value|0x1
end_define

begin_define
define|#
directive|define
name|TYPE_QUAL_VOLATILE
value|0x2
end_define

begin_define
define|#
directive|define
name|TYPE_QUAL_RESTRICT
value|0x4
end_define

begin_comment
comment|/* The set of type qualifiers for this type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_QUALS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TYPE_READONLY (NODE) * TYPE_QUAL_CONST)			\    | (TYPE_VOLATILE (NODE) * TYPE_QUAL_VOLATILE)		\    | (TYPE_RESTRICT (NODE) * TYPE_QUAL_RESTRICT))
end_define

begin_comment
comment|/* These flags are available for each language front end to use internally.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_LANG_FLAG_0
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.lang_flag_0)
end_define

begin_define
define|#
directive|define
name|TYPE_LANG_FLAG_1
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.lang_flag_1)
end_define

begin_define
define|#
directive|define
name|TYPE_LANG_FLAG_2
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.lang_flag_2)
end_define

begin_define
define|#
directive|define
name|TYPE_LANG_FLAG_3
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.lang_flag_3)
end_define

begin_define
define|#
directive|define
name|TYPE_LANG_FLAG_4
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.lang_flag_4)
end_define

begin_define
define|#
directive|define
name|TYPE_LANG_FLAG_5
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.lang_flag_5)
end_define

begin_define
define|#
directive|define
name|TYPE_LANG_FLAG_6
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.lang_flag_6)
end_define

begin_comment
comment|/* Used to keep track of visited nodes in tree traversals.  This is set to    0 by copy_node and make_node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VISITED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.visited)
end_define

begin_comment
comment|/* If set in an ARRAY_TYPE, indicates a string type (for languages    that distinguish string from array of char).    If set in a INTEGER_TYPE, indicates a character type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_STRING_FLAG
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.string_flag)
end_define

begin_comment
comment|/* If non-NULL, this is an upper bound of the size (in bytes) of an    object of the given ARRAY_TYPE.  This allows temporaries to be    allocated.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ARRAY_MAX_SIZE
parameter_list|(
name|ARRAY_TYPE
parameter_list|)
define|\
value|(ARRAY_TYPE_CHECK (ARRAY_TYPE)->type.maxval)
end_define

begin_comment
comment|/* For a VECTOR_TYPE, this is the number of sub-parts of the vector.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_VECTOR_SUBPARTS
parameter_list|(
name|VECTOR_TYPE
parameter_list|)
define|\
value|(((unsigned HOST_WIDE_INT) 1) \<< VECTOR_TYPE_CHECK (VECTOR_TYPE)->type.precision)
end_define

begin_comment
comment|/* Set precision to n when we have 2^n sub-parts of the vector.  */
end_comment

begin_define
define|#
directive|define
name|SET_TYPE_VECTOR_SUBPARTS
parameter_list|(
name|VECTOR_TYPE
parameter_list|,
name|X
parameter_list|)
define|\
value|(VECTOR_TYPE_CHECK (VECTOR_TYPE)->type.precision = exact_log2 (X))
end_define

begin_comment
comment|/* Indicates that objects of this type must be initialized by calling a    function when they are created.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NEEDS_CONSTRUCTING
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_CHECK (NODE)->type.needs_constructing_flag)
end_define

begin_comment
comment|/* Indicates that objects of this type (a UNION_TYPE), should be passed    the same way that the first union alternative would be passed.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_TRANSPARENT_UNION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(UNION_TYPE_CHECK (NODE)->type.transparent_union_flag)
end_define

begin_comment
comment|/* For an ARRAY_TYPE, indicates that it is not permitted to    take the address of a component of the type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_NONALIASED_COMPONENT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(ARRAY_TYPE_CHECK (NODE)->type.transparent_union_flag)
end_define

begin_comment
comment|/* Indicated that objects of this type should be laid out in as    compact a way as possible.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_PACKED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.packed_flag)
end_define

begin_comment
comment|/* Used by type_contains_placeholder_p to avoid recomputation.    Values are: 0 (unknown), 1 (false), 2 (true).  Never access    this field directly.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_CONTAINS_PLACEHOLDER_INTERNAL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_CHECK (NODE)->type.contains_placeholder_bits)
end_define

begin_struct_decl
struct_decl|struct
name|die_struct
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|tree_type
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
name|values
decl_stmt|;
name|tree
name|size
decl_stmt|;
name|tree
name|size_unit
decl_stmt|;
name|tree
name|attributes
decl_stmt|;
name|unsigned
name|int
name|uid
decl_stmt|;
name|unsigned
name|int
name|precision
range|:
literal|9
decl_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|machine_mode
argument_list|)
name|mode
label|:
literal|7
expr_stmt|;
name|unsigned
name|string_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|no_force_blk_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|needs_constructing_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|transparent_union_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|packed_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|restrict_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|contains_placeholder_bits
range|:
literal|2
decl_stmt|;
name|unsigned
name|lang_flag_0
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_1
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_2
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_3
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_4
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_5
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_6
range|:
literal|1
decl_stmt|;
name|unsigned
name|user_align
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|align
decl_stmt|;
name|tree
name|pointer_to
decl_stmt|;
name|tree
name|reference_to
decl_stmt|;
union|union
name|tree_type_symtab
block|{
name|int
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|)
argument_list|)
name|address
decl_stmt|;
name|char
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
name|pointer
decl_stmt|;
name|struct
name|die_struct
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
name|die
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"debug_hooks ==&sdb_debug_hooks ? 1 : debug_hooks ==&dwarf2_debug_hooks ? 2 : 0"
argument_list|)
operator|,
name|descbits
argument_list|(
literal|"2"
argument_list|)
operator|)
argument_list|)
name|symtab
union|;
name|tree
name|name
decl_stmt|;
name|tree
name|minval
decl_stmt|;
name|tree
name|maxval
decl_stmt|;
name|tree
name|next_variant
decl_stmt|;
name|tree
name|main_variant
decl_stmt|;
name|tree
name|binfo
decl_stmt|;
name|tree
name|context
decl_stmt|;
name|HOST_WIDE_INT
name|alias_set
decl_stmt|;
comment|/* Points to a structure whose details depend on the language in use.  */
name|struct
name|lang_type
modifier|*
name|lang_specific
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* Define accessor macros for information about type inheritance    and basetypes.     A "basetype" means a particular usage of a data type for inheritance    in another type.  Each such basetype usage has its own "binfo"    object to describe it.  The binfo object is a TREE_VEC node.     Inheritance is represented by the binfo nodes allocated for a    given type.  For example, given types C and D, such that D is    inherited by C, 3 binfo nodes will be allocated: one for describing    the binfo properties of C, similarly one for D, and one for    describing the binfo properties of D as a base type for C.    Thus, given a pointer to class C, one can get a pointer to the binfo    of D acting as a basetype for C by looking at C's binfo's basetypes.  */
end_comment

begin_comment
comment|/* BINFO specific flags.  */
end_comment

begin_comment
comment|/* Nonzero means that the derivation chain is via a `virtual' declaration.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_BINFO_CHECK (NODE)->common.static_flag)
end_define

begin_comment
comment|/* Flags for language dependent use.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_MARKED
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_0(TREE_BINFO_CHECK(NODE))
end_define

begin_define
define|#
directive|define
name|BINFO_FLAG_1
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_1(TREE_BINFO_CHECK(NODE))
end_define

begin_define
define|#
directive|define
name|BINFO_FLAG_2
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_2(TREE_BINFO_CHECK(NODE))
end_define

begin_define
define|#
directive|define
name|BINFO_FLAG_3
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_3(TREE_BINFO_CHECK(NODE))
end_define

begin_define
define|#
directive|define
name|BINFO_FLAG_4
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_4(TREE_BINFO_CHECK(NODE))
end_define

begin_define
define|#
directive|define
name|BINFO_FLAG_5
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_5(TREE_BINFO_CHECK(NODE))
end_define

begin_define
define|#
directive|define
name|BINFO_FLAG_6
parameter_list|(
name|NODE
parameter_list|)
value|TREE_LANG_FLAG_6(TREE_BINFO_CHECK(NODE))
end_define

begin_comment
comment|/* The actual data type node being inherited in this basetype.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_TYPE (TREE_BINFO_CHECK(NODE))
end_define

begin_comment
comment|/* The offset where this basetype appears in its containing type.    BINFO_OFFSET slot holds the offset (in bytes)    from the base of the complete object to the base of the part of the    object that is allocated on behalf of this `type'.    This is always 0 except when there is multiple inheritance.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_BINFO_CHECK(NODE)->binfo.offset)
end_define

begin_define
define|#
directive|define
name|BINFO_OFFSET_ZEROP
parameter_list|(
name|NODE
parameter_list|)
value|(integer_zerop (BINFO_OFFSET (NODE)))
end_define

begin_comment
comment|/* The virtual function table belonging to this basetype.  Virtual    function tables provide a mechanism for run-time method dispatching.    The entries of a virtual function table are language-dependent.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VTABLE
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_BINFO_CHECK(NODE)->binfo.vtable)
end_define

begin_comment
comment|/* The virtual functions in the virtual function table.  This is    a TREE_LIST that is used as an initial approximation for building    a virtual function table for this basetype.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_BINFO_CHECK(NODE)->binfo.virtuals)
end_define

begin_comment
comment|/* A vector of binfos for the direct basetypes inherited by this    basetype.     If this basetype describes type D as inherited in C, and if the    basetypes of D are E and F, then this vector contains binfos for    inheritance of E and F by C.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_BASE_BINFOS
parameter_list|(
name|NODE
parameter_list|)
value|(&TREE_BINFO_CHECK(NODE)->binfo.base_binfos)
end_define

begin_comment
comment|/* The number of basetypes for NODE.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_N_BASE_BINFOS
parameter_list|(
name|NODE
parameter_list|)
value|(VEC_length (tree, BINFO_BASE_BINFOS (NODE)))
end_define

begin_comment
comment|/* Accessor macro to get to the Nth base binfo of this binfo.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_BASE_BINFO
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
define|\
value|(VEC_index (tree, BINFO_BASE_BINFOS (NODE), (N)))
end_define

begin_define
define|#
directive|define
name|BINFO_BASE_ITERATE
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|,
name|B
parameter_list|)
define|\
value|(VEC_iterate (tree, BINFO_BASE_BINFOS (NODE), (N), (B)))
end_define

begin_define
define|#
directive|define
name|BINFO_BASE_APPEND
parameter_list|(
name|NODE
parameter_list|,
name|T
parameter_list|)
define|\
value|(VEC_quick_push (tree, BINFO_BASE_BINFOS (NODE), (T)))
end_define

begin_comment
comment|/* For a BINFO record describing a virtual base class, i.e., one where    TREE_VIA_VIRTUAL is set, this field assists in locating the virtual    base.  The actual contents are language-dependent.  In the C++    front-end this field is an INTEGER_CST giving an offset into the    vtable where the offset to the virtual base can be found.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VPTR_FIELD
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_BINFO_CHECK(NODE)->binfo.vptr_field)
end_define

begin_comment
comment|/* Indicates the accesses this binfo has to its bases. The values are    access_public_node, access_protected_node or access_private_node.    If this array is not present, public access is implied.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_BASE_ACCESSES
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_BINFO_CHECK(NODE)->binfo.base_accesses)
end_define

begin_define
define|#
directive|define
name|BINFO_BASE_ACCESS
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
define|\
value|VEC_index (tree, BINFO_BASE_ACCESSES (NODE), (N))
end_define

begin_define
define|#
directive|define
name|BINFO_BASE_ACCESS_APPEND
parameter_list|(
name|NODE
parameter_list|,
name|T
parameter_list|)
define|\
value|VEC_quick_push (tree, BINFO_BASE_ACCESSES (NODE), (T))
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
value|(TREE_BINFO_CHECK(NODE)->binfo.vtt_subvtt)
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
value|(TREE_BINFO_CHECK(NODE)->binfo.vtt_vptr)
end_define

begin_comment
comment|/* The BINFO_INHERITANCE_CHAIN points at the binfo for the base    inheriting this base for non-virtual bases. For virtual bases it    points either to the binfo for which this is a primary binfo, or to    the binfo of the most derived type.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_INHERITANCE_CHAIN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_BINFO_CHECK(NODE)->binfo.inheritance)
end_define

begin_decl_stmt
name|struct
name|tree_binfo
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
name|offset
decl_stmt|;
name|tree
name|vtable
decl_stmt|;
name|tree
name|virtuals
decl_stmt|;
name|tree
name|vptr_field
decl_stmt|;
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|base_accesses
expr_stmt|;
name|tree
name|inheritance
decl_stmt|;
name|tree
name|vtt_subvtt
decl_stmt|;
name|tree
name|vtt_vptr
decl_stmt|;
name|VEC
argument_list|(
argument|tree
argument_list|,
argument|none
argument_list|)
name|base_binfos
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* Define fields and accessors for nodes representing declared names.  */
end_comment

begin_comment
comment|/* Nonzero if DECL represents a variable for the SSA passes.  */
end_comment

begin_define
define|#
directive|define
name|SSA_VAR_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(TREE_CODE (DECL) == VAR_DECL					\ 	 || TREE_CODE (DECL) == PARM_DECL				\ 	 || TREE_CODE (DECL) == RESULT_DECL				\ 	 || MTAG_P (DECL)						\ 	 || (TREE_CODE (DECL) == SSA_NAME				\&& (TREE_CODE (SSA_NAME_VAR (DECL)) == VAR_DECL		\ 		 || TREE_CODE (SSA_NAME_VAR (DECL)) == PARM_DECL	\ 		 || TREE_CODE (SSA_NAME_VAR (DECL)) == RESULT_DECL	\ 		 || MTAG_P (SSA_NAME_VAR (DECL)))))
end_define

begin_comment
comment|/* Enumerate visibility settings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYMBOL_VISIBILITY_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|SYMBOL_VISIBILITY_DEFINED
end_define

begin_enum
enum|enum
name|symbol_visibility
block|{
name|VISIBILITY_DEFAULT
block|,
name|VISIBILITY_PROTECTED
block|,
name|VISIBILITY_HIDDEN
block|,
name|VISIBILITY_INTERNAL
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|function
struct_decl|;
end_struct_decl

begin_comment
comment|/* This is the name of the object as written by the user.    It is an IDENTIFIER_NODE.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NAME
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_MINIMAL_CHECK (NODE)->decl_minimal.name)
end_define

begin_comment
comment|/* Every ..._DECL node gets a unique number.  */
end_comment

begin_define
define|#
directive|define
name|DECL_UID
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_MINIMAL_CHECK (NODE)->decl_minimal.uid)
end_define

begin_comment
comment|/* These two fields describe where in the source code the declaration    was.  If the declaration appears in several places (as for a C    function that is declared first and then defined later), this    information should refer to the definition.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SOURCE_LOCATION
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_MINIMAL_CHECK (NODE)->decl_minimal.locus)
end_define

begin_define
define|#
directive|define
name|DECL_SOURCE_FILE
parameter_list|(
name|NODE
parameter_list|)
value|LOCATION_FILE (DECL_SOURCE_LOCATION (NODE))
end_define

begin_define
define|#
directive|define
name|DECL_SOURCE_LINE
parameter_list|(
name|NODE
parameter_list|)
value|LOCATION_LINE (DECL_SOURCE_LOCATION (NODE))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MAPPED_LOCATION
end_ifdef

begin_define
define|#
directive|define
name|DECL_IS_BUILTIN
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(DECL_SOURCE_LOCATION (DECL)<= BUILTINS_LOCATION)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECL_IS_BUILTIN
parameter_list|(
name|DECL
parameter_list|)
value|(DECL_SOURCE_LINE(DECL) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  For FIELD_DECLs, this is the RECORD_TYPE, UNION_TYPE, or     QUAL_UNION_TYPE node that the field is a member of.  For VAR_DECL,     PARM_DECL, FUNCTION_DECL, LABEL_DECL, and CONST_DECL nodes, this     points to either the FUNCTION_DECL for the containing function,     the RECORD_TYPE or UNION_TYPE for the containing type, or     NULL_TREE or a TRANSLATION_UNIT_DECL if the given decl has "file     scope".  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_MINIMAL_CHECK (NODE)->decl_minimal.context)
end_define

begin_define
define|#
directive|define
name|DECL_FIELD_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->decl_minimal.context)
end_define

begin_decl_stmt
name|struct
name|tree_decl_minimal
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
name|location_t
name|locus
decl_stmt|;
name|unsigned
name|int
name|uid
decl_stmt|;
name|tree
name|name
decl_stmt|;
name|tree
name|context
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* When computing aliasing information, we represent the memory pointed-to    by pointers with artificial variables called "memory tags" (MT).  There    are two kinds of tags, namely symbol and name:     Symbol tags (SMT) are used in flow-insensitive alias analysis, they    represent all the pointed-to locations and variables pointed-to by    the same pointer symbol.  Usually, this set is computed using    type-based analysis (i.e., alias set classes), but this may not    always be the case.     Name tags (NMT) are used in flow-sensitive points-to alias    analysis, they represent the variables and memory locations    pointed-to by a specific SSA_NAME pointer.     In general, given a pointer P with a symbol tag SMT, the alias set    of SMT should be the union of all the alias sets of the NMTs of    every SSA_NAME for P.  */
end_comment

begin_decl_stmt
name|struct
name|tree_memory_tag
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_minimal
name|common
decl_stmt|;
name|unsigned
name|int
name|is_global
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_used_alone
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|old_used_alone
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|MTAG_GLOBAL
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_MEMORY_TAG_CHECK (NODE)->mtag.is_global)
end_define

begin_comment
comment|/* This flag is true if a SMT is used as the V_MAY_DEF or VUSE operand    directly, because the access had all of the SMT's aliases pruned    from it.  */
end_comment

begin_define
define|#
directive|define
name|SMT_USED_ALONE
parameter_list|(
name|NODE
parameter_list|)
value|(SYMBOL_MEMORY_TAG_CHECK (NODE)->mtag.is_used_alone)
end_define

begin_comment
comment|/* This flag is used to temporarily store the old value of the used alone    flag when updating so we know whether to mark the symbol for    renaming.  */
end_comment

begin_define
define|#
directive|define
name|SMT_OLD_USED_ALONE
parameter_list|(
name|NODE
parameter_list|)
value|(SYMBOL_MEMORY_TAG_CHECK (NODE)->mtag.old_used_alone)
end_define

begin_decl_stmt
name|struct
name|tree_struct_field_tag
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_memory_tag
name|common
decl_stmt|;
comment|/* Parent variable.  */
name|tree
name|parent_var
decl_stmt|;
comment|/* Offset inside structure.  */
name|unsigned
name|HOST_WIDE_INT
name|offset
decl_stmt|;
comment|/* Size of the field.  */
name|unsigned
name|HOST_WIDE_INT
name|size
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|SFT_PARENT_VAR
parameter_list|(
name|NODE
parameter_list|)
value|(STRUCT_FIELD_TAG_CHECK (NODE)->sft.parent_var)
end_define

begin_define
define|#
directive|define
name|SFT_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|(STRUCT_FIELD_TAG_CHECK (NODE)->sft.offset)
end_define

begin_define
define|#
directive|define
name|SFT_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(STRUCT_FIELD_TAG_CHECK (NODE)->sft.size)
end_define

begin_comment
comment|/* For any sort of a ..._DECL node, this points to the original (abstract)    decl node which this decl is an instance of, or else it is NULL indicating    that this decl is not an instance of some other decl.  For example,    in a nested declaration of an inline function, this points back to the    definition.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ABSTRACT_ORIGIN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.abstract_origin)
end_define

begin_comment
comment|/* Like DECL_ABSTRACT_ORIGIN, but returns NODE if there's no abstract    origin.  This is useful when setting the DECL_ABSTRACT_ORIGIN.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ORIGIN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_ABSTRACT_ORIGIN (NODE) ? DECL_ABSTRACT_ORIGIN (NODE) : (NODE))
end_define

begin_comment
comment|/* Nonzero for any sort of ..._DECL node means this decl node represents an    inline instance of some original (abstract) decl from an inline function;    suppress any warnings about shadowing some other variable.  FUNCTION_DECL    nodes can also have their abstract origin set to themselves.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FROM_INLINE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_ABSTRACT_ORIGIN (NODE) != NULL_TREE \&& DECL_ABSTRACT_ORIGIN (NODE) != (NODE))
end_define

begin_comment
comment|/* In a DECL this is the field where attributes are stored.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ATTRIBUTES
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.attributes)
end_define

begin_comment
comment|/* For a FUNCTION_DECL, holds the tree of BINDINGs.    For a TRANSLATION_UNIT_DECL, holds the namespace's BLOCK.    For a VAR_DECL, holds the initial value.    For a PARM_DECL, not used--default    values for parameters are encoded in the type of the function,    not in the PARM_DECL slot.    For a FIELD_DECL, this is used for enumeration values and the C    frontend uses it for temporarily storing bitwidth of bitfields.     ??? Need to figure out some way to check this isn't a PARM_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INITIAL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.initial)
end_define

begin_comment
comment|/* Holds the size of the datum, in bits, as a tree expression.    Need not be constant.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.size)
end_define

begin_comment
comment|/* Likewise for the size in bytes.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.size_unit)
end_define

begin_comment
comment|/* Holds the alignment required for the datum, in bits.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.align)
end_define

begin_comment
comment|/* The alignment of NODE, in bytes.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ALIGN_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_ALIGN (NODE) / BITS_PER_UNIT)
end_define

begin_comment
comment|/* Set if the alignment of this DECL has been set by the user, for    example with an 'aligned' attribute.  */
end_comment

begin_define
define|#
directive|define
name|DECL_USER_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.user_align)
end_define

begin_comment
comment|/* Holds the machine mode corresponding to the declaration of a variable or    field.  Always equal to TYPE_MODE (TREE_TYPE (decl)) except for a    FIELD_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_MODE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.mode)
end_define

begin_comment
comment|/* For FUNCTION_DECL, if it is built-in, this identifies which built-in    operation it is.  Note, however, that this field is overloaded, with    DECL_BUILT_IN_CLASS as the discriminant, so the latter must always be    checked before any access to the former.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FUNCTION_CODE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.function_code)
end_define

begin_define
define|#
directive|define
name|DECL_DEBUG_EXPR_IS_FROM
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_COMMON_CHECK (NODE)->decl_common.debug_expr_is_from)
end_define

begin_comment
comment|/* Nonzero for a given ..._DECL node means that the name of this node should    be ignored for symbolic debug purposes.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IGNORED_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.ignored_flag)
end_define

begin_comment
comment|/* Nonzero for a given ..._DECL node means that this node represents an    "abstract instance" of the given declaration (e.g. in the original    declaration of an inline function).  When generating symbolic debugging    information, we mustn't try to generate any address information for nodes    marked as "abstract instances" because we don't actually generate    any code or allocate any data space for such instances.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ABSTRACT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.abstract_flag)
end_define

begin_comment
comment|/* Language-specific decl information.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LANG_SPECIFIC
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_specific)
end_define

begin_comment
comment|/* In a VAR_DECL or FUNCTION_DECL, nonzero means external reference:    do not allocate storage, and refer to a definition elsewhere.  Note that    this does not necessarily imply the entity represented by NODE    has no program source-level definition in this translation unit.  For    example, for a FUNCTION_DECL, DECL_SAVED_TREE may be non-NULL and    DECL_EXTERNAL may be true simultaneously; that can be the case for    a C99 "extern inline" function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_EXTERNAL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.decl_flag_2)
end_define

begin_comment
comment|/* In a VAR_DECL for a RECORD_TYPE, sets number for non-init_priority    initializations.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_INIT_PRIORITY
value|65535
end_define

begin_define
define|#
directive|define
name|MAX_INIT_PRIORITY
value|65535
end_define

begin_define
define|#
directive|define
name|MAX_RESERVED_INIT_PRIORITY
value|100
end_define

begin_comment
comment|/* Nonzero in a ..._DECL means this variable is ref'd from a nested function.    For VAR_DECL nodes, PARM_DECL nodes, and FUNCTION_DECL nodes.     For LABEL_DECL nodes, nonzero if nonlocal gotos to the label are permitted.     Also set in some languages for variables, etc., outside the normal    lexical scope, such as class instance variables.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NONLOCAL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.nonlocal_flag)
end_define

begin_comment
comment|/* Used in VAR_DECLs to indicate that the variable is a vtable.    Used in FIELD_DECLs for vtable pointers.    Used in FUNCTION_DECLs to indicate that the function is virtual.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VIRTUAL_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.virtual_flag)
end_define

begin_comment
comment|/* Used to indicate that this DECL represents a compiler-generated entity.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ARTIFICIAL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.artificial_flag)
end_define

begin_comment
comment|/* Additional flags for language-specific uses.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_0
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_flag_0)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_1
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_flag_1)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_2
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_flag_2)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_3
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_flag_3)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_4
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_flag_4)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_5
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_flag_5)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_6
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_flag_6)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_7
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_COMMON_CHECK (NODE)->decl_common.lang_flag_7)
end_define

begin_comment
comment|/* Used to indicate an alias set for the memory pointed to by this    particular FIELD_DECL, PARM_DECL, or VAR_DECL, which must have    pointer (or reference) type.  */
end_comment

begin_define
define|#
directive|define
name|DECL_POINTER_ALIAS_SET
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_COMMON_CHECK (NODE)->decl_common.pointer_alias_set)
end_define

begin_comment
comment|/* Nonzero if an alias set has been assigned to this declaration.  */
end_comment

begin_define
define|#
directive|define
name|DECL_POINTER_ALIAS_SET_KNOWN_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_POINTER_ALIAS_SET (NODE) != - 1)
end_define

begin_comment
comment|/* Nonzero for a decl which is at file scope.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FILE_SCOPE_P
parameter_list|(
name|EXP
parameter_list|)
define|\
value|(! DECL_CONTEXT (EXP)						\    || TREE_CODE (DECL_CONTEXT (EXP)) == TRANSLATION_UNIT_DECL)
end_define

begin_comment
comment|/* Nonzero for a decl that is decorated using attribute used.    This indicates compiler tools that this decl needs to be preserved.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PRESERVE_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|DECL_COMMON_CHECK (DECL)->decl_common.preserve_flag
end_define

begin_comment
comment|/* For function local variables of COMPLEX type, indicates that the    variable is not aliased, and that all modifications to the variable    have been adjusted so that they are killing assignments.  Thus the    variable may now be treated as a GIMPLE register, and use real    instead of virtual ops in SSA form.  */
end_comment

begin_define
define|#
directive|define
name|DECL_COMPLEX_GIMPLE_REG_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|DECL_COMMON_CHECK (DECL)->decl_common.gimple_reg_flag
end_define

begin_comment
comment|/* This is true if DECL is call clobbered in the current function.    The result of this flag should always be the same as    bitmap_bit_p (call_clobbered_vars, DECL_UID (decl)).  */
end_comment

begin_define
define|#
directive|define
name|DECL_CALL_CLOBBERED
parameter_list|(
name|DECL
parameter_list|)
define|\
value|DECL_COMMON_CHECK (DECL)->decl_common.call_clobbered_flag
end_define

begin_decl_stmt
name|struct
name|tree_decl_common
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_minimal
name|common
decl_stmt|;
name|tree
name|size
decl_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|machine_mode
argument_list|)
name|mode
label|:
literal|8
expr_stmt|;
name|unsigned
name|nonlocal_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|virtual_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|ignored_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|abstract_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|artificial_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|user_align
range|:
literal|1
decl_stmt|;
name|unsigned
name|preserve_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|debug_expr_is_from
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_0
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_1
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_2
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_3
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_4
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_5
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_6
range|:
literal|1
decl_stmt|;
name|unsigned
name|lang_flag_7
range|:
literal|1
decl_stmt|;
comment|/* In LABEL_DECL, this is DECL_ERROR_ISSUED.      In VAR_DECL and PARM_DECL, this is DECL_REGISTER.  */
name|unsigned
name|decl_flag_0
range|:
literal|1
decl_stmt|;
comment|/* In FIELD_DECL, this is DECL_PACKED.  */
name|unsigned
name|decl_flag_1
range|:
literal|1
decl_stmt|;
comment|/* In FIELD_DECL, this is DECL_BIT_FIELD      In VAR_DECL and FUNCTION_DECL, this is DECL_EXTERNAL.      In TYPE_DECL, this is TYPE_DECL_SUPRESS_DEBUG.  */
name|unsigned
name|decl_flag_2
range|:
literal|1
decl_stmt|;
comment|/* In FIELD_DECL, this is DECL_NONADDRESSABLE_P      In VAR_DECL and PARM_DECL, this is DECL_HAS_VALUE_EXPR.  */
name|unsigned
name|decl_flag_3
range|:
literal|1
decl_stmt|;
comment|/* Logically, these two would go in a theoretical base shared by var and      parm decl. */
name|unsigned
name|gimple_reg_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|call_clobbered_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|align
range|:
literal|24
decl_stmt|;
comment|/* DECL_OFFSET_ALIGN, used only for FIELD_DECLs.  */
name|unsigned
name|int
name|off_align
range|:
literal|8
decl_stmt|;
name|tree
name|size_unit
decl_stmt|;
name|tree
name|initial
decl_stmt|;
name|tree
name|attributes
decl_stmt|;
name|tree
name|abstract_origin
decl_stmt|;
name|HOST_WIDE_INT
name|pointer_alias_set
decl_stmt|;
comment|/* Points to a structure whose details depend on the language in use.  */
name|struct
name|lang_decl
modifier|*
name|lang_specific
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|tree
name|decl_value_expr_lookup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|decl_value_expr_insert
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In a VAR_DECL or PARM_DECL, the location at which the value may be found,    if transformations have made this more complicated than evaluating the    decl itself.  This should only be used for debugging; once this field has    been set, the decl itself may not legitimately appear in the function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_HAS_VALUE_EXPR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TREE_CHECK2 (NODE, VAR_DECL, PARM_DECL)->decl_common.decl_flag_3)
end_define

begin_define
define|#
directive|define
name|DECL_VALUE_EXPR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(decl_value_expr_lookup (DECL_WRTL_CHECK (NODE)))
end_define

begin_define
define|#
directive|define
name|SET_DECL_VALUE_EXPR
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(decl_value_expr_insert (DECL_WRTL_CHECK (NODE), VAL))
end_define

begin_comment
comment|/* Holds the RTL expression for the value of a variable or function.    This value can be evaluated lazily for functions, variables with    static storage duration, and labels.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RTL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_WRTL_CHECK (NODE)->decl_with_rtl.rtl		\    ? (NODE)->decl_with_rtl.rtl					\    : (make_decl_rtl (NODE), (NODE)->decl_with_rtl.rtl))
end_define

begin_comment
comment|/* Set the DECL_RTL for NODE to RTL.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_RTL
parameter_list|(
name|NODE
parameter_list|,
name|RTL
parameter_list|)
value|set_decl_rtl (NODE, RTL)
end_define

begin_comment
comment|/* Returns nonzero if NODE is a tree node that can contain RTL.  */
end_comment

begin_define
define|#
directive|define
name|HAS_RTL_P
parameter_list|(
name|NODE
parameter_list|)
value|(CODE_CONTAINS_STRUCT (TREE_CODE (NODE), TS_DECL_WRTL))
end_define

begin_comment
comment|/* Returns nonzero if the DECL_RTL for NODE has already been set.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RTL_SET_P
parameter_list|(
name|NODE
parameter_list|)
value|(HAS_RTL_P (NODE)&& DECL_WRTL_CHECK (NODE)->decl_with_rtl.rtl != NULL)
end_define

begin_comment
comment|/* Copy the RTL from NODE1 to NODE2.  If the RTL was not set for    NODE1, it will not be set for NODE2; this is a lazy copy.  */
end_comment

begin_define
define|#
directive|define
name|COPY_DECL_RTL
parameter_list|(
name|NODE1
parameter_list|,
name|NODE2
parameter_list|)
define|\
value|(DECL_WRTL_CHECK (NODE2)->decl_with_rtl.rtl = DECL_WRTL_CHECK (NODE1)->decl_with_rtl.rtl)
end_define

begin_comment
comment|/* The DECL_RTL for NODE, if it is set, or NULL, if it is not set.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RTL_IF_SET
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_RTL_SET_P (NODE) ? DECL_RTL (NODE) : NULL)
end_define

begin_comment
comment|/* In VAR_DECL and PARM_DECL nodes, nonzero means declared `register'.  */
end_comment

begin_define
define|#
directive|define
name|DECL_REGISTER
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WRTL_CHECK (NODE)->decl_common.decl_flag_0)
end_define

begin_decl_stmt
name|struct
name|tree_decl_with_rtl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_common
name|common
decl_stmt|;
name|rtx
name|rtl
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In a FIELD_DECL, this is the field position, counting in bytes, of the    DECL_OFFSET_ALIGN-bit-sized word containing the bit closest to the beginning    of the structure.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FIELD_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->field_decl.offset)
end_define

begin_comment
comment|/* In a FIELD_DECL, this is the offset, in bits, of the first bit of the    field from DECL_FIELD_OFFSET.  This field may be nonzero even for fields    that are not bit fields (since DECL_OFFSET_ALIGN may be larger than the    natural alignment of the field's type).  */
end_comment

begin_define
define|#
directive|define
name|DECL_FIELD_BIT_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->field_decl.bit_offset)
end_define

begin_comment
comment|/* In a FIELD_DECL, this indicates whether the field was a bit-field and    if so, the type that was originally specified for it.    TREE_TYPE may have been modified (in finish_struct).  */
end_comment

begin_define
define|#
directive|define
name|DECL_BIT_FIELD_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->field_decl.bit_field_type)
end_define

begin_comment
comment|/* For a FIELD_DECL in a QUAL_UNION_TYPE, records the expression, which    if nonzero, indicates that the field occupies the type.  */
end_comment

begin_define
define|#
directive|define
name|DECL_QUALIFIER
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->field_decl.qualifier)
end_define

begin_comment
comment|/* For FIELD_DECLs, off_align holds the number of low-order bits of    DECL_FIELD_OFFSET which are known to be always zero.    DECL_OFFSET_ALIGN thus returns the alignment that DECL_FIELD_OFFSET    has.  */
end_comment

begin_define
define|#
directive|define
name|DECL_OFFSET_ALIGN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(((unsigned HOST_WIDE_INT)1)<< FIELD_DECL_CHECK (NODE)->decl_common.off_align)
end_define

begin_comment
comment|/* Specify that DECL_ALIGN(NODE) is a multiple of X.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_OFFSET_ALIGN
parameter_list|(
name|NODE
parameter_list|,
name|X
parameter_list|)
define|\
value|(FIELD_DECL_CHECK (NODE)->decl_common.off_align = exact_log2 ((X)& -(X)))
end_define

begin_comment
comment|/* 1 if the alignment for this type was requested by "aligned" attribute,    0 if it is the default for this type.  */
end_comment

begin_comment
comment|/* For FIELD_DECLS, DECL_FCONTEXT is the *first* baseclass in    which this FIELD_DECL is defined.  This information is needed when    writing debugging information about vfield and vbase decls for C++.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FCONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->field_decl.fcontext)
end_define

begin_comment
comment|/* In a FIELD_DECL, indicates this field should be bit-packed.  */
end_comment

begin_define
define|#
directive|define
name|DECL_PACKED
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->decl_common.decl_flag_1)
end_define

begin_comment
comment|/* Nonzero in a FIELD_DECL means it is a bit field, and must be accessed    specially.  */
end_comment

begin_define
define|#
directive|define
name|DECL_BIT_FIELD
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->decl_common.decl_flag_2)
end_define

begin_comment
comment|/* Used in a FIELD_DECL to indicate that we cannot form the address of    this component.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NONADDRESSABLE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FIELD_DECL_CHECK (NODE)->decl_common.decl_flag_3)
end_define

begin_decl_stmt
name|struct
name|tree_field_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_common
name|common
decl_stmt|;
name|tree
name|offset
decl_stmt|;
name|tree
name|bit_field_type
decl_stmt|;
name|tree
name|qualifier
decl_stmt|;
name|tree
name|bit_offset
decl_stmt|;
name|tree
name|fcontext
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* A numeric unique identifier for a LABEL_DECL.  The UID allocation is    dense, unique within any one function, and may be used to index arrays.    If the value is -1, then no UID has been assigned.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_DECL_UID
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(LABEL_DECL_CHECK (NODE)->decl_common.pointer_alias_set)
end_define

begin_comment
comment|/* In LABEL_DECL nodes, nonzero means that an error message about    jumping into such a binding contour has been printed for this label.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ERROR_ISSUED
parameter_list|(
name|NODE
parameter_list|)
value|(LABEL_DECL_CHECK (NODE)->decl_common.decl_flag_0)
end_define

begin_decl_stmt
name|struct
name|tree_label_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_with_rtl
name|common
decl_stmt|;
comment|/* Java's verifier has some need to store information about labels,      and was using fields that no longer exist on labels.      Once the verifier doesn't need these anymore, they should be removed.  */
name|tree
name|java_field_1
decl_stmt|;
name|tree
name|java_field_2
decl_stmt|;
name|tree
name|java_field_3
decl_stmt|;
name|unsigned
name|int
name|java_field_4
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|tree_result_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_with_rtl
name|common
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|tree_const_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_with_rtl
name|common
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* For a PARM_DECL, records the data type used to pass the argument,    which may be different from the type seen in the program.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ARG_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|(PARM_DECL_CHECK (NODE)->decl_common.initial)
end_define

begin_comment
comment|/* For PARM_DECL, holds an RTL for the stack slot or register    where the data was actually passed.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INCOMING_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(PARM_DECL_CHECK (NODE)->parm_decl.incoming_rtl)
end_define

begin_decl_stmt
name|struct
name|tree_parm_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_with_rtl
name|common
decl_stmt|;
name|rtx
name|incoming_rtl
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Nonzero in a decl means that the gimplifier has seen (or placed)    this variable in a BIND_EXPR.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SEEN_IN_BIND_EXPR_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.seen_in_bind_expr)
end_define

begin_comment
comment|/* Used to indicate that the linkage status of this DECL is not yet known,    so it should not be output now.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DEFER_OUTPUT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.defer_output)
end_define

begin_comment
comment|/* Nonzero for a given ..._DECL node means that no warnings should be    generated just because this node is unused.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IN_SYSTEM_HEADER
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.in_system_header_flag)
end_define

begin_comment
comment|/* Used to indicate that this DECL has weak linkage.  */
end_comment

begin_define
define|#
directive|define
name|DECL_WEAK
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.weak_flag)
end_define

begin_comment
comment|/* Internal to the gimplifier.  Indicates that the value is a formal    temporary controlled by the gimplifier.  */
end_comment

begin_define
define|#
directive|define
name|DECL_GIMPLE_FORMAL_TEMP_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|DECL_WITH_VIS_CHECK (DECL)->decl_with_vis.gimple_formal_temp
end_define

begin_comment
comment|/* Used to indicate that the DECL is a dllimport.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DLLIMPORT_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.dllimport_flag)
end_define

begin_comment
comment|/* DECL_BASED_ON_RESTRICT_P records whether a VAR_DECL is a temporary    based on a variable with a restrict qualified type.  If it is,    DECL_RESTRICT_BASE returns the restrict qualified variable on which    it is based.  */
end_comment

begin_define
define|#
directive|define
name|DECL_BASED_ON_RESTRICT_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VAR_DECL_CHECK (NODE)->decl_with_vis.based_on_restrict_p)
end_define

begin_define
define|#
directive|define
name|DECL_GET_RESTRICT_BASE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(decl_restrict_base_lookup (VAR_DECL_CHECK (NODE)))
end_define

begin_define
define|#
directive|define
name|SET_DECL_RESTRICT_BASE
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(decl_restrict_base_insert (VAR_DECL_CHECK (NODE), (VAL)))
end_define

begin_function_decl
specifier|extern
name|tree
name|decl_restrict_base_lookup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|decl_restrict_base_insert
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used in a DECL to indicate that, even if it TREE_PUBLIC, it need    not be put out unless it is needed in this translation unit.    Entities like this are shared across translation units (like weak    entities), but are guaranteed to be generated by any translation    unit that needs them, and therefore need not be put out anywhere    where they are not needed.  DECL_COMDAT is just a hint to the    back-end; it is up to front-ends which set this flag to ensure    that there will never be any harm, other than bloat, in putting out    something which is DECL_COMDAT.  */
end_comment

begin_define
define|#
directive|define
name|DECL_COMDAT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.comdat_flag)
end_define

begin_comment
comment|/* A replaceable function is one which may be replaced at link-time    with an entirely different definition, provided that the    replacement has the same type.  For example, functions declared    with __attribute__((weak)) on most systems are replaceable.       COMDAT functions are not replaceable, since all definitions of the    function must be equivalent.  It is important that COMDAT functions    not be treated as replaceable so that use of C++ template    instantiations is not penalized.       For example, DECL_REPLACEABLE is used to determine whether or not a    function (including a template instantiation) which is not    explicitly declared "inline" can be inlined.  If the function is    DECL_REPLACEABLE then it is not safe to do the inlining, since the    implementation chosen at link-time may be different.  However, a    function that is not DECL_REPLACEABLE can be inlined, since all    versions of the function will be functionally identical.  */
end_comment

begin_define
define|#
directive|define
name|DECL_REPLACEABLE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(!DECL_COMDAT (NODE)&& !targetm.binds_local_p (NODE))
end_define

begin_comment
comment|/* The name of the object as the assembler will see it (but before any    translations made by ASM_OUTPUT_LABELREF).  Often this is the same    as DECL_NAME.  It is an IDENTIFIER_NODE.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ASSEMBLER_NAME
parameter_list|(
name|NODE
parameter_list|)
value|decl_assembler_name (NODE)
end_define

begin_comment
comment|/* Return true if NODE is a NODE that can contain a DECL_ASSEMBLER_NAME.    This is true of all DECL nodes except FIELD_DECL.  */
end_comment

begin_define
define|#
directive|define
name|HAS_DECL_ASSEMBLER_NAME_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(CODE_CONTAINS_STRUCT (TREE_CODE (NODE), TS_DECL_WITH_VIS))
end_define

begin_comment
comment|/* Returns nonzero if the DECL_ASSEMBLER_NAME for NODE has been set.  If zero,    the NODE might still have a DECL_ASSEMBLER_NAME -- it just hasn't been set    yet.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ASSEMBLER_NAME_SET_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(HAS_DECL_ASSEMBLER_NAME_P (NODE)&&  DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.assembler_name != NULL_TREE)
end_define

begin_comment
comment|/* Set the DECL_ASSEMBLER_NAME for NODE to NAME.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECL_ASSEMBLER_NAME
parameter_list|(
name|NODE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.assembler_name = (NAME))
end_define

begin_comment
comment|/* Copy the DECL_ASSEMBLER_NAME from DECL1 to DECL2.  Note that if DECL1's    DECL_ASSEMBLER_NAME has not yet been set, using this macro will not cause    the DECL_ASSEMBLER_NAME of either DECL to be set.  In other words, the    semantics of using this macro, are different than saying:       SET_DECL_ASSEMBLER_NAME(DECL2, DECL_ASSEMBLER_NAME (DECL1))     which will try to set the DECL_ASSEMBLER_NAME for DECL1.  */
end_comment

begin_define
define|#
directive|define
name|COPY_DECL_ASSEMBLER_NAME
parameter_list|(
name|DECL1
parameter_list|,
name|DECL2
parameter_list|)
define|\
value|(DECL_ASSEMBLER_NAME_SET_P (DECL1)					\    ? (void) SET_DECL_ASSEMBLER_NAME (DECL2,				\ 				     DECL_ASSEMBLER_NAME (DECL1))	\    : (void) 0)
end_define

begin_comment
comment|/* Records the section name in a section attribute.  Used to pass    the name from decl_attributes to make_function_rtl and make_decl_rtl.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SECTION_NAME
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.section_name)
end_define

begin_comment
comment|/* Value of the decls's visibility attribute */
end_comment

begin_define
define|#
directive|define
name|DECL_VISIBILITY
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.visibility)
end_define

begin_comment
comment|/* Nonzero means that the decl had its visibility specified rather than    being inferred.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VISIBILITY_SPECIFIED
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.visibility_specified)
end_define

begin_comment
comment|/* Used in TREE_PUBLIC decls to indicate that copies of this DECL in    multiple translation units should be merged.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ONE_ONLY
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.one_only)
end_define

begin_decl_stmt
name|struct
name|tree_decl_with_vis
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_with_rtl
name|common
decl_stmt|;
name|tree
name|assembler_name
decl_stmt|;
name|tree
name|section_name
decl_stmt|;
comment|/* Belong to VAR_DECL exclusively.  */
name|unsigned
name|defer_output
range|:
literal|1
decl_stmt|;
name|unsigned
name|hard_register
range|:
literal|1
decl_stmt|;
name|unsigned
name|thread_local
range|:
literal|1
decl_stmt|;
name|unsigned
name|common_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|in_text_section
range|:
literal|1
decl_stmt|;
name|unsigned
name|gimple_formal_temp
range|:
literal|1
decl_stmt|;
name|unsigned
name|dllimport_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|based_on_restrict_p
range|:
literal|1
decl_stmt|;
comment|/* Used by C++.  Might become a generic decl flag.  */
name|unsigned
name|shadowed_for_var_p
range|:
literal|1
decl_stmt|;
comment|/* Don't belong to VAR_DECL exclusively.  */
name|unsigned
name|in_system_header_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|weak_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|seen_in_bind_expr
range|:
literal|1
decl_stmt|;
name|unsigned
name|comdat_flag
range|:
literal|1
decl_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|symbol_visibility
argument_list|)
name|visibility
label|:
literal|2
expr_stmt|;
name|unsigned
name|visibility_specified
range|:
literal|1
decl_stmt|;
comment|/* Belong to FUNCTION_DECL exclusively.  */
name|unsigned
name|one_only
range|:
literal|1
decl_stmt|;
name|unsigned
name|init_priority_p
range|:
literal|1
decl_stmt|;
comment|/* Belongs to VAR_DECL exclusively.  */
name|ENUM_BITFIELD
argument_list|(
argument|tls_model
argument_list|)
name|tls_model
label|:
literal|3
expr_stmt|;
comment|/* 11 unused bits. */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In a VAR_DECL that's static,    nonzero if the space is in the text section.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IN_TEXT_SECTION
parameter_list|(
name|NODE
parameter_list|)
value|(VAR_DECL_CHECK (NODE)->decl_with_vis.in_text_section)
end_define

begin_comment
comment|/* Nonzero for a given ..._DECL node means that this node should be    put in .common, if possible.  If a DECL_INITIAL is given, and it    is not error_mark_node, then the decl cannot be put in .common.  */
end_comment

begin_define
define|#
directive|define
name|DECL_COMMON
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_WITH_VIS_CHECK (NODE)->decl_with_vis.common_flag)
end_define

begin_comment
comment|/* In a VAR_DECL, nonzero if the decl is a register variable with    an explicit asm specification.  */
end_comment

begin_define
define|#
directive|define
name|DECL_HARD_REGISTER
parameter_list|(
name|NODE
parameter_list|)
value|(VAR_DECL_CHECK (NODE)->decl_with_vis.hard_register)
end_define

begin_function_decl
specifier|extern
name|tree
name|decl_debug_expr_lookup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|decl_debug_expr_insert
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For VAR_DECL, this is set to either an expression that it was split    from (if DECL_DEBUG_EXPR_IS_FROM is true), otherwise a tree_list of    subexpressions that it was split into.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DEBUG_EXPR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(decl_debug_expr_lookup (VAR_DECL_CHECK (NODE)))
end_define

begin_define
define|#
directive|define
name|SET_DECL_DEBUG_EXPR
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(decl_debug_expr_insert (VAR_DECL_CHECK (NODE), VAL))
end_define

begin_function_decl
specifier|extern
name|unsigned
name|short
name|decl_init_priority_lookup
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|decl_init_priority_insert
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In a non-local VAR_DECL with static storage duration, this is the    initialization priority.  If this value is zero, the NODE will be    initialized at the DEFAULT_INIT_PRIORITY.  Only used by C++ FE*/
end_comment

begin_define
define|#
directive|define
name|DECL_HAS_INIT_PRIORITY_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VAR_DECL_CHECK (NODE)->decl_with_vis.init_priority_p)
end_define

begin_define
define|#
directive|define
name|DECL_INIT_PRIORITY
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(decl_init_priority_lookup (VAR_DECL_CHECK (NODE)))
end_define

begin_define
define|#
directive|define
name|SET_DECL_INIT_PRIORITY
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(decl_init_priority_insert (VAR_DECL_CHECK (NODE), VAL))
end_define

begin_comment
comment|/* In a VAR_DECL, the model to use if the data should be allocated from    thread-local storage.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TLS_MODEL
parameter_list|(
name|NODE
parameter_list|)
value|(VAR_DECL_CHECK (NODE)->decl_with_vis.tls_model)
end_define

begin_comment
comment|/* In a VAR_DECL, nonzero if the data should be allocated from    thread-local storage.  */
end_comment

begin_define
define|#
directive|define
name|DECL_THREAD_LOCAL_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VAR_DECL_CHECK (NODE)->decl_with_vis.tls_model != TLS_MODEL_NONE)
end_define

begin_decl_stmt
name|struct
name|tree_var_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_with_vis
name|common
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* This field is used to reference anything in decl.result and is meant only    for use by the garbage collector.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RESULT_FLD
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_NON_COMMON_CHECK (NODE)->decl_non_common.result)
end_define

begin_comment
comment|/* The DECL_VINDEX is used for FUNCTION_DECLS in two different ways.    Before the struct containing the FUNCTION_DECL is laid out,    DECL_VINDEX may point to a FUNCTION_DECL in a base class which    is the FUNCTION_DECL which this FUNCTION_DECL will replace as a virtual    function.  When the class is laid out, this pointer is changed    to an INTEGER_CST node which is suitable for use as an index    into the virtual function table.    C++ also uses this field in namespaces, hence the DECL_NON_COMMON_CHECK.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VINDEX
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_NON_COMMON_CHECK (NODE)->decl_non_common.vindex)
end_define

begin_decl_stmt
name|struct
name|tree_decl_non_common
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_with_vis
name|common
decl_stmt|;
comment|/* C++ uses this in namespaces.  */
name|tree
name|saved_tree
decl_stmt|;
comment|/* C++ uses this in templates.  */
name|tree
name|arguments
decl_stmt|;
comment|/* Almost all FE's use this.  */
name|tree
name|result
decl_stmt|;
comment|/* C++ uses this in namespaces.  */
name|tree
name|vindex
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* In FUNCTION_DECL, holds the decl for the return value.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RESULT
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->decl_non_common.result)
end_define

begin_comment
comment|/* In a FUNCTION_DECL, nonzero if the function cannot be inlined.  */
end_comment

begin_define
define|#
directive|define
name|DECL_UNINLINABLE
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.uninlinable)
end_define

begin_comment
comment|/* In a FUNCTION_DECL, the saved representation of the body of the    entire function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SAVED_TREE
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->decl_non_common.saved_tree)
end_define

begin_comment
comment|/* Nonzero in a FUNCTION_DECL means this function should be treated    as if it were a malloc, meaning it returns a pointer that is    not an alias.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IS_MALLOC
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.malloc_flag)
end_define

begin_comment
comment|/* Nonzero in a FUNCTION_DECL means this function may return more    than once.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IS_RETURNS_TWICE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.returns_twice_flag)
end_define

begin_comment
comment|/* Nonzero in a FUNCTION_DECL means this function should be treated    as "pure" function (like const function, but may read global memory).  */
end_comment

begin_define
define|#
directive|define
name|DECL_IS_PURE
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.pure_flag)
end_define

begin_comment
comment|/* Nonzero in a FUNCTION_DECL means this function should be treated    as "novops" function (function that does not read global memory,    but may have arbitrary side effects).  */
end_comment

begin_define
define|#
directive|define
name|DECL_IS_NOVOPS
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.novops_flag)
end_define

begin_comment
comment|/* Used in FUNCTION_DECLs to indicate that they should be run automatically    at the beginning or end of execution.  */
end_comment

begin_define
define|#
directive|define
name|DECL_STATIC_CONSTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.static_ctor_flag)
end_define

begin_define
define|#
directive|define
name|DECL_STATIC_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.static_dtor_flag)
end_define

begin_comment
comment|/* Used in FUNCTION_DECLs to indicate that function entry and exit should    be instrumented with calls to support routines.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NO_INSTRUMENT_FUNCTION_ENTRY_EXIT
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.no_instrument_function_entry_exit)
end_define

begin_comment
comment|/* Used in FUNCTION_DECLs to indicate that limit-stack-* should be    disabled in this function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NO_LIMIT_STACK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.no_limit_stack)
end_define

begin_comment
comment|/* In a FUNCTION_DECL with a nonzero DECL_CONTEXT, indicates that a    static chain is not needed.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NO_STATIC_CHAIN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.regdecl_flag)
end_define

begin_comment
comment|/* Nonzero for a decl that cgraph has decided should be inlined into    at least one call site.  It is not meaningful to look at this    directly; always use cgraph_function_possibly_inlined_p.  */
end_comment

begin_define
define|#
directive|define
name|DECL_POSSIBLY_INLINED
parameter_list|(
name|DECL
parameter_list|)
define|\
value|FUNCTION_DECL_CHECK (DECL)->function_decl.possibly_inlined
end_define

begin_comment
comment|/* Nonzero in a FUNCTION_DECL means this function can be substituted    where it is called.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INLINE
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.inline_flag)
end_define

begin_comment
comment|/* Nonzero in a FUNCTION_DECL means that this function was declared inline,    such as via the `inline' keyword in C/C++.  This flag controls the linkage    semantics of 'inline'; whether or not the function is inlined is    controlled by DECL_INLINE.  */
end_comment

begin_define
define|#
directive|define
name|DECL_DECLARED_INLINE_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.declared_inline_flag)
end_define

begin_comment
comment|/* For FUNCTION_DECL, this holds a pointer to a structure ("struct function")    that describes the status of this function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_STRUCT_FUNCTION
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.f)
end_define

begin_comment
comment|/* In a FUNCTION_DECL, nonzero means a built in function.  */
end_comment

begin_define
define|#
directive|define
name|DECL_BUILT_IN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_BUILT_IN_CLASS (NODE) != NOT_BUILT_IN)
end_define

begin_comment
comment|/* For a builtin function, identify which part of the compiler defined it.  */
end_comment

begin_define
define|#
directive|define
name|DECL_BUILT_IN_CLASS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->function_decl.built_in_class)
end_define

begin_comment
comment|/* In FUNCTION_DECL, a chain of ..._DECL nodes.    VAR_DECL and PARM_DECL reserve the arguments slot for language-specific    uses.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ARGUMENTS
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->decl_non_common.arguments)
end_define

begin_define
define|#
directive|define
name|DECL_ARGUMENT_FLD
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_NON_COMMON_CHECK (NODE)->decl_non_common.arguments)
end_define

begin_comment
comment|/* FUNCTION_DECL inherits from DECL_NON_COMMON because of the use of the    arguments/result/saved_tree fields by front ends.   It was either inherit    FUNCTION_DECL from non_common, or inherit non_common from FUNCTION_DECL,    which seemed a bit strange.  */
end_comment

begin_decl_stmt
name|struct
name|tree_function_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_non_common
name|common
decl_stmt|;
comment|/* In a FUNCTION_DECL for which DECL_BUILT_IN holds, this is      DECL_FUNCTION_CODE.  Otherwise unused.  */
name|enum
name|built_in_function
name|function_code
decl_stmt|;
name|unsigned
name|static_ctor_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|static_dtor_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|uninlinable
range|:
literal|1
decl_stmt|;
name|unsigned
name|possibly_inlined
range|:
literal|1
decl_stmt|;
name|unsigned
name|novops_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|returns_twice_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|malloc_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|pure_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|declared_inline_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|regdecl_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|inline_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|no_instrument_function_entry_exit
range|:
literal|1
decl_stmt|;
name|unsigned
name|no_limit_stack
range|:
literal|1
decl_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|built_in_class
argument_list|)
name|built_in_class
label|:
literal|2
expr_stmt|;
name|struct
name|function
modifier|*
name|f
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* For a TYPE_DECL, holds the "original" type.  (TREE_TYPE has the copy.) */
end_comment

begin_define
define|#
directive|define
name|DECL_ORIGINAL_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_DECL_CHECK (NODE)->decl_non_common.result)
end_define

begin_comment
comment|/* In a TYPE_DECL nonzero means the detail info about this type is not dumped    into stabs.  Instead it will generate cross reference ('x') of names.    This uses the same flag as DECL_EXTERNAL.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_DECL_SUPPRESS_DEBUG
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_DECL_CHECK (NODE)->decl_common.decl_flag_2)
end_define

begin_decl_stmt
name|struct
name|tree_type_decl
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|tree_decl_non_common
name|common
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* A STATEMENT_LIST chains statements together in GENERIC and GIMPLE.    To reduce overhead, the nodes containing the statements are not trees.    This avoids the overhead of tree_common on all linked list elements.     Use the interface in tree-iterator.h to access this node.  */
end_comment

begin_define
define|#
directive|define
name|STATEMENT_LIST_HEAD
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(STATEMENT_LIST_CHECK (NODE)->stmt_list.head)
end_define

begin_define
define|#
directive|define
name|STATEMENT_LIST_TAIL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(STATEMENT_LIST_CHECK (NODE)->stmt_list.tail)
end_define

begin_decl_stmt
name|struct
name|tree_statement_list_node
name|GTY
argument_list|(
operator|(
name|chain_next
argument_list|(
literal|"%h.next"
argument_list|)
operator|,
name|chain_prev
argument_list|(
literal|"%h.prev"
argument_list|)
operator|)
argument_list|)
block|{
name|struct
name|tree_statement_list_node
modifier|*
name|prev
decl_stmt|;
name|struct
name|tree_statement_list_node
modifier|*
name|next
decl_stmt|;
name|tree
name|stmt
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|tree_statement_list
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
name|tree_statement_list_node
modifier|*
name|head
decl_stmt|;
name|struct
name|tree_statement_list_node
modifier|*
name|tail
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|VALUE_HANDLE_ID
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VALUE_HANDLE_CHECK (NODE)->value_handle.id)
end_define

begin_define
define|#
directive|define
name|VALUE_HANDLE_EXPR_SET
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VALUE_HANDLE_CHECK (NODE)->value_handle.expr_set)
end_define

begin_define
define|#
directive|define
name|VALUE_HANDLE_VUSES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(VALUE_HANDLE_CHECK (NODE)->value_handle.vuses)
end_define

begin_comment
comment|/* Defined and used in tree-ssa-pre.c.  */
end_comment

begin_struct_decl
struct_decl|struct
name|value_set
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|tree_value_handle
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
comment|/* The set of expressions represented by this handle.  */
name|struct
name|value_set
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|expr_set
decl_stmt|;
comment|/* Unique ID for this value handle.  IDs are handed out in a      conveniently dense form starting at 0, so that we can make      bitmaps of value handles.  */
name|unsigned
name|int
name|id
decl_stmt|;
comment|/* Set of virtual uses represented by this handle.  */
name|VEC
argument_list|(
name|tree
argument_list|,
name|gc
argument_list|)
operator|*
name|vuses
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* Define the overall contents of a tree node.    It may be any of the structures declared above    for various types of node.  */
end_comment

begin_decl_stmt
name|union
name|tree_node
name|GTY
argument_list|(
operator|(
name|ptr_alias
argument_list|(
expr|union
name|lang_tree_node
argument_list|)
operator|,
name|desc
argument_list|(
literal|"tree_node_structure (&%h)"
argument_list|)
operator|)
argument_list|)
block|{
name|struct
name|tree_common
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_COMMON"
argument_list|)
operator|)
argument_list|)
name|common
decl_stmt|;
name|struct
name|tree_int_cst
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_INT_CST"
argument_list|)
operator|)
argument_list|)
name|int_cst
decl_stmt|;
name|struct
name|tree_real_cst
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_REAL_CST"
argument_list|)
operator|)
argument_list|)
name|real_cst
decl_stmt|;
name|struct
name|tree_vector
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_VECTOR"
argument_list|)
operator|)
argument_list|)
name|vector
decl_stmt|;
name|struct
name|tree_string
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_STRING"
argument_list|)
operator|)
argument_list|)
name|string
decl_stmt|;
name|struct
name|tree_complex
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_COMPLEX"
argument_list|)
operator|)
argument_list|)
name|complex
decl_stmt|;
name|struct
name|tree_identifier
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_IDENTIFIER"
argument_list|)
operator|)
argument_list|)
name|identifier
decl_stmt|;
name|struct
name|tree_decl_minimal
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_DECL_MINIMAL"
argument_list|)
operator|)
argument_list|)
name|decl_minimal
decl_stmt|;
name|struct
name|tree_decl_common
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_DECL_COMMON"
argument_list|)
operator|)
argument_list|)
name|decl_common
decl_stmt|;
name|struct
name|tree_decl_with_rtl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_DECL_WRTL"
argument_list|)
operator|)
argument_list|)
name|decl_with_rtl
decl_stmt|;
name|struct
name|tree_decl_non_common
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_DECL_NON_COMMON"
argument_list|)
operator|)
argument_list|)
name|decl_non_common
decl_stmt|;
name|struct
name|tree_parm_decl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_PARM_DECL"
argument_list|)
operator|)
argument_list|)
name|parm_decl
decl_stmt|;
name|struct
name|tree_decl_with_vis
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_DECL_WITH_VIS"
argument_list|)
operator|)
argument_list|)
name|decl_with_vis
decl_stmt|;
name|struct
name|tree_var_decl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_VAR_DECL"
argument_list|)
operator|)
argument_list|)
name|var_decl
decl_stmt|;
name|struct
name|tree_field_decl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_FIELD_DECL"
argument_list|)
operator|)
argument_list|)
name|field_decl
decl_stmt|;
name|struct
name|tree_label_decl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_LABEL_DECL"
argument_list|)
operator|)
argument_list|)
name|label_decl
decl_stmt|;
name|struct
name|tree_result_decl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_RESULT_DECL"
argument_list|)
operator|)
argument_list|)
name|result_decl
decl_stmt|;
name|struct
name|tree_const_decl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CONST_DECL"
argument_list|)
operator|)
argument_list|)
name|const_decl
decl_stmt|;
name|struct
name|tree_type_decl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_TYPE_DECL"
argument_list|)
operator|)
argument_list|)
name|type_decl
decl_stmt|;
name|struct
name|tree_function_decl
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_FUNCTION_DECL"
argument_list|)
operator|)
argument_list|)
name|function_decl
decl_stmt|;
name|struct
name|tree_type
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_TYPE"
argument_list|)
operator|)
argument_list|)
name|type
decl_stmt|;
name|struct
name|tree_list
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_LIST"
argument_list|)
operator|)
argument_list|)
name|list
decl_stmt|;
name|struct
name|tree_vec
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_VEC"
argument_list|)
operator|)
argument_list|)
name|vec
decl_stmt|;
name|struct
name|tree_exp
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_EXP"
argument_list|)
operator|)
argument_list|)
name|exp
decl_stmt|;
name|struct
name|tree_ssa_name
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_SSA_NAME"
argument_list|)
operator|)
argument_list|)
name|ssa_name
decl_stmt|;
name|struct
name|tree_phi_node
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_PHI_NODE"
argument_list|)
operator|)
argument_list|)
name|phi
decl_stmt|;
name|struct
name|tree_block
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_BLOCK"
argument_list|)
operator|)
argument_list|)
name|block
decl_stmt|;
name|struct
name|tree_binfo
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_BINFO"
argument_list|)
operator|)
argument_list|)
name|binfo
decl_stmt|;
name|struct
name|tree_statement_list
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_STATEMENT_LIST"
argument_list|)
operator|)
argument_list|)
name|stmt_list
decl_stmt|;
name|struct
name|tree_value_handle
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_VALUE_HANDLE"
argument_list|)
operator|)
argument_list|)
name|value_handle
decl_stmt|;
name|struct
name|tree_constructor
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_CONSTRUCTOR"
argument_list|)
operator|)
argument_list|)
name|constructor
decl_stmt|;
name|struct
name|tree_memory_tag
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_MEMORY_TAG"
argument_list|)
operator|)
argument_list|)
name|mtag
decl_stmt|;
name|struct
name|tree_struct_field_tag
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_STRUCT_FIELD_TAG"
argument_list|)
operator|)
argument_list|)
name|sft
decl_stmt|;
name|struct
name|tree_omp_clause
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"TS_OMP_CLAUSE"
argument_list|)
operator|)
argument_list|)
name|omp_clause
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/* Standard named or nameless data types of the C compiler.  */
end_comment

begin_enum
enum|enum
name|tree_index
block|{
name|TI_ERROR_MARK
block|,
name|TI_INTQI_TYPE
block|,
name|TI_INTHI_TYPE
block|,
name|TI_INTSI_TYPE
block|,
name|TI_INTDI_TYPE
block|,
name|TI_INTTI_TYPE
block|,
name|TI_UINTQI_TYPE
block|,
name|TI_UINTHI_TYPE
block|,
name|TI_UINTSI_TYPE
block|,
name|TI_UINTDI_TYPE
block|,
name|TI_UINTTI_TYPE
block|,
name|TI_INTEGER_ZERO
block|,
name|TI_INTEGER_ONE
block|,
name|TI_INTEGER_MINUS_ONE
block|,
name|TI_NULL_POINTER
block|,
name|TI_SIZE_ZERO
block|,
name|TI_SIZE_ONE
block|,
name|TI_BITSIZE_ZERO
block|,
name|TI_BITSIZE_ONE
block|,
name|TI_BITSIZE_UNIT
block|,
name|TI_PUBLIC
block|,
name|TI_PROTECTED
block|,
name|TI_PRIVATE
block|,
name|TI_BOOLEAN_FALSE
block|,
name|TI_BOOLEAN_TRUE
block|,
name|TI_COMPLEX_INTEGER_TYPE
block|,
name|TI_COMPLEX_FLOAT_TYPE
block|,
name|TI_COMPLEX_DOUBLE_TYPE
block|,
name|TI_COMPLEX_LONG_DOUBLE_TYPE
block|,
name|TI_FLOAT_TYPE
block|,
name|TI_DOUBLE_TYPE
block|,
name|TI_LONG_DOUBLE_TYPE
block|,
name|TI_FLOAT_PTR_TYPE
block|,
name|TI_DOUBLE_PTR_TYPE
block|,
name|TI_LONG_DOUBLE_PTR_TYPE
block|,
name|TI_INTEGER_PTR_TYPE
block|,
name|TI_VOID_TYPE
block|,
name|TI_PTR_TYPE
block|,
name|TI_CONST_PTR_TYPE
block|,
name|TI_SIZE_TYPE
block|,
name|TI_PID_TYPE
block|,
name|TI_PTRDIFF_TYPE
block|,
name|TI_VA_LIST_TYPE
block|,
name|TI_VA_LIST_GPR_COUNTER_FIELD
block|,
name|TI_VA_LIST_FPR_COUNTER_FIELD
block|,
name|TI_BOOLEAN_TYPE
block|,
name|TI_FILEPTR_TYPE
block|,
name|TI_DFLOAT32_TYPE
block|,
name|TI_DFLOAT64_TYPE
block|,
name|TI_DFLOAT128_TYPE
block|,
name|TI_DFLOAT32_PTR_TYPE
block|,
name|TI_DFLOAT64_PTR_TYPE
block|,
name|TI_DFLOAT128_PTR_TYPE
block|,
name|TI_VOID_LIST_NODE
block|,
name|TI_MAIN_IDENTIFIER
block|,
name|TI_MAX
block|}
enum|;
end_enum

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|global_trees
index|[
name|TI_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|error_mark_node
value|global_trees[TI_ERROR_MARK]
end_define

begin_define
define|#
directive|define
name|intQI_type_node
value|global_trees[TI_INTQI_TYPE]
end_define

begin_define
define|#
directive|define
name|intHI_type_node
value|global_trees[TI_INTHI_TYPE]
end_define

begin_define
define|#
directive|define
name|intSI_type_node
value|global_trees[TI_INTSI_TYPE]
end_define

begin_define
define|#
directive|define
name|intDI_type_node
value|global_trees[TI_INTDI_TYPE]
end_define

begin_define
define|#
directive|define
name|intTI_type_node
value|global_trees[TI_INTTI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_intQI_type_node
value|global_trees[TI_UINTQI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_intHI_type_node
value|global_trees[TI_UINTHI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_intSI_type_node
value|global_trees[TI_UINTSI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_intDI_type_node
value|global_trees[TI_UINTDI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_intTI_type_node
value|global_trees[TI_UINTTI_TYPE]
end_define

begin_define
define|#
directive|define
name|integer_zero_node
value|global_trees[TI_INTEGER_ZERO]
end_define

begin_define
define|#
directive|define
name|integer_one_node
value|global_trees[TI_INTEGER_ONE]
end_define

begin_define
define|#
directive|define
name|integer_minus_one_node
value|global_trees[TI_INTEGER_MINUS_ONE]
end_define

begin_define
define|#
directive|define
name|size_zero_node
value|global_trees[TI_SIZE_ZERO]
end_define

begin_define
define|#
directive|define
name|size_one_node
value|global_trees[TI_SIZE_ONE]
end_define

begin_define
define|#
directive|define
name|bitsize_zero_node
value|global_trees[TI_BITSIZE_ZERO]
end_define

begin_define
define|#
directive|define
name|bitsize_one_node
value|global_trees[TI_BITSIZE_ONE]
end_define

begin_define
define|#
directive|define
name|bitsize_unit_node
value|global_trees[TI_BITSIZE_UNIT]
end_define

begin_comment
comment|/* Base access nodes.  */
end_comment

begin_define
define|#
directive|define
name|access_public_node
value|global_trees[TI_PUBLIC]
end_define

begin_define
define|#
directive|define
name|access_protected_node
value|global_trees[TI_PROTECTED]
end_define

begin_define
define|#
directive|define
name|access_private_node
value|global_trees[TI_PRIVATE]
end_define

begin_define
define|#
directive|define
name|null_pointer_node
value|global_trees[TI_NULL_POINTER]
end_define

begin_define
define|#
directive|define
name|float_type_node
value|global_trees[TI_FLOAT_TYPE]
end_define

begin_define
define|#
directive|define
name|double_type_node
value|global_trees[TI_DOUBLE_TYPE]
end_define

begin_define
define|#
directive|define
name|long_double_type_node
value|global_trees[TI_LONG_DOUBLE_TYPE]
end_define

begin_define
define|#
directive|define
name|float_ptr_type_node
value|global_trees[TI_FLOAT_PTR_TYPE]
end_define

begin_define
define|#
directive|define
name|double_ptr_type_node
value|global_trees[TI_DOUBLE_PTR_TYPE]
end_define

begin_define
define|#
directive|define
name|long_double_ptr_type_node
value|global_trees[TI_LONG_DOUBLE_PTR_TYPE]
end_define

begin_define
define|#
directive|define
name|integer_ptr_type_node
value|global_trees[TI_INTEGER_PTR_TYPE]
end_define

begin_define
define|#
directive|define
name|complex_integer_type_node
value|global_trees[TI_COMPLEX_INTEGER_TYPE]
end_define

begin_define
define|#
directive|define
name|complex_float_type_node
value|global_trees[TI_COMPLEX_FLOAT_TYPE]
end_define

begin_define
define|#
directive|define
name|complex_double_type_node
value|global_trees[TI_COMPLEX_DOUBLE_TYPE]
end_define

begin_define
define|#
directive|define
name|complex_long_double_type_node
value|global_trees[TI_COMPLEX_LONG_DOUBLE_TYPE]
end_define

begin_define
define|#
directive|define
name|void_type_node
value|global_trees[TI_VOID_TYPE]
end_define

begin_comment
comment|/* The C type `void *'.  */
end_comment

begin_define
define|#
directive|define
name|ptr_type_node
value|global_trees[TI_PTR_TYPE]
end_define

begin_comment
comment|/* The C type `const void *'.  */
end_comment

begin_define
define|#
directive|define
name|const_ptr_type_node
value|global_trees[TI_CONST_PTR_TYPE]
end_define

begin_comment
comment|/* The C type `size_t'.  */
end_comment

begin_define
define|#
directive|define
name|size_type_node
value|global_trees[TI_SIZE_TYPE]
end_define

begin_define
define|#
directive|define
name|pid_type_node
value|global_trees[TI_PID_TYPE]
end_define

begin_define
define|#
directive|define
name|ptrdiff_type_node
value|global_trees[TI_PTRDIFF_TYPE]
end_define

begin_define
define|#
directive|define
name|va_list_type_node
value|global_trees[TI_VA_LIST_TYPE]
end_define

begin_define
define|#
directive|define
name|va_list_gpr_counter_field
value|global_trees[TI_VA_LIST_GPR_COUNTER_FIELD]
end_define

begin_define
define|#
directive|define
name|va_list_fpr_counter_field
value|global_trees[TI_VA_LIST_FPR_COUNTER_FIELD]
end_define

begin_comment
comment|/* The C type `FILE *'.  */
end_comment

begin_define
define|#
directive|define
name|fileptr_type_node
value|global_trees[TI_FILEPTR_TYPE]
end_define

begin_define
define|#
directive|define
name|boolean_type_node
value|global_trees[TI_BOOLEAN_TYPE]
end_define

begin_define
define|#
directive|define
name|boolean_false_node
value|global_trees[TI_BOOLEAN_FALSE]
end_define

begin_define
define|#
directive|define
name|boolean_true_node
value|global_trees[TI_BOOLEAN_TRUE]
end_define

begin_comment
comment|/* The decimal floating point types. */
end_comment

begin_define
define|#
directive|define
name|dfloat32_type_node
value|global_trees[TI_DFLOAT32_TYPE]
end_define

begin_define
define|#
directive|define
name|dfloat64_type_node
value|global_trees[TI_DFLOAT64_TYPE]
end_define

begin_define
define|#
directive|define
name|dfloat128_type_node
value|global_trees[TI_DFLOAT128_TYPE]
end_define

begin_define
define|#
directive|define
name|dfloat32_ptr_type_node
value|global_trees[TI_DFLOAT32_PTR_TYPE]
end_define

begin_define
define|#
directive|define
name|dfloat64_ptr_type_node
value|global_trees[TI_DFLOAT64_PTR_TYPE]
end_define

begin_define
define|#
directive|define
name|dfloat128_ptr_type_node
value|global_trees[TI_DFLOAT128_PTR_TYPE]
end_define

begin_comment
comment|/* The node that should be placed at the end of a parameter list to    indicate that the function does not take a variable number of    arguments.  The TREE_VALUE will be void_type_node and there will be    no TREE_CHAIN.  Language-independent code should not assume    anything else about this node.  */
end_comment

begin_define
define|#
directive|define
name|void_list_node
value|global_trees[TI_VOID_LIST_NODE]
end_define

begin_define
define|#
directive|define
name|main_identifier_node
value|global_trees[TI_MAIN_IDENTIFIER]
end_define

begin_define
define|#
directive|define
name|MAIN_NAME_P
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_NODE_CHECK (NODE) == main_identifier_node)
end_define

begin_comment
comment|/* An enumeration of the standard C integer types.  These must be    ordered so that shorter types appear before longer ones, and so    that signed types appear before unsigned ones, for the correct    functioning of interpret_integer() in c-lex.c.  */
end_comment

begin_enum
enum|enum
name|integer_type_kind
block|{
name|itk_char
block|,
name|itk_signed_char
block|,
name|itk_unsigned_char
block|,
name|itk_short
block|,
name|itk_unsigned_short
block|,
name|itk_int
block|,
name|itk_unsigned_int
block|,
name|itk_long
block|,
name|itk_unsigned_long
block|,
name|itk_long_long
block|,
name|itk_unsigned_long_long
block|,
name|itk_none
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|integer_type_kind
name|integer_type_kind
typedef|;
end_typedef

begin_comment
comment|/* The standard C integer types.  Use integer_type_kind to index into    this array.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|integer_types
index|[
name|itk_none
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|char_type_node
value|integer_types[itk_char]
end_define

begin_define
define|#
directive|define
name|signed_char_type_node
value|integer_types[itk_signed_char]
end_define

begin_define
define|#
directive|define
name|unsigned_char_type_node
value|integer_types[itk_unsigned_char]
end_define

begin_define
define|#
directive|define
name|short_integer_type_node
value|integer_types[itk_short]
end_define

begin_define
define|#
directive|define
name|short_unsigned_type_node
value|integer_types[itk_unsigned_short]
end_define

begin_define
define|#
directive|define
name|integer_type_node
value|integer_types[itk_int]
end_define

begin_define
define|#
directive|define
name|unsigned_type_node
value|integer_types[itk_unsigned_int]
end_define

begin_define
define|#
directive|define
name|long_integer_type_node
value|integer_types[itk_long]
end_define

begin_define
define|#
directive|define
name|long_unsigned_type_node
value|integer_types[itk_unsigned_long]
end_define

begin_define
define|#
directive|define
name|long_long_integer_type_node
value|integer_types[itk_long_long]
end_define

begin_define
define|#
directive|define
name|long_long_unsigned_type_node
value|integer_types[itk_unsigned_long_long]
end_define

begin_escape
end_escape

begin_comment
comment|/* Set to the default thread-local storage (tls) model to use.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tls_model
name|flag_tls_default
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* A pointer-to-function member type looks like:       struct {        __P __pfn;        ptrdiff_t __delta;      };     If __pfn is NULL, it is a NULL pointer-to-member-function.     (Because the vtable is always the first thing in the object, we    don't need its offset.)  If the function is virtual, then PFN is    one plus twice the index into the vtable; otherwise, it is just a    pointer to the function.     Unfortunately, using the lowest bit of PFN doesn't work in    architectures that don't impose alignment requirements on function    addresses, or that use the lowest bit to tell one ISA from another,    for example.  For such architectures, we use the lowest bit of    DELTA instead of the lowest bit of the PFN, and DELTA will be    multiplied by 2.  */
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

begin_escape
end_escape

begin_define
define|#
directive|define
name|NULL_TREE
value|(tree) NULL
end_define

begin_function_decl
specifier|extern
name|tree
name|decl_assembler_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute the number of bytes occupied by 'node'.  This routine only    looks at TREE_CODE and, if the code is TREE_VEC, TREE_VEC_LENGTH.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|tree_size
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute the number of bytes occupied by a tree with code CODE.  This    function cannot be used for TREE_VEC or PHI_NODE codes, which are of    variable length.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|tree_code_size
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lowest level primitive for allocating a node.    The TREE_CODE is the only argument.  Contents are initialized    to zero except for a few of the common fields.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|make_node_stat
parameter_list|(
name|enum
name|tree_code
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|make_node
parameter_list|(
name|t
parameter_list|)
value|make_node_stat (t MEM_STAT_INFO)
end_define

begin_comment
comment|/* Make a copy of a node, with all the same contents.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|copy_node_stat
parameter_list|(
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|copy_node
parameter_list|(
name|t
parameter_list|)
value|copy_node_stat (t MEM_STAT_INFO)
end_define

begin_comment
comment|/* Make a copy of a chain of TREE_LIST nodes.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|copy_list
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make a BINFO.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|make_tree_binfo_stat
parameter_list|(
name|unsigned
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|make_tree_binfo
parameter_list|(
name|t
parameter_list|)
value|make_tree_binfo_stat (t MEM_STAT_INFO)
end_define

begin_comment
comment|/* Make a TREE_VEC.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|make_tree_vec_stat
parameter_list|(
name|int
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|make_tree_vec
parameter_list|(
name|t
parameter_list|)
value|make_tree_vec_stat (t MEM_STAT_INFO)
end_define

begin_comment
comment|/* Tree nodes for SSA analysis.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_phinodes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fini_phinodes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|release_phi_node
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|GATHER_STATISTICS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|phinodes_print_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|init_ssanames
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fini_ssanames
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_ssa_name
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
name|duplicate_ssa_name
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
name|duplicate_ssa_name_ptr_info
parameter_list|(
name|tree
parameter_list|,
name|struct
name|ptr_info_def
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|release_ssa_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|release_defs
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|replace_ssa_name_symbol
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
name|GATHER_STATISTICS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ssanames_print_statistics
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
comment|/* Return the (unique) IDENTIFIER_NODE node for a given name.    The name is supplied as a char *.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_identifier
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|3000
end_if

begin_define
define|#
directive|define
name|get_identifier
parameter_list|(
name|str
parameter_list|)
define|\
value|(__builtin_constant_p (str)				\     ? get_identifier_with_length ((str), strlen (str))  \     : get_identifier (str))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Identical to get_identifier, except that the length is assumed    known.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_identifier_with_length
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If an identifier with the name TEXT (a null-terminated string) has    previously been referred to, return that node; otherwise return    NULL_TREE.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|maybe_get_identifier
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Construct various types of nodes.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_nt
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
name|build0_stat
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build0
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|build0_stat (c,t MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build1_stat
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build1
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|)
value|build1_stat (c,t1,t2 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build2_stat
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build2
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|)
value|build2_stat (c,t1,t2,t3 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build3_stat
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build3
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|)
value|build3_stat (c,t1,t2,t3,t4 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build4_stat
parameter_list|(
name|enum
name|tree_code
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
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build4
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|)
value|build4_stat (c,t1,t2,t3,t4,t5 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build5_stat
parameter_list|(
name|enum
name|tree_code
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
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build5
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|)
value|build5_stat (c,t1,t2,t3,t4,t5,t6 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build7_stat
parameter_list|(
name|enum
name|tree_code
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
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build7
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|)
define|\
value|build7_stat (c,t1,t2,t3,t4,t5,t6,t7,t8 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build_int_cst
parameter_list|(
name|tree
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_int_cst_type
parameter_list|(
name|tree
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_int_cstu
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_int_cst_wide
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vector
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|build_vector_from_ctor
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

begin_decl_stmt
specifier|extern
name|tree
name|build_constructor
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
name|build_constructor_single
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
name|build_constructor_from_list
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
name|build_real_from_int_cst
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
name|build_complex
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
name|build_one_cst
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_string
parameter_list|(
name|int
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
name|build_tree_list_stat
parameter_list|(
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build_tree_list
parameter_list|(
name|t
parameter_list|,
name|q
parameter_list|)
value|build_tree_list_stat(t,q MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build_decl_stat
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_fn_decl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|build_decl
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|q
parameter_list|)
value|build_decl_stat (c,t,q MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|build_block
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

begin_ifndef
ifndef|#
directive|ifndef
name|USE_MAPPED_LOCATION
end_ifndef

begin_function_decl
specifier|extern
name|void
name|annotate_with_file_line
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
name|annotate_with_locus
parameter_list|(
name|tree
parameter_list|,
name|location_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|tree
name|build_empty_stmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_omp_clause
parameter_list|(
name|enum
name|omp_clause_code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Construct various nodes representing data types.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|make_signed_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_unsigned_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|signed_type_for
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|unsigned_type_for
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initialize_sizetypes
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_sizetype
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fixup_unsigned_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_pointer_type_for_mode
parameter_list|(
name|tree
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_pointer_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_reference_type_for_mode
parameter_list|(
name|tree
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_reference_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vector_type_for_mode
parameter_list|(
name|tree
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_vector_type
parameter_list|(
name|tree
name|innertype
parameter_list|,
name|int
name|nunits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_type_no_quals
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_index_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_index_2_type
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
name|build_array_type
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
name|build_function_type
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
name|build_function_type_list
parameter_list|(
name|tree
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_method_type_directly
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
name|build_method_type
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
name|build_offset_type
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
name|build_complex_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_resx
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|array_type_nelts
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|in_array_bounds_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|range_in_array_bounds_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|value_member
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
name|purpose_member
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
name|attribute_list_equal
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
name|attribute_list_contained
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
name|tree_int_cst_equal
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
name|tree_int_cst_lt
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
name|tree_int_cst_compare
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
name|host_integerp
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|tree_low_cst
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
name|tree_int_cst_msb
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tree_int_cst_sgn
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tree_int_cst_sign_bit
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tree_expr_nonnegative_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tree_expr_nonnegative_warnv_p
parameter_list|(
name|tree
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|may_negate_without_overflow_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_inner_array_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From expmed.c.  Since rtl.h is included after tree.h, we can't    put the prototype here.  Rtl.h does declare the prototype if    tree.h had been included.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|make_tree
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Return a type like TTYPE except that its TYPE_ATTRIBUTES    is ATTRIBUTE.     Such modified types already made are recorded so that duplicates    are not made.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_type_attribute_variant
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
name|build_decl_attribute_variant
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Structure describing an attribute and a function to handle it.  */
end_comment

begin_struct
struct|struct
name|attribute_spec
block|{
comment|/* The name of the attribute (without any leading or trailing __),      or NULL to mark the end of a table of attributes.  */
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
comment|/* The minimum length of the list of arguments of the attribute.  */
specifier|const
name|int
name|min_length
decl_stmt|;
comment|/* The maximum length of the list of arguments of the attribute      (-1 for no maximum).  */
specifier|const
name|int
name|max_length
decl_stmt|;
comment|/* Whether this attribute requires a DECL.  If it does, it will be passed      from types of DECLs, function return types and array element types to      the DECLs, function types and array types respectively; but when      applied to a type in any other circumstances, it will be ignored with      a warning.  (If greater control is desired for a given attribute,      this should be false, and the flags argument to the handler may be      used to gain greater control in that case.)  */
specifier|const
name|bool
name|decl_required
decl_stmt|;
comment|/* Whether this attribute requires a type.  If it does, it will be passed      from a DECL to the type of that DECL.  */
specifier|const
name|bool
name|type_required
decl_stmt|;
comment|/* Whether this attribute requires a function (or method) type.  If it does,      it will be passed from a function pointer type to the target type,      and from a function return type (which is not itself a function      pointer type) to the function type.  */
specifier|const
name|bool
name|function_type_required
decl_stmt|;
comment|/* Function to handle this attribute.  NODE points to the node to which      the attribute is to be applied.  If a DECL, it should be modified in      place; if a TYPE, a copy should be created.  NAME is the name of the      attribute (possibly with leading or trailing __).  ARGS is the TREE_LIST      of the arguments (which may be NULL).  FLAGS gives further information      about the context of the attribute.  Afterwards, the attributes will      be added to the DECL_ATTRIBUTES or TYPE_ATTRIBUTES, as appropriate,      unless *NO_ADD_ATTRS is set to true (which should be done on error,      as well as in any other cases when the attributes should not be added      to the DECL or TYPE).  Depending on FLAGS, any attributes to be      applied to another type or DECL later may be returned;      otherwise the return value should be NULL_TREE.  This pointer may be      NULL if no special handling is required beyond the checks implied      by the rest of this structure.  */
name|tree
argument_list|(
argument|*const handler
argument_list|)
operator|(
name|tree
operator|*
name|node
operator|,
name|tree
name|name
operator|,
name|tree
name|args
operator|,
name|int
name|flags
operator|,
name|bool
operator|*
name|no_add_attrs
operator|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags that may be passed in the third argument of decl_attributes, and    to handler functions for attributes.  */
end_comment

begin_enum
enum|enum
name|attribute_flags
block|{
comment|/* The type passed in is the type of a DECL, and any attributes that      should be passed in again to be applied to the DECL rather than the      type should be returned.  */
name|ATTR_FLAG_DECL_NEXT
init|=
literal|1
block|,
comment|/* The type passed in is a function return type, and any attributes that      should be passed in again to be applied to the function type rather      than the return type should be returned.  */
name|ATTR_FLAG_FUNCTION_NEXT
init|=
literal|2
block|,
comment|/* The type passed in is an array element type, and any attributes that      should be passed in again to be applied to the array type rather      than the element type should be returned.  */
name|ATTR_FLAG_ARRAY_NEXT
init|=
literal|4
block|,
comment|/* The type passed in is a structure, union or enumeration type being      created, and should be modified in place.  */
name|ATTR_FLAG_TYPE_IN_PLACE
init|=
literal|8
block|,
comment|/* The attributes are being applied by default to a library function whose      name indicates known behavior, and should be silently ignored if they      are not in fact compatible with the function type.  */
name|ATTR_FLAG_BUILT_IN
init|=
literal|16
block|}
enum|;
end_enum

begin_comment
comment|/* Default versions of target-overridable functions.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|merge_decl_attributes
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
name|merge_type_attributes
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a tree node and a string, return nonzero if the tree node is    a valid attribute name for the string.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|is_attribute_p
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given an attribute name and a list of attributes, return the list element    of the attribute or NULL_TREE if not found.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|lookup_attribute
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove any instances of attribute ATTR_NAME in LIST and return the    modified list.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|remove_attribute
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given two attributes lists, return a list of their union.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|merge_attributes
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
end_if

begin_comment
comment|/* Given two Windows decl attributes lists, possibly including    dllimport, return a list of their union .  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|merge_dllimport_decl_attributes
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Handle a "dllimport" or "dllexport" attribute.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|handle_dll_attribute
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Check whether CAND is suitable to be returned from get_qualified_type    (BASE, TYPE_QUALS).  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|check_qualified_type
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a version of the TYPE, qualified as indicated by the    TYPE_QUALS, if one exists.  If no qualified version exists yet,    return NULL_TREE.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_qualified_type
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like get_qualified_type, but creates the type if it does not    exist.  This function never returns NULL_TREE.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_qualified_type
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like build_qualified_type, but only deals with the `const' and    `volatile' qualifiers.  This interface is retained for backwards    compatibility with the various front-ends; new code should use    build_qualified_type instead.  */
end_comment

begin_define
define|#
directive|define
name|build_type_variant
parameter_list|(
name|TYPE
parameter_list|,
name|CONST_P
parameter_list|,
name|VOLATILE_P
parameter_list|)
define|\
value|build_qualified_type ((TYPE),						\ 			((CONST_P) ? TYPE_QUAL_CONST : 0)		\ 			| ((VOLATILE_P) ? TYPE_QUAL_VOLATILE : 0))
end_define

begin_comment
comment|/* Make a copy of a type node.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_distinct_type_copy
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_variant_type_copy
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finish up a builtin RECORD_TYPE. Give it a name and provide its    fields. Optionally specify an alignment, and then lay it out.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|finish_builtin_struct
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a ..._TYPE node, calculate the TYPE_SIZE, TYPE_SIZE_UNIT,    TYPE_ALIGN and TYPE_MODE fields.  If called more than once on one    node, does nothing except for the first time.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|layout_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These functions allow a front-end to perform a manual layout of a    RECORD_TYPE.  (For instance, if the placement of subsequent fields    depends on the placement of fields so far.)  Begin by calling    start_record_layout.  Then, call place_field for each of the    fields.  Then, call finish_record_layout.  See layout_type for the    default way in which these functions are used.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|record_layout_info_s
block|{
comment|/* The RECORD_TYPE that we are laying out.  */
name|tree
name|t
decl_stmt|;
comment|/* The offset into the record so far, in bytes, not including bits in      BITPOS.  */
name|tree
name|offset
decl_stmt|;
comment|/* The last known alignment of SIZE.  */
name|unsigned
name|int
name|offset_align
decl_stmt|;
comment|/* The bit position within the last OFFSET_ALIGN bits, in bits.  */
name|tree
name|bitpos
decl_stmt|;
comment|/* The alignment of the record so far, in bits.  */
name|unsigned
name|int
name|record_align
decl_stmt|;
comment|/* The alignment of the record so far, ignoring #pragma pack and      __attribute__ ((packed)), in bits.  */
name|unsigned
name|int
name|unpacked_align
decl_stmt|;
comment|/* The previous field layed out.  */
name|tree
name|prev_field
decl_stmt|;
comment|/* The static variables (i.e., class variables, as opposed to      instance variables) encountered in T.  */
name|tree
name|pending_statics
decl_stmt|;
comment|/* Bits remaining in the current alignment group */
name|int
name|remaining_in_alignment
decl_stmt|;
comment|/* True if we've seen a packed field that didn't have normal      alignment anyway.  */
name|int
name|packed_maybe_necessary
decl_stmt|;
block|}
typedef|*
name|record_layout_info
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|set_lang_adjust_rli
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|record_layout_info
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|record_layout_info
name|start_record_layout
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|bit_from_pos
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
name|byte_from_pos
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
name|pos_from_bit
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|normalize_offset
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|rli_size_unit_so_far
parameter_list|(
name|record_layout_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|rli_size_so_far
parameter_list|(
name|record_layout_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|normalize_rli
parameter_list|(
name|record_layout_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|place_field
parameter_list|(
name|record_layout_info
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compute_record_mode
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_record_layout
parameter_list|(
name|record_layout_info
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a hashcode and a ..._TYPE node (for which the hashcode was made),    return a canonicalized ..._TYPE node, so that duplicates are not made.    How the hash code is computed is up to the caller, as long as any two    callers that could hash identical-looking type nodes agree.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|type_hash_canon
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a VAR_DECL, PARM_DECL, RESULT_DECL or FIELD_DECL node,    calculates the DECL_SIZE, DECL_SIZE_UNIT, DECL_ALIGN and DECL_MODE    fields.  Call this only once for any given decl node.     Second argument is the boundary that this field can be assumed to    be starting at (in bits).  Zero means it can be assumed aligned    on any boundary that may be needed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|layout_decl
parameter_list|(
name|tree
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a VAR_DECL, PARM_DECL or RESULT_DECL, clears the results of    a previous call to layout_decl and calls it again.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|relayout_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the mode for data of a given size SIZE and mode class CLASS.    If LIMIT is nonzero, then don't use modes bigger than MAX_FIXED_MODE_SIZE.    The value is BLKmode if no other mode is found.  This is like    mode_for_size, but is passed a tree.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|machine_mode
name|mode_for_size_tree
parameter_list|(
name|tree
parameter_list|,
name|enum
name|mode_class
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return an expr equal to X but certainly not valid as an lvalue.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|non_lvalue
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert
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
name|expr_align
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|expr_first
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|expr_last
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|expr_only
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|size_in_bytes
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|int_size_in_bytes
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|max_int_size_in_bytes
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|bit_position
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|int_bit_position
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|byte_position
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|int_byte_position
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define data structures, macros, and functions for handling sizes    and the various types used to represent sizes.  */
end_comment

begin_enum
enum|enum
name|size_type_kind
block|{
name|SIZETYPE
block|,
comment|/* Normal representation of sizes in bytes.  */
name|SSIZETYPE
block|,
comment|/* Signed representation of sizes in bytes.  */
name|BITSIZETYPE
block|,
comment|/* Normal representation of sizes in bits.  */
name|SBITSIZETYPE
block|,
comment|/* Signed representation of sizes in bits.  */
name|TYPE_KIND_LAST
block|}
enum|;
end_enum

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|sizetype_tab
index|[
operator|(
name|int
operator|)
name|TYPE_KIND_LAST
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sizetype
value|sizetype_tab[(int) SIZETYPE]
end_define

begin_define
define|#
directive|define
name|bitsizetype
value|sizetype_tab[(int) BITSIZETYPE]
end_define

begin_define
define|#
directive|define
name|ssizetype
value|sizetype_tab[(int) SSIZETYPE]
end_define

begin_define
define|#
directive|define
name|sbitsizetype
value|sizetype_tab[(int) SBITSIZETYPE]
end_define

begin_function_decl
specifier|extern
name|tree
name|size_int_kind
parameter_list|(
name|HOST_WIDE_INT
parameter_list|,
name|enum
name|size_type_kind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|size_binop
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
name|size_diffop
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
name|size_int
parameter_list|(
name|L
parameter_list|)
value|size_int_kind (L, SIZETYPE)
end_define

begin_define
define|#
directive|define
name|ssize_int
parameter_list|(
name|L
parameter_list|)
value|size_int_kind (L, SSIZETYPE)
end_define

begin_define
define|#
directive|define
name|bitsize_int
parameter_list|(
name|L
parameter_list|)
value|size_int_kind (L, BITSIZETYPE)
end_define

begin_define
define|#
directive|define
name|sbitsize_int
parameter_list|(
name|L
parameter_list|)
value|size_int_kind (L, SBITSIZETYPE)
end_define

begin_function_decl
specifier|extern
name|tree
name|round_up
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
name|round_down
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
name|get_pending_sizes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_pending_size
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|put_pending_sizes
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Type for sizes of data-type.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT_LOG
define|\
value|((BITS_PER_UNIT> 1) + (BITS_PER_UNIT> 2) + (BITS_PER_UNIT> 4) \    + (BITS_PER_UNIT> 8) + (BITS_PER_UNIT> 16) + (BITS_PER_UNIT> 32) \    + (BITS_PER_UNIT> 64) + (BITS_PER_UNIT> 128) + (BITS_PER_UNIT> 256))
end_define

begin_comment
comment|/* If nonzero, an upper limit on alignment of structure fields, in bits,  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|maximum_field_alignment
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and its original value in bytes, specified via -fpack-struct=<value>.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|initial_max_fld_align
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Concatenate two lists (chains of TREE_LIST nodes) X and Y    by making the last node in X point to Y.    Returns X, except if X is 0 returns Y.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|chainon
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make a new TREE_LIST node from specified PURPOSE, VALUE and CHAIN.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|tree_cons_stat
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tree_cons
parameter_list|(
name|t
parameter_list|,
name|q
parameter_list|,
name|w
parameter_list|)
value|tree_cons_stat (t,q,w MEM_STAT_INFO)
end_define

begin_comment
comment|/* Return the last tree node in a chain.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|tree_last
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reverse the order of elements in a chain, and return the new head.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|nreverse
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the length of a chain of nodes    (number of chain pointers to follow before reaching a null pointer).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|list_length
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the number of FIELD_DECLs in a type.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|fields_length
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given an initializer INIT, return TRUE if INIT is zero or some    aggregate of zeros.  Otherwise return FALSE.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|initializer_zerop
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Examine CTOR to discover:    * how many scalar fields are set to nonzero values,      and place it in *P_NZ_ELTS;    * how many scalar fields in total are in CTOR,      and place it in *P_ELT_COUNT.    * if a type is a union, and the initializer from the constructor      is not the largest element in the union, then set *p_must_clear.     Return whether or not CTOR is a valid static constant initializer, the same    as "initializer_constant_valid_p (CTOR, TREE_TYPE (CTOR)) != 0".  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|categorize_ctor_elements
parameter_list|(
name|tree
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|count_type_elements
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* integer_zerop (tree x) is nonzero if X is an integer constant of value 0.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|integer_zerop
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* integer_onep (tree x) is nonzero if X is an integer constant of value 1.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|integer_onep
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* integer_all_onesp (tree x) is nonzero if X is an integer constant    all of whose significant bits are 1.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|integer_all_onesp
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* integer_pow2p (tree x) is nonzero is X is an integer constant with    exactly one bit 1.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|integer_pow2p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* integer_nonzerop (tree x) is nonzero if X is an integer constant    with a nonzero value.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|integer_nonzerop
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|zero_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cst_and_fits_in_hwi
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|num_ending_zeros
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* staticp (tree x) is nonzero if X is a reference to data allocated    at a fixed address in memory.  Returns the outermost data.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|staticp
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* save_expr (EXP) returns an expression equivalent to EXP    but it can be used multiple times within context CTX    and only evaluate EXP once.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|save_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Look inside EXPR and into any simple arithmetic operations.  Return    the innermost non-arithmetic node.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|skip_simple_arithmetic
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return which tree structure is used by T.  */
end_comment

begin_function_decl
name|enum
name|tree_node_structure_enum
name|tree_node_structure
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return 1 if EXP contains a PLACEHOLDER_EXPR; i.e., if it represents a size    or offset that depends on a field within a record.     Note that we only allow such expressions within simple arithmetic    or a COND_EXPR.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|contains_placeholder_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This macro calls the above function but short-circuits the common    case of a constant to save time.  Also check for null.  */
end_comment

begin_define
define|#
directive|define
name|CONTAINS_PLACEHOLDER_P
parameter_list|(
name|EXP
parameter_list|)
define|\
value|((EXP) != 0&& ! TREE_CONSTANT (EXP)&& contains_placeholder_p (EXP))
end_define

begin_comment
comment|/* Return 1 if any part of the computation of TYPE involves a PLACEHOLDER_EXPR.    This includes size, bounds, qualifiers (for QUAL_UNION_TYPE) and field    positions.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|type_contains_placeholder_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a tree EXP, a FIELD_DECL F, and a replacement value R,    return a tree with all occurrences of references to F in a    PLACEHOLDER_EXPR replaced by R.   Note that we assume here that EXP    contains only arithmetic expressions.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|substitute_in_expr
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
comment|/* This macro calls the above function but short-circuits the common    case of a constant to save time and also checks for NULL.  */
end_comment

begin_define
define|#
directive|define
name|SUBSTITUTE_IN_EXPR
parameter_list|(
name|EXP
parameter_list|,
name|F
parameter_list|,
name|R
parameter_list|)
define|\
value|((EXP) == 0 || TREE_CONSTANT (EXP) ? (EXP) : substitute_in_expr (EXP, F, R))
end_define

begin_comment
comment|/* Similar, but look for a PLACEHOLDER_EXPR in EXP and find a replacement    for it within OBJ, a tree that is an object or a chain of references.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|substitute_placeholder_in_expr
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This macro calls the above function but short-circuits the common    case of a constant to save time and also checks for NULL.  */
end_comment

begin_define
define|#
directive|define
name|SUBSTITUTE_PLACEHOLDER_IN_EXPR
parameter_list|(
name|EXP
parameter_list|,
name|OBJ
parameter_list|)
define|\
value|((EXP) == 0 || TREE_CONSTANT (EXP) ? (EXP)	\    : substitute_placeholder_in_expr (EXP, OBJ))
end_define

begin_comment
comment|/* variable_size (EXP) is like save_expr (EXP) except that it    is for the special case of something that is part of a    variable size for a data type.  It makes special arrangements    to compute the value at the right time when the data type    belongs to a function parameter.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|variable_size
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stabilize_reference (EXP) returns a reference equivalent to EXP    but it can be used multiple times    and only evaluate the subexpressions once.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|stabilize_reference
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Subroutine of stabilize_reference; this is called for subtrees of    references.  Any expression with side-effects must be put in a SAVE_EXPR    to ensure that it is only evaluated once.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|stabilize_reference_1
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return EXP, stripped of any conversions to wider types    in such a way that the result of converting to type FOR_TYPE    is the same as if EXP were converted to FOR_TYPE.    If FOR_TYPE is 0, it signifies EXP's type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_unwidened
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return OP or a simpler expression for a narrower value    which can be sign-extended or zero-extended to give back OP.    Store in *UNSIGNEDP_PTR either 1 if the value should be zero-extended    or 0 if the value should be sign-extended.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_narrower
parameter_list|(
name|tree
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given an expression EXP that may be a COMPONENT_REF or an ARRAY_REF,    look for nested component-refs or array-refs at constant positions    and find the ultimate containing object, which is returned.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_inner_reference
parameter_list|(
name|tree
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|enum
name|machine_mode
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given an expression EXP that may be a COMPONENT_REF or an ARRAY_REF,    look for whether EXP or any nested component-refs within EXP is marked    as PACKED.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|contains_packed_reference
parameter_list|(
name|tree
name|exp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return 1 if T is an expression that get_inner_reference handles.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|handled_component_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a tree of sizetype representing the size, in bytes, of the element    of EXP, an ARRAY_REF.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|array_ref_element_size
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a tree representing the lower bound of the array mentioned in    EXP, an ARRAY_REF.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|array_ref_low_bound
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a tree representing the upper bound of the array mentioned in    EXP, an ARRAY_REF.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|array_ref_up_bound
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a tree representing the offset, in bytes, of the field referenced    by EXP.  This does not include any offset in DECL_FIELD_BIT_OFFSET.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|component_ref_field_offset
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a DECL or TYPE, return the scope in which it was declared, or    NUL_TREE if there is no containing scope.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_containing_scope
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the FUNCTION_DECL which provides this _DECL with its context,    or zero if none.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|decl_function_context
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the RECORD_TYPE, UNION_TYPE, or QUAL_UNION_TYPE which provides    this _DECL with its context, or zero if none.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|decl_type_context
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return 1 if EXPR is the real constant zero.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|real_zerop
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Declare commonly used variables for tree structure.  */
end_comment

begin_comment
comment|/* Nonzero means lvalues are limited to those valid in pedantic ANSI C.    Zero means allow extended lvalues.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pedantic_lvalues
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to the FUNCTION_DECL of the function whose body we are reading.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|tree
name|current_function_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means a FUNC_BEGIN label was emitted.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
specifier|const
name|char
modifier|*
name|current_function_func_begin_label
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* In tree.c */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|crc32_string
parameter_list|(
name|unsigned
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
name|clean_symbol_name
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_file_function_name_long
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
name|get_callee_fndecl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|change_decl_assembler_name
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
name|type_num_arguments
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|associative_tree_code
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|commutative_tree_code
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|upper_bound_in_type
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
name|lower_bound_in_type
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
name|operand_equal_for_phi_arg_p
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
name|empty_body_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* In stmt.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|expand_expr_stmt
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|warn_if_unused_value
parameter_list|(
name|tree
parameter_list|,
name|location_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_label
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_goto
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_stack_save
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_stack_restore
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_return
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_body_block
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-eh.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|using_eh_for_cleanups
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In fold-const.c */
end_comment

begin_comment
comment|/* Non-zero if we are folding constants inside an initializer; zero    otherwise.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|folding_initializer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fold constants as much as possible in an expression.    Returns the simplified expression.    Acts only on the top level of the expression;    if the argument itself cannot be simplified, its    subexpressions are not changed.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|fold
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_unary
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
name|fold_binary
parameter_list|(
name|enum
name|tree_code
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
name|fold_ternary
parameter_list|(
name|enum
name|tree_code
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
name|fold_build1_stat
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fold_build1
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|)
value|fold_build1_stat (c, t1, t2 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|fold_build2_stat
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fold_build2
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|)
value|fold_build2_stat (c, t1, t2, t3 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|fold_build3_stat
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fold_build3
parameter_list|(
name|c
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|)
value|fold_build3_stat (c, t1, t2, t3, t4 MEM_STAT_INFO)
end_define

begin_function_decl
specifier|extern
name|tree
name|fold_build1_initializer
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
name|fold_build2_initializer
parameter_list|(
name|enum
name|tree_code
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
name|fold_build3_initializer
parameter_list|(
name|enum
name|tree_code
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
name|fold_convert
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
name|fold_single_bit_test
parameter_list|(
name|enum
name|tree_code
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
name|fold_ignored_result
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_abs_const
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
name|fold_indirect_ref_1
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
name|fold_defer_overflow_warnings
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fold_undefer_overflow_warnings
parameter_list|(
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
name|fold_undefer_and_ignore_overflow_warnings
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|fold_deferring_overflow_warnings_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|force_fit_type
parameter_list|(
name|tree
parameter_list|,
name|int
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
name|add_double_with_sign
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|add_double
parameter_list|(
name|l1
parameter_list|,
name|h1
parameter_list|,
name|l2
parameter_list|,
name|h2
parameter_list|,
name|lv
parameter_list|,
name|hv
parameter_list|)
define|\
value|add_double_with_sign (l1, h1, l2, h2, lv, hv, false)
end_define

begin_function_decl
specifier|extern
name|int
name|neg_double
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mul_double_with_sign
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mul_double
parameter_list|(
name|l1
parameter_list|,
name|h1
parameter_list|,
name|l2
parameter_list|,
name|h2
parameter_list|,
name|lv
parameter_list|,
name|hv
parameter_list|)
define|\
value|mul_double_with_sign (l1, h1, l2, h2, lv, hv, false)
end_define

begin_function_decl
specifier|extern
name|void
name|lshift_double
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rshift_double
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lrotate_double
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rrotate_double
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|div_and_round_double
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
modifier|*
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|operand_equal_flag
block|{
name|OEP_ONLY_CONST
init|=
literal|1
block|,
name|OEP_PURE_SAME
init|=
literal|2
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|int
name|operand_equal_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|omit_one_operand
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
name|omit_two_operands
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
name|invert_truthvalue
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_truth_not_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_unary_to_constant
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
name|fold_binary_to_constant
parameter_list|(
name|enum
name|tree_code
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
name|fold_read_from_constant_string
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|int_const_binop
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
name|build_fold_addr_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_build_cleanup_point_expr
parameter_list|(
name|tree
name|type
parameter_list|,
name|tree
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_strip_sign_ops
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_fold_addr_expr_with_type
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
name|build_fold_indirect_ref
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_indirect_ref
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|constant_boolean_node
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
name|build_low_bits_mask
parameter_list|(
name|tree
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_swap_operands_p
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
name|swap_tree_operands
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
name|tree_code
name|swap_tree_comparison
parameter_list|(
name|enum
name|tree_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|ptr_difference_const
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|HOST_WIDE_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|tree_code
name|invert_tree_comparison
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_expr_nonzero_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_expr_nonzero_warnv_p
parameter_list|(
name|tree
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In builtins.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|fold_builtin
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
name|fold_builtin_fputs
parameter_list|(
name|tree
parameter_list|,
name|bool
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
name|fold_builtin_strcpy
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
name|fold_builtin_strncpy
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
name|fold_builtin_memory_chk
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|enum
name|built_in_function
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_builtin_stxcpy_chk
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|bool
parameter_list|,
name|enum
name|built_in_function
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|fold_builtin_strncpy_chk
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
name|fold_builtin_snprintf_chk
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|enum
name|built_in_function
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|fold_builtin_next_arg
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|built_in_function
name|builtin_mathfn_code
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_function_call_expr
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
name|mathfn_built_in
parameter_list|(
name|tree
parameter_list|,
name|enum
name|built_in_function
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|strip_float_extensions
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|c_strlen
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
name|std_gimplify_va_arg_expr
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_va_arg_indirect_ref
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|build_string_literal
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In convert.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|strip_float_extensions
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In alias.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|record_component_aliases
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|get_alias_set
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alias_sets_conflict_p
parameter_list|(
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alias_sets_might_conflict_p
parameter_list|(
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|objects_must_conflict_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|really_constant_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|int_fits_type_p
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
name|variably_modified_type_p
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
name|tree_log2
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tree_floor_log2
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|simple_cst_equal
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|hashval_t
name|iterative_hash_expr
parameter_list|(
name|tree
parameter_list|,
name|hashval_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|compare_tree_int
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|type_list_equal
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
name|chain_member
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
name|type_hash_lookup
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|type_hash_add
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|simple_cst_list_equal
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
name|dump_tree_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_function_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_function_start
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stack_protect_prologue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stack_protect_epilogue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|recompute_tree_invariant_for_addr_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|is_global_var
parameter_list|(
name|tree
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|needs_to_live_in_memory
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|reconstruct_complex_type
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
name|real_onep
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|real_twop
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|real_minus_onep
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_ttree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|build_common_tree_nodes
parameter_list|(
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|build_common_tree_nodes_2
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|build_common_builtin_nodes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_nonstandard_integer_type
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
name|build_range_type
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
name|HOST_WIDE_INT
name|int_cst_value
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|tree_fold_gcd
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
name|build_addr
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
name|fields_compatible_p
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
name|find_compatible_field
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In function.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|expand_main_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_dummy_function_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_dummy_function_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|init_function_for_compilation
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|allocate_struct_function
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_function_start
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|use_register_for_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setjmp_vars_warning
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setjmp_args_warning
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_temp_slots
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_temp_slots
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_temp_slots
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_temp_slots
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|preserve_temp_slots
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aggregate_value_p
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
name|push_function_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_function_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|push_function_context_to
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_function_context_from
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|gimplify_parameters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In print-rtl.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_function_decl
specifier|extern
name|void
name|print_rtl
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In print-tree.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|debug_tree
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dump_addr
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_node
parameter_list|(
name|FILE
modifier|*
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
name|void
name|print_node_brief
parameter_list|(
name|FILE
modifier|*
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
name|void
name|indent_to
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In tree-inline.c:  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|debug_find_tree
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is in tree-inline.c since the routine uses    data structures from the inliner.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|unsave_expr_now
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_duplicate_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In emit-rtl.c */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|emit_line_note
parameter_list|(
name|location_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In calls.c */
end_comment

begin_comment
comment|/* Nonzero if this is a call to a function whose return value depends    solely on its arguments, has no side effects, and does not read    global memory.  */
end_comment

begin_define
define|#
directive|define
name|ECF_CONST
value|1
end_define

begin_comment
comment|/* Nonzero if this call will never return.  */
end_comment

begin_define
define|#
directive|define
name|ECF_NORETURN
value|2
end_define

begin_comment
comment|/* Nonzero if this is a call to malloc or a related function.  */
end_comment

begin_define
define|#
directive|define
name|ECF_MALLOC
value|4
end_define

begin_comment
comment|/* Nonzero if it is plausible that this is a call to alloca.  */
end_comment

begin_define
define|#
directive|define
name|ECF_MAY_BE_ALLOCA
value|8
end_define

begin_comment
comment|/* Nonzero if this is a call to a function that won't throw an exception.  */
end_comment

begin_define
define|#
directive|define
name|ECF_NOTHROW
value|16
end_define

begin_comment
comment|/* Nonzero if this is a call to setjmp or a related function.  */
end_comment

begin_define
define|#
directive|define
name|ECF_RETURNS_TWICE
value|32
end_define

begin_comment
comment|/* Nonzero if this call replaces the current stack frame.  */
end_comment

begin_define
define|#
directive|define
name|ECF_SIBCALL
value|64
end_define

begin_comment
comment|/* Nonzero if this is a call to "pure" function (like const function,    but may read memory.  */
end_comment

begin_define
define|#
directive|define
name|ECF_PURE
value|128
end_define

begin_comment
comment|/* Nonzero if this is a call to a function that returns with the stack    pointer depressed.  */
end_comment

begin_define
define|#
directive|define
name|ECF_SP_DEPRESSED
value|256
end_define

begin_comment
comment|/* Create libcall block around the call.  */
end_comment

begin_define
define|#
directive|define
name|ECF_LIBCALL_BLOCK
value|512
end_define

begin_comment
comment|/* Function does not read or write memory (but may have side effects, so    it does not necessarily fit ECF_CONST).  */
end_comment

begin_define
define|#
directive|define
name|ECF_NOVOPS
value|1024
end_define

begin_function_decl
specifier|extern
name|int
name|flags_from_decl_or_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|call_expr_flags
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setjmp_call_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|alloca_call_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|must_pass_in_stack_var_size
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|must_pass_in_stack_var_size_or_pad
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In attribs.c.  */
end_comment

begin_comment
comment|/* Process the attributes listed in ATTRIBUTES and install them in *NODE,    which is either a DECL (including a TYPE_DECL) or a TYPE.  If a DECL,    it should be modified in place; if a TYPE, a copy should be created    unless ATTR_FLAG_TYPE_IN_PLACE is set in FLAGS.  FLAGS gives further    information, in the form of a bitwise OR of flags in enum attribute_flags    from tree.h.  Depending on these flags, some attributes may be    returned to be applied at a later stage (for example, to apply    a decl attribute to the declaration rather than to its type).  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|decl_attributes
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

begin_comment
comment|/* In integrate.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_decl_abstract_flags
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
name|set_decl_origin_self
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In stor-layout.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_min_and_max_values_for_integral_type
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
name|void
name|fixup_signed_type
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|internal_reference_types
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|update_alignment_for_field
parameter_list|(
name|record_layout_info
parameter_list|,
name|tree
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* varasm.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|make_decl_rtl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_decl_one_only
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|supports_one_only
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resolve_unique_section
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
name|mark_referenced
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_decl_referenced
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|notice_global_symbol
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_user_assembler_name
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
name|void
name|process_pending_assemble_externals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_aliases_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_aliases_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In stmt.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|expand_computed_goto
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|parse_output_constraint
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
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
name|bool
name|parse_input_constraint
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
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
name|void
name|expand_asm_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|resolve_asm_operand_names
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
name|expand_case
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_decl
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_anon_union_decl
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HARD_CONST
end_ifdef

begin_comment
comment|/* Silly ifdef to avoid having all includers depend on hard-reg-set.h.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|tree_overlaps_hard_reg_set
parameter_list|(
name|tree
parameter_list|,
name|HARD_REG_SET
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In gimplify.c.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|create_artificial_label
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gimplify_function_tree
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
name|get_name
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|unshare_expr
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sort_case_labels
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If KIND=='I', return a suitable global initializer (constructor) name.    If KIND=='D', return a suitable global clean-up (destructor) name.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_file_function_name
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Interface of the DWARF2 unwind info support.  */
end_comment

begin_comment
comment|/* Generate a new label for the CFI info to refer to.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|dwarf2out_cfi_label
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry point to update the canonical frame address (CFA).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf2out_def_cfa
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add the CFI for saving a register window.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf2out_window_save
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a CFI to update the running total of the size of arguments pushed    onto the stack.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf2out_args_size
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry point for saving a register to the stack.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf2out_reg_save
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry point for saving the return address in the stack.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf2out_return_save
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry point for saving the return address in a register.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf2out_return_reg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry point for saving the first register into the second.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf2out_reg_save_reg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-inline.c  */
end_comment

begin_comment
comment|/* The type of a set of already-visited pointers.  Functions for creating    and manipulating it are declared in pointer-set.h */
end_comment

begin_struct_decl
struct_decl|struct
name|pointer_set_t
struct_decl|;
end_struct_decl

begin_comment
comment|/* The type of a callback function for walking over tree structure.  */
end_comment

begin_typedef
typedef|typedef
name|tree
function_decl|(
modifier|*
name|walk_tree_fn
function_decl|)
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|tree
name|walk_tree
parameter_list|(
name|tree
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
name|tree
name|walk_tree_without_duplicates
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

begin_comment
comment|/* Assign the RTX to declaration.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_decl_rtl
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_decl_incoming_rtl
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Enum and arrays used for tree allocation stats.    Keep in sync with tree.c:tree_node_kind_names.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|d_kind
block|,
name|t_kind
block|,
name|b_kind
block|,
name|s_kind
block|,
name|r_kind
block|,
name|e_kind
block|,
name|c_kind
block|,
name|id_kind
block|,
name|perm_list_kind
block|,
name|temp_list_kind
block|,
name|vec_kind
block|,
name|binfo_kind
block|,
name|phi_kind
block|,
name|ssa_name_kind
block|,
name|constr_kind
block|,
name|x_kind
block|,
name|lang_decl
block|,
name|lang_type
block|,
name|omp_clause_kind
block|,
name|all_kinds
block|}
name|tree_node_kind
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|tree_node_counts
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tree_node_sizes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if we are in gimple form and the actions of the folders need to    be restricted.  False if we are not in gimple form and folding is not    restricted to creating gimple expressions.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|in_gimple_form
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In tree-gimple.c.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_base_address
parameter_list|(
name|tree
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-vectorizer.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|vect_set_verbosity_level
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tree_map
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|unsigned
name|int
name|hash
decl_stmt|;
name|tree
name|from
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
name|tree_map_hash
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
name|tree_map_marked_p
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
name|tree_map_eq
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
comment|/* In tree-ssa-address.c.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|tree_mem_ref_addr
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
name|copy_mem_ref_info
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-vrp.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|ssa_name_nonzero_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|ssa_name_nonnegative_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In tree-object-size.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_object_sizes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fini_object_sizes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|HOST_WIDE_INT
name|compute_builtin_object_size
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In expr.c.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|HOST_WIDE_INT
name|highest_pow2_factor
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_H  */
end_comment

end_unit

