begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX shell  *  *	S. R. Bourne  *	Bell Telephone Laboratories  *  */
end_comment

begin_comment
comment|/* table 1 */
end_comment

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
name|T_EOF
value|020
end_define

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
name|T_BRC
value|01
end_define

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

begin_define
define|#
directive|define
name|T_DIG
value|010
end_define

begin_define
define|#
directive|define
name|T_FNG
value|020
end_define

begin_define
define|#
directive|define
name|T_SHN
value|040
end_define

begin_define
define|#
directive|define
name|T_IDC
value|0100
end_define

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
name|_UPC
value|(T_IDC)
end_define

begin_define
define|#
directive|define
name|_LPC
value|(T_IDC)
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
value|(T_EOF)
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
name|_HAT
value|(T_MET)
end_define

begin_define
define|#
directive|define
name|_BRA
value|(T_MET)
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
name|_SQB
value|(T_FNG)
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
value|(T_QOT|T_ESC)
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
value|(T_SUB|T_ESC)
end_define

begin_define
define|#
directive|define
name|_CBR
value|T_BRC
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
value|(T_AST|T_FNG)
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
value|(T_SHN)
end_define

begin_define
define|#
directive|define
name|_NUM
value|(T_SHN)
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
value|(T_DEF|T_FNG|T_SHN)
end_define

begin_comment
comment|/* abbreviations for tests */
end_comment

begin_define
define|#
directive|define
name|_IDCH
value|(T_IDC|T_DIG)
end_define

begin_define
define|#
directive|define
name|_META
value|(T_SPC|T_DIP|T_MET|T_EOR)
end_define

begin_decl_stmt
name|char
name|_ctype1
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nb these args are not call by value !!!! */
end_comment

begin_define
define|#
directive|define
name|space
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_SPC))
end_define

begin_define
define|#
directive|define
name|eofmeta
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype1[c]&(_META|T_EOF))
end_define

begin_define
define|#
directive|define
name|qotchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_QOT))
end_define

begin_define
define|#
directive|define
name|eolchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_EOR|T_EOF))
end_define

begin_define
define|#
directive|define
name|dipchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_DIP))
end_define

begin_define
define|#
directive|define
name|subchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_SUB|T_QOT))
end_define

begin_define
define|#
directive|define
name|escchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype1[c]&(T_ESC))
end_define

begin_decl_stmt
name|char
name|_ctype2
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|digit
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_DIG))
end_define

begin_define
define|#
directive|define
name|fngchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_FNG))
end_define

begin_define
define|#
directive|define
name|dolchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_AST|T_BRC|T_DIG|T_IDC|T_SHN))
end_define

begin_define
define|#
directive|define
name|defchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_DEF))
end_define

begin_define
define|#
directive|define
name|setchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_SET))
end_define

begin_define
define|#
directive|define
name|digchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_AST|T_DIG))
end_define

begin_define
define|#
directive|define
name|letter
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_IDC))
end_define

begin_define
define|#
directive|define
name|alphanum
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(_IDCH))
end_define

begin_define
define|#
directive|define
name|astchar
parameter_list|(
name|c
parameter_list|)
value|(((c)&QUOTE)==0 ANDF _ctype2[c]&(T_AST))
end_define

end_unit

