begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2005-2011 Atheros Communications, Inc.  * All rights reserved.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AH_REGDOMAIN_REGENUM_H__
end_ifndef

begin_define
define|#
directive|define
name|__AH_REGDOMAIN_REGENUM_H__
end_define

begin_comment
comment|/*  * Enumerated Regulatory Domain Information 8 bit values indicate that  * the regdomain is really a pair of unitary regdomains.  12 bit values  * are the real unitary regdomains and are the only ones which have the  * frequency bitmasks and flags set.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* 	 * The following regulatory domain definitions are 	 * found in the EEPROM. Each regulatory domain 	 * can operate in either a 5GHz or 2.4GHz wireless mode or 	 * both 5GHz and 2.4GHz wireless modes. 	 * In general, the value holds no special 	 * meaning and is used to decode into either specific 	 * 2.4GHz or 5GHz wireless mode for that particular 	 * regulatory domain. 	 */
name|NO_ENUMRD
init|=
literal|0x00
block|,
name|NULL1_WORLD
init|=
literal|0x03
block|,
comment|/* For 11b-only countries (no 11a allowed) */
name|NULL1_ETSIB
init|=
literal|0x07
block|,
comment|/* Israel */
name|NULL1_ETSIC
init|=
literal|0x08
block|,
name|FCC1_FCCA
init|=
literal|0x10
block|,
comment|/* USA */
name|FCC1_WORLD
init|=
literal|0x11
block|,
comment|/* Hong Kong */
name|FCC4_FCCA
init|=
literal|0x12
block|,
comment|/* USA - Public Safety */
name|FCC5_FCCB
init|=
literal|0x13
block|,
comment|/* USA w/ 1/2 and 1/4 width channels */
name|FCC6_FCCA
init|=
literal|0x14
block|,
comment|/* Canada for AP only */
name|FCC2_FCCA
init|=
literal|0x20
block|,
comment|/* Canada */
name|FCC2_WORLD
init|=
literal|0x21
block|,
comment|/* Australia& HK */
name|FCC2_ETSIC
init|=
literal|0x22
block|,
name|FCC_UBNT
init|=
literal|0x2A
block|,
comment|/* Ubiquity PicoStation M2HP */
name|FRANCE_RES
init|=
literal|0x31
block|,
comment|/* Legacy France for OEM */
name|FCC3_FCCA
init|=
literal|0x3A
block|,
comment|/* USA& Canada w/5470 band, 11h, DFS enabled */
name|FCC3_WORLD
init|=
literal|0x3B
block|,
comment|/* USA& Canada w/5470 band, 11h, DFS enabled */
name|ETSI1_WORLD
init|=
literal|0x37
block|,
name|ETSI3_ETSIA
init|=
literal|0x32
block|,
comment|/* France (optional) */
name|ETSI2_WORLD
init|=
literal|0x35
block|,
comment|/* Hungary& others */
name|ETSI3_WORLD
init|=
literal|0x36
block|,
comment|/* France& others */
name|ETSI4_WORLD
init|=
literal|0x30
block|,
name|ETSI4_ETSIC
init|=
literal|0x38
block|,
name|ETSI5_WORLD
init|=
literal|0x39
block|,
name|ETSI6_WORLD
init|=
literal|0x34
block|,
comment|/* Bulgaria */
name|ETSI8_WORLD
init|=
literal|0x3D
block|,
comment|/* Russia */
name|ETSI9_WORLD
init|=
literal|0x3E
block|,
comment|/* Ukraine */
name|ETSI_RESERVED
init|=
literal|0x33
block|,
comment|/* Reserved (Do not used) */
name|MKK1_MKKA
init|=
literal|0x40
block|,
comment|/* Japan (JP1) */
name|MKK1_MKKB
init|=
literal|0x41
block|,
comment|/* Japan (JP0) */
name|APL4_WORLD
init|=
literal|0x42
block|,
comment|/* Singapore */
name|MKK2_MKKA
init|=
literal|0x43
block|,
comment|/* Japan with 4.9G channels */
name|APL_RESERVED
init|=
literal|0x44
block|,
comment|/* Reserved (Do not used)  */
name|APL2_WORLD
init|=
literal|0x45
block|,
comment|/* Korea */
name|APL2_APLC
init|=
literal|0x46
block|,
name|APL3_WORLD
init|=
literal|0x47
block|,
name|MKK1_FCCA
init|=
literal|0x48
block|,
comment|/* Japan (JP1-1) */
name|APL2_APLD
init|=
literal|0x49
block|,
comment|/* Korea with 2.3G channels */
name|MKK1_MKKA1
init|=
literal|0x4A
block|,
comment|/* Japan (JE1) */
name|MKK1_MKKA2
init|=
literal|0x4B
block|,
comment|/* Japan (JE2) */
name|MKK1_MKKC
init|=
literal|0x4C
block|,
comment|/* Japan (MKK1_MKKA,except Ch14) */
name|APL2_FCCA
init|=
literal|0x4D
block|,
comment|/* Mobile customer */
name|APL3_FCCA
init|=
literal|0x50
block|,
name|APL1_WORLD
init|=
literal|0x52
block|,
comment|/* Latin America */
name|APL1_FCCA
init|=
literal|0x53
block|,
name|APL1_APLA
init|=
literal|0x54
block|,
name|APL1_ETSIC
init|=
literal|0x55
block|,
name|APL2_ETSIC
init|=
literal|0x56
block|,
comment|/* Venezuela */
name|APL5_WORLD
init|=
literal|0x58
block|,
comment|/* Chile */
name|APL6_WORLD
init|=
literal|0x5B
block|,
comment|/* Singapore */
name|APL7_FCCA
init|=
literal|0x5C
block|,
comment|/* Taiwan 5.47 Band */
name|APL8_WORLD
init|=
literal|0x5D
block|,
comment|/* Malaysia 5GHz */
name|APL9_WORLD
init|=
literal|0x5E
block|,
comment|/* Korea 5GHz; before 11/2007; now APs only */
name|APL10_WORLD
init|=
literal|0x5F
block|,
comment|/* Korea 5GHz; After 11/2007; STAs only */
comment|/* 	 * World mode SKUs 	 */
name|WOR0_WORLD
init|=
literal|0x60
block|,
comment|/* World0 (WO0 SKU) */
name|WOR1_WORLD
init|=
literal|0x61
block|,
comment|/* World1 (WO1 SKU) */
name|WOR2_WORLD
init|=
literal|0x62
block|,
comment|/* World2 (WO2 SKU) */
name|WOR3_WORLD
init|=
literal|0x63
block|,
comment|/* World3 (WO3 SKU) */
name|WOR4_WORLD
init|=
literal|0x64
block|,
comment|/* World4 (WO4 SKU) */
name|WOR5_ETSIC
init|=
literal|0x65
block|,
comment|/* World5 (WO5 SKU) */
name|WOR01_WORLD
init|=
literal|0x66
block|,
comment|/* World0-1 (WW0-1 SKU) */
name|WOR02_WORLD
init|=
literal|0x67
block|,
comment|/* World0-2 (WW0-2 SKU) */
name|EU1_WORLD
init|=
literal|0x68
block|,
comment|/* Same as World0-2 (WW0-2 SKU), except active scan ch1-13. No ch14 */
name|WOR9_WORLD
init|=
literal|0x69
block|,
comment|/* World9 (WO9 SKU) */
name|WORA_WORLD
init|=
literal|0x6A
block|,
comment|/* WorldA (WOA SKU) */
name|WORB_WORLD
init|=
literal|0x6B
block|,
comment|/* WorldB (WOB SKU) */
name|WORC_WORLD
init|=
literal|0x6C
block|,
comment|/* WorldC (WOC SKU) */
name|MKK3_MKKB
init|=
literal|0x80
block|,
comment|/* Japan UNI-1 even + MKKB */
name|MKK3_MKKA2
init|=
literal|0x81
block|,
comment|/* Japan UNI-1 even + MKKA2 */
name|MKK3_MKKC
init|=
literal|0x82
block|,
comment|/* Japan UNI-1 even + MKKC */
name|MKK4_MKKB
init|=
literal|0x83
block|,
comment|/* Japan UNI-1 even + UNI-2 + MKKB */
name|MKK4_MKKA2
init|=
literal|0x84
block|,
comment|/* Japan UNI-1 even + UNI-2 + MKKA2 */
name|MKK4_MKKC
init|=
literal|0x85
block|,
comment|/* Japan UNI-1 even + UNI-2 + MKKC */
name|MKK5_MKKB
init|=
literal|0x86
block|,
comment|/* Japan UNI-1 even + UNI-2 + mid-band + MKKB */
name|MKK5_MKKA2
init|=
literal|0x87
block|,
comment|/* Japan UNI-1 even + UNI-2 + mid-band + MKKA2 */
name|MKK5_MKKC
init|=
literal|0x88
block|,
comment|/* Japan UNI-1 even + UNI-2 + mid-band + MKKC */
name|MKK6_MKKB
init|=
literal|0x89
block|,
comment|/* Japan UNI-1 even + UNI-1 odd MKKB */
name|MKK6_MKKA2
init|=
literal|0x8A
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + MKKA2 */
name|MKK6_MKKC
init|=
literal|0x8B
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + MKKC */
name|MKK7_MKKB
init|=
literal|0x8C
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + MKKB */
name|MKK7_MKKA2
init|=
literal|0x8D
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + MKKA2 */
name|MKK7_MKKC
init|=
literal|0x8E
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + MKKC */
name|MKK8_MKKB
init|=
literal|0x8F
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + MKKB */
name|MKK8_MKKA2
init|=
literal|0x90
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + MKKA2 */
name|MKK8_MKKC
init|=
literal|0x91
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + MKKC */
name|MKK14_MKKA1
init|=
literal|0x92
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + 4.9GHz + MKKA1 */
name|MKK15_MKKA1
init|=
literal|0x93
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + 4.9GHz + MKKA1 */
name|MKK10_FCCA
init|=
literal|0xD0
block|,
comment|/* Japan UNI-1 even + UNI-2 + 4.9GHz + FCCA */
name|MKK10_MKKA1
init|=
literal|0xD1
block|,
comment|/* Japan UNI-1 even + UNI-2 + 4.9GHz + MKKA1 */
name|MKK10_MKKC
init|=
literal|0xD2
block|,
comment|/* Japan UNI-1 even + UNI-2 + 4.9GHz + MKKC */
name|MKK10_MKKA2
init|=
literal|0xD3
block|,
comment|/* Japan UNI-1 even + UNI-2 + 4.9GHz + MKKA2 */
name|MKK11_MKKA
init|=
literal|0xD4
block|,
comment|/* Japan UNI-1 even + UNI-2 + mid-band + 4.9GHz + MKKA */
name|MKK11_FCCA
init|=
literal|0xD5
block|,
comment|/* Japan UNI-1 even + UNI-2 + mid-band + 4.9GHz + FCCA */
name|MKK11_MKKA1
init|=
literal|0xD6
block|,
comment|/* Japan UNI-1 even + UNI-2 + mid-band + 4.9GHz + MKKA1 */
name|MKK11_MKKC
init|=
literal|0xD7
block|,
comment|/* Japan UNI-1 even + UNI-2 + mid-band + 4.9GHz + MKKC */
name|MKK11_MKKA2
init|=
literal|0xD8
block|,
comment|/* Japan UNI-1 even + UNI-2 + mid-band + 4.9GHz + MKKA2 */
name|MKK12_MKKA
init|=
literal|0xD9
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + 4.9GHz + MKKA */
name|MKK12_FCCA
init|=
literal|0xDA
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + 4.9GHz + FCCA */
name|MKK12_MKKA1
init|=
literal|0xDB
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + 4.9GHz + MKKA1 */
name|MKK12_MKKC
init|=
literal|0xDC
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + 4.9GHz + MKKC */
name|MKK12_MKKA2
init|=
literal|0xDD
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + 4.9GHz + MKKA2 */
name|MKK13_MKKB
init|=
literal|0xDE
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + mid-band + MKKB + All passive + no adhoc */
comment|/* 	 * Following definitions are used only by s/w to map old 	 * Japan SKUs. 	 */
name|MKK3_MKKA
init|=
literal|0xF0
block|,
comment|/* Japan UNI-1 even + MKKA */
name|MKK3_MKKA1
init|=
literal|0xF1
block|,
comment|/* Japan UNI-1 even + MKKA1 */
name|MKK3_FCCA
init|=
literal|0xF2
block|,
comment|/* Japan UNI-1 even + FCCA */
name|MKK4_MKKA
init|=
literal|0xF3
block|,
comment|/* Japan UNI-1 even + UNI-2 + MKKA */
name|MKK4_MKKA1
init|=
literal|0xF4
block|,
comment|/* Japan UNI-1 even + UNI-2 + MKKA1 */
name|MKK4_FCCA
init|=
literal|0xF5
block|,
comment|/* Japan UNI-1 even + UNI-2 + FCCA */
name|MKK9_MKKA
init|=
literal|0xF6
block|,
comment|/* Japan UNI-1 even + 4.9GHz */
name|MKK10_MKKA
init|=
literal|0xF7
block|,
comment|/* Japan UNI-1 even + UNI-2 + 4.9GHz */
name|MKK6_MKKA1
init|=
literal|0xF8
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + MKKA1 */
name|MKK6_FCCA
init|=
literal|0xF9
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + FCCA */
name|MKK7_MKKA1
init|=
literal|0xFA
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + MKKA1 */
name|MKK7_FCCA
init|=
literal|0xFB
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + FCCA */
name|MKK9_FCCA
init|=
literal|0xFC
block|,
comment|/* Japan UNI-1 even + 4.9GHz + FCCA */
name|MKK9_MKKA1
init|=
literal|0xFD
block|,
comment|/* Japan UNI-1 even + 4.9GHz + MKKA1 */
name|MKK9_MKKC
init|=
literal|0xFE
block|,
comment|/* Japan UNI-1 even + 4.9GHz + MKKC */
name|MKK9_MKKA2
init|=
literal|0xFF
block|,
comment|/* Japan UNI-1 even + 4.9GHz + MKKA2 */
comment|/* 	 * Regulator domains ending in a number (e.g. APL1, 	 * MK1, ETSI4, etc) apply to 5GHz channel and power 	 * information.  Regulator domains ending in a letter 	 * (e.g. APLA, FCCA, etc) apply to 2.4GHz channel and 	 * power information. 	 */
name|APL1
init|=
literal|0x0150
block|,
comment|/* LAT& Asia */
name|APL2
init|=
literal|0x0250
block|,
comment|/* LAT& Asia */
name|APL3
init|=
literal|0x0350
block|,
comment|/* Taiwan */
name|APL4
init|=
literal|0x0450
block|,
comment|/* Jordan */
name|APL5
init|=
literal|0x0550
block|,
comment|/* Chile */
name|APL6
init|=
literal|0x0650
block|,
comment|/* Singapore */
name|APL7
init|=
literal|0x0750
block|,
comment|/* Taiwan, disable ch52 */
name|APL8
init|=
literal|0x0850
block|,
comment|/* Malaysia */
name|APL9
init|=
literal|0x0950
block|,
comment|/* Korea. Before 11/2007. Now used only by APs */
name|APL10
init|=
literal|0x1050
block|,
comment|/* Korea. After 11/2007. For STAs only */
name|ETSI1
init|=
literal|0x0130
block|,
comment|/* Europe& others */
name|ETSI2
init|=
literal|0x0230
block|,
comment|/* Europe& others */
name|ETSI3
init|=
literal|0x0330
block|,
comment|/* Europe& others */
name|ETSI4
init|=
literal|0x0430
block|,
comment|/* Europe& others */
name|ETSI5
init|=
literal|0x0530
block|,
comment|/* Europe& others */
name|ETSI6
init|=
literal|0x0630
block|,
comment|/* Europe& others */
name|ETSI8
init|=
literal|0x0830
block|,
comment|/* Russia */
name|ETSI9
init|=
literal|0x0930
block|,
comment|/* Ukraine */
name|ETSIA
init|=
literal|0x0A30
block|,
comment|/* France */
name|ETSIB
init|=
literal|0x0B30
block|,
comment|/* Israel */
name|ETSIC
init|=
literal|0x0C30
block|,
comment|/* Latin America */
name|FCC1
init|=
literal|0x0110
block|,
comment|/* US& others */
name|FCC2
init|=
literal|0x0120
block|,
comment|/* Canada, Australia& New Zealand */
name|FCC3
init|=
literal|0x0160
block|,
comment|/* US w/new middle band& DFS */
name|FCC4
init|=
literal|0x0165
block|,
comment|/* US Public Safety */
name|FCC5
init|=
literal|0x0166
block|,
comment|/* US w/ 1/2 and 1/4 width channels */
name|FCC6
init|=
literal|0x0610
block|,
comment|/* Canada and Australia */
name|FCCA
init|=
literal|0x0A10
block|,
name|FCCB
init|=
literal|0x0A11
block|,
comment|/* US w/ 1/2 and 1/4 width channels */
name|APLD
init|=
literal|0x0D50
block|,
comment|/* South Korea */
name|MKK1
init|=
literal|0x0140
block|,
comment|/* Japan (UNI-1 odd)*/
name|MKK2
init|=
literal|0x0240
block|,
comment|/* Japan (4.9 GHz + UNI-1 odd) */
name|MKK3
init|=
literal|0x0340
block|,
comment|/* Japan (UNI-1 even) */
name|MKK4
init|=
literal|0x0440
block|,
comment|/* Japan (UNI-1 even + UNI-2) */
name|MKK5
init|=
literal|0x0540
block|,
comment|/* Japan (UNI-1 even + UNI-2 + mid-band) */
name|MKK6
init|=
literal|0x0640
block|,
comment|/* Japan (UNI-1 odd + UNI-1 even) */
name|MKK7
init|=
literal|0x0740
block|,
comment|/* Japan (UNI-1 odd + UNI-1 even + UNI-2 */
name|MKK8
init|=
literal|0x0840
block|,
comment|/* Japan (UNI-1 odd + UNI-1 even + UNI-2 + mid-band) */
name|MKK9
init|=
literal|0x0940
block|,
comment|/* Japan (UNI-1 even + 4.9 GHZ) */
name|MKK10
init|=
literal|0x0B40
block|,
comment|/* Japan (UNI-1 even + UNI-2 + 4.9 GHZ) */
name|MKK11
init|=
literal|0x1140
block|,
comment|/* Japan (UNI-1 even + UNI-2 + 4.9 GHZ) */
name|MKK12
init|=
literal|0x1240
block|,
comment|/* Japan (UNI-1 even + UNI-2 + 4.9 GHZ) */
name|MKK13
init|=
literal|0x0C40
block|,
comment|/* Same as MKK8 but all passive and no adhoc 11a */
name|MKK14
init|=
literal|0x1440
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + 4.9GHz */
name|MKK15
init|=
literal|0x1540
block|,
comment|/* Japan UNI-1 even + UNI-1 odd + UNI-2 + 4.9GHz */
name|MKKA
init|=
literal|0x0A40
block|,
comment|/* Japan */
name|MKKC
init|=
literal|0x0A50
block|,
name|NULL1
init|=
literal|0x0198
block|,
name|WORLD
init|=
literal|0x0199
block|,
name|DEBUG_REG_DMN
init|=
literal|0x01ff
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

