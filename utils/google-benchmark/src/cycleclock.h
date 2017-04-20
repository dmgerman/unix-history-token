begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// ----------------------------------------------------------------------
end_comment

begin_comment
comment|// CycleClock
end_comment

begin_comment
comment|//    A CycleClock tells you the current time in Cycles.  The "time"
end_comment

begin_comment
comment|//    is actually time since power-on.  This is like time() but doesn't
end_comment

begin_comment
comment|//    involve a system call and is much more precise.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: Not all cpu/platform/kernel combinations guarantee that this
end_comment

begin_comment
comment|// clock increments at a constant rate or is synchronized across all logical
end_comment

begin_comment
comment|// cpus in a system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If you need the above guarantees, please consider using a different
end_comment

begin_comment
comment|// API. There are efforts to provide an interface which provides a millisecond
end_comment

begin_comment
comment|// granularity and implemented as a memory read. A memory read is generally
end_comment

begin_comment
comment|// cheaper than the CycleClock for many architectures.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Also, in some out of order CPU implementations, the CycleClock is not
end_comment

begin_comment
comment|// serializing. So if you're trying to count at cycles granularity, your
end_comment

begin_comment
comment|// data might be inaccurate due to out of order instruction execution.
end_comment

begin_comment
comment|// ----------------------------------------------------------------------
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_CYCLECLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_CYCLECLOCK_H_
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|"benchmark/macros.h"
end_include

begin_include
include|#
directive|include
file|"internal_macros.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BENCHMARK_OS_MACOSX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<mach/mach_time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// For MSVC, we want to use '_asm rdtsc' when possible (since it works
end_comment

begin_comment
comment|// with even ancient MSVC compilers), and when not possible the
end_comment

begin_comment
comment|// __rdtsc intrinsic, declared in<intrin.h>.  Unfortunately, in some
end_comment

begin_comment
comment|// environments,<windows.h> and<intrin.h> have conflicting
end_comment

begin_comment
comment|// declarations of some other intrinsics, breaking compilation.
end_comment

begin_comment
comment|// Therefore, we simply declare __rdtsc ourselves. See also
end_comment

begin_comment
comment|// http://connect.microsoft.com/VisualStudio/feedback/details/262047
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPILER_MSVC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_M_IX86
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
name|uint64_t
name|__rdtsc
parameter_list|()
function_decl|;
end_extern

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|__rdtsc
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_OS_WINDOWS
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BENCHMARK_OS_EMSCRIPTEN
end_ifdef

begin_include
include|#
directive|include
file|<emscripten.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|benchmark
block|{
comment|// NOTE: only i386 and x86_64 have been well tested.
comment|// PPC, sparc, alpha, and ia64 are based on
comment|//    http://peter.kuscsik.com/wordpress/?p=14
comment|// with modifications by m3b.  See also
comment|//    https://setisvn.ssl.berkeley.edu/svn/lib/fftw-3.0.1/kernel/cycle.h
name|namespace
name|cycleclock
block|{
comment|// This should return the number of cycles since power-on.  Thread-safe.
specifier|inline
name|BENCHMARK_ALWAYS_INLINE
name|int64_t
name|Now
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|BENCHMARK_OS_MACOSX
argument_list|)
comment|// this goes at the top because we need ALL Macs, regardless of
comment|// architecture, to return the number of "mach time units" that
comment|// have passed since startup.  See sysinfo.cc where
comment|// InitializeSystemInfo() sets the supposed cpu clock frequency of
comment|// macs to the number of mach time units per second, not actual
comment|// CPU clock frequency (which can change in the face of CPU
comment|// frequency scaling).  Also note that when the Mac sleeps, this
comment|// counter pauses; it does not continue counting, nor does it
comment|// reset to zero.
return|return
name|mach_absolute_time
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|BENCHMARK_OS_EMSCRIPTEN
argument_list|)
comment|// this goes above x86-specific code because old versions of Emscripten
comment|// define __x86_64__, although they have nothing to do with it.
return|return
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|emscripten_get_now
argument_list|()
operator|*
literal|1e+6
operator|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
name|int64_t
name|ret
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("rdtsc" : "=A"(ret));
return|return
name|ret
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
name|uint64_t
name|low
decl_stmt|,
name|high
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("rdtsc" : "=a"(low), "=d"(high));
return|return
operator|(
name|high
operator|<<
literal|32
operator|)
operator||
name|low
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
comment|// This returns a time-base, which is not always precisely a cycle-count.
name|int64_t
name|tbl
decl_stmt|,
name|tbu0
decl_stmt|,
name|tbu1
decl_stmt|;
asm|asm("mftbu %0" : "=r"(tbu0));
asm|asm("mftb  %0" : "=r"(tbl));
asm|asm("mftbu %0" : "=r"(tbu1));
name|tbl
operator|&=
operator|-
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|tbu0
operator|==
name|tbu1
operator|)
expr_stmt|;
comment|// high 32 bits in tbu1; low 32 bits in tbl  (tbu0 is garbage)
return|return
operator|(
name|tbu1
operator|<<
literal|32
operator|)
operator||
name|tbl
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc__
argument_list|)
name|int64_t
name|tick
decl_stmt|;
asm|asm(".byte 0x83, 0x41, 0x00, 0x00");
asm|asm("mov   %%g1, %0" : "=r"(tick));
return|return
name|tick
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
name|int64_t
name|itc
decl_stmt|;
asm|asm("mov %0 = ar.itc" : "=r"(itc));
return|return
name|itc
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|COMPILER_MSVC
argument_list|)
operator|&&
name|defined
argument_list|(
name|_M_IX86
argument_list|)
comment|// Older MSVC compilers (like 7.x) don't seem to support the
comment|// __rdtsc intrinsic properly, so I prefer to use _asm instead
comment|// when I know it will work.  Otherwise, I'll use __rdtsc and hope
comment|// the code is being compiled with a non-ancient compiler.
name|_asm
name|rdtsc
elif|#
directive|elif
name|defined
argument_list|(
name|COMPILER_MSVC
argument_list|)
return|return
name|__rdtsc
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|BENCHMARK_OS_NACL
argument_list|)
comment|// Native Client validator on x86/x86-64 allows RDTSC instructions,
comment|// and this case is handled above. Native Client validator on ARM
comment|// rejects MRC instructions (used in the ARM-specific sequence below),
comment|// so we handle it here. Portable Native Client compiles to
comment|// architecture-agnostic bytecode, which doesn't provide any
comment|// cycle counter access mnemonics.
comment|// Native Client does not provide any API to access cycle counter.
comment|// Use clock_gettime(CLOCK_MONOTONIC, ...) instead of gettimeofday
comment|// because is provides nanosecond resolution (which is noticable at
comment|// least for PNaCl modules running on x86 Mac& Linux).
comment|// Initialize to always return 0 if clock_gettime fails.
name|struct
name|timespec
name|ts
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|clock_gettime
argument_list|(
name|CLOCK_MONOTONIC
argument_list|,
operator|&
name|ts
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|ts
operator|.
name|tv_sec
operator|)
operator|*
literal|1000000000
operator|+
name|ts
operator|.
name|tv_nsec
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
comment|// System timer of ARMv8 runs at a different frequency than the CPU's.
comment|// The frequency is fixed, typically in the range 1-50MHz.  It can be
comment|// read at CNTFRQ special register.  We assume the OS has set up
comment|// the virtual timer properly.
name|int64_t
name|virtual_timer_value
decl_stmt|;
asm|asm
specifier|volatile
asm|("mrs %0, cntvct_el0" : "=r"(virtual_timer_value));
return|return
name|virtual_timer_value
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH
argument_list|)
comment|// V6 is the earliest arch that has a standard cyclecount
comment|// Native Client validator doesn't allow MRC instructions.
if|#
directive|if
operator|(
name|__ARM_ARCH
operator|>=
literal|6
operator|)
name|uint32_t
name|pmccntr
decl_stmt|;
name|uint32_t
name|pmuseren
decl_stmt|;
name|uint32_t
name|pmcntenset
decl_stmt|;
comment|// Read the user mode perf monitor counter access permissions.
asm|asm
specifier|volatile
asm|("mrc p15, 0, %0, c9, c14, 0" : "=r"(pmuseren));
if|if
condition|(
name|pmuseren
operator|&
literal|1
condition|)
block|{
comment|// Allows reading perfmon counters for user mode code.
asm|asm
specifier|volatile
asm|("mrc p15, 0, %0, c9, c12, 1" : "=r"(pmcntenset));
if|if
condition|(
name|pmcntenset
operator|&
literal|0x80000000ul
condition|)
block|{
comment|// Is it counting?
asm|asm
specifier|volatile
asm|("mrc p15, 0, %0, c9, c13, 0" : "=r"(pmccntr));
comment|// The counter is set up to count every 64th cycle
return|return
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|pmccntr
operator|)
operator|*
literal|64
return|;
comment|// Should optimize to<< 6
block|}
block|}
endif|#
directive|endif
name|struct
name|timeval
name|tv
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
name|nullptr
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|tv
operator|.
name|tv_sec
operator|)
operator|*
literal|1000000
operator|+
name|tv
operator|.
name|tv_usec
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|__mips__
argument_list|)
comment|// mips apparently only allows rdtsc for superusers, so we fall
comment|// back to gettimeofday.  It's possible clock_gettime would be better.
name|struct
name|timeval
name|tv
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
name|nullptr
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|tv
operator|.
name|tv_sec
operator|)
operator|*
literal|1000000
operator|+
name|tv
operator|.
name|tv_usec
return|;
else|#
directive|else
comment|// The soft failover to a generic implementation is automatic only for ARM.
comment|// For other platforms the developer is expected to make an attempt to create
comment|// a fast implementation and use generic version if nothing better is available.
error|#
directive|error
error|You need to define CycleTimer for your OS and CPU
endif|#
directive|endif
block|}
block|}
comment|// end namespace cycleclock
block|}
end_decl_stmt

begin_comment
comment|// end namespace benchmark
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BENCHMARK_CYCLECLOCK_H_
end_comment

end_unit

