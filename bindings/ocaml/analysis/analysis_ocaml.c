begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- analysis_ocaml.c - LLVM OCaml Glue ----------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Analysis.h"
end_include

begin_include
include|#
directive|include
file|"caml/alloc.h"
end_include

begin_include
include|#
directive|include
file|"caml/mlvalues.h"
end_include

begin_include
include|#
directive|include
file|"caml/memory.h"
end_include

begin_comment
comment|/* Llvm.llmodule -> string option */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_verify_module
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|)
block|{
name|CAMLparam0
argument_list|()
expr_stmt|;
name|CAMLlocal2
argument_list|(
name|String
argument_list|,
name|Option
argument_list|)
expr_stmt|;
name|char
modifier|*
name|Message
decl_stmt|;
name|int
name|Result
init|=
name|LLVMVerifyModule
argument_list|(
name|M
argument_list|,
name|LLVMReturnStatusAction
argument_list|,
operator|&
name|Message
argument_list|)
decl_stmt|;
if|if
condition|(
literal|0
operator|==
name|Result
condition|)
block|{
name|Option
operator|=
name|Val_int
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Option
operator|=
name|alloc
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|String
operator|=
name|copy_string
argument_list|(
name|Message
argument_list|)
expr_stmt|;
name|Store_field
argument_list|(
name|Option
argument_list|,
literal|0
argument_list|,
name|String
argument_list|)
expr_stmt|;
block|}
name|LLVMDisposeMessage
argument_list|(
name|Message
argument_list|)
expr_stmt|;
name|CAMLreturn
argument_list|(
name|Option
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Llvm.llvalue -> bool */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_verify_function
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|)
block|{
return|return
name|Val_bool
argument_list|(
name|LLVMVerifyFunction
argument_list|(
name|Fn
argument_list|,
name|LLVMReturnStatusAction
argument_list|)
operator|==
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Llvm.llmodule -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_assert_valid_module
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|)
block|{
name|LLVMVerifyModule
argument_list|(
name|M
argument_list|,
name|LLVMAbortProcessAction
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* Llvm.llvalue -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_assert_valid_function
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|)
block|{
name|LLVMVerifyFunction
argument_list|(
name|Fn
argument_list|,
name|LLVMAbortProcessAction
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* Llvm.llvalue -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_view_function_cfg
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|)
block|{
name|LLVMViewFunctionCFG
argument_list|(
name|Fn
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* Llvm.llvalue -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_view_function_cfg_only
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|)
block|{
name|LLVMViewFunctionCFGOnly
argument_list|(
name|Fn
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

end_unit

