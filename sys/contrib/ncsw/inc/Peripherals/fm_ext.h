begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_ext.h   @Description   FM Application Programming Interface. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_EXT
end_ifndef

begin_define
define|#
directive|define
name|__FM_EXT
end_define

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"dpaa_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_grp Frame Manager API   @Description   FM API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_lib_grp FM library   @Description   FM API functions, definitions and enums                 The FM module is the main driver module and is a mandatory module                 for FM driver users. Before any further module initialization,                 this module must be initialized.                 The FM is a "singletone" module. It is responsible of the common                 HW modules: FPM, DMA, common QMI, common BMI initializations and                 run-time control routines. This module must be initialized always                 when working with any of the FM modules.                 NOTE - We assumes that the FML will be initialize only by core No. 0!   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining port types */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortType
block|{
name|e_FM_PORT_TYPE_OH_OFFLINE_PARSING
init|=
literal|0
block|,
comment|/**< Offline parsing port (id's: 0-6, share id's with                                                  host command, so must have exclusive id) */
name|e_FM_PORT_TYPE_OH_HOST_COMMAND
block|,
comment|/**< Host command port (id's: 0-6, share id's with                                                  offline parsing ports, so must have exclusive id) */
name|e_FM_PORT_TYPE_RX
block|,
comment|/**< 1G Rx port (id's: 0-3) */
name|e_FM_PORT_TYPE_RX_10G
block|,
comment|/**< 10G Rx port (id's: 0) */
name|e_FM_PORT_TYPE_TX
block|,
comment|/**< 1G Tx port (id's: 0-3) */
name|e_FM_PORT_TYPE_TX_10G
block|,
comment|/**< 10G Tx port (id's: 0) */
name|e_FM_PORT_TYPE_DUMMY
block|}
name|e_FmPortType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    General FM defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_PARTITIONS
value|64
end_define

begin_comment
comment|/**< Maximum number of partitions */
end_comment

begin_define
define|#
directive|define
name|FM_PHYS_ADDRESS_SIZE
value|6
end_define

begin_comment
comment|/**< FM Physical address size */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_define
define|#
directive|define
name|MEM_MAP_START
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM physical Address */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPhysAddr
block|{
specifier|volatile
name|uint8_t
name|high
decl_stmt|;
comment|/**< High part of the physical address */
specifier|volatile
name|uint32_t
name|low
decl_stmt|;
comment|/**< Low part of the physical address */
block|}
name|_PackedType
name|t_FmPhysAddr
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parse results memory layout */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPrsResult
block|{
specifier|volatile
name|uint8_t
name|lpid
decl_stmt|;
comment|/**< Logical port id */
specifier|volatile
name|uint8_t
name|shimr
decl_stmt|;
comment|/**< Shim header result  */
specifier|volatile
name|uint16_t
name|l2r
decl_stmt|;
comment|/**< Layer 2 result */
specifier|volatile
name|uint16_t
name|l3r
decl_stmt|;
comment|/**< Layer 3 result */
specifier|volatile
name|uint8_t
name|l4r
decl_stmt|;
comment|/**< Layer 4 result */
specifier|volatile
name|uint8_t
name|cplan
decl_stmt|;
comment|/**< Classification plan id */
specifier|volatile
name|uint16_t
name|nxthdr
decl_stmt|;
comment|/**< Next Header  */
specifier|volatile
name|uint16_t
name|cksum
decl_stmt|;
comment|/**< Checksum */
specifier|volatile
name|uint32_t
name|lcv
decl_stmt|;
comment|/**< LCV */
specifier|volatile
name|uint8_t
name|shim_off
index|[
literal|3
index|]
decl_stmt|;
comment|/**< Shim offset */
specifier|volatile
name|uint8_t
name|eth_off
decl_stmt|;
comment|/**< ETH offset */
specifier|volatile
name|uint8_t
name|llc_snap_off
decl_stmt|;
comment|/**< LLC_SNAP offset */
specifier|volatile
name|uint8_t
name|vlan_off
index|[
literal|2
index|]
decl_stmt|;
comment|/**< VLAN offset */
specifier|volatile
name|uint8_t
name|etype_off
decl_stmt|;
comment|/**< ETYPE offset */
specifier|volatile
name|uint8_t
name|pppoe_off
decl_stmt|;
comment|/**< PPP offset */
specifier|volatile
name|uint8_t
name|mpls_off
index|[
literal|2
index|]
decl_stmt|;
comment|/**< MPLS offset */
specifier|volatile
name|uint8_t
name|ip_off
index|[
literal|2
index|]
decl_stmt|;
comment|/**< IP offset */
specifier|volatile
name|uint8_t
name|gre_off
decl_stmt|;
comment|/**< GRE offset */
specifier|volatile
name|uint8_t
name|l4_off
decl_stmt|;
comment|/**< Layer 4 offset */
specifier|volatile
name|uint8_t
name|nxthdr_off
decl_stmt|;
comment|/**< Parser end point */
block|}
name|_PackedType
name|t_FmPrsResult
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   FM Parser results */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PR_L2_VLAN_STACK
value|0x00000100
end_define

begin_comment
comment|/**< Parse Result: VLAN stack */
end_comment

begin_define
define|#
directive|define
name|FM_PR_L2_ETHERNET
value|0x00008000
end_define

begin_comment
comment|/**< Parse Result: Ethernet*/
end_comment

begin_define
define|#
directive|define
name|FM_PR_L2_VLAN
value|0x00004000
end_define

begin_comment
comment|/**< Parse Result: VLAN */
end_comment

begin_define
define|#
directive|define
name|FM_PR_L2_LLC_SNAP
value|0x00002000
end_define

begin_comment
comment|/**< Parse Result: LLC_SNAP */
end_comment

begin_define
define|#
directive|define
name|FM_PR_L2_MPLS
value|0x00001000
end_define

begin_comment
comment|/**< Parse Result: MPLS */
end_comment

begin_define
define|#
directive|define
name|FM_PR_L2_PPPoE
value|0x00000800
end_define

begin_comment
comment|/**< Parse Result: PPPoE */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   FM Frame descriptor macros */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_FD_CMD_FCO
value|0x80000000
end_define

begin_comment
comment|/**< Frame queue Context Override */
end_comment

begin_define
define|#
directive|define
name|FM_FD_CMD_RPD
value|0x40000000
end_define

begin_comment
comment|/**< Read Prepended Data */
end_comment

begin_define
define|#
directive|define
name|FM_FD_CMD_UPD
value|0x20000000
end_define

begin_comment
comment|/**< Update Prepended Data */
end_comment

begin_define
define|#
directive|define
name|FM_FD_CMD_DTC
value|0x10000000
end_define

begin_comment
comment|/**< Do L4 Checksum */
end_comment

begin_define
define|#
directive|define
name|FM_FD_CMD_DCL4C
value|0x10000000
end_define

begin_comment
comment|/**< Didn't calculate L4 Checksum */
end_comment

begin_define
define|#
directive|define
name|FM_FD_CMD_CFQ
value|0x00ffffff
end_define

begin_comment
comment|/**< Confirmation Frame Queue */
end_comment

begin_define
define|#
directive|define
name|FM_FD_TX_STATUS_ERR_MASK
value|0x07000000
end_define

begin_comment
comment|/**< TX Error FD bits */
end_comment

begin_define
define|#
directive|define
name|FM_FD_RX_STATUS_ERR_MASK
value|0x070ee3f8
end_define

begin_comment
comment|/**< RX Error FD bits */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Context A */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmContextA
block|{
specifier|volatile
name|uint32_t
name|command
decl_stmt|;
comment|/**< ContextA Command */
specifier|volatile
name|uint8_t
name|res0
index|[
literal|4
index|]
decl_stmt|;
comment|/**< ContextA Reserved bits */
block|}
name|_PackedType
name|t_FmContextA
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Context B */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_FmContextB
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   Context A macros */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_CONTEXTA_OVERRIDE_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_ICMD_MASK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_A1_VALID_MASK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_MACCMD_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_MACCMD_VALID_MASK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_MACCMD_SECURED_MASK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_MACCMD_SC_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_A1_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_GET_OVERRIDE
parameter_list|(
name|contextA
parameter_list|)
value|((((t_FmContextA *)contextA)->command& FM_CONTEXTA_OVERRIDE_MASK)>> (31-0))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_GET_ICMD
parameter_list|(
name|contextA
parameter_list|)
value|((((t_FmContextA *)contextA)->command& FM_CONTEXTA_ICMD_MASK)>> (31-1))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_GET_A1_VALID
parameter_list|(
name|contextA
parameter_list|)
value|((((t_FmContextA *)contextA)->command& FM_CONTEXTA_A1_VALID_MASK)>> (31-2))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_GET_A1
parameter_list|(
name|contextA
parameter_list|)
value|((((t_FmContextA *)contextA)->command& FM_CONTEXTA_A1_MASK)>> (31-31))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_GET_MACCMD
parameter_list|(
name|contextA
parameter_list|)
value|((((t_FmContextA *)contextA)->command& FM_CONTEXTA_MACCMD_MASK)>> (31-15))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_GET_MACCMD_VALID
parameter_list|(
name|contextA
parameter_list|)
value|((((t_FmContextA *)contextA)->command& FM_CONTEXTA_MACCMD_VALID_MASK)>> (31-8))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_GET_MACCMD_SECURED
parameter_list|(
name|contextA
parameter_list|)
value|((((t_FmContextA *)contextA)->command& FM_CONTEXTA_MACCMD_SECURED_MASK)>> (31-11))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_GET_MACCMD_SECURE_CHANNEL
parameter_list|(
name|contextA
parameter_list|)
value|((((t_FmContextA *)contextA)->command& FM_CONTEXTA_MACCMD_SC_MASK)>> (31-15))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_SET_OVERRIDE
parameter_list|(
name|contextA
parameter_list|,
name|val
parameter_list|)
value|(((t_FmContextA *)contextA)->command = (uint32_t)((((t_FmContextA *)contextA)->command& ~FM_CONTEXTA_OVERRIDE_MASK) | (((uint32_t)(val)<< (31-0))& FM_CONTEXTA_OVERRIDE_MASK) ))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_SET_ICMD
parameter_list|(
name|contextA
parameter_list|,
name|val
parameter_list|)
value|(((t_FmContextA *)contextA)->command = (uint32_t)((((t_FmContextA *)contextA)->command& ~FM_CONTEXTA_ICMD_MASK) | (((val)<< (31-1))& FM_CONTEXTA_ICMD_MASK) ))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_SET_A1_VALID
parameter_list|(
name|contextA
parameter_list|,
name|val
parameter_list|)
value|(((t_FmContextA *)contextA)->command = (uint32_t)((((t_FmContextA *)contextA)->command& ~FM_CONTEXTA_A1_VALID_MASK) | (((val)<< (31-2))& FM_CONTEXTA_A1_VALID_MASK) ))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_SET_A1
parameter_list|(
name|contextA
parameter_list|,
name|val
parameter_list|)
value|(((t_FmContextA *)contextA)->command = (uint32_t)((((t_FmContextA *)contextA)->command& ~FM_CONTEXTA_A1_MASK) | (((val)<< (31-31))& FM_CONTEXTA_A1_MASK) ))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_SET_MACCMD
parameter_list|(
name|contextA
parameter_list|,
name|val
parameter_list|)
value|(((t_FmContextA *)contextA)->command = (uint32_t)((((t_FmContextA *)contextA)->command& ~FM_CONTEXTA_MACCMD_MASK) | (((val)<< (31-15))& FM_CONTEXTA_MACCMD_MASK) ))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_SET_MACCMD_VALID
parameter_list|(
name|contextA
parameter_list|,
name|val
parameter_list|)
value|(((t_FmContextA *)contextA)->command = (uint32_t)((((t_FmContextA *)contextA)->command& ~FM_CONTEXTA_MACCMD_VALID_MASK) | (((val)<< (31-8))& FM_CONTEXTA_MACCMD_VALID_MASK) ))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_SET_MACCMD_SECURED
parameter_list|(
name|contextA
parameter_list|,
name|val
parameter_list|)
value|(((t_FmContextA *)contextA)->command = (uint32_t)((((t_FmContextA *)contextA)->command& ~FM_CONTEXTA_MACCMD_SECURED_MASK) | (((val)<< (31-11))& FM_CONTEXTA_MACCMD_SECURED_MASK) ))
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTA_SET_MACCMD_SECURE_CHANNEL
parameter_list|(
name|contextA
parameter_list|,
name|val
parameter_list|)
value|(((t_FmContextA *)contextA)->command = (uint32_t)((((t_FmContextA *)contextA)->command& ~FM_CONTEXTA_MACCMD_SC_MASK) | (((val)<< (31-15))& FM_CONTEXTA_MACCMD_SC_MASK) ))
end_define

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   Context B macros */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_CONTEXTB_FQID_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTB_GET_FQID
parameter_list|(
name|contextB
parameter_list|)
value|(*((t_FmContextB *)contextB)& FM_CONTEXTB_FQID_MASK)
end_define

begin_define
define|#
directive|define
name|FM_CONTEXTB_SET_FQID
parameter_list|(
name|contextB
parameter_list|,
name|val
parameter_list|)
value|(*((t_FmContextB *)contextB) = ((*((t_FmContextB *)contextB)& ~FM_CONTEXTB_FQID_MASK) | ((val)& FM_CONTEXTB_FQID_MASK)))
end_define

begin_comment
comment|/* @} */
end_comment

begin_define
define|#
directive|define
name|MEM_MAP_END
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmExceptions
block|{
name|e_FM_EX_DMA_BUS_ERROR
block|,
comment|/**< DMA bus error. */
name|e_FM_EX_DMA_READ_ECC
block|,
comment|/**< Read Buffer ECC error */
name|e_FM_EX_DMA_SYSTEM_WRITE_ECC
block|,
comment|/**< Write Buffer ECC error on system side */
name|e_FM_EX_DMA_FM_WRITE_ECC
block|,
comment|/**< Write Buffer ECC error on FM side */
name|e_FM_EX_FPM_STALL_ON_TASKS
block|,
comment|/**< Stall of tasks on FPM */
name|e_FM_EX_FPM_SINGLE_ECC
block|,
comment|/**< Single ECC on FPM. */
name|e_FM_EX_FPM_DOUBLE_ECC
block|,
comment|/**< Double ECC error on FPM ram access */
name|e_FM_EX_QMI_SINGLE_ECC
block|,
comment|/**< Single ECC on QMI. */
name|e_FM_EX_QMI_DOUBLE_ECC
block|,
comment|/**< Double bit ECC occurred on QMI */
name|e_FM_EX_QMI_DEQ_FROM_UNKNOWN_PORTID
block|,
comment|/**< Dequeu from unknown port id */
name|e_FM_EX_BMI_LIST_RAM_ECC
block|,
comment|/**< Linked List RAM ECC error */
name|e_FM_EX_BMI_PIPELINE_ECC
block|,
comment|/**< Pipeline Table ECC Error */
name|e_FM_EX_BMI_STATISTICS_RAM_ECC
block|,
comment|/**< Statistics Count RAM ECC Error Enable */
name|e_FM_EX_BMI_DISPATCH_RAM_ECC
block|,
comment|/**< Dispatch RAM ECC Error Enable */
name|e_FM_EX_IRAM_ECC
block|,
comment|/**< Double bit ECC occurred on IRAM*/
name|e_FM_EX_MURAM_ECC
comment|/**< Double bit ECC occurred on MURAM*/
block|}
name|e_FmExceptions
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_init_grp FM Initialization Unit   @Description   FM Initialization Unit                  Initialization Flow                 Initialization of the FM Module will be carried out by the application                 according to the following sequence:                 a.  Calling the configuration routine with basic parameters.                 b.  Calling the advance initialization routines to change driver's defaults.                 c.  Calling the initialization routine.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_FmExceptionsCallback   @Description   Exceptions user callback routine, will be called upon an                 exception passing the exception identification.   @Param[in]     h_App      - User's application descriptor.  @Param[in]     exception  - The exception. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmExceptionsCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmExceptions
name|exception
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_FmBusErrorCallback   @Description   Bus error user callback routine, will be called upon a                 bus error, passing parameters describing the errors and the owner.   @Param[in]     h_App       - User's application descriptor.  @Param[in]     portType    - Port type (e_FmPortType)  @Param[in]     portId      - Port id - relative to type.  @Param[in]     addr        - Address that caused the error  @Param[in]     tnum        - Owner of error  @Param[in]     liodn       - Logical IO device number */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmBusErrorCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmPortType
name|portType
parameter_list|,
name|uint8_t
name|portId
parameter_list|,
name|uint64_t
name|addr
parameter_list|,
name|uint8_t
name|tnum
parameter_list|,
name|uint16_t
name|liodn
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining Ucode patch for loading. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdFirmwareParams
block|{
name|uint32_t
name|size
decl_stmt|;
comment|/**< Size of uCode */
name|uint32_t
modifier|*
name|p_Code
decl_stmt|;
comment|/**< A pointer to the uCode */
block|}
name|t_FmPcdFirmwareParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing FM initialization parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_SIZE_OF_LIODN_TABLE
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
name|t_FmParams
block|{
name|uint8_t
name|fmId
decl_stmt|;
comment|/**< Index of the FM */
name|uint8_t
name|guestId
decl_stmt|;
comment|/**< FM Partition Id */
name|uintptr_t
name|baseAddr
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          A pointer to base of memory mapped FM registers (virtual);                                                          NOTE that this should include ALL common regs of the FM including                                                          the PCD regs area. */
name|t_Handle
name|h_FmMuram
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          A handle of an initialized MURAM object,                                                          to be used by the FM */
name|uint16_t
name|fmClkFreq
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          In Mhz */
ifdef|#
directive|ifdef
name|FM_PARTITION_ARRAY
name|uint16_t
name|liodnBasePerPort
index|[
name|FM_SIZE_OF_LIODN_TABLE
index|]
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          For each partition, LIODN should be configured here. */
endif|#
directive|endif
comment|/* FM_PARTITION_ARRAY */
name|t_FmExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          An application callback routine to                                                          handle exceptions.*/
name|t_FmBusErrorCallback
modifier|*
name|f_BusError
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          An application callback routine to                                                          handle exceptions.*/
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          A handle to an application layer object; This handle will                                                          be passed by the driver upon calling the above callbacks */
name|int
name|irq
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          FM interrupt source for normal events */
name|int
name|errIrq
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          FM interrupt source for errors */
name|t_FmPcdFirmwareParams
name|firmware
decl_stmt|;
comment|/**< Relevant when guestId = NCSW_MASSTER_ID only.                                                          Ucode */
block|}
name|t_FmParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_Config   @Description   Creates descriptor for the FM module.                  The routine returns a handle (descriptor) to the FM object.                 This descriptor must be passed as first parameter to all other                 FM function calls.                  No actual initialization or configuration of FM hardware is                 done by this routine.   @Param[in]     p_FmParams  - A pointer to data structure of parameters   @Return        Handle to FM object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_Config
parameter_list|(
name|t_FmParams
modifier|*
name|p_FmParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_Init   @Description   Initializes the FM module   @Param[in]     h_Fm - FM module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_Init
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_Free   @Description   Frees all resources that were assigned to FM module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_Fm - FM module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_Free
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_advanced_init_grp    FM Advanced Configuration Unit   @Description   Configuration functions used to change default values;                 Note: Advanced init routines are not available for guest partition.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DMA debug mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmDmaDbgCntMode
block|{
name|e_FM_DMA_DBG_NO_CNT
init|=
literal|0
block|,
comment|/**< No counting */
name|e_FM_DMA_DBG_CNT_DONE
block|,
comment|/**< Count DONE commands */
name|e_FM_DMA_DBG_CNT_COMM_Q_EM
block|,
comment|/**< count command queue emergency signals */
name|e_FM_DMA_DBG_CNT_INT_READ_EM
block|,
comment|/**< Count Internal Read buffer emergency signal */
name|e_FM_DMA_DBG_CNT_INT_WRITE_EM
block|,
comment|/**< Count Internal Write buffer emergency signal */
name|e_FM_DMA_DBG_CNT_FPM_WAIT
block|,
comment|/**< Count FPM WAIT signal */
name|e_FM_DMA_DBG_CNT_SIGLE_BIT_ECC
block|,
comment|/**< Single bit ECC errors. */
name|e_FM_DMA_DBG_CNT_RAW_WAR_PROT
comment|/**< Number of times there was a need for RAW& WAR protection. */
block|}
name|e_FmDmaDbgCntMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DMA Cache Override */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmDmaCacheOverride
block|{
name|e_FM_DMA_NO_CACHE_OR
init|=
literal|0
block|,
comment|/**< No override of the Cache field */
name|e_FM_DMA_NO_STASH_DATA
block|,
comment|/**< Data should not be stashed in system level cache */
name|e_FM_DMA_MAY_STASH_DATA
block|,
comment|/**< Data may be stashed in system level cache */
name|e_FM_DMA_STASH_DATA
comment|/**< Data should be stashed in system level cache */
block|}
name|e_FmDmaCacheOverride
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DMA External Bus Priority */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmDmaExtBusPri
block|{
name|e_FM_DMA_EXT_BUS_NORMAL
init|=
literal|0
block|,
comment|/**< Normal priority */
name|e_FM_DMA_EXT_BUS_EBS
block|,
comment|/**< AXI extended bus service priority */
name|e_FM_DMA_EXT_BUS_SOS
block|,
comment|/**< AXI sos priority */
name|e_FM_DMA_EXT_BUS_EBS_AND_SOS
comment|/**< AXI ebs + sos priority */
block|}
name|e_FmDmaExtBusPri
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for choosing the field that will be output on AID */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmDmaAidMode
block|{
name|e_FM_DMA_AID_OUT_PORT_ID
init|=
literal|0
block|,
comment|/**< 4 LSB of PORT_ID */
name|e_FM_DMA_AID_OUT_TNUM
comment|/**< 4 LSB of TNUM */
block|}
name|e_FmDmaAidMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FPM Catasrophic error behaviour */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmCatastrophicErr
block|{
name|e_FM_CATASTROPHIC_ERR_STALL_PORT
init|=
literal|0
block|,
comment|/**< Port_ID is stalled (only reset can release it) */
name|e_FM_CATASTROPHIC_ERR_STALL_TASK
comment|/**< Only errornous task is stalled */
block|}
name|e_FmCatastrophicErr
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FPM DMA error behaviour */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmDmaErr
block|{
name|e_FM_DMA_ERR_CATASTROPHIC
init|=
literal|0
block|,
comment|/**< Dma error is treated as a catastrophic error */
name|e_FM_DMA_ERR_REPORT
comment|/**< Dma error is just reported */
block|}
name|e_FmDmaErr
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DMA Emergency level by BMI emergency signal */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmDmaEmergencyLevel
block|{
name|e_FM_DMA_EM_EBS
init|=
literal|0
block|,
comment|/**< EBS emergency */
name|e_FM_DMA_EM_SOS
comment|/**< SOS emergency */
block|}
name|e_FmDmaEmergencyLevel
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   DMA emergency options */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|fmEmergencyBus_t
typedef|;
end_typedef

begin_comment
comment|/**< DMA emergency options */
end_comment

begin_define
define|#
directive|define
name|FM_DMA_MURAM_READ_EMERGENCY
value|0x00800000
end_define

begin_comment
comment|/**< Enable emergency for MURAM1 */
end_comment

begin_define
define|#
directive|define
name|FM_DMA_MURAM_WRITE_EMERGENCY
value|0x00400000
end_define

begin_comment
comment|/**< Enable emergency for MURAM2 */
end_comment

begin_define
define|#
directive|define
name|FM_DMA_EXT_BUS_EMERGENCY
value|0x00100000
end_define

begin_comment
comment|/**< Enable emergency for external bus */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining DMA emergency level */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmDmaEmergency
block|{
name|fmEmergencyBus_t
name|emergencyBusSelect
decl_stmt|;
comment|/**< An OR of the busses where emergency                                                                  should be enabled */
name|e_FmDmaEmergencyLevel
name|emergencyLevel
decl_stmt|;
comment|/**< EBS/SOS */
block|}
name|t_FmDmaEmergency
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining FM threshold */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmThresholds
block|{
name|uint8_t
name|dispLimit
decl_stmt|;
comment|/**< The number of times a frames may                                                                  be passed in the FM before assumed to                                                                  be looping. */
name|uint8_t
name|prsDispTh
decl_stmt|;
comment|/**< This is the number pf packets that may be                                                                  queued in the parser dispatch queue*/
name|uint8_t
name|plcrDispTh
decl_stmt|;
comment|/**< This is the number pf packets that may be                                                                  queued in the policer dispatch queue*/
name|uint8_t
name|kgDispTh
decl_stmt|;
comment|/**< This is the number pf packets that may be                                                                  queued in the keygen dispatch queue*/
name|uint8_t
name|bmiDispTh
decl_stmt|;
comment|/**< This is the number pf packets that may be                                                                  queued in the BMI dispatch queue*/
name|uint8_t
name|qmiEnqDispTh
decl_stmt|;
comment|/**< This is the number pf packets that may be                                                                  queued in the QMI enqueue dispatch queue*/
name|uint8_t
name|qmiDeqDispTh
decl_stmt|;
comment|/**< This is the number pf packets that may be                                                                  queued in the QMI dequeue dispatch queue*/
name|uint8_t
name|fmCtl1DispTh
decl_stmt|;
comment|/**< This is the number pf packets that may be                                                                  queued in fmCtl1 dispatch queue*/
name|uint8_t
name|fmCtl2DispTh
decl_stmt|;
comment|/**< This is the number pf packets that may be                                                                  queued in fmCtl2 dispatch queue*/
block|}
name|t_FmThresholds
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining DMA thresholds */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmDmaThresholds
block|{
name|uint8_t
name|assertEmergency
decl_stmt|;
comment|/**< When this value is reached,                                                                  assert emergency (Threshold)*/
name|uint8_t
name|clearEmergency
decl_stmt|;
comment|/**< After emergency is asserted, it is held                                                                  until this value is reached (Hystheresis) */
block|}
name|t_FmDmaThresholds
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigResetOnInit   @Description   Tell the driver whether to reset the FM before initialization or                 not. It changes the default configuration [FALSE].   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     enable              When TRUE, FM will be reset before any initialization.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigResetOnInit
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigTotalNumOfTasks   @Description   Change the total number of tasks from its default                 configuration [BMI_MAX_NUM_OF_TASKS]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     totalNumOfTasks     The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigTotalNumOfTasks
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|totalNumOfTasks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigTotalFifoSize   @Description   Change the total Fifo size from its default                 configuration [BMI_MAX_FIFO_SIZE]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     totalFifoSize       The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigTotalFifoSize
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint32_t
name|totalFifoSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigMaxNumOfOpenDmas   @Description   Change the maximum allowed open DMA's for this FM from its default                 configuration [BMI_MAX_NUM_OF_DMAS]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     maxNumOfOpenDmas    The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigMaxNumOfOpenDmas
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|maxNumOfOpenDmas
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigThresholds   @Description   Calling this routine changes the internal driver data base                 from its default FM threshold configuration:                                           dispLimit:    [0]                                           prsDispTh:    [16]                                           plcrDispTh:   [16]                                           kgDispTh:     [16]                                           bmiDispTh:    [16]                                           qmiEnqDispTh: [16]                                           qmiDeqDispTh: [16]                                           fmCtl1DispTh:  [16]                                           fmCtl2DispTh:  [16]   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     p_FmThresholds  A structure of threshold parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigThresholds
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmThresholds
modifier|*
name|p_FmThresholds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaCacheOverride   @Description   Calling this routine changes the internal driver data base                 from its default configuration of cache override mode [e_FM_DMA_NO_CACHE_OR]   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     cacheOverride   The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaCacheOverride
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmDmaCacheOverride
name|cacheOverride
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaAidOverride   @Description   Calling this routine changes the internal driver data base                 from its default configuration of aid override mode [TRUE]   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     aidOverride     The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaAidOverride
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|bool
name|aidOverride
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaAidMode   @Description   Calling this routine changes the internal driver data base                 from its default configuration of aid mode [e_FM_DMA_AID_OUT_TNUM]   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     aidMode         The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaAidMode
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmDmaAidMode
name|aidMode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaAxiDbgNumOfBeats   @Description   Calling this routine changes the internal driver data base                 from its default configuration of axi debug [1]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     axiDbgNumOfBeats    The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaAxiDbgNumOfBeats
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|axiDbgNumOfBeats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaCamNumOfEntries   @Description   Calling this routine changes the internal driver data base                 from its default configuration of number of CAM entries [32]   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     numOfEntries    The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaCamNumOfEntries
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|numOfEntries
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaWatchdog   @Description   Calling this routine changes the internal driver data base                 from its default watchdog configuration, which is disabled                 [0].   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     watchDogValue   The selected new value - in microseconds.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaWatchdog
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint32_t
name|watchDogValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaWriteBufThresholds   @Description   Calling this routine changes the internal driver data base                 from its default configuration of DMA write buffer threshold                 assertEmergency: [DMA_THRESH_MAX_BUF]                 clearEmergency:  [DMA_THRESH_MAX_BUF]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     p_FmDmaThresholds   A structure of thresholds to define emergency behavior -                                     When 'assertEmergency' value is reached, emergency is asserted,                                     then it is held until 'clearEmergency' value is reached.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaWriteBufThresholds
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmDmaThresholds
modifier|*
name|p_FmDmaThresholds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaCommQThresholds   @Description   Calling this routine changes the internal driver data base                 from its default configuration of DMA command queue threshold                 assertEmergency: [DMA_THRESH_MAX_COMMQ]                 clearEmergency:  [DMA_THRESH_MAX_COMMQ]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     p_FmDmaThresholds   A structure of thresholds to define emergency behavior -                                     When 'assertEmergency' value is reached, emergency is asserted,                                     then it is held until 'clearEmergency' value is reached..   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaCommQThresholds
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmDmaThresholds
modifier|*
name|p_FmDmaThresholds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaReadBufThresholds   @Description   Calling this routine changes the internal driver data base                 from its default configuration of DMA read buffer threshold                 assertEmergency: [DMA_THRESH_MAX_BUF]                 clearEmergency:  [DMA_THRESH_MAX_BUF]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     p_FmDmaThresholds   A structure of thresholds to define emergency behavior -                                     When 'assertEmergency' value is reached, emergency is asserted,                                     then it is held until 'clearEmergency' value is reached..   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaReadBufThresholds
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmDmaThresholds
modifier|*
name|p_FmDmaThresholds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaSosEmergencyThreshold   @Description   Calling this routine changes the internal driver data base                 from its default dma SOS emergency configuration [0]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     dmaSosEmergency     The selected new value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaSosEmergencyThreshold
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint32_t
name|dmaSosEmergency
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigEnableCounters   @Description   Calling this routine changes the internal driver data base                 from its default counters configuration where counters are disabled.   @Param[in]     h_Fm    A handle to an FM Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigEnableCounters
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaDbgCounter   @Description   Calling this routine changes the internal driver data base                 from its default DMA debug counters configuration [e_FM_DMA_DBG_NO_CNT]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     fmDmaDbgCntMode     An enum selecting the debug counter mode.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaDbgCounter
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmDmaDbgCntMode
name|fmDmaDbgCntMode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaStopOnBusErr   @Description   Calling this routine changes the internal driver data base                 from its default selection of bus error behavior [FALSE]    @Param[in]     h_Fm    A handle to an FM Module.  @Param[in]     stop    TRUE to stop on bus error, FALSE to continue.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init().                 Only if bus error is enabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaStopOnBusErr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|bool
name|stop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaEmergency   @Description   Calling this routine changes the internal driver data base                 from its default selection of DMA emergency where's it's disabled.   @Param[in]     h_Fm        A handle to an FM Module.  @Param[in]     p_Emergency An OR mask of all required options.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaEmergency
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmDmaEmergency
modifier|*
name|p_Emergency
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaEmergencySmoother   @Description   sets the minimum amount of DATA beats transferred on the AXI                 READ and WRITE ports before lowering the emergency level.                 By default smother is disabled.   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     emergencyCnt    emergency switching counter.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaEmergencySmoother
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint32_t
name|emergencyCnt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigDmaErr   @Description   Calling this routine changes the internal driver data base                 from its default DMA error treatment [e_FM_DMA_ERR_CATASTROPHIC]   @Param[in]     h_Fm    A handle to an FM Module.  @Param[in]     dmaErr  The selected new choice.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigDmaErr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmDmaErr
name|dmaErr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigCatastrophicErr   @Description   Calling this routine changes the internal driver data base                 from its default behavior on catastrophic error [e_FM_CATASTROPHIC_ERR_STALL_PORT]   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     catastrophicErr     The selected new choice.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigCatastrophicErr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmCatastrophicErr
name|catastrophicErr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigEnableMuramTestMode   @Description   Calling this routine changes the internal driver data base                 from its default selection of test mode where it's disabled.   @Param[in]     h_Fm    A handle to an FM Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigEnableMuramTestMode
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigEnableIramTestMode   @Description   Calling this routine changes the internal driver data base                 from its default selection of test mode where it's disabled.   @Param[in]     h_Fm    A handle to an FM Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigEnableIramTestMode
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigHaltOnExternalActivation   @Description   Calling this routine changes the internal driver data base                 from its default selection of FM behaviour on external halt                 activation [FALSE].   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     enable          TRUE to enable halt on external halt                                 activation.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigHaltOnExternalActivation
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigHaltOnUnrecoverableEccError   @Description   Calling this routine changes the internal driver data base                 from its default selection of FM behaviour on unrecoverable                 Ecc error [FALSE].   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     enable          TRUE to enable halt on unrecoverable Ecc error   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigHaltOnUnrecoverableEccError
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigException   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enablement.                 By default all exceptions are enabled.   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigException
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmExceptions
name|exception
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigExternalEccRamsEnable   @Description   Calling this routine changes the internal driver data base                 from its default [FALSE].                 When this option is enabled Rams ECC enable is not effected                 by the FPM RCR bit, but by a JTAG.   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     enable          TRUE to enable this option.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigExternalEccRamsEnable
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ConfigTnumAgingPeriod   @Description   Calling this routine changes the internal driver data base                 from its default configuration for aging of dequeue TNUM's                 in the QMI.[0]                 Note that this functionality is not available in all chips.   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     tnumAgingPeriod     Tnum Aging Period in microseconds.                                     Note that period is recalculated in units of                                     64 FM clocks. Driver will pick the closest                                     possible period.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ConfigTnumAgingPeriod
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint16_t
name|tnumAgingPeriod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_advanced_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_runtime_control_grp FM Runtime Control Unit   @Description   FM Runtime control unit API functions, definitions and enums.                 The FM driver provides a set of control routines for each module.                 These routines may only be called after the module was fully                 initialized (both configuration and initialization routines were                 called). They are typically used to get information from hardware                 (status, counters/statistics, revision etc.), to modify a current                 state or to force/enable a required action. Run-time control may                 be called whenever necessary and as many times as needed.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   General FM defines. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_VALID_PORTS
value|(FM_MAX_NUM_OF_OH_PORTS +       \                                      FM_MAX_NUM_OF_1G_RX_PORTS +    \                                      FM_MAX_NUM_OF_10G_RX_PORTS +   \                                      FM_MAX_NUM_OF_1G_TX_PORTS +    \                                      FM_MAX_NUM_OF_10G_TX_PORTS)
end_define

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for Port bandwidth requirement. Port is identified                 by type and relative id. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortBandwidth
block|{
name|e_FmPortType
name|type
decl_stmt|;
comment|/**< FM port type */
name|uint8_t
name|relativePortId
decl_stmt|;
comment|/**< Type relative port id */
name|uint8_t
name|bandwidth
decl_stmt|;
comment|/**< bandwidth - (in term of percents) */
block|}
name|t_FmPortBandwidth
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A Structure containing an array of Port bandwidth requirements.                 The user should state the ports requiring bandwidth in terms of                 percentage - i.e. all port's bandwidths in the array must add                 up to 100. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortsBandwidthParams
block|{
name|uint8_t
name|numOfPorts
decl_stmt|;
comment|/**< num of ports listed in the array below */
name|t_FmPortBandwidth
name|portsBandwidths
index|[
name|FM_MAX_NUM_OF_VALID_PORTS
index|]
decl_stmt|;
comment|/**< for each port, it's bandwidth (all port's                                                  bandwidths must add up to 100.*/
block|}
name|t_FmPortsBandwidthParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DMA Emergency control on MURAM */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmDmaMuramPort
block|{
name|e_FM_DMA_MURAM_PORT_WRITE
block|,
comment|/**< MURAM write port */
name|e_FM_DMA_MURAM_PORT_READ
comment|/**< MURAM read port */
block|}
name|e_FmDmaMuramPort
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining FM counters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmCounters
block|{
name|e_FM_COUNTERS_ENQ_TOTAL_FRAME
init|=
literal|0
block|,
comment|/**< QMI total enqueued frames counter */
name|e_FM_COUNTERS_DEQ_TOTAL_FRAME
block|,
comment|/**< QMI total dequeued frames counter */
name|e_FM_COUNTERS_DEQ_0
block|,
comment|/**< QMI 0 frames from QMan counter */
name|e_FM_COUNTERS_DEQ_1
block|,
comment|/**< QMI 1 frames from QMan counter */
name|e_FM_COUNTERS_DEQ_2
block|,
comment|/**< QMI 2 frames from QMan counter */
name|e_FM_COUNTERS_DEQ_3
block|,
comment|/**< QMI 3 frames from QMan counter */
name|e_FM_COUNTERS_DEQ_FROM_DEFAULT
block|,
comment|/**< QMI dequeue from default queue counter */
name|e_FM_COUNTERS_DEQ_FROM_CONTEXT
block|,
comment|/**< QMI dequeue from FQ context counter */
name|e_FM_COUNTERS_DEQ_FROM_FD
block|,
comment|/**< QMI dequeue from FD command field counter */
name|e_FM_COUNTERS_DEQ_CONFIRM
block|,
comment|/**< QMI dequeue confirm counter */
name|e_FM_COUNTERS_SEMAPHOR_ENTRY_FULL_REJECT
block|,
comment|/**< DMA semaphor reject due to full entry counter */
name|e_FM_COUNTERS_SEMAPHOR_QUEUE_FULL_REJECT
block|,
comment|/**< DMA semaphor reject due to full CAM queue counter */
name|e_FM_COUNTERS_SEMAPHOR_SYNC_REJECT
comment|/**< DMA semaphor reject due to sync counter */
block|}
name|e_FmCounters
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for returning revision information */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmRevisionInfo
block|{
name|uint8_t
name|majorRev
decl_stmt|;
comment|/**< Major revision */
name|uint8_t
name|minorRev
decl_stmt|;
comment|/**< Minor revision */
block|}
name|t_FmRevisionInfo
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining DMA status */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmDmaStatus
block|{
name|bool
name|cmqNotEmpty
decl_stmt|;
comment|/**< Command queue is not empty */
name|bool
name|busError
decl_stmt|;
comment|/**< Bus error occurred */
name|bool
name|readBufEccError
decl_stmt|;
comment|/**< Double ECC error on buffer Read */
name|bool
name|writeBufEccSysError
decl_stmt|;
comment|/**< Double ECC error on buffer write from system side */
name|bool
name|writeBufEccFmError
decl_stmt|;
comment|/**< Double ECC error on buffer write from FM side */
block|}
name|t_FmDmaStatus
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|DEBUG_ERRORS
argument_list|)
operator|&&
operator|(
name|DEBUG_ERRORS
operator|>
literal|0
operator|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_DumpRegs   @Description   Dumps all FM registers   @Param[in]     h_Fm      A handle to an FM Module.   @Return        E_OK on success;   @Cautions      Allowed only FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_DumpRegs
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(DEBUG_ERRORS)&& ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_SetException   @Description   Calling this routine enables/disables the specified exception.                 Note: Not available for guest partition.   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_SetException
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmExceptions
name|exception
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_SetPortsBandwidth   @Description   Sets relative weights between ports when accessing common resources.                 Note: Not available for guest partition.   @Param[in]     h_Fm                A handle to an FM Module.  @Param[in]     p_PortsBandwidth    A structure of ports bandwidths in percentage, i.e.                                     total must equal 100.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_SetPortsBandwidth
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmPortsBandwidthParams
modifier|*
name|p_PortsBandwidth
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_EnableRamsEcc   @Description   Enables ECC mechanism for all the different FM RAM's; E.g. IRAM,                 MURAM, Parser, Keygen, Policer, etc.                 Note:                 If FM_ConfigExternalEccRamsEnable was called to enable external                 setting of ECC, this routine effects IRAM ECC only.                 This routine is also called by the driver if an ECC exception is                 enabled.                 Note: Not available for guest partition.   @Param[in]     h_Fm            A handle to an FM Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_EnableRamsEcc
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_DisableRamsEcc   @Description   Disables ECC mechanism for all the different FM RAM's; E.g. IRAM,                 MURAM, Parser, Keygen, Policer, etc.                 Note:                 If FM_ConfigExternalEccRamsEnable was called to enable external                 setting of ECC, this routine effects IRAM ECC only.                 In opposed to FM_EnableRamsEcc, this routine must be called                 explicitly to disable all Rams ECC.                 Note: Not available for guest partition.    @Param[in]     h_Fm            A handle to an FM Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Config() and before FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_DisableRamsEcc
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GetRevision   @Description   Returns the FM revision   @Param[in]     h_Fm                A handle to an FM Module.  @Param[out]    p_FmRevisionInfo    A structure of revision information parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_GetRevision
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmRevisionInfo
modifier|*
name|p_FmRevisionInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GetCounter   @Description   Reads one of the FM counters.   @Param[in]     h_Fm        A handle to an FM Module.  @Param[in]     counter     The requested counter.   @Return        Counter's current value.   @Cautions      Allowed only following FM_Init().                 Note that it is user's responsibility to call this routine only                 for enabled counters, and there will be no indication if a                 disabled counter is accessed. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_GetCounter
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ModifyCounter   @Description   Sets a value to an enabled counter. Use "0" to reset the counter.                 Note: Not available for guest partition.   @Param[in]     h_Fm        A handle to an FM Module.  @Param[in]     counter     The requested counter.  @Param[in]     val         The requested value to be written into the counter.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ModifyCounter
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmCounters
name|counter
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_Resume   @Description   Release FM after halt FM command or after unrecoverable ECC error.                 Note: Not available for guest partition.   @Param[in]     h_Fm        A handle to an FM Module.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FM_Resume
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_SetDmaEmergency   @Description   Manual emergency set                 Note: Not available for guest partition.   @Param[in]     h_Fm        A handle to an FM Module.  @Param[in]     muramPort   MURAM direction select.  @Param[in]     enable      TRUE to manually enable emergency, FALSE to disable.   @Return        None.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FM_SetDmaEmergency
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmDmaMuramPort
name|muramPort
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_SetDmaExtBusPri   @Description   Manual emergency set                 Note: Not available for guest partition.   @Param[in]     h_Fm    A handle to an FM Module.  @Param[in]     pri     External bus priority select   @Return        None.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FM_SetDmaExtBusPri
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmDmaExtBusPri
name|pri
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ForceIntr   @Description   Causes an interrupt event on the requested source.                 Note: Not available for guest partition.   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     exception       An exception to be forced.   @Return        E_OK on success; Error code if the exception is not enabled,                 or is not able to create interrupt.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ForceIntr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmExceptions
name|exception
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GetDmaStatus   @Description   Reads the DMA current status   @Param[in]     h_Fm                A handle to an FM Module.  @Param[out]    p_FmDmaStatus      A structure of DMA status parameters.   @Return        None   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FM_GetDmaStatus
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmDmaStatus
modifier|*
name|p_FmDmaStatus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GetPcdHandle   @Description   Used by FMC in order to get PCD handle   @Param[in]     h_Fm     A handle to an FM Module.   @Return        A handle to the PCD module, NULL if uninitialized.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_GetPcdHandle
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ErrorIsr                 Note: Not available for guest partition.   @Description   FM interrupt-service-routine for errors.   @Param[in]     h_Fm            A handle to an FM Module.   @Return        E_OK on success; E_EMPTY if no errors found in register, other                 error code otherwise.   @Cautions      Allowed only following FM_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_ErrorIsr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_EventIsr                 Note: Not available for guest partition.   @Description   FM interrupt-service-routine for normal events.   @Param[in]     h_Fm            A handle to an FM Module.   @Cautions      Allowed only following FM_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FM_EventIsr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|DEBUG_ERRORS
argument_list|)
operator|&&
operator|(
name|DEBUG_ERRORS
operator|>
literal|0
operator|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmDumpPortRegs   @Description   Dumps FM port registers which are part of FM common registers   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     hardwarePortId    HW port id.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmDumpPortRegs
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(DEBUG_ERRORS)&& ... */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_runtime_control_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_lib_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_grp group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_EXT */
end_comment

end_unit

