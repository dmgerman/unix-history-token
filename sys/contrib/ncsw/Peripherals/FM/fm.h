begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm.h   @Description   FM internal structures and definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_H
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
file|"fm_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_ipc.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_FM
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_HW_PORT_IDS
value|64
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_GUESTS
value|100
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
name|FM_EX_DMA_BUS_ERROR
value|0x80000000
end_define

begin_comment
comment|/**< DMA bus error. */
end_comment

begin_define
define|#
directive|define
name|FM_EX_DMA_READ_ECC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_EX_DMA_SYSTEM_WRITE_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_EX_DMA_FM_WRITE_ECC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FM_EX_FPM_STALL_ON_TASKS
value|0x08000000
end_define

begin_comment
comment|/**< Stall of tasks on FPM */
end_comment

begin_define
define|#
directive|define
name|FM_EX_FPM_SINGLE_ECC
value|0x04000000
end_define

begin_comment
comment|/**< Single ECC on FPM */
end_comment

begin_define
define|#
directive|define
name|FM_EX_FPM_DOUBLE_ECC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FM_EX_QMI_SINGLE_ECC
value|0x01000000
end_define

begin_comment
comment|/**< Single ECC on FPM */
end_comment

begin_define
define|#
directive|define
name|FM_EX_QMI_DEQ_FROM_UNKNOWN_PORTID
value|0x00800000
end_define

begin_comment
comment|/**< Dequeu from default queue id */
end_comment

begin_define
define|#
directive|define
name|FM_EX_QMI_DOUBLE_ECC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FM_EX_BMI_LIST_RAM_ECC
value|0x00200000
end_define

begin_define
define|#
directive|define
name|FM_EX_BMI_PIPELINE_ECC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|FM_EX_BMI_STATISTICS_RAM_ECC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FM_EX_IRAM_ECC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|FM_EX_NURAM_ECC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FM_EX_BMI_DISPATCH_RAM_ECC
value|0x00010000
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
value|switch(exception){ \     case e_FM_EX_DMA_BUS_ERROR:                                         \         bitMask = FM_EX_DMA_BUS_ERROR; break;                           \     case e_FM_EX_DMA_READ_ECC:                                          \         bitMask = FM_EX_DMA_READ_ECC; break;                            \     case e_FM_EX_DMA_SYSTEM_WRITE_ECC:                                  \         bitMask = FM_EX_DMA_SYSTEM_WRITE_ECC; break;                    \     case e_FM_EX_DMA_FM_WRITE_ECC:                                      \         bitMask = FM_EX_DMA_FM_WRITE_ECC; break;                        \     case e_FM_EX_FPM_STALL_ON_TASKS:                                    \         bitMask = FM_EX_FPM_STALL_ON_TASKS; break;                      \     case e_FM_EX_FPM_SINGLE_ECC:                                        \         bitMask = FM_EX_FPM_SINGLE_ECC; break;                          \     case e_FM_EX_FPM_DOUBLE_ECC:                                        \         bitMask = FM_EX_FPM_DOUBLE_ECC; break;                          \     case e_FM_EX_QMI_SINGLE_ECC:                                        \         bitMask = FM_EX_QMI_SINGLE_ECC; break;                          \     case e_FM_EX_QMI_DOUBLE_ECC:                                        \         bitMask = FM_EX_QMI_DOUBLE_ECC; break;                          \     case e_FM_EX_QMI_DEQ_FROM_UNKNOWN_PORTID:                           \         bitMask = FM_EX_QMI_DEQ_FROM_UNKNOWN_PORTID; break;             \     case e_FM_EX_BMI_LIST_RAM_ECC:                                      \         bitMask = FM_EX_BMI_LIST_RAM_ECC; break;                        \     case e_FM_EX_BMI_PIPELINE_ECC:                                      \         bitMask = FM_EX_BMI_PIPELINE_ECC; break;                        \     case e_FM_EX_BMI_STATISTICS_RAM_ECC:                                \         bitMask = FM_EX_BMI_STATISTICS_RAM_ECC; break;                  \     case e_FM_EX_BMI_DISPATCH_RAM_ECC:                                  \         bitMask = FM_EX_BMI_DISPATCH_RAM_ECC; break;                    \     case e_FM_EX_IRAM_ECC:                                              \         bitMask = FM_EX_IRAM_ECC; break;                                \     case e_FM_EX_MURAM_ECC:                                             \         bitMask = FM_EX_NURAM_ECC; break;                               \     default: bitMask = 0;break;}
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

begin_define
define|#
directive|define
name|DEFAULT_exceptions
value|(FM_EX_DMA_BUS_ERROR            |\                                             FM_EX_DMA_READ_ECC              |\                                             FM_EX_DMA_SYSTEM_WRITE_ECC      |\                                             FM_EX_DMA_FM_WRITE_ECC          |\                                             FM_EX_FPM_STALL_ON_TASKS        |\                                             FM_EX_FPM_SINGLE_ECC            |\                                             FM_EX_FPM_DOUBLE_ECC            |\                                             FM_EX_QMI_SINGLE_ECC            |\                                             FM_EX_QMI_DEQ_FROM_UNKNOWN_PORTID|\                                             FM_EX_QMI_DOUBLE_ECC            |\                                             FM_EX_BMI_LIST_RAM_ECC          |\                                             FM_EX_BMI_PIPELINE_ECC          |\                                             FM_EX_BMI_STATISTICS_RAM_ECC    |\                                             FM_EX_BMI_DISPATCH_RAM_ECC      |\                                             FM_EX_IRAM_ECC                  |\                                             FM_EX_NURAM_ECC                 )
end_define

begin_define
define|#
directive|define
name|DEFAULT_totalNumOfTasks
value|(BMI_MAX_NUM_OF_TASKS*3/4)
end_define

begin_define
define|#
directive|define
name|DEFAULT_totalFifoSize
value|(BMI_MAX_FIFO_SIZE*3/4)
end_define

begin_define
define|#
directive|define
name|DEFAULT_maxNumOfOpenDmas
value|(BMI_MAX_NUM_OF_DMAS*3/4)
end_define

begin_define
define|#
directive|define
name|DEFAULT_eccEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_dispLimit
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_prsDispTh
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_plcrDispTh
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_kgDispTh
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_bmiDispTh
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_qmiEnqDispTh
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_qmiDeqDispTh
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_fmCtl1DispTh
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_fmCtl2DispTh
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_cacheOverride
value|e_FM_DMA_NO_CACHE_OR
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FM_PEDANTIC_DMA
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_aidOverride
value|TRUE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_aidOverride
value|FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_PEDANTIC_DMA */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_aidMode
value|e_FM_DMA_AID_OUT_TNUM
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaStopOnBusError
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_stopAtBusError
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_axiDbgNumOfBeats
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaCamNumOfEntries
value|32
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaCommQLow
value|((DMA_THRESH_MAX_COMMQ+1)/2)
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaCommQHigh
value|((DMA_THRESH_MAX_COMMQ+1)*3/4)
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaReadIntBufLow
value|((DMA_THRESH_MAX_BUF+1)/2)
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaReadIntBufHigh
value|((DMA_THRESH_MAX_BUF+1)*3/4)
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaWriteIntBufLow
value|((DMA_THRESH_MAX_BUF+1)/2)
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaWriteIntBufHigh
value|((DMA_THRESH_MAX_BUF+1)*3/4)
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaSosEmergency
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaDbgCntMode
value|e_FM_DMA_DBG_NO_CNT
end_define

begin_define
define|#
directive|define
name|DEFAULT_catastrophicErr
value|e_FM_CATASTROPHIC_ERR_STALL_PORT
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaErr
value|e_FM_DMA_ERR_CATASTROPHIC
end_define

begin_define
define|#
directive|define
name|DEFAULT_resetOnInit
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_haltOnExternalActivation
value|FALSE
end_define

begin_comment
comment|/* do not change! if changed, must be disabled for rev1 ! */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_haltOnUnrecoverableEccError
value|FALSE
end_define

begin_comment
comment|/* do not change! if changed, must be disabled for rev1 ! */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_externalEccRamsEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_VerifyUcode
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_tnumAgingPeriod
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaWatchdog
value|0
end_define

begin_comment
comment|/* disabled */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_mtu
value|9600
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Modules registers offsets */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_MM_MURAM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FM_MM_BMI
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FM_MM_QMI
value|0x00080400
end_define

begin_define
define|#
directive|define
name|FM_MM_PRS
value|0x000c7000
end_define

begin_define
define|#
directive|define
name|FM_MM_KG
value|0x000C1000
end_define

begin_define
define|#
directive|define
name|FM_MM_DMA
value|0x000C2000
end_define

begin_define
define|#
directive|define
name|FM_MM_FPM
value|0x000C3000
end_define

begin_define
define|#
directive|define
name|FM_MM_PLCR
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|FM_MM_IMEM
value|0x000C4000
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Interrupt Enable/Mask */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

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
specifier|volatile
name|uint32_t
name|fpmtnc
decl_stmt|;
comment|/**< FPM TNUM Control */
specifier|volatile
name|uint32_t
name|fpmpr
decl_stmt|;
comment|/**< FPM Port_ID FmCtl Association */
specifier|volatile
name|uint32_t
name|brkc
decl_stmt|;
comment|/**< FPM Breakpoint Control */
specifier|volatile
name|uint32_t
name|fpmflc
decl_stmt|;
comment|/**< FPM Flush Control */
specifier|volatile
name|uint32_t
name|fpmdis1
decl_stmt|;
comment|/**< FPM Dispatch Thresholds1 */
specifier|volatile
name|uint32_t
name|fpmdis2
decl_stmt|;
comment|/**< FPM Dispatch Thresholds2  */
specifier|volatile
name|uint32_t
name|fmepi
decl_stmt|;
comment|/**< FM Error Pending Interrupts */
specifier|volatile
name|uint32_t
name|fmrie
decl_stmt|;
comment|/**< FM Error Interrupt Enable */
specifier|volatile
name|uint32_t
name|fmfpfcev
index|[
literal|4
index|]
decl_stmt|;
comment|/**< FPM FMan-Controller Event 1-4 */
specifier|volatile
name|uint8_t
name|res1
index|[
literal|16
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|fmfpfcee
index|[
literal|4
index|]
decl_stmt|;
comment|/**< PM FMan-Controller Event 1-4 */
specifier|volatile
name|uint8_t
name|res2
index|[
literal|16
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|fpmtsc1
decl_stmt|;
comment|/**< FPM TimeStamp Control1 */
specifier|volatile
name|uint32_t
name|fpmtsc2
decl_stmt|;
comment|/**< FPM TimeStamp Control2 */
specifier|volatile
name|uint32_t
name|fpmtsp
decl_stmt|;
comment|/**< FPM Time Stamp */
specifier|volatile
name|uint32_t
name|fpmtsf
decl_stmt|;
comment|/**< FPM Time Stamp Fraction */
specifier|volatile
name|uint32_t
name|fmrcr
decl_stmt|;
comment|/**< FM Rams Control */
specifier|volatile
name|uint32_t
name|fpmextc
decl_stmt|;
comment|/**< FPM External Requests Control */
specifier|volatile
name|uint32_t
name|fpmext1
decl_stmt|;
comment|/**< FPM External Requests Config1 */
specifier|volatile
name|uint32_t
name|fpmext2
decl_stmt|;
comment|/**< FPM External Requests Config2 */
specifier|volatile
name|uint32_t
name|fpmdrd
index|[
literal|16
index|]
decl_stmt|;
comment|/**< FPM Data_Ram Data 0-15 */
specifier|volatile
name|uint32_t
name|fpmdra
decl_stmt|;
comment|/**< FPM Data Ram Access */
specifier|volatile
name|uint32_t
name|fm_ip_rev_1
decl_stmt|;
comment|/**< FM IP Block Revision 1 */
specifier|volatile
name|uint32_t
name|fm_ip_rev_2
decl_stmt|;
comment|/**< FM IP Block Revision 2 */
specifier|volatile
name|uint32_t
name|fmrstc
decl_stmt|;
comment|/**< FM Reset Command */
specifier|volatile
name|uint32_t
name|fmcld
decl_stmt|;
comment|/**< FM Classifier Debug */
specifier|volatile
name|uint32_t
name|fmnpi
decl_stmt|;
comment|/**< FM Normal Pending Interrupts  */
specifier|volatile
name|uint32_t
name|fmfp_exte
decl_stmt|;
comment|/**< FPM External Requests Enable */
specifier|volatile
name|uint32_t
name|fpmem
decl_stmt|;
comment|/**< FPM Event& Mask */
specifier|volatile
name|uint32_t
name|fpmcev
index|[
literal|4
index|]
decl_stmt|;
comment|/**< FPM CPU Event 1-4 */
specifier|volatile
name|uint8_t
name|res4
index|[
literal|16
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|fmfp_ps
index|[
literal|0x40
index|]
decl_stmt|;
comment|/**< FPM Port Status */
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|0x260
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fpmts
index|[
literal|128
index|]
decl_stmt|;
comment|/**< 0x400: FPM Task Status */
block|}
name|_PackedType
name|t_FmFpmRegs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NUM_OF_DBG_TRAPS
value|3
end_define

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fmbm_init
decl_stmt|;
comment|/**< BMI Initialization */
specifier|volatile
name|uint32_t
name|fmbm_cfg1
decl_stmt|;
comment|/**< BMI Configuration 1 */
specifier|volatile
name|uint32_t
name|fmbm_cfg2
decl_stmt|;
comment|/**< BMI Configuration 2 */
specifier|volatile
name|uint32_t
name|reserved
index|[
literal|5
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmbm_ievr
decl_stmt|;
comment|/**< Interrupt Event Register */
specifier|volatile
name|uint32_t
name|fmbm_ier
decl_stmt|;
comment|/**< Interrupt Enable Register */
specifier|volatile
name|uint32_t
name|fmbm_ifr
decl_stmt|;
comment|/**< Interrupt Force Register */
specifier|volatile
name|uint32_t
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmbm_arb
index|[
literal|8
index|]
decl_stmt|;
comment|/**< BMI Arbitration */
specifier|volatile
name|uint32_t
name|reserved2
index|[
literal|12
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmbm_dtc
index|[
name|NUM_OF_DBG_TRAPS
index|]
decl_stmt|;
comment|/**< BMI Debug Trap Counter */
specifier|volatile
name|uint32_t
name|reserved3
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmbm_dcv
index|[
name|NUM_OF_DBG_TRAPS
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/**< BMI Debug Compare Value */
specifier|volatile
name|uint32_t
name|fmbm_dcm
index|[
name|NUM_OF_DBG_TRAPS
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/**< BMI Debug Compare Mask */
specifier|volatile
name|uint32_t
name|fmbm_gde
decl_stmt|;
comment|/**< BMI Global Debug Enable */
specifier|volatile
name|uint32_t
name|fmbm_pp
index|[
literal|63
index|]
decl_stmt|;
comment|/**< BMI Port Parameters */
specifier|volatile
name|uint32_t
name|reserved4
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmbm_pfs
index|[
literal|63
index|]
decl_stmt|;
comment|/**< BMI Port FIFO Size */
specifier|volatile
name|uint32_t
name|reserved5
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmbm_ppid
index|[
literal|63
index|]
decl_stmt|;
comment|/**< Port Partition ID */
block|}
name|_PackedType
name|t_FmBmiRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fmqm_gc
decl_stmt|;
comment|/**<  General Configuration Register */
specifier|volatile
name|uint32_t
name|Reserved0
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmqm_eie
decl_stmt|;
comment|/**<  Error Interrupt Event Register */
specifier|volatile
name|uint32_t
name|fmqm_eien
decl_stmt|;
comment|/**<  Error Interrupt Enable Register */
specifier|volatile
name|uint32_t
name|fmqm_eif
decl_stmt|;
comment|/**<  Error Interrupt Force Register */
specifier|volatile
name|uint32_t
name|fmqm_ie
decl_stmt|;
comment|/**<  Interrupt Event Register */
specifier|volatile
name|uint32_t
name|fmqm_ien
decl_stmt|;
comment|/**<  Interrupt Enable Register */
specifier|volatile
name|uint32_t
name|fmqm_if
decl_stmt|;
comment|/**<  Interrupt Force Register */
specifier|volatile
name|uint32_t
name|fmqm_gs
decl_stmt|;
comment|/**<  Global Status Register */
specifier|volatile
name|uint32_t
name|fmqm_ts
decl_stmt|;
comment|/**<  Task Status Register */
specifier|volatile
name|uint32_t
name|fmqm_etfc
decl_stmt|;
comment|/**<  Enqueue Total Frame Counter */
specifier|volatile
name|uint32_t
name|fmqm_dtfc
decl_stmt|;
comment|/**<  Dequeue Total Frame Counter */
specifier|volatile
name|uint32_t
name|fmqm_dc0
decl_stmt|;
comment|/**<  Dequeue Counter 0 */
specifier|volatile
name|uint32_t
name|fmqm_dc1
decl_stmt|;
comment|/**<  Dequeue Counter 1 */
specifier|volatile
name|uint32_t
name|fmqm_dc2
decl_stmt|;
comment|/**<  Dequeue Counter 2 */
specifier|volatile
name|uint32_t
name|fmqm_dc3
decl_stmt|;
comment|/**<  Dequeue Counter 3 */
specifier|volatile
name|uint32_t
name|fmqm_dfdc
decl_stmt|;
comment|/**<  Dequeue FQID from Default Counter */
specifier|volatile
name|uint32_t
name|fmqm_dfcc
decl_stmt|;
comment|/**<  Dequeue FQID from Context Counter */
specifier|volatile
name|uint32_t
name|fmqm_dffc
decl_stmt|;
comment|/**<  Dequeue FQID from FD Counter */
specifier|volatile
name|uint32_t
name|fmqm_dcc
decl_stmt|;
comment|/**<  Dequeue Confirm Counter */
specifier|volatile
name|uint32_t
name|Reserved1a
index|[
literal|7
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmqm_tapc
decl_stmt|;
comment|/**<  Tnum Aging Period Control */
specifier|volatile
name|uint32_t
name|fmqm_dmcvc
decl_stmt|;
comment|/**<  Dequeue MAC Command Valid Counter */
specifier|volatile
name|uint32_t
name|fmqm_difdcc
decl_stmt|;
comment|/**<  Dequeue Invalid FD Command Counter */
specifier|volatile
name|uint32_t
name|fmqm_da1v
decl_stmt|;
comment|/**<  Dequeue A1 Valid Counter */
specifier|volatile
name|uint32_t
name|Reserved1b
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmqm_dtc
decl_stmt|;
comment|/**<  0x0080 Debug Trap Counter */
specifier|volatile
name|uint32_t
name|fmqm_efddd
decl_stmt|;
comment|/**<  0x0084 Enqueue Frame Descriptor Dynamic Debug */
specifier|volatile
name|uint32_t
name|Reserved3
index|[
literal|2
index|]
decl_stmt|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fmqm_dtcfg1
decl_stmt|;
comment|/**<  0x0090 Debug Trap Configuration 1 Register */
specifier|volatile
name|uint32_t
name|fmqm_dtval1
decl_stmt|;
comment|/**<  Debug Trap Value 1 Register */
specifier|volatile
name|uint32_t
name|fmqm_dtm1
decl_stmt|;
comment|/**<  Debug Trap Mask 1 Register */
specifier|volatile
name|uint32_t
name|fmqm_dtc1
decl_stmt|;
comment|/**<  Debug Trap Counter 1 Register */
specifier|volatile
name|uint32_t
name|fmqm_dtcfg2
decl_stmt|;
comment|/**<  Debug Trap Configuration 2 Register */
specifier|volatile
name|uint32_t
name|fmqm_dtval2
decl_stmt|;
comment|/**<  Debug Trap Value 2 Register */
specifier|volatile
name|uint32_t
name|fmqm_dtm2
decl_stmt|;
comment|/**<  Debug Trap Mask 2 Register */
specifier|volatile
name|uint32_t
name|Reserved1
decl_stmt|;
block|}
name|_PackedType
name|dbgTraps
index|[
name|NUM_OF_DBG_TRAPS
index|]
struct|;
block|}
name|_PackedType
name|t_FmQmiRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fmdmsr
decl_stmt|;
comment|/**<    FM DMA status register 0x04 */
specifier|volatile
name|uint32_t
name|fmdmmr
decl_stmt|;
comment|/**<    FM DMA mode register 0x08 */
specifier|volatile
name|uint32_t
name|fmdmtr
decl_stmt|;
comment|/**<    FM DMA bus threshold register 0x0c */
specifier|volatile
name|uint32_t
name|fmdmhy
decl_stmt|;
comment|/**<    FM DMA bus hysteresis register 0x10 */
specifier|volatile
name|uint32_t
name|fmdmsetr
decl_stmt|;
comment|/**<    FM DMA SOS emergency Threshold Register 0x14 */
specifier|volatile
name|uint32_t
name|fmdmtah
decl_stmt|;
comment|/**<    FM DMA transfer bus address high register 0x18  */
specifier|volatile
name|uint32_t
name|fmdmtal
decl_stmt|;
comment|/**<    FM DMA transfer bus address low register 0x1C  */
specifier|volatile
name|uint32_t
name|fmdmtcid
decl_stmt|;
comment|/**<    FM DMA transfer bus communication ID register 0x20  */
specifier|volatile
name|uint32_t
name|fmdmra
decl_stmt|;
comment|/**<    FM DMA bus internal ram address register 0x24  */
specifier|volatile
name|uint32_t
name|fmdmrd
decl_stmt|;
comment|/**<    FM DMA bus internal ram data register 0x28  */
specifier|volatile
name|uint32_t
name|fmdmwcr
decl_stmt|;
comment|/**<    FM DMA CAM watchdog counter value 0x2C  */
specifier|volatile
name|uint32_t
name|fmdmebcr
decl_stmt|;
comment|/**<    FM DMA CAM base in MURAM register 0x30  */
specifier|volatile
name|uint32_t
name|fmdmccqdr
decl_stmt|;
comment|/**<    FM DMA CAM and CMD Queue Debug register 0x34  */
specifier|volatile
name|uint32_t
name|fmdmccqvr1
decl_stmt|;
comment|/**<    FM DMA CAM and CMD Queue Value register #1 0x38  */
specifier|volatile
name|uint32_t
name|fmdmccqvr2
decl_stmt|;
comment|/**<    FM DMA CAM and CMD Queue Value register #2 0x3C  */
specifier|volatile
name|uint32_t
name|fmdmcqvr3
decl_stmt|;
comment|/**<    FM DMA CMD Queue Value register #3 0x40  */
specifier|volatile
name|uint32_t
name|fmdmcqvr4
decl_stmt|;
comment|/**<    FM DMA CMD Queue Value register #4 0x44  */
specifier|volatile
name|uint32_t
name|fmdmcqvr5
decl_stmt|;
comment|/**<    FM DMA CMD Queue Value register #5 0x48  */
specifier|volatile
name|uint32_t
name|fmdmsefrc
decl_stmt|;
comment|/**<    FM DMA Semaphore Entry Full Reject Counter 0x50  */
specifier|volatile
name|uint32_t
name|fmdmsqfrc
decl_stmt|;
comment|/**<    FM DMA Semaphore Queue Full Reject Counter 0x54  */
specifier|volatile
name|uint32_t
name|fmdmssrc
decl_stmt|;
comment|/**<    FM DMA Semaphore SYNC Reject Counter 0x54  */
specifier|volatile
name|uint32_t
name|fmdmdcr
decl_stmt|;
comment|/**<    FM DMA Debug Counter */
specifier|volatile
name|uint32_t
name|fmdmemsr
decl_stmt|;
comment|/**<    FM DMA Emrgency Smoother Register */
specifier|volatile
name|uint32_t
name|reserved
decl_stmt|;
specifier|volatile
name|uint32_t
name|fmdmplr
index|[
name|FM_SIZE_OF_LIODN_TABLE
operator|/
literal|2
index|]
decl_stmt|;
comment|/**<    FM DMA PID-LIODN # register  */
block|}
name|_PackedType
name|t_FmDmaRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|iadd
decl_stmt|;
comment|/**<    FM IRAM instruction address register */
specifier|volatile
name|uint32_t
name|idata
decl_stmt|;
comment|/**<    FM IRAM instruction data register */
specifier|volatile
name|uint32_t
name|itcfg
decl_stmt|;
comment|/**<    FM IRAM timing config register */
specifier|volatile
name|uint32_t
name|iready
decl_stmt|;
comment|/**<    FM IRAM ready register */
specifier|volatile
name|uint8_t
name|res
index|[
literal|0x80000
operator|-
literal|0x10
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FMIramRegs
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
name|FM_DEBUG_STATUS_REGISTER_OFFSET
value|0x000d1084UL
end_define

begin_define
define|#
directive|define
name|FM_UCODE_DEBUG_INSTRUCTION
value|0x6ffff805UL
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       DMA definitions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|DMA_MODE_AID_OR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_SBER
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_BER
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_ECC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DMA_MODE_PRIVILEGE_PROT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_SECURE_PROT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DMA_MODE_EMERGENCY_READ
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_EMERGENCY_WRITE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_PORTID_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_TNUM_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_LIODN_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|DMA_HIGH_LIODN_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|DMA_LOW_LIODN_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_CMD_QUEUE_NOT_EMPTY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_BUS_ERR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_READ_ECC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_SYSTEM_WRITE_ECC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FM_WRITE_ECC
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_SYSTEM_DPEXT_ECC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FM_DPEXT_ECC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_SYSTEM_DPDAT_ECC
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FM_DPDAT_ECC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FM_SPDAT_ECC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FM_LIODN_BASE_MASK
value|0x00000FFF
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|DMA_MODE_CACHE_OR_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|DMA_MODE_BUS_PRI_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_MODE_AXI_DBG_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DMA_MODE_CEN_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|DMA_MODE_BUS_PROT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|DMA_MODE_DBG_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|DMA_MODE_EMERGENCY_LEVEL_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|DMA_MODE_AID_MODE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DMA_MODE_MAX_AXI_DBG_NUM_OF_BEATS
value|16
end_define

begin_define
define|#
directive|define
name|DMA_MODE_MAX_CAM_NUM_OF_ENTRIES
value|32
end_define

begin_define
define|#
directive|define
name|DMA_THRESH_COMMQ_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DMA_THRESH_READ_INT_BUF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_LIODN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_PORTID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_TNUM_SHIFT
value|16
end_define

begin_comment
comment|/* sizes */
end_comment

begin_define
define|#
directive|define
name|DMA_MAX_WATCHDOG
value|0xffffffff
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|DMA_CAM_SIZEOF_ENTRY
value|0x40
end_define

begin_define
define|#
directive|define
name|DMA_CAM_ALIGN
value|0x1000
end_define

begin_define
define|#
directive|define
name|DMA_CAM_UNITS
value|8
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       FPM defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|FPM_EV_MASK_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_STALL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_SINGLE_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_RELEASE_FM
value|0x00010000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_DOUBLE_ECC_EN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_STALL_EN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_SINGLE_ECC_EN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_EXTERNAL_HALT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_ECC_ERR_HALT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FPM_RAM_CTL_RAMS_ECC_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_CTL_IRAM_ECC_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_CTL_MURAM_ECC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_CTL_IRAM_ECC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_CTL_MURAM_TEST_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_CTL_IRAM_TEST_ECC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_CTL_RAMS_ECC_EN_SRC_SEL
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FPM_IRAM_ECC_ERR_EX_EN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FPM_MURAM_ECC_ERR_EX_EN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|FPM_REV1_MAJOR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|FPM_REV1_MINOR_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FPM_REV2_INTEG_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|FPM_REV2_ERR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|FPM_REV2_CFG_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FPM_TS_FRACTION_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|FPM_TS_CTL_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_PORT_FM_CTL1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FPM_PORT_FM_CTL2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FPM_PRC_REALSE_STALLED
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FPM_PS_STALLED
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FPM_PS_FM_CTL1_SEL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_PS_FM_CTL2_SEL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_PS_FM_CTL_SEL_MASK
value|(FPM_PS_FM_CTL1_SEL | FPM_PS_FM_CTL2_SEL)
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_FM_RESET
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_10G0_RESET
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G0_RESET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G1_RESET
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G2_RESET
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G3_RESET
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G4_RESET
value|0x02000000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|FPM_DISP_LIMIT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FPM_THR1_PRS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FPM_THR1_KG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_THR1_PLCR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FPM_THR1_BMI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_THR2_QMI_ENQ_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FPM_THR2_QMI_DEQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_THR2_FM_CTL1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_THR2_FM_CTL2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_CAT_ERR_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_DMA_ERR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_REV1_MAJOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FPM_REV1_MINOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_REV2_INTEG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_REV2_ERR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FPM_REV2_CFG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_TS_INT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_PORT_FM_CTL_PORTID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FPM_PS_FM_CTL_SEL_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|FPM_PRC_ORA_FM_CTL_SEL_SHIFT
value|16
end_define

begin_comment
comment|/* Interrupts defines */
end_comment

begin_define
define|#
directive|define
name|FPM_EVENT_FM_CTL_0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FPM_EVENT_FM_CTL
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|FPM_EVENT_FM_CTL_BRK
value|0x00000080
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|FPM_MAX_DISP_LIMIT
value|31
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       BMI defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|BMI_INIT_START
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_ERR_INTR_EN_PIPELINE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_ERR_INTR_EN_LIST_RAM_ECC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BMI_ERR_INTR_EN_STATISTICS_RAM_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BMI_ERR_INTR_EN_DISPATCH_RAM_ECC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_TASKS_MASK
value|0x3F000000
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_EXTRA_TASKS_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_DMAS_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_EXTRA_DMAS_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|BMI_FIFO_SIZE_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|BMI_EXTRA_FIFO_SIZE_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|BMI_CFG2_DMAS_MASK
value|0x0000003F
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|BMI_CFG2_TASKS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_CFG2_DMAS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMI_CFG1_FIFO_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_FIFO_SIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMI_EXTRA_FIFO_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_TASKS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BMI_EXTRA_NUM_OF_TASKS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_DMAS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BMI_EXTRA_NUM_OF_DMAS_SHIFT
value|0
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|BMI_FIFO_ALIGN
value|0x100
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       QMI defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|QMI_CFG_ENQ_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QMI_CFG_DEQ_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|QMI_CFG_EN_COUNTERS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QMI_CFG_SOFT_RESET
value|0x01000000
end_define

begin_define
define|#
directive|define
name|QMI_CFG_DEQ_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|QMI_CFG_ENQ_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|QMI_ERR_INTR_EN_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QMI_ERR_INTR_EN_DEQ_FROM_DEF
value|0x40000000
end_define

begin_define
define|#
directive|define
name|QMI_INTR_EN_SINGLE_ECC
value|0x80000000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|QMI_CFG_ENQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|QMI_TAPC_TAP
value|22
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       IRAM defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|IRAM_IADD_AIE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IRAM_READY
value|0x80000000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|f_Isr
function_decl|)
parameter_list|(
name|t_Handle
name|h_Arg
parameter_list|,
name|uint32_t
name|event
parameter_list|)
function_decl|;
name|t_Handle
name|h_SrcHandle
decl_stmt|;
block|}
name|t_FmanCtrlIntrSrc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/*   uint8_t                     numOfPartitions; */
name|bool
name|resetOnInit
decl_stmt|;
ifdef|#
directive|ifdef
name|FM_PARTITION_ARRAY
name|uint16_t
name|liodnBasePerPort
index|[
name|FM_SIZE_OF_LIODN_TABLE
index|]
decl_stmt|;
endif|#
directive|endif
name|bool
name|enCounters
decl_stmt|;
name|t_FmThresholds
name|thresholds
decl_stmt|;
name|e_FmDmaCacheOverride
name|dmaCacheOverride
decl_stmt|;
name|e_FmDmaAidMode
name|dmaAidMode
decl_stmt|;
name|bool
name|dmaAidOverride
decl_stmt|;
name|uint8_t
name|dmaAxiDbgNumOfBeats
decl_stmt|;
name|uint8_t
name|dmaCamNumOfEntries
decl_stmt|;
name|uint32_t
name|dmaWatchdog
decl_stmt|;
name|t_FmDmaThresholds
name|dmaCommQThresholds
decl_stmt|;
name|t_FmDmaThresholds
name|dmaWriteBufThresholds
decl_stmt|;
name|t_FmDmaThresholds
name|dmaReadBufThresholds
decl_stmt|;
name|uint32_t
name|dmaSosEmergency
decl_stmt|;
name|e_FmDmaDbgCntMode
name|dmaDbgCntMode
decl_stmt|;
name|bool
name|dmaStopOnBusError
decl_stmt|;
name|bool
name|dmaEnEmergency
decl_stmt|;
name|t_FmDmaEmergency
name|dmaEmergency
decl_stmt|;
name|bool
name|dmaEnEmergencySmoother
decl_stmt|;
name|uint32_t
name|dmaEmergencySwitchCounter
decl_stmt|;
name|bool
name|haltOnExternalActivation
decl_stmt|;
name|bool
name|haltOnUnrecoverableEccError
decl_stmt|;
name|e_FmCatastrophicErr
name|catastrophicErr
decl_stmt|;
name|e_FmDmaErr
name|dmaErr
decl_stmt|;
name|bool
name|enMuramTestMode
decl_stmt|;
name|bool
name|enIramTestMode
decl_stmt|;
name|bool
name|externalEccRamsEnable
decl_stmt|;
name|uint16_t
name|tnumAgingPeriod
decl_stmt|;
name|t_FmPcdFirmwareParams
name|firmware
decl_stmt|;
name|bool
name|fwVerify
decl_stmt|;
block|}
name|t_FmDriverParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmanCtrlIsr
function_decl|)
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint32_t
name|event
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/***************************/
comment|/* Master/Guest parameters */
comment|/***************************/
name|uint8_t
name|fmId
decl_stmt|;
name|e_FmPortType
name|portsTypes
index|[
name|FM_MAX_NUM_OF_HW_PORT_IDS
index|]
decl_stmt|;
name|uint16_t
name|fmClkFreq
decl_stmt|;
comment|/**************************/
comment|/* Master Only parameters */
comment|/**************************/
name|bool
name|enabledTimeStamp
decl_stmt|;
name|uint8_t
name|count1MicroBit
decl_stmt|;
name|uint8_t
name|totalNumOfTasks
decl_stmt|;
name|uint32_t
name|totalFifoSize
decl_stmt|;
name|uint8_t
name|maxNumOfOpenDmas
decl_stmt|;
name|uint8_t
name|accumulatedNumOfTasks
decl_stmt|;
name|uint32_t
name|accumulatedFifoSize
decl_stmt|;
name|uint8_t
name|accumulatedNumOfOpenDmas
decl_stmt|;
ifdef|#
directive|ifdef
name|FM_QMI_DEQ_OPTIONS_SUPPORT
name|uint8_t
name|accumulatedNumOfDeqTnums
decl_stmt|;
endif|#
directive|endif
comment|/* FM_QMI_DEQ_OPTIONS_SUPPORT */
ifdef|#
directive|ifdef
name|FM_LOW_END_RESTRICTION
name|bool
name|lowEndRestriction
decl_stmt|;
endif|#
directive|endif
comment|/* FM_LOW_END_RESTRICTION */
name|uint32_t
name|exceptions
decl_stmt|;
name|int
name|irq
decl_stmt|;
name|int
name|errIrq
decl_stmt|;
name|bool
name|ramsEccEnable
decl_stmt|;
name|bool
name|explicitEnable
decl_stmt|;
name|bool
name|internalCall
decl_stmt|;
name|uint8_t
name|ramsEccOwners
decl_stmt|;
name|uint32_t
name|extraFifoPoolSize
decl_stmt|;
name|uint8_t
name|extraTasksPoolSize
decl_stmt|;
name|uint8_t
name|extraOpenDmasPoolSize
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|FM_MAX_NUM_OF_10G_MACS
argument_list|)
operator|&&
operator|(
name|FM_MAX_NUM_OF_10G_MACS
operator|)
name|uint16_t
name|macMaxFrameLengths10G
index|[
name|FM_MAX_NUM_OF_10G_MACS
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* defined(FM_MAX_NUM_OF_10G_MACS)&& (FM_MAX_NUM_OF_10G_MACS) */
name|uint16_t
name|macMaxFrameLengths1G
index|[
name|FM_MAX_NUM_OF_1G_MACS
index|]
decl_stmt|;
block|}
name|t_FmStateStruct
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/***************************/
comment|/* Master/Guest parameters */
comment|/***************************/
comment|/* locals for recovery */
name|uintptr_t
name|baseAddr
decl_stmt|;
comment|/* un-needed for recovery */
name|t_Handle
name|h_Pcd
decl_stmt|;
name|char
name|fmModuleName
index|[
name|MODULE_NAME_SIZE
index|]
decl_stmt|;
name|char
name|fmIpcHandlerModuleName
index|[
name|FM_MAX_NUM_OF_GUESTS
index|]
index|[
name|MODULE_NAME_SIZE
index|]
decl_stmt|;
name|t_Handle
name|h_IpcSessions
index|[
name|FM_MAX_NUM_OF_GUESTS
index|]
decl_stmt|;
name|t_FmIntrSrc
name|intrMng
index|[
name|e_FM_EV_DUMMY_LAST
index|]
decl_stmt|;
comment|/* FM exceptions user callback */
name|uint8_t
name|guestId
decl_stmt|;
comment|/**************************/
comment|/* Master Only parameters */
comment|/**************************/
comment|/* locals for recovery */
name|t_FmFpmRegs
modifier|*
name|p_FmFpmRegs
decl_stmt|;
name|t_FmBmiRegs
modifier|*
name|p_FmBmiRegs
decl_stmt|;
name|t_FmQmiRegs
modifier|*
name|p_FmQmiRegs
decl_stmt|;
name|t_FmDmaRegs
modifier|*
name|p_FmDmaRegs
decl_stmt|;
name|t_FmExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
name|t_FmBusErrorCallback
modifier|*
name|f_BusError
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
comment|/* Application handle */
name|t_Handle
name|h_Spinlock
decl_stmt|;
name|bool
name|recoveryMode
decl_stmt|;
name|t_FmStateStruct
modifier|*
name|p_FmStateStruct
decl_stmt|;
comment|/* un-needed for recovery */
name|t_FmDriverParam
modifier|*
name|p_FmDriverParam
decl_stmt|;
name|t_Handle
name|h_FmMuram
decl_stmt|;
name|uint64_t
name|fmMuramPhysBaseAddr
decl_stmt|;
name|bool
name|independentMode
decl_stmt|;
name|bool
name|hcPortInitialized
decl_stmt|;
name|uintptr_t
name|camBaseAddr
decl_stmt|;
comment|/* save for freeing */
name|uintptr_t
name|resAddr
decl_stmt|;
name|uintptr_t
name|fifoBaseAddr
decl_stmt|;
comment|/* save for freeing */
name|t_FmanCtrlIntrSrc
name|fmanCtrlIntr
index|[
name|FM_NUM_OF_FMAN_CTRL_EVENT_REGS
index|]
decl_stmt|;
comment|/* FM exceptions user callback */
name|bool
name|usedEventRegs
index|[
name|FM_NUM_OF_FMAN_CTRL_EVENT_REGS
index|]
decl_stmt|;
block|}
name|t_Fm
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_H */
end_comment

end_unit

