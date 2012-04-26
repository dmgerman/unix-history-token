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
name|LLVM_RUNTIME_DYLD_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIME_DYLD_IMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/system_error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
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
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
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
name|class
name|SectionEntry
block|{
name|public
label|:
name|uint8_t
modifier|*
name|Address
decl_stmt|;
name|size_t
name|Size
decl_stmt|;
name|uint64_t
name|LoadAddress
decl_stmt|;
comment|// For each section, the address it will be
comment|// considered to live at for relocations. The same
comment|// as the pointer to the above memory block for
comment|// hosted JITs.
name|uintptr_t
name|StubOffset
decl_stmt|;
comment|// It's used for architecturies with stub
comment|// functions for far relocations like ARM.
name|uintptr_t
name|ObjAddress
decl_stmt|;
comment|// Section address in object file. It's use for
comment|// calculate MachO relocation addend
name|SectionEntry
argument_list|(
argument|uint8_t* address
argument_list|,
argument|size_t size
argument_list|,
argument|uintptr_t stubOffset
argument_list|,
argument|uintptr_t objAddress
argument_list|)
block|:
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
operator|(
name|uintptr_t
operator|)
name|address
argument_list|)
operator|,
name|StubOffset
argument_list|(
name|stubOffset
argument_list|)
operator|,
name|ObjAddress
argument_list|(
argument|objAddress
argument_list|)
block|{}
block|}
empty_stmt|;
name|class
name|RelocationEntry
block|{
name|public
label|:
name|unsigned
name|SectionID
decl_stmt|;
comment|// Section the relocation is contained in.
name|uintptr_t
name|Offset
decl_stmt|;
comment|// Offset into the section for the relocation.
name|uint32_t
name|Data
decl_stmt|;
comment|// Relocatino data. Including type of relocation
comment|// and another flags and parameners from
name|intptr_t
name|Addend
decl_stmt|;
comment|// Addend encoded in the instruction itself, if any,
comment|// plus the offset into the source section for
comment|// the symbol once the relocation is resolvable.
name|RelocationEntry
argument_list|(
argument|unsigned id
argument_list|,
argument|uint64_t offset
argument_list|,
argument|uint32_t data
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
name|Data
argument_list|(
name|data
argument_list|)
operator|,
name|Addend
argument_list|(
argument|addend
argument_list|)
block|{}
block|}
empty_stmt|;
comment|// Raw relocation data from object file
name|class
name|ObjRelocationInfo
block|{
name|public
label|:
name|unsigned
name|SectionID
decl_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
name|SymbolRef
name|Symbol
decl_stmt|;
name|uint64_t
name|Type
decl_stmt|;
name|int64_t
name|AdditionalInfo
decl_stmt|;
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
name|intptr_t
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
name|Addend
argument_list|(
literal|0
argument_list|)
operator|,
name|SymbolName
argument_list|(
literal|0
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
name|std
operator|::
name|memcmp
argument_list|(
name|this
argument_list|,
operator|&
name|Other
argument_list|,
sizeof|sizeof
argument_list|(
name|RelocationValueRef
argument_list|)
argument_list|)
operator|==
literal|0
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
return|return
name|std
operator|::
name|memcmp
argument_list|(
name|this
argument_list|,
operator|&
name|Other
argument_list|,
sizeof|sizeof
argument_list|(
name|RelocationValueRef
argument_list|)
argument_list|)
operator|<
literal|0
return|;
block|}
block|}
empty_stmt|;
name|class
name|RuntimeDyldImpl
block|{
name|protected
label|:
comment|// The MemoryManager to load objects into.
name|RTDyldMemoryManager
modifier|*
name|MemMgr
decl_stmt|;
comment|// A list of emmitted sections.
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
comment|// Master symbol table. As modules are loaded and external symbols are
comment|// resolved, their addresses are stored here as a SectionID/Offset pair.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|uintptr_t
operator|>
name|SymbolLoc
expr_stmt|;
name|StringMap
operator|<
name|SymbolLoc
operator|>
name|SymbolTable
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|char
operator|*
operator|,
name|SymbolLoc
operator|>
name|LocalSymbolMap
expr_stmt|;
comment|// Keep a map of common symbols to their sizes
typedef|typedef
name|std
operator|::
name|map
operator|<
name|SymbolRef
operator|,
name|unsigned
operator|>
name|CommonSymbolMap
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
comment|// source of the address. The target where the address will be writen is
comment|// SectionID/Offset in the relocation itself.
name|DenseMap
operator|<
name|unsigned
operator|,
name|RelocationList
operator|>
name|Relocations
expr_stmt|;
comment|// Relocations to external symbols that are not yet resolved.
comment|// Indexed by symbol name.
name|StringMap
operator|<
name|RelocationList
operator|>
name|SymbolRelocations
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
specifier|inline
name|unsigned
name|getMaxStubSize
parameter_list|()
block|{
if|if
condition|(
name|Arch
operator|==
name|Triple
operator|::
name|arm
operator|||
name|Arch
operator|==
name|Triple
operator|::
name|thumb
condition|)
return|return
literal|8
return|;
comment|// 32-bit instruction and 32-bit address
else|else
return|return
literal|0
return|;
block|}
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
name|uint8_t
modifier|*
name|getSectionAddress
parameter_list|(
name|unsigned
name|SectionID
parameter_list|)
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
comment|/// \brief Emits a section containing common symbols.
comment|/// \return SectionID.
name|unsigned
name|emitCommonSymbols
parameter_list|(
specifier|const
name|CommonSymbolMap
modifier|&
name|Map
parameter_list|,
name|uint64_t
name|TotalSize
parameter_list|,
name|LocalSymbolMap
modifier|&
name|Symbols
parameter_list|)
function_decl|;
comment|/// \brief Emits section data from the object file to the MemoryManager.
comment|/// \param IsCode if it's true then allocateCodeSection() will be
comment|///        used for emmits, else allocateDataSection() will be used.
comment|/// \return SectionID.
name|unsigned
name|emitSection
parameter_list|(
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
comment|/// \brief If Value.SymbolName is NULL then store relocation to the
comment|///        Relocations, else store it in the SymbolRelocations.
name|void
name|AddRelocation
parameter_list|(
specifier|const
name|RelocationValueRef
modifier|&
name|Value
parameter_list|,
name|unsigned
name|SectionID
parameter_list|,
name|uintptr_t
name|Offset
parameter_list|,
name|uint32_t
name|RelType
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
name|void
name|resolveRelocationEntry
parameter_list|(
specifier|const
name|RelocationEntry
modifier|&
name|RE
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
function_decl|;
comment|/// \brief A object file specific relocation resolver
comment|/// \param Address Address to apply the relocation action
comment|/// \param Value Target symbol address to apply the relocation action
comment|/// \param Type object file specific relocation type
comment|/// \param Addend A constant addend used to compute the value to be stored
comment|///        into the relocatable field
name|virtual
name|void
name|resolveRelocation
parameter_list|(
name|uint8_t
modifier|*
name|LocalAddress
parameter_list|,
name|uint64_t
name|FinalAddress
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|uint32_t
name|Type
parameter_list|,
name|int64_t
name|Addend
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Parses the object file relocation and store it to Relocations
comment|///        or SymbolRelocations. Its depend from object file type.
name|virtual
name|void
name|processRelocationRef
parameter_list|(
specifier|const
name|ObjRelocationInfo
modifier|&
name|Rel
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
name|LocalSymbolMap
modifier|&
name|Symbols
parameter_list|,
name|StubMap
modifier|&
name|Stubs
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|resolveSymbols
parameter_list|()
function_decl|;
name|public
label|:
name|RuntimeDyldImpl
argument_list|(
name|RTDyldMemoryManager
operator|*
name|mm
argument_list|)
operator|:
name|MemMgr
argument_list|(
name|mm
argument_list|)
operator|,
name|HasError
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|RuntimeDyldImpl
argument_list|()
expr_stmt|;
name|bool
name|loadObject
parameter_list|(
specifier|const
name|MemoryBuffer
modifier|*
name|InputBuffer
parameter_list|)
function_decl|;
name|void
modifier|*
name|getSymbolAddress
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
comment|// FIXME: Just look up as a function for now. Overly simple of course.
comment|// Work in progress.
if|if
condition|(
name|SymbolTable
operator|.
name|find
argument_list|(
name|Name
argument_list|)
operator|==
name|SymbolTable
operator|.
name|end
argument_list|()
condition|)
return|return
literal|0
return|;
name|SymbolLoc
name|Loc
init|=
name|SymbolTable
operator|.
name|lookup
argument_list|(
name|Name
argument_list|)
decl_stmt|;
return|return
name|getSectionAddress
argument_list|(
name|Loc
operator|.
name|first
argument_list|)
operator|+
name|Loc
operator|.
name|second
return|;
block|}
name|void
name|resolveRelocations
parameter_list|()
function_decl|;
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
name|void
name|mapSectionAddress
parameter_list|(
name|void
modifier|*
name|LocalAddress
parameter_list|,
name|uint64_t
name|TargetAddress
parameter_list|)
function_decl|;
comment|// Is the linker in an error state?
name|bool
name|hasError
parameter_list|()
block|{
return|return
name|HasError
return|;
block|}
comment|// Mark the error condition as handled and continue.
name|void
name|clearError
parameter_list|()
block|{
name|HasError
operator|=
name|false
expr_stmt|;
block|}
comment|// Get the error message.
name|StringRef
name|getErrorString
parameter_list|()
block|{
return|return
name|ErrorStr
return|;
block|}
name|virtual
name|bool
name|isCompatibleFormat
argument_list|(
specifier|const
name|MemoryBuffer
operator|*
name|InputBuffer
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
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

