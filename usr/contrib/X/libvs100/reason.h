begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: reason.h,v 10.3 86/02/01 15:47:29 tony Rel $ */
end_comment

begin_comment
comment|/* reason.h	Interrupt reason values  *  * Author:	Paul J. Asente  * 		Digital Equipment Corporation  * 		Western Reseach Lab  * Date:	June 1983  */
end_comment

begin_comment
comment|/****************************************************************************  *									    *  *  Copyright (c) 1983, 1984 by						    *  *  DIGITAL EQUIPMENT CORPORATION, Maynard, Massachusetts.		    *  *  All rights reserved.						    *  * 									    *  *  This software is furnished on an as-is basis and may be used and copied *  *  only with inclusion of the above copyright notice. This software or any *  *  other copies thereof may be provided or otherwise made available to     *  *  others only for non-commercial purposes.  No title to or ownership of   *  *  the software is hereby transferred.					    *  * 									    *  *  The information in this software is  subject to change without notice   *  *  and  should  not  be  construed as  a commitment by DIGITAL EQUIPMENT   *  *  CORPORATION.							    *  * 									    *  *  DIGITAL assumes no responsibility for the use  or  reliability of its   *  *  software on equipment which is not supplied by DIGITAL.		    *  * 									    *  *									    *  ****************************************************************************/
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
name|INT_ID
value|0x0001
end_define

begin_define
define|#
directive|define
name|INT_ID_MSG
value|"initialization done"
end_define

begin_define
define|#
directive|define
name|INT_CD
value|0x0002
end_define

begin_define
define|#
directive|define
name|INT_CD_MSG
value|"command done"
end_define

begin_define
define|#
directive|define
name|INT_SE
value|0x0004
end_define

begin_define
define|#
directive|define
name|INT_SE_MSG
value|"started executing"
end_define

begin_define
define|#
directive|define
name|INT_BE
value|0x0008
end_define

begin_define
define|#
directive|define
name|INT_BE_MSG
value|"button event"
end_define

begin_define
define|#
directive|define
name|INT_CM
value|0x0010
end_define

begin_define
define|#
directive|define
name|INT_CM_MSG
value|"cursor moved"
end_define

begin_define
define|#
directive|define
name|INT_TM
value|0x0020
end_define

begin_define
define|#
directive|define
name|INT_TM_MSG
value|"tablet moved"
end_define

begin_define
define|#
directive|define
name|INT_MM
value|0x0040
end_define

begin_define
define|#
directive|define
name|INT_MM_MSG
value|"mouse moved"
end_define

begin_define
define|#
directive|define
name|INT_PD
value|0x0080
end_define

begin_define
define|#
directive|define
name|INT_PD_MSG
value|"powerup done"
end_define

begin_define
define|#
directive|define
name|INT_ERR
value|-128
end_define

begin_define
define|#
directive|define
name|INT_ERR_MSG
value|"error encountered"
end_define

begin_define
define|#
directive|define
name|ERR_NYI
value|INT_ERR+0
end_define

begin_define
define|#
directive|define
name|ERR_NYI_MSG
value|"not yet implemented"
end_define

begin_define
define|#
directive|define
name|ERR_IFC
value|INT_ERR+1
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
value|INT_ERR+2
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
name|ERR_RN
value|INT_ERR+3
end_define

begin_define
define|#
directive|define
name|ERR_RN_MSG
value|"bus error: non-existant memory"
end_define

begin_define
define|#
directive|define
name|ERR_RO
value|INT_ERR+4
end_define

begin_define
define|#
directive|define
name|ERR_RO_MSG
value|"bus error: retry overflow"
end_define

begin_define
define|#
directive|define
name|ERR_LD
value|INT_ERR+5
end_define

begin_define
define|#
directive|define
name|ERR_LD_MSG
value|"bus error: link down"
end_define

begin_define
define|#
directive|define
name|ERR_BE
value|INT_ERR+6
end_define

begin_define
define|#
directive|define
name|ERR_BE_MSG
value|"bus error: unexplained"
end_define

begin_define
define|#
directive|define
name|ERR_AE
value|INT_ERR+7
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
name|ERR_SI
value|INT_ERR+8
end_define

begin_define
define|#
directive|define
name|ERR_SI_MSG
value|"spurious interrupt"
end_define

begin_define
define|#
directive|define
name|ERR_II
value|INT_ERR+9
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
name|ERR_BN
value|INT_ERR+10
end_define

begin_define
define|#
directive|define
name|ERR_BN_MSG
value|"bba: non-existant memory"
end_define

begin_define
define|#
directive|define
name|ERR_BNI
value|INT_ERR+11
end_define

begin_define
define|#
directive|define
name|ERR_BNI_MSG
value|"bba not installed"
end_define

begin_define
define|#
directive|define
name|ERR_KBO
value|INT_ERR+12
end_define

begin_define
define|#
directive|define
name|ERR_KBO_MSG
value|"keyboard buffer overflow"
end_define

begin_define
define|#
directive|define
name|ERR_TBO
value|INT_ERR+13
end_define

begin_define
define|#
directive|define
name|ERR_TBO_MSG
value|"tablet buffer overflow"
end_define

begin_define
define|#
directive|define
name|ERR_BBO
value|INT_ERR+14
end_define

begin_define
define|#
directive|define
name|ERR_BBO_MSG
value|"button buffer overflow"
end_define

begin_define
define|#
directive|define
name|ERR_ITP
value|INT_ERR+15
end_define

begin_define
define|#
directive|define
name|ERR_ITP_MSG
value|"invalid tablet packet"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCMB
value|INT_ERR+32
end_define

begin_define
define|#
directive|define
name|ERR_ISRCMB_MSG
value|"invalid src modifier bits"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBW
value|INT_ERR+33
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBW_MSG
value|"invalid src bitmap width"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBH
value|INT_ERR+34
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBH_MSG
value|"invalid src bitmap height"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCC
value|INT_ERR+35
end_define

begin_define
define|#
directive|define
name|ERR_ISRCC_MSG
value|"invalid src constant"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBD
value|INT_ERR+36
end_define

begin_define
define|#
directive|define
name|ERR_ISRCBD_MSG
value|"invalid src bitmap depth"
end_define

begin_define
define|#
directive|define
name|ERR_ISRCD
value|INT_ERR+37
end_define

begin_define
define|#
directive|define
name|ERR_ISRCD_MSG
value|"invalid src bitmap dimension"
end_define

begin_define
define|#
directive|define
name|ERR_IMSKMB
value|INT_ERR+38
end_define

begin_define
define|#
directive|define
name|ERR_IMSKMB_MSG
value|"invalid msk modifier bits"
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBW
value|INT_ERR+39
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBW_MSG
value|"invalid msk bitmap width"
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBH
value|INT_ERR+40
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBH_MSG
value|"invalid msk bitmap height"
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBD
value|INT_ERR+41
end_define

begin_define
define|#
directive|define
name|ERR_IMSKBD_MSG
value|"invalid msk bitmap depth"
end_define

begin_define
define|#
directive|define
name|ERR_IDSTMB
value|INT_ERR+44
end_define

begin_define
define|#
directive|define
name|ERR_IDSTMB_MSG
value|"invalid dst-offset modifier"
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBW
value|INT_ERR+45
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBW_MSG
value|"invalid dst bitmap width"
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBH
value|INT_ERR+46
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBH_MSG
value|"invalid dst bitmap height"
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBD
value|INT_ERR+47
end_define

begin_define
define|#
directive|define
name|ERR_IDSTBD_MSG
value|"invalid dst bitmap depth"
end_define

begin_define
define|#
directive|define
name|ERR_NOAREA
value|INT_ERR+48
end_define

begin_define
define|#
directive|define
name|ERR_NOAREA_MSG
value|"no resultant area"
end_define

begin_define
define|#
directive|define
name|ERR_IMAPMB
value|INT_ERR+50
end_define

begin_define
define|#
directive|define
name|ERR_IMAPMB_MSG
value|"invalid map modifier bits"
end_define

begin_define
define|#
directive|define
name|ERR_IMAPFC
value|INT_ERR+51
end_define

begin_define
define|#
directive|define
name|ERR_IMAPFC_MSG
value|"invalid map function code"
end_define

begin_define
define|#
directive|define
name|ERR_ZIMAP
value|INT_ERR+52
end_define

begin_define
define|#
directive|define
name|ERR_ZIMAP_MSG
value|"depth incompatible with map"
end_define

begin_define
define|#
directive|define
name|ERR_ZCIMAP
value|INT_ERR+53
end_define

begin_define
define|#
directive|define
name|ERR_ZCIMAP_MSG
value|"depth combination incompatible with map"
end_define

begin_define
define|#
directive|define
name|ERR_ICLPMB
value|INT_ERR+54
end_define

begin_define
define|#
directive|define
name|ERR_ICLPMB_MSG
value|"invalid clipr modifier bits"
end_define

begin_define
define|#
directive|define
name|ERR_ICLPRC
value|INT_ERR+55
end_define

begin_define
define|#
directive|define
name|ERR_ICLPRC_MSG
value|"invalid clipr count"
end_define

begin_define
define|#
directive|define
name|ERR_SMC_ITC
value|INT_ERR+56
end_define

begin_define
define|#
directive|define
name|ERR_SMC_ITC_MSG
value|"invalid tracking ratio"
end_define

begin_define
define|#
directive|define
name|ERR_ITC_MULT
value|INT_ERR+57
end_define

begin_define
define|#
directive|define
name|ERR_ITC_MULT_MSG
value|"invalid tracking multiplier"
end_define

begin_define
define|#
directive|define
name|ERR_ITC_DIV
value|INT_ERR+58
end_define

begin_define
define|#
directive|define
name|ERR_ITC_DIV_MSG
value|"invalid tracking divisor"
end_define

begin_define
define|#
directive|define
name|ERR_ICD
value|INT_ERR+59
end_define

begin_define
define|#
directive|define
name|ERR_ICD_MSG
value|"invalid cursor device"
end_define

begin_define
define|#
directive|define
name|ERR_MO_IBC
value|INT_ERR+60
end_define

begin_define
define|#
directive|define
name|ERR_MO_IBC_MSG
value|"invalid byte count"
end_define

begin_define
define|#
directive|define
name|ERR_MO_IOT
value|INT_ERR+61
end_define

begin_define
define|#
directive|define
name|ERR_MO_IOT_MSG
value|"invalid object type"
end_define

begin_define
define|#
directive|define
name|ERR_MO_IDT
value|INT_ERR+62
end_define

begin_define
define|#
directive|define
name|ERR_MO_IDT_MSG
value|"invalid device type"
end_define

begin_define
define|#
directive|define
name|ERR_IPC
value|INT_ERR+63
end_define

begin_define
define|#
directive|define
name|ERR_IPC_MSG
value|"invalid path count"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPC
value|INT_ERR+64
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPC_MSG
value|"invalid path count"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSL
value|INT_ERR+65
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSL_MSG
value|"invalid pattern string length"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSM
value|INT_ERR+66
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSM_MSG
value|"invalid pattern string multiplier"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ICF
value|INT_ERR+67
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
name|ERR_DC_IPSP
value|INT_ERR+68
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSP_MSG
value|"invalid pattern position"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSMB
value|INT_ERR+69
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSMB_MSG
value|"invalid pattern string modifier bits"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPMMB
value|INT_ERR+70
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPMMB_MSG
value|"invalid pattern mode modifier bits"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSC
value|INT_ERR+71
end_define

begin_define
define|#
directive|define
name|ERR_DC_IPSC_MSG
value|"invalid pattern count"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBW
value|INT_ERR+72
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBW_MSG
value|"invalid second src bitmap width"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBH
value|INT_ERR+73
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBH_MSG
value|"invalid second src bitmap height"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBD
value|INT_ERR+74
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCBD_MSG
value|"invalid second src bitmap depth"
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCC
value|INT_ERR+75
end_define

begin_define
define|#
directive|define
name|ERR_DC_ISSRCC_MSG
value|"invalid second src constant"
end_define

begin_define
define|#
directive|define
name|ERR_DC_IDPM
value|INT_ERR+76
end_define

begin_define
define|#
directive|define
name|ERR_DC_IDPM_MSG
value|"incompatible drawing/pattern mode"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ICSL
value|INT_ERR+80
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
value|INT_ERR+81
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
value|INT_ERR+82
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
value|INT_ERR+83
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
value|INT_ERR+84
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
value|INT_ERR+85
end_define

begin_define
define|#
directive|define
name|ERR_PT_TSE_MSG
value|"test string exhausted"
end_define

begin_define
define|#
directive|define
name|ERR_PT_NFP
value|INT_ERR+86
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
value|INT_ERR+87
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFW_MSG
value|"invalid src font width"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFH
value|INT_ERR+88
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFH_MSG
value|"invalid src font height"
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFD
value|INT_ERR+89
end_define

begin_define
define|#
directive|define
name|ERR_PT_ISRCFD_MSG
value|"invalid src font depth"
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFW
value|INT_ERR+90
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFW_MSG
value|"invalid msk font width"
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFH
value|INT_ERR+91
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFH_MSG
value|"invalid msk font height"
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFD
value|INT_ERR+92
end_define

begin_define
define|#
directive|define
name|ERR_PT_IMSKFD_MSG
value|"invalid msk font depth"
end_define

begin_define
define|#
directive|define
name|ERR_PT_CSMF
value|INT_ERR+93
end_define

begin_define
define|#
directive|define
name|ERR_PT_CSMF_MSG
value|"conflicting src/msk fonts"
end_define

begin_define
define|#
directive|define
name|ERR_FA_ISRCB
value|INT_ERR+96
end_define

begin_define
define|#
directive|define
name|ERR_FA_ISRCB_MSG
value|"invalid src bitmap"
end_define

begin_define
define|#
directive|define
name|ERR_FA_SPIOB
value|INT_ERR+98
end_define

begin_define
define|#
directive|define
name|ERR_FA_SPIOB_MSG
value|"seed point is on boundary"
end_define

begin_define
define|#
directive|define
name|ERR_FA_SO
value|INT_ERR+99
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
name|ERR_FA_IBMMB
value|INT_ERR+100
end_define

begin_define
define|#
directive|define
name|ERR_FA_IBMMB_MSG
value|"invalid boundary map modifier bits"
end_define

begin_define
define|#
directive|define
name|ERR_FP_ISRCB
value|INT_ERR+112
end_define

begin_define
define|#
directive|define
name|ERR_FP_ISRCB_MSG
value|"invalid src bitmap"
end_define

begin_define
define|#
directive|define
name|ERR_FP_SO
value|INT_ERR+113
end_define

begin_define
define|#
directive|define
name|ERR_FP_SO_MSG
value|"stack overflow"
end_define

begin_define
define|#
directive|define
name|ERR_FP_IPC
value|INT_ERR+114
end_define

begin_define
define|#
directive|define
name|ERR_FP_IPC_MSG
value|"invalid point count"
end_define

begin_define
define|#
directive|define
name|ERR_FP_ICF
value|INT_ERR+115
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
name|ERR_68K
value|INT_ERR+129
end_define

begin_define
define|#
directive|define
name|ERR_68K_MSG
value|"68000 cpu"
end_define

begin_define
define|#
directive|define
name|ERR_RC
value|INT_ERR+130
end_define

begin_define
define|#
directive|define
name|ERR_RC_MSG
value|"rom checksum"
end_define

begin_define
define|#
directive|define
name|ERR_PR
value|INT_ERR+131
end_define

begin_define
define|#
directive|define
name|ERR_PR_MSG
value|"program ram"
end_define

begin_define
define|#
directive|define
name|ERR_CRT
value|INT_ERR+132
end_define

begin_define
define|#
directive|define
name|ERR_CRT_MSG
value|"crtc register"
end_define

begin_define
define|#
directive|define
name|ERR_TU
value|INT_ERR+133
end_define

begin_define
define|#
directive|define
name|ERR_TU_MSG
value|"tablet usart"
end_define

begin_define
define|#
directive|define
name|ERR_KU
value|INT_ERR+134
end_define

begin_define
define|#
directive|define
name|ERR_KU_MSG
value|"keyboard usart"
end_define

begin_define
define|#
directive|define
name|ERR_FOE
value|INT_ERR+135
end_define

begin_define
define|#
directive|define
name|ERR_FOE_MSG
value|"fotr electrical loop back"
end_define

begin_define
define|#
directive|define
name|ERR_VTO
value|INT_ERR+136
end_define

begin_define
define|#
directive|define
name|ERR_VTO_MSG
value|"vsync time out"
end_define

begin_define
define|#
directive|define
name|ERR_SB
value|INT_ERR+137
end_define

begin_define
define|#
directive|define
name|ERR_SB_MSG
value|"screen buffer"
end_define

begin_define
define|#
directive|define
name|ERR_BS
value|INT_ERR+138
end_define

begin_define
define|#
directive|define
name|ERR_BS_MSG
value|"bba scratchpad ram"
end_define

begin_define
define|#
directive|define
name|ERR_BC
value|INT_ERR+139
end_define

begin_define
define|#
directive|define
name|ERR_BC_MSG
value|"bba copyarea command"
end_define

begin_define
define|#
directive|define
name|ERR_TTO
value|INT_ERR+140
end_define

begin_define
define|#
directive|define
name|ERR_TTO_MSG
value|"tablet time out"
end_define

begin_define
define|#
directive|define
name|ERR_FOO
value|INT_ERR+141
end_define

begin_define
define|#
directive|define
name|ERR_FOO_MSG
value|"fotr optical loop back"
end_define

begin_define
define|#
directive|define
name|ERR_KTO
value|INT_ERR+142
end_define

begin_define
define|#
directive|define
name|ERR_KTO_MSG
value|"keyboard time out"
end_define

begin_define
define|#
directive|define
name|ERR_KST
value|INT_ERR+143
end_define

begin_define
define|#
directive|define
name|ERR_KST_MSG
value|"keyboard self-test"
end_define

begin_define
define|#
directive|define
name|ERR_LDC_IATRV
value|INT_ERR+160
end_define

begin_define
define|#
directive|define
name|ERR_LDC_IATRV_MSG
value|"invalid cursor attribute value"
end_define

begin_define
define|#
directive|define
name|ERR_LDC_ICH
value|INT_ERR+161
end_define

begin_define
define|#
directive|define
name|ERR_LDC_ICH_MSG
value|"invalid cursor height"
end_define

begin_define
define|#
directive|define
name|ERR_LDC_ICW
value|INT_ERR+162
end_define

begin_define
define|#
directive|define
name|ERR_LDC_ICW_MSG
value|"invalid cursor width"
end_define

begin_define
define|#
directive|define
name|ERR_NOVALCUR
value|INT_ERR+163
end_define

begin_define
define|#
directive|define
name|ERR_NOVALCUR_MSG
value|"no valid cursor defined"
end_define

begin_define
define|#
directive|define
name|NUM_ERR_CODES
value|108
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

