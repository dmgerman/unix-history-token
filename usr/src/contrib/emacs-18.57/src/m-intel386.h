begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for intel 386.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
value|(c)
end_define

begin_comment
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically:    Ones defined so far include vax, m68000, ns16000, pyramid,    orion, tahoe, APOLLO and many others */
end_comment

begin_define
define|#
directive|define
name|INTEL386
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

begin_ifdef
ifdef|#
directive|ifdef
name|XENIX
end_ifdef

begin_comment
comment|/* Data type of load average, as read out of kmem.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_TYPE
value|short
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
value|(((double) (x)) * 100.0 / FSCALE)
end_define

begin_define
define|#
directive|define
name|FSCALE
value|256.0
end_define

begin_comment
comment|/* determined by experimentation...  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|XENIX
end_ifdef

begin_define
define|#
directive|define
name|VALBITS
value|26
end_define

begin_define
define|#
directive|define
name|GCTYPEBITS
value|5
end_define

begin_comment
comment|/* Define NO_REMAP if memory segmentation makes it not work well    to change the boundary between the text section and data section    when Emacs is dumped.  If you define this, the preloaded Lisp    code will not be sharable; but that's better than failing completely.  */
end_comment

begin_define
define|#
directive|define
name|NO_REMAP
end_define

begin_define
define|#
directive|define
name|STACK_DIRECTION
value|-1
end_define

begin_comment
comment|/* Since cannot purify, use standard Xenix 386 startup code. */
end_comment

begin_define
define|#
directive|define
name|START_FILES
value|/lib/386/Sseg.o pre-crt0.o /lib/386/Scrt0.o
end_define

begin_comment
comment|/* These really use terminfo.  */
end_comment

begin_define
define|#
directive|define
name|LIBS_TERMCAP
value|/lib/386/Slibcurses.a  \    /lib/386/Slibtinfo.a /lib/386/Slibx.a
end_define

begin_comment
comment|/* Standard libraries for this machine.  Since `-l' doesn't work in `ld'.  */
end_comment

begin_comment
comment|/* '__fltused' is unresolved w/o Slibcfp.a */
end_comment

begin_define
define|#
directive|define
name|LIB_STANDARD
value|/lib/386/Slibcfp.a /lib/386/Slibc.a
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not XENIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_STANDARD
end_ifndef

begin_define
define|#
directive|define
name|LIB_STANDARD
value|-lPW -lc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_define
define|#
directive|define
name|NO_REMAP
end_define

begin_define
define|#
directive|define
name|TEXT_START
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not XENIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_comment
comment|/* If compiling with GCC, let GCC implement alloca.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|alloca
argument_list|)
end_if

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
name|HAVE_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

