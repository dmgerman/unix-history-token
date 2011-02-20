begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Preamble detection test: see below for comments and test commands.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|<blah>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FOO
end_ifndef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BAR
end_ifdef

begin_elif
elif|#
directive|elif
name|WIBBLE
end_elif

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|unknown
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIBBLE
end_ifdef

begin_include
include|#
directive|include
file|"honk"
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This test checks for detection of the preamble of a file, which
end_comment

begin_comment
comment|// includes all of the starting comments and #includes. Note that any
end_comment

begin_comment
comment|// changes to the preamble part of this file must be mirrored in
end_comment

begin_comment
comment|// Inputs/preamble.txt, since we diff against it.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -print-preamble %s> %t
end_comment

begin_comment
comment|// RUN: echo END.>> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|// CHECK: // Preamble detection test: see below for comments and test commands.
end_comment

begin_comment
comment|// CHECK-NEXT: //
end_comment

begin_comment
comment|// CHECK-NEXT: #include<blah>
end_comment

begin_comment
comment|// CHECK-NEXT: #ifndef FOO
end_comment

begin_comment
comment|// CHECK-NEXT: #else
end_comment

begin_comment
comment|// CHECK-NEXT: #ifdef BAR
end_comment

begin_comment
comment|// CHECK-NEXT: #elif WIBBLE
end_comment

begin_comment
comment|// CHECK-NEXT: #endif
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma unknown
end_comment

begin_comment
comment|// CHECK-NEXT: #endif
end_comment

begin_comment
comment|// CHECK-NEXT: END.
end_comment

end_unit

