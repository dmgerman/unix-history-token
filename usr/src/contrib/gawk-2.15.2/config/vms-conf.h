begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config.h -- configuration definitions for gawk.  *  * For VMS (assumes V4.6 or later; tested on V5.3 and V5.4)  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1991, 1992 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Progamming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with GAWK; see the file COPYING.  If not, write to  * the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/*  * BLKSIZE_MISSING  *	VMS: missing--not applicable  * Check your /usr/include/sys/stat.h file.  If the stat structure  * does not have a member named st_blksize, define this.  (This will  * most likely be the case on most System V systems prior to V.4.)  */
end_comment

begin_define
define|#
directive|define
name|BLKSIZE_MISSING
value|1
end_define

begin_comment
comment|/*  * SIGTYPE  *	VMS: either should work; void is 'correct'  * The return type of the routines passed to the signal function.  * Modern systems use `void', older systems use `int'.  * If left undefined, it will default to void.  */
end_comment

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_comment
comment|/*  * SIZE_T_MISSING  *	VMS:<stddef.h> via<stdlib.h> (VAX C V2.3& up);<sys/types.h> (GNU C)  * If your system has no typedef for size_t, define this to get a default  */
end_comment

begin_comment
comment|/* #define	SIZE_T_MISSING	1 */
end_comment

begin_comment
comment|/*  * CHAR_UNSIGNED  *	VMS: well behaved, either signed or unsigned (signed by default)  * If your machine uses unsigned characters (IBM RT and RS/6000 and others)  * then define this for use in regex.c  */
end_comment

begin_comment
comment|/* #define CHAR_UNSIGNED	1 */
end_comment

begin_comment
comment|/*  * HAVE_UNDERSCORE_SETJMP  *	VMS: not present  * Check in your /usr/include/setjmp.h file.  If there are routines  * there named _setjmp and _longjmp, then you should define this.  * Typically only systems derived from Berkeley Unix have this.  */
end_comment

begin_comment
comment|/* #define HAVE_UNDERSCORE_SETJMP	1 */
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
comment|/*  * MEMCMP_MISSING  * MEMCPY_MISSING  * MEMSET_MISSING  *	VMS:<string.h> (introduced V4.6)  * These three routines are for manipulating blocks of memory. Most  * likely they will either all three be present or all three be missing,  * so they're grouped together.  */
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
comment|/*  * RANDOM_MISSING  *	VMS: missing (as of V5.4)  * Your system does not have the random(3) suite of random number  * generating routines.  These are different than the old rand(3)  * routines!  */
end_comment

begin_define
define|#
directive|define
name|RANDOM_MISSING
value|1
end_define

begin_comment
comment|/*  * STRCASE_MISSING  *	VMS: missing  * Your system does not have the strcasemp() and strncasecmp()  * routines that originated in Berkeley Unix.  */
end_comment

begin_define
define|#
directive|define
name|STRCASE_MISSING
value|1
end_define

begin_comment
comment|/*  * STRCHR_MISSING  *	VMS:<string.h>  * Your system does not have the strchr() and strrchr() functions.  */
end_comment

begin_comment
comment|/* #define STRCHR_MISSING	1 */
end_comment

begin_comment
comment|/*  * STRERROR_MISSING  *	VMS:<stdlib.h> (introduced V4.6)  * Your system lacks the ANSI C strerror() routine for returning the  * strings associated with errno values.  */
end_comment

begin_comment
comment|/* #define STRERROR_MISSING	1 */
end_comment

begin_comment
comment|/*  * STRTOD_MISSING  *	VMS:<stdlib.h> (introduced V4.6)  * Your system does not have the strtod() routine for converting  * strings to double precision floating point values.  */
end_comment

begin_comment
comment|/* #define STRTOD_MISSING	1 */
end_comment

begin_comment
comment|/*  * STRFTIME_MISSING  *	VMS: missing (as of V5.4) [see below; do not change STRFTIME_MISSING]  * Your system lacks the ANSI C strftime() routine for formatting  * broken down time values.  */
end_comment

begin_define
define|#
directive|define
name|STRFTIME_MISSING
value|1
end_define

begin_comment
comment|/*  * TZSET_MISSING  *	VMS: missing, but can't use missing/tzset.c  [no timezone support]  * If you have a 4.2 BSD vintage system, then the strftime() routine  * supplied in the missing directory won't be enough, because it relies on the  * tzset() routine from System V / Posix.  Fortunately, there is an  * emulation for tzset() too that should do the trick.  If you don't  * have tzset(), define this.  */
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
comment|/*  * STDC_HEADERS  *	VMS: close enough (as of V4.6, VAX C V2.3) [GCC, see below]  * If your system does have ANSI compliant header files that  * provide prototypes for library routines, then define this.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/*  * NO_TOKEN_PASTING  *	VMS: compiler specific--see below  * If your compiler define's __STDC__ but does not support token  * pasting (tok##tok), then define this.  */
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
comment|/*  * NON_STD_SPRINTF  *	VMS: ok  * Look in your /usr/include/stdio.h file.  If the return type of the  * sprintf() function is NOT `int', define this.  */
end_comment

begin_comment
comment|/* #define NON_STD_SPRINTF	1 */
end_comment

begin_comment
comment|/*  * VPRINTF_MISSING  *	VMS: ok (introduced V4.6)  * Define this if your system lacks vprintf() and the other routines  * that go with it.  This will trigger an attempt to use _doprnt().  * If you don't have that, this attempt will fail and you are on your own.  */
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
comment|/*  * SYSTEM_MISSING  *	VMS: ok (introduced V4.6)  * Define this if your library does not provide a system function  * or you are not entirely happy with it and would rather use  * a provided replacement (atari only).  */
end_comment

begin_comment
comment|/* #define SYSTEM_MISSING   1 */
end_comment

begin_comment
comment|/*  * FMOD_MISSING  *	VMS: ok (introduced V4.6)  * Define this if your system lacks the fmod() function and modf() will  * be used instead.  */
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
comment|/*  * DEFPATH  *	VMS: "/AWK_LIBRARY" => "AWK_LIBRARY:"  * The default search path for the -f option of gawk.  It is used  * if the AWKPATH environment variable is undefined.  *  * Note: OK even if no AWK_LIBRARY logical name has been defined.  */
end_comment

begin_define
define|#
directive|define
name|DEFPATH
value|".,/AWK_LIBRARY"
end_define

begin_define
define|#
directive|define
name|ENVSEP
value|','
end_define

begin_comment
comment|/*  * alloca already has a prototype defined - don't redefine it  */
end_comment

begin_comment
comment|/* #define ALLOCA_PROTO	1 */
end_comment

begin_comment
comment|/*  * srandom already has a prototype defined - don't redefine it  */
end_comment

begin_comment
comment|/* #define SRANDOM_PROTO	1 */
end_comment

begin_comment
comment|/*  * Extended source file access.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FILETYPE
value|".awk"
end_define

begin_comment
comment|/*  * Pipe handling.  */
end_comment

begin_define
define|#
directive|define
name|PIPES_SIMULATED
value|1
end_define

begin_comment
comment|/*  * %g format in VAXCRTL is broken (chooses %e format when should use %f).  */
end_comment

begin_define
define|#
directive|define
name|GFMT_WORKAROUND
value|1
end_define

begin_comment
comment|/*  * VAX C  *  * As of V3.2, VAX C is not yet ANSI-compliant.  But it's close enough  * for GAWK's purposes.  Comment this out for VAX C V2.4 and earlier.  * Value of 0 should mean "not ANSI-C", but GAWK uses def/not-def tests.  * YYDEBUG definition is needed for combination of VAX C V2.x and Bison.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAXC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STDC__
value|0
end_define

begin_define
define|#
directive|define
name|NO_TOKEN_PASTING
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__DECC
end_ifndef

begin_comment
comment|/* DEC C does not support #pragma builtins even in VAXC mode */
end_comment

begin_define
define|#
directive|define
name|VAXC_BUILTINS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define YYDEBUG 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DEC C  *  * Digital's ANSI complier.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__DECC
end_ifdef

begin_comment
comment|/* nothing special at the moment */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * GNU C  *  * Versions of GCC (actually GAS) earlier than 1.38 don't produce the  * right code for ``extern const'' constructs, and other usages of  * const might not be right either.  The old set of include files from  * the gcc-vms distribution did not contain prototypes, and this could  * provoke some const-related compiler warnings.  If you've got an old  * version of gcc for VMS, define 'const' out of existance, and by all  * means obtain the most recent version!  *  * Note: old versions of GCC should also avoid defining STDC_HEADERS,  *       because most of the ANSI-C required header files are missing.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/* #define const */
end_comment

begin_comment
comment|/* #undef STDC_HEADERS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDC_HEADERS
end_ifndef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_define
define|#
directive|define
name|environ
value|$$PsectAttributes_NOSHR$$environ
end_define

begin_comment
comment|/* awful GAS kludge */
end_comment

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
name|STRFTIME_MISSING
end_ifdef

begin_comment
comment|/*  * Always use the version of strftime() in missing/strftime.c instead of  * the [as yet undocumented/unsupported] one in VAXCRTL.  Renaming it here  * guarantees that it won't clash with the library routine.  */
end_comment

begin_define
define|#
directive|define
name|strftime
value|gnu_strftime
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

