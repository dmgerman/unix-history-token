begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -disable-llvm-passes -emit-llvm -o - %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|M
value|if (x) goto L1;
end_define

begin_define
define|#
directive|define
name|M10
value|M M M M M M M M M M
end_define

begin_define
define|#
directive|define
name|M100
value|M10 M10 M10 M10 M10 M10 M10 M10 M10 M10
end_define

begin_define
define|#
directive|define
name|M1000
value|M100 M100 M100 M100 M100 M100 M100 M100 M100 M100
end_define

begin_function
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|h
decl_stmt|;
comment|// Many gotos to not-yet-emitted labels would cause EHScope's FixupDepth
comment|// to overflow (PR23490).
name|M1000
name|M1000
name|M1000
if|if
condition|(
name|x
operator|==
literal|5
condition|)
block|{
comment|// This will cause us to emit a clean-up of the stack variable. If the
comment|// FixupDepths are broken, fixups will erroneously get threaded through it.
name|int
name|i
decl_stmt|;
block|}
name|L1
label|:
return|return;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f
end_comment

begin_comment
comment|// CHECK-NOT: cleanup
end_comment

end_unit

