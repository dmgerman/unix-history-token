begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016,2017 SoftIron Inc.  * All rights reserved.  *  * This software was developed by Andrew Turner under  * the sponsorship of SoftIron Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XGBE_OSDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_XGBE_OSDEP_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_typedef
typedef|typedef
name|uint8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__le32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|mtx
name|lock
decl_stmt|;
block|}
name|spinlock_t
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|void
name|spin_lock_init
parameter_list|(
name|spinlock_t
modifier|*
name|spinlock
parameter_list|)
block|{
name|mtx_init
argument_list|(
operator|&
name|spinlock
operator|->
name|lock
argument_list|,
literal|"axgbe_spin"
argument_list|,
name|NULL
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|spin_lock_irqsave
parameter_list|(
name|spinlock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do {									\ 	(flags) = intr_disable();					\ 	mtx_lock(&(spinlock)->lock);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|spin_unlock_irqrestore
parameter_list|(
name|spinlock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do {									\ 	mtx_unlock(&(spinlock)->lock);					\ 	intr_restore(flags);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|pos
parameter_list|)
value|(1ul<< pos)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|clear_bit
parameter_list|(
name|int
name|pos
parameter_list|,
name|unsigned
name|long
modifier|*
name|p
parameter_list|)
block|{
name|atomic_clear_long
argument_list|(
name|p
argument_list|,
literal|1ul
operator|<<
name|pos
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|test_bit
parameter_list|(
name|int
name|pos
parameter_list|,
name|unsigned
name|long
modifier|*
name|p
parameter_list|)
block|{
name|unsigned
name|long
name|val
decl_stmt|;
name|val
operator|=
operator|*
name|p
expr_stmt|;
return|return
operator|(
operator|(
name|val
operator|&
literal|1ul
operator|<<
name|pos
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_bit
parameter_list|(
name|int
name|pos
parameter_list|,
name|unsigned
name|long
modifier|*
name|p
parameter_list|)
block|{
name|atomic_set_long
argument_list|(
name|p
argument_list|,
literal|1ul
operator|<<
name|pos
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|lower_32_bits
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffffffffu)
end_define

begin_define
define|#
directive|define
name|upper_32_bits
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 32)& 0xffffffffu)
end_define

begin_define
define|#
directive|define
name|cpu_to_le32
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
end_define

begin_define
define|#
directive|define
name|le32_to_cpu
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_AXGBE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ADVERTISED_Pause
value|0x01
end_define

begin_define
define|#
directive|define
name|ADVERTISED_Asym_Pause
value|0x02
end_define

begin_define
define|#
directive|define
name|ADVERTISED_Autoneg
value|0x04
end_define

begin_define
define|#
directive|define
name|ADVERTISED_Backplane
value|0x08
end_define

begin_define
define|#
directive|define
name|ADVERTISED_10000baseKR_Full
value|0x10
end_define

begin_define
define|#
directive|define
name|ADVERTISED_2500baseX_Full
value|0x20
end_define

begin_define
define|#
directive|define
name|ADVERTISED_1000baseKX_Full
value|0x40
end_define

begin_define
define|#
directive|define
name|AUTONEG_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|AUTONEG_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|DUPLEX_UNKNOWN
value|1
end_define

begin_define
define|#
directive|define
name|DUPLEX_FULL
value|2
end_define

begin_define
define|#
directive|define
name|SPEED_UNKNOWN
value|1
end_define

begin_define
define|#
directive|define
name|SPEED_10000
value|2
end_define

begin_define
define|#
directive|define
name|SPEED_2500
value|3
end_define

begin_define
define|#
directive|define
name|SPEED_1000
value|4
end_define

begin_define
define|#
directive|define
name|SUPPORTED_Autoneg
value|0x01
end_define

begin_define
define|#
directive|define
name|SUPPORTED_Pause
value|0x02
end_define

begin_define
define|#
directive|define
name|SUPPORTED_Asym_Pause
value|0x04
end_define

begin_define
define|#
directive|define
name|SUPPORTED_Backplane
value|0x08
end_define

begin_define
define|#
directive|define
name|SUPPORTED_10000baseKR_Full
value|0x10
end_define

begin_define
define|#
directive|define
name|SUPPORTED_1000baseKX_Full
value|0x20
end_define

begin_define
define|#
directive|define
name|SUPPORTED_2500baseX_Full
value|0x40
end_define

begin_define
define|#
directive|define
name|SUPPORTED_10000baseR_FEC
value|0x80
end_define

begin_define
define|#
directive|define
name|BMCR_SPEED100
value|0x2000
end_define

begin_define
define|#
directive|define
name|MDIO_MMD_PMAPMD
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_MMD_PCS
value|3
end_define

begin_define
define|#
directive|define
name|MDIO_MMD_AN
value|7
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_10GBR_FECABLE
value|170
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_10GBR_FECABLE_ABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_10GBR_FECABLE_ERRABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MII_ADDR_C45
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|MDIO_CTRL1
value|0x00
end_define

begin_comment
comment|/* MII_BMCR */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTRL1_RESET
value|0x8000
end_define

begin_comment
comment|/* BMCR_RESET */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTRL1_SPEEDSELEXT
value|0x2040
end_define

begin_comment
comment|/* BMCR_SPEED1000|BMCR_SPEED100*/
end_comment

begin_define
define|#
directive|define
name|MDIO_CTRL1_SPEEDSEL
value|(MDIO_CTRL1_SPEEDSELEXT | 0x3c)
end_define

begin_define
define|#
directive|define
name|MDIO_AN_CTRL1_ENABLE
value|0x1000
end_define

begin_comment
comment|/* BMCR_AUTOEN */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTRL1_LPOWER
value|0x0800
end_define

begin_comment
comment|/* BMCR_PDOWN */
end_comment

begin_define
define|#
directive|define
name|MDIO_AN_CTRL1_RESTART
value|0x0200
end_define

begin_comment
comment|/* BMCR_STARTNEG */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTRL1_SPEED10G
value|(MDIO_CTRL1_SPEEDSELEXT | 0x00)
end_define

begin_define
define|#
directive|define
name|MDIO_STAT1
value|1
end_define

begin_comment
comment|/* MII_BMSR */
end_comment

begin_define
define|#
directive|define
name|MDIO_STAT1_LSTATUS
value|0x0004
end_define

begin_comment
comment|/* BMSR_LINK */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTRL2
value|0x07
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_CTRL2_10GBR
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_CTRL2_10GBX
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_CTRL2_TYPE
value|0x0003
end_define

begin_define
define|#
directive|define
name|MDIO_AN_ADVERTISE
value|16
end_define

begin_define
define|#
directive|define
name|MDIO_AN_LPA
value|19
end_define

begin_define
define|#
directive|define
name|ETH_ALEN
value|ETHER_ADDR_LEN
end_define

begin_define
define|#
directive|define
name|ETH_HLEN
value|ETHER_HDR_LEN
end_define

begin_define
define|#
directive|define
name|ETH_FCS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|VLAN_HLEN
value|ETHER_VLAN_ENCAP_LEN
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|nitems(x)
end_define

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|(sizeof(long) * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|BITS_TO_LONGS
parameter_list|(
name|n
parameter_list|)
value|howmany((n), BITS_PER_LONG)
end_define

begin_define
define|#
directive|define
name|NSEC_PER_SEC
value|1000000000ul
end_define

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|MIN((t)(a), (t)(b))
end_define

begin_define
define|#
directive|define
name|max_t
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|MAX((t)(a), (t)(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XGBE_OSDEP_H_ */
end_comment

end_unit

