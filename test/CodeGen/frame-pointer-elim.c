begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple i386 -S -o - %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=DEFAULT %s
end_comment

begin_comment
comment|// DEFAULT: f0:
end_comment

begin_comment
comment|// DEFAULT: pushl %ebp
end_comment

begin_comment
comment|// DEFAULT: ret
end_comment

begin_comment
comment|// DEFAULT: f1:
end_comment

begin_comment
comment|// DEFAULT: pushl %ebp
end_comment

begin_comment
comment|// DEFAULT: ret
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386 -S -o - -fomit-frame-pointer %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=OMIT_ALL %s
end_comment

begin_comment
comment|// OMIT_ALL: f0:
end_comment

begin_comment
comment|// OMIT_ALL-NOT: pushl %ebp
end_comment

begin_comment
comment|// OMIT_ALL: ret
end_comment

begin_comment
comment|// OMIT_ALL: f1:
end_comment

begin_comment
comment|// OMIT_ALL-NOT: pushl %ebp
end_comment

begin_comment
comment|// OMIT_ALL: ret
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386 -S -o - -momit-leaf-frame-pointer %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=OMIT_LEAF %s
end_comment

begin_comment
comment|// OMIT_LEAF: f0:
end_comment

begin_comment
comment|// OMIT_LEAF-NOT: pushl %ebp
end_comment

begin_comment
comment|// OMIT_LEAF: ret
end_comment

begin_comment
comment|// OMIT_LEAF: f1:
end_comment

begin_comment
comment|// OMIT_LEAF: pushl %ebp
end_comment

begin_comment
comment|// OMIT_LEAF: ret
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{}
end_function

begin_function
name|void
name|f1
parameter_list|()
block|{
name|f0
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

