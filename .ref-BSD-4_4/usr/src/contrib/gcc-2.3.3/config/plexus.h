begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Copyright (C) 1990 Free Software Foundation, Inc.     Written by Randy Welch    Send bug reports, questions and improvements to any of the following    addresses:     randy@kcin.alphacdc.com    rwelch@isis.cs.du.eu    rwelch@csn.org     For Plexus P/60 and assumably P/35 P/75 P/95's running System V.2     This file outputs assembler source for gas-1.38.1 with the COFF patches    The patches for gas-1.38.1 to support COFF is on ftp.cs.umb.edu in pub/gnu     No debugging is supported, due to the fact that the only debugger Plexus    had was adb *sigh*.     This is configured for label output default by gas as LXXX instead of    plexus cc/as combination requires .LXXX  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* Define __HAVE_68881 in preprocessor only if -m68881 is specified.    This will control the use of inline 68881 insns in certain macros. */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|5
end_define

begin_comment
comment|/* set to 5 if on a '020 box */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m68881:-D__HAVE_68881__}"
end_define

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dm68 -Dunix -Dplexus"
end_define

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|01
end_if

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{m68000:-mc68000}%{mc68000:-mc68000}%{!mc68000:%{!m68000:-mc68020}}"
end_define

begin_undef
undef|#
directive|undef
name|STRICT_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{m68020:-mc68020}%{mc68020:-mc68020}%{!mc68020:%{!mc68020:-mc68000}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/*  Un comment the following if you want adb to be able to follow a core   */
end_comment

begin_comment
comment|/*  file if you compile a program with -O                                  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* #define FRAME_POINTER_REQUIRED */
end_comment

begin_comment
comment|/* Let's be compatible with the Plexus C compiler by default.  Why not?  */
end_comment

begin_define
define|#
directive|define
name|PLEXUS_CC_COMPAT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PLEXUS_CC_COMPAT
end_ifdef

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|16
end_define

begin_comment
comment|/* for compatiblity with cc */
end_comment

begin_undef
undef|#
directive|undef
name|STACK_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_comment
comment|/* ditto */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|NEED_PROBE
end_undef

begin_define
define|#
directive|define
name|NEED_PROBE
value|-132
end_define

begin_comment
comment|/* plexus needs a stack probe */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_comment
comment|/* no real debugger */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*                          items for collect2                         */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|NM_FLAGS
value|""
end_define

begin_define
define|#
directive|define
name|NO_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|NO_DUP2
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"int"
end_define

end_unit

