begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_mac_ext.h   @Description   FM MAC ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_MAC_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_MAC_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"enet_ext.h"
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
comment|/**  @Group         FM_mac_grp FM MAC   @Description   FM MAC API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_MAC_NO_PFC
value|0xff
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM MAC Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacExceptions
block|{
name|e_FM_MAC_EX_10G_MDIO_SCAN_EVENTMDIO
init|=
literal|0
comment|/**< 10GEC MDIO scan event interrupt */
block|,
name|e_FM_MAC_EX_10G_MDIO_CMD_CMPL
comment|/**< 10GEC MDIO command completion interrupt */
block|,
name|e_FM_MAC_EX_10G_REM_FAULT
comment|/**< 10GEC, mEMAC Remote fault interrupt */
block|,
name|e_FM_MAC_EX_10G_LOC_FAULT
comment|/**< 10GEC, mEMAC Local fault interrupt */
block|,
name|e_FM_MAC_EX_10G_1TX_ECC_ER
comment|/**< 10GEC, mEMAC Transmit frame ECC error interrupt */
block|,
name|e_FM_MAC_EX_10G_TX_FIFO_UNFL
comment|/**< 10GEC, mEMAC Transmit FIFO underflow interrupt */
block|,
name|e_FM_MAC_EX_10G_TX_FIFO_OVFL
comment|/**< 10GEC, mEMAC Transmit FIFO overflow interrupt */
block|,
name|e_FM_MAC_EX_10G_TX_ER
comment|/**< 10GEC Transmit frame error interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_FIFO_OVFL
comment|/**< 10GEC, mEMAC Receive FIFO overflow interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_ECC_ER
comment|/**< 10GEC, mEMAC Receive frame ECC error interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_JAB_FRM
comment|/**< 10GEC Receive jabber frame interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_OVRSZ_FRM
comment|/**< 10GEC Receive oversized frame interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_RUNT_FRM
comment|/**< 10GEC Receive runt frame interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_FRAG_FRM
comment|/**< 10GEC Receive fragment frame interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_LEN_ER
comment|/**< 10GEC Receive payload length error interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_CRC_ER
comment|/**< 10GEC Receive CRC error interrupt */
block|,
name|e_FM_MAC_EX_10G_RX_ALIGN_ER
comment|/**< 10GEC Receive alignment error interrupt */
block|,
name|e_FM_MAC_EX_1G_BAB_RX
comment|/**< dTSEC Babbling receive error */
block|,
name|e_FM_MAC_EX_1G_RX_CTL
comment|/**< dTSEC Receive control (pause frame) interrupt */
block|,
name|e_FM_MAC_EX_1G_GRATEFUL_TX_STP_COMPLET
comment|/**< dTSEC Graceful transmit stop complete */
block|,
name|e_FM_MAC_EX_1G_BAB_TX
comment|/**< dTSEC Babbling transmit error */
block|,
name|e_FM_MAC_EX_1G_TX_CTL
comment|/**< dTSEC Transmit control (pause frame) interrupt */
block|,
name|e_FM_MAC_EX_1G_TX_ERR
comment|/**< dTSEC Transmit error */
block|,
name|e_FM_MAC_EX_1G_LATE_COL
comment|/**< dTSEC Late collision */
block|,
name|e_FM_MAC_EX_1G_COL_RET_LMT
comment|/**< dTSEC Collision retry limit */
block|,
name|e_FM_MAC_EX_1G_TX_FIFO_UNDRN
comment|/**< dTSEC Transmit FIFO underrun */
block|,
name|e_FM_MAC_EX_1G_MAG_PCKT
comment|/**< dTSEC Magic Packet detection */
block|,
name|e_FM_MAC_EX_1G_MII_MNG_RD_COMPLET
comment|/**< dTSEC MII management read completion */
block|,
name|e_FM_MAC_EX_1G_MII_MNG_WR_COMPLET
comment|/**< dTSEC MII management write completion */
block|,
name|e_FM_MAC_EX_1G_GRATEFUL_RX_STP_COMPLET
comment|/**< dTSEC Graceful receive stop complete */
block|,
name|e_FM_MAC_EX_1G_TX_DATA_ERR
comment|/**< dTSEC Internal data error on transmit */
block|,
name|e_FM_MAC_EX_1G_RX_DATA_ERR
comment|/**< dTSEC Internal data error on receive */
block|,
name|e_FM_MAC_EX_1G_1588_TS_RX_ERR
comment|/**< dTSEC Time-Stamp Receive Error */
block|,
name|e_FM_MAC_EX_1G_RX_MIB_CNT_OVFL
comment|/**< dTSEC MIB counter overflow */
block|,
name|e_FM_MAC_EX_TS_FIFO_ECC_ERR
comment|/**< mEMAC Time-stamp FIFO ECC error interrupt;                                                                      not supported on T4240/B4860 rev1 chips */
block|,
name|e_FM_MAC_EX_MAGIC_PACKET_INDICATION
init|=
name|e_FM_MAC_EX_1G_MAG_PCKT
comment|/**< mEMAC Magic Packet Indication Interrupt */
block|}
name|e_FmMacExceptions
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   TM MAC statistics level */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacStatisticsLevel
block|{
name|e_FM_MAC_NONE_STATISTICS
init|=
literal|0
block|,
comment|/**< No statistics */
name|e_FM_MAC_PARTIAL_STATISTICS
block|,
comment|/**< Only error counters are available; Optimized for performance */
name|e_FM_MAC_FULL_STATISTICS
comment|/**< All counters available; Not optimized for performance */
block|}
name|e_FmMacStatisticsLevel
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Priority Flow Control Parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacPfcParams
block|{
name|bool
name|pfcEnable
decl_stmt|;
comment|/**< Enable/Disable PFC */
name|uint16_t
name|pauseQuanta
index|[
name|FM_MAX_NUM_OF_PFC_PRIORITIES
index|]
decl_stmt|;
comment|/**< Pause Quanta per priority to be sent in a pause frame. Each quanta represents a 512 bit-times*/
name|uint16_t
name|pauseThresholdQuanta
index|[
name|FM_MAX_NUM_OF_PFC_PRIORITIES
index|]
decl_stmt|;
comment|/**< Pause threshold per priority, when timer passes this threshold time a PFC frames is sent again if the port is still congested or BM pool in depletion*/
block|}
name|t_FmMacPfcParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_FmMacExceptionCallback   @Description   Fm Mac Exception Callback from FM MAC to the user   @Param[in]     h_App             - Handle to the upper layer handler   @Param[in]     exceptions        - The exception that occurred   @Return        void. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmMacExceptionCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmMacExceptions
name|exceptions
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   TM MAC statistics rfc3635 */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacStatistics
block|{
comment|/* RMON */
name|uint64_t
name|eStatPkts64
decl_stmt|;
comment|/**< r-10G tr-DT 64 byte frame counter */
name|uint64_t
name|eStatPkts65to127
decl_stmt|;
comment|/**< r-10G 65 to 127 byte frame counter */
name|uint64_t
name|eStatPkts128to255
decl_stmt|;
comment|/**< r-10G 128 to 255 byte frame counter */
name|uint64_t
name|eStatPkts256to511
decl_stmt|;
comment|/**< r-10G 256 to 511 byte frame counter */
name|uint64_t
name|eStatPkts512to1023
decl_stmt|;
comment|/**< r-10G 512 to 1023 byte frame counter */
name|uint64_t
name|eStatPkts1024to1518
decl_stmt|;
comment|/**< r-10G 1024 to 1518 byte frame counter */
name|uint64_t
name|eStatPkts1519to1522
decl_stmt|;
comment|/**< r-10G 1519 to 1522 byte good frame count */
comment|/* */
name|uint64_t
name|eStatFragments
decl_stmt|;
comment|/**< Total number of packets that were less than 64 octets long with a wrong CRC.*/
name|uint64_t
name|eStatJabbers
decl_stmt|;
comment|/**< Total number of packets longer than valid maximum length octets */
name|uint64_t
name|eStatsDropEvents
decl_stmt|;
comment|/**< number of dropped packets due to internal errors of the MAC Client (during receive). */
name|uint64_t
name|eStatCRCAlignErrors
decl_stmt|;
comment|/**< Incremented when frames of correct length but with CRC error are received.*/
name|uint64_t
name|eStatUndersizePkts
decl_stmt|;
comment|/**< Incremented for frames under 64 bytes with a valid FCS and otherwise well formed;                                             This count does not include range length errors */
name|uint64_t
name|eStatOversizePkts
decl_stmt|;
comment|/**< Incremented for frames which exceed 1518 (non VLAN) or 1522 (VLAN) and contains                                             a valid FCS and otherwise well formed */
comment|/* Pause */
name|uint64_t
name|teStatPause
decl_stmt|;
comment|/**< Pause MAC Control received */
name|uint64_t
name|reStatPause
decl_stmt|;
comment|/**< Pause MAC Control sent */
comment|/* MIB II */
name|uint64_t
name|ifInOctets
decl_stmt|;
comment|/**< Total number of byte received. */
name|uint64_t
name|ifInPkts
decl_stmt|;
comment|/**< Total number of packets received.*/
name|uint64_t
name|ifInUcastPkts
decl_stmt|;
comment|/**< Total number of unicast frame received;                                             NOTE: this counter is not supported on dTSEC MAC */
name|uint64_t
name|ifInMcastPkts
decl_stmt|;
comment|/**< Total number of multicast frame received*/
name|uint64_t
name|ifInBcastPkts
decl_stmt|;
comment|/**< Total number of broadcast frame received */
name|uint64_t
name|ifInDiscards
decl_stmt|;
comment|/**< Frames received, but discarded due to problems within the MAC RX. */
name|uint64_t
name|ifInErrors
decl_stmt|;
comment|/**< Number of frames received with error:                                                - FIFO Overflow Error                                                - CRC Error                                                - Frame Too Long Error                                                - Alignment Error                                                - The dedicated Error Code (0xfe, not a code error) was received */
name|uint64_t
name|ifOutOctets
decl_stmt|;
comment|/**< Total number of byte sent. */
name|uint64_t
name|ifOutPkts
decl_stmt|;
comment|/**< Total number of packets sent .*/
name|uint64_t
name|ifOutUcastPkts
decl_stmt|;
comment|/**< Total number of unicast frame sent;                                             NOTE: this counter is not supported on dTSEC MAC */
name|uint64_t
name|ifOutMcastPkts
decl_stmt|;
comment|/**< Total number of multicast frame sent */
name|uint64_t
name|ifOutBcastPkts
decl_stmt|;
comment|/**< Total number of multicast frame sent */
name|uint64_t
name|ifOutDiscards
decl_stmt|;
comment|/**< Frames received, but discarded due to problems within the MAC TX N/A!.*/
name|uint64_t
name|ifOutErrors
decl_stmt|;
comment|/**< Number of frames transmitted with error:                                                - FIFO Overflow Error                                                - FIFO Underflow Error                                                - Other */
block|}
name|t_FmMacStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_mac_init_grp FM MAC Initialization Unit   @Description   FM MAC Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM MAC config input */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacParams
block|{
name|uintptr_t
name|baseAddr
decl_stmt|;
comment|/**< Base of memory mapped FM MAC registers */
name|t_EnetAddr
name|addr
decl_stmt|;
comment|/**< MAC address of device; First octet is sent first */
name|uint8_t
name|macId
decl_stmt|;
comment|/**< MAC ID;                                                          numbering of dTSEC and 1G-mEMAC:                                                             0 - FM_MAX_NUM_OF_1G_MACS;                                                          numbering of 10G-MAC (TGEC) and 10G-mEMAC:                                                             0 - FM_MAX_NUM_OF_10G_MACS */
name|e_EnetMode
name|enetMode
decl_stmt|;
comment|/**< Ethernet operation mode (MAC-PHY interface and speed);                                                          Note that the speed should indicate the maximum rate that                                                          this MAC should support rather than the actual speed;                                                          i.e. user should use the FM_MAC_AdjustLink() routine to                                                          provide accurate speed;                                                          In case of mEMAC RGMII mode, the MAC is configured to RGMII                                                          automatic mode, where actual speed/duplex mode information                                                          is provided by PHY automatically in-band; FM_MAC_AdjustLink()                                                          function should be used to switch to manual RGMII speed/duplex mode                                                          configuration if RGMII PHY doesn't support in-band status signaling;                                                          In addition, in mEMAC, in case where user is using the higher MACs                                                          (i.e. the MACs that should support 10G), user should pass here                                                          speed=10000 even if the interface is not allowing that (e.g. SGMII). */
name|t_Handle
name|h_Fm
decl_stmt|;
comment|/**< A handle to the FM object this port related to */
name|int
name|mdioIrq
decl_stmt|;
comment|/**< MDIO exceptions interrupt source - not valid for all                                                          MACs; MUST be set to 'NO_IRQ' for MACs that don't have                                                          mdio-irq, or for polling */
name|t_FmMacExceptionCallback
modifier|*
name|f_Event
decl_stmt|;
comment|/**< MDIO Events Callback Routine         */
name|t_FmMacExceptionCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< Exception Callback Routine         */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                          be passed by the driver upon calling the above callbacks */
block|}
name|t_FmMacParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_Config   @Description   Creates descriptor for the FM MAC module.                  The routine returns a handle (descriptor) to the FM MAC object.                 This descriptor must be passed as first parameter to all other                 FM MAC function calls.                  No actual initialization or configuration of FM MAC hardware is                 done by this routine.   @Param[in]     p_FmMacParam   - Pointer to data structure of parameters   @Retval        Handle to FM MAC object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_MAC_Config
parameter_list|(
name|t_FmMacParams
modifier|*
name|p_FmMacParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_Init   @Description   Initializes the FM MAC module   @Param[in]     h_FmMac - FM module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_Init
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_Free   @Description   Frees all resources that were assigned to FM MAC module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_FmMac - FM module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_Free
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_mac_advanced_init_grp    FM MAC Advanced Configuration Unit   @Description   Configuration functions used to change default values.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_ConfigResetOnInit   @Description   Tell the driver whether to reset the FM MAC before initialization or                 not. It changes the default configuration [DEFAULT_resetOnInit].   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     enable     When TRUE, FM will be reset before any initialization.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigResetOnInit
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/**  @Function      FM_MAC_ConfigLoopback   @Description   Enable/Disable internal loopback mode   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     enable     TRUE to enable or FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigLoopback
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/**  @Function      FM_MAC_ConfigMaxFrameLength   @Description   Setup maximum Rx Frame Length (in 1G MAC, effects also Tx)   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     newVal     MAX Frame length   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigMaxFrameLength
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/**  @Function      FM_MAC_ConfigWan   @Description   ENABLE WAN mode in 10G-MAC   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     enable     TRUE to enable or FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigWan
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/**  @Function      FM_MAC_ConfigPadAndCrc   @Description   Config PAD and CRC mode   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     enable     TRUE to enable or FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init().                 Not supported on 10G-MAC (i.e. CRC& PAD are added automatically                 by HW); on mEMAC, this routine supports only PAD (i.e. CRC is                 added automatically by HW). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigPadAndCrc
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/**  @Function      FM_MAC_ConfigHalfDuplex   @Description   Config Half Duplex Mode   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     enable     TRUE to enable or FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigHalfDuplex
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/**  @Function      FM_MAC_ConfigTbiPhyAddr   @Description   Configures the address of internal TBI PHY.   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     newVal     TBI PHY address (1-31).   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigTbiPhyAddr
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|uint8_t
name|newVal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_ConfigLengthCheck   @Description   Configure the frame length checking.   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     enable     TRUE to enable or FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigLengthCheck
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/**  @Function      FM_MAC_ConfigException   @Description   Change Exception selection from default   @Param[in]     h_FmMac         A handle to a FM MAC Module.  @Param[in]     ex              Type of the desired exceptions  @Param[in]     enable          TRUE to enable the specified exception, FALSE to disable it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Config() and before FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ConfigException
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|e_FmMacExceptions
name|ex
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FM_TX_ECC_FRMS_ERRATA_10GMAC_A004
end_ifdef

begin_function_decl
name|t_Error
name|FM_MAC_ConfigSkipFman11Workaround
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_TX_ECC_FRMS_ERRATA_10GMAC_A004 */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_mac_advanced_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_mac_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_mac_runtime_control_grp FM MAC Runtime Control Unit   @Description   FM MAC Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_Enable   @Description   Enable the MAC   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     mode       Mode of operation (RX, TX, Both)   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_Enable
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|e_CommMode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_Disable   @Description   DISABLE the MAC   @Param[in]     h_FmMac    A handle to a FM MAC Module.  @Param[in]     mode       Define what part to Disable (RX,  TX or BOTH)   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_Disable
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|e_CommMode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_Resume   @Description   Re-init the MAC after suspend   @Param[in]     h_FmMac    A handle to a FM MAC Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_Resume
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_Enable1588TimeStamp   @Description   Enables the TSU operation.   @Param[in]     h_Fm   - Handle to the PTP as returned from the FM_MAC_PtpConfig.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_Enable1588TimeStamp
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
comment|/**  @Function      FM_MAC_Disable1588TimeStamp   @Description   Disables the TSU operation.   @Param[in]     h_Fm   - Handle to the PTP as returned from the FM_MAC_PtpConfig.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_Disable1588TimeStamp
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
comment|/**  @Function      FM_MAC_SetTxAutoPauseFrames   @Description   Enable/Disable transmission of Pause-Frames.                 The routine changes the default configuration [DEFAULT_TX_PAUSE_TIME].   @Param[in]     h_FmMac       -  A handle to a FM MAC Module.  @Param[in]     pauseTime     -  Pause quanta value used with transmitted pause frames.                                  Each quanta represents a 512 bit-times; Note that '0'                                  as an input here will be used as disabling the                                  transmission of the pause-frames.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_SetTxAutoPauseFrames
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|uint16_t
name|pauseTime
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_SetTxPauseFrames   @Description   Enable/Disable transmission of Pause-Frames.                 The routine changes the default configuration:                 pause-time - [DEFAULT_TX_PAUSE_TIME]                 threshold-time - [0]   @Param[in]     h_FmMac       -  A handle to a FM MAC Module.  @Param[in]     priority      -  the PFC class of service; use 'FM_MAC_NO_PFC'                                  to indicate legacy pause support (i.e. no PFC).  @Param[in]     pauseTime     -  Pause quanta value used with transmitted pause frames.                                  Each quanta represents a 512 bit-times;                                  Note that '0' as an input here will be used as disabling the                                  transmission of the pause-frames.  @Param[in]     threshTime    -  Pause Threshold equanta value used by the MAC to retransmit pause frame.                                  if the situation causing a pause frame to be sent didn't finish when the timer                                  reached the threshold quanta, the MAC will retransmit the pause frame.                                  Each quanta represents a 512 bit-times.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init().                 In order for PFC to work properly the user must configure                 TNUM-aging in the tx-port it is recommended that pre-fetch and                 rate limit in the tx port should be disabled;                 PFC is supported only on new mEMAC; i.e. in MACs that don't have                 PFC support (10G-MAC and dTSEC), user should use 'FM_MAC_NO_PFC'                 in the 'priority' field. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_SetTxPauseFrames
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|uint8_t
name|priority
parameter_list|,
name|uint16_t
name|pauseTime
parameter_list|,
name|uint16_t
name|threshTime
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_SetRxIgnorePauseFrames   @Description   Enable/Disable ignoring of Pause-Frames.   @Param[in]     h_FmMac    - A handle to a FM MAC Module.  @Param[in]     en         - boolean indicates whether to ignore the incoming pause                              frames or not.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_SetRxIgnorePauseFrames
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_SetWakeOnLan   @Description   Enable/Disable Wake On Lan support   @Param[in]     h_FmMac    - A handle to a FM MAC Module.  @Param[in]     en         - boolean indicates whether to enable Wake On Lan                              support or not.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_SetWakeOnLan
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_ResetCounters   @Description   reset all statistics counters   @Param[in]     h_FmMac    - A handle to a FM MAC Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ResetCounters
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_SetException   @Description   Enable/Disable a specific Exception   @Param[in]     h_FmMac        - A handle to a FM MAC Module.  @Param[in]     ex             - Type of the desired exceptions  @Param[in]     enable         - TRUE to enable the specified exception, FALSE to disable it.    @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_SetException
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|e_FmMacExceptions
name|ex
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
comment|/**  @Function      FM_MAC_SetStatistics   @Description   Define Statistics level.                 Where applicable, the routine also enables the MIB counters                 overflow interrupt in order to keep counters accurate                 and account for overflows.                 This routine is relevant only for dTSEC.   @Param[in]     h_FmMac         - A handle to a FM MAC Module.  @Param[in]     statisticsLevel - Full statistics level provides all standard counters but may                                   reduce performance. Partial statistics provides only special                                   event counters (errors etc.). If selected, regular counters (such as                                   byte/packet) will be invalid and will return -1.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_SetStatistics
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|e_FmMacStatisticsLevel
name|statisticsLevel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_GetStatistics   @Description   get all statistics counters   @Param[in]     h_FmMac       -  A handle to a FM MAC Module.  @Param[in]     p_Statistics  -  Structure with statistics   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_GetStatistics
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|t_FmMacStatistics
modifier|*
name|p_Statistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_ModifyMacAddr   @Description   Replace the main MAC Address   @Param[in]     h_FmMac     -   A handle to a FM Module.  @Param[in]     p_EnetAddr  -   Ethernet Mac address   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_ModifyMacAddr
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|t_EnetAddr
modifier|*
name|p_EnetAddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_AddHashMacAddr   @Description   Add an Address to the hash table. This is for filter purpose only.   @Param[in]     h_FmMac     -   A handle to a FM Module.  @Param[in]     p_EnetAddr  -   Ethernet Mac address   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). It is a filter only address.  @Cautions      Some address need to be filterd out in upper FM blocks. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_AddHashMacAddr
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|t_EnetAddr
modifier|*
name|p_EnetAddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_RemoveHashMacAddr   @Description   Delete an Address to the hash table. This is for filter purpose only.   @Param[in]     h_FmMac     -   A handle to a FM Module.  @Param[in]     p_EnetAddr  -   Ethernet Mac address   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_RemoveHashMacAddr
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|t_EnetAddr
modifier|*
name|p_EnetAddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_AddExactMatchMacAddr   @Description   Add a unicast or multicast mac address for exact-match filtering                 (8 on dTSEC, 2 for 10G-MAC)   @Param[in]     h_FmMac     -   A handle to a FM Module.  @Param[in]     p_EnetAddr  -   MAC Address to ADD   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_AddExactMatchMacAddr
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|t_EnetAddr
modifier|*
name|p_EnetAddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_RemovelExactMatchMacAddr   @Description   Remove a uni cast or multi cast mac address.   @Param[in]     h_FmMac     -   A handle to a FM Module.  @Param[in]     p_EnetAddr  -   MAC Address to remove   @Return        E_OK on success; Error code otherwise..   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_RemovelExactMatchMacAddr
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|t_EnetAddr
modifier|*
name|p_EnetAddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_SetPromiscuous   @Description   Enable/Disable MAC Promiscuous mode for ALL mac addresses.   @Param[in]     h_FmMac    - A handle to a FM MAC Module.  @Param[in]     enable     - TRUE to enable or FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_SetPromiscuous
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/**  @Function      FM_MAC_AdjustLink   @Description   Adjusts the Ethernet link with new speed/duplex setup.                 This routine is relevant for dTSEC and mEMAC.                 In case of mEMAC, this routine is also used for manual                 re-configuration of RGMII speed and duplex mode for                 RGMII PHYs not supporting in-band status information                 to MAC.   @Param[in]     h_FmMac     - A handle to a FM Module.  @Param[in]     speed       - Ethernet speed.  @Param[in]     fullDuplex  - TRUE for full-duplex mode;                               FALSE for half-duplex mode.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_AdjustLink
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|e_EnetSpeed
name|speed
parameter_list|,
name|bool
name|fullDuplex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_RestartAutoneg   @Description   Restarts the auto-negotiation process.                 When auto-negotiation process is invoked under traffic the                 auto-negotiation process between the internal SGMII PHY and the                 external PHY does not always complete successfully. Calling this                 function will restart the auto-negotiation process that will end                 successfully. It is recommended to call this function after issuing                 auto-negotiation restart command to the Eth Phy.                 This routine is relevant only for dTSEC.   @Param[in]     h_FmMac     - A handle to a FM Module.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_RestartAutoneg
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_GetId   @Description   Return the MAC ID   @Param[in]     h_FmMac     -   A handle to a FM Module.  @Param[out]    p_MacId     -   MAC ID of device   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_GetId
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|uint32_t
modifier|*
name|p_MacId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_GetVesrion   @Description   Return Mac HW chip version   @Param[in]     h_FmMac      -   A handle to a FM Module.  @Param[out]    p_MacVresion -   Mac version as defined by the chip   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_GetVesrion
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|uint32_t
modifier|*
name|p_MacVresion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_MII_WritePhyReg   @Description   Write data into Phy Register   @Param[in]     h_FmMac     -   A handle to a FM Module.  @Param[in]     phyAddr     -   Phy Address on the MII bus  @Param[in]     reg         -   Register Number.  @Param[in]     data        -   Data to write.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_MII_WritePhyReg
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|uint8_t
name|phyAddr
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MAC_MII_ReadPhyReg   @Description   Read data from Phy Register   @Param[in]     h_FmMac     -   A handle to a FM Module.  @Param[in]     phyAddr     -   Phy Address on the MII bus  @Param[in]     reg         -   Register Number.  @Param[out]    p_Data      -   Data from PHY.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_MII_ReadPhyReg
parameter_list|(
name|t_Handle
name|h_FmMac
parameter_list|,
name|uint8_t
name|phyAddr
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|p_Data
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
comment|/**  @Function      FM_MAC_DumpRegs   @Description   Dump internal registers   @Param[in]     h_FmMac     -   A handle to a FM Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MAC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MAC_DumpRegs
parameter_list|(
name|t_Handle
name|h_FmMac
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
comment|/* end of FM_mac_runtime_control_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_mac_grp group */
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
comment|/* __FM_MAC_EXT_H */
end_comment

end_unit

