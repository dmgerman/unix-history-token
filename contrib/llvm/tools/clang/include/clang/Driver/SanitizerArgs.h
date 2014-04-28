begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SanitizerArgs.h - Arguments for sanitizer tools  -------*- C++ -*-===//
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
name|CLANG_LIB_DRIVER_SANITIZERARGS_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_LIB_DRIVER_SANITIZERARGS_H_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Arg.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/ArgList.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|Driver
decl_stmt|;
name|class
name|ToolChain
decl_stmt|;
name|class
name|SanitizerArgs
block|{
comment|/// Assign ordinals to sanitizer flags. We'll use the ordinal values as
comment|/// bit positions within \c Kind.
enum|enum
name|SanitizeOrdinal
block|{
define|#
directive|define
name|SANITIZER
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|)
value|SO_##ID,
define|#
directive|define
name|SANITIZER_GROUP
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|,
name|ALIAS
parameter_list|)
value|SO_##ID##Group,
include|#
directive|include
file|"clang/Basic/Sanitizers.def"
name|SO_Count
block|}
enum|;
comment|/// Bugs to catch at runtime.
enum|enum
name|SanitizeKind
block|{
define|#
directive|define
name|SANITIZER
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|)
value|ID = 1<< SO_##ID,
define|#
directive|define
name|SANITIZER_GROUP
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|,
name|ALIAS
parameter_list|)
define|\
value|ID = ALIAS, ID##Group = 1<< SO_##ID##Group,
include|#
directive|include
file|"clang/Basic/Sanitizers.def"
name|NeedsAsanRt
init|=
name|Address
block|,
name|NeedsTsanRt
init|=
name|Thread
block|,
name|NeedsMsanRt
init|=
name|Memory
block|,
name|NeedsDfsanRt
init|=
name|DataFlow
block|,
name|NeedsLeakDetection
init|=
name|Leak
block|,
name|NeedsUbsanRt
init|=
name|Undefined
operator||
name|Integer
block|,
name|NotAllowedWithTrap
init|=
name|Vptr
block|,
name|HasZeroBaseShadow
init|=
name|Thread
operator||
name|Memory
operator||
name|DataFlow
block|}
enum|;
name|unsigned
name|Kind
decl_stmt|;
name|std
operator|::
name|string
name|BlacklistFile
expr_stmt|;
name|bool
name|MsanTrackOrigins
decl_stmt|;
name|bool
name|AsanZeroBaseShadow
decl_stmt|;
name|bool
name|UbsanTrapOnError
decl_stmt|;
name|public
label|:
name|SanitizerArgs
argument_list|()
expr_stmt|;
comment|/// Parses the sanitizer arguments from an argument list.
name|SanitizerArgs
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|)
expr_stmt|;
name|bool
name|needsAsanRt
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|&
name|NeedsAsanRt
return|;
block|}
name|bool
name|needsTsanRt
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|&
name|NeedsTsanRt
return|;
block|}
name|bool
name|needsMsanRt
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|&
name|NeedsMsanRt
return|;
block|}
name|bool
name|needsLeakDetection
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|&
name|NeedsLeakDetection
return|;
block|}
name|bool
name|needsLsanRt
argument_list|()
specifier|const
block|{
return|return
name|needsLeakDetection
argument_list|()
operator|&&
operator|!
name|needsAsanRt
argument_list|()
return|;
block|}
name|bool
name|needsUbsanRt
argument_list|()
specifier|const
block|{
return|return
operator|!
name|UbsanTrapOnError
operator|&&
operator|(
name|Kind
operator|&
name|NeedsUbsanRt
operator|)
return|;
block|}
name|bool
name|needsDfsanRt
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|&
name|NeedsDfsanRt
return|;
block|}
name|bool
name|sanitizesVptr
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|&
name|Vptr
return|;
block|}
name|bool
name|notAllowedWithTrap
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|&
name|NotAllowedWithTrap
return|;
block|}
name|bool
name|hasZeroBaseShadow
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Kind
operator|&
name|HasZeroBaseShadow
operator|)
operator|||
name|AsanZeroBaseShadow
return|;
block|}
name|void
name|addArgs
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|CmdArgs
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// Parse a single value from a -fsanitize= or -fno-sanitize= value list.
comment|/// Returns OR of members of the \c SanitizeKind enumeration, or \c 0
comment|/// if \p Value is not known.
specifier|static
name|unsigned
name|parse
parameter_list|(
specifier|const
name|char
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// Parse a -fsanitize= or -fno-sanitize= argument's values, diagnosing any
comment|/// invalid components.
specifier|static
name|unsigned
name|parse
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|*
name|A
argument_list|,
name|bool
name|DiagnoseErrors
argument_list|)
decl_stmt|;
comment|/// Parse a single flag of the form -f[no]sanitize=, or
comment|/// -f*-sanitizer. Sets the masks defining required change of Kind value.
comment|/// Returns true if the flag was parsed successfully.
specifier|static
name|bool
name|parse
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|*
name|A
argument_list|,
name|unsigned
operator|&
name|Add
argument_list|,
name|unsigned
operator|&
name|Remove
argument_list|,
name|bool
name|DiagnoseErrors
argument_list|)
decl_stmt|;
comment|/// Produce an argument string from ArgList \p Args, which shows how it
comment|/// provides a sanitizer kind in \p Mask. For example, the argument list
comment|/// "-fsanitize=thread,vptr -faddress-sanitizer" with mask \c NeedsUbsanRt
comment|/// would produce "-fsanitize=vptr".
specifier|static
name|std
operator|::
name|string
name|lastArgumentForKind
argument_list|(
argument|const Driver&D
argument_list|,
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|unsigned Kind
argument_list|)
expr_stmt|;
comment|/// Produce an argument string from argument \p A, which shows how it provides
comment|/// a value in \p Mask. For instance, the argument
comment|/// "-fsanitize=address,alignment" with mask \c NeedsUbsanRt would produce
comment|/// "-fsanitize=alignment".
specifier|static
name|std
operator|::
name|string
name|describeSanitizeArg
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|const llvm::opt::Arg *A
argument_list|,
argument|unsigned Mask
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|getDefaultBlacklistForKind
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
name|unsigned
name|Kind
argument_list|,
name|std
operator|::
name|string
operator|&
name|BLPath
argument_list|)
decl_stmt|;
comment|/// Return the smallest superset of sanitizer set \p Kinds such that each
comment|/// member of each group whose flag is set in \p Kinds has its flag set in the
comment|/// result.
specifier|static
name|unsigned
name|expandGroups
parameter_list|(
name|unsigned
name|Kinds
parameter_list|)
function_decl|;
comment|/// Return the subset of \p Kinds supported by toolchain \p TC.  If
comment|/// \p DiagnoseErrors is true, produce an error diagnostic for each sanitizer
comment|/// removed from \p Kinds.
specifier|static
name|unsigned
name|filterUnsupportedKinds
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|,
name|unsigned
name|Kinds
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|*
name|A
argument_list|,
name|bool
name|DiagnoseErrors
argument_list|,
name|unsigned
operator|&
name|DiagnosedKinds
argument_list|)
decl_stmt|;
comment|/// The flags in \p Mask are unsupported by \p TC.  If present in \p Kinds,
comment|/// remove them and produce an error diagnostic referring to \p A if
comment|/// \p DiagnoseErrors is true.
specifier|static
name|void
name|filterUnsupportedMask
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|,
name|unsigned
operator|&
name|Kinds
argument_list|,
name|unsigned
name|Mask
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|*
name|A
argument_list|,
name|bool
name|DiagnoseErrors
argument_list|,
name|unsigned
operator|&
name|DiagnosedKinds
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace driver
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CLANG_LIB_DRIVER_SANITIZERARGS_H_
end_comment

end_unit

