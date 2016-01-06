begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MakeResolver
parameter_list|(
name|name
parameter_list|)
define|\
value|void * name ## Resolver(void) __asm__("_" #name);              \   void * name ## Resolver(void) {                                \     __asm__(".symbol_resolver _" #name);                         \     return name ## _hidden;                                    \   }
end_define

begin_function
name|int
name|call_through_indirect_hidden
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
return|return
name|arg
operator|+
literal|5
return|;
block|}
end_function

begin_macro
name|MakeResolver
argument_list|(
argument|call_through_indirect
argument_list|)
end_macro

end_unit

