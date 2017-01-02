begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CHECK_H_
end_ifndef

begin_define
define|#
directive|define
name|CHECK_H_
end_define

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_include
include|#
directive|include
file|"internal_macros.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_decl_stmt
name|namespace
name|benchmark
block|{
name|namespace
name|internal
block|{
typedef|typedef
name|void
function_decl|(
name|AbortHandlerT
function_decl|)
parameter_list|()
function_decl|;
specifier|inline
name|AbortHandlerT
modifier|*
modifier|&
name|GetAbortHandler
parameter_list|()
block|{
specifier|static
name|AbortHandlerT
modifier|*
name|handler
init|=
operator|&
name|std
operator|::
name|abort
decl_stmt|;
return|return
name|handler
return|;
block|}
name|BENCHMARK_NORETURN
specifier|inline
name|void
name|CallAbortHandler
parameter_list|()
block|{
name|GetAbortHandler
argument_list|()
argument_list|()
expr_stmt|;
name|std
operator|::
name|abort
argument_list|()
expr_stmt|;
comment|// fallback to enforce noreturn
block|}
comment|// CheckHandler is the class constructed by failing CHECK macros. CheckHandler
comment|// will log information about the failures and abort when it is destructed.
name|class
name|CheckHandler
block|{
name|public
label|:
name|CheckHandler
argument_list|(
argument|const char* check
argument_list|,
argument|const char* file
argument_list|,
argument|const char* func
argument_list|,
argument|int line
argument_list|)
block|:
name|log_
argument_list|(
argument|GetErrorLogInstance()
argument_list|)
block|{
name|log_
operator|<<
name|file
operator|<<
literal|":"
operator|<<
name|line
operator|<<
literal|": "
operator|<<
name|func
operator|<<
literal|": Check `"
operator|<<
name|check
operator|<<
literal|"' failed. "
expr_stmt|;
block|}
name|LogType
modifier|&
name|GetLog
parameter_list|()
block|{
return|return
name|log_
return|;
block|}
name|BENCHMARK_NORETURN
operator|~
name|CheckHandler
argument_list|()
name|BENCHMARK_NOEXCEPT_OP
argument_list|(
argument|false
argument_list|)
block|{
name|log_
operator|<<
name|std
operator|::
name|endl
block|;
name|CallAbortHandler
argument_list|()
block|;   }
name|CheckHandler
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CheckHandler
operator|&
operator|)
operator|=
name|delete
expr_stmt|;
name|CheckHandler
argument_list|(
specifier|const
name|CheckHandler
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|CheckHandler
argument_list|()
operator|=
name|delete
expr_stmt|;
name|private
label|:
name|LogType
modifier|&
name|log_
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace internal
block|}
end_decl_stmt

begin_comment
comment|// end namespace benchmark
end_comment

begin_comment
comment|// The CHECK macro returns a std::ostream object that can have extra information
end_comment

begin_comment
comment|// written to it.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|b
parameter_list|)
define|\
value|(b ? ::benchmark::internal::GetNullLogInstance()                           \      : ::benchmark::internal::CheckHandler(#b, __FILE__, __func__, __LINE__) \            .GetLog())
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|b
parameter_list|)
value|::benchmark::internal::GetNullLogInstance()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHECK_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK((a) == (b))
end_define

begin_define
define|#
directive|define
name|CHECK_NE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK((a) != (b))
end_define

begin_define
define|#
directive|define
name|CHECK_GE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK((a)>= (b))
end_define

begin_define
define|#
directive|define
name|CHECK_LE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK((a)<= (b))
end_define

begin_define
define|#
directive|define
name|CHECK_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK((a)> (b))
end_define

begin_define
define|#
directive|define
name|CHECK_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK((a)< (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK_H_
end_comment

end_unit

