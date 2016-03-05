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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines enum values for all the target-independent builtin
end_comment

begin_comment
comment|/// functions.
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
file|"llvm/ADT/ArrayRef.h"
end_include

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
name|class
name|LangOptions
decl_stmt|;
enum|enum
name|LanguageID
block|{
name|GNU_LANG
init|=
literal|0x1
block|,
comment|// builtin requires GNU mode.
name|C_LANG
init|=
literal|0x2
block|,
comment|// builtin for c only.
name|CXX_LANG
init|=
literal|0x4
block|,
comment|// builtin for cplusplus only.
name|OBJC_LANG
init|=
literal|0x8
block|,
comment|// builtin for objective-c and objective-c++
name|MS_LANG
init|=
literal|0x10
block|,
comment|// builtin requires MS mode.
name|ALL_LANGUAGES
init|=
name|C_LANG
operator||
name|CXX_LANG
operator||
name|OBJC_LANG
block|,
comment|// builtin for all languages.
name|ALL_GNU_LANGUAGES
init|=
name|ALL_LANGUAGES
operator||
name|GNU_LANG
block|,
comment|// builtin requires GNU mode.
name|ALL_MS_LANGUAGES
init|=
name|ALL_LANGUAGES
operator||
name|MS_LANG
comment|// builtin requires MS mode.
block|}
enum|;
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
name|LanguageID
name|Langs
decl_stmt|;
specifier|const
name|char
modifier|*
name|Features
decl_stmt|;
block|}
struct|;
comment|/// \brief Holds information about both target-independent and
comment|/// target-specific builtins, allowing easy queries by clients.
comment|///
comment|/// Builtins from an optional auxiliary target are stored in
comment|/// AuxTSRecords. Their IDs are shifted up by TSRecords.size() and need to
comment|/// be translated back with getAuxBuiltinID() before use.
name|class
name|Context
block|{
name|llvm
operator|::
name|ArrayRef
operator|<
name|Info
operator|>
name|TSRecords
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|Info
operator|>
name|AuxTSRecords
expr_stmt|;
name|public
label|:
name|Context
argument_list|()
block|{}
comment|/// \brief Perform target-specific initialization
comment|/// \param AuxTarget Target info to incorporate builtins from. May be nullptr.
name|void
name|InitializeTarget
parameter_list|(
specifier|const
name|TargetInfo
modifier|&
name|Target
parameter_list|,
specifier|const
name|TargetInfo
modifier|*
name|AuxTarget
parameter_list|)
function_decl|;
comment|/// \brief Mark the identifiers for all the builtins with their
comment|/// appropriate builtin ID # and mark any non-portable builtin identifiers as
comment|/// such.
name|void
name|initializeBuiltins
parameter_list|(
name|IdentifierTable
modifier|&
name|Table
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|)
function_decl|;
comment|/// \brief Return the identifier name for the specified builtin,
comment|/// e.g. "__builtin_abs".
specifier|const
name|char
modifier|*
name|getName
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Name
return|;
block|}
comment|/// \brief Get the type descriptor string for the specified builtin.
specifier|const
name|char
modifier|*
name|getTypeString
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Type
return|;
block|}
comment|/// \brief Return true if this function is a target-specific builtin
name|bool
name|isTSBuiltin
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|ID
operator|>=
name|Builtin
operator|::
name|FirstTSBuiltin
return|;
block|}
comment|/// \brief Return true if this function has no side effects and doesn't
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
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'c'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Return true if we know this builtin never throws an exception.
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
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'n'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Return true if we know this builtin never returns.
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
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'r'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Return true if we know this builtin can return twice.
name|bool
name|isReturnsTwice
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'j'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Returns true if this builtin does not perform the side-effects
comment|/// of its arguments.
name|bool
name|isUnevaluated
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'u'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Return true if this is a builtin for a libc/libm function,
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
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'F'
argument_list|)
operator|!=
name|nullptr
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
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'f'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Determines whether this builtin is a predefined compiler-rt/libgcc
comment|/// function, such as "__clear_cache", where we know the signature a
comment|/// priori.
name|bool
name|isPredefinedRuntimeFunction
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'i'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Determines whether this builtin has custom typechecking.
name|bool
name|hasCustomTypechecking
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'t'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Determines whether this builtin has a result or any arguments which
comment|/// are pointer types.
name|bool
name|hasPtrArgsOrResult
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|strchr
argument_list|(
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Type
argument_list|,
literal|'*'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Completely forget that the given ID was ever considered a builtin,
comment|/// e.g., because the user provided a conflicting signature.
name|void
name|forgetBuiltin
parameter_list|(
name|unsigned
name|ID
parameter_list|,
name|IdentifierTable
modifier|&
name|Table
parameter_list|)
function_decl|;
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
name|getRecord
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
comment|/// \brief Determine whether this builtin is like scanf in its
comment|/// formatting rules and, if so, set the index to the format string
comment|/// argument and whether this function as a va_list argument.
name|bool
name|isScanfLike
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
comment|/// \brief Return true if this function has no side effects and doesn't
comment|/// read memory, except for possibly errno.
comment|///
comment|/// Such functions can be const when the MathErrno lang option is disabled.
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
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Attributes
argument_list|,
literal|'e'
argument_list|)
operator|!=
name|nullptr
return|;
block|}
specifier|const
name|char
modifier|*
name|getRequiredFeatures
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|getRecord
argument_list|(
name|ID
argument_list|)
operator|.
name|Features
return|;
block|}
comment|/// \brief Return true if builtin ID belongs to AuxTarget.
name|bool
name|isAuxBuiltinID
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|ID
operator|>=
operator|(
name|Builtin
operator|::
name|FirstTSBuiltin
operator|+
name|TSRecords
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
comment|/// Return real buitin ID (i.e. ID it would have furing compilation
comment|/// for AuxTarget).
name|unsigned
name|getAuxBuiltinID
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
return|return
name|ID
operator|-
name|TSRecords
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Returns true if this is a libc/libm function without the '__builtin_'
comment|/// prefix.
specifier|static
name|bool
name|isBuiltinFunc
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
name|private
label|:
specifier|const
name|Info
modifier|&
name|getRecord
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Is this builtin supported according to the given language options?
name|bool
name|builtinIsSupported
argument_list|(
specifier|const
name|Builtin
operator|::
name|Info
operator|&
name|BuiltinInfo
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
decl_stmt|;
comment|/// \brief Helper function for isPrintfLike and isScanfLike.
name|bool
name|isLike
argument_list|(
name|unsigned
name|ID
argument_list|,
name|unsigned
operator|&
name|FormatIdx
argument_list|,
name|bool
operator|&
name|HasVAListArg
argument_list|,
specifier|const
name|char
operator|*
name|Fmt
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|/// \brief Kinds of BuiltinTemplateDecl.
enum|enum
name|BuiltinTemplateKind
enum|:
name|int
block|{
comment|/// \brief This names the __make_integer_seq BuiltinTemplateDecl.
name|BTK__make_integer_seq
block|}
enum|;
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

