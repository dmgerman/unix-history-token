begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_BWN_PCIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_BWN_PCIVAR_H_
end_define

begin_struct_decl
struct_decl|struct
name|bwn_pci_devcfg
struct_decl|;
end_struct_decl

begin_comment
comment|/** bwn_pci per-instance state. */
end_comment

begin_struct
struct|struct
name|bwn_pci_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< device */
name|device_t
name|bhndb_dev
decl_stmt|;
comment|/**< bhnd bridge device */
specifier|const
name|struct
name|bwn_pci_devcfg
modifier|*
name|devcfg
decl_stmt|;
comment|/**< bwn device config */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< quirk flags */
block|}
struct|;
end_struct

begin_comment
comment|/* bwn device quirks */
end_comment

begin_enum
enum|enum
block|{
comment|/** No quirks */
name|BWN_QUIRK_NONE
init|=
literal|0
block|,
comment|/** 	 * This model/revision has not been tested and may not work. 	 */
name|BWN_QUIRK_UNTESTED
init|=
literal|1
operator|<<
literal|0
block|,
comment|/** 	 * Early dual-band devices did not support accessing multiple PHYs 	 * from a single WLAN core, and instead used separate 2GHz and 5GHz 	 * WLAN cores. 	 *  	 * However, not all cards with two WLAN cores are fully populated; 	 * we must whitelist the boards on which a second WLAN core is actually 	 * usable. 	 */
name|BWN_QUIRK_WLAN_DUALCORE
init|=
literal|1
operator|<<
literal|1
block|,
comment|/** 	 * Some early devices shipped with unconnected ethernet cores; set 	 * this quirk to treat these cores as unpopulated. 	 */
name|BWN_QUIRK_ENET_HW_UNPOPULATED
init|=
literal|1
operator|<<
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/* PCI device descriptor */
end_comment

begin_struct
struct|struct
name|bwn_pci_device
block|{
name|uint16_t
name|vendor
decl_stmt|;
name|uint16_t
name|device
decl_stmt|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|uint32_t
name|quirks
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BWN_BCM_DEV
parameter_list|(
name|_devid
parameter_list|,
name|_desc
parameter_list|,
name|_quirks
parameter_list|)
define|\
value|{ PCI_VENDOR_BROADCOM, PCI_DEVID_ ## _devid,	\         "Broadcom " _desc " Wireless", _quirks }
end_define

begin_comment
comment|/* Supported device table */
end_comment

begin_struct
struct|struct
name|bwn_pci_devcfg
block|{
specifier|const
name|struct
name|bhndb_hwcfg
modifier|*
name|bridge_hwcfg
decl_stmt|;
specifier|const
name|struct
name|bhndb_hw
modifier|*
name|bridge_hwtable
decl_stmt|;
specifier|const
name|struct
name|bwn_pci_device
modifier|*
name|devices
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_BWN_PCIVAR_H_ */
end_comment

end_unit

