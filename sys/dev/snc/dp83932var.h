begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: dp83932var.h,v 1.3 1999/01/24 01:39:51 kmatsuda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: if_snvar.h,v 1.12 1998/05/01 03:42:47 scottr Exp $	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1997, 1998, 1999  *	Kouichi Matsuda.  All rights reserved.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1991   Algorithmics Ltd (http://www.algor.co.uk)  * You may use, copy, and modify this program so long as you retain the  * copyright line.  */
end_comment

begin_comment
comment|/*  * if_snvar.h -- National Semiconductor DP8393X (SONIC) NetBSD/mac68k vars  */
end_comment

begin_comment
comment|/*  * Modified for NetBSD/pc98 1.2.1 from NetBSD/mac68k 1.2D by Kouichi Matsuda.  * Make adapted for NEC PC-9801-83, 84, PC-9801-103, 104, PC-9801N-25 and  * PC-9801N-J02, J02R, which uses National Semiconductor DP83934AVQB as  * Ethernet Controller and National Semiconductor NS46C46 as  * (64 * 16 bits) Microwire Serial EEPROM.  */
end_comment

begin_comment
comment|/* borrow from arch/mac68k/dev/if_mcvar.h for debug. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_define
define|#
directive|define
name|integrate
end_define

begin_define
define|#
directive|define
name|hide
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|integrate
value|static __inline
end_define

begin_define
define|#
directive|define
name|hide
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NetBSD Emulation */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NBPG
end_ifndef

begin_define
define|#
directive|define
name|NBPG
value|PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PGOFSET
end_ifndef

begin_define
define|#
directive|define
name|PGOFSET
value|PAGE_MASK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulong
typedef|;
end_typedef

begin_define
define|#
directive|define
name|delay
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Vendor types  */
end_comment

begin_comment
comment|/*  * SONIC buffers need to be aligned 16 or 32 bit aligned.  * These macros calculate and verify alignment.  */
end_comment

begin_define
define|#
directive|define
name|ROUNDUP
parameter_list|(
name|p
parameter_list|,
name|N
parameter_list|)
value|(((int) p + N - 1)& ~(N - 1))
end_define

begin_define
define|#
directive|define
name|SOALIGN
parameter_list|(
name|m
parameter_list|,
name|array
parameter_list|)
value|(m ? (ROUNDUP(array, 4)) : (ROUNDUP(array, 2)))
end_define

begin_define
define|#
directive|define
name|LOWER
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|UPPER
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)>> 16)
end_define

begin_comment
comment|/*  * Memory access macros. Since we handle SONIC in 16 bit mode (PB5X0)  * and 32 bit mode (everything else) using a single GENERIC kernel  * binary, all structures have to be accessed using macros which can  * adjust the offsets appropriately.  */
end_comment

begin_comment
comment|/* m is not sc->bitmode, we treat m as sc. */
end_comment

begin_define
define|#
directive|define
name|SWO
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|,
name|o
parameter_list|,
name|x
parameter_list|)
value|(*(m)->sc_writetodesc)((m), (a), (o), (x))
end_define

begin_define
define|#
directive|define
name|SRO
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|,
name|o
parameter_list|)
value|(*(m)->sc_readfromdesc)((m), (a), (o))
end_define

begin_comment
comment|/*  * Register access macros. We use bus_space_* to talk to the Sonic  * registers. A mapping table is used in case a particular configuration  * hooked the regs up at non-word offsets.  */
end_comment

begin_define
define|#
directive|define
name|NIC_GET
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|(*(sc)->sc_nic_get)(sc, reg)
end_define

begin_define
define|#
directive|define
name|NIC_PUT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|(*(sc)->sc_nic_put)(sc, reg, val)
end_define

begin_define
define|#
directive|define
name|SONIC_GETDMA
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_comment
comment|/* pc98 does not have any write buffers to flush... */
end_comment

begin_define
define|#
directive|define
name|wbflush
parameter_list|()
end_define

begin_comment
comment|/*  * buffer sizes in 32 bit mode  * 1 TXpkt is 4 hdr words + (3 * FRAGMAX) + 1 link word == 23 words == 92 bytes  *  * 1 RxPkt is 7 words == 28 bytes  * 1 Rda   is 4 words == 16 bytes  *  * The CDA is 17 words == 68 bytes  *  * total space in page 0 = NTDA * 92 + NRRA * 16 + NRDA * 28 + 68  */
end_comment

begin_define
define|#
directive|define
name|NRBA
value|16
end_define

begin_comment
comment|/* # receive buffers< NRRA */
end_comment

begin_define
define|#
directive|define
name|RBAMASK
value|(NRBA-1)
end_define

begin_define
define|#
directive|define
name|NTDA
value|16
end_define

begin_comment
comment|/* # transmit descriptors */
end_comment

begin_define
define|#
directive|define
name|NRRA
value|64
end_define

begin_comment
comment|/* # receive resource descriptors */
end_comment

begin_define
define|#
directive|define
name|RRAMASK
value|(NRRA-1)
end_define

begin_comment
comment|/* the reason why NRRA must be power of two */
end_comment

begin_define
define|#
directive|define
name|FCSSIZE
value|4
end_define

begin_comment
comment|/* size of FCS appended to packets */
end_comment

begin_comment
comment|/*  * maximum receive packet size plus 2 byte pad to make each  * one aligned. 4 byte slop (required for eobc)  */
end_comment

begin_define
define|#
directive|define
name|RBASIZE
parameter_list|(
name|sc
parameter_list|)
value|(sizeof(struct ether_header) + ETHERMTU + FCSSIZE + \ 			 ((sc)->bitmode ? 6 : 2))
end_define

begin_comment
comment|/*  * transmit buffer area  */
end_comment

begin_define
define|#
directive|define
name|TXBSIZE
value|1536
end_define

begin_comment
comment|/* 6*2^8 -- the same size as the 8390 TXBUF */
end_comment

begin_define
define|#
directive|define
name|SN_NPAGES
value|2 + NRBA + (NTDA/2)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mtd
block|{
name|u_int32_t
name|mtd_vtxp
decl_stmt|;
name|u_int32_t
name|mtd_vbuf
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mtd_mbuf
decl_stmt|;
block|}
name|mtd_t
typedef|;
end_typedef

begin_comment
comment|/*  * The snc_softc for PC-98 if_snc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|snc_softc
block|{
name|struct
name|arpcom
name|sc_ethercom
decl_stmt|;
define|#
directive|define
name|sc_if
value|sc_ethercom.ac_if
comment|/* network visible interface */
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|ioport
decl_stmt|;
name|int
name|ioport_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|iomem
decl_stmt|;
name|int
name|iomem_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|void
modifier|*
name|irq_handle
decl_stmt|;
name|bus_space_tag_t
name|sc_iot
decl_stmt|;
comment|/* bus identifier for io */
name|bus_space_tag_t
name|sc_memt
decl_stmt|;
comment|/* bus identifier for mem */
name|bus_space_handle_t
name|sc_ioh
decl_stmt|;
comment|/* io handle */
name|bus_space_handle_t
name|sc_memh
decl_stmt|;
comment|/* bus memory handle */
name|int
name|bitmode
decl_stmt|;
comment|/* 32 bit mode == 1, 16 == 0 */
name|u_int16_t
name|sncr_dcr
decl_stmt|;
comment|/* DCR for this instance */
name|u_int16_t
name|sncr_dcr2
decl_stmt|;
comment|/* DCR2 for this instance */
name|int
name|sc_rramark
decl_stmt|;
comment|/* index into v_rra of wp */
name|u_int32_t
name|v_rra
index|[
name|NRRA
index|]
decl_stmt|;
comment|/* DMA addresses of v_rra */
name|u_int32_t
name|v_rea
decl_stmt|;
comment|/* ptr to the end of the rra space */
name|int
name|sc_rxmark
decl_stmt|;
comment|/* current hw pos in rda ring */
name|int
name|sc_rdamark
decl_stmt|;
comment|/* current sw pos in rda ring */
name|int
name|sc_nrda
decl_stmt|;
comment|/* total number of RDAs */
name|u_int32_t
name|v_rda
decl_stmt|;
name|u_int32_t
name|rbuf
index|[
name|NRBA
index|]
decl_stmt|;
name|struct
name|mtd
name|mtda
index|[
name|NTDA
index|]
decl_stmt|;
name|int
name|mtd_hw
decl_stmt|;
comment|/* idx of first mtd given to hw */
name|int
name|mtd_prev
decl_stmt|;
comment|/* idx of last mtd given to hardware */
name|int
name|mtd_free
decl_stmt|;
comment|/* next free mtd to use */
name|int
name|mtd_tlinko
decl_stmt|;
comment|/* 					 * offset of tlink of last txp given 					 * to SONIC. Need to clear EOL on 					 * this word to add a desc. 					 */
name|int
name|mtd_pint
decl_stmt|;
comment|/* Counter to set TXP_PINT */
name|u_int32_t
name|v_cda
decl_stmt|;
name|u_int8_t
name|curbank
decl_stmt|;
comment|/* current window bank */
name|struct
name|ifmedia
name|sc_media
decl_stmt|;
comment|/* supported media information */
comment|/* 	 * NIC register access functions: 	 */
name|u_int16_t
function_decl|(
modifier|*
name|sc_nic_get
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_nic_put
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
comment|/* 	 * Memory functions: 	 * 	 *	copy to/from descriptor 	 *	copy to/from buffer 	 *	zero bytes in buffer 	 */
name|void
function_decl|(
modifier|*
name|sc_writetodesc
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
name|u_int16_t
function_decl|(
modifier|*
name|sc_readfromdesc
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_copytobuf
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_copyfrombuf
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_zerobuf
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* 	 * Machine-dependent functions: 	 * 	 *	hardware reset hook - may be NULL 	 *	hardware init hook - may be NULL 	 *	media change hook - may be NULL 	 */
name|void
function_decl|(
modifier|*
name|sc_hwreset
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_hwinit
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_mediachange
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_mediastatus
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|struct
name|ifmediareq
modifier|*
parameter_list|)
function_decl|;
name|int
name|sc_enabled
decl_stmt|;
comment|/* boolean; power enabled on interface */
name|int
function_decl|(
modifier|*
name|sc_enable
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_disable
function_decl|)
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|sc_sh
decl_stmt|;
comment|/* shutdownhook cookie */
name|int
name|gone
decl_stmt|;
if|#
directive|if
name|NRND
operator|>
literal|0
name|rndsource_element_t
name|rnd_source
decl_stmt|;
endif|#
directive|endif
block|}
name|snc_softc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Accessing SONIC data structures and registers as 32 bit values  * makes code endianess independent.  The SONIC is however always in  * bigendian mode so it is necessary to ensure that data structures shared  * between the CPU and the SONIC are always in bigendian order.  */
end_comment

begin_comment
comment|/*  * Receive Resource Descriptor  * This structure describes the buffers into which packets  * will be received.  Note that more than one packet may be  * packed into a single buffer if constraints permit.  */
end_comment

begin_define
define|#
directive|define
name|RXRSRC_PTRLO
value|0
end_define

begin_comment
comment|/* buffer address LO */
end_comment

begin_define
define|#
directive|define
name|RXRSRC_PTRHI
value|1
end_define

begin_comment
comment|/* buffer address HI */
end_comment

begin_define
define|#
directive|define
name|RXRSRC_WCLO
value|2
end_define

begin_comment
comment|/* buffer size (16bit words) LO */
end_comment

begin_define
define|#
directive|define
name|RXRSRC_WCHI
value|3
end_define

begin_comment
comment|/* buffer size (16bit words) HI */
end_comment

begin_define
define|#
directive|define
name|RXRSRC_SIZE
parameter_list|(
name|sc
parameter_list|)
value|(sc->bitmode ? (4 * 4) : (4 * 2))
end_define

begin_comment
comment|/*  * Receive Descriptor  * This structure holds information about packets received.  */
end_comment

begin_define
define|#
directive|define
name|RXPKT_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|RXPKT_BYTEC
value|1
end_define

begin_define
define|#
directive|define
name|RXPKT_PTRLO
value|2
end_define

begin_define
define|#
directive|define
name|RXPKT_PTRHI
value|3
end_define

begin_define
define|#
directive|define
name|RXPKT_SEQNO
value|4
end_define

begin_define
define|#
directive|define
name|RXPKT_RLINK
value|5
end_define

begin_define
define|#
directive|define
name|RXPKT_INUSE
value|6
end_define

begin_define
define|#
directive|define
name|RXPKT_SIZE
parameter_list|(
name|sc
parameter_list|)
value|(sc->bitmode ? (7 * 4) : (7 * 2))
end_define

begin_define
define|#
directive|define
name|RBASEQ
parameter_list|(
name|x
parameter_list|)
value|(((x)>>8)&0xff)
end_define

begin_define
define|#
directive|define
name|PSNSEQ
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_comment
comment|/*  * Transmit Descriptor  * This structure holds information about packets to be transmitted.  */
end_comment

begin_define
define|#
directive|define
name|FRAGMAX
value|8
end_define

begin_comment
comment|/* maximum number of fragments in a packet */
end_comment

begin_define
define|#
directive|define
name|TXP_STATUS
value|0
end_define

begin_comment
comment|/* + transmitted packet status */
end_comment

begin_define
define|#
directive|define
name|TXP_CONFIG
value|1
end_define

begin_comment
comment|/* transmission configuration */
end_comment

begin_define
define|#
directive|define
name|TXP_PKTSIZE
value|2
end_define

begin_comment
comment|/* entire packet size in bytes */
end_comment

begin_define
define|#
directive|define
name|TXP_FRAGCNT
value|3
end_define

begin_comment
comment|/* # fragments in packet */
end_comment

begin_define
define|#
directive|define
name|TXP_FRAGOFF
value|4
end_define

begin_comment
comment|/* offset to first fragment */
end_comment

begin_define
define|#
directive|define
name|TXP_FRAGSIZE
value|3
end_define

begin_comment
comment|/* size of each fragment desc */
end_comment

begin_define
define|#
directive|define
name|TXP_FPTRLO
value|0
end_define

begin_comment
comment|/* ptr to packet fragment LO */
end_comment

begin_define
define|#
directive|define
name|TXP_FPTRHI
value|1
end_define

begin_comment
comment|/* ptr to packet fragment HI */
end_comment

begin_define
define|#
directive|define
name|TXP_FSIZE
value|2
end_define

begin_comment
comment|/* fragment size */
end_comment

begin_define
define|#
directive|define
name|TXP_WORDS
value|(TXP_FRAGOFF + (FRAGMAX*TXP_FRAGSIZE) + 1)
end_define

begin_comment
comment|/* 1 for tlink */
end_comment

begin_define
define|#
directive|define
name|TXP_SIZE
parameter_list|(
name|sc
parameter_list|)
value|((sc->bitmode) ? (TXP_WORDS*4) : (TXP_WORDS*2))
end_define

begin_define
define|#
directive|define
name|EOL
value|0x0001
end_define

begin_comment
comment|/* end of list marker for link fields */
end_comment

begin_comment
comment|/*  * CDA, the CAM descriptor area. The SONIC has a 16 entry CAM to  * match incoming addresses against. It is programmed via DMA  * from a memory region.  */
end_comment

begin_define
define|#
directive|define
name|MAXCAM
value|16
end_define

begin_comment
comment|/* number of user entries in CAM */
end_comment

begin_define
define|#
directive|define
name|CDA_CAMDESC
value|4
end_define

begin_comment
comment|/* # words i na descriptor */
end_comment

begin_define
define|#
directive|define
name|CDA_CAMEP
value|0
end_define

begin_comment
comment|/* CAM Address Port 0 xx-xx-xx-xx-YY-YY */
end_comment

begin_define
define|#
directive|define
name|CDA_CAMAP0
value|1
end_define

begin_comment
comment|/* CAM Address Port 1 xx-xx-YY-YY-xx-xx */
end_comment

begin_define
define|#
directive|define
name|CDA_CAMAP1
value|2
end_define

begin_comment
comment|/* CAM Address Port 2 YY-YY-xx-xx-xx-xx */
end_comment

begin_define
define|#
directive|define
name|CDA_CAMAP2
value|3
end_define

begin_define
define|#
directive|define
name|CDA_ENABLE
value|64
end_define

begin_comment
comment|/* mask enabling CAM entries */
end_comment

begin_define
define|#
directive|define
name|CDA_SIZE
parameter_list|(
name|sc
parameter_list|)
value|((4*16 + 1) * ((sc->bitmode) ? 4 : 2))
end_define

begin_function_decl
name|void
name|sncconfig
parameter_list|(
name|struct
name|snc_softc
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sncintr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sncshutdown
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

