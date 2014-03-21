begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Types.h - Input& Temporary Driver Types ---------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_DRIVER_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_TYPES_H_
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Phases.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|namespace
name|types
block|{
enum|enum
name|ID
block|{
name|TY_INVALID
block|,
define|#
directive|define
name|TYPE
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|,
name|PP_TYPE
parameter_list|,
name|TEMP_SUFFIX
parameter_list|,
name|FLAGS
parameter_list|)
value|TY_##ID,
include|#
directive|include
file|"clang/Driver/Types.def"
undef|#
directive|undef
name|TYPE
name|TY_LAST
block|}
enum|;
comment|/// getTypeName - Return the name of the type for \p Id.
specifier|const
name|char
modifier|*
name|getTypeName
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// getPreprocessedType - Get the ID of the type for this input when
comment|/// it has been preprocessed, or INVALID if this input is not
comment|/// preprocessed.
name|ID
name|getPreprocessedType
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// getTypeTempSuffix - Return the suffix to use when creating a
comment|/// temp file of this type, or null if unspecified.
specifier|const
name|char
modifier|*
name|getTypeTempSuffix
parameter_list|(
name|ID
name|Id
parameter_list|,
name|bool
name|CLMode
init|=
name|false
parameter_list|)
function_decl|;
comment|/// onlyAssembleType - Should this type only be assembled.
name|bool
name|onlyAssembleType
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// onlyPrecompileType - Should this type only be precompiled.
name|bool
name|onlyPrecompileType
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// canTypeBeUserSpecified - Can this type be specified on the
comment|/// command line (by the type name); this is used when forwarding
comment|/// commands to gcc.
name|bool
name|canTypeBeUserSpecified
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// appendSuffixForType - When generating outputs of this type,
comment|/// should the suffix be appended (instead of replacing the existing
comment|/// suffix).
name|bool
name|appendSuffixForType
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// canLipoType - Is this type acceptable as the output of a
comment|/// universal build (currently, just the Nothing, Image, and Object
comment|/// types).
name|bool
name|canLipoType
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// isAcceptedByClang - Can clang handle this input type.
name|bool
name|isAcceptedByClang
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// isCXX - Is this a "C++" input (C++ and Obj-C++ sources and headers).
name|bool
name|isCXX
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// isObjC - Is this an "ObjC" input (Obj-C and Obj-C++ sources and headers).
name|bool
name|isObjC
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
comment|/// lookupTypeForExtension - Lookup the type to use for the file
comment|/// extension \p Ext.
name|ID
name|lookupTypeForExtension
parameter_list|(
specifier|const
name|char
modifier|*
name|Ext
parameter_list|)
function_decl|;
comment|/// lookupTypeForTypSpecifier - Lookup the type to use for a user
comment|/// specified type name.
name|ID
name|lookupTypeForTypeSpecifier
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|/// getCompilationPhases - Get the list of compilation phases ('Phases') to be
comment|/// done for type 'Id'.
name|void
name|getCompilationPhases
argument_list|(
name|ID
name|Id
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|phases
operator|::
name|ID
operator|>
operator|&
name|Phases
argument_list|)
decl_stmt|;
comment|/// lookupCXXTypeForCType - Lookup CXX input type that corresponds to given
comment|/// C type (used for clang++ emulation of g++ behaviour)
name|ID
name|lookupCXXTypeForCType
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
block|}
comment|// end namespace types
block|}
comment|// end namespace driver
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

