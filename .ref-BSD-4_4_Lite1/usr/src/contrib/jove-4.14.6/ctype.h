begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|C_UPPER
value|01
end_define

begin_comment
comment|/* UPPER case */
end_comment

begin_define
define|#
directive|define
name|C_LOWER
value|02
end_define

begin_comment
comment|/* LOWER case */
end_comment

begin_define
define|#
directive|define
name|C_DIGIT
value|04
end_define

begin_comment
comment|/* DIGIT */
end_comment

begin_define
define|#
directive|define
name|C_PUNCT
value|010
end_define

begin_comment
comment|/* PUNCTuation */
end_comment

begin_define
define|#
directive|define
name|C_CTRL
value|020
end_define

begin_comment
comment|/* ConTRoL */
end_comment

begin_define
define|#
directive|define
name|C_WORD
value|040
end_define

begin_comment
comment|/* WORD */
end_comment

begin_define
define|#
directive|define
name|C_BRA
value|0100
end_define

begin_comment
comment|/* open BRAket */
end_comment

begin_define
define|#
directive|define
name|C_KET
value|0200
end_define

begin_comment
comment|/* close braKET */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
modifier|*
name|SyntaxTable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CharTable[?] */
end_comment

begin_define
define|#
directive|define
name|jiswhite
parameter_list|(
name|c
parameter_list|)
value|(jisspace(c))
end_define

begin_define
define|#
directive|define
name|jisword
parameter_list|(
name|c
parameter_list|)
value|(SyntaxTable[c]&C_WORD)
end_define

begin_define
define|#
directive|define
name|jisalpha
parameter_list|(
name|c
parameter_list|)
value|(SyntaxTable[c]&(C_UPPER|C_LOWER))
end_define

begin_define
define|#
directive|define
name|jisupper
parameter_list|(
name|c
parameter_list|)
value|(SyntaxTable[c]&C_UPPER)
end_define

begin_define
define|#
directive|define
name|jislower
parameter_list|(
name|c
parameter_list|)
value|(SyntaxTable[c]&C_LOWER)
end_define

begin_define
define|#
directive|define
name|jisdigit
parameter_list|(
name|c
parameter_list|)
value|(SyntaxTable[c]&C_DIGIT)
end_define

begin_define
define|#
directive|define
name|jisspace
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_comment
comment|/* #define	jispunct(c)	(SyntaxTable[c]&C_PUNCT) */
end_comment

begin_define
define|#
directive|define
name|has_syntax
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|(SyntaxTable[(c)&CHARMASK]&(s))
end_define

begin_comment
comment|/* #define	toascii(c)	((c)&CHARMASK) */
end_comment

begin_define
define|#
directive|define
name|jiscntrl
parameter_list|(
name|c
parameter_list|)
value|((CharTable[0][c&CHARMASK])&C_CTRL)
end_define

begin_define
define|#
directive|define
name|jisopenp
parameter_list|(
name|c
parameter_list|)
value|((CharTable[0][c&CHARMASK])&C_BRA)
end_define

begin_define
define|#
directive|define
name|jisclosep
parameter_list|(
name|c
parameter_list|)
value|((CharTable[0][c&CHARMASK])&C_KET)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII7
end_ifdef

begin_define
define|#
directive|define
name|jtolower
parameter_list|(
name|c
parameter_list|)
value|((c)|040)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ASCII7 */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|jtolower
name|proto
argument_list|(
operator|(
name|int
comment|/*char*/
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ASCII7 */
end_comment

begin_define
define|#
directive|define
name|WITH_TABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|{ \ 	const unsigned char	*push = SyntaxTable; \ 	SyntaxTable = CharTable[(x)];
end_define

begin_define
define|#
directive|define
name|END_TABLE
parameter_list|()
define|\
value|SyntaxTable = push; \ }
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|CharTable
index|[
name|NMAJORS
index|]
index|[
name|NCHARS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|RaiseTable
index|[
name|NCHARS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CharUpcase
parameter_list|(
name|c
parameter_list|)
value|(RaiseTable[c])
end_define

end_unit

