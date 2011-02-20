begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PTXMachineFuctionInfo.h - PTX machine function info -------*- C++ -*-==//
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
comment|// This file declares PTX-specific per-machine-function information.
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
name|PTX_MACHINE_FUNCTION_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_MACHINE_FUNCTION_INFO_H
end_define

begin_include
include|#
directive|include
file|"PTX.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PTXMachineFunctionInfo - This class is derived from MachineFunction and
comment|/// contains private PTX target-specific information for each MachineFunction.
comment|///
name|class
name|PTXMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|private
operator|:
name|bool
name|is_kernel
block|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|reg_arg
block|,
name|reg_local_var
block|;
name|unsigned
name|reg_ret
block|;
name|bool
name|_isDoneAddArg
block|;
name|public
operator|:
name|PTXMachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|is_kernel
argument_list|(
name|false
argument_list|)
block|,
name|reg_ret
argument_list|(
name|PTX
operator|::
name|NoRegister
argument_list|)
block|,
name|_isDoneAddArg
argument_list|(
argument|false
argument_list|)
block|{
name|reg_arg
operator|.
name|reserve
argument_list|(
literal|8
argument_list|)
block|;
name|reg_local_var
operator|.
name|reserve
argument_list|(
literal|32
argument_list|)
block|;     }
name|void
name|setKernel
argument_list|(
argument|bool _is_kernel=true
argument_list|)
block|{
name|is_kernel
operator|=
name|_is_kernel
block|; }
name|void
name|addArgReg
argument_list|(
argument|unsigned reg
argument_list|)
block|{
name|reg_arg
operator|.
name|push_back
argument_list|(
name|reg
argument_list|)
block|; }
name|void
name|addLocalVarReg
argument_list|(
argument|unsigned reg
argument_list|)
block|{
name|reg_local_var
operator|.
name|push_back
argument_list|(
name|reg
argument_list|)
block|; }
name|void
name|setRetReg
argument_list|(
argument|unsigned reg
argument_list|)
block|{
name|reg_ret
operator|=
name|reg
block|; }
name|void
name|doneAddArg
argument_list|(
argument|void
argument_list|)
block|{
name|std
operator|::
name|sort
argument_list|(
name|reg_arg
operator|.
name|begin
argument_list|()
argument_list|,
name|reg_arg
operator|.
name|end
argument_list|()
argument_list|)
block|;
name|_isDoneAddArg
operator|=
name|true
block|;   }
name|void
name|doneAddLocalVar
argument_list|(
argument|void
argument_list|)
block|{
name|std
operator|::
name|sort
argument_list|(
name|reg_local_var
operator|.
name|begin
argument_list|()
argument_list|,
name|reg_local_var
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
name|bool
name|isDoneAddArg
argument_list|(
argument|void
argument_list|)
block|{
return|return
name|_isDoneAddArg
return|;
block|}
name|bool
name|isKernel
argument_list|()
specifier|const
block|{
return|return
name|is_kernel
return|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
name|reg_iterator
expr_stmt|;
name|bool
name|argRegEmpty
argument_list|()
specifier|const
block|{
return|return
name|reg_arg
operator|.
name|empty
argument_list|()
return|;
block|}
name|int
name|getNumArg
argument_list|()
specifier|const
block|{
return|return
name|reg_arg
operator|.
name|size
argument_list|()
return|;
block|}
name|reg_iterator
name|argRegBegin
argument_list|()
specifier|const
block|{
return|return
name|reg_arg
operator|.
name|begin
argument_list|()
return|;
block|}
name|reg_iterator
name|argRegEnd
argument_list|()
specifier|const
block|{
return|return
name|reg_arg
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|localVarRegEmpty
argument_list|()
specifier|const
block|{
return|return
name|reg_local_var
operator|.
name|empty
argument_list|()
return|;
block|}
name|reg_iterator
name|localVarRegBegin
argument_list|()
specifier|const
block|{
return|return
name|reg_local_var
operator|.
name|begin
argument_list|()
return|;
block|}
name|reg_iterator
name|localVarRegEnd
argument_list|()
specifier|const
block|{
return|return
name|reg_local_var
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|retReg
argument_list|()
specifier|const
block|{
return|return
name|reg_ret
return|;
block|}
name|bool
name|isArgReg
argument_list|(
argument|unsigned reg
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|binary_search
argument_list|(
name|reg_arg
operator|.
name|begin
argument_list|()
argument_list|,
name|reg_arg
operator|.
name|end
argument_list|()
argument_list|,
name|reg
argument_list|)
return|;
block|}
name|bool
name|isLocalVarReg
argument_list|(
argument|unsigned reg
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|binary_search
argument_list|(
name|reg_local_var
operator|.
name|begin
argument_list|()
argument_list|,
name|reg_local_var
operator|.
name|end
argument_list|()
argument_list|,
name|reg
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|// class PTXMachineFunctionInfo
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PTX_MACHINE_FUNCTION_INFO_H
end_comment

end_unit

