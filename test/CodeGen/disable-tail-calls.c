begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9.0 -emit-llvm -O1 -mdisable-tail-calls -o -< %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
struct|struct
name|List
block|{
name|struct
name|List
modifier|*
name|next
decl_stmt|;
name|int
name|data
decl_stmt|;
block|}
name|List
typedef|;
end_typedef

begin_comment
comment|// CHECK-LABEL: define %struct.List* @find
end_comment

begin_function
name|List
modifier|*
name|find
parameter_list|(
name|List
modifier|*
name|head
parameter_list|,
name|int
name|data
parameter_list|)
block|{
if|if
condition|(
operator|!
name|head
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|head
operator|->
name|data
operator|==
name|data
condition|)
return|return
name|head
return|;
comment|// CHECK: call %struct.List* @find
return|return
name|find
argument_list|(
name|head
operator|->
name|next
argument_list|,
name|data
argument_list|)
return|;
block|}
end_function

end_unit

