begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* policy.h    Configuration file for policy decisions.  To be edited on site.     Copyright (C) 1991, 1992 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o AIRS, P.O. Box 520, Waltham, MA 02254.     $Log: policy.h,v $    Revision 1.8  1992/04/01  21:58:35  ian    Added CLOSE_LOGFILES configuration parameter     Revision 1.7  1992/03/30  15:29:58  ian    Added HAVE_SVR4_LOCKFILES     Revision 1.6  1992/03/27  05:31:09  ian    David J. MacKenzie: various cleanups     Revision 1.5  1992/03/16  01:23:08  ian    Make blocking writes optional     Revision 1.4  1992/03/12  19:54:43  ian    Debugging based on types rather than number     Revision 1.3  1992/03/11  22:34:25  ian    Chip Salzenberg: support Internet mail addresses in uuxqt replies     Revision 1.2  1992/03/02  04:53:07  ian    Marc Unangst: added HAVE_SCO_LOCKFILES configuration parameter     Revision 1.1  1992/02/23  03:26:51  ian    Initial revision     */
end_comment

begin_comment
comment|/* This header file contains macro definitions which must be set by    each site before compilation.  The first few are system    characteristics that can not be easily discovered by the    configuration script.  Most are configuration decisions that must    be made by the local administrator.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* System characteristics.  */
end_comment

begin_comment
comment|/* This code tries to use several ANSI C features, including    prototypes, stdarg.h, the const qualifier and the types void    (including void * pointers) and unsigned char.  By default it will    use these features if the compiler defines __STDC__.  If your    compiler supports these features but does not define __STDC__, you    should set ANSI_C to 1.  If your compiler does not support these    features but defines __STDC__ (no compiler should do this, in my    opinion), you should set ANSI_C to 0.  In most cases (or if you're    not sure) just leave the line below commented out.  */
end_comment

begin_comment
comment|/* #define ANSI_C 1 */
end_comment

begin_comment
comment|/* Set USE_STDIO to 1 if data files should be read using the stdio    routines (fopen, fread, etc.) rather than the UNIX unbuffered I/O    calls (open, read, etc.).  Unless you know your stdio is really    rotten, you should leave this as 1.  */
end_comment

begin_define
define|#
directive|define
name|USE_STDIO
value|1
end_define

begin_comment
comment|/* Exactly one of the following macros must be set to 1.  Many modern    systems support more than one of these choices through some form of    compilation environment, in which case the setting will depend on    the compilation environment you use.  If you have a reasonable    choice between options, I suspect that TERMIO or TERMIOS will be    more efficient than TTY, but I have not done any head to head    comparisons.     If you don't set any of these macros, the code below will guess.    It will doubtless be wrong on some systems.     HAVE_BSD_TTY -- Use the 4.2BSD tty routines    HAVE_SYSV_TERMIO -- Use the System V termio routines    HAVE_POSIX_TERMIOS -- Use the POSIX termios routines    */
end_comment

begin_define
define|#
directive|define
name|HAVE_BSD_TTY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYSV_TERMIO
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_POSIX_TERMIOS
value|0
end_define

begin_comment
comment|/* This code tries to guess which terminal driver to use if you did    not make a choice above.  It is in this file to make it easy to    figure out what's happening if something goes wrong.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_BSD_TTY
operator|+
name|HAVE_SYSV_TERMIO
operator|+
name|HAVE_POSIX_TERMIOS
operator|==
literal|0
end_if

begin_if
if|#
directive|if
name|HAVE_CBREAK
end_if

begin_undef
undef|#
directive|undef
name|HAVE_BSD_TTY
end_undef

begin_define
define|#
directive|define
name|HAVE_BSD_TTY
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|HAVE_SYSV_TERMIO
end_undef

begin_define
define|#
directive|define
name|HAVE_SYSV_TERMIO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On some systems a write to a serial port will block even if the    file descriptor has been set to not block.  File transfer can be    more efficient if the package knows that a write to the serial port    will not block; however, if the write does block unexpectedly then    data loss is possible at high speeds.     If writes to a serial port always block even when requested not to,    you should set HAVE_UNBLOCKED_WRITES to 0; otherwise you should set    it to 1.  In general on System V HAVE_UNBLOCKED_WRITES should be 0    and on BSD it should be 1.     If HAVE_UNBLOCKED_WRITES is set to 1 when it should be 0 you may    see an unexpectedly large number of transmission errors, or, if you    have hardware handshaking, transfer times may be lower than    expected (but then, they always are).  If HAVE_UNBLOCKED_WRITES is    set to 0 when it should be 1, file transfer will use more CPU time    than necessary.  If you are unsure, setting HAVE_UNBLOCKED_WRITES    to 0 should always be safe.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNBLOCKED_WRITES
value|1
end_define

begin_comment
comment|/* When the code does do a blocking write, it wants to write the    largest amount of data which the kernel will accept as a single    unit.  On BSD this is typically the value of OBUFSIZ in<sys/tty.h>, usually 100.  On System V this is typically the size    of a clist, CLSIZE in<sys/tty.h>, which is usually 64.  Define    SINGLE_WRITE to the correct value for your system.  If SINGLE_WRITE    is too large, data loss may occur.  If SINGLE_WRITE is too small,    file transfer will use more CPU time than necessary.  If you have    no idea, 64 should work on most modern systems.  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_WRITE
value|100
end_define

begin_comment
comment|/* Set TIMES_TICK to the fraction of a second which times(2) returns    (for example, if times returns 100ths of a second TIMES_TICK should    be set to 100).  On a true POSIX system TIMES_TICK may simply be    defined as CLK_TCK.  On some systems the environment variable HZ is    what you want for TIMES_TICK, but on some other systems HZ has the    wrong value; check the man page.  If you leave this set to 0, the    code will try to guess; it will doubtless be wrong on some systems.    If TIMES_TICK is wrong the code may report incorrect file transfer    times in the statistics file, but on many systems times(2) will    actually not be used and this value will not matter at all.  */
end_comment

begin_define
define|#
directive|define
name|TIMES_TICK
value|60
end_define

begin_comment
comment|/* Set PS_PROGRAM to the program to run to get a process status,    including the arguments to pass it.  This is used by ``uustat -p''.    Set HAVE_PS_MULTIPLE to 1 if a comma separated list of process    numbers may be appended (e.g. ``ps -flp1,10,100'').  Otherwise ps    will be invoked several times, with a single process number append    each time.  The default definitions should work on most systems,    although some may complain about the 'p' option.  The second set of    definitions are appropriate for System V.  To use the second set of    definitions, change the ``#if 1'' to ``#if 0''.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|PS_PROGRAM
value|"/bin/ps -lp"
end_define

begin_define
define|#
directive|define
name|HAVE_PS_MULTIPLE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PS_PROGRAM
value|"/bin/ps -flp"
end_define

begin_define
define|#
directive|define
name|HAVE_PS_MULTIPLE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If you use other programs that also lock devices, such as cu or    uugetty, the other programs and UUCP must agree on whether a device    is locked.  This is typically done by creating a lock file in a    specific directory.  The lock file is named LCK.. followed by the    name of the device (UUCP and some versions of cu also lock systems    this way).  If the LOCKDIR macro is defined, these lock files will    be placed in the named directory; otherwise they will be placed in    the default spool directory.  On some BNU systems the lock files    are placed in /etc/locks.  On some they are placed in    /usr/spool/locks.  */
end_comment

begin_comment
comment|/* #define LOCKDIR "/etc/locks" */
end_comment

begin_define
define|#
directive|define
name|LOCKDIR
value|"/var/spool/lock"
end_define

begin_comment
comment|/* You must also specify the format of the lock files by setting    exactly one of the following macros to 1.  Check an existing lock    file to decide which of these choices is more appropriate.     The BNU style is to write the locking process ID in ASCII, passed    to ten characters, followed by a newline.     The V2 style is to write the locking process ID as four binary    bytes in the host byte order.     SCO lock files are similar to BNU lock files, but always lock the    lowercase version of the tty (i.e., LCK..tty2a is created if you    are locking tty2A).  They are appropriate if you are using Taylor    UUCP on an SCO Unix, SCO Xenix, or SCO Open Desktop system.     SVR4 lock files are also similar to BNU lock files, but they use a    different naming convention.  The filenames are LK.xxx.yyy.zzz,    where xxx is the major device number of the device holding the    special device file, yyy is the major device number of the port    device itself, and zzz is the minor device number of the port    device.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_V2_LOCKFILES
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_BNU_LOCKFILES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCO_LOCKFILES
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_SVR4_LOCKFILES
value|0
end_define

begin_comment
comment|/* If your system supports Internet mail addresses, HAVE_INTERNET_MAIL    should be set to 1.  This is checked by uuxqt when sending error    (or success, if requested) notifications to the person who    submitted the job.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTERNET_MAIL
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Adminstrative decisions.  */
end_comment

begin_comment
comment|/* Set USE_RCS_ID to 1 if you want the RCS ID strings compiled into    the executable.  Leaving them out will decrease the executable    size.  Leaving them in will make it easier to determine which    version you are running.  */
end_comment

begin_define
define|#
directive|define
name|USE_RCS_ID
value|1
end_define

begin_comment
comment|/* DEBUG controls how much debugging information is compiled into the    code.  If DEBUG is defined as 0, no sanity checks will be done and    no debugging messages will be compiled in.  If DEBUG is defined as    1 sanity checks will be done but there will still be no debugging    messages.  If DEBUG is 2 than debugging messages will be compiled    in.  When initially testing, DEBUG should be 2, and you should    probably leave it at 2 unless a small reduction in the executable    file size will be very helpful.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
value|2
end_define

begin_comment
comment|/* Set the default grade to use for a uucp command if the -g option is    not used.  The grades, from highest to lowest, are 0 to 9, A to Z,    a to z.  */
end_comment

begin_define
define|#
directive|define
name|BDEFAULT_UUCP_GRADE
value|('N')
end_define

begin_comment
comment|/* Set the default grade to use for a uux command if the -g option is    not used.  */
end_comment

begin_define
define|#
directive|define
name|BDEFAULT_UUX_GRADE
value|('N')
end_define

begin_comment
comment|/* The maximum number of times to retry calling a system which is not    answering.  If this many calls to the system have failed, the    system will not be called again until the status file has been    removed (on a Unix system the status file is in the .Status    subdirectory of the main spool directory, and has the same name as    the system name).  If this is set to 0 the system may be called    regardless of how many previous calls have failed.  */
end_comment

begin_define
define|#
directive|define
name|CMAXRETRIES
value|26
end_define

begin_comment
comment|/* To compile in use of the new style of configuration files described    in the documentation, set HAVE_TAYLOR_CONFIG to 1.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TAYLOR_CONFIG
value|1
end_define

begin_comment
comment|/* To compile in use of V2 style configuration files (L.sys, L-devices    and so on), set HAVE_V2_CONFIG to 1.  To compile in use of BNU    style configuration files (Systems, Devices and so on) set    HAVE_BNU_CONFIG to 1.  The files will be looked up in the    oldconfigdir directory as defined in the Makefile.     You may set any or all of HAVE_TAYLOR_CONFIG, HAVE_V2_CONFIG and    HAVE_BNU_CONFIG to 1 (you must set at least one of the macros).    When looking something up (a system, a port, etc.) the new style    configuration files will be read first, followed by the V2    configuration files, followed by the BNU configuration files.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_V2_CONFIG
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_BNU_CONFIG
value|0
end_define

begin_comment
comment|/* Exactly one of the following macros must be set to 1.  The exact    format of the spool directories is explained in sys3.unx.     SPOOLDIR_V2 -- Use a Version 2 (original UUCP) style spool directory    SPOOLDIR_BSD42 -- Use a BSD 4.2 style spool directory    SPOOLDIR_BSD43 -- Use a BSD 4.3 style spool directory    SPOOLDIR_BNU -- Use a BNU (HDB) style spool directory    SPOOLDIR_ULTRIX -- Use an Ultrix style spool directory    SPOOLDIR_TAYLOR -- Use a new style spool directory     If you are not worried about compatibility with a currently running    UUCP, use SPOOLDIR_TAYLOR.  */
end_comment

begin_define
define|#
directive|define
name|SPOOLDIR_V2
value|0
end_define

begin_define
define|#
directive|define
name|SPOOLDIR_BSD42
value|0
end_define

begin_define
define|#
directive|define
name|SPOOLDIR_BSD43
value|0
end_define

begin_define
define|#
directive|define
name|SPOOLDIR_BNU
value|0
end_define

begin_define
define|#
directive|define
name|SPOOLDIR_ULTRIX
value|0
end_define

begin_define
define|#
directive|define
name|SPOOLDIR_TAYLOR
value|1
end_define

begin_comment
comment|/* You must select which type of logging you want by setting exactly    one of the following to 1.  These control output to the log file    and to the statistics file.     If you define HAVE_TAYLOR_LOGGING, each line in the log file will    look something like this:     uucico uunet uucp (1991-12-10 09:04:34.45 16390) Receiving uunet/D./D.uunetSwJ72     and each line in the statistics file will look something like this:     uucp uunet (1991-12-10 09:04:40.20) received 2371 bytes in 5 seconds (474 bytes/sec)     If you define HAVE_V2_LOGGING, each line in the log file will look    something like this:     uucico uunet uucp (12/10-09:04 16390) Receiving uunet/D./D.uunetSwJ72     and each line in the statistics file will look something like this:     uucp uunet (12/10-09:04 16390) (692373862) received data 2371 bytes 5 seconds     If you define HAVE_BNU_LOGGING, each program will by default use a    separate log file.  For uucico talking to uunet, for example, it    will be /usr/spool/uucp/.Log/uucico/uunet.  Each line will look    something like this:     uucp uunet (12/10-09:04:22,16390,1) Receiving uunet/D./D.uunetSwJ72     and each line in the statistics file will look something like this:     uunet!uucp M (12/10-09:04:22) (C,16390,1) [ttyXX]<- 2371 / 5.000 secs, 474 bytes/sec     The main reason to prefer one format over another is that you may    have shell scripts which expect the files to have a particular    format.  If you have none, choose whichever format you find more    appealing.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TAYLOR_LOGGING
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_V2_LOGGING
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_BNU_LOGGING
value|0
end_define

begin_comment
comment|/* If you would like the log, debugging and statistics files to be    closed after each message, set CLOSE_LOGFILES to 1.  This will    permit the log files to be easily moved.  If a log file does not    exist when a new message is written out, it will be created.    Setting CLOSE_LOGFILES to 1 will obviously require slightly more    processing time.  */
end_comment

begin_define
define|#
directive|define
name|CLOSE_LOGFILES
value|0
end_define

begin_comment
comment|/* The name of the default spool directory.  If HAVE_TAYLOR_CONFIG is    set to 1, this may be overridden by the ``spool'' command in the    configuration file.  */
end_comment

begin_define
define|#
directive|define
name|SPOOLDIR
value|"/var/spool/uucp"
end_define

begin_comment
comment|/* The name of the default public directory.  If HAVE_TAYLOR_CONFIG is    set to 1, this may be overridden by the ``pubdir'' command in the    configuration file.  Also, a particular system may be given a    specific public directory by using the ``pubdir'' command in the    system file.  */
end_comment

begin_define
define|#
directive|define
name|PUBDIR
value|"/var/spool/uucppublic"
end_define

begin_comment
comment|/* The default command path.  This is a space separated list of    directories.  Remote command executions requested by uux are looked    up using this path.  If you are using HAVE_TAYLOR_CONFIG, the    command path may be overridden for a particular system.  For most    systems, you should just make sure that the programs rmail and    rnews can be found using this path.  */
end_comment

begin_define
define|#
directive|define
name|CMDPATH
value|"/bin /usr/bin /usr/local/bin"
end_define

begin_comment
comment|/* The default amount of free space to require for systems that do not    specify an amount with the ``free-space'' command.  This is only    used when talking to another instance of Taylor UUCP; if accepting    a file would not leave at least this many bytes free on the disk,    it will be refused.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FREE_SPACE
value|(50000)
end_define

begin_comment
comment|/* It is possible for an execute job to request to be executed using    sh(1), rather than execve(2).  This is such a security risk, it is    being disabled by default; to allow such jobs, set the following    macro to 1.  */
end_comment

begin_define
define|#
directive|define
name|ALLOW_SH_EXECUTION
value|0
end_define

begin_comment
comment|/* If a command executed on behalf of a remote system takes a filename    as an argument, a security breach may be possible (note that on my    system neither of the default commands, rmail and rnews, take    filename arguments).  If you set ALLOW_FILENAME_ARGUMENTS to 0, all    arguments to a command will be checked; if any argument    1) starts with ../    2) contains the string /../    3) begins with a / but does not name a file that may be sent or       received (according to the specified ``remote-send'' and       ``remote-receive'')    the command will be rejected.  By default, any argument is    permitted. */
end_comment

begin_define
define|#
directive|define
name|ALLOW_FILENAME_ARGUMENTS
value|1
end_define

begin_if
if|#
directive|if
name|HAVE_TAYLOR_LOGGING
end_if

begin_comment
comment|/* The default log file when using HAVE_TAYLOR_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``logfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|LOGFILE
value|"/var/spool/uucp/Log"
end_define

begin_comment
comment|/* The default statistics file when using HAVE_TAYLOR_LOGGING.  When    using HAVE_TAYLOR_CONFIG, this may be overridden by the    ``statfile'' command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|STATFILE
value|"/var/spool/uucp/Stats"
end_define

begin_comment
comment|/* The default debugging file when using HAVE_TAYLOR_LOGGING.  When    using HAVE_TAYLOR_CONFIG, this may be overridden by the    ``debugfile'' command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGFILE
value|"/var/spool/uucp/Debug"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TAYLOR_LOGGING */
end_comment

begin_if
if|#
directive|if
name|HAVE_V2_LOGGING
end_if

begin_comment
comment|/* The default log file when using HAVE_V2_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``logfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|LOGFILE
value|"/var/spool/uucp/LOGFILE"
end_define

begin_comment
comment|/* The default statistics file when using HAVE_V2_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``statfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|STATFILE
value|"/var/spool/uucp/SYSLOG"
end_define

begin_comment
comment|/* The default debugging file when using HAVE_V2_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``debugfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGFILE
value|"/var/spool/uucp/DEBUG"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_V2_LOGGING */
end_comment

begin_if
if|#
directive|if
name|HAVE_BNU_LOGGING
end_if

begin_comment
comment|/* The default log file when using HAVE_BNU_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``logfile''    command in the configuration file.  The first %s in the string will    be replaced by the program name (e.g. uucico); the second %s will    be replaced by the system name (if there is no appropriate system,    "ANY" will be used).  No other '%' character may appear in the    string.  */
end_comment

begin_define
define|#
directive|define
name|LOGFILE
value|"/var/spool/uucp/.Log/%s/%s"
end_define

begin_comment
comment|/* The default statistics file when using HAVE_BNU_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``statfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|STATFILE
value|"/var/spool/uucp/.Admin/xferstats"
end_define

begin_comment
comment|/* The default debugging file when using HAVE_BNU_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``debugfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGFILE
value|"/var/spool/uucp/.Admin/audit.local"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BNU_LOGGING */
end_comment

end_unit

