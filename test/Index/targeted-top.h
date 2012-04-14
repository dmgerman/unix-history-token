begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TARGETED_TOP_H
end_ifndef

begin_define
define|#
directive|define
name|TARGETED_TOP_H
end_define

begin_include
include|#
directive|include
file|"targeted-nested1.h"
end_include

begin_enum
enum|enum
block|{
name|VALUE
init|=
literal|3
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|TopVar
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
include|#
directive|include
file|"targeted-fields.h"
block|}
name|Vector
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|int
name|vector_get_x
parameter_list|(
name|Vector
name|v
parameter_list|)
block|{
name|int
name|x
init|=
name|v
operator|.
name|x
decl_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

