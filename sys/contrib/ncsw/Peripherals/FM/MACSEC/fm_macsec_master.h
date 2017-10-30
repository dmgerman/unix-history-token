begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2015 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_macsec_master.h   @Description   FM MACSEC internal structures and definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_MACSEC_MASTER_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_MACSEC_MASTER_H
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
file|"fm_macsec.h"
end_include

begin_define
define|#
directive|define
name|MACSEC_ICV_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|MACSEC_SECTAG_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|MACSEC_SCI_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|MACSEC_FCS_SIZE
value|4
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
name|FM_MACSEC_EX_TX_SC_0
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_MACSEC_EX_TX_SC
parameter_list|(
name|sc
parameter_list|)
value|(FM_MACSEC_EX_TX_SC_0>> (sc))
end_define

begin_define
define|#
directive|define
name|FM_MACSEC_EX_ECC
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
parameter_list|,
name|id
parameter_list|)
value|switch (exception){     \     case e_FM_MACSEC_EX_TX_SC:                                              \         bitMask = FM_MACSEC_EX_TX_SC(id); break;                            \     case e_FM_MACSEC_EX_ECC:                                                \         bitMask = FM_MACSEC_EX_ECC; break;                                  \     default: bitMask = 0;break;}
end_define

begin_define
define|#
directive|define
name|FM_MACSEC_USER_EX_SINGLE_BIT_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_MACSEC_USER_EX_MULTI_BIT_ECC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|GET_USER_EXCEPTION_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|exception
parameter_list|)
value|switch (exception){ \     case e_FM_MACSEC_EX_SINGLE_BIT_ECC:                                     \         bitMask = FM_MACSEC_USER_EX_SINGLE_BIT_ECC; break;                  \     case e_FM_MACSEC_EX_MULTI_BIT_ECC:                                      \         bitMask = FM_MACSEC_USER_EX_MULTI_BIT_ECC; break;                   \     default: bitMask = 0;break;}
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Events */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_MACSEC_EV_TX_SC_0_NEXT_PN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_MACSEC_EV_TX_SC_NEXT_PN
parameter_list|(
name|sc
parameter_list|)
value|(FM_MACSEC_EV_TX_SC_0_NEXT_PN>> (sc))
end_define

begin_define
define|#
directive|define
name|GET_EVENT_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|event
parameter_list|,
name|id
parameter_list|)
value|switch (event){     \     case e_FM_MACSEC_EV_TX_SC_NEXT_PN:                              \         bitMask = FM_MACSEC_EV_TX_SC_NEXT_PN(id); break;            \     default: bitMask = 0;break;}
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Defaults */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DEFAULT_userExceptions
value|(FM_MACSEC_USER_EX_SINGLE_BIT_ECC     |\                                             FM_MACSEC_USER_EX_MULTI_BIT_ECC)
end_define

begin_define
define|#
directive|define
name|DEFAULT_exceptions
value|(FM_MACSEC_EX_TX_SC(0)     |\                                             FM_MACSEC_EX_TX_SC(1)      |\                                             FM_MACSEC_EX_TX_SC(2)      |\                                             FM_MACSEC_EX_TX_SC(3)      |\                                             FM_MACSEC_EX_TX_SC(4)      |\                                             FM_MACSEC_EX_TX_SC(5)      |\                                             FM_MACSEC_EX_TX_SC(6)      |\                                             FM_MACSEC_EX_TX_SC(7)      |\                                             FM_MACSEC_EX_TX_SC(8)      |\                                             FM_MACSEC_EX_TX_SC(9)      |\                                             FM_MACSEC_EX_TX_SC(10)     |\                                             FM_MACSEC_EX_TX_SC(11)     |\                                             FM_MACSEC_EX_TX_SC(12)     |\                                             FM_MACSEC_EX_TX_SC(13)     |\                                             FM_MACSEC_EX_TX_SC(14)     |\                                             FM_MACSEC_EX_TX_SC(15)     |\                                             FM_MACSEC_EX_ECC          )
end_define

begin_define
define|#
directive|define
name|DEFAULT_events
value|(FM_MACSEC_EV_TX_SC_NEXT_PN(0)   |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(1)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(2)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(3)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(4)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(5)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(6)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(7)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(8)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(9)    |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(10)   |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(11)   |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(12)   |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(13)   |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(14)   |\                                             FM_MACSEC_EV_TX_SC_NEXT_PN(15)   )
end_define

begin_define
define|#
directive|define
name|DEFAULT_unknownSciFrameTreatment
value|e_FM_MACSEC_UNKNOWN_SCI_FRAME_TREATMENT_DISCARD_BOTH
end_define

begin_define
define|#
directive|define
name|DEFAULT_invalidTagsFrameTreatment
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_encryptWithNoChangedTextFrameTreatment
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_untagFrameTreatment
value|e_FM_MACSEC_UNTAG_FRAME_TREATMENT_DELIVER_UNCONTROLLED_DISCARD_CONTROLLED
end_define

begin_define
define|#
directive|define
name|DEFAULT_changedTextWithNoEncryptFrameTreatment
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_onlyScbIsSetFrameTreatment
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_keysUnreadable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_normalMode
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_sc0ReservedForPTP
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_initNextPn
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_pnExhThr
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|DEFAULT_sectagOverhead
value|(MACSEC_ICV_SIZE + MACSEC_SECTAG_SIZE)
end_define

begin_define
define|#
directive|define
name|DEFAULT_mflSubtract
value|MACSEC_FCS_SIZE
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

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
comment|/* MACsec configuration */
specifier|volatile
name|uint32_t
name|cfg
decl_stmt|;
comment|/**< MACsec configuration */
specifier|volatile
name|uint32_t
name|et
decl_stmt|;
comment|/**< MACsec EtherType */
specifier|volatile
name|uint8_t
name|res1
index|[
literal|56
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|mfl
decl_stmt|;
comment|/**< Maximum Frame Length */
specifier|volatile
name|uint32_t
name|tpnet
decl_stmt|;
comment|/**< TX Packet Number exhaustion threshold */
specifier|volatile
name|uint8_t
name|res2
index|[
literal|56
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|rxsca
decl_stmt|;
comment|/**< RX SC access select */
specifier|volatile
name|uint8_t
name|res3
index|[
literal|60
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|txsca
decl_stmt|;
comment|/**< TX SC access select */
specifier|volatile
name|uint8_t
name|res4
index|[
literal|60
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* RX configuration, status and statistic */
specifier|volatile
name|uint32_t
name|rxsci1h
decl_stmt|;
comment|/**< RX Secure Channel Identifier first half */
specifier|volatile
name|uint32_t
name|rxsci2h
decl_stmt|;
comment|/**< RX Secure Channel Identifier second half */
specifier|volatile
name|uint8_t
name|res5
index|[
literal|8
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|ifio1hs
decl_stmt|;
comment|/**< ifInOctets first half Statistic */
specifier|volatile
name|uint32_t
name|ifio2hs
decl_stmt|;
comment|/**< ifInOctets second half Statistic */
specifier|volatile
name|uint32_t
name|ifiups
decl_stmt|;
comment|/**< ifInUcastPkts Statistic */
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
name|ifimps
decl_stmt|;
comment|/**< ifInMulticastPkts Statistic */
specifier|volatile
name|uint32_t
name|ifibps
decl_stmt|;
comment|/**< ifInBroadcastPkts Statistic */
specifier|volatile
name|uint32_t
name|rxsccfg
decl_stmt|;
comment|/**< RX Secure Channel configuration */
specifier|volatile
name|uint32_t
name|rpw
decl_stmt|;
comment|/**< replayWindow */
specifier|volatile
name|uint8_t
name|res7
index|[
literal|16
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|inov1hs
decl_stmt|;
comment|/**< InOctetsValidated first half Statistic */
specifier|volatile
name|uint32_t
name|inov2hs
decl_stmt|;
comment|/**< InOctetsValidated second half Statistic */
specifier|volatile
name|uint32_t
name|inod1hs
decl_stmt|;
comment|/**< InOctetsDecrypted first half Statistic */
specifier|volatile
name|uint32_t
name|inod2hs
decl_stmt|;
comment|/**< InOctetsDecrypted second half Statistic */
specifier|volatile
name|uint32_t
name|rxscipus
decl_stmt|;
comment|/**< RX Secure Channel InPktsUnchecked Statistic */
specifier|volatile
name|uint32_t
name|rxscipds
decl_stmt|;
comment|/**< RX Secure Channel InPktsDelayed Statistic */
specifier|volatile
name|uint32_t
name|rxscipls
decl_stmt|;
comment|/**< RX Secure Channel InPktsLate Statistic */
specifier|volatile
name|uint8_t
name|res8
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|rxaninuss
index|[
name|MAX_NUM_OF_SA_PER_SC
index|]
decl_stmt|;
comment|/**< RX AN 0-3 InNotUsingSA Statistic */
specifier|volatile
name|uint32_t
name|rxanipuss
index|[
name|MAX_NUM_OF_SA_PER_SC
index|]
decl_stmt|;
comment|/**< RX AN 0-3 InPktsUnusedSA Statistic */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|rxsacs
decl_stmt|;
comment|/**< RX Security Association configuration and status */
specifier|volatile
name|uint32_t
name|rxsanpn
decl_stmt|;
comment|/**< RX Security Association nextPN */
specifier|volatile
name|uint32_t
name|rxsalpn
decl_stmt|;
comment|/**< RX Security Association lowestPN */
specifier|volatile
name|uint32_t
name|rxsaipos
decl_stmt|;
comment|/**< RX Security Association InPktsOK Statistic */
specifier|volatile
name|uint32_t
name|rxsak
index|[
literal|4
index|]
decl_stmt|;
comment|/**< RX Security Association key (128 bit) */
specifier|volatile
name|uint32_t
name|rxsah
index|[
literal|4
index|]
decl_stmt|;
comment|/**< RX Security Association hash (128 bit) */
specifier|volatile
name|uint32_t
name|rxsaipis
decl_stmt|;
comment|/**< RX Security Association InPktsInvalid Statistic */
specifier|volatile
name|uint32_t
name|rxsaipnvs
decl_stmt|;
comment|/**< RX Security Association InPktsNotValid Statistic */
specifier|volatile
name|uint8_t
name|res9
index|[
literal|8
index|]
decl_stmt|;
comment|/**< reserved */
block|}
name|_PackedType
name|fmMacsecRxScSa
index|[
name|NUM_OF_SA_PER_RX_SC
index|]
struct|;
comment|/* TX configuration, status and statistic */
specifier|volatile
name|uint32_t
name|txsci1h
decl_stmt|;
comment|/**< TX Secure Channel Identifier first half */
specifier|volatile
name|uint32_t
name|txsci2h
decl_stmt|;
comment|/**< TX Secure Channel Identifier second half */
specifier|volatile
name|uint8_t
name|res10
index|[
literal|8
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|ifoo1hs
decl_stmt|;
comment|/**< ifOutOctets first half Statistic */
specifier|volatile
name|uint32_t
name|ifoo2hs
decl_stmt|;
comment|/**< ifOutOctets second half Statistic */
specifier|volatile
name|uint32_t
name|ifoups
decl_stmt|;
comment|/**< ifOutUcastPkts Statistic */
specifier|volatile
name|uint32_t
name|opus
decl_stmt|;
comment|/**< OutPktsUntagged Statistic */
specifier|volatile
name|uint32_t
name|ifomps
decl_stmt|;
comment|/**< ifOutMulticastPkts Statistic */
specifier|volatile
name|uint32_t
name|ifobps
decl_stmt|;
comment|/**< ifOutBroadcastPkts Statistic */
specifier|volatile
name|uint32_t
name|txsccfg
decl_stmt|;
comment|/**< TX Secure Channel configuration */
specifier|volatile
name|uint32_t
name|optls
decl_stmt|;
comment|/**< OutPktsTooLong Statistic */
specifier|volatile
name|uint8_t
name|res11
index|[
literal|16
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|oop1hs
decl_stmt|;
comment|/**< OutOctetsProtected first half Statistic */
specifier|volatile
name|uint32_t
name|oop2hs
decl_stmt|;
comment|/**< OutOctetsProtected second half Statistic */
specifier|volatile
name|uint32_t
name|ooe1hs
decl_stmt|;
comment|/**< OutOctetsEncrypted first half Statistic */
specifier|volatile
name|uint32_t
name|ooe2hs
decl_stmt|;
comment|/**< OutOctetsEncrypted second half Statistic */
specifier|volatile
name|uint8_t
name|res12
index|[
literal|48
index|]
decl_stmt|;
comment|/**< reserved */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|txsacs
decl_stmt|;
comment|/**< TX Security Association configuration and status */
specifier|volatile
name|uint32_t
name|txsanpn
decl_stmt|;
comment|/**< TX Security Association nextPN */
specifier|volatile
name|uint32_t
name|txsaopps
decl_stmt|;
comment|/**< TX Security Association OutPktsProtected Statistic */
specifier|volatile
name|uint32_t
name|txsaopes
decl_stmt|;
comment|/**< TX Security Association OutPktsEncrypted Statistic */
specifier|volatile
name|uint32_t
name|txsak
index|[
literal|4
index|]
decl_stmt|;
comment|/**< TX Security Association key (128 bit) */
specifier|volatile
name|uint32_t
name|txsah
index|[
literal|4
index|]
decl_stmt|;
comment|/**< TX Security Association hash (128 bit) */
specifier|volatile
name|uint8_t
name|res13
index|[
literal|16
index|]
decl_stmt|;
comment|/**< reserved */
block|}
name|_PackedType
name|fmMacsecTxScSa
index|[
name|NUM_OF_SA_PER_TX_SC
index|]
struct|;
specifier|volatile
name|uint8_t
name|res14
index|[
literal|248
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Global configuration and status */
specifier|volatile
name|uint32_t
name|ip_rev1
decl_stmt|;
comment|/**< MACsec IP Block Revision 1 register */
specifier|volatile
name|uint32_t
name|ip_rev2
decl_stmt|;
comment|/**< MACsec IP Block Revision 2 register */
specifier|volatile
name|uint32_t
name|evr
decl_stmt|;
comment|/**< MACsec Event Register */
specifier|volatile
name|uint32_t
name|ever
decl_stmt|;
comment|/**< MACsec Event Enable Register */
specifier|volatile
name|uint32_t
name|evfr
decl_stmt|;
comment|/**< MACsec Event Force Register */
specifier|volatile
name|uint32_t
name|err
decl_stmt|;
comment|/**< MACsec Error Register */
specifier|volatile
name|uint32_t
name|erer
decl_stmt|;
comment|/**< MACsec Error Enable Register */
specifier|volatile
name|uint32_t
name|erfr
decl_stmt|;
comment|/**< MACsec Error Force Register */
specifier|volatile
name|uint8_t
name|res15
index|[
literal|40
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|meec
decl_stmt|;
comment|/**< MACsec Memory ECC Error Capture Register */
specifier|volatile
name|uint32_t
name|idle
decl_stmt|;
comment|/**< MACsec Idle status Register */
specifier|volatile
name|uint8_t
name|res16
index|[
literal|184
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* DEBUG */
specifier|volatile
name|uint32_t
name|rxec
decl_stmt|;
comment|/**< MACsec RX error capture Register */
specifier|volatile
name|uint8_t
name|res17
index|[
literal|28
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|txec
decl_stmt|;
comment|/**< MACsec TX error capture Register */
specifier|volatile
name|uint8_t
name|res18
index|[
literal|220
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Macsec Rx global statistic */
specifier|volatile
name|uint32_t
name|ifiocp1hs
decl_stmt|;
comment|/**< ifInOctetsCp first half Statistic */
specifier|volatile
name|uint32_t
name|ifiocp2hs
decl_stmt|;
comment|/**< ifInOctetsCp second half Statistic */
specifier|volatile
name|uint32_t
name|ifiupcps
decl_stmt|;
comment|/**< ifInUcastPktsCp Statistic */
specifier|volatile
name|uint8_t
name|res19
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|ifioup1hs
decl_stmt|;
comment|/**< ifInOctetsUp first half Statistic */
specifier|volatile
name|uint32_t
name|ifioup2hs
decl_stmt|;
comment|/**< ifInOctetsUp second half Statistic */
specifier|volatile
name|uint32_t
name|ifiupups
decl_stmt|;
comment|/**< ifInUcastPktsUp Statistic */
specifier|volatile
name|uint8_t
name|res20
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|ifimpcps
decl_stmt|;
comment|/**< ifInMulticastPktsCp Statistic */
specifier|volatile
name|uint32_t
name|ifibpcps
decl_stmt|;
comment|/**< ifInBroadcastPktsCp Statistic */
specifier|volatile
name|uint32_t
name|ifimpups
decl_stmt|;
comment|/**< ifInMulticastPktsUp Statistic */
specifier|volatile
name|uint32_t
name|ifibpups
decl_stmt|;
comment|/**< ifInBroadcastPktsUp Statistic */
specifier|volatile
name|uint32_t
name|ipwts
decl_stmt|;
comment|/**< InPktsWithoutTag Statistic */
specifier|volatile
name|uint32_t
name|ipkays
decl_stmt|;
comment|/**< InPktsKaY Statistic */
specifier|volatile
name|uint32_t
name|ipbts
decl_stmt|;
comment|/**< InPktsBadTag Statistic */
specifier|volatile
name|uint32_t
name|ipsnfs
decl_stmt|;
comment|/**< InPktsSCINotFound Statistic */
specifier|volatile
name|uint32_t
name|ipuecs
decl_stmt|;
comment|/**< InPktsUnsupportedEC Statistic */
specifier|volatile
name|uint32_t
name|ipescbs
decl_stmt|;
comment|/**< InPktsEponSingleCopyBroadcast Statistic */
specifier|volatile
name|uint32_t
name|iptls
decl_stmt|;
comment|/**< InPktsTooLong Statistic */
specifier|volatile
name|uint8_t
name|res21
index|[
literal|52
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Macsec Tx global statistic */
specifier|volatile
name|uint32_t
name|opds
decl_stmt|;
comment|/**< OutPktsDiscarded Statistic */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
specifier|volatile
name|uint8_t
name|res22
index|[
literal|124
index|]
decl_stmt|;
comment|/**< reserved */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|rxsak
index|[
literal|8
index|]
decl_stmt|;
comment|/**< RX Security Association key (128/256 bit) */
specifier|volatile
name|uint8_t
name|res23
index|[
literal|32
index|]
decl_stmt|;
comment|/**< reserved */
block|}
name|_PackedType
name|rxScSaKey
index|[
name|NUM_OF_SA_PER_RX_SC
index|]
struct|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|txsak
index|[
literal|8
index|]
decl_stmt|;
comment|/**< TX Security Association key (128/256 bit) */
specifier|volatile
name|uint8_t
name|res24
index|[
literal|32
index|]
decl_stmt|;
comment|/**< reserved */
block|}
name|_PackedType
name|txScSaKey
index|[
name|NUM_OF_SA_PER_TX_SC
index|]
struct|;
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|_PackedType
name|t_FmMacsecRegs
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
name|SCI_HIGH_MASK
value|0xffffffff00000000LL
end_define

begin_define
define|#
directive|define
name|SCI_LOW_MASK
value|0x00000000ffffffffLL
end_define

begin_define
define|#
directive|define
name|LONG_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|GET_SCI_FIRST_HALF
parameter_list|(
name|sci
parameter_list|)
value|(uint32_t)((macsecSCI_t)((macsecSCI_t)(sci)& SCI_HIGH_MASK)>> LONG_SHIFT)
end_define

begin_define
define|#
directive|define
name|GET_SCI_SECOND_HALF
parameter_list|(
name|sci
parameter_list|)
value|(uint32_t)((macsecSCI_t)(sci)& SCI_LOW_MASK)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Configuration defines */
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
name|CFG_UECT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CFG_ESCBT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CFG_USFT
value|0x00000300
end_define

begin_define
define|#
directive|define
name|CFG_ITT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CFG_KFT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CFG_UFT
value|0x00000030
end_define

begin_define
define|#
directive|define
name|CFG_KSS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CFG_BYPN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CFG_S0I
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_TYPE
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|MFL_MAX_LEN
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|RXSCA_SC_SEL
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|TXSCA_SC_SEL
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|IP_REV_1_IP_ID
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|IP_REV_1_IP_MJ
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|IP_REV_1_IP_MM
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|IP_REV_2_IP_INT
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|IP_REV_2_IP_ERR
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|IP_REV_2_IP_CFG
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|MECC_CAP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MECC_CET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MECC_SERCNT
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|MECC_MEMADDR
value|0x000001ff
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|CFG_UECT_SHIFT
value|(31-20)
end_define

begin_define
define|#
directive|define
name|CFG_ESCBT_SHIFT
value|(31-21)
end_define

begin_define
define|#
directive|define
name|CFG_USFT_SHIFT
value|(31-23)
end_define

begin_define
define|#
directive|define
name|CFG_ITT_SHIFT
value|(31-24)
end_define

begin_define
define|#
directive|define
name|CFG_KFT_SHIFT
value|(31-25)
end_define

begin_define
define|#
directive|define
name|CFG_UFT_SHIFT
value|(31-27)
end_define

begin_define
define|#
directive|define
name|CFG_KSS_SHIFT
value|(31-29)
end_define

begin_define
define|#
directive|define
name|CFG_BYPN_SHIFT
value|(31-30)
end_define

begin_define
define|#
directive|define
name|CFG_S0I_SHIFT
value|(31-31)
end_define

begin_define
define|#
directive|define
name|IP_REV_1_IP_ID_SHIFT
value|(31-15)
end_define

begin_define
define|#
directive|define
name|IP_REV_1_IP_MJ_SHIFT
value|(31-23)
end_define

begin_define
define|#
directive|define
name|IP_REV_1_IP_MM_SHIFT
value|(31-31)
end_define

begin_define
define|#
directive|define
name|IP_REV_2_IP_INT_SHIFT
value|(31-15)
end_define

begin_define
define|#
directive|define
name|IP_REV_2_IP_ERR_SHIFT
value|(31-23)
end_define

begin_define
define|#
directive|define
name|IP_REV_2_IP_CFG_SHIFT
value|(31-31)
end_define

begin_define
define|#
directive|define
name|MECC_CAP_SHIFT
value|(31-0)
end_define

begin_define
define|#
directive|define
name|MECC_CET_SHIFT
value|(31-1)
end_define

begin_define
define|#
directive|define
name|MECC_SERCNT_SHIFT
value|(31-15)
end_define

begin_define
define|#
directive|define
name|MECC_MEMADDR_SHIFT
value|(31-31)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       RX SC defines */
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
name|RX_SCCFG_SCI_EN_MASK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RX_SCCFG_RP_MASK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RX_SCCFG_VF_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|RX_SCCFG_CO_MASK
value|0x0000003f
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|RX_SCCFG_SCI_EN_SHIFT
value|(31-20)
end_define

begin_define
define|#
directive|define
name|RX_SCCFG_RP_SHIFT
value|(31-21)
end_define

begin_define
define|#
directive|define
name|RX_SCCFG_VF_SHIFT
value|(31-23)
end_define

begin_define
define|#
directive|define
name|RX_SCCFG_CO_SHIFT
value|(31-31)
end_define

begin_define
define|#
directive|define
name|RX_SCCFG_CS_SHIFT
value|(31-7)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       RX SA defines */
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
name|RX_SACFG_ACTIVE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RX_SACFG_AN_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|RX_SACFG_EN_MASK
value|0x00000001
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|RX_SACFG_AN_SHIFT
value|(31-30)
end_define

begin_define
define|#
directive|define
name|RX_SACFG_EN_SHIFT
value|(31-31)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       TX SC defines */
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
name|TX_SCCFG_AN_MASK
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_ASA_MASK
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_SCE_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_CO_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_CE_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_PF_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_AIS_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_UES_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_USCB_MASK
value|0x00000001
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|TX_SCCFG_AN_SHIFT
value|(31-13)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_ASA_SHIFT
value|(31-14)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_SCE_SHIFT
value|(31-15)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_CO_SHIFT
value|(31-23)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_CE_SHIFT
value|(31-27)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_PF_SHIFT
value|(31-28)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_AIS_SHIFT
value|(31-29)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_UES_SHIFT
value|(31-30)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_USCB_SHIFT
value|(31-31)
end_define

begin_define
define|#
directive|define
name|TX_SCCFG_CS_SHIFT
value|(31-7)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       TX SA defines */
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
name|TX_SACFG_ACTIVE
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
name|id
parameter_list|)
function_decl|;
name|t_Handle
name|h_SrcHandle
decl_stmt|;
block|}
name|t_FmMacsecIntrSrc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|e_FmMacsecUnknownSciFrameTreatment
name|unknownSciTreatMode
decl_stmt|;
name|bool
name|invalidTagsDeliverUncontrolled
decl_stmt|;
name|bool
name|changedTextWithNoEncryptDeliverUncontrolled
decl_stmt|;
name|bool
name|onlyScbIsSetDeliverUncontrolled
decl_stmt|;
name|bool
name|encryptWithNoChangedTextDiscardUncontrolled
decl_stmt|;
name|e_FmMacsecUntagFrameTreatment
name|untagTreatMode
decl_stmt|;
name|uint32_t
name|pnExhThr
decl_stmt|;
name|bool
name|keysUnreadable
decl_stmt|;
name|bool
name|byPassMode
decl_stmt|;
name|bool
name|reservedSc0
decl_stmt|;
name|uint32_t
name|sectagOverhead
decl_stmt|;
name|uint32_t
name|mflSubtract
decl_stmt|;
block|}
name|t_FmMacsecDriverParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmMacsecControllerDriver
name|fmMacsecControllerDriver
decl_stmt|;
name|t_Handle
name|h_Fm
decl_stmt|;
name|t_FmMacsecRegs
modifier|*
name|p_FmMacsecRegs
decl_stmt|;
name|t_Handle
name|h_FmMac
decl_stmt|;
comment|/**< A handle to the FM MAC object  related to */
name|char
name|fmMacsecModuleName
index|[
name|MODULE_NAME_SIZE
index|]
decl_stmt|;
name|t_FmMacsecIntrSrc
name|intrMng
index|[
name|NUM_OF_INTER_MODULE_EVENTS
index|]
decl_stmt|;
name|uint32_t
name|events
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|uint32_t
name|userExceptions
decl_stmt|;
name|t_FmMacsecExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< Exception Callback Routine         */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                              be passed by the driver upon calling the above callbacks */
name|bool
name|rxScTable
index|[
name|NUM_OF_RX_SC
index|]
decl_stmt|;
name|uint32_t
name|numRxScAvailable
decl_stmt|;
name|bool
name|txScTable
index|[
name|NUM_OF_TX_SC
index|]
decl_stmt|;
name|uint32_t
name|numTxScAvailable
decl_stmt|;
name|t_Handle
name|rxScSpinLock
decl_stmt|;
name|t_Handle
name|txScSpinLock
decl_stmt|;
name|t_FmMacsecDriverParam
modifier|*
name|p_FmMacsecDriverParam
decl_stmt|;
block|}
name|t_FmMacsec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_MACSEC_MASTER_H */
end_comment

end_unit

