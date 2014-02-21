begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TaggedASTType.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_TaggedASTType_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_TaggedASTType_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangASTType.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// For cases in which there are multiple classes of types that are not
comment|// interchangeable, to allow static type checking.
name|template
operator|<
name|unsigned
name|int
name|C
operator|>
name|class
name|TaggedASTType
operator|:
name|public
name|ClangASTType
block|{
name|public
operator|:
name|TaggedASTType
argument_list|(
specifier|const
name|ClangASTType
operator|&
name|clang_type
argument_list|)
operator|:
name|ClangASTType
argument_list|(
argument|clang_type
argument_list|)
block|{     }
name|TaggedASTType
argument_list|(
argument|lldb::clang_type_t type
argument_list|,
argument|clang::ASTContext *ast_context
argument_list|)
operator|:
name|ClangASTType
argument_list|(
argument|ast_context
argument_list|,
argument|type
argument_list|)
block|{     }
name|TaggedASTType
argument_list|(
specifier|const
name|TaggedASTType
operator|<
name|C
operator|>
operator|&
name|tw
argument_list|)
operator|:
name|ClangASTType
argument_list|(
argument|tw
argument_list|)
block|{     }
name|TaggedASTType
argument_list|()
operator|:
name|ClangASTType
argument_list|()
block|{     }
name|virtual
operator|~
name|TaggedASTType
argument_list|()
block|{     }
name|TaggedASTType
operator|<
name|C
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|TaggedASTType
operator|<
name|C
operator|>
operator|&
name|tw
operator|)
block|{
name|ClangASTType
operator|::
name|operator
operator|=
operator|(
name|tw
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
expr|}
block|;
comment|// Commonly-used tagged types, so code using them is interoperable
typedef|typedef
name|TaggedASTType
operator|<
literal|0
operator|>
name|TypeFromParser
expr_stmt|;
typedef|typedef
name|TaggedASTType
operator|<
literal|1
operator|>
name|TypeFromUser
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

