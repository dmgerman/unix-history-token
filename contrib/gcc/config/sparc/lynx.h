begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for SPARC running LynxOS.    Copyright (C) 1993, 1995, 1996, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_IDENT
end_undef

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t\".bss\""
end_define

begin_comment
comment|/* ??? Must redefine to get sparclite and v8 defines.  Can this be done    differently?  */
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
value|"%{mthreads:-D_MULTITHREADED}  \   %{mposix:-D_POSIX_SOURCE}  \   %{msystem-v:-I/usr/include_v}  \   %(cpp_cpu)"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
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
value|"-Dunix -Dsparc -DSPARC -DLynx -DLYNX -DIBITS32 -Asystem=unix -Asystem=lynx -Acpu=sparc -Amachine=sparc"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_comment
comment|/* Sparc version of libc.a has references to libm.a (printf calls pow for    instance), so we must always link both.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{mthreads:-L/lib/thread/}  \   %{msystem-v:-lc_v -lm_v -lc_v}  \   %{!msystem-v:%{mposix:-lc_p} -lc -lm -lc}"
end_define

end_unit

