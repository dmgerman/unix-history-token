begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software is Copyright 1989 by Jack Hudler.  *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction or this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.  *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.  *  */
end_comment

begin_comment
comment|/****************************** Module Header ******************************\ * Module Name: alarm.c * Created    : 11-08-89 * Author     : Jack Hudler  [jack@csccat.lonestar.org] * Copyright  : 1988 Jack Hudler. * Function   : Unix like alarm signal simulator. \***************************************************************************/
end_comment

begin_comment
comment|/* Tested using OS2 1.2 with Microsoft C 5.1 and 6.0. */
end_comment

begin_define
define|#
directive|define
name|INCL_DOSPROCESS
end_define

begin_define
define|#
directive|define
name|INCL_DOSSIGNALS
end_define

begin_define
define|#
directive|define
name|INCL_DOS
end_define

begin_include
include|#
directive|include
file|<os2.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"alarm.h"
end_include

begin_define
define|#
directive|define
name|ALARM_STACK
value|4096
end_define

begin_comment
comment|/* This maybe over kill, but the page size is 4K */
end_comment

begin_decl_stmt
specifier|static
name|PBYTE
name|pbAlarmStack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|SEL
name|selAlarmStack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|TID
name|tidAlarm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|PID
name|pidMain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|BOOL
name|bAlarmInit
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|BOOL
name|bAlarmRunning
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|USHORT
name|uTime
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|VOID
name|FAR
name|alarm_thread
parameter_list|(
name|VOID
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
name|bAlarmRunning
condition|)
block|{
name|DosSleep
argument_list|(
literal|1000L
argument_list|)
expr_stmt|;
name|uTime
operator|--
expr_stmt|;
if|if
condition|(
name|uTime
operator|==
literal|0L
condition|)
block|{
comment|// send signal to the main process.. I could have put raise() here
comment|// however that would require the use of the multithreaded library,
comment|// and it does not contain raise()!
comment|// I tried it with the standard library, this signaled ok, but a
comment|// test printf in the signal would not work and even caused SEGV.
comment|// So I signal the process through OS/2 and then the process
comment|// signals itself.
if|if
condition|(
name|bAlarmRunning
condition|)
name|DosFlagProcess
argument_list|(
name|pidMain
argument_list|,
name|FLGP_PID
argument_list|,
name|PFLG_A
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|bAlarmRunning
operator|=
name|FALSE
expr_stmt|;
block|}
block|}
else|else
name|DosSleep
argument_list|(
literal|500L
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|VOID
name|PASCAL
name|FAR
name|AlarmSignal
parameter_list|(
name|USHORT
name|usSigArg
parameter_list|,
name|USHORT
name|usSigNum
parameter_list|)
block|{
comment|/*      * this is not executed from the thread. The thread triggers Process      * flag A which is in the main processes scope, this inturn triggers      * (via the raise) SIGUSR1 which is defined to SIGALRM.      */
name|raise
argument_list|(
name|SIGUSR1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|alarm_init
parameter_list|(
name|void
parameter_list|)
block|{
name|PFNSIGHANDLER
name|pfnPrev
decl_stmt|;
name|USHORT
name|pfAction
decl_stmt|;
name|PIDINFO
name|pid
decl_stmt|;
name|bAlarmInit
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
operator|!
name|DosAllocSeg
argument_list|(
name|ALARM_STACK
argument_list|,
operator|(
name|PSEL
operator|)
operator|&
name|selAlarmStack
argument_list|,
name|SEG_NONSHARED
argument_list|)
condition|)
block|{
name|OFFSETOF
argument_list|(
name|pbAlarmStack
argument_list|)
operator|=
name|ALARM_STACK
operator|-
literal|2
expr_stmt|;
name|SELECTOROF
argument_list|(
name|pbAlarmStack
argument_list|)
operator|=
name|selAlarmStack
expr_stmt|;
comment|/* Create the thread */
if|if
condition|(
name|DosCreateThread
argument_list|(
name|alarm_thread
argument_list|,
operator|&
name|tidAlarm
argument_list|,
name|pbAlarmStack
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Alarm thread failed to start.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Setup the signal handler for Process Flag A */
if|if
condition|(
name|DosSetSigHandler
argument_list|(
name|AlarmSignal
argument_list|,
operator|&
name|pfnPrev
argument_list|,
operator|&
name|pfAction
argument_list|,
name|SIGA_ACCEPT
argument_list|,
name|SIG_PFLG_A
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"SigHandler Failed to install.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Save main process ID, we'll need it for triggering the signal */
name|DosGetPID
argument_list|(
operator|&
name|pid
argument_list|)
expr_stmt|;
name|pidMain
operator|=
name|pid
operator|.
name|pid
expr_stmt|;
block|}
else|else
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|unsigned
name|alarm
parameter_list|(
name|unsigned
name|sec
parameter_list|)
block|{
if|if
condition|(
operator|!
name|bAlarmInit
condition|)
name|alarm_init
argument_list|()
expr_stmt|;
if|if
condition|(
name|sec
condition|)
block|{
name|uTime
operator|=
name|sec
expr_stmt|;
name|bAlarmRunning
operator|=
name|TRUE
expr_stmt|;
block|}
else|else
name|bAlarmRunning
operator|=
name|FALSE
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|TESTING
end_ifdef

begin_comment
comment|/* A simple test to see if it works */
end_comment

begin_decl_stmt
name|BOOL
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|timeout
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ALARM TRIGGERED!!\n"
argument_list|)
expr_stmt|;
name|DosBeep
argument_list|(
literal|1000
argument_list|,
literal|500
argument_list|)
expr_stmt|;
name|x
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|main
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|alarm
argument_list|(
literal|1L
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ALARM RUNNING!!\n"
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|x
condition|)
empty_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

