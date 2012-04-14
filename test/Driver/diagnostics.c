begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Parse diagnostic arguments in the driver
end_comment

begin_comment
comment|// PR12181
end_comment

begin_comment
comment|// RUN: not %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -fsyntax-only -fzyzzybalubah \
end_comment

begin_comment
comment|// RUN:   -Werror=unused-command-line-argument %s
end_comment

begin_comment
comment|// RUN: not %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -fsyntax-only -fzyzzybalubah -Werror %s
end_comment

end_unit

