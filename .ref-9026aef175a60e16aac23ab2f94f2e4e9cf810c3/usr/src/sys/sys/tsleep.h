begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tsleep.h	7.4 (Berkeley) %G%  */
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
name|tsleep
value|ttsleep
end_define

begin_comment
comment|/* tmp tsleep, does longjmp */
end_comment

begin_define
define|#
directive|define
name|SLP_WAIT
value|"child"
end_define

begin_comment
comment|/* "wait" */
end_comment

begin_define
define|#
directive|define
name|SLP_LOGREAD
value|"syslog"
end_define

begin_comment
comment|/* "log_read" */
end_comment

begin_define
define|#
directive|define
name|SLP_SELECT
value|"select"
end_define

begin_comment
comment|/* "select" */
end_comment

begin_define
define|#
directive|define
name|SLP_TTYOUT
value|"ttyout"
end_define

begin_comment
comment|/* "ttyout" */
end_comment

begin_define
define|#
directive|define
name|SLP_TTY_NOTFG
value|"tty"
end_define

begin_comment
comment|/* "tty_notfg" */
end_comment

begin_define
define|#
directive|define
name|SLP_TTY_CARR
value|"ttyopn"
end_define

begin_comment
comment|/* "tty_carrier" */
end_comment

begin_define
define|#
directive|define
name|SLP_TTYIN_NOTFG
value|"ttyin"
end_define

begin_comment
comment|/* "ttyin_notfg" */
end_comment

begin_define
define|#
directive|define
name|SLP_TTY_READ
value|"ttyin"
end_define

begin_comment
comment|/* "ttread" */
end_comment

begin_define
define|#
directive|define
name|SLP_TTY_TSTP
value|"ttyin"
end_define

begin_comment
comment|/* "tty_tstp" */
end_comment

begin_define
define|#
directive|define
name|SLP_TTYOUT_NOTFG
value|"ttyout"
end_define

begin_comment
comment|/* "ttyout_notfg" */
end_comment

begin_define
define|#
directive|define
name|SLP_TTYOUT_CLIST
value|"ttybuf"
end_define

begin_comment
comment|/* "tty_clists" */
end_comment

begin_define
define|#
directive|define
name|SLP_PTS_OPEN
value|"ttyopn"
end_define

begin_comment
comment|/* "tty_ptsopen" */
end_comment

begin_define
define|#
directive|define
name|SLP_PTC_WRITE
value|"ttyout"
end_define

begin_comment
comment|/* "tty_ptcwrite" */
end_comment

begin_define
define|#
directive|define
name|SLP_SO_LINGER
value|"netcls"
end_define

begin_comment
comment|/* "so_linger" */
end_comment

begin_define
define|#
directive|define
name|SLP_SO_SBWAIT
value|"netio"
end_define

begin_comment
comment|/* "so_sbwait" */
end_comment

begin_define
define|#
directive|define
name|SLP_SO_ACCEPT
value|"netcon"
end_define

begin_comment
comment|/* "so_accept" */
end_comment

begin_define
define|#
directive|define
name|SLP_SO_ACCEPT2
value|"netcon"
end_define

begin_comment
comment|/* "so_accept2" */
end_comment

begin_define
define|#
directive|define
name|SLP_EXLCK
value|"flock"
end_define

begin_comment
comment|/* "exlock" */
end_comment

begin_define
define|#
directive|define
name|SLP_SHLCK
value|"flock"
end_define

begin_comment
comment|/* "shlock" */
end_comment

begin_define
define|#
directive|define
name|SLP_ISO_CONSOUT
value|"netcon"
end_define

begin_comment
comment|/* "iso_cons" */
end_comment

begin_define
define|#
directive|define
name|SLP_ISO_CONSCONN
value|"netcon"
end_define

begin_comment
comment|/* "iso_consconn" */
end_comment

begin_define
define|#
directive|define
name|SLP_NFS_IOD
value|"nfsio"
end_define

begin_comment
comment|/* "nfs_iod" */
end_comment

begin_define
define|#
directive|define
name|SLP_SO_SBLOCK
value|"netio"
end_define

begin_comment
comment|/* "so_sblock" */
end_comment

begin_define
define|#
directive|define
name|SLP_TU_OPN
value|"devopn"
end_define

begin_comment
comment|/* "tu58_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_MFS
value|"mfsio"
end_define

begin_comment
comment|/* "mfs_idle" */
end_comment

begin_define
define|#
directive|define
name|SLP_FIFO_OPEN
value|"devopn"
end_define

begin_comment
comment|/* "fifo_open" */
end_comment

begin_define
define|#
directive|define
name|SLP_HP_OPEN
value|"devopn"
end_define

begin_comment
comment|/* "hp_open" */
end_comment

begin_define
define|#
directive|define
name|SLP_AD_GETW
value|"devi"
end_define

begin_comment
comment|/* "ad_getw" */
end_comment

begin_define
define|#
directive|define
name|SLP_PCAT_OUT
value|"devout"
end_define

begin_comment
comment|/* "pcat_out" */
end_comment

begin_define
define|#
directive|define
name|SLP_PCAT_CLIST
value|"ttybuf"
end_define

begin_comment
comment|/* "pcat_clist" */
end_comment

begin_define
define|#
directive|define
name|SLP_DH_OPN
value|"ttyopn"
end_define

begin_comment
comment|/* "dh_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_DHU_OPN
value|"ttyopn"
end_define

begin_comment
comment|/* "dhu_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_DMFL_ASLP
value|"ttyout"
end_define

begin_comment
comment|/* "dmfl_aslp" */
end_comment

begin_define
define|#
directive|define
name|SLP_DMFL_ERROR
value|"ttyout"
end_define

begin_comment
comment|/* "dmfl_err" */
end_comment

begin_define
define|#
directive|define
name|SLP_DMX_OPN
value|"devopn"
end_define

begin_comment
comment|/* "dmx_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_DN_REG
value|"ttyout"
end_define

begin_comment
comment|/* "dn_reg" */
end_comment

begin_define
define|#
directive|define
name|SLP_DN_PAUSE
value|"ttyout"
end_define

begin_comment
comment|/* "dn_pause" */
end_comment

begin_define
define|#
directive|define
name|SLP_DZ_OPN
value|"ttyopn"
end_define

begin_comment
comment|/* "dz_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_IK_BUSY
value|"devout"
end_define

begin_comment
comment|/* "ik_busy" */
end_comment

begin_define
define|#
directive|define
name|SLP_LP_OUT
value|"devout"
end_define

begin_comment
comment|/* "lp_out" */
end_comment

begin_define
define|#
directive|define
name|SLP_LP_CLIST
value|"ttybuf"
end_define

begin_comment
comment|/* "lp_clist" */
end_comment

begin_define
define|#
directive|define
name|SLP_NP_SLP
value|"devin"
end_define

begin_comment
comment|/* "np_slp" */
end_comment

begin_define
define|#
directive|define
name|SLP_PS_REFRESH
value|"devout"
end_define

begin_comment
comment|/* "ps_refresh" */
end_comment

begin_define
define|#
directive|define
name|SLP_PS_MAP
value|"devout"
end_define

begin_comment
comment|/* "ps_map" */
end_comment

begin_define
define|#
directive|define
name|SLP_TM_OPN
value|"devopn"
end_define

begin_comment
comment|/* "tm_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_UDA_OPN
value|"devopn"
end_define

begin_comment
comment|/* "uda_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_UT_OPN
value|"devopn"
end_define

begin_comment
comment|/* "ut_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_UU_OPN
value|"devopn"
end_define

begin_comment
comment|/* "uu_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_WAIT
value|"devout"
end_define

begin_comment
comment|/* "vs_wait" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_USRWAIT
value|"devout"
end_define

begin_comment
comment|/* "vs_usrwait" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_START
value|"devout"
end_define

begin_comment
comment|/* "vs_start" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_ABORT
value|"devout"
end_define

begin_comment
comment|/* "vs_abort" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_PWRUP
value|"devout"
end_define

begin_comment
comment|/* "vs_pwrup" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_IOBCTL
value|"devout"
end_define

begin_comment
comment|/* "vs_iobctl" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_FIB
value|"devout"
end_define

begin_comment
comment|/* "vs_fib" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_FIBRET
value|"devout"
end_define

begin_comment
comment|/* "vs_fibret" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_INITF
value|"devout"
end_define

begin_comment
comment|/* "vs_initf" */
end_comment

begin_define
define|#
directive|define
name|SLP_VS_INITDEV
value|"devout"
end_define

begin_comment
comment|/* "vs_initdev" */
end_comment

begin_define
define|#
directive|define
name|SLP_DR_WAIT
value|"devout"
end_define

begin_comment
comment|/* "dr_wait" */
end_comment

begin_define
define|#
directive|define
name|SLP_DR_RESET
value|"devout"
end_define

begin_comment
comment|/* "dr_reset" */
end_comment

begin_define
define|#
directive|define
name|SLP_DR_ACTV
value|"devout"
end_define

begin_comment
comment|/* "dr_actv" */
end_comment

begin_define
define|#
directive|define
name|SLP_HD_OPN
value|"devopn"
end_define

begin_comment
comment|/* "hd_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_MP_1OPN
value|"ttyopn"
end_define

begin_comment
comment|/* "mp_1opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_MP_POPN
value|"ttyopn"
end_define

begin_comment
comment|/* "mp_popn" */
end_comment

begin_define
define|#
directive|define
name|SLP_MP_OPN
value|"ttyopn"
end_define

begin_comment
comment|/* "mp_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_MP_1CLS
value|"ttycls"
end_define

begin_comment
comment|/* "mp_1cls" */
end_comment

begin_define
define|#
directive|define
name|SLP_MP_CLS
value|"ttycls"
end_define

begin_comment
comment|/* "mp_cls" */
end_comment

begin_define
define|#
directive|define
name|SLP_MP_BRK
value|"ttyout"
end_define

begin_comment
comment|/* "mp_brk" */
end_comment

begin_define
define|#
directive|define
name|SLP_MP_STDL
value|"ttyout"
end_define

begin_comment
comment|/* "mp_stdl" */
end_comment

begin_define
define|#
directive|define
name|SLP_MP_DLWAIT
value|"ttyout"
end_define

begin_comment
comment|/* "mp_dlwait" */
end_comment

begin_define
define|#
directive|define
name|SLP_VD_OPN
value|"devopn"
end_define

begin_comment
comment|/* "vd_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_VX_OPN
value|"ttyopn"
end_define

begin_comment
comment|/* "vx_opn" */
end_comment

begin_define
define|#
directive|define
name|SLP_VX_CLS
value|"ttycls"
end_define

begin_comment
comment|/* "vx_cls" */
end_comment

begin_define
define|#
directive|define
name|SLP_VX_PARAM
value|"ttyout"
end_define

begin_comment
comment|/* "vx_param" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

