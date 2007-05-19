begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  IRIX version 6.    Copyright (C) 1994, 1995, 1996, 1997, 1998, 2000, 2001, 2002, 2003, 2004,    2005, 2006    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Allow some special handling for IRIX 6.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_IRIX6
end_undef

begin_define
define|#
directive|define
name|TARGET_IRIX6
value|1
end_define

begin_comment
comment|/* Default to -mabi=n32 and -mips3.  */
end_comment

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "mabi=n32" }
end_define

begin_comment
comment|/* Force the default ABI onto the command line in order to make the specs    easier to write.  Default to the mips2 ISA for the O32 ABI.  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_SELF_SPECS
define|\
value|"%{!mabi=*: -mabi=n32}", \   "%{mabi=32: %{!mips*: %{!march*: -mips2}}}"
end_define

begin_comment
comment|/* Force the generation of dwarf .debug_frame sections even if not    compiling -g.  This guarantees that we can unwind the stack.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_FRAME_INFO
value|1
end_define

begin_comment
comment|/* The system unwinder in libexc requires a specific dwarf return address    column to work.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF_FRAME_RETURN_COLUMN
end_undef

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|(FP_REG_LAST + 1)
end_define

begin_undef
undef|#
directive|undef
name|MACHINE_TYPE
end_undef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"SGI running IRIX 6.x"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX_USING_GNU_LD
end_ifdef

begin_define
define|#
directive|define
name|IRIX_SUBTARGET_LINK_SPEC
define|\
value|"%{mabi=32: -melf32bsmip}%{mabi=n32: -melf32bmipn32}%{mabi=64: -melf64bmip}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IRIX_SUBTARGET_LINK_SPEC
define|\
value|"%{w} -_SYSTYPE_SVR4 -woff 131 \    %{mabi=32: -32}%{mabi=n32: -n32}%{mabi=64: -64}%{!mabi*: -n32}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Profiling is supported via libprof1.a not -lc_p as in IRIX 3.  */
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
value|"%{!shared: \      %{mabi=32:%{pg:gcrt1.o%s} \        %{!pg:%{p:mcrt1.o%s libprof1.a%s}%{!p:crt1.o%s}}} \      %{mabi=n32: \        %{mips4:%{pg:/usr/lib32/mips4/gcrt1.o%s} \          %{!pg:%{p:/usr/lib32/mips4/mcrt1.o%s /usr/lib32/mips4/libprof1.a%s} \            %{!p:/usr/lib32/mips4/crt1.o%s}}} \        %{!mips4:%{pg:/usr/lib32/mips3/gcrt1.o%s} \          %{!pg:%{p:/usr/lib32/mips3/mcrt1.o%s /usr/lib32/mips3/libprof1.a%s} \            %{!p:/usr/lib32/mips3/crt1.o%s}}}} \      %{mabi=64: \        %{mips4:%{pg:/usr/lib64/mips4/gcrt1.o} \          %{!pg:%{p:/usr/lib64/mips4/mcrt1.o /usr/lib64/mips4/libprof1.a} \            %{!p:/usr/lib64/mips4/crt1.o}}} \        %{!mips4:%{pg:/usr/lib64/mips3/gcrt1.o} \          %{!pg:%{p:/usr/lib64/mips3/mcrt1.o /usr/lib64/mips3/libprof1.a} \            %{!p:/usr/lib64/mips3/crt1.o}}}}} \   irix-crti.o%s crtbegin.o%s"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX_USING_GNU_LD
end_ifdef

begin_define
define|#
directive|define
name|SUBTARGET_DONT_WARN_UNUSED_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|SUBTARGET_WARN_UNUSED_SPEC
value|""
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SUBTARGET_DONT_WARN_UNUSED_SPEC
value|"-dont_warn_unused"
end_define

begin_define
define|#
directive|define
name|SUBTARGET_WARN_UNUSED_SPEC
value|"-warn_unused"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{mabi=n32: %{mips4:-L/usr/lib32/mips4} %{!mips4:-L/usr/lib32/mips3} \      -L/usr/lib32} \    %{mabi=64: %{mips4:-L/usr/lib64/mips4} %{!mips4:-L/usr/lib64/mips3} \      -L/usr/lib64} \    %{!shared:" \      SUBTARGET_DONT_WARN_UNUSED_SPEC \      " %{pthread:-lpthread} %{p:libprof1.a%s}%{pg:libprof1.a%s} -lc " \      SUBTARGET_WARN_UNUSED_SPEC "}"
end_define

begin_comment
comment|/* Avoid getting two warnings for libgcc.a everytime we link.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
define|\
value|SUBTARGET_DONT_WARN_UNUSED_SPEC " -lgcc " SUBTARGET_WARN_UNUSED_SPEC
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
define|\
value|"crtend.o%s irix-crtn.o%s \    %{!shared: \      %{mabi=32:crtn.o%s}\      %{mabi=n32:%{mips4:/usr/lib32/mips4/crtn.o%s}\        %{!mips4:/usr/lib32/mips3/crtn.o%s}}\      %{mabi=64:%{mips4:/usr/lib64/mips4/crtn.o%s}\        %{!mips4:/usr/lib64/mips3/crtn.o%s}}}"
end_define

begin_define
define|#
directive|define
name|MIPS_TFMODE_FORMAT
value|mips_extended_format
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"%{pthread:-D_REENTRANT}"
end_define

end_unit

