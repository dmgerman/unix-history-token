begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Efficient ENI Adapter Support  * -----------------------------  *  * Defines for statistics  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ENI_ENI_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|_ENI_ENI_STATS_H
end_define

begin_struct
struct|struct
name|eni_stats_oc3
block|{
name|u_long
name|oc3_sect_bip8
decl_stmt|;
comment|/* Section 8-bit intrlv parity errors */
name|u_long
name|oc3_path_bip8
decl_stmt|;
comment|/* Path 8-bit intrlv parity errors */
name|u_long
name|oc3_line_bip24
decl_stmt|;
comment|/* Line 24-bit intrlv parity errors */
name|u_long
name|oc3_line_febe
decl_stmt|;
comment|/* Line far-end block errors */
name|u_long
name|oc3_path_febe
decl_stmt|;
comment|/* Path far-end block errors */
name|u_long
name|oc3_hec_corr
decl_stmt|;
comment|/* Correctable HEC errors */
name|u_long
name|oc3_hec_uncorr
decl_stmt|;
comment|/* Uncorrectable HEC errors */
name|u_long
name|oc3_pad
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eni_stats_oc3
name|Eni_Stats_oc3
typedef|;
end_typedef

begin_struct
struct|struct
name|eni_stats_atm
block|{
name|u_long
name|atm_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_long
name|atm_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_long
name|atm_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eni_stats_atm
name|Eni_Stats_atm
typedef|;
end_typedef

begin_struct
struct|struct
name|eni_stats_aal0
block|{
name|u_long
name|aal0_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_long
name|aal0_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_long
name|aal0_drops
decl_stmt|;
comment|/* Cells dropped */
name|u_long
name|aal0_pad
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eni_stats_aal0
name|Eni_Stats_aal0
typedef|;
end_typedef

begin_struct
struct|struct
name|eni_stats_aal5
block|{
name|u_long
name|aal5_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_long
name|aal5_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_long
name|aal5_crc_len
decl_stmt|;
comment|/* Cells with CRC/length errors */
name|u_long
name|aal5_drops
decl_stmt|;
comment|/* Cell drops */
name|u_long
name|aal5_pdu_xmit
decl_stmt|;
comment|/* CS PDUs transmitted */
name|u_long
name|aal5_pdu_rcvd
decl_stmt|;
comment|/* CS PDUs received */
name|u_long
name|aal5_pdu_crc
decl_stmt|;
comment|/* CS PDUs with CRC errors */
name|u_long
name|aal5_pdu_errs
decl_stmt|;
comment|/* CS layer protocol errors */
name|u_long
name|aal5_pdu_drops
decl_stmt|;
comment|/* CS PDUs dropped */
name|u_long
name|aal5_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eni_stats_aal5
name|Eni_Stats_aal5
typedef|;
end_typedef

begin_struct
struct|struct
name|eni_stats_driver
block|{
comment|/* 	 * Adapter memory allocator stats 	 */
name|u_long
name|drv_mm_toobig
decl_stmt|;
comment|/* Size larger then adapter supports */
name|u_long
name|drv_mm_nodesc
decl_stmt|;
comment|/* No memory area descriptor avail */
name|u_long
name|drv_mm_nobuf
decl_stmt|;
comment|/* No memory buffer available */
name|u_long
name|drv_mm_notuse
decl_stmt|;
comment|/* Calling free() on free buffer */
name|u_long
name|drv_mm_notfnd
decl_stmt|;
comment|/* Couldn't find descr for free() */
comment|/* 	 * VCM sats 	 */
name|u_long
name|drv_vc_maxpdu
decl_stmt|;
comment|/* Requested PDU size too large */
name|u_long
name|drv_vc_badrng
decl_stmt|;
comment|/* VPI and/or VCI too large */
comment|/* 	 * Receive stats 	 */
name|u_long
name|drv_rv_norsc
decl_stmt|;
comment|/* No buffer for resource pointers */
name|u_long
name|drv_rv_nobufs
decl_stmt|;
comment|/* No buffers for PDU */
name|u_long
name|drv_rv_nodma
decl_stmt|;
comment|/* No room in RXDMA list */
name|u_long
name|drv_rv_rxq
decl_stmt|;
comment|/* No room in local rxqueue */
name|u_long
name|drv_rv_novcc
decl_stmt|;
comment|/* Draining PDU on closed VCC */
name|u_long
name|drv_rv_intrq
decl_stmt|;
comment|/* No room in atm_intrq */
name|u_long
name|drv_rv_null
decl_stmt|;
comment|/* Trying to pass null PDU up stack */
name|u_long
name|drv_rv_segdma
decl_stmt|;
comment|/* No DMA address */
comment|/* 	 * Transmit stats 	 */
name|u_long
name|drv_xm_segdma
decl_stmt|;
comment|/* No DMA address */
name|u_long
name|drv_xm_segnoal
decl_stmt|;
comment|/* Non-aligned segment */
name|u_long
name|drv_xm_seglen
decl_stmt|;
comment|/* Padded length segment */
name|u_long
name|drv_xm_maxpdu
decl_stmt|;
comment|/* Too many segments - dropped */
name|u_long
name|drv_xm_nobuf
decl_stmt|;
comment|/* No space in TX buffer - dropped */
name|u_long
name|drv_xm_norsc
decl_stmt|;
comment|/* No buffers for resource pointers */
name|u_long
name|drv_xm_nodma
decl_stmt|;
comment|/* No space in TXDMA list */
name|u_long
name|drv_xm_dmaovfl
decl_stmt|;
comment|/* DMA overflow */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eni_stats_driver
name|Eni_Stats_drv
typedef|;
end_typedef

begin_struct
struct|struct
name|eni_stats
block|{
name|Eni_Stats_oc3
name|eni_st_oc3
decl_stmt|;
comment|/* OC3 layer stats */
name|Eni_Stats_atm
name|eni_st_atm
decl_stmt|;
comment|/* ATM layer stats */
name|Eni_Stats_aal0
name|eni_st_aal0
decl_stmt|;
comment|/* AAL0 layer stats */
name|Eni_Stats_aal5
name|eni_st_aal5
decl_stmt|;
comment|/* AAL5 layer stats */
name|Eni_Stats_drv
name|eni_st_drv
decl_stmt|;
comment|/* Driver stats */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eni_stats
name|Eni_stats
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ENI_ENI_STATS_H */
end_comment

end_unit

