begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IRObjectFile.h - LLVM IR object file implementation ------*- C++ -*-===//
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
comment|// This file declares the IRObjectFile template class.
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
name|LLVM_OBJECT_IR_OBJECT_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_IR_OBJECT_FILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/SymbolicFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Mangler
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|namespace
name|object
block|{
name|class
name|IRObjectFile
range|:
name|public
name|SymbolicFile
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|Mangler
operator|>
name|Mang
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
block|,
name|uint32_t
operator|>>
name|AsmSymbols
block|;
name|public
operator|:
name|IRObjectFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|Object
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|)
block|;
operator|~
name|IRObjectFile
argument_list|()
block|;
name|void
name|moveSymbolNext
argument_list|(
argument|DataRefImpl&Symb
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|error_code
name|printSymbolName
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|getSymbolFlags
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|GlobalValue
operator|*
name|getSymbolGV
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
block|;
name|basic_symbol_iterator
name|symbol_begin_impl
argument_list|()
specifier|const
name|override
block|;
name|basic_symbol_iterator
name|symbol_end_impl
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|IRObjectFile
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getModule
argument_list|()
return|;
block|}
name|Module
operator|&
name|getModule
argument_list|()
block|{
return|return
operator|*
name|M
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Binary *v
argument_list|)
block|{
return|return
name|v
operator|->
name|isIR
argument_list|()
return|;
block|}
specifier|static
name|ErrorOr
operator|<
name|IRObjectFile
operator|*
operator|>
name|createIRObjectFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|Object
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|)
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

