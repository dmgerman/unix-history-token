begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)tsleep.h	7.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TSLEEP_
end_ifndef

begin_define
define|#
directive|define
name|_TSLEEP_
end_define

begin_define
define|#
directive|define
name|SLP_WAIT
value|0
end_define

begin_define
define|#
directive|define
name|SLP_PAUSE
value|1
end_define

begin_define
define|#
directive|define
name|SLP_LOGREAD
value|2
end_define

begin_define
define|#
directive|define
name|SLP_SELECT
value|3
end_define

begin_define
define|#
directive|define
name|SLP_TTYOUT
value|4
end_define

begin_define
define|#
directive|define
name|SLP_TTY_NOTFG
value|5
end_define

begin_define
define|#
directive|define
name|SLP_TTY_CARR
value|6
end_define

begin_define
define|#
directive|define
name|SLP_TTYIN_NOTFG
value|7
end_define

begin_define
define|#
directive|define
name|SLP_TTY_READ
value|8
end_define

begin_define
define|#
directive|define
name|SLP_TTY_TSTP
value|9
end_define

begin_define
define|#
directive|define
name|SLP_TTYOUT_NOTFG
value|10
end_define

begin_define
define|#
directive|define
name|SLP_TTYOUT_CLIST
value|11
end_define

begin_define
define|#
directive|define
name|SLP_PTS_OPEN
value|12
end_define

begin_define
define|#
directive|define
name|SLP_PTC_WRITE
value|13
end_define

begin_define
define|#
directive|define
name|SLP_SO_LINGER
value|14
end_define

begin_define
define|#
directive|define
name|SLP_SO_SBWAIT
value|15
end_define

begin_define
define|#
directive|define
name|SLP_SO_ACCEPT
value|16
end_define

begin_define
define|#
directive|define
name|SLP_SO_ACCEPT2
value|17
end_define

begin_define
define|#
directive|define
name|SLP_EXLCK
value|18
end_define

begin_define
define|#
directive|define
name|SLP_SHLCK
value|19
end_define

begin_define
define|#
directive|define
name|SLP_ISO_CONSOUT
value|20
end_define

begin_define
define|#
directive|define
name|SLP_ISO_CONSCONN
value|21
end_define

begin_define
define|#
directive|define
name|SLP_NFS_IOD
value|22
end_define

begin_define
define|#
directive|define
name|SLP_SO_SBLOCK
value|23
end_define

begin_define
define|#
directive|define
name|SLP_TU_OPN
value|24
end_define

begin_define
define|#
directive|define
name|SLP_MFS
value|25
end_define

begin_define
define|#
directive|define
name|SLP_HP_OPEN
value|26
end_define

begin_define
define|#
directive|define
name|SLP_AD_GETW
value|27
end_define

begin_define
define|#
directive|define
name|SLP_PCAT_OUT
value|28
end_define

begin_define
define|#
directive|define
name|SLP_PCAT_CLIST
value|29
end_define

begin_define
define|#
directive|define
name|SLP_DH_OPN
value|30
end_define

begin_define
define|#
directive|define
name|SLP_DHU_OPN
value|31
end_define

begin_define
define|#
directive|define
name|SLP_DMFL_ASLP
value|32
end_define

begin_define
define|#
directive|define
name|SLP_DMFL_ERROR
value|33
end_define

begin_define
define|#
directive|define
name|SLP_DMX_OPN
value|34
end_define

begin_define
define|#
directive|define
name|SLP_DN_REG
value|35
end_define

begin_define
define|#
directive|define
name|SLP_DN_PAUSE
value|36
end_define

begin_define
define|#
directive|define
name|SLP_DZ_OPN
value|37
end_define

begin_define
define|#
directive|define
name|SLP_IK_BUSY
value|38
end_define

begin_define
define|#
directive|define
name|SLP_LP_OUT
value|39
end_define

begin_define
define|#
directive|define
name|SLP_LP_CLIST
value|40
end_define

begin_define
define|#
directive|define
name|SLP_NP_SLP
value|41
end_define

begin_define
define|#
directive|define
name|SLP_PS_REFRESH
value|42
end_define

begin_define
define|#
directive|define
name|SLP_PS_MAP
value|43
end_define

begin_define
define|#
directive|define
name|SLP_TM_OPN
value|44
end_define

begin_define
define|#
directive|define
name|SLP_UDA_OPN
value|45
end_define

begin_define
define|#
directive|define
name|SLP_UT_OPN
value|46
end_define

begin_define
define|#
directive|define
name|SLP_UU_OPN
value|47
end_define

begin_define
define|#
directive|define
name|SLP_VS_WAIT
value|48
end_define

begin_define
define|#
directive|define
name|SLP_VS_USRWAIT
value|49
end_define

begin_define
define|#
directive|define
name|SLP_VS_START
value|50
end_define

begin_define
define|#
directive|define
name|SLP_VS_ABORT
value|51
end_define

begin_define
define|#
directive|define
name|SLP_VS_PWRUP
value|52
end_define

begin_define
define|#
directive|define
name|SLP_VS_IOBCTL
value|53
end_define

begin_define
define|#
directive|define
name|SLP_VS_FIB
value|54
end_define

begin_define
define|#
directive|define
name|SLP_VS_FIBRET
value|55
end_define

begin_define
define|#
directive|define
name|SLP_VS_INITF
value|56
end_define

begin_define
define|#
directive|define
name|SLP_VS_INITDEV
value|57
end_define

begin_define
define|#
directive|define
name|SLP_DR_WAIT
value|58
end_define

begin_define
define|#
directive|define
name|SLP_DR_RESET
value|59
end_define

begin_define
define|#
directive|define
name|SLP_DR_ACTV
value|60
end_define

begin_define
define|#
directive|define
name|SLP_HD_OPN
value|61
end_define

begin_define
define|#
directive|define
name|SLP_MP_1OPN
value|62
end_define

begin_define
define|#
directive|define
name|SLP_MP_POPN
value|63
end_define

begin_define
define|#
directive|define
name|SLP_MP_OPN
value|64
end_define

begin_define
define|#
directive|define
name|SLP_MP_1CLS
value|65
end_define

begin_define
define|#
directive|define
name|SLP_MP_CLS
value|66
end_define

begin_define
define|#
directive|define
name|SLP_MP_BRK
value|67
end_define

begin_define
define|#
directive|define
name|SLP_MP_STDL
value|68
end_define

begin_define
define|#
directive|define
name|SLP_MP_DLWAIT
value|69
end_define

begin_define
define|#
directive|define
name|SLP_VD_OPN
value|70
end_define

begin_define
define|#
directive|define
name|SLP_VX_OPN
value|71
end_define

begin_define
define|#
directive|define
name|SLP_VX_CLS
value|72
end_define

begin_define
define|#
directive|define
name|SLP_VX_PARAM
value|73
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SLP_MSGLIST
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|slp_mesg
index|[]
init|=
block|{
literal|"wait"
block|,
literal|"pause"
block|,
literal|"log_read"
block|,
literal|"select"
block|,
literal|"ttyout"
block|,
literal|"tty_notfg"
block|,
literal|"tty_carrier"
block|,
literal|"ttyin_notfg"
block|,
literal|"ttread"
block|,
literal|"tty_tstp"
block|,
literal|"ttyout_notfg"
block|,
literal|"tty_clists"
block|,
literal|"tty_ptsopen"
block|,
literal|"tty_ptcwrite"
block|,
comment|/* 13 */
literal|"so_linger"
block|,
literal|"so_sbwait"
block|,
literal|"so_accept"
block|,
literal|"so_accept2"
block|,
literal|"exlock"
block|,
literal|"shlock"
block|,
literal|"iso_cons"
block|,
literal|"iso_consconn"
block|,
literal|"nfs_iod"
block|,
literal|"so_sblock"
block|,
literal|"tu58_opn"
block|,
literal|"mfs_idle"
block|,
literal|"hp_open"
block|,
literal|"ad_getw"
block|,
literal|"pcat_out"
block|,
literal|"pcat_clist"
block|,
literal|"dh_opn"
block|,
literal|"dhu_opn"
block|,
literal|"dmfl_aslp"
block|,
literal|"dmfl_err"
block|,
literal|"dmx_opn"
block|,
literal|"dn_reg"
block|,
literal|"dn_pause"
block|,
literal|"dz_opn"
block|,
literal|"ik_busy"
block|,
literal|"lp_out"
block|,
literal|"lp_clist"
block|,
literal|"np_slp"
block|,
literal|"ps_refresh"
block|,
literal|"ps_map"
block|,
literal|"tm_opn"
block|,
literal|"uda_opn"
block|,
literal|"ut_opn"
block|,
literal|"uu_opn"
block|,
literal|"vs_wait"
block|,
literal|"vs_usrwait"
block|,
literal|"vs_start"
block|,
literal|"vs_abort"
block|,
literal|"vs_pwrup"
block|,
literal|"vs_iobctl"
block|,
literal|"vs_fib"
block|,
literal|"vs_fibret"
block|,
literal|"vs_initf"
block|,
literal|"vs_initdev"
block|,
literal|"dr_wait"
block|,
literal|"dr_reset"
block|,
literal|"dr_actv"
block|,
literal|"hd_opn"
block|,
literal|"mp_1opn"
block|,
literal|"mp_popn"
block|,
literal|"mp_opn"
block|,
literal|"mp_1cls"
block|,
literal|"mp_cls"
block|,
literal|"mp_brk"
block|,
literal|"mp_stdl"
block|,
literal|"mp_dlwait"
block|,
literal|"vd_opn"
block|,
literal|"vx_opn"
block|,
literal|"vx_cls"
block|,
literal|"vx_param"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

