begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<time.h>
end_include

begin_decl_stmt
name|int
name|gl_futimens
argument_list|(
name|int
argument_list|,
name|char
specifier|const
operator|*
argument_list|,
expr|struct
name|timespec
specifier|const
index|[
literal|2
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|utimens
argument_list|(
name|char
specifier|const
operator|*
argument_list|,
expr|struct
name|timespec
specifier|const
index|[
literal|2
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

