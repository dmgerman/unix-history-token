begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * the sponsorship of the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GIC_V3_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_GIC_V3_VAR_H_
end_define

begin_define
define|#
directive|define
name|GIC_V3_DEVSTR
value|"ARM Generic Interrupt Controller v3.0"
end_define

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|gic_v3_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|LPI_FLAGS_CONF_FLUSH
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|LPI_CONFTAB_SIZE
value|PAGE_SIZE_64K
end_define

begin_comment
comment|/* 1 bit per LPI + 1 KB more for the obligatory PPI, SGI, SPI stuff */
end_comment

begin_define
define|#
directive|define
name|LPI_PENDTAB_SIZE
value|((LPI_CONFTAB_SIZE / 8) + 0x400)
end_define

begin_struct
struct|struct
name|redist_lpis
block|{
name|vm_offset_t
name|conf_base
decl_stmt|;
name|vm_offset_t
name|pend_base
index|[
name|MAXCPU
index|]
decl_stmt|;
name|uint64_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gic_redists
block|{
comment|/* 	 * Re-Distributor region description. 	 * We will have few of those depending 	 * on the #redistributor-regions property in FDT. 	 */
name|struct
name|resource
modifier|*
modifier|*
name|regions
decl_stmt|;
comment|/* Number of Re-Distributor regions */
name|u_int
name|nregions
decl_stmt|;
comment|/* Per-CPU Re-Distributor handler */
name|struct
name|resource
modifier|*
name|pcpu
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* LPIs data */
name|struct
name|redist_lpis
name|lpis
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gic_v3_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
modifier|*
name|gic_res
decl_stmt|;
name|struct
name|mtx
name|gic_mtx
decl_stmt|;
comment|/* Distributor */
name|struct
name|resource
modifier|*
name|gic_dist
decl_stmt|;
comment|/* Re-Distributors */
name|struct
name|gic_redists
name|gic_redists
decl_stmt|;
name|u_int
name|gic_nirqs
decl_stmt|;
name|u_int
name|gic_idbits
decl_stmt|;
name|boolean_t
name|gic_registered
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_GIC_V3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Device methods */
end_comment

begin_function_decl
name|int
name|gic_v3_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gic_v3_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ITS  */
end_comment

begin_define
define|#
directive|define
name|GIC_V3_ITS_DEVSTR
value|"ARM GIC Interrupt Translation Service"
end_define

begin_define
define|#
directive|define
name|GIC_V3_ITS_COMPSTR
value|"arm,gic-v3-its"
end_define

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|gic_v3_its_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* LPI chunk owned by ITS device */
end_comment

begin_struct
struct|struct
name|lpi_chunk
block|{
name|u_int
name|lpi_base
decl_stmt|;
name|u_int
name|lpi_num
decl_stmt|;
name|u_int
name|lpi_free
decl_stmt|;
comment|/* First free LPI in set */
block|}
struct|;
end_struct

begin_comment
comment|/* ITS device */
end_comment

begin_struct
struct|struct
name|its_dev
block|{
name|TAILQ_ENTRY
argument_list|(
argument|its_dev
argument_list|)
name|entry
expr_stmt|;
comment|/* PCI device */
name|device_t
name|pci_dev
decl_stmt|;
comment|/* Device ID (i.e. PCI device ID) */
name|uint32_t
name|devid
decl_stmt|;
comment|/* List of assigned LPIs */
name|struct
name|lpi_chunk
name|lpis
decl_stmt|;
comment|/* Virtual address of ITT */
name|vm_offset_t
name|itt
decl_stmt|;
comment|/* Interrupt collection */
name|struct
name|its_col
modifier|*
name|col
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|its_dev_list
argument_list|,
name|its_dev
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ITS private table description */
end_comment

begin_struct
struct|struct
name|its_ptab
block|{
name|vm_offset_t
name|ptab_vaddr
decl_stmt|;
comment|/* Virtual Address of table */
name|size_t
name|ptab_pgsz
decl_stmt|;
comment|/* Page size */
name|size_t
name|ptab_npages
decl_stmt|;
comment|/* Number of pages */
block|}
struct|;
end_struct

begin_comment
comment|/* ITS collection description. */
end_comment

begin_struct
struct|struct
name|its_col
block|{
name|uint64_t
name|col_target
decl_stmt|;
comment|/* Target Re-Distributor */
name|uint64_t
name|col_id
decl_stmt|;
comment|/* Collection ID */
block|}
struct|;
end_struct

begin_comment
comment|/* ITS command. Each command is 32 bytes long */
end_comment

begin_struct
struct|struct
name|its_cmd
block|{
name|uint64_t
name|cmd_dword
index|[
literal|4
index|]
decl_stmt|;
comment|/* ITS command double word */
block|}
struct|;
end_struct

begin_comment
comment|/* ITS commands encoding */
end_comment

begin_define
define|#
directive|define
name|ITS_CMD_SYNC
value|(0x05)
end_define

begin_define
define|#
directive|define
name|ITS_CMD_MAPD
value|(0x08)
end_define

begin_define
define|#
directive|define
name|ITS_CMD_MAPC
value|(0x09)
end_define

begin_define
define|#
directive|define
name|ITS_CMD_MAPVI
value|(0x0a)
end_define

begin_define
define|#
directive|define
name|ITS_CMD_MAPI
value|(0x0b)
end_define

begin_define
define|#
directive|define
name|ITS_CMD_INV
value|(0x0c)
end_define

begin_define
define|#
directive|define
name|ITS_CMD_INVALL
value|(0x0d)
end_define

begin_comment
comment|/* Command */
end_comment

begin_define
define|#
directive|define
name|CMD_COMMAND_MASK
value|(0xFFUL)
end_define

begin_comment
comment|/* PCI device ID */
end_comment

begin_define
define|#
directive|define
name|CMD_DEVID_SHIFT
value|(32)
end_define

begin_define
define|#
directive|define
name|CMD_DEVID_MASK
value|(0xFFFFFFFFUL<< CMD_DEVID_SHIFT)
end_define

begin_comment
comment|/* Size of IRQ ID bitfield */
end_comment

begin_define
define|#
directive|define
name|CMD_SIZE_MASK
value|(0xFFUL)
end_define

begin_comment
comment|/* Virtual LPI ID */
end_comment

begin_define
define|#
directive|define
name|CMD_ID_MASK
value|(0xFFFFFFFFUL)
end_define

begin_comment
comment|/* Physical LPI ID */
end_comment

begin_define
define|#
directive|define
name|CMD_PID_SHIFT
value|(32)
end_define

begin_define
define|#
directive|define
name|CMD_PID_MASK
value|(0xFFFFFFFFUL<< CMD_PID_SHIFT)
end_define

begin_comment
comment|/* Collection */
end_comment

begin_define
define|#
directive|define
name|CMD_COL_MASK
value|(0xFFFFUL)
end_define

begin_comment
comment|/* Target (CPU or Re-Distributor) */
end_comment

begin_define
define|#
directive|define
name|CMD_TARGET_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|CMD_TARGET_MASK
value|(0xFFFFFFFFUL<< CMD_TARGET_SHIFT)
end_define

begin_comment
comment|/* Interrupt Translation Table address */
end_comment

begin_define
define|#
directive|define
name|CMD_ITT_MASK
value|(0xFFFFFFFFFF00UL)
end_define

begin_comment
comment|/* Valid command bit */
end_comment

begin_define
define|#
directive|define
name|CMD_VALID_SHIFT
value|(63)
end_define

begin_define
define|#
directive|define
name|CMD_VALID_MASK
value|(1UL<< CMD_VALID_SHIFT)
end_define

begin_comment
comment|/*  * ITS command descriptor.  * Idea for command description passing taken from Linux.  */
end_comment

begin_struct
struct|struct
name|its_cmd_desc
block|{
name|uint8_t
name|cmd_type
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|struct
name|its_col
modifier|*
name|col
decl_stmt|;
block|}
name|cmd_desc_sync
struct|;
struct|struct
block|{
name|struct
name|its_col
modifier|*
name|col
decl_stmt|;
name|uint8_t
name|valid
decl_stmt|;
block|}
name|cmd_desc_mapc
struct|;
struct|struct
block|{
name|struct
name|its_dev
modifier|*
name|its_dev
decl_stmt|;
name|uint32_t
name|pid
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
block|}
name|cmd_desc_mapvi
struct|;
struct|struct
block|{
name|struct
name|its_dev
modifier|*
name|its_dev
decl_stmt|;
name|uint32_t
name|lpinum
decl_stmt|;
block|}
name|cmd_desc_mapi
struct|;
struct|struct
block|{
name|struct
name|its_dev
modifier|*
name|its_dev
decl_stmt|;
name|uint8_t
name|valid
decl_stmt|;
block|}
name|cmd_desc_mapd
struct|;
struct|struct
block|{
name|struct
name|its_dev
modifier|*
name|its_dev
decl_stmt|;
name|uint32_t
name|lpinum
decl_stmt|;
block|}
name|cmd_desc_inv
struct|;
struct|struct
block|{
name|struct
name|its_col
modifier|*
name|col
decl_stmt|;
block|}
name|cmd_desc_invall
struct|;
block|}
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ITS_CMDQ_SIZE
value|PAGE_SIZE_64K
end_define

begin_define
define|#
directive|define
name|ITS_CMDQ_NENTRIES
value|(ITS_CMDQ_SIZE / sizeof(struct its_cmd))
end_define

begin_define
define|#
directive|define
name|ITS_FLAGS_CMDQ_FLUSH
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|ITS_TARGET_NONE
value|0xFBADBEEF
end_define

begin_struct
struct|struct
name|gic_v3_its_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|its_res
decl_stmt|;
name|struct
name|its_cmd
modifier|*
name|its_cmdq_base
decl_stmt|;
comment|/* ITS command queue base */
name|struct
name|its_cmd
modifier|*
name|its_cmdq_write
decl_stmt|;
comment|/* ITS command queue write ptr */
name|struct
name|its_ptab
name|its_ptabs
index|[
name|GITS_BASER_NUM
index|]
decl_stmt|;
comment|/* ITS private tables */
name|struct
name|its_col
modifier|*
name|its_cols
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* Per-CPU collections */
name|uint64_t
name|its_flags
decl_stmt|;
name|struct
name|its_dev_list
name|its_dev_list
decl_stmt|;
name|unsigned
name|long
modifier|*
name|its_lpi_bitmap
decl_stmt|;
name|uint32_t
name|its_lpi_maxid
decl_stmt|;
name|struct
name|mtx
name|its_dev_lock
decl_stmt|;
name|struct
name|mtx
name|its_cmd_lock
decl_stmt|;
name|uint32_t
name|its_socket
decl_stmt|;
comment|/* Socket number ITS is attached to */
block|}
struct|;
end_struct

begin_comment
comment|/* Stuff that is specific to the vendor's implementation */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|its_devbits_func_t
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|its_devid_func_t
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|its_quirks
block|{
name|uint64_t
name|cpuid
decl_stmt|;
name|uint64_t
name|cpuid_mask
decl_stmt|;
name|its_devid_func_t
name|devid_func
decl_stmt|;
name|its_devbits_func_t
name|devbits_func
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|gic_v3_its_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|gic_v3_its_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gic_v3_its_alloc_msix
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gic_v3_its_alloc_msi
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gic_v3_its_map_msi
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|its_init_cpu
parameter_list|(
name|struct
name|gic_v3_its_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lpi_unmask_irq
parameter_list|(
name|device_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lpi_mask_irq
parameter_list|(
name|device_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * GIC Distributor accessors.  * Notice that only GIC sofc can be passed.  */
end_comment

begin_define
define|#
directive|define
name|gic_d_read
parameter_list|(
name|sc
parameter_list|,
name|len
parameter_list|,
name|reg
parameter_list|)
define|\
value|({						\ 	bus_read_##len(sc->gic_dist, reg);	\ })
end_define

begin_define
define|#
directive|define
name|gic_d_write
parameter_list|(
name|sc
parameter_list|,
name|len
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|({						\ 	bus_write_##len(sc->gic_dist, reg, val);\ })
end_define

begin_comment
comment|/* GIC Re-Distributor accessors (per-CPU) */
end_comment

begin_define
define|#
directive|define
name|gic_r_read
parameter_list|(
name|sc
parameter_list|,
name|len
parameter_list|,
name|reg
parameter_list|)
define|\
value|({						\ 	u_int cpu = PCPU_GET(cpuid);		\ 						\ 	bus_read_##len(				\ 	    sc->gic_redists.pcpu[cpu],		\ 	    reg);				\ })
end_define

begin_define
define|#
directive|define
name|gic_r_write
parameter_list|(
name|sc
parameter_list|,
name|len
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|({						\ 	u_int cpu = PCPU_GET(cpuid);		\ 						\ 	bus_write_##len(			\ 	    sc->gic_redists.pcpu[cpu],		\ 	    reg, val);				\ })
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_GENERIC
parameter_list|(
name|pci_dev
parameter_list|)
define|\
value|({								\ 	((pci_get_domain(pci_dev)<< PCI_RID_DOMAIN_SHIFT) |	\ 	(pci_get_bus(pci_dev)<< PCI_RID_BUS_SHIFT) |		\ 	(pci_get_slot(pci_dev)<< PCI_RID_SLOT_SHIFT) |		\ 	(pci_get_function(pci_dev)<< PCI_RID_FUNC_SHIFT));	\ })
end_define

begin_comment
comment|/*  * Request number of maximum MSI-X vectors for this device.  * Device can ask for less vectors than maximum supported but not more.  */
end_comment

begin_define
define|#
directive|define
name|PCI_MSIX_NUM
parameter_list|(
name|pci_dev
parameter_list|)
define|\
value|({						\ 	struct pci_devinfo *dinfo;		\ 	pcicfgregs *cfg;			\ 						\ 	dinfo = device_get_ivars(pci_dev);	\ 	cfg =&dinfo->cfg;			\ 						\ 	cfg->msix.msix_msgnum;			\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GIC_V3_VAR_H_ */
end_comment

end_unit

