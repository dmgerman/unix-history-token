begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify that the %c modifier works and strips off any prefixes from
end_comment

begin_comment
comment|// immediates.
end_comment

begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llc | grep {pickANumber: 789514}
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
asm|__asm__
specifier|volatile
asm|("/* " "pickANumber" ": %c0 */"::"i"(0xC0C0A));
comment|// Check that non-c modifiers work also (not greped for above).
asm|__asm__
specifier|volatile
asm|("/* " "pickANumber2 " ": %0 */"::"i"(123));
block|}
end_function

end_unit

