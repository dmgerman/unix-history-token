begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- InputInfo.h - Input Source& Type Information ----------*- C++ -*-===//
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
name|CLANG_LIB_DRIVER_INPUTINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_LIB_DRIVER_INPUTINFO_H_
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Arg.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
comment|/// InputInfo - Wrapper for information about an input source.
name|class
name|InputInfo
block|{
comment|// FIXME: The distinction between filenames and inputarg here is
comment|// gross; we should probably drop the idea of a "linker
comment|// input". Doing so means tweaking pipelining to still create link
comment|// steps when it sees linker inputs (but not treat them as
comment|// arguments), and making sure that arguments get rendered
comment|// correctly.
enum|enum
name|Class
block|{
name|Nothing
block|,
name|Filename
block|,
name|InputArg
block|,
name|Pipe
block|}
enum|;
union|union
block|{
specifier|const
name|char
modifier|*
name|Filename
decl_stmt|;
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|*
name|InputArg
expr_stmt|;
block|}
name|Data
union|;
name|Class
name|Kind
decl_stmt|;
name|types
operator|::
name|ID
name|Type
expr_stmt|;
specifier|const
name|char
modifier|*
name|BaseInput
decl_stmt|;
name|public
label|:
name|InputInfo
argument_list|()
block|{}
name|InputInfo
argument_list|(
argument|types::ID _Type
argument_list|,
argument|const char *_BaseInput
argument_list|)
block|:
name|Kind
argument_list|(
name|Nothing
argument_list|)
operator|,
name|Type
argument_list|(
name|_Type
argument_list|)
operator|,
name|BaseInput
argument_list|(
argument|_BaseInput
argument_list|)
block|{   }
name|InputInfo
argument_list|(
argument|const char *_Filename
argument_list|,
argument|types::ID _Type
argument_list|,
argument|const char *_BaseInput
argument_list|)
operator|:
name|Kind
argument_list|(
name|Filename
argument_list|)
operator|,
name|Type
argument_list|(
name|_Type
argument_list|)
operator|,
name|BaseInput
argument_list|(
argument|_BaseInput
argument_list|)
block|{
name|Data
operator|.
name|Filename
operator|=
name|_Filename
block|;   }
name|InputInfo
argument_list|(
argument|const llvm::opt::Arg *_InputArg
argument_list|,
argument|types::ID _Type
argument_list|,
argument|const char *_BaseInput
argument_list|)
operator|:
name|Kind
argument_list|(
name|InputArg
argument_list|)
operator|,
name|Type
argument_list|(
name|_Type
argument_list|)
operator|,
name|BaseInput
argument_list|(
argument|_BaseInput
argument_list|)
block|{
name|Data
operator|.
name|InputArg
operator|=
name|_InputArg
block|;   }
name|bool
name|isNothing
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Nothing
return|;
block|}
name|bool
name|isFilename
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Filename
return|;
block|}
name|bool
name|isInputArg
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|InputArg
return|;
block|}
name|types
operator|::
name|ID
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
specifier|const
name|char
operator|*
name|getBaseInput
argument_list|()
specifier|const
block|{
return|return
name|BaseInput
return|;
block|}
specifier|const
name|char
operator|*
name|getFilename
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isFilename
argument_list|()
operator|&&
literal|"Invalid accessor."
argument_list|)
block|;
return|return
name|Data
operator|.
name|Filename
return|;
block|}
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|&
name|getInputArg
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isInputArg
argument_list|()
operator|&&
literal|"Invalid accessor."
argument_list|)
block|;
return|return
operator|*
name|Data
operator|.
name|InputArg
return|;
block|}
comment|/// getAsString - Return a string name for this input, for
comment|/// debugging.
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isFilename
argument_list|()
condition|)
return|return
name|std
operator|::
name|string
argument_list|(
literal|"\""
argument_list|)
operator|+
name|getFilename
argument_list|()
operator|+
literal|'"'
return|;
elseif|else
if|if
condition|(
name|isInputArg
argument_list|()
condition|)
return|return
literal|"(input arg)"
return|;
else|else
return|return
literal|"(nothing)"
return|;
block|}
block|}
empty_stmt|;
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

