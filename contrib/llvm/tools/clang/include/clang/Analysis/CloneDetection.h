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
file|"llvm/ADT/SmallVector.h"
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
comment|/// Identifies a list of statements.
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
comment|/// The declaration that contains the statements.
specifier|const
name|Decl
modifier|*
name|D
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
comment|/// Constructs a StmtSequence holding multiple statements.
comment|///
comment|/// The resulting StmtSequence identifies a continuous sequence of statements
comment|/// in the body of the given CompoundStmt. Which statements of the body should
comment|/// be identified needs to be specified by providing a start and end index
comment|/// that describe a non-empty sub-array in the body of the given CompoundStmt.
comment|///
comment|/// \param Stmt A CompoundStmt that contains all statements in its body.
comment|/// \param D The Decl containing this Stmt.
comment|/// \param StartIndex The inclusive start index in the children array of
comment|///                   \p Stmt
comment|/// \param EndIndex The exclusive end index in the children array of \p Stmt.
name|StmtSequence
argument_list|(
argument|const CompoundStmt *Stmt
argument_list|,
argument|const Decl *D
argument_list|,
argument|unsigned StartIndex
argument_list|,
argument|unsigned EndIndex
argument_list|)
empty_stmt|;
comment|/// Constructs a StmtSequence holding a single statement.
comment|///
comment|/// \param Stmt An arbitrary Stmt.
comment|/// \param D The Decl containing this Stmt.
name|StmtSequence
argument_list|(
specifier|const
name|Stmt
operator|*
name|Stmt
argument_list|,
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// Constructs an empty StmtSequence.
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
expr_stmt|;
comment|/// Returns the declaration that contains the stored Stmts.
specifier|const
name|Decl
operator|*
name|getContainingDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|D
argument_list|)
block|;
return|return
name|D
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
comment|/// Searches for similar subtrees in the AST.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// First, this class needs several declarations with statement bodies which
end_comment

begin_comment
comment|/// can be passed via analyzeCodeBody. Afterwards all statements can be
end_comment

begin_comment
comment|/// searched for clones by calling findClones with a given list of constraints
end_comment

begin_comment
comment|/// that should specify the wanted properties of the clones.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The result of findClones can be further constrained with the constrainClones
end_comment

begin_comment
comment|/// method.
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
comment|/// A collection of StmtSequences that share an arbitrary property.
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|StmtSequence
operator|,
literal|8
operator|>
name|CloneGroup
expr_stmt|;
comment|/// Generates and stores search data for all statements in the body of
comment|/// the given Decl.
name|void
name|analyzeCodeBody
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// Constrains the given list of clone groups with the given constraint.
comment|///
comment|/// The constraint is expected to have a method with the signature
comment|///     `void constrain(std::vector<CloneDetector::CloneGroup>&Sequences)`
comment|/// as this is the interface that the CloneDetector uses for applying the
comment|/// constraint. The constraint is supposed to directly modify the passed list
comment|/// so that all clones in the list fulfill the specific property this
comment|/// constraint ensures.
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|constrainClones
argument_list|(
argument|std::vector<CloneGroup>&CloneGroups
argument_list|,
argument|T C
argument_list|)
block|{
name|C
operator|.
name|constrain
argument_list|(
name|CloneGroups
argument_list|)
block|;   }
comment|/// Constrains the given list of clone groups with the given list of
comment|/// constraints.
comment|///
comment|/// The constraints are applied in sequence in the order in which they are
comment|/// passed to this function.
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
operator|...
name|Ts
operator|>
specifier|static
name|void
name|constrainClones
argument_list|(
argument|std::vector<CloneGroup>&CloneGroups
argument_list|,
argument|T1 C
argument_list|,
argument|Ts... ConstraintList
argument_list|)
block|{
name|constrainClones
argument_list|(
name|CloneGroups
argument_list|,
name|C
argument_list|)
block|;
name|constrainClones
argument_list|(
name|CloneGroups
argument_list|,
name|ConstraintList
operator|...
argument_list|)
block|;   }
comment|/// Searches for clones in all previously passed statements.
comment|/// \param Result Output parameter to which all created clone groups are
comment|///               added.
comment|/// \param ConstraintList The constraints that should be applied to the
comment|//         result.
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|void
name|findClones
argument_list|(
argument|std::vector<CloneGroup>&Result
argument_list|,
argument|Ts... ConstraintList
argument_list|)
block|{
comment|// The initial assumption is that there is only one clone group and every
comment|// statement is a clone of the others. This clone group will then be
comment|// split up with the help of the constraints.
name|CloneGroup
name|AllClones
block|;
name|AllClones
operator|.
name|reserve
argument_list|(
name|Sequences
operator|.
name|size
argument_list|()
argument_list|)
block|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|C
range|:
name|Sequences
control|)
block|{
name|AllClones
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|Result
operator|.
name|push_back
argument_list|(
name|AllClones
argument_list|)
expr_stmt|;
name|constrainClones
argument_list|(
name|Result
argument_list|,
name|ConstraintList
operator|...
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|CloneGroup
name|Sequences
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// This class is a utility class that contains utility functions for building
end_comment

begin_comment
comment|/// custom constraints.
end_comment

begin_decl_stmt
name|class
name|CloneConstraint
block|{
name|public
label|:
comment|/// Removes all groups by using a filter function.
comment|/// \param CloneGroups The list of CloneGroups that is supposed to be
comment|///                    filtered.
comment|/// \param Filter The filter function that should return true for all groups
comment|///               that should be removed from the list.
specifier|static
name|void
name|filterGroups
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CloneDetector
operator|::
name|CloneGroup
operator|>
operator|&
name|CloneGroups
argument_list|,
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|CloneDetector
operator|::
name|CloneGroup
operator|&
argument_list|)
operator|>
name|Filter
argument_list|)
block|{
name|CloneGroups
operator|.
name|erase
argument_list|(
name|std
operator|::
name|remove_if
argument_list|(
name|CloneGroups
operator|.
name|begin
argument_list|()
argument_list|,
name|CloneGroups
operator|.
name|end
argument_list|()
argument_list|,
name|Filter
argument_list|)
argument_list|,
name|CloneGroups
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// Splits the given CloneGroups until the given Compare function returns true
comment|/// for all clones in a single group.
comment|/// \param CloneGroups A list of CloneGroups that should be modified.
comment|/// \param Compare The comparison function that all clones are supposed to
comment|///                pass. Should return true if and only if two clones belong
comment|///                to the same CloneGroup.
specifier|static
name|void
name|splitCloneGroups
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CloneDetector
operator|::
name|CloneGroup
operator|>
operator|&
name|CloneGroups
argument_list|,
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|StmtSequence
operator|&
argument_list|,
specifier|const
name|StmtSequence
operator|&
argument_list|)
operator|>
name|Compare
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Searches all children of the given clones for type II clones (i.e. they are
end_comment

begin_comment
comment|/// identical in every aspect beside the used variable names).
end_comment

begin_decl_stmt
name|class
name|RecursiveCloneTypeIIConstraint
block|{
comment|/// Generates and saves a hash code for the given Stmt.
comment|/// \param S The given Stmt.
comment|/// \param D The Decl containing S.
comment|/// \param StmtsByHash Output parameter that will contain the hash codes for
comment|///                    each StmtSequence in the given Stmt.
comment|/// \return The hash code of the given Stmt.
comment|///
comment|/// If the given Stmt is a CompoundStmt, this method will also generate
comment|/// hashes for all possible StmtSequences in the children of this Stmt.
name|size_t
name|saveHash
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
argument_list|,
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|size_t
argument_list|,
name|StmtSequence
operator|>>
operator|&
name|StmtsByHash
argument_list|)
decl_stmt|;
name|public
label|:
name|void
name|constrain
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CloneDetector
operator|::
name|CloneGroup
operator|>
operator|&
name|Sequences
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Ensures that every clone has at least the given complexity.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Complexity is here defined as the total amount of children of a statement.
end_comment

begin_comment
comment|/// This constraint assumes the first statement in the group is representative
end_comment

begin_comment
comment|/// for all other statements in the group in terms of complexity.
end_comment

begin_decl_stmt
name|class
name|MinComplexityConstraint
block|{
name|unsigned
name|MinComplexity
decl_stmt|;
name|public
label|:
name|MinComplexityConstraint
argument_list|(
argument|unsigned MinComplexity
argument_list|)
block|:
name|MinComplexity
argument_list|(
argument|MinComplexity
argument_list|)
block|{}
name|size_t
name|calculateStmtComplexity
argument_list|(
specifier|const
name|StmtSequence
operator|&
name|Seq
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ParentMacroStack
operator|=
literal|""
argument_list|)
decl_stmt|;
name|void
name|constrain
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CloneDetector
operator|::
name|CloneGroup
operator|>
operator|&
name|CloneGroups
argument_list|)
block|{
name|CloneConstraint
operator|::
name|filterGroups
argument_list|(
name|CloneGroups
argument_list|,
index|[
name|this
index|]
operator|(
specifier|const
name|CloneDetector
operator|::
name|CloneGroup
operator|&
name|A
operator|)
block|{
if|if
condition|(
operator|!
name|A
operator|.
name|empty
argument_list|()
condition|)
return|return
name|calculateStmtComplexity
argument_list|(
name|A
operator|.
name|front
argument_list|()
argument_list|)
operator|<
name|MinComplexity
return|;
else|else
return|return
name|false
return|;
block|}
block|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// Ensures that all clone groups contain at least the given amount of clones.
end_comment

begin_decl_stmt
name|class
name|MinGroupSizeConstraint
block|{
name|unsigned
name|MinGroupSize
decl_stmt|;
name|public
label|:
name|MinGroupSizeConstraint
argument_list|(
argument|unsigned MinGroupSize =
literal|2
argument_list|)
block|:
name|MinGroupSize
argument_list|(
argument|MinGroupSize
argument_list|)
block|{}
name|void
name|constrain
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CloneDetector
operator|::
name|CloneGroup
operator|>
operator|&
name|CloneGroups
argument_list|)
block|{
name|CloneConstraint
operator|::
name|filterGroups
argument_list|(
name|CloneGroups
argument_list|,
index|[
name|this
index|]
operator|(
specifier|const
name|CloneDetector
operator|::
name|CloneGroup
operator|&
name|A
operator|)
block|{
return|return
name|A
operator|.
name|size
argument_list|()
operator|<
name|MinGroupSize
return|;
block|}
block|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// Ensures that no clone group fully contains another clone group.
end_comment

begin_struct
struct|struct
name|OnlyLargestCloneConstraint
block|{
name|void
name|constrain
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CloneDetector
operator|::
name|CloneGroup
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Analyzes the pattern of the referenced variables in a statement.
end_comment

begin_decl_stmt
name|class
name|VariablePattern
block|{
comment|/// Describes an occurence of a variable reference in a statement.
struct|struct
name|VariableOccurence
block|{
comment|/// The index of the associated VarDecl in the Variables vector.
name|size_t
name|KindID
decl_stmt|;
comment|/// The statement in the code where the variable was referenced.
specifier|const
name|Stmt
modifier|*
name|Mention
decl_stmt|;
name|VariableOccurence
argument_list|(
argument|size_t KindID
argument_list|,
argument|const Stmt *Mention
argument_list|)
block|:
name|KindID
argument_list|(
name|KindID
argument_list|)
operator|,
name|Mention
argument_list|(
argument|Mention
argument_list|)
block|{}
block|}
struct|;
comment|/// All occurences of referenced variables in the order of appearance.
name|std
operator|::
name|vector
operator|<
name|VariableOccurence
operator|>
name|Occurences
expr_stmt|;
comment|/// List of referenced variables in the order of appearance.
comment|/// Every item in this list is unique.
name|std
operator|::
name|vector
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|Variables
expr_stmt|;
comment|/// Adds a new variable referenced to this pattern.
comment|/// \param VarDecl The declaration of the variable that is referenced.
comment|/// \param Mention The SourceRange where this variable is referenced.
name|void
name|addVariableOccurence
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VarDecl
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|Mention
parameter_list|)
function_decl|;
comment|/// Adds each referenced variable from the given statement.
name|void
name|addVariables
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Creates an VariablePattern object with information about the given
comment|/// StmtSequence.
name|VariablePattern
argument_list|(
argument|const StmtSequence&Sequence
argument_list|)
block|{
for|for
control|(
specifier|const
name|Stmt
modifier|*
name|S
range|:
name|Sequence
control|)
name|addVariables
argument_list|(
name|S
argument_list|)
expr_stmt|;
block|}
comment|/// Describes two clones that reference their variables in a different pattern
comment|/// which could indicate a programming error.
struct|struct
name|SuspiciousClonePair
block|{
comment|/// Utility class holding the relevant information about a single
comment|/// clone in this pair.
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
comment|/// Counts the differences between this pattern and the given one.
comment|/// \param Other The given VariablePattern to compare with.
comment|/// \param FirstMismatch Output parameter that will be filled with information
comment|///        about the first difference between the two patterns. This parameter
comment|///        can be a nullptr, in which case it will be ignored.
comment|/// \return Returns the number of differences between the pattern this object
comment|///         is following and the given VariablePattern.
comment|///
comment|/// For example, the following statements all have the same pattern and this
comment|/// function would return zero:
comment|///
comment|///   if (a< b) return a; return b;
comment|///   if (x< y) return x; return y;
comment|///   if (u2< u1) return u2; return u1;
comment|///
comment|/// But the following statement has a different pattern (note the changed
comment|/// variables in the return statements) and would have two differences when
comment|/// compared with one of the statements above.
comment|///
comment|///   if (a< b) return b; return a;
comment|///
comment|/// This function should only be called if the related statements of the given
comment|/// pattern and the statements of this objects are clones of each other.
name|unsigned
name|countPatternDifferences
argument_list|(
specifier|const
name|VariablePattern
operator|&
name|Other
argument_list|,
name|VariablePattern
operator|::
name|SuspiciousClonePair
operator|*
name|FirstMismatch
operator|=
name|nullptr
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Ensures that all clones reference variables in the same pattern.
end_comment

begin_struct
struct|struct
name|MatchingVariablePatternConstraint
block|{
name|void
name|constrain
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CloneDetector
operator|::
name|CloneGroup
operator|>
operator|&
name|CloneGroups
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

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

