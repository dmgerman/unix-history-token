begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for hp9000 series 800 machines.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
value|(c)
end_define

begin_comment
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically:    Ones defined so far include vax, m68000, ns16000, pyramid,    orion, tahoe, APOLLO and many others */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|hp9000s800
end_ifndef

begin_define
define|#
directive|define
name|hp9000s800
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
value|((int) (x * 100.0))
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

begin_define
define|#
directive|define
name|VIRT_ADDR_VARIES
end_define

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

begin_escape
end_escape

begin_comment
comment|/* the data segment on this machine always starts at address 0x40000000. */
end_comment

begin_define
define|#
directive|define
name|DATA_SEG_BITS
value|0x40000000
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

begin_define
define|#
directive|define
name|DATA_START
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TEXT_START
value|0x00000000
end_define

begin_define
define|#
directive|define
name|STACK_DIRECTION
value|1
end_define

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
value|unexhp9k800.o
end_define

begin_define
define|#
directive|define
name|LIBS_MACHINE
end_define

begin_define
define|#
directive|define
name|LIBS_DEBUG
end_define

begin_comment
comment|/* Define NEED_BSDTTY if you have such. */
end_comment

begin_define
define|#
directive|define
name|NEED_BSDTTY
end_define

begin_escape
end_escape

begin_comment
comment|/* The standard definitions of these macros would work ok,    but these are faster because the constants are short. */
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
name|XMARKBIT
parameter_list|(
name|a
parameter_list|)
value|((a)< 0)
end_define

begin_define
define|#
directive|define
name|XSETMARKBIT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) = ((b) ? (a)|MARKBIT : (a)& ~MARKBIT))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Loses when sign bit of type field is set.  */
end_comment

begin_define
define|#
directive|define
name|XUNMARK
parameter_list|(
name|a
parameter_list|)
value|((a) = (((a)<< INTBITS-GCTYPEBITS-VALBITS)>> INTBITS-GCTYPEBITS-VALBITS))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The symbol in the kernel where the load average is found    is named _avenrun.  At this time there are two major flavors    of hp-ux (there is the s800 and s300 (s200) flavors).  The    differences are thusly moved to the corresponding m- file. */
end_comment

begin_comment
comment|/* no underscore please */
end_comment

begin_define
define|#
directive|define
name|LDAV_SYMBOL
value|"avenrun"
end_define

begin_define
define|#
directive|define
name|CPTIME_SYMBOL
value|"cp_time"
end_define

begin_define
define|#
directive|define
name|DKXFER_SYMBOL
value|"dk_xfer"
end_define

begin_comment
comment|/* In hpux, for unknown reasons, S_IFLNK is defined even though    symbolic links do not exist.    Make sure our conditionals based on S_IFLNK are not confused.     Here we assume that stat.h is included before config.h    so that we can override it here.  */
end_comment

begin_undef
undef|#
directive|undef
name|S_IFLNK
end_undef

begin_comment
comment|/* Define the BSTRING functions in terms of the sysV functions. */
end_comment

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|)
value|memcpy (b,a,s)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|memset (a,0,s)
end_define

begin_define
define|#
directive|define
name|bcmp
value|memcmp
end_define

begin_comment
comment|/* On USG systems these have different names. */
end_comment

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_comment
comment|/* Include the file bsdtty.h, since job control exists.  */
end_comment

begin_define
define|#
directive|define
name|NEED_BSDTTY
end_define

end_unit

