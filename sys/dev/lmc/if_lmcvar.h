begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1997 Matt Thomas (matt@3am-software.com)  * Copyright (c) LAN Media Corporation 1998, 1999.  * Copyright (c) 2000 Stephen Kiernan (sk-ports@vegamuse.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *	From NetBSD: if_devar.h,v 1.21 1997/10/16 22:02:32 matt Exp  *	$Id: if_lmcvar.h,v 1.6 1999/01/12 14:16:58 explorer Exp $  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_DEV_LMC_IF_LMCVAR_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DEV_LMC_IF_LMCVAR_H
end_define

begin_define
define|#
directive|define
name|LMC_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|PPP_HEADER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|BIG_PACKET
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PCI_VENDOR_LMC
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCI_VENDOR_LMC
value|0x1376
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PCI_PRODUCT_LMC_HSSI
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCI_PRODUCT_LMC_HSSI
value|0x0003
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PCI_PRODUCT_LMC_DS3
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCI_PRODUCT_LMC_DS3
value|0x0004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PCI_PRODUCT_LMC_SSI
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCI_PRODUCT_LMC_SSI
value|0x0005
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PCI_PRODUCT_LMC_T1
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCI_PRODUCT_LMC_T1
value|0x0006
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LMC_IOMAPPED
end_ifdef

begin_define
define|#
directive|define
name|LMC_EISA_CSRSIZE
value|16
end_define

begin_define
define|#
directive|define
name|LMC_EISA_CSROFFSET
value|0
end_define

begin_define
define|#
directive|define
name|LMC_PCI_CSRSIZE
value|8
end_define

begin_define
define|#
directive|define
name|LMC_PCI_CSROFFSET
value|0
end_define

begin_typedef
typedef|typedef
name|u_int16_t
name|lmc_csrptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LMC_CSR_READ
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|)
value|(inl((sc)->lmc_csrs.csr))
end_define

begin_define
define|#
directive|define
name|LMC_CSR_WRITE
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|,
name|val
parameter_list|)
value|outl((sc)->lmc_csrs.csr, val)
end_define

begin_define
define|#
directive|define
name|LMC_CSR_READBYTE
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|)
value|(inb((sc)->lmc_csrs.csr))
end_define

begin_define
define|#
directive|define
name|LMC_CSR_WRITEBYTE
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|,
name|val
parameter_list|)
value|outb((sc)->lmc_csrs.csr, val)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LMC_IOMAPPED */
end_comment

begin_define
define|#
directive|define
name|LMC_PCI_CSRSIZE
value|8
end_define

begin_define
define|#
directive|define
name|LMC_PCI_CSROFFSET
value|0
end_define

begin_typedef
typedef|typedef
specifier|volatile
name|u_int32_t
modifier|*
name|lmc_csrptr_t
typedef|;
end_typedef

begin_comment
comment|/*  * macros to read and write CSRs.  Note that the "0 +" in  * READ_CSR is to prevent the macro from being an lvalue  * and WRITE_CSR shouldn't be assigned from.  */
end_comment

begin_define
define|#
directive|define
name|LMC_CSR_READ
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|)
value|(0 + *(sc)->lmc_csrs.csr)
end_define

begin_define
define|#
directive|define
name|LMC_CSR_WRITE
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|,
name|val
parameter_list|)
value|((void)(*(sc)->lmc_csrs.csr = (val)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LMC_IOMAPPED */
end_comment

begin_comment
comment|/*  * This structure contains "pointers" for the registers on  * the various 21x4x chips.  CSR0 through CSR8 are common  * to all chips.  After that, it gets messy...  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|lmc_csrptr_t
name|csr_busmode
decl_stmt|;
comment|/* CSR0 */
name|lmc_csrptr_t
name|csr_txpoll
decl_stmt|;
comment|/* CSR1 */
name|lmc_csrptr_t
name|csr_rxpoll
decl_stmt|;
comment|/* CSR2 */
name|lmc_csrptr_t
name|csr_rxlist
decl_stmt|;
comment|/* CSR3 */
name|lmc_csrptr_t
name|csr_txlist
decl_stmt|;
comment|/* CSR4 */
name|lmc_csrptr_t
name|csr_status
decl_stmt|;
comment|/* CSR5 */
name|lmc_csrptr_t
name|csr_command
decl_stmt|;
comment|/* CSR6 */
name|lmc_csrptr_t
name|csr_intr
decl_stmt|;
comment|/* CSR7 */
name|lmc_csrptr_t
name|csr_missed_frames
decl_stmt|;
comment|/* CSR8 */
name|lmc_csrptr_t
name|csr_9
decl_stmt|;
comment|/* CSR9 */
name|lmc_csrptr_t
name|csr_10
decl_stmt|;
comment|/* CSR10 */
name|lmc_csrptr_t
name|csr_11
decl_stmt|;
comment|/* CSR11 */
name|lmc_csrptr_t
name|csr_12
decl_stmt|;
comment|/* CSR12 */
name|lmc_csrptr_t
name|csr_13
decl_stmt|;
comment|/* CSR13 */
name|lmc_csrptr_t
name|csr_14
decl_stmt|;
comment|/* CSR14 */
name|lmc_csrptr_t
name|csr_15
decl_stmt|;
comment|/* CSR15 */
block|}
name|lmc_regfile_t
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
comment|/*  * While 21x4x allows chaining of its descriptors, this driver  * doesn't take advantage of it.  We keep the descriptors in a  * traditional FIFO ring.    */
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
name|lmc_ringinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * The 21040 has a stupid restriction in that the receive  * buffers must be longword aligned.  But since Ethernet  * headers are not a multiple of longwords in size this forces  * the data to non-longword aligned.  Since IP requires the  * data to be longword aligned, we need to copy it after it has  * been DMA'ed in our memory.  *  * Since we have to copy it anyways, we might as well as allocate  * dedicated receive space for the input.  This allows to use a  * small receive buffer size and more ring entries to be able to  * better keep with a flood of tiny Ethernet packets.  *  * The receive space MUST ALWAYS be a multiple of the page size.  * And the number of receive descriptors multiplied by the size  * of the receive buffers must equal the recevive space.  This  * is so that we can manipulate the page tables so that even if a  * packet wraps around the end of the receive space, we can   * treat it as virtually contiguous.  *  * The above used to be true (the stupid restriction is still true)  * but we gone to directly DMA'ing into MBUFs (unless it's on an   * architecture which can't handle unaligned accesses) because with  * 100Mb/s cards the copying is just too much of a hit.  */
end_comment

begin_define
define|#
directive|define
name|LMC_RXDESCS
value|48
end_define

begin_define
define|#
directive|define
name|LMC_TXDESCS
value|128
end_define

begin_define
define|#
directive|define
name|LMC_RXQ_TARGET
value|32
end_define

begin_if
if|#
directive|if
name|LMC_RXQ_TARGET
operator|>=
name|LMC_RXDESCS
end_if

begin_error
error|#
directive|error
error|LMC_RXQ_TARGET must be less than LMC_RXDESCS
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LMC_RX_BUFLEN
value|((MCLBYTES< 2048 ? MCLBYTES : 2048) - 16)
end_define

begin_comment
comment|/*  * The various controllers support.  Technically the DE425 is just  * a 21040 on EISA.  But since it remarkably difference from normal  * 21040s, we give it its own chip id.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LMC_21140
block|,
name|LMC_21140A
block|,
name|LMC_CHIPID_UNKNOWN
block|}
name|lmc_chipid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LMC_BIT
parameter_list|(
name|b
parameter_list|)
value|(1L<< ((int)(b)))
end_define

begin_typedef
typedef|typedef
struct|struct
name|lmc_xinfo
block|{
name|u_int32_t
name|Magic0
decl_stmt|;
comment|/* BEEFCAFE */
name|u_int32_t
name|PciCardType
decl_stmt|;
name|u_int32_t
name|PciSlotNumber
decl_stmt|;
comment|/* PCI slot number       */
name|u_int16_t
name|DriverMajorVersion
decl_stmt|;
name|u_int16_t
name|DriverMinorVersion
decl_stmt|;
name|u_int16_t
name|DriverSubVersion
decl_stmt|;
name|u_int16_t
name|XilinxRevisionNumber
decl_stmt|;
name|u_int16_t
name|MaxFrameSize
decl_stmt|;
name|u_int16_t
name|t1_alarm1_status
decl_stmt|;
name|u_int16_t
name|t1_alarm2_status
decl_stmt|;
name|int
name|link_status
decl_stmt|;
name|u_int32_t
name|mii_reg16
decl_stmt|;
name|u_int32_t
name|Magic1
decl_stmt|;
comment|/* DEADBEEF */
block|}
name|LMC_XINFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/*      * Transmit Statistics      */
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
name|u_int32_t
name|dot3StatsInternalTransmitUnderflows
decl_stmt|;
comment|/* not in rfc1650! */
name|u_int32_t
name|dot3StatsInternalTransmitBabbles
decl_stmt|;
comment|/* not in rfc1650! */
comment|/*      * Receive Statistics      */
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
name|lmc_dot3_stats_t
typedef|;
end_typedef

begin_comment
comment|/*  * Now to important stuff.  This is softc structure (where does softc  * come from??? No idea) for the tulip device.    *  */
end_comment

begin_struct
struct|struct
name|lmc___softc
block|{
specifier|const
name|char
modifier|*
name|lmc_name
decl_stmt|;
name|int
name|lmc_unit
decl_stmt|;
name|u_int8_t
name|lmc_enaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* yes, a small hack... */
name|lmc_regfile_t
name|lmc_csrs
decl_stmt|;
specifier|volatile
name|u_int32_t
name|lmc_txtick
decl_stmt|;
specifier|volatile
name|u_int32_t
name|lmc_rxtick
decl_stmt|;
name|u_int32_t
name|lmc_flags
decl_stmt|;
name|u_int32_t
name|lmc_features
decl_stmt|;
comment|/* static bits indicating features of chip */
name|u_int32_t
name|lmc_intrmask
decl_stmt|;
comment|/* our copy of csr_intr */
name|u_int32_t
name|lmc_cmdmode
decl_stmt|;
comment|/* our copy of csr_cmdmode */
name|u_int32_t
name|lmc_last_system_error
range|:
literal|3
decl_stmt|;
comment|/* last system error (only value is LMC_SYSTEMERROR is also set) */
name|u_int32_t
name|lmc_system_errors
decl_stmt|;
comment|/* number of system errors encountered */
name|u_int32_t
name|lmc_statusbits
decl_stmt|;
comment|/* status bits from CSR5 that may need to be printed */
name|u_int8_t
name|lmc_revinfo
decl_stmt|;
comment|/* revision of chip */
name|u_int8_t
name|lmc_cardtype
decl_stmt|;
comment|/* LMC_CARDTYPE_HSSI or ..._DS3 */
name|u_int32_t
name|lmc_gpio_io
decl_stmt|;
comment|/* state of in/out settings */
name|u_int32_t
name|lmc_gpio
decl_stmt|;
comment|/* state of outputs */
name|u_int8_t
name|lmc_gp
decl_stmt|;
name|lmc_chipid_t
name|lmc_chipid
decl_stmt|;
comment|/* type of chip we are using */
name|u_int32_t
name|lmc_miireg16
decl_stmt|;
name|struct
name|ifqueue
name|lmc_txq
decl_stmt|;
name|struct
name|ifqueue
name|lmc_rxq
decl_stmt|;
name|lmc_dot3_stats_t
name|lmc_dot3stats
decl_stmt|;
name|lmc_ringinfo_t
name|lmc_rxinfo
decl_stmt|;
name|lmc_ringinfo_t
name|lmc_txinfo
decl_stmt|;
name|u_int8_t
name|lmc_rombuf
index|[
literal|128
index|]
decl_stmt|;
name|lmc_media_t
modifier|*
name|lmc_media
decl_stmt|;
name|lmc_ctl_t
name|ictl
decl_stmt|;
name|LMC_XINFO
name|lmc_xinfo
decl_stmt|;
name|u_int8_t
name|lmc_pci_busno
decl_stmt|;
comment|/* needed for multiport boards */
name|u_int8_t
name|lmc_pci_devno
decl_stmt|;
comment|/* needed for multiport boards */
name|tulip_desc_t
modifier|*
name|lmc_rxdescs
decl_stmt|;
name|tulip_desc_t
modifier|*
name|lmc_txdescs
decl_stmt|;
name|u_int32_t
name|lmc_crcSize
decl_stmt|;
name|char
name|lmc_timing
decl_stmt|;
comment|/* for HSSI and SSI */
name|u_int16_t
name|t1_alarm1_status
decl_stmt|;
name|u_int16_t
name|t1_alarm2_status
decl_stmt|;
name|int
name|lmc_running
decl_stmt|;
name|char
name|lmc_nodename
index|[
name|NG_NODELEN
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|lmc_datahooks
decl_stmt|;
name|node_p
name|lmc_node
decl_stmt|;
name|hook_p
name|lmc_hook
decl_stmt|;
name|hook_p
name|lmc_debug_hook
decl_stmt|;
name|struct
name|ifqueue
name|lmc_xmitq_hipri
decl_stmt|;
name|struct
name|ifqueue
name|lmc_xmitq
decl_stmt|;
name|struct
name|callout_handle
name|lmc_handle
decl_stmt|;
name|char
name|lmc_xmit_busy
decl_stmt|;
name|int
name|lmc_out_dog
decl_stmt|;
name|u_long
name|lmc_inbytes
decl_stmt|,
name|lmc_outbytes
decl_stmt|;
comment|/* stats */
name|u_long
name|lmc_lastinbytes
decl_stmt|,
name|lmc_lastoutbytes
decl_stmt|;
comment|/* a second ago */
name|u_long
name|lmc_inrate
decl_stmt|,
name|lmc_outrate
decl_stmt|;
comment|/* highest rate seen */
name|u_long
name|lmc_inlast
decl_stmt|;
comment|/* last input N secs ago */
name|u_long
name|lmc_out_deficit
decl_stmt|;
comment|/* output since last input */
name|u_long
name|lmc_oerrors
decl_stmt|,
name|lmc_ierrors
decl_stmt|;
name|u_long
name|lmc_opackets
decl_stmt|,
name|lmc_ipackets
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LMC_DOG_HOLDOFF
value|6
end_define

begin_comment
comment|/* dog holds off for 6 secs */
end_comment

begin_define
define|#
directive|define
name|LMC_QUITE_A_WHILE
value|300
end_define

begin_comment
comment|/* 5 MINUTES */
end_comment

begin_define
define|#
directive|define
name|LMC_LOTS_OF_PACKETS
value|100
end_define

begin_comment
comment|/* Node type name and type cookie */
end_comment

begin_define
define|#
directive|define
name|NG_LMC_NODE_TYPE
value|"lmc"
end_define

begin_define
define|#
directive|define
name|NG_LMC_COOKIE
value|956095698
end_define

begin_comment
comment|/* Netgraph hooks */
end_comment

begin_define
define|#
directive|define
name|NG_LMC_HOOK_DEBUG
value|"debug"
end_define

begin_define
define|#
directive|define
name|NG_LMC_HOOK_CONTROL
value|"control"
end_define

begin_define
define|#
directive|define
name|NG_LMC_HOOK_RAW
value|"rawdata"
end_define

begin_comment
comment|/* Netgraph commands understood by this node type */
end_comment

begin_enum
enum|enum
block|{
name|NGM_LMC_SET_CTL
init|=
literal|1
block|,
name|NGM_LMC_GET_CTL
block|, }
enum|;
end_enum

begin_comment
comment|/*  * lmc_flags  */
end_comment

begin_define
define|#
directive|define
name|LMC_IFUP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LMC_00000002
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LMC_00000004
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LMC_00000008
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LMC_00000010
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LMC_MODEMOK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LMC_00000040
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LMC_00000080
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LMC_RXACT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LMC_INRESET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LMC_NEEDRESET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LMC_00000800
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LMC_00001000
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LMC_00002000
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LMC_WANTTXSTART
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LMC_NEWTXTHRESH
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LMC_NOAUTOSENSE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LMC_PRINTLINKUP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LMC_LINKUP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LMC_RXBUFSLOW
value|0x00080000
end_define

begin_define
define|#
directive|define
name|LMC_NOMESSAGES
value|0x00100000
end_define

begin_define
define|#
directive|define
name|LMC_SYSTEMERROR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|LMC_TIMEOUTPENDING
value|0x00400000
end_define

begin_define
define|#
directive|define
name|LMC_00800000
value|0x00800000
end_define

begin_define
define|#
directive|define
name|LMC_01000000
value|0x01000000
end_define

begin_define
define|#
directive|define
name|LMC_02000000
value|0x02000000
end_define

begin_define
define|#
directive|define
name|LMC_RXIGNORE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|LMC_08000000
value|0x08000000
end_define

begin_define
define|#
directive|define
name|LMC_10000000
value|0x10000000
end_define

begin_define
define|#
directive|define
name|LMC_20000000
value|0x20000000
end_define

begin_define
define|#
directive|define
name|LMC_40000000
value|0x40000000
end_define

begin_define
define|#
directive|define
name|LMC_80000000
value|0x80000000
end_define

begin_comment
comment|/*  * lmc_features  */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_GPR
value|0x00000001
end_define

begin_comment
comment|/* have gp register (140[A]) */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_RXBADOVRFLW
value|0x00000002
end_define

begin_comment
comment|/* RX corrupts on overflow */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_POWERMGMT
value|0x00000004
end_define

begin_comment
comment|/* Snooze/sleep modes */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_MII
value|0x00000008
end_define

begin_comment
comment|/* Some medium on MII */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_SIANWAY
value|0x00000010
end_define

begin_comment
comment|/* SIA does NWAY */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_DUALSENSE
value|0x00000020
end_define

begin_comment
comment|/* SIA senses both AUI& TP */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_SIAGP
value|0x00000040
end_define

begin_comment
comment|/* SIA has a GP port */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_BROKEN_HASH
value|0x00000080
end_define

begin_comment
comment|/* Broken Multicast Hash */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_ISVSROM
value|0x00000100
end_define

begin_comment
comment|/* uses ISV SROM Format */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_BASEROM
value|0x00000200
end_define

begin_comment
comment|/* Board ROM can be cloned */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_SLAVEDROM
value|0x00000400
end_define

begin_comment
comment|/* Board ROM cloned */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_SLAVEDINTR
value|0x00000800
end_define

begin_comment
comment|/* Board slaved interrupt */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_SHAREDINTR
value|0x00001000
end_define

begin_comment
comment|/* Board shares interrupts */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_OKROM
value|0x00002000
end_define

begin_comment
comment|/* ROM was recognized */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_NOMEDIA
value|0x00004000
end_define

begin_comment
comment|/* did not detect any media */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_STOREFWD
value|0x00008000
end_define

begin_comment
comment|/* have CMD_STOREFWD */
end_comment

begin_define
define|#
directive|define
name|LMC_HAVE_SIA100
value|0x00010000
end_define

begin_comment
comment|/* has LS100 in SIA status */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|lmc_system_errors
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
name|lmc_status_bits
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

begin_comment
comment|/*  * This driver supports a maximum of 32 tulip boards.  * This should be enough for the forseeable future.  */
end_comment

begin_define
define|#
directive|define
name|LMC_MAX_DEVICES
value|32
end_define

begin_typedef
typedef|typedef
name|void
name|ifnet_ret_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ioctl_cmd_t
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|lmc_softc_t
modifier|*
name|tulips
index|[
name|LMC_MAX_DEVICES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LMC_IFP_TO_SOFTC
parameter_list|(
name|ifp
parameter_list|)
value|((lmc_softc_t *)((ifp)->if_softc))
end_define

begin_define
define|#
directive|define
name|lmc_intrfunc_t
value|void
end_define

begin_define
define|#
directive|define
name|LMC_VOID_INTRFUNC
end_define

begin_define
define|#
directive|define
name|IFF_NOTRAILERS
value|0
end_define

begin_define
define|#
directive|define
name|CLBYTES
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|LMC_EADDR_FMT
value|"%6D"
end_define

begin_define
define|#
directive|define
name|LMC_EADDR_ARGS
parameter_list|(
name|addr
parameter_list|)
value|addr, ":"
end_define

begin_define
define|#
directive|define
name|LMC_UNIT_TO_SOFTC
parameter_list|(
name|unit
parameter_list|)
value|(tulips[unit])
end_define

begin_define
define|#
directive|define
name|LMC_BURSTSIZE
parameter_list|(
name|unit
parameter_list|)
value|pci_max_burst_len
end_define

begin_define
define|#
directive|define
name|loudprintf
value|if (bootverbose) printf
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LMC_PRINTF_FMT
end_ifndef

begin_define
define|#
directive|define
name|LMC_PRINTF_FMT
value|"%s%d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LMC_PRINTF_ARGS
end_ifndef

begin_define
define|#
directive|define
name|LMC_PRINTF_ARGS
value|sc->lmc_name, sc->lmc_unit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LMC_BURSTSIZE
end_ifndef

begin_define
define|#
directive|define
name|LMC_BURSTSIZE
parameter_list|(
name|unit
parameter_list|)
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lmc_intrfunc_t
argument_list|)
end_if

begin_define
define|#
directive|define
name|lmc_intrfunc_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LMC_KVATOPHYS
argument_list|)
end_if

begin_define
define|#
directive|define
name|LMC_KVATOPHYS
parameter_list|(
name|sc
parameter_list|,
name|va
parameter_list|)
value|vtophys(va)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LMC_RAISESPL
end_ifndef

begin_define
define|#
directive|define
name|LMC_RAISESPL
parameter_list|()
value|splimp()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LMC_RAISESOFTSPL
end_ifndef

begin_define
define|#
directive|define
name|LMC_RAISESOFTSPL
parameter_list|()
value|splnet()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TULUP_RESTORESPL
end_ifndef

begin_define
define|#
directive|define
name|LMC_RESTORESPL
parameter_list|(
name|s
parameter_list|)
value|splx(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * While I think FreeBSD's 2.2 change to the bpf is a nice simplification,  * it does add yet more conditional code to this driver.  Sigh.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LMC_BPF_MTAP
argument_list|)
operator|&&
name|NBPFILTER
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|LMC_BPF_MTAP
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|)
value|bpf_mtap((sc)->lmc_bpf, m)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_TAP
parameter_list|(
name|sc
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|bpf_tap((sc)->lmc_bpf, p, l)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_ATTACH
parameter_list|(
name|sc
parameter_list|)
value|bpfattach(&(sc)->lmc_bpf,&(sc)->lmc_sppp.pp_if, DLT_PPP, PPP_HEADER_LEN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * However, this change to FreeBSD I am much less enamored with.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LMC_EADDR_FMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|LMC_EADDR_FMT
value|"%s"
end_define

begin_define
define|#
directive|define
name|LMC_EADDR_ARGS
parameter_list|(
name|addr
parameter_list|)
value|ether_sprintf(addr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LMC_CRC32_POLY
value|0xEDB88320UL
end_define

begin_comment
comment|/* CRC-32 Poly -- Little Endian */
end_comment

begin_define
define|#
directive|define
name|LMC_MAX_TXSEG
value|30
end_define

begin_define
define|#
directive|define
name|LMC_ADDREQUAL
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
name|LMC_ADDRBRDCST
parameter_list|(
name|a1
parameter_list|)
define|\
value|(((u_int16_t *)a1)[0] == 0xFFFFU \&& ((u_int16_t *)a1)[1] == 0xFFFFU \&& ((u_int16_t *)a1)[2] == 0xFFFFU)
end_define

begin_typedef
typedef|typedef
name|int
name|lmc_spl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_DEV_LMC_IF_LMCVAR_H) */
end_comment

end_unit

