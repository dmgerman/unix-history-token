begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)ascreg.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log:	scsi_53C94.h,v $  * Revision 2.4  91/02/05  17:44:59  mrt  * 	Added author notices  * 	[91/02/04  11:18:32  mrt]  *   * 	Changed to use new Mach copyright  * 	[91/02/02  12:17:11  mrt]  *   * Revision 2.3  90/12/05  23:34:46  af  * 	Documented max DMA xfer size.  * 	[90/12/03  23:39:36  af]  *   * Revision 2.1.1.1  90/11/01  03:38:54  af  * 	Created, from the DEC specs:  * 	"PMAZ-AA TURBOchannel SCSI Module Functional Specification"  * 	Workstation Systems Engineering, Palo Alto, CA. Aug 27, 1990.  * 	And from the NCR data sheets  * 	"NCR 53C94, 53C95, 53C96 Advanced SCSI Controller"  * 	[90/09/03            af]  */
end_comment

begin_comment
comment|/*  *	File: scsi_53C94.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	9/90  *  *	Defines for the NCR 53C94 ASC (SCSI interface)  * 	Some gotcha came from the "86C01/53C94 DMA lab work" written  * 	by Ken Stewart (NCR MED Logic Products Applications Engineer)  * 	courtesy of NCR.  Thanks Ken !  */
end_comment

begin_define
define|#
directive|define
name|ASC_OFFSET_53C94
value|0x0
end_define

begin_comment
comment|/* from module base */
end_comment

begin_define
define|#
directive|define
name|ASC_OFFSET_DMAR
value|0x40000
end_define

begin_comment
comment|/* DMA Address Register */
end_comment

begin_define
define|#
directive|define
name|ASC_OFFSET_RAM
value|0x80000
end_define

begin_comment
comment|/* SRAM Buffer */
end_comment

begin_define
define|#
directive|define
name|ASC_OFFSET_ROM
value|0xc0000
end_define

begin_comment
comment|/* Diagnostic ROM */
end_comment

begin_define
define|#
directive|define
name|ASC_RAM_SIZE
value|0x20000
end_define

begin_comment
comment|/* 128k (32k*32) */
end_comment

begin_define
define|#
directive|define
name|PER_TGT_DMA_SIZE
value|((ASC_RAM_SIZE/7)& ~(sizeof(int)-1))
end_define

begin_define
define|#
directive|define
name|ASC_NCMD
value|7
end_define

begin_comment
comment|/*  * DMA Address Register  */
end_comment

begin_define
define|#
directive|define
name|ASC_DMAR_MASK
value|0x1ffff
end_define

begin_comment
comment|/* 17 bits, 128k */
end_comment

begin_define
define|#
directive|define
name|ASC_DMAR_WRITE
value|0x80000000
end_define

begin_comment
comment|/* DMA direction bit */
end_comment

begin_define
define|#
directive|define
name|ASC_DMA_ADDR
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)& ASC_DMAR_MASK)
end_define

begin_comment
comment|/*  * Synch xfer parameters, and timing conversions  */
end_comment

begin_define
define|#
directive|define
name|SCSI_MIN_PERIOD
value|50
end_define

begin_comment
comment|/* in 4 nsecs units */
end_comment

begin_define
define|#
directive|define
name|ASC_MIN_PERIOD25
value|5
end_define

begin_comment
comment|/* in CLKS/BYTE, 1 CLK = 40nsecs */
end_comment

begin_define
define|#
directive|define
name|ASC_MIN_PERIOD12
value|3
end_define

begin_comment
comment|/* in CLKS/BYTE, 1 CLK = 80nsecs */
end_comment

begin_define
define|#
directive|define
name|ASC_MAX_PERIOD25
value|35
end_define

begin_comment
comment|/* in CLKS/BYTE, 1 CLK = 40nsecs */
end_comment

begin_define
define|#
directive|define
name|ASC_MAX_PERIOD12
value|18
end_define

begin_comment
comment|/* in CLKS/BYTE, 1 CLK = 80nsecs */
end_comment

begin_define
define|#
directive|define
name|ASC_MAX_OFFSET
value|15
end_define

begin_comment
comment|/* pure number */
end_comment

begin_comment
comment|/*  * Register map, padded as needed  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
struct|struct
block|{
name|u_char
name|asc_tc_lsb
decl_stmt|;
comment|/* rw: Transfer Counter LSB */
name|char
name|pad0
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_tc_msb
decl_stmt|;
comment|/* rw: Transfer Counter MSB */
name|char
name|pad1
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_fifo
decl_stmt|;
comment|/* rw: FIFO top */
name|char
name|pad2
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_cmd
decl_stmt|;
comment|/* rw: Command */
name|char
name|pad3
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_status
decl_stmt|;
comment|/* r:  Status */
define|#
directive|define
name|asc_dbus_id
value|asc_status
comment|/* w: Destination Bus ID */
name|char
name|pad4
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_intr
decl_stmt|;
comment|/* r:  Interrupt */
define|#
directive|define
name|asc_sel_timo
value|asc_intr
comment|/* w: (re)select timeout */
name|char
name|pad5
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_ss
decl_stmt|;
comment|/* r:  Sequence Step */
define|#
directive|define
name|asc_syn_p
value|asc_ss
comment|/* w: synchronous period */
name|char
name|pad6
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_flags
decl_stmt|;
comment|/* r:  FIFO flags + seq step */
define|#
directive|define
name|asc_syn_o
value|asc_flags
comment|/* w: synchronous offset */
name|char
name|pad7
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_cnfg1
decl_stmt|;
comment|/* rw: Configuration 1 */
name|char
name|pad8
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_ccf
decl_stmt|;
comment|/* w:  Clock Conv. Factor */
name|char
name|pad9
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_test
decl_stmt|;
comment|/* w:  Test Mode */
name|char
name|pad10
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_cnfg2
decl_stmt|;
comment|/* rw: Configuration 2 */
name|char
name|pad11
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_cnfg3
decl_stmt|;
comment|/* rw: Configuration 3 */
name|char
name|pad12
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|asc_res_fifo
decl_stmt|;
comment|/* w: Reserve FIFO byte */
block|}
name|asc_regmap_t
typedef|;
end_typedef

begin_comment
comment|/*  * Transfer Count: access macros  * That a NOP is required after loading the dma counter  * I learned on the NCR test code. Sic.  */
end_comment

begin_define
define|#
directive|define
name|ASC_TC_MAX
value|0x10000
end_define

begin_define
define|#
directive|define
name|ASC_TC_GET
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
define|\
value|val = (ptr)->asc_tc_lsb | ((ptr)->asc_tc_msb<< 8)
end_define

begin_define
define|#
directive|define
name|ASC_TC_PUT
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
define|\
value|(ptr)->asc_tc_lsb = (val);			\ 	(ptr)->asc_tc_msb = (val)>> 8;			\ 	(ptr)->asc_cmd = ASC_CMD_NOP | ASC_CMD_DMA;
end_define

begin_comment
comment|/*  * Command register (command codes)  */
end_comment

begin_define
define|#
directive|define
name|ASC_CMD_DMA
value|0x80
end_define

begin_comment
comment|/* Miscellaneous */
end_comment

begin_define
define|#
directive|define
name|ASC_CMD_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|ASC_CMD_FLUSH
value|0x01
end_define

begin_define
define|#
directive|define
name|ASC_CMD_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|ASC_CMD_BUS_RESET
value|0x03
end_define

begin_comment
comment|/* Initiator state */
end_comment

begin_define
define|#
directive|define
name|ASC_CMD_XFER_INFO
value|0x10
end_define

begin_define
define|#
directive|define
name|ASC_CMD_I_COMPLETE
value|0x11
end_define

begin_define
define|#
directive|define
name|ASC_CMD_MSG_ACPT
value|0x12
end_define

begin_define
define|#
directive|define
name|ASC_CMD_XFER_PAD
value|0x18
end_define

begin_define
define|#
directive|define
name|ASC_CMD_SET_ATN
value|0x1a
end_define

begin_define
define|#
directive|define
name|ASC_CMD_CLR_ATN
value|0x1b
end_define

begin_comment
comment|/* Target state */
end_comment

begin_define
define|#
directive|define
name|ASC_CMD_SND_MSG
value|0x20
end_define

begin_define
define|#
directive|define
name|ASC_CMD_SND_STATUS
value|0x21
end_define

begin_define
define|#
directive|define
name|ASC_CMD_SND_DATA
value|0x22
end_define

begin_define
define|#
directive|define
name|ASC_CMD_DISC_SEQ
value|0x23
end_define

begin_define
define|#
directive|define
name|ASC_CMD_TERM
value|0x24
end_define

begin_define
define|#
directive|define
name|ASC_CMD_T_COMPLETE
value|0x25
end_define

begin_define
define|#
directive|define
name|ASC_CMD_DISC
value|0x27
end_define

begin_define
define|#
directive|define
name|ASC_CMD_RCV_MSG
value|0x28
end_define

begin_define
define|#
directive|define
name|ASC_CMD_RCV_CDB
value|0x29
end_define

begin_define
define|#
directive|define
name|ASC_CMD_RCV_DATA
value|0x2a
end_define

begin_define
define|#
directive|define
name|ASC_CMD_RCV_CMD
value|0x2b
end_define

begin_define
define|#
directive|define
name|ASC_CMD_ABRT_DMA
value|0x04
end_define

begin_comment
comment|/* Disconnected state */
end_comment

begin_define
define|#
directive|define
name|ASC_CMD_RESELECT
value|0x40
end_define

begin_define
define|#
directive|define
name|ASC_CMD_SEL
value|0x41
end_define

begin_define
define|#
directive|define
name|ASC_CMD_SEL_ATN
value|0x42
end_define

begin_define
define|#
directive|define
name|ASC_CMD_SEL_ATN_STOP
value|0x43
end_define

begin_define
define|#
directive|define
name|ASC_CMD_ENABLE_SEL
value|0x44
end_define

begin_define
define|#
directive|define
name|ASC_CMD_DISABLE_SEL
value|0x45
end_define

begin_define
define|#
directive|define
name|ASC_CMD_SEL_ATN3
value|0x46
end_define

begin_comment
comment|/*  * Status register, and phase encoding  */
end_comment

begin_define
define|#
directive|define
name|ASC_CSR_INT
value|0x80
end_define

begin_define
define|#
directive|define
name|ASC_CSR_GE
value|0x40
end_define

begin_define
define|#
directive|define
name|ASC_CSR_PE
value|0x20
end_define

begin_define
define|#
directive|define
name|ASC_CSR_TC
value|0x10
end_define

begin_define
define|#
directive|define
name|ASC_CSR_VGC
value|0x08
end_define

begin_define
define|#
directive|define
name|ASC_CSR_MSG
value|0x04
end_define

begin_define
define|#
directive|define
name|ASC_CSR_CD
value|0x02
end_define

begin_define
define|#
directive|define
name|ASC_CSR_IO
value|0x01
end_define

begin_define
define|#
directive|define
name|ASC_PHASE
parameter_list|(
name|csr
parameter_list|)
value|((csr)& 0x7)
end_define

begin_define
define|#
directive|define
name|ASC_PHASE_DATAO
value|0x0
end_define

begin_define
define|#
directive|define
name|ASC_PHASE_DATAI
value|0x1
end_define

begin_define
define|#
directive|define
name|ASC_PHASE_COMMAND
value|0x2
end_define

begin_define
define|#
directive|define
name|ASC_PHASE_STATUS
value|0x3
end_define

begin_comment
comment|/* 4..5 ANSI reserved */
end_comment

begin_define
define|#
directive|define
name|ASC_PHASE_MSG_OUT
value|0x6
end_define

begin_define
define|#
directive|define
name|ASC_PHASE_MSG_IN
value|0x7
end_define

begin_comment
comment|/*  * Destination Bus ID  */
end_comment

begin_define
define|#
directive|define
name|ASC_DEST_ID_MASK
value|0x07
end_define

begin_comment
comment|/*  * Interrupt register  */
end_comment

begin_define
define|#
directive|define
name|ASC_INT_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|ASC_INT_ILL
value|0x40
end_define

begin_define
define|#
directive|define
name|ASC_INT_DISC
value|0x20
end_define

begin_define
define|#
directive|define
name|ASC_INT_BS
value|0x10
end_define

begin_define
define|#
directive|define
name|ASC_INT_FC
value|0x08
end_define

begin_define
define|#
directive|define
name|ASC_INT_RESEL
value|0x04
end_define

begin_define
define|#
directive|define
name|ASC_INT_SEL_ATN
value|0x02
end_define

begin_define
define|#
directive|define
name|ASC_INT_SEL
value|0x01
end_define

begin_comment
comment|/*  * Timeout register:  *  *	val = (timeout * CLK_freq) / (8192 * CCF);  */
end_comment

begin_define
define|#
directive|define
name|ASC_TIMEOUT_250
parameter_list|(
name|clk
parameter_list|,
name|ccf
parameter_list|)
value|(((clk) * 31) / (ccf))
end_define

begin_comment
comment|/*  * Sequence Step register  */
end_comment

begin_define
define|#
directive|define
name|ASC_SS_RESERVED
value|0xf0
end_define

begin_define
define|#
directive|define
name|ASC_SS_SOM
value|0x08
end_define

begin_define
define|#
directive|define
name|ASC_SS_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|ASC_SS
parameter_list|(
name|ss
parameter_list|)
value|((ss)& ASC_SS_MASK)
end_define

begin_comment
comment|/*  * Synchronous Transfer Period  */
end_comment

begin_define
define|#
directive|define
name|ASC_STP_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|ASC_STP_MIN
value|0x05
end_define

begin_comment
comment|/* 5 clk per byte */
end_comment

begin_define
define|#
directive|define
name|ASC_STP_MAX
value|0x04
end_define

begin_comment
comment|/* after ovfl, 35 clk/byte */
end_comment

begin_comment
comment|/*  * FIFO flags  */
end_comment

begin_define
define|#
directive|define
name|ASC_FLAGS_SEQ_STEP
value|0xe0
end_define

begin_define
define|#
directive|define
name|ASC_FLAGS_FIFO_CNT
value|0x1f
end_define

begin_comment
comment|/*  * Synchronous offset  */
end_comment

begin_define
define|#
directive|define
name|ASC_SYNO_MASK
value|0x0f
end_define

begin_comment
comment|/* 0 -> asyn */
end_comment

begin_comment
comment|/*  * Configuration 1  */
end_comment

begin_define
define|#
directive|define
name|ASC_CNFG1_SLOW
value|0x80
end_define

begin_define
define|#
directive|define
name|ASC_CNFG1_SRD
value|0x40
end_define

begin_define
define|#
directive|define
name|ASC_CNFG1_P_TEST
value|0x20
end_define

begin_define
define|#
directive|define
name|ASC_CNFG1_P_CHECK
value|0x10
end_define

begin_define
define|#
directive|define
name|ASC_CNFG1_TEST
value|0x08
end_define

begin_define
define|#
directive|define
name|ASC_CNFG1_MY_BUS_ID
value|0x07
end_define

begin_comment
comment|/*  * CCF register  */
end_comment

begin_define
define|#
directive|define
name|ASC_CCF
parameter_list|(
name|clk
parameter_list|)
value|((((clk) - 1) / 5) + 1)
end_define

begin_comment
comment|/*  * Test register  */
end_comment

begin_define
define|#
directive|define
name|ASC_TEST_XXXX
value|0xf8
end_define

begin_define
define|#
directive|define
name|ASC_TEST_HI_Z
value|0x04
end_define

begin_define
define|#
directive|define
name|ASC_TEST_I
value|0x02
end_define

begin_define
define|#
directive|define
name|ASC_TEST_T
value|0x01
end_define

begin_comment
comment|/*  * Configuration 2  */
end_comment

begin_define
define|#
directive|define
name|ASC_CNFG2_RFB
value|0x80
end_define

begin_define
define|#
directive|define
name|ASC_CNFG2_EPL
value|0x40
end_define

begin_define
define|#
directive|define
name|ASC_CNFG2_EBC
value|0x20
end_define

begin_define
define|#
directive|define
name|ASC_CNFG2_DREQ_HIZ
value|0x10
end_define

begin_define
define|#
directive|define
name|ASC_CNFG2_SCSI2
value|0x08
end_define

begin_define
define|#
directive|define
name|ASC_CNFG2_BPA
value|0x04
end_define

begin_define
define|#
directive|define
name|ASC_CNFG2_RPE
value|0x02
end_define

begin_define
define|#
directive|define
name|ASC_CNFG2_DPE
value|0x01
end_define

begin_comment
comment|/*  * Configuration 3  */
end_comment

begin_define
define|#
directive|define
name|ASC_CNFG3_RESERVED
value|0xf8
end_define

begin_define
define|#
directive|define
name|ASC_CNFG3_SRB
value|0x04
end_define

begin_define
define|#
directive|define
name|ASC_CNFG3_ALT_DMA
value|0x02
end_define

begin_define
define|#
directive|define
name|ASC_CNFG3_T8
value|0x01
end_define

end_unit

