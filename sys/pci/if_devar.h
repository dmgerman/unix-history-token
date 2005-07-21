begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_devar.h,v 1.32 1999/04/01 14:55:25 tsubai Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994-1997 Matt Thomas (matt@3am-software.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Id: if_devar.h,v 1.28 1997/07/03 16:55:07 thomas Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEVAR_H
end_define

begin_typedef
typedef|typedef
name|bus_addr_t
name|tulip_csrptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TULIP_PCI_CSRSIZE
value|8
end_define

begin_define
define|#
directive|define
name|TULIP_PCI_CSROFFSET
value|0
end_define

begin_define
define|#
directive|define
name|TULIP_CSR_READ
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|)
define|\
value|bus_space_read_4((sc)->tulip_csrs_bst,	\ 			 (sc)->tulip_csrs_bsh,	\ 			 (sc)->tulip_csrs.csr)
end_define

begin_define
define|#
directive|define
name|TULIP_CSR_WRITE
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->tulip_csrs_bst,		\ 			  (sc)->tulip_csrs_bsh,		\ 			  (sc)->tulip_csrs.csr, val)
end_define

begin_define
define|#
directive|define
name|TULIP_CSR_READBYTE
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|)
define|\
value|bus_space_read_1((sc)->tulip_csrs_bst,	\ 			 (sc)->tulip_csrs_bsh,	\ 			 (sc)->tulip_csrs.csr)
end_define

begin_define
define|#
directive|define
name|TULIP_CSR_WRITEBYTE
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->tulip_csrs_bst,		\ 			  (sc)->tulip_csrs_bsh,		\ 			  (sc)->tulip_csrs.csr, val)
end_define

begin_comment
comment|/*  * This structure contains "pointers" for the registers on  * the various 21x4x chips.  CSR0 through CSR8 are common  * to all chips.  After that, it gets messy...  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|tulip_csrptr_t
name|csr_busmode
decl_stmt|;
comment|/* CSR0 */
name|tulip_csrptr_t
name|csr_txpoll
decl_stmt|;
comment|/* CSR1 */
name|tulip_csrptr_t
name|csr_rxpoll
decl_stmt|;
comment|/* CSR2 */
name|tulip_csrptr_t
name|csr_rxlist
decl_stmt|;
comment|/* CSR3 */
name|tulip_csrptr_t
name|csr_txlist
decl_stmt|;
comment|/* CSR4 */
name|tulip_csrptr_t
name|csr_status
decl_stmt|;
comment|/* CSR5 */
name|tulip_csrptr_t
name|csr_command
decl_stmt|;
comment|/* CSR6 */
name|tulip_csrptr_t
name|csr_intr
decl_stmt|;
comment|/* CSR7 */
name|tulip_csrptr_t
name|csr_missed_frames
decl_stmt|;
comment|/* CSR8 */
name|tulip_csrptr_t
name|csr_9
decl_stmt|;
comment|/* CSR9 */
name|tulip_csrptr_t
name|csr_10
decl_stmt|;
comment|/* CSR10 */
name|tulip_csrptr_t
name|csr_11
decl_stmt|;
comment|/* CSR11 */
name|tulip_csrptr_t
name|csr_12
decl_stmt|;
comment|/* CSR12 */
name|tulip_csrptr_t
name|csr_13
decl_stmt|;
comment|/* CSR13 */
name|tulip_csrptr_t
name|csr_14
decl_stmt|;
comment|/* CSR14 */
name|tulip_csrptr_t
name|csr_15
decl_stmt|;
comment|/* CSR15 */
block|}
name|tulip_regfile_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|csr_enetrom
value|csr_9
end_define

begin_comment
comment|/* 21040 */
end_comment

begin_define
define|#
directive|define
name|csr_reserved
value|csr_10
end_define

begin_comment
comment|/* 21040 */
end_comment

begin_define
define|#
directive|define
name|csr_full_duplex
value|csr_11
end_define

begin_comment
comment|/* 21040 */
end_comment

begin_define
define|#
directive|define
name|csr_bootrom
value|csr_10
end_define

begin_comment
comment|/* 21041/21140A/?? */
end_comment

begin_define
define|#
directive|define
name|csr_gp
value|csr_12
end_define

begin_comment
comment|/* 21140* */
end_comment

begin_define
define|#
directive|define
name|csr_watchdog
value|csr_15
end_define

begin_comment
comment|/* 21140* */
end_comment

begin_define
define|#
directive|define
name|csr_gp_timer
value|csr_11
end_define

begin_comment
comment|/* 21041/21140* */
end_comment

begin_define
define|#
directive|define
name|csr_srom_mii
value|csr_9
end_define

begin_comment
comment|/* 21041/21140* */
end_comment

begin_define
define|#
directive|define
name|csr_sia_status
value|csr_12
end_define

begin_comment
comment|/* 2104x */
end_comment

begin_define
define|#
directive|define
name|csr_sia_connectivity
value|csr_13
end_define

begin_comment
comment|/* 2104x */
end_comment

begin_define
define|#
directive|define
name|csr_sia_tx_rx
value|csr_14
end_define

begin_comment
comment|/* 2104x */
end_comment

begin_define
define|#
directive|define
name|csr_sia_general
value|csr_15
end_define

begin_comment
comment|/* 2104x */
end_comment

begin_comment
comment|/*  * While 21x4x allows chaining of its descriptors, this driver  * doesn't take advantage of it.  We keep the descriptors in a  * traditional FIFO ring.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|tulip_desc_t
modifier|*
name|ri_first
decl_stmt|;
comment|/* first entry in ring */
name|tulip_desc_t
modifier|*
name|ri_last
decl_stmt|;
comment|/* one after last entry */
name|tulip_desc_t
modifier|*
name|ri_nextin
decl_stmt|;
comment|/* next to processed by host */
name|tulip_desc_t
modifier|*
name|ri_nextout
decl_stmt|;
comment|/* next to processed by adapter */
name|int
name|ri_max
decl_stmt|;
name|int
name|ri_free
decl_stmt|;
block|}
name|tulip_ringinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * The 21040 has a stupid restriction in that the receive  * buffers must be longword aligned.  But since Ethernet  * headers are not a multiple of longwords in size this forces  * the data to non-longword aligned.  Since IP requires the  * data to be longword aligned, we need to copy it after it has  * been DMA'ed in our memory.  *  * Since we have to copy it anyways, we might as well as allocate  * dedicated receive space for the input.  This allows to use a  * small receive buffer size and more ring entries to be able to  * better keep with a flood of tiny Ethernet packets.  *  * The receive space MUST ALWAYS be a multiple of the page size.  * And the number of receive descriptors multiplied by the size  * of the receive buffers must equal the receive space.  This  * is so that we can manipulate the page tables so that even if a  * packet wraps around the end of the receive space, we can  * treat it as virtually contiguous.  *  * The above used to be true (the stupid restriction is still true)  * but we gone to directly DMA'ing into MBUFs (unless it's on an  * architecture which can't handle unaligned accesses) because with  * 100Mb/s cards the copying is just too much of a hit.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TULIP_COPY_RXDATA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TULIP_DATA_PER_DESC
value|2032
end_define

begin_define
define|#
directive|define
name|TULIP_TXTIMER
value|4
end_define

begin_define
define|#
directive|define
name|TULIP_RXDESCS
value|48
end_define

begin_define
define|#
directive|define
name|TULIP_TXDESCS
value|128
end_define

begin_define
define|#
directive|define
name|TULIP_RXQ_TARGET
value|32
end_define

begin_if
if|#
directive|if
name|TULIP_RXQ_TARGET
operator|>=
name|TULIP_RXDESCS
end_if

begin_error
error|#
directive|error
error|TULIP_RXQ_TARGET must be less than TULIP_RXDESCS
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TULIP_RX_BUFLEN
value|((MCLBYTES< 2048 ? MCLBYTES : 2048) - 16)
end_define

begin_comment
comment|/*  * Forward reference to make C happy.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|tulip_softc
name|tulip_softc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Enumeration of the various controllers supported.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TULIP_21040
block|,
name|TULIP_21041
block|,
name|TULIP_21140
block|,
name|TULIP_21140A
block|,
name|TULIP_21142
block|,
name|TULIP_21143
block|,
name|TULIP_CHIPID_UNKNOWN
block|}
name|tulip_chipid_t
typedef|;
end_typedef

begin_comment
comment|/*  * Various physical media types supported.  * BNCAUI is BNC or AUI since on the 21040 you can't really tell  * which is in use.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TULIP_MEDIA_UNKNOWN
block|,
name|TULIP_MEDIA_10BASET
block|,
name|TULIP_MEDIA_10BASET_FD
block|,
name|TULIP_MEDIA_BNC
block|,
name|TULIP_MEDIA_AUI
block|,
name|TULIP_MEDIA_EXTSIA
block|,
name|TULIP_MEDIA_AUIBNC
block|,
name|TULIP_MEDIA_100BASETX
block|,
name|TULIP_MEDIA_100BASETX_FD
block|,
name|TULIP_MEDIA_100BASET4
block|,
name|TULIP_MEDIA_100BASEFX
block|,
name|TULIP_MEDIA_100BASEFX_FD
block|,
name|TULIP_MEDIA_MAX
block|}
name|tulip_media_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TULIP_BIT
parameter_list|(
name|b
parameter_list|)
value|(1L<< ((int)(b)))
end_define

begin_define
define|#
directive|define
name|TULIP_FDBIT
parameter_list|(
name|m
parameter_list|)
value|(1L<< ((int)TULIP_MEDIA_ ## m ## _FD))
end_define

begin_define
define|#
directive|define
name|TULIP_MBIT
parameter_list|(
name|m
parameter_list|)
value|(1L<< ((int)TULIP_MEDIA_ ## m ))
end_define

begin_define
define|#
directive|define
name|TULIP_IS_MEDIA_FD
parameter_list|(
name|m
parameter_list|)
value|(TULIP_BIT(m)& \ 				 (TULIP_FDBIT(10BASET) | \ 				  TULIP_FDBIT(100BASETX) | \ 				  TULIP_FDBIT(100BASEFX)))
end_define

begin_define
define|#
directive|define
name|TULIP_CAN_MEDIA_FD
parameter_list|(
name|m
parameter_list|)
value|(TULIP_BIT(m)& \ 				 (TULIP_MBIT(10BASET) | \ 				  TULIP_MBIT(100BASETX) | \ 				  TULIP_MBIT(100BASEFX)))
end_define

begin_define
define|#
directive|define
name|TULIP_FD_MEDIA_OF
parameter_list|(
name|m
parameter_list|)
value|((tulip_media_t)((m) + 1))
end_define

begin_define
define|#
directive|define
name|TULIP_HD_MEDIA_OF
parameter_list|(
name|m
parameter_list|)
value|((tulip_media_t)((m) - 1))
end_define

begin_define
define|#
directive|define
name|TULIP_IS_MEDIA_100MB
parameter_list|(
name|m
parameter_list|)
value|((m)>= TULIP_MEDIA_100BASETX)
end_define

begin_define
define|#
directive|define
name|TULIP_IS_MEDIA_TP
parameter_list|(
name|m
parameter_list|)
value|((TULIP_BIT(m)& \ 				  (TULIP_MBIT(BNC) | \ 				   TULIP_MBIT(AUI) | \ 				   TULIP_MBIT(AUIBNC) | \ 				   TULIP_MBIT(EXTSIA))) == 0)
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_ATTR_MII
value|0x0100
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_ATTR_NWAY
value|0x0200
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_ATTR_AUTOSENSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_ATTR_POWERUP
value|0x0800
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_ATTR_NOLINKPASS
value|0x1000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
enum|enum
block|{
name|TULIP_MEDIAINFO_NONE
block|,
name|TULIP_MEDIAINFO_SIA
block|,
name|TULIP_MEDIAINFO_GPR
block|,
name|TULIP_MEDIAINFO_MII
block|,
name|TULIP_MEDIAINFO_RESET
block|,
name|TULIP_MEDIAINFO_SYM
block|}
name|mi_type
enum|;
union|union
block|{
struct|struct
block|{
name|u_int16_t
name|sia_connectivity
decl_stmt|;
name|u_int16_t
name|sia_tx_rx
decl_stmt|;
name|u_int16_t
name|sia_general
decl_stmt|;
name|u_int32_t
name|sia_gp_control
decl_stmt|;
comment|/* 21142/21143 */
name|u_int32_t
name|sia_gp_data
decl_stmt|;
comment|/* 21142/21143 */
block|}
name|un_sia
struct|;
struct|struct
block|{
name|u_int32_t
name|gpr_cmdmode
decl_stmt|;
name|u_int32_t
name|gpr_gpcontrol
decl_stmt|;
comment|/* 21142/21143 */
name|u_int32_t
name|gpr_gpdata
decl_stmt|;
name|u_int8_t
name|gpr_actmask
decl_stmt|;
name|u_int8_t
name|gpr_actdata
decl_stmt|;
name|u_int
name|gpr_default
range|:
literal|1
decl_stmt|;
block|}
name|un_gpr
struct|;
struct|struct
block|{
name|u_int32_t
name|mii_mediamask
decl_stmt|;
name|u_int16_t
name|mii_capabilities
decl_stmt|;
name|u_int16_t
name|mii_advertisement
decl_stmt|;
name|u_int16_t
name|mii_full_duplex
decl_stmt|;
name|u_int16_t
name|mii_tx_threshold
decl_stmt|;
name|u_int16_t
name|mii_interrupt
decl_stmt|;
comment|/* 21142/21143 */
name|u_int8_t
name|mii_phyaddr
decl_stmt|;
name|u_int8_t
name|mii_gpr_length
decl_stmt|;
name|u_int8_t
name|mii_gpr_offset
decl_stmt|;
name|u_int8_t
name|mii_reset_length
decl_stmt|;
name|u_int8_t
name|mii_reset_offset
decl_stmt|;
name|u_int32_t
name|mii_phyid
decl_stmt|;
block|}
name|un_mii
struct|;
block|}
name|mi_un
union|;
block|}
name|tulip_media_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mi_sia_connectivity
value|mi_un.un_sia.sia_connectivity
end_define

begin_define
define|#
directive|define
name|mi_sia_tx_rx
value|mi_un.un_sia.sia_tx_rx
end_define

begin_define
define|#
directive|define
name|mi_sia_general
value|mi_un.un_sia.sia_general
end_define

begin_define
define|#
directive|define
name|mi_sia_gp_control
value|mi_un.un_sia.sia_gp_control
end_define

begin_define
define|#
directive|define
name|mi_sia_gp_data
value|mi_un.un_sia.sia_gp_data
end_define

begin_define
define|#
directive|define
name|mi_gpcontrol
value|mi_un.un_gpr.gpr_gpcontrol
end_define

begin_define
define|#
directive|define
name|mi_gpdata
value|mi_un.un_gpr.gpr_gpdata
end_define

begin_define
define|#
directive|define
name|mi_actmask
value|mi_un.un_gpr.gpr_actmask
end_define

begin_define
define|#
directive|define
name|mi_actdata
value|mi_un.un_gpr.gpr_actdata
end_define

begin_define
define|#
directive|define
name|mi_default
value|mi_un.un_gpr.gpr_default
end_define

begin_define
define|#
directive|define
name|mi_cmdmode
value|mi_un.un_gpr.gpr_cmdmode
end_define

begin_define
define|#
directive|define
name|mi_phyaddr
value|mi_un.un_mii.mii_phyaddr
end_define

begin_define
define|#
directive|define
name|mi_gpr_length
value|mi_un.un_mii.mii_gpr_length
end_define

begin_define
define|#
directive|define
name|mi_gpr_offset
value|mi_un.un_mii.mii_gpr_offset
end_define

begin_define
define|#
directive|define
name|mi_reset_length
value|mi_un.un_mii.mii_reset_length
end_define

begin_define
define|#
directive|define
name|mi_reset_offset
value|mi_un.un_mii.mii_reset_offset
end_define

begin_define
define|#
directive|define
name|mi_capabilities
value|mi_un.un_mii.mii_capabilities
end_define

begin_define
define|#
directive|define
name|mi_advertisement
value|mi_un.un_mii.mii_advertisement
end_define

begin_define
define|#
directive|define
name|mi_full_duplex
value|mi_un.un_mii.mii_full_duplex
end_define

begin_define
define|#
directive|define
name|mi_tx_threshold
value|mi_un.un_mii.mii_tx_threshold
end_define

begin_define
define|#
directive|define
name|mi_mediamask
value|mi_un.un_mii.mii_mediamask
end_define

begin_define
define|#
directive|define
name|mi_mii_interrupt
value|mi_un.un_mii.mii_interrupt
end_define

begin_define
define|#
directive|define
name|mi_phyid
value|mi_un.un_mii.mii_phyid
end_define

begin_define
define|#
directive|define
name|TULIP_MEDIAINFO_SIA_INIT
parameter_list|(
name|sc
parameter_list|,
name|mi
parameter_list|,
name|chipid
parameter_list|,
name|media
parameter_list|)
value|do {		\ 	(mi)->mi_type = TULIP_MEDIAINFO_SIA;				\ 	sc->tulip_mediums[TULIP_MEDIA_ ## media] = (mi);		\ 	(mi)->mi_sia_connectivity = TULIP_ ## chipid ## _SIACONN_ ## media; \ 	(mi)->mi_sia_tx_rx = TULIP_ ## chipid ## _SIATXRX_ ## media;	\ 	(mi)->mi_sia_general = TULIP_ ## chipid ## _SIAGEN_ ## media;	\ } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_MEDIAINFO_ADD_CAPABILITY
parameter_list|(
name|sc
parameter_list|,
name|mi
parameter_list|,
name|media
parameter_list|)
value|do {		\ 	if ((sc)->tulip_mediums[TULIP_MEDIA_ ## media] == NULL		\&& ((mi)->mi_capabilities& PHYSTS_ ## media)) {		\ 		(sc)->tulip_mediums[TULIP_MEDIA_ ## media] = (mi);	\ 		(mi)->mi_mediamask |= TULIP_BIT(TULIP_MEDIA_ ## media);	\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_MII_NOPHY
value|32
end_define

begin_comment
comment|/*  * Some boards need to treated specially.  The following enumeration  * identifies the cards with quirks (or those we just want to single  * out for special merit or scorn).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TULIP_21040_GENERIC
block|,
comment|/* Generic 21040 (works with most any board) */
name|TULIP_21140_ISV
block|,
comment|/* Digital Semicondutor 21140 ISV SROM Format */
name|TULIP_21142_ISV
block|,
comment|/* Digital Semicondutor 21142 ISV SROM Format */
name|TULIP_21143_ISV
block|,
comment|/* Digital Semicondutor 21143 ISV SROM Format */
name|TULIP_21140_DEC_EB
block|,
comment|/* Digital Semicondutor 21140 Eval. Board */
name|TULIP_21140_MII
block|,
comment|/* 21140[A] with MII */
name|TULIP_21140_DEC_DE500
block|,
comment|/* Digital DE500-?? 10/100 */
name|TULIP_21140_SMC_9332
block|,
comment|/* SMC 9332 */
name|TULIP_21140_COGENT_EM100
block|,
comment|/* Cogent EM100 100 only */
name|TULIP_21140_ZNYX_ZX34X
block|,
comment|/* ZNYX ZX342 10/100 */
name|TULIP_21140_ASANTE
block|,
comment|/* AsanteFast 10/100 */
name|TULIP_21140_EN1207
block|,
comment|/* Accton EN2107 10/100 BNC */
name|TULIP_21041_GENERIC
comment|/* Generic 21041 card */
block|}
name|tulip_board_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TULIP_MEDIAPOLL_TIMER
block|,
comment|/* 100ms timer fired */
name|TULIP_MEDIAPOLL_FASTTIMER
block|,
comment|/*<100ms timer fired */
name|TULIP_MEDIAPOLL_LINKFAIL
block|,
comment|/* called from interrupt routine */
name|TULIP_MEDIAPOLL_LINKPASS
block|,
comment|/* called from interrupt routine */
name|TULIP_MEDIAPOLL_START
block|,
comment|/* start a media probe (from reset) */
name|TULIP_MEDIAPOLL_TXPROBE_OK
block|,
comment|/* txprobe succeeded */
name|TULIP_MEDIAPOLL_TXPROBE_FAILED
block|,
comment|/* txprobe failed */
name|TULIP_MEDIAPOLL_MAX
block|}
name|tulip_mediapoll_event_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TULIP_LINK_DOWN
block|,
comment|/* Link is down */
name|TULIP_LINK_UP
block|,
comment|/* link is ok */
name|TULIP_LINK_UNKNOWN
comment|/* we can't tell either way */
block|}
name|tulip_link_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * This data structure is used to abstract out the quirks.  * media_probe  = tries to determine the media type.  * media_select = enables the current media (or autosenses)  * media_poll	= autosenses media  * media_preset = 21140, etal requires bit to set before the  *		  the software reset; hence pre-set.  Should be  *		  pre-reset but that's ugly.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|tulip_board_t
name|bd_type
decl_stmt|;
name|void
function_decl|(
modifier|*
name|bd_media_probe
function_decl|)
parameter_list|(
name|tulip_softc_t
modifier|*
specifier|const
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bd_media_select
function_decl|)
parameter_list|(
name|tulip_softc_t
modifier|*
specifier|const
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bd_media_poll
function_decl|)
parameter_list|(
name|tulip_softc_t
modifier|*
specifier|const
name|sc
parameter_list|,
name|tulip_mediapoll_event_t
name|event
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bd_media_preset
function_decl|)
parameter_list|(
name|tulip_softc_t
modifier|*
specifier|const
name|sc
parameter_list|)
function_decl|;
block|}
name|tulip_boardsw_t
typedef|;
end_typedef

begin_comment
comment|/*  * The next few declarations are for MII/PHY based boards.  *  *    The first enumeration identifies a superset of various datums  * that can be obtained from various PHY chips.  Not all PHYs will  * support all datums.  *    The modedata structure indicates what register contains  * a datum, what mask is applied the register contents, and what the  * result should be.  *    The attr structure records information about a supported PHY.  *    The phy structure records information about a PHY instance.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHY_MODE_10T
block|,
name|PHY_MODE_100TX
block|,
name|PHY_MODE_100T4
block|,
name|PHY_MODE_FULLDUPLEX
block|,
name|PHY_MODE_MAX
block|}
name|tulip_phy_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|pm_regno
decl_stmt|;
name|u_int16_t
name|pm_mask
decl_stmt|;
name|u_int16_t
name|pm_value
decl_stmt|;
block|}
name|tulip_phy_modedata_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|attr_id
decl_stmt|;
name|u_int16_t
name|attr_flags
decl_stmt|;
name|tulip_phy_modedata_t
name|attr_modes
index|[
name|PHY_MODE_MAX
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|TULIP_DEBUG
specifier|const
name|char
modifier|*
name|attr_name
decl_stmt|;
endif|#
directive|endif
block|}
name|tulip_phy_attr_t
typedef|;
end_typedef

begin_comment
comment|/* Definitions for tulip_phy_attr_t.attr_flags */
end_comment

begin_define
define|#
directive|define
name|PHY_NEED_HARD_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|PHY_DUAL_CYCLE_TA
value|0x0002
end_define

begin_comment
comment|/*  * Various probe states used when trying to autosense the media.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TULIP_PROBE_INACTIVE
block|,
name|TULIP_PROBE_PHYRESET
block|,
name|TULIP_PROBE_PHYAUTONEG
block|,
name|TULIP_PROBE_GPRTEST
block|,
name|TULIP_PROBE_MEDIATEST
block|,
name|TULIP_PROBE_FAILED
block|}
name|tulip_probe_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 	 * Transmit Statistics 	 */
name|u_int32_t
name|dot3StatsSingleCollisionFrames
decl_stmt|;
name|u_int32_t
name|dot3StatsMultipleCollisionFrames
decl_stmt|;
name|u_int32_t
name|dot3StatsSQETestErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsDeferredTransmissions
decl_stmt|;
name|u_int32_t
name|dot3StatsLateCollisions
decl_stmt|;
name|u_int32_t
name|dot3StatsExcessiveCollisions
decl_stmt|;
name|u_int32_t
name|dot3StatsCarrierSenseErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsInternalMacTransmitErrors
decl_stmt|;
comment|/* not in rfc1650! */
name|u_int32_t
name|dot3StatsInternalTransmitUnderflows
decl_stmt|;
comment|/* not in rfc1650! */
name|u_int32_t
name|dot3StatsInternalTransmitBabbles
decl_stmt|;
comment|/* 	 * Receive Statistics 	 */
name|u_int32_t
name|dot3StatsMissedFrames
decl_stmt|;
comment|/* not in rfc1650! */
name|u_int32_t
name|dot3StatsAlignmentErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsFCSErrors
decl_stmt|;
name|u_int32_t
name|dot3StatsFrameTooLongs
decl_stmt|;
name|u_int32_t
name|dot3StatsInternalMacReceiveErrors
decl_stmt|;
block|}
name|tulip_dot3_stats_t
typedef|;
end_typedef

begin_comment
comment|/*  * Probe information.  */
end_comment

begin_struct
struct|struct
name|tulip_probe_info
block|{
name|u_int8_t
name|probe_count
decl_stmt|;
comment|/* count of probe operations */
name|int32_t
name|probe_timeout
decl_stmt|;
comment|/* time (ms) of probe timeout */
name|tulip_probe_state_t
name|probe_state
decl_stmt|;
comment|/* current media probe state */
name|tulip_media_t
name|probe_media
decl_stmt|;
comment|/* current media being probed */
name|u_int32_t
name|probe_mediamask
decl_stmt|;
comment|/* medias checked */
name|u_int32_t
name|probe_passes
decl_stmt|;
comment|/* times autosense failed */
name|u_int32_t
name|probe_txprobes
decl_stmt|;
comment|/* txprobes attempted */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debugging/Statistical information.  */
end_comment

begin_struct
struct|struct
name|tulip_dbg_info
block|{
name|tulip_media_t
name|dbg_last_media
decl_stmt|;
name|u_int32_t
name|dbg_intrs
decl_stmt|;
name|u_int32_t
name|dbg_media_probes
decl_stmt|;
name|u_int32_t
name|dbg_txprobe_nocarr
decl_stmt|;
name|u_int32_t
name|dbg_txprobe_exccoll
decl_stmt|;
name|u_int32_t
name|dbg_link_downed
decl_stmt|;
name|u_int32_t
name|dbg_link_suspected
decl_stmt|;
name|u_int32_t
name|dbg_link_intrs
decl_stmt|;
name|u_int32_t
name|dbg_link_pollintrs
decl_stmt|;
name|u_int32_t
name|dbg_link_failures
decl_stmt|;
name|u_int32_t
name|dbg_nway_starts
decl_stmt|;
name|u_int32_t
name|dbg_nway_failures
decl_stmt|;
name|u_int16_t
name|dbg_phyregs
index|[
literal|32
index|]
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|dbg_rxlowbufs
decl_stmt|;
name|u_int32_t
name|dbg_rxintrs
decl_stmt|;
name|u_int32_t
name|dbg_last_rxintrs
decl_stmt|;
name|u_int32_t
name|dbg_high_rxintrs_hz
decl_stmt|;
name|u_int32_t
name|dbg_no_txmaps
decl_stmt|;
name|u_int32_t
name|dbg_txput_finishes
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|dbg_txprobes_ok
index|[
name|TULIP_MEDIA_MAX
index|]
decl_stmt|;
name|u_int32_t
name|dbg_txprobes_failed
index|[
name|TULIP_MEDIA_MAX
index|]
decl_stmt|;
name|u_int32_t
name|dbg_events
index|[
name|TULIP_MEDIAPOLL_MAX
index|]
decl_stmt|;
name|u_int32_t
name|dbg_rxpktsperintr
index|[
name|TULIP_RXDESCS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Performance statistics.  */
end_comment

begin_struct
struct|struct
name|tulip_perfstat
block|{
name|u_quad_t
name|perf_intr_cycles
decl_stmt|;
name|u_quad_t
name|perf_ifstart_cycles
decl_stmt|;
name|u_quad_t
name|perf_ifstart_one_cycles
decl_stmt|;
name|u_quad_t
name|perf_ifioctl_cycles
decl_stmt|;
name|u_quad_t
name|perf_ifwatchdog_cycles
decl_stmt|;
name|u_quad_t
name|perf_timeout_cycles
decl_stmt|;
name|u_quad_t
name|perf_txput_cycles
decl_stmt|;
name|u_quad_t
name|perf_txintr_cycles
decl_stmt|;
name|u_quad_t
name|perf_rxintr_cycles
decl_stmt|;
name|u_quad_t
name|perf_rxget_cycles
decl_stmt|;
name|unsigned
name|int
name|perf_intr
decl_stmt|;
name|unsigned
name|int
name|perf_ifstart
decl_stmt|;
name|unsigned
name|int
name|perf_ifstart_one
decl_stmt|;
name|unsigned
name|int
name|perf_ifioctl
decl_stmt|;
name|unsigned
name|int
name|perf_ifwatchdog
decl_stmt|;
name|unsigned
name|int
name|perf_timeout
decl_stmt|;
name|unsigned
name|int
name|perf_txput
decl_stmt|;
name|unsigned
name|int
name|perf_txintr
decl_stmt|;
name|unsigned
name|int
name|perf_rxintr
decl_stmt|;
name|unsigned
name|int
name|perf_rxget
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TULIP_PERF_CURRENT
value|0
end_define

begin_define
define|#
directive|define
name|TULIP_PERF_PREVIOUS
value|1
end_define

begin_define
define|#
directive|define
name|TULIP_PERF_TOTAL
value|2
end_define

begin_define
define|#
directive|define
name|TULIP_PERF_MAX
value|3
end_define

begin_comment
comment|/*  * Per-driver-instance state.  */
end_comment

begin_struct
struct|struct
name|tulip_softc
block|{
name|struct
name|ifmedia
name|tulip_ifmedia
decl_stmt|;
name|int
name|tulip_unit
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|TULIP_BUS_DMA
argument_list|)
name|bus_dma_tag_t
name|tulip_dmatag
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TULIP_BUS_DMA_NOTX
argument_list|)
name|bus_dmamap_t
name|tulip_setupmap
decl_stmt|;
name|bus_dmamap_t
name|tulip_txdescmap
decl_stmt|;
name|bus_dmamap_t
name|tulip_txmaps
index|[
name|TULIP_TXDESCS
index|]
decl_stmt|;
name|unsigned
name|int
name|tulip_txmaps_free
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TULIP_BUS_DMA_NORX
argument_list|)
name|bus_dmamap_t
name|tulip_rxdescmap
decl_stmt|;
name|bus_dmamap_t
name|tulip_rxmaps
index|[
name|TULIP_RXDESCS
index|]
decl_stmt|;
name|unsigned
name|int
name|tulip_rxmaps_free
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|struct
name|ifnet
modifier|*
name|tulip_ifp
decl_stmt|;
name|u_char
name|tulip_enaddr
index|[
literal|6
index|]
decl_stmt|;
name|bus_space_tag_t
name|tulip_csrs_bst
decl_stmt|;
name|bus_space_handle_t
name|tulip_csrs_bsh
decl_stmt|;
name|tulip_regfile_t
name|tulip_csrs
decl_stmt|;
name|u_int32_t
name|tulip_flags
decl_stmt|;
name|u_int32_t
name|tulip_features
decl_stmt|;
name|u_int32_t
name|tulip_intrmask
decl_stmt|;
name|u_int32_t
name|tulip_cmdmode
decl_stmt|;
name|u_int32_t
name|tulip_last_system_error
range|:
literal|3
decl_stmt|;
name|u_int32_t
name|tulip_txtimer
range|:
literal|2
decl_stmt|;
comment|/* transmission timer */
name|u_int32_t
name|tulip_system_errors
decl_stmt|;
name|u_int32_t
name|tulip_statusbits
decl_stmt|;
comment|/* status bits from 							 * CSR5 that may need 							 * to be printed 							 */
name|tulip_media_info_t
modifier|*
name|tulip_mediums
index|[
name|TULIP_MEDIA_MAX
index|]
decl_stmt|;
name|tulip_media_t
name|tulip_media
decl_stmt|;
comment|/* current media type */
name|u_int32_t
name|tulip_abilities
decl_stmt|;
comment|/* remote system's 							 * abilities (as 							 * defined in IEEE 							 * 802.3u) 							 */
name|u_int8_t
name|tulip_revinfo
decl_stmt|;
comment|/* chip revision */
name|u_int8_t
name|tulip_phyaddr
decl_stmt|;
comment|/* current phy */
name|u_int8_t
name|tulip_gpinit
decl_stmt|;
comment|/* active pins on 							 * 21140 							 */
name|u_int8_t
name|tulip_gpdata
decl_stmt|;
comment|/* default gpdata for 21140 */
name|struct
name|tulip_probe_info
name|tulip_probe
decl_stmt|;
name|tulip_chipid_t
name|tulip_chipid
decl_stmt|;
comment|/* type of chip we are using */
specifier|const
name|tulip_boardsw_t
modifier|*
name|tulip_boardsw
decl_stmt|;
comment|/* board/chip characteristics */
name|tulip_softc_t
modifier|*
name|tulip_slaves
decl_stmt|;
comment|/* slaved devices (ZX3xx) */
if|#
directive|if
name|defined
argument_list|(
name|TULIP_DEBUG
argument_list|)
name|struct
name|tulip_dbg_info
name|tulip_dbg
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|TULIP_PERFSTATS
argument_list|)
name|struct
name|tulip_perfstat
name|tulip_perfstats
index|[
name|TULIP_PERF_MAX
index|]
decl_stmt|;
endif|#
directive|endif
name|struct
name|ifqueue
name|tulip_txq
decl_stmt|;
name|struct
name|ifqueue
name|tulip_rxq
decl_stmt|;
name|tulip_dot3_stats_t
name|tulip_dot3stats
decl_stmt|;
name|tulip_ringinfo_t
name|tulip_rxinfo
decl_stmt|;
name|tulip_ringinfo_t
name|tulip_txinfo
decl_stmt|;
name|tulip_media_info_t
name|tulip_mediainfo
index|[
literal|10
index|]
decl_stmt|;
comment|/* 	 * The setup buffers for sending the setup frame to the chip. one is 	 * the one being sent while the other is the one being filled. 	 */
name|u_int32_t
name|tulip_setupbuf
index|[
literal|192
operator|/
sizeof|sizeof
argument_list|(
name|u_int32_t
argument_list|)
index|]
decl_stmt|;
name|u_int32_t
name|tulip_setupdata
index|[
literal|192
operator|/
sizeof|sizeof
argument_list|(
name|u_int32_t
argument_list|)
index|]
decl_stmt|;
name|char
name|tulip_boardid
index|[
literal|24
index|]
decl_stmt|;
name|u_int8_t
name|tulip_rombuf
index|[
literal|128
index|]
decl_stmt|;
comment|/* must be aligned */
comment|/* needed for multiport boards */
name|u_int8_t
name|tulip_pci_busno
decl_stmt|;
name|u_int8_t
name|tulip_pci_devno
decl_stmt|;
name|u_int8_t
name|tulip_connidx
decl_stmt|;
name|tulip_srom_connection_t
name|tulip_conntype
decl_stmt|;
name|tulip_desc_t
modifier|*
name|tulip_rxdescs
decl_stmt|;
name|tulip_desc_t
modifier|*
name|tulip_txdescs
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tulip_curperfstats
value|tulip_perfstats[TULIP_PERF_CURRENT]
end_define

begin_define
define|#
directive|define
name|tulip_probe_count
value|tulip_probe.probe_count
end_define

begin_define
define|#
directive|define
name|tulip_probe_timeout
value|tulip_probe.probe_timeout
end_define

begin_define
define|#
directive|define
name|tulip_probe_state
value|tulip_probe.probe_state
end_define

begin_define
define|#
directive|define
name|tulip_probe_media
value|tulip_probe.probe_media
end_define

begin_define
define|#
directive|define
name|tulip_probe_mediamask
value|tulip_probe.probe_mediamask
end_define

begin_define
define|#
directive|define
name|tulip_probe_passes
value|tulip_probe.probe_passes
end_define

begin_comment
comment|/* Definitions for tulip_flags. */
end_comment

begin_define
define|#
directive|define
name|TULIP_WANTSETUP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TULIP_WANTHASHPERFECT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TULIP_WANTHASHONLY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TULIP_DOINGSETUP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TULIP_PRINTMEDIA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TULIP_TXPROBE_ACTIVE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TULIP_ALLMULTI
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TULIP_WANTRXACT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TULIP_RXACT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TULIP_INRESET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TULIP_NEEDRESET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|TULIP_SQETEST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TULIP_xxxxxx0
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TULIP_xxxxxx1
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TULIP_WANTTXSTART
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TULIP_NEWTXTHRESH
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TULIP_NOAUTOSENSE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TULIP_PRINTLINKUP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TULIP_LINKUP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TULIP_RXBUFSLOW
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TULIP_NOMESSAGES
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TULIP_SYSTEMERROR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TULIP_TIMEOUTPENDING
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TULIP_xxxxxx2
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TULIP_TRYNWAY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TULIP_DIDNWAY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TULIP_RXIGNORE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|TULIP_PROBE1STPASS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|TULIP_DEVICEPROBE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TULIP_PROMISC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TULIP_HASHONLY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TULIP_xxxxxx3
value|0x80000000
end_define

begin_comment
comment|/* Definitions for tulip_features. */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_GPR
value|0x00000001
end_define

begin_comment
comment|/* have gp register (140[A]) */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_RXBADOVRFLW
value|0x00000002
end_define

begin_comment
comment|/* RX corrupts on overflow */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_POWERMGMT
value|0x00000004
end_define

begin_comment
comment|/* Snooze/sleep modes */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_MII
value|0x00000008
end_define

begin_comment
comment|/* Some medium on MII */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_SIANWAY
value|0x00000010
end_define

begin_comment
comment|/* SIA does NWAY */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_DUALSENSE
value|0x00000020
end_define

begin_comment
comment|/* SIA senses both AUI& TP */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_SIAGP
value|0x00000040
end_define

begin_comment
comment|/* SIA has a GP port */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_BROKEN_HASH
value|0x00000080
end_define

begin_comment
comment|/* Broken Multicast Hash */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_ISVSROM
value|0x00000100
end_define

begin_comment
comment|/* uses ISV SROM Format */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_BASEROM
value|0x00000200
end_define

begin_comment
comment|/* Board ROM can be cloned */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_SLAVEDROM
value|0x00000400
end_define

begin_comment
comment|/* Board ROM cloned */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_SLAVEDINTR
value|0x00000800
end_define

begin_comment
comment|/* Board slaved interrupt */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_SHAREDINTR
value|0x00001000
end_define

begin_comment
comment|/* Board shares interrupts */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_OKROM
value|0x00002000
end_define

begin_comment
comment|/* ROM was recognized */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_NOMEDIA
value|0x00004000
end_define

begin_comment
comment|/* did not detect any media */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_STOREFWD
value|0x00008000
end_define

begin_comment
comment|/* have CMD_STOREFWD */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_SIA100
value|0x00010000
end_define

begin_comment
comment|/* has LS100 in SIA status */
end_comment

begin_define
define|#
directive|define
name|TULIP_HAVE_OKSROM
value|0x00020000
end_define

begin_comment
comment|/* SROM CRC is OK */
end_comment

begin_define
define|#
directive|define
name|TULIP_DO_AUTOSENSE
parameter_list|(
name|sc
parameter_list|)
define|\
value|(IFM_SUBTYPE((sc)->tulip_ifmedia.ifm_media) == IFM_AUTO)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TULIP_HDR_DATA
argument_list|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|tulip_chipdescs
index|[]
init|=
block|{
literal|"21040 [10Mb/s]"
block|,
literal|"21041 [10Mb/s]"
block|,
literal|"21140 [10-100Mb/s]"
block|,
literal|"21140A [10-100Mb/s]"
block|,
literal|"21142 [10-100Mb/s]"
block|,
literal|"21143 [10-100Mb/s]"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|tulip_mediums
index|[]
init|=
block|{
literal|"unknown"
block|,
comment|/* TULIP_MEDIA_UNKNOWN */
literal|"10baseT"
block|,
comment|/* TULIP_MEDIA_10BASET */
literal|"Full Duplex 10baseT"
block|,
comment|/* TULIP_MEDIA_10BASET_FD */
literal|"BNC"
block|,
comment|/* TULIP_MEDIA_BNC */
literal|"AUI"
block|,
comment|/* TULIP_MEDIA_AUI */
literal|"External SIA"
block|,
comment|/* TULIP_MEDIA_EXTSIA */
literal|"AUI/BNC"
block|,
comment|/* TULIP_MEDIA_AUIBNC */
literal|"100baseTX"
block|,
comment|/* TULIP_MEDIA_100BASET */
literal|"Full Duplex 100baseTX"
block|,
comment|/* TULIP_MEDIA_100BASET_FD */
literal|"100baseT4"
block|,
comment|/* TULIP_MEDIA_100BASET4 */
literal|"100baseFX"
block|,
comment|/* TULIP_MEDIA_100BASEFX */
literal|"Full Duplex 100baseFX"
block|,
comment|/* TULIP_MEDIA_100BASEFX_FD */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|tulip_media_to_ifmedia
index|[]
init|=
block|{
name|IFM_ETHER
operator||
name|IFM_NONE
block|,
comment|/* TULIP_MEDIA_UNKNOWN */
name|IFM_ETHER
operator||
name|IFM_10_T
block|,
comment|/* TULIP_MEDIA_10BASET */
name|IFM_ETHER
operator||
name|IFM_10_T
operator||
name|IFM_FDX
block|,
comment|/* TULIP_MEDIA_10BASET_FD */
name|IFM_ETHER
operator||
name|IFM_10_2
block|,
comment|/* TULIP_MEDIA_BNC */
name|IFM_ETHER
operator||
name|IFM_10_5
block|,
comment|/* TULIP_MEDIA_AUI */
name|IFM_ETHER
operator||
name|IFM_MANUAL
block|,
comment|/* TULIP_MEDIA_EXTSIA */
name|IFM_ETHER
operator||
name|IFM_10_5
block|,
comment|/* TULIP_MEDIA_AUIBNC */
name|IFM_ETHER
operator||
name|IFM_100_TX
block|,
comment|/* TULIP_MEDIA_100BASET */
name|IFM_ETHER
operator||
name|IFM_100_TX
operator||
name|IFM_FDX
block|,
comment|/* TULIP_MEDIA_100BASET_FD */
name|IFM_ETHER
operator||
name|IFM_100_T4
block|,
comment|/* TULIP_MEDIA_100BASET4 */
name|IFM_ETHER
operator||
name|IFM_100_FX
block|,
comment|/* TULIP_MEDIA_100BASEFX */
name|IFM_ETHER
operator||
name|IFM_100_FX
operator||
name|IFM_FDX
block|,
comment|/* TULIP_MEDIA_100BASEFX_FD */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|tulip_system_errors
index|[]
init|=
block|{
literal|"parity error"
block|,
literal|"master abort"
block|,
literal|"target abort"
block|,
literal|"reserved #3"
block|,
literal|"reserved #4"
block|,
literal|"reserved #5"
block|,
literal|"reserved #6"
block|,
literal|"reserved #7"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|tulip_status_bits
index|[]
init|=
block|{
name|NULL
block|,
literal|"transmit process stopped"
block|,
name|NULL
block|,
literal|"transmit jabber timeout"
block|,
name|NULL
block|,
literal|"transmit underflow"
block|,
name|NULL
block|,
literal|"receive underflow"
block|,
literal|"receive process stopped"
block|,
literal|"receive watchdog timeout"
block|,
name|NULL
block|,
name|NULL
block|,
literal|"link failure"
block|,
name|NULL
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_struct
specifier|static
specifier|const
struct|struct
block|{
name|tulip_srom_connection_t
name|sc_type
decl_stmt|;
name|tulip_media_t
name|sc_media
decl_stmt|;
name|u_int32_t
name|sc_attrs
decl_stmt|;
block|}
name|tulip_srom_conninfo
index|[]
init|=
block|{
block|{
name|TULIP_SROM_CONNTYPE_10BASET
block|,
name|TULIP_MEDIA_10BASET
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_BNC
block|,
name|TULIP_MEDIA_BNC
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_AUI
block|,
name|TULIP_MEDIA_AUI
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_100BASETX
block|,
name|TULIP_MEDIA_100BASETX
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_100BASET4
block|,
name|TULIP_MEDIA_100BASET4
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_100BASEFX
block|,
name|TULIP_MEDIA_100BASEFX
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_MII_10BASET
block|,
name|TULIP_MEDIA_10BASET
block|,
name|TULIP_SROM_ATTR_MII
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_MII_100BASETX
block|,
name|TULIP_MEDIA_100BASETX
block|,
name|TULIP_SROM_ATTR_MII
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_MII_100BASET4
block|,
name|TULIP_MEDIA_100BASET4
block|,
name|TULIP_SROM_ATTR_MII
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_MII_100BASEFX
block|,
name|TULIP_MEDIA_100BASEFX
block|,
name|TULIP_SROM_ATTR_MII
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_10BASET_NWAY
block|,
name|TULIP_MEDIA_10BASET
block|,
name|TULIP_SROM_ATTR_NWAY
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_10BASET_FD
block|,
name|TULIP_MEDIA_10BASET_FD
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_MII_10BASET_FD
block|,
name|TULIP_MEDIA_10BASET_FD
block|,
name|TULIP_SROM_ATTR_MII
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_100BASETX_FD
block|,
name|TULIP_MEDIA_100BASETX_FD
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_MII_100BASETX_FD
block|,
name|TULIP_MEDIA_100BASETX_FD
block|,
name|TULIP_SROM_ATTR_MII
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_10BASET_NOLINKPASS
block|,
name|TULIP_MEDIA_10BASET
block|,
name|TULIP_SROM_ATTR_NOLINKPASS
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_AUTOSENSE
block|,
name|TULIP_MEDIA_UNKNOWN
block|,
name|TULIP_SROM_ATTR_AUTOSENSE
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_AUTOSENSE_POWERUP
block|,
name|TULIP_MEDIA_UNKNOWN
block|,
name|TULIP_SROM_ATTR_AUTOSENSE
operator||
name|TULIP_SROM_ATTR_POWERUP
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_AUTOSENSE_NWAY
block|,
name|TULIP_MEDIA_UNKNOWN
block|,
name|TULIP_SROM_ATTR_AUTOSENSE
operator||
name|TULIP_SROM_ATTR_NWAY
block|}
block|,
block|{
name|TULIP_SROM_CONNTYPE_NOT_USED
block|,
name|TULIP_MEDIA_UNKNOWN
block|}
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TULIP_SROM_LASTCONNIDX
define|\
value|(sizeof(tulip_srom_conninfo)/sizeof(tulip_srom_conninfo[0]) - 1)
end_define

begin_struct
specifier|static
specifier|const
struct|struct
block|{
name|tulip_media_t
name|sm_type
decl_stmt|;
name|tulip_srom_media_t
name|sm_srom_type
decl_stmt|;
block|}
name|tulip_srom_mediums
index|[]
init|=
block|{
block|{
name|TULIP_MEDIA_100BASEFX_FD
block|,
name|TULIP_SROM_MEDIA_100BASEFX_FD
block|}
block|,
block|{
name|TULIP_MEDIA_100BASEFX
block|,
name|TULIP_SROM_MEDIA_100BASEFX
block|}
block|,
block|{
name|TULIP_MEDIA_100BASET4
block|,
name|TULIP_SROM_MEDIA_100BASET4
block|}
block|,
block|{
name|TULIP_MEDIA_100BASETX_FD
block|,
name|TULIP_SROM_MEDIA_100BASETX_FD
block|}
block|,
block|{
name|TULIP_MEDIA_100BASETX
block|,
name|TULIP_SROM_MEDIA_100BASETX
block|}
block|,
block|{
name|TULIP_MEDIA_10BASET_FD
block|,
name|TULIP_SROM_MEDIA_10BASET_FD
block|}
block|,
block|{
name|TULIP_MEDIA_AUI
block|,
name|TULIP_SROM_MEDIA_AUI
block|}
block|,
block|{
name|TULIP_MEDIA_BNC
block|,
name|TULIP_SROM_MEDIA_BNC
block|}
block|,
block|{
name|TULIP_MEDIA_10BASET
block|,
name|TULIP_SROM_MEDIA_10BASET
block|}
block|,
block|{
name|TULIP_MEDIA_UNKNOWN
block|}
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TULIP_HDR_DATA */
end_comment

begin_comment
comment|/*  * This driver supports a maximum of 32 tulip boards.  * This should be enough for the forseeable future.  */
end_comment

begin_define
define|#
directive|define
name|TULIP_MAX_DEVICES
value|32
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TULIP_USE_SOFTINTR
argument_list|)
operator|&&
name|defined
argument_list|(
name|TULIP_HDR_DATA
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|u_int32_t
name|tulip_softintr_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|tulip_softintr_last_unit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|tulip_softintr_max_unit
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|tulip_softintr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TULIP_BUS_DMA
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|TULIP_BUS_DMA_NORX
argument_list|)
end_if

begin_define
define|#
directive|define
name|TULIP_RXDESC_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->tulip_dmatag, (sc)->tulip_rxdescmap, \ 		   (caddr_t) di - (caddr_t) (sc)->tulip_rxdescs, \ 		   (s), BUS_DMASYNC_PREREAD|BUS_DMASYNC_PREWRITE)
end_define

begin_define
define|#
directive|define
name|TULIP_RXDESC_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->tulip_dmatag, (sc)->tulip_rxdescmap, \ 		   (caddr_t) di - (caddr_t) (sc)->tulip_rxdescs, \ 		   (s), BUS_DMASYNC_POSTREAD|BUS_DMASYNC_POSTWRITE)
end_define

begin_define
define|#
directive|define
name|TULIP_RXMAP_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->tulip_dmatag, (map), 0, (map)->dm_mapsize, \ 			BUS_DMASYNC_PREREAD|BUS_DMASYNC_PREWRITE)
end_define

begin_define
define|#
directive|define
name|TULIP_RXMAP_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->tulip_dmatag, (map), 0, (map)->dm_mapsize, \ 			BUS_DMASYNC_POSTREAD|BUS_DMASYNC_POSTWRITE)
end_define

begin_define
define|#
directive|define
name|TULIP_RXMAP_CREATE
parameter_list|(
name|sc
parameter_list|,
name|mapp
parameter_list|)
define|\
value|bus_dmamap_create((sc)->tulip_dmatag, TULIP_RX_BUFLEN, 2, \ 			  TULIP_DATA_PER_DESC, 0, \ 			  BUS_DMA_NOWAIT|BUS_DMA_ALLOCNOW, (mapp))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|TULIP_RXDESC_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
value|alpha_mb()
end_define

begin_define
define|#
directive|define
name|TULIP_RXDESC_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
value|alpha_mb()
end_define

begin_define
define|#
directive|define
name|TULIP_RXMAP_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
value|alpha_mb()
end_define

begin_define
define|#
directive|define
name|TULIP_RXMAP_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
value|alpha_mb()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TULIP_RXDESC_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_RXDESC_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_RXMAP_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_RXMAP_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TULIP_RXMAP_CREATE
parameter_list|(
name|sc
parameter_list|,
name|mapp
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TULIP_BUS_DMA
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|TULIP_BUS_DMA_NOTX
argument_list|)
end_if

begin_define
define|#
directive|define
name|TULIP_TXDESC_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->tulip_dmatag, (sc)->tulip_txdescmap, \ 			(caddr_t) di - (caddr_t) (sc)->tulip_txdescs, \ 			(s), BUS_DMASYNC_PREREAD|BUS_DMASYNC_PREWRITE)
end_define

begin_define
define|#
directive|define
name|TULIP_TXDESC_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->tulip_dmatag, (sc)->tulip_txdescmap, \ 			(caddr_t) di - (caddr_t) (sc)->tulip_txdescs, \ 			(s), BUS_DMASYNC_POSTREAD|BUS_DMASYNC_POSTWRITE)
end_define

begin_define
define|#
directive|define
name|TULIP_TXMAP_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->tulip_dmatag, (map), 0, (map)->dm_mapsize, \ 			BUS_DMASYNC_PREREAD|BUS_DMASYNC_PREWRITE)
end_define

begin_define
define|#
directive|define
name|TULIP_TXMAP_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->tulip_dmatag, (map), 0, (map)->dm_mapsize, \ 			BUS_DMASYNC_POSTREAD|BUS_DMASYNC_POSTWRITE)
end_define

begin_define
define|#
directive|define
name|TULIP_TXMAP_CREATE
parameter_list|(
name|sc
parameter_list|,
name|mapp
parameter_list|)
define|\
value|bus_dmamap_create((sc)->tulip_dmatag, TULIP_DATA_PER_DESC, \ 			  TULIP_MAX_TXSEG, TULIP_DATA_PER_DESC, \ 			  0, BUS_DMA_NOWAIT, (mapp))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|TULIP_TXDESC_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
value|alpha_mb()
end_define

begin_define
define|#
directive|define
name|TULIP_TXDESC_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
value|alpha_mb()
end_define

begin_define
define|#
directive|define
name|TULIP_TXMAP_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
value|alpha_mb()
end_define

begin_define
define|#
directive|define
name|TULIP_TXMAP_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
value|alpha_mb()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TULIP_TXDESC_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_TXDESC_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|di
parameter_list|,
name|s
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_TXMAP_PRESYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_TXMAP_POSTSYNC
parameter_list|(
name|sc
parameter_list|,
name|map
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TULIP_TXMAP_CREATE
parameter_list|(
name|sc
parameter_list|,
name|mapp
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|SIOCGADDRROM
value|_IOW('i', 240, struct ifreq)
end_define

begin_comment
comment|/* get 128 bytes of ROM */
end_comment

begin_define
define|#
directive|define
name|SIOCGCHIPID
value|_IOWR('i', 241, struct ifreq)
end_define

begin_comment
comment|/* get chipid */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TULIP_HDR_DATA
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|tulip_softc_t
modifier|*
name|tulips
index|[
name|TULIP_MAX_DEVICES
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TULIP_USE_SOFTINTR
argument_list|)
end_if

begin_expr_stmt
name|NETISR_SET
argument_list|(
name|NETISR_DE
argument_list|,
name|tulip_softintr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|loudprintf
value|if (bootverbose) printf
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TULIP_KVATOPHYS
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|TULIP_BUS_DMA
argument_list|)
operator|||
name|defined
argument_list|(
name|TULIP_BUS_DMA_NORX
argument_list|)
operator|||
name|defined
argument_list|(
name|TULIP_BUS_DMA_NOTX
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_comment
comment|/* XXX XXX NEED REAL DMA MAPPING SUPPORT XXX XXX */
end_comment

begin_define
define|#
directive|define
name|vtobus
parameter_list|(
name|va
parameter_list|)
value|alpha_XXX_dmamap((vm_offset_t)va)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vtobus
parameter_list|(
name|va
parameter_list|)
value|vtophys(va)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TULIP_KVATOPHYS
parameter_list|(
name|sc
parameter_list|,
name|va
parameter_list|)
value|vtobus(va)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TULIP_PERFSTATS
argument_list|)
end_if

begin_define
define|#
directive|define
name|TULIP_PERFMERGE
parameter_list|(
name|sc
parameter_list|,
name|member
parameter_list|)
define|\
value|do { (sc)->tulip_perfstats[TULIP_PERF_TOTAL].member \ 	     += (sc)->tulip_perfstats[TULIP_PERF_CURRENT].member; \ 	 (sc)->tulip_perfstats[TULIP_PERF_PREVIOUS].member \ 	      = (sc)->tulip_perfstats[TULIP_PERF_CURRENT].member; \ 	    (sc)->tulip_perfstats[TULIP_PERF_CURRENT].member = 0; } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_PERFSTART
parameter_list|(
name|name
parameter_list|)
value|const tulip_cycle_t perfstart_ ## name = TULIP_PERFREAD();
end_define

begin_define
define|#
directive|define
name|TULIP_PERFEND
parameter_list|(
name|name
parameter_list|)
value|do { \ 	    (sc)->tulip_curperfstats.perf_ ## name ## _cycles += TULIP_PERFDIFF(perfstart_ ## name, TULIP_PERFREAD()); \ 	    (sc)->tulip_curperfstats.perf_ ## name ++; \ 	} while (0)
end_define

begin_typedef
typedef|typedef
name|u_long
name|tulip_cycle_t
typedef|;
end_typedef

begin_function
specifier|static
name|__inline
name|tulip_cycle_t
name|TULIP_PERFREAD
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|get_cyclecount
argument_list|()
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|TULIP_PERFDIFF
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|((f) - (s))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TULIP_PERFSTART
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TULIP_PERFEND
parameter_list|(
name|name
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|TULIP_PERFMERGE
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TULIP_PERFSTATS */
end_comment

begin_define
define|#
directive|define
name|TULIP_CRC32_POLY
value|0xEDB88320UL
end_define

begin_comment
comment|/* CRC-32 Poly -- Little 						 * Endian */
end_comment

begin_define
define|#
directive|define
name|TULIP_MAX_TXSEG
value|30
end_define

begin_define
define|#
directive|define
name|TULIP_ADDREQUAL
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|(((u_int16_t *)a1)[0] == ((u_int16_t *)a2)[0] \&& ((u_int16_t *)a1)[1] == ((u_int16_t *)a2)[1] \&& ((u_int16_t *)a1)[2] == ((u_int16_t *)a2)[2])
end_define

begin_define
define|#
directive|define
name|TULIP_ADDRBRDCST
parameter_list|(
name|a1
parameter_list|)
define|\
value|(((u_int16_t *)a1)[0] == 0xFFFFU \&& ((u_int16_t *)a1)[1] == 0xFFFFU \&& ((u_int16_t *)a1)[2] == 0xFFFFU)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEVAR_H */
end_comment

end_unit

