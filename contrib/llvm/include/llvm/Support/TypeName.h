begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeName.h -----------------------------------------------*- C++ -*-===//
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
name|LLVM_SUPPORT_TYPENAME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TYPENAME_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// We provide a function which tries to compute the (demangled) name of a type
comment|/// statically.
comment|///
comment|/// This routine may fail on some platforms or for particularly unusual types.
comment|/// Do not use it for anything other than logging and debugging aids. It isn't
comment|/// portable or dependendable in any real sense.
comment|///
comment|/// The returned StringRef will point into a static storage duration string.
comment|/// However, it may not be null terminated and may be some strangely aligned
comment|/// inner substring of a larger string.
name|template
operator|<
name|typename
name|DesiredTypeName
operator|>
specifier|inline
name|StringRef
name|getTypeName
argument_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
name|StringRef
name|Name
operator|=
name|__PRETTY_FUNCTION__
block|;
name|StringRef
name|Key
operator|=
literal|"DesiredTypeName = "
block|;
name|Name
operator|=
name|Name
operator|.
name|substr
argument_list|(
name|Name
operator|.
name|find
argument_list|(
name|Key
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|Name
operator|.
name|empty
argument_list|()
operator|&&
literal|"Unable to find the template parameter!"
argument_list|)
block|;
name|Name
operator|=
name|Name
operator|.
name|drop_front
argument_list|(
name|Key
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
name|Name
operator|.
name|endswith
argument_list|(
literal|"]"
argument_list|)
operator|&&
literal|"Name doesn't end in the substitution key!"
argument_list|)
block|;
return|return
name|Name
operator|.
name|drop_back
argument_list|(
literal|1
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
name|StringRef
name|Name
operator|=
name|__FUNCSIG__
expr_stmt|;
name|StringRef
name|Key
init|=
literal|"getTypeName<"
decl_stmt|;
name|Name
operator|=
name|Name
operator|.
name|substr
argument_list|(
name|Name
operator|.
name|find
argument_list|(
name|Key
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|Name
operator|.
name|empty
argument_list|()
operator|&&
literal|"Unable to find the function name!"
argument_list|)
expr_stmt|;
name|Name
operator|=
name|Name
operator|.
name|drop_front
argument_list|(
name|Key
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|StringRef
name|Prefix
range|:
block|{
literal|"class "
block|,
literal|"struct "
block|,
literal|"union "
block|,
literal|"enum "
block|}
control|)
if|if
condition|(
name|Name
operator|.
name|startswith
argument_list|(
name|Prefix
argument_list|)
condition|)
block|{
name|Name
operator|=
name|Name
operator|.
name|drop_front
argument_list|(
name|Prefix
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
name|auto
name|AnglePos
init|=
name|Name
operator|.
name|rfind
argument_list|(
literal|'>'
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|AnglePos
operator|!=
name|StringRef
operator|::
name|npos
operator|&&
literal|"Unable to find the closing '>'!"
argument_list|)
expr_stmt|;
return|return
name|Name
operator|.
name|substr
argument_list|(
literal|0
argument_list|,
name|AnglePos
argument_list|)
return|;
else|#
directive|else
comment|// No known technique for statically extracting a type name on this compiler.
comment|// We return a string that is unlikely to look like any type in LLVM.
return|return
literal|"UNKNOWN_TYPE"
return|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

