begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*   Copyright 1988, 1989 by Olivetti Advanced Technology Center, Inc., Cupertino, California.  		All Rights Reserved    Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appears in all copies and that both the copyright notice and this permission notice appear in supporting documentation, and that the name of Olivetti not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    OLIVETTI DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL OLIVETTI BE LIABLE FOR ANY SPECIAL, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN ACTION OF CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUR OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
end_comment

begin_comment
comment|/*  * Defines for managing the status word of the 82586 cpu.  For details see  * the Intel LAN Component User's Manual starting at p. 2-14.  *  */
end_comment

begin_define
define|#
directive|define
name|SCB_SW_INT
value|0xf000
end_define

begin_define
define|#
directive|define
name|SCB_SW_CX
value|0x8000
end_define

begin_comment
comment|/* CU finished w/ int. bit set */
end_comment

begin_define
define|#
directive|define
name|SCB_SW_FR
value|0x4000
end_define

begin_comment
comment|/* RU finished receiving a frame */
end_comment

begin_define
define|#
directive|define
name|SCB_SW_CNA
value|0x2000
end_define

begin_comment
comment|/* CU left active state */
end_comment

begin_define
define|#
directive|define
name|SCB_SW_RNR
value|0x1000
end_define

begin_comment
comment|/* RU left ready state */
end_comment

begin_comment
comment|/*   * Defines for managing the Command Unit Status portion of the 82586  * System Control Block.  *  */
end_comment

begin_define
define|#
directive|define
name|SCB_CUS_IDLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCB_CUS_SUSPND
value|0x0100
end_define

begin_define
define|#
directive|define
name|SCB_CUS_ACTV
value|0x0200
end_define

begin_comment
comment|/*   * Defines for managing the Receive Unit Status portion of the System  * Control Block.  *  */
end_comment

begin_define
define|#
directive|define
name|SCB_RUS_IDLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCB_RUS_SUSPND
value|0x0010
end_define

begin_define
define|#
directive|define
name|SCB_RUS_NORESRC
value|0x0020
end_define

begin_define
define|#
directive|define
name|SCB_RUS_READY
value|0x0040
end_define

begin_comment
comment|/*  * Defines that manage portions of the Command Word in the System Control  * Block of the 82586.  Below are the Interrupt Acknowledge Bits and their  * appropriate masks.  *  */
end_comment

begin_define
define|#
directive|define
name|SCB_ACK_CX
value|0x8000
end_define

begin_define
define|#
directive|define
name|SCB_ACK_FR
value|0x4000
end_define

begin_define
define|#
directive|define
name|SCB_ACK_CNA
value|0x2000
end_define

begin_define
define|#
directive|define
name|SCB_ACK_RNR
value|0x1000
end_define

begin_comment
comment|/*   * Defines for managing the Command Unit Control word, and the Receive  * Unit Control word.  The software RESET bit is also defined.  *  */
end_comment

begin_define
define|#
directive|define
name|SCB_CU_STRT
value|0x0100
end_define

begin_define
define|#
directive|define
name|SCB_CU_RSUM
value|0x0200
end_define

begin_define
define|#
directive|define
name|SCB_CU_SUSPND
value|0x0300
end_define

begin_define
define|#
directive|define
name|SCB_CU_ABRT
value|0x0400
end_define

begin_define
define|#
directive|define
name|SCB_RESET
value|0x0080
end_define

begin_define
define|#
directive|define
name|SCB_RU_STRT
value|0x0010
end_define

begin_define
define|#
directive|define
name|SCB_RU_RSUM
value|0x0020
end_define

begin_define
define|#
directive|define
name|SCB_RU_SUSPND
value|0x0030
end_define

begin_define
define|#
directive|define
name|SCB_RU_ABRT
value|0x0040
end_define

begin_comment
comment|/*  * The following define Action Commands for the 82586 chip.  *  */
end_comment

begin_define
define|#
directive|define
name|AC_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|AC_IASETUP
value|0x01
end_define

begin_define
define|#
directive|define
name|AC_CONFIGURE
value|0x02
end_define

begin_define
define|#
directive|define
name|AC_MCSETUP
value|0x03
end_define

begin_define
define|#
directive|define
name|AC_TRANSMIT
value|0x04
end_define

begin_define
define|#
directive|define
name|AC_TDR
value|0x05
end_define

begin_define
define|#
directive|define
name|AC_DUMP
value|0x06
end_define

begin_define
define|#
directive|define
name|AC_DIAGNOSE
value|0x07
end_define

begin_comment
comment|/*  * Defines for General Format for Action Commands, both Status Words, and  * Command Words.  *  */
end_comment

begin_define
define|#
directive|define
name|AC_SW_C
value|0x8000
end_define

begin_define
define|#
directive|define
name|AC_SW_B
value|0x4000
end_define

begin_define
define|#
directive|define
name|AC_SW_OK
value|0x2000
end_define

begin_define
define|#
directive|define
name|AC_SW_A
value|0x1000
end_define

begin_define
define|#
directive|define
name|TC_CARRIER
value|0x0400
end_define

begin_define
define|#
directive|define
name|TC_CLS
value|0x0200
end_define

begin_define
define|#
directive|define
name|TC_DMA
value|0x0100
end_define

begin_define
define|#
directive|define
name|TC_DEFER
value|0x0080
end_define

begin_define
define|#
directive|define
name|TC_SQE
value|0x0040
end_define

begin_define
define|#
directive|define
name|TC_COLLISION
value|0x0020
end_define

begin_define
define|#
directive|define
name|AC_CW_EL
value|0x8000
end_define

begin_define
define|#
directive|define
name|AC_CW_S
value|0x4000
end_define

begin_define
define|#
directive|define
name|AC_CW_I
value|0x2000
end_define

begin_comment
comment|/*  * Specific defines for the transmit action command.  *  */
end_comment

begin_define
define|#
directive|define
name|TBD_SW_EOF
value|0x8000
end_define

begin_define
define|#
directive|define
name|TBD_SW_COUNT
value|0x3fff
end_define

begin_comment
comment|/*  * Specific defines for the receive frame actions.  *  */
end_comment

begin_define
define|#
directive|define
name|RBD_SW_EOF
value|0x8000
end_define

begin_define
define|#
directive|define
name|RBD_SW_COUNT
value|0x3fff
end_define

begin_define
define|#
directive|define
name|RFD_DONE
value|0x8000
end_define

begin_define
define|#
directive|define
name|RFD_BUSY
value|0x4000
end_define

begin_define
define|#
directive|define
name|RFD_OK
value|0x2000
end_define

begin_define
define|#
directive|define
name|RFD_CRC
value|0x0800
end_define

begin_define
define|#
directive|define
name|RFD_ALN
value|0x0400
end_define

begin_define
define|#
directive|define
name|RFD_RSC
value|0x0200
end_define

begin_define
define|#
directive|define
name|RFD_DMA
value|0x0100
end_define

begin_define
define|#
directive|define
name|RFD_SHORT
value|0x0080
end_define

begin_define
define|#
directive|define
name|RFD_EOF
value|0x0040
end_define

begin_define
define|#
directive|define
name|RFD_EL
value|0x8000
end_define

begin_define
define|#
directive|define
name|RFD_SUSP
value|0x4000
end_define

begin_comment
comment|/*  * 82586 chip specific structure definitions.  For details, see the Intel  * LAN Components manual.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|scp_sysbus
decl_stmt|;
name|u_short
name|scp_unused
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|scp_iscp
decl_stmt|;
name|u_short
name|scp_iscp_base
decl_stmt|;
block|}
name|scp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|iscp_busy
decl_stmt|;
name|u_short
name|iscp_scb_offset
decl_stmt|;
name|u_short
name|iscp_scb
decl_stmt|;
name|u_short
name|iscp_scb_base
decl_stmt|;
block|}
name|iscp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|scb_status
decl_stmt|;
name|u_short
name|scb_command
decl_stmt|;
name|u_short
name|scb_cbl_offset
decl_stmt|;
name|u_short
name|scb_rfa_offset
decl_stmt|;
name|u_short
name|scb_crcerrs
decl_stmt|;
name|u_short
name|scb_alnerrs
decl_stmt|;
name|u_short
name|scb_rscerrs
decl_stmt|;
name|u_short
name|scb_ovrnerrs
decl_stmt|;
block|}
name|scb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|tbd_offset
decl_stmt|;
name|u_char
name|dest_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|length
decl_stmt|;
block|}
name|transmit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|fifolim_bytecnt
decl_stmt|;
name|u_short
name|addrlen_mode
decl_stmt|;
name|u_short
name|linprio_interframe
decl_stmt|;
name|u_short
name|slot_time
decl_stmt|;
name|u_short
name|hardware
decl_stmt|;
name|u_short
name|min_frame_len
decl_stmt|;
block|}
name|configure_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|ac_status
decl_stmt|;
name|u_short
name|ac_command
decl_stmt|;
name|u_short
name|ac_link_offset
decl_stmt|;
union|union
block|{
name|transmit_t
name|transmit
decl_stmt|;
name|configure_t
name|configure
decl_stmt|;
name|u_char
name|iasetup
index|[
literal|6
index|]
decl_stmt|;
block|}
name|cmd
union|;
block|}
name|ac_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|act_count
decl_stmt|;
name|u_short
name|next_tbd_offset
decl_stmt|;
name|u_short
name|buffer_addr
decl_stmt|;
name|u_short
name|buffer_base
decl_stmt|;
block|}
name|tbd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|status
decl_stmt|;
name|u_short
name|command
decl_stmt|;
name|u_short
name|link_offset
decl_stmt|;
name|u_short
name|rbd_offset
decl_stmt|;
name|u_char
name|destination
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|source
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|length
decl_stmt|;
block|}
name|fd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|status
decl_stmt|;
name|u_short
name|next_rbd_offset
decl_stmt|;
name|u_short
name|buffer_addr
decl_stmt|;
name|u_short
name|buffer_base
decl_stmt|;
name|u_short
name|size
decl_stmt|;
block|}
name|rbd_t
typedef|;
end_typedef

end_unit

