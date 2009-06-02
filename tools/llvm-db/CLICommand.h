begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CLICommand.h - Classes used to represent commands --------*- C++ -*-===//
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
comment|// This file defines a small class hierarchy used to represent the various types
end_comment

begin_comment
comment|// of commands in the CLI debugger front-end.
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
name|CLICOMMAND_H
end_ifndef

begin_define
define|#
directive|define
name|CLICOMMAND_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CLIDebugger
decl_stmt|;
comment|/// CLICommand - Base class of the hierarchy, used to provide the abstract
comment|/// interface common to all commands.
comment|///
name|class
name|CLICommand
block|{
comment|/// ShortHelp, LongHelp - The short and long helps strings printed for the
comment|/// command.  The ShortHelp string should be a single line of text without a
comment|/// newline.  The LongHelp string should be a full description with
comment|/// terminating newline.
name|std
operator|::
name|string
name|ShortHelp
operator|,
name|LongHelp
expr_stmt|;
comment|/// RefCount - This contains the number of entries in the CLIDebugger
comment|/// CommandTable that points to this command.
name|unsigned
name|RefCount
decl_stmt|;
comment|/// OptionNames - This contains a list of names for the option.  Keeping
comment|/// track of this is done just to make the help output more helpful.
comment|///
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|OptionNames
expr_stmt|;
name|public
label|:
name|CLICommand
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|SH
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|LH
argument_list|)
operator|:
name|ShortHelp
argument_list|(
name|SH
argument_list|)
operator|,
name|LongHelp
argument_list|(
name|LH
argument_list|)
operator|,
name|RefCount
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|CLICommand
argument_list|()
block|{}
comment|/// addRef/dropRef - Implement a simple reference counting scheme to make
comment|/// sure we delete commands that are no longer used.
name|void
name|addRef
argument_list|()
block|{
operator|++
name|RefCount
block|; }
name|void
name|dropRef
argument_list|()
block|{
if|if
condition|(
operator|--
name|RefCount
operator|==
literal|0
condition|)
name|delete
name|this
decl_stmt|;
block|}
comment|/// getPrimaryOptionName - Return the first name the option was added under.
comment|/// This is the name we report for the option in the help output.
name|std
operator|::
name|string
name|getPrimaryOptionName
argument_list|()
specifier|const
block|{
return|return
name|OptionNames
operator|.
name|empty
argument_list|()
operator|?
literal|""
operator|:
name|OptionNames
index|[
literal|0
index|]
return|;
block|}
comment|/// getOptionName - Return all of the names the option is registered as.
comment|///
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|getOptionNames
argument_list|()
specifier|const
block|{
return|return
name|OptionNames
return|;
block|}
comment|/// addOptionName - Add a name that this option is known as.
comment|///
name|void
name|addOptionName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|{
name|OptionNames
operator|.
name|push_back
argument_list|(
name|Name
argument_list|)
expr_stmt|;
block|}
comment|/// removeOptionName - Eliminate one of the names for this option.
comment|///
name|void
name|removeOptionName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|{
name|unsigned
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|OptionNames
index|[
name|i
index|]
operator|!=
name|Name
condition|;
operator|++
name|i
control|)
name|assert
argument_list|(
name|i
operator|+
literal|1
operator|<
name|OptionNames
operator|.
name|size
argument_list|()
operator|&&
literal|"Didn't find option name!"
argument_list|)
expr_stmt|;
name|OptionNames
operator|.
name|erase
argument_list|(
name|OptionNames
operator|.
name|begin
argument_list|()
operator|+
name|i
argument_list|)
expr_stmt|;
block|}
comment|/// getShortHelp - Return the short help string for this command.
comment|///
specifier|const
name|std
operator|::
name|string
operator|&
name|getShortHelp
argument_list|()
block|{
return|return
name|ShortHelp
return|;
block|}
comment|/// getLongHelp - Return the long help string for this command, if it
comment|/// exists.
specifier|const
name|std
operator|::
name|string
operator|&
name|getLongHelp
argument_list|()
block|{
return|return
name|LongHelp
return|;
block|}
name|virtual
name|void
name|runCommand
argument_list|(
name|CLIDebugger
operator|&
name|D
argument_list|,
name|std
operator|::
name|string
operator|&
name|Arguments
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// BuiltinCLICommand - This class represents commands that are built directly
comment|/// into the debugger.
name|class
name|BuiltinCLICommand
range|:
name|public
name|CLICommand
block|{
comment|// Impl - Pointer to the method that implements the command
name|void
argument_list|(
name|CLIDebugger
operator|::
operator|*
name|Impl
argument_list|)
argument_list|(
name|std
operator|::
name|string
operator|&
argument_list|)
block|;
name|public
operator|:
name|BuiltinCLICommand
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ShortHelp
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|LongHelp
argument_list|,
name|void
argument_list|(
name|CLIDebugger
operator|::
operator|*
name|impl
argument_list|)
argument_list|(
name|std
operator|::
name|string
operator|&
argument_list|)
argument_list|)
operator|:
name|CLICommand
argument_list|(
name|ShortHelp
argument_list|,
name|LongHelp
argument_list|)
block|,
name|Impl
argument_list|(
argument|impl
argument_list|)
block|{}
name|void
name|runCommand
argument_list|(
argument|CLIDebugger&D
argument_list|,
argument|std::string&Arguments
argument_list|)
block|{
operator|(
name|D
operator|.*
name|Impl
operator|)
operator|(
name|Arguments
operator|)
block|;     }
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

