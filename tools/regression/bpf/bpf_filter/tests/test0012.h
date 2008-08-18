begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Test 0012:	BPF_LDX|BPF_MSH|BPF_B  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* BPF program */
end_comment

begin_decl_stmt
name|struct
name|bpf_insn
name|pc
index|[]
init|=
block|{
name|BPF_STMT
argument_list|(
name|BPF_LDX
operator||
name|BPF_MSH
operator||
name|BPF_B
argument_list|,
literal|1
argument_list|)
block|,
name|BPF_STMT
argument_list|(
name|BPF_MISC
operator||
name|BPF_TXA
argument_list|,
literal|0
argument_list|)
block|,
name|BPF_STMT
argument_list|(
name|BPF_RET
operator|+
name|BPF_A
argument_list|,
literal|0
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Packet */
end_comment

begin_decl_stmt
name|u_char
name|pkt
index|[]
init|=
block|{
literal|0x01
block|,
literal|0x23
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Packet length seen on wire */
end_comment

begin_decl_stmt
name|u_int
name|wirelen
init|=
sizeof|sizeof
argument_list|(
name|pkt
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Packet length passed on buffer */
end_comment

begin_decl_stmt
name|u_int
name|buflen
init|=
sizeof|sizeof
argument_list|(
name|pkt
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Invalid instruction */
end_comment

begin_decl_stmt
name|int
name|invalid
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expected return value */
end_comment

begin_decl_stmt
name|u_int
name|expect
init|=
operator|(
literal|0x23
operator|&
literal|0xf
operator|)
operator|<<
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expeced signal */
end_comment

begin_decl_stmt
name|int
name|expect_signal
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

