begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_stacktrace_printer.h --------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is shared between sanitizers' run-time libraries.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_STACKTRACE_PRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_STACKTRACE_PRINTER_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_symbolizer.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// Render the contents of "info" structure, which represents the contents of
comment|// stack frame "frame_no" and appends it to the "buffer". "format" is a
comment|// string with placeholders, which is copied to the output with
comment|// placeholders substituted with the contents of "info". For example,
comment|// format string
comment|//   "  frame %n: function %F at %S"
comment|// will be turned into
comment|//   "  frame 10: function foo::bar() at my/file.cc:10"
comment|// You may additionally pass "strip_path_prefix" to strip prefixes of paths to
comment|// source files and modules, and "strip_func_prefix" to strip prefixes of
comment|// function names.
comment|// Here's the full list of available placeholders:
comment|//   %% - represents a '%' character;
comment|//   %n - frame number (copy of frame_no);
comment|//   %p - PC in hex format;
comment|//   %m - path to module (binary or shared object);
comment|//   %o - offset in the module in hex format;
comment|//   %f - function name;
comment|//   %q - offset in the function in hex format (*if available*);
comment|//   %s - path to source file;
comment|//   %l - line in the source file;
comment|//   %c - column in the source file;
comment|//   %F - if function is known to be<foo>, prints "in<foo>", possibly
comment|//        followed by the offset in this function, but only if source file
comment|//        is unknown;
comment|//   %S - prints file/line/column information;
comment|//   %L - prints location information: file/line/column, if it is known, or
comment|//        module+offset if it is known, or (<unknown module>) string.
comment|//   %M - prints module basename and offset, if it is known, or PC.
name|void
name|RenderFrame
parameter_list|(
name|InternalScopedString
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|int
name|frame_no
parameter_list|,
specifier|const
name|AddressInfo
modifier|&
name|info
parameter_list|,
specifier|const
name|char
modifier|*
name|strip_path_prefix
init|=
literal|""
parameter_list|,
specifier|const
name|char
modifier|*
name|strip_func_prefix
init|=
literal|""
parameter_list|)
function_decl|;
name|void
name|RenderSourceLocation
parameter_list|(
name|InternalScopedString
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|int
name|column
parameter_list|,
specifier|const
name|char
modifier|*
name|strip_path_prefix
parameter_list|)
function_decl|;
name|void
name|RenderModuleLocation
parameter_list|(
name|InternalScopedString
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|module
parameter_list|,
name|uptr
name|offset
parameter_list|,
specifier|const
name|char
modifier|*
name|strip_path_prefix
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_STACKTRACE_PRINTER_H
end_comment

end_unit

