begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O2 -S -g %s -o - | llc -o 2010-01-05-LinkageName.s -O0
end_comment

begin_comment
comment|// RUN: %compile_c 2010-01-05-LinkageName.s -o 2010-01-05-LinkageName.s
end_comment

begin_struct
struct|struct
name|tm
block|{}
struct|;
end_struct

begin_function
name|long
name|mktime
parameter_list|(
name|struct
name|tm
modifier|*
parameter_list|)
asm|__asm("_mktime$UNIX2003");
function|tzload
parameter_list|(
name|name
parameter_list|,
name|sp
parameter_list|,
name|doextend
parameter_list|)
block|{}
end_function

begin_function
name|long
name|mktime
parameter_list|(
name|tmp
parameter_list|)
name|struct
name|tm
modifier|*
specifier|const
name|tmp
decl_stmt|;
block|{
name|tzset
argument_list|()
expr_stmt|;
block|}
end_function

begin_macro
name|timelocal
argument_list|(
argument|tmp
argument_list|)
end_macro

begin_block
block|{
return|return
name|mktime
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_block

end_unit

