begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch %s.h
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_REMAP_AFTER_TRIAL=1 c-index-test -test-load-source-reparse 3 local \
end_comment

begin_comment
comment|// RUN:           "-remap-file=%s,%s.remap" %s -include %t.h -D CMD_MACRO=1 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: error:
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
name|x
return|;
block|}
end_function

end_unit

