begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for the NCR Tower 32 running System V.2.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically:    vax, m68000, ns16000, pyramid, orion, tahoe and APOLLO    are the ones defined so far.  */
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

begin_define
define|#
directive|define
name|EXPLICIT_SIGN_EXTEND
end_define

begin_comment
comment|/* Data type of load average, as read out of kmem.  */
end_comment

begin_comment
comment|/* #define LOAD_AVE_TYPE long */
end_comment

begin_comment
comment|/* Convert that into an integer that is 100 for a load average of 1.0  */
end_comment

begin_comment
comment|/* #define LOAD_AVE_CVT(x) (int) (((double) (x)) * 100.0 / FSCALE) */
end_comment

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

begin_comment
comment|/* #define C_ALLOCA */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_comment
comment|/* Change some things to avoid bugs in compiler */
end_comment

begin_define
define|#
directive|define
name|SWITCH_ENUM_BUG
value|1
end_define

begin_comment
comment|/* The standard C library is -lcieee, not -lc.    Also use the PW library, which contains alloca.  */
end_comment

begin_define
define|#
directive|define
name|LIB_STANDARD
value|-lPW -lcieee
end_define

begin_comment
comment|/* Use the BOGUS mechanism in crt0.c. */
end_comment

begin_define
define|#
directive|define
name|BOGUS
value|zero, bogus_fp,
end_define

begin_comment
comment|/* emacs's magic number isn't temacs's;    temacs is writeable text (the default!).  */
end_comment

begin_include
include|#
directive|include
file|<asld.h>
end_include

begin_define
define|#
directive|define
name|EXEC_MAGIC
value|AOUT1MAGIC
end_define

begin_define
define|#
directive|define
name|EXEC_PAGESIZE
value|DATACLICK
end_define

end_unit

