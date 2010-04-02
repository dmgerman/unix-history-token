begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---  BugType.h - Bug Information Desciption ----------------*- C++ -*-===//
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
comment|//  This file defines BugType, a class representing a bug type.
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
name|LLVM_CLANG_ANALYSIS_BUGTYPE
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_BUGTYPE
end_define

begin_include
include|#
directive|include
file|"clang/Checker/BugReporter/BugReporter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ExplodedNode
decl_stmt|;
name|class
name|GRExprEngine
decl_stmt|;
name|class
name|BugType
block|{
name|private
label|:
specifier|const
name|std
operator|::
name|string
name|Name
expr_stmt|;
specifier|const
name|std
operator|::
name|string
name|Category
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|BugReportEquivClass
operator|>
name|EQClasses
expr_stmt|;
name|friend
name|class
name|BugReporter
decl_stmt|;
name|bool
name|SuppressonSink
decl_stmt|;
name|public
label|:
name|BugType
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef cat
argument_list|)
block|:
name|Name
argument_list|(
name|name
argument_list|)
operator|,
name|Category
argument_list|(
name|cat
argument_list|)
operator|,
name|SuppressonSink
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|BugType
argument_list|()
expr_stmt|;
comment|// FIXME: Should these be made strings as well?
name|llvm
operator|::
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|llvm
operator|::
name|StringRef
name|getCategory
argument_list|()
specifier|const
block|{
return|return
name|Category
return|;
block|}
comment|/// isSuppressOnSink - Returns true if bug reports associated with this bug
comment|///  type should be suppressed if the end node of the report is post-dominated
comment|///  by a sink node.
name|bool
name|isSuppressOnSink
argument_list|()
specifier|const
block|{
return|return
name|SuppressonSink
return|;
block|}
name|void
name|setSuppressOnSink
parameter_list|(
name|bool
name|x
parameter_list|)
block|{
name|SuppressonSink
operator|=
name|x
expr_stmt|;
block|}
name|virtual
name|void
name|FlushReports
parameter_list|(
name|BugReporter
modifier|&
name|BR
parameter_list|)
function_decl|;
typedef|typedef
name|llvm
operator|::
name|FoldingSet
operator|<
name|BugReportEquivClass
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|EQClasses
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
name|EQClasses
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|FoldingSet
operator|<
name|BugReportEquivClass
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|EQClasses
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|EQClasses
operator|.
name|end
argument_list|()
return|;
block|}
block|}
empty_stmt|;
name|class
name|BuiltinBug
range|:
name|public
name|BugType
block|{
specifier|const
name|std
operator|::
name|string
name|desc
block|;
name|public
operator|:
name|BuiltinBug
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|description
argument_list|)
operator|:
name|BugType
argument_list|(
name|name
argument_list|,
literal|"Logic error"
argument_list|)
block|,
name|desc
argument_list|(
argument|description
argument_list|)
block|{}
name|BuiltinBug
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
operator|:
name|BugType
argument_list|(
name|name
argument_list|,
literal|"Logic error"
argument_list|)
block|,
name|desc
argument_list|(
argument|name
argument_list|)
block|{}
name|llvm
operator|::
name|StringRef
name|getDescription
argument_list|()
specifier|const
block|{
return|return
name|desc
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

