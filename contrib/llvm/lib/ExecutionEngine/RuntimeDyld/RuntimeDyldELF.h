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
name|namespace
block|{
comment|// Helper for extensive error checking in debug builds.
name|error_code
name|Check
parameter_list|(
name|error_code
name|Err
parameter_list|)
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
block|}
comment|// end anonymous namespace
name|class
name|RuntimeDyldELF
range|:
name|public
name|RuntimeDyldImpl
block|{
name|void
name|resolveRelocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|void
name|resolveX86_64Relocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
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
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint32_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int32_t Addend
argument_list|)
block|;
name|void
name|resolveAArch64Relocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|void
name|resolveARMRelocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint32_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int32_t Addend
argument_list|)
block|;
name|void
name|resolveMIPSRelocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint32_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int32_t Addend
argument_list|)
block|;
name|void
name|resolvePPC64Relocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|void
name|resolveSystemZRelocation
argument_list|(
argument|const SectionEntry&Section
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Value
argument_list|,
argument|uint32_t Type
argument_list|,
argument|int64_t Addend
argument_list|)
block|;
name|uint64_t
name|findPPC64TOC
argument_list|()
specifier|const
block|;
name|void
name|findOPDEntrySection
argument_list|(
name|ObjectImage
operator|&
name|Obj
argument_list|,
name|ObjSectionToIDMap
operator|&
name|LocalSections
argument_list|,
name|RelocationValueRef
operator|&
name|Rel
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
name|virtual
name|void
name|resolveRelocation
argument_list|(
argument|const RelocationEntry&RE
argument_list|,
argument|uint64_t Value
argument_list|)
block|;
name|virtual
name|void
name|processRelocationRef
argument_list|(
argument|unsigned SectionID
argument_list|,
argument|RelocationRef RelI
argument_list|,
argument|ObjectImage&Obj
argument_list|,
argument|ObjSectionToIDMap&ObjSectionToID
argument_list|,
argument|const SymbolTableMap&Symbols
argument_list|,
argument|StubMap&Stubs
argument_list|)
block|;
name|virtual
name|bool
name|isCompatibleFormat
argument_list|(
argument|const ObjectBuffer *Buffer
argument_list|)
specifier|const
block|;
name|virtual
name|ObjectImage
operator|*
name|createObjectImage
argument_list|(
name|ObjectBuffer
operator|*
name|InputBuffer
argument_list|)
block|;
name|virtual
name|StringRef
name|getEHFrameSection
argument_list|()
block|;
name|virtual
operator|~
name|RuntimeDyldELF
argument_list|()
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

