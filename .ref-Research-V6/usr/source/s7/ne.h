begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_decl_stmt
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lp
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|used
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* available registers */
end_comment

begin_decl_stmt
name|int
name|ps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dflt init pt size */
end_comment

begin_decl_stmt
name|int
name|ft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dflt font */
end_comment

begin_decl_stmt
name|int
name|first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fout
decl_stmt|,
name|fin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number in file */
end_comment

begin_decl_stmt
name|int
name|eqline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line where eqn started */
end_comment

begin_decl_stmt
name|int
name|svargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|svargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eht
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ebase
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ewid
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|char
name|c1
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|yyval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|yypv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yylval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tht
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tbase
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nptr
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sptr
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eqnreg
decl_stmt|,
name|eqnht
decl_stmt|,
name|eqnbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lefteq
decl_stmt|,
name|righteq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastchar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last character read by lex */
end_comment

begin_define
define|#
directive|define
name|FATAL
value|1
end_define

begin_decl_stmt
name|int
name|ESC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|HREV
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|HFWD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SI
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SO
decl_stmt|;
end_decl_stmt

end_unit

