begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Intel 386 (OSF/1 with ELF) version.    Copyright (C) 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config/i386/osfrose.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-DOSF -DOSF1 -Dunix -Asystem(xpg4)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) \ %{mrose: -D__ROSE__ %{!pic-none: -D__SHARED__}} \ %{!mrose: -D__ELF__ %{fpic: -D__SHARED__}} \ %{mno-underscores: -D__NO_UNDERSCORES__} \ %{!mrose: %{!munderscores: -D__NO_UNDERSCORES__}} \ %{.S:	%{!ansi:%{!traditional:%{!traditional-cpp:%{!ftraditional: -traditional}}}}} \ %{.S:	-D__LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C} \ %{!.S:	-D__LANGUAGE_C %{!ansi:-DLANGUAGE_C}}"
end_define

begin_comment
comment|/* Turn on -pic-extern by default for OSF/rose, -fpic for ELF.  */
end_comment

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{gline:%{!g:%{!g0:%{!g1:%{!g2: -g1}}}}} \ %{!melf: %{!mrose: -melf }} \ %{!mrose: %{!munderscores: %{!mno-underscores: -mno-underscores }} \ 	  %{!mmcount: %{!mno-mcount: %{!mmcount-ptr: -mmcount-ptr }}}} \ %{mrose: %{!mmcount: %{!mno-mcount: %{!mmcount-ptr: -mmcount }}} \ 	 %{pic-extern: -mhalf-pic } %{pic-lib: -mhalf-pic } \ 	 %{!pic-extern: %{!pic-lib: %{pic-none: -mno-half-pic} %{!pic-none: -mhalf-pic}}} \ 	 %{pic-calls: } %{pic-names*: }}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{v*: -v}"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{v*: -v} \ %{mrose:	%{!noshrlib: %{pic-none: -noshrlib} %{!pic-none: -warn_nopic}} \ 		%{nostdlib} %{noshrlib} %{glue}} \ %{!mrose:	%{dy} %{dn} %{glue: } \ 		%{h*} %{z*} \ 		%{static:-dn -Bstatic} \ 		%{shared:-G -dy} \ 		%{symbolic:-Bsymbolic -G -dy} \ 		%{G:-G} \ 		%{!dy: %{!dn: %{!static: %{!shared: %{!symbolic: \ 			%{noshrlib: -dn } %{pic-none: -dn } \ 			%{!noshrlib: %{!pic-none: -dy}}}}}}}}"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION_INTERNAL
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_undef
undef|#
directive|undef
name|I386_VERSION
end_undef

begin_define
define|#
directive|define
name|I386_VERSION
value|" 80386, ELF objects"
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION_INTERNAL
parameter_list|(
name|STREAM
parameter_list|)
value|fputs (I386_VERSION, STREAM)
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION
value|TARGET_VERSION_INTERNAL (stderr)
end_define

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_ROSE
end_undef

end_unit

