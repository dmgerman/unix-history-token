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
comment|/* Features in %ecx for level 1 */
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
name|bit_SSE42
value|0x00100000
end_define

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
name|bit_RDRAND
value|0x40000000
end_define

begin_comment
comment|/* Features in %edx for level 1 */
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
comment|/* Features in %ebx for level 7 sub-leaf 0 */
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
name|bit_SMEP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|bit_ENH_MOVSB
value|0x00000200
end_define

begin_comment
comment|/* PIC on i386 uses %ebx, so preserve it. */
end_comment

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
name|__level
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
value|__asm("  pushl  %%ebx\n" \           "  cpuid\n" \           "  mov    %%ebx,%1\n" \           "  popl   %%ebx" \         : "=a"(__eax), "=r" (__ebx), "=c"(__ecx), "=d"(__edx) \         : "0"(__level))
end_define

begin_define
define|#
directive|define
name|__cpuid_count
parameter_list|(
name|__level
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
value|__asm("  pushl  %%ebx\n" \           "  cpuid\n" \           "  mov    %%ebx,%1\n" \           "  popl   %%ebx" \         : "=a"(__eax), "=r" (__ebx), "=c"(__ecx), "=d"(__edx) \         : "0"(__level), "2"(__count))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__cpuid
parameter_list|(
name|__level
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
value|__asm("cpuid" : "=a"(__eax), "=b" (__ebx), "=c"(__ecx), "=d"(__edx) \                   : "0"(__level))
end_define

begin_define
define|#
directive|define
name|__cpuid_count
parameter_list|(
name|__level
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
value|__asm("cpuid" : "=a"(__eax), "=b" (__ebx), "=c"(__ecx), "=d"(__edx) \                   : "0"(__level), "2"(__count))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|int
name|__get_cpuid
parameter_list|(
name|unsigned
name|int
name|__level
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
name|__cpuid
argument_list|(
name|__level
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
name|__get_cpuid_max
parameter_list|(
name|unsigned
name|int
name|__level
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
name|__level
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

unit|}
end_unit

