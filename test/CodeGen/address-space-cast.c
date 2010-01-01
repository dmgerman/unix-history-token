begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s
end_comment

begin_decl_stmt
specifier|volatile
name|unsigned
name|char
modifier|*
specifier|const
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|serial_ctrl
init|=
literal|0x02
decl_stmt|;
end_decl_stmt

end_unit

