begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: clang-cc -emit-pch -DFOO -o %t %S/variables.h
end_comment

begin_comment
comment|// RUN: clang-cc -DBAR=int -include-pch %t -fsyntax-only -pedantic %s
end_comment

begin_comment
comment|// RUN: clang-cc -DFOO -DBAR=int -include-pch %t -Werror %s
end_comment

begin_comment
comment|// RUN: not clang-cc -DFOO -DBAR=int -DX=5 -include-pch %t -Werror %s
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

end_unit

