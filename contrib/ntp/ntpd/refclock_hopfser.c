begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * refclock_hopfser.c  * - clock driver for hopf serial boards (GPS or DCF77)  *  * Date: 30.03.2000 Revision: 01.10  *  * latest source and further information can be found at:  * http://www.ATLSoft.de/ntp  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
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
operator|(
name|defined
argument_list|(
name|CLOCK_HOPF_SERIAL
argument_list|)
operator|)
end_if

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
file|"ntp_control.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_if
if|#
directive|if
name|defined
name|HAVE_SYS_MODEM_H
end_if

begin_include
include|#
directive|include
file|<sys/modem.h>
end_include

begin_define
define|#
directive|define
name|TIOCMSET
value|MCSETA
end_define

begin_define
define|#
directive|define
name|TIOCMGET
value|MCGETA
end_define

begin_define
define|#
directive|define
name|TIOCM_RTS
value|MRTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIOS_NEEDS__SVID3
end_ifdef

begin_define
define|#
directive|define
name|_SVID3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIOS_NEEDS__SVID3
end_ifdef

begin_undef
undef|#
directive|undef
name|_SVID3
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * clock definitions  */
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"hopf Elektronik serial clock"
end_define

begin_comment
comment|/* Long name */
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
value|"hopf\0"
end_define

begin_comment
comment|/* reference ID */
end_comment

begin_comment
comment|/*  * I/O definitions  */
end_comment

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/hopfclock%d"
end_define

begin_comment
comment|/* device name and unit */
end_comment

begin_define
define|#
directive|define
name|SPEED232
value|B9600
end_define

begin_comment
comment|/* uart speed (9600 baud) */
end_comment

begin_define
define|#
directive|define
name|STX
value|0x02
end_define

begin_define
define|#
directive|define
name|ETX
value|0x03
end_define

begin_define
define|#
directive|define
name|CR
value|0x0c
end_define

begin_define
define|#
directive|define
name|LF
value|0x0a
end_define

begin_comment
comment|/* parse states */
end_comment

begin_define
define|#
directive|define
name|REC_QUEUE_EMPTY
value|0
end_define

begin_define
define|#
directive|define
name|REC_QUEUE_FULL
value|1
end_define

begin_define
define|#
directive|define
name|HOPF_OPMODE
value|0x0C
end_define

begin_comment
comment|/* operation mode mask */
end_comment

begin_define
define|#
directive|define
name|HOPF_INVALID
value|0x00
end_define

begin_comment
comment|/* no time code available */
end_comment

begin_define
define|#
directive|define
name|HOPF_INTERNAL
value|0x04
end_define

begin_comment
comment|/* internal clock */
end_comment

begin_define
define|#
directive|define
name|HOPF_RADIO
value|0x08
end_define

begin_comment
comment|/* radio clock */
end_comment

begin_define
define|#
directive|define
name|HOPF_RADIOHP
value|0x0C
end_define

begin_comment
comment|/* high precision radio clock */
end_comment

begin_comment
comment|/*  * hopfclock unit control structure.  */
end_comment

begin_struct
struct|struct
name|hopfclock_unit
block|{
name|l_fp
name|laststamp
decl_stmt|;
comment|/* last receive timestamp */
name|short
name|unit
decl_stmt|;
comment|/* NTP refclock unit number */
name|u_long
name|polled
decl_stmt|;
comment|/* flag to detect noreplies */
name|char
name|leap_status
decl_stmt|;
comment|/* leap second flag */
name|int
name|rpt_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|hopfserial_start
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
name|hopfserial_shutdown
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
name|hopfserial_receive
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|hopfserial_poll
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

begin_comment
comment|/* static  void hopfserial_io		P((struct recvbuf *)); */
end_comment

begin_comment
comment|/*  * Transfer vector  */
end_comment

begin_decl_stmt
name|struct
name|refclock
name|refclock_hopfser
init|=
block|{
name|hopfserial_start
block|,
comment|/* start up driver */
name|hopfserial_shutdown
block|,
comment|/* shut down driver */
name|hopfserial_poll
block|,
comment|/* transmit poll message */
name|noentry
block|,
comment|/* not used  */
name|noentry
block|,
comment|/* initialize driver (not used) */
name|noentry
block|,
comment|/* not used */
name|NOFLAGS
comment|/* not used */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * hopfserial_start - open the devices and initialize data for processing  */
end_comment

begin_function
specifier|static
name|int
name|hopfserial_start
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
name|hopfclock_unit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|char
name|gpsdev
index|[
literal|20
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|SYS_WINNT
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|gpsdev
argument_list|,
literal|"COM%d:"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|gpsdev
argument_list|,
name|DEVICE
argument_list|,
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* LDISC_STD, LDISC_RAW 	 * Open serial port. Use CLK line discipline, if available. 	 */
name|fd
operator|=
name|refclock_open
argument_list|(
name|gpsdev
argument_list|,
name|SPEED232
argument_list|,
name|LDISC_CLK
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<=
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|"hopfSerialClock(%d) start: open %s failed\n"
argument_list|,
name|unit
argument_list|,
name|gpsdev
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"hopfSerialClock(%d) fd: %d dev: %s"
argument_list|,
name|unit
argument_list|,
name|fd
argument_list|,
name|gpsdev
argument_list|)
expr_stmt|;
comment|/* 	 * Allocate and initialize unit structure 	 */
name|up
operator|=
operator|(
expr|struct
name|hopfclock_unit
operator|*
operator|)
name|emalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|hopfclock_unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|up
operator|)
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"hopfSerialClock(%d) emalloc: %m"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|"hopfSerialClock(%d) emalloc\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
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
name|hopfclock_unit
argument_list|)
argument_list|)
expr_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
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
name|pp
operator|->
name|io
operator|.
name|clock_recv
operator|=
name|hopfserial_receive
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|srcclock
operator|=
operator|(
name|caddr_t
operator|)
name|peer
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|datalen
operator|=
literal|0
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|fd
operator|=
name|fd
expr_stmt|;
if|if
condition|(
operator|!
name|io_addclock
argument_list|(
operator|&
name|pp
operator|->
name|io
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|"hopfSerialClock(%d) io_addclock\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|up
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * Initialize miscellaneous variables 	 */
name|pp
operator|->
name|clockdesc
operator|=
name|DESCRIPTION
expr_stmt|;
name|peer
operator|->
name|precision
operator|=
name|PRECISION
expr_stmt|;
name|peer
operator|->
name|burst
operator|=
name|NSTAGE
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
name|up
operator|->
name|leap_status
operator|=
literal|0
expr_stmt|;
name|up
operator|->
name|unit
operator|=
operator|(
name|short
operator|)
name|unit
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * hopfserial_shutdown - shut down the clock  */
end_comment

begin_function
specifier|static
name|void
name|hopfserial_shutdown
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
name|hopfclock_unit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
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
name|hopfclock_unit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
name|io_closeclock
argument_list|(
operator|&
name|pp
operator|->
name|io
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|up
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * hopfserial_receive - receive data from the serial interface  */
end_comment

begin_function
specifier|static
name|void
name|hopfserial_receive
parameter_list|(
name|struct
name|recvbuf
modifier|*
name|rbufp
parameter_list|)
block|{
name|struct
name|hopfclock_unit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|struct
name|peer
modifier|*
name|peer
decl_stmt|;
name|int
name|sync
decl_stmt|;
comment|/* synchronization indicator */
name|int
name|DoW
decl_stmt|;
comment|/* Dow */
name|int
name|day
decl_stmt|,
name|month
decl_stmt|;
comment|/* ddd conversion */
comment|/* 	 * Initialize pointers and read the timecode and timestamp. 	 */
name|peer
operator|=
operator|(
expr|struct
name|peer
operator|*
operator|)
name|rbufp
operator|->
name|recv_srcclock
expr_stmt|;
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
name|hopfclock_unit
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
name|rpt_next
operator|==
literal|0
condition|)
return|return;
name|up
operator|->
name|rpt_next
operator|=
literal|0
expr_stmt|;
comment|/* wait until next poll interval occur */
name|pp
operator|->
name|lencode
operator|=
name|refclock_gtlin
argument_list|(
name|rbufp
argument_list|,
name|pp
operator|->
name|a_lastcode
argument_list|,
name|BMAX
argument_list|,
operator|&
name|pp
operator|->
name|lastrec
argument_list|)
expr_stmt|;
if|if
condition|(
name|pp
operator|->
name|lencode
operator|==
literal|0
condition|)
return|return;
name|sscanf
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|,
if|#
directive|if
literal|1
literal|"%1x%1x%2d%2d%2d%2d%2d%2d"
argument_list|,
comment|/* ...cr,lf */
else|#
directive|else
literal|"%*c%1x%1x%2d%2d%2d%2d%2d%2d"
argument_list|,
comment|/* stx...cr,lf,etx */
endif|#
directive|endif
operator|&
name|sync
argument_list|,
operator|&
name|DoW
argument_list|,
operator|&
name|pp
operator|->
name|hour
argument_list|,
operator|&
name|pp
operator|->
name|minute
argument_list|,
operator|&
name|pp
operator|->
name|second
argument_list|,
operator|&
name|day
argument_list|,
operator|&
name|month
argument_list|,
operator|&
name|pp
operator|->
name|year
argument_list|)
expr_stmt|;
comment|/* 	  Validate received values at least enough to prevent internal 	  array-bounds problems, etc. 	*/
if|if
condition|(
operator|(
name|pp
operator|->
name|hour
operator|<
literal|0
operator|)
operator|||
operator|(
name|pp
operator|->
name|hour
operator|>
literal|23
operator|)
operator|||
operator|(
name|pp
operator|->
name|minute
operator|<
literal|0
operator|)
operator|||
operator|(
name|pp
operator|->
name|minute
operator|>
literal|59
operator|)
operator|||
operator|(
name|pp
operator|->
name|second
operator|<
literal|0
operator|)
operator|||
operator|(
name|pp
operator|->
name|second
operator|>
literal|60
operator|)
comment|/*Allow for leap seconds.*/
operator|||
operator|(
name|day
operator|<
literal|1
operator|)
operator|||
operator|(
name|day
operator|>
literal|31
operator|)
operator|||
operator|(
name|month
operator|<
literal|1
operator|)
operator|||
operator|(
name|month
operator|>
literal|12
operator|)
operator|||
operator|(
name|pp
operator|->
name|year
operator|<
literal|0
operator|)
operator|||
operator|(
name|pp
operator|->
name|year
operator|>
literal|99
operator|)
condition|)
block|{
comment|/* Data out of range. */
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADREPLY
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	  some preparations 	*/
name|pp
operator|->
name|day
operator|=
name|ymd2yd
argument_list|(
name|pp
operator|->
name|year
argument_list|,
name|month
argument_list|,
name|day
argument_list|)
expr_stmt|;
name|pp
operator|->
name|leap
operator|=
literal|0
expr_stmt|;
comment|/* Year-2000 check! */
comment|/* wrap 2-digit date into 4-digit */
if|if
condition|(
name|pp
operator|->
name|year
operator|<
name|YEAR_PIVOT
condition|)
block|{
name|pp
operator|->
name|year
operator|+=
literal|100
expr_stmt|;
block|}
comment|/*< 98 */
name|pp
operator|->
name|year
operator|+=
literal|1900
expr_stmt|;
comment|/* preparation for timecode ntpq rl command ! */
if|#
directive|if
literal|0
block|wsprintf(pp->a_lastcode, 		 "STATUS: %1X%1X, DATE: %02d.%02d.%04d  TIME: %02d:%02d:%02d", 		 sync, 		 DoW, 		 day, 		 month, 		 pp->year, 		 pp->hour, 		 pp->minute, 		 pp->second);  	pp->lencode = strlen(pp->a_lastcode); 	if ((sync&& 0xc) == 0 ){
comment|/* time ok? */
block|refclock_report(peer, CEVNT_BADTIME); 		pp->leap = LEAP_NOTINSYNC; 		return; 	}
endif|#
directive|endif
comment|/* 	 * If clock has no valid status then report error and exit 	 */
if|if
condition|(
operator|(
name|sync
operator|&
name|HOPF_OPMODE
operator|)
operator|==
name|HOPF_INVALID
condition|)
block|{
comment|/* time ok? */
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOTINSYNC
expr_stmt|;
return|return;
block|}
comment|/* 	 * Test if time is running on internal quarz 	 * if CLK_FLAG1 is set, sychronize even if no radio operation 	 */
if|if
condition|(
operator|(
name|sync
operator|&
name|HOPF_OPMODE
operator|)
operator|==
name|HOPF_INTERNAL
condition|)
block|{
if|if
condition|(
operator|(
name|pp
operator|->
name|sloppyclockflag
operator|&
name|CLK_FLAG1
operator|)
operator|==
literal|0
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOTINSYNC
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
operator|!
name|refclock_process
argument_list|(
name|pp
argument_list|)
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
return|return;
block|}
name|refclock_receive
argument_list|(
name|peer
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|msyslog(LOG_ERR, " D:%x  D:%d D:%d",sync,pp->minute,pp->second);
endif|#
directive|endif
name|record_clock_stats
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|,
name|pp
operator|->
name|a_lastcode
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * hopfserial_poll - called by the transmit procedure  *  */
end_comment

begin_function
specifier|static
name|void
name|hopfserial_poll
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
name|hopfclock_unit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
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
name|hopfclock_unit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
name|pp
operator|->
name|polls
operator|++
expr_stmt|;
name|up
operator|->
name|rpt_next
operator|=
literal|1
expr_stmt|;
if|#
directive|if
literal|0
block|record_clock_stats(&peer->srcadr, pp->a_lastcode);
endif|#
directive|endif
return|return;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_hopfser_bs
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

