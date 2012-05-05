begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- ObjectImage.h - Format independent executuable object image -----===//
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
comment|// This file declares a file format independent ObjectImage class.
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
name|LLVM_RUNTIMEDYLD_OBJECT_IMAGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIMEDYLD_OBJECT_IMAGE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ObjectImage
block|{
name|ObjectImage
argument_list|()
expr_stmt|;
comment|// = delete
name|ObjectImage
argument_list|(
specifier|const
name|ObjectImage
operator|&
name|other
argument_list|)
expr_stmt|;
comment|// = delete
name|protected
label|:
name|object
operator|::
name|ObjectFile
operator|*
name|ObjFile
expr_stmt|;
name|public
label|:
name|ObjectImage
argument_list|(
argument|object::ObjectFile *Obj
argument_list|)
block|{
name|ObjFile
operator|=
name|Obj
expr_stmt|;
block|}
name|virtual
operator|~
name|ObjectImage
argument_list|()
block|{}
name|virtual
name|object
operator|::
name|symbol_iterator
name|begin_symbols
argument_list|()
specifier|const
block|{
return|return
name|ObjFile
operator|->
name|begin_symbols
argument_list|()
return|;
block|}
name|virtual
name|object
operator|::
name|symbol_iterator
name|end_symbols
argument_list|()
specifier|const
block|{
return|return
name|ObjFile
operator|->
name|end_symbols
argument_list|()
return|;
block|}
name|virtual
name|object
operator|::
name|section_iterator
name|begin_sections
argument_list|()
specifier|const
block|{
return|return
name|ObjFile
operator|->
name|begin_sections
argument_list|()
return|;
block|}
name|virtual
name|object
operator|::
name|section_iterator
name|end_sections
argument_list|()
specifier|const
block|{
return|return
name|ObjFile
operator|->
name|end_sections
argument_list|()
return|;
block|}
name|virtual
comment|/* Triple::ArchType */
name|unsigned
name|getArch
argument_list|()
specifier|const
block|{
return|return
name|ObjFile
operator|->
name|getArch
argument_list|()
return|;
block|}
comment|// Subclasses can override these methods to update the image with loaded
comment|// addresses for sections and common symbols
name|virtual
name|void
name|updateSectionAddress
argument_list|(
specifier|const
name|object
operator|::
name|SectionRef
operator|&
name|Sec
argument_list|,
name|uint64_t
name|Addr
argument_list|)
block|{}
name|virtual
name|void
name|updateSymbolAddress
argument_list|(
specifier|const
name|object
operator|::
name|SymbolRef
operator|&
name|Sym
argument_list|,
name|uint64_t
name|Addr
argument_list|)
block|{}
comment|// Subclasses can override this method to provide JIT debugging support
name|virtual
name|void
name|registerWithDebugger
parameter_list|()
block|{}
name|virtual
name|void
name|deregisterWithDebugger
parameter_list|()
block|{}
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

begin_comment
comment|// LLVM_RUNTIMEDYLD_OBJECT_IMAGE_H
end_comment

end_unit

