begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_usno - clock driver for the Naval Observatory dialup  * Michael Shields<shields@tembel.org> 1995/02/25  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REFCLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|CLOCK_USNO
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_IOCTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_IOCTL_H */
end_comment

begin_include
include|#
directive|include
file|"ntpd.h"
end_include

begin_include
include|#
directive|include
file|"ntp_io.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_control.h"
end_include

begin_comment
comment|/*  * This driver supports the Naval Observatory dialup at +1 202 653 0351.  * It is a hacked-up version of the ACTS driver.  *  * This driver does not support the `phone' configuration because that  * is needlessly global; it would clash with the ACTS driver.  *  * The Naval Observatory does not support the echo-delay measurement scheme.  *  * However, this driver *does* support UUCP port locking, allowing the  * line to be shared with other processes when not actually dialing  * for time.  */
end_comment

begin_comment
comment|/*  * Interface definitions  */
end_comment

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/cua%d"
end_define

begin_comment
comment|/* device name and unit */
end_comment

begin_define
define|#
directive|define
name|LOCKFILE
value|"/var/lock/LCK..cua%d"
end_define

begin_comment
comment|/* #define LOCKFILE	"/usr/spool/uucp/LCK..cua%d" */
end_comment

begin_define
define|#
directive|define
name|PHONE
value|"atdt 202 653 0351"
end_define

begin_comment
comment|/* #define PHONE	"atdt 1 202 653 0351" */
end_comment

begin_define
define|#
directive|define
name|SPEED232
value|B1200
end_define

begin_comment
comment|/* uart speed (1200 cowardly baud) */
end_comment

begin_define
define|#
directive|define
name|PRECISION
value|(-10)
end_define

begin_comment
comment|/* precision assumed (about 1 ms) */
end_comment

begin_define
define|#
directive|define
name|REFID
value|"USNO"
end_define

begin_comment
comment|/* reference ID */
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"Naval Observatory dialup"
end_define

begin_define
define|#
directive|define
name|MODE_AUTO
value|0
end_define

begin_comment
comment|/* automatic mode */
end_comment

begin_define
define|#
directive|define
name|MODE_BACKUP
value|1
end_define

begin_comment
comment|/* backup mode */
end_comment

begin_define
define|#
directive|define
name|MODE_MANUAL
value|2
end_define

begin_comment
comment|/* manual mode */
end_comment

begin_define
define|#
directive|define
name|MSGCNT
value|10
end_define

begin_comment
comment|/* we need this many time messages */
end_comment

begin_define
define|#
directive|define
name|SMAX
value|80
end_define

begin_comment
comment|/* max token string length */
end_comment

begin_define
define|#
directive|define
name|LENCODE
value|20
end_define

begin_comment
comment|/* length of valid timecode string */
end_comment

begin_define
define|#
directive|define
name|USNO_MINPOLL
value|10
end_define

begin_comment
comment|/* log2 min poll interval (1024 s) */
end_comment

begin_define
define|#
directive|define
name|USNO_MAXPOLL
value|14
end_define

begin_comment
comment|/* log2 max poll interval (16384 s) */
end_comment

begin_define
define|#
directive|define
name|MAXOUTAGE
value|3600
end_define

begin_comment
comment|/* max before USNO kicks in (s) */
end_comment

begin_comment
comment|/*  * Modem control strings. These may have to be changed for some modems.  *  * AT	command prefix  * B1	initiate call negotiation using Bell 212A  *&C1	enable carrier detect  *&D2	hang up and return to command mode on DTR transition  * E0	modem command echo disabled  * l1	set modem speaker volume to low level  * M1	speaker enabled untill carrier detect  * Q0	return result codes  * V1	return result codes as English words  */
end_comment

begin_define
define|#
directive|define
name|MODEM_SETUP
value|"ATB1&C1&D2E0L1M1Q0V1"
end_define

begin_comment
comment|/* modem setup */
end_comment

begin_define
define|#
directive|define
name|MODEM_HANGUP
value|"ATH"
end_define

begin_comment
comment|/* modem disconnect */
end_comment

begin_comment
comment|/*  * Timeouts  */
end_comment

begin_define
define|#
directive|define
name|IDLE
value|60
end_define

begin_comment
comment|/* idle timeout (s) */
end_comment

begin_define
define|#
directive|define
name|WAIT
value|2
end_define

begin_comment
comment|/* wait timeout (s) */
end_comment

begin_define
define|#
directive|define
name|ANSWER
value|30
end_define

begin_comment
comment|/* answer timeout (s) */
end_comment

begin_define
define|#
directive|define
name|CONNECT
value|10
end_define

begin_comment
comment|/* connect timeout (s) */
end_comment

begin_define
define|#
directive|define
name|TIMECODE
value|(MSGCNT+16)
end_define

begin_comment
comment|/* timecode timeout (s) */
end_comment

begin_comment
comment|/*  * Unit control structure  */
end_comment

begin_struct
struct|struct
name|usnounit
block|{
name|int
name|pollcnt
decl_stmt|;
comment|/* poll message counter */
name|int
name|state
decl_stmt|;
comment|/* the first one was Delaware */
name|int
name|run
decl_stmt|;
comment|/* call program run switch */
name|int
name|msgcnt
decl_stmt|;
comment|/* count of time messages received */
name|long
name|redial
decl_stmt|;
comment|/* interval to next automatic call */
name|int
name|unit
decl_stmt|;
comment|/* unit number (= port) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|usno_start
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|usno_shutdown
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|usno_poll
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|usno_disc
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static	void	usno_timeout	P((struct peer *)); static	void	usno_receive	P((struct recvbuf *)); static	int	usno_write	P((struct peer *, const char *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/*  * Transfer vector  */
end_comment

begin_decl_stmt
name|struct
name|refclock
name|refclock_usno
init|=
block|{
name|usno_start
block|,
comment|/* start up driver */
name|usno_shutdown
block|,
comment|/* shut down driver */
name|usno_poll
block|,
comment|/* transmit poll message */
name|noentry
block|,
comment|/* not used (usno_control) */
name|noentry
block|,
comment|/* not used (usno_init) */
name|noentry
block|,
comment|/* not used (usno_buginfo) */
name|NOFLAGS
comment|/* not used */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * usno_start - open the devices and initialize data for processing  */
end_comment

begin_function
specifier|static
name|int
name|usno_start
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
specifier|register
name|struct
name|usnounit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
comment|/* 	 * Initialize miscellaneous variables 	 */
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|peer
operator|->
name|precision
operator|=
name|PRECISION
expr_stmt|;
name|pp
operator|->
name|clockdesc
operator|=
name|DESCRIPTION
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|pp
operator|->
name|refid
argument_list|,
name|REFID
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|peer
operator|->
name|minpoll
operator|=
name|USNO_MINPOLL
expr_stmt|;
name|peer
operator|->
name|maxpoll
operator|=
name|USNO_MAXPOLL
expr_stmt|;
name|peer
operator|->
name|sstclktype
operator|=
name|CTL_SST_TS_TELEPHONE
expr_stmt|;
comment|/* 	 * Allocate and initialize unit structure 	 */
if|if
condition|(
operator|!
operator|(
name|up
operator|=
operator|(
expr|struct
name|usnounit
operator|*
operator|)
name|emalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|usnounit
argument_list|)
argument_list|)
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|memset
argument_list|(
operator|(
name|char
operator|*
operator|)
name|up
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|usnounit
argument_list|)
argument_list|)
expr_stmt|;
name|up
operator|->
name|unit
operator|=
name|unit
expr_stmt|;
name|pp
operator|->
name|unitptr
operator|=
operator|(
name|caddr_t
operator|)
name|up
expr_stmt|;
comment|/* 	 * Set up the driver timeout 	 */
name|peer
operator|->
name|nextdate
operator|=
name|current_time
operator|+
name|WAIT
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * usno_shutdown - shut down the clock  */
end_comment

begin_function
specifier|static
name|void
name|usno_shutdown
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
specifier|register
name|struct
name|usnounit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"usno: clock %s shutting down\n"
argument_list|,
name|ntoa
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|usnounit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
name|usno_disc
argument_list|(
name|peer
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|up
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * usno_receive - receive data from the serial interface  */
end_comment

begin_comment
unit|static void usno_receive( 	struct recvbuf *rbufp 	) { 	register struct usnounit *up; 	struct refclockproc *pp; 	struct peer *peer; 	char str[SMAX]; 	u_long mjd;
comment|/* Modified Julian Day */
end_comment

begin_comment
unit|static int day, hour, minute, second;
comment|/* 	 * Initialize pointers and read the timecode and timestamp. If 	 * the OK modem status code, leave it where folks can find it. 	 */
end_comment

begin_ifdef
unit|peer = (struct peer *)rbufp->recv_srcclock; 	pp = peer->procptr; 	up = (struct usnounit *)pp->unitptr; 	pp->lencode = refclock_gtlin(rbufp, pp->a_lastcode, BMAX,&pp->lastrec); 	if (pp->lencode == 0) { 		if (strcmp(pp->a_lastcode, "OK") == 0) 		    pp->lencode = 2; 		return; 	}
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_endif
unit|if (debug) 	    printf("usno: timecode %d %s\n", pp->lencode, 		   pp->a_lastcode);
endif|#
directive|endif
end_endif

begin_comment
unit|switch (up->state) {  	    case 0:
comment|/* 		 * State 0. We are not expecting anything. Probably 		 * modem disconnect noise. Go back to sleep. 		 */
end_comment

begin_comment
unit|return;  	    case 1:
comment|/* 		 * State 1. We are about to dial. Just drop it. 		 */
end_comment

begin_comment
unit|return;  	    case 2:
comment|/* 		 * State 2. We are waiting for the call to be answered. 		 * All we care about here is CONNECT as the first token 		 * in the string. If the modem signals BUSY, ERROR, NO 		 * ANSWER, NO CARRIER or NO DIALTONE, we immediately 		 * hang up the phone. If CONNECT doesn't happen after 		 * ANSWER seconds, hang up the phone. If everything is 		 * okay, start the connect timeout and slide into state 		 * 3. 		 */
end_comment

begin_comment
unit|(void)strncpy(str, strtok(pp->a_lastcode, " "), SMAX); 		if (strcmp(str, "BUSY") == 0 || strcmp(str, "ERROR") == 		    0 || strcmp(str, "NO") == 0) { 			NLOG(NLOG_CLOCKINFO)
comment|/* conditional if clause for conditional syslog */
end_comment

begin_comment
unit|msyslog(LOG_NOTICE, 					"clock %s USNO modem status %s", 					ntoa(&peer->srcadr), pp->a_lastcode); 			usno_disc(peer); 		} else if (strcmp(str, "CONNECT") == 0) { 			peer->nextdate = current_time + CONNECT; 			up->msgcnt = 0; 			up->state++; 		} else { 			NLOG(NLOG_CLOCKINFO)
comment|/* conditional if clause for conditional syslog */
end_comment

begin_comment
unit|msyslog(LOG_WARNING, 					"clock %s USNO unknown modem status %s", 					ntoa(&peer->srcadr), pp->a_lastcode); 		} 		return;  	    case 3:
comment|/* 		 * State 3. The call has been answered and we are 		 * waiting for the first message. If this doesn't 		 * happen within the timecode timeout, hang up the 		 * phone. We probably got a wrong number or they are 		 * down. 		 */
end_comment

begin_comment
unit|peer->nextdate = current_time + TIMECODE; 		up->state++; 		return;  	    case 4:
comment|/* 		 * State 4. We are reading a timecode.  It's an actual 		 * timecode, or it's the `*' OTM. 		 * 		 * jjjjj nnn hhmmss UTC 		 */
end_comment

begin_ifdef
unit|if (pp->lencode == LENCODE) { 			if (sscanf(pp->a_lastcode, "%5ld %3d %2d%2d%2d UTC",&mjd,&day,&hour,&minute,&second) != 5) {
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_endif
unit|if (debug) 				    printf("usno: bad timecode format\n");
endif|#
directive|endif
end_endif

begin_comment
unit|refclock_report(peer, CEVNT_BADREPLY); 			} else 			    up->msgcnt++; 			return; 		} else if (pp->lencode != 1 || !up->msgcnt) 		    return;
comment|/* else, OTM; drop out of switch */
end_comment

begin_comment
unit|}  	pp->leap = LEAP_NOWARNING; 	pp->day = day; 	pp->hour = hour; 	pp->minute = minute; 	pp->second = second;
comment|/* 	 * Colossal hack here. We process each sample in a trimmed-mean 	 * filter and determine the reference clock offset and 	 * dispersion. The fudge time1 value is added to each sample as 	 * received. 	 */
end_comment

begin_ifdef
unit|if (!refclock_process(pp)) {
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_endif
unit|if (debug) 		    printf("usno: time rejected\n");
endif|#
directive|endif
end_endif

begin_comment
unit|refclock_report(peer, CEVNT_BADTIME); 		return; 	} else if (up->msgcnt< MSGCNT) 	    return;
comment|/* 	 * We have a filtered sample offset ready for peer processing. 	 * We use lastrec as both the reference time and receive time in 	 * order to avoid being cute, like setting the reference time 	 * later than the receive time, which may cause a paranoid 	 * protocol module to chuck out the data. Finaly, we unhook the 	 * timeout, arm for the next call, fold the tent and go home. 	 */
end_comment

begin_endif
unit|record_clock_stats(&peer->srcadr, pp->a_lastcode); 	refclock_receive(peer); 	pp->sloppyclockflag&= ~CLK_FLAG1; 	up->pollcnt = 0; 	up->state = 0; 	usno_disc(peer); }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/*  * usno_poll - called by the transmit routine  */
end_comment

begin_function
specifier|static
name|void
name|usno_poll
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
specifier|register
name|struct
name|usnounit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
comment|/* 	 * If the driver is running, we set the enable flag (fudge 	 * flag1), which causes the driver timeout routine to initiate a 	 * call. If not, the enable flag can be set using 	 * ntpdc. If this is the sustem peer, then follow the system 	 * poll interval. 	 */
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|usnounit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|run
condition|)
block|{
name|pp
operator|->
name|sloppyclockflag
operator||=
name|CLK_FLAG1
expr_stmt|;
if|if
condition|(
name|peer
operator|==
name|sys_peer
condition|)
name|peer
operator|->
name|hpoll
operator|=
name|sys_poll
expr_stmt|;
else|else
name|peer
operator|->
name|hpoll
operator|=
name|peer
operator|->
name|minpoll
expr_stmt|;
block|}
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * usno_timeout - called by the timer interrupt  */
end_comment

begin_comment
unit|static void usno_timeout( 	struct peer *peer 	) { 	register struct usnounit *up; 	struct refclockproc *pp; 	int fd; 	char device[20]; 	char lockfile[128], pidbuf[8]; 	int dtr = TIOCM_DTR;
comment|/* 	 * If a timeout occurs in other than state 0, the call has 	 * failed. If in state 0, we just see if there is other work to 	 * do. 	 */
end_comment

begin_comment
unit|pp = peer->procptr; 	up = (struct usnounit *)pp->unitptr; 	if (up->state) { 		if (up->state != 1) { 			usno_disc(peer); 			return; 		}
comment|/* 		 * Call, and start the answer timeout. We think it 		 * strange if the OK status has not been received from 		 * the modem, but plow ahead anyway. 		 * 		 * This code is *here* because we had to stick in a brief 		 * delay to let the modem settle down after raising DTR, 		 * and for the OK to be received.  State machines are 		 * contorted. 		 */
end_comment

begin_comment
unit|if (strcmp(pp->a_lastcode, "OK") != 0) 		    NLOG(NLOG_CLOCKINFO)
comment|/* conditional if clause for conditional syslog */
end_comment

begin_comment
unit|msyslog(LOG_NOTICE, "clock %s USNO no modem status", 				    ntoa(&peer->srcadr)); 		(void)usno_write(peer, PHONE); 		NLOG(NLOG_CLOCKINFO)
comment|/* conditional if clause for conditional syslog */
end_comment

begin_comment
unit|msyslog(LOG_NOTICE, "clock %s USNO calling %s\n", 				ntoa(&peer->srcadr), PHONE); 		up->state = 2; 		up->pollcnt++; 		pp->polls++; 		peer->nextdate = current_time + ANSWER; 		return; 	} 	switch (peer->ttl) {
comment|/* 		 * In manual mode the calling program is activated 		 * by the ntpdc program using the enable flag (fudge 		 * flag1), either manually or by a cron job. 		 */
end_comment

begin_comment
unit|case MODE_MANUAL: 		up->run = 0; 		break;
comment|/* 		 * In automatic mode the calling program runs 		 * continuously at intervals determined by the sys_poll 		 * variable. 		 */
end_comment

begin_comment
unit|case MODE_AUTO: 		if (!up->run) 		    pp->sloppyclockflag |= CLK_FLAG1; 		up->run = 1; 		break;
comment|/* 		 * In backup mode the calling program is disabled, 		 * unless no system peer has been selected for MAXOUTAGE 		 * (3600 s). Once enabled, it runs until some other NTP 		 * peer shows up. 		 */
end_comment

begin_comment
unit|case MODE_BACKUP: 		if (!up->run&& sys_peer == 0) { 			if (current_time - last_time> MAXOUTAGE) { 				up->run = 1; 				peer->hpoll = peer->minpoll; 				NLOG(NLOG_CLOCKINFO)
comment|/* conditional if clause for conditional syslog */
end_comment

begin_comment
unit|msyslog(LOG_NOTICE, 						"clock %s USNO backup started ", 						ntoa(&peer->srcadr)); 			} 		} else if (up->run&& sys_peer->sstclktype != CTL_SST_TS_TELEPHONE) { 			peer->hpoll = peer->minpoll; 			up->run = 0; 			NLOG(NLOG_CLOCKINFO)
comment|/* conditional if clause for conditional syslog */
end_comment

begin_comment
unit|msyslog(LOG_NOTICE, 					"clock %s USNO backup stopped", 					ntoa(&peer->srcadr)); 		} 		break;  	    default: 		msyslog(LOG_ERR, 			"clock %s USNO invalid mode", ntoa(&peer->srcadr)); 		 	}
comment|/* 	 * The fudge flag1 is used as an enable/disable; if set either 	 * by the code or via ntpdc, the calling program is 	 * started; if reset, the phones stop ringing. 	 */
end_comment

begin_comment
unit|if (!(pp->sloppyclockflag& CLK_FLAG1)) { 		up->pollcnt = 0; 		peer->nextdate = current_time + IDLE; 		return; 	}
comment|/* 	 * Lock the port. 	 */
end_comment

begin_comment
unit|(void)sprintf(lockfile, LOCKFILE, up->unit); 	fd = open(lockfile, O_WRONLY|O_CREAT|O_EXCL, 0644); 	if (fd< 0) { 		msyslog(LOG_ERR, "clock %s USNO port busy", 			ntoa(&peer->srcadr)); 		return; 	} 	sprintf(pidbuf, "%d\n", (int) getpid()); 	write(fd, pidbuf, strlen(pidbuf)); 	close(fd);
comment|/* 	 * Open serial port. Use ACTS line discipline, if available. It 	 * pumps a timestamp into the data stream at every on-time 	 * character '*' found. Note: the port must have modem control 	 * or deep pockets for the phone bill. HP-UX 9.03 users should 	 * have very deep pockets. 	 */
end_comment

begin_comment
unit|(void)sprintf(device, DEVICE, up->unit); 	if (!(fd = refclock_open(device, SPEED232, LDISC_ACTS))) { 		unlink(lockfile); 		return; 	} 	if (ioctl(fd, TIOCMBIC, (char *)&dtr)< 0) 	    msyslog(LOG_WARNING, "usno_timeout: clock %s: couldn't clear DTR: %m", 		    ntoa(&peer->srcadr));  	pp->io.clock_recv = usno_receive; 	pp->io.srcclock = (caddr_t)peer; 	pp->io.datalen = 0; 	pp->io.fd = fd; 	if (!io_addclock(&pp->io)) { 		(void) close(fd); 		unlink(lockfile); 		free(up); 		return; 	}
comment|/* 	 * Initialize modem and kill DTR. We skedaddle if this comes 	 * bum. 	 */
end_comment

begin_comment
unit|if (!usno_write(peer, MODEM_SETUP)) { 		msyslog(LOG_ERR, "clock %s USNO couldn't write", 			ntoa(&peer->srcadr)); 		io_closeclock(&pp->io); 		unlink(lockfile); 		free(up); 		return; 	}
comment|/* 	 * Initiate a call to the Observatory. If we wind up here in 	 * other than state 0, a successful call could not be completed 	 * within minpoll seconds. 	 */
end_comment

begin_comment
unit|if (up->pollcnt) { 		refclock_report(peer, CEVNT_TIMEOUT); 		NLOG(NLOG_CLOCKINFO)
comment|/* conditional if clause for conditional syslog */
end_comment

begin_ifdef
unit|msyslog(LOG_NOTICE, 				"clock %s USNO calling program terminated", 				ntoa(&peer->srcadr)); 		pp->sloppyclockflag&= ~CLK_FLAG1; 		up->pollcnt = 0;
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_endif
unit|if (debug) 		    printf("usno: calling program terminated\n");
endif|#
directive|endif
end_endif

begin_comment
unit|usno_disc(peer); 		return; 	}
comment|/* 	 * Raise DTR, and let the modem settle.  Then we'll dial. 	 */
end_comment

begin_endif
unit|if (ioctl(pp->io.fd, TIOCMBIS, (char *)&dtr)< -1) 	    msyslog(LOG_INFO, "usno_timeout: clock %s: couldn't set DTR: %m", 		    ntoa(&peer->srcadr)); 	up->state = 1; 	peer->nextdate = current_time + WAIT; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/*  * usno_disc - disconnect the call and wait for the ruckus to cool  */
end_comment

begin_function
specifier|static
name|void
name|usno_disc
parameter_list|(
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
specifier|register
name|struct
name|usnounit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|int
name|dtr
init|=
name|TIOCM_DTR
decl_stmt|;
name|char
name|lockfile
index|[
literal|128
index|]
decl_stmt|;
comment|/* 	 * We should never get here other than in state 0, unless a call 	 * has timed out. We drop DTR, which will reliably get the modem 	 * off the air, even while the modem is hammering away full tilt. 	 */
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|usnounit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|pp
operator|->
name|io
operator|.
name|fd
argument_list|,
name|TIOCMBIC
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|dtr
argument_list|)
operator|<
literal|0
condition|)
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"usno_disc: clock %s: couldn't clear DTR: %m"
argument_list|,
name|ntoa
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|state
operator|>
literal|0
condition|)
block|{
name|up
operator|->
name|state
operator|=
literal|0
expr_stmt|;
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"clock %s USNO call failed %d"
argument_list|,
name|ntoa
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|)
argument_list|,
name|up
operator|->
name|state
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"usno: call failed %d\n"
argument_list|,
name|up
operator|->
name|state
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|io_closeclock
argument_list|(
operator|&
name|pp
operator|->
name|io
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|lockfile
argument_list|,
name|LOCKFILE
argument_list|,
name|up
operator|->
name|unit
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|lockfile
argument_list|)
expr_stmt|;
name|peer
operator|->
name|nextdate
operator|=
name|current_time
operator|+
name|WAIT
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * usno_write - write a message to the serial port  */
end_comment

begin_comment
unit|static int usno_write( 	struct peer *peer, 	const char *str 	) { 	register struct usnounit *up; 	struct refclockproc *pp; 	int len; 	int code; 	char cr = '\r';
comment|/* 	 * Not much to do here, other than send the message, handle 	 * debug and report faults. 	 */
end_comment

begin_ifdef
unit|pp = peer->procptr; 	up = (struct usnounit *)pp->unitptr; 	len = strlen(str);
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_endif
unit|if (debug) 	    printf("usno: state %d send %d %s\n", up->state, len, 		   str);
endif|#
directive|endif
end_endif

begin_endif
unit|code = write(pp->io.fd, str, (unsigned)len) == len; 	code |= write(pp->io.fd,&cr, 1) == 1; 	if (!code) 	    refclock_report(peer, CEVNT_FAULT); 	return (code); }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_usno_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK */
end_comment

end_unit

