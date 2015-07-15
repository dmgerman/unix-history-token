begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_atom - clock driver for 1-pps signals  */
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

begin_comment
comment|/*  * This driver requires the PPSAPI interface (RFC 2783)  */
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
name|CLOCK_ATOM
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_PPSAPI
argument_list|)
end_if

begin_include
include|#
directive|include
file|"ppsapi_timepps.h"
end_include

begin_include
include|#
directive|include
file|"refclock_atom.h"
end_include

begin_comment
comment|/*  * This driver furnishes an interface for pulse-per-second (PPS) signals  * produced by a cesium clock, timing receiver or related equipment. It  * can be used to remove accumulated jitter over a congested link and  * retime a server before redistributing the time to clients. It can   *also be used as a holdover should all other synchronization sources  * beconme unreachable.  *  * Before this driver becomes active, the local clock must be set to  * within +-0.4 s by another means, such as a radio clock or NTP  * itself. There are two ways to connect the PPS signal, normally at TTL  * levels, to the computer. One is to shift to EIA levels and connect to  * pin 8 (DCD) of a serial port. This requires a level converter and  * may require a one-shot flipflop to lengthen the pulse. The other is  * to connect the PPS signal directly to pin 10 (ACK) of a PC paralell  * port. These methods are architecture dependent.  *  * This driver requires the Pulse-per-Second API for Unix-like Operating  * Systems, Version 1.0, RFC-2783 (PPSAPI). Implementations are  * available for FreeBSD, Linux, SunOS, Solaris and Tru64. However, at  * present only the Tru64 implementation provides the full generality of  * the API with multiple PPS drivers and multiple handles per driver. If  * the PPSAPI is normally implemented in the /usr/include/sys/timepps.h  * header file and kernel support specific to each operating system.  *  * This driver normally uses the PLL/FLL clock discipline implemented in  * the ntpd code. Ordinarily, this is the most accurate means, as the  * median filter in the driver interface is much larger than in the  * kernel. However, if the systemic clock frequency error is large (tens  * to hundreds of PPM), it's better to used the kernel support, if  * available.  *  * This deriver is subject to the mitigation rules described in the  * "mitigation rulse and the prefer peer" page. However, there is an  * important difference. If this driver becomes the PPS driver according  * to these rules, it is acrive only if (a) a prefer peer other than  * this driver is among the survivors or (b) there are no survivors and  * the minsane option of the tos command is zero. This is intended to  * support space missions where updates from other spacecraft are  * infrequent, but a reliable PPS signal, such as from an Ultra Stable  * Oscillator (USO) is available.  *  * Fudge Factors  *  * The PPS timestamp is captured on the rising (assert) edge if flag2 is  * dim (default) and on the falling (clear) edge if lit. If flag3 is dim  * (default), the kernel PPS support is disabled; if lit it is enabled.  * If flag4 is lit, each timesampt is copied to the clockstats file for  * later analysis. This can be useful when constructing Allan deviation  * plots. The time1 parameter can be used to compensate for  * miscellaneous device driver and OS delays.  */
end_comment

begin_comment
comment|/*  * Interface definitions  */
end_comment

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/pps%d"
end_define

begin_comment
comment|/* device name and unit */
end_comment

begin_define
define|#
directive|define
name|PRECISION
value|(-20)
end_define

begin_comment
comment|/* precision assumed (about 1 us) */
end_comment

begin_define
define|#
directive|define
name|REFID
value|"PPS\0"
end_define

begin_comment
comment|/* reference ID */
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"PPS Clock Discipline"
end_define

begin_comment
comment|/* WRU */
end_comment

begin_comment
comment|/*  * PPS unit control structure  */
end_comment

begin_struct
struct|struct
name|ppsunit
block|{
name|struct
name|refclock_atom
name|atom
decl_stmt|;
comment|/* atom structure pointer */
name|int
name|fddev
decl_stmt|;
comment|/* file descriptor */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_function_decl
specifier|static
name|int
name|atom_start
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
name|atom_shutdown
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
name|atom_poll
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
name|atom_timer
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Transfer vector  */
end_comment

begin_decl_stmt
name|struct
name|refclock
name|refclock_atom
init|=
block|{
name|atom_start
block|,
comment|/* start up driver */
name|atom_shutdown
block|,
comment|/* shut down driver */
name|atom_poll
block|,
comment|/* transmit poll message */
name|noentry
block|,
comment|/* control (not used) */
name|noentry
block|,
comment|/* initialize driver (not used) */
name|noentry
block|,
comment|/* buginfo (not used) */
name|atom_timer
block|,
comment|/* called once per second */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * atom_start - initialize data for processing  */
end_comment

begin_function
specifier|static
name|int
name|atom_start
parameter_list|(
name|int
name|unit
parameter_list|,
comment|/* unit number (not used) */
name|struct
name|peer
modifier|*
name|peer
comment|/* peer structure pointer */
parameter_list|)
block|{
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|struct
name|ppsunit
modifier|*
name|up
decl_stmt|;
name|char
name|device
index|[
literal|80
index|]
decl_stmt|;
comment|/* 	 * Allocate and initialize unit structure 	 */
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
name|pp
operator|->
name|stratum
operator|=
name|STRATUM_UNSPEC
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
operator|=
name|emalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ppsunit
argument_list|)
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|up
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ppsunit
argument_list|)
argument_list|)
expr_stmt|;
name|pp
operator|->
name|unitptr
operator|=
name|up
expr_stmt|;
comment|/* 	 * Open PPS device. This can be any serial or parallel port and 	 * not necessarily the port used for the associated radio. 	 */
name|snprintf
argument_list|(
name|device
argument_list|,
sizeof|sizeof
argument_list|(
name|device
argument_list|)
argument_list|,
name|DEVICE
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|up
operator|->
name|fddev
operator|=
name|tty_open
argument_list|(
name|device
argument_list|,
name|O_RDWR
argument_list|,
literal|0777
argument_list|)
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|fddev
operator|<=
literal|0
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"refclock_atom: %s: %m"
argument_list|,
name|device
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * Light up the PPSAPI interface. 	 */
return|return
operator|(
name|refclock_ppsapi
argument_list|(
name|up
operator|->
name|fddev
argument_list|,
operator|&
name|up
operator|->
name|atom
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * atom_shutdown - shut down the clock  */
end_comment

begin_function
specifier|static
name|void
name|atom_shutdown
parameter_list|(
name|int
name|unit
parameter_list|,
comment|/* unit number (not used) */
name|struct
name|peer
modifier|*
name|peer
comment|/* peer structure pointer */
parameter_list|)
block|{
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|struct
name|ppsunit
modifier|*
name|up
decl_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
name|pp
operator|->
name|unitptr
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|fddev
operator|>
literal|0
condition|)
name|close
argument_list|(
name|up
operator|->
name|fddev
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
comment|/*  * atom_timer - called once per second  */
end_comment

begin_function
name|void
name|atom_timer
parameter_list|(
name|int
name|unit
parameter_list|,
comment|/* unit pointer (not used) */
name|struct
name|peer
modifier|*
name|peer
comment|/* peer structure pointer */
parameter_list|)
block|{
name|struct
name|ppsunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|char
name|tbuf
index|[
literal|80
index|]
decl_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
name|pp
operator|->
name|unitptr
expr_stmt|;
if|if
condition|(
name|refclock_pps
argument_list|(
name|peer
argument_list|,
operator|&
name|up
operator|->
name|atom
argument_list|,
name|pp
operator|->
name|sloppyclockflag
argument_list|)
operator|<=
literal|0
condition|)
return|return;
name|peer
operator|->
name|flags
operator||=
name|FLAG_PPS
expr_stmt|;
comment|/* 	 * If flag4 is lit, record each second offset to clockstats. 	 * That's so we can make awesome Allan deviation plots. 	 */
if|if
condition|(
name|pp
operator|->
name|sloppyclockflag
operator|&
name|CLK_FLAG4
condition|)
block|{
name|snprintf
argument_list|(
name|tbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"%.9f"
argument_list|,
name|pp
operator|->
name|filter
index|[
name|pp
operator|->
name|coderecv
index|]
argument_list|)
expr_stmt|;
name|record_clock_stats
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * atom_poll - called by the transmit procedure  */
end_comment

begin_function
specifier|static
name|void
name|atom_poll
parameter_list|(
name|int
name|unit
parameter_list|,
comment|/* unit number (not used) */
name|struct
name|peer
modifier|*
name|peer
comment|/* peer structure pointer */
parameter_list|)
block|{
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
comment|/* 	 * Don't wiggle the clock until some other driver has numbered 	 * the seconds. 	 */
if|if
condition|(
name|sys_leap
operator|==
name|LEAP_NOTINSYNC
condition|)
return|return;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|pp
operator|->
name|polls
operator|++
expr_stmt|;
if|if
condition|(
name|pp
operator|->
name|codeproc
operator|==
name|pp
operator|->
name|coderecv
condition|)
block|{
name|peer
operator|->
name|flags
operator|&=
operator|~
name|FLAG_PPS
expr_stmt|;
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_TIMEOUT
argument_list|)
expr_stmt|;
return|return;
block|}
name|pp
operator|->
name|lastref
operator|=
name|pp
operator|->
name|lastrec
expr_stmt|;
name|refclock_receive
argument_list|(
name|peer
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_atom_bs
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

