begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* The code in this file was snarfed from ctype.h and modified for JOVE. */
end_comment

begin_define
define|#
directive|define
name|_U
value|01
end_define

begin_define
define|#
directive|define
name|_L
value|02
end_define

begin_define
define|#
directive|define
name|_N
value|04
end_define

begin_define
define|#
directive|define
name|_P
value|010
end_define

begin_define
define|#
directive|define
name|_C
value|020
end_define

begin_define
define|#
directive|define
name|_W
value|040
end_define

begin_define
define|#
directive|define
name|_Op
value|0100
end_define

begin_define
define|#
directive|define
name|_Cl
value|0200
end_define

begin_decl_stmt
specifier|extern
name|int
name|SyntaxTable
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|iswhite
parameter_list|(
name|c
parameter_list|)
value|(isspace(c))
end_define

begin_define
define|#
directive|define
name|isword
parameter_list|(
name|c
parameter_list|)
value|((CharTable[SyntaxTable])[c]&(_W))
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|((CharTable[SyntaxTable])[c]&(_U|_L))
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|((CharTable[SyntaxTable])[c]&_U)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|((CharTable[SyntaxTable])[c]&_L)
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|((CharTable[SyntaxTable])[c]&_N)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|(c == ' ' || c == '\t')
end_define

begin_define
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|((CharTable[SyntaxTable])[c]&_P)
end_define

begin_define
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|((c)&CHARMASK)
end_define

begin_define
define|#
directive|define
name|isctrl
parameter_list|(
name|c
parameter_list|)
value|((CharTable[0][c&CHARMASK])&_C)
end_define

begin_define
define|#
directive|define
name|isopenp
parameter_list|(
name|c
parameter_list|)
value|((CharTable[0][c&CHARMASK])&_Op)
end_define

begin_define
define|#
directive|define
name|isclosep
parameter_list|(
name|c
parameter_list|)
value|((CharTable[0][c&CHARMASK])&_Cl)
end_define

begin_define
define|#
directive|define
name|has_syntax
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|((CharTable[SyntaxTable][c&CHARMASK])&s)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII
end_ifdef

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|((c)&~040)
end_define

begin_define
define|#
directive|define
name|tolower
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
comment|/* IBMPC or MAC */
end_comment

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|(CaseEquiv[c])
end_define

begin_comment
comment|/* #define tolower(c)	((c)|040)	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IBMPC */
end_comment

begin_define
define|#
directive|define
name|WITH_TABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|{ \ 	int	push = SyntaxTable; \ 	SyntaxTable = x;
end_define

begin_define
define|#
directive|define
name|END_TABLE
parameter_list|()
define|\
value|SyntaxTable = push; \ }
end_define

end_unit

