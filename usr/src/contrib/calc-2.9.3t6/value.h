begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  *  * Definitions of general values and related routines used by the calculator.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALUE_H
end_ifndef

begin_define
define|#
directive|define
name|VALUE_H
end_define

begin_include
include|#
directive|include
file|"cmath.h"
end_include

begin_define
define|#
directive|define
name|MAXDIM
value|4
end_define

begin_comment
comment|/* maximum number of dimensions in matrices */
end_comment

begin_define
define|#
directive|define
name|USUAL_ELEMENTS
value|4
end_define

begin_comment
comment|/* usual number of elements for objects */
end_comment

begin_comment
comment|/*  * Flags to modify results from the printvalue routine.  * These flags are OR'd together.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_NORMAL
value|0x00
end_define

begin_comment
comment|/* print in normal manner */
end_comment

begin_define
define|#
directive|define
name|PRINT_SHORT
value|0x01
end_define

begin_comment
comment|/* print in short format (no elements) */
end_comment

begin_define
define|#
directive|define
name|PRINT_UNAMBIG
value|0x02
end_define

begin_comment
comment|/* print in non-ambiguous manner */
end_comment

begin_comment
comment|/*  * Definition of values of various types.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|value
name|VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|object
name|OBJECT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|matrix
name|MATRIX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|list
name|LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|assoc
name|ASSOC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|FILEID
typedef|;
end_typedef

begin_struct
struct|struct
name|value
block|{
name|short
name|v_type
decl_stmt|;
comment|/* type of value */
name|short
name|v_subtype
decl_stmt|;
comment|/* other data related to some types */
union|union
block|{
name|long
name|vv_int
decl_stmt|;
comment|/* small integer value */
name|FILEID
name|vv_file
decl_stmt|;
comment|/* id of opened file */
name|NUMBER
modifier|*
name|vv_num
decl_stmt|;
comment|/* arbitrary sized numeric value */
name|COMPLEX
modifier|*
name|vv_com
decl_stmt|;
comment|/* complex number */
name|VALUE
modifier|*
name|vv_addr
decl_stmt|;
comment|/* address of variable value */
name|MATRIX
modifier|*
name|vv_mat
decl_stmt|;
comment|/* address of matrix */
name|LIST
modifier|*
name|vv_list
decl_stmt|;
comment|/* address of list */
name|ASSOC
modifier|*
name|vv_assoc
decl_stmt|;
comment|/* address of association */
name|OBJECT
modifier|*
name|vv_obj
decl_stmt|;
comment|/* address of object */
name|char
modifier|*
name|vv_str
decl_stmt|;
comment|/* string value */
block|}
name|v_union
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * For ease in referencing  */
end_comment

begin_define
define|#
directive|define
name|v_int
value|v_union.vv_int
end_define

begin_define
define|#
directive|define
name|v_file
value|v_union.vv_file
end_define

begin_define
define|#
directive|define
name|v_num
value|v_union.vv_num
end_define

begin_define
define|#
directive|define
name|v_com
value|v_union.vv_com
end_define

begin_define
define|#
directive|define
name|v_addr
value|v_union.vv_addr
end_define

begin_define
define|#
directive|define
name|v_str
value|v_union.vv_str
end_define

begin_define
define|#
directive|define
name|v_mat
value|v_union.vv_mat
end_define

begin_define
define|#
directive|define
name|v_list
value|v_union.vv_list
end_define

begin_define
define|#
directive|define
name|v_assoc
value|v_union.vv_assoc
end_define

begin_define
define|#
directive|define
name|v_obj
value|v_union.vv_obj
end_define

begin_define
define|#
directive|define
name|v_valid
value|v_union.vv_int
end_define

begin_comment
comment|/*  * Value types.  */
end_comment

begin_define
define|#
directive|define
name|V_NULL
value|0
end_define

begin_comment
comment|/* null value */
end_comment

begin_define
define|#
directive|define
name|V_INT
value|1
end_define

begin_comment
comment|/* normal integer */
end_comment

begin_define
define|#
directive|define
name|V_NUM
value|2
end_define

begin_comment
comment|/* number */
end_comment

begin_define
define|#
directive|define
name|V_COM
value|3
end_define

begin_comment
comment|/* complex number */
end_comment

begin_define
define|#
directive|define
name|V_ADDR
value|4
end_define

begin_comment
comment|/* address of variable value */
end_comment

begin_define
define|#
directive|define
name|V_STR
value|5
end_define

begin_comment
comment|/* address of string */
end_comment

begin_define
define|#
directive|define
name|V_MAT
value|6
end_define

begin_comment
comment|/* address of matrix structure */
end_comment

begin_define
define|#
directive|define
name|V_LIST
value|7
end_define

begin_comment
comment|/* address of list structure */
end_comment

begin_define
define|#
directive|define
name|V_ASSOC
value|8
end_define

begin_comment
comment|/* address of association structure */
end_comment

begin_define
define|#
directive|define
name|V_OBJ
value|9
end_define

begin_comment
comment|/* address of object structure */
end_comment

begin_define
define|#
directive|define
name|V_FILE
value|10
end_define

begin_comment
comment|/* opened file id */
end_comment

begin_define
define|#
directive|define
name|V_MAX
value|10
end_define

begin_comment
comment|/* highest legal value */
end_comment

begin_define
define|#
directive|define
name|V_NOSUBTYPE
value|0
end_define

begin_comment
comment|/* subtype has no meaning */
end_comment

begin_define
define|#
directive|define
name|V_STRLITERAL
value|1
end_define

begin_comment
comment|/* string subtype for literal str */
end_comment

begin_define
define|#
directive|define
name|V_STRALLOC
value|2
end_define

begin_comment
comment|/* string subtype for allocated str */
end_comment

begin_define
define|#
directive|define
name|TWOVAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) * (V_MAX+1) + (b))
end_define

begin_comment
comment|/* for switch of two values */
end_comment

begin_define
define|#
directive|define
name|NULL_VALUE
value|((VALUE *) 0)
end_define

begin_decl_stmt
specifier|extern
name|void
name|freevalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|copyvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|negvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|subvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mulvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|squarevalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|invertvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|roundvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|broundvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|intvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fracvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|incvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|decvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|conjvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sqrtvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rootvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|v3
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|absvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|normvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|shiftvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|BOOL
name|rightshift
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|scalevalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|powivalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|powervalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|v3
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|divvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|quovalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|modvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|vres
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|testvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|comparevalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FLAG
name|relvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HASH
name|hashvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printvalue
name|MATH_PROTO
argument_list|(
operator|(
name|VALUE
operator|*
name|vp
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structure of a matrix.  */
end_comment

begin_struct
struct|struct
name|matrix
block|{
name|long
name|m_dim
decl_stmt|;
comment|/* dimension of matrix */
name|long
name|m_size
decl_stmt|;
comment|/* total number of elements */
name|long
name|m_min
index|[
name|MAXDIM
index|]
decl_stmt|;
comment|/* minimum bound for indices */
name|long
name|m_max
index|[
name|MAXDIM
index|]
decl_stmt|;
comment|/* maximum bound for indices */
name|VALUE
name|m_table
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually varying length table */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|matsize
parameter_list|(
name|n
parameter_list|)
value|(sizeof(MATRIX) - sizeof(VALUE) + ((n) * sizeof(VALUE)))
end_define

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matadd
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m1
operator|,
name|MATRIX
operator|*
name|m2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matsub
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m1
operator|,
name|MATRIX
operator|*
name|m2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matmul
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m1
operator|,
name|MATRIX
operator|*
name|m2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matneg
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matalloc
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matcopy
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matsquare
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matinv
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matscale
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matshift
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matmulval
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matpowi
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|NUMBER
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matconj
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matquoval
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matmodval
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matint
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matfrac
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matround
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|long
name|places
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matbround
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|long
name|places
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|mattrans
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MATRIX
modifier|*
name|matcross
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m1
operator|,
name|MATRIX
operator|*
name|m2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|mattest
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|matcmp
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m1
operator|,
name|MATRIX
operator|*
name|m2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|matsearch
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|VALUE
operator|*
name|vp
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|matrsearch
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|VALUE
operator|*
name|vp
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HASH
name|mathash
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
name|matdet
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
name|matdot
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m1
operator|,
name|MATRIX
operator|*
name|m2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|matfill
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|matfree
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|matprint
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|m
operator|,
name|long
name|max_print
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
modifier|*
name|matindex
name|MATH_PROTO
argument_list|(
operator|(
name|MATRIX
operator|*
name|mp
operator|,
name|BOOL
name|create
operator|,
name|long
name|dim
operator|,
name|VALUE
operator|*
name|indices
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
unit|extern BOOL matisident MATH_PROTO((MATRIX *m));
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * List definitions.  * An individual list element.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|listelem
name|LISTELEM
typedef|;
end_typedef

begin_struct
struct|struct
name|listelem
block|{
name|LISTELEM
modifier|*
name|e_next
decl_stmt|;
comment|/* next element in list (or NULL) */
name|LISTELEM
modifier|*
name|e_prev
decl_stmt|;
comment|/* previous element in list (or NULL) */
name|VALUE
name|e_value
decl_stmt|;
comment|/* value of this element */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for a list of elements.  */
end_comment

begin_struct
struct|struct
name|list
block|{
name|LISTELEM
modifier|*
name|l_first
decl_stmt|;
comment|/* first list element (or NULL) */
name|LISTELEM
modifier|*
name|l_last
decl_stmt|;
comment|/* last list element (or NULL) */
name|LISTELEM
modifier|*
name|l_cache
decl_stmt|;
comment|/* cached list element (or NULL) */
name|long
name|l_cacheindex
decl_stmt|;
comment|/* index of cached element (or undefined) */
name|long
name|l_count
decl_stmt|;
comment|/* total number of elements in the list */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|insertlistfirst
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|insertlistlast
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|insertlistmiddle
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|long
name|index
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|removelistfirst
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|removelistlast
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|removelistmiddle
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|long
name|index
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|listfree
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|listprint
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|long
name|max_print
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|listsearch
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|VALUE
operator|*
name|vp
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|listrsearch
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|VALUE
operator|*
name|vp
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HASH
name|listhash
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|listcmp
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp1
operator|,
name|LIST
operator|*
name|lp2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
modifier|*
name|listfindex
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LIST
modifier|*
name|listalloc
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LIST
modifier|*
name|listcopy
name|MATH_PROTO
argument_list|(
operator|(
name|LIST
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structures for associations.  * Associations are "indexed" by one or more arbitrary values, and are  * stored in a hash table with their hash values for quick indexing.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|assocelem
name|ASSOCELEM
typedef|;
end_typedef

begin_struct
struct|struct
name|assocelem
block|{
name|ASSOCELEM
modifier|*
name|e_next
decl_stmt|;
comment|/* next element in list (or NULL) */
name|long
name|e_dim
decl_stmt|;
comment|/* dimension of indexing for this element */
name|HASH
name|e_hash
decl_stmt|;
comment|/* hash value for this element */
name|VALUE
name|e_value
decl_stmt|;
comment|/* value of association */
name|VALUE
name|e_indices
index|[
literal|1
index|]
decl_stmt|;
comment|/* index values (variable length) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|assoc
block|{
name|long
name|a_count
decl_stmt|;
comment|/* number of elements in the association */
name|long
name|a_size
decl_stmt|;
comment|/* current size of association hash table */
name|ASSOCELEM
modifier|*
modifier|*
name|a_table
decl_stmt|;
comment|/* current hash table for elements */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|ASSOC
modifier|*
name|assocalloc
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|initsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ASSOC
modifier|*
name|assoccopy
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|assocfree
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|assocprint
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap
operator|,
name|long
name|max_print
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|assocsearch
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap
operator|,
name|VALUE
operator|*
name|vp
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|assocrsearch
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap
operator|,
name|VALUE
operator|*
name|vp
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HASH
name|assochash
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|assoccmp
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap1
operator|,
name|ASSOC
operator|*
name|ap2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
modifier|*
name|assocfindex
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
modifier|*
name|associndex
name|MATH_PROTO
argument_list|(
operator|(
name|ASSOC
operator|*
name|ap
operator|,
name|BOOL
name|create
operator|,
name|long
name|dim
operator|,
name|VALUE
operator|*
name|indices
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Object actions.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_PRINT
value|0
end_define

begin_comment
comment|/* print the value */
end_comment

begin_define
define|#
directive|define
name|OBJ_ONE
value|1
end_define

begin_comment
comment|/* create the multiplicative identity */
end_comment

begin_define
define|#
directive|define
name|OBJ_TEST
value|2
end_define

begin_comment
comment|/* test a value for "zero" */
end_comment

begin_define
define|#
directive|define
name|OBJ_ADD
value|3
end_define

begin_comment
comment|/* add two values */
end_comment

begin_define
define|#
directive|define
name|OBJ_SUB
value|4
end_define

begin_comment
comment|/* subtrace one value from another */
end_comment

begin_define
define|#
directive|define
name|OBJ_NEG
value|5
end_define

begin_comment
comment|/* negate a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_MUL
value|6
end_define

begin_comment
comment|/* multiply two values */
end_comment

begin_define
define|#
directive|define
name|OBJ_DIV
value|7
end_define

begin_comment
comment|/* divide one value by another */
end_comment

begin_define
define|#
directive|define
name|OBJ_INV
value|8
end_define

begin_comment
comment|/* invert a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_ABS
value|9
end_define

begin_comment
comment|/* take absolute value of value */
end_comment

begin_define
define|#
directive|define
name|OBJ_NORM
value|10
end_define

begin_comment
comment|/* take the norm of a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_CONJ
value|11
end_define

begin_comment
comment|/* take the conjugate of a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_POW
value|12
end_define

begin_comment
comment|/* take the power function */
end_comment

begin_define
define|#
directive|define
name|OBJ_SGN
value|13
end_define

begin_comment
comment|/* return the sign of a value */
end_comment

begin_define
define|#
directive|define
name|OBJ_CMP
value|14
end_define

begin_comment
comment|/* compare two values for equality */
end_comment

begin_define
define|#
directive|define
name|OBJ_REL
value|15
end_define

begin_comment
comment|/* compare two values for inequality */
end_comment

begin_define
define|#
directive|define
name|OBJ_QUO
value|16
end_define

begin_comment
comment|/* integer quotient of values */
end_comment

begin_define
define|#
directive|define
name|OBJ_MOD
value|17
end_define

begin_comment
comment|/* remainder of division of values */
end_comment

begin_define
define|#
directive|define
name|OBJ_INT
value|18
end_define

begin_comment
comment|/* integer part of */
end_comment

begin_define
define|#
directive|define
name|OBJ_FRAC
value|19
end_define

begin_comment
comment|/* fractional part of */
end_comment

begin_define
define|#
directive|define
name|OBJ_INC
value|20
end_define

begin_comment
comment|/* increment by one */
end_comment

begin_define
define|#
directive|define
name|OBJ_DEC
value|21
end_define

begin_comment
comment|/* decrement by one */
end_comment

begin_define
define|#
directive|define
name|OBJ_SQUARE
value|22
end_define

begin_comment
comment|/* square value */
end_comment

begin_define
define|#
directive|define
name|OBJ_SCALE
value|23
end_define

begin_comment
comment|/* scale by power of two */
end_comment

begin_define
define|#
directive|define
name|OBJ_SHIFT
value|24
end_define

begin_comment
comment|/* shift left (or right) by number of bits */
end_comment

begin_define
define|#
directive|define
name|OBJ_ROUND
value|25
end_define

begin_comment
comment|/* round to specified decimal places */
end_comment

begin_define
define|#
directive|define
name|OBJ_BROUND
value|26
end_define

begin_comment
comment|/* round to specified binary places */
end_comment

begin_define
define|#
directive|define
name|OBJ_ROOT
value|27
end_define

begin_comment
comment|/* take nth root of value */
end_comment

begin_define
define|#
directive|define
name|OBJ_SQRT
value|28
end_define

begin_comment
comment|/* take square root of value */
end_comment

begin_define
define|#
directive|define
name|OBJ_MAXFUNC
value|28
end_define

begin_comment
comment|/* highest function */
end_comment

begin_comment
comment|/*  * Definition of an object type.  * This is actually a varying sized structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of object */
name|int
name|count
decl_stmt|;
comment|/* number of elements defined */
name|int
name|actions
index|[
name|OBJ_MAXFUNC
operator|+
literal|1
index|]
decl_stmt|;
comment|/* function indices for actions */
name|int
name|elements
index|[
literal|1
index|]
decl_stmt|;
comment|/* element indexes (MUST BE LAST) */
block|}
name|OBJECTACTIONS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|objectactionsize
parameter_list|(
name|elements
parameter_list|)
define|\
value|(sizeof(OBJECTACTIONS) + ((elements) - 1) * sizeof(int))
end_define

begin_comment
comment|/*  * Structure of an object.  * This is actually a varying sized structure.  * However, there are always at least USUAL_ELEMENTS values in the object.  */
end_comment

begin_struct
struct|struct
name|object
block|{
name|OBJECTACTIONS
modifier|*
name|o_actions
decl_stmt|;
comment|/* action table for this object */
name|VALUE
name|o_table
index|[
name|USUAL_ELEMENTS
index|]
decl_stmt|;
comment|/* object values (MUST BE LAST) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|objectsize
parameter_list|(
name|elements
parameter_list|)
define|\
value|(sizeof(OBJECT) + ((elements) - USUAL_ELEMENTS) * sizeof(VALUE))
end_define

begin_decl_stmt
specifier|extern
name|OBJECT
modifier|*
name|objcopy
name|MATH_PROTO
argument_list|(
operator|(
name|OBJECT
operator|*
name|op
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OBJECT
modifier|*
name|objalloc
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VALUE
name|objcall
name|MATH_PROTO
argument_list|(
operator|(
name|int
name|action
operator|,
name|VALUE
operator|*
name|v1
operator|,
name|VALUE
operator|*
name|v2
operator|,
name|VALUE
operator|*
name|v3
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|objfree
name|MATH_PROTO
argument_list|(
operator|(
name|OBJECT
operator|*
name|op
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|objuncache
name|MATH_PROTO
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
name|addelement
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|defineobject
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|indices
index|[]
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|checkobject
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|showobjfuncs
name|MATH_PROTO
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
name|findelement
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|objoffset
name|MATH_PROTO
argument_list|(
operator|(
name|OBJECT
operator|*
name|op
operator|,
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HASH
name|objhash
name|MATH_PROTO
argument_list|(
operator|(
name|OBJECT
operator|*
name|op
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

