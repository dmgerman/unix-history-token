begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_define
define|#
directive|define
name|pck
value|__attribute__((packed))
end_define

begin_struct
struct|struct
name|pck
name|F
block|{
name|unsigned
name|long
name|long
name|i
range|:
literal|12
decl_stmt|,
name|j
range|:
literal|23
decl_stmt|,
name|k
range|:
literal|27
decl_stmt|,
name|l
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|F
name|f1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|f1
operator|.
name|l
operator|=
literal|5
expr_stmt|;
block|}
end_function

end_unit

