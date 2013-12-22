begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- vectorize_ocaml.c - LLVM OCaml Glue ---------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Transforms/Vectorize.h"
end_include

begin_include
include|#
directive|include
file|"caml/mlvalues.h"
end_include

begin_include
include|#
directive|include
file|"caml/misc.h"
end_include

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_bb_vectorize
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddBBVectorizePass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_loop_vectorize
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddLoopVectorizePass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_slp_vectorize
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddSLPVectorizePass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

end_unit

