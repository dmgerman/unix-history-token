begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for ibm ps/2 aix386.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The following three symbols give information on  the size of various data types.  */
end_comment

begin_define
define|#
directive|define
name|SHORTBITS
value|16
end_define

begin_comment
comment|/* Number of bits in a short */
end_comment

begin_define
define|#
directive|define
name|INTBITS
value|32
end_define

begin_comment
comment|/* Number of bits in an int */
end_comment

begin_define
define|#
directive|define
name|LONGBITS
value|32
end_define

begin_comment
comment|/* Number of bits in a long */
end_comment

begin_comment
comment|/* i386 is not big-endian: lowest numbered byte is least significant. */
end_comment

begin_comment
comment|/* #undef BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define NO_ARG_ARRAY if you cannot take the address of the first of a  * group of arguments and treat it as an array of the arguments.  */
end_comment

begin_comment
comment|/* #define NO_ARG_ARRAY */
end_comment

begin_comment
comment|/* Define WORD_MACHINE if addresses and such have  * to be corrected before they can be used as byte counts.  */
end_comment

begin_comment
comment|/* #define WORD_MACHINE */
end_comment

begin_comment
comment|/* Define how to take a char and sign-extend into an int.    On machines where char is signed, this is a no-op.  */
end_comment

begin_define
define|#
directive|define
name|SIGN_EXTEND_CHAR
parameter_list|(
name|c
parameter_list|)
value|((signed char)(c))
end_define

begin_comment
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically:    Ones defined so far include vax, m68000, ns16000, pyramid,    orion, tahoe, APOLLO and many others */
end_comment

begin_define
define|#
directive|define
name|INTEL386
end_define

begin_define
define|#
directive|define
name|aix386
end_define

begin_undef
undef|#
directive|undef
name|SYSTEM_TYPE
end_undef

begin_define
define|#
directive|define
name|SYSTEM_TYPE
value|"ibm-aix-386"
end_define

begin_comment
comment|/* Use type int rather than a union, to represent Lisp_Object */
end_comment

begin_define
define|#
directive|define
name|NO_UNION_TYPE
end_define

begin_comment
comment|/* crt0.c, if it is used, should use the i386-bsd style of entry.    with no extra dummy args.  On USG and XENIX,    NO_REMAP says this isn't used. */
end_comment

begin_define
define|#
directive|define
name|CRT0_DUMMIES
value|bogus_fp,
end_define

begin_comment
comment|/* crt0.c should define a symbol `start' and do .globl with a dot.  */
end_comment

begin_define
define|#
directive|define
name|DOT_GLOBAL_START
end_define

begin_comment
comment|/* USG systems do not actually support the load average, so disable it for them.  */
end_comment

begin_comment
comment|/* Define CANNOT_DUMP on machines where unexec does not work.    Then the function dump-emacs will not be defined    and temacs will do (load "loadup") automatically unless told otherwise.  */
end_comment

begin_comment
comment|/* #define CANNOT_DUMP */
end_comment

begin_comment
comment|/* Define VIRT_ADDR_VARIES if the virtual addresses of    pure and impure space as loaded can vary, and even their    relative order cannot be relied on.     Otherwise Emacs assumes that text space precedes data space,    numerically.  */
end_comment

begin_comment
comment|/* #define VIRT_ADDR_VARIES */
end_comment

begin_comment
comment|/* Define addresses, macros, change some setup for dump */
end_comment

begin_define
define|#
directive|define
name|NO_REMAP
end_define

begin_undef
undef|#
directive|undef
name|static
end_undef

begin_comment
comment|/* Since NO_REMAP, problem with statics doesn't exist */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG5_3
end_ifdef

begin_define
define|#
directive|define
name|TEXT_START
value|0x00000000
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEXT_START
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TEXT_END
value|0
end_define

begin_define
define|#
directive|define
name|DATA_START
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DATA_END
value|0
end_define

begin_comment
comment|/* The data segment in this machine always starts at address 0x00800000.    An address of data cannot be stored correctly in a Lisp object;    we always lose the high bits.  We must tell XPNTR to add them back.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SEG_BITS
value|0x00800000
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

begin_comment
comment|/* I refuse to promulgate a recommendation that would make          users unable to debug - RMS.  */
end_comment

begin_comment
comment|/* delete the following line to foil optimization, enable debugging */
end_comment

begin_define
define|#
directive|define
name|C_DEBUG_SWITCH
value|-O
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BSTRING
end_define

begin_define
define|#
directive|define
name|HAVE_DUP2
end_define

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
end_define

begin_define
define|#
directive|define
name|HAVE_SELECT
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEVAL
end_define

begin_define
define|#
directive|define
name|HAVE_VFORK
end_define

begin_comment
comment|/*  * 	Define SYSV_SYSTEM_DIR to use the V.3 getdents/readir  *	library functions.  Almost, but not quite the same as  *	the 4.2 functions  */
end_comment

begin_define
define|#
directive|define
name|SYSV_SYSTEM_DIR
end_define

begin_define
define|#
directive|define
name|HAVE_CLOSEDIR
end_define

begin_comment
comment|/* This system, unlike ordinary SYSV, has closedir.  */
end_comment

begin_comment
comment|/*  *	Define NONSYSTEM_DIR_LIBRARY to make Emacs emulate  *      The 4.2 opendir, etc., library functions.  */
end_comment

begin_undef
undef|#
directive|undef
name|NONSYSTEM_DIR_LIBRARY
end_undef

begin_comment
comment|/* But don't use utimes() -- it causes SIGSEGV!  Use utime() instead. */
end_comment

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_comment
comment|/* AIX defines FIONREAD, but it does not work.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_FIONREAD
end_define

begin_escape
end_escape

begin_comment
comment|/* This page was added in June 1990.  It may be incorrect for some versions    of aix, so delete it if it causes trouble.  */
end_comment

begin_comment
comment|/* AIX has sigsetmask() */
end_comment

begin_undef
undef|#
directive|undef
name|sigsetmask
end_undef

begin_comment
comment|/* AIX386 has BSD4.3 PTYs */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTYS
end_define

begin_comment
comment|/* AIX has IPC. It also has sockets, and either can be used for client/server.    I would suggest the client/server code be changed to use HAVE_SOCKETS rather    than BSD as the conditional if sockets provide any advantages. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSVIPC
end_define

begin_comment
comment|/* AIX has sockets */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKETS
end_define

begin_comment
comment|/* #define SKTPAIR */
end_comment

begin_comment
comment|/* SKTPAIR works, but what is advantage over pipes? */
end_comment

begin_comment
comment|/* Specify the font for X to use.  */
end_comment

begin_define
define|#
directive|define
name|X_DEFAULT_FONT
value|"8x13"
end_define

begin_comment
comment|/* AIX has a wait.h.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAIT_HEADER
end_define

begin_comment
comment|/* Data type of load average, as read out of kmem.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_TYPE
value|long
end_define

begin_comment
comment|/* For AIX (sysV) */
end_comment

begin_comment
comment|/* Convert that into an integer that is 100 for a load average of 1.0  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_CVT
parameter_list|(
name|x
parameter_list|)
value|(int) (((double) (x)/65535.0) * 100.0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Here override various assumptions in ymakefile */
end_comment

begin_comment
comment|/* Define C_ALLOCA if this machine does not support a true alloca    and the one written in C should be used instead.    Define HAVE_ALLOCA to say that the system provides a properly    working alloca function and it should be used.    Define neither one if an assembler-language alloca    in the file alloca.s should be used.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|n
parameter_list|)
value|__builtin_alloca(n)
end_define

begin_define
define|#
directive|define
name|LIB_STANDARD
value|/usr/local/lib/gcc-gnulib -lbsd -lrts -lc
end_define

begin_comment
comment|/* -g fails to work, so it is omitted.  */
end_comment

begin_comment
comment|/* tranle says that -fstrength-reduce does not help.  */
end_comment

begin_define
define|#
directive|define
name|C_DEBUG_SWITCH
value|-O
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|C_ALLOCA
end_define

begin_define
define|#
directive|define
name|STACK_DIRECTION
value|-1
end_define

begin_comment
comment|/* tell alloca.c which way it grows */
end_comment

begin_define
define|#
directive|define
name|LIBS_MACHINE
value|-lbsd -lrts
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OBJECTS_MACHINE
value|hftctl.o
end_define

begin_define
define|#
directive|define
name|LD_SWITCH_MACHINE
value|-T0x00400000 -K -e start
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USG5_3
end_ifdef

begin_define
define|#
directive|define
name|XICCC
end_define

begin_define
define|#
directive|define
name|HAVE_GETWD
end_define

begin_define
define|#
directive|define
name|HAVE_RENAME
end_define

begin_undef
undef|#
directive|undef
name|LD_SWITCH_MACHINE
end_undef

begin_define
define|#
directive|define
name|LD_SWITCH_MACHINE
value|-T0x0 -K -e start
end_define

begin_comment
comment|/* Things defined in s-usg5-3.h that need to be overridden.  */
end_comment

begin_undef
undef|#
directive|undef
name|NOMULTIPLEJOBS
end_undef

begin_undef
undef|#
directive|undef
name|BROKEN_TIOCGETC
end_undef

begin_undef
undef|#
directive|undef
name|LIBX10_SYSTEM
end_undef

begin_undef
undef|#
directive|undef
name|LIBX11_SYSTEM
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

