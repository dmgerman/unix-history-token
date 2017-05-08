begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugInfo.h - Debug Information Helpers ------------------*- C++ -*-===//
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
comment|// This file defines a bunch of datatypes that are useful for creating and
end_comment

begin_comment
comment|// walking debug info in LLVM IR form. They essentially provide wrappers around
end_comment

begin_comment
comment|// the information in the global variables that's needed when constructing the
end_comment

begin_comment
comment|// DWARF information.
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
name|LLVM_IR_DEBUGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_DEBUGINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfoMetadata.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DbgDeclareInst
decl_stmt|;
name|class
name|DbgValueInst
decl_stmt|;
name|class
name|Module
decl_stmt|;
comment|/// \brief Find subprogram that is enclosing this scope.
name|DISubprogram
modifier|*
name|getDISubprogram
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// \brief Strip debug info in the module if it exists.
comment|///
comment|/// To do this, we remove all calls to the debugger intrinsics and any named
comment|/// metadata for debugging. We also remove debug locations for instructions.
comment|/// Return true if module is modified.
name|bool
name|StripDebugInfo
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
name|bool
name|stripDebugInfo
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// Downgrade the debug info in a module to contain only line table information.
comment|///
comment|/// In order to convert debug info to what -gline-tables-only would have
comment|/// created, this does the following:
comment|///   1) Delete all debug intrinsics.
comment|///   2) Delete all non-CU named metadata debug info nodes.
comment|///   3) Create new DebugLocs for each instruction.
comment|///   4) Create a new CU debug info, and similarly for every metadata node
comment|///      that's reachable from the CU debug info.
comment|///   All debug type metadata nodes are unreachable and garbage collected.
name|bool
name|stripNonLineTableDebugInfo
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// \brief Return Debug Info Metadata Version by checking module flags.
name|unsigned
name|getDebugMetadataVersionFromModule
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// \brief Utility to find all debug info in a module.
comment|///
comment|/// DebugInfoFinder tries to list all debug info MDNodes used in a module. To
comment|/// list debug info MDNodes used by an instruction, DebugInfoFinder uses
comment|/// processDeclare, processValue and processLocation to handle DbgDeclareInst,
comment|/// DbgValueInst and DbgLoc attached to instructions. processModule will go
comment|/// through all DICompileUnits in llvm.dbg.cu and list debug info MDNodes
comment|/// used by the CUs.
name|class
name|DebugInfoFinder
block|{
name|public
label|:
comment|/// \brief Process entire module and collect debug info anchors.
name|void
name|processModule
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// \brief Process DbgDeclareInst.
name|void
name|processDeclare
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|DbgDeclareInst
modifier|*
name|DDI
parameter_list|)
function_decl|;
comment|/// \brief Process DbgValueInst.
name|void
name|processValue
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|DbgValueInst
modifier|*
name|DVI
parameter_list|)
function_decl|;
comment|/// \brief Process debug info location.
name|void
name|processLocation
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|DILocation
modifier|*
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief Clear all lists.
name|void
name|reset
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|InitializeTypeMap
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
name|void
name|processType
parameter_list|(
name|DIType
modifier|*
name|DT
parameter_list|)
function_decl|;
name|void
name|processSubprogram
parameter_list|(
name|DISubprogram
modifier|*
name|SP
parameter_list|)
function_decl|;
name|void
name|processScope
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
name|bool
name|addCompileUnit
parameter_list|(
name|DICompileUnit
modifier|*
name|CU
parameter_list|)
function_decl|;
name|bool
name|addGlobalVariable
parameter_list|(
name|DIGlobalVariableExpression
modifier|*
name|DIG
parameter_list|)
function_decl|;
name|bool
name|addSubprogram
parameter_list|(
name|DISubprogram
modifier|*
name|SP
parameter_list|)
function_decl|;
name|bool
name|addType
parameter_list|(
name|DIType
modifier|*
name|DT
parameter_list|)
function_decl|;
name|bool
name|addScope
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
name|public
label|:
name|using
name|compile_unit_iterator
init|=
name|SmallVectorImpl
operator|<
name|DICompileUnit
operator|*
operator|>
operator|::
name|const_iterator
decl_stmt|;
name|using
name|subprogram_iterator
init|=
name|SmallVectorImpl
operator|<
name|DISubprogram
operator|*
operator|>
operator|::
name|const_iterator
decl_stmt|;
name|using
name|global_variable_expression_iterator
init|=
name|SmallVectorImpl
operator|<
name|DIGlobalVariableExpression
operator|*
operator|>
operator|::
name|const_iterator
decl_stmt|;
name|using
name|type_iterator
init|=
name|SmallVectorImpl
operator|<
name|DIType
operator|*
operator|>
operator|::
name|const_iterator
decl_stmt|;
name|using
name|scope_iterator
init|=
name|SmallVectorImpl
operator|<
name|DIScope
operator|*
operator|>
operator|::
name|const_iterator
decl_stmt|;
name|iterator_range
operator|<
name|compile_unit_iterator
operator|>
name|compile_units
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|CUs
operator|.
name|begin
argument_list|()
argument_list|,
name|CUs
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|subprogram_iterator
operator|>
name|subprograms
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|SPs
operator|.
name|begin
argument_list|()
argument_list|,
name|SPs
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|global_variable_expression_iterator
operator|>
name|global_variables
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|GVs
operator|.
name|begin
argument_list|()
argument_list|,
name|GVs
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|type_iterator
operator|>
name|types
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|TYs
operator|.
name|begin
argument_list|()
argument_list|,
name|TYs
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|scope_iterator
operator|>
name|scopes
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|Scopes
operator|.
name|begin
argument_list|()
argument_list|,
name|Scopes
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|unsigned
name|compile_unit_count
argument_list|()
specifier|const
block|{
return|return
name|CUs
operator|.
name|size
argument_list|()
return|;
block|}
name|unsigned
name|global_variable_count
argument_list|()
specifier|const
block|{
return|return
name|GVs
operator|.
name|size
argument_list|()
return|;
block|}
name|unsigned
name|subprogram_count
argument_list|()
specifier|const
block|{
return|return
name|SPs
operator|.
name|size
argument_list|()
return|;
block|}
name|unsigned
name|type_count
argument_list|()
specifier|const
block|{
return|return
name|TYs
operator|.
name|size
argument_list|()
return|;
block|}
name|unsigned
name|scope_count
argument_list|()
specifier|const
block|{
return|return
name|Scopes
operator|.
name|size
argument_list|()
return|;
block|}
name|private
label|:
name|SmallVector
operator|<
name|DICompileUnit
operator|*
operator|,
literal|8
operator|>
name|CUs
expr_stmt|;
name|SmallVector
operator|<
name|DISubprogram
operator|*
operator|,
literal|8
operator|>
name|SPs
expr_stmt|;
name|SmallVector
operator|<
name|DIGlobalVariableExpression
operator|*
operator|,
literal|8
operator|>
name|GVs
expr_stmt|;
name|SmallVector
operator|<
name|DIType
operator|*
operator|,
literal|8
operator|>
name|TYs
expr_stmt|;
name|SmallVector
operator|<
name|DIScope
operator|*
operator|,
literal|8
operator|>
name|Scopes
expr_stmt|;
name|SmallPtrSet
operator|<
specifier|const
name|MDNode
operator|*
operator|,
literal|32
operator|>
name|NodesSeen
expr_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_IR_DEBUGINFO_H
end_comment

end_unit

