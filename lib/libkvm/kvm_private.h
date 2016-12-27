begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software developed by the Computer Systems  * Engineering group at Lawrence Berkeley Laboratory under DARPA contract  * BG 91-66 and contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kvm_private.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_struct
struct|struct
name|kvm_arch
block|{
name|int
function_decl|(
modifier|*
name|ka_probe
function_decl|)
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ka_initvtop
function_decl|)
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ka_freevtop
function_decl|)
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ka_kvatop
function_decl|)
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|kvaddr_t
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ka_native
function_decl|)
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KVM_ARCH
parameter_list|(
name|ka
parameter_list|)
value|DATA_SET(kvm_arch, ka)
end_define

begin_struct
struct|struct
name|__kvm
block|{
name|struct
name|kvm_arch
modifier|*
name|arch
decl_stmt|;
comment|/* 	 * a string to be prepended to error messages 	 * provided for compatibility with sun's interface 	 * if this value is null, errors are saved in errbuf[] 	 */
specifier|const
name|char
modifier|*
name|program
decl_stmt|;
name|char
modifier|*
name|errp
decl_stmt|;
comment|/* XXX this can probably go away */
name|char
name|errbuf
index|[
name|_POSIX2_LINE_MAX
index|]
decl_stmt|;
define|#
directive|define
name|ISALIVE
parameter_list|(
name|kd
parameter_list|)
value|((kd)->vmfd>= 0)
name|int
name|pmfd
decl_stmt|;
comment|/* physical memory file (or crashdump) */
name|int
name|vmfd
decl_stmt|;
comment|/* virtual memory file (-1 if crashdump) */
name|int
name|nlfd
decl_stmt|;
comment|/* namelist file (e.g., /kernel) */
name|GElf_Ehdr
name|nlehdr
decl_stmt|;
comment|/* ELF file header for namelist file */
name|int
function_decl|(
modifier|*
name|resolve_symbol
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|kvaddr_t
modifier|*
parameter_list|)
function_decl|;
name|struct
name|kinfo_proc
modifier|*
name|procbase
decl_stmt|;
name|char
modifier|*
name|argspc
decl_stmt|;
comment|/* (dynamic) storage for argv strings */
name|int
name|arglen
decl_stmt|;
comment|/* length of the above */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* (dynamic) storage for argv pointers */
name|int
name|argc
decl_stmt|;
comment|/* length of above (not actual # present) */
name|char
modifier|*
name|argbuf
decl_stmt|;
comment|/* (dynamic) temporary storage */
comment|/* 	 * Kernel virtual address translation state.  This only gets filled 	 * in for dead kernels; otherwise, the running kernel (i.e. kmem) 	 * will do the translations for us.  It could be big, so we 	 * only allocate it if necessary. 	 */
name|struct
name|vmstate
modifier|*
name|vmst
decl_stmt|;
name|int
name|rawdump
decl_stmt|;
comment|/* raw dump format */
name|int
name|writable
decl_stmt|;
comment|/* physical memory is writable */
name|int
name|vnet_initialized
decl_stmt|;
comment|/* vnet fields set up */
name|kvaddr_t
name|vnet_start
decl_stmt|;
comment|/* start of kernel's vnet region */
name|kvaddr_t
name|vnet_stop
decl_stmt|;
comment|/* stop of kernel's vnet region */
name|kvaddr_t
name|vnet_current
decl_stmt|;
comment|/* vnet we're working with */
name|kvaddr_t
name|vnet_base
decl_stmt|;
comment|/* vnet base of current vnet */
comment|/* 	 * Dynamic per-CPU kernel memory.  We translate symbols, on-demand, 	 * to the data associated with dpcpu_curcpu, set with 	 * kvm_dpcpu_setcpu(). 	 */
name|int
name|dpcpu_initialized
decl_stmt|;
comment|/* dpcpu fields set up */
name|kvaddr_t
name|dpcpu_start
decl_stmt|;
comment|/* start of kernel's dpcpu region */
name|kvaddr_t
name|dpcpu_stop
decl_stmt|;
comment|/* stop of kernel's dpcpu region */
name|u_int
name|dpcpu_maxcpus
decl_stmt|;
comment|/* size of base array */
name|uintptr_t
modifier|*
name|dpcpu_off
decl_stmt|;
comment|/* base array, indexed by CPU ID */
name|u_int
name|dpcpu_curcpu
decl_stmt|;
comment|/* CPU we're currently working with */
name|kvaddr_t
name|dpcpu_curoff
decl_stmt|;
comment|/* dpcpu base of current CPU */
comment|/* Page table lookup structures. */
name|uint64_t
modifier|*
name|pt_map
decl_stmt|;
name|size_t
name|pt_map_size
decl_stmt|;
name|off_t
name|pt_sparse_off
decl_stmt|;
name|uint64_t
name|pt_sparse_size
decl_stmt|;
name|uint32_t
modifier|*
name|pt_popcounts
decl_stmt|;
name|unsigned
name|int
name|pt_page_size
decl_stmt|;
name|unsigned
name|int
name|pt_word_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Page table lookup constants. */
end_comment

begin_define
define|#
directive|define
name|POPCOUNT_BITS
value|1024
end_define

begin_define
define|#
directive|define
name|BITS_IN
parameter_list|(
name|v
parameter_list|)
value|(sizeof(v) * NBBY)
end_define

begin_define
define|#
directive|define
name|POPCOUNTS_IN
parameter_list|(
name|v
parameter_list|)
value|(POPCOUNT_BITS / BITS_IN(v))
end_define

begin_comment
comment|/*  * Functions used internally by kvm, but across kvm modules.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|_kvm32toh
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
if|if
condition|(
name|kd
operator|->
name|nlehdr
operator|.
name|e_ident
index|[
name|EI_DATA
index|]
operator|==
name|ELFDATA2LSB
condition|)
return|return
operator|(
name|le32toh
argument_list|(
name|val
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|be32toh
argument_list|(
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|_kvm64toh
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
if|if
condition|(
name|kd
operator|->
name|nlehdr
operator|.
name|e_ident
index|[
name|EI_DATA
index|]
operator|==
name|ELFDATA2LSB
condition|)
return|return
operator|(
name|le64toh
argument_list|(
name|val
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|be64toh
argument_list|(
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|void
name|_kvm_err
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
specifier|const
name|char
modifier|*
name|program
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_kvm_freeprocs
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_kvm_malloc
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_nlist
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|struct
name|kvm_nlist
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_kvm_realloc
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kvm_syserr
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
specifier|const
name|char
modifier|*
name|program
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|_kvm_vnet_selectpid
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_vnet_initialized
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kvaddr_t
name|_kvm_vnet_validaddr
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|kvaddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_dpcpu_initialized
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kvaddr_t
name|_kvm_dpcpu_validaddr
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|kvaddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_probe_elf_kernel
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_is_minidump
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_read_core_phdrs
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|GElf_Phdr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_pt_init
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|_kvm_pt_find
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

