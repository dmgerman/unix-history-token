begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACB_REG_H
end_ifndef

begin_define
define|#
directive|define
name|MACB_REG_H
end_define

begin_define
define|#
directive|define
name|EMAC_NCR
value|0x00
end_define

begin_define
define|#
directive|define
name|EMAC_NCFGR
value|0x04
end_define

begin_define
define|#
directive|define
name|EMAC_TSR
value|0x14
end_define

begin_define
define|#
directive|define
name|EMAC_RSR
value|0x20
end_define

begin_define
define|#
directive|define
name|EMAC_ISR
value|0x24
end_define

begin_define
define|#
directive|define
name|EMAC_IER
value|0x28
end_define

begin_define
define|#
directive|define
name|EMAC_IDR
value|0x2C
end_define

begin_define
define|#
directive|define
name|EMAC_IMR
value|0x30
end_define

begin_define
define|#
directive|define
name|EMAC_RBQP
value|0x18
end_define

begin_define
define|#
directive|define
name|EMAC_TBQP
value|0x1C
end_define

begin_define
define|#
directive|define
name|EMAC_HRB
value|0x90
end_define

begin_define
define|#
directive|define
name|EMAC_HRT
value|0x94
end_define

begin_define
define|#
directive|define
name|EMAC_SA1B
value|0x98
end_define

begin_define
define|#
directive|define
name|EMAC_SA1T
value|0x9C
end_define

begin_define
define|#
directive|define
name|EMAC_USRIO
value|0xC0
end_define

begin_define
define|#
directive|define
name|EMAC_MAN
value|0x34
end_define

begin_comment
comment|/* EMAC PHY Maintenance Register */
end_comment

begin_define
define|#
directive|define
name|EMAC_SR
value|0x08
end_define

begin_comment
comment|/* EMAC STatus Register */
end_comment

begin_define
define|#
directive|define
name|EMAC_SR_LINK
value|(1U<< 0)
end_define

begin_comment
comment|/* Reserved! */
end_comment

begin_define
define|#
directive|define
name|EMAC_SR_MDIO
value|(1U<< 1)
end_define

begin_comment
comment|/* MDIO pin status */
end_comment

begin_define
define|#
directive|define
name|EMAC_SR_IDLE
value|(1U<< 2)
end_define

begin_comment
comment|/* IDLE (PHY logic) */
end_comment

begin_define
define|#
directive|define
name|RX_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TX_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MPE_ENABLE
value|(1<< 4)
end_define

begin_comment
comment|/* EMAC_MAN */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAN_BITS
value|0x40020000
end_define

begin_comment
comment|/* HIGH and CODE bits */
end_comment

begin_define
define|#
directive|define
name|EMAC_MAN_READ
value|(2U<< 28)
end_define

begin_define
define|#
directive|define
name|EMAC_MAN_WRITE
value|(1U<< 28)
end_define

begin_define
define|#
directive|define
name|EMAC_MAN_PHYA_BIT
value|23
end_define

begin_define
define|#
directive|define
name|EMAC_MAN_REGA_BIT
value|18
end_define

begin_define
define|#
directive|define
name|EMAC_MAN_VALUE_MASK
value|0xffffU
end_define

begin_define
define|#
directive|define
name|EMAC_MAN_REG_WR
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(EMAC_MAN_BITS | EMAC_MAN_WRITE | ((phy)<< EMAC_MAN_PHYA_BIT) | \ 		((reg)<< EMAC_MAN_REGA_BIT) | ((val)& EMAC_MAN_VALUE_MASK))
end_define

begin_define
define|#
directive|define
name|EMAC_MAN_REG_RD
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|)
define|\
value|(EMAC_MAN_BITS | EMAC_MAN_READ | ((phy)<< EMAC_MAN_PHYA_BIT) | \ 		((reg)<< EMAC_MAN_REGA_BIT))
end_define

begin_define
define|#
directive|define
name|RCOMP_INTERRUPT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RXUBR_INTERRUPT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TUBR_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TUND_INTERRUPT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RLE_INTERRUPT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|TXERR_INTERRUPT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ROVR_INTERRUPT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HRESP_INTERRUPT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|TCOMP_INTERRUPT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CLEAR_STAT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|TRANSMIT_START
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|TRANSMIT_STOP
value|(1<< 10)
end_define

begin_comment
comment|/*Transmit status register flags*/
end_comment

begin_define
define|#
directive|define
name|TSR_UND
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|TSR_COMP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|TSR_BEX
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TSR_TGO
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TSR_RLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TSR_COL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TSR_UBR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CFG_SPD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CFG_FD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CFG_CAF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CFG_NBC
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CFG_MTI
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|CFG_UNI
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CFG_BIG
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CFG_CLK_8
value|(0)
end_define

begin_define
define|#
directive|define
name|CFG_CLK_16
value|(1)
end_define

begin_define
define|#
directive|define
name|CFG_CLK_32
value|(2)
end_define

begin_define
define|#
directive|define
name|CFG_CLK_64
value|(3)
end_define

begin_define
define|#
directive|define
name|CFG_PAE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|CFG_RBOF_0
value|(0<< 14)
end_define

begin_define
define|#
directive|define
name|CFG_RBOF_1
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|CFG_RBOF_2
value|(2<< 14)
end_define

begin_define
define|#
directive|define
name|CFG_RBOF_3
value|(3<< 14)
end_define

begin_define
define|#
directive|define
name|CFG_DRFCS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|USRIO_CLOCK
value|(1<< 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

