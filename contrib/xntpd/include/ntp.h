begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp.h,v 3.1 1993/07/06 01:06:47 jbj Exp  * ntp.h - NTP definitions for the masses  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/*  * How to get signed characters.  On machines where signed char works,  * use it.  On machines where signed char doesn't work, char had better  * be signed.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_CHAR_DEFINED
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NO_SIGNED_CHAR_DECL
argument_list|)
end_if

begin_typedef
typedef|typedef
name|char
name|s_char
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|signed
name|char
name|s_char
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sequent
end_ifdef

begin_undef
undef|#
directive|undef
name|SO_RCVBUF
end_undef

begin_undef
undef|#
directive|undef
name|SO_SNDBUF
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NTP protocol parameters.  See section 3.2.6 of the specification.  */
end_comment

begin_define
define|#
directive|define
name|NTP_VERSION
value|((u_char)3)
end_define

begin_comment
comment|/* current version number */
end_comment

begin_define
define|#
directive|define
name|NTP_OLDVERSION
value|((u_char)1)
end_define

begin_comment
comment|/* oldest credible version */
end_comment

begin_define
define|#
directive|define
name|NTP_PORT
value|123
end_define

begin_comment
comment|/* included for sake of non-unix machines */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXSTRATUM
value|((u_char)15)
end_define

begin_comment
comment|/* max stratum, infinity a la Bellman-Ford */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXAGE
value|86400
end_define

begin_comment
comment|/* one day in seconds */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXSKEW
value|1
end_define

begin_comment
comment|/* 1 sec, skew after NTP_MAXAGE w/o updates */
end_comment

begin_define
define|#
directive|define
name|NTP_SKEWINC
value|49170
end_define

begin_comment
comment|/* skew increment for clock updates (l_f) */
end_comment

begin_define
define|#
directive|define
name|NTP_SKEWFACTOR
value|16
end_define

begin_comment
comment|/* approximation of factor for peer calcs */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXDISTANCE
value|(1*FP_SECOND)
end_define

begin_comment
comment|/* max. rootdelay for synchr. */
end_comment

begin_define
define|#
directive|define
name|NTP_MINDPOLL
value|6
end_define

begin_comment
comment|/* default min poll (64 sec) */
end_comment

begin_define
define|#
directive|define
name|NTP_MINPOLL
value|4
end_define

begin_comment
comment|/* absolute min poll (16 sec) */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXPOLL
value|10
end_define

begin_comment
comment|/* actually 1<<10, or 1024 sec */
end_comment

begin_define
define|#
directive|define
name|NTP_MINCLOCK
value|3
end_define

begin_comment
comment|/* minimum for outlyer detection */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXCLOCK
value|10
end_define

begin_comment
comment|/* maximum select list size */
end_comment

begin_define
define|#
directive|define
name|NTP_MINDISPERSE
value|0x28f
end_define

begin_comment
comment|/* 0.01 sec in fp format */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXDISPERSE
value|(16*FP_SECOND)
end_define

begin_comment
comment|/* maximum dispersion (fp 16) */
end_comment

begin_define
define|#
directive|define
name|NTP_DISPFACTOR
value|20
end_define

begin_comment
comment|/* MAXDISPERSE as a shift */
end_comment

begin_define
define|#
directive|define
name|NTP_WINDOW
value|8
end_define

begin_comment
comment|/* reachability register size */
end_comment

begin_define
define|#
directive|define
name|NTP_SHIFT
value|8
end_define

begin_comment
comment|/* 8 suitable for crystal time base */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXKEY
value|65535
end_define

begin_comment
comment|/* maximum authentication key number */
end_comment

begin_comment
comment|/*  * Loop filter parameters.  See section 5.1 of the specification.  *  * Note that these are appropriate for a crystal time base.  If your  * system clock is line frequency controlled you should read the  * specification for appropriate modifications.  Note that the  * loop filter code will have to change if you change CLOCK_MAX  * to be greater than or equal to 500 ms.  *  * Note these parameters have been rescaled for a time constant range from  * 0 through 10, with 2 corresoponding to the old time constant of 0.  */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MINSTEP
value|900
end_define

begin_comment
comment|/* step timeout (sec) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ADJ
value|0
end_define

begin_comment
comment|/* log2 adjustment interval (1 sec) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_DSCALE
value|20
end_define

begin_comment
comment|/* skew reg. scale: unit is 2**-20 ~= 1 ppm */
end_comment

begin_define
define|#
directive|define
name|CLOCK_FREQ
value|16
end_define

begin_comment
comment|/* log2 frequency weight (65536) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PHASE
value|6
end_define

begin_comment
comment|/* log2 phase weight (64) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_WEIGHTTC
value|5
end_define

begin_comment
comment|/* log2 time constant weight (32) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_HOLDTC
value|128
end_define

begin_comment
comment|/* time constant hold (sec) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MAX_F
value|0x20c49ba6
end_define

begin_comment
comment|/* 128 ms, in time stamp format */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MAX_I
value|0x0
end_define

begin_comment
comment|/* both fractional and integral parts */
end_comment

begin_define
define|#
directive|define
name|CLOCK_WAYTOOBIG
value|1000
end_define

begin_comment
comment|/* if clock 1000 sec off, forget it */
end_comment

begin_comment
comment|/*  * Unspecified default.  sys.precision defaults to -6 unless otherwise  * adjusted.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SYS_PRECISION
value|(-6)
end_define

begin_comment
comment|/*  * Event timers are actually implemented as a sorted queue of expiry  * times.  The queue is slotted, with each slot holding timers which  * expire in a 2**(NTP_MINPOLL-1) (8) second period.  The timers in  * each slot are sorted by increasing expiry time.  The number of  * slots is 2**(NTP_MAXPOLL-(NTP_MINPOLL-1)), or 128, to cover a time  * period of 2**NTP_MAXPOLL (1024) seconds into the future before  * wrapping.  */
end_comment

begin_define
define|#
directive|define
name|EVENT_TIMEOUT
value|CLOCK_ADJ
end_define

begin_struct
struct|struct
name|event
block|{
name|struct
name|event
modifier|*
name|next
decl_stmt|;
comment|/* next in chain */
name|struct
name|event
modifier|*
name|prev
decl_stmt|;
comment|/* previous in chain */
name|struct
name|peer
modifier|*
name|peer
decl_stmt|;
comment|/* peer this counter belongs to */
name|void
function_decl|(
modifier|*
name|event_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call to handle event */
name|U_LONG
name|event_time
decl_stmt|;
comment|/* expiry time of counter */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIMER_SLOTTIME
value|(1<<(NTP_MINPOLL-1))
end_define

begin_define
define|#
directive|define
name|TIMER_NSLOTS
value|(1<<(NTP_MAXPOLL-(NTP_MINPOLL-1)))
end_define

begin_define
define|#
directive|define
name|TIMER_SLOT
parameter_list|(
name|t
parameter_list|)
value|(((t)>> (NTP_MINPOLL-1))& (TIMER_NSLOTS-1))
end_define

begin_comment
comment|/*  * TIMER_ENQUEUE() puts stuff on the timer queue.  It takes as  * arguments (ea), an array of event slots, and (iev), the event  * to be inserted.  This one searches the hash bucket from the  * end, and is about optimum for the timing requirements of  * NTP peers.  */
end_comment

begin_define
define|#
directive|define
name|TIMER_ENQUEUE
parameter_list|(
name|ea
parameter_list|,
name|iev
parameter_list|)
define|\
value|do { \ 		register struct event *ev; \ 		\ 		ev = (ea)[TIMER_SLOT((iev)->event_time)].prev; \ 		while (ev->event_time> (iev)->event_time) \ 			ev = ev->prev; \ 		(iev)->prev = ev; \ 		(iev)->next = ev->next; \ 		(ev)->next->prev = (iev); \ 		(ev)->next = (iev); \ 	} while(0)
end_define

begin_comment
comment|/*  * TIMER_INSERT() also puts stuff on the timer queue, but searches the  * bucket from the top.  This is better for things that do very short  * time outs, like clock support.  */
end_comment

begin_define
define|#
directive|define
name|TIMER_INSERT
parameter_list|(
name|ea
parameter_list|,
name|iev
parameter_list|)
define|\
value|do { \ 		register struct event *ev; \ 		\ 		ev = (ea)[TIMER_SLOT((iev)->event_time)].next; \ 		while (ev->event_time != 0&& \ 		    ev->event_time< (iev)->event_time) \ 			ev = ev->next; \ 		(iev)->next = ev; \ 		(iev)->prev = ev->prev; \ 		(ev)->prev->next = (iev); \ 		(ev)->prev = (iev); \ 	} while(0)
end_define

begin_comment
comment|/*  * Remove an event from the queue.  */
end_comment

begin_define
define|#
directive|define
name|TIMER_DEQUEUE
parameter_list|(
name|ev
parameter_list|)
define|\
value|do { \ 		if ((ev)->next != 0) { \ 			(ev)->next->prev = (ev)->prev; \ 			(ev)->prev->next = (ev)->next; \ 			(ev)->next = (ev)->prev = 0; \ 		} \ 	} while (0)
end_define

begin_comment
comment|/*  * The interface structure is used to hold the addresses and socket  * numbers of each of the interfaces we are using.  */
end_comment

begin_struct
struct|struct
name|interface
block|{
name|int
name|fd
decl_stmt|;
comment|/* socket this is opened on */
name|int
name|bfd
decl_stmt|;
comment|/* socket for receiving broadcasts */
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
comment|/* interface address */
name|struct
name|sockaddr_in
name|bcast
decl_stmt|;
comment|/* broadcast address */
name|struct
name|sockaddr_in
name|mask
decl_stmt|;
comment|/* interface mask */
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* name of interface */
name|int
name|flags
decl_stmt|;
comment|/* interface flags */
name|LONG
name|received
decl_stmt|;
comment|/* number of incoming packets */
name|LONG
name|sent
decl_stmt|;
comment|/* number of outgoing packets */
name|LONG
name|notsent
decl_stmt|;
comment|/* number of send failures */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for interfaces  */
end_comment

begin_define
define|#
directive|define
name|INT_BROADCAST
value|1
end_define

begin_comment
comment|/* can broadcast out this interface */
end_comment

begin_define
define|#
directive|define
name|INT_BCASTOPEN
value|2
end_define

begin_comment
comment|/* broadcast socket is open */
end_comment

begin_define
define|#
directive|define
name|INT_LOOPBACK
value|4
end_define

begin_comment
comment|/* the loopback interface */
end_comment

begin_define
define|#
directive|define
name|INT_MULTICAST
value|8
end_define

begin_comment
comment|/* multicasting enabled */
end_comment

begin_comment
comment|/*  * Define flasher bits (tests 1 through 8 in packet procedure)  * These reveal the state at the last grumble from the peer and are  * most handy for diagnosing problems, even if not strictly a state  * variable in the spec. These are recorded in the peer structure.  */
end_comment

begin_define
define|#
directive|define
name|TEST1
value|0x01
end_define

begin_comment
comment|/* duplicate packet received */
end_comment

begin_define
define|#
directive|define
name|TEST2
value|0x02
end_define

begin_comment
comment|/* bogus packet received */
end_comment

begin_define
define|#
directive|define
name|TEST3
value|0x04
end_define

begin_comment
comment|/* protocol unsynchronized */
end_comment

begin_define
define|#
directive|define
name|TEST4
value|0x08
end_define

begin_comment
comment|/* peer delay/dispersion bounds check */
end_comment

begin_define
define|#
directive|define
name|TEST5
value|0x10
end_define

begin_comment
comment|/* peer authentication failed */
end_comment

begin_define
define|#
directive|define
name|TEST6
value|0x20
end_define

begin_comment
comment|/* peer clock unsynchronized */
end_comment

begin_define
define|#
directive|define
name|TEST7
value|0x40
end_define

begin_comment
comment|/* peer stratum out of bounds */
end_comment

begin_define
define|#
directive|define
name|TEST8
value|0x80
end_define

begin_comment
comment|/* root delay/dispersion bounds check */
end_comment

begin_comment
comment|/*  * The peer structure.  Holds state information relating to the guys  * we are peering with.  Most of this stuff is from section 3.2 of the  * spec.  */
end_comment

begin_struct
struct|struct
name|peer
block|{
name|struct
name|peer
modifier|*
name|next
decl_stmt|;
name|struct
name|peer
modifier|*
name|ass_next
decl_stmt|;
comment|/* link pointer in associd hash */
name|struct
name|sockaddr_in
name|srcadr
decl_stmt|;
comment|/* address of remote host */
name|struct
name|interface
modifier|*
name|dstadr
decl_stmt|;
comment|/* pointer to address on local host */
name|u_char
name|leap
decl_stmt|;
comment|/* leap indicator */
name|u_char
name|hmode
decl_stmt|;
comment|/* association mode with this peer */
name|u_char
name|pmode
decl_stmt|;
comment|/* peer's association mode */
name|u_char
name|stratum
decl_stmt|;
comment|/* stratum of remote peer */
name|s_char
name|precision
decl_stmt|;
comment|/* peer's clock precision */
name|u_char
name|ppoll
decl_stmt|;
comment|/* peer poll interval */
name|u_char
name|hpoll
decl_stmt|;
comment|/* local host poll interval */
name|u_char
name|minpoll
decl_stmt|;
comment|/* min local host poll interval */
name|u_char
name|maxpoll
decl_stmt|;
comment|/* max local host poll interval */
name|u_char
name|version
decl_stmt|;
comment|/* version number */
name|u_char
name|flags
decl_stmt|;
comment|/* peer flags */
name|u_char
name|flash
decl_stmt|;
comment|/* peer flashers (for maint) */
name|u_char
name|refclktype
decl_stmt|;
comment|/* reference clock type */
name|u_char
name|refclkunit
decl_stmt|;
comment|/* reference clock unit number */
name|u_char
name|sstclktype
decl_stmt|;
comment|/* clock type for system status word */
name|s_fp
name|rootdelay
decl_stmt|;
comment|/* distance from primary clock */
name|u_fp
name|rootdispersion
decl_stmt|;
comment|/* peer clock dispersion */
name|U_LONG
name|refid
decl_stmt|;
comment|/* peer reference ID */
name|l_fp
name|reftime
decl_stmt|;
comment|/* time of peer's last update */
name|struct
name|event
name|event_timer
decl_stmt|;
comment|/* event queue entry */
name|U_LONG
name|keyid
decl_stmt|;
comment|/* encription key ID */
name|U_LONG
name|pkeyid
decl_stmt|;
comment|/* keyid used to encrypt last message */
name|u_short
name|associd
decl_stmt|;
comment|/* association ID, a unique integer */
name|u_char
name|ttl
decl_stmt|;
comment|/* time to live (multicast) */
comment|/* **Start of clear-to-zero area.*** */
comment|/* Everything that is cleared to zero goes below here */
name|u_char
name|valid
decl_stmt|;
comment|/* valid counter */
define|#
directive|define
name|clear_to_zero
value|valid
name|u_char
name|reach
decl_stmt|;
comment|/* reachability, NTP_WINDOW bits */
name|u_char
name|unreach
decl_stmt|;
comment|/* unreachable count */
name|u_short
name|filter_nextpt
decl_stmt|;
comment|/* index into filter shift register */
name|s_fp
name|filter_delay
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* delay part of shift register */
name|l_fp
name|filter_offset
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* offset part of shift register */
name|s_fp
name|filter_soffset
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* offset in s_fp format, for disp */
name|l_fp
name|org
decl_stmt|;
comment|/* originate time stamp */
name|l_fp
name|rec
decl_stmt|;
comment|/* receive time stamp */
name|l_fp
name|xmt
decl_stmt|;
comment|/* transmit time stamp */
comment|/* ***End of clear-to-zero area.*** */
comment|/* Everything that is cleared to zero goes above here */
name|u_char
name|filter_order
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* we keep the filter sorted here */
define|#
directive|define
name|end_clear_to_zero
value|filter_order[0]
name|u_fp
name|filter_error
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* error part of shift register */
name|LONG
name|update
decl_stmt|;
comment|/* base sys_clock for skew calc.s */
name|s_fp
name|delay
decl_stmt|;
comment|/* filter estimated delay */
name|u_fp
name|dispersion
decl_stmt|;
comment|/* filter estimated dispersion */
name|l_fp
name|offset
decl_stmt|;
comment|/* filter estimated clock offset */
name|s_fp
name|soffset
decl_stmt|;
comment|/* fp version of above */
name|s_fp
name|synch
decl_stmt|;
comment|/* synch distance from above */
name|u_fp
name|selectdisp
decl_stmt|;
comment|/* select dispersion */
name|U_LONG
name|estbdelay
decl_stmt|;
comment|/* broadcast delay, as a ts fraction */
comment|/* 	 * statistic counters 	 */
name|U_LONG
name|timereset
decl_stmt|;
comment|/* time stat counters were reset */
name|U_LONG
name|sent
decl_stmt|;
comment|/* number of updates sent */
name|U_LONG
name|received
decl_stmt|;
comment|/* number of frames received */
name|U_LONG
name|timereceived
decl_stmt|;
comment|/* last time a frame received */
name|U_LONG
name|timereachable
decl_stmt|;
comment|/* last reachable/unreachable event */
name|U_LONG
name|processed
decl_stmt|;
comment|/* processed by the protocol */
name|U_LONG
name|badauth
decl_stmt|;
comment|/* bad credentials detected */
name|U_LONG
name|bogusorg
decl_stmt|;
comment|/* rejected due to bogus origin */
name|U_LONG
name|bogusrec
decl_stmt|;
comment|/* rejected due to bogus receive */
name|U_LONG
name|bogusdelay
decl_stmt|;
comment|/* rejected due to bogus delay */
name|U_LONG
name|disttoolarge
decl_stmt|;
comment|/* rejected due to large distance */
name|U_LONG
name|oldpkt
decl_stmt|;
comment|/* rejected as duplicate packet */
name|U_LONG
name|seldisptoolarge
decl_stmt|;
comment|/* too much dispersion for selection */
name|U_LONG
name|selbroken
decl_stmt|;
comment|/* broken NTP detected in selection */
name|U_LONG
name|seltooold
decl_stmt|;
comment|/* too LONG since sync in selection */
name|u_char
name|candidate
decl_stmt|;
comment|/* position after candidate selection */
name|u_char
name|select
decl_stmt|;
comment|/* position at end of falseticker sel */
name|u_char
name|was_sane
decl_stmt|;
comment|/* set to 1 if it passed sanity check */
name|u_char
name|correct
decl_stmt|;
comment|/* set to 1 if it passed correctness check */
name|u_char
name|last_event
decl_stmt|;
comment|/* set to code for last peer error */
name|u_char
name|num_events
decl_stmt|;
comment|/* num. of events which have occurred */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values for peer.leap, sys_leap  */
end_comment

begin_define
define|#
directive|define
name|LEAP_NOWARNING
value|0x0
end_define

begin_comment
comment|/* normal, no leap second warning */
end_comment

begin_define
define|#
directive|define
name|LEAP_ADDSECOND
value|0x1
end_define

begin_comment
comment|/* last minute of day has 61 seconds */
end_comment

begin_define
define|#
directive|define
name|LEAP_DELSECOND
value|0x2
end_define

begin_comment
comment|/* last minute of day has 59 seconds */
end_comment

begin_define
define|#
directive|define
name|LEAP_NOTINSYNC
value|0x3
end_define

begin_comment
comment|/* overload, clock is free running */
end_comment

begin_comment
comment|/*  * Values for peer.mode  */
end_comment

begin_define
define|#
directive|define
name|MODE_UNSPEC
value|0
end_define

begin_comment
comment|/* unspecified (probably old NTP version) */
end_comment

begin_define
define|#
directive|define
name|MODE_ACTIVE
value|1
end_define

begin_comment
comment|/* symmetric active */
end_comment

begin_define
define|#
directive|define
name|MODE_PASSIVE
value|2
end_define

begin_comment
comment|/* symmetric passive */
end_comment

begin_define
define|#
directive|define
name|MODE_CLIENT
value|3
end_define

begin_comment
comment|/* client mode */
end_comment

begin_define
define|#
directive|define
name|MODE_SERVER
value|4
end_define

begin_comment
comment|/* server mode */
end_comment

begin_define
define|#
directive|define
name|MODE_BROADCAST
value|5
end_define

begin_comment
comment|/* broadcast mode */
end_comment

begin_define
define|#
directive|define
name|MODE_CONTROL
value|6
end_define

begin_comment
comment|/* control mode packet */
end_comment

begin_define
define|#
directive|define
name|MODE_PRIVATE
value|7
end_define

begin_comment
comment|/* implementation defined function */
end_comment

begin_define
define|#
directive|define
name|MODE_BCLIENT
value|8
end_define

begin_comment
comment|/* a pseudo mode, used internally */
end_comment

begin_comment
comment|/*  * Values for peer.stratum, sys_stratum  */
end_comment

begin_define
define|#
directive|define
name|STRATUM_REFCLOCK
value|((u_char)0)
end_define

begin_comment
comment|/* stratum claimed by primary clock */
end_comment

begin_define
define|#
directive|define
name|STRATUM_PRIMARY
value|((u_char)1)
end_define

begin_comment
comment|/* host has a primary clock */
end_comment

begin_define
define|#
directive|define
name|STRATUM_INFIN
value|((u_char)NTP_MAXSTRATUM)
end_define

begin_comment
comment|/* infinity a la Bellman-Ford */
end_comment

begin_comment
comment|/* A stratum of 0 in the packet is mapped to 16 internally */
end_comment

begin_define
define|#
directive|define
name|STRATUM_PKT_UNSPEC
value|((u_char)0)
end_define

begin_comment
comment|/* unspecified in packet */
end_comment

begin_define
define|#
directive|define
name|STRATUM_UNSPEC
value|((u_char)(NTP_MAXSTRATUM+(u_char)1))
end_define

begin_comment
comment|/* unspecified */
end_comment

begin_comment
comment|/*  * Values for peer.flags  */
end_comment

begin_define
define|#
directive|define
name|FLAG_CONFIG
value|0x1
end_define

begin_comment
comment|/* association was configured */
end_comment

begin_define
define|#
directive|define
name|FLAG_AUTHENABLE
value|0x2
end_define

begin_comment
comment|/* this guy needs authentication */
end_comment

begin_define
define|#
directive|define
name|FLAG_UNUSED
value|0x4
end_define

begin_comment
comment|/* (not used) */
end_comment

begin_define
define|#
directive|define
name|FLAG_DEFBDELAY
value|0x8
end_define

begin_comment
comment|/* using default bdelay */
end_comment

begin_define
define|#
directive|define
name|FLAG_AUTHENTIC
value|0x10
end_define

begin_comment
comment|/* last message was authentic */
end_comment

begin_define
define|#
directive|define
name|FLAG_REFCLOCK
value|0x20
end_define

begin_comment
comment|/* this is actually a reference clock */
end_comment

begin_define
define|#
directive|define
name|FLAG_SYSPEER
value|0x40
end_define

begin_comment
comment|/* this is one of the selected peers */
end_comment

begin_define
define|#
directive|define
name|FLAG_PREFER
value|0x80
end_define

begin_comment
comment|/* this is the preferred peer */
end_comment

begin_comment
comment|/*  * Definitions for the clear() routine.  We use memset() to clear  * the parts of the peer structure which go to zero.  These are  * used to calculate the start address and length of the area.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_TO_ZERO
parameter_list|(
name|p
parameter_list|)
value|((char *)&((p)->clear_to_zero))
end_define

begin_define
define|#
directive|define
name|END_CLEAR_TO_ZERO
parameter_list|(
name|p
parameter_list|)
value|((char *)&((p)->end_clear_to_zero))
end_define

begin_define
define|#
directive|define
name|LEN_CLEAR_TO_ZERO
value|(END_CLEAR_TO_ZERO((struct peer *)0) \ 				    - CLEAR_TO_ZERO((struct peer *)0))
end_define

begin_comment
comment|/*  * Reference clock identifiers (for pps signal)  */
end_comment

begin_define
define|#
directive|define
name|PPSREFID
value|"PPS "
end_define

begin_comment
comment|/* used when pps controls stratum> 1 */
end_comment

begin_comment
comment|/*  * Reference clock types.  Added as necessary.  */
end_comment

begin_define
define|#
directive|define
name|REFCLK_NONE
value|0
end_define

begin_comment
comment|/* unknown or missing */
end_comment

begin_define
define|#
directive|define
name|REFCLK_LOCALCLOCK
value|1
end_define

begin_comment
comment|/* external (e.g., ACTS) */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPS_TRAK
value|2
end_define

begin_comment
comment|/* TRAK 8810 GPS Receiver */
end_comment

begin_define
define|#
directive|define
name|REFCLK_WWV_PST
value|3
end_define

begin_comment
comment|/* PST/Traconex 1020 WWV/H */
end_comment

begin_define
define|#
directive|define
name|REFCLK_WWVB_SPECTRACOM
value|4
end_define

begin_comment
comment|/* Spectracom 8170/Netclock WWVB */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GOES_TRUETIME
value|5
end_define

begin_comment
comment|/* TrueTime 468-DC GOES */
end_comment

begin_define
define|#
directive|define
name|REFCLK_IRIG_AUDIO
value|6
end_define

begin_comment
comment|/* IRIG-B audio decoder */
end_comment

begin_define
define|#
directive|define
name|REFCLK_CHU
value|7
end_define

begin_comment
comment|/* scratchbuilt CHU (Canada) */
end_comment

begin_define
define|#
directive|define
name|REFCLK_PARSE
value|8
end_define

begin_comment
comment|/* generic driver (usually DCF77,GPS) */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPS_MX4200
value|9
end_define

begin_comment
comment|/* Magnavox MX4200 GPS */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPS_AS2201
value|10
end_define

begin_comment
comment|/* Austron 2201A GPS */
end_comment

begin_define
define|#
directive|define
name|REFCLK_OMEGA_TRUETIME
value|11
end_define

begin_comment
comment|/* TrueTime OM-DC OMEGA */
end_comment

begin_define
define|#
directive|define
name|REFCLK_IRIG_TPRO
value|12
end_define

begin_comment
comment|/* KSI/Odetics TPRO-S IRIG */
end_comment

begin_define
define|#
directive|define
name|REFCLK_ATOM_LEITCH
value|13
end_define

begin_comment
comment|/* Leitch CSD 5300 Master Clock */
end_comment

begin_define
define|#
directive|define
name|REFCLK_MSF_EES
value|14
end_define

begin_comment
comment|/* MSF EES M201, UK */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPSTM_TRUETIME
value|15
end_define

begin_comment
comment|/* TrueTime GPS/TM-TMD */
end_comment

begin_comment
comment|/*  * We tell reference clocks from real peers by giving the reference  * clocks an address of the form 127.127.t.u, where t is the type and  * u is the unit number.  We define some of this here since we will need  * some sanity checks to make sure this address isn't interpretted as  * that of a normal peer.  */
end_comment

begin_define
define|#
directive|define
name|REFCLOCK_ADDR
value|0x7f7f0000
end_define

begin_comment
comment|/* 127.127.0.0 */
end_comment

begin_define
define|#
directive|define
name|REFCLOCK_MASK
value|0xffff0000
end_define

begin_comment
comment|/* 255.255.0.0 */
end_comment

begin_define
define|#
directive|define
name|ISREFCLOCKADR
parameter_list|(
name|srcadr
parameter_list|)
value|((SRCADR(srcadr)& REFCLOCK_MASK) \ 					== REFCLOCK_ADDR)
end_define

begin_comment
comment|/*  * Macro for checking for invalid addresses.  This is really, really  * gross, but is needed so no one configures a host on net 127 now that  * we're encouraging it the the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|LOOPBACKADR
value|0x7f000001
end_define

begin_define
define|#
directive|define
name|LOOPNETMASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|ISBADADR
parameter_list|(
name|srcadr
parameter_list|)
value|(((SRCADR(srcadr)& LOOPNETMASK) \ 				    == (LOOPBACKADR& LOOPNETMASK)) \&& (SRCADR(srcadr) != LOOPBACKADR))
end_define

begin_comment
comment|/*  * Utilities for manipulating addresses and port numbers  */
end_comment

begin_define
define|#
directive|define
name|NSRCADR
parameter_list|(
name|src
parameter_list|)
value|((src)->sin_addr.s_addr)
end_define

begin_comment
comment|/* address in net byte order */
end_comment

begin_define
define|#
directive|define
name|NSRCPORT
parameter_list|(
name|src
parameter_list|)
value|((src)->sin_port)
end_define

begin_comment
comment|/* port in net byte order */
end_comment

begin_define
define|#
directive|define
name|SRCADR
parameter_list|(
name|src
parameter_list|)
value|(ntohl(NSRCADR((src))))
end_define

begin_comment
comment|/* address in host byte order */
end_comment

begin_define
define|#
directive|define
name|SRCPORT
parameter_list|(
name|src
parameter_list|)
value|(ntohs(NSRCPORT((src))))
end_define

begin_comment
comment|/* host port */
end_comment

begin_comment
comment|/*  * NTP packet format.  The mac field is optional.  It isn't really  * an l_fp either, but for now declaring it that way is convenient.  * See Appendix A in the specification.  *  * Note that all u_fp and l_fp values arrive in network byte order  * and must be converted (except the mac, which isn't, really).  */
end_comment

begin_struct
struct|struct
name|pkt
block|{
name|u_char
name|li_vn_mode
decl_stmt|;
comment|/* contains leap indicator, version and mode */
name|u_char
name|stratum
decl_stmt|;
comment|/* peer's stratum */
name|u_char
name|ppoll
decl_stmt|;
comment|/* the peer polling interval */
name|s_char
name|precision
decl_stmt|;
comment|/* peer clock precision */
name|s_fp
name|rootdelay
decl_stmt|;
comment|/* distance to primary clock */
name|u_fp
name|rootdispersion
decl_stmt|;
comment|/* clock dispersion */
name|U_LONG
name|refid
decl_stmt|;
comment|/* reference clock ID */
name|l_fp
name|reftime
decl_stmt|;
comment|/* time peer clock was last updated */
name|l_fp
name|org
decl_stmt|;
comment|/* originate time stamp */
name|l_fp
name|rec
decl_stmt|;
comment|/* receive time stamp */
name|l_fp
name|xmt
decl_stmt|;
comment|/* transmit time stamp */
define|#
directive|define
name|MIN_MAC_LEN
value|(sizeof(U_LONG) + 8)
comment|/* DES */
define|#
directive|define
name|MAX_MAC_LEN
value|(sizeof(U_LONG) + 16)
comment|/* MD5 */
name|U_LONG
name|keyid
decl_stmt|;
comment|/* key identification */
name|u_char
name|mac
index|[
name|MAX_MAC_LEN
operator|-
sizeof|sizeof
argument_list|(
name|U_LONG
argument_list|)
index|]
decl_stmt|;
comment|/* message-authentication code */
comment|/*l_fp mac;*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Packets can come in two flavours, one with a mac and one without.  */
end_comment

begin_define
define|#
directive|define
name|LEN_PKT_NOMAC
value|(sizeof(struct pkt) - MAX_MAC_LEN)
end_define

begin_comment
comment|/*  * Minimum size of packet with a MAC: has to include at least a key number.  */
end_comment

begin_define
define|#
directive|define
name|LEN_PKT_MAC
value|(LEN_PKT_NOMAC + sizeof(U_LONG))
end_define

begin_comment
comment|/*  * Stuff for extracting things from li_vn_mode  */
end_comment

begin_define
define|#
directive|define
name|PKT_MODE
parameter_list|(
name|li_vn_mode
parameter_list|)
value|((u_char)((li_vn_mode)& 0x7))
end_define

begin_define
define|#
directive|define
name|PKT_VERSION
parameter_list|(
name|li_vn_mode
parameter_list|)
value|((u_char)(((li_vn_mode)>> 3)& 0x7))
end_define

begin_define
define|#
directive|define
name|PKT_LEAP
parameter_list|(
name|li_vn_mode
parameter_list|)
value|((u_char)(((li_vn_mode)>> 6)& 0x3))
end_define

begin_comment
comment|/*  * Stuff for putting things back into li_vn_mode  */
end_comment

begin_define
define|#
directive|define
name|PKT_LI_VN_MODE
parameter_list|(
name|li
parameter_list|,
name|vn
parameter_list|,
name|md
parameter_list|)
define|\
value|((u_char)((((li)<< 6)& 0xc0) | (((vn)<< 3)& 0x38) | ((md)& 0x7)))
end_define

begin_comment
comment|/*  * Dealing with stratum.  0 gets mapped to 16 incoming, and back to 0  * on output.  */
end_comment

begin_define
define|#
directive|define
name|PKT_TO_STRATUM
parameter_list|(
name|s
parameter_list|)
value|((u_char)(((s) == (STRATUM_PKT_UNSPEC)) ?\ 				(STRATUM_UNSPEC) : (s)))
end_define

begin_define
define|#
directive|define
name|STRATUM_TO_PKT
parameter_list|(
name|s
parameter_list|)
value|((u_char)(((s) == (STRATUM_UNSPEC)) ?\ 				(STRATUM_PKT_UNSPEC) : (s)))
end_define

begin_comment
comment|/*  * Format of a recvbuf.  These are used by the asynchronous receive  * routine to store incoming packets and related information.  */
end_comment

begin_comment
comment|/*  *  the maximum length NTP packet is a full length NTP control message with  *  the maximum length message authenticator.  I hate to hard-code 468 and 12,  *  but only a few modules include ntp_control.h...  */
end_comment

begin_define
define|#
directive|define
name|RX_BUFF_SIZE
value|(468+12+MAX_MAC_LEN)
end_define

begin_struct
struct|struct
name|recvbuf
block|{
name|struct
name|recvbuf
modifier|*
name|next
decl_stmt|;
comment|/* next buffer in chain */
union|union
block|{
name|struct
name|sockaddr_in
name|X_recv_srcadr
decl_stmt|;
name|caddr_t
name|X_recv_srcclock
decl_stmt|;
block|}
name|X_from_where
union|;
define|#
directive|define
name|recv_srcadr
value|X_from_where.X_recv_srcadr
define|#
directive|define
name|recv_srcclock
value|X_from_where.X_recv_srcclock
name|struct
name|sockaddr_in
name|srcadr
decl_stmt|;
comment|/* where packet came from */
name|struct
name|interface
modifier|*
name|dstadr
decl_stmt|;
comment|/* interface datagram arrived thru */
name|l_fp
name|recv_time
decl_stmt|;
comment|/* time of arrival */
name|void
function_decl|(
modifier|*
name|receiver
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to receive buffer */
name|int
name|recv_length
decl_stmt|;
comment|/* number of octets received */
union|union
block|{
name|struct
name|pkt
name|X_recv_pkt
decl_stmt|;
name|char
name|X_recv_buffer
index|[
name|RX_BUFF_SIZE
index|]
decl_stmt|;
block|}
name|recv_space
union|;
define|#
directive|define
name|recv_pkt
value|recv_space.X_recv_pkt
define|#
directive|define
name|recv_buffer
value|recv_space.X_recv_buffer
block|}
struct|;
end_struct

begin_comment
comment|/*  * Event codes.  Used for reporting errors/events to the control module  */
end_comment

begin_define
define|#
directive|define
name|PEER_EVENT
value|0x80
end_define

begin_comment
comment|/* this is a peer event */
end_comment

begin_define
define|#
directive|define
name|EVNT_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|EVNT_SYSRESTART
value|1
end_define

begin_define
define|#
directive|define
name|EVNT_SYSFAULT
value|2
end_define

begin_define
define|#
directive|define
name|EVNT_SYNCCHG
value|3
end_define

begin_define
define|#
directive|define
name|EVNT_PEERSTCHG
value|4
end_define

begin_define
define|#
directive|define
name|EVNT_CLOCKRESET
value|5
end_define

begin_define
define|#
directive|define
name|EVNT_BADDATETIM
value|6
end_define

begin_define
define|#
directive|define
name|EVNT_CLOCKEXCPT
value|7
end_define

begin_define
define|#
directive|define
name|EVNT_PEERIPERR
value|(1|PEER_EVENT)
end_define

begin_define
define|#
directive|define
name|EVNT_PEERAUTH
value|(2|PEER_EVENT)
end_define

begin_define
define|#
directive|define
name|EVNT_UNREACH
value|(3|PEER_EVENT)
end_define

begin_define
define|#
directive|define
name|EVNT_REACH
value|(4|PEER_EVENT)
end_define

begin_define
define|#
directive|define
name|EVNT_PEERCLOCK
value|(5|PEER_EVENT)
end_define

begin_comment
comment|/*  * Clock event codes  */
end_comment

begin_define
define|#
directive|define
name|CEVNT_NOMINAL
value|0
end_define

begin_define
define|#
directive|define
name|CEVNT_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|CEVNT_BADREPLY
value|2
end_define

begin_define
define|#
directive|define
name|CEVNT_FAULT
value|3
end_define

begin_define
define|#
directive|define
name|CEVNT_PROP
value|4
end_define

begin_define
define|#
directive|define
name|CEVNT_BADDATE
value|5
end_define

begin_define
define|#
directive|define
name|CEVNT_BADTIME
value|6
end_define

begin_define
define|#
directive|define
name|CEVNT_MAX
value|CEVNT_BADTIME
end_define

begin_comment
comment|/*  * Very misplaced value.  Default port through which we send traps.  */
end_comment

begin_define
define|#
directive|define
name|TRAPPORT
value|18447
end_define

begin_comment
comment|/*  * To speed lookups, peers are hashed by the low order bits of the remote  * IP address.  These definitions relate to that.  */
end_comment

begin_define
define|#
directive|define
name|HASH_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|HASH_MASK
value|(HASH_SIZE-1)
end_define

begin_define
define|#
directive|define
name|HASH_ADDR
parameter_list|(
name|src
parameter_list|)
value|((SRCADR((src))^(SRCADR((src))>>8))& HASH_MASK)
end_define

begin_comment
comment|/*  * The poll update procedure takes an extra argument which controls  * how a random perturbation is applied to peer.timer.  The choice is  * to not randomize at all, to randomize only if we're going to update  * peer.timer, and to randomize no matter what (almost, the algorithm  * is that we apply the random value if it is less than the current  * timer count).  */
end_comment

begin_define
define|#
directive|define
name|POLL_NOTRANDOM
value|0
end_define

begin_comment
comment|/* don't randomize */
end_comment

begin_define
define|#
directive|define
name|POLL_RANDOMCHANGE
value|1
end_define

begin_comment
comment|/* if you change, change randomly */
end_comment

begin_define
define|#
directive|define
name|POLL_MAKERANDOM
value|2
end_define

begin_comment
comment|/* randomize next interval */
end_comment

begin_comment
comment|/*  * How we randomize polls.  The poll interval is a power of two.  * We chose a random value which is between 1/4 and 3/4 of the  * poll interval we would normally use and which is an even multiple  * of the EVENT_TIMEOUT.  The random number routine, given an argument  * spread value of n, returns an integer between 0 and (1<<n)-1.  This  * is shifted by EVENT_TIMEOUT and added to the base value.  */
end_comment

begin_define
define|#
directive|define
name|RANDOM_SPREAD
parameter_list|(
name|poll
parameter_list|)
value|((poll) - (EVENT_TIMEOUT+1))
end_define

begin_define
define|#
directive|define
name|RANDOM_POLL
parameter_list|(
name|poll
parameter_list|,
name|rval
parameter_list|)
value|((((rval)+1)<<EVENT_TIMEOUT) + (1<<((poll)-2)))
end_define

begin_comment
comment|/*  * min, min3 and max.  Makes it easier to transliterate the spec without  * thinking about it.  */
end_comment

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|min3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|min(min((a),(b)), (c))
end_define

begin_comment
comment|/*  * Configuration items.  These are for the protocol module (proto_config())  */
end_comment

begin_define
define|#
directive|define
name|PROTO_BROADCLIENT
value|1
end_define

begin_define
define|#
directive|define
name|PROTO_PRECISION
value|2
end_define

begin_define
define|#
directive|define
name|PROTO_AUTHENTICATE
value|3
end_define

begin_define
define|#
directive|define
name|PROTO_BROADDELAY
value|4
end_define

begin_define
define|#
directive|define
name|PROTO_AUTHDELAY
value|5
end_define

begin_define
define|#
directive|define
name|PROTO_MULTICAST_ADD
value|6
end_define

begin_define
define|#
directive|define
name|PROTO_MULTICAST_DEL
value|7
end_define

begin_comment
comment|/*  * Configuration items for the loop filter  */
end_comment

begin_define
define|#
directive|define
name|LOOP_DRIFTCOMP
value|1
end_define

begin_comment
comment|/* set frequency offset */
end_comment

begin_define
define|#
directive|define
name|LOOP_PPSDELAY
value|2
end_define

begin_comment
comment|/* set pps delay */
end_comment

begin_define
define|#
directive|define
name|LOOP_PPSBAUD
value|3
end_define

begin_comment
comment|/* set pps baud rate */
end_comment

begin_comment
comment|/*  * Configuration items for the stats printer  */
end_comment

begin_define
define|#
directive|define
name|STATS_FREQ_FILE
value|1
end_define

begin_comment
comment|/* configure drift file */
end_comment

begin_define
define|#
directive|define
name|STATS_STATSDIR
value|2
end_define

begin_comment
comment|/* directory prefix for stats files */
end_comment

begin_define
define|#
directive|define
name|STATS_PID_FILE
value|3
end_define

begin_comment
comment|/* configure xntpd PID file */
end_comment

begin_define
define|#
directive|define
name|MJD_1970
value|40587
end_define

begin_comment
comment|/* MJD for 1 Jan 1970 */
end_comment

begin_comment
comment|/*  * Default parameters.  We use these in the absense of something better.  */
end_comment

begin_define
define|#
directive|define
name|DEFPRECISION
value|(-5)
end_define

begin_comment
comment|/* conservatively low */
end_comment

begin_define
define|#
directive|define
name|DEFBROADDELAY
value|(0x020c49ba)
end_define

begin_comment
comment|/* 8 ms.  This is round trip delay */
end_comment

begin_define
define|#
directive|define
name|INADDR_NTP
value|0xe0000101
end_define

begin_comment
comment|/* NTP multicast address 224.0.1.1 */
end_comment

begin_comment
comment|/*  * Structure used optionally for monitoring when this is turned on.  */
end_comment

begin_struct
struct|struct
name|mon_data
block|{
name|struct
name|mon_data
modifier|*
name|hash_next
decl_stmt|;
comment|/* next structure in hash list */
name|struct
name|mon_data
modifier|*
name|hash_prev
decl_stmt|;
comment|/* previous structure in hash list */
name|struct
name|mon_data
modifier|*
name|mru_next
decl_stmt|;
comment|/* next structure in MRU list */
name|struct
name|mon_data
modifier|*
name|mru_prev
decl_stmt|;
comment|/* previous structure in MRU list */
name|struct
name|mon_data
modifier|*
name|fifo_next
decl_stmt|;
comment|/* next structure in FIFO list */
name|struct
name|mon_data
modifier|*
name|fifo_prev
decl_stmt|;
comment|/* previous structure in FIFO list */
name|U_LONG
name|lastdrop
decl_stmt|;
comment|/* last time dropped due to RES_LIMIT*/
name|U_LONG
name|lasttime
decl_stmt|;
comment|/* last time data updated */
name|U_LONG
name|firsttime
decl_stmt|;
comment|/* time structure initialized */
name|U_LONG
name|count
decl_stmt|;
comment|/* count we have seen */
name|U_LONG
name|rmtadr
decl_stmt|;
comment|/* address of remote host */
name|u_short
name|rmtport
decl_stmt|;
comment|/* remote port last came from */
name|u_char
name|mode
decl_stmt|;
comment|/* mode of incoming packet */
name|u_char
name|version
decl_stmt|;
comment|/* version of incoming packet */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values used with mon_enabled to indicate reason for enabling monitoring  */
end_comment

begin_define
define|#
directive|define
name|MON_OFF
value|0x00
end_define

begin_comment
comment|/* no monitoring */
end_comment

begin_define
define|#
directive|define
name|MON_ON
value|0x01
end_define

begin_comment
comment|/* monitoring explicitly enabled */
end_comment

begin_define
define|#
directive|define
name|MON_RES
value|0x02
end_define

begin_comment
comment|/* implicit monitoring for RES_LIMITED */
end_comment

begin_comment
comment|/*  * Structure used for restrictlist entries  */
end_comment

begin_struct
struct|struct
name|restrictlist
block|{
name|struct
name|restrictlist
modifier|*
name|next
decl_stmt|;
comment|/* link to next entry */
name|U_LONG
name|addr
decl_stmt|;
comment|/* host address (host byte order) */
name|U_LONG
name|mask
decl_stmt|;
comment|/* mask for address (host byte order) */
name|U_LONG
name|count
decl_stmt|;
comment|/* number of packets matched */
name|u_short
name|flags
decl_stmt|;
comment|/* accesslist flags */
name|u_short
name|mflags
decl_stmt|;
comment|/* match flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Access flags  */
end_comment

begin_define
define|#
directive|define
name|RES_IGNORE
value|0x1
end_define

begin_comment
comment|/* ignore if matched */
end_comment

begin_define
define|#
directive|define
name|RES_DONTSERVE
value|0x2
end_define

begin_comment
comment|/* don't give him any time */
end_comment

begin_define
define|#
directive|define
name|RES_DONTTRUST
value|0x4
end_define

begin_comment
comment|/* don't trust if matched */
end_comment

begin_define
define|#
directive|define
name|RES_NOQUERY
value|0x8
end_define

begin_comment
comment|/* don't allow queries if matched */
end_comment

begin_define
define|#
directive|define
name|RES_NOMODIFY
value|0x10
end_define

begin_comment
comment|/* don't allow him to modify server */
end_comment

begin_define
define|#
directive|define
name|RES_NOPEER
value|0x20
end_define

begin_comment
comment|/* don't allocate memory resources */
end_comment

begin_define
define|#
directive|define
name|RES_NOTRAP
value|0x40
end_define

begin_comment
comment|/* don't allow him to set traps */
end_comment

begin_define
define|#
directive|define
name|RES_LPTRAP
value|0x80
end_define

begin_comment
comment|/* traps set by him are low priority */
end_comment

begin_define
define|#
directive|define
name|RES_LIMITED
value|0x100
end_define

begin_comment
comment|/* limit per net number of clients */
end_comment

begin_define
define|#
directive|define
name|RES_ALLFLAGS
define|\
value|(RES_IGNORE|RES_DONTSERVE|RES_DONTTRUST|RES_NOQUERY\     |RES_NOMODIFY|RES_NOPEER|RES_NOTRAP|RES_LPTRAP|RES_LIMITED)
end_define

begin_comment
comment|/*  * Match flags  */
end_comment

begin_define
define|#
directive|define
name|RESM_INTERFACE
value|0x1
end_define

begin_comment
comment|/* this is an interface */
end_comment

begin_define
define|#
directive|define
name|RESM_NTPONLY
value|0x2
end_define

begin_comment
comment|/* match ntp port only */
end_comment

begin_comment
comment|/*  * Restriction configuration ops  */
end_comment

begin_define
define|#
directive|define
name|RESTRICT_FLAGS
value|1
end_define

begin_comment
comment|/* add flags to restrict entry */
end_comment

begin_define
define|#
directive|define
name|RESTRICT_UNFLAG
value|2
end_define

begin_comment
comment|/* remove flags from restrict entry */
end_comment

begin_define
define|#
directive|define
name|RESTRICT_REMOVE
value|3
end_define

begin_comment
comment|/* remove a restrict entry */
end_comment

begin_comment
comment|/*  * Experimental alternate selection algorithm identifiers  */
end_comment

begin_define
define|#
directive|define
name|SELECT_1
value|1
end_define

begin_define
define|#
directive|define
name|SELECT_2
value|2
end_define

begin_define
define|#
directive|define
name|SELECT_3
value|3
end_define

begin_define
define|#
directive|define
name|SELECT_4
value|4
end_define

begin_define
define|#
directive|define
name|SELECT_5
value|5
end_define

begin_comment
comment|/*  * Endpoint structure for the select algorithm  */
end_comment

begin_struct
struct|struct
name|endpoint
block|{
name|s_fp
name|val
decl_stmt|;
comment|/* offset of endpoint */
name|int
name|type
decl_stmt|;
comment|/* interval entry/exit */
block|}
struct|;
end_struct

end_unit

