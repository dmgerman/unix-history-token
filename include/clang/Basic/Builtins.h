begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Builtins.h - Builtin function header -------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file defines enum values for all the target-independent builtin
end_comment

begin_comment
comment|// functions.
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
name|LLVM_CLANG_BASIC_BUILTINS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_BUILTINS_H
end_define

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_comment
comment|// VC++ defines 'alloca' as an object-like macro, which interferes with our
end_comment

begin_comment
comment|// builtins.
end_comment

begin_undef
undef|#
directive|undef
name|alloca
end_undef

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|TargetInfo
decl_stmt|;
name|class
name|IdentifierTable
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|namespace
name|Builtin
block|{
enum|enum
name|ID
block|{
name|NotBuiltin
init|=
literal|0
block|,
comment|// This is not a builtin function.
define|#
directive|define
name|BUILTIN
parameter_list|(
name|ID
parameter_list|,
name|TYPE
parameter_list|,
name|ATTRS
parameter_list|)
value|BI##ID,
include|#
directive|include
file|"clang/Basic/Builtins.def"
name|FirstTSBuiltin
block|}
enum|;
struct|struct
name|Info
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|,
modifier|*
name|Type
decl_stmt|,
modifier|*
name|Attributes
decl_stmt|,
modifier|*
name|HeaderName
decl_stmt|;
name|bool
name|Suppressed
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Info
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
name|strcmp
argument_list|(
name|Name
argument_list|,
name|RHS
operator|.
name|Name
argument_list|)
operator|&&
operator|!
name|strcmp
argument_list|(
name|Type
argument_list|,
name|RHS
operator|.
name|Type
argument_list|)
operator|&&
operator|!
name|strcmp
argument_list|(
name|Attributes
argument_list|,
name|RHS
operator|.
name|Attributes
argument_list|)
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Info
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
block|}
struct|;
comment|/// Builtin::Context - This holds information about target-independent and
comment|/// target-specific builtins, allowing easy queries by clients.
name|class
name|Context
block|{
specifier|const
name|Info
modifier|*
name|TSRecords
decl_stmt|;
name|unsigned
name|NumTSRecords
decl_stmt|;
name|public
label|:
name|Context
argument_list|(
specifier|const
name|TargetInfo
operator|&
name|Target
argument_list|)
expr_stmt|;
comment|/// InitializeBuiltins - Mark the identifiers for all the builtins with their
comment|/// appropriate builtin ID # and mark any non-portable builtin identifiers as
comment|/// such.
name|void
name|InitializeBuiltins
parameter_list|(
name|IdentifierTable
modifier|&
name|Table
parameter_list|,
name|bool
name|NoBuiltins
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Popular the vector with the names of all of the builtins.
name|void
name|GetBuiltinNames
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|Names
argument_list|,
name|bool
name|NoBuiltins
argument_list|)
decl_stmt|;
comment|/// Builtin::GetName - Return the identifier name for the specified builtin,
comment|/// e.g. "__builtin_abs".
specifier|const
name|char
modifier|*
name|GetName
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Name
return|;
block|}
comment|/// GetTypeString - Get the type descriptor string for the specified builtin.
specifier|const
name|char
modifier|*
name|GetTypeString
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Type
return|;
block|}
comment|/// isConst - Return true if this function has no side effects and doesn't
comment|/// read memory.
name|bool
name|isConst
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'c'
argument_list|)
operator|!=
literal|0
return|;
block|}
comment|/// isNoThrow - Return true if we know this builtin never throws an exception.
name|bool
name|isNoThrow
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'n'
argument_list|)
operator|!=
literal|0
return|;
block|}
comment|/// isNoReturn - Return true if we know this builtin never returns.
name|bool
name|isNoReturn
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'r'
argument_list|)
operator|!=
literal|0
return|;
block|}
comment|/// isLibFunction - Return true if this is a builtin for a libc/libm function,
comment|/// with a "__builtin_" prefix (e.g. __builtin_abs).
name|bool
name|isLibFunction
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'F'
argument_list|)
operator|!=
literal|0
return|;
block|}
comment|/// \brief Determines whether this builtin is a predefined libc/libm
comment|/// function, such as "malloc", where we know the signature a
comment|/// priori.
name|bool
name|isPredefinedLibFunction
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'f'
argument_list|)
operator|!=
literal|0
return|;
block|}
comment|/// \brief If this is a library function that comes from a specific
comment|/// header, retrieve that header name.
specifier|const
name|char
modifier|*
name|getHeaderName
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|HeaderName
return|;
block|}
comment|/// \brief Determine whether this builtin is like printf in its
comment|/// formatting rules and, if so, set the index to the format string
comment|/// argument and whether this function as a va_list argument.
name|bool
name|isPrintfLike
parameter_list|(
name|unsigned
name|ID
parameter_list|,
name|unsigned
modifier|&
name|FormatIdx
parameter_list|,
name|bool
modifier|&
name|HasVAListArg
parameter_list|)
function_decl|;
comment|/// hasVAListUse - Return true of the specified builtin uses __builtin_va_list
comment|/// as an operand or return type.
name|bool
name|hasVAListUse
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strpbrk
argument_list|(
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Type
argument_list|,
literal|"Aa"
argument_list|)
operator|!=
literal|0
return|;
block|}
comment|/// isConstWithoutErrno - Return true if this function has no side
comment|/// effects and doesn't read memory, except for possibly errno. Such
comment|/// functions can be const when the MathErrno lang option is
comment|/// disabled.
name|bool
name|isConstWithoutErrno
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|GetRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'e'
argument_list|)
operator|!=
literal|0
return|;
block|}
name|private
label|:
specifier|const
name|Info
modifier|&
name|GetRecord
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
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

