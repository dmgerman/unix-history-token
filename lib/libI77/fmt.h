begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|syl
block|{
name|int
name|op
decl_stmt|,
name|p1
decl_stmt|,
name|p2
decl_stmt|,
name|p3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RET1
value|1
end_define

begin_define
define|#
directive|define
name|REVERT
value|2
end_define

begin_define
define|#
directive|define
name|GOTO
value|3
end_define

begin_define
define|#
directive|define
name|X
value|4
end_define

begin_define
define|#
directive|define
name|SLASH
value|5
end_define

begin_define
define|#
directive|define
name|STACK
value|6
end_define

begin_define
define|#
directive|define
name|I
value|7
end_define

begin_define
define|#
directive|define
name|ED
value|8
end_define

begin_define
define|#
directive|define
name|NED
value|9
end_define

begin_define
define|#
directive|define
name|IM
value|10
end_define

begin_define
define|#
directive|define
name|APOS
value|11
end_define

begin_define
define|#
directive|define
name|H
value|12
end_define

begin_define
define|#
directive|define
name|TL
value|13
end_define

begin_define
define|#
directive|define
name|TR
value|14
end_define

begin_define
define|#
directive|define
name|T
value|15
end_define

begin_define
define|#
directive|define
name|COLON
value|16
end_define

begin_define
define|#
directive|define
name|S
value|17
end_define

begin_define
define|#
directive|define
name|SP
value|18
end_define

begin_define
define|#
directive|define
name|SS
value|19
end_define

begin_define
define|#
directive|define
name|P
value|20
end_define

begin_define
define|#
directive|define
name|BN
value|21
end_define

begin_define
define|#
directive|define
name|BZ
value|22
end_define

begin_define
define|#
directive|define
name|F
value|23
end_define

begin_define
define|#
directive|define
name|E
value|24
end_define

begin_define
define|#
directive|define
name|EE
value|25
end_define

begin_define
define|#
directive|define
name|D
value|26
end_define

begin_define
define|#
directive|define
name|G
value|27
end_define

begin_define
define|#
directive|define
name|GE
value|28
end_define

begin_define
define|#
directive|define
name|L
value|29
end_define

begin_define
define|#
directive|define
name|A
value|30
end_define

begin_define
define|#
directive|define
name|AW
value|31
end_define

begin_define
define|#
directive|define
name|O
value|32
end_define

begin_define
define|#
directive|define
name|NONL
value|33
end_define

begin_define
define|#
directive|define
name|OM
value|34
end_define

begin_define
define|#
directive|define
name|Z
value|35
end_define

begin_define
define|#
directive|define
name|ZM
value|36
end_define

begin_decl_stmt
specifier|extern
name|struct
name|syl
name|f__syl
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|f__pc
decl_stmt|,
name|f__parenlvl
decl_stmt|,
name|f__revloc
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
union|union
block|{
name|real
name|pf
decl_stmt|;
name|doublereal
name|pd
decl_stmt|;
block|}
name|ufloat
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|short
name|is
decl_stmt|;
ifndef|#
directive|ifndef
name|KR_headers
name|signed
endif|#
directive|endif
name|char
name|ic
decl_stmt|;
name|integer
name|il
decl_stmt|;
ifdef|#
directive|ifdef
name|Allow_TYQUAD
name|longint
name|ili
decl_stmt|;
endif|#
directive|endif
block|}
name|Uint
typedef|;
end_typedef

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
name|f__doed
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|f__doned
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|f__dorevert
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|rd_ed
argument_list|()
decl_stmt|,
name|rd_ned
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|w_ed
argument_list|()
decl_stmt|,
name|w_ned
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
argument_list|(
operator|*
name|f__doed
argument_list|)
argument_list|(
expr|struct
name|syl
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|ftnlen
argument_list|)
decl_stmt|,
argument_list|(
operator|*
name|f__doned
argument_list|)
argument_list|(
expr|struct
name|syl
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|int
function_decl|(
modifier|*
name|f__dorevert
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|fmt_bg
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|pars_f
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|rd_ed
argument_list|(
expr|struct
name|syl
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|ftnlen
argument_list|)
decl_stmt|,
name|rd_ned
argument_list|(
expr|struct
name|syl
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|w_ed
argument_list|(
expr|struct
name|syl
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|ftnlen
argument_list|)
decl_stmt|,
name|w_ned
argument_list|(
expr|struct
name|syl
operator|*
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|wrt_E
parameter_list|(
name|ufloat
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|ftnlen
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wrt_F
parameter_list|(
name|ufloat
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|ftnlen
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wrt_L
parameter_list|(
name|Uint
modifier|*
parameter_list|,
name|int
parameter_list|,
name|ftnlen
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
name|flag
name|f__cblank
decl_stmt|,
name|f__cplus
decl_stmt|,
name|f__workdone
decl_stmt|,
name|f__nonl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|f__fmtbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|f__scale
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET
parameter_list|(
name|x
parameter_list|)
value|if((x=(*f__getn)())<0) return(x)
end_define

begin_define
define|#
directive|define
name|VAL
parameter_list|(
name|x
parameter_list|)
value|(x!='\n'?x:' ')
end_define

begin_define
define|#
directive|define
name|PUT
parameter_list|(
name|x
parameter_list|)
value|(*f__putn)(x)
end_define

begin_decl_stmt
specifier|extern
name|int
name|f__cursor
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|TYQUAD
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|Allow_TYQUAD
end_ifndef

begin_undef
undef|#
directive|undef
name|longint
end_undef

begin_define
define|#
directive|define
name|longint
value|long
end_define

begin_else
else|#
directive|else
end_else

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

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|f__icvt
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|f__icvt
parameter_list|(
name|longint
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

