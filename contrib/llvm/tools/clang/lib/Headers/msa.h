begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- msa.h - MIPS MSA intrinsics --------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MSA_H
end_ifndef

begin_define
define|#
directive|define
name|_MSA_H
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_msa
argument_list|)
end_if

begin_typedef
typedef|typedef
name|signed
name|char
name|v16i8
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|v16i8_b
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(1)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|v16u8
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|v16u8_b
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(1)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|v8i16
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|v8i16_h
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(2)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|v8u16
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|v8u16_h
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(2)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|v4i32
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|v4i32_w
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(4)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|v4u32
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|v4u32_w
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(4)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|v2i64
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|v2i64_d
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(8)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|v2u64
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|v2u64_d
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(8)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|v4f32
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|v4f32_w
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(4)));
end_typedef

begin_typedef
typedef|typedef
name|double
name|v2f64
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(16)));
end_typedef

begin_typedef
typedef|typedef
name|double
name|v2f64_d
name|__attribute__
typedef|((
name|vector_size
typedef|(16)
operator|,
typedef|aligned(8)));
end_typedef

begin_define
define|#
directive|define
name|__msa_sll_b
value|__builtin_msa_sll_b
end_define

begin_define
define|#
directive|define
name|__msa_sll_h
value|__builtin_msa_sll_h
end_define

begin_define
define|#
directive|define
name|__msa_sll_w
value|__builtin_msa_sll_w
end_define

begin_define
define|#
directive|define
name|__msa_sll_d
value|__builtin_msa_sll_d
end_define

begin_define
define|#
directive|define
name|__msa_slli_b
value|__builtin_msa_slli_b
end_define

begin_define
define|#
directive|define
name|__msa_slli_h
value|__builtin_msa_slli_h
end_define

begin_define
define|#
directive|define
name|__msa_slli_w
value|__builtin_msa_slli_w
end_define

begin_define
define|#
directive|define
name|__msa_slli_d
value|__builtin_msa_slli_d
end_define

begin_define
define|#
directive|define
name|__msa_sra_b
value|__builtin_msa_sra_b
end_define

begin_define
define|#
directive|define
name|__msa_sra_h
value|__builtin_msa_sra_h
end_define

begin_define
define|#
directive|define
name|__msa_sra_w
value|__builtin_msa_sra_w
end_define

begin_define
define|#
directive|define
name|__msa_sra_d
value|__builtin_msa_sra_d
end_define

begin_define
define|#
directive|define
name|__msa_srai_b
value|__builtin_msa_srai_b
end_define

begin_define
define|#
directive|define
name|__msa_srai_h
value|__builtin_msa_srai_h
end_define

begin_define
define|#
directive|define
name|__msa_srai_w
value|__builtin_msa_srai_w
end_define

begin_define
define|#
directive|define
name|__msa_srai_d
value|__builtin_msa_srai_d
end_define

begin_define
define|#
directive|define
name|__msa_srar_b
value|__builtin_msa_srar_b
end_define

begin_define
define|#
directive|define
name|__msa_srar_h
value|__builtin_msa_srar_h
end_define

begin_define
define|#
directive|define
name|__msa_srar_w
value|__builtin_msa_srar_w
end_define

begin_define
define|#
directive|define
name|__msa_srar_d
value|__builtin_msa_srar_d
end_define

begin_define
define|#
directive|define
name|__msa_srari_b
value|__builtin_msa_srari_b
end_define

begin_define
define|#
directive|define
name|__msa_srari_h
value|__builtin_msa_srari_h
end_define

begin_define
define|#
directive|define
name|__msa_srari_w
value|__builtin_msa_srari_w
end_define

begin_define
define|#
directive|define
name|__msa_srari_d
value|__builtin_msa_srari_d
end_define

begin_define
define|#
directive|define
name|__msa_srl_b
value|__builtin_msa_srl_b
end_define

begin_define
define|#
directive|define
name|__msa_srl_h
value|__builtin_msa_srl_h
end_define

begin_define
define|#
directive|define
name|__msa_srl_w
value|__builtin_msa_srl_w
end_define

begin_define
define|#
directive|define
name|__msa_srl_d
value|__builtin_msa_srl_d
end_define

begin_define
define|#
directive|define
name|__msa_srli_b
value|__builtin_msa_srli_b
end_define

begin_define
define|#
directive|define
name|__msa_srli_h
value|__builtin_msa_srli_h
end_define

begin_define
define|#
directive|define
name|__msa_srli_w
value|__builtin_msa_srli_w
end_define

begin_define
define|#
directive|define
name|__msa_srli_d
value|__builtin_msa_srli_d
end_define

begin_define
define|#
directive|define
name|__msa_srlr_b
value|__builtin_msa_srlr_b
end_define

begin_define
define|#
directive|define
name|__msa_srlr_h
value|__builtin_msa_srlr_h
end_define

begin_define
define|#
directive|define
name|__msa_srlr_w
value|__builtin_msa_srlr_w
end_define

begin_define
define|#
directive|define
name|__msa_srlr_d
value|__builtin_msa_srlr_d
end_define

begin_define
define|#
directive|define
name|__msa_srlri_b
value|__builtin_msa_srlri_b
end_define

begin_define
define|#
directive|define
name|__msa_srlri_h
value|__builtin_msa_srlri_h
end_define

begin_define
define|#
directive|define
name|__msa_srlri_w
value|__builtin_msa_srlri_w
end_define

begin_define
define|#
directive|define
name|__msa_srlri_d
value|__builtin_msa_srlri_d
end_define

begin_define
define|#
directive|define
name|__msa_bclr_b
value|__builtin_msa_bclr_b
end_define

begin_define
define|#
directive|define
name|__msa_bclr_h
value|__builtin_msa_bclr_h
end_define

begin_define
define|#
directive|define
name|__msa_bclr_w
value|__builtin_msa_bclr_w
end_define

begin_define
define|#
directive|define
name|__msa_bclr_d
value|__builtin_msa_bclr_d
end_define

begin_define
define|#
directive|define
name|__msa_bclri_b
value|__builtin_msa_bclri_b
end_define

begin_define
define|#
directive|define
name|__msa_bclri_h
value|__builtin_msa_bclri_h
end_define

begin_define
define|#
directive|define
name|__msa_bclri_w
value|__builtin_msa_bclri_w
end_define

begin_define
define|#
directive|define
name|__msa_bclri_d
value|__builtin_msa_bclri_d
end_define

begin_define
define|#
directive|define
name|__msa_bset_b
value|__builtin_msa_bset_b
end_define

begin_define
define|#
directive|define
name|__msa_bset_h
value|__builtin_msa_bset_h
end_define

begin_define
define|#
directive|define
name|__msa_bset_w
value|__builtin_msa_bset_w
end_define

begin_define
define|#
directive|define
name|__msa_bset_d
value|__builtin_msa_bset_d
end_define

begin_define
define|#
directive|define
name|__msa_bseti_b
value|__builtin_msa_bseti_b
end_define

begin_define
define|#
directive|define
name|__msa_bseti_h
value|__builtin_msa_bseti_h
end_define

begin_define
define|#
directive|define
name|__msa_bseti_w
value|__builtin_msa_bseti_w
end_define

begin_define
define|#
directive|define
name|__msa_bseti_d
value|__builtin_msa_bseti_d
end_define

begin_define
define|#
directive|define
name|__msa_bneg_b
value|__builtin_msa_bneg_b
end_define

begin_define
define|#
directive|define
name|__msa_bneg_h
value|__builtin_msa_bneg_h
end_define

begin_define
define|#
directive|define
name|__msa_bneg_w
value|__builtin_msa_bneg_w
end_define

begin_define
define|#
directive|define
name|__msa_bneg_d
value|__builtin_msa_bneg_d
end_define

begin_define
define|#
directive|define
name|__msa_bnegi_b
value|__builtin_msa_bnegi_b
end_define

begin_define
define|#
directive|define
name|__msa_bnegi_h
value|__builtin_msa_bnegi_h
end_define

begin_define
define|#
directive|define
name|__msa_bnegi_w
value|__builtin_msa_bnegi_w
end_define

begin_define
define|#
directive|define
name|__msa_bnegi_d
value|__builtin_msa_bnegi_d
end_define

begin_define
define|#
directive|define
name|__msa_binsl_b
value|__builtin_msa_binsl_b
end_define

begin_define
define|#
directive|define
name|__msa_binsl_h
value|__builtin_msa_binsl_h
end_define

begin_define
define|#
directive|define
name|__msa_binsl_w
value|__builtin_msa_binsl_w
end_define

begin_define
define|#
directive|define
name|__msa_binsl_d
value|__builtin_msa_binsl_d
end_define

begin_define
define|#
directive|define
name|__msa_binsli_b
value|__builtin_msa_binsli_b
end_define

begin_define
define|#
directive|define
name|__msa_binsli_h
value|__builtin_msa_binsli_h
end_define

begin_define
define|#
directive|define
name|__msa_binsli_w
value|__builtin_msa_binsli_w
end_define

begin_define
define|#
directive|define
name|__msa_binsli_d
value|__builtin_msa_binsli_d
end_define

begin_define
define|#
directive|define
name|__msa_binsr_b
value|__builtin_msa_binsr_b
end_define

begin_define
define|#
directive|define
name|__msa_binsr_h
value|__builtin_msa_binsr_h
end_define

begin_define
define|#
directive|define
name|__msa_binsr_w
value|__builtin_msa_binsr_w
end_define

begin_define
define|#
directive|define
name|__msa_binsr_d
value|__builtin_msa_binsr_d
end_define

begin_define
define|#
directive|define
name|__msa_binsri_b
value|__builtin_msa_binsri_b
end_define

begin_define
define|#
directive|define
name|__msa_binsri_h
value|__builtin_msa_binsri_h
end_define

begin_define
define|#
directive|define
name|__msa_binsri_w
value|__builtin_msa_binsri_w
end_define

begin_define
define|#
directive|define
name|__msa_binsri_d
value|__builtin_msa_binsri_d
end_define

begin_define
define|#
directive|define
name|__msa_addv_b
value|__builtin_msa_addv_b
end_define

begin_define
define|#
directive|define
name|__msa_addv_h
value|__builtin_msa_addv_h
end_define

begin_define
define|#
directive|define
name|__msa_addv_w
value|__builtin_msa_addv_w
end_define

begin_define
define|#
directive|define
name|__msa_addv_d
value|__builtin_msa_addv_d
end_define

begin_define
define|#
directive|define
name|__msa_addvi_b
value|__builtin_msa_addvi_b
end_define

begin_define
define|#
directive|define
name|__msa_addvi_h
value|__builtin_msa_addvi_h
end_define

begin_define
define|#
directive|define
name|__msa_addvi_w
value|__builtin_msa_addvi_w
end_define

begin_define
define|#
directive|define
name|__msa_addvi_d
value|__builtin_msa_addvi_d
end_define

begin_define
define|#
directive|define
name|__msa_subv_b
value|__builtin_msa_subv_b
end_define

begin_define
define|#
directive|define
name|__msa_subv_h
value|__builtin_msa_subv_h
end_define

begin_define
define|#
directive|define
name|__msa_subv_w
value|__builtin_msa_subv_w
end_define

begin_define
define|#
directive|define
name|__msa_subv_d
value|__builtin_msa_subv_d
end_define

begin_define
define|#
directive|define
name|__msa_subvi_b
value|__builtin_msa_subvi_b
end_define

begin_define
define|#
directive|define
name|__msa_subvi_h
value|__builtin_msa_subvi_h
end_define

begin_define
define|#
directive|define
name|__msa_subvi_w
value|__builtin_msa_subvi_w
end_define

begin_define
define|#
directive|define
name|__msa_subvi_d
value|__builtin_msa_subvi_d
end_define

begin_define
define|#
directive|define
name|__msa_max_s_b
value|__builtin_msa_max_s_b
end_define

begin_define
define|#
directive|define
name|__msa_max_s_h
value|__builtin_msa_max_s_h
end_define

begin_define
define|#
directive|define
name|__msa_max_s_w
value|__builtin_msa_max_s_w
end_define

begin_define
define|#
directive|define
name|__msa_max_s_d
value|__builtin_msa_max_s_d
end_define

begin_define
define|#
directive|define
name|__msa_maxi_s_b
value|__builtin_msa_maxi_s_b
end_define

begin_define
define|#
directive|define
name|__msa_maxi_s_h
value|__builtin_msa_maxi_s_h
end_define

begin_define
define|#
directive|define
name|__msa_maxi_s_w
value|__builtin_msa_maxi_s_w
end_define

begin_define
define|#
directive|define
name|__msa_maxi_s_d
value|__builtin_msa_maxi_s_d
end_define

begin_define
define|#
directive|define
name|__msa_max_u_b
value|__builtin_msa_max_u_b
end_define

begin_define
define|#
directive|define
name|__msa_max_u_h
value|__builtin_msa_max_u_h
end_define

begin_define
define|#
directive|define
name|__msa_max_u_w
value|__builtin_msa_max_u_w
end_define

begin_define
define|#
directive|define
name|__msa_max_u_d
value|__builtin_msa_max_u_d
end_define

begin_define
define|#
directive|define
name|__msa_maxi_u_b
value|__builtin_msa_maxi_u_b
end_define

begin_define
define|#
directive|define
name|__msa_maxi_u_h
value|__builtin_msa_maxi_u_h
end_define

begin_define
define|#
directive|define
name|__msa_maxi_u_w
value|__builtin_msa_maxi_u_w
end_define

begin_define
define|#
directive|define
name|__msa_maxi_u_d
value|__builtin_msa_maxi_u_d
end_define

begin_define
define|#
directive|define
name|__msa_min_s_b
value|__builtin_msa_min_s_b
end_define

begin_define
define|#
directive|define
name|__msa_min_s_h
value|__builtin_msa_min_s_h
end_define

begin_define
define|#
directive|define
name|__msa_min_s_w
value|__builtin_msa_min_s_w
end_define

begin_define
define|#
directive|define
name|__msa_min_s_d
value|__builtin_msa_min_s_d
end_define

begin_define
define|#
directive|define
name|__msa_mini_s_b
value|__builtin_msa_mini_s_b
end_define

begin_define
define|#
directive|define
name|__msa_mini_s_h
value|__builtin_msa_mini_s_h
end_define

begin_define
define|#
directive|define
name|__msa_mini_s_w
value|__builtin_msa_mini_s_w
end_define

begin_define
define|#
directive|define
name|__msa_mini_s_d
value|__builtin_msa_mini_s_d
end_define

begin_define
define|#
directive|define
name|__msa_min_u_b
value|__builtin_msa_min_u_b
end_define

begin_define
define|#
directive|define
name|__msa_min_u_h
value|__builtin_msa_min_u_h
end_define

begin_define
define|#
directive|define
name|__msa_min_u_w
value|__builtin_msa_min_u_w
end_define

begin_define
define|#
directive|define
name|__msa_min_u_d
value|__builtin_msa_min_u_d
end_define

begin_define
define|#
directive|define
name|__msa_mini_u_b
value|__builtin_msa_mini_u_b
end_define

begin_define
define|#
directive|define
name|__msa_mini_u_h
value|__builtin_msa_mini_u_h
end_define

begin_define
define|#
directive|define
name|__msa_mini_u_w
value|__builtin_msa_mini_u_w
end_define

begin_define
define|#
directive|define
name|__msa_mini_u_d
value|__builtin_msa_mini_u_d
end_define

begin_define
define|#
directive|define
name|__msa_max_a_b
value|__builtin_msa_max_a_b
end_define

begin_define
define|#
directive|define
name|__msa_max_a_h
value|__builtin_msa_max_a_h
end_define

begin_define
define|#
directive|define
name|__msa_max_a_w
value|__builtin_msa_max_a_w
end_define

begin_define
define|#
directive|define
name|__msa_max_a_d
value|__builtin_msa_max_a_d
end_define

begin_define
define|#
directive|define
name|__msa_min_a_b
value|__builtin_msa_min_a_b
end_define

begin_define
define|#
directive|define
name|__msa_min_a_h
value|__builtin_msa_min_a_h
end_define

begin_define
define|#
directive|define
name|__msa_min_a_w
value|__builtin_msa_min_a_w
end_define

begin_define
define|#
directive|define
name|__msa_min_a_d
value|__builtin_msa_min_a_d
end_define

begin_define
define|#
directive|define
name|__msa_ceq_b
value|__builtin_msa_ceq_b
end_define

begin_define
define|#
directive|define
name|__msa_ceq_h
value|__builtin_msa_ceq_h
end_define

begin_define
define|#
directive|define
name|__msa_ceq_w
value|__builtin_msa_ceq_w
end_define

begin_define
define|#
directive|define
name|__msa_ceq_d
value|__builtin_msa_ceq_d
end_define

begin_define
define|#
directive|define
name|__msa_ceqi_b
value|__builtin_msa_ceqi_b
end_define

begin_define
define|#
directive|define
name|__msa_ceqi_h
value|__builtin_msa_ceqi_h
end_define

begin_define
define|#
directive|define
name|__msa_ceqi_w
value|__builtin_msa_ceqi_w
end_define

begin_define
define|#
directive|define
name|__msa_ceqi_d
value|__builtin_msa_ceqi_d
end_define

begin_define
define|#
directive|define
name|__msa_clt_s_b
value|__builtin_msa_clt_s_b
end_define

begin_define
define|#
directive|define
name|__msa_clt_s_h
value|__builtin_msa_clt_s_h
end_define

begin_define
define|#
directive|define
name|__msa_clt_s_w
value|__builtin_msa_clt_s_w
end_define

begin_define
define|#
directive|define
name|__msa_clt_s_d
value|__builtin_msa_clt_s_d
end_define

begin_define
define|#
directive|define
name|__msa_clti_s_b
value|__builtin_msa_clti_s_b
end_define

begin_define
define|#
directive|define
name|__msa_clti_s_h
value|__builtin_msa_clti_s_h
end_define

begin_define
define|#
directive|define
name|__msa_clti_s_w
value|__builtin_msa_clti_s_w
end_define

begin_define
define|#
directive|define
name|__msa_clti_s_d
value|__builtin_msa_clti_s_d
end_define

begin_define
define|#
directive|define
name|__msa_clt_u_b
value|__builtin_msa_clt_u_b
end_define

begin_define
define|#
directive|define
name|__msa_clt_u_h
value|__builtin_msa_clt_u_h
end_define

begin_define
define|#
directive|define
name|__msa_clt_u_w
value|__builtin_msa_clt_u_w
end_define

begin_define
define|#
directive|define
name|__msa_clt_u_d
value|__builtin_msa_clt_u_d
end_define

begin_define
define|#
directive|define
name|__msa_clti_u_b
value|__builtin_msa_clti_u_b
end_define

begin_define
define|#
directive|define
name|__msa_clti_u_h
value|__builtin_msa_clti_u_h
end_define

begin_define
define|#
directive|define
name|__msa_clti_u_w
value|__builtin_msa_clti_u_w
end_define

begin_define
define|#
directive|define
name|__msa_clti_u_d
value|__builtin_msa_clti_u_d
end_define

begin_define
define|#
directive|define
name|__msa_cle_s_b
value|__builtin_msa_cle_s_b
end_define

begin_define
define|#
directive|define
name|__msa_cle_s_h
value|__builtin_msa_cle_s_h
end_define

begin_define
define|#
directive|define
name|__msa_cle_s_w
value|__builtin_msa_cle_s_w
end_define

begin_define
define|#
directive|define
name|__msa_cle_s_d
value|__builtin_msa_cle_s_d
end_define

begin_define
define|#
directive|define
name|__msa_clei_s_b
value|__builtin_msa_clei_s_b
end_define

begin_define
define|#
directive|define
name|__msa_clei_s_h
value|__builtin_msa_clei_s_h
end_define

begin_define
define|#
directive|define
name|__msa_clei_s_w
value|__builtin_msa_clei_s_w
end_define

begin_define
define|#
directive|define
name|__msa_clei_s_d
value|__builtin_msa_clei_s_d
end_define

begin_define
define|#
directive|define
name|__msa_cle_u_b
value|__builtin_msa_cle_u_b
end_define

begin_define
define|#
directive|define
name|__msa_cle_u_h
value|__builtin_msa_cle_u_h
end_define

begin_define
define|#
directive|define
name|__msa_cle_u_w
value|__builtin_msa_cle_u_w
end_define

begin_define
define|#
directive|define
name|__msa_cle_u_d
value|__builtin_msa_cle_u_d
end_define

begin_define
define|#
directive|define
name|__msa_clei_u_b
value|__builtin_msa_clei_u_b
end_define

begin_define
define|#
directive|define
name|__msa_clei_u_h
value|__builtin_msa_clei_u_h
end_define

begin_define
define|#
directive|define
name|__msa_clei_u_w
value|__builtin_msa_clei_u_w
end_define

begin_define
define|#
directive|define
name|__msa_clei_u_d
value|__builtin_msa_clei_u_d
end_define

begin_define
define|#
directive|define
name|__msa_ld_b
value|__builtin_msa_ld_b
end_define

begin_define
define|#
directive|define
name|__msa_ld_h
value|__builtin_msa_ld_h
end_define

begin_define
define|#
directive|define
name|__msa_ld_w
value|__builtin_msa_ld_w
end_define

begin_define
define|#
directive|define
name|__msa_ld_d
value|__builtin_msa_ld_d
end_define

begin_define
define|#
directive|define
name|__msa_st_b
value|__builtin_msa_st_b
end_define

begin_define
define|#
directive|define
name|__msa_st_h
value|__builtin_msa_st_h
end_define

begin_define
define|#
directive|define
name|__msa_st_w
value|__builtin_msa_st_w
end_define

begin_define
define|#
directive|define
name|__msa_st_d
value|__builtin_msa_st_d
end_define

begin_define
define|#
directive|define
name|__msa_sat_s_b
value|__builtin_msa_sat_s_b
end_define

begin_define
define|#
directive|define
name|__msa_sat_s_h
value|__builtin_msa_sat_s_h
end_define

begin_define
define|#
directive|define
name|__msa_sat_s_w
value|__builtin_msa_sat_s_w
end_define

begin_define
define|#
directive|define
name|__msa_sat_s_d
value|__builtin_msa_sat_s_d
end_define

begin_define
define|#
directive|define
name|__msa_sat_u_b
value|__builtin_msa_sat_u_b
end_define

begin_define
define|#
directive|define
name|__msa_sat_u_h
value|__builtin_msa_sat_u_h
end_define

begin_define
define|#
directive|define
name|__msa_sat_u_w
value|__builtin_msa_sat_u_w
end_define

begin_define
define|#
directive|define
name|__msa_sat_u_d
value|__builtin_msa_sat_u_d
end_define

begin_define
define|#
directive|define
name|__msa_add_a_b
value|__builtin_msa_add_a_b
end_define

begin_define
define|#
directive|define
name|__msa_add_a_h
value|__builtin_msa_add_a_h
end_define

begin_define
define|#
directive|define
name|__msa_add_a_w
value|__builtin_msa_add_a_w
end_define

begin_define
define|#
directive|define
name|__msa_add_a_d
value|__builtin_msa_add_a_d
end_define

begin_define
define|#
directive|define
name|__msa_adds_a_b
value|__builtin_msa_adds_a_b
end_define

begin_define
define|#
directive|define
name|__msa_adds_a_h
value|__builtin_msa_adds_a_h
end_define

begin_define
define|#
directive|define
name|__msa_adds_a_w
value|__builtin_msa_adds_a_w
end_define

begin_define
define|#
directive|define
name|__msa_adds_a_d
value|__builtin_msa_adds_a_d
end_define

begin_define
define|#
directive|define
name|__msa_adds_s_b
value|__builtin_msa_adds_s_b
end_define

begin_define
define|#
directive|define
name|__msa_adds_s_h
value|__builtin_msa_adds_s_h
end_define

begin_define
define|#
directive|define
name|__msa_adds_s_w
value|__builtin_msa_adds_s_w
end_define

begin_define
define|#
directive|define
name|__msa_adds_s_d
value|__builtin_msa_adds_s_d
end_define

begin_define
define|#
directive|define
name|__msa_adds_u_b
value|__builtin_msa_adds_u_b
end_define

begin_define
define|#
directive|define
name|__msa_adds_u_h
value|__builtin_msa_adds_u_h
end_define

begin_define
define|#
directive|define
name|__msa_adds_u_w
value|__builtin_msa_adds_u_w
end_define

begin_define
define|#
directive|define
name|__msa_adds_u_d
value|__builtin_msa_adds_u_d
end_define

begin_define
define|#
directive|define
name|__msa_ave_s_b
value|__builtin_msa_ave_s_b
end_define

begin_define
define|#
directive|define
name|__msa_ave_s_h
value|__builtin_msa_ave_s_h
end_define

begin_define
define|#
directive|define
name|__msa_ave_s_w
value|__builtin_msa_ave_s_w
end_define

begin_define
define|#
directive|define
name|__msa_ave_s_d
value|__builtin_msa_ave_s_d
end_define

begin_define
define|#
directive|define
name|__msa_ave_u_b
value|__builtin_msa_ave_u_b
end_define

begin_define
define|#
directive|define
name|__msa_ave_u_h
value|__builtin_msa_ave_u_h
end_define

begin_define
define|#
directive|define
name|__msa_ave_u_w
value|__builtin_msa_ave_u_w
end_define

begin_define
define|#
directive|define
name|__msa_ave_u_d
value|__builtin_msa_ave_u_d
end_define

begin_define
define|#
directive|define
name|__msa_aver_s_b
value|__builtin_msa_aver_s_b
end_define

begin_define
define|#
directive|define
name|__msa_aver_s_h
value|__builtin_msa_aver_s_h
end_define

begin_define
define|#
directive|define
name|__msa_aver_s_w
value|__builtin_msa_aver_s_w
end_define

begin_define
define|#
directive|define
name|__msa_aver_s_d
value|__builtin_msa_aver_s_d
end_define

begin_define
define|#
directive|define
name|__msa_aver_u_b
value|__builtin_msa_aver_u_b
end_define

begin_define
define|#
directive|define
name|__msa_aver_u_h
value|__builtin_msa_aver_u_h
end_define

begin_define
define|#
directive|define
name|__msa_aver_u_w
value|__builtin_msa_aver_u_w
end_define

begin_define
define|#
directive|define
name|__msa_aver_u_d
value|__builtin_msa_aver_u_d
end_define

begin_define
define|#
directive|define
name|__msa_subs_s_b
value|__builtin_msa_subs_s_b
end_define

begin_define
define|#
directive|define
name|__msa_subs_s_h
value|__builtin_msa_subs_s_h
end_define

begin_define
define|#
directive|define
name|__msa_subs_s_w
value|__builtin_msa_subs_s_w
end_define

begin_define
define|#
directive|define
name|__msa_subs_s_d
value|__builtin_msa_subs_s_d
end_define

begin_define
define|#
directive|define
name|__msa_subs_u_b
value|__builtin_msa_subs_u_b
end_define

begin_define
define|#
directive|define
name|__msa_subs_u_h
value|__builtin_msa_subs_u_h
end_define

begin_define
define|#
directive|define
name|__msa_subs_u_w
value|__builtin_msa_subs_u_w
end_define

begin_define
define|#
directive|define
name|__msa_subs_u_d
value|__builtin_msa_subs_u_d
end_define

begin_define
define|#
directive|define
name|__msa_subsuu_s_b
value|__builtin_msa_subsuu_s_b
end_define

begin_define
define|#
directive|define
name|__msa_subsuu_s_h
value|__builtin_msa_subsuu_s_h
end_define

begin_define
define|#
directive|define
name|__msa_subsuu_s_w
value|__builtin_msa_subsuu_s_w
end_define

begin_define
define|#
directive|define
name|__msa_subsuu_s_d
value|__builtin_msa_subsuu_s_d
end_define

begin_define
define|#
directive|define
name|__msa_subsus_u_b
value|__builtin_msa_subsus_u_b
end_define

begin_define
define|#
directive|define
name|__msa_subsus_u_h
value|__builtin_msa_subsus_u_h
end_define

begin_define
define|#
directive|define
name|__msa_subsus_u_w
value|__builtin_msa_subsus_u_w
end_define

begin_define
define|#
directive|define
name|__msa_subsus_u_d
value|__builtin_msa_subsus_u_d
end_define

begin_define
define|#
directive|define
name|__msa_asub_s_b
value|__builtin_msa_asub_s_b
end_define

begin_define
define|#
directive|define
name|__msa_asub_s_h
value|__builtin_msa_asub_s_h
end_define

begin_define
define|#
directive|define
name|__msa_asub_s_w
value|__builtin_msa_asub_s_w
end_define

begin_define
define|#
directive|define
name|__msa_asub_s_d
value|__builtin_msa_asub_s_d
end_define

begin_define
define|#
directive|define
name|__msa_asub_u_b
value|__builtin_msa_asub_u_b
end_define

begin_define
define|#
directive|define
name|__msa_asub_u_h
value|__builtin_msa_asub_u_h
end_define

begin_define
define|#
directive|define
name|__msa_asub_u_w
value|__builtin_msa_asub_u_w
end_define

begin_define
define|#
directive|define
name|__msa_asub_u_d
value|__builtin_msa_asub_u_d
end_define

begin_define
define|#
directive|define
name|__msa_mulv_b
value|__builtin_msa_mulv_b
end_define

begin_define
define|#
directive|define
name|__msa_mulv_h
value|__builtin_msa_mulv_h
end_define

begin_define
define|#
directive|define
name|__msa_mulv_w
value|__builtin_msa_mulv_w
end_define

begin_define
define|#
directive|define
name|__msa_mulv_d
value|__builtin_msa_mulv_d
end_define

begin_define
define|#
directive|define
name|__msa_maddv_b
value|__builtin_msa_maddv_b
end_define

begin_define
define|#
directive|define
name|__msa_maddv_h
value|__builtin_msa_maddv_h
end_define

begin_define
define|#
directive|define
name|__msa_maddv_w
value|__builtin_msa_maddv_w
end_define

begin_define
define|#
directive|define
name|__msa_maddv_d
value|__builtin_msa_maddv_d
end_define

begin_define
define|#
directive|define
name|__msa_msubv_b
value|__builtin_msa_msubv_b
end_define

begin_define
define|#
directive|define
name|__msa_msubv_h
value|__builtin_msa_msubv_h
end_define

begin_define
define|#
directive|define
name|__msa_msubv_w
value|__builtin_msa_msubv_w
end_define

begin_define
define|#
directive|define
name|__msa_msubv_d
value|__builtin_msa_msubv_d
end_define

begin_define
define|#
directive|define
name|__msa_div_s_b
value|__builtin_msa_div_s_b
end_define

begin_define
define|#
directive|define
name|__msa_div_s_h
value|__builtin_msa_div_s_h
end_define

begin_define
define|#
directive|define
name|__msa_div_s_w
value|__builtin_msa_div_s_w
end_define

begin_define
define|#
directive|define
name|__msa_div_s_d
value|__builtin_msa_div_s_d
end_define

begin_define
define|#
directive|define
name|__msa_div_u_b
value|__builtin_msa_div_u_b
end_define

begin_define
define|#
directive|define
name|__msa_div_u_h
value|__builtin_msa_div_u_h
end_define

begin_define
define|#
directive|define
name|__msa_div_u_w
value|__builtin_msa_div_u_w
end_define

begin_define
define|#
directive|define
name|__msa_div_u_d
value|__builtin_msa_div_u_d
end_define

begin_define
define|#
directive|define
name|__msa_hadd_s_h
value|__builtin_msa_hadd_s_h
end_define

begin_define
define|#
directive|define
name|__msa_hadd_s_w
value|__builtin_msa_hadd_s_w
end_define

begin_define
define|#
directive|define
name|__msa_hadd_s_d
value|__builtin_msa_hadd_s_d
end_define

begin_define
define|#
directive|define
name|__msa_hadd_u_h
value|__builtin_msa_hadd_u_h
end_define

begin_define
define|#
directive|define
name|__msa_hadd_u_w
value|__builtin_msa_hadd_u_w
end_define

begin_define
define|#
directive|define
name|__msa_hadd_u_d
value|__builtin_msa_hadd_u_d
end_define

begin_define
define|#
directive|define
name|__msa_hsub_s_h
value|__builtin_msa_hsub_s_h
end_define

begin_define
define|#
directive|define
name|__msa_hsub_s_w
value|__builtin_msa_hsub_s_w
end_define

begin_define
define|#
directive|define
name|__msa_hsub_s_d
value|__builtin_msa_hsub_s_d
end_define

begin_define
define|#
directive|define
name|__msa_hsub_u_h
value|__builtin_msa_hsub_u_h
end_define

begin_define
define|#
directive|define
name|__msa_hsub_u_w
value|__builtin_msa_hsub_u_w
end_define

begin_define
define|#
directive|define
name|__msa_hsub_u_d
value|__builtin_msa_hsub_u_d
end_define

begin_define
define|#
directive|define
name|__msa_mod_s_b
value|__builtin_msa_mod_s_b
end_define

begin_define
define|#
directive|define
name|__msa_mod_s_h
value|__builtin_msa_mod_s_h
end_define

begin_define
define|#
directive|define
name|__msa_mod_s_w
value|__builtin_msa_mod_s_w
end_define

begin_define
define|#
directive|define
name|__msa_mod_s_d
value|__builtin_msa_mod_s_d
end_define

begin_define
define|#
directive|define
name|__msa_mod_u_b
value|__builtin_msa_mod_u_b
end_define

begin_define
define|#
directive|define
name|__msa_mod_u_h
value|__builtin_msa_mod_u_h
end_define

begin_define
define|#
directive|define
name|__msa_mod_u_w
value|__builtin_msa_mod_u_w
end_define

begin_define
define|#
directive|define
name|__msa_mod_u_d
value|__builtin_msa_mod_u_d
end_define

begin_define
define|#
directive|define
name|__msa_dotp_s_h
value|__builtin_msa_dotp_s_h
end_define

begin_define
define|#
directive|define
name|__msa_dotp_s_w
value|__builtin_msa_dotp_s_w
end_define

begin_define
define|#
directive|define
name|__msa_dotp_s_d
value|__builtin_msa_dotp_s_d
end_define

begin_define
define|#
directive|define
name|__msa_dotp_u_h
value|__builtin_msa_dotp_u_h
end_define

begin_define
define|#
directive|define
name|__msa_dotp_u_w
value|__builtin_msa_dotp_u_w
end_define

begin_define
define|#
directive|define
name|__msa_dotp_u_d
value|__builtin_msa_dotp_u_d
end_define

begin_define
define|#
directive|define
name|__msa_dpadd_s_h
value|__builtin_msa_dpadd_s_h
end_define

begin_define
define|#
directive|define
name|__msa_dpadd_s_w
value|__builtin_msa_dpadd_s_w
end_define

begin_define
define|#
directive|define
name|__msa_dpadd_s_d
value|__builtin_msa_dpadd_s_d
end_define

begin_define
define|#
directive|define
name|__msa_dpadd_u_h
value|__builtin_msa_dpadd_u_h
end_define

begin_define
define|#
directive|define
name|__msa_dpadd_u_w
value|__builtin_msa_dpadd_u_w
end_define

begin_define
define|#
directive|define
name|__msa_dpadd_u_d
value|__builtin_msa_dpadd_u_d
end_define

begin_define
define|#
directive|define
name|__msa_dpsub_s_h
value|__builtin_msa_dpsub_s_h
end_define

begin_define
define|#
directive|define
name|__msa_dpsub_s_w
value|__builtin_msa_dpsub_s_w
end_define

begin_define
define|#
directive|define
name|__msa_dpsub_s_d
value|__builtin_msa_dpsub_s_d
end_define

begin_define
define|#
directive|define
name|__msa_dpsub_u_h
value|__builtin_msa_dpsub_u_h
end_define

begin_define
define|#
directive|define
name|__msa_dpsub_u_w
value|__builtin_msa_dpsub_u_w
end_define

begin_define
define|#
directive|define
name|__msa_dpsub_u_d
value|__builtin_msa_dpsub_u_d
end_define

begin_define
define|#
directive|define
name|__msa_sld_b
value|__builtin_msa_sld_b
end_define

begin_define
define|#
directive|define
name|__msa_sld_h
value|__builtin_msa_sld_h
end_define

begin_define
define|#
directive|define
name|__msa_sld_w
value|__builtin_msa_sld_w
end_define

begin_define
define|#
directive|define
name|__msa_sld_d
value|__builtin_msa_sld_d
end_define

begin_define
define|#
directive|define
name|__msa_sldi_b
value|__builtin_msa_sldi_b
end_define

begin_define
define|#
directive|define
name|__msa_sldi_h
value|__builtin_msa_sldi_h
end_define

begin_define
define|#
directive|define
name|__msa_sldi_w
value|__builtin_msa_sldi_w
end_define

begin_define
define|#
directive|define
name|__msa_sldi_d
value|__builtin_msa_sldi_d
end_define

begin_define
define|#
directive|define
name|__msa_splat_b
value|__builtin_msa_splat_b
end_define

begin_define
define|#
directive|define
name|__msa_splat_h
value|__builtin_msa_splat_h
end_define

begin_define
define|#
directive|define
name|__msa_splat_w
value|__builtin_msa_splat_w
end_define

begin_define
define|#
directive|define
name|__msa_splat_d
value|__builtin_msa_splat_d
end_define

begin_define
define|#
directive|define
name|__msa_splati_b
value|__builtin_msa_splati_b
end_define

begin_define
define|#
directive|define
name|__msa_splati_h
value|__builtin_msa_splati_h
end_define

begin_define
define|#
directive|define
name|__msa_splati_w
value|__builtin_msa_splati_w
end_define

begin_define
define|#
directive|define
name|__msa_splati_d
value|__builtin_msa_splati_d
end_define

begin_define
define|#
directive|define
name|__msa_pckev_b
value|__builtin_msa_pckev_b
end_define

begin_define
define|#
directive|define
name|__msa_pckev_h
value|__builtin_msa_pckev_h
end_define

begin_define
define|#
directive|define
name|__msa_pckev_w
value|__builtin_msa_pckev_w
end_define

begin_define
define|#
directive|define
name|__msa_pckev_d
value|__builtin_msa_pckev_d
end_define

begin_define
define|#
directive|define
name|__msa_pckod_b
value|__builtin_msa_pckod_b
end_define

begin_define
define|#
directive|define
name|__msa_pckod_h
value|__builtin_msa_pckod_h
end_define

begin_define
define|#
directive|define
name|__msa_pckod_w
value|__builtin_msa_pckod_w
end_define

begin_define
define|#
directive|define
name|__msa_pckod_d
value|__builtin_msa_pckod_d
end_define

begin_define
define|#
directive|define
name|__msa_ilvl_b
value|__builtin_msa_ilvl_b
end_define

begin_define
define|#
directive|define
name|__msa_ilvl_h
value|__builtin_msa_ilvl_h
end_define

begin_define
define|#
directive|define
name|__msa_ilvl_w
value|__builtin_msa_ilvl_w
end_define

begin_define
define|#
directive|define
name|__msa_ilvl_d
value|__builtin_msa_ilvl_d
end_define

begin_define
define|#
directive|define
name|__msa_ilvr_b
value|__builtin_msa_ilvr_b
end_define

begin_define
define|#
directive|define
name|__msa_ilvr_h
value|__builtin_msa_ilvr_h
end_define

begin_define
define|#
directive|define
name|__msa_ilvr_w
value|__builtin_msa_ilvr_w
end_define

begin_define
define|#
directive|define
name|__msa_ilvr_d
value|__builtin_msa_ilvr_d
end_define

begin_define
define|#
directive|define
name|__msa_ilvev_b
value|__builtin_msa_ilvev_b
end_define

begin_define
define|#
directive|define
name|__msa_ilvev_h
value|__builtin_msa_ilvev_h
end_define

begin_define
define|#
directive|define
name|__msa_ilvev_w
value|__builtin_msa_ilvev_w
end_define

begin_define
define|#
directive|define
name|__msa_ilvev_d
value|__builtin_msa_ilvev_d
end_define

begin_define
define|#
directive|define
name|__msa_ilvod_b
value|__builtin_msa_ilvod_b
end_define

begin_define
define|#
directive|define
name|__msa_ilvod_h
value|__builtin_msa_ilvod_h
end_define

begin_define
define|#
directive|define
name|__msa_ilvod_w
value|__builtin_msa_ilvod_w
end_define

begin_define
define|#
directive|define
name|__msa_ilvod_d
value|__builtin_msa_ilvod_d
end_define

begin_define
define|#
directive|define
name|__msa_vshf_b
value|__builtin_msa_vshf_b
end_define

begin_define
define|#
directive|define
name|__msa_vshf_h
value|__builtin_msa_vshf_h
end_define

begin_define
define|#
directive|define
name|__msa_vshf_w
value|__builtin_msa_vshf_w
end_define

begin_define
define|#
directive|define
name|__msa_vshf_d
value|__builtin_msa_vshf_d
end_define

begin_define
define|#
directive|define
name|__msa_and_v
value|__builtin_msa_and_v
end_define

begin_define
define|#
directive|define
name|__msa_andi_b
value|__builtin_msa_andi_b
end_define

begin_define
define|#
directive|define
name|__msa_or_v
value|__builtin_msa_or_v
end_define

begin_define
define|#
directive|define
name|__msa_ori_b
value|__builtin_msa_ori_b
end_define

begin_define
define|#
directive|define
name|__msa_nor_v
value|__builtin_msa_nor_v
end_define

begin_define
define|#
directive|define
name|__msa_nori_b
value|__builtin_msa_nori_b
end_define

begin_define
define|#
directive|define
name|__msa_xor_v
value|__builtin_msa_xor_v
end_define

begin_define
define|#
directive|define
name|__msa_xori_b
value|__builtin_msa_xori_b
end_define

begin_define
define|#
directive|define
name|__msa_bmnz_v
value|__builtin_msa_bmnz_v
end_define

begin_define
define|#
directive|define
name|__msa_bmnzi_b
value|__builtin_msa_bmnzi_b
end_define

begin_define
define|#
directive|define
name|__msa_bmz_v
value|__builtin_msa_bmz_v
end_define

begin_define
define|#
directive|define
name|__msa_bmzi_b
value|__builtin_msa_bmzi_b
end_define

begin_define
define|#
directive|define
name|__msa_bsel_v
value|__builtin_msa_bsel_v
end_define

begin_define
define|#
directive|define
name|__msa_bseli_b
value|__builtin_msa_bseli_b
end_define

begin_define
define|#
directive|define
name|__msa_shf_b
value|__builtin_msa_shf_b
end_define

begin_define
define|#
directive|define
name|__msa_shf_h
value|__builtin_msa_shf_h
end_define

begin_define
define|#
directive|define
name|__msa_shf_w
value|__builtin_msa_shf_w
end_define

begin_define
define|#
directive|define
name|__msa_test_bnz_v
value|__builtin_msa_bnz_v
end_define

begin_define
define|#
directive|define
name|__msa_test_bz_v
value|__builtin_msa_bz_v
end_define

begin_define
define|#
directive|define
name|__msa_fill_b
value|__builtin_msa_fill_b
end_define

begin_define
define|#
directive|define
name|__msa_fill_h
value|__builtin_msa_fill_h
end_define

begin_define
define|#
directive|define
name|__msa_fill_w
value|__builtin_msa_fill_w
end_define

begin_define
define|#
directive|define
name|__msa_fill_d
value|__builtin_msa_fill_d
end_define

begin_define
define|#
directive|define
name|__msa_pcnt_b
value|__builtin_msa_pcnt_b
end_define

begin_define
define|#
directive|define
name|__msa_pcnt_h
value|__builtin_msa_pcnt_h
end_define

begin_define
define|#
directive|define
name|__msa_pcnt_w
value|__builtin_msa_pcnt_w
end_define

begin_define
define|#
directive|define
name|__msa_pcnt_d
value|__builtin_msa_pcnt_d
end_define

begin_define
define|#
directive|define
name|__msa_nloc_b
value|__builtin_msa_nloc_b
end_define

begin_define
define|#
directive|define
name|__msa_nloc_h
value|__builtin_msa_nloc_h
end_define

begin_define
define|#
directive|define
name|__msa_nloc_w
value|__builtin_msa_nloc_w
end_define

begin_define
define|#
directive|define
name|__msa_nloc_d
value|__builtin_msa_nloc_d
end_define

begin_define
define|#
directive|define
name|__msa_nlzc_b
value|__builtin_msa_nlzc_b
end_define

begin_define
define|#
directive|define
name|__msa_nlzc_h
value|__builtin_msa_nlzc_h
end_define

begin_define
define|#
directive|define
name|__msa_nlzc_w
value|__builtin_msa_nlzc_w
end_define

begin_define
define|#
directive|define
name|__msa_nlzc_d
value|__builtin_msa_nlzc_d
end_define

begin_define
define|#
directive|define
name|__msa_copy_s_b
value|__builtin_msa_copy_s_b
end_define

begin_define
define|#
directive|define
name|__msa_copy_s_h
value|__builtin_msa_copy_s_h
end_define

begin_define
define|#
directive|define
name|__msa_copy_s_w
value|__builtin_msa_copy_s_w
end_define

begin_define
define|#
directive|define
name|__msa_copy_s_d
value|__builtin_msa_copy_s_d
end_define

begin_define
define|#
directive|define
name|__msa_copy_u_b
value|__builtin_msa_copy_u_b
end_define

begin_define
define|#
directive|define
name|__msa_copy_u_h
value|__builtin_msa_copy_u_h
end_define

begin_define
define|#
directive|define
name|__msa_copy_u_w
value|__builtin_msa_copy_u_w
end_define

begin_define
define|#
directive|define
name|__msa_copy_u_d
value|__builtin_msa_copy_u_d
end_define

begin_define
define|#
directive|define
name|__msa_insert_b
value|__builtin_msa_insert_b
end_define

begin_define
define|#
directive|define
name|__msa_insert_h
value|__builtin_msa_insert_h
end_define

begin_define
define|#
directive|define
name|__msa_insert_w
value|__builtin_msa_insert_w
end_define

begin_define
define|#
directive|define
name|__msa_insert_d
value|__builtin_msa_insert_d
end_define

begin_define
define|#
directive|define
name|__msa_insve_b
value|__builtin_msa_insve_b
end_define

begin_define
define|#
directive|define
name|__msa_insve_h
value|__builtin_msa_insve_h
end_define

begin_define
define|#
directive|define
name|__msa_insve_w
value|__builtin_msa_insve_w
end_define

begin_define
define|#
directive|define
name|__msa_insve_d
value|__builtin_msa_insve_d
end_define

begin_define
define|#
directive|define
name|__msa_test_bnz_b
value|__builtin_msa_bnz_b
end_define

begin_define
define|#
directive|define
name|__msa_test_bnz_h
value|__builtin_msa_bnz_h
end_define

begin_define
define|#
directive|define
name|__msa_test_bnz_w
value|__builtin_msa_bnz_w
end_define

begin_define
define|#
directive|define
name|__msa_test_bnz_d
value|__builtin_msa_bnz_d
end_define

begin_define
define|#
directive|define
name|__msa_test_bz_b
value|__builtin_msa_bz_b
end_define

begin_define
define|#
directive|define
name|__msa_test_bz_h
value|__builtin_msa_bz_h
end_define

begin_define
define|#
directive|define
name|__msa_test_bz_w
value|__builtin_msa_bz_w
end_define

begin_define
define|#
directive|define
name|__msa_test_bz_d
value|__builtin_msa_bz_d
end_define

begin_define
define|#
directive|define
name|__msa_ldi_b
value|__builtin_msa_ldi_b
end_define

begin_define
define|#
directive|define
name|__msa_ldi_h
value|__builtin_msa_ldi_h
end_define

begin_define
define|#
directive|define
name|__msa_ldi_w
value|__builtin_msa_ldi_w
end_define

begin_define
define|#
directive|define
name|__msa_ldi_d
value|__builtin_msa_ldi_d
end_define

begin_define
define|#
directive|define
name|__msa_fcaf_w
value|__builtin_msa_fcaf_w
end_define

begin_define
define|#
directive|define
name|__msa_fcaf_d
value|__builtin_msa_fcaf_d
end_define

begin_define
define|#
directive|define
name|__msa_fcor_w
value|__builtin_msa_fcor_w
end_define

begin_define
define|#
directive|define
name|__msa_fcor_d
value|__builtin_msa_fcor_d
end_define

begin_define
define|#
directive|define
name|__msa_fcun_w
value|__builtin_msa_fcun_w
end_define

begin_define
define|#
directive|define
name|__msa_fcun_d
value|__builtin_msa_fcun_d
end_define

begin_define
define|#
directive|define
name|__msa_fcune_w
value|__builtin_msa_fcune_w
end_define

begin_define
define|#
directive|define
name|__msa_fcune_d
value|__builtin_msa_fcune_d
end_define

begin_define
define|#
directive|define
name|__msa_fcueq_w
value|__builtin_msa_fcueq_w
end_define

begin_define
define|#
directive|define
name|__msa_fcueq_d
value|__builtin_msa_fcueq_d
end_define

begin_define
define|#
directive|define
name|__msa_fceq_w
value|__builtin_msa_fceq_w
end_define

begin_define
define|#
directive|define
name|__msa_fceq_d
value|__builtin_msa_fceq_d
end_define

begin_define
define|#
directive|define
name|__msa_fcne_w
value|__builtin_msa_fcne_w
end_define

begin_define
define|#
directive|define
name|__msa_fcne_d
value|__builtin_msa_fcne_d
end_define

begin_define
define|#
directive|define
name|__msa_fclt_w
value|__builtin_msa_fclt_w
end_define

begin_define
define|#
directive|define
name|__msa_fclt_d
value|__builtin_msa_fclt_d
end_define

begin_define
define|#
directive|define
name|__msa_fcult_w
value|__builtin_msa_fcult_w
end_define

begin_define
define|#
directive|define
name|__msa_fcult_d
value|__builtin_msa_fcult_d
end_define

begin_define
define|#
directive|define
name|__msa_fcle_w
value|__builtin_msa_fcle_w
end_define

begin_define
define|#
directive|define
name|__msa_fcle_d
value|__builtin_msa_fcle_d
end_define

begin_define
define|#
directive|define
name|__msa_fcule_w
value|__builtin_msa_fcule_w
end_define

begin_define
define|#
directive|define
name|__msa_fcule_d
value|__builtin_msa_fcule_d
end_define

begin_define
define|#
directive|define
name|__msa_fsaf_w
value|__builtin_msa_fsaf_w
end_define

begin_define
define|#
directive|define
name|__msa_fsaf_d
value|__builtin_msa_fsaf_d
end_define

begin_define
define|#
directive|define
name|__msa_fsor_w
value|__builtin_msa_fsor_w
end_define

begin_define
define|#
directive|define
name|__msa_fsor_d
value|__builtin_msa_fsor_d
end_define

begin_define
define|#
directive|define
name|__msa_fsun_w
value|__builtin_msa_fsun_w
end_define

begin_define
define|#
directive|define
name|__msa_fsun_d
value|__builtin_msa_fsun_d
end_define

begin_define
define|#
directive|define
name|__msa_fsune_w
value|__builtin_msa_fsune_w
end_define

begin_define
define|#
directive|define
name|__msa_fsune_d
value|__builtin_msa_fsune_d
end_define

begin_define
define|#
directive|define
name|__msa_fsueq_w
value|__builtin_msa_fsueq_w
end_define

begin_define
define|#
directive|define
name|__msa_fsueq_d
value|__builtin_msa_fsueq_d
end_define

begin_define
define|#
directive|define
name|__msa_fseq_w
value|__builtin_msa_fseq_w
end_define

begin_define
define|#
directive|define
name|__msa_fseq_d
value|__builtin_msa_fseq_d
end_define

begin_define
define|#
directive|define
name|__msa_fsne_w
value|__builtin_msa_fsne_w
end_define

begin_define
define|#
directive|define
name|__msa_fsne_d
value|__builtin_msa_fsne_d
end_define

begin_define
define|#
directive|define
name|__msa_fslt_w
value|__builtin_msa_fslt_w
end_define

begin_define
define|#
directive|define
name|__msa_fslt_d
value|__builtin_msa_fslt_d
end_define

begin_define
define|#
directive|define
name|__msa_fsult_w
value|__builtin_msa_fsult_w
end_define

begin_define
define|#
directive|define
name|__msa_fsult_d
value|__builtin_msa_fsult_d
end_define

begin_define
define|#
directive|define
name|__msa_fsle_w
value|__builtin_msa_fsle_w
end_define

begin_define
define|#
directive|define
name|__msa_fsle_d
value|__builtin_msa_fsle_d
end_define

begin_define
define|#
directive|define
name|__msa_fsule_w
value|__builtin_msa_fsule_w
end_define

begin_define
define|#
directive|define
name|__msa_fsule_d
value|__builtin_msa_fsule_d
end_define

begin_define
define|#
directive|define
name|__msa_fadd_w
value|__builtin_msa_fadd_w
end_define

begin_define
define|#
directive|define
name|__msa_fadd_d
value|__builtin_msa_fadd_d
end_define

begin_define
define|#
directive|define
name|__msa_fsub_w
value|__builtin_msa_fsub_w
end_define

begin_define
define|#
directive|define
name|__msa_fsub_d
value|__builtin_msa_fsub_d
end_define

begin_define
define|#
directive|define
name|__msa_fmul_w
value|__builtin_msa_fmul_w
end_define

begin_define
define|#
directive|define
name|__msa_fmul_d
value|__builtin_msa_fmul_d
end_define

begin_define
define|#
directive|define
name|__msa_fdiv_w
value|__builtin_msa_fdiv_w
end_define

begin_define
define|#
directive|define
name|__msa_fdiv_d
value|__builtin_msa_fdiv_d
end_define

begin_define
define|#
directive|define
name|__msa_fmadd_w
value|__builtin_msa_fmadd_w
end_define

begin_define
define|#
directive|define
name|__msa_fmadd_d
value|__builtin_msa_fmadd_d
end_define

begin_define
define|#
directive|define
name|__msa_fmsub_w
value|__builtin_msa_fmsub_w
end_define

begin_define
define|#
directive|define
name|__msa_fmsub_d
value|__builtin_msa_fmsub_d
end_define

begin_define
define|#
directive|define
name|__msa_fexp2_w
value|__builtin_msa_fexp2_w
end_define

begin_define
define|#
directive|define
name|__msa_fexp2_d
value|__builtin_msa_fexp2_d
end_define

begin_define
define|#
directive|define
name|__msa_fexdo_h
value|__builtin_msa_fexdo_h
end_define

begin_define
define|#
directive|define
name|__msa_fexdo_w
value|__builtin_msa_fexdo_w
end_define

begin_define
define|#
directive|define
name|__msa_ftq_h
value|__builtin_msa_ftq_h
end_define

begin_define
define|#
directive|define
name|__msa_ftq_w
value|__builtin_msa_ftq_w
end_define

begin_define
define|#
directive|define
name|__msa_fmin_w
value|__builtin_msa_fmin_w
end_define

begin_define
define|#
directive|define
name|__msa_fmin_d
value|__builtin_msa_fmin_d
end_define

begin_define
define|#
directive|define
name|__msa_fmin_a_w
value|__builtin_msa_fmin_a_w
end_define

begin_define
define|#
directive|define
name|__msa_fmin_a_d
value|__builtin_msa_fmin_a_d
end_define

begin_define
define|#
directive|define
name|__msa_fmax_w
value|__builtin_msa_fmax_w
end_define

begin_define
define|#
directive|define
name|__msa_fmax_d
value|__builtin_msa_fmax_d
end_define

begin_define
define|#
directive|define
name|__msa_fmax_a_w
value|__builtin_msa_fmax_a_w
end_define

begin_define
define|#
directive|define
name|__msa_fmax_a_d
value|__builtin_msa_fmax_a_d
end_define

begin_define
define|#
directive|define
name|__msa_mul_q_h
value|__builtin_msa_mul_q_h
end_define

begin_define
define|#
directive|define
name|__msa_mul_q_w
value|__builtin_msa_mul_q_w
end_define

begin_define
define|#
directive|define
name|__msa_mulr_q_h
value|__builtin_msa_mulr_q_h
end_define

begin_define
define|#
directive|define
name|__msa_mulr_q_w
value|__builtin_msa_mulr_q_w
end_define

begin_define
define|#
directive|define
name|__msa_madd_q_h
value|__builtin_msa_madd_q_h
end_define

begin_define
define|#
directive|define
name|__msa_madd_q_w
value|__builtin_msa_madd_q_w
end_define

begin_define
define|#
directive|define
name|__msa_maddr_q_h
value|__builtin_msa_maddr_q_h
end_define

begin_define
define|#
directive|define
name|__msa_maddr_q_w
value|__builtin_msa_maddr_q_w
end_define

begin_define
define|#
directive|define
name|__msa_msub_q_h
value|__builtin_msa_msub_q_h
end_define

begin_define
define|#
directive|define
name|__msa_msub_q_w
value|__builtin_msa_msub_q_w
end_define

begin_define
define|#
directive|define
name|__msa_msubr_q_h
value|__builtin_msa_msubr_q_h
end_define

begin_define
define|#
directive|define
name|__msa_msubr_q_w
value|__builtin_msa_msubr_q_w
end_define

begin_define
define|#
directive|define
name|__msa_fclass_w
value|__builtin_msa_fclass_w
end_define

begin_define
define|#
directive|define
name|__msa_fclass_d
value|__builtin_msa_fclass_d
end_define

begin_define
define|#
directive|define
name|__msa_fsqrt_w
value|__builtin_msa_fsqrt_w
end_define

begin_define
define|#
directive|define
name|__msa_fsqrt_d
value|__builtin_msa_fsqrt_d
end_define

begin_define
define|#
directive|define
name|__msa_frcp_w
value|__builtin_msa_frcp_w
end_define

begin_define
define|#
directive|define
name|__msa_frcp_d
value|__builtin_msa_frcp_d
end_define

begin_define
define|#
directive|define
name|__msa_frint_w
value|__builtin_msa_frint_w
end_define

begin_define
define|#
directive|define
name|__msa_frint_d
value|__builtin_msa_frint_d
end_define

begin_define
define|#
directive|define
name|__msa_frsqrt_w
value|__builtin_msa_frsqrt_w
end_define

begin_define
define|#
directive|define
name|__msa_frsqrt_d
value|__builtin_msa_frsqrt_d
end_define

begin_define
define|#
directive|define
name|__msa_flog2_w
value|__builtin_msa_flog2_w
end_define

begin_define
define|#
directive|define
name|__msa_flog2_d
value|__builtin_msa_flog2_d
end_define

begin_define
define|#
directive|define
name|__msa_fexupl_w
value|__builtin_msa_fexupl_w
end_define

begin_define
define|#
directive|define
name|__msa_fexupl_d
value|__builtin_msa_fexupl_d
end_define

begin_define
define|#
directive|define
name|__msa_fexupr_w
value|__builtin_msa_fexupr_w
end_define

begin_define
define|#
directive|define
name|__msa_fexupr_d
value|__builtin_msa_fexupr_d
end_define

begin_define
define|#
directive|define
name|__msa_ffql_w
value|__builtin_msa_ffql_w
end_define

begin_define
define|#
directive|define
name|__msa_ffql_d
value|__builtin_msa_ffql_d
end_define

begin_define
define|#
directive|define
name|__msa_ffqr_w
value|__builtin_msa_ffqr_w
end_define

begin_define
define|#
directive|define
name|__msa_ffqr_d
value|__builtin_msa_ffqr_d
end_define

begin_define
define|#
directive|define
name|__msa_ftint_s_w
value|__builtin_msa_ftint_s_w
end_define

begin_define
define|#
directive|define
name|__msa_ftint_s_d
value|__builtin_msa_ftint_s_d
end_define

begin_define
define|#
directive|define
name|__msa_ftint_u_w
value|__builtin_msa_ftint_u_w
end_define

begin_define
define|#
directive|define
name|__msa_ftint_u_d
value|__builtin_msa_ftint_u_d
end_define

begin_define
define|#
directive|define
name|__msa_ftrunc_s_w
value|__builtin_msa_ftrunc_s_w
end_define

begin_define
define|#
directive|define
name|__msa_ftrunc_s_d
value|__builtin_msa_ftrunc_s_d
end_define

begin_define
define|#
directive|define
name|__msa_ftrunc_u_w
value|__builtin_msa_ftrunc_u_w
end_define

begin_define
define|#
directive|define
name|__msa_ftrunc_u_d
value|__builtin_msa_ftrunc_u_d
end_define

begin_define
define|#
directive|define
name|__msa_ffint_s_w
value|__builtin_msa_ffint_s_w
end_define

begin_define
define|#
directive|define
name|__msa_ffint_s_d
value|__builtin_msa_ffint_s_d
end_define

begin_define
define|#
directive|define
name|__msa_ffint_u_w
value|__builtin_msa_ffint_u_w
end_define

begin_define
define|#
directive|define
name|__msa_ffint_u_d
value|__builtin_msa_ffint_u_d
end_define

begin_define
define|#
directive|define
name|__msa_cfcmsa
value|__builtin_msa_cfcmsa
end_define

begin_define
define|#
directive|define
name|__msa_move_v
value|__builtin_msa_move_v
end_define

begin_define
define|#
directive|define
name|__msa_cast_to_vector_float
value|__builtin_msa_cast_to_vector_float
end_define

begin_define
define|#
directive|define
name|__msa_cast_to_vector_double
value|__builtin_msa_cast_to_vector_double
end_define

begin_define
define|#
directive|define
name|__msa_cast_to_scalar_float
value|__builtin_msa_cast_to_scalar_float
end_define

begin_define
define|#
directive|define
name|__msa_cast_to_scalar_double
value|__builtin_msa_cast_to_scalar_double
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__mips_msa) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSA_H */
end_comment

end_unit

