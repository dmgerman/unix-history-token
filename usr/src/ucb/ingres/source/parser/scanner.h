begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **	SCANNER.H **	contains the global structures and variable declarations needed **	by the lexical analyzer.  This includes Manifest Constants and **	certain variables for internal communication purposes.  Therefore, **	extreme care should be exercised when modifying this file. ** **	Version: **		@(#)scanner.h	7.1	2/5/81 */
end_comment

begin_comment
comment|/* MANIFEST CONSTANTS */
end_comment

begin_define
define|#
directive|define
name|SBUFSIZ
value|2000
end_define

begin_comment
comment|/* max size of symbol table for */
end_comment

begin_define
define|#
directive|define
name|MAXSTRING
value|255
end_define

begin_comment
comment|/* max length of strings */
end_comment

begin_define
define|#
directive|define
name|GOVAL
value|-1
end_define

begin_comment
comment|/* semantic value for command names */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WARN
end_ifndef

begin_define
define|#
directive|define
name|WARN
value|0
end_define

begin_define
define|#
directive|define
name|FATAL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONSTANTS FOR THE GET_SCANNER CALL */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|0
end_define

begin_comment
comment|/* get a character from front */
end_comment

begin_define
define|#
directive|define
name|PRIME
value|1
end_define

begin_comment
comment|/* prime the front end */
end_comment

begin_define
define|#
directive|define
name|SYNC
value|2
end_define

begin_comment
comment|/* sync the front end */
end_comment

begin_comment
comment|/* CHARACTER TYPES */
end_comment

begin_define
define|#
directive|define
name|ALPHA
value|1
end_define

begin_define
define|#
directive|define
name|NUMBR
value|2
end_define

begin_define
define|#
directive|define
name|OPATR
value|3
end_define

begin_define
define|#
directive|define
name|PUNCT
value|4
end_define

begin_define
define|#
directive|define
name|CNTRL
value|5
end_define

begin_comment
comment|/* Modes for input from EQUEL front end */
end_comment

begin_define
define|#
directive|define
name|CVAR_I2
value|'\1'
end_define

begin_comment
comment|/* 2 byte integer */
end_comment

begin_define
define|#
directive|define
name|CVAR_F8
value|'\4'
end_define

begin_comment
comment|/* 8 byte floating number */
end_comment

begin_define
define|#
directive|define
name|CVAR_S
value|'\3'
end_define

begin_comment
comment|/* string with null byte */
end_comment

begin_define
define|#
directive|define
name|CVAR_I4
value|'\6'
end_define

begin_comment
comment|/* 4 byte integer */
end_comment

begin_comment
comment|/* error number definitions */
end_comment

begin_define
define|#
directive|define
name|SYMERR
value|2600
end_define

begin_comment
comment|/* syntactic error */
end_comment

begin_define
define|#
directive|define
name|STRTERM
value|2700
end_define

begin_comment
comment|/* non term string */
end_comment

begin_define
define|#
directive|define
name|STRLONG
value|2701
end_define

begin_comment
comment|/* string too long */
end_comment

begin_define
define|#
directive|define
name|BADOP
value|2702
end_define

begin_comment
comment|/* can't find operator in tables */
end_comment

begin_define
define|#
directive|define
name|NAMELONG
value|2703
end_define

begin_comment
comment|/* name too long */
end_comment

begin_define
define|#
directive|define
name|SBUFOFLO
value|2704
end_define

begin_comment
comment|/* over flow symbol table */
end_comment

begin_define
define|#
directive|define
name|COMMTERM
value|2705
end_define

begin_comment
comment|/* non term comment */
end_comment

begin_define
define|#
directive|define
name|FCONSTERR
value|2707
end_define

begin_comment
comment|/* float constant error */
end_comment

begin_define
define|#
directive|define
name|CNTRLCHR
value|2708
end_define

begin_comment
comment|/* control char from equel */
end_comment

begin_define
define|#
directive|define
name|NUMBUFOFLO
value|2709
end_define

begin_comment
comment|/* buffer oflo in number.c */
end_comment

begin_comment
comment|/* error number for yacc stack overflow */
end_comment

begin_define
define|#
directive|define
name|YOVRFLOW
value|2800
end_define

begin_comment
comment|/* if yacc stack ^ */
end_comment

begin_comment
comment|/* KEYWORD and OPERATOR TABLE */
end_comment

begin_struct
struct|struct
name|optab
comment|/* key word/operator tables */
block|{
name|char
modifier|*
name|term
decl_stmt|;
comment|/* key word/operator body */
name|int
name|token
decl_stmt|;
comment|/* associated parser token */
name|int
name|opcode
decl_stmt|;
comment|/* associated parser opcode */
block|}
struct|;
end_struct

begin_comment
comment|/* SPECIAL TOKENS for scanner */
end_comment

begin_struct
struct|struct
name|special
block|{
name|int
name|sconst
decl_stmt|;
name|int
name|bgncmnt
decl_stmt|;
name|int
name|endcmnt
decl_stmt|;
name|int
name|i2const
decl_stmt|;
name|int
name|i4const
decl_stmt|;
name|int
name|f4const
decl_stmt|;
name|int
name|f8const
decl_stmt|;
name|int
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* last token struct */
end_comment

begin_struct
struct|struct
name|lastok
block|{
name|int
name|toktyp
decl_stmt|;
name|char
modifier|*
name|tok
decl_stmt|;
name|int
name|tokop
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* declarations */
end_comment

begin_decl_stmt
name|struct
name|special
name|Tokens
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special tokens table */
end_comment

begin_decl_stmt
name|struct
name|optab
name|Optab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operator table */
end_comment

begin_decl_stmt
name|struct
name|optab
name|Keyword
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyword table */
end_comment

begin_decl_stmt
name|struct
name|lastok
name|Lastok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Opcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* opcode for current token */
end_comment

begin_decl_stmt
name|int
name|Lcase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UPPER->lower conversion flag */
end_comment

begin_decl_stmt
name|int
name|Pars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for call to getcvar or not */
end_comment

begin_decl_stmt
name|int
name|Newline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if last char read was a newline */
end_comment

begin_decl_stmt
name|int
name|Cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if line of C-code recognized */
end_comment

begin_decl_stmt
name|int
name|Keyent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries in the Keyword table */
end_comment

begin_decl_stmt
name|char
name|Sbuf
index|[
name|SBUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symbol table buffer */
end_comment

begin_comment
comment|/* **	TRACE FLAG ASSIGNMENTS **	Comment, Expand		70 **	Name, String		71 **	Number, Yylex		72 **	Operator		73 **	Inout			74 */
end_comment

end_unit

