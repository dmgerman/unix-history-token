begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)zsvar.h	7.2 (Berkeley) %G%  *  * from: $Header: zsvar.h,v 1.4 92/06/17 05:35:54 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Software state, per zs channel.  *  * The receive ring size and type are carefully chosen to make the  * zs hardware interrupt handler go fast.  We need 8 bits for the  * received character and 8 bits for the corresponding RR1 status.  * The character is known to be in the upper byte of the pair.  */
end_comment

begin_define
define|#
directive|define
name|ZLRB_RING_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|ZLRB_RING_MASK
value|255
end_define

begin_struct
struct|struct
name|zs_chanstate
block|{
name|struct
name|zs_chanstate
modifier|*
name|cs_next
decl_stmt|;
comment|/* linked list for zshard() */
specifier|volatile
name|struct
name|zschan
modifier|*
name|cs_zc
decl_stmt|;
comment|/* points to hardware regs */
name|int
name|cs_unit
decl_stmt|;
comment|/* unit number */
name|struct
name|tty
modifier|*
name|cs_ttyp
decl_stmt|;
comment|/* ### */
comment|/* 	 * We must keep a copy of the write registers as they are 	 * mostly write-only and we sometimes need to set and clear 	 * individual bits (e.g., in WR3).  Not all of these are 	 * needed but 16 bytes is cheap and this makes the addressing 	 * simpler.  Unfortunately, we can only write to some registers 	 * when the chip is not actually transmitting, so whenever 	 * we are expecting a `transmit done' interrupt the wreg array 	 * is allowed to `get ahead' of the current values.  In a 	 * few places we must change the current value of a register, 	 * rather than (or in addition to) the pending value; for these 	 * cs_creg[] contains the current value. 	 */
name|u_char
name|cs_creg
index|[
literal|16
index|]
decl_stmt|;
comment|/* current values */
name|u_char
name|cs_preg
index|[
literal|16
index|]
decl_stmt|;
comment|/* pending values */
name|u_char
name|cs_heldchange
decl_stmt|;
comment|/* change pending (creg != preg) */
comment|/* 	 * The transmit byte count and address are used for pseudo-DMA 	 * output in the hardware interrupt code.  PDMA can be suspended 	 * to get pending changes done; heldtbc is used for this.  It can 	 * also be stopped for ^S; this sets TS_TTSTOP in tp->t_state. 	 */
name|int
name|cs_tbc
decl_stmt|;
comment|/* transmit byte count */
name|caddr_t
name|cs_tba
decl_stmt|;
comment|/* transmit buffer address */
name|int
name|cs_heldtbc
decl_stmt|;
comment|/* held tbc while xmission stopped */
comment|/* 	 * Printing an overrun error message often takes long enough to 	 * cause another overrun, so we only print one per second. 	 */
name|long
name|cs_rotime
decl_stmt|;
comment|/* time of last ring overrun */
name|long
name|cs_fotime
decl_stmt|;
comment|/* time of last fifo overrun */
comment|/* pure software data, per channel */
name|int
name|cs_speed
decl_stmt|;
comment|/* default baud rate (from ROM) */
name|char
name|cs_softcar
decl_stmt|;
comment|/* software carrier */
name|char
name|cs_conk
decl_stmt|;
comment|/* is console keyboard, decode L1-A */
name|char
name|cs_brkabort
decl_stmt|;
comment|/* abort (as if via L1-A) on BREAK */
name|char
name|cs_kgdb
decl_stmt|;
comment|/* enter debugger on frame char */
name|char
name|cs_consio
decl_stmt|;
comment|/* port does /dev/console I/O */
comment|/* 	 * Status change interrupts merely copy the new status and 	 * schedule a software interrupt to deal with it.  To make 	 * checking easier, cs_rr0 is guaranteed nonzero on status 	 * changes.  cs_txint indicates a software transmit interrupt 	 * (a txint where cs_tbc was 0).  A software receive interrupt 	 * is implicit in cs_rbget != cs_rbput. 	 */
name|u_char
name|cs_txint
decl_stmt|;
comment|/* software tx interrupt */
name|u_short
name|cs_rr0
decl_stmt|;
comment|/* rr0 | 0x100, after change */
name|u_int
name|cs_rbget
decl_stmt|;
comment|/* receive ring buffer `get' index */
specifier|volatile
name|u_int
name|cs_rbput
decl_stmt|;
comment|/* receive ring buffer `put' index */
name|u_short
name|cs_rbuf
index|[
name|ZLRB_RING_SIZE
index|]
decl_stmt|;
comment|/* packed data: (char<< 8) + rr1 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macros to read and write individual registers (except 0) in a channel.  *  * On the SparcStation the 1.6 microsecond recovery time is  * handled in hardware.  */
end_comment

begin_define
define|#
directive|define
name|ZS_READ
parameter_list|(
name|c
parameter_list|,
name|r
parameter_list|)
value|((c)->zc_csr = (r), (c)->zc_csr)
end_define

begin_define
define|#
directive|define
name|ZS_WRITE
parameter_list|(
name|c
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|((c)->zc_csr = (r), (c)->zc_csr = (v))
end_define

end_unit

