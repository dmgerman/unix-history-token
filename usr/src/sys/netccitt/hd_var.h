begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * %sccs.include.redist.c%  *  *	@(#)hd_var.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *  * hdlc control block  *  */
end_comment

begin_struct
struct|struct
name|hdtxq
block|{
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdcb
block|{
name|struct
name|hdcb
modifier|*
name|hd_next
decl_stmt|;
comment|/* pointer to next hdlc control block */
name|char
name|hd_state
decl_stmt|;
comment|/* link state */
name|char
name|hd_vs
decl_stmt|;
comment|/* send state variable */
name|char
name|hd_vr
decl_stmt|;
comment|/* receive state variable */
name|char
name|hd_lastrxnr
decl_stmt|;
comment|/* last received N(R) */
name|char
name|hd_lasttxnr
decl_stmt|;
comment|/* last transmitted N(R) */
name|char
name|hd_condition
decl_stmt|;
define|#
directive|define
name|TIMER_RECOVERY_CONDITION
value|0x01
define|#
directive|define
name|REJ_CONDITION
value|0x02
define|#
directive|define
name|REMOTE_RNR_CONDITION
value|0X04
name|char
name|hd_retxcnt
decl_stmt|;
name|char
name|hd_xx
decl_stmt|;
name|struct
name|hdtxq
name|hd_txq
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|hd_retxq
index|[
name|MODULUS
index|]
decl_stmt|;
name|char
name|hd_retxqi
decl_stmt|;
name|char
name|hd_rrtimer
decl_stmt|;
name|char
name|hd_timer
decl_stmt|;
define|#
directive|define
name|SET_TIMER
parameter_list|(
name|hdp
parameter_list|)
value|hdp->hd_timer = hd_t1
define|#
directive|define
name|KILL_TIMER
parameter_list|(
name|hdp
parameter_list|)
value|hdp->hd_timer = 0
name|char
name|hd_dontcopy
decl_stmt|;
comment|/* if-driver doesn't free I-frames */
name|struct
name|ifnet
modifier|*
name|hd_ifp
decl_stmt|;
comment|/* device's network visible interface */
name|struct
name|x25config
modifier|*
name|hd_xcp
decl_stmt|;
comment|/* copy of&hdp->hd_if->if_addr */
comment|/* link statistics */
name|long
name|hd_iframes_in
decl_stmt|;
name|long
name|hd_iframes_out
decl_stmt|;
name|long
name|hd_rrs_in
decl_stmt|;
name|long
name|hd_rrs_out
decl_stmt|;
name|short
name|hd_rejs_in
decl_stmt|;
name|short
name|hd_rejs_out
decl_stmt|;
name|long
name|hd_window_condition
decl_stmt|;
name|short
name|hd_invalid_ns
decl_stmt|;
name|short
name|hd_invalid_nr
decl_stmt|;
name|short
name|hd_timeouts
decl_stmt|;
name|short
name|hd_resets
decl_stmt|;
name|short
name|hd_unknown
decl_stmt|;
name|short
name|hd_frmrs_in
decl_stmt|;
name|short
name|hd_frmrs_out
decl_stmt|;
name|short
name|hd_rnrs_in
decl_stmt|;
name|short
name|hd_rnrs_out
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|hdcb
modifier|*
name|hdcbhead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of linked list of hdcb's */
end_comment

begin_decl_stmt
name|struct
name|Frmr_frame
name|hd_frmr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rejected frame diagnostic info */
end_comment

begin_decl_stmt
name|struct
name|ifqueue
name|hdintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hdlc packet input queue */
end_comment

begin_decl_stmt
name|int
name|hd_t1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* timer T1 value */
end_comment

begin_decl_stmt
name|int
name|hd_t3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RR send timer */
end_comment

begin_decl_stmt
name|int
name|hd_n2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frame retransmission limit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

