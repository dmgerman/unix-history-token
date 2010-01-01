begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - | grep inreg | count 2
end_comment

begin_define
define|#
directive|define
name|FASTCALL
value|__attribute__((regparm(2)))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|aaa
decl_stmt|;
name|double
name|bbbb
decl_stmt|;
name|int
name|ccc
index|[
literal|200
index|]
decl_stmt|;
block|}
name|foo
typedef|;
end_typedef

begin_function
specifier|static
name|void
name|FASTCALL
name|reduced
parameter_list|(
name|char
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|foo
modifier|*
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|int
name|f
parameter_list|)
block|{ }
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|reduced
argument_list|(
literal|0
argument_list|,
literal|0.0
argument_list|,
literal|0
argument_list|,
literal|0.0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

