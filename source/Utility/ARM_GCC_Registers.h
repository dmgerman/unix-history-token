begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARM_GCC_Registers.h -------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|utility_ARM_GCC_Registers_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_ARM_GCC_Registers_h_
end_define

begin_enum
enum|enum
block|{
name|gcc_r0
init|=
literal|0
block|,
name|gcc_r1
block|,
name|gcc_r2
block|,
name|gcc_r3
block|,
name|gcc_r4
block|,
name|gcc_r5
block|,
name|gcc_r6
block|,
name|gcc_r7
block|,
name|gcc_r8
block|,
name|gcc_r9
block|,
name|gcc_r10
block|,
name|gcc_r11
block|,
name|gcc_r12
block|,
name|gcc_sp
block|,
name|gcc_lr
block|,
name|gcc_pc
block|,
name|gcc_cpsr
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|//  Name                    Nr   Rel Offset    Size  Type            Raw value
name|gdb_arm_r0
init|=
literal|0
block|,
comment|//  0      0       4 int32_t
name|gdb_arm_r1
init|=
literal|1
block|,
comment|//  1      4       4 int32_t
name|gdb_arm_r2
init|=
literal|2
block|,
comment|//  2      8       4 int32_t
name|gdb_arm_r3
init|=
literal|3
block|,
comment|//  3     12       4 int32_t
name|gdb_arm_r4
init|=
literal|4
block|,
comment|//  4     16       4 int32_t
name|gdb_arm_r5
init|=
literal|5
block|,
comment|//  5     20       4 int32_t
name|gdb_arm_r6
init|=
literal|6
block|,
comment|//  6     24       4 int32_t
name|gdb_arm_r7
init|=
literal|7
block|,
comment|//  7     28       4 int32_t
name|gdb_arm_r8
init|=
literal|8
block|,
comment|//  8     32       4 int32_t
name|gdb_arm_r9
init|=
literal|9
block|,
comment|//  9     36       4 int32_t
name|gdb_arm_r10
init|=
literal|10
block|,
comment|// 10     40       4 int32_t
name|gdb_arm_r11
init|=
literal|11
block|,
comment|// 11     44       4 int32_t
name|gdb_arm_r12
init|=
literal|12
block|,
comment|// 12     48       4 int32_t
name|gdb_arm_sp
init|=
literal|13
block|,
comment|// 13     52       4 int32_t
name|gdb_arm_lr
init|=
literal|14
block|,
comment|// 14     56       4 int32_t
name|gdb_arm_pc
init|=
literal|15
block|,
comment|// 15     60       4 int32_t
name|gdb_arm_f0
init|=
literal|16
block|,
comment|// 16     64      12 _arm_ext_littlebyte_bigword
name|gdb_arm_f1
init|=
literal|17
block|,
comment|// 17     76      12 _arm_ext_littlebyte_bigword
name|gdb_arm_f2
init|=
literal|18
block|,
comment|// 18     88      12 _arm_ext_littlebyte_bigword
name|gdb_arm_f3
init|=
literal|19
block|,
comment|// 19    100      12 _arm_ext_littlebyte_bigword
name|gdb_arm_f4
init|=
literal|20
block|,
comment|// 20    112      12 _arm_ext_littlebyte_bigword
name|gdb_arm_f5
init|=
literal|21
block|,
comment|// 21    124      12 _arm_ext_littlebyte_bigword
name|gdb_arm_f6
init|=
literal|22
block|,
comment|// 22    136      12 _arm_ext_littlebyte_bigword
name|gdb_arm_f7
init|=
literal|23
block|,
comment|// 23    148      12 _arm_ext_littlebyte_bigword
name|gdb_arm_f8
init|=
literal|24
block|,
comment|// 24    160      12 _arm_ext_littlebyte_bigword
name|gdb_arm_cpsr
init|=
literal|25
block|,
comment|// 25    172       4 int32_t
name|gdb_arm_s0
init|=
literal|26
block|,
comment|// 26    176       4 _ieee_single_little
name|gdb_arm_s1
init|=
literal|27
block|,
comment|// 27    180       4 _ieee_single_little
name|gdb_arm_s2
init|=
literal|28
block|,
comment|// 28    184       4 _ieee_single_little
name|gdb_arm_s3
init|=
literal|29
block|,
comment|// 29    188       4 _ieee_single_little
name|gdb_arm_s4
init|=
literal|30
block|,
comment|// 30    192       4 _ieee_single_little
name|gdb_arm_s5
init|=
literal|31
block|,
comment|// 31    196       4 _ieee_single_little
name|gdb_arm_s6
init|=
literal|32
block|,
comment|// 32    200       4 _ieee_single_little
name|gdb_arm_s7
init|=
literal|33
block|,
comment|// 33    204       4 _ieee_single_little
name|gdb_arm_s8
init|=
literal|34
block|,
comment|// 34    208       4 _ieee_single_little
name|gdb_arm_s9
init|=
literal|35
block|,
comment|// 35    212       4 _ieee_single_little
name|gdb_arm_s10
init|=
literal|36
block|,
comment|// 36    216       4 _ieee_single_little
name|gdb_arm_s11
init|=
literal|37
block|,
comment|// 37    220       4 _ieee_single_little
name|gdb_arm_s12
init|=
literal|38
block|,
comment|// 38    224       4 _ieee_single_little
name|gdb_arm_s13
init|=
literal|39
block|,
comment|// 39    228       4 _ieee_single_little
name|gdb_arm_s14
init|=
literal|40
block|,
comment|// 40    232       4 _ieee_single_little
name|gdb_arm_s15
init|=
literal|41
block|,
comment|// 41    236       4 _ieee_single_little
name|gdb_arm_s16
init|=
literal|42
block|,
comment|// 42    240       4 _ieee_single_little
name|gdb_arm_s17
init|=
literal|43
block|,
comment|// 43    244       4 _ieee_single_little
name|gdb_arm_s18
init|=
literal|44
block|,
comment|// 44    248       4 _ieee_single_little
name|gdb_arm_s19
init|=
literal|45
block|,
comment|// 45    252       4 _ieee_single_little
name|gdb_arm_s20
init|=
literal|46
block|,
comment|// 46    256       4 _ieee_single_little
name|gdb_arm_s21
init|=
literal|47
block|,
comment|// 47    260       4 _ieee_single_little
name|gdb_arm_s22
init|=
literal|48
block|,
comment|// 48    264       4 _ieee_single_little
name|gdb_arm_s23
init|=
literal|49
block|,
comment|// 49    268       4 _ieee_single_little
name|gdb_arm_s24
init|=
literal|50
block|,
comment|// 50    272       4 _ieee_single_little
name|gdb_arm_s25
init|=
literal|51
block|,
comment|// 51    276       4 _ieee_single_little
name|gdb_arm_s26
init|=
literal|52
block|,
comment|// 52    280       4 _ieee_single_little
name|gdb_arm_s27
init|=
literal|53
block|,
comment|// 53    284       4 _ieee_single_little
name|gdb_arm_s28
init|=
literal|54
block|,
comment|// 54    288       4 _ieee_single_little
name|gdb_arm_s29
init|=
literal|55
block|,
comment|// 55    292       4 _ieee_single_little
name|gdb_arm_s30
init|=
literal|56
block|,
comment|// 56    296       4 _ieee_single_little
name|gdb_arm_s31
init|=
literal|57
block|,
comment|// 57    300       4 _ieee_single_little
name|gdb_arm_fpscr
init|=
literal|58
block|,
comment|// 58    304       4 int32_t
name|gdb_arm_d16
init|=
literal|59
block|,
comment|// 59    308       8 _ieee_double_little
name|gdb_arm_d17
init|=
literal|60
block|,
comment|// 60    316       8 _ieee_double_little
name|gdb_arm_d18
init|=
literal|61
block|,
comment|// 61    324       8 _ieee_double_little
name|gdb_arm_d19
init|=
literal|62
block|,
comment|// 62    332       8 _ieee_double_little
name|gdb_arm_d20
init|=
literal|63
block|,
comment|// 63    340       8 _ieee_double_little
name|gdb_arm_d21
init|=
literal|64
block|,
comment|// 64    348       8 _ieee_double_little
name|gdb_arm_d22
init|=
literal|65
block|,
comment|// 65    356       8 _ieee_double_little
name|gdb_arm_d23
init|=
literal|66
block|,
comment|// 66    364       8 _ieee_double_little
name|gdb_arm_d24
init|=
literal|67
block|,
comment|// 67    372       8 _ieee_double_little
name|gdb_arm_d25
init|=
literal|68
block|,
comment|// 68    380       8 _ieee_double_little
name|gdb_arm_d26
init|=
literal|69
block|,
comment|// 69    388       8 _ieee_double_little
name|gdb_arm_d27
init|=
literal|70
block|,
comment|// 70    396       8 _ieee_double_little
name|gdb_arm_d28
init|=
literal|71
block|,
comment|// 71    404       8 _ieee_double_little
name|gdb_arm_d29
init|=
literal|72
block|,
comment|// 72    412       8 _ieee_double_little
name|gdb_arm_d30
init|=
literal|73
block|,
comment|// 73    420       8 _ieee_double_little
name|gdb_arm_d31
init|=
literal|74
block|,
comment|// 74    428       8 _ieee_double_little
name|gdb_arm_d0
init|=
literal|75
block|,
comment|//  0    436       8 _ieee_double_little
name|gdb_arm_d1
init|=
literal|76
block|,
comment|//  1    444       8 _ieee_double_little
name|gdb_arm_d2
init|=
literal|77
block|,
comment|//  2    452       8 _ieee_double_little
name|gdb_arm_d3
init|=
literal|78
block|,
comment|//  3    460       8 _ieee_double_little
name|gdb_arm_d4
init|=
literal|79
block|,
comment|//  4    468       8 _ieee_double_little
name|gdb_arm_d5
init|=
literal|80
block|,
comment|//  5    476       8 _ieee_double_little
name|gdb_arm_d6
init|=
literal|81
block|,
comment|//  6    484       8 _ieee_double_little
name|gdb_arm_d7
init|=
literal|82
block|,
comment|//  7    492       8 _ieee_double_little
name|gdb_arm_d8
init|=
literal|83
block|,
comment|//  8    500       8 _ieee_double_little
name|gdb_arm_d9
init|=
literal|84
block|,
comment|//  9    508       8 _ieee_double_little
name|gdb_arm_d10
init|=
literal|85
block|,
comment|// 10    516       8 _ieee_double_little
name|gdb_arm_d11
init|=
literal|86
block|,
comment|// 11    524       8 _ieee_double_little
name|gdb_arm_d12
init|=
literal|87
block|,
comment|// 12    532       8 _ieee_double_little
name|gdb_arm_d13
init|=
literal|88
block|,
comment|// 13    540       8 _ieee_double_little
name|gdb_arm_d14
init|=
literal|89
block|,
comment|// 14    548       8 _ieee_double_little
name|gdb_arm_d15
init|=
literal|90
block|,
comment|// 15    556       8 _ieee_double_little
name|gdb_arm_q0
init|=
literal|91
block|,
comment|// 16    564      16 _vec128
name|gdb_arm_q1
init|=
literal|92
block|,
comment|// 17    580      16 _vec128
name|gdb_arm_q2
init|=
literal|93
block|,
comment|// 18    596      16 _vec128
name|gdb_arm_q3
init|=
literal|94
block|,
comment|// 19    612      16 _vec128
name|gdb_arm_q4
init|=
literal|95
block|,
comment|// 20    628      16 _vec128
name|gdb_arm_q5
init|=
literal|96
block|,
comment|// 21    644      16 _vec128
name|gdb_arm_q6
init|=
literal|97
block|,
comment|// 22    660      16 _vec128
name|gdb_arm_q7
init|=
literal|98
block|,
comment|// 23    676      16 _vec128
name|gdb_arm_q8
init|=
literal|99
block|,
comment|// 24    692      16 _vec128
name|gdb_arm_q9
init|=
literal|100
block|,
comment|// 25    708      16 _vec128
name|gdb_arm_q10
init|=
literal|101
block|,
comment|// 26    724      16 _vec128
name|gdb_arm_q11
init|=
literal|102
block|,
comment|// 27    740      16 _vec128
name|gdb_arm_q12
init|=
literal|103
block|,
comment|// 28    756      16 _vec128
name|gdb_arm_q13
init|=
literal|104
block|,
comment|// 29    772      16 _vec128
name|gdb_arm_q14
init|=
literal|105
block|,
comment|// 30    788      16 _vec128
name|gdb_arm_q15
init|=
literal|106
comment|// 31    804      16 _vec128
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// utility_ARM_GCC_Registers_h_
end_comment

end_unit

