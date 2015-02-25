begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- linker_ocaml.c - LLVM OCaml Glue ------------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Linker.h"
end_include

begin_include
include|#
directive|include
file|"caml/alloc.h"
end_include

begin_include
include|#
directive|include
file|"caml/memory.h"
end_include

begin_include
include|#
directive|include
file|"caml/fail.h"
end_include

begin_include
include|#
directive|include
file|"caml/callback.h"
end_include

begin_function_decl
name|void
name|llvm_raise
parameter_list|(
name|value
name|Prototype
parameter_list|,
name|char
modifier|*
name|Message
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* llmodule -> llmodule -> Mode.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_link_modules
parameter_list|(
name|LLVMModuleRef
name|Dst
parameter_list|,
name|LLVMModuleRef
name|Src
parameter_list|,
name|value
name|Mode
parameter_list|)
block|{
name|char
modifier|*
name|Message
decl_stmt|;
if|if
condition|(
name|LLVMLinkModules
argument_list|(
name|Dst
argument_list|,
name|Src
argument_list|,
name|Int_val
argument_list|(
name|Mode
argument_list|)
argument_list|,
operator|&
name|Message
argument_list|)
condition|)
name|llvm_raise
argument_list|(
operator|*
name|caml_named_value
argument_list|(
literal|"Llvm_linker.Error"
argument_list|)
argument_list|,
name|Message
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

end_unit

