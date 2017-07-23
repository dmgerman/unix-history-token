begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ModuleChild.h -------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ModuleChild_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ModuleChild_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ModuleChild ModuleChild.h "lldb/Core/ModuleChild.h"
comment|/// @brief A mix in class that contains a pointer back to the module
comment|///        that owns the object which inherits from it.
comment|//----------------------------------------------------------------------
name|class
name|ModuleChild
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with owning module.
comment|///
comment|/// @param[in] module
comment|///     The module that owns the object that inherits from this
comment|///     class.
comment|//------------------------------------------------------------------
name|ModuleChild
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy constructor.
comment|///
comment|/// @param[in] rhs
comment|///     A const ModuleChild class reference to copy.
comment|//------------------------------------------------------------------
name|ModuleChild
argument_list|(
specifier|const
name|ModuleChild
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|ModuleChild
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// @param[in] rhs
comment|///     A const ModuleChild class reference to copy.
comment|///
comment|/// @return
comment|///     A const reference to this object.
comment|//------------------------------------------------------------------
specifier|const
name|ModuleChild
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ModuleChild
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the module pointer.
comment|///
comment|/// @return
comment|///     A const pointer to the module that owns the object that
comment|///     inherits from this class.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ModuleSP
name|GetModule
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor for the module pointer.
comment|///
comment|/// @param[in] module
comment|///     A new module that owns the object that inherits from this
comment|///      class.
comment|//------------------------------------------------------------------
name|void
name|SetModule
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ModuleWP
name|m_module_wp
expr_stmt|;
comment|///< The Module that owns the object that inherits
comment|///< from this class.
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ModuleChild_h_
end_comment

end_unit

