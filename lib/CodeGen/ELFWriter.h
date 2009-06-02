begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ELFWriter.h - Target-independent ELF writer support -----*- C++ -*-===//
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
comment|// This file defines the ELFWriter class.
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
name|ELFWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|ELFWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MachineCodeEmitter
decl_stmt|;
name|class
name|ELFCodeEmitter
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// ELFWriter - This class implements the common target-independent code for
comment|/// writing ELF files.  Targets should derive a class from this to
comment|/// parameterize the output format.
comment|///
name|class
name|ELFWriter
range|:
name|public
name|MachineFunctionPass
block|{
name|friend
name|class
name|ELFCodeEmitter
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|MachineCodeEmitter
operator|&
name|getMachineCodeEmitter
argument_list|()
specifier|const
block|{
return|return
operator|*
operator|(
name|MachineCodeEmitter
operator|*
operator|)
name|MCE
return|;
block|}
name|ELFWriter
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
operator|~
name|ELFWriter
argument_list|()
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|DataBuffer
expr_stmt|;
name|protected
operator|:
comment|/// Output stream to send the resultant object file to.
comment|///
name|raw_ostream
operator|&
name|O
decl_stmt|;
comment|/// Target machine description.
comment|///
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|/// Mang - The object used to perform name mangling for this module.
comment|///
name|Mangler
modifier|*
name|Mang
decl_stmt|;
comment|/// MCE - The MachineCodeEmitter object that we are exposing to emit machine
comment|/// code for functions to the .o file.
name|ELFCodeEmitter
modifier|*
name|MCE
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Properties to be set by the derived class ctor, used to configure the
comment|// ELFWriter.
comment|// e_machine - This field is the target specific value to emit as the
comment|// e_machine member of the ELF header.
name|unsigned
name|short
name|e_machine
decl_stmt|;
comment|// e_flags - The machine flags for the target.  This defaults to zero.
name|unsigned
name|e_flags
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Properties inferred automatically from the target machine.
comment|//
comment|/// is64Bit/isLittleEndian - This information is inferred from the target
comment|/// machine directly, indicating whether to emit a 32- or 64-bit ELF file.
name|bool
name|is64Bit
decl_stmt|,
name|isLittleEndian
decl_stmt|;
comment|/// doInitialization - Emit the file header and all of the global variables
comment|/// for the module to the ELF file.
name|bool
name|doInitialization
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
name|bool
name|runOnMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// doFinalization - Now that the module has been completely processed, emit
comment|/// the ELF file to 'O'.
name|bool
name|doFinalization
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
name|private
label|:
comment|// The buffer we accumulate the file header into.  Note that this should be
comment|// changed into something much more efficient later (and the bitcode writer
comment|// as well!).
name|DataBuffer
name|FileHeader
decl_stmt|;
comment|/// ELFSection - This struct contains information about each section that is
comment|/// emitted to the file.  This is eventually turned into the section header
comment|/// table at the end of the file.
struct|struct
name|ELFSection
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|// Name of the section.
name|unsigned
name|NameIdx
decl_stmt|;
comment|// Index in .shstrtab of name, once emitted.
name|unsigned
name|Type
decl_stmt|;
name|unsigned
name|Flags
decl_stmt|;
name|uint64_t
name|Addr
decl_stmt|;
name|unsigned
name|Offset
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
name|unsigned
name|Link
decl_stmt|;
name|unsigned
name|Info
decl_stmt|;
name|unsigned
name|Align
decl_stmt|;
name|unsigned
name|EntSize
decl_stmt|;
comment|/// SectionIdx - The number of the section in the Section Table.
comment|///
name|unsigned
name|short
name|SectionIdx
decl_stmt|;
comment|/// SectionData - The actual data for this section which we are building
comment|/// up for emission to the file.
name|DataBuffer
name|SectionData
decl_stmt|;
enum|enum
block|{
name|SHT_NULL
init|=
literal|0
block|,
name|SHT_PROGBITS
init|=
literal|1
block|,
name|SHT_SYMTAB
init|=
literal|2
block|,
name|SHT_STRTAB
init|=
literal|3
block|,
name|SHT_RELA
init|=
literal|4
block|,
name|SHT_HASH
init|=
literal|5
block|,
name|SHT_DYNAMIC
init|=
literal|6
block|,
name|SHT_NOTE
init|=
literal|7
block|,
name|SHT_NOBITS
init|=
literal|8
block|,
name|SHT_REL
init|=
literal|9
block|,
name|SHT_SHLIB
init|=
literal|10
block|,
name|SHT_DYNSYM
init|=
literal|11
block|}
enum|;
enum|enum
block|{
name|SHN_UNDEF
init|=
literal|0
block|,
name|SHN_ABS
init|=
literal|0xFFF1
block|,
name|SHN_COMMON
init|=
literal|0xFFF2
block|}
enum|;
enum|enum
block|{
comment|// SHF - ELF Section Header Flags
name|SHF_WRITE
init|=
literal|1
operator|<<
literal|0
block|,
comment|// Writable
name|SHF_ALLOC
init|=
literal|1
operator|<<
literal|1
block|,
comment|// Mapped into the process addr space
name|SHF_EXECINSTR
init|=
literal|1
operator|<<
literal|2
block|,
comment|// Executable
name|SHF_MERGE
init|=
literal|1
operator|<<
literal|4
block|,
comment|// Might be merged if equal
name|SHF_STRINGS
init|=
literal|1
operator|<<
literal|5
block|,
comment|// Contains null-terminated strings
name|SHF_INFO_LINK
init|=
literal|1
operator|<<
literal|6
block|,
comment|// 'sh_info' contains SHT index
name|SHF_LINK_ORDER
init|=
literal|1
operator|<<
literal|7
block|,
comment|// Preserve order after combining
name|SHF_OS_NONCONFORMING
init|=
literal|1
operator|<<
literal|8
block|,
comment|// nonstandard OS support required
name|SHF_GROUP
init|=
literal|1
operator|<<
literal|9
block|,
comment|// Section is a member of a group
name|SHF_TLS
init|=
literal|1
operator|<<
literal|10
comment|// Section holds thread-local data
block|}
enum|;
name|ELFSection
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
operator|:
name|Name
argument_list|(
name|name
argument_list|)
operator|,
name|Type
argument_list|(
literal|0
argument_list|)
operator|,
name|Flags
argument_list|(
literal|0
argument_list|)
operator|,
name|Addr
argument_list|(
literal|0
argument_list|)
operator|,
name|Offset
argument_list|(
literal|0
argument_list|)
operator|,
name|Size
argument_list|(
literal|0
argument_list|)
operator|,
name|Link
argument_list|(
literal|0
argument_list|)
operator|,
name|Info
argument_list|(
literal|0
argument_list|)
operator|,
name|Align
argument_list|(
literal|0
argument_list|)
operator|,
name|EntSize
argument_list|(
literal|0
argument_list|)
block|{       }
block|}
struct|;
comment|/// SectionList - This is the list of sections that we have emitted to the
comment|/// file.  Once the file has been completely built, the section header table
comment|/// is constructed from this info.
name|std
operator|::
name|list
operator|<
name|ELFSection
operator|>
name|SectionList
expr_stmt|;
name|unsigned
name|NumSections
decl_stmt|;
comment|// Always = SectionList.size()
comment|/// SectionLookup - This is a mapping from section name to section number in
comment|/// the SectionList.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|ELFSection
operator|*
operator|>
name|SectionLookup
expr_stmt|;
comment|/// getSection - Return the section with the specified name, creating a new
comment|/// section if one does not already exist.
name|ELFSection
modifier|&
name|getSection
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|unsigned
name|Type
argument_list|,
name|unsigned
name|Flags
operator|=
literal|0
argument_list|)
block|{
name|ELFSection
modifier|*
modifier|&
name|SN
init|=
name|SectionLookup
index|[
name|Name
index|]
decl_stmt|;
if|if
condition|(
name|SN
condition|)
return|return
operator|*
name|SN
return|;
name|SectionList
operator|.
name|push_back
argument_list|(
name|Name
argument_list|)
expr_stmt|;
name|SN
operator|=
operator|&
name|SectionList
operator|.
name|back
argument_list|()
expr_stmt|;
name|SN
operator|->
name|SectionIdx
operator|=
name|NumSections
operator|++
expr_stmt|;
name|SN
operator|->
name|Type
operator|=
name|Type
expr_stmt|;
name|SN
operator|->
name|Flags
operator|=
name|Flags
expr_stmt|;
return|return
operator|*
name|SN
return|;
block|}
name|ELFSection
modifier|&
name|getDataSection
parameter_list|()
block|{
return|return
name|getSection
argument_list|(
literal|".data"
argument_list|,
name|ELFSection
operator|::
name|SHT_PROGBITS
argument_list|,
name|ELFSection
operator|::
name|SHF_WRITE
operator||
name|ELFSection
operator|::
name|SHF_ALLOC
argument_list|)
return|;
block|}
name|ELFSection
modifier|&
name|getBSSSection
parameter_list|()
block|{
return|return
name|getSection
argument_list|(
literal|".bss"
argument_list|,
name|ELFSection
operator|::
name|SHT_NOBITS
argument_list|,
name|ELFSection
operator|::
name|SHF_WRITE
operator||
name|ELFSection
operator|::
name|SHF_ALLOC
argument_list|)
return|;
block|}
comment|/// ELFSym - This struct contains information about each symbol that is
comment|/// added to logical symbol table for the module.  This is eventually
comment|/// turned into a real symbol table in the file.
struct|struct
name|ELFSym
block|{
specifier|const
name|GlobalValue
modifier|*
name|GV
decl_stmt|;
comment|// The global value this corresponds to.
name|unsigned
name|NameIdx
decl_stmt|;
comment|// Index in .strtab of name, once emitted.
name|uint64_t
name|Value
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
name|unsigned
name|char
name|Info
decl_stmt|;
name|unsigned
name|char
name|Other
decl_stmt|;
name|unsigned
name|short
name|SectionIdx
decl_stmt|;
enum|enum
block|{
name|STB_LOCAL
init|=
literal|0
block|,
name|STB_GLOBAL
init|=
literal|1
block|,
name|STB_WEAK
init|=
literal|2
block|}
enum|;
enum|enum
block|{
name|STT_NOTYPE
init|=
literal|0
block|,
name|STT_OBJECT
init|=
literal|1
block|,
name|STT_FUNC
init|=
literal|2
block|,
name|STT_SECTION
init|=
literal|3
block|,
name|STT_FILE
init|=
literal|4
block|}
enum|;
name|ELFSym
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|gv
argument_list|)
operator|:
name|GV
argument_list|(
name|gv
argument_list|)
operator|,
name|Value
argument_list|(
literal|0
argument_list|)
operator|,
name|Size
argument_list|(
literal|0
argument_list|)
operator|,
name|Info
argument_list|(
literal|0
argument_list|)
operator|,
name|Other
argument_list|(
literal|0
argument_list|)
operator|,
name|SectionIdx
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|SetBind
argument_list|(
argument|unsigned X
argument_list|)
block|{
name|assert
argument_list|(
name|X
operator|==
operator|(
name|X
operator|&
literal|0xF
operator|)
operator|&&
literal|"Bind value out of range!"
argument_list|)
block|;
name|Info
operator|=
operator|(
name|Info
operator|&
literal|0x0F
operator|)
operator||
operator|(
name|X
operator|<<
literal|4
operator|)
block|;       }
name|void
name|SetType
argument_list|(
argument|unsigned X
argument_list|)
block|{
name|assert
argument_list|(
name|X
operator|==
operator|(
name|X
operator|&
literal|0xF
operator|)
operator|&&
literal|"Type value out of range!"
argument_list|)
block|;
name|Info
operator|=
operator|(
name|Info
operator|&
literal|0xF0
operator|)
operator||
name|X
block|;       }
block|}
struct|;
comment|/// SymbolTable - This is the list of symbols we have emitted to the file.
comment|/// This actually gets rearranged before emission to the file (to put the
comment|/// local symbols first in the list).
name|std
operator|::
name|vector
operator|<
name|ELFSym
operator|>
name|SymbolTable
expr_stmt|;
comment|// As we complete the ELF file, we need to update fields in the ELF header
comment|// (e.g. the location of the section table).  These members keep track of
comment|// the offset in ELFHeader of these various pieces to update and other
comment|// locations in the file.
name|unsigned
name|ELFHeader_e_shoff_Offset
decl_stmt|;
comment|// e_shoff    in ELF header.
name|unsigned
name|ELFHeader_e_shstrndx_Offset
decl_stmt|;
comment|// e_shstrndx in ELF header.
name|unsigned
name|ELFHeader_e_shnum_Offset
decl_stmt|;
comment|// e_shnum    in ELF header.
name|private
label|:
name|void
name|EmitGlobal
parameter_list|(
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
function_decl|;
name|void
name|EmitSymbolTable
parameter_list|()
function_decl|;
name|void
name|EmitSectionTableStringTable
parameter_list|()
function_decl|;
name|void
name|OutputSectionsAndSectionTable
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

