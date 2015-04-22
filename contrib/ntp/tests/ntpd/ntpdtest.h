begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"tests_main.h"
end_include

begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|"ntp_stdlib.h"
include|#
directive|include
file|"ntp_calendar.h"
block|}
end_extern

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ntpdtest
range|:
name|public
name|ntptest
block|{
name|protected
operator|:
specifier|static
name|time_t
name|timefunc
argument_list|(
name|time_t
operator|*
argument_list|)
block|;
specifier|static
name|time_t
name|nowtime
block|;
specifier|static
name|void
name|settime
argument_list|(
argument|int y
argument_list|,
argument|int m
argument_list|,
argument|int d
argument_list|,
argument|int H
argument_list|,
argument|int M
argument_list|,
argument|int S
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt

end_unit

