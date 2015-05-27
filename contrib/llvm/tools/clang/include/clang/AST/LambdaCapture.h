begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LambdaCapture.h - Types for C++ Lambda Captures --------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the LambdaCapture class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_AST_LAMBDACAPTURE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_LAMBDACAPTURE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Lambda.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Describes the capture of a variable or of \c this, or of a
comment|/// C++1y init-capture.
name|class
name|LambdaCapture
block|{
enum|enum
block|{
comment|/// \brief Flag used by the Capture class to indicate that the given
comment|/// capture was implicit.
name|Capture_Implicit
init|=
literal|0x01
block|,
comment|/// \brief Flag used by the Capture class to indicate that the
comment|/// given capture was by-copy.
comment|///
comment|/// This includes the case of a non-reference init-capture.
name|Capture_ByCopy
init|=
literal|0x02
block|}
enum|;
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Decl
operator|*
operator|,
literal|2
operator|>
name|DeclAndBits
expr_stmt|;
name|SourceLocation
name|Loc
decl_stmt|;
name|SourceLocation
name|EllipsisLoc
decl_stmt|;
name|friend
name|class
name|ASTStmtReader
decl_stmt|;
name|friend
name|class
name|ASTStmtWriter
decl_stmt|;
name|public
label|:
comment|/// \brief Create a new capture of a variable or of \c this.
comment|///
comment|/// \param Loc The source location associated with this capture.
comment|///
comment|/// \param Kind The kind of capture (this, byref, bycopy), which must
comment|/// not be init-capture.
comment|///
comment|/// \param Implicit Whether the capture was implicit or explicit.
comment|///
comment|/// \param Var The local variable being captured, or null if capturing
comment|/// \c this.
comment|///
comment|/// \param EllipsisLoc The location of the ellipsis (...) for a
comment|/// capture that is a pack expansion, or an invalid source
comment|/// location to indicate that this is not a pack expansion.
name|LambdaCapture
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|bool Implicit
argument_list|,
argument|LambdaCaptureKind Kind
argument_list|,
argument|VarDecl *Var = nullptr
argument_list|,
argument|SourceLocation EllipsisLoc = SourceLocation()
argument_list|)
empty_stmt|;
comment|/// \brief Determine the kind of capture.
name|LambdaCaptureKind
name|getCaptureKind
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this capture handles the C++ \c this
comment|/// pointer.
name|bool
name|capturesThis
argument_list|()
specifier|const
block|{
return|return
operator|(
name|DeclAndBits
operator|.
name|getPointer
argument_list|()
operator|==
name|nullptr
operator|)
operator|&&
operator|!
operator|(
name|DeclAndBits
operator|.
name|getInt
argument_list|()
operator|&
name|Capture_ByCopy
operator|)
return|;
block|}
comment|/// \brief Determine whether this capture handles a variable.
name|bool
name|capturesVariable
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|VarDecl
operator|>
operator|(
name|DeclAndBits
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Determine whether this captures a variable length array bound
comment|/// expression.
name|bool
name|capturesVLAType
argument_list|()
specifier|const
block|{
return|return
operator|(
name|DeclAndBits
operator|.
name|getPointer
argument_list|()
operator|==
name|nullptr
operator|)
operator|&&
operator|(
name|DeclAndBits
operator|.
name|getInt
argument_list|()
operator|&
name|Capture_ByCopy
operator|)
return|;
block|}
comment|/// \brief Determine whether this is an init-capture.
name|bool
name|isInitCapture
argument_list|()
specifier|const
block|{
return|return
name|capturesVariable
argument_list|()
operator|&&
name|getCapturedVar
argument_list|()
operator|->
name|isInitCapture
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the declaration of the local variable being
comment|/// captured.
comment|///
comment|/// This operation is only valid if this capture is a variable capture
comment|/// (other than a capture of \c this).
name|VarDecl
operator|*
name|getCapturedVar
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|capturesVariable
argument_list|()
operator|&&
literal|"No variable available for 'this' capture"
argument_list|)
block|;
return|return
name|cast
operator|<
name|VarDecl
operator|>
operator|(
name|DeclAndBits
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Determine whether this was an implicit capture (not
comment|/// written between the square brackets introducing the lambda).
name|bool
name|isImplicit
argument_list|()
specifier|const
block|{
return|return
name|DeclAndBits
operator|.
name|getInt
argument_list|()
operator|&
name|Capture_Implicit
return|;
block|}
comment|/// \brief Determine whether this was an explicit capture (written
comment|/// between the square brackets introducing the lambda).
name|bool
name|isExplicit
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isImplicit
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the source location of the capture.
comment|///
comment|/// For an explicit capture, this returns the location of the
comment|/// explicit capture in the source. For an implicit capture, this
comment|/// returns the location at which the variable or \c this was first
comment|/// used.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Determine whether this capture is a pack expansion,
comment|/// which captures a function parameter pack.
name|bool
name|isPackExpansion
argument_list|()
specifier|const
block|{
return|return
name|EllipsisLoc
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the location of the ellipsis for a capture
comment|/// that is a pack expansion.
name|SourceLocation
name|getEllipsisLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isPackExpansion
argument_list|()
operator|&&
literal|"No ellipsis location for a non-expansion"
argument_list|)
block|;
return|return
name|EllipsisLoc
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

begin_comment
comment|// LLVM_CLANG_AST_LAMBDACAPTURE_H
end_comment

end_unit

