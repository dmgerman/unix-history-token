begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTStructuralEquivalence.h - ---------------------------*- C++ -*-===//
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
comment|//  This file defines the StructuralEquivalenceContext class which checks for
end_comment

begin_comment
comment|//  structural equivalence between types.
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
name|LLVM_CLANG_AST_ASTSTRUCTURALEQUIVALENCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_ASTSTRUCTURALEQUIVALENCE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DiagnosticBuilder
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
struct|struct
name|StructuralEquivalenceContext
block|{
comment|/// AST contexts for which we are checking structural equivalence.
name|ASTContext
modifier|&
name|FromCtx
decl_stmt|,
modifier|&
name|ToCtx
decl_stmt|;
comment|/// The set of "tentative" equivalences between two canonical
comment|/// declarations, mapping from a declaration in the first context to the
comment|/// declaration in the second context that we believe to be equivalent.
name|llvm
operator|::
name|DenseMap
operator|<
name|Decl
operator|*
operator|,
name|Decl
operator|*
operator|>
name|TentativeEquivalences
expr_stmt|;
comment|/// Queue of declarations in the first context whose equivalence
comment|/// with a declaration in the second context still needs to be verified.
name|std
operator|::
name|deque
operator|<
name|Decl
operator|*
operator|>
name|DeclsToCheck
expr_stmt|;
comment|/// Declaration (from, to) pairs that are known not to be equivalent
comment|/// (which we have already complained about).
name|llvm
operator|::
name|DenseSet
operator|<
name|std
operator|::
name|pair
operator|<
name|Decl
operator|*
operator|,
name|Decl
operator|*
operator|>>
operator|&
name|NonEquivalentDecls
expr_stmt|;
comment|/// Whether we're being strict about the spelling of types when
comment|/// unifying two types.
name|bool
name|StrictTypeSpelling
decl_stmt|;
comment|/// Whether warn or error on tag type mismatches.
name|bool
name|ErrorOnTagTypeMismatch
decl_stmt|;
comment|/// Whether to complain about failures.
name|bool
name|Complain
decl_stmt|;
comment|/// \c true if the last diagnostic came from ToCtx.
name|bool
name|LastDiagFromC2
decl_stmt|;
name|StructuralEquivalenceContext
argument_list|(
argument|ASTContext&FromCtx
argument_list|,
argument|ASTContext&ToCtx
argument_list|,
argument|llvm::DenseSet<std::pair<Decl *
argument_list|,
argument|Decl *>>&NonEquivalentDecls
argument_list|,
argument|bool StrictTypeSpelling = false
argument_list|,
argument|bool Complain = true
argument_list|)
block|:
name|FromCtx
argument_list|(
name|FromCtx
argument_list|)
operator|,
name|ToCtx
argument_list|(
name|ToCtx
argument_list|)
operator|,
name|NonEquivalentDecls
argument_list|(
name|NonEquivalentDecls
argument_list|)
operator|,
name|StrictTypeSpelling
argument_list|(
name|StrictTypeSpelling
argument_list|)
operator|,
name|Complain
argument_list|(
name|Complain
argument_list|)
operator|,
name|LastDiagFromC2
argument_list|(
argument|false
argument_list|)
block|{}
name|DiagnosticBuilder
name|Diag1
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|unsigned DiagID
argument_list|)
expr_stmt|;
name|DiagnosticBuilder
name|Diag2
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// Determine whether the two declarations are structurally
comment|/// equivalent.
name|bool
name|IsStructurallyEquivalent
parameter_list|(
name|Decl
modifier|*
name|D1
parameter_list|,
name|Decl
modifier|*
name|D2
parameter_list|)
function_decl|;
comment|/// Determine whether the two types are structurally equivalent.
name|bool
name|IsStructurallyEquivalent
parameter_list|(
name|QualType
name|T1
parameter_list|,
name|QualType
name|T2
parameter_list|)
function_decl|;
comment|/// Find the index of the given anonymous struct/union within its
comment|/// context.
comment|///
comment|/// \returns Returns the index of this anonymous struct/union in its context,
comment|/// including the next assigned index (if none of them match). Returns an
comment|/// empty option if the context is not a record, i.e.. if the anonymous
comment|/// struct/union is at namespace or block scope.
comment|///
comment|/// FIXME: This is needed by ASTImporter and ASTStructureEquivalence. It
comment|/// probably makes more sense in some other common place then here.
specifier|static
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|findUntaggedStructOrUnionIndex
argument_list|(
name|RecordDecl
operator|*
name|Anon
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// Finish checking all of the structural equivalences.
comment|///
comment|/// \returns true if an error occurred, false otherwise.
name|bool
name|Finish
parameter_list|()
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_ASTSTRUCTURALEQUIVALENCE_H
end_comment

end_unit

