begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OpenMPKinds.h - OpenMP enums ---------------------------*- C++ -*-===//
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
comment|/// \brief Defines some OpenMP-specific enums and functions.
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
name|LLVM_CLANG_BASIC_OPENMPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_OPENMPKINDS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief OpenMP directives.
enum|enum
name|OpenMPDirectiveKind
block|{
define|#
directive|define
name|OPENMP_DIRECTIVE
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPD_##Name,
define|#
directive|define
name|OPENMP_DIRECTIVE_EXT
parameter_list|(
name|Name
parameter_list|,
name|Str
parameter_list|)
define|\
value|OMPD_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPD_unknown
block|}
enum|;
comment|/// \brief OpenMP clauses.
enum|enum
name|OpenMPClauseKind
block|{
define|#
directive|define
name|OPENMP_CLAUSE
parameter_list|(
name|Name
parameter_list|,
name|Class
parameter_list|)
define|\
value|OMPC_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_threadprivate
block|,
name|OMPC_unknown
block|}
enum|;
comment|/// \brief OpenMP attributes for 'default' clause.
enum|enum
name|OpenMPDefaultClauseKind
block|{
define|#
directive|define
name|OPENMP_DEFAULT_KIND
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_DEFAULT_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_DEFAULT_unknown
block|}
enum|;
comment|/// \brief OpenMP attributes for 'proc_bind' clause.
enum|enum
name|OpenMPProcBindClauseKind
block|{
define|#
directive|define
name|OPENMP_PROC_BIND_KIND
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_PROC_BIND_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_PROC_BIND_unknown
block|}
enum|;
comment|/// \brief OpenMP attributes for 'schedule' clause.
enum|enum
name|OpenMPScheduleClauseKind
block|{
define|#
directive|define
name|OPENMP_SCHEDULE_KIND
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_SCHEDULE_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_SCHEDULE_unknown
block|}
enum|;
name|OpenMPDirectiveKind
name|getOpenMPDirectiveKind
argument_list|(
name|llvm
operator|::
name|StringRef
name|Str
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|getOpenMPDirectiveName
parameter_list|(
name|OpenMPDirectiveKind
name|Kind
parameter_list|)
function_decl|;
name|OpenMPClauseKind
name|getOpenMPClauseKind
argument_list|(
name|llvm
operator|::
name|StringRef
name|Str
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|getOpenMPClauseName
parameter_list|(
name|OpenMPClauseKind
name|Kind
parameter_list|)
function_decl|;
name|unsigned
name|getOpenMPSimpleClauseType
argument_list|(
name|OpenMPClauseKind
name|Kind
argument_list|,
name|llvm
operator|::
name|StringRef
name|Str
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|getOpenMPSimpleClauseTypeName
parameter_list|(
name|OpenMPClauseKind
name|Kind
parameter_list|,
name|unsigned
name|Type
parameter_list|)
function_decl|;
name|bool
name|isAllowedClauseForDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|,
name|OpenMPClauseKind
name|CKind
parameter_list|)
function_decl|;
comment|/// \brief Checks if the specified directive is a directive with an associated
comment|/// loop construct.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a loop-associated directive like 'omp simd'
comment|/// or 'omp for' directive, otherwise - false.
name|bool
name|isOpenMPLoopDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// \brief Checks if the specified directive is a worksharing directive.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a worksharing directive like 'omp for',
comment|/// otherwise - false.
name|bool
name|isOpenMPWorksharingDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// \brief Checks if the specified directive is a parallel-kind directive.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a parallel-like directive like 'omp
comment|/// parallel', otherwise - false.
name|bool
name|isOpenMPParallelDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// \brief Checks if the specified directive is a teams-kind directive.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a teams-like directive like 'omp teams',
comment|/// otherwise - false.
name|bool
name|isOpenMPTeamsDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// \brief Checks if the specified directive is a simd directive.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a simd directive like 'omp simd',
comment|/// otherwise - false.
name|bool
name|isOpenMPSimdDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// \brief Checks if the specified clause is one of private clauses like
comment|/// 'private', 'firstprivate', 'reduction' etc..
comment|/// \param Kind Clause kind.
comment|/// \return true - the clause is a private clause, otherwise - false.
name|bool
name|isOpenMPPrivate
parameter_list|(
name|OpenMPClauseKind
name|Kind
parameter_list|)
function_decl|;
comment|/// \brief Checks if the specified clause is one of threadprivate clauses like
comment|/// 'threadprivate', 'copyin' or 'copyprivate'.
comment|/// \param Kind Clause kind.
comment|/// \return true - the clause is a threadprivate clause, otherwise - false.
name|bool
name|isOpenMPThreadPrivate
parameter_list|(
name|OpenMPClauseKind
name|Kind
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

