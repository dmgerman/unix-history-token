begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config.h -- configuration definitions for gawk.  *  * For generic 4.4 alpha  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1991, 1992, 1993 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Progamming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with GAWK; see the file COPYING.  If not, write to  * the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * This file isolates configuration dependencies for gnu awk.  * You should know something about your system, perhaps by having  * a manual handy, when you edit this file.  You should copy config.h-dist  * to config.h, and edit config.h.  Do not modify config.h-dist, so that  * it will be easy to apply any patches that may be distributed.  *  * The general idea is that systems conforming to the various standards  * should need to do the least amount of changing.  Definining the various  * items in ths file usually means that your system is missing that  * particular feature.  *  * The order of preference in standard conformance is ANSI C, POSIX,  * and the SVID.  *  * If you have no clue as to what's going on with your system, try  * compiling gawk without editing this file and see what shows up  * missing in the link stage.  From there, you can probably figure out  * which defines to turn on.  */
end_comment

begin_comment
comment|/**************************/
end_comment

begin_comment
comment|/* Miscellanious features */
end_comment

begin_comment
comment|/**************************/
end_comment

begin_comment
comment|/*  * BLKSIZE_MISSING  *  * Check your /usr/include/sys/stat.h file.  If the stat structure  * does not have a member named st_blksize, define this.  (This will  * most likely be the case on most System V systems prior to V.4.)  */
end_comment

begin_comment
comment|/* #define BLKSIZE_MISSING	1 */
end_comment

begin_comment
comment|/*  * SIGTYPE  *  * The return type of the routines passed to the signal function.  * Modern systems use `void', older systems use `int'.  * If left undefined, it will default to void.  */
end_comment

begin_comment
comment|/* #define SIGTYPE	int */
end_comment

begin_comment
comment|/*  * SIZE_T_MISSING  *  * If your system has no typedef for size_t, define this to get a default  */
end_comment

begin_comment
comment|/* #define	SIZE_T_MISSING	1 */
end_comment

begin_comment
comment|/*  * CHAR_UNSIGNED  *  * If your machine uses unsigned characters (IBM RT and RS/6000 and others)  * then define this for use in regex.c  */
end_comment

begin_comment
comment|/* #define CHAR_UNSIGNED	1 */
end_comment

begin_comment
comment|/*  * HAVE_UNDERSCORE_SETJMP  *  * Check in your /usr/include/setjmp.h file.  If there are routines  * there named _setjmp and _longjmp, then you should define this.  * Typically only systems derived from Berkeley Unix have this.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNDERSCORE_SETJMP
value|1
end_define

begin_comment
comment|/*  * LIMITS_H_MISSING  *  * You don't have a<limits.h> include file.  */
end_comment

begin_comment
comment|/* #define LIMITS_H_MISSING	1 */
end_comment

begin_comment
comment|/***********************************************/
end_comment

begin_comment
comment|/* Missing library subroutines or system calls */
end_comment

begin_comment
comment|/***********************************************/
end_comment

begin_comment
comment|/*  * MEMCMP_MISSING  * MEMCPY_MISSING  * MEMSET_MISSING  *  * These three routines are for manipulating blocks of memory. Most  * likely they will either all three be present or all three be missing,  * so they're grouped together.  */
end_comment

begin_comment
comment|/* #define MEMCMP_MISSING	1 */
end_comment

begin_comment
comment|/* #define MEMCPY_MISSING	1 */
end_comment

begin_comment
comment|/* #define MEMSET_MISSING	1 */
end_comment

begin_comment
comment|/*  * RANDOM_MISSING  *  * Your system does not have the random(3) suite of random number  * generating routines.  These are different than the old rand(3)  * routines!  */
end_comment

begin_comment
comment|/* #define RANDOM_MISSING	1 */
end_comment

begin_comment
comment|/*  * STRCASE_MISSING  *  * Your system does not have the strcasemp() and strncasecmp()  * routines that originated in Berkeley Unix.  */
end_comment

begin_comment
comment|/* #define STRCASE_MISSING	1 */
end_comment

begin_comment
comment|/*  * STRCHR_MISSING  *  * Your system does not have the strchr() and strrchr() functions.  */
end_comment

begin_comment
comment|/* #define STRCHR_MISSING	1 */
end_comment

begin_comment
comment|/*  * STRERROR_MISSING  *  * Your system lacks the ANSI C strerror() routine for returning the  * strings associated with errno values.  */
end_comment

begin_comment
comment|/* #define STRERROR_MISSING	1 */
end_comment

begin_comment
comment|/*  * STRTOD_MISSING  *  * Your system does not have the strtod() routine for converting  * strings to double precision floating point values.  */
end_comment

begin_comment
comment|/* #define STRTOD_MISSING	1 */
end_comment

begin_comment
comment|/*  * STRFTIME_MISSING  *  * Your system lacks the ANSI C strftime() routine for formatting  * broken down time values.  */
end_comment

begin_comment
comment|/* #define STRFTIME_MISSING	1 */
end_comment

begin_comment
comment|/*  * TZSET_MISSING  *  * If you have a 4.2 BSD vintage system, then the strftime() routine  * supplied in the missing directory won't be enough, because it relies on the  * tzset() routine from System V / Posix.  Fortunately, there is an  * emulation for tzset() too that should do the trick.  If you don't  * have tzset(), define this.  */
end_comment

begin_comment
comment|/* #define TZSET_MISSING	1 */
end_comment

begin_comment
comment|/*  * TZNAME_MISSING  *  * Some systems do not support the external variables tzname and daylight.  * If this is the case *and* strftime() is missing, define this.  */
end_comment

begin_comment
comment|/* #define TZNAME_MISSING	1 */
end_comment

begin_comment
comment|/*  * TM_ZONE_MISSING  *  * Your "struct tm" is missing the tm_zone field.  * If this is the case *and* strftime() is missing *and* tzname is missing,  * define this.  */
end_comment

begin_comment
comment|/* #define TM_ZONE_MISSING	1 */
end_comment

begin_comment
comment|/*  * STDC_HEADERS  *  * If your system does have ANSI compliant header files that  * provide prototypes for library routines, then define this.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/*  * NO_TOKEN_PASTING  *  * If your compiler define's __STDC__ but does not support token  * pasting (tok##tok), then define this.  */
end_comment

begin_comment
comment|/* #define NO_TOKEN_PASTING	1 */
end_comment

begin_comment
comment|/*****************************************************************/
end_comment

begin_comment
comment|/* Stuff related to the Standard I/O Library.			 */
end_comment

begin_comment
comment|/*****************************************************************/
end_comment

begin_comment
comment|/* Much of this is (still, unfortunately) black magic in nature. */
end_comment

begin_comment
comment|/* You may have to use some or all of these together to get gawk */
end_comment

begin_comment
comment|/* to work correctly.						 */
end_comment

begin_comment
comment|/*****************************************************************/
end_comment

begin_comment
comment|/*  * NON_STD_SPRINTF  *  * Look in your /usr/include/stdio.h file.  If the return type of the  * sprintf() function is NOT `int', define this.  */
end_comment

begin_comment
comment|/* #define NON_STD_SPRINTF	1 */
end_comment

begin_comment
comment|/*  * VPRINTF_MISSING  *  * Define this if your system lacks vprintf() and the other routines  * that go with it.  This will trigger an attempt to use _doprnt().  * If you don't have that, this attempt will fail and you are on your own.  */
end_comment

begin_comment
comment|/* #define VPRINTF_MISSING	1 */
end_comment

begin_comment
comment|/*  * Casts from size_t to int and back.  These will become unnecessary  * at some point in the future, but for now are required where the  * two types are a different representation.  */
end_comment

begin_comment
comment|/* #define SZTC */
end_comment

begin_comment
comment|/* #define INTC */
end_comment

begin_comment
comment|/*  * SYSTEM_MISSING  *  * Define this if your library does not provide a system function  * or you are not entirely happy with it and would rather use  * a provided replacement (atari only).  */
end_comment

begin_comment
comment|/* #define SYSTEM_MISSING   1 */
end_comment

begin_comment
comment|/*  * FMOD_MISSING  *  * Define this if your system lacks the fmod() function and modf() will  * be used instead.  */
end_comment

begin_comment
comment|/* #define FMOD_MISSING	1 */
end_comment

begin_comment
comment|/*******************************/
end_comment

begin_comment
comment|/* Gawk configuration options. */
end_comment

begin_comment
comment|/*******************************/
end_comment

begin_comment
comment|/*  * DEFPATH  *  * The default search path for the -f option of gawk.  It is used  * if the AWKPATH environment variable is undefined.  The default  * definition is provided here.  Most likely you should not change  * this.  */
end_comment

begin_comment
comment|/* #define DEFPATH	".:/usr/lib/awk:/usr/local/lib/awk" */
end_comment

begin_comment
comment|/* #define ENVSEP	':' */
end_comment

begin_comment
comment|/*  * alloca already has a prototype defined - don't redefine it  */
end_comment

begin_define
define|#
directive|define
name|ALLOCA_PROTO
value|1
end_define

begin_comment
comment|/*  * srandom already has a prototype defined - don't redefine it  */
end_comment

begin_define
define|#
directive|define
name|SRANDOM_PROTO
value|1
end_define

begin_comment
comment|/*  * getpgrp() in sysvr4 and POSIX takes no argument  */
end_comment

begin_comment
comment|/* #define GETPGRP_NOARG	0 */
end_comment

begin_comment
comment|/*  * define const to nothing if not __STDC__  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If svr4 and not gcc */
end_comment

begin_comment
comment|/* #define SVR4		0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_define
define|#
directive|define
name|__svr4__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* anything that follows is for system-specific short-term kludges */
end_comment

end_unit

