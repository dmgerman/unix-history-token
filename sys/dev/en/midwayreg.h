begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: midwayreg.h,v 1.6 1997/03/20 21:34:47 chuck Exp $	*/
end_comment

begin_comment
comment|/*  * m i d w a y r e g . h  *  * this file contains the description of the ENI ATM midway chip  * data structures.   see midway.c for more details.  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_comment
comment|/* XXX: gross.   netbsd/sparc doesn't have machine/bus.h yet. */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|bus_space_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|pci_chipset_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|caddr_t
name|bus_space_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|bus_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|caddr_t
name|bus_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|bus_space_read_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|((void) t,                            \     (*(volatile u_int32_t *)((h) + (o))))
end_define

begin_define
define|#
directive|define
name|bus_space_write_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((void) t, ((void)(*(volatile u_int32_t *)((h) + (o)) = (v))))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|x
parameter_list|)
value|((u_int32_t)(x))
end_define

begin_comment
comment|/* sun4c dvma */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MID_SZTOB
parameter_list|(
name|X
parameter_list|)
value|((X) * 256 * 4)
end_define

begin_comment
comment|/* size to bytes */
end_comment

begin_define
define|#
directive|define
name|MID_BTOSZ
parameter_list|(
name|X
parameter_list|)
value|((X) / 256 / 4)
end_define

begin_comment
comment|/* bytes to "size" */
end_comment

begin_define
define|#
directive|define
name|MID_N_VC
value|1024
end_define

begin_comment
comment|/* # of VCs we can use */
end_comment

begin_define
define|#
directive|define
name|MID_NTX_CH
value|8
end_define

begin_comment
comment|/* 8 transmit channels (shared) */
end_comment

begin_define
define|#
directive|define
name|MID_ATMDATASZ
value|48
end_define

begin_comment
comment|/* need data in 48 byte blocks */
end_comment

begin_comment
comment|/*  * card data structures, top down  *  * in order to have a portable driver, the netbsd guys will not let us  * use structs.   we have a bus_space_handle_t which is the en_base address.  * everything else is an offset from that base.   all card data must be   * accessed with bus_space_read_4()/bus_space_write_4():  *  * rv = bus_space_read_4(sc->en_memt, sc->en_base, BYTE_OFFSET);  * bus_space_write_4(sc->en_memt, sc->en_base, BYTE_OFFSET, VALUE);  *  * en_card: the whole card (prom + phy + midway + obmem)  * 	obmem contains: vci tab + dma queues (rx& tx) + service list + bufs  */
end_comment

begin_comment
comment|/* byte offsets from en_base of various items */
end_comment

begin_define
define|#
directive|define
name|MID_PHYOFF
value|0x030000
end_define

begin_comment
comment|/* PHY offset */
end_comment

begin_define
define|#
directive|define
name|MID_MIDOFF
value|0x040000
end_define

begin_comment
comment|/* midway regs offset */
end_comment

begin_define
define|#
directive|define
name|MID_RAMOFF
value|0x200000
end_define

begin_comment
comment|/* RAM offset */
end_comment

begin_define
define|#
directive|define
name|MID_DRQOFF
value|0x204000
end_define

begin_comment
comment|/* DRQ offset */
end_comment

begin_define
define|#
directive|define
name|MID_DRQEND
value|MID_DTQOFF
end_define

begin_comment
comment|/* DRQ end */
end_comment

begin_define
define|#
directive|define
name|MID_DTQOFF
value|0x205000
end_define

begin_comment
comment|/* DTQ offset */
end_comment

begin_define
define|#
directive|define
name|MID_DTQEND
value|MID_SLOFF
end_define

begin_comment
comment|/* DTQ end */
end_comment

begin_define
define|#
directive|define
name|MID_SLOFF
value|0x206000
end_define

begin_comment
comment|/* service list */
end_comment

begin_define
define|#
directive|define
name|MID_SLEND
value|MID_BUFOFF
end_define

begin_comment
comment|/* service list end */
end_comment

begin_define
define|#
directive|define
name|MID_BUFOFF
value|0x207000
end_define

begin_comment
comment|/* buffer area */
end_comment

begin_define
define|#
directive|define
name|MID_PROBEOFF
value|0x21fffc
end_define

begin_comment
comment|/* start probe here */
end_comment

begin_define
define|#
directive|define
name|MID_PROBSIZE
value|0x020000
end_define

begin_comment
comment|/* 128 KB */
end_comment

begin_define
define|#
directive|define
name|MID_MAXOFF
value|0x3ffffc
end_define

begin_comment
comment|/* max offset */
end_comment

begin_comment
comment|/*  * prom& phy: not defined here  */
end_comment

begin_define
define|#
directive|define
name|MID_ADPMACOFF
value|0xffc0
end_define

begin_comment
comment|/* mac address offset (adaptec only) */
end_comment

begin_comment
comment|/*  * midway regs  (byte offsets from en_base)  */
end_comment

begin_define
define|#
directive|define
name|MID_RESID
value|0x40000
end_define

begin_comment
comment|/* write=reset reg, read=ID reg */
end_comment

begin_define
define|#
directive|define
name|MID_VER
parameter_list|(
name|X
parameter_list|)
value|(((X)& 0xf0000000)>> 28)
end_define

begin_comment
comment|/* midway version # */
end_comment

begin_define
define|#
directive|define
name|MID_MID
parameter_list|(
name|X
parameter_list|)
value|(((X)& 0x700)>> 8)
end_define

begin_comment
comment|/* motherboard ID */
end_comment

begin_define
define|#
directive|define
name|MID_IS_SABRE
parameter_list|(
name|X
parameter_list|)
value|((X)& 0x80)
end_define

begin_comment
comment|/* sabre controller? */
end_comment

begin_define
define|#
directive|define
name|MID_IS_SUNI
parameter_list|(
name|X
parameter_list|)
value|((X)& 0x40)
end_define

begin_comment
comment|/* SUNI? vs utopia */
end_comment

begin_define
define|#
directive|define
name|MID_IS_UPIPE
parameter_list|(
name|X
parameter_list|)
value|((X)& 0x20)
end_define

begin_comment
comment|/* utopia pipeline? */
end_comment

begin_define
define|#
directive|define
name|MID_DID
parameter_list|(
name|X
parameter_list|)
value|((X)& 0x1f)
end_define

begin_comment
comment|/* daughterboard ID */
end_comment

begin_define
define|#
directive|define
name|MID_INTACK
value|0x40004
end_define

begin_comment
comment|/* interrupt ACK */
end_comment

begin_define
define|#
directive|define
name|MID_INTSTAT
value|0x40008
end_define

begin_comment
comment|/* interrupt status */
end_comment

begin_define
define|#
directive|define
name|MID_INTENA
value|0x4000c
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MID_TXCHAN
parameter_list|(
name|N
parameter_list|)
value|(1<< ((N) + 9))
end_define

begin_comment
comment|/* ack/status/enable xmit channel bit*/
end_comment

begin_define
define|#
directive|define
name|MID_INT_TX
value|0x1fe00
end_define

begin_comment
comment|/* mask for any xmit interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_DMA_OVR
value|0x00100
end_define

begin_comment
comment|/* DMA overflow interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_IDENT
value|0x00080
end_define

begin_comment
comment|/* ident match error interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_LERR
value|0x00040
end_define

begin_comment
comment|/* LERR interrupt (sbus?) */
end_comment

begin_define
define|#
directive|define
name|MID_INT_DMA_ERR
value|0x00020
end_define

begin_comment
comment|/* DMA error interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_DMA_RX
value|0x00010
end_define

begin_comment
comment|/* DMA recv interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_DMA_TX
value|0x00008
end_define

begin_comment
comment|/* DMA xmit interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_SERVICE
value|0x00004
end_define

begin_comment
comment|/* service list interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_SUNI
value|0x00002
end_define

begin_comment
comment|/* SUNI interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_STATS
value|0x00001
end_define

begin_comment
comment|/* stats overflow interrupt */
end_comment

begin_define
define|#
directive|define
name|MID_INT_ANY
value|0x1ffff
end_define

begin_comment
comment|/* any interrupt? */
end_comment

begin_define
define|#
directive|define
name|MID_INTBITS
value|"\20\21T7\20T6\17T5\16T4\15T3\14T2\13T1\12T0\11DMAOVR\10ID\7LERR\6DMAERR\5RXDMA\4TXDMA\3SERV\2SUNI\1STAT"
end_define

begin_define
define|#
directive|define
name|MID_MAST_CSR
value|0x40010
end_define

begin_comment
comment|/* master CSR */
end_comment

begin_define
define|#
directive|define
name|MID_IPL
parameter_list|(
name|X
parameter_list|)
value|(((X)& 0x1c0)>> 6)
end_define

begin_comment
comment|/* IPL */
end_comment

begin_define
define|#
directive|define
name|MID_SETIPL
parameter_list|(
name|I
parameter_list|)
value|((I)<< 6)
end_define

begin_define
define|#
directive|define
name|MID_MCSR_TXLOCK
value|0x20
end_define

begin_comment
comment|/* lock on xmit overflow mode */
end_comment

begin_comment
comment|/* NOTE: next 5 bits: write 1 means enable, write 0 means no change */
end_comment

begin_define
define|#
directive|define
name|MID_MCSR_ENDMA
value|0x10
end_define

begin_comment
comment|/* DMA enable */
end_comment

begin_define
define|#
directive|define
name|MID_MCSR_ENTX
value|0x08
end_define

begin_comment
comment|/* TX enable */
end_comment

begin_define
define|#
directive|define
name|MID_MCSR_ENRX
value|0x04
end_define

begin_comment
comment|/* RX enable */
end_comment

begin_define
define|#
directive|define
name|MID_MCSR_W1MS
value|0x02
end_define

begin_comment
comment|/* wait 1 msec */
end_comment

begin_define
define|#
directive|define
name|MID_MCSR_W500US
value|0x01
end_define

begin_comment
comment|/* wait 500 usec */
end_comment

begin_define
define|#
directive|define
name|MID_MCSRBITS
value|"\20\6LCK\5DMAON\4TXON\3RXON\2W1MS\1W500US"
end_define

begin_define
define|#
directive|define
name|MID_STAT
value|0x40014
end_define

begin_comment
comment|/* stat register, clear on read */
end_comment

begin_define
define|#
directive|define
name|MID_VTRASH
parameter_list|(
name|X
parameter_list|)
value|(((X)>> 16)& 0xffff)
end_define

begin_comment
comment|/* # cells trashed due to VCI's mode */
end_comment

begin_define
define|#
directive|define
name|MID_OTRASH
parameter_list|(
name|X
parameter_list|)
value|((X)& 0xffff)
end_define

begin_comment
comment|/* # cells trashed due to overflow */
end_comment

begin_define
define|#
directive|define
name|MID_SERV_WRITE
value|0x40018
end_define

begin_comment
comment|/* 10 bit service write pointer (r/o) */
end_comment

begin_define
define|#
directive|define
name|MID_DMA_ADDR
value|0x4001c
end_define

begin_comment
comment|/* VA of DMA (r/o) */
end_comment

begin_comment
comment|/* DMA queue pointers (bits 0 to 8) */
end_comment

begin_define
define|#
directive|define
name|MID_DMA_WRRX
value|0x40020
end_define

begin_comment
comment|/* write ptr. for DMA recv queue */
end_comment

begin_comment
comment|/* (for adaptor -> host xfers) */
end_comment

begin_define
define|#
directive|define
name|MID_DMA_RDRX
value|0x40024
end_define

begin_comment
comment|/* read ptr for DMA recv queue (r/o) */
end_comment

begin_comment
comment|/* (i.e. current adaptor->host xfer) */
end_comment

begin_define
define|#
directive|define
name|MID_DMA_WRTX
value|0x40028
end_define

begin_comment
comment|/* write ptr for DMA xmit queue */
end_comment

begin_comment
comment|/* (for host -> adaptor xfers) */
end_comment

begin_define
define|#
directive|define
name|MID_DMA_RDTX
value|0x4002c
end_define

begin_comment
comment|/* read ptr for DMA xmit queue (r/o) */
end_comment

begin_comment
comment|/* (i.e. current host->adaptor xfer) */
end_comment

begin_comment
comment|/* xmit channel regs (1 per channel, MID_NTX_CH max channels) */
end_comment

begin_define
define|#
directive|define
name|MIDX_PLACE
parameter_list|(
name|N
parameter_list|)
value|(0x40040+((N)*0x10))
end_define

begin_comment
comment|/* xmit place */
end_comment

begin_define
define|#
directive|define
name|MIDX_MKPLACE
parameter_list|(
name|SZ
parameter_list|,
name|LOC
parameter_list|)
value|( ((SZ)<< 11) | (LOC) )
end_define

begin_define
define|#
directive|define
name|MIDX_LOC
parameter_list|(
name|X
parameter_list|)
value|((X)& 0x7ff)
end_define

begin_comment
comment|/* location in obmem */
end_comment

begin_define
define|#
directive|define
name|MIDX_SZ
parameter_list|(
name|X
parameter_list|)
value|((X)>> 11)
end_define

begin_comment
comment|/* (size of block / 256) in int32_t's*/
end_comment

begin_define
define|#
directive|define
name|MIDX_BASE
parameter_list|(
name|X
parameter_list|)
define|\
value|(((MIDX_LOC(X)<< MIDV_LOCTOPSHFT) * sizeof(u_int32_t)) + MID_RAMOFF)
end_define

begin_comment
comment|/* the following two regs are word offsets in the block */
end_comment

begin_define
define|#
directive|define
name|MIDX_READPTR
parameter_list|(
name|N
parameter_list|)
value|(0x40044+((N)*0x10))
end_define

begin_comment
comment|/* xmit read pointer (r/o) */
end_comment

begin_define
define|#
directive|define
name|MIDX_DESCSTART
parameter_list|(
name|N
parameter_list|)
value|(0x40048+((N)*0x10))
end_define

begin_comment
comment|/* seg currently in DMA (r/o) */
end_comment

begin_comment
comment|/*  * obmem items  */
end_comment

begin_comment
comment|/*   * vci table in obmem (offset from MID_VCTOFF)  */
end_comment

begin_define
define|#
directive|define
name|MID_VC
parameter_list|(
name|N
parameter_list|)
value|(MID_RAMOFF+((N)*0x10))
end_define

begin_define
define|#
directive|define
name|MIDV_TRASH
value|0x00000000
end_define

begin_comment
comment|/* ignore VC */
end_comment

begin_define
define|#
directive|define
name|MIDV_AAL5
value|0x80000000
end_define

begin_comment
comment|/* do AAL5 on it */
end_comment

begin_define
define|#
directive|define
name|MIDV_NOAAL
value|0x40000000
end_define

begin_comment
comment|/* do per-cell stuff on it */
end_comment

begin_define
define|#
directive|define
name|MIDV_MASK
value|0xc0000000
end_define

begin_comment
comment|/* mode mask */
end_comment

begin_define
define|#
directive|define
name|MIDV_SETMODE
parameter_list|(
name|VC
parameter_list|,
name|M
parameter_list|)
value|(((VC)& ~(MIDV_MASK)) | (M))
end_define

begin_comment
comment|/* new mode */
end_comment

begin_define
define|#
directive|define
name|MIDV_PTI
value|0x20000000
end_define

begin_comment
comment|/* save PTI cells? */
end_comment

begin_define
define|#
directive|define
name|MIDV_LOCTOPSHFT
value|8
end_define

begin_comment
comment|/* shift to get top 11 bits of 19 */
end_comment

begin_define
define|#
directive|define
name|MIDV_LOCSHIFT
value|18
end_define

begin_define
define|#
directive|define
name|MIDV_LOCMASK
value|0x7ff
end_define

begin_define
define|#
directive|define
name|MIDV_LOC
parameter_list|(
name|X
parameter_list|)
value|(((X)>> MIDV_LOCSHIFT)& MIDV_LOCMASK)
end_define

begin_comment
comment|/* 11 most sig bits of addr */
end_comment

begin_define
define|#
directive|define
name|MIDV_SZSHIFT
value|15
end_define

begin_define
define|#
directive|define
name|MIDV_SZ
parameter_list|(
name|X
parameter_list|)
value|(((X)>> MIDV_SZSHIFT)& 7)
end_define

begin_comment
comment|/* size encoded the usual way */
end_comment

begin_define
define|#
directive|define
name|MIDV_INSERVICE
value|0x1
end_define

begin_comment
comment|/* in service list */
end_comment

begin_define
define|#
directive|define
name|MID_DST_RP
parameter_list|(
name|N
parameter_list|)
value|(MID_VC(N)|0x4)
end_define

begin_define
define|#
directive|define
name|MIDV_DSTART_SHIFT
value|16
end_define

begin_comment
comment|/* shift */
end_comment

begin_define
define|#
directive|define
name|MIDV_DSTART
parameter_list|(
name|X
parameter_list|)
value|(((X)>> MIDV_DSTART_SHIFT)& 0x7fff)
end_define

begin_define
define|#
directive|define
name|MIDV_READP_MASK
value|0x7fff
end_define

begin_comment
comment|/* valid bits, (shift = 0) */
end_comment

begin_define
define|#
directive|define
name|MID_WP_ST_CNT
parameter_list|(
name|N
parameter_list|)
value|(MID_VC(N)|0x8)
end_define

begin_comment
comment|/* write pointer/state/count */
end_comment

begin_define
define|#
directive|define
name|MIDV_WRITEP_MASK
value|0x7fff0000
end_define

begin_comment
comment|/* mask for write ptr. */
end_comment

begin_define
define|#
directive|define
name|MIDV_WRITEP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MIDV_ST_IDLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MIDV_ST_TRASH
value|0xc000
end_define

begin_define
define|#
directive|define
name|MIDV_ST_REASS
value|0x4000
end_define

begin_define
define|#
directive|define
name|MIDV_CCOUNT
value|0x7ff
end_define

begin_comment
comment|/* cell count */
end_comment

begin_define
define|#
directive|define
name|MID_CRC
parameter_list|(
name|N
parameter_list|)
value|(MID_VC(N)|0xc)
end_define

begin_comment
comment|/* CRC */
end_comment

begin_comment
comment|/*  * dma recv q.  */
end_comment

begin_define
define|#
directive|define
name|MID_DMA_END
value|(1<< 5)
end_define

begin_comment
comment|/* for both tx and rx */
end_comment

begin_define
define|#
directive|define
name|MID_DMA_CNT
parameter_list|(
name|X
parameter_list|)
value|(((X)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|MID_DMA_TXCHAN
parameter_list|(
name|X
parameter_list|)
value|(((X)>> 6)& 0x7)
end_define

begin_define
define|#
directive|define
name|MID_DMA_RXVCI
parameter_list|(
name|X
parameter_list|)
value|(((X)>> 6)& 0x3ff)
end_define

begin_define
define|#
directive|define
name|MID_DMA_TYPE
parameter_list|(
name|X
parameter_list|)
value|((X)& 0xf)
end_define

begin_define
define|#
directive|define
name|MID_DRQ_N
value|512
end_define

begin_comment
comment|/* # of descriptors */
end_comment

begin_define
define|#
directive|define
name|MID_DRQ_A2REG
parameter_list|(
name|N
parameter_list|)
value|(((N) - MID_DRQOFF)>> 3)
end_define

begin_comment
comment|/* convert byte offset to reg value */
end_comment

begin_define
define|#
directive|define
name|MID_DRQ_REG2A
parameter_list|(
name|N
parameter_list|)
value|(((N)<< 3) + MID_DRQOFF)
end_define

begin_comment
comment|/* and back */
end_comment

begin_comment
comment|/* note: format of word 1 of RXQ is different beween ENI and ADP cards */
end_comment

begin_define
define|#
directive|define
name|MID_MK_RXQ_ENI
parameter_list|(
name|CNT
parameter_list|,
name|VC
parameter_list|,
name|END
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|( ((CNT)<< 16)|((VC)<< 6)|(END)|(TYPE) )
end_define

begin_define
define|#
directive|define
name|MID_MK_RXQ_ADP
parameter_list|(
name|CNT
parameter_list|,
name|VC
parameter_list|,
name|END
parameter_list|,
name|JK
parameter_list|)
define|\
value|( ((CNT)<< 12)|((VC)<< 2)|((END)>> 4)|(((JK) != 0) ? 1 : 0))
end_define

begin_comment
comment|/*  * dma xmit q.  */
end_comment

begin_define
define|#
directive|define
name|MID_DTQ_N
value|512
end_define

begin_comment
comment|/* # of descriptors */
end_comment

begin_define
define|#
directive|define
name|MID_DTQ_A2REG
parameter_list|(
name|N
parameter_list|)
value|(((N) - MID_DTQOFF)>> 3)
end_define

begin_comment
comment|/* convert byte offset to reg value */
end_comment

begin_define
define|#
directive|define
name|MID_DTQ_REG2A
parameter_list|(
name|N
parameter_list|)
value|(((N)<< 3) + MID_DTQOFF)
end_define

begin_comment
comment|/* and back */
end_comment

begin_comment
comment|/* note: format of word 1 of TXQ is different beween ENI and ADP cards */
end_comment

begin_define
define|#
directive|define
name|MID_MK_TXQ_ENI
parameter_list|(
name|CNT
parameter_list|,
name|CHN
parameter_list|,
name|END
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|( ((CNT)<< 16)|((CHN)<< 6)|(END)|(TYPE) )
end_define

begin_define
define|#
directive|define
name|MID_MK_TXQ_ADP
parameter_list|(
name|CNT
parameter_list|,
name|CHN
parameter_list|,
name|END
parameter_list|,
name|JK
parameter_list|)
define|\
value|( ((CNT)<< 12)|((CHN)<< 2)|((END)>> 4)|(((JK) != 0) ? 1 : 0) )
end_define

begin_comment
comment|/*  * dma types  */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_JK
value|0x3
end_define

begin_comment
comment|/* just kidding */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_BYTE
value|0x1
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_2BYTE
value|0x2
end_define

begin_comment
comment|/* 2 bytes */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_WORD
value|0x0
end_define

begin_comment
comment|/* word */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_2WORD
value|0x7
end_define

begin_comment
comment|/* 2 words */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_4WORD
value|0x4
end_define

begin_comment
comment|/* 4 words */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_8WORD
value|0x5
end_define

begin_comment
comment|/* 8 words */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_16WORD
value|0x6
end_define

begin_comment
comment|/* 16 words!!! */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_2WMAYBE
value|0xf
end_define

begin_comment
comment|/* 2 words, maybe */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_4WMAYBE
value|0xc
end_define

begin_comment
comment|/* 4 words, maybe */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_8WMAYBE
value|0xd
end_define

begin_comment
comment|/* 8 words, maybe */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_16WMAYBE
value|0xe
end_define

begin_comment
comment|/* 16 words, maybe */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_MAYBE
value|0xc
end_define

begin_comment
comment|/* mask to detect WMAYBE dma code */
end_comment

begin_define
define|#
directive|define
name|MIDDMA_MAXBURST
value|(16 * sizeof(u_int32_t))
end_define

begin_comment
comment|/* largest burst */
end_comment

begin_comment
comment|/*  * service list  */
end_comment

begin_define
define|#
directive|define
name|MID_SL_N
value|1024
end_define

begin_comment
comment|/* max # entries on slist */
end_comment

begin_define
define|#
directive|define
name|MID_SL_A2REG
parameter_list|(
name|N
parameter_list|)
value|(((N) - MID_SLOFF)>> 2)
end_define

begin_comment
comment|/* convert byte offset to reg value */
end_comment

begin_define
define|#
directive|define
name|MID_SL_REG2A
parameter_list|(
name|N
parameter_list|)
value|(((N)<< 2) + MID_SLOFF)
end_define

begin_comment
comment|/* and back */
end_comment

begin_comment
comment|/*  * data in the buffer area of obmem  */
end_comment

begin_comment
comment|/*  * recv buffer desc. (1 u_int32_t at start of buffer)  */
end_comment

begin_define
define|#
directive|define
name|MID_RBD_SIZE
value|4
end_define

begin_comment
comment|/* RBD size */
end_comment

begin_define
define|#
directive|define
name|MID_CHDR_SIZE
value|4
end_define

begin_comment
comment|/* on aal0, cell header size */
end_comment

begin_define
define|#
directive|define
name|MID_RBD_ID
parameter_list|(
name|X
parameter_list|)
value|((X)& 0xfe000000)
end_define

begin_comment
comment|/* get ID */
end_comment

begin_define
define|#
directive|define
name|MID_RBD_STDID
value|0x36000000
end_define

begin_comment
comment|/* standard ID */
end_comment

begin_define
define|#
directive|define
name|MID_RBD_CLP
value|0x01000000
end_define

begin_comment
comment|/* CLP: cell loss priority */
end_comment

begin_define
define|#
directive|define
name|MID_RBD_CE
value|0x00010000
end_define

begin_comment
comment|/* CE: congestion experienced */
end_comment

begin_define
define|#
directive|define
name|MID_RBD_T
value|0x00001000
end_define

begin_comment
comment|/* T: trashed due to overflow */
end_comment

begin_define
define|#
directive|define
name|MID_RBD_CRCERR
value|0x00000800
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|MID_RBD_CNT
parameter_list|(
name|X
parameter_list|)
value|((X)& 0x7ff)
end_define

begin_comment
comment|/* cell count */
end_comment

begin_comment
comment|/*  * xmit buffer desc. (2 u_int32_t's at start of buffer)  * (note we treat the PR& RATE as a single u_int8_t)  */
end_comment

begin_define
define|#
directive|define
name|MID_TBD_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|MID_TBD_MK1
parameter_list|(
name|AAL
parameter_list|,
name|PR_RATE
parameter_list|,
name|CNT
parameter_list|)
define|\
value|(MID_TBD_STDID|(AAL)|((PR_RATE)<< 19)|(CNT))
end_define

begin_define
define|#
directive|define
name|MID_TBD_STDID
value|0xb0000000
end_define

begin_comment
comment|/* standard ID */
end_comment

begin_define
define|#
directive|define
name|MID_TBD_AAL5
value|0x08000000
end_define

begin_comment
comment|/* AAL 5 */
end_comment

begin_define
define|#
directive|define
name|MID_TBD_NOAAL5
value|0x00000000
end_define

begin_comment
comment|/* not AAL 5 */
end_comment

begin_define
define|#
directive|define
name|MID_TBD_MK2
parameter_list|(
name|VCI
parameter_list|,
name|PTI
parameter_list|,
name|CLP
parameter_list|)
define|\
value|(((VCI)<< 4)|((PTI)<< 1)|(CLP))
end_define

begin_comment
comment|/*  * aal5 pdu tail, last 2 words of last cell of AAL5 frame  * (word 2 is CRC .. handled by hw)  */
end_comment

begin_define
define|#
directive|define
name|MID_PDU_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|MID_PDU_MK1
parameter_list|(
name|UU
parameter_list|,
name|CPI
parameter_list|,
name|LEN
parameter_list|)
define|\
value|(((UU)<< 24)|((CPI)<< 16)|(LEN))
end_define

begin_define
define|#
directive|define
name|MID_PDU_LEN
parameter_list|(
name|X
parameter_list|)
value|((X)& 0xffff)
end_define

end_unit

