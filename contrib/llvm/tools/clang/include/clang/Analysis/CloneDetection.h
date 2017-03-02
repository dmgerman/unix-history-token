begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CloneDetection.h - Finds code clones in an AST ---------*- C++ -*-===//
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
comment|/// /file
end_comment

begin_comment
comment|/// This file defines classes for searching and anlyzing source code clones.
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
name|LLVM_CLANG_AST_CLONEDETECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_CLONEDETECTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Hashing.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Stmt
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|CompoundStmt
decl_stmt|;
comment|/// \brief Identifies a list of statements.
comment|///
comment|/// Can either identify a single arbitrary Stmt object, a continuous sequence of
comment|/// child statements inside a CompoundStmt or no statements at all.
name|class
name|StmtSequence
block|{
comment|/// If this object identifies a sequence of statements inside a CompoundStmt,
comment|/// S points to this CompoundStmt. If this object only identifies a single
comment|/// Stmt, then S is a pointer to this Stmt.
specifier|const
name|Stmt
modifier|*
name|S
decl_stmt|;
comment|/// The related ASTContext for S.
name|ASTContext
modifier|*
name|Context
decl_stmt|;
comment|/// If EndIndex is non-zero, then S is a CompoundStmt and this StmtSequence
comment|/// instance is representing the CompoundStmt children inside the array
comment|/// [StartIndex, EndIndex).
name|unsigned
name|StartIndex
decl_stmt|;
name|unsigned
name|EndIndex
decl_stmt|;
name|public
label|:
comment|/// \brief Constructs a StmtSequence holding multiple statements.
comment|///
comment|/// The resulting StmtSequence identifies a continuous sequence of statements
comment|/// in the body of the given CompoundStmt. Which statements of the body should
comment|/// be identified needs to be specified by providing a start and end index
comment|/// that describe a non-empty sub-array in the body of the given CompoundStmt.
comment|///
comment|/// \param Stmt A CompoundStmt that contains all statements in its body.
comment|/// \param Context The ASTContext for the given CompoundStmt.
comment|/// \param StartIndex The inclusive start index in the children array of
comment|///                   \p Stmt
comment|/// \param EndIndex The exclusive end index in the children array of \p Stmt.
name|StmtSequence
argument_list|(
argument|const CompoundStmt *Stmt
argument_list|,
argument|ASTContext&Context
argument_list|,
argument|unsigned StartIndex
argument_list|,
argument|unsigned EndIndex
argument_list|)
empty_stmt|;
comment|/// \brief Constructs a StmtSequence holding a single statement.
comment|///
comment|/// \param Stmt An arbitrary Stmt.
comment|/// \param Context The ASTContext for the given Stmt.
name|StmtSequence
argument_list|(
specifier|const
name|Stmt
operator|*
name|Stmt
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|)
expr_stmt|;
comment|/// \brief Constructs an empty StmtSequence.
name|StmtSequence
argument_list|()
expr_stmt|;
typedef|typedef
specifier|const
name|Stmt
modifier|*
specifier|const
modifier|*
name|iterator
typedef|;
comment|/// Returns an iterator pointing to the first statement in this sequence.
name|iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns an iterator pointing behind the last statement in this sequence.
name|iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the first statement in this sequence.
comment|///
comment|/// This method should only be called on a non-empty StmtSequence object.
specifier|const
name|Stmt
operator|*
name|front
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|begin
argument_list|()
index|[
literal|0
index|]
return|;
block|}
comment|/// Returns the last statement in this sequence.
comment|///
comment|/// This method should only be called on a non-empty StmtSequence object.
specifier|const
name|Stmt
operator|*
name|back
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|begin
argument_list|()
index|[
name|size
argument_list|()
operator|-
literal|1
index|]
return|;
block|}
comment|/// Returns the number of statements this object holds.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
if|if
condition|(
name|holdsSequence
argument_list|()
condition|)
return|return
name|EndIndex
operator|-
name|StartIndex
return|;
if|if
condition|(
name|S
operator|==
name|nullptr
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
comment|/// Returns true if and only if this StmtSequence contains no statements.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
comment|/// Returns the related ASTContext for the stored Stmts.
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Context
argument_list|)
block|;
return|return
operator|*
name|Context
return|;
block|}
comment|/// Returns true if this objects holds a list of statements.
name|bool
name|holdsSequence
argument_list|()
specifier|const
block|{
return|return
name|EndIndex
operator|!=
literal|0
return|;
block|}
comment|/// Returns the start sourcelocation of the first statement in this sequence.
comment|///
comment|/// This method should only be called on a non-empty StmtSequence object.
name|SourceLocation
name|getStartLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the end sourcelocation of the last statement in this sequence.
comment|///
comment|/// This method should only be called on a non-empty StmtSequence object.
name|SourceLocation
name|getEndLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the source range of the whole sequence - from the beginning
comment|/// of the first statement to the end of the last statement.
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|StmtSequence
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|tie
argument_list|(
name|S
argument_list|,
name|StartIndex
argument_list|,
name|EndIndex
argument_list|)
operator|==
name|std
operator|::
name|tie
argument_list|(
name|Other
operator|.
name|S
argument_list|,
name|Other
operator|.
name|StartIndex
argument_list|,
name|Other
operator|.
name|EndIndex
argument_list|)
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|StmtSequence
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|tie
argument_list|(
name|S
argument_list|,
name|StartIndex
argument_list|,
name|EndIndex
argument_list|)
operator|!=
name|std
operator|::
name|tie
argument_list|(
name|Other
operator|.
name|S
argument_list|,
name|Other
operator|.
name|StartIndex
argument_list|,
name|Other
operator|.
name|EndIndex
argument_list|)
return|;
block|}
comment|/// Returns true if and only if this sequence covers a source range that
comment|/// contains the source range of the given sequence \p Other.
comment|///
comment|/// This method should only be called on a non-empty StmtSequence object
comment|/// and passed a non-empty StmtSequence object.
name|bool
name|contains
argument_list|(
specifier|const
name|StmtSequence
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Searches for clones in source code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// First, this class needs a translation unit which is passed via
end_comment

begin_comment
comment|/// \p analyzeTranslationUnit . It will then generate and store search data
end_comment

begin_comment
comment|/// for all statements inside the given translation unit.
end_comment

begin_comment
comment|/// Afterwards the generated data can be used to find code clones by calling
end_comment

begin_comment
comment|/// \p findClones .
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class only searches for clones in exectuable source code
end_comment

begin_comment
comment|/// (e.g. function bodies). Other clones (e.g. cloned comments or declarations)
end_comment

begin_comment
comment|/// are not supported.
end_comment

begin_decl_stmt
name|class
name|CloneDetector
block|{
name|public
label|:
typedef|typedef
name|unsigned
name|DataPiece
typedef|;
comment|/// Holds the data about a StmtSequence that is needed during the search for
comment|/// code clones.
struct|struct
name|CloneSignature
block|{
comment|/// \brief The hash code of the StmtSequence.
comment|///
comment|/// The initial clone groups that are formed during the search for clones
comment|/// consist only of Sequences that share the same hash code. This makes this
comment|/// value the central part of this heuristic that is needed to find clones
comment|/// in a performant way. For this to work, the type of this variable
comment|/// always needs to be small and fast to compare.
comment|///
comment|/// Also, StmtSequences that are clones of each others have to share
comment|/// the same hash code. StmtSequences that are not clones of each other
comment|/// shouldn't share the same hash code, but if they do, it will only
comment|/// degrade the performance of the hash search but doesn't influence
comment|/// the correctness of the result.
name|size_t
name|Hash
decl_stmt|;
comment|/// \brief The complexity of the StmtSequence.
comment|///
comment|/// This value gives an approximation on how many direct or indirect child
comment|/// statements are contained in the related StmtSequence. In general, the
comment|/// greater this value, the greater the amount of statements. However, this
comment|/// is only an approximation and the actual amount of statements can be
comment|/// higher or lower than this value. Statements that are generated by the
comment|/// compiler (e.g. macro expansions) for example barely influence the
comment|/// complexity value.
comment|///
comment|/// The main purpose of this value is to filter clones that are too small
comment|/// and therefore probably not interesting enough for the user.
name|unsigned
name|Complexity
decl_stmt|;
comment|/// \brief Creates an empty CloneSignature without any data.
name|CloneSignature
argument_list|()
operator|:
name|Complexity
argument_list|(
literal|1
argument_list|)
block|{}
name|CloneSignature
argument_list|(
argument|llvm::hash_code Hash
argument_list|,
argument|unsigned Complexity
argument_list|)
operator|:
name|Hash
argument_list|(
name|Hash
argument_list|)
operator|,
name|Complexity
argument_list|(
argument|Complexity
argument_list|)
block|{}
block|}
struct|;
comment|/// Holds group of StmtSequences that are clones of each other and the
comment|/// complexity value (see CloneSignature::Complexity) that all stored
comment|/// StmtSequences have in common.
struct|struct
name|CloneGroup
block|{
name|std
operator|::
name|vector
operator|<
name|StmtSequence
operator|>
name|Sequences
expr_stmt|;
name|CloneSignature
name|Signature
decl_stmt|;
name|CloneGroup
argument_list|()
block|{}
name|CloneGroup
argument_list|(
argument|const StmtSequence&Seq
argument_list|,
argument|CloneSignature Signature
argument_list|)
block|:
name|Signature
argument_list|(
argument|Signature
argument_list|)
block|{
name|Sequences
operator|.
name|push_back
argument_list|(
name|Seq
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Returns false if and only if this group should be skipped when
comment|///        searching for clones.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
comment|// A clone group with only one member makes no sense, so we skip them.
return|return
name|Sequences
operator|.
name|size
argument_list|()
operator|>
literal|1
return|;
block|}
block|}
struct|;
comment|/// \brief Generates and stores search data for all statements in the body of
comment|///        the given Decl.
name|void
name|analyzeCodeBody
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Stores the CloneSignature to allow future querying.
name|void
name|add
parameter_list|(
specifier|const
name|StmtSequence
modifier|&
name|S
parameter_list|,
specifier|const
name|CloneSignature
modifier|&
name|Signature
parameter_list|)
function_decl|;
comment|/// \brief Searches the provided statements for clones.
comment|///
comment|/// \param Result Output parameter that is filled with a list of found
comment|///               clone groups. Each group contains multiple StmtSequences
comment|///               that were identified to be clones of each other.
comment|/// \param MinGroupComplexity Only return clones which have at least this
comment|///                           complexity value.
comment|/// \param CheckPatterns Returns only clone groups in which the referenced
comment|///                      variables follow the same pattern.
name|void
name|findClones
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CloneGroup
operator|>
operator|&
name|Result
argument_list|,
name|unsigned
name|MinGroupComplexity
argument_list|,
name|bool
name|CheckPatterns
operator|=
name|true
argument_list|)
decl_stmt|;
comment|/// \brief Describes two clones that reference their variables in a different
comment|///        pattern which could indicate a programming error.
struct|struct
name|SuspiciousClonePair
block|{
comment|/// \brief Utility class holding the relevant information about a single
comment|///        clone in this pair.
struct|struct
name|SuspiciousCloneInfo
block|{
comment|/// The variable which referencing in this clone was against the pattern.
specifier|const
name|VarDecl
modifier|*
name|Variable
decl_stmt|;
comment|/// Where the variable was referenced.
specifier|const
name|Stmt
modifier|*
name|Mention
decl_stmt|;
comment|/// The variable that should have been referenced to follow the pattern.
comment|/// If Suggestion is a nullptr then it's not possible to fix the pattern
comment|/// by referencing a different variable in this clone.
specifier|const
name|VarDecl
modifier|*
name|Suggestion
decl_stmt|;
name|SuspiciousCloneInfo
argument_list|(
specifier|const
name|VarDecl
operator|*
name|Variable
argument_list|,
specifier|const
name|Stmt
operator|*
name|Mention
argument_list|,
specifier|const
name|VarDecl
operator|*
name|Suggestion
argument_list|)
operator|:
name|Variable
argument_list|(
name|Variable
argument_list|)
operator|,
name|Mention
argument_list|(
name|Mention
argument_list|)
operator|,
name|Suggestion
argument_list|(
argument|Suggestion
argument_list|)
block|{}
name|SuspiciousCloneInfo
argument_list|()
block|{}
block|}
struct|;
comment|/// The first clone in the pair which always has a suggested variable.
name|SuspiciousCloneInfo
name|FirstCloneInfo
decl_stmt|;
comment|/// This other clone in the pair which can have a suggested variable.
name|SuspiciousCloneInfo
name|SecondCloneInfo
decl_stmt|;
block|}
struct|;
comment|/// \brief Searches the provided statements for pairs of clones that don't
comment|///        follow the same pattern when referencing variables.
comment|/// \param Result Output parameter that will contain the clone pairs.
comment|/// \param MinGroupComplexity Only clone pairs in which the clones have at
comment|///                           least this complexity value.
name|void
name|findSuspiciousClones
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SuspiciousClonePair
operator|>
operator|&
name|Result
argument_list|,
name|unsigned
name|MinGroupComplexity
argument_list|)
decl_stmt|;
name|private
label|:
comment|/// Stores all encountered StmtSequences alongside their CloneSignature.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|CloneSignature
operator|,
name|StmtSequence
operator|>>
name|Sequences
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_CLONEDETECTION_H
end_comment

end_unit

