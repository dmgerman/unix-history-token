begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- COFFImportFile.h - COFF short import file implementation -*- C++ -*-===//
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
comment|// COFF short import file is a special kind of file which contains
end_comment

begin_comment
comment|// only symbol names for DLL-exported symbols. This class implements
end_comment

begin_comment
comment|// SymbolicFile interface for the file.
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
name|LLVM_OBJECT_COFF_IMPORT_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_COFF_IMPORT_FILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/COFF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/IRObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/SymbolicFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|COFFImportFile
range|:
name|public
name|SymbolicFile
block|{
name|public
operator|:
name|COFFImportFile
argument_list|(
argument|MemoryBufferRef Source
argument_list|)
operator|:
name|SymbolicFile
argument_list|(
argument|ID_COFFImportFile
argument_list|,
argument|Source
argument_list|)
block|{}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|Binary const *V
argument_list|)
block|{
return|return
name|V
operator|->
name|isCOFFImportFile
argument_list|()
return|;
block|}
name|void
name|moveSymbolNext
argument_list|(
argument|DataRefImpl&Symb
argument_list|)
specifier|const
name|override
block|{
operator|++
name|Symb
operator|.
name|p
block|; }
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
block|{
if|if
condition|(
name|Symb
operator|.
name|p
operator|==
literal|0
condition|)
name|OS
operator|<<
literal|"__imp_"
expr_stmt|;
name|OS
operator|<<
name|StringRef
argument_list|(
name|Data
operator|.
name|getBufferStart
argument_list|()
operator|+
sizeof|sizeof
argument_list|(
name|coff_import_header
argument_list|)
argument_list|)
block|;
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
name|uint32_t
name|getSymbolFlags
argument_list|(
name|DataRefImpl
name|Symb
argument_list|)
decl|const
name|override
block|{
return|return
name|SymbolRef
operator|::
name|SF_Global
return|;
block|}
name|basic_symbol_iterator
name|symbol_begin
argument_list|()
specifier|const
name|override
block|{
return|return
name|BasicSymbolRef
argument_list|(
name|DataRefImpl
argument_list|()
argument_list|,
name|this
argument_list|)
return|;
block|}
name|basic_symbol_iterator
name|symbol_end
argument_list|()
specifier|const
name|override
block|{
name|DataRefImpl
name|Symb
block|;
name|Symb
operator|.
name|p
operator|=
name|isData
argument_list|()
condition|?
literal|1
else|:
literal|2
block|;
return|return
name|BasicSymbolRef
argument_list|(
name|Symb
argument_list|,
name|this
argument_list|)
return|;
block|}
specifier|const
name|coff_import_header
operator|*
name|getCOFFImportHeader
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|object
operator|::
name|coff_import_header
operator|*
operator|>
operator|(
name|Data
operator|.
name|getBufferStart
argument_list|()
operator|)
return|;
block|}
name|private
label|:
name|bool
name|isData
argument_list|()
specifier|const
block|{
return|return
name|getCOFFImportHeader
argument_list|()
operator|->
name|getType
argument_list|()
operator|==
name|COFF
operator|::
name|IMPORT_DATA
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace object
end_comment

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

