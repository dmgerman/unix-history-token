begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/VTparse.h,v $  *	$Header: VTparse.h,v 10.101 86/12/01 21:49:38 jg Rel $  */
end_comment

begin_comment
comment|/* @(#)VTparse.h       X10/6.6B 12/26/86 */
end_comment

begin_define
define|#
directive|define
name|CASE_GROUND_STATE
value|0
end_define

begin_define
define|#
directive|define
name|CASE_IGNORE_STATE
value|(CASE_GROUND_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_IGNORE_ESC
value|(CASE_IGNORE_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_IGNORE
value|(CASE_IGNORE_ESC+1)
end_define

begin_define
define|#
directive|define
name|CASE_BELL
value|(CASE_IGNORE+1)
end_define

begin_define
define|#
directive|define
name|CASE_BS
value|(CASE_BELL+1)
end_define

begin_define
define|#
directive|define
name|CASE_CR
value|(CASE_BS+1)
end_define

begin_define
define|#
directive|define
name|CASE_ESC
value|(CASE_CR+1)
end_define

begin_define
define|#
directive|define
name|CASE_VMOT
value|(CASE_ESC+1)
end_define

begin_define
define|#
directive|define
name|CASE_TAB
value|(CASE_VMOT+1)
end_define

begin_define
define|#
directive|define
name|CASE_SI
value|(CASE_TAB+1)
end_define

begin_define
define|#
directive|define
name|CASE_SO
value|(CASE_SI+1)
end_define

begin_define
define|#
directive|define
name|CASE_SCR_STATE
value|(CASE_SO+1)
end_define

begin_define
define|#
directive|define
name|CASE_SCS0_STATE
value|(CASE_SCR_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_SCS1_STATE
value|(CASE_SCS0_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_SCS2_STATE
value|(CASE_SCS1_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_SCS3_STATE
value|(CASE_SCS2_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_ESC_IGNORE
value|(CASE_SCS3_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_ESC_DIGIT
value|(CASE_ESC_IGNORE+1)
end_define

begin_define
define|#
directive|define
name|CASE_ESC_SEMI
value|(CASE_ESC_DIGIT+1)
end_define

begin_define
define|#
directive|define
name|CASE_DEC_STATE
value|(CASE_ESC_SEMI+1)
end_define

begin_define
define|#
directive|define
name|CASE_ICH
value|(CASE_DEC_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_CUU
value|(CASE_ICH+1)
end_define

begin_define
define|#
directive|define
name|CASE_CUD
value|(CASE_CUU+1)
end_define

begin_define
define|#
directive|define
name|CASE_CUF
value|(CASE_CUD+1)
end_define

begin_define
define|#
directive|define
name|CASE_CUB
value|(CASE_CUF+1)
end_define

begin_define
define|#
directive|define
name|CASE_CUP
value|(CASE_CUB+1)
end_define

begin_define
define|#
directive|define
name|CASE_ED
value|(CASE_CUP+1)
end_define

begin_define
define|#
directive|define
name|CASE_EL
value|(CASE_ED+1)
end_define

begin_define
define|#
directive|define
name|CASE_IL
value|(CASE_EL+1)
end_define

begin_define
define|#
directive|define
name|CASE_DL
value|(CASE_IL+1)
end_define

begin_define
define|#
directive|define
name|CASE_DCH
value|(CASE_DL+1)
end_define

begin_define
define|#
directive|define
name|CASE_DA1
value|(CASE_DCH+1)
end_define

begin_define
define|#
directive|define
name|CASE_TBC
value|(CASE_DA1+1)
end_define

begin_define
define|#
directive|define
name|CASE_SET
value|(CASE_TBC+1)
end_define

begin_define
define|#
directive|define
name|CASE_RST
value|(CASE_SET+1)
end_define

begin_define
define|#
directive|define
name|CASE_SGR
value|(CASE_RST+1)
end_define

begin_define
define|#
directive|define
name|CASE_CPR
value|(CASE_SGR+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECSTBM
value|(CASE_CPR+1)
end_define

begin_define
define|#
directive|define
name|CASE_SUN_EMU
value|(CASE_DECSTBM+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECREQTPARM
value|(CASE_SUN_EMU+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECSET
value|(CASE_DECREQTPARM+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECRST
value|(CASE_DECSET+1)
end_define

begin_define
define|#
directive|define
name|CASE_HIDDEN
value|(CASE_DECRST+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECALN
value|(CASE_HIDDEN+1)
end_define

begin_define
define|#
directive|define
name|CASE_GSETS
value|(CASE_DECALN+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECSC
value|(CASE_GSETS+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECRC
value|(CASE_DECSC+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECKPAM
value|(CASE_DECRC+1)
end_define

begin_define
define|#
directive|define
name|CASE_DECKPNM
value|(CASE_DECKPAM+1)
end_define

begin_define
define|#
directive|define
name|CASE_IND
value|(CASE_DECKPNM+1)
end_define

begin_define
define|#
directive|define
name|CASE_NEL
value|(CASE_IND+1)
end_define

begin_define
define|#
directive|define
name|CASE_HTS
value|(CASE_NEL+1)
end_define

begin_define
define|#
directive|define
name|CASE_RI
value|(CASE_HTS+1)
end_define

begin_define
define|#
directive|define
name|CASE_SS2
value|(CASE_RI+1)
end_define

begin_define
define|#
directive|define
name|CASE_SS3
value|(CASE_SS2+1)
end_define

begin_define
define|#
directive|define
name|CASE_CSI_STATE
value|(CASE_SS3+1)
end_define

begin_define
define|#
directive|define
name|CASE_OSC
value|(CASE_CSI_STATE+1)
end_define

begin_define
define|#
directive|define
name|CASE_RIS
value|(CASE_OSC+1)
end_define

begin_define
define|#
directive|define
name|CASE_LS2
value|(CASE_RIS+1)
end_define

begin_define
define|#
directive|define
name|CASE_LS3
value|(CASE_LS2+1)
end_define

begin_define
define|#
directive|define
name|CASE_LS3R
value|(CASE_LS3+1)
end_define

begin_define
define|#
directive|define
name|CASE_LS2R
value|(CASE_LS3R+1)
end_define

begin_define
define|#
directive|define
name|CASE_LS1R
value|(CASE_LS2R+1)
end_define

begin_define
define|#
directive|define
name|CASE_PRINT
value|(CASE_LS1R+1)
end_define

begin_define
define|#
directive|define
name|CASE_TO_STATUS
value|(CASE_PRINT+1)
end_define

begin_define
define|#
directive|define
name|CASE_FROM_STATUS
value|(CASE_TO_STATUS+1)
end_define

begin_define
define|#
directive|define
name|CASE_SHOW_STATUS
value|(CASE_FROM_STATUS+1)
end_define

begin_define
define|#
directive|define
name|CASE_HIDE_STATUS
value|(CASE_SHOW_STATUS+1)
end_define

begin_define
define|#
directive|define
name|CASE_ERASE_STATUS
value|(CASE_HIDE_STATUS+1)
end_define

begin_define
define|#
directive|define
name|CASE_XTERM_SAVE
value|(CASE_ERASE_STATUS+1)
end_define

begin_define
define|#
directive|define
name|CASE_XTERM_RESTORE
value|(CASE_XTERM_SAVE+1)
end_define

end_unit

