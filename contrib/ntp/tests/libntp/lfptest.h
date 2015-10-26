begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NTP_TESTS_LFPTEST_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_TESTS_LFPTEST_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|int32
name|HALF
init|=
operator|-
literal|2147483647L
operator|-
literal|1L
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int32
name|HALF_PROMILLE_UP
init|=
literal|2147484
decl_stmt|;
end_decl_stmt

begin_comment
comment|// slightly more than 0.0005
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|int32
name|HALF_PROMILLE_DOWN
init|=
literal|2147483
decl_stmt|;
end_decl_stmt

begin_comment
comment|// slightly less than 0.0005
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|int32
name|QUARTER
init|=
literal|1073741824L
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int32
name|QUARTER_PROMILLE_APPRX
init|=
literal|1073742L
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|IsEqual
parameter_list|(
specifier|const
name|l_fp
name|expected
parameter_list|,
specifier|const
name|l_fp
name|actual
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

