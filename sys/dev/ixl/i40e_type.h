begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_TYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_TYPE_H_
end_define

begin_include
include|#
directive|include
file|"i40e_status.h"
end_include

begin_include
include|#
directive|include
file|"i40e_osdep.h"
end_include

begin_include
include|#
directive|include
file|"i40e_register.h"
end_include

begin_include
include|#
directive|include
file|"i40e_adminq.h"
end_include

begin_include
include|#
directive|include
file|"i40e_hmc.h"
end_include

begin_include
include|#
directive|include
file|"i40e_lan_hmc.h"
end_include

begin_include
include|#
directive|include
file|"i40e_devids.h"
end_include

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|a
parameter_list|)
value|(1UL<< (a))
end_define

begin_define
define|#
directive|define
name|BIT_ULL
parameter_list|(
name|a
parameter_list|)
value|(1ULL<< (a))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|I40E_MASK
end_ifndef

begin_comment
comment|/* I40E_MASK is a macro used on 32 bit registers */
end_comment

begin_define
define|#
directive|define
name|I40E_MASK
parameter_list|(
name|mask
parameter_list|,
name|shift
parameter_list|)
value|(mask<< shift)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|I40E_MAX_PF
value|16
end_define

begin_define
define|#
directive|define
name|I40E_MAX_PF_VSI
value|64
end_define

begin_define
define|#
directive|define
name|I40E_MAX_PF_QP
value|128
end_define

begin_define
define|#
directive|define
name|I40E_MAX_VSI_QP
value|16
end_define

begin_define
define|#
directive|define
name|I40E_MAX_VF_VSI
value|3
end_define

begin_define
define|#
directive|define
name|I40E_MAX_CHAINED_RX_BUFFERS
value|5
end_define

begin_define
define|#
directive|define
name|I40E_MAX_PF_UDP_OFFLOAD_PORTS
value|16
end_define

begin_comment
comment|/* something less than 1 minute */
end_comment

begin_define
define|#
directive|define
name|I40E_HEARTBEAT_TIMEOUT
value|(HZ * 50)
end_define

begin_comment
comment|/* Max default timeout in ms, */
end_comment

begin_define
define|#
directive|define
name|I40E_MAX_NVM_TIMEOUT
value|18000
end_define

begin_comment
comment|/* Check whether address is multicast. */
end_comment

begin_define
define|#
directive|define
name|I40E_IS_MULTICAST
parameter_list|(
name|address
parameter_list|)
value|(bool)(((u8 *)(address))[0]& ((u8)0x01))
end_define

begin_comment
comment|/* Check whether an address is broadcast. */
end_comment

begin_define
define|#
directive|define
name|I40E_IS_BROADCAST
parameter_list|(
name|address
parameter_list|)
define|\
value|((((u8 *)(address))[0] == ((u8)0xff))&& \ 	(((u8 *)(address))[1] == ((u8)0xff)))
end_define

begin_comment
comment|/* Switch from ms to the 1usec global time (this is the GTIME resolution) */
end_comment

begin_define
define|#
directive|define
name|I40E_MS_TO_GTIME
parameter_list|(
name|time
parameter_list|)
value|((time) * 1000)
end_define

begin_comment
comment|/* forward declaration */
end_comment

begin_struct_decl
struct_decl|struct
name|i40e_hw
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|I40E_ADMINQ_CALLBACK
function_decl|)
parameter_list|(
name|struct
name|i40e_hw
modifier|*
parameter_list|,
name|struct
name|i40e_aq_desc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|I40E_ETH_LENGTH_OF_ADDRESS
value|6
end_define

begin_comment
comment|/* Data type manipulation macros. */
end_comment

begin_define
define|#
directive|define
name|I40E_HI_DWORD
parameter_list|(
name|x
parameter_list|)
value|((u32)((((x)>> 16)>> 16)& 0xFFFFFFFF))
end_define

begin_define
define|#
directive|define
name|I40E_LO_DWORD
parameter_list|(
name|x
parameter_list|)
value|((u32)((x)& 0xFFFFFFFF))
end_define

begin_define
define|#
directive|define
name|I40E_HI_WORD
parameter_list|(
name|x
parameter_list|)
value|((u16)(((x)>> 16)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|I40E_LO_WORD
parameter_list|(
name|x
parameter_list|)
value|((u16)((x)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|I40E_HI_BYTE
parameter_list|(
name|x
parameter_list|)
value|((u8)(((x)>> 8)& 0xFF))
end_define

begin_define
define|#
directive|define
name|I40E_LO_BYTE
parameter_list|(
name|x
parameter_list|)
value|((u8)((x)& 0xFF))
end_define

begin_comment
comment|/* Number of Transmit Descriptors must be a multiple of 8. */
end_comment

begin_define
define|#
directive|define
name|I40E_REQ_TX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_comment
comment|/* Number of Receive Descriptors must be a multiple of 32 if  * the number of descriptors is greater than 32.  */
end_comment

begin_define
define|#
directive|define
name|I40E_REQ_RX_DESCRIPTOR_MULTIPLE
value|32
end_define

begin_define
define|#
directive|define
name|I40E_DESC_UNUSED
parameter_list|(
name|R
parameter_list|)
define|\
value|((((R)->next_to_clean> (R)->next_to_use) ? 0 : (R)->count) + \ 	(R)->next_to_clean - (R)->next_to_use - 1)
end_define

begin_comment
comment|/* bitfields for Tx queue mapping in QTX_CTL */
end_comment

begin_define
define|#
directive|define
name|I40E_QTX_CTL_VF_QUEUE
value|0x0
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL_VM_QUEUE
value|0x1
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL_PF_QUEUE
value|0x2
end_define

begin_comment
comment|/* debug masks - set these bits in hw->debug_mask to control output */
end_comment

begin_enum
enum|enum
name|i40e_debug_mask
block|{
name|I40E_DEBUG_INIT
init|=
literal|0x00000001
block|,
name|I40E_DEBUG_RELEASE
init|=
literal|0x00000002
block|,
name|I40E_DEBUG_LINK
init|=
literal|0x00000010
block|,
name|I40E_DEBUG_PHY
init|=
literal|0x00000020
block|,
name|I40E_DEBUG_HMC
init|=
literal|0x00000040
block|,
name|I40E_DEBUG_NVM
init|=
literal|0x00000080
block|,
name|I40E_DEBUG_LAN
init|=
literal|0x00000100
block|,
name|I40E_DEBUG_FLOW
init|=
literal|0x00000200
block|,
name|I40E_DEBUG_DCB
init|=
literal|0x00000400
block|,
name|I40E_DEBUG_DIAG
init|=
literal|0x00000800
block|,
name|I40E_DEBUG_FD
init|=
literal|0x00001000
block|,
name|I40E_DEBUG_AQ_MESSAGE
init|=
literal|0x01000000
block|,
name|I40E_DEBUG_AQ_DESCRIPTOR
init|=
literal|0x02000000
block|,
name|I40E_DEBUG_AQ_DESC_BUFFER
init|=
literal|0x04000000
block|,
name|I40E_DEBUG_AQ_COMMAND
init|=
literal|0x06000000
block|,
name|I40E_DEBUG_AQ
init|=
literal|0x0F000000
block|,
name|I40E_DEBUG_USER
init|=
literal|0xF0000000
block|,
name|I40E_DEBUG_ALL
init|=
literal|0xFFFFFFFF
block|}
enum|;
end_enum

begin_comment
comment|/* PCI Bus Info */
end_comment

begin_define
define|#
directive|define
name|I40E_PCI_LINK_STATUS
value|0xB2
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_WIDTH
value|0x3F0
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_WIDTH_1
value|0x10
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_WIDTH_2
value|0x20
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_WIDTH_4
value|0x40
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_WIDTH_8
value|0x80
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_SPEED
value|0xF
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_SPEED_2500
value|0x1
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_SPEED_5000
value|0x2
end_define

begin_define
define|#
directive|define
name|I40E_PCI_LINK_SPEED_8000
value|0x3
end_define

begin_define
define|#
directive|define
name|I40E_MDIO_CLAUSE22_STCODE_MASK
value|I40E_MASK(1, \ 						  I40E_GLGEN_MSCA_STCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MDIO_CLAUSE22_OPCODE_WRITE_MASK
value|I40E_MASK(1, \ 						  I40E_GLGEN_MSCA_OPCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MDIO_CLAUSE22_OPCODE_READ_MASK
value|I40E_MASK(2, \ 						  I40E_GLGEN_MSCA_OPCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MDIO_CLAUSE45_STCODE_MASK
value|I40E_MASK(0, \ 						  I40E_GLGEN_MSCA_STCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MDIO_CLAUSE45_OPCODE_ADDRESS_MASK
value|I40E_MASK(0, \ 						  I40E_GLGEN_MSCA_OPCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MDIO_CLAUSE45_OPCODE_WRITE_MASK
value|I40E_MASK(1, \ 						  I40E_GLGEN_MSCA_OPCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MDIO_CLAUSE45_OPCODE_READ_INC_ADDR_MASK
value|I40E_MASK(2, \ 						  I40E_GLGEN_MSCA_OPCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MDIO_CLAUSE45_OPCODE_READ_MASK
value|I40E_MASK(3, \ 						  I40E_GLGEN_MSCA_OPCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PHY_COM_REG_PAGE
value|0x1E
end_define

begin_define
define|#
directive|define
name|I40E_PHY_LED_LINK_MODE_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|I40E_PHY_LED_MANUAL_ON
value|0x100
end_define

begin_define
define|#
directive|define
name|I40E_PHY_LED_PROV_REG_1
value|0xC430
end_define

begin_define
define|#
directive|define
name|I40E_PHY_LED_MODE_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|I40E_PHY_LED_MODE_ORIG
value|0x80000000
end_define

begin_comment
comment|/* Memory types */
end_comment

begin_enum
enum|enum
name|i40e_memset_type
block|{
name|I40E_NONDMA_MEM
init|=
literal|0
block|,
name|I40E_DMA_MEM
block|}
enum|;
end_enum

begin_comment
comment|/* Memcpy types */
end_comment

begin_enum
enum|enum
name|i40e_memcpy_type
block|{
name|I40E_NONDMA_TO_NONDMA
init|=
literal|0
block|,
name|I40E_NONDMA_TO_DMA
block|,
name|I40E_DMA_TO_DMA
block|,
name|I40E_DMA_TO_NONDMA
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_FW_API_VERSION_MINOR_X722
value|0x0005
end_define

begin_define
define|#
directive|define
name|I40E_FW_API_VERSION_MINOR_X710
value|0x0005
end_define

begin_comment
comment|/* These are structs for managing the hardware information and the operations.  * The structures of function pointers are filled out at init time when we  * know for sure exactly which hardware we're working with.  This gives us the  * flexibility of using the same main driver code but adapting to slightly  * different hardware needs as new parts are developed.  For this architecture,  * the Firmware and AdminQ are intended to insulate the driver from most of the  * future changes, but these structures will also do part of the job.  */
end_comment

begin_enum
enum|enum
name|i40e_mac_type
block|{
name|I40E_MAC_UNKNOWN
init|=
literal|0
block|,
name|I40E_MAC_XL710
block|,
name|I40E_MAC_VF
block|,
name|I40E_MAC_X722
block|,
name|I40E_MAC_X722_VF
block|,
name|I40E_MAC_GENERIC
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|i40e_media_type
block|{
name|I40E_MEDIA_TYPE_UNKNOWN
init|=
literal|0
block|,
name|I40E_MEDIA_TYPE_FIBER
block|,
name|I40E_MEDIA_TYPE_BASET
block|,
name|I40E_MEDIA_TYPE_BACKPLANE
block|,
name|I40E_MEDIA_TYPE_CX4
block|,
name|I40E_MEDIA_TYPE_DA
block|,
name|I40E_MEDIA_TYPE_VIRTUAL
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_fc_mode
block|{
name|I40E_FC_NONE
init|=
literal|0
block|,
name|I40E_FC_RX_PAUSE
block|,
name|I40E_FC_TX_PAUSE
block|,
name|I40E_FC_FULL
block|,
name|I40E_FC_PFC
block|,
name|I40E_FC_DEFAULT
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_set_fc_aq_failures
block|{
name|I40E_SET_FC_AQ_FAIL_NONE
init|=
literal|0
block|,
name|I40E_SET_FC_AQ_FAIL_GET
init|=
literal|1
block|,
name|I40E_SET_FC_AQ_FAIL_SET
init|=
literal|2
block|,
name|I40E_SET_FC_AQ_FAIL_UPDATE
init|=
literal|4
block|,
name|I40E_SET_FC_AQ_FAIL_SET_UPDATE
init|=
literal|6
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_vsi_type
block|{
name|I40E_VSI_MAIN
init|=
literal|0
block|,
name|I40E_VSI_VMDQ1
init|=
literal|1
block|,
name|I40E_VSI_VMDQ2
init|=
literal|2
block|,
name|I40E_VSI_CTRL
init|=
literal|3
block|,
name|I40E_VSI_FCOE
init|=
literal|4
block|,
name|I40E_VSI_MIRROR
init|=
literal|5
block|,
name|I40E_VSI_SRIOV
init|=
literal|6
block|,
name|I40E_VSI_FDIR
init|=
literal|7
block|,
name|I40E_VSI_TYPE_UNKNOWN
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_queue_type
block|{
name|I40E_QUEUE_TYPE_RX
init|=
literal|0
block|,
name|I40E_QUEUE_TYPE_TX
block|,
name|I40E_QUEUE_TYPE_PE_CEQ
block|,
name|I40E_QUEUE_TYPE_UNKNOWN
block|}
enum|;
end_enum

begin_struct
struct|struct
name|i40e_link_status
block|{
name|enum
name|i40e_aq_phy_type
name|phy_type
decl_stmt|;
name|enum
name|i40e_aq_link_speed
name|link_speed
decl_stmt|;
name|u8
name|link_info
decl_stmt|;
name|u8
name|an_info
decl_stmt|;
name|u8
name|fec_info
decl_stmt|;
name|u8
name|ext_info
decl_stmt|;
name|u8
name|loopback
decl_stmt|;
comment|/* is Link Status Event notification to SW enabled */
name|bool
name|lse_enable
decl_stmt|;
name|u16
name|max_frame_size
decl_stmt|;
name|bool
name|crc_enable
decl_stmt|;
name|u8
name|pacing
decl_stmt|;
name|u8
name|requested_speeds
decl_stmt|;
name|u8
name|module_type
index|[
literal|3
index|]
decl_stmt|;
comment|/* 1st byte: module identifier */
define|#
directive|define
name|I40E_MODULE_TYPE_SFP
value|0x03
define|#
directive|define
name|I40E_MODULE_TYPE_QSFP
value|0x0D
comment|/* 2nd byte: ethernet compliance codes for 10/40G */
define|#
directive|define
name|I40E_MODULE_TYPE_40G_ACTIVE
value|0x01
define|#
directive|define
name|I40E_MODULE_TYPE_40G_LR4
value|0x02
define|#
directive|define
name|I40E_MODULE_TYPE_40G_SR4
value|0x04
define|#
directive|define
name|I40E_MODULE_TYPE_40G_CR4
value|0x08
define|#
directive|define
name|I40E_MODULE_TYPE_10G_BASE_SR
value|0x10
define|#
directive|define
name|I40E_MODULE_TYPE_10G_BASE_LR
value|0x20
define|#
directive|define
name|I40E_MODULE_TYPE_10G_BASE_LRM
value|0x40
define|#
directive|define
name|I40E_MODULE_TYPE_10G_BASE_ER
value|0x80
comment|/* 3rd byte: ethernet compliance codes for 1G */
define|#
directive|define
name|I40E_MODULE_TYPE_1000BASE_SX
value|0x01
define|#
directive|define
name|I40E_MODULE_TYPE_1000BASE_LX
value|0x02
define|#
directive|define
name|I40E_MODULE_TYPE_1000BASE_CX
value|0x04
define|#
directive|define
name|I40E_MODULE_TYPE_1000BASE_T
value|0x08
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_phy_info
block|{
name|struct
name|i40e_link_status
name|link_info
decl_stmt|;
name|struct
name|i40e_link_status
name|link_info_old
decl_stmt|;
name|bool
name|get_link_info
decl_stmt|;
name|enum
name|i40e_media_type
name|media_type
decl_stmt|;
comment|/* all the phy types the NVM is capable of */
name|u64
name|phy_types
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_SGMII
value|BIT_ULL(I40E_PHY_TYPE_SGMII)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_1000BASE_KX
value|BIT_ULL(I40E_PHY_TYPE_1000BASE_KX)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_KX4
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_KX4)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_KR
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_KR)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_40GBASE_KR4
value|BIT_ULL(I40E_PHY_TYPE_40GBASE_KR4)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_XAUI
value|BIT_ULL(I40E_PHY_TYPE_XAUI)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_XFI
value|BIT_ULL(I40E_PHY_TYPE_XFI)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_SFI
value|BIT_ULL(I40E_PHY_TYPE_SFI)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_XLAUI
value|BIT_ULL(I40E_PHY_TYPE_XLAUI)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_XLPPI
value|BIT_ULL(I40E_PHY_TYPE_XLPPI)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_40GBASE_CR4_CU
value|BIT_ULL(I40E_PHY_TYPE_40GBASE_CR4_CU)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_CR1_CU
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_CR1_CU)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_AOC
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_AOC)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_40GBASE_AOC
value|BIT_ULL(I40E_PHY_TYPE_40GBASE_AOC)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_100BASE_TX
value|BIT_ULL(I40E_PHY_TYPE_100BASE_TX)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_1000BASE_T
value|BIT_ULL(I40E_PHY_TYPE_1000BASE_T)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_T
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_T)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_SR
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_SR)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_LR
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_LR)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_SFPP_CU
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_SFPP_CU)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_10GBASE_CR1
value|BIT_ULL(I40E_PHY_TYPE_10GBASE_CR1)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_40GBASE_CR4
value|BIT_ULL(I40E_PHY_TYPE_40GBASE_CR4)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_40GBASE_SR4
value|BIT_ULL(I40E_PHY_TYPE_40GBASE_SR4)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_40GBASE_LR4
value|BIT_ULL(I40E_PHY_TYPE_40GBASE_LR4)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_1000BASE_SX
value|BIT_ULL(I40E_PHY_TYPE_1000BASE_SX)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_1000BASE_LX
value|BIT_ULL(I40E_PHY_TYPE_1000BASE_LX)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_1000BASE_T_OPTICAL
define|\
value|BIT_ULL(I40E_PHY_TYPE_1000BASE_T_OPTICAL)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_20GBASE_KR2
value|BIT_ULL(I40E_PHY_TYPE_20GBASE_KR2)
end_define

begin_comment
comment|/*  * Defining the macro I40E_TYPE_OFFSET to implement a bit shift for some  * PHY types. There is an unused bit (31) in the I40E_CAP_PHY_TYPE_* bit  * fields but no corresponding gap in the i40e_aq_phy_type enumeration. So,  * a shift is needed to adjust for this with values larger than 31. The  * only affected values are I40E_PHY_TYPE_25GBASE_*.  */
end_comment

begin_define
define|#
directive|define
name|I40E_PHY_TYPE_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_25GBASE_KR
value|BIT_ULL(I40E_PHY_TYPE_25GBASE_KR + \ 					     I40E_PHY_TYPE_OFFSET)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_25GBASE_CR
value|BIT_ULL(I40E_PHY_TYPE_25GBASE_CR + \ 					     I40E_PHY_TYPE_OFFSET)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_25GBASE_SR
value|BIT_ULL(I40E_PHY_TYPE_25GBASE_SR + \ 					     I40E_PHY_TYPE_OFFSET)
end_define

begin_define
define|#
directive|define
name|I40E_CAP_PHY_TYPE_25GBASE_LR
value|BIT_ULL(I40E_PHY_TYPE_25GBASE_LR + \ 					     I40E_PHY_TYPE_OFFSET)
end_define

begin_define
define|#
directive|define
name|I40E_HW_CAP_MAX_GPIO
value|30
end_define

begin_define
define|#
directive|define
name|I40E_HW_CAP_MDIO_PORT_MODE_MDIO
value|0
end_define

begin_define
define|#
directive|define
name|I40E_HW_CAP_MDIO_PORT_MODE_I2C
value|1
end_define

begin_enum
enum|enum
name|i40e_acpi_programming_method
block|{
name|I40E_ACPI_PROGRAMMING_METHOD_HW_FVL
init|=
literal|0
block|,
name|I40E_ACPI_PROGRAMMING_METHOD_AQC_FPK
init|=
literal|1
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_WOL_SUPPORT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|I40E_ACPI_PROGRAMMING_METHOD_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|I40E_PROXY_SUPPORT_MASK
value|0x4
end_define

begin_comment
comment|/* Capabilities of a PF or a VF or the whole device */
end_comment

begin_struct
struct|struct
name|i40e_hw_capabilities
block|{
name|u32
name|switch_mode
decl_stmt|;
define|#
directive|define
name|I40E_NVM_IMAGE_TYPE_EVB
value|0x0
define|#
directive|define
name|I40E_NVM_IMAGE_TYPE_CLOUD
value|0x2
define|#
directive|define
name|I40E_NVM_IMAGE_TYPE_UDP_CLOUD
value|0x3
name|u32
name|management_mode
decl_stmt|;
name|u32
name|mng_protocols_over_mctp
decl_stmt|;
define|#
directive|define
name|I40E_MNG_PROTOCOL_PLDM
value|0x2
define|#
directive|define
name|I40E_MNG_PROTOCOL_OEM_COMMANDS
value|0x4
define|#
directive|define
name|I40E_MNG_PROTOCOL_NCSI
value|0x8
name|u32
name|npar_enable
decl_stmt|;
name|u32
name|os2bmc
decl_stmt|;
name|u32
name|valid_functions
decl_stmt|;
name|bool
name|sr_iov_1_1
decl_stmt|;
name|bool
name|vmdq
decl_stmt|;
name|bool
name|evb_802_1_qbg
decl_stmt|;
comment|/* Edge Virtual Bridging */
name|bool
name|evb_802_1_qbh
decl_stmt|;
comment|/* Bridge Port Extension */
name|bool
name|dcb
decl_stmt|;
name|bool
name|fcoe
decl_stmt|;
name|bool
name|iscsi
decl_stmt|;
comment|/* Indicates iSCSI enabled */
name|bool
name|flex10_enable
decl_stmt|;
name|bool
name|flex10_capable
decl_stmt|;
name|u32
name|flex10_mode
decl_stmt|;
define|#
directive|define
name|I40E_FLEX10_MODE_UNKNOWN
value|0x0
define|#
directive|define
name|I40E_FLEX10_MODE_DCC
value|0x1
define|#
directive|define
name|I40E_FLEX10_MODE_DCI
value|0x2
name|u32
name|flex10_status
decl_stmt|;
define|#
directive|define
name|I40E_FLEX10_STATUS_DCC_ERROR
value|0x1
define|#
directive|define
name|I40E_FLEX10_STATUS_VC_MODE
value|0x2
name|bool
name|sec_rev_disabled
decl_stmt|;
name|bool
name|update_disabled
decl_stmt|;
define|#
directive|define
name|I40E_NVM_MGMT_SEC_REV_DISABLED
value|0x1
define|#
directive|define
name|I40E_NVM_MGMT_UPDATE_DISABLED
value|0x2
name|bool
name|mgmt_cem
decl_stmt|;
name|bool
name|ieee_1588
decl_stmt|;
name|bool
name|iwarp
decl_stmt|;
name|bool
name|fd
decl_stmt|;
name|u32
name|fd_filters_guaranteed
decl_stmt|;
name|u32
name|fd_filters_best_effort
decl_stmt|;
name|bool
name|rss
decl_stmt|;
name|u32
name|rss_table_size
decl_stmt|;
name|u32
name|rss_table_entry_width
decl_stmt|;
name|bool
name|led
index|[
name|I40E_HW_CAP_MAX_GPIO
index|]
decl_stmt|;
name|bool
name|sdp
index|[
name|I40E_HW_CAP_MAX_GPIO
index|]
decl_stmt|;
name|u32
name|nvm_image_type
decl_stmt|;
name|u32
name|num_flow_director_filters
decl_stmt|;
name|u32
name|num_vfs
decl_stmt|;
name|u32
name|vf_base_id
decl_stmt|;
name|u32
name|num_vsis
decl_stmt|;
name|u32
name|num_rx_qp
decl_stmt|;
name|u32
name|num_tx_qp
decl_stmt|;
name|u32
name|base_queue
decl_stmt|;
name|u32
name|num_msix_vectors
decl_stmt|;
name|u32
name|num_msix_vectors_vf
decl_stmt|;
name|u32
name|led_pin_num
decl_stmt|;
name|u32
name|sdp_pin_num
decl_stmt|;
name|u32
name|mdio_port_num
decl_stmt|;
name|u32
name|mdio_port_mode
decl_stmt|;
name|u8
name|rx_buf_chain_len
decl_stmt|;
name|u32
name|enabled_tcmap
decl_stmt|;
name|u32
name|maxtc
decl_stmt|;
name|u64
name|wr_csr_prot
decl_stmt|;
name|bool
name|apm_wol_support
decl_stmt|;
name|enum
name|i40e_acpi_programming_method
name|acpi_prog_method
decl_stmt|;
name|bool
name|proxy_support
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_mac_info
block|{
name|enum
name|i40e_mac_type
name|type
decl_stmt|;
name|u8
name|addr
index|[
name|I40E_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u8
name|perm_addr
index|[
name|I40E_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u8
name|san_addr
index|[
name|I40E_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u8
name|port_addr
index|[
name|I40E_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u16
name|max_fcoeq
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|i40e_aq_resources_ids
block|{
name|I40E_NVM_RESOURCE_ID
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_aq_resource_access_type
block|{
name|I40E_RESOURCE_READ
init|=
literal|1
block|,
name|I40E_RESOURCE_WRITE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|i40e_nvm_info
block|{
name|u64
name|hw_semaphore_timeout
decl_stmt|;
comment|/* usec global time (GTIME resolution) */
name|u32
name|timeout
decl_stmt|;
comment|/* [ms] */
name|u16
name|sr_size
decl_stmt|;
comment|/* Shadow RAM size in words */
name|bool
name|blank_nvm_mode
decl_stmt|;
comment|/* is NVM empty (no FW present)*/
name|u16
name|version
decl_stmt|;
comment|/* NVM package version */
name|u32
name|eetrack
decl_stmt|;
comment|/* NVM data version */
name|u32
name|oem_ver
decl_stmt|;
comment|/* OEM version info */
block|}
struct|;
end_struct

begin_comment
comment|/* definitions used in NVM update support */
end_comment

begin_enum
enum|enum
name|i40e_nvmupd_cmd
block|{
name|I40E_NVMUPD_INVALID
block|,
name|I40E_NVMUPD_READ_CON
block|,
name|I40E_NVMUPD_READ_SNT
block|,
name|I40E_NVMUPD_READ_LCB
block|,
name|I40E_NVMUPD_READ_SA
block|,
name|I40E_NVMUPD_WRITE_ERA
block|,
name|I40E_NVMUPD_WRITE_CON
block|,
name|I40E_NVMUPD_WRITE_SNT
block|,
name|I40E_NVMUPD_WRITE_LCB
block|,
name|I40E_NVMUPD_WRITE_SA
block|,
name|I40E_NVMUPD_CSUM_CON
block|,
name|I40E_NVMUPD_CSUM_SA
block|,
name|I40E_NVMUPD_CSUM_LCB
block|,
name|I40E_NVMUPD_STATUS
block|,
name|I40E_NVMUPD_EXEC_AQ
block|,
name|I40E_NVMUPD_GET_AQ_RESULT
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|i40e_nvmupd_state
block|{
name|I40E_NVMUPD_STATE_INIT
block|,
name|I40E_NVMUPD_STATE_READING
block|,
name|I40E_NVMUPD_STATE_WRITING
block|,
name|I40E_NVMUPD_STATE_INIT_WAIT
block|,
name|I40E_NVMUPD_STATE_WRITE_WAIT
block|,
name|I40E_NVMUPD_STATE_ERROR
block|}
enum|;
end_enum

begin_comment
comment|/* nvm_access definition and its masks/shifts need to be accessible to  * application, core driver, and shared code.  Where is the right file?  */
end_comment

begin_define
define|#
directive|define
name|I40E_NVM_READ
value|0xB
end_define

begin_define
define|#
directive|define
name|I40E_NVM_WRITE
value|0xC
end_define

begin_define
define|#
directive|define
name|I40E_NVM_MOD_PNT_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|I40E_NVM_TRANS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_NVM_TRANS_MASK
value|(0xf<< I40E_NVM_TRANS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_NVM_CON
value|0x0
end_define

begin_define
define|#
directive|define
name|I40E_NVM_SNT
value|0x1
end_define

begin_define
define|#
directive|define
name|I40E_NVM_LCB
value|0x2
end_define

begin_define
define|#
directive|define
name|I40E_NVM_SA
value|(I40E_NVM_SNT | I40E_NVM_LCB)
end_define

begin_define
define|#
directive|define
name|I40E_NVM_ERA
value|0x4
end_define

begin_define
define|#
directive|define
name|I40E_NVM_CSUM
value|0x8
end_define

begin_define
define|#
directive|define
name|I40E_NVM_EXEC
value|0xf
end_define

begin_define
define|#
directive|define
name|I40E_NVM_ADAPT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_NVM_ADAPT_MASK
value|(0xffffULL<< I40E_NVM_ADAPT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_NVMUPD_MAX_DATA
value|4096
end_define

begin_define
define|#
directive|define
name|I40E_NVMUPD_IFACE_TIMEOUT
value|2
end_define

begin_comment
comment|/* seconds */
end_comment

begin_struct
struct|struct
name|i40e_nvm_access
block|{
name|u32
name|command
decl_stmt|;
name|u32
name|config
decl_stmt|;
name|u32
name|offset
decl_stmt|;
comment|/* in bytes */
name|u32
name|data_size
decl_stmt|;
comment|/* in bytes */
name|u8
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* PCI bus types */
end_comment

begin_enum
enum|enum
name|i40e_bus_type
block|{
name|i40e_bus_type_unknown
init|=
literal|0
block|,
name|i40e_bus_type_pci
block|,
name|i40e_bus_type_pcix
block|,
name|i40e_bus_type_pci_express
block|,
name|i40e_bus_type_reserved
block|}
enum|;
end_enum

begin_comment
comment|/* PCI bus speeds */
end_comment

begin_enum
enum|enum
name|i40e_bus_speed
block|{
name|i40e_bus_speed_unknown
init|=
literal|0
block|,
name|i40e_bus_speed_33
init|=
literal|33
block|,
name|i40e_bus_speed_66
init|=
literal|66
block|,
name|i40e_bus_speed_100
init|=
literal|100
block|,
name|i40e_bus_speed_120
init|=
literal|120
block|,
name|i40e_bus_speed_133
init|=
literal|133
block|,
name|i40e_bus_speed_2500
init|=
literal|2500
block|,
name|i40e_bus_speed_5000
init|=
literal|5000
block|,
name|i40e_bus_speed_8000
init|=
literal|8000
block|,
name|i40e_bus_speed_reserved
block|}
enum|;
end_enum

begin_comment
comment|/* PCI bus widths */
end_comment

begin_enum
enum|enum
name|i40e_bus_width
block|{
name|i40e_bus_width_unknown
init|=
literal|0
block|,
name|i40e_bus_width_pcie_x1
init|=
literal|1
block|,
name|i40e_bus_width_pcie_x2
init|=
literal|2
block|,
name|i40e_bus_width_pcie_x4
init|=
literal|4
block|,
name|i40e_bus_width_pcie_x8
init|=
literal|8
block|,
name|i40e_bus_width_32
init|=
literal|32
block|,
name|i40e_bus_width_64
init|=
literal|64
block|,
name|i40e_bus_width_reserved
block|}
enum|;
end_enum

begin_comment
comment|/* Bus parameters */
end_comment

begin_struct
struct|struct
name|i40e_bus_info
block|{
name|enum
name|i40e_bus_speed
name|speed
decl_stmt|;
name|enum
name|i40e_bus_width
name|width
decl_stmt|;
name|enum
name|i40e_bus_type
name|type
decl_stmt|;
name|u16
name|func
decl_stmt|;
name|u16
name|device
decl_stmt|;
name|u16
name|lan_id
decl_stmt|;
name|u16
name|bus_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flow control (FC) parameters */
end_comment

begin_struct
struct|struct
name|i40e_fc_info
block|{
name|enum
name|i40e_fc_mode
name|current_mode
decl_stmt|;
comment|/* FC mode in effect */
name|enum
name|i40e_fc_mode
name|requested_mode
decl_stmt|;
comment|/* FC mode requested by caller */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_MAX_TRAFFIC_CLASS
value|8
end_define

begin_define
define|#
directive|define
name|I40E_MAX_USER_PRIORITY
value|8
end_define

begin_define
define|#
directive|define
name|I40E_DCBX_MAX_APPS
value|32
end_define

begin_define
define|#
directive|define
name|I40E_LLDPDU_SIZE
value|1500
end_define

begin_define
define|#
directive|define
name|I40E_TLV_STATUS_OPER
value|0x1
end_define

begin_define
define|#
directive|define
name|I40E_TLV_STATUS_SYNC
value|0x2
end_define

begin_define
define|#
directive|define
name|I40E_TLV_STATUS_ERR
value|0x4
end_define

begin_define
define|#
directive|define
name|I40E_CEE_OPER_MAX_APPS
value|3
end_define

begin_define
define|#
directive|define
name|I40E_APP_PROTOID_FCOE
value|0x8906
end_define

begin_define
define|#
directive|define
name|I40E_APP_PROTOID_ISCSI
value|0x0cbc
end_define

begin_define
define|#
directive|define
name|I40E_APP_PROTOID_FIP
value|0x8914
end_define

begin_define
define|#
directive|define
name|I40E_APP_SEL_ETHTYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|I40E_APP_SEL_TCPIP
value|0x2
end_define

begin_define
define|#
directive|define
name|I40E_CEE_APP_SEL_ETHTYPE
value|0x0
end_define

begin_define
define|#
directive|define
name|I40E_CEE_APP_SEL_TCPIP
value|0x1
end_define

begin_comment
comment|/* CEE or IEEE 802.1Qaz ETS Configuration data */
end_comment

begin_struct
struct|struct
name|i40e_dcb_ets_config
block|{
name|u8
name|willing
decl_stmt|;
name|u8
name|cbs
decl_stmt|;
name|u8
name|maxtcs
decl_stmt|;
name|u8
name|prioritytable
index|[
name|I40E_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
name|u8
name|tcbwtable
index|[
name|I40E_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
name|u8
name|tsatable
index|[
name|I40E_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* CEE or IEEE 802.1Qaz PFC Configuration data */
end_comment

begin_struct
struct|struct
name|i40e_dcb_pfc_config
block|{
name|u8
name|willing
decl_stmt|;
name|u8
name|mbc
decl_stmt|;
name|u8
name|pfccap
decl_stmt|;
name|u8
name|pfcenable
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* CEE or IEEE 802.1Qaz Application Priority data */
end_comment

begin_struct
struct|struct
name|i40e_dcb_app_priority_table
block|{
name|u8
name|priority
decl_stmt|;
name|u8
name|selector
decl_stmt|;
name|u16
name|protocolid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_dcbx_config
block|{
name|u8
name|dcbx_mode
decl_stmt|;
define|#
directive|define
name|I40E_DCBX_MODE_CEE
value|0x1
define|#
directive|define
name|I40E_DCBX_MODE_IEEE
value|0x2
name|u8
name|app_mode
decl_stmt|;
define|#
directive|define
name|I40E_DCBX_APPS_NON_WILLING
value|0x1
name|u32
name|numapps
decl_stmt|;
name|u32
name|tlv_status
decl_stmt|;
comment|/* CEE mode TLV status */
name|struct
name|i40e_dcb_ets_config
name|etscfg
decl_stmt|;
name|struct
name|i40e_dcb_ets_config
name|etsrec
decl_stmt|;
name|struct
name|i40e_dcb_pfc_config
name|pfc
decl_stmt|;
name|struct
name|i40e_dcb_app_priority_table
name|app
index|[
name|I40E_DCBX_MAX_APPS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Port hardware description */
end_comment

begin_struct
struct|struct
name|i40e_hw
block|{
name|u8
modifier|*
name|hw_addr
decl_stmt|;
name|void
modifier|*
name|back
decl_stmt|;
comment|/* subsystem structs */
name|struct
name|i40e_phy_info
name|phy
decl_stmt|;
name|struct
name|i40e_mac_info
name|mac
decl_stmt|;
name|struct
name|i40e_bus_info
name|bus
decl_stmt|;
name|struct
name|i40e_nvm_info
name|nvm
decl_stmt|;
name|struct
name|i40e_fc_info
name|fc
decl_stmt|;
comment|/* pci info */
name|u16
name|device_id
decl_stmt|;
name|u16
name|vendor_id
decl_stmt|;
name|u16
name|subsystem_device_id
decl_stmt|;
name|u16
name|subsystem_vendor_id
decl_stmt|;
name|u8
name|revision_id
decl_stmt|;
name|u8
name|port
decl_stmt|;
name|bool
name|adapter_stopped
decl_stmt|;
comment|/* capabilities for entire device and PCI func */
name|struct
name|i40e_hw_capabilities
name|dev_caps
decl_stmt|;
name|struct
name|i40e_hw_capabilities
name|func_caps
decl_stmt|;
comment|/* Flow Director shared filter space */
name|u16
name|fdir_shared_filter_count
decl_stmt|;
comment|/* device profile info */
name|u8
name|pf_id
decl_stmt|;
name|u16
name|main_vsi_seid
decl_stmt|;
comment|/* for multi-function MACs */
name|u16
name|partition_id
decl_stmt|;
name|u16
name|num_partitions
decl_stmt|;
name|u16
name|num_ports
decl_stmt|;
comment|/* Closest numa node to the device */
name|u16
name|numa_node
decl_stmt|;
comment|/* Admin Queue info */
name|struct
name|i40e_adminq_info
name|aq
decl_stmt|;
comment|/* state of nvm update process */
name|enum
name|i40e_nvmupd_state
name|nvmupd_state
decl_stmt|;
name|struct
name|i40e_aq_desc
name|nvm_wb_desc
decl_stmt|;
name|struct
name|i40e_virt_mem
name|nvm_buff
decl_stmt|;
name|bool
name|nvm_release_on_done
decl_stmt|;
name|u16
name|nvm_wait_opcode
decl_stmt|;
comment|/* HMC info */
name|struct
name|i40e_hmc_info
name|hmc
decl_stmt|;
comment|/* HMC info struct */
comment|/* LLDP/DCBX Status */
name|u16
name|dcbx_status
decl_stmt|;
comment|/* DCBX info */
name|struct
name|i40e_dcbx_config
name|local_dcbx_config
decl_stmt|;
comment|/* Oper/Local Cfg */
name|struct
name|i40e_dcbx_config
name|remote_dcbx_config
decl_stmt|;
comment|/* Peer Cfg */
name|struct
name|i40e_dcbx_config
name|desired_dcbx_config
decl_stmt|;
comment|/* CEE Desired Cfg */
comment|/* WoL and proxy support */
name|u16
name|num_wol_proxy_filters
decl_stmt|;
name|u16
name|wol_proxy_vsi_seid
decl_stmt|;
define|#
directive|define
name|I40E_HW_FLAG_AQ_SRCTL_ACCESS_ENABLE
value|BIT_ULL(0)
name|u64
name|flags
decl_stmt|;
comment|/* debug mask */
name|u32
name|debug_mask
decl_stmt|;
name|char
name|err_str
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|INLINE
name|bool
name|i40e_is_vf
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|)
block|{
return|return
operator|(
name|hw
operator|->
name|mac
operator|.
name|type
operator|==
name|I40E_MAC_VF
operator|||
name|hw
operator|->
name|mac
operator|.
name|type
operator|==
name|I40E_MAC_X722_VF
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|i40e_driver_version
block|{
name|u8
name|major_version
decl_stmt|;
name|u8
name|minor_version
decl_stmt|;
name|u8
name|build_version
decl_stmt|;
name|u8
name|subbuild_version
decl_stmt|;
name|u8
name|driver_string
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RX Descriptors */
end_comment

begin_union
union|union
name|i40e_16byte_rx_desc
block|{
struct|struct
block|{
name|__le64
name|pkt_addr
decl_stmt|;
comment|/* Packet buffer address */
name|__le64
name|hdr_addr
decl_stmt|;
comment|/* Header buffer address */
block|}
name|read
struct|;
struct|struct
block|{
struct|struct
block|{
struct|struct
block|{
union|union
block|{
name|__le16
name|mirroring_status
decl_stmt|;
name|__le16
name|fcoe_ctx_id
decl_stmt|;
block|}
name|mirr_fcoe
union|;
name|__le16
name|l2tag1
decl_stmt|;
block|}
name|lo_dword
struct|;
union|union
block|{
name|__le32
name|rss
decl_stmt|;
comment|/* RSS Hash */
name|__le32
name|fd_id
decl_stmt|;
comment|/* Flow director filter id */
name|__le32
name|fcoe_param
decl_stmt|;
comment|/* FCoE DDP Context id */
block|}
name|hi_dword
union|;
block|}
name|qword0
struct|;
struct|struct
block|{
comment|/* ext status/error/pktype/length */
name|__le64
name|status_error_len
decl_stmt|;
block|}
name|qword1
struct|;
block|}
name|wb
struct|;
comment|/* writeback */
block|}
union|;
end_union

begin_union
union|union
name|i40e_32byte_rx_desc
block|{
struct|struct
block|{
name|__le64
name|pkt_addr
decl_stmt|;
comment|/* Packet buffer address */
name|__le64
name|hdr_addr
decl_stmt|;
comment|/* Header buffer address */
comment|/* bit 0 of hdr_buffer_addr is DD bit */
name|__le64
name|rsvd1
decl_stmt|;
name|__le64
name|rsvd2
decl_stmt|;
block|}
name|read
struct|;
struct|struct
block|{
struct|struct
block|{
struct|struct
block|{
union|union
block|{
name|__le16
name|mirroring_status
decl_stmt|;
name|__le16
name|fcoe_ctx_id
decl_stmt|;
block|}
name|mirr_fcoe
union|;
name|__le16
name|l2tag1
decl_stmt|;
block|}
name|lo_dword
struct|;
union|union
block|{
name|__le32
name|rss
decl_stmt|;
comment|/* RSS Hash */
name|__le32
name|fcoe_param
decl_stmt|;
comment|/* FCoE DDP Context id */
comment|/* Flow director filter id in case of 				 * Programming status desc WB 				 */
name|__le32
name|fd_id
decl_stmt|;
block|}
name|hi_dword
union|;
block|}
name|qword0
struct|;
struct|struct
block|{
comment|/* status/error/pktype/length */
name|__le64
name|status_error_len
decl_stmt|;
block|}
name|qword1
struct|;
struct|struct
block|{
name|__le16
name|ext_status
decl_stmt|;
comment|/* extended status */
name|__le16
name|rsvd
decl_stmt|;
name|__le16
name|l2tag2_1
decl_stmt|;
name|__le16
name|l2tag2_2
decl_stmt|;
block|}
name|qword2
struct|;
struct|struct
block|{
union|union
block|{
name|__le32
name|flex_bytes_lo
decl_stmt|;
name|__le32
name|pe_status
decl_stmt|;
block|}
name|lo_dword
union|;
union|union
block|{
name|__le32
name|flex_bytes_hi
decl_stmt|;
name|__le32
name|fd_id
decl_stmt|;
block|}
name|hi_dword
union|;
block|}
name|qword3
struct|;
block|}
name|wb
struct|;
comment|/* writeback */
block|}
union|;
end_union

begin_define
define|#
directive|define
name|I40E_RXD_QW0_MIRROR_STATUS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW0_MIRROR_STATUS_MASK
value|(0x3FUL<< \ 					 I40E_RXD_QW0_MIRROR_STATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW0_FCOEINDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW0_FCOEINDX_MASK
value|(0xFFFUL<< \ 					 I40E_RXD_QW0_FCOEINDX_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_rx_desc_status_bits
block|{
comment|/* Note: These are predefined bit offsets */
name|I40E_RX_DESC_STATUS_DD_SHIFT
init|=
literal|0
block|,
name|I40E_RX_DESC_STATUS_EOF_SHIFT
init|=
literal|1
block|,
name|I40E_RX_DESC_STATUS_L2TAG1P_SHIFT
init|=
literal|2
block|,
name|I40E_RX_DESC_STATUS_L3L4P_SHIFT
init|=
literal|3
block|,
name|I40E_RX_DESC_STATUS_CRCP_SHIFT
init|=
literal|4
block|,
name|I40E_RX_DESC_STATUS_TSYNINDX_SHIFT
init|=
literal|5
block|,
comment|/* 2 BITS */
name|I40E_RX_DESC_STATUS_TSYNVALID_SHIFT
init|=
literal|7
block|,
name|I40E_RX_DESC_STATUS_EXT_UDP_0_SHIFT
init|=
literal|8
block|,
name|I40E_RX_DESC_STATUS_UMBCAST_SHIFT
init|=
literal|9
block|,
comment|/* 2 BITS */
name|I40E_RX_DESC_STATUS_FLM_SHIFT
init|=
literal|11
block|,
name|I40E_RX_DESC_STATUS_FLTSTAT_SHIFT
init|=
literal|12
block|,
comment|/* 2 BITS */
name|I40E_RX_DESC_STATUS_LPBK_SHIFT
init|=
literal|14
block|,
name|I40E_RX_DESC_STATUS_IPV6EXADD_SHIFT
init|=
literal|15
block|,
name|I40E_RX_DESC_STATUS_RESERVED2_SHIFT
init|=
literal|16
block|,
comment|/* 2 BITS */
name|I40E_RX_DESC_STATUS_INT_UDP_0_SHIFT
init|=
literal|18
block|,
name|I40E_RX_DESC_STATUS_LAST
comment|/* this entry must be last!!! */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_RXD_QW1_STATUS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_STATUS_MASK
value|((BIT(I40E_RX_DESC_STATUS_LAST) - 1)<< \ 					 I40E_RXD_QW1_STATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_STATUS_TSYNINDX_SHIFT
value|I40E_RX_DESC_STATUS_TSYNINDX_SHIFT
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_STATUS_TSYNINDX_MASK
value|(0x3UL<< \ 					     I40E_RXD_QW1_STATUS_TSYNINDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_STATUS_TSYNVALID_SHIFT
value|I40E_RX_DESC_STATUS_TSYNVALID_SHIFT
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_STATUS_TSYNVALID_MASK
value|BIT_ULL(I40E_RXD_QW1_STATUS_TSYNVALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_STATUS_UMBCAST_SHIFT
value|I40E_RX_DESC_STATUS_UMBCAST
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_STATUS_UMBCAST_MASK
value|(0x3UL<< \ 					 I40E_RXD_QW1_STATUS_UMBCAST_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_rx_desc_fltstat_values
block|{
name|I40E_RX_DESC_FLTSTAT_NO_DATA
init|=
literal|0
block|,
name|I40E_RX_DESC_FLTSTAT_RSV_FD_ID
init|=
literal|1
block|,
comment|/* 16byte desc? FD_ID : RSV */
name|I40E_RX_DESC_FLTSTAT_RSV
init|=
literal|2
block|,
name|I40E_RX_DESC_FLTSTAT_RSS_HASH
init|=
literal|3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_RXD_PACKET_TYPE_UNICAST
value|0
end_define

begin_define
define|#
directive|define
name|I40E_RXD_PACKET_TYPE_MULTICAST
value|1
end_define

begin_define
define|#
directive|define
name|I40E_RXD_PACKET_TYPE_BROADCAST
value|2
end_define

begin_define
define|#
directive|define
name|I40E_RXD_PACKET_TYPE_MIRRORED
value|3
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_ERROR_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_ERROR_MASK
value|(0xFFUL<< I40E_RXD_QW1_ERROR_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_rx_desc_error_bits
block|{
comment|/* Note: These are predefined bit offsets */
name|I40E_RX_DESC_ERROR_RXE_SHIFT
init|=
literal|0
block|,
name|I40E_RX_DESC_ERROR_RECIPE_SHIFT
init|=
literal|1
block|,
name|I40E_RX_DESC_ERROR_HBO_SHIFT
init|=
literal|2
block|,
name|I40E_RX_DESC_ERROR_L3L4E_SHIFT
init|=
literal|3
block|,
comment|/* 3 BITS */
name|I40E_RX_DESC_ERROR_IPE_SHIFT
init|=
literal|3
block|,
name|I40E_RX_DESC_ERROR_L4E_SHIFT
init|=
literal|4
block|,
name|I40E_RX_DESC_ERROR_EIPE_SHIFT
init|=
literal|5
block|,
name|I40E_RX_DESC_ERROR_OVERSIZE_SHIFT
init|=
literal|6
block|,
name|I40E_RX_DESC_ERROR_PPRS_SHIFT
init|=
literal|7
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_desc_error_l3l4e_fcoe_masks
block|{
name|I40E_RX_DESC_ERROR_L3L4E_NONE
init|=
literal|0
block|,
name|I40E_RX_DESC_ERROR_L3L4E_PROT
init|=
literal|1
block|,
name|I40E_RX_DESC_ERROR_L3L4E_FC
init|=
literal|2
block|,
name|I40E_RX_DESC_ERROR_L3L4E_DMAC_ERR
init|=
literal|3
block|,
name|I40E_RX_DESC_ERROR_L3L4E_DMAC_WARN
init|=
literal|4
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_RXD_QW1_PTYPE_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_PTYPE_MASK
value|(0xFFULL<< I40E_RXD_QW1_PTYPE_SHIFT)
end_define

begin_comment
comment|/* Packet type non-ip values */
end_comment

begin_enum
enum|enum
name|i40e_rx_l2_ptype
block|{
name|I40E_RX_PTYPE_L2_RESERVED
init|=
literal|0
block|,
name|I40E_RX_PTYPE_L2_MAC_PAY2
init|=
literal|1
block|,
name|I40E_RX_PTYPE_L2_TIMESYNC_PAY2
init|=
literal|2
block|,
name|I40E_RX_PTYPE_L2_FIP_PAY2
init|=
literal|3
block|,
name|I40E_RX_PTYPE_L2_OUI_PAY2
init|=
literal|4
block|,
name|I40E_RX_PTYPE_L2_MACCNTRL_PAY2
init|=
literal|5
block|,
name|I40E_RX_PTYPE_L2_LLDP_PAY2
init|=
literal|6
block|,
name|I40E_RX_PTYPE_L2_ECP_PAY2
init|=
literal|7
block|,
name|I40E_RX_PTYPE_L2_EVB_PAY2
init|=
literal|8
block|,
name|I40E_RX_PTYPE_L2_QCN_PAY2
init|=
literal|9
block|,
name|I40E_RX_PTYPE_L2_EAPOL_PAY2
init|=
literal|10
block|,
name|I40E_RX_PTYPE_L2_ARP
init|=
literal|11
block|,
name|I40E_RX_PTYPE_L2_FCOE_PAY3
init|=
literal|12
block|,
name|I40E_RX_PTYPE_L2_FCOE_FCDATA_PAY3
init|=
literal|13
block|,
name|I40E_RX_PTYPE_L2_FCOE_FCRDY_PAY3
init|=
literal|14
block|,
name|I40E_RX_PTYPE_L2_FCOE_FCRSP_PAY3
init|=
literal|15
block|,
name|I40E_RX_PTYPE_L2_FCOE_FCOTHER_PA
init|=
literal|16
block|,
name|I40E_RX_PTYPE_L2_FCOE_VFT_PAY3
init|=
literal|17
block|,
name|I40E_RX_PTYPE_L2_FCOE_VFT_FCDATA
init|=
literal|18
block|,
name|I40E_RX_PTYPE_L2_FCOE_VFT_FCRDY
init|=
literal|19
block|,
name|I40E_RX_PTYPE_L2_FCOE_VFT_FCRSP
init|=
literal|20
block|,
name|I40E_RX_PTYPE_L2_FCOE_VFT_FCOTHER
init|=
literal|21
block|,
name|I40E_RX_PTYPE_GRENAT4_MAC_PAY3
init|=
literal|58
block|,
name|I40E_RX_PTYPE_GRENAT4_MACVLAN_IPV6_ICMP_PAY4
init|=
literal|87
block|,
name|I40E_RX_PTYPE_GRENAT6_MAC_PAY3
init|=
literal|124
block|,
name|I40E_RX_PTYPE_GRENAT6_MACVLAN_IPV6_ICMP_PAY4
init|=
literal|153
block|}
enum|;
end_enum

begin_struct
struct|struct
name|i40e_rx_ptype_decoded
block|{
name|u32
name|ptype
range|:
literal|8
decl_stmt|;
name|u32
name|known
range|:
literal|1
decl_stmt|;
name|u32
name|outer_ip
range|:
literal|1
decl_stmt|;
name|u32
name|outer_ip_ver
range|:
literal|1
decl_stmt|;
name|u32
name|outer_frag
range|:
literal|1
decl_stmt|;
name|u32
name|tunnel_type
range|:
literal|3
decl_stmt|;
name|u32
name|tunnel_end_prot
range|:
literal|2
decl_stmt|;
name|u32
name|tunnel_end_frag
range|:
literal|1
decl_stmt|;
name|u32
name|inner_prot
range|:
literal|4
decl_stmt|;
name|u32
name|payload_layer
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|i40e_rx_ptype_outer_ip
block|{
name|I40E_RX_PTYPE_OUTER_L2
init|=
literal|0
block|,
name|I40E_RX_PTYPE_OUTER_IP
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_ptype_outer_ip_ver
block|{
name|I40E_RX_PTYPE_OUTER_NONE
init|=
literal|0
block|,
name|I40E_RX_PTYPE_OUTER_IPV4
init|=
literal|0
block|,
name|I40E_RX_PTYPE_OUTER_IPV6
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_ptype_outer_fragmented
block|{
name|I40E_RX_PTYPE_NOT_FRAG
init|=
literal|0
block|,
name|I40E_RX_PTYPE_FRAG
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_ptype_tunnel_type
block|{
name|I40E_RX_PTYPE_TUNNEL_NONE
init|=
literal|0
block|,
name|I40E_RX_PTYPE_TUNNEL_IP_IP
init|=
literal|1
block|,
name|I40E_RX_PTYPE_TUNNEL_IP_GRENAT
init|=
literal|2
block|,
name|I40E_RX_PTYPE_TUNNEL_IP_GRENAT_MAC
init|=
literal|3
block|,
name|I40E_RX_PTYPE_TUNNEL_IP_GRENAT_MAC_VLAN
init|=
literal|4
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_ptype_tunnel_end_prot
block|{
name|I40E_RX_PTYPE_TUNNEL_END_NONE
init|=
literal|0
block|,
name|I40E_RX_PTYPE_TUNNEL_END_IPV4
init|=
literal|1
block|,
name|I40E_RX_PTYPE_TUNNEL_END_IPV6
init|=
literal|2
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_ptype_inner_prot
block|{
name|I40E_RX_PTYPE_INNER_PROT_NONE
init|=
literal|0
block|,
name|I40E_RX_PTYPE_INNER_PROT_UDP
init|=
literal|1
block|,
name|I40E_RX_PTYPE_INNER_PROT_TCP
init|=
literal|2
block|,
name|I40E_RX_PTYPE_INNER_PROT_SCTP
init|=
literal|3
block|,
name|I40E_RX_PTYPE_INNER_PROT_ICMP
init|=
literal|4
block|,
name|I40E_RX_PTYPE_INNER_PROT_TIMESYNC
init|=
literal|5
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_ptype_payload_layer
block|{
name|I40E_RX_PTYPE_PAYLOAD_LAYER_NONE
init|=
literal|0
block|,
name|I40E_RX_PTYPE_PAYLOAD_LAYER_PAY2
init|=
literal|1
block|,
name|I40E_RX_PTYPE_PAYLOAD_LAYER_PAY3
init|=
literal|2
block|,
name|I40E_RX_PTYPE_PAYLOAD_LAYER_PAY4
init|=
literal|3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_RX_PTYPE_BIT_MASK
value|0x0FFFFFFF
end_define

begin_define
define|#
directive|define
name|I40E_RX_PTYPE_SHIFT
value|56
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_LENGTH_PBUF_SHIFT
value|38
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_LENGTH_PBUF_MASK
value|(0x3FFFULL<< \ 					 I40E_RXD_QW1_LENGTH_PBUF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_LENGTH_HBUF_SHIFT
value|52
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_LENGTH_HBUF_MASK
value|(0x7FFULL<< \ 					 I40E_RXD_QW1_LENGTH_HBUF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_LENGTH_SPH_SHIFT
value|63
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_LENGTH_SPH_MASK
value|BIT_ULL(I40E_RXD_QW1_LENGTH_SPH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_NEXTP_SHIFT
value|38
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW1_NEXTP_MASK
value|(0x1FFFULL<< I40E_RXD_QW1_NEXTP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW2_EXT_STATUS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW2_EXT_STATUS_MASK
value|(0xFFFFFUL<< \ 					 I40E_RXD_QW2_EXT_STATUS_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_rx_desc_ext_status_bits
block|{
comment|/* Note: These are predefined bit offsets */
name|I40E_RX_DESC_EXT_STATUS_L2TAG2P_SHIFT
init|=
literal|0
block|,
name|I40E_RX_DESC_EXT_STATUS_L2TAG3P_SHIFT
init|=
literal|1
block|,
name|I40E_RX_DESC_EXT_STATUS_FLEXBL_SHIFT
init|=
literal|2
block|,
comment|/* 2 BITS */
name|I40E_RX_DESC_EXT_STATUS_FLEXBH_SHIFT
init|=
literal|4
block|,
comment|/* 2 BITS */
name|I40E_RX_DESC_EXT_STATUS_FDLONGB_SHIFT
init|=
literal|9
block|,
name|I40E_RX_DESC_EXT_STATUS_FCOELONGB_SHIFT
init|=
literal|10
block|,
name|I40E_RX_DESC_EXT_STATUS_PELONGB_SHIFT
init|=
literal|11
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_RXD_QW2_L2TAG2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW2_L2TAG2_MASK
value|(0xFFFFUL<< I40E_RXD_QW2_L2TAG2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW2_L2TAG3_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_RXD_QW2_L2TAG3_MASK
value|(0xFFFFUL<< I40E_RXD_QW2_L2TAG3_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_rx_desc_pe_status_bits
block|{
comment|/* Note: These are predefined bit offsets */
name|I40E_RX_DESC_PE_STATUS_QPID_SHIFT
init|=
literal|0
block|,
comment|/* 18 BITS */
name|I40E_RX_DESC_PE_STATUS_L4PORT_SHIFT
init|=
literal|0
block|,
comment|/* 16 BITS */
name|I40E_RX_DESC_PE_STATUS_IPINDEX_SHIFT
init|=
literal|16
block|,
comment|/* 8 BITS */
name|I40E_RX_DESC_PE_STATUS_QPIDHIT_SHIFT
init|=
literal|24
block|,
name|I40E_RX_DESC_PE_STATUS_APBVTHIT_SHIFT
init|=
literal|25
block|,
name|I40E_RX_DESC_PE_STATUS_PORTV_SHIFT
init|=
literal|26
block|,
name|I40E_RX_DESC_PE_STATUS_URG_SHIFT
init|=
literal|27
block|,
name|I40E_RX_DESC_PE_STATUS_IPFRAG_SHIFT
init|=
literal|28
block|,
name|I40E_RX_DESC_PE_STATUS_IPOPT_SHIFT
init|=
literal|29
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_RX_PROG_STATUS_DESC_LENGTH_SHIFT
value|38
end_define

begin_define
define|#
directive|define
name|I40E_RX_PROG_STATUS_DESC_LENGTH
value|0x2000000
end_define

begin_define
define|#
directive|define
name|I40E_RX_PROG_STATUS_DESC_QW1_PROGID_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_RX_PROG_STATUS_DESC_QW1_PROGID_MASK
value|(0x7UL<< \ 				I40E_RX_PROG_STATUS_DESC_QW1_PROGID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RX_PROG_STATUS_DESC_QW1_STATUS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_RX_PROG_STATUS_DESC_QW1_STATUS_MASK
value|(0x7FFFUL<< \ 				I40E_RX_PROG_STATUS_DESC_QW1_STATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_RX_PROG_STATUS_DESC_QW1_ERROR_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_RX_PROG_STATUS_DESC_QW1_ERROR_MASK
value|(0x3FUL<< \ 				I40E_RX_PROG_STATUS_DESC_QW1_ERROR_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_rx_prog_status_desc_status_bits
block|{
comment|/* Note: These are predefined bit offsets */
name|I40E_RX_PROG_STATUS_DESC_DD_SHIFT
init|=
literal|0
block|,
name|I40E_RX_PROG_STATUS_DESC_PROG_ID_SHIFT
init|=
literal|2
comment|/* 3 BITS */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_prog_status_desc_prog_id_masks
block|{
name|I40E_RX_PROG_STATUS_DESC_FD_FILTER_STATUS
init|=
literal|1
block|,
name|I40E_RX_PROG_STATUS_DESC_FCOE_CTXT_PROG_STATUS
init|=
literal|2
block|,
name|I40E_RX_PROG_STATUS_DESC_FCOE_CTXT_INVL_STATUS
init|=
literal|4
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|i40e_rx_prog_status_desc_error_bits
block|{
comment|/* Note: These are predefined bit offsets */
name|I40E_RX_PROG_STATUS_DESC_FD_TBL_FULL_SHIFT
init|=
literal|0
block|,
name|I40E_RX_PROG_STATUS_DESC_NO_FD_ENTRY_SHIFT
init|=
literal|1
block|,
name|I40E_RX_PROG_STATUS_DESC_FCOE_TBL_FULL_SHIFT
init|=
literal|2
block|,
name|I40E_RX_PROG_STATUS_DESC_FCOE_CONFLICT_SHIFT
init|=
literal|3
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_TWO_BIT_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|I40E_THREE_BIT_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|I40E_FOUR_BIT_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|I40E_EIGHTEEN_BIT_MASK
value|0x3FFFF
end_define

begin_comment
comment|/* TX Descriptor */
end_comment

begin_struct
struct|struct
name|i40e_tx_desc
block|{
name|__le64
name|buffer_addr
decl_stmt|;
comment|/* Address of descriptor's data buf */
name|__le64
name|cmd_type_offset_bsz
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_TXD_QW1_DTYPE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_DTYPE_MASK
value|(0xFUL<< I40E_TXD_QW1_DTYPE_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_tx_desc_dtype_value
block|{
name|I40E_TX_DESC_DTYPE_DATA
init|=
literal|0x0
block|,
name|I40E_TX_DESC_DTYPE_NOP
init|=
literal|0x1
block|,
comment|/* same as Context desc */
name|I40E_TX_DESC_DTYPE_CONTEXT
init|=
literal|0x1
block|,
name|I40E_TX_DESC_DTYPE_FCOE_CTX
init|=
literal|0x2
block|,
name|I40E_TX_DESC_DTYPE_FILTER_PROG
init|=
literal|0x8
block|,
name|I40E_TX_DESC_DTYPE_DDP_CTX
init|=
literal|0x9
block|,
name|I40E_TX_DESC_DTYPE_FLEX_DATA
init|=
literal|0xB
block|,
name|I40E_TX_DESC_DTYPE_FLEX_CTX_1
init|=
literal|0xC
block|,
name|I40E_TX_DESC_DTYPE_FLEX_CTX_2
init|=
literal|0xD
block|,
name|I40E_TX_DESC_DTYPE_DESC_DONE
init|=
literal|0xF
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_TXD_QW1_CMD_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_CMD_MASK
value|(0x3FFUL<< I40E_TXD_QW1_CMD_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_tx_desc_cmd_bits
block|{
name|I40E_TX_DESC_CMD_EOP
init|=
literal|0x0001
block|,
name|I40E_TX_DESC_CMD_RS
init|=
literal|0x0002
block|,
name|I40E_TX_DESC_CMD_ICRC
init|=
literal|0x0004
block|,
name|I40E_TX_DESC_CMD_IL2TAG1
init|=
literal|0x0008
block|,
name|I40E_TX_DESC_CMD_DUMMY
init|=
literal|0x0010
block|,
name|I40E_TX_DESC_CMD_IIPT_NONIP
init|=
literal|0x0000
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_IIPT_IPV6
init|=
literal|0x0020
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_IIPT_IPV4
init|=
literal|0x0040
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_IIPT_IPV4_CSUM
init|=
literal|0x0060
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_FCOET
init|=
literal|0x0080
block|,
name|I40E_TX_DESC_CMD_L4T_EOFT_UNK
init|=
literal|0x0000
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_L4T_EOFT_TCP
init|=
literal|0x0100
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_L4T_EOFT_SCTP
init|=
literal|0x0200
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_L4T_EOFT_UDP
init|=
literal|0x0300
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_L4T_EOFT_EOF_N
init|=
literal|0x0000
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_L4T_EOFT_EOF_T
init|=
literal|0x0100
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_L4T_EOFT_EOF_NI
init|=
literal|0x0200
block|,
comment|/* 2 BITS */
name|I40E_TX_DESC_CMD_L4T_EOFT_EOF_A
init|=
literal|0x0300
block|,
comment|/* 2 BITS */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_TXD_QW1_OFFSET_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_OFFSET_MASK
value|(0x3FFFFULL<< \ 					 I40E_TXD_QW1_OFFSET_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_tx_desc_length_fields
block|{
comment|/* Note: These are predefined bit offsets */
name|I40E_TX_DESC_LENGTH_MACLEN_SHIFT
init|=
literal|0
block|,
comment|/* 7 BITS */
name|I40E_TX_DESC_LENGTH_IPLEN_SHIFT
init|=
literal|7
block|,
comment|/* 7 BITS */
name|I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT
init|=
literal|14
comment|/* 4 BITS */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_TXD_QW1_MACLEN_MASK
value|(0x7FUL<< I40E_TX_DESC_LENGTH_MACLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_IPLEN_MASK
value|(0x7FUL<< I40E_TX_DESC_LENGTH_IPLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_L4LEN_MASK
value|(0xFUL<< I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_FCLEN_MASK
value|(0xFUL<< I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_TX_BUF_SZ_SHIFT
value|34
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_TX_BUF_SZ_MASK
value|(0x3FFFULL<< \ 					 I40E_TXD_QW1_TX_BUF_SZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_L2TAG1_SHIFT
value|48
end_define

begin_define
define|#
directive|define
name|I40E_TXD_QW1_L2TAG1_MASK
value|(0xFFFFULL<< I40E_TXD_QW1_L2TAG1_SHIFT)
end_define

begin_comment
comment|/* Context descriptors */
end_comment

begin_struct
struct|struct
name|i40e_tx_context_desc
block|{
name|__le32
name|tunneling_params
decl_stmt|;
name|__le16
name|l2tag2
decl_stmt|;
name|__le16
name|rsvd
decl_stmt|;
name|__le64
name|type_cmd_tso_mss
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_DTYPE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_DTYPE_MASK
value|(0xFUL<< I40E_TXD_CTX_QW1_DTYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_CMD_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_CMD_MASK
value|(0xFFFFUL<< I40E_TXD_CTX_QW1_CMD_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_tx_ctx_desc_cmd_bits
block|{
name|I40E_TX_CTX_DESC_TSO
init|=
literal|0x01
block|,
name|I40E_TX_CTX_DESC_TSYN
init|=
literal|0x02
block|,
name|I40E_TX_CTX_DESC_IL2TAG2
init|=
literal|0x04
block|,
name|I40E_TX_CTX_DESC_IL2TAG2_IL2H
init|=
literal|0x08
block|,
name|I40E_TX_CTX_DESC_SWTCH_NOTAG
init|=
literal|0x00
block|,
name|I40E_TX_CTX_DESC_SWTCH_UPLINK
init|=
literal|0x10
block|,
name|I40E_TX_CTX_DESC_SWTCH_LOCAL
init|=
literal|0x20
block|,
name|I40E_TX_CTX_DESC_SWTCH_VSI
init|=
literal|0x30
block|,
name|I40E_TX_CTX_DESC_SWPE
init|=
literal|0x40
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_TSO_LEN_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_TSO_LEN_MASK
value|(0x3FFFFULL<< \ 					 I40E_TXD_CTX_QW1_TSO_LEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_MSS_SHIFT
value|50
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_MSS_MASK
value|(0x3FFFULL<< \ 					 I40E_TXD_CTX_QW1_MSS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_VSI_SHIFT
value|50
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW1_VSI_MASK
value|(0x1FFULL<< I40E_TXD_CTX_QW1_VSI_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_EXT_IP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_EXT_IP_MASK
value|(0x3ULL<< \ 					 I40E_TXD_CTX_QW0_EXT_IP_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_tx_ctx_desc_eipt_offload
block|{
name|I40E_TX_CTX_EXT_IP_NONE
init|=
literal|0x0
block|,
name|I40E_TX_CTX_EXT_IP_IPV6
init|=
literal|0x1
block|,
name|I40E_TX_CTX_EXT_IP_IPV4_NO_CSUM
init|=
literal|0x2
block|,
name|I40E_TX_CTX_EXT_IP_IPV4
init|=
literal|0x3
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_EXT_IPLEN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_EXT_IPLEN_MASK
value|(0x3FULL<< \ 					 I40E_TXD_CTX_QW0_EXT_IPLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_NATT_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_NATT_MASK
value|(0x3ULL<< I40E_TXD_CTX_QW0_NATT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_UDP_TUNNELING
value|BIT_ULL(I40E_TXD_CTX_QW0_NATT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_GRE_TUNNELING
value|(0x2ULL<< I40E_TXD_CTX_QW0_NATT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_EIP_NOINC_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_EIP_NOINC_MASK
value|BIT_ULL(I40E_TXD_CTX_QW0_EIP_NOINC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_EIP_NOINC_IPID_CONST
value|I40E_TXD_CTX_QW0_EIP_NOINC_MASK
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_NATLEN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_NATLEN_MASK
value|(0X7FULL<< \ 					 I40E_TXD_CTX_QW0_NATLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_DECTTL_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_DECTTL_MASK
value|(0xFULL<< \ 					 I40E_TXD_CTX_QW0_DECTTL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_L4T_CS_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_TXD_CTX_QW0_L4T_CS_MASK
value|BIT_ULL(I40E_TXD_CTX_QW0_L4T_CS_SHIFT)
end_define

begin_struct
struct|struct
name|i40e_nop_desc
block|{
name|__le64
name|rsvd
decl_stmt|;
name|__le64
name|dtype_cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_TXD_NOP_QW1_DTYPE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_TXD_NOP_QW1_DTYPE_MASK
value|(0xFUL<< I40E_TXD_NOP_QW1_DTYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_NOP_QW1_CMD_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_TXD_NOP_QW1_CMD_MASK
value|(0x7FUL<< I40E_TXD_NOP_QW1_CMD_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_tx_nop_desc_cmd_bits
block|{
comment|/* Note: These are predefined bit offsets */
name|I40E_TX_NOP_DESC_EOP_SHIFT
init|=
literal|0
block|,
name|I40E_TX_NOP_DESC_RS_SHIFT
init|=
literal|1
block|,
name|I40E_TX_NOP_DESC_RSV_SHIFT
init|=
literal|2
comment|/* 5 bits */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|i40e_filter_program_desc
block|{
name|__le32
name|qindex_flex_ptype_vsi
decl_stmt|;
name|__le32
name|rsvd
decl_stmt|;
name|__le32
name|dtype_cmd_cntindex
decl_stmt|;
name|__le32
name|fd_id
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW0_QINDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW0_QINDEX_MASK
value|(0x7FFUL<< \ 					 I40E_TXD_FLTR_QW0_QINDEX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW0_FLEXOFF_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW0_FLEXOFF_MASK
value|(0x7UL<< \ 					 I40E_TXD_FLTR_QW0_FLEXOFF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW0_PCTYPE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW0_PCTYPE_MASK
value|(0x3FUL<< \ 					 I40E_TXD_FLTR_QW0_PCTYPE_SHIFT)
end_define

begin_comment
comment|/* Packet Classifier Types for filters */
end_comment

begin_enum
enum|enum
name|i40e_filter_pctype
block|{
comment|/* Note: Values 0-28 are reserved for future use. 	 * Value 29, 30, 32 are not supported on XL710 and X710. 	 */
name|I40E_FILTER_PCTYPE_NONF_UNICAST_IPV4_UDP
init|=
literal|29
block|,
name|I40E_FILTER_PCTYPE_NONF_MULTICAST_IPV4_UDP
init|=
literal|30
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV4_UDP
init|=
literal|31
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV4_TCP_SYN_NO_ACK
init|=
literal|32
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV4_TCP
init|=
literal|33
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV4_SCTP
init|=
literal|34
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV4_OTHER
init|=
literal|35
block|,
name|I40E_FILTER_PCTYPE_FRAG_IPV4
init|=
literal|36
block|,
comment|/* Note: Values 37-38 are reserved for future use. 	 * Value 39, 40, 42 are not supported on XL710 and X710. 	 */
name|I40E_FILTER_PCTYPE_NONF_UNICAST_IPV6_UDP
init|=
literal|39
block|,
name|I40E_FILTER_PCTYPE_NONF_MULTICAST_IPV6_UDP
init|=
literal|40
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV6_UDP
init|=
literal|41
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV6_TCP_SYN_NO_ACK
init|=
literal|42
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV6_TCP
init|=
literal|43
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV6_SCTP
init|=
literal|44
block|,
name|I40E_FILTER_PCTYPE_NONF_IPV6_OTHER
init|=
literal|45
block|,
name|I40E_FILTER_PCTYPE_FRAG_IPV6
init|=
literal|46
block|,
comment|/* Note: Value 47 is reserved for future use */
name|I40E_FILTER_PCTYPE_FCOE_OX
init|=
literal|48
block|,
name|I40E_FILTER_PCTYPE_FCOE_RX
init|=
literal|49
block|,
name|I40E_FILTER_PCTYPE_FCOE_OTHER
init|=
literal|50
block|,
comment|/* Note: Values 51-62 are reserved for future use */
name|I40E_FILTER_PCTYPE_L2_PAYLOAD
init|=
literal|63
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|i40e_filter_program_desc_dest
block|{
name|I40E_FILTER_PROGRAM_DESC_DEST_DROP_PACKET
init|=
literal|0x0
block|,
name|I40E_FILTER_PROGRAM_DESC_DEST_DIRECT_PACKET_QINDEX
init|=
literal|0x1
block|,
name|I40E_FILTER_PROGRAM_DESC_DEST_DIRECT_PACKET_OTHER
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|i40e_filter_program_desc_fd_status
block|{
name|I40E_FILTER_PROGRAM_DESC_FD_STATUS_NONE
init|=
literal|0x0
block|,
name|I40E_FILTER_PROGRAM_DESC_FD_STATUS_FD_ID
init|=
literal|0x1
block|,
name|I40E_FILTER_PROGRAM_DESC_FD_STATUS_FD_ID_4FLEX_BYTES
init|=
literal|0x2
block|,
name|I40E_FILTER_PROGRAM_DESC_FD_STATUS_8FLEX_BYTES
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW0_DEST_VSI_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW0_DEST_VSI_MASK
value|(0x1FFUL<< \ 					 I40E_TXD_FLTR_QW0_DEST_VSI_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_DTYPE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_DTYPE_MASK
value|(0xFUL<< I40E_TXD_FLTR_QW1_DTYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_CMD_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_CMD_MASK
value|(0xFFFFULL<< \ 					 I40E_TXD_FLTR_QW1_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_PCMD_SHIFT
value|(0x0ULL + I40E_TXD_FLTR_QW1_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_PCMD_MASK
value|(0x7ULL<< I40E_TXD_FLTR_QW1_PCMD_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_filter_program_desc_pcmd
block|{
name|I40E_FILTER_PROGRAM_DESC_PCMD_ADD_UPDATE
init|=
literal|0x1
block|,
name|I40E_FILTER_PROGRAM_DESC_PCMD_REMOVE
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_DEST_SHIFT
value|(0x3ULL + I40E_TXD_FLTR_QW1_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_DEST_MASK
value|(0x3ULL<< I40E_TXD_FLTR_QW1_DEST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_CNT_ENA_SHIFT
value|(0x7ULL + I40E_TXD_FLTR_QW1_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_CNT_ENA_MASK
value|BIT_ULL(I40E_TXD_FLTR_QW1_CNT_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_FD_STATUS_SHIFT
value|(0x9ULL + \ 						 I40E_TXD_FLTR_QW1_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_FD_STATUS_MASK
value|(0x3ULL<< \ 					  I40E_TXD_FLTR_QW1_FD_STATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_ATR_SHIFT
value|(0xEULL + \ 					 I40E_TXD_FLTR_QW1_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_ATR_MASK
value|BIT_ULL(I40E_TXD_FLTR_QW1_ATR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_CNTINDEX_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_TXD_FLTR_QW1_CNTINDEX_MASK
value|(0x1FFUL<< \ 					 I40E_TXD_FLTR_QW1_CNTINDEX_SHIFT)
end_define

begin_enum
enum|enum
name|i40e_filter_type
block|{
name|I40E_FLOW_DIRECTOR_FLTR
init|=
literal|0
block|,
name|I40E_PE_QUAD_HASH_FLTR
init|=
literal|1
block|,
name|I40E_ETHERTYPE_FLTR
block|,
name|I40E_FCOE_CTX_FLTR
block|,
name|I40E_MAC_VLAN_FLTR
block|,
name|I40E_HASH_FLTR
block|}
enum|;
end_enum

begin_struct
struct|struct
name|i40e_vsi_context
block|{
name|u16
name|seid
decl_stmt|;
name|u16
name|uplink_seid
decl_stmt|;
name|u16
name|vsi_number
decl_stmt|;
name|u16
name|vsis_allocated
decl_stmt|;
name|u16
name|vsis_unallocated
decl_stmt|;
name|u16
name|flags
decl_stmt|;
name|u8
name|pf_num
decl_stmt|;
name|u8
name|vf_num
decl_stmt|;
name|u8
name|connection_type
decl_stmt|;
name|struct
name|i40e_aqc_vsi_properties_data
name|info
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_veb_context
block|{
name|u16
name|seid
decl_stmt|;
name|u16
name|uplink_seid
decl_stmt|;
name|u16
name|veb_number
decl_stmt|;
name|u16
name|vebs_allocated
decl_stmt|;
name|u16
name|vebs_unallocated
decl_stmt|;
name|u16
name|flags
decl_stmt|;
name|struct
name|i40e_aqc_get_veb_parameters_completion
name|info
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Statistics collected by each port, VSI, VEB, and S-channel */
end_comment

begin_struct
struct|struct
name|i40e_eth_stats
block|{
name|u64
name|rx_bytes
decl_stmt|;
comment|/* gorc */
name|u64
name|rx_unicast
decl_stmt|;
comment|/* uprc */
name|u64
name|rx_multicast
decl_stmt|;
comment|/* mprc */
name|u64
name|rx_broadcast
decl_stmt|;
comment|/* bprc */
name|u64
name|rx_discards
decl_stmt|;
comment|/* rdpc */
name|u64
name|rx_unknown_protocol
decl_stmt|;
comment|/* rupp */
name|u64
name|tx_bytes
decl_stmt|;
comment|/* gotc */
name|u64
name|tx_unicast
decl_stmt|;
comment|/* uptc */
name|u64
name|tx_multicast
decl_stmt|;
comment|/* mptc */
name|u64
name|tx_broadcast
decl_stmt|;
comment|/* bptc */
name|u64
name|tx_discards
decl_stmt|;
comment|/* tdpc */
name|u64
name|tx_errors
decl_stmt|;
comment|/* tepc */
block|}
struct|;
end_struct

begin_comment
comment|/* Statistics collected per VEB per TC */
end_comment

begin_struct
struct|struct
name|i40e_veb_tc_stats
block|{
name|u64
name|tc_rx_packets
index|[
name|I40E_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
name|u64
name|tc_rx_bytes
index|[
name|I40E_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
name|u64
name|tc_tx_packets
index|[
name|I40E_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
name|u64
name|tc_tx_bytes
index|[
name|I40E_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Statistics collected by the MAC */
end_comment

begin_struct
struct|struct
name|i40e_hw_port_stats
block|{
comment|/* eth stats collected by the port */
name|struct
name|i40e_eth_stats
name|eth
decl_stmt|;
comment|/* additional port specific stats */
name|u64
name|tx_dropped_link_down
decl_stmt|;
comment|/* tdold */
name|u64
name|crc_errors
decl_stmt|;
comment|/* crcerrs */
name|u64
name|illegal_bytes
decl_stmt|;
comment|/* illerrc */
name|u64
name|error_bytes
decl_stmt|;
comment|/* errbc */
name|u64
name|mac_local_faults
decl_stmt|;
comment|/* mlfc */
name|u64
name|mac_remote_faults
decl_stmt|;
comment|/* mrfc */
name|u64
name|rx_length_errors
decl_stmt|;
comment|/* rlec */
name|u64
name|link_xon_rx
decl_stmt|;
comment|/* lxonrxc */
name|u64
name|link_xoff_rx
decl_stmt|;
comment|/* lxoffrxc */
name|u64
name|priority_xon_rx
index|[
literal|8
index|]
decl_stmt|;
comment|/* pxonrxc[8] */
name|u64
name|priority_xoff_rx
index|[
literal|8
index|]
decl_stmt|;
comment|/* pxoffrxc[8] */
name|u64
name|link_xon_tx
decl_stmt|;
comment|/* lxontxc */
name|u64
name|link_xoff_tx
decl_stmt|;
comment|/* lxofftxc */
name|u64
name|priority_xon_tx
index|[
literal|8
index|]
decl_stmt|;
comment|/* pxontxc[8] */
name|u64
name|priority_xoff_tx
index|[
literal|8
index|]
decl_stmt|;
comment|/* pxofftxc[8] */
name|u64
name|priority_xon_2_xoff
index|[
literal|8
index|]
decl_stmt|;
comment|/* pxon2offc[8] */
name|u64
name|rx_size_64
decl_stmt|;
comment|/* prc64 */
name|u64
name|rx_size_127
decl_stmt|;
comment|/* prc127 */
name|u64
name|rx_size_255
decl_stmt|;
comment|/* prc255 */
name|u64
name|rx_size_511
decl_stmt|;
comment|/* prc511 */
name|u64
name|rx_size_1023
decl_stmt|;
comment|/* prc1023 */
name|u64
name|rx_size_1522
decl_stmt|;
comment|/* prc1522 */
name|u64
name|rx_size_big
decl_stmt|;
comment|/* prc9522 */
name|u64
name|rx_undersize
decl_stmt|;
comment|/* ruc */
name|u64
name|rx_fragments
decl_stmt|;
comment|/* rfc */
name|u64
name|rx_oversize
decl_stmt|;
comment|/* roc */
name|u64
name|rx_jabber
decl_stmt|;
comment|/* rjc */
name|u64
name|tx_size_64
decl_stmt|;
comment|/* ptc64 */
name|u64
name|tx_size_127
decl_stmt|;
comment|/* ptc127 */
name|u64
name|tx_size_255
decl_stmt|;
comment|/* ptc255 */
name|u64
name|tx_size_511
decl_stmt|;
comment|/* ptc511 */
name|u64
name|tx_size_1023
decl_stmt|;
comment|/* ptc1023 */
name|u64
name|tx_size_1522
decl_stmt|;
comment|/* ptc1522 */
name|u64
name|tx_size_big
decl_stmt|;
comment|/* ptc9522 */
name|u64
name|mac_short_packet_dropped
decl_stmt|;
comment|/* mspdc */
name|u64
name|checksum_error
decl_stmt|;
comment|/* xec */
comment|/* flow director stats */
name|u64
name|fd_atr_match
decl_stmt|;
name|u64
name|fd_sb_match
decl_stmt|;
name|u64
name|fd_atr_tunnel_match
decl_stmt|;
name|u32
name|fd_atr_status
decl_stmt|;
name|u32
name|fd_sb_status
decl_stmt|;
comment|/* EEE LPI */
name|u32
name|tx_lpi_status
decl_stmt|;
name|u32
name|rx_lpi_status
decl_stmt|;
name|u64
name|tx_lpi_count
decl_stmt|;
comment|/* etlpic */
name|u64
name|rx_lpi_count
decl_stmt|;
comment|/* erlpic */
block|}
struct|;
end_struct

begin_comment
comment|/* Checksum and Shadow RAM pointers */
end_comment

begin_define
define|#
directive|define
name|I40E_SR_NVM_CONTROL_WORD
value|0x00
end_define

begin_define
define|#
directive|define
name|I40E_SR_PCIE_ANALOG_CONFIG_PTR
value|0x03
end_define

begin_define
define|#
directive|define
name|I40E_SR_PHY_ANALOG_CONFIG_PTR
value|0x04
end_define

begin_define
define|#
directive|define
name|I40E_SR_OPTION_ROM_PTR
value|0x05
end_define

begin_define
define|#
directive|define
name|I40E_SR_RO_PCIR_REGS_AUTO_LOAD_PTR
value|0x06
end_define

begin_define
define|#
directive|define
name|I40E_SR_AUTO_GENERATED_POINTERS_PTR
value|0x07
end_define

begin_define
define|#
directive|define
name|I40E_SR_PCIR_REGS_AUTO_LOAD_PTR
value|0x08
end_define

begin_define
define|#
directive|define
name|I40E_SR_EMP_GLOBAL_MODULE_PTR
value|0x09
end_define

begin_define
define|#
directive|define
name|I40E_SR_RO_PCIE_LCB_PTR
value|0x0A
end_define

begin_define
define|#
directive|define
name|I40E_SR_EMP_IMAGE_PTR
value|0x0B
end_define

begin_define
define|#
directive|define
name|I40E_SR_PE_IMAGE_PTR
value|0x0C
end_define

begin_define
define|#
directive|define
name|I40E_SR_CSR_PROTECTED_LIST_PTR
value|0x0D
end_define

begin_define
define|#
directive|define
name|I40E_SR_MNG_CONFIG_PTR
value|0x0E
end_define

begin_define
define|#
directive|define
name|I40E_SR_EMP_MODULE_PTR
value|0x0F
end_define

begin_define
define|#
directive|define
name|I40E_SR_PBA_FLAGS
value|0x15
end_define

begin_define
define|#
directive|define
name|I40E_SR_PBA_BLOCK_PTR
value|0x16
end_define

begin_define
define|#
directive|define
name|I40E_SR_BOOT_CONFIG_PTR
value|0x17
end_define

begin_define
define|#
directive|define
name|I40E_NVM_OEM_VER_OFF
value|0x83
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_DEV_STARTER_VERSION
value|0x18
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_WAKE_ON_LAN
value|0x19
end_define

begin_define
define|#
directive|define
name|I40E_SR_ALTERNATE_SAN_MAC_ADDRESS_PTR
value|0x27
end_define

begin_define
define|#
directive|define
name|I40E_SR_PERMANENT_SAN_MAC_ADDRESS_PTR
value|0x28
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_MAP_VERSION
value|0x29
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_IMAGE_VERSION
value|0x2A
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_STRUCTURE_VERSION
value|0x2B
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_EETRACK_LO
value|0x2D
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_EETRACK_HI
value|0x2E
end_define

begin_define
define|#
directive|define
name|I40E_SR_VPD_PTR
value|0x2F
end_define

begin_define
define|#
directive|define
name|I40E_SR_PXE_SETUP_PTR
value|0x30
end_define

begin_define
define|#
directive|define
name|I40E_SR_PXE_CONFIG_CUST_OPTIONS_PTR
value|0x31
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_ORIGINAL_EETRACK_LO
value|0x34
end_define

begin_define
define|#
directive|define
name|I40E_SR_NVM_ORIGINAL_EETRACK_HI
value|0x35
end_define

begin_define
define|#
directive|define
name|I40E_SR_SW_ETHERNET_MAC_ADDRESS_PTR
value|0x37
end_define

begin_define
define|#
directive|define
name|I40E_SR_POR_REGS_AUTO_LOAD_PTR
value|0x38
end_define

begin_define
define|#
directive|define
name|I40E_SR_EMPR_REGS_AUTO_LOAD_PTR
value|0x3A
end_define

begin_define
define|#
directive|define
name|I40E_SR_GLOBR_REGS_AUTO_LOAD_PTR
value|0x3B
end_define

begin_define
define|#
directive|define
name|I40E_SR_CORER_REGS_AUTO_LOAD_PTR
value|0x3C
end_define

begin_define
define|#
directive|define
name|I40E_SR_PHY_ACTIVITY_LIST_PTR
value|0x3D
end_define

begin_define
define|#
directive|define
name|I40E_SR_PCIE_ALT_AUTO_LOAD_PTR
value|0x3E
end_define

begin_define
define|#
directive|define
name|I40E_SR_SW_CHECKSUM_WORD
value|0x3F
end_define

begin_define
define|#
directive|define
name|I40E_SR_1ST_FREE_PROVISION_AREA_PTR
value|0x40
end_define

begin_define
define|#
directive|define
name|I40E_SR_4TH_FREE_PROVISION_AREA_PTR
value|0x42
end_define

begin_define
define|#
directive|define
name|I40E_SR_3RD_FREE_PROVISION_AREA_PTR
value|0x44
end_define

begin_define
define|#
directive|define
name|I40E_SR_2ND_FREE_PROVISION_AREA_PTR
value|0x46
end_define

begin_define
define|#
directive|define
name|I40E_SR_EMP_SR_SETTINGS_PTR
value|0x48
end_define

begin_define
define|#
directive|define
name|I40E_SR_FEATURE_CONFIGURATION_PTR
value|0x49
end_define

begin_define
define|#
directive|define
name|I40E_SR_CONFIGURATION_METADATA_PTR
value|0x4D
end_define

begin_define
define|#
directive|define
name|I40E_SR_IMMEDIATE_VALUES_PTR
value|0x4E
end_define

begin_comment
comment|/* Auxiliary field, mask and shift definition for Shadow RAM and NVM Flash */
end_comment

begin_define
define|#
directive|define
name|I40E_SR_VPD_MODULE_MAX_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|I40E_SR_PCIE_ALT_MODULE_MAX_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|I40E_SR_CONTROL_WORD_1_SHIFT
value|0x06
end_define

begin_define
define|#
directive|define
name|I40E_SR_CONTROL_WORD_1_MASK
value|(0x03<< I40E_SR_CONTROL_WORD_1_SHIFT)
end_define

begin_comment
comment|/* Shadow RAM related */
end_comment

begin_define
define|#
directive|define
name|I40E_SR_SECTOR_SIZE_IN_WORDS
value|0x800
end_define

begin_define
define|#
directive|define
name|I40E_SR_BUF_ALIGNMENT
value|4096
end_define

begin_define
define|#
directive|define
name|I40E_SR_WORDS_IN_1KB
value|512
end_define

begin_comment
comment|/* Checksum should be calculated such that after adding all the words,  * including the checksum word itself, the sum should be 0xBABA.  */
end_comment

begin_define
define|#
directive|define
name|I40E_SR_SW_CHECKSUM_BASE
value|0xBABA
end_define

begin_define
define|#
directive|define
name|I40E_SRRD_SRCTL_ATTEMPTS
value|100000
end_define

begin_enum
enum|enum
name|i40e_switch_element_types
block|{
name|I40E_SWITCH_ELEMENT_TYPE_MAC
init|=
literal|1
block|,
name|I40E_SWITCH_ELEMENT_TYPE_PF
init|=
literal|2
block|,
name|I40E_SWITCH_ELEMENT_TYPE_VF
init|=
literal|3
block|,
name|I40E_SWITCH_ELEMENT_TYPE_EMP
init|=
literal|4
block|,
name|I40E_SWITCH_ELEMENT_TYPE_BMC
init|=
literal|6
block|,
name|I40E_SWITCH_ELEMENT_TYPE_PE
init|=
literal|16
block|,
name|I40E_SWITCH_ELEMENT_TYPE_VEB
init|=
literal|17
block|,
name|I40E_SWITCH_ELEMENT_TYPE_PA
init|=
literal|18
block|,
name|I40E_SWITCH_ELEMENT_TYPE_VSI
init|=
literal|19
block|, }
enum|;
end_enum

begin_comment
comment|/* Supported EtherType filters */
end_comment

begin_enum
enum|enum
name|i40e_ether_type_index
block|{
name|I40E_ETHER_TYPE_1588
init|=
literal|0
block|,
name|I40E_ETHER_TYPE_FIP
init|=
literal|1
block|,
name|I40E_ETHER_TYPE_OUI_EXTENDED
init|=
literal|2
block|,
name|I40E_ETHER_TYPE_MAC_CONTROL
init|=
literal|3
block|,
name|I40E_ETHER_TYPE_LLDP
init|=
literal|4
block|,
name|I40E_ETHER_TYPE_EVB_PROTOCOL1
init|=
literal|5
block|,
name|I40E_ETHER_TYPE_EVB_PROTOCOL2
init|=
literal|6
block|,
name|I40E_ETHER_TYPE_QCN_CNM
init|=
literal|7
block|,
name|I40E_ETHER_TYPE_8021X
init|=
literal|8
block|,
name|I40E_ETHER_TYPE_ARP
init|=
literal|9
block|,
name|I40E_ETHER_TYPE_RSV1
init|=
literal|10
block|,
name|I40E_ETHER_TYPE_RSV2
init|=
literal|11
block|, }
enum|;
end_enum

begin_comment
comment|/* Filter context base size is 1K */
end_comment

begin_define
define|#
directive|define
name|I40E_HASH_FILTER_BASE_SIZE
value|1024
end_define

begin_comment
comment|/* Supported Hash filter values */
end_comment

begin_enum
enum|enum
name|i40e_hash_filter_size
block|{
name|I40E_HASH_FILTER_SIZE_1K
init|=
literal|0
block|,
name|I40E_HASH_FILTER_SIZE_2K
init|=
literal|1
block|,
name|I40E_HASH_FILTER_SIZE_4K
init|=
literal|2
block|,
name|I40E_HASH_FILTER_SIZE_8K
init|=
literal|3
block|,
name|I40E_HASH_FILTER_SIZE_16K
init|=
literal|4
block|,
name|I40E_HASH_FILTER_SIZE_32K
init|=
literal|5
block|,
name|I40E_HASH_FILTER_SIZE_64K
init|=
literal|6
block|,
name|I40E_HASH_FILTER_SIZE_128K
init|=
literal|7
block|,
name|I40E_HASH_FILTER_SIZE_256K
init|=
literal|8
block|,
name|I40E_HASH_FILTER_SIZE_512K
init|=
literal|9
block|,
name|I40E_HASH_FILTER_SIZE_1M
init|=
literal|10
block|, }
enum|;
end_enum

begin_comment
comment|/* DMA context base size is 0.5K */
end_comment

begin_define
define|#
directive|define
name|I40E_DMA_CNTX_BASE_SIZE
value|512
end_define

begin_comment
comment|/* Supported DMA context values */
end_comment

begin_enum
enum|enum
name|i40e_dma_cntx_size
block|{
name|I40E_DMA_CNTX_SIZE_512
init|=
literal|0
block|,
name|I40E_DMA_CNTX_SIZE_1K
init|=
literal|1
block|,
name|I40E_DMA_CNTX_SIZE_2K
init|=
literal|2
block|,
name|I40E_DMA_CNTX_SIZE_4K
init|=
literal|3
block|,
name|I40E_DMA_CNTX_SIZE_8K
init|=
literal|4
block|,
name|I40E_DMA_CNTX_SIZE_16K
init|=
literal|5
block|,
name|I40E_DMA_CNTX_SIZE_32K
init|=
literal|6
block|,
name|I40E_DMA_CNTX_SIZE_64K
init|=
literal|7
block|,
name|I40E_DMA_CNTX_SIZE_128K
init|=
literal|8
block|,
name|I40E_DMA_CNTX_SIZE_256K
init|=
literal|9
block|, }
enum|;
end_enum

begin_comment
comment|/* Supported Hash look up table (LUT) sizes */
end_comment

begin_enum
enum|enum
name|i40e_hash_lut_size
block|{
name|I40E_HASH_LUT_SIZE_128
init|=
literal|0
block|,
name|I40E_HASH_LUT_SIZE_512
init|=
literal|1
block|, }
enum|;
end_enum

begin_comment
comment|/* Structure to hold a per PF filter control settings */
end_comment

begin_struct
struct|struct
name|i40e_filter_control_settings
block|{
comment|/* number of PE Quad Hash filter buckets */
name|enum
name|i40e_hash_filter_size
name|pe_filt_num
decl_stmt|;
comment|/* number of PE Quad Hash contexts */
name|enum
name|i40e_dma_cntx_size
name|pe_cntx_num
decl_stmt|;
comment|/* number of FCoE filter buckets */
name|enum
name|i40e_hash_filter_size
name|fcoe_filt_num
decl_stmt|;
comment|/* number of FCoE DDP contexts */
name|enum
name|i40e_dma_cntx_size
name|fcoe_cntx_num
decl_stmt|;
comment|/* size of the Hash LUT */
name|enum
name|i40e_hash_lut_size
name|hash_lut_size
decl_stmt|;
comment|/* enable FDIR filters for PF and its VFs */
name|bool
name|enable_fdir
decl_stmt|;
comment|/* enable Ethertype filters for PF and its VFs */
name|bool
name|enable_ethtype
decl_stmt|;
comment|/* enable MAC/VLAN filters for PF and its VFs */
name|bool
name|enable_macvlan
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to hold device level control filter counts */
end_comment

begin_struct
struct|struct
name|i40e_control_filter_stats
block|{
name|u16
name|mac_etype_used
decl_stmt|;
comment|/* Used perfect match MAC/EtherType filters */
name|u16
name|etype_used
decl_stmt|;
comment|/* Used perfect EtherType filters */
name|u16
name|mac_etype_free
decl_stmt|;
comment|/* Un-used perfect match MAC/EtherType filters */
name|u16
name|etype_free
decl_stmt|;
comment|/* Un-used perfect EtherType filters */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|i40e_reset_type
block|{
name|I40E_RESET_POR
init|=
literal|0
block|,
name|I40E_RESET_CORER
init|=
literal|1
block|,
name|I40E_RESET_GLOBR
init|=
literal|2
block|,
name|I40E_RESET_EMPR
init|=
literal|3
block|, }
enum|;
end_enum

begin_comment
comment|/* IEEE 802.1AB LLDP Agent Variables from NVM */
end_comment

begin_define
define|#
directive|define
name|I40E_NVM_LLDP_CFG_PTR
value|0xD
end_define

begin_struct
struct|struct
name|i40e_lldp_variables
block|{
name|u16
name|length
decl_stmt|;
name|u16
name|adminstatus
decl_stmt|;
name|u16
name|msgfasttx
decl_stmt|;
name|u16
name|msgtxinterval
decl_stmt|;
name|u16
name|txparams
decl_stmt|;
name|u16
name|timers
decl_stmt|;
name|u16
name|crc8
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Offsets into Alternate Ram */
end_comment

begin_define
define|#
directive|define
name|I40E_ALT_STRUCT_FIRST_PF_OFFSET
value|0
end_define

begin_comment
comment|/* in dwords */
end_comment

begin_define
define|#
directive|define
name|I40E_ALT_STRUCT_DWORDS_PER_PF
value|64
end_define

begin_comment
comment|/* in dwords */
end_comment

begin_define
define|#
directive|define
name|I40E_ALT_STRUCT_OUTER_VLAN_TAG_OFFSET
value|0xD
end_define

begin_comment
comment|/* in dwords */
end_comment

begin_define
define|#
directive|define
name|I40E_ALT_STRUCT_USER_PRIORITY_OFFSET
value|0xC
end_define

begin_comment
comment|/* in dwords */
end_comment

begin_define
define|#
directive|define
name|I40E_ALT_STRUCT_MIN_BW_OFFSET
value|0xE
end_define

begin_comment
comment|/* in dwords */
end_comment

begin_define
define|#
directive|define
name|I40E_ALT_STRUCT_MAX_BW_OFFSET
value|0xF
end_define

begin_comment
comment|/* in dwords */
end_comment

begin_comment
comment|/* Alternate Ram Bandwidth Masks */
end_comment

begin_define
define|#
directive|define
name|I40E_ALT_BW_VALUE_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|I40E_ALT_BW_RELATIVE_MASK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|I40E_ALT_BW_VALID_MASK
value|0x80000000
end_define

begin_comment
comment|/* RSS Hash Table Size */
end_comment

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_HASHLUTSIZE_512
value|0x00010000
end_define

begin_comment
comment|/* INPUT SET MASK for RSS, flow director, and flexible payload */
end_comment

begin_define
define|#
directive|define
name|I40E_L3_SRC_SHIFT
value|47
end_define

begin_define
define|#
directive|define
name|I40E_L3_SRC_MASK
value|(0x3ULL<< I40E_L3_SRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_L3_V6_SRC_SHIFT
value|43
end_define

begin_define
define|#
directive|define
name|I40E_L3_V6_SRC_MASK
value|(0xFFULL<< I40E_L3_V6_SRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_L3_DST_SHIFT
value|35
end_define

begin_define
define|#
directive|define
name|I40E_L3_DST_MASK
value|(0x3ULL<< I40E_L3_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_L3_V6_DST_SHIFT
value|35
end_define

begin_define
define|#
directive|define
name|I40E_L3_V6_DST_MASK
value|(0xFFULL<< I40E_L3_V6_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_L4_SRC_SHIFT
value|34
end_define

begin_define
define|#
directive|define
name|I40E_L4_SRC_MASK
value|(0x1ULL<< I40E_L4_SRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_L4_DST_SHIFT
value|33
end_define

begin_define
define|#
directive|define
name|I40E_L4_DST_MASK
value|(0x1ULL<< I40E_L4_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VERIFY_TAG_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VERIFY_TAG_MASK
value|(0x3ULL<< I40E_VERIFY_TAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_50_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_50_MASK
value|(0x1ULL<< I40E_FLEX_50_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_51_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_51_MASK
value|(0x1ULL<< I40E_FLEX_51_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_52_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_52_MASK
value|(0x1ULL<< I40E_FLEX_52_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_53_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_53_MASK
value|(0x1ULL<< I40E_FLEX_53_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_54_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_54_MASK
value|(0x1ULL<< I40E_FLEX_54_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_55_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_55_MASK
value|(0x1ULL<< I40E_FLEX_55_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_56_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_56_MASK
value|(0x1ULL<< I40E_FLEX_56_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_57_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_FLEX_57_MASK
value|(0x1ULL<< I40E_FLEX_57_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I40E_TYPE_H_ */
end_comment

end_unit

