begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	manifest.h	4.2	87/12/09	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MANIFEST_
end_ifndef

begin_define
define|#
directive|define
name|_MANIFEST_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"pcclocal.h"
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_define
define|#
directive|define
name|DSIZE
value|(MAXOP+1)
end_define

begin_comment
comment|/* DSIZE is the size of the dope array */
end_comment

begin_define
define|#
directive|define
name|NOLAB
value|(-1)
end_define

begin_comment
comment|/* no label with constant */
end_comment

begin_comment
comment|/*  * Node types  */
end_comment

begin_define
define|#
directive|define
name|LTYPE
value|02
end_define

begin_comment
comment|/* leaf */
end_comment

begin_define
define|#
directive|define
name|UTYPE
value|04
end_define

begin_comment
comment|/* unary */
end_comment

begin_define
define|#
directive|define
name|BITYPE
value|010
end_define

begin_comment
comment|/* binary */
end_comment

begin_comment
comment|/*  * Bogus type values  */
end_comment

begin_define
define|#
directive|define
name|TNULL
value|INCREF(MOETY)
end_define

begin_comment
comment|/* pointer to MOETY -- impossible type */
end_comment

begin_define
define|#
directive|define
name|TVOID
value|FTN
end_define

begin_comment
comment|/* function returning UNDEF (for void) */
end_comment

begin_comment
comment|/*  * Type packing constants  */
end_comment

begin_define
define|#
directive|define
name|TMASK
value|060
end_define

begin_comment
comment|/* mask for 1st component of compound type */
end_comment

begin_define
define|#
directive|define
name|TMASK1
value|0300
end_define

begin_comment
comment|/* mask for 2nd component of compound type */
end_comment

begin_define
define|#
directive|define
name|TMASK2
value|0360
end_define

begin_comment
comment|/* mask for 3rd component of compound type */
end_comment

begin_define
define|#
directive|define
name|BTMASK
value|017
end_define

begin_comment
comment|/* basic type mask */
end_comment

begin_define
define|#
directive|define
name|BTSHIFT
value|4
end_define

begin_comment
comment|/* basic type shift */
end_comment

begin_define
define|#
directive|define
name|TSHIFT
value|2
end_define

begin_comment
comment|/* shift count to get next type component */
end_comment

begin_comment
comment|/*  * Type manipulation macros  */
end_comment

begin_define
define|#
directive|define
name|MODTYPE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x = ((x)&(~BTMASK))|(y)
end_define

begin_comment
comment|/* set basic type of x to y */
end_comment

begin_define
define|#
directive|define
name|BTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)&BTMASK)
end_define

begin_comment
comment|/* basic type of x */
end_comment

begin_define
define|#
directive|define
name|ISUNSIGNED
parameter_list|(
name|x
parameter_list|)
value|((x)<=ULONG&&(x)>=UCHAR)
end_define

begin_define
define|#
directive|define
name|UNSIGNABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<=LONG&&(x)>=CHAR)
end_define

begin_define
define|#
directive|define
name|ENUNSIGN
parameter_list|(
name|x
parameter_list|)
value|((x)+(UNSIGNED-INT))
end_define

begin_define
define|#
directive|define
name|DEUNSIGN
parameter_list|(
name|x
parameter_list|)
value|((x)+(INT-UNSIGNED))
end_define

begin_define
define|#
directive|define
name|ISPTR
parameter_list|(
name|x
parameter_list|)
value|(((x)&TMASK)==PTR)
end_define

begin_define
define|#
directive|define
name|ISFTN
parameter_list|(
name|x
parameter_list|)
value|(((x)&TMASK)==FTN)
end_define

begin_comment
comment|/* is x a function type */
end_comment

begin_define
define|#
directive|define
name|ISARY
parameter_list|(
name|x
parameter_list|)
value|(((x)&TMASK)==ARY)
end_define

begin_comment
comment|/* is x an array type */
end_comment

begin_define
define|#
directive|define
name|INCREF
parameter_list|(
name|x
parameter_list|)
value|((((x)&~BTMASK)<<TSHIFT)|PTR|((x)&BTMASK))
end_define

begin_define
define|#
directive|define
name|DECREF
parameter_list|(
name|x
parameter_list|)
value|((((x)>>TSHIFT)&~BTMASK)|( (x)&BTMASK))
end_define

begin_comment
comment|/* advance x to a multiple of y */
end_comment

begin_define
define|#
directive|define
name|SETOFF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|if ((x)%(y) != 0) (x) = (((x)/(y) + 1) * (y))
end_define

begin_comment
comment|/* can y bits be added to x without overflowing z */
end_comment

begin_define
define|#
directive|define
name|NOFIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)%(z) + (y))> (z))
end_define

begin_comment
comment|/*  * Pack and unpack field descriptors (size and offset)  */
end_comment

begin_define
define|#
directive|define
name|PKFIELD
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|)
value|(((o)<<6)| (s))
end_define

begin_define
define|#
directive|define
name|UPKFSZ
parameter_list|(
name|v
parameter_list|)
value|((v)&077)
end_define

begin_define
define|#
directive|define
name|UPKFOFF
parameter_list|(
name|v
parameter_list|)
value|((v)>>6)
end_define

begin_comment
comment|/*  * Operator information  */
end_comment

begin_define
define|#
directive|define
name|TYFLG
value|016
end_define

begin_define
define|#
directive|define
name|ASGFLG
value|01
end_define

begin_define
define|#
directive|define
name|LOGFLG
value|020
end_define

begin_define
define|#
directive|define
name|SIMPFLG
value|040
end_define

begin_define
define|#
directive|define
name|COMMFLG
value|0100
end_define

begin_define
define|#
directive|define
name|DIVFLG
value|0200
end_define

begin_define
define|#
directive|define
name|FLOFLG
value|0400
end_define

begin_define
define|#
directive|define
name|LTYFLG
value|01000
end_define

begin_define
define|#
directive|define
name|CALLFLG
value|02000
end_define

begin_define
define|#
directive|define
name|MULFLG
value|04000
end_define

begin_define
define|#
directive|define
name|SHFFLG
value|010000
end_define

begin_define
define|#
directive|define
name|ASGOPFLG
value|020000
end_define

begin_define
define|#
directive|define
name|SPFLG
value|040000
end_define

begin_define
define|#
directive|define
name|optype
parameter_list|(
name|o
parameter_list|)
value|(dope[o]&TYFLG)
end_define

begin_define
define|#
directive|define
name|asgop
parameter_list|(
name|o
parameter_list|)
value|(dope[o]&ASGFLG)
end_define

begin_define
define|#
directive|define
name|logop
parameter_list|(
name|o
parameter_list|)
value|(dope[o]&LOGFLG)
end_define

begin_define
define|#
directive|define
name|callop
parameter_list|(
name|o
parameter_list|)
value|(dope[o]&CALLFLG)
end_define

begin_comment
comment|/*  * External declarations, typedefs and the like  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FLEXNAMES
end_ifdef

begin_function_decl
name|char
modifier|*
name|hash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tstr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|tstrused
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tstrbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|curtstr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|freetstr
parameter_list|()
value|curtstr = tstrbuf, tstrused = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|nerrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of errors seen so far */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dope
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a vector containing operator information */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|opst
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a vector containing names for ops */
end_comment

begin_typedef
typedef|typedef
name|union
name|ndu
name|NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|TWORD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NIL
value|(NODE *)0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ONEPASS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|EXPR
end_ifndef

begin_define
define|#
directive|define
name|EXPR
value|'.'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BBEG
end_ifndef

begin_define
define|#
directive|define
name|BBEG
value|'['
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BEND
end_ifndef

begin_define
define|#
directive|define
name|BEND
value|']'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"onepass.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

