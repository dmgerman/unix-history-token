begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -fblocks -g -S %s -o -
end_comment

begin_comment
comment|// rdar://7590323
end_comment

begin_typedef
typedef|typedef
name|struct
name|dispatch_queue_s
modifier|*
name|dispatch_queue_t
typedef|;
end_typedef

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"default"
argument|))
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|struct
name|dispatch_queue_s
name|_dispatch_main_q
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|dispatch_item_s
modifier|*
name|dispatch_item_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|dispatch_legacy_block_t
function_decl|)
parameter_list|(
name|dispatch_item_t
parameter_list|)
function_decl|;
end_typedef

begin_function
name|dispatch_item_t
name|LEGACY_dispatch_call
parameter_list|(
name|dispatch_queue_t
name|dq
parameter_list|,
name|dispatch_legacy_block_t
name|dispatch_block
parameter_list|,
name|dispatch_legacy_block_t
name|callback_block
parameter_list|)
block|{
name|dispatch_queue_t
name|lq
init|=
name|_dispatch_queue_get_current
argument_list|()
condition|?
else|:
operator|(
operator|&
name|_dispatch_main_q
operator|)
decl_stmt|;
name|dispatch_async
argument_list|(
name|dq
argument_list|,
lambda|^
block|{
if|if
condition|(
name|callback_block
condition|)
block|{
name|dispatch_async
argument_list|(
name|lq
argument_list|,
lambda|^
block|{           }
argument_list|)
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

