begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Test 0018:	BPF_JMP+BPF_JEQ+BPF_K  *  * $FreeBSD$  */
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
name|BPF_LD
operator|+
name|BPF_IMM
argument_list|,
literal|0x01234567
argument_list|)
block|,
name|BPF_JUMP
argument_list|(
name|BPF_JMP
operator|+
name|BPF_JEQ
operator|+
name|BPF_K
argument_list|,
literal|0x01234568
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
block|,
name|BPF_JUMP
argument_list|(
name|BPF_JMP
operator|+
name|BPF_JEQ
operator|+
name|BPF_K
argument_list|,
literal|0x01234567
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
block|,
name|BPF_STMT
argument_list|(
name|BPF_LD
operator|+
name|BPF_IMM
argument_list|,
literal|0xdeadc0de
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
block|,
name|BPF_JUMP
argument_list|(
name|BPF_JMP
operator|+
name|BPF_JEQ
operator|+
name|BPF_K
argument_list|,
literal|0x01234566
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
name|BPF_STMT
argument_list|(
name|BPF_LD
operator|+
name|BPF_IMM
argument_list|,
literal|0xc0decafe
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
literal|0x00
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
literal|0xc0decafe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expected signal */
end_comment

begin_decl_stmt
name|int
name|expect_signal
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

