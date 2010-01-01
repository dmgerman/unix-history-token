begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep 'ei_1 = (17 +1);'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | grep 'ei_2 = (M1)(17);'
end_comment

begin_define
define|#
directive|define
name|M1
parameter_list|(
name|a
parameter_list|)
value|(a+1)
end_define

begin_define
define|#
directive|define
name|M2
parameter_list|(
name|b
parameter_list|)
value|b
end_define

begin_decl_stmt
name|int
name|ei_1
init|=
name|M2
argument_list|(
name|M1
argument_list|)
argument_list|(
literal|17
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* becomes int ei_1 = (17+1); */
end_comment

begin_decl_stmt
name|int
name|ei_2
init|=
operator|(
name|M2
argument_list|(
name|M1
argument_list|)
operator|)
operator|(
literal|17
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* becomes int ei_2 = (M1)(17); */
end_comment

end_unit

