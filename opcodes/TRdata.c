begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char	*trnames[] { 	0, 	"MINUS", 	"MOD", 	"DIV", 	"DIVD", 	"MULT", 	"ADD", 	"SUB", 	"EQ", 	"NE", 	"LT", 	"GT", 	"LE", 	"GE", 	"NOT", 	"AND", 	"OR", 	"ASGN", 	"PLUS", 	"IN", 	"LISTPP", 	"PDEC", 	"FDEC", 	"PVAL", 	"PVAR", 	"PFUNC", 	"PPROC", 	"NIL", 	"STRNG", 	"CSTRNG", 	"PLUSC", 	"MINUSC", 	"ID", 	"INT", 	"FINT", 	"CINT", 	"CFINT", 	"TYPTR", 	"TYPACK", 	"TYSCAL", 	"TYRANG", 	"TYARY", 	"TYFILE", 	"TYSET", 	"TYREC", 	"TYFIELD", 	"TYVARPT", 	"TYVARNT", 	"CSTAT", 	"BLOCK", 	"LABEL", 	"PCALL", 	"FCALL", 	"CASE", 	"WITH", 	"WHILE", 	"REPEAT", 	"FORU", 	"FORD", 	"GOTO", 	"IF", 	"ASRT", 	"CSET", 	"RANG", 	"VAR", 	"ARGL", 	"ARY", 	"FIELD", 	"PTR", 	"WEXP", 	"PROG", 	"BINT", 	"CBINT", 	"IFEL", 	"IFX", 	"TYID" }; */
end_comment

begin_comment
comment|/* char	*trdesc[] { 	0, 	"np", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"np", 	"dpp", 	"dpp", 	"d\"p", 	"np", 	"dpp", 	"pp", 	"n\"pp", 	"n\"pp", 	"pp", 	"pp", 	"pp", 	"p", 	"d", 	"d\"", 	"\"", 	"p", 	"p", 	"p", 	"d\"", 	"d\"", 	"\"", 	"\"", 	"p", 	"p", 	"p", 	"pp", 	"pp", 	"p", 	"p", 	"p", 	"pp", 	"ppp", 	"pp", 	"dpp", 	"dp", 	"d\"p", 	"d\"p", 	"d\"p", 	"dpp", 	"dpp", 	"dpp", 	"dpp", 	"dppp", 	"dppp", 	"d\"", 	"dppp", 	"dp", 	"dp", 	"pp", 	"d\"p", 	"p", 	"p", 	"pp", 	"", 	"ppp", 	"n\"pp", 	"\"", 	"\"", 	"dppp", 	"dppp", 	"dpp" }; */
end_comment

begin_decl_stmt
name|char
modifier|*
name|opnames
index|[]
block|{
literal|0
operator|,
literal|"unary -"
operator|,
literal|"mod"
operator|,
literal|"div"
operator|,
literal|"/"
operator|,
literal|"*"
operator|,
literal|"+"
operator|,
literal|"-"
operator|,
literal|"="
operator|,
literal|"<>"
operator|,
literal|"<"
operator|,
literal|">"
operator|,
literal|"<="
operator|,
literal|">="
operator|,
literal|"not"
operator|,
literal|"and"
operator|,
literal|"or"
operator|,
literal|":="
operator|,
literal|"unary +"
operator|,
literal|"in"
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

