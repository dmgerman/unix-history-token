begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_HAL_MGMT_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_MGMT_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/*  * struct vxge_hal_mgmt_about_info_t - About info.  * @vendor: PCI Vendor ID.  * @device: PCI Device ID.  * @subsys_vendor: PCI Subsystem Vendor ID.  * @subsys_device: PCI Subsystem Device ID.  * @board_rev: PCI Board revision, e.g. 3 - for Xena 3.  * @vendor_name: Exar Corp.  * @chip_name: X3100.  * @media: Fiber, copper.  * @hal_major: HAL major version number.  * @hal_minor: HAL minor version number.  * @hal_fix: HAL fix number.  * @hal_build: HAL build number.  * @ll_major: Link-layer ULD major version number.  * @ll_minor: Link-layer ULD minor version number.  * @ll_fix: Link-layer ULD fix version number.  * @ll_build: Link-layer ULD build number.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_mgmt_about_info_t
block|{
name|u16
name|vendor
decl_stmt|;
name|u16
name|device
decl_stmt|;
name|u16
name|subsys_vendor
decl_stmt|;
name|u16
name|subsys_device
decl_stmt|;
name|u8
name|board_rev
decl_stmt|;
name|char
name|vendor_name
index|[
literal|16
index|]
decl_stmt|;
name|char
name|chip_name
index|[
literal|16
index|]
decl_stmt|;
name|char
name|media
index|[
literal|16
index|]
decl_stmt|;
name|char
name|hal_major
index|[
literal|4
index|]
decl_stmt|;
name|char
name|hal_minor
index|[
literal|4
index|]
decl_stmt|;
name|char
name|hal_fix
index|[
literal|4
index|]
decl_stmt|;
name|char
name|hal_build
index|[
literal|16
index|]
decl_stmt|;
name|char
name|ll_major
index|[
literal|4
index|]
decl_stmt|;
name|char
name|ll_minor
index|[
literal|4
index|]
decl_stmt|;
name|char
name|ll_fix
index|[
literal|4
index|]
decl_stmt|;
name|char
name|ll_build
index|[
literal|16
index|]
decl_stmt|;
block|}
name|vxge_hal_mgmt_about_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * vxge_hal_mgmt_about - Retrieve about info.  * @devh: HAL device handle.  * @about_info: Filled in by HAL. See vxge_hal_mgmt_about_info_t {}.  * @size: Pointer to buffer containing the Size of the @buffer_info.  * HAL will return an error if the size is smaller than  * sizeof(vxge_hal_mgmt_about_info_t) and returns required size in this field  *  * Retrieve information such as PCI device and vendor IDs, board  * revision number, HAL version number, etc.  *  * Returns: VXGE_HAL_OK - success;  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_VERSION_CONFLICT - Version it not matching.  * VXGE_HAL_ERR_OUT_OF_SPACE - If the buffer is not sufficient  * VXGE_HAL_FAIL - Failed to retrieve the information.  *  * See also: vxge_hal_mgmt_about_info_t {}.  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_about
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_about_info_t
modifier|*
name|about_info
parameter_list|,
name|u32
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_pci_config - Retrieve PCI configuration.  * @devh: HAL device handle.  * @buffer: Buffer for PCI configuration space.  * @size: Pointer to buffer containing the Size of the @buffer.  * HAL will return an error if the size is smaller than  * sizeof(vxge_hal_pci_config_t) and returns required size in this field  *  * Get PCI configuration. Permits to retrieve at run-time configuration  * values that were used to configure the device at load-time.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_VERSION_CONFLICT - Version it not matching.  * VXGE_HAL_ERR_OUT_OF_SPACE - If the buffer is not sufficient  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_pci_config
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u8
modifier|*
name|buffer
parameter_list|,
name|u32
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * struct vxge_hal_mgmt_pm_cap_t - Power Management Capabilities  * @pm_cap_ver: Version  * @pm_cap_pme_clock: PME clock required  * @pm_cap_aux_power: Auxiliary power support  * @pm_cap_dsi: Device specific initialization  * @pm_cap_aux_current: auxiliary current requirements  * @pm_cap_cap_d0: D1 power state support  * @pm_cap_cap_d1: D2 power state support  * @pm_cap_pme_d0: PME# can be asserted from D3hot  * @pm_cap_pme_d1: PME# can be asserted from D3hot  * @pm_cap_pme_d2: PME# can be asserted from D3hot  * @pm_cap_pme_d3_hot: PME# can be asserted from D3hot  * @pm_cap_pme_d3_cold: PME# can be asserted from D3cold  * @pm_ctrl_state: Current power state (D0 to D3)  * @pm_ctrl_no_soft_reset: Devices transitioning from D3hot to D0  * @pm_ctrl_pme_enable: PME pin enable  * @pm_ctrl_pme_data_sel: Data select  * @pm_ctrl_pme_data_scale: Data scale  * @pm_ctrl_pme_status: PME pin status  * @pm_ppb_ext_b2_b3: Stop clock when in D3hot  * @pm_ppb_ext_ecc_en: Bus power/clock control enable  * @pm_data_reg: state dependent data requested by pm_ctrl_pme_data_sel  *  * Power Management Capabilities structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_mgmt_pm_cap_t
block|{
name|u32
name|pm_cap_ver
decl_stmt|;
name|u32
name|pm_cap_pme_clock
decl_stmt|;
name|u32
name|pm_cap_aux_power
decl_stmt|;
name|u32
name|pm_cap_dsi
decl_stmt|;
name|u32
name|pm_cap_aux_current
decl_stmt|;
name|u32
name|pm_cap_cap_d0
decl_stmt|;
name|u32
name|pm_cap_cap_d1
decl_stmt|;
name|u32
name|pm_cap_pme_d0
decl_stmt|;
name|u32
name|pm_cap_pme_d1
decl_stmt|;
name|u32
name|pm_cap_pme_d2
decl_stmt|;
name|u32
name|pm_cap_pme_d3_hot
decl_stmt|;
name|u32
name|pm_cap_pme_d3_cold
decl_stmt|;
name|u32
name|pm_ctrl_state
decl_stmt|;
name|u32
name|pm_ctrl_no_soft_reset
decl_stmt|;
name|u32
name|pm_ctrl_pme_enable
decl_stmt|;
name|u32
name|pm_ctrl_pme_data_sel
decl_stmt|;
name|u32
name|pm_ctrl_pme_data_scale
decl_stmt|;
name|u32
name|pm_ctrl_pme_status
decl_stmt|;
name|u32
name|pm_ppb_ext_b2_b3
decl_stmt|;
name|u32
name|pm_ppb_ext_ecc_en
decl_stmt|;
name|u32
name|pm_data_reg
decl_stmt|;
block|}
name|vxge_hal_mgmt_pm_cap_t
typedef|;
end_typedef

begin_comment
comment|/*  * vxge_hal_mgmt_pm_capabilities_get - Returns the pm capabilities  * @devh: HAL device handle.  * @pm_cap: Power Management Capabilities  *  * Return the pm capabilities  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_pm_capabilities_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_pm_cap_t
modifier|*
name|pm_cap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * struct vxge_hal_mgmt_sid_cap_t - Slot ID Capabilities  * @sid_number_of_slots: Number of solts  * @sid_first_in_chasis: First in chasis flag  * @sid_chasis_number: Chasis Number  *  * Slot ID Capabilities structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_mgmt_sid_cap_t
block|{
name|u32
name|sid_number_of_slots
decl_stmt|;
name|u32
name|sid_first_in_chasis
decl_stmt|;
name|u32
name|sid_chasis_number
decl_stmt|;
block|}
name|vxge_hal_mgmt_sid_cap_t
typedef|;
end_typedef

begin_comment
comment|/*  * vxge_hal_mgmt_sid_capabilities_get - Returns the sid capabilities  * @devh: HAL device handle.  * @sid_cap: Slot Id Capabilities  *  * Return the pm capabilities  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_sid_capabilities_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_sid_cap_t
modifier|*
name|sid_cap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * struct vxge_hal_mgmt_msi_cap_t - MSI Capabilities  * @enable: 1 - MSI enabled, 0 - MSI not enabled  * @is_pvm_capable: 1 - PVM capable, 0 - Not PVM Capable (valid for get only)  * @is_64bit_addr_capable: 1 - 64 bit address capable, 0 - 32 bit address only  *		(valid for get only)  * @vectors_allocated: Number of vectors allocated  *		000-1 vectors  *		001-2 vectors  *		010-4 vectors  *		011-8 vectors  *		100-16 vectors  *		101-32 vectors  * @max_vectors_capable: Maximum number of vectors that can be allocated  *		(valid for get only)  *		000-1 vectors  *		001-2 vectors  *		010-4 vectors  *		011-8 vectors  *		100-16 vectors  *		101-32 vectors  * @address: MSI address  * @data: MSI Data  * @mask_bits: For each Mask bit that is set, the function is prohibited from  *		sending the associated message  * @pending_bits: For each Pending bit that is set, the function has a  *		pending associated message.  *  * MSI Capabilities structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_mgmt_msi_cap_t
block|{
name|u32
name|enable
decl_stmt|;
name|u32
name|is_pvm_capable
decl_stmt|;
name|u32
name|is_64bit_addr_capable
decl_stmt|;
name|u32
name|vectors_allocated
decl_stmt|;
name|u32
name|max_vectors_capable
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MGMT_MSI_CAP_VECTORS_1
value|0
define|#
directive|define
name|VXGE_HAL_MGMT_MSI_CAP_VECTORS_2
value|1
define|#
directive|define
name|VXGE_HAL_MGMT_MSI_CAP_VECTORS_4
value|2
define|#
directive|define
name|VXGE_HAL_MGMT_MSI_CAP_VECTORS_8
value|3
define|#
directive|define
name|VXGE_HAL_MGMT_MSI_CAP_VECTORS_16
value|4
define|#
directive|define
name|VXGE_HAL_MGMT_MSI_CAP_VECTORS_32
value|5
name|u64
name|address
decl_stmt|;
name|u16
name|data
decl_stmt|;
name|u32
name|mask_bits
decl_stmt|;
name|u32
name|pending_bits
decl_stmt|;
block|}
name|vxge_hal_mgmt_msi_cap_t
typedef|;
end_typedef

begin_comment
comment|/*  * vxge_hal_mgmt_msi_capabilities_get - Returns the msi capabilities  * @devh: HAL device handle.  * @msi_cap: MSI Capabilities  *  * Return the msi capabilities  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_msi_capabilities_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_msi_cap_t
modifier|*
name|msi_cap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_msi_capabilities_set - Sets the msi capabilities  * @devh: HAL device handle.  * @msi_cap: MSI Capabilities  *  * Sets the msi capabilities  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_msi_capabilities_set
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_msi_cap_t
modifier|*
name|msi_cap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * struct vxge_hal_mgmt_msix_cap_t - MSIX Capabilities  * @enable: 1 - MSIX enabled, 0 - MSIX not enabled  * @mask_all_vect: 1 - Mask all vectors, 0 - Do not mask all vectors  * @table_size: MSIX Table Size-1  * @table_offset: Offset of the table from the table_bir  * @table_bir: Table Bar address register number 0-BAR0, 2-BAR1, 4-BAR2  * @pba_offset: Offset of the PBA from the pba_bir  * @pba_bir: PBA Bar address register number 0-BAR0, 2-BAR1, 4-BAR2  *  * MSIS Capabilities structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_mgmt_msix_cap_t
block|{
name|u32
name|enable
decl_stmt|;
name|u32
name|mask_all_vect
decl_stmt|;
name|u32
name|table_size
decl_stmt|;
name|u32
name|table_offset
decl_stmt|;
name|u32
name|table_bir
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MGMT_MSIX_CAP_TABLE_BAR0
value|0
define|#
directive|define
name|VXGE_HAL_MGMT_MSIX_CAP_TABLE_BAR1
value|2
define|#
directive|define
name|VXGE_HAL_MGMT_MSIX_CAP_TABLE_BAR2
value|4
name|u32
name|pba_offset
decl_stmt|;
name|u32
name|pba_bir
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MGMT_MSIX_CAP_PBA_BAR0
value|0
define|#
directive|define
name|VXGE_HAL_MGMT_MSIX_CAP_PBA_BAR1
value|2
define|#
directive|define
name|VXGE_HAL_MGMT_MSIX_CAP_PBA_BAR2
value|4
block|}
name|vxge_hal_mgmt_msix_cap_t
typedef|;
end_typedef

begin_comment
comment|/*  * vxge_hal_mgmt_msix_capabilities_get - Returns the msix capabilities  * @devh: HAL device handle.  * @msix_cap: MSIX Capabilities  *  * Return the msix capabilities  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_msix_capabilities_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_msix_cap_t
modifier|*
name|msix_cap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * struct vxge_hal_pci_err_cap_t - PCI Error Capabilities  * @pci_err_header: Error header  * @pci_err_uncor_status: Uncorrectable error status  *		0x00000001 - Training  *		0x00000010 - Data Link Protocol  *		0x00001000 - Poisoned TLP  *		0x00002000 - Flow Control Protocol  *		0x00004000 - Completion Timeout  *		0x00008000 - Completer Abort  *		0x00010000 - Unexpected Completion  *		0x00020000 - Receiver Overflow  *		0x00040000 - Malformed TLP  *		0x00080000 - ECRC Error Status  *		0x00100000 - Unsupported Request  * @pci_err_uncor_mask: Uncorrectable mask  * @pci_err_uncor_server: Uncorrectable server  * @pci_err_cor_status: Correctable status  *		0x00000001 - Receiver Error Status  *		0x00000040 - Bad TLP Status  *		0x00000080 - Bad DLLP Status  *		0x00000100 - REPLAY_NUM Rollover  *		0x00001000 - Replay Timer Timeout  *		VXGE_HAL_PCI_ERR_COR_MASK	20  * @pci_err_cap: Error capability  *		0x00000020 - ECRC Generation Capable  *		0x00000040 - ECRC Generation Enable  *		0x00000080 - ECRC Check Capable  *		0x00000100 - ECRC Check Enable  * @err_header_log: Error header log  * @unused: Reserved  * @pci_err_root_command: Error root command  * @pci_err_root_status: Error root status  * @pci_err_root_cor_src:  Error root correctible source  * @pci_err_root_src: Error root source  *  * MSIS Capabilities structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pci_err_cap_t
block|{
name|u32
name|pci_err_header
decl_stmt|;
name|u32
name|pci_err_uncor_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_TRAIN
value|0x00000001
comment|/* Training */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_DLP
value|0x00000010
comment|/* Data Link Protocol */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_POISON_TLP
value|0x00001000
comment|/* Poisoned TLP */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_FCP
value|0x00002000
comment|/* Flow Ctrl Protocol */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_COMP_TIME
value|0x00004000
comment|/* Completion Timeout */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_COMP_ABORT
value|0x00008000
comment|/* Completer Abort */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_UNX_COMP
value|0x00010000
comment|/* Unexpected Compl */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_RX_OVER
value|0x00020000
comment|/* Receiver Overflow */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_MALF_TLP
value|0x00040000
comment|/* Malformed TLP */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_ECRC
value|0x00080000
comment|/* ECRC Error Status */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_UNC_UNSUP
value|0x00100000
comment|/* Unsupported Request */
name|u32
name|pci_err_uncor_mask
decl_stmt|;
name|u32
name|pci_err_uncor_server
decl_stmt|;
name|u32
name|pci_err_cor_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_COR_RCVR
value|0x00000001
comment|/* Recv Err Status */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_COR_BAD_TLP
value|0x00000040
comment|/* Bad TLP Status */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_COR_BAD_DLLP
value|0x00000080
comment|/* Bad DLLP Status */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_COR_REP_ROLL
value|0x00000100
comment|/* REPLAY Rollover */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_COR_REP_TIMER
value|0x00001000
comment|/* Replay Timeout */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_COR_MASK
value|20
comment|/* Corrble Err Mask */
name|u32
name|pci_err_cap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_CAP_FEP
parameter_list|(
name|x
parameter_list|)
value|((x)& 31)
comment|/* First Err Ptr */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_CAP_ECRC_GENC
value|0x00000020
comment|/* ECRC Gen Capable */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_CAP_ECRC_GENE
value|0x00000040
comment|/* ECRC Gen Enable */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_CAP_ECRC_CHKC
value|0x00000080
comment|/* ECRC Chk Capable */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_CAP_ECRC_CHKE
value|0x00000100
comment|/* ECRC Chk Enable */
name|u32
name|err_header_log
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_HEADER_LOG
parameter_list|(
name|x
parameter_list|)
value|((x)>> 31)
comment|/* Error Hdr Log */
name|u32
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u32
name|pci_err_root_command
decl_stmt|;
name|u32
name|pci_err_root_status
decl_stmt|;
name|u32
name|pci_err_root_cor_src
decl_stmt|;
name|u32
name|pci_err_root_src
decl_stmt|;
block|}
name|vxge_hal_pci_err_cap_t
typedef|;
end_typedef

begin_comment
comment|/*  * vxge_hal_mgmt_pci_err_capabilities_get - Returns the pci error capabilities  * @devh: HAL device handle.  * @err_cap: PCI-E Extended Error Capabilities  *  * Return the PCI-E Extended Error capabilities  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_pci_err_capabilities_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_pci_err_cap_t
modifier|*
name|err_cap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_driver_config - Retrieve driver configuration.  * @drv_config: Device configuration, see vxge_hal_driver_config_t {}.  * @size: Pointer to buffer containing the Size of the @drv_config.  * HAL will return an error if the size is smaller than  * sizeof(vxge_hal_driver_config_t) and returns required size in this field  *  * Get driver configuration. Permits to retrieve at run-time configuration  * values that were used to configure the device at load-time.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_DRIVER_NOT_INITIALIZED - HAL is not initialized.  * VXGE_HAL_ERR_VERSION_CONFLICT - Version is not matching.  * VXGE_HAL_ERR_OUT_OF_SPACE - If the buffer is not sufficient  *  * See also: vxge_hal_driver_config_t {}, vxge_hal_mgmt_device_config().  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_driver_config
parameter_list|(
name|vxge_hal_driver_config_t
modifier|*
name|drv_config
parameter_list|,
name|u32
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VXGE_TRACE_INTO_CIRCULAR_ARR
argument_list|)
end_if

begin_comment
comment|/*  * vxge_hal_mgmt_trace_read - Read trace buffer contents.  * @buffer: Buffer to store the trace buffer contents.  * @buf_size: Size of the buffer.  * @offset: Offset in the internal trace buffer to read data.  * @read_length: Size of the valid data in the buffer.  *  * Read  HAL trace buffer contents starting from the offset  * up to the size of the buffer or till EOF is reached.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_EOF_TRACE_BUF - No more data in the trace buffer.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_trace_read
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|buf_size
parameter_list|,
name|unsigned
modifier|*
name|offset
parameter_list|,
name|unsigned
modifier|*
name|read_length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * vxge_hal_mgmt_device_config - Retrieve device configuration.  * @devh: HAL device handle.  * @dev_config: Device configuration, see vxge_hal_device_config_t {}.  * @size: Pointer to buffer containing the Size of the @dev_config.  * HAL will return an error if the size is smaller than  * sizeof(vxge_hal_device_config_t) and returns required size in this field  *  * Get device configuration. Permits to retrieve at run-time configuration  * values that were used to initialize and configure the device.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_VERSION_CONFLICT - Version it not matching.  * VXGE_HAL_ERR_OUT_OF_SPACE - If the buffer is not sufficient  *  * See also: vxge_hal_device_config_t {}, vxge_hal_mgmt_driver_config().  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_device_config
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_device_config_t
modifier|*
name|dev_config
parameter_list|,
name|u32
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_pcireg_read - Read PCI configuration at a specified  * offset.  * @devh: HAL device handle.  * @offset: Offset in the 256 byte PCI configuration space.  * @value_bits: 8, 16, or 32 (bits) to read.  * @value: Value returned by HAL.  *  * Read PCI configuration, given device and offset in the PCI space.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_INVALID_OFFSET - Register offset in the BAR space is not  * valid.  * VXGE_HAL_ERR_INVALID_VALUE_BIT_SIZE - Invalid bits size. Valid  * values(8/16/32).  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_pcireg_read
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|,
name|int
name|value_bits
parameter_list|,
name|u32
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * enum vxge_hal_mgmt_reg_type_e - Register types.  *  * @vxge_hal_mgmt_reg_type_legacy: Legacy registers  * @vxge_hal_mgmt_reg_type_toc: TOC Registers  * @vxge_hal_mgmt_reg_type_common: Common Registers  * @vxge_hal_mgmt_reg_type_memrepair: Memrepair Registers  * @vxge_hal_mgmt_reg_type_pcicfgmgmt: pci cfg management registers  * @vxge_hal_mgmt_reg_type_mrpcim: mrpcim registers  * @vxge_hal_mgmt_reg_type_srpcim: srpcim registers  * @vxge_hal_mgmt_reg_type_vpmgmt: vpath management registers  * @vxge_hal_mgmt_reg_type_vpath: vpath registers  *  * Register type enumaration  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|vxge_hal_mgmt_reg_type_e
block|{
name|vxge_hal_mgmt_reg_type_legacy
init|=
literal|0
block|,
name|vxge_hal_mgmt_reg_type_toc
init|=
literal|1
block|,
name|vxge_hal_mgmt_reg_type_common
init|=
literal|2
block|,
name|vxge_hal_mgmt_reg_type_memrepair
init|=
literal|3
block|,
name|vxge_hal_mgmt_reg_type_pcicfgmgmt
init|=
literal|4
block|,
name|vxge_hal_mgmt_reg_type_mrpcim
init|=
literal|5
block|,
name|vxge_hal_mgmt_reg_type_srpcim
init|=
literal|6
block|,
name|vxge_hal_mgmt_reg_type_vpmgmt
init|=
literal|7
block|,
name|vxge_hal_mgmt_reg_type_vpath
init|=
literal|8
block|}
name|vxge_hal_mgmt_reg_type_e
typedef|;
end_typedef

begin_comment
comment|/*  * vxge_hal_mgmt_reg_read - Read X3100 register.  * @devh: HAL device handle.  * @type: Register types as defined in enum vxge_hal_mgmt_reg_type_e {}  * @index: For pcicfgmgmt, srpcim, vpmgmt, vpath this gives the Index  *		ignored for others  * @offset: Register offset in the register space qualified by the type and  *		index.  * @value: Register value. Returned by HAL.  * Read X3100 register.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_INVALID_TYPE - Type is not valid.  * VXGE_HAL_ERR_INVALID_INDEX - Index is not valid.  * VXGE_HAL_ERR_INVALID_OFFSET - Register offset in the space is not valid.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_reg_read
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_reg_type_e
name|type
parameter_list|,
name|u32
name|index
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u64
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_reg_Write - Write X3100 register.  * @devh: HAL device handle.  * @type: Register types as defined in enum vxge_hal_mgmt_reg_type_e {}  * @index: For pcicfgmgmt, srpcim, vpmgmt, vpath this gives the Index  *		ignored for others  * @offset: Register offset in the register space qualified by the type and  *		index.  * @value: Register value to be written.  * Write X3100 register.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_INVALID_TYPE - Type is not valid.  * VXGE_HAL_ERR_INVALID_INDEX - Index is not valid.  * VXGE_HAL_ERR_INVALID_OFFSET - Register offset in the space is not valid.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_reg_write
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_reg_type_e
name|type
parameter_list|,
name|u32
name|index
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u64
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_bar0_read - Read X3100 register located at the offset  *			     from bar0.  * @devh: HAL device handle.  * @offset: Register offset from bar0  * @value: Register value. Returned by HAL.  * Read X3100 register.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_INVALID_OFFSET - Register offset in the space is not valid.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_bar0_read
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u64
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_bar1_read - Read X3100 register located at the offset  *			     from bar1.  * @devh: HAL device handle.  * @offset: Register offset from bar1  * @value: Register value. Returned by HAL.  * Read X3100 register.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_INVALID_OFFSET - Register offset in the space is not valid.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_bar1_read
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u64
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_bar0_Write - Write X3100 register located at the offset  *			     from bar0.  * @devh: HAL device handle.  * @offset: Register offset from bar0  * @value: Register value to be written.  * Write X3100 register.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_INVALID_OFFSET - Register offset in the space is not valid.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_bar0_write
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u64
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_register_config - Retrieve register configuration.  * @devh: HAL device handle.  * @type: Register types as defined in enum vxge_hal_mgmt_reg_type_e {}  * @Index: For pcicfgmgmt, srpcim, vpmgmt, vpath this gives the Index  *		ignored for others  * @config: Device configuration, see vxge_hal_device_config_t {}.  * @size: Pointer to buffer containing the Size of the @reg_config.  * HAL will return an error if the size is smaller than  * requested register space and returns required size in this field  *  * Get register configuration. Permits to retrieve register values.  *  * Returns: VXGE_HAL_OK - success.  * VXGE_HAL_ERR_INVALID_DEVICE - Device is not valid.  * VXGE_HAL_ERR_INVALID_TYPE - Type is not valid.  * VXGE_HAL_ERR_INVALID_INDEX - Index is not valid.  * VXGE_HAL_ERR_OUT_OF_SPACE - If the buffer is not sufficient  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_register_config
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mgmt_reg_type_e
name|type
parameter_list|,
name|u32
name|vp_id
parameter_list|,
name|u8
modifier|*
name|config
parameter_list|,
name|u32
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_read_xfp_current_temp - Read current temparature of given port  * @devh: HAL device handle.  * @port: Port number  *  * This routine only gets the temperature for XFP modules. Also, updating of the  * NVRAM can sometimes fail and so the reading we might get may not be uptodate.  */
end_comment

begin_function_decl
name|u32
name|vxge_hal_mgmt_read_xfp_current_temp
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_pma_loopback - Enable or disable PMA loopback  * @devh: HAL device handle.  * @port: Port number  * @enable:Boolean set to 1 to enable and 0 to disable.  *  * Enable or disable PMA loopback.  * Return value:  * 0 on success.  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_pma_loopback
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|port
parameter_list|,
name|u32
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mgmt_xgmii_loopback - Enable or disable xgmii loopback  * @devh: HAL device handle.  * @port: Port number  * @enable:Boolean set to 1 to enable and 0 to disable.  *  * Enable or disable xgmii loopback.  * Return value:  * 0 on success.  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mgmt_xgmii_loopback
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|port
parameter_list|,
name|u32
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_MGMT_H */
end_comment

end_unit

