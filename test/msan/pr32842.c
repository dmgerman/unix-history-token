begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Regression test for https://bugs.llvm.org/show_bug.cgi?id=32842
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_msan -g %s -o %t
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck  %s
end_comment

begin_struct
struct|struct
name|iphdr
block|{
name|unsigned
name|char
name|pad1
range|:
literal|2
decl_stmt|,
name|ihl
range|:
literal|4
decl_stmt|,
name|pad2
range|:
literal|2
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|raw_send_hdrinc
parameter_list|(
name|unsigned
name|long
name|int
name|length
parameter_list|)
block|{
name|struct
name|iphdr
name|iph
decl_stmt|;
if|if
condition|(
name|iph
operator|.
name|ihl
operator|*
literal|4
operator|>
name|length
condition|)
block|{
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
return|return
name|raw_send_hdrinc
argument_list|(
literal|12
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: WARNING: MemorySanitizer: use-of-uninitialized-value
end_comment

end_unit

