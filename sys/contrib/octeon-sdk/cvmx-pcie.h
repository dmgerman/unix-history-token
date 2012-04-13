begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to PCIe as a host(RC) or target(EP)  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_PCIE_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_PCIE_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * The physical memory base mapped by BAR1.  256MB at the end of the  * first 4GB.  */
define|#
directive|define
name|CVMX_PCIE_BAR1_PHYS_BASE
value|((1ull<< 32) - (1ull<< 28))
define|#
directive|define
name|CVMX_PCIE_BAR1_PHYS_SIZE
value|(1ull<< 28)
comment|/*  * The RC base of BAR1.  gen1 has a 39-bit BAR2, gen2 has 41-bit BAR2,  * place BAR1 so it is the same for both.  */
define|#
directive|define
name|CVMX_PCIE_BAR1_RC_BASE
value|(1ull<< 41)
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|upper
range|:
literal|2
decl_stmt|;
comment|/* Normally 2 for XKPHYS */
name|uint64_t
name|reserved_49_61
range|:
literal|13
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|io
range|:
literal|1
decl_stmt|;
comment|/* 1 for IO space access */
name|uint64_t
name|did
range|:
literal|5
decl_stmt|;
comment|/* PCIe DID = 3 */
name|uint64_t
name|subdid
range|:
literal|3
decl_stmt|;
comment|/* PCIe SubDID = 1 */
name|uint64_t
name|reserved_36_39
range|:
literal|4
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|es
range|:
literal|2
decl_stmt|;
comment|/* Endian swap = 1 */
name|uint64_t
name|port
range|:
literal|2
decl_stmt|;
comment|/* PCIe port 0,1 */
name|uint64_t
name|reserved_29_31
range|:
literal|3
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|ty
range|:
literal|1
decl_stmt|;
comment|/* Selects the type of the configuration request (0 = type 0, 1 = type 1). */
name|uint64_t
name|bus
range|:
literal|8
decl_stmt|;
comment|/* Target bus number sent in the ID in the request. */
name|uint64_t
name|dev
range|:
literal|5
decl_stmt|;
comment|/* Target device number sent in the ID in the request. Note that Dev must be                                                 zero for type 0 configuration requests. */
name|uint64_t
name|func
range|:
literal|3
decl_stmt|;
comment|/* Target function number sent in the ID in the request. */
name|uint64_t
name|reg
range|:
literal|12
decl_stmt|;
comment|/* Selects a register in the configuration space of the target. */
block|}
name|config
struct|;
struct|struct
block|{
name|uint64_t
name|upper
range|:
literal|2
decl_stmt|;
comment|/* Normally 2 for XKPHYS */
name|uint64_t
name|reserved_49_61
range|:
literal|13
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|io
range|:
literal|1
decl_stmt|;
comment|/* 1 for IO space access */
name|uint64_t
name|did
range|:
literal|5
decl_stmt|;
comment|/* PCIe DID = 3 */
name|uint64_t
name|subdid
range|:
literal|3
decl_stmt|;
comment|/* PCIe SubDID = 2 */
name|uint64_t
name|reserved_36_39
range|:
literal|4
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|es
range|:
literal|2
decl_stmt|;
comment|/* Endian swap = 1 */
name|uint64_t
name|port
range|:
literal|2
decl_stmt|;
comment|/* PCIe port 0,1 */
name|uint64_t
name|address
range|:
literal|32
decl_stmt|;
comment|/* PCIe IO address */
block|}
name|io
struct|;
struct|struct
block|{
name|uint64_t
name|upper
range|:
literal|2
decl_stmt|;
comment|/* Normally 2 for XKPHYS */
name|uint64_t
name|reserved_49_61
range|:
literal|13
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|io
range|:
literal|1
decl_stmt|;
comment|/* 1 for IO space access */
name|uint64_t
name|did
range|:
literal|5
decl_stmt|;
comment|/* PCIe DID = 3 */
name|uint64_t
name|subdid
range|:
literal|3
decl_stmt|;
comment|/* PCIe SubDID = 3-6 */
name|uint64_t
name|reserved_36_39
range|:
literal|4
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|address
range|:
literal|36
decl_stmt|;
comment|/* PCIe Mem address */
block|}
name|mem
struct|;
block|}
name|cvmx_pcie_address_t
typedef|;
comment|/**  * Return the Core virtual base address for PCIe IO access. IOs are  * read/written as an offset from this address.  *  * @param pcie_port PCIe port the IO is for  *  * @return 64bit Octeon IO base address for read/write  */
name|uint64_t
name|cvmx_pcie_get_io_base_address
parameter_list|(
name|int
name|pcie_port
parameter_list|)
function_decl|;
comment|/**  * Size of the IO address region returned at address  * cvmx_pcie_get_io_base_address()  *  * @param pcie_port PCIe port the IO is for  *  * @return Size of the IO window  */
name|uint64_t
name|cvmx_pcie_get_io_size
parameter_list|(
name|int
name|pcie_port
parameter_list|)
function_decl|;
comment|/**  * Return the Core virtual base address for PCIe MEM access. Memory is  * read/written as an offset from this address.  *  * @param pcie_port PCIe port the IO is for  *  * @return 64bit Octeon IO base address for read/write  */
name|uint64_t
name|cvmx_pcie_get_mem_base_address
parameter_list|(
name|int
name|pcie_port
parameter_list|)
function_decl|;
comment|/**  * Size of the Mem address region returned at address  * cvmx_pcie_get_mem_base_address()  *  * @param pcie_port PCIe port the IO is for  *  * @return Size of the Mem window  */
name|uint64_t
name|cvmx_pcie_get_mem_size
parameter_list|(
name|int
name|pcie_port
parameter_list|)
function_decl|;
comment|/**  * Initialize a PCIe port for use in host(RC) mode. It doesn't enumerate the bus.  *  * @param pcie_port PCIe port to initialize  *  * @return Zero on success  */
name|int
name|cvmx_pcie_rc_initialize
parameter_list|(
name|int
name|pcie_port
parameter_list|)
function_decl|;
comment|/**  * Shutdown a PCIe port and put it in reset  *  * @param pcie_port PCIe port to shutdown  *  * @return Zero on success  */
name|int
name|cvmx_pcie_rc_shutdown
parameter_list|(
name|int
name|pcie_port
parameter_list|)
function_decl|;
comment|/**  * Read 8bits from a Device's config space  *  * @param pcie_port PCIe port the device is on  * @param bus       Sub bus  * @param dev       Device ID  * @param fn        Device sub function  * @param reg       Register to access  *  * @return Result of the read  */
name|uint8_t
name|cvmx_pcie_config_read8
parameter_list|(
name|int
name|pcie_port
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
name|fn
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
comment|/**  * Read 16bits from a Device's config space  *  * @param pcie_port PCIe port the device is on  * @param bus       Sub bus  * @param dev       Device ID  * @param fn        Device sub function  * @param reg       Register to access  *  * @return Result of the read  */
name|uint16_t
name|cvmx_pcie_config_read16
parameter_list|(
name|int
name|pcie_port
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
name|fn
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
comment|/**  * Read 32bits from a Device's config space  *  * @param pcie_port PCIe port the device is on  * @param bus       Sub bus  * @param dev       Device ID  * @param fn        Device sub function  * @param reg       Register to access  *  * @return Result of the read  */
name|uint32_t
name|cvmx_pcie_config_read32
parameter_list|(
name|int
name|pcie_port
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
name|fn
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
comment|/**  * Write 8bits to a Device's config space  *  * @param pcie_port PCIe port the device is on  * @param bus       Sub bus  * @param dev       Device ID  * @param fn        Device sub function  * @param reg       Register to access  * @param val       Value to write  */
name|void
name|cvmx_pcie_config_write8
parameter_list|(
name|int
name|pcie_port
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
name|fn
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint8_t
name|val
parameter_list|)
function_decl|;
comment|/**  * Write 16bits to a Device's config space  *  * @param pcie_port PCIe port the device is on  * @param bus       Sub bus  * @param dev       Device ID  * @param fn        Device sub function  * @param reg       Register to access  * @param val       Value to write  */
name|void
name|cvmx_pcie_config_write16
parameter_list|(
name|int
name|pcie_port
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
name|fn
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint16_t
name|val
parameter_list|)
function_decl|;
comment|/**  * Write 32bits to a Device's config space  *  * @param pcie_port PCIe port the device is on  * @param bus       Sub bus  * @param dev       Device ID  * @param fn        Device sub function  * @param reg       Register to access  * @param val       Value to write  */
name|void
name|cvmx_pcie_config_write32
parameter_list|(
name|int
name|pcie_port
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
name|fn
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
comment|/**  * Read a PCIe config space register indirectly. This is used for  * registers of the form PCIEEP_CFG??? and PCIERC?_CFG???.  *  * @param pcie_port  PCIe port to read from  * @param cfg_offset Address to read  *  * @return Value read  */
name|uint32_t
name|cvmx_pcie_cfgx_read
parameter_list|(
name|int
name|pcie_port
parameter_list|,
name|uint32_t
name|cfg_offset
parameter_list|)
function_decl|;
comment|/**  * Write a PCIe config space register indirectly. This is used for  * registers of the form PCIEEP_CFG??? and PCIERC?_CFG???.  *  * @param pcie_port  PCIe port to write to  * @param cfg_offset Address to write  * @param val        Value to write  */
name|void
name|cvmx_pcie_cfgx_write
parameter_list|(
name|int
name|pcie_port
parameter_list|,
name|uint32_t
name|cfg_offset
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
comment|/**  * Write a 32bit value to the Octeon NPEI register space  *  * @param address Address to write to  * @param val     Value to write  */
specifier|static
specifier|inline
name|void
name|cvmx_pcie_npei_write32
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|cvmx_write64_uint32
argument_list|(
name|address
operator|^
literal|4
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|cvmx_read64_uint32
argument_list|(
name|address
operator|^
literal|4
argument_list|)
expr_stmt|;
block|}
comment|/**  * Read a 32bit value from the Octeon NPEI register space  *  * @param address Address to read  * @return The result  */
specifier|static
specifier|inline
name|uint32_t
name|cvmx_pcie_npei_read32
parameter_list|(
name|uint64_t
name|address
parameter_list|)
block|{
return|return
name|cvmx_read64_uint32
argument_list|(
name|address
operator|^
literal|4
argument_list|)
return|;
block|}
comment|/**  * Initialize a PCIe port for use in target(EP) mode.  *  * @param pcie_port PCIe port to initialize  *  * @return Zero on success  */
name|int
name|cvmx_pcie_ep_initialize
parameter_list|(
name|int
name|pcie_port
parameter_list|)
function_decl|;
comment|/**  * Wait for posted PCIe read/writes to reach the other side of  * the internal PCIe switch. This will insure that core  * read/writes are posted before anything after this function  * is called. This may be necessary when writing to memory that  * will later be read using the DMA/PKT engines.  *  * @param pcie_port PCIe port to wait for  */
name|void
name|cvmx_pcie_wait_for_pending
parameter_list|(
name|int
name|pcie_port
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

