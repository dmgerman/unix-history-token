begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, University of Vermont and State Agricultural College.  * Copyright (c) 1992, Garrett A. Wollman.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	Vermont and State Agricultural College and Garrett A. Wollman.  * 4. Neither the name of the University nor the name of the author  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE UNIVERSITY OR AUTHOR BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Intel 82586 Ethernet chip  * Register, bit, and structure definitions.  *  * Written by GAW with reference to the Clarkson Packet Driver code for this  * chip written by Russ Nelson and others.  */
end_comment

begin_struct
struct|struct
name|ie_en_addr
block|{
name|u_char
name|data
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the master configuration block.  It tells the hardware where all  * the rest of the stuff is.  */
end_comment

begin_struct
struct|struct
name|ie_sys_conf_ptr
block|{
name|u_short
name|mbz
decl_stmt|;
comment|/* must be zero */
name|u_char
name|ie_bus_use
decl_stmt|;
comment|/* true if 8-bit only */
name|u_char
name|mbz2
index|[
literal|5
index|]
decl_stmt|;
comment|/* must be zero */
name|caddr_t
name|ie_iscp_ptr
decl_stmt|;
comment|/* 24-bit physaddr of ISCP */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Note that this is wired in hardware; the SCP is always located here, no  * matter what.  */
end_comment

begin_define
define|#
directive|define
name|IE_SCP_ADDR
value|0xfffff4
end_define

begin_comment
comment|/*  * The tells the hardware where all the rest of the stuff is, too.  * FIXME: some of these should be re-commented after we figure out their  * REAL function.  */
end_comment

begin_struct
struct|struct
name|ie_int_sys_conf_ptr
block|{
name|u_char
name|ie_busy
decl_stmt|;
comment|/* zeroed after init */
name|u_char
name|mbz
decl_stmt|;
name|u_short
name|ie_scb_offset
decl_stmt|;
comment|/* 16-bit physaddr of next struct */
name|caddr_t
name|ie_base
decl_stmt|;
comment|/* 24-bit physaddr for all 16-bit vars */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This FINALLY tells the hardware what to do and where to put it.  */
end_comment

begin_struct
struct|struct
name|ie_sys_ctl_block
block|{
name|u_short
name|ie_status
decl_stmt|;
comment|/* status word */
name|u_short
name|ie_command
decl_stmt|;
comment|/* command word */
name|u_short
name|ie_command_list
decl_stmt|;
comment|/* 16-pointer to command block list */
name|u_short
name|ie_recv_list
decl_stmt|;
comment|/* 16-pointer to receive frame list */
name|u_short
name|ie_err_crc
decl_stmt|;
comment|/* CRC errors */
name|u_short
name|ie_err_align
decl_stmt|;
comment|/* Alignment errors */
name|u_short
name|ie_err_resource
decl_stmt|;
comment|/* Resource errors */
name|u_short
name|ie_err_overrun
decl_stmt|;
comment|/* Overrun errors */
block|}
struct|;
end_struct

begin_comment
comment|/* Command values */
end_comment

begin_define
define|#
directive|define
name|IE_RU_COMMAND
value|0x0070
end_define

begin_comment
comment|/* mask for RU command */
end_comment

begin_define
define|#
directive|define
name|IE_RU_NOP
value|0
end_define

begin_comment
comment|/* for completeness */
end_comment

begin_define
define|#
directive|define
name|IE_RU_START
value|0x0010
end_define

begin_comment
comment|/* start receive unit command */
end_comment

begin_define
define|#
directive|define
name|IE_RU_ENABLE
value|0x0020
end_define

begin_comment
comment|/* enable receiver command */
end_comment

begin_define
define|#
directive|define
name|IE_RU_DISABLE
value|0x0030
end_define

begin_comment
comment|/* disable receiver command */
end_comment

begin_define
define|#
directive|define
name|IE_RU_ABORT
value|0x0040
end_define

begin_comment
comment|/* abort current receive operation */
end_comment

begin_define
define|#
directive|define
name|IE_CU_COMMAND
value|0x0700
end_define

begin_comment
comment|/* mask for CU command */
end_comment

begin_define
define|#
directive|define
name|IE_CU_NOP
value|0
end_define

begin_comment
comment|/* included for completeness */
end_comment

begin_define
define|#
directive|define
name|IE_CU_START
value|0x0100
end_define

begin_comment
comment|/* do-command command */
end_comment

begin_define
define|#
directive|define
name|IE_CU_RESUME
value|0x0200
end_define

begin_comment
comment|/* resume a suspended cmd list */
end_comment

begin_define
define|#
directive|define
name|IE_CU_STOP
value|0x0300
end_define

begin_comment
comment|/* SUSPEND was already taken */
end_comment

begin_define
define|#
directive|define
name|IE_CU_ABORT
value|0x0400
end_define

begin_comment
comment|/* abort current command */
end_comment

begin_define
define|#
directive|define
name|IE_ACK_COMMAND
value|0xf000
end_define

begin_comment
comment|/* mask for ACK command */
end_comment

begin_define
define|#
directive|define
name|IE_ACK_CX
value|0x8000
end_define

begin_comment
comment|/* ack IE_ST_DONE */
end_comment

begin_define
define|#
directive|define
name|IE_ACK_FR
value|0x4000
end_define

begin_comment
comment|/* ack IE_ST_RECV */
end_comment

begin_define
define|#
directive|define
name|IE_ACK_CNA
value|0x2000
end_define

begin_comment
comment|/* ack IE_ST_ALLDONE */
end_comment

begin_define
define|#
directive|define
name|IE_ACK_RNR
value|0x1000
end_define

begin_comment
comment|/* ack IE_ST_RNR */
end_comment

begin_define
define|#
directive|define
name|IE_ACTION_COMMAND
parameter_list|(
name|x
parameter_list|)
value|(((x)& IE_CU_COMMAND) == IE_CU_START)
end_define

begin_comment
comment|/* is this command an action command? */
end_comment

begin_comment
comment|/* Status values */
end_comment

begin_define
define|#
directive|define
name|IE_ST_WHENCE
value|0xf000
end_define

begin_comment
comment|/* mask for cause of interrupt */
end_comment

begin_define
define|#
directive|define
name|IE_ST_DONE
value|0x8000
end_define

begin_comment
comment|/* command with I bit completed */
end_comment

begin_define
define|#
directive|define
name|IE_ST_RECV
value|0x4000
end_define

begin_comment
comment|/* frame received */
end_comment

begin_define
define|#
directive|define
name|IE_ST_ALLDONE
value|0x2000
end_define

begin_comment
comment|/* all commands completed */
end_comment

begin_define
define|#
directive|define
name|IE_ST_RNR
value|0x1000
end_define

begin_comment
comment|/* receive not ready */
end_comment

begin_define
define|#
directive|define
name|IE_CU_STATUS
value|0x700
end_define

begin_comment
comment|/* mask for command unit status */
end_comment

begin_define
define|#
directive|define
name|IE_CU_ACTIVE
value|0x200
end_define

begin_comment
comment|/* command unit is active */
end_comment

begin_define
define|#
directive|define
name|IE_CU_SUSPEND
value|0x100
end_define

begin_comment
comment|/* command unit is suspended */
end_comment

begin_define
define|#
directive|define
name|IE_RU_STATUS
value|0x70
end_define

begin_comment
comment|/* mask for receiver unit status */
end_comment

begin_define
define|#
directive|define
name|IE_RU_SUSPEND
value|0x10
end_define

begin_comment
comment|/* receiver is suspended */
end_comment

begin_define
define|#
directive|define
name|IE_RU_NOSPACE
value|0x20
end_define

begin_comment
comment|/* receiver has no resources */
end_comment

begin_define
define|#
directive|define
name|IE_RU_READY
value|0x40
end_define

begin_comment
comment|/* reveiver is ready */
end_comment

begin_comment
comment|/*  * This is filled in partially by the chip, partially by us.  */
end_comment

begin_struct
struct|struct
name|ie_recv_frame_desc
block|{
name|u_short
name|ie_fd_status
decl_stmt|;
comment|/* status for this frame */
name|u_short
name|ie_fd_last
decl_stmt|;
comment|/* end of frame list flag */
name|u_short
name|ie_fd_next
decl_stmt|;
comment|/* 16-pointer to next RFD */
name|u_short
name|ie_fd_buf_desc
decl_stmt|;
comment|/* 16-pointer to list of buffer desc's */
name|struct
name|ie_en_addr
name|dest
decl_stmt|;
comment|/* destination ether */
name|struct
name|ie_en_addr
name|src
decl_stmt|;
comment|/* source ether */
name|u_short
name|ie_length
decl_stmt|;
comment|/* 802 length/Ether type */
name|u_short
name|mbz
decl_stmt|;
comment|/* must be zero */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IE_FD_LAST
value|0x8000
end_define

begin_comment
comment|/* last rfd in list */
end_comment

begin_define
define|#
directive|define
name|IE_FD_SUSP
value|0x4000
end_define

begin_comment
comment|/* suspend RU after receipt */
end_comment

begin_define
define|#
directive|define
name|IE_FD_COMPLETE
value|0x8000
end_define

begin_comment
comment|/* frame is complete */
end_comment

begin_define
define|#
directive|define
name|IE_FD_BUSY
value|0x4000
end_define

begin_comment
comment|/* frame is busy */
end_comment

begin_define
define|#
directive|define
name|IE_FD_OK
value|0x2000
end_define

begin_comment
comment|/* frame is bad */
end_comment

begin_define
define|#
directive|define
name|IE_FD_RNR
value|0x0200
end_define

begin_comment
comment|/* receiver out of resources here */
end_comment

begin_comment
comment|/*  * linked list of buffers...  */
end_comment

begin_struct
struct|struct
name|ie_recv_buf_desc
block|{
name|u_short
name|ie_rbd_actual
decl_stmt|;
comment|/* status for this buffer */
name|u_short
name|ie_rbd_next
decl_stmt|;
comment|/* 16-pointer to next RBD */
name|caddr_t
name|ie_rbd_buffer
decl_stmt|;
comment|/* 24-pointer to buffer for this RBD */
name|u_short
name|ie_rbd_length
decl_stmt|;
comment|/* length of the buffer */
name|u_short
name|mbz
decl_stmt|;
comment|/* must be zero */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IE_RBD_LAST
value|0x8000
end_define

begin_comment
comment|/* last buffer */
end_comment

begin_define
define|#
directive|define
name|IE_RBD_USED
value|0x4000
end_define

begin_comment
comment|/* this buffer has data */
end_comment

begin_comment
comment|/*  * All commands share this in common.  */
end_comment

begin_struct
struct|struct
name|ie_cmd_common
block|{
name|u_short
name|ie_cmd_status
decl_stmt|;
comment|/* status of this command */
name|u_short
name|ie_cmd_cmd
decl_stmt|;
comment|/* command word */
name|u_short
name|ie_cmd_link
decl_stmt|;
comment|/* link to next command */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IE_STAT_COMPL
value|0x8000
end_define

begin_comment
comment|/* command is completed */
end_comment

begin_define
define|#
directive|define
name|IE_STAT_BUSY
value|0x4000
end_define

begin_comment
comment|/* command is running now */
end_comment

begin_define
define|#
directive|define
name|IE_STAT_OK
value|0x2000
end_define

begin_comment
comment|/* command completed successfully */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_NOP
value|0x0000
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_IASETUP
value|0x0001
end_define

begin_comment
comment|/* initial address setup */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_CONFIG
value|0x0002
end_define

begin_comment
comment|/* configure command */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_MCAST
value|0x0003
end_define

begin_comment
comment|/* multicast setup command */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_XMIT
value|0x0004
end_define

begin_comment
comment|/* transmit command */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_TDR
value|0x0005
end_define

begin_comment
comment|/* time-domain reflectometer command */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_DUMP
value|0x0006
end_define

begin_comment
comment|/* dump command */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_DIAGNOSE
value|0x0007
end_define

begin_comment
comment|/* diagnostics command */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_LAST
value|0x8000
end_define

begin_comment
comment|/* this is the last command in the list */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_SUSPEND
value|0x4000
end_define

begin_comment
comment|/* suspend CU after this command */
end_comment

begin_define
define|#
directive|define
name|IE_CMD_INTR
value|0x2000
end_define

begin_comment
comment|/* post an interrupt after completion */
end_comment

begin_comment
comment|/*  * This is the command to transmit a frame.  */
end_comment

begin_struct
struct|struct
name|ie_xmit_cmd
block|{
name|struct
name|ie_cmd_common
name|com
decl_stmt|;
comment|/* common part */
define|#
directive|define
name|ie_xmit_status
value|com.ie_cmd_status
name|u_short
name|ie_xmit_desc
decl_stmt|;
comment|/* 16-pointer to buffer descriptor */
name|struct
name|ie_en_addr
name|ie_xmit_addr
decl_stmt|;
comment|/* destination address */
name|u_short
name|ie_xmit_length
decl_stmt|;
comment|/* 802.3 length/Ether type field */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IE_XS_MAXCOLL
value|0x000f
end_define

begin_comment
comment|/* number of collisions during transmit */
end_comment

begin_define
define|#
directive|define
name|IE_XS_EXCMAX
value|0x0020
end_define

begin_comment
comment|/* exceeded maximum number of collisions */
end_comment

begin_define
define|#
directive|define
name|IE_XS_SQE
value|0x0040
end_define

begin_comment
comment|/* SQE positive */
end_comment

begin_define
define|#
directive|define
name|IE_XS_DEFERRED
value|0x0080
end_define

begin_comment
comment|/* transmission deferred */
end_comment

begin_define
define|#
directive|define
name|IE_XS_UNDERRUN
value|0x0100
end_define

begin_comment
comment|/* DMA underrun */
end_comment

begin_define
define|#
directive|define
name|IE_XS_LOSTCTS
value|0x0200
end_define

begin_comment
comment|/* Lost CTS */
end_comment

begin_define
define|#
directive|define
name|IE_XS_NOCARRIER
value|0x0400
end_define

begin_comment
comment|/* No Carrier */
end_comment

begin_define
define|#
directive|define
name|IE_XS_LATECOLL
value|0x0800
end_define

begin_comment
comment|/* Late collision */
end_comment

begin_comment
comment|/*  * This is a buffer descriptor for a frame to be transmitted.  */
end_comment

begin_struct
struct|struct
name|ie_xmit_buf
block|{
name|u_short
name|ie_xmit_flags
decl_stmt|;
comment|/* see below */
name|u_short
name|ie_xmit_next
decl_stmt|;
comment|/* 16-pointer to next desc. */
name|caddr_t
name|ie_xmit_buf
decl_stmt|;
comment|/* 24-pointer to the actual buffer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IE_XMIT_LAST
value|0x8000
end_define

begin_comment
comment|/* this TBD is the last one */
end_comment

begin_comment
comment|/* The rest of the `flags' word is actually the length. */
end_comment

begin_comment
comment|/*  * Multicast setup command.  */
end_comment

begin_define
define|#
directive|define
name|MAXMCAST
value|50
end_define

begin_comment
comment|/* must fit in transmit buffer */
end_comment

begin_struct
struct|struct
name|ie_mcast_cmd
block|{
name|struct
name|ie_cmd_common
name|com
decl_stmt|;
comment|/* common part */
define|#
directive|define
name|ie_mcast_status
value|com.ie_cmd_status
name|u_short
name|ie_mcast_bytes
decl_stmt|;
comment|/* size (in bytes) of multicast addresses */
name|struct
name|ie_en_addr
name|ie_mcast_addrs
index|[
name|MAXMCAST
operator|+
literal|1
index|]
decl_stmt|;
comment|/* space for them */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Time Domain Reflectometer command.  */
end_comment

begin_struct
struct|struct
name|ie_tdr_cmd
block|{
name|struct
name|ie_cmd_common
name|com
decl_stmt|;
comment|/* common part */
define|#
directive|define
name|ie_tdr_status
value|com.ie_cmd_status
name|u_short
name|ie_tdr_time
decl_stmt|;
comment|/* error bits and time */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IE_TDR_SUCCESS
value|0x8000
end_define

begin_comment
comment|/* TDR succeeded without error */
end_comment

begin_define
define|#
directive|define
name|IE_TDR_XCVR
value|0x4000
end_define

begin_comment
comment|/* detected a transceiver problem */
end_comment

begin_define
define|#
directive|define
name|IE_TDR_OPEN
value|0x2000
end_define

begin_comment
comment|/* detected an open */
end_comment

begin_define
define|#
directive|define
name|IE_TDR_SHORT
value|0x1000
end_define

begin_comment
comment|/* TDR detected a short */
end_comment

begin_define
define|#
directive|define
name|IE_TDR_TIME
value|0x07ff
end_define

begin_comment
comment|/* mask for reflection time */
end_comment

begin_comment
comment|/*  * Initial Address Setup command  */
end_comment

begin_struct
struct|struct
name|ie_iasetup_cmd
block|{
name|struct
name|ie_cmd_common
name|com
decl_stmt|;
define|#
directive|define
name|ie_iasetup_status
value|com.ie_cmd_status
name|struct
name|ie_en_addr
name|ie_address
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Configuration command  */
end_comment

begin_struct
struct|struct
name|ie_config_cmd
block|{
name|struct
name|ie_cmd_common
name|com
decl_stmt|;
comment|/* common part */
define|#
directive|define
name|ie_config_status
value|com.ie_cmd_status
name|u_char
name|ie_config_count
decl_stmt|;
comment|/* byte count (0x0c) */
name|u_char
name|ie_fifo
decl_stmt|;
comment|/* fifo (8) */
name|u_char
name|ie_save_bad
decl_stmt|;
comment|/* save bad frames (0x40) */
name|u_char
name|ie_addr_len
decl_stmt|;
comment|/* address length (0x2e) (AL-LOC == 1) */
name|u_char
name|ie_priority
decl_stmt|;
comment|/* priority and backoff (0x0) */
name|u_char
name|ie_ifs
decl_stmt|;
comment|/* inter-frame spacing (0x60) */
name|u_char
name|ie_slot_low
decl_stmt|;
comment|/* slot time, LSB (0x0) */
name|u_char
name|ie_slot_high
decl_stmt|;
comment|/* slot time, MSN, and retries (0xf2) */
name|u_char
name|ie_promisc
decl_stmt|;
comment|/* 1 if promiscuous, else 0 */
name|u_char
name|ie_crs_cdt
decl_stmt|;
comment|/* CSMA/CD parameters (0x0) */
name|u_char
name|ie_min_len
decl_stmt|;
comment|/* min frame length (0x40) */
name|u_char
name|ie_junk
decl_stmt|;
comment|/* stuff for 82596 (0xff) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Here are a few useful functions.  We could have done these as macros,  * but since we have the inline facility, it makes sense to use that  * instead.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ie_setup_config
parameter_list|(
specifier|volatile
name|struct
name|ie_config_cmd
modifier|*
name|cmd
parameter_list|,
name|int
name|promiscuous
parameter_list|,
name|int
name|manchester
parameter_list|)
block|{
name|cmd
operator|->
name|ie_config_count
operator|=
literal|0x0c
expr_stmt|;
name|cmd
operator|->
name|ie_fifo
operator|=
literal|8
expr_stmt|;
name|cmd
operator|->
name|ie_save_bad
operator|=
literal|0x40
expr_stmt|;
name|cmd
operator|->
name|ie_addr_len
operator|=
literal|0x2e
expr_stmt|;
name|cmd
operator|->
name|ie_priority
operator|=
literal|0
expr_stmt|;
name|cmd
operator|->
name|ie_ifs
operator|=
literal|0x60
expr_stmt|;
name|cmd
operator|->
name|ie_slot_low
operator|=
literal|0
expr_stmt|;
name|cmd
operator|->
name|ie_slot_high
operator|=
literal|0xf2
expr_stmt|;
name|cmd
operator|->
name|ie_promisc
operator|=
operator|!
operator|!
name|promiscuous
operator||
name|manchester
operator|<<
literal|2
expr_stmt|;
name|cmd
operator|->
name|ie_crs_cdt
operator|=
literal|0
expr_stmt|;
name|cmd
operator|->
name|ie_min_len
operator|=
literal|64
expr_stmt|;
name|cmd
operator|->
name|ie_junk
operator|=
literal|0xff
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|Align
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|uintptr_t
name|l
init|=
operator|(
name|uintptr_t
operator|)
name|ptr
decl_stmt|;
name|l
operator|=
operator|(
name|l
operator|+
literal|3
operator|)
operator|&
operator|~
literal|3L
expr_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
name|l
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
specifier|volatile
name|void
modifier|*
name|Alignvol
parameter_list|(
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|uintptr_t
name|l
init|=
operator|(
name|uintptr_t
operator|)
name|ptr
decl_stmt|;
name|l
operator|=
operator|(
name|l
operator|+
literal|3
operator|)
operator|&
operator|~
literal|3L
expr_stmt|;
return|return
operator|(
specifier|volatile
name|void
operator|*
operator|)
name|l
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ie_ack
parameter_list|(
specifier|volatile
name|struct
name|ie_sys_ctl_block
modifier|*
name|scb
parameter_list|,
name|u_int
name|mask
parameter_list|,
name|int
name|unit
parameter_list|,
name|void
function_decl|(
modifier|*
name|ca
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
block|{
name|scb
operator|->
name|ie_command
operator|=
name|scb
operator|->
name|ie_status
operator|&
name|mask
expr_stmt|;
call|(
modifier|*
name|ca
call|)
argument_list|(
name|unit
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

