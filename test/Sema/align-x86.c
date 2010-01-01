begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR3433
end_comment

begin_decl_stmt
name|double
name|g1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|chk1
index|[
name|__alignof__
argument_list|(
name|g1
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|chk2
index|[
name|__alignof__
argument_list|(
name|double
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|long
name|g2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|chk1
index|[
name|__alignof__
argument_list|(
name|g2
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|chk2
index|[
name|__alignof__
argument_list|(
argument|long long
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|_Complex
name|double
name|g3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|chk1
index|[
name|__alignof__
argument_list|(
name|g3
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|chk2
index|[
name|__alignof__
argument_list|(
specifier|_Complex
name|double
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

