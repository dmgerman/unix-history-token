begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  CONSTANTS.H -- manifest constants, operand and operator codes ** **	Defines: **		op_codes for operands **		Opflag's domain set **		Type_spec's domain set ** **	Version: **		@(#)constants.h	7.2	10/27/81 */
end_comment

begin_comment
comment|/* ** 	Manifest constants used throughout Equel */
end_comment

begin_define
define|#
directive|define
name|CONTINUE
value|1
end_define

begin_comment
comment|/* "loop" flag for yylex */
end_comment

begin_define
define|#
directive|define
name|MAXNAME
value|13
end_define

begin_comment
comment|/* maximum length for equel  					 * identifiers (or keywords)  					 */
end_comment

begin_define
define|#
directive|define
name|MAXSTRING
value|255
end_define

begin_comment
comment|/* maximum length for equel strings */
end_comment

begin_define
define|#
directive|define
name|FILLCNT
value|110
end_define

begin_comment
comment|/* length to fill lines when in Fillmode */
end_comment

begin_comment
comment|/* debugging info conditional compilation flag */
end_comment

begin_define
define|#
directive|define
name|xDEBUG
end_define

begin_comment
comment|/* on for "-c" and "-v" flags */
end_comment

begin_define
define|#
directive|define
name|YYDEBUG
end_define

begin_comment
comment|/* must ALWAYS be on-used in yyparse()*/
end_comment

begin_comment
comment|/*  **	Character types [cmap.c]  */
end_comment

begin_define
define|#
directive|define
name|EOF_TOK
value|0
end_define

begin_comment
comment|/* end of parse input too */
end_comment

begin_define
define|#
directive|define
name|ALPHA
value|1
end_define

begin_comment
comment|/* alphabetic or '_' */
end_comment

begin_define
define|#
directive|define
name|NUMBR
value|2
end_define

begin_comment
comment|/* numeric */
end_comment

begin_define
define|#
directive|define
name|OPATR
value|3
end_define

begin_comment
comment|/* other non control characters */
end_comment

begin_define
define|#
directive|define
name|PUNCT
value|4
end_define

begin_comment
comment|/* white space */
end_comment

begin_define
define|#
directive|define
name|CNTRL
value|5
end_define

begin_comment
comment|/* control-characters */
end_comment

begin_comment
comment|/* **	Modes for Lastc in w_op() and w_key() [prtout.c]  */
end_comment

begin_define
define|#
directive|define
name|OPCHAR
value|0
end_define

begin_comment
comment|/* last character  					 * printed was an operator  					 */
end_comment

begin_define
define|#
directive|define
name|KEYCHAR
value|1
end_define

begin_comment
comment|/* last was alphanumeric */
end_comment

begin_comment
comment|/*  * Modes used in parser actions to distinguish contexts in which  * the same syntax applies. Opflag is set to these modes.  *  * (There are some modes that are never referenced, but are useful  * for extension).  */
end_comment

begin_comment
comment|/* quel statements */
end_comment

begin_define
define|#
directive|define
name|mdAPPEND
value|1
end_define

begin_define
define|#
directive|define
name|mdCOPY
value|2
end_define

begin_define
define|#
directive|define
name|mdCREATE
value|3
end_define

begin_define
define|#
directive|define
name|mdDEFINE
value|4
end_define

begin_define
define|#
directive|define
name|mdDELETE
value|5
end_define

begin_define
define|#
directive|define
name|mdDESTROY
value|6
end_define

begin_define
define|#
directive|define
name|mdHELP
value|7
end_define

begin_define
define|#
directive|define
name|mdINDEX
value|8
end_define

begin_define
define|#
directive|define
name|mdINTEGRITY
value|9
end_define

begin_define
define|#
directive|define
name|mdMODIFY
value|10
end_define

begin_define
define|#
directive|define
name|mdPRINT
value|11
end_define

begin_define
define|#
directive|define
name|mdRANGE
value|12
end_define

begin_define
define|#
directive|define
name|mdREPLACE
value|13
end_define

begin_define
define|#
directive|define
name|mdRETRIEVE
value|14
end_define

begin_define
define|#
directive|define
name|mdSAVE
value|15
end_define

begin_define
define|#
directive|define
name|mdVIEW
value|16
end_define

begin_define
define|#
directive|define
name|mdPROT
value|17
end_define

begin_comment
comment|/* statements particular to Equel */
end_comment

begin_define
define|#
directive|define
name|mdDECL
value|16
end_define

begin_comment
comment|/* C - declaration */
end_comment

begin_define
define|#
directive|define
name|mdCTLELM
value|17
end_define

begin_comment
comment|/* left hand side of target list element 					 * in "retrieve" to C-variables 					 */
end_comment

begin_define
define|#
directive|define
name|mdEXIT
value|18
end_define

begin_comment
comment|/* ## exit */
end_comment

begin_define
define|#
directive|define
name|mdINGRES
value|19
end_define

begin_comment
comment|/* ## ingres */
end_comment

begin_define
define|#
directive|define
name|mdTUPRET
value|20
end_define

begin_comment
comment|/* "retrieve" w/o an "into" */
end_comment

begin_define
define|#
directive|define
name|mdFILENAME
value|21
end_define

begin_comment
comment|/* used in "copy" statement */
end_comment

begin_comment
comment|/* define	typTYPE		xx		/*   c types "Type_spec"  */
end_comment

begin_define
define|#
directive|define
name|opSHORT
value|1
end_define

begin_define
define|#
directive|define
name|opFLOAT
value|2
end_define

begin_define
define|#
directive|define
name|opSTRING
value|3
end_define

begin_define
define|#
directive|define
name|opDOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|opCHAR
value|5
end_define

begin_define
define|#
directive|define
name|opLONG
value|6
end_define

begin_define
define|#
directive|define
name|opIDSTRING
value|7
end_define

begin_define
define|#
directive|define
name|opSTRUCT
value|8
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PDP
end_ifdef

begin_define
define|#
directive|define
name|opINT
value|opSHORT
end_define

begin_else
else|#
directive|else
else|PDP
end_else

begin_define
define|#
directive|define
name|opINT
value|opLONG
end_define

begin_endif
endif|#
directive|endif
endif|PDP
end_endif

begin_comment
comment|/* define	typALLOC	xx		/*  c var allocation types  */
end_comment

begin_define
define|#
directive|define
name|opAUTO
value|0
end_define

begin_define
define|#
directive|define
name|opSTATIC
value|1
end_define

begin_define
define|#
directive|define
name|opEXTERN
value|2
end_define

begin_define
define|#
directive|define
name|opREGISTER
value|3
end_define

end_unit

