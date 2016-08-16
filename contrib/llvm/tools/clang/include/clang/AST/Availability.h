begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Availability.h - Classes for availability --------------*- C++ -*-===//
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
comment|// This files defines some classes that implement availability checking.
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
name|LLVM_CLANG_AST_AVAILABILITY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_AVAILABILITY_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/VersionTuple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief One specifier in an @available expression.
comment|///
comment|/// \code
comment|///   @available(macos 10.10, *)
comment|/// \endcode
comment|///
comment|/// Here, 'macos 10.10' and '*' both map to an instance of this type.
comment|///
name|class
name|AvailabilitySpec
block|{
comment|/// Represents the version that this specifier requires. If the host OS
comment|/// version is greater than or equal to Version, the @available will evaluate
comment|/// to true.
name|VersionTuple
name|Version
decl_stmt|;
comment|/// Name of the platform that Version corresponds to.
name|StringRef
name|Platform
decl_stmt|;
name|SourceLocation
name|BeginLoc
decl_stmt|,
name|EndLoc
decl_stmt|;
name|public
label|:
name|AvailabilitySpec
argument_list|(
argument|VersionTuple Version
argument_list|,
argument|StringRef Platform
argument_list|,
argument|SourceLocation BeginLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
block|:
name|Version
argument_list|(
name|Version
argument_list|)
operator|,
name|Platform
argument_list|(
name|Platform
argument_list|)
operator|,
name|BeginLoc
argument_list|(
name|BeginLoc
argument_list|)
operator|,
name|EndLoc
argument_list|(
argument|EndLoc
argument_list|)
block|{}
comment|/// This constructor is used when representing the '*' case.
name|AvailabilitySpec
argument_list|(
argument|SourceLocation StarLoc
argument_list|)
operator|:
name|BeginLoc
argument_list|(
name|StarLoc
argument_list|)
operator|,
name|EndLoc
argument_list|(
argument|StarLoc
argument_list|)
block|{}
name|VersionTuple
name|getVersion
argument_list|()
specifier|const
block|{
return|return
name|Version
return|;
block|}
name|StringRef
name|getPlatform
argument_list|()
specifier|const
block|{
return|return
name|Platform
return|;
block|}
name|SourceLocation
name|getBeginLoc
argument_list|()
specifier|const
block|{
return|return
name|BeginLoc
return|;
block|}
name|SourceLocation
name|getEndLoc
argument_list|()
specifier|const
block|{
return|return
name|EndLoc
return|;
block|}
comment|/// Returns true when this represents the '*' case.
name|bool
name|isOtherPlatformSpec
argument_list|()
specifier|const
block|{
return|return
name|Version
operator|.
name|empty
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

