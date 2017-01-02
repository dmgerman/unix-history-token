begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -o /dev/null -v -fxray-instrument -c %s
end_comment

begin_comment
comment|// XFAIL: -linux-
end_comment

begin_comment
comment|// REQUIRES-ANY: amd64, x86_64, x86_64h, arm, aarch64, arm64
end_comment

begin_typedef
typedef|typedef
name|int
name|a
typedef|;
end_typedef

end_unit

