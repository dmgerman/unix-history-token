begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_local - local pseudo-clock driver  */
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
name|LOCAL_CLOCK
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

begin_include
include|#
directive|include
file|"ntpd.h"
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
comment|/*  * This is a hack to allow a machine to use its own system clock as a  * reference clock, i.e., to free-run using no outside clock discipline  * source. This is useful if you want to use NTP in an isolated  * environment with no radio clock or NIST modem available. Pick a  * machine that you figure has a good clock oscillator and configure it  * with this driver. Set the clock using the best means available, like  * eyeball-and-wristwatch. Then, point all the other machines at this  * one or use broadcast (not multicast) mode to distribute time.  *  * Another application for this driver is if you want to use a  * particular server's clock as the clock of last resort when all other  * normal synchronization sources have gone away. This is especially  * useful if that server has an ovenized oscillator. For this you would  * configure this driver at a higher stratum (say 3 or 4) to prevent the  * server's stratum from falling below that.  *  * A third application for this driver is when an external discipline  * source is available, such as the NIST "lockclock" program, which  * synchronizes the local clock via a telephone modem and the NIST  * Automated Computer Time Service (ACTS), or the Digital Time  * Synchronization Service (DTSS), which runs on DCE machines. In this  * case the stratum should be set at zero, indicating a bona fide  * stratum-1 source. Exercise some caution with this, since there is no  * easy way to telegraph via NTP that something might be wrong in the  * discipline source itself. In the case of DTSS, the local clock can  * have a rather large jitter, depending on the interval between  * corrections and the intrinsic frequency error of the clock  * oscillator. In extreme cases, this can cause clients to exceed the  * 128-ms slew window and drop off the NTP subnet.  *  * In the default mode the behavior of the clock selection algorithm is  * modified when this driver is in use. The algorithm is designed so  * that this driver will never be selected unless no other discipline  * source is available. This can be overriden with the prefer keyword of  * the server configuration command, in which case only this driver will  * be selected for synchronization and all other discipline sources will  * be ignored. This behavior is intended for use when an external  * discipline source controls the system clock.  *  * Fudge Factors  *  * The stratum for this driver LCLSTRATUM is set at 3 by default, but  * can be changed by the fudge command and/or the xntpdc utility. The  * reference ID is "LCL" by default, but can be changed using the same  * mechanisms. *NEVER* configure this driver to operate at a stratum  * which might possibly disrupt a client with access to a bona fide  * primary server, unless athe local clock oscillator is reliably  * disciplined by another source. *NEVER NEVER* configure a server which  * might devolve to an undisciplined local clock to use multicast mode.  *  * This driver provides a mechanism to trim the local clock in both time  * and frequency, as well as a way to manipulate the leap bits. The  * fudge time1 parameter adjusts the time, in seconds, and the fudge  * time2 parameter adjusts the frequency, in ppm. Both parameters are  * additive; that is, they add increments in time or frequency to the  * present values. The fudge flag1 and fudge flag2 bits set the  * corresponding leap bits; for example, setting flag1 causes a leap  * second to be added at the end of the UTC day. These bits are not  * reset automatically when the leap takes place; they must be turned  * off manually after the leap event.  */
end_comment

begin_comment
comment|/*  * Local interface definitions  */
end_comment

begin_define
define|#
directive|define
name|PRECISION
value|(-7)
end_define

begin_comment
comment|/* about 10 ms precision */
end_comment

begin_define
define|#
directive|define
name|REFID
value|"LCL\0"
end_define

begin_comment
comment|/* reference ID */
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"Undisciplined local clock"
end_define

begin_comment
comment|/* WRU */
end_comment

begin_define
define|#
directive|define
name|STRATUM
value|3
end_define

begin_comment
comment|/* default stratum */
end_comment

begin_define
define|#
directive|define
name|DISPERSION
value|(FP_SECOND / 100)
end_define

begin_comment
comment|/* default dispersion (10 ms) */
end_comment

begin_comment
comment|/*  * Imported from the timer module  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|current_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Imported from ntp_proto  */
end_comment

begin_decl_stmt
specifier|extern
name|s_char
name|sys_precision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|local_start
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
name|local_poll
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
comment|/*  * Transfer vector  */
end_comment

begin_decl_stmt
name|struct
name|refclock
name|refclock_local
init|=
block|{
name|local_start
block|,
comment|/* start up driver */
name|noentry
block|,
comment|/* shut down driver (not used) */
name|local_poll
block|,
comment|/* transmit poll message */
name|noentry
block|,
comment|/* not used (old lcl_control) */
name|noentry
block|,
comment|/* initialize driver (not used) */
name|noentry
block|,
comment|/* not used (old lcl_buginfo) */
name|NOFLAGS
comment|/* not used */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * local_start - start up the clock  */
end_comment

begin_function
specifier|static
name|int
name|local_start
parameter_list|(
name|unit
parameter_list|,
name|peer
parameter_list|)
name|int
name|unit
decl_stmt|;
name|struct
name|peer
modifier|*
name|peer
decl_stmt|;
block|{
specifier|register
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
comment|/* 	 * Initialize miscellaneous variables 	 */
name|peer
operator|->
name|precision
operator|=
name|sys_precision
expr_stmt|;
name|pp
operator|->
name|clockdesc
operator|=
name|DESCRIPTION
expr_stmt|;
name|peer
operator|->
name|stratum
operator|=
name|STRATUM
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
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * local_poll - called by the transmit procedure  */
end_comment

begin_function
specifier|static
name|void
name|local_poll
parameter_list|(
name|unit
parameter_list|,
name|peer
parameter_list|)
name|int
name|unit
decl_stmt|;
name|struct
name|peer
modifier|*
name|peer
decl_stmt|;
block|{
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
name|pp
operator|->
name|polls
operator|++
expr_stmt|;
name|pp
operator|->
name|lasttime
operator|=
name|current_time
expr_stmt|;
comment|/* 	 * Ramble through the usual filtering and grooming code, which 	 * is essentially a no-op and included mostly for pretty 	 * billboards. We fudge flags as the leap indicators and allow a 	 * one-time adjustment in time using fudge time1 (s) and 	 * frequency using fudge time 2 (ppm). 	 */
name|pp
operator|->
name|dispersion
operator|=
name|DISPERSION
expr_stmt|;
name|gettstamp
argument_list|(
operator|&
name|pp
operator|->
name|lastrec
argument_list|)
expr_stmt|;
name|refclock_receive
argument_list|(
name|peer
argument_list|,
operator|&
name|pp
operator|->
name|fudgetime1
argument_list|,
literal|0
argument_list|,
name|pp
operator|->
name|dispersion
argument_list|,
operator|&
name|pp
operator|->
name|lastrec
argument_list|,
operator|&
name|pp
operator|->
name|lastrec
argument_list|,
name|pp
operator|->
name|sloppyclockflag
argument_list|)
expr_stmt|;
name|adj_frequency
argument_list|(
name|LFPTOFP
argument_list|(
operator|&
name|pp
operator|->
name|fudgetime2
argument_list|)
argument_list|)
expr_stmt|;
name|L_CLR
argument_list|(
operator|&
name|pp
operator|->
name|fudgetime1
argument_list|)
expr_stmt|;
name|L_CLR
argument_list|(
operator|&
name|pp
operator|->
name|fudgetime2
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK */
end_comment

end_unit

