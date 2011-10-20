begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|// Without PCH
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s.h:1:11 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s.h:2:14 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s.h:4:5 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s.h:5:5 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s.h:5:14 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:5:7 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:6:6 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:6:19 \
end_comment

begin_comment
comment|// RUN:     -include %s.h %s | FileCheck %s
end_comment

begin_comment
comment|// With PCH
end_comment

begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch %s.h -Xclang -detailed-preprocessing-record
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s.h:1:11 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s.h:2:14 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s.h:4:5 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s.h:5:5 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s.h:5:14 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:5:7 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:6:6 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:6:19 \
end_comment

begin_comment
comment|// RUN:     -include %t.h %s | FileCheck %s
end_comment

begin_comment
comment|// From header
end_comment

begin_comment
comment|// CHECK: macro definition=OBSCURE
end_comment

begin_comment
comment|// CHECK: macro definition=DECORATION
end_comment

begin_comment
comment|// CHECK: macro expansion=DECORATION:2:9
end_comment

begin_comment
comment|// CHECK: macro expansion=OBSCURE:1:9
end_comment

begin_comment
comment|// CHECK: macro expansion=DECORATION:2:9
end_comment

begin_comment
comment|// From main file
end_comment

begin_comment
comment|// CHECK: macro expansion=OBSCURE:1:9
end_comment

begin_comment
comment|// CHECK: macro expansion=OBSCURE:1:9
end_comment

begin_comment
comment|// CHECK: macro expansion=DECORATION:2:9
end_comment

end_unit

