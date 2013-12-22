begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- include-all.c - tool for testing libLLVM and llvm-c API -----------===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file doesn't have any actual code. It just make sure that all         *| |* the llvm-c include files are good and doesn't generate any warnings        *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_comment
comment|// FIXME: Autogenerate this list
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Analysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/BitReader.h"
end_include

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
file|"llvm-c/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Initialization.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/LinkTimeOptimizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Linker.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Object.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Target.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Transforms/IPO.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Transforms/PassManagerBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Transforms/Scalar.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Transforms/Vectorize.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/lto.h"
end_include

end_unit

