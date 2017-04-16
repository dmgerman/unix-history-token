begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/IPO/FunctionImport.h - ThinLTO importing -*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
name|LLVM_FUNCTIONIMPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUNCTIONIMPORT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<unordered_set>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|GlobalValueSummary
decl_stmt|;
name|class
name|Module
decl_stmt|;
comment|/// The function importer is automatically importing function from other modules
comment|/// based on the provided summary informations.
name|class
name|FunctionImporter
block|{
name|public
label|:
comment|/// Set of functions to import from a source module. Each entry is a map
comment|/// containing all the functions to import for a source module.
comment|/// The keys is the GUID identifying a function to import, and the value
comment|/// is the threshold applied when deciding to import it.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GlobalValue
operator|::
name|GUID
operator|,
name|unsigned
operator|>
name|FunctionsToImportTy
expr_stmt|;
comment|/// The map contains an entry for every module to import from, the key being
comment|/// the module identifier to pass to the ModuleLoader. The value is the set of
comment|/// functions to import.
typedef|typedef
name|StringMap
operator|<
name|FunctionsToImportTy
operator|>
name|ImportMapTy
expr_stmt|;
comment|/// The set contains an entry for every global value the module exports.
typedef|typedef
name|std
operator|::
name|unordered_set
operator|<
name|GlobalValue
operator|::
name|GUID
operator|>
name|ExportSetTy
expr_stmt|;
comment|/// A function of this type is used to load modules referenced by the index.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
operator|(
name|StringRef
name|Identifier
operator|)
operator|>
name|ModuleLoaderTy
expr_stmt|;
comment|/// Create a Function Importer.
name|FunctionImporter
argument_list|(
argument|const ModuleSummaryIndex&Index
argument_list|,
argument|ModuleLoaderTy ModuleLoader
argument_list|)
block|:
name|Index
argument_list|(
name|Index
argument_list|)
operator|,
name|ModuleLoader
argument_list|(
argument|std::move(ModuleLoader)
argument_list|)
block|{}
comment|/// Import functions in Module \p M based on the supplied import list.
name|Expected
operator|<
name|bool
operator|>
name|importFunctions
argument_list|(
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|ImportMapTy
operator|&
name|ImportList
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// The summaries index used to trigger importing.
specifier|const
name|ModuleSummaryIndex
modifier|&
name|Index
decl_stmt|;
comment|/// Factory function to load a Module for a given identifier
name|ModuleLoaderTy
name|ModuleLoader
decl_stmt|;
block|}
empty_stmt|;
comment|/// The function importing pass
name|class
name|FunctionImportPass
range|:
name|public
name|PassInfoMixin
operator|<
name|FunctionImportPass
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
comment|/// Compute all the imports and exports for every module in the Index.
comment|///
comment|/// \p ModuleToDefinedGVSummaries contains for each Module a map
comment|/// (GUID -> Summary) for every global defined in the module.
comment|///
comment|/// \p ImportLists will be populated with an entry for every Module we are
comment|/// importing into. This entry is itself a map that can be passed to
comment|/// FunctionImporter::importFunctions() above (see description there).
comment|///
comment|/// \p ExportLists contains for each Module the set of globals (GUID) that will
comment|/// be imported by another module, or referenced by such a function. I.e. this
comment|/// is the set of globals that need to be promoted/renamed appropriately.
comment|///
comment|/// \p DeadSymbols (optional) contains a list of GUID that are deemed "dead" and
comment|/// will be ignored for the purpose of importing.
name|void
name|ComputeCrossModuleImport
argument_list|(
specifier|const
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
specifier|const
name|StringMap
operator|<
name|GVSummaryMapTy
operator|>
operator|&
name|ModuleToDefinedGVSummaries
argument_list|,
name|StringMap
operator|<
name|FunctionImporter
operator|::
name|ImportMapTy
operator|>
operator|&
name|ImportLists
argument_list|,
name|StringMap
operator|<
name|FunctionImporter
operator|::
name|ExportSetTy
operator|>
operator|&
name|ExportLists
argument_list|,
specifier|const
name|DenseSet
operator|<
name|GlobalValue
operator|::
name|GUID
operator|>
operator|*
name|DeadSymbols
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// Compute all the imports for the given module using the Index.
comment|///
comment|/// \p ImportList will be populated with a map that can be passed to
comment|/// FunctionImporter::importFunctions() above (see description there).
name|void
name|ComputeCrossModuleImportForModule
argument_list|(
name|StringRef
name|ModulePath
argument_list|,
specifier|const
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|FunctionImporter
operator|::
name|ImportMapTy
operator|&
name|ImportList
argument_list|)
decl_stmt|;
comment|/// Compute all the symbols that are "dead": i.e these that can't be reached
comment|/// in the graph from any of the given symbols listed in
comment|/// \p GUIDPreservedSymbols.
name|DenseSet
operator|<
name|GlobalValue
operator|::
name|GUID
operator|>
name|computeDeadSymbols
argument_list|(
specifier|const
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
specifier|const
name|DenseSet
operator|<
name|GlobalValue
operator|::
name|GUID
operator|>
operator|&
name|GUIDPreservedSymbols
argument_list|)
expr_stmt|;
comment|/// Compute the set of summaries needed for a ThinLTO backend compilation of
comment|/// \p ModulePath.
comment|//
comment|/// This includes summaries from that module (in case any global summary based
comment|/// optimizations were recorded) and from any definitions in other modules that
comment|/// should be imported.
comment|//
comment|/// \p ModuleToSummariesForIndex will be populated with the needed summaries
comment|/// from each required module path. Use a std::map instead of StringMap to get
comment|/// stable order for bitcode emission.
name|void
name|gatherImportedSummariesForModule
argument_list|(
name|StringRef
name|ModulePath
argument_list|,
specifier|const
name|StringMap
operator|<
name|GVSummaryMapTy
operator|>
operator|&
name|ModuleToDefinedGVSummaries
argument_list|,
specifier|const
name|FunctionImporter
operator|::
name|ImportMapTy
operator|&
name|ImportList
argument_list|,
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
name|GVSummaryMapTy
operator|>
operator|&
name|ModuleToSummariesForIndex
argument_list|)
decl_stmt|;
comment|/// Emit into \p OutputFilename the files module \p ModulePath will import from.
name|std
operator|::
name|error_code
name|EmitImportsFiles
argument_list|(
argument|StringRef ModulePath
argument_list|,
argument|StringRef OutputFilename
argument_list|,
argument|const FunctionImporter::ImportMapTy&ModuleImports
argument_list|)
expr_stmt|;
comment|/// Resolve WeakForLinker values in \p TheModule based on the information
comment|/// recorded in the summaries during global summary-based analysis.
name|void
name|thinLTOResolveWeakForLinkerModule
parameter_list|(
name|Module
modifier|&
name|TheModule
parameter_list|,
specifier|const
name|GVSummaryMapTy
modifier|&
name|DefinedGlobals
parameter_list|)
function_decl|;
comment|/// Internalize \p TheModule based on the information recorded in the summaries
comment|/// during global summary-based analysis.
name|void
name|thinLTOInternalizeModule
parameter_list|(
name|Module
modifier|&
name|TheModule
parameter_list|,
specifier|const
name|GVSummaryMapTy
modifier|&
name|DefinedGlobals
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUNCTIONIMPORT_H
end_comment

end_unit

