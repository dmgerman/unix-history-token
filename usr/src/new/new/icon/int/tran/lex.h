begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  * token table  */
end_comment

begin_struct
struct|struct
name|toktab
block|{
name|char
modifier|*
name|t_word
decl_stmt|;
comment|/* token */
name|int
name|t_type
decl_stmt|;
comment|/* token type returned by yylex */
name|int
name|t_flags
decl_stmt|;
comment|/* flags for semicolon insertion */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|toktab
name|toktab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* token table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|toktab
modifier|*
name|restab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserved word index */
end_comment

begin_define
define|#
directive|define
name|T_IDENT
value|&toktab[0]
end_define

begin_define
define|#
directive|define
name|T_INT
value|&toktab[1]
end_define

begin_define
define|#
directive|define
name|T_REAL
value|&toktab[2]
end_define

begin_define
define|#
directive|define
name|T_STRING
value|&toktab[3]
end_define

begin_define
define|#
directive|define
name|T_CSET
value|&toktab[4]
end_define

begin_define
define|#
directive|define
name|T_EOF
value|&toktab[5]
end_define

begin_comment
comment|/*  * t_flags values for token table  * if a newline follows an "ender" and precedes a "beginner",  * a semicolon is inserted  */
end_comment

begin_define
define|#
directive|define
name|BEGINNER
value|1
end_define

begin_comment
comment|/* token can follow a semicolon */
end_comment

begin_define
define|#
directive|define
name|ENDER
value|2
end_define

begin_comment
comment|/* token can precede a semicolon */
end_comment

begin_comment
comment|/*  * Operator table - a finite-state automaton for  * recognizing Icon operators  */
end_comment

begin_struct
struct|struct
name|optab
block|{
name|char
name|o_input
decl_stmt|;
name|char
name|o_action
decl_stmt|;
name|int
name|o_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state5
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state6
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state7
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state8
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state9
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state10
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state11
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state12
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state13
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state14
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state15
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state16
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state17
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state18
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state19
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state20
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state21
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state22
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state23
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state24
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state25
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state26
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state27
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state28
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state29
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state30
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state31
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state33
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state34
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state35
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state36
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state37
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state38
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state39
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state40
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state41
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state42
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state43
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state44
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state45
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state46
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state47
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state48
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state49
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state50
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state51
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state52
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state53
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state54
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state55
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state56
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state57
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state58
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state59
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state60
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optab
name|state61
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* o_action values */
end_comment

begin_define
define|#
directive|define
name|A_GOTO
value|1
end_define

begin_comment
comment|/* shift input and goto new state o_val */
end_comment

begin_define
define|#
directive|define
name|A_ERROR
value|2
end_define

begin_comment
comment|/* illegal operator */
end_comment

begin_define
define|#
directive|define
name|A_RETURN
value|3
end_define

begin_comment
comment|/* return o_val, save input char */
end_comment

begin_define
define|#
directive|define
name|A_IMMRET
value|4
end_define

begin_comment
comment|/* return o_val, discard input char */
end_comment

begin_comment
comment|/*  * miscellaneous  */
end_comment

begin_define
define|#
directive|define
name|isoctal
parameter_list|(
name|c
parameter_list|)
value|((c)>='0'&&(c)<='7')
end_define

begin_comment
comment|/* macro to test for octal digit */
end_comment

begin_define
define|#
directive|define
name|NEXTCHAR
value|nextchar()
end_define

begin_comment
comment|/* macro to get next character */
end_comment

begin_define
define|#
directive|define
name|PUSHCHAR
parameter_list|(
name|c
parameter_list|)
value|peekc=(c)
end_define

begin_comment
comment|/* macro to push back a character */
end_comment

begin_define
define|#
directive|define
name|COMMENT
value|'#'
end_define

begin_comment
comment|/* comment beginner */
end_comment

begin_define
define|#
directive|define
name|ESCAPE
value|'\\'
end_define

begin_comment
comment|/* string literal escape character */
end_comment

end_unit

