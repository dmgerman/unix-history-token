begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c-test.h - tool for testing libLLVM and llvm-c API -----------===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* Header file for llvm-c-test                                                *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_TEST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_TEST_H
end_define

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// helpers.c
name|void
name|llvm_tokenize_stdin
parameter_list|(
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|char
modifier|*
modifier|*
name|tokens
parameter_list|,
name|int
name|ntokens
parameter_list|)
parameter_list|)
function_decl|;
comment|// module.c
name|LLVMModuleRef
name|llvm_load_module
parameter_list|(
name|bool
name|Lazy
parameter_list|,
name|bool
name|New
parameter_list|)
function_decl|;
name|int
name|llvm_module_dump
parameter_list|(
name|bool
name|Lazy
parameter_list|,
name|bool
name|New
parameter_list|)
function_decl|;
name|int
name|llvm_module_list_functions
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|llvm_module_list_globals
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// calc.c
name|int
name|llvm_calc
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// disassemble.c
name|int
name|llvm_disassemble
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// metadata.c
name|int
name|llvm_add_named_metadata_operand
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|llvm_set_metadata
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// object.c
name|int
name|llvm_object_list_sections
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|llvm_object_list_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// targets.c
name|int
name|llvm_targets_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// echo.c
name|int
name|llvm_echo
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// diagnostic.c
name|int
name|llvm_test_diagnostic_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// attributes.c
name|int
name|llvm_test_function_attributes
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|llvm_test_callsite_attributes
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__cplusplus) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

