begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1  -emit-llvm -g %s -o %t
end_comment

begin_comment
comment|// RUN: grep DW_TAG_enumeration_type %t
end_comment

begin_comment
comment|// Radar 8195980
end_comment

begin_enum
enum|enum
name|vtag
block|{
name|VT_ONE
block|}
enum|;
end_enum

begin_function
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
operator|==
name|VT_ONE
return|;
block|}
end_function

end_unit

