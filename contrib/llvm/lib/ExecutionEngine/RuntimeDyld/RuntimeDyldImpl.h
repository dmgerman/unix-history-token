begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RuntimeDyldImpl.h - Run-time dynamic linker for MC-JIT --*- C++ -*-===//
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
comment|// Interface for the implementations of runtime dynamic linker facilities.
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
name|LLVM_LIB_EXECUTIONENGINE_RUNTIMEDYLD_RUNTIMEDYLDIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_EXECUTIONENGINE_RUNTIMEDYLD_RUNTIMEDYLDIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RTDyldMemoryManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyldChecker.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Host.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SwapByteOrder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
name|namespace
name|llvm
operator|::
name|object
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Helper for extensive error checking in debug builds.
specifier|inline
name|std
operator|::
name|error_code
name|Check
argument_list|(
argument|std::error_code Err
argument_list|)
block|{
if|if
condition|(
name|Err
condition|)
block|{
name|report_fatal_error
argument_list|(
name|Err
operator|.
name|message
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|Err
return|;
block|}
name|class
name|Twine
decl_stmt|;
comment|/// SectionEntry - represents a section emitted into memory by the dynamic
comment|/// linker.
name|class
name|SectionEntry
block|{
name|public
label|:
comment|/// Name - section name.
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|/// Address - address in the linker's memory where the section resides.
name|uint8_t
modifier|*
name|Address
decl_stmt|;
comment|/// Size - section size. Doesn't include the stubs.
name|size_t
name|Size
decl_stmt|;
comment|/// LoadAddress - the address of the section in the target process's memory.
comment|/// Used for situations in which JIT-ed code is being executed in the address
comment|/// space of a separate process.  If the code executes in the same address
comment|/// space where it was JIT-ed, this just equals Address.
name|uint64_t
name|LoadAddress
decl_stmt|;
comment|/// StubOffset - used for architectures with stub functions for far
comment|/// relocations (like ARM).
name|uintptr_t
name|StubOffset
decl_stmt|;
comment|/// ObjAddress - address of the section in the in-memory object file.  Used
comment|/// for calculating relocations in some object formats (like MachO).
name|uintptr_t
name|ObjAddress
decl_stmt|;
name|SectionEntry
argument_list|(
argument|StringRef name
argument_list|,
argument|uint8_t *address
argument_list|,
argument|size_t size
argument_list|,
argument|uintptr_t objAddress
argument_list|)
block|:
name|Name
argument_list|(
name|name
argument_list|)
operator|,
name|Address
argument_list|(
name|address
argument_list|)
operator|,
name|Size
argument_list|(
name|size
argument_list|)
operator|,
name|LoadAddress
argument_list|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|address
operator|)
argument_list|)
operator|,
name|StubOffset
argument_list|(
name|size
argument_list|)
operator|,
name|ObjAddress
argument_list|(
argument|objAddress
argument_list|)
block|{}
block|}
empty_stmt|;
comment|/// RelocationEntry - used to represent relocations internally in the dynamic
comment|/// linker.
name|class
name|RelocationEntry
block|{
name|public
label|:
comment|/// SectionID - the section this relocation points to.
name|unsigned
name|SectionID
decl_stmt|;
comment|/// Offset - offset into the section.
name|uint64_t
name|Offset
decl_stmt|;
comment|/// RelType - relocation type.
name|uint32_t
name|RelType
decl_stmt|;
comment|/// Addend - the relocation addend encoded in the instruction itself.  Also
comment|/// used to make a relocation section relative instead of symbol relative.
name|int64_t
name|Addend
decl_stmt|;
struct|struct
name|SectionPair
block|{
name|uint32_t
name|SectionA
decl_stmt|;
name|uint32_t
name|SectionB
decl_stmt|;
block|}
struct|;
comment|/// SymOffset - Section offset of the relocation entry's symbol (used for GOT
comment|/// lookup).
union|union
block|{
name|uint64_t
name|SymOffset
decl_stmt|;
name|SectionPair
name|Sections
decl_stmt|;
block|}
union|;
comment|/// True if this is a PCRel relocation (MachO specific).
name|bool
name|IsPCRel
decl_stmt|;
comment|/// The size of this relocation (MachO specific).
name|unsigned
name|Size
decl_stmt|;
name|RelocationEntry
argument_list|(
argument|unsigned id
argument_list|,
argument|uint64_t offset
argument_list|,
argument|uint32_t type
argument_list|,
argument|int64_t addend
argument_list|)
block|:
name|SectionID
argument_list|(
name|id
argument_list|)
operator|,
name|Offset
argument_list|(
name|offset
argument_list|)
operator|,
name|RelType
argument_list|(
name|type
argument_list|)
operator|,
name|Addend
argument_list|(
name|addend
argument_list|)
operator|,
name|SymOffset
argument_list|(
literal|0
argument_list|)
operator|,
name|IsPCRel
argument_list|(
name|false
argument_list|)
operator|,
name|Size
argument_list|(
literal|0
argument_list|)
block|{}
name|RelocationEntry
argument_list|(
argument|unsigned id
argument_list|,
argument|uint64_t offset
argument_list|,
argument|uint32_t type
argument_list|,
argument|int64_t addend
argument_list|,
argument|uint64_t symoffset
argument_list|)
operator|:
name|SectionID
argument_list|(
name|id
argument_list|)
operator|,
name|Offset
argument_list|(
name|offset
argument_list|)
operator|,
name|RelType
argument_list|(
name|type
argument_list|)
operator|,
name|Addend
argument_list|(
name|addend
argument_list|)
operator|,
name|SymOffset
argument_list|(
name|symoffset
argument_list|)
operator|,
name|IsPCRel
argument_list|(
name|false
argument_list|)
operator|,
name|Size
argument_list|(
literal|0
argument_list|)
block|{}
name|RelocationEntry
argument_list|(
argument|unsigned id
argument_list|,
argument|uint64_t offset
argument_list|,
argument|uint32_t type
argument_list|,
argument|int64_t addend
argument_list|,
argument|bool IsPCRel
argument_list|,
argument|unsigned Size
argument_list|)
operator|:
name|SectionID
argument_list|(
name|id
argument_list|)
operator|,
name|Offset
argument_list|(
name|offset
argument_list|)
operator|,
name|RelType
argument_list|(
name|type
argument_list|)
operator|,
name|Addend
argument_list|(
name|addend
argument_list|)
operator|,
name|SymOffset
argument_list|(
literal|0
argument_list|)
operator|,
name|IsPCRel
argument_list|(
name|IsPCRel
argument_list|)
operator|,
name|Size
argument_list|(
argument|Size
argument_list|)
block|{}
name|RelocationEntry
argument_list|(
argument|unsigned id
argument_list|,
argument|uint64_t offset
argument_list|,
argument|uint32_t type
argument_list|,
argument|int64_t addend
argument_list|,
argument|unsigned SectionA
argument_list|,
argument|uint64_t SectionAOffset
argument_list|,
argument|unsigned SectionB
argument_list|,
argument|uint64_t SectionBOffset
argument_list|,
argument|bool IsPCRel
argument_list|,
argument|unsigned Size
argument_list|)
operator|:
name|SectionID
argument_list|(
name|id
argument_list|)
operator|,
name|Offset
argument_list|(
name|offset
argument_list|)
operator|,
name|RelType
argument_list|(
name|type
argument_list|)
operator|,
name|Addend
argument_list|(
name|SectionAOffset
operator|-
name|SectionBOffset
operator|+
name|addend
argument_list|)
operator|,
name|IsPCRel
argument_list|(
name|IsPCRel
argument_list|)
operator|,
name|Size
argument_list|(
argument|Size
argument_list|)
block|{
name|Sections
operator|.
name|SectionA
operator|=
name|SectionA
block|;
name|Sections
operator|.
name|SectionB
operator|=
name|SectionB
block|;   }
block|}
empty_stmt|;
name|class
name|RelocationValueRef
block|{
name|public
label|:
name|unsigned
name|SectionID
decl_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
name|int64_t
name|Addend
decl_stmt|;
specifier|const
name|char
modifier|*
name|SymbolName
decl_stmt|;
name|RelocationValueRef
argument_list|()
operator|:
name|SectionID
argument_list|(
literal|0
argument_list|)
operator|,
name|Offset
argument_list|(
literal|0
argument_list|)
operator|,
name|Addend
argument_list|(
literal|0
argument_list|)
operator|,
name|SymbolName
argument_list|(
argument|nullptr
argument_list|)
block|{}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RelocationValueRef
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|SectionID
operator|==
name|Other
operator|.
name|SectionID
operator|&&
name|Offset
operator|==
name|Other
operator|.
name|Offset
operator|&&
name|Addend
operator|==
name|Other
operator|.
name|Addend
operator|&&
name|SymbolName
operator|==
name|Other
operator|.
name|SymbolName
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|RelocationValueRef
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|SectionID
operator|!=
name|Other
operator|.
name|SectionID
condition|)
return|return
name|SectionID
operator|<
name|Other
operator|.
name|SectionID
return|;
if|if
condition|(
name|Offset
operator|!=
name|Other
operator|.
name|Offset
condition|)
return|return
name|Offset
operator|<
name|Other
operator|.
name|Offset
return|;
if|if
condition|(
name|Addend
operator|!=
name|Other
operator|.
name|Addend
condition|)
return|return
name|Addend
operator|<
name|Other
operator|.
name|Addend
return|;
return|return
name|SymbolName
operator|<
name|Other
operator|.
name|SymbolName
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @brief Symbol info for RuntimeDyld.
end_comment

begin_decl_stmt
name|class
name|SymbolTableEntry
range|:
name|public
name|JITSymbolBase
block|{
name|public
operator|:
name|SymbolTableEntry
argument_list|()
operator|:
name|JITSymbolBase
argument_list|(
name|JITSymbolFlags
operator|::
name|None
argument_list|)
block|,
name|Offset
argument_list|(
literal|0
argument_list|)
block|,
name|SectionID
argument_list|(
literal|0
argument_list|)
block|{}
name|SymbolTableEntry
argument_list|(
argument|unsigned SectionID
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|JITSymbolFlags Flags
argument_list|)
operator|:
name|JITSymbolBase
argument_list|(
name|Flags
argument_list|)
block|,
name|Offset
argument_list|(
name|Offset
argument_list|)
block|,
name|SectionID
argument_list|(
argument|SectionID
argument_list|)
block|{}
name|unsigned
name|getSectionID
argument_list|()
specifier|const
block|{
return|return
name|SectionID
return|;
block|}
name|uint64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|private
operator|:
name|uint64_t
name|Offset
block|;
name|unsigned
name|SectionID
block|; }
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|StringMap
operator|<
name|SymbolTableEntry
operator|>
name|RTDyldSymbolTable
expr_stmt|;
end_typedef

begin_decl_stmt
name|class
name|RuntimeDyldImpl
block|{
name|friend
name|class
name|RuntimeDyld
operator|::
name|LoadedObjectInfo
expr_stmt|;
name|friend
name|class
name|RuntimeDyldCheckerImpl
decl_stmt|;
name|protected
label|:
comment|// The MemoryManager to load objects into.
name|RuntimeDyld
operator|::
name|MemoryManager
operator|&
name|MemMgr
expr_stmt|;
comment|// The symbol resolver to use for external symbols.
name|RuntimeDyld
operator|::
name|SymbolResolver
operator|&
name|Resolver
expr_stmt|;
comment|// Attached RuntimeDyldChecker instance. Null if no instance attached.
name|RuntimeDyldCheckerImpl
modifier|*
name|Checker
decl_stmt|;
comment|// A list of all sections emitted by the dynamic linker.  These sections are
comment|// referenced in the code by means of their index in this list - SectionID.
typedef|typedef
name|SmallVector
operator|<
name|SectionEntry
operator|,
literal|64
operator|>
name|SectionList
expr_stmt|;
name|SectionList
name|Sections
decl_stmt|;
typedef|typedef
name|unsigned
name|SID
typedef|;
comment|// Type for SectionIDs
define|#
directive|define
name|RTDYLD_INVALID_SECTION_ID
value|((RuntimeDyldImpl::SID)(-1))
comment|// Keep a map of sections from object file to the SectionID which
comment|// references it.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|SectionRef
operator|,
name|unsigned
operator|>
name|ObjSectionToIDMap
expr_stmt|;
comment|// A global symbol table for symbols from all loaded modules.
name|RTDyldSymbolTable
name|GlobalSymbolTable
decl_stmt|;
comment|// Keep a map of common symbols to their info pairs
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|SymbolRef
operator|>
name|CommonSymbolList
expr_stmt|;
comment|// For each symbol, keep a list of relocations based on it. Anytime
comment|// its address is reassigned (the JIT re-compiled the function, e.g.),
comment|// the relocations get re-resolved.
comment|// The symbol (or section) the relocation is sourced from is the Key
comment|// in the relocation list where it's stored.
typedef|typedef
name|SmallVector
operator|<
name|RelocationEntry
operator|,
literal|64
operator|>
name|RelocationList
expr_stmt|;
comment|// Relocations to sections already loaded. Indexed by SectionID which is the
comment|// source of the address. The target where the address will be written is
comment|// SectionID/Offset in the relocation itself.
name|DenseMap
operator|<
name|unsigned
operator|,
name|RelocationList
operator|>
name|Relocations
expr_stmt|;
comment|// Relocations to external symbols that are not yet resolved.  Symbols are
comment|// external when they aren't found in the global symbol table of all loaded
comment|// modules.  This map is indexed by symbol name.
name|StringMap
operator|<
name|RelocationList
operator|>
name|ExternalSymbolRelocations
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|RelocationValueRef
operator|,
name|uintptr_t
operator|>
name|StubMap
expr_stmt|;
name|Triple
operator|::
name|ArchType
name|Arch
expr_stmt|;
name|bool
name|IsTargetLittleEndian
decl_stmt|;
comment|// True if all sections should be passed to the memory manager, false if only
comment|// sections containing relocations should be. Defaults to 'false'.
name|bool
name|ProcessAllSections
decl_stmt|;
comment|// This mutex prevents simultaneously loading objects from two different
comment|// threads.  This keeps us from having to protect individual data structures
comment|// and guarantees that section allocation requests to the memory manager
comment|// won't be interleaved between modules.  It is also used in mapSectionAddress
comment|// and resolveRelocations to protect write access to internal data structures.
comment|//
comment|// loadObject may be called on the same thread during the handling of of
comment|// processRelocations, and that's OK.  The handling of the relocation lists
comment|// is written in such a way as to work correctly if new elements are added to
comment|// the end of the list while the list is being processed.
name|sys
operator|::
name|Mutex
name|lock
expr_stmt|;
name|virtual
name|unsigned
name|getMaxStubSize
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|unsigned
name|getStubAlignment
parameter_list|()
init|=
literal|0
function_decl|;
name|bool
name|HasError
decl_stmt|;
name|std
operator|::
name|string
name|ErrorStr
expr_stmt|;
comment|// Set the error state and record an error string.
name|bool
name|Error
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
block|{
name|ErrorStr
operator|=
name|Msg
operator|.
name|str
argument_list|()
expr_stmt|;
name|HasError
operator|=
name|true
expr_stmt|;
return|return
name|true
return|;
block|}
name|uint64_t
name|getSectionLoadAddress
argument_list|(
name|unsigned
name|SectionID
argument_list|)
decl|const
block|{
return|return
name|Sections
index|[
name|SectionID
index|]
operator|.
name|LoadAddress
return|;
block|}
name|uint8_t
modifier|*
name|getSectionAddress
argument_list|(
name|unsigned
name|SectionID
argument_list|)
decl|const
block|{
return|return
operator|(
name|uint8_t
operator|*
operator|)
name|Sections
index|[
name|SectionID
index|]
operator|.
name|Address
return|;
block|}
name|void
name|writeInt16BE
parameter_list|(
name|uint8_t
modifier|*
name|Addr
parameter_list|,
name|uint16_t
name|Value
parameter_list|)
block|{
if|if
condition|(
name|IsTargetLittleEndian
condition|)
name|sys
operator|::
name|swapByteOrder
argument_list|(
name|Value
argument_list|)
expr_stmt|;
operator|*
name|Addr
operator|=
operator|(
name|Value
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|1
operator|)
operator|=
name|Value
operator|&
literal|0xFF
expr_stmt|;
block|}
name|void
name|writeInt32BE
parameter_list|(
name|uint8_t
modifier|*
name|Addr
parameter_list|,
name|uint32_t
name|Value
parameter_list|)
block|{
if|if
condition|(
name|IsTargetLittleEndian
condition|)
name|sys
operator|::
name|swapByteOrder
argument_list|(
name|Value
argument_list|)
expr_stmt|;
operator|*
name|Addr
operator|=
operator|(
name|Value
operator|>>
literal|24
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|1
operator|)
operator|=
operator|(
name|Value
operator|>>
literal|16
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|2
operator|)
operator|=
operator|(
name|Value
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|3
operator|)
operator|=
name|Value
operator|&
literal|0xFF
expr_stmt|;
block|}
name|void
name|writeInt64BE
parameter_list|(
name|uint8_t
modifier|*
name|Addr
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
block|{
if|if
condition|(
name|IsTargetLittleEndian
condition|)
name|sys
operator|::
name|swapByteOrder
argument_list|(
name|Value
argument_list|)
expr_stmt|;
operator|*
name|Addr
operator|=
operator|(
name|Value
operator|>>
literal|56
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|1
operator|)
operator|=
operator|(
name|Value
operator|>>
literal|48
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|2
operator|)
operator|=
operator|(
name|Value
operator|>>
literal|40
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|3
operator|)
operator|=
operator|(
name|Value
operator|>>
literal|32
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|4
operator|)
operator|=
operator|(
name|Value
operator|>>
literal|24
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|5
operator|)
operator|=
operator|(
name|Value
operator|>>
literal|16
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|6
operator|)
operator|=
operator|(
name|Value
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
expr_stmt|;
operator|*
operator|(
name|Addr
operator|+
literal|7
operator|)
operator|=
name|Value
operator|&
literal|0xFF
expr_stmt|;
block|}
comment|/// Endian-aware read Read the least significant Size bytes from Src.
name|uint64_t
name|readBytesUnaligned
argument_list|(
name|uint8_t
operator|*
name|Src
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
comment|/// Endian-aware write. Write the least significant Size bytes from Value to
comment|/// Dst.
name|void
name|writeBytesUnaligned
argument_list|(
name|uint64_t
name|Value
argument_list|,
name|uint8_t
operator|*
name|Dst
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Given the common symbols discovered in the object file, emit a
comment|/// new section for them and update the symbol mappings in the object and
comment|/// symbol table.
name|void
name|emitCommonSymbols
parameter_list|(
specifier|const
name|ObjectFile
modifier|&
name|Obj
parameter_list|,
name|CommonSymbolList
modifier|&
name|CommonSymbols
parameter_list|)
function_decl|;
comment|/// \brief Emits section data from the object file to the MemoryManager.
comment|/// \param IsCode if it's true then allocateCodeSection() will be
comment|///        used for emits, else allocateDataSection() will be used.
comment|/// \return SectionID.
name|unsigned
name|emitSection
parameter_list|(
specifier|const
name|ObjectFile
modifier|&
name|Obj
parameter_list|,
specifier|const
name|SectionRef
modifier|&
name|Section
parameter_list|,
name|bool
name|IsCode
parameter_list|)
function_decl|;
comment|/// \brief Find Section in LocalSections. If the secton is not found - emit
comment|///        it and store in LocalSections.
comment|/// \param IsCode if it's true then allocateCodeSection() will be
comment|///        used for emmits, else allocateDataSection() will be used.
comment|/// \return SectionID.
name|unsigned
name|findOrEmitSection
parameter_list|(
specifier|const
name|ObjectFile
modifier|&
name|Obj
parameter_list|,
specifier|const
name|SectionRef
modifier|&
name|Section
parameter_list|,
name|bool
name|IsCode
parameter_list|,
name|ObjSectionToIDMap
modifier|&
name|LocalSections
parameter_list|)
function_decl|;
comment|// \brief Add a relocation entry that uses the given section.
name|void
name|addRelocationForSection
parameter_list|(
specifier|const
name|RelocationEntry
modifier|&
name|RE
parameter_list|,
name|unsigned
name|SectionID
parameter_list|)
function_decl|;
comment|// \brief Add a relocation entry that uses the given symbol.  This symbol may
comment|// be found in the global symbol table, or it may be external.
name|void
name|addRelocationForSymbol
parameter_list|(
specifier|const
name|RelocationEntry
modifier|&
name|RE
parameter_list|,
name|StringRef
name|SymbolName
parameter_list|)
function_decl|;
comment|/// \brief Emits long jump instruction to Addr.
comment|/// \return Pointer to the memory area for emitting target address.
name|uint8_t
modifier|*
name|createStubFunction
parameter_list|(
name|uint8_t
modifier|*
name|Addr
parameter_list|,
name|unsigned
name|AbiVariant
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Resolves relocations from Relocs list with address from Value.
name|void
name|resolveRelocationList
parameter_list|(
specifier|const
name|RelocationList
modifier|&
name|Relocs
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
function_decl|;
comment|/// \brief A object file specific relocation resolver
comment|/// \param RE The relocation to be resolved
comment|/// \param Value Target symbol address to apply the relocation action
name|virtual
name|void
name|resolveRelocation
parameter_list|(
specifier|const
name|RelocationEntry
modifier|&
name|RE
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Parses one or more object file relocations (some object files use
comment|///        relocation pairs) and stores it to Relocations or SymbolRelocations
comment|///        (this depends on the object file type).
comment|/// \return Iterator to the next relocation that needs to be parsed.
name|virtual
name|relocation_iterator
name|processRelocationRef
parameter_list|(
name|unsigned
name|SectionID
parameter_list|,
name|relocation_iterator
name|RelI
parameter_list|,
specifier|const
name|ObjectFile
modifier|&
name|Obj
parameter_list|,
name|ObjSectionToIDMap
modifier|&
name|ObjSectionToID
parameter_list|,
name|StubMap
modifier|&
name|Stubs
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Resolve relocations to external symbols.
name|void
name|resolveExternalSymbols
parameter_list|()
function_decl|;
comment|// \brief Compute an upper bound of the memory that is required to load all
comment|// sections
name|void
name|computeTotalAllocSize
parameter_list|(
specifier|const
name|ObjectFile
modifier|&
name|Obj
parameter_list|,
name|uint64_t
modifier|&
name|CodeSize
parameter_list|,
name|uint64_t
modifier|&
name|DataSizeRO
parameter_list|,
name|uint64_t
modifier|&
name|DataSizeRW
parameter_list|)
function_decl|;
comment|// \brief Compute the stub buffer size required for a section
name|unsigned
name|computeSectionStubBufSize
parameter_list|(
specifier|const
name|ObjectFile
modifier|&
name|Obj
parameter_list|,
specifier|const
name|SectionRef
modifier|&
name|Section
parameter_list|)
function_decl|;
comment|// \brief Implementation of the generic part of the loadObject algorithm.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|loadObjectImpl
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|Obj
argument_list|)
expr_stmt|;
name|public
label|:
name|RuntimeDyldImpl
argument_list|(
name|RuntimeDyld
operator|::
name|MemoryManager
operator|&
name|MemMgr
argument_list|,
name|RuntimeDyld
operator|::
name|SymbolResolver
operator|&
name|Resolver
argument_list|)
operator|:
name|MemMgr
argument_list|(
name|MemMgr
argument_list|)
operator|,
name|Resolver
argument_list|(
name|Resolver
argument_list|)
operator|,
name|Checker
argument_list|(
name|nullptr
argument_list|)
operator|,
name|ProcessAllSections
argument_list|(
name|false
argument_list|)
operator|,
name|HasError
argument_list|(
argument|false
argument_list|)
block|{   }
name|virtual
operator|~
name|RuntimeDyldImpl
argument_list|()
expr_stmt|;
name|void
name|setProcessAllSections
parameter_list|(
name|bool
name|ProcessAllSections
parameter_list|)
block|{
name|this
operator|->
name|ProcessAllSections
operator|=
name|ProcessAllSections
expr_stmt|;
block|}
name|void
name|setRuntimeDyldChecker
parameter_list|(
name|RuntimeDyldCheckerImpl
modifier|*
name|Checker
parameter_list|)
block|{
name|this
operator|->
name|Checker
operator|=
name|Checker
expr_stmt|;
block|}
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyld
operator|::
name|LoadedObjectInfo
operator|>
name|loadObject
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|Obj
argument_list|)
operator|=
literal|0
expr_stmt|;
name|uint8_t
modifier|*
name|getSymbolLocalAddress
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
block|{
comment|// FIXME: Just look up as a function for now. Overly simple of course.
comment|// Work in progress.
name|RTDyldSymbolTable
operator|::
name|const_iterator
name|pos
operator|=
name|GlobalSymbolTable
operator|.
name|find
argument_list|(
name|Name
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|==
name|GlobalSymbolTable
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
specifier|const
specifier|auto
modifier|&
name|SymInfo
init|=
name|pos
operator|->
name|second
decl_stmt|;
return|return
name|getSectionAddress
argument_list|(
name|SymInfo
operator|.
name|getSectionID
argument_list|()
argument_list|)
operator|+
name|SymInfo
operator|.
name|getOffset
argument_list|()
return|;
block|}
name|RuntimeDyld
operator|::
name|SymbolInfo
name|getSymbol
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
comment|// FIXME: Just look up as a function for now. Overly simple of course.
comment|// Work in progress.
name|RTDyldSymbolTable
operator|::
name|const_iterator
name|pos
operator|=
name|GlobalSymbolTable
operator|.
name|find
argument_list|(
name|Name
argument_list|)
block|;
if|if
condition|(
name|pos
operator|==
name|GlobalSymbolTable
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
specifier|const
name|auto
operator|&
name|SymEntry
operator|=
name|pos
operator|->
name|second
expr_stmt|;
name|uint64_t
name|TargetAddr
init|=
name|getSectionLoadAddress
argument_list|(
name|SymEntry
operator|.
name|getSectionID
argument_list|()
argument_list|)
operator|+
name|SymEntry
operator|.
name|getOffset
argument_list|()
decl_stmt|;
return|return
name|RuntimeDyld
operator|::
name|SymbolInfo
argument_list|(
name|TargetAddr
argument_list|,
name|SymEntry
operator|.
name|getFlags
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
name|void
name|resolveRelocations
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reassignSectionAddress
parameter_list|(
name|unsigned
name|SectionID
parameter_list|,
name|uint64_t
name|Addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mapSectionAddress
parameter_list|(
specifier|const
name|void
modifier|*
name|LocalAddress
parameter_list|,
name|uint64_t
name|TargetAddress
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Is the linker in an error state?
end_comment

begin_function
name|bool
name|hasError
parameter_list|()
block|{
return|return
name|HasError
return|;
block|}
end_function

begin_comment
comment|// Mark the error condition as handled and continue.
end_comment

begin_function
name|void
name|clearError
parameter_list|()
block|{
name|HasError
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_comment
comment|// Get the error message.
end_comment

begin_function
name|StringRef
name|getErrorString
parameter_list|()
block|{
return|return
name|ErrorStr
return|;
block|}
end_function

begin_decl_stmt
name|virtual
name|bool
name|isCompatibleFile
argument_list|(
specifier|const
name|ObjectFile
operator|&
name|Obj
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|void
name|registerEHFrames
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|deregisterEHFrames
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|virtual
name|void
name|finalizeLoad
parameter_list|(
specifier|const
name|ObjectFile
modifier|&
name|ObjImg
parameter_list|,
name|ObjSectionToIDMap
modifier|&
name|SectionMap
parameter_list|)
block|{}
end_function

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

