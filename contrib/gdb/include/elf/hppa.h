begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* HPPA ELF support for BFD.    Copyright (C) 1993, 1994 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the HPPA ELF ABI.  Note    that most of this is not actually implemented by BFD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_HPPA_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_HPPA_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* Target processor IDs to be placed in the low 16 bits of the flags    field.  Note these names are shared with SOM, and therefore do not    follow ELF naming conventions.  */
end_comment

begin_comment
comment|/* PA 1.0 big endian.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPU_PA_RISC1_0
end_ifndef

begin_define
define|#
directive|define
name|CPU_PA_RISC1_0
value|0x0000020b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PA 1.1 big endian.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPU_PA_RISC1_1
end_ifndef

begin_define
define|#
directive|define
name|CPU_PA_RISC1_1
value|0x00000210
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PA 1.0 little endian (unsupported) is 0x0000028b.  */
end_comment

begin_comment
comment|/* PA 1.1 little endian (unsupported) is 0x00000290.  */
end_comment

begin_comment
comment|/* Trap null address dereferences.  */
end_comment

begin_define
define|#
directive|define
name|ELF_PARISC_TRAPNIL
value|0x00010000
end_define

begin_comment
comment|/* .PARISC.archext section is present.  */
end_comment

begin_define
define|#
directive|define
name|EF_PARISC_EXT
value|0x00020000
end_define

begin_comment
comment|/* Processor specific section types.  */
end_comment

begin_comment
comment|/* Holds the global offset table, a table of pointers to external    data.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_GOT
value|SHT_LOPROC+0
end_define

begin_comment
comment|/* Nonloadable section containing information in architecture    extensions used by the code.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_ARCH
value|SHT_LOPROC+1
end_define

begin_comment
comment|/* Section in which $global$ is defined.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_GLOBAL
value|SHT_LOPROC+2
end_define

begin_comment
comment|/* Section holding millicode routines (mul, div, rem, dyncall, etc.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_MILLI
value|SHT_LOPROC+3
end_define

begin_comment
comment|/* Section holding unwind information for use by debuggers.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_UNWIND
value|SHT_LOPROC+4
end_define

begin_comment
comment|/* Section holding the procedure linkage table.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_PLT
value|SHT_LOPROC+5
end_define

begin_comment
comment|/* Short initialized and uninitialized data.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_SDATA
value|SHT_LOPROC+6
end_define

begin_define
define|#
directive|define
name|SHT_PARISC_SBSS
value|SHT_LOPROC+7
end_define

begin_comment
comment|/* Optional section holding argument location/relocation info.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_SYMEXTN
value|SHT_LOPROC+8
end_define

begin_comment
comment|/* Option section for linker stubs.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_STUBS
value|SHT_LOPROC+9
end_define

begin_comment
comment|/* Processor specific section flags.  */
end_comment

begin_comment
comment|/* This section is near the global data pointer and thus allows short    addressing modes to be used.  */
end_comment

begin_define
define|#
directive|define
name|SHF_PARISC_SHORT
value|0x20000000
end_define

begin_comment
comment|/* Processor specific symbol types.  */
end_comment

begin_comment
comment|/* Millicode function entry point.  */
end_comment

begin_define
define|#
directive|define
name|STT_PARISC_MILLICODE
value|STT_LOPROC+0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_HPPA_H */
end_comment

end_unit

