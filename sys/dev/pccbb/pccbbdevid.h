begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 M. Warner Losh. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Vendor/Device IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_CLPD6729
value|0x11001013ul
end_define

begin_comment
comment|/* 16bit I/O */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_CLPD6832
value|0x11101013ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_CLPD6833
value|0x11131013ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_CLPD6834
value|0x11121013ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6729
value|0x67291217ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6730
value|0x673A1217ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6832
value|0x68321217ul
end_define

begin_comment
comment|/* Also 6833 */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6860
value|0x68361217ul
end_define

begin_comment
comment|/* Also 6836 */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6872
value|0x68721217ul
end_define

begin_comment
comment|/* Also 6812 */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6912
value|0x69721217ul
end_define

begin_comment
comment|/* Also 6972? */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6922
value|0x69251217ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_OZ6933
value|0x69331217ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C465
value|0x04651180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C466
value|0x04661180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C475
value|0x04751180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C476
value|0x04761180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C477
value|0x04771180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_RICOH_RL5C478
value|0x04781180ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_OMEGA_82C094
value|0x1221119bul
end_define

begin_comment
comment|/* 16bit I/O */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1031
value|0xac13104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1130
value|0xac12104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1131
value|0xac15104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1210
value|0xac1a104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1211
value|0xac1e104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1220
value|0xac17104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1221
value|0xac19104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1225
value|0xac1c104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1250
value|0xac16104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1260
value|0xac18104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1260B
value|0xac30104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1251
value|0xac1d104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1251B
value|0xac1f104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1410
value|0xac50104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1420
value|0xac51104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1421
value|0xac53104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1450
value|0xac1b104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1451
value|0xac52104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI4410
value|0xac41104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI4450
value|0xac40104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI4451
value|0xac42104cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_TOSHIBA_TOPIC95
value|0x06031179ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_TOSHIBA_TOPIC95B
value|0x060a1179ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_TOSHIBA_TOPIC97
value|0x060f1179ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_TOSHIBA_TOPIC100
value|0x06171179ul
end_define

begin_comment
comment|/*  * Other ID, from sources too vague to be reliable  *	Mfg		  model		PCI ID  *   Intel		82092AA		0x12218086	16bit I/O  *   smc/Databook	DB87144		0x310610b3  *   SMC/databook	smc34c90	0xb10610b3  *   Omega/Trident	82c194		0x01941023  *   Omega/Trident	82c722		0x07221023?  *   Opti		82c814		0xc8141045  *   Opti		82c824		0xc8241045  *   NEC		uPD66369	0x003e1033  */
end_comment

end_unit

