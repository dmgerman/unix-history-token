begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/Tekparse.h,v $  *	$Header: Tekparse.h,v 10.100 86/12/01 14:39:07 jg Rel $  */
end_comment

begin_comment
comment|/* @(#)Tekparse.h       X10/6.6B 12/26/86 */
end_comment

begin_define
define|#
directive|define
name|CASE_REPORT
value|0
end_define

begin_define
define|#
directive|define
name|CASE_VT_MODE
value|(CASE_REPORT + 1)
end_define

begin_define
define|#
directive|define
name|CASE_SPT_STATE
value|(CASE_VT_MODE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_GIN
value|(CASE_SPT_STATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_BEL
value|(CASE_GIN + 1)
end_define

begin_define
define|#
directive|define
name|CASE_BS
value|(CASE_BEL + 1)
end_define

begin_define
define|#
directive|define
name|CASE_PT_STATE
value|(CASE_BS + 1)
end_define

begin_define
define|#
directive|define
name|CASE_PLT_STATE
value|(CASE_PT_STATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_TAB
value|(CASE_PLT_STATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_IPL_STATE
value|(CASE_TAB + 1)
end_define

begin_define
define|#
directive|define
name|CASE_ALP_STATE
value|(CASE_IPL_STATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_UP
value|(CASE_ALP_STATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_COPY
value|(CASE_UP + 1)
end_define

begin_define
define|#
directive|define
name|CASE_PAGE
value|(CASE_COPY + 1)
end_define

begin_define
define|#
directive|define
name|CASE_BES_STATE
value|(CASE_PAGE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_BYP_STATE
value|(CASE_BES_STATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_IGNORE
value|(CASE_BYP_STATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_ASCII
value|(CASE_IGNORE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_APL
value|(CASE_ASCII + 1)
end_define

begin_define
define|#
directive|define
name|CASE_CHAR_SIZE
value|(CASE_APL + 1)
end_define

begin_define
define|#
directive|define
name|CASE_BEAM_VEC
value|(CASE_CHAR_SIZE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_CURSTATE
value|(CASE_BEAM_VEC + 1)
end_define

begin_define
define|#
directive|define
name|CASE_PENUP
value|(CASE_CURSTATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_PENDOWN
value|(CASE_PENUP + 1)
end_define

begin_define
define|#
directive|define
name|CASE_IPL_POINT
value|(CASE_PENDOWN + 1)
end_define

begin_define
define|#
directive|define
name|CASE_PLT_VEC
value|(CASE_IPL_POINT + 1)
end_define

begin_define
define|#
directive|define
name|CASE_PT_POINT
value|(CASE_PLT_VEC + 1)
end_define

begin_define
define|#
directive|define
name|CASE_SPT_POINT
value|(CASE_PT_POINT + 1)
end_define

begin_define
define|#
directive|define
name|CASE_CR
value|(CASE_SPT_POINT + 1)
end_define

begin_define
define|#
directive|define
name|CASE_ESC_STATE
value|(CASE_CR + 1)
end_define

begin_define
define|#
directive|define
name|CASE_LF
value|(CASE_ESC_STATE + 1)
end_define

begin_define
define|#
directive|define
name|CASE_SP
value|(CASE_LF + 1)
end_define

begin_define
define|#
directive|define
name|CASE_PRINT
value|(CASE_SP + 1)
end_define

begin_define
define|#
directive|define
name|CASE_OSC
value|(CASE_PRINT + 1)
end_define

end_unit

