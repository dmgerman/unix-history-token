begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  *  * This file is derived from the hndsoc.h header distributed with  * Broadcom's initial brcm80211 Linux driver release, as  * contributed to the Linux staging repository.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHND_CORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHND_CORE_H_
end_define

begin_comment
comment|/* Common core control flags */
end_comment

begin_define
define|#
directive|define
name|BHND_CF
value|0x0408
end_define

begin_define
define|#
directive|define
name|BHND_CF_BIST_EN
value|0x8000
end_define

begin_comment
comment|/**< built-in self test */
end_comment

begin_define
define|#
directive|define
name|BHND_CF_PME_EN
value|0x4000
end_define

begin_comment
comment|/**< ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_CF_CORE_BITS
value|0x3ffc
end_define

begin_comment
comment|/**< core specific flag mask */
end_comment

begin_define
define|#
directive|define
name|BHND_CF_FGC
value|0x0002
end_define

begin_comment
comment|/**< force clock gating */
end_comment

begin_define
define|#
directive|define
name|BHND_CF_CLOCK_EN
value|0x0001
end_define

begin_comment
comment|/**< enable clock */
end_comment

begin_comment
comment|/* Common core status flags */
end_comment

begin_define
define|#
directive|define
name|BHND_SF
value|0x0500
end_define

begin_define
define|#
directive|define
name|BHND_SF_BIST_DONE
value|0x8000
end_define

begin_comment
comment|/**< ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_SF_BIST_ERROR
value|0x4000
end_define

begin_comment
comment|/**< ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_SF_GATED_CLK
value|0x2000
end_define

begin_comment
comment|/**< clock gated */
end_comment

begin_define
define|#
directive|define
name|BHND_SF_DMA64
value|0x1000
end_define

begin_comment
comment|/**< supports 64-bit DMA */
end_comment

begin_define
define|#
directive|define
name|BHND_SF_CORE_BITS
value|0x0fff
end_define

begin_comment
comment|/**< core-specific status mask */
end_comment

begin_comment
comment|/*Reset core control flags */
end_comment

begin_define
define|#
directive|define
name|BHND_RESET_CF
value|0x0800
end_define

begin_define
define|#
directive|define
name|BHND_RESET_CF_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|BHND_RESET_SF
value|0x0804
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHND_CORE_H_ */
end_comment

end_unit

