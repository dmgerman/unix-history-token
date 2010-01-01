begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -include %S/file_to_include.h -E %s -fno-caret-diagnostics 2>&1>/dev/null | grep 'file successfully included' | count 1
end_comment

begin_comment
comment|// PR3464
end_comment

end_unit

