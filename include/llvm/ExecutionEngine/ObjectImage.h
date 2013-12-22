begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- ObjectImage.h - Format independent executuable object image -----===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//		       The LLVM Compiler Infrastructure
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
name|LLVM_EXECUTIONENGINE_OBJECTIMAGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_OBJECTIMAGE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ObjectImage - A container class that represents an ObjectFile that has been
comment|/// or is in the process of being loaded into memory for execution.
name|class
name|ObjectImage
block|{
name|ObjectImage
argument_list|()
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|ObjectImage
argument_list|(
argument|const ObjectImage&other
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|protected
label|:
name|OwningPtr
operator|<
name|ObjectBuffer
operator|>
name|Buffer
expr_stmt|;
name|public
label|:
name|ObjectImage
argument_list|(
name|ObjectBuffer
operator|*
name|Input
argument_list|)
operator|:
name|Buffer
argument_list|(
argument|Input
argument_list|)
block|{}
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
operator|=
literal|0
expr_stmt|;
name|virtual
name|object
operator|::
name|symbol_iterator
name|end_symbols
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|object
operator|::
name|section_iterator
name|begin_sections
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|object
operator|::
name|section_iterator
name|end_sections
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
comment|/* Triple::ArchType */
name|unsigned
name|getArch
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
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
init|=
literal|0
decl_stmt|;
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
init|=
literal|0
decl_stmt|;
name|virtual
name|StringRef
name|getData
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|object
operator|::
name|ObjectFile
operator|*
name|getObjectFile
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Subclasses can override these methods to provide JIT debugging support
name|virtual
name|void
name|registerWithDebugger
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|deregisterWithDebugger
parameter_list|()
init|=
literal|0
function_decl|;
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
comment|// LLVM_EXECUTIONENGINE_OBJECTIMAGE_H
end_comment

end_unit

