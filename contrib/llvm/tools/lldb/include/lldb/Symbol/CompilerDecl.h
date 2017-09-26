begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompilerDecl.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_CompilerDecl_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CompilerDecl_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CompilerDecl
block|{
name|public
label|:
comment|//----------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//----------------------------------------------------------------------
name|CompilerDecl
argument_list|()
operator|:
name|m_type_system
argument_list|(
name|nullptr
argument_list|)
operator|,
name|m_opaque_decl
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|CompilerDecl
argument_list|(
name|TypeSystem
operator|*
name|type_system
argument_list|,
name|void
operator|*
name|decl
argument_list|)
operator|:
name|m_type_system
argument_list|(
name|type_system
argument_list|)
operator|,
name|m_opaque_decl
argument_list|(
argument|decl
argument_list|)
block|{}
operator|~
name|CompilerDecl
argument_list|()
block|{}
comment|//----------------------------------------------------------------------
comment|// Tests
comment|//----------------------------------------------------------------------
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|IsValid
argument_list|()
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CompilerDecl
operator|&
name|rhs
operator|)
specifier|const
block|{
if|if
condition|(
name|m_type_system
operator|==
name|rhs
operator|.
name|m_type_system
condition|)
return|return
name|m_opaque_decl
operator|<
name|rhs
operator|.
name|m_opaque_decl
return|;
return|return
name|m_type_system
operator|<
name|rhs
operator|.
name|m_type_system
return|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_type_system
operator|!=
name|nullptr
operator|&&
name|m_opaque_decl
operator|!=
name|nullptr
return|;
block|}
name|bool
name|IsClang
argument_list|()
specifier|const
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// Accessors
comment|//----------------------------------------------------------------------
name|TypeSystem
operator|*
name|GetTypeSystem
argument_list|()
specifier|const
block|{
return|return
name|m_type_system
return|;
block|}
name|void
operator|*
name|GetOpaqueDecl
argument_list|()
specifier|const
block|{
return|return
name|m_opaque_decl
return|;
block|}
name|void
name|SetDecl
parameter_list|(
name|TypeSystem
modifier|*
name|type_system
parameter_list|,
name|void
modifier|*
name|decl
parameter_list|)
block|{
name|m_type_system
operator|=
name|type_system
expr_stmt|;
name|m_opaque_decl
operator|=
name|decl
expr_stmt|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_type_system
operator|=
name|nullptr
expr_stmt|;
name|m_opaque_decl
operator|=
name|nullptr
expr_stmt|;
block|}
name|ConstString
name|GetName
argument_list|()
specifier|const
expr_stmt|;
name|ConstString
name|GetMangledName
argument_list|()
specifier|const
expr_stmt|;
name|CompilerDeclContext
name|GetDeclContext
argument_list|()
specifier|const
expr_stmt|;
comment|// If this decl represents a function, return the return type
name|CompilerType
name|GetFunctionReturnType
argument_list|()
specifier|const
expr_stmt|;
comment|// If this decl represents a function, return the number of arguments for the
comment|// function
name|size_t
name|GetNumFunctionArguments
argument_list|()
specifier|const
expr_stmt|;
comment|// If this decl represents a function, return the argument type given a zero
comment|// based argument index
name|CompilerType
name|GetFunctionArgumentType
argument_list|(
name|size_t
name|arg_idx
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|TypeSystem
modifier|*
name|m_type_system
decl_stmt|;
name|void
modifier|*
name|m_opaque_decl
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CompilerDecl
operator|&
name|lhs
operator|,
specifier|const
name|CompilerDecl
operator|&
name|rhs
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|CompilerDecl
operator|&
name|lhs
operator|,
specifier|const
name|CompilerDecl
operator|&
name|rhs
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_CompilerDecl_h_
end_comment

end_unit

