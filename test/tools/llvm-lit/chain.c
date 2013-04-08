begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This test should fail. lit used to interpret this as:
end_comment

begin_comment
comment|//   (false&& false) || true
end_comment

begin_comment
comment|// instead of the intended
end_comment

begin_comment
comment|//   false&& (false || true
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: false
end_comment

begin_comment
comment|// RUN: false || true
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XFAIL: *
end_comment

end_unit

