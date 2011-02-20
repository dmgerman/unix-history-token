begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|e
decl_stmt|,
name|f
decl_stmt|,
name|g
decl_stmt|,
name|h
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|,
name|l
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|(""             : [a] "+r" (a), [b] "+r" (b), [c] "+r" (c), [d] "+r" (d),               [e] "+r" (e), [f] "+r" (f), [g] "+r" (g), [h] "+r" (h),               [i] "+r" (i), [j] "+r" (j), [k] "+r" (k), [l] "+r" (l));
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|(""             : [a] "+r,m" (a), [b] "+r,m" (b), [c] "+r,m" (c), [d] "+r,m" (d),               [e] "+r,m" (e), [f] "+r,m" (f), [g] "+r,m" (g), [h] "+r,m" (h),               [i] "+r,m" (i), [j] "+r,m" (j), [k] "+r,m" (k), [l] "+r,m" (l));
block|}
end_function

begin_function
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|(""             : [a] "=r" (a), [b] "=r" (b), [c] "=r" (c), [d] "=r" (d),               [e] "=r" (e), [f] "=r" (f), [g] "=r" (g), [h] "=r" (h),               [i] "=r" (i), [j] "=r" (j), [k] "=r" (k), [l] "=r" (l)             : "[a]" (a), "[b]" (b), "[c]" (c), "[d]" (d),               "[e]" (e), "[f]" (f), "[g]" (g), "[h]" (h),               "[i]" (i), "[j]" (j), "[k]" (k), "[l]" (l));
block|}
end_function

begin_function
name|void
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|(""             : [a] "=r,m" (a), [b] "=r,m" (b), [c] "=r,m" (c), [d] "=r,m" (d),               [e] "=r,m" (e), [f] "=r,m" (f), [g] "=r,m" (g), [h] "=r,m" (h),               [i] "=r,m" (i), [j] "=r,m" (j), [k] "=r,m" (k), [l] "=r,m" (l)             : "[a],m" (a), "[b],m" (b), "[c],m" (c), "[d],m" (d),               "[e],m" (e), "[f],m" (f), "[g],m" (g), "[h],m" (h),               "[i],m" (i), "[j],m" (j), "[k],m" (k), "[l],m" (l));
block|}
end_function

end_unit

