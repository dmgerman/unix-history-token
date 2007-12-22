begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for ARM running ucLinux using ELF    Copyright (C) 1999, 2001, 2004, 2005 Free Software Foundation, Inc.    Contributed by Philip Blundell<pb@nexus.co.uk>     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* We don't want a PLT.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_PLT_RELOC
end_undef

begin_define
define|#
directive|define
name|NEED_PLT_RELOC
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/ELF ucLinux)", stderr);
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_SINGLE_PIC_BASE)
end_define

begin_comment
comment|/* NOTE: The remaining definitions in this file are needed because uclinux    does not use config/linux.h.  */
end_comment

begin_comment
comment|/* Do not assume anything about header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* The GNU C++ standard library requires that these macros be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUSPLUS_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
value|"-D_GNU_SOURCE %(cpp)"
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for GNU/Linux.  Here we add    the GNU/Linux magical crtbegin.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main'.  */
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
define|\
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} \ 		       %{!p:%{profile:gcrt1.o%s} \ 			 %{!profile:crt1.o%s}}}} \    crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for GNU/Linux.  Here we tack on    the GNU/Linux magical crtend.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main', followed by a normal    GNU/Linux "finalizer" file, `crtn.o'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
define|\
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{profile:-p}"
end_define

begin_define
define|#
directive|define
name|LINK_GCC_C_SEQUENCE_SPEC
define|\
value|"%{static:--start-group} %G %L %{static:--end-group}%{!static:%G}"
end_define

begin_comment
comment|/* Use --as-needed -lgcc_s for eh support.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LD_AS_NEEDED
end_ifdef

begin_define
define|#
directive|define
name|USE_LD_AS_NEEDED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

