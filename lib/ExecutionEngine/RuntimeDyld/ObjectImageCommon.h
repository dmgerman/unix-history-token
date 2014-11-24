begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectImageCommon.h - Format independent executuable object image -===//
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
name|LLVM_RUNTIMEDYLD_OBJECTIMAGECOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIMEDYLD_OBJECTIMAGECOMMON_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectImage.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|ObjectFile
decl_stmt|;
block|}
name|class
name|ObjectImageCommon
range|:
name|public
name|ObjectImage
block|{
name|ObjectImageCommon
argument_list|()
block|;
comment|// = delete
name|ObjectImageCommon
argument_list|(
specifier|const
name|ObjectImageCommon
operator|&
name|other
argument_list|)
block|;
comment|// = delete
name|void
name|anchor
argument_list|()
name|override
block|;
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|ObjFile
block|;
comment|// This form of the constructor allows subclasses to use
comment|// format-specific subclasses of ObjectFile directly
name|ObjectImageCommon
argument_list|(
name|ObjectBuffer
operator|*
name|Input
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|Obj
argument_list|)
operator|:
name|ObjectImage
argument_list|(
name|Input
argument_list|)
block|,
comment|// saves Input as Buffer and takes ownership
name|ObjFile
argument_list|(
argument|std::move(Obj)
argument_list|)
block|{   }
name|public
operator|:
name|ObjectImageCommon
argument_list|(
name|ObjectBuffer
operator|*
name|Input
argument_list|)
operator|:
name|ObjectImage
argument_list|(
argument|Input
argument_list|)
comment|// saves Input as Buffer and takes ownership
block|{
comment|// FIXME: error checking? createObjectFile returns an ErrorOr<ObjectFile*>
comment|// and should probably be checked for failure.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|Buf
argument_list|(
name|Buffer
operator|->
name|getMemBuffer
argument_list|()
argument_list|)
block|;
name|ObjFile
operator|.
name|reset
argument_list|(
name|object
operator|::
name|ObjectFile
operator|::
name|createObjectFile
argument_list|(
name|Buf
argument_list|)
operator|.
name|get
argument_list|()
argument_list|)
block|;   }
name|ObjectImageCommon
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|Input
argument_list|)
operator|:
name|ObjectImage
argument_list|(
name|nullptr
argument_list|)
block|,
name|ObjFile
argument_list|(
argument|std::move(Input)
argument_list|)
block|{}
name|virtual
operator|~
name|ObjectImageCommon
argument_list|()
block|{ }
name|object
operator|::
name|symbol_iterator
name|begin_symbols
argument_list|()
specifier|const
name|override
block|{
return|return
name|ObjFile
operator|->
name|symbol_begin
argument_list|()
return|;
block|}
name|object
operator|::
name|symbol_iterator
name|end_symbols
argument_list|()
specifier|const
name|override
block|{
return|return
name|ObjFile
operator|->
name|symbol_end
argument_list|()
return|;
block|}
name|object
operator|::
name|section_iterator
name|begin_sections
argument_list|()
specifier|const
name|override
block|{
return|return
name|ObjFile
operator|->
name|section_begin
argument_list|()
return|;
block|}
name|object
operator|::
name|section_iterator
name|end_sections
argument_list|()
specifier|const
name|override
block|{
return|return
name|ObjFile
operator|->
name|section_end
argument_list|()
return|;
block|}
comment|/* Triple::ArchType */
name|unsigned
name|getArch
argument_list|()
specifier|const
name|override
block|{
return|return
name|ObjFile
operator|->
name|getArch
argument_list|()
return|;
block|}
name|StringRef
name|getData
argument_list|()
specifier|const
name|override
block|{
return|return
name|ObjFile
operator|->
name|getData
argument_list|()
return|;
block|}
name|object
operator|::
name|ObjectFile
operator|*
name|getObjectFile
argument_list|()
specifier|const
name|override
block|{
return|return
name|ObjFile
operator|.
name|get
argument_list|()
return|;
block|}
comment|// Subclasses can override these methods to update the image with loaded
comment|// addresses for sections and common symbols
name|void
name|updateSectionAddress
argument_list|(
argument|const object::SectionRef&Sec
argument_list|,
argument|uint64_t Addr
argument_list|)
name|override
block|{}
name|void
name|updateSymbolAddress
argument_list|(
argument|const object::SymbolRef&Sym
argument_list|,
argument|uint64_t Addr
argument_list|)
name|override
block|{}
comment|// Subclasses can override these methods to provide JIT debugging support
name|void
name|registerWithDebugger
argument_list|()
name|override
block|{}
name|void
name|deregisterWithDebugger
argument_list|()
name|override
block|{}
expr|}
block|;  }
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

