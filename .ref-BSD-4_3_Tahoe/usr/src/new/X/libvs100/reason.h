begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* reason.h	Interrupt reason values for Nov 84 firmware  *  * Author:	Paul J. Asente  * 		Digital Equipment Corporation  * 		Western Reseach Lab  * Date:	Sept 1985  */
end_comment

begin_comment
comment|/****************************************************************************  *									    *  *  Copyright (c) 1985 by						    *  *  DIGITAL EQUIPMENT CORPORATION, Maynard, Massachusetts.		    *  *  All rights reserved.						    *  * 									    *  *  This software is furnished under a license and may be used and copied   *  *  only in  accordance with  the  terms  of  such  license  and with the   *  *  inclusion of the above copyright notice. This software or  any  other   *  *  copies thereof may not be provided or otherwise made available to any   *  *  other person.  No title to and ownership of  the  software is  hereby   *  *  transferred.							    *  * 									    *  *  The information in this software is  subject to change without notice   *  *  and  should  not  be  construed as  a commitment by DIGITAL EQUIPMENT   *  *  CORPORATION.							    *  * 									    *  *  DIGITAL assumes no responsibility for the use  or  reliability of its   *  *  software on equipment which is not supplied by DIGITAL.		    *  * 									    *  *									    *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VS_REASONS
end_ifndef

begin_define
define|#
directive|define
name|VS_REASONS
end_define

begin_define
define|#
directive|define
name|IR_ID
value|1<<0
end_define

begin_define
define|#
directive|define
name|IR_ID_MSG
value|"initialization done"
end_define

begin_define
define|#
directive|define
name|IR_CD
value|1<<1
end_define

begin_define
define|#
directive|define
name|IR_CD_MSG
value|"command done"
end_define

begin_define
define|#
directive|define
name|IR_DCI
value|1<<2
end_define

begin_define
define|#
directive|define
name|IR_DCI_MSG
value|"display code initialized"
end_define

begin_define
define|#
directive|define
name|IR_DE
value|1<<3
end_define

begin_define
define|#
directive|define
name|IR_DE_MSG
value|"device event"
end_define

begin_define
define|#
directive|define
name|IR_CM
value|1<<4
end_define

begin_define
define|#
directive|define
name|IR_CM_MSG
value|"cursor moved"
end_define

begin_define
define|#
directive|define
name|IR_DPM
value|1<<5
end_define

begin_define
define|#
directive|define
name|IR_DPM_MSG
value|"data pad moved"
end_define

begin_define
define|#
directive|define
name|IR_MM
value|1<<6
end_define

begin_define
define|#
directive|define
name|IR_MM_MSG
value|"mouse moved"
end_define

begin_define
define|#
directive|define
name|IR_PD
value|1<<7
end_define

begin_define
define|#
directive|define
name|IR_PD_MSG
value|"powerup done"
end_define

begin_define
define|#
directive|define
name|IR_AB_ACK
value|1<<8
end_define

begin_define
define|#
directive|define
name|IR_AB_ACK_MSG
value|"abort acknowledge"
end_define

begin_define
define|#
directive|define
name|IR_STAT_ACK
value|1<<9
end_define

begin_define
define|#
directive|define
name|IR_STAT_ACK_MSG
value|"status acknowledge"
end_define

begin_define
define|#
directive|define
name|IR_SAVE_ACK
value|1<<10
end_define

begin_define
define|#
directive|define
name|IR_SAVE_ACK_MSG
value|"save_screen acknowledge"
end_define

begin_define
define|#
directive|define
name|IR_ERROR
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|ERR_NYI
value|IR_ERROR+0
end_define

begin_define
define|#
directive|define
name|ERR_NYI_MSG
value|"function not yet implemented"
end_define

begin_define
define|#
directive|define
name|ERR_IFC
value|IR_ERROR+1
end_define

begin_define
define|#
directive|define
name|ERR_IFC_MSG
value|"invalid function code"
end_define

begin_define
define|#
directive|define
name|ERR_ICC
value|IR_ERROR+2
end_define

begin_define
define|#
directive|define
name|ERR_ICC_MSG
value|"invalid command code"
end_define

begin_define
define|#
directive|define
name|ERR_BE_NXM_68K
value|IR_ERROR+3
end_define

begin_define
define|#
directive|define
name|ERR_BE_NXM_68K_MSG
value|"bus error:  receive nxm -- 68K unibus access"
end_define

begin_define
define|#
directive|define
name|ERR_BE_RO
value|IR_ERROR+4
end_define

begin_define
define|#
directive|define
name|ERR_BE_RO_MSG
value|"bus error:  retry overflow"
end_define

begin_define
define|#
directive|define
name|ERR_BE_LD
value|IR_ERROR+5
end_define

begin_define
define|#
directive|define
name|ERR_BE_LD_MSG
value|"bus error:  link down"
end_define

begin_define
define|#
directive|define
name|ERR_BE_S
value|IR_ERROR+6
end_define

begin_define
define|#
directive|define
name|ERR_BE_S_MSG
value|"bus error:  spurious"
end_define

begin_define
define|#
directive|define
name|ERR_AE
value|IR_ERROR+7
end_define

begin_define
define|#
directive|define
name|ERR_AE_MSG
value|"address error"
end_define

begin_define
define|#
directive|define
name|ERR_ZD
value|IR_ERROR+8
end_define

begin_define
define|#
directive|define
name|ERR_ZD_MSG
value|"zero divide"
end_define

begin_define
define|#
directive|define
name|ERR_II
value|IR_ERROR+9
end_define

begin_define
define|#
directive|define
name|ERR_II_MSG
value|"illegal instruction"
end_define

begin_define
define|#
directive|define
name|ERR_NXM_BBA
value|IR_ERROR+10
end_define

begin_define
define|#
directive|define
name|ERR_NXM_BBA_MSG
value|"receive nxm -- BBA unibus access"
end_define

begin_define
define|#
directive|define
name|ERR_BNI
value|IR_ERROR+11
end_define

begin_define
define|#
directive|define
name|ERR_BNI_MSG
value|"BBA not installed"
end_define

begin_define
define|#
directive|define
name|ERR_KCQO
value|IR_ERROR+12
end_define

begin_define
define|#
directive|define
name|ERR_KCQO_MSG
value|"keyboard command queue overflow"
end_define

begin_define
define|#
directive|define
name|ERR_DPCQO
value|IR_ERROR+13
end_define

begin_define
define|#
directive|define
name|ERR_DPCQO_MSG
value|"data pad command queue overflow"
end_define

begin_define
define|#
directive|define
name|ERR_MEQO
value|IR_ERROR+14
end_define

begin_define
define|#
directive|define
name|ERR_MEQO_MSG
value|"mouse event queue overflow"
end_define

begin_define
define|#
directive|define
name|ERR_DPEQO
value|IR_ERROR+15
end_define

begin_define
define|#
directive|define
name|ERR_DPEQO_MSG
value|"data pad event queue overflow"
end_define

begin_define
define|#
directive|define
name|ERR_AB_BBA
value|IR_ERROR+16
end_define

begin_define
define|#
directive|define
name|ERR_AB_BBA_MSG
value|"unable to abort the BBA"
end_define

begin_define
define|#
directive|define
name|ERR_KEQO
value|IR_ERROR+17
end_define

begin_define
define|#
directive|define
name|ERR_KEQO_MSG
value|"keyboard event queue overflow"
end_define

begin_define
define|#
directive|define
name|ERR_KOR
value|IR_ERROR+18
end_define

begin_define
define|#
directive|define
name|ERR_KOR_MSG
value|"keyboard overrun"
end_define

begin_define
define|#
directive|define
name|ERR_DPOR
value|IR_ERROR+19
end_define

begin_define
define|#
directive|define
name|ERR_DPOR_MSG
value|"data pad overrun"
end_define

begin_define
define|#
directive|define
name|ERR_KFE
value|IR_ERROR+20
end_define

begin_define
define|#
directive|define
name|ERR_KFE_MSG
value|"keyboard framing error"
end_define

begin_define
define|#
directive|define
name|ERR_DPFE
value|IR_ERROR+21
end_define

begin_define
define|#
directive|define
name|ERR_DPFE_MSG
value|"data pad framing error"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCM
value|IR_ERROR+32
end_define

begin_define
define|#
directive|define
name|ERR_ISRCM_MSG
value|"invalid source modifiers"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBW
value|IR_ERROR+33
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBW_MSG
value|"invalid source bitmap width"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBH
value|IR_ERROR+34
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBH_MSG
value|"invalid source bitmap height"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCC
value|IR_ERROR+35
end_define

begin_define
define|#
directive|define
name|ERR_ISRCC_MSG
value|"invalid source constant"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBD
value|IR_ERROR+36
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBD_MSG
value|"invalid source bitmap depth"
end_define

begin_define
define|#
directive|define
name|ERR_IMSKM
value|IR_ERROR+38
end_define

begin_define
define|#
directive|define
name|ERR_IMSKM_MSG
value|"invalid source mask modifiers"
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBW
value|IR_ERROR+39
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBW_MSG
value|"invalid source mask bitmap width"
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBH
value|IR_ERROR+40
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBH_MSG
value|"invalid source mask bitmap height"
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBD
value|IR_ERROR+41
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBD_MSG
value|"invalid source mask bitmap depth"
end_define

begin_define
define|#
directive|define
name|ERR_IDSTM
value|IR_ERROR+44
end_define

begin_define
define|#
directive|define
name|ERR_IDSTM_MSG
value|"invalid destination offset modifiers"
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBW
value|IR_ERROR+45
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBW_MSG
value|"invalid destination bitmap width"
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBH
value|IR_ERROR+46
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBH_MSG
value|"invalid destination bitmap height"
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBD
value|IR_ERROR+47
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBD_MSG
value|"invalid destination bitmap depth"
end_define

begin_define
define|#
directive|define
name|ERR_IMAPM
value|IR_ERROR+50
end_define

begin_define
define|#
directive|define
name|ERR_IMAPM_MSG
value|"invalid mapping function modifiers"
end_define

begin_define
define|#
directive|define
name|ERR_ICLPM
value|IR_ERROR+54
end_define

begin_define
define|#
directive|define
name|ERR_ICLPM_MSG
value|"invalid clipping rectangle modifiers"
end_define

begin_define
define|#
directive|define
name|ERR_ICLPC
value|IR_ERROR+55
end_define

begin_define
define|#
directive|define
name|ERR_ICLPC_MSG
value|"invalid clipping rectangle count"
end_define

begin_define
define|#
directive|define
name|ERR_SMC_ITC
value|IR_ERROR+56
end_define

begin_define
define|#
directive|define
name|ERR_SMC_ITC_MSG
value|"set_mouse_characteristics:  invalid tracking constant"
end_define

begin_define
define|#
directive|define
name|ERR_SCL_CD
value|IR_ERROR+58
end_define

begin_define
define|#
directive|define
name|ERR_SCL_CD_MSG
value|"set_cursor_location:  cursor is detached"
end_define

begin_define
define|#
directive|define
name|ERR_AC_ICD
value|IR_ERROR+59
end_define

begin_define
define|#
directive|define
name|ERR_AC_ICD_MSG
value|"attach_cursor:  invalid cursor device"
end_define

begin_define
define|#
directive|define
name|ERR_MO_IBC
value|IR_ERROR+60
end_define

begin_define
define|#
directive|define
name|ERR_MO_IBC_MSG
value|"move_object:  invalid byte count"
end_define

begin_define
define|#
directive|define
name|ERR_MO_IOT
value|IR_ERROR+61
end_define

begin_define
define|#
directive|define
name|ERR_MO_IOT_MSG
value|"move_object:  invalid object type"
end_define

begin_define
define|#
directive|define
name|ERR_MO_IDT
value|IR_ERROR+62
end_define

begin_define
define|#
directive|define
name|ERR_MO_IDT_MSG
value|"move_object:  invalid device type"
end_define

begin_define
define|#
directive|define
name|ERR_IPC
value|IR_ERROR+63
end_define

begin_define
define|#
directive|define
name|ERR_IPC_MSG
value|"invalid path count (draw_curve or fill_polygon)"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPL
value|IR_ERROR+65
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPL_MSG
value|"invalid pattern length"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPM
value|IR_ERROR+66
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPM_MSG
value|"invalid pattern multiplier"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ICF
value|IR_ERROR+67
end_define

begin_define
define|#
directive|define
name|ERR_DC_ICF_MSG
value|"invalid closed figure"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPP
value|IR_ERROR+68
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPP_MSG
value|"invalid pattern position"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSM
value|IR_ERROR+69
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSM_MSG
value|"invalid pattern string modifiers"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPMM
value|IR_ERROR+70
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPMM_MSG
value|"invalid pattern mode modifiers"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPC
value|IR_ERROR+71
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPC_MSG
value|"invalid pattern count"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBW
value|IR_ERROR+72
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBW_MSG
value|"invalid second source bitmap width"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBH
value|IR_ERROR+73
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBH_MSG
value|"invalid second source bitmap height"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBD
value|IR_ERROR+74
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBD_MSG
value|"invalid second source bitmap depth"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCC
value|IR_ERROR+75
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCC_MSG
value|"invalid second source constant"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IDPM
value|IR_ERROR+76
end_define

begin_define
define|#
directive|define
name|ERR_DC_IDPM_MSG
value|"incompatible drawing/pattern modes"
end_define

begin_define
define|#
directive|define
name|ERR_DC_DXO
value|IR_ERROR+77
end_define

begin_define
define|#
directive|define
name|ERR_DC_DXO_MSG
value|"delta_x overflow"
end_define

begin_define
define|#
directive|define
name|ERR_DC_DYO
value|IR_ERROR+78
end_define

begin_define
define|#
directive|define
name|ERR_DC_DYO_MSG
value|"delta_y overflow"
end_define

begin_define
define|#
directive|define
name|ERR_DC_CRSO
value|IR_ERROR+79
end_define

begin_define
define|#
directive|define
name|ERR_DC_CRSO_MSG
value|"clipping rectangle stack overflow"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICSL
value|IR_ERROR+80
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICSL_MSG
value|"invalid control string length"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICSO
value|IR_ERROR+81
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICSO_MSG
value|"invalid control string opcode"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICSP
value|IR_ERROR+82
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICSP_MSG
value|"invalid control string parameter"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ITSL
value|IR_ERROR+83
end_define

begin_define
define|#
directive|define
name|ERR_PT_ITSL_MSG
value|"invalid text string length"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICI
value|IR_ERROR+84
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICI_MSG
value|"invalid character index"
end_define

begin_define
define|#
directive|define
name|ERR_PT_TSE
value|IR_ERROR+85
end_define

begin_define
define|#
directive|define
name|ERR_PT_TSE_MSG
value|"text string exhausted"
end_define

begin_define
define|#
directive|define
name|ERR_PT_NFP
value|IR_ERROR+86
end_define

begin_define
define|#
directive|define
name|ERR_PT_NFP_MSG
value|"no font present"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFW
value|IR_ERROR+87
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFW_MSG
value|"invalid source font width"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFH
value|IR_ERROR+88
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFH_MSG
value|"invalid source font height"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFD
value|IR_ERROR+89
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFD_MSG
value|"invalid source font depth"
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFW
value|IR_ERROR+90
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFW_MSG
value|"invalid source mask font width"
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFH
value|IR_ERROR+91
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFH_MSG
value|"invalid source mask font height"
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFD
value|IR_ERROR+92
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFD_MSG
value|"invalid source mask font depth"
end_define

begin_define
define|#
directive|define
name|ERR_PT_CSMF
value|IR_ERROR+93
end_define

begin_define
define|#
directive|define
name|ERR_PT_CSMF_MSG
value|"conflicting source/source mask fonts"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ILB
value|IR_ERROR+94
end_define

begin_define
define|#
directive|define
name|ERR_PT_ILB_MSG
value|"invalid left_array bounds"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ILE
value|IR_ERROR+95
end_define

begin_define
define|#
directive|define
name|ERR_PT_ILE_MSG
value|"invalid left_array element"
end_define

begin_define
define|#
directive|define
name|ERR_FA_ISRCB
value|IR_ERROR+96
end_define

begin_define
define|#
directive|define
name|ERR_FA_ISRCB_MSG
value|"invalid source bitmap"
end_define

begin_define
define|#
directive|define
name|ERR_FA_SO
value|IR_ERROR+99
end_define

begin_define
define|#
directive|define
name|ERR_FA_SO_MSG
value|"stack overflow"
end_define

begin_define
define|#
directive|define
name|ERR_FA_IBMM
value|IR_ERROR+100
end_define

begin_define
define|#
directive|define
name|ERR_FA_IBMM_MSG
value|"invalid boundary map modifiers"
end_define

begin_define
define|#
directive|define
name|ERR_FP_ISRCB
value|IR_ERROR+112
end_define

begin_define
define|#
directive|define
name|ERR_FP_ISRCB_MSG
value|"invalid source bitmap"
end_define

begin_define
define|#
directive|define
name|ERR_FP_ICF
value|IR_ERROR+115
end_define

begin_define
define|#
directive|define
name|ERR_FP_ICF_MSG
value|"invalid closed figure"
end_define

begin_define
define|#
directive|define
name|ERR_FP_DXO
value|IR_ERROR+116
end_define

begin_define
define|#
directive|define
name|ERR_FP_DXO_MSG
value|"delta_x overflow"
end_define

begin_define
define|#
directive|define
name|ERR_FP_DYO
value|IR_ERROR+117
end_define

begin_define
define|#
directive|define
name|ERR_FP_DYO_MSG
value|"delta_y overflow"
end_define

begin_define
define|#
directive|define
name|ERR_CPU
value|IR_ERROR+129
end_define

begin_define
define|#
directive|define
name|ERR_CPU_MSG
value|"CPU or supervisor stack error"
end_define

begin_define
define|#
directive|define
name|ERR_RHB
value|IR_ERROR+130
end_define

begin_define
define|#
directive|define
name|ERR_RHB_MSG
value|"ROM high byte checksum error"
end_define

begin_define
define|#
directive|define
name|ERR_PR
value|IR_ERROR+131
end_define

begin_define
define|#
directive|define
name|ERR_PR_MSG
value|"program RAM data error"
end_define

begin_define
define|#
directive|define
name|ERR_CRTC
value|IR_ERROR+132
end_define

begin_define
define|#
directive|define
name|ERR_CRTC_MSG
value|"CRT controller data error"
end_define

begin_define
define|#
directive|define
name|ERR_DPE
value|IR_ERROR+133
end_define

begin_define
define|#
directive|define
name|ERR_DPE_MSG
value|"data pad EPCI data error or time out"
end_define

begin_define
define|#
directive|define
name|ERR_KE
value|IR_ERROR+134
end_define

begin_define
define|#
directive|define
name|ERR_KE_MSG
value|"keyboard EPCI data error or time out"
end_define

begin_define
define|#
directive|define
name|ERR_FOE
value|IR_ERROR+135
end_define

begin_define
define|#
directive|define
name|ERR_FOE_MSG
value|"fiber optics electrical loop back"
end_define

begin_define
define|#
directive|define
name|ERR_F0
value|IR_ERROR+137
end_define

begin_define
define|#
directive|define
name|ERR_F0_MSG
value|"frame #0 data error"
end_define

begin_define
define|#
directive|define
name|ERR_BSR
value|IR_ERROR+138
end_define

begin_define
define|#
directive|define
name|ERR_BSR_MSG
value|"BBA scratchpad RAM data error"
end_define

begin_define
define|#
directive|define
name|ERR_BCC
value|IR_ERROR+139
end_define

begin_define
define|#
directive|define
name|ERR_BCC_MSG
value|"BBA copyarea command data error"
end_define

begin_define
define|#
directive|define
name|ERR_DPTO
value|IR_ERROR+140
end_define

begin_define
define|#
directive|define
name|ERR_DPTO_MSG
value|"data pad self test time out"
end_define

begin_define
define|#
directive|define
name|ERR_FOO
value|IR_ERROR+141
end_define

begin_define
define|#
directive|define
name|ERR_FOO_MSG
value|"fiber optics optical loop back"
end_define

begin_define
define|#
directive|define
name|ERR_KTO
value|IR_ERROR+142
end_define

begin_define
define|#
directive|define
name|ERR_KTO_MSG
value|"keyboard self test time out"
end_define

begin_define
define|#
directive|define
name|ERR_KST
value|IR_ERROR+143
end_define

begin_define
define|#
directive|define
name|ERR_KST_MSG
value|"keyboard self test error"
end_define

begin_define
define|#
directive|define
name|ERR_VR
value|IR_ERROR+144
end_define

begin_define
define|#
directive|define
name|ERR_VR_MSG
value|"vector RAM data error"
end_define

begin_define
define|#
directive|define
name|ERR_F1
value|IR_ERROR+145
end_define

begin_define
define|#
directive|define
name|ERR_F1_MSG
value|"frame #1 data error"
end_define

begin_define
define|#
directive|define
name|ERR_F2
value|IR_ERROR+146
end_define

begin_define
define|#
directive|define
name|ERR_F2_MSG
value|"frame #2 data error"
end_define

begin_define
define|#
directive|define
name|ERR_F3
value|IR_ERROR+147
end_define

begin_define
define|#
directive|define
name|ERR_F3_MSG
value|"frame #3 data error"
end_define

begin_define
define|#
directive|define
name|ERR_DPP
value|IR_ERROR+148
end_define

begin_define
define|#
directive|define
name|ERR_DPP_MSG
value|"data pad port loop back data error"
end_define

begin_define
define|#
directive|define
name|ERR_KP
value|IR_ERROR+149
end_define

begin_define
define|#
directive|define
name|ERR_KP_MSG
value|"keyboard port loop back data error"
end_define

begin_define
define|#
directive|define
name|ERR_FOED
value|IR_ERROR+150
end_define

begin_define
define|#
directive|define
name|ERR_FOED_MSG
value|"fiber optics electrical loop back"
end_define

begin_define
define|#
directive|define
name|ERR_FOOD
value|IR_ERROR+151
end_define

begin_define
define|#
directive|define
name|ERR_FOOD_MSG
value|"fiber optics optical loop back"
end_define

begin_define
define|#
directive|define
name|ERR_BCTO
value|IR_ERROR+152
end_define

begin_define
define|#
directive|define
name|ERR_BCTO_MSG
value|"BBA copyarea command time out"
end_define

begin_define
define|#
directive|define
name|ERR_RLB
value|IR_ERROR+153
end_define

begin_define
define|#
directive|define
name|ERR_RLB_MSG
value|"ROM low byte checksum error"
end_define

begin_define
define|#
directive|define
name|ERR_KD
value|IR_ERROR+154
end_define

begin_define
define|#
directive|define
name|ERR_KD_MSG
value|"key down on keyboard self test"
end_define

begin_define
define|#
directive|define
name|ERR_BVC
value|IR_ERROR+155
end_define

begin_define
define|#
directive|define
name|ERR_BVC_MSG
value|"BBA vector command data error"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCHW
value|IR_ERROR+161
end_define

begin_define
define|#
directive|define
name|ERR_ISRCHW_MSG
value|"invalid source halftone width"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCHH
value|IR_ERROR+162
end_define

begin_define
define|#
directive|define
name|ERR_ISRCHH_MSG
value|"invalid source halftone height"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCHD
value|IR_ERROR+163
end_define

begin_define
define|#
directive|define
name|ERR_ISRCHD_MSG
value|"invalid source halftone depth"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCHW
value|IR_ERROR+164
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCHW_MSG
value|"invalid second source halftone width"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCHH
value|IR_ERROR+165
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCHH_MSG
value|"invalid second source halftone height"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCHD
value|IR_ERROR+166
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCHD_MSG
value|"invalid second source halftone depth"
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICTX
value|IR_ERROR+167
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICTX_MSG
value|"load_cursor:  invalid cursor tip_x"
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICTY
value|IR_ERROR+168
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICTY_MSG
value|"load_cursor:  invalid cursor tip_y"
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICCX
value|IR_ERROR+169
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICCX_MSG
value|"load_cursor:  invalid cursor centre_x"
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICCY
value|IR_ERROR+170
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICCY_MSG
value|"load_cursor:  invalid cursor centre_y"
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICW
value|IR_ERROR+171
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICW_MSG
value|"load_cursor:  invalid cursor width"
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICH
value|IR_ERROR+172
end_define

begin_define
define|#
directive|define
name|ERR_LC_ICH_MSG
value|"load_cursor:  invalid cursor height"
end_define

begin_define
define|#
directive|define
name|ERR_PT_DXO
value|IR_ERROR+173
end_define

begin_define
define|#
directive|define
name|ERR_PT_DXO_MSG
value|"print_text:  destination offset x overflow"
end_define

begin_define
define|#
directive|define
name|ERR_PT_CRSO
value|IR_ERROR+174
end_define

begin_define
define|#
directive|define
name|ERR_PT_CRSO_MSG
value|"print_text:  clipping rectangle stack overflow"
end_define

begin_define
define|#
directive|define
name|NUM_ERR_CODES
value|134
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

