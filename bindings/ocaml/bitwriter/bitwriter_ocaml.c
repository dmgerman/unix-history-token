begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- bitwriter_ocaml.c - LLVM Ocaml Glue ---------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's ocaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/BitWriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
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
comment|/*===-- Modules -----------------------------------------------------------===*/
end_comment

begin_comment
comment|/* Llvm.llmodule -> string -> bool */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_write_bitcode_file
parameter_list|(
name|value
name|M
parameter_list|,
name|value
name|Path
parameter_list|)
block|{
name|int
name|res
init|=
name|LLVMWriteBitcodeToFile
argument_list|(
operator|(
name|LLVMModuleRef
operator|)
name|M
argument_list|,
name|String_val
argument_list|(
name|Path
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|Val_bool
argument_list|(
name|res
operator|==
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

