begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"macro2.h"
end_include

begin_define
define|#
directive|define
name|ONE
value|1
end_define

begin_define
define|#
directive|define
name|TWO
value|2
end_define

begin_define
define|#
directive|define
name|THREE
value|3
end_define

begin_define
define|#
directive|define
name|FOUR
value|4
end_define

begin_decl_stmt
name|class
name|Simple
block|{
name|public
label|:
name|int
name|Method
parameter_list|()
block|{
return|return
name|ONE
operator|+
name|TWO
return|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

