begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Adrian Chadd<adrian@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_BWN_CHIPID_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_BWN_CHIPID_H__
end_define

begin_comment
comment|/*  * BCMA chip identifiers.  */
end_comment

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4313
value|0x4313
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43142
value|43142
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43131
value|43131
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43217
value|43217
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43222
value|43222
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43224
value|43224
end_define

begin_define
define|#
directive|define
name|BCMA_PKG_ID_BCM43224_FAB_CSM
value|0x8
end_define

begin_define
define|#
directive|define
name|BCMA_PKG_ID_BCM43224_FAB_SMIC
value|0xa
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43225
value|43225
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43227
value|43227
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43228
value|43228
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43421
value|43421
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43428
value|43428
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43431
value|43431
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM43460
value|43460
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4331
value|0x4331
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM6362
value|0x6362
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4360
value|0x4360
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4352
value|0x4352
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4706
value|0x5300
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4716
value|0x4716
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM47162
value|47162
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4748
value|0x4748
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4749
value|0x4749
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM5356
value|0x5356
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM5357
value|0x5357
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM53572
value|53572
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM4707
value|53010
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM47094
value|53030
end_define

begin_define
define|#
directive|define
name|BCMA_CHIP_ID_BCM53018
value|53018
end_define

begin_define
define|#
directive|define
name|BCMA_BOARD_TYPE_BCM943224M93
value|0x008B
end_define

begin_define
define|#
directive|define
name|BCMA_BOARD_TYPE_BCM943224M93A
value|0x0090
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_BWN_CHIPID_H__ */
end_comment

end_unit

