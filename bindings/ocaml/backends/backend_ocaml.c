begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- backend_ocaml.c - LLVM OCaml Glue -----------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
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
file|"caml/memory.h"
end_include

begin_comment
comment|/* TODO: Figure out how to call these only for targets which support them.  * LLVMInitialize ## target ## AsmPrinter();  * LLVMInitialize ## target ## AsmParser();  * LLVMInitialize ## target ## Disassembler();  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZER1
parameter_list|(
name|target
parameter_list|)
define|\
value|CAMLprim value llvm_initialize_ ## target(value Unit) {  \     LLVMInitialize ## target ## TargetInfo();              \     LLVMInitialize ## target ## Target();                  \     LLVMInitialize ## target ## TargetMC();                \     return Val_unit;                                       \   }
end_define

begin_define
define|#
directive|define
name|INITIALIZER
parameter_list|(
name|target
parameter_list|)
value|INITIALIZER1(target)
end_define

begin_macro
name|INITIALIZER
argument_list|(
argument|TARGET
argument_list|)
end_macro

end_unit

