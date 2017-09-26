begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Pass.h - Base class for Passes ----------------------*- C++ -*-===//
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
comment|// This file defines a base class that indicates that a specified class is a
end_comment

begin_comment
comment|// transformation pass implementation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Passes are designed this way so that it is possible to run passes in a cache
end_comment

begin_comment
comment|// and organizationally optimal order without having to specify it at the front
end_comment

begin_comment
comment|// end.  This allows arbitrary passes to be strung together and have them
end_comment

begin_comment
comment|// executed as efficiently as possible.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Passes should extend one of the classes below, depending on the guarantees
end_comment

begin_comment
comment|// that it can make about what will be modified as it is run.  For example, most
end_comment

begin_comment
comment|// global optimizations should derive from FunctionPass, because they do not add
end_comment

begin_comment
comment|// or delete functions, they operate on the internals of the function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that this file #includes PassSupport.h and PassAnalysisSupport.h (at the
end_comment

begin_comment
comment|// bottom), so the APIs exposed by these files are also automatically available
end_comment

begin_comment
comment|// to all users of this file.
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
name|LLVM_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASS_H
end_define

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
name|BasicBlock
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|PassInfo
decl_stmt|;
name|class
name|ImmutablePass
decl_stmt|;
name|class
name|PMStack
decl_stmt|;
name|class
name|AnalysisResolver
decl_stmt|;
name|class
name|PMDataManager
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|// AnalysisID - Use the PassInfo to identify a pass...
typedef|typedef
specifier|const
name|void
modifier|*
name|AnalysisID
typedef|;
comment|/// Different types of internal pass managers. External pass managers
comment|/// (PassManager and FunctionPassManager) are not represented here.
comment|/// Ordering of pass manager types is important here.
enum|enum
name|PassManagerType
block|{
name|PMT_Unknown
init|=
literal|0
block|,
name|PMT_ModulePassManager
init|=
literal|1
block|,
comment|///< MPPassManager
name|PMT_CallGraphPassManager
block|,
comment|///< CGPassManager
name|PMT_FunctionPassManager
block|,
comment|///< FPPassManager
name|PMT_LoopPassManager
block|,
comment|///< LPPassManager
name|PMT_RegionPassManager
block|,
comment|///< RGPassManager
name|PMT_BasicBlockPassManager
block|,
comment|///< BBPassManager
name|PMT_Last
block|}
enum|;
comment|// Different types of passes.
enum|enum
name|PassKind
block|{
name|PT_BasicBlock
block|,
name|PT_Region
block|,
name|PT_Loop
block|,
name|PT_Function
block|,
name|PT_CallGraphSCC
block|,
name|PT_Module
block|,
name|PT_PassManager
block|}
enum|;
comment|//===----------------------------------------------------------------------===//
comment|/// Pass interface - Implemented by all 'passes'.  Subclass this if you are an
comment|/// interprocedural optimization or you do not fit into any of the more
comment|/// constrained passes described below.
comment|///
name|class
name|Pass
block|{
name|AnalysisResolver
modifier|*
name|Resolver
decl_stmt|;
comment|// Used to resolve analysis
specifier|const
name|void
modifier|*
name|PassID
decl_stmt|;
name|PassKind
name|Kind
decl_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|Pass
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|Pass
argument_list|(
specifier|const
name|Pass
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|public
label|:
name|explicit
name|Pass
argument_list|(
argument|PassKind K
argument_list|,
argument|char&pid
argument_list|)
block|:
name|Resolver
argument_list|(
name|nullptr
argument_list|)
operator|,
name|PassID
argument_list|(
operator|&
name|pid
argument_list|)
operator|,
name|Kind
argument_list|(
argument|K
argument_list|)
block|{ }
name|virtual
operator|~
name|Pass
argument_list|()
expr_stmt|;
name|PassKind
name|getPassKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// getPassName - Return a nice clean name for a pass.  This usually
comment|/// implemented in terms of the name that is registered by one of the
comment|/// Registration templates, but can be overloaded directly.
comment|///
name|virtual
name|StringRef
name|getPassName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getPassID - Return the PassID number that corresponds to this pass.
name|AnalysisID
name|getPassID
argument_list|()
specifier|const
block|{
return|return
name|PassID
return|;
block|}
comment|/// doInitialization - Virtual method overridden by subclasses to do
comment|/// any necessary initialization before any pass is run.
comment|///
name|virtual
name|bool
name|doInitialization
parameter_list|(
name|Module
modifier|&
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// doFinalization - Virtual method overriden by subclasses to do any
comment|/// necessary clean up after all passes have run.
comment|///
name|virtual
name|bool
name|doFinalization
parameter_list|(
name|Module
modifier|&
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// print - Print out the internal state of the pass.  This is called by
comment|/// Analyze to print out the contents of an analysis.  Otherwise it is not
comment|/// necessary to implement this method.  Beware that the module pointer MAY be
comment|/// null.  This automatically forwards to a virtual function that does not
comment|/// provide the Module* in case the analysis doesn't need it it can just be
comment|/// ignored.
comment|///
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|Module
operator|*
name|M
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|// dump - Print to stderr.
comment|/// createPrinterPass - Get a Pass appropriate to print the IR this
comment|/// pass operates on (Module, Function or MachineFunction).
name|virtual
name|Pass
modifier|*
name|createPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Each pass is responsible for assigning a pass manager to itself.
comment|/// PMS is the stack of available pass manager.
name|virtual
name|void
name|assignPassManager
parameter_list|(
name|PMStack
modifier|&
parameter_list|,
name|PassManagerType
parameter_list|)
block|{}
comment|/// Check if available pass managers are suitable for this pass or not.
name|virtual
name|void
name|preparePassManager
parameter_list|(
name|PMStack
modifier|&
parameter_list|)
function_decl|;
comment|///  Return what kind of Pass Manager can manage this pass.
name|virtual
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
expr_stmt|;
comment|// Access AnalysisResolver
name|void
name|setResolver
parameter_list|(
name|AnalysisResolver
modifier|*
name|AR
parameter_list|)
function_decl|;
name|AnalysisResolver
operator|*
name|getResolver
argument_list|()
specifier|const
block|{
return|return
name|Resolver
return|;
block|}
comment|/// getAnalysisUsage - This function should be overriden by passes that need
comment|/// analysis information to do their job.  If a pass specifies that it uses a
comment|/// particular analysis result to this function, it can then use the
comment|/// getAnalysis<AnalysisType>() function, below.
comment|///
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// releaseMemory() - This member can be implemented by a pass if it wants to
comment|/// be able to release its memory when it is no longer needed.  The default
comment|/// behavior of passes is to hold onto memory for the entire duration of their
comment|/// lifetime (which is the entire compile time).  For pipelined passes, this
comment|/// is not a big deal because that memory gets recycled every time the pass is
comment|/// invoked on another program unit.  For IP passes, it is more important to
comment|/// free memory when it is unused.
comment|///
comment|/// Optionally implement this function to release pass memory when it is no
comment|/// longer used.
comment|///
name|virtual
name|void
name|releaseMemory
parameter_list|()
function_decl|;
comment|/// getAdjustedAnalysisPointer - This method is used when a pass implements
comment|/// an analysis interface through multiple inheritance.  If needed, it should
comment|/// override this to adjust the this pointer as needed for the specified pass
comment|/// info.
name|virtual
name|void
modifier|*
name|getAdjustedAnalysisPointer
parameter_list|(
name|AnalysisID
name|ID
parameter_list|)
function_decl|;
name|virtual
name|ImmutablePass
modifier|*
name|getAsImmutablePass
parameter_list|()
function_decl|;
name|virtual
name|PMDataManager
modifier|*
name|getAsPMDataManager
parameter_list|()
function_decl|;
comment|/// verifyAnalysis() - This member can be implemented by a analysis pass to
comment|/// check state of analysis information.
name|virtual
name|void
name|verifyAnalysis
argument_list|()
specifier|const
expr_stmt|;
comment|// dumpPassStructure - Implement the -debug-passes=PassStructure option
name|virtual
name|void
name|dumpPassStructure
parameter_list|(
name|unsigned
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|// lookupPassInfo - Return the pass info object for the specified pass class,
comment|// or null if it is not known.
specifier|static
specifier|const
name|PassInfo
modifier|*
name|lookupPassInfo
parameter_list|(
specifier|const
name|void
modifier|*
name|TI
parameter_list|)
function_decl|;
comment|// lookupPassInfo - Return the pass info object for the pass with the given
comment|// argument string, or null if it is not known.
specifier|static
specifier|const
name|PassInfo
modifier|*
name|lookupPassInfo
parameter_list|(
name|StringRef
name|Arg
parameter_list|)
function_decl|;
comment|// createPass - Create a object for the specified pass class,
comment|// or null if it is not known.
specifier|static
name|Pass
modifier|*
name|createPass
parameter_list|(
name|AnalysisID
name|ID
parameter_list|)
function_decl|;
comment|/// getAnalysisIfAvailable<AnalysisType>() - Subclasses use this function to
comment|/// get analysis information that might be around, for example to update it.
comment|/// This is different than getAnalysis in that it can fail (if the analysis
comment|/// results haven't been computed), so should only be used if you can handle
comment|/// the case when the analysis is not available.  This method is often used by
comment|/// transformation APIs to update analysis results for a pass automatically as
comment|/// the transform is performed.
comment|///
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|*
name|getAnalysisIfAvailable
argument_list|()
specifier|const
expr_stmt|;
comment|// Defined in PassAnalysisSupport.h
comment|/// mustPreserveAnalysisID - This method serves the same function as
comment|/// getAnalysisIfAvailable, but works if you just have an AnalysisID.  This
comment|/// obviously cannot give you a properly typed instance of the class if you
comment|/// don't have the class name available (use getAnalysisIfAvailable if you
comment|/// do), but it can tell you if you need to preserve the pass at least.
comment|///
name|bool
name|mustPreserveAnalysisID
argument_list|(
name|char
operator|&
name|AID
argument_list|)
decl|const
decl_stmt|;
comment|/// getAnalysis<AnalysisType>() - This function is used by subclasses to get
comment|/// to the analysis information that they claim to use by overriding the
comment|/// getAnalysisUsage function.
comment|///
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|&
name|getAnalysis
argument_list|()
specifier|const
expr_stmt|;
comment|// Defined in PassAnalysisSupport.h
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|&
name|getAnalysis
argument_list|(
name|Function
operator|&
name|F
argument_list|)
expr_stmt|;
comment|// Defined in PassAnalysisSupport.h
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|&
name|getAnalysisID
argument_list|(
argument|AnalysisID PI
argument_list|)
specifier|const
expr_stmt|;
name|template
operator|<
name|typename
name|AnalysisType
operator|>
name|AnalysisType
operator|&
name|getAnalysisID
argument_list|(
argument|AnalysisID PI
argument_list|,
argument|Function&F
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// ModulePass class - This class is used to implement unstructured
comment|/// interprocedural optimizations and analyses.  ModulePasses may do anything
comment|/// they want to the program.
comment|///
name|class
name|ModulePass
range|:
name|public
name|Pass
block|{
name|public
operator|:
comment|/// createPrinterPass - Get a module printer pass.
name|Pass
operator|*
name|createPrinterPass
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const std::string&Banner
argument_list|)
specifier|const
name|override
block|;
comment|/// runOnModule - Virtual method overriden by subclasses to process the module
comment|/// being operated on.
name|virtual
name|bool
name|runOnModule
argument_list|(
name|Module
operator|&
name|M
argument_list|)
operator|=
literal|0
block|;
name|void
name|assignPassManager
argument_list|(
argument|PMStack&PMS
argument_list|,
argument|PassManagerType T
argument_list|)
name|override
block|;
comment|///  Return what kind of Pass Manager can manage this pass.
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
name|override
block|;
name|explicit
name|ModulePass
argument_list|(
name|char
operator|&
name|pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|PT_Module
argument_list|,
argument|pid
argument_list|)
block|{}
comment|// Force out-of-line virtual method.
operator|~
name|ModulePass
argument_list|()
name|override
block|;
name|protected
operator|:
comment|/// Optional passes call this function to check whether the pass should be
comment|/// skipped. This is the case when optimization bisect is over the limit.
name|bool
name|skipModule
argument_list|(
argument|Module&M
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// ImmutablePass class - This class is used to provide information that does
comment|/// not need to be run.  This is useful for things like target information and
comment|/// "basic" versions of AnalysisGroups.
comment|///
name|class
name|ImmutablePass
range|:
name|public
name|ModulePass
block|{
name|public
operator|:
comment|/// initializePass - This method may be overriden by immutable passes to allow
comment|/// them to perform various initialization actions they require.  This is
comment|/// primarily because an ImmutablePass can "require" another ImmutablePass,
comment|/// and if it does, the overloaded version of initializePass may get access to
comment|/// these passes with getAnalysis<>.
comment|///
name|virtual
name|void
name|initializePass
argument_list|()
block|;
name|ImmutablePass
operator|*
name|getAsImmutablePass
argument_list|()
name|override
block|{
return|return
name|this
return|;
block|}
comment|/// ImmutablePasses are never run.
comment|///
name|bool
name|runOnModule
argument_list|(
argument|Module&
argument_list|)
name|override
block|{
return|return
name|false
return|;
block|}
name|explicit
name|ImmutablePass
argument_list|(
name|char
operator|&
name|pid
argument_list|)
operator|:
name|ModulePass
argument_list|(
argument|pid
argument_list|)
block|{}
comment|// Force out-of-line virtual method.
operator|~
name|ImmutablePass
argument_list|()
name|override
block|; }
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// FunctionPass class - This class is used to implement most global
comment|/// optimizations.  Optimizations should subclass this class if they meet the
comment|/// following constraints:
comment|///
comment|///  1. Optimizations are organized globally, i.e., a function at a time
comment|///  2. Optimizing a function does not cause the addition or removal of any
comment|///     functions in the module
comment|///
name|class
name|FunctionPass
range|:
name|public
name|Pass
block|{
name|public
operator|:
name|explicit
name|FunctionPass
argument_list|(
name|char
operator|&
name|pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|PT_Function
argument_list|,
argument|pid
argument_list|)
block|{}
comment|/// createPrinterPass - Get a function printer pass.
name|Pass
operator|*
name|createPrinterPass
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const std::string&Banner
argument_list|)
specifier|const
name|override
block|;
comment|/// runOnFunction - Virtual method overriden by subclasses to do the
comment|/// per-function processing of the pass.
comment|///
name|virtual
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
operator|=
literal|0
block|;
name|void
name|assignPassManager
argument_list|(
argument|PMStack&PMS
argument_list|,
argument|PassManagerType T
argument_list|)
name|override
block|;
comment|///  Return what kind of Pass Manager can manage this pass.
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
name|override
block|;
name|protected
operator|:
comment|/// Optional passes call this function to check whether the pass should be
comment|/// skipped. This is the case when Attribute::OptimizeNone is set or when
comment|/// optimization bisect is over the limit.
name|bool
name|skipFunction
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// BasicBlockPass class - This class is used to implement most local
comment|/// optimizations.  Optimizations should subclass this class if they
comment|/// meet the following constraints:
comment|///   1. Optimizations are local, operating on either a basic block or
comment|///      instruction at a time.
comment|///   2. Optimizations do not modify the CFG of the contained function, or any
comment|///      other basic block in the function.
comment|///   3. Optimizations conform to all of the constraints of FunctionPasses.
comment|///
name|class
name|BasicBlockPass
range|:
name|public
name|Pass
block|{
name|public
operator|:
name|explicit
name|BasicBlockPass
argument_list|(
name|char
operator|&
name|pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|PT_BasicBlock
argument_list|,
argument|pid
argument_list|)
block|{}
comment|/// createPrinterPass - Get a basic block printer pass.
name|Pass
operator|*
name|createPrinterPass
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const std::string&Banner
argument_list|)
specifier|const
name|override
block|;
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doInitialization
block|;
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doFinalization
block|;
comment|/// doInitialization - Virtual method overridden by BasicBlockPass subclasses
comment|/// to do any necessary per-function initialization.
comment|///
name|virtual
name|bool
name|doInitialization
argument_list|(
name|Function
operator|&
argument_list|)
block|;
comment|/// runOnBasicBlock - Virtual method overriden by subclasses to do the
comment|/// per-basicblock processing of the pass.
comment|///
name|virtual
name|bool
name|runOnBasicBlock
argument_list|(
name|BasicBlock
operator|&
name|BB
argument_list|)
operator|=
literal|0
block|;
comment|/// doFinalization - Virtual method overriden by BasicBlockPass subclasses to
comment|/// do any post processing needed after all passes have run.
comment|///
name|virtual
name|bool
name|doFinalization
argument_list|(
name|Function
operator|&
argument_list|)
block|;
name|void
name|assignPassManager
argument_list|(
argument|PMStack&PMS
argument_list|,
argument|PassManagerType T
argument_list|)
name|override
block|;
comment|///  Return what kind of Pass Manager can manage this pass.
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
name|override
block|;
name|protected
operator|:
comment|/// Optional passes call this function to check whether the pass should be
comment|/// skipped. This is the case when Attribute::OptimizeNone is set or when
comment|/// optimization bisect is over the limit.
name|bool
name|skipBasicBlock
argument_list|(
argument|const BasicBlock&BB
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// If the user specifies the -time-passes argument on an LLVM tool command line
comment|/// then the value of this boolean will be true, otherwise false.
comment|/// @brief This is the storage for the -time-passes option.
specifier|extern
name|bool
name|TimePassesIsEnabled
decl_stmt|;
comment|/// isFunctionInPrintList - returns true if a function should be printed via
comment|//  debugging options like -print-after-all/-print-before-all.
comment|//  @brief Tells if the function IR should be printed by PrinterPass.
specifier|extern
name|bool
name|isFunctionInPrintList
parameter_list|(
name|StringRef
name|FunctionName
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Include support files that contain important APIs commonly used by Passes,
end_comment

begin_comment
comment|// but that we want to separate out to make it easier to read the header files.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"llvm/PassAnalysisSupport.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassSupport.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

