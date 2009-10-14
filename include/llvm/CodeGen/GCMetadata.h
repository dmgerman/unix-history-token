begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GCMetadata.h - Garbage collector metadata -------------------------===//
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
comment|// This file declares the GCFunctionInfo and GCModuleInfo classes, which are
end_comment

begin_comment
comment|// used as a communication channel from the target code generator to the target
end_comment

begin_comment
comment|// garbage collectors. This interface allows code generators and garbage
end_comment

begin_comment
comment|// collectors to be developed independently.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The GCFunctionInfo class logs the data necessary to build a type accurate
end_comment

begin_comment
comment|// stack map. The code generator outputs:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   - Safe points as specified by the GCStrategy's NeededSafePoints.
end_comment

begin_comment
comment|//   - Stack offsets for GC roots, as specified by calls to llvm.gcroot
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// As a refinement, liveness analysis calculates the set of live roots at each
end_comment

begin_comment
comment|// safe point. Liveness analysis is not presently performed by the code
end_comment

begin_comment
comment|// generator, so all roots are assumed live.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GCModuleInfo simply collects GCFunctionInfo instances for each Function as
end_comment

begin_comment
comment|// they are compiled. This accretion is necessary for collectors which must emit
end_comment

begin_comment
comment|// a stack map for the compilation unit as a whole. Therefore, GCFunctionInfo
end_comment

begin_comment
comment|// outlives the MachineFunction from which it is derived and must not refer to
end_comment

begin_comment
comment|// any code generator data structures.
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
name|LLVM_CODEGEN_GCMETADATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GCMETADATA_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|GCStrategy
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|namespace
name|GC
block|{
comment|/// PointKind - The type of a collector-safe point.
comment|///
enum|enum
name|PointKind
block|{
name|Loop
block|,
comment|//< Instr is a loop (backwards branch).
name|Return
block|,
comment|//< Instr is a return instruction.
name|PreCall
block|,
comment|//< Instr is a call instruction.
name|PostCall
comment|//< Instr is the return address of a call.
block|}
enum|;
block|}
comment|/// GCPoint - Metadata for a collector-safe point in machine code.
comment|///
struct|struct
name|GCPoint
block|{
name|GC
operator|::
name|PointKind
name|Kind
expr_stmt|;
comment|//< The kind of the safe point.
name|unsigned
name|Num
decl_stmt|;
comment|//< Usually a label.
name|GCPoint
argument_list|(
argument|GC::PointKind K
argument_list|,
argument|unsigned N
argument_list|)
block|:
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|Num
argument_list|(
argument|N
argument_list|)
block|{}
block|}
struct|;
comment|/// GCRoot - Metadata for a pointer to an object managed by the garbage
comment|/// collector.
struct|struct
name|GCRoot
block|{
name|int
name|Num
decl_stmt|;
comment|//< Usually a frame index.
name|int
name|StackOffset
decl_stmt|;
comment|//< Offset from the stack pointer.
name|Constant
modifier|*
name|Metadata
decl_stmt|;
comment|//< Metadata straight from the call to llvm.gcroot.
name|GCRoot
argument_list|(
argument|int N
argument_list|,
argument|Constant *MD
argument_list|)
block|:
name|Num
argument_list|(
name|N
argument_list|)
operator|,
name|StackOffset
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|Metadata
argument_list|(
argument|MD
argument_list|)
block|{}
block|}
struct|;
comment|/// GCFunctionInfo - Garbage collection metadata for a single function.
comment|///
name|class
name|GCFunctionInfo
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|GCPoint
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|GCRoot
operator|>
operator|::
name|iterator
name|roots_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|GCRoot
operator|>
operator|::
name|const_iterator
name|live_iterator
expr_stmt|;
name|private
label|:
specifier|const
name|Function
modifier|&
name|F
decl_stmt|;
name|GCStrategy
modifier|&
name|S
decl_stmt|;
name|uint64_t
name|FrameSize
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|GCRoot
operator|>
name|Roots
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|GCPoint
operator|>
name|SafePoints
expr_stmt|;
comment|// FIXME: Liveness. A 2D BitVector, perhaps?
comment|//
comment|//   BitVector Liveness;
comment|//
comment|//   bool islive(int point, int root) =
comment|//     Liveness[point * SafePoints.size() + root]
comment|//
comment|// The bit vector is the more compact representation where>3.2% of roots
comment|// are live per safe point (1.5% on 64-bit hosts).
name|public
label|:
name|GCFunctionInfo
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|,
name|GCStrategy
operator|&
name|S
argument_list|)
expr_stmt|;
operator|~
name|GCFunctionInfo
argument_list|()
expr_stmt|;
comment|/// getFunction - Return the function to which this metadata applies.
comment|///
specifier|const
name|Function
operator|&
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|F
return|;
block|}
comment|/// getStrategy - Return the GC strategy for the function.
comment|///
name|GCStrategy
modifier|&
name|getStrategy
parameter_list|()
block|{
return|return
name|S
return|;
block|}
comment|/// addStackRoot - Registers a root that lives on the stack. Num is the
comment|///                stack object ID for the alloca (if the code generator is
comment|//                 using  MachineFrameInfo).
name|void
name|addStackRoot
parameter_list|(
name|int
name|Num
parameter_list|,
name|Constant
modifier|*
name|Metadata
parameter_list|)
block|{
name|Roots
operator|.
name|push_back
argument_list|(
name|GCRoot
argument_list|(
name|Num
argument_list|,
name|Metadata
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// addSafePoint - Notes the existence of a safe point. Num is the ID of the
comment|/// label just prior to the safe point (if the code generator is using
comment|/// MachineModuleInfo).
name|void
name|addSafePoint
argument_list|(
name|GC
operator|::
name|PointKind
name|Kind
argument_list|,
name|unsigned
name|Num
argument_list|)
block|{
name|SafePoints
operator|.
name|push_back
argument_list|(
name|GCPoint
argument_list|(
name|Kind
argument_list|,
name|Num
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// getFrameSize/setFrameSize - Records the function's frame size.
comment|///
name|uint64_t
name|getFrameSize
argument_list|()
specifier|const
block|{
return|return
name|FrameSize
return|;
block|}
name|void
name|setFrameSize
parameter_list|(
name|uint64_t
name|S
parameter_list|)
block|{
name|FrameSize
operator|=
name|S
expr_stmt|;
block|}
comment|/// begin/end - Iterators for safe points.
comment|///
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|SafePoints
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|SafePoints
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|SafePoints
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// roots_begin/roots_end - Iterators for all roots in the function.
comment|///
name|roots_iterator
name|roots_begin
parameter_list|()
block|{
return|return
name|Roots
operator|.
name|begin
argument_list|()
return|;
block|}
name|roots_iterator
name|roots_end
parameter_list|()
block|{
return|return
name|Roots
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|roots_size
argument_list|()
specifier|const
block|{
return|return
name|Roots
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// live_begin/live_end - Iterators for live roots at a given safe point.
comment|///
name|live_iterator
name|live_begin
parameter_list|(
specifier|const
name|iterator
modifier|&
name|p
parameter_list|)
block|{
return|return
name|roots_begin
argument_list|()
return|;
block|}
name|live_iterator
name|live_end
parameter_list|(
specifier|const
name|iterator
modifier|&
name|p
parameter_list|)
block|{
return|return
name|roots_end
argument_list|()
return|;
block|}
name|size_t
name|live_size
argument_list|(
specifier|const
name|iterator
operator|&
name|p
argument_list|)
decl|const
block|{
return|return
name|roots_size
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// GCModuleInfo - Garbage collection metadata for a whole module.
comment|///
name|class
name|GCModuleInfo
range|:
name|public
name|ImmutablePass
block|{
typedef|typedef
name|StringMap
operator|<
name|GCStrategy
operator|*
operator|>
name|strategy_map_type
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|GCStrategy
operator|*
operator|>
name|list_type
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
operator|,
name|GCFunctionInfo
operator|*
operator|>
name|finfo_map_type
expr_stmt|;
name|strategy_map_type
name|StrategyMap
decl_stmt|;
name|list_type
name|StrategyList
decl_stmt|;
name|finfo_map_type
name|FInfoMap
decl_stmt|;
name|GCStrategy
modifier|*
name|getOrCreateStrategy
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
decl_stmt|;
name|public
label|:
typedef|typedef
name|list_type
operator|::
name|const_iterator
name|iterator
expr_stmt|;
specifier|static
name|char
name|ID
decl_stmt|;
name|GCModuleInfo
argument_list|()
expr_stmt|;
operator|~
name|GCModuleInfo
argument_list|()
expr_stmt|;
comment|/// clear - Resets the pass. The metadata deleter pass calls this.
comment|///
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// begin/end - Iterators for used strategies.
comment|///
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|StrategyList
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|StrategyList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// get - Look up function metadata.
comment|///
name|GCFunctionInfo
modifier|&
name|getFunctionInfo
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

