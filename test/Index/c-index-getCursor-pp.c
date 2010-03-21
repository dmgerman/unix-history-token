begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|OBSCURE
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_define
define|#
directive|define
name|DECORATION
end_define

begin_typedef
typedef|typedef
name|int
name|T
typedef|;
end_typedef

begin_function
name|void
name|OBSCURE
function|(
name|func
function|)
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|OBSCURE
argument_list|(
argument|T
argument_list|)
name|DECORATION
name|value
decl_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:1:11 %s | FileCheck -check-prefix=CHECK-1 %s
end_comment

begin_comment
comment|// CHECK-1: macro definition=OBSCURE
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:2:14 %s | FileCheck -check-prefix=CHECK-2 %s
end_comment

begin_comment
comment|// CHECK-2: macro definition=DECORATION
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:5:7 %s | FileCheck -check-prefix=CHECK-3 %s
end_comment

begin_comment
comment|// CHECK-3: macro instantiation=OBSCURE:1:9
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:6:6 %s | FileCheck -check-prefix=CHECK-4 %s
end_comment

begin_comment
comment|// CHECK-4: macro instantiation=OBSCURE:1:9
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:6:19 %s | FileCheck -check-prefix=CHECK-5 %s
end_comment

begin_comment
comment|// CHECK-5: macro instantiation=DECORATION:2:9
end_comment

end_unit

