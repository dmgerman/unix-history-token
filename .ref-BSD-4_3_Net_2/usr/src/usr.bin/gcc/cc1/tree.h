begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Front-end tree definitions for GNU compiler.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* codes of tree nodes */
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
comment|/* A convienent way to get a value for 				   NUM_TREE_CODE.  */
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* Number of tree codes.  */
end_comment

begin_define
define|#
directive|define
name|NUM_TREE_CODES
value|((int)LAST_AND_UNUSED_TREE_CODE)
end_define

begin_comment
comment|/* Indexed by enum tree_code, contains a character which is    `e' for an expression, `r' for a reference, `c' for a constant,    `d' for a decl, `t' for a type, `s' for a statement,    and `x' for anything else (TREE_LIST, IDENTIFIER, etc).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tree_code_type
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of argument-words in each kind of tree-node.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tree_code_length
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the definition of `enum machine_mode' */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MACHINE_MODES
end_ifndef

begin_define
define|#
directive|define
name|DEF_MACHMODE
parameter_list|(
name|SYM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|SIZE
parameter_list|,
name|UNIT
parameter_list|,
name|WIDER
parameter_list|)
value|SYM,
end_define

begin_enum
enum|enum
name|machine_mode
block|{
include|#
directive|include
file|"machmode.def"
name|MAX_MACHINE_MODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEF_MACHMODE
end_undef

begin_define
define|#
directive|define
name|HAVE_MACHINE_MODES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_MACHINE_MODES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NUM_MACHINE_MODES
end_ifndef

begin_define
define|#
directive|define
name|NUM_MACHINE_MODES
value|(int) MAX_MACHINE_MODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Codes that identify the various built in functions    so that expand_call can identify them quickly.  */
end_comment

begin_enum
enum|enum
name|built_in_function
block|{
name|NOT_BUILT_IN
block|,
name|BUILT_IN_ALLOCA
block|,
name|BUILT_IN_ABS
block|,
name|BUILT_IN_FABS
block|,
name|BUILT_IN_LABS
block|,
name|BUILT_IN_FFS
block|,
name|BUILT_IN_DIV
block|,
name|BUILT_IN_LDIV
block|,
name|BUILT_IN_FFLOOR
block|,
name|BUILT_IN_FCEIL
block|,
name|BUILT_IN_FMOD
block|,
name|BUILT_IN_FREM
block|,
name|BUILT_IN_MEMCPY
block|,
name|BUILT_IN_MEMCMP
block|,
name|BUILT_IN_MEMSET
block|,
name|BUILT_IN_FSQRT
block|,
name|BUILT_IN_GETEXP
block|,
name|BUILT_IN_GETMAN
block|,
name|BUILT_IN_SAVEREGS
block|,
name|BUILT_IN_CLASSIFY_TYPE
block|,
name|BUILT_IN_NEXT_ARG
block|,
comment|/* C++ extensions */
name|BUILT_IN_NEW
block|,
name|BUILT_IN_VEC_NEW
block|,
name|BUILT_IN_DELETE
block|,
name|BUILT_IN_VEC_DELETE
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
comment|/* This type is used everywhere to refer to a tree node.  */
end_comment

begin_typedef
typedef|typedef
name|union
name|tree_node
modifier|*
name|tree
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULL_TREE
value|(tree) NULL
end_define

begin_comment
comment|/* Every kind of tree node starts with this structure,    so all nodes have these fields.     See the accessor macros, defined below, for documentation of the fields.  */
end_comment

begin_struct
struct|struct
name|tree_common
block|{
name|int
name|uid
decl_stmt|;
name|union
name|tree_node
modifier|*
name|chain
decl_stmt|;
name|union
name|tree_node
modifier|*
name|type
decl_stmt|;
name|unsigned
name|char
name|code
range|:
literal|8
decl_stmt|;
name|unsigned
name|external_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|public_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|static_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|volatile_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|packed_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|readonly_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|literal_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|nonlocal_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|permanent_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|addressable_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|regdecl_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|this_vol_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|unsigned_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|asm_written_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|inline_attr
range|:
literal|1
decl_stmt|;
name|unsigned
name|used_attr
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
comment|/* There is room for four more attributes.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Define accessors for the fields that all tree nodes have    (though some fields are not used for all kinds of nodes).  */
end_comment

begin_comment
comment|/* The unique id of a tree node distinguishes it from all other nodes    in the same compiler run.  */
end_comment

begin_define
define|#
directive|define
name|TREE_UID
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.uid)
end_define

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
value|((NODE)->common.code = (int) (VALUE))
end_define

begin_comment
comment|/* In all nodes that are expressions, this is the data type of the expression.    In POINTER_TYPE nodes, this is the type that the pointer points to.    In ARRAY_TYPE nodes, this is the type of the elements.  */
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

begin_escape
end_escape

begin_comment
comment|/* Define many boolean fields that all tree nodes have.  */
end_comment

begin_comment
comment|/* In a VAR_DECL or FUNCTION_DECL,    nonzero means external reference:    do not allocate storage, and refer to a definition elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|TREE_EXTERNAL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.external_attr)
end_define

begin_comment
comment|/* In a VAR_DECL, nonzero means allocate static storage.    In a FUNCTION_DECL, currently nonzero if function has been defined.  */
end_comment

begin_define
define|#
directive|define
name|TREE_STATIC
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.static_attr)
end_define

begin_comment
comment|/* In a VAR_DECL or FUNCTION_DECL,    nonzero means name is to be accessible from outside this module.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PUBLIC
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.public_attr)
end_define

begin_comment
comment|/* In VAR_DECL nodes, nonzero means address of this is needed.    So it cannot be in a register.    In a FUNCTION_DECL, nonzero means its address is needed.    So it must be compiled even if it is an inline function.    In CONSTRUCTOR nodes, it means the elements are all constants suitable    for output as assembly-language initializers.    In LABEL_DECL nodes, it means a goto for this label has been seen     from a place outside all binding contours that restore stack levels,    or that an error message about jumping into such a binding contour    has been printed for this label.    In ..._TYPE nodes, it means that objects of this type must    be fully addressable.  This means that pieces of this    object cannot go into register parameters, for example.  */
end_comment

begin_define
define|#
directive|define
name|TREE_ADDRESSABLE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.addressable_attr)
end_define

begin_comment
comment|/* In VAR_DECL nodes, nonzero means declared `register'.  */
end_comment

begin_define
define|#
directive|define
name|TREE_REGDECL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.regdecl_attr)
end_define

begin_comment
comment|/* In any expression, nonzero means it has side effects or reevaluation    of the whole expression could produce a different value.    This is set if any subexpression is a function call, a side effect    or a reference to a volatile variable.    In a ..._DECL, this is set only if the declaration said `volatile'.    In a ..._TYPE, nonzero means the type is volatile-qualified.  */
end_comment

begin_define
define|#
directive|define
name|TREE_VOLATILE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.volatile_attr)
end_define

begin_comment
comment|/* Nonzero means this expression is volatile in the C sense:    its address should be of type `volatile WHATEVER *'.    If this bit is set, so is `volatile_attr'.  */
end_comment

begin_define
define|#
directive|define
name|TREE_THIS_VOLATILE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.this_vol_attr)
end_define

begin_comment
comment|/* In a VAR_DECL, PARM_DECL or FIELD_DECL, or any kind of ..._REF node,    nonzero means it may not be the lhs of an assignment.    In a ..._TYPE node, means this type is const-qualified.  */
end_comment

begin_define
define|#
directive|define
name|TREE_READONLY
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.readonly_attr)
end_define

begin_comment
comment|/* Nonzero in a FIELD_DECL means it is a bit-field; it may occupy    less than a storage unit, and its address may not be taken, etc.    This controls layout of the containing record.    In a LABEL_DECL, nonzero means label was defined inside a binding    contour that restored a stack level and which is now exited.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PACKED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.packed_attr)
end_define

begin_comment
comment|/* Value of expression is constant.    Always appears in all ..._CST nodes.    May also appear in an arithmetic expression, an ADDR_EXPR or a CONSTRUCTOR    if the value is constant.  */
end_comment

begin_define
define|#
directive|define
name|TREE_LITERAL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.literal_attr)
end_define

begin_comment
comment|/* Nonzero in a ..._DECL means this variable is ref'd from a nested function.    Cannot happen in C because it does not allow nested functions, as of now.    For VAR_DECL nodes, PARM_DECL nodes, and    maybe FUNCTION_DECL or LABEL_DECL nodes.     Also set in some languages for variables, etc., outside the normal    lexical scope, such as class instance variables.  */
end_comment

begin_define
define|#
directive|define
name|TREE_NONLOCAL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.nonlocal_attr)
end_define

begin_comment
comment|/* Nonzero means permanent node;    node will continue to exist for the entire compiler run.    Otherwise it will be recycled at the end of the function.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PERMANENT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.permanent_attr)
end_define

begin_comment
comment|/* In INTEGER_TYPE or ENUMERAL_TYPE nodes, means an unsigned type.    In FIELD_DECL nodes, means an unsigned bit field.  */
end_comment

begin_define
define|#
directive|define
name|TREE_UNSIGNED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.unsigned_attr)
end_define

begin_comment
comment|/* Nonzero in a VAR_DECL means assembler code has been written.    Nonzero in a FUNCTION_DECL means that the function has been compiled.    This is interesting in an inline function, since it might not need    to be compiled separately.  */
end_comment

begin_define
define|#
directive|define
name|TREE_ASM_WRITTEN
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.asm_written_attr)
end_define

begin_comment
comment|/* Nonzero in a FUNCTION_DECL means this function can be substituted    where it is called.  */
end_comment

begin_define
define|#
directive|define
name|TREE_INLINE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.inline_attr)
end_define

begin_comment
comment|/* Nonzero in a _DECL if the name is used in its scope.  */
end_comment

begin_define
define|#
directive|define
name|TREE_USED
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.used_attr)
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

begin_escape
end_escape

begin_comment
comment|/* Define additional fields and accessors for nodes representing constants.  */
end_comment

begin_comment
comment|/* In an INTEGER_CST node.  These two together make a 64 bit integer.    If the data type is signed, the value is sign-extended to 64 bits    even though not all of them may really be in use.    In an unsigned constant shorter than 64 bits, the extra bits are 0.  */
end_comment

begin_define
define|#
directive|define
name|TREE_INT_CST_LOW
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->int_cst.int_cst_low)
end_define

begin_define
define|#
directive|define
name|TREE_INT_CST_HIGH
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->int_cst.int_cst_high)
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
value|(TREE_INT_CST_HIGH (A)< TREE_INT_CST_HIGH (B)			\  || (TREE_INT_CST_HIGH (A) == TREE_INT_CST_HIGH (B)		\&& ((unsigned) TREE_INT_CST_LOW (A)< (unsigned) TREE_INT_CST_LOW (B))))
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
value|((unsigned) TREE_INT_CST_HIGH (A)< (unsigned) TREE_INT_CST_HIGH (B)	  \  || ((unsigned) TREE_INT_CST_HIGH (A) == (unsigned) TREE_INT_CST_HIGH (B) \&& ((unsigned) TREE_INT_CST_LOW (A)< (unsigned) TREE_INT_CST_LOW (B))))
end_define

begin_struct
struct|struct
name|tree_int_cst
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
name|long
name|int_cst_low
decl_stmt|;
name|long
name|int_cst_high
decl_stmt|;
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
value|((NODE)->real_cst.rtl)
end_define

begin_comment
comment|/* In a REAL_CST node.  */
end_comment

begin_comment
comment|/* We can represent a real value as either a `double' or a string.    Strings don't allow for any optimization, but they do allow    for cross-compilation.  */
end_comment

begin_define
define|#
directive|define
name|TREE_REAL_CST
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->real_cst.real_cst)
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
comment|/* acts as link to register transfer language 				   (rtl) info */
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
value|((NODE)->string.length)
end_define

begin_define
define|#
directive|define
name|TREE_STRING_POINTER
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->string.pointer)
end_define

begin_struct
struct|struct
name|tree_string
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
comment|/* acts as link to register transfer language 				   (rtl) info */
name|int
name|length
decl_stmt|;
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
value|((NODE)->complex.real)
end_define

begin_define
define|#
directive|define
name|TREE_IMAGPART
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->complex.imag)
end_define

begin_struct
struct|struct
name|tree_complex
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
comment|/* acts as link to register transfer language 				   (rtl) info */
name|union
name|tree_node
modifier|*
name|real
decl_stmt|;
name|union
name|tree_node
modifier|*
name|imag
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

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
value|((NODE)->identifier.length)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_POINTER
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->identifier.pointer)
end_define

begin_struct
struct|struct
name|tree_identifier
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
name|int
name|length
decl_stmt|;
name|char
modifier|*
name|pointer
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
value|((NODE)->list.purpose)
end_define

begin_define
define|#
directive|define
name|TREE_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->list.value)
end_define

begin_struct
struct|struct
name|tree_list
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
name|union
name|tree_node
modifier|*
name|purpose
decl_stmt|;
name|union
name|tree_node
modifier|*
name|value
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
name|SAVE_EXPR_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(*(struct rtx_def **)&(NODE)->exp.operands[1])
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
value|(*(struct rtx_def **)&(NODE)->exp.operands[0])
end_define

begin_define
define|#
directive|define
name|RTL_EXPR_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(*(struct rtx_def **)&(NODE)->exp.operands[1])
end_define

begin_comment
comment|/* In a CALL_EXPR node.  */
end_comment

begin_define
define|#
directive|define
name|CALL_EXPR_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(*(struct rtx_def **)&(NODE)->exp.operands[2])
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
value|TREE_OPERAND (NODE, 1)
end_define

begin_comment
comment|/* In expression and reference nodes.  */
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
value|((NODE)->exp.operands[I])
end_define

begin_define
define|#
directive|define
name|TREE_COMPLEXITY
parameter_list|(
name|NODE
parameter_list|,
name|I
parameter_list|)
value|((NODE)->exp.complexity)
end_define

begin_struct
struct|struct
name|tree_exp
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
name|int
name|complexity
decl_stmt|;
name|union
name|tree_node
modifier|*
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
comment|/* Define fields and accessors for nodes representing data types.  */
end_comment

begin_comment
comment|/* See tree.def for documentation of the use of these fields.    Look at the documentation of the various ..._TYPE tree codes.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.size)
end_define

begin_define
define|#
directive|define
name|TYPE_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.size_unit)
end_define

begin_define
define|#
directive|define
name|TYPE_MODE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.mode)
end_define

begin_define
define|#
directive|define
name|TYPE_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.align)
end_define

begin_define
define|#
directive|define
name|TYPE_VALUES
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_DOMAIN
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELDS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_ARG_TYPES
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.values)
end_define

begin_define
define|#
directive|define
name|TYPE_METHOD_BASETYPE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.max)
end_define

begin_define
define|#
directive|define
name|TYPE_OFFSET_BASETYPE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.max)
end_define

begin_define
define|#
directive|define
name|TYPE_SEP
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.sep)
end_define

begin_define
define|#
directive|define
name|TYPE_SEP_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.sep_unit)
end_define

begin_define
define|#
directive|define
name|TYPE_POINTER_TO
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.pointer_to)
end_define

begin_define
define|#
directive|define
name|TYPE_REFERENCE_TO
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.reference_to)
end_define

begin_define
define|#
directive|define
name|TYPE_MIN_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.sep)
end_define

begin_define
define|#
directive|define
name|TYPE_MAX_VALUE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.max)
end_define

begin_define
define|#
directive|define
name|TYPE_PRECISION
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.sep_unit)
end_define

begin_define
define|#
directive|define
name|TYPE_PARSE_INFO
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.parse_info)
end_define

begin_define
define|#
directive|define
name|TYPE_SYMTAB_ADDRESS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.symtab_address)
end_define

begin_define
define|#
directive|define
name|TYPE_NAME
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.name)
end_define

begin_define
define|#
directive|define
name|TYPE_NEXT_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.next_variant)
end_define

begin_define
define|#
directive|define
name|TYPE_MAIN_VARIANT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.main_variant)
end_define

begin_define
define|#
directive|define
name|TYPE_BASETYPES
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.basetypes)
end_define

begin_define
define|#
directive|define
name|TYPE_NONCOPIED_PARTS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.noncopied_parts)
end_define

begin_define
define|#
directive|define
name|TYPE_LANG_SPECIFIC
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->type.lang_specific)
end_define

begin_struct
struct|struct
name|tree_type
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
name|union
name|tree_node
modifier|*
name|values
decl_stmt|;
name|union
name|tree_node
modifier|*
name|sep
decl_stmt|;
name|union
name|tree_node
modifier|*
name|size
decl_stmt|;
name|enum
name|machine_mode
name|mode
range|:
literal|8
decl_stmt|;
name|unsigned
name|char
name|size_unit
decl_stmt|;
name|unsigned
name|char
name|align
decl_stmt|;
name|unsigned
name|char
name|sep_unit
decl_stmt|;
name|union
name|tree_node
modifier|*
name|pointer_to
decl_stmt|;
name|union
name|tree_node
modifier|*
name|reference_to
decl_stmt|;
name|int
name|parse_info
decl_stmt|;
name|int
name|symtab_address
decl_stmt|;
name|union
name|tree_node
modifier|*
name|name
decl_stmt|;
name|union
name|tree_node
modifier|*
name|max
decl_stmt|;
name|union
name|tree_node
modifier|*
name|next_variant
decl_stmt|;
name|union
name|tree_node
modifier|*
name|main_variant
decl_stmt|;
name|union
name|tree_node
modifier|*
name|basetypes
decl_stmt|;
name|union
name|tree_node
modifier|*
name|noncopied_parts
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

begin_comment
comment|/* Define fields and accessors for nodes representing declared names.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VOFFSET
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.voffset)
end_define

begin_comment
comment|/* In FIELD_DECLs and maybe PARM_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RESULT_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.voffset)
end_define

begin_comment
comment|/* In FUNCTION_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|DECL_VOFFSET_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.voffset_unit)
end_define

begin_define
define|#
directive|define
name|DECL_OFFSET
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.offset)
end_define

begin_define
define|#
directive|define
name|DECL_FUNCTION_CODE
parameter_list|(
name|NODE
parameter_list|)
value|((enum built_in_function) (NODE)->decl.offset)
end_define

begin_define
define|#
directive|define
name|DECL_SET_FUNCTION_CODE
parameter_list|(
name|NODE
parameter_list|,
name|VAL
parameter_list|)
value|((NODE)->decl.offset = (int) (VAL))
end_define

begin_define
define|#
directive|define
name|DECL_NAME
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.name)
end_define

begin_define
define|#
directive|define
name|DECL_PRINT_NAME
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.print_name)
end_define

begin_define
define|#
directive|define
name|DECL_ASSEMBLER_NAME
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.assembler_name)
end_define

begin_define
define|#
directive|define
name|DECL_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.context)
end_define

begin_define
define|#
directive|define
name|DECL_FIELD_CONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.context)
end_define

begin_define
define|#
directive|define
name|DECL_ARGUMENTS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.arguments)
end_define

begin_comment
comment|/* In FUNCTION_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ARG_TYPE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.arguments)
end_define

begin_comment
comment|/* In PARM_DECL.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RESULT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.result)
end_define

begin_define
define|#
directive|define
name|DECL_INITIAL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.initial)
end_define

begin_define
define|#
directive|define
name|DECL_SOURCE_FILE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.filename)
end_define

begin_define
define|#
directive|define
name|DECL_SOURCE_LINE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.linenum)
end_define

begin_define
define|#
directive|define
name|DECL_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.size)
end_define

begin_define
define|#
directive|define
name|DECL_SIZE_UNIT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.size_unit)
end_define

begin_define
define|#
directive|define
name|DECL_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.align)
end_define

begin_define
define|#
directive|define
name|DECL_MODE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.mode)
end_define

begin_define
define|#
directive|define
name|DECL_RTL
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.rtl)
end_define

begin_define
define|#
directive|define
name|DECL_BLOCK_SYMTAB_ADDRESS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.block_symtab_address)
end_define

begin_define
define|#
directive|define
name|DECL_SYMTAB_INDEX
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.block_symtab_address)
end_define

begin_define
define|#
directive|define
name|DECL_SAVED_INSNS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.saved_insns)
end_define

begin_define
define|#
directive|define
name|DECL_FRAME_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.frame_size)
end_define

begin_define
define|#
directive|define
name|DECL_LANG_SPECIFIC
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.lang_specific)
end_define

begin_struct
struct|struct
name|tree_decl
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
name|union
name|tree_node
modifier|*
name|size
decl_stmt|;
name|enum
name|machine_mode
name|mode
range|:
literal|8
decl_stmt|;
name|unsigned
name|char
name|size_unit
decl_stmt|;
name|unsigned
name|char
name|align
decl_stmt|;
name|unsigned
name|char
name|voffset_unit
decl_stmt|;
name|union
name|tree_node
modifier|*
name|name
decl_stmt|;
name|union
name|tree_node
modifier|*
name|context
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|union
name|tree_node
modifier|*
name|voffset
decl_stmt|;
name|union
name|tree_node
modifier|*
name|arguments
decl_stmt|;
name|union
name|tree_node
modifier|*
name|result
decl_stmt|;
name|union
name|tree_node
modifier|*
name|initial
decl_stmt|;
name|char
modifier|*
name|print_name
decl_stmt|;
name|char
modifier|*
name|assembler_name
decl_stmt|;
name|struct
name|rtx_def
modifier|*
name|rtl
decl_stmt|;
comment|/* acts as link to register transfer language 				   (rtl) info */
name|int
name|frame_size
decl_stmt|;
comment|/* For FUNCTION_DECLs: size of stack frame */
name|struct
name|rtx_def
modifier|*
name|saved_insns
decl_stmt|;
comment|/* For FUNCTION_DECLs: points to insn that 				   constitutes its definition on the 				   permanent obstack.  */
name|int
name|block_symtab_address
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
comment|/* Define fields and accessors for nodes representing statements.    These are now obsolete for C, except for LET_STMT, which is used    to record the structure of binding contours (and the names declared    in each contour) for the sake of outputting debugging info.    Perhaps they will be used once again for other languages.  */
end_comment

begin_comment
comment|/* For LABEL_STMT, GOTO_STMT, RETURN_STMT, LOOP_STMT,    COMPOUND_STMT, ASM_STMT.  */
end_comment

begin_define
define|#
directive|define
name|STMT_SOURCE_LINE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->stmt.linenum)
end_define

begin_define
define|#
directive|define
name|STMT_SOURCE_FILE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->stmt.filename)
end_define

begin_define
define|#
directive|define
name|STMT_BODY
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->stmt.body)
end_define

begin_struct
struct|struct
name|tree_stmt
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
name|union
name|tree_node
modifier|*
name|body
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For IF_STMT.  */
end_comment

begin_comment
comment|/* #define STMT_SOURCE_LINE(NODE) */
end_comment

begin_comment
comment|/* #define STMT_SOURCE_FILE(NODE) */
end_comment

begin_define
define|#
directive|define
name|STMT_COND
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->if_stmt.cond)
end_define

begin_define
define|#
directive|define
name|STMT_THEN
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->if_stmt.thenpart)
end_define

begin_define
define|#
directive|define
name|STMT_ELSE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->if_stmt.elsepart)
end_define

begin_struct
struct|struct
name|tree_if_stmt
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
name|union
name|tree_node
modifier|*
name|cond
decl_stmt|,
modifier|*
name|thenpart
decl_stmt|,
modifier|*
name|elsepart
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For LET_STMT and WITH_STMT.  */
end_comment

begin_comment
comment|/* #define STMT_SOURCE_LINE(NODE) */
end_comment

begin_comment
comment|/* #define STMT_SOURCE_FILE(NODE) */
end_comment

begin_comment
comment|/* #define STMT_BODY(NODE) */
end_comment

begin_define
define|#
directive|define
name|STMT_VARS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->bind_stmt.vars)
end_define

begin_define
define|#
directive|define
name|STMT_SUPERCONTEXT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->bind_stmt.supercontext)
end_define

begin_define
define|#
directive|define
name|STMT_BIND_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->bind_stmt.bind_size)
end_define

begin_define
define|#
directive|define
name|STMT_TYPE_TAGS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->bind_stmt.type_tags)
end_define

begin_define
define|#
directive|define
name|STMT_SUBBLOCKS
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->bind_stmt.subblocks)
end_define

begin_struct
struct|struct
name|tree_bind_stmt
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
name|union
name|tree_node
modifier|*
name|body
decl_stmt|,
modifier|*
name|vars
decl_stmt|,
modifier|*
name|supercontext
decl_stmt|,
modifier|*
name|bind_size
decl_stmt|,
modifier|*
name|type_tags
decl_stmt|;
name|union
name|tree_node
modifier|*
name|subblocks
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For CASE_STMT.  */
end_comment

begin_define
define|#
directive|define
name|STMT_CASE_INDEX
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->case_stmt.index)
end_define

begin_define
define|#
directive|define
name|STMT_CASE_LIST
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->case_stmt.case_list)
end_define

begin_struct
struct|struct
name|tree_case_stmt
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
name|union
name|tree_node
modifier|*
name|index
decl_stmt|,
modifier|*
name|case_list
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
name|tree_exp
name|exp
decl_stmt|;
name|struct
name|tree_stmt
name|stmt
decl_stmt|;
name|struct
name|tree_if_stmt
name|if_stmt
decl_stmt|;
name|struct
name|tree_bind_stmt
name|bind_stmt
decl_stmt|;
name|struct
name|tree_case_stmt
name|case_stmt
decl_stmt|;
block|}
union|;
end_union

begin_escape
end_escape

begin_function_decl
specifier|extern
name|char
modifier|*
name|oballoc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|permalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Lowest level primitive for allocating a node.    The TREE_CODE is the only argument.  Contents are initialized    to zero except for a few of the common fields.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|make_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make a copy of a node, with all the same contents except    for TREE_UID and TREE_PERMANENT.  (The copy is permanent    iff nodes being made now are permanent.)  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|copy_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make a copy of a chain of TREE_LIST nodes.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|copy_list
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the (unique) IDENTIFIER_NODE node for a given name.    The name is supplied as a char *.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_identifier
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Construct various types of nodes.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_int_2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_real
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_real_from_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_real_from_int_cst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_complex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_nt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_tree_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_op_identifier
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_decl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_let
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Construct various nodes representing data types.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|make_signed_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|make_unsigned_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fixup_unsigned_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_pointer_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_reference_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_index_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_array_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_function_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_method_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_offset_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|array_type_nelts
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Construct expressions, performing type checking.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_binary_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_indirect_ref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_unary_op
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Given a type node TYPE, and CONSTP and VOLATILEP, return a type    for the same kind of data as TYPE describes.    Variants point to the "main variant" (which has neither CONST nor VOLATILE)    via TYPE_MAIN_VARIANT, and it points to a chain of other variants    so that duplicate variants are never made.    Only main variants should ever appear as types of expressions.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|build_type_variant
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given a ..._TYPE node, calculate the TYPE_SIZE, TYPE_SIZE_UNIT,    TYPE_ALIGN and TYPE_MODE fields.    If called more than once on one node, does nothing except    for the first time.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|layout_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given a hashcode and a ..._TYPE node (for which the hashcode was made),    return a canonicalized ..._TYPE node, so that duplicates are not made.    How the hash code is computed is up to the caller, as long as any two    callers that could hash identical-looking type nodes agree.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|type_hash_canon
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given a VAR_DECL, PARM_DECL, RESULT_DECL or FIELD_DECL node,    calculates the DECL_SIZE, DECL_SIZE_UNIT, DECL_ALIGN and DECL_MODE    fields.  Call this only once for any given decl node.     Second argument is the boundary that this field can be assumed to    be starting at (in bits).  Zero means it can be assumed aligned    on any boundary that may be needed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|layout_decl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Fold constants as much as possible in an expression.    Returns the simplified expression.    Acts only on the top level of the expression;    if the argument itself cannot be simplified, its    subexpressions are not changed.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|fold
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* combine (tree_code, exp1, exp2) where EXP1 and EXP2 are constants    returns a constant expression for the result of performing    the operation specified by TREE_CODE on EXP1 and EXP2.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|combine
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|convert_units
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|size_in_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|genop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|build_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|get_pending_sizes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Type for sizes of data-type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|sizetype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Concatenate two lists (chains of TREE_LIST nodes) X and Y    by making the last node in X point to Y.    Returns X, except if X is 0 returns Y.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|chainon
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make a new TREE_LIST node from specified PURPOSE, VALUE and CHAIN.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|tree_cons
argument_list|()
decl_stmt|,
name|perm_tree_cons
argument_list|()
decl_stmt|,
name|temp_tree_cons
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tree
name|saveable_tree_cons
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the last tree node in a chain.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|tree_last
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Reverse the order of elements in a chain, and return the new head.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|nreverse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the length of a chain of nodes    (number of chain pointers to follow before reaching a null pointer).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|list_length
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* integer_zerop (tree x) is nonzero if X is an integer constant of value 0 */
end_comment

begin_function_decl
specifier|extern
name|int
name|integer_zerop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* integer_onep (tree x) is nonzero if X is an integer constant of value 1 */
end_comment

begin_function_decl
specifier|extern
name|int
name|integer_onep
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* integer_all_onesp (tree x) is nonzero if X is an integer constant    all of whose significant bits are 1.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|integer_all_onesp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* type_unsigned_p (tree x) is nonzero if the type X is an unsigned type    (all of its possible values are>= 0).    If X is a pointer type, the value is 1.    If X is a real type, the value is 0.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|type_unsigned_p
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* staticp (tree x) is nonzero if X is a reference to data allocated    at a fixed address in memory.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|staticp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Gets an error if argument X is not an lvalue.    Also returns 1 if X is an lvalue, 0 if not.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|lvalue_or_else
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* save_expr (EXP) returns an expression equivalent to EXP    but it can be used multiple times within context CTX    and only evaluate EXP once.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|save_expr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* stabilize_reference (EXP) returns an reference equivalent to EXP    but it can be used multiple times    and only evaluate the subexpressions once.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|stabilize_reference
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return EXP, stripped of any conversions to wider types    in such a way that the result of converting to type FOR_TYPE    is the same as if EXP were converted to FOR_TYPE.    If FOR_TYPE is 0, it signifies EXP's type.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_unwidened
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return OP or a simpler expression for a narrower value    which can be sign-extended or zero-extended to give back OP.    Store in *UNSIGNEDP_PTR either 1 if the value should be zero-extended    or 0 if the value should be sign-extended.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_narrower
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given PRECISION and UNSIGNEDP, return a suitable type-tree    for an integer type with at least that precision.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|type_for_size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given an integer type T, return a type like T but unsigned.    If T is unsigned, the value is T.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|unsigned_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given an integer type T, return a type like T but signed.    If T is signed, the value is T.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|signed_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the floating type node for a given floating machine mode.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|get_floating_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given the FUNCTION_DECL for the current function,    return zero if it is ok for this function to be inline.    Otherwise return a warning message with a single %s    for the function's name.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|function_cannot_inline_p
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Declare commonly used variables for tree structure.  */
end_comment

begin_comment
comment|/* An integer constant with value 0 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|integer_zero_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An integer constant with value 1 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|integer_one_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An integer constant with value 0 whose type is sizetype.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|size_zero_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An integer constant with value 1 whose type is sizetype.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|size_one_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A constant of type pointer-to-int and value 0 */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|null_pointer_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A node of type ERROR_MARK.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|error_mark_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The type node for the void type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|void_type_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The type node for the ordinary (signed) integer type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|integer_type_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The type node for the unsigned integer type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|unsigned_type_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The type node for the ordinary character type.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|char_type_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to the name of the input file from which the current input    being parsed originally came (before it went into cpp).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current source line number in that file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -pedantic switch: warn about anything    that standard C forbids.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pedantic
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
comment|/* Points to the FUNCTION_DECL of the function whose body we are reading. */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|current_function_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call setjmp.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_setjmp
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

begin_escape
end_escape

begin_comment
comment|/* In stmt.c */
end_comment

begin_function_decl
specifier|extern
name|tree
name|expand_start_stmt_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|expand_end_stmt_expr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|expand_expr_stmt
argument_list|()
decl_stmt|,
name|clear_last_expr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_label
argument_list|()
decl_stmt|,
name|expand_goto
argument_list|()
decl_stmt|,
name|expand_asm
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_start_cond
argument_list|()
decl_stmt|,
name|expand_end_cond
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_start_else
argument_list|()
decl_stmt|,
name|expand_end_else
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_start_loop
argument_list|()
decl_stmt|,
name|expand_start_loop_continue_elsewhere
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|expand_loop_continue_here
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_end_loop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|expand_continue_loop
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|expand_exit_loop
argument_list|()
decl_stmt|,
name|expand_exit_loop_if_false
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|expand_exit_something
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_start_delayed_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|expand_end_delayed_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_emit_delayed_expr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|expand_null_return
argument_list|()
decl_stmt|,
name|expand_return
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_start_bindings
argument_list|()
decl_stmt|,
name|expand_end_bindings
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_start_case
argument_list|()
decl_stmt|,
name|expand_end_case
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pushcase
argument_list|()
decl_stmt|,
name|pushcase_range
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_start_function
argument_list|()
decl_stmt|,
name|expand_end_function
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

