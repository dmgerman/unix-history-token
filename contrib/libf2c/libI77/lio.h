begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	copy of ftypes from the compiler */
end_comment

begin_comment
comment|/* variable types  * numeric assumptions:  *	int< reals< complexes  *	TYDREAL-TYREAL = TYDCOMPLEX-TYCOMPLEX  */
end_comment

begin_comment
comment|/* 0-10 retain their old (pre LOGICAL*1, etc.) */
end_comment

begin_comment
comment|/* values to allow mixing old and new objects. */
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
name|TYINT1
value|11
end_define

begin_define
define|#
directive|define
name|TYLOGICAL1
value|12
end_define

begin_define
define|#
directive|define
name|TYLOGICAL2
value|13
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|Allow_TYQUAD
end_ifdef

begin_undef
undef|#
directive|undef
name|TYQUAD
end_undef

begin_define
define|#
directive|define
name|TYQUAD
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINTW
value|24
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

begin_ifdef
ifdef|#
directive|ifdef
name|Old_list_output
end_ifdef

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
value|1.e9
end_define

begin_define
define|#
directive|define
name|LEFMT
value|" %# .8E"
end_define

begin_define
define|#
directive|define
name|LFFMT
value|" %# .9g"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LGFMT
value|"%.9G"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LEFBL 20 should suffice; 24 overcomes a NeXT bug. */
end_comment

begin_define
define|#
directive|define
name|LEFBL
value|24
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|flchar
decl_stmt|;
name|short
name|flshort
decl_stmt|;
name|ftnint
name|flint
decl_stmt|;
ifdef|#
directive|ifdef
name|Allow_TYQUAD
name|longint
name|fllongint
decl_stmt|;
endif|#
directive|endif
name|real
name|flreal
decl_stmt|;
name|doublereal
name|fldouble
decl_stmt|;
block|}
name|flex
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|f__scale
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
specifier|extern
name|int
argument_list|(
operator|*
name|f__lioproc
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|l_getc
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|l_ungetc
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|l_read
argument_list|()
decl_stmt|,
name|l_write
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|int
function_decl|(
modifier|*
name|f__lioproc
function_decl|)
parameter_list|(
name|ftnint
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|ftnlen
parameter_list|,
name|ftnint
parameter_list|)
function_decl|;
specifier|extern
name|int
name|l_write
parameter_list|(
name|ftnint
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|ftnlen
parameter_list|,
name|ftnint
parameter_list|)
function_decl|;
specifier|extern
name|void
name|x_wsne
parameter_list|(
name|cilist
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|c_le
argument_list|(
name|cilist
operator|*
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|l_getc
argument_list|)
argument_list|(
name|void
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|l_ungetc
argument_list|)
argument_list|(
name|int
argument_list|,
name|FILE
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|l_read
parameter_list|(
name|ftnint
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|ftnlen
parameter_list|,
name|ftnint
parameter_list|)
function_decl|;
specifier|extern
name|integer
name|e_rsle
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|e_wsle
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|s_wsne
argument_list|(
name|cilist
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|z_rnew
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|ftnint
name|L_len
decl_stmt|;
end_decl_stmt

end_unit

