begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  *  * Data structure declarations for extended precision arithmetic.  * The assumption made is that a long is 32 bits and shorts are 16 bits,  * and longs must be addressible on word boundaries.  */
end_comment

begin_include
include|#
directive|include
file|"alloc.h"
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
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*#define ALLOCTEST 1*/
end_comment

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
value|((p == _zeroval_) || (p == _oneval_) || free(p))
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
value|{ if ((p != _zeroval_)&& (p != _oneval_)) free((void *)p); }
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
name|short
name|FLAG
typedef|;
end_typedef

begin_comment
comment|/* small value (e.g. comparison) */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|BOOL
typedef|;
end_typedef

begin_comment
comment|/* TRUE or FALSE value */
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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

begin_decl_stmt
specifier|extern
name|long
name|iigcd
name|proto
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
name|itoz
name|proto
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
name|long
name|ztoi
name|proto
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
name|zcopy
name|proto
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
name|zadd
name|proto
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
name|proto
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
name|proto
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
name|zsquare
name|proto
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
name|zreduce
name|proto
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
name|zdiv
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|zlowbit
name|proto
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
name|proto
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
name|zisset
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|FLAG
name|ztest
name|proto
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
name|proto
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
name|proto
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
name|trim
name|proto
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
name|shiftr
name|proto
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
name|shiftl
name|proto
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
name|zfact
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|zgcd
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|zmuli
name|proto
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
name|proto
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
name|long
name|zdivi
name|proto
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
name|HALF
modifier|*
name|zalloctemp
name|proto
argument_list|(
operator|(
name|LEN
name|len
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
unit|extern void zapprox proto((ZVALUE z1, ZVALUE z2, ZVALUE* res1, ZVALUE* res2));
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern void zmulmod proto((ZVALUE z1, ZVALUE z2, ZVALUE z3, ZVALUE *res)); extern void zsquaremod proto((ZVALUE z1, ZVALUE z2, ZVALUE *res)); extern void zsubmod proto((ZVALUE z1, ZVALUE z2, ZVALUE z3, ZVALUE *res));
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|zminmod
name|proto
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
name|proto
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

begin_decl_stmt
specifier|extern
name|REDC
modifier|*
name|zredcalloc
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
name|proto
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
comment|/*  * Rational arithmetic definitions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ZVALUE
name|num
decl_stmt|,
name|den
decl_stmt|;
name|long
name|links
decl_stmt|;
block|}
name|NUMBER
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qadd
argument_list|()
decl_stmt|,
modifier|*
name|qsub
argument_list|()
decl_stmt|,
modifier|*
name|qmul
argument_list|()
decl_stmt|,
modifier|*
name|qdiv
argument_list|()
decl_stmt|,
modifier|*
name|qquo
argument_list|()
decl_stmt|,
modifier|*
name|qmod
argument_list|()
decl_stmt|,
modifier|*
name|qcomb
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qsquare
argument_list|()
decl_stmt|,
modifier|*
name|qgcd
argument_list|()
decl_stmt|,
modifier|*
name|qlcm
argument_list|()
decl_stmt|,
modifier|*
name|qmin
argument_list|()
decl_stmt|,
modifier|*
name|qmax
argument_list|()
decl_stmt|,
modifier|*
name|qand
argument_list|()
decl_stmt|,
modifier|*
name|qor
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qxor
argument_list|()
decl_stmt|,
modifier|*
name|qpowermod
argument_list|()
decl_stmt|,
modifier|*
name|qpowi
argument_list|()
decl_stmt|,
modifier|*
name|qpower
argument_list|()
decl_stmt|,
modifier|*
name|qneg
argument_list|()
decl_stmt|,
modifier|*
name|qsign
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qfact
argument_list|()
decl_stmt|,
modifier|*
name|qpfact
argument_list|()
decl_stmt|,
modifier|*
name|qsqrt
argument_list|()
decl_stmt|,
modifier|*
name|qshift
argument_list|()
decl_stmt|,
modifier|*
name|qminv
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qint
argument_list|()
decl_stmt|,
modifier|*
name|qfrac
argument_list|()
decl_stmt|,
modifier|*
name|qnum
argument_list|()
decl_stmt|,
modifier|*
name|qden
argument_list|()
decl_stmt|,
modifier|*
name|qinv
argument_list|()
decl_stmt|,
modifier|*
name|qabs
argument_list|()
decl_stmt|,
modifier|*
name|qroot
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qfacrem
argument_list|()
decl_stmt|,
modifier|*
name|qcopy
argument_list|()
decl_stmt|,
modifier|*
name|atoq
argument_list|()
decl_stmt|,
modifier|*
name|itoq
argument_list|()
decl_stmt|,
modifier|*
name|iitoq
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qperm
argument_list|()
decl_stmt|,
modifier|*
name|qgcdrem
argument_list|()
decl_stmt|,
modifier|*
name|qtrunc
argument_list|()
decl_stmt|,
modifier|*
name|qround
argument_list|()
decl_stmt|,
modifier|*
name|qalloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qlowfactor
argument_list|()
decl_stmt|,
modifier|*
name|qfib
argument_list|()
decl_stmt|,
modifier|*
name|qcfappr
argument_list|()
decl_stmt|,
modifier|*
name|qcos
argument_list|()
decl_stmt|,
modifier|*
name|qsin
argument_list|()
decl_stmt|,
modifier|*
name|qexp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qscale
argument_list|()
decl_stmt|,
modifier|*
name|qln
argument_list|()
decl_stmt|,
modifier|*
name|qbtrunc
argument_list|()
decl_stmt|,
modifier|*
name|qbround
argument_list|()
decl_stmt|,
modifier|*
name|qisqrt
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qtan
argument_list|()
decl_stmt|,
modifier|*
name|qacos
argument_list|()
decl_stmt|,
modifier|*
name|qasin
argument_list|()
decl_stmt|,
modifier|*
name|qatan
argument_list|()
decl_stmt|,
modifier|*
name|qatan2
argument_list|()
decl_stmt|,
modifier|*
name|qjacobi
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qinc
argument_list|()
decl_stmt|,
modifier|*
name|qdec
argument_list|()
decl_stmt|,
modifier|*
name|qhypot
argument_list|()
decl_stmt|,
modifier|*
name|qcosh
argument_list|()
decl_stmt|,
modifier|*
name|qsinh
argument_list|()
decl_stmt|,
modifier|*
name|qtanh
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qacosh
argument_list|()
decl_stmt|,
modifier|*
name|qasinh
argument_list|()
decl_stmt|,
modifier|*
name|qatanh
argument_list|()
decl_stmt|,
modifier|*
name|qlegtoleg
argument_list|()
decl_stmt|,
modifier|*
name|qiroot
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qpi
argument_list|()
decl_stmt|,
modifier|*
name|qbappr
argument_list|()
decl_stmt|,
modifier|*
name|qdivi
argument_list|()
decl_stmt|,
modifier|*
name|qlcmfact
argument_list|()
decl_stmt|,
modifier|*
name|qminmod
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|qredcin
argument_list|()
decl_stmt|,
modifier|*
name|qredcout
argument_list|()
decl_stmt|,
modifier|*
name|qredcmul
argument_list|()
decl_stmt|,
modifier|*
name|qredcsquare
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|NUMBER
modifier|*
name|qredcpower
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|BOOL
name|qcmp
argument_list|()
decl_stmt|,
name|qcmpi
argument_list|()
decl_stmt|,
name|qprimetest
argument_list|()
decl_stmt|,
name|qissquare
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|qisset
argument_list|()
decl_stmt|,
name|qcmpmod
argument_list|()
decl_stmt|,
name|qquomod
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FLAG
name|qrel
argument_list|()
decl_stmt|,
name|qreli
argument_list|()
decl_stmt|,
name|qnear
argument_list|()
decl_stmt|,
name|qdigit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|qtoi
argument_list|()
decl_stmt|,
name|qprecision
argument_list|()
decl_stmt|,
name|qplaces
argument_list|()
decl_stmt|,
name|qdigits
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|qilog2
argument_list|()
decl_stmt|,
name|qilog10
argument_list|()
decl_stmt|,
name|qparse
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|qfreenum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qprintnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setepsilon
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern NUMBER *qbitvalue(), *qmuli(), *qmulmod(), *qsquaremod(); extern NUMBER *qaddmod(), *qsubmod(), *qreadval(), *qnegmod(); extern BOOL qbittest(); extern FLAG qtest();
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CODE
end_ifdef

begin_function_decl
specifier|extern
name|NUMBER
modifier|*
name|qaddi
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Complex arithmetic definitions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|NUMBER
modifier|*
name|real
decl_stmt|;
comment|/* real part of number */
name|NUMBER
modifier|*
name|imag
decl_stmt|;
comment|/* imaginary part of number */
name|long
name|links
decl_stmt|;
comment|/* link count */
block|}
name|COMPLEX
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|COMPLEX
modifier|*
name|cadd
argument_list|()
decl_stmt|,
modifier|*
name|csub
argument_list|()
decl_stmt|,
modifier|*
name|cmul
argument_list|()
decl_stmt|,
modifier|*
name|cdiv
argument_list|()
decl_stmt|,
modifier|*
name|csquare
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|COMPLEX
modifier|*
name|cneg
argument_list|()
decl_stmt|,
modifier|*
name|cinv
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|COMPLEX
modifier|*
name|comalloc
argument_list|()
decl_stmt|,
modifier|*
name|caddq
argument_list|()
decl_stmt|,
modifier|*
name|csubq
argument_list|()
decl_stmt|,
modifier|*
name|cmulq
argument_list|()
decl_stmt|,
modifier|*
name|cdivq
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|COMPLEX
modifier|*
name|cpowi
argument_list|()
decl_stmt|,
modifier|*
name|csqrt
argument_list|()
decl_stmt|,
modifier|*
name|cscale
argument_list|()
decl_stmt|,
modifier|*
name|cshift
argument_list|()
decl_stmt|,
modifier|*
name|cround
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|COMPLEX
modifier|*
name|cbround
argument_list|()
decl_stmt|,
modifier|*
name|cint
argument_list|()
decl_stmt|,
modifier|*
name|cfrac
argument_list|()
decl_stmt|,
modifier|*
name|croot
argument_list|()
decl_stmt|,
modifier|*
name|cexp
argument_list|()
decl_stmt|,
modifier|*
name|cln
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|COMPLEX
modifier|*
name|ccos
argument_list|()
decl_stmt|,
modifier|*
name|csin
argument_list|()
decl_stmt|,
modifier|*
name|cpolar
argument_list|()
decl_stmt|,
modifier|*
name|cpower
argument_list|()
decl_stmt|,
modifier|*
name|cmodq
argument_list|()
decl_stmt|,
modifier|*
name|cquoq
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|comfree
argument_list|()
decl_stmt|,
name|comprint
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|BOOL
name|ccmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cprintfr
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern COMPLEX *cconj(), *creal(), *cimag(), *qqtoc();
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * macro expansions to speed this thing up  */
end_comment

begin_define
define|#
directive|define
name|iseven
parameter_list|(
name|z
parameter_list|)
value|(!(*(z).v& 01))
end_define

begin_define
define|#
directive|define
name|isodd
parameter_list|(
name|z
parameter_list|)
value|(*(z).v& 01)
end_define

begin_define
define|#
directive|define
name|iszero
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 0)&& ((z).len == 1))
end_define

begin_define
define|#
directive|define
name|isneg
parameter_list|(
name|z
parameter_list|)
value|((z).sign)
end_define

begin_define
define|#
directive|define
name|ispos
parameter_list|(
name|z
parameter_list|)
value|(((z).sign == 0)&& (*(z).v || ((z).len> 1)))
end_define

begin_define
define|#
directive|define
name|isunit
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 1)&& ((z).len == 1))
end_define

begin_define
define|#
directive|define
name|isone
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 1)&& ((z).len == 1)&& !(z).sign)
end_define

begin_define
define|#
directive|define
name|isnegone
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 1)&& ((z).len == 1)&& (z).sign)
end_define

begin_define
define|#
directive|define
name|istwo
parameter_list|(
name|z
parameter_list|)
value|((*(z).v == 2)&& ((z).len == 1)&& !(z).sign)
end_define

begin_define
define|#
directive|define
name|isleone
parameter_list|(
name|z
parameter_list|)
value|((*(z).v<= 1)&& ((z).len == 1))
end_define

begin_define
define|#
directive|define
name|istiny
parameter_list|(
name|z
parameter_list|)
value|((z).len == 1)
end_define

begin_define
define|#
directive|define
name|issmall
parameter_list|(
name|z
parameter_list|)
value|(((z).len< 2) || (((z).len == 2)&& (((short)(z).v[1])>= 0)))
end_define

begin_define
define|#
directive|define
name|isbig
parameter_list|(
name|z
parameter_list|)
value|(((z).len> 2) || (((z).len == 2)&& (((short)(z).v[1])< 0)))
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
name|qiszero
parameter_list|(
name|q
parameter_list|)
value|(iszero((q)->num))
end_define

begin_define
define|#
directive|define
name|qisneg
parameter_list|(
name|q
parameter_list|)
value|(isneg((q)->num))
end_define

begin_define
define|#
directive|define
name|qispos
parameter_list|(
name|q
parameter_list|)
value|(ispos((q)->num))
end_define

begin_define
define|#
directive|define
name|qisint
parameter_list|(
name|q
parameter_list|)
value|(isunit((q)->den))
end_define

begin_define
define|#
directive|define
name|qisfrac
parameter_list|(
name|q
parameter_list|)
value|(!isunit((q)->den))
end_define

begin_define
define|#
directive|define
name|qisunit
parameter_list|(
name|q
parameter_list|)
value|(isunit((q)->num)&& isunit((q)->den))
end_define

begin_define
define|#
directive|define
name|qisone
parameter_list|(
name|q
parameter_list|)
value|(isone((q)->num)&& isunit((q)->den))
end_define

begin_define
define|#
directive|define
name|qisnegone
parameter_list|(
name|q
parameter_list|)
value|(isnegone((q)->num)&& isunit((q)->den))
end_define

begin_define
define|#
directive|define
name|qistwo
parameter_list|(
name|q
parameter_list|)
value|(istwo((q)->num)&& isunit((q)->den))
end_define

begin_define
define|#
directive|define
name|qiseven
parameter_list|(
name|q
parameter_list|)
value|(isunit((q)->den)&& iseven((q)->num))
end_define

begin_define
define|#
directive|define
name|qisodd
parameter_list|(
name|q
parameter_list|)
value|(isunit((q)->den)&& isodd((q)->num))
end_define

begin_define
define|#
directive|define
name|qistwopower
parameter_list|(
name|q
parameter_list|)
value|(isunit((q)->den)&& zistwopower((q)->num))
end_define

begin_define
define|#
directive|define
name|qhighbit
parameter_list|(
name|q
parameter_list|)
value|(zhighbit((q)->num))
end_define

begin_define
define|#
directive|define
name|qlowbit
parameter_list|(
name|q
parameter_list|)
value|(zlowbit((q)->num))
end_define

begin_define
define|#
directive|define
name|qdivides
parameter_list|(
name|q1
parameter_list|,
name|q2
parameter_list|)
value|(zdivides((q1)->num, (q2)->num))
end_define

begin_define
define|#
directive|define
name|qdivcount
parameter_list|(
name|q1
parameter_list|,
name|q2
parameter_list|)
value|(zdivcount((q1)->num, (q2)->num))
end_define

begin_define
define|#
directive|define
name|qilog
parameter_list|(
name|q1
parameter_list|,
name|q2
parameter_list|)
value|(zlog((q1)->num, (q2)->num))
end_define

begin_define
define|#
directive|define
name|qlink
parameter_list|(
name|q
parameter_list|)
value|((q)->links++, (q))
end_define

begin_define
define|#
directive|define
name|qfree
parameter_list|(
name|q
parameter_list|)
value|{if (--((q)->links)<= 0) qfreenum(q);}
end_define

begin_define
define|#
directive|define
name|quicktrim
parameter_list|(
name|z
parameter_list|)
value|{if (((z).len> 1)&& ((z).v[(z).len-1] == 0)) (z).len--;}
end_define

begin_define
define|#
directive|define
name|cisreal
parameter_list|(
name|c
parameter_list|)
value|(qiszero((c)->imag))
end_define

begin_define
define|#
directive|define
name|cisimag
parameter_list|(
name|c
parameter_list|)
value|(qiszero((c)->real)&& !cisreal(c))
end_define

begin_define
define|#
directive|define
name|ciszero
parameter_list|(
name|c
parameter_list|)
value|(cisreal(c)&& qiszero((c)->real))
end_define

begin_define
define|#
directive|define
name|cisone
parameter_list|(
name|c
parameter_list|)
value|(cisreal(c)&& qisone((c)->real))
end_define

begin_define
define|#
directive|define
name|cisnegone
parameter_list|(
name|c
parameter_list|)
value|(cisreal(c)&& qisnegone((c)->real))
end_define

begin_define
define|#
directive|define
name|cisrunit
parameter_list|(
name|c
parameter_list|)
value|(cisreal(c)&& qisunit((c)->real))
end_define

begin_define
define|#
directive|define
name|cisiunit
parameter_list|(
name|c
parameter_list|)
value|(qiszero((c)->real)&& qisunit((c)->imag))
end_define

begin_define
define|#
directive|define
name|cistwo
parameter_list|(
name|c
parameter_list|)
value|(cisreal(c)&& qistwo((c)->real))
end_define

begin_define
define|#
directive|define
name|cisint
parameter_list|(
name|c
parameter_list|)
value|(qisint((c)->real)&& qisint((c)->imag))
end_define

begin_define
define|#
directive|define
name|ciseven
parameter_list|(
name|c
parameter_list|)
value|(qiseven((c)->real)&& qiseven((c)->imag))
end_define

begin_define
define|#
directive|define
name|cisodd
parameter_list|(
name|c
parameter_list|)
value|(qisodd((c)->real) || qisodd((c)->imag))
end_define

begin_define
define|#
directive|define
name|clink
parameter_list|(
name|c
parameter_list|)
value|((c)->links++, (c))
end_define

begin_define
define|#
directive|define
name|clearval
parameter_list|(
name|z
parameter_list|)
value|memset((z).v, 0, (z).len * sizeof(HALF))
end_define

begin_define
define|#
directive|define
name|copyval
parameter_list|(
name|z1
parameter_list|,
name|z2
parameter_list|)
value|memcpy((z2).v, (z1).v, (z1).len * sizeof(HALF))
end_define

begin_comment
comment|/*  * Flags for qparse calls  */
end_comment

begin_define
define|#
directive|define
name|QPF_SLASH
value|0x1
end_define

begin_comment
comment|/* allow slash for fractional number */
end_comment

begin_define
define|#
directive|define
name|QPF_IMAG
value|0x2
end_define

begin_comment
comment|/* allow trailing 'i' for imaginary number */
end_comment

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
argument_list|()
decl_stmt|,
name|math_str
argument_list|()
decl_stmt|,
name|math_flush
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|divertio
argument_list|()
decl_stmt|,
name|cleardiversions
argument_list|()
decl_stmt|,
name|setfp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|getdivertedio
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_mode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set output mode for numeric output */
end_comment

begin_function_decl
specifier|extern
name|void
name|setdigits
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set # of digits for float or exp output */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|math_fmt
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|math_fmt
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Print a formatted string containing arbitrary numbers, similar to printf.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|qprintf
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|qprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|qprintf
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
name|NUMBER
name|_qzero_
decl_stmt|,
name|_qone_
decl_stmt|,
name|_qnegone_
decl_stmt|,
name|_qonehalf_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|COMPLEX
name|_czero_
decl_stmt|,
name|_cone_
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern NUMBER _conei_;
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|BOOL
name|_sinisneg_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whether sin(x)< 0 (set by cos(x)) */
end_comment

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
name|long
name|_epsilonprec_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* binary precision of epsilon */
end_comment

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|_epsilon_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default error for real functions */
end_comment

begin_decl_stmt
specifier|extern
name|ZVALUE
name|_tenpowers_
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of 10^2^n */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_outdigits_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current output digits for float or exp */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|extern char *_mallocptr_;
comment|/* pointer for malloc calls */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * misc function declarations - most to keep lint happy  */
end_comment

begin_function_decl
specifier|extern
name|void
name|initmasks
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* init the bitmask rotation arrays */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|error
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

