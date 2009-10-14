begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MachOWriter.h - Target-independent Mach-O writer support --*- C++ -*-===//
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
comment|// This file defines the MachOWriter class.
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
name|MACHOWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|MACHOWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|Constant
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineRelocation
decl_stmt|;
name|class
name|MachOCodeEmitter
decl_stmt|;
struct_decl|struct
name|MachODySymTab
struct_decl|;
struct_decl|struct
name|MachOHeader
struct_decl|;
struct_decl|struct
name|MachOSection
struct_decl|;
struct_decl|struct
name|MachOSym
struct_decl|;
name|class
name|TargetData
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|ObjectCodeEmitter
decl_stmt|;
name|class
name|OutputBuffer
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MachOWriter - This class implements the common target-independent code for
comment|/// writing Mach-O files.  Targets should derive a class from this to
comment|/// parameterize the output format.
comment|///
name|class
name|MachOWriter
range|:
name|public
name|MachineFunctionPass
block|{
name|friend
name|class
name|MachOCodeEmitter
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|ObjectCodeEmitter
operator|*
name|getObjectCodeEmitter
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|ObjectCodeEmitter
operator|*
operator|>
operator|(
name|MachOCE
operator|)
return|;
block|}
name|MachOWriter
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
name|virtual
operator|~
name|MachOWriter
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"Mach-O Writer"
return|;
block|}
name|protected
operator|:
comment|/// Output stream to send the resultant object file to.
comment|///
name|raw_ostream
operator|&
name|O
block|;
comment|/// Target machine description.
comment|///
name|TargetMachine
operator|&
name|TM
block|;
comment|/// Mang - The object used to perform name mangling for this module.
comment|///
name|Mangler
operator|*
name|Mang
block|;
comment|/// MachOCE - The MachineCodeEmitter object that we are exposing to emit
comment|/// machine code for functions to the .o file.
name|MachOCodeEmitter
operator|*
name|MachOCE
block|;
comment|/// is64Bit/isLittleEndian - This information is inferred from the target
comment|/// machine directly, indicating what header values and flags to set.
name|bool
name|is64Bit
block|,
name|isLittleEndian
block|;
comment|// Target Asm Info
specifier|const
name|MCAsmInfo
operator|*
name|MAI
block|;
comment|/// Header - An instance of MachOHeader that we will update while we build
comment|/// the file, and then emit during finalization.
name|MachOHeader
name|Header
block|;
comment|/// doInitialization - Emit the file header and all of the global variables
comment|/// for the module to the Mach-O file.
name|bool
name|doInitialization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
comment|/// doFinalization - Now that the module has been completely processed, emit
comment|/// the Mach-O file to 'O'.
name|bool
name|doFinalization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|private
operator|:
comment|/// SectionList - This is the list of sections that we have emitted to the
comment|/// file.  Once the file has been completely built, the segment load command
comment|/// SectionCommands are constructed from this info.
name|std
operator|::
name|vector
operator|<
name|MachOSection
operator|*
operator|>
name|SectionList
block|;
comment|/// SectionLookup - This is a mapping from section name to SectionList entry
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|MachOSection
operator|*
operator|>
name|SectionLookup
block|;
comment|/// GVSection - This is a mapping from a GlobalValue to a MachOSection,
comment|/// to aid in emitting relocations.
name|std
operator|::
name|map
operator|<
name|GlobalValue
operator|*
block|,
name|MachOSection
operator|*
operator|>
name|GVSection
block|;
comment|/// GVOffset - This is a mapping from a GlobalValue to an offset from the
comment|/// start of the section in which the GV resides, to aid in emitting
comment|/// relocations.
name|std
operator|::
name|map
operator|<
name|GlobalValue
operator|*
block|,
name|intptr_t
operator|>
name|GVOffset
block|;
comment|/// getSection - Return the section with the specified name, creating a new
comment|/// section if one does not already exist.
name|MachOSection
operator|*
name|getSection
argument_list|(
argument|const std::string&seg
argument_list|,
argument|const std::string&sect
argument_list|,
argument|unsigned Flags =
literal|0
argument_list|)
block|;
comment|/// getTextSection - Return text section with different flags for code/data
name|MachOSection
operator|*
name|getTextSection
argument_list|(
argument|bool isCode = true
argument_list|)
block|;
name|MachOSection
operator|*
name|getDataSection
argument_list|()
block|{
return|return
name|getSection
argument_list|(
literal|"__DATA"
argument_list|,
literal|"__data"
argument_list|)
return|;
block|}
name|MachOSection
operator|*
name|getBSSSection
argument_list|()
block|;
name|MachOSection
operator|*
name|getConstSection
argument_list|(
name|Constant
operator|*
name|C
argument_list|)
block|;
name|MachOSection
operator|*
name|getJumpTableSection
argument_list|()
block|;
comment|/// MachOSymTab - This struct contains information about the offsets and
comment|/// size of symbol table information.
comment|/// segment.
block|struct
name|MachOSymTab
block|{
name|uint32_t
name|cmd
block|;
comment|// LC_SYMTAB
name|uint32_t
name|cmdsize
block|;
comment|// sizeof( MachOSymTab )
name|uint32_t
name|symoff
block|;
comment|// symbol table offset
name|uint32_t
name|nsyms
block|;
comment|// number of symbol table entries
name|uint32_t
name|stroff
block|;
comment|// string table offset
name|uint32_t
name|strsize
block|;
comment|// string table size in bytes
comment|// Constants for the cmd field
comment|// see<mach-o/loader.h>
block|enum
block|{
name|LC_SYMTAB
operator|=
literal|0x02
comment|// link-edit stab symbol table info
block|}
block|;
name|MachOSymTab
argument_list|()
operator|:
name|cmd
argument_list|(
name|LC_SYMTAB
argument_list|)
block|,
name|cmdsize
argument_list|(
literal|6
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
argument_list|)
block|,
name|symoff
argument_list|(
literal|0
argument_list|)
block|,
name|nsyms
argument_list|(
literal|0
argument_list|)
block|,
name|stroff
argument_list|(
literal|0
argument_list|)
block|,
name|strsize
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
block|;
comment|/// SymTab - The "stab" style symbol table information
name|MachOSymTab
name|SymTab
block|;
comment|/// DySymTab - symbol table info for the dynamic link editor
name|MachODySymTab
name|DySymTab
block|;
name|protected
operator|:
comment|/// SymbolTable - This is the list of symbols we have emitted to the file.
comment|/// This actually gets rearranged before emission to the file (to put the
comment|/// local symbols first in the list).
name|std
operator|::
name|vector
operator|<
name|MachOSym
operator|>
name|SymbolTable
block|;
comment|/// SymT - A buffer to hold the symbol table before we write it out at the
comment|/// appropriate location in the file.
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|SymT
block|;
comment|/// StrT - A buffer to hold the string table before we write it out at the
comment|/// appropriate location in the file.
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|StrT
block|;
comment|/// PendingSyms - This is a list of externally defined symbols that we have
comment|/// been asked to emit, but have not seen a reference to.  When a reference
comment|/// is seen, the symbol will move from this list to the SymbolTable.
name|std
operator|::
name|vector
operator|<
name|GlobalValue
operator|*
operator|>
name|PendingGlobals
block|;
comment|/// DynamicSymbolTable - This is just a vector of indices into
comment|/// SymbolTable to aid in emitting the DYSYMTAB load command.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|DynamicSymbolTable
block|;
specifier|static
name|void
name|InitMem
argument_list|(
argument|const Constant *C
argument_list|,
argument|uintptr_t Offset
argument_list|,
argument|const TargetData *TD
argument_list|,
argument|MachOSection* mos
argument_list|)
block|;
name|private
operator|:
name|void
name|AddSymbolToSection
argument_list|(
name|MachOSection
operator|*
name|MOS
argument_list|,
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
name|void
name|EmitGlobal
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
name|void
name|EmitHeaderAndLoadCommands
argument_list|()
block|;
name|void
name|EmitSections
argument_list|()
block|;
name|void
name|EmitRelocations
argument_list|()
block|;
name|void
name|BufferSymbolAndStringTable
argument_list|()
block|;
name|void
name|CalculateRelocations
argument_list|(
name|MachOSection
operator|&
name|MOS
argument_list|)
block|;
comment|// GetJTRelocation - Get a relocation a new BB relocation based
comment|// on target information.
name|MachineRelocation
name|GetJTRelocation
argument_list|(
argument|unsigned Offset
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// GetTargetRelocation - Returns the number of relocations.
name|unsigned
name|GetTargetRelocation
argument_list|(
argument|MachineRelocation&MR
argument_list|,
argument|unsigned FromIdx
argument_list|,
argument|unsigned ToAddr
argument_list|,
argument|unsigned ToIndex
argument_list|,
argument|OutputBuffer&RelocOut
argument_list|,
argument|OutputBuffer&SecOut
argument_list|,
argument|bool Scattered
argument_list|,
argument|bool Extern
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

