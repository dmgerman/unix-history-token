begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MachO.h - Mach-O structures and constants -----------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines MachO .
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHO_H
end_ifndef

begin_define
define|#
directive|define
name|MACHO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/BinaryObject.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
comment|/// MachOSym - This struct contains information about each symbol that is
comment|/// added to logical symbol table for the module.  This is eventually
comment|/// turned into a real symbol table in the file.
struct|struct
name|MachOSym
block|{
specifier|const
name|GlobalValue
modifier|*
name|GV
decl_stmt|;
comment|// The global value this corresponds to.
name|std
operator|::
name|string
name|GVName
expr_stmt|;
comment|// The mangled name of the global value.
name|uint32_t
name|n_strx
decl_stmt|;
comment|// index into the string table
name|uint8_t
name|n_type
decl_stmt|;
comment|// type flag
name|uint8_t
name|n_sect
decl_stmt|;
comment|// section number or NO_SECT
name|int16_t
name|n_desc
decl_stmt|;
comment|// see<mach-o/stab.h>
name|uint64_t
name|n_value
decl_stmt|;
comment|// value for this symbol (or stab offset)
comment|// Constants for the n_sect field
comment|// see<mach-o/nlist.h>
enum|enum
block|{
name|NO_SECT
init|=
literal|0
block|}
enum|;
comment|// symbol is not in any section
comment|// Constants for the n_type field
comment|// see<mach-o/nlist.h>
enum|enum
block|{
name|N_UNDF
init|=
literal|0x0
block|,
comment|// undefined, n_sect == NO_SECT
name|N_ABS
init|=
literal|0x2
block|,
comment|// absolute, n_sect == NO_SECT
name|N_SECT
init|=
literal|0xe
block|,
comment|// defined in section number n_sect
name|N_PBUD
init|=
literal|0xc
block|,
comment|// prebound undefined (defined in a dylib)
name|N_INDR
init|=
literal|0xa
comment|// indirect
block|}
enum|;
comment|// The following bits are OR'd into the types above. For example, a type
comment|// of 0x0f would be an external N_SECT symbol (0x0e | 0x01).
enum|enum
block|{
name|N_EXT
init|=
literal|0x01
block|,
comment|// external symbol bit
name|N_PEXT
init|=
literal|0x10
comment|// private external symbol bit
block|}
enum|;
comment|// Constants for the n_desc field
comment|// see<mach-o/loader.h>
enum|enum
block|{
name|REFERENCE_FLAG_UNDEFINED_NON_LAZY
init|=
literal|0
block|,
name|REFERENCE_FLAG_UNDEFINED_LAZY
init|=
literal|1
block|,
name|REFERENCE_FLAG_DEFINED
init|=
literal|2
block|,
name|REFERENCE_FLAG_PRIVATE_DEFINED
init|=
literal|3
block|,
name|REFERENCE_FLAG_PRIVATE_UNDEFINED_NON_LAZY
init|=
literal|4
block|,
name|REFERENCE_FLAG_PRIVATE_UNDEFINED_LAZY
init|=
literal|5
block|}
enum|;
enum|enum
block|{
name|N_NO_DEAD_STRIP
init|=
literal|0x0020
block|,
comment|// symbol is not to be dead stripped
name|N_WEAK_REF
init|=
literal|0x0040
block|,
comment|// symbol is weak referenced
name|N_WEAK_DEF
init|=
literal|0x0080
comment|// coalesced symbol is a weak definition
block|}
enum|;
name|MachOSym
argument_list|(
argument|const GlobalValue *gv
argument_list|,
argument|std::string name
argument_list|,
argument|uint8_t sect
argument_list|,
argument|const MCAsmInfo *MAI
argument_list|)
empty_stmt|;
struct|struct
name|SymCmp
block|{
comment|// FIXME: this does not appear to be sorting 'f' after 'F'
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|MachOSym
operator|&
name|LHS
operator|,
specifier|const
name|MachOSym
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|GVName
operator|<
name|RHS
operator|.
name|GVName
return|;
block|}
block|}
struct|;
comment|/// PartitionByLocal - Simple boolean predicate that returns true if Sym is
comment|/// a local symbol rather than an external symbol.
specifier|static
specifier|inline
name|bool
name|PartitionByLocal
parameter_list|(
specifier|const
name|MachOSym
modifier|&
name|Sym
parameter_list|)
block|{
return|return
operator|(
name|Sym
operator|.
name|n_type
operator|&
operator|(
name|MachOSym
operator|::
name|N_EXT
operator||
name|MachOSym
operator|::
name|N_PEXT
operator|)
operator|)
operator|==
literal|0
return|;
block|}
comment|/// PartitionByDefined - Simple boolean predicate that returns true if Sym is
comment|/// defined in this module.
specifier|static
specifier|inline
name|bool
name|PartitionByDefined
parameter_list|(
specifier|const
name|MachOSym
modifier|&
name|Sym
parameter_list|)
block|{
comment|// FIXME: Do N_ABS or N_INDR count as defined?
return|return
operator|(
name|Sym
operator|.
name|n_type
operator|&
name|MachOSym
operator|::
name|N_SECT
operator|)
operator|==
name|MachOSym
operator|::
name|N_SECT
return|;
block|}
block|}
struct|;
comment|// end struct MachOSym
comment|/// MachOHeader - This struct contains the header information about a
comment|/// specific architecture type/subtype pair that is emitted to the file.
struct|struct
name|MachOHeader
block|{
name|uint32_t
name|magic
decl_stmt|;
comment|// mach magic number identifier
name|uint32_t
name|filetype
decl_stmt|;
comment|// type of file
name|uint32_t
name|ncmds
decl_stmt|;
comment|// number of load commands
name|uint32_t
name|sizeofcmds
decl_stmt|;
comment|// the size of all the load commands
name|uint32_t
name|flags
decl_stmt|;
comment|// flags
name|uint32_t
name|reserved
decl_stmt|;
comment|// 64-bit only
comment|/// HeaderData - The actual data for the header which we are building
comment|/// up for emission to the file.
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|HeaderData
expr_stmt|;
comment|// Constants for the filetype field
comment|// see<mach-o/loader.h> for additional info on the various types
enum|enum
block|{
name|MH_OBJECT
init|=
literal|1
block|,
comment|// relocatable object file
name|MH_EXECUTE
init|=
literal|2
block|,
comment|// demand paged executable file
name|MH_FVMLIB
init|=
literal|3
block|,
comment|// fixed VM shared library file
name|MH_CORE
init|=
literal|4
block|,
comment|// core file
name|MH_PRELOAD
init|=
literal|5
block|,
comment|// preloaded executable file
name|MH_DYLIB
init|=
literal|6
block|,
comment|// dynamically bound shared library
name|MH_DYLINKER
init|=
literal|7
block|,
comment|// dynamic link editor
name|MH_BUNDLE
init|=
literal|8
block|,
comment|// dynamically bound bundle file
name|MH_DYLIB_STUB
init|=
literal|9
block|,
comment|// shared library stub for static linking only
name|MH_DSYM
init|=
literal|10
comment|// companion file wiht only debug sections
block|}
enum|;
comment|// Constants for the flags field
enum|enum
block|{
name|MH_NOUNDEFS
init|=
literal|1
operator|<<
literal|0
block|,
comment|// the object file has no undefined references
name|MH_INCRLINK
init|=
literal|1
operator|<<
literal|1
block|,
comment|// the object file is the output of an incremental link against
comment|// a base file and cannot be link edited again
name|MH_DYLDLINK
init|=
literal|1
operator|<<
literal|2
block|,
comment|// the object file is input for the dynamic linker and cannot be
comment|// statically link edited again.
name|MH_BINDATLOAD
init|=
literal|1
operator|<<
literal|3
block|,
comment|// the object file's undefined references are bound by the
comment|// dynamic linker when loaded.
name|MH_PREBOUND
init|=
literal|1
operator|<<
literal|4
block|,
comment|// the file has its dynamic undefined references prebound
name|MH_SPLIT_SEGS
init|=
literal|1
operator|<<
literal|5
block|,
comment|// the file has its read-only and read-write segments split
comment|// see<mach/shared_memory_server.h>
name|MH_LAZY_INIT
init|=
literal|1
operator|<<
literal|6
block|,
comment|// the shared library init routine is to be run lazily via
comment|// catching memory faults to its writable segments (obsolete)
name|MH_TWOLEVEL
init|=
literal|1
operator|<<
literal|7
block|,
comment|// the image is using two-level namespace bindings
name|MH_FORCE_FLAT
init|=
literal|1
operator|<<
literal|8
block|,
comment|// the executable is forcing all images to use flat namespace
comment|// bindings.
name|MH_NOMULTIDEFS
init|=
literal|1
operator|<<
literal|8
block|,
comment|// this umbrella guarantees no multiple definitions of symbols
comment|// in its sub-images so the two-level namespace hints can
comment|// always be used.
name|MH_NOFIXPREBINDING
init|=
literal|1
operator|<<
literal|10
block|,
comment|// do not have dyld notify the prebidning agent about this
comment|// executable.
name|MH_PREBINDABLE
init|=
literal|1
operator|<<
literal|11
block|,
comment|// the binary is not prebound but can have its prebinding
comment|// redone.  only used when MH_PREBOUND is not set.
name|MH_ALLMODSBOUND
init|=
literal|1
operator|<<
literal|12
block|,
comment|// indicates that this binary binds to all two-level namespace
comment|// modules of its dependent libraries.  Only used when
comment|// MH_PREBINDABLE and MH_TWOLEVEL are both set.
name|MH_SUBSECTIONS_VIA_SYMBOLS
init|=
literal|1
operator|<<
literal|13
block|,
comment|// safe to divide up the sections into sub-sections via symbols
comment|// for dead code stripping.
name|MH_CANONICAL
init|=
literal|1
operator|<<
literal|14
block|,
comment|// the binary has been canonicalized via the unprebind operation
name|MH_WEAK_DEFINES
init|=
literal|1
operator|<<
literal|15
block|,
comment|// the final linked image contains external weak symbols
name|MH_BINDS_TO_WEAK
init|=
literal|1
operator|<<
literal|16
block|,
comment|// the final linked image uses weak symbols
name|MH_ALLOW_STACK_EXECUTION
init|=
literal|1
operator|<<
literal|17
comment|// When this bit is set, all stacks in the task will be given
comment|// stack execution privilege.  Only used in MH_EXECUTE filetype
block|}
enum|;
name|MachOHeader
argument_list|()
operator|:
name|magic
argument_list|(
literal|0
argument_list|)
operator|,
name|filetype
argument_list|(
literal|0
argument_list|)
operator|,
name|ncmds
argument_list|(
literal|0
argument_list|)
operator|,
name|sizeofcmds
argument_list|(
literal|0
argument_list|)
operator|,
name|flags
argument_list|(
literal|0
argument_list|)
operator|,
name|reserved
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// cmdSize - This routine returns the size of the MachOSection as written
comment|/// to disk, depending on whether the destination is a 64 bit Mach-O file.
name|unsigned
name|cmdSize
argument_list|(
argument|bool is64Bit
argument_list|)
specifier|const
block|{
if|if
condition|(
name|is64Bit
condition|)
return|return
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
return|;
else|else
return|return
literal|7
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
return|;
block|}
comment|/// setMagic - This routine sets the appropriate value for the 'magic'
comment|/// field based on pointer size and endianness.
name|void
name|setMagic
parameter_list|(
name|bool
name|isLittleEndian
parameter_list|,
name|bool
name|is64Bit
parameter_list|)
block|{
if|if
condition|(
name|isLittleEndian
condition|)
if|if
condition|(
name|is64Bit
condition|)
name|magic
operator|=
literal|0xcffaedfe
expr_stmt|;
else|else
name|magic
operator|=
literal|0xcefaedfe
expr_stmt|;
elseif|else
if|if
condition|(
name|is64Bit
condition|)
name|magic
operator|=
literal|0xfeedfacf
expr_stmt|;
else|else
name|magic
operator|=
literal|0xfeedface
expr_stmt|;
block|}
block|}
struct|;
comment|// end struct MachOHeader
comment|/// MachOSegment - This struct contains the necessary information to
comment|/// emit the load commands for each section in the file.
struct|struct
name|MachOSegment
block|{
name|uint32_t
name|cmd
decl_stmt|;
comment|// LC_SEGMENT or LC_SEGMENT_64
name|uint32_t
name|cmdsize
decl_stmt|;
comment|// Total size of this struct and section commands
name|std
operator|::
name|string
name|segname
expr_stmt|;
comment|// segment name
name|uint64_t
name|vmaddr
decl_stmt|;
comment|// address of this segment
name|uint64_t
name|vmsize
decl_stmt|;
comment|// size of this segment, may be larger than filesize
name|uint64_t
name|fileoff
decl_stmt|;
comment|// offset in file
name|uint64_t
name|filesize
decl_stmt|;
comment|// amount to read from file
name|uint32_t
name|maxprot
decl_stmt|;
comment|// maximum VM protection
name|uint32_t
name|initprot
decl_stmt|;
comment|// initial VM protection
name|uint32_t
name|nsects
decl_stmt|;
comment|// number of sections in this segment
name|uint32_t
name|flags
decl_stmt|;
comment|// flags
comment|// The following constants are getting pulled in by one of the
comment|// system headers, which creates a neat clash with the enum.
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VM_PROT_NONE
argument_list|)
define|#
directive|define
name|VM_PROT_NONE
value|0x00
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VM_PROT_READ
argument_list|)
define|#
directive|define
name|VM_PROT_READ
value|0x01
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VM_PROT_WRITE
argument_list|)
define|#
directive|define
name|VM_PROT_WRITE
value|0x02
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VM_PROT_EXECUTE
argument_list|)
define|#
directive|define
name|VM_PROT_EXECUTE
value|0x04
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VM_PROT_ALL
argument_list|)
define|#
directive|define
name|VM_PROT_ALL
value|0x07
endif|#
directive|endif
comment|// Constants for the vm protection fields
comment|// see<mach-o/vm_prot.h>
enum|enum
block|{
name|SEG_VM_PROT_NONE
init|=
name|VM_PROT_NONE
block|,
name|SEG_VM_PROT_READ
init|=
name|VM_PROT_READ
block|,
comment|// read permission
name|SEG_VM_PROT_WRITE
init|=
name|VM_PROT_WRITE
block|,
comment|// write permission
name|SEG_VM_PROT_EXECUTE
init|=
name|VM_PROT_EXECUTE
block|,
name|SEG_VM_PROT_ALL
init|=
name|VM_PROT_ALL
block|}
enum|;
comment|// Constants for the cmd field
comment|// see<mach-o/loader.h>
enum|enum
block|{
name|LC_SEGMENT
init|=
literal|0x01
block|,
comment|// segment of this file to be mapped
name|LC_SEGMENT_64
init|=
literal|0x19
comment|// 64-bit segment of this file to be mapped
block|}
enum|;
comment|/// cmdSize - This routine returns the size of the MachOSection as written
comment|/// to disk, depending on whether the destination is a 64 bit Mach-O file.
name|unsigned
name|cmdSize
argument_list|(
name|bool
name|is64Bit
argument_list|)
decl|const
block|{
if|if
condition|(
name|is64Bit
condition|)
return|return
literal|6
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|+
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|+
literal|16
return|;
else|else
return|return
literal|10
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|+
literal|16
return|;
comment|// addresses only 32 bits
block|}
name|MachOSegment
argument_list|(
argument|const std::string&seg
argument_list|,
argument|bool is64Bit
argument_list|)
block|:
name|cmd
argument_list|(
name|is64Bit
condition|?
name|LC_SEGMENT_64
else|:
name|LC_SEGMENT
argument_list|)
operator|,
name|cmdsize
argument_list|(
literal|0
argument_list|)
operator|,
name|segname
argument_list|(
name|seg
argument_list|)
operator|,
name|vmaddr
argument_list|(
literal|0
argument_list|)
operator|,
name|vmsize
argument_list|(
literal|0
argument_list|)
operator|,
name|fileoff
argument_list|(
literal|0
argument_list|)
operator|,
name|filesize
argument_list|(
literal|0
argument_list|)
operator|,
name|maxprot
argument_list|(
name|VM_PROT_ALL
argument_list|)
operator|,
name|initprot
argument_list|(
name|VM_PROT_ALL
argument_list|)
operator|,
name|nsects
argument_list|(
literal|0
argument_list|)
operator|,
name|flags
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
struct|;
comment|/// MachOSection - This struct contains information about each section in a
comment|/// particular segment that is emitted to the file.  This is eventually
comment|/// turned into the SectionCommand in the load command for a particlar
comment|/// segment.
name|struct
name|MachOSection
range|:
name|public
name|BinaryObject
block|{
name|std
operator|::
name|string
name|sectname
block|;
comment|// name of this section,
name|std
operator|::
name|string
name|segname
block|;
comment|// segment this section goes in
name|uint64_t
name|addr
block|;
comment|// memory address of this section
name|uint32_t
name|offset
block|;
comment|// file offset of this section
name|uint32_t
name|align
block|;
comment|// section alignment (power of 2)
name|uint32_t
name|reloff
block|;
comment|// file offset of relocation entries
name|uint32_t
name|nreloc
block|;
comment|// number of relocation entries
name|uint32_t
name|flags
block|;
comment|// flags (section type and attributes)
name|uint32_t
name|reserved1
block|;
comment|// reserved (for offset or index)
name|uint32_t
name|reserved2
block|;
comment|// reserved (for count or sizeof)
name|uint32_t
name|reserved3
block|;
comment|// reserved (64 bit only)
comment|/// A unique number for this section, which will be used to match symbols
comment|/// to the correct section.
name|uint32_t
name|Index
block|;
comment|/// RelocBuffer - A buffer to hold the mach-o relocations before we write
comment|/// them out at the appropriate location in the file.
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|RelocBuffer
block|;
comment|// Constants for the section types (low 8 bits of flags field)
comment|// see<mach-o/loader.h>
block|enum
block|{
name|S_REGULAR
operator|=
literal|0
block|,
comment|// regular section
name|S_ZEROFILL
operator|=
literal|1
block|,
comment|// zero fill on demand section
name|S_CSTRING_LITERALS
operator|=
literal|2
block|,
comment|// section with only literal C strings
name|S_4BYTE_LITERALS
operator|=
literal|3
block|,
comment|// section with only 4 byte literals
name|S_8BYTE_LITERALS
operator|=
literal|4
block|,
comment|// section with only 8 byte literals
name|S_LITERAL_POINTERS
operator|=
literal|5
block|,
comment|// section with only pointers to literals
name|S_NON_LAZY_SYMBOL_POINTERS
operator|=
literal|6
block|,
comment|// section with only non-lazy symbol pointers
name|S_LAZY_SYMBOL_POINTERS
operator|=
literal|7
block|,
comment|// section with only lazy symbol pointers
name|S_SYMBOL_STUBS
operator|=
literal|8
block|,
comment|// section with only symbol stubs
comment|// byte size of stub in the reserved2 field
name|S_MOD_INIT_FUNC_POINTERS
operator|=
literal|9
block|,
comment|// section with only function pointers for initialization
name|S_MOD_TERM_FUNC_POINTERS
operator|=
literal|10
block|,
comment|// section with only function pointers for termination
name|S_COALESCED
operator|=
literal|11
block|,
comment|// section contains symbols that are coalesced
name|S_GB_ZEROFILL
operator|=
literal|12
block|,
comment|// zero fill on demand section (that can be larger than 4GB)
name|S_INTERPOSING
operator|=
literal|13
block|,
comment|// section with only pairs of function pointers for interposing
name|S_16BYTE_LITERALS
operator|=
literal|14
comment|// section with only 16 byte literals
block|}
block|;
comment|// Constants for the section flags (high 24 bits of flags field)
comment|// see<mach-o/loader.h>
block|enum
block|{
name|S_ATTR_PURE_INSTRUCTIONS
operator|=
literal|1
operator|<<
literal|31
block|,
comment|// section contains only true machine instructions
name|S_ATTR_NO_TOC
operator|=
literal|1
operator|<<
literal|30
block|,
comment|// section contains coalesced symbols that are not to be in a
comment|// ranlib table of contents
name|S_ATTR_STRIP_STATIC_SYMS
operator|=
literal|1
operator|<<
literal|29
block|,
comment|// ok to strip static symbols in this section in files with the
comment|// MY_DYLDLINK flag
name|S_ATTR_NO_DEAD_STRIP
operator|=
literal|1
operator|<<
literal|28
block|,
comment|// no dead stripping
name|S_ATTR_LIVE_SUPPORT
operator|=
literal|1
operator|<<
literal|27
block|,
comment|// blocks are live if they reference live blocks
name|S_ATTR_SELF_MODIFYING_CODE
operator|=
literal|1
operator|<<
literal|26
block|,
comment|// used with i386 code stubs written on by dyld
name|S_ATTR_DEBUG
operator|=
literal|1
operator|<<
literal|25
block|,
comment|// a debug section
name|S_ATTR_SOME_INSTRUCTIONS
operator|=
literal|1
operator|<<
literal|10
block|,
comment|// section contains some machine instructions
name|S_ATTR_EXT_RELOC
operator|=
literal|1
operator|<<
literal|9
block|,
comment|// section has external relocation entries
name|S_ATTR_LOC_RELOC
operator|=
literal|1
operator|<<
literal|8
comment|// section has local relocation entries
block|}
block|;
comment|/// cmdSize - This routine returns the size of the MachOSection as written
comment|/// to disk, depending on whether the destination is a 64 bit Mach-O file.
name|unsigned
name|cmdSize
argument_list|(
argument|bool is64Bit
argument_list|)
specifier|const
block|{
if|if
condition|(
name|is64Bit
condition|)
return|return
literal|7
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|+
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|+
literal|32
return|;
else|else
return|return
literal|9
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|+
literal|32
return|;
comment|// addresses only 32 bits
block|}
name|MachOSection
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|seg
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|sect
argument_list|)
operator|:
name|BinaryObject
argument_list|()
block|,
name|sectname
argument_list|(
name|sect
argument_list|)
block|,
name|segname
argument_list|(
name|seg
argument_list|)
block|,
name|addr
argument_list|(
literal|0
argument_list|)
block|,
name|offset
argument_list|(
literal|0
argument_list|)
block|,
name|align
argument_list|(
literal|2
argument_list|)
block|,
name|reloff
argument_list|(
literal|0
argument_list|)
block|,
name|nreloc
argument_list|(
literal|0
argument_list|)
block|,
name|flags
argument_list|(
literal|0
argument_list|)
block|,
name|reserved1
argument_list|(
literal|0
argument_list|)
block|,
name|reserved2
argument_list|(
literal|0
argument_list|)
block|,
name|reserved3
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
decl_stmt|;
comment|// end struct MachOSection
comment|/// MachOSymTab - This struct contains information about the offsets and
comment|/// size of symbol table information.
comment|/// segment.
struct|struct
name|MachODySymTab
block|{
name|uint32_t
name|cmd
decl_stmt|;
comment|// LC_DYSYMTAB
name|uint32_t
name|cmdsize
decl_stmt|;
comment|// sizeof(MachODySymTab)
name|uint32_t
name|ilocalsym
decl_stmt|;
comment|// index to local symbols
name|uint32_t
name|nlocalsym
decl_stmt|;
comment|// number of local symbols
name|uint32_t
name|iextdefsym
decl_stmt|;
comment|// index to externally defined symbols
name|uint32_t
name|nextdefsym
decl_stmt|;
comment|// number of externally defined symbols
name|uint32_t
name|iundefsym
decl_stmt|;
comment|// index to undefined symbols
name|uint32_t
name|nundefsym
decl_stmt|;
comment|// number of undefined symbols
name|uint32_t
name|tocoff
decl_stmt|;
comment|// file offset to table of contents
name|uint32_t
name|ntoc
decl_stmt|;
comment|// number of entries in table of contents
name|uint32_t
name|modtaboff
decl_stmt|;
comment|// file offset to module table
name|uint32_t
name|nmodtab
decl_stmt|;
comment|// number of module table entries
name|uint32_t
name|extrefsymoff
decl_stmt|;
comment|// offset to referenced symbol table
name|uint32_t
name|nextrefsyms
decl_stmt|;
comment|// number of referenced symbol table entries
name|uint32_t
name|indirectsymoff
decl_stmt|;
comment|// file offset to the indirect symbol table
name|uint32_t
name|nindirectsyms
decl_stmt|;
comment|// number of indirect symbol table entries
name|uint32_t
name|extreloff
decl_stmt|;
comment|// offset to external relocation entries
name|uint32_t
name|nextrel
decl_stmt|;
comment|// number of external relocation entries
name|uint32_t
name|locreloff
decl_stmt|;
comment|// offset to local relocation entries
name|uint32_t
name|nlocrel
decl_stmt|;
comment|// number of local relocation entries
comment|// Constants for the cmd field
comment|// see<mach-o/loader.h>
enum|enum
block|{
name|LC_DYSYMTAB
init|=
literal|0x0B
comment|// dynamic link-edit symbol table info
block|}
enum|;
name|MachODySymTab
argument_list|()
operator|:
name|cmd
argument_list|(
name|LC_DYSYMTAB
argument_list|)
operator|,
name|cmdsize
argument_list|(
literal|20
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
argument_list|)
operator|,
name|ilocalsym
argument_list|(
literal|0
argument_list|)
operator|,
name|nlocalsym
argument_list|(
literal|0
argument_list|)
operator|,
name|iextdefsym
argument_list|(
literal|0
argument_list|)
operator|,
name|nextdefsym
argument_list|(
literal|0
argument_list|)
operator|,
name|iundefsym
argument_list|(
literal|0
argument_list|)
operator|,
name|nundefsym
argument_list|(
literal|0
argument_list|)
operator|,
name|tocoff
argument_list|(
literal|0
argument_list|)
operator|,
name|ntoc
argument_list|(
literal|0
argument_list|)
operator|,
name|modtaboff
argument_list|(
literal|0
argument_list|)
operator|,
name|nmodtab
argument_list|(
literal|0
argument_list|)
operator|,
name|extrefsymoff
argument_list|(
literal|0
argument_list|)
operator|,
name|nextrefsyms
argument_list|(
literal|0
argument_list|)
operator|,
name|indirectsymoff
argument_list|(
literal|0
argument_list|)
operator|,
name|nindirectsyms
argument_list|(
literal|0
argument_list|)
operator|,
name|extreloff
argument_list|(
literal|0
argument_list|)
operator|,
name|nextrel
argument_list|(
literal|0
argument_list|)
operator|,
name|locreloff
argument_list|(
literal|0
argument_list|)
operator|,
name|nlocrel
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|// end struct MachODySymTab
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

