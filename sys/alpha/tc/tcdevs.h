begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: tcdevs.h,v 1.12 1998/06/18 23:29:46 jonathan Exp $	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	NetBSD: tcdevs,v 1.10 1998/06/18 23:28:12 jonathan Exp   */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|TC_DEVICE_AV01B_AA
value|"lofi"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_AV01B_AA
value|"DecAudio \"LoFi\" audio/isdn"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_DGLTA_FA
value|"otto"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_DGLTA_FA
value|"DGLTA ATM"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_FORE_ATM
value|"fa"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_FORE_ATM
value|"Fore TCA-100 ATM"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_KZTSA_AA
value|"tza"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_KZTSA_AA
value|"TZA FWD SCSI"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_OTTO
value|"otto"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_OTTO
value|"DEC SRC \"OTTO\" ATM"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAD_AA
value|"le"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAD_AA
value|"LANCE Ethernet"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAF_AA
value|"fza"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAF_AA
value|"DEC FDDIcontroller 700 (DEFZA; fiber optic)"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAF_F
value|"fta"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAF_F
value|"DEFTA FDDI"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAG_AA
value|"mfb"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAG_AA
value|"Monochrome Frame Buffer"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAG_BA
value|"cfb"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAG_BA
value|"Color Frame Buffer"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAG_CA
value|"ga"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAG_CA
value|"2D Graphics"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAG_DA
value|"gq"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAG_DA
value|"3D Graphics (LM)"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAG_DV
value|"xcfb"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAG_DV
value|"Maxine Color Frame Buffer"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAG_FA
value|"gq"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAG_FA
value|"3D Graphics (HE)"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAGB_BA
value|"sfb"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAGB_BA
value|"Smart Frame Buffer"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAGD
value|"sfbp"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAGD
value|"Smart Frame Buffer Plus, unknown bpp"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAGD_AA
value|"sfbp"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAGD_AA
value|"Smart Frame Buffer Plus, 8bpp"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAGD_BA
value|"sfbp"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAGD_BA
value|"Smart Frame Buffer Plus, 32bpp"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAZ_AA
value|"asc"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAZ_AA
value|"53c94 SCSI"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAZ_DS
value|"tcds"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAZ_DS
value|"53c94 TCDS SCSI (baseboard)"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAZ_FS
value|"tcds"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAZ_FS
value|"53c94 TCDS Fast SCSI (baseboard)"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAZB_AA
value|"tcds"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAZB_AA
value|"53c94 TCDS SCSI option card"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAZC_AA
value|"tcds"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAZC_AA
value|"53c94 TCDS Fast SCSI option card"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_T1D4PKT
value|"ds"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_T1D4PKT
value|"DECWRL Turbochannel T1"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_T3PKT
value|"tt"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_T3PKT
value|"DECWRL Turbochannel T3"
end_define

begin_define
define|#
directive|define
name|TC_DEVICE_PMAT_AA
value|"tra"
end_define

begin_define
define|#
directive|define
name|TC_DESCRIPTION_PMAT_AA
value|"DEC TurboChannel Token Ring Controller"
end_define

end_unit

