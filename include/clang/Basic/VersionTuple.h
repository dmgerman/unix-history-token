begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- VersionTuple.h - Version Number Handling -----------------*- C++ -*-===//
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
comment|// This header defines the VersionTuple class, which represents a version in
end_comment

begin_comment
comment|// the form major[.minor[.subminor]].
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
name|LLVM_CLANG_BASIC_VERSIONTUPLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_VERSIONTUPLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

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
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Represents a version number in the form major[.minor[.subminor]].
name|class
name|VersionTuple
block|{
name|unsigned
name|Major
decl_stmt|;
name|unsigned
name|Minor
range|:
literal|31
decl_stmt|;
name|unsigned
name|Subminor
range|:
literal|31
decl_stmt|;
name|unsigned
name|HasMinor
range|:
literal|1
decl_stmt|;
name|unsigned
name|HasSubminor
range|:
literal|1
decl_stmt|;
name|public
label|:
name|VersionTuple
argument_list|()
operator|:
name|Major
argument_list|(
literal|0
argument_list|)
operator|,
name|Minor
argument_list|(
literal|0
argument_list|)
operator|,
name|Subminor
argument_list|(
literal|0
argument_list|)
operator|,
name|HasMinor
argument_list|(
name|false
argument_list|)
operator|,
name|HasSubminor
argument_list|(
argument|false
argument_list|)
block|{ }
name|explicit
name|VersionTuple
argument_list|(
argument|unsigned Major
argument_list|)
operator|:
name|Major
argument_list|(
name|Major
argument_list|)
operator|,
name|Minor
argument_list|(
literal|0
argument_list|)
operator|,
name|Subminor
argument_list|(
literal|0
argument_list|)
operator|,
name|HasMinor
argument_list|(
name|false
argument_list|)
operator|,
name|HasSubminor
argument_list|(
argument|false
argument_list|)
block|{ }
name|explicit
name|VersionTuple
argument_list|(
argument|unsigned Major
argument_list|,
argument|unsigned Minor
argument_list|)
operator|:
name|Major
argument_list|(
name|Major
argument_list|)
operator|,
name|Minor
argument_list|(
name|Minor
argument_list|)
operator|,
name|Subminor
argument_list|(
literal|0
argument_list|)
operator|,
name|HasMinor
argument_list|(
name|true
argument_list|)
operator|,
name|HasSubminor
argument_list|(
argument|false
argument_list|)
block|{ }
name|explicit
name|VersionTuple
argument_list|(
argument|unsigned Major
argument_list|,
argument|unsigned Minor
argument_list|,
argument|unsigned Subminor
argument_list|)
operator|:
name|Major
argument_list|(
name|Major
argument_list|)
operator|,
name|Minor
argument_list|(
name|Minor
argument_list|)
operator|,
name|Subminor
argument_list|(
name|Subminor
argument_list|)
operator|,
name|HasMinor
argument_list|(
name|true
argument_list|)
operator|,
name|HasSubminor
argument_list|(
argument|true
argument_list|)
block|{ }
comment|/// \brief Determine whether this version information is empty
comment|/// (e.g., all version components are zero).
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Major
operator|==
literal|0
operator|&&
name|Minor
operator|==
literal|0
operator|&&
name|Subminor
operator|==
literal|0
return|;
block|}
comment|/// \brief Retrieve the major version number.
name|unsigned
name|getMajor
argument_list|()
specifier|const
block|{
return|return
name|Major
return|;
block|}
comment|/// \brief Retrieve the minor version number, if provided.
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|getMinor
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasMinor
condition|)
return|return
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
operator|(
operator|)
return|;
return|return
name|Minor
return|;
block|}
comment|/// \brief Retrieve the subminor version number, if provided.
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|getSubminor
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasSubminor
condition|)
return|return
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
operator|(
operator|)
return|;
return|return
name|Subminor
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determine if two version numbers are equivalent. If not
end_comment

begin_comment
comment|/// provided, minor and subminor version numbers are considered to be zero.
end_comment

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|VersionTuple
operator|&
name|X
operator|,
specifier|const
name|VersionTuple
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Major
operator|==
name|Y
operator|.
name|Major
operator|&&
name|X
operator|.
name|Minor
operator|==
name|Y
operator|.
name|Minor
operator|&&
name|X
operator|.
name|Subminor
operator|==
name|Y
operator|.
name|Subminor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine if two version numbers are not equivalent. If
end_comment

begin_comment
comment|/// not provided, minor and subminor version numbers are considered to be
end_comment

begin_comment
comment|/// zero.
end_comment

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|VersionTuple
operator|&
name|X
operator|,
specifier|const
name|VersionTuple
operator|&
name|Y
operator|)
block|{
return|return
operator|!
operator|(
name|X
operator|==
name|Y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether one version number precedes another. If not
end_comment

begin_comment
comment|/// provided, minor and subminor version numbers are considered to be zero.
end_comment

begin_expr_stmt
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|VersionTuple
operator|&
name|X
operator|,
specifier|const
name|VersionTuple
operator|&
name|Y
operator|)
block|{
if|if
condition|(
name|X
operator|.
name|Major
operator|!=
name|Y
operator|.
name|Major
condition|)
return|return
name|X
operator|.
name|Major
operator|<
name|Y
operator|.
name|Major
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|X
operator|.
name|Minor
operator|!=
name|Y
operator|.
name|Minor
condition|)
return|return
name|X
operator|.
name|Minor
operator|<
name|Y
operator|.
name|Minor
return|;
end_if

begin_return
return|return
name|X
operator|.
name|Subminor
operator|<
name|Y
operator|.
name|Subminor
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determine whether one version number follows another. If not
end_comment

begin_comment
comment|/// provided, minor and subminor version numbers are considered to be zero.
end_comment

begin_expr_stmt
unit|friend
name|bool
name|operator
operator|>
operator|(
specifier|const
name|VersionTuple
operator|&
name|X
operator|,
specifier|const
name|VersionTuple
operator|&
name|Y
operator|)
block|{
return|return
name|Y
operator|<
name|X
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether one version number precedes or is
end_comment

begin_comment
comment|/// equivalent to another. If not provided, minor and subminor
end_comment

begin_comment
comment|/// version numbers are considered to be zero.
end_comment

begin_expr_stmt
name|friend
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|VersionTuple
operator|&
name|X
operator|,
specifier|const
name|VersionTuple
operator|&
name|Y
operator|)
block|{
return|return
operator|!
operator|(
name|Y
operator|<
name|X
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether one version number follows or is
end_comment

begin_comment
comment|/// equivalent to another. If not provided, minor and subminor
end_comment

begin_comment
comment|/// version numbers are considered to be zero.
end_comment

begin_expr_stmt
name|friend
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|VersionTuple
operator|&
name|X
operator|,
specifier|const
name|VersionTuple
operator|&
name|Y
operator|)
block|{
return|return
operator|!
operator|(
name|X
operator|<
name|Y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve a string representation of the version number/
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Print a version number.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
operator|,
specifier|const
name|VersionTuple
operator|&
name|V
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_VERSIONTUPLE_H
end_comment

end_unit

