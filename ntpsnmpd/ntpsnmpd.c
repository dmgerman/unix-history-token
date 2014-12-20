begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************  *  *  ntpsnmpd.c  *  *  The NTP SNMP daemon is an Agent X subagent application that   *  registers itself with a running SNMP Agent X master process running  *  on the same machine on port TCP 705. It utilizes the libntqp library  *  which accesses status and general data of a running ntpd process on  *  the same machine and enables the user to monitor the status of a  *  ntp daemon process via SNMP.   *  *  This started as a Google Summer of Code 2008 project,   *  including the ntpsnmpd sub agent and the libntpq library.   *  *  For more information please visit  *	http://support.ntp.org/bin/view/Dev/GSoC2008snmp  *  Or contact:  *   Harlan Stenn   (Mentor) at stenn@ntp.org  *   Heiko Gerstung (Student) at gerstung@ntp.org   *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<ntp_snmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS
end_ifdef

begin_comment
comment|/* needed with at least Solaris 8 */
end_comment

begin_include
include|#
directive|include
file|<siginfo.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<libntpq.h>
end_include

begin_include
include|#
directive|include
file|<ntpsnmpd-opts.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|keep_running
decl_stmt|;
end_decl_stmt

begin_function_decl
name|RETSIGTYPE
name|stop_server
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|RETSIGTYPE
name|stop_server
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|keep_running
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* The main function just sets up a few things and then enters a loop in which it will   * wait for SNMP requests coming from the master agent   */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|background
init|=
literal|0
decl_stmt|;
comment|/* start as background process */
name|int
name|use_syslog
init|=
literal|1
decl_stmt|;
comment|/* use syslog for logging */
block|{
name|int
name|optct
init|=
name|optionProcess
argument_list|(
operator|&
name|ntpsnmpdOptions
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|argc
operator|-=
name|optct
expr_stmt|;
name|argv
operator|+=
name|optct
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|HAVE_OPT
argument_list|(
name|NOFORK
argument_list|)
condition|)
name|background
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|HAVE_OPT
argument_list|(
name|SYSLOG
argument_list|)
condition|)
name|use_syslog
operator|=
literal|0
expr_stmt|;
comment|/* using the net-snmp syslog facility */
if|if
condition|(
name|use_syslog
condition|)
name|snmp_enable_calllog
argument_list|()
expr_stmt|;
else|else
name|snmp_enable_stderrlog
argument_list|()
expr_stmt|;
comment|/* Become Subagent */
name|netsnmp_ds_set_boolean
argument_list|(
name|NETSNMP_DS_APPLICATION_ID
argument_list|,
name|NETSNMP_DS_AGENT_ROLE
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* go into background mode, if requested */
if|if
condition|(
name|background
operator|&&
name|netsnmp_daemonize
argument_list|(
literal|1
argument_list|,
operator|!
name|use_syslog
argument_list|)
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Now register with the master Agent X process */
comment|/* call Netsnmp socket startup macro, which will initialize the network stuff if required */
name|SOCK_STARTUP
expr_stmt|;
comment|/* Set AgentX socket interface */
name|netsnmp_ds_set_string
argument_list|(
name|NETSNMP_DS_APPLICATION_ID
argument_list|,
name|NETSNMP_DS_AGENT_X_SOCKET
argument_list|,
name|OPT_ARG
argument_list|(
name|AGENTXSOCKET
argument_list|)
argument_list|)
expr_stmt|;
name|init_agent
argument_list|(
literal|"ntpsnmpd"
argument_list|)
expr_stmt|;
comment|/* Try to connect to ntpd */
if|if
condition|(
name|ntpq_openhost
argument_list|(
literal|"localhost"
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error: Could not connect to ntpd. Aborting.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Register callback functions ...  */
name|init_ntpSnmpSubagentObject
argument_list|()
expr_stmt|;
name|init_snmp
argument_list|(
literal|"ntpsnmpd"
argument_list|)
expr_stmt|;
comment|/* Signal handler */
name|keep_running
operator|=
literal|1
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|stop_server
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|stop_server
argument_list|)
expr_stmt|;
name|snmp_log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"ntpsnmpd started.\n"
argument_list|)
expr_stmt|;
comment|/* main loop here... */
while|while
condition|(
name|keep_running
condition|)
block|{
name|agent_check_and_process
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* 0 == don't block */
block|}
comment|/* at shutdown time */
name|ntpq_closehost
argument_list|()
expr_stmt|;
name|snmp_shutdown
argument_list|(
literal|"ntpsnmpd"
argument_list|)
expr_stmt|;
name|SOCK_CLEANUP
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

