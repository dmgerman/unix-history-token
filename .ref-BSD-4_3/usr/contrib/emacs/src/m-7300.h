begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for AT&T UNIX PC model 7300    Copyright (C) 1985 Richard M. Stallman.    Modified for this machine by mtxinu!rtech!gonzo!daveb  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* This machine does not have flexnames.  Yuk */
end_comment

begin_define
define|#
directive|define
name|SHORTNAMES
end_define

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
comment|/* XINT must explicitly sign-extend */
end_comment

begin_define
define|#
directive|define
name|EXPLICIT_SIGN_EXTEND
end_define

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
comment|/* Use type int rather than a union, to represent Lisp_Object */
end_comment

begin_define
define|#
directive|define
name|NO_UNION_TYPE
end_define

begin_comment
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically:    vax, m68000, ns16000 are the ones defined so far.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|mc68k
end_ifndef

begin_define
define|#
directive|define
name|mc68k
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|m68k
end_ifndef

begin_define
define|#
directive|define
name|m68k
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Cause crt0.c to define errno.  */
end_comment

begin_define
define|#
directive|define
name|NEED_ERRNO
end_define

begin_comment
comment|/* Data type of load average, as read out of kmem.  */
end_comment

begin_comment
comment|/* These are commented out since it is not supported by this machine.  */
end_comment

begin_comment
comment|/* #define LOAD_AVE_TYPE long */
end_comment

begin_comment
comment|/* Convert that into an integer that is 100 for a load average of 1.0  */
end_comment

begin_comment
comment|/* #define LOAD_AVE_CVT(x) (int) (((double) (x)) * 100.0) */
end_comment

begin_comment
comment|/* Avoid compiler bug */
end_comment

begin_define
define|#
directive|define
name|ADDR_CORRECT
value|(c) (c)
end_define

end_unit

