begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GCC inline implementation of BaseLib processor specific functions.      Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Used to serialize load and store operations.    All loads and stores that proceed calls to this function are guaranteed to be   globally visible when this function returns.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|MemoryFence
parameter_list|(
name|VOID
parameter_list|)
block|{
comment|// This is a little bit of overkill and it is more about the compiler that it is
comment|// actually processor synchronization. This is like the _ReadWriteBarrier
comment|// Microsoft specific intrinsic
asm|__asm__
specifier|__volatile__
asm|("":::"memory");
block|}
end_function

begin_comment
comment|/**   Enables CPU interrupts.    Enables CPU interrupts.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|EnableInterrupts
parameter_list|(
name|VOID
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("sti"::: "memory");
block|}
end_function

begin_comment
comment|/**   Disables CPU interrupts.    Disables CPU interrupts.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|DisableInterrupts
parameter_list|(
name|VOID
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("cli"::: "memory");
block|}
end_function

begin_comment
comment|/**   Requests CPU to pause for a short period of time.    Requests CPU to pause for a short period of time. Typically used in MP   systems to prevent memory starvation while waiting for a spin lock.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|CpuPause
parameter_list|(
name|VOID
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("pause");
block|}
end_function

begin_comment
comment|/**   Generates a breakpoint on the CPU.    Generates a breakpoint on the CPU. The breakpoint must be implemented such   that code can resume normal execution after the breakpoint.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|CpuBreakpoint
parameter_list|(
name|VOID
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("int $3");
block|}
end_function

begin_comment
comment|/**   Returns a 64-bit Machine Specific Register(MSR).    Reads and returns the 64-bit MSR specified by Index. No parameter checking is   performed on Index, and some Index values may cause CPU exceptions. The   caller must either guarantee that Index is valid, or the caller must set up   exception handlers to catch the exceptions. This function is only available   on IA-32 and X64.    @param  Index The 32-bit MSR index to read.    @return The value of the MSR identified by Index.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMsr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|)
block|{
name|UINT32
name|LowData
decl_stmt|;
name|UINT32
name|HighData
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "rdmsr"     : "=a" (LowData),
comment|// %0
asm|"=d" (HighData)
comment|// %1
asm|: "c"  (Index)
comment|// %2
asm|);
return|return
operator|(
operator|(
operator|(
name|UINT64
operator|)
name|HighData
operator|)
operator|<<
literal|32
operator|)
operator||
name|LowData
return|;
block|}
end_function

begin_comment
comment|/**   Writes a 64-bit value to a Machine Specific Register(MSR), and returns the   value.    Writes the 64-bit value specified by Value to the MSR specified by Index. The   64-bit value written to the MSR is returned. No parameter checking is   performed on Index or Value, and some of these may cause CPU exceptions. The   caller must either guarantee that Index and Value are valid, or the caller   must establish proper exception handlers. This function is only available on   IA-32 and X64.    @param  Index The 32-bit MSR index to write.   @param  Value The 64-bit value to write to the MSR.    @return Value  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmWriteMsr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
name|UINT32
name|LowData
decl_stmt|;
name|UINT32
name|HighData
decl_stmt|;
name|LowData
operator|=
call|(
name|UINT32
call|)
argument_list|(
name|Value
argument_list|)
expr_stmt|;
name|HighData
operator|=
call|(
name|UINT32
call|)
argument_list|(
name|Value
operator|>>
literal|32
argument_list|)
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "wrmsr"     :     : "c" (Index),       "a" (LowData),       "d" (HighData)     );
return|return
name|Value
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of the EFLAGS register.    Reads and returns the current value of the EFLAGS register. This function is   only available on IA-32 and X64. This returns a 32-bit value on IA-32 and a   64-bit value on X64.    @return EFLAGS on IA-32 or RFLAGS on X64.  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadEflags
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Eflags
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "pushfq         \n\t"     "pop     %0         "     : "=r" (Eflags)
comment|// %0
asm|);
return|return
name|Eflags
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of the Control Register 0 (CR0).    Reads and returns the current value of CR0. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of the Control Register 0 (CR0).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadCr0
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%cr0,%0"      : "=r" (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of the Control Register 2 (CR2).    Reads and returns the current value of CR2. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of the Control Register 2 (CR2).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadCr2
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%cr2,  %0"      : "=r" (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of the Control Register 3 (CR3).    Reads and returns the current value of CR3. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of the Control Register 3 (CR3).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadCr3
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%cr3,  %0"      : "=r" (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of the Control Register 4 (CR4).    Reads and returns the current value of CR4. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of the Control Register 4 (CR4).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadCr4
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%cr4,  %0"      : "=r" (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Control Register 0 (CR0).    Writes and returns a new value to CR0. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Cr0 The value to write to CR0.    @return The value written to CR0.  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteCr0
parameter_list|(
name|UINTN
name|Cr0
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%cr0"     :     : "r" (Cr0)     );
return|return
name|Cr0
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Control Register 2 (CR2).    Writes and returns a new value to CR2. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Cr2 The value to write to CR2.    @return The value written to CR2.  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteCr2
parameter_list|(
name|UINTN
name|Cr2
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%cr2"     :     : "r" (Cr2)     );
return|return
name|Cr2
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Control Register 3 (CR3).    Writes and returns a new value to CR3. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Cr3 The value to write to CR3.    @return The value written to CR3.  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteCr3
parameter_list|(
name|UINTN
name|Cr3
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%cr3"     :     : "r" (Cr3)     );
return|return
name|Cr3
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Control Register 4 (CR4).    Writes and returns a new value to CR4. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Cr4 The value to write to CR4.    @return The value written to CR4.  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteCr4
parameter_list|(
name|UINTN
name|Cr4
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%cr4"     :     : "r" (Cr4)     );
return|return
name|Cr4
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Debug Register 0 (DR0).    Reads and returns the current value of DR0. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of Debug Register 0 (DR0).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr0
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%dr0, %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Debug Register 1 (DR1).    Reads and returns the current value of DR1. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of Debug Register 1 (DR1).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr1
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%dr1, %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Debug Register 2 (DR2).    Reads and returns the current value of DR2. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of Debug Register 2 (DR2).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr2
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%dr2, %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Debug Register 3 (DR3).    Reads and returns the current value of DR3. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of Debug Register 3 (DR3).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr3
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%dr3, %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Debug Register 4 (DR4).    Reads and returns the current value of DR4. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of Debug Register 4 (DR4).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr4
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%dr4, %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Debug Register 5 (DR5).    Reads and returns the current value of DR5. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of Debug Register 5 (DR5).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr5
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%dr5, %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Debug Register 6 (DR6).    Reads and returns the current value of DR6. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of Debug Register 6 (DR6).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr6
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%dr6, %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Debug Register 7 (DR7).    Reads and returns the current value of DR7. This function is only available   on IA-32 and X64. This returns a 32-bit value on IA-32 and a 64-bit value on   X64.    @return The value of Debug Register 7 (DR7).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr7
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINTN
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%dr7, %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Debug Register 0 (DR0).    Writes and returns a new value to DR0. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Dr0 The value to write to Dr0.    @return The value written to Debug Register 0 (DR0).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr0
parameter_list|(
name|UINTN
name|Dr0
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%dr0"     :     : "r" (Dr0)     );
return|return
name|Dr0
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Debug Register 1 (DR1).    Writes and returns a new value to DR1. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Dr1 The value to write to Dr1.    @return The value written to Debug Register 1 (DR1).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr1
parameter_list|(
name|UINTN
name|Dr1
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%dr1"     :     : "r" (Dr1)     );
return|return
name|Dr1
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Debug Register 2 (DR2).    Writes and returns a new value to DR2. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Dr2 The value to write to Dr2.    @return The value written to Debug Register 2 (DR2).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr2
parameter_list|(
name|UINTN
name|Dr2
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%dr2"     :     : "r" (Dr2)     );
return|return
name|Dr2
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Debug Register 3 (DR3).    Writes and returns a new value to DR3. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Dr3 The value to write to Dr3.    @return The value written to Debug Register 3 (DR3).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr3
parameter_list|(
name|UINTN
name|Dr3
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%dr3"     :     : "r" (Dr3)     );
return|return
name|Dr3
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Debug Register 4 (DR4).    Writes and returns a new value to DR4. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Dr4 The value to write to Dr4.    @return The value written to Debug Register 4 (DR4).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr4
parameter_list|(
name|UINTN
name|Dr4
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%dr4"     :     : "r" (Dr4)     );
return|return
name|Dr4
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Debug Register 5 (DR5).    Writes and returns a new value to DR5. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Dr5 The value to write to Dr5.    @return The value written to Debug Register 5 (DR5).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr5
parameter_list|(
name|UINTN
name|Dr5
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%dr5"     :     : "r" (Dr5)     );
return|return
name|Dr5
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Debug Register 6 (DR6).    Writes and returns a new value to DR6. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Dr6 The value to write to Dr6.    @return The value written to Debug Register 6 (DR6).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr6
parameter_list|(
name|UINTN
name|Dr6
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%dr6"     :     : "r" (Dr6)     );
return|return
name|Dr6
return|;
block|}
end_function

begin_comment
comment|/**   Writes a value to Debug Register 7 (DR7).    Writes and returns a new value to DR7. This function is only available on   IA-32 and X64. This writes a 32-bit value on IA-32 and a 64-bit value on X64.    @param  Dr7 The value to write to Dr7.    @return The value written to Debug Register 7 (DR7).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr7
parameter_list|(
name|UINTN
name|Dr7
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mov  %0, %%dr7"     :     : "r" (Dr7)     );
return|return
name|Dr7
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Code Segment Register (CS).    Reads and returns the current value of CS. This function is only available on   IA-32 and X64.    @return The current value of CS.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadCs
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT16
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov   %%cs, %0"     :"=a" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Data Segment Register (DS).    Reads and returns the current value of DS. This function is only available on   IA-32 and X64.    @return The current value of DS.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadDs
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT16
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%ds, %0"     :"=a" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Extra Segment Register (ES).    Reads and returns the current value of ES. This function is only available on   IA-32 and X64.    @return The current value of ES.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadEs
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT16
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%es, %0"     :"=a" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of FS Data Segment Register (FS).    Reads and returns the current value of FS. This function is only available on   IA-32 and X64.    @return The current value of FS.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadFs
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT16
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%fs, %0"     :"=a" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of GS Data Segment Register (GS).    Reads and returns the current value of GS. This function is only available on   IA-32 and X64.    @return The current value of GS.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadGs
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT16
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%gs, %0"     :"=a" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Stack Segment Register (SS).    Reads and returns the current value of SS. This function is only available on   IA-32 and X64.    @return The current value of SS.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadSs
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT16
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "mov  %%ds, %0"     :"=a" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of Task Register (TR).    Reads and returns the current value of TR. This function is only available on   IA-32 and X64.    @return The current value of TR.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadTr
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT16
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "str  %0"     : "=r" (Data)     );
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current Global Descriptor Table Register(GDTR) descriptor.    Reads and returns the current GDTR descriptor and returns it in Gdtr. This   function is only available on IA-32 and X64.    @param  Gdtr  The pointer to a GDTR descriptor.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86ReadGdtr
parameter_list|(
name|OUT
name|IA32_DESCRIPTOR
modifier|*
name|Gdtr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "sgdt %0"     : "=m" (*Gdtr)     );
block|}
end_function

begin_comment
comment|/**   Writes the current Global Descriptor Table Register (GDTR) descriptor.    Writes and the current GDTR descriptor specified by Gdtr. This function is   only available on IA-32 and X64.    @param  Gdtr  The pointer to a GDTR descriptor.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86WriteGdtr
parameter_list|(
name|IN
name|CONST
name|IA32_DESCRIPTOR
modifier|*
name|Gdtr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "lgdt %0"     :     : "m" (*Gdtr)     );
block|}
end_function

begin_comment
comment|/**   Reads the current Interrupt Descriptor Table Register(GDTR) descriptor.    Reads and returns the current IDTR descriptor and returns it in Idtr. This   function is only available on IA-32 and X64.    @param  Idtr  The pointer to a IDTR descriptor.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86ReadIdtr
parameter_list|(
name|OUT
name|IA32_DESCRIPTOR
modifier|*
name|Idtr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "sidt  %0"     : "=m" (*Idtr)     );
block|}
end_function

begin_comment
comment|/**   Writes the current Interrupt Descriptor Table Register(GDTR) descriptor.    Writes the current IDTR descriptor and returns it in Idtr. This function is   only available on IA-32 and X64.    @param  Idtr  The pointer to a IDTR descriptor.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86WriteIdtr
parameter_list|(
name|IN
name|CONST
name|IA32_DESCRIPTOR
modifier|*
name|Idtr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "lidt %0"     :     : "m" (*Idtr)     );
block|}
end_function

begin_comment
comment|/**   Reads the current Local Descriptor Table Register(LDTR) selector.    Reads and returns the current 16-bit LDTR descriptor value. This function is   only available on IA-32 and X64.    @return The current selector of LDT.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|AsmReadLdtr
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT16
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "sldt  %0"     : "=g" (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Writes the current Local Descriptor Table Register (GDTR) selector.    Writes and the current LDTR descriptor specified by Ldtr. This function is   only available on IA-32 and X64.    @param  Ldtr  16-bit LDTR selector value.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteLdtr
parameter_list|(
name|IN
name|UINT16
name|Ldtr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "lldtw  %0"     :     : "g" (Ldtr)
comment|// %0
asm|);
block|}
end_function

begin_comment
comment|/**   Save the current floating point/SSE/SSE2 context to a buffer.    Saves the current floating point/SSE/SSE2 state to the buffer specified by   Buffer. Buffer must be aligned on a 16-byte boundary. This function is only   available on IA-32 and X64.    @param  Buffer  The pointer to a buffer to save the floating point/SSE/SSE2 context.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86FxSave
parameter_list|(
name|OUT
name|IA32_FX_BUFFER
modifier|*
name|Buffer
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "fxsave %0"     :     : "m" (*Buffer)
comment|// %0
asm|);
block|}
end_function

begin_comment
comment|/**   Restores the current floating point/SSE/SSE2 context from a buffer.    Restores the current floating point/SSE/SSE2 state from the buffer specified   by Buffer. Buffer must be aligned on a 16-byte boundary. This function is   only available on IA-32 and X64.    @param  Buffer  The pointer to a buffer to save the floating point/SSE/SSE2 context.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86FxRestore
parameter_list|(
name|IN
name|CONST
name|IA32_FX_BUFFER
modifier|*
name|Buffer
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "fxrstor %0"     :     : "m" (*Buffer)
comment|// %0
asm|);
block|}
end_function

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #0 (MM0).    Reads and returns the current value of MM0. This function is only available   on IA-32 and X64.    @return The current value of MM0.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm0
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "movd   %%mm0,  %0    \n\t"     : "=r"  (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #1 (MM1).    Reads and returns the current value of MM1. This function is only available   on IA-32 and X64.    @return The current value of MM1.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm1
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "movd   %%mm1,  %0    \n\t"     : "=r"  (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #2 (MM2).    Reads and returns the current value of MM2. This function is only available   on IA-32 and X64.    @return The current value of MM2.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm2
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "movd  %%mm2,  %0    \n\t"     : "=r"  (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #3 (MM3).    Reads and returns the current value of MM3. This function is only available   on IA-32 and X64.    @return The current value of MM3.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm3
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "movd  %%mm3,  %0    \n\t"     : "=r"  (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #4 (MM4).    Reads and returns the current value of MM4. This function is only available   on IA-32 and X64.    @return The current value of MM4.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm4
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "movd  %%mm4,  %0    \n\t"     : "=r"  (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #5 (MM5).    Reads and returns the current value of MM5. This function is only available   on IA-32 and X64.    @return The current value of MM5.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm5
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "movd  %%mm5,  %0    \n\t"     : "=r"  (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #6 (MM6).    Reads and returns the current value of MM6. This function is only available   on IA-32 and X64.    @return The current value of MM6.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm6
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "movd  %%mm6,  %0    \n\t"     : "=r"  (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #7 (MM7).    Reads and returns the current value of MM7. This function is only available   on IA-32 and X64.    @return The current value of MM7.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm7
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Data
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "movd  %%mm7,  %0    \n\t"     : "=r"  (Data)
comment|// %0
asm|);
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #0 (MM0).    Writes the current value of MM0. This function is only available on IA32 and   X64.    @param  Value The 64-bit value to write to MM0.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm0
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "movd  %0, %%mm0"
comment|// %0
asm|:       : "m" (Value)     );
block|}
end_function

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #1 (MM1).    Writes the current value of MM1. This function is only available on IA32 and   X64.    @param  Value The 64-bit value to write to MM1.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm1
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "movd  %0, %%mm1"
comment|// %0
asm|:       : "m" (Value)     );
block|}
end_function

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #2 (MM2).    Writes the current value of MM2. This function is only available on IA32 and   X64.    @param  Value The 64-bit value to write to MM2.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm2
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "movd  %0, %%mm2"
comment|// %0
asm|:       : "m" (Value)     );
block|}
end_function

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #3 (MM3).    Writes the current value of MM3. This function is only available on IA32 and   X64.    @param  Value The 64-bit value to write to MM3.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm3
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "movd  %0, %%mm3"
comment|// %0
asm|:       : "m" (Value)     );
block|}
end_function

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #4 (MM4).    Writes the current value of MM4. This function is only available on IA32 and   X64.    @param  Value The 64-bit value to write to MM4.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm4
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "movd  %0, %%mm4"
comment|// %0
asm|:       : "m" (Value)     );
block|}
end_function

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #5 (MM5).    Writes the current value of MM5. This function is only available on IA32 and   X64.    @param  Value The 64-bit value to write to MM5.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm5
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "movd  %0, %%mm5"
comment|// %0
asm|:       : "m" (Value)     );
block|}
end_function

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #6 (MM6).    Writes the current value of MM6. This function is only available on IA32 and   X64.    @param  Value The 64-bit value to write to MM6.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm6
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "movd  %0, %%mm6"
comment|// %0
asm|:       : "m" (Value)     );
block|}
end_function

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #7 (MM7).    Writes the current value of MM7. This function is only available on IA32 and   X64.    @param  Value The 64-bit value to write to MM7.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm7
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "movd  %0, %%mm7"
comment|// %0
asm|:       : "m" (Value)     );
block|}
end_function

begin_comment
comment|/**   Reads the current value of Time Stamp Counter (TSC).    Reads and returns the current value of TSC. This function is only available   on IA-32 and X64.    @return The current value of TSC  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadTsc
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT32
name|LowData
decl_stmt|;
name|UINT32
name|HiData
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "rdtsc"     : "=a" (LowData),       "=d" (HiData)     );
return|return
operator|(
operator|(
operator|(
name|UINT64
operator|)
name|HiData
operator|)
operator|<<
literal|32
operator|)
operator||
name|LowData
return|;
block|}
end_function

begin_comment
comment|/**   Reads the current value of a Performance Counter (PMC).    Reads and returns the current value of performance counter specified by   Index. This function is only available on IA-32 and X64.    @param  Index The 32-bit Performance Counter index to read.    @return The value of the PMC specified by Index.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadPmc
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|)
block|{
name|UINT32
name|LowData
decl_stmt|;
name|UINT32
name|HiData
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "rdpmc"     : "=a" (LowData),       "=d" (HiData)     : "c"  (Index)     );
return|return
operator|(
operator|(
operator|(
name|UINT64
operator|)
name|HiData
operator|)
operator|<<
literal|32
operator|)
operator||
name|LowData
return|;
block|}
end_function

begin_comment
comment|/**   Sets up a monitor buffer that is used by AsmMwait().    Executes a MONITOR instruction with the register state specified by Eax, Ecx   and Edx. Returns Eax. This function is only available on IA-32 and X64.    @param  Eax The value to load into EAX or RAX before executing the MONITOR               instruction.   @param  Ecx The value to load into ECX or RCX before executing the MONITOR               instruction.   @param  Edx The value to load into EDX or RDX before executing the MONITOR               instruction.    @return Eax  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmMonitor
parameter_list|(
name|IN
name|UINTN
name|Eax
parameter_list|,
name|IN
name|UINTN
name|Ecx
parameter_list|,
name|IN
name|UINTN
name|Edx
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "monitor"     :     : "a" (Eax),       "c" (Ecx),       "d" (Edx)     );
return|return
name|Eax
return|;
block|}
end_function

begin_comment
comment|/**   Executes an MWAIT instruction.    Executes an MWAIT instruction with the register state specified by Eax and   Ecx. Returns Eax. This function is only available on IA-32 and X64.    @param  Eax The value to load into EAX or RAX before executing the MONITOR               instruction.   @param  Ecx The value to load into ECX or RCX before executing the MONITOR               instruction.    @return Eax  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmMwait
parameter_list|(
name|IN
name|UINTN
name|Eax
parameter_list|,
name|IN
name|UINTN
name|Ecx
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "mwait"     :      : "a"  (Eax),       "c"  (Ecx)     );
return|return
name|Eax
return|;
block|}
end_function

begin_comment
comment|/**   Executes a WBINVD instruction.    Executes a WBINVD instruction. This function is only available on IA-32 and   X64.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWbinvd
parameter_list|(
name|VOID
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("wbinvd":::"memory");
block|}
end_function

begin_comment
comment|/**   Executes a INVD instruction.    Executes a INVD instruction. This function is only available on IA-32 and   X64.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmInvd
parameter_list|(
name|VOID
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("invd":::"memory");
block|}
end_function

begin_comment
comment|/**   Flushes a cache line from all the instruction and data caches within the   coherency domain of the CPU.    Flushed the cache line specified by LinearAddress, and returns LinearAddress.   This function is only available on IA-32 and X64.    @param  LinearAddress The address of the cache line to flush. If the CPU is                         in a physical addressing mode, then LinearAddress is a                         physical address. If the CPU is in a virtual                         addressing mode, then LinearAddress is a virtual                         address.    @return LinearAddress **/
end_comment

begin_function
name|VOID
modifier|*
name|EFIAPI
name|AsmFlushCacheLine
parameter_list|(
name|IN
name|VOID
modifier|*
name|LinearAddress
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(     "clflush (%0)"     :     : "r" (LinearAddress)      : "memory"     );
return|return
name|LinearAddress
return|;
block|}
end_function

end_unit

