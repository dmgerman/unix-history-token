begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  SYMBOL.H -- definition of internal symbols. ** **	Version: **		@(#)symbol.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AND
end_ifndef

begin_define
define|#
directive|define
name|AND
value|'a'
end_define

begin_define
define|#
directive|define
name|OR
value|'o'
end_define

begin_define
define|#
directive|define
name|UOP
value|'U'
end_define

begin_comment
comment|/* UNARY OPERATORS */
end_comment

begin_define
define|#
directive|define
name|opPLUS
value|0
end_define

begin_define
define|#
directive|define
name|opMINUS
value|1
end_define

begin_define
define|#
directive|define
name|opNOT
value|2
end_define

begin_define
define|#
directive|define
name|opATAN
value|3
end_define

begin_define
define|#
directive|define
name|opCOS
value|4
end_define

begin_define
define|#
directive|define
name|opGAMMA
value|5
end_define

begin_define
define|#
directive|define
name|opLOG
value|6
end_define

begin_define
define|#
directive|define
name|opASCII
value|7
end_define

begin_define
define|#
directive|define
name|opSIN
value|8
end_define

begin_define
define|#
directive|define
name|opSQRT
value|9
end_define

begin_define
define|#
directive|define
name|opABS
value|10
end_define

begin_define
define|#
directive|define
name|opEXP
value|11
end_define

begin_define
define|#
directive|define
name|opINT1
value|12
end_define

begin_define
define|#
directive|define
name|opINT2
value|13
end_define

begin_define
define|#
directive|define
name|opINT4
value|14
end_define

begin_define
define|#
directive|define
name|opFLOAT4
value|15
end_define

begin_define
define|#
directive|define
name|opFLOAT8
value|16
end_define

begin_define
define|#
directive|define
name|BOP
value|'B'
end_define

begin_comment
comment|/* BINARY OPERATORS */
end_comment

begin_define
define|#
directive|define
name|opADD
value|0
end_define

begin_define
define|#
directive|define
name|opSUB
value|1
end_define

begin_define
define|#
directive|define
name|opMUL
value|2
end_define

begin_define
define|#
directive|define
name|opDIV
value|3
end_define

begin_define
define|#
directive|define
name|opPOW
value|4
end_define

begin_define
define|#
directive|define
name|opEQ
value|5
end_define

begin_define
define|#
directive|define
name|opNE
value|6
end_define

begin_define
define|#
directive|define
name|opLT
value|7
end_define

begin_define
define|#
directive|define
name|opLE
value|8
end_define

begin_define
define|#
directive|define
name|opGT
value|9
end_define

begin_define
define|#
directive|define
name|opGE
value|10
end_define

begin_define
define|#
directive|define
name|opMOD
value|11
end_define

begin_define
define|#
directive|define
name|opCONCAT
value|12
end_define

begin_define
define|#
directive|define
name|AOP
value|'A'
end_define

begin_comment
comment|/* AGGREGATE OPERATORS */
end_comment

begin_define
define|#
directive|define
name|opCOUNT
value|0
end_define

begin_define
define|#
directive|define
name|opCOUNTU
value|1
end_define

begin_define
define|#
directive|define
name|opSUM
value|2
end_define

begin_define
define|#
directive|define
name|opSUMU
value|3
end_define

begin_define
define|#
directive|define
name|opAVG
value|4
end_define

begin_define
define|#
directive|define
name|opAVGU
value|5
end_define

begin_define
define|#
directive|define
name|opMIN
value|6
end_define

begin_define
define|#
directive|define
name|opMAX
value|7
end_define

begin_define
define|#
directive|define
name|opANY
value|8
end_define

begin_define
define|#
directive|define
name|COP
value|'C'
end_define

begin_comment
comment|/* CONSTANT OPERATORS */
end_comment

begin_define
define|#
directive|define
name|BADCOP
value|-1
end_define

begin_comment
comment|/* error return on lookup */
end_comment

begin_define
define|#
directive|define
name|opDBA
value|0
end_define

begin_define
define|#
directive|define
name|opUSERCODE
value|1
end_define

begin_define
define|#
directive|define
name|opDATE
value|2
end_define

begin_define
define|#
directive|define
name|opTIME
value|3
end_define

begin_define
define|#
directive|define
name|RESDOM
value|'r'
end_define

begin_comment
comment|/* RESULT DOMAIN NUMBER */
end_comment

begin_define
define|#
directive|define
name|VAR
value|'v'
end_define

begin_comment
comment|/* VARIABLE */
end_comment

begin_define
define|#
directive|define
name|S_VAR
value|'s'
end_define

begin_comment
comment|/* variable for which 						 * a substitution has been done,						 * Only occurs in the ovqp-decomp 						 * merged process. 						 */
end_comment

begin_define
define|#
directive|define
name|QMODE
value|'Q'
end_define

begin_comment
comment|/* QUERY MODE */
end_comment

begin_define
define|#
directive|define
name|mdRETTERM
value|0
end_define

begin_comment
comment|/* retrieve to terminal, used by decomp-ovqp */
end_comment

begin_define
define|#
directive|define
name|mdRETR
value|1
end_define

begin_comment
comment|/* retrieve, into rel perhaps */
end_comment

begin_define
define|#
directive|define
name|mdAPP
value|2
end_define

begin_comment
comment|/* append to rel */
end_comment

begin_define
define|#
directive|define
name|mdREPL
value|3
end_define

begin_comment
comment|/* replace in rel */
end_comment

begin_define
define|#
directive|define
name|mdDEL
value|4
end_define

begin_comment
comment|/* delete from rel */
end_comment

begin_define
define|#
directive|define
name|mdCOPY
value|5
end_define

begin_comment
comment|/* copy into/from rel */
end_comment

begin_define
define|#
directive|define
name|mdCREATE
value|6
end_define

begin_comment
comment|/* create new relation */
end_comment

begin_define
define|#
directive|define
name|mdDESTROY
value|7
end_define

begin_comment
comment|/* destroy old relation */
end_comment

begin_define
define|#
directive|define
name|mdHELP
value|8
end_define

begin_comment
comment|/* print info on relation */
end_comment

begin_define
define|#
directive|define
name|mdINDEX
value|9
end_define

begin_comment
comment|/* create secondary index */
end_comment

begin_define
define|#
directive|define
name|mdMODIFY
value|10
end_define

begin_comment
comment|/* change access structure of rel */
end_comment

begin_define
define|#
directive|define
name|mdPRINT
value|11
end_define

begin_comment
comment|/* print rel on terminal */
end_comment

begin_define
define|#
directive|define
name|mdRANGE
value|12
end_define

begin_comment
comment|/* declare range variable */
end_comment

begin_define
define|#
directive|define
name|mdSAVE
value|13
end_define

begin_comment
comment|/* save relation date */
end_comment

begin_comment
comment|/*		unused			14		unused */
end_comment

begin_define
define|#
directive|define
name|mdRET_UNI
value|15
end_define

begin_comment
comment|/* retrieve unique */
end_comment

begin_define
define|#
directive|define
name|mdVIEW
value|16
end_define

begin_comment
comment|/* extra info for view def, to qrymod */
end_comment

begin_define
define|#
directive|define
name|mdUPDATE
value|17
end_define

begin_comment
comment|/* update processor */
end_comment

begin_define
define|#
directive|define
name|mdRESETREL
value|18
end_define

begin_comment
comment|/* modify to truncated */
end_comment

begin_define
define|#
directive|define
name|mdDISPLAY
value|19
end_define

begin_comment
comment|/* dump qm decl */
end_comment

begin_define
define|#
directive|define
name|mdNETQRY
value|20
end_define

begin_comment
comment|/* reserved for distr ingres */
end_comment

begin_define
define|#
directive|define
name|mdMOVEREL
value|21
end_define

begin_comment
comment|/* reserved for distr ingres */
end_comment

begin_define
define|#
directive|define
name|mdPROT
value|22
end_define

begin_comment
comment|/* extra info for permit def, to qrymod */
end_comment

begin_define
define|#
directive|define
name|mdINTEG
value|23
end_define

begin_comment
comment|/* extra info for integrity def, to qrymod */
end_comment

begin_define
define|#
directive|define
name|mdDCREATE
value|24
end_define

begin_comment
comment|/* reserved for distr ingres */
end_comment

begin_define
define|#
directive|define
name|mdWAITQRY
value|25
end_define

begin_comment
comment|/* reserved for distr ingres */
end_comment

begin_define
define|#
directive|define
name|mdREMQM
value|26
end_define

begin_comment
comment|/* remove permit integrity definition */
end_comment

begin_define
define|#
directive|define
name|mdDISTRIB
value|27
end_define

begin_comment
comment|/* reserved for distr ingres */
end_comment

begin_comment
comment|/* special modes used only for control module communication */
end_comment

begin_define
define|#
directive|define
name|mdQRY
value|1
end_define

begin_comment
comment|/* general query call */
end_comment

begin_define
define|#
directive|define
name|mdDECOMP
value|2
end_define

begin_comment
comment|/* call decomp */
end_comment

begin_define
define|#
directive|define
name|mdPARSER
value|3
end_define

begin_comment
comment|/* parser module */
end_comment

begin_define
define|#
directive|define
name|ROOT
value|'R'
end_define

begin_comment
comment|/* ROOT of QUERY TREE */
end_comment

begin_define
define|#
directive|define
name|QLEND
value|'q'
end_define

begin_comment
comment|/* NULL branch at end of QUAL */
end_comment

begin_define
define|#
directive|define
name|TREE
value|'T'
end_define

begin_comment
comment|/* SIGNALS BEGINNING of TREE */
end_comment

begin_define
define|#
directive|define
name|BYHEAD
value|'H'
end_define

begin_comment
comment|/* BY LIST HEAD */
end_comment

begin_define
define|#
directive|define
name|AGHEAD
value|'h'
end_define

begin_comment
comment|/* AGGREGATE HEAD */
end_comment

begin_define
define|#
directive|define
name|SITE
value|'S'
end_define

begin_comment
comment|/* reserved for distr ingres */
end_comment

begin_define
define|#
directive|define
name|INT
value|'i'
end_define

begin_comment
comment|/* INTEGER CONSTANT */
end_comment

begin_define
define|#
directive|define
name|FLOAT
value|'f'
end_define

begin_comment
comment|/* FLOATING POINT CONSTANT */
end_comment

begin_define
define|#
directive|define
name|CHAR
value|'c'
end_define

begin_comment
comment|/* CHARACTER CONSTANT */
end_comment

begin_define
define|#
directive|define
name|BINARY
value|'b'
end_define

begin_comment
comment|/* BINARY CONSTANT (used in printup */
end_comment

begin_define
define|#
directive|define
name|TUPLE
value|'t'
end_define

begin_comment
comment|/* TUPLE (used in ctlmod) */
end_comment

begin_define
define|#
directive|define
name|RESULTVAR
value|'='
end_define

begin_comment
comment|/* RESULT RELATION VAR NO. */
end_comment

begin_define
define|#
directive|define
name|SOURCEID
value|'<'
end_define

begin_comment
comment|/* SOURCE RELATION NAME(S) */
end_comment

begin_define
define|#
directive|define
name|RESULTID
value|'>'
end_define

begin_comment
comment|/* RESULT RELATION NAME	*/
end_comment

begin_define
define|#
directive|define
name|CHANGESTRAT
value|'g'
end_define

begin_comment
comment|/* FOR OVQP TO DEVISE NEW STRATEGY */
end_comment

begin_define
define|#
directive|define
name|USERQRY
value|'u'
end_define

begin_comment
comment|/* Tells OVQP result rel is a user rel */
end_comment

begin_define
define|#
directive|define
name|EXIT
value|'x'
end_define

begin_comment
comment|/* tells OVQP that query is done */
end_comment

begin_define
define|#
directive|define
name|ACK
value|1
end_define

begin_comment
comment|/* OVQP should write an acknowledging EOP */
end_comment

begin_define
define|#
directive|define
name|NOACK
value|2
end_define

begin_comment
comment|/* OVQP should not acknowledge */
end_comment

begin_define
define|#
directive|define
name|RUBACK
value|3
end_define

begin_comment
comment|/* internal mode for DECOMP */
end_comment

begin_define
define|#
directive|define
name|REOPENRES
value|'O'
end_define

begin_comment
comment|/* OVQP should reopen result relation */
end_comment

begin_define
define|#
directive|define
name|RETVAL
value|'V'
end_define

begin_comment
comment|/* RETURN FROM OVQP */
end_comment

begin_define
define|#
directive|define
name|UPDATE
value|-3
end_define

begin_comment
comment|/* tells DECOMP to call update */
end_comment

begin_define
define|#
directive|define
name|NOUPDATE
value|-2
end_define

begin_comment
comment|/* tells DECOMP not to call update */
end_comment

begin_define
define|#
directive|define
name|EMPTY
value|-1
end_define

begin_define
define|#
directive|define
name|NONEMPTY
value|0
end_define

begin_define
define|#
directive|define
name|EOTUP
value|'Z'
end_define

begin_comment
comment|/* end of tuple symbol send by OVQP to equel */
end_comment

begin_comment
comment|/*	The following are pattern matching symbols used by ovqp */
end_comment

begin_define
define|#
directive|define
name|PAT_ANY
value|1
end_define

begin_comment
comment|/* matches 0 or more char */
end_comment

begin_define
define|#
directive|define
name|PAT_ONE
value|2
end_define

begin_comment
comment|/* matches any one char */
end_comment

begin_define
define|#
directive|define
name|PAT_LBRAC
value|3
end_define

begin_comment
comment|/* left bracket for char groupings */
end_comment

begin_define
define|#
directive|define
name|PAT_RBRAC
value|4
end_define

begin_comment
comment|/* right bracket for char groupings */
end_comment

begin_endif
endif|#
directive|endif
endif|AND
end_endif

end_unit

