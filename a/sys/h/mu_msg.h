begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mu_msg.h	Melb 4.2	82/10/20	*/
end_comment

begin_comment
comment|/*  * Melb Uni trivial IPC mechanism  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MUSH
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DATA_T
end_ifndef

begin_comment
comment|/* so people can make a union/struct if they want */
end_comment

begin_define
define|#
directive|define
name|DATA_T
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
ifdef|#
directive|ifdef
name|vax
comment|/* this isn't important, just nice */
name|u_short
name|msg_uid
range|:
literal|15
decl_stmt|;
comment|/* effective sender uid (or code if pid==0) */
name|u_short
name|msg_val
range|:
literal|1
decl_stmt|;
comment|/* msg is valid, ie: really sent by someone */
name|u_short
name|msg_pid
range|:
literal|15
decl_stmt|;
comment|/* rcv: proc id of sender, snd: dest addr */
name|u_short
name|msg_rply
range|:
literal|1
decl_stmt|;
comment|/* rcv: reply required, snd: recv reply only */
else|#
directive|else
name|u_short
name|msg_rply
range|:
literal|1
decl_stmt|;
name|u_short
name|msg_pid
range|:
literal|15
decl_stmt|;
name|u_short
name|msg_val
range|:
literal|1
decl_stmt|;
name|u_short
name|msg_uid
range|:
literal|15
decl_stmt|;
endif|#
directive|endif
name|DATA_T
name|msg_data
decl_stmt|;
block|}
name|mmsgbuf
typedef|;
end_typedef

begin_comment
comment|/*  * The following relate to the mu_msg() sys call  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MSG_ENAB
block|,
comment|/* enable input msgs to process */
name|MSG_DISB
block|,
comment|/* no more messages */
name|MSG_RECV
block|,
comment|/* get a message */
name|MSG_SEND
block|,
comment|/* send a message */
name|MSG_SNDW
block|,
comment|/* send a msg then get one */
name|MSG_RPLY
block|,
comment|/* send a reply */
block|}
name|msg_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_W_RCV
value|0x0001
end_define

begin_comment
comment|/* wait for message to be received */
end_comment

begin_define
define|#
directive|define
name|MSG_W_POST
value|0x0002
end_define

begin_comment
comment|/* wait till queued to receiver */
end_comment

begin_define
define|#
directive|define
name|MSG_W_DLV
value|0x0004
end_define

begin_comment
comment|/* wait till delivered (not impl) */
end_comment

begin_define
define|#
directive|define
name|MSG_W_Q
value|0x0008
end_define

begin_comment
comment|/* wait if process queues full (not impl) */
end_comment

begin_define
define|#
directive|define
name|MSG_W_ENAB
value|0x0010
end_define

begin_comment
comment|/* wait till rcvr enables messages (not impl) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* 	 * Some of this stuff belongs other places, but ... 	 */
end_comment

begin_define
define|#
directive|define
name|MSGENAB
value|0x0001
end_define

begin_comment
comment|/* process has messages enabled */
end_comment

begin_define
define|#
directive|define
name|MSGOK
value|0x0002
end_define

begin_comment
comment|/* process is waiting for msg */
end_comment

begin_define
define|#
directive|define
name|MSGWRPLY
value|0x0004
end_define

begin_comment
comment|/* message process is waiting for is a reply */
end_comment

begin_define
define|#
directive|define
name|MSGRPLY
value|0x0008
end_define

begin_comment
comment|/* process must reply to last msg */
end_comment

begin_define
define|#
directive|define
name|MSGWAIT
value|0x0010
end_define

begin_comment
comment|/* some process is waiting on our msgbuf */
end_comment

begin_define
define|#
directive|define
name|MSGPRI
value|(PZERO+4)
end_define

begin_comment
comment|/* Interruptible */
end_comment

begin_function_decl
name|struct
name|proc
modifier|*
name|mu_send
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGMESG
value|28
end_define

begin_comment
comment|/* sig sent to MSGENAB'd proc if msg arrives */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

