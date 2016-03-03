begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   **************************************************************************/
end_comment

begin_comment
comment|/**   @File          dpaa_integration_ext.h   @Description   P2041 FM external definitions and structures. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DPAA_INTEGRATION_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__DPAA_INTEGRATION_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DPAA SW Portals Enumeration. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_DPAA_SWPORTAL0
init|=
literal|0
block|,
name|e_DPAA_SWPORTAL1
block|,
name|e_DPAA_SWPORTAL2
block|,
name|e_DPAA_SWPORTAL3
block|,
name|e_DPAA_SWPORTAL4
block|,
name|e_DPAA_SWPORTAL5
block|,
name|e_DPAA_SWPORTAL6
block|,
name|e_DPAA_SWPORTAL7
block|,
name|e_DPAA_SWPORTAL8
block|,
name|e_DPAA_SWPORTAL9
block|,
name|e_DPAA_SWPORTAL_DUMMY_LAST
block|}
name|e_DpaaSwPortal
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   DPAA Direct Connect Portals Enumeration. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_DPAA_DCPORTAL0
init|=
literal|0
block|,
name|e_DPAA_DCPORTAL1
block|,
name|e_DPAA_DCPORTAL2
block|,
name|e_DPAA_DCPORTAL3
block|,
name|e_DPAA_DCPORTAL4
block|,
name|e_DPAA_DCPORTAL_DUMMY_LAST
block|}
name|e_DpaaDcPortal
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DPAA_MAX_NUM_OF_SW_PORTALS
value|e_DPAA_SWPORTAL_DUMMY_LAST
end_define

begin_define
define|#
directive|define
name|DPAA_MAX_NUM_OF_DC_PORTALS
value|e_DPAA_DCPORTAL_DUMMY_LAST
end_define

begin_comment
comment|/*****************************************************************************  QMan INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|QM_MAX_NUM_OF_POOL_CHANNELS
value|15
end_define

begin_comment
comment|/**< Total number of channels, dedicated and pool */
end_comment

begin_define
define|#
directive|define
name|QM_MAX_NUM_OF_WQ
value|8
end_define

begin_comment
comment|/**< Number of work queues per channel */
end_comment

begin_define
define|#
directive|define
name|QM_MAX_NUM_OF_CGS
value|256
end_define

begin_comment
comment|/**< Congestion groups number */
end_comment

begin_define
define|#
directive|define
name|QM_MAX_NUM_OF_FQIDS
value|(16 * MEGABYTE)
end_define

begin_comment
comment|/**< FQIDs range - 24 bits */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Work Queue Channel assignments in QMan. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_QM_FQ_CHANNEL_SWPORTAL0
init|=
literal|0
block|,
comment|/**< Dedicated channels serviced by software portals 0 to 9 */
name|e_QM_FQ_CHANNEL_SWPORTAL1
block|,
name|e_QM_FQ_CHANNEL_SWPORTAL2
block|,
name|e_QM_FQ_CHANNEL_SWPORTAL3
block|,
name|e_QM_FQ_CHANNEL_SWPORTAL4
block|,
name|e_QM_FQ_CHANNEL_SWPORTAL5
block|,
name|e_QM_FQ_CHANNEL_SWPORTAL6
block|,
name|e_QM_FQ_CHANNEL_SWPORTAL7
block|,
name|e_QM_FQ_CHANNEL_SWPORTAL8
block|,
name|e_QM_FQ_CHANNEL_SWPORTAL9
block|,
name|e_QM_FQ_CHANNEL_POOL1
init|=
literal|0x21
block|,
comment|/**< Pool channels that can be serviced by any of the software portals */
name|e_QM_FQ_CHANNEL_POOL2
block|,
name|e_QM_FQ_CHANNEL_POOL3
block|,
name|e_QM_FQ_CHANNEL_POOL4
block|,
name|e_QM_FQ_CHANNEL_POOL5
block|,
name|e_QM_FQ_CHANNEL_POOL6
block|,
name|e_QM_FQ_CHANNEL_POOL7
block|,
name|e_QM_FQ_CHANNEL_POOL8
block|,
name|e_QM_FQ_CHANNEL_POOL9
block|,
name|e_QM_FQ_CHANNEL_POOL10
block|,
name|e_QM_FQ_CHANNEL_POOL11
block|,
name|e_QM_FQ_CHANNEL_POOL12
block|,
name|e_QM_FQ_CHANNEL_POOL13
block|,
name|e_QM_FQ_CHANNEL_POOL14
block|,
name|e_QM_FQ_CHANNEL_POOL15
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP0
init|=
literal|0x40
block|,
comment|/**< Dedicated channels serviced by Direct Connect Portal 0:                                                      connected to FMan 0; assigned in incrementing order to                                                      each sub-portal (SP) in the portal */
name|e_QM_FQ_CHANNEL_FMAN0_SP1
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP2
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP3
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP4
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP5
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP6
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP7
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP8
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP9
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP10
block|,
name|e_QM_FQ_CHANNEL_FMAN0_SP11
block|,
name|e_QM_FQ_CHANNEL_RMAN_SP2
init|=
literal|0x62
block|,
comment|/**< Dedicated channels serviced by Direct Connect Portal 1: connected to RMan */
name|e_QM_FQ_CHANNEL_RMAN_SP3
block|,
name|e_QM_FQ_CHANNEL_CAAM
init|=
literal|0x80
block|,
comment|/**< Dedicated channel serviced by Direct Connect Portal 2:                                                      connected to SEC 4.x */
name|e_QM_FQ_CHANNEL_PME
init|=
literal|0xA0
comment|/**< Dedicated channel serviced by Direct Connect Portal 3:                                                      connected to PME */
block|}
name|e_QmFQChannel
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  BMan INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BM_MAX_NUM_OF_POOLS
value|64
end_define

begin_comment
comment|/**< Number of buffers pools */
end_comment

begin_comment
comment|/*****************************************************************************  SEC INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SEC_NUM_OF_DECOS
value|2
end_define

begin_define
define|#
directive|define
name|SEC_ALL_DECOS_MASK
value|0x00000003
end_define

begin_comment
comment|/*****************************************************************************  FM INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|INTG_MAX_NUM_OF_FM
value|1
end_define

begin_comment
comment|/* Ports defines */
end_comment

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_1G_MACS
value|5
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_10G_MACS
value|1
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_MACS
value|(FM_MAX_NUM_OF_1G_MACS + FM_MAX_NUM_OF_10G_MACS)
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_OH_PORTS
value|7
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_1G_RX_PORTS
value|FM_MAX_NUM_OF_1G_MACS
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_10G_RX_PORTS
value|FM_MAX_NUM_OF_10G_MACS
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_RX_PORTS
value|(FM_MAX_NUM_OF_10G_RX_PORTS + FM_MAX_NUM_OF_1G_RX_PORTS)
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_1G_TX_PORTS
value|FM_MAX_NUM_OF_1G_MACS
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_10G_TX_PORTS
value|FM_MAX_NUM_OF_10G_MACS
end_define

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_TX_PORTS
value|(FM_MAX_NUM_OF_10G_TX_PORTS + FM_MAX_NUM_OF_1G_TX_PORTS)
end_define

begin_define
define|#
directive|define
name|FM_PORT_MAX_NUM_OF_EXT_POOLS
value|8
end_define

begin_comment
comment|/**< Number of external BM pools per Rx port */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_NUM_OF_CONGESTION_GRPS
value|256
end_define

begin_comment
comment|/**< Total number of congestion groups in QM */
end_comment

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_SUB_PORTALS
value|12
end_define

begin_define
define|#
directive|define
name|FM_PORT_MAX_NUM_OF_OBSERVED_EXT_POOLS
value|0
end_define

begin_comment
comment|/* RAMs defines */
end_comment

begin_define
define|#
directive|define
name|FM_MURAM_SIZE
value|(160 * KILOBYTE)
end_define

begin_define
define|#
directive|define
name|FM_IRAM_SIZE
value|( 64 * KILOBYTE)
end_define

begin_comment
comment|/* PCD defines */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_NUM_ENTRIES
value|256
end_define

begin_comment
comment|/**< Total number of policer profiles */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_NUM_OF_SCHEMES
value|32
end_define

begin_comment
comment|/**< Total number of KG schemes */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_CLS_PLANS
value|256
end_define

begin_comment
comment|/**< Number of classification plan entries. */
end_comment

begin_comment
comment|/* RTC defines */
end_comment

begin_define
define|#
directive|define
name|FM_RTC_NUM_OF_ALARMS
value|2
end_define

begin_comment
comment|/**< RTC number of alarms */
end_comment

begin_define
define|#
directive|define
name|FM_RTC_NUM_OF_PERIODIC_PULSES
value|2
end_define

begin_comment
comment|/**< RTC number of periodic pulses */
end_comment

begin_define
define|#
directive|define
name|FM_RTC_NUM_OF_EXT_TRIGGERS
value|2
end_define

begin_comment
comment|/**< RTC number of external triggers */
end_comment

begin_comment
comment|/* QMI defines */
end_comment

begin_define
define|#
directive|define
name|QMI_MAX_NUM_OF_TNUMS
value|64
end_define

begin_define
define|#
directive|define
name|MAX_QMI_DEQ_SUBPORTAL
value|12
end_define

begin_define
define|#
directive|define
name|QMI_DEF_TNUMS_THRESH
value|48
end_define

begin_comment
comment|/* FPM defines */
end_comment

begin_define
define|#
directive|define
name|FM_NUM_OF_FMAN_CTRL_EVENT_REGS
value|4
end_define

begin_comment
comment|/* DMA defines */
end_comment

begin_define
define|#
directive|define
name|DMA_THRESH_MAX_COMMQ
value|31
end_define

begin_define
define|#
directive|define
name|DMA_THRESH_MAX_BUF
value|127
end_define

begin_comment
comment|/* BMI defines */
end_comment

begin_define
define|#
directive|define
name|BMI_MAX_NUM_OF_TASKS
value|128
end_define

begin_define
define|#
directive|define
name|BMI_MAX_NUM_OF_DMAS
value|32
end_define

begin_define
define|#
directive|define
name|BMI_MAX_FIFO_SIZE
value|(FM_MURAM_SIZE)
end_define

begin_define
define|#
directive|define
name|PORT_MAX_WEIGHT
value|16
end_define

begin_comment
comment|/**< Port weight in BMI arbitration register */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for inter-module interrupts registration */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmEventModules
block|{
name|e_FM_MOD_PRS
block|,
comment|/**< Parser event */
name|e_FM_MOD_KG
block|,
comment|/**< Keygen event */
name|e_FM_MOD_PLCR
block|,
comment|/**< Policer event */
name|e_FM_MOD_10G_MAC
block|,
comment|/**< 10G MAC error event */
name|e_FM_MOD_1G_MAC
block|,
comment|/**< 1G MAC error event */
name|e_FM_MOD_TMR
block|,
comment|/**< Timer event */
name|e_FM_MOD_1G_MAC_TMR
block|,
comment|/**< 1G MAC timer event */
name|e_FM_MOD_FMAN_CTRL
block|,
comment|/**< FMAN Controller timer event */
name|e_FM_MOD_DUMMY_LAST
block|}
name|e_FmEventModules
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for interrupts types */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmIntrType
block|{
name|e_FM_INTR_TYPE_ERR
block|,
name|e_FM_INTR_TYPE_NORMAL
block|}
name|e_FmIntrType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for inter-module interrupts registration */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmInterModuleEvent
block|{
name|e_FM_EV_PRS
block|,
comment|/**< Parser event */
name|e_FM_EV_ERR_PRS
block|,
comment|/**< Parser error event */
name|e_FM_EV_KG
block|,
comment|/**< Keygen event */
name|e_FM_EV_ERR_KG
block|,
comment|/**< Keygen error event */
name|e_FM_EV_PLCR
block|,
comment|/**< Policer event */
name|e_FM_EV_ERR_PLCR
block|,
comment|/**< Policer error event */
name|e_FM_EV_ERR_10G_MAC0
block|,
comment|/**< 10G MAC 0 error event */
name|e_FM_EV_ERR_1G_MAC0
block|,
comment|/**< 1G MAC 0 error event */
name|e_FM_EV_ERR_1G_MAC1
block|,
comment|/**< 1G MAC 1 error event */
name|e_FM_EV_ERR_1G_MAC2
block|,
comment|/**< 1G MAC 2 error event */
name|e_FM_EV_ERR_1G_MAC3
block|,
comment|/**< 1G MAC 3 error event */
name|e_FM_EV_ERR_1G_MAC4
block|,
comment|/**< 1G MAC 4 error event */
name|e_FM_EV_TMR
block|,
comment|/**< Timer event */
name|e_FM_EV_1G_MAC0_TMR
block|,
comment|/**< 1G MAC 0 timer event */
name|e_FM_EV_1G_MAC1_TMR
block|,
comment|/**< 1G MAC 1 timer event */
name|e_FM_EV_1G_MAC2_TMR
block|,
comment|/**< 1G MAC 2 timer event */
name|e_FM_EV_1G_MAC3_TMR
block|,
comment|/**< 1G MAC 3 timer event */
name|e_FM_EV_1G_MAC4_TMR
block|,
comment|/**< 1G MAC 4 timer event */
name|e_FM_EV_FMAN_CTRL_0
block|,
comment|/**< Fman controller event 0 */
name|e_FM_EV_FMAN_CTRL_1
block|,
comment|/**< Fman controller event 1 */
name|e_FM_EV_FMAN_CTRL_2
block|,
comment|/**< Fman controller event 2 */
name|e_FM_EV_FMAN_CTRL_3
block|,
comment|/**< Fman controller event 3 */
name|e_FM_EV_DUMMY_LAST
block|}
name|e_FmInterModuleEvent
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GET_FM_MODULE_EVENT
parameter_list|(
name|mod
parameter_list|,
name|id
parameter_list|,
name|intrType
parameter_list|,
name|event
parameter_list|)
define|\
value|switch(mod){                                                                                    \         case e_FM_MOD_PRS:                                                                          \             if (id) event = e_FM_EV_DUMMY_LAST;                                                     \             else event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_PRS : e_FM_EV_PRS;          \             break;                                                                                  \         case e_FM_MOD_KG:                                                                           \             if (id) event = e_FM_EV_DUMMY_LAST;                                                     \             else event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_KG : e_FM_EV_DUMMY_LAST;    \             break;                                                                                  \         case e_FM_MOD_PLCR:                                                                         \             if (id) event = e_FM_EV_DUMMY_LAST;                                                     \             else event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_PLCR : e_FM_EV_PLCR;        \             break;                                                                                  \         case e_FM_MOD_10G_MAC:                                                                      \             if (id) event = e_FM_EV_DUMMY_LAST;                                                     \             else event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_10G_MAC0 : e_FM_EV_DUMMY_LAST; \             break;                                                                                  \         case e_FM_MOD_1G_MAC:                                                                       \             switch(id){                                                                             \                  case(0): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_1G_MAC0 : e_FM_EV_DUMMY_LAST; break; \                  case(1): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_1G_MAC1 : e_FM_EV_DUMMY_LAST; break; \                  case(2): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_1G_MAC2 : e_FM_EV_DUMMY_LAST; break; \                  case(3): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_1G_MAC3 : e_FM_EV_DUMMY_LAST; break; \                  case(4): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_ERR_1G_MAC4 : e_FM_EV_DUMMY_LAST; break; \                  }                                                                                  \             break;                                                                                  \         case e_FM_MOD_TMR:                                                                          \             if (id) event = e_FM_EV_DUMMY_LAST;                                                     \             else event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_DUMMY_LAST : e_FM_EV_TMR;       \             break;                                                                                  \         case e_FM_MOD_1G_MAC_TMR:                                                                   \             switch(id){                                                                             \                  case(0): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_DUMMY_LAST : e_FM_EV_1G_MAC0_TMR; break; \                  case(1): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_DUMMY_LAST : e_FM_EV_1G_MAC1_TMR; break; \                  case(2): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_DUMMY_LAST : e_FM_EV_1G_MAC2_TMR; break; \                  case(3): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_DUMMY_LAST : e_FM_EV_1G_MAC3_TMR; break; \                  case(4): event = (intrType == e_FM_INTR_TYPE_ERR) ? e_FM_EV_DUMMY_LAST : e_FM_EV_1G_MAC4_TMR; break; \                  }                                                                                  \             break;                                                                                  \         case e_FM_MOD_FMAN_CTRL:                                                                    \             if (intrType == e_FM_INTR_TYPE_ERR) event = e_FM_EV_DUMMY_LAST;                         \             else switch(id){                                                                        \                  case(0): event = e_FM_EV_FMAN_CTRL_0; break;                                       \                  case(1): event = e_FM_EV_FMAN_CTRL_1; break;                                       \                  case(2): event = e_FM_EV_FMAN_CTRL_2; break;                                       \                  case(3): event = e_FM_EV_FMAN_CTRL_3; break;                                       \                  }                                                                                  \             break;                                                                                  \         default: event = e_FM_EV_DUMMY_LAST;                                                        \         break;}
end_define

begin_define
define|#
directive|define
name|FM_CHECK_PORT_RESTRICTIONS
parameter_list|(
name|__validPorts
parameter_list|,
name|__newPortIndx
parameter_list|)
value|TRUE
end_define

begin_comment
comment|/* P2041 unique features */
end_comment

begin_define
define|#
directive|define
name|FM_QMI_DEQ_OPTIONS_SUPPORT
end_define

begin_define
define|#
directive|define
name|FM_NO_DISPATCH_RAM_ECC
end_define

begin_define
define|#
directive|define
name|FM_FIFO_ALLOCATION_OLD_ALG
end_define

begin_define
define|#
directive|define
name|FM_NO_WATCHDOG
end_define

begin_define
define|#
directive|define
name|FM_NO_TNUM_AGING
end_define

begin_define
define|#
directive|define
name|FM_NO_TGEC_LOOPBACK
end_define

begin_define
define|#
directive|define
name|FM_KG_NO_BYPASS_FQID_GEN
end_define

begin_define
define|#
directive|define
name|FM_KG_NO_BYPASS_PLCR_PROFILE_GEN
end_define

begin_define
define|#
directive|define
name|FM_NO_BACKUP_POOLS
end_define

begin_define
define|#
directive|define
name|FM_NO_OP_OBSERVED_POOLS
end_define

begin_define
define|#
directive|define
name|FM_NO_ADVANCED_RATE_LIMITER
end_define

begin_define
define|#
directive|define
name|FM_NO_OP_OBSERVED_CGS
end_define

begin_comment
comment|/* FM erratas */
end_comment

begin_define
define|#
directive|define
name|FM_BAD_VLAN_DETECT_ERRATA_10GMAC_A010
end_define

begin_define
define|#
directive|define
name|FM_RX_PREAM_4_ERRATA_DTSEC_A001
end_define

begin_define
define|#
directive|define
name|FM_MAGIC_PACKET_UNRECOGNIZED_ERRATA_DTSEC2
end_define

begin_comment
comment|/* No implementation, Out of LLD scope */
end_comment

begin_define
define|#
directive|define
name|FM_UCODE_NOT_RESET_ERRATA_BUGZILLA6173
end_define

begin_define
define|#
directive|define
name|FM_LEN_CHECK_ERRATA_FMAN_SW002
end_define

begin_define
define|#
directive|define
name|FM_PRS_MEM_ERRATA_FMAN_SW003
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DPAA_INTEGRATION_EXT_H */
end_comment

end_unit

