begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)shtype.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *  *	S. R. Bourne  *	AT&T Bell Laboratories  *  */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* table 1 */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|(~0177)
end_define

begin_define
define|#
directive|define
name|T_SUB
value|01
end_define

begin_define
define|#
directive|define
name|T_MET
value|02
end_define

begin_define
define|#
directive|define
name|T_SPC
value|04
end_define

begin_define
define|#
directive|define
name|T_DIP
value|010
end_define

begin_define
define|#
directive|define
name|T_EXP
value|020
end_define

begin_comment
comment|/* characters which require expansion or substitution */
end_comment

begin_define
define|#
directive|define
name|T_EOR
value|040
end_define

begin_define
define|#
directive|define
name|T_QOT
value|0100
end_define

begin_define
define|#
directive|define
name|T_ESC
value|0200
end_define

begin_comment
comment|/* table 2 */
end_comment

begin_define
define|#
directive|define
name|T_ALP
value|01
end_define

begin_comment
comment|/* alpha, but not upper or lower */
end_comment

begin_define
define|#
directive|define
name|T_DEF
value|02
end_define

begin_define
define|#
directive|define
name|T_AST
value|04
end_define

begin_comment
comment|/* * or @ */
end_comment

begin_define
define|#
directive|define
name|T_DIG
value|010
end_define

begin_comment
comment|/* digit */
end_comment

begin_define
define|#
directive|define
name|T_UPC
value|020
end_define

begin_comment
comment|/* uppercase only */
end_comment

begin_define
define|#
directive|define
name|T_SHN
value|040
end_define

begin_comment
comment|/* legal parameter characters */
end_comment

begin_define
define|#
directive|define
name|T_LPC
value|0100
end_define

begin_comment
comment|/* lowercase only */
end_comment

begin_define
define|#
directive|define
name|T_SET
value|0200
end_define

begin_comment
comment|/* for single chars */
end_comment

begin_define
define|#
directive|define
name|_TAB
value|(T_SPC)
end_define

begin_define
define|#
directive|define
name|_SPC
value|(T_SPC)
end_define

begin_define
define|#
directive|define
name|_ALP
value|(T_ALP)
end_define

begin_define
define|#
directive|define
name|_UPC
value|(T_UPC)
end_define

begin_define
define|#
directive|define
name|_LPC
value|(T_LPC)
end_define

begin_define
define|#
directive|define
name|_DIG
value|(T_DIG)
end_define

begin_define
define|#
directive|define
name|_EOF
value|(T_EOR)
end_define

begin_define
define|#
directive|define
name|_EOR
value|(T_EOR)
end_define

begin_define
define|#
directive|define
name|_BAR
value|(T_DIP)
end_define

begin_define
define|#
directive|define
name|_BRA
value|(T_MET|T_DIP)
end_define

begin_define
define|#
directive|define
name|_KET
value|(T_MET)
end_define

begin_define
define|#
directive|define
name|_AMP
value|(T_DIP)
end_define

begin_define
define|#
directive|define
name|_SEM
value|(T_DIP)
end_define

begin_define
define|#
directive|define
name|_LT
value|(T_DIP)
end_define

begin_define
define|#
directive|define
name|_GT
value|(T_DIP)
end_define

begin_define
define|#
directive|define
name|_LQU
value|(T_QOT|T_ESC|T_EXP)
end_define

begin_define
define|#
directive|define
name|_QU1
value|T_EXP
end_define

begin_define
define|#
directive|define
name|_AST1
value|T_EXP
end_define

begin_define
define|#
directive|define
name|_BSL
value|(T_ESC)
end_define

begin_define
define|#
directive|define
name|_DQU
value|(T_QOT)
end_define

begin_define
define|#
directive|define
name|_DOL1
value|(T_SUB|T_ESC|T_EXP)
end_define

begin_define
define|#
directive|define
name|_CBR
value|T_SHN
end_define

begin_define
define|#
directive|define
name|_CKT
value|T_DEF
end_define

begin_define
define|#
directive|define
name|_AST
value|(T_AST)
end_define

begin_define
define|#
directive|define
name|_EQ
value|(T_DEF)
end_define

begin_define
define|#
directive|define
name|_MIN
value|(T_DEF|T_SHN)
end_define

begin_define
define|#
directive|define
name|_PCS
value|(T_DEF|T_SHN|T_SET)
end_define

begin_define
define|#
directive|define
name|_NUM
value|(T_DEF|T_SHN|T_SET)
end_define

begin_define
define|#
directive|define
name|_DOL2
value|(T_SHN)
end_define

begin_define
define|#
directive|define
name|_PLS
value|(T_DEF|T_SET)
end_define

begin_define
define|#
directive|define
name|_AT
value|(T_AST)
end_define

begin_define
define|#
directive|define
name|_QU
value|(T_DEF|T_SHN)
end_define

begin_define
define|#
directive|define
name|_LPAR
value|T_SHN
end_define

begin_define
define|#
directive|define
name|_SS2
value|T_ALP
end_define

begin_define
define|#
directive|define
name|_SS3
value|T_ALP
end_define

begin_comment
comment|/* abbreviations for tests */
end_comment

begin_define
define|#
directive|define
name|_IDCH
value|(T_UPC|T_LPC|T_DIG|T_ALP)
end_define

begin_define
define|#
directive|define
name|_META
value|(T_SPC|T_DIP|T_MET|T_EOR)
end_define

begin_decl_stmt
specifier|extern
name|char
name|_ctype1
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* these args are not call by value !!!! */
end_comment

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(T_SPC))
end_define

begin_define
define|#
directive|define
name|ismeta
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(_META))
end_define

begin_define
define|#
directive|define
name|isqmeta
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(_META|T_QOT))
end_define

begin_define
define|#
directive|define
name|qotchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(T_QOT))
end_define

begin_define
define|#
directive|define
name|eolchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(T_EOR))
end_define

begin_define
define|#
directive|define
name|dipchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(T_DIP))
end_define

begin_define
define|#
directive|define
name|subchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(T_SUB|T_QOT))
end_define

begin_define
define|#
directive|define
name|escchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(T_ESC))
end_define

begin_define
define|#
directive|define
name|expchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&(T_EXP|T_SPC))
end_define

begin_define
define|#
directive|define
name|isexp
parameter_list|(
name|c
parameter_list|)
value|(_ctype1[c]&T_EXP)
end_define

begin_decl_stmt
specifier|extern
name|char
name|_ctype2
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|(((c)&0340)&& ((c)!=0177))
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_DIG))
end_define

begin_define
define|#
directive|define
name|dolchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_AST|_IDCH|T_SHN))
end_define

begin_define
define|#
directive|define
name|defchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_DEF))
end_define

begin_define
define|#
directive|define
name|setchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_SET))
end_define

begin_define
define|#
directive|define
name|digchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_AST|T_DIG))
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_UPC|T_LPC|T_ALP))
end_define

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(_IDCH))
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_UPC))
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_LPC))
end_define

begin_define
define|#
directive|define
name|astchar
parameter_list|(
name|c
parameter_list|)
value|(_ctype2[c]&(T_AST))
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|((c) + 'A' - 'a')
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|((c) + 'a' - 'A')
end_define

end_unit

