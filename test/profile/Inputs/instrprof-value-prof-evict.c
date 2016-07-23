begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|void
name|callee_0
parameter_list|()
block|{}
end_function

begin_function
name|void
name|callee_1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|callee_2
parameter_list|()
block|{}
end_function

begin_function
name|void
name|callee_3
parameter_list|()
block|{}
end_function

begin_decl_stmt
name|void
modifier|*
name|CalleeAddrs
index|[]
init|=
block|{
name|callee_0
block|,
name|callee_1
block|,
name|callee_2
block|,
name|callee_3
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|lprofSetMaxValsPerSite
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// sequences of callee ids
end_comment

begin_comment
comment|// In the following sequences,
end_comment

begin_comment
comment|// there are two targets, the dominating target is
end_comment

begin_comment
comment|// target 0.
end_comment

begin_decl_stmt
name|int
name|CallSeqTwoTarget_1
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CallSeqTwoTarget_2
index|[]
init|=
block|{
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CallSeqTwoTarget_3
index|[]
init|=
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CallSeqTwoTarget_4
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// In the following sequences, there are three targets
end_comment

begin_comment
comment|// The dominating target is 0 and has> 50% of total
end_comment

begin_comment
comment|// counts.
end_comment

begin_decl_stmt
name|int
name|CallSeqThreeTarget_1
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CallSeqThreeTarget_2
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CallSeqThreeTarget_3
index|[]
init|=
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|2
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CallSeqThreeTarget_4
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Four target sequence --
end_comment

begin_comment
comment|// There are two cold targets which occupies the value counters
end_comment

begin_comment
comment|// early. There is also a very hot target and a medium hot target
end_comment

begin_comment
comment|// which are invoked in an interleaved fashion -- the length of each
end_comment

begin_comment
comment|// hot period in the sequence is shorter than the cold targets' count.
end_comment

begin_comment
comment|//  1. If only two values are tracked, the Hot and Medium hot targets
end_comment

begin_comment
comment|//     should surive in the end
end_comment

begin_comment
comment|//  2. If only three values are tracked, the top three targets should
end_comment

begin_comment
comment|//     surive in the end.
end_comment

begin_decl_stmt
name|int
name|CallSeqFourTarget_1
index|[]
init|=
block|{
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Same as above, but the cold entries are invoked later.
end_comment

begin_decl_stmt
name|int
name|CallSeqFourTarget_2
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Same as above, but all the targets are interleaved.
end_comment

begin_decl_stmt
name|int
name|CallSeqFourTarget_3
index|[]
init|=
block|{
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|2
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|3
block|,
literal|0
block|,
literal|3
block|,
literal|2
block|,
literal|2
block|,
literal|0
block|,
literal|3
block|,
literal|3
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|2
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|FPT
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Testing value profiling eviction algorithm.
end_comment

begin_function
name|FPT
name|getCalleeFunc
parameter_list|(
name|int
name|I
parameter_list|)
block|{
return|return
name|CalleeAddrs
index|[
name|I
index|]
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|I
decl_stmt|;
define|#
directive|define
name|INDIRECT_CALLSITE
parameter_list|(
name|Sequence
parameter_list|,
name|NumValsTracked
parameter_list|)
define|\
value|lprofSetMaxValsPerSite(NumValsTracked);                                      \   for (I = 0; I< sizeof(Sequence) / sizeof(*Sequence); I++) {                 \     FPT FP = getCalleeFunc(Sequence[I]);                                       \     FP();                                                                      \   }
comment|// check site, target patterns
comment|// CHECK: 0, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqTwoTarget_1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 1, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqTwoTarget_2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 2, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqTwoTarget_3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 3, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqTwoTarget_4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 4, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqThreeTarget_1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 5, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqThreeTarget_2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 6, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqThreeTarget_3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 7, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqThreeTarget_4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 8, callee_0
comment|// CHECK-NEXT: 8, callee_1
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqThreeTarget_1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 9, callee_0
comment|// CHECK-NEXT: 9, callee_1
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqThreeTarget_2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 10, callee_0
comment|// CHECK-NEXT: 10, callee_1
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqThreeTarget_3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 11, callee_0
comment|// CHECK-NEXT: 11, callee_1
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqThreeTarget_4
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 12, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 13, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 14, callee_0
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 15, callee_0
comment|// CHECK-NEXT: 15, callee_3
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 16, callee_0
comment|// CHECK-NEXT: 16, callee_3
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 17, callee_0
comment|// CHECK-NEXT: 17, callee_3
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 18, callee_0
comment|// CHECK-NEXT: 18, callee_3
comment|// CHECK-NEXT: 18, callee_2
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 19, callee_0
comment|// CHECK-NEXT: 19, callee_3
comment|// CHECK-NEXT: 19, callee_2
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: 20, callee_0
comment|// CHECK-NEXT: 20, callee_3
comment|// CHECK-NEXT: 20, callee_2
name|INDIRECT_CALLSITE
argument_list|(
name|CallSeqFourTarget_3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

