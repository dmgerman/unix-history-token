begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Assembly/PrintModulePass.h - Printing Pass ----------*- C++ -*-===//
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
comment|// This file defines two passes to print out a module.  The PrintModulePass pass
end_comment

begin_comment
comment|// simply prints out the entire module when it is executed.  The
end_comment

begin_comment
comment|// PrintFunctionPass class is designed to be pipelined with other
end_comment

begin_comment
comment|// FunctionPass's, and prints out the functions of the module as they are
end_comment

begin_comment
comment|// processed.
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
name|LLVM_ASSEMBLY_PRINTMODULEPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ASSEMBLY_PRINTMODULEPASS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|BasicBlockPass
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// createPrintModulePass - Create and return a pass that writes the
comment|/// module to the specified raw_ostream.
name|ModulePass
modifier|*
name|createPrintModulePass
argument_list|(
name|raw_ostream
operator|*
name|OS
argument_list|,
name|bool
name|DeleteStream
operator|=
name|false
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// createPrintFunctionPass - Create and return a pass that prints
comment|/// functions to the specified raw_ostream as they are processed.
name|FunctionPass
modifier|*
name|createPrintFunctionPass
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
argument_list|,
name|raw_ostream
operator|*
name|OS
argument_list|,
name|bool
name|DeleteStream
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// createPrintBasicBlockPass - Create and return a pass that writes the
comment|/// BB to the specified raw_ostream.
name|BasicBlockPass
modifier|*
name|createPrintBasicBlockPass
argument_list|(
name|raw_ostream
operator|*
name|OS
argument_list|,
name|bool
name|DeleteStream
operator|=
name|false
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

