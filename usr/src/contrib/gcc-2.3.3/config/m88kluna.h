begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Motorola m88100 running Omron Luna/88k.    Copyright (C) 1991 Free Software Foundation, Inc.    Contributed by Jeffery Friedl (jfriedl@omron.co.jp)    Currently supported by Tom Wood (wood@dg-rtp.dg.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The Omron Luna/88k is MACH and uses BSD a.out, not COFF or ELF.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACH
end_ifndef

begin_define
define|#
directive|define
name|MACH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|DEFAULT_GDB_EXTENSIONS
value|0
end_define

begin_include
include|#
directive|include
file|"aoutos.h"
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
value|"Omron Luna/88k, "
end_define

begin_comment
comment|/* Macros to be automatically defined.  */
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
value|"-DMACH -Dm88k -Dunix -Dluna -Dluna88k -D__CLASSIFY_TYPE__=2"
end_define

begin_comment
comment|/* If -m88000 is in effect, add -Dmc88000; similarly for -m88100 and -m88110.    However, reproduce the effect of -Dmc88100 previously in CPP_PREDEFINES.    Here, the CPU_DEFAULT is assumed to be -m88100.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m88000:-D__mc88000__} \ 		  %{!m88000:%{m88100:%{m88110:-D__mc88000__}}} \ 		  %{!m88000:%{!m88100:%{m88110:-D__mc88110__}}} \ 		  %{!m88000:%{!m88110:%{!ansi:%{traditional:-Dmc88100}} \ 				      -D__mc88100__ -D__mc88100}}"
end_define

begin_comment
comment|/* Specify extra dir to search for include files.  */
end_comment

begin_undef
undef|#
directive|undef
name|SYSTEM_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|SYSTEM_INCLUDE_DIR
value|"/usr/mach/include"
end_define

begin_comment
comment|/* For the Omron Luna/88k, a float function returns a double in traditional    mode (and a float in ansi mode).  */
end_comment

begin_undef
undef|#
directive|undef
name|TRADITIONAL_RETURN_FLOAT
end_undef

end_unit

