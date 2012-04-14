begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -ccc-clang-archs mipsel -S -o - -emit-llvm %s
end_comment

begin_comment
comment|/*     This checks that the frontend will accept both     enumerated and symbolic Mips GPR register names.          Any bad names will make the frontend choke.  */
end_comment

begin_function
name|main
parameter_list|()
block|{
asm|__asm__
specifier|__volatile__
asm|(".set noat \n\t addi $7,$at,77":::"at");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$v0,77":::"v0");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$v1,77":::"v1");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$a0,77":::"a0");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$a1,77":::"a1");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$a2,77":::"a2");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$a3,77":::"a3");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t0,77":::"t0");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t1,77":::"t1");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t2,77":::"t2");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t3,77":::"t3");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t4,77":::"t4");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t5,77":::"t5");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t6,77":::"t6");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t7,77":::"t7");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$s0,77":::"s0");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$s1,77":::"s1");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$s2,77":::"s2");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$s3,77":::"s3");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$s4,77":::"s4");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$s5,77":::"s5");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$s6,77":::"s6");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$s7,77":::"s7");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t8,77":::"t8");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$t9,77":::"t9");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$k0,77":::"k0");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$k1,77":::"k1");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$gp,77":::"gp");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$sp,77":::"sp");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$fp,77":::"fp");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$sp,77":::"$sp");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$fp,77":::"$fp");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$ra,77":::"ra");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$0,77":::"$0");
asm|__asm__
specifier|__volatile__
asm|(".set noat \n\t addi $7,$1,77":::"$1");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$2,77":::"$2");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$3,77":::"$3");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$4,77":::"$4");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$5,77":::"$5");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$6,77":::"$6");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$7,77":::"$7");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$8,77":::"$8");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$9,77":::"$9");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$10,77":::"$10");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$11,77":::"$10");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$12,77":::"$12");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$13,77":::"$13");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$14,77":::"$14");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$15,77":::"$15");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$16,77":::"$16");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$17,77":::"$17");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$18,77":::"$18");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$19,77":::"$19");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$20,77":::"$20");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$21,77":::"$21");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$22,77":::"$22");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$23,77":::"$23");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$24,77":::"$24");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$25,77":::"$25");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$26,77":::"$26");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$27,77":::"$27");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$28,77":::"$28");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$29,77":::"$29");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$30,77":::"$30");
asm|__asm__
specifier|__volatile__
asm|("addi $7,$31,77":::"$31");
block|}
end_function

end_unit

