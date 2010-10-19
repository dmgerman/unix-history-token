begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Mach-O support for BFD.    Copyright 1999, 2000, 2001, 2002, 2003, 2005    Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BFD_MACH_O_H_
end_ifndef

begin_define
define|#
directive|define
name|_BFD_MACH_O_H_
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_define
define|#
directive|define
name|BFD_MACH_O_N_STAB
value|0xe0
end_define

begin_comment
comment|/* If any of these bits set, a symbolic debugging entry.  */
end_comment

begin_define
define|#
directive|define
name|BFD_MACH_O_N_PEXT
value|0x10
end_define

begin_comment
comment|/* Private external symbol bit.  */
end_comment

begin_define
define|#
directive|define
name|BFD_MACH_O_N_TYPE
value|0x0e
end_define

begin_comment
comment|/* Mask for the type bits.  */
end_comment

begin_define
define|#
directive|define
name|BFD_MACH_O_N_EXT
value|0x01
end_define

begin_comment
comment|/* External symbol bit, set for external symbols.  */
end_comment

begin_define
define|#
directive|define
name|BFD_MACH_O_N_UNDF
value|0x00
end_define

begin_comment
comment|/* Undefined, n_sect == NO_SECT.  */
end_comment

begin_define
define|#
directive|define
name|BFD_MACH_O_N_ABS
value|0x02
end_define

begin_comment
comment|/* Absolute, n_sect == NO_SECT.  */
end_comment

begin_define
define|#
directive|define
name|BFD_MACH_O_N_SECT
value|0x0e
end_define

begin_comment
comment|/* Defined in section number n_sect.  */
end_comment

begin_define
define|#
directive|define
name|BFD_MACH_O_N_PBUD
value|0x0c
end_define

begin_comment
comment|/* Prebound undefined (defined in a dylib).  */
end_comment

begin_define
define|#
directive|define
name|BFD_MACH_O_N_INDR
value|0x0a
end_define

begin_comment
comment|/* Indirect.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|bfd_mach_o_ppc_thread_flavour
block|{
name|BFD_MACH_O_PPC_THREAD_STATE
init|=
literal|1
block|,
name|BFD_MACH_O_PPC_FLOAT_STATE
init|=
literal|2
block|,
name|BFD_MACH_O_PPC_EXCEPTION_STATE
init|=
literal|3
block|,
name|BFD_MACH_O_PPC_VECTOR_STATE
init|=
literal|4
block|}
name|bfd_mach_o_ppc_thread_flavour
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|bfd_mach_o_i386_thread_flavour
block|{
name|BFD_MACH_O_i386_NEW_THREAD_STATE
init|=
literal|1
block|,
name|BFD_MACH_O_i386_FLOAT_STATE
init|=
literal|2
block|,
name|BFD_MACH_O_i386_ISA_PORT_MAP_STATE
init|=
literal|3
block|,
name|BFD_MACH_O_i386_V86_ASSIST_STATE
init|=
literal|4
block|,
name|BFD_MACH_O_i386_REGS_SEGS_STATE
init|=
literal|5
block|,
name|BFD_MACH_O_i386_THREAD_SYSCALL_STATE
init|=
literal|6
block|,
name|BFD_MACH_O_i386_THREAD_STATE_NONE
init|=
literal|7
block|,
name|BFD_MACH_O_i386_SAVED_STATE
init|=
literal|8
block|,
name|BFD_MACH_O_i386_THREAD_STATE
init|=
operator|-
literal|1
block|,
name|BFD_MACH_O_i386_THREAD_FPSTATE
init|=
operator|-
literal|2
block|,
name|BFD_MACH_O_i386_THREAD_EXCEPTSTATE
init|=
operator|-
literal|3
block|,
name|BFD_MACH_O_i386_THREAD_CTHREADSTATE
init|=
operator|-
literal|4
block|, }
name|bfd_mach_o_i386_thread_flavour
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BFD_MACH_O_LC_REQ_DYLD
value|0x80000000
end_define

begin_typedef
typedef|typedef
enum|enum
name|bfd_mach_o_load_command_type
block|{
name|BFD_MACH_O_LC_SEGMENT
init|=
literal|0x1
block|,
comment|/* File segment to be mapped.  */
name|BFD_MACH_O_LC_SYMTAB
init|=
literal|0x2
block|,
comment|/* Link-edit stab symbol table info (obsolete).  */
name|BFD_MACH_O_LC_SYMSEG
init|=
literal|0x3
block|,
comment|/* Link-edit gdb symbol table info.  */
name|BFD_MACH_O_LC_THREAD
init|=
literal|0x4
block|,
comment|/* Thread.  */
name|BFD_MACH_O_LC_UNIXTHREAD
init|=
literal|0x5
block|,
comment|/* UNIX thread (includes a stack).  */
name|BFD_MACH_O_LC_LOADFVMLIB
init|=
literal|0x6
block|,
comment|/* Load a fixed VM shared library.  */
name|BFD_MACH_O_LC_IDFVMLIB
init|=
literal|0x7
block|,
comment|/* Fixed VM shared library id.  */
name|BFD_MACH_O_LC_IDENT
init|=
literal|0x8
block|,
comment|/* Object identification information (obsolete).  */
name|BFD_MACH_O_LC_FVMFILE
init|=
literal|0x9
block|,
comment|/* Fixed VM file inclusion.  */
name|BFD_MACH_O_LC_PREPAGE
init|=
literal|0xa
block|,
comment|/* Prepage command (internal use).  */
name|BFD_MACH_O_LC_DYSYMTAB
init|=
literal|0xb
block|,
comment|/* Dynamic link-edit symbol table info.  */
name|BFD_MACH_O_LC_LOAD_DYLIB
init|=
literal|0xc
block|,
comment|/* Load a dynamically linked shared library.  */
name|BFD_MACH_O_LC_ID_DYLIB
init|=
literal|0xd
block|,
comment|/* Dynamically linked shared lib identification.  */
name|BFD_MACH_O_LC_LOAD_DYLINKER
init|=
literal|0xe
block|,
comment|/* Load a dynamic linker.  */
name|BFD_MACH_O_LC_ID_DYLINKER
init|=
literal|0xf
block|,
comment|/* Dynamic linker identification.  */
name|BFD_MACH_O_LC_PREBOUND_DYLIB
init|=
literal|0x10
block|,
comment|/* Modules prebound for a dynamically.  */
name|BFD_MACH_O_LC_ROUTINES
init|=
literal|0x11
block|,
comment|/* Image routines.  */
name|BFD_MACH_O_LC_SUB_FRAMEWORK
init|=
literal|0x12
block|,
comment|/* Sub framework.  */
name|BFD_MACH_O_LC_SUB_UMBRELLA
init|=
literal|0x13
block|,
comment|/* Sub umbrella.  */
name|BFD_MACH_O_LC_SUB_CLIENT
init|=
literal|0x14
block|,
comment|/* Sub client.  */
name|BFD_MACH_O_LC_SUB_LIBRARY
init|=
literal|0x15
block|,
comment|/* Sub library.  */
name|BFD_MACH_O_LC_TWOLEVEL_HINTS
init|=
literal|0x16
block|,
comment|/* Two-level namespace lookup hints.  */
name|BFD_MACH_O_LC_PREBIND_CKSUM
init|=
literal|0x17
block|,
comment|/* Prebind checksum.  */
comment|/* Load a dynamically linked shared library that is allowed to be        missing (weak).  */
name|BFD_MACH_O_LC_LOAD_WEAK_DYLIB
init|=
literal|0x18
block|}
name|bfd_mach_o_load_command_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|bfd_mach_o_cpu_type
block|{
name|BFD_MACH_O_CPU_TYPE_VAX
init|=
literal|1
block|,
name|BFD_MACH_O_CPU_TYPE_MC680x0
init|=
literal|6
block|,
name|BFD_MACH_O_CPU_TYPE_I386
init|=
literal|7
block|,
name|BFD_MACH_O_CPU_TYPE_MIPS
init|=
literal|8
block|,
name|BFD_MACH_O_CPU_TYPE_MC98000
init|=
literal|10
block|,
name|BFD_MACH_O_CPU_TYPE_HPPA
init|=
literal|11
block|,
name|BFD_MACH_O_CPU_TYPE_ARM
init|=
literal|12
block|,
name|BFD_MACH_O_CPU_TYPE_MC88000
init|=
literal|13
block|,
name|BFD_MACH_O_CPU_TYPE_SPARC
init|=
literal|14
block|,
name|BFD_MACH_O_CPU_TYPE_I860
init|=
literal|15
block|,
name|BFD_MACH_O_CPU_TYPE_ALPHA
init|=
literal|16
block|,
name|BFD_MACH_O_CPU_TYPE_POWERPC
init|=
literal|18
block|}
name|bfd_mach_o_cpu_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|bfd_mach_o_filetype
block|{
name|BFD_MACH_O_MH_OBJECT
init|=
literal|1
block|,
name|BFD_MACH_O_MH_EXECUTE
init|=
literal|2
block|,
name|BFD_MACH_O_MH_FVMLIB
init|=
literal|3
block|,
name|BFD_MACH_O_MH_CORE
init|=
literal|4
block|,
name|BFD_MACH_O_MH_PRELOAD
init|=
literal|5
block|,
name|BFD_MACH_O_MH_DYLIB
init|=
literal|6
block|,
name|BFD_MACH_O_MH_DYLINKER
init|=
literal|7
block|,
name|BFD_MACH_O_MH_BUNDLE
init|=
literal|8
block|}
name|bfd_mach_o_filetype
typedef|;
end_typedef

begin_comment
comment|/* Constants for the type of a section.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|bfd_mach_o_section_type
block|{
comment|/* Regular section.  */
name|BFD_MACH_O_S_REGULAR
init|=
literal|0x0
block|,
comment|/* Zero fill on demand section.  */
name|BFD_MACH_O_S_ZEROFILL
init|=
literal|0x1
block|,
comment|/* Section with only literal C strings.  */
name|BFD_MACH_O_S_CSTRING_LITERALS
init|=
literal|0x2
block|,
comment|/* Section with only 4 byte literals.  */
name|BFD_MACH_O_S_4BYTE_LITERALS
init|=
literal|0x3
block|,
comment|/* Section with only 8 byte literals.  */
name|BFD_MACH_O_S_8BYTE_LITERALS
init|=
literal|0x4
block|,
comment|/* Section with only pointers to literals.  */
name|BFD_MACH_O_S_LITERAL_POINTERS
init|=
literal|0x5
block|,
comment|/* For the two types of symbol pointers sections and the symbol stubs      section they have indirect symbol table entries.  For each of the      entries in the section the indirect symbol table entries, in      corresponding order in the indirect symbol table, start at the index      stored in the reserved1 field of the section structure.  Since the      indirect symbol table entries correspond to the entries in the      section the number of indirect symbol table entries is inferred from      the size of the section divided by the size of the entries in the      section.  For symbol pointers sections the size of the entries in      the section is 4 bytes and for symbol stubs sections the byte size      of the stubs is stored in the reserved2 field of the section      structure.  */
comment|/* Section with only non-lazy symbol pointers.  */
name|BFD_MACH_O_S_NON_LAZY_SYMBOL_POINTERS
init|=
literal|0x6
block|,
comment|/* Section with only lazy symbol pointers.  */
name|BFD_MACH_O_S_LAZY_SYMBOL_POINTERS
init|=
literal|0x7
block|,
comment|/* Section with only symbol stubs, byte size of stub in the reserved2 field.  */
name|BFD_MACH_O_S_SYMBOL_STUBS
init|=
literal|0x8
block|,
comment|/* Section with only function pointers for initialization.  */
name|BFD_MACH_O_S_MOD_INIT_FUNC_POINTERS
init|=
literal|0x9
block|}
name|bfd_mach_o_section_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bfd_mach_o_cpu_subtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_header
block|{
name|unsigned
name|long
name|magic
decl_stmt|;
name|unsigned
name|long
name|cputype
decl_stmt|;
name|unsigned
name|long
name|cpusubtype
decl_stmt|;
name|unsigned
name|long
name|filetype
decl_stmt|;
name|unsigned
name|long
name|ncmds
decl_stmt|;
name|unsigned
name|long
name|sizeofcmds
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|enum
name|bfd_endian
name|byteorder
decl_stmt|;
block|}
name|bfd_mach_o_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_section
block|{
name|asection
modifier|*
name|bfdsection
decl_stmt|;
name|char
name|sectname
index|[
literal|16
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|segname
index|[
literal|16
operator|+
literal|1
index|]
decl_stmt|;
name|bfd_vma
name|addr
decl_stmt|;
name|bfd_vma
name|size
decl_stmt|;
name|bfd_vma
name|offset
decl_stmt|;
name|unsigned
name|long
name|align
decl_stmt|;
name|bfd_vma
name|reloff
decl_stmt|;
name|unsigned
name|long
name|nreloc
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|unsigned
name|long
name|reserved1
decl_stmt|;
name|unsigned
name|long
name|reserved2
decl_stmt|;
block|}
name|bfd_mach_o_section
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_segment_command
block|{
name|char
name|segname
index|[
literal|16
index|]
decl_stmt|;
name|bfd_vma
name|vmaddr
decl_stmt|;
name|bfd_vma
name|vmsize
decl_stmt|;
name|bfd_vma
name|fileoff
decl_stmt|;
name|unsigned
name|long
name|filesize
decl_stmt|;
name|unsigned
name|long
name|nsects
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|bfd_mach_o_section
modifier|*
name|sections
decl_stmt|;
name|asection
modifier|*
name|segment
decl_stmt|;
block|}
name|bfd_mach_o_segment_command
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_symtab_command
block|{
name|unsigned
name|long
name|symoff
decl_stmt|;
name|unsigned
name|long
name|nsyms
decl_stmt|;
name|unsigned
name|long
name|stroff
decl_stmt|;
name|unsigned
name|long
name|strsize
decl_stmt|;
name|asymbol
modifier|*
name|symbols
decl_stmt|;
name|char
modifier|*
name|strtab
decl_stmt|;
name|asection
modifier|*
name|stabs_segment
decl_stmt|;
name|asection
modifier|*
name|stabstr_segment
decl_stmt|;
block|}
name|bfd_mach_o_symtab_command
typedef|;
end_typedef

begin_comment
comment|/* This is the second set of the symbolic information which is used to support    the data structures for the dynamically link editor.     The original set of symbolic information in the symtab_command which contains    the symbol and string tables must also be present when this load command is    present.  When this load command is present the symbol table is organized    into three groups of symbols:        local symbols (static and debugging symbols) - grouped by module        defined external symbols - grouped by module (sorted by name if not lib)        undefined external symbols (sorted by name)    In this load command there are offsets and counts to each of the three groups    of symbols.     This load command contains a the offsets and sizes of the following new    symbolic information tables:        table of contents        module table        reference symbol table        indirect symbol table    The first three tables above (the table of contents, module table and    reference symbol table) are only present if the file is a dynamically linked    shared library.  For executable and object modules, which are files    containing only one module, the information that would be in these three    tables is determined as follows:        table of contents - the defined external symbols are sorted by name        module table - the file contains only one module so everything in the                       file is part of the module.        reference symbol table - is the defined and undefined external symbols     For dynamically linked shared library files this load command also contains    offsets and sizes to the pool of relocation entries for all sections    separated into two groups:        external relocation entries        local relocation entries    For executable and object modules the relocation entries continue to hang    off the section structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_dysymtab_command
block|{
comment|/* The symbols indicated by symoff and nsyms of the LC_SYMTAB load command      are grouped into the following three groups:        local symbols (further grouped by the module they are from)        defined external symbols (further grouped by the module they are from)        undefined symbols       The local symbols are used only for debugging.  The dynamic binding      process may have to use them to indicate to the debugger the local      symbols for a module that is being bound.       The last two groups are used by the dynamic binding process to do the      binding (indirectly through the module table and the reference symbol      table when this is a dynamically linked shared library file).  */
name|unsigned
name|long
name|ilocalsym
decl_stmt|;
comment|/* Index to local symbols.  */
name|unsigned
name|long
name|nlocalsym
decl_stmt|;
comment|/* Number of local symbols.  */
name|unsigned
name|long
name|iextdefsym
decl_stmt|;
comment|/* Index to externally defined symbols.  */
name|unsigned
name|long
name|nextdefsym
decl_stmt|;
comment|/* Number of externally defined symbols.  */
name|unsigned
name|long
name|iundefsym
decl_stmt|;
comment|/* Index to undefined symbols.  */
name|unsigned
name|long
name|nundefsym
decl_stmt|;
comment|/* Number of undefined symbols.  */
comment|/* For the for the dynamic binding process to find which module a symbol      is defined in the table of contents is used (analogous to the ranlib      structure in an archive) which maps defined external symbols to modules      they are defined in.  This exists only in a dynamically linked shared      library file.  For executable and object modules the defined external      symbols are sorted by name and is use as the table of contents.  */
name|unsigned
name|long
name|tocoff
decl_stmt|;
comment|/* File offset to table of contents.  */
name|unsigned
name|long
name|ntoc
decl_stmt|;
comment|/* Number of entries in table of contents.  */
comment|/* To support dynamic binding of "modules" (whole object files) the symbol      table must reflect the modules that the file was created from.  This is      done by having a module table that has indexes and counts into the merged      tables for each module.  The module structure that these two entries      refer to is described below.  This exists only in a dynamically linked      shared library file.  For executable and object modules the file only      contains one module so everything in the file belongs to the module.  */
name|unsigned
name|long
name|modtaboff
decl_stmt|;
comment|/* File offset to module table.  */
name|unsigned
name|long
name|nmodtab
decl_stmt|;
comment|/* Number of module table entries.  */
comment|/* To support dynamic module binding the module structure for each module      indicates the external references (defined and undefined) each module      makes.  For each module there is an offset and a count into the      reference symbol table for the symbols that the module references.      This exists only in a dynamically linked shared library file.  For      executable and object modules the defined external symbols and the      undefined external symbols indicates the external references.  */
name|unsigned
name|long
name|extrefsymoff
decl_stmt|;
comment|/* Offset to referenced symbol table.  */
name|unsigned
name|long
name|nextrefsyms
decl_stmt|;
comment|/* Number of referenced symbol table entries.  */
comment|/* The sections that contain "symbol pointers" and "routine stubs" have      indexes and (implied counts based on the size of the section and fixed      size of the entry) into the "indirect symbol" table for each pointer      and stub.  For every section of these two types the index into the      indirect symbol table is stored in the section header in the field      reserved1.  An indirect symbol table entry is simply a 32bit index into      the symbol table to the symbol that the pointer or stub is referring to.      The indirect symbol table is ordered to match the entries in the section.  */
name|unsigned
name|long
name|indirectsymoff
decl_stmt|;
comment|/* File offset to the indirect symbol table.  */
name|unsigned
name|long
name|nindirectsyms
decl_stmt|;
comment|/* Number of indirect symbol table entries.  */
comment|/* To support relocating an individual module in a library file quickly the      external relocation entries for each module in the library need to be      accessed efficiently.  Since the relocation entries can't be accessed      through the section headers for a library file they are separated into      groups of local and external entries further grouped by module.  In this      case the presents of this load command who's extreloff, nextrel,      locreloff and nlocrel fields are non-zero indicates that the relocation      entries of non-merged sections are not referenced through the section      structures (and the reloff and nreloc fields in the section headers are      set to zero).       Since the relocation entries are not accessed through the section headers      this requires the r_address field to be something other than a section      offset to identify the item to be relocated.  In this case r_address is      set to the offset from the vmaddr of the first LC_SEGMENT command.       The relocation entries are grouped by module and the module table      entries have indexes and counts into them for the group of external      relocation entries for that the module.       For sections that are merged across modules there must not be any      remaining external relocation entries for them (for merged sections      remaining relocation entries must be local).  */
name|unsigned
name|long
name|extreloff
decl_stmt|;
comment|/* Offset to external relocation entries.  */
name|unsigned
name|long
name|nextrel
decl_stmt|;
comment|/* Number of external relocation entries.  */
comment|/* All the local relocation entries are grouped together (they are not      grouped by their module since they are only used if the object is moved      from it statically link edited address).  */
name|unsigned
name|long
name|locreloff
decl_stmt|;
comment|/* Offset to local relocation entries.  */
name|unsigned
name|long
name|nlocrel
decl_stmt|;
comment|/* Number of local relocation entries.  */
block|}
name|bfd_mach_o_dysymtab_command
typedef|;
end_typedef

begin_comment
comment|/* An indirect symbol table entry is simply a 32bit index into the symbol table    to the symbol that the pointer or stub is refering to.  Unless it is for a    non-lazy symbol pointer section for a defined symbol which strip(1) as    removed.  In which case it has the value INDIRECT_SYMBOL_LOCAL.  If the    symbol was also absolute INDIRECT_SYMBOL_ABS is or'ed with that.  */
end_comment

begin_define
define|#
directive|define
name|INDIRECT_SYMBOL_LOCAL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|INDIRECT_SYMBOL_ABS
value|0x40000000
end_define

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_thread_flavour
block|{
name|unsigned
name|long
name|flavour
decl_stmt|;
name|bfd_vma
name|offset
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
block|}
name|bfd_mach_o_thread_flavour
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_thread_command
block|{
name|unsigned
name|long
name|nflavours
decl_stmt|;
name|bfd_mach_o_thread_flavour
modifier|*
name|flavours
decl_stmt|;
name|asection
modifier|*
name|section
decl_stmt|;
block|}
name|bfd_mach_o_thread_command
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_dylinker_command
block|{
name|unsigned
name|long
name|cmd
decl_stmt|;
comment|/* LC_ID_DYLIB or LC_LOAD_DYLIB.  */
name|unsigned
name|long
name|cmdsize
decl_stmt|;
comment|/* Includes pathname string.  */
name|unsigned
name|long
name|name_offset
decl_stmt|;
comment|/* Offset to library's path name.  */
name|unsigned
name|long
name|name_len
decl_stmt|;
comment|/* Offset to library's path name.  */
name|asection
modifier|*
name|section
decl_stmt|;
block|}
name|bfd_mach_o_dylinker_command
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_dylib_command
block|{
name|unsigned
name|long
name|cmd
decl_stmt|;
comment|/* LC_ID_DYLIB or LC_LOAD_DYLIB.  */
name|unsigned
name|long
name|cmdsize
decl_stmt|;
comment|/* Includes pathname string.  */
name|unsigned
name|long
name|name_offset
decl_stmt|;
comment|/* Offset to library's path name.  */
name|unsigned
name|long
name|name_len
decl_stmt|;
comment|/* Offset to library's path name.  */
name|unsigned
name|long
name|timestamp
decl_stmt|;
comment|/* Library's build time stamp.  */
name|unsigned
name|long
name|current_version
decl_stmt|;
comment|/* Library's current version number.  */
name|unsigned
name|long
name|compatibility_version
decl_stmt|;
comment|/* Library's compatibility vers number.  */
name|asection
modifier|*
name|section
decl_stmt|;
block|}
name|bfd_mach_o_dylib_command
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_prebound_dylib_command
block|{
name|unsigned
name|long
name|cmd
decl_stmt|;
comment|/* LC_PREBOUND_DYLIB.  */
name|unsigned
name|long
name|cmdsize
decl_stmt|;
comment|/* Includes strings.  */
name|unsigned
name|long
name|name
decl_stmt|;
comment|/* Library's path name.  */
name|unsigned
name|long
name|nmodules
decl_stmt|;
comment|/* Number of modules in library.  */
name|unsigned
name|long
name|linked_modules
decl_stmt|;
comment|/* Bit vector of linked modules.  */
name|asection
modifier|*
name|section
decl_stmt|;
block|}
name|bfd_mach_o_prebound_dylib_command
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bfd_mach_o_load_command
block|{
name|bfd_mach_o_load_command_type
name|type
decl_stmt|;
name|unsigned
name|int
name|type_required
decl_stmt|;
name|bfd_vma
name|offset
decl_stmt|;
name|bfd_vma
name|len
decl_stmt|;
union|union
block|{
name|bfd_mach_o_segment_command
name|segment
decl_stmt|;
name|bfd_mach_o_symtab_command
name|symtab
decl_stmt|;
name|bfd_mach_o_dysymtab_command
name|dysymtab
decl_stmt|;
name|bfd_mach_o_thread_command
name|thread
decl_stmt|;
name|bfd_mach_o_dylib_command
name|dylib
decl_stmt|;
name|bfd_mach_o_dylinker_command
name|dylinker
decl_stmt|;
name|bfd_mach_o_prebound_dylib_command
name|prebound_dylib
decl_stmt|;
block|}
name|command
union|;
block|}
name|bfd_mach_o_load_command
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mach_o_data_struct
block|{
name|bfd_mach_o_header
name|header
decl_stmt|;
name|bfd_mach_o_load_command
modifier|*
name|commands
decl_stmt|;
name|unsigned
name|long
name|nsymbols
decl_stmt|;
name|asymbol
modifier|*
name|symbols
decl_stmt|;
name|unsigned
name|long
name|nsects
decl_stmt|;
name|bfd_mach_o_section
modifier|*
modifier|*
name|sections
decl_stmt|;
name|bfd
modifier|*
name|ibfd
decl_stmt|;
block|}
name|mach_o_data_struct
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mach_o_data_struct
name|bfd_mach_o_data_struct
typedef|;
end_typedef

begin_function_decl
name|bfd_boolean
name|bfd_mach_o_valid
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_scan_read_symtab_symbol
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_mach_o_symtab_command
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_scan_read_symtab_strtab
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_mach_o_symtab_command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_scan_read_symtab_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_mach_o_symtab_command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_scan_read_dysymtab_symbol
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_mach_o_dysymtab_command
modifier|*
parameter_list|,
name|bfd_mach_o_symtab_command
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_scan_start_address
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_scan
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_mach_o_header
modifier|*
parameter_list|,
name|bfd_mach_o_data_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|bfd_mach_o_mkobject
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|bfd_target
modifier|*
name|bfd_mach_o_object_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|bfd_target
modifier|*
name|bfd_mach_o_core_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|bfd_target
modifier|*
name|bfd_mach_o_archive_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd
modifier|*
name|bfd_mach_o_openr_next_archived_file
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_lookup_section
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_mach_o_load_command
modifier|*
modifier|*
parameter_list|,
name|bfd_mach_o_section
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_lookup_command
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_mach_o_load_command_type
parameter_list|,
name|bfd_mach_o_load_command
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|bfd_mach_o_stack_addr
parameter_list|(
name|enum
name|bfd_mach_o_cpu_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_core_fetch_environment
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|bfd_mach_o_core_file_failing_command
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_mach_o_core_file_failing_signal
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|bfd_mach_o_core_file_matches_executable_p
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|mach_o_be_vec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|mach_o_le_vec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|mach_o_fat_vec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BFD_MACH_O_H_ */
end_comment

end_unit

