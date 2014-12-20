begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_comment
comment|/* our private version */
end_comment

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_include
include|#
directive|include
file|"ntp_debug.h"
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
file|"clockstuff.h"
end_include

begin_comment
comment|/*  * setpriority  *  * to reduce the #ifdef forest in the portable code,  * we emulate the BSD setpriority interface:  *  * 		if (-1 == setpriority(PRIO_PROCESS, 0, NTP_PRIO))  * 			msyslog(LOG_ERR, "setpriority() error: %m");  *  * However, since the Windows port of ntpd has always raised its  * priority (to realtime if allowed, or silently downgraded to   * high by the system if not) with or without -N.  Changing that  * now would endanger users who upgrade the binary without adding  * -N to its invocation.  Instsrv assumes ntpd.exe is installed  * with no command-line arguments.  *  * This routine is used by utilities as well as ntpd itself, so  * it checks if the priority is already high or realtime and   * logs no complaints in that case, to avoid duplicating.  ntpd  * will have raised the priority to one of those in  * init_winnt_time, while the utilities will rely on this  * code.  *  */
end_comment

begin_function
name|int
name|setpriority
parameter_list|(
name|int
name|which
parameter_list|,
name|int
name|who
parameter_list|,
name|int
name|prio
parameter_list|)
block|{
name|BOOL
name|success
decl_stmt|;
name|DWORD
name|prio_class
decl_stmt|;
if|if
condition|(
name|PRIO_PROCESS
operator|!=
name|which
operator|||
name|who
operator|||
name|NTP_PRIO
operator|!=
name|prio
condition|)
name|TRACE
argument_list|(
literal|1
argument_list|,
operator|(
literal|"windows setpriority() clone needs work.\n"
operator|)
argument_list|)
expr_stmt|;
name|prio_class
operator|=
name|GetPriorityClass
argument_list|(
name|GetCurrentProcess
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|HIGH_PRIORITY_CLASS
operator|==
name|prio_class
operator|||
name|REALTIME_PRIORITY_CLASS
operator|==
name|prio_class
condition|)
return|return
literal|0
return|;
name|success
operator|=
name|SetPriorityClass
argument_list|(
name|GetCurrentProcess
argument_list|()
argument_list|,
name|REALTIME_PRIORITY_CLASS
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Unable to raise priority: %m"
argument_list|)
expr_stmt|;
name|errno
operator|=
name|EPERM
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|prio_class
operator|=
name|GetPriorityClass
argument_list|(
name|GetCurrentProcess
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|REALTIME_PRIORITY_CLASS
operator|==
name|prio_class
condition|)
name|msyslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"Raised to realtime priority class"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|HIGH_PRIORITY_CLASS
operator|==
name|prio_class
condition|)
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Raised to high priority class, realtime "
literal|"requires Increase Scheduling Priority "
literal|"privilege (enabled with secpol.msc)."
argument_list|)
expr_stmt|;
else|else
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Unexpected process priority class %d"
argument_list|,
name|prio_class
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

