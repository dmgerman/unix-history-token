begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|ckxv
init|=
literal|"Unix tty I/O, 4C(037), 31 Jul 85"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K U T I O  */
end_comment

begin_comment
comment|/* C-Kermit interrupt, terminal control& i/o functions for Unix systems */
end_comment

begin_comment
comment|/*  Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_comment
comment|/* Includes for all Unixes (conditional includes come later) */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Types */
end_comment

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_comment
comment|/* Directory */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* Character types */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Unix Standard i/o */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* Interrupts */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* Longjumps */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* Typedefs, formats for debug() */
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

begin_comment
comment|/* 4.1 BSD support added by Charles E. Brooks, EDN-VAX */
end_comment

begin_comment
comment|/* Fortune 16:32 For:Pro 1.7 support mostly like 4.1, added by J-P Dumas */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_define
define|#
directive|define
name|ANYBSD
end_define

begin_undef
undef|#
directive|undef
name|DIRSIZ
end_undef

begin_define
define|#
directive|define
name|DIRSIZ
value|(sizeof(struct direct))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MAXNAMLEN
end_ifdef

begin_define
define|#
directive|define
name|BSD42
end_define

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" 4.2 BSD"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|FT17
end_ifdef

begin_define
define|#
directive|define
name|BSD41
end_define

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" For:Pro Fortune 1.7"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BSD41
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|C70
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" 4.1 BSD"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 2.9bsd support contributed by Bradley Smith, UCLA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
end_ifdef

begin_define
define|#
directive|define
name|ANYBSD
end_define

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" 2.9 BSD"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  Version 7 UNIX support contributed by Gregg Wonderly,  Oklahoma State University:  gregg@okstate.csnet */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" Version 7 UNIX (tm)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|V7
end_endif

begin_comment
comment|/* BBN C70 support from Frank Wancho, WANCHO@SIMTEL20 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|C70
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" BBN C/70"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Amdahl UTS 2.4 (v7 derivative) for IBM 370 series compatible mainframes */
end_comment

begin_comment
comment|/* Contributed by Garard Gaye, Jean-Pierre Dumas, DUMAS@SUMEX-AIM. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UTS24
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" Amdahl UTS 2.4"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Pro/Venix Version 1.x support from Columbia U. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" Pro-3xx Venix v1"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tower support contributed by John Bray, Auburn, Alabama */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TOWER1
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" NCR Tower 1632, OS 1.02"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sys III/V, Xenix, PC/IX support by Herm Fischer, Encino, CA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UXIII
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|XENIX
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" Xenix/286"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PCIX
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" PC/IX"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ISIII
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" Interactive Systems Corp System III"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|ckxsys
init|=
literal|" AT&T System III/System V"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Features... */
end_comment

begin_comment
comment|/* Do own buffering, using unbuffered read() calls... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UXIII
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
comment|/*  Note - KERLD is the Berkeley Unix Berknet line driver, modified to pass  through all 8  bits, and to allow an arbitrary break character to be set.  Don't define this symbol unless you have made this modification to your  4.2BSD kernel! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_comment
comment|/* #define KERLD */
end_comment

begin_comment
comment|/*<-- note, commented out */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*  Variables available to outside world:     dftty  -- Pointer to default tty name string, like "/dev/tty".    dfloc  -- 0 if dftty is console, 1 if external line.    dfprty -- Default parity    dfflow -- Default flow control    ckxech -- Flag for who echoes console typein:      1 - The program (system echo is turned off)      0 - The system (or front end, or terminal).    functions that want to do their own echoing should check this flag    before doing so.     flfnam -- Name of lock file, including its path, e.g., 		"/usr/spool/uucp/LCK..cul0" or "/etc/locks/tty77"    hasLock -- Flag set if this kermit established a uucp lock.    inbufc -- number of tty line rawmode unread characters  		(system III/V unixes)    backgrd -- Flag indicating program executing in background (& on  		end of shell command). Used to ignore INT and QUIT signals.   Functions for assigned communication line (either external or console tty):     sysinit()               -- System dependent program initialization    ttopen(ttname,local,mdmtyp) -- Open the named tty for exclusive access.    ttclos()                -- Close& reset the tty, releasing any access lock.    ttpkt(speed,flow)       -- Put the tty in packet mode and set the speed.    ttvt(speed,flow)        -- Put the tty in virtual terminal mode. 				or in DIALING or CONNECTED modem control state.    ttinl(dest,max,timo)    -- Timed read line from the tty.    ttinc(timo)             -- Timed read character from tty.    myread()		   -- System 3 raw mode bulk buffer read, gives 			   --   subsequent chars one at a time and simulates 			   --   FIONREAD!    myunrd(c)		   -- Places c back in buffer to be read (one only)    ttchk()                 -- See how many characters in tty input buffer.    ttxin(n,buf)            -- Read n characters from tty (untimed).    ttol(string,length)     -- Write a string to the tty.    ttoc(c)                 -- Write a character to the tty.    ttflui()                -- Flush tty input buffer.     ttlock(ttname)	   -- Lock against uucp collisions (Sys III)    ttunlck()		   -- Unlock "       "     "    look4lk(ttname)	   -- Check if a lock file exists */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Functions for console terminal:     congm()   -- Get console terminal modes.    concb(esc) -- Put the console in single-character wakeup mode with no echo.    conbin(esc) -- Put the console in binary (raw) mode.    conres()  -- Restore the console to mode obtained by congm().    conoc(c)  -- Unbuffered output, one character to console.    conol(s)  -- Unbuffered output, null-terminated string to the console.    conola(s) -- Unbuffered output, array of strings to the console.    conxo(n,s) -- Unbuffered output, n characters to the console.    conchk()  -- Check if characters available at console (bsd 4.2). 		Check if escape char (^\) typed at console (System III/V).    coninc(timo)  -- Timed get a character from the console.    conint()  -- Enable terminal interrupts on the console if not background.    connoi()  -- Disable terminal interrupts on the console if not background.  Time functions     msleep(m) -- Millisecond sleep    ztime(&s) -- Return pointer to date/time string    rtimer() --  Reset timer    gtimer()  -- Get elapsed time since last call to rtimer() */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Conditional Includes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT17
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|/* File information */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PROVX1
end_ifndef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|/* File information */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System III, System V */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UXIII
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* directory reading for locking */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* error numbers for system returns */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not Sys III/V */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UXIII
end_ifndef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/* Set/Get tty modes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROVX1
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

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
name|BSD41
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_comment
comment|/* BSD 4.1 ... ceb */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_escape
end_escape

begin_comment
comment|/* Declarations */
end_comment

begin_function_decl
name|long
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* All Unixes should have this... */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System call error return */
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
comment|/* dftty is the device name of the default device for file transfer */
end_comment

begin_comment
comment|/* dfloc is 0 if dftty is the user's console terminal, 1 if an external line */
end_comment

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

begin_decl_stmt
name|int
name|dfprty
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parity (0 = none) */
end_comment

begin_decl_stmt
name|int
name|dfflow
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Xon/Xoff flow control */
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
name|long
name|tcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Elapsed time counter */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|brnuls
init|=
literal|"\0\0\0\0\0\0\0"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A string of nulls */
end_comment

begin_decl_stmt
specifier|static
name|jmp_buf
name|sjbuf
decl_stmt|,
name|jjbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Longjump buffer */
end_comment

begin_decl_stmt
specifier|static
name|int
name|lkf
init|=
literal|0
decl_stmt|,
comment|/* Line lock flag */
name|conif
init|=
literal|0
decl_stmt|,
comment|/* Console interrupts on/off flag */
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
specifier|static
name|char
name|escchr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Escape or attn character */
end_comment

begin_comment
comment|/* Special line discipline, 4.2bsd only, and only with kernel mods... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERLD
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|kerld
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Special Kermit line discipline... */
end_comment

begin_decl_stmt
name|struct
name|tchars
name|oldc
decl_stmt|,
name|newc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Special characters */
end_comment

begin_decl_stmt
name|int
name|ld
init|=
name|NETLDISC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Really a hack to "Berknet" l.d. */
end_comment

begin_decl_stmt
name|int
name|oldld
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Old discipline */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|int
name|kerld
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Not selected, no special l.d. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
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

begin_comment
comment|/* Same as 4.2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD41
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|clock
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

begin_ifdef
ifdef|#
directive|ifdef
name|TOWER1
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|clock
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

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|clock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UXIII
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|termio
comment|/* sgtty info... */
name|ttold
decl_stmt|,
name|ttraw
decl_stmt|,
name|tttvt
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
name|ttbuf
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

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
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

begin_decl_stmt
specifier|static
name|int
name|hasLock
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* =1 if this kermit locked uucp */
end_comment

begin_decl_stmt
specifier|static
name|int
name|inbufc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stuff for efficient SIII raw line */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ungotn
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pushback to unread character */
end_comment

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

begin_function_decl
specifier|static
name|int
name|ttlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* definition of ttlock subprocedure */
end_comment

begin_function_decl
specifier|static
name|int
name|ttunlck
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* and unlock subprocedure */
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
comment|/* copy of open path for tthang */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  S Y S I N I T  --  System-dependent program initialization.  */
end_comment

begin_macro
name|sysinit
argument_list|()
end_macro

begin_block
block|{
comment|/* for now, nothing... */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T O P E N  --  Open a tty for exclusive access.  */
end_comment

begin_comment
comment|/*  Returns 0 on success, -1 on failure.  */
end_comment

begin_comment
comment|/*   If called with lcl< 0, sets value of lcl as follows:   0: the terminal named by ttname is the job's controlling terminal.   1: the terminal named by ttname is not the job's controlling terminal.   But watch out: if a line is already open, or if requested line can't   be opened, then lcl remains (and is returned as) -1. */
end_comment

begin_macro
name|ttopen
argument_list|(
argument|ttname
argument_list|,
argument|lcl
argument_list|,
argument|modem
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ttname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|lcl
decl_stmt|,
name|modem
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|UXIII
name|char
modifier|*
name|ctermid
parameter_list|()
function_decl|;
comment|/* Wish they all had this! */
endif|#
directive|endif
name|char
modifier|*
name|x
decl_stmt|;
specifier|extern
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
name|char
name|cname
index|[
name|DEVNAMLEN
index|]
decl_stmt|;
if|if
condition|(
name|ttyfd
operator|>
operator|-
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* If already open, ignore this call */
name|xlocal
operator|=
operator|*
name|lcl
expr_stmt|;
comment|/* Make this available to other fns */
ifndef|#
directive|ifndef
name|UXIII
name|ttyfd
operator|=
name|open
argument_list|(
name|ttname
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|/* Try to open for read/write */
else|#
directive|else
comment|/* if modem connection, don't wait for carrier */
name|ttyfd
operator|=
name|open
argument_list|(
name|ttname
argument_list|,
name|O_RDWR
operator||
operator|(
name|modem
condition|?
name|O_NDELAY
else|:
literal|0
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
block|{
comment|/* If couldn't open, fail. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|strncpy
argument_list|(
name|ttnmsv
argument_list|,
name|ttname
argument_list|,
name|DEVNAMLEN
argument_list|)
expr_stmt|;
comment|/* Open, keep copy of name locally. */
comment|/* Caller wants us to figure out if line is controlling tty */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttopen"
argument_list|,
name|ttname
argument_list|,
operator|*
name|lcl
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|lcl
operator|==
operator|-
literal|1
condition|)
block|{
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
name|debug
argument_list|(
name|F110
argument_list|,
literal|" Same as CTTNAM"
argument_list|,
name|ttname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xlocal
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
block|{
comment|/* Else, if stdin not redirected */
name|x
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* then compare its device name */
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
literal|" ttyname(0)"
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
comment|/* ...with real name of ttname. */
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
block|}
else|else
block|{
comment|/* Else, if stdin redirected... */
ifdef|#
directive|ifdef
name|UXIII
comment|/* Sys III/V provides nice ctermid() function to get name of controlling tty */
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
comment|/* Just assume local, so "set speed" and similar commands will work */
comment|/* If not really local, how could it work anyway?... */
name|xlocal
operator|=
literal|1
expr_stmt|;
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
endif|#
directive|endif
block|}
block|}
comment|/* Now check if line is locked -- if so fail, else lock for ourselves */
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
if|if
condition|(
name|ttlock
argument_list|(
name|ttname
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Exclusive access to %s denied\n"
argument_list|,
name|ttname
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
name|debug
argument_list|(
name|F110
argument_list|,
literal|" Access denied by lock"
argument_list|,
name|ttname
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
comment|/* Not if already locked */
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
operator|<
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
endif|V7
comment|/* Request exclusive access on systems that allow it. */
ifndef|#
directive|ifndef
name|XENIX
comment|/* Xenix exclusive access prevents open(close(...)) from working... */
ifdef|#
directive|ifdef
name|TIOCEXCL
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCEXCL
argument_list|,
name|NULL
argument_list|)
operator|<
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning, problem getting exclusive access\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* Get tty device settings */
ifndef|#
directive|ifndef
name|UXIII
name|gtty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttold
argument_list|)
expr_stmt|;
comment|/* Get sgtty info */
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
else|#
directive|else
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
comment|/* Same deal for Sys III, Sys V */
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
endif|#
directive|endif
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
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T C L O S  --  Close the TTY, releasing any lock.  */
end_comment

begin_macro
name|ttclos
argument_list|()
end_macro

begin_block
block|{
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
name|xlocal
condition|)
block|{
if|if
condition|(
name|tthang
argument_list|()
condition|)
comment|/* Hang up phone line */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning, problem hanging up the phone\n"
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
literal|"Warning, problem releasing lock\n"
argument_list|)
expr_stmt|;
block|}
name|ttres
argument_list|()
expr_stmt|;
comment|/* Reset modes. */
comment|/* Relinquish exclusive access if we might have had it... */
ifndef|#
directive|ifndef
name|XENIX
ifdef|#
directive|ifdef
name|TIOCEXCL
ifdef|#
directive|ifdef
name|TIOCNXCL
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCNXCL
argument_list|,
name|NULL
argument_list|)
operator|<
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning, problem relinquishing exclusive access\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Close it. */
name|ttyfd
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Mark it as closed. */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  T T H A N G -- Hangup phone line */
end_comment

begin_macro
name|tthang
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|UXIII
name|unsigned
name|short
name|ttc_save
decl_stmt|;
endif|#
directive|endif
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
comment|/* Not open. */
ifdef|#
directive|ifdef
name|ANYBSD
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCCDTR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear DTR */
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
comment|/* Let things settle */
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UXIII
name|ttc_save
operator|=
name|ttraw
operator|.
name|c_cflag
expr_stmt|;
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
expr_stmt|;
comment|/* swa: set baud rate to 0 to hangup */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAF
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
comment|/* do it */
name|msleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|/* let things settle */
name|ttraw
operator|.
name|c_cflag
operator|=
name|ttc_save
expr_stmt|;
ifndef|#
directive|ifndef
name|XENIX
comment|/* xenix cannot do close/open when carrier drops */
comment|/* following corrects a PC/IX defficiency */
name|ttc_save
operator|=
name|fcntl
argument_list|(
name|ttyfd
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* close/reopen file descriptor */
if|if
condition|(
operator|(
name|ttyfd
operator|=
name|open
argument_list|(
name|ttnmsv
argument_list|,
name|ttc_save
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
endif|#
directive|endif
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAF
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
comment|/* un-do it */
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  T T R E S  --  Restore terminal to "normal" mode.  */
end_comment

begin_macro
name|ttres
argument_list|()
end_macro

begin_block
block|{
comment|/* Restore the tty to normal. */
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
ifndef|#
directive|ifndef
name|UXIII
comment|/* except for sIII, */
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Wait for pending i/o to finish. */
endif|#
directive|endif
comment|/*   (sIII does wait in ioctls) */
ifdef|#
directive|ifdef
name|KERLD
if|if
condition|(
name|kerld
condition|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETD
argument_list|,
operator|&
name|oldld
argument_list|)
expr_stmt|;
comment|/* Restore old line discipline. */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UXIII
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|ttold
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
comment|/* restore termio stuff */
else|#
directive|else
if|if
condition|(
name|stty
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|ttold
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
comment|/* Restore sgtty stuff */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|KERLD
if|if
condition|(
name|kerld
condition|)
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|oldc
argument_list|)
expr_stmt|;
comment|/* Restore old special chars. */
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* Exclusive uucp file locking control */
end_comment

begin_comment
comment|/*  by H. Fischer, creative non-Bell coding !  copyright rights for lock modules assigned to Columbia University */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|xxlast
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
block|{
comment|/* Equivalent to strrchr() */
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
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

begin_expr_stmt
specifier|static
name|look4lk
argument_list|(
argument|ttname
argument_list|)
name|char
operator|*
name|ttname
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|extern
name|char
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|;
name|char
modifier|*
name|device
decl_stmt|,
modifier|*
name|devname
decl_stmt|;
name|char
name|lockfil
index|[
name|DIRSIZ
operator|+
literal|1
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|ISIII
name|char
modifier|*
name|lockdir
init|=
literal|"/etc/locks"
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ATT3BX
name|char
modifier|*
name|lockdir
init|=
literal|"/usr/spool/locks"
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|lockdir
init|=
literal|"/usr/spool/uucp"
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|ISIII
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|lockfil
argument_list|,
name|device
argument_list|)
expr_stmt|;
else|#
directive|else
name|strcat
argument_list|(
name|strcpy
argument_list|(
name|lockfil
argument_list|,
literal|"LCK.."
argument_list|)
argument_list|,
name|device
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|access
argument_list|(
name|lockdir
argument_list|,
literal|04
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* read access denied on lock dir */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning, read access to lock directory denied\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
comment|/* cannot check or set lock file */
block|}
name|strcat
argument_list|(
name|strcat
argument_list|(
name|strcpy
argument_list|(
name|flfnam
argument_list|,
name|lockdir
argument_list|)
argument_list|,
literal|"/"
argument_list|)
argument_list|,
name|lockfil
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"look4lk"
argument_list|,
name|flfnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|access
argument_list|(
name|flfnam
argument_list|,
literal|00
argument_list|)
condition|)
block|{
comment|/* print out lock file entry */
name|char
name|lckcmd
index|[
literal|40
index|]
decl_stmt|;
name|strcat
argument_list|(
name|strcpy
argument_list|(
name|lckcmd
argument_list|,
literal|"ls -l "
argument_list|)
argument_list|,
name|flfnam
argument_list|)
expr_stmt|;
name|system
argument_list|(
name|lckcmd
argument_list|)
expr_stmt|;
if|if
condition|(
name|access
argument_list|(
name|flfnam
argument_list|,
literal|02
argument_list|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"(You may type \"! rm %s\" to remove this file)\n"
argument_list|,
name|flfnam
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|access
argument_list|(
name|lockdir
argument_list|,
literal|02
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* lock file cannot be written */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning, write access to lock directory denied\n"
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
comment|/* okay to go ahead and lock */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T L O C K  */
end_comment

begin_expr_stmt
specifier|static
name|ttlock
argument_list|(
argument|ttyfd
argument_list|)
name|char
operator|*
name|ttyfd
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* lock uucp if possible */
ifdef|#
directive|ifdef
name|ATT3BX
name|FILE
modifier|*
name|lck_fild
decl_stmt|;
endif|#
directive|endif
name|int
name|lck_fil
decl_stmt|,
name|l4l
decl_stmt|;
name|int
name|pid_buf
init|=
name|getpid
argument_list|()
decl_stmt|;
comment|/* pid to save in lock file */
name|hasLock
operator|=
literal|0
expr_stmt|;
comment|/* not locked yet */
name|l4l
operator|=
name|look4lk
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|l4l
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* already locked */
if|if
condition|(
name|l4l
operator|==
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* can't read/write lock directory */
name|lck_fil
operator|=
name|creat
argument_list|(
name|flfnam
argument_list|,
literal|0444
argument_list|)
expr_stmt|;
comment|/* create lock file ... */
if|if
condition|(
name|lck_fil
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* create of lockfile failed */
comment|/* creat leaves file handle open for writing -- hf */
ifdef|#
directive|ifdef
name|ATT3BX
name|fprintf
argument_list|(
operator|(
name|lck_fild
operator|=
name|fdopen
argument_list|(
name|lck_fil
argument_list|,
literal|"w"
argument_list|)
operator|)
argument_list|,
literal|"%10d\n"
argument_list|,
name|pid_buf
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|lck_fild
argument_list|)
expr_stmt|;
else|#
directive|else
name|write
argument_list|(
name|lck_fil
argument_list|,
operator|&
name|pid_buf
argument_list|,
sizeof|sizeof
argument_list|(
name|pid_buf
argument_list|)
argument_list|)
expr_stmt|;
comment|/* uucp expects int in file */
endif|#
directive|endif
name|close
argument_list|(
name|lck_fil
argument_list|)
expr_stmt|;
name|hasLock
operator|=
literal|1
expr_stmt|;
comment|/* now is locked */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  T T U N L O C K  */
end_comment

begin_expr_stmt
specifier|static
name|ttunlck
argument_list|()
block|{
comment|/* kill uucp lock if possible */
if|if
condition|(
name|hasLock
condition|)
return|return
operator|(
name|unlink
argument_list|(
name|flfnam
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/*  T T P K T  --  Condition the communication line for packets. */
end_comment

begin_comment
comment|/*		or for modem dialing */
end_comment

begin_define
define|#
directive|define
name|DIALING
value|4
end_define

begin_comment
comment|/* flags (via flow) for modem handling */
end_comment

begin_define
define|#
directive|define
name|CONNECT
value|5
end_define

begin_comment
comment|/*  If called with speed> -1, also set the speed.  */
end_comment

begin_comment
comment|/*  Returns 0 on success, -1 on failure.  */
end_comment

begin_macro
name|ttpkt
argument_list|(
argument|speed
argument_list|,
argument|flow
argument_list|)
end_macro

begin_decl_stmt
name|int
name|speed
decl_stmt|,
name|flow
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|s
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
ifdef|#
directive|ifdef
name|KERLD
comment|/* Note, KERLD ignores the TANDEM, ECHO, and CRMOD bits */
if|if
condition|(
name|kerld
condition|)
block|{
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCGETD
argument_list|,
operator|&
name|oldld
argument_list|)
expr_stmt|;
comment|/* Get line discipline */
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCGETC
argument_list|,
operator|&
name|oldc
argument_list|)
expr_stmt|;
comment|/* Get special chars */
name|newc
operator|=
name|oldc
expr_stmt|;
comment|/* Copy special chars */
name|newc
operator|.
name|t_brkc
operator|=
literal|'\r'
expr_stmt|;
comment|/* Set CR to be break character */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|newc
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
block|}
endif|#
directive|endif
name|s
operator|=
name|ttsspd
argument_list|(
name|speed
argument_list|)
expr_stmt|;
comment|/* Check the speed */
ifndef|#
directive|ifndef
name|UXIII
if|if
condition|(
name|flow
operator|==
literal|1
condition|)
name|ttraw
operator|.
name|sg_flags
operator||=
name|TANDEM
expr_stmt|;
comment|/* Use XON/XOFF if selected */
if|if
condition|(
name|flow
operator|==
literal|0
condition|)
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
name|RAW
expr_stmt|;
comment|/* Go into raw mode */
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
comment|/* Use CR for break character */
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
comment|/* Must tell Tower no parityr */
endif|#
directive|endif
if|if
condition|(
name|s
operator|>
operator|-
literal|1
condition|)
name|ttraw
operator|.
name|sg_ispeed
operator|=
name|ttraw
operator|.
name|sg_ospeed
operator|=
name|s
expr_stmt|;
comment|/* Do the speed */
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
ifdef|#
directive|ifdef
name|MYREAD
ifdef|#
directive|ifdef
name|BSD4
comment|/* Try to make reads nonblocking */
if|if
condition|(
name|kerld
operator|==
literal|0
condition|)
block|{
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
name|FNDELAY
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UXIII
if|if
condition|(
name|flow
operator|==
literal|1
condition|)
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
if|if
condition|(
name|flow
operator|==
literal|0
condition|)
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
if|if
condition|(
name|flow
operator|==
name|DIALING
condition|)
name|ttraw
operator|.
name|c_cflag
operator||=
name|CLOCAL
operator||
name|HUPCL
expr_stmt|;
if|if
condition|(
name|flow
operator|==
name|CONNECT
condition|)
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
name|CLOCAL
expr_stmt|;
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
operator||=
name|ISIG
expr_stmt|;
comment|/* do check for interrupt */
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
operator|)
expr_stmt|;
name|ttraw
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
name|ttraw
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|s
operator|>
operator|-
literal|1
condition|)
name|ttraw
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
operator|,
name|ttraw
operator|.
name|c_cflag
operator||=
name|s
expr_stmt|;
comment|/* set speed */
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
if|if
condition|(
name|flow
operator|==
name|DIALING
condition|)
block|{
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
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|close
argument_list|(
name|open
argument_list|(
name|ttnmsv
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
comment|/* magic to force mode change!!! */
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|KERLD
if|if
condition|(
name|kerld
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCSETD
argument_list|,
operator|&
name|ld
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
comment|/* Set line discpline. */
block|}
endif|#
directive|endif
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush any pending input */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T V T -- Condition communication line for use as virtual terminal  */
end_comment

begin_macro
name|ttvt
argument_list|(
argument|speed
argument_list|,
argument|flow
argument_list|)
end_macro

begin_decl_stmt
name|int
name|speed
decl_stmt|,
name|flow
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|s
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
name|s
operator|=
name|ttsspd
argument_list|(
name|speed
argument_list|)
expr_stmt|;
comment|/* Check the speed */
ifndef|#
directive|ifndef
name|UXIII
if|if
condition|(
name|flow
operator|==
literal|1
condition|)
name|tttvt
operator|.
name|sg_flags
operator||=
name|TANDEM
expr_stmt|;
comment|/* XON/XOFF if selected */
if|if
condition|(
name|flow
operator|==
literal|0
condition|)
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
name|RAW
expr_stmt|;
comment|/* Raw mode */
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
comment|/* No echo or system III ??? parity */
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
if|if
condition|(
name|s
operator|>
operator|-
literal|1
condition|)
name|tttvt
operator|.
name|sg_ispeed
operator|=
name|tttvt
operator|.
name|sg_ospeed
operator|=
name|s
expr_stmt|;
comment|/* Do the speed */
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
return|return
operator|(
operator|-
literal|1
operator|)
return|;
ifdef|#
directive|ifdef
name|MYREAD
ifdef|#
directive|ifdef
name|BSD4
comment|/* Make reads nonblocking */
if|if
condition|(
name|kerld
operator|==
literal|0
condition|)
block|{
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
name|FNDELAY
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
endif|#
directive|endif
else|#
directive|else
if|if
condition|(
name|flow
operator|==
literal|1
condition|)
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
if|if
condition|(
name|flow
operator|==
literal|0
condition|)
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
if|if
condition|(
name|flow
operator|==
name|DIALING
condition|)
name|tttvt
operator|.
name|c_cflag
operator||=
name|CLOCAL
operator||
name|HUPCL
expr_stmt|;
if|if
condition|(
name|flow
operator|==
name|CONNECT
condition|)
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
name|CLOCAL
expr_stmt|;
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
operator|)
expr_stmt|;
name|tttvt
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
name|tttvt
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|s
operator|>
operator|-
literal|1
condition|)
name|tttvt
operator|.
name|c_cflag
operator|&=
operator|~
name|CBAUD
operator|,
name|tttvt
operator|.
name|c_cflag
operator||=
name|s
expr_stmt|;
comment|/* set speed */
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
if|if
condition|(
name|flow
operator|==
name|DIALING
condition|)
block|{
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
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|close
argument_list|(
name|open
argument_list|(
name|ttnmsv
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
comment|/* magic to force mode change!!! */
block|}
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T S S P D  --  Return the internal baud rate code for 'speed'.  */
end_comment

begin_macro
name|ttsspd
argument_list|(
argument|speed
argument_list|)
end_macro

begin_block
block|{
name|int
name|s
decl_stmt|,
name|spdok
decl_stmt|;
if|if
condition|(
name|speed
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|spdok
operator|=
literal|1
expr_stmt|;
comment|/* Assume arg ok */
switch|switch
condition|(
name|speed
condition|)
block|{
case|case
literal|0
case|:
name|s
operator|=
name|B0
expr_stmt|;
break|break;
comment|/* Just the common ones. */
case|case
literal|110
case|:
name|s
operator|=
name|B110
expr_stmt|;
break|break;
comment|/* The others from ttydev.h */
case|case
literal|150
case|:
name|s
operator|=
name|B150
expr_stmt|;
break|break;
comment|/* could also be included if */
case|case
literal|300
case|:
name|s
operator|=
name|B300
expr_stmt|;
break|break;
comment|/* necessary... */
case|case
literal|600
case|:
name|s
operator|=
name|B600
expr_stmt|;
break|break;
case|case
literal|1200
case|:
name|s
operator|=
name|B1200
expr_stmt|;
break|break;
case|case
literal|1800
case|:
name|s
operator|=
name|B1800
expr_stmt|;
break|break;
case|case
literal|2400
case|:
name|s
operator|=
name|B2400
expr_stmt|;
break|break;
case|case
literal|4800
case|:
name|s
operator|=
name|B4800
expr_stmt|;
break|break;
case|case
literal|9600
case|:
name|s
operator|=
name|B9600
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|PLEXUS
case|case
literal|19200
case|:
name|s
operator|=
name|EXTA
expr_stmt|;
break|break;
endif|#
directive|endif
default|default:
name|spdok
operator|=
literal|0
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unsupported line speed - %d\n"
argument_list|,
name|speed
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Current speed not changed\n"
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|spdok
condition|)
return|return
operator|(
name|s
operator|)
return|;
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  T T F L U I  --  Flush tty input buffer */
end_comment

begin_macro
name|ttflui
argument_list|()
end_macro

begin_block
block|{
ifndef|#
directive|ifndef
name|UXIII
name|long
name|n
decl_stmt|;
endif|#
directive|endif
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
name|ungotn
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Initialize myread() stuff */
name|inbufc
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|UXIII
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TCFLSH
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"flush failed"
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|TIOCFLUSH
if|#
directive|if
name|defined
argument_list|(
name|ANYBSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD4_4
argument_list|)
name|n
operator|=
name|FREAD
expr_stmt|;
comment|/* Specify read queue */
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCFLUSH
argument_list|,
operator|&
name|n
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"flush failed"
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|TIOCFLUSH
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"flush failed"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* Interrupt Functions */
end_comment

begin_comment
comment|/* Timeout handler for communication line input functions */
end_comment

begin_macro
name|timerh
argument_list|()
end_macro

begin_block
block|{
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Set up terminal interrupts on console terminal */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UXIII
end_ifdef

begin_macro
name|esctrp
argument_list|()
end_macro

begin_block
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
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_macro
name|esctrp
argument_list|()
end_macro

begin_block
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
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|C70
end_ifdef

begin_macro
name|esctrp
argument_list|()
end_macro

begin_block
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
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  C O N I N T  --  Console Interrupt setter  */
end_comment

begin_function_decl
name|conint
function_decl|(
name|f
function_decl|)
name|int
argument_list|(
argument|*f
argument_list|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
comment|/* Set an interrupt trap. */
if|if
condition|(
name|backgrd
condition|)
return|return;
comment|/* must ignore signals in bkgrd */
comment|/*  Except for special cases below, ignore keyboard quit signal.  ^\ too easily confused with connect escape, and besides, we don't want  to leave lock files around.  (Frank Prindle) */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|UXIII
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|esctrp
argument_list|)
expr_stmt|;
comment|/* console escape in pkt modes */
if|if
condition|(
name|conesc
condition|)
block|{
comment|/* clear out pending escapes */
name|conesc
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
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
comment|/* console escape in pkt modes */
if|if
condition|(
name|conesc
condition|)
block|{
comment|/* clear out pending escapes */
name|conesc
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|conif
condition|)
return|return;
comment|/* Nothing to do if already on. */
comment|/* check if invoked in background -- if so signals set to be ignored */
if|if
condition|(
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
operator|==
name|SIG_IGN
condition|)
block|{
name|backgrd
operator|=
literal|1
expr_stmt|;
comment|/*   means running in background */
ifdef|#
directive|ifdef
name|UXIII
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/*   must leave signals ignored */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|V7
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/*   must leave signals ignored */
endif|#
directive|endif
return|return;
block|}
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Function to trap to on interrupt. */
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Or hangup, so lock file cleared. */
name|conif
operator|=
literal|1
expr_stmt|;
comment|/* Flag console interrupts on. */
block|}
end_block

begin_comment
comment|/*  C O N N O I  --  Reset console terminal interrupts */
end_comment

begin_macro
name|connoi
argument_list|()
end_macro

begin_block
block|{
comment|/* Console-no-interrupts */
if|if
condition|(
name|backgrd
condition|)
return|return;
comment|/* Ignore signals in background */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
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
name|SIG_DFL
argument_list|)
expr_stmt|;
name|conif
operator|=
literal|0
expr_stmt|;
comment|/* Flag interrupt trapping off */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  myread() -- For use by systems that can do nonblocking read() calls  */
end_comment

begin_comment
comment|/*  Returns:   -1  if no characters available,   -2  upon error (such as disconnect),   otherwise value of character (0 or greater) */
end_comment

begin_macro
name|myread
argument_list|()
end_macro

begin_block
block|{
specifier|static
name|int
name|inbuf_item
decl_stmt|;
specifier|static
name|CHAR
name|inbuf
index|[
literal|257
index|]
decl_stmt|;
name|CHAR
name|readit
decl_stmt|;
if|if
condition|(
name|ungotn
operator|>=
literal|0
condition|)
block|{
name|readit
operator|=
name|ungotn
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|inbufc
operator|>
literal|0
condition|)
block|{
name|readit
operator|=
name|inbuf
index|[
operator|++
name|inbuf_item
index|]
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|(
name|inbufc
operator|=
name|read
argument_list|(
name|ttyfd
argument_list|,
name|inbuf
argument_list|,
literal|256
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* end of file */
comment|/* means carrier dropped on modem connection */
name|errno
operator|=
literal|9999
expr_stmt|;
comment|/* magic number for no carrier */
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* end of file has no errno */
block|}
if|if
condition|(
name|inbufc
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
name|readit
operator|=
name|inbuf
index|[
name|inbuf_item
operator|=
literal|0
index|]
expr_stmt|;
block|}
name|inbufc
operator|--
expr_stmt|;
block|}
name|ungotn
operator|=
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|readit
operator|)
return|;
block|}
end_block

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
comment|/* push back up to one character */
name|ungotn
operator|=
name|ch
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  I N I T R A W Q  --  Set up to read /DEV/KMEM for character count.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_comment
comment|/*  Used in Version 7 to simulate Berkeley's FIONREAD ioctl call.  This  eliminates blocking on a read, because we can read /dev/kmem to get the  number of characters available for raw input.  If your system can't  or you won't let it read /dev/kmem (the world that is) then you must  figure out a different way to do the counting of characters available,  or else replace this by a dummy function that always returns 0. */
end_comment

begin_comment
comment|/*  * Call this routine as: initrawq(tty)  * where tty is the file descriptor of a terminal.  It will return  * (as a char *) the kernel-mode memory address of the rawq character  * count, which may then be read.  It has the side-effect of flushing  * input on the terminal.  */
end_comment

begin_comment
comment|/*  * John Mackin, Physiology Dept., University of Sydney (Australia)  * ...!decvax!mulga!physiol.su.oz!john  *  * Permission is hereby granted to do anything with this code, as  * long as this comment is retained unmodified and no commercial  * advantage is gained.  */
end_comment

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
name|malloc
argument_list|()
decl_stmt|,
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
decl_stmt|,
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
name|int
operator|*
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
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  More V7-support functions...  */
end_comment

begin_expr_stmt
specifier|static
name|err
argument_list|(
argument|s
argument_list|)
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
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
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|catch
argument_list|()
block|{
name|longjmp
argument_list|(
name|jjbuf
argument_list|,
operator|-
literal|1
argument_list|)
block|; }
comment|/*  G E N B R K  --  Simulate a modem break.  */
define|#
directive|define
name|BSPEED
value|B150
name|genbrk
argument_list|(
argument|fn
argument_list|)
name|int
name|fn
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|struct
name|sgttyb
name|ttbuf
decl_stmt|;
name|int
name|ret
decl_stmt|,
name|sospeed
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
name|ret
operator|=
name|write
argument_list|(
name|fn
argument_list|,
literal|"\0\0\0\0\0\0\0\0\0\0\0\0"
argument_list|,
literal|8
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
end_block

begin_endif
endif|#
directive|endif
endif|V7
end_endif

begin_escape
end_escape

begin_comment
comment|/*  T T C H K  --  Tell how many characters are waiting in tty input buffer  */
end_comment

begin_macro
name|ttchk
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
decl_stmt|;
name|long
name|n
decl_stmt|;
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
literal|"ttchk"
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
ifdef|#
directive|ifdef
name|V7
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
else|#
directive|else
else|V7
ifdef|#
directive|ifdef
name|UXIII
return|return
operator|(
name|inbufc
operator|+
operator|(
name|ungotn
operator|>=
literal|0
operator|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|C70
return|return
operator|(
name|inbufc
operator|+
operator|(
name|ungotn
operator|>=
literal|0
operator|)
operator|)
return|;
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
return|return
operator|(
literal|0
operator|)
return|;
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
end_block

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

begin_macro
name|ttxin
argument_list|(
argument|n
argument_list|,
argument|buf
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
name|CHAR
name|c
decl_stmt|;
ifdef|#
directive|ifdef
name|MYREAD
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
condition|;
name|buf
index|[
name|x
operator|++
index|]
operator|=
name|myread
argument_list|()
control|)
empty_stmt|;
else|#
directive|else
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttxin: n"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
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
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T O L  --  Similar to "ttinl", but for writing.  */
end_comment

begin_macro
name|ttol
argument_list|(
argument|s
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
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
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ttol"
argument_list|,
name|s
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
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ttol failed"
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
end_block

begin_comment
comment|/*  T T O C  --  Output a character to the communication line  */
end_comment

begin_macro
name|ttoc
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
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
return|return
operator|(
name|write
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T I N L  --  Read a record (up to break character) from comm line.  */
end_comment

begin_comment
comment|/*   If no break character encountered within "max", return "max" characters,   with disposition of any remaining characters undefined.  Otherwise, return   the characters that were read, including the break character, in "dest" and   the number of characters read as the value of function, or 0 upon end of   file, or -1 if an error occurred.  Times out& returns error if not completed   within "timo" seconds. */
end_comment

begin_macro
name|ttinl
argument_list|(
argument|dest
argument_list|,
argument|max
argument_list|,
argument|timo
argument_list|,
argument|eol
argument_list|)
end_macro

begin_decl_stmt
name|int
name|max
decl_stmt|,
name|timo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|eol
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|CHAR
name|c
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
name|timo
operator|<=
literal|0
condition|)
block|{
comment|/* Untimed read... */
ifdef|#
directive|ifdef
name|MYREAD
for|for
control|(
name|x
operator|=
name|y
operator|=
literal|0
init|;
operator|(
name|x
operator|<
name|max
operator|)
operator|&&
operator|(
name|c
operator|!=
name|eol
operator|)
condition|;
name|x
operator|++
control|)
block|{
while|while
condition|(
operator|(
name|y
operator|=
name|myread
argument_list|()
operator|)
operator|==
operator|-
literal|1
condition|)
empty_stmt|;
if|if
condition|(
name|y
operator|==
operator|-
literal|2
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|dest
index|[
name|x
index|]
operator|=
name|y
operator|&
literal|0377
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
name|dest
argument_list|,
name|max
argument_list|)
expr_stmt|;
comment|/* Try to read. */
endif|#
directive|endif
return|return
operator|(
name|x
operator|)
return|;
comment|/* Return the count. */
block|}
comment|/* Timed read... */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Set up timeout action. */
name|alarm
argument_list|(
name|timo
argument_list|)
expr_stmt|;
comment|/* Set the timer. */
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
comment|/* Do this if timer went off. */
name|x
operator|=
operator|-
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|kerld
condition|)
block|{
comment|/* Efficient Kermit line discipline */
name|x
operator|=
name|read
argument_list|(
name|ttyfd
argument_list|,
name|dest
argument_list|,
name|max
argument_list|)
expr_stmt|;
comment|/* for 4.2bsd only... */
block|}
else|else
block|{
comment|/* Normal case... */
for|for
control|(
name|x
operator|=
name|c
operator|=
name|y
operator|=
literal|0
init|;
operator|(
name|x
operator|<
name|max
operator|)
operator|&&
operator|(
name|c
operator|!=
name|eol
operator|)
condition|;
name|x
operator|++
control|)
block|{
ifdef|#
directive|ifdef
name|MYREAD
while|while
condition|(
operator|(
name|y
operator|=
name|myread
argument_list|()
operator|)
operator|==
operator|-
literal|1
condition|)
comment|/* Use own buffering if we can */
empty_stmt|;
if|if
condition|(
name|y
operator|==
operator|-
literal|2
condition|)
name|y
operator|++
expr_stmt|;
name|c
operator|=
name|y
operator|&
literal|0377
expr_stmt|;
else|#
directive|else
while|while
condition|(
operator|(
name|y
operator|=
name|read
argument_list|(
name|ttyfd
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
operator|)
operator|==
literal|0
condition|)
comment|/* Else call system */
empty_stmt|;
comment|/* ...for each character. */
endif|#
directive|endif
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Error, turn off timer, */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
comment|/* and associated interrupt. */
return|return
operator|(
name|y
operator|)
return|;
comment|/* Return the error indication. */
block|}
name|dest
index|[
name|x
index|]
operator|=
name|c
expr_stmt|;
block|}
name|x
operator|++
expr_stmt|;
block|}
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Success, turn off timer, */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
comment|/* and associated interrupt. */
return|return
operator|(
name|x
operator|)
return|;
comment|/* Return the count. */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T I N C --  Read a character from the communication line  */
end_comment

begin_macro
name|ttinc
argument_list|(
argument|timo
argument_list|)
end_macro

begin_decl_stmt
name|int
name|timo
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
name|CHAR
name|ch
init|=
literal|0
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
while|while
condition|(
operator|(
name|n
operator|=
name|myread
argument_list|()
operator|)
operator|==
operator|-
literal|1
condition|)
empty_stmt|;
comment|/* Wait for a character... */
if|if
condition|(
name|n
operator|==
operator|-
literal|2
condition|)
name|n
operator|++
expr_stmt|;
return|return
operator|(
name|n
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
empty_stmt|;
comment|/* Wait for a character. */
return|return
operator|(
operator|(
name|n
operator|>
literal|0
operator|)
condition|?
operator|(
name|ch
operator|&
literal|0377
operator|)
else|:
name|n
operator|)
return|;
endif|#
directive|endif
block|}
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Timed, set up timer. */
name|alarm
argument_list|(
name|timo
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
name|n
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|MYREAD
while|while
condition|(
operator|(
name|n
operator|=
name|myread
argument_list|()
operator|)
operator|==
operator|-
literal|1
condition|)
empty_stmt|;
comment|/* If managing own buffer... */
if|if
condition|(
name|n
operator|==
operator|-
literal|2
condition|)
block|{
name|n
operator|++
expr_stmt|;
block|}
else|else
block|{
name|ch
operator|=
name|n
expr_stmt|;
name|n
operator|=
literal|1
expr_stmt|;
block|}
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
endif|#
directive|endif
block|}
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Turn off timer, */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
comment|/* and interrupt. */
return|return
operator|(
operator|(
name|n
operator|>
literal|0
operator|)
condition|?
operator|(
name|ch
operator|&
literal|0377
operator|)
else|:
name|n
operator|)
return|;
comment|/* Return char or -1. */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T T S N D B  --  Send a BREAK signal  */
end_comment

begin_macro
name|ttsndb
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
decl_stmt|;
name|long
name|n
decl_stmt|;
name|char
name|spd
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
name|write
argument_list|(
name|ttyfd
argument_list|,
name|brnuls
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|/* Send 3 nulls */
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
name|UXIII
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
comment|/* Send a BREAK */
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
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ANYBSD
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BSD4_4
argument_list|)
name|n
operator|=
name|FWRITE
expr_stmt|;
comment|/* Flush output queue. */
endif|#
directive|endif
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
literal|275
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
literal|1
argument_list|)
expr_stmt|;
comment|/* Get out, closing the line. */
comment|/*   with exit status = 1 */
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
name|V7
name|genbrk
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
comment|/* Simulate a BREAK */
return|return
operator|(
name|x
operator|)
return|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  M S L E E P  --  Millisecond version of sleep().  */
end_comment

begin_comment
comment|/*  Intended only for small intervals.  For big ones, just use sleep(). */
end_comment

begin_macro
name|msleep
argument_list|(
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|int
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|PROVX1
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ANYBSD
name|int
name|t1
decl_stmt|,
name|t3
decl_stmt|,
name|t4
decl_stmt|;
ifdef|#
directive|ifdef
name|BSD41
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
comment|/* Get current time. */
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
comment|/* new time */
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
name|t3
operator|)
return|;
block|}
else|#
directive|else
comment|/* 2.9 and 4.1 BSD do it this way */
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
literal|1000
expr_stmt|;
return|return
operator|(
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
operator|)
return|;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UXIII
ifdef|#
directive|ifdef
name|XENIX
define|#
directive|define
name|CLOCK_TICK
value|50
comment|/* millisecs per clock tick */
else|#
directive|else
define|#
directive|define
name|CLOCK_TICK
value|17
comment|/* 1/60 sec */
endif|#
directive|endif
specifier|extern
name|long
name|times
parameter_list|()
function_decl|;
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TOWER1
name|int
name|t1
decl_stmt|,
name|t3
decl_stmt|;
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
comment|/* Get current time. */
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
comment|/* new time */
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
name|t3
operator|)
return|;
block|}
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  R T I M E R --  Reset elapsed time counter  */
end_comment

begin_macro
name|rtimer
argument_list|()
end_macro

begin_block
block|{
name|tcount
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
block|}
end_block

begin_comment
comment|/*  G T I M E R --  Get current value of elapsed time counter in seconds  */
end_comment

begin_macro
name|gtimer
argument_list|()
end_macro

begin_block
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
name|long
operator|*
operator|)
literal|0
argument_list|)
operator|-
name|tcount
argument_list|)
expr_stmt|;
name|rtimer
argument_list|()
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
end_block

begin_comment
comment|/*  Z T I M E  --  Return date/time string  */
end_comment

begin_macro
name|ztime
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|UXIII
specifier|extern
name|long
name|time
parameter_list|()
function_decl|;
comment|/* Sys III/V way to do it */
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PROVX1
name|int
name|utime
index|[
literal|2
index|]
decl_stmt|;
comment|/* Venix way */
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ANYBSD
name|char
modifier|*
name|asctime
parameter_list|()
function_decl|;
comment|/* Berkeley way */
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
ifndef|#
directive|ifndef
name|BSD41
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|tz
argument_list|)
expr_stmt|;
comment|/* BSD 2.9, 4.2 ... */
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
else|#
directive|else
name|time
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
comment|/* BSD 4.1 ... ceb */
name|tp
operator|=
name|localtime
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|*
name|s
operator|=
name|asctime
argument_list|(
name|tp
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TOWER1
name|char
modifier|*
name|asctime
parameter_list|()
function_decl|;
comment|/* Tower way */
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
name|time
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|tp
operator|=
name|localtime
argument_list|(
operator|&
name|clock
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|V7
name|char
modifier|*
name|asctime
parameter_list|()
function_decl|;
comment|/* V7 way */
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
name|time
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|tp
operator|=
name|localtime
argument_list|(
operator|&
name|clock
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
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C O N G M  --  Get console terminal modes.  */
end_comment

begin_comment
comment|/*  Saves current console mode, and establishes variables for switching between   current (presumably normal) mode and other modes. */
end_comment

begin_macro
name|congm
argument_list|()
end_macro

begin_block
block|{
ifndef|#
directive|ifndef
name|UXIII
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|ccold
argument_list|)
expr_stmt|;
comment|/* Structure for restoring */
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|cccbrk
argument_list|)
expr_stmt|;
comment|/* For setting CBREAK mode */
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|ccraw
argument_list|)
expr_stmt|;
comment|/* For setting RAW mode */
else|#
directive|else
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ccold
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|cccbrk
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|ccraw
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|cgmf
operator|=
literal|1
expr_stmt|;
comment|/* Flag that we got them. */
block|}
end_block

begin_comment
comment|/*  C O N C B --  Put console in cbreak mode.  */
end_comment

begin_comment
comment|/*  Returns 0 if ok, -1 if not  */
end_comment

begin_macro
name|concb
argument_list|(
argument|esc
argument_list|)
end_macro

begin_decl_stmt
name|char
name|esc
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|cgmf
operator|==
literal|0
condition|)
name|congm
argument_list|()
expr_stmt|;
comment|/* Get modes if necessary. */
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
ifndef|#
directive|ifndef
name|UXIII
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
name|cccbrk
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
name|cccbrk
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
name|cccbrk
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|1
expr_stmt|;
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
comment|/* set new modes . */
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|V7
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
endif|V7
return|return
operator|(
name|x
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C O N B I N  --  Put console in binary mode  */
end_comment

begin_comment
comment|/*  Returns 0 if ok, -1 if not  */
end_comment

begin_macro
name|conbin
argument_list|(
argument|esc
argument_list|)
end_macro

begin_decl_stmt
name|char
name|esc
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|cgmf
operator|==
literal|0
condition|)
name|congm
argument_list|()
expr_stmt|;
comment|/* Get modes if necessary. */
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
ifndef|#
directive|ifndef
name|UXIII
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
comment|/* Set rawmode, XON/XOFF */
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
else|#
directive|else
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
operator|)
expr_stmt|;
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
name|ccraw
operator|.
name|c_oflag
operator|&=
operator|~
name|OPOST
expr_stmt|;
comment|/*** Kermit used to put the console in 8-bit raw mode, but some users have  *** pointed out that this should not be done, since some sites actually  *** use terminals with parity settings on their Unix systems, and if we  *** override the current settings and stop doing parity, then their terminals  *** will display blotches for characters whose parity is wrong.  Therefore,  *** the following two lines are commented out (Larry Afrin, Clemson U):  ***  ***   ccraw.c_cflag&= ~(PARENB|CSIZE);  ***   ccraw.c_cflag |= (CS8|CREAD);  ***  *** Sys III/V sites that have trouble with this can restore these lines.  ***/
name|ccraw
operator|.
name|c_cc
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
name|ccraw
operator|.
name|c_cc
index|[
literal|5
index|]
operator|=
literal|1
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
name|ccraw
argument_list|)
operator|)
return|;
comment|/* set new modes . */
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/*  C O N R E S  --  Restore the console terminal  */
end_comment

begin_macro
name|conres
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|cgmf
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Don't do anything if modes */
ifndef|#
directive|ifndef
name|UXIII
comment|/* except for sIII, */
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/*  not known! */
endif|#
directive|endif
comment|/*   (sIII does wait in ioctls) */
name|ckxech
operator|=
literal|0
expr_stmt|;
comment|/* System should echo chars */
ifndef|#
directive|ifndef
name|UXIII
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
comment|/* Restore controlling tty */
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
name|ccold
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C O N O C  --  Output a character to the console terminal  */
end_comment

begin_macro
name|conoc
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|write
argument_list|(
literal|1
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  C O N X O  --  Write x characters to the console terminal  */
end_comment

begin_macro
name|conxo
argument_list|(
argument|x
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|write
argument_list|(
literal|1
argument_list|,
name|s
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  C O N O L  --  Write a line to the console terminal  */
end_comment

begin_macro
name|conol
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|len
decl_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|1
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  C O N O L A  --  Write an array of lines to the console terminal */
end_comment

begin_macro
name|conola
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
index|[]
decl_stmt|;
end_decl_stmt

begin_block
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
name|conol
argument_list|(
name|s
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  C O N O L L  --  Output a string followed by CRLF  */
end_comment

begin_macro
name|conoll
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|conol
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|1
argument_list|,
literal|"\r\n"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C O N C H K  --  Return how many characters available at console  */
end_comment

begin_macro
name|conchk
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
decl_stmt|;
name|long
name|n
decl_stmt|;
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
name|V7
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
else|#
directive|else
ifdef|#
directive|ifdef
name|UXIII
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
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C O N I N C  --  Get a character from the console  */
end_comment

begin_macro
name|coninc
argument_list|(
argument|timo
argument_list|)
end_macro

begin_decl_stmt
name|int
name|timo
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
name|char
name|ch
decl_stmt|;
if|if
condition|(
name|timo
operator|<=
literal|0
condition|)
block|{
comment|/* untimed */
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
name|ch
operator|&=
literal|0377
expr_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
return|return
operator|(
name|ch
operator|)
return|;
comment|/* Return the char if read */
elseif|else
ifdef|#
directive|ifdef
name|UXIII
if|if
condition|(
name|n
operator|<
literal|0
operator|&&
name|errno
operator|==
name|EINTR
condition|)
comment|/* if read was interrupted by QUIT */
return|return
operator|(
name|escchr
operator|)
return|;
comment|/* user entered escape character */
else|else
comment|/* couldnt be ^c, sigint never returns */
endif|#
directive|endif
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Return the char, or -1. */
block|}
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timerh
argument_list|)
expr_stmt|;
comment|/* Timed read, so set up timer */
name|alarm
argument_list|(
name|timo
argument_list|)
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
name|n
operator|=
operator|-
literal|2
expr_stmt|;
else|else
block|{
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
name|ch
operator|&=
literal|0377
expr_stmt|;
block|}
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Stop timing, we got our character */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
return|return
operator|(
name|ch
operator|)
return|;
elseif|else
ifdef|#
directive|ifdef
name|UXIII
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
condition|)
comment|/* If read interrupted by QUIT, */
return|return
operator|(
name|escchr
operator|)
return|;
comment|/* user entered escape character, */
else|else
comment|/* can't be ^c, sigint never returns */
endif|#
directive|endif
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

end_unit

