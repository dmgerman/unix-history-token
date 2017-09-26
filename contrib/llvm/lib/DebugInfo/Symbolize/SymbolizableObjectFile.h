begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolizableObjectFile.h ---------------------------------*- C++ -*-===//
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
comment|// This file declares the SymbolizableObjectFile class.
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
name|LLVM_LIB_DEBUGINFO_SYMBOLIZE_SYMBOLIZABLEOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_DEBUGINFO_SYMBOLIZE_SYMBOLIZABLEOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/Symbolize/SymbolizableModule.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataExtractor
decl_stmt|;
name|namespace
name|symbolize
block|{
name|class
name|SymbolizableObjectFile
range|:
name|public
name|SymbolizableModule
block|{
name|public
operator|:
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SymbolizableObjectFile
operator|>>
name|create
argument_list|(
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|DIContext
operator|>
name|DICtx
argument_list|)
block|;
name|DILineInfo
name|symbolizeCode
argument_list|(
argument|uint64_t ModuleOffset
argument_list|,
argument|FunctionNameKind FNKind
argument_list|,
argument|bool UseSymbolTable
argument_list|)
specifier|const
name|override
block|;
name|DIInliningInfo
name|symbolizeInlinedCode
argument_list|(
argument|uint64_t ModuleOffset
argument_list|,
argument|FunctionNameKind FNKind
argument_list|,
argument|bool UseSymbolTable
argument_list|)
specifier|const
name|override
block|;
name|DIGlobal
name|symbolizeData
argument_list|(
argument|uint64_t ModuleOffset
argument_list|)
specifier|const
name|override
block|;
comment|// Return true if this is a 32-bit x86 PE COFF module.
name|bool
name|isWin32Module
argument_list|()
specifier|const
name|override
block|;
comment|// Returns the preferred base of the module, i.e. where the loader would place
comment|// it in memory assuming there were no conflicts.
name|uint64_t
name|getModulePreferredBase
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|bool
name|shouldOverrideWithSymbolTable
argument_list|(
argument|FunctionNameKind FNKind
argument_list|,
argument|bool UseSymbolTable
argument_list|)
specifier|const
block|;
name|bool
name|getNameFromSymbolTable
argument_list|(
argument|object::SymbolRef::Type Type
argument_list|,
argument|uint64_t Address
argument_list|,
argument|std::string&Name
argument_list|,
argument|uint64_t&Addr
argument_list|,
argument|uint64_t&Size
argument_list|)
specifier|const
block|;
comment|// For big-endian PowerPC64 ELF, OpdAddress is the address of the .opd
comment|// (function descriptor) section and OpdExtractor refers to its contents.
name|std
operator|::
name|error_code
name|addSymbol
argument_list|(
argument|const object::SymbolRef&Symbol
argument_list|,
argument|uint64_t SymbolSize
argument_list|,
argument|DataExtractor *OpdExtractor = nullptr
argument_list|,
argument|uint64_t OpdAddress =
literal|0
argument_list|)
block|;
name|std
operator|::
name|error_code
name|addCoffExportSymbols
argument_list|(
specifier|const
name|object
operator|::
name|COFFObjectFile
operator|*
name|CoffObj
argument_list|)
block|;
name|object
operator|::
name|ObjectFile
operator|*
name|Module
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|DIContext
operator|>
name|DebugInfoContext
block|;    struct
name|SymbolDesc
block|{
name|uint64_t
name|Addr
block|;
comment|// If size is 0, assume that symbol occupies the whole memory range up to
comment|// the following symbol.
name|uint64_t
name|Size
block|;
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SymbolDesc
operator|&
name|s1
expr|,
specifier|const
name|SymbolDesc
operator|&
name|s2
operator|)
block|{
return|return
name|s1
operator|.
name|Addr
operator|<
name|s2
operator|.
name|Addr
return|;
block|}
expr|}
block|;
name|std
operator|::
name|map
operator|<
name|SymbolDesc
block|,
name|StringRef
operator|>
name|Functions
block|;
name|std
operator|::
name|map
operator|<
name|SymbolDesc
block|,
name|StringRef
operator|>
name|Objects
block|;
name|SymbolizableObjectFile
argument_list|(
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|DIContext
operator|>
name|DICtx
argument_list|)
block|; }
block|;  }
comment|// end namespace symbolize
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
comment|// LLVM_LIB_DEBUGINFO_SYMBOLIZE_SYMBOLIZABLEOBJECTFILE_H
end_comment

end_unit

