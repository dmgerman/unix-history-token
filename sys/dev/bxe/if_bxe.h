begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2011 Broadcom Corporation. All rights reserved.  *  *    Gary Zambrano<zambrano@broadcom.com>  *    David Christensen<davidch@broadcom.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Broadcom Corporation nor the name of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written consent.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_BXE_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_BXE_H
end_define

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_vlan_var.h>
end_include

begin_include
include|#
directive|include
file|<net/zlib.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/in_cksum.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/miivar.h>
end_include

begin_include
include|#
directive|include
file|"miidevs.h"
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|"miibus_if.h"
end_include

begin_comment
comment|/*  * Device identification definitions.  */
end_comment

begin_define
define|#
directive|define
name|BRCM_VENDORID
value|0x14E4
end_define

begin_define
define|#
directive|define
name|BRCM_DEVICEID_BCM57710
value|0x164E
end_define

begin_define
define|#
directive|define
name|BRCM_DEVICEID_BCM57711
value|0x164F
end_define

begin_define
define|#
directive|define
name|BRCM_DEVICEID_BCM57711E
value|0x1650
end_define

begin_define
define|#
directive|define
name|PCI_ANY_ID
value|(u_int16_t) (~0U)
end_define

begin_struct
struct|struct
name|bxe_type
block|{
name|u_int16_t
name|bxe_vid
decl_stmt|;
name|u_int16_t
name|bxe_did
decl_stmt|;
name|u_int16_t
name|bxe_svid
decl_stmt|;
name|u_int16_t
name|bxe_sdid
decl_stmt|;
name|char
modifier|*
name|bxe_name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STORM_ASSERT_ARRAY_SIZE
value|50
end_define

begin_define
define|#
directive|define
name|ATTN_NIG_FOR_FUNC
value|(1L<< 8)
end_define

begin_define
define|#
directive|define
name|ATTN_SW_TIMER_4_FUNC
value|(1L<< 9)
end_define

begin_define
define|#
directive|define
name|GPIO_2_FUNC
value|(1L<< 10)
end_define

begin_define
define|#
directive|define
name|GPIO_3_FUNC
value|(1L<< 11)
end_define

begin_define
define|#
directive|define
name|GPIO_4_FUNC
value|(1L<< 12)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_1
value|(1L<< 13)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_2
value|(1L<< 14)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_3
value|(1L<< 15)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_4
value|(1L<< 13)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_5
value|(1L<< 14)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_6
value|(1L<< 15)
end_define

begin_define
define|#
directive|define
name|ATTN_HARD_WIRED_MASK
value|0xff00
end_define

begin_comment
comment|/*  * Convenience definitions.  */
end_comment

begin_define
define|#
directive|define
name|BXE_CORE_LOCK_INIT
parameter_list|(
name|sc
parameter_list|,
name|name
parameter_list|)
define|\
value|mtx_init(&(sc->bxe_core_mtx), name,				\ 	"BXE Core Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BXE_SP_LOCK_INIT
parameter_list|(
name|sc
parameter_list|,
name|name
parameter_list|)
define|\
value|mtx_init(&(sc->bxe_sp_mtx), name,				\ 	"BXE Slowpath Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BXE_DMAE_LOCK_INIT
parameter_list|(
name|sc
parameter_list|,
name|name
parameter_list|)
define|\
value|mtx_init(&(sc->bxe_dmae_mtx), name,				\ 	"BXE DMAE Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BXE_PHY_LOCK_INIT
parameter_list|(
name|sc
parameter_list|,
name|name
parameter_list|)
define|\
value|mtx_init(&(sc->port.bxe_phy_mtx), name,				\ 	"BXE PHY Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BXE_FWMB_LOCK_INIT
parameter_list|(
name|sc
parameter_list|,
name|name
parameter_list|)
define|\
value|mtx_init(&(sc->bxe_fwmb_mtx), name,				\ 	"BXE FWMB Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BXE_PRINT_LOCK_INIT
parameter_list|(
name|sc
parameter_list|,
name|name
parameter_list|)
define|\
value|mtx_init(&(sc->bxe_print_mtx), name,				\ 	"BXE PRINT Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BXE_CORE_LOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_lock(&(sc->bxe_core_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_SP_LOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_lock(&(sc->bxe_sp_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_DMAE_LOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_lock(&(sc->bxe_dmae_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_PHY_LOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_lock(&(sc->port.bxe_phy_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_FWMB_LOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_lock(&(sc->bxe_fwmb_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_PRINT_LOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_lock(&(sc->bxe_print_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_CORE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_assert(&(sc->bxe_core_mtx), MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BXE_SP_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_assert(&(sc->bxe_sp_mtx), MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BXE_DMAE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_assert(&(sc->bxe_dmae_mtx), MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BXE_PHY_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_assert(&(sc->port.bxe_phy_mtx), MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BXE_CORE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_unlock(&(sc->bxe_core_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_SP_UNLOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_unlock(&(sc->bxe_sp_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_DMAE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_unlock(&(sc->bxe_dmae_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_PHY_UNLOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_unlock(&(sc->port.bxe_phy_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_FWMB_UNLOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_unlock(&(sc->bxe_fwmb_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_PRINT_UNLOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_unlock(&(sc->bxe_print_mtx))
end_define

begin_define
define|#
directive|define
name|BXE_CORE_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
define|\
value|if (mtx_initialized(&(sc->bxe_core_mtx))) {			\ 		mtx_destroy(&(sc->bxe_core_mtx));			\ 	}
end_define

begin_define
define|#
directive|define
name|BXE_SP_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
define|\
value|if (mtx_initialized(&(sc->bxe_sp_mtx))) {			\ 		mtx_destroy(&(sc->bxe_sp_mtx));				\ 	}
end_define

begin_define
define|#
directive|define
name|BXE_DMAE_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
define|\
value|if (mtx_initialized(&(sc->bxe_dmae_mtx))) {			\ 		mtx_destroy(&(sc->bxe_dmae_mtx));			\ 	}
end_define

begin_define
define|#
directive|define
name|BXE_PHY_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
define|\
value|if (mtx_initialized(&(sc->port.bxe_phy_mtx))) {			\ 		mtx_destroy(&(sc->port.bxe_phy_mtx));			\ 	}
end_define

begin_define
define|#
directive|define
name|BXE_FWMB_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
define|\
value|if (mtx_initialized(&(sc->bxe_fwmb_mtx))) {			\ 		mtx_destroy(&(sc->bxe_fwmb_mtx));			\ 	}
end_define

begin_define
define|#
directive|define
name|BXE_PRINT_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
define|\
value|if (mtx_initialized(&(sc->bxe_print_mtx))) {			\ 		mtx_destroy(&(sc->bxe_print_mtx));			\ 	}
end_define

begin_comment
comment|/* Must be used on a CID before placing it on a HW chain. */
end_comment

begin_define
define|#
directive|define
name|HW_CID
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|((BP_PORT(sc)<< 23) | (BP_E1HVN(sc)<< 17) | x)
end_define

begin_comment
comment|/* Used on a CID received from the HW. */
end_comment

begin_define
define|#
directive|define
name|SW_CID
parameter_list|(
name|x
parameter_list|)
define|\
value|(le32toh(x)& (COMMON_RAMROD_ETH_RX_CQE_CID>> 7))
end_define

begin_define
define|#
directive|define
name|CQE_CMD
parameter_list|(
name|x
parameter_list|)
define|\
value|(le32toh(x)>> COMMON_RAMROD_ETH_RX_CQE_CMD_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|DPM_TRIGGER_TYPE
value|0x40
end_define

begin_define
define|#
directive|define
name|DOORBELL
parameter_list|(
name|sc
parameter_list|,
name|cid
parameter_list|,
name|val
parameter_list|)
value|do{					\ 	bus_space_write_4(sc->bxe_db_btag, sc->bxe_db_bhandle,		\ 	((BCM_PAGE_SIZE * (cid)) + DPM_TRIGGER_TYPE), (uint32_t)val);	\ } while(0)
end_define

begin_if
if|#
directive|if
operator|(
name|BUS_SPACE_MAXADDR
operator|>
literal|0xFFFFFFFF
operator|)
end_if

begin_comment
comment|/* Define the macro based on whether CPU is 32 or 64 bit. */
end_comment

begin_define
define|#
directive|define
name|U64_LO
parameter_list|(
name|y
parameter_list|)
value|((uint64_t) (y)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|U64_HI
parameter_list|(
name|y
parameter_list|)
value|((uint64_t) (y)>> 32)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|U64_LO
parameter_list|(
name|y
parameter_list|)
value|((uint32_t)y)
end_define

begin_define
define|#
directive|define
name|U64_HI
parameter_list|(
name|y
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HILO_U64
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
value|(((uint64_t)hi<< 32) + lo)
end_define

begin_define
define|#
directive|define
name|BXE_HAS_WORK
parameter_list|(
name|fp
parameter_list|)
define|\
value|(bxe_has_rx_work(fp) || bxe_has_tx_work(fp))
end_define

begin_comment
comment|/* Define the page size of the host CPU. */
end_comment

begin_define
define|#
directive|define
name|BCM_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BCM_PAGE_SIZE
value|(1<< BCM_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|BCM_PAGE_MASK
value|(~(BCM_PAGE_SIZE - 1))
end_define

begin_define
define|#
directive|define
name|BCM_PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|((addr + BCM_PAGE_SIZE - 1)& BCM_PAGE_MASK)
end_define

begin_if
if|#
directive|if
name|BCM_PAGE_SIZE
operator|!=
literal|4096
end_if

begin_error
error|#
directive|error
error|Page sizes other than 4KB not currently supported!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MC hsi */
end_comment

begin_define
define|#
directive|define
name|PAGES_PER_SGE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAGES_PER_SGE
value|(1<< PAGES_PER_SGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|SGE_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|SGE_PAGE_SHIFT
value|PAGE_SHIFT
end_define

begin_define
define|#
directive|define
name|SGE_PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|PAGE_ALIGN(addr)
end_define

begin_comment
comment|/* SGE ring related macros */
end_comment

begin_define
define|#
directive|define
name|NUM_RX_SGE_PAGES
value|2
end_define

begin_define
define|#
directive|define
name|RX_SGE_CNT
value|(BCM_PAGE_SIZE / sizeof(struct eth_rx_sge))
end_define

begin_define
define|#
directive|define
name|MAX_RX_SGE_CNT
value|(RX_SGE_CNT - 2)
end_define

begin_comment
comment|/* RX_SGE_CNT is required to be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|RX_SGE_MASK
value|(RX_SGE_CNT - 1)
end_define

begin_define
define|#
directive|define
name|TOTAL_RX_SGE
value|(RX_SGE_CNT * NUM_RX_SGE_PAGES)
end_define

begin_define
define|#
directive|define
name|MAX_RX_SGE
value|(TOTAL_RX_SGE - 1)
end_define

begin_define
define|#
directive|define
name|NEXT_SGE_IDX
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& RX_SGE_MASK) == (MAX_RX_SGE_CNT - 1)) ? (x) + 3 : (x) + 1)
end_define

begin_define
define|#
directive|define
name|RX_SGE
parameter_list|(
name|x
parameter_list|)
value|((x)& MAX_RX_SGE)
end_define

begin_define
define|#
directive|define
name|RX_SGE_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~RX_SGE_MASK)>> 9)
end_define

begin_define
define|#
directive|define
name|RX_SGE_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& RX_SGE_MASK)
end_define

begin_comment
comment|/* SGE producer mask related macros. */
end_comment

begin_comment
comment|/* Number of bits in one sge_mask array element. */
end_comment

begin_define
define|#
directive|define
name|RX_SGE_MASK_ELEM_SZ
value|64
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_ELEM_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_ELEM_MASK
value|((uint64_t)RX_SGE_MASK_ELEM_SZ - 1)
end_define

begin_comment
comment|/*  * Creates a bitmask of all ones in less significant bits.  * idx - index of the most significant bit in the created mask.  */
end_comment

begin_define
define|#
directive|define
name|RX_SGE_ONES_MASK
parameter_list|(
name|idx
parameter_list|)
define|\
value|(((uint64_t)0x1<< (((idx)& RX_SGE_MASK_ELEM_MASK) + 1)) - 1)
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_ELEM_ONE_MASK
value|((uint64_t)(~0))
end_define

begin_comment
comment|/* Number of uint64_t elements in SGE mask array. */
end_comment

begin_define
define|#
directive|define
name|RX_SGE_MASK_LEN
define|\
value|((NUM_RX_SGE_PAGES * RX_SGE_CNT) / RX_SGE_MASK_ELEM_SZ)
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_LEN_MASK
value|(RX_SGE_MASK_LEN - 1)
end_define

begin_define
define|#
directive|define
name|NEXT_SGE_MASK_ELEM
parameter_list|(
name|el
parameter_list|)
value|(((el) + 1)& RX_SGE_MASK_LEN_MASK)
end_define

begin_comment
comment|/* Transmit Buffer Descriptor (tx_bd) definitions. */
end_comment

begin_comment
comment|/* ToDo: Tune this value based on multi-queue/RSS enable/disable. */
end_comment

begin_define
define|#
directive|define
name|NUM_TX_PAGES
value|2
end_define

begin_define
define|#
directive|define
name|TOTAL_TX_BD_PER_PAGE
value|(BCM_PAGE_SIZE / sizeof(union eth_tx_bd_types))
end_define

begin_define
define|#
directive|define
name|USABLE_TX_BD_PER_PAGE
value|(TOTAL_TX_BD_PER_PAGE - 1)
end_define

begin_define
define|#
directive|define
name|TOTAL_TX_BD
value|(TOTAL_TX_BD_PER_PAGE * NUM_TX_PAGES)
end_define

begin_define
define|#
directive|define
name|USABLE_TX_BD
value|(USABLE_TX_BD_PER_PAGE * NUM_TX_PAGES)
end_define

begin_define
define|#
directive|define
name|MAX_TX_AVAIL
value|(USABLE_TX_BD_PER_PAGE * NUM_TX_PAGES - 2)
end_define

begin_define
define|#
directive|define
name|MAX_TX_BD
value|(TOTAL_TX_BD - 1)
end_define

begin_define
define|#
directive|define
name|NEXT_TX_BD
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& USABLE_TX_BD_PER_PAGE) ==				\ 	(USABLE_TX_BD_PER_PAGE - 1)) ? (x) + 2 : (x) + 1)
end_define

begin_define
define|#
directive|define
name|TX_BD
parameter_list|(
name|x
parameter_list|)
value|((x)& MAX_TX_BD)
end_define

begin_define
define|#
directive|define
name|TX_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~USABLE_TX_BD_PER_PAGE)>> 8)
end_define

begin_define
define|#
directive|define
name|TX_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& USABLE_TX_BD_PER_PAGE)
end_define

begin_comment
comment|/* Receive Buffer Descriptor (rx_bd) definitions. */
end_comment

begin_define
define|#
directive|define
name|NUM_RX_PAGES
value|2
end_define

begin_comment
comment|/* 512 (0x200) of 8 byte bds in 4096 byte page. */
end_comment

begin_define
define|#
directive|define
name|TOTAL_RX_BD_PER_PAGE
value|(BCM_PAGE_SIZE / sizeof(struct eth_rx_bd))
end_define

begin_comment
comment|/* 510 (0x1fe) = 512 - 2 */
end_comment

begin_define
define|#
directive|define
name|USABLE_RX_BD_PER_PAGE
value|(TOTAL_RX_BD_PER_PAGE - 2)
end_define

begin_comment
comment|/* 1024 (0x400) */
end_comment

begin_define
define|#
directive|define
name|TOTAL_RX_BD
value|(TOTAL_RX_BD_PER_PAGE * NUM_RX_PAGES)
end_define

begin_comment
comment|/* 1020 (0x3fc) = 1024 - 4 */
end_comment

begin_define
define|#
directive|define
name|USABLE_RX_BD
value|(USABLE_RX_BD_PER_PAGE * NUM_RX_PAGES)
end_define

begin_comment
comment|/* 1023 (0x3ff) = 1024 -1 */
end_comment

begin_define
define|#
directive|define
name|MAX_RX_BD
value|(TOTAL_RX_BD - 1)
end_define

begin_comment
comment|/* 511 (0x1ff) = 512 - 1 */
end_comment

begin_define
define|#
directive|define
name|RX_DESC_MASK
value|(TOTAL_RX_BD_PER_PAGE - 1)
end_define

begin_define
define|#
directive|define
name|NEXT_RX_BD
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& RX_DESC_MASK) ==					\ 	(USABLE_RX_BD_PER_PAGE - 1)) ? (x) + 3 : (x) + 1)
end_define

begin_comment
comment|/* x& 0x3ff */
end_comment

begin_define
define|#
directive|define
name|RX_BD
parameter_list|(
name|x
parameter_list|)
value|((x)& MAX_RX_BD)
end_define

begin_define
define|#
directive|define
name|RX_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~RX_DESC_MASK)>> 9)
end_define

begin_define
define|#
directive|define
name|RX_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& RX_DESC_MASK)
end_define

begin_comment
comment|/* Receive Completion Queue definitions. */
end_comment

begin_comment
comment|/* CQEs (32 bytes) are 4 times larger than rx_bd's (8 bytes). */
end_comment

begin_define
define|#
directive|define
name|NUM_RCQ_PAGES
value|(NUM_RX_PAGES * 4)
end_define

begin_comment
comment|/* 128 (0x80) */
end_comment

begin_define
define|#
directive|define
name|TOTAL_RCQ_ENTRIES_PER_PAGE
define|\
value|(BCM_PAGE_SIZE / sizeof(union eth_rx_cqe))
end_define

begin_comment
comment|/* 127 (0x7f)for the next page RCQ bd */
end_comment

begin_define
define|#
directive|define
name|USABLE_RCQ_ENTRIES_PER_PAGE
value|(TOTAL_RCQ_ENTRIES_PER_PAGE - 1)
end_define

begin_comment
comment|/* 1024 (0x400) */
end_comment

begin_define
define|#
directive|define
name|TOTAL_RCQ_ENTRIES
value|(TOTAL_RCQ_ENTRIES_PER_PAGE * NUM_RCQ_PAGES)
end_define

begin_comment
comment|/* 1016 (0x3f8) */
end_comment

begin_define
define|#
directive|define
name|USABLE_RCQ_ENTRIES
value|(USABLE_RCQ_ENTRIES_PER_PAGE * NUM_RCQ_PAGES)
end_define

begin_comment
comment|/* 1023 (0x3ff) */
end_comment

begin_define
define|#
directive|define
name|MAX_RCQ_ENTRIES
value|(TOTAL_RCQ_ENTRIES - 1)
end_define

begin_define
define|#
directive|define
name|NEXT_RCQ_IDX
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& USABLE_RCQ_ENTRIES_PER_PAGE) ==			\ 	(USABLE_RCQ_ENTRIES_PER_PAGE - 1)) ? (x) + 2 : (x) + 1)
end_define

begin_define
define|#
directive|define
name|RCQ_ENTRY
parameter_list|(
name|x
parameter_list|)
value|((x)& MAX_RCQ_ENTRIES)
end_define

begin_define
define|#
directive|define
name|RCQ_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~USABLE_RCQ_ENTRIES_PER_PAGE)>> 7)
end_define

begin_define
define|#
directive|define
name|RCQ_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& USABLE_RCQ_ENTRIES_PER_PAGE)
end_define

begin_comment
comment|/* Slowpath Queue definitions. */
end_comment

begin_define
define|#
directive|define
name|SP_DESC_CNT
value|(BCM_PAGE_SIZE / sizeof(struct eth_spe))
end_define

begin_define
define|#
directive|define
name|MAX_SP_DESC_CNT
value|(SP_DESC_CNT - 1)
end_define

begin_define
define|#
directive|define
name|NEXT_SPE
parameter_list|(
name|x
parameter_list|)
value|(((x) + 1 == (MAX_SP_DESC_CNT)) ? 0 : (x) + 1)
end_define

begin_comment
comment|/* This is needed for determening of last_max */
end_comment

begin_define
define|#
directive|define
name|SUB_S16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(int16_t)((int16_t)(a) - (int16_t)(b))
end_define

begin_define
define|#
directive|define
name|__SGE_MASK_SET_BIT
parameter_list|(
name|el
parameter_list|,
name|bit
parameter_list|)
value|do {				\ 	el = ((el) | ((uint64_t)0x1<< (bit)));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|__SGE_MASK_CLEAR_BIT
parameter_list|(
name|el
parameter_list|,
name|bit
parameter_list|)
value|do {				\ 	el = ((el)& (~((uint64_t)0x1<< (bit))));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|SGE_MASK_SET_BIT
parameter_list|(
name|fp
parameter_list|,
name|idx
parameter_list|)
define|\
value|__SGE_MASK_SET_BIT(fp->sge_mask[(idx)>> RX_SGE_MASK_ELEM_SHIFT], \ 	    ((idx)& RX_SGE_MASK_ELEM_MASK))
end_define

begin_define
define|#
directive|define
name|SGE_MASK_CLEAR_BIT
parameter_list|(
name|fp
parameter_list|,
name|idx
parameter_list|)
define|\
value|__SGE_MASK_CLEAR_BIT(fp->sge_mask[(idx)>> RX_SGE_MASK_ELEM_SHIFT], \ 	    ((idx)& RX_SGE_MASK_ELEM_MASK))
end_define

begin_define
define|#
directive|define
name|BXE_TX_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|BXE_TX_CLEANUP_THRESHOLD
value|((USABLE_TX_BD * 7 ) / 8)
end_define

begin_define
define|#
directive|define
name|BXE_DMA_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|BXE_DMA_BOUNDARY
value|0
end_define

begin_comment
comment|/* ToDo: Need to verify the following 3 values. */
end_comment

begin_comment
comment|/* Reduce from 13 to leave room for the parsing buffer. */
end_comment

begin_define
define|#
directive|define
name|BXE_MAX_SEGMENTS
value|12
end_define

begin_define
define|#
directive|define
name|BXE_TSO_MAX_SEGMENTS
value|32
end_define

begin_define
define|#
directive|define
name|BXE_TSO_MAX_SIZE
value|(65535 + sizeof(struct ether_vlan_header))
end_define

begin_define
define|#
directive|define
name|BXE_TSO_MAX_SEG_SIZE
value|4096
end_define

begin_comment
comment|/*  * Hardware Support For IP and TCP checksum.  * (Per packet hardware assist capabilites, derived.  * from CSUM_* in sys/mbuf.h). */
end_comment

begin_define
define|#
directive|define
name|BXE_IF_HWASSIST
value|(CSUM_IP | CSUM_TCP | CSUM_UDP | CSUM_TSO)
end_define

begin_comment
comment|/*  * Per interface capabilities.  *  * ToDo: Consider adding IFCAP_WOL_MAGIC, IFCAP_TOE4,  * IFCAP_TSO6, IFCAP_WOL_UCAST.  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700000
end_if

begin_define
define|#
directive|define
name|BXE_IF_CAPABILITIES
define|\
value|(IFCAP_VLAN_MTU | IFCAP_VLAN_HWTAGGING | IFCAP_HWCSUM |		\ 	IFCAP_JUMBO_MTU | IFCAP_LRO)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TSO was introduced in FreeBSD 7 */
end_comment

begin_define
define|#
directive|define
name|BXE_IF_CAPABILITIES
define|\
value|(IFCAP_VLAN_MTU | IFCAP_VLAN_HWTAGGING | IFCAP_HWCSUM |		\ 	IFCAP_JUMBO_MTU | IFCAP_LRO | IFCAP_TSO4 | IFCAP_VLAN_HWCSUM)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some typical Ethernet frame sizes */
end_comment

begin_define
define|#
directive|define
name|BXE_MIN_MTU
value|60
end_define

begin_define
define|#
directive|define
name|BXE_MIN_ETHER_MTU
value|64
end_define

begin_define
define|#
directive|define
name|BXE_STD_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|BXE_STD_ETHER_MTU
value|1518
end_define

begin_define
define|#
directive|define
name|BXE_STD_ETHER_MTU_VLAN
value|1522
end_define

begin_define
define|#
directive|define
name|BXE_JUMBO_MTU
value|9000
end_define

begin_define
define|#
directive|define
name|BXE_JUMBO_ETHER_MTU
value|9018
end_define

begin_define
define|#
directive|define
name|BXE_JUMBO_ETHER_MTU_VLAN
value|9022
end_define

begin_define
define|#
directive|define
name|BXE_BTR
value|3
end_define

begin_define
define|#
directive|define
name|MAX_SPQ_PENDING
value|8
end_define

begin_comment
comment|/* Derived E1HVN constants for rate shaping. */
end_comment

begin_define
define|#
directive|define
name|DEF_MIN_RATE
value|100
end_define

begin_comment
comment|/* Resolution of the rate shaping timer - 100 usec */
end_comment

begin_define
define|#
directive|define
name|RS_PERIODIC_TIMEOUT_USEC
value|100
end_define

begin_comment
comment|/*  * Resolution of fairness algorithm, in usecs.  * Coefficient for calculating the actual t_fair.  */
end_comment

begin_define
define|#
directive|define
name|T_FAIR_COEF
value|10000000
end_define

begin_comment
comment|/*  * Number of bytes in single QM arbitration cycle.  * Coefficient for calculating the fairness timer.  */
end_comment

begin_define
define|#
directive|define
name|QM_ARB_BYTES
value|40000
end_define

begin_define
define|#
directive|define
name|FAIR_MEM
value|2
end_define

begin_define
define|#
directive|define
name|MIN_BXE_BC_VER
value|0x00040200
end_define

begin_define
define|#
directive|define
name|BXE_NO_RX_FLAGS
define|\
value|(TSTORM_ETH_DROP_FLAGS_DROP_ALL_PACKETS)
end_define

begin_define
define|#
directive|define
name|BXE_NORMAL_RX_FLAGS
define|\
value|(TSTORM_ETH_DROP_FLAGS_DROP_TCP_CS_ERROR_FLG |			\ 	TSTORM_ETH_DROP_FLAGS_DROP_IP_CS_ERROR_FLG |			\ 	TSTORM_ETH_DROP_FLAGS_DONT_DROP_MAC_ERR_FLG |			\ 	TSTORM_ETH_DROP_FLAGS_DROP_TOO_BIG_PACKETS |			\ 	TSTORM_ETH_DROP_FLAGS_DROP_UNMATCH_UNICAST |			\ 	TSTORM_ETH_DROP_FLAGS_DROP_UNMATCH_MULTICAST |			\ 	TSTORM_ETH_DROP_FLAGS_DONT_DROP_TTL0_FLG)
end_define

begin_define
define|#
directive|define
name|BXE_ALLMULTI_RX_FLAGS
define|\
value|(TSTORM_ETH_DROP_FLAGS_DROP_TCP_CS_ERROR_FLG |			\ 	TSTORM_ETH_DROP_FLAGS_DROP_IP_CS_ERROR_FLG |			\ 	 TSTORM_ETH_DROP_FLAGS_DONT_DROP_MAC_ERR_FLG |			\ 	 TSTORM_ETH_DROP_FLAGS_DROP_TOO_BIG_PACKETS |			\ 	 TSTORM_ETH_DROP_FLAGS_DROP_UNMATCH_UNICAST |			\ 	 TSTORM_ETH_DROP_FLAGS_DONT_DROP_TTL0_FLG)
end_define

begin_define
define|#
directive|define
name|BXE_PROMISC_RX_FLAGS
define|\
value|(TSTORM_ETH_DROP_FLAGS_DONT_DROP_TTL0_FLG)
end_define

begin_comment
comment|/*  * External definitions.  */
end_comment

begin_comment
comment|/* FreeBSD multip proc number of active cpus on the system. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mp_ncpus
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_DYNAMIC_ATTN_GRPS
value|8
end_define

begin_define
define|#
directive|define
name|MAC_STX_NA
value|0xffffffff
end_define

begin_comment
comment|/* Attention group wiring. */
end_comment

begin_struct
struct|struct
name|attn_route
block|{
name|uint32_t
name|sig
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regp
block|{
name|uint32_t
name|lo
decl_stmt|;
name|uint32_t
name|hi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nig_stats
block|{
name|uint32_t
name|brb_discard
decl_stmt|;
name|uint32_t
name|brb_packet
decl_stmt|;
name|uint32_t
name|brb_truncate
decl_stmt|;
name|uint32_t
name|flow_ctrl_discard
decl_stmt|;
name|uint32_t
name|flow_ctrl_octets
decl_stmt|;
name|uint32_t
name|flow_ctrl_packet
decl_stmt|;
name|uint32_t
name|mng_discard
decl_stmt|;
name|uint32_t
name|mng_octet_inp
decl_stmt|;
name|uint32_t
name|mng_octet_out
decl_stmt|;
name|uint32_t
name|mng_packet_inp
decl_stmt|;
name|uint32_t
name|mng_packet_out
decl_stmt|;
name|uint32_t
name|pbf_octets
decl_stmt|;
name|uint32_t
name|pbf_packet
decl_stmt|;
name|uint32_t
name|safc_inp
decl_stmt|;
name|uint32_t
name|egress_mac_pkt0_lo
decl_stmt|;
name|uint32_t
name|egress_mac_pkt0_hi
decl_stmt|;
name|uint32_t
name|egress_mac_pkt1_lo
decl_stmt|;
name|uint32_t
name|egress_mac_pkt1_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|bxe_stats_event
block|{
name|STATS_EVENT_PMF
init|=
literal|0
block|,
name|STATS_EVENT_LINK_UP
block|,
name|STATS_EVENT_UPDATE
block|,
name|STATS_EVENT_STOP
block|,
name|STATS_EVENT_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|bxe_stats_state
block|{
name|STATS_STATE_DISABLED
init|=
literal|0
block|,
name|STATS_STATE_ENABLED
block|,
name|STATS_STATE_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|bxe_eth_stats
block|{
name|uint32_t
name|total_bytes_received_hi
decl_stmt|;
name|uint32_t
name|total_bytes_received_lo
decl_stmt|;
name|uint32_t
name|total_bytes_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_bytes_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_unicast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_unicast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_multicast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_multicast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_unicast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_unicast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_multicast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_multicast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|valid_bytes_received_hi
decl_stmt|;
name|uint32_t
name|valid_bytes_received_lo
decl_stmt|;
name|uint32_t
name|error_bytes_received_hi
decl_stmt|;
name|uint32_t
name|error_bytes_received_lo
decl_stmt|;
name|uint32_t
name|rx_stat_ifhcinbadoctets_hi
decl_stmt|;
name|uint32_t
name|rx_stat_ifhcinbadoctets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_ifhcoutbadoctets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_ifhcoutbadoctets_lo
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsfcserrors_hi
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsfcserrors_lo
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsalignmenterrors_hi
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsalignmenterrors_lo
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statscarriersenseerrors_hi
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statscarriersenseerrors_lo
decl_stmt|;
name|uint32_t
name|rx_stat_falsecarriererrors_hi
decl_stmt|;
name|uint32_t
name|rx_stat_falsecarriererrors_lo
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsundersizepkts_hi
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsundersizepkts_lo
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsframestoolong_hi
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsframestoolong_lo
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsfragments_hi
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsfragments_lo
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsjabbers_hi
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsjabbers_lo
decl_stmt|;
name|uint32_t
name|rx_stat_maccontrolframesreceived_hi
decl_stmt|;
name|uint32_t
name|rx_stat_maccontrolframesreceived_lo
decl_stmt|;
name|uint32_t
name|rx_stat_bmac_xpf_hi
decl_stmt|;
name|uint32_t
name|rx_stat_bmac_xpf_lo
decl_stmt|;
name|uint32_t
name|rx_stat_bmac_xcf_hi
decl_stmt|;
name|uint32_t
name|rx_stat_bmac_xcf_lo
decl_stmt|;
name|uint32_t
name|rx_stat_xoffstateentered_hi
decl_stmt|;
name|uint32_t
name|rx_stat_xoffstateentered_lo
decl_stmt|;
name|uint32_t
name|rx_stat_xonpauseframesreceived_hi
decl_stmt|;
name|uint32_t
name|rx_stat_xonpauseframesreceived_lo
decl_stmt|;
name|uint32_t
name|rx_stat_xoffpauseframesreceived_hi
decl_stmt|;
name|uint32_t
name|rx_stat_xoffpauseframesreceived_lo
decl_stmt|;
name|uint32_t
name|tx_stat_outxonsent_hi
decl_stmt|;
name|uint32_t
name|tx_stat_outxonsent_lo
decl_stmt|;
name|uint32_t
name|tx_stat_outxoffsent_hi
decl_stmt|;
name|uint32_t
name|tx_stat_outxoffsent_lo
decl_stmt|;
name|uint32_t
name|tx_stat_flowcontroldone_hi
decl_stmt|;
name|uint32_t
name|tx_stat_flowcontroldone_lo
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatscollisions_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatscollisions_lo
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statssinglecollisionframes_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statssinglecollisionframes_lo
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsmultiplecollisionframes_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsmultiplecollisionframes_lo
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsdeferredtransmissions_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsdeferredtransmissions_lo
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsexcessivecollisions_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsexcessivecollisions_lo
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statslatecollisions_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statslatecollisions_lo
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts64octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts64octets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts65octetsto127octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts65octetsto127octets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts128octetsto255octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts128octetsto255octets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts256octetsto511octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts256octetsto511octets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts512octetsto1023octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts512octetsto1023octets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts1024octetsto1522octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts1024octetsto1522octets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspktsover1522octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspktsover1522octets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_2047_hi
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_2047_lo
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_4095_hi
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_4095_lo
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_9216_hi
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_9216_lo
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_16383_hi
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_16383_lo
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsinternalmactransmiterrors_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsinternalmactransmiterrors_lo
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_ufl_hi
decl_stmt|;
name|uint32_t
name|tx_stat_bmac_ufl_lo
decl_stmt|;
name|uint32_t
name|brb_drop_hi
decl_stmt|;
name|uint32_t
name|brb_drop_lo
decl_stmt|;
name|uint32_t
name|brb_truncate_hi
decl_stmt|;
name|uint32_t
name|brb_truncate_lo
decl_stmt|;
name|uint32_t
name|pause_frames_received_hi
decl_stmt|;
name|uint32_t
name|pause_frames_received_lo
decl_stmt|;
name|uint32_t
name|pause_frames_sent_hi
decl_stmt|;
name|uint32_t
name|pause_frames_sent_lo
decl_stmt|;
name|uint32_t
name|jabber_packets_received
decl_stmt|;
name|uint32_t
name|etherstatspkts1024octetsto1522octets_hi
decl_stmt|;
name|uint32_t
name|etherstatspkts1024octetsto1522octets_lo
decl_stmt|;
name|uint32_t
name|etherstatspktsover1522octets_hi
decl_stmt|;
name|uint32_t
name|etherstatspktsover1522octets_lo
decl_stmt|;
name|uint32_t
name|no_buff_discard_hi
decl_stmt|;
name|uint32_t
name|no_buff_discard_lo
decl_stmt|;
name|uint32_t
name|mac_filter_discard
decl_stmt|;
name|uint32_t
name|xxoverflow_discard
decl_stmt|;
name|uint32_t
name|brb_truncate_discard
decl_stmt|;
name|uint32_t
name|mac_discard
decl_stmt|;
name|uint32_t
name|driver_xoff
decl_stmt|;
name|uint32_t
name|rx_err_discard_pkt
decl_stmt|;
name|uint32_t
name|rx_skb_alloc_failed
decl_stmt|;
name|uint32_t
name|hw_csum_err
decl_stmt|;
name|uint32_t
name|nig_timer_max
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STATS_OFFSET32
parameter_list|(
name|stat_name
parameter_list|)
define|\
value|(offsetof(struct bxe_eth_stats, stat_name) / 4)
end_define

begin_define
define|#
directive|define
name|MAX_CONTEXT
value|16
end_define

begin_union
union|union
name|cdu_context
block|{
name|struct
name|eth_context
name|eth
decl_stmt|;
name|char
name|pad
index|[
literal|1024
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Load/unload mode. */
end_comment

begin_define
define|#
directive|define
name|LOAD_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|LOAD_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|LOAD_DIAG
value|2
end_define

begin_define
define|#
directive|define
name|UNLOAD_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|UNLOAD_CLOSE
value|1
end_define

begin_define
define|#
directive|define
name|BXE_MAX_POLL_COUNT
value|1024
end_define

begin_struct
struct|struct
name|sw_rx_bd
block|{
name|struct
name|mbuf
modifier|*
name|pmbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common data structure.  * This information is shared across all ports and functions.  */
end_comment

begin_struct
struct|struct
name|bxe_common
block|{
name|uint32_t
name|chip_id
decl_stmt|;
comment|/* chip num:16-31, rev:12-15, metal:4-11, bond_id:0-3 */
define|#
directive|define
name|CHIP_ID
parameter_list|(
name|sc
parameter_list|)
value|(sc->common.chip_id& 0xfffffff0)
define|#
directive|define
name|CHIP_NUM
parameter_list|(
name|sc
parameter_list|)
value|(sc->common.chip_id>> 16)
define|#
directive|define
name|CHIP_NUM_57710
value|0x164e
define|#
directive|define
name|CHIP_NUM_57711
value|0x164f
define|#
directive|define
name|CHIP_NUM_57711E
value|0x1650
define|#
directive|define
name|CHIP_IS_E1
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57710)
define|#
directive|define
name|CHIP_IS_57711
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57711)
define|#
directive|define
name|CHIP_IS_57711E
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57711E)
define|#
directive|define
name|CHIP_IS_E1H
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_57711(sc) || CHIP_IS_57711E(sc))
define|#
directive|define
name|CHIP_IS_MF_CAP
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_57711E(sc))
define|#
directive|define
name|IS_E1H_OFFSET
value|CHIP_IS_E1H(sc)
define|#
directive|define
name|CHIP_REV
parameter_list|(
name|sc
parameter_list|)
value|((sc->common.chip_id)& 0x0000f000)
define|#
directive|define
name|CHIP_REV_Ax
value|0x00000000
define|#
directive|define
name|CHIP_REV_Bx
value|0x00001000
define|#
directive|define
name|CHIP_REV_Cx
value|0x00002000
define|#
directive|define
name|CHIP_METAL
parameter_list|(
name|sc
parameter_list|)
value|((sc->common.chip_id)& 0x00000ff0)
define|#
directive|define
name|CHIP_BOND_ID
parameter_list|(
name|sc
parameter_list|)
value|((sc->common.chip_id)& 0x0000000f)
name|int
name|flash_size
decl_stmt|;
define|#
directive|define
name|NVRAM_1MB_SIZE
value|0x20000
define|#
directive|define
name|NVRAM_TIMEOUT_COUNT
value|30000
define|#
directive|define
name|NVRAM_PAGE_SIZE
value|256
comment|/* Bootcode shared memory address in BAR memory. */
name|uint32_t
name|shmem_base
decl_stmt|;
name|uint32_t
name|shmem2_base
decl_stmt|;
comment|/* Device configuration read from bootcode shared memory. */
name|uint32_t
name|hw_config
decl_stmt|;
name|uint32_t
name|bc_ver
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* End struct bxe_common */
end_comment

begin_comment
comment|/*  * Port specifc data structure.  */
end_comment

begin_struct
struct|struct
name|bxe_port
block|{
comment|/* 	 * Port Management Function (for 57711E only). 	 * When this field is set the driver instance is 	 * responsible for managing port specifc 	 * configurations such as handling link attentions. 	 */
name|uint32_t
name|pmf
decl_stmt|;
comment|/* Ethernet maximum transmission unit. */
name|uint16_t
name|ether_mtu
decl_stmt|;
name|uint32_t
name|link_config
decl_stmt|;
comment|/* Defines the features	supported by the PHY. */
name|uint32_t
name|supported
decl_stmt|;
define|#
directive|define
name|SUPPORTED_10baseT_Half
value|(1<< 1)
define|#
directive|define
name|SUPPORTED_10baseT_Full
value|(1<< 2)
define|#
directive|define
name|SUPPORTED_100baseT_Half
value|(1<< 3)
define|#
directive|define
name|SUPPORTED_100baseT_Full
value|(1<< 4)
define|#
directive|define
name|SUPPORTED_1000baseT_Half
value|(1<< 5)
define|#
directive|define
name|SUPPORTED_1000baseT_Full
value|(1<< 6)
define|#
directive|define
name|SUPPORTED_TP
value|(1<< 7)
define|#
directive|define
name|SUPPORTED_FIBRE
value|(1<< 8)
define|#
directive|define
name|SUPPORTED_Autoneg
value|(1<< 9)
define|#
directive|define
name|SUPPORTED_Asym_Pause
value|(1<< 10)
define|#
directive|define
name|SUPPORTED_Pause
value|(1<< 11)
define|#
directive|define
name|SUPPORTED_2500baseX_Full
value|(1<< 15)
define|#
directive|define
name|SUPPORTED_10000baseT_Full
value|(1<< 16)
comment|/* Defines the features	advertised by the PHY. */
name|uint32_t
name|advertising
decl_stmt|;
define|#
directive|define
name|ADVERTISED_10baseT_Half
value|(1<< 1)
define|#
directive|define
name|ADVERTISED_10baseT_Full
value|(1<< 2)
define|#
directive|define
name|ADVERTISED_100baseT_Half
value|(1<< 3)
define|#
directive|define
name|ADVERTISED_100baseT_Full
value|(1<< 4)
define|#
directive|define
name|ADVERTISED_1000baseT_Half
value|(1<< 5)
define|#
directive|define
name|ADVERTISED_1000baseT_Full
value|(1<< 6)
define|#
directive|define
name|ADVERTISED_TP
value|(1<< 7)
define|#
directive|define
name|ADVERTISED_FIBRE
value|(1<< 8)
define|#
directive|define
name|ADVERTISED_Autoneg
value|(1<< 9)
define|#
directive|define
name|ADVERTISED_Asym_Pause
value|(1<< 10)
define|#
directive|define
name|ADVERTISED_Pause
value|(1<< 11)
define|#
directive|define
name|ADVERTISED_2500baseX_Full
value|(1<< 15)
define|#
directive|define
name|ADVERTISED_10000baseT_Full
value|(1<< 16)
name|uint32_t
name|phy_addr
decl_stmt|;
comment|/* Used to synchronize phy accesses. */
name|struct
name|mtx
name|bxe_phy_mtx
decl_stmt|;
comment|/* 	 * MCP scratchpad address for port specific statistics. 	 * The device is responsible for writing statistcss 	 * back to the MCP for use with management firmware such 	 * as UMP/NC-SI. 	 */
name|uint32_t
name|port_stx
decl_stmt|;
name|struct
name|nig_stats
name|old_nig_stats
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* End struct bxe_port */
end_comment

begin_comment
comment|/* DMAE command defines */
end_comment

begin_define
define|#
directive|define
name|DMAE_CMD_SRC_PCI
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_SRC_GRC
value|DMAE_COMMAND_SRC
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_DST_PCI
value|(1<< DMAE_COMMAND_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_DST_GRC
value|(2<< DMAE_COMMAND_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_C_DST_PCI
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_C_DST_GRC
value|(1<< DMAE_COMMAND_C_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_C_ENABLE
value|DMAE_COMMAND_C_TYPE_ENABLE
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY_NO_SWAP
value|(0<< DMAE_COMMAND_ENDIANITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY_B_SWAP
value|(1<< DMAE_COMMAND_ENDIANITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY_DW_SWAP
value|(2<< DMAE_COMMAND_ENDIANITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY_B_DW_SWAP
value|(3<< DMAE_COMMAND_ENDIANITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_PORT_0
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_PORT_1
value|DMAE_COMMAND_PORT
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_SRC_RESET
value|DMAE_COMMAND_SRC_RESET
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_DST_RESET
value|DMAE_COMMAND_DST_RESET
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_E1HVN_SHIFT
value|DMAE_COMMAND_E1HVN_SHIFT
end_define

begin_define
define|#
directive|define
name|DMAE_LEN32_RD_MAX
value|0x80
end_define

begin_define
define|#
directive|define
name|DMAE_LEN32_WR_MAX
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E1(sc) ? 0x400 : 0x2000)
end_define

begin_define
define|#
directive|define
name|DMAE_COMP_VAL
value|0xe0d0d0ae
end_define

begin_define
define|#
directive|define
name|MAX_DMAE_C
value|8
end_define

begin_define
define|#
directive|define
name|MAX_DMAE_C_PER_PORT
value|8
end_define

begin_define
define|#
directive|define
name|INIT_DMAE_C
parameter_list|(
name|sc
parameter_list|)
define|\
value|(BP_PORT(sc) * MAX_DMAE_C_PER_PORT + BP_E1HVN(sc))
end_define

begin_define
define|#
directive|define
name|PMF_DMAE_C
parameter_list|(
name|sc
parameter_list|)
define|\
value|(BP_PORT(sc) * MAX_DMAE_C_PER_PORT + E1HVN_MAX)
end_define

begin_comment
comment|/*  * This is the slowpath data structure.  It is mapped into non-paged memory  * so that the hardware can access it's contents directly and must be page  * aligned.  */
end_comment

begin_struct
struct|struct
name|bxe_slowpath
block|{
comment|/* 	 * The cdu_context array MUST be the first element in this 	 * structure.  It is used during the leading edge ramrod 	 * operation. 	 */
name|union
name|cdu_context
name|context
index|[
name|MAX_CONTEXT
index|]
decl_stmt|;
name|struct
name|eth_stats_query
name|fw_stats
decl_stmt|;
comment|/* Used as a DMA source for MAC configuration. */
name|struct
name|mac_configuration_cmd
name|mac_config
decl_stmt|;
name|struct
name|mac_configuration_cmd
name|mcast_config
decl_stmt|;
comment|/* Used by the DMAE command executer. */
name|struct
name|dmae_command
name|dmae
index|[
name|MAX_DMAE_C
index|]
decl_stmt|;
comment|/* Statistics completion. */
name|uint32_t
name|stats_comp
decl_stmt|;
comment|/* Firmware defined statistics blocks. */
name|union
name|mac_stats
name|mac_stats
decl_stmt|;
name|struct
name|nig_stats
name|nig_stats
decl_stmt|;
name|struct
name|host_port_stats
name|port_stats
decl_stmt|;
name|struct
name|host_func_stats
name|func_stats
decl_stmt|;
name|struct
name|host_func_stats
name|func_stats_base
decl_stmt|;
comment|/* DMAE completion value. */
name|uint32_t
name|wb_comp
decl_stmt|;
define|#
directive|define
name|BXE_WB_COMP_VAL
value|0xe0d0d0ae
comment|/* DMAE data source/sink. */
name|uint32_t
name|wb_data
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* End struct bxe_slowpath */
end_comment

begin_define
define|#
directive|define
name|BXE_SP
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(&sc->slowpath->var)
end_define

begin_define
define|#
directive|define
name|BXE_SP_CHECK
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|((sc->slowpath) ? (&sc->slowpath->var) : NULL)
end_define

begin_define
define|#
directive|define
name|BXE_SP_MAPPING
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
define|\
value|(sc->slowpath_paddr + offsetof(struct bxe_slowpath, var))
end_define

begin_union
union|union
name|db_prod
block|{
name|struct
name|doorbell_set_prod
name|data
decl_stmt|;
name|uint32_t
name|raw
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|bxe_q_stats
block|{
name|uint32_t
name|total_bytes_received_hi
decl_stmt|;
name|uint32_t
name|total_bytes_received_lo
decl_stmt|;
name|uint32_t
name|total_bytes_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_bytes_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_unicast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_unicast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_multicast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_multicast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_unicast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_unicast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_multicast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_multicast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|valid_bytes_received_hi
decl_stmt|;
name|uint32_t
name|valid_bytes_received_lo
decl_stmt|;
name|uint32_t
name|error_bytes_received_hi
decl_stmt|;
name|uint32_t
name|error_bytes_received_lo
decl_stmt|;
name|uint32_t
name|etherstatsoverrsizepkts_hi
decl_stmt|;
name|uint32_t
name|etherstatsoverrsizepkts_lo
decl_stmt|;
name|uint32_t
name|no_buff_discard_hi
decl_stmt|;
name|uint32_t
name|no_buff_discard_lo
decl_stmt|;
name|uint32_t
name|driver_xoff
decl_stmt|;
name|uint32_t
name|rx_err_discard_pkt
decl_stmt|;
name|uint32_t
name|rx_skb_alloc_failed
decl_stmt|;
name|uint32_t
name|hw_csum_err
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the fastpath data structure.  There can be up to MAX_CONTEXT  * instances of the fastpath structure when using RSS/multi-queue.  */
end_comment

begin_struct
struct|struct
name|bxe_fastpath
block|{
comment|/* Pointer back to parent structure. */
name|struct
name|bxe_softc
modifier|*
name|sc
decl_stmt|;
comment|/* Hardware maintained status block. */
name|bus_dma_tag_t
name|status_block_tag
decl_stmt|;
name|bus_dmamap_t
name|status_block_map
decl_stmt|;
name|struct
name|host_status_block
modifier|*
name|status_block
decl_stmt|;
name|bus_addr_t
name|status_block_paddr
decl_stmt|;
ifdef|#
directive|ifdef
name|notyet
comment|/* 	 * In this implementation the doorbell data block 	 * (eth_tx_db_data) is mapped into memory immediately 	 * following the status block and is part of the same 	 * memory allocation. 	 */
name|struct
name|eth_tx_db_data
modifier|*
name|hw_tx_prods
decl_stmt|;
name|bus_addr_t
name|tx_prods_paddr
decl_stmt|;
endif|#
directive|endif
comment|/* Hardware maintained TX buffer descriptor chains. */
name|bus_dma_tag_t
name|tx_bd_chain_tag
decl_stmt|;
name|bus_dmamap_t
name|tx_bd_chain_map
index|[
name|NUM_TX_PAGES
index|]
decl_stmt|;
name|union
name|eth_tx_bd_types
modifier|*
name|tx_bd_chain
index|[
name|NUM_TX_PAGES
index|]
decl_stmt|;
name|bus_addr_t
name|tx_bd_chain_paddr
index|[
name|NUM_TX_PAGES
index|]
decl_stmt|;
comment|/* Bus resource tag for TX mbufs. */
name|bus_dma_tag_t
name|tx_mbuf_tag
decl_stmt|;
name|bus_dmamap_t
name|tx_mbuf_map
index|[
name|TOTAL_TX_BD
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tx_mbuf_ptr
index|[
name|TOTAL_TX_BD
index|]
decl_stmt|;
comment|/* Hardware maintained RX buffer descriptor chains. */
name|bus_dma_tag_t
name|rx_bd_chain_tag
decl_stmt|;
name|bus_dmamap_t
name|rx_bd_chain_map
index|[
name|NUM_RX_PAGES
index|]
decl_stmt|;
name|struct
name|eth_rx_bd
modifier|*
name|rx_bd_chain
index|[
name|NUM_RX_PAGES
index|]
decl_stmt|;
name|bus_addr_t
name|rx_bd_chain_paddr
index|[
name|NUM_RX_PAGES
index|]
decl_stmt|;
comment|/* Bus resource tag for RX mbufs. */
name|bus_dma_tag_t
name|rx_mbuf_tag
decl_stmt|;
name|bus_dmamap_t
name|rx_mbuf_map
index|[
name|TOTAL_RX_BD
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rx_mbuf_ptr
index|[
name|TOTAL_RX_BD
index|]
decl_stmt|;
comment|/* Hardware maintained Completion Queue (CQ) chains. */
name|bus_dma_tag_t
name|rx_cq_chain_tag
decl_stmt|;
name|bus_dmamap_t
name|rx_cq_chain_map
index|[
name|NUM_RCQ_PAGES
index|]
decl_stmt|;
name|union
name|eth_rx_cqe
modifier|*
name|rx_cq_chain
index|[
name|NUM_RCQ_PAGES
index|]
decl_stmt|;
name|bus_addr_t
name|rx_cq_chain_paddr
index|[
name|NUM_RCQ_PAGES
index|]
decl_stmt|;
comment|/* Taskqueue reqources. */
name|struct
name|task
name|task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* Fastpath state. */
comment|/* ToDo: Why use 'int' here, why not 'uint32_t'? */
name|int
name|state
decl_stmt|;
define|#
directive|define
name|BXE_FP_STATE_CLOSED
value|0x00000
define|#
directive|define
name|BXE_FP_STATE_IRQ
value|0x80000
define|#
directive|define
name|BXE_FP_STATE_OPENING
value|0x90000
define|#
directive|define
name|BXE_FP_STATE_OPEN
value|0xa0000
define|#
directive|define
name|BXE_FP_STATE_HALTING
value|0xb0000
define|#
directive|define
name|BXE_FP_STATE_HALTED
value|0xc0000
comment|/* Self-reference back to this fastpath's queue number. */
name|uint8_t
name|index
decl_stmt|;
define|#
directive|define
name|FP_IDX
parameter_list|(
name|fp
parameter_list|)
value|(fp->index)
comment|/* Ethernet client ID (each fastpath set of RX/TX/CQE is a client). */
name|uint8_t
name|cl_id
decl_stmt|;
define|#
directive|define
name|BP_CL_ID
parameter_list|(
name|sc
parameter_list|)
value|(sc->fp[0].cl_id)
comment|/* Status block number in hardware. */
name|uint8_t
name|sb_id
decl_stmt|;
define|#
directive|define
name|FP_SB_ID
parameter_list|(
name|fp
parameter_list|)
value|(fp->sb_id)
comment|/* Class of service. */
name|uint8_t
name|cos
decl_stmt|;
name|union
name|db_prod
name|tx_db
decl_stmt|;
comment|/* Transmit packet producer index (used in eth_tx_bd). */
name|uint16_t
name|tx_pkt_prod
decl_stmt|;
comment|/* Transmit packet consumer index. */
name|uint16_t
name|tx_pkt_cons
decl_stmt|;
comment|/* Transmit buffer descriptor prod/cons indices. */
name|uint16_t
name|tx_bd_prod
decl_stmt|;
name|uint16_t
name|tx_bd_cons
decl_stmt|;
comment|/* Driver's copy of the fastpath CSTORM/USTORM indices. */
name|uint16_t
name|fp_c_idx
decl_stmt|;
name|uint16_t
name|fp_u_idx
decl_stmt|;
comment|/* Driver's copy of the receive buffer descriptor prod/cons indices. */
name|uint16_t
name|rx_bd_prod
decl_stmt|;
name|uint16_t
name|rx_bd_cons
decl_stmt|;
comment|/* Driver's copy of the receive completion queue prod/cons indices. */
name|uint16_t
name|rx_cq_prod
decl_stmt|;
name|uint16_t
name|rx_cq_cons
decl_stmt|;
comment|/* Pointer to the receive consumer index in the status block. */
name|uint16_t
modifier|*
name|rx_cons_sb
decl_stmt|;
comment|/* 	 * Pointer to the receive buffer descriptor consumer in the 	 * status block. 	 */
name|uint16_t
modifier|*
name|rx_bd_cons_sb
decl_stmt|;
comment|/* Pointer to the transmit consumer in the status block. */
name|uint16_t
modifier|*
name|tx_cons_sb
decl_stmt|;
comment|/* Free/used buffer descriptor counters. */
name|uint16_t
name|used_tx_bd
decl_stmt|;
comment|/* Begin: TPA Related data structure. */
comment|/* Hardware maintained RX Scatter Gather Entry chains. */
name|bus_dma_tag_t
name|rx_sge_chain_tag
decl_stmt|;
name|bus_dmamap_t
name|rx_sge_chain_map
index|[
name|NUM_RX_SGE_PAGES
index|]
decl_stmt|;
name|struct
name|eth_rx_sge
modifier|*
name|rx_sge_chain
index|[
name|NUM_RX_SGE_PAGES
index|]
decl_stmt|;
name|bus_addr_t
name|rx_sge_chain_paddr
index|[
name|NUM_RX_SGE_PAGES
index|]
decl_stmt|;
comment|/* Bus tag for RX SGE bufs. */
name|bus_dma_tag_t
name|rx_sge_buf_tag
decl_stmt|;
name|bus_dmamap_t
name|rx_sge_buf_map
index|[
name|TOTAL_RX_SGE
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rx_sge_buf_ptr
index|[
name|TOTAL_RX_SGE
index|]
decl_stmt|;
name|uint64_t
name|sge_mask
index|[
name|RX_SGE_MASK_LEN
index|]
decl_stmt|;
name|uint16_t
name|rx_sge_prod
decl_stmt|;
comment|/* The last maximal completed SGE. */
name|uint16_t
name|last_max_sge
decl_stmt|;
name|uint16_t
name|rx_sge_free_idx
decl_stmt|;
comment|/* Use the larger supported size for TPA queue length. */
name|bus_dmamap_t
name|tpa_mbuf_map
index|[
name|ETH_MAX_AGGREGATION_QUEUES_E1H
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tpa_mbuf_ptr
index|[
name|ETH_MAX_AGGREGATION_QUEUES_E1H
index|]
decl_stmt|;
name|bus_dma_segment_t
name|tpa_mbuf_segs
index|[
name|ETH_MAX_AGGREGATION_QUEUES_E1H
index|]
decl_stmt|;
name|uint8_t
name|tpa_state
index|[
name|ETH_MAX_AGGREGATION_QUEUES_E1H
index|]
decl_stmt|;
define|#
directive|define
name|BXE_TPA_STATE_START
value|1
define|#
directive|define
name|BXE_TPA_STATE_STOP
value|2
name|uint8_t
name|segs
decl_stmt|;
name|uint8_t
name|disable_tpa
decl_stmt|;
comment|/* End: TPA related data structure. */
name|struct
name|tstorm_per_client_stats
name|old_tclient
decl_stmt|;
name|struct
name|ustorm_per_client_stats
name|old_uclient
decl_stmt|;
name|struct
name|xstorm_per_client_stats
name|old_xclient
decl_stmt|;
name|struct
name|bxe_q_stats
name|eth_q_stats
decl_stmt|;
name|uint16_t
name|free_rx_bd
decl_stmt|;
comment|/* Recieve/transmit packet counters. */
name|unsigned
name|long
name|rx_pkts
decl_stmt|;
name|unsigned
name|long
name|tx_pkts
decl_stmt|;
name|unsigned
name|long
name|tpa_pkts
decl_stmt|;
comment|/* Receive interrupt counter. */
name|unsigned
name|long
name|rx_calls
decl_stmt|;
comment|/* Memory buffer allocation failure counter. */
name|unsigned
name|long
name|mbuf_alloc_failed
decl_stmt|;
name|unsigned
name|long
name|mbuf_defrag_attempts
decl_stmt|;
name|unsigned
name|long
name|mbuf_defrag_failures
decl_stmt|;
name|unsigned
name|long
name|mbuf_defrag_successes
decl_stmt|;
comment|/* Track the number of enqueued mbufs. */
name|int
name|tx_mbuf_alloc
decl_stmt|;
name|int
name|rx_mbuf_alloc
decl_stmt|;
name|int
name|sge_mbuf_alloc
decl_stmt|;
name|int
name|tpa_mbuf_alloc
decl_stmt|;
name|uint64_t
name|tpa_queue_used
decl_stmt|;
name|unsigned
name|long
name|null_cqe_flags
decl_stmt|;
name|unsigned
name|long
name|ip_csum_offload_frames
decl_stmt|;
name|unsigned
name|long
name|tcp_csum_offload_frames
decl_stmt|;
name|unsigned
name|long
name|udp_csum_offload_frames
decl_stmt|;
name|unsigned
name|long
name|tso_offload_frames
decl_stmt|;
name|unsigned
name|long
name|tx_encap_failures
decl_stmt|;
name|unsigned
name|long
name|tx_start_called_on_empty_queue
decl_stmt|;
name|unsigned
name|long
name|tx_queue_too_full
decl_stmt|;
name|unsigned
name|long
name|tx_dma_mapping_failure
decl_stmt|;
name|unsigned
name|long
name|tso_window_violation
decl_stmt|;
name|unsigned
name|long
name|std_window_violation
decl_stmt|;
name|unsigned
name|long
name|unsupported_tso_ipv6_request
decl_stmt|;
name|unsigned
name|long
name|unsupported_tso_protocol_request
decl_stmt|;
name|unsigned
name|long
name|tpa_mbuf_alloc_failed
decl_stmt|;
name|unsigned
name|long
name|tx_chain_lost_mbuf
decl_stmt|;
comment|/* FreeBSD interface statistics. */
name|unsigned
name|long
name|soft_rx_errors
decl_stmt|;
name|unsigned
name|long
name|soft_tx_errors
decl_stmt|;
name|unsigned
name|long
name|ipackets
decl_stmt|;
name|unsigned
name|long
name|opackets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bxe_fastpath */
end_comment

begin_comment
comment|/*  * BXE Device State Data Structure  */
end_comment

begin_define
define|#
directive|define
name|BXE_STATUS_BLK_SZ
define|\
value|sizeof(struct host_status_block)
end_define

begin_comment
comment|/* +sizeof(struct eth_tx_db_data) */
end_comment

begin_define
define|#
directive|define
name|BXE_DEF_STATUS_BLK_SZ
value|sizeof(struct host_def_status_block)
end_define

begin_define
define|#
directive|define
name|BXE_STATS_BLK_SZ
value|sizeof(struct bxe_eth_stats)
end_define

begin_define
define|#
directive|define
name|BXE_SLOWPATH_SZ
value|sizeof(struct bxe_slowpath)
end_define

begin_define
define|#
directive|define
name|BXE_SPQ_SZ
value|BCM_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BXE_TX_CHAIN_PAGE_SZ
value|BCM_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BXE_RX_CHAIN_PAGE_SZ
value|BCM_PAGE_SIZE
end_define

begin_comment
comment|/* ToDo: Audit this structure for unused varaibles. */
end_comment

begin_struct
struct|struct
name|bxe_softc
block|{
comment|/* 	 * MUST start with ifnet pointer (see definition of miibus_statchg()). 	 */
name|struct
name|ifnet
modifier|*
name|bxe_ifp
decl_stmt|;
name|int
name|media
decl_stmt|;
comment|/* Parent device handle. */
name|device_t
name|bxe_dev
decl_stmt|;
comment|/* Driver instance number. */
name|u_int8_t
name|bxe_unit
decl_stmt|;
comment|/* FreeBSD network interface media structure. */
name|struct
name|ifmedia
name|bxe_ifmedia
decl_stmt|;
comment|/* Bus tag for the bxe controller. */
name|bus_dma_tag_t
name|parent_tag
decl_stmt|;
comment|/* OS resources for BAR0 memory. */
name|struct
name|resource
modifier|*
name|bxe_res
decl_stmt|;
name|bus_space_tag_t
name|bxe_btag
decl_stmt|;
name|bus_space_handle_t
name|bxe_bhandle
decl_stmt|;
name|vm_offset_t
name|bxe_vhandle
decl_stmt|;
comment|/* OS resources for BAR2 memory. */
comment|/* OS resources for BAR1 doorbell memory. */
define|#
directive|define
name|BXE_DB_SIZE
value|(16 * 2048)
name|struct
name|resource
modifier|*
name|bxe_db_res
decl_stmt|;
name|bus_space_tag_t
name|bxe_db_btag
decl_stmt|;
name|bus_space_handle_t
name|bxe_db_bhandle
decl_stmt|;
name|vm_offset_t
name|bxe_db_vhandle
decl_stmt|;
comment|/* Driver mutex. */
name|struct
name|mtx
name|bxe_core_mtx
decl_stmt|;
name|struct
name|mtx
name|bxe_sp_mtx
decl_stmt|;
name|struct
name|mtx
name|bxe_dmae_mtx
decl_stmt|;
name|struct
name|mtx
name|bxe_fwmb_mtx
decl_stmt|;
name|struct
name|mtx
name|bxe_print_mtx
decl_stmt|;
comment|/* Per-queue state. */
comment|/* ToDo: Convert to an array of pointers to conserve memory. */
name|struct
name|bxe_fastpath
name|fp
index|[
name|MAX_CONTEXT
index|]
decl_stmt|;
name|int
name|tx_ring_size
decl_stmt|;
comment|/* Legacy interrupt handler resources. */
name|struct
name|resource
modifier|*
name|bxe_irq_res
decl_stmt|;
name|int
name|bxe_irq_rid
decl_stmt|;
name|void
modifier|*
name|bxe_irq_tag
decl_stmt|;
comment|/* MSI-X interrupt handler resources (up to 17 vectors). */
name|struct
name|resource
modifier|*
name|bxe_msix_res
index|[
name|MAX_CONTEXT
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|bxe_msix_rid
index|[
name|MAX_CONTEXT
operator|+
literal|1
index|]
decl_stmt|;
name|void
modifier|*
name|bxe_msix_tag
index|[
name|MAX_CONTEXT
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|msix_count
decl_stmt|;
comment|/* MSI interrupt handler resources (up to XX vectors). */
define|#
directive|define
name|BXE_MSI_VECTOR_COUNT
value|8
name|struct
name|resource
modifier|*
name|bxe_msi_res
index|[
name|BXE_MSI_VECTOR_COUNT
index|]
decl_stmt|;
name|int
name|bxe_msi_rid
index|[
name|BXE_MSI_VECTOR_COUNT
index|]
decl_stmt|;
name|void
modifier|*
name|bxe_msi_tag
index|[
name|BXE_MSI_VECTOR_COUNT
index|]
decl_stmt|;
name|int
name|msi_count
decl_stmt|;
comment|/* Taskqueue resources. */
name|struct
name|task
name|task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* RX Driver parameters*/
name|uint32_t
name|rx_csum
decl_stmt|;
name|int
name|rx_buf_size
decl_stmt|;
comment|/* ToDo: Replace with OS specific defintions. */
define|#
directive|define
name|ETH_HLEN
value|14
define|#
directive|define
name|ETH_OVREHEAD
value|(ETH_HLEN + 8)
comment|/* 8 for CRC + VLAN */
define|#
directive|define
name|ETH_MIN_PACKET_SIZE
value|60
define|#
directive|define
name|ETH_MAX_PACKET_SIZE
value|1500
define|#
directive|define
name|ETH_MAX_JUMBO_PACKET_SIZE
value|9600
comment|/* Hardware Maintained Host Default Status Block. */
name|bus_dma_tag_t
name|def_status_block_tag
decl_stmt|;
name|bus_dmamap_t
name|def_status_block_map
decl_stmt|;
name|struct
name|host_def_status_block
modifier|*
name|def_status_block
decl_stmt|;
name|bus_addr_t
name|def_status_block_paddr
decl_stmt|;
define|#
directive|define
name|DEF_SB_ID
value|16
name|uint16_t
name|def_c_idx
decl_stmt|;
name|uint16_t
name|def_u_idx
decl_stmt|;
name|uint16_t
name|def_t_idx
decl_stmt|;
name|uint16_t
name|def_x_idx
decl_stmt|;
name|uint16_t
name|def_att_idx
decl_stmt|;
name|uint32_t
name|attn_state
decl_stmt|;
name|struct
name|attn_route
name|attn_group
index|[
name|MAX_DYNAMIC_ATTN_GRPS
index|]
decl_stmt|;
comment|/* H/W maintained statistics block. */
name|bus_dma_tag_t
name|stats_tag
decl_stmt|;
name|bus_dmamap_t
name|stats_map
decl_stmt|;
name|struct
name|statistics_block
modifier|*
name|stats_block
decl_stmt|;
name|bus_addr_t
name|stats_block_paddr
decl_stmt|;
comment|/* H/W maintained slow path. */
name|bus_dma_tag_t
name|slowpath_tag
decl_stmt|;
name|bus_dmamap_t
name|slowpath_map
decl_stmt|;
name|struct
name|bxe_slowpath
modifier|*
name|slowpath
decl_stmt|;
name|bus_addr_t
name|slowpath_paddr
decl_stmt|;
comment|/* Slow path ring. */
name|bus_dma_tag_t
name|spq_tag
decl_stmt|;
name|bus_dmamap_t
name|spq_map
decl_stmt|;
name|struct
name|eth_spe
modifier|*
name|spq
decl_stmt|;
name|bus_addr_t
name|spq_paddr
decl_stmt|;
name|uint16_t
name|spq_prod_idx
decl_stmt|;
name|struct
name|eth_spe
modifier|*
name|spq_prod_bd
decl_stmt|;
name|struct
name|eth_spe
modifier|*
name|spq_last_bd
decl_stmt|;
name|uint16_t
modifier|*
name|dsb_sp_prod
decl_stmt|;
name|uint16_t
modifier|*
name|spq_hw_con
decl_stmt|;
name|uint16_t
name|spq_left
decl_stmt|;
comment|/* State information for pending ramrod commands. */
name|uint8_t
name|stats_pending
decl_stmt|;
name|uint8_t
name|set_mac_pending
decl_stmt|;
name|int
name|panic
decl_stmt|;
comment|/* Device flags. */
name|uint32_t
name|bxe_flags
decl_stmt|;
define|#
directive|define
name|BXE_ONE_PORT_FLAG
value|0x00000004
define|#
directive|define
name|BXE_NO_WOL_FLAG
value|0x00000008
define|#
directive|define
name|BXE_USING_DAC_FLAG
value|0x00000010
define|#
directive|define
name|BXE_USING_MSIX_FLAG
value|0x00000020
define|#
directive|define
name|BXE_USING_MSI_FLAG
value|0x00000040
define|#
directive|define
name|BXE_TPA_ENABLE_FLAG
value|0x00000080
define|#
directive|define
name|BXE_NO_MCP_FLAG
value|0x00000100
define|#
directive|define
name|BP_NOMCP
parameter_list|(
name|sc
parameter_list|)
value|(sc->bxe_flags& BXE_NO_MCP_FLAG)
define|#
directive|define
name|BXE_SAFC_TX_FLAG
value|0x00000200
define|#
directive|define
name|TPA_ENABLED
parameter_list|(
name|sc
parameter_list|)
value|(sc->bxe_flags& BXE_TPA_ENABLE_FLAG)
comment|/* PCI Express function number for the device. */
name|int
name|bxe_func
decl_stmt|;
comment|/*  * Ethernet port to PCIe function mapping for  * 57710 and 57711:  * +---------------+---------------+-------------+  * | Ethernet Port | PCIe Function | Virtual NIC |  * |       0       |       0       |      0      |  * |       1       |       1       |      0      |  * +---------------+---------------+-------------+  *  * Ethernet port to PCIe function mapping for  * 57711E:  * +---------------+---------------+-------------+  * | Ethernet Port | PCIe Function | Virtual NIC |  * |       0       |       0       |      1      |  * |       1       |       1       |      2      |  * |       0       |       2       |      3      |  * |       1       |       3       |      4      |  * |       0       |       4       |      5      |  * |       1       |       5       |      6      |  * |       0       |       6       |      7      |  * |       1       |       7       |      8      |  * +---------------+---------------+-------------+  */
define|#
directive|define
name|BP_PORT
parameter_list|(
name|sc
parameter_list|)
value|(sc->bxe_func % PORT_MAX)
define|#
directive|define
name|BP_FUNC
parameter_list|(
name|sc
parameter_list|)
value|(sc->bxe_func)
define|#
directive|define
name|BP_E1HVN
parameter_list|(
name|sc
parameter_list|)
value|(sc->bxe_func>> 1)
define|#
directive|define
name|BP_L_ID
parameter_list|(
name|sc
parameter_list|)
value|(BP_E1HVN(sc)<< 2)
comment|/* PCI Express link information. */
name|uint16_t
name|pcie_link_width
decl_stmt|;
name|uint16_t
name|pcie_link_speed
decl_stmt|;
name|uint32_t
name|bxe_cap_flags
decl_stmt|;
define|#
directive|define
name|BXE_MSI_CAPABLE_FLAG
value|0x00000001
define|#
directive|define
name|BXE_MSIX_CAPABLE_FLAG
value|0x00000002
define|#
directive|define
name|BXE_PCIE_CAPABLE_FLAG
value|0x00000004
name|uint16_t
name|pcie_cap
decl_stmt|;
name|uint16_t
name|pm_cap
decl_stmt|;
comment|/* PCIe maximum read request size. */
name|int
name|mrrs
decl_stmt|;
comment|/* ToDo: Is this really needed? */
name|uint16_t
name|sp_running
decl_stmt|;
comment|/* Driver/firmware synchronization. */
name|uint16_t
name|fw_seq
decl_stmt|;
name|uint16_t
name|fw_drv_pulse_wr_seq
decl_stmt|;
name|uint32_t
name|fw_mb
decl_stmt|;
comment|/* 	 * MCP scratchpad address for function specific statistics. 	 * The device is responsible for writing statistics back to 	 * the MCP for use with management firmware such as UMP/NC-SI. 	 */
name|uint32_t
name|func_stx
decl_stmt|;
name|struct
name|link_params
name|link_params
decl_stmt|;
name|struct
name|link_vars
name|link_vars
decl_stmt|;
name|struct
name|bxe_common
name|common
decl_stmt|;
name|struct
name|bxe_port
name|port
decl_stmt|;
name|struct
name|cmng_struct_per_port
name|cmng
decl_stmt|;
name|uint32_t
name|vn_wsum
decl_stmt|;
name|uint32_t
name|cos_wsum
decl_stmt|;
name|uint8_t
name|ser_lane
decl_stmt|;
name|uint8_t
name|rx_lane_swap
decl_stmt|;
name|uint8_t
name|tx_lane_swap
decl_stmt|;
name|uint8_t
name|wol
decl_stmt|;
name|int
name|rx_ring_size
decl_stmt|;
comment|/* RX/TX Interrupt Coalescing Parameters */
name|uint16_t
name|rx_ticks
decl_stmt|;
name|uint16_t
name|tx_ticks
decl_stmt|;
comment|/* Device State: Used for Driver-FW communication. */
name|int
name|state
decl_stmt|;
define|#
directive|define
name|BXE_STATE_CLOSED
value|0x0
define|#
directive|define
name|BXE_STATE_OPENING_WAIT4_LOAD
value|0x1000
define|#
directive|define
name|BXE_STATE_OPENING_WAIT4_PORT
value|0x2000
define|#
directive|define
name|BXE_STATE_OPEN
value|0x3000
define|#
directive|define
name|BXE_STATE_CLOSING_WAIT4_HALT
value|0x4000
define|#
directive|define
name|BXE_STATE_CLOSING_WAIT4_DELETE
value|0x5000
define|#
directive|define
name|BXE_STATE_CLOSING_WAIT4_UNLOAD
value|0x6000
define|#
directive|define
name|BXE_STATE_DISABLED
value|0xD000
define|#
directive|define
name|BXE_STATE_DIAG
value|0xE000
define|#
directive|define
name|BXE_STATE_ERROR
value|0xF000
name|int
name|int_mode
decl_stmt|;
name|int
name|multi_mode
decl_stmt|;
define|#
directive|define
name|BXE_MAX_COS
value|3
define|#
directive|define
name|BXE_MAX_PRIORITY
value|8
define|#
directive|define
name|BXE_MAX_ENTRIES_PER_PRI
value|16
comment|/* Number of queues per class of service. */
name|uint8_t
name|qs_per_cos
index|[
name|BXE_MAX_COS
index|]
decl_stmt|;
comment|/* Priority to class of service mapping. */
name|uint8_t
name|pri_map
index|[
name|BXE_MAX_PRIORITY
index|]
decl_stmt|;
comment|/* min rate per cos */
name|uint16_t
name|cos_min_rate
index|[
name|BXE_MAX_COS
index|]
decl_stmt|;
comment|/* Class of service to queue mapping. */
name|uint8_t
name|cos_map
index|[
name|BXE_MAX_COS
index|]
decl_stmt|;
comment|/* The number of fastpath queues (for RSS/multi-queue). */
name|int
name|num_queues
decl_stmt|;
define|#
directive|define
name|BXE_NUM_QUEUES
parameter_list|(
name|cos
parameter_list|)
define|\
value|((bxe_qs_per_cos& (0xff<< (cos * 8)))>> (cos * 8))
define|#
directive|define
name|BXE_MAX_QUEUES
parameter_list|(
name|sc
parameter_list|)
define|\
value|(IS_E1HMF(sc) ? (MAX_CONTEXT / E1HVN_MAX) : MAX_CONTEXT)
comment|/* Used for multiple function devices. */
name|uint32_t
name|mf_config
index|[
name|E1HVN_MAX
index|]
decl_stmt|;
comment|/* Outer VLAN tag. */
name|uint16_t
name|e1hov
decl_stmt|;
define|#
directive|define
name|IS_E1HOV
parameter_list|(
name|sc
parameter_list|)
value|(sc->e1hov != 0)
name|uint8_t
name|e1hmf
decl_stmt|;
define|#
directive|define
name|IS_E1HMF
parameter_list|(
name|sc
parameter_list|)
value|(sc->e1hmf != 0)
comment|/* Receive mode settings (i.e promiscuous, multicast, etc.). */
name|uint32_t
name|rx_mode
decl_stmt|;
define|#
directive|define
name|BXE_RX_MODE_NONE
value|0
define|#
directive|define
name|BXE_RX_MODE_NORMAL
value|1
define|#
directive|define
name|BXE_RX_MODE_ALLMULTI
value|2
define|#
directive|define
name|BXE_RX_MODE_PROMISC
value|3
define|#
directive|define
name|BXE_MAX_MULTICAST
value|64
define|#
directive|define
name|BXE_MAX_EMUL_MULTI
value|16
name|uint32_t
name|rx_mode_cl_mask
decl_stmt|;
comment|/* Device name */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Used to synchronize statistics collection. */
name|int
name|stats_state
decl_stmt|;
define|#
directive|define
name|STATS_STATE_DISABLE
value|0
define|#
directive|define
name|STATS_STATE_ENABLE
value|1
define|#
directive|define
name|STATS_STATE_STOP
value|2
name|int
name|dmae_ready
decl_stmt|;
comment|/* Used by the DMAE command loader. */
name|struct
name|dmae_command
name|stats_dmae
decl_stmt|;
name|struct
name|dmae_command
name|init_dmae
decl_stmt|;
name|int
name|executer_idx
decl_stmt|;
comment|/* Statistics. */
name|uint16_t
name|stats_counter
decl_stmt|;
name|struct
name|bxe_eth_stats
name|eth_stats
decl_stmt|;
name|z_streamp
name|strm
decl_stmt|;
name|bus_dma_tag_t
name|gunzip_tag
decl_stmt|;
name|bus_dmamap_t
name|gunzip_map
decl_stmt|;
name|void
modifier|*
name|gunzip_buf
decl_stmt|;
name|bus_addr_t
name|gunzip_mapping
decl_stmt|;
name|int
name|gunzip_outlen
decl_stmt|;
define|#
directive|define
name|FW_BUF_SIZE
value|0x40000
name|struct
name|raw_op
modifier|*
name|init_ops
decl_stmt|;
comment|/* Init blocks offsets inside init_ops */
specifier|const
name|uint16_t
modifier|*
name|init_ops_offsets
decl_stmt|;
comment|/* Data blob - has 32 bit granularity */
specifier|const
name|uint32_t
modifier|*
name|init_data
decl_stmt|;
comment|/* PRAM blobs - raw data */
specifier|const
name|uint8_t
modifier|*
name|tsem_int_table_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|tsem_pram_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|usem_int_table_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|usem_pram_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|xsem_int_table_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|xsem_pram_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|csem_int_table_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|csem_pram_data
decl_stmt|;
define|#
directive|define
name|INIT_OPS
parameter_list|(
name|sc
parameter_list|)
value|(sc->init_ops)
define|#
directive|define
name|INIT_OPS_OFFSETS
parameter_list|(
name|sc
parameter_list|)
value|(sc->init_ops_offsets)
define|#
directive|define
name|INIT_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->init_data)
define|#
directive|define
name|INIT_TSEM_INT_TABLE_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->tsem_int_table_data)
define|#
directive|define
name|INIT_TSEM_PRAM_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->tsem_pram_data)
define|#
directive|define
name|INIT_USEM_INT_TABLE_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->usem_int_table_data)
define|#
directive|define
name|INIT_USEM_PRAM_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->usem_pram_data)
define|#
directive|define
name|INIT_XSEM_INT_TABLE_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->xsem_int_table_data)
define|#
directive|define
name|INIT_XSEM_PRAM_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->xsem_pram_data)
define|#
directive|define
name|INIT_CSEM_INT_TABLE_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->csem_int_table_data)
define|#
directive|define
name|INIT_CSEM_PRAM_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->csem_pram_data)
comment|/* OS handle for periodic tick routine. */
name|struct
name|callout
name|bxe_tick_callout
decl_stmt|;
name|uint8_t
name|pad
decl_stmt|;
comment|/* Frame size and mbuf allocation size for RX frames. */
name|uint32_t
name|max_frame_size
decl_stmt|;
name|int
name|mbuf_alloc_size
decl_stmt|;
name|uint16_t
name|tx_driver
decl_stmt|;
comment|/* Ticks until chip reset. */
name|int
name|watchdog_timer
decl_stmt|;
comment|/* Verify bxe_function_init is run before handling interrupts. */
name|uint8_t
name|intr_sem
decl_stmt|;
ifdef|#
directive|ifdef
name|BXE_DEBUG
name|unsigned
name|long
name|debug_mbuf_sim_alloc_failed
decl_stmt|;
name|unsigned
name|long
name|debug_mbuf_sim_map_failed
decl_stmt|;
name|unsigned
name|long
name|debug_received_frame_error
decl_stmt|;
name|unsigned
name|long
name|debug_memory_allocated
decl_stmt|;
comment|/* A buffer for hardware/firmware state information (grcdump). */
name|uint32_t
modifier|*
name|grcdump_buffer
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVST_STOP_ON_ERROR
name|uint32_t
name|next_free
decl_stmt|;
name|uint32_t
name|last_alloc
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* end of struct bxe_softc */
end_comment

begin_define
define|#
directive|define
name|MDIO_AN_CL73_OR_37_COMPLETE
define|\
value|(MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_AUTONEG_COMPLETE |		\ 	MDIO_GP_STATUS_TOP_AN_STATUS1_CL37_AUTONEG_COMPLETE)
end_define

begin_define
define|#
directive|define
name|GP_STATUS_PAUSE_RSOLUTION_TXSIDE
define|\
value|MDIO_GP_STATUS_TOP_AN_STATUS1_PAUSE_RSOLUTION_TXSIDE
end_define

begin_define
define|#
directive|define
name|GP_STATUS_PAUSE_RSOLUTION_RXSIDE
define|\
value|MDIO_GP_STATUS_TOP_AN_STATUS1_PAUSE_RSOLUTION_RXSIDE
end_define

begin_define
define|#
directive|define
name|GP_STATUS_SPEED_MASK
define|\
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_MASK
end_define

begin_define
define|#
directive|define
name|GP_STATUS_10M
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10M
end_define

begin_define
define|#
directive|define
name|GP_STATUS_100M
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_100M
end_define

begin_define
define|#
directive|define
name|GP_STATUS_1G
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_1G
end_define

begin_define
define|#
directive|define
name|GP_STATUS_2_5G
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_2_5G
end_define

begin_define
define|#
directive|define
name|GP_STATUS_5G
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_5G
end_define

begin_define
define|#
directive|define
name|GP_STATUS_6G
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_6G
end_define

begin_define
define|#
directive|define
name|GP_STATUS_10G_HIG
define|\
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_HIG
end_define

begin_define
define|#
directive|define
name|GP_STATUS_10G_CX4
define|\
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_CX4
end_define

begin_define
define|#
directive|define
name|GP_STATUS_12G_HIG
define|\
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_12G_HIG
end_define

begin_define
define|#
directive|define
name|GP_STATUS_12_5G
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_12_5G
end_define

begin_define
define|#
directive|define
name|GP_STATUS_13G
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_13G
end_define

begin_define
define|#
directive|define
name|GP_STATUS_15G
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_15G
end_define

begin_define
define|#
directive|define
name|GP_STATUS_16G
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_16G
end_define

begin_define
define|#
directive|define
name|GP_STATUS_1G_KX
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_1G_KX
end_define

begin_define
define|#
directive|define
name|GP_STATUS_10G_KX4
define|\
value|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_KX4
end_define

begin_define
define|#
directive|define
name|LINK_10THD
value|LINK_STATUS_SPEED_AND_DUPLEX_10THD
end_define

begin_define
define|#
directive|define
name|LINK_10TFD
value|LINK_STATUS_SPEED_AND_DUPLEX_10TFD
end_define

begin_define
define|#
directive|define
name|LINK_100TXHD
value|LINK_STATUS_SPEED_AND_DUPLEX_100TXHD
end_define

begin_define
define|#
directive|define
name|LINK_100T4
value|LINK_STATUS_SPEED_AND_DUPLEX_100T4
end_define

begin_define
define|#
directive|define
name|LINK_100TXFD
value|LINK_STATUS_SPEED_AND_DUPLEX_100TXFD
end_define

begin_define
define|#
directive|define
name|LINK_1000THD
value|LINK_STATUS_SPEED_AND_DUPLEX_1000THD
end_define

begin_define
define|#
directive|define
name|LINK_1000TFD
value|LINK_STATUS_SPEED_AND_DUPLEX_1000TFD
end_define

begin_define
define|#
directive|define
name|LINK_1000XFD
value|LINK_STATUS_SPEED_AND_DUPLEX_1000XFD
end_define

begin_define
define|#
directive|define
name|LINK_2500THD
value|LINK_STATUS_SPEED_AND_DUPLEX_2500THD
end_define

begin_define
define|#
directive|define
name|LINK_2500TFD
value|LINK_STATUS_SPEED_AND_DUPLEX_2500TFD
end_define

begin_define
define|#
directive|define
name|LINK_2500XFD
value|LINK_STATUS_SPEED_AND_DUPLEX_2500XFD
end_define

begin_define
define|#
directive|define
name|LINK_10GTFD
value|LINK_STATUS_SPEED_AND_DUPLEX_10GTFD
end_define

begin_define
define|#
directive|define
name|LINK_10GXFD
value|LINK_STATUS_SPEED_AND_DUPLEX_10GXFD
end_define

begin_define
define|#
directive|define
name|LINK_12GTFD
value|LINK_STATUS_SPEED_AND_DUPLEX_12GTFD
end_define

begin_define
define|#
directive|define
name|LINK_12GXFD
value|LINK_STATUS_SPEED_AND_DUPLEX_12GXFD
end_define

begin_define
define|#
directive|define
name|LINK_12_5GTFD
value|LINK_STATUS_SPEED_AND_DUPLEX_12_5GTFD
end_define

begin_define
define|#
directive|define
name|LINK_12_5GXFD
value|LINK_STATUS_SPEED_AND_DUPLEX_12_5GXFD
end_define

begin_define
define|#
directive|define
name|LINK_13GTFD
value|LINK_STATUS_SPEED_AND_DUPLEX_13GTFD
end_define

begin_define
define|#
directive|define
name|LINK_13GXFD
value|LINK_STATUS_SPEED_AND_DUPLEX_13GXFD
end_define

begin_define
define|#
directive|define
name|LINK_15GTFD
value|LINK_STATUS_SPEED_AND_DUPLEX_15GTFD
end_define

begin_define
define|#
directive|define
name|LINK_15GXFD
value|LINK_STATUS_SPEED_AND_DUPLEX_15GXFD
end_define

begin_define
define|#
directive|define
name|LINK_16GTFD
value|LINK_STATUS_SPEED_AND_DUPLEX_16GTFD
end_define

begin_define
define|#
directive|define
name|LINK_16GXFD
value|LINK_STATUS_SPEED_AND_DUPLEX_16GXFD
end_define

begin_define
define|#
directive|define
name|MEDIUM_FULL_DUPLEX
value|0
end_define

begin_define
define|#
directive|define
name|MEDIUM_HALF_DUPLEX
value|1
end_define

begin_define
define|#
directive|define
name|DUPLEX_FULL
value|0
end_define

begin_define
define|#
directive|define
name|DUPLEX_HALF
value|1
end_define

begin_define
define|#
directive|define
name|SPEED_10
value|10
end_define

begin_define
define|#
directive|define
name|SPEED_100
value|100
end_define

begin_define
define|#
directive|define
name|SPEED_1000
value|1000
end_define

begin_define
define|#
directive|define
name|SPEED_2500
value|2500
end_define

begin_define
define|#
directive|define
name|SPEED_10000
value|10000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|NIG_STATUS_XGXS0_LINK10G
define|\
value|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK10G
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_XGXS0_LINK_STATUS
define|\
value|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK_STATUS
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_XGXS0_LINK_STATUS_SIZE
define|\
value|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK_STATUS_SIZE
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_SERDES0_LINK_STATUS
define|\
value|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_SERDES0_LINK_STATUS
end_define

begin_define
define|#
directive|define
name|NIG_MASK_MI_INT
define|\
value|NIG_MASK_INTERRUPT_PORT0_REG_MASK_EMAC0_MISC_MI_INT
end_define

begin_define
define|#
directive|define
name|NIG_MASK_XGXS0_LINK10G
define|\
value|NIG_MASK_INTERRUPT_PORT0_REG_MASK_XGXS0_LINK10G
end_define

begin_define
define|#
directive|define
name|NIG_MASK_XGXS0_LINK_STATUS
define|\
value|NIG_MASK_INTERRUPT_PORT0_REG_MASK_XGXS0_LINK_STATUS
end_define

begin_define
define|#
directive|define
name|NIG_MASK_SERDES0_LINK_STATUS
define|\
value|NIG_MASK_INTERRUPT_PORT0_REG_MASK_SERDES0_LINK_STATUS
end_define

begin_define
define|#
directive|define
name|XGXS_RESET_BITS
define|\
value|(MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_RSTB_HW |	\ 	MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_IDDQ |		\ 	MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_PWRDWN |		\ 	MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_PWRDWN_SD |	\ 	MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_TXD_FIFO_RSTB)
end_define

begin_define
define|#
directive|define
name|SERDES_RESET_BITS
define|\
value|(MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_RSTB_HW |	\ 	MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_IDDQ |		\ 	MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_PWRDWN |	\ 	MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_PWRDWN_SD)
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_CON_TYPE_ADDR
value|0x2
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_CON_TYPE_VAL_LC
value|0x7
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_CON_TYPE_VAL_COPPER
value|0x21
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_FC_TX_TECH_ADDR
value|0x8
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_FC_TX_TECH_BITMASK_COPPER_ACTIVE
value|0x8
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_VENDOR_NAME_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_OPTIONS_LINEAR_RX_OUT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_OPTIONS_SIZE
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BXE_PMF_LINK_ASSERT
define|\
value|GENERAL_ATTEN_OFFSET(LINK_SYNC_ATTENTION_BIT_FUNC_0 + BP_FUNC(sc))
end_define

begin_define
define|#
directive|define
name|BXE_MC_ASSERT_BITS
define|\
value|(GENERAL_ATTEN_OFFSET(TSTORM_FATAL_ASSERT_ATTENTION_BIT) |	\ 	GENERAL_ATTEN_OFFSET(USTORM_FATAL_ASSERT_ATTENTION_BIT) |	\ 	GENERAL_ATTEN_OFFSET(CSTORM_FATAL_ASSERT_ATTENTION_BIT) |	\ 	GENERAL_ATTEN_OFFSET(XSTORM_FATAL_ASSERT_ATTENTION_BIT))
end_define

begin_define
define|#
directive|define
name|BXE_MCP_ASSERT
define|\
value|GENERAL_ATTEN_OFFSET(MCP_FATAL_ASSERT_ATTENTION_BIT)
end_define

begin_define
define|#
directive|define
name|BXE_GRC_TIMEOUT
define|\
value|GENERAL_ATTEN_OFFSET(LATCHED_ATTN_TIMEOUT_GRC)
end_define

begin_define
define|#
directive|define
name|BXE_GRC_RSV
define|\
value|(GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCR) |			\ 	 GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCT) |			\ 	 GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCN) |			\ 	 GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCU) |			\ 	 GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCP) |			\ 	 GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RSVD_GRC))
end_define

begin_define
define|#
directive|define
name|HW_INTERRUT_ASSERT_SET_0
define|\
value|(AEU_INPUTS_ATTN_BITS_TSDM_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_TCM_HW_INTERRUPT |				\ 	AEU_INPUTS_ATTN_BITS_TSEMI_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_PBF_HW_INTERRUPT)
end_define

begin_define
define|#
directive|define
name|HW_PRTY_ASSERT_SET_0
define|\
value|(AEU_INPUTS_ATTN_BITS_BRB_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_PARSER_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_TSDM_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_SEARCHER_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_TSEMI_PARITY_ERROR)
end_define

begin_define
define|#
directive|define
name|HW_INTERRUT_ASSERT_SET_1
define|\
value|(AEU_INPUTS_ATTN_BITS_QM_HW_INTERRUPT |				\ 	AEU_INPUTS_ATTN_BITS_TIMERS_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_XSDM_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_XCM_HW_INTERRUPT |				\ 	AEU_INPUTS_ATTN_BITS_XSEMI_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_USDM_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_UCM_HW_INTERRUPT |				\ 	AEU_INPUTS_ATTN_BITS_USEMI_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_UPB_HW_INTERRUPT |				\ 	AEU_INPUTS_ATTN_BITS_CSDM_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_CCM_HW_INTERRUPT)
end_define

begin_define
define|#
directive|define
name|HW_PRTY_ASSERT_SET_1
define|\
value|(AEU_INPUTS_ATTN_BITS_PBCLIENT_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_QM_PARITY_ERROR |				\ 	AEU_INPUTS_ATTN_BITS_XSDM_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_XSEMI_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_DOORBELLQ_PARITY_ERROR |			\     	AEU_INPUTS_ATTN_BITS_VAUX_PCI_CORE_PARITY_ERROR |		\ 	AEU_INPUTS_ATTN_BITS_DEBUG_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_USDM_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_USEMI_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_UPB_PARITY_ERROR |				\ 	AEU_INPUTS_ATTN_BITS_CSDM_PARITY_ERROR)
end_define

begin_define
define|#
directive|define
name|HW_INTERRUT_ASSERT_SET_2
define|\
value|(AEU_INPUTS_ATTN_BITS_CSEMI_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_CDU_HW_INTERRUPT |				\ 	AEU_INPUTS_ATTN_BITS_DMAE_HW_INTERRUPT |			\ 	AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_HW_INTERRUPT |		\ 	AEU_INPUTS_ATTN_BITS_MISC_HW_INTERRUPT)
end_define

begin_define
define|#
directive|define
name|HW_PRTY_ASSERT_SET_2
define|\
value|(AEU_INPUTS_ATTN_BITS_CSEMI_PARITY_ERROR |			\ 	AEU_INPUTS_ATTN_BITS_PXP_PARITY_ERROR |				\ 	AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_PARITY_ERROR |		\ 	AEU_INPUTS_ATTN_BITS_CFC_PARITY_ERROR |				\ 	AEU_INPUTS_ATTN_BITS_CDU_PARITY_ERROR |				\ 	AEU_INPUTS_ATTN_BITS_IGU_PARITY_ERROR |				\ 	AEU_INPUTS_ATTN_BITS_MISC_PARITY_ERROR)
end_define

begin_comment
comment|/* Stuff added to make the code fit 80Col. */
end_comment

begin_define
define|#
directive|define
name|CQE_TYPE
parameter_list|(
name|cqe_fp_flags
parameter_list|)
value|((cqe_fp_flags)& ETH_FAST_PATH_RX_CQE_TYPE)
end_define

begin_define
define|#
directive|define
name|TPA_TYPE_START
value|ETH_FAST_PATH_RX_CQE_START_FLG
end_define

begin_define
define|#
directive|define
name|TPA_TYPE_END
value|ETH_FAST_PATH_RX_CQE_END_FLG
end_define

begin_define
define|#
directive|define
name|TPA_TYPE
parameter_list|(
name|cqe_fp_flags
parameter_list|)
define|\
value|((cqe_fp_flags)& (TPA_TYPE_START | TPA_TYPE_END))
end_define

begin_define
define|#
directive|define
name|ETH_RX_ERROR_FLAGS
value|ETH_FAST_PATH_RX_CQE_PHY_DECODE_ERR_FLG
end_define

begin_define
define|#
directive|define
name|BXE_IP_CSUM_ERR
parameter_list|(
name|cqe
parameter_list|)
define|\
value|(!((cqe)->fast_path_cqe.status_flags&				\ 	ETH_FAST_PATH_RX_CQE_IP_XSUM_NO_VALIDATION_FLG)&&		\ 	((cqe)->fast_path_cqe.type_error_flags&			\ 	ETH_FAST_PATH_RX_CQE_IP_BAD_XSUM_FLG))
end_define

begin_define
define|#
directive|define
name|BXE_L4_CSUM_ERR
parameter_list|(
name|cqe
parameter_list|)
define|\
value|(!((cqe)->fast_path_cqe.status_flags&				\ 	ETH_FAST_PATH_RX_CQE_L4_XSUM_NO_VALIDATION_FLG)&&		\ 	((cqe)->fast_path_cqe.type_error_flags&			\ 	ETH_FAST_PATH_RX_CQE_L4_BAD_XSUM_FLG))
end_define

begin_define
define|#
directive|define
name|BXE_RX_CSUM_OK
parameter_list|(
name|cqe
parameter_list|)
define|\
value|(!(BXE_L4_CSUM_ERR(cqe) || BXE_IP_CSUM_ERR(cqe)))
end_define

begin_define
define|#
directive|define
name|BXE_RX_SUM_FIX
parameter_list|(
name|cqe
parameter_list|)
define|\
value|((le16toh(cqe->fast_path_cqe.pars_flags.flags)&		\ 	PARSING_FLAGS_OVER_ETHERNET_PROTOCOL) ==			\ 	(1<< PARSING_FLAGS_OVER_ETHERNET_PROTOCOL_SHIFT))
end_define

begin_define
define|#
directive|define
name|MULTI_FLAGS
parameter_list|(
name|sc
parameter_list|)
define|\
value|(TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV4_CAPABILITY |	\ 	TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV4_TCP_CAPABILITY |	\ 	TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV6_CAPABILITY |		\ 	TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV6_TCP_CAPABILITY |	\ 	(sc->multi_mode<<						\ 	TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_MODE_SHIFT))
end_define

begin_define
define|#
directive|define
name|MULTI_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|FP_USB_FUNC_OFF
value|(2 + 2 * HC_USTORM_SB_NUM_INDICES)
end_define

begin_define
define|#
directive|define
name|FP_CSB_FUNC_OFF
value|(2 + 2 * HC_CSTORM_SB_NUM_INDICES)
end_define

begin_define
define|#
directive|define
name|U_SB_ETH_RX_CQ_INDEX
value|HC_INDEX_U_ETH_RX_CQ_CONS
end_define

begin_define
define|#
directive|define
name|U_SB_ETH_RX_BD_INDEX
value|HC_INDEX_U_ETH_RX_BD_CONS
end_define

begin_define
define|#
directive|define
name|C_SB_ETH_TX_CQ_INDEX
value|HC_INDEX_C_ETH_TX_CQ_CONS
end_define

begin_define
define|#
directive|define
name|DEF_USB_FUNC_OFF
value|(2 + 2 * HC_USTORM_DEF_SB_NUM_INDICES)
end_define

begin_define
define|#
directive|define
name|DEF_CSB_FUNC_OFF
value|(2 + 2 * HC_CSTORM_DEF_SB_NUM_INDICES)
end_define

begin_define
define|#
directive|define
name|DEF_XSB_FUNC_OFF
value|(2 + 2 * HC_XSTORM_DEF_SB_NUM_INDICES)
end_define

begin_define
define|#
directive|define
name|DEF_TSB_FUNC_OFF
value|(2 + 2 * HC_TSTORM_DEF_SB_NUM_INDICES)
end_define

begin_define
define|#
directive|define
name|C_DEF_SB_SP_INDEX
value|HC_INDEX_DEF_C_ETH_SLOW_PATH
end_define

begin_define
define|#
directive|define
name|BXE_RX_SB_INDEX
define|\
value|&fp->status_block->u_status_block.index_values[U_SB_ETH_RX_CQ_INDEX]
end_define

begin_define
define|#
directive|define
name|BXE_RX_SB_BD_INDEX
define|\
value|(&fp->status_block->u_status_block.index_values[U_SB_ETH_RX_BD_INDEX])
end_define

begin_define
define|#
directive|define
name|BXE_TX_SB_INDEX
define|\
value|(&fp->status_block->c_status_block.index_values[C_SB_ETH_TX_CQ_INDEX])
end_define

begin_define
define|#
directive|define
name|BXE_SP_DSB_INDEX
define|\
value|&sc->def_status_block->c_def_status_block.index_values[C_DEF_SB_SP_INDEX]
end_define

begin_define
define|#
directive|define
name|BXE_RX_SB_INDEX_NUM
define|\
value|(((U_SB_ETH_RX_CQ_INDEX<<					\ 	USTORM_ETH_ST_CONTEXT_CONFIG_CQE_SB_INDEX_NUMBER_SHIFT)&	\ 	USTORM_ETH_ST_CONTEXT_CONFIG_CQE_SB_INDEX_NUMBER) |		\ 	((U_SB_ETH_RX_BD_INDEX<<					\ 	USTORM_ETH_ST_CONTEXT_CONFIG_BD_SB_INDEX_NUMBER_SHIFT)&	\ 	USTORM_ETH_ST_CONTEXT_CONFIG_BD_SB_INDEX_NUMBER))
end_define

begin_define
define|#
directive|define
name|CAM_IS_INVALID
parameter_list|(
name|x
parameter_list|)
define|\
value|(x.target_table_entry.flags ==					\ 	TSTORM_CAM_TARGET_TABLE_ENTRY_ACTION_TYPE)
end_define

begin_define
define|#
directive|define
name|CAM_INVALIDATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(x.target_table_entry.flags = TSTORM_CAM_TARGET_TABLE_ENTRY_ACTION_TYPE)
end_define

begin_comment
comment|/* Number of uint32_t elements in multicast hash array. */
end_comment

begin_define
define|#
directive|define
name|MC_HASH_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|MC_HASH_OFFSET
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|(BAR_TSTORM_INTMEM +						\ 	TSTORM_APPROXIMATE_MATCH_MULTICAST_FILTERING_OFFSET(BP_FUNC(sc)) + \ 	i * 4)
end_define

begin_define
define|#
directive|define
name|UINT_MAX
value|(~0U)
end_define

begin_comment
comment|/*  * PCIE Capability Register Definitions. Need to replace with the system  * header file later.  */
end_comment

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL
value|8
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_CERE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_NFERE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_FERE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_URRE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_RELAX_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_PAYLOAD
value|0x00e0
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_EXT_TAG
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_PHANTOM
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_AUX_PME
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_NOSNOOP_EN
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_READRQ
value|0x7000
end_define

begin_comment
comment|/*  * Return Value for bxe_attach/bxe_detach when device is not found.  */
end_comment

begin_comment
comment|/* ToDo: Are these necessary? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENODEV
end_ifndef

begin_define
define|#
directive|define
name|ENODEV
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return Vlaue for sp_post */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ESPQOVERFLOW
end_ifndef

begin_define
define|#
directive|define
name|ESPQOVERFLOW
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return Value for bxe_write_phy, bxe_read_phy. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EBUSY
end_ifndef

begin_define
define|#
directive|define
name|EBUSY
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_EXP_DEVCTL
end_ifndef

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL
value|8
end_define

begin_comment
comment|/* Device Control */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_EXP_DEVCTL_PAYLOAD
end_ifndef

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_PAYLOAD
value|0x00e0
end_define

begin_comment
comment|/* Max_Payload_Size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_EXP_DEVCTL_READRQ
end_ifndef

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_READRQ
value|0x7000
end_define

begin_comment
comment|/* Max_Read_Request_Size */
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
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_comment
comment|/* ToDo: Validate this! */
end_comment

begin_comment
comment|/* 128 byte L1 cache size. */
end_comment

begin_define
define|#
directive|define
name|BXE_RX_ALIGN_SHIFT
value|7
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ToDo: Validate this! */
end_comment

begin_comment
comment|/* 256 byte L1 cache size. */
end_comment

begin_define
define|#
directive|define
name|BXE_RX_ALIGN_SHIFT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BXE_RX_ALIGN
value|(1<< BXE_RX_ALIGN_SHIFT)
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|800054
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__asm volatile("mfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|__asm volatile("sfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|__asm volatile("lfence" ::: "memory")
end_define

begin_function
specifier|static
name|__inline
name|void
name|prefetch
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
asm|__asm volatile("prefetcht0 %0" :: "m" (*(unsigned long *)x));
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|prefetch
parameter_list|()
end_define

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
name|BXE_RX_ALIGN
value|(1<< BXE_RX_ALIGN_SHIFT)
end_define

begin_define
define|#
directive|define
name|PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|(((addr) + PAGE_SIZE - 1)& (~PAGE_MASK))
end_define

begin_comment
comment|/* External PHY definitions. */
end_comment

begin_define
define|#
directive|define
name|LED_MODE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|LED_MODE_OPER
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_IF_BXE_H */
end_comment

end_unit

