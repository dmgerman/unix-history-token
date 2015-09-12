begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup grouppcie PCI Express Controller  *  @{  * @section overview Overview  * This header file provide API for the HAL driver of the pcie port, the driver  * provides the following functionalities:  * - Port initialization  * - Link operation  * - Interrupts transactions generation (Endpoint mode).  * - Configuration Access management functions  * - Internal Translation Unit programming  *  * This API does not provide the following:  * - PCIe transactions generation and reception (except interrupts as mentioned  *   above) as this functionality is done by the port without need for sw  *   intervention.  * - Configuration Access: those transactions are generated automatically by  *   the port (ECAM or ATU mode) when the CPU issues memory transaction  *   through the fabric toward the PCIe port. This API provides management  *   function for controlling the Configuration Access type and bus destination  * - Interrupt Handling.  * - Message Generation: common used messages are automatically generated, also,  *   the ATU generic mechanism for generating various kind of messages.  * - PCIe Port Management: both link and port power management features can be  *   managed using the PCI/PCIe standard power management and PCIe capabilities  *   registers.  * - PCIe link and protocol error handling: the feature can be managed using  *   the Advanced Error Handling PCIe capability registers.  *  * @section flows Software Flows  * @subsection init Initialization  *   - allocation and set zeros al_pcie_port and al_pcie_pf structures handles  *   - call al_pcie_port_handle_init() with pointer to the allocated  *     al_pcie_port handle, address of the port internal registers space, and  *     port id.  *   - call al_pcie_pf_handle_init() with pointer to the al_pcie_port handle  *     and pf_number.  *   - set the port mode, End-Point or Root-Compex (default).  *   - set number of lanes connected to the controller.  *   - enable the controller using the al_pcie_port_enable(). note that this  *     function expect the virtual address of the PBS Functional Registers.  *   - wait for 2000 South-bridge cycles.  *   - prepare al_pcie_port_config_params and al_pcie_pf_config_params  *     structures depending on chip, board and system configuration.  *     for example, when using the port as root complex, the operating_mode  *     field should be set to AL_PCIE_OPERATING_MODE_RC. In this example we  *     prepare the following configuration:  *     For port configuration  *     - Root Complex mode  *     - Set the Max Link Speed to Gen2  *     - Set the max lanes width to 2 (x2)  *     - Disable reversal mode  *     - Enable Snoops to support I/O Hardware cache coherency  *     - Enable pcie core RAM parity  *     - Enable pcie core AXI parity  *     - Keep transaction layer default credits  *     For pf configuration  *     - No EP parameters  *     - No SR-IOV parameters  *     so the structures we prepare:  *     @code  *     - struct al_pcie_link_params link_params = {  *		AL_PCIE_LINK_SPEED_GEN2,  *		AL_FALSE,	// disable reversal mode  *		AL_PCIE_MPS_DEFAULT};  *  *     - struct al_pcie_port_config_params config_params = {  *&link_params,  *		AL_TRUE, // enable Snoop for inbound memory transactions  *		AL_TRUE, // enable pcie port RAM parity  *		AL_TRUE, // enable pcie port AXI parity  *		NULL, // use default latency/replay timers  *		NULL, // use default gen2 pipe params  *		NULL, // gen3_params not needed when max speed set to Gen2  *		NULL, // don't change TL credits  *		NULL, // end point params not needed  *		AL_FALSE, //no fast link  *		AL_FALSE};	//return 0xFFFFFFFF for read transactions with  *				//pci target error  *	@endcode  *	- now call al_pcie_port_config() with pcie_port and port_config_params  * @subsection link-init Link Initialization  *  - once the port configured, we can start PCIe link:  *  - call al_pcie_link_start()  *  - call al_pcie_link_up_wait()  *  - allocate al_pcie_link_status struct and call al_pcie_link_status() and  *    check the link is established.  *  *  @subsection  cap Configuration Access Preparation  *  - Once the link is established, we can prepare the port for pci  *  configuration access, this stage requires system knowledge about the PCI  *  buses enumeration. For example, if 5 buses were discovered on previously  *  scanned root complex port, then we should start enumeration from bus 5 (PCI  *  secondary bus), the sub-ordinary bus will be temporarily set to maximum  *  value (255) until the scan process under this bus is finished, then it will  *  updated to the maximum bus value found. So we use the following sequence:  *  - call al_pcie_secondary_bus_set() with sec-bus = 5  *  - call al_pcie_subordinary_bus_set() with sub-bus = 255  *  *  @subsection cfg Configuration (Cfg) Access Generation  *  - we assume using ECAM method, in this method, the software issues pcie Cfg  *  access by accessing the ECAM memory space of the pcie port. For example, to  *  issue 4 byte Cfg Read from bus B, Device D, Function F and register R, the  *  software issues 4 byte read access to the following physical address  *  ECAM base address of the port + (B<< 20) + (D<< 15) + (F<< 12) + R.  *  But, as the default size of the ECAM address space is less than  *  needed full range (256MB), we modify the target_bus value prior to Cfg  *  access in order make the port generate Cfg access with bus value set to the  *  value of the target_bus rather than bits 27:20 of the physical address.  *  - call al_pcie_target_bus_set() with target_bus set to the required bus of  *   the next Cfg access to be issued, mask_target_bus will be set to 0xff.  *   no need to call that function if the next Cfg access bus equals to the last  *   value set to target_bus.  *  *      @file  al_hal_pcie.h  *      @brief HAL Driver Header for the Annapurna Labs PCI Express port.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AL_HAL_PCIE_H_
end_ifndef

begin_define
define|#
directive|define
name|_AL_HAL_PCIE_H_
end_define

begin_include
include|#
directive|include
file|"al_hal_common.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_pcie_regs.h"
end_include

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/********************************* Constants **********************************/
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/** Inbound header credits sum - rev 0/1/2 */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_REV_1_2_IB_HCRD_SUM
value|97
end_define

begin_comment
comment|/** Inbound header credits sum - rev 3 */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_REV3_IB_HCRD_SUM
value|259
end_define

begin_comment
comment|/** Number of extended registers */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_EX_REGS_NUM
value|40
end_define

begin_comment
comment|/*******************************************************************************  * PCIe AER uncorrectable error bits  * To be used with the following functions:  * - al_pcie_aer_config  * - al_pcie_aer_uncorr_get_and_clear  ******************************************************************************/
end_comment

begin_comment
comment|/** Data Link Protocol Error */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_DLP_ERR
value|AL_BIT(4)
end_define

begin_comment
comment|/** Poisoned TLP */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_POISIONED_TLP
value|AL_BIT(12)
end_define

begin_comment
comment|/** Flow Control Protocol Error */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_FLOW_CTRL_ERR
value|AL_BIT(13)
end_define

begin_comment
comment|/** Completion Timeout */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_COMPL_TO
value|AL_BIT(14)
end_define

begin_comment
comment|/** Completer Abort */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_COMPL_ABT
value|AL_BIT(15)
end_define

begin_comment
comment|/** Unexpected Completion */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_UNEXPCTED_COMPL
value|AL_BIT(16)
end_define

begin_comment
comment|/** Receiver Overflow */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_RCV_OVRFLW
value|AL_BIT(17)
end_define

begin_comment
comment|/** Malformed TLP */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_MLFRM_TLP
value|AL_BIT(18)
end_define

begin_comment
comment|/** ECRC Error */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_ECRC_ERR
value|AL_BIT(19)
end_define

begin_comment
comment|/** Unsupported Request Error */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_UNSUPRT_REQ_ERR
value|AL_BIT(20)
end_define

begin_comment
comment|/** Uncorrectable Internal Error */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_INT_ERR
value|AL_BIT(22)
end_define

begin_comment
comment|/** AtomicOp Egress Blocked */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_UNCORR_ATOMIC_EGRESS_BLK
value|AL_BIT(24)
end_define

begin_comment
comment|/*******************************************************************************  * PCIe AER correctable error bits  * To be used with the following functions:  * - al_pcie_aer_config  * - al_pcie_aer_corr_get_and_clear  ******************************************************************************/
end_comment

begin_comment
comment|/** Receiver Error */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_CORR_RCV_ERR
value|AL_BIT(0)
end_define

begin_comment
comment|/** Bad TLP */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_CORR_BAD_TLP
value|AL_BIT(6)
end_define

begin_comment
comment|/** Bad DLLP */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_CORR_BAD_DLLP
value|AL_BIT(7)
end_define

begin_comment
comment|/** REPLAY_NUM Rollover */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_CORR_RPLY_NUM_ROLL_OVR
value|AL_BIT(8)
end_define

begin_comment
comment|/** Replay Timer Timeout */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_CORR_RPLY_TMR_TO
value|AL_BIT(12)
end_define

begin_comment
comment|/** Advisory Non-Fatal Error */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_CORR_ADVISORY_NON_FTL_ERR
value|AL_BIT(13)
end_define

begin_comment
comment|/** Corrected Internal Error */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_CORR_INT_ERR
value|AL_BIT(14)
end_define

begin_comment
comment|/** The AER erroneous TLP header length [num DWORDs] */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_ERR_TLP_HDR_NUM_DWORDS
value|4
end_define

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/************************* Data Structures and Types **************************/
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/**  * al_pcie_ib_hcrd_config: data structure internally used in order to config  * inbound posted/non-posted parameters.  * Note: it's required to have this structure in pcie_port handle since it has  *	 a state (required/not-required) which is determined by outbound  *	 outstanding configuration  */
end_comment

begin_struct
struct|struct
name|al_pcie_ib_hcrd_config
block|{
comment|/* Internally used - see 'al_pcie_ib_hcrd_os_ob_reads_config' */
name|unsigned
name|int
name|nof_np_hdr
decl_stmt|;
comment|/* Internally used - see 'al_pcie_ib_hcrd_os_ob_reads_config' */
name|unsigned
name|int
name|nof_p_hdr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The Max Payload Size. Measured in bytes.  *   DEFAULT: do not change the current MPS  */
end_comment

begin_enum
enum|enum
name|al_pcie_max_payload_size
block|{
name|AL_PCIE_MPS_DEFAULT
block|,
name|AL_PCIE_MPS_128
init|=
literal|0
block|,
name|AL_PCIE_MPS_256
init|=
literal|1
block|,
name|AL_PCIE_MPS_512
init|=
literal|2
block|,
name|AL_PCIE_MPS_1024
init|=
literal|3
block|,
name|AL_PCIE_MPS_2048
init|=
literal|4
block|,
name|AL_PCIE_MPS_4096
init|=
literal|5
block|, }
enum|;
end_enum

begin_comment
comment|/**  * al_pcie_port: data structure used by the HAL to handle a specific pcie port.  * this structure is allocated and set to zeros by the upper layer, then it is  * initialized by the al_pcie_port_handle_init() that should be called before any  * other function of this API. later, this handle passed to the API functions.  */
end_comment

begin_struct
struct|struct
name|al_pcie_port
block|{
name|void
name|__iomem
modifier|*
name|pcie_reg_base
decl_stmt|;
name|struct
name|al_pcie_regs
name|regs_ptrs
decl_stmt|;
name|struct
name|al_pcie_regs
modifier|*
name|regs
decl_stmt|;
name|uint32_t
modifier|*
name|ex_regs_ptrs
index|[
name|AL_PCIE_EX_REGS_NUM
index|]
decl_stmt|;
name|void
modifier|*
name|ex_regs
decl_stmt|;
name|void
name|__iomem
modifier|*
name|pbs_regs
decl_stmt|;
comment|/* Revision ID */
name|uint8_t
name|rev_id
decl_stmt|;
name|unsigned
name|int
name|port_id
decl_stmt|;
name|uint8_t
name|max_lanes
decl_stmt|;
name|uint8_t
name|max_num_of_pfs
decl_stmt|;
comment|/* Internally used */
name|struct
name|al_pcie_ib_hcrd_config
name|ib_hcrd_config
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * al_pcie_pf: the pf handle, a data structure used to handle PF specific  * functionality. Initialized using "al_pcie_pf_handle_init()"  */
end_comment

begin_struct
struct|struct
name|al_pcie_pf
block|{
name|unsigned
name|int
name|pf_num
decl_stmt|;
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Operating mode (endpoint, root complex) */
end_comment

begin_enum
enum|enum
name|al_pcie_operating_mode
block|{
name|AL_PCIE_OPERATING_MODE_EP
block|,
name|AL_PCIE_OPERATING_MODE_RC
block|,
name|AL_PCIE_OPERATING_MODE_UNKNOWN
block|}
enum|;
end_enum

begin_comment
comment|/* The maximum link speed, measured GT/s (Giga transfer / second)  *   DEFAULT: do not change the current speed  *   GEN1: 2.5 GT/s  *   GEN2: 5 GT/s  *   GEN3: 8GT/s  *  *   Note: The values of this enumerator are important for proper behavior  */
end_comment

begin_enum
enum|enum
name|al_pcie_link_speed
block|{
name|AL_PCIE_LINK_SPEED_DEFAULT
block|,
name|AL_PCIE_LINK_SPEED_GEN1
init|=
literal|1
block|,
name|AL_PCIE_LINK_SPEED_GEN2
init|=
literal|2
block|,
name|AL_PCIE_LINK_SPEED_GEN3
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/** PCIe capabilities that supported by a specific port */
end_comment

begin_struct
struct|struct
name|al_pcie_max_capability
block|{
name|al_bool
name|end_point_mode_supported
decl_stmt|;
name|al_bool
name|root_complex_mode_supported
decl_stmt|;
name|enum
name|al_pcie_link_speed
name|max_speed
decl_stmt|;
name|uint8_t
name|max_lanes
decl_stmt|;
name|al_bool
name|reversal_supported
decl_stmt|;
name|uint8_t
name|atu_regions_num
decl_stmt|;
name|uint32_t
name|atu_min_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe link related parameters */
end_comment

begin_struct
struct|struct
name|al_pcie_link_params
block|{
name|enum
name|al_pcie_link_speed
name|max_speed
decl_stmt|;
name|al_bool
name|enable_reversal
decl_stmt|;
name|enum
name|al_pcie_max_payload_size
name|max_payload_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe gen2 link parameters */
end_comment

begin_struct
struct|struct
name|al_pcie_gen2_params
block|{
name|al_bool
name|tx_swing_low
decl_stmt|;
comment|/* set tx swing low when true, and tx swing full when false */
name|al_bool
name|tx_compliance_receive_enable
decl_stmt|;
name|al_bool
name|set_deemphasis
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe gen 3 standard per lane equalization parameters */
end_comment

begin_struct
struct|struct
name|al_pcie_gen3_lane_eq_params
block|{
name|uint8_t
name|downstream_port_transmitter_preset
decl_stmt|;
name|uint8_t
name|downstream_port_receiver_preset_hint
decl_stmt|;
name|uint8_t
name|upstream_port_transmitter_preset
decl_stmt|;
name|uint8_t
name|upstream_port_receiver_preset_hint
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe gen 3 equalization parameters */
end_comment

begin_struct
struct|struct
name|al_pcie_gen3_params
block|{
name|al_bool
name|perform_eq
decl_stmt|;
name|al_bool
name|interrupt_enable_on_link_eq_request
decl_stmt|;
name|struct
name|al_pcie_gen3_lane_eq_params
modifier|*
name|eq_params
decl_stmt|;
comment|/* array of lanes params */
name|int
name|eq_params_elements
decl_stmt|;
comment|/* number of elements in the eq_params array */
name|al_bool
name|eq_disable
decl_stmt|;
comment|/* disables the equalization feature */
name|al_bool
name|eq_phase2_3_disable
decl_stmt|;
comment|/* Equalization Phase 2 and Phase 3 */
comment|/* Disable (RC mode only) */
name|uint8_t
name|local_lf
decl_stmt|;
comment|/* Full Swing (FS) Value for Gen3 Transmit Equalization */
comment|/* Value Range: 12 through 63 (decimal).*/
name|uint8_t
name|local_fs
decl_stmt|;
comment|/* Low Frequency (LF) Value for Gen3 Transmit Equalization */
block|}
struct|;
end_struct

begin_comment
comment|/** Transport Layer credits parameters */
end_comment

begin_struct
struct|struct
name|al_pcie_tl_credits_params
block|{ }
struct|;
end_struct

begin_comment
comment|/** Various configuration features */
end_comment

begin_struct
struct|struct
name|al_pcie_features
block|{
comment|/** 	 * Enable MSI fix from the SATA to the PCIe EP 	 * Only valid for port 0, when enabled as EP 	 */
name|al_bool
name|sata_ep_msi_fix
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Inbound posted/non-posted header credits and outstanding outbound reads  * completion header configuration  *  * Constraints:  * - nof_cpl_hdr + nof_np_hdr + nof_p_hdr ==  *			AL_PCIE_REV_1_2_IB_HCRD_SUM/AL_PCIE_REV3_IB_HCRD_SUM  * - nof_cpl_hdr> 0  * - nof_p_hdr> 0  * - nof_np_hdr> 0  */
end_comment

begin_struct
struct|struct
name|al_pcie_ib_hcrd_os_ob_reads_config
block|{
comment|/** Max number of outstanding outbound reads */
name|uint8_t
name|nof_outstanding_ob_reads
decl_stmt|;
comment|/** 	 * This value set the possible outstanding headers CMPLs , the core 	 * can get (the core always advertise infinite credits for CMPLs). 	 */
name|unsigned
name|int
name|nof_cpl_hdr
decl_stmt|;
comment|/** 	 * This value set the possible outstanding headers reads (non-posted 	 * transactions), the core can get  (it set the value in the init FC 	 * process). 	 */
name|unsigned
name|int
name|nof_np_hdr
decl_stmt|;
comment|/** 	 * This value set the possible outstanding headers writes (posted 	 * transactions), the core can get  (it set the value in the init FC 	 * process). 	 */
name|unsigned
name|int
name|nof_p_hdr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe Ack/Nak Latency and Replay timers */
end_comment

begin_struct
struct|struct
name|al_pcie_latency_replay_timers
block|{
name|uint16_t
name|round_trip_lat_limit
decl_stmt|;
name|uint16_t
name|replay_timer_limit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SRIS KP counter values */
end_comment

begin_struct
struct|struct
name|al_pcie_sris_params
block|{
comment|/** set to AL_TRUE to use defaults and ignore the other parameters */
name|al_bool
name|use_defaults
decl_stmt|;
name|uint16_t
name|kp_counter_gen3
decl_stmt|;
comment|/* only for Gen3 */
name|uint16_t
name|kp_counter_gen21
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Relaxed ordering params */
end_comment

begin_struct
struct|struct
name|al_pcie_relaxed_ordering_params
block|{
name|al_bool
name|enable_tx_relaxed_ordering
decl_stmt|;
name|al_bool
name|enable_rx_relaxed_ordering
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe port configuration parameters  * This structure includes the parameters that the HAL should apply to the port  * (by al_pcie_port_config()).  * The fields that are pointers (e.g. link_params) can be set to NULL, in that  * case, the al_pcie_port_config() will keep the current HW settings.  */
end_comment

begin_struct
struct|struct
name|al_pcie_port_config_params
block|{
name|struct
name|al_pcie_link_params
modifier|*
name|link_params
decl_stmt|;
name|al_bool
name|enable_axi_snoop
decl_stmt|;
name|al_bool
name|enable_ram_parity_int
decl_stmt|;
name|al_bool
name|enable_axi_parity_int
decl_stmt|;
name|struct
name|al_pcie_latency_replay_timers
modifier|*
name|lat_rply_timers
decl_stmt|;
name|struct
name|al_pcie_gen2_params
modifier|*
name|gen2_params
decl_stmt|;
name|struct
name|al_pcie_gen3_params
modifier|*
name|gen3_params
decl_stmt|;
name|struct
name|al_pcie_tl_credits_params
modifier|*
name|tl_credits
decl_stmt|;
name|struct
name|al_pcie_features
modifier|*
name|features
decl_stmt|;
comment|/* Sets all internal timers to Fast Mode for speeding up simulation.*/
name|al_bool
name|fast_link_mode
decl_stmt|;
comment|/* 	 * when true, the PCI unit will return Slave Error/Decoding Error to the master unit in case 	 * of error. when false, the value 0xFFFFFFFF will be returned without error indication. 	 */
name|al_bool
name|enable_axi_slave_err_resp
decl_stmt|;
name|struct
name|al_pcie_sris_params
modifier|*
name|sris_params
decl_stmt|;
name|struct
name|al_pcie_relaxed_ordering_params
modifier|*
name|relaxed_ordering_params
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** BAR register configuration parameters (Endpoint Mode only) */
end_comment

begin_struct
struct|struct
name|al_pcie_ep_bar_params
block|{
name|al_bool
name|enable
decl_stmt|;
name|al_bool
name|memory_space
decl_stmt|;
comment|/**< memory or io */
name|al_bool
name|memory_64_bit
decl_stmt|;
comment|/**< is memory space is 64 bit */
name|al_bool
name|memory_is_prefetchable
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
comment|/* the bar size in bytes */
block|}
struct|;
end_struct

begin_comment
comment|/** PF config params (EP mode only) */
end_comment

begin_struct
struct|struct
name|al_pcie_pf_config_params
block|{
name|al_bool
name|cap_d1_d3hot_dis
decl_stmt|;
name|al_bool
name|cap_flr_dis
decl_stmt|;
name|al_bool
name|cap_aspm_dis
decl_stmt|;
name|al_bool
name|bar_params_valid
decl_stmt|;
name|struct
name|al_pcie_ep_bar_params
name|bar_params
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|al_pcie_ep_bar_params
name|exp_bar_params
decl_stmt|;
comment|/* expansion ROM BAR*/
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe link status */
end_comment

begin_struct
struct|struct
name|al_pcie_link_status
block|{
name|al_bool
name|link_up
decl_stmt|;
name|enum
name|al_pcie_link_speed
name|speed
decl_stmt|;
name|uint8_t
name|lanes
decl_stmt|;
name|uint8_t
name|ltssm_state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe lane status */
end_comment

begin_struct
struct|struct
name|al_pcie_lane_status
block|{
name|al_bool
name|is_reset
decl_stmt|;
name|enum
name|al_pcie_link_speed
name|requested_speed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIe MSIX capability configuration parameters */
end_comment

begin_struct
struct|struct
name|al_pcie_msix_params
block|{
name|uint16_t
name|table_size
decl_stmt|;
name|uint16_t
name|table_offset
decl_stmt|;
name|uint8_t
name|table_bar
decl_stmt|;
name|uint16_t
name|pba_offset
decl_stmt|;
name|uint16_t
name|pba_bar
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** PCIE AER capability parameters */
end_comment

begin_struct
struct|struct
name|al_pcie_aer_params
block|{
comment|/** ECRC Generation Enable */
name|al_bool
name|ecrc_gen_en
decl_stmt|;
comment|/** ECRC Check Enable */
name|al_bool
name|ecrc_chk_en
decl_stmt|;
comment|/** 	 * Enabled reporting of correctable errors (bit mask) 	 * See 'AL_PCIE_AER_CORR_*' for details 	 * 0 - no reporting at all 	 */
name|unsigned
name|int
name|enabled_corr_err
decl_stmt|;
comment|/** 	 * Enabled reporting of non-fatal uncorrectable errors (bit mask) 	 * See 'AL_PCIE_AER_UNCORR_*' for details 	 * 0 - no reporting at all 	 */
name|unsigned
name|int
name|enabled_uncorr_non_fatal_err
decl_stmt|;
comment|/** 	 * Enabled reporting of fatal uncorrectable errors (bit mask) 	 * See 'AL_PCIE_AER_UNCORR_*' for details 	 * 0 - no reporting at all 	 */
name|unsigned
name|int
name|enabled_uncorr_fatal_err
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/********************************** PCIe API **********************************/
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/*************************** PCIe Initialization API **************************/
end_comment

begin_comment
comment|/**  * Initializes a PCIe port handle structure.  *  * @param   pcie_port		an allocated, non-initialized instance.  * @param   pcie_reg_base	the virtual base address of the port internal  *				registers  * @param   pbs_reg_base	the virtual base address of the pbs functional  *				registers  * @param   port_id		the port id (used mainly for debug messages)  *  * @return 0 if no error found.  */
end_comment

begin_function_decl
name|int
name|al_pcie_port_handle_init
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|void
name|__iomem
modifier|*
name|pcie_reg_base
parameter_list|,
name|void
name|__iomem
modifier|*
name|pbs_reg_base
parameter_list|,
name|unsigned
name|int
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initializes a PCIe pf handle structure  * @param  pcie_pf   an allocated, non-initialized instance of pf handle  * @param  pcie_port pcie port handle  * @param  pf_num    physical function number  * @return           0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_pf_handle_init
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|unsigned
name|int
name|pf_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** Pre PCIe Port Enable API **************************/
end_comment

begin_comment
comment|/**  * @brief set current pcie operating mode (root complex or endpoint)  * This function can be called only before enabling the controller using  * al_pcie_port_enable().  *  * @param pcie_port pcie port handle  * @param mode pcie operating mode  *  * @return 0 if no error found.  */
end_comment

begin_function_decl
name|int
name|al_pcie_port_operating_mode_config
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|enum
name|al_pcie_operating_mode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Configure number of lanes connected to this port.  * This function can be called only before enabling the controller using al_pcie_port_enable().  *  * @param pcie_port pcie port handle  * @param lanes number of lanes  * Note: this function must be called before any al_pcie_port_config() calls  *  * @return 0 if no error found.  */
end_comment

begin_function_decl
name|int
name|al_pcie_port_max_lanes_set
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|uint8_t
name|lanes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set maximum physical function numbers  * @param pcie_port      pcie port handle  * @param max_num_of_pfs number of physical functions  * Note: this function must be called before any al_pcie_pf_config() calls  */
end_comment

begin_function_decl
name|int
name|al_pcie_port_max_num_of_pfs_set
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|uint8_t
name|max_num_of_pfs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Inbound posted/non-posted header credits and outstanding outbound  *        reads completion header configuration  *  * @param	pcie_port pcie port handle  * @param	ib_hcrd_os_ob_reads_config  * 		Inbound header credits and outstanding outbound reads  * 		configuration  */
end_comment

begin_function_decl
name|int
name|al_pcie_port_ib_hcrd_os_ob_reads_config
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|struct
name|al_pcie_ib_hcrd_os_ob_reads_config
modifier|*
name|ib_hcrd_os_ob_reads_config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** return PCIe operating mode  * @param pcie_port	pcie port handle  * @return		operating mode  */
end_comment

begin_function_decl
name|enum
name|al_pcie_operating_mode
name|al_pcie_operating_mode_get
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************** PCIe Port Enable API ****************************/
end_comment

begin_comment
comment|/** Enable PCIe unit (deassert reset)  *  * @param   pcie_port pcie port handle  *  * @return 0 if no error found.  */
end_comment

begin_function_decl
name|int
name|al_pcie_port_enable
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Disable PCIe unit (assert reset)  *  * @param   pcie_port pcie port handle  */
end_comment

begin_function_decl
name|void
name|al_pcie_port_disable
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Port memory shutdown/up  * Caution: This function can be called only when the controller is disabled  *  * @param pcie_port pcie port handle  * @param enable memory shutdown enable or disable  *  */
end_comment

begin_function_decl
name|int
name|al_pcie_port_memory_shutdown_set
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|al_bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check if port enabled or not  * @param  pcie_port pcie port handle  * @return           AL_TRUE of port enabled and AL_FALSE otherwise  */
end_comment

begin_function_decl
name|al_bool
name|al_pcie_port_is_enabled
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************** PCIe Configuration API ***************************/
end_comment

begin_comment
comment|/**  * @brief   configure pcie port (mode, link params, etc..)  * this function must be called before initializing the link  *  * @param pcie_port pcie port handle  * @param params configuration structure.  *  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_port_config
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
specifier|const
name|struct
name|al_pcie_port_config_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Configure a specific PF (EP params, sriov params, ...)  * this function must be called before any datapath transactions  *  * @param pcie_pf	pcie pf handle  * @param params	configuration structure.  *  * @return		0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_pf_config
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
specifier|const
name|struct
name|al_pcie_pf_config_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** PCIe Link Operations API **************************/
end_comment

begin_comment
comment|/**  * @brief   start pcie link  *  * @param   pcie_port pcie port handle  *  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_link_start
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   stop pcie link  *  * @param   pcie_port pcie port handle  *  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_link_stop
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   trigger link-disable  *  * @param   pcie_port pcie port handle  * @param   disable   AL_TRUE to disable the link and AL_FALSE to enable it  *  * Note: this functionality differs from "al_pcie_link_stop" as it's a spec  *       functionality where both sides of the PCIe agrees to disable the link  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_link_disable
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|al_bool
name|disable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   wait for link up indication  * this function waits for link up indication, it polls LTSSM state until link is ready  *  * @param   pcie_port pcie port handle  * @param   timeout_ms maximum timeout in milli-seconds to wait for link up  *  * @return  0 if link up indication detected  * 	    -ETIME if not.  */
end_comment

begin_function_decl
name|int
name|al_pcie_link_up_wait
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|uint32_t
name|timeout_ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   get link status  *  * @param   pcie_port pcie port handle  * @param   status structure for link status  *  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_link_status
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|struct
name|al_pcie_link_status
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   get lane status  *  * @param	pcie_port  *		pcie port handle  * @param	lane  *		PCIe lane  * @param	status  *		Pointer to returned structure for lane status  *  */
end_comment

begin_function_decl
name|void
name|al_pcie_lane_status_get
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|unsigned
name|int
name|lane
parameter_list|,
name|struct
name|al_pcie_lane_status
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   trigger hot reset  *  * @param   pcie_port pcie port handle  * @param   enable   AL_TRUE to enable hot-reset and AL_FALSE to disable it  *  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_link_hot_reset
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|al_bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   trigger link-retain  * this function initiates Link retraining by directing the Physical Layer LTSSM  * to the Recovery state. If the LTSSM is already in Recovery or Configuration,  * re-entering Recovery is permitted but not required.   * @param   pcie_port pcie port handle  *  * Note: there's no need to disable initiating link-retrain  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_link_retrain
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   change port speed  * this function changes the port speed, it doesn't wait for link re-establishment  *  * @param   pcie_port pcie port handle  * @param   new_speed the new speed gen to set  *  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_link_change_speed
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|enum
name|al_pcie_link_speed
name|new_speed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO: check if this function needed */
end_comment

begin_function_decl
name|int
name|al_pcie_link_change_width
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|uint8_t
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************** Post Link Start API *****************************/
end_comment

begin_comment
comment|/************************** Snoop Configuration API ***************************/
end_comment

begin_comment
comment|/**  * @brief   configure pcie port axi snoop  *  * @param pcie_port pcie port handle  * @param enable_axi_snoop enable snoop.  *  * @return  0 if no error found  */
end_comment

begin_comment
comment|/* TODO: Can this API be called after port enable? */
end_comment

begin_function_decl
name|int
name|al_pcie_port_snoop_config
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|al_bool
name|enable_axi_snoop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** Configuration Space API ***************************/
end_comment

begin_comment
comment|/**  * Configuration Space Access Through PCI-E_ECAM_Ext PASW (RC mode only)  */
end_comment

begin_comment
comment|/**  * @brief   get base address of pci configuration space header  * @param   pcie_pf	pcie pf handle  * @param   addr	pointer for returned address;  * @return              0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_config_space_get
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|uint8_t
name|__iomem
modifier|*
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read data from the local configuration space  *  * @param	pcie_pf	pcie	pf handle  * @param	reg_offset	Configuration space register offset  * @return	Read data  */
end_comment

begin_function_decl
name|uint32_t
name|al_pcie_local_cfg_space_read
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|unsigned
name|int
name|reg_offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Write data to the local configuration space  *  * @param	pcie_pf		PCIe pf handle  * @param	reg_offset	Configuration space register offset  * @param	data		Data to write  * @param	cs2		Should be AL_TRUE if dbi_cs2 must be asserted  *				to enable writing to this register, according to  *				the PCIe Core specifications  * @param	allow_ro_wr	AL_TRUE to allow writing into read-only regs  *  */
end_comment

begin_function_decl
name|void
name|al_pcie_local_cfg_space_write
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|unsigned
name|int
name|reg_offset
parameter_list|,
name|uint32_t
name|data
parameter_list|,
name|al_bool
name|cs2
parameter_list|,
name|al_bool
name|allow_ro_wr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   set target_bus and mask_target_bus  * @param   pcie_port pcie port handle  * @param   target_bus  * @param   mask_target_bus  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_target_bus_set
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|uint8_t
name|target_bus
parameter_list|,
name|uint8_t
name|mask_target_bus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   get target_bus and mask_target_bus  * @param   pcie_port pcie port handle  * @param   target_bus  * @param   mask_target_bus  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_target_bus_get
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|uint8_t
modifier|*
name|target_bus
parameter_list|,
name|uint8_t
modifier|*
name|mask_target_bus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set secondary bus number  *  * @param pcie_port pcie port handle  * @param secbus pci secondary bus number  *  * @return 0 if no error found.  */
end_comment

begin_function_decl
name|int
name|al_pcie_secondary_bus_set
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|uint8_t
name|secbus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set subordinary bus number  *  * @param   pcie_port pcie port handle  * @param   subbus the highest bus number of all of the buses that can be reached  *		downstream of the PCIE instance.  *  * @return 0 if no error found.  */
end_comment

begin_function_decl
name|int
name|al_pcie_subordinary_bus_set
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|uint8_t
name|subbus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Enable/disable deferring incoming configuration requests until  * initialization is complete. When enabled, the core completes incoming  * configuration requests with a Configuration Request Retry Status.  * Other incoming Requests complete with Unsupported Request status.  *  * @param pcie_port pcie port handle  * @param en enable/disable  */
end_comment

begin_function_decl
name|void
name|al_pcie_app_req_retry_set
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|al_bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************** Internal Address Translation Unit (ATU) API ******************/
end_comment

begin_enum
enum|enum
name|al_pcie_atu_dir
block|{
name|AL_PCIE_ATU_DIR_OUTBOUND
init|=
literal|0
block|,
name|AL_PCIE_ATU_DIR_INBOUND
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|al_pcie_atu_tlp
block|{
name|AL_PCIE_TLP_TYPE_MEM
init|=
literal|0
block|,
name|AL_PCIE_TLP_TYPE_IO
init|=
literal|2
block|,
name|AL_PCIE_TLP_TYPE_CFG0
init|=
literal|4
block|,
name|AL_PCIE_TLP_TYPE_CFG1
init|=
literal|5
block|,
name|AL_PCIE_TLP_TYPE_MSG
init|=
literal|0x10
block|,
name|AL_PCIE_TLP_TYPE_RESERVED
init|=
literal|0x1f
block|}
enum|;
end_enum

begin_enum
enum|enum
name|al_pcie_atu_response
block|{
name|AL_PCIE_RESPONSE_NORMAL
init|=
literal|0
block|,
name|AL_PCIE_RESPONSE_UR
init|=
literal|1
block|,
name|AL_PCIE_RESPONSE_CA
init|=
literal|2
block|}
enum|;
end_enum

begin_struct
struct|struct
name|al_pcie_atu_region
block|{
name|al_bool
name|enable
decl_stmt|;
comment|/* outbound or inbound */
name|enum
name|al_pcie_atu_dir
name|direction
decl_stmt|;
comment|/* region index */
name|uint8_t
name|index
decl_stmt|;
name|uint64_t
name|base_addr
decl_stmt|;
comment|/** limit marks the region's end address. only bits [39:0] are valid 	 * given the Alpine PoC maximum physical address space 	 */
name|uint64_t
name|limit
decl_stmt|;
comment|/** the address that matches will be translated to this address + offset 	 */
name|uint64_t
name|target_addr
decl_stmt|;
name|al_bool
name|invert_matching
decl_stmt|;
comment|/* pcie tlp type*/
name|enum
name|al_pcie_atu_tlp
name|tlp_type
decl_stmt|;
comment|/* pcie frame header attr field*/
name|uint8_t
name|attr
decl_stmt|;
comment|/** 	 * outbound specific params 	 */
comment|/* pcie message code */
name|uint8_t
name|msg_code
decl_stmt|;
name|al_bool
name|cfg_shift_mode
decl_stmt|;
comment|/** 	 * inbound specific params 	 */
name|uint8_t
name|bar_number
decl_stmt|;
comment|/* BAR match mode, used in EP for MEM and IO tlps*/
name|uint8_t
name|match_mode
decl_stmt|;
comment|/** 	 * For outbound: enables taking the function number of the translated 	 * TLP from the PCIe core. For inbound: enables ATU function match mode 	 * Note: this boolean is ignored in RC mode 	 */
name|al_bool
name|function_match_bypass_mode
decl_stmt|;
comment|/** 	 * The function number to match/bypass (see previous parameter) 	 * Note: this parameter is ignored when previous param is FALSE 	 */
name|uint8_t
name|function_match_bypass_mode_number
decl_stmt|;
comment|/* response code */
name|enum
name|al_pcie_atu_response
name|response
decl_stmt|;
name|al_bool
name|enable_attr_match_mode
decl_stmt|;
name|al_bool
name|enable_msg_match_mode
decl_stmt|;
comment|/** 	 * USE WITH CAUTION: setting this boolean to AL_TRUE allows setting the 	 * outbound ATU even after link is already started. DO NOT SET this 	 * boolean to AL_TRUE unless there have been NO traffic before calling 	 * al_pcie_atu_region_set function 	 */
name|al_bool
name|enforce_ob_atu_region_set
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief   program internal ATU region entry  * @param   pcie_port	pcie port handle  * @param   atu_region	data structure that contains the region index and the  *          translation parameters  * @return  0 if no error  */
end_comment

begin_function_decl
name|int
name|al_pcie_atu_region_set
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|struct
name|al_pcie_atu_region
modifier|*
name|atu_region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief  get internal ATU is enabled and base/target addresses  * @param  pcie_port   pcie port handle  * @param  direction   input: iATU direction (IB/OB)  * @param  index       input: iATU index  * @param  enable      output: AL_TRUE if the iATU is enabled  * @param  base_addr   output: the iATU base address  * @param  target_addr output: the iATU target address  */
end_comment

begin_function_decl
name|void
name|al_pcie_atu_region_get_fields
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|enum
name|al_pcie_atu_dir
name|direction
parameter_list|,
name|uint8_t
name|index
parameter_list|,
name|al_bool
modifier|*
name|enable
parameter_list|,
name|uint64_t
modifier|*
name|base_addr
parameter_list|,
name|uint64_t
modifier|*
name|target_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   Configure axi io bar.  *          every hit to this bar will override size to 4 bytes.  * @param   pcie_port pcie port handle  * @param   start the first address of the memory  * @param   end the last address of the memory  * @return  */
end_comment

begin_function_decl
name|void
name|al_pcie_axi_io_config
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|al_phys_addr_t
name|start
parameter_list|,
name|al_phys_addr_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************** Interrupt generation (Endpoint mode Only) API *****************/
end_comment

begin_enum
enum|enum
name|al_pcie_legacy_int_type
block|{
name|AL_PCIE_LEGACY_INTA
init|=
literal|0
block|,
name|AL_PCIE_LEGACY_INTB
block|,
name|AL_PCIE_LEGACY_INTC
block|,
name|AL_PCIE_LEGACY_INTD
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief		generate INTx Assert/DeAssert Message  * @param  pcie_pf	pcie pf handle  * @param  assert	when true, Assert Message is sent  * @param  type		type of message (INTA, INTB, etc)  * @return		0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_legacy_int_gen
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|al_bool
name|assert
parameter_list|,
name|enum
name|al_pcie_legacy_int_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief		generate MSI interrupt  * @param  pcie_pf	pcie pf handle  * @param  vector	the vector index to send interrupt for.  * @return		0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_msi_int_gen
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|uint8_t
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   configure MSIX capability  * @param   pcie_pf	pcie pf handle  * @param   msix_params	MSIX capability configuration parameters  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_msix_config
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|struct
name|al_pcie_msix_params
modifier|*
name|msix_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   check whether MSIX capability is enabled  * @param   pcie_pf	pcie pf handle  * @return  AL_TRUE if MSIX capability is enabled, AL_FALSE otherwise  */
end_comment

begin_function_decl
name|al_bool
name|al_pcie_msix_enabled
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   check whether MSIX capability is masked  * @param   pcie_pf	pcie pf handle  * @return  AL_TRUE if MSIX capability is masked, AL_FALSE otherwise  */
end_comment

begin_function_decl
name|al_bool
name|al_pcie_msix_masked
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************** Advanced Error Reporting (AER) API **********************/
end_comment

begin_comment
comment|/**  * @brief   configure AER capability  * @param   pcie_pf	pcie pf handle  * @param   params	AER capability configuration parameters  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_aer_config
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|struct
name|al_pcie_aer_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   AER uncorretable errors get and clear  * @param   pcie_pf	pcie pf handle  * @return  bit mask of uncorrectable errors - see 'AL_PCIE_AER_UNCORR_*' for  *          details  */
end_comment

begin_function_decl
name|unsigned
name|int
name|al_pcie_aer_uncorr_get_and_clear
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   AER corretable errors get and clear  * @param   pcie_pf	pcie pf handle  * @return  bit mask of correctable errors - see 'AL_PCIE_AER_CORR_*' for  *          details  */
end_comment

begin_function_decl
name|unsigned
name|int
name|al_pcie_aer_corr_get_and_clear
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   AER get the header for the TLP corresponding to a detected error  * @param   pcie_pf	pcie pf handle  * @param   hdr		pointer to an array for getting the header  */
end_comment

begin_function_decl
name|void
name|al_pcie_aer_err_tlp_hdr_get
parameter_list|(
name|struct
name|al_pcie_pf
modifier|*
name|pcie_pf
parameter_list|,
name|uint32_t
name|hdr
index|[
name|AL_PCIE_AER_ERR_TLP_HDR_NUM_DWORDS
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************** Loop-Back mode (RC and Endpoint modes) ******************/
end_comment

begin_comment
comment|/**  * @brief   enter local pipe loop-back mode  *  This mode will connect the pipe RX signals to TX.  *  no need to start link when using this mode.  *  Gen3 equalization must be disabled before enabling this mode  *  The caller must make sure the port is ready to accept the TLPs it sends to  *  itself. for example, BARs should be initialized before sending memory TLPs.  *  * @param   pcie_port pcie port handle  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_local_pipe_loopback_enter
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   exit local pipe loopback mode  *  * @param   pcie_port pcie port handle  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_local_pipe_loopback_exit
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   enter master remote loopback mode  *  No need to configure the link partner to enter slave remote loopback mode  *  as this should be done as response to special training sequence directives  *  when master works in remote loopback mode.  *  The caller must make sure the port is ready to accept the TLPs it sends to  *  itself. for example, BARs should be initialized before sending memory TLPs.  *  * @param   pcie_port pcie port handle  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_remote_loopback_enter
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief   exit remote loopback mode  *  * @param   pcie_port pcie port handle  * @return  0 if no error found  */
end_comment

begin_function_decl
name|int
name|al_pcie_remote_loopback_exit
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** @} end of grouppcie group */
end_comment

end_unit

