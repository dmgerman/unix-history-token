begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  *   * Portions of this file were derived from the aidmp.h header  * distributed with Broadcom's initial brcm80211 Linux driver release, as  * contributed to the Linux staging repository.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCMA_BCMA_DMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_BCMA_BCMA_DMP_H_
end_define

begin_comment
comment|/*  * PL-368 Device Management Plugin (DMP) Registers& Constants  *   * The "DMP" core used in Broadcom HND devices has been described  * by Broadcom engineers (and in published header files) as being  * ARM's PL-368 "Device Management Plugin" system IP, included with  * the CoreLink AMBA Designer tooling.  *   * Documentation for the PL-368 is not publicly available, however,  * and the only public reference by ARM to its existence appears to be  * in the proprietary "NIC-301 Interconnect Device Management (PL368)"  * errata publication, available to licensees as part of ARM's  * CoreLink Controllers and Peripherals Engineering Errata.  */
end_comment

begin_comment
comment|/* Out-of-band Router registers */
end_comment

begin_define
define|#
directive|define
name|BCMA_OOB_BUSCONFIG
value|0x020
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_STATUSA
value|0x100
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_STATUSB
value|0x104
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_STATUSC
value|0x108
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_STATUSD
value|0x10c
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEA0
value|0x200
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEA1
value|0x204
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEA2
value|0x208
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEA3
value|0x20c
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEB0
value|0x280
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEB1
value|0x284
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEB2
value|0x288
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEB3
value|0x28c
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEC0
value|0x300
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEC1
value|0x304
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEC2
value|0x308
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLEC3
value|0x30c
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLED0
value|0x380
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLED1
value|0x384
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLED2
value|0x388
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ENABLED3
value|0x38c
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITCR
value|0xf00
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITIPOOBA
value|0xf10
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITIPOOBB
value|0xf14
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITIPOOBC
value|0xf18
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITIPOOBD
value|0xf1c
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITOPOOBA
value|0xf30
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITOPOOBB
value|0xf34
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITOPOOBC
value|0xf38
end_define

begin_define
define|#
directive|define
name|BCMA_OOB_ITOPOOBD
value|0xf3c
end_define

begin_comment
comment|/* DMP wrapper registers */
end_comment

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELINA30
value|0x000
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELINA74
value|0x004
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELINB30
value|0x020
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELINB74
value|0x024
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELINC30
value|0x040
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELINC74
value|0x044
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELIND30
value|0x060
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELIND74
value|0x064
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTA30
value|0x100
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTA74
value|0x104
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTB30
value|0x120
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTB74
value|0x124
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTC30
value|0x140
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTC74
value|0x144
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTD30
value|0x160
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTD74
value|0x164
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSYNCA
value|0x200
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTAEN
value|0x204
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSYNCB
value|0x220
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTBEN
value|0x224
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSYNCC
value|0x240
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTCEN
value|0x244
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSYNCD
value|0x260
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBSELOUTDEN
value|0x264
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBAEXTWIDTH
value|0x300
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBAINWIDTH
value|0x304
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBAOUTWIDTH
value|0x308
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBBEXTWIDTH
value|0x320
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBBINWIDTH
value|0x324
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBBOUTWIDTH
value|0x328
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBCEXTWIDTH
value|0x340
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBCINWIDTH
value|0x344
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBCOUTWIDTH
value|0x348
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBDEXTWIDTH
value|0x360
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBDINWIDTH
value|0x364
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_OOBDOUTWIDTH
value|0x368
end_define

begin_comment
comment|// This was inherited from Broadcom's aidmp.h header
end_comment

begin_comment
comment|// Is it required for any of our use-cases?
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* defined(IL_BIGENDIAN)&& defined(BCMHND74K) */
end_comment

begin_comment
comment|/* Selective swapped defines for those registers we need in  * big-endian code.  */
end_comment

begin_define
define|#
directive|define
name|BCMA_DMP_IOCTRLSET
value|0x404
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_IOCTRLCLEAR
value|0x400
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_IOCTRL
value|0x40c
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_IOSTATUS
value|0x504
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_RESETCTRL
value|0x804
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_RESETSTATUS
value|0x800
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !IL_BIGENDIAN || !BCMHND74K */
end_comment

begin_define
define|#
directive|define
name|BCMA_DMP_IOCTRLSET
value|0x400
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_IOCTRLCLEAR
value|0x404
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_IOCTRL
value|0x408
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_IOSTATUS
value|0x500
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_RESETCTRL
value|0x800
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_RESETSTATUS
value|0x804
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IL_BIGENDIAN&& BCMHND74K */
end_comment

begin_define
define|#
directive|define
name|BCMA_DMP_IOCTRLWIDTH
value|0x700
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_IOSTATUSWIDTH
value|0x704
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_RESETREADID
value|0x808
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_RESETWRITEID
value|0x80c
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ERRLOGCTRL
value|0xa00
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ERRLOGDONE
value|0xa04
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ERRLOGSTATUS
value|0xa08
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ERRLOGADDRLO
value|0xa0c
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ERRLOGADDRHI
value|0xa10
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ERRLOGID
value|0xa14
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ERRLOGUSER
value|0xa18
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ERRLOGFLAGS
value|0xa1c
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_INTSTATUS
value|0xa00
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_CONFIG
value|0xe00
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITCR
value|0xf00
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITIPOOBA
value|0xf10
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITIPOOBB
value|0xf14
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITIPOOBC
value|0xf18
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITIPOOBD
value|0xf1c
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITIPOOBAOUT
value|0xf30
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITIPOOBBOUT
value|0xf34
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITIPOOBCOUT
value|0xf38
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITIPOOBDOUT
value|0xf3c
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPOOBA
value|0xf50
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPOOBB
value|0xf54
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPOOBC
value|0xf58
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPOOBD
value|0xf5c
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPOOBAIN
value|0xf70
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPOOBBIN
value|0xf74
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPOOBCIN
value|0xf78
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPOOBDIN
value|0xf7c
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_ITOPRESET
value|0xf90
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_PERIPHERIALID4
value|0xfd0
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_PERIPHERIALID5
value|0xfd4
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_PERIPHERIALID6
value|0xfd8
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_PERIPHERIALID7
value|0xfdc
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_PERIPHERIALID0
value|0xfe0
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_PERIPHERIALID1
value|0xfe4
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_PERIPHERIALID2
value|0xfe8
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_PERIPHERIALID3
value|0xfec
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_COMPONENTID0
value|0xff0
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_COMPONENTID1
value|0xff4
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_COMPONENTID2
value|0xff8
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_COMPONENTID3
value|0xffc
end_define

begin_comment
comment|/* resetctrl */
end_comment

begin_define
define|#
directive|define
name|BMCA_DMP_RC_RESET
value|1
end_define

begin_comment
comment|/* config */
end_comment

begin_define
define|#
directive|define
name|BCMA_DMP_CFG_OOB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_CFG_IOS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_CFGIOC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_CFGTO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_CFGERRL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BCMA_DMP_CFGRST
value|0x00000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCMA_BCMA_DMP_H_ */
end_comment

end_unit

