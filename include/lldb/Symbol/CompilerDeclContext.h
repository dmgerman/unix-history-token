begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompilerDeclContext.h -----------------------------------*- C++ -*-===//
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
name|liblldb_CompilerDeclContext_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CompilerDeclContext_h_
end_define

begin_include
include|#
directive|include
file|<vector>
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
name|CompilerDeclContext
block|{
name|public
label|:
comment|//----------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//----------------------------------------------------------------------
name|CompilerDeclContext
argument_list|()
operator|:
name|m_type_system
argument_list|(
name|nullptr
argument_list|)
operator|,
name|m_opaque_decl_ctx
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|CompilerDeclContext
argument_list|(
name|TypeSystem
operator|*
name|type_system
argument_list|,
name|void
operator|*
name|decl_ctx
argument_list|)
operator|:
name|m_type_system
argument_list|(
name|type_system
argument_list|)
operator|,
name|m_opaque_decl_ctx
argument_list|(
argument|decl_ctx
argument_list|)
block|{}
operator|~
name|CompilerDeclContext
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
name|CompilerDeclContext
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
name|m_opaque_decl_ctx
operator|<
name|rhs
operator|.
name|m_opaque_decl_ctx
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
name|m_opaque_decl_ctx
operator|!=
name|nullptr
return|;
block|}
name|bool
name|IsClang
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|CompilerDecl
operator|>
name|FindDeclByName
argument_list|(
argument|ConstString name
argument_list|,
argument|const bool ignore_using_decls
argument_list|)
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Checks if this decl context represents a method of a class.
comment|///
comment|/// @param[out] language_ptr
comment|///     If non NULL and \b true is returned from this function,
comment|///     this will indicate if the language that respresents the method.
comment|///
comment|/// @param[out] is_instance_method_ptr
comment|///     If non NULL and \b true is returned from this function,
comment|///     this will indicate if the method is an instance function (true)
comment|///     or a class method (false indicating the function is static, or
comment|///     doesn't require an instance of the class to be called).
comment|///
comment|/// @param[out] language_object_name_ptr
comment|///     If non NULL and \b true is returned from this function,
comment|///     this will indicate if implicit object name for the language
comment|///     like "this" for C++, and "self" for Objective C.
comment|///
comment|/// @return
comment|///     Returns true if this is a decl context that represents a method
comment|///     in a struct, union or class.
comment|//----------------------------------------------------------------------
name|bool
name|IsClassMethod
argument_list|(
name|lldb
operator|::
name|LanguageType
operator|*
name|language_ptr
argument_list|,
name|bool
operator|*
name|is_instance_method_ptr
argument_list|,
name|ConstString
operator|*
name|language_object_name_ptr
argument_list|)
decl_stmt|;
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
name|GetOpaqueDeclContext
argument_list|()
specifier|const
block|{
return|return
name|m_opaque_decl_ctx
return|;
block|}
name|void
name|SetDeclContext
parameter_list|(
name|TypeSystem
modifier|*
name|type_system
parameter_list|,
name|void
modifier|*
name|decl_ctx
parameter_list|)
block|{
name|m_type_system
operator|=
name|type_system
expr_stmt|;
name|m_opaque_decl_ctx
operator|=
name|decl_ctx
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
name|m_opaque_decl_ctx
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
name|GetScopeQualifiedName
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsStructUnionOrClass
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|TypeSystem
modifier|*
name|m_type_system
decl_stmt|;
name|void
modifier|*
name|m_opaque_decl_ctx
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
name|CompilerDeclContext
operator|&
name|lhs
operator|,
specifier|const
name|CompilerDeclContext
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
name|CompilerDeclContext
operator|&
name|lhs
operator|,
specifier|const
name|CompilerDeclContext
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
comment|// #ifndef liblldb_CompilerDeclContext_h_
end_comment

end_unit

