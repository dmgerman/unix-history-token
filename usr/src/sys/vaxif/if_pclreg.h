begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_pclreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * DEC CSS PCL-11B Parallel Communications Interface  */
end_comment

begin_struct
struct|struct
name|pcldevice
block|{
name|u_short
name|pcl_tcr
decl_stmt|;
comment|/* Transmitter Command Register */
name|u_short
name|pcl_tsr
decl_stmt|;
comment|/* Transmitter Status Register */
name|u_short
name|pcl_tsdb
decl_stmt|;
comment|/* Transmitter Source Data Buffer */
name|short
name|pcl_tsbc
decl_stmt|;
comment|/* Transmitter Source Byte Count */
name|u_short
name|pcl_tsba
decl_stmt|;
comment|/* Transmitter Source Bus Address */
name|u_short
name|pcl_tmmr
decl_stmt|;
comment|/* Transmitter Master/Maint Regs */
name|u_short
name|pcl_tscrc
decl_stmt|;
comment|/* Transmitter Source CRC */
name|u_short
name|pcl_spare
decl_stmt|;
name|u_short
name|pcl_rcr
decl_stmt|;
comment|/* Receiver Command Register */
name|u_short
name|pcl_rsr
decl_stmt|;
comment|/* Receiver Status Register */
name|u_short
name|pcl_rddb
decl_stmt|;
comment|/* Receiver Destination Data Buffer */
name|short
name|pcl_rdbc
decl_stmt|;
comment|/* Receiver Destination Byte Count */
name|u_short
name|pcl_rdba
decl_stmt|;
comment|/* Receiver Destination Bus Address */
name|u_short
name|pcl_rdcrc
decl_stmt|;
comment|/* Receiver Destination CRC */
block|}
struct|;
end_struct

begin_comment
comment|/* Transmitter Command and Status Bits */
end_comment

begin_define
define|#
directive|define
name|PCL_STTXM
value|(1<<0)
end_define

begin_comment
comment|/* Start transmission */
end_comment

begin_define
define|#
directive|define
name|PCL_TXINIT
value|(1<<1)
end_define

begin_comment
comment|/* Transmitter Initialize */
end_comment

begin_define
define|#
directive|define
name|PCL_IE
value|(1<<6)
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|PCL_SNDWD
value|(1<<13)
end_define

begin_comment
comment|/* Send word */
end_comment

begin_define
define|#
directive|define
name|PCL_TXNPR
value|(1<<14)
end_define

begin_comment
comment|/* Transmitter NPR */
end_comment

begin_define
define|#
directive|define
name|PCL_RIB
value|(1<<15)
end_define

begin_comment
comment|/* Retry if busy */
end_comment

begin_define
define|#
directive|define
name|PCL_RESPA
value|(3<<0)
end_define

begin_comment
comment|/* Response A bits (tsr& rsr) */
end_comment

begin_define
define|#
directive|define
name|PCL_RESPB
value|(3<<2)
end_define

begin_comment
comment|/* Response B bits (tsr& rsr) */
end_comment

begin_define
define|#
directive|define
name|PCL_MSTDWN
value|(1<<11)
end_define

begin_comment
comment|/* Master down */
end_comment

begin_define
define|#
directive|define
name|PCL_ERR
value|(1<<15)
end_define

begin_comment
comment|/* Error summary */
end_comment

begin_define
define|#
directive|define
name|PCL_MASTER
value|(1<<8)
end_define

begin_comment
comment|/* Set MASTER status */
end_comment

begin_define
define|#
directive|define
name|PCL_AUTOADDR
value|(1<<12)
end_define

begin_comment
comment|/* Auto time slicing */
end_comment

begin_comment
comment|/* Receiver Command and Status Bits */
end_comment

begin_define
define|#
directive|define
name|PCL_RCVDAT
value|(1<<0)
end_define

begin_comment
comment|/* Receive data */
end_comment

begin_define
define|#
directive|define
name|PCL_RCINIT
value|(1<<1)
end_define

begin_comment
comment|/* Receiver Initialize */
end_comment

begin_define
define|#
directive|define
name|PCL_RCVWD
value|(1<<13)
end_define

begin_comment
comment|/* Receive word */
end_comment

begin_define
define|#
directive|define
name|PCL_RCNPR
value|(1<<14)
end_define

begin_comment
comment|/* Receive NRP */
end_comment

begin_define
define|#
directive|define
name|PCL_REJ
value|(1<<15)
end_define

begin_comment
comment|/* Reject transmission */
end_comment

begin_define
define|#
directive|define
name|PCL_BCOFL
value|(1<<9)
end_define

begin_comment
comment|/* Byte Counter Overflow */
end_comment

begin_define
define|#
directive|define
name|PCL_TERRBITS
value|"\20\20ERR\17NXL\16MEM_OFL\15TXM_ERR\14MST_DWN\13TIM_OUT\12OVERRUN\11DTI_RDY\10SUC_TXF\07BUSY\06SOREJ\05TBS_BUSY"
end_define

begin_define
define|#
directive|define
name|PCL_TCSRBITS
value|"\20\20RIB\17TX_NPR\16SND_WD\10RD_SILO\07IE\04DTO_RDY\03INH_ADI\02TX_INIT\01START_TXM"
end_define

begin_define
define|#
directive|define
name|PCL_RERRBITS
value|"\20\20ERR\17NXL\16MEM_OFL\15TXM_ERR\14PARITY\13TIM_OUT\12BC_OFL\11DTO_RDY\10SUC_TXF\07BUSY\06REJ_COMP\05CHN_OPN"
end_define

begin_define
define|#
directive|define
name|PCL_RCSRBITS
value|"\20\20REJ\17RC_NPR\16RCV_WD\10LD_SILO\07IE\04DTI_RDY\03INH_ADI\02RC_INIT\01RCV_DAT"
end_define

end_unit

