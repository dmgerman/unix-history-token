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
name|LLVM_OBJECT_IROBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_IROBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/IRSymtab.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ModuleSymbolTable.h"
end_include

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
name|BitcodeModule
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|namespace
name|object
block|{
name|class
name|ObjectFile
decl_stmt|;
name|class
name|IRObjectFile
range|:
name|public
name|SymbolicFile
block|{
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|Mods
block|;
name|ModuleSymbolTable
name|SymTab
block|;
name|IRObjectFile
argument_list|(
argument|MemoryBufferRef Object
argument_list|,
argument|std::vector<std::unique_ptr<Module>> Mods
argument_list|)
block|;
name|public
operator|:
operator|~
name|IRObjectFile
argument_list|()
name|override
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
name|basic_symbol_iterator
name|symbol_begin
argument_list|()
specifier|const
name|override
block|;
name|basic_symbol_iterator
name|symbol_end
argument_list|()
specifier|const
name|override
block|;
name|StringRef
name|getTargetTriple
argument_list|()
specifier|const
block|;
specifier|static
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
comment|/// \brief Finds and returns bitcode embedded in the given object file, or an
comment|/// error code if not found.
specifier|static
name|ErrorOr
operator|<
name|MemoryBufferRef
operator|>
name|findBitcodeInObject
argument_list|(
specifier|const
name|ObjectFile
operator|&
name|Obj
argument_list|)
block|;
comment|/// \brief Finds and returns bitcode in the given memory buffer (which may
comment|/// be either a bitcode file or a native object file with embedded bitcode),
comment|/// or an error code if not found.
specifier|static
name|ErrorOr
operator|<
name|MemoryBufferRef
operator|>
name|findBitcodeInMemBuffer
argument_list|(
argument|MemoryBufferRef Object
argument_list|)
block|;
specifier|static
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|IRObjectFile
operator|>>
name|create
argument_list|(
argument|MemoryBufferRef Object
argument_list|,
argument|LLVMContext&Context
argument_list|)
block|; }
decl_stmt|;
comment|/// The contents of a bitcode file and its irsymtab. Any underlying data
comment|/// for the irsymtab are owned by Symtab and Strtab.
struct|struct
name|IRSymtabFile
block|{
name|std
operator|::
name|vector
operator|<
name|BitcodeModule
operator|>
name|Mods
expr_stmt|;
name|SmallVector
operator|<
name|char
operator|,
literal|0
operator|>
name|Symtab
operator|,
name|Strtab
expr_stmt|;
name|irsymtab
operator|::
name|Reader
name|TheReader
expr_stmt|;
block|}
struct|;
comment|/// Reads a bitcode file, creating its irsymtab if necessary.
name|Expected
operator|<
name|IRSymtabFile
operator|>
name|readIRSymtab
argument_list|(
argument|MemoryBufferRef MBRef
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

