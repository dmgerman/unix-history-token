begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)lio.h	5.2 (Berkeley) 7/30/85  */
end_comment

begin_comment
comment|/*  * copy of ftypes from the compiler  * variable types numeric assumptions:  *	int< reals< complexes  *	TYDREAL-TYREAL = TYDCOMPLEX-TYCOMPLEX  */
end_comment

begin_define
define|#
directive|define
name|TYUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|TYADDR
value|1
end_define

begin_define
define|#
directive|define
name|TYSHORT
value|2
end_define

begin_define
define|#
directive|define
name|TYLONG
value|3
end_define

begin_define
define|#
directive|define
name|TYREAL
value|4
end_define

begin_define
define|#
directive|define
name|TYDREAL
value|5
end_define

begin_define
define|#
directive|define
name|TYCOMPLEX
value|6
end_define

begin_define
define|#
directive|define
name|TYDCOMPLEX
value|7
end_define

begin_define
define|#
directive|define
name|TYLOGICAL
value|8
end_define

begin_define
define|#
directive|define
name|TYCHAR
value|9
end_define

begin_define
define|#
directive|define
name|TYSUBR
value|10
end_define

begin_define
define|#
directive|define
name|TYERROR
value|11
end_define

begin_define
define|#
directive|define
name|NTYPES
value|(TYERROR+1)
end_define

begin_define
define|#
directive|define
name|LINE
value|80
end_define

begin_define
define|#
directive|define
name|LINTW
value|(strlen(buf))
end_define

begin_define
define|#
directive|define
name|LLOGW
value|3
end_define

begin_define
define|#
directive|define
name|LSTRW
value|(len+2)
end_define

begin_define
define|#
directive|define
name|LLOW
value|1.0e-1
end_define

begin_define
define|#
directive|define
name|LHIGH
value|1.0e+LFD
end_define

begin_define
define|#
directive|define
name|LDHIGH
value|1.0e+LDFD
end_define

begin_define
define|#
directive|define
name|LFD
value|6
end_define

begin_define
define|#
directive|define
name|LFW
value|(LFD+4)
end_define

begin_define
define|#
directive|define
name|LDFD
value|14
end_define

begin_define
define|#
directive|define
name|LDFW
value|(LDFD+4)
end_define

begin_define
define|#
directive|define
name|LED
value|LFD
end_define

begin_define
define|#
directive|define
name|LEW
value|LFW+4
end_define

begin_define
define|#
directive|define
name|LEE
value|2
end_define

begin_define
define|#
directive|define
name|LDED
value|LDFD
end_define

begin_define
define|#
directive|define
name|LDEW
value|LDFW+4
end_define

begin_define
define|#
directive|define
name|LDEE
value|2
end_define

begin_define
define|#
directive|define
name|LCW
value|(width(a)+width(b)+5)
end_define

begin_define
define|#
directive|define
name|LDCW
value|(dwidth(a)+dwidth(b)+5)
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|z
parameter_list|)
value|(z<0?-z:z)
end_define

begin_define
define|#
directive|define
name|width
parameter_list|(
name|z
parameter_list|)
value|((z!=0.0&& (abs(z)>=LHIGH || abs(z)<LLOW))?LEW:LFW)
end_define

begin_define
define|#
directive|define
name|dwidth
parameter_list|(
name|z
parameter_list|)
value|((z!=0.0&& (abs(z)>=LDHIGH || abs(z)<LLOW))?LDEW:LDFW)
end_define

begin_define
define|#
directive|define
name|ERR
parameter_list|(
name|x
parameter_list|)
value|if(n=(x)) err(n>0?errflag:endflag,n,"list io")
end_define

begin_define
define|#
directive|define
name|ERRCHK
parameter_list|(
name|x
parameter_list|)
value|if(n=(x)) goto got_err;
end_define

begin_define
define|#
directive|define
name|chk_len
parameter_list|(
name|w
parameter_list|)
value|if(recpos+w> line_len) PUT('\n');
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|short
name|flshort
decl_stmt|;
name|ftnint
name|flint
decl_stmt|;
name|float
name|flreal
decl_stmt|;
name|double
name|fldouble
decl_stmt|;
block|}
name|flex
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|lioproc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|flag
name|leof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ioflag
name|lquit
decl_stmt|,
name|l_first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lcount
decl_stmt|,
name|line_len
decl_stmt|;
end_decl_stmt

end_unit

