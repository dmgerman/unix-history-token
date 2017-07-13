begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- cpuid.h - X86 cpu model detection --------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|__x86_64__
operator|||
name|__i386__
operator|)
end_if

begin_error
error|#
directive|error
error|this header is for x86 only
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Responses identification request with %eax 0 */
end_comment

begin_comment
comment|/* AMD:     "AuthenticAMD" */
end_comment

begin_define
define|#
directive|define
name|signature_AMD_ebx
value|0x68747541
end_define

begin_define
define|#
directive|define
name|signature_AMD_edx
value|0x69746e65
end_define

begin_define
define|#
directive|define
name|signature_AMD_ecx
value|0x444d4163
end_define

begin_comment
comment|/* CENTAUR: "CentaurHauls" */
end_comment

begin_define
define|#
directive|define
name|signature_CENTAUR_ebx
value|0x746e6543
end_define

begin_define
define|#
directive|define
name|signature_CENTAUR_edx
value|0x48727561
end_define

begin_define
define|#
directive|define
name|signature_CENTAUR_ecx
value|0x736c7561
end_define

begin_comment
comment|/* CYRIX:   "CyrixInstead" */
end_comment

begin_define
define|#
directive|define
name|signature_CYRIX_ebx
value|0x69727943
end_define

begin_define
define|#
directive|define
name|signature_CYRIX_edx
value|0x736e4978
end_define

begin_define
define|#
directive|define
name|signature_CYRIX_ecx
value|0x64616574
end_define

begin_comment
comment|/* INTEL:   "GenuineIntel" */
end_comment

begin_define
define|#
directive|define
name|signature_INTEL_ebx
value|0x756e6547
end_define

begin_define
define|#
directive|define
name|signature_INTEL_edx
value|0x49656e69
end_define

begin_define
define|#
directive|define
name|signature_INTEL_ecx
value|0x6c65746e
end_define

begin_comment
comment|/* TM1:     "TransmetaCPU" */
end_comment

begin_define
define|#
directive|define
name|signature_TM1_ebx
value|0x6e617254
end_define

begin_define
define|#
directive|define
name|signature_TM1_edx
value|0x74656d73
end_define

begin_define
define|#
directive|define
name|signature_TM1_ecx
value|0x55504361
end_define

begin_comment
comment|/* TM2:     "GenuineTMx86" */
end_comment

begin_define
define|#
directive|define
name|signature_TM2_ebx
value|0x756e6547
end_define

begin_define
define|#
directive|define
name|signature_TM2_edx
value|0x54656e69
end_define

begin_define
define|#
directive|define
name|signature_TM2_ecx
value|0x3638784d
end_define

begin_comment
comment|/* NSC:     "Geode by NSC" */
end_comment

begin_define
define|#
directive|define
name|signature_NSC_ebx
value|0x646f6547
end_define

begin_define
define|#
directive|define
name|signature_NSC_edx
value|0x43534e20
end_define

begin_define
define|#
directive|define
name|signature_NSC_ecx
value|0x79622065
end_define

begin_comment
comment|/* NEXGEN:  "NexGenDriven" */
end_comment

begin_define
define|#
directive|define
name|signature_NEXGEN_ebx
value|0x4778654e
end_define

begin_define
define|#
directive|define
name|signature_NEXGEN_edx
value|0x72446e65
end_define

begin_define
define|#
directive|define
name|signature_NEXGEN_ecx
value|0x6e657669
end_define

begin_comment
comment|/* RISE:    "RiseRiseRise" */
end_comment

begin_define
define|#
directive|define
name|signature_RISE_ebx
value|0x65736952
end_define

begin_define
define|#
directive|define
name|signature_RISE_edx
value|0x65736952
end_define

begin_define
define|#
directive|define
name|signature_RISE_ecx
value|0x65736952
end_define

begin_comment
comment|/* SIS:     "SiS SiS SiS " */
end_comment

begin_define
define|#
directive|define
name|signature_SIS_ebx
value|0x20536953
end_define

begin_define
define|#
directive|define
name|signature_SIS_edx
value|0x20536953
end_define

begin_define
define|#
directive|define
name|signature_SIS_ecx
value|0x20536953
end_define

begin_comment
comment|/* UMC:     "UMC UMC UMC " */
end_comment

begin_define
define|#
directive|define
name|signature_UMC_ebx
value|0x20434d55
end_define

begin_define
define|#
directive|define
name|signature_UMC_edx
value|0x20434d55
end_define

begin_define
define|#
directive|define
name|signature_UMC_ecx
value|0x20434d55
end_define

begin_comment
comment|/* VIA:     "VIA VIA VIA " */
end_comment

begin_define
define|#
directive|define
name|signature_VIA_ebx
value|0x20414956
end_define

begin_define
define|#
directive|define
name|signature_VIA_edx
value|0x20414956
end_define

begin_define
define|#
directive|define
name|signature_VIA_ecx
value|0x20414956
end_define

begin_comment
comment|/* VORTEX:  "Vortex86 SoC" */
end_comment

begin_define
define|#
directive|define
name|signature_VORTEX_ebx
value|0x74726f56
end_define

begin_define
define|#
directive|define
name|signature_VORTEX_edx
value|0x36387865
end_define

begin_define
define|#
directive|define
name|signature_VORTEX_ecx
value|0x436f5320
end_define

begin_comment
comment|/* Features in %ecx for leaf 1 */
end_comment

begin_define
define|#
directive|define
name|bit_SSE3
value|0x00000001
end_define

begin_define
define|#
directive|define
name|bit_PCLMULQDQ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|bit_PCLMUL
value|bit_PCLMULQDQ
end_define

begin_comment
comment|/* for gcc compat */
end_comment

begin_define
define|#
directive|define
name|bit_DTES64
value|0x00000004
end_define

begin_define
define|#
directive|define
name|bit_MONITOR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|bit_DSCPL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|bit_VMX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|bit_SMX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|bit_EIST
value|0x00000080
end_define

begin_define
define|#
directive|define
name|bit_TM2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|bit_SSSE3
value|0x00000200
end_define

begin_define
define|#
directive|define
name|bit_CNXTID
value|0x00000400
end_define

begin_define
define|#
directive|define
name|bit_FMA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|bit_CMPXCHG16B
value|0x00002000
end_define

begin_define
define|#
directive|define
name|bit_xTPR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|bit_PDCM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|bit_PCID
value|0x00020000
end_define

begin_define
define|#
directive|define
name|bit_DCA
value|0x00040000
end_define

begin_define
define|#
directive|define
name|bit_SSE41
value|0x00080000
end_define

begin_define
define|#
directive|define
name|bit_SSE4_1
value|bit_SSE41
end_define

begin_comment
comment|/* for gcc compat */
end_comment

begin_define
define|#
directive|define
name|bit_SSE42
value|0x00100000
end_define

begin_define
define|#
directive|define
name|bit_SSE4_2
value|bit_SSE42
end_define

begin_comment
comment|/* for gcc compat */
end_comment

begin_define
define|#
directive|define
name|bit_x2APIC
value|0x00200000
end_define

begin_define
define|#
directive|define
name|bit_MOVBE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|bit_POPCNT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|bit_TSCDeadline
value|0x01000000
end_define

begin_define
define|#
directive|define
name|bit_AESNI
value|0x02000000
end_define

begin_define
define|#
directive|define
name|bit_AES
value|bit_AESNI
end_define

begin_comment
comment|/* for gcc compat */
end_comment

begin_define
define|#
directive|define
name|bit_XSAVE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|bit_OSXSAVE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|bit_AVX
value|0x10000000
end_define

begin_define
define|#
directive|define
name|bit_F16C
value|0x20000000
end_define

begin_define
define|#
directive|define
name|bit_RDRND
value|0x40000000
end_define

begin_comment
comment|/* Features in %edx for leaf 1 */
end_comment

begin_define
define|#
directive|define
name|bit_FPU
value|0x00000001
end_define

begin_define
define|#
directive|define
name|bit_VME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|bit_DE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|bit_PSE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|bit_TSC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|bit_MSR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|bit_PAE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|bit_MCE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|bit_CX8
value|0x00000100
end_define

begin_define
define|#
directive|define
name|bit_CMPXCHG8B
value|bit_CX8
end_define

begin_comment
comment|/* for gcc compat */
end_comment

begin_define
define|#
directive|define
name|bit_APIC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|bit_SEP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|bit_MTRR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|bit_PGE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|bit_MCA
value|0x00004000
end_define

begin_define
define|#
directive|define
name|bit_CMOV
value|0x00008000
end_define

begin_define
define|#
directive|define
name|bit_PAT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|bit_PSE36
value|0x00020000
end_define

begin_define
define|#
directive|define
name|bit_PSN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|bit_CLFSH
value|0x00080000
end_define

begin_define
define|#
directive|define
name|bit_DS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|bit_ACPI
value|0x00400000
end_define

begin_define
define|#
directive|define
name|bit_MMX
value|0x00800000
end_define

begin_define
define|#
directive|define
name|bit_FXSR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|bit_FXSAVE
value|bit_FXSR
end_define

begin_comment
comment|/* for gcc compat */
end_comment

begin_define
define|#
directive|define
name|bit_SSE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|bit_SSE2
value|0x04000000
end_define

begin_define
define|#
directive|define
name|bit_SS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|bit_HTT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|bit_TM
value|0x20000000
end_define

begin_define
define|#
directive|define
name|bit_PBE
value|0x80000000
end_define

begin_comment
comment|/* Features in %ebx for leaf 7 sub-leaf 0 */
end_comment

begin_define
define|#
directive|define
name|bit_FSGSBASE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|bit_SGX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|bit_BMI
value|0x00000008
end_define

begin_define
define|#
directive|define
name|bit_HLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|bit_AVX2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|bit_SMEP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|bit_BMI2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|bit_ENH_MOVSB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|bit_RTM
value|0x00000800
end_define

begin_define
define|#
directive|define
name|bit_MPX
value|0x00004000
end_define

begin_define
define|#
directive|define
name|bit_AVX512F
value|0x00010000
end_define

begin_define
define|#
directive|define
name|bit_AVX512DQ
value|0x00020000
end_define

begin_define
define|#
directive|define
name|bit_RDSEED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|bit_ADX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|bit_AVX512IFMA
value|0x00200000
end_define

begin_define
define|#
directive|define
name|bit_CLFLUSHOPT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|bit_CLWB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|bit_AVX512PF
value|0x04000000
end_define

begin_define
define|#
directive|define
name|bit_AVX51SER
value|0x08000000
end_define

begin_define
define|#
directive|define
name|bit_AVX512CD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|bit_SHA
value|0x20000000
end_define

begin_define
define|#
directive|define
name|bit_AVX512BW
value|0x40000000
end_define

begin_define
define|#
directive|define
name|bit_AVX512VL
value|0x80000000
end_define

begin_comment
comment|/* Features in %ecx for leaf 7 sub-leaf 0 */
end_comment

begin_define
define|#
directive|define
name|bit_PREFTCHWT1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|bit_AVX512VBMI
value|0x00000002
end_define

begin_define
define|#
directive|define
name|bit_PKU
value|0x00000004
end_define

begin_define
define|#
directive|define
name|bit_OSPKE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|bit_AVX512VPOPCNTDQ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|bit_RDPID
value|0x00400000
end_define

begin_comment
comment|/* Features in %edx for leaf 7 sub-leaf 0 */
end_comment

begin_define
define|#
directive|define
name|bit_AVX5124VNNIW
value|0x00000004
end_define

begin_define
define|#
directive|define
name|bit_AVX5124FMAPS
value|0x00000008
end_define

begin_comment
comment|/* Features in %eax for leaf 13 sub-leaf 1 */
end_comment

begin_define
define|#
directive|define
name|bit_XSAVEOPT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|bit_XSAVEC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|bit_XSAVES
value|0x00000008
end_define

begin_comment
comment|/* Features in %ecx for leaf 0x80000001 */
end_comment

begin_define
define|#
directive|define
name|bit_LAHF_LM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|bit_ABM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|bit_SSE4a
value|0x00000040
end_define

begin_define
define|#
directive|define
name|bit_PRFCHW
value|0x00000100
end_define

begin_define
define|#
directive|define
name|bit_XOP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|bit_LWP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|bit_FMA4
value|0x00010000
end_define

begin_define
define|#
directive|define
name|bit_TBM
value|0x00200000
end_define

begin_define
define|#
directive|define
name|bit_MWAITX
value|0x20000000
end_define

begin_comment
comment|/* Features in %edx for leaf 0x80000001 */
end_comment

begin_define
define|#
directive|define
name|bit_MMXEXT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|bit_LM
value|0x20000000
end_define

begin_define
define|#
directive|define
name|bit_3DNOWP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|bit_3DNOW
value|0x80000000
end_define

begin_comment
comment|/* Features in %ebx for leaf 0x80000001 */
end_comment

begin_define
define|#
directive|define
name|bit_CLZERO
value|0x00000001
end_define

begin_if
if|#
directive|if
name|__i386__
end_if

begin_define
define|#
directive|define
name|__cpuid
parameter_list|(
name|__leaf
parameter_list|,
name|__eax
parameter_list|,
name|__ebx
parameter_list|,
name|__ecx
parameter_list|,
name|__edx
parameter_list|)
define|\
value|__asm("cpuid" : "=a"(__eax), "=b" (__ebx), "=c"(__ecx), "=d"(__edx) \                   : "0"(__leaf))
end_define

begin_define
define|#
directive|define
name|__cpuid_count
parameter_list|(
name|__leaf
parameter_list|,
name|__count
parameter_list|,
name|__eax
parameter_list|,
name|__ebx
parameter_list|,
name|__ecx
parameter_list|,
name|__edx
parameter_list|)
define|\
value|__asm("cpuid" : "=a"(__eax), "=b" (__ebx), "=c"(__ecx), "=d"(__edx) \                   : "0"(__leaf), "2"(__count))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* x86-64 uses %rbx as the base register, so preserve it. */
end_comment

begin_define
define|#
directive|define
name|__cpuid
parameter_list|(
name|__leaf
parameter_list|,
name|__eax
parameter_list|,
name|__ebx
parameter_list|,
name|__ecx
parameter_list|,
name|__edx
parameter_list|)
define|\
value|__asm("  xchgq  %%rbx,%q1\n" \           "  cpuid\n" \           "  xchgq  %%rbx,%q1" \         : "=a"(__eax), "=r" (__ebx), "=c"(__ecx), "=d"(__edx) \         : "0"(__leaf))
end_define

begin_define
define|#
directive|define
name|__cpuid_count
parameter_list|(
name|__leaf
parameter_list|,
name|__count
parameter_list|,
name|__eax
parameter_list|,
name|__ebx
parameter_list|,
name|__ecx
parameter_list|,
name|__edx
parameter_list|)
define|\
value|__asm("  xchgq  %%rbx,%q1\n" \           "  cpuid\n" \           "  xchgq  %%rbx,%q1" \         : "=a"(__eax), "=r" (__ebx), "=c"(__ecx), "=d"(__edx) \         : "0"(__leaf), "2"(__count))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|int
name|__get_cpuid_max
parameter_list|(
name|unsigned
name|int
name|__leaf
parameter_list|,
name|unsigned
name|int
modifier|*
name|__sig
parameter_list|)
block|{
name|unsigned
name|int
name|__eax
decl_stmt|,
name|__ebx
decl_stmt|,
name|__ecx
decl_stmt|,
name|__edx
decl_stmt|;
if|#
directive|if
name|__i386__
name|int
name|__cpuid_supported
decl_stmt|;
asm|__asm("  pushfl\n"
literal|"  popl   %%eax\n"
literal|"  movl   %%eax,%%ecx\n"
literal|"  xorl   $0x00200000,%%eax\n"
literal|"  pushl  %%eax\n"
literal|"  popfl\n"
literal|"  pushfl\n"
literal|"  popl   %%eax\n"
literal|"  movl   $0,%0\n"
literal|"  cmpl   %%eax,%%ecx\n"
literal|"  je     1f\n"
literal|"  movl   $1,%0\n"
literal|"1:"
operator|:
literal|"=r"
operator|(
name|__cpuid_supported
operator|)
operator|:
operator|:
literal|"eax"
operator|,
literal|"ecx"
block|)
function|;
end_function

begin_if
if|if
condition|(
operator|!
name|__cpuid_supported
condition|)
return|return
literal|0
return|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__cpuid
argument_list|(
name|__leaf
argument_list|,
name|__eax
argument_list|,
name|__ebx
argument_list|,
name|__ecx
argument_list|,
name|__edx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__sig
condition|)
operator|*
name|__sig
operator|=
name|__ebx
expr_stmt|;
end_if

begin_return
return|return
name|__eax
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|__get_cpuid
parameter_list|(
name|unsigned
name|int
name|__leaf
parameter_list|,
name|unsigned
name|int
modifier|*
name|__eax
parameter_list|,
name|unsigned
name|int
modifier|*
name|__ebx
parameter_list|,
name|unsigned
name|int
modifier|*
name|__ecx
parameter_list|,
name|unsigned
name|int
modifier|*
name|__edx
parameter_list|)
block|{
name|unsigned
name|int
name|__max_leaf
init|=
name|__get_cpuid_max
argument_list|(
name|__leaf
operator|&
literal|0x80000000
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|__max_leaf
operator|==
literal|0
operator|||
name|__max_leaf
operator|<
name|__leaf
condition|)
return|return
literal|0
return|;
name|__cpuid
argument_list|(
name|__leaf
argument_list|,
operator|*
name|__eax
argument_list|,
operator|*
name|__ebx
argument_list|,
operator|*
name|__ecx
argument_list|,
operator|*
name|__edx
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__get_cpuid_count
parameter_list|(
name|unsigned
name|int
name|__leaf
parameter_list|,
name|unsigned
name|int
name|__subleaf
parameter_list|,
name|unsigned
name|int
modifier|*
name|__eax
parameter_list|,
name|unsigned
name|int
modifier|*
name|__ebx
parameter_list|,
name|unsigned
name|int
modifier|*
name|__ecx
parameter_list|,
name|unsigned
name|int
modifier|*
name|__edx
parameter_list|)
block|{
name|unsigned
name|int
name|__max_leaf
init|=
name|__get_cpuid_max
argument_list|(
name|__leaf
operator|&
literal|0x80000000
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|__max_leaf
operator|==
literal|0
operator|||
name|__max_leaf
operator|<
name|__leaf
condition|)
return|return
literal|0
return|;
name|__cpuid_count
argument_list|(
name|__leaf
argument_list|,
name|__subleaf
argument_list|,
operator|*
name|__eax
argument_list|,
operator|*
name|__ebx
argument_list|,
operator|*
name|__ecx
argument_list|,
operator|*
name|__edx
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

