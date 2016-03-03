begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_port_ext.h   @Description   FM-Port Application Programming Interface. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_PORT_EXT
end_ifndef

begin_define
define|#
directive|define
name|__FM_PORT_EXT
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
file|"fm_pcd_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_ext.h"
end_include

begin_include
include|#
directive|include
file|"net_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @Group         FM_grp Frame Manager API   @Description   FM API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PORT_grp FM Port   @Description   FM Port API                  The FM uses a general module called "port" to represent a Tx port                 (MAC), an Rx port (MAC), offline parsing flow or host command                 flow. There may be up to 17 (may change) ports in an FM - 5 Tx                 ports (4 for the 1G MACs, 1 for the 10G MAC), 5 Rx Ports, and 7                 Host command/Offline parsing ports. The SW driver manages these                 ports as sub-modules of the FM, i.e. after an FM is initialized,                 its ports may be initialized and operated upon.                  The port is initialized aware of its type, but other functions on                 a port may be indifferent to its type. When necessary, the driver                 verifies coherency and returns error if applicable.                  On initialization, user specifies the port type and it's index                 (relative to the port's type). Host command and Offline parsing                 ports share the same id range, I.e user may not initialized host                 command port 0 and offline parsing port 0.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   An enum for defining port PCD modes.                 This enum defines the superset of PCD engines support - i.e. not                 all engines have to be used, but all have to be enabled. The real                 flow of a specific frame depends on the PCD configuration and the                 frame headers and payload. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortPcdSupport
block|{
name|e_FM_PORT_PCD_SUPPORT_NONE
init|=
literal|0
block|,
comment|/**< BMI to BMI, PCD is not used */
name|e_FM_PORT_PCD_SUPPORT_PRS_ONLY
block|,
comment|/**< Use only Parser */
name|e_FM_PORT_PCD_SUPPORT_PLCR_ONLY
block|,
comment|/**< Use only Policer */
name|e_FM_PORT_PCD_SUPPORT_PRS_AND_PLCR
block|,
comment|/**< Use Parser and Policer */
name|e_FM_PORT_PCD_SUPPORT_PRS_AND_KG
block|,
comment|/**< Use Parser and Keygen */
name|e_FM_PORT_PCD_SUPPORT_PRS_AND_KG_AND_CC
block|,
comment|/**< Use Parser, Keygen and Coarse Classification */
name|e_FM_PORT_PCD_SUPPORT_PRS_AND_KG_AND_CC_AND_PLCR
block|,
comment|/**< Use all PCD engines */
name|e_FM_PORT_PCD_SUPPORT_PRS_AND_KG_AND_PLCR
comment|/**< Use Parser, Keygen and Policer */
ifdef|#
directive|ifdef
name|FM_CAPWAP_SUPPORT
block|,
name|e_FM_PORT_PCD_SUPPORT_CC_ONLY
block|,
comment|/**< Use only Coarse Classification */
name|e_FM_PORT_PCD_SUPPORT_CC_AND_KG
block|,
comment|/**< Use Coarse Classification,and Keygen */
name|e_FM_PORT_PCD_SUPPORT_CC_AND_KG_AND_PLCR
comment|/**< Use Coarse Classification, Keygen and Policer */
endif|#
directive|endif
comment|/* FM_CAPWAP_SUPPORT */
block|}
name|e_FmPortPcdSupport
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Port interrupts */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortExceptions
block|{
name|e_FM_PORT_EXCEPTION_IM_BUSY
comment|/**< Independent-Mode Rx-BUSY */
block|}
name|e_FmPortExceptions
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    General FM Port defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PORT_PRS_RESULT_NUM_OF_WORDS
value|8
end_define

begin_comment
comment|/**< Number of 4 bytes words in parser result */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   FM Frame error */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|fmPortFrameErrSelect_t
typedef|;
end_typedef

begin_comment
comment|/**< typedef for defining Frame Descriptor errors */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_UNSUPPORTED_FORMAT
value|0x04000000
end_define

begin_comment
comment|/**< Offline parsing only! Unsupported Format */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_LENGTH
value|0x02000000
end_define

begin_comment
comment|/**< Offline parsing only! Length Error */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_DMA
value|0x01000000
end_define

begin_comment
comment|/**< DMA Data error */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FM_CAPWAP_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_NON_FM
value|0x00400000
end_define

begin_comment
comment|/**< non Frame-Manager error; probably come from SEC that                                                                          was chained to FM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_CAPWAP_SUPPORT */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_PHYSICAL
value|0x00080000
end_define

begin_comment
comment|/**< Rx FIFO overflow, FCS error, code error, running disparity                                                                          error (SGMII and TBI modes), FIFO parity error. PHY                                                                          Sequence error, PHY error control character detected. */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_SIZE
value|0x00040000
end_define

begin_comment
comment|/**< Frame too long OR Frame size exceeds max_length_frame  */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_CLS_DISCARD
value|0x00020000
end_define

begin_comment
comment|/**< classification discard */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_EXTRACTION
value|0x00008000
end_define

begin_comment
comment|/**< Extract Out of Frame */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_NO_SCHEME
value|0x00004000
end_define

begin_comment
comment|/**< No Scheme Selected */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_KEYSIZE_OVERFLOW
value|0x00002000
end_define

begin_comment
comment|/**< Keysize Overflow */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_COLOR_YELLOW
value|0x00000400
end_define

begin_comment
comment|/**< Frame color is yellow */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_COLOR_RED
value|0x00000800
end_define

begin_comment
comment|/**< Frame color is red */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_ILL_PLCR
value|0x00000200
end_define

begin_comment
comment|/**< Illegal Policer Profile selected */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_PLCR_FRAME_LEN
value|0x00000100
end_define

begin_comment
comment|/**< Policer frame length error */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_PRS_TIMEOUT
value|0x00000080
end_define

begin_comment
comment|/**< Parser Time out Exceed */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_PRS_ILL_INSTRUCT
value|0x00000040
end_define

begin_comment
comment|/**< Invalid Soft Parser instruction */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_PRS_HDR_ERR
value|0x00000020
end_define

begin_comment
comment|/**< Header error was identified during parsing */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_BLOCK_LIMIT_EXCEEDED
value|0x00000008
end_define

begin_comment
comment|/**< Frame parsed beyind 256 first bytes */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_FRM_ERR_PROCESS_TIMEOUT
value|0x00000001
end_define

begin_comment
comment|/**< FPM Frame Processing Timeout Exceeded */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PORT_init_grp FM Port Initialization Unit   @Description   FM Port Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Exceptions user callback routine, will be called upon an                 exception passing the exception identification.   @Param[in]     h_App      - User's application descriptor.  @Param[in]     exception  - The exception.   */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmPortExceptionCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmPortExceptions
name|exception
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   User callback function called by driver with received data.                  User provides this function. Driver invokes it.   @Param[in]     h_App           Application's handle originally specified to                                 the API Config function  @Param[in]     p_Data          A pointer to data received  @Param[in]     length          length of received data  @Param[in]     status          receive status and errors  @Param[in]     position        position of buffer in frame  @Param[in]     h_BufContext    A handle of the user acossiated with this buffer   @Retval        e_RX_STORE_RESPONSE_CONTINUE - order the driver to continue Rx                                                operation for all ready data.  @Retval        e_RX_STORE_RESPONSE_PAUSE    - order the driver to stop Rx operation. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|e_RxStoreResponse
function_decl|(
name|t_FmPortImRxStoreCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|uint8_t
modifier|*
name|p_Data
parameter_list|,
name|uint16_t
name|length
parameter_list|,
name|uint16_t
name|status
parameter_list|,
name|uint8_t
name|position
parameter_list|,
name|t_Handle
name|h_BufContext
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   User callback function called by driver when transmit completed.                  User provides this function. Driver invokes it.   @Param[in]     h_App           Application's handle originally specified to                                 the API Config function  @Param[in]     p_Data          A pointer to data received  @Param[in]     status          transmit status and errors  @Param[in]     lastBuffer      is last buffer in frame  @Param[in]     h_BufContext    A handle of the user acossiated with this buffer  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmPortImTxConfCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|uint8_t
modifier|*
name|p_Data
parameter_list|,
name|uint16_t
name|status
parameter_list|,
name|t_Handle
name|h_BufContext
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure of information about each of the external                 buffer pools used by the port, */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortExtPoolParams
block|{
name|uint8_t
name|id
decl_stmt|;
comment|/**< External buffer pool id */
name|uint16_t
name|size
decl_stmt|;
comment|/**< External buffer pool buffer size */
block|}
name|t_FmPortExtPoolParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for informing the driver about the external                 buffer pools allocated in the BM and used by this port. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortExtPools
block|{
name|uint8_t
name|numOfPoolsUsed
decl_stmt|;
comment|/**< Number of pools use by this port */
name|t_FmPortExtPoolParams
name|extBufPool
index|[
name|FM_PORT_MAX_NUM_OF_EXT_POOLS
index|]
decl_stmt|;
comment|/**< Parameters for each port */
block|}
name|t_FmPortExtPools
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for additional Rx port parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortRxParams
block|{
name|uint32_t
name|errFqid
decl_stmt|;
comment|/**< Error Queue Id. */
name|uint32_t
name|dfltFqid
decl_stmt|;
comment|/**< Default Queue Id.  */
name|uint16_t
name|liodnOffset
decl_stmt|;
comment|/**< Port's LIODN offset. */
name|t_FmPortExtPools
name|extBufPools
decl_stmt|;
comment|/**< Which external buffer pools are used                                                      (up to FM_PORT_MAX_NUM_OF_EXT_POOLS), and their sizes. */
block|}
name|t_FmPortRxParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for additional non-Rx port parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortNonRxParams
block|{
name|uint32_t
name|errFqid
decl_stmt|;
comment|/**< Error Queue Id. */
name|uint32_t
name|dfltFqid
decl_stmt|;
comment|/**< For Tx and HC - Default Confirmation queue,                                                      0 means no Tx confirmation for processed                                                      frames. For OP - default Rx queue. */
name|uint32_t
name|qmChannel
decl_stmt|;
comment|/**< QM-channel dedicated to this port; will be used                                                      by the FM for dequeue. */
ifdef|#
directive|ifdef
name|FM_OP_PARTITION_ERRATA_FMANx8
name|uint16_t
name|opLiodnOffset
decl_stmt|;
comment|/**< For Offline Parsing ports only. Port's LIODN offset. */
endif|#
directive|endif
comment|/* FM_OP_PARTITION_ERRATA_FMANx8 */
block|}
name|t_FmPortNonRxParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for additional Rx port parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortImRxTxParams
block|{
name|t_Handle
name|h_FmMuram
decl_stmt|;
comment|/**< A handle of the FM-MURAM partition */
name|uint16_t
name|liodnOffset
decl_stmt|;
comment|/**< For Rx ports only. Port's LIODN Offset. */
name|uint8_t
name|dataMemId
decl_stmt|;
comment|/**< Memory partition ID for data buffers */
name|uint32_t
name|dataMemAttributes
decl_stmt|;
comment|/**< Memory attributes for data buffers */
name|t_BufferPoolInfo
name|rxPoolParams
decl_stmt|;
comment|/**< For Rx ports only. */
name|t_FmPortImRxStoreCallback
modifier|*
name|f_RxStore
decl_stmt|;
comment|/**< For Rx ports only. */
name|t_FmPortImTxConfCallback
modifier|*
name|f_TxConf
decl_stmt|;
comment|/**< For Tx ports only. */
block|}
name|t_FmPortImRxTxParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Union for additional parameters depending on port type */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|u_FmPortSpecificParams
block|{
name|t_FmPortImRxTxParams
name|imRxTxParams
decl_stmt|;
comment|/**< Rx/Tx Independent-Mode port parameter structure */
name|t_FmPortRxParams
name|rxParams
decl_stmt|;
comment|/**< Rx port parameters structure */
name|t_FmPortNonRxParams
name|nonRxParams
decl_stmt|;
comment|/**< Non-Rx port parameters structure */
block|}
name|u_FmPortSpecificParams
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

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortParams
block|{
name|uintptr_t
name|baseAddr
decl_stmt|;
comment|/**< Virtual Address of memory mapped FM Port registers.*/
name|t_Handle
name|h_Fm
decl_stmt|;
comment|/**< A handle to the FM object this port related to */
name|e_FmPortType
name|portType
decl_stmt|;
comment|/**< Port type */
name|uint8_t
name|portId
decl_stmt|;
comment|/**< Port Id - relative to type */
name|bool
name|independentModeEnable
decl_stmt|;
comment|/**< This port is Independent-Mode - Used for Rx/Tx ports only! */
name|uint16_t
name|liodnBase
decl_stmt|;
comment|/**< Irrelevant for P4080 rev 1. LIODN base for this port, to be                                                          used together with LIODN offset. */
name|u_FmPortSpecificParams
name|specificParams
decl_stmt|;
comment|/**< Additional parameters depending on port                                                          type. */
name|t_FmPortExceptionCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< Callback routine to be called of PCD exception */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                          be passed by the driver upon calling the above callbacks */
block|}
name|t_FmPortParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_Config   @Description   Creates descriptor for the FM PORT module.                  The routine returns a handle (descriptor) to the FM PORT object.                 This descriptor must be passed as first parameter to all other                 FM PORT function calls.                  No actual initialization or configuration of FM hardware is                 done by this routine.   @Param[in]     p_FmPortParams   - Pointer to data structure of parameters   @Retval        Handle to FM object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PORT_Config
parameter_list|(
name|t_FmPortParams
modifier|*
name|p_FmPortParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_Init   @Description   Initializes the FM PORT module   @Param[in]     h_FmPort - FM PORT module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_Init
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_Free   @Description   Frees all resources that were assigned to FM PORT module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_FmPort - FM PORT module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_Free
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PORT_advanced_init_grp    FM Port Advanced Configuration Unit   @Description   Configuration functions used to change default values.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining QM frame dequeue */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortDeqType
block|{
name|e_FM_PORT_DEQ_TYPE1
block|,
comment|/**< Dequeue from the SP channel - with priority precedence,                                          and Intra-Class Scheduling respected. */
name|e_FM_PORT_DEQ_TYPE2
block|,
comment|/**< Dequeue from the SP channel - with active FQ precedence,                                          and Intra-Class Scheduling respected. */
name|e_FM_PORT_DEQ_TYPE3
comment|/**< Dequeue from the SP channel - with active FQ precedence,                                          and override Intra-Class Scheduling */
block|}
name|e_FmPortDeqType
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|FM_QMI_DEQ_OPTIONS_SUPPORT
end_ifdef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining QM frame dequeue */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortDeqPrefetchOption
block|{
name|e_FM_PORT_DEQ_NO_PREFETCH
block|,
comment|/**< QMI preforms a dequeue action for a single frame                                          only when a dedicated portID Tnum is waiting. */
name|e_FM_PORT_DEQ_PARTIAL_PREFETCH
block|,
comment|/**< QMI preforms a dequeue action for 3 frames when                                          one dedicated portId tnum is waiting. */
name|e_FM_PORT_DEQ_FULL_PREFETCH
comment|/**< QMI preforms a dequeue action for 3 frames when                                          no dedicated portId tnums are waiting. */
block|}
name|e_FmPortDeqPrefetchOption
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_QMI_DEQ_OPTIONS_SUPPORT */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining port DMA swap mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortDmaSwap
block|{
name|e_FM_PORT_DMA_NO_SWP
block|,
comment|/**< No swap, transfer data as is.*/
name|e_FM_PORT_DMA_SWP_PPC_LE
block|,
comment|/**< The transferred data should be swapped                                          in PowerPc Little Endian mode. */
name|e_FM_PORT_DMA_SWP_BE
comment|/**< The transferred data should be swapped                                          in Big Endian mode */
block|}
name|e_FmPortDmaSwap
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining port DMA cache attributes */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortDmaCache
block|{
name|e_FM_PORT_DMA_NO_STASH
init|=
literal|0
block|,
comment|/**< Cacheable, no Allocate (No Stashing) */
name|e_FM_PORT_DMA_STASH
init|=
literal|1
comment|/**< Cacheable and Allocate (Stashing on) */
block|}
name|e_FmPortDmaCache
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining port default color */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortColor
block|{
name|e_FM_PORT_COLOR_GREEN
block|,
comment|/**< Default port color is green */
name|e_FM_PORT_COLOR_YELLOW
block|,
comment|/**< Default port color is yellow */
name|e_FM_PORT_COLOR_RED
block|,
comment|/**< Default port color is red */
name|e_FM_PORT_COLOR_OVERRIDE
comment|/**< Ignore color */
block|}
name|e_FmPortColor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining Dual Tx rate limiting scale */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortDualRateLimiterScaleDown
block|{
name|e_FM_PORT_DUAL_RATE_LIMITER_NONE
init|=
literal|0
block|,
comment|/**< Use only single rate limiter  */
name|e_FM_PORT_DUAL_RATE_LIMITER_SCALE_DOWN_BY_2
block|,
comment|/**< Divide high rate limiter by 2 */
name|e_FM_PORT_DUAL_RATE_LIMITER_SCALE_DOWN_BY_4
block|,
comment|/**< Divide high rate limiter by 4 */
name|e_FM_PORT_DUAL_RATE_LIMITER_SCALE_DOWN_BY_8
comment|/**< Divide high rate limiter by 8 */
block|}
name|e_FmPortDualRateLimiterScaleDown
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining FM port resources */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortRsrc
block|{
name|uint32_t
name|num
decl_stmt|;
comment|/**< Committed required resource */
name|uint32_t
name|extra
decl_stmt|;
comment|/**< Extra (not committed) required resource */
block|}
name|t_FmPortRsrc
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining pool depletion criteria */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortBufPoolDepletion
block|{
name|bool
name|numberOfPoolsModeEnable
decl_stmt|;
comment|/**< select mode in which pause frames will be sent after                                                          a number of pools are depleted */
name|uint8_t
name|numOfPools
decl_stmt|;
comment|/**< the minimum number of depleted pools that will                                                          invoke pause frames transmission. */
name|bool
name|poolsToConsider
index|[
name|BM_MAX_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< For each pool, TRUE if it should be considered for                                                          depletion (Note - this pool must be used by this port!) */
name|bool
name|singlePoolModeEnable
decl_stmt|;
comment|/**< select mode in which pause frames will be sent after                                                          a single of pools are depleted */
name|bool
name|poolsToConsiderForSingleMode
index|[
name|BM_MAX_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< For each pool, TRUE if it should be considered for                                                          depletion (Note - this pool must be used by this port!) */
block|}
name|t_FmPortBufPoolDepletion
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining observed pool depletion */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortObservedBufPoolDepletion
block|{
name|t_FmPortBufPoolDepletion
name|poolDepletionParams
decl_stmt|;
comment|/**< parameters to define pool depletion */
name|t_FmPortExtPools
name|poolsParams
decl_stmt|;
comment|/**< Which external buffer pools are observed                                                          (up to FM_PORT_MAX_NUM_OF_OBSERVED_EXT_POOLS),                                                          and their sizes. */
block|}
name|t_FmPortObservedBufPoolDepletion
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining Tx rate limiting */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortRateLimit
block|{
name|uint16_t
name|maxBurstSize
decl_stmt|;
comment|/**< in kBytes for Tx ports, in frames                                                                      for offline parsing ports. (note that                                                                      for early chips burst size is                                                                      rounded up to a multiply of 1000 frames).*/
name|uint32_t
name|rateLimit
decl_stmt|;
comment|/**< in Kb/sec for Tx ports, in frame/sec for                                                                      offline parsing ports. Rate limit refers to                                                                      data rate (rather than line rate). */
name|e_FmPortDualRateLimiterScaleDown
name|rateLimitDivider
decl_stmt|;
comment|/**< For offline parsing ports only. Not-valid                                                                      for some earlier chip revisions */
block|}
name|t_FmPortRateLimit
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining define the parameters of                 the Rx port performance counters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortPerformanceCnt
block|{
name|uint8_t
name|taskCompVal
decl_stmt|;
comment|/**< Task compare value */
name|uint8_t
name|queueCompVal
decl_stmt|;
comment|/**< Rx queue/Tx confirm queue compare                                              value (unused for H/O) */
name|uint8_t
name|dmaCompVal
decl_stmt|;
comment|/**< Dma compare value */
name|uint32_t
name|fifoCompVal
decl_stmt|;
comment|/**< Fifo compare value (in bytes) */
block|}
name|t_FmPortPerformanceCnt
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining buffer content. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortBufferPrefixContent
block|{
name|uint16_t
name|privDataSize
decl_stmt|;
comment|/**< Number of bytes to be left at the beginning                                          of the external buffer */
name|bool
name|passPrsResult
decl_stmt|;
comment|/**< TRUE to pass the parse result to/from the FM */
name|bool
name|passTimeStamp
decl_stmt|;
comment|/**< TRUE to pass the timeStamp to/from the FM */
name|bool
name|passHashResult
decl_stmt|;
comment|/**< TRUE to pass the KG hash result to/from the FM */
name|bool
name|passAllOtherPCDInfo
decl_stmt|;
comment|/**< Add all other Internal-Context information:                                          AD, hash-result, key, etc. */
name|uint16_t
name|dataAlign
decl_stmt|;
comment|/**< 0 to use driver's default alignment, other value                                          for selecting a data alignment (must be a                                          power of 2) */
ifdef|#
directive|ifdef
name|DEBUG
name|bool
name|passDebugInfo
decl_stmt|;
comment|/**< Debug-information */
endif|#
directive|endif
comment|/* DEBUG */
ifdef|#
directive|ifdef
name|FM_CAPWAP_SUPPORT
name|uint8_t
name|manipExtraSpace
decl_stmt|;
comment|/**< Maximum extra size needed (insertion-size minus removal-size) */
endif|#
directive|endif
comment|/* FM_CAPWAP_SUPPORT */
block|}
name|t_FmPortBufferPrefixContent
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining backup Bm Pools. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortBackupBmPools
block|{
name|uint8_t
name|numOfBackupPools
decl_stmt|;
comment|/**< Number of BM backup pools -                                              must be smaller than the total number of                                              pools defined for the specified port.*/
name|uint8_t
name|poolIds
index|[
name|FM_PORT_MAX_NUM_OF_EXT_POOLS
index|]
decl_stmt|;
comment|/**< numOfBackupPools pool id's, specifying which                                              pools should be used only as backup. Pool                                              id's specified here must be a subset of the                                              pools used by the specified port.*/
block|}
name|t_FmPortBackupBmPools
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDeqHighPriority   @Description   Calling this routine changes the dequeue priority in the                 internal driver data base from its default configuration                 [TRUE]                  May be used for Non-Rx ports only   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     highPri     TRUE to select high priority, FALSE for normal operation.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDeqHighPriority
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|bool
name|highPri
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDeqType   @Description   Calling this routine changes the dequeue type parameter in the                 internal driver data base from its default configuration                 [e_FM_PORT_DEQ_TYPE1].                  May be used for Non-Rx ports only   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     deqType     According to QM definition.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDeqType
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortDeqType
name|deqType
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FM_QMI_DEQ_OPTIONS_SUPPORT
end_ifdef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDeqPrefetchOption   @Description   Calling this routine changes the dequeue prefetch option parameter in the                 internal driver data base from its default configuration                 [e_FM_PORT_DEQ_FULL_PREFETCH]                 Note: Available for some chips only                  May be used for Non-Rx ports only   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     deqPrefetchOption   New option   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDeqPrefetchOption
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortDeqPrefetchOption
name|deqPrefetchOption
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_QMI_DEQ_OPTIONS_SUPPORT */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDeqByteCnt   @Description   Calling this routine changes the dequeue byte count parameter in                 the internal driver data base from its default configuration [2000].                  May be used for Non-Rx ports only   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     deqByteCnt      New byte count   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDeqByteCnt
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint16_t
name|deqByteCnt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigTxFifoMinFillLevel   @Description   Calling this routine changes the fifo minimum                 fill level parameter in the internal driver data base                 from its default configuration  [0]                  May be used for Tx ports only   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     minFillLevel    New value   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigTxFifoMinFillLevel
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint32_t
name|minFillLevel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigTxFifoDeqPipelineDepth   @Description   Calling this routine changes the fifo dequeue                 pipeline depth parameter in the internal driver data base                  from its default configuration: 1G ports: [2],                 10G port: [8]                  May be used for Tx ports only   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     deqPipelineDepth    New value   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigTxFifoDeqPipelineDepth
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|deqPipelineDepth
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigTxFifoLowComfLevel   @Description   Calling this routine changes the fifo low comfort level                 parameter in internal driver data base                 from its default configuration  [5]                  May be used for Tx ports only   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     fifoLowComfLevel    New value   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigTxFifoLowComfLevel
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint32_t
name|fifoLowComfLevel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigRxFifoThreshold   @Description   Calling this routine changes the threshold of the FIFO                 fill level parameter in the internal driver data base                 from its default configuration [BMI_MAX_FIFO_SIZE]                  If the total number of buffers which are                 currently in use and associated with the                 specific RX port exceed this threshold, the                 BMI will signal the MAC to send a pause frame                 over the link.                  May be used for Rx ports only   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     fifoThreshold       New value   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigRxFifoThreshold
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint32_t
name|fifoThreshold
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigRxFifoPriElevationLevel   @Description   Calling this routine changes the priority elevation level                 parameter in the internal driver data base from its default                 configuration  [BMI_MAX_FIFO_SIZE]                  If the total number of buffers which are currently in use and                 associated with the specific RX port exceed the amount specified                 in priElevationLevel, BMI will signal the main FM's DMA to                 elevate the FM priority on the system bus.                  May be used for Rx ports only   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     priElevationLevel   New value   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigRxFifoPriElevationLevel
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint32_t
name|priElevationLevel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigBufferPrefixContent   @Description   Defines the structure, size and content of the application buffer.                 The prefix will                 In Tx ports, if 'passPrsResult', the application                 should set a value to their offsets in the prefix of                 the FM will save the first 'privDataSize', than,                 depending on 'passPrsResult' and 'passTimeStamp', copy parse result                 and timeStamp, and the packet itself (in this order), to the                 application buffer, and to offset.                 Calling this routine changes the buffer margins definitions                 in the internal driver data base from its default                 configuration: Data size:  [0]                                Pass Parser result: [FALSE].                                Pass timestamp: [FALSE].                  May be used for all ports   @Param[in]     h_FmPort                        A handle to a FM Port module.  @Param[in,out] p_FmPortBufferPrefixContent     A structure of parameters describing the                                                 structure of the buffer.                                                 Out parameter: Start margin - offset                                                 of data from start of external buffer.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigBufferPrefixContent
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortBufferPrefixContent
modifier|*
name|p_FmPortBufferPrefixContent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigCheksumLastBytesIgnore   @Description   Calling this routine changes the number of checksum bytes to ignore                 parameter in the internal driver data base from its default configuration                 [0]                  May be used by Tx& Rx ports only   @Param[in]     h_FmPort                A handle to a FM Port module.  @Param[in]     cheksumLastBytesIgnore    New value   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigCheksumLastBytesIgnore
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|cheksumLastBytesIgnore
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigCutBytesFromEnd   @Description   Calling this routine changes the number of bytes to cut from a                 frame's end parameter in the internal driver data base                 from its default configuration  [4]                 Note that if the result of (frame length before chop - cutBytesFromEnd) is                 less than 14 bytes, the chop operation is not executed.                  May be used for Rx ports only   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     cutBytesFromEnd     New value   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigCutBytesFromEnd
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|cutBytesFromEnd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigPoolDepletion   @Description   Calling this routine enables pause frame generation depending on the                 depletion status of BM pools. It also defines the conditions to activate                 this functionality. By default, this functionality is disabled.                  May be used for Rx ports only   @Param[in]     h_FmPort                A handle to a FM Port module.  @Param[in]     p_BufPoolDepletion      A structure of pool depletion parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigPoolDepletion
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortBufPoolDepletion
modifier|*
name|p_BufPoolDepletion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigObservedPoolDepletion   @Description   Calling this routine enables a mechanism to stop port enqueue                 depending on the depletion status of selected BM pools.                 It also defines the conditions to activate                 this functionality. By default, this functionality is disabled.                  Note: Available for some chips only                  May be used for Offline Parsing ports only   @Param[in]     h_FmPort                            A handle to a FM Port module.  @Param[in]     p_FmPortObservedBufPoolDepletion    A structure of parameters for pool depletion.    @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigObservedPoolDepletion
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortObservedBufPoolDepletion
modifier|*
name|p_FmPortObservedBufPoolDepletion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigExtBufPools   @Description   This routine should be called for offline parsing ports                 that internally use BM buffer pools. In such cases, e.g. for fragmentation and                 re-assembly, the FM needs new BM buffers. By calling this routine the user                 specifies the BM buffer pools that should be used.                  Note: Available for some chips only                  May be used for Offline Parsing ports only   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     p_FmPortExtPools    A structure of parameters for the external pools.    @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigExtBufPools
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortExtPools
modifier|*
name|p_FmPortExtPools
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigBackupPools   @Description   Calling this routine allows the configuration of some of the BM pools                 defined for this port as backup pools.                 A pool configured to be a backup pool will be used only if all other                 enabled non-backup pools are depleted.                  May be used for Rx ports only   @Param[in]     h_FmPort                A handle to a FM Port module.  @Param[in]     p_FmPortBackupBmPools   An array of pool id's. All pools specified here will                                         be defined as backup pools.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigBackupPools
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortBackupBmPools
modifier|*
name|p_FmPortBackupBmPools
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigFrmDiscardOverride   @Description   Calling this routine changes the error frames destination parameter                 in the internal driver data base from its default configuration:                 override = [FALSE]                  May be used for Rx and offline parsing ports only   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     override    TRUE to override dicarding of error frames and                             enqueueing them to error queue.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigFrmDiscardOverride
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|bool
name|override
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigErrorsToDiscard   @Description   Calling this routine changes the behaviour on error parameter                 in the internal driver data base from its default configuration:                 [FM_PORT_FRM_ERR_CLS_DISCARD].                 If a requested error was previously defined as "ErrorsToEnqueue" it's                 definition will change and the frame will be discarded.                 Errors that were not defined either as "ErrorsToEnqueue" nor as                 "ErrorsToDiscard", will be forwarded to CPU.                   May be used for Rx and offline parsing ports only   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     errs        A list of errors to discard   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigErrorsToDiscard
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|fmPortFrameErrSelect_t
name|errs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDmaSwapData   @Description   Calling this routine changes the DMA swap data aparameter                 in the internal driver data base from its default                 configuration  [e_FM_PORT_DMA_NO_SWP]                  May be used for all port types   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     swapData    New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDmaSwapData
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortDmaSwap
name|swapData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDmaIcCacheAttr   @Description   Calling this routine changes the internal context cache                 attribute parameter in the internal driver data base                 from its default configuration  [e_FM_PORT_DMA_NO_STASH]                  May be used for all port types   @Param[in]     h_FmPort               A handle to a FM Port module.  @Param[in]     intContextCacheAttr    New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDmaIcCacheAttr
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortDmaCache
name|intContextCacheAttr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDmaHdrAttr   @Description   Calling this routine changes the header cache                 attribute parameter in the internal driver data base                 from its default configuration  [e_FM_PORT_DMA_NO_STASH]                  May be used for all port types   @Param[in]     h_FmPort                    A handle to a FM Port module.  @Param[in]     headerCacheAttr             New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDmaHdrAttr
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortDmaCache
name|headerCacheAttr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDmaScatterGatherAttr   @Description   Calling this routine changes the scatter gather cache                 attribute parameter in the internal driver data base                 from its default configuration  [e_FM_PORT_DMA_NO_STASH]                  May be used for all port types   @Param[in]     h_FmPort                    A handle to a FM Port module.  @Param[in]     scatterGatherCacheAttr      New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDmaScatterGatherAttr
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortDmaCache
name|scatterGatherCacheAttr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDmaWriteOptimize   @Description   Calling this routine changes the write optimization                 parameter in the internal driver data base                 from its default configuration:  optimize = [TRUE]                  May be used for non-Tx port types   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     optimize    TRUE to enable optimization, FALSE for normal operation   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDmaWriteOptimize
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|bool
name|optimize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDfltColor   @Description   Calling this routine changes the internal default color parameter                 in the internal driver data base                 from its default configuration  [e_FM_PORT_COLOR_GREEN]                  May be used for all port types   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     color           New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDfltColor
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortColor
name|color
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigSyncReq   @Description   Calling this routine changes the synchronization attribute parameter                 in the internal driver data base from its default configuration:                 syncReq = [TRUE]                  May be used for all port types   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     syncReq         TRUE to request synchronization, FALSE otherwize.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigSyncReq
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|bool
name|syncReq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigForwardReuseIntContext   @Description   This routine is relevant for Rx ports that are routed to offline                 parsing. It changes the internal context reuse option                 in the internal driver data base from its default configuration:                 reuse = [FALSE]                  May be used for Rx ports only   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     reuse           TRUE to reuse internal context on frames                                 forwarded to offline parsing.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigForwardReuseIntContext
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|bool
name|reuse
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigDontReleaseTxBufToBM   @Description   This routine should be called if no Tx confirmation                 is done, and yet buffers should not be released to the BM.                 Normally, buffers are returned using the Tx confirmation                 process. When Tx confirmation is not used (defFqid=0),                 buffers are typically released to the BM. This routine                 may be called to avoid this behavior and not release the                 buffers.                  May be used for Tx ports only   @Param[in]     h_FmPort        A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigDontReleaseTxBufToBM
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigIMMaxRxBufLength   @Description   Changes the maximum receive buffer length from its default                 configuration: Closest rounded down power of 2 value of the                 data buffer size.                  The maximum receive buffer length directly affects the structure                 of received frames (single- or multi-buffered) and the performance                 of both the FM and the driver.                  The selection between single- or multi-buffered frames should be                 done according to the characteristics of the specific application.                 The recommended mode is to use a single data buffer per packet,                 as this mode provides the best performance. However, the user can                 select to use multiple data buffers per packet.   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     newVal          Maximum receive buffer length (in bytes).   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init().                 This routine is to be used only if Independent-Mode is enabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigIMMaxRxBufLength
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint16_t
name|newVal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigIMRxBdRingLength   @Description   Changes the receive BD ring length from its default                 configuration:[128]   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     newVal          The desired BD ring length.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init().                 This routine is to be used only if Independent-Mode is enabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigIMRxBdRingLength
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint16_t
name|newVal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigIMTxBdRingLength   @Description   Changes the transmit BD ring length from its default                 configuration:[16]   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     newVal          The desired BD ring length.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init().                 This routine is to be used only if Independent-Mode is enabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigIMTxBdRingLength
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint16_t
name|newVal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigIMFmanCtrlExternalStructsMemory   @Description   Configures memory partition and attributes for FMan-Controller                 data structures (e.g. BD rings).                 Calling this routine changes the internal driver data base                 from its default configuration                 [0 , MEMORY_ATTR_CACHEABLE].   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     memId           Memory partition ID.  @Param[in]     memAttributes   Memory attributes mask (a combination of MEMORY_ATTR_x flags).   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigIMFmanCtrlExternalStructsMemory
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|memId
parameter_list|,
name|uint32_t
name|memAttributes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ConfigIMPolling   @Description   Changes the Rx flow from interrupt driven (default) to polling.   @Param[in]     h_FmPort        A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init().                 This routine is to be used only if Independent-Mode is enabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ConfigIMPolling
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PORT_advanced_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PORT_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PORT_runtime_control_grp FM Port Runtime Control Unit   @Description   FM Port Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining FM Port counters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortCounters
block|{
name|e_FM_PORT_COUNTERS_CYCLE
block|,
comment|/**< BMI performance counter */
name|e_FM_PORT_COUNTERS_TASK_UTIL
block|,
comment|/**< BMI performance counter */
name|e_FM_PORT_COUNTERS_QUEUE_UTIL
block|,
comment|/**< BMI performance counter */
name|e_FM_PORT_COUNTERS_DMA_UTIL
block|,
comment|/**< BMI performance counter */
name|e_FM_PORT_COUNTERS_FIFO_UTIL
block|,
comment|/**< BMI performance counter */
name|e_FM_PORT_COUNTERS_RX_PAUSE_ACTIVATION
block|,
comment|/**< BMI Rx only performance counter */
name|e_FM_PORT_COUNTERS_FRAME
block|,
comment|/**< BMI statistics counter */
name|e_FM_PORT_COUNTERS_DISCARD_FRAME
block|,
comment|/**< BMI statistics counter */
name|e_FM_PORT_COUNTERS_DEALLOC_BUF
block|,
comment|/**< BMI deallocate buffer statistics counter */
name|e_FM_PORT_COUNTERS_RX_BAD_FRAME
block|,
comment|/**< BMI Rx only statistics counter */
name|e_FM_PORT_COUNTERS_RX_LARGE_FRAME
block|,
comment|/**< BMI Rx only statistics counter */
name|e_FM_PORT_COUNTERS_RX_OUT_OF_BUFFERS_DISCARD
block|,
comment|/**< BMI Rx only statistics counter */
name|e_FM_PORT_COUNTERS_RX_FILTER_FRAME
block|,
comment|/**< BMI Rx& OP only statistics counter */
name|e_FM_PORT_COUNTERS_RX_LIST_DMA_ERR
block|,
comment|/**< BMI Rx, OP& HC only statistics counter */
name|e_FM_PORT_COUNTERS_WRED_DISCARD
block|,
comment|/**< BMI OP& HC only statistics counter */
name|e_FM_PORT_COUNTERS_LENGTH_ERR
block|,
comment|/**< BMI non-Rx statistics counter */
name|e_FM_PORT_COUNTERS_UNSUPPRTED_FORMAT
block|,
comment|/**< BMI non-Rx statistics counter */
name|e_FM_PORT_COUNTERS_DEQ_TOTAL
block|,
comment|/**< QMI counter */
name|e_FM_PORT_COUNTERS_ENQ_TOTAL
block|,
comment|/**< QMI counter */
name|e_FM_PORT_COUNTERS_DEQ_FROM_DEFAULT
block|,
comment|/**< QMI counter */
name|e_FM_PORT_COUNTERS_DEQ_CONFIRM
comment|/**< QMI counter */
block|}
name|e_FmPortCounters
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for Port id parameters.                 Fields commented 'IN' are passed by the port module to be used                 by the FM module.                 Fields commented 'OUT' will be filled by FM before returning to port. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortCongestionGrps
block|{
name|uint16_t
name|numOfCongestionGrpsToConsider
decl_stmt|;
comment|/**< The number of required congestion groups                                                              to define the size of the following array */
name|uint8_t
name|congestionGrpsToConsider
index|[
name|FM_PORT_NUM_OF_CONGESTION_GRPS
index|]
decl_stmt|;
comment|/**< An array of 'numOfCongestionGrpsToConsider'                                                              describing the groups */
block|}
name|t_FmPortCongestionGrps
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
comment|/**  @Function      FM_PORT_DumpRegs   @Description   Dump all regs.                  Calling this routine invalidates the descriptor.   @Param[in]     h_FmPort - FM PORT module descriptor   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_DumpRegs
parameter_list|(
name|t_Handle
name|h_FmPort
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
comment|/**  @Function      FM_PORT_GetBufferDataOffset   @Description   Relevant for Rx ports.                 Returns the data offset from the beginning of the data buffer   @Param[in]     h_FmPort - FM PORT module descriptor   @Return        data offset.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PORT_GetBufferDataOffset
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_GetBufferICInfo   @Description   Returns the Internal Context offset from the beginning of the data buffer   @Param[in]     h_FmPort - FM PORT module descriptor  @Param[in]     p_Data      - A pointer to the data buffer.   @Return        Internal context info pointer on success, NULL if 'allOtherInfo' was not                 configured for this port.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|FM_PORT_GetBufferICInfo
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_GetBufferDebugInfo   @Description   Returns the debug info offset from the beginning of the data buffer   @Param[in]     h_FmPort - FM PORT module descriptor  @Param[in]     p_Data      - A pointer to the data buffer.   @Return        Debug info pointer on success, NULL if 'passDebugInfo' was not                 configured for this port.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|FM_PORT_GetBufferDebugInfo
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_GetBufferPrsResult   @Description   Returns the pointer to the parse result in the data buffer.                 In Rx ports this is relevant after reception, if parse                 result is configured to be part of the data passed to the                 application. For non Rx ports it may be used to get the pointer                 of the area in the buffer where parse result should be                 initialized - if so configured.                 See FM_PORT_ConfigBufferPrefixContent for data buffer prefix                 configuration.   @Param[in]     h_FmPort    - FM PORT module descriptor  @Param[in]     p_Data      - A pointer to the data buffer.   @Return        Parse result pointer on success, NULL if parse result was not                 configured for this port.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_FmPrsResult
modifier|*
name|FM_PORT_GetBufferPrsResult
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_GetBufferTimeStamp   @Description   Returns the time stamp in the data buffer.                 Relevant for Rx ports for getting the buffer time stamp.                 See FM_PORT_ConfigBufferPrefixContent for data buffer prefix                 configuration.   @Param[in]     h_FmPort    - FM PORT module descriptor  @Param[in]     p_Data      - A pointer to the data buffer.   @Return        A pointer to the hash result on success, NULL otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
modifier|*
name|FM_PORT_GetBufferTimeStamp
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_GetBufferHashResult   @Description   Given a data buffer, on the condition that hash result was defined                 as a part of the buffer content (see FM_PORT_ConfigBufferPrefixContent)                 this routine will return the pointer to the hash result location in the                 buffer prefix.   @Param[in]     h_FmPort    - FM PORT module descriptor  @Param[in]     p_Data      - A pointer to the data buffer.   @Return        A pointer to the hash result on success, NULL otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|FM_PORT_GetBufferHashResult
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_Disable   @Description   Gracefully disable an FM port. The port will not start new tasks after all                 tasks associated with the port are terminated.   @Param[in]     h_FmPort    A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init().                 This is a blocking routine, it returns after port is                 gracefully stopped, i.e. the port will not except new frames,                 but it will finish all frames or tasks which were already began */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_Disable
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_Enable   @Description   A runtime routine provided to allow disable/enable of port.   @Param[in]     h_FmPort    A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_Enable
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetRateLimit   @Description   Calling this routine enables rate limit algorithm.                 By default, this functionality is disabled.                 Note that rate-limit mechanism uses the FM time stamp.                 The selected rate limit specified here would be                 rounded DOWN to the nearest 16M.                  May be used for Tx and offline parsing ports only   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     p_RateLimit     A structure of rate limit parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetRateLimit
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortRateLimit
modifier|*
name|p_RateLimit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_DeleteRateLimit   @Description   Calling this routine disables and clears rate limit                 initialization.                  May be used for Tx and offline parsing ports only   @Param[in]     h_FmPort        A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_DeleteRateLimit
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetStatisticsCounters   @Description   Calling this routine enables/disables port's statistics counters.                 By default, counters are enabled.                  May be used for all port types   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     enable      TRUE to enable, FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetStatisticsCounters
parameter_list|(
name|t_Handle
name|h_FmPort
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
comment|/**  @Function      FM_PORT_SetFrameQueueCounters   @Description   Calling this routine enables/disables port's enqueue/dequeue counters.                 By default, counters are enabled.                  May be used for all ports   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     enable      TRUE to enable, FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetFrameQueueCounters
parameter_list|(
name|t_Handle
name|h_FmPort
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
comment|/**  @Function      FM_PORT_SetPerformanceCounters   @Description   Calling this routine enables/disables port's performance counters.                 By default, counters are enabled.                  May be used for all port types   @Param[in]     h_FmPort                A handle to a FM Port module.  @Param[in]     enable                  TRUE to enable, FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetPerformanceCounters
parameter_list|(
name|t_Handle
name|h_FmPort
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
comment|/**  @Function      FM_PORT_SetPerformanceCounters   @Description   Calling this routine defines port's performance                 counters parameters.                  May be used for all port types   @Param[in]     h_FmPort                A handle to a FM Port module.  @Param[in]     p_FmPortPerformanceCnt  A pointer to a structure of performance                                         counters parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetPerformanceCountersParams
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortPerformanceCnt
modifier|*
name|p_FmPortPerformanceCnt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_AnalyzePerformanceParams   @Description   User may call this routine to so the driver will analyze if the                 basic performance parameters are correct and also the driver may                 suggest of improvments; The basic parameters are FIFO sizes, number                 of DMAs and number of TNUMs for the port.                  May be used for all port types   @Param[in]     h_FmPort                A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_AnalyzePerformanceParams
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetNumOfOpenDmas   @Description   Calling this routine updates the number of open DMA requested for                 this port.                   May be used for all port types.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     p_NumOfOpenDmas     A structure of resource requested parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetNumOfOpenDmas
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortRsrc
modifier|*
name|p_NumOfOpenDmas
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetNumOfTasks   @Description   Calling this routine updates the number of tasks requested for                 this port.                  May be used for all port types.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     p_NumOfTasks        A structure of resource requested parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetNumOfTasks
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortRsrc
modifier|*
name|p_NumOfTasks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetSizeOfFifo   @Description   Calling this routine updates the Fifo size resource requested for                 this port.                  May be used for all port types - note that only Rx has 'extra'                 fifo size. For other ports 'extra' field must be disabled.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     p_SizeOfFifo        A structure of resource requested parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetSizeOfFifo
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortRsrc
modifier|*
name|p_SizeOfFifo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetAllocBufCounter   @Description   Calling this routine enables/disables BM pool allocate                 buffer counters.                 By default, counters are enabled.                  May be used for Rx ports only   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     poolId      BM pool id.  @Param[in]     enable      TRUE to enable, FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetAllocBufCounter
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|poolId
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
comment|/**  @Function      FM_PORT_GetCounter   @Description   Reads one of the FM PORT counters.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     fmPortCounter       The requested counter.   @Return        Counter's current value.   @Cautions      Allowed only following FM_PORT_Init().                 Note that it is user's responsibility to call this routine only                 for enabled counters, and there will be no indication if a                 disabled counter is accessed. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PORT_GetCounter
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortCounters
name|fmPortCounter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ModifyCounter   @Description   Sets a value to an enabled counter. Use "0" to reset the counter.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     fmPortCounter       The requested counter.  @Param[in]     value               The requested value to be written into the counter.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ModifyCounter
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortCounters
name|fmPortCounter
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_GetAllocBufCounter   @Description   Reads one of the FM PORT buffer counters.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     poolId              The requested pool.   @Return        Counter's current value.   @Cautions      Allowed only following FM_PORT_Init().                 Note that it is user's responsibility to call this routine only                 for enabled counters, and there will be no indication if a                 disabled counter is accessed. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PORT_GetAllocBufCounter
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|poolId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ModifyAllocBufCounter   @Description   Sets a value to an enabled counter. Use "0" to reset the counter.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     poolId              The requested pool.  @Param[in]     value               The requested value to be written into the counter.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ModifyAllocBufCounter
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|poolId
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_AddCongestionGrps   @Description   This routine effects the corresponding Tx port.                 It should be called in order to enable pause                 frame transmission in case of congestion in one or more                 of the congestion groups relevant to this port.                 Each call to this routine may add one or more congestion                 groups to be considered relevant to this port.                  May be used for Rx, or  RX+OP ports only (depending on chip)   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     p_CongestionGrps    A pointer to an array of congestion groups                                     id's to consider.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_AddCongestionGrps
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortCongestionGrps
modifier|*
name|p_CongestionGrps
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_RemoveCongestionGrps   @Description   This routine effects the corresponding Tx port. It should be                 called when congestion groups were                 defined for this port and are no longer relevant, or pause                 frames transmitting is not required on their behalf.                 Each call to this routine may remove one or more congestion                 groups to be considered relevant to this port.                  May be used for Rx, or RX+OP ports only (depending on chip)   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     p_CongestionGrps    A pointer to an array of congestion groups                                     id's to consider.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_RemoveCongestionGrps
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortCongestionGrps
modifier|*
name|p_CongestionGrps
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_IsStalled   @Description   A routine for checking whether the specified port is stalled.   @Param[in]     h_FmPort            A handle to a FM Port module.   @Return        TRUE if port is stalled, FALSE otherwize   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|bool
name|FM_PORT_IsStalled
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ReleaseStalled   @Description   This routine may be called in case the port was stalled and may                 now be released.   @Param[in]     h_FmPort    A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ReleaseStalled
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetRxL4ChecksumVerify   @Description   This routine is relevant for Rx ports (1G and 10G). The routine                 set/clear the L3/L4 checksum verification (on RX side).                 Note that this takes affect only if hw-parser is enabled!   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     l4Checksum      boolean indicates whether to do L3/L4 checksum                                 on frames or not.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetRxL4ChecksumVerify
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|bool
name|l4Checksum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetErrorsRoute   @Description   Errors selected for this routine will cause a frame with that error                 to be enqueued to error queue.                 Errors not selected for this routine will cause a frame with that error                 to be enqueued to the one of the other port queues.                 By default all errors are defined to be enqueued to error queue.                 Errors that were configured to be discarded (at initialization)                 may not be selected here.                  May be used for Rx and offline parsing ports only   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     errs        A list of errors to enqueue to error queue   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Config() and before FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetErrorsRoute
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|fmPortFrameErrSelect_t
name|errs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetIMExceptions   @Description   Calling this routine enables/disables FM PORT interrupts.                 Note: Not available for guest partition.   @Param[in]     h_FmPort        FM PORT module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetIMExceptions
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortExceptions
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
comment|/**  @Group         FM_PORT_pcd_runtime_control_grp FM Port PCD Runtime Control Unit   @Description   FM Port PCD Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure defining the KG scheme after the parser.                 This is relevant only to change scheme selection mode - from                 direct to indirect and vice versa, or when the scheme is selected directly,                 to select the scheme id.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgSchemeSelect
block|{
name|bool
name|direct
decl_stmt|;
comment|/**< TRUE to use 'h_Scheme' directly, FALSE to use LCV.*/
name|t_Handle
name|h_DirectScheme
decl_stmt|;
comment|/**< Relevant for 'direct'=TRUE only.                                              'h_DirectScheme' selects the scheme after parser. */
block|}
name|t_FmPcdKgSchemeSelect
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure of scheme parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdPortSchemesParams
block|{
name|uint8_t
name|numOfSchemes
decl_stmt|;
comment|/**< Number of schemes for port to be bound to. */
name|t_Handle
name|h_Schemes
index|[
name|FM_PCD_KG_NUM_OF_SCHEMES
index|]
decl_stmt|;
comment|/**< Array of 'numOfSchemes' schemes for the                                                              port to be bound to */
block|}
name|t_FmPcdPortSchemesParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Union for defining port protocol parameters for parser */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|u_FmPcdHdrPrsOpts
block|{
comment|/* MPLS */
struct|struct
block|{
name|bool
name|labelInterpretationEnable
decl_stmt|;
comment|/**< When this bit is set, the last MPLS label will be                                                          interpreted as described in HW spec table. When the bit                                                          is cleared, the parser will advance to MPLS next parse */
name|e_NetHeaderType
name|nextParse
decl_stmt|;
comment|/**< must be equal or higher than IPv4 */
block|}
name|mplsPrsOptions
struct|;
comment|/* VLAN */
struct|struct
block|{
name|uint16_t
name|tagProtocolId1
decl_stmt|;
comment|/**< User defined Tag Protocol Identifier, to be recognized                                                          on VLAN TAG on top of 0x8100 and 0x88A8 */
name|uint16_t
name|tagProtocolId2
decl_stmt|;
comment|/**< User defined Tag Protocol Identifier, to be recognized                                                          on VLAN TAG on top of 0x8100 and 0x88A8 */
block|}
name|vlanPrsOptions
struct|;
comment|/* PPP */
struct|struct
block|{
name|bool
name|enableMTUCheck
decl_stmt|;
comment|/**< Check validity of MTU according to RFC2516 */
block|}
name|pppoePrsOptions
struct|;
comment|/* IPV6 */
struct|struct
block|{
name|bool
name|routingHdrDisable
decl_stmt|;
comment|/**< Disable routing header */
block|}
name|ipv6PrsOptions
struct|;
comment|/* UDP */
struct|struct
block|{
name|bool
name|padIgnoreChecksum
decl_stmt|;
comment|/**< TRUE to ignore pad in checksum */
block|}
name|udpPrsOptions
struct|;
comment|/* TCP */
struct|struct
block|{
name|bool
name|padIgnoreChecksum
decl_stmt|;
comment|/**< TRUE to ignore pad in checksum */
block|}
name|tcpPrsOptions
struct|;
block|}
name|u_FmPcdHdrPrsOpts
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining each header for the parser */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdPrsAdditionalHdrParams
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Selected header */
name|bool
name|errDisable
decl_stmt|;
comment|/**< TRUE to disable error indication */
name|bool
name|swPrsEnable
decl_stmt|;
comment|/**< Enable jump to SW parser when this                                                  header is recognized by the HW parser. */
name|uint8_t
name|indexPerHdr
decl_stmt|;
comment|/**< Normally 0, if more than one sw parser                                                  attachments exists for the same header,                                                  (in the main sw parser code) use this                                                  index to distinguish between them. */
name|bool
name|usePrsOpts
decl_stmt|;
comment|/**< TRUE to use parser options. */
name|u_FmPcdHdrPrsOpts
name|prsOpts
decl_stmt|;
comment|/**< A union according to header type,                                                  defining the parser options selected.*/
block|}
name|t_FmPcdPrsAdditionalHdrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining port PCD parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortPcdPrsParams
block|{
name|uint8_t
name|prsResultPrivateInfo
decl_stmt|;
comment|/**< The private info provides a method of inserting                                                                          port information into the parser result. This information                                                                          may be extracted by Keygen and be used for frames                                                                          distribution when a per-port distinction is required,                                                                          it may also be used as a port logical id for analyzing                                                                          incoming frames. */
name|uint8_t
name|parsingOffset
decl_stmt|;
comment|/**< Number of bytes from beginning of packet to start parsing */
name|e_NetHeaderType
name|firstPrsHdr
decl_stmt|;
comment|/**< The type of the first header expected at 'parsingOffset' */
name|bool
name|includeInPrsStatistics
decl_stmt|;
comment|/**< TRUE to include this port in the parser statistics;                                                                          NOTE: this field is not valid when the FN is in "guest" mode. */
name|uint8_t
name|numOfHdrsWithAdditionalParams
decl_stmt|;
comment|/**< Normally 0, some headers may get                                                                          special parameters */
name|t_FmPcdPrsAdditionalHdrParams
name|additionalParams
index|[
name|FM_PCD_PRS_NUM_OF_HDRS
index|]
decl_stmt|;
comment|/**< 'numOfHdrsWithAdditionalParams'  structures                                                                          of additional parameters                                                                          for each header that requires them */
name|bool
name|setVlanTpid1
decl_stmt|;
comment|/**< TRUE to configure user selection of Ethertype to                                                                          indicate a VLAN tag (in addition to the TPID values                                                                          0x8100 and 0x88A8). */
name|uint16_t
name|vlanTpid1
decl_stmt|;
comment|/**< extra tag to use if setVlanTpid1=TRUE. */
name|bool
name|setVlanTpid2
decl_stmt|;
comment|/**< TRUE to configure user selection of Ethertype to                                                                          indicate a VLAN tag (in addition to the TPID values                                                                          0x8100 and 0x88A8). */
name|uint16_t
name|vlanTpid2
decl_stmt|;
comment|/**< extra tag to use if setVlanTpid1=TRUE. */
block|}
name|t_FmPortPcdPrsParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining coarse alassification parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortPcdCcParams
block|{
name|t_Handle
name|h_CcTree
decl_stmt|;
comment|/**< A handle to a CC tree */
block|}
name|t_FmPortPcdCcParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining keygen parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortPcdKgParams
block|{
name|uint8_t
name|numOfSchemes
decl_stmt|;
comment|/**< Number of schemes for port to be bound to. */
name|t_Handle
name|h_Schemes
index|[
name|FM_PCD_KG_NUM_OF_SCHEMES
index|]
decl_stmt|;
comment|/**< Array of 'numOfSchemes' schemes handles for the                                                              port to be bound to */
name|bool
name|directScheme
decl_stmt|;
comment|/**< TRUE for going from parser to a specific scheme,                                                              regardless of parser result */
name|t_Handle
name|h_DirectScheme
decl_stmt|;
comment|/**< relevant only if direct == TRUE, Scheme handle,                                                              as returned by FM_PCD_KgSetScheme */
block|}
name|t_FmPortPcdKgParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining policer parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortPcdPlcrParams
block|{
name|t_Handle
name|h_Profile
decl_stmt|;
comment|/**< Selected profile handle; Relevant for one of                                                      following cases:                                                      e_FM_PORT_PCD_SUPPORT_PLCR_ONLY or                                                      e_FM_PORT_PCD_SUPPORT_PRS_AND_PLCR were selected,                                                      or if any flow uses a KG scheme were policer                                                      profile is not generated                                                      (bypassPlcrProfileGeneration selected) */
block|}
name|t_FmPortPcdPlcrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining port PCD parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortPcdParams
block|{
name|e_FmPortPcdSupport
name|pcdSupport
decl_stmt|;
comment|/**< Relevant for Rx and offline ports only.                                                      Describes the active PCD engines for this port. */
name|t_Handle
name|h_NetEnv
decl_stmt|;
comment|/**< HL Unused in PLCR only mode */
name|t_FmPortPcdPrsParams
modifier|*
name|p_PrsParams
decl_stmt|;
comment|/**< Parser parameters for this port */
name|t_FmPortPcdCcParams
modifier|*
name|p_CcParams
decl_stmt|;
comment|/**< Coarse classification parameters for this port */
name|t_FmPortPcdKgParams
modifier|*
name|p_KgParams
decl_stmt|;
comment|/**< Keygen parameters for this port */
name|t_FmPortPcdPlcrParams
modifier|*
name|p_PlcrParams
decl_stmt|;
comment|/**< Policer parameters for this port */
block|}
name|t_FmPortPcdParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining the Parser starting point */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdPrsStart
block|{
name|uint8_t
name|parsingOffset
decl_stmt|;
comment|/**< Number of bytes from beginning of packet to                                              start parsing */
name|e_NetHeaderType
name|firstPrsHdr
decl_stmt|;
comment|/**< The type of the first header axpected at                                              'parsingOffset' */
block|}
name|t_FmPcdPrsStart
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_SetPCD   @Description   Calling this routine defines the port's PCD configuration.                 It changes it from its default configuration which is PCD                 disabled (BMI to BMI) and configures it according to the passed                 parameters.                  May be used for Rx and offline parsing ports only   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     p_FmPortPcd     A Structure of parameters defining the port's PCD                                 configuration.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_SetPCD
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortPcdParams
modifier|*
name|p_FmPortPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_DeletePCD   @Description   Calling this routine releases the port's PCD configuration.                 The port returns to its default configuration which is PCD                 disabled (BMI to BMI) and all PCD configuration is removed.                  May be used for Rx and offline parsing ports which are                 in PCD mode  only   @Param[in]     h_FmPort        A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_DeletePCD
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_AttachPCD   @Description   This routine may be called after FM_PORT_DetachPCD was called,                 to return to the originally configured PCD support flow.                 The couple of routines are used to allow PCD configuration changes                 that demand that PCD will not be used while changes take place.                  May be used for Rx and offline parsing ports which are                 in PCD mode only   @Param[in]     h_FmPort        A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_AttachPCD
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_DetachPCD   @Description   Calling this routine detaches the port from its PCD functionality.                 The port returns to its default flow which is BMI to BMI.                  May be used for Rx and offline parsing ports which are                 in PCD mode only   @Param[in]     h_FmPort        A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_AttachPCD(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_DetachPCD
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_PcdPlcrAllocProfiles   @Description   This routine may be called only for ports that use the Policer in                 order to allocate private policer profiles.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     numOfProfiles       The number of required policer profiles   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init() and FM_PCD_Init(), and before FM_PORT_SetPCD(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_PcdPlcrAllocProfiles
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint16_t
name|numOfProfiles
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_PcdPlcrFreeProfiles   @Description   This routine should be called for freeing private policer profiles.   @Param[in]     h_FmPort            A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init() and FM_PCD_Init(), and before FM_PORT_SetPCD(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_PcdPlcrFreeProfiles
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_PcdKgModifyInitialScheme   @Description   This routine may be called only for ports that use the keygen in                 order to change the initial scheme frame should be routed to.                 The change may be of a scheme id (in case of direct mode),                 from direct to indirect, or from indirect to direct - specifying the scheme id.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     p_FmPcdKgScheme     A structure of parameters for defining whether                                     a scheme is direct/indirect, and if direct - scheme id.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init() and FM_PORT_SetPCD(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_PcdKgModifyInitialScheme
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPcdKgSchemeSelect
modifier|*
name|p_FmPcdKgScheme
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_PcdPlcrModifyInitialProfile   @Description   This routine may be called for ports with flows                 e_FM_PORT_PCD_SUPPORT_PLCR_ONLY or e_FM_PORT_PCD_SUPPORT_PRS_AND_PLCR                 only, to change the initial Policer profile frame should be                 routed to. The change may be of a profile and/or absolute/direct                 mode selection.   @Param[in]     h_FmPort                A handle to a FM Port module.  @Param[in]     h_Profile               Policer profile handle   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init() and FM_PORT_SetPCD(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_PcdPlcrModifyInitialProfile
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_Handle
name|h_Profile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_PcdCcModifyTree   @Description   This routine may be called for ports that use coarse classification tree                 if the user wishes to replace the tree. The routine may not be called while port                 receives packets using the PCD functionalities, therefor port must be first detached                 from the PCD, only than the routine may be called, and than port be attached to PCD again.   @Param[in]     h_FmPort            A handle to a FM Port module.  @Param[in]     h_CcTree            A CC tree that was already built. The tree id as returned from                                     the BuildTree routine.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(), FM_PORT_SetPCD() and FM_PORT_DetachPCD() */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_PcdCcModifyTree
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_Handle
name|h_CcTree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_PcdKgBindSchemes   @Description   These routines may be called for adding more schemes for the                 port to be bound to. The selected schemes are not added,                 just this specific port starts using them.   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     p_PortScheme    A structure defining the list of schemes to be added.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init() and FM_PORT_SetPCD(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_PcdKgBindSchemes
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPcdPortSchemesParams
modifier|*
name|p_PortScheme
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_PcdKgUnbindSchemes   @Description   These routines may be called for adding more schemes for the                 port to be bound to. The selected schemes are not removed or invalidated,                 just this specific port stops using them.   @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     p_PortScheme    A structure defining the list of schemes to be added.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init() and FM_PORT_SetPCD(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_PcdKgUnbindSchemes
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPcdPortSchemesParams
modifier|*
name|p_PortScheme
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_PcdPrsModifyStartOffset   @Description   Runtime change of the parser start offset within the header.                 The routine may not be called while port                 receives packets using the PCD functionalities, therefore port must be first detached                 from the PCD, only than the routine may be called, and than port be attached to PCD again.  @Param[in]     h_FmPort        A handle to a FM Port module.  @Param[in]     p_FmPcdPrsStart A structure of parameters for defining the                                 start point for the parser.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init(), FM_PORT_SetPCD() and FM_PORT_DetatchPCD(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_PcdPrsModifyStartOffset
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPcdPrsStart
modifier|*
name|p_FmPcdPrsStart
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PORT_pcd_runtime_control_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PORT_runtime_control_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PORT_runtime_data_grp FM Port Runtime Data-path Unit   @Description   FM Port Runtime data unit API functions, definitions and enums.                 This API is valid only if working in Independent-Mode.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ImTx   @Description   Tx function, called to transmit a data buffer on the port.   @Param[in]     h_FmPort    A handle to a FM Port module.  @Param[in]     p_Data      A pointer to an LCP data buffer.  @Param[in]     length      Size of data for transmission.  @Param[in]     lastBuffer  Buffer position - TRUE for the last buffer                             of a frame, including a single buffer frame  @Param[in]     h_BufContext  A handle of the user acossiated with this buffer   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init().                 NOTE - This routine can be used only when working in                 Independent-Mode mode. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ImTx
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
modifier|*
name|p_Data
parameter_list|,
name|uint16_t
name|length
parameter_list|,
name|bool
name|lastBuffer
parameter_list|,
name|t_Handle
name|h_BufContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ImTxConf   @Description   Tx port confirmation routine, optional, may be called to verify                 transmission of all frames. The procedure performed by this                 routine will be performed automatically on next buffer transmission,                 but if desired, calling this routine will invoke this action on                 demand.   @Param[in]     h_FmPort            A handle to a FM Port module.   @Cautions      Allowed only following FM_PORT_Init().                 NOTE - This routine can be used only when working in                 Independent-Mode mode. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FM_PORT_ImTxConf
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PORT_ImRx   @Description   Rx function, may be called to poll for received buffers.                 Normally, Rx process is invoked by the driver on Rx interrupt.                 Alternatively, this routine may be called on demand.   @Param[in]     h_FmPort            A handle to a FM Port module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PORT_Init().                 NOTE - This routine can be used only when working in                 Independent-Mode mode. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PORT_ImRx
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PORT_runtime_data_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PORT_grp group */
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
comment|/* __FM_PORT_EXT */
end_comment

end_unit

