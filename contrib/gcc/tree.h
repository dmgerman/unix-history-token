begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Front-end tree definitions for GNU compiler.    Copyright (C) 1989, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"machmode.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
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
comment|/* A convenient way to get a value for 				   NUM_TREE_CODE.  */
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

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
comment|/* Indexed by enum tree_code, contains a character which is    `<' for a comparison expression, `1', for a unary arithmetic    expression, `2' for a binary arithmetic expression, `e' for    other types of expressions, `r' for a reference, `c' for a    constant, `d' for a decl, `t' for a type, `s' for a statement,    and `x' for anything else (TREE_LIST, IDENTIFIER, etc).  */
end_comment

begin_define
define|#
directive|define
name|MAX_TREE_CODES
value|256
end_define

begin_decl_stmt
specifier|extern
name|char
name|tree_code_type
index|[
name|MAX_TREE_CODES
index|]
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
comment|/* Returns non-zero iff CLASS is the tree-code class of an    expression.  */
end_comment

begin_define
define|#
directive|define
name|IS_EXPR_CODE_CLASS
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|((CLASS) == '<' || (CLASS) == '1' || (CLASS) == '2' || (CLASS) == 'e')
end_define

begin_comment
comment|/* Number of argument-words in each kind of tree-node.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tree_code_length
index|[
name|MAX_TREE_CODES
index|]
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
name|tree_code_name
index|[
name|MAX_TREE_CODES
index|]
decl_stmt|;
end_decl_stmt

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
specifier|const
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
comment|/* An array of _DECL trees for the above.  */
end_comment

begin_decl_stmt
specifier|extern
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

begin_struct
struct|struct
name|tree_common
block|{
name|tree
name|chain
decl_stmt|;
name|tree
name|type
decl_stmt|;
name|void
modifier|*
name|aux
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
name|bounded_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|deprecated_flag
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
comment|/* This flag is presently unused.  However, language front-ends      should not make use of this flag; it is reserved for future      expansion.  */
name|unsigned
name|dummy
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The following table lists the uses of each of the above flags and    for which types of nodes they are defined.  Note that expressions    include decls.     addressable_flag:         TREE_ADDRESSABLE in    	   VAR_DECL, FUNCTION_DECL, FIELD_DECL, CONSTRUCTOR, LABEL_DECL, 	   ..._TYPE, IDENTIFIER_NODE. 	   In a STMT_EXPR, it means we want the result of the enclosed 	   expression.     static_flag:         TREE_STATIC in            VAR_DECL, FUNCTION_DECL, CONSTRUCTOR, ADDR_EXPR        TREE_NO_UNUSED_WARNING in            CONVERT_EXPR, NOP_EXPR, COMPOUND_EXPR        TREE_VIA_VIRTUAL in            TREE_LIST or TREE_VEC        TREE_CONSTANT_OVERFLOW in            INTEGER_CST, REAL_CST, COMPLEX_CST        TREE_SYMBOL_REFERENCED in            IDENTIFIER_NODE     public_flag:         TREE_OVERFLOW in            INTEGER_CST, REAL_CST, COMPLEX_CST        TREE_PUBLIC in            VAR_DECL or FUNCTION_DECL or IDENTIFIER_NODE        TREE_VIA_PUBLIC in            TREE_LIST or TREE_VEC        EXPR_WFL_EMIT_LINE_NOTE in            EXPR_WITH_FILE_LOCATION     private_flag:         TREE_VIA_PRIVATE in            TREE_LIST or TREE_VEC        TREE_PRIVATE in            ??? unspecified nodes     protected_flag:         TREE_VIA_PROTECTED in            TREE_LIST 	   TREE_VEC        TREE_PROTECTED in            BLOCK 	   ??? unspecified nodes     side_effects_flag:         TREE_SIDE_EFFECTS in            all expressions     volatile_flag:         TREE_THIS_VOLATILE in            all expressions        TYPE_VOLATILE in            ..._TYPE     readonly_flag:         TREE_READONLY in            all expressions        TYPE_READONLY in            ..._TYPE     constant_flag:         TREE_CONSTANT in            all expressions     unsigned_flag:         TREE_UNSIGNED in            INTEGER_TYPE, ENUMERAL_TYPE, FIELD_DECL        DECL_BUILT_IN_NONANSI in            FUNCTION_DECL        SAVE_EXPR_NOPLACEHOLDER in 	   SAVE_EXPR     asm_written_flag:         TREE_ASM_WRITTEN in            VAR_DECL, FUNCTION_DECL, RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE 	   BLOCK     used_flag:         TREE_USED in            expressions, IDENTIFIER_NODE     nothrow_flag:         TREE_NOTHROW in            CALL_EXPR, FUNCTION_DECL     bounded_flag:         TREE_BOUNDED in 	   expressions, VAR_DECL, PARM_DECL, FIELD_DECL, FUNCTION_DECL, 	   IDENTIFIER_NODE        TYPE_BOUNDED in 	   ..._TYPE     deprecated_flag:  	TREE_DEPRECATED in 	   ..._DECL */
end_comment

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
define|\
value|((NODE)->common.code = (ENUM_BITFIELD (tree_code)) (VALUE))
end_define

begin_comment
comment|/* When checking is enabled, errors will be generated if a tree node    is accessed incorrectly. The macros abort with a fatal error.  */
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
name|t
parameter_list|,
name|code
parameter_list|)
value|__extension__				\ ({  const tree __t = (t);						\     if (TREE_CODE(__t) != (code))					\       tree_check_failed (__t, code, __FILE__, __LINE__, __FUNCTION__);	\     __t; })
end_define

begin_define
define|#
directive|define
name|TREE_CLASS_CHECK
parameter_list|(
name|t
parameter_list|,
name|class
parameter_list|)
value|__extension__			\ ({  const tree __t = (t);						\     if (TREE_CODE_CLASS(TREE_CODE(__t)) != (class))			\       tree_class_check_failed (__t, class, __FILE__, __LINE__,		\ 			       __FUNCTION__);				\     __t; })
end_define

begin_comment
comment|/* These checks have to be special cased.  */
end_comment

begin_define
define|#
directive|define
name|CST_OR_CONSTRUCTOR_CHECK
parameter_list|(
name|t
parameter_list|)
value|__extension__			\ ({  const tree __t = (t);						\     enum tree_code const __c = TREE_CODE(__t);				\     if (__c != CONSTRUCTOR&& TREE_CODE_CLASS(__c) != 'c')		\       tree_check_failed (__t, CONSTRUCTOR, __FILE__, __LINE__,		\ 			 __FUNCTION__);					\     __t; })
end_define

begin_define
define|#
directive|define
name|EXPR_CHECK
parameter_list|(
name|t
parameter_list|)
value|__extension__					\ ({  const tree __t = (t);						\     char const __c = TREE_CODE_CLASS(TREE_CODE(__t));			\     if (__c != 'r'&& __c != 's'&& __c != '<'				\&& __c != '1'&& __c != '2'&& __c != 'e')			\       tree_class_check_failed (__t, 'e', __FILE__, __LINE__,		\ 			       __FUNCTION__);				\     __t; })
end_define

begin_decl_stmt
specifier|extern
name|void
name|tree_check_failed
name|PARAMS
argument_list|(
operator|(
specifier|const
name|tree
operator|,
expr|enum
name|tree_code
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tree_class_check_failed
name|PARAMS
argument_list|(
operator|(
specifier|const
name|tree
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
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
name|TREE_CHECK
parameter_list|(
name|t
parameter_list|,
name|code
parameter_list|)
value|(t)
end_define

begin_define
define|#
directive|define
name|TREE_CLASS_CHECK
parameter_list|(
name|t
parameter_list|,
name|code
parameter_list|)
value|(t)
end_define

begin_define
define|#
directive|define
name|CST_OR_CONSTRUCTOR_CHECK
parameter_list|(
name|t
parameter_list|)
value|(t)
end_define

begin_define
define|#
directive|define
name|EXPR_CHECK
parameter_list|(
name|t
parameter_list|)
value|(t)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|tree
parameter_list|)
value|TREE_CLASS_CHECK  (tree, 't')
end_define

begin_define
define|#
directive|define
name|DECL_CHECK
parameter_list|(
name|tree
parameter_list|)
value|TREE_CLASS_CHECK  (tree, 'd')
end_define

begin_define
define|#
directive|define
name|CST_CHECK
parameter_list|(
name|tree
parameter_list|)
value|TREE_CLASS_CHECK  (tree, 'c')
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
value|((size_t) (TYPE)& 0777777)
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
value|while ((TREE_CODE (EXP) == NOP_EXPR				\ 	  || TREE_CODE (EXP) == CONVERT_EXPR			\ 	  || TREE_CODE (EXP) == NON_LVALUE_EXPR)		\&& TREE_OPERAND (EXP, 0) != error_mark_node		\&& (TYPE_MODE (TREE_TYPE (EXP))			\ 	     == TYPE_MODE (TREE_TYPE (TREE_OPERAND (EXP, 0))))	\&& (TREE_UNSIGNED (TREE_TYPE (EXP))			\ 	     == TREE_UNSIGNED (TREE_TYPE (TREE_OPERAND (EXP, 0))))) \     (EXP) = TREE_OPERAND (EXP, 0)
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
comment|/* Nonzero if TYPE represents an integral type.  Note that we do not    include COMPLEX types here.  */
end_comment

begin_define
define|#
directive|define
name|INTEGRAL_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == INTEGER_TYPE || TREE_CODE (TYPE) == ENUMERAL_TYPE  \    || TREE_CODE (TYPE) == BOOLEAN_TYPE || TREE_CODE (TYPE) == CHAR_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents a floating-point type, including complex    floating-point types.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == REAL_TYPE	\    || (TREE_CODE (TYPE) == COMPLEX_TYPE \&& TREE_CODE (TREE_TYPE (TYPE)) == REAL_TYPE))
end_define

begin_comment
comment|/* Nonzero if TYPE represents an aggregate (multi-component) type.  */
end_comment

begin_define
define|#
directive|define
name|AGGREGATE_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == ARRAY_TYPE || TREE_CODE (TYPE) == RECORD_TYPE \    || TREE_CODE (TYPE) == UNION_TYPE || TREE_CODE (TYPE) == QUAL_UNION_TYPE \    || TREE_CODE (TYPE) == SET_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents an unbounded pointer or unbounded    reference type.  (It should be renamed to INDIRECT_TYPE_P.)  */
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
comment|/* Nonzero if TYPE represents a bounded pointer or bounded reference type.  */
end_comment

begin_define
define|#
directive|define
name|BOUNDED_INDIRECT_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == RECORD_TYPE&& TREE_TYPE (TYPE))
end_define

begin_comment
comment|/* Nonzero if TYPE represents a bounded pointer type.  */
end_comment

begin_define
define|#
directive|define
name|BOUNDED_POINTER_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(BOUNDED_INDIRECT_TYPE_P (TYPE) \&& TREE_CODE (TYPE_BOUNDED_SUBTYPE (TYPE)) == POINTER_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents a bounded reference type.  Bounded    reference types have two specific uses: (1) When a reference is    seated to a variable-length RECORD_TYPE that has an array of    indeterminate length as its final field.  For all other objects, it    is sufficient to check bounds at the time the reference is seated,    and assume that all future uses of the reference are safe, since    the address of references cannot change.  (2) When a reference    supertype is seated to an subtype object.  The bounds "remember"    the true size of the complete object, so that subsequent upcasts of    the address of the reference will be checked properly (is such a    thing valid C++?).  */
end_comment

begin_define
define|#
directive|define
name|BOUNDED_REFERENCE_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(BOUNDED_INDIRECT_TYPE_P (TYPE) \&& TREE_CODE (TYPE_BOUNDED_SUBTYPE (TYPE)) == REFERENCE_TYPE)
end_define

begin_comment
comment|/* Nonzero if TYPE represents a pointer or reference type, either    bounded or unbounded.  */
end_comment

begin_define
define|#
directive|define
name|MAYBE_BOUNDED_INDIRECT_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(POINTER_TYPE_P (TYPE) || BOUNDED_INDIRECT_TYPE_P (TYPE))
end_define

begin_comment
comment|/* Nonzero if TYPE represents a pointer type, either bounded or unbounded.  */
end_comment

begin_define
define|#
directive|define
name|MAYBE_BOUNDED_POINTER_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == POINTER_TYPE || BOUNDED_POINTER_TYPE_P (TYPE))
end_define

begin_comment
comment|/* Nonzero if TYPE represents a reference type, either bounded or    unbounded.  */
end_comment

begin_define
define|#
directive|define
name|MAYBE_BOUNDED_REFERENCE_TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == REFERENCE_TYPE || BOUNDED_REFERENCE_TYPE_P (TYPE))
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

begin_comment
comment|/* Nonzero if TYPE represents a type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_P
parameter_list|(
name|TYPE
parameter_list|)
value|(TREE_CODE_CLASS (TREE_CODE (TYPE)) == 't')
end_define

begin_escape
end_escape

begin_comment
comment|/* Define many boolean fields that all tree nodes have.  */
end_comment

begin_comment
comment|/* In VAR_DECL nodes, nonzero means address of this is needed.    So it cannot be in a register.    In a FUNCTION_DECL, nonzero means its address is needed.    So it must be compiled even if it is an inline function.    In a FIELD_DECL node, it means that the programmer is permitted to    construct the address of this field.  This is used for aliasing    purposes: see record_component_aliases.    In CONSTRUCTOR nodes, it means object constructed must be in memory.    In LABEL_DECL nodes, it means a goto for this label has been seen     from a place outside all binding contours that restore stack levels.    In ..._TYPE nodes, it means that objects of this type must    be fully addressable.  This means that pieces of this    object cannot go into register parameters, for example.    In IDENTIFIER_NODEs, this means that some extern decl for this name    had its address taken.  That matters for inline functions.  */
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
comment|/* In a VAR_DECL, nonzero means allocate static storage.    In a FUNCTION_DECL, nonzero if function has been defined.    In a CONSTRUCTOR, nonzero means allocate static storage.  */
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
comment|/* In a CONVERT_EXPR, NOP_EXPR or COMPOUND_EXPR, this means the node was    made implicitly and should not lead to an "unused value" warning.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NO_UNUSED_WARNING
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.static_flag)
end_define

begin_comment
comment|/* Nonzero for a TREE_LIST or TREE_VEC node means that the derivation    chain is via a `virtual' declaration.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VIA_VIRTUAL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.static_flag)
end_define

begin_comment
comment|/* In an INTEGER_CST, REAL_CST, or COMPLEX_CST, this means there was an    overflow in folding.  This is distinct from TREE_OVERFLOW because ANSI C    requires a diagnostic when overflows occur in constant expressions.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CONSTANT_OVERFLOW
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.static_flag)
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
comment|/* In an INTEGER_CST, REAL_CST, of COMPLEX_CST, this means there was an    overflow in folding, and no warning has been issued for this subexpression.    TREE_OVERFLOW implies TREE_CONSTANT_OVERFLOW, but not vice versa.  */
end_comment

begin_define
define|#
directive|define
name|TREE_OVERFLOW
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.public_flag)
end_define

begin_comment
comment|/* In a VAR_DECL or FUNCTION_DECL,    nonzero means name is to be accessible from outside this module.    In an IDENTIFIER_NODE, nonzero means an external declaration    accessible from outside this module was previously seen    for this name in an inner scope.  */
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
comment|/* Nonzero for TREE_LIST or TREE_VEC node means that the path to the    base class is via a `public' declaration, which preserves public    fields from the base class as public.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VIA_PUBLIC
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.public_flag)
end_define

begin_comment
comment|/* Ditto, for `private' declarations.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VIA_PRIVATE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.private_flag)
end_define

begin_comment
comment|/* Nonzero for TREE_LIST or TREE_VEC node means that the path to the    base class is via a `protected' declaration, which preserves    protected fields from the base class as protected.    OVERLOADED.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VIA_PROTECTED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.protected_flag)
end_define

begin_comment
comment|/* In any expression, nonzero means it has side effects or reevaluation    of the whole expression could produce a different value.    This is set if any subexpression is a function call, a side effect    or a reference to a volatile variable.    In a ..._DECL, this is set only if the declaration said `volatile'.  */
end_comment

begin_define
define|#
directive|define
name|TREE_SIDE_EFFECTS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.side_effects_flag)
end_define

begin_comment
comment|/* Nonzero means this expression is volatile in the C sense:    its address should be of type `volatile WHATEVER *'.    In other words, the declared item is volatile qualified.    This is used in _DECL nodes and _REF nodes.     In a ..._TYPE node, means this type is volatile-qualified.    But use TYPE_VOLATILE instead of this macro when the node is a type,    because eventually we may make that a different bit.     If this bit is set in an expression, so is TREE_SIDE_EFFECTS.  */
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
comment|/* In a VAR_DECL, PARM_DECL or FIELD_DECL, or any kind of ..._REF node,    nonzero means it may not be the lhs of an assignment.    In a ..._TYPE node, means this type is const-qualified    (but the macro TYPE_READONLY should be used instead of this macro    when the node is a type).  */
end_comment

begin_define
define|#
directive|define
name|TREE_READONLY
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.readonly_flag)
end_define

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
value|(TREE_READONLY (NODE)&& DECL_P (NODE))
end_define

begin_comment
comment|/* Value of expression is constant.    Always appears in all ..._CST nodes.    May also appear in an arithmetic expression, an ADDR_EXPR or a CONSTRUCTOR    if the value is constant.  */
end_comment

begin_define
define|#
directive|define
name|TREE_CONSTANT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.constant_flag)
end_define

begin_comment
comment|/* In INTEGER_TYPE or ENUMERAL_TYPE nodes, means an unsigned type.    In FIELD_DECL nodes, means an unsigned bit field.    The same bit is used in functions as DECL_BUILT_IN_NONANSI.  */
end_comment

begin_define
define|#
directive|define
name|TREE_UNSIGNED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.unsigned_flag)
end_define

begin_define
define|#
directive|define
name|TYPE_TRAP_SIGNED
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(flag_trapv&& ! TREE_UNSIGNED (TYPE_CHECK (NODE)))
end_define

begin_comment
comment|/* Nonzero in a VAR_DECL means assembler code has been written.    Nonzero in a FUNCTION_DECL means that the function has been compiled.    This is interesting in an inline function, since it might not need    to be compiled separately.    Nonzero in a RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE or ENUMERAL_TYPE    if the sdb debugging info for the type has been written.    In a BLOCK node, nonzero if reorder_blocks has already seen this block.  */
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
comment|/* Nonzero in a _DECL if the name is used in its scope.    Nonzero in an expr node means inhibit warning if value is unused.    In IDENTIFIER_NODEs, this means that some extern decl for this name    was used.  */
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
comment|/* In a type, nonzero means that all objects of the type are guaranteed by the    language or front-end to be properly aligned, so we can indicate that a MEM    of this type is aligned at least to the alignment of the type, even if it    doesn't appear that it is.  We see this, for example, in object-oriented    languages where a tag field may show this is an object of a more-aligned    variant of the more generic type.  */
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
comment|/* In a ..._TYPE node, nonzero means that the type's size and layout,    (or the size and layout of its arguments and/or return value in the    case of a FUNCTION_TYPE or METHOD_TYPE) was changed by the presence    of pointer bounds.  Use TYPE_BOUNDED instead of this macro when the    node is a type, because eventually we may make that a different    bit.  TYPE_BOUNDED doesn't mean that this type is a bounded indirect    type--use BOUNDED_POINTER_TYPE_P, BOUNDED_REFERENCE_TYPE_P,    BOUNDED_INDIRECT_TYPE_P to test for that.     In a FUNCTION_DECL, nonzero means that the size and layout of one    of its arguments and/or return value was changed by the presence of    pointer bounds.  This value can differ from the value of    TYPE_BOUNDED (TREE_TYPE (fundecl)) if the function was implicitly    declared, then later called with pointer args, or was declared with    a variable argument list and is later called with pointer values in    the variable argument list.     In a VAR_DECL, PARM_DECL or FIELD_DECL, TREE_BOUNDED matches the value    of the decl's type's BOUNDED_POINTER_TYPE_P.     In a CONSTRUCTOR or other expression, nonzero means the value is a    bounded pointer.  It is insufficient to determine the boundedness    of an expression EXP with BOUNDED_POINTER_TYPE_P (TREE_TYPE (EXP)),    since we allow pointer to be temporarily cast to integer for    rounding up to an alignment boudary in a way that preserves the    pointer's bounds.     In an IDENTIFIER_NODE, nonzero means that the name is prefixed with    BP_PREFIX (see varasm.c).  This occurs for the DECL_ASSEMBLER_NAME    of a function that has bounded pointer(s) for its return type and/or    argument type(s).  */
end_comment

begin_define
define|#
directive|define
name|TREE_BOUNDED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.bounded_flag)
end_define

begin_comment
comment|/* Nonzero in a IDENTIFIER_NODE if the use of the name is defined as a    deprecated feature by __attribute__((deprecated)).  */
end_comment

begin_define
define|#
directive|define
name|TREE_DEPRECATED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.deprecated_flag)
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
value|(((unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (A)		\< (unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (B))		\    || (((unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (A)		\         == (unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (B))	\&& TREE_INT_CST_LOW (A)< TREE_INT_CST_LOW (B)))
end_define

begin_struct
struct|struct
name|tree_int_cst
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|rtx
name|rtl
decl_stmt|;
comment|/* acts as link to register transfer language 			   (rtl) info */
comment|/* A sub-struct is necessary here because the function `const_hash'      wants to scan both words as a unit and taking the address of the      sub-struct yields the properly inclusive bounded pointer.  */
struct|struct
block|{
name|unsigned
name|HOST_WIDE_INT
name|low
decl_stmt|;
name|HOST_WIDE_INT
name|high
decl_stmt|;
block|}
name|int_cst
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* In REAL_CST, STRING_CST, COMPLEX_CST nodes, and CONSTRUCTOR nodes,    and generally in all kinds of constants that could    be given labels (rather than being immediate).  */
end_comment

begin_define
define|#
directive|define
name|TREE_CST_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(CST_OR_CONSTRUCTOR_CHECK (NODE)->real_cst.rtl)
end_define

begin_comment
comment|/* In a REAL_CST node.     We can represent a real value as either a `double' or an array of    longs.  */
end_comment

begin_define
define|#
directive|define
name|TREE_REAL_CST
parameter_list|(
name|NODE
parameter_list|)
value|(REAL_CST_CHECK (NODE)->real_cst.real_cst)
end_define

begin_include
include|#
directive|include
file|"real.h"
end_include

begin_struct
struct|struct
name|tree_real_cst
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|rtx
name|rtl
decl_stmt|;
comment|/* acts as link to register transfer language (rtl) info */
name|REAL_VALUE_TYPE
name|real_cst
decl_stmt|;
block|}
struct|;
end_struct

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
value|(STRING_CST_CHECK (NODE)->string.pointer)
end_define

begin_struct
struct|struct
name|tree_string
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|rtx
name|rtl
decl_stmt|;
comment|/* acts as link to register transfer language (rtl) info */
name|int
name|length
decl_stmt|;
specifier|const
name|char
modifier|*
name|pointer
decl_stmt|;
block|}
struct|;
end_struct

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

begin_struct
struct|struct
name|tree_complex
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|rtx
name|rtl
decl_stmt|;
comment|/* acts as link to register transfer language (rtl) info */
name|tree
name|real
decl_stmt|;
name|tree
name|imag
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_include
include|#
directive|include
file|"hashtable.h"
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

begin_struct
struct|struct
name|tree_identifier
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
struct|;
end_struct

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

begin_struct
struct|struct
name|tree_list
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
struct|;
end_struct

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
name|TREE_VEC_ELT
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
value|(TREE_VEC_CHECK (NODE)->vec.a[I])
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

begin_struct
struct|struct
name|tree_vec
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|int
name|length
decl_stmt|;
name|tree
name|a
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Define fields and accessors for some nodes that represent expressions.  */
end_comment

begin_comment
comment|/* In a SAVE_EXPR node.  */
end_comment

begin_define
define|#
directive|define
name|SAVE_EXPR_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (SAVE_EXPR_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|SAVE_EXPR_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(*(rtx *)&SAVE_EXPR_CHECK (NODE)->exp.operands[2])
end_define

begin_define
define|#
directive|define
name|SAVE_EXPR_NOPLACEHOLDER
parameter_list|(
name|NODE
parameter_list|)
value|TREE_UNSIGNED (SAVE_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* Nonzero if the SAVE_EXPRs value should be kept, even if it occurs    both in normal code and in a handler.  (Normally, in a handler, all    SAVE_EXPRs are unsaved, meaning that there values are    recalculated.)  */
end_comment

begin_define
define|#
directive|define
name|SAVE_EXPR_PERSISTENT_P
parameter_list|(
name|NODE
parameter_list|)
value|TREE_ASM_WRITTEN (SAVE_EXPR_CHECK (NODE))
end_define

begin_comment
comment|/* In a RTL_EXPR node.  */
end_comment

begin_define
define|#
directive|define
name|RTL_EXPR_SEQUENCE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(*(rtx *)&RTL_EXPR_CHECK (NODE)->exp.operands[0])
end_define

begin_define
define|#
directive|define
name|RTL_EXPR_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(*(rtx *)&RTL_EXPR_CHECK (NODE)->exp.operands[1])
end_define

begin_comment
comment|/* In a WITH_CLEANUP_EXPR node.  */
end_comment

begin_define
define|#
directive|define
name|WITH_CLEANUP_EXPR_RTL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(*(rtx *)&WITH_CLEANUP_EXPR_CHECK (NODE)->exp.operands[2])
end_define

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
value|TREE_OPERAND (CONSTRUCTOR_CHECK (NODE), 1)
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
value|(EXPR_CHECK (NODE)->exp.operands[I])
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
comment|/* In a LABELED_BLOCK_EXPR node.  */
end_comment

begin_define
define|#
directive|define
name|LABELED_BLOCK_LABEL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (LABELED_BLOCK_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|LABELED_BLOCK_BODY
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (LABELED_BLOCK_EXPR_CHECK (NODE), 1)
end_define

begin_comment
comment|/* In a EXIT_BLOCK_EXPR node.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_BLOCK_LABELED_BLOCK
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (EXIT_BLOCK_EXPR_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|EXIT_BLOCK_RETURN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (EXIT_BLOCK_EXPR_CHECK (NODE), 1)
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
value|TREE_OPERAND (LOOP_EXPR_CHECK (NODE), 0)
end_define

begin_comment
comment|/* In a EXPR_WITH_FILE_LOCATION node.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_WFL_EMIT_LINE_NOTE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(EXPR_WITH_FILE_LOCATION_CHECK (NODE)->common.public_flag)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_NODE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (EXPR_WITH_FILE_LOCATION_CHECK (NODE), 0)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_FILENAME_NODE
parameter_list|(
name|NODE
parameter_list|)
define|\
value|TREE_OPERAND (EXPR_WITH_FILE_LOCATION_CHECK (NODE), 1)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_FILENAME
parameter_list|(
name|NODE
parameter_list|)
define|\
value|IDENTIFIER_POINTER (EXPR_WFL_FILENAME_NODE (NODE))
end_define

begin_comment
comment|/* ??? Java uses this in all expressions.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_WFL_LINECOL
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_CHECK (NODE)->exp.complexity)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_LINENO
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_WFL_LINECOL (NODE)>> 12)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_COLNO
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_WFL_LINECOL (NODE)& 0xfff)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_SET_LINECOL
parameter_list|(
name|NODE
parameter_list|,
name|LINE
parameter_list|,
name|COL
parameter_list|)
define|\
value|(EXPR_WFL_LINECOL(NODE) = ((LINE)<< 12) | ((COL)& 0xfff))
end_define

begin_struct
struct|struct
name|tree_exp
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|int
name|complexity
decl_stmt|;
name|tree
name|operands
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

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
comment|/* If block reordering splits a lexical block into discontiguous    address ranges, we'll make a copy of the original block.     Note that this is logically distinct from BLOCK_ABSTRACT_ORIGIN.    In that case, we have one source block that has been replicated    (through inlining or unrolling) into many logical blocks, and that    these logical blocks have different physical variables in them.     In this case, we have one logical block split into several    non-contiguous address ranges.  Most debug formats can't actually    represent this idea directly, so we fake it by creating multiple    logical blocks with the same variables in them.  However, for those    that do support non-contiguous regions, these allow the original    logical block to be reconstructed, along with the set of address    ranges.     One of the logical block fragments is arbitrarily chosen to be    the ORIGIN.  The other fragments will point to the origin via    BLOCK_FRAGMENT_ORIGIN; the origin itself will have this pointer    be null.  The list of fragments will be chained through     BLOCK_FRAGMENT_CHAIN from the origin.  */
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

begin_struct
struct|struct
name|tree_block
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
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Define fields and accessors for nodes representing data types.  */
end_comment

begin_comment
comment|/* See tree.def for documentation of the use of these fields.    Look at the documentation of the various ..._TYPE tree codes.  */
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
value|(TYPE_CHECK (NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_DOMAIN
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELDS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_METHODS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.maxval)
end_define

begin_define
define|#
directive|define
name|TYPE_VFIELD
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.minval)
end_define

begin_define
define|#
directive|define
name|TYPE_ARG_TYPES
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_METHOD_BASETYPE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.maxval)
end_define

begin_define
define|#
directive|define
name|TYPE_OFFSET_BASETYPE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.maxval)
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
name|TYPE_MIN_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.minval)
end_define

begin_define
define|#
directive|define
name|TYPE_MAX_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.maxval)
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
value|(TYPE_CHECK (NODE)->type.values)
end_define

begin_comment
comment|/* Indirect types present difficulties because they may be represented    as either POINTER_TYPE/REFERENCE_TYPE nodes (unbounded) or as    RECORD_TYPE nodes (bounded).  Bounded and unbounded pointers might    be logically equivalent, but physically different.  Simple    comparison of the main variant only tells if the types are    logically equivalent.  Use this predicate to compare for physical    equivalency.  */
end_comment

begin_comment
comment|/* Types have the same main variant, and have the same boundedness.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_MAIN_VARIANTS_PHYSICALLY_EQUAL_P
parameter_list|(
name|TYPE1
parameter_list|,
name|TYPE2
parameter_list|)
define|\
value|(TYPE_MAIN_VARIANT (TYPE1) == TYPE_MAIN_VARIANT (TYPE2)	\&& TREE_CODE (TYPE1) == TREE_CODE (TYPE2))
end_define

begin_comment
comment|/* Return the type variant that has no qualifiers (i.e., the main variant),    except that the boundedness qualifier is preserved.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_MAIN_PHYSICAL_VARIANT
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(BOUNDED_POINTER_TYPE_P (TYPE)			\    ? build_qualified_type (TYPE, TYPE_QUAL_BOUNDED)	\    : TYPE_MAIN_VARIANT (TYPE))
end_define

begin_comment
comment|/* For aggregate types, information about this type, as a base type    for itself.  Used in a language-dependent way for types that are    neither a RECORD_TYPE, QUAL_UNION_TYPE, nor a UNION_TYPE.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BINFO
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.binfo)
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
comment|/* If nonzero, this type's size and layout, (or the size and layout of    its arguments and/or return value in the case of a FUNCTION_TYPE or    METHOD_TYPE) was changed by the presence of pointer bounds.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BOUNDED
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->common.bounded_flag)
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

begin_define
define|#
directive|define
name|TYPE_QUAL_BOUNDED
value|0x8
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
value|((TYPE_READONLY (NODE) * TYPE_QUAL_CONST)			\    | (TYPE_VOLATILE (NODE) * TYPE_QUAL_VOLATILE)		\    | (TYPE_RESTRICT (NODE) * TYPE_QUAL_RESTRICT)		\    | (BOUNDED_INDIRECT_TYPE_P (NODE) * TYPE_QUAL_BOUNDED))
end_define

begin_comment
comment|/* The set of qualifiers pertinent to an expression node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_EXPR_QUALS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_READONLY (NODE) * TYPE_QUAL_CONST)		\    | (TREE_THIS_VOLATILE (NODE) * TYPE_QUAL_VOLATILE)	\    | (TREE_BOUNDED (NODE) * TYPE_QUAL_BOUNDED))
end_define

begin_comment
comment|/* The set of qualifiers pertinent to a FUNCTION_DECL node.  */
end_comment

begin_define
define|#
directive|define
name|TREE_FUNC_QUALS
parameter_list|(
name|NODE
parameter_list|)
define|\
value|((TREE_READONLY (NODE) * TYPE_QUAL_CONST)		\    | (TREE_THIS_VOLATILE (NODE) * TYPE_QUAL_VOLATILE))
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
comment|/* If set in an ARRAY_TYPE, indicates a string type (for languages    that distinguish string from array of char).    If set in a SET_TYPE, indicates a bitstring type.  */
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
value|TYPE_MAX_VALUE (ARRAY_TYPE_CHECK (ARRAY_TYPE))
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
value|GET_MODE_NUNITS (VECTOR_TYPE_CHECK (VECTOR_TYPE)->type.mode)
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
comment|/* A bounded pointer or bounded reference type (collectively called    indirect types) is represented as a RECORD_TYPE node containing    three pointer fields whose type is the corresponding unbounded    POINTER_TYPE or REFERENCE_TYPE.  A RECORD_TYPE node that represents    a bounded indirect type differs from a normal RECORD_TYPE node in    that its TREE_TYPE is non-NULL and has the pointed-to type just as    a POINTER_TYPE or REFERENCE_TYPE node has.  The bounded RECORD_TYPE    nodes are stored on the same type variant chain alongside the    variants of the underlaying indirect types nodes.  The main variant    of such chains is always the unbounded type.  */
end_comment

begin_comment
comment|/* Access the field decls of a bounded-pointer type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BOUNDED_VALUE
parameter_list|(
name|TYPE
parameter_list|)
value|TYPE_FIELDS (TYPE)
end_define

begin_define
define|#
directive|define
name|TYPE_BOUNDED_BASE
parameter_list|(
name|TYPE
parameter_list|)
value|TREE_CHAIN (TYPE_BOUNDED_VALUE (TYPE))
end_define

begin_define
define|#
directive|define
name|TYPE_BOUNDED_EXTENT
parameter_list|(
name|TYPE
parameter_list|)
value|TREE_CHAIN (TYPE_BOUNDED_BASE (TYPE))
end_define

begin_comment
comment|/* Access the simple-pointer subtype of a bounded-pointer type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_BOUNDED_SUBTYPE
parameter_list|(
name|TYPE
parameter_list|)
value|TREE_TYPE (TYPE_BOUNDED_VALUE (TYPE))
end_define

begin_comment
comment|/* Find the unbounded counterpart to a type, or return TYPE if it is    already unbounded.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_UNBOUNDED_VARIANT
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(BOUNDED_POINTER_TYPE_P (TYPE) ? TYPE_BOUNDED_SUBTYPE (TYPE) : (TYPE))
end_define

begin_comment
comment|/* This field comprises two bits, for values in the range 0..3:     depth=0 means that type is a scalar, or an aggregate that contains    only depth=0 types, or a function that has only depth=0 types for    its return value and argument types.     depth=1 means that type is a pointer to a depth=0 type, or an    aggregate that contains only depth=0 and depth=1 types, or a    function that has only depth=0 and depth=1 types for its return    value and argument types.     The meanings of depth=2 and depth=3 are obvious by induction.    Varargs functions are depth=3.  The type `va_list' is depth=3.     The purpose of measuring pointer depth of a type is to determine    the eligibility of a function for an automatically-generated    bounded-pointer thunk.  A depth=0 functions needs no thunk.  A    depth=1 function is eligible for an automatic thunk.  Functions    with depth 2 or more are too complex to get automatic thunks.     Function decls also have a pointer_depth field, since we also    consider the actual argument types for functions.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_POINTER_DEPTH
parameter_list|(
name|TYPE
parameter_list|)
value|(TYPE_CHECK (TYPE)->type.pointer_depth)
end_define

begin_comment
comment|/* In a FUNCTION_TYPE node, this bit stores the value of    default_pointer_boundedness at the time TYPE was created.  It is    useful for choosing default boundedness of function arguments for    non-prototype function decls and for varargs/stdarg lists.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_AMBIENT_BOUNDEDNESS
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(FUNCTION_TYPE_CHECK (TYPE)->type.transparent_union_flag)
end_define

begin_define
define|#
directive|define
name|MAX_POINTER_DEPTH
value|2
end_define

begin_define
define|#
directive|define
name|VA_LIST_POINTER_DEPTH
value|3
end_define

begin_struct
struct|struct
name|tree_type
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
name|pointer_depth
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
block|{
name|int
name|address
decl_stmt|;
name|char
modifier|*
name|pointer
decl_stmt|;
block|}
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
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Define accessor macros for information about type inheritance    and basetypes.     A "basetype" means a particular usage of a data type for inheritance    in another type.  Each such basetype usage has its own "binfo"    object to describe it.  The binfo object is a TREE_VEC node.     Inheritance is represented by the binfo nodes allocated for a    given type.  For example, given types C and D, such that D is    inherited by C, 3 binfo nodes will be allocated: one for describing    the binfo properties of C, similarly one for D, and one for    describing the binfo properties of D as a base type for C.    Thus, given a pointer to class C, one can get a pointer to the binfo    of D acting as a basetype for C by looking at C's binfo's basetypes.  */
end_comment

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
value|TREE_TYPE (NODE)
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
value|TREE_VEC_ELT ((NODE), 1)
end_define

begin_define
define|#
directive|define
name|TYPE_BINFO_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_OFFSET (TYPE_BINFO (NODE))
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
value|TREE_VEC_ELT ((NODE), 2)
end_define

begin_define
define|#
directive|define
name|TYPE_BINFO_VTABLE
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_VTABLE (TYPE_BINFO (NODE))
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
value|TREE_VEC_ELT ((NODE), 3)
end_define

begin_define
define|#
directive|define
name|TYPE_BINFO_VIRTUALS
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_VIRTUALS (TYPE_BINFO (NODE))
end_define

begin_comment
comment|/* A vector of binfos for the direct basetypes inherited by this    basetype.     If this basetype describes type D as inherited in C, and if the    basetypes of D are E and F, then this vector contains binfos for    inheritance of E and F by C.     ??? This could probably be done by just allocating the    base types at the end of this TREE_VEC (instead of using    another TREE_VEC).  This would simplify the calculation    of how many basetypes a given type had.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_BASETYPES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT ((NODE), 4)
end_define

begin_define
define|#
directive|define
name|TYPE_BINFO_BASETYPES
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT (TYPE_BINFO (NODE), 4)
end_define

begin_comment
comment|/* The number of basetypes for NODE.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_N_BASETYPES
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(BINFO_BASETYPES (NODE) ? TREE_VEC_LENGTH (BINFO_BASETYPES (NODE)) : 0)
end_define

begin_comment
comment|/* Accessor macro to get to the Nth basetype of this basetype.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_BASETYPE
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
value|TREE_VEC_ELT (BINFO_BASETYPES (NODE), (N))
end_define

begin_define
define|#
directive|define
name|TYPE_BINFO_BASETYPE
parameter_list|(
name|NODE
parameter_list|,
name|N
parameter_list|)
define|\
value|BINFO_TYPE (TREE_VEC_ELT (BINFO_BASETYPES (TYPE_BINFO (NODE)), (N)))
end_define

begin_comment
comment|/* For a BINFO record describing a virtual base class, i.e., one where    TREE_VIA_VIRTUAL is set, this field assists in locating the virtual    base.  The actual contents are language-dependent.  Under the old    ABI, the C++ front-end uses a FIELD_DECL whose contents are a    pointer to the virtual base; under the new ABI this field is    instead a INTEGER_CST giving an offset into the vtable where the    offset to the virtual base can be found.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VPTR_FIELD
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT (NODE, 5)
end_define

begin_comment
comment|/* The size of a base class subobject of this type.  Not all frontends    currently allocate the space for these fields.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT (NODE, 6)
end_define

begin_define
define|#
directive|define
name|BINFO_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT (NODE, 7)
end_define

begin_define
define|#
directive|define
name|TYPE_BINFO_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_SIZE (TYPE_BINFO (NODE))
end_define

begin_define
define|#
directive|define
name|TYPE_BINFO_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|BINFO_SIZE_UNIT (TYPE_BINFO (NODE))
end_define

begin_comment
comment|/* Slot used to build a chain that represents a use of inheritance.    For example, if X is derived from Y, and Y is derived from Z,    then this field can be used to link the binfo node for X to    the binfo node for X's Y to represent the use of inheritance    from X to Y.  Similarly, this slot of the binfo node for X's Y    can point to the Z from which Y is inherited (in X's inheritance    hierarchy).  In this fashion, one can represent and traverse specific    uses of inheritance using the binfo nodes themselves (instead of    consing new space pointing to binfo nodes).    It is up to the language-dependent front-ends to maintain    this information as necessary.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_INHERITANCE_CHAIN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT ((NODE), 0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define fields and accessors for nodes representing declared names.  */
end_comment

begin_comment
comment|/* Nonzero if DECL represents a decl.  */
end_comment

begin_define
define|#
directive|define
name|DECL_P
parameter_list|(
name|DECL
parameter_list|)
value|(TREE_CODE_CLASS (TREE_CODE (DECL)) == 'd')
end_define

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
value|(DECL_CHECK (NODE)->decl.name)
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
define|\
value|((DECL_ASSEMBLER_NAME_SET_P (NODE)		\     ? (void) 0					\     : (*lang_set_decl_assembler_name) (NODE)),	\    DECL_CHECK (NODE)->decl.assembler_name)
end_define

begin_comment
comment|/* Returns non-zero if the DECL_ASSEMBLER_NAME for NODE has been set.  If zero,    the NODE might still have a DECL_ASSEMBLER_NAME -- it just hasn't been set    yet.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ASSEMBLER_NAME_SET_P
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CHECK (NODE)->decl.assembler_name != NULL_TREE)
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
value|(DECL_CHECK (NODE)->decl.assembler_name = (NAME))
end_define

begin_comment
comment|/* Copy the DECL_ASSEMBLER_NAME from DECL1 to DECL2.  Note that if DECL1's    DECL_ASSEMBLER_NAME has not yet been set, using this macro will not cause    the DECL_ASSEMBLER_NAME of either DECL to be set.  In other words, the    semantics of using this macro, are different than saying:            SET_DECL_ASSEMBLER_NAME(DECL2, DECL_ASSEMBLER_NAME (DECL1))     which will try to set the DECL_ASSEMBLER_NAME for DECL1.  */
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
value|(DECL_ASSEMBLER_NAME_SET_P (DECL1)					\    ? (void) SET_DECL_ASSEMBLER_NAME (DECL2, 				\                                      DECL_ASSEMBLER_NAME (DECL1))	\    : (void) 0)
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
value|(DECL_CHECK (NODE)->decl.section_name)
end_define

begin_comment
comment|/*  For FIELD_DECLs, this is the     RECORD_TYPE, UNION_TYPE, or QUAL_UNION_TYPE node that the field is     a member of.  For VAR_DECL, PARM_DECL, FUNCTION_DECL, LABEL_DECL,     and CONST_DECL nodes, this points to either the FUNCTION_DECL for the     containing function, the RECORD_TYPE or UNION_TYPE for the containing     type, or NULL_TREE if the given decl has "file scope".  */
end_comment

begin_define
define|#
directive|define
name|DECL_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.context)
end_define

begin_define
define|#
directive|define
name|DECL_FIELD_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->decl.context)
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
value|(DECL_CHECK (NODE)->decl.attributes)
end_define

begin_comment
comment|/* In a FIELD_DECL, this is the field position, counting in bytes, of the    byte containing the bit closest to the beginning of the structure.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FIELD_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->decl.arguments)
end_define

begin_comment
comment|/* In a FIELD_DECL, this is the offset, in bits, of the first bit of the    field from DECL_FIELD_OFFSET.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FIELD_BIT_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|(FIELD_DECL_CHECK (NODE)->decl.u2.t)
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
value|(FIELD_DECL_CHECK (NODE)->decl.result)
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
value|(DECL_CHECK (NODE)->decl.arguments)
end_define

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
value|(DECL_CHECK (NODE)->decl.result)
end_define

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
value|(FUNCTION_DECL_CHECK (NODE)->decl.result)
end_define

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
value|(TYPE_DECL_CHECK (NODE)->decl.result)
end_define

begin_comment
comment|/* In PARM_DECL, holds the type as written (perhaps a function or array).  */
end_comment

begin_define
define|#
directive|define
name|DECL_ARG_TYPE_AS_WRITTEN
parameter_list|(
name|NODE
parameter_list|)
value|(PARM_DECL_CHECK (NODE)->decl.result)
end_define

begin_comment
comment|/* For a FUNCTION_DECL, holds the tree of BINDINGs.    For a VAR_DECL, holds the initial value.    For a PARM_DECL, not used--default    values for parameters are encoded in the type of the function,    not in the PARM_DECL slot.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INITIAL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.initial)
end_define

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
value|(PARM_DECL_CHECK (NODE)->decl.initial)
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
value|(FIELD_DECL_CHECK (NODE)->decl.initial)
end_define

begin_comment
comment|/* These two fields describe where in the source code the declaration    was.  If the declaration appears in several places (as for a C    function that is declared first and then defined later), this    information should refer to the definition.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SOURCE_FILE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.filename)
end_define

begin_define
define|#
directive|define
name|DECL_SOURCE_LINE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.linenum)
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
value|(DECL_CHECK (NODE)->decl.size)
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
value|(DECL_CHECK (NODE)->decl.size_unit)
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
value|(DECL_CHECK (NODE)->decl.u1.a.align)
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
value|(((unsigned HOST_WIDE_INT)1)<< FIELD_DECL_CHECK (NODE)->decl.u1.a.off_align)
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
value|(FIELD_DECL_CHECK (NODE)->decl.u1.a.off_align	= exact_log2 ((X)& -(X)))
end_define

begin_comment
comment|/* 1 if the alignment for this type was requested by "aligned" attribute,    0 if it is the default for this type.  */
end_comment

begin_define
define|#
directive|define
name|DECL_USER_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.user_align)
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
value|(DECL_CHECK (NODE)->decl.mode)
end_define

begin_comment
comment|/* Holds the RTL expression for the value of a variable or function.  If    PROMOTED_MODE is defined, the mode of this expression may not be same    as DECL_MODE.  In that case, DECL_MODE contains the mode corresponding    to the variable's data type, while the mode    of DECL_RTL is the mode actually used to contain the data.       This value can be evaluated lazily for functions, variables with    static storage duration, and labels.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RTL
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CHECK (NODE)->decl.rtl				\    ? (NODE)->decl.rtl					\    : (make_decl_rtl (NODE, NULL), (NODE)->decl.rtl))
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
value|(DECL_CHECK (NODE)->decl.rtl = (RTL))
end_define

begin_comment
comment|/* Returns non-zero if the DECL_RTL for NODE has already been set.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RTL_SET_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.rtl != NULL)
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
value|(DECL_CHECK (NODE2)->decl.rtl = DECL_CHECK (NODE1)->decl.rtl)
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
comment|/* Holds an INSN_LIST of all of the live ranges in which the variable    has been moved to a possibly different register.  */
end_comment

begin_define
define|#
directive|define
name|DECL_LIVE_RANGE_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.live_range_rtl)
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
value|(PARM_DECL_CHECK (NODE)->decl.u2.r)
end_define

begin_comment
comment|/* For FUNCTION_DECL, if it is inline, holds the saved insn chain.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SAVED_INSNS
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->decl.u2.f)
end_define

begin_comment
comment|/* For FUNCTION_DECL, if it is built-in,    this identifies which built-in operation it is.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FUNCTION_CODE
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->decl.u1.f)
end_define

begin_comment
comment|/* The DECL_VINDEX is used for FUNCTION_DECLS in two different ways.    Before the struct containing the FUNCTION_DECL is laid out,    DECL_VINDEX may point to a FUNCTION_DECL in a base class which    is the FUNCTION_DECL which this FUNCTION_DECL will replace as a virtual    function.  When the class is laid out, this pointer is changed    to an INTEGER_CST node which is suitable for use as an index    into the virtual function table.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VINDEX
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.vindex)
end_define

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
value|(FIELD_DECL_CHECK (NODE)->decl.vindex)
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
value|(DECL_CHECK (NODE)->decl.uid)
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
value|(DECL_CHECK (NODE)->decl.abstract_origin)
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
comment|/* Nonzero if a _DECL means that the name of this decl should be ignored    for symbolic debug purposes.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IGNORED_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.ignored_flag)
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
value|(DECL_CHECK (NODE)->decl.abstract_flag)
end_define

begin_comment
comment|/* Nonzero if a _DECL means that no warnings should be generated just    because this decl is unused.  */
end_comment

begin_define
define|#
directive|define
name|DECL_IN_SYSTEM_HEADER
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(DECL_CHECK (NODE)->decl.in_system_header_flag)
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
value|(DECL_CHECK (NODE)->decl.common_flag)
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
value|(DECL_CHECK (NODE)->decl.lang_specific)
end_define

begin_comment
comment|/* In a VAR_DECL or FUNCTION_DECL,    nonzero means external reference:    do not allocate storage, and refer to a definition elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|DECL_EXTERNAL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.external_flag)
end_define

begin_comment
comment|/* In a VAR_DECL for a RECORD_TYPE, sets number for non-init_priority    initializatons.  */
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
comment|/* In a TYPE_DECL    nonzero means the detail info about this type is not dumped into stabs.    Instead it will generate cross reference ('x') of names.     This uses the same flag as DECL_EXTERNAL.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_DECL_SUPPRESS_DEBUG
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(TYPE_DECL_CHECK (NODE)->decl.external_flag)
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
value|(DECL_CHECK (NODE)->decl.regdecl_flag)
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
value|(LABEL_DECL_CHECK (NODE)->decl.regdecl_flag)
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
value|(FIELD_DECL_CHECK (NODE)->decl.regdecl_flag)
end_define

begin_comment
comment|/* In a FUNCTION_DECL with a non-zero DECL_CONTEXT, indicates that a    static chain is not needed.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NO_STATIC_CHAIN
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->decl.regdecl_flag)
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
value|(DECL_CHECK (NODE)->decl.nonlocal_flag)
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
value|(FUNCTION_DECL_CHECK (NODE)->decl.inline_flag)
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
value|(FUNCTION_DECL_CHECK (NODE)->decl.uninlinable)
end_define

begin_comment
comment|/* In a FUNCTION_DECL, the saved representation of the body of the    entire function.  Usually a COMPOUND_STMT, but in C++ this may also    be a RETURN_INIT, CTOR_INITIALIZER, or TRY_BLOCK.  */
end_comment

begin_define
define|#
directive|define
name|DECL_SAVED_TREE
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->decl.saved_tree)
end_define

begin_comment
comment|/* List of FUNCTION_DECLs inlined into this function's body.  */
end_comment

begin_define
define|#
directive|define
name|DECL_INLINED_FNS
parameter_list|(
name|NODE
parameter_list|)
value|(FUNCTION_DECL_CHECK (NODE)->decl.inlined_fns)
end_define

begin_comment
comment|/* Nonzero in a FUNCTION_DECL means this is a built-in function    that is not specified by ansi C and that users are supposed to be allowed    to redefine for any purpose whatever.  */
end_comment

begin_define
define|#
directive|define
name|DECL_BUILT_IN_NONANSI
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->common.unsigned_flag)
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
value|(FUNCTION_DECL_CHECK (NODE)->decl.malloc_flag)
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
value|(FUNCTION_DECL_CHECK (NODE)->decl.pure_flag)
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
value|(FIELD_DECL_CHECK (NODE)->decl.bit_field_flag)
end_define

begin_comment
comment|/* In a LABEL_DECL, nonzero means label was defined inside a binding    contour that restored a stack level and which is now exited.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TOO_LATE
parameter_list|(
name|NODE
parameter_list|)
value|(LABEL_DECL_CHECK (NODE)->decl.bit_field_flag)
end_define

begin_comment
comment|/* Unused in FUNCTION_DECL.  */
end_comment

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
value|(VAR_DECL_CHECK (NODE)->decl.bit_field_flag)
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
value|(FUNCTION_DECL_CHECK (NODE)->decl.built_in_class)
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
value|(DECL_CHECK (NODE)->decl.virtual_flag)
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
value|(DECL_CHECK (NODE)->decl.defer_output)
end_define

begin_comment
comment|/* Used in PARM_DECLs whose type are unions to indicate that the    argument should be passed in the same way that the first union    alternative would be passed.  */
end_comment

begin_define
define|#
directive|define
name|DECL_TRANSPARENT_UNION
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(PARM_DECL_CHECK (NODE)->decl.transparent_union)
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
value|(FUNCTION_DECL_CHECK (NODE)->decl.static_ctor_flag)
end_define

begin_define
define|#
directive|define
name|DECL_STATIC_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
define|\
value|(FUNCTION_DECL_CHECK (NODE)->decl.static_dtor_flag)
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
value|(DECL_CHECK (NODE)->decl.artificial_flag)
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
value|(DECL_CHECK (NODE)->decl.weak_flag)
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
value|(DECL_CHECK (NODE)->decl.transparent_union)
end_define

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
value|(DECL_CHECK (NODE)->decl.comdat_flag)
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
value|(FUNCTION_DECL_CHECK (NODE)->decl.no_instrument_function_entry_exit)
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
value|(FUNCTION_DECL_CHECK (NODE)->decl.no_limit_stack)
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
value|(DECL_CHECK (NODE)->decl.lang_flag_0)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_1
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.lang_flag_1)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_2
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.lang_flag_2)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_3
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.lang_flag_3)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_4
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.lang_flag_4)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_5
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.lang_flag_5)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_6
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.lang_flag_6)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_FLAG_7
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.lang_flag_7)
end_define

begin_comment
comment|/* Used to indicate that the pointer to this DECL cannot be treated as    an address constant.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NON_ADDR_CONST_P
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.non_addr_const_p)
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
value|(FIELD_DECL_CHECK (NODE)->decl.non_addressable)
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
value|(DECL_CHECK (NODE)->decl.pointer_alias_set)
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
comment|/* The pointer_depth field comprises two bits for values in the range    0..3.  The value is normally equal to TYPE_POINTER_DEPTH of decl's    type node, but for functions it migth be greater.  For example,    this can happen when the function is declared to accept a parameter    of type void* (depth=1), but is actually called with an argument of    type foo** (depth=2).  The function type will get the formal    parameter's depth, but the function decl will get the actual    argument's depth.  */
end_comment

begin_define
define|#
directive|define
name|DECL_POINTER_DEPTH
parameter_list|(
name|DECL
parameter_list|)
value|(DECL_CHECK (DECL)->decl.pointer_depth)
end_define

begin_struct_decl
struct_decl|struct
name|function
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|tree_decl
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
name|unsigned
name|int
name|uid
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
name|external_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|nonlocal_flag
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
name|bit_field_flag
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
name|in_system_header_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|common_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|defer_output
range|:
literal|1
decl_stmt|;
name|unsigned
name|transparent_union
range|:
literal|1
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
name|artificial_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|weak_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|non_addr_const_p
range|:
literal|1
decl_stmt|;
name|unsigned
name|no_instrument_function_entry_exit
range|:
literal|1
decl_stmt|;
name|unsigned
name|comdat_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|malloc_flag
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
name|unsigned
name|pure_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|pointer_depth
range|:
literal|2
decl_stmt|;
name|unsigned
name|non_addressable
range|:
literal|1
decl_stmt|;
name|unsigned
name|user_align
range|:
literal|1
decl_stmt|;
name|unsigned
name|uninlinable
range|:
literal|1
decl_stmt|;
comment|/* Three unused bits.  */
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
union|union
block|{
comment|/* In a FUNCTION_DECL for which DECL_BUILT_IN holds, this is        DECL_FUNCTION_CODE.  */
name|enum
name|built_in_function
name|f
decl_stmt|;
comment|/* In a FUNCITON_DECL for which DECL_BUILT_IN does not hold, this        is used by language-dependent code.  */
name|HOST_WIDE_INT
name|i
decl_stmt|;
comment|/* DECL_ALIGN and DECL_OFFSET_ALIGN.  (These are not used for        FUNCTION_DECLs).  */
struct|struct
block|{
name|unsigned
name|int
name|align
range|:
literal|24
decl_stmt|;
name|unsigned
name|int
name|off_align
range|:
literal|8
decl_stmt|;
block|}
name|a
struct|;
block|}
name|u1
union|;
name|tree
name|size_unit
decl_stmt|;
name|tree
name|name
decl_stmt|;
name|tree
name|context
decl_stmt|;
name|tree
name|arguments
decl_stmt|;
comment|/* Also used for DECL_FIELD_OFFSET */
name|tree
name|result
decl_stmt|;
comment|/* Also used for DECL_BIT_FIELD_TYPE */
name|tree
name|initial
decl_stmt|;
comment|/* Also used for DECL_QUALIFIER */
name|tree
name|abstract_origin
decl_stmt|;
name|tree
name|assembler_name
decl_stmt|;
name|tree
name|section_name
decl_stmt|;
name|tree
name|attributes
decl_stmt|;
name|rtx
name|rtl
decl_stmt|;
comment|/* RTL representation for object.  */
name|rtx
name|live_range_rtl
decl_stmt|;
comment|/* In FUNCTION_DECL, if it is inline, holds the saved insn chain.      In FIELD_DECL, is DECL_FIELD_BIT_OFFSET.      In PARM_DECL, holds an RTL for the stack slot      of register where the data was actually passed.      Used by Chill and Java in LABEL_DECL and by C++ and Java in VAR_DECL.  */
union|union
block|{
name|struct
name|function
modifier|*
name|f
decl_stmt|;
name|rtx
name|r
decl_stmt|;
name|tree
name|t
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
name|u2
union|;
comment|/* In a FUNCTION_DECL, this is DECL_SAVED_TREE.  */
name|tree
name|saved_tree
decl_stmt|;
comment|/* In a FUNCTION_DECL, these are function data which is to be kept      as long as FUNCTION_DECL is kept.  */
name|tree
name|inlined_fns
decl_stmt|;
name|tree
name|vindex
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
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Define the overall contents of a tree node.    It may be any of the structures declared above    for various types of node.  */
end_comment

begin_union
union|union
name|tree_node
block|{
name|struct
name|tree_common
name|common
decl_stmt|;
name|struct
name|tree_int_cst
name|int_cst
decl_stmt|;
name|struct
name|tree_real_cst
name|real_cst
decl_stmt|;
name|struct
name|tree_string
name|string
decl_stmt|;
name|struct
name|tree_complex
name|complex
decl_stmt|;
name|struct
name|tree_identifier
name|identifier
decl_stmt|;
name|struct
name|tree_decl
name|decl
decl_stmt|;
name|struct
name|tree_type
name|type
decl_stmt|;
name|struct
name|tree_list
name|list
decl_stmt|;
name|struct
name|tree_vec
name|vec
decl_stmt|;
name|struct
name|tree_exp
name|exp
decl_stmt|;
name|struct
name|tree_block
name|block
decl_stmt|;
block|}
union|;
end_union

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
name|TI_VOID_TYPE
block|,
name|TI_PTR_TYPE
block|,
name|TI_CONST_PTR_TYPE
block|,
name|TI_PTRDIFF_TYPE
block|,
name|TI_VA_LIST_TYPE
block|,
name|TI_VOID_LIST_NODE
block|,
name|TI_UV4SF_TYPE
block|,
name|TI_UV4SI_TYPE
block|,
name|TI_UV8HI_TYPE
block|,
name|TI_UV8QI_TYPE
block|,
name|TI_UV4HI_TYPE
block|,
name|TI_UV2SI_TYPE
block|,
name|TI_UV2SF_TYPE
block|,
name|TI_UV16QI_TYPE
block|,
name|TI_V4SF_TYPE
block|,
name|TI_V4SI_TYPE
block|,
name|TI_V8HI_TYPE
block|,
name|TI_V8QI_TYPE
block|,
name|TI_V4HI_TYPE
block|,
name|TI_V2SI_TYPE
block|,
name|TI_V2SF_TYPE
block|,
name|TI_V16QI_TYPE
block|,
name|TI_MAIN_IDENTIFIER
block|,
name|TI_MAX
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
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

begin_define
define|#
directive|define
name|unsigned_V16QI_type_node
value|global_trees[TI_UV16QI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_V4SI_type_node
value|global_trees[TI_UV4SI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_V8QI_type_node
value|global_trees[TI_UV8QI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_V8HI_type_node
value|global_trees[TI_UV8HI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_V4HI_type_node
value|global_trees[TI_UV4HI_TYPE]
end_define

begin_define
define|#
directive|define
name|unsigned_V2SI_type_node
value|global_trees[TI_UV2SI_TYPE]
end_define

begin_define
define|#
directive|define
name|V16QI_type_node
value|global_trees[TI_V16QI_TYPE]
end_define

begin_define
define|#
directive|define
name|V4SF_type_node
value|global_trees[TI_V4SF_TYPE]
end_define

begin_define
define|#
directive|define
name|V4SI_type_node
value|global_trees[TI_V4SI_TYPE]
end_define

begin_define
define|#
directive|define
name|V8QI_type_node
value|global_trees[TI_V8QI_TYPE]
end_define

begin_define
define|#
directive|define
name|V8HI_type_node
value|global_trees[TI_V8HI_TYPE]
end_define

begin_define
define|#
directive|define
name|V4HI_type_node
value|global_trees[TI_V4HI_TYPE]
end_define

begin_define
define|#
directive|define
name|V2SI_type_node
value|global_trees[TI_V2SI_TYPE]
end_define

begin_define
define|#
directive|define
name|V2SF_type_node
value|global_trees[TI_V2SF_TYPE]
end_define

begin_comment
comment|/* An enumeration of the standard C integer types.  These must be    ordered so that shorter types appear before longer ones.  */
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

begin_decl_stmt
specifier|extern
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

begin_define
define|#
directive|define
name|NULL_TREE
value|(tree) NULL
end_define

begin_comment
comment|/* Approximate positive square root of a host double.  This is for    statistical reports, not code generation.  */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|approx_sqrt
name|PARAMS
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|permalloc
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
name|char
modifier|*
name|expralloc
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compute the number of bytes occupied by 'node'.  This routine only    looks at TREE_CODE and, if the code is TREE_VEC, TREE_VEC_LENGTH.  */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|tree_size
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lowest level primitive for allocating a node.    The TREE_CODE is the only argument.  Contents are initialized    to zero except for a few of the common fields.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|make_node
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
name|make_lang_type
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern tree (*make_lang_type_fn
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Make a copy of a node, with all the same contents except    for TREE_PERMANENT.  (The copy is permanent    iff nodes being made now are permanent.)  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|copy_node
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a copy of a chain of TREE_LIST nodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|copy_list
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a TREE_VEC.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|make_tree_vec
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the (unique) IDENTIFIER_NODE node for a given name.    The name is supplied as a char *.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_identifier
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
comment|/* Identical to get_identifier, except that the length is assumed    known.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_identifier_with_length
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If an identifier with the name TEXT (a null-terminated string) has    previously been referred to, return that node; otherwise return    NULL_TREE.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|maybe_get_identifier
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
comment|/* Construct various types of nodes.  */
end_comment

begin_define
define|#
directive|define
name|build_int_2
parameter_list|(
name|LO
parameter_list|,
name|HI
parameter_list|)
define|\
value|build_int_2_wide ((unsigned HOST_WIDE_INT) (LO), (HOST_WIDE_INT) (HI))
end_define

begin_decl_stmt
specifier|extern
name|tree
name|build
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
name|build_nt
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
name|build_int_2_wide
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_real
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|REAL_VALUE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|build_real_from_int_cst
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
name|build_complex
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
name|build_string
name|PARAMS
argument_list|(
operator|(
name|int
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
name|build1
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
name|build_tree_list
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
name|build_decl
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
name|build_block
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
name|build_expr_wfl
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
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Construct various nodes representing data types.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|make_signed_type
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
name|make_unsigned_type
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
name|initialize_sizetypes
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
name|set_sizetype
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
name|signed_or_unsigned_type
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
name|void
name|fixup_unsigned_type
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
name|build_pointer_type
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
name|build_reference_type
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
name|build_type_no_quals
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
name|build_index_type
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
name|build_index_2_type
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
name|build_array_type
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
name|build_function_type
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
name|build_method_type
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
name|build_offset_type
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
name|build_complex_type
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
name|array_type_nelts
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
name|value_member
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
name|purpose_member
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
name|binfo_member
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
name|unsigned
name|int
name|attribute_hash_list
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
name|attribute_list_equal
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
name|attribute_list_contained
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
name|tree_int_cst_equal
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
name|tree_int_cst_lt
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
name|tree_int_cst_compare
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
name|host_integerp
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
name|HOST_WIDE_INT
name|tree_low_cst
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
name|tree_int_cst_msb
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
name|tree_int_cst_sgn
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
name|tree_expr_nonnegative_p
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
name|rtl_expr_nonnegative_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|index_type_equal
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
name|get_inner_array_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From expmed.c.  Since rtl.h is included after tree.h, we can't    put the prototype here.  Rtl.h does declare the prototype if    tree.h had been included.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|make_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Return a type like TTYPE except that its TYPE_ATTRIBUTES    is ATTRIBUTE.     Such modified types already made are recorded so that duplicates    are not made.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_type_attribute_variant
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
name|build_decl_attribute_variant
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
name|PARAMS
argument_list|(
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
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|attribute_spec
name|default_target_attribute_table
index|[]
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|tree
name|merge_decl_attributes
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
name|merge_type_attributes
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
name|default_comp_type_attributes
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
name|default_set_default_type_attributes
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
name|default_insert_attributes
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
name|bool
name|default_function_attribute_inlinable_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Split a list of declspecs and attributes into two.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|split_specs_attrs
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

begin_comment
comment|/* Strip attributes from a list of combined specs and attrs.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|strip_attrs
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if an attribute and its arguments are valid for a decl or type.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|valid_machine_attribute
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

begin_comment
comment|/* Given a tree node and a string, return non-zero if the tree node is    a valid attribute name for the string.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|is_attribute_p
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

begin_comment
comment|/* Given an attribute name and a list of attributes, return the list element    of the attribute or NULL_TREE if not found.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|lookup_attribute
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

begin_comment
comment|/* Given two attributes lists, return a list of their union.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|merge_attributes
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

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
end_ifdef

begin_comment
comment|/* Given two Windows decl attributes lists, possibly including    dllimport, return a list of their union .  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|merge_dllimport_decl_attributes
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return a version of the TYPE, qualified as indicated by the    TYPE_QUALS, if one exists.  If no qualified version exists yet,    return NULL_TREE.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_qualified_type
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

begin_comment
comment|/* Like get_qualified_type, but creates the type if it does not    exist.  This function never returns NULL_TREE.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_qualified_type
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

begin_comment
comment|/* Like build_qualified_type, but only deals with the `const' and    `volatile' qualifiers.  This interface is retained for backwards    compatiblity with the various front-ends; new code should use    build_qualified_type instead.  */
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

begin_decl_stmt
specifier|extern
name|tree
name|build_type_copy
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a ..._TYPE node, calculate the TYPE_SIZE, TYPE_SIZE_UNIT,    TYPE_ALIGN and TYPE_MODE fields.  If called more than once on one    node, does nothing except for the first time.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|layout_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* The alignment of the record so far, not including padding, in bits.  */
name|unsigned
name|int
name|unpacked_align
decl_stmt|;
comment|/* The alignment of the record so far, allowing for the record to be      padded only at the end, in bits.  */
name|unsigned
name|int
name|unpadded_align
decl_stmt|;
comment|/* The static variables (i.e., class variables, as opposed to      instance variables) encountered in T.  */
name|tree
name|pending_statics
decl_stmt|;
name|int
name|packed_maybe_necessary
decl_stmt|;
block|}
typedef|*
name|record_layout_info
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|set_lang_adjust_rli
name|PARAMS
argument_list|(
operator|(
name|void
argument_list|(
argument|*
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|record_layout_info
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|record_layout_info
name|start_record_layout
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
name|bit_from_pos
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
name|byte_from_pos
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
name|pos_from_byte
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|tree
operator|*
operator|,
name|unsigned
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
name|pos_from_bit
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|tree
operator|*
operator|,
name|unsigned
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
name|normalize_offset
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|tree
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|rli_size_unit_so_far
name|PARAMS
argument_list|(
operator|(
name|record_layout_info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|rli_size_so_far
name|PARAMS
argument_list|(
operator|(
name|record_layout_info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|normalize_rli
name|PARAMS
argument_list|(
operator|(
name|record_layout_info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|place_field
name|PARAMS
argument_list|(
operator|(
name|record_layout_info
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|compute_record_mode
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
name|finish_record_layout
name|PARAMS
argument_list|(
operator|(
name|record_layout_info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a hashcode and a ..._TYPE node (for which the hashcode was made),    return a canonicalized ..._TYPE node, so that duplicates are not made.    How the hash code is computed is up to the caller, as long as any two    callers that could hash identical-looking type nodes agree.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|type_hash_canon
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a VAR_DECL, PARM_DECL, RESULT_DECL or FIELD_DECL node,    calculates the DECL_SIZE, DECL_SIZE_UNIT, DECL_ALIGN and DECL_MODE    fields.  Call this only once for any given decl node.     Second argument is the boundary that this field can be assumed to    be starting at (in bits).  Zero means it can be assumed aligned    on any boundary that may be needed.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|layout_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the mode for data of a given size SIZE and mode class CLASS.    If LIMIT is nonzero, then don't use modes bigger than MAX_FIXED_MODE_SIZE.    The value is BLKmode if no other mode is found.  This is like    mode_for_size, but is passed a tree.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|mode_for_size_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
expr|enum
name|mode_class
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return an expr equal to X but certainly not valid as an lvalue.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|non_lvalue
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
name|pedantic_non_lvalue
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
name|convert
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
name|unsigned
name|int
name|expr_align
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
name|size_in_bytes
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
name|HOST_WIDE_INT
name|int_size_in_bytes
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
name|bit_position
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
name|HOST_WIDE_INT
name|int_bit_position
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
name|byte_position
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
name|HOST_WIDE_INT
name|int_byte_position
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|USIZETYPE
block|,
comment|/* Unsigned representation of sizes in bytes.  */
name|BITSIZETYPE
block|,
comment|/* Normal representation of sizes in bits.  */
name|SBITSIZETYPE
block|,
comment|/* Signed representation of sizes in bits.  */
name|UBITSIZETYPE
block|,
comment|/* Unsifgned representation of sizes in bits.  */
name|TYPE_KIND_LAST
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
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
name|usizetype
value|sizetype_tab[(int) USIZETYPE]
end_define

begin_define
define|#
directive|define
name|sbitsizetype
value|sizetype_tab[(int) SBITSIZETYPE]
end_define

begin_define
define|#
directive|define
name|ubitsizetype
value|sizetype_tab[(int) UBITSIZETYPE]
end_define

begin_decl_stmt
specifier|extern
name|tree
name|size_binop
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
name|size_diffop
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
name|size_int_wide
name|PARAMS
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
expr|enum
name|size_type_kind
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|size_int_type_wide
name|PARAMS
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|size_int_type
parameter_list|(
name|L
parameter_list|,
name|T
parameter_list|)
value|size_int_type_wide ((HOST_WIDE_INT) (L), T)
end_define

begin_define
define|#
directive|define
name|size_int
parameter_list|(
name|L
parameter_list|)
value|size_int_wide ((HOST_WIDE_INT) (L), SIZETYPE)
end_define

begin_define
define|#
directive|define
name|ssize_int
parameter_list|(
name|L
parameter_list|)
value|size_int_wide ((HOST_WIDE_INT) (L), SSIZETYPE)
end_define

begin_define
define|#
directive|define
name|bitsize_int
parameter_list|(
name|L
parameter_list|)
value|size_int_wide ((HOST_WIDE_INT) (L), BITSIZETYPE)
end_define

begin_define
define|#
directive|define
name|sbitsize_int
parameter_list|(
name|L
parameter_list|)
value|size_int_wide ((HOST_WIDE_INT) (L), SBITSIZETYPE)
end_define

begin_decl_stmt
specifier|extern
name|tree
name|round_up
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
name|round_down
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
name|get_pending_sizes
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
name|is_pending_size
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
name|put_pending_size
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
name|put_pending_sizes
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* If nonzero, an upper limit on alignment of structure fields, in bits.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|maximum_field_alignment
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-zero, the alignment of a bitstring or (power-)set value, in bits.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|set_alignment
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Concatenate two lists (chains of TREE_LIST nodes) X and Y    by making the last node in X point to Y.    Returns X, except if X is 0 returns Y.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|chainon
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
comment|/* Make a new TREE_LIST node from specified PURPOSE, VALUE and CHAIN.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|tree_cons
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

begin_comment
comment|/* Return the last tree node in a chain.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|tree_last
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reverse the order of elements in a chain, and return the new head.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|nreverse
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns the length of a chain of nodes    (number of chain pointers to follow before reaching a null pointer).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|list_length
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns the number of FIELD_DECLs in a type.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fields_length
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* integer_zerop (tree x) is nonzero if X is an integer constant of value 0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|integer_zerop
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* integer_onep (tree x) is nonzero if X is an integer constant of value 1 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|integer_onep
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* integer_all_onesp (tree x) is nonzero if X is an integer constant    all of whose significant bits are 1.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|integer_all_onesp
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* integer_pow2p (tree x) is nonzero is X is an integer constant with    exactly one bit 1.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|integer_pow2p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* staticp (tree x) is nonzero if X is a reference to data allocated    at a fixed address in memory.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|staticp
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gets an error if argument X is not an lvalue.    Also returns 1 if X is an lvalue, 0 if not.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lvalue_or_else
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

begin_comment
comment|/* save_expr (EXP) returns an expression equivalent to EXP    but it can be used multiple times within context CTX    and only evaluate EXP once.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|save_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns the index of the first non-tree operand for CODE, or the number    of operands if all are trees.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|first_rtl_op
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unsave_expr (EXP) returns an expression equivalent to EXP but it    can be used multiple times and will evaluate EXP in its entirety    each time.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|unsave_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reset EXP in place so that it can be expaned again.  Does not    recurse into subtrees.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|unsave_expr_1
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like unsave_expr_1, but recurses into all subtrees.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|unsave_expr_now
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-null, these are language-specific helper functions for    unsave_expr_now.  If present, LANG_UNSAVE is called before its    argument (an UNSAVE_EXPR) is to be unsaved, and all other    processing in unsave_expr_now is aborted.  LANG_UNSAVE_EXPR_NOW is    called from unsave_expr_1 for language-specific tree codes.  */
end_comment

begin_extern
extern|extern void (*lang_unsave
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*lang_unsave_expr_now
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Return 0 if it is safe to evaluate EXPR multiple times,    return 1 if it is safe if EXPR is unsaved afterward, or    return 2 if it is completely unsafe.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unsafe_for_reeval
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-null, these are language-specific helper functions for    unsafe_for_reeval.  Return negative to not handle some tree.  */
end_comment

begin_extern
extern|extern int (*lang_unsafe_for_reeval
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Return 1 if EXP contains a PLACEHOLDER_EXPR; i.e., if it represents a size    or offset that depends on a field within a record.     Note that we only allow such expressions within simple arithmetic    or a COND_EXPR.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|contains_placeholder_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if EXP contains any expressions that produce cleanups for an    outer scope to deal with.  Used by fold.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|has_cleanups
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a tree EXP, a FIELD_DECL F, and a replacement value R,    return a tree with all occurrences of references to F in a    PLACEHOLDER_EXPR replaced by R.   Note that we assume here that EXP    contains only arithmetic expressions.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|substitute_in_expr
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

begin_comment
comment|/* variable_size (EXP) is like save_expr (EXP) except that it    is for the special case of something that is part of a    variable size for a data type.  It makes special arrangements    to compute the value at the right time when the data type    belongs to a function parameter.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|variable_size
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stabilize_reference (EXP) returns an reference equivalent to EXP    but it can be used multiple times    and only evaluate the subexpressions once.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|stabilize_reference
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Subroutine of stabilize_reference; this is called for subtrees of    references.  Any expression with side-effects must be put in a SAVE_EXPR    to ensure that it is only evaluated once.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|stabilize_reference_1
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return EXP, stripped of any conversions to wider types    in such a way that the result of converting to type FOR_TYPE    is the same as if EXP were converted to FOR_TYPE.    If FOR_TYPE is 0, it signifies EXP's type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_unwidened
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
comment|/* Return OP or a simpler expression for a narrower value    which can be sign-extended or zero-extended to give back OP.    Store in *UNSIGNEDP_PTR either 1 if the value should be zero-extended    or 0 if the value should be sign-extended.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_narrower
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

begin_comment
comment|/* Given MODE and UNSIGNEDP, return a suitable type-tree    with that mode.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|type_for_mode
name|PARAMS
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

begin_comment
comment|/* Given PRECISION and UNSIGNEDP, return a suitable type-tree    for an integer type with at least that precision.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|type_for_size
name|PARAMS
argument_list|(
operator|(
name|unsigned
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given an integer type T, return a type like T but unsigned.    If T is unsigned, the value is T.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given an integer type T, return a type like T but signed.    If T is signed, the value is T.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|signed_type
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function must be defined in the language-specific files.    expand_expr calls it to build the cleanup-expression for a TARGET_EXPR.    This is defined in a language-specific file.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|maybe_build_cleanup
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given an expression EXP that may be a COMPONENT_REF or an ARRAY_REF,    look for nested component-refs or array-refs at constant positions    and find the ultimate containing object, which is returned.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_inner_reference
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|tree
operator|*
operator|,
expr|enum
name|machine_mode
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if T is an expression that get_inner_reference handles.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|handled_component_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a DECL or TYPE, return the scope in which it was declared, or    NUL_TREE if there is no containing scope.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_containing_scope
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the FUNCTION_DECL which provides this _DECL with its context,    or zero if none.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|decl_function_context
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the RECORD_TYPE, UNION_TYPE, or QUAL_UNION_TYPE which provides    this _DECL with its context, or zero if none.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|decl_type_context
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given the FUNCTION_DECL for the current function,    return zero if it is ok for this function to be inline.    Otherwise return a warning message with a single %s    for the function's name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|function_cannot_inline_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if EXPR is the real constant zero.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|real_zerop
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Declare commonly used variables for tree structure.  */
end_comment

begin_comment
comment|/* Points to the name of the input file from which the current input    being parsed originally came (before it went into cpp).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|input_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current line number in input file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

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
comment|/* Nonzero means can safely call expand_expr now;    otherwise layout_type puts variable sizes onto `pending_sizes' instead.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|immediate_size_expand
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to the FUNCTION_DECL of the function whose body we are reading.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_function_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means a FUNC_BEGIN label was emitted.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_function_func_begin_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means all ..._TYPE nodes should be allocated permanently.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|all_types_permanent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to function to compute the name to use to print a declaration.    DECL is the declaration in question.    VERBOSITY determines what information will be printed:      0: DECL_NAME, demangled as necessary.      1: and scope information.      2: and any other information that might be interesting, such as function         parameter types in C++.  */
end_comment

begin_extern
extern|extern const char *(*decl_printable_name
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Pointer to function to finish handling an incomplete decl at the    end of compilation.  */
end_comment

begin_extern
extern|extern void (*incomplete_decl_finalize_hook
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Declare a predefined function.  Return the declaration.  This function is    provided by each language frontend.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|builtin_function
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|tree
operator|,
name|int
operator|,
expr|enum
name|built_in_class
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* In tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|perm_calloc
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clean_symbol_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|get_file_function_name_long
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
name|tree
name|get_set_constructor_bits
name|PARAMS
argument_list|(
operator|(
name|tree
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
name|tree
name|get_set_constructor_bytes
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|unsigned
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
name|tree
name|get_callee_fndecl
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
name|set_decl_assembler_name
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
name|type_num_arguments
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* In stmt.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in_control_zone_p
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
name|expand_fixups
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|expand_start_stmt_expr
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
name|expand_end_stmt_expr
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
name|expand_expr_stmt
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
name|expand_expr_stmt_value
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

begin_decl_stmt
specifier|extern
name|int
name|warn_if_unused_value
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
name|expand_decl_init
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
name|clear_last_expr
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
name|expand_label
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
name|expand_goto
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
name|expand_asm
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
name|expand_start_cond
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
name|expand_end_cond
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
name|expand_start_else
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
name|expand_start_elseif
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
name|struct
name|nesting
modifier|*
name|expand_start_loop
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
name|struct
name|nesting
modifier|*
name|expand_start_loop_continue_elsewhere
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
name|struct
name|nesting
modifier|*
name|expand_start_null_loop
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
name|expand_loop_continue_here
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
name|expand_end_loop
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
name|expand_end_null_loop
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
name|expand_continue_loop
name|PARAMS
argument_list|(
operator|(
expr|struct
name|nesting
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|expand_exit_loop
name|PARAMS
argument_list|(
operator|(
expr|struct
name|nesting
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|expand_exit_loop_if_false
name|PARAMS
argument_list|(
operator|(
expr|struct
name|nesting
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
name|expand_exit_loop_top_cond
name|PARAMS
argument_list|(
operator|(
expr|struct
name|nesting
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
name|expand_exit_something
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
name|expand_return
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
name|optimize_tail_recursion
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_start_bindings_and_block
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

begin_define
define|#
directive|define
name|expand_start_bindings
parameter_list|(
name|flags
parameter_list|)
define|\
value|expand_start_bindings_and_block(flags, NULL_TREE)
end_define

begin_decl_stmt
specifier|extern
name|void
name|expand_end_bindings
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

begin_decl_stmt
specifier|extern
name|void
name|warn_about_unused_variables
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
name|start_cleanup_deferral
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
name|end_cleanup_deferral
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
name|is_body_block
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
name|conditional_context
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
name|struct
name|nesting
modifier|*
name|current_nesting_level
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
name|last_cleanup_this_contour
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
name|expand_start_case
name|PARAMS
argument_list|(
operator|(
name|int
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
name|void
name|expand_end_case
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
name|add_case_node
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
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pushcase
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
name|tree
argument_list|)
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
name|int
name|pushcase_range
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|tree
argument_list|(
operator|*
argument_list|)
argument_list|(
name|tree
argument_list|,
name|tree
argument_list|)
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
name|void
name|using_eh_for_cleanups
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
name|stmt_loop_nest_empty
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In fold-const.c */
end_comment

begin_comment
comment|/* Fold constants as much as possible in an expression.    Returns the simplified expression.    Acts only on the top level of the expression;    if the argument itself cannot be simplified, its    subexpressions are not changed.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|fold
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
name|force_fit_type
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
name|add_double
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|neg_double
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mul_double
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|lshift_double
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
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
name|rshift_double
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
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
name|lrotate_double
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rrotate_double
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|operand_equal_p
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
name|invert_truthvalue
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In builtins.c.  Given a type, apply default promotions wrt unnamed    function arguments and return the new type.  Return NULL_TREE if no    change.  Required by any language that supports variadic arguments.  */
end_comment

begin_extern
extern|extern tree (*lang_type_promotes_to
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|tree
name|fold_builtin
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The language front-end must define these functions.  */
end_comment

begin_comment
comment|/* Function to replace the DECL_LANG_SPECIFIC field of a DECL with a copy.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|copy_lang_decl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function called with no arguments to parse and compile the input.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yyparse
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions for processing symbol declarations.  */
end_comment

begin_comment
comment|/* Function to enter a new lexical scope.    Takes one argument: always zero when called from outside the front end.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pushlevel
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function to exit a lexical scope.  It returns a BINDING for that scope.    Takes three arguments:      KEEP -- nonzero if there were declarations in this scope.      REVERSE -- reverse the order of decls before returning them.      FUNCTIONBODY -- nonzero if this level is the body of a function.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|poplevel
name|PARAMS
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

begin_comment
comment|/* Set the BLOCK node for the current scope level.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function to add a decl to the current scope level.    Takes one argument, a decl to add.    Returns that decl, or, if the same symbol is already declared, may    return a different decl for that name.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|pushdecl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function to return the chain of decls so far in the current scope level.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|getdecls
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function to return the chain of structure tags in the current scope level.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|gettags
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
name|build_nonstandard_integer_type
name|PARAMS
argument_list|(
operator|(
name|unsigned
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
name|build_range_type
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

begin_comment
comment|/* In alias.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|record_component_aliases
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
name|HOST_WIDE_INT
name|get_alias_set
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
name|alias_sets_conflict_p
name|PARAMS
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|readonly_fields_p
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
name|objects_must_conflict_p
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
comment|/* Set the DECL_ASSEMBLER_NAME for a node.  If it is the sort of thing    that the assembler should talk about, set DECL_ASSEMBLER_NAME to an    appropriate IDENTIFIER_NODE.  Otherwise, set it to the    ERROR_MARK_NODE to ensure that the assembler does not talk about    it.  */
end_comment

begin_extern
extern|extern void (*lang_set_decl_assembler_name
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_comment
comment|/* In tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|really_constant_p
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
name|int_fits_type_p
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
name|tree_log2
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
name|tree_floor_log2
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
name|preserve_data
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
name|object_permanent_p
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
name|type_precision
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
name|simple_cst_equal
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
name|compare_tree_int
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|type_list_equal
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
name|chain_member
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
name|chain_member_purpose
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
name|chain_member_value
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
name|listify
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
name|type_hash_lookup
name|PARAMS
argument_list|(
operator|(
name|unsigned
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
name|type_hash_add
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|type_hash_list
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
name|simple_cst_list_equal
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
name|dump_tree_statistics
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
name|print_obstack_statistics
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|print_obstack_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|expand_function_end
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
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
name|expand_function_start
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
name|expand_pending_sizes
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
name|real_onep
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
name|real_twop
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
name|gcc_obstack_init
name|PARAMS
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_obstacks
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
name|build_common_tree_nodes
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
name|build_common_tree_nodes_2
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
name|mark_tree_hashtable
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In function.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|setjmp_protect_args
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
name|setjmp_protect
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
name|expand_main_function
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
name|mark_varargs
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
name|init_dummy_function_start
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
name|expand_dummy_function_end
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
name|init_function_for_compilation
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
name|init_function_start
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
name|void
name|assign_parms
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
name|put_var_into_stack
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
name|flush_addressof
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
name|uninitialized_vars_warning
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
name|setjmp_args_warning
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
name|mark_all_temps_used
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
name|init_temp_slots
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
name|combine_temp_slots
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
name|free_temp_slots
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
name|pop_temp_slots
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
name|push_temp_slots
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
name|preserve_temp_slots
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|preserve_rtl_expr_temps
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
name|aggregate_value_p
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
name|free_temps_for_rtl_expr
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
name|instantiate_virtual_regs
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unshare_all_rtl
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|max_parm_reg_num
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
name|push_function_context
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
name|pop_function_context
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
name|push_function_context_to
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
name|pop_function_context_from
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
name|ggc_mark_struct_function
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In print-rtl.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|print_rtl
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In print-tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|debug_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|print_node
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
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
name|print_node_brief
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
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
name|indent_to
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In expr.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|apply_args_register_offset
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
name|rtx
name|expand_builtin_return_addr
name|PARAMS
argument_list|(
operator|(
expr|enum
name|built_in_function
operator|,
name|int
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_max_integer_computation_mode
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In emit-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|start_sequence_for_rtl_expr
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
name|rtx
name|emit_line_note
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In calls.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|setjmp_call_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In attribs.c.  */
end_comment

begin_comment
comment|/* Process the attributes listed in ATTRIBUTES and install them in *NODE,    which is either a DECL (including a TYPE_DECL) or a TYPE.  If a DECL,    it should be modified in place; if a TYPE, a copy should be created    unless ATTR_FLAG_TYPE_IN_PLACE is set in FLAGS.  FLAGS gives further    information, in the form of a bitwise OR of flags in enum attribute_flags    from tree.h.  Depending on these flags, some attributes may be    returned to be applied at a later stage (for example, to apply    a decl attribute to the declaration rather than to its type).  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|decl_attributes
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

begin_comment
comment|/* The following function must be provided by front ends    using attribs.c.  */
end_comment

begin_comment
comment|/* Possibly apply default attributes to a function (represented by    a FUNCTION_DECL).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|insert_default_attributes
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table of machine-independent attributes for checking formats, if used.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|attribute_spec
modifier|*
name|format_attribute_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table of machine-independent attributes for a particular language.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|attribute_spec
modifier|*
name|lang_attribute_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag saying whether common language attributes are to be supported.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lang_attribute_common
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In front end.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mark_addressable
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
name|incomplete_type_error
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
name|truthvalue_conversion
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
name|global_bindings_p
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
name|insert_block
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In integrate.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|save_for_inline
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
name|set_decl_abstract_flags
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
name|output_inline_function
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
name|set_decl_origin_self
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In stor-layout.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fixup_signed_type
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
name|internal_reference_types
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* varasm.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|make_decl_rtl
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
name|make_decl_one_only
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
name|supports_one_only
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
name|variable_section
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

begin_comment
comment|/* In fold-const.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|div_and_round_double
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|int
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In stmt.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_nop
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
name|expand_computed_goto
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
name|bool
name|parse_output_constraint
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|bool
operator|*
operator|,
name|bool
operator|*
operator|,
name|bool
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_asm_operands
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
name|any_pending_cleanups
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
name|init_stmt
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
name|init_stmt_for_function
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
name|drop_through_at_end_p
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
name|expand_start_target_temps
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
name|expand_end_target_temps
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
name|expand_elseif
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
name|save_stack_pointer
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
name|expand_decl
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
name|expand_decl_cleanup
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
name|expand_anon_union_decl
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
name|move_cleanups_up
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
name|expand_start_case_dummy
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
name|expand_end_case_dummy
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
name|case_index_expr_type
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
name|HOST_WIDE_INT
name|all_cases_count
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
name|check_for_full_enumeration_handling
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
name|declare_nonlocal_label
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If KIND=='I', return a suitable global initializer (constructor) name.    If KIND=='D', return a suitable global clean-up (destructor) name.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_file_function_name
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Interface of the DWARF2 unwind info support.  */
end_comment

begin_comment
comment|/* Generate a new label for the CFI info to refer to.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dwarf2out_cfi_label
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entry point to update the canonical frame address (CFA).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_def_cfa
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add the CFI for saving a register window.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_window_save
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
comment|/* Add a CFI to update the running total of the size of arguments pushed    onto the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_args_size
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entry point for saving a register to the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_reg_save
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entry point for saving the return address in the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_return_save
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entry point for saving the return address in a register.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_return_reg
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The type of a function that walks over tree structure.  */
end_comment

begin_typedef
typedef|typedef
name|tree
argument_list|(
argument|*walk_tree_fn
argument_list|)
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
expr_stmt|;
end_typedef

begin_comment
comment|/* In tree-dump.c */
end_comment

begin_comment
comment|/* Different tree dump places.  When you add new tree dump places,    extend the DUMP_FILES array in tree-dump.c */
end_comment

begin_enum
enum|enum
name|tree_dump_index
block|{
name|TDI_all
block|,
comment|/* dump the whole translation unit */
name|TDI_class
block|,
comment|/* dump class hierarchy */
name|TDI_original
block|,
comment|/* dump each function before optimizing it */
name|TDI_optimized
block|,
comment|/* dump each function after optimizing it */
name|TDI_inlined
block|,
comment|/* dump each function after inlining 				   within it.  */
name|TDI_end
block|}
enum|;
end_enum

begin_comment
comment|/* Bit masks to control tree dumping. Not all values are applicable to    all tree dumps. Add new ones at the end. When you define new    values, extend the DUMP_OPTIONS array in tree-dump.c */
end_comment

begin_define
define|#
directive|define
name|TDF_ADDRESS
value|(1<< 0)
end_define

begin_comment
comment|/* dump node addresses */
end_comment

begin_define
define|#
directive|define
name|TDF_SLIM
value|(1<< 1)
end_define

begin_comment
comment|/* don't go wild following links */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dump_info
modifier|*
name|dump_info_p
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|dump_flag
name|PARAMS
argument_list|(
operator|(
name|dump_info_p
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
name|dump_enabled_p
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_dump_index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|dump_begin
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_dump_index
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
name|dump_end
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_dump_index
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_node
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dump_switch_p
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
specifier|const
name|char
modifier|*
name|dump_flag_name
name|PARAMS
argument_list|(
operator|(
expr|enum
name|tree_dump_index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Redefine abort to report an internal error w/o coredump, and    reporting the location of the error in the source file.  This logic    is duplicated in rtl.h and tree.h because every file that needs the    special abort includes one or both.  toplev.h gets too few files,    system.h gets too many.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fancy_abort
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|abort
parameter_list|()
value|fancy_abort (__FILE__, __LINE__, __FUNCTION__)
end_define

end_unit

