begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RuntimeDyldCOFF.h - Run-time dynamic linker for MC-JIT ---*- C++ -*-==//
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
comment|// COFF support for MC-JIT runtime dynamic linker.
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
name|LLVM_RUNTIME_DYLD_COFF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIME_DYLD_COFF_H
end_define

begin_include
include|#
directive|include
file|"RuntimeDyldImpl.h"
end_include

begin_define
define|#
directive|define
name|DEBUG_TYPE
value|"dyld"
end_define

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Common base class for COFF dynamic linker support.
comment|// Concrete subclasses for each target can be found in ./Targets.
name|class
name|RuntimeDyldCOFF
range|:
name|public
name|RuntimeDyldImpl
block|{
name|public
operator|:
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
argument|const object::ObjectFile&Obj
argument_list|)
name|override
block|;
name|bool
name|isCompatibleFile
argument_list|(
argument|const object::ObjectFile&Obj
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyldCOFF
operator|>
name|create
argument_list|(
argument|Triple::ArchType Arch
argument_list|,
argument|RuntimeDyld::MemoryManager&MemMgr
argument_list|,
argument|JITSymbolResolver&Resolver
argument_list|)
block|;
name|protected
operator|:
name|RuntimeDyldCOFF
argument_list|(
name|RuntimeDyld
operator|::
name|MemoryManager
operator|&
name|MemMgr
argument_list|,
name|JITSymbolResolver
operator|&
name|Resolver
argument_list|)
operator|:
name|RuntimeDyldImpl
argument_list|(
argument|MemMgr
argument_list|,
argument|Resolver
argument_list|)
block|{}
name|uint64_t
name|getSymbolOffset
argument_list|(
specifier|const
name|SymbolRef
operator|&
name|Sym
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_undef
undef|#
directive|undef
name|DEBUG_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

