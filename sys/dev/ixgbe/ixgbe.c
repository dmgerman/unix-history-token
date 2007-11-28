begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  Copyright (c) 2001-2007, Intel Corporation All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Intel Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ***************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_KERNEL_OPTION_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|"opt_device_polling.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ixgbe.h"
end_include

begin_comment
comment|/*********************************************************************  *  Set this to one to display debug statistics  *********************************************************************/
end_comment

begin_decl_stmt
name|int
name|ixgbe_display_debug_stats
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*********************************************************************  *  Driver version  *********************************************************************/
end_comment

begin_decl_stmt
name|char
name|ixgbe_driver_version
index|[]
init|=
literal|"1.2.16"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*********************************************************************  *  PCI Device ID Table  *  *  Used by probe to select devices to load on  *  Last field stores an index into ixgbe_strings  *  Last entry must be all 0s  *  *  { Vendor ID, Device ID, SubVendor ID, SubDevice ID, String Index }  *********************************************************************/
end_comment

begin_decl_stmt
specifier|static
name|ixgbe_vendor_info_t
name|ixgbe_vendor_info_array
index|[]
init|=
block|{
block|{
name|IXGBE_INTEL_VENDOR_ID
block|,
name|IXGBE_DEV_ID_82598AF_DUAL_PORT
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
name|IXGBE_INTEL_VENDOR_ID
block|,
name|IXGBE_DEV_ID_82598AF_SINGLE_PORT
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
name|IXGBE_INTEL_VENDOR_ID
block|,
name|IXGBE_DEV_ID_82598EB_CX4
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
name|IXGBE_INTEL_VENDOR_ID
block|,
name|IXGBE_DEV_ID_82598AT
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* required last entry */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*********************************************************************  *  Table of branding strings  *********************************************************************/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ixgbe_strings
index|[]
init|=
block|{
literal|"Intel(R) PRO/10GbE PCI-Express Network Driver"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*********************************************************************  *  Function prototypes  *********************************************************************/
end_comment

begin_function_decl
specifier|static
name|int
name|ixgbe_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_shutdown
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_start_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_watchdog
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_init_locked
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_stop
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_media_status
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifmediareq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_media_change
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_identify_hardware
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_allocate_pci_resources
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_free_pci_resources
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_local_timer
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_hardware_init
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_setup_interface
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_allocate_queues
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_allocate_msix_resources
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
end_if

begin_function_decl
specifier|static
name|int
name|ixgbe_setup_msix
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|ixgbe_allocate_transmit_buffers
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_setup_transmit_structures
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_setup_transmit_ring
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_initialize_transmit_units
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_free_transmit_structures
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_free_transmit_buffers
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_allocate_receive_buffers
parameter_list|(
name|struct
name|rx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_setup_receive_structures
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_setup_receive_ring
parameter_list|(
name|struct
name|rx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_initialize_receive_units
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_free_receive_structures
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_free_receive_buffers
parameter_list|(
name|struct
name|rx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_enable_intr
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_disable_intr
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_update_stats_counters
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|ixgbe_txeof
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_rxeof
parameter_list|(
name|struct
name|rx_ring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_rx_checksum
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_set_promisc
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_disable_promisc
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_set_multi
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_print_hw_stats
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_print_debug_info
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_update_link_status
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_get_buf
parameter_list|(
name|struct
name|rx_ring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_enable_hw_vlans
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_encap
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_sysctl_stats
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_sysctl_debug
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_set_flowcntl
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ixgbe_dma_malloc
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|,
name|struct
name|ixgbe_dma_alloc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_dma_free
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|struct
name|ixgbe_dma_alloc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_add_rx_process_limit
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|boolean_t
name|ixgbe_tx_ctx_setup
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|boolean_t
name|ixgbe_tso_setup
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_set_ivar
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u8
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_configure_ivars
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u8
modifier|*
name|ixgbe_mc_array_itr
parameter_list|(
name|u8
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Legacy Fast Interrupt routine and handlers */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
end_if

begin_function_decl
specifier|static
name|int
name|ixgbe_fast_irq
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The MSI/X Interrupt handlers */
end_comment

begin_function_decl
specifier|static
name|void
name|ixgbe_msix_tx
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_msix_rx
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_msix_link
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|static
name|void
name|ixgbe_fast_irq
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|ixgbe_rxtx
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ixgbe_link
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NO_82598_A0_SUPPORT
end_ifndef

begin_function_decl
specifier|static
name|void
name|desc_flip
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*********************************************************************  *  FreeBSD Device Interface Entry Points  *********************************************************************/
end_comment

begin_decl_stmt
specifier|static
name|device_method_t
name|ixgbe_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ixgbe_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ixgbe_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|ixgbe_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|ixgbe_shutdown
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|ixgbe_driver
init|=
block|{
literal|"ix"
block|,
name|ixgbe_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|adapter
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|ixgbe_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ixgbe
argument_list|,
name|pci
argument_list|,
name|ixgbe_driver
argument_list|,
name|ixgbe_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ixgbe
argument_list|,
name|pci
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ixgbe
argument_list|,
name|ether
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ** TUNEABLE PARAMETERS: */
end_comment

begin_comment
comment|/* How many packets rxeof tries to clean at a time */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ixgbe_rx_process_limit
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.ixgbe.rx_process_limit"
argument_list|,
operator|&
name|ixgbe_rx_process_limit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Flow control setting, default to full */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ixgbe_flow_control
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.ixgbe.flow_control"
argument_list|,
operator|&
name|ixgbe_flow_control
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Number of TX Queues, note multi tx is not working */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ixgbe_tx_queues
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.ixgbe.tx_queues"
argument_list|,
operator|&
name|ixgbe_tx_queues
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Number of RX Queues, with 0 setting  * it autoconfigures to the number of cpus.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ixgbe_rx_queues
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.ixgbe.rx_queues"
argument_list|,
operator|&
name|ixgbe_rx_queues
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Number of Other Queues, this is used for link interrupts */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ixgbe_other_queues
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.ixgbe.other_queues"
argument_list|,
operator|&
name|ixgbe_other_queues
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Number of TX descriptors per ring */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ixgbe_txd
init|=
name|DEFAULT_TXD
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.ixgbe.txd"
argument_list|,
operator|&
name|ixgbe_txd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Number of RX descriptors per ring */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ixgbe_rxd
init|=
name|DEFAULT_RXD
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.ixgbe.rxd"
argument_list|,
operator|&
name|ixgbe_rxd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Total number of Interfaces - need for config sanity check */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ixgbe_total_ports
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*********************************************************************  *  Device identification routine  *  *  ixgbe_probe determines if the driver should be loaded on  *  adapter based on PCI vendor/device id of the adapter.  *  *  return 0 on success, positive on failure  *********************************************************************/
end_comment

begin_function
specifier|static
name|int
name|ixgbe_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|ixgbe_vendor_info_t
modifier|*
name|ent
decl_stmt|;
name|u_int16_t
name|pci_vendor_id
init|=
literal|0
decl_stmt|;
name|u_int16_t
name|pci_device_id
init|=
literal|0
decl_stmt|;
name|u_int16_t
name|pci_subvendor_id
init|=
literal|0
decl_stmt|;
name|u_int16_t
name|pci_subdevice_id
init|=
literal|0
decl_stmt|;
name|char
name|adapter_name
index|[
literal|60
index|]
decl_stmt|;
name|INIT_DEBUGOUT
argument_list|(
literal|"ixgbe_probe: begin"
argument_list|)
expr_stmt|;
name|pci_vendor_id
operator|=
name|pci_get_vendor
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|pci_vendor_id
operator|!=
name|IXGBE_INTEL_VENDOR_ID
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|pci_device_id
operator|=
name|pci_get_device
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|pci_subvendor_id
operator|=
name|pci_get_subvendor
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|pci_subdevice_id
operator|=
name|pci_get_subdevice
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|ent
operator|=
name|ixgbe_vendor_info_array
expr_stmt|;
while|while
condition|(
name|ent
operator|->
name|vendor_id
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|pci_vendor_id
operator|==
name|ent
operator|->
name|vendor_id
operator|)
operator|&&
operator|(
name|pci_device_id
operator|==
name|ent
operator|->
name|device_id
operator|)
operator|&&
operator|(
operator|(
name|pci_subvendor_id
operator|==
name|ent
operator|->
name|subvendor_id
operator|)
operator|||
operator|(
name|ent
operator|->
name|subvendor_id
operator|==
literal|0
operator|)
operator|)
operator|&&
operator|(
operator|(
name|pci_subdevice_id
operator|==
name|ent
operator|->
name|subdevice_id
operator|)
operator|||
operator|(
name|ent
operator|->
name|subdevice_id
operator|==
literal|0
operator|)
operator|)
condition|)
block|{
name|sprintf
argument_list|(
name|adapter_name
argument_list|,
literal|"%s, Version - %s"
argument_list|,
name|ixgbe_strings
index|[
name|ent
operator|->
name|index
index|]
argument_list|,
name|ixgbe_driver_version
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|pci_device_id
condition|)
block|{
case|case
name|IXGBE_DEV_ID_82598AF_DUAL_PORT
case|:
name|ixgbe_total_ports
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
name|IXGBE_DEV_ID_82598AF_SINGLE_PORT
case|:
name|ixgbe_total_ports
operator|+=
literal|1
expr_stmt|;
default|default:
break|break;
block|}
name|device_set_desc_copy
argument_list|(
name|dev
argument_list|,
name|adapter_name
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|ent
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_comment
comment|/*********************************************************************  *  Device initialization routine  *  *  The attach entry point is called when the driver is being loaded.  *  This routine identifies the type of hardware, allocates all resources  *  and initializes the hardware.  *  *  return 0 on success, positive on failure  *********************************************************************/
end_comment

begin_function
specifier|static
name|int
name|ixgbe_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|uint32_t
name|ctrl_ext
decl_stmt|;
name|char
name|name_string
index|[
literal|16
index|]
decl_stmt|;
name|INIT_DEBUGOUT
argument_list|(
literal|"ixgbe_attach: begin"
argument_list|)
expr_stmt|;
comment|/* Allocate, clear, and link in our adapter structure */
name|adapter
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|dev
operator|=
name|adapter
operator|->
name|osdep
operator|.
name|dev
operator|=
name|dev
expr_stmt|;
comment|/* General Lock Init*/
name|snprintf
argument_list|(
name|name_string
argument_list|,
sizeof|sizeof
argument_list|(
name|name_string
argument_list|)
argument_list|,
literal|"%s:core"
argument_list|,
name|device_get_nameunit
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
name|mtx_init
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|,
name|name_string
argument_list|,
name|NULL
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
comment|/* SYSCTL APIs */
name|SYSCTL_ADD_PROC
argument_list|(
name|device_get_sysctl_ctx
argument_list|(
name|dev
argument_list|)
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|device_get_sysctl_tree
argument_list|(
name|dev
argument_list|)
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"stats"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
name|adapter
argument_list|,
literal|0
argument_list|,
name|ixgbe_sysctl_stats
argument_list|,
literal|"I"
argument_list|,
literal|"Statistics"
argument_list|)
expr_stmt|;
name|SYSCTL_ADD_PROC
argument_list|(
name|device_get_sysctl_ctx
argument_list|(
name|dev
argument_list|)
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|device_get_sysctl_tree
argument_list|(
name|dev
argument_list|)
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"debug"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
name|adapter
argument_list|,
literal|0
argument_list|,
name|ixgbe_sysctl_debug
argument_list|,
literal|"I"
argument_list|,
literal|"Debug Info"
argument_list|)
expr_stmt|;
name|SYSCTL_ADD_PROC
argument_list|(
name|device_get_sysctl_ctx
argument_list|(
name|dev
argument_list|)
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|device_get_sysctl_tree
argument_list|(
name|dev
argument_list|)
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"flow_control"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
name|adapter
argument_list|,
literal|0
argument_list|,
name|ixgbe_set_flowcntl
argument_list|,
literal|"I"
argument_list|,
literal|"Flow Control"
argument_list|)
expr_stmt|;
comment|/* Set up the timer callout */
name|callout_init_mtx
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|,
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Determine hardware revision */
name|ixgbe_identify_hardware
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* Indicate to RX setup to use Jumbo Clusters */
name|adapter
operator|->
name|bigbufs
operator|=
name|TRUE
expr_stmt|;
comment|/* Do base PCI setup - map BAR0 */
if|if
condition|(
name|ixgbe_allocate_pci_resources
argument_list|(
name|adapter
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Allocation of PCI resources failed\n"
argument_list|)
expr_stmt|;
name|error
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|err_out
goto|;
block|}
comment|/* Do descriptor calc and sanity checks */
if|if
condition|(
operator|(
operator|(
name|ixgbe_txd
operator|*
sizeof|sizeof
argument_list|(
expr|union
name|ixgbe_adv_tx_desc
argument_list|)
operator|)
operator|%
name|DBA_ALIGN
operator|)
operator|!=
literal|0
operator|||
name|ixgbe_txd
operator|<
name|MIN_TXD
operator|||
name|ixgbe_txd
operator|>
name|MAX_TXD
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"TXD config issue, using default!\n"
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|num_tx_desc
operator|=
name|DEFAULT_TXD
expr_stmt|;
block|}
else|else
name|adapter
operator|->
name|num_tx_desc
operator|=
name|ixgbe_txd
expr_stmt|;
comment|/* 	** With many RX rings it is easy to exceed the 	** system mbuf allocation. Tuning nmbclusters 	** can alleviate this. 	*/
if|if
condition|(
operator|(
name|adapter
operator|->
name|num_rx_queues
operator|>
literal|1
operator|)
operator|&&
operator|(
name|nmbclusters
operator|>
literal|0
operator|)
condition|)
block|{
name|int
name|s
decl_stmt|;
comment|/* Calculate the total RX mbuf needs */
name|s
operator|=
operator|(
name|ixgbe_rxd
operator|*
name|adapter
operator|->
name|num_rx_queues
operator|)
operator|*
name|ixgbe_total_ports
expr_stmt|;
if|if
condition|(
name|s
operator|>
name|nmbclusters
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"RX Descriptors exceed "
literal|"system mbuf max, using default instead!\n"
argument_list|)
expr_stmt|;
name|ixgbe_rxd
operator|=
name|DEFAULT_RXD
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
operator|(
name|ixgbe_rxd
operator|*
sizeof|sizeof
argument_list|(
expr|union
name|ixgbe_adv_rx_desc
argument_list|)
operator|)
operator|%
name|DBA_ALIGN
operator|)
operator|!=
literal|0
operator|||
name|ixgbe_rxd
operator|<
name|MIN_TXD
operator|||
name|ixgbe_rxd
operator|>
name|MAX_TXD
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"RXD config issue, using default!\n"
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|num_rx_desc
operator|=
name|DEFAULT_RXD
expr_stmt|;
block|}
else|else
name|adapter
operator|->
name|num_rx_desc
operator|=
name|ixgbe_rxd
expr_stmt|;
comment|/* Allocate our TX/RX Queues */
if|if
condition|(
name|ixgbe_allocate_queues
argument_list|(
name|adapter
argument_list|)
condition|)
block|{
name|error
operator|=
name|ENOMEM
expr_stmt|;
goto|goto
name|err_out
goto|;
block|}
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
if|if
condition|(
name|adapter
operator|->
name|msix
condition|)
block|{
name|error
operator|=
name|ixgbe_setup_msix
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|err_out
goto|;
block|}
endif|#
directive|endif
comment|/* Initialize the shared code */
if|if
condition|(
name|ixgbe_init_shared_code
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to initialize the shared code\n"
argument_list|)
expr_stmt|;
name|error
operator|=
name|EIO
expr_stmt|;
goto|goto
name|err_out
goto|;
block|}
comment|/* Initialize the hardware */
if|if
condition|(
name|ixgbe_hardware_init
argument_list|(
name|adapter
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to initialize the hardware\n"
argument_list|)
expr_stmt|;
name|error
operator|=
name|EIO
expr_stmt|;
goto|goto
name|err_out
goto|;
block|}
comment|/* Setup OS specific network interface */
name|ixgbe_setup_interface
argument_list|(
name|dev
argument_list|,
name|adapter
argument_list|)
expr_stmt|;
comment|/* Sysctl for limiting the amount of work done in the taskqueue */
name|ixgbe_add_rx_process_limit
argument_list|(
name|adapter
argument_list|,
literal|"rx_processing_limit"
argument_list|,
literal|"max number of rx packets to process"
argument_list|,
operator|&
name|adapter
operator|->
name|rx_process_limit
argument_list|,
name|ixgbe_rx_process_limit
argument_list|)
expr_stmt|;
comment|/* Initialize statistics */
name|ixgbe_update_stats_counters
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* let hardware know driver is loaded */
name|ctrl_ext
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_CTRL_EXT
argument_list|)
expr_stmt|;
name|ctrl_ext
operator||=
name|IXGBE_CTRL_EXT_DRV_LOAD
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_CTRL_EXT
argument_list|,
name|ctrl_ext
argument_list|)
expr_stmt|;
name|INIT_DEBUGOUT
argument_list|(
literal|"ixgbe_attach: end"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
name|err_out
label|:
name|ixgbe_free_pci_resources
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/*********************************************************************  *  Device removal routine  *  *  The detach entry point is called when the driver is being removed.  *  This routine stops the adapter and deallocates all the resources  *  that were allocated for driver operation.  *  *  return 0 on success, positive on failure  *********************************************************************/
end_comment

begin_function
specifier|static
name|int
name|ixgbe_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|u32
name|ctrl_ext
decl_stmt|;
name|INIT_DEBUGOUT
argument_list|(
literal|"ixgbe_detach: begin"
argument_list|)
expr_stmt|;
comment|/* Make sure VLANS are not using driver */
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
if|if
condition|(
name|adapter
operator|->
name|ifp
operator|->
name|if_vlantrunk
operator|!=
name|NULL
condition|)
block|{
else|#
directive|else
if|if
condition|(
name|adapter
operator|->
name|ifp
operator|->
name|if_nvlans
operator|!=
literal|0
condition|)
block|{
endif|#
directive|endif
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Vlan in use, detach first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EBUSY
operator|)
return|;
block|}
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
name|ixgbe_stop
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
if|if
condition|(
name|adapter
operator|->
name|tq
operator|!=
name|NULL
condition|)
block|{
name|taskqueue_drain
argument_list|(
name|adapter
operator|->
name|tq
argument_list|,
operator|&
name|adapter
operator|->
name|rxtx_task
argument_list|)
expr_stmt|;
name|taskqueue_drain
argument_list|(
name|taskqueue_fast
argument_list|,
operator|&
name|adapter
operator|->
name|link_task
argument_list|)
expr_stmt|;
name|taskqueue_free
argument_list|(
name|adapter
operator|->
name|tq
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|tq
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* let hardware know driver is unloading */
name|ctrl_ext
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_CTRL_EXT
argument_list|)
expr_stmt|;
name|ctrl_ext
operator|&=
operator|~
name|IXGBE_CTRL_EXT_DRV_LOAD
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_CTRL_EXT
argument_list|,
name|ctrl_ext
argument_list|)
expr_stmt|;
name|ether_ifdetach
argument_list|(
name|adapter
operator|->
name|ifp
argument_list|)
expr_stmt|;
name|callout_drain
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|)
expr_stmt|;
name|ixgbe_free_pci_resources
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|bus_generic_detach
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|if_free
argument_list|(
name|adapter
operator|->
name|ifp
argument_list|)
expr_stmt|;
name|ixgbe_free_transmit_structures
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|ixgbe_free_receive_structures
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_destroy
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/*********************************************************************  *  *  Shutdown entry point  *  **********************************************************************/
specifier|static
name|int
name|ixgbe_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
name|ixgbe_stop
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/*********************************************************************  *  Transmit entry point  *  *  ixgbe_start is called by the stack to initiate a transmit.  *  The driver will remain in this routine as long as there are  *  packets to transmit and transmit resources are available.  *  In case resources are not available stack is notified and  *  the packet is requeued.  **********************************************************************/
specifier|static
name|void
name|ixgbe_start_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|ifp
operator|->
name|if_softc
decl_stmt|;
name|mtx_assert
argument_list|(
operator|&
name|adapter
operator|->
name|tx_mtx
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ifp
operator|->
name|if_drv_flags
operator|&
operator|(
name|IFF_DRV_RUNNING
operator||
name|IFF_DRV_OACTIVE
operator|)
operator|)
operator|!=
name|IFF_DRV_RUNNING
condition|)
return|return;
if|if
condition|(
operator|!
name|adapter
operator|->
name|link_active
condition|)
return|return;
while|while
condition|(
operator|!
name|IFQ_DRV_IS_EMPTY
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
name|IFQ_DRV_DEQUEUE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m_head
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_head
operator|==
name|NULL
condition|)
break|break;
if|if
condition|(
name|ixgbe_encap
argument_list|(
name|adapter
argument_list|,
operator|&
name|m_head
argument_list|)
condition|)
block|{
if|if
condition|(
name|m_head
operator|==
name|NULL
condition|)
break|break;
name|ifp
operator|->
name|if_drv_flags
operator||=
name|IFF_DRV_OACTIVE
expr_stmt|;
name|IFQ_DRV_PREPEND
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m_head
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* Send a copy of the frame to the BPF listener */
name|ETHER_BPF_MTAP
argument_list|(
name|ifp
argument_list|,
name|m_head
argument_list|)
expr_stmt|;
comment|/* Set timeout in case hardware has problems transmitting */
name|adapter
operator|->
name|watchdog_timer
operator|=
name|IXGBE_TX_TIMEOUT
expr_stmt|;
block|}
return|return;
block|}
specifier|static
name|void
name|ixgbe_start
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|ifp
operator|->
name|if_softc
decl_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|tx_mtx
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
condition|)
name|ixgbe_start_locked
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|tx_mtx
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/*********************************************************************  *  Ioctl entry point  *  *  ixgbe_ioctl is called when the user wants to configure the  *  interface.  *  *  return 0 on success, positive on failure  **********************************************************************/
specifier|static
name|int
name|ixgbe_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|command
parameter_list|,
name|caddr_t
name|data
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|struct
name|ifreq
modifier|*
name|ifr
init|=
operator|(
expr|struct
name|ifreq
operator|*
operator|)
name|data
decl_stmt|;
name|struct
name|ifaddr
modifier|*
name|ifa
init|=
operator|(
expr|struct
name|ifaddr
operator|*
operator|)
name|data
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|ifp
operator|->
name|if_softc
decl_stmt|;
switch|switch
condition|(
name|command
condition|)
block|{
case|case
name|SIOCSIFADDR
case|:
name|IOCTL_DEBUGOUT
argument_list|(
literal|"ioctl: SIOCxIFADDR (Get/Set Interface Addr)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifa
operator|->
name|ifa_addr
operator|->
name|sa_family
operator|==
name|AF_INET
condition|)
block|{
name|ifp
operator|->
name|if_flags
operator||=
name|IFF_UP
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
operator|)
condition|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
name|ixgbe_init_locked
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
block|}
name|arp_ifinit
argument_list|(
name|ifp
argument_list|,
name|ifa
argument_list|)
expr_stmt|;
block|}
else|else
name|ether_ioctl
argument_list|(
name|ifp
argument_list|,
name|command
argument_list|,
name|data
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCSIFMTU
case|:
name|IOCTL_DEBUGOUT
argument_list|(
literal|"ioctl: SIOCSIFMTU (Set Interface MTU)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifr
operator|->
name|ifr_mtu
operator|>
name|IXGBE_MAX_FRAME_SIZE
operator|-
name|ETHER_HDR_LEN
condition|)
block|{
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
else|else
block|{
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
name|ifp
operator|->
name|if_mtu
operator|=
name|ifr
operator|->
name|ifr_mtu
expr_stmt|;
name|adapter
operator|->
name|max_frame_size
operator|=
name|ifp
operator|->
name|if_mtu
operator|+
name|ETHER_HDR_LEN
operator|+
name|ETHER_CRC_LEN
expr_stmt|;
name|ixgbe_init_locked
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|SIOCSIFFLAGS
case|:
name|IOCTL_DEBUGOUT
argument_list|(
literal|"ioctl: SIOCSIFFLAGS (Set Interface Flags)"
argument_list|)
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_UP
condition|)
block|{
if|if
condition|(
operator|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|ifp
operator|->
name|if_flags
operator|^
name|adapter
operator|->
name|if_flags
operator|)
operator|&
name|IFF_PROMISC
condition|)
block|{
name|ixgbe_disable_promisc
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|ixgbe_set_promisc
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|ixgbe_init_locked
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
condition|)
name|ixgbe_stop
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|if_flags
operator|=
name|ifp
operator|->
name|if_flags
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCADDMULTI
case|:
case|case
name|SIOCDELMULTI
case|:
name|IOCTL_DEBUGOUT
argument_list|(
literal|"ioctl: SIOC(ADD|DEL)MULTI"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
condition|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
name|ixgbe_disable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|ixgbe_set_multi
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|ixgbe_enable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|SIOCSIFMEDIA
case|:
case|case
name|SIOCGIFMEDIA
case|:
name|IOCTL_DEBUGOUT
argument_list|(
literal|"ioctl: SIOCxIFMEDIA (Get/Set Interface Media)"
argument_list|)
expr_stmt|;
name|error
operator|=
name|ifmedia_ioctl
argument_list|(
name|ifp
argument_list|,
name|ifr
argument_list|,
operator|&
name|adapter
operator|->
name|media
argument_list|,
name|command
argument_list|)
expr_stmt|;
break|break;
case|case
name|SIOCSIFCAP
case|:
block|{
name|int
name|mask
init|=
name|ifr
operator|->
name|ifr_reqcap
operator|^
name|ifp
operator|->
name|if_capenable
decl_stmt|;
name|IOCTL_DEBUGOUT
argument_list|(
literal|"ioctl: SIOCSIFCAP (Set Capabilities)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mask
operator|&
name|IFCAP_HWCSUM
condition|)
name|ifp
operator|->
name|if_capenable
operator|^=
name|IFCAP_HWCSUM
expr_stmt|;
if|if
condition|(
name|mask
operator|&
name|IFCAP_TSO4
condition|)
name|ifp
operator|->
name|if_capenable
operator|^=
name|IFCAP_TSO4
expr_stmt|;
if|if
condition|(
name|mask
operator|&
name|IFCAP_VLAN_HWTAGGING
condition|)
name|ifp
operator|->
name|if_capenable
operator|^=
name|IFCAP_VLAN_HWTAGGING
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
condition|)
name|ixgbe_init
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
name|VLAN_CAPABILITIES
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
default|default:
name|IOCTL_DEBUGOUT1
argument_list|(
literal|"ioctl: UNKNOWN (0x%X)\n"
argument_list|,
operator|(
name|int
operator|)
name|command
argument_list|)
expr_stmt|;
name|error
operator|=
name|ether_ioctl
argument_list|(
name|ifp
argument_list|,
name|command
argument_list|,
name|data
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
comment|/*********************************************************************  *  Watchdog entry point  *  *  This routine is called whenever hardware quits transmitting.  *  **********************************************************************/
specifier|static
name|void
name|ixgbe_watchdog
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|device_t
name|dev
init|=
name|adapter
operator|->
name|dev
decl_stmt|;
name|struct
name|tx_ring
modifier|*
name|txr
init|=
name|adapter
operator|->
name|tx_rings
decl_stmt|;
name|struct
name|ixgbe_hw
modifier|*
name|hw
init|=
operator|&
name|adapter
operator|->
name|hw
decl_stmt|;
name|mtx_assert
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
comment|/*          * The timer is set to 5 every time ixgbe_start() queues a packet.          * Then ixgbe_txeof() keeps resetting to 5 as long as it cleans at          * least one descriptor.          * Finally, anytime all descriptors are clean the timer is          * set to 0.          */
if|if
condition|(
name|adapter
operator|->
name|watchdog_timer
operator|==
literal|0
operator|||
operator|--
name|adapter
operator|->
name|watchdog_timer
condition|)
return|return;
comment|/* 	 * If we are in this routine because of pause frames, then don't 	 * reset the hardware. 	 */
if|if
condition|(
name|IXGBE_READ_REG
argument_list|(
name|hw
argument_list|,
name|IXGBE_TFCS
argument_list|)
operator|&
name|IXGBE_TFCS_TXOFF
condition|)
block|{
name|adapter
operator|->
name|watchdog_timer
operator|=
name|IXGBE_TX_TIMEOUT
expr_stmt|;
return|return;
block|}
name|device_printf
argument_list|(
name|adapter
operator|->
name|dev
argument_list|,
literal|"Watchdog timeout -- resetting\n"
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Queue(0) tdh = %d, hw tdt = %d\n"
argument_list|,
name|IXGBE_READ_REG
argument_list|(
name|hw
argument_list|,
name|IXGBE_TDH
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|,
name|IXGBE_READ_REG
argument_list|(
name|hw
argument_list|,
name|IXGBE_TDT
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"TX desc avail = %d, Next TX to Clean = %d\n"
argument_list|,
name|txr
operator|->
name|tx_avail
argument_list|,
name|txr
operator|->
name|next_tx_to_clean
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|ifp
operator|->
name|if_drv_flags
operator|&=
operator|~
name|IFF_DRV_RUNNING
expr_stmt|;
name|adapter
operator|->
name|watchdog_events
operator|++
expr_stmt|;
name|ixgbe_init_locked
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
block|}
comment|/*********************************************************************  *  Init entry point  *  *  This routine is used in two ways. It is used by the stack as  *  init entry point in network interface structure. It is also used  *  by the driver as a hw/sw initialization routine to get to a  *  consistent state.  *  *  return 0 on success, positive on failure  **********************************************************************/
define|#
directive|define
name|IXGBE_MHADD_MFS_SHIFT
value|16
specifier|static
name|void
name|ixgbe_init_locked
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
name|device_t
name|dev
init|=
name|adapter
operator|->
name|dev
decl_stmt|;
name|u32
name|txdctl
decl_stmt|,
name|rxdctl
decl_stmt|,
name|mhadd
decl_stmt|;
name|INIT_DEBUGOUT
argument_list|(
literal|"ixgbe_init: begin"
argument_list|)
expr_stmt|;
name|mtx_assert
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
name|ixgbe_stop
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* Get the latest mac address, User can use a LAA */
name|bcopy
argument_list|(
name|IF_LLADDR
argument_list|(
name|adapter
operator|->
name|ifp
argument_list|)
argument_list|,
name|adapter
operator|->
name|hw
operator|.
name|mac
operator|.
name|addr
argument_list|,
name|IXGBE_ETH_LENGTH_OF_ADDRESS
argument_list|)
expr_stmt|;
name|ixgbe_set_rar
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
literal|0
argument_list|,
name|adapter
operator|->
name|hw
operator|.
name|mac
operator|.
name|addr
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|hw
operator|.
name|addr_ctrl
operator|.
name|rar_used_count
operator|=
literal|1
expr_stmt|;
comment|/* Initialize the hardware */
if|if
condition|(
name|ixgbe_hardware_init
argument_list|(
name|adapter
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to initialize the hardware\n"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|ifp
operator|->
name|if_capenable
operator|&
name|IFCAP_VLAN_HWTAGGING
condition|)
name|ixgbe_enable_hw_vlans
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* Prepare transmit descriptors and buffers */
if|if
condition|(
name|ixgbe_setup_transmit_structures
argument_list|(
name|adapter
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Could not setup transmit structures\n"
argument_list|)
expr_stmt|;
name|ixgbe_stop
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
return|return;
block|}
name|ixgbe_initialize_transmit_units
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* Setup Multicast table */
name|ixgbe_set_multi
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* 	** If we are resetting MTU smaller than 2K 	** drop to small RX buffers 	*/
if|if
condition|(
name|adapter
operator|->
name|max_frame_size
operator|<=
name|MCLBYTES
condition|)
name|adapter
operator|->
name|bigbufs
operator|=
name|FALSE
expr_stmt|;
comment|/* Prepare receive descriptors and buffers */
if|if
condition|(
name|ixgbe_setup_receive_structures
argument_list|(
name|adapter
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Could not setup receive structures\n"
argument_list|)
expr_stmt|;
name|ixgbe_stop
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* Configure RX settings */
name|ixgbe_initialize_receive_units
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* Enable Enhanced MSIX mode */
if|if
condition|(
name|adapter
operator|->
name|msix
condition|)
block|{
name|u32
name|gpie
decl_stmt|;
name|gpie
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_GPIE
argument_list|)
expr_stmt|;
name|gpie
operator||=
name|IXGBE_GPIE_MSIX_MODE
expr_stmt|;
name|gpie
operator||=
name|IXGBE_GPIE_EIAME
operator||
name|IXGBE_GPIE_PBA_SUPPORT
operator||
name|IXGBE_GPIE_OCD
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_GPIE
argument_list|,
name|gpie
argument_list|)
expr_stmt|;
name|gpie
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_GPIE
argument_list|)
expr_stmt|;
block|}
comment|/* Set the various hardware offload abilities */
name|ifp
operator|->
name|if_hwassist
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_capenable
operator|&
name|IFCAP_TSO4
condition|)
name|ifp
operator|->
name|if_hwassist
operator||=
name|CSUM_TSO
expr_stmt|;
elseif|else
if|if
condition|(
name|ifp
operator|->
name|if_capenable
operator|&
name|IFCAP_TXCSUM
condition|)
name|ifp
operator|->
name|if_hwassist
operator|=
operator|(
name|CSUM_TCP
operator||
name|CSUM_UDP
operator|)
expr_stmt|;
comment|/* Set MTU size */
if|if
condition|(
name|ifp
operator|->
name|if_mtu
operator|>
name|ETHERMTU
condition|)
block|{
name|mhadd
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_MHADD
argument_list|)
expr_stmt|;
name|mhadd
operator|&=
operator|~
name|IXGBE_MHADD_MFS_MASK
expr_stmt|;
name|mhadd
operator||=
name|adapter
operator|->
name|max_frame_size
operator|<<
name|IXGBE_MHADD_MFS_SHIFT
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_MHADD
argument_list|,
name|mhadd
argument_list|)
expr_stmt|;
block|}
comment|/* Now enable all the queues */
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|adapter
operator|->
name|num_tx_queues
condition|;
name|i
operator|++
control|)
block|{
name|txdctl
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_TXDCTL
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|txdctl
operator||=
name|IXGBE_TXDCTL_ENABLE
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_TXDCTL
argument_list|(
name|i
argument_list|)
argument_list|,
name|txdctl
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|adapter
operator|->
name|num_rx_queues
condition|;
name|i
operator|++
control|)
block|{
name|rxdctl
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_RXDCTL
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|rxdctl
operator||=
name|IXGBE_RXDCTL_ENABLE
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_RXDCTL
argument_list|(
name|i
argument_list|)
argument_list|,
name|rxdctl
argument_list|)
expr_stmt|;
block|}
name|callout_reset
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|,
name|hz
argument_list|,
name|ixgbe_local_timer
argument_list|,
name|adapter
argument_list|)
expr_stmt|;
comment|/* Set up MSI/X routing */
name|ixgbe_configure_ivars
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|ixgbe_enable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* Now inform the stack we're ready */
name|ifp
operator|->
name|if_drv_flags
operator||=
name|IFF_DRV_RUNNING
expr_stmt|;
name|ifp
operator|->
name|if_drv_flags
operator|&=
operator|~
name|IFF_DRV_OACTIVE
expr_stmt|;
return|return;
block|}
specifier|static
name|void
name|ixgbe_init
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|arg
decl_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
name|ixgbe_init_locked
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|static
name|void
name|ixgbe_link
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|context
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
operator|)
condition|)
block|{
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
return|return;
block|}
name|callout_stop
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|)
expr_stmt|;
name|ixgbe_update_link_status
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|callout_reset
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|,
name|hz
argument_list|,
name|ixgbe_local_timer
argument_list|,
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
block|}
comment|/* ** MSI and Legacy Deferred Handler **	- note this runs without the general lock */
specifier|static
name|void
name|ixgbe_rxtx
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|context
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
comment|/* For legacy there is only one of each */
name|struct
name|rx_ring
modifier|*
name|rxr
init|=
name|adapter
operator|->
name|rx_rings
decl_stmt|;
name|struct
name|tx_ring
modifier|*
name|txr
init|=
name|adapter
operator|->
name|tx_rings
decl_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
condition|)
block|{
if|if
condition|(
name|ixgbe_rxeof
argument_list|(
name|rxr
argument_list|,
name|adapter
operator|->
name|rx_process_limit
argument_list|)
operator|!=
literal|0
condition|)
name|taskqueue_enqueue
argument_list|(
name|adapter
operator|->
name|tq
argument_list|,
operator|&
name|adapter
operator|->
name|rxtx_task
argument_list|)
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|tx_mtx
argument_list|)
expr_stmt|;
name|ixgbe_txeof
argument_list|(
name|txr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|IFQ_DRV_IS_EMPTY
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
name|ixgbe_start_locked
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|tx_mtx
argument_list|)
expr_stmt|;
block|}
name|ixgbe_enable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
block|}
comment|/*********************************************************************  *  *  Legacy Interrupt Service routine  *  **********************************************************************/
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
specifier|static
name|int
else|#
directive|else
specifier|static
name|void
endif|#
directive|endif
name|ixgbe_fast_irq
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|u32
name|reg_eicr
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|arg
decl_stmt|;
name|reg_eicr
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_EICR
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg_eicr
operator|==
literal|0
condition|)
return|return
name|FILTER_STRAY
return|;
name|ixgbe_disable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|taskqueue_enqueue
argument_list|(
name|adapter
operator|->
name|tq
argument_list|,
operator|&
name|adapter
operator|->
name|rxtx_task
argument_list|)
expr_stmt|;
comment|/* Link status change */
if|if
condition|(
name|reg_eicr
operator|&
name|IXGBE_EICR_LSC
condition|)
name|taskqueue_enqueue
argument_list|(
name|taskqueue_fast
argument_list|,
operator|&
name|adapter
operator|->
name|link_task
argument_list|)
expr_stmt|;
return|return
name|FILTER_HANDLED
return|;
block|}
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
comment|/*********************************************************************  *  *  MSI TX Interrupt Service routine  *  **********************************************************************/
name|void
name|ixgbe_msix_tx
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|tx_ring
modifier|*
name|txr
init|=
name|arg
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|txr
operator|->
name|adapter
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
name|uint32_t
name|loop_cnt
init|=
name|MAX_INTR
decl_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|tx_mtx
argument_list|)
expr_stmt|;
operator|++
name|txr
operator|->
name|tx_irq
expr_stmt|;
while|while
condition|(
name|loop_cnt
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|__predict_false
argument_list|(
operator|!
name|ixgbe_txeof
argument_list|(
name|txr
argument_list|)
argument_list|)
condition|)
break|break;
name|loop_cnt
operator|--
expr_stmt|;
block|}
if|if
condition|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
operator|&&
name|ifp
operator|->
name|if_snd
operator|.
name|ifq_head
operator|!=
name|NULL
condition|)
name|ixgbe_start_locked
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|ixgbe_enable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|tx_mtx
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/*********************************************************************  *  *  MSI RX Interrupt Service routine  *  **********************************************************************/
specifier|static
name|void
name|ixgbe_msix_rx
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|rx_ring
modifier|*
name|rxr
init|=
name|arg
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|rxr
operator|->
name|adapter
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
name|uint32_t
name|loop
init|=
name|MAX_INTR
decl_stmt|;
operator|++
name|rxr
operator|->
name|rx_irq
expr_stmt|;
while|while
condition|(
operator|(
name|loop
operator|--
operator|>
literal|0
operator|)
operator|&&
operator|(
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
operator|)
condition|)
name|ixgbe_rxeof
argument_list|(
name|rxr
argument_list|,
name|adapter
operator|->
name|rx_process_limit
argument_list|)
expr_stmt|;
name|ixgbe_enable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|ixgbe_msix_link
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|arg
decl_stmt|;
name|uint32_t
name|reg_eicr
decl_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
operator|++
name|adapter
operator|->
name|link_irq
expr_stmt|;
name|reg_eicr
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_EICR
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg_eicr
operator|&
name|IXGBE_EICR_LSC
condition|)
block|{
name|callout_stop
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|)
expr_stmt|;
name|ixgbe_update_link_status
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|callout_reset
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|,
name|hz
argument_list|,
name|ixgbe_local_timer
argument_list|,
name|adapter
argument_list|)
expr_stmt|;
block|}
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_EIMS
argument_list|,
name|IXGBE_EIMS_OTHER
argument_list|)
expr_stmt|;
name|ixgbe_enable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/*  __FreeBSD_version>= 700000 */
comment|/*********************************************************************  *  *  Media Ioctl callback  *  *  This routine is called whenever the user queries the status of  *  the interface using ifconfig.  *  **********************************************************************/
specifier|static
name|void
name|ixgbe_media_status
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|ifmediareq
modifier|*
name|ifmr
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|ifp
operator|->
name|if_softc
decl_stmt|;
name|INIT_DEBUGOUT
argument_list|(
literal|"ixgbe_media_status: begin"
argument_list|)
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
name|ixgbe_update_link_status
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|ifmr
operator|->
name|ifm_status
operator|=
name|IFM_AVALID
expr_stmt|;
name|ifmr
operator|->
name|ifm_active
operator|=
name|IFM_ETHER
expr_stmt|;
if|if
condition|(
operator|!
name|adapter
operator|->
name|link_active
condition|)
block|{
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
return|return;
block|}
name|ifmr
operator|->
name|ifm_status
operator||=
name|IFM_ACTIVE
expr_stmt|;
switch|switch
condition|(
name|adapter
operator|->
name|link_speed
condition|)
block|{
case|case
name|IXGBE_LINK_SPEED_1GB_FULL
case|:
name|ifmr
operator|->
name|ifm_active
operator||=
name|IFM_1000_T
operator||
name|IFM_FDX
expr_stmt|;
break|break;
case|case
name|IXGBE_LINK_SPEED_10GB_FULL
case|:
name|ifmr
operator|->
name|ifm_active
operator||=
name|IFM_10G_SR
operator||
name|IFM_FDX
expr_stmt|;
break|break;
block|}
name|mtx_unlock
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/*********************************************************************  *  *  Media Ioctl callback  *  *  This routine is called when the user changes speed/duplex using  *  media/mediopt option with ifconfig.  *  **********************************************************************/
specifier|static
name|int
name|ixgbe_media_change
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|ifp
operator|->
name|if_softc
decl_stmt|;
name|struct
name|ifmedia
modifier|*
name|ifm
init|=
operator|&
name|adapter
operator|->
name|media
decl_stmt|;
name|INIT_DEBUGOUT
argument_list|(
literal|"ixgbe_media_change: begin"
argument_list|)
expr_stmt|;
if|if
condition|(
name|IFM_TYPE
argument_list|(
name|ifm
operator|->
name|ifm_media
argument_list|)
operator|!=
name|IFM_ETHER
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
switch|switch
condition|(
name|IFM_SUBTYPE
argument_list|(
name|ifm
operator|->
name|ifm_media
argument_list|)
condition|)
block|{
case|case
name|IFM_AUTO
case|:
name|adapter
operator|->
name|hw
operator|.
name|mac
operator|.
name|autoneg
operator|=
name|TRUE
expr_stmt|;
name|adapter
operator|->
name|hw
operator|.
name|phy
operator|.
name|autoneg_advertised
operator|=
name|IXGBE_LINK_SPEED_1GB_FULL
operator||
name|IXGBE_LINK_SPEED_10GB_FULL
expr_stmt|;
break|break;
default|default:
name|device_printf
argument_list|(
name|adapter
operator|->
name|dev
argument_list|,
literal|"Only auto media type\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/*********************************************************************  *  *  This routine maps the mbufs to tx descriptors.  *    WARNING: while this code is using an MQ style infrastructure,  *    it would NOT work as is with more than 1 queue.  *  *  return 0 on success, positive on failure  **********************************************************************/
specifier|static
name|int
name|ixgbe_encap
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|m_headp
parameter_list|)
block|{
name|u32
name|olinfo_status
init|=
literal|0
decl_stmt|,
name|cmd_type_len
init|=
literal|0
decl_stmt|;
name|u32
name|paylen
decl_stmt|;
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|error
decl_stmt|,
name|nsegs
decl_stmt|;
name|int
name|first
decl_stmt|,
name|last
init|=
literal|0
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|bus_dma_segment_t
name|segs
index|[
name|IXGBE_MAX_SCATTER
index|]
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|struct
name|tx_ring
modifier|*
name|txr
init|=
name|adapter
operator|->
name|tx_rings
decl_stmt|;
name|struct
name|ixgbe_tx_buf
modifier|*
name|txbuf
decl_stmt|,
modifier|*
name|txbuf_mapped
decl_stmt|;
name|union
name|ixgbe_adv_tx_desc
modifier|*
name|txd
init|=
name|NULL
decl_stmt|;
name|m_head
operator|=
operator|*
name|m_headp
expr_stmt|;
name|paylen
operator|=
literal|0
expr_stmt|;
comment|/* Basic descriptor defines */
name|cmd_type_len
operator||=
name|IXGBE_ADVTXD_DTYP_DATA
expr_stmt|;
name|cmd_type_len
operator||=
name|IXGBE_ADVTXD_DCMD_IFCS
operator||
name|IXGBE_ADVTXD_DCMD_DEXT
expr_stmt|;
if|if
condition|(
name|m_head
operator|->
name|m_flags
operator|&
name|M_VLANTAG
condition|)
name|cmd_type_len
operator||=
name|IXGBE_ADVTXD_DCMD_VLE
expr_stmt|;
comment|/* 	 * Force a cleanup if number of TX descriptors 	 * available is below the threshold. If it fails 	 * to get above, then abort transmit. 	 */
if|if
condition|(
name|txr
operator|->
name|tx_avail
operator|<=
name|IXGBE_TX_CLEANUP_THRESHOLD
condition|)
block|{
name|ixgbe_txeof
argument_list|(
name|txr
argument_list|)
expr_stmt|;
comment|/* Make sure things have improved */
if|if
condition|(
name|txr
operator|->
name|tx_avail
operator|<=
name|IXGBE_TX_OP_THRESHOLD
condition|)
block|{
name|adapter
operator|->
name|no_tx_desc_avail1
operator|++
expr_stmt|;
return|return
operator|(
name|ENOBUFS
operator|)
return|;
block|}
block|}
comment|/*          * Important to capture the first descriptor          * used because it will contain the index of          * the one we tell the hardware to report back          */
name|first
operator|=
name|txr
operator|->
name|next_avail_tx_desc
expr_stmt|;
name|txbuf
operator|=
operator|&
name|txr
operator|->
name|tx_buffers
index|[
name|first
index|]
expr_stmt|;
name|txbuf_mapped
operator|=
name|txbuf
expr_stmt|;
name|map
operator|=
name|txbuf
operator|->
name|map
expr_stmt|;
comment|/* 	 * Map the packet for DMA. 	 */
name|error
operator|=
name|bus_dmamap_load_mbuf_sg
argument_list|(
name|txr
operator|->
name|txtag
argument_list|,
name|map
argument_list|,
operator|*
name|m_headp
argument_list|,
name|segs
argument_list|,
operator|&
name|nsegs
argument_list|,
name|BUS_DMA_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
name|EFBIG
condition|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|m
operator|=
name|m_defrag
argument_list|(
operator|*
name|m_headp
argument_list|,
name|M_DONTWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
block|{
name|adapter
operator|->
name|mbuf_alloc_failed
operator|++
expr_stmt|;
name|m_freem
argument_list|(
operator|*
name|m_headp
argument_list|)
expr_stmt|;
operator|*
name|m_headp
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|ENOBUFS
operator|)
return|;
block|}
operator|*
name|m_headp
operator|=
name|m
expr_stmt|;
comment|/* Try it again */
name|error
operator|=
name|bus_dmamap_load_mbuf_sg
argument_list|(
name|txr
operator|->
name|txtag
argument_list|,
name|map
argument_list|,
operator|*
name|m_headp
argument_list|,
name|segs
argument_list|,
operator|&
name|nsegs
argument_list|,
name|BUS_DMA_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
name|ENOMEM
condition|)
block|{
name|adapter
operator|->
name|no_tx_dma_setup
operator|++
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
name|adapter
operator|->
name|no_tx_dma_setup
operator|++
expr_stmt|;
name|m_freem
argument_list|(
operator|*
name|m_headp
argument_list|)
expr_stmt|;
operator|*
name|m_headp
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|error
operator|==
name|ENOMEM
condition|)
block|{
name|adapter
operator|->
name|no_tx_dma_setup
operator|++
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
name|adapter
operator|->
name|no_tx_dma_setup
operator|++
expr_stmt|;
name|m_freem
argument_list|(
operator|*
name|m_headp
argument_list|)
expr_stmt|;
operator|*
name|m_headp
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
comment|/* Make certain there are enough descriptors */
if|if
condition|(
name|nsegs
operator|>
name|txr
operator|->
name|tx_avail
operator|-
literal|2
condition|)
block|{
name|adapter
operator|->
name|no_tx_desc_avail2
operator|++
expr_stmt|;
name|error
operator|=
name|ENOBUFS
expr_stmt|;
goto|goto
name|encap_fail
goto|;
block|}
name|m_head
operator|=
operator|*
name|m_headp
expr_stmt|;
comment|/* 	** Set the appropriate offload context 	** this becomes the first descriptor of  	** a packet. 	*/
if|if
condition|(
name|ixgbe_tso_setup
argument_list|(
name|txr
argument_list|,
name|m_head
argument_list|,
operator|&
name|paylen
argument_list|)
condition|)
block|{
name|cmd_type_len
operator||=
name|IXGBE_ADVTXD_DCMD_TSE
expr_stmt|;
name|olinfo_status
operator||=
name|IXGBE_TXD_POPTS_IXSM
operator|<<
literal|8
expr_stmt|;
name|olinfo_status
operator||=
name|IXGBE_TXD_POPTS_TXSM
operator|<<
literal|8
expr_stmt|;
name|olinfo_status
operator||=
name|paylen
operator|<<
name|IXGBE_ADVTXD_PAYLEN_SHIFT
expr_stmt|;
operator|++
name|adapter
operator|->
name|tso_tx
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ixgbe_tx_ctx_setup
argument_list|(
name|txr
argument_list|,
name|m_head
argument_list|)
condition|)
name|olinfo_status
operator||=
name|IXGBE_TXD_POPTS_TXSM
operator|<<
literal|8
expr_stmt|;
name|i
operator|=
name|txr
operator|->
name|next_avail_tx_desc
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|nsegs
condition|;
name|j
operator|++
control|)
block|{
name|bus_size_t
name|seglen
decl_stmt|;
name|bus_addr_t
name|segaddr
decl_stmt|;
name|txbuf
operator|=
operator|&
name|txr
operator|->
name|tx_buffers
index|[
name|i
index|]
expr_stmt|;
name|txd
operator|=
operator|&
name|txr
operator|->
name|tx_base
index|[
name|i
index|]
expr_stmt|;
name|seglen
operator|=
name|segs
index|[
name|j
index|]
operator|.
name|ds_len
expr_stmt|;
name|segaddr
operator|=
name|htole64
argument_list|(
name|segs
index|[
name|j
index|]
operator|.
name|ds_addr
argument_list|)
expr_stmt|;
name|txd
operator|->
name|read
operator|.
name|buffer_addr
operator|=
name|segaddr
expr_stmt|;
name|txd
operator|->
name|read
operator|.
name|cmd_type_len
operator|=
name|htole32
argument_list|(
name|txr
operator|->
name|txd_cmd
operator||
name|cmd_type_len
operator||
name|seglen
argument_list|)
expr_stmt|;
name|txd
operator|->
name|read
operator|.
name|olinfo_status
operator|=
name|htole32
argument_list|(
name|olinfo_status
argument_list|)
expr_stmt|;
name|last
operator|=
name|i
expr_stmt|;
comment|/* Next descriptor that will get completed */
if|if
condition|(
operator|++
name|i
operator|==
name|adapter
operator|->
name|num_tx_desc
condition|)
name|i
operator|=
literal|0
expr_stmt|;
name|txbuf
operator|->
name|m_head
operator|=
name|NULL
expr_stmt|;
name|txbuf
operator|->
name|next_eop
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* 		** we have to do this inside the loop right now 		** because of the hardware workaround. 		*/
if|if
condition|(
name|j
operator|==
operator|(
name|nsegs
operator|-
literal|1
operator|)
condition|)
comment|/* Last descriptor gets EOP and RS */
name|txd
operator|->
name|read
operator|.
name|cmd_type_len
operator||=
name|htole32
argument_list|(
name|IXGBE_TXD_CMD_EOP
operator||
name|IXGBE_TXD_CMD_RS
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NO_82598_A0_SUPPORT
if|if
condition|(
name|adapter
operator|->
name|hw
operator|.
name|revision_id
operator|==
literal|0
condition|)
name|desc_flip
argument_list|(
name|txd
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|txr
operator|->
name|tx_avail
operator|-=
name|nsegs
expr_stmt|;
name|txr
operator|->
name|next_avail_tx_desc
operator|=
name|i
expr_stmt|;
name|txbuf
operator|->
name|m_head
operator|=
name|m_head
expr_stmt|;
name|txbuf
operator|->
name|map
operator|=
name|map
expr_stmt|;
name|bus_dmamap_sync
argument_list|(
name|txr
operator|->
name|txtag
argument_list|,
name|map
argument_list|,
name|BUS_DMASYNC_PREWRITE
argument_list|)
expr_stmt|;
comment|/* Set the index of the descriptor that will be marked done */
name|txbuf
operator|=
operator|&
name|txr
operator|->
name|tx_buffers
index|[
name|first
index|]
expr_stmt|;
name|txbuf
operator|->
name|next_eop
operator|=
name|last
expr_stmt|;
name|bus_dmamap_sync
argument_list|(
name|txr
operator|->
name|txdma
operator|.
name|dma_tag
argument_list|,
name|txr
operator|->
name|txdma
operator|.
name|dma_map
argument_list|,
name|BUS_DMASYNC_PREREAD
operator||
name|BUS_DMASYNC_PREWRITE
argument_list|)
expr_stmt|;
comment|/* 	 * Advance the Transmit Descriptor Tail (Tdt), this tells the 	 * hardware that this frame is available to transmit. 	 */
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_TDT
argument_list|(
name|txr
operator|->
name|me
argument_list|)
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
name|encap_fail
label|:
name|bus_dmamap_unload
argument_list|(
name|txr
operator|->
name|txtag
argument_list|,
name|txbuf
operator|->
name|map
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
specifier|static
name|void
name|ixgbe_set_promisc
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|u_int32_t
name|reg_rctl
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
name|reg_rctl
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_FCTRL
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_PROMISC
condition|)
block|{
name|reg_rctl
operator||=
operator|(
name|IXGBE_FCTRL_UPE
operator||
name|IXGBE_FCTRL_MPE
operator|)
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_FCTRL
argument_list|,
name|reg_rctl
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_ALLMULTI
condition|)
block|{
name|reg_rctl
operator||=
name|IXGBE_FCTRL_MPE
expr_stmt|;
name|reg_rctl
operator|&=
operator|~
name|IXGBE_FCTRL_UPE
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_FCTRL
argument_list|,
name|reg_rctl
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
specifier|static
name|void
name|ixgbe_disable_promisc
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|u_int32_t
name|reg_rctl
decl_stmt|;
name|reg_rctl
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_FCTRL
argument_list|)
expr_stmt|;
name|reg_rctl
operator|&=
operator|(
operator|~
name|IXGBE_FCTRL_UPE
operator|)
expr_stmt|;
name|reg_rctl
operator|&=
operator|(
operator|~
name|IXGBE_FCTRL_MPE
operator|)
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_FCTRL
argument_list|,
name|reg_rctl
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/*********************************************************************  *  Multicast Update  *  *  This routine is called whenever multicast address list is updated.  *  **********************************************************************/
define|#
directive|define
name|IXGBE_RAR_ENTRIES
value|16
specifier|static
name|void
name|ixgbe_set_multi
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|u32
name|fctrl
decl_stmt|;
name|u8
name|mta
index|[
name|MAX_NUM_MULTICAST_ADDRESSES
operator|*
name|IXGBE_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u8
modifier|*
name|update_ptr
decl_stmt|;
name|struct
name|ifmultiaddr
modifier|*
name|ifma
decl_stmt|;
name|int
name|mcnt
init|=
literal|0
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
name|IOCTL_DEBUGOUT
argument_list|(
literal|"ixgbe_set_multi: begin"
argument_list|)
expr_stmt|;
name|fctrl
operator|=
name|IXGBE_READ_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_FCTRL
argument_list|)
expr_stmt|;
name|fctrl
operator||=
operator|(
name|IXGBE_FCTRL_UPE
operator||
name|IXGBE_FCTRL_MPE
operator|)
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_PROMISC
condition|)
name|fctrl
operator||=
operator|(
name|IXGBE_FCTRL_UPE
operator||
name|IXGBE_FCTRL_MPE
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_ALLMULTI
condition|)
block|{
name|fctrl
operator||=
name|IXGBE_FCTRL_MPE
expr_stmt|;
name|fctrl
operator|&=
operator|~
name|IXGBE_FCTRL_UPE
expr_stmt|;
block|}
else|else
name|fctrl
operator|&=
operator|~
operator|(
name|IXGBE_FCTRL_UPE
operator||
name|IXGBE_FCTRL_MPE
operator|)
expr_stmt|;
name|IXGBE_WRITE_REG
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|IXGBE_FCTRL
argument_list|,
name|fctrl
argument_list|)
expr_stmt|;
name|IF_ADDR_LOCK
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|TAILQ_FOREACH
argument_list|(
argument|ifma
argument_list|,
argument|&ifp->if_multiaddrs
argument_list|,
argument|ifma_link
argument_list|)
block|{
if|if
condition|(
name|ifma
operator|->
name|ifma_addr
operator|->
name|sa_family
operator|!=
name|AF_LINK
condition|)
continue|continue;
name|bcopy
argument_list|(
name|LLADDR
argument_list|(
operator|(
expr|struct
name|sockaddr_dl
operator|*
operator|)
name|ifma
operator|->
name|ifma_addr
argument_list|)
argument_list|,
operator|&
name|mta
index|[
name|mcnt
operator|*
name|IXGBE_ETH_LENGTH_OF_ADDRESS
index|]
argument_list|,
name|IXGBE_ETH_LENGTH_OF_ADDRESS
argument_list|)
expr_stmt|;
name|mcnt
operator|++
expr_stmt|;
block|}
name|IF_ADDR_UNLOCK
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|update_ptr
operator|=
name|mta
expr_stmt|;
name|ixgbe_update_mc_addr_list
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
name|update_ptr
argument_list|,
name|mcnt
argument_list|,
name|ixgbe_mc_array_itr
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/*  * This is an iterator function now needed by the multicast  * shared code. It simply feeds the shared code routine the  * addresses in the array of ixgbe_set_multi() one by one.  */
specifier|static
name|u8
modifier|*
name|ixgbe_mc_array_itr
parameter_list|(
name|u8
modifier|*
modifier|*
name|update_ptr
parameter_list|)
block|{
name|u8
modifier|*
name|addr
init|=
operator|*
name|update_ptr
decl_stmt|;
name|u8
modifier|*
name|newptr
decl_stmt|;
name|newptr
operator|=
name|addr
operator|+
name|IXGBE_ETH_LENGTH_OF_ADDRESS
expr_stmt|;
operator|*
name|update_ptr
operator|=
name|newptr
expr_stmt|;
return|return
name|addr
return|;
block|}
comment|/*********************************************************************  *  Timer routine  *  *  This routine checks for link status,updates statistics,  *  and runs the watchdog timer.  *  **********************************************************************/
specifier|static
name|void
name|ixgbe_local_timer
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|arg
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
name|mtx_assert
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
name|ixgbe_update_link_status
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|ixgbe_update_stats_counters
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
if|if
condition|(
name|ixgbe_display_debug_stats
operator|&&
name|ifp
operator|->
name|if_drv_flags
operator|&
name|IFF_DRV_RUNNING
condition|)
block|{
name|ixgbe_print_hw_stats
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Each second we check the watchdog 	 * to protect against hardware hangs. 	 */
name|ixgbe_watchdog
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
name|callout_reset
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|,
name|hz
argument_list|,
name|ixgbe_local_timer
argument_list|,
name|adapter
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|ixgbe_update_link_status
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|boolean_t
name|link_up
init|=
name|FALSE
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|adapter
operator|->
name|ifp
decl_stmt|;
name|device_t
name|dev
init|=
name|adapter
operator|->
name|dev
decl_stmt|;
name|ixgbe_check_link
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
operator|&
name|adapter
operator|->
name|link_speed
argument_list|,
operator|&
name|link_up
argument_list|)
expr_stmt|;
if|if
condition|(
name|link_up
condition|)
block|{
if|if
condition|(
name|adapter
operator|->
name|link_active
operator|==
name|FALSE
condition|)
block|{
if|if
condition|(
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Link is up %d Gbps %s \n"
argument_list|,
operator|(
operator|(
name|adapter
operator|->
name|link_speed
operator|==
literal|128
operator|)
condition|?
literal|10
else|:
literal|1
operator|)
argument_list|,
literal|"Full Duplex"
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|link_active
operator|=
name|TRUE
expr_stmt|;
name|if_link_state_change
argument_list|(
name|ifp
argument_list|,
name|LINK_STATE_UP
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Link down */
if|if
condition|(
name|adapter
operator|->
name|link_active
operator|==
name|TRUE
condition|)
block|{
if|if
condition|(
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Link is Down\n"
argument_list|)
expr_stmt|;
name|if_link_state_change
argument_list|(
name|ifp
argument_list|,
name|LINK_STATE_DOWN
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|link_active
operator|=
name|FALSE
expr_stmt|;
name|adapter
operator|->
name|watchdog_timer
operator|=
name|FALSE
expr_stmt|;
block|}
block|}
return|return;
block|}
comment|/*********************************************************************  *  *  This routine disables all traffic on the adapter by issuing a  *  global reset on the MAC and deallocates TX/RX buffers.  *  **********************************************************************/
specifier|static
name|void
name|ixgbe_stop
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|arg
decl_stmt|;
name|ifp
operator|=
name|adapter
operator|->
name|ifp
expr_stmt|;
name|mtx_assert
argument_list|(
operator|&
name|adapter
operator|->
name|core_mtx
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
name|INIT_DEBUGOUT
argument_list|(
literal|"ixgbe_stop: begin\n"
argument_list|)
expr_stmt|;
name|ixgbe_disable_intr
argument_list|(
name|adapter
argument_list|)
expr_stmt|;
comment|/* Tell the stack that the interface is no longer active */
name|ifp
operator|->
name|if_drv_flags
operator|&=
operator|~
operator|(
name|IFF_DRV_RUNNING
operator||
name|IFF_DRV_OACTIVE
operator|)
expr_stmt|;
name|ixgbe_reset_hw
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|hw
operator|.
name|adapter_stopped
operator|=
name|FALSE
expr_stmt|;
name|ixgbe_stop_adapter
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|)
expr_stmt|;
name|callout_stop
argument_list|(
operator|&
name|adapter
operator|->
name|timer
argument_list|)
expr_stmt|;
comment|/* reprogram the RAR[0] in case user changed it. */
name|ixgbe_set_rar
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
literal|0
argument_list|,
name|adapter
operator|->
name|hw
operator|.
name|mac
operator|.
name|addr
argument_list|,
name|IXGBE_RAH_AV
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/*********************************************************************  *  *  Determine hardware revision.  *  **********************************************************************/
specifier|static
name|void
name|ixgbe_identify_hardware
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|device_t
name|dev
init|=
name|adapter
operator|->
name|dev
decl_stmt|;
comment|/* Save off the information about this board */
name|adapter
operator|->
name|hw
operator|.
name|vendor_id
operator|=
name|pci_get_vendor
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|hw
operator|.
name|device_id
operator|=
name|pci_get_device
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|hw
operator|.
name|revision_id
operator|=
name|pci_read_config
argument_list|(
name|dev
argument_list|,
name|PCIR_REVID
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|hw
operator|.
name|subsystem_vendor_id
operator|=
name|pci_read_config
argument_list|(
name|dev
argument_list|,
name|PCIR_SUBVEND_0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|hw
operator|.
name|subsystem_device_id
operator|=
name|pci_read_config
argument_list|(
name|dev
argument_list|,
name|PCIR_SUBDEV_0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return;
block|}
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
comment|/*********************************************************************  *  *  Setup MSIX: this is a prereq for doing Multiqueue/RSS.  *  **********************************************************************/
specifier|static
name|int
name|ixgbe_setup_msix
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|device_t
name|dev
init|=
name|adapter
operator|->
name|dev
decl_stmt|;
name|struct
name|tx_ring
modifier|*
name|txr
init|=
name|adapter
operator|->
name|tx_rings
decl_stmt|;
name|struct
name|rx_ring
modifier|*
name|rxr
init|=
name|adapter
operator|->
name|rx_rings
decl_stmt|;
name|int
name|error
decl_stmt|,
name|vector
init|=
literal|0
decl_stmt|;
comment|/* TX setup: the code is here for multi tx, 	   there are other parts of the driver not ready for it */
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|adapter
operator|->
name|num_tx_queues
condition|;
name|i
operator|++
operator|,
name|vector
operator|++
operator|,
name|txr
operator|++
control|)
block|{
name|adapter
operator|->
name|res
index|[
name|vector
index|]
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|adapter
operator|->
name|rid
index|[
name|vector
index|]
argument_list|,
name|RF_SHAREABLE
operator||
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|adapter
operator|->
name|res
index|[
name|vector
index|]
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to allocate"
literal|" bus resource: tx interrupt [%d]\n"
argument_list|,
name|vector
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Set the handler function */
name|error
operator|=
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|adapter
operator|->
name|res
index|[
name|vector
index|]
argument_list|,
name|INTR_TYPE_NET
operator||
name|INTR_MPSAFE
argument_list|,
name|NULL
argument_list|,
name|ixgbe_msix_tx
argument_list|,
name|txr
argument_list|,
operator|&
name|adapter
operator|->
name|tag
index|[
name|vector
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|adapter
operator|->
name|res
index|[
name|vector
index|]
operator|=
name|NULL
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Failed to register TX handler"
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
name|txr
operator|->
name|msix
operator|=
name|vector
expr_stmt|;
name|adapter
operator|->
name|msix
operator|++
expr_stmt|;
block|}
comment|/* RX setup */
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|adapter
operator|->
name|num_rx_queues
condition|;
name|i
operator|++
operator|,
name|vector
operator|++
operator|,
name|rxr
operator|++
control|)
block|{
name|adapter
operator|->
name|res
index|[
name|vector
index|]
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|adapter
operator|->
name|rid
index|[
name|vector
index|]
argument_list|,
name|RF_SHAREABLE
operator||
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|adapter
operator|->
name|res
index|[
name|vector
index|]
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to allocate"
literal|" bus resource: rx interrupt [%d],"
literal|"rid = %d\n"
argument_list|,
name|i
argument_list|,
name|adapter
operator|->
name|rid
index|[
name|vector
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Set the handler function */
name|error
operator|=
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|adapter
operator|->
name|res
index|[
name|vector
index|]
argument_list|,
name|INTR_TYPE_NET
operator||
name|INTR_MPSAFE
argument_list|,
name|NULL
argument_list|,
name|ixgbe_msix_rx
argument_list|,
name|rxr
argument_list|,
operator|&
name|adapter
operator|->
name|tag
index|[
name|vector
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|adapter
operator|->
name|res
index|[
name|vector
index|]
operator|=
name|NULL
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Failed to register RX handler"
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
name|rxr
operator|->
name|msix
operator|=
name|vector
expr_stmt|;
name|adapter
operator|->
name|msix
operator|++
expr_stmt|;
block|}
comment|/* Now for Link changes */
name|adapter
operator|->
name|res
index|[
name|vector
index|]
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|adapter
operator|->
name|rid
index|[
name|vector
index|]
argument_list|,
name|RF_SHAREABLE
operator||
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|adapter
operator|->
name|res
index|[
name|vector
index|]
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to allocate"
literal|" bus resource: Link interrupt [%d]\n"
argument_list|,
name|adapter
operator|->
name|rid
index|[
name|vector
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Set the link handler function */
name|error
operator|=
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|adapter
operator|->
name|res
index|[
name|vector
index|]
argument_list|,
name|INTR_TYPE_NET
operator||
name|INTR_MPSAFE
argument_list|,
name|NULL
argument_list|,
name|ixgbe_msix_link
argument_list|,
name|adapter
argument_list|,
operator|&
name|adapter
operator|->
name|tag
index|[
name|vector
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|adapter
operator|->
name|res
index|[
name|vector
index|]
operator|=
name|NULL
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Failed to register LINK handler"
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
name|adapter
operator|->
name|linkvec
operator|=
name|vector
expr_stmt|;
name|adapter
operator|->
name|msix
operator|++
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
specifier|static
name|int
name|ixgbe_allocate_pci_resources
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
name|int
name|error
decl_stmt|,
name|rid
decl_stmt|;
name|device_t
name|dev
init|=
name|adapter
operator|->
name|dev
decl_stmt|;
name|rid
operator|=
name|PCIR_BAR
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|res_memory
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|adapter
operator|->
name|res_memory
operator|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to allocate bus resource: memory\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|adapter
operator|->
name|osdep
operator|.
name|mem_bus_space_tag
operator|=
name|rman_get_bustag
argument_list|(
name|adapter
operator|->
name|res_memory
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|osdep
operator|.
name|mem_bus_space_handle
operator|=
name|rman_get_bushandle
argument_list|(
name|adapter
operator|->
name|res_memory
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|hw
operator|.
name|hw_addr
operator|=
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|adapter
operator|->
name|osdep
operator|.
name|mem_bus_space_handle
expr_stmt|;
comment|/* 	 * First try to setup MSI/X interrupts, 	 * if that fails fall back to Legacy. 	 */
if|if
condition|(
name|ixgbe_allocate_msix_resources
argument_list|(
name|adapter
argument_list|)
condition|)
block|{
name|int
name|val
decl_stmt|;
name|adapter
operator|->
name|num_tx_queues
operator|=
literal|1
expr_stmt|;
name|adapter
operator|->
name|num_rx_queues
operator|=
literal|1
expr_stmt|;
name|val
operator|=
literal|0
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
comment|/* Attempt to use MSI */
name|val
operator|=
name|pci_msi_count
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|)
operator|&&
name|pci_alloc_msi
argument_list|(
name|dev
argument_list|,
operator|&
name|val
argument_list|)
operator|==
literal|0
condition|)
block|{
name|adapter
operator|->
name|rid
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"MSI Interrupt enabled\n"
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|adapter
operator|->
name|rid
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Legacy Interrupt enabled\n"
argument_list|)
expr_stmt|;
block|}
name|adapter
operator|->
name|res
index|[
literal|0
index|]
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|adapter
operator|->
name|rid
index|[
literal|0
index|]
argument_list|,
name|RF_SHAREABLE
operator||
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|adapter
operator|->
name|res
index|[
literal|0
index|]
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to allocate bus "
literal|"resource: interrupt\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Set the handler contexts */
name|TASK_INIT
argument_list|(
operator|&
name|adapter
operator|->
name|rxtx_task
argument_list|,
literal|0
argument_list|,
name|ixgbe_rxtx
argument_list|,
name|adapter
argument_list|)
expr_stmt|;
name|TASK_INIT
argument_list|(
operator|&
name|adapter
operator|->
name|link_task
argument_list|,
literal|0
argument_list|,
name|ixgbe_link
argument_list|,
name|adapter
argument_list|)
expr_stmt|;
name|adapter
operator|->
name|tq
operator|=
name|taskqueue_create_fast
argument_list|(
literal|"ix_taskq"
argument_list|,
name|M_NOWAIT
argument_list|,
name|taskqueue_thread_enqueue
argument_list|,
operator|&
name|adapter
operator|->
name|tq
argument_list|)
expr_stmt|;
name|taskqueue_start_threads
argument_list|(
operator|&
name|adapter
operator|->
name|tq
argument_list|,
literal|1
argument_list|,
name|PI_NET
argument_list|,
literal|"%s taskq"
argument_list|,
name|device_get_nameunit
argument_list|(
name|adapter
operator|->
name|dev
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700000
name|error
operator|=
name|bus_setup_intr
argument_list|(
argument|dev
argument_list|,
argument|adapter->res[
literal|0
argument|]
argument_list|,
argument|INTR_TYPE_NET | INTR_FAST
argument_list|,
argument|ixgbe_fast_irq
argument_list|,
else|#
directive|else
argument|error = bus_setup_intr(dev, adapter->res[
literal|0
argument|], 		    INTR_TYPE_NET, ixgbe_fast_irq, NULL,
endif|#
directive|endif
argument|adapter,&adapter->tag[
literal|0
argument|]); 		if (error) { 			adapter->res[
literal|0
argument|] = NULL; 			device_printf(dev,
literal|"Failed to register"
literal|" Fast Legacy handler"
argument|); 			return (error); 		} 	}  	adapter->hw.back =&adapter->osdep; 	return (
literal|0
argument|); }
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
comment|/*  * Attempt to configure MSI/X, the prefered  * interrupt option.  */
argument|static int ixgbe_allocate_msix_resources(struct adapter *adapter) { 	int             error
argument_list|,
argument|val
argument_list|,
argument|want
argument_list|,
argument|rid; 	device_t        dev = adapter->dev; 	int		vector =
literal|1
argument|;
comment|/* First map the MSIX table */
argument|rid = PCIR_BAR(
literal|3
argument|); 	adapter->res_msix = bus_alloc_resource_any(dev, SYS_RES_MEMORY,&rid, RF_ACTIVE); 	if (!adapter->res_msix) { 		device_printf(dev,
literal|"Unable to map MSIX table \n"
argument|); 			return (ENXIO);       	}
comment|/* Now figure out now many vectors we need to use */
argument|val = pci_msix_count(dev);
comment|/* check configured values */
argument|if (ixgbe_rx_queues ==
literal|0
argument|)
comment|/* Autoconfigure */
argument|ixgbe_rx_queues = mp_ncpus; 	want = ixgbe_tx_queues + ixgbe_rx_queues + ixgbe_other_queues;
comment|/* 	 *  We arent going to do anything fancy for now, 	 *  we either can meet desired config or we fail. 	 */
argument|if (val>= want)  		val = want; 	else  		return (ENXIO);
comment|/* Initialize the resource arrays */
argument|for (int i =
literal|0
argument|; i< IXGBE_MSGS; i++, vector++) { 		adapter->rid[i] = vector; 		adapter->tag[i] = NULL; 		adapter->res[i] = NULL; 	}  	adapter->num_tx_queues = ixgbe_tx_queues; 	adapter->num_rx_queues = ixgbe_rx_queues;
comment|/* Now allocate the vectors */
argument|if ((error = pci_alloc_msix(dev,&val)) ==
literal|0
argument|) { 		adapter->msix =
literal|1
argument|; 		device_printf(dev,
literal|"MSI/X Enabled with %d TX Queue, "
literal|"%d RX Queues, and Link Interrupt\n"
argument|,  		    ixgbe_tx_queues, ixgbe_rx_queues); 	} else { 		device_printf(dev,
literal|"FAIL pci_alloc_msix() %d\n"
argument|, error); 		return (error); 	} 	return (
literal|0
argument|); }
else|#
directive|else
comment|/* FreeBSD 6.2 */
argument|static int ixgbe_allocate_msix_resources(struct adapter *adapter) { 	return (
literal|1
argument|);
comment|/* Force Legacy behavior for 6.2 */
argument|}
endif|#
directive|endif
argument|static void ixgbe_free_pci_resources(struct adapter * adapter) { 	device_t dev = adapter->dev; 	int		i
argument_list|,
argument|loop;
comment|/* 	 * Legacy has this set to 0, but we need 	 * to run this once, so reset it. 	 */
argument|if (adapter->msix) 		loop = adapter->msix; 	else 		loop =
literal|1
argument|;
comment|/* 	 * First release all the interrupt resources: 	 * 	notice that since these are just kept 	 *	in an array we can do the same logic 	 * 	whether its MSIX or just legacy. 	 */
argument|for (i =
literal|0
argument|; i< loop; i++) { 		if (adapter->tag[i] != NULL) { 			bus_teardown_intr(dev, adapter->res[i], 			    adapter->tag[i]); 			adapter->tag[i] = NULL; 		} 		if (adapter->res[i] != NULL) { 			bus_release_resource(dev, SYS_RES_IRQ, 			    adapter->rid[i], adapter->res[i]); 		} 	}
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
argument|pci_release_msi(dev);
endif|#
directive|endif
argument|if (adapter->res_memory != NULL) 		bus_release_resource(dev, SYS_RES_MEMORY, 		    IXGBE_MMBA, adapter->res_memory);  	return; }
comment|/*********************************************************************  *  *  Initialize the hardware to a configuration as specified by the  *  adapter structure. The controller is reset, the EEPROM is  *  verified, the MAC address is set, then the shared initialization  *  routines are called.  *  **********************************************************************/
argument|static int ixgbe_hardware_init(struct adapter *adapter) { 	device_t dev = adapter->dev; 	uint16_t csum;  	csum =
literal|0
argument|;
comment|/* Issue a global reset */
argument|adapter->hw.adapter_stopped = FALSE; 	ixgbe_stop_adapter(&adapter->hw);
comment|/* Make sure we have a good EEPROM before we read from it */
argument|if (ixgbe_validate_eeprom_checksum(&adapter->hw,&csum)<
literal|0
argument|) { 		device_printf(dev,
literal|"The EEPROM Checksum Is Not Valid\n"
argument|); 		return (EIO); 	}
comment|/* Get Hardware Flow Control setting */
argument|adapter->hw.fc.original_type = ixgbe_fc_full; 	adapter->hw.fc.pause_time = IXGBE_FC_PAUSE; 	adapter->hw.fc.low_water = IXGBE_FC_LO; 	adapter->hw.fc.high_water = IXGBE_FC_HI; 	adapter->hw.fc.send_xon = TRUE;  	if (ixgbe_init_hw(&adapter->hw)) { 		device_printf(dev,
literal|"Hardware Initialization Failed"
argument|); 		return (EIO); 	}  	return (
literal|0
argument|); }
comment|/*********************************************************************  *  *  Setup networking device structure and register an interface.  *  **********************************************************************/
argument|static void ixgbe_setup_interface(device_t dev, struct adapter *adapter) { 	struct ifnet   *ifp; 	struct ixgbe_hw *hw =&adapter->hw; 	INIT_DEBUGOUT(
literal|"ixgbe_setup_interface: begin"
argument|);  	ifp = adapter->ifp = if_alloc(IFT_ETHER); 	if (ifp == NULL) 		panic(
literal|"%s: can not if_alloc()\n"
argument|, device_get_nameunit(dev)); 	if_initname(ifp, device_get_name(dev), device_get_unit(dev)); 	ifp->if_mtu = ETHERMTU; 	ifp->if_baudrate =
literal|1000000000
argument|; 	ifp->if_init = ixgbe_init; 	ifp->if_softc = adapter; 	ifp->if_flags = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST; 	ifp->if_ioctl = ixgbe_ioctl; 	ifp->if_start = ixgbe_start; 	ifp->if_timer =
literal|0
argument|; 	ifp->if_watchdog = NULL; 	ifp->if_snd.ifq_maxlen = adapter->num_tx_desc -
literal|1
argument|;  	ether_ifattach(ifp, adapter->hw.mac.addr);  	adapter->max_frame_size = 	    ifp->if_mtu + ETHER_HDR_LEN + ETHER_CRC_LEN;
comment|/* 	 * Tell the upper layer(s) we support long frames. 	 */
argument|ifp->if_data.ifi_hdrlen = sizeof(struct ether_vlan_header);  	if (adapter->msix)
comment|/* RSS and HWCSUM not compatible */
argument|ifp->if_capabilities |= IFCAP_TSO4; 	else 		ifp->if_capabilities |= (IFCAP_HWCSUM | IFCAP_TSO4); 	ifp->if_capabilities |= IFCAP_VLAN_HWTAGGING | IFCAP_VLAN_MTU; 	ifp->if_capabilities |= IFCAP_JUMBO_MTU;  	ifp->if_capenable = ifp->if_capabilities;  	if (hw->device_id == IXGBE_DEV_ID_82598AT) 		ixgbe_setup_link_speed(hw, (IXGBE_LINK_SPEED_10GB_FULL | 		    IXGBE_LINK_SPEED_1GB_FULL), TRUE, TRUE); 	else 		ixgbe_setup_link_speed(hw, IXGBE_LINK_SPEED_10GB_FULL, 		    TRUE, FALSE);
comment|/* 	 * Specify the media types supported by this adapter and register 	 * callbacks to update media and link information 	 */
argument|ifmedia_init(&adapter->media, IFM_IMASK, ixgbe_media_change, 		     ixgbe_media_status); 	ifmedia_add(&adapter->media, IFM_ETHER | IFM_10G_SR | 		    IFM_FDX,
literal|0
argument|, NULL); 	if (hw->device_id == IXGBE_DEV_ID_82598AT) { 		ifmedia_add(&adapter->media, 		    IFM_ETHER | IFM_1000_T | IFM_FDX,
literal|0
argument|, NULL); 		ifmedia_add(&adapter->media, 		    IFM_ETHER | IFM_1000_T,
literal|0
argument|, NULL); 	} 	ifmedia_add(&adapter->media, IFM_ETHER | IFM_AUTO,
literal|0
argument|, NULL); 	ifmedia_set(&adapter->media, IFM_ETHER | IFM_AUTO);  	return; }
comment|/********************************************************************  * Manage DMA'able memory.  *******************************************************************/
argument|static void ixgbe_dmamap_cb(void *arg, bus_dma_segment_t * segs, int nseg, int error) { 	if (error) 		return; 	*(bus_addr_t *) arg = segs->ds_addr; 	return; }  static int ixgbe_dma_malloc(struct adapter *adapter, bus_size_t size, 		struct ixgbe_dma_alloc *dma, int mapflags) { 	device_t dev = adapter->dev; 	int             r;  	r = bus_dma_tag_create(NULL,
comment|/* parent */
argument|PAGE_SIZE,
literal|0
argument|,
comment|/* alignment, bounds */
argument|BUS_SPACE_MAXADDR,
comment|/* lowaddr */
argument|BUS_SPACE_MAXADDR,
comment|/* highaddr */
argument|NULL, NULL,
comment|/* filter, filterarg */
argument|size,
comment|/* maxsize */
literal|1
argument|,
comment|/* nsegments */
argument|size,
comment|/* maxsegsize */
argument|BUS_DMA_ALLOCNOW,
comment|/* flags */
argument|NULL,
comment|/* lockfunc */
argument|NULL,
comment|/* lockfuncarg */
argument|&dma->dma_tag); 	if (r !=
literal|0
argument|) { 		device_printf(dev,
literal|"ixgbe_dma_malloc: bus_dma_tag_create failed; "
literal|"error %u\n"
argument|, r); 		goto fail_0; 	} 	r = bus_dmamem_alloc(dma->dma_tag, (void **)&dma->dma_vaddr, 			     BUS_DMA_NOWAIT,&dma->dma_map); 	if (r !=
literal|0
argument|) { 		device_printf(dev,
literal|"ixgbe_dma_malloc: bus_dmamem_alloc failed; "
literal|"error %u\n"
argument|, r); 		goto fail_1; 	} 	r = bus_dmamap_load(dma->dma_tag, dma->dma_map, dma->dma_vaddr, 			    size, 			    ixgbe_dmamap_cb,&dma->dma_paddr, 			    mapflags | BUS_DMA_NOWAIT); 	if (r !=
literal|0
argument|) { 		device_printf(dev,
literal|"ixgbe_dma_malloc: bus_dmamap_load failed; "
literal|"error %u\n"
argument|, r); 		goto fail_2; 	} 	dma->dma_size = size; 	return (
literal|0
argument|); fail_2: 	bus_dmamem_free(dma->dma_tag, dma->dma_vaddr, dma->dma_map); fail_1: 	bus_dma_tag_destroy(dma->dma_tag); fail_0: 	dma->dma_map = NULL; 	dma->dma_tag = NULL; 	return (r); }  static void ixgbe_dma_free(struct adapter *adapter, struct ixgbe_dma_alloc *dma) { 	bus_dmamap_sync(dma->dma_tag, dma->dma_map, 	    BUS_DMASYNC_POSTREAD | BUS_DMASYNC_POSTWRITE); 	bus_dmamap_unload(dma->dma_tag, dma->dma_map); 	bus_dmamem_free(dma->dma_tag, dma->dma_vaddr, dma->dma_map); 	bus_dma_tag_destroy(dma->dma_tag); }
comment|/*********************************************************************  *  *  Allocate memory for the transmit and receive rings, and then  *  the descriptors associated with each, called only once at attach.  *  **********************************************************************/
argument|static int ixgbe_allocate_queues(struct adapter *adapter) { 	device_t dev = adapter->dev; 	struct tx_ring *txr; 	struct rx_ring *rxr; 	int rsize
argument_list|,
argument|tsize
argument_list|,
argument|error = IXGBE_SUCCESS; 	int txconf =
literal|0
argument_list|,
argument|rxconf =
literal|0
argument|;
comment|/* First allocate the TX ring struct memory */
argument|if (!(adapter->tx_rings = 	    (struct tx_ring *) malloc(sizeof(struct tx_ring) * 	    adapter->num_tx_queues, M_DEVBUF, M_NOWAIT | M_ZERO))) { 		device_printf(dev,
literal|"Unable to allocate TX ring memory\n"
argument|); 		error = ENOMEM; 		goto fail; 	} 	txr = adapter->tx_rings;
comment|/* Next allocate the RX */
argument|if (!(adapter->rx_rings = 	    (struct rx_ring *) malloc(sizeof(struct rx_ring) * 	    adapter->num_rx_queues, M_DEVBUF, M_NOWAIT | M_ZERO))) { 		device_printf(dev,
literal|"Unable to allocate RX ring memory\n"
argument|); 		error = ENOMEM; 		goto rx_fail; 	} 	rxr = adapter->rx_rings;  	tsize = roundup2(adapter->num_tx_desc * 	    sizeof(union ixgbe_adv_tx_desc),
literal|4096
argument|);
comment|/* 	 * Now set up the TX queues, txconf is needed to handle the 	 * possibility that things fail midcourse and we need to 	 * undo memory gracefully 	 */
argument|for (int i =
literal|0
argument|; i< adapter->num_tx_queues; i++, txconf++) { 		char	name_string[
literal|16
argument|];
comment|/* Set up some basics */
argument|txr =&adapter->tx_rings[i]; 		txr->adapter = adapter; 		txr->me = i;
comment|/* 		 * Initialize the TX side lock 		 *  -this has to change for multi tx 		 */
argument|snprintf(name_string, sizeof(name_string),
literal|"%s:tx"
argument|, 		    device_get_nameunit(dev)); 		mtx_init(&adapter->tx_mtx, name_string, NULL, MTX_DEF);  		if (ixgbe_dma_malloc(adapter, tsize,&txr->txdma, BUS_DMA_NOWAIT)) { 			device_printf(dev,
literal|"Unable to allocate TX Descriptor memory\n"
argument|); 			error = ENOMEM; 			goto err_tx_desc; 		} 		txr->tx_base = (union ixgbe_adv_tx_desc *)txr->txdma.dma_vaddr; 		bzero((void *)txr->tx_base, tsize);
comment|/* Now allocate transmit buffers for the ring */
argument|if (ixgbe_allocate_transmit_buffers(txr)) { 			device_printf(dev,
literal|"Critical Failure setting up transmit buffers\n"
argument|); 			error = ENOMEM; 			goto err_tx_desc;         	}  	}
comment|/* 	 * Next the RX queues... 	 */
argument|rsize = roundup2(adapter->num_rx_desc * 	    sizeof(union ixgbe_adv_rx_desc),
literal|4096
argument|); 	for (int i =
literal|0
argument|; i< adapter->num_rx_queues; i++, rxconf++) { 		rxr =&adapter->rx_rings[i];
comment|/* Set up some basics */
argument|rxr->adapter = adapter; 		rxr->me = i;  		if (ixgbe_dma_malloc(adapter, rsize,&rxr->rxdma, BUS_DMA_NOWAIT)) { 			device_printf(dev,
literal|"Unable to allocate RxDescriptor memory\n"
argument|); 			error = ENOMEM; 			goto err_rx_desc; 		} 		rxr->rx_base = (union ixgbe_adv_rx_desc *)rxr->rxdma.dma_vaddr; 		bzero((void *)rxr->rx_base, rsize);
comment|/* Allocate receive buffers for the ring*/
argument|if (ixgbe_allocate_receive_buffers(rxr)) { 			device_printf(dev,
literal|"Critical Failure setting up receive buffers\n"
argument|); 			error = ENOMEM; 			goto err_rx_desc; 		} 	}  	return (
literal|0
argument|);  err_rx_desc: 	for (rxr = adapter->rx_rings; rxconf>
literal|0
argument|; rxr++, rxconf--) 		ixgbe_dma_free(adapter,&rxr->rxdma); err_tx_desc: 	for (txr = adapter->tx_rings; txconf>
literal|0
argument|; txr++, txconf--) 		ixgbe_dma_free(adapter,&txr->txdma); 	free(adapter->rx_rings, M_DEVBUF); rx_fail: 	free(adapter->tx_rings, M_DEVBUF); fail: 	return (error); }
comment|/*********************************************************************  *  *  Allocate memory for tx_buffer structures. The tx_buffer stores all  *  the information needed to transmit a packet on the wire. This is  *  called only once at attach, setup is done every reset.  *  **********************************************************************/
argument|static int ixgbe_allocate_transmit_buffers(struct tx_ring *txr) { 	struct adapter *adapter = txr->adapter; 	device_t dev = adapter->dev; 	struct ixgbe_tx_buf *txbuf; 	int error
argument_list|,
argument|i;
comment|/* 	 * Setup DMA descriptor areas. 	 */
argument|if ((error = bus_dma_tag_create(NULL,
comment|/* parent */
argument|PAGE_SIZE,
literal|0
argument|,
comment|/* alignment, bounds */
argument|BUS_SPACE_MAXADDR,
comment|/* lowaddr */
argument|BUS_SPACE_MAXADDR,
comment|/* highaddr */
argument|NULL, NULL,
comment|/* filter, filterarg */
argument|IXGBE_TSO_SIZE,
comment|/* maxsize */
argument|IXGBE_MAX_SCATTER,
comment|/* nsegments */
argument|PAGE_SIZE,
comment|/* maxsegsize */
literal|0
argument|,
comment|/* flags */
argument|NULL,
comment|/* lockfunc */
argument|NULL,
comment|/* lockfuncarg */
argument|&txr->txtag))) { 		device_printf(dev,
literal|"Unable to allocate TX DMA tag\n"
argument|); 		goto fail; 	}  	if (!(txr->tx_buffers = 	    (struct ixgbe_tx_buf *) malloc(sizeof(struct ixgbe_tx_buf) * 	    adapter->num_tx_desc, M_DEVBUF, M_NOWAIT | M_ZERO))) { 		device_printf(dev,
literal|"Unable to allocate tx_buffer memory\n"
argument|); 		error = ENOMEM; 		goto fail; 	}
comment|/* Create the descriptor buffer dma maps */
argument|txbuf = txr->tx_buffers; 	for (i =
literal|0
argument|; i< adapter->num_tx_desc; i++, txbuf++) { 		error = bus_dmamap_create(txr->txtag,
literal|0
argument|,&txbuf->map); 		if (error !=
literal|0
argument|) { 			device_printf(dev,
literal|"Unable to create TX DMA map\n"
argument|); 			goto fail; 		} 	}  	return
literal|0
argument|; fail:
comment|/* We free all, it handles case where we are in the middle */
argument|ixgbe_free_transmit_structures(adapter); 	return (error); }
comment|/*********************************************************************  *  *  Initialize a transmit ring.  *  **********************************************************************/
argument|static void ixgbe_setup_transmit_ring(struct tx_ring *txr) { 	struct adapter *adapter = txr->adapter; 	struct ixgbe_tx_buf *txbuf; 	int i;
comment|/* Clear the old ring contents */
argument|bzero((void *)txr->tx_base, 	      (sizeof(union ixgbe_adv_tx_desc)) * adapter->num_tx_desc);
comment|/* Reset indices */
argument|txr->next_avail_tx_desc =
literal|0
argument|; 	txr->next_tx_to_clean =
literal|0
argument|;
comment|/* Free any existing tx buffers. */
argument|txbuf = txr->tx_buffers; 	for (i =
literal|0
argument|; i< adapter->num_tx_desc; i++, txbuf++) { 		if (txbuf->m_head != NULL) { 			bus_dmamap_sync(txr->txtag, txbuf->map, 			    BUS_DMASYNC_POSTWRITE); 			bus_dmamap_unload(txr->txtag, txbuf->map); 			m_freem(txbuf->m_head); 			txbuf->m_head = NULL; 		}
comment|/* clear the watch index */
argument|txbuf->next_eop = -
literal|1
argument|;         }
comment|/* Set number of descriptors available */
argument|txr->tx_avail = adapter->num_tx_desc;  	bus_dmamap_sync(txr->txdma.dma_tag, txr->txdma.dma_map, 	    BUS_DMASYNC_PREREAD | BUS_DMASYNC_PREWRITE);  }
comment|/*********************************************************************  *  *  Initialize all transmit rings.  *  **********************************************************************/
argument|static int ixgbe_setup_transmit_structures(struct adapter *adapter) { 	struct tx_ring *txr = adapter->tx_rings;  	for (int i =
literal|0
argument|; i< adapter->num_tx_queues; i++, txr++) 		ixgbe_setup_transmit_ring(txr);  	return (
literal|0
argument|); }
comment|/*********************************************************************  *  *  Enable transmit unit.  *	NOTE: this will need to be changed if there are more than  *	one transmit queues.  **********************************************************************/
argument|static void ixgbe_initialize_transmit_units(struct adapter *adapter) { 	struct tx_ring *txr = adapter->tx_rings; 	uint64_t       tdba = txr->txdma.dma_paddr;
comment|/* Setup the Base and Length of the Tx Descriptor Ring */
argument|IXGBE_WRITE_REG(&adapter->hw, IXGBE_TDBAL(
literal|0
argument|), 		       (tdba&
literal|0x00000000ffffffffULL
argument|)); 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_TDBAH(
literal|0
argument|), (tdba>>
literal|32
argument|)); 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_TDLEN(
literal|0
argument|), 		       adapter->num_tx_desc * 		       sizeof(struct ixgbe_legacy_tx_desc));
comment|/* Setup the HW Tx Head and Tail descriptor pointers */
argument|IXGBE_WRITE_REG(&adapter->hw, IXGBE_TDH(
literal|0
argument|),
literal|0
argument|); 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_TDT(
literal|0
argument|),
literal|0
argument|);  	IXGBE_WRITE_REG(&adapter->hw, IXGBE_TIPG, IXGBE_TIPG_FIBER_DEFAULT);  	adapter->watchdog_timer =
literal|0
argument|;
comment|/* Setup Transmit Descriptor Cmd Settings */
argument|txr->txd_cmd = IXGBE_TXD_CMD_IFCS;  	return; }
comment|/*********************************************************************  *  *  Free all transmit rings.  *  **********************************************************************/
argument|static void ixgbe_free_transmit_structures(struct adapter *adapter) { 	struct tx_ring *txr = adapter->tx_rings; 	mtx_lock(&adapter->tx_mtx); 	for (int i =
literal|0
argument|; i< adapter->num_tx_queues; i++, txr++) { 		ixgbe_free_transmit_buffers(txr); 		ixgbe_dma_free(adapter,&txr->txdma); 	} 	mtx_unlock(&adapter->tx_mtx); 	mtx_destroy(&adapter->tx_mtx); 	free(adapter->tx_rings, M_DEVBUF); }
comment|/*********************************************************************  *  *  Free transmit ring related data structures.  *  **********************************************************************/
argument|static void ixgbe_free_transmit_buffers(struct tx_ring *txr) { 	struct adapter *adapter = txr->adapter; 	struct ixgbe_tx_buf *tx_buffer; 	int             i;  	INIT_DEBUGOUT(
literal|"free_transmit_ring: begin"
argument|);  	if (txr->tx_buffers == NULL) 		return;  	tx_buffer = txr->tx_buffers; 	for (i =
literal|0
argument|; i< adapter->num_tx_desc; i++, tx_buffer++) { 		if (tx_buffer->m_head != NULL) { 			bus_dmamap_sync(txr->txtag, tx_buffer->map, 			    BUS_DMASYNC_POSTWRITE); 			bus_dmamap_unload(txr->txtag, 			    tx_buffer->map); 			m_freem(tx_buffer->m_head); 			tx_buffer->m_head = NULL; 			if (tx_buffer->map != NULL) { 				bus_dmamap_destroy(txr->txtag, 				    tx_buffer->map); 				tx_buffer->map = NULL; 			} 		} else if (tx_buffer->map != NULL) { 			bus_dmamap_unload(txr->txtag, 			    tx_buffer->map); 			bus_dmamap_destroy(txr->txtag, 			    tx_buffer->map); 			tx_buffer->map = NULL; 		} 	}  	if (txr->tx_buffers != NULL) { 		free(txr->tx_buffers, M_DEVBUF); 		txr->tx_buffers = NULL; 	} 	if (txr->txtag != NULL) { 		bus_dma_tag_destroy(txr->txtag); 		txr->txtag = NULL; 	} 	return; }
comment|/*********************************************************************  *  *  Advanced Context Descriptor setup for VLAN or CSUM  *  **********************************************************************/
argument|static boolean_t ixgbe_tx_ctx_setup(struct tx_ring *txr, struct mbuf *mp) { 	struct adapter *adapter = txr->adapter; 	struct ixgbe_adv_tx_context_desc *TXD; 	struct ixgbe_tx_buf        *tx_buffer; 	uint32_t vlan_macip_lens =
literal|0
argument_list|,
argument|type_tucmd_mlhl =
literal|0
argument|; 	struct ether_vlan_header *eh; 	struct ip *ip; 	struct ip6_hdr *ip6; 	int  ehdrlen
argument_list|,
argument|ip_hlen =
literal|0
argument|; 	u16	etype; 	u8	ipproto =
literal|0
argument|; 	bool	offload = TRUE; 	int ctxd = txr->next_avail_tx_desc;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700000
argument|struct m_tag	*mtag;
else|#
directive|else
argument|u16 vtag =
literal|0
argument|;
endif|#
directive|endif
argument|if ((mp->m_pkthdr.csum_flags& CSUM_OFFLOAD) ==
literal|0
argument|) 		offload = FALSE;  	tx_buffer =&txr->tx_buffers[ctxd]; 	TXD = (struct ixgbe_adv_tx_context_desc *)&txr->tx_base[ctxd];
comment|/* 	** In advanced descriptors the vlan tag must  	** be placed into the descriptor itself. 	*/
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700000
argument|mtag = VLAN_OUTPUT_TAG(ifp, mp); 	if (mtag != NULL) { 		vlan_macip_lens |= 		    htole16(VLAN_TAG_VALUE(mtag))<< IXGBE_ADVTXD_VLAN_SHIFT; 	} else if (offload == FALSE) 		return FALSE;
comment|/* No need for CTX */
else|#
directive|else
argument|if (mp->m_flags& M_VLANTAG) { 		vtag = htole16(mp->m_pkthdr.ether_vtag); 		vlan_macip_lens |= (vtag<< IXGBE_ADVTXD_VLAN_SHIFT); 	} else if (offload == FALSE) 		return FALSE;
endif|#
directive|endif
comment|/* 	 * Determine where frame payload starts. 	 * Jump over vlan headers if already present, 	 * helpful for QinQ too. 	 */
argument|eh = mtod(mp, struct ether_vlan_header *); 	if (eh->evl_encap_proto == htons(ETHERTYPE_VLAN)) { 		etype = ntohs(eh->evl_proto); 		ehdrlen = ETHER_HDR_LEN + ETHER_VLAN_ENCAP_LEN; 	} else { 		etype = ntohs(eh->evl_encap_proto); 		ehdrlen = ETHER_HDR_LEN; 	}
comment|/* Set the ether header length */
argument|vlan_macip_lens |= ehdrlen<< IXGBE_ADVTXD_MACLEN_SHIFT;  	switch (etype) { 		case ETHERTYPE_IP: 			ip = (struct ip *)(mp->m_data + ehdrlen); 			ip_hlen = ip->ip_hl<<
literal|2
argument|; 			if (mp->m_len< ehdrlen + ip_hlen) 				return FALSE;
comment|/* failure */
argument|ipproto = ip->ip_p; 			type_tucmd_mlhl |= IXGBE_ADVTXD_TUCMD_IPV4; 			break; 		case ETHERTYPE_IPV6: 			ip6 = (struct ip6_hdr *)(mp->m_data + ehdrlen); 			ip_hlen = sizeof(struct ip6_hdr); 			if (mp->m_len< ehdrlen + ip_hlen) 				return FALSE;
comment|/* failure */
argument|ipproto = ip6->ip6_nxt; 			type_tucmd_mlhl |= IXGBE_ADVTXD_TUCMD_IPV6; 			break; 		default: 			offload = FALSE; 			break; 	}  	vlan_macip_lens |= ip_hlen; 	type_tucmd_mlhl |= IXGBE_ADVTXD_DCMD_DEXT | IXGBE_ADVTXD_DTYP_CTXT;  	switch (ipproto) { 		case IPPROTO_TCP: 			if (mp->m_pkthdr.csum_flags& CSUM_TCP) 				type_tucmd_mlhl |= IXGBE_ADVTXD_TUCMD_L4T_TCP; 			break; 		case IPPROTO_UDP: 			if (mp->m_pkthdr.csum_flags& CSUM_UDP) 				type_tucmd_mlhl |= IXGBE_ADVTXD_TUCMD_L4T_UDP; 			break; 		default: 			offload = FALSE; 			break; 	}
comment|/* Now copy bits into descriptor */
argument|TXD->vlan_macip_lens |= htole32(vlan_macip_lens); 	TXD->type_tucmd_mlhl |= htole32(type_tucmd_mlhl); 	TXD->seqnum_seed = htole32(
literal|0
argument|); 	TXD->mss_l4len_idx = htole32(
literal|0
argument|);
ifndef|#
directive|ifndef
name|NO_82598_A0_SUPPORT
argument|if (adapter->hw.revision_id ==
literal|0
argument|) 		desc_flip(TXD);
endif|#
directive|endif
argument|tx_buffer->m_head = NULL; 	tx_buffer->next_eop = -
literal|1
argument|;
comment|/* We've consumed the first desc, adjust counters */
argument|if (++ctxd == adapter->num_tx_desc) 		ctxd =
literal|0
argument|; 	txr->next_avail_tx_desc = ctxd; 	--txr->tx_avail;          return (offload); }
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700000
comment|/**********************************************************************  *  *  Setup work for hardware segmentation offload (TSO) on  *  adapters using advanced tx descriptors  *  **********************************************************************/
argument|static boolean_t ixgbe_tso_setup(struct tx_ring *txr, struct mbuf *mp, u32 *paylen) { 	struct adapter *adapter = txr->adapter; 	struct ixgbe_adv_tx_context_desc *TXD; 	struct ixgbe_tx_buf        *tx_buffer; 	u32 vlan_macip_lens =
literal|0
argument_list|,
argument|type_tucmd_mlhl =
literal|0
argument|; 	u32 mss_l4len_idx =
literal|0
argument|; 	u16 vtag =
literal|0
argument|; 	int ctxd
argument_list|,
argument|ehdrlen
argument_list|,
argument|hdrlen
argument_list|,
argument|ip_hlen
argument_list|,
argument|tcp_hlen; 	struct ether_vlan_header *eh; 	struct ip *ip; 	struct tcphdr *th;  	if (((mp->m_pkthdr.csum_flags& CSUM_TSO) ==
literal|0
argument|) || 	    (mp->m_pkthdr.len<= IXGBE_TX_BUFFER_SIZE)) 	        return FALSE;
comment|/* 	 * Determine where frame payload starts. 	 * Jump over vlan headers if already present 	 */
argument|eh = mtod(mp, struct ether_vlan_header *); 	if (eh->evl_encap_proto == htons(ETHERTYPE_VLAN))  		ehdrlen = ETHER_HDR_LEN + ETHER_VLAN_ENCAP_LEN; 	else 		ehdrlen = ETHER_HDR_LEN;
comment|/* Ensure we have at least the IP+TCP header in the first mbuf. */
argument|if (mp->m_len< ehdrlen + sizeof(struct ip) + sizeof(struct tcphdr)) 		return FALSE;  	ctxd = txr->next_avail_tx_desc; 	tx_buffer =&txr->tx_buffers[ctxd]; 	TXD = (struct ixgbe_adv_tx_context_desc *)&txr->tx_base[ctxd];  	ip = (struct ip *)(mp->m_data + ehdrlen); 	if (ip->ip_p != IPPROTO_TCP) 		return FALSE;
comment|/* 0 */
argument|ip->ip_len =
literal|0
argument|; 	ip->ip_sum =
literal|0
argument|; 	ip_hlen = ip->ip_hl<<
literal|2
argument|; 	th = (struct tcphdr *)((caddr_t)ip + ip_hlen); 	th->th_sum = in_pseudo(ip->ip_src.s_addr, 	    ip->ip_dst.s_addr, htons(IPPROTO_TCP)); 	tcp_hlen = th->th_off<<
literal|2
argument|; 	hdrlen = ehdrlen + ip_hlen + tcp_hlen;
comment|/* This is used in the transmit desc in encap */
argument|*paylen = mp->m_pkthdr.len - hdrlen;
comment|/* VLAN MACLEN IPLEN */
argument|if (mp->m_flags& M_VLANTAG) { 		vtag = htole16(mp->m_pkthdr.ether_vtag);                 vlan_macip_lens |= (vtag<< IXGBE_ADVTXD_VLAN_SHIFT); 	}  	vlan_macip_lens |= ehdrlen<< IXGBE_ADVTXD_MACLEN_SHIFT; 	vlan_macip_lens |= ip_hlen; 	TXD->vlan_macip_lens |= htole32(vlan_macip_lens);
comment|/* ADV DTYPE TUCMD */
argument|type_tucmd_mlhl |= IXGBE_ADVTXD_DCMD_DEXT | IXGBE_ADVTXD_DTYP_CTXT; 	type_tucmd_mlhl |= IXGBE_ADVTXD_TUCMD_L4T_TCP; 	type_tucmd_mlhl |= IXGBE_ADVTXD_TUCMD_IPV4; 	TXD->type_tucmd_mlhl |= htole32(type_tucmd_mlhl);
comment|/* MSS L4LEN IDX */
argument|mss_l4len_idx |= (mp->m_pkthdr.tso_segsz<< IXGBE_ADVTXD_MSS_SHIFT); 	mss_l4len_idx |= (tcp_hlen<< IXGBE_ADVTXD_L4LEN_SHIFT); 	TXD->mss_l4len_idx = htole32(mss_l4len_idx);  	TXD->seqnum_seed = htole32(
literal|0
argument|); 	tx_buffer->m_head = NULL; 	tx_buffer->next_eop = -
literal|1
argument|;
ifndef|#
directive|ifndef
name|NO_82598_A0_SUPPORT
argument|if (adapter->hw.revision_id ==
literal|0
argument|) 		desc_flip(TXD);
endif|#
directive|endif
argument|if (++ctxd == adapter->num_tx_desc) 		ctxd =
literal|0
argument|;  	txr->tx_avail--; 	txr->next_avail_tx_desc = ctxd; 	return TRUE; }
else|#
directive|else
comment|/* For 6.2 RELEASE */
comment|/* This makes it easy to keep the code common */
argument|static boolean_t ixgbe_tso_setup(struct tx_ring *txr, struct mbuf *mp, u32 *paylen) { 	return (FALSE); }
endif|#
directive|endif
comment|/**********************************************************************  *  *  Examine each tx_buffer in the used queue. If the hardware is done  *  processing the packet then free associated resources. The  *  tx_buffer is put back on the free queue.  *  **********************************************************************/
argument|static boolean_t ixgbe_txeof(struct tx_ring *txr) { 	struct adapter * adapter = txr->adapter; 	struct ifnet	*ifp = adapter->ifp; 	int	first
argument_list|,
argument|last
argument_list|,
argument|done
argument_list|,
argument|num_avail; 	struct ixgbe_tx_buf *tx_buffer; 	struct ixgbe_legacy_tx_desc *tx_desc
argument_list|,
argument|*eop_desc;  	mtx_assert(&adapter->tx_mtx, MA_OWNED);  	if (txr->tx_avail == adapter->num_tx_desc) 		return FALSE;  	num_avail = txr->tx_avail; 	first = txr->next_tx_to_clean;  	tx_buffer =&txr->tx_buffers[first];
comment|/* For cleanup we just use legacy struct */
argument|tx_desc = (struct ixgbe_legacy_tx_desc *)&txr->tx_base[first]; 	last = tx_buffer->next_eop;         if (last == -
literal|1
argument|) 		return FALSE;  	eop_desc = (struct ixgbe_legacy_tx_desc *)&txr->tx_base[last];
comment|/*          * What this does is get the index of the          * first descriptor AFTER the EOP of the          * first packet, that way we can do the          * simple comparison on the inner while loop 	 * below.          */
argument|if (++last == adapter->num_tx_desc) last =
literal|0
argument|;         done = last;          bus_dmamap_sync(txr->txdma.dma_tag, txr->txdma.dma_map,             BUS_DMASYNC_POSTREAD);  	while (eop_desc->upper.fields.status& IXGBE_TXD_STAT_DD) {
comment|/* We clean the range of the packet */
argument|while (first != done) { 			tx_desc->upper.data =
literal|0
argument|; 			tx_desc->lower.data =
literal|0
argument|; 			tx_desc->buffer_addr =
literal|0
argument|; 			num_avail++;  			if (tx_buffer->m_head) { 				ifp->if_opackets++; 				bus_dmamap_sync(txr->txtag, 				    tx_buffer->map, 				    BUS_DMASYNC_POSTWRITE); 				bus_dmamap_unload(txr->txtag, 				    tx_buffer->map); 				m_freem(tx_buffer->m_head); 				tx_buffer->m_head = NULL; 				tx_buffer->map = NULL; 			} 			tx_buffer->next_eop = -
literal|1
argument|;  			if (++first == adapter->num_tx_desc) 				first =
literal|0
argument|;  			tx_buffer =&txr->tx_buffers[first]; 			tx_desc = 			    (struct ixgbe_legacy_tx_desc *)&txr->tx_base[first]; 		}
comment|/* See if we can continue to the next packet */
argument|last = tx_buffer->next_eop; 		if (last != -
literal|1
argument|) { 			eop_desc = 			    (struct ixgbe_legacy_tx_desc *)&txr->tx_base[last];
comment|/* Get new done point */
argument|if (++last == adapter->num_tx_desc) last =
literal|0
argument|; 			done = last; 		} else 			break;  	} 	bus_dmamap_sync(txr->txdma.dma_tag, txr->txdma.dma_map, 	    BUS_DMASYNC_PREREAD | BUS_DMASYNC_PREWRITE);  	txr->next_tx_to_clean = first;
comment|/* 	 * If we have enough room, clear IFF_DRV_OACTIVE to tell the stack that 	 * it is OK to send packets. If there are no pending descriptors, 	 * clear the timeout. Otherwise, if some descriptors have been freed, 	 * restart the timeout. 	 */
argument|if (num_avail> IXGBE_TX_CLEANUP_THRESHOLD) { 		ifp->if_drv_flags&= ~IFF_DRV_OACTIVE;
comment|/* If all are clean turn off the timer */
argument|if (num_avail == adapter->num_tx_desc) 			adapter->watchdog_timer =
literal|0
argument|;
comment|/* Some were cleaned, so reset timer */
argument|else if (num_avail != txr->tx_avail) 			adapter->watchdog_timer = IXGBE_TX_TIMEOUT; 	}  	txr->tx_avail = num_avail; 	return TRUE; }
comment|/*********************************************************************  *  *  Get a buffer from system mbuf buffer pool.  *  **********************************************************************/
argument|static int ixgbe_get_buf(struct rx_ring *rxr, int i) { 	struct adapter	*adapter = rxr->adapter; 	struct mbuf	*mp; 	bus_dmamap_t	map; 	int		nsegs
argument_list|,
argument|error
argument_list|,
argument|old
argument_list|,
argument|s =
literal|0
argument|; 	int		size = MCLBYTES;   	bus_dma_segment_t	segs[
literal|1
argument|]; 	struct ixgbe_rx_buf	*rxbuf;
comment|/* Are we going to Jumbo clusters? */
argument|if (adapter->bigbufs) { 		size = MJUMPAGESIZE; 		s =
literal|1
argument|; 	}; 	 	mp = m_getjcl(M_DONTWAIT, MT_DATA, M_PKTHDR, size); 	if (mp == NULL) { 		adapter->mbuf_alloc_failed++; 		return (ENOBUFS); 	}  	mp->m_len = mp->m_pkthdr.len = size;  	if (adapter->max_frame_size<= (MCLBYTES - ETHER_ALIGN)) 		m_adj(mp, ETHER_ALIGN);
comment|/* 	 * Using memory from the mbuf cluster pool, invoke the bus_dma 	 * machinery to arrange the memory mapping. 	 */
argument|error = bus_dmamap_load_mbuf_sg(rxr->rxtag[s], rxr->spare_map[s], 	    mp, segs,&nsegs, BUS_DMA_NOWAIT); 	if (error) { 		m_free(mp); 		return (error); 	}
comment|/* Now check our target buffer for existing mapping */
argument|rxbuf =&rxr->rx_buffers[i]; 	old = rxbuf->bigbuf; 	if (rxbuf->m_head != NULL) 		bus_dmamap_unload(rxr->rxtag[old], rxbuf->map[old]);          map = rxbuf->map[old];         rxbuf->map[s] = rxr->spare_map[s];         rxr->spare_map[old] = map;         bus_dmamap_sync(rxr->rxtag[s], rxbuf->map[s], BUS_DMASYNC_PREREAD);         rxbuf->m_head = mp;         rxbuf->bigbuf = s;          rxr->rx_base[i].read.pkt_addr = htole64(segs[
literal|0
argument|].ds_addr);
ifndef|#
directive|ifndef
name|NO_82598_A0_SUPPORT
comment|/* A0 needs to One's Compliment descriptors */
argument|if (adapter->hw.revision_id ==
literal|0
argument|) {         	struct dhack {u32 a1; u32 a2; u32 b1; u32 b2;};         	struct dhack *d;             	d = (struct dhack *)&rxr->rx_base[i];         	d->a1 = ~(d->a1);         	d->a2 = ~(d->a2); 	}
endif|#
directive|endif
argument|return (
literal|0
argument|); }
comment|/*********************************************************************  *  *  Allocate memory for rx_buffer structures. Since we use one  *  rx_buffer per received packet, the maximum number of rx_buffer's  *  that we'll need is equal to the number of receive descriptors  *  that we've allocated.  *  **********************************************************************/
argument|static int ixgbe_allocate_receive_buffers(struct rx_ring *rxr) { 	struct	adapter 	*adapter = rxr->adapter; 	device_t 		dev = adapter->dev; 	struct ixgbe_rx_buf 	*rxbuf; 	int             	i
argument_list|,
argument|bsize
argument_list|,
argument|error;  	bsize = sizeof(struct ixgbe_rx_buf) * adapter->num_rx_desc; 	if (!(rxr->rx_buffers = 	    (struct ixgbe_rx_buf *) malloc(bsize, 	    M_DEVBUF, M_NOWAIT | M_ZERO))) { 		device_printf(dev,
literal|"Unable to allocate rx_buffer memory\n"
argument|); 		error = ENOMEM; 		goto fail; 	}
comment|/* First make the small (2K) tag/map */
argument|if ((error = bus_dma_tag_create(NULL,
comment|/* parent */
argument|PAGE_SIZE,
literal|0
argument|,
comment|/* alignment, bounds */
argument|BUS_SPACE_MAXADDR,
comment|/* lowaddr */
argument|BUS_SPACE_MAXADDR,
comment|/* highaddr */
argument|NULL, NULL,
comment|/* filter, filterarg */
argument|MCLBYTES,
comment|/* maxsize */
literal|1
argument|,
comment|/* nsegments */
argument|MCLBYTES,
comment|/* maxsegsize */
literal|0
argument|,
comment|/* flags */
argument|NULL,
comment|/* lockfunc */
argument|NULL,
comment|/* lockfuncarg */
argument|&rxr->rxtag[
literal|0
argument|]))) { 		device_printf(dev,
literal|"Unable to create RX Small DMA tag\n"
argument|); 		goto fail; 	}
comment|/* Next make the large (4K) tag/map */
argument|if ((error = bus_dma_tag_create(NULL,
comment|/* parent */
argument|PAGE_SIZE,
literal|0
argument|,
comment|/* alignment, bounds */
argument|BUS_SPACE_MAXADDR,
comment|/* lowaddr */
argument|BUS_SPACE_MAXADDR,
comment|/* highaddr */
argument|NULL, NULL,
comment|/* filter, filterarg */
argument|MJUMPAGESIZE,
comment|/* maxsize */
literal|1
argument|,
comment|/* nsegments */
argument|MJUMPAGESIZE,
comment|/* maxsegsize */
literal|0
argument|,
comment|/* flags */
argument|NULL,
comment|/* lockfunc */
argument|NULL,
comment|/* lockfuncarg */
argument|&rxr->rxtag[
literal|1
argument|]))) { 		device_printf(dev,
literal|"Unable to create RX Large DMA tag\n"
argument|); 		goto fail; 	}
comment|/* Create the spare maps (used by getbuf) */
argument|error = bus_dmamap_create(rxr->rxtag[
literal|0
argument|], BUS_DMA_NOWAIT,&rxr->spare_map[
literal|0
argument|]);         error = bus_dmamap_create(rxr->rxtag[
literal|1
argument|], BUS_DMA_NOWAIT,&rxr->spare_map[
literal|1
argument|]); 	if (error) { 		device_printf(dev,
literal|"%s: bus_dmamap_create failed: %d\n"
argument|, 		    __func__, error); 		goto fail; 	}  	for (i =
literal|0
argument|; i< adapter->num_rx_desc; i++, rxbuf++) { 		rxbuf =&rxr->rx_buffers[i]; 		error = bus_dmamap_create(rxr->rxtag[
literal|0
argument|], 		    BUS_DMA_NOWAIT,&rxbuf->map[
literal|0
argument|]); 		if (error) { 			device_printf(dev,
literal|"Unable to create Small RX DMA map\n"
argument|); 			goto fail; 		} 		error = bus_dmamap_create(rxr->rxtag[
literal|1
argument|], 		    BUS_DMA_NOWAIT,&rxbuf->map[
literal|1
argument|]); 		if (error) { 			device_printf(dev,
literal|"Unable to create Large RX DMA map\n"
argument|); 			goto fail; 		} 	}  	return (
literal|0
argument|);  fail:
comment|/* Frees all, but can handle partial completion */
argument|ixgbe_free_receive_structures(adapter); 	return (error); }
comment|/*********************************************************************  *  *  Initialize a receive ring and its buffers.  *  **********************************************************************/
argument|static int ixgbe_setup_receive_ring(struct rx_ring *rxr) { 	struct	adapter 	*adapter; 	struct ixgbe_rx_buf *rxbuf; 	int j
argument_list|,
argument|rsize
argument_list|,
argument|s;  	adapter = rxr->adapter; 	rsize = roundup2(adapter->num_rx_desc * 	    sizeof(union ixgbe_adv_rx_desc),
literal|4096
argument|);
comment|/* Clear the ring contents */
argument|bzero((void *)rxr->rx_base, rsize);
comment|/* 	** Free current RX buffers: the size buffer 	** that is loaded is indicated by the buffer 	** bigbuf value. 	*/
argument|for (int i =
literal|0
argument|; i< adapter->num_rx_desc; i++) { 		rxbuf =&rxr->rx_buffers[i]; 		s = rxbuf->bigbuf; 		if (rxbuf->m_head != NULL) { 			bus_dmamap_sync(rxr->rxtag[s], rxbuf->map[s], 			    BUS_DMASYNC_POSTREAD); 			bus_dmamap_unload(rxr->rxtag[s], rxbuf->map[s]); 			m_freem(rxbuf->m_head); 			rxbuf->m_head = NULL; 		} 	}  	for (j =
literal|0
argument|; j< adapter->num_rx_desc; j++) { 		if (ixgbe_get_buf(rxr, j) == ENOBUFS) { 			rxr->rx_buffers[j].m_head = NULL; 			rxr->rx_base[j].read.pkt_addr =
literal|0
argument|;
comment|/* If we fail some may have change size */
argument|s = adapter->bigbufs; 			goto fail; 		} 	}
comment|/* Setup our descriptor indices */
argument|rxr->next_to_check =
literal|0
argument|; 	rxr->last_cleaned =
literal|0
argument|;  	bus_dmamap_sync(rxr->rxdma.dma_tag, rxr->rxdma.dma_map, 	    BUS_DMASYNC_PREREAD | BUS_DMASYNC_PREWRITE);  	return (
literal|0
argument|); fail:
comment|/* 	 * We need to clean up any buffers allocated so far 	 * 'j' is the failing index, decrement it to get the 	 * last success. 	 */
argument|for (--j; j<
literal|0
argument|; j--) { 		rxbuf =&rxr->rx_buffers[j]; 		if (rxbuf->m_head != NULL) { 			bus_dmamap_sync(rxr->rxtag[s], rxbuf->map[s], 			    BUS_DMASYNC_POSTREAD); 			bus_dmamap_unload(rxr->rxtag[s], rxbuf->map[s]); 			m_freem(rxbuf->m_head); 			rxbuf->m_head = NULL; 		} 	} 	return (ENOBUFS); }
comment|/*********************************************************************  *  *  Initialize all receive rings.  *  **********************************************************************/
argument|static int ixgbe_setup_receive_structures(struct adapter *adapter) { 	struct rx_ring *rxr = adapter->rx_rings; 	int i
argument_list|,
argument|j
argument_list|,
argument|s;  	for (i =
literal|0
argument|; i< adapter->num_rx_queues; i++, rxr++) 		if (ixgbe_setup_receive_ring(rxr)) 			goto fail;  	return (
literal|0
argument|); fail:
comment|/* 	 * Free RX buffers allocated so far, we will only handle 	 * the rings that completed, the failing case will have 	 * cleaned up for itself. The value of 'i' will be the 	 * failed ring so we must pre-decrement it. 	 */
argument|rxr = adapter->rx_rings; 	for (--i; i>
literal|0
argument|; i--, rxr++) { 		for (j =
literal|0
argument|; j< adapter->num_rx_desc; j++) { 			struct ixgbe_rx_buf *rxbuf; 			rxbuf =&rxr->rx_buffers[j]; 			s = rxbuf->bigbuf; 			if (rxbuf->m_head != NULL) { 				bus_dmamap_sync(rxr->rxtag[s], rxbuf->map[s], 			  	  BUS_DMASYNC_POSTREAD); 				bus_dmamap_unload(rxr->rxtag[s], rxbuf->map[s]); 				m_freem(rxbuf->m_head); 				rxbuf->m_head = NULL; 			} 		} 	}  	return (ENOBUFS); }
comment|/*********************************************************************  *  *  Enable receive unit.  *  **********************************************************************/
argument|static void ixgbe_initialize_receive_units(struct adapter *adapter) { 	struct	rx_ring	*rxr = adapter->rx_rings; 	struct ifnet   *ifp = adapter->ifp; 	u32		rxctrl
argument_list|,
argument|fctrl
argument_list|,
argument|srrctl
argument_list|,
argument|rxcsum; 	u32		reta
argument_list|,
argument|mrqc
argument_list|,
argument|hlreg
argument_list|,
argument|linkvec; 	u32		random[
literal|10
argument|];
comment|/* 	 * Make sure receives are disabled while 	 * setting up the descriptor ring 	 */
argument|rxctrl = IXGBE_READ_REG(&adapter->hw, IXGBE_RXCTRL); 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_RXCTRL, 	    rxctrl& ~IXGBE_RXCTRL_RXEN);
comment|/* Enable broadcasts */
argument|fctrl = IXGBE_READ_REG(&adapter->hw, IXGBE_FCTRL); 	fctrl |= IXGBE_FCTRL_BAM; 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_FCTRL, fctrl);  	hlreg = IXGBE_READ_REG(&adapter->hw, IXGBE_HLREG0); 	if (ifp->if_mtu> ETHERMTU) 		hlreg |= IXGBE_HLREG0_JUMBOEN; 	else 		hlreg&= ~IXGBE_HLREG0_JUMBOEN; 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_HLREG0, hlreg);  	srrctl = IXGBE_READ_REG(&adapter->hw, IXGBE_SRRCTL(
literal|0
argument|)); 	srrctl&= ~IXGBE_SRRCTL_BSIZEHDR_MASK; 	srrctl&= ~IXGBE_SRRCTL_BSIZEPKT_MASK; 	if (adapter->bigbufs) 		srrctl |=
literal|4096
argument|>> IXGBE_SRRCTL_BSIZEPKT_SHIFT; 	else 		srrctl |=
literal|2048
argument|>> IXGBE_SRRCTL_BSIZEPKT_SHIFT; 	srrctl |= IXGBE_SRRCTL_DESCTYPE_ADV_ONEBUF; 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_SRRCTL(
literal|0
argument|), srrctl);
comment|/* Set Queue moderation rate */
argument|for (int i =
literal|0
argument|; i< IXGBE_MSGS; i++) 		IXGBE_WRITE_REG(&adapter->hw, IXGBE_EITR(i), DEFAULT_ITR);
comment|/* Set Link moderation lower */
argument|linkvec = adapter->num_tx_queues + adapter->num_rx_queues; 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_EITR(linkvec), LINK_ITR);  	for (int i =
literal|0
argument|; i< adapter->num_rx_queues; i++, rxr++) { 		u64 rdba = rxr->rxdma.dma_paddr;
comment|/* Setup the Base and Length of the Rx Descriptor Ring */
argument|IXGBE_WRITE_REG(&adapter->hw, IXGBE_RDBAL(i), 			       (rdba&
literal|0x00000000ffffffffULL
argument|)); 		IXGBE_WRITE_REG(&adapter->hw, IXGBE_RDBAH(i), (rdba>>
literal|32
argument|)); 		IXGBE_WRITE_REG(&adapter->hw, IXGBE_RDLEN(i), 		    adapter->num_rx_desc * sizeof(union ixgbe_adv_rx_desc));
comment|/* Setup the HW Rx Head and Tail Descriptor Pointers */
argument|IXGBE_WRITE_REG(&adapter->hw, IXGBE_RDH(i),
literal|0
argument|); 		IXGBE_WRITE_REG(&adapter->hw, IXGBE_RDT(i), 		    adapter->num_rx_desc -
literal|1
argument|); 	}  	if (adapter->num_rx_queues>
literal|1
argument|) {
comment|/* set up random bits */
argument|arc4rand(&random, sizeof(random),
literal|0
argument|); 		switch (adapter->num_rx_queues) { 			case
literal|8
argument|: 			case
literal|4
argument|: 				reta =
literal|0x00010203
argument|; 				break; 			case
literal|2
argument|: 				reta =
literal|0x00010001
argument|; 				break; 			default: 				reta =
literal|0x00000000
argument|; 		}
comment|/* Set up the redirection table */
argument|for (int i =
literal|0
argument|; i<
literal|32
argument|; i++) { 			IXGBE_WRITE_REG(&adapter->hw, IXGBE_RETA(i), reta); 			if (adapter->num_rx_queues>
literal|4
argument|) { 				++i; 				IXGBE_WRITE_REG(&adapter->hw, 				    IXGBE_RETA(i),
literal|0x04050607
argument|); 			} 		}
comment|/* Now fill our hash function seeds */
argument|for (int i =
literal|0
argument|; i<
literal|10
argument|; i++) 			IXGBE_WRITE_REG_ARRAY(&adapter->hw, 			    IXGBE_RSSRK(
literal|0
argument|), i, random[i]);  		mrqc = IXGBE_MRQC_RSSEN
comment|/* Perform hash on these packet types */
argument|| IXGBE_MRQC_RSS_FIELD_IPV4 		    | IXGBE_MRQC_RSS_FIELD_IPV4_TCP 		    | IXGBE_MRQC_RSS_FIELD_IPV4_UDP 		    | IXGBE_MRQC_RSS_FIELD_IPV6_EX_TCP 		    | IXGBE_MRQC_RSS_FIELD_IPV6_EX 		    | IXGBE_MRQC_RSS_FIELD_IPV6 		    | IXGBE_MRQC_RSS_FIELD_IPV6_TCP 		    | IXGBE_MRQC_RSS_FIELD_IPV6_UDP 		    | IXGBE_MRQC_RSS_FIELD_IPV6_EX_UDP; 		IXGBE_WRITE_REG(&adapter->hw, IXGBE_MRQC, mrqc);
comment|/* RSS and RX IPP Checksum are mutually exclusive */
argument|rxcsum = IXGBE_READ_REG(&adapter->hw, IXGBE_RXCSUM); 		rxcsum |= IXGBE_RXCSUM_PCSD; 		IXGBE_WRITE_REG(&adapter->hw, IXGBE_RXCSUM, rxcsum); 	} else { 		rxcsum = IXGBE_READ_REG(&adapter->hw, IXGBE_RXCSUM); 		if (ifp->if_capenable& IFCAP_RXCSUM) 			rxcsum |= IXGBE_RXCSUM_IPPCSE; 		IXGBE_WRITE_REG(&adapter->hw, IXGBE_RXCSUM, rxcsum); 	}
comment|/* Enable Receive engine */
argument|rxctrl |= (IXGBE_RXCTRL_RXEN | IXGBE_RXCTRL_DMBYPS); 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_RXCTRL, rxctrl);  	return; }
comment|/*********************************************************************  *  *  Free all receive rings.  *  **********************************************************************/
argument|static void ixgbe_free_receive_structures(struct adapter *adapter) { 	struct rx_ring *rxr = adapter->rx_rings;  	for (int i =
literal|0
argument|; i< adapter->num_rx_queues; i++, rxr++) { 		ixgbe_free_receive_buffers(rxr);
comment|/* Free the ring memory as well */
argument|ixgbe_dma_free(adapter,&rxr->rxdma); 	}  	free(adapter->rx_rings, M_DEVBUF); }
comment|/*********************************************************************  *  *  Free receive ring data structures  *  **********************************************************************/
argument|void ixgbe_free_receive_buffers(struct rx_ring *rxr) { 	struct adapter		*adapter = NULL; 	struct ixgbe_rx_buf	*rxbuf = NULL;  	INIT_DEBUGOUT(
literal|"free_receive_buffers: begin"
argument|); 	adapter = rxr->adapter; 	if (rxr->rx_buffers != NULL) { 		rxbuf =&rxr->rx_buffers[
literal|0
argument|]; 		for (int i =
literal|0
argument|; i< adapter->num_rx_desc; i++) { 			int s = rxbuf->bigbuf; 			if (rxbuf->map != NULL) { 				bus_dmamap_unload(rxr->rxtag[s], rxbuf->map[s]); 				bus_dmamap_destroy(rxr->rxtag[s], rxbuf->map[s]); 			} 			if (rxbuf->m_head != NULL) { 				m_freem(rxbuf->m_head); 			} 			rxbuf->m_head = NULL; 			++rxbuf; 		} 	} 	if (rxr->rx_buffers != NULL) { 		free(rxr->rx_buffers, M_DEVBUF); 		rxr->rx_buffers = NULL; 	} 	for (int s =
literal|0
argument|; s<
literal|2
argument|; s++) { 		if (rxr->rxtag[s] != NULL) { 			bus_dma_tag_destroy(rxr->rxtag[s]); 			rxr->rxtag[s] = NULL; 		} 	} 	return; }
comment|/*********************************************************************  *  *  This routine executes in interrupt context. It replenishes  *  the mbufs in the descriptor and sends data which has been  *  dma'ed into host memory to upper layer.  *  *  We loop at most count times if count is> 0, or until done if  *  count< 0.  *  *********************************************************************/
argument|static int ixgbe_rxeof(struct rx_ring *rxr, int count) { 	struct adapter 		*adapter = rxr->adapter; 	struct ifnet   		*ifp = adapter->ifp; 	struct mbuf    		*mp; 	int             	len
argument_list|,
argument|i
argument_list|,
argument|eop =
literal|0
argument|; 	uint8_t			accept_frame =
literal|0
argument|; 	uint32_t		staterr; 	union ixgbe_adv_rx_desc	*cur;   	i = rxr->next_to_check; 	cur =&rxr->rx_base[i]; 	staterr = cur->wb.upper.status_error;  	if (!(staterr& IXGBE_RXD_STAT_DD)) 		return (
literal|0
argument|);  	while ((staterr& IXGBE_RXD_STAT_DD)&& (count !=
literal|0
argument|)&& 	    (ifp->if_drv_flags& IFF_DRV_RUNNING)) { 		struct mbuf *m = NULL; 		int s;  		mp = rxr->rx_buffers[i].m_head; 		s = rxr->rx_buffers[i].bigbuf; 		bus_dmamap_sync(rxr->rxtag[s], rxr->rx_buffers[i].map[s], 				BUS_DMASYNC_POSTREAD); 		accept_frame =
literal|1
argument|; 		if (staterr& IXGBE_RXD_STAT_EOP) { 			count--; 			eop =
literal|1
argument|; 		} else { 			eop =
literal|0
argument|; 		} 		len = cur->wb.upper.length;  		if (staterr& IXGBE_RXDADV_ERR_FRAME_ERR_MASK) 			accept_frame =
literal|0
argument|;  		if (accept_frame) {
comment|/* Get a fresh buffer first */
argument|if (ixgbe_get_buf(rxr, i) !=
literal|0
argument|) { 				ifp->if_iqdrops++; 				goto discard; 			}
comment|/* Assign correct length to the current fragment */
argument|mp->m_len = len;  			if (rxr->fmp == NULL) { 				mp->m_pkthdr.len = len; 				rxr->fmp = mp;
comment|/* Store the first mbuf */
argument|rxr->lmp = mp; 			} else {
comment|/* Chain mbuf's together */
argument|mp->m_flags&= ~M_PKTHDR; 				rxr->lmp->m_next = mp; 				rxr->lmp = rxr->lmp->m_next; 				rxr->fmp->m_pkthdr.len += len; 			}  			if (eop) { 				rxr->fmp->m_pkthdr.rcvif = ifp; 				ifp->if_ipackets++; 				rxr->packet_count++; 				rxr->byte_count += rxr->fmp->m_pkthdr.len;  				ixgbe_rx_checksum(adapter, 				    staterr, rxr->fmp);  				if (staterr& IXGBE_RXD_STAT_VP) {
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700000
argument|VLAN_INPUT_TAG_NEW(ifp, rxr->fmp, 					    (le16toh(cur->wb.upper.vlan)& 					    IXGBE_RX_DESC_SPECIAL_VLAN_MASK));
else|#
directive|else
argument|rxr->fmp->m_pkthdr.ether_vtag =                                             le16toh(cur->wb.upper.vlan);                                         rxr->fmp->m_flags |= M_VLANTAG;
endif|#
directive|endif
argument|} 				m = rxr->fmp; 				rxr->fmp = NULL; 				rxr->lmp = NULL; 			} 		} else { 			ifp->if_ierrors++; discard:
comment|/* Reuse loaded DMA map and just update mbuf chain */
argument|mp = rxr->rx_buffers[i].m_head; 			mp->m_len = mp->m_pkthdr.len = 			    (rxr->rx_buffers[i].bigbuf ? MJUMPAGESIZE:MCLBYTES); 			mp->m_data = mp->m_ext.ext_buf; 			mp->m_next = NULL; 			if (adapter->max_frame_size<= (MCLBYTES - ETHER_ALIGN)) 				m_adj(mp, ETHER_ALIGN); 			if (rxr->fmp != NULL) { 				m_freem(rxr->fmp); 				rxr->fmp = NULL; 				rxr->lmp = NULL; 			} 			m = NULL; 		}
comment|/* Zero out the receive descriptors status  */
argument|cur->wb.upper.status_error =
literal|0
argument|; 		bus_dmamap_sync(rxr->rxdma.dma_tag, rxr->rxdma.dma_map, 		    BUS_DMASYNC_PREREAD | BUS_DMASYNC_PREWRITE);  		rxr->last_cleaned = i;
comment|/* for updating tail */
argument|if (++i == adapter->num_rx_desc) 			i =
literal|0
argument|;
comment|/* Now send up to the stack */
argument|if (m != NULL) {                         rxr->next_to_check = i;                         (*ifp->if_input)(ifp, m);                         i = rxr->next_to_check;                 }
comment|/* Get next descriptor */
argument|cur =&rxr->rx_base[i]; 		staterr = cur->wb.upper.status_error; 	} 	rxr->next_to_check = i;
comment|/* Advance the IXGB's Receive Queue "Tail Pointer" */
argument|IXGBE_WRITE_REG(&adapter->hw, IXGBE_RDT(rxr->me), rxr->last_cleaned);  	if (!(staterr& IXGBE_RXD_STAT_DD)) 		return (
literal|0
argument|);  	return (
literal|1
argument|); }
comment|/*********************************************************************  *  *  Verify that the hardware indicated that the checksum is valid.  *  Inform the stack about the status of checksum so that stack  *  doesn't spend time verifying the checksum.  *  *********************************************************************/
argument|static void ixgbe_rx_checksum(struct adapter *adapter,     uint32_t staterr, struct mbuf * mp) { 	uint16_t status = (uint16_t) staterr; 	uint8_t  errors = (uint8_t) (staterr>>
literal|24
argument|);
comment|/* Not offloaded */
argument|if (status& IXGBE_RXD_STAT_IXSM) { 		mp->m_pkthdr.csum_flags =
literal|0
argument|; 		return; 	}  	if (status& IXGBE_RXD_STAT_IPCS) {
comment|/* Did it pass? */
argument|if (!(errors& IXGBE_RXD_ERR_IPE)) {
comment|/* IP Checksum Good */
argument|mp->m_pkthdr.csum_flags = CSUM_IP_CHECKED; 			mp->m_pkthdr.csum_flags |= CSUM_IP_VALID;  		} else 			mp->m_pkthdr.csum_flags =
literal|0
argument|; 	} 	if (status& IXGBE_RXD_STAT_L4CS) {
comment|/* Did it pass? */
argument|if (!(errors& IXGBE_RXD_ERR_TCPE)) { 			mp->m_pkthdr.csum_flags |= 				(CSUM_DATA_VALID | CSUM_PSEUDO_HDR); 			mp->m_pkthdr.csum_data = htons(
literal|0xffff
argument|); 		}  	} 	return; }   static void ixgbe_enable_hw_vlans(struct adapter *adapter) { 	uint32_t        ctrl;  	ixgbe_disable_intr(adapter); 	ctrl = IXGBE_READ_REG(&adapter->hw, IXGBE_VLNCTRL); 	ctrl |= IXGBE_VLNCTRL_VME; 	ctrl&= ~IXGBE_VLNCTRL_CFIEN; 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_VLNCTRL, ctrl); 	ixgbe_enable_intr(adapter);  	return; }   static void ixgbe_enable_intr(struct adapter *adapter) { 	u32 mask;
comment|/* With RSS set up what to auto clear */
argument|if (adapter->msix) { 		mask = IXGBE_EIMS_ENABLE_MASK; 		mask&= ~IXGBE_EIMS_OTHER; 		mask&= ~IXGBE_EIMS_LSC; 		IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIAC, mask); 	}  	mask = IXGBE_EIMS_ENABLE_MASK; 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMS, IXGBE_EIMS_ENABLE_MASK); 	IXGBE_WRITE_FLUSH(&adapter->hw);  	return; }  static void ixgbe_disable_intr(struct adapter *adapter) { 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC, ~
literal|0
argument|); 	return; }  u16 ixgbe_read_pci_cfg(struct ixgbe_hw *hw, u32 reg) { 	u16 value;  	value = pci_read_config(((struct ixgbe_osdep *)hw->back)->dev, 	    reg,
literal|2
argument|);  	return (value); }  static void ixgbe_set_ivar(struct adapter *adapter, u16 entry, u8 vector) { 	u32 ivar
argument_list|,
argument|index;  	vector |= IXGBE_IVAR_ALLOC_VAL; 	index = (entry>>
literal|2
argument|)&
literal|0x1F
argument|; 	ivar = IXGBE_READ_REG(&adapter->hw, IXGBE_IVAR(index)); 	ivar&= ~(
literal|0xFF
argument|<< (
literal|8
argument|* (entry&
literal|0x3
argument|))); 	ivar |= (vector<< (
literal|8
argument|* (entry&
literal|0x3
argument|))); 	IXGBE_WRITE_REG(&adapter->hw, IXGBE_IVAR(index), ivar); }  static void ixgbe_configure_ivars(struct adapter *adapter) { 	struct  tx_ring *txr = adapter->tx_rings; 	struct  rx_ring *rxr = adapter->rx_rings;          for (int i =
literal|0
argument|; i< adapter->num_rx_queues; i++, rxr++)                 ixgbe_set_ivar(adapter, IXGBE_IVAR_RX_QUEUE(i), rxr->msix);          for (int i =
literal|0
argument|; i< adapter->num_tx_queues; i++, txr++) 		ixgbe_set_ivar(adapter, IXGBE_IVAR_TX_QUEUE(i), txr->msix);
comment|/* For the Link interrupt */
argument|ixgbe_set_ivar(adapter, IXGBE_IVAR_OTHER_CAUSES_INDEX, adapter->linkvec); }
comment|/**********************************************************************  *  *  Update the board statistics counters.  *  **********************************************************************/
argument|static void ixgbe_update_stats_counters(struct adapter *adapter) { 	struct ifnet   *ifp; 	struct ixgbe_hw *hw =&adapter->hw; 	u64  good_rx
argument_list|,
argument|missed_rx;  	adapter->stats.crcerrs += IXGBE_READ_REG(hw, IXGBE_CRCERRS);  	good_rx = IXGBE_READ_REG(hw, IXGBE_GPRC); 	missed_rx  = IXGBE_READ_REG(hw, IXGBE_MPC(
literal|0
argument|)); 	missed_rx += IXGBE_READ_REG(hw, IXGBE_MPC(
literal|1
argument|)); 	missed_rx += IXGBE_READ_REG(hw, IXGBE_MPC(
literal|2
argument|)); 	missed_rx += IXGBE_READ_REG(hw, IXGBE_MPC(
literal|3
argument|)); 	missed_rx += IXGBE_READ_REG(hw, IXGBE_MPC(
literal|4
argument|)); 	missed_rx += IXGBE_READ_REG(hw, IXGBE_MPC(
literal|5
argument|)); 	missed_rx += IXGBE_READ_REG(hw, IXGBE_MPC(
literal|6
argument|)); 	missed_rx += IXGBE_READ_REG(hw, IXGBE_MPC(
literal|7
argument|));  	adapter->stats.gprc += (good_rx - missed_rx);          adapter->stats.mpc[
literal|0
argument|] += missed_rx; 	adapter->stats.gorc += IXGBE_READ_REG(hw, IXGBE_GORCH); 	adapter->stats.bprc += IXGBE_READ_REG(hw, IXGBE_BPRC); 	adapter->stats.mprc += IXGBE_READ_REG(hw, IXGBE_MPRC);
comment|/* 	 * Workaround: mprc hardware is incorrectly counting 	 * broadcasts, so for now we subtract those. 	 */
argument|adapter->stats.mprc -= adapter->stats.bprc; 	adapter->stats.roc += IXGBE_READ_REG(hw, IXGBE_ROC); 	adapter->stats.prc64 += IXGBE_READ_REG(hw, IXGBE_PRC64); 	adapter->stats.prc127 += IXGBE_READ_REG(hw, IXGBE_PRC127); 	adapter->stats.prc255 += IXGBE_READ_REG(hw, IXGBE_PRC255); 	adapter->stats.prc511 += IXGBE_READ_REG(hw, IXGBE_PRC511); 	adapter->stats.prc1023 += IXGBE_READ_REG(hw, IXGBE_PRC1023); 	adapter->stats.prc1522 += IXGBE_READ_REG(hw, IXGBE_PRC1522);  	adapter->stats.rlec += IXGBE_READ_REG(hw, IXGBE_RLEC); 	adapter->stats.lxonrxc += IXGBE_READ_REG(hw, IXGBE_LXONRXC); 	adapter->stats.lxontxc += IXGBE_READ_REG(hw, IXGBE_LXONTXC); 	adapter->stats.lxoffrxc += IXGBE_READ_REG(hw, IXGBE_LXOFFRXC); 	adapter->stats.lxofftxc += IXGBE_READ_REG(hw, IXGBE_LXOFFTXC); 	adapter->stats.ruc += IXGBE_READ_REG(hw, IXGBE_RUC); 	adapter->stats.gptc += IXGBE_READ_REG(hw, IXGBE_GPTC); 	adapter->stats.gotc += IXGBE_READ_REG(hw, IXGBE_GOTCH); 	adapter->stats.rnbc[
literal|0
argument|] += IXGBE_READ_REG(hw, IXGBE_RNBC(
literal|0
argument|)); 	adapter->stats.ruc += IXGBE_READ_REG(hw, IXGBE_RUC); 	adapter->stats.rfc += IXGBE_READ_REG(hw, IXGBE_RFC); 	adapter->stats.rjc += IXGBE_READ_REG(hw, IXGBE_RJC); 	adapter->stats.tor += IXGBE_READ_REG(hw, IXGBE_TORH); 	adapter->stats.gotc += IXGBE_READ_REG(hw, IXGBE_GOTCH); 	adapter->stats.tpr += IXGBE_READ_REG(hw, IXGBE_TPR); 	adapter->stats.ptc64 += IXGBE_READ_REG(hw, IXGBE_PTC64); 	adapter->stats.ptc127 += IXGBE_READ_REG(hw, IXGBE_PTC127); 	adapter->stats.ptc255 += IXGBE_READ_REG(hw, IXGBE_PTC255); 	adapter->stats.ptc511 += IXGBE_READ_REG(hw, IXGBE_PTC511); 	adapter->stats.ptc1023 += IXGBE_READ_REG(hw, IXGBE_PTC1023); 	adapter->stats.ptc1522 += IXGBE_READ_REG(hw, IXGBE_PTC1522); 	adapter->stats.mptc += IXGBE_READ_REG(hw, IXGBE_MPTC); 	adapter->stats.bptc += IXGBE_READ_REG(hw, IXGBE_BPTC);  	ifp = adapter->ifp;
comment|/* Fill out the OS statistics structure */
argument|ifp->if_ipackets = adapter->stats.gprc; 	ifp->if_opackets = adapter->stats.gptc; 	ifp->if_ibytes = adapter->stats.gorc; 	ifp->if_obytes = adapter->stats.gotc; 	ifp->if_imcasts = adapter->stats.mprc; 	ifp->if_collisions =
literal|0
argument|;
comment|/* Rx Errors */
argument|ifp->if_ierrors = 		adapter->stats.mpc[
literal|0
argument|] + 		adapter->stats.crcerrs + 		adapter->stats.rlec;  }
comment|/**********************************************************************  *  *  This routine is called only when ixgbe_display_debug_stats is enabled.  *  This routine provides a way to take a look at important statistics  *  maintained by the driver and hardware.  *  **********************************************************************/
argument|static void ixgbe_print_hw_stats(struct adapter * adapter) { 	device_t dev = adapter->dev;   	device_printf(dev,
literal|"Tx Descriptors not Avail1 = %lu\n"
argument|, 	       adapter->no_tx_desc_avail1); 	device_printf(dev,
literal|"Tx Descriptors not Avail2 = %lu\n"
argument|, 	       adapter->no_tx_desc_avail2); 	device_printf(dev,
literal|"Std Mbuf Failed = %lu\n"
argument|, 	       adapter->mbuf_alloc_failed); 	device_printf(dev,
literal|"Std Cluster Failed = %lu\n"
argument|, 	       adapter->mbuf_cluster_failed);  	device_printf(dev,
literal|"Missed Packets = %llu\n"
argument|, 	       (long long)adapter->stats.mpc[
literal|0
argument|]); 	device_printf(dev,
literal|"Receive length errors = %llu\n"
argument|, 	       ((long long)adapter->stats.roc + 	       (long long)adapter->stats.ruc)); 	device_printf(dev,
literal|"Crc errors = %llu\n"
argument|, 	       (long long)adapter->stats.crcerrs); 	device_printf(dev,
literal|"Driver dropped packets = %lu\n"
argument|, 	       adapter->dropped_pkts); 	device_printf(dev,
literal|"watchdog timeouts = %ld\n"
argument|, 	       adapter->watchdog_events);  	device_printf(dev,
literal|"XON Rcvd = %llu\n"
argument|, 	       (long long)adapter->stats.lxonrxc); 	device_printf(dev,
literal|"XON Xmtd = %llu\n"
argument|, 	       (long long)adapter->stats.lxontxc); 	device_printf(dev,
literal|"XOFF Rcvd = %llu\n"
argument|, 	       (long long)adapter->stats.lxoffrxc); 	device_printf(dev,
literal|"XOFF Xmtd = %llu\n"
argument|, 	       (long long)adapter->stats.lxofftxc);  	device_printf(dev,
literal|"Total Packets Rcvd = %llu\n"
argument|, 	       (long long)adapter->stats.tpr); 	device_printf(dev,
literal|"Good Packets Rcvd = %llu\n"
argument|, 	       (long long)adapter->stats.gprc); 	device_printf(dev,
literal|"Good Packets Xmtd = %llu\n"
argument|, 	       (long long)adapter->stats.gptc); 	device_printf(dev,
literal|"TSO Transmissions = %lu\n"
argument|, 	       adapter->tso_tx);  	return; }
comment|/**********************************************************************  *  *  This routine is called only when em_display_debug_stats is enabled.  *  This routine provides a way to take a look at important statistics  *  maintained by the driver and hardware.  *  **********************************************************************/
argument|static void ixgbe_print_debug_info(struct adapter *adapter) { 	device_t dev = adapter->dev; 	struct rx_ring *rxr = adapter->rx_rings; 	struct tx_ring *txr = adapter->tx_rings; 	struct ixgbe_hw *hw =&adapter->hw;
ifdef|#
directive|ifdef
name|IXGBE_DEBUG
argument|uint8_t *hw_addr = adapter->hw.hw_addr;
comment|/* 	 * This is not normally that useful, turn it on or 	 * add to as needed... 	 */
argument|device_printf(dev,
literal|"Adapter hardware address = %p \n"
argument|, hw_addr); 	device_printf(dev,
literal|"TXDCTL = 0x%x RXCTRL = 0x%x \n"
argument|, 	    IXGBE_READ_REG(hw, IXGBE_TXDCTL(
literal|0
argument|)), 	    IXGBE_READ_REG(hw, IXGBE_RXCTRL));   	device_printf(dev,
literal|"RXDCTL(0) = 0x%x RXDCTL(1) = 0x%x"
literal|" RXCTRL(2) = 0x%x \n"
argument|, 	    IXGBE_READ_REG(hw, IXGBE_RXDCTL(
literal|0
argument|)), 	    IXGBE_READ_REG(hw, IXGBE_RXDCTL(
literal|1
argument|)), 	    IXGBE_READ_REG(hw, IXGBE_RXDCTL(
literal|2
argument|))); 	device_printf(dev,
literal|"SRRCTL(0) = 0x%x SRRCTL(1) = 0x%x"
literal|" SRRCTL(2) = 0x%x \n"
argument|, 	    IXGBE_READ_REG(hw, IXGBE_SRRCTL(
literal|0
argument|)), 	    IXGBE_READ_REG(hw, IXGBE_SRRCTL(
literal|1
argument|)), 	    IXGBE_READ_REG(hw, IXGBE_SRRCTL(
literal|2
argument|)));
endif|#
directive|endif
argument|device_printf(dev,
literal|"Queue(0) tdh = %d, hw tdt = %d\n"
argument|, 	    IXGBE_READ_REG(hw, IXGBE_TDH(
literal|0
argument|)), 	    IXGBE_READ_REG(hw, IXGBE_TDT(
literal|0
argument|)));  	for (int i =
literal|0
argument|; i< adapter->num_rx_queues; i++) { 		device_printf(dev,
literal|"Queue[%d]: rdh = %d, hw rdt = %d\n"
argument|, 	    	    i, IXGBE_READ_REG(hw, IXGBE_RDH(i)), 	    	    IXGBE_READ_REG(hw, IXGBE_RDT(i))); 	}  	device_printf(dev,
literal|"Error Byte Count = %u \n"
argument|, 	    IXGBE_READ_REG(hw, IXGBE_ERRBC));  	for (int i =
literal|0
argument|; i< adapter->num_rx_queues; i++, rxr++) { 		device_printf(dev,
literal|"Queue %d Packets Received: %lu\n"
argument|, 	    	    rxr->me, (long)rxr->packet_count); 		device_printf(dev,
literal|"Queue %d Bytes Received: %lu\n"
argument|, 	    	    rxr->me, (long)rxr->byte_count); 		device_printf(dev,
literal|"RX Queue %d IRQ Handled: %lu\n"
argument|, 	    	    rxr->me, (long)rxr->rx_irq); 	}  	device_printf(dev,
literal|"TX Queue IRQ Handled: %lu\n"
argument|,     	    (long)txr->tx_irq); 	device_printf(dev,
literal|"Link IRQ Handled: %lu\n"
argument|,     	    (long)adapter->link_irq); 	return; }  static int ixgbe_sysctl_stats(SYSCTL_HANDLER_ARGS) { 	int             error; 	int             result; 	struct adapter *adapter;  	result = -
literal|1
argument|; 	error = sysctl_handle_int(oidp,&result,
literal|0
argument|, req);  	if (error || !req->newptr) 		return (error);  	if (result ==
literal|1
argument|) { 		adapter = (struct adapter *) arg1; 		ixgbe_print_hw_stats(adapter); 	} 	return error; }  static int ixgbe_sysctl_debug(SYSCTL_HANDLER_ARGS) { 	int error
argument_list|,
argument|result; 	struct adapter *adapter;  	result = -
literal|1
argument|; 	error = sysctl_handle_int(oidp,&result,
literal|0
argument|, req);  	if (error || !req->newptr) 		return (error);  	if (result ==
literal|1
argument|) { 		adapter = (struct adapter *) arg1; 		ixgbe_print_debug_info(adapter); 	} 	return error; }
comment|/* ** Set flow control using sysctl: ** Flow control values: ** 	0 - off **	1 - rx pause **	2 - tx pause **	3 - full */
argument|static int ixgbe_set_flowcntl(SYSCTL_HANDLER_ARGS) { 	int error; 	struct adapter *adapter;  	error = sysctl_handle_int(oidp,&ixgbe_flow_control,
literal|0
argument|, req);  	if (error) 		return (error);  	adapter = (struct adapter *) arg1; 	switch (ixgbe_flow_control) { 		case ixgbe_fc_rx_pause: 		case ixgbe_fc_tx_pause: 		case ixgbe_fc_full: 			adapter->hw.fc.original_type = ixgbe_flow_control; 			break; 		case ixgbe_fc_none: 		default: 			adapter->hw.fc.original_type = ixgbe_fc_none; 	}  	ixgbe_setup_fc(&adapter->hw,
literal|0
argument|); 	return error; }  static void ixgbe_add_rx_process_limit(struct adapter *adapter, const char *name,         const char *description, int *limit, int value) {         *limit = value;         SYSCTL_ADD_INT(device_get_sysctl_ctx(adapter->dev),             SYSCTL_CHILDREN(device_get_sysctl_tree(adapter->dev)),             OID_AUTO, name, CTLTYPE_INT|CTLFLAG_RW, limit, value, description); }
ifndef|#
directive|ifndef
name|NO_82598_A0_SUPPORT
comment|/*  * A0 Workaround: invert descriptor for hardware  */
argument|void desc_flip(void *desc) {         struct dhack {u32 a1; u32 a2; u32 b1; u32 b2;};         struct dhack *d;          d = (struct dhack *)desc;         d->a1 = ~(d->a1);         d->a2 = ~(d->a2);         d->b1 = ~(d->b1);         d->b2 = ~(d->b2);         d->b2&=
literal|0xFFFFFFF0
argument|;         d->b1&= ~IXGBE_ADVTXD_DCMD_RS; }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

