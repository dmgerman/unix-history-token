begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	DATAKIT VCS Data Structures for a DR-11C interface  *		@(#)dkdr.h	1.1 Garage 84/03/27  */
end_comment

begin_comment
comment|/*  *  Structure for each Datakit channel  */
end_comment

begin_struct
struct|struct
name|dkchan
block|{
name|short
name|dk_state
decl_stmt|;
name|struct
name|ifqueue
name|dk_outq
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dk_endfcn
function_decl|)
parameter_list|()
function_decl|;
name|caddr_t
name|dk_endparm
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dk_supfcn
function_decl|)
parameter_list|()
function_decl|;
comment|/* who to tell of circuit supervision */
name|caddr_t
name|dk_raddr
decl_stmt|;
comment|/* address of received data */
name|unsigned
name|dk_rlen
decl_stmt|;
comment|/* length of pending receive */
name|short
name|dk_rmode
decl_stmt|;
comment|/* possible completion modes */
name|unsigned
name|dk_xlen
decl_stmt|;
comment|/* length of xmit */
name|struct
name|mbuf
modifier|*
name|dk_curout
decl_stmt|;
comment|/* current buffer */
name|struct
name|dkpkbufr
modifier|*
name|dk_rq
decl_stmt|;
comment|/* un-acked input */
name|struct
name|dkpkbufr
modifier|*
name|dk_rb
decl_stmt|;
comment|/* un-checked input */
name|short
name|dk_rblen
decl_stmt|;
comment|/* len of unchecked */
name|char
name|dk_S
decl_stmt|;
comment|/* protocol parameters */
name|char
name|dk_R
decl_stmt|;
name|char
name|dk_X
decl_stmt|;
name|char
name|dk_A
decl_stmt|;
name|char
name|dk_C
decl_stmt|;
name|char
name|dk_trmode
decl_stmt|;
name|char
name|dk_rseq
decl_stmt|;
name|short
name|dk_tail1
decl_stmt|;
name|short
name|dk_tail2
decl_stmt|;
name|int
name|dk_rejcnt
decl_stmt|;
comment|/* Reject messages received */
name|int
name|dk_srejcnt
decl_stmt|;
comment|/* Reject messages sent */
name|int
name|dk_ackrejcnt
decl_stmt|;
comment|/* Acks that cause retransmit */
name|int
name|dk_enqcnt
decl_stmt|;
comment|/* ENQs sent */
block|}
struct|;
end_struct

begin_comment
comment|/* Flags for dk_X */
end_comment

begin_define
define|#
directive|define
name|XM_OFF
value|((char) 0xff)
end_define

begin_comment
comment|/* transmitter off */
end_comment

begin_define
define|#
directive|define
name|XM_INIT
value|((char) 02)
end_define

begin_comment
comment|/* transmitter initialized */
end_comment

begin_define
define|#
directive|define
name|XM_REJ
value|((char) 04)
end_define

begin_comment
comment|/* Sent REJ */
end_comment

begin_define
define|#
directive|define
name|XM_ENQ
value|((char) 010)
end_define

begin_comment
comment|/* send ENQ next timeout */
end_comment

begin_comment
comment|/*  * Packet buffers  */
end_comment

begin_struct
struct|struct
name|dkpkbufr
block|{
name|struct
name|dkpkbufr
modifier|*
name|Pnext
decl_stmt|;
name|short
name|Phibits
decl_stmt|;
name|char
name|Pseq
decl_stmt|;
name|char
name|Plen
decl_stmt|;
name|char
name|Pdata
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure to save completion status until processed  */
end_comment

begin_struct
struct|struct
name|dkstat
block|{
name|short
name|k_type
decl_stmt|;
comment|/* type of completion status */
name|short
name|k_chan
decl_stmt|;
comment|/* channel number */
name|short
name|k_info1
decl_stmt|;
comment|/* misc info */
name|short
name|k_info2
decl_stmt|;
block|}
struct|;
end_struct

end_unit

