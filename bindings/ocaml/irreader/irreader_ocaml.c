begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- irreader_ocaml.c - LLVM OCaml Glue ----------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/IRReader.h"
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
comment|/* Llvm.llcontext -> Llvm.llmemorybuffer -> Llvm.llmodule */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_parse_ir
parameter_list|(
name|LLVMContextRef
name|C
parameter_list|,
name|LLVMMemoryBufferRef
name|MemBuf
parameter_list|)
block|{
name|CAMLparam0
argument_list|()
expr_stmt|;
name|CAMLlocal2
argument_list|(
name|Variant
argument_list|,
name|MessageVal
argument_list|)
expr_stmt|;
name|LLVMModuleRef
name|M
decl_stmt|;
name|char
modifier|*
name|Message
decl_stmt|;
if|if
condition|(
name|LLVMParseIRInContext
argument_list|(
name|C
argument_list|,
name|MemBuf
argument_list|,
operator|&
name|M
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
literal|"Llvm_irreader.Error"
argument_list|)
argument_list|,
name|Message
argument_list|)
expr_stmt|;
name|CAMLreturn
argument_list|(
operator|(
name|value
operator|)
name|M
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

