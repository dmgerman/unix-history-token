begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for hp9000 series 200 or 300    Copyright (C) 1985 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Define NOMULTIPLEJOBS on versions of HPUX before 6.5.  */
end_comment

begin_comment
comment|/* #define NOMULTIPLEJOBS */
end_comment

begin_comment
comment|/* Define this symbol if you are running a version of HP-UX    which predates version 6.01 */
end_comment

begin_comment
comment|/* #define HPUX_5 */
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

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|hp9000s300
end_ifndef

begin_define
define|#
directive|define
name|hp9000s300
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
value|((int) ((x) * 100.0))
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

begin_escape
end_escape

begin_comment
comment|/* For University of Utah 4.3bsd and standard 4.4bsd on HP300s.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_3
end_ifdef

begin_comment
comment|/* Tell crt0.c that this is an ordinary 68020.  */
end_comment

begin_undef
undef|#
directive|undef
name|hp9000s300
end_undef

begin_define
define|#
directive|define
name|CRT0_DUMMIES
value|bogus_a6,
end_define

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETLOADAVG
end_ifndef

begin_undef
undef|#
directive|undef
name|LOAD_AVE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|LOAD_AVE_CVT
end_undef

begin_define
define|#
directive|define
name|LOAD_AVE_TYPE
value|long
end_define

begin_define
define|#
directive|define
name|LOAD_AVE_CVT
parameter_list|(
name|x
parameter_list|)
value|((int) (((double) (x)) / 2048.0 * 100.0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_3 */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4_3
end_ifndef

begin_comment
comment|/* The following definitions are for HPUX only.  */
end_comment

begin_comment
comment|/* The symbol in the kernel where the load average is found    is named _avenrun on this machine.  */
end_comment

begin_define
define|#
directive|define
name|LDAV_SYMBOL
value|"_avenrun"
end_define

begin_comment
comment|/* This library is needed with -g, on the 200/300 only.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__HPUX_ASM__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBS_DEBUG
value|/usr/lib/end.o
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The symbol FIONREAD is defined, but the feature does not work    on the 200/300.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_FIONREAD
end_define

begin_comment
comment|/* In older versions of hpux, for unknown reasons, S_IFLNK is defined    even though symbolic links do not exist.    Make sure our conditionals based on S_IFLNK are not confused.     Here we assume that stat.h is included before config.h    so that we can override it here.     Version 6 of HP-UX has symbolic links.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_5
end_ifdef

begin_undef
undef|#
directive|undef
name|S_IFLNK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the BSTRING functions in terms of the sysV functions.    Version 6 of HP-UX supplies these in the BSD library,    but that library has reported bugs in `signal'.  */
end_comment

begin_comment
comment|/* #ifdef HPUX_5 */
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
comment|/* #endif */
end_comment

begin_comment
comment|/* On USG systems these have different names.    Version 6 of HP-UX supplies these in the BSD library,    which we currently want to avoid using.  */
end_comment

begin_comment
comment|/* #ifdef HPUX_5 */
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
comment|/* #endif */
end_comment

begin_comment
comment|/* Define C_SWITCH_MACHINE to be +X if you want the s200/300  * Emacs to run on both 68010 and 68020 based hp-ux's.  *  * Define OLD_HP_ASSEMBLER if you have an ancient assembler  *  * Define HPUX_68010 if you are using the new assembler but  * compiling for a s200 (upgraded) or s310.  68010 based  * processor without 68881.  */
end_comment

begin_comment
comment|/* These switches increase the size of some internal C compiler tables.    They are required for compiling the X11 interface files. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX_5
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|C_SWITCH_MACHINE
value|-Wc,-Nd4000,-Ns3000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define NEED_BSDTTY if you have such. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOMULTIPLEJOBS
end_ifndef

begin_define
define|#
directive|define
name|NEED_BSDTTY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BSD4_3 */
end_comment

end_unit

