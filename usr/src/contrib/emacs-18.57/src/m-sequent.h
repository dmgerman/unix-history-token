begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for SEQUENT BALANCE machines    Copyright (C) 1985, 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* NOTE: this file works for DYNIX release 2.0  	  (not tested on 1.3) on NS32000's */
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

begin_comment
comment|/* #define BIG_ENDIAN */
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
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically:    vax, m68000, ns16000, pyramid, orion, tahoe and APOLLO    are the ones defined so far.  */
end_comment

begin_comment
comment|/* BTW: DYNIX defines sequent, ns32000, and ns16000 (GENIX compatibility) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|sequent
end_ifndef

begin_comment
comment|/* pre DYNIX 2.1 releases */
end_comment

begin_define
define|#
directive|define
name|sequent
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
comment|/* crt0.c should use the vax-bsd style of entry, with these dummy args.  */
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
value|unsigned long
end_define

begin_comment
comment|/* Convert that into an integer that is 100 for a load average of 1.0  */
end_comment

begin_define
define|#
directive|define
name|FSCALE
value|1000.0
end_define

begin_define
define|#
directive|define
name|LOAD_AVE_CVT
parameter_list|(
name|x
parameter_list|)
value|(int) (((double) (x)) * 100.0 / FSCALE)
end_define

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
comment|/* Define C_ALLOCA if this machine does not support a true alloca    and the one written in C should be used instead.    Define HAVE_ALLOCA to say that the system provides a properly    working alloca function and it should be used.    Define neither one if an assembler-language alloca    in the file alloca.s should be used.  */
end_comment

begin_comment
comment|/* #define C_ALLOCA */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_comment
comment|/* Name of file the to look in    for the kernel symbol table (for load average) */
end_comment

begin_undef
undef|#
directive|undef
name|KERNEL_FILE
end_undef

begin_define
define|#
directive|define
name|KERNEL_FILE
value|"/dynix"
end_define

begin_comment
comment|/* Avoids a compiler bug */
end_comment

begin_define
define|#
directive|define
name|TAHOE_REGISTER_BUG
end_define

begin_comment
comment|/* Say that the text segment of a.out includes the header;    the header actually occupies the first few bytes of the text segment    and is counted in hdr.a_text.  Furthermore, the value written    in the a_text in the file must have N_ADDRADJ added to it.  */
end_comment

begin_define
define|#
directive|define
name|A_TEXT_OFFSET
parameter_list|(
name|HDR
parameter_list|)
value|(sizeof (HDR) + N_ADDRADJ (HDR))
end_define

begin_comment
comment|/* (short) negative-int doesn't sign-extend correctly */
end_comment

begin_define
define|#
directive|define
name|SHORT_CAST_BUG
end_define

begin_comment
comment|/* Cause compilations to be done in parallel in ymakefile.  */
end_comment

begin_define
define|#
directive|define
name|MAKE_PARALLEL
value|&
end_define

begin_comment
comment|/* Say that mailer interlocking uses flock.  */
end_comment

begin_define
define|#
directive|define
name|MAIL_USE_FLOCK
end_define

begin_comment
comment|/* On many 4.2-based systems, there's a rather tricky bug  * with the interpretation of the pid/pgrp value given to  * the F_SETOWN fcntl() call.  It works as documented EXCEPT  * when applied to filedescriptors for sockets, in which case  * the sign must be reversed.  If your emacs subprocesses get  * SIGIO's when they shouldn't, while running on a socket  * (e.g. under X windows), you should probably define this.  */
end_comment

begin_define
define|#
directive|define
name|F_SETOWN_SOCK_NEG
end_define

begin_comment
comment|/* Some really obscure 4.2-based systems (like Sequent DYNIX)  * do not support asynchronous I/O (using SIGIO) on sockets,  * even though it works fine on tty's.  If you have one of  * these systems, define the following, and then use it in  * config.h (or elsewhere) to decide when (not) to use SIGIO.  */
end_comment

begin_define
define|#
directive|define
name|NO_SOCK_SIGIO
end_define

begin_comment
comment|/* Define how to search all pty names.    This is for Dynix 3.0; delete next 5 definitions for older systems.  */
end_comment

begin_define
define|#
directive|define
name|PTY_MAJOR
value|"pqrstuvwPQRSTUVW"
end_define

begin_define
define|#
directive|define
name|PTY_MINOR
value|"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
end_define

begin_define
define|#
directive|define
name|PTY_ITERATION
define|\
value|register int ma, mi;					\   for (ma = 0; ma< sizeof(PTY_MAJOR) - 1; ma++)	\     for (mi = 0; mi< sizeof(PTY_MINOR) - 1; mi++)
end_define

begin_define
define|#
directive|define
name|PTY_NAME_SPRINTF
define|\
value|sprintf (pty_name, "/dev/pty%c%c", PTY_MAJOR[ma], PTY_MINOR[mi]);
end_define

begin_define
define|#
directive|define
name|PTY_TTY_NAME_SPRINTF
define|\
value|sprintf (pty_name, "/dev/tty%c%c", PTY_MAJOR[ma], PTY_MINOR[mi]);
end_define

end_unit

