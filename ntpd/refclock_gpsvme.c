begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* refclock_psc.c:  clock driver for Brandywine PCI-SyncClock32/HP-UX 11.X */
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

begin_comment
comment|/* HAVE_CONFIG_H	*/
end_comment

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
name|CLOCK_GPSVME
argument_list|)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_include
include|#
directive|include
file|<sys/rtprio.h>
end_include

begin_comment
comment|/* may already be included above	*/
end_comment

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_comment
comment|/* NEEDED for PROCLOCK			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hpux	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/* for _IOR, ioctl			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__	*/
end_comment

begin_enum
enum|enum
block|{
comment|/* constants	*/
name|BUFSIZE
init|=
literal|32
block|,
name|PSC_SYNC_OK
init|=
literal|0x40
block|,
comment|/* Sync status bit	*/
name|DP_LEAPSEC_DAY10DAY1
init|=
literal|0x82
block|,
comment|/* DP RAM address	*/
name|DP_LEAPSEC_DAY1000DAY100
init|=
literal|0x83
block|,
name|DELAY
init|=
literal|1
block|,
name|NUNIT
init|=
literal|2
comment|/* max UNITS		*/
block|}
enum|;
end_enum

begin_comment
comment|/*	clock card registers	*/
end_comment

begin_struct
struct|struct
name|psc_regs
block|{
name|uint32_t
name|low_time
decl_stmt|;
comment|/* card base + 0x00	*/
name|uint32_t
name|high_time
decl_stmt|;
comment|/* card base + 0x04	*/
name|uint32_t
name|ext_low_time
decl_stmt|;
comment|/* card base + 0x08	*/
name|uint32_t
name|ext_high_time
decl_stmt|;
comment|/* card base + 0x0C	*/
name|uint8_t
name|device_status
decl_stmt|;
comment|/* card base + 0x10	*/
name|uint8_t
name|device_control
decl_stmt|;
comment|/* card base + 0x11	*/
name|uint8_t
name|reserved0
decl_stmt|;
comment|/* card base + 0x12	*/
name|uint8_t
name|ext_100ns
decl_stmt|;
comment|/* card base + 0x13	*/
name|uint8_t
name|match_usec
decl_stmt|;
comment|/* card base + 0x14	*/
name|uint8_t
name|match_msec
decl_stmt|;
comment|/* card base + 0x15	*/
name|uint8_t
name|reserved1
decl_stmt|;
comment|/* card base + 0x16	*/
name|uint8_t
name|reserved2
decl_stmt|;
comment|/* card base + 0x17	*/
name|uint8_t
name|reserved3
decl_stmt|;
comment|/* card base + 0x18	*/
name|uint8_t
name|reserved4
decl_stmt|;
comment|/* card base + 0x19	*/
name|uint8_t
name|dp_ram_addr
decl_stmt|;
comment|/* card base + 0x1A	*/
name|uint8_t
name|reserved5
decl_stmt|;
comment|/* card base + 0x1B	*/
name|uint8_t
name|reserved6
decl_stmt|;
comment|/* card base + 0x1C	*/
name|uint8_t
name|reserved7
decl_stmt|;
comment|/* card base + 0x1D	*/
name|uint8_t
name|dp_ram_data
decl_stmt|;
comment|/* card base + 0x1E	*/
name|uint8_t
name|reserved8
decl_stmt|;
comment|/* card base + 0x1F	*/
block|}
modifier|*
decl|volatile
name|regp
index|[
name|NUNIT
index|]
struct|;
end_struct

begin_define
define|#
directive|define
name|PSC_REGS
value|_IOR('K', 0, long)
end_define

begin_comment
comment|/* ioctl argument	*/
end_comment

begin_comment
comment|/* Macros to swap byte order and convert BCD to binary	*/
end_comment

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|val
parameter_list|)
value|( ((val)>> 24) | (((val)& 0x00ff0000)>> 8) | \ (((val)& 0x0000ff00)<< 8) | (((val)& 0x000000ff)<< 24) )
end_define

begin_define
define|#
directive|define
name|BCD2INT2
parameter_list|(
name|val
parameter_list|)
value|( ((val)>> 4& 0x0f)*10 + ((val)& 0x0f) )
end_define

begin_define
define|#
directive|define
name|BCD2INT3
parameter_list|(
name|val
parameter_list|)
value|( ((val)>> 8& 0x0f)*100 + ((val)>> 4& 0x0f)*10 + \ ((val)& 0x0f) )
end_define

begin_comment
comment|/* PSC interface definitions */
end_comment

begin_define
define|#
directive|define
name|PRECISION
value|(-20)
end_define

begin_comment
comment|/* precision assumed (1 us)	*/
end_comment

begin_define
define|#
directive|define
name|REFID
value|"USNO"
end_define

begin_comment
comment|/* reference ID	*/
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"Brandywine PCI-SyncClock32"
end_define

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/refclock%1d"
end_define

begin_comment
comment|/* device file	*/
end_comment

begin_comment
comment|/* clock unit control structure */
end_comment

begin_struct
struct|struct
name|psc_unit
block|{
name|short
name|unit
decl_stmt|;
comment|/* NTP refclock unit number	*/
name|short
name|last_hour
decl_stmt|;
comment|/* last hour (monitor leap sec)	*/
name|int
name|msg_flag
index|[
literal|2
index|]
decl_stmt|;
comment|/* count error messages		*/
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|fd
index|[
name|NUNIT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor	*/
end_comment

begin_comment
comment|/* Local function prototypes */
end_comment

begin_function_decl
specifier|static
name|int
name|psc_start
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|psc_shutdown
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|psc_poll
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|check_leap_sec
parameter_list|(
name|struct
name|refclockproc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Transfer vector	*/
end_comment

begin_decl_stmt
name|struct
name|refclock
name|refclock_gpsvme
init|=
block|{
name|psc_start
block|,
name|psc_shutdown
block|,
name|psc_poll
block|,
name|noentry
block|,
name|noentry
block|,
name|noentry
block|,
name|NOFLAGS
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* psc_start:  open device and initialize data for processing */
end_comment

begin_function
specifier|static
name|int
name|psc_start
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
name|char
name|buf
index|[
name|BUFSIZE
index|]
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|struct
name|psc_unit
modifier|*
name|up
init|=
name|emalloc
argument_list|(
sizeof|sizeof
expr|*
name|up
argument_list|)
decl_stmt|;
if|if
condition|(
name|unit
operator|<
literal|0
operator|||
name|unit
operator|>
literal|1
condition|)
block|{
comment|/* support units 0 and 1	*/
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"psc_start: bad unit: %d"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|memset
argument_list|(
name|up
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
expr|*
name|up
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|DEVICE
argument_list|,
name|unit
argument_list|)
expr_stmt|;
comment|/* dev file name	*/
name|fd
index|[
name|unit
index|]
operator|=
name|open
argument_list|(
name|buf
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
comment|/* open device file	*/
if|if
condition|(
name|fd
index|[
name|unit
index|]
operator|<
literal|0
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"psc_start: unit: %d, open failed.  %m"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* get the address of the mapped regs	*/
if|if
condition|(
name|ioctl
argument_list|(
name|fd
index|[
name|unit
index|]
argument_list|,
name|PSC_REGS
argument_list|,
operator|&
name|regp
index|[
name|unit
index|]
argument_list|)
operator|<
literal|0
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"psc_start: unit: %d, ioctl failed.  %m"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* initialize peer variables	*/
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|clock_recv
operator|=
name|noentry
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|srcclock
operator|=
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
operator|-
literal|1
expr_stmt|;
name|pp
operator|->
name|unitptr
operator|=
name|up
expr_stmt|;
name|get_systime
argument_list|(
operator|&
name|pp
operator|->
name|lastrec
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
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
name|up
operator|->
name|unit
operator|=
name|unit
expr_stmt|;
ifdef|#
directive|ifdef
name|__hpux
name|rtprio
argument_list|(
literal|0
argument_list|,
literal|120
argument_list|)
expr_stmt|;
comment|/* set real time priority	*/
name|plock
argument_list|(
name|PROCLOCK
argument_list|)
expr_stmt|;
comment|/* lock process in memory	*/
endif|#
directive|endif
comment|/* __hpux	*/
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* psc_shutdown:  shut down the clock */
end_comment

begin_function
specifier|static
name|void
name|psc_shutdown
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
if|if
condition|(
name|NULL
operator|!=
name|peer
operator|->
name|procptr
operator|->
name|unitptr
condition|)
name|free
argument_list|(
name|peer
operator|->
name|procptr
operator|->
name|unitptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
index|[
name|unit
index|]
operator|>
literal|0
condition|)
name|close
argument_list|(
name|fd
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* psc_poll:  read, decode, and record device time */
end_comment

begin_function
specifier|static
name|void
name|psc_poll
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
name|struct
name|refclockproc
modifier|*
name|pp
init|=
name|peer
operator|->
name|procptr
decl_stmt|;
name|struct
name|psc_unit
modifier|*
name|up
decl_stmt|;
name|unsigned
name|tlo
decl_stmt|,
name|thi
decl_stmt|;
name|unsigned
name|char
name|status
decl_stmt|;
name|up
operator|=
operator|(
expr|struct
name|psc_unit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
name|tlo
operator|=
name|regp
index|[
name|unit
index|]
operator|->
name|low_time
expr_stmt|;
comment|/* latch and read first 4 bytes	*/
name|thi
operator|=
name|regp
index|[
name|unit
index|]
operator|->
name|high_time
expr_stmt|;
comment|/* read 4 higher order bytes	*/
name|status
operator|=
name|regp
index|[
name|unit
index|]
operator|->
name|device_status
expr_stmt|;
comment|/* read device status byte	*/
if|if
condition|(
operator|!
operator|(
name|status
operator|&
name|PSC_SYNC_OK
operator|)
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|up
operator|->
name|msg_flag
index|[
name|unit
index|]
condition|)
block|{
comment|/* write once to system log	*/
name|msyslog
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"SYNCHRONIZATION LOST on unit %1d, status %02x\n"
argument_list|,
name|unit
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|up
operator|->
name|msg_flag
index|[
name|unit
index|]
operator|=
literal|1
expr_stmt|;
block|}
return|return;
block|}
name|get_systime
argument_list|(
operator|&
name|pp
operator|->
name|lastrec
argument_list|)
expr_stmt|;
name|pp
operator|->
name|polls
operator|++
expr_stmt|;
name|tlo
operator|=
name|SWAP
argument_list|(
name|tlo
argument_list|)
expr_stmt|;
comment|/* little to big endian swap on	*/
name|thi
operator|=
name|SWAP
argument_list|(
name|thi
argument_list|)
expr_stmt|;
comment|/* copy of data			*/
comment|/* convert the BCD time to broken down time used by refclockproc	*/
name|pp
operator|->
name|day
operator|=
name|BCD2INT3
argument_list|(
operator|(
name|thi
operator|&
literal|0x0FFF0000
operator|)
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|pp
operator|->
name|hour
operator|=
name|BCD2INT2
argument_list|(
operator|(
name|thi
operator|&
literal|0x0000FF00
operator|)
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|pp
operator|->
name|minute
operator|=
name|BCD2INT2
argument_list|(
name|thi
operator|&
literal|0x000000FF
argument_list|)
expr_stmt|;
name|pp
operator|->
name|second
operator|=
name|BCD2INT2
argument_list|(
name|tlo
operator|>>
literal|24
argument_list|)
expr_stmt|;
comment|/* ntp_process() in ntp_refclock.c appears to use usec as fraction of        second in microseconds if usec is nonzero. */
name|pp
operator|->
name|nsec
operator|=
literal|1000000
operator|*
name|BCD2INT3
argument_list|(
operator|(
name|tlo
operator|&
literal|0x00FFF000
operator|)
operator|>>
literal|12
argument_list|)
operator|+
name|BCD2INT3
argument_list|(
name|tlo
operator|&
literal|0x00000FFF
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|,
sizeof|sizeof
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|)
argument_list|,
literal|"%3.3d %2.2d:%2.2d:%2.2d.%09ld %02x %08x %08x"
argument_list|,
name|pp
operator|->
name|day
argument_list|,
name|pp
operator|->
name|hour
argument_list|,
name|pp
operator|->
name|minute
argument_list|,
name|pp
operator|->
name|second
argument_list|,
name|pp
operator|->
name|nsec
argument_list|,
name|status
argument_list|,
name|thi
argument_list|,
name|tlo
argument_list|)
expr_stmt|;
name|pp
operator|->
name|lencode
operator|=
name|strlen
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|)
expr_stmt|;
comment|/* compute the timecode timestamp	*/
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
comment|/* simulate the NTP receive and packet procedures	*/
name|refclock_receive
argument_list|(
name|peer
argument_list|)
expr_stmt|;
comment|/* write clock statistics to file	*/
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
comment|/* With the first timecode beginning the day, check for a GPS        leap second notification.      */
if|if
condition|(
name|pp
operator|->
name|hour
operator|<
name|up
operator|->
name|last_hour
condition|)
block|{
name|check_leap_sec
argument_list|(
name|pp
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|up
operator|->
name|msg_flag
index|[
literal|0
index|]
operator|=
name|up
operator|->
name|msg_flag
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
comment|/* reset flags	*/
block|}
name|up
operator|->
name|last_hour
operator|=
name|pp
operator|->
name|hour
expr_stmt|;
block|}
end_function

begin_comment
comment|/* check_leap_sec:  read the Dual Port RAM leap second day registers.  The    onboard GPS receiver should write the hundreds digit of day of year in    DP_LeapSec_Day1000Day100 and the tens and ones digits in    DP_LeapSec_Day10Day1.  If these values are nonzero and today, we have    a leap second pending, so we set the pp->leap flag to LEAP_ADDSECOND.    If the BCD data are zero or a date other than today, set pp->leap to    LEAP_NOWARNING.  */
end_comment

begin_function
specifier|static
name|void
name|check_leap_sec
parameter_list|(
name|struct
name|refclockproc
modifier|*
name|pp
parameter_list|,
name|int
name|unit
parameter_list|)
block|{
name|unsigned
name|char
name|dhi
decl_stmt|,
name|dlo
decl_stmt|;
name|int
name|leap_day
decl_stmt|;
name|regp
index|[
name|unit
index|]
operator|->
name|dp_ram_addr
operator|=
name|DP_LEAPSEC_DAY10DAY1
expr_stmt|;
name|usleep
argument_list|(
name|DELAY
argument_list|)
expr_stmt|;
name|dlo
operator|=
name|regp
index|[
name|unit
index|]
operator|->
name|dp_ram_data
expr_stmt|;
name|regp
index|[
name|unit
index|]
operator|->
name|dp_ram_addr
operator|=
name|DP_LEAPSEC_DAY1000DAY100
expr_stmt|;
name|usleep
argument_list|(
name|DELAY
argument_list|)
expr_stmt|;
name|dhi
operator|=
name|regp
index|[
name|unit
index|]
operator|->
name|dp_ram_data
expr_stmt|;
name|leap_day
operator|=
name|BCD2INT2
argument_list|(
name|dlo
argument_list|)
operator|+
literal|100
operator|*
operator|(
name|dhi
operator|&
literal|0x0F
operator|)
expr_stmt|;
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOWARNING
expr_stmt|;
comment|/* default	*/
if|if
condition|(
name|leap_day
operator|&&
name|leap_day
operator|==
name|pp
operator|->
name|day
condition|)
block|{
name|pp
operator|->
name|leap
operator|=
name|LEAP_ADDSECOND
expr_stmt|;
comment|/* leap second today	*/
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"LEAP_ADDSECOND flag set, day %d (%x %x)."
argument_list|,
name|leap_day
argument_list|,
name|dhi
argument_list|,
name|dlo
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_gpsvme_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK	*/
end_comment

end_unit

