begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_leap.c,v 3.1 1993/07/06 01:11:18 jbj Exp  * ntp_leap - maintain leap bits and take action when a leap occurs  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntpd.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_comment
comment|/*  * This module is devoted to maintaining the leap bits and taking  * action when a leap second occurs.  It probably has bugs since  * a leap second has never occurred to excercise the code.  *  * The code does two things when a leap second occurs.  It first  * steps the clock one second in the appropriate direction.  It  * then informs the reference clock code, if compiled in, that the  * leap second has occured so that any clocks which need to disable  * themselves can do so.  This is done within the first few seconds  * after midnight, UTC.  *  * The code maintains two variables which may be written externally,  * leap_warning and leap_indicator.  Leap_warning can be written  * any time in the month preceeding a leap second.  24 hours before  * the leap is to occur, leap_warning's contents are copied to  * leap_indicator.  The latter is used by reference clocks to set  * their leap bits.  *  * The module normally maintains a timer which is arranged to expire  * just after 0000Z one day before the leap.  On the day a leap might  * occur the interrupt is aimed at 2200Z and every 5 minutes thereafter  * until 1200Z to see if the leap bits appear.  */
end_comment

begin_comment
comment|/*  * The leap indicator and leap warning flags.  Set by control messages  */
end_comment

begin_decl_stmt
name|u_char
name|leap_indicator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|leap_warning
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|leap_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set on day before a potential leap */
end_comment

begin_comment
comment|/*  * Timer.  The timer code imports this so it can call us prior to  * calling out any pending transmits.  */
end_comment

begin_decl_stmt
name|U_LONG
name|leap_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * We don't want to do anything drastic if the leap function is handled  * by the kernel.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pll_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set nonzero if kernel pll in uss */
end_comment

begin_comment
comment|/*  * Internal leap bits.  If we see leap bits set during the last  * hour we set these.  */
end_comment

begin_decl_stmt
name|u_char
name|leapbits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Constants.  */
end_comment

begin_define
define|#
directive|define
name|OKAYTOSETWARNING
value|(31*24*60*60)
end_define

begin_define
define|#
directive|define
name|DAYBEFORE
value|(24*60*60)
end_define

begin_define
define|#
directive|define
name|TWOHOURSBEFORE
value|(2*60*60)
end_define

begin_define
define|#
directive|define
name|FIVEMINUTES
value|(5*60)
end_define

begin_define
define|#
directive|define
name|ONEMINUTE
value|(60)
end_define

begin_comment
comment|/*  * Imported from the timer module.  */
end_comment

begin_decl_stmt
specifier|extern
name|U_LONG
name|current_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Some statistics counters  */
end_comment

begin_decl_stmt
name|U_LONG
name|leap_processcalls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* calls to leap_process */
end_comment

begin_decl_stmt
name|U_LONG
name|leap_notclose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* leap found to be a LONG time from now */
end_comment

begin_decl_stmt
name|U_LONG
name|leap_monthofleap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in the month of a leap */
end_comment

begin_decl_stmt
name|U_LONG
name|leap_dayofleap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the day of the leap */
end_comment

begin_decl_stmt
name|U_LONG
name|leap_hoursfromleap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only 2 hours from leap */
end_comment

begin_decl_stmt
name|U_LONG
name|leap_happened
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* leap process saw the leap */
end_comment

begin_comment
comment|/*  * Imported from the main module  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|setnexttimeout
name|P
argument_list|(
operator|(
name|U_LONG
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * init_leap - initialize the leap module's data.  */
end_comment

begin_function
name|void
name|init_leap
parameter_list|()
block|{
comment|/* 	 * Zero the indicators.  Schedule an event for just after 	 * initialization so we can sort things out. 	 */
name|leap_indicator
operator|=
name|leap_warning
operator|=
name|leap_mask
operator|=
literal|0
expr_stmt|;
name|leap_timer
operator|=
literal|1
operator|<<
name|EVENT_TIMEOUT
expr_stmt|;
name|leapbits
operator|=
literal|0
expr_stmt|;
name|leap_processcalls
operator|=
name|leap_notclose
operator|=
literal|0
expr_stmt|;
name|leap_monthofleap
operator|=
name|leap_dayofleap
operator|=
literal|0
expr_stmt|;
name|leap_hoursfromleap
operator|=
name|leap_happened
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * leap_process - process a leap event expiry and/or a system time step  */
end_comment

begin_function
name|void
name|leap_process
parameter_list|()
block|{
name|U_LONG
name|leapnext
decl_stmt|;
name|U_LONG
name|leaplast
decl_stmt|;
name|l_fp
name|ts
decl_stmt|;
name|u_char
name|bits
decl_stmt|;
specifier|extern
name|u_char
name|sys_leap
decl_stmt|;
name|leap_processcalls
operator|++
expr_stmt|;
name|get_systime
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
name|calleapwhen
argument_list|(
name|ts
operator|.
name|l_ui
argument_list|,
operator|&
name|leaplast
argument_list|,
operator|&
name|leapnext
argument_list|)
expr_stmt|;
comment|/* 	 * Figure out what to do based on how LONG to the next leap. 	 */
if|if
condition|(
name|leapnext
operator|>
name|OKAYTOSETWARNING
condition|)
block|{
if|if
condition|(
name|leaplast
operator|<
name|ONEMINUTE
condition|)
block|{
comment|/* 			 * The golden moment!  See if there's anything 			 * to do. 			 */
name|leap_happened
operator|++
expr_stmt|;
name|bits
operator|=
literal|0
expr_stmt|;
name|leap_mask
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|leap_indicator
operator|!=
literal|0
condition|)
name|bits
operator|=
name|leap_indicator
expr_stmt|;
elseif|else
if|if
condition|(
name|leapbits
operator|!=
literal|0
condition|)
name|bits
operator|=
name|leapbits
expr_stmt|;
if|if
condition|(
name|bits
operator|!=
literal|0
operator|&&
operator|!
name|pll_control
condition|)
block|{
name|l_fp
name|tmp
decl_stmt|;
comment|/* 				 * Step the clock 1 second in the proper 				 * direction. 				 */
if|if
condition|(
name|bits
operator|==
name|LEAP_DELSECOND
condition|)
name|tmp
operator|.
name|l_i
operator|=
literal|1
expr_stmt|;
else|else
name|tmp
operator|.
name|l_i
operator|=
operator|-
literal|1
expr_stmt|;
name|tmp
operator|.
name|l_uf
operator|=
literal|0
expr_stmt|;
name|step_systime
argument_list|(
operator|&
name|tmp
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SLEWALWAYS
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"leap second occured, slewed time %s 1 second"
argument_list|,
name|tmp
operator|.
name|l_i
operator|>
literal|0
condition|?
literal|"forward"
else|:
literal|"back"
argument_list|)
expr_stmt|;
else|#
directive|else
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"leap second occured, stepped time %s 1 second"
argument_list|,
name|tmp
operator|.
name|l_i
operator|>
literal|0
condition|?
literal|"forward"
else|:
literal|"back"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
else|else
block|{
name|leap_notclose
operator|++
expr_stmt|;
block|}
name|leap_warning
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|leapnext
operator|>
name|DAYBEFORE
condition|)
name|leap_monthofleap
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
name|leapnext
operator|>
name|TWOHOURSBEFORE
condition|)
name|leap_dayofleap
operator|++
expr_stmt|;
else|else
name|leap_hoursfromleap
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|leapnext
operator|>
name|DAYBEFORE
condition|)
block|{
name|leap_indicator
operator|=
literal|0
expr_stmt|;
name|leapbits
operator|=
literal|0
expr_stmt|;
comment|/* 		 * Berkeley's setitimer call does result in alarm 		 * signal drift despite rumours to the contrary. 		 * Schedule an event no more than 24 hours into 		 * the future to allow the event time to be 		 * recomputed. 		 */
if|if
condition|(
operator|(
name|leapnext
operator|-
name|DAYBEFORE
operator|)
operator|>=
name|DAYBEFORE
condition|)
name|setnexttimeout
argument_list|(
operator|(
name|U_LONG
operator|)
name|DAYBEFORE
argument_list|)
expr_stmt|;
else|else
name|setnexttimeout
argument_list|(
name|leapnext
operator|-
name|DAYBEFORE
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Here we're in the day of the leap.  Set the leap indicator 	 * bits from the warning, if necessary. 	 */
if|if
condition|(
name|leap_indicator
operator|==
literal|0
operator|&&
name|leap_warning
operator|!=
literal|0
condition|)
name|leap_indicator
operator|=
name|leap_warning
expr_stmt|;
name|leap_mask
operator|=
name|LEAP_NOTINSYNC
expr_stmt|;
if|if
condition|(
name|leapnext
operator|>
name|TWOHOURSBEFORE
condition|)
block|{
name|leapbits
operator|=
literal|0
expr_stmt|;
name|setnexttimeout
argument_list|(
name|leapnext
operator|-
name|TWOHOURSBEFORE
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Here we're in the final 2 hours.  If sys_leap is set, set 	 * leapbits to it. 	 */
if|if
condition|(
name|sys_leap
operator|==
name|LEAP_ADDSECOND
operator|||
name|sys_leap
operator|==
name|LEAP_DELSECOND
condition|)
name|leapbits
operator|=
name|sys_leap
expr_stmt|;
name|setnexttimeout
argument_list|(
operator|(
name|leapnext
operator|>
name|FIVEMINUTES
operator|)
condition|?
name|FIVEMINUTES
else|:
name|leapnext
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * setnexttimeout - set the next leap alarm  */
end_comment

begin_function
specifier|static
name|void
name|setnexttimeout
parameter_list|(
name|secs
parameter_list|)
name|U_LONG
name|secs
decl_stmt|;
block|{
comment|/* 	 * We try to aim the time out at between 1 and 1+(1<<EVENT_TIMEOUT) 	 * seconds after the desired time. 	 */
name|leap_timer
operator|=
operator|(
name|secs
operator|+
literal|1
operator|+
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
operator|+
name|current_time
operator|)
operator|&
operator|~
operator|(
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
operator|-
literal|1
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * leap_setleap - set leap_indicator and/or leap_warning.  Return failure  *		  if we don't want to do it.  */
end_comment

begin_function
name|int
name|leap_setleap
parameter_list|(
name|indicator
parameter_list|,
name|warning
parameter_list|)
name|int
name|indicator
decl_stmt|;
name|int
name|warning
decl_stmt|;
block|{
name|U_LONG
name|leapnext
decl_stmt|;
name|U_LONG
name|leaplast
decl_stmt|;
name|l_fp
name|ts
decl_stmt|;
name|int
name|i
decl_stmt|;
name|get_systime
argument_list|(
operator|&
name|ts
argument_list|)
expr_stmt|;
name|calleapwhen
argument_list|(
name|ts
operator|.
name|l_ui
argument_list|,
operator|&
name|leaplast
argument_list|,
operator|&
name|leapnext
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|warning
operator|!=
operator|~
literal|0
condition|)
if|if
condition|(
name|leapnext
operator|>
name|OKAYTOSETWARNING
condition|)
name|i
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|indicator
operator|!=
operator|~
literal|0
condition|)
if|if
condition|(
name|leapnext
operator|>
name|DAYBEFORE
condition|)
name|i
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|i
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"attempt to set leap bits at unlikely time of month"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|warning
operator|!=
operator|~
literal|0
condition|)
name|leap_warning
operator|=
name|warning
expr_stmt|;
if|if
condition|(
name|indicator
operator|!=
operator|~
literal|0
condition|)
block|{
if|if
condition|(
name|indicator
operator|==
name|LEAP_NOWARNING
condition|)
block|{
name|leap_warning
operator|=
name|LEAP_NOWARNING
expr_stmt|;
block|}
name|leap_indicator
operator|=
name|indicator
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * leap_actual  *  * calculate leap value - pass arg through of no local  * configuration. Otherwise ise local configuration  * (only used to cope with broken time servers and  * broken refclocks)  *  * Mapping of leap_indicator:  *	LEAP_NOWARNING  *		pass peer value to sys_leap - usual operation  *	LEAP_ADD/DEL_SECOND  *		pass  LEAP_ADD/DEL_SECOND to sys_leap  *	LEAP_NOTINSYNC  *		pass LEAP_NOWARNING to sys_leap - effectively ignores leap  */
end_comment

begin_comment
comment|/* there seems to be a bug in the IRIX 4 compiler which prevents    u_char from beeing used in prototyped functions    AIX also suffers from this.    So give up and define it terms of int. */
end_comment

begin_function
name|int
name|leap_actual
parameter_list|(
name|l
parameter_list|)
name|int
name|l
decl_stmt|;
block|{
if|if
condition|(
name|leap_indicator
operator|!=
name|LEAP_NOWARNING
condition|)
block|{
if|if
condition|(
name|leap_indicator
operator|==
name|LEAP_NOTINSYNC
condition|)
return|return
name|LEAP_NOWARNING
return|;
else|else
return|return
name|leap_indicator
return|;
block|}
else|else
block|{
return|return
name|l
return|;
block|}
block|}
end_function

end_unit

