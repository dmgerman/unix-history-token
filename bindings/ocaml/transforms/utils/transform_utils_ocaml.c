begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- vectorize_ocaml.c - LLVM OCaml Glue ---------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
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
comment|/*  * Do not move directly into external. This function is here to pull in  * -lLLVMTransformUtils, which would otherwise be not linked on static builds,  * as ld can't see the reference from OCaml code.  */
end_comment

begin_comment
comment|/* llmodule -> llmodule */
end_comment

begin_function
name|CAMLprim
name|LLVMModuleRef
name|llvm_clone_module
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|)
block|{
return|return
name|LLVMCloneModule
argument_list|(
name|M
argument_list|)
return|;
block|}
end_function

end_unit

