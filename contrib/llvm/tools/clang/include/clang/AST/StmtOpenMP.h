begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StmtOpenMP.h - Classes for OpenMP directives  ------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file defines OpenMP AST classes for executable directives and
end_comment

begin_comment
comment|/// clauses.
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
name|LLVM_CLANG_AST_STMTOPENMP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_STMTOPENMP_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/OpenMPClause.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/OpenMPKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|//===----------------------------------------------------------------------===//
comment|// AST classes for directives.
comment|//===----------------------------------------------------------------------===//
comment|/// \brief This is a basic class for representing single OpenMP executable
comment|/// directive.
comment|///
name|class
name|OMPExecutableDirective
range|:
name|public
name|Stmt
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Kind of the directive.
name|OpenMPDirectiveKind
name|Kind
block|;
comment|/// \brief Starting location of the directive (directive keyword).
name|SourceLocation
name|StartLoc
block|;
comment|/// \brief Ending location of the directive.
name|SourceLocation
name|EndLoc
block|;
comment|/// \brief Numbers of clauses.
specifier|const
name|unsigned
name|NumClauses
block|;
comment|/// \brief Number of child expressions/stmts.
specifier|const
name|unsigned
name|NumChildren
block|;
comment|/// \brief Offset from this to the start of clauses.
comment|/// There are NumClauses pointers to clauses, they are followed by
comment|/// NumChildren pointers to child stmts/exprs (if the directive type
comment|/// requires an associated stmt, then it has to be the first of them).
specifier|const
name|unsigned
name|ClausesOffset
block|;
comment|/// \brief Get the clauses storage.
name|MutableArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|getClauses
argument_list|()
block|{
name|OMPClause
operator|*
operator|*
name|ClauseStorage
operator|=
name|reinterpret_cast
operator|<
name|OMPClause
operator|*
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
name|ClausesOffset
operator|)
block|;
return|return
name|MutableArrayRef
operator|<
name|OMPClause
operator|*
operator|>
operator|(
name|ClauseStorage
expr|,
name|NumClauses
operator|)
return|;
block|}
name|protected
operator|:
comment|/// \brief Build instance of directive of class \a K.
comment|///
comment|/// \param SC Statement class.
comment|/// \param K Kind of OpenMP directive.
comment|/// \param StartLoc Starting location of the directive (directive keyword).
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|template
operator|<
name|typename
name|T
operator|>
name|OMPExecutableDirective
argument_list|(
argument|const T *
argument_list|,
argument|StmtClass SC
argument_list|,
argument|OpenMPDirectiveKind K
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|unsigned NumChildren
argument_list|)
operator|:
name|Stmt
argument_list|(
name|SC
argument_list|)
block|,
name|Kind
argument_list|(
name|K
argument_list|)
block|,
name|StartLoc
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|StartLoc
argument_list|)
argument_list|)
block|,
name|EndLoc
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|EndLoc
argument_list|)
argument_list|)
block|,
name|NumClauses
argument_list|(
name|NumClauses
argument_list|)
block|,
name|NumChildren
argument_list|(
name|NumChildren
argument_list|)
block|,
name|ClausesOffset
argument_list|(
argument|llvm::RoundUpToAlignment(sizeof(T),                                                llvm::alignOf<OMPClause *>())
argument_list|)
block|{}
comment|/// \brief Sets the list of variables for this clause.
comment|///
comment|/// \param Clauses The list of clauses for the directive.
comment|///
name|void
name|setClauses
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|)
block|;
comment|/// \brief Set the associated statement for the directive.
comment|///
comment|/// /param S Associated statement.
comment|///
name|void
name|setAssociatedStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|assert
argument_list|(
name|hasAssociatedStmt
argument_list|()
operator|&&
literal|"no associated statement."
argument_list|)
block|;
operator|*
name|child_begin
argument_list|()
operator|=
name|S
block|;   }
name|public
operator|:
comment|/// \brief Iterates over a filtered subrange of clauses applied to a
comment|/// directive.
comment|///
comment|/// This iterator visits only those declarations that meet some run-time
comment|/// criteria.
name|template
operator|<
name|class
name|FilterPredicate
operator|>
name|class
name|filtered_clause_iterator
block|{
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
operator|::
name|const_iterator
name|Current
block|;
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
operator|::
name|const_iterator
name|End
block|;
name|FilterPredicate
name|Pred
block|;
name|void
name|SkipToNextClause
argument_list|()
block|{
while|while
condition|(
name|Current
operator|!=
name|End
operator|&&
operator|!
name|Pred
argument_list|(
operator|*
name|Current
argument_list|)
condition|)
operator|++
name|Current
expr_stmt|;
block|}
name|public
operator|:
typedef|typedef
specifier|const
name|OMPClause
modifier|*
name|value_type
typedef|;
name|filtered_clause_iterator
argument_list|()
operator|:
name|Current
argument_list|()
block|,
name|End
argument_list|()
block|{}
name|filtered_clause_iterator
argument_list|(
argument|ArrayRef<OMPClause *> Arr
argument_list|,
argument|FilterPredicate Pred
argument_list|)
operator|:
name|Current
argument_list|(
name|Arr
operator|.
name|begin
argument_list|()
argument_list|)
block|,
name|End
argument_list|(
name|Arr
operator|.
name|end
argument_list|()
argument_list|)
block|,
name|Pred
argument_list|(
argument|Pred
argument_list|)
block|{
name|SkipToNextClause
argument_list|()
block|;     }
name|value_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|Current
return|;
block|}
name|value_type
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
operator|*
name|Current
return|;
block|}
name|filtered_clause_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Current
block|;
name|SkipToNextClause
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|filtered_clause_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|filtered_clause_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
name|bool
name|operator
operator|!
operator|(
operator|)
block|{
return|return
name|Current
operator|==
name|End
return|;
block|}
name|operator
name|bool
argument_list|()
block|{
return|return
name|Current
operator|!=
name|End
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Gets a single clause of the specified kind \a K associated with the
comment|/// current directive iff there is only one clause of this kind (and assertion
comment|/// is fired if there is more than one clause is associated with the
comment|/// directive). Returns nullptr if no clause of kind \a K is associated with
comment|/// the directive.
specifier|const
name|OMPClause
modifier|*
name|getSingleClause
argument_list|(
name|OpenMPClauseKind
name|K
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns starting location of directive kind.
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
return|return
name|StartLoc
return|;
block|}
comment|/// \brief Returns ending location of directive.
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|EndLoc
return|;
block|}
comment|/// \brief Set starting location of directive kind.
comment|///
comment|/// \param Loc New starting location of directive.
comment|///
name|void
name|setLocStart
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|StartLoc
operator|=
name|Loc
expr_stmt|;
block|}
comment|/// \brief Set ending location of directive.
comment|///
comment|/// \param Loc New ending location of directive.
comment|///
name|void
name|setLocEnd
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|EndLoc
operator|=
name|Loc
expr_stmt|;
block|}
comment|/// \brief Get number of clauses.
name|unsigned
name|getNumClauses
argument_list|()
specifier|const
block|{
return|return
name|NumClauses
return|;
block|}
comment|/// \brief Returns specified clause.
comment|///
comment|/// \param i Number of clause.
comment|///
name|OMPClause
modifier|*
name|getClause
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|clauses
argument_list|()
index|[
name|i
index|]
return|;
block|}
comment|/// \brief Returns true if directive has associated statement.
name|bool
name|hasAssociatedStmt
argument_list|()
specifier|const
block|{
return|return
name|NumChildren
operator|>
literal|0
return|;
block|}
comment|/// \brief Returns statement associated with the directive.
name|Stmt
operator|*
name|getAssociatedStmt
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasAssociatedStmt
argument_list|()
operator|&&
literal|"no associated statement."
argument_list|)
block|;
return|return
name|const_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|*
name|child_begin
argument_list|()
operator|)
return|;
block|}
name|OpenMPDirectiveKind
name|getDirectiveKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
operator|->
name|getStmtClass
argument_list|()
operator|>=
name|firstOMPExecutableDirectiveConstant
operator|&&
name|S
operator|->
name|getStmtClass
argument_list|()
operator|<=
name|lastOMPExecutableDirectiveConstant
return|;
block|}
name|child_range
name|children
parameter_list|()
block|{
if|if
condition|(
operator|!
name|hasAssociatedStmt
argument_list|()
condition|)
return|return
name|child_range
argument_list|()
return|;
name|Stmt
modifier|*
modifier|*
name|ChildStorage
init|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|getClauses
argument_list|()
operator|.
name|end
argument_list|()
operator|)
decl_stmt|;
return|return
name|child_range
argument_list|(
name|ChildStorage
argument_list|,
name|ChildStorage
operator|+
name|NumChildren
argument_list|)
return|;
block|}
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|clauses
argument_list|()
block|{
return|return
name|getClauses
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|clauses
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|OMPExecutableDirective
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getClauses
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief This represents '#pragma omp parallel' directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// #pragma omp parallel private(a,b) reduction(+: c,d)
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// In this example directive '#pragma omp parallel' has clauses 'private'
end_comment

begin_comment
comment|/// with the variables 'a' and 'b' and 'reduction' with operator '+' and
end_comment

begin_comment
comment|/// variables 'c' and 'd'.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|OMPParallelDirective
range|:
name|public
name|OMPExecutableDirective
block|{
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive (directive keyword).
comment|/// \param EndLoc Ending Location of the directive.
comment|///
name|OMPParallelDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPParallelDirectiveClass
argument_list|,
argument|OMPD_parallel
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPParallelDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPParallelDirectiveClass
argument_list|,
argument|OMPD_parallel
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement associated with the directive.
comment|///
specifier|static
name|OMPParallelDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a N clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPParallelDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPParallelDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This is a common base class for loop directives ('omp simd', 'omp
comment|/// for', 'omp for simd' etc.). It is responsible for the loop code generation.
comment|///
name|class
name|OMPLoopDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Number of collapsed loops as specified by 'collapse' clause.
name|unsigned
name|CollapsedNum
block|;
comment|/// \brief Offsets to the stored exprs.
comment|/// This enumeration contains offsets to all the pointers to children
comment|/// expressions stored in OMPLoopDirective.
comment|/// The first 9 children are nesessary for all the loop directives, and
comment|/// the next 7 are specific to the worksharing ones.
comment|/// After the fixed children, three arrays of length CollapsedNum are
comment|/// allocated: loop counters, their updates and final values.
comment|///
block|enum
block|{
name|AssociatedStmtOffset
operator|=
literal|0
block|,
name|IterationVariableOffset
operator|=
literal|1
block|,
name|LastIterationOffset
operator|=
literal|2
block|,
name|CalcLastIterationOffset
operator|=
literal|3
block|,
name|PreConditionOffset
operator|=
literal|4
block|,
name|CondOffset
operator|=
literal|5
block|,
name|SeparatedCondOffset
operator|=
literal|6
block|,
name|InitOffset
operator|=
literal|7
block|,
name|IncOffset
operator|=
literal|8
block|,
comment|// The '...End' enumerators do not correspond to child expressions - they
comment|// specify the offset to the end (and start of the following counters/
comment|// updates/finals arrays).
name|DefaultEnd
operator|=
literal|9
block|,
comment|// The following 7 exprs are used by worksharing loops only.
name|IsLastIterVariableOffset
operator|=
literal|9
block|,
name|LowerBoundVariableOffset
operator|=
literal|10
block|,
name|UpperBoundVariableOffset
operator|=
literal|11
block|,
name|StrideVariableOffset
operator|=
literal|12
block|,
name|EnsureUpperBoundOffset
operator|=
literal|13
block|,
name|NextLowerBoundOffset
operator|=
literal|14
block|,
name|NextUpperBoundOffset
operator|=
literal|15
block|,
comment|// Offset to the end (and start of the following counters/updates/finals
comment|// arrays) for worksharing loop directives.
name|WorksharingEnd
operator|=
literal|16
block|,   }
block|;
comment|/// \brief Get the counters storage.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getCounters
argument_list|()
block|{
name|Expr
operator|*
operator|*
name|Storage
operator|=
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
operator|&
operator|(
operator|*
operator|(
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|getArraysOffset
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
argument_list|)
operator|)
operator|)
operator|)
block|;
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Storage
expr|,
name|CollapsedNum
operator|)
return|;
block|}
comment|/// \brief Get the updates storage.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getUpdates
argument_list|()
block|{
name|Expr
operator|*
operator|*
name|Storage
operator|=
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
operator|&
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|getArraysOffset
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|+
name|CollapsedNum
argument_list|)
operator|)
block|;
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Storage
expr|,
name|CollapsedNum
operator|)
return|;
block|}
comment|/// \brief Get the final counter updates storage.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getFinals
argument_list|()
block|{
name|Expr
operator|*
operator|*
name|Storage
operator|=
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
operator|&
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|getArraysOffset
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|+
literal|2
operator|*
name|CollapsedNum
argument_list|)
operator|)
block|;
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Storage
expr|,
name|CollapsedNum
operator|)
return|;
block|}
name|protected
operator|:
comment|/// \brief Build instance of loop directive of class \a Kind.
comment|///
comment|/// \param SC Statement class.
comment|/// \param Kind Kind of OpenMP directive.
comment|/// \param StartLoc Starting location of the directive (directive keyword).
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed loops from 'collapse' clause.
comment|/// \param NumClauses Number of clauses.
comment|/// \param NumSpecialChildren Number of additional directive-specific stmts.
comment|///
name|template
operator|<
name|typename
name|T
operator|>
name|OMPLoopDirective
argument_list|(
argument|const T *That
argument_list|,
argument|StmtClass SC
argument_list|,
argument|OpenMPDirectiveKind Kind
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|unsigned NumSpecialChildren =
literal|0
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
name|That
argument_list|,
name|SC
argument_list|,
name|Kind
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|NumClauses
argument_list|,
name|numLoopChildren
argument_list|(
name|CollapsedNum
argument_list|,
name|Kind
argument_list|)
operator|+
name|NumSpecialChildren
argument_list|)
block|,
name|CollapsedNum
argument_list|(
argument|CollapsedNum
argument_list|)
block|{}
comment|/// \brief Offset to the start of children expression arrays.
specifier|static
name|unsigned
name|getArraysOffset
argument_list|(
argument|OpenMPDirectiveKind Kind
argument_list|)
block|{
return|return
name|isOpenMPWorksharingDirective
argument_list|(
name|Kind
argument_list|)
operator|?
name|WorksharingEnd
operator|:
name|DefaultEnd
return|;
block|}
comment|/// \brief Children number.
specifier|static
name|unsigned
name|numLoopChildren
argument_list|(
argument|unsigned CollapsedNum
argument_list|,
argument|OpenMPDirectiveKind Kind
argument_list|)
block|{
return|return
name|getArraysOffset
argument_list|(
name|Kind
argument_list|)
operator|+
literal|3
operator|*
name|CollapsedNum
return|;
comment|// Counters, Updates and Finals
block|}
name|void
name|setIterationVariable
argument_list|(
argument|Expr *IV
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|IterationVariableOffset
argument_list|)
operator|=
name|IV
block|;   }
name|void
name|setLastIteration
argument_list|(
argument|Expr *LI
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|LastIterationOffset
argument_list|)
operator|=
name|LI
block|;   }
name|void
name|setCalcLastIteration
argument_list|(
argument|Expr *CLI
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|CalcLastIterationOffset
argument_list|)
operator|=
name|CLI
block|;   }
name|void
name|setPreCond
argument_list|(
argument|Expr *PC
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|PreConditionOffset
argument_list|)
operator|=
name|PC
block|;   }
name|void
name|setCond
argument_list|(
argument|Expr *Cond
argument_list|,
argument|Expr *SeparatedCond
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|CondOffset
argument_list|)
operator|=
name|Cond
block|;
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|SeparatedCondOffset
argument_list|)
operator|=
name|SeparatedCond
block|;   }
name|void
name|setInit
argument_list|(
argument|Expr *Init
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|InitOffset
argument_list|)
operator|=
name|Init
block|; }
name|void
name|setInc
argument_list|(
argument|Expr *Inc
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|IncOffset
argument_list|)
operator|=
name|Inc
block|; }
name|void
name|setIsLastIterVariable
argument_list|(
argument|Expr *IL
argument_list|)
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|IsLastIterVariableOffset
argument_list|)
operator|=
name|IL
block|;   }
name|void
name|setLowerBoundVariable
argument_list|(
argument|Expr *LB
argument_list|)
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|LowerBoundVariableOffset
argument_list|)
operator|=
name|LB
block|;   }
name|void
name|setUpperBoundVariable
argument_list|(
argument|Expr *UB
argument_list|)
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|UpperBoundVariableOffset
argument_list|)
operator|=
name|UB
block|;   }
name|void
name|setStrideVariable
argument_list|(
argument|Expr *ST
argument_list|)
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|StrideVariableOffset
argument_list|)
operator|=
name|ST
block|;   }
name|void
name|setEnsureUpperBound
argument_list|(
argument|Expr *EUB
argument_list|)
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|EnsureUpperBoundOffset
argument_list|)
operator|=
name|EUB
block|;   }
name|void
name|setNextLowerBound
argument_list|(
argument|Expr *NLB
argument_list|)
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|NextLowerBoundOffset
argument_list|)
operator|=
name|NLB
block|;   }
name|void
name|setNextUpperBound
argument_list|(
argument|Expr *NUB
argument_list|)
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|NextUpperBoundOffset
argument_list|)
operator|=
name|NUB
block|;   }
name|void
name|setCounters
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|A
argument_list|)
block|;
name|void
name|setUpdates
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|A
argument_list|)
block|;
name|void
name|setFinals
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|A
argument_list|)
block|;
name|public
operator|:
comment|/// \brief The expressions built for the OpenMP loop CodeGen for the
comment|/// whole collapsed loop nest.
expr|struct
name|HelperExprs
block|{
comment|/// \brief Loop iteration variable.
name|Expr
operator|*
name|IterationVarRef
block|;
comment|/// \brief Loop last iteration number.
name|Expr
operator|*
name|LastIteration
block|;
comment|/// \brief Calculation of last iteration.
name|Expr
operator|*
name|CalcLastIteration
block|;
comment|/// \brief Loop pre-condition.
name|Expr
operator|*
name|PreCond
block|;
comment|/// \brief Loop condition.
name|Expr
operator|*
name|Cond
block|;
comment|/// \brief A condition with 1 iteration separated.
name|Expr
operator|*
name|SeparatedCond
block|;
comment|/// \brief Loop iteration variable init.
name|Expr
operator|*
name|Init
block|;
comment|/// \brief Loop increment.
name|Expr
operator|*
name|Inc
block|;
comment|/// \brief IsLastIteration - local flag variable passed to runtime.
name|Expr
operator|*
name|IL
block|;
comment|/// \brief LowerBound - local variable passed to runtime.
name|Expr
operator|*
name|LB
block|;
comment|/// \brief UpperBound - local variable passed to runtime.
name|Expr
operator|*
name|UB
block|;
comment|/// \brief Stride - local variable passed to runtime.
name|Expr
operator|*
name|ST
block|;
comment|/// \brief EnsureUpperBound -- expression LB = min(LB, NumIterations).
name|Expr
operator|*
name|EUB
block|;
comment|/// \brief Update of LowerBound for statically sheduled 'omp for' loops.
name|Expr
operator|*
name|NLB
block|;
comment|/// \brief Update of UpperBound for statically sheduled 'omp for' loops.
name|Expr
operator|*
name|NUB
block|;
comment|/// \brief Counters Loop counters.
name|SmallVector
operator|<
name|Expr
operator|*
block|,
literal|4
operator|>
name|Counters
block|;
comment|/// \brief Expressions for loop counters update for CodeGen.
name|SmallVector
operator|<
name|Expr
operator|*
block|,
literal|4
operator|>
name|Updates
block|;
comment|/// \brief Final loop counter values for GodeGen.
name|SmallVector
operator|<
name|Expr
operator|*
block|,
literal|4
operator|>
name|Finals
block|;
comment|/// \brief Check if all the expressions are built (does not check the
comment|/// worksharing ones).
name|bool
name|builtAll
argument_list|()
block|{
return|return
name|IterationVarRef
operator|!=
name|nullptr
operator|&&
name|LastIteration
operator|!=
name|nullptr
operator|&&
name|PreCond
operator|!=
name|nullptr
operator|&&
name|Cond
operator|!=
name|nullptr
operator|&&
name|SeparatedCond
operator|!=
name|nullptr
operator|&&
name|Init
operator|!=
name|nullptr
operator|&&
name|Inc
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Initialize all the fields to null.
comment|/// \param Size Number of elements in the counters/finals/updates arrays.
name|void
name|clear
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|IterationVarRef
operator|=
name|nullptr
block|;
name|LastIteration
operator|=
name|nullptr
block|;
name|CalcLastIteration
operator|=
name|nullptr
block|;
name|PreCond
operator|=
name|nullptr
block|;
name|Cond
operator|=
name|nullptr
block|;
name|SeparatedCond
operator|=
name|nullptr
block|;
name|Init
operator|=
name|nullptr
block|;
name|Inc
operator|=
name|nullptr
block|;
name|IL
operator|=
name|nullptr
block|;
name|LB
operator|=
name|nullptr
block|;
name|UB
operator|=
name|nullptr
block|;
name|ST
operator|=
name|nullptr
block|;
name|EUB
operator|=
name|nullptr
block|;
name|NLB
operator|=
name|nullptr
block|;
name|NUB
operator|=
name|nullptr
block|;
name|Counters
operator|.
name|resize
argument_list|(
name|Size
argument_list|)
block|;
name|Updates
operator|.
name|resize
argument_list|(
name|Size
argument_list|)
block|;
name|Finals
operator|.
name|resize
argument_list|(
name|Size
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Size
condition|;
operator|++
name|i
control|)
block|{
name|Counters
index|[
name|i
index|]
operator|=
name|nullptr
expr_stmt|;
name|Updates
index|[
name|i
index|]
operator|=
name|nullptr
expr_stmt|;
name|Finals
index|[
name|i
index|]
operator|=
name|nullptr
expr_stmt|;
block|}
block|}
expr|}
block|;
comment|/// \brief Get number of collapsed loops.
name|unsigned
name|getCollapsedNumber
argument_list|()
specifier|const
block|{
return|return
name|CollapsedNum
return|;
block|}
name|Expr
operator|*
name|getIterationVariable
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|IterationVariableOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getLastIteration
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|LastIterationOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getCalcLastIteration
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|CalcLastIterationOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getPreCond
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|PreConditionOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getCond
argument_list|(
argument|bool SeparateIter
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
operator|(
name|SeparateIter
operator|?
name|SeparatedCondOffset
operator|:
name|CondOffset
operator|)
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getInit
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|InitOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getInc
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|IncOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getIsLastIterVariable
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|IsLastIterVariableOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getLowerBoundVariable
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|LowerBoundVariableOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getUpperBoundVariable
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|UpperBoundVariableOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getStrideVariable
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|StrideVariableOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getEnsureUpperBound
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|EnsureUpperBoundOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getNextLowerBound
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|NextLowerBoundOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getNextUpperBound
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|&&
literal|"expected worksharing loop directive"
argument_list|)
block|;
return|return
name|const_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|NextUpperBoundOffset
argument_list|)
operator|)
operator|)
return|;
block|}
specifier|const
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
block|{
comment|// This relies on the loop form is already checked by Sema.
name|Stmt
operator|*
name|Body
operator|=
name|getAssociatedStmt
argument_list|()
operator|->
name|IgnoreContainers
argument_list|(
name|true
argument_list|)
block|;
name|Body
operator|=
name|cast
operator|<
name|ForStmt
operator|>
operator|(
name|Body
operator|)
operator|->
name|getBody
argument_list|()
block|;
for|for
control|(
name|unsigned
name|Cnt
init|=
literal|1
init|;
name|Cnt
operator|<
name|CollapsedNum
condition|;
operator|++
name|Cnt
control|)
block|{
name|Body
operator|=
name|Body
operator|->
name|IgnoreContainers
argument_list|()
expr_stmt|;
name|Body
operator|=
name|cast
operator|<
name|ForStmt
operator|>
operator|(
name|Body
operator|)
operator|->
name|getBody
argument_list|()
expr_stmt|;
block|}
return|return
name|Body
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|counters
argument_list|()
block|{
return|return
name|getCounters
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|counters
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|OMPLoopDirective
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCounters
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|updates
argument_list|()
block|{
return|return
name|getUpdates
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|updates
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|OMPLoopDirective
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getUpdates
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|finals
argument_list|()
block|{
return|return
name|getFinals
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|finals
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|OMPLoopDirective
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getFinals
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPForDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPForSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPParallelForDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPParallelForSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp simd' directive.
comment|///
comment|/// \code
comment|/// #pragma omp simd private(a,b) linear(i,j:s) reduction(+:c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp simd' has clauses 'private'
comment|/// with the variables 'a' and 'b', 'linear' with variables 'i', 'j' and
comment|/// linear step 's', 'reduction' with operator '+' and variables 'c' and 'd'.
comment|///
name|class
name|OMPSimdDirective
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPSimdDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPSimdDirectiveClass
argument_list|,
argument|OMPD_simd
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPSimdDirective
argument_list|(
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPSimdDirectiveClass
argument_list|,
argument|OMPD_simd
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param CollapsedNum Number of collapsed loops.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param Exprs Helper expressions for CodeGen.
comment|///
specifier|static
name|OMPSimdDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|,
argument|const HelperExprs&Exprs
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place
comment|/// for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPSimdDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp for' directive.
comment|///
comment|/// \code
comment|/// #pragma omp for private(a,b) reduction(+:c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp for' has clauses 'private' with the
comment|/// variables 'a' and 'b' and 'reduction' with operator '+' and variables 'c'
comment|/// and 'd'.
comment|///
name|class
name|OMPForDirective
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPForDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPForDirectiveClass
argument_list|,
argument|OMPD_for
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPForDirective
argument_list|(
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPForDirectiveClass
argument_list|,
argument|OMPD_for
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param CollapsedNum Number of collapsed loops.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param Exprs Helper expressions for CodeGen.
comment|///
specifier|static
name|OMPForDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|,
argument|const HelperExprs&Exprs
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place
comment|/// for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPForDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPForDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp for simd' directive.
comment|///
comment|/// \code
comment|/// #pragma omp for simd private(a,b) linear(i,j:s) reduction(+:c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp for simd' has clauses 'private'
comment|/// with the variables 'a' and 'b', 'linear' with variables 'i', 'j' and
comment|/// linear step 's', 'reduction' with operator '+' and variables 'c' and 'd'.
comment|///
name|class
name|OMPForSimdDirective
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPForSimdDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPForSimdDirectiveClass
argument_list|,
argument|OMPD_for_simd
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPForSimdDirective
argument_list|(
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPForSimdDirectiveClass
argument_list|,
argument|OMPD_for_simd
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param CollapsedNum Number of collapsed loops.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param Exprs Helper expressions for CodeGen.
comment|///
specifier|static
name|OMPForSimdDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|,
argument|const HelperExprs&Exprs
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place
comment|/// for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPForSimdDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPForSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp sections' directive.
comment|///
comment|/// \code
comment|/// #pragma omp sections private(a,b) reduction(+:c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp sections' has clauses 'private' with
comment|/// the variables 'a' and 'b' and 'reduction' with operator '+' and variables
comment|/// 'c' and 'd'.
comment|///
name|class
name|OMPSectionsDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPSectionsDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPSectionsDirectiveClass
argument_list|,
argument|OMPD_sections
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPSectionsDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPSectionsDirectiveClass
argument_list|,
argument|OMPD_sections
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPSectionsDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a NumClauses
comment|/// clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPSectionsDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPSectionsDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp section' directive.
comment|///
comment|/// \code
comment|/// #pragma omp section
comment|/// \endcode
comment|///
name|class
name|OMPSectionDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|OMPSectionDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPSectionDirectiveClass
argument_list|,
argument|OMPD_section
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
name|explicit
name|OMPSectionDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPSectionDirectiveClass
argument_list|,
argument|OMPD_section
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPSectionDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|///
specifier|static
name|OMPSectionDirective
operator|*
name|CreateEmpty
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPSectionDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp single' directive.
comment|///
comment|/// \code
comment|/// #pragma omp single private(a,b) copyprivate(c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp single' has clauses 'private' with
comment|/// the variables 'a' and 'b' and 'copyprivate' with variables 'c' and 'd'.
comment|///
name|class
name|OMPSingleDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPSingleDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPSingleDirectiveClass
argument_list|,
argument|OMPD_single
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPSingleDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPSingleDirectiveClass
argument_list|,
argument|OMPD_single
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPSingleDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a NumClauses
comment|/// clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPSingleDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPSingleDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp master' directive.
comment|///
comment|/// \code
comment|/// #pragma omp master
comment|/// \endcode
comment|///
name|class
name|OMPMasterDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|OMPMasterDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPMasterDirectiveClass
argument_list|,
argument|OMPD_master
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
name|explicit
name|OMPMasterDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPMasterDirectiveClass
argument_list|,
argument|OMPD_master
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPMasterDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|///
specifier|static
name|OMPMasterDirective
operator|*
name|CreateEmpty
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPMasterDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp critical' directive.
comment|///
comment|/// \code
comment|/// #pragma omp critical
comment|/// \endcode
comment|///
name|class
name|OMPCriticalDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Name of the directive.
name|DeclarationNameInfo
name|DirName
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param Name Name of the directive.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|OMPCriticalDirective
argument_list|(
argument|const DeclarationNameInfo&Name
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
name|this
argument_list|,
name|OMPCriticalDirectiveClass
argument_list|,
name|OMPD_critical
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|,
name|DirName
argument_list|(
argument|Name
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
name|explicit
name|OMPCriticalDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
name|this
argument_list|,
name|OMPCriticalDirectiveClass
argument_list|,
name|OMPD_critical
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|,
name|DirName
argument_list|()
block|{}
comment|/// \brief Set name of the directive.
comment|///
comment|/// \param Name Name of the directive.
comment|///
name|void
name|setDirectiveName
argument_list|(
argument|const DeclarationNameInfo&Name
argument_list|)
block|{
name|DirName
operator|=
name|Name
block|; }
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param Name Name of the directive.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPCriticalDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|const DeclarationNameInfo&Name
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|///
specifier|static
name|OMPCriticalDirective
operator|*
name|CreateEmpty
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|EmptyShell
argument_list|)
block|;
comment|/// \brief Return name of the directive.
comment|///
name|DeclarationNameInfo
name|getDirectiveName
argument_list|()
specifier|const
block|{
return|return
name|DirName
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPCriticalDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp parallel for' directive.
comment|///
comment|/// \code
comment|/// #pragma omp parallel for private(a,b) reduction(+:c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel for' has clauses 'private'
comment|/// with the variables 'a' and 'b' and 'reduction' with operator '+' and
comment|/// variables 'c' and 'd'.
comment|///
name|class
name|OMPParallelForDirective
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPParallelForDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPParallelForDirectiveClass
argument_list|,
argument|OMPD_parallel_for
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPParallelForDirective
argument_list|(
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPParallelForDirectiveClass
argument_list|,
argument|OMPD_parallel_for
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param CollapsedNum Number of collapsed loops.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param Exprs Helper expressions for CodeGen.
comment|///
specifier|static
name|OMPParallelForDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|,
argument|const HelperExprs&Exprs
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place
comment|/// for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPParallelForDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPParallelForDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp parallel for simd' directive.
comment|///
comment|/// \code
comment|/// #pragma omp parallel for simd private(a,b) linear(i,j:s) reduction(+:c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel for simd' has clauses
comment|/// 'private' with the variables 'a' and 'b', 'linear' with variables 'i', 'j'
comment|/// and linear step 's', 'reduction' with operator '+' and variables 'c' and
comment|/// 'd'.
comment|///
name|class
name|OMPParallelForSimdDirective
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPParallelForSimdDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_parallel_for_simd
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPParallelForSimdDirective
argument_list|(
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
argument|this
argument_list|,
argument|OMPParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_parallel_for_simd
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|CollapsedNum
argument_list|,
argument|NumClauses
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param CollapsedNum Number of collapsed loops.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param Exprs Helper expressions for CodeGen.
comment|///
specifier|static
name|OMPParallelForSimdDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|,
argument|const HelperExprs&Exprs
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place
comment|/// for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPParallelForSimdDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|unsigned CollapsedNum
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPParallelForSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp parallel sections' directive.
comment|///
comment|/// \code
comment|/// #pragma omp parallel sections private(a,b) reduction(+:c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel sections' has clauses
comment|/// 'private' with the variables 'a' and 'b' and 'reduction' with operator '+'
comment|/// and variables 'c' and 'd'.
comment|///
name|class
name|OMPParallelSectionsDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPParallelSectionsDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPParallelSectionsDirectiveClass
argument_list|,
argument|OMPD_parallel_sections
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPParallelSectionsDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPParallelSectionsDirectiveClass
argument_list|,
argument|OMPD_parallel_sections
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPParallelSectionsDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a NumClauses
comment|/// clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPParallelSectionsDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPParallelSectionsDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp task' directive.
comment|///
comment|/// \code
comment|/// #pragma omp task private(a,b) final(d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp task' has clauses 'private' with the
comment|/// variables 'a' and 'b' and 'final' with condition 'd'.
comment|///
name|class
name|OMPTaskDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTaskDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTaskDirectiveClass
argument_list|,
argument|OMPD_task
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTaskDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTaskDirectiveClass
argument_list|,
argument|OMPD_task
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPTaskDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a NumClauses
comment|/// clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTaskDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTaskDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp taskyield' directive.
comment|///
comment|/// \code
comment|/// #pragma omp taskyield
comment|/// \endcode
comment|///
name|class
name|OMPTaskyieldDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|OMPTaskyieldDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTaskyieldDirectiveClass
argument_list|,
argument|OMPD_taskyield
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
name|explicit
name|OMPTaskyieldDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTaskyieldDirectiveClass
argument_list|,
argument|OMPD_taskyield
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|///
specifier|static
name|OMPTaskyieldDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|///
specifier|static
name|OMPTaskyieldDirective
operator|*
name|CreateEmpty
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTaskyieldDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp barrier' directive.
comment|///
comment|/// \code
comment|/// #pragma omp barrier
comment|/// \endcode
comment|///
name|class
name|OMPBarrierDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|OMPBarrierDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPBarrierDirectiveClass
argument_list|,
argument|OMPD_barrier
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
name|explicit
name|OMPBarrierDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPBarrierDirectiveClass
argument_list|,
argument|OMPD_barrier
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|///
specifier|static
name|OMPBarrierDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|///
specifier|static
name|OMPBarrierDirective
operator|*
name|CreateEmpty
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPBarrierDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp taskwait' directive.
comment|///
comment|/// \code
comment|/// #pragma omp taskwait
comment|/// \endcode
comment|///
name|class
name|OMPTaskwaitDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|OMPTaskwaitDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTaskwaitDirectiveClass
argument_list|,
argument|OMPD_taskwait
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
name|explicit
name|OMPTaskwaitDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTaskwaitDirectiveClass
argument_list|,
argument|OMPD_taskwait
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|///
specifier|static
name|OMPTaskwaitDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|///
specifier|static
name|OMPTaskwaitDirective
operator|*
name|CreateEmpty
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTaskwaitDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp flush' directive.
comment|///
comment|/// \code
comment|/// #pragma omp flush(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp flush' has 2 arguments- variables 'a'
comment|/// and 'b'.
comment|/// 'omp flush' directive does not have clauses but have an optional list of
comment|/// variables to flush. This list of variables is stored within some fake clause
comment|/// FlushClause.
name|class
name|OMPFlushDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPFlushDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPFlushDirectiveClass
argument_list|,
argument|OMPD_flush
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|0
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPFlushDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPFlushDirectiveClass
argument_list|,
argument|OMPD_flush
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|0
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses (only single OMPFlushClause clause is
comment|/// allowed).
comment|///
specifier|static
name|OMPFlushDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a NumClauses
comment|/// clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPFlushDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPFlushDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp ordered' directive.
comment|///
comment|/// \code
comment|/// #pragma omp ordered
comment|/// \endcode
comment|///
name|class
name|OMPOrderedDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|OMPOrderedDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPOrderedDirectiveClass
argument_list|,
argument|OMPD_ordered
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
name|explicit
name|OMPOrderedDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPOrderedDirectiveClass
argument_list|,
argument|OMPD_ordered
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPOrderedDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|///
specifier|static
name|OMPOrderedDirective
operator|*
name|CreateEmpty
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPOrderedDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp atomic' directive.
comment|///
comment|/// \code
comment|/// #pragma omp atomic capture
comment|/// \endcode
comment|/// In this example directive '#pragma omp atomic' has clause 'capture'.
comment|///
name|class
name|OMPAtomicDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPAtomicDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPAtomicDirectiveClass
argument_list|,
argument|OMPD_atomic
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|4
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPAtomicDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPAtomicDirectiveClass
argument_list|,
argument|OMPD_atomic
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|4
argument_list|)
block|{}
comment|/// \brief Set 'x' part of the associated expression/statement.
name|void
name|setX
argument_list|(
argument|Expr *X
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|)
operator|=
name|X
block|; }
comment|/// \brief Set 'v' part of the associated expression/statement.
name|void
name|setV
argument_list|(
argument|Expr *V
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
literal|2
argument_list|)
operator|=
name|V
block|; }
comment|/// \brief Set 'expr' part of the associated expression/statement.
name|void
name|setExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
literal|3
argument_list|)
operator|=
name|E
block|; }
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses and 'x', 'v' and 'expr'
comment|/// parts of the atomic construct (see Section 2.12.6, atomic Construct, for
comment|/// detailed description of 'x', 'v' and 'expr').
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param X 'x' part of the associated expression/statement.
comment|/// \param V 'v' part of the associated expression/statement.
comment|/// \param E 'expr' part of the associated expression/statement.
comment|///
specifier|static
name|OMPAtomicDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|,
argument|Expr *X
argument_list|,
argument|Expr *V
argument_list|,
argument|Expr *E
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a NumClauses
comment|/// clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPAtomicDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
comment|/// \brief Get 'x' part of the associated expression/statement.
name|Expr
operator|*
name|getX
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|)
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getX
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|)
operator|)
return|;
block|}
comment|/// \brief Get 'v' part of the associated expression/statement.
name|Expr
operator|*
name|getV
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
literal|2
argument_list|)
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getV
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
literal|2
argument_list|)
operator|)
return|;
block|}
comment|/// \brief Get 'expr' part of the associated expression/statement.
name|Expr
operator|*
name|getExpr
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
literal|3
argument_list|)
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getExpr
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
literal|3
argument_list|)
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPAtomicDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp target' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target if(a)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target' has clause 'if' with
comment|/// condition 'a'.
comment|///
name|class
name|OMPTargetDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTargetDirectiveClass
argument_list|,
argument|OMPD_target
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTargetDirectiveClass
argument_list|,
argument|OMPD_target
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPTargetDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a NumClauses
comment|/// clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTargetDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTargetDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp teams' directive.
comment|///
comment|/// \code
comment|/// #pragma omp teams if(a)
comment|/// \endcode
comment|/// In this example directive '#pragma omp teams' has clause 'if' with
comment|/// condition 'a'.
comment|///
name|class
name|OMPTeamsDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTeamsDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTeamsDirectiveClass
argument_list|,
argument|OMPD_teams
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTeamsDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTeamsDirectiveClass
argument_list|,
argument|OMPD_teams
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
literal|1
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPTeamsDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive with the place for \a NumClauses
comment|/// clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTeamsDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumClauses
argument_list|,
argument|EmptyShell
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTeamsDirectiveClass
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

