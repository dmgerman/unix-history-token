begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -DFOO -o %t %S/variables.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DBAR=int -include-pch %t -fsyntax-only -pedantic %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DFOO -DBAR=int -include-pch %t %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DFOO=blah -DBAR=int -include-pch %t %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-FOO %s< %t.err
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -UFOO -include-pch %t %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-NOFOO %s< %t.err
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -DFOO -undef -include-pch %t %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-UNDEF %s< %t.err
end_comment

begin_decl_stmt
name|BAR
name|bar
init|=
literal|17
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|FOO
end_ifndef

begin_error
error|#
directive|error
error|FOO was not defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FOO
operator|!=
literal|1
end_if

begin_error
error|#
directive|error
error|FOO has the wrong definition
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BAR
end_ifndef

begin_error
error|#
directive|error
error|BAR was not defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-FOO: definition of macro 'FOO' differs between the precompiled header ('1') and the command line ('blah')
end_comment

begin_comment
comment|// CHECK-NOFOO: macro 'FOO' was defined in the precompiled header but undef'd on the command line
end_comment

begin_comment
comment|// CHECK-UNDEF: command line contains '-undef' but precompiled header was not built with it
end_comment

end_unit

