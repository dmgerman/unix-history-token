begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  @File          qm.h   @Description   QM header */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__QM_H
end_ifndef

begin_define
define|#
directive|define
name|__QM_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"list_ext.h"
end_include

begin_include
include|#
directive|include
file|"qm_ext.h"
end_include

begin_include
include|#
directive|include
file|"qman_private.h"
end_include

begin_include
include|#
directive|include
file|"qm_ipc.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_QM
end_define

begin_define
define|#
directive|define
name|QM_NUM_OF_SWP
value|10
end_define

begin_define
define|#
directive|define
name|QM_NUM_OF_DCP
value|5
end_define

begin_define
define|#
directive|define
name|CACHELINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|QM_CONTEXTA_MAX_STASH_SIZE
value|(3 * CACHELINE_SIZE)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|QM_EX_CORENET_INITIATOR_DATA
value|0x20000000
end_define

begin_define
define|#
directive|define
name|QM_EX_CORENET_TARGET_DATA
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QM_EX_CORENET_INVALID_TARGET_TRANSACTION
value|0x08000000
end_define

begin_define
define|#
directive|define
name|QM_EX_PFDR_THRESHOLD
value|0x04000000
end_define

begin_define
define|#
directive|define
name|QM_EX_MULTI_ECC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|QM_EX_SINGLE_ECC
value|0x01000000
end_define

begin_define
define|#
directive|define
name|QM_EX_PFDR_ENQUEUE_BLOCKED
value|0x00800000
end_define

begin_define
define|#
directive|define
name|QM_EX_INVALID_COMMAND
value|0x00010000
end_define

begin_define
define|#
directive|define
name|QM_EX_DEQUEUE_DCP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|QM_EX_DEQUEUE_FQ
value|0x00000400
end_define

begin_define
define|#
directive|define
name|QM_EX_DEQUEUE_SOURCE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|QM_EX_DEQUEUE_QUEUE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|QM_EX_ENQUEUE_OVERFLOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|QM_EX_ENQUEUE_STATE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|QM_EX_ENQUEUE_CHANNEL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|QM_EX_ENQUEUE_QUEUE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GET_EXCEPTION_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|exception
parameter_list|)
value|switch(exception){ \     case e_QM_EX_CORENET_INITIATOR_DATA:                                \         bitMask = QM_EX_CORENET_INITIATOR_DATA; break;                  \     case e_QM_EX_CORENET_TARGET_DATA:                                   \         bitMask = QM_EX_CORENET_TARGET_DATA; break;                     \     case e_QM_EX_CORENET_INVALID_TARGET_TRANSACTION:                    \         bitMask = QM_EX_CORENET_INVALID_TARGET_TRANSACTION; break;      \     case e_QM_EX_PFDR_THRESHOLD:                                        \         bitMask = QM_EX_PFDR_THRESHOLD; break;                          \     case e_QM_EX_PFDR_ENQUEUE_BLOCKED:                                  \         bitMask = QM_EX_PFDR_ENQUEUE_BLOCKED; break;                    \     case e_QM_EX_SINGLE_ECC:                                            \         bitMask = QM_EX_SINGLE_ECC; break;                              \     case e_QM_EX_MULTI_ECC:                                             \         bitMask = QM_EX_MULTI_ECC; break;                               \     case e_QM_EX_INVALID_COMMAND:                                       \         bitMask = QM_EX_INVALID_COMMAND; break;                         \     case e_QM_EX_DEQUEUE_DCP:                                           \         bitMask = QM_EX_DEQUEUE_DCP; break;                             \     case e_QM_EX_DEQUEUE_FQ:                                            \         bitMask = QM_EX_DEQUEUE_FQ; break;                              \     case e_QM_EX_DEQUEUE_SOURCE:                                        \         bitMask = QM_EX_DEQUEUE_SOURCE; break;                          \     case e_QM_EX_DEQUEUE_QUEUE:                                         \         bitMask = QM_EX_DEQUEUE_QUEUE; break;                           \     case e_QM_EX_ENQUEUE_OVERFLOW:                                      \         bitMask = QM_EX_ENQUEUE_OVERFLOW; break;                        \     case e_QM_EX_ENQUEUE_STATE:                                         \         bitMask = QM_EX_ENQUEUE_STATE; break;                           \     case e_QM_EX_ENQUEUE_CHANNEL:                                       \         bitMask = QM_EX_ENQUEUE_CHANNEL; break;                         \     case e_QM_EX_ENQUEUE_QUEUE:                                         \         bitMask = QM_EX_ENQUEUE_QUEUE; break;                           \     default: bitMask = 0;break;}
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       defaults */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* QM defaults */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_exceptions
value|((uint32_t)(QM_EX_CORENET_INITIATOR_DATA                | \                                                             QM_EX_CORENET_TARGET_DATA                   | \                                                             QM_EX_CORENET_INVALID_TARGET_TRANSACTION    | \                                                             QM_EX_PFDR_THRESHOLD                        | \                                                             QM_EX_SINGLE_ECC                            | \                                                             QM_EX_MULTI_ECC                             | \                                                             QM_EX_PFDR_ENQUEUE_BLOCKED                  | \                                                             QM_EX_INVALID_COMMAND                       | \                                                             QM_EX_DEQUEUE_DCP                           | \                                                             QM_EX_DEQUEUE_FQ                            | \                                                             QM_EX_DEQUEUE_SOURCE                        | \                                                             QM_EX_DEQUEUE_QUEUE                         | \                                                             QM_EX_ENQUEUE_OVERFLOW                      | \                                                             QM_EX_ENQUEUE_STATE                         | \                                                             QM_EX_ENQUEUE_CHANNEL                       | \                                                             QM_EX_ENQUEUE_QUEUE                         ))
end_define

begin_define
define|#
directive|define
name|DEFAULT_rtFramesDepth
value|30000
end_define

begin_define
define|#
directive|define
name|DEFAULT_pfdrThreshold
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_sfdrThreshold
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_pfdrBaseConstant
value|64
end_define

begin_comment
comment|/* Corenet initiator settings. Stash request queues are 4-deep to match cores'     ability to snart. Stash priority is 3, other priorities are 2. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_initiatorSrcciv
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_initiatorSrqW
value|3
end_define

begin_define
define|#
directive|define
name|DEFAULT_initiatorRwW
value|2
end_define

begin_define
define|#
directive|define
name|DEFAULT_initiatorBmanW
value|2
end_define

begin_comment
comment|/* QM-Portal defaults */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_dequeueDcaMode
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_dequeueUpToThreeFrames
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_dequeueCommandType
value|e_QM_PORTAL_PRIORITY_PRECEDENCE_INTRA_CLASS_SCHEDULING
end_define

begin_define
define|#
directive|define
name|DEFAULT_dequeueUserToken
value|0xab
end_define

begin_define
define|#
directive|define
name|DEFAULT_dequeueSpecifiedWq
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_dequeueDedicatedChannel
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_dequeuePoolChannelId
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_dequeueWqId
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_dequeueDedicatedChannelHasPrecedenceOverPoolChannels
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_dqrrSize
value|DQRR_MAXFILL
end_define

begin_define
define|#
directive|define
name|DEFAULT_pullMode
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_portalExceptions
value|((uint32_t)(QM_PIRQ_EQCI | \                                                             QM_PIRQ_EQRI | \                                                             QM_PIRQ_DQRI | \                                                             QM_PIRQ_MRI  | \                                                             QM_PIRQ_CSCI))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Memory Mapped Registers */
end_comment

begin_comment
comment|/***************************************************************************/
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

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
comment|/* QMan Software Portal Configuration Registers */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|lio_cfg
decl_stmt|;
comment|/**< QMan Software Portal LIO Configuration */
specifier|volatile
name|uint32_t
name|io_cfg
decl_stmt|;
comment|/**< QMan Software Portal 0 IO Configuration */
specifier|volatile
name|uint8_t
name|res1
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|dd_cfg
decl_stmt|;
comment|/**< Software Portal Dynamic Debug Configuration */
block|}
name|_PackedType
name|swpConfRegs
index|[
name|QM_NUM_OF_SWP
index|]
struct|;
specifier|volatile
name|uint8_t
name|res1
index|[
literal|352
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Dynamic Debug (DD) Configuration Registers */
specifier|volatile
name|uint32_t
name|qman_dd_cfg
decl_stmt|;
comment|/**< QMan Dynamic Debug (DD) Configuration */
specifier|volatile
name|uint8_t
name|res2
index|[
literal|12
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|qcsp_dd_ihrsr
decl_stmt|;
comment|/**< Software Portal DD Internal Halt Request Status */
specifier|volatile
name|uint32_t
name|qcsp_dd_ihrfr
decl_stmt|;
comment|/**< Software Portal DD Internal Halt Request Force */
specifier|volatile
name|uint32_t
name|qcsp_dd_hasr
decl_stmt|;
comment|/**< Software Portal DD Halt Acknowledge Status */
specifier|volatile
name|uint8_t
name|res3
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|dcp_dd_ihrsr
decl_stmt|;
comment|/**< DCP DD Internal Halt Request Status */
specifier|volatile
name|uint32_t
name|dcp_dd_ihrfr
decl_stmt|;
comment|/**< DCP DD Internal Halt Request Force */
specifier|volatile
name|uint32_t
name|dcp_dd_hasr
decl_stmt|;
comment|/**< DCP DD Halt Acknowledge Status */
specifier|volatile
name|uint8_t
name|res4
index|[
literal|212
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Direct Connect Portal (DCP) Configuration Registers */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|cfg
decl_stmt|;
comment|/**< DCP Configuration */
specifier|volatile
name|uint32_t
name|dd_cfg
decl_stmt|;
comment|/**< DCP Dynamic Debug Configuration */
specifier|volatile
name|uint32_t
name|dlm_cfg
decl_stmt|;
comment|/**< DCP Dequeue Latency Monitor Configuration */
specifier|volatile
name|uint32_t
name|dlm_avg
decl_stmt|;
comment|/**< DCP Dequeue Latency Monitor Average */
block|}
name|_PackedType
name|dcpConfRegs
index|[
name|QM_NUM_OF_DCP
index|]
struct|;
specifier|volatile
name|uint8_t
name|res5
index|[
literal|176
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Packed Frame Descriptor Record (PFDR) Manager Query Registers */
specifier|volatile
name|uint32_t
name|pfdr_fpc
decl_stmt|;
comment|/**< PFDR Free Pool Count */
specifier|volatile
name|uint32_t
name|pfdr_fp_head
decl_stmt|;
comment|/**< PFDR Free Pool Head Pointer */
specifier|volatile
name|uint32_t
name|pfdr_fp_tail
decl_stmt|;
comment|/**< PFDR Free Pool Tail Pointer */
specifier|volatile
name|uint8_t
name|res6
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|pfdr_fp_lwit
decl_stmt|;
comment|/**< PFDR Free Pool Low Watermark Interrupt Threshold */
specifier|volatile
name|uint32_t
name|pfdr_cfg
decl_stmt|;
comment|/**< PFDR Configuration */
specifier|volatile
name|uint8_t
name|res7
index|[
literal|232
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Single Frame Descriptor Record (SFDR) Manager Registers */
specifier|volatile
name|uint32_t
name|sfdr_cfg
decl_stmt|;
comment|/**< SFDR Configuration */
specifier|volatile
name|uint32_t
name|sfdr_in_use
decl_stmt|;
comment|/**< SFDR In Use Register */
specifier|volatile
name|uint8_t
name|res8
index|[
literal|248
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Work Queue Semaphore and Context Manager Registers */
specifier|volatile
name|uint32_t
name|wq_cs_cfg
index|[
literal|6
index|]
decl_stmt|;
comment|/**< Work Queue Class Scheduler Configuration */
specifier|volatile
name|uint8_t
name|res9
index|[
literal|24
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|wq_def_enq_wqid
decl_stmt|;
comment|/**< Work Queue Default Enqueue WQID */
specifier|volatile
name|uint8_t
name|res10
index|[
literal|12
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|wq_sc_dd_cfg
index|[
literal|5
index|]
decl_stmt|;
comment|/**< WQ S/W Channel Dynamic Debug Config */
specifier|volatile
name|uint8_t
name|res11
index|[
literal|44
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|wq_pc_dd_cs_cfg
index|[
literal|8
index|]
decl_stmt|;
comment|/**< WQ Pool Channel Dynamic Debug Config */
specifier|volatile
name|uint8_t
name|res12
index|[
literal|32
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|wq_dc0_dd_cs_cfg
index|[
literal|6
index|]
decl_stmt|;
comment|/**< WQ DCP0 Chan. Dynamic Debug Config */
specifier|volatile
name|uint8_t
name|res13
index|[
literal|40
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|wq_dc1_dd_cs_cfg
index|[
literal|6
index|]
decl_stmt|;
comment|/**< WQ DCP1 Chan. Dynamic Debug Config */
specifier|volatile
name|uint8_t
name|res14
index|[
literal|40
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|wq_dc2_dd_cs_cfg
decl_stmt|;
comment|/**< WQ DCP2 Chan. Dynamic Debug Config */
specifier|volatile
name|uint8_t
name|res15
index|[
literal|60
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|wq_dc3_dd_cs_cfg
decl_stmt|;
comment|/**< WQ DCP3 Chan. Dynamic Debug Config */
specifier|volatile
name|uint8_t
name|res16
index|[
literal|124
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Congestion Manager (CM) Registers */
specifier|volatile
name|uint32_t
name|cm_cfg
decl_stmt|;
comment|/**< CM Configuration Register */
specifier|volatile
name|uint8_t
name|res17
index|[
literal|508
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* QMan Error Capture Registers */
specifier|volatile
name|uint32_t
name|ecsr
decl_stmt|;
comment|/**< QMan Error Capture Status Register */
specifier|volatile
name|uint32_t
name|ecir
decl_stmt|;
comment|/**< QMan Error Capture Information Register */
specifier|volatile
name|uint32_t
name|eadr
decl_stmt|;
comment|/**< QMan Error Capture Address Register */
specifier|volatile
name|uint8_t
name|res18
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|edata
index|[
literal|16
index|]
decl_stmt|;
comment|/**< QMan ECC Error Data Register */
specifier|volatile
name|uint8_t
name|res19
index|[
literal|32
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|sbet
decl_stmt|;
comment|/**< QMan Single Bit ECC Error Threshold Register */
specifier|volatile
name|uint8_t
name|res20
index|[
literal|12
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|sbec
index|[
literal|7
index|]
decl_stmt|;
comment|/**< QMan Single Bit ECC Error Count Register */
specifier|volatile
name|uint8_t
name|res21
index|[
literal|100
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* QMan Initialization and Debug Control Registers */
specifier|volatile
name|uint32_t
name|mcr
decl_stmt|;
comment|/**< QMan Management Command/Result Register */
specifier|volatile
name|uint32_t
name|mcp0
decl_stmt|;
comment|/**< QMan Management Command Parameter 0 Register */
specifier|volatile
name|uint32_t
name|mcp1
decl_stmt|;
comment|/**< QMan Management Command Parameter 1 Register */
specifier|volatile
name|uint8_t
name|res22
index|[
literal|20
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|mr
index|[
literal|16
index|]
decl_stmt|;
comment|/**< QMan Management Return Register */
specifier|volatile
name|uint8_t
name|res23
index|[
literal|148
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|idle_stat
decl_stmt|;
comment|/**< QMan Idle Status Register */
comment|/* QMan ID/Revision Registers */
specifier|volatile
name|uint32_t
name|ip_rev_1
decl_stmt|;
comment|/**< QMan IP Block Revision 1 register */
specifier|volatile
name|uint32_t
name|ip_rev_2
decl_stmt|;
comment|/**< QMan IP Block Revision 2 register */
comment|/* QMan Initiator Interface Memory Window Configuration Registers */
specifier|volatile
name|uint32_t
name|fqd_bare
decl_stmt|;
comment|/**< FQD Extended Base Address Register */
specifier|volatile
name|uint32_t
name|fqd_bar
decl_stmt|;
comment|/**< Frame Queue Descriptor (FQD) Base Address Register */
specifier|volatile
name|uint8_t
name|res24
index|[
literal|8
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|fqd_ar
decl_stmt|;
comment|/**< FQD Attributes Register */
specifier|volatile
name|uint8_t
name|res25
index|[
literal|12
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|pfdr_bare
decl_stmt|;
comment|/**< PFDR Extended Base Address Register */
specifier|volatile
name|uint32_t
name|pfdr_bar
decl_stmt|;
comment|/**< Packed Frame Descriptor Record (PFDR) Base Addr */
specifier|volatile
name|uint8_t
name|res26
index|[
literal|8
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|pfdr_ar
decl_stmt|;
comment|/**< PFDR Attributes Register */
specifier|volatile
name|uint8_t
name|res27
index|[
literal|76
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|qcsp_bare
decl_stmt|;
comment|/**< QCSP Extended Base Address */
specifier|volatile
name|uint32_t
name|qcsp_bar
decl_stmt|;
comment|/**< QMan Software Portal Base Address */
specifier|volatile
name|uint8_t
name|res28
index|[
literal|120
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|ci_sched_cfg
decl_stmt|;
comment|/**< Initiator Scheduling Configuration */
specifier|volatile
name|uint32_t
name|srcidr
decl_stmt|;
comment|/**< QMan Source ID Register */
specifier|volatile
name|uint32_t
name|liodnr
decl_stmt|;
comment|/**< QMan Logical I/O Device Number Register */
specifier|volatile
name|uint8_t
name|res29
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|ci_rlm_cfg
decl_stmt|;
comment|/**< Initiator Read Latency Monitor Configuration */
specifier|volatile
name|uint32_t
name|ci_rlm_avg
decl_stmt|;
comment|/**< Initiator Read Latency Monitor Average */
specifier|volatile
name|uint8_t
name|res30
index|[
literal|232
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* QMan Interrupt and Error Registers */
specifier|volatile
name|uint32_t
name|err_isr
decl_stmt|;
comment|/**< QMan Error Interrupt Status Register */
specifier|volatile
name|uint32_t
name|err_ier
decl_stmt|;
comment|/**< QMan Error Interrupt Enable Register */
specifier|volatile
name|uint32_t
name|err_isdr
decl_stmt|;
comment|/**< QMan Error Interrupt Status Disable Register */
specifier|volatile
name|uint32_t
name|err_iir
decl_stmt|;
comment|/**< QMan Error Interrupt Inhibit Register */
specifier|volatile
name|uint8_t
name|res31
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|err_her
decl_stmt|;
comment|/**< QMan Error Halt Enable Register */
block|}
name|_PackedType
name|t_QmRegs
typedef|;
end_typedef

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
comment|/**  @Description       General defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MODULE_NAME_SIZE
value|30
end_define

begin_define
define|#
directive|define
name|PORTALS_OFFSET_CE
parameter_list|(
name|portal
parameter_list|)
value|(0x4000 * portal)
end_define

begin_define
define|#
directive|define
name|PORTALS_OFFSET_CI
parameter_list|(
name|portal
parameter_list|)
value|(0x1000 * portal)
end_define

begin_define
define|#
directive|define
name|PFDR_ENTRY_SIZE
value|64
end_define

begin_comment
comment|/* 64 bytes */
end_comment

begin_define
define|#
directive|define
name|FQD_ENTRY_SIZE
value|64
end_define

begin_comment
comment|/* 64 bytes */
end_comment

begin_comment
comment|/* Compilation constants */
end_comment

begin_define
define|#
directive|define
name|DQRR_MAXFILL
value|15
end_define

begin_define
define|#
directive|define
name|EQCR_THRESH
value|1
end_define

begin_comment
comment|/* reread h/w CI when running out of space */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Register defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* Assists for QMAN_MCR */
end_comment

begin_define
define|#
directive|define
name|MCR_INIT_PFDR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|MCR_get_rslt
parameter_list|(
name|v
parameter_list|)
value|(uint8_t)((v)>> 24)
end_define

begin_define
define|#
directive|define
name|MCR_rslt_idle
parameter_list|(
name|r
parameter_list|)
value|(!rslt || (rslt>= 0xf0))
end_define

begin_define
define|#
directive|define
name|MCR_rslt_ok
parameter_list|(
name|r
parameter_list|)
value|(rslt == 0xf0)
end_define

begin_define
define|#
directive|define
name|MCR_rslt_eaccess
parameter_list|(
name|r
parameter_list|)
value|(rslt == 0xf8)
end_define

begin_define
define|#
directive|define
name|MCR_rslt_inval
parameter_list|(
name|r
parameter_list|)
value|(rslt == 0xff)
end_define

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|REV1_MAJOR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|REV1_MINOR_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|REV2_INTEG_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|REV2_ERR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|REV2_CFG_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PRIORITY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_STASH
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_SIZE_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|ECIR_PORTAL_TYPE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ECIR_PORTAL_MASK
value|0x1f000000
end_define

begin_define
define|#
directive|define
name|ECIR_FQID_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|CI_SCHED_CFG_EN
value|0x80000000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|REV1_MAJOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|REV1_MINOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|REV2_INTEG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|REV2_ERR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|REV2_CFG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR_SIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ECIR_PORTAL_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|ECIR_FQID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CI_SCHED_CFG_SRCCIV_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CI_SCHED_CFG_SRQ_W_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CI_SCHED_CFG_RW_W_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|CI_SCHED_CFG_BMAN_W_SHIFT
value|0
end_define

begin_comment
comment|/********* CGR ******************************/
end_comment

begin_define
define|#
directive|define
name|QM_CGR_TARG_FIRST_SWPORTAL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QM_CGR_TARG_FIRST_DCPORTAL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|QM_CGR_TARGET_SWP
parameter_list|(
name|portlaId
parameter_list|)
value|(QM_CGR_TARG_FIRST_SWPORTAL>> portlaId)
end_define

begin_define
define|#
directive|define
name|QM_CGR_TARGET_DCP
parameter_list|(
name|portlaId
parameter_list|)
value|(QM_CGR_TARG_FIRST_DCPORTAL>> portlaId)
end_define

begin_define
define|#
directive|define
name|QM_DCP_CFG_ED
value|0x00000100
end_define

begin_comment
comment|/* #define CGR_VALID                       0x80 #define CGR_VERB_INIT                   0x50 #define CGR_VERB_MODIFY                 0x51 #define CGR_WRITE_ALL                   0x07FF #define CGR_WRITE_ENABLE_CSCN           0x0010 #define CGR_WRITE_ENABLE_GREEN_MODIFY   0x0380 #define CGR_WRITE_ENABLE_YELLOW_MODIFY  0x0240 #define CGR_WRITE_ENABLE_RED_MODIFY     0x0120   #define CGR_MODE_BYTE               0x00 #define CGR_MODE_FRAME              0x01 #define GCR_ENABLE_WRED             0x01 #define GCR_ENABLE_TD               0x01 #define GCR_ENABLE_CSCN             0x01 */
end_comment

begin_comment
comment|/* Lock/unlock frame queues, subject to the "UNLOCKED" flag. This is about  * inter-processor locking only. */
end_comment

begin_define
define|#
directive|define
name|FQLOCK
parameter_list|(
name|fq
parameter_list|)
define|\
value|do {                                        \         if (fq->flags& QMAN_FQ_FLAG_LOCKED)    \             XX_LockSpinlock(&fq->fqlock);       \     } while(0)
end_define

begin_define
define|#
directive|define
name|FQUNLOCK
parameter_list|(
name|fq
parameter_list|)
define|\
value|do {                                        \         if (fq->flags& QMAN_FQ_FLAG_LOCKED)    \             XX_UnlockSpinlock(&fq->fqlock);     \     } while(0)
end_define

begin_comment
comment|/* Lock/unlock portals, subject to "UNLOCKED" flag. This is about disabling  * interrupts/preemption and, if FLAG_UNLOCKED isn't defined, inter-processor  * locking as well. */
end_comment

begin_define
define|#
directive|define
name|NCSW_PLOCK
parameter_list|(
name|p
parameter_list|)
value|((t_QmPortal*)(p))->irq_flags = XX_DisableAllIntr()
end_define

begin_define
define|#
directive|define
name|PUNLOCK
parameter_list|(
name|p
parameter_list|)
value|XX_RestoreAllIntr(((t_QmPortal*)(p))->irq_flags)
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_QmLoopDequeueRing
function_decl|)
parameter_list|(
name|t_Handle
name|h_QmPortal
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Follows WQ_CS_CFG0-5 */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_QM_WQ_SW_PORTALS
init|=
literal|0
block|,
name|e_QM_WQ_POOLS
block|,
name|e_QM_WQ_DCP0
block|,
name|e_QM_WQ_DCP1
block|,
name|e_QM_WQ_DCP2
block|,
name|e_QM_WQ_DCP3
block|}
name|e_QmWqClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_QM_PORTAL_NO_DEQUEUES
init|=
literal|0
block|,
name|e_QM_PORTAL_PRIORITY_PRECEDENCE_INTRA_CLASS_SCHEDULING
block|,
name|e_QM_PORTAL_ACTIVE_FQ_PRECEDENCE_INTRA_CLASS_SCHEDULING
block|,
name|e_QM_PORTAL_ACTIVE_FQ_PRECEDENCE_OVERRIDE_INTRA_CLASS_SCHEDULING
block|}
name|e_QmPortalDequeueCommandType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|e_QmInterModuleCounters
block|{
name|e_QM_IM_COUNTERS_SFDR_IN_USE
init|=
literal|0
block|,
name|e_QM_IM_COUNTERS_PFDR_IN_USE
block|,
name|e_QM_IM_COUNTERS_PFDR_FREE_POOL
block|}
name|e_QmInterModuleCounters
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_QmInterModulePortalInitParams
block|{
name|uint8_t
name|portalId
decl_stmt|;
name|uint8_t
name|stashDestQueue
decl_stmt|;
name|uint16_t
name|liodn
decl_stmt|;
name|uint16_t
name|dqrrLiodn
decl_stmt|;
name|uint16_t
name|fdFqLiodn
decl_stmt|;
block|}
name|t_QmInterModulePortalInitParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_QmCg
block|{
name|t_Handle
name|h_Qm
decl_stmt|;
name|t_Handle
name|h_QmPortal
decl_stmt|;
name|t_QmExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
block|}
name|t_QmCg
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uintptr_t
name|swPortalsBaseAddress
decl_stmt|;
comment|/**< QM Software Portals Base Address (virtual) */
name|uint32_t
name|partFqidBase
decl_stmt|;
name|uint32_t
name|partNumOfFqids
decl_stmt|;
name|uint32_t
name|totalNumOfFqids
decl_stmt|;
name|uint32_t
name|rtFramesDepth
decl_stmt|;
name|uint32_t
name|fqdMemPartitionId
decl_stmt|;
name|uint32_t
name|pfdrMemPartitionId
decl_stmt|;
name|uint32_t
name|pfdrThreshold
decl_stmt|;
name|uint32_t
name|sfdrThreshold
decl_stmt|;
name|uint32_t
name|pfdrBaseConstant
decl_stmt|;
name|uint16_t
name|liodn
decl_stmt|;
name|t_QmDcPortalParams
name|dcPortalsParams
index|[
name|DPAA_MAX_NUM_OF_DC_PORTALS
index|]
decl_stmt|;
block|}
name|t_QmDriverParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|guestId
decl_stmt|;
name|t_Handle
name|h_RsrvFqidMm
decl_stmt|;
name|t_Handle
name|h_FqidMm
decl_stmt|;
name|t_Handle
name|h_Session
decl_stmt|;
name|char
name|moduleName
index|[
name|MODULE_NAME_SIZE
index|]
decl_stmt|;
name|t_Handle
name|h_Portals
index|[
name|DPAA_MAX_NUM_OF_SW_PORTALS
index|]
decl_stmt|;
name|t_QmRegs
modifier|*
name|p_QmRegs
decl_stmt|;
name|uint32_t
modifier|*
name|p_FqdBase
decl_stmt|;
name|uint32_t
modifier|*
name|p_PfdrBase
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|t_QmExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
name|uintptr_t
name|errIrq
decl_stmt|;
comment|/**< error interrupt line; NO_IRQ if interrupts not used */
name|uint32_t
name|numOfPfdr
decl_stmt|;
name|uint16_t
name|partNumOfCgs
decl_stmt|;
name|uint16_t
name|partCgsBase
decl_stmt|;
name|uint8_t
name|cgsUsed
index|[
name|QM_MAX_NUM_OF_CGS
index|]
decl_stmt|;
name|t_Handle
name|lock
decl_stmt|;
name|t_QmDriverParams
modifier|*
name|p_QmDriverParams
decl_stmt|;
block|}
name|t_Qm
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|hwExtStructsMemAttr
decl_stmt|;
name|uint8_t
name|dqrrSize
decl_stmt|;
name|bool
name|pullMode
decl_stmt|;
name|bool
name|dequeueDcaMode
decl_stmt|;
name|bool
name|dequeueUpToThreeFrames
decl_stmt|;
name|e_QmPortalDequeueCommandType
name|commandType
decl_stmt|;
name|uint8_t
name|userToken
decl_stmt|;
name|bool
name|specifiedWq
decl_stmt|;
name|bool
name|dedicatedChannel
decl_stmt|;
name|bool
name|dedicatedChannelHasPrecedenceOverPoolChannels
decl_stmt|;
name|uint8_t
name|poolChannels
index|[
name|QM_MAX_NUM_OF_POOL_CHANNELS
index|]
decl_stmt|;
name|uint8_t
name|poolChannelId
decl_stmt|;
name|uint8_t
name|wqId
decl_stmt|;
name|uint16_t
name|fdLiodnOffset
decl_stmt|;
name|uint8_t
name|stashDestQueue
decl_stmt|;
name|uint8_t
name|eqcr
decl_stmt|;
name|bool
name|eqcrHighPri
decl_stmt|;
name|bool
name|dqrr
decl_stmt|;
name|uint16_t
name|dqrrLiodn
decl_stmt|;
name|bool
name|dqrrHighPri
decl_stmt|;
name|bool
name|fdFq
decl_stmt|;
name|uint16_t
name|fdFqLiodn
decl_stmt|;
name|bool
name|fdFqHighPri
decl_stmt|;
name|bool
name|fdFqDrop
decl_stmt|;
block|}
name|t_QmPortalDriverParams
typedef|;
end_typedef

begin_comment
comment|/*typedef struct t_QmPortalCgs{     uint32_t    cgsMask[QM_MAX_NUM_OF_CGS/32]; }t_QmPortalCgs; */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmPortal
block|{
name|t_Handle
name|h_Qm
decl_stmt|;
name|struct
name|qm_portal
modifier|*
name|p_LowQmPortal
decl_stmt|;
name|uint32_t
name|bits
decl_stmt|;
comment|/* PORTAL_BITS_*** - dynamic, strictly internal */
name|t_Handle
name|h_App
decl_stmt|;
name|t_QmLoopDequeueRing
modifier|*
name|f_LoopDequeueRingCB
decl_stmt|;
name|bool
name|pullMode
decl_stmt|;
comment|/* To avoid overloading the term "flags", we use these 2; */
name|uint32_t
name|options
decl_stmt|;
comment|/* QMAN_PORTAL_FLAG_*** - static, caller-provided */
name|uint32_t
name|irq_flags
decl_stmt|;
comment|/* The wrap-around eq_[prod|cons] counters are used to support      * QMAN_ENQUEUE_FLAG_WAIT_SYNC. */
name|uint32_t
name|eqProd
decl_stmt|;
specifier|volatile
name|int
name|disable_count
decl_stmt|;
name|struct
name|qman_cgrs
name|cgrs
index|[
literal|2
index|]
decl_stmt|;
comment|/* 2-element array. cgrs[0] is mask, cgrs[1] is previous snapshot. */
comment|/* If we receive a DQRR or MR ring entry for a "null" FQ, ie. for which      * FQD::contextB is NULL rather than pointing to a FQ object, we use      * these handlers. (This is not considered a fast-path mechanism.) */
name|t_Handle
name|cgsHandles
index|[
name|QM_MAX_NUM_OF_CGS
index|]
decl_stmt|;
name|struct
name|qman_fq_cb
modifier|*
name|p_NullCB
decl_stmt|;
name|t_QmReceivedFrameCallback
modifier|*
name|f_DfltFrame
decl_stmt|;
name|t_QmRejectedFrameCallback
modifier|*
name|f_RejectedFrame
decl_stmt|;
name|t_QmPortalDriverParams
modifier|*
name|p_QmPortalDriverParams
decl_stmt|;
block|}
name|t_QmPortal
typedef|;
end_typedef

begin_struct
struct|struct
name|qman_fq
block|{
name|struct
name|qman_fq_cb
name|cb
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
name|t_Handle
name|h_QmFqr
decl_stmt|;
name|t_Handle
name|fqlock
decl_stmt|;
name|uint32_t
name|fqid
decl_stmt|;
name|uint32_t
name|fqidOffset
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* s/w-visible states. Ie. tentatively scheduled + truly scheduled +      * active + held-active + held-suspended are just "sched". Things like      * 'retired' will not be assumed until it is complete (ie.      * QMAN_FQ_STATE_CHANGING is set until then, to indicate it's completing      * and to gate attempts to retry the retire command). Note, park      * commands do not set QMAN_FQ_STATE_CHANGING because it's technically      * impossible in the case of enqueue DCAs (which refer to DQRR ring      * index rather than the FQ that ring entry corresponds to), so repeated      * park commands are allowed (if you're silly enough to try) but won't      * change FQ state, and the resulting park notifications move FQs from      * 'sched' to 'parked'. */
name|enum
name|qman_fq_state
name|state
decl_stmt|;
name|int
name|cgr_groupid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Qm
decl_stmt|;
name|t_Handle
name|h_QmPortal
decl_stmt|;
name|e_QmFQChannel
name|channel
decl_stmt|;
name|uint8_t
name|workQueue
decl_stmt|;
name|bool
name|shadowMode
decl_stmt|;
name|uint32_t
name|fqidBase
decl_stmt|;
name|uint32_t
name|numOfFqids
decl_stmt|;
name|t_QmFqrDrainedCompletionCB
modifier|*
name|f_CompletionCB
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
name|uint32_t
name|numOfDrainedFqids
decl_stmt|;
name|bool
modifier|*
name|p_DrainedFqs
decl_stmt|;
name|struct
name|qman_fq
modifier|*
modifier|*
name|p_Fqs
decl_stmt|;
block|}
name|t_QmFqr
typedef|;
end_typedef

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/*       Inter-Module functions         */
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_function_decl
name|uint32_t
name|QmGetCounter
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|e_QmInterModuleCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|QmGetRevision
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|t_QmRevisionInfo
modifier|*
name|p_QmRevisionInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|QmGetSetPortalParams
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|t_QmInterModulePortalInitParams
modifier|*
name|p_PortalParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|QmFreeDcPortal
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|e_DpaaDcPortal
name|dcPortalId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|QmFqidGet
parameter_list|(
name|t_Qm
modifier|*
name|p_Qm
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|uint32_t
name|alignment
parameter_list|,
name|bool
name|force
parameter_list|,
name|uint32_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|QmFqidPut
parameter_list|(
name|t_Qm
modifier|*
name|p_Qm
parameter_list|,
name|uint32_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|QmGetCgId
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|uint8_t
modifier|*
name|p_CgId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|QmFreeCgId
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|uint8_t
name|cgId
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline__
name|void
name|QmSetPortalHandle
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|t_Handle
name|h_Portal
parameter_list|,
name|e_DpaaSwPortal
name|portalId
parameter_list|)
block|{
name|ASSERT_COND
argument_list|(
operator|!
operator|(
operator|(
name|t_Qm
operator|*
operator|)
name|h_Qm
operator|)
operator|->
name|h_Portals
index|[
name|portalId
index|]
operator|||
operator|!
name|h_Portal
argument_list|)
expr_stmt|;
operator|(
operator|(
name|t_Qm
operator|*
operator|)
name|h_Qm
operator|)
operator|->
name|h_Portals
index|[
name|portalId
index|]
operator|=
name|h_Portal
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|t_Handle
name|QmGetPortalHandle
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|)
block|{
name|t_Qm
modifier|*
name|p_Qm
init|=
operator|(
name|t_Qm
operator|*
operator|)
name|h_Qm
decl_stmt|;
name|ASSERT_COND
argument_list|(
name|p_Qm
argument_list|)
expr_stmt|;
return|return
name|p_Qm
operator|->
name|h_Portals
index|[
name|CORE_GetId
argument_list|()
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint32_t
name|GenerateCgrThresh
parameter_list|(
name|uint64_t
name|val
parameter_list|,
name|int
name|roundup
parameter_list|)
block|{
name|uint32_t
name|e
init|=
literal|0
decl_stmt|;
comment|/* co-efficient, exponent */
name|uint32_t
name|oddbit
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|val
operator|>
literal|0xff
condition|)
block|{
name|oddbit
operator|=
operator|(
name|uint32_t
operator|)
name|val
operator|&
literal|1
expr_stmt|;
name|val
operator|>>=
literal|1
expr_stmt|;
name|e
operator|++
expr_stmt|;
if|if
condition|(
name|roundup
operator|&&
name|oddbit
condition|)
name|val
operator|++
expr_stmt|;
block|}
return|return
call|(
name|uint32_t
call|)
argument_list|(
operator|(
name|val
operator|<<
literal|5
operator|)
operator||
name|e
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|t_Error
name|SetException
parameter_list|(
name|t_Qm
modifier|*
name|p_Qm
parameter_list|,
name|e_QmExceptions
name|exception
parameter_list|,
name|bool
name|enable
parameter_list|)
block|{
name|uint32_t
name|bitMask
init|=
literal|0
decl_stmt|;
name|ASSERT_COND
argument_list|(
name|p_Qm
argument_list|)
expr_stmt|;
name|GET_EXCEPTION_FLAG
argument_list|(
name|bitMask
argument_list|,
name|exception
argument_list|)
expr_stmt|;
if|if
condition|(
name|bitMask
condition|)
block|{
if|if
condition|(
name|enable
condition|)
name|p_Qm
operator|->
name|exceptions
operator||=
name|bitMask
expr_stmt|;
else|else
name|p_Qm
operator|->
name|exceptions
operator|&=
operator|~
name|bitMask
expr_stmt|;
block|}
else|else
name|RETURN_ERROR
argument_list|(
name|MAJOR
argument_list|,
name|E_INVALID_VALUE
argument_list|,
operator|(
literal|"Undefined exception"
operator|)
argument_list|)
expr_stmt|;
return|return
name|E_OK
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __QM_H */
end_comment

end_unit

