begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)$Id: fmtcompile.h,v 1.10 1993/06/12 06:46:16 jromine Exp $ */
end_comment

begin_comment
comment|/* Format Types */
end_comment

begin_comment
comment|/* -------------*/
end_comment

begin_comment
comment|/* types that output text */
end_comment

begin_define
define|#
directive|define
name|FT_COMP
value|1
end_define

begin_comment
comment|/* the text of a component */
end_comment

begin_define
define|#
directive|define
name|FT_COMPF
value|2
end_define

begin_comment
comment|/* comp text, filled */
end_comment

begin_define
define|#
directive|define
name|FT_LIT
value|3
end_define

begin_comment
comment|/* literal text */
end_comment

begin_define
define|#
directive|define
name|FT_LITF
value|4
end_define

begin_comment
comment|/* literal text, filled */
end_comment

begin_define
define|#
directive|define
name|FT_CHAR
value|5
end_define

begin_comment
comment|/* a single ascii character */
end_comment

begin_define
define|#
directive|define
name|FT_NUM
value|6
end_define

begin_comment
comment|/* "value" as decimal number */
end_comment

begin_define
define|#
directive|define
name|FT_NUMF
value|7
end_define

begin_comment
comment|/* "value" as filled dec number */
end_comment

begin_define
define|#
directive|define
name|FT_STR
value|8
end_define

begin_comment
comment|/* "str" as text */
end_comment

begin_define
define|#
directive|define
name|FT_STRF
value|9
end_define

begin_comment
comment|/* "str" as text, filled */
end_comment

begin_define
define|#
directive|define
name|FT_STRFW
value|10
end_define

begin_comment
comment|/* "str" as text, filled, width in "value" */
end_comment

begin_define
define|#
directive|define
name|FT_PUTADDR
value|11
end_define

begin_comment
comment|/* split and print address line */
end_comment

begin_comment
comment|/* types that modify the "str" or "value" registers */
end_comment

begin_define
define|#
directive|define
name|FT_LS_COMP
value|12
end_define

begin_comment
comment|/* set "str" to component text */
end_comment

begin_define
define|#
directive|define
name|FT_LS_LIT
value|13
end_define

begin_comment
comment|/* set "str" to literal text */
end_comment

begin_define
define|#
directive|define
name|FT_LS_GETENV
value|14
end_define

begin_comment
comment|/* set "str" to getenv(text) */
end_comment

begin_define
define|#
directive|define
name|FT_LS_MFIND
value|15
end_define

begin_comment
comment|/* set "str" to m_find(text) */
end_comment

begin_define
define|#
directive|define
name|FT_LS_TRIM
value|16
end_define

begin_comment
comment|/* trim trailing white space from "str" */
end_comment

begin_define
define|#
directive|define
name|FT_LV_COMP
value|17
end_define

begin_comment
comment|/* set "value" to comp (as dec. num) */
end_comment

begin_define
define|#
directive|define
name|FT_LV_COMPFLAG
value|18
end_define

begin_comment
comment|/* set "value" to comp flag word */
end_comment

begin_define
define|#
directive|define
name|FT_LV_LIT
value|19
end_define

begin_comment
comment|/* set "value" to literal num */
end_comment

begin_define
define|#
directive|define
name|FT_LV_DAT
value|20
end_define

begin_comment
comment|/* set "value" to dat[n] */
end_comment

begin_define
define|#
directive|define
name|FT_LV_STRLEN
value|21
end_define

begin_comment
comment|/* set "value" to length of "str" */
end_comment

begin_define
define|#
directive|define
name|FT_LV_PLUS_L
value|22
end_define

begin_comment
comment|/* set "value" += literal */
end_comment

begin_define
define|#
directive|define
name|FT_LV_MINUS_L
value|23
end_define

begin_comment
comment|/* set "value" -= literal */
end_comment

begin_define
define|#
directive|define
name|FT_LV_DIVIDE_L
value|24
end_define

begin_comment
comment|/* set "value" to value / literal */
end_comment

begin_define
define|#
directive|define
name|FT_LV_MODULO_L
value|25
end_define

begin_comment
comment|/* set "value" to value % literal */
end_comment

begin_define
define|#
directive|define
name|FT_LV_CHAR_LEFT
value|26
end_define

begin_comment
comment|/* set "value" to char left in output */
end_comment

begin_define
define|#
directive|define
name|FT_LS_MONTH
value|27
end_define

begin_comment
comment|/* set "str" to tws month */
end_comment

begin_define
define|#
directive|define
name|FT_LS_LMONTH
value|28
end_define

begin_comment
comment|/* set "str" to long tws month */
end_comment

begin_define
define|#
directive|define
name|FT_LS_ZONE
value|29
end_define

begin_comment
comment|/* set "str" to tws timezone */
end_comment

begin_define
define|#
directive|define
name|FT_LS_DAY
value|30
end_define

begin_comment
comment|/* set "str" to tws weekday */
end_comment

begin_define
define|#
directive|define
name|FT_LS_WEEKDAY
value|31
end_define

begin_comment
comment|/* set "str" to long tws weekday */
end_comment

begin_define
define|#
directive|define
name|FT_LS_822DATE
value|32
end_define

begin_comment
comment|/* set "str" to 822 date str */
end_comment

begin_define
define|#
directive|define
name|FT_LS_PRETTY
value|33
end_define

begin_comment
comment|/* set "str" to pretty (?) date str */
end_comment

begin_define
define|#
directive|define
name|FT_LV_SEC
value|34
end_define

begin_comment
comment|/* set "value" to tws second */
end_comment

begin_define
define|#
directive|define
name|FT_LV_MIN
value|35
end_define

begin_comment
comment|/* set "value" to tws minute */
end_comment

begin_define
define|#
directive|define
name|FT_LV_HOUR
value|36
end_define

begin_comment
comment|/* set "value" to tws hour */
end_comment

begin_define
define|#
directive|define
name|FT_LV_MDAY
value|37
end_define

begin_comment
comment|/* set "value" to tws day of month */
end_comment

begin_define
define|#
directive|define
name|FT_LV_MON
value|38
end_define

begin_comment
comment|/* set "value" to tws month */
end_comment

begin_define
define|#
directive|define
name|FT_LV_YEAR
value|39
end_define

begin_comment
comment|/* set "value" to tws year */
end_comment

begin_define
define|#
directive|define
name|FT_LV_YDAY
value|40
end_define

begin_comment
comment|/* set "value" to tws day of year */
end_comment

begin_define
define|#
directive|define
name|FT_LV_WDAY
value|41
end_define

begin_comment
comment|/* set "value" to tws weekday */
end_comment

begin_define
define|#
directive|define
name|FT_LV_ZONE
value|42
end_define

begin_comment
comment|/* set "value" to tws timezone */
end_comment

begin_define
define|#
directive|define
name|FT_LV_CLOCK
value|43
end_define

begin_comment
comment|/* set "value" to tws clock */
end_comment

begin_define
define|#
directive|define
name|FT_LV_RCLOCK
value|44
end_define

begin_comment
comment|/* set "value" to now - tws clock */
end_comment

begin_define
define|#
directive|define
name|FT_LV_DAYF
value|45
end_define

begin_comment
comment|/* set "value" to tws day flag */
end_comment

begin_define
define|#
directive|define
name|FT_LV_DST
value|46
end_define

begin_comment
comment|/* set "value" to tws daylight savings flag */
end_comment

begin_define
define|#
directive|define
name|FT_LV_ZONEF
value|47
end_define

begin_comment
comment|/* set "value" to tws timezone flag */
end_comment

begin_define
define|#
directive|define
name|FT_LS_PERS
value|48
end_define

begin_comment
comment|/* set "str" to person part of addr */
end_comment

begin_define
define|#
directive|define
name|FT_LS_MBOX
value|49
end_define

begin_comment
comment|/* set "str" to mbox part of addr */
end_comment

begin_define
define|#
directive|define
name|FT_LS_HOST
value|50
end_define

begin_comment
comment|/* set "str" to host part of addr */
end_comment

begin_define
define|#
directive|define
name|FT_LS_PATH
value|51
end_define

begin_comment
comment|/* set "str" to route part of addr */
end_comment

begin_define
define|#
directive|define
name|FT_LS_GNAME
value|52
end_define

begin_comment
comment|/* set "str" to group part of addr */
end_comment

begin_define
define|#
directive|define
name|FT_LS_NOTE
value|53
end_define

begin_comment
comment|/* set "str" to comment part of addr */
end_comment

begin_define
define|#
directive|define
name|FT_LS_ADDR
value|54
end_define

begin_comment
comment|/* set "str" to mbox@host */
end_comment

begin_define
define|#
directive|define
name|FT_LS_822ADDR
value|55
end_define

begin_comment
comment|/* set "str" to 822 format addr */
end_comment

begin_define
define|#
directive|define
name|FT_LS_FRIENDLY
value|56
end_define

begin_comment
comment|/* set "str" to "friendly" format addr */
end_comment

begin_define
define|#
directive|define
name|FT_LV_HOSTTYPE
value|57
end_define

begin_comment
comment|/* set "value" to addr host type */
end_comment

begin_define
define|#
directive|define
name|FT_LV_INGRPF
value|58
end_define

begin_comment
comment|/* set "value" to addr in-group flag */
end_comment

begin_define
define|#
directive|define
name|FT_LV_NOHOSTF
value|59
end_define

begin_comment
comment|/* set "value" to addr no-host flag */
end_comment

begin_comment
comment|/* Date Coercion */
end_comment

begin_define
define|#
directive|define
name|FT_LOCALDATE
value|60
end_define

begin_comment
comment|/* Coerce date to local timezone */
end_comment

begin_define
define|#
directive|define
name|FT_GMTDATE
value|61
end_define

begin_comment
comment|/* Coerce date to gmt */
end_comment

begin_comment
comment|/* pre-format processing */
end_comment

begin_define
define|#
directive|define
name|FT_PARSEDATE
value|62
end_define

begin_comment
comment|/* parse comp into a date (tws) struct */
end_comment

begin_define
define|#
directive|define
name|FT_PARSEADDR
value|63
end_define

begin_comment
comment|/* parse comp into a mailaddr struct */
end_comment

begin_define
define|#
directive|define
name|FT_FORMATADDR
value|64
end_define

begin_comment
comment|/* let external routine format addr */
end_comment

begin_define
define|#
directive|define
name|FT_MYMBOX
value|65
end_define

begin_comment
comment|/* do "mymbox" test on comp */
end_comment

begin_comment
comment|/* misc. */
end_comment

begin_comment
comment|/* ADDTOSEQ only works if you include "options LBL" */
end_comment

begin_define
define|#
directive|define
name|FT_ADDTOSEQ
value|66
end_define

begin_comment
comment|/* add current msg to a sequence */
end_comment

begin_comment
comment|/* conditionals& control flow (must be last) */
end_comment

begin_define
define|#
directive|define
name|FT_SAVESTR
value|67
end_define

begin_comment
comment|/* save current str reg */
end_comment

begin_define
define|#
directive|define
name|FT_DONE
value|68
end_define

begin_comment
comment|/* stop formatting */
end_comment

begin_define
define|#
directive|define
name|FT_PAUSE
value|69
end_define

begin_comment
comment|/* pause */
end_comment

begin_define
define|#
directive|define
name|FT_NOP
value|70
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|FT_GOTO
value|71
end_define

begin_comment
comment|/* (relative) goto */
end_comment

begin_define
define|#
directive|define
name|FT_IF_S_NULL
value|72
end_define

begin_comment
comment|/* test if "str" null */
end_comment

begin_define
define|#
directive|define
name|FT_IF_S
value|73
end_define

begin_comment
comment|/* test if "str" non-null */
end_comment

begin_define
define|#
directive|define
name|FT_IF_V_EQ
value|74
end_define

begin_comment
comment|/* test if "value" = literal */
end_comment

begin_define
define|#
directive|define
name|FT_IF_V_NE
value|75
end_define

begin_comment
comment|/* test if "value" != literal */
end_comment

begin_define
define|#
directive|define
name|FT_IF_V_GT
value|76
end_define

begin_comment
comment|/* test if "value"> literal */
end_comment

begin_define
define|#
directive|define
name|FT_IF_MATCH
value|77
end_define

begin_comment
comment|/* test if "str" contains literal */
end_comment

begin_define
define|#
directive|define
name|FT_IF_AMATCH
value|78
end_define

begin_comment
comment|/* test if "str" starts with literal */
end_comment

begin_define
define|#
directive|define
name|FT_S_NULL
value|79
end_define

begin_comment
comment|/* V = 1 if "str" null */
end_comment

begin_define
define|#
directive|define
name|FT_S_NONNULL
value|80
end_define

begin_comment
comment|/* V = 1 if "str" non-null */
end_comment

begin_define
define|#
directive|define
name|FT_V_EQ
value|81
end_define

begin_comment
comment|/* V = 1 if "value" = literal */
end_comment

begin_define
define|#
directive|define
name|FT_V_NE
value|82
end_define

begin_comment
comment|/* V = 1 if "value" != literal */
end_comment

begin_define
define|#
directive|define
name|FT_V_GT
value|83
end_define

begin_comment
comment|/* V = 1 if "value"> literal */
end_comment

begin_define
define|#
directive|define
name|FT_V_MATCH
value|84
end_define

begin_comment
comment|/* V = 1 if "str" contains literal */
end_comment

begin_define
define|#
directive|define
name|FT_V_AMATCH
value|85
end_define

begin_comment
comment|/* V = 1 if "str" starts with literal */
end_comment

begin_define
define|#
directive|define
name|IF_FUNCS
value|FT_S_NULL
end_define

begin_comment
comment|/* start of "if" functions */
end_comment

end_unit

