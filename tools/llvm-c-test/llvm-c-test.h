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

begin_comment
comment|// helpers.c
end_comment

begin_function_decl
name|void
name|tokenize_stdin
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
end_function_decl

begin_comment
comment|// module.c
end_comment

begin_function_decl
name|int
name|module_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|module_list_functions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|module_list_globals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// calc.c
end_comment

begin_function_decl
name|int
name|calc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// disassemble.c
end_comment

begin_function_decl
name|int
name|disassemble
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// metadata.c
end_comment

begin_function_decl
name|int
name|add_named_metadata_operand
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_metadata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// object.c
end_comment

begin_function_decl
name|int
name|object_list_sections
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|object_list_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// targets.c
end_comment

begin_function_decl
name|int
name|targets_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

