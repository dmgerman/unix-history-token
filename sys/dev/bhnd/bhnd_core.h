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
name|BHND_CF_BIST_EN
value|0x8000
end_define

begin_comment
comment|/**< ??? */
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
comment|/*   * A register that is common to all cores to  * communicate w/PMU regarding clock control.  *   * TODO: Determine when this register first appeared.  */
end_comment

begin_define
define|#
directive|define
name|BHND_CLK_CTL_ST
value|0x1e0
end_define

begin_comment
comment|/**< clock control and status */
end_comment

begin_comment
comment|/*  * BHND_CLK_CTL_ST register   *   * Clock Mode		Name	Description  * High Throughput	(HT)	Full bandwidth, low latency. Generally supplied  * 				from PLL.  * Active Low Power	(ALP)	Register access, low speed DMA.  * Idle Low Power	(ILP)	No interconnect activity, or if long latency  * 				is permitted.  */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_FORCEALP
value|0x00000001
end_define

begin_comment
comment|/**< force ALP request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_FORCEHT
value|0x00000002
end_define

begin_comment
comment|/**< force HT request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_FORCEILP
value|0x00000004
end_define

begin_comment
comment|/**< force ILP request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ALPAREQ
value|0x00000008
end_define

begin_comment
comment|/**< ALP Avail Request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_HTAREQ
value|0x00000010
end_define

begin_comment
comment|/**< HT Avail Request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_FORCEHWREQOFF
value|0x00000020
end_define

begin_comment
comment|/**< Force HW Clock Request Off */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_REQ_MASK
value|0x00000700
end_define

begin_comment
comment|/**< external resource requests */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_REQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_CCS_ALPAVAIL
value|0x00010000
end_define

begin_comment
comment|/**< ALP is available */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_HTAVAIL
value|0x00020000
end_define

begin_comment
comment|/**< HT is available */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_BP_ON_APL
value|0x00040000
end_define

begin_comment
comment|/**< RO: Backplane is running on ALP clock */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_BP_ON_HT
value|0x00080000
end_define

begin_comment
comment|/**< RO: Backplane is running on HT clock */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_STS_MASK
value|0x07000000
end_define

begin_comment
comment|/**< external resource status */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_STS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BHND_CCS0_HTAVAIL
value|0x00010000
end_define

begin_comment
comment|/**< HT avail in chipc and pcmcia on 4328a0 */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS0_ALPAVAIL
value|0x00020000
end_define

begin_comment
comment|/**< ALP avail in chipc and pcmcia on 4328a0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHND_CORE_H_ */
end_comment

end_unit

