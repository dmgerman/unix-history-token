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
name|OMPD_unknown
init|=
literal|0
block|,
define|#
directive|define
name|OPENMP_DIRECTIVE
parameter_list|(
name|Name
parameter_list|)
define|\
value|OMPD_##Name,
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
name|NUM_OPENMP_DIRECTIVES
block|}
enum|;
comment|/// \brief OpenMP clauses.
enum|enum
name|OpenMPClauseKind
block|{
name|OMPC_unknown
init|=
literal|0
block|,
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
name|NUM_OPENMP_CLAUSES
block|}
enum|;
comment|/// \brief OpenMP attributes for 'default' clause.
enum|enum
name|OpenMPDefaultClauseKind
block|{
name|OMPC_DEFAULT_unknown
init|=
literal|0
block|,
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
name|NUM_OPENMP_DEFAULT_KINDS
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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

