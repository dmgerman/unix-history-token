begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbdevs.h,v 1.8 1998/12/02 22:51:50 augustss Exp $	*/
end_comment

begin_comment
comment|/*	FreeBSD $Id$ */
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	NetBSD: usbdevs,v 1.8 1998/12/02 22:49:51 augustss Exp   */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Author: Lennart Augustsson<augustss@carlstedt.se>  *         Carlstedt Research& Technology  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * List of known USB vendors  */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_NEC
value|0x0409
end_define

begin_comment
comment|/* NEC */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_KODAK
value|0x040a
end_define

begin_comment
comment|/* Eastman Kodak */
end_comment

begin_comment
comment|/* Computer Access Technology Corporation */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_CATC
value|0x0423
end_define

begin_comment
comment|/* CATC */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_NANAO
value|0x0440
end_define

begin_comment
comment|/* Nanao */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_UNIXTAR
value|0x0451
end_define

begin_comment
comment|/* Unixtar */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_GENIUS
value|0x0458
end_define

begin_comment
comment|/* Genius */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_CHERRY
value|0x046a
end_define

begin_comment
comment|/* Cherry */
end_comment

begin_comment
comment|/* Behavior Technology Corporation */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_BTC
value|0x046e
end_define

begin_comment
comment|/* BTC */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_PHILIPS
value|0x0471
end_define

begin_comment
comment|/* Philips */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_CONNECTIX
value|0x0478
end_define

begin_comment
comment|/* Connectix */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_CYPRESS
value|0x04b4
end_define

begin_comment
comment|/* Cypress Semiconductor */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_3COM
value|0x04c1
end_define

begin_comment
comment|/* 3Com */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_JAZZ
value|0x04fa
end_define

begin_comment
comment|/* Jazz */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_ATEN
value|0x0557
end_define

begin_comment
comment|/* ATen */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_EIZO
value|0x056d
end_define

begin_comment
comment|/* EIZO */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_AGILER
value|0x056e
end_define

begin_comment
comment|/* Agiler */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_BELKIN
value|0x05ab
end_define

begin_comment
comment|/* Belkin */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_EIZONANAO
value|0x05e7
end_define

begin_comment
comment|/* EIZO Nanao */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_CHIC
value|0x05fe
end_define

begin_comment
comment|/* Chic Technology */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_PLX
value|0x10b5
end_define

begin_comment
comment|/* PLX */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_INSIDEOUT
value|0x1608
end_define

begin_comment
comment|/* Inside Out Networks */
end_comment

begin_define
define|#
directive|define
name|USB_VENDOR_INTEL
value|0x8086
end_define

begin_comment
comment|/* Intel */
end_comment

begin_comment
comment|/*  * List of known products.  Grouped by vendor.  */
end_comment

begin_comment
comment|/* NEC products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_NEC_HUB
value|0x55aa
end_define

begin_comment
comment|/* hub */
end_comment

begin_comment
comment|/* Kodak products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_KODAK_DC260
value|0x0110
end_define

begin_comment
comment|/* Digital Science DC260 */
end_comment

begin_comment
comment|/* CATC products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_CATC_ANDROMEDA
value|0x1237
end_define

begin_comment
comment|/* Andromeda hub */
end_comment

begin_comment
comment|/* Nanao products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_NANAO_HUB
value|0x0000
end_define

begin_comment
comment|/* hub */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_NANAO_MONITOR
value|0x0001
end_define

begin_comment
comment|/* monitor */
end_comment

begin_comment
comment|/* Unixtar products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_UNIXTAR_UTUSB41
value|0x1446
end_define

begin_comment
comment|/* UT-USB41 */
end_comment

begin_comment
comment|/* Genius products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_GENIUS_NICHE
value|0x0001
end_define

begin_comment
comment|/* Niche mouse */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_GENIUS_FLIGHT2000
value|0x1004
end_define

begin_comment
comment|/* Flight 2000 joystick */
end_comment

begin_comment
comment|/* Cherry products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_CHERRY_MY3000KBD
value|0x0001
end_define

begin_comment
comment|/* My3000 keyboard */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_CHERRY_MY3000HUB
value|0x0003
end_define

begin_comment
comment|/* My3000 hub */
end_comment

begin_comment
comment|/* Behavior Technology Corporation products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_BTC_BTC7932
value|0x6782
end_define

begin_comment
comment|/* Keyboard with mouse port */
end_comment

begin_comment
comment|/* Philips products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_PHILIPS_DSS
value|0x0101
end_define

begin_comment
comment|/* DSS 350 Digital Speaker System */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_PHILIPS_HUB
value|0x0201
end_define

begin_comment
comment|/* hub */
end_comment

begin_comment
comment|/* Connectix products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_CONNECTIX_QUICKCAM
value|0x0001
end_define

begin_comment
comment|/* QuickCam */
end_comment

begin_comment
comment|/* 3Com products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_3COM_USR56K
value|0x3021
end_define

begin_comment
comment|/* U.S.Robotics 56000 Voice USB Modem */
end_comment

begin_comment
comment|/* Jazz products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_JAZZ_J6502
value|0x4201
end_define

begin_comment
comment|/* J-6502 speakers */
end_comment

begin_comment
comment|/* Cypress Semiconduuctor products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_CYPRESS_MOUSE
value|0x0001
end_define

begin_comment
comment|/* mouse */
end_comment

begin_comment
comment|/* ATen */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_ATEN_UC1284
value|0x2001
end_define

begin_comment
comment|/* Parallel printer adapter */
end_comment

begin_comment
comment|/* Agiler products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_AGILER_MOUSE29UO
value|0x0002
end_define

begin_comment
comment|/* mouse 29UO */
end_comment

begin_comment
comment|/* Belkin products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_BELKIN_F5U002
value|0x0002
end_define

begin_comment
comment|/* Parallel printer adapter */
end_comment

begin_comment
comment|/* EIZO Nanao products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_EIZO_HUB
value|0x0000
end_define

begin_comment
comment|/* hub */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_EIZO_MONITOR
value|0x0001
end_define

begin_comment
comment|/* monitor */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_EIZONANAO_HUB
value|0x0000
end_define

begin_comment
comment|/* hub */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_EIZONANAO_MONITOR
value|0x0001
end_define

begin_comment
comment|/* monitor */
end_comment

begin_comment
comment|/* Chic Technology */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_CHIC_MOUSE1
value|0x0001
end_define

begin_comment
comment|/* mouse */
end_comment

begin_comment
comment|/* PLX products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_PLX_TESTBOARD
value|0x9060
end_define

begin_comment
comment|/* test board */
end_comment

begin_comment
comment|/* Inside Out Networks products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_INSIDEOUT_EDGEPORT4
value|0x0001
end_define

begin_comment
comment|/* EdgePort/4 */
end_comment

begin_comment
comment|/* Intel products */
end_comment

begin_define
define|#
directive|define
name|USB_PRODUCT_INTEL_TESTBOARD
value|0x9890
end_define

begin_comment
comment|/* 82930 test board */
end_comment

end_unit

