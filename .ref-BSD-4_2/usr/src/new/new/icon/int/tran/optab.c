begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_comment
comment|/*  * state tables for operator recognition  */
end_comment

begin_decl_stmt
name|struct
name|optab
name|state0
index|[]
init|=
block|{
comment|/* initial state */
block|{
literal|','
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|59
index|]
block|}
block|,
comment|/* ","     */
block|{
literal|'.'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|63
index|]
block|}
block|,
comment|/* "."     */
block|{
literal|'['
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|70
index|]
block|}
block|,
comment|/* "["     */
block|{
literal|']'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|99
index|]
block|}
block|,
comment|/* "]"     */
block|{
literal|'('
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|79
index|]
block|}
block|,
comment|/* "("     */
block|{
literal|')'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|100
index|]
block|}
block|,
comment|/* ")"     */
block|{
literal|';'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|101
index|]
block|}
block|,
comment|/* ";"     */
block|{
literal|'{'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|69
index|]
block|}
block|,
comment|/* "{"     */
block|{
literal|'}'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|98
index|]
block|}
block|,
comment|/* "}"     */
block|{
literal|'!'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|54
index|]
block|}
block|,
comment|/* "!"     */
block|{
literal|'\\'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|53
index|]
block|}
block|,
comment|/* "\\"    */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state1
block|}
block|,
comment|/* ":" ... */
block|{
literal|'<'
block|,
name|A_GOTO
block|,
name|state2
block|}
block|,
comment|/* "<" ... */
block|{
literal|'>'
block|,
name|A_GOTO
block|,
name|state4
block|}
block|,
comment|/* ">" ... */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state5
block|}
block|,
comment|/* "=" ... */
block|{
literal|'|'
block|,
name|A_GOTO
block|,
name|state3
block|}
block|,
comment|/* "|" ... */
block|{
literal|'+'
block|,
name|A_GOTO
block|,
name|state7
block|}
block|,
comment|/* "+" ... */
block|{
literal|'-'
block|,
name|A_GOTO
block|,
name|state8
block|}
block|,
comment|/* "-" ... */
block|{
literal|'*'
block|,
name|A_GOTO
block|,
name|state9
block|}
block|,
comment|/* "*" ... */
block|{
literal|'^'
block|,
name|A_GOTO
block|,
name|state6
block|}
block|,
comment|/* "^" ... */
block|{
literal|'~'
block|,
name|A_GOTO
block|,
name|state29
block|}
block|,
comment|/* "~" ... */
block|{
literal|'/'
block|,
name|A_GOTO
block|,
name|state21
block|}
block|,
comment|/* "/" ... */
block|{
literal|'%'
block|,
name|A_GOTO
block|,
name|state30
block|}
block|,
comment|/* "%" ... */
block|{
literal|'?'
block|,
name|A_GOTO
block|,
name|state36
block|}
block|,
comment|/* "?" ... */
block|{
literal|'&'
block|,
name|A_GOTO
block|,
name|state38
block|}
block|,
comment|/* "&" ... */
block|{
literal|'@'
block|,
name|A_GOTO
block|,
name|state40
block|}
block|,
comment|/* "@" ... */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state1
index|[]
init|=
block|{
comment|/* ":" */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state10
block|}
block|,
comment|/* ":=" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|58
index|]
block|}
comment|/* ":"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state2
index|[]
init|=
block|{
comment|/* "<" */
block|{
literal|'-'
block|,
name|A_GOTO
block|,
name|state11
block|}
block|,
comment|/* "<-" ... */
block|{
literal|'<'
block|,
name|A_GOTO
block|,
name|state32
block|}
block|,
comment|/* "<<" ... */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state46
block|}
block|,
comment|/* "<:" ... */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state56
block|}
block|,
comment|/* "<=" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|90
index|]
block|}
comment|/* "<"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state3
index|[]
init|=
block|{
comment|/* "|" */
block|{
literal|'|'
block|,
name|A_GOTO
block|,
name|state22
block|}
block|,
comment|/* "||" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|55
index|]
block|}
comment|/* "|"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state4
index|[]
init|=
block|{
comment|/* ">" */
block|{
literal|'>'
block|,
name|A_GOTO
block|,
name|state33
block|}
block|,
comment|/* ">>" ... */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state44
block|}
block|,
comment|/* ">:" ... */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state57
block|}
block|,
comment|/* ">=" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|88
index|]
block|}
comment|/* ">"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state5
index|[]
init|=
block|{
comment|/* "=" */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state12
block|}
block|,
comment|/* "==" ... */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state42
block|}
block|,
comment|/* "=:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|86
index|]
block|}
comment|/* "="      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state6
index|[]
init|=
block|{
comment|/* "^" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state23
block|}
block|,
comment|/* "^:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|56
index|]
block|}
comment|/* "^"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state7
index|[]
init|=
block|{
comment|/* "+" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state15
block|}
block|,
comment|/* "+:" ... */
block|{
literal|'+'
block|,
name|A_GOTO
block|,
name|state16
block|}
block|,
comment|/* "++" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|93
index|]
block|}
comment|/* "+"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state8
index|[]
init|=
block|{
comment|/* "-" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state17
block|}
block|,
comment|/* "-:" ... */
block|{
literal|'-'
block|,
name|A_GOTO
block|,
name|state18
block|}
block|,
comment|/* "--" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|81
index|]
block|}
comment|/* "-"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state9
index|[]
init|=
block|{
comment|/* "*" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state19
block|}
block|,
comment|/* "*:" ... */
block|{
literal|'*'
block|,
name|A_GOTO
block|,
name|state20
block|}
block|,
comment|/* "**" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|105
index|]
block|}
comment|/* "*"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state10
index|[]
init|=
block|{
comment|/* ":=" */
block|{
literal|':'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|107
index|]
block|}
block|,
comment|/* ":=:" */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|35
index|]
block|}
comment|/* ":="  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state11
index|[]
init|=
block|{
comment|/* "<-" */
block|{
literal|'>'
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|97
index|]
block|}
block|,
comment|/* "<->" */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|96
index|]
block|}
comment|/* "<-"  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state12
index|[]
init|=
block|{
comment|/* "==" */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state61
block|}
block|,
comment|/* "===" ... */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state48
block|}
block|,
comment|/* "==:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|73
index|]
block|}
comment|/* "=="  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state13
index|[]
init|=
block|{
comment|/* "~=" */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state14
block|}
block|,
comment|/* "~==" ... */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state43
block|}
block|,
comment|/* "~=:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|91
index|]
block|}
comment|/* "~="      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state14
index|[]
init|=
block|{
comment|/* "~==" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state49
block|}
block|,
comment|/* "~==:" ... */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state60
block|}
block|,
comment|/* "~===" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|78
index|]
block|}
comment|/* "~=="  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state15
index|[]
init|=
block|{
comment|/* "+:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|94
index|]
block|}
block|,
comment|/* "+:=" */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|92
index|]
block|}
comment|/* "+:"  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state16
index|[]
init|=
block|{
comment|/* "++" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state24
block|}
block|,
comment|/* "++:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|109
index|]
block|}
comment|/* "++"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state17
index|[]
init|=
block|{
comment|/* "-:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|82
index|]
block|}
block|,
comment|/* "-:=" */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|80
index|]
block|}
comment|/* "-:"  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state18
index|[]
init|=
block|{
comment|/* "--" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state25
block|}
block|,
comment|/* "--:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|64
index|]
block|}
comment|/* "--" */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state19
index|[]
init|=
block|{
comment|/* "*:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|106
index|]
block|}
block|,
comment|/* "*:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state20
index|[]
init|=
block|{
comment|/* "**" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state26
block|}
block|,
comment|/* "**:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|67
index|]
block|}
comment|/* "**"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state21
index|[]
init|=
block|{
comment|/* "/" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state27
block|}
block|,
comment|/* "/:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|103
index|]
block|}
comment|/* "/"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state22
index|[]
init|=
block|{
comment|/* "||" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state28
block|}
block|,
comment|/* "||:" ... */
block|{
literal|'|'
block|,
name|A_GOTO
block|,
name|state34
block|}
block|,
comment|/* "|||" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|60
index|]
block|}
comment|/* "||"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state23
index|[]
init|=
block|{
comment|/* "^:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|57
index|]
block|}
block|,
comment|/* "^:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state24
index|[]
init|=
block|{
comment|/* "++:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|110
index|]
block|}
block|,
comment|/* "++:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state25
index|[]
init|=
block|{
comment|/* "--:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|65
index|]
block|}
block|,
comment|/* "--:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state26
index|[]
init|=
block|{
comment|/* "**:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|68
index|]
block|}
block|,
comment|/* "**:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state27
index|[]
init|=
block|{
comment|/* "/:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|104
index|]
block|}
block|,
comment|/* "/:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state28
index|[]
init|=
block|{
comment|/* "||:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|61
index|]
block|}
block|,
comment|/* "||:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state29
index|[]
init|=
block|{
comment|/* "~" */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state13
block|}
block|,
comment|/* "~=" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|108
index|]
block|}
comment|/* "~"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state30
index|[]
init|=
block|{
comment|/* "%" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state31
block|}
block|,
comment|/* "%:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|83
index|]
block|}
comment|/* "%"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state31
index|[]
init|=
block|{
comment|/* "%:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|84
index|]
block|}
block|,
comment|/* "%:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state32
index|[]
init|=
block|{
comment|/* "<<" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state52
block|}
block|,
comment|/* "<<:" ... */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state58
block|}
block|,
comment|/* "<<=" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|77
index|]
block|}
comment|/* "<<"     */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state33
index|[]
init|=
block|{
comment|/* ">>" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state50
block|}
block|,
comment|/* ">>:" ... */
block|{
literal|'='
block|,
name|A_GOTO
block|,
name|state59
block|}
block|,
comment|/* ">>=" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|75
index|]
block|}
comment|/* ">>"     */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state34
index|[]
init|=
block|{
comment|/* "|||" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state35
block|}
block|,
comment|/* "|||:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|71
index|]
block|}
comment|/* "|||"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state35
index|[]
init|=
block|{
comment|/* "|||:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|72
index|]
block|}
block|,
comment|/* "|||:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state36
index|[]
init|=
block|{
comment|/* "?" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state37
block|}
block|,
comment|/* "?:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|95
index|]
block|}
comment|/* "?"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state37
index|[]
init|=
block|{
comment|/* "?:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|102
index|]
block|}
block|,
comment|/* "?:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state38
index|[]
init|=
block|{
comment|/* "&" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state39
block|}
block|,
comment|/* "&:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|62
index|]
block|}
comment|/* "&"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state39
index|[]
init|=
block|{
comment|/* "&:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|38
index|]
block|}
block|,
comment|/* "&:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state40
index|[]
init|=
block|{
comment|/* "@" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state41
block|}
block|,
comment|/* "@:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|36
index|]
block|}
comment|/* "@"      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state41
index|[]
init|=
block|{
comment|/* "@:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|37
index|]
block|}
block|,
comment|/* "@:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state42
index|[]
init|=
block|{
comment|/* "=:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|39
index|]
block|}
block|,
comment|/* "=:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state43
index|[]
init|=
block|{
comment|/* "~=:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|45
index|]
block|}
block|,
comment|/* "~=:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state44
index|[]
init|=
block|{
comment|/* ">:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|42
index|]
block|}
block|,
comment|/* ">:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state45
index|[]
init|=
block|{
comment|/* ">=:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|41
index|]
block|}
block|,
comment|/* ">=:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state46
index|[]
init|=
block|{
comment|/* "<:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|44
index|]
block|}
block|,
comment|/* "<:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state47
index|[]
init|=
block|{
comment|/* "<=:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|43
index|]
block|}
block|,
comment|/* "<=:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state48
index|[]
init|=
block|{
comment|/* "==:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|47
index|]
block|}
block|,
comment|/* "==:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state49
index|[]
init|=
block|{
comment|/* "~==:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|52
index|]
block|}
block|,
comment|/* "~==:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state50
index|[]
init|=
block|{
comment|/* ">>:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|49
index|]
block|}
block|,
comment|/* ">>:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state51
index|[]
init|=
block|{
comment|/* ">>=:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|48
index|]
block|}
block|,
comment|/* ">>=:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state52
index|[]
init|=
block|{
comment|/* "<<:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|51
index|]
block|}
block|,
comment|/* "<<:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state53
index|[]
init|=
block|{
comment|/* "<<=:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|50
index|]
block|}
block|,
comment|/* "<<=:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state54
index|[]
init|=
block|{
comment|/* "===:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|40
index|]
block|}
block|,
comment|/* "===:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state55
index|[]
init|=
block|{
comment|/* "~===:" */
block|{
literal|'='
block|,
name|A_IMMRET
block|,
operator|&
name|toktab
index|[
literal|46
index|]
block|}
block|,
comment|/* "~===:=" */
block|{
literal|0
block|,
name|A_ERROR
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state56
index|[]
init|=
block|{
comment|/* "<=" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state47
block|}
block|,
comment|/* "<=:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|89
index|]
block|}
comment|/* "<="      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state57
index|[]
init|=
block|{
comment|/* ">=" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state45
block|}
block|,
comment|/* ">=:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|87
index|]
block|}
comment|/* ">="      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state58
index|[]
init|=
block|{
comment|/* "<<=" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state53
block|}
block|,
comment|/* "<<=:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|76
index|]
block|}
comment|/* "<<="      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state59
index|[]
init|=
block|{
comment|/* ">>=" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state51
block|}
block|,
comment|/* ">>=:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|74
index|]
block|}
comment|/* ">>="      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state60
index|[]
init|=
block|{
comment|/* "~===" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state55
block|}
block|,
comment|/* "~===:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|85
index|]
block|}
comment|/* "~==="      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|optab
name|state61
index|[]
init|=
block|{
comment|/* "===" */
block|{
literal|':'
block|,
name|A_GOTO
block|,
name|state54
block|}
block|,
comment|/* "===:" ... */
block|{
literal|0
block|,
name|A_RETURN
block|,
operator|&
name|toktab
index|[
literal|66
index|]
block|}
comment|/* "==="      */
block|}
decl_stmt|;
end_decl_stmt

end_unit

