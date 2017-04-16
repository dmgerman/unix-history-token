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
name|OMPC_uniform
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
comment|/// \brief OpenMP modifiers for 'schedule' clause.
enum|enum
name|OpenMPScheduleClauseModifier
block|{
name|OMPC_SCHEDULE_MODIFIER_unknown
init|=
name|OMPC_SCHEDULE_unknown
block|,
define|#
directive|define
name|OPENMP_SCHEDULE_MODIFIER
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_SCHEDULE_MODIFIER_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_SCHEDULE_MODIFIER_last
block|}
enum|;
comment|/// \brief OpenMP attributes for 'depend' clause.
enum|enum
name|OpenMPDependClauseKind
block|{
define|#
directive|define
name|OPENMP_DEPEND_KIND
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_DEPEND_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_DEPEND_unknown
block|}
enum|;
comment|/// \brief OpenMP attributes for 'linear' clause.
enum|enum
name|OpenMPLinearClauseKind
block|{
define|#
directive|define
name|OPENMP_LINEAR_KIND
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_LINEAR_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_LINEAR_unknown
block|}
enum|;
comment|/// \brief OpenMP mapping kind for 'map' clause.
enum|enum
name|OpenMPMapClauseKind
block|{
define|#
directive|define
name|OPENMP_MAP_KIND
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_MAP_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_MAP_unknown
block|}
enum|;
comment|/// \brief OpenMP attributes for 'dist_schedule' clause.
enum|enum
name|OpenMPDistScheduleClauseKind
block|{
define|#
directive|define
name|OPENMP_DIST_SCHEDULE_KIND
parameter_list|(
name|Name
parameter_list|)
value|OMPC_DIST_SCHEDULE_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_DIST_SCHEDULE_unknown
block|}
enum|;
comment|/// \brief OpenMP attributes for 'defaultmap' clause.
enum|enum
name|OpenMPDefaultmapClauseKind
block|{
define|#
directive|define
name|OPENMP_DEFAULTMAP_KIND
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_DEFAULTMAP_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_DEFAULTMAP_unknown
block|}
enum|;
comment|/// \brief OpenMP modifiers for 'defaultmap' clause.
enum|enum
name|OpenMPDefaultmapClauseModifier
block|{
name|OMPC_DEFAULTMAP_MODIFIER_unknown
init|=
name|OMPC_DEFAULTMAP_unknown
block|,
define|#
directive|define
name|OPENMP_DEFAULTMAP_MODIFIER
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPC_DEFAULTMAP_MODIFIER_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|OMPC_DEFAULTMAP_MODIFIER_last
block|}
enum|;
comment|/// Scheduling data for loop-based OpenMP directives.
struct|struct
name|OpenMPScheduleTy
name|final
block|{
name|OpenMPScheduleClauseKind
name|Schedule
init|=
name|OMPC_SCHEDULE_unknown
decl_stmt|;
name|OpenMPScheduleClauseModifier
name|M1
init|=
name|OMPC_SCHEDULE_MODIFIER_unknown
decl_stmt|;
name|OpenMPScheduleClauseModifier
name|M2
init|=
name|OMPC_SCHEDULE_MODIFIER_unknown
decl_stmt|;
block|}
struct|;
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
comment|/// \brief Checks if the specified directive is a taskloop directive.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a worksharing directive like 'omp taskloop',
comment|/// otherwise - false.
name|bool
name|isOpenMPTaskLoopDirective
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
comment|/// \brief Checks if the specified directive is a target code offload directive.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a target code offload directive like
comment|/// 'omp target', 'omp target parallel', 'omp target xxx'
comment|/// otherwise - false.
name|bool
name|isOpenMPTargetExecutionDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// \brief Checks if the specified directive is a target data offload directive.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a target data offload directive like
comment|/// 'omp target data', 'omp target update', 'omp target enter data',
comment|/// 'omp target exit data'
comment|/// otherwise - false.
name|bool
name|isOpenMPTargetDataManagementDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// Checks if the specified composite/combined directive constitutes a teams
comment|/// directive in the outermost nest.  For example
comment|/// 'omp teams distribute' or 'omp teams distribute parallel for'.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive has teams on the outermost nest, otherwise -
comment|/// false.
name|bool
name|isOpenMPNestingTeamsDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// Checks if the specified directive is a teams-kind directive.  For example,
comment|/// 'omp teams distribute' or 'omp target teams'.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a teams-like directive, otherwise - false.
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
comment|/// \brief Checks if the specified directive is a distribute directive.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive is a distribute-directive like 'omp
comment|/// distribute',
comment|/// otherwise - false.
name|bool
name|isOpenMPDistributeDirective
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|)
function_decl|;
comment|/// Checks if the specified composite/combined directive constitutes a
comment|/// distribute directive in the outermost nest.  For example,
comment|/// 'omp distribute parallel for' or 'omp distribute'.
comment|/// \param DKind Specified directive.
comment|/// \return true - the directive has distribute on the outermost nest.
comment|/// otherwise - false.
name|bool
name|isOpenMPNestingDistributeDirective
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
comment|/// Checks if the specified directive kind is one of tasking directives - task,
comment|/// taskloop or taksloop simd.
name|bool
name|isOpenMPTaskingDirective
parameter_list|(
name|OpenMPDirectiveKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Checks if the specified directive kind is one of the composite or combined
comment|/// directives that need loop bound sharing across loops outlined in nested
comment|/// functions
name|bool
name|isOpenMPLoopBoundSharingDirective
parameter_list|(
name|OpenMPDirectiveKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Return the captured regions of an OpenMP directive.
name|void
name|getOpenMPCaptureRegions
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|OpenMPDirectiveKind
operator|>
operator|&
name|CaptureRegions
argument_list|,
name|OpenMPDirectiveKind
name|DKind
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

