begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration common to all targets running RTEMS.     Copyright (C) 2000, 2002, 2004 Free Software Foundation, Inc.   This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* The system headers under RTEMS are C++-aware.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_MEM_FUNCTIONS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Dummy start/end specification to let linker work as  * needed by autoconf scripts using this compiler.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"crt0.o%s"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|""
end_define

begin_comment
comment|/*  * Some targets do not set up LIB_SPECS, override it, here.  */
end_comment

begin_define
define|#
directive|define
name|STD_LIB_SPEC
define|\
value|"%{!shared:%{g*:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}}"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!qrtems: " STD_LIB_SPEC "} " \ "%{!nostdlib: %{qrtems: --start-group \  %{!qrtems_debug: -lrtemsbsp -lrtemscpu} \  %{qrtems_debug: -lrtemsbsp_g -lrtemscpu_g} \  -lc -lgcc --end-group %{!qnolinkcmds: -T linkcmds%s}}}"
end_define

end_unit

