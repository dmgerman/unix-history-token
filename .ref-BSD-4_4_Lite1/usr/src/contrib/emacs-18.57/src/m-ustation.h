begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Ustation E30.    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
name|m68000
end_define

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

begin_comment
comment|/* #define EXPLICIT_SIGN_EXTEND */
end_comment

begin_comment
comment|/* Data type of load average, as read out of kmem.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_TYPE
value|double
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
value|((int) ((x) * 100.0))
end_define

begin_comment
comment|/* Define CANNOT_DUMP on machines where unexec does not work.    Then the function dump-emacs will not be defined    and temacs will do (load "loadup") automatically unless told otherwise.  */
end_comment

begin_comment
comment|/* #define CANNOT_DUMP */
end_comment

begin_comment
comment|/* Define VIRT_ADDR_VARIES if the virtual addresses of    pure and impure space as loaded can vary, and even their    relative order cannot be relied on.     Otherwise Emacs assumes that data space precedes text space,    numerically.  */
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

begin_comment
comment|/* #define NO_REMAP */
end_comment

begin_comment
comment|/* Prevent -lg from being used for debugging.  Not implemented?  */
end_comment

begin_define
define|#
directive|define
name|LIBS_DEBUG
end_define

begin_comment
comment|/* -lnet is not standard library */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SELECT
end_undef

begin_undef
undef|#
directive|undef
name|LIBS_SYSTEM
end_undef

begin_comment
comment|/* Compiler's bug */
end_comment

begin_define
define|#
directive|define
name|SWITCH_ENUM_BUG
end_define

begin_comment
comment|/* Termcap is available */
end_comment

begin_define
define|#
directive|define
name|LIBS_TERMCAP
value|-ltermcap
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|EXEC_PAGESIZE
value|1024
end_define

begin_define
define|#
directive|define
name|PURESIZE
value|130000
end_define

begin_undef
undef|#
directive|undef
name|HAVE_TIMEVAL
end_undef

begin_undef
undef|#
directive|undef
name|NONSYSTEM_DIR_LIBRARY
end_undef

begin_undef
undef|#
directive|undef
name|SIGIO
end_undef

begin_undef
undef|#
directive|undef
name|SIGTSTP
end_undef

end_unit

