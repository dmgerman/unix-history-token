begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  * All rights reserved.  *  * This file is derived from the pcie_core.h header distributed with Broadcom's  * initial brcm80211 Linux driver release, as contributed to the Linux staging  * repository.  *   * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PCI_MDIO_PCIEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PCI_MDIO_PCIEREG_H_
end_define

begin_comment
comment|/* MDIO register offsets */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIO_CTL
value|0x0
end_define

begin_comment
comment|/**< mdio control */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIO_DATA
value|0x4
end_define

begin_comment
comment|/**< mdio data */
end_comment

begin_comment
comment|/* MDIO control */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIOCTL_DIVISOR_MASK
value|0x7f
end_define

begin_comment
comment|/* clock divisor mask */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIOCTL_DIVISOR_VAL
value|0x2
end_define

begin_comment
comment|/* default clock divisor */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIOCTL_PREAM_EN
value|0x80
end_define

begin_comment
comment|/* enable preamble mode */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIOCTL_DONE
value|0x100
end_define

begin_comment
comment|/* tranaction completed */
end_comment

begin_comment
comment|/* MDIO Data */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIODATA_PHYADDR_MASK
value|0x0f800000
end_define

begin_comment
comment|/* phy addr */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIODATA_PHYADDR_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|BHND_MDIODATA_REGADDR_MASK
value|0x007c0000
end_define

begin_comment
comment|/* reg/dev addr */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIODATA_REGADDR_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|BHND_MDIODATA_DATA_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* data  */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIODATA_TA
value|0x00020000
end_define

begin_comment
comment|/* slave turnaround time */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIODATA_START
value|0x40000000
end_define

begin_comment
comment|/* start of transaction */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIODATA_CMD_WRITE
value|0x10000000
end_define

begin_comment
comment|/* write command */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIODATA_CMD_READ
value|0x20000000
end_define

begin_comment
comment|/* read command */
end_comment

begin_define
define|#
directive|define
name|BHND_MDIODATA_ADDR
parameter_list|(
name|_phyaddr
parameter_list|,
name|_regaddr
parameter_list|)
value|(		\ 	(((_phyaddr)<< BHND_MDIODATA_PHYADDR_SHIFT)&	\ 	    BHND_MDIODATA_PHYADDR_MASK) |		\ 	(((_regaddr)<< BHND_MDIODATA_REGADDR_SHIFT)&	\ 	    BHND_MDIODATA_REGADDR_MASK)			\ )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCI_MDIO_PCIEREG_H_ */
end_comment

end_unit

