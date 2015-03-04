begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	NetBSD: ediddevs,v 1.1 2006/05/11 01:49:53 gdamore Exp  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006 Itronix Inc.  * All rights reserved.  *  * Written by Garrett D'Amore for Itronix Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of Itronix Inc. may not be used to endorse  *    or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ITRONIX INC. ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL ITRONIX INC. BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|EDID_VENDOR_AAC
value|"AcerView"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_AOC
value|"AOC"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_APP
value|"Apple Computer"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_AST
value|"AST Research"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_CPL
value|"Compal"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_CPQ
value|"Compaq"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_CTX
value|"CTX"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_DEC
value|"DEC"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_DEL
value|"Dell"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_DPC
value|"Delta"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_DWE
value|"Daewoo"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_EIZ
value|"EIZO"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_ELS
value|"ELSA"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_EPI
value|"Envision"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_FCM
value|"Funai"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_FUJ
value|"Fujitsu"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_GSM
value|"LG Electronics"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_GWY
value|"Gateway 2000"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_HEI
value|"Hyundai"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_HIT
value|"Hitachi"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_HSL
value|"Hansol"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_HTC
value|"Hitachi/Nissei"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_HWP
value|"HP"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_IBM
value|"IBM"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_ICL
value|"Fujitsu ICL"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_IVM
value|"Iiyama"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_KDS
value|"Korea Data Systems"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_MEI
value|"Panasonic"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_MEL
value|"Mitsubishi Electronics"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_NAN
value|"Nanao"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_NEC
value|"NEC"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_NOK
value|"Nokia Data"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_PHL
value|"Philips"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_REL
value|"Relisys"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_SAM
value|"Samsung"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_SGI
value|"SGI"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_SNY
value|"Sony"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_SRC
value|"Shamrock"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_SUN
value|"Sun Microsystems"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_TAT
value|"Tatung"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_TOS
value|"Toshiba"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_TSB
value|"Toshiba"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_VSC
value|"ViewSonic"
end_define

begin_define
define|#
directive|define
name|EDID_VENDOR_ZCM
value|"Zenith"
end_define

begin_comment
comment|/* Dell  - this exists for now as a sample.  I don't have one of these.  */
end_comment

begin_define
define|#
directive|define
name|EDID_PRODUCT_DEL_ULTRASCAN14XE_REVA
value|0x139A
end_define

begin_comment
comment|/* Ultrascan 14XE */
end_comment

begin_define
define|#
directive|define
name|EDID_PRODUCT_DEL_ULTRASCAN14XE_REVB
value|0x139B
end_define

begin_comment
comment|/* Ultrascan 14XE */
end_comment

begin_comment
comment|/* ViewSonic */
end_comment

begin_define
define|#
directive|define
name|EDID_PRODUCT_VSC_17GS
value|0x0c00
end_define

begin_comment
comment|/* 17GS */
end_comment

begin_define
define|#
directive|define
name|EDID_PRODUCT_VSC_17PS
value|0x0c0f
end_define

begin_comment
comment|/* 17PS */
end_comment

end_unit

