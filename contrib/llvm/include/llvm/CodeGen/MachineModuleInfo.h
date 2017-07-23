begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineModuleInfo.h ------------------------*- C++ -*-===//
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
comment|// Collect meta information for a module.  This information should be in a
end_comment

begin_comment
comment|// neutral form that can be used by different debugging and exception handling
end_comment

begin_comment
comment|// schemes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The organization of information is primarily clustered around the source
end_comment

begin_comment
comment|// compile units.  The main exception is source line correspondence where
end_comment

begin_comment
comment|// inlining may interleave code from various compile units.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following information can be retrieved from the MachineModuleInfo.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  -- Source directories - Directories are uniqued based on their canonical
end_comment

begin_comment
comment|//     string and assigned a sequential numeric ID (base 1.)
end_comment

begin_comment
comment|//  -- Source files - Files are also uniqued based on their name and directory
end_comment

begin_comment
comment|//     ID.  A file ID is sequential number (base 1.)
end_comment

begin_comment
comment|//  -- Source line correspondence - A vector of file ID, line#, column# triples.
end_comment

begin_comment
comment|//     A DEBUG_LOCATION instruction is generated  by the DAG Legalizer
end_comment

begin_comment
comment|//     corresponding to each entry in the source line list.  This allows a debug
end_comment

begin_comment
comment|//     emitter to generate labels referenced by debug information tables.
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
name|LLVM_CODEGEN_MACHINEMODULEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEMODULEINFO_H
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
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|class
name|BasicBlock
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MMIAddrLabelMap
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// This class can be derived from and used by targets to hold private
comment|/// target-specific information for each Module.  Objects of type are
comment|/// accessed/created with MMI::getInfo and destroyed when the MachineModuleInfo
comment|/// is destroyed.
comment|///
name|class
name|MachineModuleInfoImpl
block|{
name|public
label|:
name|using
name|StubValueTy
init|=
name|PointerIntPair
operator|<
name|MCSymbol
operator|*
decl_stmt|, 1,
name|bool
decl|>
decl_stmt|;
name|using
name|SymbolListTy
init|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
decl_stmt|,
name|StubValueTy
decl|>>
decl_stmt|;
name|virtual
operator|~
name|MachineModuleInfoImpl
argument_list|()
expr_stmt|;
name|protected
label|:
comment|/// Return the entries from a DenseMap in a deterministic sorted orer.
comment|/// Clears the map.
specifier|static
name|SymbolListTy
name|getSortedStubs
argument_list|(
name|DenseMap
operator|<
name|MCSymbol
operator|*
argument_list|,
name|StubValueTy
operator|>
operator|&
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// This class contains meta information specific to a module.  Queries can be
comment|/// made by different debugging and exception handling schemes and reformated
comment|/// for specific use.
comment|///
name|class
name|MachineModuleInfo
range|:
name|public
name|ImmutablePass
block|{
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
comment|/// This is the MCContext used for the entire code generator.
name|MCContext
name|Context
block|;
comment|/// This is the LLVM Module being worked on.
specifier|const
name|Module
operator|*
name|TheModule
block|;
comment|/// This is the object-file-format-specific implementation of
comment|/// MachineModuleInfoImpl, which lets targets accumulate whatever info they
comment|/// want.
name|MachineModuleInfoImpl
operator|*
name|ObjFileMMI
block|;
comment|/// \name Exception Handling
comment|/// \{
comment|/// Vector of all personality functions ever seen. Used to emit common EH
comment|/// frames.
name|std
operator|::
name|vector
operator|<
specifier|const
name|Function
operator|*
operator|>
name|Personalities
block|;
comment|/// The current call site index being processed, if any. 0 if none.
name|unsigned
name|CurCallSite
block|;
comment|/// \}
comment|/// This map keeps track of which symbol is being used for the specified
comment|/// basic block's address of label.
name|MMIAddrLabelMap
operator|*
name|AddrLabelSymbols
block|;
comment|// TODO: Ideally, what we'd like is to have a switch that allows emitting
comment|// synchronous (precise at call-sites only) CFA into .eh_frame. However,
comment|// even under this switch, we'd like .debug_frame to be precise when using
comment|// -g. At this moment, there's no way to specify that some CFI directives
comment|// go into .eh_frame only, while others go into .debug_frame only.
comment|/// True if debugging information is available in this module.
name|bool
name|DbgInfoAvailable
block|;
comment|/// True if this module calls VarArg function with floating-point arguments.
comment|/// This is used to emit an undefined reference to _fltused on Windows
comment|/// targets.
name|bool
name|UsesVAFloatArgument
block|;
comment|/// True if the module calls the __morestack function indirectly, as is
comment|/// required under the large code model on x86. This is used to emit
comment|/// a definition of a symbol, __morestack_addr, containing the address. See
comment|/// comments in lib/Target/X86/X86FrameLowering.cpp for more details.
name|bool
name|UsesMorestackAddr
block|;
comment|/// Maps IR Functions to their corresponding MachineFunctions.
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
block|,
name|std
operator|::
name|unique_ptr
operator|<
name|MachineFunction
operator|>>
name|MachineFunctions
block|;
comment|/// Next unique number available for a MachineFunction.
name|unsigned
name|NextFnNum
operator|=
literal|0
block|;
specifier|const
name|Function
operator|*
name|LastRequest
operator|=
name|nullptr
block|;
comment|///< Used for shortcut/cache.
name|MachineFunction
operator|*
name|LastResult
operator|=
name|nullptr
block|;
comment|///< Used for shortcut/cache.
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|explicit
name|MachineModuleInfo
argument_list|(
specifier|const
name|TargetMachine
operator|*
name|TM
operator|=
name|nullptr
argument_list|)
block|;
operator|~
name|MachineModuleInfo
argument_list|()
name|override
block|;
comment|// Initialization and Finalization
name|bool
name|doInitialization
argument_list|(
argument|Module&
argument_list|)
name|override
block|;
name|bool
name|doFinalization
argument_list|(
argument|Module&
argument_list|)
name|override
block|;
specifier|const
name|MCContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
name|MCContext
operator|&
name|getContext
argument_list|()
block|{
return|return
name|Context
return|;
block|}
name|void
name|setModule
argument_list|(
argument|const Module *M
argument_list|)
block|{
name|TheModule
operator|=
name|M
block|; }
specifier|const
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|TheModule
return|;
block|}
comment|/// Returns the MachineFunction constructed for the IR function \p F.
comment|/// Creates a new MachineFunction if none exists yet.
name|MachineFunction
operator|&
name|getOrCreateMachineFunction
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
block|;
comment|/// \bried Returns the MachineFunction associated to IR function \p F if there
comment|/// is one, otherwise nullptr.
name|MachineFunction
operator|*
name|getMachineFunction
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
block|;
comment|/// Delete the MachineFunction \p MF and reset the link in the IR Function to
comment|/// Machine Function map.
name|void
name|deleteMachineFunctionFor
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
comment|/// Keep track of various per-function pieces of information for backends
comment|/// that would like to do so.
name|template
operator|<
name|typename
name|Ty
operator|>
name|Ty
operator|&
name|getObjFileInfo
argument_list|()
block|{
if|if
condition|(
name|ObjFileMMI
operator|==
name|nullptr
condition|)
name|ObjFileMMI
operator|=
name|new
name|Ty
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
return|return
operator|*
name|static_cast
operator|<
name|Ty
operator|*
operator|>
operator|(
name|ObjFileMMI
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|Ty
operator|>
specifier|const
name|Ty
operator|&
name|getObjFileInfo
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MachineModuleInfo
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getObjFileInfo
operator|<
name|Ty
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Returns true if valid debug info is present.
name|bool
name|hasDebugInfo
argument_list|()
specifier|const
block|{
return|return
name|DbgInfoAvailable
return|;
block|}
name|void
name|setDebugInfoAvailability
parameter_list|(
name|bool
name|avail
parameter_list|)
block|{
name|DbgInfoAvailable
operator|=
name|avail
expr_stmt|;
block|}
name|bool
name|usesVAFloatArgument
argument_list|()
specifier|const
block|{
return|return
name|UsesVAFloatArgument
return|;
block|}
name|void
name|setUsesVAFloatArgument
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|UsesVAFloatArgument
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|usesMorestackAddr
argument_list|()
specifier|const
block|{
return|return
name|UsesMorestackAddr
return|;
block|}
name|void
name|setUsesMorestackAddr
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|UsesMorestackAddr
operator|=
name|b
expr_stmt|;
block|}
comment|/// Return the symbol to be used for the specified basic block when its
comment|/// address is taken.  This cannot be its normal LBB label because the block
comment|/// may be accessed outside its containing function.
name|MCSymbol
modifier|*
name|getAddrLabelSymbol
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|getAddrLabelSymbolToEmit
argument_list|(
name|BB
argument_list|)
operator|.
name|front
argument_list|()
return|;
block|}
comment|/// Return the symbol to be used for the specified basic block when its
comment|/// address is taken.  If other blocks were RAUW'd to this one, we may have
comment|/// to emit them as well, return the whole set.
name|ArrayRef
operator|<
name|MCSymbol
operator|*
operator|>
name|getAddrLabelSymbolToEmit
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
expr_stmt|;
comment|/// If the specified function has had any references to address-taken blocks
comment|/// generated, but the block got deleted, return the symbol now so we can
comment|/// emit it.  This prevents emitting a reference to a symbol that has no
comment|/// definition.
name|void
name|takeDeletedSymbolsForFunction
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MCSymbol
operator|*
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
comment|/// \name Exception Handling
comment|/// \{
comment|/// Set the call site currently being processed.
name|void
name|setCurrentCallSite
parameter_list|(
name|unsigned
name|Site
parameter_list|)
block|{
name|CurCallSite
operator|=
name|Site
expr_stmt|;
block|}
comment|/// Get the call site currently being processed, if any.  return zero if
comment|/// none.
name|unsigned
name|getCurrentCallSite
parameter_list|()
block|{
return|return
name|CurCallSite
return|;
block|}
comment|/// Provide the personality function for the exception information.
name|void
name|addPersonality
parameter_list|(
specifier|const
name|Function
modifier|*
name|Personality
parameter_list|)
function_decl|;
comment|/// Return array of personality functions ever seen.
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|Function
operator|*
operator|>
operator|&
name|getPersonalities
argument_list|()
specifier|const
block|{
return|return
name|Personalities
return|;
block|}
comment|/// \}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// End class MachineModuleInfo
end_comment

begin_comment
comment|//===- MMI building helpers -----------------------------------------------===//
end_comment

begin_comment
comment|/// Determine if any floating-point values are being passed to this variadic
end_comment

begin_comment
comment|/// function, and set the MachineModuleInfo's usesVAFloatArgument flag if so.
end_comment

begin_comment
comment|/// This flag is used to emit an undefined reference to _fltused on Windows,
end_comment

begin_comment
comment|/// which will link in MSVCRT's floating-point support.
end_comment

begin_function_decl
name|void
name|computeUsesVAFloatArgument
parameter_list|(
specifier|const
name|CallInst
modifier|&
name|I
parameter_list|,
name|MachineModuleInfo
modifier|&
name|MMI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_MACHINEMODULEINFO_H
end_comment

end_unit

