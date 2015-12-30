begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(lockable)
argument_list|)
name|mutex
block|{
name|void
name|lock
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(exclusive_lock_function
block|)
end_struct

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|unlock
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unlock_function
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

unit|};
end_unit

