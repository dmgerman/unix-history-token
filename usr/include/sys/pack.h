begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|pack
block|{
name|short
name|p_state
decl_stmt|;
comment|/* line state */
name|short
name|p_bits
decl_stmt|;
comment|/* mask for getepack */
name|short
name|p_psize
decl_stmt|;
comment|/* packet size */
name|short
name|p_icount
decl_stmt|;
comment|/* input byte count */
name|char
name|p_ostate
decl_stmt|;
comment|/* output state */
name|char
name|p_istate
decl_stmt|;
comment|/* input state */
name|char
name|p_msgs
decl_stmt|;
comment|/* # cntl msgs sent */
name|char
name|p_window
decl_stmt|;
comment|/* window size */
name|char
name|p_iseq
decl_stmt|;
comment|/* input SEQ byte */
name|char
name|p_oseq
decl_stmt|;
comment|/* output SEQ byte */
name|char
name|p_msg
decl_stmt|;
comment|/* control msg */
name|char
name|p_msg2
decl_stmt|;
comment|/* extra msg bits */
name|char
name|p_ps
decl_stmt|,
name|p_pr
decl_stmt|;
comment|/* last packet sent, recv'd */
name|char
name|p_rps
decl_stmt|,
name|p_rpr
decl_stmt|;
comment|/* remote (received) ps and pr */
name|char
name|p_nxtps
decl_stmt|;
comment|/* next output seq number */
name|char
name|p_nxtpr
decl_stmt|;
comment|/* expected input seq number */
name|char
name|p_prcopy
decl_stmt|;
comment|/* oldest received packet in kernel */
name|char
name|p_pscopy
decl_stmt|;
comment|/* newest output packet */
name|char
modifier|*
name|p_input
decl_stmt|;
comment|/* points into input buffer */
name|char
name|p_iobuf
index|[
literal|6
index|]
decl_stmt|;
comment|/* cntl packet buffer */
name|char
modifier|*
name|p_ob
index|[
literal|8
index|]
decl_stmt|;
comment|/* output buffers */
name|char
modifier|*
name|p_ib
index|[
literal|8
index|]
decl_stmt|;
comment|/* input buffers */
name|char
name|p_bstate
index|[
literal|8
index|]
decl_stmt|;
comment|/* output buffer status */
name|char
name|p_cstate
index|[
literal|8
index|]
decl_stmt|;
comment|/* input buffer status */
name|short
name|p_checks
index|[
literal|8
index|]
decl_stmt|;
name|short
name|p_rcheck
decl_stmt|;
name|struct
name|tty
modifier|*
name|p_ttyp
decl_stmt|;
name|int
name|p_timer
decl_stmt|;
name|int
name|xcount
decl_stmt|,
name|rcount
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NPSTRUCT
value|(1+(sizeof(struct pack))/64)
end_define

begin_define
define|#
directive|define
name|NPERBUF
value|(8/NPSTRUCT)
end_define

begin_define
define|#
directive|define
name|CHECK
value|0125252
end_define

begin_decl_stmt
name|int
name|npbits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * driver state  */
end_comment

begin_define
define|#
directive|define
name|DEAD
value|0
end_define

begin_define
define|#
directive|define
name|INITa
value|1
end_define

begin_define
define|#
directive|define
name|INITb
value|2
end_define

begin_define
define|#
directive|define
name|ISINIT
value|3
end_define

begin_define
define|#
directive|define
name|LIVE
value|4
end_define

begin_define
define|#
directive|define
name|RESYNC
value|010
end_define

begin_define
define|#
directive|define
name|DOWN
value|020
end_define

begin_define
define|#
directive|define
name|RREJ
value|040
end_define

begin_define
define|#
directive|define
name|RXMIT
value|0100
end_define

begin_define
define|#
directive|define
name|PDEBUG
value|0200
end_define

begin_define
define|#
directive|define
name|DRAINO
value|0400
end_define

begin_define
define|#
directive|define
name|WAITO
value|01000
end_define

begin_comment
comment|/*  * input side states  */
end_comment

begin_define
define|#
directive|define
name|P_IDLE
value|1
end_define

begin_define
define|#
directive|define
name|P_SCAN
value|2
end_define

begin_define
define|#
directive|define
name|P_SEQ1
value|3
end_define

begin_define
define|#
directive|define
name|P_PACK
value|4
end_define

begin_define
define|#
directive|define
name|P_CHK1
value|5
end_define

begin_define
define|#
directive|define
name|P_CHK2
value|6
end_define

begin_define
define|#
directive|define
name|P_SEQ2
value|7
end_define

begin_define
define|#
directive|define
name|P_FLUSH
value|8
end_define

begin_define
define|#
directive|define
name|SYN
value|026
end_define

begin_comment
comment|/*  * output side states  */
end_comment

begin_define
define|#
directive|define
name|T_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|T_READY
value|1
end_define

begin_define
define|#
directive|define
name|T_HDR
value|2
end_define

begin_define
define|#
directive|define
name|T_PACK
value|3
end_define

begin_define
define|#
directive|define
name|T_TAIL
value|4
end_define

begin_comment
comment|/*  * io buffer states  */
end_comment

begin_define
define|#
directive|define
name|B_FREE
value|0
end_define

begin_define
define|#
directive|define
name|B_READY
value|1
end_define

begin_define
define|#
directive|define
name|B_SENT
value|2
end_define

begin_define
define|#
directive|define
name|B_PACK
value|4
end_define

begin_define
define|#
directive|define
name|B_COPY
value|010
end_define

begin_define
define|#
directive|define
name|B_XMIT
value|020
end_define

begin_comment
comment|/*  * frame control messages  */
end_comment

begin_define
define|#
directive|define
name|RR
value|1
end_define

begin_define
define|#
directive|define
name|RWR
value|2
end_define

begin_define
define|#
directive|define
name|REJ
value|3
end_define

begin_define
define|#
directive|define
name|CLOSE
value|4
end_define

begin_define
define|#
directive|define
name|RESET
value|6
end_define

begin_define
define|#
directive|define
name|INIT
value|7
end_define

begin_define
define|#
directive|define
name|UA
value|8
end_define

begin_define
define|#
directive|define
name|PKOPRI
value|31
end_define

begin_define
define|#
directive|define
name|PKIPRI
value|30
end_define

begin_define
define|#
directive|define
name|NPLINES
value|8
end_define

begin_comment
comment|/*  * packet ioctl buf  */
end_comment

begin_struct
struct|struct
name|piocb
block|{
name|unsigned
name|t
decl_stmt|;
name|short
name|psize
decl_stmt|;
name|short
name|mode
decl_stmt|;
name|short
name|state
decl_stmt|;
name|char
name|window
decl_stmt|;
block|}
struct|;
end_struct

end_unit

