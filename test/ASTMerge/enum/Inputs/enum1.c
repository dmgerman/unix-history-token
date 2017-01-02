begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Matching
end_comment

begin_enum
enum|enum
name|E1
block|{
name|E1Enumerator1
block|,
name|E1Enumerator2
init|=
literal|3
block|,
name|E1Enumerator3
block|}
name|x1
enum|;
end_enum

begin_comment
comment|// Value mismatch
end_comment

begin_enum
enum|enum
name|E2
block|{
name|E2Enumerator1
block|,
name|E2Enumerator2
init|=
literal|3
block|,
name|E2Enumerator3
block|}
name|x2
enum|;
end_enum

begin_comment
comment|// Name mismatch
end_comment

begin_enum
enum|enum
name|E3
block|{
name|E3Enumerator1
block|,
name|E3Enumerator2
init|=
literal|3
block|,
name|E3Enumerator3
block|}
name|x3
enum|;
end_enum

begin_comment
comment|// Missing enumerator
end_comment

begin_enum
enum|enum
name|E4
block|{
name|E4Enumerator1
block|,
name|E4Enumerator2
block|,
name|E4Enumerator3
block|}
name|x4
enum|;
end_enum

begin_comment
comment|// Extra enumerator
end_comment

begin_enum
enum|enum
name|E5
block|{
name|E5Enumerator1
block|,
name|E5Enumerator2
block|,
name|E5Enumerator3
block|}
name|x5
enum|;
end_enum

begin_comment
comment|// Matching, with typedef
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|E6Enumerator1
block|,
name|E6Enumerator2
block|}
name|E6
typedef|;
end_typedef

begin_decl_stmt
name|E6
name|x6
decl_stmt|;
end_decl_stmt

end_unit

