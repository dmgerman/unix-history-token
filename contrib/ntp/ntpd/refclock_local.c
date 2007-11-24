begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_local - local pseudo-clock driver  *  * wjm 17-aug-1995: add a hook for special treatment of VMS_LOCALUNIT  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_include
include|#
directive|include
file|"ntp_syscall.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is a hack to allow a machine to use its own system clock as a  * reference clock, i.e., to free-run using no outside clock discipline  * source. This is useful if you want to use NTP in an isolated  * environment with no radio clock or NIST modem available. Pick a  * machine that you figure has a good clock oscillator and configure it  * with this driver. Set the clock using the best means available, like  * eyeball-and-wristwatch. Then, point all the other machines at this  * one or use broadcast (not multicast) mode to distribute time.  *  * Another application for this driver is if you want to use a  * particular server's clock as the clock of last resort when all other  * normal synchronization sources have gone away. This is especially  * useful if that server has an ovenized oscillator. For this you would  * configure this driver at a higher stratum (say 5) to prevent the  * server's stratum from falling below that.  *  * A third application for this driver is when an external discipline  * source is available, such as the NIST "lockclock" program, which  * synchronizes the local clock via a telephone modem and the NIST  * Automated Computer Time Service (ACTS), or the Digital Time  * Synchronization Service (DTSS), which runs on DCE machines. In this  * case the stratum should be set at zero, indicating a bona fide  * stratum-1 source. Exercise some caution with this, since there is no  * easy way to telegraph via NTP that something might be wrong in the  * discipline source itself. In the case of DTSS, the local clock can  * have a rather large jitter, depending on the interval between  * corrections and the intrinsic frequency error of the clock  * oscillator. In extreme cases, this can cause clients to exceed the  * 128-ms slew window and drop off the NTP subnet.  *  * THis driver includes provisions to telegraph synchronization state  * and related variables by means of kernel variables with specially  * modified kernels. This is done using the ntp_adjtime() syscall.  * In the cases where another protocol or device synchronizes the local  * host, the data given to the kernel can be slurped up by this driver  * and distributed to clients by ordinary NTP messaging.  *  * In the default mode the behavior of the clock selection algorithm is  * modified when this driver is in use. The algorithm is designed so  * that this driver will never be selected unless no other discipline  * source is available. This can be overriden with the prefer keyword of  * the server configuration command, in which case only this driver will  * be selected for synchronization and all other discipline sources will  * be ignored. This behavior is intended for use when an external  * discipline source controls the system clock.  *  * Fudge Factors  *  * The stratum for this driver set at 5 by default, but it can be  * changed by the fudge command and/or the ntpdc utility. The reference  * ID is "LCL" by default, but can be changed using the same mechanism.  * *NEVER* configure this driver to operate at a stratum which might  * possibly disrupt a client with access to a bona fide primary server,  * unless the local clock oscillator is reliably disciplined by another  * source. *NEVER NEVER* configure a server which might devolve to an  * undisciplined local clock to use multicast mode. Always remember that  * an improperly configured local clock driver let loose in the Internet  * can cause very serious disruption. This is why most of us who care  * about good time use cryptographic authentication.  *  * This driver provides a mechanism to trim the local clock in both time  * and frequency, as well as a way to manipulate the leap bits. The  * fudge time1 parameter adjusts the time, in seconds, and the fudge  * time2 parameter adjusts the frequency, in ppm. The fudge time1  * parameter is additive; that is, it adds an increment to the current  * time. The fudge time2 parameter directly sets the frequency.  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
name|defined
argument_list|(
name|VMS_LOCALUNIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|REFID
value|"LCLv"
end_define

begin_comment
comment|/* reference ID */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VMS VMS_LOCALUNIT */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS VMS_LOCALUNIT */
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
value|5
end_define

begin_comment
comment|/* default stratum */
end_comment

begin_define
define|#
directive|define
name|DISPERSION
value|.01
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_comment
comment|/*  * Imported from ntp_loopfilter  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pll_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel pll control */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|kern_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel pll enabled */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ext_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external clock enable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_PLL */
end_comment

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
comment|/*  * Local variables  */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|poll_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last time polled */
end_comment

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
name|leap
operator|=
name|LEAP_NOTINSYNC
expr_stmt|;
name|peer
operator|->
name|stratum
operator|=
name|STRATUM
expr_stmt|;
name|pp
operator|->
name|stratum
operator|=
name|STRATUM
expr_stmt|;
name|pp
operator|->
name|clockdesc
operator|=
name|DESCRIPTION
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|pp
operator|->
name|refid
argument_list|,
literal|"INIT"
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|poll_time
operator|=
name|current_time
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * local_poll - called by the transmit procedure  *  * LOCKCLOCK: If the kernel supports the nanokernel or microkernel  * system calls, the leap bits are extracted from the kernel. If there  * is a kernel error or the kernel leap bits are set to 11, the NTP leap  * bits are set to 11 and the stratum is set to infinity. Otherwise, the  * NTP leap bits are set to the kernel leap bits and the stratum is set  * as fudged. This behavior does not faithfully follow the  * specification, but is probably more appropriate in a multiple-server  * national laboratory network.  */
end_comment

begin_function
specifier|static
name|void
name|local_poll
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
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_PLL
argument_list|)
operator|&&
name|defined
argument_list|(
name|LOCKCLOCK
argument_list|)
name|struct
name|timex
name|ntv
decl_stmt|;
endif|#
directive|endif
comment|/* KERNEL_PLL LOCKCLOCK */
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
name|defined
argument_list|(
name|VMS_LOCALUNIT
argument_list|)
if|if
condition|(
name|unit
operator|==
name|VMS_LOCALUNIT
condition|)
block|{
specifier|extern
name|void
name|vms_local_poll
argument_list|(
expr|struct
name|peer
operator|*
argument_list|)
decl_stmt|;
name|vms_local_poll
argument_list|(
name|peer
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
comment|/* VMS&& VMS_LOCALUNIT */
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
comment|/* 	 * Ramble through the usual filtering and grooming code, which 	 * is essentially a no-op and included mostly for pretty 	 * billboards. We allow a one-time time adjustment using fudge 	 * time1 (s) and a continuous frequency adjustment using fudge 	 * time 2 (ppm). 	 */
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
name|fudgetime1
operator|+=
name|pp
operator|->
name|fudgetime2
operator|*
literal|1e-6
operator|*
operator|(
name|current_time
operator|-
name|poll_time
operator|)
expr_stmt|;
name|poll_time
operator|=
name|current_time
expr_stmt|;
name|refclock_process_offset
argument_list|(
name|pp
argument_list|,
name|pp
operator|->
name|lastrec
argument_list|,
name|pp
operator|->
name|lastrec
argument_list|,
name|pp
operator|->
name|fudgetime1
argument_list|)
expr_stmt|;
comment|/* 	 * If another process is disciplining the system clock, we set 	 * the leap bits and quality indicators from the kernel. 	 */
if|#
directive|if
name|defined
argument_list|(
name|KERNEL_PLL
argument_list|)
operator|&&
name|defined
argument_list|(
name|LOCKCLOCK
argument_list|)
name|memset
argument_list|(
operator|&
name|ntv
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|ntv
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ntp_adjtime
argument_list|(
operator|&
name|ntv
argument_list|)
condition|)
block|{
case|case
name|TIME_OK
case|:
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOWARNING
expr_stmt|;
name|peer
operator|->
name|stratum
operator|=
name|pp
operator|->
name|stratum
expr_stmt|;
break|break;
case|case
name|TIME_INS
case|:
name|pp
operator|->
name|leap
operator|=
name|LEAP_ADDSECOND
expr_stmt|;
name|peer
operator|->
name|stratum
operator|=
name|pp
operator|->
name|stratum
expr_stmt|;
break|break;
case|case
name|TIME_DEL
case|:
name|pp
operator|->
name|leap
operator|=
name|LEAP_DELSECOND
expr_stmt|;
name|peer
operator|->
name|stratum
operator|=
name|pp
operator|->
name|stratum
expr_stmt|;
break|break;
default|default:
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOTINSYNC
expr_stmt|;
name|peer
operator|->
name|stratum
operator|=
name|STRATUM_UNSPEC
expr_stmt|;
block|}
name|pp
operator|->
name|disp
operator|=
literal|0
expr_stmt|;
name|pp
operator|->
name|jitter
operator|=
literal|0
expr_stmt|;
else|#
directive|else
comment|/* KERNEL_PLL LOCKCLOCK */
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOWARNING
expr_stmt|;
name|pp
operator|->
name|disp
operator|=
name|DISPERSION
expr_stmt|;
name|pp
operator|->
name|jitter
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* KERNEL_PLL LOCKCLOCK */
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
name|pp
operator|->
name|fudgetime1
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_local_bs
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

