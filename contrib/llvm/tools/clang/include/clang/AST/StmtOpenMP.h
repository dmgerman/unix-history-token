begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StmtOpenMP.h - Classes for OpenMP directives and clauses --*- C++ -*-===//
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
file|"clang/Basic/OpenMPKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

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
name|T
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
name|OMPVarList
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
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getVarRefs
argument_list|()
block|{
return|return
name|llvm
operator|::
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
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
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
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
operator|)
argument_list|)
block|;   }
comment|/// \brief Build clause with number of variables \a N.
comment|///
comment|/// \param N Number of the variables in the clause.
comment|///
name|OMPVarList
argument_list|(
argument|SourceLocation LParenLoc
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|NumVars
argument_list|(
argument|N
argument_list|)
block|{ }
name|public
operator|:
typedef|typedef
name|llvm
operator|::
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
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
specifier|const
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
operator|)
operator|,
name|NumVars
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief This represents 'default' clause in the '#pragma omp ...' directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// #pragma omp parallel default(shared)
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// In this example directive '#pragma omp parallel' has simple 'default'
end_comment

begin_comment
comment|/// clause with kind 'shared'.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|OMPDefaultClause
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
block|{ }
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
block|{ }
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
name|OMPClause
block|,
name|public
name|OMPVarList
operator|<
name|OMPPrivateClause
operator|>
block|{
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
name|OMPClause
argument_list|(
name|OMPC_private
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|OMPVarList
operator|<
name|OMPPrivateClause
operator|>
operator|(
name|LParenLoc
expr|,
name|N
operator|)
block|{ }
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
name|OMPClause
argument_list|(
name|OMPC_private
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|OMPVarList
operator|<
name|OMPPrivateClause
operator|>
operator|(
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{ }
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
name|OMPClause
block|,
name|public
name|OMPVarList
operator|<
name|OMPFirstprivateClause
operator|>
block|{
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
name|OMPClause
argument_list|(
name|OMPC_firstprivate
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|OMPVarList
operator|<
name|OMPFirstprivateClause
operator|>
operator|(
name|LParenLoc
expr|,
name|N
operator|)
block|{ }
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
name|OMPClause
argument_list|(
name|OMPC_firstprivate
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|OMPVarList
operator|<
name|OMPFirstprivateClause
operator|>
operator|(
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{ }
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
name|OMPClause
block|,
name|public
name|OMPVarList
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
name|OMPClause
argument_list|(
name|OMPC_shared
argument_list|,
name|StartLoc
argument_list|,
name|EndLoc
argument_list|)
block|,
name|OMPVarList
operator|<
name|OMPSharedClause
operator|>
operator|(
name|LParenLoc
expr|,
name|N
operator|)
block|{ }
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
name|OMPClause
argument_list|(
name|OMPC_shared
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|OMPVarList
operator|<
name|OMPSharedClause
operator|>
operator|(
name|SourceLocation
argument_list|()
expr|,
name|N
operator|)
block|{ }
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
comment|//===----------------------------------------------------------------------===//
comment|// AST classes for directives.
comment|//===----------------------------------------------------------------------===//
comment|/// \brief This is a basic class for representing single OpenMP executable
comment|/// directive.
comment|///
name|class
name|OMPExecutableDirective
operator|:
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
comment|/// \brief Pointer to the list of clauses.
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
block|;
comment|/// \brief Associated statement (if any) and expressions.
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|Stmt
operator|*
operator|>
name|StmtAndExpressions
block|;
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
argument|unsigned NumberOfExpressions
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
name|StartLoc
argument_list|)
block|,
name|EndLoc
argument_list|(
name|EndLoc
argument_list|)
block|,
name|Clauses
argument_list|(
name|reinterpret_cast
operator|<
name|OMPClause
operator|*
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
literal|1
operator|)
argument_list|,
name|NumClauses
argument_list|)
block|,
name|StmtAndExpressions
argument_list|(
argument|reinterpret_cast<Stmt **>(Clauses.end())
argument_list|,
argument|NumberOfExpressions
argument_list|)
block|{ }
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
name|StmtAndExpressions
index|[
literal|0
index|]
operator|=
name|S
block|;   }
name|public
operator|:
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
name|Clauses
operator|.
name|size
argument_list|()
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
name|assert
argument_list|(
name|i
operator|<
name|Clauses
operator|.
name|size
argument_list|()
operator|&&
literal|"index out of bound!"
argument_list|)
block|;
return|return
name|Clauses
index|[
name|i
index|]
return|;
block|}
comment|/// \brief Returns statement associated with the directive.
name|Stmt
operator|*
name|getAssociatedStmt
argument_list|()
specifier|const
block|{
return|return
name|StmtAndExpressions
index|[
literal|0
index|]
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
return|return
name|child_range
argument_list|(
name|StmtAndExpressions
operator|.
name|begin
argument_list|()
argument_list|,
name|StmtAndExpressions
operator|.
name|end
argument_list|()
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
name|Clauses
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
name|Clauses
return|;
block|}
expr|}
block|;
comment|/// \brief This represents '#pragma omp parallel' directive.
comment|///
comment|/// \code
comment|/// #pragma omp parallel private(a,b) reduction(+: c,d)
comment|/// \endcode
comment|/// In this example directive '#pragma omp parallel' has clauses 'private'
comment|/// with the variables 'a' and 'b' and 'reduction' with operator '+' and
comment|/// variables 'c' and 'd'.
comment|///
name|class
name|OMPParallelDirective
operator|:
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
argument|unsigned N
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
argument|N
argument_list|,
literal|1
argument_list|)
block|{ }
comment|/// \brief Build an empty directive.
comment|///
comment|/// \param N Number of clauses.
comment|///
name|explicit
name|OMPParallelDirective
argument_list|(
argument|unsigned N
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
argument|N
argument_list|,
literal|1
argument_list|)
block|{ }
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
comment|/// \param N The number of clauses.
comment|///
specifier|static
name|OMPParallelDirective
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
name|OMPParallelDirectiveClass
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

