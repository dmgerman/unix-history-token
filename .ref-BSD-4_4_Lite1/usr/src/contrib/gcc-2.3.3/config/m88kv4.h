begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Motorola 88100 in an 88open ABI environment.    Copyright (C) 1990, 1991 Free Software Foundation, Inc.    Written by Ron Guilmette (rfg@ncd.com).    Contributed to FSF by Network Computing Devices.    Other contributions by Vince Guarna (vguarna@urbana.mcd.mot.com),    Ray Essick (essick@i88.isc.com), and Wilson Tien (wtien@urbana.mcd.mot.com).    Currently supported by Tom Wood (wood@dg-rtp.dg.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* DWARF_DEBUGGING_INFO defined in svr4.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_BUGS
end_ifndef

begin_define
define|#
directive|define
name|AS_BUG_DOT_LABELS
end_define

begin_define
define|#
directive|define
name|AS_BUG_POUND_TYPE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"svr4.h"
end_include

begin_include
include|#
directive|include
file|"m88k.h"
end_include

begin_comment
comment|/* Identify the compiler.  */
end_comment

begin_undef
undef|#
directive|undef
name|VERSION_INFO1
end_undef

begin_define
define|#
directive|define
name|VERSION_INFO1
value|"88open ABI, "
end_define

begin_comment
comment|/* Default switches */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_CHECK_ZERO_DIV | \ 			 MASK_OCS_DEBUG_INFO | \ 			 MASK_SVR4)
end_define

begin_comment
comment|/* Cpp spec.  These pre-assertions are needed for SVR4 as they occur    often in the system header files.  __svr4__ is our extension.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Dm88000 -Dm88k -Dunix -D__svr4__ -Amachine(m88k) -Acpu(m88k) -Asystem(unix)"
end_define

begin_comment
comment|/* For the AT&T SVR4 port, the function is _mcount.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|output_function_profiler (FILE, LABELNO, "_mcount", 1)
end_define

begin_comment
comment|/* Override svr4.h and m88k.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"section\t.init,\"xa\",#progbits"
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"section\t.ctors,\"a\",#progbits"
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"section\t.dtors,\"a\",#progbits"
end_define

end_unit

