begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 	DATAKIT Common Kernel Structure interface definitions  *		@(#)dkdev.h	1.3 Garage 84/05/14  */
end_comment

begin_comment
comment|/*  * datakit ioctl commands  */
end_comment

begin_define
define|#
directive|define
name|DKIOCMASK
value|(0377<< 8)
end_define

begin_comment
comment|/*  if (code& mask) == val   */
end_comment

begin_define
define|#
directive|define
name|DKIOCVAL
value|('k'<< 8)
end_define

begin_comment
comment|/*    then datakit control    */
end_comment

begin_comment
comment|/*  *	common structure for dk.c and dkxqt.c (and a little of dktty.c)  *	  for an open channel  */
end_comment

begin_struct
struct|struct
name|dkdev
block|{
name|short
name|d_state
decl_stmt|;
comment|/* various bit values, defined below */
name|short
name|dc_state
decl_stmt|;
comment|/* more bit values */
name|short
name|d_bufct
decl_stmt|;
comment|/* count of buffers in write Q */
name|short
name|d_rmode
decl_stmt|;
comment|/* receive termination modes */
name|short
name|d_rresid
decl_stmt|;
comment|/* 1 of 3 */
comment|/* residual buffer left in receive */
name|short
name|d_rdone
decl_stmt|;
comment|/* 2 of 3 */
comment|/* completion status of last receive */
name|short
name|d_rctl
decl_stmt|;
comment|/* 3 of 3 */
comment|/* control char received */
name|short
name|d_xctl
decl_stmt|;
comment|/* control char to send */
name|int
name|d_pgrp
decl_stmt|;
comment|/* process group number */
name|short
name|d_prot
decl_stmt|;
comment|/* active protocols on this channel */
name|struct
name|diocxwin
name|d_win
decl_stmt|;
comment|/* Requested window size */
name|struct
name|diocctype
modifier|*
name|d_ctype
decl_stmt|;
comment|/* Connection type */
define|#
directive|define
name|DpURP
value|0x0001
comment|/* plain URP -- dk.c */
define|#
directive|define
name|DpTTY
value|0x0002
comment|/* tty protocol -- dktty.c */
define|#
directive|define
name|DpXQT
value|0x0004
comment|/* remote execution -- dkxqt.c */
define|#
directive|define
name|DpIP
value|0x0008
comment|/* IP */
union|union
block|{
struct|struct
block|{
comment|/* DK */
name|caddr_t
name|dk_addr
decl_stmt|;
comment|/* address of current bp or cb */
name|short
name|dk_param
index|[
literal|3
index|]
decl_stmt|;
comment|/* parameters from user from ioctl */
name|short
name|dk_Xstate
decl_stmt|;
comment|/* various state bits */
name|short
name|dk_error
decl_stmt|;
comment|/* call setup error code */
block|}
name|d_dk
struct|;
struct|struct
block|{
comment|/* DKXQT */
name|caddr_t
name|dkx_rbuf
decl_stmt|;
comment|/* receive buffer address */
name|caddr_t
name|dkx_xbuf
decl_stmt|;
comment|/* transmit buffer address */
name|unsigned
name|dkx_discard
decl_stmt|;
comment|/* amount to discard from input */
name|short
name|dkx_Xstate
decl_stmt|;
comment|/* various state bits */
block|}
name|d_dkx
struct|;
comment|/* others? */
block|}
name|d_var
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|d_addr
value|d_var.d_dk.dk_addr
end_define

begin_define
define|#
directive|define
name|d_param
value|d_var.d_dk.dk_param
end_define

begin_define
define|#
directive|define
name|d_error
value|d_var.d_dk.dk_error
end_define

begin_define
define|#
directive|define
name|d_rbuf
value|d_var.d_dkx.dkx_rbuf
end_define

begin_define
define|#
directive|define
name|d_xbuf
value|d_var.d_dkx.dkx_xbuf
end_define

begin_define
define|#
directive|define
name|d_discard
value|d_var.d_dkx.dkx_discard
end_define

begin_define
define|#
directive|define
name|dx_state
value|d_var.d_dkx.dkx_Xstate
end_define

begin_comment
comment|/*  *	bits in d_state  */
end_comment

begin_define
define|#
directive|define
name|DKOPEN
value|000001
end_define

begin_comment
comment|/* this channel is open somewhere */
end_comment

begin_define
define|#
directive|define
name|DKXCLUDE
value|000002
end_define

begin_comment
comment|/* open exclusive use, or DT open */
end_comment

begin_define
define|#
directive|define
name|DKWAIT
value|000004
end_define

begin_comment
comment|/* process waiting for a buffer */
end_comment

begin_define
define|#
directive|define
name|DKSPLICED
value|000020
end_define

begin_comment
comment|/* received splice request from controller */
end_comment

begin_comment
comment|/*  *	bits in dc_state  */
end_comment

begin_define
define|#
directive|define
name|DKSETUP
value|000004
end_define

begin_comment
comment|/* setup in progress on channel */
end_comment

begin_define
define|#
directive|define
name|DKEXPMT
value|000010
end_define

begin_comment
comment|/* timing experiment mode */
end_comment

begin_define
define|#
directive|define
name|DKXMIT
value|000010
end_define

begin_comment
comment|/* transmit */
end_comment

begin_define
define|#
directive|define
name|DKDROP
value|000030
end_define

begin_comment
comment|/* for ignoring input */
end_comment

begin_define
define|#
directive|define
name|DKRW
value|000050
end_define

begin_comment
comment|/* bounce, read then write */
end_comment

begin_define
define|#
directive|define
name|DKWR
value|000070
end_define

begin_comment
comment|/* bounce, write then read */
end_comment

begin_define
define|#
directive|define
name|DKNOABO
value|000100
end_define

begin_comment
comment|/* do not abort receives, NK mode */
end_comment

begin_define
define|#
directive|define
name|DK_ASYNC
value|000200
end_define

begin_comment
comment|/* generate sigio when complete */
end_comment

begin_define
define|#
directive|define
name|DK_NDELAY
value|000400
end_define

begin_comment
comment|/* non-blocking mode */
end_comment

begin_comment
comment|/*  *	bits in dx_state  */
end_comment

begin_define
define|#
directive|define
name|DXWAIT
value|000040
end_define

begin_comment
comment|/* process is waiting for line */
end_comment

begin_define
define|#
directive|define
name|DXCANCEL
value|020000
end_define

begin_comment
comment|/* last sent cancel, ignore nxt msg */
end_comment

begin_define
define|#
directive|define
name|DXRQRCV
value|040000
end_define

begin_comment
comment|/* response received to request */
end_comment

begin_define
define|#
directive|define
name|DXRQACT
value|0100000
end_define

begin_comment
comment|/* request active on channel */
end_comment

end_unit

