begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|ckxv
init|=
literal|"UNIX Communications support, 5A(0102), 23 Nov 92"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K U T I O  */
end_comment

begin_comment
comment|/* C-Kermit interrupt, terminal control& i/o functions for UNIX */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Includes */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* This moved to here. */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* System error numbers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__386BSD__
end_ifdef

begin_define
define|#
directive|define
name|ENOTCONN
value|57
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __386BSD__ */
end_comment

begin_include
include|#
directive|include
file|"ckcnet.h"
end_include

begin_comment
comment|/* Symbols for network types. */
end_comment

begin_comment
comment|/*   The directory-related includes are here because we need to test some   file-system-related symbols to find out which system we're being compiled   under.  For example, MAXNAMLEN is defined in BSD4.2 but not 4.1. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SDIRENT
end_ifdef

begin_comment
comment|/* Directory bits... */
end_comment

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SDIRENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XNDIR
end_ifdef

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !XNDIR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDIR
end_ifdef

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NDIR, !XNDIR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RTU
end_ifdef

begin_include
include|#
directive|include
file|"/usr/lib/ndir.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !RTU, !NDIR, !XNDIR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIRENT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SDIRENT
end_ifdef

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SDIRENT */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !RTU, !NDIR, !XNDIR, !DIRENT, i.e. all others */
end_comment

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIRENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XNDIR */
end_comment

begin_comment
comment|/* Definition of HZ, used in msleep() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS
end_ifdef

begin_define
define|#
directive|define
name|HZ
value|( 1000 / CLOCK_TICK )
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NAP
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|TRS16
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HZ
value|( 1000 / CLOCK_TICK )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRS16 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NAPHACK
end_ifdef

begin_define
define|#
directive|define
name|nap
parameter_list|(
name|x
parameter_list|)
value|(void)syscall(3112, (x))
end_define

begin_define
define|#
directive|define
name|NAP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAPHACK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_UNIX
end_ifdef

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

begin_comment
comment|/* Prevent multiple definition warnings */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_UNIX */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* Signals */
end_comment

begin_comment
comment|/* For setjmp and longjmp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZILOG
end_ifndef

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<setret.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZILOG */
end_comment

begin_comment
comment|/* Maximum length for the name of a tty device */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEVNAMLEN
end_ifndef

begin_define
define|#
directive|define
name|DEVNAMLEN
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NETCONN
end_ifdef

begin_undef
undef|#
directive|undef
name|DEVNAMLEN
end_undef

begin_define
define|#
directive|define
name|DEVNAMLEN
value|50
end_define

begin_comment
comment|/* longer field for host:service */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETCONN */
end_comment

begin_comment
comment|/*   The following test differentiates between 4.1 BSD and 4.2& later.   If you have a 4.1BSD system with the DIRENT library, this test could   mistakenly diagnose 4.2BSD and then later enable the use of system calls   that aren't defined.  If indeed there are such systems, we can use some   other way of testing for 4.1BSD, or add yet another compile-time switch. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXNAMLEN
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|FT21
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|FT18
end_ifndef

begin_comment
comment|/* Except for Fortune. */
end_comment

begin_define
define|#
directive|define
name|BSD42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT18 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT21 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXNAMLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_comment
comment|/*  Minix support added by Charles Hedrick,  Rutgers University:  hedrick@aramis.rutgers.edu  Minix also has V7 enabled. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_define
define|#
directive|define
name|TANDEM
value|0
end_define

begin_define
define|#
directive|define
name|MYREAD
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_include
include|#
directive|include
file|"ckuver.h"
end_include

begin_comment
comment|/* Version herald */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
name|HERALD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UUCP lock file name definition */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOUUCP
end_ifndef

begin_comment
comment|/* Name of UUCP tty device lock file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACUCNTRL
end_ifdef

begin_define
define|#
directive|define
name|LCKDIR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACUCNTRL */
end_comment

begin_comment
comment|/*   LOCK_DIR is the name of the lockfile directory.   If LOCK_DIR is already defined (e.g. on command line), we don't change it.   PIDSTRING means use ASCII string to represent pid in lockfile. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_DIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/var/spool/uucp";
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX430
end_ifdef

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/var/spool/locks";
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|RTAIX
end_ifdef

begin_comment
comment|/* IBM RT PC AIX 2.2.1 */
end_comment

begin_define
define|#
directive|define
name|PIDSTRING
end_define

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/etc/locks";
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|AIXRS
end_ifdef

begin_define
define|#
directive|define
name|PIDSTRING
end_define

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/etc/locks";
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ISIII
end_ifdef

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/etc/locks";
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HDBUUCP
end_ifdef

begin_define
define|#
directive|define
name|PIDSTRING
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|M_SYS5
end_ifdef

begin_comment
comment|/* wht@n4hgf - SCO */
end_comment

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/usr/spool/uucp";
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|M_UNIX
end_ifdef

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/usr/spool/uucp";
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/var/spool/locks";
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCKF
end_ifndef

begin_define
define|#
directive|define
name|LOCKF
end_define

begin_comment
comment|/* Use lockf() too in SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCKF */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4
end_ifdef

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/var/spool/locks";
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/usr/spool/locks";
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_SYS5 */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|LCKDIR
end_ifdef

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/usr/spool/uucp/LCK";
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCK_DIR
value|"/usr/spool/uucp";
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LCKDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HDBUUCP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISIII */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXRS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTAIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX430 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCK_DIR (outside ifndef) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NOUUCP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_define
define|#
directive|define
name|MYREAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT7300
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MYREAD
end_ifndef

begin_define
define|#
directive|define
name|MYREAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYREAD */
end_comment

begin_comment
comment|/* bits for attmodem: internal modem in use, restart getty */
end_comment

begin_define
define|#
directive|define
name|ISMODEM
value|1
end_define

begin_define
define|#
directive|define
name|DOGETY
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATT7300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_define
define|#
directive|define
name|MYREAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD42 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_define
define|#
directive|define
name|MYREAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  Variables available to outside world:     dftty  -- Pointer to default tty name string, like "/dev/tty".    dfloc  -- 0 if dftty is console, 1 if external line.    dfprty -- Default parity    dfflow -- Default flow control    ckxech -- Flag for who echoes console typein:      1 - The program (system echo is turned off)      0 - The system (or front end, or terminal).    functions that want to do their own echoing should check this flag    before doing so.     flfnam  -- Name of lock file, including its path, e.g.,                 "/usr/spool/uucp/LCK..cul0" or "/etc/locks/tty77"    lkflfn  -- Name of link to lock file, including its paths    haslock -- Flag set if this kermit established a uucp lock.    backgrd -- Flag indicating program executing in background (& on                 end of shell command). Used to ignore INT and QUIT signals.    rtu_bug -- Set by stptrap().  RTU treats ^Z as EOF (but only when we handle                 SIGTSTP)   Functions for assigned communication line (either external or console tty):     sysinit()               -- System dependent program initialization    syscleanup()            -- System dependent program shutdown    ttopen(ttname,local,mdmtyp,timo) -- Open the named tty for exclusive access.    ttclos()                -- Close& reset the tty, releasing any access lock.    ttsspd(cps)             -- Set the transmission speed of the tty.    ttgspd()                -- Get (read) the the transmission speed of the tty.    ttpkt(speed,flow,parity) -- Put the tty in packet mode and set the speed.    ttvt(speed,flow)        -- Put the tty in virtual terminal mode.                                 or in DIALING or CONNECTED modem control state.    ttres()                 -- Restore original tty modes.    ttscarr(carrier)        -- Set carrier control mode, on/off/auto.    ttinl(dest,max,timo)    -- Timed read line from the tty.    ttinc(timo)             -- Timed read character from tty.    myread()                -- Raw mode bulk buffer read, gives subsequent                                 chars one at a time and simulates FIONREAD.    myunrd(c)               -- Places c back in buffer to be read (one only)    ttchk()                 -- See how many characters in tty input buffer.    ttxin(n,buf)            -- Read n characters from tty (untimed).    ttol(string,length)     -- Write a string to the tty.    ttoc(c)                 -- Write a character to the tty.    ttflui()                -- Flush tty input buffer.    ttsndb()                -- Send BREAK signal.    ttsndlb()               -- Send Long BREAK signal.     ttlock(ttname)          -- "Lock" tty device against uucp collisions.    ttunlck()               -- Unlock tty device.                                For ATT7300/Unix PC, System V:    attdial(ttname,speed,telnbr) -- dials ATT7300/Unix PC internal modem    offgetty(ttname)        -- Turns off getty(1m) for comms line    ongetty(ttname)         -- Restores getty() to comms line */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Functions for console terminal:     congm()   -- Get console terminal modes.    concb(esc) -- Put the console in single-character wakeup mode with no echo.    conbin(esc) -- Put the console in binary (raw) mode.    conres()  -- Restore the console to mode obtained by congm().    conoc(c)  -- Unbuffered output, one character to console.    conol(s)  -- Unbuffered output, null-terminated string to the console.    conola(s) -- Unbuffered output, array of strings to the console.    conxo(n,s) -- Unbuffered output, n characters to the console.    conchk()  -- Check if characters available at console (bsd 4.2).                 Check if escape char (^\) typed at console (System III/V).    coninc(timo)  -- Timed get a character from the console.    congks(timo)  -- Timed get keyboard scan code.    conint()  -- Enable terminal interrupts on the console if not background.    connoi()  -- Disable terminal interrupts on the console if not background.  Time functions     msleep(m) -- Millisecond sleep    ztime(&s) -- Return pointer to date/time string    rtimer() --  Reset timer    gtimer()  -- Get elapsed time since last call to rtimer() */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Conditional Includes */
end_comment

begin_comment
comment|/* Whether to include<sys/file.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RTU
end_ifdef

begin_comment
comment|/* RTU doesn't */
end_comment

begin_define
define|#
directive|define
name|NOFILEH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTU */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CIE
end_ifdef

begin_comment
comment|/* CIE does. */
end_comment

begin_undef
undef|#
directive|undef
name|NOFILEH
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CIE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD41
end_ifdef

begin_comment
comment|/* 4.1 BSD doesn't */
end_comment

begin_define
define|#
directive|define
name|NOFILEH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD41 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|is68k
end_ifdef

begin_comment
comment|/* is68k (whatever that is)  */
end_comment

begin_define
define|#
directive|define
name|NOFILEH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* is68k */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_comment
comment|/* MINIX */
end_comment

begin_define
define|#
directive|define
name|NOFILEH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_comment
comment|/* Coherent */
end_comment

begin_define
define|#
directive|define
name|NOFILEH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOFILEH
end_ifndef

begin_comment
comment|/* Now include if selected. */
end_comment

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOFILEH */
end_comment

begin_comment
comment|/* POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
end_ifdef

begin_comment
comment|/* POSIX uses termios.h */
end_comment

begin_define
define|#
directive|define
name|TERMIOS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|bsdi
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NCCS
end_ifndef

begin_define
define|#
directive|define
name|NCCS
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCCS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bsdi */
end_comment

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD44
end_ifndef

begin_comment
comment|/* Really POSIX */
end_comment

begin_define
define|#
directive|define
name|NOSYSIOCTLH
end_define

begin_comment
comment|/* No ioctl's allowed. */
end_comment

begin_undef
undef|#
directive|undef
name|ultrix
end_undef

begin_comment
comment|/* Turn off any ultrix features. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_comment
comment|/* System III, System V */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD44
end_ifndef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_comment
comment|/* Sys V R4 and later */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIOX
end_ifdef

begin_comment
comment|/* Need this for termiox structure, RTS/CTS and DTR/CD flow control */
end_comment

begin_include
include|#
directive|include
file|<termiox.h>
end_include

begin_decl_stmt
name|struct
name|termiox
name|rctsx
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|STERMIOX
end_ifdef

begin_include
include|#
directive|include
file|<sys/termiox.h>
end_include

begin_decl_stmt
name|struct
name|termiox
name|rctsx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STERMIOX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TERMIOX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_comment
comment|/* MINIX uses ioctl's */
end_comment

begin_define
define|#
directive|define
name|NOSYSIOCTLH
end_define

begin_comment
comment|/* but has no<sys/ioctl.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_comment
comment|/* Others */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSYSIOCTLH
end_ifndef

begin_comment
comment|/* Others use ioctl() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4S5
end_ifdef

begin_comment
comment|/*   This is to get rid of cpp warning messages that occur because all of   these symbols are defined by both termios.h and ioctl.h on the SUN. */
end_comment

begin_undef
undef|#
directive|undef
name|ECHO
end_undef

begin_undef
undef|#
directive|undef
name|NL0
end_undef

begin_undef
undef|#
directive|undef
name|NL1
end_undef

begin_undef
undef|#
directive|undef
name|TAB0
end_undef

begin_undef
undef|#
directive|undef
name|TAB1
end_undef

begin_undef
undef|#
directive|undef
name|TAB2
end_undef

begin_undef
undef|#
directive|undef
name|XTABS
end_undef

begin_undef
undef|#
directive|undef
name|CR0
end_undef

begin_undef
undef|#
directive|undef
name|CR1
end_undef

begin_undef
undef|#
directive|undef
name|CR2
end_undef

begin_undef
undef|#
directive|undef
name|CR3
end_undef

begin_undef
undef|#
directive|undef
name|FF0
end_undef

begin_undef
undef|#
directive|undef
name|FF1
end_undef

begin_undef
undef|#
directive|undef
name|BS0
end_undef

begin_undef
undef|#
directive|undef
name|BS1
end_undef

begin_undef
undef|#
directive|undef
name|TOSTOP
end_undef

begin_undef
undef|#
directive|undef
name|FLUSHO
end_undef

begin_undef
undef|#
directive|undef
name|PENDIN
end_undef

begin_undef
undef|#
directive|undef
name|NOFLSH
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUN4S5 */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSYSIOCTLH */
end_comment

begin_comment
comment|/* Whether to include<fcntl.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|is68k
end_ifndef

begin_comment
comment|/* Only a few don't have this one. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD41
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|FT21
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|FT18
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|COHERENT
end_ifndef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT18 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT21 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD41 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not is68k */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT7300
end_ifdef

begin_comment
comment|/* Unix PC, internal modem dialer */
end_comment

begin_include
include|#
directive|include
file|<sys/phone.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATT7300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_comment
comment|/* HP-UX variations. */
end_comment

begin_define
define|#
directive|define
name|HPUXJOBCTL
end_define

begin_include
include|#
directive|include
file|<sys/modem.h>
end_include

begin_comment
comment|/* HP-UX modem signals */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp9000s500
end_ifdef

begin_comment
comment|/* Model 500 */
end_comment

begin_undef
undef|#
directive|undef
name|HPUXJOBCTL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hp9000s500 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUXPRE65
end_ifdef

begin_undef
undef|#
directive|undef
name|HPUXJOBCTL
end_undef

begin_typedef
typedef|typedef
name|int
name|mflag
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUXPRE65 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUXJOBCTL
end_ifdef

begin_include
include|#
directive|include
file|<sys/bsdtty.h>
end_include

begin_comment
comment|/* HP-UX Berkeley tty support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUXJOBCTL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX */
end_comment

begin_comment
comment|/* BSD, V7, Coherent, Minix, et al. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVORPOSIX
end_ifdef

begin_comment
comment|/* Sys V or POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIXRS
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXRS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOIEXTEN
end_ifdef

begin_comment
comment|/* This is broken on some systems */
end_comment

begin_undef
undef|#
directive|undef
name|IEXTEN
end_undef

begin_comment
comment|/* like Convex/OS 9.1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOIEXTEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEXTEN
end_ifndef

begin_comment
comment|/* Turn off ^O/^V processing. */
end_comment

begin_define
define|#
directive|define
name|IEXTEN
value|0
end_define

begin_comment
comment|/* Needed, at least, on BSDI. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEXTEN */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not AT&T Sys V or POSIX */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/* So we use<sgtty.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROVX1
end_ifndef

begin_comment
comment|/* Now<sys/time.h> ... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|V7
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD41
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|COHERENT
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* Clock info (for break generation) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD41 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROVX1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVORPOSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OSF
end_ifdef

begin_comment
comment|/* DEC OSF/1 1.0 */
end_comment

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD41
end_ifdef

begin_comment
comment|/* BSD 4.1 */
end_comment

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD41 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT21
end_ifdef

begin_comment
comment|/* For:Pro 2.1 */
end_comment

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT21 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
end_ifdef

begin_comment
comment|/* BSD 2.9 */
end_comment

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD29 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TOWER1
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_comment
comment|/* Clock info for NCR Tower */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TOWER1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_comment
comment|/* Clock info for NCR Tower */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|aegis
end_ifdef

begin_include
include|#
directive|include
file|"/sys/ins/base.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/error.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/ios.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/sio.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/pad.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/time.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/pfm.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/pgm.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/ec2.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/type_uids.ins.c"
end_include

begin_include
include|#
directive|include
file|<default_acl.h>
end_include

begin_undef
undef|#
directive|undef
name|TIOCEXCL
end_undef

begin_undef
undef|#
directive|undef
name|FIONREAD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* aegis */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sxaE50
end_ifdef

begin_comment
comment|/* PFU Compact A SX/A TISP V10/L50 */
end_comment

begin_undef
undef|#
directive|undef
name|FIONREAD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sxaE50 */
end_comment

begin_comment
comment|/* The following #defines are catch-alls for those systems */
end_comment

begin_comment
comment|/* that didn't have or couldn't find<file.h>... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FREAD
end_ifndef

begin_define
define|#
directive|define
name|FREAD
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FREAD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FWRITE
end_ifndef

begin_define
define|#
directive|define
name|FWRITE
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FWRITE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* O_RDONLY */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Declarations */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_comment
comment|/* This includes MINIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AIXRS
end_ifndef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXRS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|XENIX
end_ifdef

begin_comment
comment|/*   Because Xenix<time.h> doesn't declare time() if we're using gcc. */
end_comment

begin_function_decl
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XENIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_function_decl
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* All Unixes should have this... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Special stuff for V7 input buffer peeking */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_decl_stmt
name|int
name|kmem
index|[
literal|2
index|]
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|initrawq
argument_list|()
decl_stmt|,
modifier|*
name|qaddr
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CON
value|0
end_define

begin_define
define|#
directive|define
name|TTY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_comment
comment|/* dftty is the device name of the default device for file transfer */
end_comment

begin_comment
comment|/* dfloc is 0 if dftty is the user's console terminal, 1 if an external line */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DFTTY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|dftty
init|=
literal|"/dev/com1.dout"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Only example so far of a system */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dfmdm
init|=
literal|"none"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dfloc
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* that goes in local mode by default */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|dftty
init|=
literal|"/dev/modem"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dfmdm
init|=
literal|"none"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dfloc
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|dftty
init|=
name|CTTNAM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remote by default, use normal */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dfmdm
init|=
literal|"none"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dfloc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* controlling terminal name. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROVX1 */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|dftty
init|=
name|DFTTY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default location specified on */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dfmdm
init|=
literal|"none"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command line. */
end_comment

begin_decl_stmt
name|int
name|dfloc
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* controlling terminal name. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DFTTY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RTU
end_ifdef

begin_decl_stmt
name|int
name|rtu_bug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 when returning from SIGTSTP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTU */
end_comment

begin_decl_stmt
name|int
name|dfprty
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default parity (0 = none) */
end_comment

begin_decl_stmt
name|int
name|ttprty
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The parity that is in use. */
end_comment

begin_decl_stmt
name|int
name|ttpflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parity not sensed yet. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ttpmsk
init|=
literal|0377
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parity stripping mask. */
end_comment

begin_decl_stmt
name|int
name|ttmdm
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Modem in use. */
end_comment

begin_decl_stmt
name|int
name|ttcarr
init|=
name|CAR_AUT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Carrier handling mode. */
end_comment

begin_decl_stmt
name|int
name|dfflow
init|=
name|FLO_XONX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default is Xon/Xoff */
end_comment

begin_decl_stmt
name|int
name|backgrd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assume in foreground (no '&' ) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_decl_stmt
name|int
name|iniflags
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fcntl flags for ttyfd */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix */
end_comment

begin_decl_stmt
name|int
name|fdflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for redirected stdio */
end_comment

begin_decl_stmt
name|int
name|ttfdflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open File descriptor was given */
end_comment

begin_decl_stmt
name|int
name|tvtflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag that ttvt has been called */
end_comment

begin_decl_stmt
name|long
name|ttspeed
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For saving speed */
end_comment

begin_decl_stmt
name|int
name|ttflow
init|=
operator|-
literal|9
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For saving flow */
end_comment

begin_decl_stmt
name|int
name|ttld
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line discipline */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sony_news
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|km_con
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Kanji mode for console tty */
end_comment

begin_decl_stmt
specifier|static
name|int
name|km_ext
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Kanji mode for external device */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sony_news */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ttnproto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in ckcnet.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ttnet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in ckcnet.c */
end_comment

begin_decl_stmt
name|int
name|ckxech
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 if system normally echoes console characters, else 1 */
end_comment

begin_comment
comment|/* Declarations of variables global within this module */
end_comment

begin_decl_stmt
specifier|static
name|time_t
name|tcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Elapsed time counter */
end_comment

begin_function_decl
specifier|static
name|SIGTYP
function_decl|(
modifier|*
name|saval
function_decl|)
parameter_list|()
init|=
name|NULL
function_decl|;
end_function_decl

begin_comment
comment|/* For saving alarm() handler */
end_comment

begin_comment
comment|/*   BREAKNULS is defined for systems that simulate sending a BREAK signal   by sending a bunch of NUL characters at low speed. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BREAKNULS
end_ifndef

begin_define
define|#
directive|define
name|BREAKNULS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BREAKNULS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROVX1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BREAKNULS
end_ifndef

begin_define
define|#
directive|define
name|BREAKNULS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BREAKNULS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BREAKNULS
end_ifdef

begin_decl_stmt
specifier|static
name|char
comment|/* A string of nulls */
modifier|*
name|brnuls
init|=
literal|"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BREAKNULS */
end_comment

begin_decl_stmt
specifier|static
name|jmp_buf
name|sjbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Longjump buffers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_decl_stmt
specifier|static
name|jmp_buf
name|jjbuf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_comment
comment|/* static */
end_comment

begin_comment
comment|/* (Not static any more) */
end_comment

begin_decl_stmt
name|int
name|ttyfd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TTY file descriptor */
end_comment

begin_decl_stmt
name|int
name|telnetfd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor is for telnet */
end_comment

begin_decl_stmt
name|int
name|x25fd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor is for X.25 */
end_comment

begin_decl_stmt
specifier|static
name|int
name|lkf
init|=
literal|0
decl_stmt|,
comment|/* Line lock flag */
name|cgmf
init|=
literal|0
decl_stmt|,
comment|/* Flag that console modes saved */
name|xlocal
init|=
literal|0
decl_stmt|,
comment|/* Flag for tty local or remote */
name|curcarr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Carrier mode: require/ignore. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|netconn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if network connection active */
end_comment

begin_decl_stmt
specifier|static
name|char
name|escchr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Escape or attn character */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIXRS
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|timeval
name|tv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For getting time, from sys/time.h */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timezone
name|tz
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|timeval
name|tv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For getting time, from sys/time.h */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timezone
name|tz
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|timeval
name|tv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For getting time, from sys/time.h */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timezone
name|tz
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OSF
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|timeb
name|ftp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And from sys/timeb.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD42 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXRS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|xclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For getting time from sys/time.h */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timeb
name|ftp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And from sys/timeb.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD29 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD41
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|xclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For getting time from sys/time.h */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timeb
name|ftp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And from sys/timeb.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD41 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT21
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|xclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For getting time from sys/time.h */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timeb
name|ftp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And from sys/timeb.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT21 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TOWER1
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|xclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For getting time from sys/time.h */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timeb
name|ftp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And from sys/timeb.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TOWER1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|xclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For getting time from sys/time.h */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timeb
name|ftp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And from sys/timeb.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|xclock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_comment
comment|/* sgtty/termio information... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
end_ifdef

begin_comment
comment|/* POSIX or BSD44 */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|termios
name|ttold
decl_stmt|,
name|ttraw
decl_stmt|,
name|tttvt
decl_stmt|,
name|ttcur
decl_stmt|,
name|ccold
decl_stmt|,
name|ccraw
decl_stmt|,
name|cccbrk
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD, V7, etc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|termio
name|ttold
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Init'd for word alignment, */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|termio
name|ttraw
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which is important for some */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|termio
name|tttvt
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* systems, like Zilog... */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|termio
name|ttcur
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|termio
name|ccold
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|termio
name|ccraw
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|termio
name|cccbrk
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|struct
name|sgttyb
comment|/* sgtty info... */
name|ttold
decl_stmt|,
name|ttraw
decl_stmt|,
name|tttvt
decl_stmt|,
name|ttcur
decl_stmt|,
comment|/* for communication line */
name|ccold
decl_stmt|,
name|ccraw
decl_stmt|,
name|cccbrk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and for console */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCGETC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|sgttyb
name|tchold
decl_stmt|,
name|tchnoi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Special chars */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|struct
name|tchars
name|tchold
decl_stmt|,
name|tchnoi
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_decl_stmt
specifier|static
name|int
name|tcharf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIOCGETC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCGLTC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|sgttyb
name|ltchold
decl_stmt|,
name|ltchnoi
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|struct
name|ltchars
name|ltchold
decl_stmt|,
name|ltchnoi
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ltcharf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIOCGLTC */
end_comment

begin_decl_stmt
name|int
name|lmodef
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local modes */
end_comment

begin_decl_stmt
name|int
name|lmode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44ORPOSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|sgttyb
name|ttbuf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROVX1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_comment
comment|/* do we really need this? */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|sgttyb
name|vanilla
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT7300
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|attmodem
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ATT7300 internal-modem status */
end_comment

begin_decl_stmt
name|struct
name|updata
name|dialer
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Condition dialer for data call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATT7300 */
end_comment

begin_decl_stmt
name|char
name|flfnam
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uucp lock file path name */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RTAIX
end_ifdef

begin_decl_stmt
name|char
name|lkflfn
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and possible link to it */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTAIX */
end_comment

begin_decl_stmt
name|int
name|haslock
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* =1 if this kermit locked uucp */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVORPOSIX
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|conesc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 if esc char (^\) typed */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|conesc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|C70
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|conesc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C70 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_decl_stmt
specifier|static
name|char
name|ttnmsv
index|[
name|DEVNAMLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy of open path for tthang */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|aegis
end_ifdef

begin_decl_stmt
specifier|static
name|status_$t
name|st
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error status return value */
end_comment

begin_decl_stmt
specifier|static
name|short
name|concrp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if console is CRP pad */
end_comment

begin_define
define|#
directive|define
name|CONBUFSIZ
value|10
end_define

begin_decl_stmt
specifier|static
name|char
name|conbuf
index|[
name|CONBUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* console readahead buffer */
end_comment

begin_decl_stmt
specifier|static
name|int
name|conbufn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # chars in readahead buffer */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|conbufp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next char in readahead buffer */
end_comment

begin_decl_stmt
specifier|static
name|uid_$t
name|ttyuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty type uid */
end_comment

begin_decl_stmt
specifier|static
name|uid_$t
name|conuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stdout type uid */
end_comment

begin_comment
comment|/* APOLLO Aegis main()  * establish acl usage and cleanup handling  *    this makes sure that CRP pads  *    get restored to a usable mode  */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|status_$t
name|status
decl_stmt|;
name|pfm_$cleanup_rec
name|dirty
decl_stmt|;
name|PID_T
name|pid
init|=
name|getpid
argument_list|()
decl_stmt|;
comment|/* acl usage according to invoking environment */
name|default_acl
argument_list|(
name|USE_DEFENV
argument_list|)
expr_stmt|;
comment|/* establish a cleanup continuation */
name|status
operator|=
name|pfm_$cleanup
argument_list|(
name|dirty
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|.
name|all
operator|!=
name|pfm_$cleanup_set
condition|)
block|{
comment|/* only handle faults for the original process */
if|if
condition|(
name|pid
operator|==
name|getpid
argument_list|()
operator|&&
name|status
operator|.
name|all
operator|>
name|pgm_$max_severity
condition|)
block|{
comment|/* blew up in main process */
name|status_$t
name|quo
decl_stmt|;
name|pfm_$cleanup_rec
name|clean
decl_stmt|;
comment|/* restore the console in any case */
name|conres
argument_list|()
expr_stmt|;
comment|/* attempt a clean exit */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"cleanup fault status"
argument_list|,
literal|""
argument_list|,
name|status
operator|.
name|all
argument_list|)
expr_stmt|;
comment|/* doexit(), then send status to continuation */
name|quo
operator|=
name|pfm_$cleanup
argument_list|(
name|clean
argument_list|)
expr_stmt|;
if|if
condition|(
name|quo
operator|.
name|all
operator|==
name|pfm_$cleanup_set
condition|)
name|doexit
argument_list|(
name|pgm_$program_faulted
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|quo
operator|.
name|all
operator|>
name|pgm_$max_severity
condition|)
name|pfm_$signal
argument_list|(
name|quo
argument_list|)
expr_stmt|;
comment|/* blew up in doexit() */
block|}
comment|/* send to the original continuation */
name|pfm_$signal
argument_list|(
name|status
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
return|return
operator|(
name|ckcmai
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* aegis */
end_comment

begin_escape
end_escape

begin_comment
comment|/* ANSI-style prototypes for internal functions. */
end_comment

begin_comment
comment|/* Functions used outside this module are prototyped in ckcker.h. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP timerh
argument_list|,
argument|()
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP cctrap
argument_list|,
argument|()
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP esctrp
argument_list|,
argument|()
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP sig_ign
argument_list|,
argument|()
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP timerh
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP cctrap
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP esctrp
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int do_open
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttrpid
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static int ttlock
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static int ttunlck
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int mygetbuf
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int myfillbuf
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID conbgt
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ACUCNTRL
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID acucntrl
argument_list|,
argument|(char *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACUCNTRL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int carrctl
argument_list|,
argument|(struct termios *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int carrctl
argument_list|,
argument|(struct termio *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|_PROTOTYP
argument_list|(
argument|int carrctl
argument_list|,
argument|(struct sgttyb *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44ORPOSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT7300
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int attdial
argument_list|,
argument|(char *, long, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int offgetty
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ongetty
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATT7300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSIC
end_ifdef

begin_function
specifier|static
name|char
modifier|*
name|xxlast
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|char
name|c
parameter_list|)
else|#
directive|else
function|static char * xxlast
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* xxlast */
block|{
comment|/*  Last occurrence of character c in string s. */
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
if|if
condition|(
name|s
index|[
name|i
operator|-
literal|1
index|]
operator|==
name|c
condition|)
return|return
operator|(
name|s
operator|+
operator|(
name|i
operator|-
literal|1
operator|)
operator|)
return|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Timeout handler for communication line input functions */
end_comment

begin_function
name|SIGTYP
name|timerh
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
name|ttimoff
argument_list|()
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Control-C trap for communication line input functions */
end_comment

begin_decl_stmt
name|int
name|cc_int
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag */
end_comment

begin_function_decl
name|SIGTYP
function_decl|(
modifier|*
name|occt
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* For saving old SIGINT handler */
end_comment

begin_function
name|SIGTYP
name|cctrap
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* Needs arg for ANSI C */
name|cc_int
operator|=
literal|1
expr_stmt|;
comment|/* signal() prototype. */
return|return;
block|}
end_function

begin_comment
comment|/*  S Y S I N I T  --  System-dependent program initialization.  */
end_comment

begin_function
name|int
name|sysinit
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|conbgt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* See if we're in the background */
ifndef|#
directive|ifndef
name|__386BSD__
comment|/*   386BSD doesn't allow opening /dev/tty if Kermit is running setuid. */
name|congm
argument_list|()
expr_stmt|;
comment|/* Get console modes */
endif|#
directive|endif
comment|/* __386BSD__ */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Ignore alarms */
ifdef|#
directive|ifdef
name|ultrix
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|vanilla
argument_list|)
expr_stmt|;
comment|/* Get sgtty info */
name|iniflags
operator|=
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Get flags */
else|#
directive|else
ifdef|#
directive|ifdef
name|AUX
name|set42sig
argument_list|()
expr_stmt|;
comment|/* Don't ask! (hakanson@cs.orst.edu) */
endif|#
directive|endif
comment|/* AUX */
endif|#
directive|endif
comment|/* ultrix */
comment|/* Initialize the setuid package. */
comment|/* Change to the user's real user and group id. */
comment|/* If this can't be done, don't run at all. */
if|if
condition|(
name|x
operator|=
name|priv_ini
argument_list|()
condition|)
block|{
if|if
condition|(
name|x
operator||
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Fatal: setuid failure.\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator||
literal|2
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Fatal: setgid failure.\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator||
literal|4
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Fatal: C-Kermit setuid to root!\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|__386BSD__
comment|/*   386BSD...  OK, now we have changed into ourselves, so can open /dev/tty. */
name|congm
argument_list|()
expr_stmt|;
comment|/* Get console modes */
endif|#
directive|endif
comment|/* __386BSD__ */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  S Y S C L E A N U P  --  System-dependent program cleanup.  */
end_comment

begin_function
name|int
name|syscleanup
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|ultrix
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|vanilla
argument_list|)
expr_stmt|;
comment|/* Get sgtty info */
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETFL
argument_list|,
name|iniflags
argument_list|)
expr_stmt|;
comment|/* Restore flags */
endif|#
directive|endif
comment|/* ultrix */
comment|/* No need to call anything in the suid package here, right? */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  T T O P E N  --  Open a tty for exclusive access.  */
end_comment

begin_comment
comment|/*   Call with:     ttname: character string - device name or network host name.     lcl:   If called with lcl< 0, sets value of lcl as follows:   0: the terminal named by ttname is the job's controlling terminal.   1: the terminal named by ttname is not the job's controlling terminal.   But watch out: if a line is already open, or if requested line can't   be opened, then lcl remains (and is returned as) -1.     modem:   Less than zero: ttname is a network host name.   Zero or greater: ttname is a terminal device name.       Zero means a local connection (don't use modem signals).   Positive means use modem signals.      timo:   0 = no timer.   nonzero = number of seconds to wait for open() to return before timing out.    Returns:     0 on success    -5 if device is in use    -4 if access to device is denied    -3 if access to lock directory denied    -2 upon timeout waiting for device to open    -1 on other error */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ttotmo
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Timeout flag */
end_comment

begin_comment
comment|/* Flag kept here to avoid being clobbered by longjmp.  */
end_comment

begin_function
name|int
name|ttopen
parameter_list|(
name|ttname
parameter_list|,
name|lcl
parameter_list|,
name|modem
parameter_list|,
name|timo
parameter_list|)
name|char
modifier|*
name|ttname
decl_stmt|;
name|int
modifier|*
name|lcl
decl_stmt|,
name|modem
decl_stmt|,
name|timo
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|BSD44
define|#
directive|define
name|ctermid
parameter_list|(
name|x
parameter_list|)
value|strcpy(x,"")
else|#
directive|else
ifdef|#
directive|ifdef
name|SVORPOSIX
ifndef|#
directive|ifndef
name|CIE
specifier|extern
name|char
modifier|*
name|ctermid
parameter_list|()
function_decl|;
comment|/* Wish they all had this! */
else|#
directive|else
comment|/* CIE Regulus */
define|#
directive|define
name|ctermid
parameter_list|(
name|x
parameter_list|)
value|strcpy(x,"")
endif|#
directive|endif
comment|/* CIE */
endif|#
directive|endif
comment|/* SVORPOSIX */
endif|#
directive|endif
comment|/* BSD44 */
name|char
modifier|*
name|x
decl_stmt|;
comment|/* what's this ? */
ifndef|#
directive|ifndef
name|MINIX
specifier|extern
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* MINIX */
name|char
name|cname
index|[
name|DEVNAMLEN
operator|+
literal|4
index|]
decl_stmt|;
ifndef|#
directive|ifndef
name|pdp11
define|#
directive|define
name|NAMEFD
comment|/* Feature to allow name to be an open file descriptor */
endif|#
directive|endif
comment|/* pdp11 */
ifdef|#
directive|ifdef
name|NAMEFD
name|char
modifier|*
name|p
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen telnetfd"
argument_list|,
literal|""
argument_list|,
name|telnetfd
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NAMEFD */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen entry modem"
argument_list|,
name|ttname
argument_list|,
name|modem
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ttyfd"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" lcl"
argument_list|,
literal|""
argument_list|,
operator|*
name|lcl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MAXNAMLEN
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen MAXNAMLEN defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen MAXNAMLEN *NOT* defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BSD4
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen BSD4 defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen BSD4 *NOT* defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BSD42
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen BSD42 defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen BSD42 *NOT* defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD42 */
ifdef|#
directive|ifdef
name|MYREAD
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen MYREAD defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen MYREAD *NOT* defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MYREAD */
if|if
condition|(
name|ttyfd
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* if device already opened */
if|if
condition|(
name|strncmp
argument_list|(
name|ttname
argument_list|,
name|ttnmsv
argument_list|,
name|DEVNAMLEN
argument_list|)
condition|)
comment|/* are new& old names equal? */
name|ttclos
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* no, close old ttname, open new */
else|else
comment|/* else same, ignore this call, */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* and return. */
block|}
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|modem
operator|<
literal|0
condition|)
block|{
comment|/* modem< 0 = special code for net */
name|int
name|x
decl_stmt|;
name|ttmdm
operator|=
name|modem
expr_stmt|;
name|modem
operator|=
operator|-
name|modem
expr_stmt|;
comment|/* Positive network type number */
name|fdflag
operator|=
literal|0
expr_stmt|;
comment|/* Stdio not redirected. */
name|netconn
operator|=
literal|1
expr_stmt|;
comment|/* And it's a network connection */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen net"
argument_list|,
name|ttname
argument_list|,
name|modem
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NAMEFD
for|for
control|(
name|p
operator|=
name|ttname
init|;
name|isdigit
argument_list|(
operator|*
name|p
argument_list|)
condition|;
name|p
operator|++
control|)
empty_stmt|;
comment|/* Check for all digits */
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
operator|&&
operator|(
name|telnetfd
operator|||
name|x25fd
operator|)
condition|)
block|{
comment|/* Avoid X.121 addresses */
name|ttyfd
operator|=
name|atoi
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
comment|/* Is there a way to test it's open? */
name|ttfdflg
operator|=
literal|1
expr_stmt|;
comment|/* We got an open file descriptor */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen got open network fd"
argument_list|,
name|ttname
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|ttnmsv
argument_list|,
name|ttname
argument_list|,
name|DEVNAMLEN
argument_list|)
expr_stmt|;
comment|/* Remember the "name". */
name|x
operator|=
literal|1
expr_stmt|;
comment|/* Return code is "good". */
if|if
condition|(
name|telnetfd
condition|)
block|{
name|ttnet
operator|=
name|NET_TCPB
expr_stmt|;
name|ttnproto
operator|=
name|NP_TELNET
expr_stmt|;
ifdef|#
directive|ifdef
name|SUNX25
block|}
elseif|else
if|if
condition|(
name|x25fd
condition|)
block|{
name|ttnet
operator|=
name|NET_SX25
expr_stmt|;
name|ttnproto
operator|=
name|NP_NONE
expr_stmt|;
endif|#
directive|endif
comment|/* SUNX25 */
block|}
block|}
else|else
block|{
comment|/* Host name or address given */
endif|#
directive|endif
comment|/* NAMEFD */
name|x
operator|=
name|netopen
argument_list|(
name|ttname
argument_list|,
name|lcl
argument_list|,
name|modem
argument_list|)
expr_stmt|;
comment|/* (see ckcnet.h) */
if|if
condition|(
name|x
operator|>
operator|-
literal|1
condition|)
block|{
name|strncpy
argument_list|(
name|ttnmsv
argument_list|,
name|ttname
argument_list|,
name|DEVNAMLEN
argument_list|)
expr_stmt|;
block|}
else|else
name|netconn
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|NAMEFD
block|}
endif|#
directive|endif
comment|/* NAMEFD */
ifdef|#
directive|ifdef
name|sony_news
comment|/* Sony NEWS */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCKGET
argument_list|,
operator|&
name|km_ext
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Get Kanji mode */
name|perror
argument_list|(
literal|"ttopen error getting Kanji mode (network)"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen error getting Kanji mode"
argument_list|,
literal|"network"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|km_ext
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Make sure this stays undefined. */
block|}
endif|#
directive|endif
comment|/* sony_news */
name|xlocal
operator|=
operator|*
name|lcl
operator|=
literal|1
expr_stmt|;
comment|/* Network connections are local. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen net x"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|>
operator|-
literal|1
operator|&&
operator|!
name|x25fd
condition|)
name|x
operator|=
name|tn_ini
argument_list|()
expr_stmt|;
comment|/* Initialize TELNET protocol */
return|return
operator|(
name|x
operator|)
return|;
block|}
else|else
block|{
comment|/* Terminal device */
endif|#
directive|endif
comment|/* NETCONN */
ifdef|#
directive|ifdef
name|NAMEFD
comment|/*   This code lets you give Kermit an open file descriptor for a serial   communication device, rather than a device name.  Kermit assumes that the   line is already open, locked, conditioned with the right parameters, etc. */
for|for
control|(
name|p
operator|=
name|ttname
init|;
name|isdigit
argument_list|(
operator|*
name|p
argument_list|)
condition|;
name|p
operator|++
control|)
empty_stmt|;
comment|/* Check for all digits */
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
block|{
name|ttyfd
operator|=
name|atoi
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
comment|/* Is there a way to test it's open? */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen got open fd"
argument_list|,
name|ttname
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|ttnmsv
argument_list|,
name|ttname
argument_list|,
name|DEVNAMLEN
argument_list|)
expr_stmt|;
comment|/* Remember the "name". */
name|xlocal
operator|=
operator|*
name|lcl
operator|=
literal|1
expr_stmt|;
comment|/* Assume it's local. */
name|netconn
operator|=
literal|0
expr_stmt|;
comment|/* Assume it's not a network. */
name|tvtflg
operator|=
literal|0
expr_stmt|;
comment|/* Might need to initialize modes. */
name|ttmdm
operator|=
name|modem
expr_stmt|;
comment|/* Remember modem type. */
name|fdflag
operator|=
literal|0
expr_stmt|;
comment|/* Stdio not redirected. */
name|ttfdflg
operator|=
literal|1
expr_stmt|;
comment|/* Flag we were opened this way. */
ifdef|#
directive|ifdef
name|sony_news
comment|/* Sony NEWS */
comment|/* Get device Kanji mode */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCKGET
argument_list|,
operator|&
name|km_ext
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"ttopen error getting Kanji mode"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen error getting Kanji mode"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|km_ext
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Make sure this stays undefined. */
block|}
endif|#
directive|endif
comment|/* sony_news */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Return success */
block|}
endif|#
directive|endif
comment|/* NAMEFD */
ifdef|#
directive|ifdef
name|NETCONN
block|}
endif|#
directive|endif
comment|/* NETCONN */
comment|/* Here we have to open a serial device of the given name. */
name|occt
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|cctrap
argument_list|)
expr_stmt|;
comment|/* Set Control-C trap, save old one */
name|tvtflg
operator|=
literal|0
expr_stmt|;
comment|/* Flag for use by ttvt(). */
comment|/* 0 = ttvt not called yet for this device */
name|fdflag
operator|=
operator|(
operator|!
name|isatty
argument_list|(
literal|0
argument_list|)
operator|||
operator|!
name|isatty
argument_list|(
literal|1
argument_list|)
operator|)
expr_stmt|;
comment|/* Flag for stdio redirected */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen fdflag"
argument_list|,
literal|""
argument_list|,
name|fdflag
argument_list|)
expr_stmt|;
name|ttmdm
operator|=
name|modem
expr_stmt|;
comment|/* Make this available to other fns */
name|xlocal
operator|=
operator|*
name|lcl
expr_stmt|;
comment|/* Make this available to other fns */
comment|/* Code for handling bidirectional tty lines goes here. */
comment|/* Use specified method for turning off logins and suppressing getty. */
ifdef|#
directive|ifdef
name|ACUCNTRL
comment|/* Should put call to priv_on() here, but that would be very risky! */
name|acucntrl
argument_list|(
literal|"disable"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
comment|/* acucntrl() program. */
comment|/* and priv_off() here... */
else|#
directive|else
ifdef|#
directive|ifdef
name|ATT7300
if|if
condition|(
operator|(
name|attmodem
operator|&
name|DOGETY
operator|)
operator|==
literal|0
condition|)
comment|/* offgetty() program. */
name|attmodem
operator||=
name|offgetty
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
comment|/* Remember response.  */
endif|#
directive|endif
comment|/* ATT7300 */
endif|#
directive|endif
comment|/* ACUCNTRL */
comment|/*  In the following section, we open the tty device for read/write.  If a modem has been specified via "set modem" prior to "set line"  then the O_NDELAY parameter is used in the open, provided this symbol  is defined (e.g. in fcntl.h), so that the program does not hang waiting  for carrier (which in most cases won't be present because a connection  has not been dialed yet).  O_NDELAY is removed later on in ttopen().  It  would make more sense to first determine if the line is local before  doing this, but because ttyname() requires a file descriptor, we have  to open it first.  See do_open().   Now open the device using the desired treatment of carrier.  If carrier is REQUIRED, then open could hang forever, so an optional  timer is provided.  If carrier is not required, the timer should never  go off, and should do no harm... */
name|ttotmo
operator|=
literal|0
expr_stmt|;
comment|/* Flag no timeout */
if|if
condition|(
name|timo
operator|>
literal|0
condition|)
block|{
name|int
name|xx
decl_stmt|;
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Timed, set up timer. */
name|xx
operator|=
name|alarm
argument_list|(
name|timo
argument_list|)
expr_stmt|;
comment|/* Timed open() */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen alarm"
argument_list|,
literal|""
argument_list|,
name|xx
argument_list|)
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
block|{
name|ttotmo
operator|=
literal|1
expr_stmt|;
comment|/* Flag timeout. */
block|}
else|else
name|ttyfd
operator|=
name|do_open
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
name|ttimoff
argument_list|()
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen"
argument_list|,
literal|"modem"
argument_list|,
name|modem
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ttyfd"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" alarm return"
argument_list|,
literal|""
argument_list|,
name|ttotmo
argument_list|)
expr_stmt|;
block|}
else|else
name|ttyfd
operator|=
name|do_open
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen ttyfd"
argument_list|,
name|ttname
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
block|{
comment|/* If couldn't open, fail. */
ifdef|#
directive|ifdef
name|ATT7300
if|if
condition|(
name|attmodem
operator|&
name|DOGETY
condition|)
comment|/* was getty(1m) running before us? */
name|ongetty
argument_list|(
name|ttnmsv
argument_list|)
expr_stmt|;
comment|/* yes, restart on tty line */
name|attmodem
operator|&=
operator|~
name|DOGETY
expr_stmt|;
comment|/* no phone in use, getty restored */
else|#
directive|else
if|#
directive|if
name|ACUCNTRL
comment|/* Should put call to priv_on() here, but that would be risky! */
name|acucntrl
argument_list|(
literal|"enable"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
comment|/* acucntrl() program. */
comment|/* and priv_off() here... */
endif|#
directive|endif
comment|/* ACUNTRL */
endif|#
directive|endif
comment|/* ATT7300 */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|occt
argument_list|)
expr_stmt|;
comment|/* Put old Ctrl-C trap back. */
if|if
condition|(
name|errno
operator|==
name|EACCES
condition|)
block|{
comment|/* Device is protected against user */
name|perror
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
comment|/* Print message */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen tty access denied"
argument_list|,
name|ttname
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|4
operator|)
return|;
block|}
else|else
return|return
operator|(
name|ttotmo
condition|?
operator|-
literal|2
else|:
operator|-
literal|1
operator|)
return|;
block|}
comment|/* Make sure it's a real tty. */
if|if
condition|(
operator|!
name|isatty
argument_list|(
name|ttyfd
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s is not a tty!\n"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ttopen not a tty"
argument_list|,
name|ttname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
name|ttyfd
operator|=
operator|-
literal|1
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|occt
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|aegis
comment|/* Apollo C runtime claims that console pads are tty devices, which 	 * is reasonable, but they aren't any good for packet transfer. */
name|ios_$inq_type_uid
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|ttyuid
argument_list|,
name|st
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|.
name|all
operator|!=
name|status_$ok
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"problem getting tty object type: "
argument_list|)
expr_stmt|;
name|error_$print
argument_list|(
name|st
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ttyuid
operator|!=
name|sio_$uid
condition|)
block|{
comment|/* reject non-SIO lines */
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
name|ttyfd
operator|=
operator|-
literal|1
expr_stmt|;
name|errno
operator|=
name|ENOTTY
expr_stmt|;
name|perror
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|occt
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* aegis */
name|strncpy
argument_list|(
name|ttnmsv
argument_list|,
name|ttname
argument_list|,
name|DEVNAMLEN
argument_list|)
expr_stmt|;
comment|/*  Keep copy of name locally. */
comment|/* Caller wants us to figure out if line is controlling tty */
if|if
condition|(
operator|*
name|lcl
operator|<
literal|0
condition|)
block|{
name|int
name|x0
init|=
literal|0
decl_stmt|,
name|x1
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|ttname
argument_list|,
name|CTTNAM
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* "/dev/tty" always remote */
name|xlocal
operator|=
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|" ttname=CTTNAM"
argument_list|,
name|ttname
argument_list|,
name|xlocal
argument_list|)
expr_stmt|;
comment|/* If any of 0, 1, or 2 not redirected, we can use ttyname() to get */
comment|/* the name of the controlling terminal... */
comment|/*   Warning: on some UNIX systems (SVR4?), ttyname() reportedly opens /dev but   never closes it.  If it is called often enough, we run out of file   descriptors and subsequent open()'s of other devices or files can fail. */
block|}
elseif|else
if|if
condition|(
operator|(
name|x0
operator|=
name|isatty
argument_list|(
literal|0
argument_list|)
operator|)
operator|||
operator|(
name|x1
operator|=
name|isatty
argument_list|(
literal|1
argument_list|)
operator|)
operator|||
name|isatty
argument_list|(
literal|2
argument_list|)
condition|)
block|{
ifndef|#
directive|ifndef
name|MINIX
if|if
condition|(
name|x0
condition|)
name|x
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* and compare it with the */
elseif|else
if|if
condition|(
name|x1
condition|)
comment|/* tty device name. */
name|x
operator|=
name|ttyname
argument_list|(
literal|1
argument_list|)
expr_stmt|;
else|else
name|x
operator|=
name|ttyname
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|cname
argument_list|,
name|x
argument_list|,
name|DEVNAMLEN
argument_list|)
expr_stmt|;
comment|/* (copy from internal static buf) */
name|debug
argument_list|(
name|F110
argument_list|,
literal|" cname"
argument_list|,
name|x
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|x
operator|=
name|ttyname
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Gat real name of ttname. */
name|xlocal
operator|=
operator|(
name|strncmp
argument_list|(
name|x
argument_list|,
name|cname
argument_list|,
name|DEVNAMLEN
argument_list|)
operator|==
literal|0
operator|)
condition|?
literal|0
else|:
literal|1
expr_stmt|;
comment|/* Compare. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|" ttyname"
argument_list|,
name|x
argument_list|,
name|xlocal
argument_list|)
expr_stmt|;
else|#
directive|else
name|xlocal
operator|=
literal|1
expr_stmt|;
comment|/* Can't do this test in MINIX */
endif|#
directive|endif
comment|/* MINIX */
block|}
else|else
block|{
comment|/* Else, if stdin redirected... */
ifdef|#
directive|ifdef
name|SVORPOSIX
comment|/* System V provides nice ctermid() function to get name of controlling tty */
name|ctermid
argument_list|(
name|cname
argument_list|)
expr_stmt|;
comment|/* Get name of controlling terminal */
name|debug
argument_list|(
name|F110
argument_list|,
literal|" ctermid"
argument_list|,
name|cname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|x
operator|=
name|ttyname
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Compare with name of comm line. */
name|xlocal
operator|=
operator|(
name|strncmp
argument_list|(
name|x
argument_list|,
name|cname
argument_list|,
name|DEVNAMLEN
argument_list|)
operator|==
literal|0
operator|)
condition|?
literal|0
else|:
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|" ttyname"
argument_list|,
name|x
argument_list|,
name|xlocal
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Just assume local */
name|xlocal
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* SVORPOSIX */
name|debug
argument_list|(
name|F101
argument_list|,
literal|" redirected stdin"
argument_list|,
literal|""
argument_list|,
name|xlocal
argument_list|)
expr_stmt|;
block|}
block|}
ifndef|#
directive|ifndef
name|NOFDZERO
comment|/* Note, the following code was added so that Unix "idle-line" snoopers */
comment|/* would not think Kermit was idle when it was transferring files, and */
comment|/* maybe log people out. */
if|if
condition|(
name|xlocal
operator|==
literal|0
condition|)
block|{
comment|/* Remote mode */
if|if
condition|(
name|fdflag
operator|==
literal|0
condition|)
block|{
comment|/* Standard i/o is not redirected */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen setting ttyfd = 0"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Use file descriptor 0 */
name|ttyfd
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|/* Standard i/o is redirected */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen stdio redirected"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* NOFDZERO */
comment|/* Now check if line is locked -- if so fail, else lock for ourselves */
comment|/* Note: After having done this, don't forget to delete the lock if you */
comment|/* leave ttopen() with an error condition. */
name|lkf
operator|=
literal|0
expr_stmt|;
comment|/* Check lock */
if|if
condition|(
name|xlocal
operator|>
literal|0
condition|)
block|{
name|int
name|xx
decl_stmt|;
name|int
name|xpid
decl_stmt|;
if|if
condition|(
operator|(
name|xx
operator|=
name|ttlock
argument_list|(
name|ttname
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Can't lock it. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen ttlock fails"
argument_list|,
name|ttname
argument_list|,
name|xx
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Close the device. */
name|ttyfd
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Erase its file descriptor. */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|occt
argument_list|)
expr_stmt|;
comment|/* Put old SIGINT back. */
if|if
condition|(
name|xx
operator|==
operator|-
literal|2
condition|)
block|{
comment|/* If lockfile says tty is in use, */
name|char
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|200
argument_list|)
decl_stmt|;
comment|/* print an ls -l listing */
if|if
condition|(
name|p
condition|)
block|{
comment|/* if we can get space... */
name|sprintf
argument_list|(
name|p
argument_list|,
literal|"/bin/ls -l %s"
argument_list|,
name|flfnam
argument_list|)
expr_stmt|;
name|zsyscmd
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Get listing. */
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* free the space */
name|xpid
operator|=
name|ttrpid
argument_list|(
name|flfnam
argument_list|)
expr_stmt|;
comment|/* Try to read pid from lockfile */
name|priv_off
argument_list|()
expr_stmt|;
comment|/* Turn privs back off. */
if|if
condition|(
name|xpid
operator|>
operator|-
literal|1
condition|)
name|printf
argument_list|(
literal|"pid = %d\n"
argument_list|,
name|xpid
argument_list|)
expr_stmt|;
comment|/* show pid */
block|}
return|return
operator|(
operator|-
literal|5
operator|)
return|;
comment|/* Code for device in use */
block|}
else|else
return|return
operator|(
operator|-
literal|3
operator|)
return|;
comment|/* Access denied */
block|}
else|else
name|lkf
operator|=
literal|1
expr_stmt|;
block|}
comment|/* Got the line, now set the desired value for local. */
if|if
condition|(
operator|*
name|lcl
operator|!=
literal|0
condition|)
operator|*
name|lcl
operator|=
name|xlocal
expr_stmt|;
comment|/* Some special stuff for v7... */
ifdef|#
directive|ifdef
name|V7
ifndef|#
directive|ifndef
name|MINIX
if|if
condition|(
name|kmem
index|[
name|TTY
index|]
operator|<
literal|0
condition|)
block|{
comment|/*  If open, then skip this.  */
name|qaddr
index|[
name|TTY
index|]
operator|=
name|initrawq
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Init the queue. */
if|if
condition|(
operator|(
name|kmem
index|[
name|TTY
index|]
operator|=
name|open
argument_list|(
literal|"/dev/kmem"
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't read /dev/kmem in ttopen.\n"
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|"/dev/kmem"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* !MINIX */
endif|#
directive|endif
comment|/* V7 */
comment|/* No failure returns after this point */
ifdef|#
directive|ifdef
name|ultrix
ifdef|#
directive|ifdef
name|TIOCSINUSE
if|if
condition|(
name|xlocal
operator|&&
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSINUSE
argument_list|,
name|NULL
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't set in-use flag on modem.\n"
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|"TIOCSINUSE"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* TIOCSINUSE */
endif|#
directive|endif
comment|/* ultrix */
comment|/* Get tty device settings */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
comment|/* POSIX */
name|tcgetattr
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttold
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen tcgetattr ttold.c_lflag"
argument_list|,
literal|""
argument_list|,
name|ttold
operator|.
name|c_lflag
argument_list|)
expr_stmt|;
name|tcgetattr
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
name|tcgetattr
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|tttvt
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* BSD, V7, and all others */
ifdef|#
directive|ifdef
name|ATTSV
comment|/* AT&T UNIX */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ttold
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen ioctl TCGETA ttold.c_lflag"
argument_list|,
literal|""
argument_list|,
name|ttold
operator|.
name|c_lflag
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|tttvt
argument_list|)
expr_stmt|;
else|#
directive|else
name|gtty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttold
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen gtty ttold.sg_flags"
argument_list|,
literal|""
argument_list|,
name|ttold
operator|.
name|sg_flags
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|sony_news
comment|/* Sony NEWS */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCKGET
argument_list|,
operator|&
name|km_ext
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Get console Kanji mode */
name|perror
argument_list|(
literal|"ttopen error getting Kanji mode"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen error getting Kanji mode"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|km_ext
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Make sure this stays undefined. */
block|}
endif|#
directive|endif
comment|/* sony_news */
ifdef|#
directive|ifdef
name|TIOCGETC
name|tcharf
operator|=
literal|0
expr_stmt|;
comment|/* In remote mode, also get */
if|if
condition|(
name|xlocal
operator|==
literal|0
condition|)
block|{
comment|/* special characters */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCGETC
argument_list|,
operator|&
name|tchold
argument_list|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen TIOCGETC failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|tcharf
operator|=
literal|1
expr_stmt|;
comment|/* It worked. */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCGETC
argument_list|,
operator|&
name|tchnoi
argument_list|)
expr_stmt|;
comment|/* Get another copy */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen TIOCGETC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
else|#
directive|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen TIOCGETC not defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCGETC */
ifdef|#
directive|ifdef
name|TIOCGLTC
name|ltcharf
operator|=
literal|0
expr_stmt|;
comment|/* In remote mode, also get */
if|if
condition|(
name|xlocal
operator|==
literal|0
condition|)
block|{
comment|/* local special characters */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCGLTC
argument_list|,
operator|&
name|ltchold
argument_list|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen TIOCGLTC failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ltcharf
operator|=
literal|1
expr_stmt|;
comment|/* It worked. */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCGLTC
argument_list|,
operator|&
name|ltchnoi
argument_list|)
expr_stmt|;
comment|/* Get another copy */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen TIOCGLTC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
else|#
directive|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen TIOCGLTC not defined"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCGLTC */
ifdef|#
directive|ifdef
name|TIOCLGET
name|lmodef
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCLGET
argument_list|,
operator|&
name|lmode
argument_list|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen TIOCLGET failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|lmodef
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttopen TIOCLGET ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* TIOCLGET */
name|gtty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
comment|/* And a copy of it for packets*/
name|gtty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|tttvt
argument_list|)
expr_stmt|;
comment|/* And one for virtual tty service */
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
comment|/* Section for changing line discipline.  It's restored in ttres(). */
ifdef|#
directive|ifdef
name|BSD41
comment|/* For 4.1BSD only, force "old" tty driver, new one botches TANDEM. */
block|{
name|int
name|k
decl_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCGETD
argument_list|,
operator|&
name|ttld
argument_list|)
expr_stmt|;
comment|/* Get and save line discipline */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"4.1bsd line discipline"
argument_list|,
literal|""
argument_list|,
name|ttld
argument_list|)
expr_stmt|;
name|k
operator|=
name|OTTYDISC
expr_stmt|;
comment|/* Switch to "old" discipline */
name|k
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETD
argument_list|,
operator|&
name|k
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"4.1bsd tiocsetd"
argument_list|,
literal|""
argument_list|,
name|k
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* BSD41 */
ifdef|#
directive|ifdef
name|aegis
comment|/* This was previously done before the last two TCGETA or gtty above,      * in both the ATTSV and not-ATTSV case.  If it is not okay to have only      * one copy if it here instead, give us a shout!      */
name|sio_$control
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|sio_$raw_nl
argument_list|,
name|false
argument_list|,
name|st
argument_list|)
expr_stmt|;
if|if
condition|(
name|xlocal
condition|)
block|{
comment|/* ignore breaks from local line */
name|sio_$control
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|sio_$int_enable
argument_list|,
name|false
argument_list|,
name|st
argument_list|)
expr_stmt|;
name|sio_$control
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|sio_$quit_enable
argument_list|,
name|false
argument_list|,
name|st
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* aegis */
ifdef|#
directive|ifdef
name|VXVE
name|ttraw
operator|.
name|c_line
operator|=
literal|0
expr_stmt|;
comment|/* STTY line 0 for VX/VE */
name|tttvt
operator|.
name|c_line
operator|=
literal|0
expr_stmt|;
comment|/* STTY line 0 for VX/VE */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* vxve */
comment|/* If O_NDELAY was used during open(), then remove it now. */
ifdef|#
directive|ifdef
name|O_NDELAY
if|if
condition|(
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator|&
name|O_NDELAY
condition|)
block|{
ifndef|#
directive|ifndef
name|aegis
if|if
condition|(
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_SETFL
argument_list|,
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator|&
operator|~
name|O_NDELAY
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"Can't unset O_NDELAY"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* aegis */
comment|/* Some systems, notably Xenix (don't know how common this is in 	 * other systems), need special treatment to get rid of the O_NDELAY 	 * behaviour on read() with respect to carrier presence (i.e. read() 	 * returning 0 when carrier absent), even though the above fcntl() 	 * is enough to make read() wait for input when carrier is present. 	 * This magic, in turn, requires CLOCAL for working when the carrier 	 * is absent. But if xlocal == 0, presumably you already have CLOCAL 	 * or you have a carrier, otherwise you wouldn't be running this. 	 */
ifdef|#
directive|ifdef
name|ATTSV
ifdef|#
directive|ifdef
name|BSD44
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|xlocal
condition|)
block|{
name|ttraw
operator|.
name|c_cflag
operator||=
name|CLOCAL
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* BSD44 */
endif|#
directive|endif
comment|/* ATTSV */
ifndef|#
directive|ifndef
name|SCO3R2
ifndef|#
directive|ifndef
name|OXOS
comment|/* Reportedly lets uugetty grab the device in SCO UNIX 3.2 / XENIX 2.3 */
name|close
argument_list|(
name|priv_opn
argument_list|(
name|ttname
argument_list|,
name|O_RDWR
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Magic to force change. */
endif|#
directive|endif
comment|/* OXOS */
endif|#
directive|endif
comment|/* SCO3R2 */
block|}
endif|#
directive|endif
comment|/* O_NDELAY */
comment|/* Instruct the system how to treat the carrier, and set a few other tty  * parameters.  *  * This also undoes the temporary setting of CLOCAL that may have been done  * for the close(open()) above (except in Xenix).  Also throw in ~ECHO, to  * prevent the other end of the line from sitting there talking to itself,  * producing garbage when the user performs a connect.  *  * SCO Xenix unfortunately seems to ignore the actual state of CLOCAL.  * Now it thinks CLOCAL is always on. It seems the only real solution for  * Xenix is to switch between the lower and upper case device names.  *  * This section may at some future time expand into setting a complete  * collection of tty parameters, or call a function shared with ttpkt()/  * ttvt() that does so.  On the other hand, the initial parameters are not  * that important, since ttpkt() or ttvt() should always fix that before  * any communication is done.  Well, we'll see...  */
if|if
condition|(
name|xlocal
condition|)
block|{
name|curcarr
operator|=
operator|-
literal|2
expr_stmt|;
name|carrctl
argument_list|(
operator|&
name|ttraw
argument_list|,
name|ttcarr
operator|==
name|CAR_ON
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SVORPOSIX
name|ttraw
operator|.
name|c_lflag
operator|&=
operator|~
name|ECHO
expr_stmt|;
name|ttold
operator|.
name|c_lflag
operator|&=
operator|~
name|ECHO
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
else|#
directive|else
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
else|#
directive|else
comment|/* BSD, etc */
name|ttraw
operator|.
name|sg_flags
operator|&=
operator|~
name|ECHO
expr_stmt|;
name|ttold
operator|.
name|sg_flags
operator|&=
operator|~
name|ECHO
expr_stmt|;
name|stty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttraw
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SVORPOSIX */
comment|/*	ttflui();  This fails for some reason  */
block|}
comment|/* Get current speed */
name|ttspeed
operator|=
name|ttgspd
argument_list|()
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen ttspeed"
argument_list|,
literal|""
argument_list|,
name|ttspeed
argument_list|)
expr_stmt|;
comment|/* Done, make entries in debug log, restore Ctrl-C trap, and return. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttopen, ttyfd"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" lcl"
argument_list|,
literal|""
argument_list|,
operator|*
name|lcl
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|" lock file"
argument_list|,
name|flfnam
argument_list|,
name|lkf
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|occt
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  D O _ O P E N  --  Do the right kind of open() call for the tty. */
end_comment

begin_function
name|int
name|do_open
parameter_list|(
name|ttname
parameter_list|)
name|char
modifier|*
name|ttname
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|O_NDELAY
comment|/* O_NDELAY not defined */
return|return
operator|(
name|priv_opn
argument_list|(
name|ttname
argument_list|,
literal|2
argument_list|)
operator|)
return|;
else|#
directive|else
comment|/* O_NDELAY defined */
ifdef|#
directive|ifdef
name|ATT7300
comment|/*  Open comms line without waiting for carrier so initial call does not hang  because state of "modem" is likely unknown at the initial call  -jrd.  If this is needed for the getty stuff to work, and the open would not work  without O_NDELAY when getty is still on, then this special case is ok.  Otherwise, get rid of it. -ske */
return|return
operator|(
name|priv_opn
argument_list|(
name|ttname
argument_list|,
name|O_RDWR
operator||
name|O_NDELAY
argument_list|)
operator|)
return|;
else|#
directive|else
comment|/* !ATT7300 */
comment|/* Normal case. Use O_NDELAY according to SET CARRIER. See ttscarr(). */
return|return
operator|(
name|priv_opn
argument_list|(
name|ttname
argument_list|,
name|O_RDWR
operator||
operator|(
operator|(
name|ttcarr
operator|!=
name|CAR_ON
operator|)
condition|?
name|O_NDELAY
else|:
literal|0
operator|)
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* !ATT7300 */
endif|#
directive|endif
comment|/* O_NDELAY */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  T T C L O S  --  Close the TTY, releasing any lock.  */
end_comment

begin_function
name|int
name|ttclos
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* Arg req'd for signal() prototype */
name|int
name|x
init|=
literal|0
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttclos ttyfd"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Wasn't open. */
if|if
condition|(
name|ttfdflg
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* If we got ttyfd from another */
comment|/* process, don't close it. */
name|tvtflg
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
block|{
comment|/* Network connection. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttclos closing net"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|netclos
argument_list|()
expr_stmt|;
comment|/* Close it. */
name|netconn
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* NETCONN */
ifdef|#
directive|ifdef
name|FT21
if|if
condition|(
name|xlocal
condition|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCHPCL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* FT21 */
ifdef|#
directive|ifdef
name|ultrix
if|if
condition|(
name|xlocal
condition|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCNCAR
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ultrix */
if|if
condition|(
name|xlocal
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttclos about to call ttunlck"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttunlck
argument_list|()
condition|)
comment|/* Release uucp-style lock */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning, problem releasing lock\r\n"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttclos about to call ttres"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ttyfd
operator|>
literal|0
condition|)
block|{
name|int
name|xx
decl_stmt|;
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Enable timer interrupt. */
name|xx
operator|=
name|alarm
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|/* Allow 5 seconds for this. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttclos alarm"
argument_list|,
literal|""
argument_list|,
name|xx
argument_list|)
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
block|{
comment|/* Timer went off? */
name|x
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|/* What we're really trying to do */
if|if
condition|(
name|xlocal
condition|)
block|{
name|tthang
argument_list|()
expr_stmt|;
comment|/* Hang up first, then... */
name|ttres
argument_list|()
expr_stmt|;
comment|/* reset device modes. */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttclos about to call close"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Close the device. */
name|x
operator|=
literal|1
expr_stmt|;
block|}
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Turn off timer. */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"?Timed out closing device: %s\n"
argument_list|,
name|ttnmsv
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttclos timed out"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
name|ttyfd
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Invalidate the file descriptor. */
ifdef|#
directive|ifdef
name|sony_news
name|km_ext
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Invalidate device's Kanji-mode */
endif|#
directive|endif
comment|/* sony_news */
comment|/* For bidirectional lines, restore getty if it was there before. */
ifdef|#
directive|ifdef
name|ACUCNTRL
comment|/* 4.3BSD acucntrl() method. */
name|acucntrl
argument_list|(
literal|"enable"
argument_list|,
name|ttnmsv
argument_list|)
expr_stmt|;
comment|/* Enable getty on the device. */
else|#
directive|else
ifdef|#
directive|ifdef
name|ATT7300
comment|/* ATT UNIX PC (3B1, 7300) method. */
if|if
condition|(
name|attmodem
operator|&
name|DOGETY
condition|)
comment|/* Was getty(1m) running before us? */
name|ongetty
argument_list|(
name|ttnmsv
argument_list|)
expr_stmt|;
comment|/* Yes, restart getty on tty line */
name|attmodem
operator|&=
operator|~
name|DOGETY
expr_stmt|;
comment|/* No phone in use, getty restored */
endif|#
directive|endif
comment|/* ATT7300 */
endif|#
directive|endif
comment|/* System-dependent getty-restoring methods */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttclos done"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  T T H A N G  --  Hangup phone line or network connection.  */
end_comment

begin_comment
comment|/*   Returns:   0 if it does nothing.   1 if it believes that it hung up successfully.  -1 if it believes that the hangup attempt failed. */
end_comment

begin_define
define|#
directive|define
name|HUPTIME
value|500
end_define

begin_comment
comment|/* Milliseconds for hangup */
end_comment

begin_function
name|int
name|tthang
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|/* Sometimes used as return code. */
ifndef|#
directive|ifndef
name|POSIX
name|int
name|z
decl_stmt|;
comment|/* worker */
endif|#
directive|endif
comment|/* POSIX */
ifdef|#
directive|ifdef
name|SVORPOSIX
comment|/* AT&T, POSIX, HPUX declarations. */
name|int
name|spdsav
decl_stmt|;
comment|/* for saving speed */
name|int
name|spdsavi
decl_stmt|;
ifdef|#
directive|ifdef
name|HPUX
name|mflag
name|dtr_down
init|=
literal|00000000000
decl_stmt|,
name|modem_rtn
decl_stmt|;
name|mflag
name|modem_sav
decl_stmt|;
name|char
name|modem_state
index|[
literal|64
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* HPUX */
name|int
name|flags
decl_stmt|;
comment|/* fcntl flags */
name|unsigned
name|short
name|ttc_save
decl_stmt|;
endif|#
directive|endif
comment|/* SVORPOSIX */
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Don't do this if not open  */
if|if
condition|(
name|xlocal
operator|<
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Don't do this if not local */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
comment|/* Network connection. */
return|return
operator|(
operator|(
name|netclos
argument_list|()
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
return|;
comment|/* Just close it. */
endif|#
directive|endif
comment|/* NETCONN */
comment|/* From here down, we handle real tty devices. */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
comment|/* Should add some error checking here... */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang POSIX style"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|spdsav
operator|=
name|cfgetospeed
argument_list|(
operator|&
name|ttcur
argument_list|)
expr_stmt|;
comment|/* Get current speed */
name|spdsavi
operator|=
name|cfgetispeed
argument_list|(
operator|&
name|ttcur
argument_list|)
expr_stmt|;
comment|/* Get current speed */
name|cfsetospeed
argument_list|(
operator|&
name|ttcur
argument_list|,
name|B0
argument_list|)
expr_stmt|;
comment|/* Replace by 0 */
name|cfsetispeed
argument_list|(
operator|&
name|ttcur
argument_list|,
name|B0
argument_list|)
expr_stmt|;
if|if
condition|(
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang tcsetattr fails"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|msleep
argument_list|(
name|HUPTIME
argument_list|)
expr_stmt|;
comment|/* Sleep */
name|cfsetospeed
argument_list|(
operator|&
name|ttcur
argument_list|,
name|spdsav
argument_list|)
expr_stmt|;
comment|/* Restore previous speed */
name|cfsetispeed
argument_list|(
operator|&
name|ttcur
argument_list|,
name|spdsavi
argument_list|)
expr_stmt|;
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ttcur
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
else|#
directive|else
comment|/* BSD44ORPOSIX */
ifdef|#
directive|ifdef
name|aegis
comment|/* Apollo Aegis */
name|sio_$control
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|sio_$dtr
argument_list|,
name|false
argument_list|,
name|st
argument_list|)
expr_stmt|;
comment|/* DTR down */
name|msleep
argument_list|(
name|HUPTIME
argument_list|)
expr_stmt|;
comment|/* pause */
name|sio_$control
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|sio_$dtr
argument_list|,
name|true
argument_list|,
name|st
argument_list|)
expr_stmt|;
comment|/* DTR up */
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* aegis */
ifdef|#
directive|ifdef
name|ANYBSD
comment|/* Any BSD version. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang BSD style"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCCDTR
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Clear DTR. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang TIOCCDTR fails"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|msleep
argument_list|(
name|HUPTIME
argument_list|)
expr_stmt|;
comment|/* For about 1/2 sec */
name|errno
operator|=
literal|0
expr_stmt|;
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSDTR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Restore DTR */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
comment|/* 	  For some reason, this tends to fail with "no such device or address" 	  but the operation still works, probably because of the close/open 	  later on.  So let's not scare the user unnecessarily here. 	*/
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang TIOCSDTR errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|/* Log the error */
name|x
operator|=
literal|1
expr_stmt|;
comment|/* Pretend we succeeded */
block|}
elseif|else
if|if
condition|(
name|x
operator|==
literal|0
condition|)
name|x
operator|=
literal|1
expr_stmt|;
comment|/* Success */
ifdef|#
directive|ifdef
name|COMMENT
ifdef|#
directive|ifdef
name|FT21
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSAVEMODES
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCHPCL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Yes, must do this twice */
if|if
condition|(
operator|(
name|ttyfd
operator|=
name|open
argument_list|(
name|ttnmsv
argument_list|,
literal|2
argument_list|)
operator|)
operator|<
literal|0
condition|)
comment|/* on Fortune computers... */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* (but why?) */
else|else
name|x
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* FT21 */
endif|#
directive|endif
comment|/* COMMENT */
name|close
argument_list|(
name|do_open
argument_list|(
name|ttnmsv
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Clear i/o error condition */
name|errno
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
comment|/* This is definitely dangerous.  Why was it here? */
name|z
operator|=
name|ttvt
argument_list|(
name|ttspeed
argument_list|,
name|ttflow
argument_list|)
expr_stmt|;
comment|/* Restore modes. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang ttvt returns"
argument_list|,
literal|""
argument_list|,
name|z
argument_list|)
expr_stmt|;
return|return
operator|(
name|z
operator|<
literal|0
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|x
operator|)
return|;
endif|#
directive|endif
comment|/* COMMENT */
endif|#
directive|endif
comment|/* ANYBSD */
ifdef|#
directive|ifdef
name|ATTSV
comment|/* AT&T UNIX section, includes HP-UX and generic AT&T System III/V... */
ifdef|#
directive|ifdef
name|HPUX
comment|/* Hewlett Packard allows explicit manipulation of modem signals. */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* Old way... */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang HP-UX style"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|MCSETAF
argument_list|,
operator|&
name|dtr_down
argument_list|)
operator|<
literal|0
condition|)
comment|/* lower DTR */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* oops, can't. */
name|msleep
argument_list|(
name|HUPTIME
argument_list|)
expr_stmt|;
comment|/* Pause half a second. */
name|x
operator|=
literal|1
expr_stmt|;
comment|/* Set return code */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|MCGETA
argument_list|,
operator|&
name|modem_rtn
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Get line status. */
if|if
condition|(
operator|(
name|modem_rtn
operator|&
name|MDCD
operator|)
operator|!=
literal|0
condition|)
comment|/* Check if CD is low. */
name|x
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* CD didn't drop, fail. */
block|}
else|else
name|x
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Even if above calls fail, RTS& DTR should be turned back on. */
name|modem_rtn
operator|=
name|MRTS
operator||
name|MDTR
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|MCSETAF
argument_list|,
operator|&
name|modem_rtn
argument_list|)
operator|<
literal|0
condition|)
name|x
operator|=
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
else|#
directive|else
comment|/* New way, from Hellmuth Michaelis */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang HP-UX style, HPUXDEBUG"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|MCGETA
argument_list|,
operator|&
name|modem_rtn
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Get current status. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang HP-UX: can't get modem lines, NO HANGUP!"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|sprintf
argument_list|(
name|modem_state
argument_list|,
literal|"%#lx"
argument_list|,
name|modem_rtn
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"tthang HP-UX: modem lines got = "
argument_list|,
name|modem_state
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|modem_sav
operator|=
name|modem_rtn
expr_stmt|;
comment|/* save line status */
name|modem_rtn
operator|&=
operator|~
name|MDTR
expr_stmt|;
comment|/* DTR bit down */
name|sprintf
argument_list|(
name|modem_state
argument_list|,
literal|"%#lx"
argument_list|,
name|modem_rtn
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"tthang HP-UX: modem lines lowered DTR = "
argument_list|,
name|modem_state
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|MCSETAF
argument_list|,
operator|&
name|modem_rtn
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* lower DTR */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang HP-UX: can't lower DTR!"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* oops, can't. */
block|}
name|msleep
argument_list|(
name|HUPTIME
argument_list|)
expr_stmt|;
comment|/* Pause half a second. */
name|x
operator|=
literal|1
expr_stmt|;
comment|/* Set return code */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|MCGETA
argument_list|,
operator|&
name|modem_rtn
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Get line status. */
name|sprintf
argument_list|(
name|modem_state
argument_list|,
literal|"%#lx"
argument_list|,
name|modem_rtn
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"tthang HP-UX: modem lines got = "
argument_list|,
name|modem_state
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|modem_rtn
operator|&
name|MDCD
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* Check if CD is low. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang HP-UX: DCD didn't get down!"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|x
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* CD didn't drop, fail. */
block|}
else|else
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang HP-UX: DCD down!"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|x
operator|=
operator|-
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang HP-UX: can't get DCD status !"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* Even if above calls fail, RTS& DTR should be turned back on. */
name|modem_sav
operator||=
operator|(
name|MRTS
operator||
name|MDTR
operator|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|MCSETAF
argument_list|,
operator|&
name|modem_sav
argument_list|)
operator|<
literal|0
condition|)
block|{
name|x
operator|=
operator|-
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang HP-UX: can't set saved state |=(RTS | DTR)"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sprintf
argument_list|(
name|modem_state
argument_list|,
literal|"%#lx"
argument_list|,
name|modem_sav
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"tthang HP-UX: final modem lines = "
argument_list|,
name|modem_state
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|x
operator|)
return|;
endif|#
directive|endif
comment|/* COMMENT */
else|#
directive|else
comment|/* AT&T but not HP-UX */
comment|/* SVID for AT&T System V R3 defines ioctl's for handling modem signals. */
comment|/* It is not known how many, if any, systems actually implement them, */
comment|/* so we include them here in ifdef's. */
ifndef|#
directive|ifndef
name|_IBMR2
comment|/*   No modem-signal twiddling for IBM RT PC or RS/6000.   In AIX 3.1 and earlier, the ioctl() call is broken.   This code could be activated for AIX 3.1 with PTF 2006 or later   (e.g. AIX 3.2), but close/open does the job too, so why bother. */
ifdef|#
directive|ifdef
name|TIOCMBIS
comment|/* Bit Set */
ifdef|#
directive|ifdef
name|TIOCMBIC
comment|/* Bit Clear */
ifdef|#
directive|ifdef
name|TIOCM_DTR
comment|/* DTR */
comment|/* Clear DTR, sleep 300 msec, turn it back on. */
comment|/* If any of the ioctl's return failure, go on to the next section. */
name|z
operator|=
name|TIOCM_DTR
expr_stmt|;
comment|/* Code for DTR. */
ifdef|#
directive|ifdef
name|TIOCM_RTS
comment|/* Lower RTS too if symbol is known. */
name|z
operator||=
name|TIOCM_RTS
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCM_RTS */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang TIOCM signal mask"
argument_list|,
literal|""
argument_list|,
name|z
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCMBIC
argument_list|,
operator|&
name|z
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Try to lower DTR. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang TIOCMBIC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|msleep
argument_list|(
name|HUPTIME
argument_list|)
expr_stmt|;
comment|/* Pause half a second. */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCMBIS
argument_list|,
operator|&
name|z
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Try to turn it back on. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang TIOCMBIS ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|CLSOPN
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Success, done. */
endif|#
directive|endif
comment|/* CLSOPN */
block|}
else|else
block|{
comment|/* Couldn't raise, continue. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang TIOCMBIS errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Couldn't lower, continue. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang TIOCMBIC errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* TIOCM_DTR */
endif|#
directive|endif
comment|/* TIOCMBIC */
endif|#
directive|endif
comment|/* TIOCMBIS */
endif|#
directive|endif
comment|/* _IBMR2 */
comment|/*   General AT&T UNIX case, not HPUX.  The following code is highly suspect.  No   two AT&T-based systems seem to do this the same way.  The object is simply   to turn off DTR and then turn it back on.  SVID says the universal method   for turning off DTR is to set the speed to zero, and this does seem to do   the trick in all cases.  But neither SVID nor any known man pages say how to   turn DTR back on again.  Some variants, like most Xenix implementations,   raise DTR again when the speed is restored to a nonzero value.  Others   require the device to be closed and opened again, but this is risky because   getty could seize the device during the instant it is closed. */
comment|/* Return code for ioctl failures... */
ifdef|#
directive|ifdef
name|ATT6300
name|x
operator|=
literal|1
expr_stmt|;
comment|/* ATT6300 doesn't want to fail... */
else|#
directive|else
name|x
operator|=
operator|-
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* ATT6300 */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang get settings"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
comment|/* Get current settings. */
return|return
operator|(
name|x
operator|)
return|;
comment|/* Fail if this doesn't work. */
if|if
condition|(
operator|(
name|flags
operator|=
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
comment|/* Get device flags. */
return|return
operator|(
name|x
operator|)
return|;
name|ttc_save
operator|=
name|ttcur
operator|.
name|c_cflag
expr_stmt|;
comment|/* Remember current speed. */
name|spdsav
operator|=
name|ttc_save
operator|&
name|CBAUD
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang speed"
argument_list|,
literal|""
argument_list|,
name|spdsav
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|O_NDELAY
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang turning O_NDELAY on"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_SETFL
argument_list|,
name|flags
operator||
name|O_NDELAY
argument_list|)
expr_stmt|;
comment|/* Activate O_NDELAY */
endif|#
directive|endif
comment|/* O_NDELAY */
ifdef|#
directive|ifdef
name|ATT7300
comment|/* This is the way it is SUPPOSED to work */
name|ttcur
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
comment|/* Change the speed to zero.  */
else|#
directive|else
ifdef|#
directive|ifdef
name|RTAIX
name|ttcur
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
comment|/* Change the speed to zero.  */
else|#
directive|else
comment|/* This way really works but may be dangerous */
ifdef|#
directive|ifdef
name|u3b2
name|ttcur
operator|.
name|c_cflag
operator|=
operator|~
operator|(
name|CBAUD
operator||
name|CLOCAL
operator|)
expr_stmt|;
comment|/* Special for AT&T 3B2s */
comment|/* (CLOCAL must be OFF) */
else|#
directive|else
ifdef|#
directive|ifdef
name|SCO3R2
comment|/* SCO UNIX 3.2 */
comment|/*   This is complete nonsense, but an SCO user claimed this change made   hanging up work.  Comments from other SCO UNIX 3.2 users would be    appreciated. */
name|ttcur
operator|.
name|c_cflag
operator|=
name|CBAUD
operator||
name|B0
expr_stmt|;
else|#
directive|else
comment|/* None of the above. */
name|ttcur
operator|.
name|c_cflag
operator|=
name|CLOCAL
operator||
name|HUPCL
expr_stmt|;
comment|/* Change all but these to zero */
comment|/* (CLOCAL must be ON) */
endif|#
directive|endif
comment|/* SCO3R2 */
endif|#
directive|endif
comment|/* u3b2 */
endif|#
directive|endif
comment|/* RTAIX */
endif|#
directive|endif
comment|/* ATT7300 */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* and if none of those work, try one of these... */
name|ttcur
operator|.
name|c_cflag
operator|=
literal|0
expr_stmt|;
name|ttcur
operator|.
name|c_cflag
operator|=
name|CLOCAL
expr_stmt|;
name|ttcur
operator|.
name|c_cflag
operator|&=
operator|~
operator|(
name|CBAUD
operator||
name|HUPCL
operator|)
expr_stmt|;
name|ttcur
operator|.
name|c_cflag
operator|&=
operator|~
operator|(
name|CBAUD
operator||
name|CREAD
operator|)
expr_stmt|;
name|ttcur
operator|.
name|c_cflag
operator|&=
operator|~
operator|(
name|CBAUD
operator||
name|CREAD
operator||
name|HUPCL
operator|)
expr_stmt|;
comment|/* or other combinations */
endif|#
directive|endif
comment|/* COMMENT */
ifdef|#
directive|ifdef
name|TCXONC
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang TCXONC"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCXONC
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TCXONC */
ifdef|#
directive|ifdef
name|TIOCSTART
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang TIOCSTART"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSTART
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCSTART */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAF
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Fail if we can't. */
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_SETFL
argument_list|,
name|flags
argument_list|)
expr_stmt|;
comment|/* Restore flags */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* before returning. */
block|}
name|msleep
argument_list|(
literal|300
argument_list|)
expr_stmt|;
comment|/* Give modem time to notice. */
comment|/* Now, even though it doesn't say this in SVID or any man page, we have */
comment|/* to close and reopen the device.  This is not necessary for all systems, */
comment|/* but it's impossible to predict which ones need it and which ones don't. */
ifdef|#
directive|ifdef
name|ATT7300
comment|/*   Special handling for ATT 7300 UNIX PC and 3B1, which have "phone"   related ioctl's for their internal modems.  attmodem has getty status and    modem-in-use bit.  Reportedly the ATT7300/3B1 PIOCDISC call is necessary,    but also ruins the file descriptor, and no other phone(7) ioctl call can fix    it.  Whateverit does, it seems to escape detection with PIOCGETA and TCGETA.   The only way to undo the damage is to close the fd and then reopen it. */
if|if
condition|(
name|attmodem
operator|&
name|ISMODEM
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang attmodem close/open"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCUNHOLD
argument_list|,
operator|&
name|dialer
argument_list|)
expr_stmt|;
comment|/* Return call to handset. */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCDISC
argument_list|,
operator|&
name|dialer
argument_list|)
expr_stmt|;
comment|/* Disconnect phone. */
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Close and reopen the fd. */
name|ttyfd
operator|=
name|priv_opn
argument_list|(
name|ttnmsv
argument_list|,
name|O_RDWR
operator||
name|O_NDELAY
argument_list|)
expr_stmt|;
name|attmodem
operator|&=
operator|~
name|ISMODEM
expr_stmt|;
comment|/* Phone no longer in use. */
block|}
else|#
directive|else
comment|/* !ATT7300 */
comment|/* It seems we have to close and open the device for other AT&T systems */
comment|/* too, and this is the place to do it.  The following code does the */
comment|/* famous close(open(...)) magic by default.  If that doesn't work for you, */
comment|/* then try uncommenting the following statement or putting -DCLSOPN in */
comment|/* the makefile CFLAGS. */
comment|/* #define CLSOPN */
ifndef|#
directive|ifndef
name|SCO32
comment|/* Not needed by, and harmful to, SCO UNIX 3.2 / Xenix 2.3 */
ifdef|#
directive|ifdef
name|O_NDELAY
define|#
directive|define
name|OPENFLGS
value|O_RDWR | O_NDELAY
else|#
directive|else
define|#
directive|define
name|OPENFLGS
value|O_RDWR
endif|#
directive|endif
ifndef|#
directive|ifndef
name|CLSOPN
comment|/* This method is used by default, i.e. unless CLSOPN is defined. */
comment|/* It is thought to be safer because there is no window where getty */
comment|/* can seize control of the device.  The drawback is that it might not work. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang close(open()), OPENFLGS"
argument_list|,
literal|""
argument_list|,
name|OPENFLGS
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|priv_opn
argument_list|(
name|ttnmsv
argument_list|,
name|OPENFLGS
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* This method is used if you #define CLSOPN.  It is more likely to work */
comment|/* than the previous method, but it's also more dangerous. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tthang close/open, OPENFLGS"
argument_list|,
literal|""
argument_list|,
name|OPENFLGS
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
name|msleep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|ttyfd
operator|=
name|priv_opn
argument_list|(
name|ttnmsv
argument_list|,
name|OPENFLGS
argument_list|)
expr_stmt|;
comment|/* Open it again */
endif|#
directive|endif
comment|/* CLSOPN */
undef|#
directive|undef
name|OPENFLGS
endif|#
directive|endif
comment|/* SCO32 */
endif|#
directive|endif
comment|/* ATT7300 */
comment|/* Now put all flags& modes back the way we found them. */
comment|/* (Does the order of ioctl& fcntl matter ? ) */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthang restore settings"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttcur
operator|.
name|c_cflag
operator|=
name|ttc_save
expr_stmt|;
comment|/* Get old speed back. */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAF
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
comment|/* ioctl parameters. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
ifdef|#
directive|ifdef
name|O_NDELAY
comment|/*   This is required for IBM RT and RS/6000, probably helps elsewhere too (?).   After closing a modem line, the modem will probably not be asserting   carrier any more, so we should not require carrier any more.  If this   causes trouble on non-IBM UNIXes, change the #ifdef to use _IBMR2 rather   than O_NDELAY. */
name|flags
operator|&=
operator|~
name|O_NDELAY
expr_stmt|;
comment|/* Don't require carrier on reopen */
endif|#
directive|endif
comment|/* O_NDELAY */
if|if
condition|(
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_SETFL
argument_list|,
name|flags
argument_list|)
operator|<
literal|0
condition|)
comment|/* fcntl parameters */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* not HPUX */
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
block|}
end_function

begin_comment
comment|/*   Major change in 5A(174).  We used to use LPASS8, if it was defined, to   allow 8-bit data and Xon/Xoff flow control at the same time.  But this   LPASS8 business seems to have been causing trouble for everybody but me!   For example, Annex terminal servers, commonly used with Encore computers,   do not support LPASS8 even though the Encore itself does.  Ditto for many   other terminal servers, TELNET connections, rlogin connections, etc etc.   Now, reportedly, even vanilla 4.3 BSD systems can't do this right on their   serial lines, even though LPASS8 is a feature of 4.3BSD.  So let's turn it   off for everybody.  That means we goes back to using raw mode, with no   flow control.  Phooey.    NOTE: This must be done before the first reference to LPASS8 in this file,   and after the last #include statment. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LPASS8
end_ifdef

begin_undef
undef|#
directive|undef
name|LPASS8
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LPASS8 */
end_comment

begin_comment
comment|/*  T T R E S  --  Restore terminal to "normal" mode.  */
end_comment

begin_comment
comment|/* ske@pkmab.se: There are two choices for what this function should do.  * (1) Restore the tty to current "normal" mode, with carrier treatment  * according to ttcarr, to be used after every kermit command. (2) Restore  * the tty to the state it was in before kermit opened it. These choices  * conflict, since ttold can't hold both choices of tty parameters.  ttres()  * is currently being called as in choice (1), but ttold basically holds  * the initial parameters, as in (2), and the description at the beginning  * of this file says (2).  *  * I don't think restoring tty parameters after all kermit commands makes  * much of a difference.  Restoring them upon exit from kermit may be of  * some use in some cases (when the line is not restored automatically on  * close, by the operating system).  *  * I can't choose which one it should be, so I haven't changed it. It  * probably works as it is, too. It would probably even work even with  * ttres() entirely deleted...  *  * (from fdc: Actually, this function operates in remote mode too, so  * it restores the console (command) terminal to whatever mode it was  * in before packet operations began, so that commands work right again.)  */
end_comment

begin_function
name|int
name|ttres
parameter_list|()
block|{
comment|/* Restore the tty to normal. */
name|int
name|x
decl_stmt|;
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Not open. */
if|if
condition|(
name|ttfdflg
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Don't mess with terminal modes if */
comment|/* we got ttyfd from another process */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Network connection, do nothing */
endif|#
directive|endif
comment|/* NETCONN */
comment|/* Real terminal device, so restore its original modes */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
comment|/* For POSIX like this */
name|x
operator|=
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ttold
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* For all others... */
ifdef|#
directive|ifdef
name|ATTSV
comment|/* For AT&T versions... */
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|ttold
argument_list|)
expr_stmt|;
comment|/* Restore tty modes this way. */
else|#
directive|else
name|msleep
argument_list|(
name|HUPTIME
argument_list|)
expr_stmt|;
comment|/* This replaces sleep(1)... */
comment|/* Put back sleep(1) if tty is */
comment|/* messed up after close. */
comment|/* Here we restore the modes for BSD */
ifdef|#
directive|ifdef
name|LPASS8
comment|/* Undo "pass8" if it were done */
if|if
condition|(
name|lmodef
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCLSET
argument_list|,
operator|&
name|lmode
argument_list|)
operator|<
literal|0
condition|)
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres TIOCLSET failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres TIOCLSET ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* LPASS8 */
ifdef|#
directive|ifdef
name|CK_DTRCTS
comment|/* Undo hardware flow if it were done */
if|if
condition|(
name|lmodef
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCLSET
argument_list|,
operator|&
name|lmode
argument_list|)
operator|<
literal|0
condition|)
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres TIOCLSET failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres TIOCLSET ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* CK_DTRCTS */
ifdef|#
directive|ifdef
name|TIOCGETC
comment|/* Put back special characters */
if|if
condition|(
name|tcharf
operator|&&
operator|(
name|xlocal
operator|==
literal|0
operator|)
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|tchold
argument_list|)
operator|<
literal|0
condition|)
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres TIOCSETC failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres TIOCSETC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* TIOCGETC */
ifdef|#
directive|ifdef
name|TIOCGLTC
comment|/* Put back local special characters */
if|if
condition|(
name|ltcharf
operator|&&
operator|(
name|xlocal
operator|==
literal|0
operator|)
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSLTC
argument_list|,
operator|&
name|ltchold
argument_list|)
operator|<
literal|0
condition|)
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres TIOCSLTC failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres TIOCSLTC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* TIOCGLTC */
name|x
operator|=
name|stty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttold
argument_list|)
expr_stmt|;
comment|/* restore tty modes the old way. */
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttres tty modes restore"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttres errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD41
if|if
condition|(
name|ttld
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Put back line discipline */
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETD
argument_list|,
operator|&
name|ttld
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttres line discipline restore"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|debug
argument_list|(
name|F101
argument_list|,
literal|"...ioctl errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|ttld
operator|=
operator|-
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* BSD41 */
ifdef|#
directive|ifdef
name|sony_news
name|x
operator|=
name|xlocal
condition|?
name|km_ext
else|:
name|km_con
expr_stmt|;
comment|/* Restore Kanji mode. */
if|if
condition|(
name|x
operator|!=
operator|-
literal|1
condition|)
block|{
comment|/* Make sure we know original modes. */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCKSET
argument_list|,
operator|&
name|x
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"ttres can't set Kanji mode"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttres error setting Kanji mode"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttres set Kanji mode ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sony_news */
name|tvtflg
operator|=
literal|0
expr_stmt|;
comment|/* Invalidate terminal mode settings */
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  T T R P I D  --  Read pid from lockfile "name" (used by ttlock) */
end_comment

begin_function
name|int
name|ttrpid
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|int
name|x
decl_stmt|,
name|fd
decl_stmt|,
name|pid
decl_stmt|;
name|fd
operator|=
name|open
argument_list|(
name|name
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
comment|/* Try to open lockfile. */
if|if
condition|(
name|fd
operator|>
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|PIDSTRING
name|char
name|buf
index|[
literal|12
index|]
decl_stmt|;
name|x
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|/* For HDP UUCP, read pid string */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|buf
index|[
literal|11
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|11
condition|)
name|x
operator|=
name|sscanf
argument_list|(
name|buf
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|pid
argument_list|)
expr_stmt|;
comment|/* Get the integer pid from it. */
else|#
directive|else
name|x
operator|=
name|read
argument_list|(
name|fd
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|pid
argument_list|,
sizeof|sizeof
argument_list|(
name|pid
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Else read integer pid */
endif|#
directive|endif
comment|/* PIDSTRING */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|pid
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Return any errors. */
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
comment|/* Close the lockfile. */
block|}
else|else
name|pid
operator|=
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|pid
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  T T L O C K  */
end_comment

begin_comment
comment|/*   This function attempts to coordinate use of the communication device with   other copies of Kermit and any other program that follows the UUCP   device-locking conventions, which, unfortunately, vary among different UNIX   implementations.  The idea is to look for a file of a certain name, the   "lockfile", in a certain directory.  If such a file is found, then the line   is presumed to be in use, and Kermit should not use it.  If no such file is   found, Kermit attempts to create one so that other programs will not use the   same line at the same time.  Because the lockfile and/or the directory it's   in might lack write permission for the person running Kermit, Kermit could   find itself running setuid to uucp or other user that does have the   necessary permissions.  At startup, Kermit has changed its effective uid to   the user's real uid, and so ttlock() must switch back to the original   effective uid in order to create the lockfile, and then back again to the   real uid to prevent unauthorized access to other directories or files owned   by the user the program is setuid to.    Totally rewritten for C-Kermit 5A to eliminate windows of vulnerability,   based on suggestions from Warren Tucker.  Call with pointer to name of    tty device.  Returns:     0 on success   -1 on failure    Note: Once privileges are turned on using priv_on(), it is essential that   they are turned off again before this function returns. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_comment
comment|/* Lockfile uses device numbers. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LFDEVNO
end_ifndef

begin_comment
comment|/* Define this for SVR4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AIXRS
end_ifndef

begin_comment
comment|/* But not for RS/6000 AIX 3.2 */
end_comment

begin_define
define|#
directive|define
name|LFDEVNO
end_define

begin_comment
comment|/* If anybody else needs it, */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXRS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LFDEVNO */
end_comment

begin_comment
comment|/* define it here or on CC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_comment
comment|/* command line. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LFDEVNO
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* For major()& minor() macros. */
end_comment

begin_comment
comment|/* Should be in<sys/types.h>. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|major
end_ifndef

begin_comment
comment|/* If we didn't find it */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_comment
comment|/* then for Sys V R4 */
end_comment

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_comment
comment|/* look here */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* or for Sunos versions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4
end_ifdef

begin_comment
comment|/* ... */
end_comment

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_comment
comment|/* look here */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Otherwise take a chance: */
end_comment

begin_define
define|#
directive|define
name|major
parameter_list|(
name|dev
parameter_list|)
value|( (int) ( ((unsigned)(dev)>> 8)& 0xff))
end_define

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|dev
parameter_list|)
value|( (int) ( (dev)& 0xff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* major */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LFDEVNO */
end_comment

begin_comment
comment|/*   Note for RS/6000: routines ttylock(devicename), ttyunlock(devicename),   and ttylocked(devicename) from the standard library (libc.a) could be    used here instead.  It's not clear whether there is any advantage in this. */
end_comment

begin_function
specifier|static
name|int
name|ttlock
parameter_list|(
name|ttdev
parameter_list|)
name|char
modifier|*
name|ttdev
decl_stmt|;
block|{
name|int
name|x
decl_stmt|;
ifdef|#
directive|ifdef
name|MINIX
name|char
modifier|*
name|buf
decl_stmt|;
endif|#
directive|endif
comment|/* MINIX */
ifdef|#
directive|ifdef
name|NOUUCP
name|strcpy
argument_list|(
name|flfnam
argument_list|,
literal|"NOLOCK"
argument_list|)
expr_stmt|;
name|haslock
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
comment|/* !NOUUCP */
name|int
name|lockfd
decl_stmt|;
comment|/* File descriptor for lock file. */
name|PID_T
name|pid
decl_stmt|;
comment|/* Process id of this process. */
name|int
name|fpid
decl_stmt|;
comment|/* pid found in existing lockfile. */
name|int
name|tries
decl_stmt|;
comment|/* How many times we've tried... */
ifdef|#
directive|ifdef
name|LFDEVNO
name|struct
name|stat
name|devbuf
decl_stmt|;
comment|/* For device numbers (SVR4). */
endif|#
directive|endif
comment|/* LFDEVNO */
ifdef|#
directive|ifdef
name|PIDSTRING
name|char
name|pid_str
index|[
literal|12
index|]
decl_stmt|;
comment|/* My pid in string format. */
endif|#
directive|endif
comment|/* PIDSTRING */
name|char
modifier|*
name|device
decl_stmt|,
modifier|*
name|devname
decl_stmt|;
define|#
directive|define
name|LFNAML
value|50
comment|/* Max length for lock file name. */
name|char
name|lockfil
index|[
name|LFNAML
index|]
decl_stmt|;
comment|/* Lock file name */
ifdef|#
directive|ifdef
name|RTAIX
name|char
name|lklockf
index|[
name|LFNAML
index|]
decl_stmt|;
comment|/* Name for link to lock file  */
endif|#
directive|endif
comment|/* RTAIX */
name|char
name|tmpnam
index|[
name|LFNAML
operator|+
literal|30
index|]
decl_stmt|;
comment|/* Temporary lockfile name. */
name|char
modifier|*
name|lockdir
init|=
name|LOCK_DIR
decl_stmt|;
comment|/* Defined near top of this file, */
comment|/* or on cc command line. */
name|haslock
operator|=
literal|0
expr_stmt|;
comment|/* Not locked yet. */
operator|*
name|flfnam
operator|=
literal|'\0'
expr_stmt|;
comment|/* Lockfile name is empty. */
name|pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
comment|/* Get id of this process. */
comment|/*  Construct name of lockfile and temporary file */
comment|/*  device  = name of tty device without the path, e.g. "ttyh8" */
comment|/*  lockfil = name of lock file, without path, e.g. "LCK..ttyh8" */
name|device
operator|=
operator|(
operator|(
name|devname
operator|=
name|xxlast
argument_list|(
name|ttdev
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|!=
name|NULL
condition|?
name|devname
operator|+
literal|1
else|:
name|ttdev
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ISIII
comment|/* Interactive System III, PC/IX */
name|strcpy
argument_list|(
name|lockfil
argument_list|,
name|device
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|LFDEVNO
comment|/* Lockfilename has device numbers. */
if|if
condition|(
name|stat
argument_list|(
name|ttdev
argument_list|,
operator|&
name|devbuf
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|sprintf
argument_list|(
name|lockfil
argument_list|,
literal|"LK.%03d.%03d.%03d"
argument_list|,
name|major
argument_list|(
name|devbuf
operator|.
name|st_dev
argument_list|)
argument_list|,
comment|/* inode */
name|major
argument_list|(
name|devbuf
operator|.
name|st_rdev
argument_list|)
argument_list|,
comment|/* major device number */
name|minor
argument_list|(
name|devbuf
operator|.
name|st_rdev
argument_list|)
argument_list|)
expr_stmt|;
comment|/* minor device number */
else|#
directive|else
comment|/* Others... */
ifdef|#
directive|ifdef
name|PTX
comment|/* Dynix PTX */
if|if
condition|(
name|device
operator|!=
operator|&
name|ttdev
index|[
literal|5
index|]
operator|&&
name|strncmp
argument_list|(
name|ttdev
argument_list|,
literal|"/dev/"
argument_list|,
literal|5
argument_list|)
operator|==
literal|0
condition|)
block|{
name|sprintf
argument_list|(
name|lockfil
argument_list|,
literal|"LCK..%.3s%s"
argument_list|,
operator|&
name|ttdev
index|[
literal|5
index|]
argument_list|,
name|device
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|/* PTX */
name|sprintf
argument_list|(
name|lockfil
argument_list|,
literal|"LCK..%s"
argument_list|,
name|device
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|M_XENIX
comment|/* SCO Xenix */
block|{
name|int
name|x
decl_stmt|;
name|char
name|c
decl_stmt|;
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|lockfil
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* Get last letter of device name. */
if|if
condition|(
name|x
operator|>
literal|0
condition|)
block|{
comment|/* If it's uppercase, lower it. */
name|c
operator|=
name|lockfil
index|[
name|x
index|]
expr_stmt|;
if|if
condition|(
name|c
operator|>=
literal|'A'
operator|&&
name|c
operator|<=
literal|'Z'
condition|)
name|lockfil
index|[
name|x
index|]
operator|+=
operator|(
literal|'a'
operator|-
literal|'A'
operator|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* M_XENIX */
ifdef|#
directive|ifdef
name|RTAIX
name|strcpy
argument_list|(
name|lklockf
argument_list|,
name|device
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RTAIX */
endif|#
directive|endif
comment|/* LFDEVNO */
endif|#
directive|endif
comment|/* ISIII */
comment|/*  flfnam = full lockfile pathname, e.g. "/usr/spool/uucp/LCK..ttyh8" */
comment|/*  tmpnam = temporary unique, e.g. "/usr/spool/uucp/LTMP..pid" */
name|sprintf
argument_list|(
name|flfnam
argument_list|,
literal|"%s/%s"
argument_list|,
name|lockdir
argument_list|,
name|lockfil
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|RTAIX
name|sprintf
argument_list|(
name|lkflfn
argument_list|,
literal|"%s/%s"
argument_list|,
name|lockdir
argument_list|,
name|lklockf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RTAIX */
name|sprintf
argument_list|(
name|tmpnam
argument_list|,
literal|"%s/LTMP.%05d"
argument_list|,
name|lockdir
argument_list|,
operator|(
name|int
operator|)
name|pid
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ttlock flfnam"
argument_list|,
name|flfnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ttlock tmpnam"
argument_list|,
name|tmpnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|priv_on
argument_list|()
expr_stmt|;
comment|/* Turn on privileges if possible. */
name|lockfd
operator|=
name|creat
argument_list|(
name|tmpnam
argument_list|,
literal|0444
argument_list|)
expr_stmt|;
comment|/* Try to create temp lock file. */
if|if
condition|(
name|lockfd
operator|<
literal|0
condition|)
block|{
comment|/* Create failed. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttlock creat failed"
argument_list|,
name|tmpnam
argument_list|,
name|errno
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|==
name|ENOENT
condition|)
block|{
name|perror
argument_list|(
name|lockdir
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"UUCP not installed or Kermit misconfigured\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|perror
argument_list|(
name|lockdir
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|tmpnam
argument_list|)
expr_stmt|;
comment|/* Get rid of the temporary file. */
block|}
name|priv_off
argument_list|()
expr_stmt|;
comment|/* Turn off privileges!!! */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Return failure code. */
block|}
comment|/* Now write the pid into the temp lockfile in the appropriate format */
ifdef|#
directive|ifdef
name|PIDSTRING
comment|/* For Honey DanBer UUCP, */
name|sprintf
argument_list|(
name|pid_str
argument_list|,
literal|"%10d\n"
argument_list|,
operator|(
name|int
operator|)
name|pid
argument_list|)
expr_stmt|;
comment|/* Write pid as decimal string. */
name|write
argument_list|(
name|lockfd
argument_list|,
name|pid_str
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttlock hdb pid string"
argument_list|,
name|pid_str
argument_list|,
operator|(
name|int
operator|)
name|pid
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Others use integer pid */
name|write
argument_list|(
name|lockfd
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|pid
argument_list|,
sizeof|sizeof
argument_list|(
name|pid
argument_list|)
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttlock pid"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|pid
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PIDSTRING */
comment|/* Now try to rename the temp file to the real lock file name. */
comment|/* This will fail if a lock file of that name already exists.  */
name|close
argument_list|(
name|lockfd
argument_list|)
expr_stmt|;
comment|/* Close the temp lockfile. */
name|chmod
argument_list|(
name|tmpnam
argument_list|,
literal|0444
argument_list|)
expr_stmt|;
comment|/* Permission for a valid lock. */
name|tries
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|!
name|haslock
operator|&&
name|tries
operator|++
operator|<
literal|2
condition|)
block|{
name|haslock
operator|=
operator|(
name|link
argument_list|(
name|tmpnam
argument_list|,
name|flfnam
argument_list|)
operator|==
literal|0
operator|)
expr_stmt|;
comment|/* Create a link to it. */
if|if
condition|(
name|haslock
condition|)
block|{
comment|/* If we got the lockfile */
ifdef|#
directive|ifdef
name|RTAIX
name|link
argument_list|(
name|flfnam
argument_list|,
name|lkflfn
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RTAIX */
ifdef|#
directive|ifdef
name|LOCKF
comment|/*   Advisory file locking works on SVR4, so we use it.  In fact, it is   necessary in some cases, e.g. when SLIP is involved. */
while|while
condition|(
name|lockf
argument_list|(
name|ttyfd
argument_list|,
name|F_TLOCK
argument_list|,
literal|0L
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttlock: lockf returns errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|++
name|tries
operator|>=
literal|3
operator|)
operator|||
operator|(
name|errno
operator|!=
name|EAGAIN
operator|)
condition|)
block|{
name|x
operator|=
name|unlink
argument_list|(
name|flfnam
argument_list|)
expr_stmt|;
comment|/* remove the lockfile */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttlock unlink"
argument_list|,
name|flfnam
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|haslock
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|haslock
condition|)
comment|/* If we got an advisory lock */
endif|#
directive|endif
comment|/* LOCKF */
break|break;
comment|/* We're done. */
block|}
else|else
block|{
comment|/* We didn't create a new lockfile. */
if|if
condition|(
operator|(
name|fpid
operator|=
name|ttrpid
argument_list|(
name|flfnam
argument_list|)
operator|)
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Read pid from old one. */
if|if
condition|(
name|fpid
operator|>
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttlock fpid"
argument_list|,
literal|""
argument_list|,
name|fpid
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
comment|/* See if process still exists. */
name|x
operator|=
name|kill
argument_list|(
operator|(
name|PID_T
operator|)
name|fpid
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttlock kill"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttlock kill errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
operator|&&
name|errno
operator|==
name|ESRCH
condition|)
block|{
comment|/* pid is invalid */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttlock removing stale lock"
argument_list|,
name|flfnam
argument_list|,
name|fpid
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|backgrd
condition|)
name|printf
argument_list|(
literal|"Removing stale lock %s (pid %d terminated)\n"
argument_list|,
name|flfnam
argument_list|,
name|fpid
argument_list|)
expr_stmt|;
name|x
operator|=
name|unlink
argument_list|(
name|flfnam
argument_list|)
expr_stmt|;
comment|/* remove the lockfile. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttlock unlink"
argument_list|,
name|flfnam
argument_list|,
name|x
argument_list|)
expr_stmt|;
continue|continue;
comment|/* and go back and try again. */
block|}
elseif|else
if|if
condition|(
operator|(
name|x
operator|<
literal|0
operator|&&
name|errno
operator|==
name|EPERM
operator|)
operator|||
name|x
operator|==
literal|0
condition|)
block|{
name|unlink
argument_list|(
name|tmpnam
argument_list|)
expr_stmt|;
comment|/* Delete the tempfile */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttlock found tty locked"
argument_list|,
literal|""
argument_list|,
name|fpid
argument_list|)
expr_stmt|;
name|priv_off
argument_list|()
expr_stmt|;
comment|/* Turn off privs */
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* Code for device is in use. */
block|}
block|}
else|else
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttlock can't get fpid"
argument_list|,
literal|""
argument_list|,
name|fpid
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
else|else
break|break;
comment|/* Couldn't read pid from old file */
block|}
block|}
name|unlink
argument_list|(
name|tmpnam
argument_list|)
expr_stmt|;
comment|/* Unlink (remove) the temp file. */
name|priv_off
argument_list|()
expr_stmt|;
comment|/* Turn off privs */
return|return
operator|(
name|haslock
condition|?
literal|0
else|:
operator|-
literal|1
operator|)
return|;
comment|/* Return link's return code. */
endif|#
directive|endif
comment|/* !NOUUCP */
block|}
end_function

begin_comment
comment|/*  T T U N L O C K  */
end_comment

begin_function
specifier|static
name|int
name|ttunlck
parameter_list|()
block|{
comment|/* Remove UUCP lockfile. */
ifndef|#
directive|ifndef
name|NOUUCP
if|if
condition|(
name|haslock
operator|&&
operator|*
name|flfnam
condition|)
block|{
name|priv_on
argument_list|()
expr_stmt|;
comment|/* Turn privileges on.  */
name|unlink
argument_list|(
name|flfnam
argument_list|)
expr_stmt|;
comment|/* Remove the lockfile. */
ifdef|#
directive|ifdef
name|RTAIX
name|unlink
argument_list|(
name|lkflfn
argument_list|)
expr_stmt|;
comment|/* Remove other lockfile */
endif|#
directive|endif
comment|/* RTAIX */
ifdef|#
directive|ifdef
name|LOCKF
operator|(
name|void
operator|)
name|lockf
argument_list|(
name|ttyfd
argument_list|,
name|F_ULOCK
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
comment|/* Remove advisory lock */
endif|#
directive|endif
comment|/* LOCKF */
operator|*
name|flfnam
operator|=
literal|'\0'
expr_stmt|;
comment|/* Erase the name. */
name|priv_off
argument_list|()
expr_stmt|;
comment|/* Turn privileges off. */
block|}
endif|#
directive|endif
comment|/* !NOUUCP */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* 4.3BSD-style UUCP line direction control (Stan Barber, Rice U) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACUCNTRL
end_ifdef

begin_function
name|VOID
name|acucntrl
parameter_list|(
name|flag
parameter_list|,
name|ttname
parameter_list|)
name|char
modifier|*
name|flag
decl_stmt|,
decl|*
name|ttname
decl_stmt|;
end_function

begin_block
block|{
name|char
name|x
index|[
name|DEVNAMLEN
operator|+
literal|32
index|]
decl_stmt|,
modifier|*
name|device
decl_stmt|,
modifier|*
name|devname
decl_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|ttname
argument_list|,
name|CTTNAM
argument_list|)
operator|==
literal|0
operator|||
name|xlocal
operator|==
literal|0
condition|)
comment|/* If not local, */
return|return;
comment|/* just return. */
name|device
operator|=
operator|(
operator|(
name|devname
operator|=
name|xxlast
argument_list|(
name|ttname
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|!=
name|NULL
condition|?
name|devname
operator|+
literal|1
else|:
name|ttname
operator|)
expr_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|device
argument_list|,
literal|"LCK.."
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
condition|)
name|device
operator|+=
literal|5
expr_stmt|;
name|sprintf
argument_list|(
name|x
argument_list|,
literal|"/usr/lib/uucp/acucntrl %s %s"
argument_list|,
name|flag
argument_list|,
name|device
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"called "
argument_list|,
name|x
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|zsyscmd
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACUCNTRL */
end_comment

begin_escape
end_escape

begin_comment
comment|/*   T T H F L O W  --  Set hardware flow control. */
end_comment

begin_function
specifier|static
name|int
name|tthflow
parameter_list|(
name|flow
parameter_list|)
name|int
name|flow
decl_stmt|;
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|/* Return code */
comment|/* There is no hardware flow control in POSIX. */
comment|/*   For SunOS 4.0 and later in the BSD environment ...    The declarations are copied and interpreted from the System V header files,   so we don't actually have to pull in all the System V junk when building   C-Kermit for SunOS in the BSD environment, which would be dangerous because   having those symbols defined would cause us to take the wrong paths through   the code.  The code in this section is used in both the BSD and Sys V SunOS   versions. */
ifdef|#
directive|ifdef
name|SUNOS41
comment|/*   In SunOS 4.1 and later, we use the POSIX calls rather than ioctl calls   because GNU CC uses different formats for the _IOxxx macros than regular CC;   the POSIX forms work for both.  But the POSIX calls are not available in   SunOS 4.0. */
define|#
directive|define
name|CRTSCTS
value|0x80000000
comment|/* RTS/CTS flow control */
define|#
directive|define
name|TCSANOW
value|0
comment|/* Do it now */
struct|struct
name|termios
block|{
name|unsigned
name|long
name|c_iflag
decl_stmt|;
comment|/* Input modes */
name|unsigned
name|long
name|c_oflag
decl_stmt|;
comment|/* Output modes */
name|unsigned
name|long
name|c_cflag
decl_stmt|;
comment|/* Control modes */
name|unsigned
name|long
name|c_lflag
decl_stmt|;
comment|/* Line discipline modes */
name|char
name|c_line
decl_stmt|;
name|CHAR
name|c_cc
index|[
literal|17
index|]
decl_stmt|;
block|}
struct|;
name|struct
name|termios
name|temp
decl_stmt|;
name|_PROTOTYP
argument_list|(
argument|int tcgetattr
argument_list|,
argument|(int, struct termios *)
argument_list|)
empty_stmt|;
name|_PROTOTYP
argument_list|(
argument|int tcsetattr
argument_list|,
argument|(int, int, struct termios *)
argument_list|)
empty_stmt|;
comment|/*   When CRTSCTS is set, SunOS won't do output unless both CTS and CD are   asserted.  So we don't set CRTSCTS unless CD is up.  This should be OK,   since we don't need RTS/CTS during dialing, and after dialing is complete,   we should have CD.  If not, we still communicate, but without RTS/CTS. */
name|int
name|mflags
decl_stmt|;
comment|/* Modem signal flags */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCMGET
argument_list|,
operator|&
name|mflags
argument_list|)
operator|>
operator|-
literal|1
operator|&&
comment|/* Get modem signals */
operator|(
name|mflags
operator|&
name|TIOCM_CAR
operator|)
condition|)
block|{
comment|/* Check for CD */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthflow SunOS has CD"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|tcgetattr
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|temp
argument_list|)
operator|>
operator|-
literal|1
operator|&&
comment|/* Get device attributes */
operator|!
operator|(
name|temp
operator|.
name|c_cflag
operator|&
name|CRTSCTS
operator|)
condition|)
block|{
comment|/* Check for RTS/CTS */
name|temp
operator|.
name|c_cflag
operator||=
name|CRTSCTS
expr_stmt|;
comment|/* Not there, add it */
name|x
operator|=
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSANOW
argument_list|,
operator|&
name|temp
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"tthflow SunOS no CD"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|SUNOS4
comment|/*   SunOS 4.0 (and maybe earlier?).  This code is dangerous because it   prevents compilation with GNU gcc, which uses different formats for the   _IORxxx macros than regular cc.  SunOS 4.1 and later can use the POSIX   routines in the #else part of this clause, which work for both cc and gcc. */
define|#
directive|define
name|TCGETS
value|_IOR(T, 8, struct termios)
comment|/* Get modes into termios struct */
define|#
directive|define
name|TCSETS
value|_IOW(T, 9, struct termios)
comment|/* Set modes from termios struct */
define|#
directive|define
name|CRTSCTS
value|0x80000000
comment|/* RTS/CTS flow control */
struct|struct
name|termios
block|{
name|unsigned
name|long
name|c_iflag
decl_stmt|;
comment|/* Input modes */
name|unsigned
name|long
name|c_oflag
decl_stmt|;
comment|/* Output modes */
name|unsigned
name|long
name|c_cflag
decl_stmt|;
comment|/* Control modes */
name|unsigned
name|long
name|c_lflag
decl_stmt|;
comment|/* Line discipline modes */
name|char
name|c_line
decl_stmt|;
name|CHAR
name|c_cc
index|[
literal|17
index|]
decl_stmt|;
block|}
struct|;
name|struct
name|termios
name|temp
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETS
argument_list|,
operator|&
name|temp
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Get current terminal modes. */
name|temp
operator|.
name|c_cflag
operator||=
name|CRTSCTS
expr_stmt|;
comment|/* Add RTS/CTS to them. */
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETS
argument_list|,
operator|&
name|temp
argument_list|)
expr_stmt|;
comment|/* Set them again. */
block|}
else|#
directive|else
comment|/* Not SunOS 4.0 or later */
ifdef|#
directive|ifdef
name|ATTSV
if|if
condition|(
name|flow
operator|==
name|FLO_RTSC
condition|)
block|{
comment|/* RTS/CTS Flow control... */
ifdef|#
directive|ifdef
name|RTSXOFF
comment|/* This is the preferred way, according to SVID R4 */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETX
argument_list|,
operator|&
name|rctsx
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
name|rctsx
operator|.
name|x_hflag
operator||=
name|RTSXOFF
operator||
name|CTSXON
expr_stmt|;
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETX
argument_list|,
operator|&
name|rctsx
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* RTSXOFF */
block|}
if|if
condition|(
name|flow
operator|==
name|FLO_DTRC
condition|)
block|{
comment|/* DTR/CD Flow control... */
ifdef|#
directive|ifdef
name|DTRXOFF
comment|/* This is straight out of SVID R4 */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETX
argument_list|,
operator|&
name|rctsx
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
name|rctsx
operator|.
name|x_hflag
operator||=
name|DTRXOFF
operator||
name|CDXON
expr_stmt|;
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETX
argument_list|,
operator|&
name|rctsx
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* DTRXOFF */
block|}
else|#
directive|else
comment|/* not System V */
ifdef|#
directive|ifdef
name|CK_DTRCTS
name|x
operator|=
name|LDODTR
operator||
name|LDOCTS
expr_stmt|;
comment|/* Found only on UTEK? */
if|if
condition|(
name|flow
operator|==
name|FLO_DTRT
condition|)
block|{
comment|/* Use hardware flow control */
if|if
condition|(
name|lmodef
condition|)
block|{
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCLBIS
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"hardflow TIOCLBIS error"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|lmodef
operator|++
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"hardflow TIOCLBIS ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
if|if
condition|(
name|lmodef
condition|)
block|{
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCLBIC
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"hardflow TIOCLBIC error"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|lmodef
operator|++
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"hardflow TIOCLBIC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
block|}
endif|#
directive|endif
comment|/* CK_DTRCTS */
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* SUNOS4 */
endif|#
directive|endif
comment|/* SUNOS41 */
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  T T P K T  --  Condition the communication line for packets */
end_comment

begin_comment
comment|/*                 or for modem dialing */
end_comment

begin_comment
comment|/*   If called with speed> -1, also set the speed.   Returns 0 on success, -1 on failure.    NOTE: the "xflow" parameter is supposed to be the currently selected   type of flow control, but for historical reasons, this parameter is also   used to indicate that we are dialing.  Therefore, when the true flow   control setting is needed, we access the external variable "flow", rather   than trusting our "xflow" argument. */
end_comment

begin_function
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|ttpkt
parameter_list|(
name|long
name|speed
parameter_list|,
name|int
name|xflow
parameter_list|,
name|int
name|parity
parameter_list|)
else|#
directive|else
function|ttpkt
parameter_list|(
name|speed
parameter_list|,
name|xflow
parameter_list|,
name|parity
parameter_list|)
name|long
name|speed
decl_stmt|;
name|int
name|xflow
decl_stmt|,
name|parity
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* ttpkt */
block|{
name|int
name|s2
decl_stmt|;
name|int
name|s
init|=
operator|-
literal|1
decl_stmt|;
ifndef|#
directive|ifndef
name|SVORPOSIX
name|int
name|x
decl_stmt|;
endif|#
directive|endif
comment|/* SVORPOSIX */
specifier|extern
name|int
name|flow
decl_stmt|;
comment|/* REAL flow-control setting */
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Not open. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttpkt parity"
argument_list|,
literal|""
argument_list|,
name|parity
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttpkt xflow"
argument_list|,
literal|""
argument_list|,
name|xflow
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttpkt speed"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|speed
argument_list|)
expr_stmt|;
name|ttprty
operator|=
name|parity
expr_stmt|;
comment|/* Let other tt functions see these. */
name|ttpflg
operator|=
literal|0
expr_stmt|;
comment|/* Parity not sensed yet */
name|ttpmsk
operator|=
name|ttprty
condition|?
literal|0177
else|:
literal|0377
expr_stmt|;
comment|/* Parity stripping mask */
name|ttspeed
operator|=
name|speed
expr_stmt|;
comment|/* Make global copy for this module */
ifdef|#
directive|ifdef
name|NETCONN
comment|/* Nothing to do for telnet */
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* NETCONN */
if|if
condition|(
name|ttfdflg
operator|&&
operator|!
name|isatty
argument_list|(
name|ttyfd
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
ifndef|#
directive|ifndef
name|SVORPOSIX
comment|/* Berkeley, V7, etc. */
ifdef|#
directive|ifdef
name|LPASS8
comment|/*  For some reason, with BSD terminal drivers, you can't set FLOW to XON/XOFF  after having previously set it to NONE without closing and reopening the  device.  Unless there's something I overlooked below... */
if|if
condition|(
name|ttflow
operator|==
name|FLO_NONE
operator|&&
name|flow
operator|==
name|FLO_XONX
operator|&&
name|xlocal
operator|==
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttpkt executing horrible flow kludge"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Close it */
name|x
operator|=
literal|0
expr_stmt|;
name|ttopen
argument_list|(
name|ttnmsv
argument_list|,
operator|&
name|x
argument_list|,
name|ttmdm
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Open it again */
block|}
endif|#
directive|endif
comment|/* LPASS8 */
endif|#
directive|endif
comment|/* SVORPOSIX */
if|if
condition|(
name|xflow
operator|!=
name|FLO_DIAL
operator|&&
name|xflow
operator|!=
name|FLO_DIAX
condition|)
name|ttflow
operator|=
name|xflow
expr_stmt|;
comment|/* Now make this available too. */
if|if
condition|(
name|xlocal
condition|)
block|{
name|s2
operator|=
call|(
name|int
call|)
argument_list|(
name|speed
operator|/
literal|10L
argument_list|)
expr_stmt|;
comment|/* Convert bps to cps */
name|s
operator|=
name|ttsspd
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|/* Check and set the speed */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttpkt carrier"
argument_list|,
literal|""
argument_list|,
name|xflow
argument_list|)
expr_stmt|;
name|carrctl
argument_list|(
operator|&
name|ttraw
argument_list|,
name|xflow
operator|!=
name|FLO_DIAL
comment|/* Carrier control */
operator|&&
operator|(
name|ttcarr
operator|==
name|CAR_ON
operator|)
argument_list|)
expr_stmt|;
name|tvtflg
operator|=
literal|0
expr_stmt|;
comment|/* So ttvt() will work next time */
block|}
ifndef|#
directive|ifndef
name|SVORPOSIX
comment|/* BSD section */
if|if
condition|(
name|flow
operator|==
name|FLO_RTSC
operator|||
comment|/* Hardware flow control */
name|flow
operator|==
name|FLO_DTRC
operator|||
name|flow
operator|==
name|FLO_DTRT
condition|)
block|{
name|tthflow
argument_list|(
name|flow
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt hard flow, TANDEM off, RAW on"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttraw
operator|.
name|sg_flags
operator|&=
operator|~
name|TANDEM
expr_stmt|;
comment|/* Don't ask for it. */
name|ttraw
operator|.
name|sg_flags
operator||=
name|RAW
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_NONE
condition|)
block|{
comment|/* No Xon/Xoff flow control */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt no flow, TANDEM off, RAW on"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttraw
operator|.
name|sg_flags
operator|&=
operator|~
name|TANDEM
expr_stmt|;
comment|/* Don't ask for it. */
name|ttraw
operator|.
name|sg_flags
operator||=
name|RAW
expr_stmt|;
comment|/* NOTE: We should also turn off hardware flow control here! */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_KEEP
condition|)
block|{
comment|/* Keep device's original setting */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt keeping original TANDEM"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttraw
operator|.
name|sg_flags
operator|&=
operator|~
name|TANDEM
expr_stmt|;
name|ttraw
operator|.
name|sg_flags
operator||=
operator|(
name|ttold
operator|.
name|sg_flags
operator|&
name|TANDEM
operator|)
expr_stmt|;
comment|/* NOTE: We should also handle hardware flow control here! */
block|}
comment|/* SET FLOW XON/XOFF is in effect, or SET FLOW KEEP resulted in Xon/Xoff */
if|if
condition|(
operator|(
name|flow
operator|==
name|FLO_XONX
operator|)
operator|||
operator|(
name|ttraw
operator|.
name|sg_flags
operator|&
name|TANDEM
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt turning on TANDEM"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttraw
operator|.
name|sg_flags
operator||=
name|TANDEM
expr_stmt|;
comment|/* So ask for it. */
ifdef|#
directive|ifdef
name|LPASS8
comment|/* Can pass 8-bit data through? */
comment|/* If the LPASS8 local mode is available, then flow control can always  */
comment|/* be used, even if parity is none and we are transferring 8-bit data.  */
comment|/* But we only need to do all this if Xon/Xoff is requested. */
comment|/* BUT... this tends not to work through IP or LAT connections, terminal */
comment|/* servers, telnet, rlogin, etc, so it is currently disabled. */
name|x
operator|=
name|LPASS8
expr_stmt|;
comment|/* If LPASS8 defined, then */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt executing LPASS8 code"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|lmodef
condition|)
block|{
comment|/* TIOCLBIS must be too. */
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCLBIS
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
comment|/* Try to set LPASS8. */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCLBIS error"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|lmodef
operator|++
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCLBIS ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
comment|/*  But if we use LPASS8 mode, we must explicitly turn off  terminal interrupts of all kinds. */
ifdef|#
directive|ifdef
name|TIOCGETC
comment|/* Not rawmode, */
if|if
condition|(
name|tcharf
operator|&&
operator|(
name|xlocal
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* must turn off */
name|tchnoi
operator|.
name|t_intrc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* interrupt character */
name|tchnoi
operator|.
name|t_quitc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* and quit character. */
name|tchnoi
operator|.
name|t_startc
operator|=
literal|17
expr_stmt|;
comment|/* Make sure xon */
name|tchnoi
operator|.
name|t_stopc
operator|=
literal|19
expr_stmt|;
comment|/* and xoff not ignored. */
ifndef|#
directive|ifndef
name|NOBRKC
name|tchnoi
operator|.
name|t_eofc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* eof character. */
name|tchnoi
operator|.
name|t_brkc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* brk character. */
endif|#
directive|endif
comment|/* NOBRKC */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|tchnoi
argument_list|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCSETC failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|tcharf
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCSETC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|COMMENT
comment|/* only for paranoid debugging */
if|if
condition|(
name|tcharf
condition|)
block|{
name|struct
name|tchars
name|foo
decl_stmt|;
name|char
name|tchbuf
index|[
literal|100
index|]
decl_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETC
argument_list|,
operator|&
name|foo
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|tchbuf
argument_list|,
literal|"intr=%d,quit=%d, start=%d, stop=%d, eof=%d, brk=%d"
argument_list|,
name|foo
operator|.
name|t_intrc
argument_list|,
name|foo
operator|.
name|t_quitc
argument_list|,
name|foo
operator|.
name|t_startc
argument_list|,
name|foo
operator|.
name|t_stopc
argument_list|,
name|foo
operator|.
name|t_eofc
argument_list|,
name|foo
operator|.
name|t_brkc
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ttpkt chars"
argument_list|,
name|tchbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* COMMENT */
block|}
name|ttraw
operator|.
name|sg_flags
operator||=
name|CBREAK
expr_stmt|;
comment|/* Needed for unknown reason */
endif|#
directive|endif
comment|/* TIOCGETC */
comment|/* Prevent suspend during packet mode */
ifdef|#
directive|ifdef
name|TIOCGLTC
comment|/* Not rawmode, */
if|if
condition|(
name|ltcharf
operator|&&
operator|(
name|xlocal
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* must turn off */
name|ltchnoi
operator|.
name|t_suspc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* suspend character */
name|ltchnoi
operator|.
name|t_dsuspc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* and delayed suspend character */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSLTC
argument_list|,
operator|&
name|tchnoi
argument_list|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCSLTC failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ltcharf
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCSLTC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* TIOCGLTC */
else|#
directive|else
comment|/* LPASS8 not defined */
comment|/* Previously, BSD-based implementations always */
comment|/* used rawmode for packets.  Now, we use rawmode only if parity is NONE. */
comment|/* This allows the flow control requested above to actually work, but only */
comment|/* if the user asks for parity (which also means they get 8th-bit quoting). */
if|if
condition|(
name|parity
condition|)
block|{
comment|/* If parity, */
name|ttraw
operator|.
name|sg_flags
operator|&=
operator|~
name|RAW
expr_stmt|;
comment|/* use cooked mode */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* WHY??? */
if|if
condition|(
name|xlocal
condition|)
endif|#
directive|endif
comment|/* COMMENT */
name|ttraw
operator|.
name|sg_flags
operator||=
name|CBREAK
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttpkt cooked, cbreak, parity"
argument_list|,
literal|""
argument_list|,
name|parity
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TIOCGETC
comment|/* Not rawmode, */
if|if
condition|(
name|tcharf
operator|&&
operator|(
name|xlocal
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* must turn off */
name|tchnoi
operator|.
name|t_intrc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* interrupt character */
name|tchnoi
operator|.
name|t_quitc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* and quit character. */
name|tchnoi
operator|.
name|t_startc
operator|=
literal|17
expr_stmt|;
comment|/* Make sure xon */
name|tchnoi
operator|.
name|t_stopc
operator|=
literal|19
expr_stmt|;
comment|/* and xoff not ignored. */
ifndef|#
directive|ifndef
name|NOBRKC
name|tchnoi
operator|.
name|t_eofc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* eof character. */
name|tchnoi
operator|.
name|t_brkc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* brk character. */
endif|#
directive|endif
comment|/* NOBRKC */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|tchnoi
argument_list|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCSETC failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|tcharf
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCSETC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* TIOCGETC */
ifdef|#
directive|ifdef
name|TIOCGLTC
comment|/* Not rawmode, */
comment|/* Prevent suspend during packet mode */
if|if
condition|(
name|ltcharf
operator|&&
operator|(
name|xlocal
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* must turn off */
name|ltchnoi
operator|.
name|t_suspc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* suspend character */
name|ltchnoi
operator|.
name|t_dsuspc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* and delayed suspend character */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSLTC
argument_list|,
operator|&
name|tchnoi
argument_list|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCSLTC failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ltcharf
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt TIOCSLTC ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* TIOCGLTC */
block|}
else|else
block|{
comment|/* If no parity, */
name|ttraw
operator|.
name|sg_flags
operator||=
name|RAW
expr_stmt|;
comment|/* must use 8-bit raw mode. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttpkt setting rawmode, parity"
argument_list|,
literal|""
argument_list|,
name|parity
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* LPASS8 */
block|}
comment|/* End of Xon/Xoff section */
comment|/* Don't echo, don't map CR to CRLF on output, don't fool with case */
ifdef|#
directive|ifdef
name|LCASE
name|ttraw
operator|.
name|sg_flags
operator|&=
operator|~
operator|(
name|ECHO
operator||
name|CRMOD
operator||
name|LCASE
operator|)
expr_stmt|;
else|#
directive|else
name|ttraw
operator|.
name|sg_flags
operator|&=
operator|~
operator|(
name|ECHO
operator||
name|CRMOD
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* LCASE */
ifdef|#
directive|ifdef
name|TOWER1
name|ttraw
operator|.
name|sg_flags
operator|&=
operator|~
name|ANYP
expr_stmt|;
comment|/* Must set this on old Towers */
endif|#
directive|endif
comment|/* TOWER1 */
if|if
condition|(
name|stty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttraw
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Set the new modes. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt stty ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|sony_news
name|x
operator|=
name|xlocal
condition|?
name|km_ext
else|:
name|km_con
expr_stmt|;
comment|/* Put line in ASCII mode. */
if|if
condition|(
name|x
operator|!=
operator|-
literal|1
condition|)
block|{
comment|/* Make sure we know original modes. */
name|x
operator|&=
operator|~
name|KM_TTYPE
expr_stmt|;
name|x
operator||=
name|KM_ASCII
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCKSET
argument_list|,
operator|&
name|x
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"ttpkt can't set ASCII mode"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttpkt error setting ASCII mode"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttpkt set ASCII mode ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sony_news */
if|if
condition|(
name|xlocal
operator|==
literal|0
condition|)
comment|/* Turn this off so we can read */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Ctrl-C chars typed at console */
name|tvtflg
operator|=
literal|0
expr_stmt|;
comment|/* So ttvt() will work next time */
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* Not ATTSV or POSIX */
comment|/* AT&T UNIX and POSIX */
ifdef|#
directive|ifdef
name|SVORPOSIX
if|if
condition|(
name|flow
operator|==
name|FLO_XONX
condition|)
comment|/* Xon/Xoff */
name|ttraw
operator|.
name|c_iflag
operator||=
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_NONE
condition|)
block|{
comment|/* None */
name|ttraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|CCTS_OFLOW
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
operator|(
name|CCTS_OFLOW
operator||
name|CRTS_IFLOW
operator||
name|MDMBUF
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* CCTS_OFLOW */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_KEEP
condition|)
block|{
comment|/* Keep */
name|ttraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
comment|/* Turn off Xon/Xoff flags */
name|ttraw
operator|.
name|c_iflag
operator||=
operator|(
name|ttold
operator|.
name|c_iflag
operator|&
operator|(
name|IXON
operator||
name|IXOFF
operator|)
operator|)
expr_stmt|;
comment|/* OR in old ones */
comment|/* NOTE: We should also handle hardware flow control here! */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_RTSC
condition|)
block|{
ifdef|#
directive|ifdef
name|CCTS_OFLOW
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
name|CIGNORE
expr_stmt|;
name|ttraw
operator|.
name|c_cflag
operator||=
operator|(
name|CCTS_OFLOW
operator||
name|CRTS_IFLOW
operator|)
expr_stmt|;
name|ttraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* CCTS_OFLOW */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_DTRC
condition|)
block|{
ifdef|#
directive|ifdef
name|MDMBUF
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
name|CIGNORE
expr_stmt|;
name|ttraw
operator|.
name|c_cflag
operator||=
operator|(
name|CCTS_OFLOW
operator||
name|MDMBUF
operator|)
expr_stmt|;
name|ttraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* CCTS_OFLOW */
block|}
name|ttraw
operator|.
name|c_lflag
operator|&=
operator|~
operator|(
name|ICANON
operator||
name|ECHO
operator|)
expr_stmt|;
name|ttraw
operator|.
name|c_lflag
operator|&=
operator|~
name|ISIG
expr_stmt|;
comment|/* Do NOT check for interrupt chars */
name|ttraw
operator|.
name|c_lflag
operator|&=
operator|~
name|IEXTEN
expr_stmt|;
comment|/* Turn off ^O/^V processing */
name|ttraw
operator|.
name|c_lflag
operator||=
name|NOFLSH
expr_stmt|;
comment|/* Don't flush */
name|ttraw
operator|.
name|c_iflag
operator||=
operator|(
name|BRKINT
operator||
name|IGNPAR
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ATTSV
ifdef|#
directive|ifdef
name|BSD44
name|ttraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IGNBRK
operator||
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|INPCK
operator||
name|ISTRIP
operator||
name|IXANY
operator|)
expr_stmt|;
else|#
directive|else
name|ttraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IGNBRK
operator||
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|IUCLC
operator||
name|INPCK
operator||
name|ISTRIP
operator||
name|IXANY
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD44 */
else|#
directive|else
comment|/* POSIX */
name|ttraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IGNBRK
operator||
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|INPCK
operator||
name|ISTRIP
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* ATTSV */
name|ttraw
operator|.
name|c_oflag
operator|&=
operator|~
name|OPOST
expr_stmt|;
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
operator|(
name|CSIZE
operator||
name|PARENB
operator|)
expr_stmt|;
name|ttraw
operator|.
name|c_cflag
operator||=
operator|(
name|CS8
operator||
name|CREAD
operator||
name|HUPCL
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|IX370
name|ttraw
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|48
expr_stmt|;
comment|/* So Series/1 doesn't interrupt on every char */
name|ttraw
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|1
expr_stmt|;
else|#
directive|else
ifndef|#
directive|ifndef
name|VEOF
comment|/* for DGUX this is VEOF, not VMIN */
name|ttraw
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
comment|/* [VMIN]  return max of this many characters or */
else|#
directive|else
ifdef|#
directive|ifdef
name|VMIN
name|ttraw
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* VMIN */
endif|#
directive|endif
comment|/* VEOF */
ifndef|#
directive|ifndef
name|VEOL
comment|/* for DGUX this is VEOL, not VTIME */
name|ttraw
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|0
expr_stmt|;
comment|/* [VTIME] when this many secs/10 expire w/no input */
else|#
directive|else
ifdef|#
directive|ifdef
name|VTIME
name|ttraw
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* VTIME */
endif|#
directive|endif
comment|/* VEOL */
endif|#
directive|endif
comment|/* IX370 */
ifdef|#
directive|ifdef
name|VINTR
comment|/* Turn off interrupt character */
if|if
condition|(
name|xlocal
operator|==
literal|0
condition|)
comment|/* so ^C^C can break us out of */
name|ttraw
operator|.
name|c_cc
index|[
name|VINTR
index|]
operator|=
literal|0
expr_stmt|;
comment|/* packet mode. */
endif|#
directive|endif
comment|/* VINTR */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
if|if
condition|(
name|xlocal
operator|&&
operator|(
name|s
operator|>
literal|0
operator|)
condition|)
block|{
name|cfsetispeed
argument_list|(
operator|&
name|ttraw
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|cfsetospeed
argument_list|(
operator|&
name|ttraw
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ttraw
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|#
directive|else
comment|/* ATTSV */
if|if
condition|(
name|xlocal
operator|&&
operator|(
name|s
operator|>
literal|0
operator|)
condition|)
block|{
comment|/* set speed */
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
name|ttraw
operator|.
name|c_cflag
operator||=
name|s
expr_stmt|;
block|}
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|ttraw
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* set new modes . */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
name|tvtflg
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* ATTSV */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  T T V T -- Condition communication line for use as virtual terminal  */
end_comment

begin_function
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|ttvt
parameter_list|(
name|long
name|speed
parameter_list|,
name|int
name|flow
parameter_list|)
else|#
directive|else
function|ttvt
parameter_list|(
name|speed
parameter_list|,
name|flow
parameter_list|)
name|long
name|speed
decl_stmt|;
name|int
name|flow
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* ttvt */
block|{
name|int
name|s
decl_stmt|,
name|s2
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttvt ttyfd"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttvt tvtflg"
argument_list|,
literal|""
argument_list|,
name|tvtflg
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttvt speed"
argument_list|,
literal|""
argument_list|,
name|speed
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Not open. */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
block|{
name|tvtflg
operator|=
literal|1
expr_stmt|;
comment|/* Network connections */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* require no special setup */
block|}
endif|#
directive|endif
comment|/* NETCONN */
if|if
condition|(
name|tvtflg
operator|!=
literal|0
operator|&&
name|speed
operator|==
name|ttspeed
operator|&&
name|flow
operator|==
name|ttflow
operator|&&
name|ttcarr
operator|==
name|curcarr
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Already been called. */
if|if
condition|(
name|ttfdflg
operator|&&
operator|!
name|isatty
argument_list|(
name|ttyfd
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|xlocal
condition|)
block|{
comment|/* For external lines... */
name|s2
operator|=
call|(
name|int
call|)
argument_list|(
name|speed
operator|/
literal|10L
argument_list|)
expr_stmt|;
name|s
operator|=
name|ttsspd
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|/* Check/set the speed */
name|carrctl
argument_list|(
operator|&
name|tttvt
argument_list|,
name|flow
operator|!=
name|FLO_DIAL
comment|/* Do carrier control */
operator|&&
operator|(
name|ttcarr
operator|==
name|CAR_ON
operator|||
operator|(
name|ttcarr
operator|==
name|CAR_AUT
operator|&&
name|ttmdm
operator|!=
literal|0
operator|)
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
name|s
operator|=
name|s2
operator|=
operator|-
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|SVORPOSIX
comment|/* Berkeley, V7, etc */
if|if
condition|(
name|flow
operator|==
name|FLO_RTSC
operator|||
comment|/* Hardware flow control */
name|flow
operator|==
name|FLO_DTRC
operator|||
name|flow
operator|==
name|FLO_DTRT
condition|)
name|tthflow
argument_list|(
name|flow
argument_list|)
expr_stmt|;
if|if
condition|(
name|flow
operator|==
name|FLO_XONX
condition|)
block|{
comment|/* No Xon/Xoff flow control */
name|tttvt
operator|.
name|sg_flags
operator||=
name|TANDEM
expr_stmt|;
comment|/* Ask for it. */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_KEEP
condition|)
block|{
name|tttvt
operator|.
name|sg_flags
operator|&=
operator|~
name|TANDEM
expr_stmt|;
name|tttvt
operator|.
name|sg_flags
operator||=
operator|(
name|ttold
operator|.
name|sg_flags
operator|&
name|TANDEM
operator|)
expr_stmt|;
comment|/* NOTE: We should also handle hardware flow control here! */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_NONE
condition|)
block|{
name|tttvt
operator|.
name|sg_flags
operator|&=
operator|~
name|TANDEM
expr_stmt|;
comment|/* Don't ask for it. */
comment|/* NOTE: We should also turn off hardware flow control here! */
block|}
name|tttvt
operator|.
name|sg_flags
operator||=
name|RAW
expr_stmt|;
comment|/* Raw mode in all cases */
ifdef|#
directive|ifdef
name|TOWER1
name|tttvt
operator|.
name|sg_flags
operator|&=
operator|~
operator|(
name|ECHO
operator||
name|ANYP
operator|)
expr_stmt|;
comment|/* No echo or parity */
else|#
directive|else
name|tttvt
operator|.
name|sg_flags
operator|&=
operator|~
name|ECHO
expr_stmt|;
comment|/* No echo */
endif|#
directive|endif
comment|/* TOWER1 */
if|if
condition|(
name|stty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|tttvt
argument_list|)
operator|<
literal|0
condition|)
comment|/* Set the new modes */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|#
directive|else
comment|/* It is ATTSV or POSIX */
if|if
condition|(
name|flow
operator|==
name|FLO_RTSC
condition|)
block|{
comment|/* Hardware flow control */
ifdef|#
directive|ifdef
name|CCTS_OFLOW
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
name|CIGNORE
expr_stmt|;
name|tttvt
operator|.
name|c_cflag
operator||=
operator|(
name|CCTS_OFLOW
operator||
name|CRTS_IFLOW
operator|)
expr_stmt|;
name|tttvt
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* CCTS_OFLOW */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_DTRC
condition|)
block|{
ifdef|#
directive|ifdef
name|MDMBUF
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
name|CIGNORE
expr_stmt|;
name|tttvt
operator|.
name|c_cflag
operator||=
operator|(
name|CCTS_OFLOW
operator||
name|MDMBUF
operator|)
expr_stmt|;
name|tttvt
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* CCTS_OFLOW */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_XONX
condition|)
block|{
comment|/* Software flow control */
name|tttvt
operator|.
name|c_iflag
operator||=
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
comment|/* On if requested. */
ifdef|#
directive|ifdef
name|CCTS_OFLOW
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
operator|(
name|CCTS_OFLOW
operator||
name|CRTS_IFLOW
operator||
name|MDMBUF
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* CCTS_OFLOW */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_KEEP
condition|)
block|{
name|tttvt
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
comment|/* Turn off Xon/Xoff flags */
name|tttvt
operator|.
name|c_iflag
operator||=
operator|(
name|ttold
operator|.
name|c_iflag
operator|&
operator|(
name|IXON
operator||
name|IXOFF
operator|)
operator|)
expr_stmt|;
comment|/* OR in old ones */
comment|/* NOTE: We should also handle hardware flow control here! */
block|}
elseif|else
if|if
condition|(
name|flow
operator|==
name|FLO_NONE
condition|)
block|{
comment|/* Off if NONE or hardware */
name|tttvt
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
comment|/* requested. */
ifdef|#
directive|ifdef
name|CCTS_OFLOW
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
operator|(
name|CCTS_OFLOW
operator||
name|CRTS_IFLOW
operator||
name|MDMBUF
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* CCTS_OFLOW */
block|}
name|tttvt
operator|.
name|c_lflag
operator|&=
operator|~
operator|(
name|ISIG
operator||
name|ICANON
operator||
name|ECHO
operator||
name|IEXTEN
operator|)
expr_stmt|;
name|tttvt
operator|.
name|c_iflag
operator||=
operator|(
name|IGNBRK
operator||
name|IGNPAR
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ATTSV
ifdef|#
directive|ifdef
name|BSD44
name|tttvt
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|BRKINT
operator||
name|INPCK
operator||
name|ISTRIP
operator||
name|IXANY
operator|)
expr_stmt|;
else|#
directive|else
name|tttvt
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|IUCLC
operator||
name|BRKINT
operator||
name|INPCK
operator||
name|ISTRIP
operator||
name|IXANY
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD44 */
else|#
directive|else
comment|/* POSIX */
name|tttvt
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|BRKINT
operator||
name|INPCK
operator||
name|ISTRIP
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* ATTSV */
name|tttvt
operator|.
name|c_oflag
operator|&=
operator|~
name|OPOST
expr_stmt|;
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
operator|(
name|CSIZE
operator||
name|PARENB
operator|)
expr_stmt|;
name|tttvt
operator|.
name|c_cflag
operator||=
operator|(
name|CS8
operator||
name|CREAD
operator||
name|HUPCL
operator|)
expr_stmt|;
ifndef|#
directive|ifndef
name|VEOF
comment|/* DGUX termio has VEOF at entry 4, see comment above */
name|tttvt
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VMIN
name|tttvt
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* VMIN */
endif|#
directive|endif
comment|/* VEOF */
ifndef|#
directive|ifndef
name|VEOL
comment|/* DGUX termio has VEOL at entry 5, see comment above */
name|tttvt
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|0
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VTIME
name|tttvt
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* VTIME */
endif|#
directive|endif
comment|/* VEOL */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
if|if
condition|(
name|xlocal
operator|&&
operator|(
name|s
operator|>
literal|0
operator|)
condition|)
block|{
name|cfsetispeed
argument_list|(
operator|&
name|tttvt
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|cfsetospeed
argument_list|(
operator|&
name|tttvt
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|tttvt
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|#
directive|else
comment|/* ATTSV */
if|if
condition|(
name|s
operator|>
literal|0
condition|)
block|{
comment|/* Set speed */
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
name|tttvt
operator|.
name|c_cflag
operator||=
name|s
expr_stmt|;
block|}
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|tttvt
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* set new modes . */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
endif|#
directive|endif
comment|/* ATTSV */
name|ttspeed
operator|=
name|speed
expr_stmt|;
comment|/* Done, remember how we were */
name|ttflow
operator|=
name|flow
expr_stmt|;
comment|/* called, so we can decide how to */
name|tvtflg
operator|=
literal|1
expr_stmt|;
comment|/* respond next time. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttvt done"
argument_list|,
literal|""
argument_list|,
name|tvtflg
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  T T S S P D  --  Checks and sets transmission rate.  */
end_comment

begin_comment
comment|/*  Call with speed in characters (not bits!) per second. */
end_comment

begin_comment
comment|/*  Returns internal speed code if successful, -1 otherwise. */
end_comment

begin_function
name|int
name|ttsspd
parameter_list|(
name|cps
parameter_list|)
name|int
name|cps
decl_stmt|;
block|{
name|int
name|s
decl_stmt|,
name|s2
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttsspd"
argument_list|,
literal|""
argument_list|,
name|cps
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* NETCONN */
if|if
condition|(
name|cps
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|s
operator|=
name|s2
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* First check that the given speed is valid. */
switch|switch
condition|(
name|cps
condition|)
block|{
ifndef|#
directive|ifndef
name|MINIX
case|case
literal|0
case|:
name|s
operator|=
name|B0
expr_stmt|;
break|break;
case|case
literal|5
case|:
name|s
operator|=
name|B50
expr_stmt|;
break|break;
case|case
literal|7
case|:
name|s
operator|=
name|B75
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
literal|11
case|:
name|s
operator|=
name|B110
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|MINIX
case|case
literal|15
case|:
name|s
operator|=
name|B150
expr_stmt|;
break|break;
case|case
literal|20
case|:
name|s
operator|=
name|B200
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
literal|30
case|:
name|s
operator|=
name|B300
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|MINIX
case|case
literal|60
case|:
name|s
operator|=
name|B600
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
literal|120
case|:
name|s
operator|=
name|B1200
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|MINIX
case|case
literal|180
case|:
name|s
operator|=
name|B1800
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
literal|240
case|:
name|s
operator|=
name|B2400
expr_stmt|;
break|break;
case|case
literal|480
case|:
name|s
operator|=
name|B4800
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|MINIX
case|case
literal|888
case|:
name|s
operator|=
name|B75
expr_stmt|;
name|s2
operator|=
name|B1200
expr_stmt|;
break|break;
comment|/* 888 = 75/1200 split speed */
endif|#
directive|endif
case|case
literal|960
case|:
name|s
operator|=
name|B9600
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|B19200
case|case
literal|1920
case|:
name|s
operator|=
name|B19200
expr_stmt|;
break|break;
else|#
directive|else
ifdef|#
directive|ifdef
name|EXTA
case|case
literal|1920
case|:
name|s
operator|=
name|EXTA
expr_stmt|;
break|break;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B38400
case|case
literal|3840
case|:
name|s
operator|=
name|B38400
expr_stmt|;
break|break;
else|#
directive|else
ifdef|#
directive|ifdef
name|EXTB
case|case
literal|3840
case|:
name|s
operator|=
name|EXTB
expr_stmt|;
break|break;
endif|#
directive|endif
endif|#
directive|endif
default|default:
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* Actually set the speed */
if|if
condition|(
name|ttyfd
operator|>
operator|-
literal|1
operator|&&
name|s
operator|>
operator|-
literal|1
operator|&&
name|xlocal
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|s2
operator|==
operator|-
literal|1
condition|)
name|s2
operator|=
name|s
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
if|if
condition|(
name|tcgetattr
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|cfsetospeed
argument_list|(
operator|&
name|ttcur
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|cfsetispeed
argument_list|(
operator|&
name|ttcur
argument_list|,
name|s2
argument_list|)
expr_stmt|;
name|cfsetospeed
argument_list|(
operator|&
name|ttraw
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|cfsetispeed
argument_list|(
operator|&
name|ttraw
argument_list|,
name|s2
argument_list|)
expr_stmt|;
name|cfsetospeed
argument_list|(
operator|&
name|tttvt
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|cfsetispeed
argument_list|(
operator|&
name|tttvt
argument_list|,
name|s2
argument_list|)
expr_stmt|;
name|cfsetospeed
argument_list|(
operator|&
name|ttold
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|cfsetispeed
argument_list|(
operator|&
name|ttold
argument_list|,
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|tcsetattr
argument_list|(
name|ttyfd
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATTSV
if|if
condition|(
name|cps
operator|==
literal|888
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* No split speeds, sorry. */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|ttcur
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
name|ttcur
operator|.
name|c_cflag
operator||=
name|s
expr_stmt|;
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
name|tttvt
operator|.
name|c_cflag
operator||=
name|s
expr_stmt|;
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
name|ttraw
operator|.
name|c_cflag
operator||=
name|s
expr_stmt|;
name|ttold
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
name|ttold
operator|.
name|c_cflag
operator||=
name|s
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|#
directive|else
if|if
condition|(
name|gtty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|ttcur
operator|.
name|sg_ospeed
operator|=
name|s
expr_stmt|;
name|ttcur
operator|.
name|sg_ispeed
operator|=
name|s2
expr_stmt|;
name|tttvt
operator|.
name|sg_ospeed
operator|=
name|s
expr_stmt|;
name|tttvt
operator|.
name|sg_ispeed
operator|=
name|s2
expr_stmt|;
name|ttraw
operator|.
name|sg_ospeed
operator|=
name|s
expr_stmt|;
name|ttraw
operator|.
name|sg_ispeed
operator|=
name|s2
expr_stmt|;
name|ttold
operator|.
name|sg_ospeed
operator|=
name|s
expr_stmt|;
name|ttold
operator|.
name|sg_ispeed
operator|=
name|s2
expr_stmt|;
if|if
condition|(
name|stty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
block|}
return|return
operator|(
name|s
operator|)
return|;
block|}
end_function

begin_comment
comment|/* T T G S P D  -  Get speed of currently selected tty line  */
end_comment

begin_comment
comment|/*   Unreliable.  After SET LINE, it returns an actual speed, but not the real   speed.  Apparently it always returns the line's nominal speed, from   /etc/ttytab.  Even if you SET SPEED to something else, this function might   not notice. */
end_comment

begin_function
name|long
name|ttgspd
parameter_list|()
block|{
comment|/* Get current tty speed */
name|int
name|s
decl_stmt|;
name|long
name|ss
decl_stmt|;
name|char
name|temp
index|[
literal|12
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* -1 if network connection */
endif|#
directive|endif
comment|/* NETCONN */
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
name|s
operator|=
name|cfgetospeed
argument_list|(
operator|&
name|ccold
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATTSV
name|s
operator|=
name|ccold
operator|.
name|c_cflag
operator|&
name|CBAUD
expr_stmt|;
else|#
directive|else
name|s
operator|=
name|ccold
operator|.
name|sg_ospeed
expr_stmt|;
comment|/* (obtained by congm()) */
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
if|if
condition|(
name|tcgetattr
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|s
operator|=
name|cfgetospeed
argument_list|(
operator|&
name|ttcur
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATTSV
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|s
operator|=
name|ttcur
operator|.
name|c_cflag
operator|&
name|CBAUD
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|gtty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttcur
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|s
operator|=
name|ttcur
operator|.
name|sg_ospeed
expr_stmt|;
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttgspd ttyfd"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttgspd code"
argument_list|,
literal|""
argument_list|,
name|s
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|s
condition|)
block|{
ifdef|#
directive|ifdef
name|B0
case|case
name|B0
case|:
name|ss
operator|=
literal|0L
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* B0 */
ifndef|#
directive|ifndef
name|MINIX
comment|/*  MINIX defines the Bxx symbols to be bps/100, so B50==B75, B110==B134==B150,  etc, making for many "duplicate case in switch" errors, which are fatal. */
ifdef|#
directive|ifdef
name|B50
case|case
name|B50
case|:
name|ss
operator|=
literal|50L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B75
case|case
name|B75
case|:
name|ss
operator|=
literal|75L
expr_stmt|;
break|break;
endif|#
directive|endif
endif|#
directive|endif
comment|/* MINIX */
ifdef|#
directive|ifdef
name|B110
case|case
name|B110
case|:
name|ss
operator|=
literal|110L
expr_stmt|;
break|break;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MINIX
ifdef|#
directive|ifdef
name|B134
case|case
name|B134
case|:
name|ss
operator|=
literal|134L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B150
case|case
name|B150
case|:
name|ss
operator|=
literal|150L
expr_stmt|;
break|break;
endif|#
directive|endif
endif|#
directive|endif
comment|/* MINIX */
ifdef|#
directive|ifdef
name|B200
case|case
name|B200
case|:
name|ss
operator|=
literal|200L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B300
case|case
name|B300
case|:
name|ss
operator|=
literal|300L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B600
case|case
name|B600
case|:
name|ss
operator|=
literal|600L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B1200
case|case
name|B1200
case|:
name|ss
operator|=
literal|1200L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B1800
case|case
name|B1800
case|:
name|ss
operator|=
literal|1800L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B2400
case|case
name|B2400
case|:
name|ss
operator|=
literal|2400L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B4800
case|case
name|B4800
case|:
name|ss
operator|=
literal|4800L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B9600
case|case
name|B9600
case|:
name|ss
operator|=
literal|9600L
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B19200
case|case
name|B19200
case|:
name|ss
operator|=
literal|19200L
expr_stmt|;
break|break;
else|#
directive|else
ifdef|#
directive|ifdef
name|EXTA
case|case
name|EXTA
case|:
name|ss
operator|=
literal|19200L
expr_stmt|;
break|break;
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MINIX
ifdef|#
directive|ifdef
name|B38400
case|case
name|B38400
case|:
name|ss
operator|=
literal|38400L
expr_stmt|;
break|break;
else|#
directive|else
ifdef|#
directive|ifdef
name|EXTB
case|case
name|EXTB
case|:
name|ss
operator|=
literal|38400L
expr_stmt|;
break|break;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
comment|/* MINIX */
default|default:
name|ss
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
block|}
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|"%ld"
argument_list|,
name|ss
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"speed"
argument_list|,
name|temp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|ss
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ckumyr.c by Kristoffer Eriksson, ske@pkmab.se, 15 Mar 1990. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FIONREAD
end_ifdef

begin_undef
undef|#
directive|undef
name|FIONREAD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FIONREAD
value|TIOCQUERY
end_define

begin_define
define|#
directive|define
name|PEEKTYPE
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PEEKTYPE
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYREAD
end_ifdef

begin_comment
comment|/* Private buffer for myread() and its companions.  Not for use by anything  * else.  ttflui() is allowed to reset them to initial values.  ttchk() is  * allowed to read my_count.  *  * my_item is an index into mybuf[].  Increment it *before* reading mybuf[].  *  * A global parity mask variable could be useful too.  We could use it to  * let myread() strip the parity on its own, instead of stripping sign  * bits as it does now.  */
end_comment

begin_define
define|#
directive|define
name|MYBUFLEN
value|256
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUNX25
end_ifdef

begin_comment
comment|/*   On X.25 connections, there is an extra control byte at the beginning. */
end_comment

begin_decl_stmt
specifier|static
name|CHAR
name|x25buf
index|[
name|MYBUFLEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Communication device input buffer */
end_comment

begin_decl_stmt
specifier|static
name|CHAR
modifier|*
name|mybuf
init|=
name|x25buf
operator|+
literal|1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|CHAR
name|mybuf
index|[
name|MYBUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNX25 */
end_comment

begin_decl_stmt
specifier|static
name|int
name|my_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of chars still in mybuf */
end_comment

begin_decl_stmt
specifier|static
name|int
name|my_item
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last index read from mybuf[] */
end_comment

begin_comment
comment|/* myread() -- Efficient read of one character from communications line.  *  * Uses a private buffer to minimize the number of expensive read() system  * calls.  Essentially performs the equivalent of read() of 1 character, which  * is then returned.  By reading all available input from the system buffers  * to the private buffer in one chunk, and then working from this buffer, the  * number of system calls is reduced in any case where more than one character  * arrives during the processing of the previous chunk, for instance high  * baud rates or network type connections where input arrives in packets.  * If the time needed for a read() system call approaches the time for more  * than one character to arrive, then this mechanism automatically compensates  * for that by performing bigger read()s less frequently.  If the system load  * is high, the same mechanism compensates for that too.  *  * myread() is a macro that returns the next character from the buffer.  If the  * buffer is empty, mygetbuf() is called.  See mygetbuf() for possible error  * returns.  *  * This should be efficient enough for any one-character-at-a-time loops.  * For even better efficiency you might use memcpy()/bcopy() or such between  * buffers (since they are often better optimized for copying), but it may not  * be worth it if you have to take an extra pass over the buffer to strip  * parity and check for CTRL-C anyway.  *  * Note that if you have been using myread() from another program module, you  * may have some trouble accessing this macro version and the private variables  * it uses.  In that case, just add a function in this module, that invokes the  * macro.  */
end_comment

begin_define
define|#
directive|define
name|myread
parameter_list|()
value|(--my_count< 0 ? mygetbuf() : 255& (int)mybuf[++my_item])
end_define

begin_comment
comment|/* Specification: Push back up to one character onto myread()'s queue.  *  * This implementation: Push back characters into mybuf. At least one character  * must have been read through myread() before myunrd() may be used.  After  * EOF or read error, again, myunrd() can not be used.  Sometimes more than  * one character can be pushed back, but only one character is guaranteed.  * Since a previous myread() must have read its character out of mybuf[],  * that guarantees that there is space for at least one character.  If push  * back was really needed after EOF, a small addition could provide that.  *  * myunrd() is currently not called from anywhere inside kermit...  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOTUSED
end_ifdef

begin_macro
name|myunrd
argument_list|(
argument|ch
argument_list|)
end_macro

begin_decl_stmt
name|CHAR
name|ch
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|my_item
operator|>=
literal|0
condition|)
block|{
name|mybuf
index|[
name|my_item
operator|--
index|]
operator|=
name|ch
expr_stmt|;
operator|++
name|my_count
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mygetbuf() -- Fill buffer for myread() and return first character.  *  * This function is what myread() uses when it can't get the next character  * directly from its buffer.  First, it calls a system dependent myfillbuf()  * to read at least one new character into the buffer, and then it returns  * the first character just as myread() would have done.  This function also  * is responsible for all error conditions that myread() can indicate.  *  * Returns: When OK	=> a positive character, 0 or greater.  *	    When EOF	=> -2.  *	    When error	=> -3, error code in errno.  *  * Older myread()s additionally returned -1 to indicate that there was nothing  * to read, upon which the caller would call myread() again until it got  * something.  The new myread()/mygetbuf() always gets something.  If it   * doesn't, then make it do so!  Any program that actually depends on the old  * behaviour will break.  *  * The older version also used to return -2 both for EOF and other errors,  * and used to set errno to 9999 on EOF.  The errno stuff is gone, EOF and  * other errors now return different results, although Kermit currently never  * checks to see which it was.  It just disconnects in both cases.  *  * Kermit lets the user use the quit key to perform some special commands  * during file transfer.  This causes read(), and thus also mygetbuf(), to  * finish without reading anything and return the EINTR error.  This should  * be checked by the caller.  Mygetbuf() could retry the read() on EINTR,  * but if there is nothing to read, this could delay Kermit's reaction to  * the command, and make Kermit appear unresponsive.  *  * The debug() call should be removed for optimum performance.  */
end_comment

begin_function
name|int
name|mygetbuf
parameter_list|()
block|{
name|my_count
operator|=
name|myfillbuf
argument_list|()
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"myfillbuf read"
argument_list|,
literal|""
argument_list|,
name|my_count
argument_list|)
expr_stmt|;
if|if
condition|(
name|my_count
operator|<=
literal|0
condition|)
return|return
operator|(
name|my_count
operator|<
literal|0
condition|?
operator|-
literal|3
else|:
operator|-
literal|2
operator|)
return|;
operator|--
name|my_count
expr_stmt|;
return|return
operator|(
literal|255
operator|&
operator|(
name|int
operator|)
name|mybuf
index|[
name|my_item
operator|=
literal|0
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* myfillbuf():  * System-dependent read() into mybuf[], as many characters as possible.  *  * Returns: OK => number of characters read, always more than zero.  *          EOF => 0  *          Error => -1, error code in errno.  *  * If there is input available in the system's buffers, all of it should be  * read into mybuf[] and the function return immediately.  If no input is  * available, it should wait for a character to arrive, and return with that  * one in mybuf[] as soon as possible.  It may wait somewhat past the first  * character, but be aware that any such delay lengthens the packet turnaround  * time during kermit file transfers.  Should never return with zero characters  * unless EOF or irrecoverable read error.  *  * Correct functioning depends on the correct tty parameters being used.  * Better control of current parameters is required than may have been the  * case in older Kermit releases.  For instance, O_NDELAY (or equivalent) can   * no longer be sometimes off and sometimes on like it used to, unless a   * special myfillbuf() is written to handle that.  Otherwise the ordinary   * myfillbuf()s may think they have come to EOF.  *  * If your system has a facility to directly perform the functioning of  * myfillbuf(), then use it.  If the system can tell you how many characters  * are available in its buffers, then read that amount (but not less than 1).  * If the system can return a special indication when you try to read without  * anything to read, while allowing you to read all there is when there is  * something, you may loop until there is something to read, but probably that  * is not good for the system load.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVORPOSIX
end_ifdef

begin_comment
comment|/* This is for System III/V with VMIN>0, VTIME=0 and O_NDELAY off, 	 * and CLOCAL set any way you like.  This way, read() will do exactly 	 * what is required by myfillbuf(): If there is data in the buffers 	 * of the O.S., all available data is read into mybuf, up to the size 	 * of mybuf.  If there is none, the first character to arrive is 	 * awaited and returned. 	 */
end_comment

begin_function
name|int
name|myfillbuf
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|sxaE50
comment|/* From S. Dezawa at Fujifilm in Japan.  I don't know why this is */
comment|/* necessary for the sxa E50, but it is. */
return|return
name|read
argument_list|(
name|ttyfd
argument_list|,
name|mybuf
argument_list|,
literal|255
argument_list|)
return|;
else|#
directive|else
comment|/* sizeof(mybuf) should be MYBUFL == 256 */
return|return
name|read
argument_list|(
name|ttyfd
argument_list|,
name|mybuf
argument_list|,
sizeof|sizeof
argument_list|(
name|mybuf
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
comment|/* sxaE50 */
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not AT&T or POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|aegis
end_ifdef

begin_comment
comment|/* This is quoted from the old myread().  The semantics seem to be 	 * alright, but maybe errno would not need to be set even when 	 * there is no error?  I don't know aegis. 	 */
end_comment

begin_function
name|int
name|myfillbuf
parameter_list|()
block|{
name|int
name|count
decl_stmt|;
name|count
operator|=
name|ios_$get
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|ios_$cond_opt
argument_list|,
name|mybuf
argument_list|,
literal|256L
argument_list|,
name|st
argument_list|)
expr_stmt|;
name|errno
operator|=
name|EIO
expr_stmt|;
if|if
condition|(
name|st
operator|.
name|all
operator|==
name|ios_$get_conditional_failed
condition|)
comment|/* get at least one */
name|inbufc
operator|=
name|ios_$get
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
literal|0
argument_list|,
name|mybuf
argument_list|,
literal|1L
argument_list|,
name|st
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|.
name|all
operator|==
name|ios_$end_of_file
condition|)
return|return
operator|(
literal|0
operator|)
return|;
elseif|else
if|if
condition|(
name|st
operator|.
name|all
operator|!=
name|status_$ok
condition|)
block|{
name|errno
operator|=
name|EIO
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
name|count
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !aegis */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FIONREAD
end_ifdef

begin_comment
comment|/* This is for systems with FIONREAD.  FIONREAD returns the number 	 * of characters available for reading. If none are available, wait 	 * until something arrives, otherwise return all there is. 	 */
end_comment

begin_function
name|int
name|myfillbuf
parameter_list|()
block|{
name|PEEKTYPE
name|avail
decl_stmt|;
name|int
name|x
decl_stmt|;
ifdef|#
directive|ifdef
name|SUNX25
comment|/*   SunLink X.25 support in this routine from Stefaan A. Eeckels, Eurostat (CEC).   Depends on SunOS having FIONREAD, not because we use it, but just so this   code is grouped correctly within the #ifdefs.  Let's hope Solaris keeps it.    We call x25xin() instead of read() so that Q-Bit packets, which contain   X.25 service-level information (e.g. PAD parameter changes), can be processed   transparently to the upper-level code.  This is a blocking read, and so   we depend on higher-level code (such as ttinc()) to set any necessary alarms. */
specifier|extern
name|int
name|nettype
decl_stmt|;
if|if
condition|(
name|netconn
operator|&&
name|nettype
operator|==
name|NET_SX25
condition|)
block|{
while|while
condition|(
operator|(
name|x
operator|=
name|x25xin
argument_list|(
sizeof|sizeof
argument_list|(
name|x25buf
argument_list|)
argument_list|,
name|x25buf
argument_list|)
operator|)
operator|<
literal|1
condition|)
empty_stmt|;
return|return
operator|(
name|x
operator|-
literal|1
operator|)
return|;
comment|/* "-1" compensates for extra status byte */
block|}
endif|#
directive|endif
comment|/* SUNX25 */
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|avail
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"myfillbuf FIONREAD"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"myfillbuf errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|x
operator|<
literal|0
operator|||
name|avail
operator|==
literal|0
condition|)
name|avail
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|avail
operator|>
name|MYBUFLEN
condition|)
name|avail
operator|=
name|MYBUFLEN
expr_stmt|;
return|return
operator|(
name|read
argument_list|(
name|ttyfd
argument_list|,
name|mybuf
argument_list|,
operator|(
name|int
operator|)
name|avail
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !FIONREAD */
end_comment

begin_comment
comment|/* Add other systems here, between #ifdef and #else, e.g. NETCONN. */
end_comment

begin_comment
comment|/* When there is no other possibility, read 1 character at a time. */
end_comment

begin_function
name|int
name|myfillbuf
parameter_list|()
block|{
return|return
name|read
argument_list|(
name|ttyfd
argument_list|,
name|mybuf
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !FIONREAD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !aegis */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYREAD */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  T T F L U I  --  Flush tty input buffer */
end_comment

begin_function
name|int
name|ttflui
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|BSD44
name|int
name|n
decl_stmt|;
endif|#
directive|endif
comment|/* BSD44 */
ifndef|#
directive|ifndef
name|SVORPOSIX
name|int
name|n
decl_stmt|;
endif|#
directive|endif
comment|/* SVORPOSIX */
ifdef|#
directive|ifdef
name|MYREAD
comment|/*   Flush internal MYREAD buffer *FIRST*, in all cases. */
name|my_count
operator|=
literal|0
expr_stmt|;
comment|/* Reset count to zero */
name|my_item
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* And buffer index to -1 */
endif|#
directive|endif
comment|/* MYREAD */
ifdef|#
directive|ifdef
name|NETCONN
comment|/*   Network flush is done specially, in the network support module. */
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
name|netflui
argument_list|()
operator|)
return|;
endif|#
directive|endif
comment|/* NETCONN */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttflui ttyfd"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
ifdef|#
directive|ifdef
name|aegis
name|sio_$control
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|sio_$flush_in
argument_list|,
name|true
argument_list|,
name|st
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|.
name|all
operator|!=
name|status_$ok
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"flush failed: "
argument_list|)
expr_stmt|;
name|error_$print
argument_list|(
name|st
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* sometimes the flush doesn't work */
for|for
control|(
init|;
condition|;
control|)
block|{
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
comment|/* eat all the characters that shouldn't be available */
name|ios_$get
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|ios_$cond_opt
argument_list|,
name|buf
argument_list|,
literal|256L
argument_list|,
name|st
argument_list|)
expr_stmt|;
comment|/* (void) */
if|if
condition|(
name|st
operator|.
name|all
operator|==
name|ios_$get_conditional_failed
condition|)
break|break;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"flush failed(2): "
argument_list|)
expr_stmt|;
name|error_$print
argument_list|(
name|st
argument_list|)
expr_stmt|;
block|}
block|}
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD44
comment|/* 4.4 BSD */
name|n
operator|=
name|FREAD
expr_stmt|;
comment|/* Specify read queue */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttflui BSD44 flush"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCFLUSH
argument_list|,
operator|&
name|n
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSAFLUSH
argument_list|,
operator|&
name|n
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|POSIX
comment|/* POSIX */
name|tcflush
argument_list|(
name|ttyfd
argument_list|,
name|TCIFLUSH
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATTSV
comment|/* System V */
ifndef|#
directive|ifndef
name|VXVE
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCFLSH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VXVE */
else|#
directive|else
comment|/* Not BSD44, POSIX, or Sys V */
ifdef|#
directive|ifdef
name|TIOCFLUSH
comment|/* Those with TIOCFLUSH defined */
ifdef|#
directive|ifdef
name|ANYBSD
comment|/* Berkeley */
name|n
operator|=
name|FREAD
expr_stmt|;
comment|/* Specify read queue */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttflui anybsd flush"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCFLUSH
argument_list|,
operator|&
name|n
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Others (V7, etc) */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCFLUSH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ANYBSD */
else|#
directive|else
comment|/* All others... */
comment|/*   No system call (that we know about) for input buffer flushing.   So see how many there are and read them in a loop, using ttinc().   ttinc() is buffered, so we're not getting charged with a system call    per character, just a function call. */
if|if
condition|(
operator|(
name|n
operator|=
name|ttchk
argument_list|()
operator|)
operator|>
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttflui reading"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|n
operator|--
operator|)
operator|&&
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|>
literal|1
condition|)
empty_stmt|;
block|}
endif|#
directive|endif
comment|/* TIOCFLUSH */
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* POSIX */
endif|#
directive|endif
comment|/* BSD44 */
endif|#
directive|endif
comment|/* aegis */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|ttfluo
parameter_list|()
block|{
comment|/* Flush output buffer */
ifdef|#
directive|ifdef
name|POSIX
return|return
operator|(
name|tcflush
argument_list|(
name|ttyfd
argument_list|,
name|TCOFLUSH
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
comment|/* (dummy for now) */
endif|#
directive|endif
comment|/* POSIX */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Interrupt Functions */
end_comment

begin_comment
comment|/* Set up terminal interrupts on console terminal */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVORPOSIX
end_ifdef

begin_function
name|SIGTYP
name|esctrp
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* trap console escapes (^\) */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* ignore until trapped */
name|conesc
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"esctrp caught SIGQUIT"
argument_list|,
literal|""
argument_list|,
name|conesc
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVORPOSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_function
name|SIGTYP
name|esctrp
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* trap console escapes (^\) */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* ignore until trapped */
name|conesc
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"esctrp caught SIGQUIT"
argument_list|,
literal|""
argument_list|,
name|conesc
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|C70
end_ifdef

begin_function
name|SIGTYP
name|esctrp
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* trap console escapes (^\) */
name|conesc
operator|=
literal|1
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* ignore until trapped */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  C O N B G T  --  Background Test  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|jc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 = no job control */
end_comment

begin_comment
comment|/*   Call with flag == 1 to prevent signal test, which can not be expected   to work during file transfer, when SIGINT probably *is* set to SIG_IGN.      Call with flag == 0 to use the signal test, but only if the process-group   test fails, as it does on some UNIX systems, where getpgrp() is buggy,   requires an argument when the man page says it doesn't, or vice versa.     If flag == 0 and the process-group test fails, then we determine background   status simply (but not necessarily reliably) from isatty().    conbgt() sets the global backgrd = 1 if we appear to be in the background,   and to 0 if we seem to be in the foreground.  conbgt() is highly prone to   misbehavior. */
end_comment

begin_function
name|VOID
name|conbgt
parameter_list|(
name|flag
parameter_list|)
name|int
name|flag
decl_stmt|;
block|{
name|int
name|x
init|=
operator|-
literal|1
decl_stmt|,
comment|/* process group or SIGINT test */
name|y
init|=
literal|0
decl_stmt|;
comment|/* isatty() test */
comment|/*   Check for background operation, even if not running on real tty, so that   background flag can be set correctly.  If background status is detected,   then Kermit will not issue its interactive prompt or most messages.   If your prompt goes away, you can blame (and fix?) this function. */
comment|/* Use process-group test if possible. */
ifdef|#
directive|ifdef
name|POSIX
comment|/* We can do it in POSIX */
define|#
directive|define
name|PGROUP_T
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD4
comment|/* and in BSD 4.x. */
define|#
directive|define
name|PGROUP_T
else|#
directive|else
ifdef|#
directive|ifdef
name|HPUXJOBCTL
comment|/* and in most HP-UX's */
define|#
directive|define
name|PGROUP_T
else|#
directive|else
ifdef|#
directive|ifdef
name|TIOCGPGRP
comment|/* and anyplace that has this ioctl. */
define|#
directive|define
name|PGROUP_T
endif|#
directive|endif
comment|/* TIOCGPGRP */
endif|#
directive|endif
comment|/* HPUXJOBCTL */
endif|#
directive|endif
comment|/* BSD4 */
endif|#
directive|endif
comment|/* POSIX */
ifdef|#
directive|ifdef
name|MIPS
comment|/* Except if it doesn't work... */
undef|#
directive|undef
name|PGROUP_T
endif|#
directive|endif
comment|/* MIPS */
ifdef|#
directive|ifdef
name|PGROUP_T
comment|/*   Semi-reliable process-group test.  Check whether this process's group is   the same as the controlling terminal's process group.  This works if the   getpgrp() call doesn't lie (as it does in the SUNOS System V environment). */
name|PID_T
name|mypgrp
init|=
operator|(
name|PID_T
operator|)
literal|0
decl_stmt|;
comment|/* Kermit's process group */
name|PID_T
name|ctpgrp
init|=
operator|(
name|PID_T
operator|)
literal|0
decl_stmt|;
comment|/* The terminal's process group */
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
comment|/*   The getpgrp() prototype is obtained from system header files for POSIX    and Sys V R4 compilations.  Other systems, who knows.  Some complain about   a duplicate declaration here, others don't, so it's safer to leave it in   if we don't know for certain. */
ifndef|#
directive|ifndef
name|SVR4
ifndef|#
directive|ifndef
name|PS2AIX10
specifier|extern
name|PID_T
name|getpgrp
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* PS2AIX10 */
endif|#
directive|endif
comment|/* SVR4 */
endif|#
directive|endif
comment|/* _POSIX_SOURCE */
comment|/* Get my process group. */
ifdef|#
directive|ifdef
name|SVR3
comment|/* Maybe this should be ATTSV? */
comment|/* This function is not described in SVID R2 */
name|mypgrp
operator|=
name|getpgrp
argument_list|()
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ATTSV conbgt process group"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|mypgrp
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|POSIX
name|mypgrp
operator|=
name|getpgrp
argument_list|()
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"POSIX conbgt process group"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|mypgrp
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* BSD, V7, etc */
name|mypgrp
operator|=
name|getpgrp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"BSD conbgt process group"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|mypgrp
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* POSIX */
endif|#
directive|endif
comment|/* SVR3 */
comment|/* Now get controlling tty's process group */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
name|ctpgrp
operator|=
name|tcgetpgrp
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* The POSIX way */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"POSIX conbgt terminal process group"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|ctpgrp
argument_list|)
expr_stmt|;
else|#
directive|else
name|ioctl
argument_list|(
literal|1
argument_list|,
name|TIOCGPGRP
argument_list|,
operator|&
name|ctpgrp
argument_list|)
expr_stmt|;
comment|/* Or the BSD way */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"non-POSIX conbgt terminal process group"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|ctpgrp
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
if|if
condition|(
operator|(
name|mypgrp
operator|>
operator|(
name|PID_T
operator|)
literal|0
operator|)
operator|&&
operator|(
name|ctpgrp
operator|>
operator|(
name|PID_T
operator|)
literal|0
operator|)
condition|)
name|x
operator|=
operator|(
name|mypgrp
operator|==
name|ctpgrp
operator|)
condition|?
literal|0
else|:
literal|1
expr_stmt|;
comment|/* If they differ, then background. */
else|else
name|x
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* If error, remember. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conbgt process group test"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PGROUP_T */
comment|/* Try to see if job control is available */
ifdef|#
directive|ifdef
name|NOJC
comment|/* User override */
name|jc
operator|=
literal|0
expr_stmt|;
comment|/* No job control allowed */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"NOJC"
argument_list|,
literal|"jc"
argument_list|,
name|jc
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD44
name|jc
operator|=
literal|1
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|SVR4ORPOSIX
comment|/* POSIX actually tells us */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"SVR4ORPOSIX jc test..."
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_SC_JOB_CONTROL
ifdef|#
directive|ifdef
name|bsdi
name|jc
operator|=
literal|1
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|__386BSD__
name|jc
operator|=
literal|1
expr_stmt|;
else|#
directive|else
name|jc
operator|=
name|sysconf
argument_list|(
name|_SC_JOB_CONTROL
argument_list|)
expr_stmt|;
comment|/* Whatever system says */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"sysconf(_SC_JOB_CONTROL)"
argument_list|,
literal|"jc"
argument_list|,
name|jc
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __386BSD__ */
endif|#
directive|endif
comment|/* bsdi */
else|#
directive|else
ifdef|#
directive|ifdef
name|_POSIX_JOB_CONTROL
name|jc
operator|=
literal|1
expr_stmt|;
comment|/* By definition */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"_POSIX_JOB_CONTROL is defined"
argument_list|,
literal|"jc"
argument_list|,
name|jc
argument_list|)
expr_stmt|;
else|#
directive|else
name|jc
operator|=
literal|0
expr_stmt|;
comment|/* Assume job control not allowed */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"SVR4ORPOSIX _SC/POSIX_JOB_CONTROL not defined"
argument_list|,
literal|"jc"
argument_list|,
name|jc
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _POSIX_JOB_CONTROL */
endif|#
directive|endif
comment|/* _SC_JOB_CONTROL */
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD4
name|jc
operator|=
literal|1
expr_stmt|;
comment|/* Job control allowed */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"BSD job control"
argument_list|,
literal|"jc"
argument_list|,
name|jc
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|SVR3JC
name|jc
operator|=
literal|1
expr_stmt|;
comment|/* JC allowed */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"SVR3 job control"
argument_list|,
literal|"jc"
argument_list|,
name|jc
argument_list|)
expr_stmt|;
else|#
directive|else
name|jc
operator|=
literal|0
expr_stmt|;
comment|/* JC not allowed */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"job control catch-all"
argument_list|,
literal|"jc"
argument_list|,
name|jc
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SVR3JC */
endif|#
directive|endif
comment|/* BSD4 */
endif|#
directive|endif
comment|/* SVR4ORPOSIX */
endif|#
directive|endif
comment|/* BSD44 */
endif|#
directive|endif
comment|/* NOJC */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conbgt jc"
argument_list|,
literal|""
argument_list|,
name|jc
argument_list|)
expr_stmt|;
comment|/*   Another background test.   Test if SIGINT (terminal interrupt) is set to SIG_IGN (ignore),   which is done by the shell (sh) if the program is started with '&'.   Unfortunately, this is NOT done by csh or ksh so watch out!   Note, it's safe to set SIGINT to SIG_IGN here, because further down   we always set it to something else. */
if|if
condition|(
name|x
operator|<
literal|0
operator|&&
operator|!
name|flag
condition|)
block|{
comment|/* Didn't get good results above... */
name|SIGTYP
function_decl|(
modifier|*
name|osigint
function_decl|)
parameter_list|()
function_decl|;
name|osigint
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* What is SIGINT set to? */
name|x
operator|=
operator|(
name|osigint
operator|==
name|SIG_IGN
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
comment|/* SIG_IGN? */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conbgt osigint"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|osigint
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conbgt signal test"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
comment|/* Also check to see if we're running with redirected stdio. */
comment|/* This is not really background operation, but we want to act as though */
comment|/* it were. */
name|y
operator|=
operator|(
name|isatty
argument_list|(
literal|0
argument_list|)
operator|&&
name|isatty
argument_list|(
literal|1
argument_list|)
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conbgt isatty test"
argument_list|,
literal|""
argument_list|,
name|y
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD29
comment|/* The process group and/or signal test doesn't work under these... */
name|backgrd
operator|=
operator|!
name|y
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|sxaE50
name|backgrd
operator|=
operator|!
name|y
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|MINIX
name|backgrd
operator|=
operator|!
name|y
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|x
operator|>
operator|-
literal|1
condition|)
name|backgrd
operator|=
operator|(
name|x
operator|||
operator|!
name|y
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
else|else
name|backgrd
operator|=
operator|!
name|y
expr_stmt|;
endif|#
directive|endif
comment|/* BSD29 */
endif|#
directive|endif
comment|/* sxaE50 */
endif|#
directive|endif
comment|/* MINIX */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conbgt backgrd"
argument_list|,
literal|""
argument_list|,
name|backgrd
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  C O N I N T  --  Console Interrupt setter  */
end_comment

begin_comment
comment|/*   First arg is pointer to function to handle SIGTERM& SIGINT (like Ctrl-C).   Second arg is pointer to function to handle SIGTSTP (suspend). */
end_comment

begin_decl_stmt
name|VOID
comment|/* Set terminal interrupt traps. */
ifdef|#
directive|ifdef
name|CK_ANSIC
ifdef|#
directive|ifdef
name|apollo
name|conint
argument_list|(
name|f
argument_list|,
name|s
argument_list|)
name|SIGTYP
argument_list|(
operator|*
name|f
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|s
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|conint
argument_list|(
argument|SIGTYP (*f)(int)
argument_list|,
argument|SIGTYP (*s)(int)
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_else
else|#
directive|else
end_else

begin_macro
name|conint
argument_list|(
argument|f
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|SIGTYP
argument_list|(
operator|*
name|f
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|s
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_comment
comment|/* conint */
end_comment

begin_block
block|{
name|conbgt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Do background test. */
comment|/* Set the desired handlers for hangup and software termination. */
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Software termination */
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   Prior to edit 184, we used to trap SIGHUP here.  That is clearly wrong;   on some systems, it would leave the user's process on the terminal after   the phone hung up.  But the trap was here for a reason: most likely some   UNIX systems (init, getty, or login) fail to properly restore the terminal   modes after regaining control of a hung-up-upon login terminal.  Therefore   removing this trap is likely to cause problems too.  A more sensible   approach would be to use a special handler for HANGUP, which would restore   the terminal modes and then exit().  But that could leave zombie processes   around (like the lower CONNECT fork, or any fork started by zxcmd()), but   there is probably no clean, portable, reliable way for Kermit to kill all   its forks.  So we just exit() and hope that UNIX fixes the terminal modes   before the next person tries to log in. */
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Hangup */
endif|#
directive|endif
comment|/* COMMENT */
comment|/* Now handle keyboard stop, quit, and interrupt signals. */
comment|/* Check if invoked in background -- if so signals set to be ignored. */
comment|/* However, if running under a job control shell, don't ignore them. */
comment|/* We won't be getting any, as we aren't in the terminal's process group. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conint backgrd"
argument_list|,
literal|""
argument_list|,
name|backgrd
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conint jc"
argument_list|,
literal|""
argument_list|,
name|jc
argument_list|)
expr_stmt|;
if|if
condition|(
name|backgrd
operator|&&
operator|!
name|jc
condition|)
block|{
comment|/* In background, ignore signals */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conint background ignoring signals, jc"
argument_list|,
literal|""
argument_list|,
name|jc
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGTSTP
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Keyboard stop */
endif|#
directive|endif
comment|/* SIGTSTP */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Keyboard quit */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Keyboard interrupt */
block|}
else|else
block|{
comment|/* Else in foreground or suspended */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conint foreground catching signals, jc"
argument_list|,
literal|""
argument_list|,
name|jc
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Catch terminal interrupt */
ifdef|#
directive|ifdef
name|SIGTSTP
comment|/* Keyboard stop (suspend) */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conint SIGSTSTP"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
name|s
operator|=
name|SIG_DFL
expr_stmt|;
ifdef|#
directive|ifdef
name|NOJC
comment|/* No job control allowed. */
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Job control allowed */
if|if
condition|(
name|jc
condition|)
comment|/* if available. */
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|else
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOJC */
endif|#
directive|endif
comment|/* SIGTSTP */
ifdef|#
directive|ifdef
name|SVORPOSIX
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|esctrp
argument_list|)
expr_stmt|;
comment|/* Quit signal, Sys III/V. */
if|if
condition|(
name|conesc
condition|)
name|conesc
operator|=
literal|0
expr_stmt|;
comment|/* Clear out pending escapes */
else|#
directive|else
ifdef|#
directive|ifdef
name|V7
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|esctrp
argument_list|)
expr_stmt|;
comment|/* V7 like Sys III/V */
if|if
condition|(
name|conesc
condition|)
name|conesc
operator|=
literal|0
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|aegis
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Apollo, catch it like others. */
else|#
directive|else
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Others, ignore like 4D& earlier. */
endif|#
directive|endif
comment|/* aegis */
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* SVORPOSIX */
block|}
block|}
end_block

begin_comment
comment|/*  C O N N O I  --  Reset console terminal interrupts */
end_comment

begin_function
name|SIGTYP
comment|/* Dummy function to ignore signals */
ifdef|#
directive|ifdef
name|CK_ANSIC
name|sig_ign
parameter_list|(
name|int
name|foo
parameter_list|)
else|#
directive|else
function|sig_ign
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* sig_IGN */
block|{
comment|/* Just like the real one, but has  */
block|}
end_function

begin_comment
comment|/* different address. */
end_comment

begin_function
name|VOID
name|connoi
parameter_list|()
block|{
comment|/* Console-no-interrupts */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"connoi"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGTSTP
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGTSTP */
comment|/* Note the locally defined replacement for SIG_IGN that is used here */
comment|/* for the SIGINT setting.  This is done so that the Sys V background */
comment|/* test -- (signal(SIGINT,SIG_IGN) == SIG_IGN) -- can work.  If we use */
comment|/* the real SIG_IGN here, then conint will always decide that this */
comment|/* program is running in the background! */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|sig_ign
argument_list|)
expr_stmt|;
comment|/*<--- note! */
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  I N I T R A W Q  --  Set up to read /dev/kmem for character count.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_comment
comment|/*  Used in Version 7 to simulate Berkeley's FIONREAD ioctl call.  This  eliminates blocking on a read, because we can read /dev/kmem to get the  number of characters available for raw input.  If your system can't  or you won't let the world read /dev/kmem then you must figure out a  different way to do the counting of characters available, or else replace  this by a dummy function that always returns 0. */
end_comment

begin_comment
comment|/*  * Call this routine as: initrawq(tty)  * where tty is the file descriptor of a terminal.  It will return  * (as a char *) the kernel-mode memory address of the rawq character  * count, which may then be read.  It has the side-effect of flushing  * input on the terminal.  */
end_comment

begin_comment
comment|/*  * John Mackin, Physiology Dept., University of Sydney (Australia)  * ...!decvax!mulga!physiol.su.oz!john  *  * Permission is hereby granted to do anything with this code, as  * long as this comment is retained unmodified and no commercial  * advantage is gained.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MINIX
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|COHERENT
end_ifndef

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_include
include|#
directive|include
file|<l.out.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_function
name|char
modifier|*
name|initrawq
parameter_list|(
name|tty
parameter_list|)
name|int
name|tty
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|MINIX
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|UTS24
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD29
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
name|long
name|lseek
parameter_list|()
function_decl|;
specifier|static
name|struct
name|nlist
name|nl
index|[]
init|=
block|{
block|{
name|PROCNAME
block|}
block|,
block|{
name|NPROCNAME
block|}
block|,
block|{
literal|""
block|}
block|}
decl_stmt|;
specifier|static
name|struct
name|proc
modifier|*
name|pp
decl_stmt|;
name|char
modifier|*
name|qaddr
decl_stmt|,
modifier|*
name|p
decl_stmt|,
name|c
decl_stmt|;
name|int
name|m
decl_stmt|;
name|PID_T
name|pid
decl_stmt|,
name|me
decl_stmt|;
name|NPTYPE
name|xproc
decl_stmt|;
comment|/* Its type is defined in makefile. */
name|int
name|catch
parameter_list|()
function_decl|;
name|me
operator|=
name|getpid
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|m
operator|=
name|open
argument_list|(
literal|"/dev/kmem"
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|"kmem"
argument_list|)
expr_stmt|;
name|nlist
argument_list|(
name|BOOTNAME
argument_list|,
name|nl
argument_list|)
expr_stmt|;
if|if
condition|(
name|nl
index|[
literal|0
index|]
operator|.
name|n_type
operator|==
literal|0
condition|)
name|err
argument_list|(
literal|"proc array"
argument_list|)
expr_stmt|;
if|if
condition|(
name|nl
index|[
literal|1
index|]
operator|.
name|n_type
operator|==
literal|0
condition|)
name|err
argument_list|(
literal|"nproc"
argument_list|)
expr_stmt|;
name|lseek
argument_list|(
name|m
argument_list|,
call|(
name|long
call|)
argument_list|(
name|nl
index|[
literal|1
index|]
operator|.
name|n_value
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|read
argument_list|(
name|m
argument_list|,
operator|&
name|xproc
argument_list|,
sizeof|sizeof
argument_list|(
name|xproc
argument_list|)
argument_list|)
expr_stmt|;
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|catch
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pid
operator|=
name|fork
argument_list|()
operator|)
operator|==
literal|0
condition|)
block|{
while|while
condition|(
literal|1
condition|)
name|read
argument_list|(
name|tty
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|alarm
argument_list|(
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|jjbuf
argument_list|)
operator|==
literal|0
condition|)
block|{
while|while
condition|(
literal|1
condition|)
name|read
argument_list|(
name|tty
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DIRECT
name|pp
operator|=
operator|(
expr|struct
name|proc
operator|*
operator|)
name|nl
index|[
literal|0
index|]
operator|.
name|n_value
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|lseek
argument_list|(
name|m
argument_list|,
call|(
name|long
call|)
argument_list|(
name|nl
index|[
literal|0
index|]
operator|.
name|n_value
argument_list|)
argument_list|,
literal|0
argument_list|)
operator|<
literal|0L
condition|)
name|err
argument_list|(
literal|"seek"
argument_list|)
expr_stmt|;
if|if
condition|(
name|read
argument_list|(
name|m
argument_list|,
operator|&
name|pp
argument_list|,
sizeof|sizeof
argument_list|(
name|pp
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|pp
argument_list|)
condition|)
name|err
argument_list|(
literal|"no read of proc ptr"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|lseek
argument_list|(
name|m
argument_list|,
call|(
name|long
call|)
argument_list|(
name|nl
index|[
literal|1
index|]
operator|.
name|n_value
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|read
argument_list|(
name|m
argument_list|,
operator|&
name|xproc
argument_list|,
sizeof|sizeof
argument_list|(
name|xproc
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|m
argument_list|,
operator|(
name|long
operator|)
name|pp
argument_list|,
literal|0
argument_list|)
operator|<
literal|0L
condition|)
name|err
argument_list|(
literal|"Can't seek to proc"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|malloc
argument_list|(
name|xproc
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|proc
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|err
argument_list|(
literal|"malloc"
argument_list|)
expr_stmt|;
if|if
condition|(
name|read
argument_list|(
name|m
argument_list|,
name|p
argument_list|,
name|xproc
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|proc
argument_list|)
argument_list|)
operator|!=
name|xproc
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|proc
argument_list|)
condition|)
name|err
argument_list|(
literal|"read proc table"
argument_list|)
expr_stmt|;
for|for
control|(
name|pp
operator|=
operator|(
expr|struct
name|proc
operator|*
operator|)
name|p
init|;
name|xproc
operator|>
literal|0
condition|;
operator|--
name|xproc
operator|,
operator|++
name|pp
control|)
block|{
if|if
condition|(
name|pp
operator|->
name|p_pid
operator|==
operator|(
name|short
operator|)
name|pid
condition|)
goto|goto
name|iout
goto|;
block|}
name|err
argument_list|(
literal|"no such proc"
argument_list|)
expr_stmt|;
name|iout
label|:
name|close
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|qaddr
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|pp
operator|->
name|p_wchan
operator|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|pid
argument_list|,
name|SIGKILL
argument_list|)
expr_stmt|;
name|wait
argument_list|(
operator|(
name|WAIT_T
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|/* Destroy the ZOMBIEs! */
return|return
operator|(
name|qaddr
operator|)
return|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  More V7-support functions...  */
end_comment

begin_function
specifier|static
name|VOID
name|err
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
name|buf
index|[
literal|200
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"fatal error in initrawq: %s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|doexit
argument_list|(
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|VOID
name|catch
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
name|longjmp
argument_list|(
name|jjbuf
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  G E N B R K  --  Simulate a modem break.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_define
define|#
directive|define
name|BSPEED
value|B110
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BSPEED
value|B150
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_function
name|VOID
name|genbrk
parameter_list|(
name|fn
parameter_list|,
name|msec
parameter_list|)
name|int
name|fn
decl_stmt|,
name|msec
decl_stmt|;
block|{
name|struct
name|sgttyb
name|ttbuf
decl_stmt|;
name|int
name|ret
decl_stmt|,
name|sospeed
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|;
name|ret
operator|=
name|ioctl
argument_list|(
name|fn
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|ttbuf
argument_list|)
expr_stmt|;
name|sospeed
operator|=
name|ttbuf
operator|.
name|sg_ospeed
expr_stmt|;
name|ttbuf
operator|.
name|sg_ospeed
operator|=
name|BSPEED
expr_stmt|;
name|ret
operator|=
name|ioctl
argument_list|(
name|fn
argument_list|,
name|TIOCSETP
argument_list|,
operator|&
name|ttbuf
argument_list|)
expr_stmt|;
name|y
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|brnuls
argument_list|)
expr_stmt|;
name|x
operator|=
operator|(
name|BSPEED
operator|*
literal|100
operator|)
operator|/
name|msec
expr_stmt|;
if|if
condition|(
name|x
operator|>
name|y
condition|)
name|x
operator|=
name|y
expr_stmt|;
name|ret
operator|=
name|write
argument_list|(
name|fn
argument_list|,
name|brnuls
argument_list|,
operator|(
operator|(
name|BSPEED
operator|*
literal|100
operator|)
operator|/
name|msec
operator|)
argument_list|)
expr_stmt|;
name|ttbuf
operator|.
name|sg_ospeed
operator|=
name|sospeed
expr_stmt|;
name|ret
operator|=
name|ioctl
argument_list|(
name|fn
argument_list|,
name|TIOCSETP
argument_list|,
operator|&
name|ttbuf
argument_list|)
expr_stmt|;
name|ret
operator|=
name|write
argument_list|(
name|fn
argument_list|,
literal|"@"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  T T C H K  --  Tell how many characters are waiting in tty input buffer  */
end_comment

begin_comment
comment|/*  Some callers of this want to know whether there is something to read  *  either in the system buffers or in our private buffers (and mostly don't  *  care how many characters, just whether it's more than zero or not), while  *  some others would be better off with the number of characters in our  *  private buffers only.  *  *  Some systems can say how many characters there are in the system buffers.  *  Others can not. For those that can't, the number in the private buffers  *  will have to do (or should we put the tty into O_NDELAY-mode and try to  *  read one character?). If the system can tell whether there is zero or  *  more than zero characters, we can return 1 in the latter case even if the  *  private buffer is empty. (That is good for sliding windows.)  */
end_comment

begin_function
name|int
name|ttchk
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|PEEKTYPE
name|n
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   This was REALLY slowing TELNET connections down!  Just do the regular   ttyfd-based stuff here.  Let the VMS version call nettchk if it has to...   FIONREAD definitely works for TELNET, at least on the NeXT and SUNOS. */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
name|nettchk
argument_list|()
operator|)
return|;
endif|#
directive|endif
comment|/* NETCONN */
endif|#
directive|endif
comment|/* COMMENT */
ifdef|#
directive|ifdef
name|FIONREAD
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|n
argument_list|)
expr_stmt|;
comment|/* Berkeley and maybe some others */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttchk FIONREAD return code"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttchk FIONREAD count"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|n
operator|=
literal|0
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|V7
ifdef|#
directive|ifdef
name|MINIX
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
name|lseek
argument_list|(
name|kmem
index|[
name|TTY
index|]
argument_list|,
operator|(
name|long
operator|)
name|qaddr
index|[
name|TTY
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 7th Edition Unix */
name|x
operator|=
name|read
argument_list|(
name|kmem
index|[
name|TTY
index|]
argument_list|,
operator|&
name|n
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|!=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|)
name|n
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* MINIX */
else|#
directive|else
ifdef|#
directive|ifdef
name|PROVX1
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCQCNT
argument_list|,
operator|&
name|ttbuf
argument_list|)
expr_stmt|;
comment|/* Pro/3xx Venix V.1 */
name|n
operator|=
name|ttbuf
operator|.
name|sg_ispeed
operator|&
literal|0377
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|n
operator|=
literal|0
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|RDCHK
comment|/*   Last resort for systems without FIONREAD or equivalent, but with   something like rdchk(), like XENIX. */
if|if
condition|(
name|my_count
operator|==
literal|0
operator|&&
name|rdchk
argument_list|(
name|ttyfd
argument_list|)
operator|>
literal|0
condition|)
name|n
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttchk rdchk"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RDCHK */
endif|#
directive|endif
comment|/* PROVX1 */
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* FIONREAD */
ifdef|#
directive|ifdef
name|MYREAD
comment|/*   For myread() users, add the contents of myread()'s private buffer.   Sometimes, this is all there is to construct a result of ttchk() on. */
if|if
condition|(
name|my_count
operator|>
literal|0
condition|)
name|n
operator|+=
name|my_count
expr_stmt|;
endif|#
directive|endif
comment|/* MYREAD */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttchk returns"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  T T X I N  --  Get n characters from tty input buffer  */
end_comment

begin_comment
comment|/*  Returns number of characters actually gotten, or -1 on failure  */
end_comment

begin_comment
comment|/*  Intended for use only when it is known that n characters are actually */
end_comment

begin_comment
comment|/*  Available in the input buffer.  */
end_comment

begin_function
name|int
name|ttxin
parameter_list|(
name|n
parameter_list|,
name|buf
parameter_list|)
name|int
name|n
decl_stmt|;
name|CHAR
modifier|*
name|buf
decl_stmt|;
block|{
specifier|register
name|int
name|x
decl_stmt|,
name|c
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttxin n"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|<
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|ttpmsk
operator|=
operator|(
name|ttprty
operator|)
condition|?
literal|0177
else|:
literal|0377
expr_stmt|;
comment|/* Parity stripping mask. */
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|netconn
operator|&&
operator|(
name|ttnet
operator|==
name|NET_SX25
operator|)
condition|)
comment|/* X.25 connection */
return|return
operator|(
name|x25xin
argument_list|(
name|n
argument_list|,
name|buf
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* SUNX25 */
ifdef|#
directive|ifdef
name|MYREAD
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttxin MYREAD"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|c
operator|=
operator|-
literal|2
expr_stmt|;
for|for
control|(
name|x
operator|=
literal|0
init|;
operator|(
name|x
operator|>
operator|-
literal|1
operator|)
operator|&&
operator|(
name|x
operator|<
name|n
operator|)
operator|&&
operator|(
name|c
operator|=
name|myread
argument_list|()
operator|)
operator|>=
literal|0
condition|;
control|)
name|buf
index|[
name|x
operator|++
index|]
operator|=
name|c
operator|&
name|ttpmsk
expr_stmt|;
if|if
condition|(
name|c
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttxin myread returns"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
operator|-
literal|3
condition|)
name|x
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|#
directive|else
name|x
operator|=
name|read
argument_list|(
name|ttyfd
argument_list|,
name|buf
argument_list|,
name|n
argument_list|)
expr_stmt|;
for|for
control|(
name|c
operator|=
literal|0
init|;
name|c
operator|<
name|n
condition|;
name|c
operator|++
control|)
name|buf
index|[
name|c
index|]
operator|&=
name|ttpmsk
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" x"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MYREAD */
if|if
condition|(
name|x
operator|>
literal|0
condition|)
name|buf
index|[
name|x
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|x
operator|=
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  T T O L  --  Write string s, length n, to communication device.  */
end_comment

begin_comment
comment|/*   Returns:>= 0 on success, number of characters actually written.    -1 on failure. */
end_comment

begin_define
define|#
directive|define
name|TTOLMAXT
value|5
end_define

begin_function
name|int
name|ttol
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
name|CHAR
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|x
decl_stmt|,
name|len
decl_stmt|,
name|tries
decl_stmt|;
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Not open? */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttol n"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|tries
operator|=
name|TTOLMAXT
expr_stmt|;
comment|/* Allow up to this many tries */
name|len
operator|=
name|n
expr_stmt|;
comment|/* Remember original length */
while|while
condition|(
name|n
operator|>
literal|0
operator|&&
name|tries
operator|--
operator|>
literal|0
condition|)
block|{
comment|/* Be persistent */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttol try"
argument_list|,
literal|""
argument_list|,
name|TTOLMAXT
operator|-
name|tries
argument_list|)
expr_stmt|;
name|x
operator|=
name|write
argument_list|(
name|ttyfd
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
comment|/* Write string to device */
if|if
condition|(
name|x
operator|==
name|n
condition|)
block|{
comment|/* Worked? */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttol ok"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* OK */
return|return
operator|(
name|len
operator|)
return|;
comment|/* Done */
block|}
elseif|else
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
comment|/* No, got error? */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttol failed"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
block|{
comment|/* No error, so partial success */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttol partial"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|s
operator|+=
name|x
expr_stmt|;
comment|/* Point to part not written yet */
name|n
operator|-=
name|x
expr_stmt|;
comment|/* Adjust length */
if|if
condition|(
name|x
operator|>
literal|0
condition|)
name|msleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|/* Wait 100 msec */
block|}
comment|/* Go back and try again */
block|}
return|return
operator|(
name|n
operator|<
literal|1
condition|?
name|len
else|:
operator|-
literal|1
operator|)
return|;
comment|/* Too many tries */
block|}
end_function

begin_comment
comment|/*  T T O C  --  Output a character to the communication line  */
end_comment

begin_comment
comment|/*  This function should only be used for interactive, character-mode operations,  like terminal connection, script execution, dialer i/o, where the overhead  of the signals and alarms does not create a bottleneck. */
end_comment

begin_function
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|ttoc
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|ttoc
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* ttoc */
block|{
define|#
directive|define
name|TTOC_TMO
value|15
comment|/* Timeout in case we get stuck */
name|int
name|xx
decl_stmt|;
name|c
operator|&=
literal|0xff
expr_stmt|;
comment|/* debug(F101,"ttoc","",(CHAR) c); */
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Check for not open. */
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Enable timer interrupt */
name|xx
operator|=
name|alarm
argument_list|(
name|TTOC_TMO
argument_list|)
expr_stmt|;
comment|/* for this many seconds. */
if|if
condition|(
name|xx
operator|<
literal|0
condition|)
name|xx
operator|=
literal|0
expr_stmt|;
comment|/* Save old alarm value. */
comment|/* debug(F101,"ttoc alarm","",xx); */
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
block|{
comment|/* Timer went off? */
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Yes, cancel this alarm. */
if|if
condition|(
name|xx
operator|-
name|TTOC_TMO
operator|>
literal|0
condition|)
name|alarm
argument_list|(
name|xx
operator|-
name|TTOC_TMO
argument_list|)
expr_stmt|;
comment|/* Restore previous one */
comment|/* debug(F100,"ttoc timeout","",0); */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
operator|!
name|netconn
condition|)
block|{
endif|#
directive|endif
comment|/* NETCONN */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttoc timeout"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttflow
operator|==
name|FLO_XONX
condition|)
block|{
name|int
name|x
init|=
literal|0
decl_stmt|,
name|y
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttoc flow"
argument_list|,
literal|""
argument_list|,
name|ttflow
argument_list|)
expr_stmt|;
comment|/* Maybe we're xoff'd */
ifdef|#
directive|ifdef
name|POSIX
name|y
operator|=
name|tcflow
argument_list|(
name|ttyfd
argument_list|,
name|TCOON
argument_list|)
expr_stmt|;
comment|/* POSIX way to unstick. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttoc tcflow"
argument_list|,
literal|""
argument_list|,
name|y
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD4
comment|/* Berkeley way to do it. */
ifdef|#
directive|ifdef
name|TIOCSTART
comment|/* .... Used to be "ioctl(ttyfd, TIOCSTART, 0);".  Who knows? */
name|y
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSTART
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttoc TIOCSTART"
argument_list|,
literal|""
argument_list|,
name|y
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCSTART */
endif|#
directive|endif
comment|/* BSD4 */
comment|/* Is there a Sys V way to do this? */
endif|#
directive|endif
comment|/* POSIX */
block|}
ifdef|#
directive|ifdef
name|NETCONN
block|}
endif|#
directive|endif
comment|/* NETCONN */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Return failure code. */
block|}
else|else
block|{
if|if
condition|(
name|write
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
operator|<
literal|1
condition|)
block|{
comment|/* Try to write the character. */
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Failed, turn off the alarm. */
name|alarm
argument_list|(
name|xx
argument_list|)
expr_stmt|;
comment|/* Restore previous alarm. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttoc error"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|/* Log the error, */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* and return the error code. */
block|}
block|}
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Success, turn off the alarm. */
name|alarm
argument_list|(
name|xx
argument_list|)
expr_stmt|;
comment|/* Restore previous alarm. */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Return good code. */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  T T I N L  --  Read a record (up to break character) from comm line.  */
end_comment

begin_comment
comment|/*   Reads up to "max" characters from the communication line, terminating on:      (a) the packet length field if the "turn" argument is zero, or     (b) on the packet-end character (eol) if the "turn" argument is nonzero     (c) two Ctrl-C's in a row    and returns the number of characters read upon success, or if "max" was   exceeded or the timeout interval expired before (a) or (b), returns -1.    The characters that were input are copied into "dest" with their parity bits   stripped if parity was selected.  Returns the number of characters read.   Characters after the eol are available upon the next call to this function.    The idea is to minimize the number of system calls per packet, and also to   minimize timeouts.  This function is the inner loop of the program and must   be as efficient as possible.  The current strategy is to use myread().    WARNING: this function calls parchk(), which is defined in another module.   Normally, ckutio.c does not depend on code from any other module, but there   is an exception in this case because all the other ck?tio.c modules also   need to call parchk(), so it's better to have it defined in a common place.    Since this function has grown to have its fingers so deeply into the    protocol, it is slated for removal: rpack() will take care of everything. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CTRLC
end_ifdef

begin_undef
undef|#
directive|undef
name|CTRLC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRLC */
end_comment

begin_define
define|#
directive|define
name|CTRLC
value|'\03'
end_define

begin_comment
comment|/*   We have four different declarations here because:   (a) to allow Kermit to be built without the automatic parity sensing feature   (b) one of each type for ANSI C, one for non-ANSI. */
end_comment

begin_function
name|int
ifdef|#
directive|ifdef
name|PARSENSE
ifdef|#
directive|ifdef
name|CK_ANSIC
name|ttinl
parameter_list|(
name|CHAR
modifier|*
name|dest
parameter_list|,
name|int
name|max
parameter_list|,
name|int
name|timo
parameter_list|,
name|CHAR
name|eol
parameter_list|,
name|CHAR
name|start
parameter_list|,
name|int
name|turn
parameter_list|)
else|#
directive|else
function|ttinl
parameter_list|(
name|dest
parameter_list|,
name|max
parameter_list|,
name|timo
parameter_list|,
name|eol
parameter_list|,
name|start
parameter_list|,
name|turn
parameter_list|)
name|int
name|max
decl_stmt|,
name|timo
decl_stmt|,
name|turn
decl_stmt|;
name|CHAR
modifier|*
name|dest
decl_stmt|,
name|eol
decl_stmt|,
name|start
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
else|#
directive|else
comment|/* not PARSENSE */
ifdef|#
directive|ifdef
name|CK_ANSIC
function|ttinl
parameter_list|(
name|CHAR
modifier|*
name|dest
parameter_list|,
name|int
name|max
parameter_list|,
name|int
name|timo
parameter_list|,
name|CHAR
name|eol
parameter_list|)
else|#
directive|else
function|ttinl
parameter_list|(
name|dest
parameter_list|,
name|max
parameter_list|,
name|timo
parameter_list|,
name|eol
parameter_list|)
name|int
name|max
decl_stmt|,
name|timo
decl_stmt|;
name|CHAR
modifier|*
name|dest
decl_stmt|,
name|eol
decl_stmt|;
endif|#
directive|endif
comment|/* __SDTC__ */
endif|#
directive|endif
comment|/* PARSENSE */
comment|/* ttinl */
block|{
ifndef|#
directive|ifndef
name|MYREAD
name|CHAR
name|ch
decl_stmt|;
endif|#
directive|endif
comment|/* MYREAD */
ifdef|#
directive|ifdef
name|PARSENSE
name|int
name|pktlen
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|lplen
init|=
literal|0
decl_stmt|;
name|int
name|havelen
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
comment|/* PARSENSE */
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Not open. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl max"
argument_list|,
literal|""
argument_list|,
name|max
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl timo"
argument_list|,
literal|""
argument_list|,
name|timo
argument_list|)
expr_stmt|;
operator|*
name|dest
operator|=
literal|'\0'
expr_stmt|;
comment|/* Clear destination buffer */
if|if
condition|(
name|timo
operator|<
literal|0
condition|)
name|timo
operator|=
literal|0
expr_stmt|;
comment|/* Safety */
if|if
condition|(
name|timo
condition|)
block|{
comment|/* Don't time out if timo == 0 */
name|int
name|xx
decl_stmt|;
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Enable timer interrupt */
name|xx
operator|=
name|alarm
argument_list|(
name|timo
argument_list|)
expr_stmt|;
comment|/* Set it. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl alarm"
argument_list|,
literal|""
argument_list|,
name|xx
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
block|{
comment|/* Timer went off? */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ttinl timout"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Get here on timeout. */
comment|/* debug(F110," with",(char *) dest,0); */
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Turn off timer */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* and return error code. */
block|}
else|else
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|m
decl_stmt|,
name|n
decl_stmt|;
comment|/* local variables */
name|int
name|ccn
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|PARSENSE
name|int
name|flag
init|=
literal|0
decl_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"ttinl start"
argument_list|,
literal|""
argument_list|,
name|start
argument_list|)
expr_stmt|;
name|flag
operator|=
literal|0
expr_stmt|;
comment|/* Start of packet flag */
endif|#
directive|endif
comment|/* PARSENSE */
name|ttpmsk
operator|=
name|m
operator|=
operator|(
name|ttprty
operator|)
condition|?
literal|0177
else|:
literal|0377
expr_stmt|;
comment|/* Set parity stripping mask. */
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   No longer needed. */
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|netconn
operator|&&
operator|(
name|ttnet
operator|==
name|NET_SX25
operator|)
condition|)
ifdef|#
directive|ifdef
name|PARSENSE
return|return
operator|(
name|x25inl
argument_list|(
name|dest
argument_list|,
name|max
argument_list|,
name|timo
argument_list|,
name|eol
argument_list|,
name|start
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|x25inl
argument_list|(
name|dest
argument_list|,
name|max
argument_list|,
name|timo
argument_list|,
name|eol
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* PARSENSE */
endif|#
directive|endif
comment|/* SUNX25 */
endif|#
directive|endif
comment|/* COMMENT */
comment|/* Now read into destination, stripping parity and looking for the */
comment|/* the packet terminator, and also for two Ctrl-C's typed in a row. */
name|i
operator|=
literal|0
expr_stmt|;
comment|/* Destination index */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl eol"
argument_list|,
literal|""
argument_list|,
name|eol
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MYREAD
while|while
condition|(
name|i
operator|<
name|max
operator|-
literal|1
condition|)
block|{
comment|/* debug(F101,"ttinl i","",i); */
if|if
condition|(
operator|(
name|n
operator|=
name|myread
argument_list|()
operator|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl myread failure, n"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl myread errno,"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|/* Don't let EINTR break packets. */
if|if
condition|(
name|n
operator|==
operator|-
literal|3
operator|&&
name|errno
operator|==
name|EINTR
operator|&&
name|i
operator|>
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl myread i"
argument_list|,
literal|""
argument_list|,
name|i
argument_list|)
expr_stmt|;
continue|continue;
block|}
break|break;
block|}
else|#
directive|else
while|while
condition|(
operator|(
name|i
operator|<
name|max
operator|-
literal|1
operator|)
operator|&&
operator|(
name|n
operator|=
name|read
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ch
argument_list|,
literal|1
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
name|n
operator|=
name|ch
expr_stmt|;
endif|#
directive|endif
comment|/* MYREAD */
comment|/* debug(F101,"ttinl char","", (n& ttpmsk)); */
ifdef|#
directive|ifdef
name|PARSENSE
comment|/*   Figure out what the length is supposed to be in case the packet   has no terminator (as with Honeywell GCOS-8 Kermit). */
ifndef|#
directive|ifndef
name|xunchar
define|#
directive|define
name|xunchar
parameter_list|(
name|ch
parameter_list|)
value|(((ch) - 32 )& 0xFF )
comment|/* Character to number */
endif|#
directive|endif
comment|/* xunchar */
if|if
condition|(
operator|(
name|flag
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|(
name|n
operator|&
literal|0x7f
operator|)
operator|==
name|start
operator|)
condition|)
name|flag
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|flag
condition|)
name|dest
index|[
name|i
operator|++
index|]
operator|=
name|n
operator|&
name|ttpmsk
expr_stmt|;
comment|/*   If we have not been instructed to wait for a turnaround character, we   can go by the packet length field.  If turn != 0, we must wait for the   end of line (eol) character before returning. */
if|if
condition|(
name|i
operator|==
literal|2
condition|)
block|{
name|pktlen
operator|=
name|xunchar
argument_list|(
name|dest
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|havelen
operator|=
operator|(
name|pktlen
operator|>
literal|1
operator|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl length"
argument_list|,
literal|""
argument_list|,
name|pktlen
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|i
operator|==
literal|5
operator|&&
name|pktlen
operator|==
literal|0
condition|)
block|{
name|lplen
operator|=
name|xunchar
argument_list|(
name|dest
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|i
operator|==
literal|6
operator|&&
name|pktlen
operator|==
literal|0
condition|)
block|{
name|pktlen
operator|=
name|lplen
operator|*
literal|95
operator|+
name|xunchar
argument_list|(
name|dest
index|[
literal|5
index|]
argument_list|)
operator|+
literal|5
expr_stmt|;
name|havelen
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl length"
argument_list|,
literal|""
argument_list|,
name|pktlen
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|dest
index|[
name|i
operator|++
index|]
operator|=
name|n
operator|&
name|ttpmsk
expr_stmt|;
endif|#
directive|endif
comment|/* PARSENSE */
if|if
condition|(
operator|(
name|n
operator|&
literal|0x7f
operator|)
operator|==
name|CTRLC
condition|)
block|{
comment|/* Check for ^C^C */
if|if
condition|(
operator|++
name|ccn
operator|>
literal|1
condition|)
block|{
comment|/* If we got 2 in a row, bail out. */
if|if
condition|(
name|timo
condition|)
block|{
comment|/* Clear timer. */
name|ttimoff
argument_list|()
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"^C...\r\n"
argument_list|)
expr_stmt|;
comment|/* Echo Ctrl-C */
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
block|}
else|else
name|ccn
operator|=
literal|0
expr_stmt|;
comment|/* Not ^C, so reset ^C counter, */
ifdef|#
directive|ifdef
name|PARSENSE
if|if
condition|(
name|flag
operator|==
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl skipping"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
continue|continue;
block|}
endif|#
directive|endif
comment|/* PARSENSE */
comment|/* Check for end of packet */
if|if
condition|(
operator|(
operator|(
name|n
operator|&
literal|0x7f
operator|)
operator|==
name|eol
operator|)
ifdef|#
directive|ifdef
name|PARSENSE
operator|||
operator|(
operator|!
name|turn
operator|&&
name|havelen
operator|&&
operator|(
name|i
operator|>
name|pktlen
operator|+
literal|1
operator|)
operator|)
endif|#
directive|endif
comment|/* PARSENSE */
condition|)
block|{
ifndef|#
directive|ifndef
name|PARSENSE
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl got eol"
argument_list|,
literal|""
argument_list|,
name|eol
argument_list|)
expr_stmt|;
name|dest
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Yes, terminate the string, */
comment|/* debug(F101,"ttinl i","",i); */
else|#
directive|else
if|if
condition|(
operator|(
name|n
operator|&
literal|0x7f
operator|)
operator|!=
name|eol
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl EOP length"
argument_list|,
literal|""
argument_list|,
name|pktlen
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl i"
argument_list|,
literal|""
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
else|else
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl got eol"
argument_list|,
literal|""
argument_list|,
name|eol
argument_list|)
expr_stmt|;
name|dest
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate the string, */
comment|/* Parity checked yet? */
if|if
condition|(
name|ttpflg
operator|++
operator|==
literal|0
operator|&&
name|ttprty
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|ttprty
operator|=
name|parchk
argument_list|(
name|dest
argument_list|,
name|start
argument_list|,
name|i
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
comment|/* No, check. */
name|int
name|j
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttinl senses parity"
argument_list|,
literal|""
argument_list|,
name|ttprty
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ttinl packet before"
argument_list|,
name|dest
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttpmsk
operator|=
literal|0x7f
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|i
condition|;
name|j
operator|++
control|)
name|dest
index|[
name|j
index|]
operator|&=
literal|0x7f
expr_stmt|;
comment|/* Strip parity from packet */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ttinl packet after "
argument_list|,
name|dest
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
name|ttprty
operator|=
literal|0
expr_stmt|;
comment|/* restore if parchk error */
block|}
endif|#
directive|endif
comment|/* PARSENSE */
if|if
condition|(
name|timo
condition|)
block|{
comment|/* Turn off timer. */
name|ttimoff
argument_list|()
expr_stmt|;
block|}
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttinl got"
argument_list|,
name|dest
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
operator|(
name|i
operator|)
return|;
block|}
block|}
comment|/* end of while() */
name|ttimoff
argument_list|()
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
comment|/*  T T I N C --  Read a character from the communication line  */
comment|/*  On success, returns the character that was read,>= 0.  On failure, returns -1 or other negative myread error code. */
name|int
name|ttinc
parameter_list|(
name|timo
parameter_list|)
name|int
name|timo
decl_stmt|;
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
ifndef|#
directive|ifndef
name|MYREAD
name|CHAR
name|ch
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
comment|/* MYREAD */
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Not open. */
if|if
condition|(
name|timo
operator|<=
literal|0
condition|)
block|{
comment|/* Untimed. */
ifdef|#
directive|ifdef
name|MYREAD
comment|/* comm line failure returns -1 thru myread, so no&= 0377 */
name|n
operator|=
name|myread
argument_list|()
expr_stmt|;
comment|/* Wait for a character... */
comment|/* debug(F101,"ttinc MYREAD n","",n); */
return|return
operator|(
name|n
operator|<
literal|0
condition|?
name|n
else|:
name|n
operator|&
name|ttpmsk
operator|)
return|;
else|#
directive|else
while|while
condition|(
operator|(
name|n
operator|=
name|read
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ch
argument_list|,
literal|1
argument_list|)
operator|)
operator|==
literal|0
condition|)
comment|/* Wait for a character. */
comment|/* Shouldn't have to loop in ver 5A. */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
block|{
comment|/* Special handling for net */
name|netclos
argument_list|()
expr_stmt|;
comment|/* If read() returns 0 it means */
name|netconn
operator|=
literal|0
expr_stmt|;
comment|/* the connection has dropped. */
name|errno
operator|=
name|ENOTCONN
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* NETCONN */
empty_stmt|;
comment|/* debug(F000,"ttinc","",ch); */
return|return
operator|(
operator|(
name|n
operator|<
literal|1
operator|)
condition|?
operator|-
literal|3
else|:
operator|(
name|ch
operator|&
name|ttpmsk
operator|)
operator|)
return|;
endif|#
directive|endif
comment|/* MYREAD */
block|}
else|else
block|{
comment|/* Timed read */
name|int
name|xx
decl_stmt|;
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Set up handler, save old one. */
name|xx
operator|=
name|alarm
argument_list|(
name|timo
argument_list|)
expr_stmt|;
comment|/* Set alarm, save old one. */
comment|/* debug(F101,"ttinc alarm","",xx); */
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
block|{
comment|/* Timer expired */
name|n
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* set flag */
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|MYREAD
name|n
operator|=
name|myread
argument_list|()
expr_stmt|;
comment|/* If managing own buffer... */
comment|/* debug(F101,"ttinc myread","",n); */
else|#
directive|else
name|n
operator|=
name|read
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ch
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Otherwise call the system. */
comment|/* debug(F101,"ttinc read","",n); */
if|if
condition|(
name|n
operator|>
literal|0
condition|)
name|n
operator|=
name|ch
operator|&
literal|255
expr_stmt|;
else|else
name|n
operator|=
operator|(
name|n
operator|<
literal|0
operator|)
condition|?
operator|-
literal|3
else|:
operator|-
literal|2
expr_stmt|;
comment|/* Special return codes. */
endif|#
directive|endif
comment|/* MYREAD */
block|}
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Turn off the timer */
comment|/* #ifdef COMMENT */
if|if
condition|(
name|n
operator|==
operator|-
literal|1
condition|)
name|xx
operator|-=
name|timo
expr_stmt|;
comment|/* and restore any previous alarm */
if|if
condition|(
name|xx
operator|<
literal|0
condition|)
name|xx
operator|=
literal|0
expr_stmt|;
comment|/* adjusted by timeout interval */
name|alarm
argument_list|(
name|xx
argument_list|)
expr_stmt|;
comment|/* if timer expired. */
comment|/* #endif */
comment|/* COMMENT */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
block|{
if|if
condition|(
name|n
operator|==
operator|-
literal|2
condition|)
block|{
comment|/* read() returns 0 */
name|netclos
argument_list|()
expr_stmt|;
comment|/* on network read failure */
name|netconn
operator|=
literal|0
expr_stmt|;
name|errno
operator|=
name|ENOTCONN
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* NETCONN */
return|return
operator|(
operator|(
name|n
operator|<
literal|0
operator|)
condition|?
name|n
else|:
operator|(
name|n
operator|&
name|ttpmsk
operator|)
operator|)
return|;
comment|/* Return masked char or neg. */
block|}
block|}
comment|/*  S N D B R K  --  Send a BREAK signal of the given duration  */
specifier|static
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|sndbrk
parameter_list|(
name|int
name|msec
parameter_list|)
block|{
comment|/* Argument is milliseconds */
else|#
directive|else
name|sndbrk
argument_list|(
argument|msec
argument_list|)
name|int
name|msec
decl_stmt|;
block|{
endif|#
directive|endif
comment|/* CK_ANSIC */
ifndef|#
directive|ifndef
name|POSIX
name|int
name|x
decl_stmt|,
name|n
decl_stmt|;
endif|#
directive|endif
comment|/* POSIX */
ifdef|#
directive|ifdef
name|ANYBSD
define|#
directive|define
name|BSDBREAK
endif|#
directive|endif
comment|/* ANYBSD */
ifdef|#
directive|ifdef
name|BSD44
define|#
directive|define
name|BSDBREAK
endif|#
directive|endif
comment|/* BSD44 */
ifdef|#
directive|ifdef
name|COHERENT
define|#
directive|define
name|BSDBREAK
endif|#
directive|endif
comment|/* COHERENT */
ifdef|#
directive|ifdef
name|PROVX1
name|char
name|spd
decl_stmt|;
endif|#
directive|endif
comment|/* PROVX1 */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttsndb ttyfd"
argument_list|,
literal|""
argument_list|,
name|ttyfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Not open. */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|netconn
condition|)
comment|/* Send network BREAK */
return|return
operator|(
name|netbreak
argument_list|()
operator|)
return|;
endif|#
directive|endif
comment|/* NETCONN */
if|if
condition|(
name|msec
operator|<
literal|1
operator|||
name|msec
operator|>
literal|5000
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Bad argument */
ifdef|#
directive|ifdef
name|POSIX
comment|/* Easy in POSIX */
return|return
operator|(
name|tcsendbreak
argument_list|(
name|ttyfd
argument_list|,
name|msec
operator|/
literal|375
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|PROVX1
name|gtty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttbuf
argument_list|)
expr_stmt|;
comment|/* Get current tty flags */
name|spd
operator|=
name|ttbuf
operator|.
name|sg_ospeed
expr_stmt|;
comment|/* Save speed */
name|ttbuf
operator|.
name|sg_ospeed
operator|=
name|B50
expr_stmt|;
comment|/* Change to 50 baud */
name|stty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttbuf
argument_list|)
expr_stmt|;
comment|/*  ... */
name|n
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|brnuls
argument_list|)
expr_stmt|;
comment|/* Send the right number of nulls */
name|x
operator|=
name|msec
operator|/
literal|91
expr_stmt|;
if|if
condition|(
name|x
operator|>
name|n
condition|)
name|x
operator|=
name|n
expr_stmt|;
name|write
argument_list|(
name|ttyfd
argument_list|,
name|brnuls
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|ttbuf
operator|.
name|sg_ospeed
operator|=
name|spd
expr_stmt|;
comment|/* Restore speed */
name|stty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttbuf
argument_list|)
expr_stmt|;
comment|/*  ... */
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|aegis
name|sio_$control
argument_list|(
operator|(
name|short
operator|)
name|ttyfd
argument_list|,
name|sio_$send_break
argument_list|,
name|msec
argument_list|,
name|st
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|BSDBREAK
name|n
operator|=
name|FWRITE
expr_stmt|;
comment|/* Flush output queue. */
comment|/* Watch out for int vs long problems in&n arg! */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCFLUSH
argument_list|,
operator|&
name|n
argument_list|)
expr_stmt|;
comment|/* Ignore any errors.. */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSBRK
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Turn on BREAK */
name|perror
argument_list|(
literal|"Can't send BREAK"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|x
operator|=
name|msleep
argument_list|(
name|msec
argument_list|)
expr_stmt|;
comment|/* Sleep for so many milliseconds */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCCBRK
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Turn off BREAK */
name|perror
argument_list|(
literal|"BREAK stuck!!!"
argument_list|)
expr_stmt|;
name|doexit
argument_list|(
name|BAD_EXIT
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* Get out, closing the line. */
comment|/*   with bad exit status */
block|}
return|return
operator|(
name|x
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATTSV
comment|/*   No way to send a long BREAK in Sys V, so send a bunch of regular ones.   (Actually, Sys V R4 is *supposed* to have the POSIX tcsendbreak() function,   but there's no way for this code to know for sure.) */
name|x
operator|=
name|msec
operator|/
literal|275
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|x
condition|;
name|n
operator|++
control|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSBRK
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"Can't send BREAK"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|V7
return|return
operator|(
name|genbrk
argument_list|(
name|ttyfd
argument_list|,
literal|250
argument_list|)
operator|)
return|;
comment|/* Simulate a BREAK */
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* BSDBREAK */
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* aegis */
endif|#
directive|endif
comment|/* PROVX1 */
endif|#
directive|endif
comment|/* POSIX */
block|}
comment|/*  T T S N D B  --  Send a BREAK signal  */
name|int
name|ttsndb
parameter_list|()
block|{
return|return
operator|(
name|sndbrk
argument_list|(
literal|275
argument_list|)
operator|)
return|;
block|}
comment|/*  T T S N D L B  --  Send a Long BREAK signal  */
name|int
name|ttsndlb
parameter_list|()
block|{
return|return
operator|(
name|sndbrk
argument_list|(
literal|1500
argument_list|)
operator|)
return|;
block|}
comment|/*  M S L E E P  --  Millisecond version of sleep().  */
comment|/*   Call with number of milliseconds (thousandths of seconds) to sleep.   Intended only for small intervals.  For big ones, just use sleep().   Highly system-dependent.   Returns 0 always, even if it didn't work. */
comment|/* Define MSLFTIME for systems that must use an ftime() loop. */
ifdef|#
directive|ifdef
name|ANYBSD
comment|/* For pre-4.2 BSD versions */
ifndef|#
directive|ifndef
name|BSD4
define|#
directive|define
name|MSLFTIME
endif|#
directive|endif
comment|/* BSD4 */
endif|#
directive|endif
comment|/* ANYBSD */
ifdef|#
directive|ifdef
name|TOWER1
comment|/* NCR Tower OS 1.0 */
define|#
directive|define
name|MSLFTIME
endif|#
directive|endif
comment|/* TOWER1 */
ifdef|#
directive|ifdef
name|COHERENT
comment|/* Coherent */
ifndef|#
directive|ifndef
name|_I386
define|#
directive|define
name|MSLFTIME
endif|#
directive|endif
comment|/* _I386 */
endif|#
directive|endif
comment|/* COHERENT */
name|int
name|msleep
parameter_list|(
name|m
parameter_list|)
name|int
name|m
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|USLEEP
ifdef|#
directive|ifdef
name|SUNOS4
comment|/* Systems that have usleep() */
define|#
directive|define
name|USLEEP
endif|#
directive|endif
comment|/* SUNOS4 */
ifdef|#
directive|ifdef
name|SUN4S5
define|#
directive|define
name|USLEEP
endif|#
directive|endif
comment|/* SUN4S5 */
ifdef|#
directive|ifdef
name|NEXT
define|#
directive|define
name|USLEEP
endif|#
directive|endif
comment|/* NEXT*/
endif|#
directive|endif
comment|/* USLEEP */
ifdef|#
directive|ifdef
name|AIXRS
comment|/* RS/6000 can do select() */
define|#
directive|define
name|BSD42
endif|#
directive|endif
comment|/* AIXRS */
ifndef|#
directive|ifndef
name|SELECT
ifdef|#
directive|ifdef
name|BSD44
define|#
directive|define
name|SELECT
endif|#
directive|endif
comment|/* BSD44 */
ifdef|#
directive|ifdef
name|BSD42
define|#
directive|define
name|SELECT
endif|#
directive|endif
comment|/* BSD42 */
endif|#
directive|endif
comment|/* SELECT */
ifdef|#
directive|ifdef
name|SELECT
comment|/* BSD 4.2& above can do it with select()... */
name|int
name|t1
decl_stmt|;
if|if
condition|(
name|m
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|m
operator|>=
literal|1000
condition|)
block|{
comment|/* Catch big arguments. */
name|sleep
argument_list|(
name|m
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|m
operator|=
name|m
operator|%
literal|1000
expr_stmt|;
if|if
condition|(
name|m
operator|<
literal|10
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|tz
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Get current time. */
name|t1
operator|=
name|tv
operator|.
name|tv_sec
expr_stmt|;
comment|/* Seconds */
name|tv
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
comment|/* Use select() */
name|tv
operator|.
name|tv_usec
operator|=
name|m
operator|*
literal|1000L
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD44
name|select
argument_list|(
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD43
name|select
argument_list|(
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
else|#
directive|else
name|select
argument_list|(
literal|0
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD43 */
endif|#
directive|endif
comment|/* BSD44 */
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
comment|/* Not SELECT */
ifdef|#
directive|ifdef
name|USLEEP
comment|/*   "This routine is implemented using setitimer(2); it requires eight   system calls...".  In other words, it might take 5 minutes to sleep   for 100 milliseconds... */
if|if
condition|(
name|m
operator|>=
literal|1000
condition|)
block|{
comment|/* Catch big arguments. */
name|sleep
argument_list|(
name|m
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|m
operator|=
name|m
operator|%
literal|1000
expr_stmt|;
if|if
condition|(
name|m
operator|<
literal|10
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|usleep
argument_list|(
call|(
name|unsigned
name|int
call|)
argument_list|(
name|m
operator|*
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|aegis
name|time_$clock_t
name|dur
decl_stmt|;
name|dur
operator|.
name|c2
operator|.
name|high16
operator|=
literal|0
expr_stmt|;
name|dur
operator|.
name|c2
operator|.
name|low32
operator|=
literal|250
operator|*
name|m
expr_stmt|;
comment|/* one millisecond = 250 four microsecond ticks */
name|time_$wait
argument_list|(
name|time_$relative
argument_list|,
name|dur
argument_list|,
name|st
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|PROVX1
if|if
condition|(
name|m
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|sleep
argument_list|(
operator|-
operator|(
operator|(
name|m
operator|*
literal|60
operator|+
literal|500
operator|)
operator|/
literal|1000
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|NAP
name|nap
argument_list|(
operator|(
name|long
operator|)
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATTSV
ifndef|#
directive|ifndef
name|BSD44
specifier|extern
name|long
name|times
parameter_list|()
function_decl|;
comment|/* Or #include<times.h> ? */
endif|#
directive|endif
comment|/* BSD44 */
name|long
name|t1
decl_stmt|,
name|t2
decl_stmt|,
name|tarray
index|[
literal|4
index|]
decl_stmt|;
name|int
name|t3
decl_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
comment|/* This better be picked up in ckcdeb.h... */
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* COMMENT */
name|char
modifier|*
name|cp
init|=
name|getenv
argument_list|(
literal|"HZ"
argument_list|)
decl_stmt|;
name|int
name|CLOCK_TICK
decl_stmt|;
name|int
name|hertz
decl_stmt|;
if|if
condition|(
name|cp
operator|&&
operator|(
name|hertz
operator|=
name|atoi
argument_list|(
name|cp
argument_list|)
operator|)
condition|)
block|{
name|CLOCK_TICK
operator|=
literal|1000
operator|/
name|hertz
expr_stmt|;
block|}
else|else
block|{
comment|/* probably single user mode */
ifdef|#
directive|ifdef
name|HZ
name|CLOCK_TICK
operator|=
literal|1000
operator|/
name|HZ
expr_stmt|;
else|#
directive|else
specifier|static
name|warned
operator|=
literal|0
expr_stmt|;
comment|/* HZ always exists in, for instance, SCO Xenix, so you don't have to 	 * make special #ifdefs for XENIX here, like in ver 4F. Also, if you 	 * have Xenix, you have should have nap(), so the best is to use -DNAP 	 * in the makefile. Most systems have HZ. 	 */
name|CLOCK_TICK
operator|=
literal|17
expr_stmt|;
comment|/* 1/60 sec */
if|if
condition|(
operator|!
name|warned
condition|)
block|{
name|printf
argument_list|(
literal|"warning: environment variable HZ bad... using HZ=%d\r\n"
argument_list|,
literal|1000
operator|/
name|CLOCK_TICK
argument_list|)
expr_stmt|;
name|warned
operator|=
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* !HZ */
block|}
if|if
condition|(
name|m
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|m
operator|>=
literal|1000
condition|)
block|{
comment|/* Catch big arguments. */
name|sleep
argument_list|(
name|m
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|m
operator|=
name|m
operator|%
literal|1000
expr_stmt|;
if|if
condition|(
name|m
operator|<
literal|10
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|t1
operator|=
name|times
argument_list|(
name|tarray
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
operator|(
name|t2
operator|=
name|times
argument_list|(
name|tarray
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|t3
operator|=
operator|(
call|(
name|int
call|)
argument_list|(
name|t2
operator|-
name|t1
argument_list|)
operator|)
operator|*
name|CLOCK_TICK
expr_stmt|;
if|if
condition|(
name|t3
operator|>
name|m
condition|)
return|return
operator|(
name|t3
operator|)
return|;
block|}
else|#
directive|else
comment|/* Not ATTSV */
ifdef|#
directive|ifdef
name|MSLFTIME
comment|/* Use ftime() loop... */
name|int
name|t1
decl_stmt|,
name|t3
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|m
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|m
operator|>=
literal|1000
condition|)
block|{
comment|/* Catch big arguments. */
name|sleep
argument_list|(
name|m
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|m
operator|=
name|m
operator|%
literal|1000
expr_stmt|;
if|if
condition|(
name|m
operator|<
literal|10
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|ftime
argument_list|(
operator|&
name|ftp
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Get base time. */
name|t1
operator|=
operator|(
operator|(
name|ftp
operator|.
name|time
operator|&
literal|0xff
operator|)
operator|*
literal|1000
operator|)
operator|+
name|ftp
operator|.
name|millitm
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|ftime
argument_list|(
operator|&
name|ftp
argument_list|)
expr_stmt|;
comment|/* Get current time and compare. */
name|t3
operator|=
operator|(
operator|(
operator|(
name|ftp
operator|.
name|time
operator|&
literal|0xff
operator|)
operator|*
literal|1000
operator|)
operator|+
name|ftp
operator|.
name|millitm
operator|)
operator|-
name|t1
expr_stmt|;
if|if
condition|(
name|t3
operator|>
name|m
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|#
directive|else
comment|/* This includes true POSIX, which has no way to do this. */
if|if
condition|(
name|m
operator|>=
literal|1000
condition|)
block|{
comment|/* Catch big arguments. */
name|sleep
argument_list|(
name|m
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|m
operator|=
name|m
operator|%
literal|1000
expr_stmt|;
if|if
condition|(
name|m
operator|<
literal|10
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|m
operator|>
literal|0
condition|)
while|while
condition|(
name|m
operator|>
literal|0
condition|)
name|m
operator|--
expr_stmt|;
comment|/* Just a dumb busy loop */
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* MSLFTIME */
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* NAP */
endif|#
directive|endif
comment|/* PROVX1 */
endif|#
directive|endif
comment|/* aegis */
endif|#
directive|endif
comment|/* SELECT */
endif|#
directive|endif
comment|/* USLEEP */
block|}
comment|/*  R T I M E R --  Reset elapsed time counter  */
name|VOID
name|rtimer
parameter_list|()
block|{
name|tcount
operator|=
name|time
argument_list|(
operator|(
name|time_t
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/*  G T I M E R --  Get current value of elapsed time counter in seconds  */
name|int
name|gtimer
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|x
operator|=
call|(
name|int
call|)
argument_list|(
name|time
argument_list|(
operator|(
name|time_t
operator|*
operator|)
literal|0
argument_list|)
operator|-
name|tcount
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"gtimer"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|x
operator|<
literal|0
operator|)
condition|?
literal|0
else|:
name|x
operator|)
return|;
block|}
comment|/*  Z T I M E  --  Return date/time string  */
name|VOID
name|ztime
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
modifier|*
name|s
decl_stmt|;
block|{
undef|#
directive|undef
name|ZTIMEV7
comment|/* Which systems need to use */
ifdef|#
directive|ifdef
name|COHERENT
comment|/* old UNIX Version 7 way... */
define|#
directive|define
name|ZTIMEV7
endif|#
directive|endif
comment|/* COHERENT */
ifdef|#
directive|ifdef
name|TOWER1
define|#
directive|define
name|ZTIMEV7
endif|#
directive|endif
comment|/* TOWER1 */
ifdef|#
directive|ifdef
name|ANYBSD
ifndef|#
directive|ifndef
name|BSD42
define|#
directive|define
name|ZTIMEV7
endif|#
directive|endif
comment|/* BSD42 */
endif|#
directive|endif
comment|/* ANYBSD */
ifdef|#
directive|ifdef
name|V7
ifndef|#
directive|ifndef
name|MINIX
define|#
directive|define
name|ZTIMEV7
endif|#
directive|endif
comment|/* MINIX */
endif|#
directive|endif
comment|/* V7 */
ifdef|#
directive|ifdef
name|POSIX
define|#
directive|define
name|ZTIMEV7
endif|#
directive|endif
comment|/* POSIX */
ifdef|#
directive|ifdef
name|ATTSV
comment|/* AT&T way */
comment|/*  extern long time(); */
comment|/* Theoretically these should */
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
comment|/* already been dcl'd in<time.h> */
name|long
name|clock_storage
decl_stmt|;
name|clock_storage
operator|=
name|time
argument_list|(
operator|(
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
operator|*
name|s
operator|=
name|ctime
argument_list|(
operator|&
name|clock_storage
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|PROVX1
comment|/* Venix 1.0 way */
name|int
name|utime
index|[
literal|2
index|]
decl_stmt|;
name|time
argument_list|(
name|utime
argument_list|)
expr_stmt|;
operator|*
name|s
operator|=
name|ctime
argument_list|(
name|utime
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD42
comment|/* 4.2BSD way */
name|char
modifier|*
name|asctime
parameter_list|()
function_decl|;
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
name|struct
name|tm
modifier|*
name|tp
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|tz
argument_list|)
expr_stmt|;
name|time
argument_list|(
operator|&
name|tv
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
name|tp
operator|=
name|localtime
argument_list|(
operator|&
name|tv
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
operator|*
name|s
operator|=
name|asctime
argument_list|(
name|tp
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|MINIX
comment|/* MINIX way */
ifdef|#
directive|ifdef
name|COMMENT
specifier|extern
name|long
name|time
parameter_list|()
function_decl|;
comment|/* Already got these from<time.h> */
specifier|extern
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* COMMENT */
name|time_t
name|utime
index|[
literal|2
index|]
decl_stmt|;
name|time
argument_list|(
name|utime
argument_list|)
expr_stmt|;
operator|*
name|s
operator|=
name|ctime
argument_list|(
name|utime
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ZTIMEV7
comment|/* The regular way */
name|char
modifier|*
name|asctime
parameter_list|()
function_decl|;
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
name|struct
name|tm
modifier|*
name|tp
decl_stmt|;
name|long
name|xclock
decl_stmt|;
name|time
argument_list|(
operator|&
name|xclock
argument_list|)
expr_stmt|;
name|tp
operator|=
name|localtime
argument_list|(
operator|&
name|xclock
argument_list|)
expr_stmt|;
operator|*
name|s
operator|=
name|asctime
argument_list|(
name|tp
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Catch-all for others... */
operator|*
name|s
operator|=
literal|"Ddd Mmm 00 00:00:00 0000\n"
comment|/* Return dummy in asctime() format */
endif|#
directive|endif
comment|/* ZTIMEV7 */
endif|#
directive|endif
comment|/* MINIX */
endif|#
directive|endif
comment|/* BSD42 */
endif|#
directive|endif
comment|/* PROVX1 */
endif|#
directive|endif
comment|/* SVORPOSIX */
block|}
comment|/*  C O N G M  --  Get console terminal modes.  */
comment|/*   Saves initial console mode, and establishes variables for switching   between current (presumably normal) mode and other modes.   Should be called when program starts, but only after establishing   whether program is in the foreground or background.   Returns 1 if it got the modes OK, 0 if it did nothing, -1 on error. */
name|int
name|congm
parameter_list|()
block|{
name|int
name|fd
decl_stmt|;
if|if
condition|(
name|backgrd
operator|||
operator|!
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
block|{
comment|/* If in background. */
name|cgmf
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Don't bother, modes are garbage. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|cgmf
operator|>
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Already did this. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"congm getting modes"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Need to do it. */
ifdef|#
directive|ifdef
name|aegis
name|ios_$inq_type_uid
argument_list|(
name|ios_$stdin
argument_list|,
name|conuid
argument_list|,
name|st
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|.
name|all
operator|!=
name|status_$ok
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"problem getting stdin objtype: "
argument_list|)
expr_stmt|;
name|error_$print
argument_list|(
name|st
argument_list|)
expr_stmt|;
block|}
name|concrp
operator|=
operator|(
name|conuid
operator|==
name|mbx_$uid
operator|)
expr_stmt|;
name|conbufn
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* aegis */
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|CTTNAM
argument_list|,
literal|2
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Open controlling terminal */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error opening %s\n"
argument_list|,
name|CTTNAM
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|"congm"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
if|if
condition|(
name|tcgetattr
argument_list|(
name|fd
argument_list|,
operator|&
name|ccold
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|tcgetattr
argument_list|(
name|fd
argument_list|,
operator|&
name|cccbrk
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|tcgetattr
argument_list|(
name|fd
argument_list|,
operator|&
name|ccraw
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATTSV
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ccold
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|cccbrk
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ccraw
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
ifdef|#
directive|ifdef
name|VXVE
name|cccbrk
operator|.
name|c_line
operator|=
literal|0
expr_stmt|;
comment|/* STTY line 0 for CDC VX/VE */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|cccbrk
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|ccraw
operator|.
name|c_line
operator|=
literal|0
expr_stmt|;
comment|/* STTY line 0 for CDC VX/VE */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|ccraw
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* VXVE */
else|#
directive|else
if|if
condition|(
name|gtty
argument_list|(
name|fd
argument_list|,
operator|&
name|ccold
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|gtty
argument_list|(
name|fd
argument_list|,
operator|&
name|cccbrk
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|gtty
argument_list|(
name|fd
argument_list|,
operator|&
name|ccraw
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
ifdef|#
directive|ifdef
name|sony_news
comment|/* Sony NEWS */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCKGET
argument_list|,
operator|&
name|km_con
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Get console Kanji mode */
name|perror
argument_list|(
literal|"congm error getting Kanji mode"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"congm error getting Kanji mode"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|km_con
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Make sure this stays undefined. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* sony_news */
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|cgmf
operator|=
literal|1
expr_stmt|;
comment|/* Flag that we got them. */
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/*  C O N C B --  Put console in cbreak mode.  */
comment|/*  Returns 0 if ok, -1 if not  */
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|concb
parameter_list|(
name|char
name|esc
parameter_list|)
else|#
directive|else
function|concb
parameter_list|(
name|esc
parameter_list|)
name|char
name|esc
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* concb */
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|cgmf
operator|<
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Console modes not available yet */
if|if
condition|(
name|ttfdflg
operator|&&
name|ttyfd
operator|>=
literal|0
operator|&&
name|ttyfd
operator|<
literal|3
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"concb backgrd"
argument_list|,
literal|""
argument_list|,
name|backgrd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Only for real ttys */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"concb isatty"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|backgrd
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Do nothing if in background. */
name|escchr
operator|=
name|esc
expr_stmt|;
comment|/* Make this available to other fns */
name|ckxech
operator|=
literal|1
expr_stmt|;
comment|/* Program can echo characters */
ifdef|#
directive|ifdef
name|aegis
name|conbufn
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|concrp
condition|)
return|return
operator|(
name|write
argument_list|(
literal|1
argument_list|,
literal|"\035\002"
argument_list|,
literal|2
argument_list|)
operator|)
return|;
if|if
condition|(
name|conuid
operator|==
name|input_pad_$uid
condition|)
block|{
name|pad_$raw
argument_list|(
name|ios_$stdin
argument_list|,
name|st
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SVORPOSIX
comment|/* BSD, V7, etc */
name|cccbrk
operator|.
name|sg_flags
operator||=
name|CBREAK
expr_stmt|;
comment|/* Set to character wakeup, */
name|cccbrk
operator|.
name|sg_flags
operator|&=
operator|~
name|ECHO
expr_stmt|;
comment|/* no echo. */
name|x
operator|=
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|cccbrk
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Sys V and POSIX */
name|cccbrk
operator|.
name|c_lflag
operator|&=
operator|~
operator|(
name|ICANON
operator||
name|ECHO
operator||
name|IEXTEN
operator|)
expr_stmt|;
ifndef|#
directive|ifndef
name|VINTR
name|cccbrk
operator|.
name|c_cc
index|[
literal|0
index|]
operator|=
literal|003
expr_stmt|;
comment|/* interrupt char is control-c */
else|#
directive|else
name|cccbrk
operator|.
name|c_cc
index|[
name|VINTR
index|]
operator|=
literal|003
expr_stmt|;
endif|#
directive|endif
comment|/* VINTR */
ifndef|#
directive|ifndef
name|VQUIT
name|cccbrk
operator|.
name|c_cc
index|[
literal|1
index|]
operator|=
name|escchr
expr_stmt|;
comment|/* escape during packet modes */
else|#
directive|else
name|cccbrk
operator|.
name|c_cc
index|[
name|VQUIT
index|]
operator|=
name|escchr
expr_stmt|;
endif|#
directive|endif
comment|/* VQUIT */
ifndef|#
directive|ifndef
name|VEOF
name|cccbrk
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VMIN
name|cccbrk
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* VMIN */
endif|#
directive|endif
comment|/* VEOF */
ifdef|#
directive|ifdef
name|ZILOG
name|cccbrk
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|0
expr_stmt|;
else|#
directive|else
ifndef|#
directive|ifndef
name|VEOL
name|cccbrk
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|1
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VTIME
name|cccbrk
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* VTIME */
endif|#
directive|endif
comment|/* VEOL */
endif|#
directive|endif
comment|/* ZILOG */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
comment|/* Set new modes */
name|x
operator|=
name|tcsetattr
argument_list|(
literal|0
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|cccbrk
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* ATTSV */
comment|/* or the POSIX way */
name|x
operator|=
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|cccbrk
argument_list|)
expr_stmt|;
comment|/* the Sys V way */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
endif|#
directive|endif
comment|/* SVORPOSIX */
ifndef|#
directive|ifndef
name|aegis
ifndef|#
directive|ifndef
name|NOSETBUF
if|if
condition|(
name|x
operator|>
operator|-
literal|1
condition|)
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* Make console unbuffered. */
endif|#
directive|endif
comment|/* NOSETBUF */
endif|#
directive|endif
comment|/* aegis */
ifdef|#
directive|ifdef
name|V7
ifndef|#
directive|ifndef
name|MINIX
if|if
condition|(
name|kmem
index|[
name|CON
index|]
operator|<
literal|0
condition|)
block|{
name|qaddr
index|[
name|CON
index|]
operator|=
name|initrawq
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|kmem
index|[
name|CON
index|]
operator|=
name|open
argument_list|(
literal|"/dev/kmem"
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't read /dev/kmem in concb.\n"
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|"/dev/kmem"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* MINIX */
endif|#
directive|endif
comment|/* V7 */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"concb returns"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
comment|/*  C O N B I N  --  Put console in binary mode  */
comment|/*  Returns 0 if ok, -1 if not  */
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|conbin
parameter_list|(
name|char
name|esc
parameter_list|)
else|#
directive|else
function|conbin
parameter_list|(
name|esc
parameter_list|)
name|char
name|esc
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* conbin */
block|{
if|if
condition|(
operator|!
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* only for real ttys */
name|congm
argument_list|()
expr_stmt|;
comment|/* Get modes if necessary. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"conbin"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|escchr
operator|=
name|esc
expr_stmt|;
comment|/* Make this available to other fns */
name|ckxech
operator|=
literal|1
expr_stmt|;
comment|/* Program can echo characters */
ifdef|#
directive|ifdef
name|aegis
name|conbufn
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|concrp
condition|)
return|return
operator|(
name|write
argument_list|(
literal|1
argument_list|,
literal|"\035\002"
argument_list|,
literal|2
argument_list|)
operator|)
return|;
if|if
condition|(
name|conuid
operator|==
name|input_pad_$uid
condition|)
name|pad_$raw
argument_list|(
name|ios_$stdin
argument_list|,
name|st
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
endif|#
directive|endif
comment|/* aegis */
ifdef|#
directive|ifdef
name|SVORPOSIX
name|ccraw
operator|.
name|c_lflag
operator|&=
operator|~
operator|(
name|ISIG
operator||
name|ICANON
operator||
name|ECHO
operator||
name|IEXTEN
operator|)
return|;
name|ccraw
operator|.
name|c_iflag
operator||=
operator|(
name|BRKINT
operator||
name|IGNPAR
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ATTSV
ifdef|#
directive|ifdef
name|BSD44
name|ccraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IGNBRK
operator||
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|IXON
operator||
name|IXANY
operator||
name|IXOFF
operator||
name|INPCK
operator||
name|ISTRIP
operator|)
expr_stmt|;
else|#
directive|else
name|ccraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IGNBRK
operator||
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|IUCLC
operator||
name|IXON
operator||
name|IXANY
operator||
name|IXOFF
operator||
name|INPCK
operator||
name|ISTRIP
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* BSD44 */
else|#
directive|else
comment|/* POSIX */
name|ccraw
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|IGNBRK
operator||
name|INLCR
operator||
name|IGNCR
operator||
name|ICRNL
operator||
name|IXON
operator||
name|IXOFF
operator||
name|INPCK
operator||
name|ISTRIP
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* ATTSV */
name|ccraw
operator|.
name|c_oflag
operator|&=
operator|~
name|OPOST
expr_stmt|;
ifdef|#
directive|ifdef
name|ATT7300
name|ccraw
operator|.
name|c_cflag
operator|=
name|CLOCAL
operator||
name|B9600
operator||
name|CS8
operator||
name|CREAD
operator||
name|HUPCL
expr_stmt|;
endif|#
directive|endif
comment|/* ATT7300 */
comment|/*** Kermit used to put the console in 8-bit raw mode, but some users have  *** pointed out that this should not be done, since some sites actually  *** use terminals with parity settings on their Unix systems, and if we  *** override the current settings and stop doing parity, then their terminals  *** will display blotches for characters whose parity is wrong.  Therefore,  *** the following two lines are commented out (Larry Afrin, Clemson U):  ***  ***   ccraw.c_cflag&= ~(PARENB|CSIZE);  ***   ccraw.c_cflag |= (CS8|CREAD);  ***  *** Sys III/V sites that have trouble with this can restore these lines.  ***/
ifndef|#
directive|ifndef
name|VINTR
name|ccraw
operator|.
name|c_cc
index|[
literal|0
index|]
operator|=
literal|003
expr_stmt|;
comment|/* Interrupt char is Ctrl-C */
else|#
directive|else
name|ccraw
operator|.
name|c_cc
index|[
name|VINTR
index|]
operator|=
literal|003
expr_stmt|;
endif|#
directive|endif
comment|/* VINTR */
ifndef|#
directive|ifndef
name|VQUIT
name|ccraw
operator|.
name|c_cc
index|[
literal|1
index|]
operator|=
name|escchr
expr_stmt|;
comment|/* Escape during packet mode */
else|#
directive|else
name|ccraw
operator|.
name|c_cc
index|[
name|VQUIT
index|]
operator|=
name|escchr
expr_stmt|;
endif|#
directive|endif
comment|/* VQUIT */
ifndef|#
directive|ifndef
name|VEOF
name|ccraw
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VMIN
name|ccraw
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* VEOF */
ifdef|#
directive|ifdef
name|ZILOG
name|ccraw
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|0
expr_stmt|;
else|#
directive|else
ifndef|#
directive|ifndef
name|VEOL
name|ccraw
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|1
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VTIME
name|ccraw
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* VTIME */
endif|#
directive|endif
comment|/* VEOL */
endif|#
directive|endif
comment|/* ZILOG */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
return|return
operator|(
name|tcsetattr
argument_list|(
literal|0
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ccraw
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|ccraw
argument_list|)
operator|)
return|;
comment|/* Set new modes. */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
else|#
directive|else
comment|/* Berkeley, etc. */
name|ccraw
operator|.
name|sg_flags
operator||=
operator|(
name|RAW
operator||
name|TANDEM
operator|)
expr_stmt|;
comment|/* Set rawmode, XON/XOFF (ha) */
name|ccraw
operator|.
name|sg_flags
operator|&=
operator|~
operator|(
name|ECHO
operator||
name|CRMOD
operator|)
expr_stmt|;
comment|/* Set char wakeup, no echo */
return|return
operator|(
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|ccraw
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* SVORPOSIX */
block|}
comment|/*  C O N R E S  --  Restore the console terminal  */
name|int
name|conres
parameter_list|()
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conres cgmf"
argument_list|,
literal|""
argument_list|,
name|cgmf
argument_list|)
expr_stmt|;
if|if
condition|(
name|cgmf
operator|<
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Do nothing if modes unchanged */
if|if
condition|(
operator|!
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* only for real ttys */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"conres isatty ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ckxech
operator|=
literal|0
expr_stmt|;
comment|/* System should echo chars */
ifdef|#
directive|ifdef
name|aegis
name|conbufn
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|concrp
condition|)
return|return
operator|(
name|write
argument_list|(
literal|1
argument_list|,
literal|"\035\001"
argument_list|,
literal|2
argument_list|)
operator|)
return|;
if|if
condition|(
name|conuid
operator|==
name|input_pad_$uid
condition|)
name|pad_$cooked
argument_list|(
name|ios_$stdin
argument_list|,
name|st
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* aegis */
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
name|debug
argument_list|(
name|F100
argument_list|,
literal|"conres restoring tcsetattr"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|tcsetattr
argument_list|(
literal|0
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|ccold
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATTSV
name|debug
argument_list|(
name|F100
argument_list|,
literal|"conres restoring ioctl"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|ccold
argument_list|)
operator|)
return|;
else|#
directive|else
comment|/* BSD, V7, and friends */
ifdef|#
directive|ifdef
name|sony_news
comment|/* Sony NEWS */
if|if
condition|(
name|km_con
operator|!=
operator|-
literal|1
condition|)
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCKSET
argument_list|,
operator|&
name|km_con
argument_list|)
expr_stmt|;
comment|/* Restore console Kanji mode */
endif|#
directive|endif
comment|/* sony_news */
name|msleep
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"conres restoring stty"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|ccold
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* ATTSV */
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
block|}
comment|/*  C O N O C  --  Output a character to the console terminal  */
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|conoc
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|conoc
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* conoc */
block|{
return|return
operator|(
name|write
argument_list|(
literal|1
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
comment|/*  C O N X O  --  Write x characters to the console terminal  */
name|int
name|conxo
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|{
return|return
operator|(
name|write
argument_list|(
literal|1
argument_list|,
name|s
argument_list|,
name|x
argument_list|)
operator|)
return|;
block|}
comment|/*  C O N O L  --  Write a line to the console terminal  */
name|int
name|conol
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|len
decl_stmt|;
name|len
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|write
argument_list|(
literal|1
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
operator|)
return|;
block|}
comment|/*  C O N O L A  --  Write an array of lines to the console terminal */
name|int
name|conola
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
index|[]
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|*
name|s
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|conol
argument_list|(
name|s
index|[
name|i
index|]
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
empty_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/*  C O N O L L  --  Output a string followed by CRLF  */
name|int
name|conoll
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|conol
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|write
argument_list|(
literal|1
argument_list|,
literal|"\r\n"
argument_list|,
literal|2
argument_list|)
operator|)
return|;
block|}
comment|/*  C O N C H K  --  Return how many characters available at console  */
name|int
name|conchk
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|PEEKTYPE
name|n
decl_stmt|;
if|if
condition|(
name|backgrd
operator|||
operator|!
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
ifdef|#
directive|ifdef
name|PROVX1
name|x
operator|=
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCQCNT
argument_list|,
operator|&
name|ttbuf
argument_list|)
expr_stmt|;
name|n
operator|=
name|ttbuf
operator|.
name|sg_ispeed
operator|&
literal|0377
expr_stmt|;
return|return
operator|(
operator|(
name|x
operator|<
literal|0
operator|)
condition|?
literal|0
else|:
name|n
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|aegis
if|if
condition|(
name|conbufn
operator|>
literal|0
condition|)
return|return
operator|(
name|conbufn
operator|)
return|;
comment|/* use old count if nonzero */
comment|/* read in more characters */
name|conbufn
operator|=
name|ios_$get
argument_list|(
name|ios_$stdin
argument_list|,
name|ios_$cond_opt
argument_list|,
name|conbuf
argument_list|,
operator|(
name|long
operator|)
sizeof|sizeof
argument_list|(
name|conbuf
argument_list|)
argument_list|,
name|st
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|.
name|all
operator|!=
name|status_$ok
condition|)
name|conbufn
operator|=
literal|0
expr_stmt|;
name|conbufp
operator|=
name|conbuf
expr_stmt|;
return|return
operator|(
name|conbufn
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|V7
ifdef|#
directive|ifdef
name|MINIX
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
name|lseek
argument_list|(
name|kmem
index|[
name|CON
index|]
argument_list|,
operator|(
name|long
operator|)
name|qaddr
index|[
name|CON
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|x
operator|=
name|read
argument_list|(
name|kmem
index|[
name|CON
index|]
argument_list|,
operator|&
name|n
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|x
operator|==
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|)
condition|?
name|n
else|:
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* MINIX */
else|#
directive|else
ifdef|#
directive|ifdef
name|SVORPOSIX
if|if
condition|(
name|conesc
condition|)
block|{
comment|/* Escape typed */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"conchk returns conesc"
argument_list|,
literal|""
argument_list|,
name|conesc
argument_list|)
expr_stmt|;
name|conesc
operator|=
literal|0
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|esctrp
argument_list|)
expr_stmt|;
comment|/* Restore escape */
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|C70
if|if
condition|(
name|conesc
condition|)
block|{
comment|/* Escape typed */
name|conesc
operator|=
literal|0
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|esctrp
argument_list|)
expr_stmt|;
comment|/* Restore escape */
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|FIONREAD
comment|/*   Reportedly, this can cause C-Kermit to be suspended on certain OS's,   such as Olivetti X/OS, when called if Kermit is really in the background.   Hence the change at the top of this routine to return 0 if the backgrd   flag is set. */
name|x
operator|=
name|ioctl
argument_list|(
literal|0
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|n
argument_list|)
expr_stmt|;
comment|/* BSD and maybe some others */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conchk"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|x
operator|<
literal|0
operator|)
condition|?
literal|0
else|:
name|n
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Others can't do. */
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
block|}
comment|/*  C O N I N C  --  Get a character from the console  */
comment|/*   Call with timo> 0 to do a timed read, timo == 0 to do an untimed blocking   read.  Upon success, returns the character.  Upon failure, returns -1.   A timed read that does not complete within the timeout period returns -1. */
name|int
name|coninc
parameter_list|(
name|timo
parameter_list|)
name|int
name|timo
decl_stmt|;
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
name|CHAR
name|ch
decl_stmt|;
name|int
name|xx
decl_stmt|;
ifdef|#
directive|ifdef
name|aegis
comment|/* Apollo Aegis only... */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"coninc timo"
argument_list|,
literal|""
argument_list|,
name|timo
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|conchk
argument_list|()
operator|>
literal|0
condition|)
block|{
operator|--
name|conbufn
expr_stmt|;
return|return
operator|(
operator|*
name|conbufp
operator|++
operator|&
literal|0377
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* aegis */
if|if
condition|(
name|timo
operator|<=
literal|0
condition|)
block|{
comment|/* Untimed, blocking read. */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* Keep trying till we get one. */
name|n
operator|=
name|read
argument_list|(
literal|0
argument_list|,
operator|&
name|ch
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Read a character. */
if|if
condition|(
name|n
operator|==
literal|0
condition|)
continue|continue;
comment|/* Shouldn't happen. */
if|if
condition|(
name|n
operator|>
literal|0
condition|)
comment|/* If read was successful, */
return|return
operator|(
name|ch
operator|&
literal|0377
operator|)
return|;
comment|/* return the character. */
comment|/* Come here if read() returned an error. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"coninc(0) errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|/* Log the error. */
ifdef|#
directive|ifdef
name|SVORPOSIX
ifdef|#
directive|ifdef
name|CIE
comment|/* CIE Regulus has no EINTR symbol? */
ifndef|#
directive|ifndef
name|EINTR
define|#
directive|define
name|EINTR
value|4
endif|#
directive|endif
comment|/* EINTR */
endif|#
directive|endif
comment|/* CIE */
comment|/*   This routine is used for several different purposes.  In CONNECT mode, it is   used to do an untimed, blocking read from the keyboard in the lower CONNECT   fork.  During local-mode file transfer, it reads a character from the   console to interrupt the file transfer (like A for a status report, X to   cancel a file, etc).  Obviously, we don't want the reads in the latter case   to be blocking, or the file transfer would stop until the user typed   something.  Unfortunately, System V does not allow the console device input   buffer to be sampled nondestructively (e.g. by conchk()), so a kludge is   used instead.  During local-mode file transfer, the SIGQUIT signal is armed   and trapped by esctrp(), and this routine pretends to have read the quit   character from the keyboard normally.  But, kludge or no kludge, the read()   issued by this command, under System V only, can fail if a signal -- ANY   signal -- is caught while the read is pending.  This can occur not only when   the user types the quit character, but also during telnet negotiations, when   the lower CONNECT fork signals the upper one about an echoing mode change.   When this happens, we have to post the read() again.  This is apparently not   a problem in BSD-based UNIX versions. */
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
comment|/* Read interrupted. */
if|if
condition|(
name|conesc
condition|)
block|{
comment|/* If by SIGQUIT, */
name|conesc
operator|=
literal|0
expr_stmt|;
comment|/* the conesc variable is set, */
return|return
operator|(
name|escchr
operator|)
return|;
comment|/* so return the escape character. */
block|}
else|else
continue|continue;
comment|/* By other signal, try again. */
else|#
directive|else
comment|/*   This might be dangerous, but let's do this on non-System V versions too,   since at least one SunOS 4.1.2 user complains of immediate disconnections   upon first making a TELNET connection. */
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
comment|/* Read interrupted. */
continue|continue;
endif|#
directive|endif
comment|/* SVORPOSIX */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Error */
block|}
block|}
if|if
condition|(
name|timo
operator|<=
literal|0
condition|)
comment|/* This should never happen */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"coninc HORRIBLE ERROR"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Timed read... */
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Set up timeout handler. */
name|xx
operator|=
name|alarm
argument_list|(
name|timo
argument_list|)
expr_stmt|;
comment|/* Set the alarm. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"coninc alarm"
argument_list|,
literal|""
argument_list|,
name|xx
argument_list|)
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
comment|/* The read() timed out. */
name|n
operator|=
operator|-
literal|2
expr_stmt|;
comment|/* Code for timeout. */
else|else
name|n
operator|=
name|read
argument_list|(
literal|0
argument_list|,
operator|&
name|ch
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Turn off timer */
if|if
condition|(
name|n
operator|>
literal|0
condition|)
comment|/* Got character OK. */
return|return
operator|(
name|ch
operator|&
literal|0377
operator|)
return|;
comment|/* Return it. */
comment|/*   Read returned an error.  Same deal as above, but without the loop. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"coninc(timo) n"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"coninc(timo) errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SVORPOSIX
if|if
condition|(
name|n
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EINTR
operator|&&
name|conesc
operator|!=
literal|0
condition|)
block|{
name|conesc
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|escchr
operator|)
return|;
comment|/* User entered escape character. */
block|}
else|else
comment|/* n == 0 shouldn't happen. */
endif|#
directive|endif
comment|/* SVORPOSIX */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/*  C O N G K S  --  Console Get Keyboard Scancode  */
ifndef|#
directive|ifndef
name|congks
comment|/*   This function needs to be filled in with the various system-dependent   system calls used by SUNOS, NeXT OS, Xenix, Aviion, etc, to read a full   keyboard scan code.  For now, it's a dummy. */
name|int
name|congks
parameter_list|(
name|timo
parameter_list|)
name|int
name|timo
decl_stmt|;
block|{
return|return
operator|(
name|coninc
argument_list|(
name|timo
argument_list|)
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* congks */
ifdef|#
directive|ifdef
name|ATT7300
comment|/*  A T T D I A L  --  Dial up the remote system using internal modem  * Purpose: to open and dial a number on the internal modem available on the  * ATT7300 UNIX PC.  Written by Joe Doupnik. Superceeds version written by  * Richard E. Hill, Dickinson, TX. which employed dial(3c).  * Uses information in<sys/phone.h> and our status int attmodem.  */
name|attdial
argument_list|(
argument|ttname
argument_list|,
argument|speed
argument_list|,
argument|telnbr
argument_list|)
name|char
modifier|*
name|ttname
decl_stmt|,
modifier|*
name|telnbr
decl_stmt|;
name|long
name|speed
decl_stmt|;
block|{
name|char
modifier|*
name|telnum
decl_stmt|;
name|int
name|ttclos
parameter_list|()
function_decl|;
name|attmodem
operator|&=
operator|~
name|ISMODEM
expr_stmt|;
comment|/* modem not in use yet */
comment|/* Ensure O_NDELAY is set, else i/o traffic hangs */
comment|/* We turn this flag off once the dial is complete */
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_SETFL
argument_list|,
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator||
name|O_NDELAY
argument_list|)
expr_stmt|;
comment|/* Condition line, check availability& DATA mode, turn on speaker */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCOFFHOOK
argument_list|,
operator|&
name|dialer
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"cannot access phone\n"
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCGETP
argument_list|,
operator|&
name|dialer
argument_list|)
expr_stmt|;
comment|/* get phone dialer parameters */
if|if
condition|(
name|dialer
operator|.
name|c_lineparam
operator|&
name|VOICE
condition|)
block|{
comment|/* phone must be in DATA mode */
name|printf
argument_list|(
literal|" Should not dial with modem in VOICE mode.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Exit Kermit, switch to DATA and retry call.\n"
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|ATTTONED
comment|/* Old way, tone dialing only. */
name|dialer
operator|.
name|c_lineparam
operator|=
name|DATA
operator||
name|DTMF
expr_stmt|;
comment|/* Dial with tones, */
name|dialer
operator|.
name|c_lineparam
operator|&=
operator|~
name|PULSE
expr_stmt|;
comment|/* not with pulses. */
else|#
directive|else
comment|/* Leave current pulse/tone state alone. */
comment|/* But what about DATA?  Add it back if you have trouble. */
comment|/* sys/phone says you get DATA automatically by opening device RDWR */
endif|#
directive|endif
name|dialer
operator|.
name|c_waitdialtone
operator|=
literal|5
expr_stmt|;
comment|/* wait 5 sec for dialtone */
ifdef|#
directive|ifdef
name|COMMENT
name|dialer
operator|.
name|c_feedback
operator|=
name|SPEAKERON
operator||
name|NORMSPK
operator||
name|RINGON
expr_stmt|;
comment|/* control speaker */
else|#
directive|else
comment|/* sys/phone says RINGON used only for incoming voice calls */
name|dialer
operator|.
name|c_feedback
operator|&=
operator|~
operator|(
name|SOFTSPK
operator||
name|LOUDSPK
operator|)
expr_stmt|;
name|dialer
operator|.
name|c_feedback
operator||=
name|SPEAKERON
operator||
name|NORMSPK
expr_stmt|;
endif|#
directive|endif
name|dialer
operator|.
name|c_waitflash
operator|=
literal|500
expr_stmt|;
comment|/* 0.5 sec flash hook */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCSETP
argument_list|,
operator|&
name|dialer
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* set phone parameters */
name|printf
argument_list|(
literal|"Cannot set modem characteristics\n"
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCRECONN
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Turns on speaker for pulse */
ifdef|#
directive|ifdef
name|COMMENT
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Phone line status. line_par:%o dialtone_wait:%o \ line_status:%o feedback:%o\n"
argument_list|,
name|dialer
operator|.
name|c_lineparam
argument_list|,
name|dialer
operator|.
name|c_waitdialtone
argument_list|,
name|dialer
operator|.
name|c_linestatus
argument_list|,
name|dialer
operator|.
name|c_feedback
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|attmodem
operator||=
name|ISMODEM
expr_stmt|;
comment|/* modem is now in-use */
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|telnum
operator|=
name|telnbr
init|;
operator|*
name|telnum
operator|!=
literal|'\0'
condition|;
name|telnum
operator|++
control|)
comment|/* dial number */
ifdef|#
directive|ifdef
name|ATTTONED
comment|/* Tone dialing only */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCDIAL
argument_list|,
name|telnum
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"Error in dialing"
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
else|#
directive|else
comment|/* Allow Pulse or Tone dialing */
switch|switch
condition|(
operator|*
name|telnum
condition|)
block|{
case|case
literal|'t'
case|:
case|case
literal|'T'
case|:
case|case
literal|'%'
case|:
comment|/* Tone dialing requested */
name|dialer
operator|.
name|c_lineparam
operator||=
name|DTMF
expr_stmt|;
name|dialer
operator|.
name|c_lineparam
operator|&=
operator|~
name|PULSE
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCSETP
argument_list|,
operator|&
name|dialer
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Cannot set modem to tone dialing\n"
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
break|break;
case|case
literal|'d'
case|:
case|case
literal|'D'
case|:
case|case
literal|'p'
case|:
case|case
literal|'P'
case|:
case|case
literal|'^'
case|:
name|dialer
operator|.
name|c_lineparam
operator||=
name|PULSE
expr_stmt|;
name|dialer
operator|.
name|c_lineparam
operator|&=
operator|~
name|DTMF
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCSETP
argument_list|,
operator|&
name|dialer
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Cannot set modem to pulse dialing\n"
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
break|break;
default|default:
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCDIAL
argument_list|,
name|telnum
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"Dialing error"
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
break|break;
block|}
endif|#
directive|endif
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCDIAL
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
comment|/* terminator for data call */
do|do
block|{
comment|/* wait for modems to Connect */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|PIOCGETP
argument_list|,
operator|&
name|dialer
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* get params */
name|perror
argument_list|(
literal|"Cannot get modems to connect"
argument_list|)
expr_stmt|;
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
block|}
do|while
condition|(
operator|(
name|dialer
operator|.
name|c_linestatus
operator|&
name|MODEMCONNECTED
operator|)
operator|==
literal|0
condition|)
do|;
comment|/* Turn off O_NDELAY flag now. */
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_SETFL
argument_list|,
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator|&
operator|~
name|O_NDELAY
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|ttclos
argument_list|)
expr_stmt|;
comment|/* hangup on loss of carrier */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return success */
block|}
comment|/*   Offgetty, ongetty functions. These function get the 'getty(1m)' off   and restore it to the indicated line.  Shell's return codes are:     0: Can't do it.  Probably a user logged on.     1: No need.  No getty on that line.     2: Done, you should restore the getty when you're done.   DOGETY System(3), however, returns them as 0, 256, 512, respectively.   Thanks to Kevin O'Gorman, Anarm Software Systems.     getoff.sh looks like:   geton.sh looks like:      setgetty $1 0           setgetty $1 1      err=$?                  exit $?      sleep 2      exit $err */
comment|/*  O F F G E T T Y  --  Turn off getty(1m) for the communications tty line  * and get status so it can be restarted after the line is hung up.  */
name|int
name|offgetty
parameter_list|(
name|ttname
parameter_list|)
name|char
modifier|*
name|ttname
decl_stmt|;
block|{
name|char
name|temp
index|[
literal|30
index|]
decl_stmt|;
while|while
condition|(
operator|*
name|ttname
operator|!=
literal|'\0'
condition|)
name|ttname
operator|++
expr_stmt|;
comment|/* seek terminator of path */
name|ttname
operator|-=
literal|3
expr_stmt|;
comment|/* get last 3 chars of name */
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|"/usr/bin/getoff.sh %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
return|return
operator|(
name|zsyscmd
argument_list|(
name|temp
argument_list|)
operator|)
return|;
block|}
comment|/*  O N G E T T Y  --  Turn on getty(1m) for the communications tty line */
name|int
name|ongetty
parameter_list|(
name|ttname
parameter_list|)
name|char
modifier|*
name|ttname
decl_stmt|;
block|{
name|char
name|temp
index|[
literal|30
index|]
decl_stmt|;
while|while
condition|(
operator|*
name|ttname
operator|!=
literal|'\0'
condition|)
name|ttname
operator|++
expr_stmt|;
comment|/* comms tty path name */
name|ttname
operator|-=
literal|3
expr_stmt|;
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|"/usr/bin/geton.sh %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
return|return
operator|(
name|zsyscmd
argument_list|(
name|temp
argument_list|)
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* ATT7300 */
comment|/*  T T S C A R R  --  Set ttcarr variable, controlling carrier handling.  *  *  0 = Off: Always ignore carrier. E.g. you can connect without carrier.  *  1 = On: Heed carrier, except during dialing. Carrier loss gives disconnect.  *  2 = Auto: For "modem direct": The same as "Off".  *            For real modem types: Heed carrier during connect, but ignore  *                it anytime else.  Compatible with pre-5A C-Kermit versions.  *  * As you can see, this setting does not affect dialing, which always ignores  * carrier (unless there is some special exception for some modem type).  It  * does affect ttopen() if it is set before ttopen() is used.  This setting  * takes effect on the next call to ttopen()/ttpkt()/ttvt().  And they are  * (or should be) always called before any communications is tried, which  * means that, practically speaking, the effect is immediate.  *  * Of course, nothing of this applies to remote mode (xlocal = 0).  *  * Someone has yet to uncover how to manipulate the carrier in the BSD  * environment (or any non-termio using environment).  Until that time, this  * will simply be a no-op for BSD.  *  * Note that in previous versions, the carrier was most often left unchanged  * in ttpkt()/ttvt() unless they were called with FLO_DIAL or FLO_DIAX.  This  * has changed.  Now it is controlled by ttcarr in conjunction with these  * modes.  */
name|int
name|ttscarr
parameter_list|(
name|carrier
parameter_list|)
name|int
name|carrier
decl_stmt|;
block|{
name|ttcarr
operator|=
name|carrier
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttscarr"
argument_list|,
literal|""
argument_list|,
name|ttcarr
argument_list|)
expr_stmt|;
return|return
operator|(
name|ttcarr
operator|)
return|;
block|}
comment|/* C A R R C T L  --  Set tty modes for carrier treatment.  *  * Sets the appropriate bits in a termio or sgttyb struct for carrier control  * (actually, there are no bits in sgttyb for that), or performs any other  * operations needed to control this on the current system.  The function does  * not do the actual TCSETA or stty, since often we want to set other bits too  * first.  Don't call this function when xlocal is 0, or the tty is not opened.  *  * We don't know how to do anything like carrier control on non-ATTSV systems,  * except, apparently, ultrix.  See above.  It is also known that this doesn't  * have much effect on a Xenix system.  For Xenix, one should switch back and  * forth between the upper and lower case device files.  Maybe later.   * Presently, Xenix will stick to the mode it was opened with.  *  * carrier: 0 = ignore carrier, 1 = require carrier.  * The current state is saved in curcarr, and checked to save labour.  */
ifdef|#
directive|ifdef
name|SVORPOSIX
name|int
ifdef|#
directive|ifdef
name|BSD44ORPOSIX
name|carrctl
parameter_list|(
name|ttpar
parameter_list|,
name|carrier
parameter_list|)
name|struct
name|termios
modifier|*
name|ttpar
decl_stmt|;
name|int
name|carrier
decl_stmt|;
else|#
directive|else
comment|/* ATTSV */
function|carrctl
parameter_list|(
name|ttpar
parameter_list|,
name|carrier
parameter_list|)
name|struct
name|termio
modifier|*
name|ttpar
decl_stmt|;
name|int
name|carrier
decl_stmt|;
endif|#
directive|endif
comment|/* BSD44ORPOSIX */
comment|/* carrctl */
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"carrctl"
argument_list|,
literal|""
argument_list|,
name|carrier
argument_list|)
expr_stmt|;
if|if
condition|(
name|carrier
condition|)
name|ttpar
operator|->
name|c_cflag
operator|&=
operator|~
name|CLOCAL
expr_stmt|;
else|else
name|ttpar
operator|->
name|c_cflag
operator||=
name|CLOCAL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|#
directive|else
comment|/* Berkeley, V7, et al... */
name|int
name|carrctl
parameter_list|(
name|ttpar
parameter_list|,
name|carrier
parameter_list|)
name|struct
name|sgttyb
modifier|*
name|ttpar
decl_stmt|;
name|int
name|carrier
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|ultrix
name|int
name|temp
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
comment|/* ultrix */
ifdef|#
directive|ifdef
name|OXOS
name|int
name|modem_status
decl_stmt|,
name|lnohang
init|=
name|LNOHANG
decl_stmt|;
endif|#
directive|endif
comment|/* OXOS */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"carrctl"
argument_list|,
literal|""
argument_list|,
name|carrier
argument_list|)
expr_stmt|;
if|if
condition|(
name|carrier
operator|==
name|curcarr
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|curcarr
operator|=
name|carrier
expr_stmt|;
ifdef|#
directive|ifdef
name|ultrix
if|if
condition|(
name|carrier
condition|)
block|{
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCMODEM
argument_list|,
operator|&
name|temp
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCHPCL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* (According to the manuals, TIOCNCAR should be preferred */
comment|/* over TIOCNMODEM...) */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCNMODEM
argument_list|,
operator|&
name|temp
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* ultrix */
ifdef|#
directive|ifdef
name|OXOS
comment|/*   From Fulvio Marino at Olivetti.  This code allows CONNECT to work even   if DCD/RTS are down, if "carrier" is set appropriately. */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCMODG
argument_list|,
operator|&
name|modem_status
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|carrier
condition|)
block|{
comment|/* enable carrier detect */
name|modem_status
operator||=
name|TIOCM_CAR
expr_stmt|;
block|}
else|else
block|{
comment|/* disable carrier detect */
name|modem_status
operator|&=
operator|~
name|TIOCM_CAR
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCMODS
argument_list|,
operator|&
name|modem_status
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|carrier
condition|)
block|{
comment|/* Send hangup when carrier drops */
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCLBIC
argument_list|,
operator|&
name|lnohang
argument_list|)
expr_stmt|;
comment|/* hang up the phone */
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCHPCL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Don't send hangup when carrier drops */
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCLBIS
argument_list|,
operator|&
name|lnohang
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* OXOS */
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* SVORPOSIX */
comment|/*  T T G M D M  --  Get modem signals  */
comment|/*  Looks for RS-232 modem signals, and returns those that are on in as its  return value, in a bit mask composed of the BM_xxx values defined in ckcdeb.h.  Returns:   -3 Not implemented  -2 if the communication device does not have modem control (e.g. telnet)  -1 on error.>= 0 on success, with a bit mask containing the modem signals that are on. */
comment|/*   Define the symbol K_MDMCTL if we have Sys V R3 / 4.3 BSD style   modem control, namely the TIOCMGET ioctl. */
ifdef|#
directive|ifdef
name|BSD43
define|#
directive|define
name|K_MDMCTL
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SUNOS4
define|#
directive|define
name|K_MDMCTL
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCMGET
define|#
directive|define
name|K_MDMCTL
endif|#
directive|endif
name|int
name|ttgmdm
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HPUX
comment|/* HPUX has its own way */
comment|/*   NOTE: I don't have an HPUX man page, and so I'm only guessing at the   right names for these symbols.  Somebody with HPUX please let me know   what corrections are needed. */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* No modem signals for network */
if|if
condition|(
name|xlocal
condition|)
comment|/* Get modem signals */
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|MCGETA
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
else|else
name|x
operator|=
name|ioctl
argument_list|(
literal|0
argument_list|,
name|MCGETA
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttgmdm"
argument_list|,
literal|""
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|z
operator|=
literal|0
expr_stmt|;
comment|/* Initialize return value */
comment|/* Now set bits for each modem signal that is reported to be on. */
ifdef|#
directive|ifdef
name|MCTS
comment|/* Clear To Send */
if|if
condition|(
name|y
operator|&
name|MCTS
condition|)
name|z
operator||=
name|BM_CTS
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MDSR
comment|/* Data Set Ready */
if|if
condition|(
name|y
operator|&
name|MDSR
condition|)
name|z
operator||=
name|BM_DSR
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MDCD
comment|/* Carrier */
if|if
condition|(
name|y
operator|&
name|MDCD
condition|)
name|z
operator||=
name|BM_DCD
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MRNG
comment|/* Ring Indicate */
if|if
condition|(
name|y
operator|&
name|MRNG
condition|)
name|z
operator||=
name|BM_RNG
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MDTR
comment|/* Data Terminal Ready */
if|if
condition|(
name|y
operator|&
name|MDTR
condition|)
name|z
operator||=
name|BM_DTR
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MRTS
comment|/* Request To Send */
if|if
condition|(
name|y
operator|&
name|MRTS
condition|)
name|z
operator||=
name|BM_RTS
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|z
operator|)
return|;
else|#
directive|else
comment|/* ! HPUX */
ifdef|#
directive|ifdef
name|K_MDMCTL
comment|/*   Note,<sys/ttycom> might have already been included by by<sys/ioctl.h>.   Hence the following ifndef on a symbol which is defined there. */
ifndef|#
directive|ifndef
name|TIOCMGET
include|#
directive|include
file|<sys/ttycom.h>
endif|#
directive|endif
comment|/* TIOCMGET */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* Network, no modem signals. */
if|if
condition|(
name|xlocal
condition|)
name|x
operator|=
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCMGET
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
comment|/* Get modem signals. */
else|else
name|x
operator|=
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCMGET
argument_list|,
operator|&
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttgmdm"
argument_list|,
literal|""
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|z
operator|=
literal|0
expr_stmt|;
comment|/* Initialize return value. */
ifdef|#
directive|ifdef
name|TIOCM_CTS
comment|/* Clear To Send */
if|if
condition|(
name|y
operator|&
name|TIOCM_CTS
condition|)
name|z
operator||=
name|BM_CTS
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCM_DSR
comment|/* Data Set Ready */
if|if
condition|(
name|y
operator|&
name|TIOCM_DSR
condition|)
name|z
operator||=
name|BM_DSR
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCM_CAR
comment|/* Carrier */
if|if
condition|(
name|y
operator|&
name|TIOCM_CAR
condition|)
name|z
operator||=
name|BM_DCD
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCM_RNG
comment|/* Ring Indicate */
if|if
condition|(
name|y
operator|&
name|TIOCM_RNG
condition|)
name|z
operator||=
name|BM_RNG
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCM_DTR
comment|/* Data Terminal Ready */
if|if
condition|(
name|y
operator|&
name|TIOCM_DTR
condition|)
name|z
operator||=
name|BM_DTR
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCM_RTS
comment|/* Request To Send */
if|if
condition|(
name|y
operator|&
name|TIOCM_RTS
condition|)
name|z
operator||=
name|BM_RTS
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|z
operator|)
return|;
else|#
directive|else
if|if
condition|(
name|netconn
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
return|return
operator|(
operator|-
literal|3
operator|)
return|;
endif|#
directive|endif
comment|/* K_MDMCTL */
endif|#
directive|endif
comment|/* HPUX */
block|}
comment|/*  P S U S P E N D  --  Put this process in the background.  */
comment|/*   Call with flag nonzero if suspending is allowed, zero if not allowed.   Returns 0 on apparent success, -1 on failure (flag was zero, or   kill() returned an error code. */
name|int
name|psuspend
parameter_list|(
name|flag
parameter_list|)
name|int
name|flag
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|RTU
specifier|extern
name|int
name|rtu_bug
decl_stmt|;
endif|#
directive|endif
comment|/* RTU */
if|if
condition|(
name|flag
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
ifdef|#
directive|ifdef
name|NOJC
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|SIGTSTP
comment|/*   The big question here is whether job control is *really* supported.   There's no way Kermit can know for sure.  The fact that SIGTSTP is   defined does not guarantee the Unix kernel supports it, and the fact   that the Unix kernel supports it doesn't guarantee that the user's   shell (or other process that invoked Kermit) supports it. */
ifdef|#
directive|ifdef
name|RTU
name|rtu_bug
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* RTU */
if|if
condition|(
name|kill
argument_list|(
literal|0
argument_list|,
name|SIGSTOP
argument_list|)
operator|<
literal|0
ifdef|#
directive|ifdef
name|OXOS
comment|/*   Because "kill(myself,SIGSTOP)" can't be caught, blocked, or ignored..." */
operator|&&
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGSTOP
argument_list|)
operator|<
literal|0
else|#
directive|else
ifdef|#
directive|ifdef
name|MIPS
comment|/* Let's try this for MIPS too. */
operator|&&
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGSTOP
argument_list|)
operator|<
literal|0
endif|#
directive|endif
comment|/* MIPS */
endif|#
directive|endif
comment|/* OXOS */
condition|)
block|{
comment|/* If job control, suspend the job */
name|perror
argument_list|(
literal|"suspend"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"psuspend error"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|debug
argument_list|(
name|F100
argument_list|,
literal|"psuspend ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* SIGTSTP */
endif|#
directive|endif
comment|/* NOJC */
block|}
comment|/*   setuid package, by Kristoffer Eriksson, with contributions from Dean   Long and fdc. */
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
ifndef|#
directive|ifndef
name|SUNOS4
ifndef|#
directive|ifndef
name|NEXT
ifndef|#
directive|ifndef
name|PS2AIX10
specifier|extern
name|UID_T
name|getuid
argument_list|()
decl_stmt|,
name|geteuid
argument_list|()
decl_stmt|,
name|getreuid
argument_list|()
decl_stmt|;
specifier|extern
name|GID_T
name|getgid
argument_list|()
decl_stmt|,
name|getegid
argument_list|()
decl_stmt|,
name|getregid
argument_list|()
decl_stmt|;
endif|#
directive|endif
comment|/* PS2AIX10 */
endif|#
directive|endif
comment|/* NEXT */
endif|#
directive|endif
comment|/* SUNOS4 */
endif|#
directive|endif
comment|/* _POSIX_SOURCE */
comment|/* Subject: Set-user-id To: fdc@watsun.cc.columbia.edu (Frank da Cruz) Date: Sat, 21 Apr 90 4:48:25 MES From: Kristoffer Eriksson<ske@pkmab.se>  This is a set of functions to be used in programs that may be run set-user-id and/or set-group-id. They handle both the case where the program is not run with such privileges (nothing special happens then), and the case where one or both of these set-id modes are used.  The program is made to run with the user's real user and group ids most of the time, except for when more privileges are needed.  Don't set-user-id to "root".  This works on System V and POSIX.  In BSD, it depends on the "saved-set-user-id" feature. */
define|#
directive|define
name|UID_ROOT
value|0
comment|/* Root user and group ids */
define|#
directive|define
name|GID_ROOT
value|0
comment|/*   The following construction automatically defines the symbol SETREUID for   Unix versions based on Berkeley Unix 4.2 or later.  If this symbol is    defined, then this program will use getreuid() and getregid() calls in   preference to getuid() and getgid(), which in Berkeley-based Unixes do   not allow arbitrary switching back and forth of real& effective uid.   This construction also allows -DSETREUID to be put on the cc command line   for any system that has and wants to use setre[ug]id().  It also prevents   automatic definition of SETREUID if -DNOSETREU is included on the cc    command line (or otherwise defined). */
ifdef|#
directive|ifdef
name|FT18
comment|/* None of this for Fortune. */
define|#
directive|define
name|NOSETREU
endif|#
directive|endif
comment|/* FT18 */
ifdef|#
directive|ifdef
name|ANYBSD
ifndef|#
directive|ifndef
name|BSD29
ifndef|#
directive|ifndef
name|BSD41
ifndef|#
directive|ifndef
name|SETREUID
ifndef|#
directive|ifndef
name|NOSETREU
define|#
directive|define
name|SETREUID
endif|#
directive|endif
comment|/* NOSETREU */
endif|#
directive|endif
comment|/* SETREUID */
endif|#
directive|endif
comment|/* !BSD41 */
endif|#
directive|endif
comment|/* !BSD29 */
endif|#
directive|endif
comment|/* ANYBSD */
comment|/* Variables for user and group IDs. */
specifier|static
name|UID_T
name|realuid
init|=
operator|(
name|UID_T
operator|)
operator|-
literal|1
decl_stmt|,
name|privuid
init|=
operator|(
name|UID_T
operator|)
operator|-
literal|1
decl_stmt|;
specifier|static
name|GID_T
name|realgid
init|=
operator|(
name|GID_T
operator|)
operator|-
literal|1
decl_stmt|,
name|privgid
init|=
operator|(
name|GID_T
operator|)
operator|-
literal|1
decl_stmt|;
comment|/* P R I V _ I N I  --  Initialize privileges package  */
comment|/* Called as early as possible in a set-uid or set-gid program to store the  * set-to uid and/or gid and step down to the users real uid and gid. The  * stored id's can be temporarily restored (allowed in System V) during  * operations that require the privilege.  Most of the time, the program  * should execute in unpriviliged state, to not impose any security threat.  *  * Note: Don't forget that access() always uses the real id:s to determine  * file access, even with privileges restored.  *  * Returns an error mask, with error values or:ed together:  *   1 if setuid() fails,  *   2 if setgid() fails, and  *   4 if the program is set-user-id to "root", which can't be handled.  *  * Only the return value 0 indicates real success. In case of failure,  * those privileges that could be reduced have been, at least, but the  * program should be aborted none-the-less.  *  * Also note that these functions do not expect the uid or gid to change  * without their knowing. It may work if it is only done temporarily, but  * you're on your own.  */
name|int
name|priv_ini
parameter_list|()
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|/* Save real ID:s. */
name|realuid
operator|=
name|getuid
argument_list|()
expr_stmt|;
name|realgid
operator|=
name|getgid
argument_list|()
expr_stmt|;
comment|/* Save current effective ID:s, those set to at program exec. */
name|privuid
operator|=
name|geteuid
argument_list|()
expr_stmt|;
name|privgid
operator|=
name|getegid
argument_list|()
expr_stmt|;
comment|/* If running set-uid, go down to real uid, otherwise remember that      * no privileged uid is available.      *      * Exceptions:      *      * 1) If the real uid is already "root" and the set-uid uid (the      * initial effective uid) is not "root", then we would have trouble      * if we went "down" to "root" here, and then temporarily back to the      * set-uid uid (not "root") and then again tried to become "root". I      * think the "saved set-uid" is lost when changing uid from effective      * uid "root", which changes all uid, not only the effective uid. But      * in this situation, we can simply go to "root" and stay there all      * the time. That should give sufficient privilege (understatement!),      * and give the right uids for subprocesses.      *      * 2) If the set-uid (the initial effective uid) is "root", and we      * change uid to the real uid, we can't change it back to "root" when      * we need the privilege, for the same reason as in 1). Thus, we can't      * handle programs that are set-user-id to "root" at all. The program      * should be aborted. Use some other uid. "root" is probably to      * privileged for such things, anyway. (The uid is reverted to the      * real uid until abortion.)      *      * These two exceptions have the effect that the "root" uid will never      * be one of the two uids that are being switched between, which also      * means we don't have to check for such cases in the switching      * functions.      *      * Note that exception 1) is handled by these routines (by constantly      * running with uid "root", while exception 2) is a serious error, and      * is not provided for at all in the switching functions.      */
if|if
condition|(
name|realuid
operator|==
name|privuid
condition|)
name|privuid
operator|=
operator|(
name|UID_T
operator|)
operator|-
literal|1
expr_stmt|;
comment|/* Not running set-user-id. */
comment|/* If running set-gid, go down to real gid, otherwise remember that      * no privileged gid is available.      *      * There are no exception like there is for the user id, since there      * is no group id that is privileged in the manner of uid "root".      * There could be equivalent problems for group changing if the      * program sometimes ran with uid "root" and sometimes not, but      * that is already avoided as explained above.      *      * Thus we can expect always to be able to switch to the "saved set-      * gid" when we want, and back to the real gid again. You may also      * draw the conclusion that set-gid provides for fewer hassles than      * set-uid.      */
if|if
condition|(
name|realgid
operator|==
name|privgid
condition|)
comment|/* If not running set-user-id, */
name|privgid
operator|=
operator|(
name|GID_T
operator|)
operator|-
literal|1
expr_stmt|;
comment|/*  remember it this way. */
name|err
operator|=
name|priv_off
argument_list|()
expr_stmt|;
comment|/* Turn off setuid privilege. */
if|if
condition|(
name|privuid
operator|==
name|UID_ROOT
condition|)
comment|/* If setuid to root, */
name|err
operator||=
literal|4
expr_stmt|;
comment|/* return this error. */
if|if
condition|(
name|realuid
operator|==
name|UID_ROOT
condition|)
comment|/* If real id is root, */
name|privuid
operator|=
operator|(
name|UID_T
operator|)
operator|-
literal|1
expr_stmt|;
comment|/* stay root at all times. */
return|return
operator|(
name|err
operator|)
return|;
block|}
comment|/* Macros for hiding the differences in UID/GID setting between various Unix  * systems. These macros should always be called with both the privileged ID  * and the non-privileged ID. The one in the second argument, will become the  * effective ID. The one in the first argument will be retained for later  * retrieval.  */
ifdef|#
directive|ifdef
name|SETREUID
ifdef|#
directive|ifdef
name|SAVEDUID
comment|/* On BSD systems with the saved-UID feature, we just juggle the effective  * UID back and forth, and leave the real UID at its true value.  The kernel  * allows switching to both the current real UID, the effective UID, and the  * UID which the program is set-UID to.  The saved set-UID always holds the  * privileged UID for us, and the real UID will always be the non-privileged,  * and we can freely choose one of them for the effective UID at any time.  */
define|#
directive|define
name|switchuid
parameter_list|(
name|hidden
parameter_list|,
name|active
parameter_list|)
value|setreuid( (UID_T) -1, active)
define|#
directive|define
name|switchgid
parameter_list|(
name|hidden
parameter_list|,
name|active
parameter_list|)
value|setregid( (GID_T) -1, active)
else|#
directive|else
comment|/* SETREUID,!SAVEDUID */
comment|/* On systems with setreXid() but without the saved-UID feature, notably  * BSD 4.2, we swap the real and effective UIDs each time.  It's  * the effective UID that we are interrested in, but we have to retain the  * unused UID somewhere to enable us to restore it later, and that we do this  * in the real UID.  The kernel only allows switching to either the current   * real or the effective UID, unless you're "root".  */
define|#
directive|define
name|switchuid
parameter_list|(
name|hidden
parameter_list|,
name|active
parameter_list|)
value|setreuid(hidden,active)
define|#
directive|define
name|switchgid
parameter_list|(
name|hidden
parameter_list|,
name|active
parameter_list|)
value|setregid(hidden,active)
endif|#
directive|endif
else|#
directive|else
comment|/* !SETREUID, !SAVEDUID */
comment|/* On System V and POSIX, the only thing we can change is the effective UID  * (unless the current effective UID is "root", but initsuid() avoids that for  * us).  The kernel allows switching to the current real UID or to the saved  * set-UID.  These are always set to the non-privileged UID and the privileged  * UID, respectively, and we only change the effective UID.  This breaks if  * the current effective UID is "root", though, because for "root" setuid/gid  * becomes more powerful, which is why initsuid() treats "root" specially.  * Note: That special treatment maybe could be ignored for BSD?  Note: For  * systems that don't fit any of these three cases, we simply can't support  * set-UID.  */
define|#
directive|define
name|switchuid
parameter_list|(
name|hidden
parameter_list|,
name|active
parameter_list|)
value|setuid(active)
define|#
directive|define
name|switchgid
parameter_list|(
name|hidden
parameter_list|,
name|active
parameter_list|)
value|setgid(active)
endif|#
directive|endif
comment|/* SETREUID */
comment|/* P R I V _ O N  --  Turn on the setuid and/or setgid */
comment|/* Go to the privileged uid (gid) that the program is set-user-id  * (set-group-id) to, unless the program is running unprivileged.  * If setuid() fails, return value will be 1. If getuid() fails it  * will be 2.  Return immediately after first failure, and the function  * tries to restore any partial work done.  Returns 0 on success.  * Group id is changed first, since it is less serious than user id.  */
name|int
name|priv_on
parameter_list|()
block|{
if|if
condition|(
name|privgid
operator|!=
operator|(
name|GID_T
operator|)
operator|-
literal|1
condition|)
if|if
condition|(
name|switchgid
argument_list|(
name|realgid
argument_list|,
name|privgid
argument_list|)
condition|)
return|return
operator|(
literal|2
operator|)
return|;
if|if
condition|(
name|privuid
operator|!=
operator|(
name|UID_T
operator|)
operator|-
literal|1
condition|)
if|if
condition|(
name|switchuid
argument_list|(
name|realuid
argument_list|,
name|privuid
argument_list|)
condition|)
block|{
if|if
condition|(
name|privgid
operator|!=
operator|(
name|GID_T
operator|)
operator|-
literal|1
condition|)
name|switchgid
argument_list|(
name|privgid
argument_list|,
name|realgid
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* P R I V _ O F F  --  Turn on the real uid and gid */
comment|/* Return to the unprivileged uid (gid) after an temporary visit to  * privileged status, unless the program is running without set-user-id  * (set-group-id). Returns 1 for failure in setuid() and 2 for failure  * in setgid() or:ed together. The functions tries to return both uid  * and gid to unprivileged state, regardless of errors. Returns 0 on  * success.  */
name|int
name|priv_off
parameter_list|()
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|privuid
operator|!=
operator|(
name|UID_T
operator|)
operator|-
literal|1
condition|)
if|if
condition|(
name|switchuid
argument_list|(
name|privuid
argument_list|,
name|realuid
argument_list|)
condition|)
name|err
operator||=
literal|1
expr_stmt|;
if|if
condition|(
name|privgid
operator|!=
operator|(
name|GID_T
operator|)
operator|-
literal|1
condition|)
if|if
condition|(
name|switchgid
argument_list|(
name|privgid
argument_list|,
name|realgid
argument_list|)
condition|)
name|err
operator||=
literal|2
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
comment|/* Turn off privilege permanently.  No going back.  This is necessary before  * a fork() on BSD43 machines that don't save the setUID or setGID, because  * we swap the real and effective ids, and we don't want to let the forked  * process swap them again and get the privilege back. It will work on other  * machines too, such that you can rely on its effect always being the same,  * for instance, even when you're in priv_on() state when this is called.  * (Well, that part about "permanent" is on System V only true if you follow  * this with a call to exec(), but that's what we want it for anyway.)  * Added by Dean Long -- dlong@midgard.ucsc.edu  */
name|int
name|priv_can
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|SETREUID
name|int
name|err
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|privuid
operator|!=
operator|(
name|UID_T
operator|)
operator|-
literal|1
condition|)
if|if
condition|(
name|setreuid
argument_list|(
name|realuid
argument_list|,
name|realuid
argument_list|)
condition|)
name|err
operator||=
literal|1
expr_stmt|;
if|if
condition|(
name|privgid
operator|!=
operator|(
name|GID_T
operator|)
operator|-
literal|1
condition|)
if|if
condition|(
name|setregid
argument_list|(
name|realgid
argument_list|,
name|realgid
argument_list|)
condition|)
name|err
operator||=
literal|2
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
else|#
directive|else
comment|/* Easy way of using setuid()/setgid() instead of setreuid()/setregid().*/
return|return
operator|(
name|priv_off
argument_list|()
operator|)
return|;
endif|#
directive|endif
comment|/* SETREUID */
block|}
comment|/* P R I V _ O P N  --  For opening protected files or devices. */
name|int
name|priv_opn
parameter_list|(
name|name
parameter_list|,
name|modes
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|modes
decl_stmt|;
block|{
name|int
name|x
decl_stmt|;
name|priv_on
argument_list|()
expr_stmt|;
comment|/* Turn privileges on */
name|x
operator|=
name|open
argument_list|(
name|name
argument_list|,
name|modes
argument_list|)
expr_stmt|;
comment|/* Try to open the device */
name|priv_off
argument_list|()
expr_stmt|;
comment|/* Turn privileges off */
return|return
operator|(
name|x
operator|)
return|;
comment|/* Return open's return code */
block|}
comment|/*  P R I V _ C H K  --  Check privileges.  */
comment|/*  Try to turn them off.  If turning them off did not succeed, cancel them */
name|int
name|priv_chk
parameter_list|()
block|{
name|int
name|x
decl_stmt|,
name|y
init|=
literal|0
decl_stmt|;
name|x
operator|=
name|priv_off
argument_list|()
expr_stmt|;
comment|/* Turn off privs. */
if|if
condition|(
name|x
operator|!=
literal|0
operator|||
name|getuid
argument_list|()
operator|==
name|privuid
operator|||
name|geteuid
argument_list|()
operator|==
name|privuid
condition|)
name|y
operator|=
name|priv_can
argument_list|()
expr_stmt|;
if|if
condition|(
name|x
operator|!=
literal|0
operator|||
name|getgid
argument_list|()
operator|==
name|privgid
operator|||
name|getegid
argument_list|()
operator|==
name|privgid
condition|)
name|y
operator|=
name|y
operator||
name|priv_can
argument_list|()
expr_stmt|;
return|return
operator|(
name|y
operator|)
return|;
block|}
name|UID_T
name|real_uid
parameter_list|()
block|{
return|return
operator|(
name|realuid
operator|)
return|;
block|}
name|VOID
name|ttimoff
parameter_list|()
block|{
comment|/* Turn off any timer interrupts */
name|int
name|xx
decl_stmt|;
comment|/*   As of 5A(183), we set SIGALRM to SIG_IGN (to ignore alarms) rather than to   SIG_DFL (to catch alarms, or if there is no handler, to exit).  This is to   cure (mask, really) a deeper problem with stray alarms that occurs on some   systems, possibly having to do with sleep(), that caused core dumps.  It   should be OK to do this, because no code in this module uses nested alarms.   (But we still have to watch out for SCRIPT and DIAL...) */
name|xx
operator|=
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* debug(F101,"ttimoff alarm","",xx); */
if|if
condition|(
name|saval
condition|)
block|{
comment|/* Restore any previous */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|saval
argument_list|)
expr_stmt|;
comment|/* alarm handler. */
comment|/* debug(F101,"ttimoff alarm restoring saval","",saval); */
name|saval
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Used to be SIG_DFL */
comment|/* debug(F100,"ttimoff alarm SIG_IGN","",0); */
block|}
block|}
end_function

end_unit

