begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DEFINED
end_ifdef

begin_include
include|#
directive|include
file|<cxgb_include.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dev/cxgb/cxgb_include.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Marvell PHY interrupt status bits. */
end_comment

begin_define
define|#
directive|define
name|MV_INTR_JABBER
value|0x0001
end_define

begin_define
define|#
directive|define
name|MV_INTR_POLARITY_CHNG
value|0x0002
end_define

begin_define
define|#
directive|define
name|MV_INTR_ENG_DETECT_CHNG
value|0x0010
end_define

begin_define
define|#
directive|define
name|MV_INTR_DOWNSHIFT
value|0x0020
end_define

begin_define
define|#
directive|define
name|MV_INTR_MDI_XOVER_CHNG
value|0x0040
end_define

begin_define
define|#
directive|define
name|MV_INTR_FIFO_OVER_UNDER
value|0x0080
end_define

begin_define
define|#
directive|define
name|MV_INTR_FALSE_CARRIER
value|0x0100
end_define

begin_define
define|#
directive|define
name|MV_INTR_SYMBOL_ERROR
value|0x0200
end_define

begin_define
define|#
directive|define
name|MV_INTR_LINK_CHNG
value|0x0400
end_define

begin_define
define|#
directive|define
name|MV_INTR_AUTONEG_DONE
value|0x0800
end_define

begin_define
define|#
directive|define
name|MV_INTR_PAGE_RECV
value|0x1000
end_define

begin_define
define|#
directive|define
name|MV_INTR_DUPLEX_CHNG
value|0x2000
end_define

begin_define
define|#
directive|define
name|MV_INTR_SPEED_CHNG
value|0x4000
end_define

begin_define
define|#
directive|define
name|MV_INTR_AUTONEG_ERR
value|0x8000
end_define

begin_comment
comment|/* Marvell PHY specific registers. */
end_comment

begin_define
define|#
directive|define
name|MV88E1XXX_SPECIFIC_CNTRL
value|16
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_SPECIFIC_STATUS
value|17
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_INTR_ENABLE
value|18
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_INTR_STATUS
value|19
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_EXT_SPECIFIC_CNTRL
value|20
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_RECV_ERR
value|21
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_EXT_ADDR
value|22
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_GLOBAL_STATUS
value|23
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_LED_CNTRL
value|24
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_LED_OVERRIDE
value|25
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_EXT_SPECIFIC_CNTRL2
value|26
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_EXT_SPECIFIC_STATUS
value|27
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_VIRTUAL_CABLE_TESTER
value|28
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_EXTENDED_ADDR
value|29
end_define

begin_define
define|#
directive|define
name|MV88E1XXX_EXTENDED_DATA
value|30
end_define

begin_comment
comment|/* PHY specific control register fields */
end_comment

begin_define
define|#
directive|define
name|S_PSCR_MDI_XOVER_MODE
value|5
end_define

begin_define
define|#
directive|define
name|M_PSCR_MDI_XOVER_MODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_PSCR_MDI_XOVER_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PSCR_MDI_XOVER_MODE)
end_define

begin_comment
comment|/* Extended PHY specific control register fields */
end_comment

begin_define
define|#
directive|define
name|S_DOWNSHIFT_ENABLE
value|8
end_define

begin_define
define|#
directive|define
name|V_DOWNSHIFT_ENABLE
value|(1<< S_DOWNSHIFT_ENABLE)
end_define

begin_define
define|#
directive|define
name|S_DOWNSHIFT_CNT
value|9
end_define

begin_define
define|#
directive|define
name|M_DOWNSHIFT_CNT
value|0x7
end_define

begin_define
define|#
directive|define
name|V_DOWNSHIFT_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DOWNSHIFT_CNT)
end_define

begin_comment
comment|/* PHY specific status register fields */
end_comment

begin_define
define|#
directive|define
name|S_PSSR_JABBER
value|0
end_define

begin_define
define|#
directive|define
name|V_PSSR_JABBER
value|(1<< S_PSSR_JABBER)
end_define

begin_define
define|#
directive|define
name|S_PSSR_POLARITY
value|1
end_define

begin_define
define|#
directive|define
name|V_PSSR_POLARITY
value|(1<< S_PSSR_POLARITY)
end_define

begin_define
define|#
directive|define
name|S_PSSR_RX_PAUSE
value|2
end_define

begin_define
define|#
directive|define
name|V_PSSR_RX_PAUSE
value|(1<< S_PSSR_RX_PAUSE)
end_define

begin_define
define|#
directive|define
name|S_PSSR_TX_PAUSE
value|3
end_define

begin_define
define|#
directive|define
name|V_PSSR_TX_PAUSE
value|(1<< S_PSSR_TX_PAUSE)
end_define

begin_define
define|#
directive|define
name|S_PSSR_ENERGY_DETECT
value|4
end_define

begin_define
define|#
directive|define
name|V_PSSR_ENERGY_DETECT
value|(1<< S_PSSR_ENERGY_DETECT)
end_define

begin_define
define|#
directive|define
name|S_PSSR_DOWNSHIFT_STATUS
value|5
end_define

begin_define
define|#
directive|define
name|V_PSSR_DOWNSHIFT_STATUS
value|(1<< S_PSSR_DOWNSHIFT_STATUS)
end_define

begin_define
define|#
directive|define
name|S_PSSR_MDI
value|6
end_define

begin_define
define|#
directive|define
name|V_PSSR_MDI
value|(1<< S_PSSR_MDI)
end_define

begin_define
define|#
directive|define
name|S_PSSR_CABLE_LEN
value|7
end_define

begin_define
define|#
directive|define
name|M_PSSR_CABLE_LEN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_PSSR_CABLE_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PSSR_CABLE_LEN)
end_define

begin_define
define|#
directive|define
name|G_PSSR_CABLE_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PSSR_CABLE_LEN)& M_PSSR_CABLE_LEN)
end_define

begin_define
define|#
directive|define
name|S_PSSR_LINK
value|10
end_define

begin_define
define|#
directive|define
name|V_PSSR_LINK
value|(1<< S_PSSR_LINK)
end_define

begin_define
define|#
directive|define
name|S_PSSR_STATUS_RESOLVED
value|11
end_define

begin_define
define|#
directive|define
name|V_PSSR_STATUS_RESOLVED
value|(1<< S_PSSR_STATUS_RESOLVED)
end_define

begin_define
define|#
directive|define
name|S_PSSR_PAGE_RECEIVED
value|12
end_define

begin_define
define|#
directive|define
name|V_PSSR_PAGE_RECEIVED
value|(1<< S_PSSR_PAGE_RECEIVED)
end_define

begin_define
define|#
directive|define
name|S_PSSR_DUPLEX
value|13
end_define

begin_define
define|#
directive|define
name|V_PSSR_DUPLEX
value|(1<< S_PSSR_DUPLEX)
end_define

begin_define
define|#
directive|define
name|S_PSSR_SPEED
value|14
end_define

begin_define
define|#
directive|define
name|M_PSSR_SPEED
value|0x3
end_define

begin_define
define|#
directive|define
name|V_PSSR_SPEED
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PSSR_SPEED)
end_define

begin_define
define|#
directive|define
name|G_PSSR_SPEED
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PSSR_SPEED)& M_PSSR_SPEED)
end_define

begin_comment
comment|/* MV88E1XXX MDI crossover register values */
end_comment

begin_define
define|#
directive|define
name|CROSSOVER_MDI
value|0
end_define

begin_define
define|#
directive|define
name|CROSSOVER_MDIX
value|1
end_define

begin_define
define|#
directive|define
name|CROSSOVER_AUTO
value|3
end_define

begin_define
define|#
directive|define
name|INTR_ENABLE_MASK
value|(MV_INTR_SPEED_CHNG | MV_INTR_DUPLEX_CHNG | \ 	MV_INTR_AUTONEG_DONE | MV_INTR_LINK_CHNG | MV_INTR_FIFO_OVER_UNDER | \ 	MV_INTR_ENG_DETECT_CHNG)
end_define

begin_comment
comment|/*  * Reset the PHY.  If 'wait' is set wait until the reset completes.  */
end_comment

begin_function
specifier|static
name|int
name|mv88e1xxx_reset
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|,
name|int
name|wait
parameter_list|)
block|{
return|return
name|t3_phy_reset
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|wait
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_intr_enable
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|)
block|{
return|return
name|mdio_write
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_INTR_ENABLE
argument_list|,
name|INTR_ENABLE_MASK
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_intr_disable
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|)
block|{
return|return
name|mdio_write
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_INTR_ENABLE
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_intr_clear
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|)
block|{
name|u32
name|val
decl_stmt|;
comment|/* Clear PHY interrupts by reading the register. */
return|return
name|mdio_read
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_INTR_STATUS
argument_list|,
operator|&
name|val
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_crossover_set
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|,
name|int
name|crossover
parameter_list|)
block|{
return|return
name|t3_mdio_change_bits
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_SPECIFIC_CNTRL
argument_list|,
name|V_PSCR_MDI_XOVER_MODE
argument_list|(
name|M_PSCR_MDI_XOVER_MODE
argument_list|)
argument_list|,
name|V_PSCR_MDI_XOVER_MODE
argument_list|(
name|crossover
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_autoneg_enable
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|)
block|{
name|mv88e1xxx_crossover_set
argument_list|(
name|cphy
argument_list|,
name|CROSSOVER_AUTO
argument_list|)
expr_stmt|;
comment|/* restart autoneg for change to take effect */
return|return
name|t3_mdio_change_bits
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MII_BMCR
argument_list|,
name|BMCR_PDOWN
operator||
name|BMCR_ISOLATE
argument_list|,
name|BMCR_ANENABLE
operator||
name|BMCR_ANRESTART
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_autoneg_restart
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|)
block|{
return|return
name|t3_mdio_change_bits
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MII_BMCR
argument_list|,
name|BMCR_PDOWN
operator||
name|BMCR_ISOLATE
argument_list|,
name|BMCR_ANRESTART
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_set_loopback
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|,
name|int
name|mmd
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|on
parameter_list|)
block|{
return|return
name|t3_mdio_change_bits
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MII_BMCR
argument_list|,
name|BMCR_LOOPBACK
argument_list|,
name|on
condition|?
name|BMCR_LOOPBACK
else|:
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_get_link_status
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|,
name|int
modifier|*
name|link_ok
parameter_list|,
name|int
modifier|*
name|speed
parameter_list|,
name|int
modifier|*
name|duplex
parameter_list|,
name|int
modifier|*
name|fc
parameter_list|)
block|{
name|u32
name|status
decl_stmt|;
name|int
name|sp
init|=
operator|-
literal|1
decl_stmt|,
name|dplx
init|=
operator|-
literal|1
decl_stmt|,
name|pause
init|=
literal|0
decl_stmt|;
name|mdio_read
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_SPECIFIC_STATUS
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|status
operator|&
name|V_PSSR_STATUS_RESOLVED
operator|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|status
operator|&
name|V_PSSR_RX_PAUSE
condition|)
name|pause
operator||=
name|PAUSE_RX
expr_stmt|;
if|if
condition|(
name|status
operator|&
name|V_PSSR_TX_PAUSE
condition|)
name|pause
operator||=
name|PAUSE_TX
expr_stmt|;
name|dplx
operator|=
operator|(
name|status
operator|&
name|V_PSSR_DUPLEX
operator|)
condition|?
name|DUPLEX_FULL
else|:
name|DUPLEX_HALF
expr_stmt|;
name|sp
operator|=
name|G_PSSR_SPEED
argument_list|(
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|==
literal|0
condition|)
name|sp
operator|=
name|SPEED_10
expr_stmt|;
elseif|else
if|if
condition|(
name|sp
operator|==
literal|1
condition|)
name|sp
operator|=
name|SPEED_100
expr_stmt|;
else|else
name|sp
operator|=
name|SPEED_1000
expr_stmt|;
block|}
if|if
condition|(
name|link_ok
condition|)
operator|*
name|link_ok
operator|=
operator|(
name|status
operator|&
name|V_PSSR_LINK
operator|)
operator|!=
literal|0
expr_stmt|;
if|if
condition|(
name|speed
condition|)
operator|*
name|speed
operator|=
name|sp
expr_stmt|;
if|if
condition|(
name|duplex
condition|)
operator|*
name|duplex
operator|=
name|dplx
expr_stmt|;
if|if
condition|(
name|fc
condition|)
operator|*
name|fc
operator|=
name|pause
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_downshift_set
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|,
name|int
name|downshift_enable
parameter_list|)
block|{
comment|/* 	 * Set the downshift counter to 2 so we try to establish Gb link 	 * twice before downshifting. 	 */
return|return
name|t3_mdio_change_bits
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_EXT_SPECIFIC_CNTRL
argument_list|,
name|V_DOWNSHIFT_ENABLE
operator||
name|V_DOWNSHIFT_CNT
argument_list|(
name|M_DOWNSHIFT_CNT
argument_list|)
argument_list|,
name|downshift_enable
condition|?
name|V_DOWNSHIFT_ENABLE
operator||
name|V_DOWNSHIFT_CNT
argument_list|(
literal|2
argument_list|)
else|:
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_power_down
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|,
name|int
name|enable
parameter_list|)
block|{
return|return
name|t3_mdio_change_bits
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MII_BMCR
argument_list|,
name|BMCR_PDOWN
argument_list|,
name|enable
condition|?
name|BMCR_PDOWN
else|:
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|mv88e1xxx_intr_handler
parameter_list|(
name|struct
name|cphy
modifier|*
name|cphy
parameter_list|)
block|{
specifier|const
name|u32
name|link_change_intrs
init|=
name|MV_INTR_LINK_CHNG
operator||
name|MV_INTR_AUTONEG_DONE
operator||
name|MV_INTR_DUPLEX_CHNG
operator||
name|MV_INTR_SPEED_CHNG
operator||
name|MV_INTR_DOWNSHIFT
decl_stmt|;
name|u32
name|cause
decl_stmt|;
name|int
name|cphy_cause
init|=
literal|0
decl_stmt|;
name|mdio_read
argument_list|(
name|cphy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_INTR_STATUS
argument_list|,
operator|&
name|cause
argument_list|)
expr_stmt|;
name|cause
operator|&=
name|INTR_ENABLE_MASK
expr_stmt|;
if|if
condition|(
name|cause
operator|&
name|link_change_intrs
condition|)
name|cphy_cause
operator||=
name|cphy_cause_link_change
expr_stmt|;
if|if
condition|(
name|cause
operator|&
name|MV_INTR_FIFO_OVER_UNDER
condition|)
name|cphy_cause
operator||=
name|cphy_cause_fifo_error
expr_stmt|;
return|return
name|cphy_cause
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|C99_NOT_SUPPORTED
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|cphy_ops
name|mv88e1xxx_ops
init|=
block|{
name|NULL
block|,
name|mv88e1xxx_reset
block|,
name|mv88e1xxx_intr_enable
block|,
name|mv88e1xxx_intr_disable
block|,
name|mv88e1xxx_intr_clear
block|,
name|mv88e1xxx_intr_handler
block|,
name|mv88e1xxx_autoneg_enable
block|,
name|mv88e1xxx_autoneg_restart
block|,
name|t3_phy_advertise
block|,
name|mv88e1xxx_set_loopback
block|,
name|t3_set_phy_speed_duplex
block|,
name|mv88e1xxx_get_link_status
block|,
name|mv88e1xxx_power_down
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|struct
name|cphy_ops
name|mv88e1xxx_ops
init|=
block|{
operator|.
name|reset
operator|=
name|mv88e1xxx_reset
block|,
operator|.
name|intr_enable
operator|=
name|mv88e1xxx_intr_enable
block|,
operator|.
name|intr_disable
operator|=
name|mv88e1xxx_intr_disable
block|,
operator|.
name|intr_clear
operator|=
name|mv88e1xxx_intr_clear
block|,
operator|.
name|intr_handler
operator|=
name|mv88e1xxx_intr_handler
block|,
operator|.
name|autoneg_enable
operator|=
name|mv88e1xxx_autoneg_enable
block|,
operator|.
name|autoneg_restart
operator|=
name|mv88e1xxx_autoneg_restart
block|,
operator|.
name|advertise
operator|=
name|t3_phy_advertise
block|,
operator|.
name|set_loopback
operator|=
name|mv88e1xxx_set_loopback
block|,
operator|.
name|set_speed_duplex
operator|=
name|t3_set_phy_speed_duplex
block|,
operator|.
name|get_link_status
operator|=
name|mv88e1xxx_get_link_status
block|,
operator|.
name|power_down
operator|=
name|mv88e1xxx_power_down
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|t3_mv88e1xxx_phy_prep
parameter_list|(
name|struct
name|cphy
modifier|*
name|phy
parameter_list|,
name|adapter_t
modifier|*
name|adapter
parameter_list|,
name|int
name|phy_addr
parameter_list|,
specifier|const
name|struct
name|mdio_ops
modifier|*
name|mdio_ops
parameter_list|)
block|{
name|cphy_init
argument_list|(
name|phy
argument_list|,
name|adapter
argument_list|,
name|phy_addr
argument_list|,
operator|&
name|mv88e1xxx_ops
argument_list|,
name|mdio_ops
argument_list|)
expr_stmt|;
comment|/* Configure copper PHY transmitter as class A to reduce EMI. */
name|mdio_write
argument_list|(
name|phy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_EXTENDED_ADDR
argument_list|,
literal|0xb
argument_list|)
expr_stmt|;
name|mdio_write
argument_list|(
name|phy
argument_list|,
literal|0
argument_list|,
name|MV88E1XXX_EXTENDED_DATA
argument_list|,
literal|0x8004
argument_list|)
expr_stmt|;
name|mv88e1xxx_downshift_set
argument_list|(
name|phy
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Enable downshift */
block|}
end_function

end_unit

