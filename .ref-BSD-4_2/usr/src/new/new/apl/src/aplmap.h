begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|aplmap_h_Sccsid
index|[]
init|=
literal|"aplmap.h @(#)aplmap.h	1.2	10/1/82 Berkeley "
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PURDUE_EE
end_ifdef

begin_comment
comment|/*  *	Mapping arrays  *  * The following arrays perform character mapping between the APL  * character set (LSI modified by Peter Hallenbeck) and the ASCII  * character set.  *  */
end_comment

begin_comment
comment|/* Map to the APL character set from ASCII */
end_comment

begin_decl_stmt
name|char
name|map_apl
index|[]
init|=
block|{
literal|'!'
block|,
comment|/* does not map */
literal|' '
block|,
comment|/* does not map */
literal|'('
block|,
comment|/* mapped pound sign (not equals) */
literal|'$'
block|,
comment|/* dollar sign maps to itself (.le.) */
literal|'='
block|,
comment|/* mapped percent (division) */
literal|'&'
block|,
comment|/*& becomes .ge. automatically */
literal|'K'
block|,
comment|/* mapped single quote mark */
literal|'+'
block|,
comment|/* mapped opening parenthesis */
literal|'`'
block|,
comment|/* mapped closing parenthesis */
literal|'P'
block|,
comment|/* mapped asterisk */
literal|':'
block|,
comment|/* mapped plus */
literal|','
block|,
comment|/* , maps to itself */
literal|'*'
block|,
comment|/* mapped minus */
literal|'.'
block|,
comment|/* . maps to itself */
literal|'/'
block|,
comment|/* / maps to itself */
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'9'
block|,
comment|/* all digits ok */
literal|'>'
block|,
comment|/* mapped colon */
literal|'<'
block|,
comment|/* mapped semi-colon */
literal|'#'
block|,
comment|/* mapped less-than */
literal|'%'
block|,
comment|/* mapped equals */
literal|'\''
block|,
comment|/* mapped greater-than */
literal|'Q'
block|,
comment|/* mapped question-mark */
literal|' '
block|,
comment|/* @ does not map */
literal|'A'
block|,
comment|/* capital a maps to itself (alpha) */
literal|'B'
block|,
comment|/* capital b equals decode */
literal|'C'
block|,
comment|/* capital c equals inverted U */
literal|'D'
block|,
comment|/* capital d equals floot */
literal|'E'
block|,
comment|/* capital e equals epsilon */
literal|'F'
block|,
comment|/* capital f maps to itself (underscore) */
literal|'G'
block|,
comment|/* capital g equals del */
literal|'H'
block|,
comment|/* capital h equals interted del */
literal|'I'
block|,
comment|/* capital i equals iota */
literal|'J'
block|,
comment|/* capital j equals circle */
literal|' '
block|,
comment|/* capital k does not map */
literal|'L'
block|,
comment|/* capital l equals quad */
literal|'-'
block|,
comment|/* mapped multiply */
literal|'N'
block|,
comment|/* capital n equals encode */
literal|'O'
block|,
comment|/* capital o equals big circle */
literal|'='
block|,
comment|/* mapped divide */
literal|')'
block|,
comment|/* mapped "or" */
literal|'R'
block|,
comment|/* capital r equals rho */
literal|'S'
block|,
comment|/* capital s equals ceiling */
literal|' '
block|,
comment|/* capital t does not map */
literal|'U'
block|,
comment|/* capital u equals drop */
literal|')'
block|,
comment|/* mapped "or" */
literal|'W'
block|,
comment|/* capital w equals omega */
literal|'-'
block|,
comment|/* capital x equals times sign */
literal|'Y'
block|,
comment|/* capital y equals take */
literal|'Z'
block|,
comment|/* capital z equals inverted subset symbol */
literal|';'
block|,
comment|/* mapped open brace */
literal|'?'
block|,
comment|/* mapped backslash */
literal|'@'
block|,
comment|/* mapped closing brace */
literal|'{'
block|,
comment|/* mapped caret */
literal|'\\'
block|,
comment|/* mapped underscore */
literal|'"'
block|,
comment|/* raised minus */
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'i'
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'n'
block|,
literal|'o'
block|,
literal|'p'
block|,
literal|'q'
block|,
literal|'r'
block|,
literal|'s'
block|,
literal|'t'
block|,
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
literal|'y'
block|,
literal|'z'
block|,
literal|'\\'
block|,
comment|/* mapped open brace */
literal|'M'
block|,
comment|/* mapped mod (abs) */
literal|'|'
block|,
comment|/* mapped closing brace */
literal|'T'
block|,
comment|/* mapped "not" */
literal|'\177'
comment|/* delete maps to itself */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map to ASCII from the APL character set */
end_comment

begin_decl_stmt
name|char
name|map_ascii
index|[]
init|=
block|{
literal|'!'
block|,
literal|'`'
block|,
literal|'<'
block|,
literal|'$'
block|,
literal|'='
block|,
literal|'&'
block|,
literal|'>'
block|,
literal|'#'
block|,
literal|'V'
block|,
literal|'-'
block|,
literal|'('
block|,
literal|','
block|,
literal|'X'
block|,
literal|'.'
block|,
literal|'/'
block|,
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'9'
block|,
literal|'+'
block|,
literal|'['
block|,
literal|';'
block|,
literal|'%'
block|,
literal|':'
block|,
literal|'\\'
block|,
literal|']'
block|,
literal|'A'
block|,
literal|'B'
block|,
literal|'C'
block|,
literal|'D'
block|,
literal|'E'
block|,
literal|'F'
block|,
literal|'G'
block|,
literal|'H'
block|,
literal|'I'
block|,
literal|'J'
block|,
literal|'\''
block|,
literal|'L'
block|,
literal|'|'
block|,
literal|'N'
block|,
literal|'O'
block|,
literal|'*'
block|,
literal|'?'
block|,
literal|'R'
block|,
literal|'S'
block|,
literal|'~'
block|,
literal|'U'
block|,
literal|'V'
block|,
literal|'W'
block|,
literal|'X'
block|,
literal|'Y'
block|,
literal|'Z'
block|,
literal|'$'
block|,
literal|'{'
block|,
literal|']'
block|,
literal|'\10'
block|,
literal|'_'
block|,
literal|')'
block|,
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'i'
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'n'
block|,
literal|'o'
block|,
literal|'p'
block|,
literal|'q'
block|,
literal|'r'
block|,
literal|'s'
block|,
literal|'t'
block|,
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
literal|'y'
block|,
literal|'z'
block|,
literal|'^'
block|,
literal|'}'
block|,
literal|'}'
block|,
literal|' '
block|,
literal|'\177'
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  *	Mapping arrays  *  * The following arrays perform character mapping between the APL  * character set (Datamedia elite 1520) and the ASCII character  * set.  This is a typewriter-paired keyboard.  */
end_comment

begin_comment
comment|/* Map to the APL character set from ASCII */
end_comment

begin_decl_stmt
name|char
name|map_apl
index|[]
init|=
block|{
literal|'!'
block|,
comment|/* does not map */
literal|' '
block|,
comment|/* does not map */
literal|'*'
block|,
comment|/* mapped pound sign (not equals) */
literal|'$'
block|,
comment|/* dollar sign maps to itself (.le.) */
literal|'+'
block|,
comment|/* mapped percent (division) */
literal|'^'
block|,
comment|/*& becomes .ge. */
literal|'K'
block|,
comment|/* mapped single quote mark */
literal|':'
block|,
comment|/* mapped opening parenthesis */
literal|'"'
block|,
comment|/* mapped closing parenthesis */
literal|'P'
block|,
comment|/* mapped asterisk */
literal|'-'
block|,
comment|/* mapped plus */
literal|','
block|,
comment|/* , maps to itself */
literal|'_'
block|,
comment|/* mapped minus */
literal|'.'
block|,
comment|/* . maps to itself */
literal|'/'
block|,
comment|/* / maps to itself */
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'9'
block|,
comment|/* all digits ok */
literal|'>'
block|,
comment|/* mapped colon */
literal|'<'
block|,
comment|/* mapped semi-colon */
literal|'#'
block|,
comment|/* mapped less-than */
literal|'%'
block|,
comment|/* mapped equals */
literal|'&'
block|,
comment|/* mapped greater-than */
literal|'Q'
block|,
comment|/* mapped question-mark */
literal|' '
block|,
comment|/* @ does not map */
literal|'A'
block|,
comment|/* capital a maps to itself (alpha) */
literal|'B'
block|,
comment|/* capital b equals decode */
literal|'C'
block|,
comment|/* capital c equals inverted U */
literal|'D'
block|,
comment|/* capital d equals floot */
literal|'E'
block|,
comment|/* capital e equals epsilon */
literal|'F'
block|,
comment|/* capital f maps to itself (underscore) */
literal|'G'
block|,
comment|/* capital g equals del */
literal|'H'
block|,
comment|/* capital h equals interted del */
literal|'I'
block|,
comment|/* capital i equals iota */
literal|'J'
block|,
comment|/* capital j equals circle */
literal|' '
block|,
comment|/* capital k does not map */
literal|'L'
block|,
comment|/* capital l equals quad */
literal|'='
block|,
comment|/* mapped multiply */
literal|'N'
block|,
comment|/* capital n equals encode */
literal|'O'
block|,
comment|/* capital o equals big circle */
literal|'+'
block|,
comment|/* mapped divide */
literal|'('
block|,
comment|/* mapped "or" */
literal|'R'
block|,
comment|/* capital r equals rho */
literal|'S'
block|,
comment|/* capital s equals ceiling */
literal|' '
block|,
comment|/* capital t does not map */
literal|'U'
block|,
comment|/* capital u equals drop */
literal|'('
block|,
comment|/* mapped "or" */
literal|'W'
block|,
comment|/* capital w equals omega */
literal|'='
block|,
comment|/* capital x equals times sign */
literal|'Y'
block|,
comment|/* capital y equals take */
literal|'Z'
block|,
comment|/* capital z equals inverted subset symbol */
literal|';'
block|,
comment|/* mapped open bracket */
literal|'?'
block|,
comment|/* mapped backslash */
literal|'\''
block|,
comment|/* mapped closing bracket */
literal|')'
block|,
comment|/* mapped caret */
literal|'['
block|,
comment|/* mapped underscore */
literal|'@'
block|,
comment|/* raised minus */
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'i'
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'n'
block|,
literal|'o'
block|,
literal|'p'
block|,
literal|'q'
block|,
literal|'r'
block|,
literal|'s'
block|,
literal|'t'
block|,
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
literal|'y'
block|,
literal|'z'
block|,
literal|'['
block|,
comment|/* mapped open brace */
literal|'M'
block|,
comment|/* mapped mod (abs) */
literal|']'
block|,
comment|/* mapped closing brace */
literal|'T'
block|,
comment|/* mapped "not" */
literal|'\177'
comment|/* delete maps to itself */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map to ASCII from the APL character set */
end_comment

begin_decl_stmt
name|char
name|map_ascii
index|[]
init|=
block|{
literal|'!'
block|,
literal|')'
block|,
literal|'<'
block|,
literal|'$'
block|,
literal|'='
block|,
literal|'>'
block|,
literal|']'
block|,
literal|'V'
block|,
literal|'^'
block|,
literal|'#'
block|,
literal|'%'
block|,
literal|','
block|,
literal|'+'
block|,
literal|'.'
block|,
literal|'/'
block|,
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'9'
block|,
literal|'('
block|,
literal|'['
block|,
literal|';'
block|,
literal|'X'
block|,
literal|':'
block|,
literal|'\\'
block|,
literal|'`'
block|,
literal|'A'
block|,
literal|'B'
block|,
literal|'C'
block|,
literal|'D'
block|,
literal|'E'
block|,
literal|'F'
block|,
literal|'G'
block|,
literal|'H'
block|,
literal|'I'
block|,
literal|'J'
block|,
literal|'\''
block|,
literal|'L'
block|,
literal|'|'
block|,
literal|'N'
block|,
literal|'O'
block|,
literal|'*'
block|,
literal|'?'
block|,
literal|'R'
block|,
literal|'S'
block|,
literal|'~'
block|,
literal|'U'
block|,
literal|'V'
block|,
literal|'W'
block|,
literal|'X'
block|,
literal|'Y'
block|,
literal|'Z'
block|,
literal|'{'
block|,
literal|'{'
block|,
literal|'}'
block|,
literal|'&'
block|,
literal|'-'
block|,
literal|'J'
block|,
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'i'
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'n'
block|,
literal|'o'
block|,
literal|'p'
block|,
literal|'q'
block|,
literal|'r'
block|,
literal|'s'
block|,
literal|'t'
block|,
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
literal|'y'
block|,
literal|'z'
block|,
literal|'{'
block|,
literal|'}'
block|,
literal|'}'
block|,
literal|'$'
block|,
literal|'\177'
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

