begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* R2 AIX machine/system dependent defines    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* Define how to take a char and sign-extend into an int.    On machines where char is signed, this is a no-op.  */
end_comment

begin_define
define|#
directive|define
name|SIGN_EXTEND_CHAR
parameter_list|(
name|c
parameter_list|)
value|((((int) (c))<< 24)>> 24)
end_define

begin_comment
comment|/* Now define a symbol for the cpu type, if your compiler    does not define it automatically.  */
end_comment

begin_define
define|#
directive|define
name|IBMR2AIX
end_define

begin_comment
comment|/* Use type int rather than a union, to represent Lisp_Object */
end_comment

begin_comment
comment|/* This is desirable for most machines.	 */
end_comment

begin_define
define|#
directive|define
name|NO_UNION_TYPE
end_define

begin_comment
comment|/* Define CANNOT_DUMP on machines where unexec does not work.    Then the function dump-emacs will not be defined    and temacs will do (load "loadup") automatically unless told otherwise.  */
end_comment

begin_comment
comment|/* #define CANNOT_DUMP */
end_comment

begin_define
define|#
directive|define
name|UNEXEC
value|unexaix.o
end_define

begin_comment
comment|/* Define addresses, macros, change some setup for dump */
end_comment

begin_define
define|#
directive|define
name|NO_REMAP
end_define

begin_define
define|#
directive|define
name|TEXT_START
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TEXT_END
value|0
end_define

begin_define
define|#
directive|define
name|DATA_START
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DATA_END
value|0
end_define

begin_comment
comment|/* The data segment in this machine always starts at address 0x20000000.    An address of data cannot be stored correctly in a Lisp object;    we always lose the high bits.  We must tell XPNTR to add them back.	*/
end_comment

begin_define
define|#
directive|define
name|DATA_SEG_BITS
value|0x20000000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CANNOT_DUMP
end_ifdef

begin_comment
comment|/* Define shared memory segment symbols */
end_comment

begin_define
define|#
directive|define
name|PURE_SEG_BITS
value|0x30000000
end_define

begin_comment
comment|/* Use shared memory.  */
end_comment

begin_comment
comment|/* This is turned off because it does not always work.	See etc/AIX.DUMP.  */
end_comment

begin_comment
comment|/* #define HAVE_SHM */
end_comment

begin_define
define|#
directive|define
name|SHMKEY
value|5305035
end_define

begin_comment
comment|/* used for shared memory code segments */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CANNOT_DUMP */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|BADMAG(x)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|A_TEXTPOS(x)
end_define

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
value|A_SYMPOS(x)
end_define

begin_define
define|#
directive|define
name|A_TEXT_OFFSET
parameter_list|(
name|HDR
parameter_list|)
value|sizeof(HDR)
end_define

begin_comment
comment|/* #define ADJUST_EXEC_HEADER \     unexec_text_start += sizeof(hdr); \     unexec_data_start = ohdr.a_dbase */
end_comment

begin_undef
undef|#
directive|undef
name|ADDR_CORRECT
end_undef

begin_define
define|#
directive|define
name|ADDR_CORRECT
parameter_list|(
name|x
parameter_list|)
value|((int)(x))
end_define

begin_comment
comment|/* Define C_ALLOCA if this machine does not support a true alloca    and the one written in C should be used instead.    Define HAVE_ALLOCA to say that the system provides a properly    working alloca function and it should be used.    Define neither one if an assembler-language alloca    in the file alloca.s should be used.	 */
end_comment

begin_define
define|#
directive|define
name|C_ALLOCA
end_define

begin_define
define|#
directive|define
name|STACK_DIRECTION
value|-1
end_define

begin_comment
comment|/* tell alloca.c which way it grows */
end_comment

begin_comment
comment|/* Specify the font for X to use.  */
end_comment

begin_define
define|#
directive|define
name|X_DEFAULT_FONT
value|"Rom14.500"
end_define

begin_comment
comment|/* Here override various assumptions in ymakefile */
end_comment

begin_define
define|#
directive|define
name|OBJECTS_MACHINE
value|hftctl.o
end_define

begin_define
define|#
directive|define
name|C_SWITCH_MACHINE
value|-D_BSD
end_define

begin_define
define|#
directive|define
name|LIBS_MACHINE
value|-lrts
end_define

begin_define
define|#
directive|define
name|START_FILES
end_define

begin_define
define|#
directive|define
name|HAVE_DUP2
end_define

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
end_define

begin_define
define|#
directive|define
name|HAVE_SYSVIPC
end_define

begin_define
define|#
directive|define
name|HAVE_SETSID
end_define

begin_define
define|#
directive|define
name|HAVE_GETWD
end_define

begin_comment
comment|/*** BUILD 9008 - FIONREAD problem still exists in X-Windows. ***/
end_comment

begin_define
define|#
directive|define
name|BROKEN_FIONREAD
end_define

begin_define
define|#
directive|define
name|NO_SIOCTL_H
end_define

begin_undef
undef|#
directive|undef
name|LINKER
end_undef

begin_define
define|#
directive|define
name|LINKER
value|cc -Wl,-bnso,-bnodelcsect,-bI:/lib/syscalls.exp
end_define

end_unit

