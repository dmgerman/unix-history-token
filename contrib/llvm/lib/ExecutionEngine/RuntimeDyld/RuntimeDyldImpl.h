begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RuntimeDyldImpl.h - Run-time dynamic linker for MC-JIT ------*- C++ -*-===//
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
file|"llvm/Object/MachOObject.h"
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
file|"llvm/ExecutionEngine/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
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
name|RuntimeDyldImpl
block|{
name|protected
label|:
name|unsigned
name|CPUType
decl_stmt|;
name|unsigned
name|CPUSubtype
decl_stmt|;
comment|// The MemoryManager to load objects into.
name|RTDyldMemoryManager
modifier|*
name|MemMgr
decl_stmt|;
comment|// FIXME: This all assumes we're dealing with external symbols for anything
comment|//        explicitly referenced. I.e., we can index by name and things
comment|//        will work out. In practice, this may not be the case, so we
comment|//        should find a way to effectively generalize.
comment|// For each function, we have a MemoryBlock of it's instruction data.
name|StringMap
operator|<
name|sys
operator|::
name|MemoryBlock
operator|>
name|Functions
expr_stmt|;
comment|// Master symbol table. As modules are loaded and external symbols are
comment|// resolved, their addresses are stored here.
name|StringMap
operator|<
name|uint8_t
operator|*
operator|>
name|SymbolTable
expr_stmt|;
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
name|void
name|extractFunction
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint8_t
modifier|*
name|StartAddress
parameter_list|,
name|uint8_t
modifier|*
name|EndAddress
parameter_list|)
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
name|virtual
name|bool
name|loadObject
parameter_list|(
name|MemoryBuffer
modifier|*
name|InputBuffer
parameter_list|)
init|=
literal|0
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
return|return
name|SymbolTable
operator|.
name|lookup
argument_list|(
name|Name
argument_list|)
return|;
block|}
name|void
name|resolveRelocations
parameter_list|()
function_decl|;
name|virtual
name|void
name|reassignSymbolAddress
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint8_t
modifier|*
name|Addr
parameter_list|)
init|=
literal|0
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
name|class
name|RuntimeDyldMachO
range|:
name|public
name|RuntimeDyldImpl
block|{
comment|// For each symbol, keep a list of relocations based on it. Anytime
comment|// its address is reassigned (the JIT re-compiled the function, e.g.),
comment|// the relocations get re-resolved.
block|struct
name|RelocationEntry
block|{
name|std
operator|::
name|string
name|Target
block|;
comment|// Object this relocation is contained in.
name|uint64_t
name|Offset
block|;
comment|// Offset into the object for the relocation.
name|uint32_t
name|Data
block|;
comment|// Second word of the raw macho relocation entry.
name|int64_t
name|Addend
block|;
comment|// Addend encoded in the instruction itself, if any.
name|bool
name|isResolved
block|;
comment|// Has this relocation been resolved previously?
name|RelocationEntry
argument_list|(
argument|StringRef t
argument_list|,
argument|uint64_t offset
argument_list|,
argument|uint32_t data
argument_list|,
argument|int64_t addend
argument_list|)
operator|:
name|Target
argument_list|(
name|t
argument_list|)
block|,
name|Offset
argument_list|(
name|offset
argument_list|)
block|,
name|Data
argument_list|(
name|data
argument_list|)
block|,
name|Addend
argument_list|(
name|addend
argument_list|)
block|,
name|isResolved
argument_list|(
argument|false
argument_list|)
block|{}
block|}
block|;
typedef|typedef
name|SmallVector
operator|<
name|RelocationEntry
operator|,
literal|4
operator|>
name|RelocationList
expr_stmt|;
name|StringMap
operator|<
name|RelocationList
operator|>
name|Relocations
decl_stmt|;
comment|// FIXME: Also keep a map of all the relocations contained in an object. Use
comment|// this to dynamically answer whether all of the relocations in it have
comment|// been resolved or not.
name|bool
name|resolveRelocation
parameter_list|(
name|uint8_t
modifier|*
name|Address
parameter_list|,
name|uint8_t
modifier|*
name|Value
parameter_list|,
name|bool
name|isPCRel
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
name|bool
name|resolveX86_64Relocation
parameter_list|(
name|uintptr_t
name|Address
parameter_list|,
name|uintptr_t
name|Value
parameter_list|,
name|bool
name|isPCRel
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
name|bool
name|resolveARMRelocation
parameter_list|(
name|uintptr_t
name|Address
parameter_list|,
name|uintptr_t
name|Value
parameter_list|,
name|bool
name|isPCRel
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
name|bool
name|loadSegment32
argument_list|(
specifier|const
name|MachOObject
operator|*
name|Obj
argument_list|,
specifier|const
name|MachOObject
operator|::
name|LoadCommandInfo
operator|*
name|SegmentLCI
argument_list|,
specifier|const
name|InMemoryStruct
operator|<
name|macho
operator|::
name|SymtabLoadCommand
operator|>
operator|&
name|SymtabLC
argument_list|)
decl_stmt|;
name|bool
name|loadSegment64
argument_list|(
specifier|const
name|MachOObject
operator|*
name|Obj
argument_list|,
specifier|const
name|MachOObject
operator|::
name|LoadCommandInfo
operator|*
name|SegmentLCI
argument_list|,
specifier|const
name|InMemoryStruct
operator|<
name|macho
operator|::
name|SymtabLoadCommand
operator|>
operator|&
name|SymtabLC
argument_list|)
decl_stmt|;
name|public
label|:
name|RuntimeDyldMachO
argument_list|(
name|RTDyldMemoryManager
operator|*
name|mm
argument_list|)
operator|:
name|RuntimeDyldImpl
argument_list|(
argument|mm
argument_list|)
block|{}
name|bool
name|loadObject
argument_list|(
name|MemoryBuffer
operator|*
name|InputBuffer
argument_list|)
expr_stmt|;
name|void
name|reassignSymbolAddress
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint8_t
modifier|*
name|Addr
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isKnownFormat
parameter_list|(
specifier|const
name|MemoryBuffer
modifier|*
name|InputBuffer
parameter_list|)
function_decl|;
name|bool
name|isCompatibleFormat
argument_list|(
specifier|const
name|MemoryBuffer
operator|*
name|InputBuffer
argument_list|)
decl|const
block|{
return|return
name|isKnownFormat
argument_list|(
name|InputBuffer
argument_list|)
return|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

