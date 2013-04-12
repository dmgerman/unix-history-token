begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ProfileDataLoader.h - Load& convert profile info ----*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// The ProfileDataLoader class is used to load profiling data from a dump file.
end_comment

begin_comment
comment|// The ProfileDataT<FType, BType> class is used to store the mapping of this
end_comment

begin_comment
comment|// data to control flow edges.
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
name|LLVM_ANALYSIS_PROFILEDATALOADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PROFILEDATALOADER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ModulePass
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
comment|// Helper for dumping edges to dbgs().
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|O
operator|,
name|std
operator|::
name|pair
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
specifier|const
name|BasicBlock
operator|*
operator|>
name|E
operator|)
expr_stmt|;
comment|/// \brief The ProfileDataT<FType, BType> class is used to store the mapping of
comment|/// profiling data to control flow edges.
comment|///
comment|/// An edge is defined by its source and sink basic blocks.
name|template
operator|<
name|class
name|FType
operator|,
name|class
name|BType
operator|>
name|class
name|ProfileDataT
block|{
name|public
operator|:
comment|// The profiling information defines an Edge by its source and sink basic
comment|// blocks.
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|BType
operator|*
operator|,
specifier|const
name|BType
operator|*
operator|>
name|Edge
expr_stmt|;
name|private
operator|:
typedef|typedef
name|DenseMap
operator|<
name|Edge
operator|,
name|unsigned
operator|>
name|EdgeWeights
expr_stmt|;
comment|/// \brief Count the number of times a transition between two blocks is
comment|/// executed.
comment|///
comment|/// As a special case, we also hold an edge from the null BasicBlock to the
comment|/// entry block to indicate how many times the function was entered.
name|DenseMap
operator|<
specifier|const
name|FType
operator|*
operator|,
name|EdgeWeights
operator|>
name|EdgeInformation
expr_stmt|;
name|public
label|:
comment|/// getFunction() - Returns the Function for an Edge.
specifier|static
specifier|const
name|FType
modifier|*
name|getFunction
parameter_list|(
name|Edge
name|e
parameter_list|)
block|{
comment|// e.first may be NULL
name|assert
argument_list|(
operator|(
operator|(
operator|!
name|e
operator|.
name|first
operator|)
operator|||
operator|(
name|e
operator|.
name|first
operator|->
name|getParent
argument_list|()
operator|==
name|e
operator|.
name|second
operator|->
name|getParent
argument_list|()
operator|)
operator|)
operator|&&
literal|"A ProfileData::Edge can not be between two functions"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|e
operator|.
name|second
operator|&&
literal|"A ProfileData::Edge must have a real sink"
argument_list|)
expr_stmt|;
return|return
name|e
operator|.
name|second
operator|->
name|getParent
argument_list|()
return|;
block|}
comment|/// getEdge() - Creates an Edge between two BasicBlocks.
specifier|static
name|Edge
name|getEdge
parameter_list|(
specifier|const
name|BType
modifier|*
name|Src
parameter_list|,
specifier|const
name|BType
modifier|*
name|Dest
parameter_list|)
block|{
return|return
name|Edge
argument_list|(
name|Src
argument_list|,
name|Dest
argument_list|)
return|;
block|}
comment|/// getEdgeWeight - Return the number of times that a given edge was
comment|/// executed.
name|unsigned
name|getEdgeWeight
argument_list|(
name|Edge
name|e
argument_list|)
decl|const
block|{
specifier|const
name|FType
modifier|*
name|f
init|=
name|getFunction
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|assert
argument_list|(
operator|(
name|EdgeInformation
operator|.
name|find
argument_list|(
name|f
argument_list|)
operator|!=
name|EdgeInformation
operator|.
name|end
argument_list|()
operator|)
operator|&&
literal|"No profiling information for function"
argument_list|)
expr_stmt|;
name|EdgeWeights
name|weights
init|=
name|EdgeInformation
operator|.
name|find
argument_list|(
name|f
argument_list|)
operator|->
name|second
decl_stmt|;
name|assert
argument_list|(
operator|(
name|weights
operator|.
name|find
argument_list|(
name|e
argument_list|)
operator|!=
name|weights
operator|.
name|end
argument_list|()
operator|)
operator|&&
literal|"No profiling information for edge"
argument_list|)
expr_stmt|;
return|return
name|weights
operator|.
name|find
argument_list|(
name|e
argument_list|)
operator|->
name|second
return|;
block|}
comment|/// addEdgeWeight - Add 'weight' to the already stored execution count for
comment|/// this edge.
name|void
name|addEdgeWeight
parameter_list|(
name|Edge
name|e
parameter_list|,
name|unsigned
name|weight
parameter_list|)
block|{
name|EdgeInformation
index|[
name|getFunction
argument_list|(
name|e
argument_list|)
index|]
index|[
name|e
index|]
operator|+=
name|weight
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|ProfileDataT
operator|<
name|Function
operator|,
name|BasicBlock
operator|>
name|ProfileData
expr_stmt|;
end_typedef

begin_comment
comment|//typedef ProfileDataT<MachineFunction, MachineBasicBlock> MachineProfileData;
end_comment

begin_comment
comment|/// The ProfileDataLoader class is used to load raw profiling data from the
end_comment

begin_comment
comment|/// dump file.
end_comment

begin_decl_stmt
name|class
name|ProfileDataLoader
block|{
name|private
label|:
comment|/// The name of the file where the raw profiling data is stored.
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
expr_stmt|;
comment|/// A vector of the command line arguments used when the target program was
comment|/// run to generate profiling data.  One entry per program run.
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|,
literal|1
operator|>
name|CommandLines
expr_stmt|;
comment|/// The raw values for how many times each edge was traversed, values from
comment|/// multiple program runs are accumulated.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|32
operator|>
name|EdgeCounts
expr_stmt|;
name|public
label|:
comment|/// ProfileDataLoader ctor - Read the specified profiling data file, exiting
comment|/// the program if the file is invalid or broken.
name|ProfileDataLoader
argument_list|(
specifier|const
name|char
operator|*
name|ToolName
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|)
expr_stmt|;
comment|/// A special value used to represent the weight of an edge which has not
comment|/// been counted yet.
specifier|static
specifier|const
name|unsigned
name|Uncounted
decl_stmt|;
comment|/// getNumExecutions - Return the number of times the target program was run
comment|/// to generate this profiling data.
name|unsigned
name|getNumExecutions
argument_list|()
specifier|const
block|{
return|return
name|CommandLines
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// getExecution - Return the command line parameters used to generate the
comment|/// i'th set of profiling data.
specifier|const
name|std
operator|::
name|string
operator|&
name|getExecution
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|CommandLines
index|[
name|i
index|]
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getFileName
argument_list|()
specifier|const
block|{
return|return
name|Filename
return|;
block|}
comment|/// getRawEdgeCounts - Return the raw profiling data, this is just a list of
comment|/// numbers with no mappings to edges.
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getRawEdgeCounts
argument_list|()
specifier|const
block|{
return|return
name|EdgeCounts
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// createProfileMetadataLoaderPass - This function returns a Pass that loads
end_comment

begin_comment
comment|/// the profiling information for the module from the specified filename.
end_comment

begin_decl_stmt
name|ModulePass
modifier|*
name|createProfileMetadataLoaderPass
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

