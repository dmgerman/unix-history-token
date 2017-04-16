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
argument|llvm::alignTo(sizeof(T), alignof(OMPClause *))
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
comment|/// This iterator visits only clauses of type SpecificClause.
name|template
operator|<
name|typename
name|SpecificClause
operator|>
name|class
name|specific_clause_iterator
operator|:
name|public
name|llvm
operator|::
name|iterator_adaptor_base
operator|<
name|specific_clause_iterator
operator|<
name|SpecificClause
operator|>
block|,
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
operator|::
name|const_iterator
block|,
name|std
operator|::
name|forward_iterator_tag
block|,
specifier|const
name|SpecificClause
operator|*
block|,
name|ptrdiff_t
block|,
specifier|const
name|SpecificClause
operator|*
block|,
specifier|const
name|SpecificClause
operator|*
operator|>
block|{
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
operator|::
name|const_iterator
name|End
block|;
name|void
name|SkipToNextClause
argument_list|()
block|{
while|while
condition|(
name|this
operator|->
name|I
operator|!=
name|End
operator|&&
operator|!
name|isa
operator|<
name|SpecificClause
operator|>
operator|(
operator|*
name|this
operator|->
name|I
operator|)
condition|)
operator|++
name|this
operator|->
name|I
expr_stmt|;
block|}
name|public
operator|:
name|explicit
name|specific_clause_iterator
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|)
operator|:
name|specific_clause_iterator
operator|::
name|iterator_adaptor_base
argument_list|(
name|Clauses
operator|.
name|begin
argument_list|()
argument_list|)
block|,
name|End
argument_list|(
argument|Clauses.end()
argument_list|)
block|{
name|SkipToNextClause
argument_list|()
block|;     }
specifier|const
name|SpecificClause
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|cast
operator|<
name|SpecificClause
operator|>
operator|(
operator|*
name|this
operator|->
name|I
operator|)
return|;
block|}
specifier|const
name|SpecificClause
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
operator|*
operator|*
name|this
return|;
block|}
name|specific_clause_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|this
operator|->
name|I
block|;
name|SkipToNextClause
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|SpecificClause
operator|>
specifier|static
name|llvm
operator|::
name|iterator_range
operator|<
name|specific_clause_iterator
operator|<
name|SpecificClause
operator|>>
name|getClausesOfKind
argument_list|(
argument|ArrayRef<OMPClause *> Clauses
argument_list|)
block|{
return|return
block|{
name|specific_clause_iterator
operator|<
name|SpecificClause
operator|>
operator|(
name|Clauses
operator|)
block|,
name|specific_clause_iterator
operator|<
name|SpecificClause
operator|>
operator|(
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|Clauses
operator|.
name|end
argument_list|()
argument_list|,
literal|0
argument_list|)
operator|)
block|}
return|;
block|}
name|template
operator|<
name|typename
name|SpecificClause
operator|>
name|llvm
operator|::
name|iterator_range
operator|<
name|specific_clause_iterator
operator|<
name|SpecificClause
operator|>>
name|getClausesOfKind
argument_list|()
specifier|const
block|{
return|return
name|getClausesOfKind
operator|<
name|SpecificClause
operator|>
operator|(
name|clauses
argument_list|()
operator|)
return|;
block|}
comment|/// Gets a single clause of the specified kind associated with the
comment|/// current directive iff there is only one clause of this kind (and assertion
comment|/// is fired if there is more than one clause is associated with the
comment|/// directive). Returns nullptr if no clause of this kind is associated with
comment|/// the directive.
name|template
operator|<
name|typename
name|SpecificClause
operator|>
specifier|const
name|SpecificClause
operator|*
name|getSingleClause
argument_list|()
specifier|const
block|{
name|auto
name|Clauses
operator|=
name|getClausesOfKind
operator|<
name|SpecificClause
operator|>
operator|(
operator|)
block|;
if|if
condition|(
name|Clauses
operator|.
name|begin
argument_list|()
operator|!=
name|Clauses
operator|.
name|end
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|std
operator|::
name|next
argument_list|(
name|Clauses
operator|.
name|begin
argument_list|()
argument_list|)
operator|==
name|Clauses
operator|.
name|end
argument_list|()
operator|&&
literal|"There are at least 2 clauses of the specified kind"
argument_list|)
expr_stmt|;
return|return
operator|*
name|Clauses
operator|.
name|begin
argument_list|()
return|;
block|}
return|return
name|nullptr
return|;
block|}
comment|/// Returns true if the current directive has one or more clauses of a
comment|/// specific kind.
name|template
operator|<
name|typename
name|SpecificClause
operator|>
name|bool
name|hasClausesOfKind
argument_list|()
specifier|const
block|{
name|auto
name|Clauses
operator|=
name|getClausesOfKind
operator|<
name|SpecificClause
operator|>
operator|(
operator|)
block|;
return|return
name|Clauses
operator|.
name|begin
argument_list|()
operator|!=
name|Clauses
operator|.
name|end
argument_list|()
return|;
block|}
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
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|StartLoc
operator|=
name|Loc
block|; }
comment|/// \brief Set ending location of directive.
comment|///
comment|/// \param Loc New ending location of directive.
comment|///
name|void
name|setLocEnd
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|EndLoc
operator|=
name|Loc
block|; }
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
operator|*
name|getClause
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
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
comment|/// \brief Returns the captured statement associated with the
comment|/// component region within the (combined) directive.
comment|//
comment|// \param RegionKind Component region kind.
name|CapturedStmt
operator|*
name|getCapturedStmt
argument_list|(
argument|OpenMPDirectiveKind RegionKind
argument_list|)
specifier|const
block|{
name|SmallVector
operator|<
name|OpenMPDirectiveKind
block|,
literal|4
operator|>
name|CaptureRegions
block|;
name|getOpenMPCaptureRegions
argument_list|(
name|CaptureRegions
argument_list|,
name|getDirectiveKind
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
name|std
operator|::
name|any_of
argument_list|(
name|CaptureRegions
operator|.
name|begin
argument_list|()
argument_list|,
name|CaptureRegions
operator|.
name|end
argument_list|()
argument_list|,
index|[
operator|=
index|]
operator|(
specifier|const
name|OpenMPDirectiveKind
name|K
operator|)
block|{
return|return
name|K
operator|==
name|RegionKind
return|;
block|}
argument_list|)
operator|&&
literal|"RegionKind not found in OpenMP CaptureRegions."
argument_list|)
block|;
name|auto
operator|*
name|CS
operator|=
name|cast
operator|<
name|CapturedStmt
operator|>
operator|(
name|getAssociatedStmt
argument_list|()
operator|)
block|;
for|for
control|(
name|auto
name|ThisCaptureRegion
range|:
name|CaptureRegions
control|)
block|{
if|if
condition|(
name|ThisCaptureRegion
operator|==
name|RegionKind
condition|)
return|return
name|CS
return|;
name|CS
operator|=
name|cast
operator|<
name|CapturedStmt
operator|>
operator|(
name|CS
operator|->
name|getCapturedStmt
argument_list|()
operator|)
expr_stmt|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Incorrect RegionKind specified for directive."
argument_list|)
expr_stmt|;
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
argument_list|(
argument|const Stmt *S
argument_list|)
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
argument_list|()
block|{
if|if
condition|(
operator|!
name|hasAssociatedStmt
argument_list|()
condition|)
return|return
name|child_range
argument_list|(
name|child_iterator
argument_list|()
argument_list|,
name|child_iterator
argument_list|()
argument_list|)
return|;
name|Stmt
operator|*
operator|*
name|ChildStorage
operator|=
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
block|;
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
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief true if the construct has inner cancel directive.
name|bool
name|HasCancel
block|;
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
name|this
argument_list|,
name|OMPParallelDirectiveClass
argument_list|,
name|OMPD_parallel
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|NumClauses
argument_list|,
literal|1
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
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
name|this
argument_list|,
name|OMPParallelDirectiveClass
argument_list|,
name|OMPD_parallel
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|NumClauses
argument_list|,
literal|1
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Set cancel state.
name|void
name|setHasCancel
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasCancel
operator|=
name|Has
block|; }
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement associated with the directive.
comment|/// \param HasCancel true if this directive has inner cancel directive.
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
argument_list|,
argument|bool HasCancel
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
comment|/// \brief Return true if current directive has inner cancel directive.
name|bool
name|hasCancel
argument_list|()
specifier|const
block|{
return|return
name|HasCancel
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
comment|/// the next 10 are specific to the worksharing ones.
comment|/// After the fixed children, three arrays of length CollapsedNum are
comment|/// allocated: loop counters, their updates and final values.
comment|/// PrevLowerBound and PrevUpperBound are used to communicate blocking
comment|/// information in composite constructs which require loop blocking
comment|/// DistInc is used to generate the increment expression for the distribute
comment|/// loop when combined with a further nested loop
comment|/// PrevEnsureUpperBound is used as the EnsureUpperBound expression for the
comment|/// for loop when combined with a previous distribute loop in the same pragma
comment|/// (e.g. 'distribute parallel for')
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
name|InitOffset
operator|=
literal|6
block|,
name|IncOffset
operator|=
literal|7
block|,
name|PreInitsOffset
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
comment|// The following 12 exprs are used by worksharing and distribute loops only.
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
name|NumIterationsOffset
operator|=
literal|16
block|,
name|PrevLowerBoundVariableOffset
operator|=
literal|17
block|,
name|PrevUpperBoundVariableOffset
operator|=
literal|18
block|,
name|DistIncOffset
operator|=
literal|19
block|,
name|PrevEnsureUpperBoundOffset
operator|=
literal|20
block|,
comment|// Offset to the end (and start of the following counters/updates/finals
comment|// arrays) for worksharing loop directives.
name|WorksharingEnd
operator|=
literal|21
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
comment|/// \brief Get the private counters storage.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getPrivateCounters
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
comment|/// \brief Get the updates storage.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getInits
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
literal|3
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
literal|4
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|Kind
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|Kind
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|Kind
argument_list|)
operator|)
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
literal|5
operator|*
name|CollapsedNum
return|;
comment|// Counters,
comment|// PrivateCounters, Inits,
comment|// Updates and Finals
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
name|setPreInits
argument_list|(
argument|Stmt *PreInits
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
name|PreInitsOffset
argument_list|)
operator|=
name|PreInits
block|;   }
name|void
name|setIsLastIterVariable
argument_list|(
argument|Expr *IL
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|setNumIterations
argument_list|(
argument|Expr *NI
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|NumIterationsOffset
argument_list|)
operator|=
name|NI
block|;   }
name|void
name|setPrevLowerBoundVariable
argument_list|(
argument|Expr *PrevLB
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|PrevLowerBoundVariableOffset
argument_list|)
operator|=
name|PrevLB
block|;   }
name|void
name|setPrevUpperBoundVariable
argument_list|(
argument|Expr *PrevUB
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|PrevUpperBoundVariableOffset
argument_list|)
operator|=
name|PrevUB
block|;   }
name|void
name|setDistInc
argument_list|(
argument|Expr *DistInc
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|DistIncOffset
argument_list|)
operator|=
name|DistInc
block|;   }
name|void
name|setPrevEnsureUpperBound
argument_list|(
argument|Expr *PrevEUB
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|PrevEnsureUpperBoundOffset
argument_list|)
operator|=
name|PrevEUB
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
name|setPrivateCounters
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
name|setInits
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
comment|/// \brief Loop number of iterations.
name|Expr
operator|*
name|NumIterations
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
comment|/// \brief EnsureUpperBound -- expression UB = min(UB, NumIterations).
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
comment|/// \brief PreviousLowerBound - local variable passed to runtime in the
comment|/// enclosing schedule or null if that does not apply.
name|Expr
operator|*
name|PrevLB
block|;
comment|/// \brief PreviousUpperBound - local variable passed to runtime in the
comment|/// enclosing schedule or null if that does not apply.
name|Expr
operator|*
name|PrevUB
block|;
comment|/// \brief DistInc - increment expression for distribute loop when found
comment|/// combined with a further loop level (e.g. in 'distribute parallel for')
comment|/// expression IV = IV + ST
name|Expr
operator|*
name|DistInc
block|;
comment|/// \brief PrevEUB - expression similar to EUB but to be used when loop
comment|/// scheduling uses PrevLB and PrevUB (e.g.  in 'distribute parallel for'
comment|/// when ensuring that the UB is either the calculated UB by the runtime or
comment|/// the end of the assigned distribute chunk)
comment|/// expression UB = min (UB, PrevUB)
name|Expr
operator|*
name|PrevEUB
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
comment|/// \brief PrivateCounters Loop counters.
name|SmallVector
operator|<
name|Expr
operator|*
block|,
literal|4
operator|>
name|PrivateCounters
block|;
comment|/// \brief Expressions for loop counters inits for CodeGen.
name|SmallVector
operator|<
name|Expr
operator|*
block|,
literal|4
operator|>
name|Inits
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
comment|/// Init statement for all captured expressions.
name|Stmt
operator|*
name|PreInits
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
name|NumIterations
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
name|NumIterations
operator|=
name|nullptr
block|;
name|PrevLB
operator|=
name|nullptr
block|;
name|PrevUB
operator|=
name|nullptr
block|;
name|DistInc
operator|=
name|nullptr
block|;
name|PrevEUB
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
name|PrivateCounters
operator|.
name|resize
argument_list|(
name|Size
argument_list|)
block|;
name|Inits
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
name|PrivateCounters
index|[
name|i
index|]
operator|=
name|nullptr
expr_stmt|;
name|Inits
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
name|PreInits
operator|=
name|nullptr
expr_stmt|;
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
name|CondOffset
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
specifier|const
name|Stmt
operator|*
name|getPreInits
argument_list|()
specifier|const
block|{
return|return
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|PreInitsOffset
argument_list|)
return|;
block|}
name|Stmt
operator|*
name|getPreInits
argument_list|()
block|{
return|return
operator|*
name|std
operator|::
name|next
argument_list|(
name|child_begin
argument_list|()
argument_list|,
name|PreInitsOffset
argument_list|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|Expr
operator|*
name|getNumIterations
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|NumIterationsOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getPrevLowerBoundVariable
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|PrevLowerBoundVariableOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getPrevUpperBoundVariable
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|PrevUpperBoundVariableOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getDistInc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|DistIncOffset
argument_list|)
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getPrevEnsureUpperBound
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isOpenMPWorksharingDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPTaskLoopDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|||
name|isOpenMPDistributeDirective
argument_list|(
name|getDirectiveKind
argument_list|()
argument_list|)
operator|)
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
name|PrevEnsureUpperBoundOffset
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
name|private_counters
argument_list|()
block|{
return|return
name|getPrivateCounters
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|private_counters
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
name|getPrivateCounters
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|inits
argument_list|()
block|{
return|return
name|getInits
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|inits
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
name|getInits
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
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTaskLoopDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTaskLoopSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPDistributeDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTargetParallelForDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPDistributeParallelForDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPDistributeParallelForSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPDistributeSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTargetParallelForSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTargetSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTeamsDistributeDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTeamsDistributeSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTeamsDistributeParallelForSimdDirectiveClass
operator|||
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|OMPTeamsDistributeParallelForDirectiveClass
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
comment|/// \brief true if current directive has inner cancel directive.
name|bool
name|HasCancel
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
name|this
argument_list|,
name|OMPForDirectiveClass
argument_list|,
name|OMPD_for
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|CollapsedNum
argument_list|,
name|NumClauses
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
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
name|this
argument_list|,
name|OMPForDirectiveClass
argument_list|,
name|OMPD_for
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|CollapsedNum
argument_list|,
name|NumClauses
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Set cancel state.
name|void
name|setHasCancel
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasCancel
operator|=
name|Has
block|; }
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
comment|/// \param HasCancel true if current directive has inner cancel directive.
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
argument_list|,
argument|bool HasCancel
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
comment|/// \brief Return true if current directive has inner cancel directive.
name|bool
name|hasCancel
argument_list|()
specifier|const
block|{
return|return
name|HasCancel
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
comment|/// \brief true if current directive has inner cancel directive.
name|bool
name|HasCancel
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
name|this
argument_list|,
name|OMPSectionsDirectiveClass
argument_list|,
name|OMPD_sections
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|NumClauses
argument_list|,
literal|1
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
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
name|this
argument_list|,
name|OMPSectionsDirectiveClass
argument_list|,
name|OMPD_sections
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|NumClauses
argument_list|,
literal|1
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Set cancel state.
name|void
name|setHasCancel
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasCancel
operator|=
name|Has
block|; }
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param HasCancel true if current directive has inner directive.
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
argument_list|,
argument|bool HasCancel
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
comment|/// \brief Return true if current directive has inner cancel directive.
name|bool
name|hasCancel
argument_list|()
specifier|const
block|{
return|return
name|HasCancel
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
comment|/// \brief true if current directive has inner cancel directive.
name|bool
name|HasCancel
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
name|this
argument_list|,
name|OMPSectionDirectiveClass
argument_list|,
name|OMPD_section
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
name|HasCancel
argument_list|(
argument|false
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
name|this
argument_list|,
name|OMPSectionDirectiveClass
argument_list|,
name|OMPD_section
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
name|HasCancel
argument_list|(
argument|false
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
comment|/// \param HasCancel true if current directive has inner directive.
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
argument_list|,
argument|bool HasCancel
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
comment|/// \brief Set cancel state.
name|void
name|setHasCancel
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasCancel
operator|=
name|Has
block|; }
comment|/// \brief Return true if current directive has inner cancel directive.
name|bool
name|hasCancel
argument_list|()
specifier|const
block|{
return|return
name|HasCancel
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
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPCriticalDirective
argument_list|(
argument|const DeclarationNameInfo&Name
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumClauses
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
name|NumClauses
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
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPCriticalDirective
argument_list|(
argument|unsigned NumClauses
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
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|NumClauses
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
comment|/// \param Clauses List of clauses.
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
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPCriticalDirective
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
comment|/// \brief true if current region has inner cancel directive.
name|bool
name|HasCancel
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
name|this
argument_list|,
name|OMPParallelForDirectiveClass
argument_list|,
name|OMPD_parallel_for
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|CollapsedNum
argument_list|,
name|NumClauses
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
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
name|this
argument_list|,
name|OMPParallelForDirectiveClass
argument_list|,
name|OMPD_parallel_for
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|CollapsedNum
argument_list|,
name|NumClauses
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Set cancel state.
name|void
name|setHasCancel
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasCancel
operator|=
name|Has
block|; }
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
comment|/// \param HasCancel true if current directive has inner cancel directive.
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
argument_list|,
argument|bool HasCancel
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
comment|/// \brief Return true if current directive has inner cancel directive.
name|bool
name|hasCancel
argument_list|()
specifier|const
block|{
return|return
name|HasCancel
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
comment|/// \brief true if current directive has inner cancel directive.
name|bool
name|HasCancel
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
name|this
argument_list|,
name|OMPParallelSectionsDirectiveClass
argument_list|,
name|OMPD_parallel_sections
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|NumClauses
argument_list|,
literal|1
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
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
name|this
argument_list|,
name|OMPParallelSectionsDirectiveClass
argument_list|,
name|OMPD_parallel_sections
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|NumClauses
argument_list|,
literal|1
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Set cancel state.
name|void
name|setHasCancel
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasCancel
operator|=
name|Has
block|; }
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param HasCancel true if current directive has inner cancel directive.
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
argument_list|,
argument|bool HasCancel
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
comment|/// \brief Return true if current directive has inner cancel directive.
name|bool
name|hasCancel
argument_list|()
specifier|const
block|{
return|return
name|HasCancel
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
comment|/// \brief true if this directive has inner cancel directive.
name|bool
name|HasCancel
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
name|this
argument_list|,
name|OMPTaskDirectiveClass
argument_list|,
name|OMPD_task
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|NumClauses
argument_list|,
literal|1
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
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
name|this
argument_list|,
name|OMPTaskDirectiveClass
argument_list|,
name|OMPD_task
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|NumClauses
argument_list|,
literal|1
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Set cancel state.
name|void
name|setHasCancel
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasCancel
operator|=
name|Has
block|; }
name|public
operator|:
comment|/// \brief Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|/// \param HasCancel true, if current directive has inner cancel directive.
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
argument_list|,
argument|bool HasCancel
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
comment|/// \brief Return true if current directive has inner cancel directive.
name|bool
name|hasCancel
argument_list|()
specifier|const
block|{
return|return
name|HasCancel
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
comment|/// \brief This represents '#pragma omp taskgroup' directive.
comment|///
comment|/// \code
comment|/// #pragma omp taskgroup
comment|/// \endcode
comment|///
name|class
name|OMPTaskgroupDirective
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
name|OMPTaskgroupDirective
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
argument|OMPTaskgroupDirectiveClass
argument_list|,
argument|OMPD_taskgroup
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
name|OMPTaskgroupDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTaskgroupDirectiveClass
argument_list|,
argument|OMPD_taskgroup
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
name|OMPTaskgroupDirective
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
name|OMPTaskgroupDirective
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
name|OMPTaskgroupDirectiveClass
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
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPOrderedDirective
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
argument|OMPOrderedDirectiveClass
argument_list|,
argument|OMPD_ordered
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
name|OMPOrderedDirective
argument_list|(
argument|unsigned NumClauses
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
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
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
argument|ArrayRef<OMPClause *> Clauses
argument_list|,
argument|Stmt *AssociatedStmt
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPOrderedDirective
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
comment|/// \brief Used for 'atomic update' or 'atomic capture' constructs. They may
comment|/// have atomic expressions of forms
comment|/// \code
comment|/// x = x binop expr;
comment|/// x = expr binop x;
comment|/// \endcode
comment|/// This field is true for the first form of the expression and false for the
comment|/// second. Required for correct codegen of non-associative operations (like
comment|///<< or>>).
name|bool
name|IsXLHSInRHSPart
block|;
comment|/// \brief Used for 'atomic update' or 'atomic capture' constructs. They may
comment|/// have atomic expressions of forms
comment|/// \code
comment|/// v = x;<update x>;
comment|///<update x>; v = x;
comment|/// \endcode
comment|/// This field is true for the first(postfix) form of the expression and false
comment|/// otherwise.
name|bool
name|IsPostfixUpdate
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
name|this
argument_list|,
name|OMPAtomicDirectiveClass
argument_list|,
name|OMPD_atomic
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|NumClauses
argument_list|,
literal|5
argument_list|)
block|,
name|IsXLHSInRHSPart
argument_list|(
name|false
argument_list|)
block|,
name|IsPostfixUpdate
argument_list|(
argument|false
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
name|this
argument_list|,
name|OMPAtomicDirectiveClass
argument_list|,
name|OMPD_atomic
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|NumClauses
argument_list|,
literal|5
argument_list|)
block|,
name|IsXLHSInRHSPart
argument_list|(
name|false
argument_list|)
block|,
name|IsPostfixUpdate
argument_list|(
argument|false
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
comment|/// \brief Set helper expression of the form
comment|/// 'OpaqueValueExpr(x) binop OpaqueValueExpr(expr)' or
comment|/// 'OpaqueValueExpr(expr) binop OpaqueValueExpr(x)'.
name|void
name|setUpdateExpr
argument_list|(
argument|Expr *UE
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
name|UE
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
literal|3
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
literal|4
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
comment|/// \param UE Helper expression of the form
comment|/// 'OpaqueValueExpr(x) binop OpaqueValueExpr(expr)' or
comment|/// 'OpaqueValueExpr(expr) binop OpaqueValueExpr(x)'.
comment|/// \param IsXLHSInRHSPart true if \a UE has the first form and false if the
comment|/// second.
comment|/// \param IsPostfixUpdate true if original value of 'x' must be stored in
comment|/// 'v', not an updated one.
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
argument_list|,
argument|Expr *UE
argument_list|,
argument|bool IsXLHSInRHSPart
argument_list|,
argument|bool IsPostfixUpdate
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
comment|/// \brief Get helper expression of the form
comment|/// 'OpaqueValueExpr(x) binop OpaqueValueExpr(expr)' or
comment|/// 'OpaqueValueExpr(expr) binop OpaqueValueExpr(x)'.
name|Expr
operator|*
name|getUpdateExpr
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
name|getUpdateExpr
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
comment|/// \brief Return true if helper update expression has form
comment|/// 'OpaqueValueExpr(x) binop OpaqueValueExpr(expr)' and false if it has form
comment|/// 'OpaqueValueExpr(expr) binop OpaqueValueExpr(x)'.
name|bool
name|isXLHSInRHSPart
argument_list|()
specifier|const
block|{
return|return
name|IsXLHSInRHSPart
return|;
block|}
comment|/// \brief Return true if 'v' expression must be updated to original value of
comment|/// 'x', false if 'v' must be updated to the new value of 'x'.
name|bool
name|isPostfixUpdate
argument_list|()
specifier|const
block|{
return|return
name|IsPostfixUpdate
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
literal|3
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
literal|3
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
literal|4
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
literal|4
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
comment|/// \brief This represents '#pragma omp target data' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target data device(0) if(a) map(b[:])
comment|/// \endcode
comment|/// In this example directive '#pragma omp target data' has clauses 'device'
comment|/// with the value '0', 'if' with condition 'a' and 'map' with array
comment|/// section 'b[:]'.
comment|///
name|class
name|OMPTargetDataDirective
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
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param NumClauses The number of clauses.
comment|///
name|OMPTargetDataDirective
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
argument|OMPTargetDataDirectiveClass
argument_list|,
argument|OMPD_target_data
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
name|OMPTargetDataDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTargetDataDirectiveClass
argument_list|,
argument|OMPD_target_data
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
name|OMPTargetDataDirective
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
comment|/// \param N The number of clauses.
comment|///
specifier|static
name|OMPTargetDataDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
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
name|OMPTargetDataDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp target enter data' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target enter data device(0) if(a) map(b[:])
comment|/// \endcode
comment|/// In this example directive '#pragma omp target enter data' has clauses
comment|/// 'device' with the value '0', 'if' with condition 'a' and 'map' with array
comment|/// section 'b[:]'.
comment|///
name|class
name|OMPTargetEnterDataDirective
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
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param NumClauses The number of clauses.
comment|///
name|OMPTargetEnterDataDirective
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
argument|OMPTargetEnterDataDirectiveClass
argument_list|,
argument|OMPD_target_enter_data
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
comment|/*NumChildren=*/
literal|0
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetEnterDataDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTargetEnterDataDirectiveClass
argument_list|,
argument|OMPD_target_enter_data
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
comment|/*NumChildren=*/
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
comment|/// \param Clauses List of clauses.
comment|///
specifier|static
name|OMPTargetEnterDataDirective
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
comment|/// \brief Creates an empty directive with the place for \a N clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of clauses.
comment|///
specifier|static
name|OMPTargetEnterDataDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
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
name|OMPTargetEnterDataDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp target exit data' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target exit data device(0) if(a) map(b[:])
comment|/// \endcode
comment|/// In this example directive '#pragma omp target exit data' has clauses
comment|/// 'device' with the value '0', 'if' with condition 'a' and 'map' with array
comment|/// section 'b[:]'.
comment|///
name|class
name|OMPTargetExitDataDirective
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
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param NumClauses The number of clauses.
comment|///
name|OMPTargetExitDataDirective
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
argument|OMPTargetExitDataDirectiveClass
argument_list|,
argument|OMPD_target_exit_data
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
comment|/*NumChildren=*/
literal|0
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetExitDataDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTargetExitDataDirectiveClass
argument_list|,
argument|OMPD_target_exit_data
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
comment|/*NumChildren=*/
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
comment|/// \param Clauses List of clauses.
comment|///
specifier|static
name|OMPTargetExitDataDirective
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
comment|/// \brief Creates an empty directive with the place for \a N clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of clauses.
comment|///
specifier|static
name|OMPTargetExitDataDirective
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
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
name|OMPTargetExitDataDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp target parallel' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target parallel if(a)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target parallel' has clause 'if' with
comment|/// condition 'a'.
comment|///
name|class
name|OMPTargetParallelDirective
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
name|OMPTargetParallelDirective
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
argument|OMPTargetParallelDirectiveClass
argument_list|,
argument|OMPD_target_parallel
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|,
argument|NumClauses
argument_list|,
comment|/*NumChildren=*/
literal|1
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetParallelDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTargetParallelDirectiveClass
argument_list|,
argument|OMPD_target_parallel
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|,
argument|NumClauses
argument_list|,
comment|/*NumChildren=*/
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
name|OMPTargetParallelDirective
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
name|OMPTargetParallelDirective
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
name|OMPTargetParallelDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp target parallel for' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target parallel for private(a,b) reduction(+:c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target parallel for' has clauses
comment|/// 'private' with the variables 'a' and 'b' and 'reduction' with operator '+'
comment|/// and variables 'c' and 'd'.
comment|///
name|class
name|OMPTargetParallelForDirective
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// \brief true if current region has inner cancel directive.
name|bool
name|HasCancel
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetParallelForDirective
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
name|this
argument_list|,
name|OMPTargetParallelForDirectiveClass
argument_list|,
name|OMPD_target_parallel_for
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|CollapsedNum
argument_list|,
name|NumClauses
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetParallelForDirective
argument_list|(
argument|unsigned CollapsedNum
argument_list|,
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPLoopDirective
argument_list|(
name|this
argument_list|,
name|OMPTargetParallelForDirectiveClass
argument_list|,
name|OMPD_target_parallel_for
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|CollapsedNum
argument_list|,
name|NumClauses
argument_list|)
block|,
name|HasCancel
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Set cancel state.
name|void
name|setHasCancel
argument_list|(
argument|bool Has
argument_list|)
block|{
name|HasCancel
operator|=
name|Has
block|; }
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
comment|/// \param HasCancel true if current directive has inner cancel directive.
comment|///
specifier|static
name|OMPTargetParallelForDirective
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
argument_list|,
argument|bool HasCancel
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
name|OMPTargetParallelForDirective
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
comment|/// \brief Return true if current directive has inner cancel directive.
name|bool
name|hasCancel
argument_list|()
specifier|const
block|{
return|return
name|HasCancel
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
name|OMPTargetParallelForDirectiveClass
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
block|;
comment|/// \brief This represents '#pragma omp cancellation point' directive.
comment|///
comment|/// \code
comment|/// #pragma omp cancellation point for
comment|/// \endcode
comment|///
comment|/// In this example a cancellation point is created for innermost 'for' region.
name|class
name|OMPCancellationPointDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
name|OpenMPDirectiveKind
name|CancelRegion
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|///
name|OMPCancellationPointDirective
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
name|this
argument_list|,
name|OMPCancellationPointDirectiveClass
argument_list|,
name|OMPD_cancellation_point
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|CancelRegion
argument_list|(
argument|OMPD_unknown
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
name|explicit
name|OMPCancellationPointDirective
argument_list|()
operator|:
name|OMPExecutableDirective
argument_list|(
name|this
argument_list|,
name|OMPCancellationPointDirectiveClass
argument_list|,
name|OMPD_cancellation_point
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|CancelRegion
argument_list|(
argument|OMPD_unknown
argument_list|)
block|{}
comment|/// \brief Set cancel region for current cancellation point.
comment|/// \param CR Cancellation region.
name|void
name|setCancelRegion
argument_list|(
argument|OpenMPDirectiveKind CR
argument_list|)
block|{
name|CancelRegion
operator|=
name|CR
block|; }
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|///
specifier|static
name|OMPCancellationPointDirective
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|OpenMPDirectiveKind CancelRegion
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|///
specifier|static
name|OMPCancellationPointDirective
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
comment|/// \brief Get cancellation region for the current cancellation point.
name|OpenMPDirectiveKind
name|getCancelRegion
argument_list|()
specifier|const
block|{
return|return
name|CancelRegion
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
name|OMPCancellationPointDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp cancel' directive.
comment|///
comment|/// \code
comment|/// #pragma omp cancel for
comment|/// \endcode
comment|///
comment|/// In this example a cancel is created for innermost 'for' region.
name|class
name|OMPCancelDirective
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
name|OpenMPDirectiveKind
name|CancelRegion
block|;
comment|/// \brief Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPCancelDirective
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
name|this
argument_list|,
name|OMPCancelDirectiveClass
argument_list|,
name|OMPD_cancel
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|,
name|NumClauses
argument_list|,
literal|0
argument_list|)
block|,
name|CancelRegion
argument_list|(
argument|OMPD_unknown
argument_list|)
block|{}
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
name|explicit
name|OMPCancelDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
name|this
argument_list|,
name|OMPCancelDirectiveClass
argument_list|,
name|OMPD_cancel
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|NumClauses
argument_list|,
literal|0
argument_list|)
block|,
name|CancelRegion
argument_list|(
argument|OMPD_unknown
argument_list|)
block|{}
comment|/// \brief Set cancel region for current cancellation point.
comment|/// \param CR Cancellation region.
name|void
name|setCancelRegion
argument_list|(
argument|OpenMPDirectiveKind CR
argument_list|)
block|{
name|CancelRegion
operator|=
name|CR
block|; }
name|public
operator|:
comment|/// \brief Creates directive.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|///
specifier|static
name|OMPCancelDirective
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
argument|OpenMPDirectiveKind CancelRegion
argument_list|)
block|;
comment|/// \brief Creates an empty directive.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPCancelDirective
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
comment|/// \brief Get cancellation region for the current cancellation point.
name|OpenMPDirectiveKind
name|getCancelRegion
argument_list|()
specifier|const
block|{
return|return
name|CancelRegion
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
name|OMPCancelDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp taskloop' directive.
comment|///
comment|/// \code
comment|/// #pragma omp taskloop private(a,b) grainsize(val) num_tasks(num)
comment|/// \endcode
comment|/// In this example directive '#pragma omp taskloop' has clauses 'private'
comment|/// with the variables 'a' and 'b', 'grainsize' with expression 'val' and
comment|/// 'num_tasks' with expression 'num'.
comment|///
name|class
name|OMPTaskLoopDirective
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
name|OMPTaskLoopDirective
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
argument|OMPTaskLoopDirectiveClass
argument_list|,
argument|OMPD_taskloop
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
name|OMPTaskLoopDirective
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
argument|OMPTaskLoopDirectiveClass
argument_list|,
argument|OMPD_taskloop
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
name|OMPTaskLoopDirective
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
name|OMPTaskLoopDirective
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
name|OMPTaskLoopDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp taskloop simd' directive.
comment|///
comment|/// \code
comment|/// #pragma omp taskloop simd private(a,b) grainsize(val) num_tasks(num)
comment|/// \endcode
comment|/// In this example directive '#pragma omp taskloop simd' has clauses 'private'
comment|/// with the variables 'a' and 'b', 'grainsize' with expression 'val' and
comment|/// 'num_tasks' with expression 'num'.
comment|///
name|class
name|OMPTaskLoopSimdDirective
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
name|OMPTaskLoopSimdDirective
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
argument|OMPTaskLoopSimdDirectiveClass
argument_list|,
argument|OMPD_taskloop_simd
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
name|OMPTaskLoopSimdDirective
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
argument|OMPTaskLoopSimdDirectiveClass
argument_list|,
argument|OMPD_taskloop_simd
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
name|OMPTaskLoopSimdDirective
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
name|OMPTaskLoopSimdDirective
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
name|OMPTaskLoopSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp distribute' directive.
comment|///
comment|/// \code
comment|/// #pragma omp distribute private(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp distribute' has clauses 'private'
comment|/// with the variables 'a' and 'b'
comment|///
name|class
name|OMPDistributeDirective
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
name|OMPDistributeDirective
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
argument|OMPDistributeDirectiveClass
argument_list|,
argument|OMPD_distribute
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
name|OMPDistributeDirective
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
argument|OMPDistributeDirectiveClass
argument_list|,
argument|OMPD_distribute
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
name|OMPDistributeDirective
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
name|OMPDistributeDirective
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
name|OMPDistributeDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp target update' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target update to(a) from(b) device(1)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target update' has clause 'to' with
comment|/// argument 'a', clause 'from' with argument 'b' and clause 'device' with
comment|/// argument '1'.
comment|///
name|class
name|OMPTargetUpdateDirective
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
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param NumClauses The number of clauses.
comment|///
name|OMPTargetUpdateDirective
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
argument|OMPTargetUpdateDirectiveClass
argument_list|,
argument|OMPD_target_update
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
name|OMPTargetUpdateDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTargetUpdateDirectiveClass
argument_list|,
argument|OMPD_target_update
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
comment|/// \param Clauses List of clauses.
comment|///
specifier|static
name|OMPTargetUpdateDirective
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
comment|/// \param NumClauses The number of clauses.
comment|///
specifier|static
name|OMPTargetUpdateDirective
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
name|OMPTargetUpdateDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp distribute parallel for' composite
comment|///  directive.
comment|///
comment|/// \code
comment|/// #pragma omp distribute parallel for private(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp distribute parallel for' has clause
comment|/// 'private' with the variables 'a' and 'b'
comment|///
name|class
name|OMPDistributeParallelForDirective
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
name|OMPDistributeParallelForDirective
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
argument|OMPDistributeParallelForDirectiveClass
argument_list|,
argument|OMPD_distribute_parallel_for
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
name|OMPDistributeParallelForDirective
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
argument|OMPDistributeParallelForDirectiveClass
argument_list|,
argument|OMPD_distribute_parallel_for
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
name|OMPDistributeParallelForDirective
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
name|OMPDistributeParallelForDirective
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
name|OMPDistributeParallelForDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp distribute parallel for simd' composite
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp distribute parallel for simd private(x)
comment|/// \endcode
comment|/// In this example directive '#pragma omp distribute parallel for simd' has
comment|/// clause 'private' with the variables 'x'
comment|///
name|class
name|OMPDistributeParallelForSimdDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPDistributeParallelForSimdDirective
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
argument|OMPDistributeParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_distribute_parallel_for_simd
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPDistributeParallelForSimdDirective
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
argument|OMPDistributeParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_distribute_parallel_for_simd
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPDistributeParallelForSimdDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPDistributeParallelForSimdDirective
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
name|OMPDistributeParallelForSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp distribute simd' composite directive.
comment|///
comment|/// \code
comment|/// #pragma omp distribute simd private(x)
comment|/// \endcode
comment|/// In this example directive '#pragma omp distribute simd' has clause
comment|/// 'private' with the variables 'x'
comment|///
name|class
name|OMPDistributeSimdDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPDistributeSimdDirective
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
argument|OMPDistributeSimdDirectiveClass
argument_list|,
argument|OMPD_distribute_simd
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPDistributeSimdDirective
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
argument|OMPDistributeSimdDirectiveClass
argument_list|,
argument|OMPD_distribute_simd
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPDistributeSimdDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPDistributeSimdDirective
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
name|OMPDistributeSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp target parallel for simd' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target parallel for simd private(a) map(b) safelen(c)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target parallel for simd' has clauses
comment|/// 'private' with the variable 'a', 'map' with the variable 'b' and 'safelen'
comment|/// with the variable 'c'.
comment|///
name|class
name|OMPTargetParallelForSimdDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetParallelForSimdDirective
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
argument|OMPTargetParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_target_parallel_for_simd
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetParallelForSimdDirective
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
argument|OMPTargetParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_target_parallel_for_simd
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTargetParallelForSimdDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTargetParallelForSimdDirective
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
name|OMPTargetParallelForSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp target simd' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target simd private(a) map(b) safelen(c)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target simd' has clauses 'private'
comment|/// with the variable 'a', 'map' with the variable 'b' and 'safelen' with
comment|/// the variable 'c'.
comment|///
name|class
name|OMPTargetSimdDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetSimdDirective
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
argument|OMPTargetSimdDirectiveClass
argument_list|,
argument|OMPD_target_simd
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetSimdDirective
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
argument|OMPTargetSimdDirectiveClass
argument_list|,
argument|OMPD_target_simd
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTargetSimdDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTargetSimdDirective
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
name|OMPTargetSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp teams distribute' directive.
comment|///
comment|/// \code
comment|/// #pragma omp teams distribute private(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp teams distribute' has clauses
comment|/// 'private' with the variables 'a' and 'b'
comment|///
name|class
name|OMPTeamsDistributeDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTeamsDistributeDirective
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
argument|OMPTeamsDistributeDirectiveClass
argument_list|,
argument|OMPD_teams_distribute
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTeamsDistributeDirective
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
argument|OMPTeamsDistributeDirectiveClass
argument_list|,
argument|OMPD_teams_distribute
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTeamsDistributeDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTeamsDistributeDirective
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
name|OMPTeamsDistributeDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp teams distribute simd'
comment|/// combined directive.
comment|///
comment|/// \code
comment|/// #pragma omp teams distribute simd private(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp teams distribute simd'
comment|/// has clause 'private' with the variables 'a' and 'b'
comment|///
name|class
name|OMPTeamsDistributeSimdDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTeamsDistributeSimdDirective
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
argument|OMPTeamsDistributeSimdDirectiveClass
argument_list|,
argument|OMPD_teams_distribute_simd
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTeamsDistributeSimdDirective
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
argument|OMPTeamsDistributeSimdDirectiveClass
argument_list|,
argument|OMPD_teams_distribute_simd
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTeamsDistributeSimdDirective
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
comment|/// Creates an empty directive with the place
comment|/// for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTeamsDistributeSimdDirective
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
name|OMPTeamsDistributeSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp teams distribute parallel for simd' composite
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp teams distribute parallel for simd private(x)
comment|/// \endcode
comment|/// In this example directive '#pragma omp teams distribute parallel for simd'
comment|/// has clause 'private' with the variables 'x'
comment|///
name|class
name|OMPTeamsDistributeParallelForSimdDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTeamsDistributeParallelForSimdDirective
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
argument|OMPTeamsDistributeParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_teams_distribute_parallel_for_simd
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTeamsDistributeParallelForSimdDirective
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
argument|OMPTeamsDistributeParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_teams_distribute_parallel_for_simd
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTeamsDistributeParallelForSimdDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTeamsDistributeParallelForSimdDirective
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
name|OMPTeamsDistributeParallelForSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp teams distribute parallel for' composite
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp teams distribute parallel for private(x)
comment|/// \endcode
comment|/// In this example directive '#pragma omp teams distribute parallel for'
comment|/// has clause 'private' with the variables 'x'
comment|///
name|class
name|OMPTeamsDistributeParallelForDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTeamsDistributeParallelForDirective
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
argument|OMPTeamsDistributeParallelForDirectiveClass
argument_list|,
argument|OMPD_teams_distribute_parallel_for
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTeamsDistributeParallelForDirective
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
argument|OMPTeamsDistributeParallelForDirectiveClass
argument_list|,
argument|OMPD_teams_distribute_parallel_for
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTeamsDistributeParallelForDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTeamsDistributeParallelForDirective
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
name|OMPTeamsDistributeParallelForDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp target teams' directive.
comment|///
comment|/// \code
comment|/// #pragma omp target teams if(a>0)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target teams' has clause 'if' with
comment|/// condition 'a>0'.
comment|///
name|class
name|OMPTargetTeamsDirective
name|final
operator|:
name|public
name|OMPExecutableDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetTeamsDirective
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
argument|OMPTargetTeamsDirectiveClass
argument_list|,
argument|OMPD_target_teams
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
comment|/// Build an empty directive.
comment|///
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetTeamsDirective
argument_list|(
argument|unsigned NumClauses
argument_list|)
operator|:
name|OMPExecutableDirective
argument_list|(
argument|this
argument_list|,
argument|OMPTargetTeamsDirectiveClass
argument_list|,
argument|OMPD_target_teams
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
comment|/// Creates directive with a list of \a Clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending Location of the directive.
comment|/// \param Clauses List of clauses.
comment|/// \param AssociatedStmt Statement, associated with the directive.
comment|///
specifier|static
name|OMPTargetTeamsDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTargetTeamsDirective
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
name|OMPTargetTeamsDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp target teams distribute' combined directive.
comment|///
comment|/// \code
comment|/// #pragma omp target teams distribute private(x)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target teams distribute' has clause
comment|/// 'private' with the variables 'x'
comment|///
name|class
name|OMPTargetTeamsDistributeDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetTeamsDistributeDirective
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
argument|OMPTargetTeamsDistributeDirectiveClass
argument_list|,
argument|OMPD_target_teams_distribute
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetTeamsDistributeDirective
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
argument|OMPTargetTeamsDistributeDirectiveClass
argument_list|,
argument|OMPD_target_teams_distribute
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTargetTeamsDistributeDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTargetTeamsDistributeDirective
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
name|OMPTargetTeamsDistributeDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp target teams distribute parallel for' combined
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp target teams distribute parallel for private(x)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target teams distribute parallel
comment|/// for' has clause 'private' with the variables 'x'
comment|///
name|class
name|OMPTargetTeamsDistributeParallelForDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetTeamsDistributeParallelForDirective
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
argument|OMPTargetTeamsDistributeParallelForDirectiveClass
argument_list|,
argument|OMPD_target_teams_distribute_parallel_for
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetTeamsDistributeParallelForDirective
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
argument|OMPTargetTeamsDistributeParallelForDirectiveClass
argument_list|,
argument|OMPD_target_teams_distribute_parallel_for
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTargetTeamsDistributeParallelForDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTargetTeamsDistributeParallelForDirective
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
name|OMPTargetTeamsDistributeParallelForDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp target teams distribute parallel for simd'
comment|/// combined directive.
comment|///
comment|/// \code
comment|/// #pragma omp target teams distribute parallel for simd private(x)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target teams distribute parallel
comment|/// for simd' has clause 'private' with the variables 'x'
comment|///
name|class
name|OMPTargetTeamsDistributeParallelForSimdDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetTeamsDistributeParallelForSimdDirective
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
argument|OMPTargetTeamsDistributeParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_target_teams_distribute_parallel_for_simd
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetTeamsDistributeParallelForSimdDirective
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
argument|OMPTargetTeamsDistributeParallelForSimdDirectiveClass
argument_list|,
argument|OMPD_target_teams_distribute_parallel_for_simd
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTargetTeamsDistributeParallelForSimdDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTargetTeamsDistributeParallelForSimdDirective
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
name|OMPTargetTeamsDistributeParallelForSimdDirectiveClass
return|;
block|}
expr|}
block|;
comment|/// This represents '#pragma omp target teams distribute simd' combined
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp target teams distribute simd private(x)
comment|/// \endcode
comment|/// In this example directive '#pragma omp target teams distribute simd'
comment|/// has clause 'private' with the variables 'x'
comment|///
name|class
name|OMPTargetTeamsDistributeSimdDirective
name|final
operator|:
name|public
name|OMPLoopDirective
block|{
name|friend
name|class
name|ASTStmtReader
block|;
comment|/// Build directive with the given start and end location.
comment|///
comment|/// \param StartLoc Starting location of the directive kind.
comment|/// \param EndLoc Ending location of the directive.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|OMPTargetTeamsDistributeSimdDirective
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
argument|OMPTargetTeamsDistributeSimdDirectiveClass
argument_list|,
argument|OMPD_target_teams_distribute_simd
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
comment|/// Build an empty directive.
comment|///
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
name|explicit
name|OMPTargetTeamsDistributeSimdDirective
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
argument|OMPTargetTeamsDistributeSimdDirectiveClass
argument_list|,
argument|OMPD_target_teams_distribute_simd
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
comment|/// Creates directive with a list of \a Clauses.
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
name|OMPTargetTeamsDistributeSimdDirective
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
comment|/// Creates an empty directive with the place for \a NumClauses clauses.
comment|///
comment|/// \param C AST context.
comment|/// \param CollapsedNum Number of collapsed nested loops.
comment|/// \param NumClauses Number of clauses.
comment|///
specifier|static
name|OMPTargetTeamsDistributeSimdDirective
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
name|OMPTargetTeamsDistributeSimdDirectiveClass
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

