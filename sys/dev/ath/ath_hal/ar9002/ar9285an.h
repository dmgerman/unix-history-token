begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR9285_AN_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR9285_AN_H__
end_define

begin_comment
comment|/* AR9285 Analog register definitions */
end_comment

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1
value|0x7820
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_ENPACAL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_ENPACAL_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV1
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV1_S
value|25
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV2
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV2_S
value|24
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPAOUT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPAOUT_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2
value|0x7824
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2_OFFCAL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2_OFFCAL_S
value|12
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3
value|0x7828
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_PDVCCOMP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_PDVCCOMP_S
value|25
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_0
value|0x00E00000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_0_S
value|21
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_1
value|0x001C0000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_1_S
value|18
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_2
value|0x00038000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_2_S
value|15
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_3
value|0x00007000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_3_S
value|12
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_4
value|0x00000E00
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_4_S
value|9
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_0
value|0x000001C0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_0_S
value|6
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_1
value|0x00000038
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_1_S
value|3
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_2
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4
value|0x782C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_3
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_3_S
value|29
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_4
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_4_S
value|26
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_0
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_0_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_1
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_1_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_2
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_2_S
value|17
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_3
value|0x0001C000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_3_S
value|14
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_4
value|0x00003800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_4_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6
value|0x7834
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6_CCOMP
value|0x00007800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6_CCOMP_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6_OFFS
value|0x03f00000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6_OFFS_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7
value|0x7838
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7_PWDDB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7_PWDDB_S
value|1
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7_PADRVGN2TAB0
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7_PADRVGN2TAB0_S
value|29
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G8
value|0x783C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G8_PADRVGN2TAB0
value|0x0001C000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G8_PADRVGN2TAB0_S
value|14
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G9
value|0x7840
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1
value|0x7854
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDRXTXBB1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDRXTXBB1_S
value|5
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDV2I
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDV2I_S
value|7
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDDACIF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDDACIF_S
value|8
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_SPARE9
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_SPARE9_S
value|0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP2
value|0x7868
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3
value|0x786c
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_XPABIAS_LVL
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_XPABIAS_LVL_S
value|2
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_PWDDAC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_PWDDAC_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP4
value|0x7870
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP4_DEFAULT
value|0x10142c00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR9285_AN_H__ */
end_comment

end_unit

