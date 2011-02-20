begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-win32 -emit-llvm -O2 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Under Windows 64, int and long are 32-bits.  Make sure pointer math doesn't
end_comment

begin_comment
comment|// cause any sign extensions.
end_comment

begin_comment
comment|// CHECK:      [[P:%.*]] = add i64 %param, -8
end_comment

begin_comment
comment|// CHECK-NEXT: [[Q:%.*]] = inttoptr i64 [[P]] to [[R:%.*\*]]
end_comment

begin_comment
comment|// CHECK-NEXT: {{%.*}} = getelementptr inbounds [[R]] [[Q]], i64 0, i32 0
end_comment

begin_define
define|#
directive|define
name|CR
parameter_list|(
name|Record
parameter_list|,
name|TYPE
parameter_list|,
name|Field
parameter_list|)
define|\
value|((TYPE *) ((unsigned char *) (Record) - (unsigned char *)&(((TYPE *) 0)->Field)))
end_define

begin_typedef
typedef|typedef
struct|struct
name|_LIST_ENTRY
block|{
name|struct
name|_LIST_ENTRY
modifier|*
name|ForwardLink
decl_stmt|;
name|struct
name|_LIST_ENTRY
modifier|*
name|BackLink
decl_stmt|;
block|}
name|LIST_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|long
name|Signature
decl_stmt|;
name|LIST_ENTRY
name|Link
decl_stmt|;
block|}
name|MEMORY_MAP
typedef|;
end_typedef

begin_function
name|int
name|test
parameter_list|(
name|unsigned
name|long
name|long
name|param
parameter_list|)
block|{
name|LIST_ENTRY
modifier|*
name|Link
decl_stmt|;
name|MEMORY_MAP
modifier|*
name|Entry
decl_stmt|;
name|Link
operator|=
operator|(
name|LIST_ENTRY
operator|*
operator|)
name|param
expr_stmt|;
name|Entry
operator|=
name|CR
argument_list|(
name|Link
argument_list|,
name|MEMORY_MAP
argument_list|,
name|Link
argument_list|)
expr_stmt|;
return|return
operator|(
name|int
operator|)
name|Entry
operator|->
name|Signature
return|;
block|}
end_function

end_unit

