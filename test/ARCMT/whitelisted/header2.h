begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NS_ENUM
parameter_list|(
name|_type
parameter_list|,
name|_name
parameter_list|)
value|enum _name : _type _name; enum _name : _type
end_define

begin_typedef
typedef|typedef
enum_decl|enum :
name|NSInteger
block|{
name|five
block|}
name|ApplicableEnum
typedef|;
end_typedef

begin_decl_stmt
unit|@
name|interface
name|I2
range|:
name|NSObject
operator|-
operator|(
name|int
operator|)
name|prop
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setProp
operator|:
operator|(
name|int
operator|)
name|p
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

