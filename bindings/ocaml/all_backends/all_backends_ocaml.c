begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- all_backends_ocaml.c - LLVM OCaml Glue ------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Target.h"
end_include

begin_include
include|#
directive|include
file|"caml/alloc.h"
end_include

begin_include
include|#
directive|include
file|"caml/fail.h"
end_include

begin_include
include|#
directive|include
file|"caml/memory.h"
end_include

begin_include
include|#
directive|include
file|"caml/custom.h"
end_include

begin_comment
comment|/* unit -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_initialize_all
parameter_list|(
name|value
name|Unit
parameter_list|)
block|{
name|LLVMInitializeAllTargetInfos
argument_list|()
expr_stmt|;
name|LLVMInitializeAllTargets
argument_list|()
expr_stmt|;
name|LLVMInitializeAllTargetMCs
argument_list|()
expr_stmt|;
name|LLVMInitializeAllAsmPrinters
argument_list|()
expr_stmt|;
name|LLVMInitializeAllAsmParsers
argument_list|()
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

end_unit

