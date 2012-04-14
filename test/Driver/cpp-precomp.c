begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -Werror -cpp-precomp -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -Werror -no-cpp-precomp -fsyntax-only %s
end_comment

end_unit

