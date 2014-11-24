begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 nul
end_comment

begin_comment
comment|// REQUIRES: system-windows
end_comment

begin_comment
comment|// Verify that cc1 doesn't crash with an assertion failure
end_comment

begin_comment
comment|// in MemoryBuffer.cpp due to an invalid file size reported
end_comment

begin_comment
comment|// when the Windows 'nul' device is passed in input.
end_comment

end_unit

