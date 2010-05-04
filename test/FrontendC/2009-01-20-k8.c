begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -march=k8 -o /dev/null
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: x86,i386,i686
end_comment

begin_decl_stmt
name|long
name|double
name|x
decl_stmt|;
end_decl_stmt

end_unit

