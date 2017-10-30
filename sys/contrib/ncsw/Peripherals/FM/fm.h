begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|"fsl_fman.h"
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
name|FM_EX_BMI_STORAGE_PROFILE_ECC
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
name|FM_EX_MURAM_ECC
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
name|FM_EX_DMA_SINGLE_PORT_ECC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DMA_EMSR_EMSTR_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|DMA_THRESH_COMMQ_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|DMA_THRESH_READ_INT_BUF_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|DMA_THRESH_WRITE_INT_BUF_MASK
value|0x0000007F
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
define|\
value|switch (exception){                                         \     case e_FM_EX_DMA_BUS_ERROR:                             \         bitMask = FM_EX_DMA_BUS_ERROR; break;               \     case e_FM_EX_DMA_SINGLE_PORT_ECC:                       \         bitMask = FM_EX_DMA_SINGLE_PORT_ECC; break;         \     case e_FM_EX_DMA_READ_ECC:                              \         bitMask = FM_EX_DMA_READ_ECC; break;                \     case e_FM_EX_DMA_SYSTEM_WRITE_ECC:                      \         bitMask = FM_EX_DMA_SYSTEM_WRITE_ECC; break;        \     case e_FM_EX_DMA_FM_WRITE_ECC:                          \         bitMask = FM_EX_DMA_FM_WRITE_ECC; break;            \     case e_FM_EX_FPM_STALL_ON_TASKS:                        \         bitMask = FM_EX_FPM_STALL_ON_TASKS; break;          \     case e_FM_EX_FPM_SINGLE_ECC:                            \         bitMask = FM_EX_FPM_SINGLE_ECC; break;              \     case e_FM_EX_FPM_DOUBLE_ECC:                            \         bitMask = FM_EX_FPM_DOUBLE_ECC; break;              \     case e_FM_EX_QMI_SINGLE_ECC:                            \         bitMask = FM_EX_QMI_SINGLE_ECC; break;              \     case e_FM_EX_QMI_DOUBLE_ECC:                            \         bitMask = FM_EX_QMI_DOUBLE_ECC; break;              \     case e_FM_EX_QMI_DEQ_FROM_UNKNOWN_PORTID:               \         bitMask = FM_EX_QMI_DEQ_FROM_UNKNOWN_PORTID; break; \     case e_FM_EX_BMI_LIST_RAM_ECC:                          \         bitMask = FM_EX_BMI_LIST_RAM_ECC; break;            \     case e_FM_EX_BMI_STORAGE_PROFILE_ECC:                   \         bitMask = FM_EX_BMI_STORAGE_PROFILE_ECC; break;     \     case e_FM_EX_BMI_STATISTICS_RAM_ECC:                    \         bitMask = FM_EX_BMI_STATISTICS_RAM_ECC; break;      \     case e_FM_EX_BMI_DISPATCH_RAM_ECC:                      \         bitMask = FM_EX_BMI_DISPATCH_RAM_ECC; break;        \     case e_FM_EX_IRAM_ECC:                                  \         bitMask = FM_EX_IRAM_ECC; break;                    \     case e_FM_EX_MURAM_ECC:                                 \         bitMask = FM_EX_MURAM_ECC; break;                   \     default: bitMask = 0;break;                             \ }
end_define

begin_define
define|#
directive|define
name|GET_FM_MODULE_EVENT
parameter_list|(
name|_mod
parameter_list|,
name|_id
parameter_list|,
name|_intrType
parameter_list|,
name|_event
parameter_list|)
define|\
value|switch (_mod) {                                                                                 \         case e_FM_MOD_PRS:                                                                          \             if (_id) _event = e_FM_EV_DUMMY_LAST;                                                   \             else _event = (_intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_PRS : e_FM_EV_PRS;        \             break;                                                                                  \         case e_FM_MOD_KG:                                                                           \             if (_id) _event = e_FM_EV_DUMMY_LAST;                                                   \             else _event = (_intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_KG : e_FM_EV_DUMMY_LAST;  \             break;                                                                                  \         case e_FM_MOD_PLCR:                                                                         \             if (_id) _event = e_FM_EV_DUMMY_LAST;                                                   \             else _event = (_intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_PLCR : e_FM_EV_PLCR;      \             break;                                                                                  \         case e_FM_MOD_TMR:                                                                          \             if (_id) _event = e_FM_EV_DUMMY_LAST;                                                   \             else _event = (_intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_DUMMY_LAST : e_FM_EV_TMR;     \             break;                                                                                  \         case e_FM_MOD_10G_MAC:                                                                      \             if (_id>= FM_MAX_NUM_OF_10G_MACS) _event = e_FM_EV_DUMMY_LAST;                         \             else _event = (_intrType == e_FM_INTR_TYPE_ERR) ? (e_FM_EV_ERR_10G_MAC0 + _id) : (e_FM_EV_10G_MAC0 + _id); \             break;                                                                                  \         case e_FM_MOD_1G_MAC:                                                                       \             if (_id>= FM_MAX_NUM_OF_1G_MACS) _event = e_FM_EV_DUMMY_LAST;                          \             else _event = (_intrType == e_FM_INTR_TYPE_ERR) ? (e_FM_EV_ERR_1G_MAC0 + _id) : (e_FM_EV_1G_MAC0 + _id); \             break;                                                                                  \         case e_FM_MOD_MACSEC:                                                                       \             switch (_id){                                                                           \                  case (0): _event = (_intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_MACSEC_MAC0:e_FM_EV_MACSEC_MAC0; \                  break;                                                                             \                  }                                                                                  \             break;                                                                                  \         case e_FM_MOD_FMAN_CTRL:                                                                    \             if (_intrType == e_FM_INTR_TYPE_ERR) _event = e_FM_EV_DUMMY_LAST;                       \             else _event = (e_FM_EV_FMAN_CTRL_0 + _id);                                              \             break;                                                                                  \         default: _event = e_FM_EV_DUMMY_LAST;                                                       \         break;                                                                                      \     }
end_define

begin_define
define|#
directive|define
name|FMAN_CACHE_OVERRIDE_TRANS
parameter_list|(
name|fsl_cache_override
parameter_list|,
name|_cache_override
parameter_list|)
define|\
value|switch (_cache_override){ \         case  e_FM_DMA_NO_CACHE_OR:                    \             fsl_cache_override =  E_FMAN_DMA_NO_CACHE_OR; break;    \         case  e_FM_DMA_NO_STASH_DATA:                    \             fsl_cache_override =  E_FMAN_DMA_NO_STASH_DATA; break;        \         case  e_FM_DMA_MAY_STASH_DATA:                    \             fsl_cache_override =  E_FMAN_DMA_MAY_STASH_DATA; break;    \         case  e_FM_DMA_STASH_DATA:                        \             fsl_cache_override =  E_FMAN_DMA_STASH_DATA; break;        \         default: \             fsl_cache_override =  E_FMAN_DMA_NO_CACHE_OR; break;    \     }
end_define

begin_define
define|#
directive|define
name|FMAN_AID_MODE_TRANS
parameter_list|(
name|fsl_aid_mode
parameter_list|,
name|_aid_mode
parameter_list|)
define|\
value|switch (_aid_mode){ \         case  e_FM_DMA_AID_OUT_PORT_ID:                    \             fsl_aid_mode =  E_FMAN_DMA_AID_OUT_PORT_ID; break;    \         case  e_FM_DMA_AID_OUT_TNUM:                    \             fsl_aid_mode =  E_FMAN_DMA_AID_OUT_TNUM; break;        \         default: \             fsl_aid_mode =  E_FMAN_DMA_AID_OUT_PORT_ID; break;    \     }
end_define

begin_define
define|#
directive|define
name|FMAN_DMA_DBG_CNT_TRANS
parameter_list|(
name|fsl_dma_dbg_cnt
parameter_list|,
name|_dma_dbg_cnt
parameter_list|)
define|\
value|switch (_dma_dbg_cnt){ \         case  e_FM_DMA_DBG_NO_CNT:                    \             fsl_dma_dbg_cnt =  E_FMAN_DMA_DBG_NO_CNT; break;    \         case  e_FM_DMA_DBG_CNT_DONE:                    \             fsl_dma_dbg_cnt =  E_FMAN_DMA_DBG_CNT_DONE; break;        \         case  e_FM_DMA_DBG_CNT_COMM_Q_EM:                    \             fsl_dma_dbg_cnt =  E_FMAN_DMA_DBG_CNT_COMM_Q_EM; break;    \         case  e_FM_DMA_DBG_CNT_INT_READ_EM:                        \             fsl_dma_dbg_cnt =  E_FMAN_DMA_DBG_CNT_INT_READ_EM; break;        \         case  e_FM_DMA_DBG_CNT_INT_WRITE_EM:                        \             fsl_dma_dbg_cnt = E_FMAN_DMA_DBG_CNT_INT_WRITE_EM ; break;        \         case  e_FM_DMA_DBG_CNT_FPM_WAIT:                        \             fsl_dma_dbg_cnt = E_FMAN_DMA_DBG_CNT_FPM_WAIT ; break;        \         case  e_FM_DMA_DBG_CNT_SIGLE_BIT_ECC:                        \             fsl_dma_dbg_cnt = E_FMAN_DMA_DBG_CNT_SIGLE_BIT_ECC ; break;        \         case  e_FM_DMA_DBG_CNT_RAW_WAR_PROT:                        \             fsl_dma_dbg_cnt = E_FMAN_DMA_DBG_CNT_RAW_WAR_PROT ; break;        \         default: \             fsl_dma_dbg_cnt =  E_FMAN_DMA_DBG_NO_CNT; break;    \     }
end_define

begin_define
define|#
directive|define
name|FMAN_DMA_EMER_TRANS
parameter_list|(
name|fsl_dma_emer
parameter_list|,
name|_dma_emer
parameter_list|)
define|\
value|switch (_dma_emer){ \         case  e_FM_DMA_EM_EBS:                    \             fsl_dma_emer =  E_FMAN_DMA_EM_EBS; break;    \         case  e_FM_DMA_EM_SOS:                    \             fsl_dma_emer =  E_FMAN_DMA_EM_SOS; break;        \         default: \             fsl_dma_emer =  E_FMAN_DMA_EM_EBS; break;    \     }
end_define

begin_define
define|#
directive|define
name|FMAN_DMA_ERR_TRANS
parameter_list|(
name|fsl_dma_err
parameter_list|,
name|_dma_err
parameter_list|)
define|\
value|switch (_dma_err){ \         case  e_FM_DMA_ERR_CATASTROPHIC:                    \             fsl_dma_err =  E_FMAN_DMA_ERR_CATASTROPHIC; break;    \         case  e_FM_DMA_ERR_REPORT:                    \             fsl_dma_err =  E_FMAN_DMA_ERR_REPORT; break;        \         default: \             fsl_dma_err =  E_FMAN_DMA_ERR_CATASTROPHIC; break;    \     }
end_define

begin_define
define|#
directive|define
name|FMAN_CATASTROPHIC_ERR_TRANS
parameter_list|(
name|fsl_catastrophic_err
parameter_list|,
name|_catastrophic_err
parameter_list|)
define|\
value|switch (_catastrophic_err){ \         case  e_FM_CATASTROPHIC_ERR_STALL_PORT:                    \             fsl_catastrophic_err =  E_FMAN_CATAST_ERR_STALL_PORT; break;    \         case  e_FM_CATASTROPHIC_ERR_STALL_TASK:                    \             fsl_catastrophic_err =  E_FMAN_CATAST_ERR_STALL_TASK; break;        \         default: \             fsl_catastrophic_err =  E_FMAN_CATAST_ERR_STALL_PORT; break;    \     }
end_define

begin_define
define|#
directive|define
name|FMAN_COUNTERS_TRANS
parameter_list|(
name|fsl_counters
parameter_list|,
name|_counters
parameter_list|)
define|\
value|switch (_counters){ \         case  e_FM_COUNTERS_ENQ_TOTAL_FRAME:                    \             fsl_counters =  E_FMAN_COUNTERS_ENQ_TOTAL_FRAME; break;    \         case  e_FM_COUNTERS_DEQ_TOTAL_FRAME:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_TOTAL_FRAME; break;        \         case  e_FM_COUNTERS_DEQ_0:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_0; break;    \         case  e_FM_COUNTERS_DEQ_1:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_1; break;        \         case  e_FM_COUNTERS_DEQ_2:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_2; break;    \         case  e_FM_COUNTERS_DEQ_3:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_3; break;        \         case  e_FM_COUNTERS_DEQ_FROM_DEFAULT:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_FROM_DEFAULT; break;    \         case  e_FM_COUNTERS_DEQ_FROM_CONTEXT:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_FROM_CONTEXT; break;        \         case  e_FM_COUNTERS_DEQ_FROM_FD:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_FROM_FD; break;    \         case  e_FM_COUNTERS_DEQ_CONFIRM:                    \             fsl_counters =  E_FMAN_COUNTERS_DEQ_CONFIRM; break;        \         default: \             fsl_counters =  E_FMAN_COUNTERS_ENQ_TOTAL_FRAME; break;    \     }
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
value|(FM_EX_DMA_BUS_ERROR            |\                                             FM_EX_DMA_READ_ECC              |\                                             FM_EX_DMA_SYSTEM_WRITE_ECC      |\                                             FM_EX_DMA_FM_WRITE_ECC          |\                                             FM_EX_FPM_STALL_ON_TASKS        |\                                             FM_EX_FPM_SINGLE_ECC            |\                                             FM_EX_FPM_DOUBLE_ECC            |\                                             FM_EX_QMI_DEQ_FROM_UNKNOWN_PORTID|\                                             FM_EX_BMI_LIST_RAM_ECC          |\                                             FM_EX_BMI_STORAGE_PROFILE_ECC   |\                                             FM_EX_BMI_STATISTICS_RAM_ECC    |\                                             FM_EX_IRAM_ECC                  |\                                             FM_EX_MURAM_ECC                 |\                                             FM_EX_BMI_DISPATCH_RAM_ECC      |\                                             FM_EX_QMI_DOUBLE_ECC            |\                                             FM_EX_QMI_SINGLE_ECC)
end_define

begin_define
define|#
directive|define
name|DEFAULT_eccEnable
value|FALSE
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
name|DEFAULT_resetOnInitOverrideCallback
value|NULL
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

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|<
literal|11
operator|)
end_if

begin_define
define|#
directive|define
name|DEFAULT_totalFifoSize
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|(((major == 2) || (major == 5)) ?           \      (100*KILOBYTE) : ((major == 4) ?           \      (49*KILOBYTE) : (122*KILOBYTE)))
end_define

begin_define
define|#
directive|define
name|DEFAULT_totalNumOfTasks
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|BMI_MAX_NUM_OF_TASKS
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
name|DEFAULT_cacheOverride
value|e_FM_DMA_NO_CACHE_OR
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
name|DEFAULT_dmaDbgCntMode
value|e_FM_DMA_DBG_NO_CNT
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaEnEmergency
value|FALSE
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
name|DEFAULT_dmaWatchdog
value|0
end_define

begin_comment
comment|/* disabled */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_dmaEnEmergencySmoother
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaEmergencySwitchCounter
value|0
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* (DPAA_VERSION< 11) */
end_comment

begin_comment
comment|/* Defaults are registers' reset values */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_totalFifoSize
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|(((major == 6)&& ((minor == 1) || (minor == 4))) ?	\ 	(156*KILOBYTE) : (295*KILOBYTE))
end_define

begin_comment
comment|/* According to the default value of FMBM_CFG2[TNTSKS] */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_totalNumOfTasks
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|(((major == 6)&& ((minor == 1) || (minor == 4))) ? 59 : 124)
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaCommQLow
value|0x2A
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaCommQHigh
value|0x3F
end_define

begin_define
define|#
directive|define
name|DEFAULT_cacheOverride
value|e_FM_DMA_NO_CACHE_OR
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaCamNumOfEntries
value|64
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
name|DEFAULT_dmaEnEmergency
value|FALSE
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
name|DEFAULT_dmaWatchdog
value|0
end_define

begin_comment
comment|/* disabled */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_dmaEnEmergencySmoother
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_dmaEmergencySwitchCounter
value|0
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION< 11) */
end_comment

begin_define
define|#
directive|define
name|FM_TIMESTAMP_1_USEC_BIT
value|8
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   Defines used for enabling/disabling FM interrupts  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ERR_INTR_EN_DMA
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_FPM
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_BMI
value|0x00800000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_QMI
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_PRS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_KG
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_PLCR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_MURAM
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_IRAM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_10G_MAC0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_10G_MAC1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC0
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC1
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC2
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC3
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC4
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC5
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC6
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_MACSEC_MAC0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INTR_EN_QMI
value|0x40000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_PRS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_WAKEUP
value|0x10000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_PLCR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC0
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC1
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC3
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC4
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC6
value|0x00000008
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC7
value|0x00000002
end_define

begin_define
define|#
directive|define
name|INTR_EN_10G_MAC0
value|0x00200000
end_define

begin_define
define|#
directive|define
name|INTR_EN_10G_MAC1
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INTR_EN_REV0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|INTR_EN_REV1
value|0x00004000
end_define

begin_define
define|#
directive|define
name|INTR_EN_REV2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|INTR_EN_REV3
value|0x00001000
end_define

begin_define
define|#
directive|define
name|INTR_EN_BRK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTR_EN_TMR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_MACSEC_MAC0
value|0x00000001
end_define

begin_comment
comment|/* @} */
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

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|iadd
decl_stmt|;
comment|/**< FM IRAM instruction address register */
specifier|volatile
name|uint32_t
name|idata
decl_stmt|;
comment|/**< FM IRAM instruction data register */
specifier|volatile
name|uint32_t
name|itcfg
decl_stmt|;
comment|/**< FM IRAM timing config register */
specifier|volatile
name|uint32_t
name|iready
decl_stmt|;
comment|/**< FM IRAM ready register */
specifier|volatile
name|uint32_t
name|res
index|[
literal|0x1FFFC
index|]
decl_stmt|;
block|}
name|t_FMIramRegs
typedef|;
end_typedef

begin_comment
comment|/* Trace buffer registers -    each FM Controller has its own trace buffer residing at FM_MM_TRB(fmCtrlIndex) offset */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmTrbRegs
block|{
specifier|volatile
name|uint32_t
name|tcrh
decl_stmt|;
specifier|volatile
name|uint32_t
name|tcrl
decl_stmt|;
specifier|volatile
name|uint32_t
name|tesr
decl_stmt|;
specifier|volatile
name|uint32_t
name|tecr0h
decl_stmt|;
specifier|volatile
name|uint32_t
name|tecr0l
decl_stmt|;
specifier|volatile
name|uint32_t
name|terf0h
decl_stmt|;
specifier|volatile
name|uint32_t
name|terf0l
decl_stmt|;
specifier|volatile
name|uint32_t
name|tecr1h
decl_stmt|;
specifier|volatile
name|uint32_t
name|tecr1l
decl_stmt|;
specifier|volatile
name|uint32_t
name|terf1h
decl_stmt|;
specifier|volatile
name|uint32_t
name|terf1l
decl_stmt|;
specifier|volatile
name|uint32_t
name|tpcch
decl_stmt|;
specifier|volatile
name|uint32_t
name|tpccl
decl_stmt|;
specifier|volatile
name|uint32_t
name|tpc1h
decl_stmt|;
specifier|volatile
name|uint32_t
name|tpc1l
decl_stmt|;
specifier|volatile
name|uint32_t
name|tpc2h
decl_stmt|;
specifier|volatile
name|uint32_t
name|tpc2l
decl_stmt|;
specifier|volatile
name|uint32_t
name|twdimr
decl_stmt|;
specifier|volatile
name|uint32_t
name|twicvr
decl_stmt|;
specifier|volatile
name|uint32_t
name|tar
decl_stmt|;
specifier|volatile
name|uint32_t
name|tdr
decl_stmt|;
specifier|volatile
name|uint32_t
name|tsnum1
decl_stmt|;
specifier|volatile
name|uint32_t
name|tsnum2
decl_stmt|;
specifier|volatile
name|uint32_t
name|tsnum3
decl_stmt|;
specifier|volatile
name|uint32_t
name|tsnum4
decl_stmt|;
block|}
name|t_FmTrbRegs
typedef|;
end_typedef

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
name|FM_FW_DEBUG_INSTRUCTION
value|0x6ffff805UL
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
name|FPM_BRKC_RDBG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|FPM_BRKC_SLP
value|0x00000800
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
name|BMI_ERR_INTR_EN_STORAGE_PROFILE_ECC
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       TRB defines */
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
name|TRB_TCRH_RESET
value|0x04000000
end_define

begin_define
define|#
directive|define
name|TRB_TCRH_ENABLE_COUNTERS
value|0x84008000
end_define

begin_define
define|#
directive|define
name|TRB_TCRH_DISABLE_COUNTERS
value|0x8400C000
end_define

begin_define
define|#
directive|define
name|TRB_TCRL_RESET
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TRB_TCRL_UTIL
value|0x00000460
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
name|uint16_t
name|fmMacClkFreq
decl_stmt|;
name|t_FmRevisionInfo
name|revInfo
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
name|uint8_t
name|accumulatedNumOfDeqTnums
decl_stmt|;
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
name|uintptr_t
name|irq
decl_stmt|;
name|uintptr_t
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
name|portMaxFrameLengths10G
index|[
name|FM_MAX_NUM_OF_10G_MACS
index|]
decl_stmt|;
name|uint16_t
name|macMaxFrameLengths10G
index|[
name|FM_MAX_NUM_OF_10G_MACS
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* defined(FM_MAX_NUM_OF_10G_MACS)&& ... */
name|uint16_t
name|portMaxFrameLengths1G
index|[
name|FM_MAX_NUM_OF_1G_MACS
index|]
decl_stmt|;
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

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|t_FmMapParam
block|{
name|uint16_t
name|profilesBase
decl_stmt|;
name|uint16_t
name|numOfProfiles
decl_stmt|;
name|t_Handle
name|h_FmPort
decl_stmt|;
block|}
name|t_FmMapParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmAllocMng
block|{
name|bool
name|allocated
decl_stmt|;
name|uint8_t
name|ownerId
decl_stmt|;
comment|/* guestId for KG in multi-partition only,                                 portId for PLCR in any environment */
block|}
name|t_FmAllocMng
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdSpEntry
block|{
name|bool
name|valid
decl_stmt|;
name|t_FmAllocMng
name|profilesMng
decl_stmt|;
block|}
name|t_FmPcdSpEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmSp
block|{
name|void
modifier|*
name|p_FmPcdStoragePrflRegs
decl_stmt|;
name|t_FmPcdSpEntry
name|profiles
index|[
name|FM_VSP_MAX_NUM_OF_ENTRIES
index|]
decl_stmt|;
name|t_FmMapParam
name|portsMapping
index|[
name|FM_MAX_NUM_OF_PORTS
index|]
decl_stmt|;
block|}
name|t_FmSp
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_Fm
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
name|struct
name|fman_fpm_regs
modifier|*
name|p_FmFpmRegs
decl_stmt|;
name|struct
name|fman_bmi_regs
modifier|*
name|p_FmBmiRegs
decl_stmt|;
name|struct
name|fman_qmi_regs
modifier|*
name|p_FmQmiRegs
decl_stmt|;
name|struct
name|fman_dma_regs
modifier|*
name|p_FmDmaRegs
decl_stmt|;
name|struct
name|fman_regs
modifier|*
name|p_FmRegs
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
name|uint16_t
name|tnumAgingPeriod
decl_stmt|;
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmSp
modifier|*
name|p_FmSp
decl_stmt|;
name|uint8_t
name|partNumOfVSPs
decl_stmt|;
name|uint8_t
name|partVSPBase
decl_stmt|;
name|uintptr_t
name|vspBaseAddr
decl_stmt|;
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|bool
name|portsPreFetchConfigured
index|[
name|FM_MAX_NUM_OF_HW_PORT_IDS
index|]
decl_stmt|;
comment|/* Prefetch configration per Tx-port */
name|bool
name|portsPreFetchValue
index|[
name|FM_MAX_NUM_OF_HW_PORT_IDS
index|]
decl_stmt|;
comment|/* Prefetch configration per Tx-port */
comment|/* un-needed for recovery */
name|struct
name|fman_cfg
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
name|t_FmFirmwareParams
name|firmware
decl_stmt|;
name|bool
name|fwVerify
decl_stmt|;
name|bool
name|resetOnInit
decl_stmt|;
name|t_FmResetOnInitOverrideCallback
modifier|*
name|f_ResetOnInitOverride
decl_stmt|;
name|uint32_t
name|userSetExceptions
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

