begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- avx512erintrin.h - AVX512ER intrinsics ---------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMMINTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<avx512erintrin.h> directly; include<immintrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__AVX512ERINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__AVX512ERINTRIN_H
end_define

begin_comment
comment|// exp2a23
end_comment

begin_define
define|#
directive|define
name|_mm512_exp2a23_round_pd
parameter_list|(
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_exp2pd_mask((__v8df)(__m512d)(A), \                                       (__v8df)_mm512_setzero_pd(), \                                       (__mmask8)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_mask_exp2a23_round_pd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_exp2pd_mask((__v8df)(__m512d)(A), \                                       (__v8df)(__m512d)(S), \                                       (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_exp2a23_round_pd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_exp2pd_mask((__v8df)(__m512d)(A), \                                       (__v8df)_mm512_setzero_pd(), \                                       (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_exp2a23_pd
parameter_list|(
name|A
parameter_list|)
define|\
value|_mm512_exp2a23_round_pd((A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_mask_exp2a23_pd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_mask_exp2a23_round_pd((S), (M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_exp2a23_pd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_maskz_exp2a23_round_pd((M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_exp2a23_round_ps
parameter_list|(
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_exp2ps_mask((__v16sf)(__m512)(A), \                                      (__v16sf)_mm512_setzero_ps(), \                                      (__mmask8)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_mask_exp2a23_round_ps
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_exp2ps_mask((__v16sf)(__m512)(A), \                                      (__v16sf)(__m512)(S), \                                      (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_exp2a23_round_ps
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_exp2ps_mask((__v16sf)(__m512)(A), \                                      (__v16sf)_mm512_setzero_ps(), \                                      (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_exp2a23_ps
parameter_list|(
name|A
parameter_list|)
define|\
value|_mm512_exp2a23_round_ps((A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_mask_exp2a23_ps
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_mask_exp2a23_round_ps((S), (M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_exp2a23_ps
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_maskz_exp2a23_round_ps((M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_comment
comment|// rsqrt28
end_comment

begin_define
define|#
directive|define
name|_mm512_rsqrt28_round_pd
parameter_list|(
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_rsqrt28pd_mask((__v8df)(__m512d)(A), \                                          (__v8df)_mm512_setzero_pd(), \                                          (__mmask8)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_mask_rsqrt28_round_pd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_rsqrt28pd_mask((__v8df)(__m512d)(A), \                                          (__v8df)(__m512d)(S), \                                          (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_rsqrt28_round_pd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_rsqrt28pd_mask((__v8df)(__m512d)(A), \                                          (__v8df)_mm512_setzero_pd(), \                                          (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_rsqrt28_pd
parameter_list|(
name|A
parameter_list|)
define|\
value|_mm512_rsqrt28_round_pd((A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_mask_rsqrt28_pd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_mask_rsqrt28_round_pd((S), (M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_rsqrt28_pd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_maskz_rsqrt28_round_pd((M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_rsqrt28_round_ps
parameter_list|(
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_rsqrt28ps_mask((__v16sf)(__m512)(A), \                                         (__v16sf)_mm512_setzero_ps(), \                                         (__mmask16)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_mask_rsqrt28_round_ps
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_rsqrt28ps_mask((__v16sf)(__m512)(A), \                                         (__v16sf)(__m512)(S), \                                         (__mmask16)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_rsqrt28_round_ps
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_rsqrt28ps_mask((__v16sf)(__m512)(A), \                                         (__v16sf)_mm512_setzero_ps(), \                                         (__mmask16)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_rsqrt28_ps
parameter_list|(
name|A
parameter_list|)
define|\
value|_mm512_rsqrt28_round_ps((A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_mask_rsqrt28_ps
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_mask_rsqrt28_round_ps((S), (M), A, _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_rsqrt28_ps
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_maskz_rsqrt28_round_ps((M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_rsqrt28_round_ss
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_rsqrt28ss_round((__v4sf)(__m128)(A), \                                         (__v4sf)(__m128)(B), \                                         (__v4sf)_mm_setzero_ps(), \                                         (__mmask8)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_mask_rsqrt28_round_ss
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_rsqrt28ss_round((__v4sf)(__m128)(A), \                                         (__v4sf)(__m128)(B), \                                         (__v4sf)(__m128)(S), \                                         (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_maskz_rsqrt28_round_ss
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_rsqrt28ss_round((__v4sf)(__m128)(A), \                                         (__v4sf)(__m128)(B), \                                         (__v4sf)_mm_setzero_ps(), \                                         (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_rsqrt28_ss
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_rsqrt28_round_ss((A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_mask_rsqrt28_ss
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_mask_rsqrt28_round_ss((S), (M), (A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_maskz_rsqrt28_ss
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_maskz_rsqrt28_round_ss((M), (A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_rsqrt28_round_sd
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_rsqrt28sd_round((__v2df)(__m128d)(A), \                                          (__v2df)(__m128d)(B), \                                          (__v2df)_mm_setzero_pd(), \                                          (__mmask8)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_mask_rsqrt28_round_sd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_rsqrt28sd_round((__v2df)(__m128d)(A), \                                          (__v2df)(__m128d)(B), \                                          (__v2df)(__m128d)(S), \                                          (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_maskz_rsqrt28_round_sd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_rsqrt28sd_round((__v2df)(__m128d)(A), \                                          (__v2df)(__m128d)(B), \                                          (__v2df)_mm_setzero_pd(), \                                          (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_rsqrt28_sd
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_rsqrt28_round_sd((A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_mask_rsqrt28_sd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_mask_rsqrt28_round_sd((S), (M), (A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_maskz_rsqrt28_sd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_mask_rsqrt28_round_sd((M), (A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_comment
comment|// rcp28
end_comment

begin_define
define|#
directive|define
name|_mm512_rcp28_round_pd
parameter_list|(
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_rcp28pd_mask((__v8df)(__m512d)(A), \                                        (__v8df)_mm512_setzero_pd(), \                                        (__mmask8)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_mask_rcp28_round_pd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_rcp28pd_mask((__v8df)(__m512d)(A), \                                        (__v8df)(__m512d)(S), \                                        (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_rcp28_round_pd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512d)__builtin_ia32_rcp28pd_mask((__v8df)(__m512d)(A), \                                        (__v8df)_mm512_setzero_pd(), \                                        (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_rcp28_pd
parameter_list|(
name|A
parameter_list|)
define|\
value|_mm512_rcp28_round_pd((A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_mask_rcp28_pd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_mask_rcp28_round_pd((S), (M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_rcp28_pd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_maskz_rcp28_round_pd((M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_rcp28_round_ps
parameter_list|(
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_rcp28ps_mask((__v16sf)(__m512)(A), \                                       (__v16sf)_mm512_setzero_ps(), \                                       (__mmask16)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_mask_rcp28_round_ps
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_rcp28ps_mask((__v16sf)(__m512)(A), \                                       (__v16sf)(__m512)(S), \                                       (__mmask16)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_rcp28_round_ps
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m512)__builtin_ia32_rcp28ps_mask((__v16sf)(__m512)(A), \                                       (__v16sf)_mm512_setzero_ps(), \                                       (__mmask16)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm512_rcp28_ps
parameter_list|(
name|A
parameter_list|)
define|\
value|_mm512_rcp28_round_ps((A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_mask_rcp28_ps
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_mask_rcp28_round_ps((S), (M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm512_maskz_rcp28_ps
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|)
define|\
value|_mm512_maskz_rcp28_round_ps((M), (A), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_rcp28_round_ss
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_rcp28ss_round((__v4sf)(__m128)(A), \                                       (__v4sf)(__m128)(B), \                                       (__v4sf)_mm_setzero_ps(), \                                       (__mmask8)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_mask_rcp28_round_ss
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_rcp28ss_round((__v4sf)(__m128)(A), \                                       (__v4sf)(__m128)(B), \                                       (__v4sf)(__m128)(S), \                                       (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_maskz_rcp28_round_ss
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128)__builtin_ia32_rcp28ss_round((__v4sf)(__m128)(A), \                                       (__v4sf)(__m128)(B), \                                       (__v4sf)_mm_setzero_ps(), \                                       (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_rcp28_ss
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_rcp28_round_ss((A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_mask_rcp28_ss
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_mask_rcp28_round_ss((S), (M), (A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_maskz_rcp28_ss
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_maskz_rcp28_round_ss((M), (A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_rcp28_round_sd
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_rcp28sd_round((__v2df)(__m128d)(A), \                                        (__v2df)(__m128d)(B), \                                        (__v2df)_mm_setzero_pd(), \                                        (__mmask8)-1, (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_mask_rcp28_round_sd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_rcp28sd_round((__v2df)(__m128d)(A), \                                        (__v2df)(__m128d)(B), \                                        (__v2df)(__m128d)(S), \                                        (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_maskz_rcp28_round_sd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|R
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_ia32_rcp28sd_round((__v2df)(__m128d)(A), \                                        (__v2df)(__m128d)(B), \                                        (__v2df)_mm_setzero_pd(), \                                        (__mmask8)(M), (R)); })
end_define

begin_define
define|#
directive|define
name|_mm_rcp28_sd
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_rcp28_round_sd((A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_mask_rcp28_sd
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_mask_rcp28_round_sd((S), (M), (A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_define
define|#
directive|define
name|_mm_maskz_rcp28_sd
parameter_list|(
name|M
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|_mm_maskz_rcp28_round_sd((M), (A), (B), _MM_FROUND_CUR_DIRECTION)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __AVX512ERINTRIN_H
end_comment

end_unit

