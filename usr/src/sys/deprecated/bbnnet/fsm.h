begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: fsm.h,v 1.3 85/04/08 13:02:06 walsh Exp $ */
end_comment

begin_define
define|#
directive|define
name|EFAILEC
value|(-1)
end_define

begin_define
define|#
directive|define
name|SAME
value|0
end_define

begin_define
define|#
directive|define
name|LISTEN
value|1
end_define

begin_define
define|#
directive|define
name|SYN_SENT
value|2
end_define

begin_define
define|#
directive|define
name|SYN_RCVD
value|3
end_define

begin_define
define|#
directive|define
name|L_SYN_RCVD
value|4
end_define

begin_define
define|#
directive|define
name|ESTAB
value|5
end_define

begin_define
define|#
directive|define
name|FIN_W1
value|6
end_define

begin_define
define|#
directive|define
name|FIN_W2
value|7
end_define

begin_define
define|#
directive|define
name|TIME_WAIT
value|8
end_define

begin_define
define|#
directive|define
name|CLOSE_WAIT
value|9
end_define

begin_define
define|#
directive|define
name|CLOSING1
value|10
end_define

begin_define
define|#
directive|define
name|CLOSING2
value|11
end_define

begin_define
define|#
directive|define
name|RCV_WAIT
value|12
end_define

begin_define
define|#
directive|define
name|CLOSED
value|13
end_define

begin_define
define|#
directive|define
name|TCP_NSTATES
value|14
end_define

begin_define
define|#
directive|define
name|IUOPENA
value|1
end_define

begin_define
define|#
directive|define
name|INRECV
value|2
end_define

begin_define
define|#
directive|define
name|IUOPENR
value|3
end_define

begin_define
define|#
directive|define
name|IUCLOSE
value|4
end_define

begin_define
define|#
directive|define
name|ISTIMER
value|5
end_define

begin_define
define|#
directive|define
name|IURECV
value|6
end_define

begin_define
define|#
directive|define
name|IUSEND
value|7
end_define

begin_define
define|#
directive|define
name|IUABORT
value|8
end_define

begin_define
define|#
directive|define
name|INCLEAR
value|9
end_define

begin_define
define|#
directive|define
name|INOP
value|10
end_define

begin_comment
comment|/* number of inputs to TCP fsm */
end_comment

begin_define
define|#
directive|define
name|TXMT
value|0
end_define

begin_comment
comment|/* measure time from sent sequence t_xmt_val to ack */
end_comment

begin_define
define|#
directive|define
name|TINIT
value|1
end_define

begin_comment
comment|/* timeout on connetion creation */
end_comment

begin_define
define|#
directive|define
name|TREXMT
value|2
end_define

begin_comment
comment|/* resend data when goes off */
end_comment

begin_define
define|#
directive|define
name|TREXMTTL
value|3
end_define

begin_comment
comment|/* tell user retransmissions failing when goes off */
end_comment

begin_define
define|#
directive|define
name|TPERSIST
value|4
end_define

begin_comment
comment|/* probe closed windows to ensure opening */
end_comment

begin_define
define|#
directive|define
name|TFINACK
value|5
end_define

begin_define
define|#
directive|define
name|TDELACK
value|6
end_define

begin_comment
comment|/* used to reduce ack-only traffic + incr thruput */
end_comment

begin_define
define|#
directive|define
name|TNOACT
value|7
end_define

begin_comment
comment|/* no activity, or close took too long */
end_comment

begin_define
define|#
directive|define
name|NTIMERS
value|8
end_define

begin_comment
comment|/* number of tcp timers */
end_comment

end_unit

