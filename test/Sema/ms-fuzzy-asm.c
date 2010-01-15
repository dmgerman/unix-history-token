begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fms-extensions
end_comment

begin_define
define|#
directive|define
name|M
value|__asm int 0x2c
end_define

begin_define
define|#
directive|define
name|M2
value|int
end_define

begin_function
name|void
name|t1
parameter_list|(
name|void
parameter_list|)
block|{
name|M
block|}
end_function

begin_function
name|void
name|t2
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm int 0x2c
block|}
end_function

begin_function
name|void
name|t3
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm M2 0x2c
block|}
end_function

begin_function
name|void
modifier|*
name|t4
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm mov eax, fs:[0x10]
block|}
end_function

end_unit

