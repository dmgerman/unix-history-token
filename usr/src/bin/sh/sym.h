begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	sym.h	4.1	82/05/07	*/
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX shell  */
end_comment

begin_comment
comment|/* symbols for parsing */
end_comment

begin_define
define|#
directive|define
name|DOSYM
value|0405
end_define

begin_define
define|#
directive|define
name|FISYM
value|0420
end_define

begin_define
define|#
directive|define
name|EFSYM
value|0422
end_define

begin_define
define|#
directive|define
name|ELSYM
value|0421
end_define

begin_define
define|#
directive|define
name|INSYM
value|0412
end_define

begin_define
define|#
directive|define
name|BRSYM
value|0406
end_define

begin_define
define|#
directive|define
name|KTSYM
value|0450
end_define

begin_define
define|#
directive|define
name|THSYM
value|0444
end_define

begin_define
define|#
directive|define
name|ODSYM
value|0441
end_define

begin_define
define|#
directive|define
name|ESSYM
value|0442
end_define

begin_define
define|#
directive|define
name|IFSYM
value|0436
end_define

begin_define
define|#
directive|define
name|FORSYM
value|0435
end_define

begin_define
define|#
directive|define
name|WHSYM
value|0433
end_define

begin_define
define|#
directive|define
name|UNSYM
value|0427
end_define

begin_define
define|#
directive|define
name|CASYM
value|0417
end_define

begin_define
define|#
directive|define
name|SYMREP
value|04000
end_define

begin_define
define|#
directive|define
name|ECSYM
value|(SYMREP|';')
end_define

begin_define
define|#
directive|define
name|ANDFSYM
value|(SYMREP|'&')
end_define

begin_define
define|#
directive|define
name|ORFSYM
value|(SYMREP|'|')
end_define

begin_define
define|#
directive|define
name|APPSYM
value|(SYMREP|'>')
end_define

begin_define
define|#
directive|define
name|DOCSYM
value|(SYMREP|'<')
end_define

begin_define
define|#
directive|define
name|EOFSYM
value|02000
end_define

begin_define
define|#
directive|define
name|SYMFLG
value|0400
end_define

begin_comment
comment|/* arg to `cmd' */
end_comment

begin_define
define|#
directive|define
name|NLFLG
value|1
end_define

begin_define
define|#
directive|define
name|MTFLG
value|2
end_define

begin_comment
comment|/* for peekc */
end_comment

begin_define
define|#
directive|define
name|MARK
value|0100000
end_define

begin_comment
comment|/* odd chars */
end_comment

begin_define
define|#
directive|define
name|DQUOTE
value|'"'
end_define

begin_define
define|#
directive|define
name|SQUOTE
value|'`'
end_define

begin_define
define|#
directive|define
name|LITERAL
value|'\''
end_define

begin_define
define|#
directive|define
name|DOLLAR
value|'$'
end_define

begin_define
define|#
directive|define
name|ESCAPE
value|'\\'
end_define

begin_define
define|#
directive|define
name|BRACE
value|'{'
end_define

end_unit

