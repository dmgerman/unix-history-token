begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzv
init|=
literal|"OS/2 File support, 5A(067) 11 Nov 92"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|aegis
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzv
init|=
literal|"Aegis File support, 5A(067) 11 Nov 92"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|ckzv
init|=
literal|"UNIX File support, 5A(067) 11 Nov 92"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* aegis */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_comment
comment|/* C K U F I O  --  Kermit file system support for UNIX, OS/2, and Aegis */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_comment
comment|/* Include Files */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

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
comment|/* POSIX */
end_comment

begin_comment
comment|/* Directory structure header file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_comment
comment|/*    C-Kermit's OS/2 support originally by Chris Adie<C.Adie@uk.ac.edinburgh>   Edinburgh University Computing Service, Scotland, for C-Kermit 4F.  Adapted   to C-Kermit 5A and integrated into the UNIX support module by Kai Uwe Rommel<rommel@informatik.tu-muenchen.de>, Muenchen, Germany, December 1991. */
end_comment

begin_comment
comment|/*   Directory Separator macros, to allow this module to work with both UNIX and   OS/2: Because of ambiguity with the command line editor escape \ character,   the directory separator is currently left as / for OS/2 too, because the   OS/2 kernel also accepts / as directory separator.  But this is subject to   change in future versions to conform to the normal OS/2 style. */
end_comment

begin_define
define|#
directive|define
name|DIRSEP
value|'/'
end_define

begin_comment
comment|/* #define DIRSEP       '\\' */
end_comment

begin_define
define|#
directive|define
name|ISDIRSEP
parameter_list|(
name|c
parameter_list|)
value|((c)=='/'||(c)=='\\')
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not OS2 */
end_comment

begin_define
define|#
directive|define
name|DIRSEP
value|'/'
end_define

begin_define
define|#
directive|define
name|ISDIRSEP
parameter_list|(
name|c
parameter_list|)
value|((c)=='/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SDIRENT
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|OPENDIR
end_define

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_include
include|#
directive|include
file|"ckodir.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !RTU, !NDIR, !XNDIR, !DIRENT, !OS2, i.e. all others */
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
comment|/* OS2 */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_comment
comment|/* OS/2 file system interface */
end_comment

begin_define
define|#
directive|define
name|BSD4
end_define

begin_comment
comment|/* is like Berkeley UNIX */
end_comment

begin_define
define|#
directive|define
name|NOFILEH
end_define

begin_comment
comment|/* with no<file.h> */
end_comment

begin_include
include|#
directive|include
file|<sys/utime.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|binary
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We need to know this for open() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__IBMC__
end_ifdef

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|popen
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__EMX__
end_ifndef

begin_define
define|#
directive|define
name|popen
value|_popen
end_define

begin_define
define|#
directive|define
name|pclose
value|_pclose
end_define

begin_include
include|#
directive|include
file|<share.h>
end_include

begin_define
define|#
directive|define
name|fopen
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|_fsopen(n, m, SH_DENYWR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IBMC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_comment
comment|/* Password file for shell name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OS2
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSUTIMEH
end_ifdef

begin_comment
comment|/*<sys/utime.h> if requested,  */
end_comment

begin_include
include|#
directive|include
file|<sys/utime.h>
end_include

begin_comment
comment|/* for extra fields required by */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSUTIMEH */
end_comment

begin_comment
comment|/* 88Open spec. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_comment
comment|/* BSD 4.4 */
end_comment

begin_define
define|#
directive|define
name|TIMESTAMP
end_define

begin_comment
comment|/* Can do file dates */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_comment
comment|/* BSD 4.3 and below */
end_comment

begin_define
define|#
directive|define
name|TIMESTAMP
end_define

begin_comment
comment|/* Can do file dates */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* Need this */
end_comment

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_comment
comment|/* Need this if really BSD */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_comment
comment|/*   4.4 BSD uses utimes() instead of utime() for this, which accepts a... */
end_comment

begin_define
define|#
directive|define
name|TIMESTAMP
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* void tzset(); (the "void" type upsets some compilers) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ultrix
end_ifndef

begin_decl_stmt
specifier|extern
name|long
name|timezone
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix */
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
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_comment
comment|/* Is `y' a leap year? */
end_comment

begin_define
define|#
directive|define
name|leap
parameter_list|(
name|y
parameter_list|)
value|(((y) % 4 == 0&& (y) % 100 != 0) || (y) % 400 == 0)
end_define

begin_comment
comment|/* Number of leap years from 1970 to `y' (not including `y' itself). */
end_comment

begin_define
define|#
directive|define
name|nleap
parameter_list|(
name|y
parameter_list|)
value|(((y) - 1969) / 4 - ((y) - 1901) / 100 + ((y) - 1601) / 400)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/* not used */
end_comment

begin_comment
comment|/* Number of days in each month of the year. */
end_comment

begin_decl_stmt
specifier|static
name|char
name|monlens
index|[]
init|=
block|{
literal|31
block|,
literal|28
block|,
literal|31
block|,
literal|30
block|,
literal|31
block|,
literal|30
block|,
literal|31
block|,
literal|31
block|,
literal|30
block|,
literal|31
block|,
literal|30
block|,
literal|31
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CIE
end_ifdef

begin_include
include|#
directive|include
file|<stat.h>
end_include

begin_comment
comment|/* File status */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* because standard stat has trouble with trailing /'s we have to wrap it */
end_comment

begin_function_decl
name|int
name|os2stat
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|stat
parameter_list|(
name|path
parameter_list|,
name|buf
parameter_list|)
value|os2stat(path, buf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CIE */
end_comment

begin_escape
end_escape

begin_comment
comment|/*   Functions (n is one of the predefined file numbers from ckcker.h):     zopeni(n,name)   -- Opens an existing file for input.    zopeno(n,name,attr,fcb) -- Opens a new file for output.    zclose(n)        -- Closes a file.    zchin(n,&c)      -- Gets the next character from an input file.    zsinl(n,&s,x)    -- Read a line from file n, max len x, into address s.    zsout(n,s)       -- Write a null-terminated string to output file, buffered.    zsoutl(n,s)      -- Like zsout, but appends a line terminator.    zsoutx(n,s,x)    -- Write x characters to output file, unbuffered.    zchout(n,c)      -- Add a character to an output file, unbuffered.    zchki(name)      -- Check if named file exists and is readable, return size.    zchko(name)      -- Check if named file can be created.    zchkspa(name,n)  -- Check if n bytes available to create new file, name.    znewn(name,s)    -- Make a new unique file name based on the given name.    zdelet(name)     -- Delete the named file.    zxpand(string)   -- Expands the given wildcard string into a list of files.    znext(string)    -- Returns the next file from the list in "string".    zxcmd(n,cmd)     -- Execute the command in a lower fork on file number n.    zclosf()         -- Close input file associated with zxcmd()'s lower fork.    zrtol(n1,n2)     -- Convert remote filename into local form.    zltor(n1,n2)     -- Convert local filename into remote form.    zchdir(dirnam)   -- Change working directory.    zhome()          -- Return pointer to home directory name string.    zkself()         -- Kill self, log out own job.    zsattr(struct zattr *) -- Return attributes for file which is being sent.    zstime(f, struct zattr *, x) - Set file creation date from attribute packet.    zrename(old, new) -- Rename a file.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Kermit-specific includes */
end_comment

begin_comment
comment|/*   Definitions here supersede those from system include files.   ckcdeb.h is included above. */
end_comment

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_comment
comment|/* Kermit definitions */
end_comment

begin_include
include|#
directive|include
file|"ckucmd.h"
end_include

begin_comment
comment|/* For sys-dependent keyword tables */
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
name|ckzsys
init|=
name|HERALD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Support for tilde-expansion in file and directory names */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_define
define|#
directive|define
name|NAMEENV
value|"LOGNAME"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_define
define|#
directive|define
name|NAMEENV
value|"USER"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_define
define|#
directive|define
name|NAMEENV
value|"LOGNAME"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_comment
comment|/* Berkeley Unix Version 4.x */
end_comment

begin_comment
comment|/* 4.1bsd support from Charles E Brooks, EDN-VAX */
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
comment|/* Definitions of some system commands */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|DELCMD
init|=
literal|"del "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For file deletion */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PWDCMD
init|=
literal|"chdir "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For saying where I am */
end_comment

begin_decl_stmt
name|char
modifier|*
name|TYPCMD
init|=
literal|"type "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For typing a file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DIRCMD
init|=
literal|"dir "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For directory listing */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DIRCM2
init|=
literal|"dir "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For directory listing, no args */
end_comment

begin_decl_stmt
name|char
modifier|*
name|WHOCMD
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Who's there? */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SPACMD
init|=
literal|"dir | find \"bytes free\""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For space on disk */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SPACM2
init|=
literal|"dir | find \"bytes free\""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For space on disk */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not OS2, ergo UNIX */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DELCMD
init|=
literal|"rm -f "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For file deletion */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PWDCMD
init|=
literal|"pwd "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For saying where I am */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|DIRCMD
init|=
literal|"/bin/ls -ld "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For directory listing */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DIRCM2
init|=
literal|"/bin/ls -ld *"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For directory listing, no args */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|DIRCMD
init|=
literal|"/bin/ls -l "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For directory listing */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DIRCM2
init|=
literal|"/bin/ls -l "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For directory listing, no args */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_decl_stmt
name|char
modifier|*
name|TYPCMD
init|=
literal|"cat "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For typing a file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT18
end_ifdef

begin_comment
comment|/* Fortune For:Pro 1.8 */
end_comment

begin_undef
undef|#
directive|undef
name|BSD4
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT18 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|SPACMD
init|=
literal|"pwd ; df ."
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Space in current directory */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|FT18
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|SPACMD
init|=
literal|"pwd ; du ; df ."
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|SPACMD
init|=
literal|"df "
decl_stmt|;
end_decl_stmt

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
comment|/* BSD4 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SPACM2
init|=
literal|"df "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For space in specified directory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT18
end_ifdef

begin_define
define|#
directive|define
name|BSD4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT18 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OXOS
end_ifdef

begin_comment
comment|/* For seeing who's logged in */
end_comment

begin_decl_stmt
name|char
modifier|*
name|WHOCMD
init|=
literal|"who "
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|WHOCMD
init|=
literal|"finger "
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|WHOCMD
init|=
literal|"who "
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSOS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DTILDE
end_ifdef

begin_comment
comment|/* For tilde expansion */
end_comment

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|tilde_expand
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DTILDE */
end_comment

begin_comment
comment|/* More system-dependent includes, which depend on symbols defined */
end_comment

begin_comment
comment|/* in the Kermit-specific includes.  Oh what a tangled web we weave... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_comment
comment|/*<sys/file.h> */
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

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

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
name|aegis
end_ifdef

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
comment|/* aegis */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|unos
end_ifdef

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
comment|/* unos */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOFILEH
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|is68k
end_ifndef

begin_comment
comment|/* Whether to include<fcntl.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD41
end_ifndef

begin_comment
comment|/* All but a couple UNIXes have it. */
end_comment

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
comment|/* FT18  */
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

begin_comment
comment|/*   Change argument to "(const char *)" if this causes trouble.   Or... if it causes trouble, then maybe it was already declared    in a header file after all, so you can remove this prototype. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NEXT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4
end_ifndef

begin_comment
comment|/* POSIX<pwd.h> already gave prototypes for these. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX40
end_ifdef

begin_expr_stmt
name|_PROTOTYP
argument_list|(
expr|struct
name|passwd
operator|*
name|getpwnam
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|_PROTOTYP
argument_list|(
expr|struct
name|passwd
operator|*
name|getpwnam
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX40 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUNOS4
end_ifndef

begin_expr_stmt
name|_PROTOTYP
argument_list|(
expr|struct
name|passwd
operator|*
name|getpwuid
argument_list|,
operator|(
name|PWID_T
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_expr_stmt
name|_PROTOTYP
argument_list|(
expr|struct
name|passwd
operator|*
name|getpwent
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* NEXT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define macros for getting file type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OXOS
end_ifdef

begin_comment
comment|/*   Olivetti X/OS 2.3 has S_ISREG and S_ISDIR defined   incorrectly, so we force their redefinition. */
end_comment

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OXOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UTSV
end_ifdef

begin_comment
comment|/* Same deal for Amdahl UTSV */
end_comment

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNISYS52
end_ifdef

begin_comment
comment|/* And for UNISYS UTS V 5.2 */
end_comment

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNISYS52 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_ISREG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_ISDIR */
end_comment

begin_comment
comment|/* Define maximum length for a file name if not already defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXNAMLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|255
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|FILENAME_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|FILENAME_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NAME_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|NAME_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_NAME_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|_POSIX_NAME_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_D_NAME_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|_D_NAME_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|DIRSIZ
end_ifdef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|DIRSIZ
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXNAMLEN
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIRSIZ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _D_NAME_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_NAME_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAME_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILENAME_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXNAMLEN */
end_comment

begin_comment
comment|/* Longest pathname */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATH
end_ifdef

begin_undef
undef|#
directive|undef
name|MAXPATH
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATH */
end_comment

begin_define
define|#
directive|define
name|MAXPATH
value|MAXPATHLEN
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXPATH
value|PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXPATH
value|_POSIX_PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_define
define|#
directive|define
name|MAXPATH
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXPATH
value|255
end_define

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
comment|/* _POSIX_PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_comment
comment|/* Maximum number of filenames for wildcard expansion */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_define
define|#
directive|define
name|MAXWLD
value|50
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
end_ifdef

begin_define
define|#
directive|define
name|MAXWLD
value|50
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|MAXWLD
value|50
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXWLD
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD29 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROVX1 */
end_comment

begin_comment
comment|/* More internal function prototypes */
end_comment

begin_comment
comment|/*  * The path structure is used to represent the name to match.  * Each slash-separated segment of the name is kept in one  * such structure, and they are linked together, to make  * traversing the name easier.  */
end_comment

begin_struct
struct|struct
name|path
block|{
name|char
name|npart
index|[
name|MAXNAMLEN
operator|+
literal|4
index|]
decl_stmt|;
comment|/* name part of path segment */
name|struct
name|path
modifier|*
name|fwd
decl_stmt|;
comment|/* forward ptr */
block|}
struct|;
end_struct

begin_macro
name|_PROTOTYP
argument_list|(
argument|int shxpand
argument_list|,
argument|(char *, char *[], int )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static int fgen
argument_list|,
argument|(char *, char *[], int )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static VOID traverse
argument_list|,
argument|(struct path *, char *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static VOID addresult
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
argument|static int match
argument_list|,
argument|(char *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
specifier|static
name|char
operator|*
name|whoami
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|xindex
argument_list|,
operator|(
name|char
operator|*
operator|,
name|char
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|UID_T real_uid
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
expr|struct
name|path
operator|*
name|splitpath
argument_list|,
operator|(
name|char
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Some systems define these symbols in include files, others don't... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_comment
comment|/* For access */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|W_OK
end_ifndef

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_escape
end_escape

begin_comment
comment|/* Declarations */
end_comment

begin_decl_stmt
name|int
name|maxnam
init|=
name|MAXNAMLEN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Available to the outside */
end_comment

begin_decl_stmt
name|int
name|maxpath
init|=
name|MAXPATH
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fp
index|[
name|ZNFILS
index|]
init|=
block|{
comment|/* File pointers */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_decl_stmt
name|int
name|ispipe
index|[
name|ZNFILS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for file is a pipe */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_comment
comment|/* Buffers and pointers used in buffered file input and output. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zinbuffer
decl_stmt|,
modifier|*
name|zoutbuffer
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
name|zinbuffer
index|[]
decl_stmt|,
name|zoutbuffer
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zinptr
decl_stmt|,
modifier|*
name|zoutptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zincnt
decl_stmt|,
name|zoutcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wildxpand
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|UID_T
name|real_uid
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|long
name|iflen
init|=
operator|-
literal|1L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input file length */
end_comment

begin_decl_stmt
specifier|static
name|PID_T
name|pid
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of child fork */
end_comment

begin_decl_stmt
specifier|static
name|int
name|fcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of files in wild group */
end_comment

begin_decl_stmt
specifier|static
name|char
name|nambuf
index|[
name|MAXNAMLEN
operator|+
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for a filename */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOFRILLS
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|zmbuf
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For mail, remote print strings */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOFRILLS */
end_comment

begin_comment
comment|/* static */
end_comment

begin_comment
comment|/* Not static, must be global now. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mtchs
index|[
name|MAXWLD
index|]
decl_stmt|,
comment|/* Matches found for filename */
modifier|*
modifier|*
name|mtchptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to current match */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  Z K S E L F  --  Kill Self: log out own job, if possible.  */
end_comment

begin_comment
comment|/* Note, should get current pid, but if your system doesn't have */
end_comment

begin_comment
comment|/* getppid(), then just kill(0,9)...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVR3
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|POSIX
end_ifndef

begin_comment
comment|/* Already declared in unistd.h for SVR3 and POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSIC
end_ifdef

begin_function_decl
specifier|extern
name|PID_T
name|getppid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|PS2AIX10
end_ifndef

begin_function_decl
specifier|extern
name|PID_T
name|getppid
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PS2AIX10 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3 */
end_comment

begin_function
name|int
name|zkself
parameter_list|()
block|{
comment|/* For "bye", but no guarantee! */
ifdef|#
directive|ifdef
name|PROVX1
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|V7
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|TOWER1
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|FT18
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|aegis
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|COHERENT
return|return
operator|(
name|kill
argument_list|(
operator|(
name|PID_T
operator|)
name|getpid
argument_list|()
argument_list|,
literal|1
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|OS2
name|exit
argument_list|(
literal|3
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|PID_T
name|exit
argument_list|(
name|kill
argument_list|(
operator|(
name|PID_T
operator|)
name|getppid
argument_list|()
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|exit
argument_list|(
name|kill
argument_list|(
name|getppid
argument_list|()
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
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
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  Z O P E N I  --  Open an existing file for input. */
end_comment

begin_function
name|int
name|zopeni
parameter_list|(
name|n
parameter_list|,
name|name
parameter_list|)
name|int
name|n
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|" zopeni"
argument_list|,
name|name
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"  fp"
argument_list|,
literal|""
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|zincnt
operator|=
literal|0
expr_stmt|;
comment|/* Reset input buffer */
if|if
condition|(
name|n
operator|==
name|ZSYSFN
condition|)
block|{
comment|/* Input from a system function? */
comment|/*** Note, this function should not be called with ZSYSFN ***/
comment|/*** Always call zxcmd() directly, and give it the real file number ***/
comment|/*** you want to use.  ***/
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zopeni called with ZSYSFN, failing!"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|*
name|nambuf
operator|=
literal|'\0'
expr_stmt|;
comment|/* No filename. */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* fail. */
ifdef|#
directive|ifdef
name|COMMENT
return|return
operator|(
name|zxcmd
argument_list|(
name|n
argument_list|,
name|name
argument_list|)
operator|)
return|;
comment|/* Try to fork the command */
endif|#
directive|endif
block|}
if|if
condition|(
name|n
operator|==
name|ZSTDIO
condition|)
block|{
comment|/* Standard input? */
if|if
condition|(
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Terminal input not allowed"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zopeni: attempts input from unredirected stdin"
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
name|fp
index|[
name|ZIFILE
index|]
operator|=
name|stdin
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
name|setmode
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|,
name|O_BINARY
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
return|return
operator|(
literal|1
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
name|n
operator|==
name|ZIFILE
operator|||
name|n
operator|==
name|ZRFILE
condition|)
name|fp
index|[
name|n
index|]
operator|=
name|fopen
argument_list|(
name|name
argument_list|,
literal|"rb"
argument_list|)
expr_stmt|;
comment|/* Binary mode */
else|else
endif|#
directive|endif
comment|/* OS2 */
name|fp
index|[
name|n
index|]
operator|=
name|fopen
argument_list|(
name|name
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
comment|/* Real file, open it. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|" zopeni"
argument_list|,
name|name
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|fp
index|[
name|n
index|]
operator|==
name|NULL
condition|)
name|perror
argument_list|(
literal|"zopeni"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|fp
index|[
name|n
index|]
operator|!=
name|NULL
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Z O P E N O  --  Open a new file for output.  */
end_comment

begin_function
name|int
name|zopeno
parameter_list|(
name|n
parameter_list|,
name|name
parameter_list|,
name|zz
parameter_list|,
name|fcb
parameter_list|)
comment|/* zopeno */
name|int
name|n
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|zattr
modifier|*
name|zz
decl_stmt|;
name|struct
name|filinfo
modifier|*
name|fcb
decl_stmt|;
block|{
name|char
name|p
index|[
literal|8
index|]
decl_stmt|;
comment|/* (===OS2 change===) */
comment|/* As of Version 5A, the attribute structure and the file information */
comment|/* structure are included in the arglist. */
ifdef|#
directive|ifdef
name|DEBUG
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zopeno"
argument_list|,
name|name
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|fcb
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zopeno fcb disp"
argument_list|,
literal|""
argument_list|,
name|fcb
operator|->
name|dsp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zopeno fcb type"
argument_list|,
literal|""
argument_list|,
name|fcb
operator|->
name|typ
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zopeno fcb char"
argument_list|,
literal|""
argument_list|,
name|fcb
operator|->
name|cs
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"zopeno fcb is NULL"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|!=
name|ZDFILE
condition|)
name|debug
argument_list|(
name|F111
argument_list|,
literal|" zopeno"
argument_list|,
name|name
argument_list|,
name|n
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|(
name|n
operator|==
name|ZCTERM
operator|)
operator|||
operator|(
name|n
operator|==
name|ZSTDIO
operator|)
condition|)
block|{
comment|/* Terminal or standard output */
name|fp
index|[
name|ZOFILE
index|]
operator|=
name|stdout
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|n
operator|!=
name|ZDFILE
condition|)
name|debug
argument_list|(
name|F101
argument_list|,
literal|" fp[]=stdout"
argument_list|,
literal|""
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
name|zoutcnt
operator|=
literal|0
expr_stmt|;
name|zoutptr
operator|=
name|zoutbuffer
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* A real file.  Open it in desired mode (create or append). */
name|strcpy
argument_list|(
name|p
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
comment|/* Assume write/create mode */
if|if
condition|(
name|fcb
condition|)
block|{
comment|/* If called with an FCB... */
if|if
condition|(
name|fcb
operator|->
name|dsp
operator|==
name|XYFZ_A
condition|)
comment|/* Does it say Append? */
name|strcpy
argument_list|(
name|p
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
comment|/* Yes. */
block|}
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
name|n
operator|==
name|ZOFILE
operator|||
name|n
operator|==
name|ZSFILE
condition|)
comment|/* OS/2 binary mode */
name|strcat
argument_list|(
name|p
argument_list|,
literal|"b"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
name|fp
index|[
name|n
index|]
operator|=
name|fopen
argument_list|(
name|name
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* Try to open the file */
if|if
condition|(
name|fp
index|[
name|n
index|]
operator|==
name|NULL
condition|)
block|{
comment|/* Failed */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zopeno failed errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
comment|/* Let upper levels print message. */
name|perror
argument_list|(
literal|"Can't open output file"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
block|}
else|else
block|{
comment|/* Succeeded */
if|if
condition|(
name|n
operator|==
name|ZDFILE
condition|)
comment|/* If it's the debug log */
name|setbuf
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* make it unbuffered */
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"zopeno ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|zoutcnt
operator|=
literal|0
expr_stmt|;
comment|/* (PWP) reset output buffer */
name|zoutptr
operator|=
name|zoutbuffer
expr_stmt|;
return|return
operator|(
operator|(
name|fp
index|[
name|n
index|]
operator|!=
name|NULL
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Z C L O S E  --  Close the given file.  */
end_comment

begin_comment
comment|/*  Returns 0 if arg out of range, 1 if successful, -1 if close failed.  */
end_comment

begin_function
name|int
name|zclose
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
name|int
name|x
decl_stmt|,
name|x2
decl_stmt|;
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Check range of n */
if|if
condition|(
operator|(
name|n
operator|==
name|ZOFILE
operator|)
operator|&&
operator|(
name|zoutcnt
operator|>
literal|0
operator|)
condition|)
comment|/* (PWP) output leftovers */
name|x2
operator|=
name|zoutdump
argument_list|()
expr_stmt|;
else|else
name|x2
operator|=
literal|0
expr_stmt|;
name|x
operator|=
literal|0
expr_stmt|;
comment|/* Initialize return code */
if|if
condition|(
name|fp
index|[
name|ZSYSFN
index|]
condition|)
block|{
comment|/* If file is really pipe */
name|x
operator|=
name|zclosf
argument_list|(
name|n
argument_list|)
expr_stmt|;
comment|/* do it specially */
block|}
else|else
block|{
if|if
condition|(
operator|(
name|fp
index|[
name|n
index|]
operator|!=
name|stdout
operator|)
operator|&&
operator|(
name|fp
index|[
name|n
index|]
operator|!=
name|stdin
operator|)
condition|)
name|x
operator|=
name|fclose
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
name|fp
index|[
name|n
index|]
operator|=
name|NULL
expr_stmt|;
block|}
name|iflen
operator|=
operator|-
literal|1L
expr_stmt|;
comment|/* Invalidate file length */
if|if
condition|(
name|x
operator|==
name|EOF
condition|)
comment|/* if we got a close error */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
elseif|else
if|if
condition|(
name|x2
operator|<
literal|0
condition|)
comment|/* or an error flushing the last buffer */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* then return an error */
else|else
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Z C H I N  --  Get a character from the input file.  */
end_comment

begin_comment
comment|/*  Returns -1 if EOF, 0 otherwise with character returned in argument  */
end_comment

begin_function
name|int
name|zchin
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
name|int
name|n
decl_stmt|;
name|int
modifier|*
name|c
decl_stmt|;
block|{
name|int
name|a
decl_stmt|,
name|x
decl_stmt|;
comment|/* (PWP) Just in case this gets called when it shouldn't. */
if|if
condition|(
name|n
operator|==
name|ZIFILE
condition|)
block|{
name|x
operator|=
name|zminchar
argument_list|()
expr_stmt|;
operator|*
name|c
operator|=
name|x
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
comment|/* if (chkfn(n)< 1) return(-1); */
name|a
operator|=
name|getc
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|a
operator|==
name|EOF
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
operator|!
name|binary
operator|&&
name|a
operator|==
literal|0x1A
condition|)
comment|/* Ctrl-Z marks EOF for text mode*/
return|return
operator|(
operator|-
literal|1
operator|)
return|;
endif|#
directive|endif
operator|*
name|c
operator|=
operator|(
name|CHAR
operator|)
name|a
operator|&
literal|0377
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Z S I N L  --  Read a line from a file  */
end_comment

begin_comment
comment|/*   Writes the line into the address provided by the caller.   n is the Kermit "channel number".   Writing terminates when newline is encountered, newline is not copied.   Writing also terminates upon EOF or if length x is exhausted.   Returns 0 on success, -1 on EOF or error. */
end_comment

begin_function
name|int
name|zsinl
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|,
name|x
parameter_list|)
name|int
name|n
decl_stmt|,
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|a
decl_stmt|,
name|z
init|=
literal|0
decl_stmt|;
comment|/* z is return code. */
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
block|{
comment|/* Make sure file is open */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|a
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Current character, none yet. */
while|while
condition|(
name|x
operator|--
condition|)
block|{
comment|/* Up to given length */
ifndef|#
directive|ifndef
name|NLCHAR
name|int
name|old
decl_stmt|;
name|old
operator|=
name|a
expr_stmt|;
comment|/* Previous character */
endif|#
directive|endif
if|if
condition|(
name|zchin
argument_list|(
name|n
argument_list|,
operator|&
name|a
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Read a character from the file */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zsinl"
argument_list|,
literal|""
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|z
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* EOF or other error */
break|break;
block|}
ifdef|#
directive|ifdef
name|NLCHAR
if|if
condition|(
name|a
operator|==
operator|(
name|char
operator|)
name|NLCHAR
condition|)
break|break;
comment|/* Single-character line terminator */
else|#
directive|else
comment|/* CRLF line terminator */
if|if
condition|(
name|a
operator|==
literal|'\015'
condition|)
continue|continue;
comment|/* CR, get next character */
if|if
condition|(
name|old
operator|==
literal|'\015'
condition|)
block|{
comment|/* Previous character was CR */
if|if
condition|(
name|a
operator|==
literal|'\012'
condition|)
break|break;
comment|/* This one is LF, so we have a line */
else|else
operator|*
name|s
operator|++
operator|=
literal|'\015'
expr_stmt|;
comment|/* Not LF, deposit CR */
block|}
ifdef|#
directive|ifdef
name|OS2
comment|/*   I'm not sure I understand this one, so let's keep it only for OS/2 for now. */
if|if
condition|(
name|a
operator|==
literal|'\012'
condition|)
break|break;
comment|/* Break on single LF too */
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* NLCHAR */
operator|*
name|s
operator|=
name|a
expr_stmt|;
comment|/* Deposit character */
name|s
operator|++
expr_stmt|;
block|}
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate the string */
return|return
operator|(
name|z
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * (PWP) (re)fill the buffered input buffer with data.  All file input  * should go through this routine, usually by calling the zminchar()  * macro (in ckcker.h).  */
end_comment

begin_comment
comment|/*  * Suggestion: if fread() returns 0, call ferror to find out what the  * problem was.  If it was not EOF, then return -2 instead of -1.  * Upper layers (getpkt function in ckcfns.c) should set cxseen flag  * if it gets -2 return from zminchar macro.  */
end_comment

begin_function
name|int
name|zinfill
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|zincnt
operator|=
name|fread
argument_list|(
name|zinbuffer
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|,
name|INBUFSIZE
argument_list|,
name|fp
index|[
name|ZIFILE
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zinfill fp"
argument_list|,
literal|""
argument_list|,
name|fp
index|[
name|ZIFILE
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zinfill zincnt"
argument_list|,
literal|""
argument_list|,
name|zincnt
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|zincnt
operator|==
literal|0
condition|)
block|{
ifndef|#
directive|ifndef
name|UTEK
ifdef|#
directive|ifdef
name|ferror
name|x
operator|=
name|ferror
argument_list|(
name|fp
index|[
name|ZIFILE
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zinfill errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zinfill ferror"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
endif|#
directive|endif
comment|/* ferror */
else|#
directive|else
name|x
operator|=
name|feof
argument_list|(
name|fp
index|[
name|ZIFILE
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zinfill errno"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zinfill feof"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|x
operator|&&
name|ferror
argument_list|(
name|fp
index|[
name|ZIFILE
index|]
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
endif|#
directive|endif
comment|/* UTEK */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|zinptr
operator|=
name|zinbuffer
expr_stmt|;
comment|/* set pointer to beginning, (==&zinbuffer[0]) */
name|zincnt
operator|--
expr_stmt|;
comment|/* one less char in buffer */
return|return
operator|(
call|(
name|int
call|)
argument_list|(
operator|*
name|zinptr
operator|++
argument_list|)
operator|&
literal|0377
operator|)
return|;
comment|/* because we return the first */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  Z S O U T  --  Write a string out to the given file, buffered.  */
end_comment

begin_function
name|int
name|zsout
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
name|int
name|n
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|{
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Keep this here, prevents memory faults */
ifndef|#
directive|ifndef
name|OS2
if|if
condition|(
name|n
operator|==
name|ZSFILE
condition|)
return|return
operator|(
name|write
argument_list|(
name|fileno
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
argument_list|,
name|s
argument_list|,
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
argument_list|)
operator|)
return|;
else|else
endif|#
directive|endif
comment|/* OS2 */
return|return
operator|(
name|fputs
argument_list|(
name|s
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
operator|==
name|EOF
condition|?
operator|-
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Z S O U T L  --  Write string to file, with line terminator, buffered  */
end_comment

begin_function
name|int
name|zsoutl
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
name|int
name|n
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|{
comment|/* if (chkfn(n)< 1) return(-1); */
if|if
condition|(
name|fputs
argument_list|(
name|s
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
operator|==
name|EOF
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
operator|==
name|EOF
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* (===OS2 ? \r\n) */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Z S O U T X  --  Write x characters to file, unbuffered.  */
end_comment

begin_function
name|int
name|zsoutx
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|,
name|x
parameter_list|)
name|int
name|n
decl_stmt|,
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|COMMENT
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|write
argument_list|(
name|fp
index|[
name|n
index|]
operator|->
name|_file
argument_list|,
name|s
argument_list|,
name|x
argument_list|)
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
name|write
argument_list|(
name|fileno
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
argument_list|,
name|s
argument_list|,
name|x
argument_list|)
operator|==
name|x
condition|?
name|x
else|:
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Z C H O U T  --  Add a character to the given file.  */
end_comment

begin_comment
comment|/*  Should return 0 or greater on success, -1 on failure (e.g. disk full)  */
end_comment

begin_function
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|zchout
parameter_list|(
specifier|register
name|int
name|n
parameter_list|,
name|char
name|c
parameter_list|)
else|#
directive|else
function|zchout
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
specifier|register
name|int
name|n
decl_stmt|;
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* zchout() */
block|{
comment|/* if (chkfn(n)< 1) return(-1); */
ifndef|#
directive|ifndef
name|OS2
if|if
condition|(
name|n
operator|==
name|ZSFILE
condition|)
block|{
comment|/* Use unbuffered for session log */
return|return
operator|(
name|write
argument_list|(
name|fileno
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
operator|==
literal|1
condition|?
literal|0
else|:
operator|-
literal|1
operator|)
return|;
block|}
else|else
block|{
comment|/* Buffered for everything else */
endif|#
directive|endif
comment|/* OS2 */
if|if
condition|(
name|putc
argument_list|(
name|c
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
operator|==
name|EOF
condition|)
comment|/* If true, maybe there was an error */
return|return
operator|(
name|ferror
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
condition|?
operator|-
literal|1
else|:
literal|0
operator|)
return|;
comment|/* Check to make sure */
else|else
comment|/* Otherwise... */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* There was no error. */
ifndef|#
directive|ifndef
name|OS2
block|}
endif|#
directive|endif
comment|/* OS2 */
block|}
end_function

begin_comment
comment|/* (PWP) buffered character output routine to speed up file IO */
end_comment

begin_function
name|int
name|zoutdump
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|zoutptr
operator|=
name|zoutbuffer
expr_stmt|;
comment|/* Reset buffer pointer in all cases */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zoutdump chars"
argument_list|,
literal|""
argument_list|,
name|zoutcnt
argument_list|)
expr_stmt|;
if|if
condition|(
name|zoutcnt
operator|==
literal|0
condition|)
block|{
comment|/* Nothing to output */
return|return
operator|(
literal|0
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|zoutcnt
operator|<
literal|0
condition|)
block|{
comment|/* Unexpected negative argument */
name|zoutcnt
operator|=
literal|0
expr_stmt|;
comment|/* Reset output buffer count */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* and fail. */
block|}
comment|/* Frank Prindle suggested that replacing this fwrite() by an fflush() */
comment|/* followed by a write() would improve the efficiency, especially when */
comment|/* writing to stdout.  Subsequent tests showed a 5-fold improvement!   */
comment|/* if (x = fwrite(zoutbuffer, 1, zoutcnt, fp[ZOFILE])) {              */
name|fflush
argument_list|(
name|fp
index|[
name|ZOFILE
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
name|write
argument_list|(
name|fileno
argument_list|(
name|fp
index|[
name|ZOFILE
index|]
argument_list|)
argument_list|,
name|zoutbuffer
argument_list|,
name|zoutcnt
argument_list|)
operator|)
operator|==
name|zoutcnt
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zoutdump write ok"
argument_list|,
literal|""
argument_list|,
name|zoutcnt
argument_list|)
expr_stmt|;
name|zoutcnt
operator|=
literal|0
expr_stmt|;
comment|/* Reset output buffer count */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* write() worked OK */
block|}
else|else
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zoutdump write error"
argument_list|,
literal|""
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zoutdump write returns"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|zoutcnt
operator|=
literal|0
expr_stmt|;
comment|/* Reset output buffer count */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* write() failed */
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  C H K F N  --  Internal function to verify file number is ok  */
end_comment

begin_comment
comment|/*  Returns:   -1: File number n is out of range    0: n is in range, but file is not open    1: n in range and file is open */
end_comment

begin_function
name|int
name|chkfn
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|COMMENT
comment|/* Save some stack space */
switch|switch
condition|(
name|n
condition|)
block|{
case|case
name|ZCTERM
case|:
case|case
name|ZSTDIO
case|:
case|case
name|ZIFILE
case|:
case|case
name|ZOFILE
case|:
case|case
name|ZDFILE
case|:
case|case
name|ZTFILE
case|:
case|case
name|ZPFILE
case|:
case|case
name|ZSFILE
case|:
case|case
name|ZSYSFN
case|:
case|case
name|ZRFILE
case|:
case|case
name|ZWFILE
case|:
break|break;
default|default:
name|debug
argument_list|(
name|F101
argument_list|,
literal|"chkfn: file number out of range"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"?File number out of range - %d\n"
argument_list|,
name|n
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
operator|(
name|fp
index|[
name|n
index|]
operator|==
name|NULL
operator|)
condition|?
literal|0
else|:
literal|1
operator|)
return|;
else|#
directive|else
if|if
condition|(
name|n
operator|<
literal|0
operator|||
name|n
operator|>=
name|ZNFILS
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
operator|(
name|fp
index|[
name|n
index|]
operator|==
name|NULL
operator|)
condition|?
literal|0
else|:
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* COMMENT */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  Z C H K I  --  Check if input file exists and is readable  */
end_comment

begin_comment
comment|/*   Returns:>= 0 if the file can be read (returns the size).      -1 if file doesn't exist or can't be accessed,      -2 if file exists but is not readable (e.g. a directory file).      -3 if file exists but protected against read access. */
end_comment

begin_comment
comment|/*  For Berkeley Unix, a file must be of type "regular" to be readable.  Directory files, special files, and symbolic links are not readable. */
end_comment

begin_function
name|long
name|zchki
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|struct
name|stat
name|buf
decl_stmt|;
name|int
name|x
decl_stmt|;
ifdef|#
directive|ifdef
name|UNIX
name|x
operator|=
name|strlen
argument_list|(
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|9
operator|&&
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"/dev/null"
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* UNIX */
name|x
operator|=
name|stat
argument_list|(
name|name
argument_list|,
operator|&
name|buf
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
name|F111
argument_list|,
literal|"zchki stat fails"
argument_list|,
name|name
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
if|if
condition|(
operator|!
name|S_ISREG
argument_list|(
name|buf
operator|.
name|st_mode
argument_list|)
condition|)
block|{
comment|/* Must be regular file */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchki skipping:"
argument_list|,
name|name
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchki stat ok:"
argument_list|,
name|name
argument_list|,
name|x
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|OXOS
name|priv_on
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* OXOS */
name|x
operator|=
name|access
argument_list|(
name|name
argument_list|,
name|R_OK
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|OXOS
name|priv_chk
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* OXOS */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
comment|/* Is the file accessible? */
name|debug
argument_list|(
name|F111
argument_list|,
literal|" access failed:"
argument_list|,
name|name
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* No */
return|return
operator|(
operator|-
literal|3
operator|)
return|;
block|}
else|else
block|{
name|iflen
operator|=
name|buf
operator|.
name|st_size
expr_stmt|;
comment|/* Yes, remember size */
name|strncpy
argument_list|(
name|nambuf
argument_list|,
name|name
argument_list|,
name|MAXNAMLEN
argument_list|)
expr_stmt|;
comment|/* and name globally. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|" access ok:"
argument_list|,
name|name
argument_list|,
operator|(
name|int
operator|)
name|iflen
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|iflen
operator|>
operator|-
literal|1L
operator|)
condition|?
name|iflen
else|:
literal|0L
operator|)
return|;
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  Z C H K O  --  Check if output file can be created  */
end_comment

begin_comment
comment|/*  Returns -1 if write permission for the file would be denied, 0 otherwise. */
end_comment

begin_function
name|int
name|zchko
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|int
name|i
decl_stmt|,
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
operator|!
name|name
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Watch out for null pointer. */
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|name
argument_list|)
expr_stmt|;
comment|/* Get length of filename */
name|debug
argument_list|(
name|F101
argument_list|,
literal|" length"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|UNIX
comment|/*   Writing to null device is OK. */
if|if
condition|(
name|x
operator|==
literal|9
operator|&&
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"/dev/null"
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* UNIX */
name|s
operator|=
name|malloc
argument_list|(
name|x
operator|+
literal|3
argument_list|)
expr_stmt|;
comment|/* Must copy because we can't */
if|if
condition|(
operator|!
name|s
condition|)
block|{
comment|/* write into our argument. */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Malloc error 46\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|strcpy
argument_list|(
name|s
argument_list|,
name|name
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|x
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
comment|/* Strip filename from right. */
if|if
condition|(
name|ISDIRSEP
argument_list|(
name|s
index|[
name|i
operator|-
literal|1
index|]
argument_list|)
condition|)
break|break;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" i"
argument_list|,
literal|""
argument_list|,
name|i
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
comment|/* X/OPEN XPG3-compliant systems fail if argument ends with "/"...  */
if|if
condition|(
name|i
operator|==
literal|0
condition|)
comment|/* If no path, use current directory */
name|strcpy
argument_list|(
name|s
argument_list|,
literal|"./"
argument_list|)
expr_stmt|;
else|else
comment|/* Otherwise, use given one. */
name|s
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
else|#
directive|else
comment|/* So now we use "path/." if path given, or "." if no path given. */
name|s
index|[
name|i
operator|++
index|]
operator|=
literal|'.'
expr_stmt|;
comment|/* Append "." to path. */
name|s
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
ifdef|#
directive|ifdef
name|OXOS
name|priv_on
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* OXOS */
ifdef|#
directive|ifdef
name|OS2
comment|/* No unwritable directories in OS/2 */
name|x
operator|=
literal|0
expr_stmt|;
else|#
directive|else
name|x
operator|=
name|access
argument_list|(
name|s
argument_list|,
name|W_OK
argument_list|)
expr_stmt|;
comment|/* Check access of path. */
endif|#
directive|endif
comment|/* OS2 */
ifdef|#
directive|ifdef
name|OXOS
name|priv_chk
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* OXOS */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchko access failed:"
argument_list|,
name|s
argument_list|,
name|errno
argument_list|)
expr_stmt|;
else|else
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchko access ok:"
argument_list|,
name|s
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* Free temporary storage */
return|return
operator|(
operator|(
name|x
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
literal|0
operator|)
return|;
comment|/* and return. */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  Z D E L E T  --  Delete the named file.  */
end_comment

begin_function
name|int
name|zdelet
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
return|return
operator|(
name|unlink
argument_list|(
name|name
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Z R T O L  --  Convert remote filename into local form  */
end_comment

begin_comment
comment|/*  For UNIX, this means changing uppercase letters to lowercase.  */
end_comment

begin_function
name|VOID
name|zrtol
parameter_list|(
name|name
parameter_list|,
name|name2
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|,
decl|*
name|name2
decl_stmt|;
end_function

begin_block
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|flag
init|=
literal|0
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zrtol name"
argument_list|,
literal|""
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zrtol name2"
argument_list|,
literal|""
argument_list|,
name|name2
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|name
operator|||
operator|!
name|name2
condition|)
return|return;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zrtol input"
argument_list|,
literal|""
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|p
operator|=
name|name2
expr_stmt|;
for|for
control|(
init|;
operator|*
name|name
operator|!=
literal|'\0'
condition|;
name|name
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|name
operator|>
literal|' '
condition|)
name|flag
operator|=
literal|1
expr_stmt|;
comment|/* Strip leading blanks and controls */
if|if
condition|(
name|flag
operator|==
literal|0
operator|&&
operator|*
name|name
operator|<
literal|'!'
condition|)
continue|continue;
operator|*
name|p
operator|++
operator|=
name|isupper
argument_list|(
operator|*
name|name
argument_list|)
condition|?
name|tolower
argument_list|(
operator|*
name|name
argument_list|)
else|:
operator|*
name|name
expr_stmt|;
block|}
operator|*
name|p
operator|--
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate */
while|while
condition|(
operator|*
name|p
operator|<
literal|'!'
operator|&&
name|p
operator|>
name|name2
condition|)
comment|/* Strip trailing blanks& contronls */
operator|*
name|p
operator|--
operator|=
literal|'\0'
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
operator|!
name|IsFileNameValid
argument_list|(
name|name2
argument_list|)
condition|)
name|ChangeNameForFAT
argument_list|(
name|name2
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zrtol result"
argument_list|,
name|name2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  Z S T R I P  --  Strip device& directory name from file specification */
end_comment

begin_comment
comment|/*  Strip pathname from filename "name", return pointer to result in name2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|work
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for use by zstrip and zltor */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
name|work
index|[
literal|257
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_function
name|VOID
name|zstrip
parameter_list|(
name|name
parameter_list|,
name|name2
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|,
decl|*
modifier|*
name|name2
decl_stmt|;
end_function

begin_block
block|{
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|pp
decl_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zstrip before"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pp
operator|=
name|work
expr_stmt|;
ifdef|#
directive|ifdef
name|DTILDE
if|if
condition|(
operator|*
name|name
operator|==
literal|'~'
condition|)
name|name
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* DTILDE */
for|for
control|(
name|cp
operator|=
name|name
init|;
operator|*
name|cp
operator|!=
literal|'\0'
condition|;
name|cp
operator|++
control|)
block|{
if|if
condition|(
name|ISDIRSEP
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
name|pp
operator|=
name|work
expr_stmt|;
else|else
operator|*
name|pp
operator|++
operator|=
operator|*
name|cp
expr_stmt|;
block|}
operator|*
name|pp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate the string */
operator|*
name|name2
operator|=
name|work
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zstrip after"
argument_list|,
operator|*
name|name2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  Z L T O R  --  Local TO Remote */
end_comment

begin_function
name|VOID
name|zltor
parameter_list|(
name|name
parameter_list|,
name|name2
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|,
decl|*
name|name2
decl_stmt|;
end_function

begin_block
block|{
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|pp
decl_stmt|;
name|int
name|dc
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|aegis
name|char
modifier|*
name|namechars
decl_stmt|;
name|int
name|tilde
init|=
literal|0
decl_stmt|,
name|bslash
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|namechars
operator|=
name|getenv
argument_list|(
literal|"NAMECHARS"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|xindex
argument_list|(
name|namechars
argument_list|,
literal|'~'
argument_list|)
operator|!=
name|NULL
condition|)
name|tilde
operator|=
literal|'~'
expr_stmt|;
if|if
condition|(
name|xindex
argument_list|(
name|namechars
argument_list|,
literal|'\\'
argument_list|)
operator|!=
name|NULL
condition|)
name|bslash
operator|=
literal|'\\'
expr_stmt|;
block|}
else|else
block|{
name|tilde
operator|=
literal|'~'
expr_stmt|;
name|bslash
operator|=
literal|'\\'
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* aegis */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zltor"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pp
operator|=
name|work
expr_stmt|;
ifdef|#
directive|ifdef
name|aegis
name|cp
operator|=
name|name
expr_stmt|;
if|if
condition|(
name|tilde
operator|&&
operator|*
name|cp
operator|==
name|tilde
condition|)
operator|++
name|cp
expr_stmt|;
for|for
control|(
init|;
operator|*
name|cp
operator|!=
literal|'\0'
condition|;
name|cp
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|cp
operator|==
literal|'/'
operator|||
operator|*
name|cp
operator|==
name|bslash
condition|)
block|{
comment|/* strip path name */
else|#
directive|else
for|for
control|(
name|cp
operator|=
name|name
init|;
operator|*
name|cp
operator|!=
literal|'\0'
condition|;
name|cp
operator|++
control|)
block|{
comment|/* strip path name */
if|if
condition|(
name|ISDIRSEP
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
block|{
endif|#
directive|endif
comment|/* aegis */
name|dc
operator|=
literal|0
expr_stmt|;
name|pp
operator|=
name|work
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|islower
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
operator|*
name|pp
operator|++
operator|=
name|toupper
argument_list|(
operator|*
name|cp
argument_list|)
expr_stmt|;
comment|/* Uppercase letters */
elseif|else
if|if
condition|(
operator|*
name|cp
operator|==
literal|'~'
condition|)
operator|*
name|pp
operator|++
operator|=
literal|'X'
expr_stmt|;
comment|/* Change tilde to 'X' */
elseif|else
if|if
condition|(
operator|*
name|cp
operator|==
literal|'#'
condition|)
operator|*
name|pp
operator|++
operator|=
literal|'X'
expr_stmt|;
comment|/* Change number sign to 'X' */
elseif|else
if|if
condition|(
operator|(
operator|*
name|cp
operator|==
literal|'.'
operator|)
operator|&&
operator|(
operator|++
name|dc
operator|>
literal|1
operator|)
condition|)
operator|*
name|pp
operator|++
operator|=
literal|'X'
expr_stmt|;
comment|/*& extra dots */
else|else
operator|*
name|pp
operator|++
operator|=
operator|*
name|cp
expr_stmt|;
block|}
operator|*
name|pp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Tie it off. */
name|cp
operator|=
name|name2
expr_stmt|;
comment|/* If nothing before dot, */
if|if
condition|(
operator|*
name|work
operator|==
literal|'.'
condition|)
operator|*
name|cp
operator|++
operator|=
literal|'X'
expr_stmt|;
comment|/* insert 'X' */
name|strcpy
argument_list|(
name|cp
argument_list|,
name|work
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|" name2"
argument_list|,
name|name2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/*  Z C H D I R  --  Change directory  */
comment|/*   Call with:     dirnam = pointer to name of directory to change to,       which may be "" or NULL to indicate user's home directory.   Returns:     0 on failure     1 on success */
name|int
name|zchdir
parameter_list|(
name|dirnam
parameter_list|)
name|char
modifier|*
name|dirnam
decl_stmt|;
block|{
name|char
modifier|*
name|hd
decl_stmt|,
modifier|*
name|sp
decl_stmt|,
modifier|*
name|p
decl_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zchdir"
argument_list|,
name|dirnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|dirnam
operator|==
name|NULL
operator|||
name|dirnam
operator|==
literal|""
operator|||
operator|*
name|dirnam
operator|==
literal|'\0'
condition|)
comment|/* If arg is null */
name|dirnam
operator|=
name|zhome
argument_list|()
expr_stmt|;
comment|/* use user's home directory. */
name|sp
operator|=
name|dirnam
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zchdir 2"
argument_list|,
name|dirnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DTILDE
name|hd
operator|=
name|tilde_expand
argument_list|(
name|dirnam
argument_list|)
expr_stmt|;
comment|/* Attempt to expand tilde */
if|if
condition|(
operator|*
name|hd
operator|==
literal|'\0'
condition|)
name|hd
operator|=
name|dirnam
expr_stmt|;
comment|/* in directory name. */
else|#
directive|else
name|hd
operator|=
name|dirnam
expr_stmt|;
endif|#
directive|endif
comment|/* DTILDE */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zchdir 3"
argument_list|,
name|hd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|pdp11
comment|/* Just to save some space */
return|return
operator|(
operator|(
name|chdir
argument_list|(
name|hd
argument_list|)
operator|==
literal|0
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
name|isalpha
argument_list|(
name|hd
index|[
literal|0
index|]
argument_list|)
operator|&&
name|hd
index|[
literal|1
index|]
operator|==
literal|':'
condition|)
block|{
if|if
condition|(
name|zchdsk
argument_list|(
name|hd
index|[
literal|0
index|]
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|hd
index|[
literal|2
index|]
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Handle drive-only case */
block|}
endif|#
directive|endif
comment|/* OS2 */
if|if
condition|(
name|chdir
argument_list|(
name|hd
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Try to cd */
comment|/* (===OS2===) */
name|p
operator|=
name|sp
expr_stmt|;
comment|/* Failed, lowercase it. */
while|while
condition|(
operator|*
name|p
condition|)
block|{
if|if
condition|(
name|isupper
argument_list|(
operator|*
name|p
argument_list|)
condition|)
operator|*
name|p
operator|=
name|tolower
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zchdir 4"
argument_list|,
name|hd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DTILDE
name|hd
operator|=
name|tilde_expand
argument_list|(
name|sp
argument_list|)
expr_stmt|;
comment|/* Try again to expand tilde */
if|if
condition|(
operator|*
name|hd
operator|==
literal|'\0'
condition|)
name|hd
operator|=
name|sp
expr_stmt|;
else|#
directive|else
name|hd
operator|=
name|sp
expr_stmt|;
comment|/* Point to result */
endif|#
directive|endif
comment|/* DTILDE */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zchdir 5"
argument_list|,
name|hd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|chdir
argument_list|(
name|hd
argument_list|)
operator|==
literal|0
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* pdp11 */
block|}
comment|/*  Z H O M E  --  Return pointer to user's home directory  */
name|char
modifier|*
name|zhome
parameter_list|()
block|{
name|char
modifier|*
name|home
init|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|OS2
specifier|extern
name|char
name|startupdir
index|[]
decl_stmt|;
return|return
operator|(
name|home
condition|?
name|home
else|:
name|startupdir
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|home
condition|?
name|home
else|:
literal|"."
operator|)
return|;
endif|#
directive|endif
block|}
comment|/*  Z G T D I R  --  Return pointer to user's current directory  */
ifdef|#
directive|ifdef
name|pdp11
define|#
directive|define
name|CWDBL
value|80
comment|/* Save every byte we can... */
else|#
directive|else
ifdef|#
directive|ifdef
name|MAXPATHLEN
define|#
directive|define
name|CWDBL
value|MAXPATHLEN
else|#
directive|else
define|#
directive|define
name|CWDBL
value|100
endif|#
directive|endif
comment|/* MAXPATHLEN */
endif|#
directive|endif
comment|/* pdp11 */
specifier|static
name|char
name|cwdbuf
index|[
name|CWDBL
operator|+
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|zgtdir
parameter_list|()
block|{
name|char
modifier|*
name|buf
decl_stmt|;
ifdef|#
directive|ifdef
name|BSD44
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
name|buf
operator|=
name|cwdbuf
expr_stmt|;
return|return
operator|(
name|getwd
argument_list|(
name|buf
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|SVORPOSIX
specifier|extern
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
name|buf
operator|=
name|cwdbuf
expr_stmt|;
return|return
operator|(
name|getcwd
argument_list|(
name|buf
argument_list|,
name|CWDBL
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|OS2
specifier|extern
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
name|buf
operator|=
name|cwdbuf
expr_stmt|;
return|return
operator|(
name|getcwd
argument_list|(
name|buf
argument_list|,
name|CWDBL
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD4
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
name|buf
operator|=
name|cwdbuf
expr_stmt|;
return|return
operator|(
name|getwd
argument_list|(
name|buf
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|"directory unknown"
operator|)
return|;
endif|#
directive|endif
comment|/* BSD4 */
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* SYSVORPOSIX */
endif|#
directive|endif
comment|/* BSD44 */
block|}
comment|/*  Z X C M D -- Run a system command so its output can be read like a file */
name|int
name|zxcmd
parameter_list|(
name|filnum
parameter_list|,
name|comand
parameter_list|)
name|int
name|filnum
decl_stmt|;
name|char
modifier|*
name|comand
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
name|chkfn
argument_list|(
name|filnum
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
comment|/* Need a valid Kermit file number. */
if|if
condition|(
name|filnum
operator|==
name|ZSTDIO
operator|||
name|filnum
operator|==
name|ZCTERM
condition|)
comment|/* But not one of these. */
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|filnum
operator|==
name|ZIFILE
operator|||
name|filnum
operator|==
name|ZRFILE
condition|)
block|{
comment|/* Input from a command */
if|if
condition|(
name|priv_chk
argument_list|()
operator|||
operator|(
operator|(
name|fp
index|[
name|filnum
index|]
operator|=
name|popen
argument_list|(
name|comand
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
comment|/* Output to a command */
if|if
condition|(
name|priv_chk
argument_list|()
operator|||
operator|(
operator|(
name|fp
index|[
name|filnum
index|]
operator|=
name|popen
argument_list|(
name|comand
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|ispipe
index|[
name|filnum
index|]
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
else|#
directive|else
comment|/* Not OS2 */
name|int
name|pipes
index|[
literal|2
index|]
decl_stmt|;
name|int
name|out
decl_stmt|;
if|if
condition|(
name|chkfn
argument_list|(
name|filnum
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
comment|/* Need a valid Kermit file number. */
if|if
condition|(
name|filnum
operator|==
name|ZSTDIO
operator|||
name|filnum
operator|==
name|ZCTERM
condition|)
comment|/* But not one of these. */
return|return
operator|(
literal|0
operator|)
return|;
name|out
operator|=
operator|(
name|filnum
operator|==
name|ZIFILE
operator|||
name|filnum
operator|==
name|ZRFILE
operator|)
condition|?
literal|0
else|:
literal|1
expr_stmt|;
comment|/* Output to a command */
if|if
condition|(
name|out
condition|)
block|{
comment|/* Need popen() to do this. */
ifdef|#
directive|ifdef
name|NOPOPEN
return|return
operator|(
literal|0
operator|)
return|;
comment|/* no popen(), fail. */
else|#
directive|else
comment|/* Use popen() to run the command. */
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
comment|/* Strictly speaking, popen() is not available in POSIX.1 */
define|#
directive|define
name|DCLPOPEN
endif|#
directive|endif
comment|/* _POSIX_SOURCE */
ifdef|#
directive|ifdef
name|DCLPOPEN
comment|/* popen() needs declaring because it's not declared in<stdio.h> */
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* DCLPOPEN */
if|if
condition|(
name|priv_chk
argument_list|()
operator|||
operator|(
operator|(
name|fp
index|[
name|filnum
index|]
operator|=
name|popen
argument_list|(
name|comand
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* NOPOPEN */
block|}
comment|/* Input from a command */
if|if
condition|(
name|pipe
argument_list|(
name|pipes
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"zxcmd pipe failure"
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
comment|/* can't make pipe, fail */
block|}
comment|/* Create a fork in which to run the named process */
ifdef|#
directive|ifdef
name|aegis
if|if
condition|(
operator|(
name|pid
operator|=
name|vfork
argument_list|()
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* child */
else|#
directive|else
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
comment|/* child */
endif|#
directive|endif
comment|/* We're in the fork. */
name|char
modifier|*
name|shpath
decl_stmt|,
modifier|*
name|shname
decl_stmt|,
modifier|*
name|shptr
decl_stmt|;
comment|/* Find user's preferred shell */
ifndef|#
directive|ifndef
name|aegis
name|struct
name|passwd
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|defshell
init|=
literal|"/bin/sh"
decl_stmt|;
comment|/* default shell */
endif|#
directive|endif
comment|/* aegis */
if|if
condition|(
name|priv_can
argument_list|()
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Turn off any privileges! */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zxcmd pid"
argument_list|,
literal|""
argument_list|,
name|pid
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|pipes
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* close input side of pipe */
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* close stdin */
if|if
condition|(
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* replace input by null */
ifndef|#
directive|ifndef
name|SVORPOSIX
name|dup2
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* BSD: replace stdout& stderr */
name|dup2
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|/* by the pipe */
else|#
directive|else
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* AT&T: close stdout */
if|if
condition|(
name|dup
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|)
operator|!=
literal|1
condition|)
comment|/* Send stdout to the pipe */
return|return
operator|(
literal|0
operator|)
return|;
name|close
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* Send stderr to the pipe */
if|if
condition|(
name|dup
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|)
operator|!=
literal|2
condition|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* SVORPOSIX */
name|close
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* Don't need this any more. */
ifdef|#
directive|ifdef
name|aegis
if|if
condition|(
operator|(
name|shpath
operator|=
name|getenv
argument_list|(
literal|"SERVERSHELL"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|shpath
operator|=
literal|"/bin/sh"
expr_stmt|;
else|#
directive|else
name|shpath
operator|=
name|getenv
argument_list|(
literal|"SHELL"
argument_list|)
expr_stmt|;
comment|/* What shell? */
if|if
condition|(
name|shpath
operator|==
name|NULL
condition|)
block|{
name|p
operator|=
name|getpwuid
argument_list|(
name|real_uid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* Get login data */
if|if
condition|(
name|p
operator|==
operator|(
expr|struct
name|passwd
operator|*
operator|)
name|NULL
operator|||
operator|!
operator|*
operator|(
name|p
operator|->
name|pw_shell
operator|)
condition|)
name|shpath
operator|=
name|defshell
expr_stmt|;
else|else
name|shpath
operator|=
name|p
operator|->
name|pw_shell
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* aegis */
name|shptr
operator|=
name|shname
operator|=
name|shpath
expr_stmt|;
while|while
condition|(
operator|*
name|shptr
operator|!=
literal|'\0'
condition|)
if|if
condition|(
operator|*
name|shptr
operator|++
operator|==
literal|'/'
condition|)
name|shname
operator|=
name|shptr
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"zxcmd..."
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
name|shpath
argument_list|,
name|shname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|execl
argument_list|(
name|shpath
argument_list|,
name|shname
argument_list|,
literal|"-c"
argument_list|,
name|comand
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
comment|/* Execute the cmd */
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* just punt if it failed. */
block|}
elseif|else
if|if
condition|(
name|pid
operator|==
operator|(
name|PID_T
operator|)
operator|-
literal|1
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"zxcmd fork failure"
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
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zxcmd pid"
argument_list|,
literal|""
argument_list|,
name|pid
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|close
argument_list|(
name|pipes
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* Don't need the input side */
name|fp
index|[
name|filnum
index|]
operator|=
name|fdopen
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
comment|/* Open a stream for output. */
name|fp
index|[
name|ZSYSFN
index|]
operator|=
name|fp
index|[
name|filnum
index|]
expr_stmt|;
comment|/* Remember. */
name|zoutcnt
operator|=
literal|0
expr_stmt|;
comment|/* (PWP) reset input buffer */
name|zoutptr
operator|=
name|zoutbuffer
expr_stmt|;
block|}
else|else
block|{
name|close
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* Don't need the output side */
name|fp
index|[
name|filnum
index|]
operator|=
name|fdopen
argument_list|(
name|pipes
index|[
literal|0
index|]
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
comment|/* Open a stream for input. */
name|fp
index|[
name|ZSYSFN
index|]
operator|=
name|fp
index|[
name|filnum
index|]
expr_stmt|;
comment|/* Remember. */
name|zincnt
operator|=
literal|0
expr_stmt|;
comment|/* (PWP) reset input buffer */
name|zinptr
operator|=
name|zinbuffer
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* OS2 */
block|}
comment|/*  Z C L O S F  - wait for the child fork to terminate and close the pipe. */
name|int
name|zclosf
parameter_list|(
name|filnum
parameter_list|)
name|int
name|filnum
decl_stmt|;
block|{
name|int
name|wstat
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zclosf filnum"
argument_list|,
literal|""
argument_list|,
name|filnum
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOPOPEN
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
name|ispipe
index|[
name|filnum
index|]
condition|)
block|{
name|int
name|x
decl_stmt|;
name|x
operator|=
name|pclose
argument_list|(
name|fp
index|[
name|filnum
index|]
argument_list|)
expr_stmt|;
name|fp
index|[
name|filnum
index|]
operator|=
name|NULL
expr_stmt|;
name|ispipe
index|[
name|filnum
index|]
operator|=
literal|0
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|filnum
operator|==
name|ZWFILE
condition|)
block|{
name|int
name|x
decl_stmt|;
name|x
operator|=
name|pclose
argument_list|(
name|fp
index|[
name|filnum
index|]
argument_list|)
expr_stmt|;
name|fp
index|[
name|filnum
index|]
operator|=
name|fp
index|[
name|ZSYSFN
index|]
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
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
literal|1
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* NOPOPEN */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zclosf fp[filnum]"
argument_list|,
literal|""
argument_list|,
name|fp
index|[
name|filnum
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zclosf fp[ZSYSFN]"
argument_list|,
literal|""
argument_list|,
name|fp
index|[
name|ZSYSFN
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
name|fclose
argument_list|(
name|fp
index|[
name|filnum
index|]
argument_list|)
expr_stmt|;
name|fp
index|[
name|filnum
index|]
operator|=
name|NULL
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|pid
operator|!=
operator|(
name|PID_T
operator|)
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"zclosf killing pid"
argument_list|,
literal|""
argument_list|,
name|pid
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|pid
argument_list|,
literal|9
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|wstat
operator|=
name|wait
argument_list|(
operator|(
name|WAIT_T
operator|*
operator|)
literal|0
argument_list|)
operator|)
operator|!=
name|pid
operator|&&
name|wstat
operator|!=
operator|-
literal|1
condition|)
empty_stmt|;
name|pid
operator|=
literal|0
expr_stmt|;
block|}
name|fclose
argument_list|(
name|fp
index|[
name|filnum
index|]
argument_list|)
expr_stmt|;
name|fp
index|[
name|filnum
index|]
operator|=
name|fp
index|[
name|ZSYSFN
index|]
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/*  Z X P A N D  --  Expand a wildcard string into an array of strings  */
comment|/*   Returns the number of files that match fn1, with data structures set up   so that first file (if any) will be returned by the next znext() call.   Depends on external variable wildxpand: 0 means we expand wildcards   internally, nonzero means we call the shell to do it. */
name|int
name|zxpand
parameter_list|(
name|fn
parameter_list|)
name|char
modifier|*
name|fn
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
ifdef|#
directive|ifdef
name|DTILDE
comment|/* Built with tilde-expansion? */
name|char
modifier|*
name|tnam
decl_stmt|;
endif|#
directive|endif
comment|/* DTILDE */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zxpand entry"
argument_list|,
name|fn
argument_list|,
name|wildxpand
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DTILDE
comment|/* Built with tilde-expansion? */
if|if
condition|(
operator|*
name|fn
operator|==
literal|'~'
condition|)
block|{
comment|/* Starts with tilde? */
name|tnam
operator|=
name|tilde_expand
argument_list|(
name|fn
argument_list|)
expr_stmt|;
comment|/* Try to expand it. */
if|if
condition|(
name|tnam
condition|)
name|fn
operator|=
name|tnam
expr_stmt|;
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zxpand after tilde_x"
argument_list|,
name|fn
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DTILDE */
ifndef|#
directive|ifndef
name|OS2
if|if
condition|(
name|wildxpand
condition|)
comment|/* Who is expanding wildcards? */
name|fcount
operator|=
name|shxpand
argument_list|(
name|fn
argument_list|,
name|mtchs
argument_list|,
name|MAXWLD
argument_list|)
expr_stmt|;
comment|/* Shell */
else|else
endif|#
directive|endif
comment|/* OS2 */
name|fcount
operator|=
name|fgen
argument_list|(
name|fn
argument_list|,
name|mtchs
argument_list|,
name|MAXWLD
argument_list|)
expr_stmt|;
comment|/* Kermit */
if|if
condition|(
name|fcount
operator|>
literal|0
condition|)
block|{
name|mtchptr
operator|=
name|mtchs
expr_stmt|;
comment|/* Save pointer for next. */
block|}
if|if
condition|(
name|fcount
operator|>
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zxpand ok"
argument_list|,
name|mtchs
index|[
literal|0
index|]
argument_list|,
name|fcount
argument_list|)
expr_stmt|;
return|return
operator|(
name|fcount
operator|)
return|;
block|}
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zxpand fgen1"
argument_list|,
name|fn
argument_list|,
name|fcount
argument_list|)
expr_stmt|;
comment|/* Didn't get one, or got too many */
name|p
operator|=
name|malloc
argument_list|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|fn
argument_list|)
operator|+
literal|10
argument_list|)
expr_stmt|;
comment|/* Make space */
if|if
condition|(
operator|!
name|p
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|zrtol
argument_list|(
name|fn
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* Try again, maybe lowercase */
ifndef|#
directive|ifndef
name|OS2
if|if
condition|(
name|wildxpand
condition|)
name|fcount
operator|=
name|shxpand
argument_list|(
name|p
argument_list|,
name|mtchs
argument_list|,
name|MAXWLD
argument_list|)
expr_stmt|;
comment|/* Shell */
else|else
endif|#
directive|endif
comment|/* OS2 */
name|fcount
operator|=
name|fgen
argument_list|(
name|p
argument_list|,
name|mtchs
argument_list|,
name|MAXWLD
argument_list|)
expr_stmt|;
comment|/* Kermit */
if|if
condition|(
name|fcount
operator|>
literal|0
condition|)
block|{
comment|/* Got one? */
name|mtchptr
operator|=
name|mtchs
expr_stmt|;
comment|/* Save pointer for next. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zxpand fgen2 ok"
argument_list|,
name|mtchs
index|[
literal|0
index|]
argument_list|,
name|fcount
argument_list|)
expr_stmt|;
block|}
else|else
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zxpand 2 not ok"
argument_list|,
name|p
argument_list|,
name|fcount
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|fcount
operator|)
return|;
block|}
comment|/*  Z N E X T  --  Get name of next file from list created by zxpand(). */
comment|/*  Returns>0 if there's another file, with its name copied into the arg string,  or 0 if no more files in list. */
name|int
name|znext
parameter_list|(
name|fn
parameter_list|)
name|char
modifier|*
name|fn
decl_stmt|;
block|{
if|if
condition|(
name|fcount
operator|--
operator|>
literal|0
condition|)
name|strcpy
argument_list|(
name|fn
argument_list|,
operator|*
name|mtchptr
operator|++
argument_list|)
expr_stmt|;
else|else
operator|*
name|fn
operator|=
literal|'\0'
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"znext"
argument_list|,
name|fn
argument_list|,
name|fcount
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|fcount
operator|+
literal|1
operator|)
return|;
block|}
comment|/*  Z C H K S P A  --  Check if there is enough space to store the file  */
comment|/*  Call with file specification f, size n in bytes.  Returns -1 on error, 0 if not enough space, 1 if enough space. */
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|zchkspa
parameter_list|(
name|char
modifier|*
name|f
parameter_list|,
name|long
name|n
parameter_list|)
else|#
directive|else
function|zchkspa
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|f
decl_stmt|;
name|long
name|n
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* zchkspa() */
block|{
ifdef|#
directive|ifdef
name|OS2
comment|/* OS/2 gives us an easy way to do this. */
if|if
condition|(
name|isalpha
argument_list|(
name|f
index|[
literal|0
index|]
argument_list|)
operator|&&
name|f
index|[
literal|1
index|]
operator|==
literal|':'
condition|)
return|return
operator|(
name|zdskspace
argument_list|(
name|toupper
argument_list|(
name|f
index|[
literal|0
index|]
argument_list|)
operator|-
literal|'A'
operator|+
literal|1
argument_list|)
operator|>=
name|n
operator|)
return|;
else|else
return|return
operator|(
name|zdskspace
argument_list|(
literal|0
argument_list|)
operator|>=
name|n
operator|)
return|;
else|#
directive|else
comment|/* In UNIX there is no good (and portable) way. */
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Always say OK. */
endif|#
directive|endif
comment|/* OS2 */
block|}
comment|/*  Z N E W N  --  Make a new name for the given file  */
comment|/*   Given the name, fn, of a file that already exists, this function builds a   new name of the form "<oldname>.~<n>~", where<oldname> is argument name   (fn), and<n> is a version number, one higher than any existing version   number for that file, up to 9999.  This format is consistent with that used   by GNU EMACS.  If the constructed name is too long for the system's maximum,   enough characters are truncated from the end of<fn> to allow the version   number to fit.  If no free version numbers exist between 1 and 9999, a   version number of "xxxx" is used.  Returns a pointer to the new name in   argument s. */
name|VOID
name|znewn
parameter_list|(
name|fn
parameter_list|,
name|s
parameter_list|)
name|char
modifier|*
name|fn
decl_stmt|,
decl|*
modifier|*
name|s
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|pdp11
define|#
directive|define
name|ZNEWNBL
value|63
comment|/* Name buffer length */
define|#
directive|define
name|ZNEWNMD
value|3
comment|/* Max digits for version number */
else|#
directive|else
define|#
directive|define
name|ZNEWNBL
value|255
define|#
directive|define
name|ZNEWNMD
value|4
endif|#
directive|endif
comment|/* pdp11 */
specifier|static
name|char
name|buf
index|[
name|ZNEWNBL
operator|+
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|bp
decl_stmt|,
modifier|*
name|xp
decl_stmt|,
modifier|*
name|yp
decl_stmt|;
ifdef|#
directive|ifdef
name|OS2
name|char
modifier|*
name|zp
decl_stmt|,
name|ch
decl_stmt|,
name|temp
index|[
literal|14
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* OS2 */
name|int
name|len
init|=
literal|0
decl_stmt|,
name|d
init|=
literal|0
decl_stmt|,
name|n
decl_stmt|,
name|t
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|,
name|power
init|=
literal|1
decl_stmt|;
name|int
name|max
init|=
name|MAXNAMLEN
decl_stmt|;
comment|/* Maximum name length */
if|if
condition|(
name|max
operator|<
literal|14
condition|)
name|max
operator|=
literal|14
expr_stmt|;
comment|/* Make it reasonable */
if|if
condition|(
name|max
operator|>
name|ZNEWNBL
condition|)
name|max
operator|=
name|ZNEWNBL
expr_stmt|;
name|bp
operator|=
name|buf
expr_stmt|;
comment|/* Buffer for building new name */
name|yp
operator|=
name|fn
expr_stmt|;
while|while
condition|(
operator|*
name|yp
condition|)
block|{
comment|/* Copy old name into buffer */
operator|*
name|bp
operator|++
operator|=
operator|*
name|yp
operator|++
expr_stmt|;
if|if
condition|(
name|len
operator|++
operator|>
name|ZNEWNBL
condition|)
break|break;
comment|/* ...up to buffer length */
block|}
operator|*
name|s
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|ZNEWNMD
operator|+
literal|1
condition|;
name|i
operator|++
control|)
block|{
comment|/* Version numbers up to 10**i - 1 */
name|power
operator|*=
literal|10
expr_stmt|;
comment|/* Next power of 10 */
name|j
operator|=
name|max
operator|-
name|len
expr_stmt|;
comment|/* Space left for version number */
name|k
operator|=
literal|3
operator|+
name|i
expr_stmt|;
comment|/* Space needed for it */
if|if
condition|(
name|j
operator|<
name|k
condition|)
block|{
comment|/* Make room if necessary */
name|len
operator|-=
operator|(
name|k
operator|-
name|j
operator|)
expr_stmt|;
comment|/* Adjust length of filename */
name|bp
operator|=
name|buf
operator|+
name|len
expr_stmt|;
comment|/* Point to new end */
block|}
operator|*
name|bp
operator|++
operator|=
literal|'*'
expr_stmt|;
comment|/* Put a star on the end (UNIX) */
operator|*
name|bp
operator|--
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate with null */
name|n
operator|=
name|zxpand
argument_list|(
name|buf
argument_list|)
expr_stmt|;
comment|/* Expand the resulting wild name */
comment|/* n is the number of matches */
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
block|{
comment|/* Find any existing name.~n~ files */
name|xp
operator|=
operator|*
name|mtchptr
operator|++
expr_stmt|;
comment|/* Point at matching name */
name|xp
operator|+=
name|len
expr_stmt|;
comment|/* Look for .~<n>~ at the end of it */
if|if
condition|(
operator|*
name|xp
operator|==
literal|'.'
operator|&&
operator|*
operator|(
name|xp
operator|+
literal|1
operator|)
operator|==
literal|'~'
condition|)
block|{
comment|/* Has a version number */
name|t
operator|=
name|atoi
argument_list|(
name|xp
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|/* Get it */
if|if
condition|(
name|t
operator|>
name|d
condition|)
name|d
operator|=
name|t
expr_stmt|;
comment|/* Save d = highest version number */
block|}
block|}
if|if
condition|(
name|d
operator|<
name|power
operator|-
literal|1
condition|)
block|{
comment|/* Less than maximum possible? */
name|sprintf
argument_list|(
name|bp
argument_list|,
literal|".~%d~"
argument_list|,
name|d
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* Yes, make "name.~<d+1>~" */
operator|*
name|s
operator|=
name|buf
expr_stmt|;
comment|/* Point to new name */
break|break;
comment|/* Done, return it */
block|}
block|}
if|if
condition|(
operator|*
name|s
operator|==
name|NULL
condition|)
block|{
name|sprintf
argument_list|(
name|bp
argument_list|,
literal|".~xxxx~"
argument_list|)
expr_stmt|;
comment|/* Too many, use xxxx. */
operator|*
name|s
operator|=
name|buf
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
name|IsFileNameValid
argument_list|(
name|buf
argument_list|)
condition|)
return|return;
comment|/* HPFS */
comment|/* otherwise make FAT 8.3 name */
name|xp
operator|=
name|bp
operator|=
name|buf
expr_stmt|;
name|yp
operator|=
name|fn
expr_stmt|;
while|while
condition|(
operator|*
name|yp
condition|)
block|{
comment|/* Copy name into buf */
name|ch
operator|=
operator|*
name|bp
operator|++
operator|=
operator|*
name|yp
operator|++
expr_stmt|;
if|if
condition|(
name|ISDIRSEP
argument_list|(
name|ch
argument_list|)
operator|||
operator|(
name|ch
operator|==
literal|':'
operator|)
condition|)
name|xp
operator|=
name|bp
expr_stmt|;
block|}
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
name|yp
operator|=
name|xp
expr_stmt|;
name|i
operator|=
literal|1
expr_stmt|;
while|while
condition|(
operator|*
name|yp
operator|&&
operator|(
operator|*
name|yp
operator|!=
literal|'.'
operator|)
condition|)
block|{
name|yp
operator|++
expr_stmt|;
if|if
condition|(
operator|++
name|i
operator|<=
literal|6
condition|)
name|zp
operator|=
name|yp
expr_stmt|;
block|}
comment|/* zp points to 6th character in name, or yp, whichever occurs first. */
name|strcpy
argument_list|(
name|temp
argument_list|,
name|yp
argument_list|)
expr_stmt|;
comment|/* Copy extension, if any */
while|while
condition|(
name|zp
operator|!=
name|xp
operator|+
literal|8
condition|)
block|{
if|if
condition|(
name|zp
operator|<
name|xp
operator|+
literal|5
condition|)
operator|*
name|zp
operator|++
operator|=
literal|'0'
expr_stmt|;
else|else
operator|*
name|zp
operator|++
operator|=
literal|'?'
expr_stmt|;
comment|/* Pad out with wild cards */
block|}
name|strcpy
argument_list|(
name|zp
argument_list|,
name|temp
argument_list|)
expr_stmt|;
comment|/* Get the extension back */
name|n
operator|=
name|zxpand
argument_list|(
name|buf
argument_list|)
expr_stmt|;
comment|/* Expand the resulting wild name */
name|d
operator|=
literal|0
expr_stmt|;
comment|/* Index number */
while|while
condition|(
name|znext
argument_list|(
name|temp
argument_list|)
condition|)
block|{
name|i
operator|=
name|atoi
argument_list|(
name|temp
operator|+
literal|5
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>
name|d
condition|)
name|d
operator|=
name|i
expr_stmt|;
block|}
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|"%03d"
argument_list|,
name|d
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* get the number into a string */
name|memcpy
argument_list|(
name|xp
operator|+
literal|5
argument_list|,
name|temp
argument_list|,
literal|3
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
return|return;
block|}
comment|/*  Z R E N A M E  --  Rename a file  */
comment|/*  Note, link() and unlink() are used because rename() is not available  */
comment|/*  in some versions of UNIX.   */
comment|/*  Call with old and new names */
comment|/*  Returns 0 on success, -1 on failure. */
name|int
name|zrename
parameter_list|(
name|old
parameter_list|,
name|new
parameter_list|)
name|char
modifier|*
name|old
decl_stmt|,
decl|*
name|new
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|OS2
return|return
name|rename
argument_list|(
name|old
argument_list|,
name|new
argument_list|)
return|;
else|#
directive|else
if|if
condition|(
name|link
argument_list|(
name|old
argument_list|,
name|new
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Make a link with the new name. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zrename link fails, errno"
argument_list|,
name|old
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
if|if
condition|(
name|unlink
argument_list|(
name|old
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Unlink the old name. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zrename unlink fails, errno"
argument_list|,
name|old
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
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* OS2 */
block|}
comment|/*  Z S A T T R */
comment|/*  Fills in a Kermit file attribute structure for the file which is to be sent.  Returns 0 on success with the structure filled in, or -1 on failure.  If any string member is null, then it should be ignored.  If any numeric member is -1, then it should be ignored. */
name|int
name|zsattr
parameter_list|(
name|xx
parameter_list|)
name|struct
name|zattr
modifier|*
name|xx
decl_stmt|;
block|{
name|long
name|k
decl_stmt|;
name|k
operator|=
name|iflen
operator|%
literal|1024L
expr_stmt|;
comment|/* File length in K */
if|if
condition|(
name|k
operator|!=
literal|0L
condition|)
name|k
operator|=
literal|1L
expr_stmt|;
name|xx
operator|->
name|lengthk
operator|=
operator|(
name|iflen
operator|/
literal|1024L
operator|)
operator|+
name|k
expr_stmt|;
name|xx
operator|->
name|type
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* File type can't be filled in here */
name|xx
operator|->
name|type
operator|.
name|val
operator|=
literal|""
expr_stmt|;
if|if
condition|(
operator|*
name|nambuf
condition|)
block|{
name|xx
operator|->
name|date
operator|.
name|val
operator|=
name|zfcdat
argument_list|(
name|nambuf
argument_list|)
expr_stmt|;
comment|/* File creation date */
name|xx
operator|->
name|date
operator|.
name|len
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|xx
operator|->
name|date
operator|.
name|val
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|xx
operator|->
name|date
operator|.
name|len
operator|=
literal|0
expr_stmt|;
name|xx
operator|->
name|date
operator|.
name|val
operator|=
literal|""
expr_stmt|;
block|}
name|xx
operator|->
name|creator
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* File creator */
name|xx
operator|->
name|creator
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|account
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* File account */
name|xx
operator|->
name|account
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|area
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* File area */
name|xx
operator|->
name|area
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|passwd
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* Area password */
name|xx
operator|->
name|passwd
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|blksize
operator|=
operator|-
literal|1L
expr_stmt|;
comment|/* File blocksize */
name|xx
operator|->
name|access
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* File access */
name|xx
operator|->
name|access
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|encoding
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* Transfer syntax */
name|xx
operator|->
name|encoding
operator|.
name|val
operator|=
literal|0
expr_stmt|;
name|xx
operator|->
name|disp
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* Disposition upon arrival */
name|xx
operator|->
name|disp
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|lprotect
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* Local protection */
name|xx
operator|->
name|lprotect
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|gprotect
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* Generic protection */
name|xx
operator|->
name|gprotect
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|systemid
operator|.
name|len
operator|=
literal|2
expr_stmt|;
comment|/* System ID */
name|xx
operator|->
name|systemid
operator|.
name|val
operator|=
literal|"U1"
expr_stmt|;
name|xx
operator|->
name|recfm
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* Record format */
name|xx
operator|->
name|recfm
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|sysparam
operator|.
name|len
operator|=
literal|0
expr_stmt|;
comment|/* System-dependent parameters */
name|xx
operator|->
name|sysparam
operator|.
name|val
operator|=
literal|""
expr_stmt|;
name|xx
operator|->
name|length
operator|=
name|iflen
expr_stmt|;
comment|/* Length */
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Z F C D A T  --  Get file creation date */
comment|/*   Call with pointer to filename.   On success, returns pointer to creation date in yyyymmdd hh:mm:ss format.   On failure, returns pointer to null string. */
specifier|static
name|char
name|datbuf
index|[
literal|40
index|]
decl_stmt|;
comment|/* static */
comment|/* (===OS2 change===) */
name|char
modifier|*
name|zfcdat
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|TIMESTAMP
name|struct
name|stat
name|buffer
decl_stmt|;
name|struct
name|tm
modifier|*
name|time_stamp
decl_stmt|,
modifier|*
name|localtime
argument_list|()
decl_stmt|;
name|int
name|yy
decl_stmt|,
name|ss
decl_stmt|;
name|datbuf
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|name
argument_list|,
operator|&
name|buffer
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zfcdat stat failed"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|""
operator|)
return|;
block|}
name|time_stamp
operator|=
name|localtime
argument_list|(
operator|&
operator|(
name|buffer
operator|.
name|st_mtime
operator|)
argument_list|)
expr_stmt|;
name|yy
operator|=
name|time_stamp
operator|->
name|tm_year
expr_stmt|;
if|if
condition|(
name|yy
operator|<
literal|100
condition|)
comment|/* In case it returns 2-digit year? */
name|yy
operator|+=
literal|1900
expr_stmt|;
if|if
condition|(
name|yy
operator|<
literal|0
operator|||
name|yy
operator|>
literal|9999
condition|)
block|{
comment|/* Make sure year is ok */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zfcdat date failed"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|""
operator|)
return|;
block|}
if|if
condition|(
name|time_stamp
operator|->
name|tm_mon
operator|<
literal|0
operator|||
name|time_stamp
operator|->
name|tm_mon
operator|>
literal|11
condition|)
return|return
operator|(
literal|""
operator|)
return|;
if|if
condition|(
name|time_stamp
operator|->
name|tm_mday
operator|<
literal|0
operator|||
name|time_stamp
operator|->
name|tm_mday
operator|>
literal|31
condition|)
return|return
operator|(
literal|""
operator|)
return|;
if|if
condition|(
name|time_stamp
operator|->
name|tm_hour
operator|<
literal|0
operator|||
name|time_stamp
operator|->
name|tm_hour
operator|>
literal|23
condition|)
return|return
operator|(
literal|""
operator|)
return|;
if|if
condition|(
name|time_stamp
operator|->
name|tm_min
operator|<
literal|0
operator|||
name|time_stamp
operator|->
name|tm_min
operator|>
literal|59
condition|)
return|return
operator|(
literal|""
operator|)
return|;
name|ss
operator|=
name|time_stamp
operator|->
name|tm_sec
expr_stmt|;
comment|/* Seconds */
if|if
condition|(
name|ss
operator|<
literal|0
operator|||
name|ss
operator|>
literal|59
condition|)
comment|/* Some systems give a BIG number */
name|ss
operator|=
literal|0
expr_stmt|;
name|sprintf
argument_list|(
name|datbuf
argument_list|,
ifdef|#
directive|ifdef
name|pdp11
comment|/* For some reason, 2.1x BSD sprintf gets the last field wrong. */
literal|"%04d%02d%02d %02d:%02d:00"
argument_list|,
else|#
directive|else
literal|"%04d%02d%02d %02d:%02d:%02d"
argument_list|,
endif|#
directive|endif
comment|/* pdp11 */
name|yy
argument_list|,
name|time_stamp
operator|->
name|tm_mon
operator|+
literal|1
argument_list|,
name|time_stamp
operator|->
name|tm_mday
argument_list|,
name|time_stamp
operator|->
name|tm_hour
argument_list|,
name|time_stamp
operator|->
name|tm_min
ifndef|#
directive|ifndef
name|pdp11
argument_list|,
name|ss
endif|#
directive|endif
comment|/* pdp11 */
argument_list|)
expr_stmt|;
name|yy
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|datbuf
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zfcdat"
argument_list|,
name|datbuf
argument_list|,
name|yy
argument_list|)
expr_stmt|;
if|if
condition|(
name|yy
operator|>
literal|17
condition|)
name|datbuf
index|[
literal|17
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|datbuf
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|""
operator|)
return|;
endif|#
directive|endif
comment|/* TIMESTAMP */
block|}
comment|/* Z S T I M E  --  Set creation date for incoming file */
comment|/*  Call with:  f  = pointer to name of existing file.  yy = pointer to a Kermit file attribute structure in which yy->date.val       is a date of the form yyyymmdd hh:mm:ss, e.g. 19900208 13:00:00.  x  = is a function code: 0 means to set the file's creation date as given.       1 means compare the given date with the file creation date.  Returns:  -1 on any kind of error.   0 if x is 0 and the file date was set successfully.   0 if x is 1 and date from attribute structure<= file creation date.   1 if x is 1 and date from attribute structure> file creation date. */
name|int
name|zstime
parameter_list|(
name|f
parameter_list|,
name|yy
parameter_list|,
name|x
parameter_list|)
name|char
modifier|*
name|f
decl_stmt|;
name|struct
name|zattr
modifier|*
name|yy
decl_stmt|;
name|int
name|x
decl_stmt|;
block|{
name|int
name|r
init|=
operator|-
literal|1
decl_stmt|;
comment|/* return code */
comment|/*   It is ifdef'd TIMESTAMP because it might not work on V7. bk@kullmar.se. */
ifdef|#
directive|ifdef
name|TIMESTAMP
comment|/*   To do: adapt code from OS-9 Kermit's ck9fio.c zstime function, which   is more flexible, allowing [yy]yymmdd[ hh:mm[:ss]]. */
ifndef|#
directive|ifndef
name|OS2
specifier|extern
name|int
name|ftime
argument_list|()
decl_stmt|,
name|stat
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|BSD44
specifier|extern
name|int
name|utimes
parameter_list|()
function_decl|;
else|#
directive|else
specifier|extern
name|int
name|utime
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* BSD44 */
comment|/* at least, the declarations for int functions are not needed anyway */
specifier|extern
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
comment|/* and this should have been declared always through a header file */
endif|#
directive|endif
comment|/* OS2 */
name|long
name|tm
decl_stmt|,
name|days
decl_stmt|;
name|int
name|i
decl_stmt|,
name|n
decl_stmt|,
name|isleapyear
decl_stmt|;
comment|/*       J  F  M  A   M   J   J   A   S   O   N   D   */
comment|/*      31 28 31 30  31  30  31  31  30  31  30  31   */
specifier|static
name|int
name|monthdays
index|[
literal|13
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|31
block|,
literal|59
block|,
literal|90
block|,
literal|120
block|,
literal|151
block|,
literal|181
block|,
literal|212
block|,
literal|243
block|,
literal|273
block|,
literal|304
block|,
literal|334
block|}
decl_stmt|;
name|char
name|s
index|[
literal|5
index|]
decl_stmt|;
name|struct
name|stat
name|sb
decl_stmt|;
ifdef|#
directive|ifdef
name|BSD44
name|struct
name|timeval
name|tp
index|[
literal|2
index|]
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|OS2
name|struct
name|utimbuf
name|tp
decl_stmt|;
ifdef|#
directive|ifdef
name|__EMX__
name|long
name|timezone
decl_stmt|;
name|struct
name|timeb
name|tbp
decl_stmt|;
endif|#
directive|endif
comment|/* __EMX__ */
else|#
directive|else
ifdef|#
directive|ifdef
name|V7
struct|struct
name|utimbuf
block|{
name|time_t
name|timep
index|[
literal|2
index|]
decl_stmt|;
comment|/* New access and modificaton time */
block|}
name|tp
struct|;
name|char
modifier|*
name|tz
decl_stmt|;
name|long
name|timezone
decl_stmt|;
comment|/* In case timezone not defined in .h file */
else|#
directive|else
ifdef|#
directive|ifdef
name|SYSUTIMEH
name|struct
name|utimbuf
name|tp
decl_stmt|;
else|#
directive|else
struct|struct
name|utimbuf
block|{
name|time_t
name|atime
decl_stmt|;
comment|/* New access time */
name|time_t
name|mtime
decl_stmt|;
comment|/* New modification time */
block|}
name|tp
struct|;
endif|#
directive|endif
comment|/* SYSUTIMEH */
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* BSD44 */
ifdef|#
directive|ifdef
name|ANYBSD
name|long
name|timezone
decl_stmt|;
specifier|static
name|struct
name|timeb
name|tbp
decl_stmt|;
endif|#
directive|endif
comment|/* ANYBSD */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zstime"
argument_list|,
name|f
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|yy
operator|->
name|date
operator|.
name|len
operator|==
literal|0
operator|)
operator|||
operator|(
name|yy
operator|->
name|date
operator|.
name|len
operator|!=
literal|17
operator|)
operator|||
operator|(
name|yy
operator|->
name|date
operator|.
name|val
index|[
literal|8
index|]
operator|!=
literal|' '
operator|)
operator|||
operator|(
name|yy
operator|->
name|date
operator|.
name|val
index|[
literal|11
index|]
operator|!=
literal|':'
operator|)
operator|||
operator|(
name|yy
operator|->
name|date
operator|.
name|val
index|[
literal|14
index|]
operator|!=
literal|':'
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"Bad creation date "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
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
name|F111
argument_list|,
literal|"zstime date check 1"
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|isdigit
argument_list|(
name|yy
operator|->
name|date
operator|.
name|val
index|[
name|i
index|]
argument_list|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"Bad creation date "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
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
name|F111
argument_list|,
literal|"zstime date check 2"
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
for|for
control|(
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|+=
literal|3
control|)
block|{
if|if
condition|(
operator|(
operator|!
name|isdigit
argument_list|(
name|yy
operator|->
name|date
operator|.
name|val
index|[
name|i
index|]
argument_list|)
operator|)
operator|||
operator|(
operator|!
name|isdigit
argument_list|(
name|yy
operator|->
name|date
operator|.
name|val
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"Bad creation date "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
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
name|F111
argument_list|,
literal|"zstime date check 3"
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ANYBSD
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ztime BSD calling ftime"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ftime
argument_list|(
operator|&
name|tbp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ztime BSD back from ftime"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|timezone
operator|=
name|tbp
operator|.
name|timezone
operator|*
literal|60L
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ztime BSD timezone"
argument_list|,
literal|""
argument_list|,
name|timezone
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|OS2
ifdef|#
directive|ifdef
name|__EMX__
name|ftime
argument_list|(
operator|&
name|tbp
argument_list|)
expr_stmt|;
name|timezone
operator|=
name|tbp
operator|.
name|timezone
operator|*
literal|60L
expr_stmt|;
endif|#
directive|endif
comment|/* __EMX__ */
endif|#
directive|endif
comment|/* OS2 */
ifdef|#
directive|ifdef
name|ATTSV
name|tzset
argument_list|()
expr_stmt|;
comment|/* Set `timezone'. */
endif|#
directive|endif
comment|/* ATTSV */
ifdef|#
directive|ifdef
name|V7
if|if
condition|(
operator|(
name|tz
operator|=
name|getenv
argument_list|(
literal|"TZ"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|timezone
operator|=
literal|0
expr_stmt|;
comment|/* UTC/GMT */
else|else
name|timezone
operator|=
name|atoi
argument_list|(
operator|&
name|tz
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
comment|/* Set 'timezone'. */
name|timezone
operator|*=
literal|60L
expr_stmt|;
endif|#
directive|endif
name|debug
argument_list|(
name|F100
argument_list|,
literal|"zstime so far so good"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|s
index|[
literal|4
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
name|i
operator|++
control|)
comment|/* Fix the year */
name|s
index|[
name|i
index|]
operator|=
name|yy
operator|->
name|date
operator|.
name|val
index|[
name|i
index|]
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zstime year"
argument_list|,
name|s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|n
operator|=
name|atoi
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zstime year"
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
comment|/* Previous year's leap days. This won't work after year 2100. */
name|isleapyear
operator|=
operator|(
operator|(
name|n
operator|%
literal|4
operator|==
literal|0
operator|&&
name|n
operator|%
literal|100
operator|!=
literal|0
operator|)
operator|||
name|n
operator|%
literal|400
operator|==
literal|0
operator|)
expr_stmt|;
name|days
operator|=
call|(
name|long
call|)
argument_list|(
name|n
operator|-
literal|1970
argument_list|)
operator|*
literal|365
expr_stmt|;
name|days
operator|+=
operator|(
name|n
operator|-
literal|1968
operator|-
literal|1
operator|)
operator|/
literal|4
operator|-
operator|(
name|n
operator|-
literal|1900
operator|-
literal|1
operator|)
operator|/
literal|100
operator|+
operator|(
name|n
operator|-
literal|1600
operator|-
literal|1
operator|)
operator|/
literal|400
expr_stmt|;
name|s
index|[
literal|2
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|4
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|+=
literal|2
control|)
block|{
name|s
index|[
literal|0
index|]
operator|=
name|yy
operator|->
name|date
operator|.
name|val
index|[
name|i
index|]
expr_stmt|;
name|s
index|[
literal|1
index|]
operator|=
name|yy
operator|->
name|date
operator|.
name|val
index|[
name|i
operator|+
literal|1
index|]
expr_stmt|;
name|n
operator|=
name|atoi
argument_list|(
name|s
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|4
case|:
comment|/* MM: month */
if|if
condition|(
operator|(
name|n
operator|<
literal|1
operator|)
operator|||
operator|(
name|n
operator|>
literal|12
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zstime 4 bad date "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|days
operator|+=
name|monthdays
index|[
name|n
index|]
expr_stmt|;
if|if
condition|(
name|isleapyear
operator|&&
name|n
operator|>
literal|2
condition|)
operator|++
name|days
expr_stmt|;
continue|continue;
case|case
literal|6
case|:
comment|/* DD: day */
if|if
condition|(
operator|(
name|n
operator|<
literal|1
operator|)
operator|||
operator|(
name|n
operator|>
literal|31
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zstime 6 bad date "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|tm
operator|=
operator|(
name|days
operator|+
name|n
operator|-
literal|1
operator|)
operator|*
literal|24L
operator|*
literal|60L
operator|*
literal|60L
expr_stmt|;
name|i
operator|++
expr_stmt|;
comment|/* Skip the space */
continue|continue;
case|case
literal|9
case|:
comment|/* hh: hour */
if|if
condition|(
operator|(
name|n
operator|<
literal|0
operator|)
operator|||
operator|(
name|n
operator|>
literal|23
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zstime 9 bad date "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|tm
operator|+=
name|n
operator|*
literal|60L
operator|*
literal|60L
expr_stmt|;
name|i
operator|++
expr_stmt|;
comment|/* Skip the colon */
continue|continue;
case|case
literal|12
case|:
comment|/* mm: minute */
if|if
condition|(
operator|(
name|n
operator|<
literal|0
operator|)
operator|||
operator|(
name|n
operator|>
literal|59
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zstime 12 bad date "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
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
name|ANYBSD
comment|/* Correct for time zone */
name|tm
operator|+=
name|timezone
expr_stmt|;
else|#
directive|else
ifndef|#
directive|ifndef
name|BSD44
comment|/* For now... */
ifdef|#
directive|ifdef
name|ultrix
name|tm
operator|+=
operator|(
name|long
operator|)
name|timezone
expr_stmt|;
else|#
directive|else
name|tm
operator|+=
name|timezone
expr_stmt|;
endif|#
directive|endif
comment|/* ultrix */
endif|#
directive|endif
comment|/* BSD44 */
endif|#
directive|endif
comment|/* ANYBSD */
name|tm
operator|+=
name|n
operator|*
literal|60L
expr_stmt|;
name|i
operator|++
expr_stmt|;
comment|/* Skip the colon */
continue|continue;
case|case
literal|15
case|:
comment|/* ss: second */
if|if
condition|(
operator|(
name|n
operator|<
literal|0
operator|)
operator|||
operator|(
name|n
operator|>
literal|59
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zstime 15 bad date "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|tm
operator|+=
name|n
expr_stmt|;
block|}
if|if
condition|(
name|localtime
argument_list|(
operator|&
name|tm
argument_list|)
operator|->
name|tm_isdst
condition|)
name|tm
operator|-=
literal|60L
operator|*
literal|60L
expr_stmt|;
comment|/* Adjust for daylight savings time */
block|}
name|debug
argument_list|(
name|F111
argument_list|,
literal|"A-pkt date ok "
argument_list|,
name|yy
operator|->
name|date
operator|.
name|val
argument_list|,
name|yy
operator|->
name|date
operator|.
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|f
argument_list|,
operator|&
name|sb
argument_list|)
condition|)
block|{
comment|/* Get the time for the file */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"Can't stat file:"
argument_list|,
name|f
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
ifdef|#
directive|ifdef
name|OS2
name|tp
operator|.
name|modtime
operator|=
name|tm
expr_stmt|;
comment|/* Set modif. time to creation date */
name|tp
operator|.
name|actime
operator|=
name|sb
operator|.
name|st_atime
expr_stmt|;
comment|/* Don't change the access time */
else|#
directive|else
ifdef|#
directive|ifdef
name|SYSUTIMEH
name|tp
operator|.
name|modtime
operator|=
name|tm
expr_stmt|;
comment|/* Set modif. time to creation date */
name|tp
operator|.
name|actime
operator|=
name|sb
operator|.
name|st_atime
expr_stmt|;
comment|/* Don't change the access time */
else|#
directive|else
ifdef|#
directive|ifdef
name|V7
name|tp
operator|.
name|timep
index|[
literal|0
index|]
operator|=
name|tm
expr_stmt|;
comment|/* Set modif. time to creation date */
name|tp
operator|.
name|timep
index|[
literal|1
index|]
operator|=
name|sb
operator|.
name|st_atime
expr_stmt|;
comment|/* Don't change the access time */
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD44
name|tp
index|[
literal|0
index|]
operator|.
name|tv_sec
operator|=
name|sb
operator|.
name|st_atime
expr_stmt|;
comment|/* Access time first */
name|tp
index|[
literal|1
index|]
operator|.
name|tv_sec
operator|=
name|tm
expr_stmt|;
comment|/* Update time second */
else|#
directive|else
name|tp
operator|.
name|mtime
operator|=
name|tm
expr_stmt|;
comment|/* Set modif. time to creation date */
name|tp
operator|.
name|atime
operator|=
name|sb
operator|.
name|st_atime
expr_stmt|;
comment|/* Don't change the access time */
endif|#
directive|endif
comment|/* BSD44 */
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* SYSUTIMEH */
endif|#
directive|endif
comment|/* OS2 */
switch|switch
condition|(
name|x
condition|)
block|{
comment|/* Execute desired function */
case|case
literal|0
case|:
comment|/* Set the creation date of the file */
if|if
condition|(
ifdef|#
directive|ifdef
name|BSD44
name|utimes
argument_list|(
argument|f
argument_list|,
argument|tp
argument_list|)
else|#
directive|else
name|utime
argument_list|(
name|f
argument_list|,
operator|&
name|tp
argument_list|)
endif|#
directive|endif
comment|/* BSD44 */
condition|)
block|{
comment|/* Fix modification time */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"Can't set modification time for file: "
argument_list|,
name|f
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|r
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"Modification time is set for file: "
argument_list|,
name|f
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|r
operator|=
literal|0
expr_stmt|;
block|}
break|break;
case|case
literal|1
case|:
comment|/* Compare the dates */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zstime compare"
argument_list|,
name|f
argument_list|,
name|sb
operator|.
name|st_atime
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zstime compare"
argument_list|,
literal|"packet"
argument_list|,
name|tm
argument_list|)
expr_stmt|;
name|r
operator|=
operator|(
name|sb
operator|.
name|st_atime
operator|<
name|tm
operator|)
condition|?
literal|0
else|:
literal|1
expr_stmt|;
break|break;
default|default:
comment|/* Error */
name|r
operator|=
operator|-
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* TIMESTAMP */
return|return
operator|(
name|r
operator|)
return|;
block|}
comment|/* Find initialization file. */
ifdef|#
directive|ifdef
name|NOTUSED
name|int
name|zkermini
parameter_list|()
block|{
comment|/*  nothing here for Unix.  This function added for benefit of VMS Kermit.  */
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* NOTUSED */
ifndef|#
directive|ifndef
name|NOFRILLS
name|int
name|zmail
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|f
decl_stmt|;
block|{
comment|/* Send file f as mail to address p */
comment|/*   Returns 0 on success    2 if mail delivered but temp file can't be deleted   -2 if mail can't be delivered   The UNIX version always returns 0 because it can't get a good return   code from zsyscmd. */
ifdef|#
directive|ifdef
name|BSD4
comment|/* The idea is to use /usr/ucb/mail, rather than regular mail, so that   */
comment|/* a subject line can be included with -s.  Since we can't depend on the */
comment|/* user's path, we use the convention that /usr/ucb/Mail = /usr/ucb/mail */
comment|/* and even if Mail has been moved to somewhere else, this should still  */
comment|/* find it...  The search could be made more reliable by actually using  */
comment|/* access() to see if /usr/ucb/Mail exists. */
comment|/* Should also make some check on zmbuf overflow... */
ifdef|#
directive|ifdef
name|OXOS
name|sprintf
argument_list|(
name|zmbuf
argument_list|,
literal|"mailx -s %c%s%c %s< %s"
argument_list|,
literal|'"'
argument_list|,
name|f
argument_list|,
literal|'"'
argument_list|,
name|p
argument_list|,
name|f
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|DGUX540
name|sprintf
argument_list|(
name|zmbuf
argument_list|,
literal|"mailx -s %c%s%c %s< %s"
argument_list|,
literal|'"'
argument_list|,
name|f
argument_list|,
literal|'"'
argument_list|,
name|p
argument_list|,
name|f
argument_list|)
expr_stmt|;
else|#
directive|else
name|sprintf
argument_list|(
name|zmbuf
argument_list|,
literal|"Mail -s %c%s%c %s< %s"
argument_list|,
literal|'"'
argument_list|,
name|f
argument_list|,
literal|'"'
argument_list|,
name|p
argument_list|,
name|f
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DGUX540 */
endif|#
directive|endif
comment|/* OXOS */
name|zsyscmd
argument_list|(
name|zmbuf
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|SVORPOSIX
name|sprintf
argument_list|(
name|zmbuf
argument_list|,
literal|"mail %s< %s"
argument_list|,
name|p
argument_list|,
name|f
argument_list|)
expr_stmt|;
name|zsyscmd
argument_list|(
name|zmbuf
argument_list|)
expr_stmt|;
else|#
directive|else
operator|*
name|zmbuf
operator|=
literal|'\0'
expr_stmt|;
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
endif|#
directive|endif
comment|/* NOFRILLS */
ifndef|#
directive|ifndef
name|NOFRILLS
name|int
name|zprint
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|f
decl_stmt|;
block|{
comment|/* Print file f with options p */
ifdef|#
directive|ifdef
name|OS2
name|sprintf
argument_list|(
name|zmbuf
argument_list|,
literal|"print %s %s"
argument_list|,
name|p
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Construct print command */
name|zsyscmd
argument_list|(
name|zmbuf
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|UNIX
ifdef|#
directive|ifdef
name|ANYBSD
comment|/* BSD uses lpr to spool */
ifdef|#
directive|ifdef
name|OXOS
comment|/* Except Olivetti... */
define|#
directive|define
name|SPOOLER
value|"lp"
else|#
directive|else
ifdef|#
directive|ifdef
name|DGUX540
comment|/* And DG/UX */
define|#
directive|define
name|SPOOLER
value|"lp"
else|#
directive|else
define|#
directive|define
name|SPOOLER
value|"lpr"
endif|#
directive|endif
comment|/* DGUX540 */
endif|#
directive|endif
comment|/* OXOS */
else|#
directive|else
comment|/* Sys V uses lp */
ifdef|#
directive|ifdef
name|TRS16
comment|/* except for Tandy-16/6000... */
define|#
directive|define
name|SPOOLER
value|"lpr"
else|#
directive|else
define|#
directive|define
name|SPOOLER
value|"lp"
endif|#
directive|endif
endif|#
directive|endif
comment|/*   Note use of standard input redirection.  In some systems, lp[r] runs   setuid to lp (or ...?), so if user has sent a file into a directory   that lp does not have read access to, it can't be printed unless it is   feed to lp[r] as standard input. */
name|sprintf
argument_list|(
name|zmbuf
argument_list|,
literal|"%s %s< %s"
argument_list|,
name|SPOOLER
argument_list|,
name|p
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Construct print command */
name|zsyscmd
argument_list|(
name|zmbuf
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Not UNIX */
operator|*
name|zmbuf
operator|=
literal|'\0'
expr_stmt|;
endif|#
directive|endif
comment|/* UNIX */
endif|#
directive|endif
comment|/* OS2 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* NOFRILLS */
comment|/*   Wildcard expansion functions.  C-Kermit used to insist on doing this itself   New code (version 5A, 1990-91) gives user option to ask UNIX to do it.   This lets users use the wildcard expansion features of their favorite shell.   Operation is slower because of the forking& piping, but flexibility is   greater and program is smaller.  For OS/2, C-Kermit still does this itself. */
specifier|static
name|char
name|scratch
index|[
name|MAXPATH
operator|+
literal|4
index|]
decl_stmt|;
comment|/* Used by both methods */
ifndef|#
directive|ifndef
name|OS2
specifier|static
name|int
name|oldmtchs
init|=
literal|0
decl_stmt|;
comment|/* Let shell (ls) expand them. */
ifdef|#
directive|ifdef
name|COMMENT
specifier|static
name|char
modifier|*
name|lscmd
init|=
literal|"/bin/ls -d"
decl_stmt|;
comment|/* Command to use. */
else|#
directive|else
specifier|static
name|char
modifier|*
name|lscmd
init|=
literal|"echo"
decl_stmt|;
comment|/* Command to use. */
endif|#
directive|endif
comment|/* COMMENT */
name|int
name|shxpand
argument_list|(
name|pat
argument_list|,
name|namlst
argument_list|,
name|len
argument_list|)
name|char
modifier|*
name|pat
decl_stmt|,
modifier|*
name|namlst
index|[]
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|char
modifier|*
name|fgbuf
init|=
name|NULL
decl_stmt|;
comment|/* Buffer for forming ls command */
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
comment|/* Workers */
name|int
name|i
decl_stmt|,
name|x
decl_stmt|,
name|retcode
decl_stmt|;
name|char
name|c
decl_stmt|;
comment|/* ... */
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|pat
argument_list|)
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|lscmd
argument_list|)
operator|+
literal|3
expr_stmt|;
comment|/* Length of ls command */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|oldmtchs
condition|;
name|i
operator|++
control|)
comment|/* Free previous file list */
name|free
argument_list|(
name|namlst
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|fgbuf
operator|=
name|malloc
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|/* Get buffer for command */
if|if
condition|(
operator|!
name|fgbuf
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Fail if cannot */
name|sprintf
argument_list|(
name|fgbuf
argument_list|,
literal|"%s %s"
argument_list|,
name|lscmd
argument_list|,
name|pat
argument_list|)
expr_stmt|;
comment|/* Form the command */
name|zxcmd
argument_list|(
name|ZIFILE
argument_list|,
name|fgbuf
argument_list|)
expr_stmt|;
comment|/* Start the command */
name|i
operator|=
literal|0
expr_stmt|;
comment|/* File counter */
name|p
operator|=
name|scratch
expr_stmt|;
comment|/* Point to scratch area */
name|retcode
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Assume failure */
while|while
condition|(
operator|(
name|x
operator|=
name|zminchar
argument_list|()
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
comment|/* Read characters from command */
name|c
operator|=
operator|(
name|char
operator|)
name|x
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|' '
operator|||
name|c
operator|==
literal|'\n'
condition|)
block|{
comment|/* Got newline or space? */
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
comment|/* Yes, terminate string */
name|p
operator|=
name|scratch
expr_stmt|;
comment|/* Point back to beginning */
if|if
condition|(
name|zchki
argument_list|(
name|p
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|/* Does file exist? */
continue|continue;
comment|/* No, continue */
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Yes, get length of name */
name|q
operator|=
name|malloc
argument_list|(
name|x
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* Allocate space for it */
if|if
condition|(
operator|!
name|q
condition|)
goto|goto
name|shxfin
goto|;
comment|/* Fail if space can't be obtained */
name|strcpy
argument_list|(
name|q
argument_list|,
name|scratch
argument_list|)
expr_stmt|;
comment|/* Copy name to space */
name|namlst
index|[
name|i
operator|++
index|]
operator|=
name|q
expr_stmt|;
comment|/* Copy pointer to name into array */
if|if
condition|(
name|i
operator|>
name|len
condition|)
goto|goto
name|shxfin
goto|;
comment|/* Fail if too many */
block|}
else|else
block|{
comment|/* Regular character */
operator|*
name|p
operator|++
operator|=
name|c
expr_stmt|;
comment|/* Copy it into scratch area */
block|}
block|}
name|retcode
operator|=
name|i
expr_stmt|;
comment|/* Return number of matching files */
name|shxfin
label|:
comment|/* Common exit point */
name|free
argument_list|(
name|fgbuf
argument_list|)
expr_stmt|;
comment|/* Free command buffer */
name|zclosf
argument_list|(
name|ZIFILE
argument_list|)
expr_stmt|;
comment|/* Delete the command fork. */
name|oldmtchs
operator|=
name|i
expr_stmt|;
comment|/* Remember how many files */
return|return
operator|(
name|retcode
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* OS2 */
comment|/* Directory Functions for Unix, written by Jeff Damens, CUCCA, 1984. */
comment|/* Define the size of the string space for filename expansion. */
ifndef|#
directive|ifndef
name|DYNAMIC
ifdef|#
directive|ifdef
name|PROVX1
define|#
directive|define
name|SSPACE
value|500
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD29
define|#
directive|define
name|SSPACE
value|500
else|#
directive|else
ifdef|#
directive|ifdef
name|pdp11
define|#
directive|define
name|SSPACE
value|500
else|#
directive|else
ifdef|#
directive|ifdef
name|aegis
define|#
directive|define
name|SSPACE
value|10000
comment|/* size of string-generating buffer */
specifier|static
name|char
name|bslash
decl_stmt|;
comment|/* backslash character if active */
else|#
directive|else
comment|/* Default static buffer size */
define|#
directive|define
name|SSPACE
value|2000
comment|/* size of string-generating buffer */
endif|#
directive|endif
comment|/* aegis */
endif|#
directive|endif
comment|/* pdp11 */
endif|#
directive|endif
comment|/* BSD29 */
endif|#
directive|endif
comment|/* PROVX1 */
specifier|static
name|char
name|sspace
index|[
name|SSPACE
index|]
decl_stmt|;
comment|/* buffer for generating filenames */
else|#
directive|else
comment|/* DYNAMIC */
define|#
directive|define
name|SSPACE
value|10000
specifier|static
name|char
modifier|*
name|sspace
init|=
operator|(
name|char
operator|*
operator|)
literal|0
decl_stmt|;
endif|#
directive|endif
comment|/* DYNAMIC */
specifier|static
name|int
name|ssplen
init|=
name|SSPACE
decl_stmt|;
comment|/* length of string space buffer */
specifier|static
name|char
modifier|*
name|freeptr
decl_stmt|,
modifier|*
modifier|*
name|resptr
decl_stmt|;
comment|/* copies of caller's arguments */
specifier|static
name|int
name|remlen
decl_stmt|;
comment|/* remaining length in caller's array*/
specifier|static
name|int
name|numfnd
decl_stmt|;
comment|/* number of matches found */
comment|/*  * splitpath:  *  takes a string and splits the slash-separated portions into  *  a list of path structures.  Returns the head of the list.  The  *  structures are allocated by malloc, so they must be freed.  *  Splitpath is used internally by the filename generator.  *  * Input: A string.  * Returns: A linked list of the slash-separated segments of the input.  */
name|struct
name|path
modifier|*
name|splitpath
parameter_list|(
name|p
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
block|{
name|struct
name|path
modifier|*
name|head
decl_stmt|,
modifier|*
name|cur
decl_stmt|,
modifier|*
name|prv
decl_stmt|;
name|int
name|i
decl_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"splitpath"
argument_list|,
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|head
operator|=
name|prv
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|ISDIRSEP
argument_list|(
operator|*
name|p
argument_list|)
condition|)
name|p
operator|++
expr_stmt|;
comment|/* skip leading slash */
while|while
condition|(
operator|*
name|p
operator|!=
literal|'\0'
condition|)
block|{
name|cur
operator|=
operator|(
expr|struct
name|path
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|path
argument_list|)
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"splitpath malloc"
argument_list|,
literal|""
argument_list|,
name|cur
argument_list|)
expr_stmt|;
if|if
condition|(
name|cur
operator|==
name|NULL
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"splitpath malloc failure"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
expr|struct
name|path
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
name|cur
operator|->
name|fwd
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|head
operator|==
name|NULL
condition|)
name|head
operator|=
name|cur
expr_stmt|;
else|else
name|prv
operator|->
name|fwd
operator|=
name|cur
expr_stmt|;
comment|/* link into chain */
name|prv
operator|=
name|cur
expr_stmt|;
ifdef|#
directive|ifdef
name|aegis
comment|/* treat backslash as "../" */
if|if
condition|(
name|bslash
operator|&&
operator|*
name|p
operator|==
name|bslash
condition|)
block|{
name|strcpy
argument_list|(
name|cur
operator|->
name|npart
argument_list|,
literal|".."
argument_list|)
expr_stmt|;
operator|++
name|p
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXNAMLEN
operator|&&
operator|*
name|p
operator|&&
operator|*
name|p
operator|!=
literal|'/'
operator|&&
operator|*
name|p
operator|!=
name|bslash
condition|;
name|i
operator|++
control|)
name|cur
operator|->
name|npart
index|[
name|i
index|]
operator|=
operator|*
name|p
operator|++
expr_stmt|;
name|cur
operator|->
name|npart
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* end this segment */
if|if
condition|(
name|i
operator|>=
name|MAXNAMLEN
condition|)
while|while
condition|(
operator|*
name|p
operator|&&
operator|*
name|p
operator|!=
literal|'/'
operator|&&
operator|*
name|p
operator|!=
name|bslash
condition|)
name|p
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|p
operator|==
literal|'/'
condition|)
name|p
operator|++
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|OS2
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXNAMLEN
operator|&&
operator|!
name|ISDIRSEP
argument_list|(
operator|*
name|p
argument_list|)
operator|&&
operator|*
name|p
operator|!=
literal|':'
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|;
name|i
operator|++
control|)
name|cur
operator|->
name|npart
index|[
name|i
index|]
operator|=
operator|*
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|':'
condition|)
block|{
name|cur
operator|->
name|npart
index|[
name|i
operator|++
index|]
operator|=
operator|*
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|!
name|ISDIRSEP
argument_list|(
operator|*
name|p
argument_list|)
condition|)
name|cur
operator|->
name|npart
index|[
name|i
operator|++
index|]
operator|=
literal|'.'
expr_stmt|;
block|}
else|#
directive|else
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXNAMLEN
operator|&&
operator|!
name|ISDIRSEP
argument_list|(
operator|*
name|p
argument_list|)
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|;
name|i
operator|++
control|)
block|{
name|cur
operator|->
name|npart
index|[
name|i
index|]
operator|=
operator|*
name|p
operator|++
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* OS2 */
name|cur
operator|->
name|npart
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* end this segment */
if|if
condition|(
name|i
operator|>=
name|MAXNAMLEN
condition|)
while|while
condition|(
operator|!
name|ISDIRSEP
argument_list|(
operator|*
name|p
argument_list|)
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|p
operator|++
expr_stmt|;
if|if
condition|(
name|ISDIRSEP
argument_list|(
operator|*
name|p
argument_list|)
condition|)
name|p
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* aegis */
block|}
return|return
operator|(
name|head
operator|)
return|;
block|}
comment|/*  * fgen:  *  This is the actual name generator.  It is passed a string,  *  possibly containing wildcards, and an array of character pointers.  *  It finds all the matching filenames and stores them into the array.  *  The returned strings are allocated from a static buffer local to  *  this module (so the caller doesn't have to worry about deallocating  *  them); this means that successive calls to fgen will wipe out  *  the results of previous calls.  This isn't a problem here  *  because we process one wildcard string at a time.  *  * Input: a wildcard string, an array to write names to, the  *        length of the array.  * Returns: the number of matches.  The array is filled with filenames  *          that matched the pattern.  If there wasn't enough room in the  *	    array, -1 is returned.  * Originally by: Jeff Damens, CUCCA, 1984.  Many changes since then.  */
specifier|static
name|int
name|fgen
argument_list|(
name|pat
argument_list|,
name|resarry
argument_list|,
name|len
argument_list|)
name|char
modifier|*
name|pat
decl_stmt|,
modifier|*
name|resarry
index|[]
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|struct
name|path
modifier|*
name|head
decl_stmt|;
name|char
modifier|*
name|sptr
decl_stmt|;
ifdef|#
directive|ifdef
name|aegis
name|char
modifier|*
name|namechars
decl_stmt|;
name|int
name|tilde
init|=
literal|0
decl_stmt|,
name|bquote
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|namechars
operator|=
name|getenv
argument_list|(
literal|"NAMECHARS"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|xindex
argument_list|(
name|namechars
argument_list|,
literal|'~'
argument_list|)
operator|!=
name|NULL
condition|)
name|tilde
operator|=
literal|'~'
expr_stmt|;
if|if
condition|(
name|xindex
argument_list|(
name|namechars
argument_list|,
literal|'\\'
argument_list|)
operator|!=
name|NULL
condition|)
name|bslash
operator|=
literal|'\\'
expr_stmt|;
if|if
condition|(
name|xindex
argument_list|(
name|namechars
argument_list|,
literal|'`'
argument_list|)
operator|!=
name|NULL
condition|)
name|bquote
operator|=
literal|'`'
expr_stmt|;
block|}
else|else
block|{
name|tilde
operator|=
literal|'~'
expr_stmt|;
name|bslash
operator|=
literal|'\\'
expr_stmt|;
name|bquote
operator|=
literal|'`'
expr_stmt|;
block|}
name|sptr
operator|=
name|scratch
expr_stmt|;
comment|/* copy "`node_data", etc. anchors */
if|if
condition|(
name|bquote
operator|&&
operator|*
name|pat
operator|==
name|bquote
condition|)
while|while
condition|(
operator|*
name|pat
operator|&&
operator|*
name|pat
operator|!=
literal|'/'
operator|&&
operator|*
name|pat
operator|!=
name|bslash
condition|)
operator|*
name|sptr
operator|++
operator|=
operator|*
name|pat
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
name|tilde
operator|&&
operator|*
name|pat
operator|==
name|tilde
condition|)
operator|*
name|sptr
operator|++
operator|=
operator|*
name|pat
operator|++
expr_stmt|;
while|while
condition|(
operator|*
name|pat
operator|==
literal|'/'
condition|)
operator|*
name|sptr
operator|++
operator|=
operator|*
name|pat
operator|++
expr_stmt|;
if|if
condition|(
name|sptr
operator|==
name|scratch
condition|)
block|{
name|strcpy
argument_list|(
name|scratch
argument_list|,
literal|"./"
argument_list|)
expr_stmt|;
name|sptr
operator|=
name|scratch
operator|+
literal|2
expr_stmt|;
block|}
comment|/* init buffer correctly */
if|if
condition|(
operator|!
operator|(
name|head
operator|=
name|splitpath
argument_list|(
name|pat
argument_list|)
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|#
directive|else
comment|/* not aegis */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"fgen pat"
argument_list|,
name|pat
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|head
operator|=
name|splitpath
argument_list|(
name|pat
argument_list|)
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|sptr
operator|=
name|scratch
expr_stmt|;
if|if
condition|(
operator|!
name|ISDIRSEP
argument_list|(
operator|*
name|pat
argument_list|)
condition|)
operator|*
name|sptr
operator|++
operator|=
literal|'.'
expr_stmt|;
comment|/* init buffer correctly */
operator|*
name|sptr
operator|++
operator|=
name|DIRSEP
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
name|isalpha
argument_list|(
name|pat
index|[
literal|0
index|]
argument_list|)
operator|&&
name|pat
index|[
literal|1
index|]
operator|==
literal|':'
condition|)
name|sptr
operator|=
name|scratch
expr_stmt|;
comment|/* reset in case of leading drive: */
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* aegis */
name|numfnd
operator|=
literal|0
expr_stmt|;
comment|/* none found yet */
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
operator|!
name|sspace
condition|)
block|{
comment|/* Need to allocate string space? */
while|while
condition|(
name|ssplen
operator|>
literal|50
condition|)
block|{
if|if
condition|(
operator|(
name|sspace
operator|=
name|malloc
argument_list|(
name|ssplen
operator|+
literal|2
argument_list|)
operator|)
condition|)
block|{
comment|/* Got it. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"fgen string space"
argument_list|,
literal|""
argument_list|,
name|ssplen
argument_list|)
expr_stmt|;
break|break;
block|}
name|ssplen
operator|=
operator|(
name|ssplen
operator|/
literal|2
operator|)
operator|+
operator|(
name|ssplen
operator|/
literal|4
operator|)
expr_stmt|;
comment|/* Didn't, reduce by 3/4 */
block|}
if|if
condition|(
name|ssplen
operator|<=
literal|50
condition|)
block|{
comment|/* Did we get it? */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"fgen can't malloc string space\n"
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
endif|#
directive|endif
comment|/* DYNAMIC */
name|freeptr
operator|=
name|sspace
expr_stmt|;
comment|/* this is where matches are copied */
name|resptr
operator|=
name|resarry
expr_stmt|;
comment|/* static copies of these so */
name|remlen
operator|=
name|len
expr_stmt|;
comment|/* recursive calls can alter them */
name|traverse
argument_list|(
name|head
argument_list|,
name|scratch
argument_list|,
name|sptr
argument_list|)
expr_stmt|;
comment|/* go walk the directory tree */
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   This code, circa 1984, has never worked right - it references the head   pointer after it has already been freed.  Lord knows what might have been   happening because of this.  Thanks to Steve Walton for finding& fixing   this bug. */
for|for
control|(
init|;
name|head
operator|!=
name|NULL
condition|;
name|head
operator|=
name|head
operator|->
name|fwd
control|)
name|free
argument_list|(
name|head
argument_list|)
expr_stmt|;
comment|/* return the path segments */
else|#
directive|else
while|while
condition|(
name|head
operator|!=
name|NULL
condition|)
block|{
name|struct
name|path
modifier|*
name|next
init|=
name|head
operator|->
name|fwd
decl_stmt|;
name|free
argument_list|(
name|head
argument_list|)
expr_stmt|;
name|head
operator|=
name|next
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* COMMENT */
return|return
operator|(
name|numfnd
operator|)
return|;
comment|/* and return the number of matches */
block|}
comment|/* traverse:  *  Walks the directory tree looking for matches to its arguments.  *  The algorithm is, briefly:  *   If the current pattern segment contains no wildcards, that  *   segment is added to what we already have.  If the name so far  *   exists, we call ourselves recursively with the next segment  *   in the pattern string; otherwise, we just return.  *  *   If the current pattern segment contains wildcards, we open the name  *   we've accumulated so far (assuming it is really a directory), then read  *   each filename in it, and, if it matches the wildcard pattern segment, add  *   that filename to what we have so far and call ourselves recursively on the  *   next segment.  *  *   Finally, when no more pattern segments remain, we add what's accumulated  *   so far to the result array and increment the number of matches.  *  * Input: a pattern path list (as generated by splitpath), a string  *	  pointer that points to what we've traversed so far (this  *	  can be initialized to "/" to start the search at the root  *	  directory, or to "./" to start the search at the current  *	  directory), and a string pointer to the end of the string  *	  in the previous argument.  * Returns: nothing.  */
specifier|static
name|VOID
name|traverse
parameter_list|(
name|pl
parameter_list|,
name|sofar
parameter_list|,
name|endcur
parameter_list|)
name|struct
name|path
modifier|*
name|pl
decl_stmt|;
name|char
modifier|*
name|sofar
decl_stmt|,
decl|*
name|endcur
decl_stmt|;
block|{
comment|/* Define LONGFN (long file names) automatically for BSD 2.9 and 4.2 */
comment|/* LONGFN can also be defined on the cc command line. */
ifdef|#
directive|ifdef
name|BSD29
ifndef|#
directive|ifndef
name|LONGFN
define|#
directive|define
name|LONGFN
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BSD42
ifndef|#
directive|ifndef
name|LONGFN
define|#
directive|define
name|LONGFN
endif|#
directive|endif
endif|#
directive|endif
comment|/* Appropriate declarations for directory routines and structures */
comment|/* #define OPENDIR means to use opendir(), readdir(), closedir()  */
comment|/* If OPENDIR not defined, we use open(), read(), close() */
ifdef|#
directive|ifdef
name|DIRENT
comment|/* New way,<dirent.h> */
define|#
directive|define
name|OPENDIR
name|DIR
modifier|*
name|fd
decl_stmt|,
modifier|*
name|opendir
argument_list|()
decl_stmt|;
name|struct
name|dirent
modifier|*
name|dirbuf
decl_stmt|;
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|()
function_decl|;
else|#
directive|else
comment|/* !DIRENT */
ifdef|#
directive|ifdef
name|LONGFN
comment|/* Old way,<dir.h> with opendir() */
define|#
directive|define
name|OPENDIR
name|DIR
modifier|*
name|fd
decl_stmt|,
modifier|*
name|opendir
argument_list|()
decl_stmt|;
name|struct
name|direct
modifier|*
name|dirbuf
decl_stmt|;
else|#
directive|else
comment|/* !LONGFN */
name|int
name|fd
decl_stmt|;
comment|/* Old way,<dir.h> with open() */
name|struct
name|direct
name|dir_entry
decl_stmt|;
name|struct
name|direct
modifier|*
name|dirbuf
init|=
operator|&
name|dir_entry
decl_stmt|;
endif|#
directive|endif
comment|/* LONGFN */
endif|#
directive|endif
comment|/* DIRENT */
name|struct
name|stat
name|statbuf
decl_stmt|;
comment|/* for file info */
if|if
condition|(
name|pl
operator|==
name|NULL
condition|)
block|{
operator|*
operator|--
name|endcur
operator|=
literal|'\0'
expr_stmt|;
comment|/* end string, overwrite trailing / */
name|addresult
argument_list|(
name|sofar
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|iswild
argument_list|(
name|pl
operator|->
name|npart
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|endcur
argument_list|,
name|pl
operator|->
name|npart
argument_list|)
expr_stmt|;
name|endcur
operator|+=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|pl
operator|->
name|npart
argument_list|)
expr_stmt|;
operator|*
name|endcur
operator|=
literal|'\0'
expr_stmt|;
comment|/* end current string */
if|if
condition|(
name|stat
argument_list|(
name|sofar
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* if current piece exists */
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
name|endcur
operator|-
name|sofar
operator|==
literal|3
operator|&&
name|endcur
index|[
operator|-
literal|1
index|]
operator|==
literal|'.'
operator|&&
name|endcur
index|[
operator|-
literal|2
index|]
operator|==
literal|':'
condition|)
name|endcur
operator|--
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* OS2 */
operator|*
name|endcur
operator|++
operator|=
name|DIRSEP
expr_stmt|;
comment|/* add slash to end */
operator|*
name|endcur
operator|=
literal|'\0'
expr_stmt|;
comment|/* and end the string */
name|traverse
argument_list|(
name|pl
operator|->
name|fwd
argument_list|,
name|sofar
argument_list|,
name|endcur
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
comment|/* Segment contains wildcards, have to search directory */
operator|*
name|endcur
operator|=
literal|'\0'
expr_stmt|;
comment|/* end current string */
if|if
condition|(
name|stat
argument_list|(
name|sofar
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return;
comment|/* doesn't exist, forget it */
if|if
condition|(
operator|!
name|S_ISDIR
argument_list|(
name|statbuf
operator|.
name|st_mode
argument_list|)
condition|)
return|return;
comment|/* not a directory, skip */
ifdef|#
directive|ifdef
name|OPENDIR
if|if
condition|(
operator|(
name|fd
operator|=
name|opendir
argument_list|(
name|sofar
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return;
comment|/* Can't open, fail. */
while|while
condition|(
name|dirbuf
operator|=
name|readdir
argument_list|(
name|fd
argument_list|)
condition|)
else|#
directive|else
comment|/* !OPENDIR */
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|sofar
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return;
comment|/* Can't open, fail. */
while|while
condition|(
name|read
argument_list|(
name|fd
argument_list|,
operator|(
name|char
operator|*
operator|)
name|dirbuf
argument_list|,
sizeof|sizeof
name|dir_entry
argument_list|)
condition|)
endif|#
directive|endif
comment|/* OPENDIR */
block|{
comment|/* Get null-terminated copy!!! */
name|strncpy
argument_list|(
name|nambuf
argument_list|,
name|dirbuf
operator|->
name|d_name
argument_list|,
name|MAXNAMLEN
argument_list|)
expr_stmt|;
name|nambuf
index|[
name|MAXNAMLEN
index|]
operator|=
literal|'\0'
expr_stmt|;
ifdef|#
directive|ifdef
name|unos
if|if
condition|(
name|dirbuf
operator|->
name|d_ino
operator|!=
operator|-
literal|1
operator|&&
name|match
argument_list|(
name|pl
operator|->
name|npart
argument_list|,
name|nambuf
argument_list|)
condition|)
else|#
directive|else
comment|/* #ifdef _POSIX_SOURCE */
comment|/*   Directory reading is not specified in POSIX.1.  POSIX.2 gives us glob() and   fnmatch(), which are not yet supported by C-Kermit.  Meanwhile, maybe POSIX   implementations should force "set wildcard shell" and remove all of this   code. */
ifdef|#
directive|ifdef
name|SOLARIS
if|if
condition|(
name|dirbuf
operator|->
name|d_ino
operator|!=
literal|0
operator|&&
name|match
argument_list|(
name|pl
operator|->
name|npart
argument_list|,
name|nambuf
argument_list|)
condition|)
else|#
directive|else
ifdef|#
directive|ifdef
name|sun
if|if
condition|(
name|dirbuf
operator|->
name|d_fileno
operator|!=
literal|0
operator|&&
name|match
argument_list|(
name|pl
operator|->
name|npart
argument_list|,
name|nambuf
argument_list|)
condition|)
else|#
directive|else
ifdef|#
directive|ifdef
name|bsdi
if|if
condition|(
name|dirbuf
operator|->
name|d_fileno
operator|!=
literal|0
operator|&&
name|match
argument_list|(
name|pl
operator|->
name|npart
argument_list|,
name|nambuf
argument_list|)
condition|)
else|#
directive|else
ifdef|#
directive|ifdef
name|__386BSD__
if|if
condition|(
name|dirbuf
operator|->
name|d_fileno
operator|!=
literal|0
operator|&&
name|match
argument_list|(
name|pl
operator|->
name|npart
argument_list|,
name|nambuf
argument_list|)
condition|)
else|#
directive|else
ifdef|#
directive|ifdef
name|ultrix
if|if
condition|(
name|dirbuf
operator|->
name|gd_ino
operator|!=
literal|0
operator|&&
name|match
argument_list|(
name|pl
operator|->
name|npart
argument_list|,
name|nambuf
argument_list|)
condition|)
else|#
directive|else
if|if
condition|(
name|dirbuf
operator|->
name|d_ino
operator|!=
literal|0
operator|&&
name|match
argument_list|(
name|pl
operator|->
name|npart
argument_list|,
name|nambuf
argument_list|)
condition|)
endif|#
directive|endif
comment|/* ultrix */
endif|#
directive|endif
comment|/* __386BSD__ */
endif|#
directive|endif
comment|/* bsdi */
endif|#
directive|endif
comment|/* sun */
endif|#
directive|endif
comment|/* SOLARIS */
comment|/* #else */
comment|/* not _POSIX_SOURCE */
comment|/*	  if (dirbuf->d_ino != 0&& match(pl -> npart,nambuf)) */
comment|/* #endif */
comment|/* _POSIX_SOURCE */
endif|#
directive|endif
comment|/* unos */
block|{
name|char
modifier|*
name|eos
decl_stmt|;
name|strcpy
argument_list|(
name|endcur
argument_list|,
name|nambuf
argument_list|)
expr_stmt|;
name|eos
operator|=
name|endcur
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|nambuf
argument_list|)
expr_stmt|;
operator|*
name|eos
operator|++
operator|=
name|DIRSEP
expr_stmt|;
comment|/* end this segment */
name|traverse
argument_list|(
name|pl
operator|->
name|fwd
argument_list|,
name|sofar
argument_list|,
name|eos
argument_list|)
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|OPENDIR
name|closedir
argument_list|(
name|fd
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !OPENDIR */
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OPENDIR */
block|}
comment|/*  * addresult:  *  Adds a result string to the result array.  Increments the number  *  of matches found, copies the found string into our string  *  buffer, and puts a pointer to the buffer into the caller's result  *  array.  Our free buffer pointer is updated.  If there is no  *  more room in the caller's array, the number of matches is set to -1.  * Input: a result string.  * Returns: nothing.  */
specifier|static
name|VOID
name|addresult
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
name|int
name|l
decl_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"addresult"
argument_list|,
name|str
argument_list|,
name|remlen
argument_list|)
expr_stmt|;
if|if
condition|(
name|str
index|[
literal|0
index|]
operator|==
literal|'.'
operator|&&
name|ISDIRSEP
argument_list|(
name|str
index|[
literal|1
index|]
argument_list|)
condition|)
name|str
operator|+=
literal|2
expr_stmt|;
comment|/* (===OS2 change===) */
if|if
condition|(
operator|--
name|remlen
operator|<
literal|0
condition|)
block|{
name|numfnd
operator|=
operator|-
literal|1
expr_stmt|;
return|return;
block|}
name|l
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|str
argument_list|)
operator|+
literal|1
expr_stmt|;
comment|/* size this will take up */
if|if
condition|(
operator|(
name|freeptr
operator|+
name|l
operator|)
operator|>
operator|(
name|sspace
operator|+
name|ssplen
operator|)
condition|)
block|{
name|numfnd
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* do not record if not enough space */
return|return;
block|}
name|strcpy
argument_list|(
name|freeptr
argument_list|,
name|str
argument_list|)
expr_stmt|;
operator|*
name|resptr
operator|++
operator|=
name|freeptr
expr_stmt|;
name|freeptr
operator|+=
name|l
expr_stmt|;
name|numfnd
operator|++
expr_stmt|;
block|}
comment|/*  * match:  *  pattern matcher.  Takes a string and a pattern possibly containing  *  the wildcard characters '*' and '?'.  Returns true if the pattern  *  matches the string, false otherwise.  * by: Jeff Damens, CUCCA, 1984  * skipping over dot files and backslash quoting added by fdc, 1990.  *  * Input: a string and a wildcard pattern.  * Returns: 1 if match, 0 if no match.  */
specifier|static
name|int
name|match
parameter_list|(
name|pattern
parameter_list|,
name|string
parameter_list|)
name|char
modifier|*
name|pattern
decl_stmt|,
decl|*
name|string
decl_stmt|;
block|{
name|char
modifier|*
name|psave
decl_stmt|,
modifier|*
name|ssave
decl_stmt|;
comment|/* back up pointers for failure */
name|int
name|q
init|=
literal|0
decl_stmt|;
comment|/* quote flag */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"match str"
argument_list|,
name|string
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|psave
operator|=
name|ssave
operator|=
name|NULL
expr_stmt|;
ifndef|#
directive|ifndef
name|MATCHDOT
if|if
condition|(
operator|*
name|string
operator|==
literal|'.'
operator|&&
operator|*
name|pattern
operator|!=
literal|'.'
condition|)
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"match skip"
argument_list|,
name|string
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
endif|#
directive|endif
while|while
condition|(
literal|1
condition|)
block|{
for|for
control|(
init|;
operator|*
name|pattern
operator|==
operator|*
name|string
condition|;
name|pattern
operator|++
operator|,
name|string
operator|++
control|)
comment|/* skip first */
if|if
condition|(
operator|*
name|string
operator|==
literal|'\0'
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* end of strings, succeed */
if|if
condition|(
operator|*
name|pattern
operator|==
literal|'\\'
operator|&&
name|q
operator|==
literal|0
condition|)
block|{
comment|/* Watch out for quoted */
name|q
operator|=
literal|1
expr_stmt|;
comment|/* metacharacters */
name|pattern
operator|++
expr_stmt|;
comment|/* advance past quote */
if|if
condition|(
operator|*
name|pattern
operator|!=
operator|*
name|string
condition|)
return|return
operator|(
literal|0
operator|)
return|;
continue|continue;
block|}
else|else
name|q
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|q
condition|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
if|if
condition|(
operator|*
name|string
operator|!=
literal|'\0'
operator|&&
operator|*
name|pattern
operator|==
literal|'?'
condition|)
block|{
name|pattern
operator|++
expr_stmt|;
comment|/* '?', let it match */
name|string
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|pattern
operator|==
literal|'*'
condition|)
block|{
comment|/* '*' ... */
name|psave
operator|=
operator|++
name|pattern
expr_stmt|;
comment|/* remember where we saw it */
name|ssave
operator|=
name|string
expr_stmt|;
comment|/* let it match 0 chars */
block|}
elseif|else
if|if
condition|(
name|ssave
operator|!=
name|NULL
operator|&&
operator|*
name|ssave
operator|!=
literal|'\0'
condition|)
block|{
comment|/* if not at end  */
comment|/* ...have seen a star */
name|string
operator|=
operator|++
name|ssave
expr_stmt|;
comment|/* skip 1 char from string */
name|pattern
operator|=
name|psave
expr_stmt|;
comment|/* and back up pattern */
block|}
else|else
return|return
operator|(
literal|0
operator|)
return|;
comment|/* otherwise just fail */
block|}
block|}
block|}
comment|/*   The following two functions are for expanding tilde in filenames   Contributed by Howie Kaye, CUCCA, developed for CCMD package. */
comment|/*  W H O A M I  --  Get user's username.  */
comment|/*   1) Get real uid   2) See if the $USER environment variable is set ($LOGNAME on AT&T)   3) If $USER's uid is the same as ruid, realname is $USER   4) Otherwise get logged in user's name   5) If that name has the same uid as the real uid realname is loginname   6) Otherwise, get a name for ruid from /etc/passwd */
specifier|static
name|char
modifier|*
name|whoami
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|DTILDE
ifdef|#
directive|ifdef
name|pdp11
define|#
directive|define
name|WHOLEN
value|100
else|#
directive|else
define|#
directive|define
name|WHOLEN
value|257
endif|#
directive|endif
comment|/* pdp11 */
specifier|static
name|char
name|realname
index|[
literal|256
index|]
decl_stmt|;
comment|/* user's name */
specifier|static
name|int
name|ruid
init|=
operator|-
literal|1
decl_stmt|;
comment|/* user's real uid */
name|char
name|loginname
index|[
literal|256
index|]
decl_stmt|,
name|envname
index|[
literal|256
index|]
decl_stmt|;
comment|/* temp storage */
name|char
modifier|*
name|c
decl_stmt|;
name|struct
name|passwd
modifier|*
name|p
decl_stmt|;
name|_PROTOTYP
argument_list|(
specifier|extern
name|char
operator|*
name|getlogin
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ruid
operator|!=
operator|-
literal|1
condition|)
return|return
operator|(
name|realname
operator|)
return|;
name|ruid
operator|=
name|real_uid
argument_list|()
expr_stmt|;
comment|/* get our uid */
comment|/* how about $USER or $LOGNAME? */
if|if
condition|(
operator|(
name|c
operator|=
name|getenv
argument_list|(
name|NAMEENV
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* check the env variable */
name|strcpy
argument_list|(
name|envname
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|getpwnam
argument_list|(
name|envname
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|p
operator|->
name|pw_uid
operator|==
name|ruid
condition|)
block|{
comment|/* get passwd entry for envname */
name|strcpy
argument_list|(
name|realname
argument_list|,
name|envname
argument_list|)
expr_stmt|;
comment|/* if the uid's are the same */
return|return
operator|(
name|realname
operator|)
return|;
block|}
block|}
block|}
comment|/* can we use loginname() ? */
if|if
condition|(
operator|(
name|c
operator|=
name|getlogin
argument_list|()
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* name from utmp file */
name|strcpy
argument_list|(
name|loginname
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|getpwnam
argument_list|(
name|loginname
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
comment|/* get passwd entry */
if|if
condition|(
name|p
operator|->
name|pw_uid
operator|==
name|ruid
condition|)
block|{
comment|/* for loginname */
name|strcpy
argument_list|(
name|realname
argument_list|,
name|loginname
argument_list|)
expr_stmt|;
comment|/* if the uid's are the same */
return|return
operator|(
name|realname
operator|)
return|;
block|}
block|}
comment|/* Use first name we get for ruid */
if|if
condition|(
operator|(
name|p
operator|=
name|getpwuid
argument_list|(
name|ruid
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* name for uid */
name|realname
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* no user name */
name|ruid
operator|=
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|strcpy
argument_list|(
name|realname
argument_list|,
name|p
operator|->
name|pw_name
argument_list|)
expr_stmt|;
return|return
operator|(
name|realname
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|NULL
operator|)
return|;
endif|#
directive|endif
comment|/* DTILDE */
block|}
comment|/*  T I L D E _ E X P A N D  --  expand ~user to the user's home directory. */
name|char
modifier|*
name|tilde_expand
parameter_list|(
name|dirname
parameter_list|)
name|char
modifier|*
name|dirname
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|DTILDE
ifdef|#
directive|ifdef
name|pdp11
define|#
directive|define
name|BUFLEN
value|100
else|#
directive|else
define|#
directive|define
name|BUFLEN
value|257
endif|#
directive|endif
comment|/* pdp11 */
name|struct
name|passwd
modifier|*
name|user
decl_stmt|;
specifier|static
name|char
name|olddir
index|[
name|BUFLEN
index|]
decl_stmt|;
specifier|static
name|char
name|oldrealdir
index|[
name|BUFLEN
index|]
decl_stmt|;
specifier|static
name|char
name|temp
index|[
name|BUFLEN
index|]
decl_stmt|;
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"tilde_expand"
argument_list|,
name|dirname
argument_list|,
name|dirname
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|dirname
index|[
literal|0
index|]
operator|!=
literal|'~'
condition|)
comment|/* Not a tilde...return param */
return|return
operator|(
name|dirname
operator|)
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|olddir
argument_list|,
name|dirname
argument_list|)
condition|)
block|{
comment|/* Same as last time */
return|return
operator|(
name|oldrealdir
operator|)
return|;
comment|/* so return old answer. */
block|}
else|else
block|{
name|j
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|dirname
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|j
condition|;
name|i
operator|++
control|)
comment|/* find username part of string */
if|if
condition|(
operator|!
name|ISDIRSEP
argument_list|(
name|dirname
index|[
name|i
index|]
argument_list|)
condition|)
name|temp
index|[
name|i
index|]
operator|=
name|dirname
index|[
name|i
index|]
expr_stmt|;
else|else
break|break;
name|temp
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* tie off with a NULL */
if|if
condition|(
name|i
operator|==
literal|1
condition|)
block|{
comment|/* if just a "~" */
name|user
operator|=
name|getpwnam
argument_list|(
name|whoami
argument_list|()
argument_list|)
expr_stmt|;
comment|/*  get info on current user */
block|}
else|else
block|{
name|user
operator|=
name|getpwnam
argument_list|(
operator|&
name|temp
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* otherwise on the specified user */
block|}
block|}
if|if
condition|(
name|user
operator|!=
name|NULL
condition|)
block|{
comment|/* valid user? */
name|strcpy
argument_list|(
name|olddir
argument_list|,
name|dirname
argument_list|)
expr_stmt|;
comment|/* remember the directory */
name|strcpy
argument_list|(
name|oldrealdir
argument_list|,
name|user
operator|->
name|pw_dir
argument_list|)
expr_stmt|;
comment|/* and their home directory */
name|strcat
argument_list|(
name|oldrealdir
argument_list|,
operator|&
name|dirname
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldrealdir
operator|)
return|;
block|}
else|else
block|{
comment|/* invalid? */
name|strcpy
argument_list|(
name|olddir
argument_list|,
name|dirname
argument_list|)
expr_stmt|;
comment|/* remember for next time */
name|strcpy
argument_list|(
name|oldrealdir
argument_list|,
name|dirname
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldrealdir
operator|)
return|;
block|}
else|#
directive|else
return|return
operator|(
name|NULL
operator|)
return|;
endif|#
directive|endif
comment|/* DTILDE */
block|}
comment|/*   Functions for executing system commands.   zsyscmd() executes the system command in the normal, default way for   the system.  In UNIX, it does what system() does.  Thus, its results   are always predictable.   zshcmd() executes the command using the user's preferred shell. */
name|int
name|zsyscmd
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|OS2
if|if
condition|(
operator|!
name|priv_chk
argument_list|()
condition|)
name|system
argument_list|(
name|s
argument_list|)
expr_stmt|;
else|#
directive|else
name|PID_T
name|shpid
decl_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
comment|/* This doesn't work... */
name|WAIT_T
name|status
decl_stmt|;
else|#
directive|else
name|int
name|status
decl_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
if|if
condition|(
name|shpid
operator|=
name|fork
argument_list|()
condition|)
block|{
if|if
condition|(
name|shpid
operator|<
operator|(
name|PID_T
operator|)
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Parent */
while|while
condition|(
name|shpid
operator|!=
operator|(
name|PID_T
operator|)
name|wait
argument_list|(
operator|&
name|status
argument_list|)
condition|)
empty_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
if|if
condition|(
name|priv_can
argument_list|()
condition|)
block|{
comment|/* Child: cancel any priv's */
name|printf
argument_list|(
literal|"?Privilege cancellation failure\n"
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|255
argument_list|)
expr_stmt|;
block|}
name|execl
argument_list|(
literal|"/bin/sh"
argument_list|,
literal|"sh"
argument_list|,
literal|"-c"
argument_list|,
name|s
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|"/bin/sh"
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|255
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Shut up ANSI compilers. */
endif|#
directive|endif
comment|/* OS2 */
block|}
comment|/*   UNIX code by H. Fischer; copyright rights assigned to Columbia Univ.   Adapted to use getpwuid to find login shell because many systems do not   have SHELL in environment, and to use direct calling of shell rather   than intermediate system() call. -- H. Fischer   Call with s pointing to command to execute. */
name|int
name|zshcmd
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|PID_T
name|pid
decl_stmt|;
ifdef|#
directive|ifdef
name|OS2
name|char
modifier|*
name|shell
init|=
name|getenv
argument_list|(
literal|"COMSPEC"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|priv_chk
argument_list|()
condition|)
if|if
condition|(
operator|*
name|s
operator|==
literal|'\0'
condition|)
name|spawnl
argument_list|(
name|P_WAIT
argument_list|,
name|shell
argument_list|,
name|shell
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
else|else
name|system
argument_list|(
name|s
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|AMIGA
if|if
condition|(
operator|!
name|priv_chk
argument_list|()
condition|)
name|system
argument_list|(
name|s
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|datageneral
if|if
condition|(
name|priv_chk
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
operator|*
name|s
operator|==
literal|'\0'
condition|)
comment|/* Interactive shell requested? */
ifdef|#
directive|ifdef
name|mvux
name|system
argument_list|(
literal|"/bin/sh "
argument_list|)
expr_stmt|;
else|#
directive|else
name|system
argument_list|(
literal|"x :cli prefix Kermit_Baby:"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* mvux */
else|else
comment|/* Otherwise, */
name|system
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* Best for aos/vs?? */
else|#
directive|else
ifdef|#
directive|ifdef
name|aegis
if|if
condition|(
operator|(
name|pid
operator|=
name|vfork
argument_list|()
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Make child quickly */
name|char
modifier|*
name|shpath
decl_stmt|,
modifier|*
name|shname
decl_stmt|,
modifier|*
name|shptr
decl_stmt|;
comment|/* For finding desired shell */
if|if
condition|(
name|priv_can
argument_list|()
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Turn off privs. */
if|if
condition|(
operator|(
name|shpath
operator|=
name|getenv
argument_list|(
literal|"SHELL"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|shpath
operator|=
literal|"/com/sh"
expr_stmt|;
else|#
directive|else
comment|/* All Unix systems */
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
comment|/* Make child */
name|char
modifier|*
name|shpath
decl_stmt|,
modifier|*
name|shname
decl_stmt|,
modifier|*
name|shptr
decl_stmt|;
comment|/* For finding desired shell */
name|struct
name|passwd
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|defshell
init|=
literal|"/bin/sh"
decl_stmt|;
comment|/* Default */
if|if
condition|(
name|priv_can
argument_list|()
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Turn off privs. */
name|p
operator|=
name|getpwuid
argument_list|(
name|real_uid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* Get login data */
if|if
condition|(
name|p
operator|==
operator|(
expr|struct
name|passwd
operator|*
operator|)
name|NULL
operator|||
operator|!
operator|*
operator|(
name|p
operator|->
name|pw_shell
operator|)
condition|)
name|shpath
operator|=
name|defshell
expr_stmt|;
else|else
name|shpath
operator|=
name|p
operator|->
name|pw_shell
expr_stmt|;
endif|#
directive|endif
comment|/* aegis */
name|shptr
operator|=
name|shname
operator|=
name|shpath
expr_stmt|;
while|while
condition|(
operator|*
name|shptr
operator|!=
literal|'\0'
condition|)
if|if
condition|(
operator|*
name|shptr
operator|++
operator|==
name|DIRSEP
condition|)
name|shname
operator|=
name|shptr
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
operator|||
operator|*
name|s
operator|==
literal|'\0'
condition|)
block|{
comment|/* Interactive shell requested? */
name|execl
argument_list|(
name|shpath
argument_list|,
name|shname
argument_list|,
literal|"-i"
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* Yes, do that */
block|}
else|else
block|{
comment|/* Otherwise, */
name|execl
argument_list|(
name|shpath
argument_list|,
name|shname
argument_list|,
literal|"-c"
argument_list|,
name|s
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* exec the given command */
block|}
comment|/* If execl() failed, */
name|exit
argument_list|(
name|BAD_EXIT
argument_list|)
expr_stmt|;
comment|/* return bad return code. */
block|}
else|else
block|{
comment|/* Parent */
name|int
name|wstat
decl_stmt|;
comment|/* ... must wait for child */
name|SIGTYP
argument_list|(
operator|*
name|istat
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|qstat
argument_list|)
argument_list|()
decl_stmt|;
if|if
condition|(
name|pid
operator|==
operator|(
name|PID_T
operator|)
operator|-
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* fork() failed? */
name|istat
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Let the fork handle keyboard */
name|qstat
operator|=
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* interrupts itself... */
while|while
condition|(
operator|(
operator|(
name|wstat
operator|=
name|wait
argument_list|(
operator|(
name|WAIT_T
operator|*
operator|)
literal|0
argument_list|)
operator|)
operator|!=
name|pid
operator|)
operator|&&
operator|(
name|wstat
operator|!=
operator|-
literal|1
operator|)
condition|)
empty_stmt|;
comment|/* Wait for fork */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|istat
argument_list|)
expr_stmt|;
comment|/* Restore interrupts */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|qstat
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
return|return
operator|(
literal|1
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|aegis
comment|/*  Replacement for strchr() and index(), neither of which seem to be universal. */
specifier|static
name|char
modifier|*
ifdef|#
directive|ifdef
name|CK_ANSIC
name|xindex
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
function|xindex
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|,
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* xindex */
block|{
while|while
condition|(
operator|*
name|s
operator|!=
literal|'\0'
operator|&&
operator|*
name|s
operator|!=
name|c
condition|)
name|s
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
name|c
condition|)
return|return
operator|(
name|s
operator|)
return|;
else|else
return|return
operator|(
name|NULL
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* aegis */
comment|/*  I S W I L D  --  Check if filespec is "wild"  */
comment|/*   Returns 0 if it is a single file, 1 if it contains wildcard characters.   Note: must match the algorithm used by match(), hence no [a-z], etc. */
name|int
name|iswild
parameter_list|(
name|filespec
parameter_list|)
name|char
modifier|*
name|filespec
decl_stmt|;
block|{
name|char
name|c
decl_stmt|;
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|wildxpand
condition|)
block|{
if|if
condition|(
operator|(
name|x
operator|=
name|zxpand
argument_list|(
name|filespec
argument_list|)
operator|)
operator|>
literal|1
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* File does not exist */
name|p
operator|=
name|malloc
argument_list|(
name|MAXNAMLEN
operator|+
literal|20
argument_list|)
expr_stmt|;
name|znext
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|x
operator|=
operator|(
name|strcmp
argument_list|(
name|filespec
argument_list|,
name|p
argument_list|)
operator|!=
literal|0
operator|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
else|else
block|{
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|filespec
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
if|if
condition|(
name|c
operator|==
literal|'*'
operator|||
name|c
operator|==
literal|'?'
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
ifdef|#
directive|ifdef
name|OS2
comment|/*  Z C H D S K  --  Change currently selected disk device */
comment|/* Returns -1 if error, otherwise 0 */
name|zchdsk
argument_list|(
argument|c
argument_list|)
name|int
name|c
decl_stmt|;
block|{
name|int
name|i
init|=
name|toupper
argument_list|(
name|c
argument_list|)
operator|-
literal|64
decl_stmt|;
return|return
operator|(
name|_chdrive
argument_list|(
name|i
argument_list|)
operator|)
return|;
block|}
undef|#
directive|undef
name|stat
name|os2stat
argument_list|(
argument|char *path
argument_list|,
argument|struct stat *st
argument_list|)
block|{
name|char
name|local
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|len
decl_stmt|;
name|strcpy
argument_list|(
name|local
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|local
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|==
literal|2
operator|&&
name|local
index|[
literal|1
index|]
operator|==
literal|':'
condition|)
name|local
index|[
literal|2
index|]
operator|=
name|DIRSEP
operator|,
name|local
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
comment|/* if drive only, append / */
elseif|else
if|if
condition|(
name|len
operator|==
literal|0
condition|)
name|local
index|[
literal|0
index|]
operator|=
name|DIRSEP
operator|,
name|local
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
comment|/* if empty path, take / instead */
elseif|else
if|if
condition|(
name|len
operator|>
literal|1
operator|&&
name|ISDIRSEP
argument_list|(
name|local
index|[
name|len
operator|-
literal|1
index|]
argument_list|)
operator|&&
name|local
index|[
name|len
operator|-
literal|2
index|]
operator|!=
literal|':'
condition|)
name|local
index|[
name|len
operator|-
literal|1
index|]
operator|=
literal|0
expr_stmt|;
comment|/* strip trailing / except after d: */
return|return
name|stat
argument_list|(
name|local
argument_list|,
name|st
argument_list|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

end_unit

