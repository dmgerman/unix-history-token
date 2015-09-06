begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|UTILS_H
end_define

begin_function
specifier|static
specifier|inline
name|void
name|break_optimization
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("" : : "r" (arg) : "memory");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

