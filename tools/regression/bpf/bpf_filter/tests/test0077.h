begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Test 0077:	Check boundary conditions (BPF_ST)  *  * $FreeBSD$  */
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
literal|0xdeadc0de
argument_list|)
block|,
name|BPF_STMT
argument_list|(
name|BPF_ST
argument_list|,
literal|0x8fffffff
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
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expected return value */
end_comment

begin_decl_stmt
name|u_int
name|expect
init|=
literal|0xdeadc0de
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expected signal */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_decl_stmt
name|int
name|expect_signal
init|=
name|SIGBUS
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|expect_signal
init|=
name|SIGSEGV
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

