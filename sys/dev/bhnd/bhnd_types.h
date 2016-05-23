begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHND_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHND_TYPES_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/** bhnd(4) device classes. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_DEVCLASS_CC
block|,
comment|/**< chipcommon i/o controller */
name|BHND_DEVCLASS_CC_B
block|,
comment|/**< chipcommon auxiliary controller */
name|BHND_DEVCLASS_PMU
block|,
comment|/**< pmu controller */
name|BHND_DEVCLASS_PCI
block|,
comment|/**< pci host/device bridge */
name|BHND_DEVCLASS_PCIE
block|,
comment|/**< pcie host/device bridge */
name|BHND_DEVCLASS_PCCARD
block|,
comment|/**< pcmcia host/device bridge */
name|BHND_DEVCLASS_RAM
block|,
comment|/**< internal RAM/SRAM */
name|BHND_DEVCLASS_MEMC
block|,
comment|/**< memory controller */
name|BHND_DEVCLASS_ENET
block|,
comment|/**< 802.3 MAC/PHY */
name|BHND_DEVCLASS_ENET_MAC
block|,
comment|/**< 802.3 MAC */
name|BHND_DEVCLASS_ENET_PHY
block|,
comment|/**< 802.3 PHY */
name|BHND_DEVCLASS_WLAN
block|,
comment|/**< 802.11 MAC/PHY/Radio */
name|BHND_DEVCLASS_WLAN_MAC
block|,
comment|/**< 802.11 MAC */
name|BHND_DEVCLASS_WLAN_PHY
block|,
comment|/**< 802.11 PHY */
name|BHND_DEVCLASS_CPU
block|,
comment|/**< cpu core */
name|BHND_DEVCLASS_SOC_ROUTER
block|,
comment|/**< interconnect router */
name|BHND_DEVCLASS_SOC_BRIDGE
block|,
comment|/**< interconnect host bridge */
name|BHND_DEVCLASS_EROM
block|,
comment|/**< bus device enumeration ROM */
name|BHND_DEVCLASS_NVRAM
block|,
comment|/**< nvram/flash controller */
name|BHND_DEVCLASS_OTHER
block|,
comment|/**< other / unknown */
name|BHND_DEVCLASS_INVALID
comment|/**< no/invalid class */
block|}
name|bhnd_devclass_t
typedef|;
end_typedef

begin_comment
comment|/**  * bhnd(4) port types.  *   * Only BHND_PORT_DEVICE is guaranteed to be supported by all bhnd(4) bus  * implementations.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_PORT_DEVICE
init|=
literal|0
block|,
comment|/**< device memory */
name|BHND_PORT_BRIDGE
init|=
literal|1
block|,
comment|/**< bridge memory */
name|BHND_PORT_AGENT
init|=
literal|2
block|,
comment|/**< interconnect agent/wrapper */
block|}
name|bhnd_port_type
typedef|;
end_typedef

begin_comment
comment|/**  * bhnd(4) attachment types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_ATTACH_ADAPTER
init|=
literal|0
block|,
comment|/**< A bridged card, such as a PCI WiFi chipset  */
name|BHND_ATTACH_NATIVE
init|=
literal|1
comment|/**< A bus resident on the native host, such as 					  *  the primary or secondary bus of an embedded 					  *  SoC */
block|}
name|bhnd_attach_type
typedef|;
end_typedef

begin_comment
comment|/** Evaluates to true if @p cls is a device class that can be configured  *  as a host bridge device. */
end_comment

begin_define
define|#
directive|define
name|BHND_DEVCLASS_SUPPORTS_HOSTB
parameter_list|(
name|cls
parameter_list|)
define|\
value|((cls) == BHND_DEVCLASS_PCI || (cls) == BHND_DEVCLASS_PCIE ||	\ 	 (cls) == BHND_DEVCLASS_PCCARD)
end_define

begin_comment
comment|/**  * BHND bus address.  *   * @note While the interconnect may support 64-bit addressing, not  * all bridges and SoC CPUs will.  */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|bhnd_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BHND_ADDR_MAX
value|UINT64_MAX
end_define

begin_comment
comment|/**< Maximum bhnd_addr_t value */
end_comment

begin_comment
comment|/** BHND bus size. */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|bhnd_size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BHND_SIZE_MAX
value|UINT64_MAX
end_define

begin_comment
comment|/**< Maximum bhnd_size_t value */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHND_TYPES_H_ */
end_comment

end_unit

