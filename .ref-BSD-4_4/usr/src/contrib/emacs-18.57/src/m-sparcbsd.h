begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Sun 4 SPARC.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* SPARC has lowest-numbered byte as most significant */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
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
comment|/* Say this machine is a sparc */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|sparc
end_ifndef

begin_define
define|#
directive|define
name|sparc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This level of optimization is reported to work.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|C_OPTIMIZE_SWITCH
value|-O
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* This level of optimization is reported to work.  */
end_comment

begin_define
define|#
directive|define
name|C_OPTIMIZE_SWITCH
value|-O2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use type int rather than a union, to represent Lisp_Object */
end_comment

begin_define
define|#
directive|define
name|NO_UNION_TYPE
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
comment|/* Define C_ALLOCA if this machine does not support a true alloca    and the one written in C should be used instead.    Define HAVE_ALLOCA to say that the system provides a properly    working alloca function and it should be used.    Define neither one if an assembler-language alloca    in the file alloca.s should be used.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_comment
comment|/* Must use the system's termcap.  It does special things.  */
end_comment

begin_define
define|#
directive|define
name|LIBS_TERMCAP
value|-ltermcap
end_define

begin_comment
comment|/* Mask for address bits within a memory segment */
end_comment

begin_define
define|#
directive|define
name|SEGMENT_MASK
value|(__LDPGSZ - 1)
end_define

begin_comment
comment|/* loader pages are 8k for sun4/4c compat */
end_comment

begin_comment
comment|/* Arrange to link with sun windows, if requested.  */
end_comment

begin_comment
comment|/* For details on emacstool and sunfns, see etc/SUN-SUPPORT */
end_comment

begin_comment
comment|/* These programs require Sun UNIX 4.2 Release 3.2 or greater */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SUN_WINDOWS
end_ifdef

begin_define
define|#
directive|define
name|OTHER_FILES
value|${etcdir}emacstool
end_define

begin_define
define|#
directive|define
name|LIBS_MACHINE
value|-lsuntool -lsunwindow -lpixrect
end_define

begin_define
define|#
directive|define
name|OBJECTS_MACHINE
value|sunfns.o
end_define

begin_define
define|#
directive|define
name|SYMS_MACHINE
value|syms_of_sunfns ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PURESIZE
value|180000
end_define

begin_comment
comment|/* Say that the text segment of a.out includes the header;    the header actually occupies the first few bytes of the text segment    and is counted in hdr.a_text.  */
end_comment

begin_define
define|#
directive|define
name|A_TEXT_OFFSET
parameter_list|(
name|HDR
parameter_list|)
value|sizeof (HDR)
end_define

end_unit

