begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  * All rights reserved.  *  * Portions of this file were derived from the sbchipc.h header contributed by  * Broadcom to to the Linux staging repository, as well as later revisions of  * sbchipc.h distributed with the Asus RT-N16 firmware source code release.  *   * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHNDREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHNDREG_H_
end_define

begin_comment
comment|/**  * The default address at which the ChipCommon core is mapped on all siba(4)  * devices, and most (all?) bcma(4) devices.  */
end_comment

begin_define
define|#
directive|define
name|BHND_DEFAULT_CHIPC_ADDR
value|0x18000000
end_define

begin_comment
comment|/**  * The standard size of a primary BHND_PORT_DEVICE or BHND_PORT_AGENT  * register block.  */
end_comment

begin_define
define|#
directive|define
name|BHND_DEFAULT_CORE_SIZE
value|0x1000
end_define

begin_comment
comment|/**  * The standard size of the siba(4) and bcma(4) enumeration space.  */
end_comment

begin_define
define|#
directive|define
name|BHND_DEFAULT_ENUM_SIZE
value|0x00100000
end_define

begin_comment
comment|/*  * Common per-core clock control/status register available on PMU-equipped  * devices.  *   * Clock Mode		Name	Description  * High Throughput	(HT)	Full bandwidth, low latency. Generally supplied  * 				from PLL.  * Active Low Power	(ALP)	Register access, low speed DMA.  * Idle Low Power	(ILP)	No interconnect activity, or if long latency  * 				is permitted.  */
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
name|BHND_CCS_FORCE_MASK
value|0x0000000F
end_define

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
name|BHND_CCS_AREQ_MASK
value|0x00000018
end_define

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
name|BHND_CCS_ERSRC_MAX
value|2
end_define

begin_comment
comment|/**< maximum ERSRC value (corresponding to bits 0-2) */
end_comment

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
name|BHND_CCS_AVAIL_MASK
value|0x00030000
end_define

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

begin_define
define|#
directive|define
name|BHND_CCS_GET_FLAG
parameter_list|(
name|_value
parameter_list|,
name|_flag
parameter_list|)
define|\
value|(((_value)& _flag) != 0)
end_define

begin_define
define|#
directive|define
name|BHND_CCS_GET_BITS
parameter_list|(
name|_value
parameter_list|,
name|_field
parameter_list|)
define|\
value|(((_value)& _field ## _MASK)>> _field ## _SHIFT)
end_define

begin_define
define|#
directive|define
name|BHND_CCS_SET_BITS
parameter_list|(
name|_value
parameter_list|,
name|_field
parameter_list|)
define|\
value|(((_value)<< _field ## _SHIFT)& _field ## _MASK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHNDREG_H_ */
end_comment

end_unit

