begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* policy.h    Configuration file for policy decisions.  To be edited on site.     Copyright (C) 1991, 1992, 1993, 1994, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
value|0
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
value|1
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
name|HAVE_TERMIOS_H
end_if

begin_undef
undef|#
directive|undef
name|HAVE_POSIX_TERMIOS
end_undef

begin_define
define|#
directive|define
name|HAVE_POSIX_TERMIOS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_TERMIOS_H */
end_comment

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

begin_comment
comment|/* ! HAVE_CBREAK */
end_comment

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

begin_comment
comment|/* ! HAVE_CBREAK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_TERMIOS_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BSD_TTY + HAVE_SYSV_TERMIO + HAVE_POSIX_TERMIOS == 0 */
end_comment

begin_comment
comment|/* On some systems a write to a serial port will block even if the    file descriptor has been set to not block.  File transfer can be    more efficient if the package knows that a write to the serial port    will not block; however, if the write does block unexpectedly then    data loss is possible at high speeds.     If writes to a serial port always block even when requested not to,    you should set HAVE_UNBLOCKED_WRITES to 0; otherwise you should set    it to 1.  In general on System V releases without STREAMS-based    ttys (e.g., before SVR4) HAVE_UNBLOCKED_WRITES should be 0 and on    BSD or SVR4 it should be 1.     If HAVE_UNBLOCKED_WRITES is set to 1 when it should be 0 you may    see an unexpectedly large number of transmission errors, or, if you    have hardware handshaking, transfer times may be lower than    expected (but then, they always are).  If HAVE_UNBLOCKED_WRITES is    set to 0 when it should be 1, file transfer will use more CPU time    than necessary.  If you are unsure, setting HAVE_UNBLOCKED_WRITES    to 0 should always be safe.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNBLOCKED_WRITES
value|1
end_define

begin_comment
comment|/* When the code does do a blocking write, it wants to write the    largest amount of data which the kernel will accept as a single    unit.  On BSD this is typically the value of OBUFSIZ in<sys/tty.h>, usually 100.  On System V before SVR4 this is    typically the size of a clist, CLSIZE in<sys/tty.h>, which is    usually 64.  On SVR4, which uses STREAMS-based ttys, 2048 is    reasonable.  Define SINGLE_WRITE to the correct value for your    system.  If SINGLE_WRITE is too large, data loss may occur.  If    SINGLE_WRITE is too small, file transfer will use more CPU time    than necessary.  If you have no idea, 64 should work on most modern    systems.  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_WRITE
value|100
end_define

begin_comment
comment|/* Some tty drivers, such as those from SCO and AT&T's Unix PC, have a    bug in the implementation of ioctl() that causes CLOCAL to be    ineffective until the port is opened a second time.  If    HAVE_CLOCAL_BUG is set to 1, code will be added to do this second    open on the port.  Set this if you are getting messages that say    "Line disconnected" while in the dial chat script after only    writing the first few characters to the port.  This bug causes the    resetting of CLOCAL to have no effect, so the "\m" (require    carrier) escape sequence won't function properly in dialer chat    scripts.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCAL_BUG
value|0
end_define

begin_comment
comment|/* On some systems, such as SCO Xenix, resetting DTR on a port    apparently prevents getty from working on the port, and thus    prevents anybody from dialing in.  If HAVE_RESET_BUG is set to 1,    DTR will not be reset when a serial port is closed.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESET_BUG
value|0
end_define

begin_comment
comment|/* The Sony NEWS reportedly handles no parity by clearing both the odd    and even parity bits in the sgtty structure, unlike most BSD based    systems in which no parity is indicated by setting both the odd and    even parity bits.  Setting HAVE_PARITY_BUG to 1 will handle this    correctly.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PARITY_BUG
value|0
end_define

begin_if
if|#
directive|if
name|HAVE_BSD_TTY
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|sony
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_PARITY_BUG
end_undef

begin_define
define|#
directive|define
name|HAVE_PARITY_BUG
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
comment|/* On Ultrix 4.0, at least, setting CBREAK causes input characters to    be stripped, regardless of the setting of LPASS8 and LLITOUT.  This    can be worked around by using the termio call to reset ISTRIP.    This probably does not apply to any other operating system.    Setting HAVE_STRIP_BUG to 1 will use this workaround.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRIP_BUG
value|0
end_define

begin_if
if|#
directive|if
name|HAVE_BSD_TTY
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__ultrix__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ultrix
end_ifndef

begin_define
define|#
directive|define
name|ultrix
end_define

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
name|ultrix
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_STRIP_BUG
end_undef

begin_define
define|#
directive|define
name|HAVE_STRIP_BUG
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
comment|/* If your system implements full duplex pipes, set    HAVE_FULLDUPLEX_PIPES to 1.  Everything should work fine if you    leave it set to 0, but setting it to 1 can be slightly more    efficient.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FULLDUPLEX_PIPES
value|0
end_define

begin_comment
comment|/* TIMES_TICK is the fraction of a second which times(2) returns (for    example, if times returns 100ths of a second TIMES_TICK should be    set to 100).  On a true POSIX system (one which has the sysconf    function and also has _SC_CLK_TCK defined in<unistd.h>) TIMES_TICK    may simply be left as 0.  On some systems the environment variable    HZ is what you want for TIMES_TICK, but on some other systems HZ    has the wrong value; check the man page.  If you leave this set to    0, the code will try to guess; it will doubtless be wrong on some    non-POSIX systems.  If TIMES_TICK is wrong the code may report    incorrect file transfer times in the statistics file, but on many    systems times(2) will actually not be used and this value will not    matter at all.  */
end_comment

begin_define
define|#
directive|define
name|TIMES_TICK
value|0
end_define

begin_comment
comment|/* If your system does not support saved set user ID, set    HAVE_SAVED_SETUID to 0.  However, this is ignored if your system    has the setreuid function.  Most modern Unixes have one or the    other.  If your system has the setreuid function, don't worry about    this define, or about the following discussion.     If you set HAVE_SAVED_SETUID to 0, you will not be able to use uucp    to transfer files that the uucp user can not read.  Basically, you    will only be able to use uucp on world-readable files.  If you set    HAVE_SAVED_SETUID to 1, but your system does not have saved set    user ID, uucp will fail with an error message whenever anybody    other than the uucp user uses it.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SAVED_SETUID
value|0
end_define

begin_comment
comment|/* On some systems, such as 4.4BSD-Lite, NetBSD, the DG Aviion and,    possibly, the RS/6000, the setreuid function is broken.  It should    be possible to use setreuid to swap the real and effective user    ID's, but on some systems it will not change the real user ID (I    believe this is due to a misreading of the POSIX standard).  On    such a system you must set HAVE_BROKEN_SETREUID to 1; if you do    not, you will get error messages from setreuid.  Systems on which    setreuid exists but is broken pretty much always have saved setuid.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BROKEN_SETREUID
value|0
end_define

begin_comment
comment|/* On a few systems, such as NextStep 3.3, the POSIX macro F_SETLKW is    defined, but does not work.  On such systems, you must set    HAVE_BROKEN_SETLKW to 1.  If you do not, uux will hang, or log    peculiar error messages, every time it is run.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BROKEN_SETLKW
value|0
end_define

begin_comment
comment|/* On the 3B2, and possibly other systems, nap takes an argument in    hundredths of a second rather than milliseconds.  I don't know of    any way to test for this.  Set HAVE_HUNDREDTHS_NAP to 1 if this is    true on your system.  This does not matter if your system does not    have the nap function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_HUNDREDTHS_NAP
value|0
end_define

begin_comment
comment|/* Set MAIL_PROGRAM to a program which can be used to send mail.  It    will be used for mail to both local and remote users.  Set    MAIL_PROGRAM_TO_BODY to 1 if the recipient should be specified as a    To: line in the body of the message; otherwise, the recipient will    be provided as an argument to MAIL_PROGRAM.  Set    MAIL_PROGRAM_SUBJECT_BODY if the subject should be specified as a    Subject: line in the body of the message; otherwise, the subject    will be provided using the -s option to MAIL_PROGRAM (if your mail    program does not support the -s option, you must set    MAIL_PROGRAM_SUBJECT_BODY to 1).  If your system uses sendmail, use    the sendmail choice below.  Otherwise, select one of the other    choices as appropriate.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|MAIL_PROGRAM
value|"/usr/sbin/sendmail -t"
end_define

begin_define
define|#
directive|define
name|MAIL_PROGRAM_TO_BODY
value|1
end_define

begin_define
define|#
directive|define
name|MAIL_PROGRAM_SUBJECT_BODY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MAIL_PROGRAM
value|"/usr/ucb/mail"
end_define

begin_define
define|#
directive|define
name|MAIL_PROGRAM_TO_BODY
value|0
end_define

begin_define
define|#
directive|define
name|MAIL_PROGRAM_SUBJECT_BODY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MAIL_PROGRAM
value|"/bin/mail"
end_define

begin_define
define|#
directive|define
name|MAIL_PROGRAM_TO_BODY
value|0
end_define

begin_define
define|#
directive|define
name|MAIL_PROGRAM_SUBJECT_BODY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set PS_PROGRAM to the program to run to get a process status,    including the arguments to pass it.  This is used by ``uustat -p''.    Set HAVE_PS_MULTIPLE to 1 if a comma separated list of process    numbers may be appended (e.g. ``ps -flp1,10,100'').  Otherwise ps    will be invoked several times, with a single process number append    each time.  The default definitions should work on most systems,    although some (such as the NeXT) will complain about the 'p'    option; for those, use the second set of definitions.  The third    set of definitions are appropriate for System V.  To use the second    or third set of definitions, change the ``#if 1'' to ``#if 0'' and    change the appropriate ``#if 0'' to ``#if 1''.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|PS_PROGRAM
value|"/bin/ps -l"
end_define

begin_define
define|#
directive|define
name|HAVE_PS_MULTIPLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

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

begin_ifdef
ifdef|#
directive|ifdef
name|__QNX__
end_ifdef

begin_comment
comment|/* Use this for QNX, along with HAVE_QNX_LOCKFILES.  */
end_comment

begin_undef
undef|#
directive|undef
name|PS_PROGRAM
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_PS_MULTIPLE
end_undef

begin_define
define|#
directive|define
name|PS_PROGRAM
value|"/bin/ps -l -n -p"
end_define

begin_define
define|#
directive|define
name|HAVE_PS_MULTIPLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If you use other programs that also lock devices, such as cu or    uugetty, the other programs and UUCP must agree on whether a device    is locked.  This is typically done by creating a lock file in a    specific directory; the lock files are generally named    LCK..something or LK.something.  If the LOCKDIR macro is defined,    these lock files will be placed in the named directory; otherwise    they will be placed in the default spool directory.  On some HDB    systems the lock files are placed in /etc/locks.  On some they are    placed in /usr/spool/locks.  On the NeXT they are placed in    /usr/spool/uucp/LCK.  */
end_comment

begin_comment
comment|/* #define LOCKDIR "/usr/spool/uucp" */
end_comment

begin_comment
comment|/* #define LOCKDIR "/etc/locks" */
end_comment

begin_comment
comment|/* #define LOCKDIR "/usr/spool/locks" */
end_comment

begin_comment
comment|/* #define LOCKDIR "/usr/spool/uucp/LCK" */
end_comment

begin_define
define|#
directive|define
name|LOCKDIR
value|"/var/spool/lock"
end_define

begin_comment
comment|/* You must also specify the format of the lock files by setting    exactly one of the following macros to 1.  Check an existing lock    file to decide which of these choices is more appropriate.     The HDB style is to write the locking process ID in ASCII, passed    to ten characters, followed by a newline.     The V2 style is to write the locking process ID as four binary    bytes in the host byte order.  Many BSD derived systems use this    type of lock file, including the NeXT.     SCO lock files are similar to HDB lock files, but always lock the    lowercase version of the tty (i.e., LCK..tty2a is created if you    are locking tty2A).  They are appropriate if you are using Taylor    UUCP on an SCO Unix, SCO Xenix, or SCO Open Desktop system.     SVR4 lock files are also similar to HDB lock files, but they use a    different naming convention.  The filenames are LK.xxx.yyy.zzz,    where xxx is the major device number of the device holding the    special device file, yyy is the major device number of the port    device itself, and zzz is the minor device number of the port    device.     Sequent DYNIX/ptx (but perhaps not Dynix 3.x) uses yet another    naming convention.  The lock file for /dev/ttyXA/XAAP is named    LCK..ttyXAAP.     Coherent use a completely different method of terminal locking.    See unix/cohtty for details.  For locks other than for terminals,    HDB type lock files are used.     QNX lock files are similar to HDB lock files except that the node    ID must be stored in addition to the process ID and for serial    devices the node ID must be included in the lock file name.  QNX    boxes are generally used in bunches, and all of them behave like    one big machine to some extent.  Thus, processes on different    machines will be sharing the files in the spool directory.  To    detect if a process has died and a lock is thus stale, you need the    node ID of the process as well as the process ID.  The process ID    is stored as a number written using ASCII digits padded to 10    characters, followed by a space, followed by the node ID written    using ASCII digits padded to 10 characters, followed by a newline.    The format for QNX lock files was made up just for Taylor UUCP.    QNX doesn't come with a version of UUCP.  */
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
name|HAVE_HDB_LOCKFILES
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

begin_define
define|#
directive|define
name|HAVE_SEQUENT_LOCKFILES
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_COHERENT_LOCKFILES
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_QNX_LOCKFILES
value|0
end_define

begin_comment
comment|/* This tries to pick a default based on preprocessor definitions.    Ignore it if you have explicitly set one of the above values.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_V2_LOCKFILES
operator|+
name|HAVE_HDB_LOCKFILES
operator|+
name|HAVE_SCO_LOCKFILES
operator|+
name|HAVE_SVR4_LOCKFILES
operator|+
name|HAVE_SEQUENT_LOCKFILES
operator|+
name|HAVE_COHERENT_LOCKFILES
operator|+
name|HAVE_QNX_LOCKFILES
operator|==
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__QNX__
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_QNX_LOCKFILES
end_undef

begin_define
define|#
directive|define
name|HAVE_QNX_LOCKFILES
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__QNX__) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__COHERENT__
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_COHERENT_LOCKFILES
end_undef

begin_define
define|#
directive|define
name|HAVE_COHERENT_LOCKFILES
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__COHERENT__) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_SEQUENT_LOCKFILES
end_undef

begin_define
define|#
directive|define
name|HAVE_SEQUENT_LOCKFILES
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (_SEQUENT) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sco
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_SCO_LOCKFILES
end_undef

begin_define
define|#
directive|define
name|HAVE_SCO_LOCKFILES
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (sco) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__svr4__
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_SVR4_LOCKFILES
end_undef

begin_define
define|#
directive|define
name|HAVE_SVR4_LOCKFILES
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__svr4__) */
end_comment

begin_comment
comment|/* Final default is HDB.  There's no way to tell V2 from HDB.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_HDB_LOCKFILES
end_undef

begin_define
define|#
directive|define
name|HAVE_HDB_LOCKFILES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__svr4__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (sco) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (_SEQUENT) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__COHERENT__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__QNX__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no LOCKFILES define */
end_comment

begin_comment
comment|/* If your system supports Internet mail addresses (which look like    user@host.domain rather than system!user), HAVE_INTERNET_MAIL    should be set to 1.  This is checked by uuxqt and uustat when    sending notifications to the person who submitted the job.     If your system does not understand addresses of the form user@host,    you must set HAVE_INTERNET_MAIL to 0.     If your system does not understand addresses of the form host!user,    which is unlikely, you must set HAVE_INTERNET_MAIL to 1.     If your system sends mail addressed to "A!B@C" to host C (i.e., it    parses the address as "(A!B)@C"), you must set HAVE_INTERNET_MAIL    to 1.     If your system sends mail addressed to "A!B@C" to host A (i.e., it    parses the address as "A!(B@C)"), you must set HAVE_INTERNET_MAIL    to 0.     Note that in general it is best to avoid addresses of the form    "A!B@C" because of this ambiguity of precedence.  UUCP will not    intentionally generate addresses of this form, but it can occur in    certain rather complex cases.  */
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
comment|/* Set HAVE_ENCRYPTED_PASSWORDS to 1 if you want login passwords to be    encrypted before comparing them against the values in the file.    This only applies when uucico is run with the -l or -e switches and    is doing its own login prompting.  Note that the passwords used are    from the UUCP password file, not the system /etc/passwd file.  See    the documentation for further details.  If you set this, you are    responsible for encrypting the passwords in the UUCP password file.    The function crypt will be used to do comparisons.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENCRYPTED_PASSWORDS
value|0
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
comment|/* To compile in use of the new style of configuration files described    in the documentation, set HAVE_TAYLOR_CONFIG to 1.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TAYLOR_CONFIG
value|1
end_define

begin_comment
comment|/* To compile in use of V2 style configuration files (L.sys, L-devices    and so on), set HAVE_V2_CONFIG to 1.  To compile in use of HDB    style configuration files (Systems, Devices and so on) set    HAVE_HDB_CONFIG to 1.  The files will be looked up in the    oldconfigdir directory as defined in the Makefile.     You may set any or all of HAVE_TAYLOR_CONFIG, HAVE_V2_CONFIG and    HAVE_HDB_CONFIG to 1 (you must set at least one of the macros).    When looking something up (a system, a port, etc.) the new style    configuration files will be read first, followed by the V2    configuration files, followed by the HDB configuration files.  */
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
name|HAVE_HDB_CONFIG
value|1
end_define

begin_comment
comment|/* Exactly one of the following macros must be set to 1.  The exact    format of the spool directories is explained in unix/spool.c.     SPOOLDIR_V2 -- Use a Version 2 (original UUCP) style spool directory    SPOOLDIR_BSD42 -- Use a BSD 4.2 style spool directory    SPOOLDIR_BSD43 -- Use a BSD 4.3 style spool directory    SPOOLDIR_HDB -- Use a HDB (BNU) style spool directory    SPOOLDIR_ULTRIX -- Use an Ultrix style spool directory    SPOOLDIR_SVR4 -- Use a System V Release 4 spool directory    SPOOLDIR_TAYLOR -- Use a new style spool directory     If you are not worried about compatibility with a currently running    UUCP, use SPOOLDIR_TAYLOR.  */
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
name|SPOOLDIR_HDB
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
name|SPOOLDIR_SVR4
value|0
end_define

begin_define
define|#
directive|define
name|SPOOLDIR_TAYLOR
value|1
end_define

begin_comment
comment|/* The status file generated by UUCP can use either the traditional    HDB upper case comments or new easier to read lower case comments.    This affects the display of uustat -m or uustat -q.  Some    third-party programs read these status files and expect them to be    in a certain format.  The default is to use the traditional    comments when using an HDB or SVR4 spool directory, and to use    lower case comments otherwise.  */
end_comment

begin_define
define|#
directive|define
name|USE_TRADITIONAL_STATUS
value|(SPOOLDIR_HDB || SPOOLDIR_SVR4)
end_define

begin_comment
comment|/* You must select which type of logging you want by setting exactly    one of the following to 1.  These control output to the log file    and to the statistics file.     If you define HAVE_TAYLOR_LOGGING, each line in the log file will    look something like this:     uucico uunet uucp (1991-12-10 09:04:34.45 16390) Receiving uunet/D./D.uunetSwJ72     and each line in the statistics file will look something like this:     uucp uunet (1991-12-10 09:04:40.20) received 2371 bytes in 5 seconds (474 bytes/sec)     If you define HAVE_V2_LOGGING, each line in the log file will look    something like this:     uucico uunet uucp (12/10-09:04 16390) Receiving uunet/D./D.uunetSwJ72     and each line in the statistics file will look something like this:     uucp uunet (12/10-09:04 16390) (692373862) received data 2371 bytes 5 seconds     If you define HAVE_HDB_LOGGING, each program will by default use a    separate log file.  For uucico talking to uunet, for example, it    will be /usr/spool/uucp/.Log/uucico/uunet.  Each line will look    something like this:     uucp uunet (12/10-09:04:22,16390,1) Receiving uunet/D./D.uunetSwJ72     and each line in the statistics file will look something like this:     uunet!uucp M (12/10-09:04:22) (C,16390,1) [ttyXX]<- 2371 / 5.000 secs, 474 bytes/sec     The main reason to prefer one format over another is that you may    have shell scripts which expect the files to have a particular    format.  If you have none, choose whichever format you find more    appealing.  */
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
name|HAVE_HDB_LOGGING
value|0
end_define

begin_comment
comment|/* If QNX_LOG_NODE_ID is set to 1, log messages will include the QNX    node ID just after the process ID.  This is a policy decision    because it changes the log file entry format, which can break other    programs (e.g., some of the ones in the contrib directory) which    expect to read the standard log file format.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__QNX__
end_ifdef

begin_define
define|#
directive|define
name|QNX_LOG_NODE_ID
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QNX_LOG_NODE_ID
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If LOG_DEVICE_PREFIX is 1, log messages will give the full    pathname of a device rather than just the final component.  This is    important because on QNX //2/dev/ser2 refers to a different device    than //4/dev/ser2.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__QNX__
end_ifdef

begin_define
define|#
directive|define
name|LOG_DEVICE_PREFIX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOG_DEVICE_PREFIX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* #define SPOOLDIR "/usr/spool/uucp" */
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

begin_comment
comment|/* #define PUBDIR "/usr/spool/uucppublic" */
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
comment|/* While a file is being received, Taylor UUCP will periodically check    to see if there is enough free space remaining on the disk.  If    there is not enough space available on the disk (as determined by    DEFAULT_FREE_SPACE, above, or the ``free-space'' command for the    system) the communication will be aborted.  The disk will be    checked each time FREE_SPACE_DELTA bytes are received.  Lower    values of FREE_SPACE_DELTA are less likely to fill up the disk, but    will also waste more time checking the amount of free space.  To    avoid checking the disk while the file is being received, set    FREE_SPACE_DELTA to 0.  */
end_comment

begin_define
define|#
directive|define
name|FREE_SPACE_DELTA
value|(10240)
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

begin_comment
comment|/* If you set FSYNC_ON_CLOSE to 1, all output files will be forced out    to disk using the fsync system call when they are closed.  This can    be useful if you can not afford to lose people's mail if the system    crashes.  However, not all systems have the fsync call, and it is    always less efficient to use it.  Note that some versions of SCO    Unix, and possibly other systems, make fsync a synonym for sync,    which is extremely inefficient.  */
end_comment

begin_define
define|#
directive|define
name|FSYNC_ON_CLOSE
value|0
end_define

begin_if
if|#
directive|if
name|HAVE_TAYLOR_LOGGING
end_if

begin_comment
comment|/* The default log file when using HAVE_TAYLOR_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``logfile''    command in the configuration file.  */
end_comment

begin_comment
comment|/* #define LOGFILE "/usr/spool/uucp/Log" */
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

begin_comment
comment|/* #define STATFILE "/usr/spool/uucp/Stats" */
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

begin_comment
comment|/* #define DEBUGFILE "/usr/spool/uucp/Debug" */
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
value|"/usr/spool/uucp/LOGFILE"
end_define

begin_comment
comment|/* The default statistics file when using HAVE_V2_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``statfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|STATFILE
value|"/usr/spool/uucp/SYSLOG"
end_define

begin_comment
comment|/* The default debugging file when using HAVE_V2_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``debugfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGFILE
value|"/usr/spool/uucp/DEBUG"
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
name|HAVE_HDB_LOGGING
end_if

begin_comment
comment|/* The default log file when using HAVE_HDB_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``logfile''    command in the configuration file.  The first %s in the string will    be replaced by the program name (e.g. uucico); the second %s will    be replaced by the system name (if there is no appropriate system,    "ANY" will be used).  No other '%' character may appear in the    string.  */
end_comment

begin_define
define|#
directive|define
name|LOGFILE
value|"/usr/spool/uucp/.Log/%s/%s"
end_define

begin_comment
comment|/* The default statistics file when using HAVE_HDB_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``statfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|STATFILE
value|"/usr/spool/uucp/.Admin/xferstats"
end_define

begin_comment
comment|/* The default debugging file when using HAVE_HDB_LOGGING.  When using    HAVE_TAYLOR_CONFIG, this may be overridden by the ``debugfile''    command in the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGFILE
value|"/usr/spool/uucp/.Admin/audit.local"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_HDB_LOGGING */
end_comment

end_unit

