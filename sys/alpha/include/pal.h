begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: pal.h,v 1.1 1997/09/06 01:23:53 thorpej Exp */
end_comment

begin_comment
comment|/*   * Copyright (c) 1991,1990,1989,1994,1995,1996 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * PAL "function" codes (used as arguments to call_pal instructions).  *  * Those marked with "P" are privileged, and those marked with "U"  * are unprivileged.  */
end_comment

begin_comment
comment|/* Common PAL function codes. */
end_comment

begin_define
define|#
directive|define
name|PAL_halt
value|0x0000
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_cflush
value|0x0001
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_draina
value|0x0002
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_cserve
value|0x0009
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_swppal
value|0x000a
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_ipir
value|0x000d
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_bpt
value|0x0080
end_define

begin_comment
comment|/* U */
end_comment

begin_define
define|#
directive|define
name|PAL_bugchk
value|0x0081
end_define

begin_comment
comment|/* U */
end_comment

begin_define
define|#
directive|define
name|PAL_imb
value|0x0086
end_define

begin_comment
comment|/* U */
end_comment

begin_define
define|#
directive|define
name|PAL_rdunique
value|0x009e
end_define

begin_comment
comment|/* U */
end_comment

begin_define
define|#
directive|define
name|PAL_wrunique
value|0x009f
end_define

begin_comment
comment|/* U */
end_comment

begin_define
define|#
directive|define
name|PAL_gentrap
value|0x00aa
end_define

begin_comment
comment|/* U */
end_comment

begin_comment
comment|/* VMS PAL function codes. */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_ldqp
value|0x0003
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_stqp
value|0x0004
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_fen
value|0x000c
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_ipir
value|0x000d
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mfpr_ipl
value|0x000e
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_ipl
value|0x000f
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mfpr_mces
value|0x0010
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_mces
value|0x0011
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mfpr_prbr
value|0x0013
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_prbr
value|0x0014
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mfpr_ptbr
value|0x0015
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_scbb
value|0x0017
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_sirr
value|0x0018
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_tbia
value|0x001b
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_tbiap
value|0x001c
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_tbis
value|0x001d
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mfpr_usp
value|0x0022
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mtpr_usp
value|0x0023
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mfpr_vptb
value|0x0029
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_mfpr_whami
value|0x003f
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_VMS_rei
value|0x0092
end_define

begin_comment
comment|/* U */
end_comment

begin_comment
comment|/* OSF/1 PAL function codes. */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_rdmces
value|0x0010
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_wrmces
value|0x0011
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_wrfen
value|0x002b
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_wrvptptr
value|0x002d
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_swpctx
value|0x0030
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_wrval
value|0x0031
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_rdval
value|0x0032
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_tbi
value|0x0033
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_wrent
value|0x0034
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_swpipl
value|0x0035
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_rdps
value|0x0036
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_wrkgp
value|0x0037
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_wrusp
value|0x0038
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_wrperfmon
value|0x0039
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_rdusp
value|0x003a
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_whami
value|0x003c
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_retsys
value|0x003d
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_rti
value|0x003f
end_define

begin_comment
comment|/* P */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_callsys
value|0x0083
end_define

begin_comment
comment|/* U */
end_comment

begin_define
define|#
directive|define
name|PAL_OSF1_imb
value|0x0086
end_define

begin_comment
comment|/* U */
end_comment

end_unit

