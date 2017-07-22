begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Symbolize.h ----------------------------------------------*- C++ -*-===//
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
comment|// Header for LLVM symbolization library.
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
name|LLVM_DEBUGINFO_SYMBOLIZE_SYMBOLIZE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_SYMBOLIZE_SYMBOLIZE_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/Symbolize/SymbolizableModule.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Binary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
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
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|symbolize
block|{
name|using
name|namespace
name|object
decl_stmt|;
name|using
name|FunctionNameKind
init|=
name|DILineInfoSpecifier
operator|::
name|FunctionNameKind
decl_stmt|;
name|class
name|LLVMSymbolizer
block|{
name|public
label|:
struct|struct
name|Options
block|{
name|FunctionNameKind
name|PrintFunctions
decl_stmt|;
name|bool
name|UseSymbolTable
range|:
literal|1
decl_stmt|;
name|bool
name|Demangle
range|:
literal|1
decl_stmt|;
name|bool
name|RelativeAddresses
range|:
literal|1
decl_stmt|;
name|std
operator|::
name|string
name|DefaultArch
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|DsymHints
expr_stmt|;
name|Options
argument_list|(
argument|FunctionNameKind PrintFunctions = FunctionNameKind::LinkageName
argument_list|,
argument|bool UseSymbolTable = true
argument_list|,
argument|bool Demangle = true
argument_list|,
argument|bool RelativeAddresses = false
argument_list|,
argument|std::string DefaultArch =
literal|""
argument_list|)
block|:
name|PrintFunctions
argument_list|(
name|PrintFunctions
argument_list|)
operator|,
name|UseSymbolTable
argument_list|(
name|UseSymbolTable
argument_list|)
operator|,
name|Demangle
argument_list|(
name|Demangle
argument_list|)
operator|,
name|RelativeAddresses
argument_list|(
name|RelativeAddresses
argument_list|)
operator|,
name|DefaultArch
argument_list|(
argument|std::move(DefaultArch)
argument_list|)
block|{}
block|}
struct|;
name|LLVMSymbolizer
argument_list|(
specifier|const
name|Options
operator|&
name|Opts
operator|=
name|Options
argument_list|()
argument_list|)
operator|:
name|Opts
argument_list|(
argument|Opts
argument_list|)
block|{}
operator|~
name|LLVMSymbolizer
argument_list|()
block|{
name|flush
argument_list|()
block|;   }
name|Expected
operator|<
name|DILineInfo
operator|>
name|symbolizeCode
argument_list|(
argument|const std::string&ModuleName
argument_list|,
argument|uint64_t ModuleOffset
argument_list|)
expr_stmt|;
name|Expected
operator|<
name|DIInliningInfo
operator|>
name|symbolizeInlinedCode
argument_list|(
argument|const std::string&ModuleName
argument_list|,
argument|uint64_t ModuleOffset
argument_list|)
expr_stmt|;
name|Expected
operator|<
name|DIGlobal
operator|>
name|symbolizeData
argument_list|(
argument|const std::string&ModuleName
argument_list|,
argument|uint64_t ModuleOffset
argument_list|)
expr_stmt|;
name|void
name|flush
parameter_list|()
function_decl|;
specifier|static
name|std
operator|::
name|string
name|DemangleName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
specifier|const
name|SymbolizableModule
operator|*
name|DbiModuleDescriptor
argument_list|)
expr_stmt|;
name|private
label|:
comment|// Bundles together object file with code/data and object file with
comment|// corresponding debug info. These objects can be the same.
name|using
name|ObjectPair
init|=
name|std
operator|::
name|pair
operator|<
name|ObjectFile
operator|*
decl_stmt|,
name|ObjectFile
modifier|*
decl|>
decl_stmt|;
comment|/// Returns a SymbolizableModule or an error if loading debug info failed.
comment|/// Only one attempt is made to load a module, and errors during loading are
comment|/// only reported once. Subsequent calls to get module info for a module that
comment|/// failed to load will return nullptr.
name|Expected
operator|<
name|SymbolizableModule
operator|*
operator|>
name|getOrCreateModuleInfo
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ModuleName
argument_list|)
expr_stmt|;
name|ObjectFile
modifier|*
name|lookUpDsymFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Path
argument_list|,
specifier|const
name|MachOObjectFile
operator|*
name|ExeObj
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ArchName
argument_list|)
decl_stmt|;
name|ObjectFile
modifier|*
name|lookUpDebuglinkObject
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Path
argument_list|,
specifier|const
name|ObjectFile
operator|*
name|Obj
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ArchName
argument_list|)
decl_stmt|;
comment|/// \brief Returns pair of pointers to object and debug object.
name|Expected
operator|<
name|ObjectPair
operator|>
name|getOrCreateObjectPair
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Path
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ArchName
argument_list|)
expr_stmt|;
comment|/// \brief Return a pointer to object file at specified path, for a specified
comment|/// architecture (e.g. if path refers to a Mach-O universal binary, only one
comment|/// object file from it will be returned).
name|Expected
operator|<
name|ObjectFile
operator|*
operator|>
name|getOrCreateObject
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Path
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ArchName
argument_list|)
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|SymbolizableModule
operator|>>
name|Modules
expr_stmt|;
comment|/// \brief Contains cached results of getOrCreateObjectPair().
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
operator|,
name|ObjectPair
operator|>
name|ObjectPairForPathArch
expr_stmt|;
comment|/// \brief Contains parsed binary for each path, or parsing error.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|OwningBinary
operator|<
name|Binary
operator|>>
name|BinaryForPath
expr_stmt|;
comment|/// \brief Parsed object file for path/architecture pair, where "path" refers
comment|/// to Mach-O universal binary.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|ObjectFile
operator|>>
name|ObjectForUBPathAndArch
expr_stmt|;
name|Options
name|Opts
decl_stmt|;
block|}
empty_stmt|;
block|}
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
comment|// LLVM_DEBUGINFO_SYMBOLIZE_SYMBOLIZE_H
end_comment

end_unit

