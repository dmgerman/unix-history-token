begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	copy of ftypes from the compiler */
end_comment

begin_comment
comment|/* variable types  * numeric assumptions:  *	int< reals< complexes  *	TYDREAL-TYREAL = TYDCOMPLEX-TYCOMPLEX  */
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
name|LINTW
value|12
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
name|LLOGW
value|2
end_define

begin_define
define|#
directive|define
name|LLOW
value|1.0
end_define

begin_define
define|#
directive|define
name|LHIGH
value|10.0
end_define

begin_define
define|#
directive|define
name|LFW
value|12
end_define

begin_define
define|#
directive|define
name|LFD
value|8
end_define

begin_define
define|#
directive|define
name|LEW
value|16
end_define

begin_define
define|#
directive|define
name|LED
value|9
end_define

begin_define
define|#
directive|define
name|LEE
value|2
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

begin_decl_stmt
specifier|extern
name|int
name|scale
decl_stmt|;
end_decl_stmt

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

end_unit

