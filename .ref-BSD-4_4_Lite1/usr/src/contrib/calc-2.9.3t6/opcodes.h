begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPCODES_H
end_ifndef

begin_define
define|#
directive|define
name|OPCODES_H
end_define

begin_comment
comment|/*  * Opcodes  */
end_comment

begin_define
define|#
directive|define
name|OP_NOP
value|0L
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|OP_LOCALADDR
value|1L
end_define

begin_comment
comment|/* load address of local variable */
end_comment

begin_define
define|#
directive|define
name|OP_GLOBALADDR
value|2L
end_define

begin_comment
comment|/* load address of global variable */
end_comment

begin_define
define|#
directive|define
name|OP_PARAMADDR
value|3L
end_define

begin_comment
comment|/* load address of paramater variable */
end_comment

begin_define
define|#
directive|define
name|OP_LOCALVALUE
value|4L
end_define

begin_comment
comment|/* load value of local variable */
end_comment

begin_define
define|#
directive|define
name|OP_GLOBALVALUE
value|5L
end_define

begin_comment
comment|/* load value of global variable */
end_comment

begin_define
define|#
directive|define
name|OP_PARAMVALUE
value|6L
end_define

begin_comment
comment|/* load value of paramater variable */
end_comment

begin_define
define|#
directive|define
name|OP_NUMBER
value|7L
end_define

begin_comment
comment|/* load constant real numeric value */
end_comment

begin_define
define|#
directive|define
name|OP_INDEXADDR
value|8L
end_define

begin_comment
comment|/* load array index address */
end_comment

begin_define
define|#
directive|define
name|OP_PRINTRESULT
value|9L
end_define

begin_comment
comment|/* print result of top-level expression */
end_comment

begin_define
define|#
directive|define
name|OP_ASSIGN
value|10L
end_define

begin_comment
comment|/* assign value to variable */
end_comment

begin_define
define|#
directive|define
name|OP_ADD
value|11L
end_define

begin_comment
comment|/* add top two values */
end_comment

begin_define
define|#
directive|define
name|OP_SUB
value|12L
end_define

begin_comment
comment|/* subtract top two values */
end_comment

begin_define
define|#
directive|define
name|OP_MUL
value|13L
end_define

begin_comment
comment|/* multiply top two values */
end_comment

begin_define
define|#
directive|define
name|OP_DIV
value|14L
end_define

begin_comment
comment|/* divide top two values */
end_comment

begin_define
define|#
directive|define
name|OP_MOD
value|15L
end_define

begin_comment
comment|/* take mod of top two values */
end_comment

begin_define
define|#
directive|define
name|OP_SAVE
value|16L
end_define

begin_comment
comment|/* save value for later use */
end_comment

begin_define
define|#
directive|define
name|OP_NEGATE
value|17L
end_define

begin_comment
comment|/* negate top value */
end_comment

begin_define
define|#
directive|define
name|OP_INVERT
value|18L
end_define

begin_comment
comment|/* invert top value */
end_comment

begin_define
define|#
directive|define
name|OP_INT
value|19L
end_define

begin_comment
comment|/* take integer part of top value */
end_comment

begin_define
define|#
directive|define
name|OP_FRAC
value|20L
end_define

begin_comment
comment|/* take fraction part of top value */
end_comment

begin_define
define|#
directive|define
name|OP_NUMERATOR
value|21L
end_define

begin_comment
comment|/* take numerator of top value */
end_comment

begin_define
define|#
directive|define
name|OP_DENOMINATOR
value|22L
end_define

begin_comment
comment|/* take denominator of top value */
end_comment

begin_define
define|#
directive|define
name|OP_DUPLICATE
value|23L
end_define

begin_comment
comment|/* duplicate top value on stack */
end_comment

begin_define
define|#
directive|define
name|OP_POP
value|24L
end_define

begin_comment
comment|/* pop top value from stack */
end_comment

begin_define
define|#
directive|define
name|OP_RETURN
value|25L
end_define

begin_comment
comment|/* return value of function */
end_comment

begin_define
define|#
directive|define
name|OP_JUMPEQ
value|26L
end_define

begin_comment
comment|/* jump if top value is zero */
end_comment

begin_define
define|#
directive|define
name|OP_JUMPNE
value|27L
end_define

begin_comment
comment|/* jump if top value is nonzero */
end_comment

begin_define
define|#
directive|define
name|OP_JUMP
value|28L
end_define

begin_comment
comment|/* jump unconditionally */
end_comment

begin_define
define|#
directive|define
name|OP_USERCALL
value|29L
end_define

begin_comment
comment|/* call a user-defined function */
end_comment

begin_define
define|#
directive|define
name|OP_GETVALUE
value|30L
end_define

begin_comment
comment|/* convert address to value */
end_comment

begin_define
define|#
directive|define
name|OP_EQ
value|31L
end_define

begin_comment
comment|/* test top two elements for equality */
end_comment

begin_define
define|#
directive|define
name|OP_NE
value|32L
end_define

begin_comment
comment|/* test top two elements for inequality */
end_comment

begin_define
define|#
directive|define
name|OP_LE
value|33L
end_define

begin_comment
comment|/* test top two elements for<= */
end_comment

begin_define
define|#
directive|define
name|OP_GE
value|34L
end_define

begin_comment
comment|/* test top two elements for>= */
end_comment

begin_define
define|#
directive|define
name|OP_LT
value|35L
end_define

begin_comment
comment|/* test top two elements for< */
end_comment

begin_define
define|#
directive|define
name|OP_GT
value|36L
end_define

begin_comment
comment|/* test top two elements for> */
end_comment

begin_define
define|#
directive|define
name|OP_PREINC
value|37L
end_define

begin_comment
comment|/* add one to variable (++x) */
end_comment

begin_define
define|#
directive|define
name|OP_PREDEC
value|38L
end_define

begin_comment
comment|/* subtract one from variable (--x) */
end_comment

begin_define
define|#
directive|define
name|OP_POSTINC
value|39L
end_define

begin_comment
comment|/* add one to variable (x++) */
end_comment

begin_define
define|#
directive|define
name|OP_POSTDEC
value|40L
end_define

begin_comment
comment|/* subtract one from variable (x--) */
end_comment

begin_define
define|#
directive|define
name|OP_DEBUG
value|41L
end_define

begin_comment
comment|/* debugging point */
end_comment

begin_define
define|#
directive|define
name|OP_PRINT
value|42L
end_define

begin_comment
comment|/* print value */
end_comment

begin_define
define|#
directive|define
name|OP_ASSIGNPOP
value|43L
end_define

begin_comment
comment|/* assign to variable and remove it */
end_comment

begin_define
define|#
directive|define
name|OP_ZERO
value|44L
end_define

begin_comment
comment|/* put zero on the stack */
end_comment

begin_define
define|#
directive|define
name|OP_ONE
value|45L
end_define

begin_comment
comment|/* put one on the stack */
end_comment

begin_define
define|#
directive|define
name|OP_PRINTEOL
value|46L
end_define

begin_comment
comment|/* print end of line */
end_comment

begin_define
define|#
directive|define
name|OP_PRINTSPACE
value|47L
end_define

begin_comment
comment|/* print a space */
end_comment

begin_define
define|#
directive|define
name|OP_PRINTSTRING
value|48L
end_define

begin_comment
comment|/* print constant string */
end_comment

begin_define
define|#
directive|define
name|OP_DUPVALUE
value|49L
end_define

begin_comment
comment|/* duplicate value of top value */
end_comment

begin_define
define|#
directive|define
name|OP_OLDVALUE
value|50L
end_define

begin_comment
comment|/* old calculation value */
end_comment

begin_define
define|#
directive|define
name|OP_QUO
value|51L
end_define

begin_comment
comment|/* integer quotient of top two values */
end_comment

begin_define
define|#
directive|define
name|OP_POWER
value|52L
end_define

begin_comment
comment|/* number raised to a power */
end_comment

begin_define
define|#
directive|define
name|OP_QUIT
value|53L
end_define

begin_comment
comment|/* quit program */
end_comment

begin_define
define|#
directive|define
name|OP_CALL
value|54L
end_define

begin_comment
comment|/* call built-in routine */
end_comment

begin_define
define|#
directive|define
name|OP_GETEPSILON
value|55L
end_define

begin_comment
comment|/* get allowed error for calculations */
end_comment

begin_define
define|#
directive|define
name|OP_AND
value|56L
end_define

begin_comment
comment|/* arithmetic and */
end_comment

begin_define
define|#
directive|define
name|OP_OR
value|57L
end_define

begin_comment
comment|/* arithmetic or */
end_comment

begin_define
define|#
directive|define
name|OP_NOT
value|58L
end_define

begin_comment
comment|/* logical not */
end_comment

begin_define
define|#
directive|define
name|OP_ABS
value|59L
end_define

begin_comment
comment|/* absolute value */
end_comment

begin_define
define|#
directive|define
name|OP_SGN
value|60L
end_define

begin_comment
comment|/* sign of number */
end_comment

begin_define
define|#
directive|define
name|OP_ISINT
value|61L
end_define

begin_comment
comment|/* whether top value is integer */
end_comment

begin_define
define|#
directive|define
name|OP_CONDORJUMP
value|62L
end_define

begin_comment
comment|/* conditional or jump */
end_comment

begin_define
define|#
directive|define
name|OP_CONDANDJUMP
value|63L
end_define

begin_comment
comment|/* conditional and jump */
end_comment

begin_define
define|#
directive|define
name|OP_SQUARE
value|64L
end_define

begin_comment
comment|/* square top value */
end_comment

begin_define
define|#
directive|define
name|OP_STRING
value|65L
end_define

begin_comment
comment|/* load constant string value */
end_comment

begin_define
define|#
directive|define
name|OP_ISNUM
value|66L
end_define

begin_comment
comment|/* whether top value is a number */
end_comment

begin_define
define|#
directive|define
name|OP_UNDEF
value|67L
end_define

begin_comment
comment|/* load undefined value on stack */
end_comment

begin_define
define|#
directive|define
name|OP_ISNULL
value|68L
end_define

begin_comment
comment|/* whether variable is the null value */
end_comment

begin_define
define|#
directive|define
name|OP_ARGVALUE
value|69L
end_define

begin_comment
comment|/* load value of argument (parameter) n */
end_comment

begin_define
define|#
directive|define
name|OP_MATCREATE
value|70L
end_define

begin_comment
comment|/* create matrix */
end_comment

begin_define
define|#
directive|define
name|OP_ISMAT
value|71L
end_define

begin_comment
comment|/* whether variable is a matrix */
end_comment

begin_define
define|#
directive|define
name|OP_ISSTR
value|72L
end_define

begin_comment
comment|/* whether variable is a string */
end_comment

begin_define
define|#
directive|define
name|OP_GETCONFIG
value|73L
end_define

begin_comment
comment|/* get value of configuration parameter */
end_comment

begin_define
define|#
directive|define
name|OP_LEFTSHIFT
value|74L
end_define

begin_comment
comment|/* left shift of integer */
end_comment

begin_define
define|#
directive|define
name|OP_RIGHTSHIFT
value|75L
end_define

begin_comment
comment|/* right shift of integer */
end_comment

begin_define
define|#
directive|define
name|OP_CASEJUMP
value|76L
end_define

begin_comment
comment|/* test case and jump if not matched */
end_comment

begin_define
define|#
directive|define
name|OP_ISODD
value|77L
end_define

begin_comment
comment|/* whether value is an odd integer */
end_comment

begin_define
define|#
directive|define
name|OP_ISEVEN
value|78L
end_define

begin_comment
comment|/* whether value is even integer */
end_comment

begin_define
define|#
directive|define
name|OP_FIADDR
value|79L
end_define

begin_comment
comment|/* 'fast index' matrix value address */
end_comment

begin_define
define|#
directive|define
name|OP_FIVALUE
value|80L
end_define

begin_comment
comment|/* 'fast index' matrix value */
end_comment

begin_define
define|#
directive|define
name|OP_ISREAL
value|81L
end_define

begin_comment
comment|/* test value for real number */
end_comment

begin_define
define|#
directive|define
name|OP_IMAGINARY
value|82L
end_define

begin_comment
comment|/* load imaginary numeric constant */
end_comment

begin_define
define|#
directive|define
name|OP_RE
value|83L
end_define

begin_comment
comment|/* real part of complex number */
end_comment

begin_define
define|#
directive|define
name|OP_IM
value|84L
end_define

begin_comment
comment|/* imaginary part of complex number */
end_comment

begin_define
define|#
directive|define
name|OP_CONJUGATE
value|85L
end_define

begin_comment
comment|/* complex conjugate of complex number */
end_comment

begin_define
define|#
directive|define
name|OP_OBJCREATE
value|86L
end_define

begin_comment
comment|/* create object */
end_comment

begin_define
define|#
directive|define
name|OP_ISOBJ
value|87L
end_define

begin_comment
comment|/* whether value is an object */
end_comment

begin_define
define|#
directive|define
name|OP_NORM
value|88L
end_define

begin_comment
comment|/* norm of value (square of abs) */
end_comment

begin_define
define|#
directive|define
name|OP_ELEMADDR
value|89L
end_define

begin_comment
comment|/* address of element of object */
end_comment

begin_define
define|#
directive|define
name|OP_ELEMVALUE
value|90L
end_define

begin_comment
comment|/* value of element of object */
end_comment

begin_define
define|#
directive|define
name|OP_ISTYPE
value|91L
end_define

begin_comment
comment|/* whether two values are the same type */
end_comment

begin_define
define|#
directive|define
name|OP_SCALE
value|92L
end_define

begin_comment
comment|/* scale value by a power of two */
end_comment

begin_define
define|#
directive|define
name|OP_ISLIST
value|93L
end_define

begin_comment
comment|/* whether value is a list */
end_comment

begin_define
define|#
directive|define
name|OP_SWAP
value|94L
end_define

begin_comment
comment|/* swap values of two variables */
end_comment

begin_define
define|#
directive|define
name|OP_ISSIMPLE
value|95L
end_define

begin_comment
comment|/* whether value is a simple type */
end_comment

begin_define
define|#
directive|define
name|OP_CMP
value|96L
end_define

begin_comment
comment|/* compare values returning -1, 0, or 1 */
end_comment

begin_define
define|#
directive|define
name|OP_QUOMOD
value|97L
end_define

begin_comment
comment|/* calculate quotient and remainder */
end_comment

begin_define
define|#
directive|define
name|OP_SETCONFIG
value|98L
end_define

begin_comment
comment|/* set configuration parameter */
end_comment

begin_define
define|#
directive|define
name|OP_SETEPSILON
value|99L
end_define

begin_comment
comment|/* set allowed error for calculations */
end_comment

begin_define
define|#
directive|define
name|OP_ISFILE
value|100L
end_define

begin_comment
comment|/* whether value is a file */
end_comment

begin_define
define|#
directive|define
name|OP_ISASSOC
value|101L
end_define

begin_comment
comment|/* whether value is an association */
end_comment

begin_define
define|#
directive|define
name|OP_INITSTATIC
value|102L
end_define

begin_comment
comment|/* once only code for static initialization */
end_comment

begin_define
define|#
directive|define
name|OP_ELEMINIT
value|103L
end_define

begin_comment
comment|/* assign element of matrix or object */
end_comment

begin_define
define|#
directive|define
name|MAX_OPCODE
value|103L
end_define

begin_comment
comment|/* highest legal opcode */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

