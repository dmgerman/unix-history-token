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
name|RET
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

begin_decl_stmt
specifier|extern
name|struct
name|syl
name|syl
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pc
decl_stmt|,
name|parenlvl
decl_stmt|,
name|revloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
argument_list|(
operator|*
name|doed
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|doned
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
argument_list|(
operator|*
name|dorevert
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|donewrec
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|doend
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|cblank
decl_stmt|,
name|cplus
decl_stmt|,
name|workdone
decl_stmt|,
name|nonl
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|dummy
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fmtbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scale
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|pf
decl_stmt|;
name|double
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
name|char
name|ic
decl_stmt|;
name|long
name|il
decl_stmt|;
block|}
name|uint
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GET
parameter_list|(
name|x
parameter_list|)
value|if((x=(*getn)())<0) return(x)
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
value|(*putn)(x)
end_define

begin_decl_stmt
specifier|extern
name|int
name|cursor
decl_stmt|;
end_decl_stmt

end_unit

