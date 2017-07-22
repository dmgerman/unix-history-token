begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ImportedFunctionsInliningStats.h ------------------------*- C++ -*-===//
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
comment|// Generating inliner statistics for imported functions, mostly useful for
end_comment

begin_comment
comment|// ThinLTO.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_UTILS_IMPORTEDFUNCTIONSINLININGSTATISTICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_IMPORTEDFUNCTIONSINLININGSTATISTICS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
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
name|class
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
comment|/// \brief Calculate and dump ThinLTO specific inliner stats.
comment|/// The main statistics are:
comment|/// (1) Number of inlined imported functions,
comment|/// (2) Number of imported functions inlined into importing module (indirect),
comment|/// (3) Number of non imported functions inlined into importing module
comment|/// (indirect).
comment|/// The difference between first and the second is that first stat counts
comment|/// all performed inlines on imported functions, but the second one only the
comment|/// functions that have been eventually inlined to a function in the importing
comment|/// module (by a chain of inlines). Because llvm uses bottom-up inliner, it is
comment|/// possible to e.g. import function `A`, `B` and then inline `B` to `A`,
comment|/// and after this `A` might be too big to be inlined into some other function
comment|/// that calls it. It calculates this statistic by building graph, where
comment|/// the nodes are functions, and edges are performed inlines and then by marking
comment|/// the edges starting from not imported function.
comment|///
comment|/// If `Verbose` is set to true, then it also dumps statistics
comment|/// per each inlined function, sorted by the greatest inlines count like
comment|/// - number of performed inlines
comment|/// - number of performed inlines to importing module
name|class
name|ImportedFunctionsInliningStatistics
block|{
name|private
label|:
comment|/// InlineGraphNode represents node in graph of inlined functions.
struct|struct
name|InlineGraphNode
block|{
comment|// Default-constructible and movable.
name|InlineGraphNode
argument_list|()
operator|=
expr|default
expr_stmt|;
name|InlineGraphNode
argument_list|(
name|InlineGraphNode
operator|&&
argument_list|)
operator|=
expr|default
expr_stmt|;
name|InlineGraphNode
modifier|&
name|operator
init|=
operator|(
name|InlineGraphNode
operator|&&
operator|)
operator|=
expr|default
decl_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|InlineGraphNode
operator|*
operator|,
literal|8
operator|>
name|InlinedCallees
expr_stmt|;
comment|/// Incremented every direct inline.
name|int32_t
name|NumberOfInlines
init|=
literal|0
decl_stmt|;
comment|/// Number of inlines into non imported function (possibly indirect via
comment|/// intermediate inlines). Computed based on graph search.
name|int32_t
name|NumberOfRealInlines
init|=
literal|0
decl_stmt|;
name|bool
name|Imported
init|=
name|false
decl_stmt|;
name|bool
name|Visited
init|=
name|false
decl_stmt|;
block|}
struct|;
name|public
label|:
name|ImportedFunctionsInliningStatistics
argument_list|()
operator|=
expr|default
expr_stmt|;
name|ImportedFunctionsInliningStatistics
argument_list|(
specifier|const
name|ImportedFunctionsInliningStatistics
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
comment|/// Set information like AllFunctions, ImportedFunctions, ModuleName.
name|void
name|setModuleInfo
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// Record inline of @param Callee to @param Caller for statistis.
name|void
name|recordInline
parameter_list|(
specifier|const
name|Function
modifier|&
name|Caller
parameter_list|,
specifier|const
name|Function
modifier|&
name|Callee
parameter_list|)
function_decl|;
comment|/// Dump stats computed with InlinerStatistics class.
comment|/// If @param Verbose is true then separate statistics for every inlined
comment|/// function will be printed.
name|void
name|dump
parameter_list|(
name|bool
name|Verbose
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Creates new Node in NodeMap and sets attributes, or returns existed one.
name|InlineGraphNode
modifier|&
name|createInlineGraphNode
parameter_list|(
specifier|const
name|Function
modifier|&
parameter_list|)
function_decl|;
name|void
name|calculateRealInlines
parameter_list|()
function_decl|;
name|void
name|dfs
parameter_list|(
name|InlineGraphNode
modifier|&
name|GraphNode
parameter_list|)
function_decl|;
name|using
name|NodesMapTy
init|=
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|InlineGraphNode
operator|>>
decl_stmt|;
name|using
name|SortedNodesTy
init|=
name|std
operator|::
name|vector
operator|<
specifier|const
name|NodesMapTy
operator|::
name|MapEntryTy
operator|*
operator|>
decl_stmt|;
comment|/// Returns vector of elements sorted by
comment|/// (-NumberOfInlines, -NumberOfRealInlines, FunctionName).
name|SortedNodesTy
name|getSortedNodes
parameter_list|()
function_decl|;
name|private
label|:
comment|/// This map manage life of all InlineGraphNodes. Unique pointer to
comment|/// InlineGraphNode used since the node pointers are also saved in the
comment|/// InlinedCallees vector. If it would store InlineGraphNode instead then the
comment|/// address of the node would not be invariant.
name|NodesMapTy
name|NodesMap
decl_stmt|;
comment|/// Non external functions that have some other function inlined inside.
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|NonImportedCallers
expr_stmt|;
name|int
name|AllFunctions
init|=
literal|0
decl_stmt|;
name|int
name|ImportedFunctions
init|=
literal|0
decl_stmt|;
name|StringRef
name|ModuleName
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_IMPORTEDFUNCTIONSINLININGSTATISTICS_H
end_comment

end_unit

