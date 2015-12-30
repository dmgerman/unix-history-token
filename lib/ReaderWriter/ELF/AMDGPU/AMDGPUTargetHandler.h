begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/AMDGPU/AMDGPUTargetHandler.h ------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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

begin_ifndef
ifndef|#
directive|ifndef
name|AMDGPU_TARGET_HANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPU_TARGET_HANDLER_H
end_define

begin_include
include|#
directive|include
file|"ELFFile.h"
end_include

begin_include
include|#
directive|include
file|"ELFReader.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPURelocationHandler.h"
end_include

begin_include
include|#
directive|include
file|"TargetLayout.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|AMDGPULinkingContext
decl_stmt|;
name|class
name|HSATextSection
range|:
name|public
name|AtomSection
operator|<
name|ELF64LE
operator|>
block|{
name|public
operator|:
name|HSATextSection
argument_list|(
specifier|const
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief TargetLayout for AMDGPU
name|class
name|AMDGPUTargetLayout
name|final
range|:
name|public
name|TargetLayout
operator|<
name|ELF64LE
operator|>
block|{
name|public
operator|:
name|AMDGPUTargetLayout
argument_list|(
name|AMDGPULinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|TargetLayout
argument_list|(
argument|ctx
argument_list|)
block|{}
name|void
name|assignSectionsToSegments
argument_list|()
name|override
block|;
comment|/// \brief Gets or creates a section.
name|AtomSection
operator|<
name|ELF64LE
operator|>
operator|*
name|createSection
argument_list|(
argument|StringRef name
argument_list|,
argument|int32_t contentType
argument_list|,
argument|DefinedAtom::ContentPermissions contentPermissions
argument_list|,
argument|TargetLayout::SectionOrder sectionOrder
argument_list|)
name|override
block|{
if|if
condition|(
name|name
operator|==
literal|".hsatext"
condition|)
return|return
name|new
argument_list|(
argument|_allocator
argument_list|)
name|HSATextSection
argument_list|(
name|_ctx
argument_list|)
return|;
if|if
condition|(
name|name
operator|==
literal|".note"
condition|)
name|contentType
operator|=
name|DefinedAtom
operator|::
name|typeRONote
expr_stmt|;
return|return
name|TargetLayout
operator|::
name|createSection
argument_list|(
name|name
argument_list|,
name|contentType
argument_list|,
name|contentPermissions
argument_list|,
name|sectionOrder
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief TargetHandler for AMDGPU
end_comment

begin_decl_stmt
name|class
name|AMDGPUTargetHandler
name|final
range|:
name|public
name|TargetHandler
block|{
name|public
operator|:
name|AMDGPUTargetHandler
argument_list|(
name|AMDGPULinkingContext
operator|&
name|targetInfo
argument_list|)
block|;
specifier|const
name|TargetRelocationHandler
operator|&
name|getRelocationHandler
argument_list|()
specifier|const
name|override
block|{
return|return
operator|*
name|_relocationHandler
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
name|getObjReader
argument_list|()
name|override
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|ELFReader
operator|<
name|ELFFile
operator|<
name|ELF64LE
operator|>>>
operator|(
name|_ctx
operator|)
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
name|getDSOReader
argument_list|()
name|override
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|ELFReader
operator|<
name|DynamicFile
operator|<
name|ELF64LE
operator|>>>
operator|(
name|_ctx
operator|)
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|getWriter
argument_list|()
name|override
block|;
name|private
operator|:
name|AMDGPULinkingContext
operator|&
name|_ctx
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|AMDGPUTargetLayout
operator|>
name|_targetLayout
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|AMDGPUTargetRelocationHandler
operator|>
name|_relocationHandler
block|; }
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|finalizeAMDGPURuntimeAtomValues
parameter_list|(
name|AMDGPUTargetLayout
modifier|&
name|layout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// end namespace elf
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

