begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RTPC machine dependent defines     Copyright (C) 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_define
define|#
directive|define
name|WORD_MACHINE
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
value|((signed char)(c))
end_define

begin_comment
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically.  */
end_comment

begin_define
define|#
directive|define
name|ibmrt
end_define

begin_define
define|#
directive|define
name|romp
end_define

begin_comment
comment|/* unfortunately old include files are hanging around.  */
end_comment

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
value|double
end_define

begin_comment
comment|/* For AIS (sysV) */
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
value|(int) (((double) (x)) * 100.0)
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

begin_undef
undef|#
directive|undef
name|VIRT_ADDR_VARIES
end_undef

begin_comment
comment|/* Define C_ALLOCA if this machine does not support a true alloca    and the one written in C should be used instead.    Define HAVE_ALLOCA to say that the system provides a properly    working alloca function and it should be used.    Define neither one if an assembler-language alloca    in the file alloca.s should be used.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_escape
end_escape

begin_comment
comment|/* The data segment in this machine starts at a fixed address.    An address of data cannot be stored correctly in a Lisp object;    we always lose the high bits.  We must tell XPNTR to add them back.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SEG_BITS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DATA_START
value|0x10000000
end_define

begin_comment
comment|/* The text segment always starts at a fixed address.    This way we don't need to have a label _start defined.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_START
value|0
end_define

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
comment|/* Taking a pointer to a char casting it as int pointer */
end_comment

begin_comment
comment|/* and then taking the int which the int pointer points to */
end_comment

begin_comment
comment|/* is practically guaranteed to give erroneous results */
end_comment

begin_define
define|#
directive|define
name|NEED_ERRNO
end_define

begin_define
define|#
directive|define
name|SKTPAIR
end_define

begin_comment
comment|/* BSD has BSTRING.  */
end_comment

begin_define
define|#
directive|define
name|BSTRING
end_define

begin_comment
comment|/* Special switches to give the C compiler.  */
end_comment

begin_define
define|#
directive|define
name|C_SWITCH_MACHINE
value|-Dalloca=_Alloca
end_define

begin_comment
comment|/* Don't attempt to relabel some of the data as text when dumping.    It does not work because their virtual addresses are not consecutive.    This enables us to use the standard crt0.o.  */
end_comment

begin_define
define|#
directive|define
name|NO_REMAP
end_define

end_unit

