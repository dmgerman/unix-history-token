begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntpsim.h  *  * The header file for the ntp discrete event simulator.   *  * Written By:	Sachin Kamboj  *		University of Delaware  *		Newark, DE 19711  * Copyright (c) 2006  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTPSIM_H
end_ifndef

begin_define
define|#
directive|define
name|NTPSIM_H
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|"ntp_prio_q.h"
end_include

begin_comment
comment|/* CONSTANTS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PI
end_ifdef

begin_undef
undef|#
directive|undef
name|PI
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PI
value|3.1415926535
end_define

begin_comment
comment|/* The world's most famous constant */
end_comment

begin_define
define|#
directive|define
name|SIM_TIME
value|86400
end_define

begin_comment
comment|/* end simulation time */
end_comment

begin_define
define|#
directive|define
name|NET_DLY
value|.001
end_define

begin_comment
comment|/* network delay */
end_comment

begin_define
define|#
directive|define
name|PROC_DLY
value|.001
end_define

begin_comment
comment|/* processing delay */
end_comment

begin_define
define|#
directive|define
name|BEEP_DLY
value|3600
end_define

begin_comment
comment|/* beep interval (s) */
end_comment

begin_comment
comment|/* Discrete Event Queue  * --------------------  * The NTP simulator is a discrete event simulator.  *  * Central to this simulator is an event queue which is a priority queue  * in which the "priority" is given by the time of arrival of the event.  *  * A discrete set of events can happen and are stored in the queue to arrive  * at a particular time.  */
end_comment

begin_comment
comment|/* Possible Discrete Events */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BEEP
block|,
comment|/* Event to record simulator stats */
name|CLOCK
block|,
comment|/* Event to advance the clock to the specified time */
name|TIMER
block|,
comment|/* Event that designates a timer interrupt. */
name|PACKET
comment|/* Event that designates arrival of a packet */
block|}
name|funcTkn
typedef|;
end_typedef

begin_comment
comment|/* Event information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|time
decl_stmt|;
comment|/* Time at which event occurred */
name|funcTkn
name|function
decl_stmt|;
comment|/* Type of event that occured */
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
comment|/* Other data associated with the event */
define|#
directive|define
name|ntp_pkt
value|buffer.evnt_pkt
define|#
directive|define
name|rcv_buf
value|buffer.evnt_buf
block|}
name|Event
typedef|;
end_typedef

begin_comment
comment|/* Server Script Information */
end_comment

begin_typedef
typedef|typedef
name|struct
name|script_info_tag
name|script_info
typedef|;
end_typedef

begin_struct
struct|struct
name|script_info_tag
block|{
name|script_info
modifier|*
name|link
decl_stmt|;
name|double
name|duration
decl_stmt|;
name|double
name|freq_offset
decl_stmt|;
name|double
name|wander
decl_stmt|;
name|double
name|jitter
decl_stmt|;
name|double
name|prop_delay
decl_stmt|;
name|double
name|proc_delay
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|script_info
argument_list|)
name|script_info_fifo
expr_stmt|;
end_typedef

begin_comment
comment|/* Server Structures */
end_comment

begin_typedef
typedef|typedef
name|struct
name|server_info_tag
name|server_info
typedef|;
end_typedef

begin_struct
struct|struct
name|server_info_tag
block|{
name|server_info
modifier|*
name|link
decl_stmt|;
name|double
name|server_time
decl_stmt|;
name|sockaddr_u
modifier|*
name|addr
decl_stmt|;
name|script_info_fifo
modifier|*
name|script
decl_stmt|;
name|script_info
modifier|*
name|curr_script
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|DECL_FIFO_ANCHOR
argument_list|(
argument|server_info
argument_list|)
name|server_info_fifo
expr_stmt|;
end_typedef

begin_comment
comment|/* Simulation control information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Sim_Info
block|{
name|double
name|sim_time
decl_stmt|;
comment|/* Time in the simulation */
name|double
name|end_time
decl_stmt|;
comment|/* Time at which simulation needs to be ended */
name|double
name|beep_delay
decl_stmt|;
comment|/* Delay between simulation "beeps" at which                              simulation  stats are recorded. */
name|int
name|num_of_servers
decl_stmt|;
comment|/* Number of servers in the simulation */
name|server_info
modifier|*
name|servers
decl_stmt|;
comment|/* Pointer to array of servers */
block|}
name|sim_info
typedef|;
end_typedef

begin_comment
comment|/* Local Clock (Client) Variables */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Local_Clock_Info
block|{
name|double
name|local_time
decl_stmt|;
comment|/* Client disciplined time */
name|double
name|adj
decl_stmt|;
comment|/* Remaining time correction */
name|double
name|slew
decl_stmt|;
comment|/* Correction Slew Rate */
name|double
name|last_read_time
decl_stmt|;
comment|/* Last time the clock was read */
block|}
name|local_clock_info
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|local_clock_info
name|simclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local Clock Variables */
end_comment

begin_decl_stmt
specifier|extern
name|sim_info
name|simulation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Simulation Control Variables */
end_comment

begin_comment
comment|/* Function Prototypes */
end_comment

begin_function_decl
name|int
name|ntpsim
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Event
modifier|*
name|event
parameter_list|(
name|double
name|t
parameter_list|,
name|funcTkn
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sim_event_timer
parameter_list|(
name|Event
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|simulate_server
parameter_list|(
name|sockaddr_u
modifier|*
name|serv_addr
parameter_list|,
name|endpt
modifier|*
name|inter
parameter_list|,
name|struct
name|pkt
modifier|*
name|rpkt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sim_update_clocks
parameter_list|(
name|Event
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sim_event_recv_packet
parameter_list|(
name|Event
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sim_event_beep
parameter_list|(
name|Event
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|abortsim
parameter_list|(
name|char
modifier|*
name|errmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|gauss
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|poisson
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_server_associations
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTPSIM_H */
end_comment

end_unit

