begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)if_qereg.h	7.1 (Berkeley) 6/5/86 */
end_comment

begin_comment
comment|/* @(#)if_qereg.h	1.2 (ULTRIX) 1/3/85 */
end_comment

begin_comment
comment|/****************************************************************  *								*  *        Licensed from Digital Equipment Corporation 		*  *                       Copyright (c) 				*  *               Digital Equipment Corporation			*  *                   Maynard, Massachusetts 			*  *                         1985, 1986 				*  *                    All rights reserved. 			*  *								*  *        The Information in this software is subject to change *  *   without notice and should not be construed as a commitment *  *   by  Digital  Equipment  Corporation.   Digital   makes  no *  *   representations about the suitability of this software for *  *   any purpose.  It is supplied "As Is" without expressed  or *  *   implied  warranty. 					*  *								*  *        If the Regents of the University of California or its *  *   licensees modify the software in a manner creating  	*  *   diriviative copyright rights, appropriate copyright  	*  *   legends may be placed on  the drivative work in addition   *  *   to that set forth above. 					*  *								*  ****************************************************************/
end_comment

begin_comment
comment|/* ---------------------------------------------------------------------  * Modification History   *  *  13 Feb. 84 -- rjl  *  *	Initial version of driver. derived from IL driver.  *   * ---------------------------------------------------------------------  */
end_comment

begin_comment
comment|/*  * Digital Q-BUS to NI Adapter   */
end_comment

begin_struct
struct|struct
name|qedevice
block|{
name|u_short
name|qe_sta_addr
index|[
literal|2
index|]
decl_stmt|;
comment|/* Station address (actually 6 	*/
name|u_short
name|qe_rcvlist_lo
decl_stmt|;
comment|/* Receive list lo address 	*/
name|u_short
name|qe_rcvlist_hi
decl_stmt|;
comment|/* Receive list hi address 	*/
name|u_short
name|qe_xmtlist_lo
decl_stmt|;
comment|/* Transmit list lo address 	*/
name|u_short
name|qe_xmtlist_hi
decl_stmt|;
comment|/* Transmit list hi address 	*/
name|u_short
name|qe_vector
decl_stmt|;
comment|/* Interrupt vector 		*/
name|u_short
name|qe_csr
decl_stmt|;
comment|/* Command and Status Register 	*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command and status bits (csr)  */
end_comment

begin_define
define|#
directive|define
name|QE_RCV_ENABLE
value|0x0001
end_define

begin_comment
comment|/* Receiver enable		*/
end_comment

begin_define
define|#
directive|define
name|QE_RESET
value|0x0002
end_define

begin_comment
comment|/* Software reset		*/
end_comment

begin_define
define|#
directive|define
name|QE_NEX_MEM_INT
value|0x0004
end_define

begin_comment
comment|/* Non existant mem interrupt	*/
end_comment

begin_define
define|#
directive|define
name|QE_LOAD_ROM
value|0x0008
end_define

begin_comment
comment|/* Load boot/diag from rom	*/
end_comment

begin_define
define|#
directive|define
name|QE_XL_INVALID
value|0x0010
end_define

begin_comment
comment|/* Transmit list invalid	*/
end_comment

begin_define
define|#
directive|define
name|QE_RL_INVALID
value|0x0020
end_define

begin_comment
comment|/* Receive list invalid		*/
end_comment

begin_define
define|#
directive|define
name|QE_INT_ENABLE
value|0x0040
end_define

begin_comment
comment|/* Interrupt enable		*/
end_comment

begin_define
define|#
directive|define
name|QE_XMIT_INT
value|0x0080
end_define

begin_comment
comment|/* Transmit interrupt		*/
end_comment

begin_define
define|#
directive|define
name|QE_ILOOP
value|0x0100
end_define

begin_comment
comment|/* Internal loopback		*/
end_comment

begin_define
define|#
directive|define
name|QE_ELOOP
value|0x0200
end_define

begin_comment
comment|/* External loopback		*/
end_comment

begin_define
define|#
directive|define
name|QE_STIM_ENABLE
value|0x0400
end_define

begin_comment
comment|/* Sanity timer enable		*/
end_comment

begin_define
define|#
directive|define
name|QE_POWERUP
value|0x1000
end_define

begin_comment
comment|/* Tranceiver power on		*/
end_comment

begin_define
define|#
directive|define
name|QE_CARRIER
value|0x2000
end_define

begin_comment
comment|/* Carrier detect		*/
end_comment

begin_define
define|#
directive|define
name|QE_RCV_INT
value|0x8000
end_define

begin_comment
comment|/* Receiver interrupt		*/
end_comment

begin_comment
comment|/*  * Transmit and receive ring discriptor ---------------------------  *  * The QNA uses the flag, status1 and the valid bit as a handshake/semiphore  * mechinism.   *   * The flag word is written on ( bits 15,15 set to 1 ) when it reads the  * descriptor. If the valid bit is set it considers the address to be valid.  * When it uses the buffer pointed to by the valid address it sets status word  * one.  */
end_comment

begin_struct
struct|struct
name|qe_ring
block|{
name|u_short
name|qe_flag
decl_stmt|;
comment|/* Buffer utilization flags	*/
name|u_short
name|qe_addr_hi
range|:
literal|6
decl_stmt|,
comment|/* Hi order bits of buffer addr	*/
name|qe_odd_begin
range|:
literal|1
decl_stmt|,
comment|/* Odd byte begin and end (xmit)*/
name|qe_odd_end
range|:
literal|1
decl_stmt|,
name|qe_fill1
range|:
literal|4
decl_stmt|,
name|qe_setup
range|:
literal|1
decl_stmt|,
comment|/* Setup packet			*/
name|qe_eomsg
range|:
literal|1
decl_stmt|,
comment|/* End of message flag		*/
name|qe_chain
range|:
literal|1
decl_stmt|,
comment|/* Chain address instead of buf */
name|qe_valid
range|:
literal|1
decl_stmt|;
comment|/* Address field is valid	*/
name|u_short
name|qe_addr_lo
decl_stmt|;
comment|/* Low order bits of address	*/
name|short
name|qe_buf_len
decl_stmt|;
comment|/* Negative buffer length	*/
name|u_short
name|qe_status1
decl_stmt|;
comment|/* Status word one		*/
name|u_short
name|qe_status2
decl_stmt|;
comment|/* Status word two		*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Status word definations (receive)  *	word1  */
end_comment

begin_define
define|#
directive|define
name|QE_OVF
value|0x0001
end_define

begin_comment
comment|/* Receiver overflow		*/
end_comment

begin_define
define|#
directive|define
name|QE_CRCERR
value|0x0002
end_define

begin_comment
comment|/* CRC error			*/
end_comment

begin_define
define|#
directive|define
name|QE_FRAME
value|0x0004
end_define

begin_comment
comment|/* Framing alignment error	*/
end_comment

begin_define
define|#
directive|define
name|QE_SHORT
value|0x0008
end_define

begin_comment
comment|/* Packet size< 10 bytes	*/
end_comment

begin_define
define|#
directive|define
name|QE_RBL_HI
value|0x0700
end_define

begin_comment
comment|/* Hi bits of receive len	*/
end_comment

begin_define
define|#
directive|define
name|QE_RUNT
value|0x0800
end_define

begin_comment
comment|/* Runt packet			*/
end_comment

begin_define
define|#
directive|define
name|QE_DISCARD
value|0x1000
end_define

begin_comment
comment|/* Discard the packet		*/
end_comment

begin_define
define|#
directive|define
name|QE_ESETUP
value|0x2000
end_define

begin_comment
comment|/* Looped back setup or eloop	*/
end_comment

begin_define
define|#
directive|define
name|QE_ERROR
value|0x4000
end_define

begin_comment
comment|/* Receiver error		*/
end_comment

begin_define
define|#
directive|define
name|QE_LASTNOT
value|0x8000
end_define

begin_comment
comment|/* Not the last in the packet	*/
end_comment

begin_comment
comment|/*	word2								*/
end_comment

begin_define
define|#
directive|define
name|QE_RBL_LO
value|0x00ff
end_define

begin_comment
comment|/* Low bits of receive len	*/
end_comment

begin_comment
comment|/*  * Status word definations (transmit)  *	word1  */
end_comment

begin_define
define|#
directive|define
name|QE_CCNT
value|0x00f0
end_define

begin_comment
comment|/* Collision count this packet	*/
end_comment

begin_define
define|#
directive|define
name|QE_FAIL
value|0x0100
end_define

begin_comment
comment|/* Heart beat check failure	*/
end_comment

begin_define
define|#
directive|define
name|QE_ABORT
value|0x0200
end_define

begin_comment
comment|/* Transmission abort		*/
end_comment

begin_define
define|#
directive|define
name|QE_STE16
value|0x0400
end_define

begin_comment
comment|/* Sanity timer default on	*/
end_comment

begin_define
define|#
directive|define
name|QE_NOCAR
value|0x0800
end_define

begin_comment
comment|/* No carrier			*/
end_comment

begin_define
define|#
directive|define
name|QE_LOSS
value|0x1000
end_define

begin_comment
comment|/* Loss of carrier while xmit	*/
end_comment

begin_comment
comment|/*	word2								*/
end_comment

begin_define
define|#
directive|define
name|QE_TDR
value|0x3fff
end_define

begin_comment
comment|/* Time domain reflectometry	*/
end_comment

begin_comment
comment|/*  * General constant definations  */
end_comment

begin_define
define|#
directive|define
name|QEALLOC
value|0
end_define

begin_comment
comment|/* Allocate an mbuf		*/
end_comment

begin_define
define|#
directive|define
name|QENOALLOC
value|1
end_define

begin_comment
comment|/* No mbuf allocation		*/
end_comment

begin_define
define|#
directive|define
name|QEDEALLOC
value|2
end_define

begin_comment
comment|/* Release an mbuf chain	*/
end_comment

begin_define
define|#
directive|define
name|QE_NOTYET
value|0x8000
end_define

begin_comment
comment|/* Descriptor not in use yet	*/
end_comment

begin_define
define|#
directive|define
name|QE_INUSE
value|0x4000
end_define

begin_comment
comment|/* Descriptor being used by QNA	*/
end_comment

begin_define
define|#
directive|define
name|QE_MASK
value|0xc000
end_define

begin_comment
comment|/* Lastnot/error/used mask	*/
end_comment

end_unit

