begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	FreeBSD: src/sys/dev/cardbus/cardbusdevs,v 1.1 1999/11/18 07:21:50 imp Exp   */
end_comment

begin_comment
comment|/*  * Copyright (C) 1999  Hayakawa Koichi.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the author  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This code is stollen from sys/dev/pci/pcidevs  */
end_comment

begin_comment
comment|/*  * List of known CardBus vendors  */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_VENDOR_DEC
value|0x1011
end_define

begin_comment
comment|/* Digital Equipment */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_VENDOR_3COM
value|0x10B7
end_define

begin_comment
comment|/* 3Com */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_VENDOR_ADP
value|0x9004
end_define

begin_comment
comment|/* Adaptec */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_VENDOR_ADP2
value|0x9005
end_define

begin_comment
comment|/* Adaptec (2nd PCI Vendor ID) */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_VENDOR_OPTI
value|0x1045
end_define

begin_comment
comment|/* Opti */
end_comment

begin_comment
comment|/*  * List of known products.  Grouped by vendor.  */
end_comment

begin_comment
comment|/* 3COM Products */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_PRODUCT_3COM_3C575TX
value|0x5057
end_define

begin_comment
comment|/* 3c575 100Base-TX */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_PRODUCT_3COM_3C575BTX
value|0x5157
end_define

begin_comment
comment|/* 3c575B 100Base-TX */
end_comment

begin_comment
comment|/* Adaptec products */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_PRODUCT_ADP_1480
value|0x6075
end_define

begin_comment
comment|/* APA-1480 */
end_comment

begin_comment
comment|/* DEC products */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_PRODUCT_DEC_21142
value|0x0019
end_define

begin_comment
comment|/* DECchip 21142/3 */
end_comment

begin_comment
comment|/* Opti products */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_PRODUCT_OPTI_82C861
value|0xc861
end_define

begin_comment
comment|/* 82C861 USB Host Controller (OHCI) */
end_comment

end_unit

