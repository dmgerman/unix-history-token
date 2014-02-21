begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SelectorLocationsKind.h - Kind of selector locations ---*- C++ -*-===//
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
comment|// Describes whether the identifier locations for a selector are "standard"
end_comment

begin_comment
comment|// or not.
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
name|LLVM_CLANG_AST_SELECTORLOCATIONSKIND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_SELECTORLOCATIONSKIND_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Selector
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|ParmVarDecl
decl_stmt|;
comment|/// \brief Whether all locations of the selector identifiers are in a
comment|/// "standard" position.
enum|enum
name|SelectorLocationsKind
block|{
comment|/// \brief Non-standard.
name|SelLoc_NonStandard
init|=
literal|0
block|,
comment|/// \brief For nullary selectors, immediately before the end:
comment|///    "[foo release]" / "-(void)release;"
comment|/// Or immediately before the arguments:
comment|///    "[foo first:1 second:2]" / "-(id)first:(int)x second:(int)y;
name|SelLoc_StandardNoSpace
init|=
literal|1
block|,
comment|/// \brief For nullary selectors, immediately before the end:
comment|///    "[foo release]" / "-(void)release;"
comment|/// Or with a space between the arguments:
comment|///    "[foo first: 1 second: 2]" / "-(id)first: (int)x second: (int)y;
name|SelLoc_StandardWithSpace
init|=
literal|2
block|}
enum|;
comment|/// \brief Returns true if all \p SelLocs are in a "standard" location.
name|SelectorLocationsKind
name|hasStandardSelectorLocs
argument_list|(
name|Selector
name|Sel
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelLocs
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
comment|/// \brief Get the "standard" location of a selector identifier, e.g:
comment|/// For nullary selectors, immediately before ']': "[foo release]"
comment|///
comment|/// \param WithArgSpace if true the standard location is with a space apart
comment|/// before arguments: "[foo first: 1 second: 2]"
comment|/// If false: "[foo first:1 second:2]"
name|SourceLocation
name|getStandardSelectorLoc
argument_list|(
name|unsigned
name|Index
argument_list|,
name|Selector
name|Sel
argument_list|,
name|bool
name|WithArgSpace
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
comment|/// \brief Returns true if all \p SelLocs are in a "standard" location.
name|SelectorLocationsKind
name|hasStandardSelectorLocs
argument_list|(
name|Selector
name|Sel
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelLocs
argument_list|,
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
comment|/// \brief Get the "standard" location of a selector identifier, e.g:
comment|/// For nullary selectors, immediately before ']': "[foo release]"
comment|///
comment|/// \param WithArgSpace if true the standard location is with a space apart
comment|/// before arguments: "-(id)first: (int)x second: (int)y;"
comment|/// If false: "-(id)first:(int)x second:(int)y;"
name|SourceLocation
name|getStandardSelectorLoc
argument_list|(
name|unsigned
name|Index
argument_list|,
name|Selector
name|Sel
argument_list|,
name|bool
name|WithArgSpace
argument_list|,
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
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

