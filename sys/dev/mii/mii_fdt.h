begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Development sponsored by Microsemi, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_FDT_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_FDT_H_
end_define

begin_comment
comment|/*  * Common FDT config for a PHY, as documented in the devicetree bindings  * documents ethernet.txt and phy.txt.  Boolean properties are represented as  * bits in the flags member.  */
end_comment

begin_struct
struct|struct
name|mii_fdt_phy_config
block|{
name|phandle_t
name|macnode
decl_stmt|;
comment|/* Node (not xref) of parent MAC */
name|phandle_t
name|phynode
decl_stmt|;
comment|/* Node (not xref) of PHY */
name|mii_contype_t
name|con_type
decl_stmt|;
comment|/* MAC<->PHY connection type */
name|u_int
name|max_speed
decl_stmt|;
comment|/* Mbits/sec, 0 = not specified */
name|uint32_t
name|flags
decl_stmt|;
comment|/* MIIF_FDT_xxx boolean properties */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mii_fdt_phy_config
name|mii_fdt_phy_config_t
typedef|;
end_typedef

begin_comment
comment|/* PHY config flags. */
end_comment

begin_define
define|#
directive|define
name|MIIF_FDT_COMPAT_CLAUSE45
value|0x0001
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_BROKEN_TURNAROUND
value|0x0002
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_LANE_SWAP
value|0x0004
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_NO_LANE_SWAP
value|0x0008
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_EEE_BROKEN_100TX
value|0x0010
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_EEE_BROKEN_1000T
value|0x0020
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_EEE_BROKEN_10GT
value|0x0040
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_EEE_BROKEN_1000KX
value|0x0080
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_EEE_BROKEN_10GKX4
value|0x0100
end_define

begin_define
define|#
directive|define
name|MIIF_FDT_EEE_BROKEN_10GKR
value|0x0200
end_define

begin_comment
comment|/*  * Convert between mii_contype enums and devicetree property strings.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|mii_fdt_contype_to_name
parameter_list|(
name|mii_contype_t
name|contype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mii_contype_t
name|mii_fdt_contype_from_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the connection type from the given MAC node. */
end_comment

begin_function_decl
name|mii_contype_t
name|mii_fdt_get_contype
parameter_list|(
name|phandle_t
name|macnode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get/free the config for the given PHY device.  */
end_comment

begin_function_decl
name|void
name|mii_fdt_free_config
parameter_list|(
name|struct
name|mii_fdt_phy_config
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mii_fdt_phy_config_t
modifier|*
name|mii_fdt_get_config
parameter_list|(
name|device_t
name|phydev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

