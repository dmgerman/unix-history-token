begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RTPC AIX machine/system dependent defines    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
name|IBMRTAIX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|AIX
end_ifndef

begin_define
define|#
directive|define
name|AIX
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
comment|/* No load average information appears in the AIX kernel.  VRM has this    info, and if anyone desires they should fix fns.c to get it out of VRM */
end_comment

begin_comment
comment|/* Define CANNOT_DUMP on machines where unexec does not work.    Then the function dump-emacs will not be defined    and temacs will do (load "loadup") automatically unless told otherwise.  */
end_comment

begin_comment
comment|/* #define CANNOT_DUMP */
end_comment

begin_comment
comment|/* Define addresses, macros, change some setup for dump */
end_comment

begin_undef
undef|#
directive|undef
name|COFF
end_undef

begin_define
define|#
directive|define
name|NO_REMAP
end_define

begin_undef
undef|#
directive|undef
name|static
end_undef

begin_comment
comment|/* Since NO_REMAP, problem with statics doesn't exist */
end_comment

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
comment|/* The data segment in this machine always starts at address 0x20000000.    An address of data cannot be stored correctly in a Lisp object;    we always lose the high bits.  We must tell XPNTR to add them back.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SEG_BITS
value|0x20000000
end_define

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

begin_define
define|#
directive|define
name|ADJUST_EXEC_HEADER
define|\
value|unexec_text_start += sizeof(hdr); \     unexec_data_start = ohdr.a_dbase
end_define

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
comment|/* Define C_ALLOCA if this machine does not support a true alloca    and the one written in C should be used instead.    Define HAVE_ALLOCA to say that the system provides a properly    working alloca function and it should be used.    Define neither one if an assembler-language alloca    in the file alloca.s should be used.  */
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
comment|/* AIX has PTYs, so define here, along with defines needed to make them work. */
end_comment

begin_comment
comment|/* AIX has one problem related to PTYs though: SIGHUP is seen by the parent   */
end_comment

begin_comment
comment|/* along with SIGCHLD when the child dies.  Thus we need to ignore SIGHUP     */
end_comment

begin_comment
comment|/* once a process is begun on a PTY.  EMACS may not go away when its tty      */
end_comment

begin_comment
comment|/* goes away because of this -- if this is a problem, either comment out the  */
end_comment

begin_comment
comment|/* def of HAVE_PTYS below, or set process-connection-type to nil in .emacs.   */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTYS
end_define

begin_define
define|#
directive|define
name|PTY_ITERATION
value|for (i=0; i<256; i++)
end_define

begin_define
define|#
directive|define
name|PTY_NAME_SPRINTF
value|sprintf (pty_name, "/dev/ptc%d", i);
end_define

begin_define
define|#
directive|define
name|PTY_TTY_NAME_SPRINTF
define|\
comment|/* Check that server side not already open */
define|\
value|if ((ioctl(fd, PTYSTATUS, 0)& 0xFFFF) != 0) {          \             close(fd);                                          \             continue;                                           \         }                                                       \         sprintf (pty_name, "/dev/pts%d", i);
end_define

begin_comment
comment|/* TIOCNOTTY isn't needed on AIX, but the rest of the conditionalized code     in process.c does properly begin a new process group if we fake this out.    On AIX 2.2 TIOCNOTTY is defined in termio.h, and this will be overriden     by that definition appropriately.  */
end_comment

begin_define
define|#
directive|define
name|TIOCNOTTY
value|IOCTYPE
end_define

begin_comment
comment|/* AIX has IPC. It also has sockets, and either can be used for client/server.    I would suggest the client/server code be changed to use HAVE_SOCKETS rather    than BSD as the conditional if sockets provide any advantages.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSVIPC
end_define

begin_comment
comment|/* AIX has sockets */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKETS
end_define

begin_comment
comment|/* #define SKTPAIR */
end_comment

begin_comment
comment|/* SKTPAIR works, but what is advantage over pipes? */
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

begin_comment
comment|/* On AIX 2.2.1, use these definitions instead #define C_SWITCH_MACHINE -I/usr/include -Nn2000 #define LIBS_MACHINE -lrts #define LIBX10_MACHINE -lrts #define LIBX11_MACHINE -lrts */
end_comment

begin_define
define|#
directive|define
name|C_SWITCH_MACHINE
value|-I/usr/include -I/usr/include/bsd -Nn2000
end_define

begin_comment
comment|/* need to duplicate -lsock -lbsd -lrts so refs in libX can be resolved   */
end_comment

begin_comment
comment|/* order of lib specs in ymakefile should probably be changed.            */
end_comment

begin_define
define|#
directive|define
name|LIBS_MACHINE
value|-lsock -lbsd -lrts
end_define

begin_define
define|#
directive|define
name|LIBX10_MACHINE
value|-lsock -lbsd -lrts
end_define

begin_define
define|#
directive|define
name|LIBX11_MACHINE
value|-lsock -lbsd -lrts
end_define

begin_define
define|#
directive|define
name|OBJECTS_MACHINE
value|hftctl.o
end_define

begin_define
define|#
directive|define
name|START_FILES
value|/lib/crt0.o
end_define

begin_define
define|#
directive|define
name|LD_SWITCH_MACHINE
value|-n -T0x10000000 -K -e start
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* I refuse to promulgate a recommendation that would make          users unable to debug - RMS.  */
end_comment

begin_comment
comment|/* delete the following line to foil optimization, enable debugging */
end_comment

begin_define
define|#
directive|define
name|C_DEBUG_SWITCH
value|-O
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Setup to do some things BSD way - these won't work previous to AIX 2.1.2 */
end_comment

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|t
parameter_list|,
name|s
parameter_list|)
value|(memset((t),(0),(s)))
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|,
name|s
parameter_list|)
value|(memcmp((t),(f),(s)))
end_define

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_define
define|#
directive|define
name|killpg
parameter_list|(
name|pgrp
parameter_list|,
name|sig
parameter_list|)
value|(kill( -(pgrp), (sig) ))
end_define

begin_define
define|#
directive|define
name|BSTRING
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
name|HAVE_SELECT
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEVAL
end_define

begin_define
define|#
directive|define
name|HAVE_VFORK
end_define

begin_comment
comment|/* But don't use utimes() -- it causes SIGSEGV!  Use utime() instead. */
end_comment

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_comment
comment|/* getwd is in same object module as getcwd in AIX 2.2, but doesn't exist */
end_comment

begin_comment
comment|/* at all in 2.1.2.  So, for compatibility, avoid name collision on 2.2 */
end_comment

begin_define
define|#
directive|define
name|getwd
value|AIX_getwd
end_define

begin_comment
comment|/* AIX defines FIONREAD, but it does not work.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_FIONREAD
end_define

end_unit

