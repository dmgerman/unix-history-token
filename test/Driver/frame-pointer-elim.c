begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// For these next two tests when optimized we should omit the leaf frame
end_comment

begin_comment
comment|// pointer, for unoptimized we should have a leaf frame pointer.
end_comment

begin_comment
comment|// RUN: %clang -### -target i386-pc-linux-gnu -S -O1 %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=LINUX-OPT %s
end_comment

begin_comment
comment|// LINUX-OPT: "-momit-leaf-frame-pointer"
end_comment

begin_comment
comment|// RUN: %clang -### -target i386-pc-linux-gnu -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=LINUX %s
end_comment

begin_comment
comment|// LINUX-NOT: "-momit-leaf-frame-pointer"
end_comment

begin_comment
comment|// Darwin disables omitting the leaf frame pointer even under optimization
end_comment

begin_comment
comment|// unless the command lines are given.
end_comment

begin_comment
comment|// RUN: %clang -### -target i386-apple-darwin -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=DARWIN %s
end_comment

begin_comment
comment|// DARWIN: "-mdisable-fp-elim"
end_comment

begin_comment
comment|// RUN: %clang -### -target i386-apple-darwin -S -O1 %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=DARWIN-OPT %s
end_comment

begin_comment
comment|// DARWIN-OPT-NOT: "-momit-leaf-frame-pointer"
end_comment

begin_comment
comment|// RUN: %clang -### -target i386-darwin -S -fomit-frame-pointer %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=OMIT_ALL %s
end_comment

begin_comment
comment|// OMIT_ALL-NOT: "-mdisable-fp-elim"
end_comment

begin_comment
comment|// RUN: %clang -### -target i386-darwin -S -momit-leaf-frame-pointer %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=OMIT_LEAF %s
end_comment

begin_comment
comment|// OMIT_LEAF: "-momit-leaf-frame-pointer"
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

