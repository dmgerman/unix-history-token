begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)zsvar.h	7.3 (Berkeley) %G%  *  * from: $Header: zsvar.h,v 1.7 92/11/26 01:28:04 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Software state, per zs channel.  *  * The zs chip has insufficient buffering, so we provide a software  * buffer using a two-level interrupt scheme.  The hardware (high priority)  * interrupt simply grabs the `cause' of the interrupt and stuffs it into  * a ring buffer.  It then schedules a software interrupt; the latter  * empties the ring as fast as it can, hoping to avoid overflow.  *  * Interrupts can happen because of:  *	- received data;  *	- transmit pseudo-DMA done; and  *	- status change.  * These are all stored together in the (single) ring.  The size of the  * ring is a power of two, to make % operations fast.  Since we need two  * bits to distinguish the interrupt type, and up to 16 for the received  * data plus RR1 status, we use 32 bits per ring entry.  *  * When the value is a character + RR1 status, the character is in the  * upper 8 bits of the RR1 status.  */
end_comment

begin_define
define|#
directive|define
name|ZLRB_RING_SIZE
value|256
end_define

begin_comment
comment|/* ZS line ring buffer size */
end_comment

begin_define
define|#
directive|define
name|ZLRB_RING_MASK
value|255
end_define

begin_comment
comment|/* mask for same */
end_comment

begin_comment
comment|/* 0 is reserved (means "no interrupt") */
end_comment

begin_define
define|#
directive|define
name|ZRING_RINT
value|1
end_define

begin_comment
comment|/* receive data interrupt */
end_comment

begin_define
define|#
directive|define
name|ZRING_XINT
value|2
end_define

begin_comment
comment|/* transmit done interrupt */
end_comment

begin_define
define|#
directive|define
name|ZRING_SINT
value|3
end_define

begin_comment
comment|/* status change interrupt */
end_comment

begin_define
define|#
directive|define
name|ZRING_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& 3)
end_define

begin_define
define|#
directive|define
name|ZRING_VALUE
parameter_list|(
name|x
parameter_list|)
value|((x)>> 8)
end_define

begin_define
define|#
directive|define
name|ZRING_MAKE
parameter_list|(
name|t
parameter_list|,
name|v
parameter_list|)
value|((t) | (v)<< 8)
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
comment|/* 	 * We must keep a copy of the write registers as they are 	 * mostly write-only and we sometimes need to set and clear 	 * individual bits (e.g., in WR3).  Not all of these are 	 * needed but 16 bytes is cheap and this makes the addressing 	 * simpler.  Unfortunately, we can only write to some registers 	 * when the chip is not actually transmitting, so whenever 	 * we are expecting a `transmit done' interrupt the preg array 	 * is allowed to `get ahead' of the current values.  In a 	 * few places we must change the current value of a register, 	 * rather than (or in addition to) the pending value; for these 	 * cs_creg[] contains the current value. 	 */
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
name|u_char
name|cs_rr0
decl_stmt|;
comment|/* last rr0 processed */
comment|/* pure software data, per channel */
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
name|char
name|cs_xxx
decl_stmt|;
comment|/* (spare) */
name|int
name|cs_speed
decl_stmt|;
comment|/* default baud rate (from ROM) */
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
comment|/* 	 * The ring buffer. 	 */
name|u_int
name|cs_rbget
decl_stmt|;
comment|/* ring buffer `get' index */
specifier|volatile
name|u_int
name|cs_rbput
decl_stmt|;
comment|/* ring buffer `put' index */
name|int
name|cs_rbuf
index|[
name|ZLRB_RING_SIZE
index|]
decl_stmt|;
comment|/* type, value pairs */
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

