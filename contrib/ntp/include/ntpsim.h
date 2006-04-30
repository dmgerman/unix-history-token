begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntpsim.h - Prototypes for ntpsim  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ntpsim_h
end_ifndef

begin_define
define|#
directive|define
name|__ntpsim_h
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_select.h"
end_include

begin_include
include|#
directive|include
file|"ntp_malloc.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"recvbuff.h"
end_include

begin_include
include|#
directive|include
file|"ntp_io.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_define
define|#
directive|define
name|PI
value|3.1415926535
end_define

begin_comment
comment|/*  * ntpsim declarations  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BEEP
block|,
name|CLOCK
block|,
name|TIMER
block|,
name|PACKET
block|}
name|funcTkn
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|time
decl_stmt|;
union|union
block|{
name|struct
name|pkt
name|evnt_pkt
decl_stmt|;
name|struct
name|recvbuf
name|evnt_buf
decl_stmt|;
block|}
name|buffer
union|;
define|#
directive|define
name|ntp_pkt
value|buffer.evnt_pkt
define|#
directive|define
name|rcv_buf
value|buffer.evnt_buf
name|funcTkn
name|function
decl_stmt|;
block|}
name|Event
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|List
block|{
name|Event
name|event
decl_stmt|;
name|struct
name|List
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|Queue
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nde
block|{
name|double
name|time
decl_stmt|;
comment|/* simulation time */
name|double
name|sim_time
decl_stmt|;
comment|/* end simulation time */
name|double
name|ntp_time
decl_stmt|;
comment|/* client disciplined time */
name|double
name|adj
decl_stmt|;
comment|/* remaining time correction */
name|double
name|slew
decl_stmt|;
comment|/* correction slew rate */
name|double
name|clk_time
decl_stmt|;
comment|/* server time */
name|double
name|ferr
decl_stmt|;
comment|/* frequency errort */
name|double
name|fnse
decl_stmt|;
comment|/* random walk noise */
name|double
name|ndly
decl_stmt|;
comment|/* network delay */
name|double
name|snse
decl_stmt|;
comment|/* phase noise */
name|double
name|pdly
decl_stmt|;
comment|/* processing delay */
name|double
name|bdly
decl_stmt|;
comment|/* beep interval */
name|double
name|last_time
decl_stmt|;
comment|/* last clock read time */
name|Queue
name|events
decl_stmt|;
comment|/* Node Event Queue */
name|struct
name|recvbuf
modifier|*
name|rbuflist
decl_stmt|;
comment|/* Node Receive Buffer */
block|}
name|Node
typedef|;
end_typedef

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
name|int
name|ntpsim
name|P
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Event
name|event
name|P
argument_list|(
operator|(
name|double
operator|,
name|funcTkn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Queue
name|queue
name|P
argument_list|(
operator|(
name|Event
operator|,
name|Queue
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Node
name|node
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|push
name|P
argument_list|(
operator|(
name|Event
operator|,
name|Queue
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Event
name|pop
name|P
argument_list|(
operator|(
name|Queue
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ndbeep
name|P
argument_list|(
operator|(
name|Node
operator|*
operator|,
name|Event
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ndeclk
name|P
argument_list|(
operator|(
name|Node
operator|*
operator|,
name|Event
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ntptmr
name|P
argument_list|(
operator|(
name|Node
operator|*
operator|,
name|Event
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|netpkt
name|P
argument_list|(
operator|(
name|Node
operator|*
operator|,
name|Event
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|srvr_rply
name|P
argument_list|(
operator|(
name|Node
operator|*
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|,
expr|struct
name|pkt
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|gauss
name|P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|poisson
name|P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|node_clock
name|P
argument_list|(
operator|(
name|Node
operator|*
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|abortsim
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The global Node  */
end_comment

begin_decl_stmt
name|Node
name|ntp_node
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

