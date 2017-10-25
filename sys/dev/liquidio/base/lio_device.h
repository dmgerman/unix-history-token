begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/*  *  \brief Host Driver: This file defines the octeon device structure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIO_DEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIO_DEVICE_H_
end_define

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_comment
comment|/* for BYTE_ORDER */
end_comment

begin_comment
comment|/* PCI VendorId Device Id */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PF_PCIID
value|0x9702177d
end_define

begin_comment
comment|/*  *  Driver identifies chips by these Ids, created by clubbing together  *  DeviceId+RevisionId; Where Revision Id is not used to distinguish  *  between chips, a value of 0 is used for revision id.  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PF_VID
value|0x9702
end_define

begin_define
define|#
directive|define
name|LIO_CN2350_10G_SUBDEVICE
value|0x03
end_define

begin_define
define|#
directive|define
name|LIO_CN2350_10G_SUBDEVICE1
value|0x04
end_define

begin_define
define|#
directive|define
name|LIO_CN2360_10G_SUBDEVICE
value|0x05
end_define

begin_define
define|#
directive|define
name|LIO_CN2350_25G_SUBDEVICE
value|0x07
end_define

begin_define
define|#
directive|define
name|LIO_CN2360_25G_SUBDEVICE
value|0x06
end_define

begin_comment
comment|/* Endian-swap modes supported by Octeon. */
end_comment

begin_enum
enum|enum
name|lio_pci_swap_mode
block|{
name|LIO_PCI_PASSTHROUGH
init|=
literal|0
block|,
name|LIO_PCI_SWAP_64BIT
init|=
literal|1
block|,
name|LIO_PCI_SWAP_32BIT
init|=
literal|2
block|,
name|LIO_PCI_LW_SWAP_32BIT
init|=
literal|3
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|LIO_CFG_TYPE_DEFAULT
init|=
literal|0
block|,
name|LIO_NUM_CFGS
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|OCTEON_OUTPUT_INTR
value|(2)
end_define

begin_define
define|#
directive|define
name|OCTEON_ALL_INTR
value|0xff
end_define

begin_comment
comment|/*---------------   PCI BAR1 index registers -------------*/
end_comment

begin_comment
comment|/* BAR1 Mask */
end_comment

begin_define
define|#
directive|define
name|LIO_PCI_BAR1_ENABLE_CA
value|1
end_define

begin_define
define|#
directive|define
name|LIO_PCI_BAR1_ENDIAN_MODE
value|LIO_PCI_SWAP_64BIT
end_define

begin_define
define|#
directive|define
name|LIO_PCI_BAR1_ENTRY_VALID
value|1
end_define

begin_define
define|#
directive|define
name|LIO_PCI_BAR1_MASK
value|((LIO_PCI_BAR1_ENABLE_CA<< 3) |   \ 					 (LIO_PCI_BAR1_ENDIAN_MODE<< 1) | \ 					 LIO_PCI_BAR1_ENTRY_VALID)
end_define

begin_comment
comment|/*  *  Octeon Device state.  *  Each octeon device goes through each of these states  *  as it is initialized.  */
end_comment

begin_define
define|#
directive|define
name|LIO_DEV_BEGIN_STATE
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_DEV_PCI_ENABLE_DONE
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_DEV_PCI_MAP_DONE
value|0x2
end_define

begin_define
define|#
directive|define
name|LIO_DEV_DISPATCH_INIT_DONE
value|0x3
end_define

begin_define
define|#
directive|define
name|LIO_DEV_INSTR_QUEUE_INIT_DONE
value|0x4
end_define

begin_define
define|#
directive|define
name|LIO_DEV_SC_BUFF_POOL_INIT_DONE
value|0x5
end_define

begin_define
define|#
directive|define
name|LIO_DEV_MSIX_ALLOC_VECTOR_DONE
value|0x6
end_define

begin_define
define|#
directive|define
name|LIO_DEV_RESP_LIST_INIT_DONE
value|0x7
end_define

begin_define
define|#
directive|define
name|LIO_DEV_DROQ_INIT_DONE
value|0x8
end_define

begin_define
define|#
directive|define
name|LIO_DEV_INTR_SET_DONE
value|0xa
end_define

begin_define
define|#
directive|define
name|LIO_DEV_IO_QUEUES_DONE
value|0xb
end_define

begin_define
define|#
directive|define
name|LIO_DEV_CONSOLE_INIT_DONE
value|0xc
end_define

begin_define
define|#
directive|define
name|LIO_DEV_HOST_OK
value|0xd
end_define

begin_define
define|#
directive|define
name|LIO_DEV_CORE_OK
value|0xe
end_define

begin_define
define|#
directive|define
name|LIO_DEV_RUNNING
value|0xf
end_define

begin_define
define|#
directive|define
name|LIO_DEV_IN_RESET
value|0x10
end_define

begin_define
define|#
directive|define
name|LIO_DEV_STATE_INVALID
value|0x11
end_define

begin_define
define|#
directive|define
name|LIO_DEV_STATES
value|LIO_DEV_STATE_INVALID
end_define

begin_comment
comment|/*  * Octeon Device interrupts  * These interrupt bits are set in int_status filed of  * octeon_device structure  */
end_comment

begin_define
define|#
directive|define
name|LIO_DEV_INTR_DMA0_FORCE
value|0x01
end_define

begin_define
define|#
directive|define
name|LIO_DEV_INTR_DMA1_FORCE
value|0x02
end_define

begin_define
define|#
directive|define
name|LIO_DEV_INTR_PKT_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|LIO_RESET_MSECS
value|(3000)
end_define

begin_comment
comment|/*---------------------------DISPATCH LIST-------------------------------*/
end_comment

begin_comment
comment|/*  *  The dispatch list entry.  *  The driver keeps a record of functions registered for each  *  response header opcode in this structure. Since the opcode is  *  hashed to index into the driver's list, more than one opcode  *  can hash to the same entry, in which case the list field points  *  to a linked list with the other entries.  */
end_comment

begin_struct
struct|struct
name|lio_dispatch
block|{
comment|/* Singly-linked tail queue node for this entry */
name|struct
name|lio_stailq_node
name|node
decl_stmt|;
comment|/* Singly-linked tail queue head for this entry */
name|struct
name|lio_stailq_head
name|head
decl_stmt|;
comment|/* The opcode for which the dispatch function& arg should be used */
name|uint16_t
name|opcode
decl_stmt|;
comment|/* The function to be called for a packet received by the driver */
name|lio_dispatch_fn_t
name|dispatch_fn
decl_stmt|;
comment|/* 	 * The application specified argument to be passed to the above 	 * function along with the received packet 	 */
name|void
modifier|*
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The dispatch list structure. */
end_comment

begin_struct
struct|struct
name|lio_dispatch_list
block|{
comment|/* access to dispatch list must be atomic */
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/* Count of dispatch functions currently registered */
name|uint32_t
name|count
decl_stmt|;
comment|/* The list of dispatch functions */
name|struct
name|lio_dispatch
modifier|*
name|dlist
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*-----------------------  THE OCTEON DEVICE  ---------------------------*/
end_comment

begin_define
define|#
directive|define
name|LIO_MEM_REGIONS
value|3
end_define

begin_comment
comment|/*  *  PCI address space information.  *  Each of the 3 address spaces given by BAR0, BAR2 and BAR4 of  *  Octeon gets mapped to different physical address spaces in  *  the kernel.  */
end_comment

begin_struct
struct|struct
name|lio_mem_bus_space
block|{
name|struct
name|resource
modifier|*
name|pci_mem
decl_stmt|;
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_MAX_MAPS
value|32
end_define

begin_struct
struct|struct
name|lio_io_enable
block|{
name|uint64_t
name|iq
decl_stmt|;
name|uint64_t
name|oq
decl_stmt|;
name|uint64_t
name|iq64B
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_reg_list
block|{
name|uint32_t
name|pci_win_wr_addr
decl_stmt|;
name|uint32_t
name|pci_win_rd_addr_hi
decl_stmt|;
name|uint32_t
name|pci_win_rd_addr_lo
decl_stmt|;
name|uint32_t
name|pci_win_rd_addr
decl_stmt|;
name|uint32_t
name|pci_win_wr_data_hi
decl_stmt|;
name|uint32_t
name|pci_win_wr_data_lo
decl_stmt|;
name|uint32_t
name|pci_win_wr_data
decl_stmt|;
name|uint32_t
name|pci_win_rd_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_MAX_CONSOLE_READ_BYTES
value|512
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|octeon_console_print_fn
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|num
parameter_list|,
name|char
modifier|*
name|pre
parameter_list|,
name|char
modifier|*
name|suf
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|lio_console
block|{
name|uint32_t
name|active
decl_stmt|;
name|uint32_t
name|waiting
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
name|uint32_t
name|buffer_size
decl_stmt|;
name|uint64_t
name|input_base_addr
decl_stmt|;
name|uint64_t
name|output_base_addr
decl_stmt|;
name|octeon_console_print_fn
name|print
decl_stmt|;
name|char
name|leftover
index|[
name|LIO_MAX_CONSOLE_READ_BYTES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_board_info
block|{
name|char
name|name
index|[
name|LIO_BOARD_NAME
index|]
decl_stmt|;
name|char
name|serial_number
index|[
name|LIO_SERIAL_NUM_LEN
index|]
decl_stmt|;
name|uint64_t
name|major
decl_stmt|;
name|uint64_t
name|minor
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_fn_list
block|{
name|void
function_decl|(
modifier|*
name|setup_iq_regs
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setup_oq_regs
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|process_interrupt_regs
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|uint64_t
function_decl|(
modifier|*
name|msix_interrupt_handler
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|soft_reset
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|setup_device_regs
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bar1_idx_setup
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bar1_idx_write
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|uint32_t
function_decl|(
modifier|*
name|bar1_idx_read
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|uint32_t
function_decl|(
modifier|*
name|update_iq_read_idx
function_decl|)
parameter_list|(
name|struct
name|lio_instr_queue
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|enable_interrupt
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|disable_interrupt
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|enable_io_queues
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|disable_io_queues
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Must be multiple of 8, changing breaks ABI */
end_comment

begin_define
define|#
directive|define
name|LIO_BOOTMEM_NAME_LEN
value|128
end_define

begin_comment
comment|/*  * Structure for named memory blocks  * Number of descriptors  * available can be changed without affecting compatibility,  * but name length changes require a bump in the bootmem  * descriptor version  * Note: This structure must be naturally 64 bit aligned, as a single  * memory image will be used by both 32 and 64 bit programs.  */
end_comment

begin_struct
struct|struct
name|cvmx_bootmem_named_block_desc
block|{
comment|/* Base address of named block */
name|uint64_t
name|base_addr
decl_stmt|;
comment|/* Size actually allocated for named block */
name|uint64_t
name|size
decl_stmt|;
comment|/* name of named block */
name|char
name|name
index|[
name|LIO_BOOTMEM_NAME_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_fw_info
block|{
name|uint32_t
name|max_nic_ports
decl_stmt|;
comment|/* max nic ports for the device */
name|uint32_t
name|num_gmx_ports
decl_stmt|;
comment|/* num gmx ports */
name|uint64_t
name|app_cap_flags
decl_stmt|;
comment|/* firmware cap flags */
comment|/* 	 * The core application is running in this mode. 	 * See octeon-drv-opcodes.h for values. 	 */
name|uint32_t
name|app_mode
decl_stmt|;
name|char
name|lio_firmware_version
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_callout
block|{
name|struct
name|callout
name|timer
decl_stmt|;
name|void
modifier|*
name|ctxptr
decl_stmt|;
name|uint64_t
name|ctxul
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_NIC_STARTER_TIMEOUT
value|30000
end_define

begin_comment
comment|/* 30000ms (30s) */
end_comment

begin_struct
struct|struct
name|lio_tq
block|{
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
name|struct
name|timeout_task
name|work
decl_stmt|;
name|void
modifier|*
name|ctxptr
decl_stmt|;
name|uint64_t
name|ctxul
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_if_props
block|{
comment|/* 	 * Each interface in the Octeon device has a network 	 * device pointer (used for OS specific calls). 	 */
name|int
name|rx_on
decl_stmt|;
name|int
name|gmxport
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_MSIX_PO_INT
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_MSIX_PI_INT
value|0x2
end_define

begin_struct
struct|struct
name|lio_pf_vf_hs_word
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
comment|/* PKIND value assigned for the DPI interface */
name|uint64_t
name|pkind
range|:
literal|8
decl_stmt|;
comment|/* OCTEON core clock multiplier   */
name|uint64_t
name|core_tics_per_us
range|:
literal|16
decl_stmt|;
comment|/* OCTEON coprocessor clock multiplier  */
name|uint64_t
name|coproc_tics_per_us
range|:
literal|16
decl_stmt|;
comment|/* app that currently running on OCTEON  */
name|uint64_t
name|app_mode
range|:
literal|8
decl_stmt|;
comment|/* RESERVED */
name|uint64_t
name|reserved
range|:
literal|16
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != LITTLE_ENDIAN */
comment|/* RESERVED */
name|uint64_t
name|reserved
range|:
literal|16
decl_stmt|;
comment|/* app that currently running on OCTEON  */
name|uint64_t
name|app_mode
range|:
literal|8
decl_stmt|;
comment|/* OCTEON coprocessor clock multiplier  */
name|uint64_t
name|coproc_tics_per_us
range|:
literal|16
decl_stmt|;
comment|/* OCTEON core clock multiplier   */
name|uint64_t
name|core_tics_per_us
range|:
literal|16
decl_stmt|;
comment|/* PKIND value assigned for the DPI interface */
name|uint64_t
name|pkind
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == LITTLE_ENDIAN */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_sriov_info
block|{
comment|/* Actual rings left for PF device */
name|uint32_t
name|num_pf_rings
decl_stmt|;
comment|/* SRN of PF usable IO queues */
name|uint32_t
name|pf_srn
decl_stmt|;
comment|/* total pf rings */
name|uint32_t
name|trs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_ioq_vector
block|{
name|struct
name|octeon_device
modifier|*
name|oct_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix_res
decl_stmt|;
name|void
modifier|*
name|tag
decl_stmt|;
name|int
name|droq_index
decl_stmt|;
name|int
name|vector
decl_stmt|;
name|cpuset_t
name|affinity_mask
decl_stmt|;
name|uint32_t
name|ioq_num
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  The Octeon device.  *  Each Octeon device has this structure to represent all its  *  components.  */
end_comment

begin_struct
struct|struct
name|octeon_device
block|{
comment|/* Lock for PCI window configuration accesses */
name|struct
name|mtx
name|pci_win_lock
decl_stmt|;
comment|/* Lock for memory accesses */
name|struct
name|mtx
name|mem_access_lock
decl_stmt|;
comment|/* PCI device pointer */
name|device_t
name|device
decl_stmt|;
comment|/* Chip specific information. */
name|void
modifier|*
name|chip
decl_stmt|;
comment|/* Number of interfaces detected in this octeon device. */
name|uint32_t
name|ifcount
decl_stmt|;
name|struct
name|lio_if_props
name|props
decl_stmt|;
comment|/* Octeon Chip type. */
name|uint16_t
name|chip_id
decl_stmt|;
name|uint16_t
name|rev_id
decl_stmt|;
name|uint16_t
name|subdevice_id
decl_stmt|;
name|uint16_t
name|pf_num
decl_stmt|;
comment|/* This device's id - set by the driver. */
name|uint32_t
name|octeon_id
decl_stmt|;
comment|/* This device's PCIe port used for traffic. */
name|uint16_t
name|pcie_port
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|LIO_FLAG_MSIX_ENABLED
value|(uint32_t)(1<< 2)
comment|/* The state of this device */
specifier|volatile
name|int
name|status
decl_stmt|;
comment|/* memory mapped io range */
name|struct
name|lio_mem_bus_space
name|mem_bus_space
index|[
name|LIO_MEM_REGIONS
index|]
decl_stmt|;
name|struct
name|lio_reg_list
name|reg_list
decl_stmt|;
name|struct
name|lio_fn_list
name|fn_list
decl_stmt|;
name|struct
name|lio_board_info
name|boardinfo
decl_stmt|;
name|uint32_t
name|num_iqs
decl_stmt|;
comment|/* The pool containing pre allocated buffers used for soft commands */
name|struct
name|lio_sc_buffer_pool
name|sc_buf_pool
decl_stmt|;
comment|/* The input instruction queues */
name|struct
name|lio_instr_queue
modifier|*
name|instr_queue
index|[
name|LIO_MAX_POSSIBLE_INSTR_QUEUES
index|]
decl_stmt|;
comment|/* The doubly-linked list of instruction response */
name|struct
name|lio_response_list
name|response_list
index|[
name|LIO_MAX_RESPONSE_LISTS
index|]
decl_stmt|;
name|uint32_t
name|num_oqs
decl_stmt|;
comment|/* The DROQ output queues  */
name|struct
name|lio_droq
modifier|*
name|droq
index|[
name|LIO_MAX_POSSIBLE_OUTPUT_QUEUES
index|]
decl_stmt|;
name|struct
name|lio_io_enable
name|io_qmask
decl_stmt|;
comment|/* List of dispatch functions */
name|struct
name|lio_dispatch_list
name|dispatch
decl_stmt|;
name|uint32_t
name|int_status
decl_stmt|;
comment|/* Physical location of the cvmx_bootmem_desc_t in octeon memory */
name|uint64_t
name|bootmem_desc_addr
decl_stmt|;
comment|/* 	 * Placeholder memory for named blocks. 	 * Assumes single-threaded access 	 */
name|struct
name|cvmx_bootmem_named_block_desc
name|bootmem_named_block_desc
decl_stmt|;
comment|/* Address of consoles descriptor */
name|uint64_t
name|console_desc_addr
decl_stmt|;
comment|/* Number of consoles available. 0 means they are inaccessible */
name|uint32_t
name|num_consoles
decl_stmt|;
comment|/* Console caches */
name|struct
name|lio_console
name|console
index|[
name|LIO_MAX_MAPS
index|]
decl_stmt|;
comment|/* Console named block info */
struct|struct
block|{
name|uint64_t
name|dram_region_base
decl_stmt|;
name|int
name|bar1_index
decl_stmt|;
block|}
name|console_nb_info
struct|;
comment|/* Coprocessor clock rate. */
name|uint64_t
name|coproc_clock_rate
decl_stmt|;
comment|/* 	 * The core application is running in this mode. See lio_common.h 	 * for values. 	 */
name|uint32_t
name|app_mode
decl_stmt|;
name|struct
name|lio_fw_info
name|fw_info
decl_stmt|;
comment|/* The name given to this device. */
name|char
name|device_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|lio_tq
name|dma_comp_tq
decl_stmt|;
comment|/* Lock for dma response list */
name|struct
name|mtx
name|cmd_resp_wqlock
decl_stmt|;
name|uint32_t
name|cmd_resp_state
decl_stmt|;
name|struct
name|lio_tq
name|check_db_tq
index|[
name|LIO_MAX_POSSIBLE_INSTR_QUEUES
index|]
decl_stmt|;
name|struct
name|lio_callout
name|console_timer
index|[
name|LIO_MAX_MAPS
index|]
decl_stmt|;
name|int
name|num_msix_irqs
decl_stmt|;
comment|/* For PF, there is one non-ioq interrupt handler */
name|struct
name|resource
modifier|*
name|msix_res
decl_stmt|;
name|int
name|aux_vector
decl_stmt|;
name|void
modifier|*
name|tag
decl_stmt|;
define|#
directive|define
name|INTRNAMSIZ
value|(32)
define|#
directive|define
name|IRQ_NAME_OFF
parameter_list|(
name|i
parameter_list|)
value|((i) * INTRNAMSIZ)
name|struct
name|lio_sriov_info
name|sriov_info
decl_stmt|;
name|struct
name|lio_pf_vf_hs_word
name|pfvf_hsword
decl_stmt|;
name|int
name|msix_on
decl_stmt|;
comment|/* IOq information of it's corresponding MSI-X interrupt. */
name|struct
name|lio_ioq_vector
modifier|*
name|ioq_vector
decl_stmt|;
name|int
name|rx_pause
decl_stmt|;
name|int
name|tx_pause
decl_stmt|;
comment|/* TX/RX process pkt budget */
name|uint32_t
name|rx_budget
decl_stmt|;
name|uint32_t
name|tx_budget
decl_stmt|;
name|struct
name|octeon_link_stats
name|link_stats
decl_stmt|;
comment|/* stastics from firmware */
name|struct
name|proc
modifier|*
name|watchdog_task
decl_stmt|;
specifier|volatile
name|bool
name|cores_crashed
decl_stmt|;
name|uint32_t
name|rx_coalesce_usecs
decl_stmt|;
name|uint32_t
name|rx_max_coalesced_frames
decl_stmt|;
name|uint32_t
name|tx_max_coalesced_frames
decl_stmt|;
define|#
directive|define
name|OCTEON_UBOOT_BUFFER_SIZE
value|512
name|char
name|uboot_version
index|[
name|OCTEON_UBOOT_BUFFER_SIZE
index|]
decl_stmt|;
name|int
name|uboot_len
decl_stmt|;
name|int
name|uboot_sidx
decl_stmt|,
name|uboot_eidx
decl_stmt|;
struct|struct
block|{
name|int
name|bus
decl_stmt|;
name|int
name|dev
decl_stmt|;
name|int
name|func
decl_stmt|;
block|}
name|loc
struct|;
specifier|volatile
name|int
modifier|*
name|adapter_refcount
decl_stmt|;
comment|/* reference count of adapter */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_DRV_ONLINE
value|1
end_define

begin_define
define|#
directive|define
name|LIO_DRV_OFFLINE
value|2
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PF
parameter_list|(
name|oct
parameter_list|)
value|((oct)->chip_id == LIO_CN23XX_PF_VID)
end_define

begin_define
define|#
directive|define
name|LIO_CHIP_CONF
parameter_list|(
name|oct
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(((struct lio_ ## TYPE  *)((oct)->chip))->conf)
end_define

begin_define
define|#
directive|define
name|MAX_IO_PENDING_PKT_COUNT
value|100
end_define

begin_comment
comment|/*------------------ Function Prototypes ----------------------*/
end_comment

begin_comment
comment|/* Initialize device list memory */
end_comment

begin_function_decl
name|void
name|lio_init_device_list
parameter_list|(
name|int
name|conf_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free memory for Input and Output queue structures for a octeon device */
end_comment

begin_function_decl
name|void
name|lio_free_device_mem
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Look up a free entry in the octeon_device table and allocate resources  * for the octeon_device structure for an octeon device. Called at init  * time.  */
end_comment

begin_function_decl
name|struct
name|octeon_device
modifier|*
name|lio_allocate_device
parameter_list|(
name|device_t
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Register a device's bus location at initialization time.  *  @param oct        - pointer to the octeon device structure.  *  @param bus        - PCIe bus #  *  @param dev        - PCIe device #  *  @param func       - PCIe function #  *  @param is_pf      - TRUE for PF, FALSE for VF  *  @return reference count of device's adapter  */
end_comment

begin_function_decl
name|int
name|lio_register_device
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
name|func
parameter_list|,
name|int
name|is_pf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Deregister a device at de-initialization time.  *  @param oct - pointer to the octeon device structure.  *  @return reference count of device's adapter  */
end_comment

begin_function_decl
name|int
name|lio_deregister_device
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Initialize the driver's dispatch list which is a mix of a hash table  *  and a linked list. This is done at driver load time.  *  @param octeon_dev - pointer to the octeon device structure.  *  @return 0 on success, else -ve error value  */
end_comment

begin_function_decl
name|int
name|lio_init_dispatch_list
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Delete the driver's dispatch list and all registered entries.  * This is done at driver unload time.  * @param octeon_dev - pointer to the octeon device structure.  */
end_comment

begin_function_decl
name|void
name|lio_delete_dispatch_list
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize the core device fields with the info returned by the FW.  * @param recv_info - Receive info structure  * @param buf       - Receive buffer  */
end_comment

begin_function_decl
name|int
name|lio_core_drv_init
parameter_list|(
name|struct
name|lio_recv_info
modifier|*
name|recv_info
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Gets the dispatch function registered to receive packets with a  *  given opcode/subcode.  *  @param  octeon_dev  - the octeon device pointer.  *  @param  opcode      - the opcode for which the dispatch function  *                        is to checked.  *  @param  subcode     - the subcode for which the dispatch function  *                        is to checked.  *  *  @return Success: lio_dispatch_fn_t (dispatch function pointer)  *  @return Failure: NULL  *  *  Looks up the dispatch list to get the dispatch function for a  *  given opcode.  */
end_comment

begin_function_decl
name|lio_dispatch_fn_t
name|lio_get_dispatch
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|,
name|uint16_t
name|opcode
parameter_list|,
name|uint16_t
name|subcode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Get the octeon device pointer.  *  @param octeon_id  - The id for which the octeon device pointer is required.  *  @return Success: Octeon device pointer.  *  @return Failure: NULL.  */
end_comment

begin_function_decl
name|struct
name|octeon_device
modifier|*
name|lio_get_device
parameter_list|(
name|uint32_t
name|octeon_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Get the octeon id assigned to the octeon device passed as argument.  *  This function is exported to other modules.  *  @param dev - octeon device pointer passed as a void *.  *  @return octeon device id  */
end_comment

begin_function_decl
name|int
name|lio_get_device_id
parameter_list|(
name|void
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|uint16_t
name|OCTEON_MAJOR_REV
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
block|{
name|uint16_t
name|rev
init|=
operator|(
name|oct
operator|->
name|rev_id
operator|&
literal|0xC
operator|)
operator|>>
literal|2
decl_stmt|;
return|return
operator|(
operator|(
name|rev
operator|==
literal|0
operator|)
condition|?
literal|1
else|:
name|rev
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|OCTEON_MINOR_REV
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
block|{
return|return
operator|(
name|oct
operator|->
name|rev_id
operator|&
literal|0x3
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *  Read windowed register.  *  @param  oct   -  pointer to the Octeon device.  *  @param  addr  -  Address of the register to read.  *  *  This routine is called to read from the indirectly accessed  *  Octeon registers that are visible through a PCI BAR0 mapped window  *  register.  *  @return  - 64 bit value read from the register.  */
end_comment

begin_function_decl
name|uint64_t
name|lio_pci_readq
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Write windowed register.  *  @param  oct  -  pointer to the Octeon device.  *  @param  val  -  Value to write  *  @param  addr -  Address of the register to write  *  *  This routine is called to write to the indirectly accessed  *  Octeon registers that are visible through a PCI BAR0 mapped window  *  register.  *  @return   Nothing.  */
end_comment

begin_function_decl
name|void
name|lio_pci_writeq
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint64_t
name|val
parameter_list|,
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Checks if memory access is okay  *  * @param oct which octeon to send to  * @return Zero on success, negative on failure.  */
end_comment

begin_function_decl
name|int
name|lio_mem_access_ok
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Waits for DDR initialization.  *  * @param oct which octeon to send to  * @param timeout_in_ms pointer to how long to wait until DDR is initialized  * in ms.  *                      If contents are 0, it waits until contents are non-zero  *                      before starting to check.  * @return Zero on success, negative on failure.  */
end_comment

begin_function_decl
name|int
name|lio_wait_for_ddr_init
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|unsigned
name|long
modifier|*
name|timeout_in_ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Wait for u-boot to boot and be waiting for a command.  *  * @param wait_time_hundredths  *               Maximum time to wait  *  * @return Zero on success, negative on failure.  */
end_comment

begin_function_decl
name|int
name|lio_wait_for_bootloader
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|wait_time_hundredths
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize console access  *  * @param oct which octeon initialize  * @return Zero on success, negative on failure.  */
end_comment

begin_function_decl
name|int
name|lio_init_consoles
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Adds access to a console to the device.  *  * @param oct:		which octeon to add to  * @param console_num:	which console  * @param dbg_enb:      ptr to debug enablement string, one of:  *                    * NULL for no debug output (i.e. disabled)  *                    * empty string enables debug output (via default method)  *                    * specific string to enable debug console output  *  * @return Zero on success, negative on failure.  */
end_comment

begin_function_decl
name|int
name|lio_add_console
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|console_num
parameter_list|,
name|char
modifier|*
name|dbg_enb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* write or read from a console */
end_comment

begin_function_decl
name|int
name|lio_console_write
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|console_num
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|write_request_size
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Removes all attached consoles. */
end_comment

begin_function_decl
name|void
name|lio_remove_consoles
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Send a string to u-boot on console 0 as a command.  *  * @param oct which octeon to send to  * @param cmd_str String to send  * @param wait_hundredths Time to wait for u-boot to accept the command.  *  * @return Zero on success, negative on failure.  */
end_comment

begin_function_decl
name|int
name|lio_console_send_cmd
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|char
modifier|*
name|cmd_str
parameter_list|,
name|uint32_t
name|wait_hundredths
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Parses, validates, and downloads firmware, then boots associated cores.  *  @param oct which octeon to download firmware to  *  @param data  - The complete firmware file image  *  @param size  - The size of the data  *  *  @return 0 if success.  *         -EINVAL if file is incompatible or badly formatted.  *         -ENODEV if no handler was found for the application type or an  *         invalid octeon id was passed.  */
end_comment

begin_function_decl
name|int
name|lio_download_firmware
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|lio_get_state_string
parameter_list|(
specifier|volatile
name|int
modifier|*
name|state_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Sets up instruction queues for the device  *  @param oct which octeon to setup  *  *  @return 0 if success. 1 if fails  */
end_comment

begin_function_decl
name|int
name|lio_setup_instr_queue0
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Sets up output queues for the device  *  @param oct which octeon to setup  *  *  @return 0 if success. 1 if fails  */
end_comment

begin_function_decl
name|int
name|lio_setup_output_queue0
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_get_tx_qsize
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|q_no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_get_rx_qsize
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|q_no
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Retrieve the config for the device  *  @param oct which octeon  *  @param card_type type of card  *  *  @returns pointer to configuration  */
end_comment

begin_function_decl
name|void
modifier|*
name|lio_get_config_info
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint16_t
name|card_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Gets the octeon device configuration  *  @return - pointer to the octeon configuration struture  */
end_comment

begin_function_decl
name|struct
name|lio_config
modifier|*
name|lio_get_conf
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lio_free_ioq_vector
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_allocate_ioq_vector
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lio_enable_irq
parameter_list|(
name|struct
name|lio_droq
modifier|*
name|droq
parameter_list|,
name|struct
name|lio_instr_queue
modifier|*
name|iq
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|uint32_t
name|lio_read_pci_cfg
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|pci_read_config
argument_list|(
name|oct
operator|->
name|device
argument_list|,
name|reg
argument_list|,
literal|4
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|lio_write_pci_cfg
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|)
block|{
name|pci_write_config
argument_list|(
name|oct
operator|->
name|device
argument_list|,
name|reg
argument_list|,
name|value
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint8_t
name|lio_read_csr8
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|bus_space_read_1
argument_list|(
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|lio_write_csr8
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint8_t
name|val
parameter_list|)
block|{
name|bus_space_write_1
argument_list|(
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|lio_read_csr16
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|bus_space_read_2
argument_list|(
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|lio_write_csr16
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint16_t
name|val
parameter_list|)
block|{
name|bus_space_write_2
argument_list|(
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|lio_read_csr32
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|bus_space_read_4
argument_list|(
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|lio_write_csr32
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|bus_space_write_4
argument_list|(
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|lio_read_csr64
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__i386__
return|return
operator|(
name|lio_read_csr32
argument_list|(
name|oct
argument_list|,
name|reg
argument_list|)
operator||
operator|(
operator|(
name|uint64_t
operator|)
name|lio_read_csr32
argument_list|(
name|oct
argument_list|,
name|reg
operator|+
literal|4
argument_list|)
operator|<<
literal|32
operator|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|bus_space_read_8
argument_list|(
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
name|reg
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|lio_write_csr64
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__i386__
name|lio_write_csr32
argument_list|(
name|oct
argument_list|,
name|reg
argument_list|,
operator|(
name|uint32_t
operator|)
name|val
argument_list|)
expr_stmt|;
name|lio_write_csr32
argument_list|(
name|oct
argument_list|,
name|reg
operator|+
literal|4
argument_list|,
name|val
operator|>>
literal|32
argument_list|)
expr_stmt|;
else|#
directive|else
name|bus_space_write_8
argument_list|(
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|oct
operator|->
name|mem_bus_space
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIO_DEVICE_H_ */
end_comment

end_unit

