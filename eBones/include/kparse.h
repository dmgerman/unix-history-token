begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * Include file for kparse routines.  *  *	from: kparse.h,v 4.5 89/01/11 12:05:53 steiner Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KPARSE_DEFS
end_ifndef

begin_define
define|#
directive|define
name|KPARSE_DEFS
end_define

begin_comment
comment|/*  * values returned by fGetParameterSet()  */
end_comment

begin_define
define|#
directive|define
name|PS_BAD_KEYWORD
value|-2
end_define

begin_comment
comment|/* unknown or duplicate keyword */
end_comment

begin_define
define|#
directive|define
name|PS_SYNTAX
value|-1
end_define

begin_comment
comment|/* syntax error */
end_comment

begin_define
define|#
directive|define
name|PS_OKAY
value|0
end_define

begin_comment
comment|/* got a complete parameter set */
end_comment

begin_define
define|#
directive|define
name|PS_EOF
value|1
end_define

begin_comment
comment|/* nothing more in the file */
end_comment

begin_comment
comment|/*  * values returned by fGetKeywordValue()  */
end_comment

begin_define
define|#
directive|define
name|KV_SYNTAX
value|-2
end_define

begin_comment
comment|/* syntax error */
end_comment

begin_define
define|#
directive|define
name|KV_EOF
value|-1
end_define

begin_comment
comment|/* nothing more in the file */
end_comment

begin_define
define|#
directive|define
name|KV_OKAY
value|0
end_define

begin_comment
comment|/* got a keyword/value pair */
end_comment

begin_define
define|#
directive|define
name|KV_EOL
value|1
end_define

begin_comment
comment|/* nothing more on this line */
end_comment

begin_comment
comment|/*  * values returned by fGetToken()  */
end_comment

begin_define
define|#
directive|define
name|GTOK_BAD_QSTRING
value|-1
end_define

begin_comment
comment|/* newline found in quoted string */
end_comment

begin_define
define|#
directive|define
name|GTOK_EOF
value|0
end_define

begin_comment
comment|/* end of file encountered */
end_comment

begin_define
define|#
directive|define
name|GTOK_QSTRING
value|1
end_define

begin_comment
comment|/* quoted string */
end_comment

begin_define
define|#
directive|define
name|GTOK_STRING
value|2
end_define

begin_comment
comment|/* unquoted string */
end_comment

begin_define
define|#
directive|define
name|GTOK_NUMBER
value|3
end_define

begin_comment
comment|/* one or more digits */
end_comment

begin_define
define|#
directive|define
name|GTOK_PUNK
value|4
end_define

begin_comment
comment|/* punks are punctuation, newline, 				 * etc. */
end_comment

begin_define
define|#
directive|define
name|GTOK_WHITE
value|5
end_define

begin_comment
comment|/* one or more whitespace chars */
end_comment

begin_comment
comment|/*  * extended character classification macros  */
end_comment

begin_define
define|#
directive|define
name|ISOCTAL
parameter_list|(
name|CH
parameter_list|)
value|( (CH>='0')&& (CH<='7') )
end_define

begin_define
define|#
directive|define
name|ISQUOTE
parameter_list|(
name|CH
parameter_list|)
value|( (CH=='\"') || (CH=='\'') || (CH=='`') )
end_define

begin_define
define|#
directive|define
name|ISWHITESPACE
parameter_list|(
name|C
parameter_list|)
value|( (C==' ')   || (C=='\t') )
end_define

begin_define
define|#
directive|define
name|ISLINEFEED
parameter_list|(
name|C
parameter_list|)
value|( (C=='\n')  || (C=='\r')  || (C=='\f') )
end_define

begin_comment
comment|/*  * tokens consist of any printable charcacter except comma, equal, or  * whitespace  */
end_comment

begin_define
define|#
directive|define
name|ISTOKENCHAR
parameter_list|(
name|C
parameter_list|)
value|((C>040)&& (C<0177)&& (C != ',')&& (C != '='))
end_define

begin_comment
comment|/*  * the parameter table defines the keywords that will be recognized by  * fGetParameterSet, and their default values if not specified.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|keyword
decl_stmt|;
name|char
modifier|*
name|defvalue
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
name|parmtable
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PARMCOUNT
parameter_list|(
name|P
parameter_list|)
value|(sizeof(P)/sizeof(P[0]))
end_define

begin_decl_stmt
specifier|extern
name|int
name|LineNbr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current line # in parameter file */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ErrorMsg
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 				 * meaningful only when KV_SYNTAX,  				 * PS_SYNTAX,  or PS_BAD_KEYWORD is 				 * returned by fGetKeywordValue or 				 * fGetParameterSet 				 */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsave
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* defined in this module */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strutol
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* defined in this module */
end_comment

begin_function_decl
name|int
name|fGetParameterSet
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|parmtable
name|parm
index|[]
parameter_list|,
name|int
name|parmcount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fGetKeywordValue
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|char
modifier|*
name|keyword
parameter_list|,
name|int
name|klen
parameter_list|,
name|char
modifier|*
name|value
parameter_list|,
name|int
name|vlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fGetToken
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KPARSE_DEFS */
end_comment

end_unit

