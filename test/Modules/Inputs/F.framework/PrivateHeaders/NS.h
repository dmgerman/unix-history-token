begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|NS
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|NSE
block|{
name|FST
init|=
literal|22
block|,
name|SND
init|=
literal|43
block|,
name|TRD
init|=
literal|55
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NS_ENUM
parameter_list|(
name|_type
parameter_list|,
name|_name
parameter_list|)
define|\
value|enum _name : _type _name;   \   enum _name : _type
end_define

begin_typedef
typedef|typedef
name|NS_ENUM
argument_list|(
argument|int
argument_list|,
argument|NSMyEnum
argument_list|)
block|{
name|MinX
operator|=
literal|11
operator|,
name|MinXOther
operator|=
name|MinX
operator|,
block|}
end_typedef

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

