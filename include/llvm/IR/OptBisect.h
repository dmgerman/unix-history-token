begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------- llvm/IR/OptBisect.h - LLVM Bisect support -------------===//
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
comment|/// This file declares the interface for bisecting optimizations.
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
name|LLVM_IR_OPTBISECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_OPTBISECT_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Pass
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
comment|/// This class implements a mechanism to disable passes and individual
comment|/// optimizations at compile time based on a command line option
comment|/// (-opt-bisect-limit) in order to perform a bisecting search for
comment|/// optimization-related problems.
name|class
name|OptBisect
block|{
name|public
label|:
comment|/// \brief Default constructor, initializes the OptBisect state based on the
comment|/// -opt-bisect-limit command line argument.
comment|///
comment|/// By default, bisection is disabled.
comment|///
comment|/// Clients should not instantiate this class directly.  All access should go
comment|/// through LLVMContext.
name|OptBisect
argument_list|()
expr_stmt|;
comment|/// Checks the bisect limit to determine if the specified pass should run.
comment|///
comment|/// This function will immediate return true if bisection is disabled. If the
comment|/// bisect limit is set to -1, the function will print a message describing
comment|/// the pass and the bisect number assigned to it and return true.  Otherwise,
comment|/// the function will print a message with the bisect number assigned to the
comment|/// pass and indicating whether or not the pass will be run and return true if
comment|/// the bisect limit has not yet been exceded or false if it has.
comment|///
comment|/// Most passes should not call this routine directly.  Instead, it is called
comment|/// through a helper routine provided by the pass base class.  For instance,
comment|/// function passes should call FunctionPass::skipFunction().
name|template
operator|<
name|class
name|UnitT
operator|>
name|bool
name|shouldRunPass
argument_list|(
specifier|const
name|Pass
operator|*
name|P
argument_list|,
specifier|const
name|UnitT
operator|&
name|U
argument_list|)
expr_stmt|;
name|private
label|:
name|bool
name|checkPass
parameter_list|(
specifier|const
name|StringRef
name|PassName
parameter_list|,
specifier|const
name|StringRef
name|TargetDesc
parameter_list|)
function_decl|;
name|bool
name|BisectEnabled
init|=
name|false
decl_stmt|;
name|unsigned
name|LastBisectNum
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_OPTBISECT_H
end_comment

end_unit

