begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Front-end tree definitions for GNU compiler.    Copyright (C) 1989, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"machmode.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|RTX_CODE
end_ifndef

begin_struct_decl
struct_decl|struct
name|rtx_def
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Number of tree codes.  */
end_comment

begin_define
define|#
directive|define
name|NUM_TREE_CODES
value|((int)LAST_AND_UNUSED_TREE_CODE)
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
value|(CLASS == '<' || CLASS == '1' || CLASS == '2' || CLASS == 'e')
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

begin_comment
comment|/* Names of tree components.  */
end_comment

begin_decl_stmt
specifier|extern
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
name|BUILT_IN_STRCPY
block|,
name|BUILT_IN_STRCMP
block|,
name|BUILT_IN_STRLEN
block|,
name|BUILT_IN_FSQRT
block|,
name|BUILT_IN_SIN
block|,
name|BUILT_IN_COS
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
name|BUILT_IN_ARGS_INFO
block|,
name|BUILT_IN_CONSTANT_P
block|,
name|BUILT_IN_FRAME_ADDRESS
block|,
name|BUILT_IN_RETURN_ADDRESS
block|,
name|BUILT_IN_AGGREGATE_INCOMING_ADDRESS
block|,
name|BUILT_IN_APPLY_ARGS
block|,
name|BUILT_IN_APPLY
block|,
name|BUILT_IN_RETURN
block|,
name|BUILT_IN_SETJMP
block|,
name|BUILT_IN_LONGJMP
block|,
name|BUILT_IN_TRAP
block|,
comment|/* Various hooks for the DWARF 2 __throw routine.  */
name|BUILT_IN_UNWIND_INIT
block|,
name|BUILT_IN_DWARF_CFA
block|,
name|BUILT_IN_DWARF_FP_REGNUM
block|,
name|BUILT_IN_DWARF_REG_SIZE
block|,
name|BUILT_IN_FROB_RETURN_ADDR
block|,
name|BUILT_IN_EXTRACT_RETURN_ADDR
block|,
name|BUILT_IN_EH_RETURN
block|,
comment|/* C++ extensions */
name|BUILT_IN_NEW
block|,
name|BUILT_IN_VEC_NEW
block|,
name|BUILT_IN_DELETE
block|,
name|BUILT_IN_VEC_DELETE
block|,
comment|/* Upper bound on non-language-specific builtins. */
name|END_BUILTINS
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

begin_comment
comment|/* Every kind of tree node starts with this structure,    so all nodes have these fields.     See the accessor macros, defined below, for documentation of the fields.      DO NOT change the layout of tree_common unless absolutely necessary.  Some    front-ends (namely g++) depend on the internal layout of this tructure.    See my_tree_cons in the cp subdir for such uglyness.  Ugh.  */
end_comment

begin_struct
struct|struct
name|tree_common
block|{
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
ifdef|#
directive|ifdef
name|ONLY_INT_FIELDS
name|unsigned
name|int
name|code
range|:
literal|8
decl_stmt|;
else|#
directive|else
name|enum
name|tree_code
name|code
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
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
name|permanent_flag
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
name|raises_flag
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
comment|/* There is room for three more flags.  */
block|}
struct|;
end_struct

begin_comment
comment|/* The following table lists the uses of each of the above flags and    for which types of nodes they are defined.  Note that expressions    include decls.     addressable_flag:         TREE_ADDRESSABLE in    	   VAR_DECL, FUNCTION_DECL, CONSTRUCTOR, LABEL_DECL, ..._TYPE 	   IDENTIFIER_NODE     static_flag:         TREE_STATIC in            VAR_DECL, FUNCTION_DECL, CONSTRUCTOR, ADDR_EXPR        TREE_NO_UNUSED_WARNING in            CONVERT_EXPR, NOP_EXPR, COMPOUND_EXPR        TREE_VIA_VIRTUAL in            TREE_LIST or TREE_VEC        TREE_CONSTANT_OVERFLOW in            INTEGER_CST, REAL_CST, COMPLEX_CST        TREE_SYMBOL_REFERENCED in            IDENTIFIER_NODE     public_flag:         TREE_OVERFLOW in            INTEGER_CST, REAL_CST, COMPLEX_CST        TREE_PUBLIC in            VAR_DECL or FUNCTION_DECL        TREE_VIA_PUBLIC in            TREE_LIST or TREE_VEC        EXPR_WFL_EMIT_LINE_NOTE in            EXPR_WITH_FILE_LOCATION     private_flag:         TREE_VIA_PRIVATE in            TREE_LIST or TREE_VEC        TREE_PRIVATE in            ??? unspecified nodes     protected_flag:         TREE_VIA_PROTECTED in            TREE_LIST        TREE_PROTECTED in            BLOCK 	   ??? unspecified nodes     side_effects_flag:         TREE_SIDE_EFFECTS in            all expressions     volatile_flag:         TREE_THIS_VOLATILE in            all expressions        TYPE_VOLATILE in            ..._TYPE     readonly_flag:         TREE_READONLY in            all expressions        ITERATOR_BOUND_P in            VAR_DECL if iterator (C)        TYPE_READONLY in            ..._TYPE     constant_flag:         TREE_CONSTANT in            all expressions     permanent_flag: TREE_PERMANENT in all nodes     unsigned_flag:         TREE_UNSIGNED in            INTEGER_TYPE, ENUMERAL_TYPE, FIELD_DECL        DECL_BUILT_IN_NONANSI in            FUNCTION_DECL        TREE_PARMLIST in            TREE_PARMLIST (C++)        SAVE_EXPR_NOPLACEHOLDER in 	   SAVE_EXPR     asm_written_flag:         TREE_ASM_WRITTEN in            VAR_DECL, FUNCTION_DECL, RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE 	   BLOCK     used_flag:         TREE_USED in            expressions, IDENTIFIER_NODE     raises_flag:         TREE_RAISES in            expressions  							  */
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
value|((NODE)->common.code = (int) (VALUE))
end_define

begin_comment
comment|/* When checking is enabled, errors will be generated if a tree node    is accessed incorrectly. The macros abort with a fatal error,    except for the *1 variants, which just return 0 on failure.  The    latter variants should only be used for combination checks, which    succeed when one of the checks succeed. The CHAIN_CHECK macro helps    defining such checks.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
end_ifdef

begin_define
define|#
directive|define
name|DO_CHECK
parameter_list|(
name|FUNC
parameter_list|,
name|t
parameter_list|,
name|param
parameter_list|)
value|FUNC (t, param, __FILE__, __LINE__, 0)
end_define

begin_define
define|#
directive|define
name|DO_CHECK1
parameter_list|(
name|FUNC
parameter_list|,
name|t
parameter_list|,
name|param
parameter_list|)
value|FUNC (t, param, __FILE__, __LINE__, 1)
end_define

begin_define
define|#
directive|define
name|CHAIN_CHECK
parameter_list|(
name|t
parameter_list|,
name|c1
parameter_list|,
name|c2
parameter_list|)
value|(c1 (t) ? t : c2 (t))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DO_CHECK
parameter_list|(
name|FUNC
parameter_list|,
name|t
parameter_list|,
name|param
parameter_list|)
value|(t)
end_define

begin_define
define|#
directive|define
name|DO_CHECK1
parameter_list|(
name|FUNC
parameter_list|,
name|t
parameter_list|,
name|param
parameter_list|)
value|(t)
end_define

begin_define
define|#
directive|define
name|CHAIN_CHECK
parameter_list|(
name|t
parameter_list|,
name|c1
parameter_list|,
name|c2
parameter_list|)
value|(t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TREE_CHECK
parameter_list|(
name|t
parameter_list|,
name|code
parameter_list|)
value|DO_CHECK (tree_check, t, code)
end_define

begin_define
define|#
directive|define
name|TREE_CHECK1
parameter_list|(
name|t
parameter_list|,
name|code
parameter_list|)
value|DO_CHECK1 (tree_check, t, code)
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
name|tree
parameter_list|)
value|DO_CHECK (tree_class_check, tree, 't')
end_define

begin_define
define|#
directive|define
name|TYPE_CHECK1
parameter_list|(
name|tree
parameter_list|)
value|DO_CHECK1 (tree_class_check, tree, 't')
end_define

begin_define
define|#
directive|define
name|DECL_CHECK
parameter_list|(
name|t
parameter_list|)
value|DO_CHECK (tree_class_check, t, 'd')
end_define

begin_define
define|#
directive|define
name|DECL_CHECK1
parameter_list|(
name|t
parameter_list|)
value|DO_CHECK1 (tree_class_check, t, 'd')
end_define

begin_define
define|#
directive|define
name|CST_CHECK
parameter_list|(
name|t
parameter_list|)
value|DO_CHECK (tree_class_check, t, 'c')
end_define

begin_define
define|#
directive|define
name|CST_CHECK1
parameter_list|(
name|t
parameter_list|)
value|DO_CHECK1 (tree_class_check, t, 'c')
end_define

begin_define
define|#
directive|define
name|EXPR_CHECK
parameter_list|(
name|t
parameter_list|)
value|DO_CHECK (expr_check, t, 0)
end_define

begin_comment
comment|/* Chained checks. The last check has to succeed, the others may fail. */
end_comment

begin_define
define|#
directive|define
name|CST_OR_CONSTRUCTOR_CHECK
parameter_list|(
name|t
parameter_list|)
define|\
value|CHAIN_CHECK (t, CST_CHECK1, CONSTRUCTOR_CHECK)
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
value|while ((TREE_CODE (EXP) == NOP_EXPR				\ 	  || TREE_CODE (EXP) == CONVERT_EXPR			\ 	  || TREE_CODE (EXP) == NON_LVALUE_EXPR)		\&& (TYPE_MODE (TREE_TYPE (EXP))			\ 	     == TYPE_MODE (TREE_TYPE (TREE_OPERAND (EXP, 0)))))	\     (EXP) = TREE_OPERAND (EXP, 0);
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
value|while ((TREE_CODE (EXP) == NOP_EXPR				\ 	  || TREE_CODE (EXP) == CONVERT_EXPR			\ 	  || TREE_CODE (EXP) == NON_LVALUE_EXPR)		\&& (TREE_TYPE (EXP)					\ 	     == TREE_TYPE (TREE_OPERAND (EXP, 0))))		\     (EXP) = TREE_OPERAND (EXP, 0);
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
comment|/* Nonzero if TYPE represents an aggregate (multi-component) type. */
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
comment|/* Nonzero if TYPE represents a pointer type.  */
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
comment|/* In VAR_DECL nodes, nonzero means address of this is needed.    So it cannot be in a register.    In a FUNCTION_DECL, nonzero means its address is needed.    So it must be compiled even if it is an inline function.    In CONSTRUCTOR nodes, it means object constructed must be in memory.    In LABEL_DECL nodes, it means a goto for this label has been seen     from a place outside all binding contours that restore stack levels.    In ..._TYPE nodes, it means that objects of this type must    be fully addressable.  This means that pieces of this    object cannot go into register parameters, for example.    In IDENTIFIER_NODEs, this means that some extern decl for this name    had its address taken.  That matters for inline functions.  */
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
value|((NODE)->common.static_flag)
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
comment|/* In a VAR_DECL or FUNCTION_DECL,    nonzero means name is to be accessible from outside this module.    In an identifier node, nonzero means an external declaration    accessible from outside this module was previously seen    for this name in an inner scope.  */
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
comment|/* Nonzero for TREE_LIST node means that the path to the    base class is via a `protected' declaration, which preserves    protected fields from the base class as protected.    OVERLOADED.  */
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
comment|/* Nonzero means permanent node;    node will continue to exist for the entire compiler run.    Otherwise it will be recycled at the end of the function.  */
end_comment

begin_define
define|#
directive|define
name|TREE_PERMANENT
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.permanent_flag)
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
comment|/* Nonzero for a tree node whose evaluation could result    in the raising of an exception.  Not implemented yet.  */
end_comment

begin_define
define|#
directive|define
name|TREE_RAISES
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.raises_flag)
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
name|TREE_INT_CST_LOW
parameter_list|(
name|NODE
parameter_list|)
value|(INTEGER_CST_CHECK (NODE)->int_cst.int_cst_low)
end_define

begin_define
define|#
directive|define
name|TREE_INT_CST_HIGH
parameter_list|(
name|NODE
parameter_list|)
value|(INTEGER_CST_CHECK (NODE)->int_cst.int_cst_high)
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
value|(TREE_INT_CST_HIGH (A)< TREE_INT_CST_HIGH (B)			\  || (TREE_INT_CST_HIGH (A) == TREE_INT_CST_HIGH (B)		\&& ((unsigned HOST_WIDE_INT) TREE_INT_CST_LOW (A)		\< (unsigned HOST_WIDE_INT) TREE_INT_CST_LOW (B))))
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
value|(((unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (A)	\< (unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (B))	\  || (((unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (A)	\       == (unsigned HOST_WIDE_INT ) TREE_INT_CST_HIGH (B)) \&& (((unsigned HOST_WIDE_INT) TREE_INT_CST_LOW (A)	\< (unsigned HOST_WIDE_INT) TREE_INT_CST_LOW (B)))))
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
name|struct
name|rtx_def
modifier|*
name|rtl
decl_stmt|;
comment|/* acts as link to register transfer language 			   (rtl) info */
name|HOST_WIDE_INT
name|int_cst_low
decl_stmt|;
name|HOST_WIDE_INT
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
value|(CST_OR_CONSTRUCTOR_CHECK (NODE)->real_cst.rtl)
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
value|(IDENTIFIER_NODE_CHECK (NODE)->identifier.length)
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_POINTER
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_NODE_CHECK (NODE)->identifier.pointer)
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
value|((void) TREE_VEC_CHECK (NODE),&((NODE)->vec.a[(NODE)->vec.length]))
end_define

begin_struct
struct|struct
name|tree_vec
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
name|union
name|tree_node
modifier|*
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
value|TREE_OPERAND(NODE, 1)
end_define

begin_define
define|#
directive|define
name|SAVE_EXPR_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(*(struct rtx_def **)&EXPR_CHECK (NODE)->exp.operands[2])
end_define

begin_define
define|#
directive|define
name|SAVE_EXPR_NOPLACEHOLDER
parameter_list|(
name|NODE
parameter_list|)
value|TREE_UNSIGNED (NODE)
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
value|(*(struct rtx_def **)&EXPR_CHECK (NODE)->exp.operands[0])
end_define

begin_define
define|#
directive|define
name|RTL_EXPR_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(*(struct rtx_def **)&EXPR_CHECK (NODE)->exp.operands[1])
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
value|(*(struct rtx_def **)&EXPR_CHECK (NODE)->exp.operands[2])
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
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|LABELED_BLOCK_BODY
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
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
value|TREE_OPERAND (NODE, 0)
end_define

begin_define
define|#
directive|define
name|EXIT_BLOCK_RETURN
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND (NODE, 1)
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
value|TREE_OPERAND (NODE, 0)
end_define

begin_comment
comment|/* In a EXPR_WITH_FILE_LOCATION node.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_WFL_NODE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_OPERAND((NODE), 0)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_FILENAME
parameter_list|(
name|NODE
parameter_list|)
value|(IDENTIFIER_POINTER ((NODE)->common.chain))
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_FILENAME_NODE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.chain)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_LINENO
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_CHECK (NODE)->exp.complexity>> 12)
end_define

begin_define
define|#
directive|define
name|EXPR_WFL_COLNO
parameter_list|(
name|NODE
parameter_list|)
value|(EXPR_CHECK (NODE)->exp.complexity& 0xfff)
end_define

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

begin_define
define|#
directive|define
name|EXPR_WFL_EMIT_LINE_NOTE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.public_flag)
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
name|BLOCK_TYPE_TAGS
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.type_tags)
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
value|TREE_CHAIN (NODE)
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

begin_define
define|#
directive|define
name|BLOCK_END_NOTE
parameter_list|(
name|NODE
parameter_list|)
value|(BLOCK_CHECK (NODE)->block.end_note)
end_define

begin_comment
comment|/* Nonzero means that this block has separate live range regions */
end_comment

begin_define
define|#
directive|define
name|BLOCK_LIVE_RANGE_FLAG
parameter_list|(
name|NOTE
parameter_list|)
value|(BLOCK_CHECK (NOTE)->block.live_range_flag)
end_define

begin_comment
comment|/* Nonzero means that this block has a variable declared in it    that is split into separate live ranges.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_LIVE_RANGE_VAR_FLAG
parameter_list|(
name|NOTE
parameter_list|)
value|(BLOCK_CHECK (NOTE)->block.live_range_var_flag)
end_define

begin_comment
comment|/* Index for marking the start of the block for live ranges.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_LIVE_RANGE_START
parameter_list|(
name|NOTE
parameter_list|)
value|(BLOCK_CHECK (NOTE)->block.live_range_start)
end_define

begin_comment
comment|/* Index for marking the end of the block for live ranges.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_LIVE_RANGE_END
parameter_list|(
name|NOTE
parameter_list|)
value|(BLOCK_CHECK (NOTE)->block.live_range_end)
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
value|(BLOCK_CHECK (NODE)->block.handler_block_flag)
end_define

begin_struct
struct|struct
name|tree_block
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
name|live_range_flag
range|:
literal|1
decl_stmt|;
name|unsigned
name|live_range_var_flag
range|:
literal|1
decl_stmt|;
name|union
name|tree_node
modifier|*
name|vars
decl_stmt|;
name|union
name|tree_node
modifier|*
name|type_tags
decl_stmt|;
name|union
name|tree_node
modifier|*
name|subblocks
decl_stmt|;
name|union
name|tree_node
modifier|*
name|supercontext
decl_stmt|;
name|union
name|tree_node
modifier|*
name|abstract_origin
decl_stmt|;
name|struct
name|rtx_def
modifier|*
name|end_note
decl_stmt|;
name|int
name|live_range_start
decl_stmt|;
name|int
name|live_range_end
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
name|TYPE_NONCOPIED_PARTS
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.noncopied_parts)
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
name|TYPE_OBSTACK
parameter_list|(
name|NODE
parameter_list|)
value|(TYPE_CHECK (NODE)->type.obstack)
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
define|\
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

begin_define
define|#
directive|define
name|TYPE_STUB_DECL
parameter_list|(
name|NODE
parameter_list|)
value|(TREE_CHAIN (NODE))
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
comment|/* Nonzero in a type considered volatile as a whole.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_VOLATILE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->common.volatile_flag)
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
value|((NODE)->common.readonly_flag)
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
value|((TYPE_READONLY(NODE) * TYPE_QUAL_CONST) |	\    (TYPE_VOLATILE(NODE) * TYPE_QUAL_VOLATILE) |	\    (TYPE_RESTRICT(NODE) * TYPE_QUAL_RESTRICT))
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
comment|/* If set in an ARRAY_TYPE, indicates a string type (for languages    that distinguish string from array of char).    If set in a SET_TYPE, indicates a bitstring type. */
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
comment|/* If non-NULL, this is a upper bound of the size (in bytes) of an    object of the given ARRAY_TYPE.  This allows temporaries to be allocated. */
end_comment

begin_define
define|#
directive|define
name|TYPE_ARRAY_MAX_SIZE
parameter_list|(
name|ARRAY_TYPE
parameter_list|)
value|TYPE_MAX_VALUE (ARRAY_TYPE)
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
value|(TYPE_CHECK (NODE)->type.transparent_union_flag)
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
name|size
decl_stmt|;
name|union
name|tree_node
modifier|*
name|size_unit
decl_stmt|;
name|union
name|tree_node
modifier|*
name|attributes
decl_stmt|;
name|unsigned
name|uid
decl_stmt|;
name|unsigned
name|char
name|precision
decl_stmt|;
ifdef|#
directive|ifdef
name|ONLY_INT_FIELDS
name|int
name|mode
range|:
literal|8
decl_stmt|;
else|#
directive|else
name|enum
name|machine_mode
name|mode
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
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
comment|/* room for 3 more bits */
name|unsigned
name|int
name|align
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
name|union
name|tree_node
modifier|*
name|name
decl_stmt|;
name|union
name|tree_node
modifier|*
name|minval
decl_stmt|;
name|union
name|tree_node
modifier|*
name|maxval
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
name|binfo
decl_stmt|;
name|union
name|tree_node
modifier|*
name|noncopied_parts
decl_stmt|;
name|union
name|tree_node
modifier|*
name|context
decl_stmt|;
name|struct
name|obstack
modifier|*
name|obstack
decl_stmt|;
name|int
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
comment|/* A vector of additional binfos for the types inherited by this basetype.     If this basetype describes type D as inherited in C,    and if the basetypes of D are E anf F,    then this vector contains binfos for inheritance of E and F by C.     ??? This could probably be done by just allocating the    base types at the end of this TREE_VEC (instead of using    another TREE_VEC).  This would simplify the calculation    of how many basetypes a given type had.  */
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
value|BINFO_TYPE (TREE_VEC_ELT (BINFO_BASETYPES (TYPE_BINFO (NODE)), (N)))
end_define

begin_comment
comment|/* For a BINFO record describing an inheritance, this yields a pointer    to the artificial FIELD_DECL node which contains the "virtual base    class pointer" for the given inheritance.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_VPTR_FIELD
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT ((NODE), 5)
end_define

begin_comment
comment|/* The size of a base class subobject of this type.  Not all frontends    currently allocate the space for this field.  */
end_comment

begin_define
define|#
directive|define
name|BINFO_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|TREE_VEC_ELT ((NODE), 6)
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
comment|/* This is the name of the object as the assembler will see it    (but before any translations made by ASM_OUTPUT_LABELREF).    Often this is the same as DECL_NAME.    It is an IDENTIFIER_NODE.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ASSEMBLER_NAME
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.assembler_name)
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
value|(DECL_CHECK (NODE)->decl.context)
end_define

begin_comment
comment|/* In a DECL this is the field where configuration dependent machine    attributes are store */
end_comment

begin_define
define|#
directive|define
name|DECL_MACHINE_ATTRIBUTES
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.machine_attributes)
end_define

begin_comment
comment|/* In a FIELD_DECL, this is the field position, counting in bits,    of the bit closest to the beginning of the structure.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FIELD_BITPOS
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.arguments)
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
value|(DECL_CHECK (NODE)->decl.result)
end_define

begin_comment
comment|/* In FUNCTION_DECL, a chain of ..._DECL nodes.  */
end_comment

begin_comment
comment|/* VAR_DECL and PARM_DECL reserve the arguments slot    for language-specific uses.  */
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
comment|/* In FUNCTION_DECL, holds the decl for the return value.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RESULT
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.result)
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
value|(DECL_CHECK (NODE)->decl.result)
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
value|(DECL_CHECK (NODE)->decl.result)
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
value|(DECL_CHECK (NODE)->decl.initial)
end_define

begin_comment
comment|/* In PARM_DECL.  */
end_comment

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
value|(DECL_CHECK (NODE)->decl.initial)
end_define

begin_comment
comment|/* These two fields describe where in the source code the declaration was.  */
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
comment|/* Holds the size of the datum, as a tree expression.    Need not be constant.  */
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
comment|/* Holds the alignment required for the datum.  */
end_comment

begin_define
define|#
directive|define
name|DECL_ALIGN
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.frame_size.u)
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
comment|/* Holds the RTL expression for the value of a variable or function.  If    PROMOTED_MODE is defined, the mode of this expression may not be same    as DECL_MODE.  In that case, DECL_MODE contains the mode corresponding    to the variable's data type, while the mode    of DECL_RTL is the mode actually used to contain the data.  */
end_comment

begin_define
define|#
directive|define
name|DECL_RTL
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.rtl)
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
value|(DECL_CHECK (NODE)->decl.saved_insns.r)
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
value|(DECL_CHECK (NODE)->decl.saved_insns.r)
end_define

begin_comment
comment|/* For FUNCTION_DECL, if it is inline,    holds the size of the stack frame, as an integer.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FRAME_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.frame_size.i)
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
value|(DECL_CHECK (NODE)->decl.frame_size.f)
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
value|(DECL_CHECK (NODE)->decl.frame_size.f = (VAL))
end_define

begin_comment
comment|/* For a FIELD_DECL, holds the size of the member as an integer.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FIELD_SIZE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.saved_insns.i)
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
value|(DECL_CHECK (NODE)->decl.vindex)
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
value|(DECL_ABSTRACT_ORIGIN (NODE) ? DECL_ABSTRACT_ORIGIN (NODE) : NODE)
end_define

begin_comment
comment|/* Nonzero for any sort of ..._DECL node means this decl node represents    an inline instance of some original (abstract) decl from an inline function;    suppress any warnings about shadowing some other variable.  */
end_comment

begin_define
define|#
directive|define
name|DECL_FROM_INLINE
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_ABSTRACT_ORIGIN (NODE) != (tree) 0)
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
comment|/* In a VAR_DECL for a RECORD_TYPE, sets number for non-init_priority    initializatons. */
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
comment|/* In a TYPE_DECL    nonzero means the detail info about this type is not dumped into stabs.    Instead it will generate cross reference ('x') of names.     This uses the same flag as DECL_EXTERNAL. */
end_comment

begin_define
define|#
directive|define
name|TYPE_DECL_SUPPRESS_DEBUG
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.external_flag)
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
value|(DECL_CHECK (NODE)->decl.regdecl_flag)
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
value|(DECL_CHECK (NODE)->decl.regdecl_flag)
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
value|(DECL_CHECK (NODE)->decl.regdecl_flag)
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
value|(DECL_CHECK (NODE)->decl.inline_flag)
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
value|((NODE)->common.unsigned_flag)
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
value|(DECL_CHECK (NODE)->decl.bit_field_flag)
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
value|(DECL_CHECK (NODE)->decl.bit_field_flag)
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
value|(DECL_CHECK (NODE)->decl.bit_field_flag)
end_define

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
value|(DECL_CHECK (NODE)->decl.bit_field_flag)
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
value|(DECL_CHECK (NODE)->decl.transparent_union)
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
value|(DECL_CHECK (NODE)->decl.static_ctor_flag)
end_define

begin_define
define|#
directive|define
name|DECL_STATIC_DESTRUCTOR
parameter_list|(
name|NODE
parameter_list|)
value|(DECL_CHECK (NODE)->decl.static_dtor_flag)
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
value|((NODE)->decl.no_instrument_function_entry_exit)
end_define

begin_comment
comment|/* Used in FUNCTION_DECLs to indicate that in this function,    check-memory-usage should be disabled.  */
end_comment

begin_define
define|#
directive|define
name|DECL_NO_CHECK_MEMORY_USAGE
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->decl.no_check_memory_usage)
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
name|unsigned
name|int
name|uid
decl_stmt|;
name|union
name|tree_node
modifier|*
name|size
decl_stmt|;
ifdef|#
directive|ifdef
name|ONLY_INT_FIELDS
name|int
name|mode
range|:
literal|8
decl_stmt|;
else|#
directive|else
name|enum
name|machine_mode
name|mode
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
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
name|no_check_memory_usage
range|:
literal|1
decl_stmt|;
name|unsigned
name|comdat_flag
range|:
literal|1
decl_stmt|;
comment|/* For a FUNCTION_DECL, if inline, this is the size of frame needed.      If built-in, this is the code for which built-in function.      For other kinds of decls, this is DECL_ALIGN.  */
union|union
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|int
name|u
decl_stmt|;
name|enum
name|built_in_function
name|f
decl_stmt|;
block|}
name|frame_size
union|;
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
name|union
name|tree_node
modifier|*
name|abstract_origin
decl_stmt|;
name|union
name|tree_node
modifier|*
name|assembler_name
decl_stmt|;
name|union
name|tree_node
modifier|*
name|section_name
decl_stmt|;
name|union
name|tree_node
modifier|*
name|machine_attributes
decl_stmt|;
name|struct
name|rtx_def
modifier|*
name|rtl
decl_stmt|;
comment|/* acts as link to register transfer language 				   (rtl) info */
name|struct
name|rtx_def
modifier|*
name|live_range_rtl
decl_stmt|;
comment|/* For FUNCTION_DECLs: points to insn that constitutes its definition      on the permanent obstack.  For FIELD_DECL, this is DECL_FIELD_SIZE.  */
union|union
block|{
name|struct
name|rtx_def
modifier|*
name|r
decl_stmt|;
name|HOST_WIDE_INT
name|i
decl_stmt|;
block|}
name|saved_insns
union|;
name|union
name|tree_node
modifier|*
name|vindex
decl_stmt|;
name|int
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

begin_define
define|#
directive|define
name|NULL_TREE
value|(tree) NULL
end_define

begin_comment
comment|/* The following functions accept a wide integer argument.  Rather than    having to cast on every function call, we use a macro instead, that is    defined here and in rtl.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|exact_log2
end_ifndef

begin_define
define|#
directive|define
name|exact_log2
parameter_list|(
name|N
parameter_list|)
value|exact_log2_wide ((unsigned HOST_WIDE_INT) (N))
end_define

begin_define
define|#
directive|define
name|floor_log2
parameter_list|(
name|N
parameter_list|)
value|floor_log2_wide ((unsigned HOST_WIDE_INT) (N))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|exact_log2_wide
name|PROTO
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|floor_log2_wide
name|PROTO
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|oballoc
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
name|char
modifier|*
name|permalloc
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
name|char
modifier|*
name|savealloc
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
name|char
modifier|*
name|expralloc
name|PROTO
argument_list|(
operator|(
name|int
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
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a copy of a node, with all the same contents except    for TREE_PERMANENT.  (The copy is permanent    iff nodes being made now are permanent.)  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|copy_node
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* If an identifier with the name TEXT (a null-terminated string) has    previously been referred to, return that node; otherwise return    NULL_TREE.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|maybe_get_identifier
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
value|build_int_2_wide ((HOST_WIDE_INT) (LO), (HOST_WIDE_INT) (HI))
end_define

begin_decl_stmt
specifier|extern
name|tree
name|build
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
name|build_nt
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
name|build_parse_node
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
name|build_int_2_wide
name|PROTO
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
name|tree
name|build_real
name|PROTO
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
name|build_complex
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
name|build_string
name|PROTO
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
name|build_tree_list
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
name|build_decl_list
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
name|build_expr_list
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
name|build_decl
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
name|build_block
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
name|build_expr_wfl
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
name|make_unsigned_type
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
name|set_sizetype
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
name|void
name|fixup_unsigned_type
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
name|build_pointer_type
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
name|build_reference_type
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
name|build_index_type
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
name|build_index_2_type
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
name|build_array_type
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
name|build_function_type
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
name|build_method_type
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
name|build_offset_type
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
name|build_complex_type
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
name|array_type_nelts
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
name|value_member
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
name|purpose_member
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
name|binfo_member
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
name|attribute_hash_list
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
name|attribute_list_equal
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
name|attribute_list_contained
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
name|tree_int_cst_equal
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
name|tree_int_cst_lt
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
name|tree_int_cst_sgn
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
name|index_type_equal
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
name|get_inner_array_type
name|PROTO
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

begin_escape
end_escape

begin_comment
comment|/* Return a type like TTYPE except that its TYPE_ATTRIBUTES    is ATTRIBUTE.     Such modified types already made are recorded so that duplicates    are not made. */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_type_attribute_variant
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
name|build_decl_attribute_variant
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
name|merge_machine_decl_attributes
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
name|merge_machine_type_attributes
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
comment|/* Split a list of declspecs and attributes into two.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|split_specs_attrs
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
name|PROTO
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

begin_comment
comment|/* Given a tree node and a string, return non-zero if the tree node is    a valid attribute name for the string.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|is_attribute_p
name|PROTO
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
name|PROTO
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
comment|/* Given a type node TYPE and a TYPE_QUALIFIER_SET, return a type for    the same kind of data as TYPE describes.  Variants point to the    "main variant" (which has no qualifiers set) via TYPE_MAIN_VARIANT,    and it points to a chain of other variants so that duplicate    variants are never made.  Only main variants should ever appear as    types of expressions.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_qualified_type
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
value|build_qualified_type (TYPE,						\ 			((CONST_P) ? TYPE_QUAL_CONST : 0)		\ 			| ((VOLATILE_P) ? TYPE_QUAL_VOLATILE : 0))
end_define

begin_comment
comment|/* Make a copy of a type node.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|build_type_copy
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a ..._TYPE node, calculate the TYPE_SIZE, TYPE_SIZE_UNIT,    TYPE_ALIGN and TYPE_MODE fields.    If called more than once on one node, does nothing except    for the first time.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|layout_type
name|PROTO
argument_list|(
operator|(
name|tree
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
comment|/* Given a VAR_DECL, PARM_DECL, RESULT_DECL or FIELD_DECL node,    calculates the DECL_SIZE, DECL_SIZE_UNIT, DECL_ALIGN and DECL_MODE    fields.  Call this only once for any given decl node.     Second argument is the boundary that this field can be assumed to    be starting at (in bits).  Zero means it can be assumed aligned    on any boundary that may be needed.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|layout_decl
name|PROTO
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
comment|/* Return an expr equal to X but certainly not valid as an lvalue.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|non_lvalue
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
name|pedantic_non_lvalue
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
name|size_in_bytes
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
name|HOST_WIDE_INT
name|int_size_in_bytes
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
name|size_binop
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
name|ssize_binop
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
name|size_int_wide
name|PROTO
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|size_int
parameter_list|(
name|L
parameter_list|)
value|size_int_2 ((L), 0, 0)
end_define

begin_define
define|#
directive|define
name|bitsize_int
parameter_list|(
name|L
parameter_list|,
name|H
parameter_list|)
value|size_int_2 ((L), (H), 1)
end_define

begin_define
define|#
directive|define
name|size_int_2
parameter_list|(
name|L
parameter_list|,
name|H
parameter_list|,
name|T
parameter_list|)
define|\
value|size_int_wide ((unsigned HOST_WIDE_INT) (L),	\ 		 (unsigned HOST_WIDE_INT) (H), (T))
end_define

begin_decl_stmt
specifier|extern
name|tree
name|round_up
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
name|get_pending_sizes
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
name|put_pending_sizes
name|PROTO
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

begin_struct
struct|struct
name|sizetype_tab
block|{
name|tree
name|xsizetype
decl_stmt|,
name|xbitsizetype
decl_stmt|;
name|tree
name|xssizetype
decl_stmt|,
name|xusizetype
decl_stmt|;
name|tree
name|xsbitsizetype
decl_stmt|,
name|xubitsizetype
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|sizetype_tab
name|sizetype_tab
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sizetype
value|sizetype_tab.xsizetype
end_define

begin_define
define|#
directive|define
name|bitsizetype
value|sizetype_tab.xbitsizetype
end_define

begin_define
define|#
directive|define
name|ssizetype
value|sizetype_tab.xssizetype
end_define

begin_define
define|#
directive|define
name|usizetype
value|sizetype_tab.xusizetype
end_define

begin_define
define|#
directive|define
name|sbitsizetype
value|sizetype_tab.xsbitsizetype
end_define

begin_define
define|#
directive|define
name|ubitsizetype
value|sizetype_tab.xubitsizetype
end_define

begin_comment
comment|/* If nonzero, an upper limit on alignment of structure fields, in bits. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maximum_field_alignment
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-zero, the alignment of a bitstring or (power-)set value, in bits. */
end_comment

begin_decl_stmt
specifier|extern
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
comment|/* Make a new TREE_LIST node from specified PURPOSE, VALUE and CHAIN.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|tree_cons
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
name|perm_tree_cons
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
name|temp_tree_cons
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
name|saveable_tree_cons
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
name|decl_tree_cons
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
name|expr_tree_cons
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
comment|/* Return the last tree node in a chain.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|tree_last
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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

begin_comment
comment|/* save_expr (EXP) returns an expression equivalent to EXP    but it can be used multiple times within context CTX    and only evaluate EXP once.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|save_expr
name|PROTO
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
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unsave_expr (EXP) returns an expression equivalent to EXP but it    can be used multiple times and will evaluate EXP, in its entirety    each time.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|unsave_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unsave_expr_now (EXP) resets EXP in place, so that it can be    expanded again.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|unsave_expr_now
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if EXP contains a PLACEHOLDER_EXPR; i.e., if it represents a size    or offset that depends on a field within a record.     Note that we only allow such expressions within simple arithmetic    or a COND_EXPR.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|contains_placeholder_p
name|PROTO
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
name|PROTO
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
comment|/* variable_size (EXP) is like save_expr (EXP) except that it    is for the special case of something that is part of a    variable size for a data type.  It makes special arrangements    to compute the value at the right time when the data type    belongs to a function parameter.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|variable_size
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* Return OP or a simpler expression for a narrower value    which can be sign-extended or zero-extended to give back OP.    Store in *UNSIGNEDP_PTR either 1 if the value should be zero-extended    or 0 if the value should be sign-extended.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_narrower
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

begin_comment
comment|/* Given MODE and UNSIGNEDP, return a suitable type-tree    with that mode.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

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

begin_comment
comment|/* Given PRECISION and UNSIGNEDP, return a suitable type-tree    for an integer type with at least that precision.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

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

begin_comment
comment|/* Given an integer type T, return a type like T but unsigned.    If T is unsigned, the value is T.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

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

begin_comment
comment|/* Given an integer type T, return a type like T but signed.    If T is signed, the value is T.    The definition of this resides in language-specific code    as the repertoire of available types may vary.  */
end_comment

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

begin_comment
comment|/* This function must be defined in the language-specific files.    expand_expr calls it to build the cleanup-expression for a TARGET_EXPR.    This is defined in a language-specific file.  */
end_comment

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

begin_comment
comment|/* Given an expression EXP that may be a COMPONENT_REF or an ARRAY_REF,    look for nested component-refs or array-refs at constant positions    and find the ultimate containing object, which is returned.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_inner_reference
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|*
operator|,
name|int
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
operator|,
name|int
operator|*
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* Current line number in input file.  */
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
comment|/* Nonzero if function being compiled can call longjmp.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_longjmp
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
extern|extern char *(*decl_printable_name
end_extern

begin_expr_stmt
unit|)
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|PROTO
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
name|tree
name|get_file_function_name
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
name|get_file_function_name_long
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
name|get_set_constructor_bits
name|PROTO
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
name|PROTO
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
name|int
name|get_alias_set
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
name|new_alias_set
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern int (*lang_get_alias_set
end_extern

begin_expr_stmt
unit|)
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/* In stmt.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_fixups
name|PROTO
argument_list|(
operator|(
expr|struct
name|rtx_def
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|expand_start_stmt_expr
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
name|expand_end_stmt_expr
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
name|expand_expr_stmt
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
name|warn_if_unused_value
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
name|expand_decl_init
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
name|clear_last_expr
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
name|expand_label
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
name|expand_goto
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
name|expand_asm
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
name|expand_start_cond
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
name|expand_end_cond
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
name|expand_start_else
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
name|expand_start_elseif
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
name|nesting
modifier|*
name|expand_start_loop
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
name|struct
name|nesting
modifier|*
name|expand_start_loop_continue_elsewhere
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
name|expand_loop_continue_here
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
name|expand_end_loop
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
name|expand_continue_loop
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|expand_null_return
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
name|expand_return
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
name|optimize_tail_recursion
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
name|void
name|expand_start_bindings
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
name|expand_end_bindings
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
name|void
name|start_cleanup_deferral
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
name|end_cleanup_deferral
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
name|mark_block_as_eh_region
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
name|mark_block_as_not_eh_region
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
name|is_eh_region
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
name|conditional_context
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
name|last_cleanup_this_contour
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
name|expand_dhc_cleanup
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
name|expand_dcc_cleanup
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
name|expand_start_case
name|PROTO
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
name|pushcase
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
name|PROTO
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
name|stmt_loop_nest_empty
name|PROTO
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
name|force_fit_type
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
name|add_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
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
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
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
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
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
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
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
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
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
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
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
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
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
name|invert_truthvalue
name|PROTO
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
comment|/* Interface of the DWARF2 unwind info support.  */
end_comment

begin_comment
comment|/* Decide whether we want to emit frame unwind information for the current    translation unit.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dwarf2out_do_frame
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate a new label for the CFI info to refer to.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dwarf2out_cfi_label
name|PROTO
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a marker (i.e. a label) for the beginning of a function, before    the prologue.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_begin_prologue
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a marker (i.e. a label) for the absolute end of the generated    code for a function definition.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_end_epilogue
name|PROTO
argument_list|(
operator|(
name|void
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
comment|/* Function of no arguments for initializing options.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lang_init_options
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function of no arguments for initializing lexical scanning.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_lex
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function of no arguments for initializing the symbol table.  */
end_comment

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

begin_comment
comment|/* Functions called with no arguments at the beginning and end or processing    the input source file.  */
end_comment

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

begin_comment
comment|/* Function to identify which front-end produced the output file. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lang_identify
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function to replace the DECL_LANG_SPECIFIC field of a DECL with a copy.  */
end_comment

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

begin_comment
comment|/* Function called with no arguments to parse and compile the input.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yyparse
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function called with option as argument    to decode options starting with -f or -W or +.    It should return nonzero if it handles the option.  */
end_comment

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
name|PROTO
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

begin_comment
comment|/* Set the BLOCK node for the current scope level.  */
end_comment

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

begin_comment
comment|/* Function to add a decl to the current scope level.    Takes one argument, a decl to add.    Returns that decl, or, if the same symbol is already declared, may    return a different decl for that name.  */
end_comment

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

begin_comment
comment|/* Function to return the chain of decls so far in the current scope level.  */
end_comment

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

begin_comment
comment|/* Function to return the chain of structure tags in the current scope level.  */
end_comment

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

begin_decl_stmt
specifier|extern
name|tree
name|build_range_type
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
comment|/* Call when starting to parse a declaration:    make expressions in the declaration last the length of the function.    Returns an argument that should be passed to resume_momentary later.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|suspend_momentary
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
name|allocation_temporary_p
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Call when finished parsing a declaration:    restore the treatment of node-allocation that was    in effect before the suspension.    YES should be the value previously returned by suspend_momentary.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|resume_momentary
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called after finishing a record, union or enumeral type.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|rest_of_type_compilation
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

begin_comment
comment|/* Save the current set of obstacks, but don't change them.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|push_obstacks_nochange
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
name|permanent_allocation
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
name|push_momentary
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
name|clear_momentary
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
name|pop_momentary
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
name|end_temporary_allocation
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop the obstack selection stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pop_obstacks
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|really_constant_p
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
name|push_obstacks
name|PROTO
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
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
name|void
name|pop_momentary_nofree
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
name|preserve_momentary
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
name|saveable_allocation
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
name|temporary_allocation
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
name|resume_temporary_allocation
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
name|get_file_function_name
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
name|set_identifier_size
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
name|int_fits_type_p
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
name|tree_log2
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
name|preserve_initializer
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
name|preserve_data
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
name|object_permanent_p
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
name|type_precision
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
name|simple_cst_equal
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
name|type_list_equal
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
name|chain_member
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
name|chain_member_purpose
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
name|chain_member_value
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
name|listify
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
name|type_hash_lookup
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
name|type_hash_add
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
name|int
name|type_hash_list
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
name|simple_cst_list_equal
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
name|debug_obstack
name|PROTO
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
name|void
name|rtl_in_current_obstack
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
name|rtl_in_saveable_obstack
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
name|init_tree_codes
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
name|dump_tree_statistics
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
name|print_obstack_statistics
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
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
name|real_onep
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
name|real_twop
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
name|start_identifier_warnings
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
name|gcc_obstack_init
name|PROTO
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
name|obfree
name|PROTO
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
name|tree_check
name|PROTO
argument_list|(
operator|(
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
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|tree_class_check
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|char
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

begin_decl_stmt
specifier|extern
name|tree
name|expr_check
name|PROTO
argument_list|(
operator|(
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
name|int
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
name|setjmp_protect
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
name|expand_main_function
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
name|mark_varargs
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
name|init_function_start
name|PROTO
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
name|void
name|assign_parms
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
name|put_var_into_stack
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
name|uninitialized_vars_warning
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
name|setjmp_args_warning
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
name|mark_all_temps_used
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
name|init_temp_slots
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
name|combine_temp_slots
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
name|free_temp_slots
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
name|pop_temp_slots
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
name|push_temp_slots
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
name|preserve_temp_slots
name|PROTO
argument_list|(
operator|(
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
name|aggregate_value_p
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
name|reorder_blocks
name|PROTO
argument_list|(
operator|(
name|tree
operator|*
operator|,
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
name|void
name|free_temps_for_rtl_expr
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
name|instantiate_virtual_regs
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
name|void
name|unshare_all_rtl
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
name|max_parm_reg_num
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
name|push_function_context
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
name|pop_function_context
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
name|push_function_context_to
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
name|pop_function_context_from
name|PROTO
argument_list|(
operator|(
name|tree
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
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
expr|struct
name|rtx_def
operator|*
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|void
name|emit_queue
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
name|apply_args_register_offset
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
name|struct
name|rtx_def
modifier|*
name|expand_builtin_return_addr
name|PROTO
argument_list|(
operator|(
expr|enum
name|built_in_function
operator|,
name|int
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
name|void
name|do_pending_stack_adjust
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
name|struct
name|rtx_def
modifier|*
name|expand_assignment
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
name|struct
name|rtx_def
modifier|*
name|store_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
expr|struct
name|rtx_def
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
name|check_max_integer_computation_mode
name|PROTO
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
name|rtx_def
modifier|*
name|emit_line_note_after
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
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
name|struct
name|rtx_def
modifier|*
name|emit_line_note
name|PROTO
argument_list|(
operator|(
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
name|struct
name|rtx_def
modifier|*
name|emit_line_note_force
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In c-typeck.c */
end_comment

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

begin_comment
comment|/* In c-lang.c */
end_comment

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

begin_comment
comment|/* In c-common.c */
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
name|int
name|min_precision
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
name|split_specs_attrs
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In c-decl.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|print_lang_decl
name|PROTO
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
name|print_lang_type
name|PROTO
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
name|print_lang_identifier
name|PROTO
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

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* In integrate.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|save_for_inline_nocopy
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
name|save_for_inline_copying
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
name|set_decl_abstract_flags
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
name|output_inline_function
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In c-lex.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_yydebug
name|PROTO
argument_list|(
operator|(
name|int
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
name|PROTO
argument_list|(
operator|(
name|tree
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
name|make_decl_one_only
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
name|supports_one_only
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
name|variable_section
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

begin_comment
comment|/* In fold-const.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|div_and_round_double
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
name|int
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
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
name|expand_computed_goto
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
name|rtx_def
modifier|*
name|label_rtx
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
name|expand_asm_operands
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
name|int
name|any_pending_cleanups
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
name|init_stmt
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
name|init_stmt_for_function
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
name|remember_end_note
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
name|drop_through_at_end_p
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
name|expand_start_target_temps
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
name|expand_end_target_temps
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
name|expand_elseif
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
name|expand_decl
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
name|expand_decl_cleanup
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
name|expand_anon_union_decl
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
name|move_cleanups_up
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
name|expand_start_case_dummy
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
name|expand_end_case_dummy
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
name|case_index_expr_type
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
name|HOST_WIDE_INT
name|all_cases_count
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
name|check_for_full_enumeration_handling
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
name|declare_nonlocal_label
name|PROTO
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
name|lang_print_xnode
name|PROTO
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If KIND=='I', return a suitable global initializer (constructor) name.    If KIND=='D', return a suitable global clean-up (destructor) name.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|get_file_function_name
name|PROTO
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
comment|/* Decide whether we want to emit frame unwind information for the current    translation unit.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dwarf2out_do_frame
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate a new label for the CFI info to refer to.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dwarf2out_cfi_label
name|PROTO
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a marker (i.e. a label) for the beginning of a function, before    the prologue.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_begin_prologue
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a marker (i.e. a label) for the absolute end of the generated    code for a function definition.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_end_epilogue
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

