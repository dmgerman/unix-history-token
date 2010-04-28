begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2004 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5210PHY_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5210PHY_H
end_define

begin_comment
comment|/*  * Definitions for the PHY on the Atheros AR5210 parts.  */
end_comment

begin_comment
comment|/* PHY Registers */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BASE
value|0x9800
end_define

begin_comment
comment|/* PHY register base */
end_comment

begin_define
define|#
directive|define
name|AR_PHY
parameter_list|(
name|_n
parameter_list|)
value|(AR_PHY_BASE + ((_n)<<2))
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRCTL
value|0x9804
end_define

begin_comment
comment|/* PHY frame control */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TURBO_MODE
value|0x00000001
end_define

begin_comment
comment|/* PHY turbo mode */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TURBO_SHORT
value|0x00000002
end_define

begin_comment
comment|/* PHY turbo short symbol */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_ERR
value|0x01000000
end_define

begin_comment
comment|/* Detect PHY timing error */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PARITY_ERR
value|0x02000000
end_define

begin_comment
comment|/* Detect signal parity err */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ILLRATE_ERR
value|0x04000000
end_define

begin_comment
comment|/* Detect PHY illegal rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ILLLEN_ERR
value|0x08000000
end_define

begin_comment
comment|/* Detect PHY illegal length */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SERVICE_ERR
value|0x20000000
end_define

begin_comment
comment|/* Detect PHY nonzero service */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TXURN_ERR
value|0x40000000
end_define

begin_comment
comment|/* DetectPHY TX underrun */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FRCTL_BITS
define|\
value|"\20\1TURBO_MODE\2TURBO_SHORT\30TIMING_ERR\31PARITY_ERR\32ILLRATE_ERR"\ 	"\33ILLEN_ERR\35SERVICE_ERR\36TXURN_ERR"
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC
value|0x9808
end_define

begin_comment
comment|/* PHY AGC command */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_DISABLE
value|0x08000000
end_define

begin_comment
comment|/* Disable PHY AGC */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_BITS
value|"\20\33DISABLE"
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHIPID
value|0x9818
end_define

begin_comment
comment|/* PHY chip revision */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ACTIVE
value|0x981c
end_define

begin_comment
comment|/* PHY activation */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* activate PHY */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_DISABLE
value|0x00000002
end_define

begin_comment
comment|/* deactivate PHY */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ACTIVE_BITS
value|"\20\1ENABLE\2DISABLE"
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGCCTL
value|0x9860
end_define

begin_comment
comment|/* PHY calibration and noise floor */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CAL
value|0x00000001
end_define

begin_comment
comment|/* PHY internal calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_NF
value|0x00000002
end_define

begin_comment
comment|/* calc PHY noise-floor */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGCCTL_BITS
value|"\20\1CAL\2NF"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5210PHY_H */
end_comment

end_unit

