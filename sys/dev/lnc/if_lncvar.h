begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Paul Richards. This software may be used, modified,  *   copied, distributed, and sold, in both source and binary form provided  *   that the above copyright and these terms are retained. Under no  *   circumstances is the author responsible for the proper functioning  *   of this software, nor does the author assume any responsibility  *   for damages incurred with its use.  *  */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/ic/Am7990.h>
end_include

begin_comment
comment|/*  * Initialize multicast address hashing registers to accept  * all multicasts (only used when in promiscuous mode)  */
end_comment

begin_if
if|#
directive|if
name|NBPFILTER
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|MULTI_INIT_ADDR
value|0xff
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTI_INIT_ADDR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|NRDRE
value|3
end_define

begin_define
define|#
directive|define
name|NTDRE
value|3
end_define

begin_define
define|#
directive|define
name|RECVBUFSIZE
value|1518
end_define

begin_comment
comment|/* Packet size rounded to dword boundary */
end_comment

begin_define
define|#
directive|define
name|TRANSBUFSIZE
value|1518
end_define

begin_define
define|#
directive|define
name|MBUF_CACHE_LIMIT
value|0
end_define

begin_define
define|#
directive|define
name|MEM_SLEW
value|8
end_define

begin_comment
comment|/* BICC port addresses */
end_comment

begin_define
define|#
directive|define
name|BICC_IOSIZE
value|16
end_define

begin_define
define|#
directive|define
name|BICC_RDP
value|0x0c
end_define

begin_comment
comment|/* Register Data Port */
end_comment

begin_define
define|#
directive|define
name|BICC_RAP
value|0x0e
end_define

begin_comment
comment|/* Register Address Port */
end_comment

begin_comment
comment|/* NE2100 port addresses */
end_comment

begin_define
define|#
directive|define
name|NE2100_IOSIZE
value|24
end_define

begin_define
define|#
directive|define
name|PCNET_RDP
value|0x10
end_define

begin_comment
comment|/* Register Data Port */
end_comment

begin_define
define|#
directive|define
name|PCNET_RAP
value|0x12
end_define

begin_comment
comment|/* Register Address Port */
end_comment

begin_define
define|#
directive|define
name|PCNET_RESET
value|0x14
end_define

begin_define
define|#
directive|define
name|PCNET_IDP
value|0x16
end_define

begin_define
define|#
directive|define
name|PCNET_VSW
value|0x18
end_define

begin_comment
comment|/* DEPCA port addresses */
end_comment

begin_define
define|#
directive|define
name|DEPCA_IOSIZE
value|16
end_define

begin_define
define|#
directive|define
name|DEPCA_CTRL
value|0x00
end_define

begin_comment
comment|/* NIC Control and status register */
end_comment

begin_define
define|#
directive|define
name|DEPCA_RDP
value|0x04
end_define

begin_comment
comment|/* Register Data Port */
end_comment

begin_define
define|#
directive|define
name|DEPCA_RAP
value|0x06
end_define

begin_comment
comment|/* Register Address Port */
end_comment

begin_define
define|#
directive|define
name|DEPCA_ADP
value|0x0c
end_define

begin_comment
comment|/* DEPCA specific defines */
end_comment

begin_define
define|#
directive|define
name|DEPCA_ADDR_ROM_SIZE
value|32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* C-NET(98)S port addresses */
end_comment

begin_define
define|#
directive|define
name|CNET98S_RDP
value|0x400
end_define

begin_comment
comment|/* Register Data Port */
end_comment

begin_define
define|#
directive|define
name|CNET98S_RAP
value|0x402
end_define

begin_comment
comment|/* Register Address Port */
end_comment

begin_define
define|#
directive|define
name|CNET98S_RESET
value|0x404
end_define

begin_define
define|#
directive|define
name|CNET98S_IDP
value|0x406
end_define

begin_define
define|#
directive|define
name|CNET98S_EEPROM
value|0x40e
end_define

begin_comment
comment|/*  * XXX - The I/O address range is fragmented in the C-NET(98)S.  *       This is the number of regs at iobase.  */
end_comment

begin_define
define|#
directive|define
name|CNET98S_IOSIZE
value|16
end_define

begin_comment
comment|/* # of i/o addresses used. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Chip types */
end_comment

begin_define
define|#
directive|define
name|LANCE
value|1
end_define

begin_comment
comment|/* Am7990   */
end_comment

begin_define
define|#
directive|define
name|C_LANCE
value|2
end_define

begin_comment
comment|/* Am79C90  */
end_comment

begin_define
define|#
directive|define
name|PCnet_ISA
value|3
end_define

begin_comment
comment|/* Am79C960 */
end_comment

begin_define
define|#
directive|define
name|PCnet_ISAplus
value|4
end_define

begin_comment
comment|/* Am79C961 */
end_comment

begin_define
define|#
directive|define
name|PCnet_32
value|5
end_define

begin_comment
comment|/* Am79C965 */
end_comment

begin_define
define|#
directive|define
name|PCnet_PCI
value|6
end_define

begin_comment
comment|/* Am79C970 */
end_comment

begin_comment
comment|/* CSR88-89: Chip ID masks */
end_comment

begin_define
define|#
directive|define
name|AMD_MASK
value|0x003
end_define

begin_define
define|#
directive|define
name|PART_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|Am79C960
value|0x0003
end_define

begin_define
define|#
directive|define
name|Am79C961
value|0x2260
end_define

begin_define
define|#
directive|define
name|Am79C965
value|0x2430
end_define

begin_define
define|#
directive|define
name|Am79C970
value|0x0242
end_define

begin_comment
comment|/* Board types */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|BICC
value|1
end_define

begin_define
define|#
directive|define
name|NE2100
value|2
end_define

begin_define
define|#
directive|define
name|DEPCA
value|3
end_define

begin_define
define|#
directive|define
name|CNET98S
value|4
end_define

begin_comment
comment|/* PC-98 */
end_comment

begin_comment
comment|/* mem_mode values */
end_comment

begin_define
define|#
directive|define
name|DMA_FIXED
value|1
end_define

begin_define
define|#
directive|define
name|DMA_MBUF
value|2
end_define

begin_define
define|#
directive|define
name|SHMEM
value|4
end_define

begin_define
define|#
directive|define
name|MEM_MODES
define|\
value|"\20\3SHMEM\2DMA_MBUF\1DMA_FIXED"
end_define

begin_define
define|#
directive|define
name|CSR0_FLAGS
define|\
value|"\20\20ERR\17BABL\16CERR\15MISS\14MERR\13RINT\12TINT\11IDON\ 	    \10INTR\07INEA\06RXON\05TXON\04TDMD\03STOP\02STRT\01INIT"
end_define

begin_define
define|#
directive|define
name|INIT_MODE
define|\
value|"\20\20PROM\07INTL\06DRTY\05COLL\04DTCR\03LOOP\02DTX\01DRX"
end_define

begin_define
define|#
directive|define
name|RECV_MD1
define|\
value|"\20\10OWN\7ERR\6FRAM\5OFLO\4CRC\3BUFF\2STP\1ENP"
end_define

begin_define
define|#
directive|define
name|TRANS_MD1
define|\
value|"\20\10OWN\7ERR\6RES\5MORE\4ONE\3DEF\2STP\1ENP"
end_define

begin_define
define|#
directive|define
name|TRANS_MD3
define|\
value|"\20\6BUFF\5UFLO\4RES\3LCOL\2LCAR\1RTRY"
end_define

begin_struct
struct|struct
name|nic_info
block|{
name|int
name|ident
decl_stmt|;
comment|/* Type of card */
name|int
name|ic
decl_stmt|;
comment|/* Type of ic, Am7990, Am79C960 etc. */
name|int
name|mem_mode
decl_stmt|;
name|int
name|iobase
decl_stmt|;
name|int
name|mode
decl_stmt|;
comment|/* Mode setting at initialization */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|host_ring_entry
block|{
name|struct
name|mds
modifier|*
name|md
decl_stmt|;
union|union
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|buff
union|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|LNC_KEEP_STATS
end_ifdef

begin_define
define|#
directive|define
name|LNCSTATS_STRUCT
define|\
value|struct lnc_stats { \ 		int idon; \ 		int rint; \ 		int tint; \ 		int cerr; \ 		int babl; \ 		int miss; \ 		int merr; \ 		int rxoff; \ 		int txoff; \ 		int terr; \ 		int lcol; \ 		int lcar; \ 		int tbuff; \ 		int def; \ 		int more; \ 		int one; \ 		int uflo; \ 		int rtry; \ 		int rerr; \ 		int fram; \ 		int oflo; \ 		int crc; \ 		int rbuff; \ 		int drop_packet; \ 		int trans_ring_full; \ 	} lnc_stats;
end_define

begin_define
define|#
directive|define
name|LNCSTATS
parameter_list|(
name|X
parameter_list|)
value|++(sc->lnc_stats.X);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LNCSTATS_STRUCT
end_define

begin_define
define|#
directive|define
name|LNCSTATS
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NDESC
parameter_list|(
name|len2
parameter_list|)
value|(1<< len2)
end_define

begin_define
define|#
directive|define
name|INC_MD_PTR
parameter_list|(
name|ptr
parameter_list|,
name|no_entries
parameter_list|)
define|\
value|if (++ptr>= NDESC(no_entries)) \ 		ptr = 0;
end_define

begin_define
define|#
directive|define
name|DEC_MD_PTR
parameter_list|(
name|ptr
parameter_list|,
name|no_entries
parameter_list|)
define|\
value|if (--ptr< 0) \ 		ptr = NDESC(no_entries) - 1;
end_define

begin_define
define|#
directive|define
name|RECV_NEXT
value|(sc->recv_ring->base + sc->recv_next)
end_define

begin_define
define|#
directive|define
name|TRANS_NEXT
value|(sc->trans_ring->base + sc->trans_next)
end_define

end_unit

