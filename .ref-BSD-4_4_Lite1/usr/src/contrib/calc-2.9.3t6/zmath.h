begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  *  * Data structure declarations for extended precision integer arithmetic.  * The assumption made is that a long is 32 bits and shorts are 16 bits,  * and longs must be addressible on word boundaries.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZMATH_H
end_ifndef

begin_define
define|#
directive|define
name|ZMATH_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"alloc.h"
end_include

begin_include
include|#
directive|include
file|"endian.h"
end_include

begin_include
include|#
directive|include
file|"longbits.h"
end_include

begin_include
include|#
directive|include
file|"have_stdlib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ALLOCTEST
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CALC_MALLOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|freeh
parameter_list|(
name|p
parameter_list|)
value|(((void *)p == (void *)_zeroval_) ||			\ 		    ((void *)p == (void *)_oneval_) || free((void *)p))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|freeh
parameter_list|(
name|p
parameter_list|)
value|{ if (((void *)p != (void *)_zeroval_)&&		\ 			 ((void *)p != (void *)_oneval_)) free((void *)p); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|FLAG
typedef|;
end_typedef

begin_comment
comment|/* small value (e.g. comparison) */
end_comment

begin_typedef
typedef|typedef
name|int
name|BOOL
typedef|;
end_typedef

begin_comment
comment|/* TRUE or FALSE value */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|HASH
typedef|;
end_typedef

begin_comment
comment|/* hash value */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TRUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|TRUE
value|((BOOL) 1)
end_define

begin_comment
comment|/* booleans */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FALSE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FALSE
value|((BOOL) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NOTE: FULL must be twice the storage size of a HALF  *	 LEN storage size must be<= FULL storage size  */
end_comment

begin_if
if|#
directive|if
name|LONG_BITS
operator|==
literal|64
end_if

begin_comment
comment|/* for 64-bit machines */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|HALF
typedef|;
end_typedef

begin_comment
comment|/* unit of number storage */
end_comment

begin_typedef
typedef|typedef
name|int
name|SHALF
typedef|;
end_typedef

begin_comment
comment|/* signed HALF */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|FULL
typedef|;
end_typedef

begin_comment
comment|/* double unit of number storage */
end_comment

begin_typedef
typedef|typedef
name|long
name|LEN
typedef|;
end_typedef

begin_comment
comment|/* unit of length storage */
end_comment

begin_define
define|#
directive|define
name|BASE
value|((FULL) 4294967296)
end_define

begin_comment
comment|/* base for calculations (2^32) */
end_comment

begin_define
define|#
directive|define
name|BASE1
value|((FULL) (BASE - 1))
end_define

begin_comment
comment|/* one less than base */
end_comment

begin_define
define|#
directive|define
name|BASEB
value|32
end_define

begin_comment
comment|/* number of bits in base */
end_comment

begin_define
define|#
directive|define
name|BASEDIG
value|10
end_define

begin_comment
comment|/* number of digits in base */
end_comment

begin_define
define|#
directive|define
name|MAXHALF
value|((FULL) 0x7fffffff)
end_define

begin_comment
comment|/* largest positive half value */
end_comment

begin_define
define|#
directive|define
name|MAXFULL
value|((FULL) 0x7fffffffffffffff)
end_define

begin_comment
comment|/* largest positive full value */
end_comment

begin_define
define|#
directive|define
name|TOPHALF
value|((FULL) 0x80000000)
end_define

begin_comment
comment|/* highest bit in half value */
end_comment

begin_define
define|#
directive|define
name|TOPFULL
value|((FULL) 0x8000000000000000)
end_define

begin_comment
comment|/* highest bit in full value */
end_comment

begin_define
define|#
directive|define
name|MAXLEN
value|((LEN)	0x7fffffffffffffff)
end_define

begin_comment
comment|/* longest value allowed */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* for 32-bit machines */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|HALF
typedef|;
end_typedef

begin_comment
comment|/* unit of number storage */
end_comment

begin_typedef
typedef|typedef
name|short
name|SHALF
typedef|;
end_typedef

begin_comment
comment|/* signed HALF */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|FULL
typedef|;
end_typedef

begin_comment
comment|/* double unit of number storage */
end_comment

begin_typedef
typedef|typedef
name|long
name|LEN
typedef|;
end_typedef

begin_comment
comment|/* unit of length storage */
end_comment

begin_define
define|#
directive|define
name|BASE
value|((FULL) 65536)
end_define

begin_comment
comment|/* base for calculations (2^16) */
end_comment

begin_define
define|#
directive|define
name|BASE1
value|((FULL) (BASE - 1))
end_define

begin_comment
comment|/* one less than base */
end_comment

begin_define
define|#
directive|define
name|BASEB
value|16
end_define

begin_comment
comment|/* number of bits in base */
end_comment

begin_define
define|#
directive|define
name|BASEDIG
value|5
end_define

begin_comment
comment|/* number of digits in base */
end_comment

begin_define
define|#
directive|define
name|MAXHALF
value|((FULL) 0x7fff)
end_define

begin_comment
comment|/* largest positive half value */
end_comment

begin_define
define|#
directive|define
name|MAXFULL
value|((FULL) 0x7fffffff)
end_define

begin_comment
comment|/* largest positive full value */
end_comment

begin_define
define|#
directive|define
name|TOPHALF
value|((FULL) 0x8000)
end_define

begin_comment
comment|/* highest bit in half value */
end_comment

begin_define
define|#
directive|define
name|TOPFULL
value|((FULL) 0x80000000)
end_define

begin_comment
comment|/* highest bit in full value */
end_comment

begin_define
define|#
directive|define
name|MAXLEN
value|((LEN)	0x7fffffff)
end_define

begin_comment
comment|/* longest value allowed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXREDC
value|5
end_define

begin_comment
comment|/* number of entries in REDC cache */
end_comment

begin_define
define|#
directive|define
name|SQ_ALG2
value|20
end_define

begin_comment
comment|/* size for alternative squaring */
end_comment

begin_define
define|#
directive|define
name|MUL_ALG2
value|20
end_define

begin_comment
comment|/* size for alternative multiply */
end_comment

begin_define
define|#
directive|define
name|POW_ALG2
value|40
end_define

begin_comment
comment|/* size for using REDC for powers */
end_comment

begin_define
define|#
directive|define
name|REDC_ALG2
value|50
end_define

begin_comment
comment|/* size for using alternative REDC */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|FULL
name|ivalue
decl_stmt|;
struct|struct
block|{
name|HALF
name|Svalue1
decl_stmt|;
name|HALF
name|Svalue2
decl_stmt|;
block|}
name|sis
struct|;
block|}
name|SIUNION
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LITTLE_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* Least Significant Byte first */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* Most Significant Byte first */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDP_ENDIAN - LSB in word, MSW in long is not supported */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|silow
value|sis.Svalue1
end_define

begin_comment
comment|/* low order half of full value */
end_comment

begin_define
define|#
directive|define
name|sihigh
value|sis.Svalue2
end_define

begin_comment
comment|/* high order half of full value */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|silow
value|sis.Svalue2
end_define

begin_comment
comment|/* low order half of full value */
end_comment

begin_define
define|#
directive|define
name|sihigh
value|sis.Svalue1
end_define

begin_comment
comment|/* high order half of full value */
end_comment

begin_else
else|#
directive|else
end_else

begin_expr_stmt
unit|:@
operator|<
comment|/*/>@:    BYTE_ORDER must be BIG_ENDIAN or LITTLE_ENDIAN    :@</*/
operator|>
expr|@
operator|:
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|HALF
modifier|*
name|v
decl_stmt|;
comment|/* pointer to array of values */
name|LEN
name|len
decl_stmt|;
comment|/* number of values in array */
name|BOOL
name|sign
decl_stmt|;
comment|/* sign, nonzero is negative */
block|}
name|ZVALUE
typedef|;
end_typedef

begin_comment
comment|/*  * Function prototypes for integer math routines.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MATH_PROTO
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MATH_PROTO
parameter_list|(
name|a
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|HALF
modifier|*
name|alloc
name|MATH_PROTO
argument_list|(
operator|(
name|LEN
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOCTEST
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|freeh
name|MATH_PROTO
argument_list|(
operator|(
name|HALF
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
comment|/*  * Input, output, and conversion routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|zcopy
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|itoz
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|i
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|atoz
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|ztoi
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zprintval
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|decimals
operator|,
name|long
name|width
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zprintx
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|width
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zprintb
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|width
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zprinto
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|width
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Basic numeric routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|zmuli
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|n
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zdivi
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|n
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zmodi
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zadd
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zsub
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zmul
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zdiv
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|,
name|ZVALUE
operator|*
name|rem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zquo
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zmod
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|rem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zdivides
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zor
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zand
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zxor
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zshift
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|n
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zsquare
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zlowbit
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zhighbit
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zbitvalue
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|n
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zisset
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zisonebit
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zisallbits
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FLAG
name|ztest
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FLAG
name|zrel
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zcmp
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * More complicated numeric functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|iigcd
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|i1
operator|,
name|long
name|i2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zgcd
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zlcm
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zreduce
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|z1res
operator|,
name|ZVALUE
operator|*
name|z2res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zfact
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|ZVALUE
operator|*
name|dest
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zpfact
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|ZVALUE
operator|*
name|dest
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zlcmfact
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|ZVALUE
operator|*
name|dest
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zperm
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zcomb
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zprimetest
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FLAG
name|zjacobi
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zfib
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zpowi
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ztenpow
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|power
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zpowermod
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
name|z3
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zmodinv
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zrelprime
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zlog
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zlog10
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zdivcount
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zfacrem
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|rem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zgcdrem
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zlowfactor
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|zdigits
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FLAG
name|zdigit
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zsqrt
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
operator|*
name|dest
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zroot
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|dest
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zissquare
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HASH
name|zhash
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
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
unit|extern void zapprox MATH_PROTO((ZVALUE z1, ZVALUE z2, ZVALUE *res1, ZVALUE *res2));
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern void zmulmod MATH_PROTO((ZVALUE z1, ZVALUE z2, ZVALUE z3, ZVALUE *res)); extern void zsquaremod MATH_PROTO((ZVALUE z1, ZVALUE z2, ZVALUE *res)); extern void zsubmod MATH_PROTO((ZVALUE z1, ZVALUE z2, ZVALUE z3, ZVALUE *res));
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|zminmod
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|zcmpmod
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
name|z3
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These functions are for internal use only.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ztrim
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
operator|*
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zshiftr
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zshiftl
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z
operator|,
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HALF
modifier|*
name|zalloctemp
name|MATH_PROTO
argument_list|(
operator|(
name|LEN
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initmasks
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Modulo arithmetic definitions.  * Structure holding state of REDC initialization.  * Multiple instances of this structure can be used allowing  * calculations with more than one modulus at the same time.  * Len of zero means the structure is not initialized.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|LEN
name|len
decl_stmt|;
comment|/* number of words in binary modulus */
name|ZVALUE
name|mod
decl_stmt|;
comment|/* modulus REDC is computing with */
name|ZVALUE
name|inv
decl_stmt|;
comment|/* inverse of modulus in binary modulus */
name|ZVALUE
name|one
decl_stmt|;
comment|/* REDC format for the number 1 */
block|}
name|REDC
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|REDC
modifier|*
name|zredcalloc
name|MATH_PROTO
argument_list|(
operator|(
name|ZVALUE
name|z1
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zredcfree
name|MATH_PROTO
argument_list|(
operator|(
name|REDC
operator|*
name|rp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zredcencode
name|MATH_PROTO
argument_list|(
operator|(
name|REDC
operator|*
name|rp
operator|,
name|ZVALUE
name|z1
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zredcdecode
name|MATH_PROTO
argument_list|(
operator|(
name|REDC
operator|*
name|rp
operator|,
name|ZVALUE
name|z1
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zredcmul
name|MATH_PROTO
argument_list|(
operator|(
name|REDC
operator|*
name|rp
operator|,
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zredcsquare
name|MATH_PROTO
argument_list|(
operator|(
name|REDC
operator|*
name|rp
operator|,
name|ZVALUE
name|z1
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zredcpower
name|MATH_PROTO
argument_list|(
operator|(
name|REDC
operator|*
name|rp
operator|,
name|ZVALUE
name|z1
operator|,
name|ZVALUE
name|z2
operator|,
name|ZVALUE
operator|*
name|res
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * macro expansions to speed this thing up  */
end_comment

begin_define
define|#
directive|define
name|ziseven
parameter_list|(
name|z
parameter_list|)
value|(!(*(z).v& 01))
end_define

begin_define
define|#
directive|define
name|zisodd
parameter_list|(
name|z
parameter_list|)
value|(*(z).v& 01)
end_define

begin_define
define|#
directive|define
name|ziszero
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 0)&& ((z).len == 1))
end_define

begin_define
define|#
directive|define
name|zisneg
parameter_list|(
name|z
parameter_list|)
value|((z).sign)
end_define

begin_define
define|#
directive|define
name|zispos
parameter_list|(
name|z
parameter_list|)
value|(((z).sign == 0)&& (*(z).v || ((z).len> 1)))
end_define

begin_define
define|#
directive|define
name|zisunit
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 1)&& ((z).len == 1))
end_define

begin_define
define|#
directive|define
name|zisone
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 1)&& ((z).len == 1)&& !(z).sign)
end_define

begin_define
define|#
directive|define
name|zisnegone
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 1)&& ((z).len == 1)&& (z).sign)
end_define

begin_define
define|#
directive|define
name|zistwo
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 2)&& ((z).len == 1)&& !(z).sign)
end_define

begin_define
define|#
directive|define
name|zisleone
parameter_list|(
name|z
parameter_list|)
value|((*(z).v<= 1)&& ((z).len == 1))
end_define

begin_define
define|#
directive|define
name|zistiny
parameter_list|(
name|z
parameter_list|)
value|((z).len == 1)
end_define

begin_define
define|#
directive|define
name|zissmall
parameter_list|(
name|z
parameter_list|)
value|(((z).len< 2) || (((z).len == 2)&& (((SHALF)(z).v[1])>= 0)))
end_define

begin_define
define|#
directive|define
name|zisbig
parameter_list|(
name|z
parameter_list|)
value|(((z).len> 2) || (((z).len == 2)&& (((SHALF)(z).v[1])< 0)))
end_define

begin_define
define|#
directive|define
name|z1tol
parameter_list|(
name|z
parameter_list|)
value|((long)((z).v[0]))
end_define

begin_define
define|#
directive|define
name|z2tol
parameter_list|(
name|z
parameter_list|)
value|(((long)((z).v[0])) + \ 				(((long)((z).v[1]& MAXHALF))<< BASEB))
end_define

begin_define
define|#
directive|define
name|zclearval
parameter_list|(
name|z
parameter_list|)
value|memset((z).v, 0, (z).len * sizeof(HALF))
end_define

begin_define
define|#
directive|define
name|zcopyval
parameter_list|(
name|z1
parameter_list|,
name|z2
parameter_list|)
value|memcpy((z2).v, (z1).v, (z1).len * sizeof(HALF))
end_define

begin_define
define|#
directive|define
name|zquicktrim
parameter_list|(
name|z
parameter_list|)
value|{if (((z).len> 1)&& ((z).v[(z).len-1] == 0)) \ 				(z).len--;}
end_define

begin_define
define|#
directive|define
name|zfree
parameter_list|(
name|z
parameter_list|)
value|freeh((z).v)
end_define

begin_comment
comment|/*  * Output modes for numeric displays.  */
end_comment

begin_define
define|#
directive|define
name|MODE_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|MODE_FRAC
value|1
end_define

begin_define
define|#
directive|define
name|MODE_INT
value|2
end_define

begin_define
define|#
directive|define
name|MODE_REAL
value|3
end_define

begin_define
define|#
directive|define
name|MODE_EXP
value|4
end_define

begin_define
define|#
directive|define
name|MODE_HEX
value|5
end_define

begin_define
define|#
directive|define
name|MODE_OCTAL
value|6
end_define

begin_define
define|#
directive|define
name|MODE_BINARY
value|7
end_define

begin_define
define|#
directive|define
name|MODE_MAX
value|7
end_define

begin_define
define|#
directive|define
name|MODE_INITIAL
value|MODE_REAL
end_define

begin_comment
comment|/*  * Output routines for either FILE handles or strings.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|math_chr
name|MATH_PROTO
argument_list|(
operator|(
name|int
name|ch
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|math_str
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|math_fill
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|long
name|width
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|math_flush
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
name|void
name|math_divertio
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
name|void
name|math_cleardiversions
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
name|void
name|math_setfp
name|MATH_PROTO
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|math_getdivertedio
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
name|math_setmode
name|MATH_PROTO
argument_list|(
operator|(
name|int
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|math_setdigits
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|digits
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|math_fmt
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|math_fmt
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The error routine.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|math_error
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|math_error
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * constants used often by the arithmetic routines  */
end_comment

begin_decl_stmt
specifier|extern
name|HALF
name|_zeroval_
index|[]
decl_stmt|,
name|_oneval_
index|[]
decl_stmt|,
name|_twoval_
index|[]
decl_stmt|,
name|_tenval_
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ZVALUE
name|_zero_
decl_stmt|,
name|_one_
decl_stmt|,
name|_ten_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|_math_abort_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero to abort calculations */
end_comment

begin_decl_stmt
specifier|extern
name|ZVALUE
name|_tenpowers_
index|[
literal|2
operator|*
name|BASEB
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of 10^2^n */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_outmode_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current output mode */
end_comment

begin_decl_stmt
specifier|extern
name|LEN
name|_mul2_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of number to use multiply algorithm 2 */
end_comment

begin_decl_stmt
specifier|extern
name|LEN
name|_sq2_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of number to use square algorithm 2 */
end_comment

begin_decl_stmt
specifier|extern
name|LEN
name|_pow2_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of modulus to use REDC for powers */
end_comment

begin_decl_stmt
specifier|extern
name|LEN
name|_redc2_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of modulus to use REDC algorithm 2 */
end_comment

begin_decl_stmt
specifier|extern
name|HALF
modifier|*
name|bitmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bit rotation, norm 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

