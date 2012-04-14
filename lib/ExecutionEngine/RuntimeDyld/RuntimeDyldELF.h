begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RuntimeDyldELF.h - Run-time dynamic linker for MC-JIT ---*- C++ -*-===//
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
comment|// ELF support for MC-JIT runtime dynamic linker.
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
name|LLVM_RUNTIME_DYLD_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIME_DYLD_ELF_H
end_define

begin_include
include|#
directive|include
file|"RuntimeDyldImpl.h"
end_include

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
name|class
name|RuntimeDyldELF
range|:
name|public
name|RuntimeDyldImpl
block|{
name|protected
operator|:
name|void
name|resolveX86_64Relocation
argument_list|(
argument|uint8_t *LocalAddress
argument_list|,
argument|uint64_t FinalAddress
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|void
name|resolveX86Relocation
argument_list|(
argument|uint8_t *LocalAddress
argument_list|,
argument|uint32_t FinalAddress
argument_list|,
argument|uint32_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int32_t Addend
argument_list|)
block|;
name|void
name|resolveARMRelocation
argument_list|(
argument|uint8_t *LocalAddress
argument_list|,
argument|uint32_t FinalAddress
argument_list|,
argument|uint32_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int32_t Addend
argument_list|)
block|;
name|virtual
name|void
name|resolveRelocation
argument_list|(
argument|uint8_t *LocalAddress
argument_list|,
argument|uint64_t FinalAddress
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|virtual
name|void
name|processRelocationRef
argument_list|(
specifier|const
name|ObjRelocationInfo
operator|&
name|Rel
argument_list|,
specifier|const
name|ObjectFile
operator|&
name|Obj
argument_list|,
name|ObjSectionToIDMap
operator|&
name|ObjSectionToID
argument_list|,
name|LocalSymbolMap
operator|&
name|Symbols
argument_list|,
name|StubMap
operator|&
name|Stubs
argument_list|)
block|;
name|public
operator|:
name|RuntimeDyldELF
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
name|isCompatibleFormat
argument_list|(
argument|const MemoryBuffer *InputBuffer
argument_list|)
specifier|const
block|; }
decl_stmt|;
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

