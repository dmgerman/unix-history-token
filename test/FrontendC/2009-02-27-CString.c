begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %llvmgcc %s -S -o - -emit-llvm | \    RUN: egrep {CSTRING SECTION.\*section.\*__TEXT,.\*__cstring}    XFAIL: *    XTARGET: darwin    END.    Insure that stings go to the cstring section.  This test is    intended solely for Darwin targets.  */
end_comment

begin_function
name|char
modifier|*
name|foo
parameter_list|()
block|{
return|return
literal|"this string should go to the CSTRING SECTION"
return|;
block|}
end_function

end_unit

