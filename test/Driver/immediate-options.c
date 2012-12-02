begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --help | grep isystem
end_comment

begin_comment
comment|// RUN: %clang --help | not grep ast-dump
end_comment

begin_comment
comment|// RUN: %clang --help | not grep ccc-cxx
end_comment

begin_comment
comment|// RUN: %clang --help-hidden | grep ccc-cxx
end_comment

begin_comment
comment|// RUN: %clang -dumpversion
end_comment

begin_comment
comment|// RUN: %clang -print-search-dirs
end_comment

end_unit

