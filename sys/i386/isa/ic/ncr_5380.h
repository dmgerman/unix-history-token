begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IC_NCR_5380_H_
end_ifndef

begin_define
define|#
directive|define
name|_IC_NCR_5380_H_
end_define

begin_comment
comment|/*  * Register map  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|u_char
name|sci_data
decl_stmt|;
comment|/* r: Current data */
define|#
directive|define
name|sci_odata
value|sci_data
comment|/* w: Out data */
specifier|volatile
name|u_char
name|sci_icmd
decl_stmt|;
comment|/* rw:Initiator command */
specifier|volatile
name|u_char
name|sci_mode
decl_stmt|;
comment|/* rw:Mode */
specifier|volatile
name|u_char
name|sci_tcmd
decl_stmt|;
comment|/* rw:Target command */
specifier|volatile
name|u_char
name|sci_bus_csr
decl_stmt|;
comment|/* r: Bus Status */
define|#
directive|define
name|sci_sel_enb
value|sci_bus_csr
comment|/* w: Select enable */
specifier|volatile
name|u_char
name|sci_csr
decl_stmt|;
comment|/* r: Status */
define|#
directive|define
name|sci_dma_send
value|sci_csr
comment|/* w: Start dma send data */
specifier|volatile
name|u_char
name|sci_idata
decl_stmt|;
comment|/* r: Input data */
define|#
directive|define
name|sci_trecv
value|sci_idata
comment|/* w: Start dma recv, target */
specifier|volatile
name|u_char
name|sci_iack
decl_stmt|;
comment|/* r: Interrupt Acknowledge  */
define|#
directive|define
name|sci_irecv
value|sci_iack
comment|/* w: Start dma recv, initiator */
block|}
name|sci_regmap_t
typedef|;
end_typedef

begin_comment
comment|/*  * Initiator command register  */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_DATA
value|0x01
end_define

begin_comment
comment|/* rw:Assert data bus   */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_ATN
value|0x02
end_define

begin_comment
comment|/* rw:Assert ATN signal */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_SEL
value|0x04
end_define

begin_comment
comment|/* rw:Assert SEL signal */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_BSY
value|0x08
end_define

begin_comment
comment|/* rw:Assert BSY signal */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_ACK
value|0x10
end_define

begin_comment
comment|/* rw:Assert ACK signal */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_LST
value|0x20
end_define

begin_comment
comment|/* r: Lost arbitration */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_DIFF
value|SCI_ICMD_LST
end_define

begin_comment
comment|/* w: Differential cable */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_AIP
value|0x40
end_define

begin_comment
comment|/* r: Arbitration in progress */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_TEST
value|SCI_ICMD_AIP
end_define

begin_comment
comment|/* w: Test mode */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_RST
value|0x80
end_define

begin_comment
comment|/* rw:Assert RST signal */
end_comment

begin_comment
comment|/*  * Mode register  */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_ARB
value|0x01
end_define

begin_comment
comment|/* rw: Start arbitration */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_DMA
value|0x02
end_define

begin_comment
comment|/* rw: Enable DMA xfers */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_MONBSY
value|0x04
end_define

begin_comment
comment|/* rw: Monitor BSY signal */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_DMA_IE
value|0x08
end_define

begin_comment
comment|/* rw: Enable DMA complete interrupt */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_PERR_IE
value|0x10
end_define

begin_comment
comment|/* rw: Interrupt on parity errors */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_PAR_CHK
value|0x20
end_define

begin_comment
comment|/* rw: Check parity */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_TARGET
value|0x40
end_define

begin_comment
comment|/* rw: Target mode (Initiator if 0) */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_BLOCKDMA
value|0x80
end_define

begin_comment
comment|/* rw: Block-mode DMA handshake (MBZ) */
end_comment

begin_comment
comment|/*  * Target command register  */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_IO
value|0x01
end_define

begin_comment
comment|/* rw: Assert I/O signal */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_CD
value|0x02
end_define

begin_comment
comment|/* rw: Assert C/D signal */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_MSG
value|0x04
end_define

begin_comment
comment|/* rw: Assert MSG signal */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_PHASE_MASK
value|0x07
end_define

begin_comment
comment|/* r:  Mask for current bus phase */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_REQ
value|0x08
end_define

begin_comment
comment|/* rw: Assert REQ signal */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_LAST_SENT
value|0x80
end_define

begin_comment
comment|/* ro: Last byte was xferred 					 *     (not on 5380/1) */
end_comment

begin_define
define|#
directive|define
name|SCI_PHASE
parameter_list|(
name|x
parameter_list|)
value|SCSI_PHASE(x)
end_define

begin_comment
comment|/*  * Current (SCSI) Bus status  */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_DBP
value|0x01
end_define

begin_comment
comment|/* r:  Data Bus parity */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_SEL
value|0x02
end_define

begin_comment
comment|/* r:  SEL signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_IO
value|0x04
end_define

begin_comment
comment|/* r:  I/O signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_CD
value|0x08
end_define

begin_comment
comment|/* r:  C/D signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_MSG
value|0x10
end_define

begin_comment
comment|/* r:  MSG signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_REQ
value|0x20
end_define

begin_comment
comment|/* r:  REQ signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_BSY
value|0x40
end_define

begin_comment
comment|/* r:  BSY signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_RST
value|0x80
end_define

begin_comment
comment|/* r:  RST signal */
end_comment

begin_define
define|#
directive|define
name|SCI_CUR_PHASE
parameter_list|(
name|x
parameter_list|)
value|SCSI_PHASE((x)>>2)
end_define

begin_comment
comment|/*  * Bus and Status register  */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_ACK
value|0x01
end_define

begin_comment
comment|/* r:  ACK signal */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_ATN
value|0x02
end_define

begin_comment
comment|/* r:  ATN signal */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_DISC
value|0x04
end_define

begin_comment
comment|/* r:  Disconnected (BSY==0) */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_PHASE_MATCH
value|0x08
end_define

begin_comment
comment|/* r:  Bus and SCI_TCMD match */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_INT
value|0x10
end_define

begin_comment
comment|/* r:  Interrupt request */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_PERR
value|0x20
end_define

begin_comment
comment|/* r:  Parity error */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_DREQ
value|0x40
end_define

begin_comment
comment|/* r:  DMA request */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_DONE
value|0x80
end_define

begin_comment
comment|/* r:  DMA count is zero */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IC_NCR_5380_H_ */
end_comment

end_unit

