begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp.h - NTP definitions for the masses  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_H
end_define

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/* common definitions for Y2K repairs			[ Y2KFixes */
end_comment

begin_comment
comment|/* (this might better be put in ntp_calendar.h) */
end_comment

begin_define
define|#
directive|define
name|YEAR_BREAK
value|500
end_define

begin_comment
comment|/* assume years< this are tm_year values: */
end_comment

begin_comment
comment|/*    Break< AnyFourDigitYear&& Break> Anytm_yearYear */
end_comment

begin_define
define|#
directive|define
name|YEAR_PIVOT
value|98
end_define

begin_comment
comment|/* 97/98: assume years< this are year 2000+ */
end_comment

begin_comment
comment|/* FYI: official UNIX pivot year is 68/69 */
end_comment

begin_comment
comment|/* Number of Days since (mythical) 1.BC Gregorian to 1 January of given year*/
end_comment

begin_define
define|#
directive|define
name|julian0
parameter_list|(
name|year
parameter_list|)
define|\
value|(	\ 	  ( (year) * 365 ) + ( (year)> 0  	\ 		? ( ((year)+3) / 4 - ((year-1) / 100) + ((year-1) / 400) )  \ 		: 0 ) \ 	)
end_define

begin_comment
comment|/* Number of days since start of NTP time to 1 January of given year */
end_comment

begin_define
define|#
directive|define
name|ntp0
parameter_list|(
name|year
parameter_list|)
value|( julian0(year) - julian0(1900) )
end_define

begin_comment
comment|/* Number of days since start of UNIX time to 1 January of given year */
end_comment

begin_define
define|#
directive|define
name|unix0
parameter_list|(
name|year
parameter_list|)
value|( julian0(year) - julian0(1970) )
end_define

begin_comment
comment|/* LEAP YEAR test for full 4-digit years (e.g, 1999, 2010) */
end_comment

begin_define
define|#
directive|define
name|isleap_4
parameter_list|(
name|y
parameter_list|)
comment|/* a TRUE and PROPER leap year test */
define|\
value|((y)%4 == 0&& !((y)%100 == 0&& !(y%400 == 0)))
end_define

begin_comment
comment|/* NOTE: year 2000 TRULY IS A LEAP YEAR!!! */
end_comment

begin_comment
comment|/* LEAP YEAR test for tm_year (struct tm) years (e.g, 99, 110) */
end_comment

begin_define
define|#
directive|define
name|isleap_tm
parameter_list|(
name|y
parameter_list|)
comment|/* a TRUE and PROPER leap year test */
define|\
value|((y)%4 == 0&& !((y)%100 == 0&& !(((y)+1900)%400 == 0)))
end_define

begin_comment
comment|/* to convert simple two-digit years to tm_year style years: 	if ( year< YEAR_PIVOT ) year += 100;     * to convert either two-digit OR tm_year years to four-digit years: 	if ( year< YEAR_PIVOT ) year += 100; 	if ( year< YEAR_BREAK ) year += 1900;   CALL TO STANDARD:    * As the Internet is an INTERNATIONAL network, it makes SENSE to use      the international standard ISO 8601 to format dates and times.      Basically this is yyyy-mm-dd for years and hh:mm:ss for times      (joining the two togeather in computer readable media calls for      yyyy-mm-ddThh:mm:ss, though yyyy-mm-dd hh:mm:ss is often used      for human readable forms even though it is not not strictly      valid ISO 8601). Standard time-zone offsets ([+-]hh:mm) are allowed. 					ghealton	         ] Y2KFixes */
end_comment

begin_comment
comment|/*  * How to get signed characters.  On machines where signed char works,  * use it.  On machines where signed char doesn't work, char had better  * be signed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_S_CHAR_TYPEDEF
end_ifdef

begin_if
if|#
directive|if
name|SIZEOF_SIGNED_CHAR
end_if

begin_typedef
typedef|typedef
name|signed
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
name|char
name|s_char
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX: Why is this sequent bit INSIDE this test? */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FALSE */
end_comment

begin_comment
comment|/*  * NTP protocol parameters.  See section 3.2.6 of the specification.  */
end_comment

begin_define
define|#
directive|define
name|NTP_VERSION
value|((u_char)4)
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
name|NTP_UNREACH
value|16
end_define

begin_comment
comment|/* poll interval backoff count */
end_comment

begin_define
define|#
directive|define
name|NTP_MINDPOLL
value|6
end_define

begin_comment
comment|/* log2 default min poll interval (64 s) */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXDPOLL
value|10
end_define

begin_comment
comment|/* log2 default max poll interval (~17 m) */
end_comment

begin_define
define|#
directive|define
name|NTP_MINPOLL
value|4
end_define

begin_comment
comment|/* log2 min poll interval (16 s) */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXPOLL
value|17
end_define

begin_comment
comment|/* log2 max poll interval (~4.5 h) */
end_comment

begin_define
define|#
directive|define
name|NTP_MINCLOCK
value|3
end_define

begin_comment
comment|/* minimum survivors */
end_comment

begin_define
define|#
directive|define
name|NTP_CANCLOCK
value|6
end_define

begin_comment
comment|/* minimum candidates */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXCLOCK
value|10
end_define

begin_comment
comment|/* maximum candidates */
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

begin_define
define|#
directive|define
name|NTP_MAXSESSION
value|100
end_define

begin_comment
comment|/* maximum entries on session key list */
end_comment

begin_define
define|#
directive|define
name|NTP_AUTOMAX
value|12
end_define

begin_comment
comment|/* log2 default max session key lifetime */
end_comment

begin_define
define|#
directive|define
name|KEY_REVOKE
value|16
end_define

begin_comment
comment|/* log2 default key revoke timeout */
end_comment

begin_define
define|#
directive|define
name|NTP_FWEIGHT
value|.5
end_define

begin_comment
comment|/* clock filter weight */
end_comment

begin_define
define|#
directive|define
name|NTP_SWEIGHT
value|.75
end_define

begin_comment
comment|/* select weight */
end_comment

begin_define
define|#
directive|define
name|CLOCK_SGATE
value|10.
end_define

begin_comment
comment|/* popcorn spike gate */
end_comment

begin_define
define|#
directive|define
name|BURST_INTERVAL1
value|4
end_define

begin_comment
comment|/* first interburst interval (log2) */
end_comment

begin_define
define|#
directive|define
name|BURST_INTERVAL2
value|1
end_define

begin_comment
comment|/* succeeding interburst intervals (log2) */
end_comment

begin_comment
comment|/*  * Operations for jitter (variance) calculations (these use doubles).  * Note that we carefully separate the jitter component from the dispersion  * component (frequency error plus precision). The frequency error  * component is computed as CLOCK_PHI times the difference between the epoch  * of the time measurement and the reference time. The precision componen  * is computed as the square root of the mean of the squares of a zero-  * mean, uniform distribution of unit maximum amplitude. Whether this  * makes statistical sense may be arguable.  */
end_comment

begin_define
define|#
directive|define
name|SQUARE
parameter_list|(
name|x
parameter_list|)
value|((x) * (x))
end_define

begin_define
define|#
directive|define
name|SQRT
parameter_list|(
name|x
parameter_list|)
value|(sqrt(x))
end_define

begin_define
define|#
directive|define
name|DIFF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(SQUARE((x) - (y)))
end_define

begin_define
define|#
directive|define
name|LOGTOD
parameter_list|(
name|a
parameter_list|)
value|((a)< 0 ? 1. / (1L<< -(a)) : \ 			    1L<< (int)(a))
end_define

begin_comment
comment|/* log2 to double */
end_comment

begin_define
define|#
directive|define
name|UNIVAR
parameter_list|(
name|x
parameter_list|)
value|(SQUARE(.28867513 * LOGTOD(x)))
end_define

begin_comment
comment|/* std uniform distr */
end_comment

begin_define
define|#
directive|define
name|ULOGTOD
parameter_list|(
name|a
parameter_list|)
value|(1L<< (int)(a))
end_define

begin_comment
comment|/* ulog2 to double */
end_comment

begin_define
define|#
directive|define
name|MAXDISPERSE
value|16.
end_define

begin_comment
comment|/* max dispersion (square) */
end_comment

begin_define
define|#
directive|define
name|MINDISPERSE
value|.01
end_define

begin_comment
comment|/* min dispersion */
end_comment

begin_define
define|#
directive|define
name|MAXDISTANCE
value|1.
end_define

begin_comment
comment|/* max root distance */
end_comment

begin_comment
comment|/*  * Loop filter parameters.  See section 5.1 of the specification.  *  * Note that these are appropriate for a crystal time base.  If your  * system clock is line frequency controlled you should read the  * specification for appropriate modifications.  */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PHI
value|15e-6
end_define

begin_comment
comment|/* max frequency wander */
end_comment

begin_define
define|#
directive|define
name|EVENT_TIMEOUT
value|0
end_define

begin_comment
comment|/* one second, that is */
end_comment

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
name|int
name|last_ttl
decl_stmt|;
comment|/* last TTL specified */
specifier|volatile
name|long
name|received
decl_stmt|;
comment|/* number of incoming packets */
name|long
name|sent
decl_stmt|;
comment|/* number of outgoing packets */
name|long
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
value|0x0001
end_define

begin_comment
comment|/* duplicate packet received */
end_comment

begin_define
define|#
directive|define
name|TEST2
value|0x0002
end_define

begin_comment
comment|/* bogus packet received */
end_comment

begin_define
define|#
directive|define
name|TEST3
value|0x0004
end_define

begin_comment
comment|/* protocol unsynchronized */
end_comment

begin_define
define|#
directive|define
name|TEST4
value|0x0008
end_define

begin_comment
comment|/* peer delay/dispersion bounds check */
end_comment

begin_define
define|#
directive|define
name|TEST5
value|0x0010
end_define

begin_comment
comment|/* peer authentication failed */
end_comment

begin_define
define|#
directive|define
name|TEST6
value|0x0020
end_define

begin_comment
comment|/* peer clock unsynchronized */
end_comment

begin_define
define|#
directive|define
name|TEST7
value|0x0040
end_define

begin_comment
comment|/* peer stratum out of bounds */
end_comment

begin_define
define|#
directive|define
name|TEST8
value|0x0080
end_define

begin_comment
comment|/* root delay/dispersion bounds check */
end_comment

begin_define
define|#
directive|define
name|TEST9
value|0x0100
end_define

begin_comment
comment|/* peer not authenticated */
end_comment

begin_define
define|#
directive|define
name|TEST10
value|0x0200
end_define

begin_comment
comment|/* access denied */
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
name|struct
name|refclockproc
modifier|*
name|procptr
decl_stmt|;
comment|/* pointer to reference clock stuff */
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
name|burst
decl_stmt|;
comment|/* packets remaining in burst */
name|u_char
name|version
decl_stmt|;
comment|/* version number */
name|u_int
name|flags
decl_stmt|;
comment|/* peer flags */
name|u_char
name|cast_flags
decl_stmt|;
comment|/* flags MDF_?CAST */
name|u_int
name|flash
decl_stmt|;
comment|/* protocol error tally bits */
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
name|u_int32
name|refid
decl_stmt|;
comment|/* peer reference ID */
name|l_fp
name|reftime
decl_stmt|;
comment|/* update epoch */
name|u_long
name|keyid
decl_stmt|;
comment|/* current key ID */
name|u_long
name|pkeyid
decl_stmt|;
comment|/* previous key ID (autokey) */
name|u_long
modifier|*
name|keylist
decl_stmt|;
comment|/* session key identifier list */
name|int
name|keynumber
decl_stmt|;
comment|/* session key identifier number */
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
name|double
name|estbdelay
decl_stmt|;
comment|/* broadcast offset */
name|u_char
name|status
decl_stmt|;
comment|/* peer status */
name|u_char
name|pollsw
decl_stmt|;
comment|/* what it says */
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
name|double
name|filter_delay
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* delay part of shift register */
name|double
name|filter_offset
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* offset part of shift register */
name|double
name|filter_disp
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* dispersion part of shift register */
name|u_long
name|filter_epoch
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* epoch part of shift register */
name|u_char
name|filter_order
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* we keep the filter sorted here */
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
name|double
name|offset
decl_stmt|;
comment|/* peer clock offset */
name|double
name|delay
decl_stmt|;
comment|/* peer roundtrip delay */
name|double
name|variance
decl_stmt|;
comment|/* peer variance (jitter) */
name|double
name|disp
decl_stmt|;
comment|/* peer dispersion */
name|double
name|rootdelay
decl_stmt|;
comment|/* roundtrip delay to primary clock */
name|double
name|rootdispersion
decl_stmt|;
comment|/* dispersion to primary clock */
name|u_long
name|epoch
decl_stmt|;
comment|/* reference epoch */
comment|/* ***End of clear-to-zero area.*** */
comment|/* Everything that is cleared to zero goes above here */
name|u_long
name|update
decl_stmt|;
comment|/* receive epoch */
define|#
directive|define
name|end_clear_to_zero
value|update
name|u_long
name|outdate
decl_stmt|;
comment|/* send time last packet */
name|u_long
name|nextdate
decl_stmt|;
comment|/* send time next packet */
name|u_long
name|nextaction
decl_stmt|;
comment|/* peer local activity timeout (refclocks mainly) */
name|void
argument_list|(
argument|*action
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* action timeout function */
comment|/* 	 * statistic counters 	 */
name|u_long
name|timereset
decl_stmt|;
comment|/* time stat counters were reset */
name|u_long
name|sent
decl_stmt|;
comment|/* number of updates sent */
name|u_long
name|received
decl_stmt|;
comment|/* number of frames received */
name|u_long
name|timereceived
decl_stmt|;
comment|/* last time a frame received */
name|u_long
name|timereachable
decl_stmt|;
comment|/* last reachable/unreachable event */
name|u_long
name|processed
decl_stmt|;
comment|/* processed by the protocol */
name|u_long
name|badauth
decl_stmt|;
comment|/* bad credentials detected */
name|u_long
name|bogusorg
decl_stmt|;
comment|/* rejected due to bogus origin */
name|u_long
name|oldpkt
decl_stmt|;
comment|/* rejected as duplicate packet */
name|u_long
name|seldisptoolarge
decl_stmt|;
comment|/* too much dispersion for selection */
name|u_long
name|selbroken
decl_stmt|;
comment|/* broken NTP detected in selection */
name|u_long
name|seltooold
decl_stmt|;
comment|/* too long since sync in selection */
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

begin_define
define|#
directive|define
name|MODE_MCLIENT
value|9
end_define

begin_comment
comment|/* multicast mode, used internally */
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
name|FLAG_MCAST1
value|0x4
end_define

begin_comment
comment|/* multicast client/server mode */
end_comment

begin_define
define|#
directive|define
name|FLAG_MCAST2
value|0x8
end_define

begin_comment
comment|/* multicast client mode */
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

begin_define
define|#
directive|define
name|FLAG_BURST
value|0x100
end_define

begin_comment
comment|/* burst mode */
end_comment

begin_define
define|#
directive|define
name|FLAG_SKEY
value|0x200
end_define

begin_comment
comment|/* autokey authentication */
end_comment

begin_define
define|#
directive|define
name|FLAG_NOSELECT
value|0x400
end_define

begin_comment
comment|/* this is a "noselect" peer */
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
value|(u_int32)"PPS "
end_define

begin_comment
comment|/* used when pps controls stratum>1 */
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
comment|/* external (e.g., lockclock) */
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
name|REFCLK_SPECTRACOM
value|4
end_define

begin_comment
comment|/* Spectracom (generic) Receivers */
end_comment

begin_define
define|#
directive|define
name|REFCLK_TRUETIME
value|5
end_define

begin_comment
comment|/* TrueTime (generic) Receivers */
end_comment

begin_define
define|#
directive|define
name|REFCLK_IRIG_AUDIO
value|6
end_define

begin_comment
comment|/* IRIG-B/W audio decoder */
end_comment

begin_define
define|#
directive|define
name|REFCLK_CHU_AUDIO
value|7
end_define

begin_comment
comment|/* CHU audio demodulator/decoder */
end_comment

begin_define
define|#
directive|define
name|REFCLK_PARSE
value|8
end_define

begin_comment
comment|/* generic driver (usually DCF77,GPS,MSF) */
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
name|REFCLK_GPS_ARBITER
value|11
end_define

begin_comment
comment|/* Arbiter 1088A/B/ GPS */
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
comment|/* EES M201 MSF Receiver */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPSTM_TRUE
value|15
end_define

begin_comment
comment|/* OLD TrueTime GPS/TM-TMD Receiver */
end_comment

begin_define
define|#
directive|define
name|REFCLK_IRIG_BANCOMM
value|16
end_define

begin_comment
comment|/* Bancomm GPS/IRIG Interface */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPS_DATUM
value|17
end_define

begin_comment
comment|/* Datum Programmable Time System */
end_comment

begin_define
define|#
directive|define
name|REFCLK_NIST_ACTS
value|18
end_define

begin_comment
comment|/* NIST Auto Computer Time Service */
end_comment

begin_define
define|#
directive|define
name|REFCLK_WWV_HEATH
value|19
end_define

begin_comment
comment|/* Heath GC1000 WWV/WWVH Receiver */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPS_NMEA
value|20
end_define

begin_comment
comment|/* NMEA based GPS clock */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPS_VME
value|21
end_define

begin_comment
comment|/* TrueTime GPS-VME Interface */
end_comment

begin_define
define|#
directive|define
name|REFCLK_ATOM_PPS
value|22
end_define

begin_comment
comment|/* 1-PPS Clock Discipline */
end_comment

begin_define
define|#
directive|define
name|REFCLK_PTB_ACTS
value|23
end_define

begin_comment
comment|/* PTB Auto Computer Time Service */
end_comment

begin_define
define|#
directive|define
name|REFCLK_USNO
value|24
end_define

begin_comment
comment|/* Naval Observatory dialup */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPS_HP
value|26
end_define

begin_comment
comment|/* HP 58503A Time/Frequency Receiver */
end_comment

begin_define
define|#
directive|define
name|REFCLK_ARCRON_MSF
value|27
end_define

begin_comment
comment|/* ARCRON MSF radio clock. */
end_comment

begin_define
define|#
directive|define
name|REFCLK_SHM
value|28
end_define

begin_comment
comment|/* clock attached thru shared memory */
end_comment

begin_define
define|#
directive|define
name|REFCLK_PALISADE
value|29
end_define

begin_comment
comment|/* Trimble Navigation Palisade GPS */
end_comment

begin_define
define|#
directive|define
name|REFCLK_ONCORE
value|30
end_define

begin_comment
comment|/* Motorola UT Oncore GPS */
end_comment

begin_define
define|#
directive|define
name|REFCLK_GPS_JUPITER
value|31
end_define

begin_comment
comment|/* Rockwell Jupiter GPS receiver */
end_comment

begin_define
define|#
directive|define
name|REFCLK_CHRONOLOG
value|32
end_define

begin_comment
comment|/* Chrono-log K WWVB receiver */
end_comment

begin_define
define|#
directive|define
name|REFCLK_DUMBCLOCK
value|33
end_define

begin_comment
comment|/* Dumb localtime clock */
end_comment

begin_define
define|#
directive|define
name|REFCLK_ULINK
value|34
end_define

begin_comment
comment|/* Ultralink M320 WWVB receiver */
end_comment

begin_define
define|#
directive|define
name|REFCLK_PCF
value|35
end_define

begin_comment
comment|/* Conrad parallel port radio clock */
end_comment

begin_define
define|#
directive|define
name|REFCLK_WWV_AUDIO
value|36
end_define

begin_comment
comment|/* WWV/H audio demodulator/decoder */
end_comment

begin_define
define|#
directive|define
name|REFCLK_FG
value|37
end_define

begin_comment
comment|/* Forum Graphic GPS */
end_comment

begin_define
define|#
directive|define
name|REFCLK_MAX
value|37
end_define

begin_comment
comment|/* Grow as needed... */
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
name|u_fp
name|rootdelay
decl_stmt|;
comment|/* distance to primary clock */
name|u_fp
name|rootdispersion
decl_stmt|;
comment|/* clock dispersion */
name|u_int32
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
value|(sizeof(u_int32) + 8)
comment|/* DES */
define|#
directive|define
name|MAX_MAC_LEN
value|(sizeof(u_int32) + 16)
comment|/* MD5 */
comment|/* 	 * The length of the packet less MAC must be a multiple of 64 	 * bits. For normal private-key cryptography, the cryptosum 	 * covers only the raw NTP header. For autokey cryptography, 	 * the heade is incresed by 64 bits to contain the field length 	 * and private value. 	 */
name|u_int32
name|keyid1
decl_stmt|;
comment|/* key identifier 1 */
name|u_int32
name|keyid2
decl_stmt|;
comment|/* key identifier 2 */
name|u_int32
name|keyid3
decl_stmt|;
comment|/* key identifier 3 */
name|u_char
name|mac
index|[
name|MAX_MAC_LEN
index|]
decl_stmt|;
comment|/* mac */
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
value|(sizeof(struct pkt) - MAX_MAC_LEN - 3 * sizeof(u_int32))
end_define

begin_comment
comment|/*  * Minimum size of packet with a MAC: has to include at least a key number.  */
end_comment

begin_define
define|#
directive|define
name|LEN_PKT_MAC
value|(LEN_PKT_NOMAC + sizeof(u_int32))
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
comment|/*  * How we randomize polls.  The poll interval is a power of two.  * We chose a random value which is between 1/4 and 3/4 of the  * poll interval we would normally use and which is an even multiple  * of the EVENT_TIMEOUT.  The random number routine, given an argument  * spread value of n, returns an integer between 0 and (1<<n)-1.  This  * is shifted by EVENT_TIMEOUT and added to the base value.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MRAND48
argument_list|)
end_if

begin_define
define|#
directive|define
name|RANDOM
value|(mrand48())
end_define

begin_define
define|#
directive|define
name|SRANDOM
parameter_list|(
name|x
parameter_list|)
value|(srand48(x))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_RANDOM
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RANDOM
value|(random())
end_define

begin_define
define|#
directive|define
name|SRANDOM
parameter_list|(
name|x
parameter_list|)
value|(srandom(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RANDOM
value|(0)
end_define

begin_define
define|#
directive|define
name|SRANDOM
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RANDPOLL
parameter_list|(
name|x
parameter_list|)
value|((1<< (x)) - 1 + (RANDOM& 0x3))
end_define

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

begin_comment
comment|/* (not used) */
end_comment

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

begin_comment
comment|/* (not used) */
end_comment

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

begin_define
define|#
directive|define
name|PROTO_NTP
value|8
end_define

begin_define
define|#
directive|define
name|PROTO_KERNEL
value|9
end_define

begin_define
define|#
directive|define
name|PROTO_MONITOR
value|10
end_define

begin_define
define|#
directive|define
name|PROTO_FILEGEN
value|11
end_define

begin_comment
comment|/*  * Configuration items for the loop filter  */
end_comment

begin_define
define|#
directive|define
name|LOOP_DRIFTINIT
value|1
end_define

begin_comment
comment|/* set initial frequency offset */
end_comment

begin_define
define|#
directive|define
name|LOOP_DRIFTCOMP
value|2
end_define

begin_comment
comment|/* set frequency offset */
end_comment

begin_define
define|#
directive|define
name|LOOP_PPSDELAY
value|3
end_define

begin_comment
comment|/* set pps delay */
end_comment

begin_define
define|#
directive|define
name|LOOP_PPSBAUD
value|4
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
comment|/* configure ntpd PID file */
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
comment|/*  * Default parameters.  We use these in the absence of something better.  */
end_comment

begin_define
define|#
directive|define
name|DEFBROADDELAY
value|4e-3
end_define

begin_comment
comment|/* default broadcast offset */
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
name|u_long
name|lastdrop
decl_stmt|;
comment|/* last time dropped due to RES_LIMIT*/
name|u_long
name|lasttime
decl_stmt|;
comment|/* last time data updated */
name|u_long
name|firsttime
decl_stmt|;
comment|/* time structure initialized */
name|u_long
name|count
decl_stmt|;
comment|/* count we have seen */
name|u_int32
name|rmtadr
decl_stmt|;
comment|/* address of remote host */
name|struct
name|interface
modifier|*
name|interface
decl_stmt|;
comment|/* interface on which this arrived */
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
name|u_char
name|cast_flags
decl_stmt|;
comment|/* flags MDF_?CAST */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MDF_UCAST
value|0x1
end_define

begin_comment
comment|/* unicast packet */
end_comment

begin_define
define|#
directive|define
name|MDF_MCAST
value|0x2
end_define

begin_comment
comment|/* multicast packet */
end_comment

begin_define
define|#
directive|define
name|MDF_BCAST
value|0x4
end_define

begin_comment
comment|/* broadcast packet */
end_comment

begin_define
define|#
directive|define
name|MDF_LCAST
value|0x8
end_define

begin_comment
comment|/* local packet */
end_comment

begin_define
define|#
directive|define
name|MDF_ACAST
value|0x10
end_define

begin_comment
comment|/* manycast packet */
end_comment

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
name|u_int32
name|addr
decl_stmt|;
comment|/* host address (host byte order) */
name|u_int32
name|mask
decl_stmt|;
comment|/* mask for address (host byte order) */
name|u_long
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
name|double
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

begin_comment
comment|/*  * Defines for association matching   */
end_comment

begin_define
define|#
directive|define
name|AM_MODES
value|10
end_define

begin_comment
comment|/* total number of modes */
end_comment

begin_define
define|#
directive|define
name|NO_PEER
value|0
end_define

begin_comment
comment|/* action when no peer is found */
end_comment

begin_comment
comment|/*  * Association matching AM[] return codes  */
end_comment

begin_define
define|#
directive|define
name|AM_ERR
value|-1
end_define

begin_define
define|#
directive|define
name|AM_NOMATCH
value|0
end_define

begin_define
define|#
directive|define
name|AM_PROCPKT
value|1
end_define

begin_define
define|#
directive|define
name|AM_FXMIT
value|2
end_define

begin_define
define|#
directive|define
name|AM_MANYCAST
value|3
end_define

begin_define
define|#
directive|define
name|AM_NEWPASS
value|4
end_define

begin_define
define|#
directive|define
name|AM_NEWBCL
value|5
end_define

begin_define
define|#
directive|define
name|AM_POSSBCL
value|6
end_define

begin_comment
comment|/* NetInfo configuration locations */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINFO
end_ifdef

begin_define
define|#
directive|define
name|NETINFO_CONFIG_DIR
value|"/config/ntp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_H */
end_comment

end_unit

