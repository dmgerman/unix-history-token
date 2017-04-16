begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|int
name|Int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|Float
typedef|;
end_typedef

begin_comment
comment|// Matches
end_comment

begin_struct
struct|struct
name|S0
block|{
name|Int
name|field1
decl_stmt|;
name|Float
name|field2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|S0
name|x0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Mismatch in field type
end_comment

begin_struct
struct|struct
name|S1
block|{
name|Int
name|field1
decl_stmt|;
name|int
name|field2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|S1
name|x1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Mismatch in tag kind.
end_comment

begin_struct
struct|struct
name|S2
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|x2
struct|;
end_struct

begin_comment
comment|// Missing fields
end_comment

begin_struct
struct|struct
name|S3
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
name|x3
struct|;
end_struct

begin_comment
comment|// Extra fields
end_comment

begin_struct
struct|struct
name|S4
block|{
name|int
name|i
decl_stmt|;
block|}
name|x4
struct|;
end_struct

begin_comment
comment|// Bit-field matches
end_comment

begin_struct
struct|struct
name|S5
block|{
name|int
name|i
range|:
literal|8
decl_stmt|;
name|unsigned
name|j
range|:
literal|8
decl_stmt|;
block|}
name|x5
struct|;
end_struct

begin_comment
comment|// Bit-field mismatch
end_comment

begin_struct
struct|struct
name|S6
block|{
name|int
name|i
range|:
literal|8
decl_stmt|;
name|unsigned
name|j
range|:
literal|8
decl_stmt|;
block|}
name|x6
struct|;
end_struct

begin_comment
comment|// Bit-field mismatch
end_comment

begin_struct
struct|struct
name|S7
block|{
name|int
name|i
range|:
literal|8
decl_stmt|;
name|unsigned
name|j
range|:
literal|8
decl_stmt|;
block|}
name|x7
struct|;
end_struct

begin_comment
comment|// Incomplete type
end_comment

begin_decl_stmt
name|struct
name|S8
modifier|*
name|x8
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Incomplete type
end_comment

begin_struct
struct|struct
name|S9
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
modifier|*
name|x9
struct|;
end_struct

begin_comment
comment|// Incomplete type
end_comment

begin_decl_stmt
name|struct
name|S10
modifier|*
name|x10
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Matches
end_comment

begin_struct
struct|struct
name|ListNode
block|{
name|int
name|value
decl_stmt|;
name|struct
name|ListNode
modifier|*
name|Next
decl_stmt|;
block|}
name|xList
struct|;
end_struct

begin_comment
comment|// Mismatch due to struct used internally
end_comment

begin_struct
struct|struct
name|DeepError
block|{
name|int
name|value
decl_stmt|;
struct|struct
name|DeeperError
block|{
name|int
name|i
decl_stmt|;
name|int
name|f
decl_stmt|;
block|}
modifier|*
name|Deeper
struct|;
block|}
name|xDeep
struct|;
end_struct

begin_comment
comment|// Matches
end_comment

begin_struct
struct|struct
block|{
name|Int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|x11
struct|;
end_struct

begin_comment
comment|// Matches
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|S12
typedef|;
end_typedef

begin_decl_stmt
name|S12
name|x12
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Mismatch
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Float
name|i
decl_stmt|;
comment|// Mismatch here.
name|float
name|f
decl_stmt|;
block|}
name|S13
typedef|;
end_typedef

begin_decl_stmt
name|S13
name|x13
decl_stmt|;
end_decl_stmt

end_unit

