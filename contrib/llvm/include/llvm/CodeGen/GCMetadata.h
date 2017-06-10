begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GCMetadata.h - Garbage collector metadata ----------------*- C++ -*-===//
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
file|"llvm/CodeGen/GCStrategy.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
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
comment|///< The kind of the safe point.
name|MCSymbol
modifier|*
name|Label
decl_stmt|;
comment|///< A label.
name|DebugLoc
name|Loc
decl_stmt|;
name|GCPoint
argument_list|(
argument|GC::PointKind K
argument_list|,
argument|MCSymbol *L
argument_list|,
argument|DebugLoc DL
argument_list|)
block|:
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|Label
argument_list|(
name|L
argument_list|)
operator|,
name|Loc
argument_list|(
argument|std::move(DL)
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
comment|///< Usually a frame index.
name|int
name|StackOffset
init|=
operator|-
literal|1
decl_stmt|;
comment|///< Offset from the stack pointer.
specifier|const
name|Constant
modifier|*
name|Metadata
decl_stmt|;
comment|///< Metadata straight from the call
comment|///< to llvm.gcroot.
name|GCRoot
argument_list|(
argument|int N
argument_list|,
argument|const Constant *MD
argument_list|)
block|:
name|Num
argument_list|(
name|N
argument_list|)
operator|,
name|Metadata
argument_list|(
argument|MD
argument_list|)
block|{}
block|}
struct|;
comment|/// Garbage collection metadata for a single function.  Currently, this
comment|/// information only applies to GCStrategies which use GCRoot.
name|class
name|GCFunctionInfo
block|{
name|public
label|:
name|using
name|iterator
init|=
name|std
operator|::
name|vector
operator|<
name|GCPoint
operator|>
operator|::
name|iterator
decl_stmt|;
name|using
name|roots_iterator
init|=
name|std
operator|::
name|vector
operator|<
name|GCRoot
operator|>
operator|::
name|iterator
decl_stmt|;
name|using
name|live_iterator
init|=
name|std
operator|::
name|vector
operator|<
name|GCRoot
operator|>
operator|::
name|const_iterator
decl_stmt|;
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
specifier|const
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
comment|/// removeStackRoot - Removes a root.
name|roots_iterator
name|removeStackRoot
parameter_list|(
name|roots_iterator
name|position
parameter_list|)
block|{
return|return
name|Roots
operator|.
name|erase
argument_list|(
name|position
argument_list|)
return|;
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
name|MCSymbol
operator|*
name|Label
argument_list|,
specifier|const
name|DebugLoc
operator|&
name|DL
argument_list|)
block|{
name|SafePoints
operator|.
name|emplace_back
argument_list|(
name|Kind
argument_list|,
name|Label
argument_list|,
name|DL
argument_list|)
expr_stmt|;
block|}
comment|/// getFrameSize/setFrameSize - Records the function's frame size.
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
comment|/// An analysis pass which caches information about the entire Module.
comment|/// Records both the function level information used by GCRoots and a
comment|/// cache of the 'active' gc strategy objects for the current Module.
name|class
name|GCModuleInfo
range|:
name|public
name|ImmutablePass
block|{
comment|/// An owning list of all GCStrategies which have been created
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|GCStrategy
operator|>
block|,
literal|1
operator|>
name|GCStrategyList
block|;
comment|/// A helper map to speedup lookups into the above list
name|StringMap
operator|<
name|GCStrategy
operator|*
operator|>
name|GCStrategyMap
block|;
name|public
operator|:
comment|/// Lookup the GCStrategy object associated with the given gc name.
comment|/// Objects are owned internally; No caller should attempt to delete the
comment|/// returned objects.
name|GCStrategy
operator|*
name|getGCStrategy
argument_list|(
argument|const StringRef Name
argument_list|)
block|;
comment|/// List of per function info objects.  In theory, Each of these
comment|/// may be associated with a different GC.
name|using
name|FuncInfoVec
operator|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|GCFunctionInfo
operator|>>
block|;
name|FuncInfoVec
operator|::
name|iterator
name|funcinfo_begin
argument_list|()
block|{
return|return
name|Functions
operator|.
name|begin
argument_list|()
return|;
block|}
name|FuncInfoVec
operator|::
name|iterator
name|funcinfo_end
argument_list|()
block|{
return|return
name|Functions
operator|.
name|end
argument_list|()
return|;
block|}
name|private
operator|:
comment|/// Owning list of all GCFunctionInfos associated with this Module
name|FuncInfoVec
name|Functions
block|;
comment|/// Non-owning map to bypass linear search when finding the GCFunctionInfo
comment|/// associated with a particular Function.
name|using
name|finfo_map_type
operator|=
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
block|,
name|GCFunctionInfo
operator|*
operator|>
block|;
name|finfo_map_type
name|FInfoMap
block|;
name|public
operator|:
name|using
name|iterator
operator|=
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|GCStrategy
operator|>
block|,
literal|1
operator|>
operator|::
name|const_iterator
block|;
specifier|static
name|char
name|ID
block|;
name|GCModuleInfo
argument_list|()
block|;
comment|/// clear - Resets the pass. Any pass, which uses GCModuleInfo, should
comment|/// call it in doFinalization().
comment|///
name|void
name|clear
argument_list|()
block|;
comment|/// begin/end - Iterators for used strategies.
comment|///
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|GCStrategyList
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
name|GCStrategyList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// get - Look up function metadata.  This is currently assumed
comment|/// have the side effect of initializing the associated GCStrategy.  That
comment|/// will soon change.
name|GCFunctionInfo
operator|&
name|getFunctionInfo
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
block|; }
decl_stmt|;
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
comment|// LLVM_CODEGEN_GCMETADATA_H
end_comment

end_unit

