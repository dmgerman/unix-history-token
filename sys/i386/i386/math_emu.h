begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * linux/include/linux/math_emu.h  *  * (C) 1991 Linus Torvalds  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MATH_EMU_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MATH_EMU_H
end_define

begin_comment
comment|/*#define math_abort(x,y) \ (((volatile void (*)(struct info *,unsigned int)) __math_abort)((x),(y)))*/
end_comment

begin_comment
comment|/*  * Gcc forces this stupid alignment problem: I want to use only two int32_t's  * for the temporary real 64-bit mantissa, but then gcc aligns out the  * structure to 12 bytes which breaks things in math_emulate.c. Shit. I  * want some kind of "no-alignt" pragma or something.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|a
decl_stmt|,
name|b
decl_stmt|;
name|short
name|exponent
decl_stmt|;
block|}
name|temp_real
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|m0
decl_stmt|,
name|m1
decl_stmt|,
name|m2
decl_stmt|,
name|m3
decl_stmt|;
name|short
name|exponent
decl_stmt|;
block|}
name|temp_real_unaligned
typedef|;
end_typedef

begin_define
define|#
directive|define
name|real_to_real
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((*(long long *) (b) = *(long long *) (a)),((b)->exponent = (a)->exponent))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|long_real
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|short_real
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|a
decl_stmt|,
name|b
decl_stmt|;
name|short
name|sign
decl_stmt|;
block|}
name|temp_int
typedef|;
end_typedef

begin_struct
struct|struct
name|swd
block|{
name|int
name|ie
range|:
literal|1
decl_stmt|;
name|int
name|de
range|:
literal|1
decl_stmt|;
name|int
name|ze
range|:
literal|1
decl_stmt|;
name|int
name|oe
range|:
literal|1
decl_stmt|;
name|int
name|ue
range|:
literal|1
decl_stmt|;
name|int
name|pe
range|:
literal|1
decl_stmt|;
name|int
name|sf
range|:
literal|1
decl_stmt|;
name|int
name|ir
range|:
literal|1
decl_stmt|;
name|int
name|c0
range|:
literal|1
decl_stmt|;
name|int
name|c1
range|:
literal|1
decl_stmt|;
name|int
name|c2
range|:
literal|1
decl_stmt|;
name|int
name|top
range|:
literal|3
decl_stmt|;
name|int
name|c3
range|:
literal|1
decl_stmt|;
name|int
name|b
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i387_struct
block|{
name|int32_t
name|cwd
decl_stmt|;
name|int32_t
name|swd
decl_stmt|;
name|int32_t
name|twd
decl_stmt|;
name|int32_t
name|fip
decl_stmt|;
name|int32_t
name|fcs
decl_stmt|;
name|int32_t
name|foo
decl_stmt|;
name|int32_t
name|fos
decl_stmt|;
name|int32_t
name|st_space
index|[
literal|20
index|]
decl_stmt|;
comment|/* 8*10 bytes for each FP-reg = 80 bytes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I387
value|(*(struct i387_struct *)&(((struct pcb *)curproc->p_addr)->pcb_save.sv_87))
end_define

begin_define
define|#
directive|define
name|SWD
value|(*(struct swd *)&I387.swd)
end_define

begin_define
define|#
directive|define
name|ROUNDING
value|((I387.cwd>> 10)& 3)
end_define

begin_define
define|#
directive|define
name|PRECISION
value|((I387.cwd>> 8)& 3)
end_define

begin_define
define|#
directive|define
name|BITS24
value|0
end_define

begin_define
define|#
directive|define
name|BITS53
value|2
end_define

begin_define
define|#
directive|define
name|BITS64
value|3
end_define

begin_define
define|#
directive|define
name|ROUND_NEAREST
value|0
end_define

begin_define
define|#
directive|define
name|ROUND_DOWN
value|1
end_define

begin_define
define|#
directive|define
name|ROUND_UP
value|2
end_define

begin_define
define|#
directive|define
name|ROUND_0
value|3
end_define

begin_define
define|#
directive|define
name|CONSTZ
value|(temp_real_unaligned) {0x0000,0x0000,0x0000,0x0000,0x0000}
end_define

begin_define
define|#
directive|define
name|CONST1
value|(temp_real_unaligned) {0x0000,0x0000,0x0000,0x8000,0x3FFF}
end_define

begin_define
define|#
directive|define
name|CONSTPI
value|(temp_real_unaligned) {0xC235,0x2168,0xDAA2,0xC90F,0x4000}
end_define

begin_define
define|#
directive|define
name|CONSTLN2
value|(temp_real_unaligned) {0x79AC,0xD1CF,0x17F7,0xB172,0x3FFE}
end_define

begin_define
define|#
directive|define
name|CONSTLG2
value|(temp_real_unaligned) {0xF799,0xFBCF,0x9A84,0x9A20,0x3FFD}
end_define

begin_define
define|#
directive|define
name|CONSTL2E
value|(temp_real_unaligned) {0xF0BC,0x5C17,0x3B29,0xB8AA,0x3FFF}
end_define

begin_define
define|#
directive|define
name|CONSTL2T
value|(temp_real_unaligned) {0x8AFE,0xCD1B,0x784B,0xD49A,0x4000}
end_define

begin_define
define|#
directive|define
name|set_IE
parameter_list|()
value|(I387.swd |= 1)
end_define

begin_define
define|#
directive|define
name|set_DE
parameter_list|()
value|(I387.swd |= 2)
end_define

begin_define
define|#
directive|define
name|set_ZE
parameter_list|()
value|(I387.swd |= 4)
end_define

begin_define
define|#
directive|define
name|set_OE
parameter_list|()
value|(I387.swd |= 8)
end_define

begin_define
define|#
directive|define
name|set_UE
parameter_list|()
value|(I387.swd |= 16)
end_define

begin_define
define|#
directive|define
name|set_PE
parameter_list|()
value|(I387.swd |= 32)
end_define

begin_define
define|#
directive|define
name|set_C0
parameter_list|()
value|(I387.swd |= 0x0100)
end_define

begin_define
define|#
directive|define
name|set_C1
parameter_list|()
value|(I387.swd |= 0x0200)
end_define

begin_define
define|#
directive|define
name|set_C2
parameter_list|()
value|(I387.swd |= 0x0400)
end_define

begin_define
define|#
directive|define
name|set_C3
parameter_list|()
value|(I387.swd |= 0x4000)
end_define

begin_comment
comment|/* ea.c */
end_comment

begin_function_decl
specifier|static
name|char
modifier|*
name|ea
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convert.c */
end_comment

begin_function_decl
specifier|static
name|void
name|frndint
parameter_list|(
specifier|const
name|temp_real
modifier|*
name|__a
parameter_list|,
name|temp_real
modifier|*
name|__b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|Fscale
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|temp_real
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|short_to_temp
parameter_list|(
specifier|const
name|short_real
modifier|*
name|__a
parameter_list|,
name|temp_real
modifier|*
name|__b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|long_to_temp
parameter_list|(
specifier|const
name|long_real
modifier|*
name|__a
parameter_list|,
name|temp_real
modifier|*
name|__b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|temp_to_short
parameter_list|(
specifier|const
name|temp_real
modifier|*
name|__a
parameter_list|,
name|short_real
modifier|*
name|__b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|temp_to_long
parameter_list|(
specifier|const
name|temp_real
modifier|*
name|__a
parameter_list|,
name|long_real
modifier|*
name|__b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|real_to_int
parameter_list|(
specifier|const
name|temp_real
modifier|*
name|__a
parameter_list|,
name|temp_int
modifier|*
name|__b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|int_to_real
parameter_list|(
specifier|const
name|temp_int
modifier|*
name|__a
parameter_list|,
name|temp_real
modifier|*
name|__b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get_put.c */
end_comment

begin_function_decl
specifier|static
name|void
name|get_short_real
parameter_list|(
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|get_long_real
parameter_list|(
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|get_temp_real
parameter_list|(
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|get_short_int
parameter_list|(
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|get_long_int
parameter_list|(
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|get_longlong_int
parameter_list|(
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|get_BCD
parameter_list|(
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|put_short_real
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|put_long_real
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|put_temp_real
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|put_short_int
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|put_long_int
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|put_longlong_int
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|put_BCD
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* add.c */
end_comment

begin_function_decl
specifier|static
name|void
name|fadd
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|temp_real
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mul.c */
end_comment

begin_function_decl
specifier|static
name|void
name|fmul
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|temp_real
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* div.c */
end_comment

begin_function_decl
specifier|static
name|void
name|fdiv
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
specifier|const
name|temp_real
modifier|*
parameter_list|,
name|temp_real
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* compare.c */
end_comment

begin_function_decl
specifier|static
name|void
name|fcom
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
specifier|const
name|temp_real
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|fucom
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|,
specifier|const
name|temp_real
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ftst
parameter_list|(
specifier|const
name|temp_real
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

