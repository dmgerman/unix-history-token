begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Copyright (C) 1990 Free Software Foundation, Inc.     Written by Robert Andersson, International Systems, Oslo, Norway.    Please send bug reports, questions and improvements to ra@intsys.no.     For NCR Tower 32/4x0 and 32/6x0 running System V Release 3.    I don't have access to 200/700/800/850 machines, so I don't know if it    works on those as well.  It shouldn't be far from it however.    The hardware floating point support is completely untested, as I do    not have access to a machine with a 6888x FPU in it.    It does not work on the System V Release 2 based OS releases.  Making it    work will not be easy, due to the silly way in which stack expansion is    implemented in the OS.     This file is included in tower-as.h.    Do *NOT* include this file directly.   This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* See m68k.h.  5 means 68020 with no 68881.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|5
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dtower32 -Dtower32_200"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* It is incorrect to test these symbols. 	  They describe the host, not the target. 	  It should not matter which model is specified.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|tower32_600
end_ifdef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dtower32 -Dtower32_600"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tower32_700
end_ifdef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dtower32 -Dtower32_700"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tower32_800
end_ifdef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dtower32 -Dtower32_800"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tower32_850
end_ifdef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dtower32 -Dtower32_850"
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
comment|/* The startfiles and libraries depend on the -p and -m68881 options.    The Tower does not support the -pg option.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{p:%{m68881:-L/usr/lib/fp/libp} -L/usr/lib/libp}             \  %{m68881:-L/usr/lib/fp}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{shlib:-lc_s} -lc crtend.o%s \  %{m68881:/usr/lib/fp/crtn.o}%{!m68881:/lib/crtn.o}"
end_define

begin_comment
comment|/* Use mem* functions, recognize #ident lines.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_define
define|#
directive|define
name|IDENT_DIRECTIVE
end_define

begin_comment
comment|/* Every structure and union's size must be a multiple of two bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|16
end_define

begin_comment
comment|/* All register names should have a leading % character.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"%d0", "%d1", "%d2", "%d3", "%d4", "%d5", "%d6", "%d7",                      \  "%a0", "%a1", "%a2", "%a3", "%a4", "%a5", "%a6", "%sp",                      \  "%fp0", "%fp1", "%fp2", "%fp3", "%fp4", "%fp5", "%fp6", "%fp7"};
end_define

begin_comment
comment|/* We do not want leading underscores.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "%s", NAME)
end_define

end_unit

