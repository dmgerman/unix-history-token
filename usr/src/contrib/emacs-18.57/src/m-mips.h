begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Mips machines.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* Define BIG_ENDIAN iff lowest-numbered byte in a word    is the most significant byte.  */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
end_define

begin_comment
comment|/* Define NO_ARG_ARRAY if you cannot take the address of the first of a  * group of arguments and treat it as an array of the arguments.  */
end_comment

begin_define
define|#
directive|define
name|NO_ARG_ARRAY
end_define

begin_comment
comment|/* Define WORD_MACHINE if addresses and such have  * to be corrected before they can be used as byte counts.  */
end_comment

begin_undef
undef|#
directive|undef
name|WORD_MACHINE
end_undef

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

begin_ifndef
ifndef|#
directive|ifndef
name|mips
end_ifndef

begin_define
define|#
directive|define
name|mips
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use type int rather than a union, to represent Lisp_Object */
end_comment

begin_comment
comment|/* This is desirable for most machines.  */
end_comment

begin_define
define|#
directive|define
name|NO_UNION_TYPE
end_define

begin_comment
comment|/* Define EXPLICIT_SIGN_EXTEND if XINT must explicitly sign-extend    the 24-bit bit field into an int.  In other words, if bit fields    are always unsigned.     If you use NO_UNION_TYPE, this flag does not matter.  */
end_comment

begin_define
define|#
directive|define
name|EXPLICIT_SIGN_EXTEND
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
comment|/* Convert that into an integer that is 100 for a load average of 1.0  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_CVT
parameter_list|(
name|x
parameter_list|)
value|(int) (((double) (x)) * 100.0 / 256.0)
end_define

begin_comment
comment|/* Define CANNOT_DUMP on machines where unexec does not work.    Then the function dump-emacs will not be defined    and temacs will do (load "loadup") automatically unless told otherwise.  */
end_comment

begin_undef
undef|#
directive|undef
name|CANNOT_DUMP
end_undef

begin_comment
comment|/* Define VIRT_ADDR_VARIES if the virtual addresses of    pure and impure space as loaded can vary, and even their    relative order cannot be relied on.     Otherwise Emacs assumes that text space precedes data space,    numerically.  */
end_comment

begin_comment
comment|/* #define VIRT_ADDR_VARIES */
end_comment

begin_comment
comment|/* Define C_ALLOCA if this machine does not support a true alloca    and the one written in C should be used instead.    Define HAVE_ALLOCA to say that the system provides a properly    working alloca function and it should be used.    Define neither one if an assembler-language alloca    in the file alloca.s should be used.  */
end_comment

begin_define
define|#
directive|define
name|C_ALLOCA
end_define

begin_comment
comment|/* #define HAVE_ALLOCA */
end_comment

begin_comment
comment|/* Define NO_REMAP if memory segmentation makes it not work well    to change the boundary between the text section and data section    when Emacs is dumped.  If you define this, the preloaded Lisp    code will not be sharable; but that's better than failing completely.  */
end_comment

begin_define
define|#
directive|define
name|NO_REMAP
end_define

begin_comment
comment|/* This machine requires completely different unexec code    which lives in a separate file.  Specify the file name.  */
end_comment

begin_define
define|#
directive|define
name|UNEXEC
value|unexmips.o
end_define

begin_comment
comment|/* Describe layout of the address space in an executing process.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_START
value|0x400000
end_define

begin_define
define|#
directive|define
name|DATA_START
value|0x800000
end_define

begin_comment
comment|/* Alter some of the options used when linking.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_comment
comment|/* Supposedly the dec machine doesn't have this library.    #define LIBS_MACHINE -lmld  */
end_comment

begin_define
define|#
directive|define
name|LD_SWITCH_MACHINE
value|-D 800000
end_define

begin_define
define|#
directive|define
name|LIBS_DEBUG
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBS_MACHINE
value|-lmld
end_define

begin_define
define|#
directive|define
name|LD_SWITCH_MACHINE
value|-D 800000 -g3
end_define

begin_define
define|#
directive|define
name|START_FILES
value|pre-crt0.o /usr/lib/crt1.o
end_define

begin_define
define|#
directive|define
name|LIB_STANDARD
value|-lbsd -lc /usr/lib/crtn.o
end_define

begin_define
define|#
directive|define
name|LIBS_TERMCAP
value|-lcurses
end_define

begin_define
define|#
directive|define
name|C_SWITCH_SYSTEM
value|-I/usr/include/bsd
end_define

begin_define
define|#
directive|define
name|C_DEBUG_SWITCH
value|-O -g3
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_X_WINDOWS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_X11
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_VFORK
end_define

begin_comment
comment|/* Graciously provided by libX.a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* The standard definitions of these macros would work ok,    but these are faster because the constants are short.  */
end_comment

begin_define
define|#
directive|define
name|XUINT
parameter_list|(
name|a
parameter_list|)
value|(((unsigned)(a)<< INTBITS-VALBITS)>> INTBITS-VALBITS)
end_define

begin_define
define|#
directive|define
name|XSET
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|ptr
parameter_list|)
define|\
value|((var) = ((int)(type)<< VALBITS) + (((unsigned) (ptr)<< INTBITS-VALBITS)>> INTBITS-VALBITS))
end_define

begin_define
define|#
directive|define
name|XSETINT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSET(a, XTYPE(a), b)
end_define

begin_define
define|#
directive|define
name|XSETUINT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSET(a, XTYPE(a), b)
end_define

begin_define
define|#
directive|define
name|XSETPNTR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSET(a, XTYPE(a), b)
end_define

begin_define
define|#
directive|define
name|XUNMARK
parameter_list|(
name|a
parameter_list|)
value|((a) = (((unsigned)(a)<< INTBITS-GCTYPEBITS-VALBITS)>> INTBITS-GCTYPEBITS-VALBITS))
end_define

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_comment
comment|/* Cancel certain parts of standard sysV support.  */
end_comment

begin_undef
undef|#
directive|undef
name|NONSYSTEM_DIR_LIBRARY
end_undef

begin_define
define|#
directive|define
name|SYSV_SYSTEM_DIR
end_define

begin_undef
undef|#
directive|undef
name|static
end_undef

begin_comment
comment|/* Don't try to use SIGIO or FIONREAD even though they are defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIGIO
end_undef

begin_define
define|#
directive|define
name|BROKEN_FIONREAD
end_define

begin_comment
comment|/* Describe special kernel features.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSVIPC
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEVAL
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|emacs
argument_list|)
end_if

begin_include
include|#
directive|include
file|<bsd/sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define HAVE_SELECT    The `select' in the system won't work for pipes,    so don't use it.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP2
end_define

begin_define
define|#
directive|define
name|HAVE_GETWD
end_define

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
end_define

begin_define
define|#
directive|define
name|HAVE_PTYS
end_define

begin_define
define|#
directive|define
name|HAVE_SOCKETS
end_define

begin_undef
undef|#
directive|undef
name|NOMULTIPLEJOBS
end_undef

begin_define
define|#
directive|define
name|utimes
value|utime
end_define

begin_comment
comment|/* Someone should check this.  */
end_comment

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|IRIS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|COFF
end_define

begin_define
define|#
directive|define
name|TERMINFO
end_define

begin_undef
undef|#
directive|undef
name|MAIL_USE_FLOCK
end_undef

begin_comment
comment|/* Someone should check this.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UNION_WAIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_comment
comment|/* Load average requires special crocks.  Version 19 has them.    For now, this avoids a bug.  */
end_comment

begin_undef
undef|#
directive|undef
name|LOAD_AVE_TYPE
end_undef

end_unit

