begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- OpenMPClause.h - Classes for OpenMP clauses --------------*- C++ -*-===//
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
comment|/// \brief This file defines OpenMP AST classes for clauses.
end_comment

begin_comment
comment|/// There are clauses for executable directives, clauses for declarative
end_comment

begin_comment
comment|/// directives and clauses which can be used in both kinds of directives.
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
name|LLVM_CLANG_AST_OPENMPCLAUSE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_OPENMPCLAUSE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
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
comment|// AST classes for clauses.
comment|//===----------------------------------------------------------------------===//
comment|/// \brief This is a basic class for representing single OpenMP clause.
comment|///
name|class
name|OMPClause
block|{
comment|/// \brief Starting location of the clause (the clause keyword).
name|SourceLocation
name|StartLoc
decl_stmt|;
comment|/// \brief Ending location of the clause.
name|SourceLocation
name|EndLoc
decl_stmt|;
comment|/// \brief Kind of the clause.
name|OpenMPClauseKind
name|Kind
decl_stmt|;
name|protected
label|:
name|OMPClause
argument_list|(
argument|OpenMPClauseKind K
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
block|:
name|StartLoc
argument_list|(
name|StartLoc
argument_list|)
operator|,
name|EndLoc
argument_list|(
name|EndLoc
argument_list|)
operator|,
name|Kind
argument_list|(
argument|K
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Returns the starting location of the clause.
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
return|return
name|StartLoc
return|;
block|}
comment|/// \brief Returns the ending location of the clause.
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|EndLoc
return|;
block|}
comment|/// \brief Sets the starting location of the clause.
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
comment|/// \brief Sets the ending location of the clause.
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
comment|/// \brief Returns kind of OpenMP clause (private, shared, reduction, etc.).
name|OpenMPClauseKind
name|getClauseKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|bool
name|isImplicit
argument_list|()
specifier|const
block|{
return|return
name|StartLoc
operator|.
name|isInvalid
argument_list|()
return|;
block|}
name|StmtRange
name|children
parameter_list|()
function_decl|;
name|ConstStmtRange
name|children
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|OMPClause
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|children
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|OMPClause
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief This represents clauses with the list of variables like 'private',
comment|/// 'firstprivate', 'copyin', 'shared', or 'reduction' clauses in the
comment|/// '#pragma omp ...' directives.
name|template
operator|<
name|class
name|T
operator|>
name|class
name|OMPVarListClause
operator|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief Number of variables in the list.
name|unsigned
name|NumVars
block|;
name|protected
operator|:
comment|/// \brief Fetches list of variables associated with this clause.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getVarRefs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|Expr
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
name|llvm
operator|::
name|RoundUpToAlignment
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|llvm
operator|::
name|alignOf
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
argument_list|)
operator|)
operator|,
name|NumVars
operator|)
return|;
block|}
comment|/// \brief Sets the list of variables for this clause.
name|void
name|setVarRefs
argument_list|(
argument|ArrayRef<Expr *> VL
argument_list|)
block|{
name|assert
argument_list|(
name|VL
operator|.
name|size
argument_list|()
operator|==
name|NumVars
operator|&&
literal|"Number of variables is not the same as the preallocated buffer"
argument_list|)
block|;
name|std
operator|::
name|copy
argument_list|(
name|VL
operator|.
name|begin
argument_list|()
argument_list|,
name|VL
operator|.
name|end
argument_list|()
argument_list|,
name|reinterpret_cast
operator|<
name|Expr
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
name|llvm
operator|::
name|RoundUpToAlignment
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|llvm
operator|::
name|alignOf
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
argument_list|)
operator|)
argument_list|)
block|;   }
comment|/// \brief Build a clause with \a N variables
comment|///
comment|/// \param K Kind of the clause.
comment|/// \param StartLoc Starting location of the clause (the clause keyword).
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPVarListClause
argument_list|(
argument|OpenMPClauseKind K
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|K
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|NumVars
argument_list|(
argument|N
argument_list|)
block|{}
name|public
operator|:
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|varlist_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|varlist_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|varlist_iterator
operator|>
name|varlist_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|varlist_const_iterator
operator|>
name|varlist_const_range
expr_stmt|;
name|unsigned
name|varlist_size
argument_list|()
specifier|const
block|{
return|return
name|NumVars
return|;
block|}
name|bool
name|varlist_empty
argument_list|()
specifier|const
block|{
return|return
name|NumVars
operator|==
literal|0
return|;
block|}
name|varlist_range
name|varlists
parameter_list|()
block|{
return|return
name|varlist_range
argument_list|(
name|varlist_begin
argument_list|()
argument_list|,
name|varlist_end
argument_list|()
argument_list|)
return|;
block|}
name|varlist_const_range
name|varlists
argument_list|()
specifier|const
block|{
return|return
name|varlist_const_range
argument_list|(
name|varlist_begin
argument_list|()
argument_list|,
name|varlist_end
argument_list|()
argument_list|)
return|;
block|}
name|varlist_iterator
name|varlist_begin
parameter_list|()
block|{
return|return
name|getVarRefs
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|varlist_iterator
name|varlist_end
parameter_list|()
block|{
return|return
name|getVarRefs
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|varlist_const_iterator
name|varlist_begin
argument_list|()
specifier|const
block|{
return|return
name|getVarRefs
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|varlist_const_iterator
name|varlist_end
argument_list|()
specifier|const
block|{
return|return
name|getVarRefs
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Sets the location of '('.
name|void
name|setLParenLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|LParenLoc
operator|=
name|Loc
expr_stmt|;
block|}
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Fetches list of all variables in the clause.
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getVarRefs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
specifier|const
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
name|llvm
operator|::
name|RoundUpToAlignment
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|llvm
operator|::
name|alignOf
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|)
argument_list|)
operator|)
argument_list|,
name|NumVars
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief This represents 'if' clause in the '#pragma omp ...' directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// #pragma omp parallel if(a> 5)
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// In this example directive '#pragma omp parallel' has simple 'if'
end_comment

begin_comment
comment|/// clause with condition 'a> 5'.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|OMPIfClause
range|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief Condition of the 'if' clause.
name|Stmt
operator|*
name|Condition
block|;
comment|/// \brief Set condition.
comment|///
name|void
name|setCondition
argument_list|(
argument|Expr *Cond
argument_list|)
block|{
name|Condition
operator|=
name|Cond
block|; }
name|public
operator|:
comment|/// \brief Build 'if' clause with condition \a Cond.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param Cond Condition of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPIfClause
argument_list|(
argument|Expr *Cond
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|OMPC_if
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|Condition
argument_list|(
argument|Cond
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPIfClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
name|OMPC_if
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|Condition
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Sets the location of '('.
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LParenLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Returns condition.
name|Expr
operator|*
name|getCondition
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Condition
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_if
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
operator|&
name|Condition
argument_list|,
operator|&
name|Condition
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'final' clause in the '#pragma omp ...' directive.
comment|///
comment|/// \code
comment|/// #pragma omp task final(a> 5)
comment|/// \endcode
comment|/// In this example directive '#pragma omp task' has simple 'final'
comment|/// clause with condition 'a> 5'.
comment|///
name|class
name|OMPFinalClause
operator|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief Condition of the 'if' clause.
name|Stmt
operator|*
name|Condition
block|;
comment|/// \brief Set condition.
comment|///
name|void
name|setCondition
argument_list|(
argument|Expr *Cond
argument_list|)
block|{
name|Condition
operator|=
name|Cond
block|; }
name|public
operator|:
comment|/// \brief Build 'final' clause with condition \a Cond.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param Cond Condition of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPFinalClause
argument_list|(
argument|Expr *Cond
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|OMPC_final
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|Condition
argument_list|(
argument|Cond
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPFinalClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
name|OMPC_final
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|Condition
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Sets the location of '('.
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LParenLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Returns condition.
name|Expr
operator|*
name|getCondition
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Condition
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_final
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
operator|&
name|Condition
argument_list|,
operator|&
name|Condition
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'num_threads' clause in the '#pragma omp ...'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp parallel num_threads(6)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has simple 'num_threads'
comment|/// clause with number of threads '6'.
comment|///
name|class
name|OMPNumThreadsClause
operator|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief Condition of the 'num_threads' clause.
name|Stmt
operator|*
name|NumThreads
block|;
comment|/// \brief Set condition.
comment|///
name|void
name|setNumThreads
argument_list|(
argument|Expr *NThreads
argument_list|)
block|{
name|NumThreads
operator|=
name|NThreads
block|; }
name|public
operator|:
comment|/// \brief Build 'num_threads' clause with condition \a NumThreads.
comment|///
comment|/// \param NumThreads Number of threads for the construct.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPNumThreadsClause
argument_list|(
argument|Expr *NumThreads
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|OMPC_num_threads
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|NumThreads
argument_list|(
argument|NumThreads
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPNumThreadsClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
name|OMPC_num_threads
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|NumThreads
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Sets the location of '('.
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LParenLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Returns number of threads.
name|Expr
operator|*
name|getNumThreads
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|NumThreads
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_num_threads
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
operator|&
name|NumThreads
argument_list|,
operator|&
name|NumThreads
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'safelen' clause in the '#pragma omp ...'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp simd safelen(4)
comment|/// \endcode
comment|/// In this example directive '#pragma omp simd' has clause 'safelen'
comment|/// with single expression '4'.
comment|/// If the safelen clause is used then no two iterations executed
comment|/// concurrently with SIMD instructions can have a greater distance
comment|/// in the logical iteration space than its value. The parameter of
comment|/// the safelen clause must be a constant positive integer expression.
comment|///
name|class
name|OMPSafelenClause
operator|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief Safe iteration space distance.
name|Stmt
operator|*
name|Safelen
block|;
comment|/// \brief Set safelen.
name|void
name|setSafelen
argument_list|(
argument|Expr *Len
argument_list|)
block|{
name|Safelen
operator|=
name|Len
block|; }
name|public
operator|:
comment|/// \brief Build 'safelen' clause.
comment|///
comment|/// \param Len Expression associated with this clause.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPSafelenClause
argument_list|(
argument|Expr *Len
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|OMPC_safelen
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|Safelen
argument_list|(
argument|Len
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|explicit
name|OMPSafelenClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
name|OMPC_safelen
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|Safelen
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Sets the location of '('.
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LParenLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Return safe iteration space distance.
name|Expr
operator|*
name|getSafelen
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Safelen
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_safelen
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
operator|&
name|Safelen
argument_list|,
operator|&
name|Safelen
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'collapse' clause in the '#pragma omp ...'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp simd collapse(3)
comment|/// \endcode
comment|/// In this example directive '#pragma omp simd' has clause 'collapse'
comment|/// with single expression '3'.
comment|/// The parameter must be a constant positive integer expression, it specifies
comment|/// the number of nested loops that should be collapsed into a single iteration
comment|/// space.
comment|///
name|class
name|OMPCollapseClause
operator|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief Number of for-loops.
name|Stmt
operator|*
name|NumForLoops
block|;
comment|/// \brief Set the number of associated for-loops.
name|void
name|setNumForLoops
argument_list|(
argument|Expr *Num
argument_list|)
block|{
name|NumForLoops
operator|=
name|Num
block|; }
name|public
operator|:
comment|/// \brief Build 'collapse' clause.
comment|///
comment|/// \param Num Expression associated with this clause.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPCollapseClause
argument_list|(
argument|Expr *Num
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|OMPC_collapse
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|NumForLoops
argument_list|(
argument|Num
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|explicit
name|OMPCollapseClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
name|OMPC_collapse
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|NumForLoops
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Sets the location of '('.
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LParenLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Return the number of associated for-loops.
name|Expr
operator|*
name|getNumForLoops
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|NumForLoops
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_collapse
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
operator|&
name|NumForLoops
argument_list|,
operator|&
name|NumForLoops
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'default' clause in the '#pragma omp ...' directive.
comment|///
comment|/// \code
comment|/// #pragma omp parallel default(shared)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has simple 'default'
comment|/// clause with kind 'shared'.
comment|///
name|class
name|OMPDefaultClause
operator|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief A kind of the 'default' clause.
name|OpenMPDefaultClauseKind
name|Kind
block|;
comment|/// \brief Start location of the kind in source code.
name|SourceLocation
name|KindKwLoc
block|;
comment|/// \brief Set kind of the clauses.
comment|///
comment|/// \param K Argument of clause.
comment|///
name|void
name|setDefaultKind
argument_list|(
argument|OpenMPDefaultClauseKind K
argument_list|)
block|{
name|Kind
operator|=
name|K
block|; }
comment|/// \brief Set argument location.
comment|///
comment|/// \param KLoc Argument location.
comment|///
name|void
name|setDefaultKindKwLoc
argument_list|(
argument|SourceLocation KLoc
argument_list|)
block|{
name|KindKwLoc
operator|=
name|KLoc
block|; }
name|public
operator|:
comment|/// \brief Build 'default' clause with argument \a A ('none' or 'shared').
comment|///
comment|/// \param A Argument of the clause ('none' or 'shared').
comment|/// \param ALoc Starting location of the argument.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPDefaultClause
argument_list|(
argument|OpenMPDefaultClauseKind A
argument_list|,
argument|SourceLocation ALoc
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|OMPC_default
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|Kind
argument_list|(
name|A
argument_list|)
block|,
name|KindKwLoc
argument_list|(
argument|ALoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPDefaultClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
name|OMPC_default
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|Kind
argument_list|(
name|OMPC_DEFAULT_unknown
argument_list|)
block|,
name|KindKwLoc
argument_list|(
argument|SourceLocation()
argument_list|)
block|{}
comment|/// \brief Sets the location of '('.
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LParenLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Returns kind of the clause.
name|OpenMPDefaultClauseKind
name|getDefaultKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Returns location of clause kind.
name|SourceLocation
name|getDefaultKindKwLoc
argument_list|()
specifier|const
block|{
return|return
name|KindKwLoc
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_default
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'proc_bind' clause in the '#pragma omp ...'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp parallel proc_bind(master)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has simple 'proc_bind'
comment|/// clause with kind 'master'.
comment|///
name|class
name|OMPProcBindClause
operator|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief A kind of the 'proc_bind' clause.
name|OpenMPProcBindClauseKind
name|Kind
block|;
comment|/// \brief Start location of the kind in source code.
name|SourceLocation
name|KindKwLoc
block|;
comment|/// \brief Set kind of the clause.
comment|///
comment|/// \param K Kind of clause.
comment|///
name|void
name|setProcBindKind
argument_list|(
argument|OpenMPProcBindClauseKind K
argument_list|)
block|{
name|Kind
operator|=
name|K
block|; }
comment|/// \brief Set clause kind location.
comment|///
comment|/// \param KLoc Kind location.
comment|///
name|void
name|setProcBindKindKwLoc
argument_list|(
argument|SourceLocation KLoc
argument_list|)
block|{
name|KindKwLoc
operator|=
name|KLoc
block|; }
name|public
operator|:
comment|/// \brief Build 'proc_bind' clause with argument \a A ('master', 'close' or
comment|///        'spread').
comment|///
comment|/// \param A Argument of the clause ('master', 'close' or 'spread').
comment|/// \param ALoc Starting location of the argument.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPProcBindClause
argument_list|(
argument|OpenMPProcBindClauseKind A
argument_list|,
argument|SourceLocation ALoc
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|OMPC_proc_bind
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|Kind
argument_list|(
name|A
argument_list|)
block|,
name|KindKwLoc
argument_list|(
argument|ALoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPProcBindClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
name|OMPC_proc_bind
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|Kind
argument_list|(
name|OMPC_PROC_BIND_unknown
argument_list|)
block|,
name|KindKwLoc
argument_list|(
argument|SourceLocation()
argument_list|)
block|{}
comment|/// \brief Sets the location of '('.
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LParenLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Returns kind of the clause.
name|OpenMPProcBindClauseKind
name|getProcBindKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Returns location of clause kind.
name|SourceLocation
name|getProcBindKindKwLoc
argument_list|()
specifier|const
block|{
return|return
name|KindKwLoc
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_proc_bind
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'schedule' clause in the '#pragma omp ...' directive.
comment|///
comment|/// \code
comment|/// #pragma omp for schedule(static, 3)
comment|/// \endcode
comment|/// In this example directive '#pragma omp for' has 'schedule' clause with
comment|/// arguments 'static' and '3'.
comment|///
name|class
name|OMPScheduleClause
operator|:
name|public
name|OMPClause
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of '('.
name|SourceLocation
name|LParenLoc
block|;
comment|/// \brief A kind of the 'schedule' clause.
name|OpenMPScheduleClauseKind
name|Kind
block|;
comment|/// \brief Start location of the schedule ind in source code.
name|SourceLocation
name|KindLoc
block|;
comment|/// \brief Location of ',' (if any).
name|SourceLocation
name|CommaLoc
block|;
comment|/// \brief Chunk size and a reference to pseudo variable for combined
comment|/// directives.
block|enum
block|{
name|CHUNK_SIZE
block|,
name|HELPER_CHUNK_SIZE
block|,
name|NUM_EXPRS
block|}
block|;
name|Stmt
operator|*
name|ChunkSizes
index|[
name|NUM_EXPRS
index|]
block|;
comment|/// \brief Set schedule kind.
comment|///
comment|/// \param K Schedule kind.
comment|///
name|void
name|setScheduleKind
argument_list|(
argument|OpenMPScheduleClauseKind K
argument_list|)
block|{
name|Kind
operator|=
name|K
block|; }
comment|/// \brief Sets the location of '('.
comment|///
comment|/// \param Loc Location of '('.
comment|///
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|LParenLoc
operator|=
name|Loc
block|; }
comment|/// \brief Set schedule kind start location.
comment|///
comment|/// \param KLoc Schedule kind location.
comment|///
name|void
name|setScheduleKindLoc
argument_list|(
argument|SourceLocation KLoc
argument_list|)
block|{
name|KindLoc
operator|=
name|KLoc
block|; }
comment|/// \brief Set location of ','.
comment|///
comment|/// \param Loc Location of ','.
comment|///
name|void
name|setCommaLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|CommaLoc
operator|=
name|Loc
block|; }
comment|/// \brief Set chunk size.
comment|///
comment|/// \param E Chunk size.
comment|///
name|void
name|setChunkSize
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|ChunkSizes
index|[
name|CHUNK_SIZE
index|]
operator|=
name|E
block|; }
comment|/// \brief Set helper chunk size.
comment|///
comment|/// \param E Helper chunk size.
comment|///
name|void
name|setHelperChunkSize
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|ChunkSizes
index|[
name|HELPER_CHUNK_SIZE
index|]
operator|=
name|E
block|; }
name|public
operator|:
comment|/// \brief Build 'schedule' clause with schedule kind \a Kind and chunk size
comment|/// expression \a ChunkSize.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param KLoc Starting location of the argument.
comment|/// \param CommaLoc Location of ','.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param Kind Schedule kind.
comment|/// \param ChunkSize Chunk size.
comment|/// \param HelperChunkSize Helper chunk size for combined directives.
comment|///
name|OMPScheduleClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation KLoc
argument_list|,
argument|SourceLocation CommaLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|OpenMPScheduleClauseKind Kind
argument_list|,
argument|Expr *ChunkSize
argument_list|,
argument|Expr *HelperChunkSize
argument_list|)
operator|:
name|OMPClause
argument_list|(
name|OMPC_schedule
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|Kind
argument_list|(
name|Kind
argument_list|)
block|,
name|KindLoc
argument_list|(
name|KLoc
argument_list|)
block|,
name|CommaLoc
argument_list|(
argument|CommaLoc
argument_list|)
block|{
name|ChunkSizes
index|[
name|CHUNK_SIZE
index|]
operator|=
name|ChunkSize
block|;
name|ChunkSizes
index|[
name|HELPER_CHUNK_SIZE
index|]
operator|=
name|HelperChunkSize
block|;   }
comment|/// \brief Build an empty clause.
comment|///
name|explicit
name|OMPScheduleClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
name|OMPC_schedule
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|Kind
argument_list|(
argument|OMPC_SCHEDULE_unknown
argument_list|)
block|{
name|ChunkSizes
index|[
name|CHUNK_SIZE
index|]
operator|=
name|nullptr
block|;
name|ChunkSizes
index|[
name|HELPER_CHUNK_SIZE
index|]
operator|=
name|nullptr
block|;   }
comment|/// \brief Get kind of the clause.
comment|///
name|OpenMPScheduleClauseKind
name|getScheduleKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Get location of '('.
comment|///
name|SourceLocation
name|getLParenLoc
argument_list|()
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Get kind location.
comment|///
name|SourceLocation
name|getScheduleKindLoc
argument_list|()
block|{
return|return
name|KindLoc
return|;
block|}
comment|/// \brief Get location of ','.
comment|///
name|SourceLocation
name|getCommaLoc
argument_list|()
block|{
return|return
name|CommaLoc
return|;
block|}
comment|/// \brief Get chunk size.
comment|///
name|Expr
operator|*
name|getChunkSize
argument_list|()
block|{
return|return
name|dyn_cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|ChunkSizes
index|[
name|CHUNK_SIZE
index|]
operator|)
return|;
block|}
comment|/// \brief Get chunk size.
comment|///
name|Expr
operator|*
name|getChunkSize
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|ChunkSizes
index|[
name|CHUNK_SIZE
index|]
operator|)
return|;
block|}
comment|/// \brief Get helper chunk size.
comment|///
name|Expr
operator|*
name|getHelperChunkSize
argument_list|()
block|{
return|return
name|dyn_cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|ChunkSizes
index|[
name|HELPER_CHUNK_SIZE
index|]
operator|)
return|;
block|}
comment|/// \brief Get helper chunk size.
comment|///
name|Expr
operator|*
name|getHelperChunkSize
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|ChunkSizes
index|[
name|HELPER_CHUNK_SIZE
index|]
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_schedule
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
operator|&
name|ChunkSizes
index|[
name|CHUNK_SIZE
index|]
argument_list|,
operator|&
name|ChunkSizes
index|[
name|CHUNK_SIZE
index|]
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'ordered' clause in the '#pragma omp ...' directive.
comment|///
comment|/// \code
comment|/// #pragma omp for ordered
comment|/// \endcode
comment|/// In this example directive '#pragma omp for' has 'ordered' clause.
comment|///
name|class
name|OMPOrderedClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'ordered' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPOrderedClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_ordered
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPOrderedClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_ordered
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_ordered
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'nowait' clause in the '#pragma omp ...' directive.
comment|///
comment|/// \code
comment|/// #pragma omp for nowait
comment|/// \endcode
comment|/// In this example directive '#pragma omp for' has 'nowait' clause.
comment|///
name|class
name|OMPNowaitClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'nowait' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPNowaitClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_nowait
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPNowaitClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_nowait
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_nowait
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'untied' clause in the '#pragma omp ...' directive.
comment|///
comment|/// \code
comment|/// #pragma omp task untied
comment|/// \endcode
comment|/// In this example directive '#pragma omp task' has 'untied' clause.
comment|///
name|class
name|OMPUntiedClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'untied' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPUntiedClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_untied
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPUntiedClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_untied
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_untied
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'mergeable' clause in the '#pragma omp ...'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp task mergeable
comment|/// \endcode
comment|/// In this example directive '#pragma omp task' has 'mergeable' clause.
comment|///
name|class
name|OMPMergeableClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'mergeable' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPMergeableClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_mergeable
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPMergeableClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_mergeable
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_mergeable
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'read' clause in the '#pragma omp atomic' directive.
comment|///
comment|/// \code
comment|/// #pragma omp atomic read
comment|/// \endcode
comment|/// In this example directive '#pragma omp atomic' has 'read' clause.
comment|///
name|class
name|OMPReadClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'read' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPReadClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_read
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPReadClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_read
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_read
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'write' clause in the '#pragma omp atomic' directive.
comment|///
comment|/// \code
comment|/// #pragma omp atomic write
comment|/// \endcode
comment|/// In this example directive '#pragma omp atomic' has 'write' clause.
comment|///
name|class
name|OMPWriteClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'write' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPWriteClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_write
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPWriteClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_write
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_write
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'update' clause in the '#pragma omp atomic'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp atomic update
comment|/// \endcode
comment|/// In this example directive '#pragma omp atomic' has 'update' clause.
comment|///
name|class
name|OMPUpdateClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'update' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPUpdateClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_update
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPUpdateClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_update
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_update
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'capture' clause in the '#pragma omp atomic'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp atomic capture
comment|/// \endcode
comment|/// In this example directive '#pragma omp atomic' has 'capture' clause.
comment|///
name|class
name|OMPCaptureClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'capture' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPCaptureClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_capture
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPCaptureClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_capture
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_capture
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents 'seq_cst' clause in the '#pragma omp atomic'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp atomic seq_cst
comment|/// \endcode
comment|/// In this example directive '#pragma omp atomic' has 'seq_cst' clause.
comment|///
name|class
name|OMPSeqCstClause
operator|:
name|public
name|OMPClause
block|{
name|public
operator|:
comment|/// \brief Build 'seq_cst' clause.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param EndLoc Ending location of the clause.
comment|///
name|OMPSeqCstClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
operator|:
name|OMPClause
argument_list|(
argument|OMPC_seq_cst
argument_list|,
argument|StartLoc
argument_list|,
argument|EndLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
name|OMPSeqCstClause
argument_list|()
operator|:
name|OMPClause
argument_list|(
argument|OMPC_seq_cst
argument_list|,
argument|SourceLocation()
argument_list|,
argument|SourceLocation()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_seq_cst
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief This represents clause 'private' in the '#pragma omp ...' directives.
comment|///
comment|/// \code
comment|/// #pragma omp parallel private(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has clause 'private'
comment|/// with the variables 'a' and 'b'.
comment|///
name|class
name|OMPPrivateClause
operator|:
name|public
name|OMPVarListClause
operator|<
name|OMPPrivateClause
operator|>
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPPrivateClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPPrivateClause
operator|>
operator|(
name|OMPC_private
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPPrivateClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPPrivateClause
operator|>
operator|(
name|OMPC_private
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{}
comment|/// \brief Sets the list of references to private copies with initializers for
comment|/// new private variables.
comment|/// \param VL List of references.
name|void
name|setPrivateCopies
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VL
argument_list|)
block|;
comment|/// \brief Gets the list of references to private copies with initializers for
comment|/// new private variables.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getPrivateCopies
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getPrivateCopies
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|varlist_end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the variables.
comment|/// \param PrivateVL List of references to private copies with initializers.
comment|///
specifier|static
name|OMPPrivateClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|,
argument|ArrayRef<Expr *> PrivateVL
argument_list|)
block|;
comment|/// \brief Creates an empty clause with the place for \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPPrivateClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|private_copies_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|private_copies_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|private_copies_iterator
operator|>
name|private_copies_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|private_copies_const_iterator
operator|>
name|private_copies_const_range
expr_stmt|;
name|private_copies_range
name|private_copies
argument_list|()
block|{
return|return
name|private_copies_range
argument_list|(
name|getPrivateCopies
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|private_copies_const_range
name|private_copies
argument_list|()
specifier|const
block|{
return|return
name|private_copies_const_range
argument_list|(
name|getPrivateCopies
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_private
return|;
block|}
expr|}
block|;
comment|/// \brief This represents clause 'firstprivate' in the '#pragma omp ...'
comment|/// directives.
comment|///
comment|/// \code
comment|/// #pragma omp parallel firstprivate(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has clause 'firstprivate'
comment|/// with the variables 'a' and 'b'.
comment|///
name|class
name|OMPFirstprivateClause
operator|:
name|public
name|OMPVarListClause
operator|<
name|OMPFirstprivateClause
operator|>
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPFirstprivateClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPFirstprivateClause
operator|>
operator|(
name|OMPC_firstprivate
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPFirstprivateClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPFirstprivateClause
operator|>
operator|(
name|OMPC_firstprivate
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{}
comment|/// \brief Sets the list of references to private copies with initializers for
comment|/// new private variables.
comment|/// \param VL List of references.
name|void
name|setPrivateCopies
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VL
argument_list|)
block|;
comment|/// \brief Gets the list of references to private copies with initializers for
comment|/// new private variables.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getPrivateCopies
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getPrivateCopies
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|varlist_end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Sets the list of references to initializer variables for new
comment|/// private variables.
comment|/// \param VL List of references.
name|void
name|setInits
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VL
argument_list|)
block|;
comment|/// \brief Gets the list of references to initializer variables for new
comment|/// private variables.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getInits
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getInits
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the original variables.
comment|/// \param PrivateVL List of references to private copies with initializers.
comment|/// \param InitVL List of references to auto generated variables used for
comment|/// initialization of a single array element. Used if firstprivate variable is
comment|/// of array type.
comment|///
specifier|static
name|OMPFirstprivateClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|,
argument|ArrayRef<Expr *> PrivateVL
argument_list|,
argument|ArrayRef<Expr *> InitVL
argument_list|)
block|;
comment|/// \brief Creates an empty clause with the place for \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPFirstprivateClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|private_copies_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|private_copies_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|private_copies_iterator
operator|>
name|private_copies_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|private_copies_const_iterator
operator|>
name|private_copies_const_range
expr_stmt|;
name|private_copies_range
name|private_copies
argument_list|()
block|{
return|return
name|private_copies_range
argument_list|(
name|getPrivateCopies
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|private_copies_const_range
name|private_copies
argument_list|()
specifier|const
block|{
return|return
name|private_copies_const_range
argument_list|(
name|getPrivateCopies
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|inits_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|inits_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|inits_iterator
operator|>
name|inits_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|inits_const_iterator
operator|>
name|inits_const_range
expr_stmt|;
name|inits_range
name|inits
argument_list|()
block|{
return|return
name|inits_range
argument_list|(
name|getInits
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getInits
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|inits_const_range
name|inits
argument_list|()
specifier|const
block|{
return|return
name|inits_const_range
argument_list|(
name|getInits
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getInits
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_firstprivate
return|;
block|}
expr|}
block|;
comment|/// \brief This represents clause 'lastprivate' in the '#pragma omp ...'
comment|/// directives.
comment|///
comment|/// \code
comment|/// #pragma omp simd lastprivate(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp simd' has clause 'lastprivate'
comment|/// with the variables 'a' and 'b'.
name|class
name|OMPLastprivateClause
operator|:
name|public
name|OMPVarListClause
operator|<
name|OMPLastprivateClause
operator|>
block|{
comment|// There are 4 additional tail-allocated arrays at the end of the class:
comment|// 1. Contains list of pseudo variables with the default initialization for
comment|// each non-firstprivate variables. Used in codegen for initialization of
comment|// lastprivate copies.
comment|// 2. List of helper expressions for proper generation of assignment operation
comment|// required for lastprivate clause. This list represents private variables
comment|// (for arrays, single array element).
comment|// 3. List of helper expressions for proper generation of assignment operation
comment|// required for lastprivate clause. This list represents original variables
comment|// (for arrays, single array element).
comment|// 4. List of helper expressions that represents assignment operation:
comment|// \code
comment|// DstExprs = SrcExprs;
comment|// \endcode
comment|// Required for proper codegen of final assignment performed by the
comment|// lastprivate clause.
comment|//
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPLastprivateClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPLastprivateClause
operator|>
operator|(
name|OMPC_lastprivate
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPLastprivateClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPLastprivateClause
operator|>
operator|(
name|OMPC_lastprivate
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{}
comment|/// \brief Get the list of helper expressions for initialization of private
comment|/// copies for lastprivate variables.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getPrivateCopies
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getPrivateCopies
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|varlist_end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper expressions, required for proper codegen of the
comment|/// clause. These expressions represent private variables (for arrays, single
comment|/// array element) in the final assignment statement performed by the
comment|/// lastprivate clause.
name|void
name|setSourceExprs
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|SrcExprs
argument_list|)
block|;
comment|/// \brief Get the list of helper source expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getSourceExprs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getSourceExprs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper expressions, required for proper codegen of the
comment|/// clause. These expressions represent original variables (for arrays, single
comment|/// array element) in the final assignment statement performed by the
comment|/// lastprivate clause.
name|void
name|setDestinationExprs
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|DstExprs
argument_list|)
block|;
comment|/// \brief Get the list of helper destination expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getDestinationExprs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getDestinationExprs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper assignment expressions, required for proper
comment|/// codegen of the clause. These expressions are assignment expressions that
comment|/// assign private copy of the variable to original variable.
name|void
name|setAssignmentOps
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|AssignmentOps
argument_list|)
block|;
comment|/// \brief Get the list of helper assignment expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getAssignmentOps
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getAssignmentOps
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the variables.
comment|/// \param SrcExprs List of helper expressions for proper generation of
comment|/// assignment operation required for lastprivate clause. This list represents
comment|/// private variables (for arrays, single array element).
comment|/// \param DstExprs List of helper expressions for proper generation of
comment|/// assignment operation required for lastprivate clause. This list represents
comment|/// original variables (for arrays, single array element).
comment|/// \param AssignmentOps List of helper expressions that represents assignment
comment|/// operation:
comment|/// \code
comment|/// DstExprs = SrcExprs;
comment|/// \endcode
comment|/// Required for proper codegen of final assignment performed by the
comment|/// lastprivate clause.
comment|///
comment|///
specifier|static
name|OMPLastprivateClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|,
argument|ArrayRef<Expr *> SrcExprs
argument_list|,
argument|ArrayRef<Expr *> DstExprs
argument_list|,
argument|ArrayRef<Expr *> AssignmentOps
argument_list|)
block|;
comment|/// \brief Creates an empty clause with the place for \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPLastprivateClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|helper_expr_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|helper_expr_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|helper_expr_iterator
operator|>
name|helper_expr_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|helper_expr_const_iterator
operator|>
name|helper_expr_const_range
expr_stmt|;
comment|/// \brief Set list of helper expressions, required for generation of private
comment|/// copies of original lastprivate variables.
name|void
name|setPrivateCopies
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|PrivateCopies
argument_list|)
block|;
name|helper_expr_const_range
name|private_copies
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getPrivateCopies
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_range
name|private_copies
argument_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getPrivateCopies
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getPrivateCopies
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_const_range
name|source_exprs
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_range
name|source_exprs
argument_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_const_range
name|destination_exprs
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_range
name|destination_exprs
argument_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_const_range
name|assignment_ops
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getAssignmentOps
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getAssignmentOps
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_range
name|assignment_ops
argument_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getAssignmentOps
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getAssignmentOps
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_lastprivate
return|;
block|}
expr|}
block|;
comment|/// \brief This represents clause 'shared' in the '#pragma omp ...' directives.
comment|///
comment|/// \code
comment|/// #pragma omp parallel shared(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has clause 'shared'
comment|/// with the variables 'a' and 'b'.
comment|///
name|class
name|OMPSharedClause
operator|:
name|public
name|OMPVarListClause
operator|<
name|OMPSharedClause
operator|>
block|{
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPSharedClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPSharedClause
operator|>
operator|(
name|OMPC_shared
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPSharedClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPSharedClause
operator|>
operator|(
name|OMPC_shared
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the variables.
comment|///
specifier|static
name|OMPSharedClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|)
block|;
comment|/// \brief Creates an empty clause with \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPSharedClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_shared
return|;
block|}
expr|}
block|;
comment|/// \brief This represents clause 'reduction' in the '#pragma omp ...'
comment|/// directives.
comment|///
comment|/// \code
comment|/// #pragma omp parallel reduction(+:a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has clause 'reduction'
comment|/// with operator '+' and the variables 'a' and 'b'.
comment|///
name|class
name|OMPReductionClause
operator|:
name|public
name|OMPVarListClause
operator|<
name|OMPReductionClause
operator|>
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of ':'.
name|SourceLocation
name|ColonLoc
block|;
comment|/// \brief Nested name specifier for C++.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief Name of custom operator.
name|DeclarationNameInfo
name|NameInfo
block|;
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param ColonLoc Location of ':'.
comment|/// \param N Number of the variables in the clause.
comment|/// \param QualifierLoc The nested-name qualifier with location information
comment|/// \param NameInfo The full name info for reduction identifier.
comment|///
name|OMPReductionClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPReductionClause
operator|>
operator|(
name|OMPC_reduction
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|,
name|ColonLoc
argument_list|(
name|ColonLoc
argument_list|)
block|,
name|QualifierLoc
argument_list|(
name|QualifierLoc
argument_list|)
block|,
name|NameInfo
argument_list|(
argument|NameInfo
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPReductionClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPReductionClause
operator|>
operator|(
name|OMPC_reduction
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|,
name|ColonLoc
argument_list|()
block|,
name|QualifierLoc
argument_list|()
block|,
name|NameInfo
argument_list|()
block|{}
comment|/// \brief Sets location of ':' symbol in clause.
name|void
name|setColonLoc
argument_list|(
argument|SourceLocation CL
argument_list|)
block|{
name|ColonLoc
operator|=
name|CL
block|; }
comment|/// \brief Sets the name info for specified reduction identifier.
name|void
name|setNameInfo
argument_list|(
argument|DeclarationNameInfo DNI
argument_list|)
block|{
name|NameInfo
operator|=
name|DNI
block|; }
comment|/// \brief Sets the nested name specifier.
name|void
name|setQualifierLoc
argument_list|(
argument|NestedNameSpecifierLoc NSL
argument_list|)
block|{
name|QualifierLoc
operator|=
name|NSL
block|; }
comment|/// \brief Set list of helper expressions, required for proper codegen of the
comment|/// clause. These expressions represent LHS expression in the final
comment|/// reduction expression performed by the reduction clause.
name|void
name|setLHSExprs
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|LHSExprs
argument_list|)
block|;
comment|/// \brief Get the list of helper LHS expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getLHSExprs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getLHSExprs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|varlist_end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper expressions, required for proper codegen of the
comment|/// clause. These expressions represent RHS expression in the final
comment|/// reduction expression performed by the reduction clause.
comment|/// Also, variables in these expressions are used for proper initialization of
comment|/// reduction copies.
name|void
name|setRHSExprs
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|RHSExprs
argument_list|)
block|;
comment|/// \brief Get the list of helper destination expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getRHSExprs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getLHSExprs
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getRHSExprs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getLHSExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper reduction expressions, required for proper
comment|/// codegen of the clause. These expressions are binary expressions or
comment|/// operator/custom reduction call that calculates new value from source
comment|/// helper expressions to destination helper expressions.
name|void
name|setReductionOps
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|ReductionOps
argument_list|)
block|;
comment|/// \brief Get the list of helper reduction expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getReductionOps
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getRHSExprs
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getReductionOps
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getRHSExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param ColonLoc Location of ':'.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL The variables in the clause.
comment|/// \param QualifierLoc The nested-name qualifier with location information
comment|/// \param NameInfo The full name info for reduction identifier.
comment|/// \param LHSExprs List of helper expressions for proper generation of
comment|/// assignment operation required for copyprivate clause. This list represents
comment|/// LHSs of the reduction expressions.
comment|/// \param RHSExprs List of helper expressions for proper generation of
comment|/// assignment operation required for copyprivate clause. This list represents
comment|/// RHSs of the reduction expressions.
comment|/// Also, variables in these expressions are used for proper initialization of
comment|/// reduction copies.
comment|/// \param ReductionOps List of helper expressions that represents reduction
comment|/// expressions:
comment|/// \code
comment|/// LHSExprs binop RHSExprs;
comment|/// operator binop(LHSExpr, RHSExpr);
comment|///<CutomReduction>(LHSExpr, RHSExpr);
comment|/// \endcode
comment|/// Required for proper codegen of final reduction operation performed by the
comment|/// reduction clause.
comment|///
specifier|static
name|OMPReductionClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|ArrayRef<Expr *> LHSExprs
argument_list|,
argument|ArrayRef<Expr *> RHSExprs
argument_list|,
argument|ArrayRef<Expr *> ReductionOps
argument_list|)
block|;
comment|/// \brief Creates an empty clause with the place for \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPReductionClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
comment|/// \brief Gets location of ':' symbol in clause.
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
return|;
block|}
comment|/// \brief Gets the name info for specified reduction identifier.
specifier|const
name|DeclarationNameInfo
operator|&
name|getNameInfo
argument_list|()
specifier|const
block|{
return|return
name|NameInfo
return|;
block|}
comment|/// \brief Gets the nested name specifier.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|helper_expr_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|helper_expr_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|helper_expr_iterator
operator|>
name|helper_expr_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|helper_expr_const_iterator
operator|>
name|helper_expr_const_range
expr_stmt|;
name|helper_expr_const_range
name|lhs_exprs
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getLHSExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getLHSExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_range
name|lhs_exprs
argument_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getLHSExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getLHSExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_const_range
name|rhs_exprs
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getRHSExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getRHSExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_range
name|rhs_exprs
argument_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getRHSExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getRHSExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_const_range
name|reduction_ops
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getReductionOps
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getReductionOps
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|helper_expr_range
name|reduction_ops
argument_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getReductionOps
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getReductionOps
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_reduction
return|;
block|}
expr|}
block|;
comment|/// \brief This represents clause 'linear' in the '#pragma omp ...'
comment|/// directives.
comment|///
comment|/// \code
comment|/// #pragma omp simd linear(a,b : 2)
comment|/// \endcode
comment|/// In this example directive '#pragma omp simd' has clause 'linear'
comment|/// with variables 'a', 'b' and linear step '2'.
comment|///
name|class
name|OMPLinearClause
operator|:
name|public
name|OMPVarListClause
operator|<
name|OMPLinearClause
operator|>
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of ':'.
name|SourceLocation
name|ColonLoc
block|;
comment|/// \brief Sets the linear step for clause.
name|void
name|setStep
argument_list|(
argument|Expr *Step
argument_list|)
block|{
operator|*
operator|(
name|getFinals
argument_list|()
operator|.
name|end
argument_list|()
operator|)
operator|=
name|Step
block|; }
comment|/// \brief Sets the expression to calculate linear step for clause.
name|void
name|setCalcStep
argument_list|(
argument|Expr *CalcStep
argument_list|)
block|{
operator|*
operator|(
name|getFinals
argument_list|()
operator|.
name|end
argument_list|()
operator|+
literal|1
operator|)
operator|=
name|CalcStep
block|; }
comment|/// \brief Build 'linear' clause with given number of variables \a NumVars.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param ColonLoc Location of ':'.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param NumVars Number of variables.
comment|///
name|OMPLinearClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumVars
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPLinearClause
operator|>
operator|(
name|OMPC_linear
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|NumVars
operator|)
block|,
name|ColonLoc
argument_list|(
argument|ColonLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param NumVars Number of variables.
comment|///
name|explicit
name|OMPLinearClause
argument_list|(
argument|unsigned NumVars
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPLinearClause
operator|>
operator|(
name|OMPC_linear
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|NumVars
operator|)
block|,
name|ColonLoc
argument_list|(
argument|SourceLocation()
argument_list|)
block|{}
comment|/// \brief Gets the list of initial values for linear variables.
comment|///
comment|/// There are NumVars expressions with initial values allocated after the
comment|/// varlist, they are followed by NumVars update expressions (used to update
comment|/// the linear variable's value on current iteration) and they are followed by
comment|/// NumVars final expressions (used to calculate the linear variable's
comment|/// value after the loop body). After these lists, there are 2 helper
comment|/// expressions - linear step and a helper to calculate it before the
comment|/// loop body (used when the linear step is not constant):
comment|///
comment|/// { Vars[] /* in OMPVarListClause */; Inits[]; Updates[]; Finals[];
comment|///   Step; CalcStep; }
comment|///
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getInits
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getInits
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|varlist_end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Sets the list of update expressions for linear variables.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getUpdates
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getInits
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getUpdates
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getInits
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Sets the list of final update expressions for linear variables.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getFinals
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getUpdates
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getFinals
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getUpdates
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Sets the list of the initial values for linear variables.
comment|/// \param IL List of expressions.
name|void
name|setInits
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|IL
argument_list|)
block|;
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL and a linear step
comment|/// \a Step.
comment|///
comment|/// \param C AST Context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param ColonLoc Location of ':'.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the variables.
comment|/// \param IL List of initial values for the variables.
comment|/// \param Step Linear step.
comment|/// \param CalcStep Calculation of the linear step.
specifier|static
name|OMPLinearClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|,
argument|ArrayRef<Expr *> IL
argument_list|,
argument|Expr *Step
argument_list|,
argument|Expr *CalcStep
argument_list|)
block|;
comment|/// \brief Creates an empty clause with the place for \a NumVars variables.
comment|///
comment|/// \param C AST context.
comment|/// \param NumVars Number of variables.
comment|///
specifier|static
name|OMPLinearClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumVars
argument_list|)
block|;
comment|/// \brief Sets the location of ':'.
name|void
name|setColonLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|ColonLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of '('.
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
return|;
block|}
comment|/// \brief Returns linear step.
name|Expr
operator|*
name|getStep
argument_list|()
block|{
return|return
operator|*
operator|(
name|getFinals
argument_list|()
operator|.
name|end
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns linear step.
specifier|const
name|Expr
operator|*
name|getStep
argument_list|()
specifier|const
block|{
return|return
operator|*
operator|(
name|getFinals
argument_list|()
operator|.
name|end
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns expression to calculate linear step.
name|Expr
operator|*
name|getCalcStep
argument_list|()
block|{
return|return
operator|*
operator|(
name|getFinals
argument_list|()
operator|.
name|end
argument_list|()
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Returns expression to calculate linear step.
specifier|const
name|Expr
operator|*
name|getCalcStep
argument_list|()
specifier|const
block|{
return|return
operator|*
operator|(
name|getFinals
argument_list|()
operator|.
name|end
argument_list|()
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Sets the list of update expressions for linear variables.
comment|/// \param UL List of expressions.
name|void
name|setUpdates
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|UL
argument_list|)
block|;
comment|/// \brief Sets the list of final update expressions for linear variables.
comment|/// \param FL List of expressions.
name|void
name|setFinals
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|FL
argument_list|)
block|;
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|inits_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|inits_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|inits_iterator
operator|>
name|inits_range
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|inits_const_iterator
operator|>
name|inits_const_range
expr_stmt|;
end_typedef

begin_function
name|inits_range
name|inits
parameter_list|()
block|{
return|return
name|inits_range
argument_list|(
name|getInits
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getInits
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|inits_const_range
name|inits
argument_list|()
specifier|const
block|{
return|return
name|inits_const_range
argument_list|(
name|getInits
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getInits
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|updates_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|updates_const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|updates_iterator
operator|>
name|updates_range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|updates_const_iterator
operator|>
name|updates_const_range
expr_stmt|;
end_typedef

begin_function
name|updates_range
name|updates
parameter_list|()
block|{
return|return
name|updates_range
argument_list|(
name|getUpdates
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getUpdates
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|updates_const_range
name|updates
argument_list|()
specifier|const
block|{
return|return
name|updates_const_range
argument_list|(
name|getUpdates
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getUpdates
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|finals_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|finals_const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|finals_iterator
operator|>
name|finals_range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|finals_const_iterator
operator|>
name|finals_const_range
expr_stmt|;
end_typedef

begin_function
name|finals_range
name|finals
parameter_list|()
block|{
return|return
name|finals_range
argument_list|(
name|getFinals
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getFinals
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|finals_const_range
name|finals
argument_list|()
specifier|const
block|{
return|return
name|finals_const_range
argument_list|(
name|getFinals
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getFinals
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|StmtRange
name|children
parameter_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|OMPClause
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_linear
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief This represents clause 'aligned' in the '#pragma omp ...'
end_comment

begin_comment
comment|/// directives.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// #pragma omp simd aligned(a,b : 8)
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// In this example directive '#pragma omp simd' has clause 'aligned'
end_comment

begin_comment
comment|/// with variables 'a', 'b' and alignment '8'.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|OMPAlignedClause
range|:
name|public
name|OMPVarListClause
operator|<
name|OMPAlignedClause
operator|>
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Location of ':'.
name|SourceLocation
name|ColonLoc
block|;
comment|/// \brief Sets the alignment for clause.
name|void
name|setAlignment
argument_list|(
argument|Expr *A
argument_list|)
block|{
operator|*
name|varlist_end
argument_list|()
operator|=
name|A
block|; }
comment|/// \brief Build 'aligned' clause with given number of variables \a NumVars.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param ColonLoc Location of ':'.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param NumVars Number of variables.
comment|///
name|OMPAlignedClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned NumVars
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPAlignedClause
operator|>
operator|(
name|OMPC_aligned
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|NumVars
operator|)
block|,
name|ColonLoc
argument_list|(
argument|ColonLoc
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param NumVars Number of variables.
comment|///
name|explicit
name|OMPAlignedClause
argument_list|(
argument|unsigned NumVars
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPAlignedClause
operator|>
operator|(
name|OMPC_aligned
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|NumVars
operator|)
block|,
name|ColonLoc
argument_list|(
argument|SourceLocation()
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL and alignment \a A.
comment|///
comment|/// \param C AST Context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param ColonLoc Location of ':'.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the variables.
comment|/// \param A Alignment.
specifier|static
name|OMPAlignedClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|,
argument|Expr *A
argument_list|)
block|;
comment|/// \brief Creates an empty clause with the place for \a NumVars variables.
comment|///
comment|/// \param C AST context.
comment|/// \param NumVars Number of variables.
comment|///
specifier|static
name|OMPAlignedClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumVars
argument_list|)
block|;
comment|/// \brief Sets the location of ':'.
name|void
name|setColonLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|ColonLoc
operator|=
name|Loc
block|; }
comment|/// \brief Returns the location of ':'.
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
return|;
block|}
comment|/// \brief Returns alignment.
name|Expr
operator|*
name|getAlignment
argument_list|()
block|{
return|return
operator|*
name|varlist_end
argument_list|()
return|;
block|}
comment|/// \brief Returns alignment.
specifier|const
name|Expr
operator|*
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
operator|*
name|varlist_end
argument_list|()
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_aligned
return|;
block|}
expr|}
block|;
comment|/// \brief This represents clause 'copyin' in the '#pragma omp ...' directives.
comment|///
comment|/// \code
comment|/// #pragma omp parallel copyin(a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has clause 'copyin'
comment|/// with the variables 'a' and 'b'.
comment|///
name|class
name|OMPCopyinClause
operator|:
name|public
name|OMPVarListClause
operator|<
name|OMPCopyinClause
operator|>
block|{
comment|// Class has 3 additional tail allocated arrays:
comment|// 1. List of helper expressions for proper generation of assignment operation
comment|// required for copyin clause. This list represents sources.
comment|// 2. List of helper expressions for proper generation of assignment operation
comment|// required for copyin clause. This list represents destinations.
comment|// 3. List of helper expressions that represents assignment operation:
comment|// \code
comment|// DstExprs = SrcExprs;
comment|// \endcode
comment|// Required for proper codegen of propagation of master's thread values of
comment|// threadprivate variables to local instances of that variables in other
comment|// implicit threads.
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPCopyinClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPCopyinClause
operator|>
operator|(
name|OMPC_copyin
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPCopyinClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPCopyinClause
operator|>
operator|(
name|OMPC_copyin
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{}
comment|/// \brief Set list of helper expressions, required for proper codegen of the
comment|/// clause. These expressions represent source expression in the final
comment|/// assignment statement performed by the copyin clause.
name|void
name|setSourceExprs
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|SrcExprs
argument_list|)
block|;
comment|/// \brief Get the list of helper source expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getSourceExprs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getSourceExprs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|varlist_end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper expressions, required for proper codegen of the
comment|/// clause. These expressions represent destination expression in the final
comment|/// assignment statement performed by the copyin clause.
name|void
name|setDestinationExprs
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|DstExprs
argument_list|)
block|;
comment|/// \brief Get the list of helper destination expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getDestinationExprs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getDestinationExprs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper assignment expressions, required for proper
comment|/// codegen of the clause. These expressions are assignment expressions that
comment|/// assign source helper expressions to destination helper expressions
comment|/// correspondingly.
name|void
name|setAssignmentOps
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|AssignmentOps
argument_list|)
block|;
comment|/// \brief Get the list of helper assignment expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getAssignmentOps
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getAssignmentOps
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the variables.
comment|/// \param SrcExprs List of helper expressions for proper generation of
comment|/// assignment operation required for copyin clause. This list represents
comment|/// sources.
comment|/// \param DstExprs List of helper expressions for proper generation of
comment|/// assignment operation required for copyin clause. This list represents
comment|/// destinations.
comment|/// \param AssignmentOps List of helper expressions that represents assignment
comment|/// operation:
comment|/// \code
comment|/// DstExprs = SrcExprs;
comment|/// \endcode
comment|/// Required for proper codegen of propagation of master's thread values of
comment|/// threadprivate variables to local instances of that variables in other
comment|/// implicit threads.
comment|///
specifier|static
name|OMPCopyinClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|,
argument|ArrayRef<Expr *> SrcExprs
argument_list|,
argument|ArrayRef<Expr *> DstExprs
argument_list|,
argument|ArrayRef<Expr *> AssignmentOps
argument_list|)
block|;
comment|/// \brief Creates an empty clause with \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPCopyinClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|helper_expr_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|helper_expr_const_iterator
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|helper_expr_iterator
operator|>
name|helper_expr_range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|helper_expr_const_iterator
operator|>
name|helper_expr_const_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|helper_expr_const_range
name|source_exprs
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|helper_expr_range
name|source_exprs
parameter_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|helper_expr_const_range
name|destination_exprs
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|helper_expr_range
name|destination_exprs
parameter_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|helper_expr_const_range
name|assignment_ops
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getAssignmentOps
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getAssignmentOps
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|helper_expr_range
name|assignment_ops
parameter_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getAssignmentOps
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getAssignmentOps
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|StmtRange
name|children
parameter_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|OMPClause
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_copyin
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief This represents clause 'copyprivate' in the '#pragma omp ...'
end_comment

begin_comment
comment|/// directives.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// #pragma omp single copyprivate(a,b)
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// In this example directive '#pragma omp single' has clause 'copyprivate'
end_comment

begin_comment
comment|/// with the variables 'a' and 'b'.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|OMPCopyprivateClause
range|:
name|public
name|OMPVarListClause
operator|<
name|OMPCopyprivateClause
operator|>
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPCopyprivateClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPCopyprivateClause
operator|>
operator|(
name|OMPC_copyprivate
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPCopyprivateClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPCopyprivateClause
operator|>
operator|(
name|OMPC_copyprivate
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{}
comment|/// \brief Set list of helper expressions, required for proper codegen of the
comment|/// clause. These expressions represent source expression in the final
comment|/// assignment statement performed by the copyprivate clause.
name|void
name|setSourceExprs
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|SrcExprs
argument_list|)
block|;
comment|/// \brief Get the list of helper source expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getSourceExprs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getSourceExprs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|varlist_end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper expressions, required for proper codegen of the
comment|/// clause. These expressions represent destination expression in the final
comment|/// assignment statement performed by the copyprivate clause.
name|void
name|setDestinationExprs
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|DstExprs
argument_list|)
block|;
comment|/// \brief Get the list of helper destination expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getDestinationExprs
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getDestinationExprs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set list of helper assignment expressions, required for proper
comment|/// codegen of the clause. These expressions are assignment expressions that
comment|/// assign source helper expressions to destination helper expressions
comment|/// correspondingly.
name|void
name|setAssignmentOps
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|AssignmentOps
argument_list|)
block|;
comment|/// \brief Get the list of helper assignment expressions.
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getAssignmentOps
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
expr|,
name|varlist_size
argument_list|()
operator|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getAssignmentOps
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|varlist_size
argument_list|()
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the variables.
comment|/// \param SrcExprs List of helper expressions for proper generation of
comment|/// assignment operation required for copyprivate clause. This list represents
comment|/// sources.
comment|/// \param DstExprs List of helper expressions for proper generation of
comment|/// assignment operation required for copyprivate clause. This list represents
comment|/// destinations.
comment|/// \param AssignmentOps List of helper expressions that represents assignment
comment|/// operation:
comment|/// \code
comment|/// DstExprs = SrcExprs;
comment|/// \endcode
comment|/// Required for proper codegen of final assignment performed by the
comment|/// copyprivate clause.
comment|///
specifier|static
name|OMPCopyprivateClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|,
argument|ArrayRef<Expr *> SrcExprs
argument_list|,
argument|ArrayRef<Expr *> DstExprs
argument_list|,
argument|ArrayRef<Expr *> AssignmentOps
argument_list|)
block|;
comment|/// \brief Creates an empty clause with \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPCopyprivateClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|helper_expr_iterator
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|helper_expr_const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|helper_expr_iterator
operator|>
name|helper_expr_range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|helper_expr_const_iterator
operator|>
name|helper_expr_const_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|helper_expr_const_range
name|source_exprs
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|helper_expr_range
name|source_exprs
parameter_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getSourceExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getSourceExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|helper_expr_const_range
name|destination_exprs
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|helper_expr_range
name|destination_exprs
parameter_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getDestinationExprs
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getDestinationExprs
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|helper_expr_const_range
name|assignment_ops
argument_list|()
specifier|const
block|{
return|return
name|helper_expr_const_range
argument_list|(
name|getAssignmentOps
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getAssignmentOps
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|helper_expr_range
name|assignment_ops
parameter_list|()
block|{
return|return
name|helper_expr_range
argument_list|(
name|getAssignmentOps
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|getAssignmentOps
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|StmtRange
name|children
parameter_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|OMPClause
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_copyprivate
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief This represents implicit clause 'flush' for the '#pragma omp flush'
end_comment

begin_comment
comment|/// directive.
end_comment

begin_comment
comment|/// This clause does not exist by itself, it can be only as a part of 'omp
end_comment

begin_comment
comment|/// flush' directive. This clause is introduced to keep the original structure
end_comment

begin_comment
comment|/// of \a OMPExecutableDirective class and its derivatives and to use the
end_comment

begin_comment
comment|/// existing infrastructure of clauses with the list of variables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// #pragma omp flush(a,b)
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// In this example directive '#pragma omp flush' has implicit clause 'flush'
end_comment

begin_comment
comment|/// with the variables 'a' and 'b'.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|OMPFlushClause
range|:
name|public
name|OMPVarListClause
operator|<
name|OMPFlushClause
operator|>
block|{
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPFlushClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPFlushClause
operator|>
operator|(
name|OMPC_flush
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPFlushClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPFlushClause
operator|>
operator|(
name|OMPC_flush
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{}
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param VL List of references to the variables.
comment|///
specifier|static
name|OMPFlushClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|)
block|;
comment|/// \brief Creates an empty clause with \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPFlushClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_flush
return|;
block|}
expr|}
block|;
comment|/// \brief This represents implicit clause 'depend' for the '#pragma omp task'
comment|/// directive.
comment|///
comment|/// \code
comment|/// #pragma omp task depend(in:a,b)
comment|/// \endcode
comment|/// In this example directive '#pragma omp task' with clause 'depend' with the
comment|/// variables 'a' and 'b' with dependency 'in'.
comment|///
name|class
name|OMPDependClause
operator|:
name|public
name|OMPVarListClause
operator|<
name|OMPDependClause
operator|>
block|{
name|friend
name|class
name|OMPClauseReader
block|;
comment|/// \brief Dependency type (one of in, out, inout).
name|OpenMPDependClauseKind
name|DepKind
block|;
comment|/// \brief Dependency type location.
name|SourceLocation
name|DepLoc
block|;
comment|/// \brief Colon location.
name|SourceLocation
name|ColonLoc
block|;
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPDependClause
argument_list|(
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPDependClause
operator|>
operator|(
name|OMPC_depend
expr|,
name|StartLoc
expr|,
name|LParenLoc
expr|,
name|EndLoc
expr|,
name|N
operator|)
block|,
name|DepKind
argument_list|(
argument|OMPC_DEPEND_unknown
argument_list|)
block|{}
comment|/// \brief Build an empty clause.
comment|///
comment|/// \param N Number of variables.
comment|///
name|explicit
name|OMPDependClause
argument_list|(
argument|unsigned N
argument_list|)
operator|:
name|OMPVarListClause
operator|<
name|OMPDependClause
operator|>
operator|(
name|OMPC_depend
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|,
name|DepKind
argument_list|(
argument|OMPC_DEPEND_unknown
argument_list|)
block|{}
comment|/// \brief Set dependency kind.
name|void
name|setDependencyKind
argument_list|(
argument|OpenMPDependClauseKind K
argument_list|)
block|{
name|DepKind
operator|=
name|K
block|; }
comment|/// \brief Set dependency kind and its location.
name|void
name|setDependencyLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|DepLoc
operator|=
name|Loc
block|; }
comment|/// \brief Set colon location.
name|void
name|setColonLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|ColonLoc
operator|=
name|Loc
block|; }
name|public
operator|:
comment|/// \brief Creates clause with a list of variables \a VL.
comment|///
comment|/// \param C AST context.
comment|/// \param StartLoc Starting location of the clause.
comment|/// \param LParenLoc Location of '('.
comment|/// \param EndLoc Ending location of the clause.
comment|/// \param DepKind Dependency type.
comment|/// \param DepLoc Location of the dependency type.
comment|/// \param ColonLoc Colon location.
comment|/// \param VL List of references to the variables.
comment|///
specifier|static
name|OMPDependClause
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|OpenMPDependClauseKind DepKind
argument_list|,
argument|SourceLocation DepLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|)
block|;
comment|/// \brief Creates an empty clause with \a N variables.
comment|///
comment|/// \param C AST context.
comment|/// \param N The number of variables.
comment|///
specifier|static
name|OMPDependClause
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned N
argument_list|)
block|;
comment|/// \brief Get dependency type.
name|OpenMPDependClauseKind
name|getDependencyKind
argument_list|()
specifier|const
block|{
return|return
name|DepKind
return|;
block|}
comment|/// \brief Get dependency type location.
name|SourceLocation
name|getDependencyLoc
argument_list|()
specifier|const
block|{
return|return
name|DepLoc
return|;
block|}
comment|/// \brief Get colon location.
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
return|;
block|}
name|StmtRange
name|children
argument_list|()
block|{
return|return
name|StmtRange
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_begin
argument_list|()
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|varlist_end
argument_list|()
operator|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OMPClause *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getClauseKind
argument_list|()
operator|==
name|OMPC_depend
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

