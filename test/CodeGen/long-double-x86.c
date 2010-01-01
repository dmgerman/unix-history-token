begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 | grep x86_fp80
end_comment

begin_decl_stmt
name|long
name|double
name|x
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|checksize
index|[
sizeof|sizeof
argument_list|(
name|x
argument_list|)
operator|==
literal|16
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

