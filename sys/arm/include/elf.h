begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 David E. O'Brien  * Copyright (c) 1996-1997 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ELF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ELF_H_
value|1
end_define

begin_comment
comment|/*  * EABI ELF definitions for the StrongARM architecture.  * See "ARM ELF", document no. `SWS ESPC 0003 A-08' for details.  */
end_comment

begin_include
include|#
directive|include
file|<sys/elf32.h>
end_include

begin_comment
comment|/* Definitions common to all 32 bit architectures. */
end_comment

begin_define
define|#
directive|define
name|__ELF_WORD_SIZE
value|32
end_define

begin_comment
comment|/* Used by<sys/elf_generic.h> */
end_comment

begin_include
include|#
directive|include
file|<sys/elf_generic.h>
end_include

begin_define
define|#
directive|define
name|ELF_ARCH
value|EM_ARM
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_OK
parameter_list|(
name|x
parameter_list|)
value|((x) == EM_ARM)
end_define

begin_comment
comment|/*  * Relocation types.  */
end_comment

begin_define
define|#
directive|define
name|R_ARM_NONE
value|0
end_define

begin_comment
comment|/* No relocation. */
end_comment

begin_define
define|#
directive|define
name|R_ARM_PC24
value|1
end_define

begin_define
define|#
directive|define
name|R_ARM_ABS32
value|2
end_define

begin_define
define|#
directive|define
name|R_ARM_REL32
value|3
end_define

begin_define
define|#
directive|define
name|R_ARM_PC13
value|4
end_define

begin_define
define|#
directive|define
name|R_ARM_ABS16
value|5
end_define

begin_define
define|#
directive|define
name|R_ARM_ABS12
value|6
end_define

begin_define
define|#
directive|define
name|R_ARM_THM_ABS5
value|7
end_define

begin_define
define|#
directive|define
name|R_ARM_ABS8
value|8
end_define

begin_define
define|#
directive|define
name|R_ARM_SBREL32
value|9
end_define

begin_define
define|#
directive|define
name|R_ARM_THM_PC22
value|10
end_define

begin_define
define|#
directive|define
name|R_ARM_THM_PC8
value|11
end_define

begin_define
define|#
directive|define
name|R_ARM_AMP_VCALL9
value|12
end_define

begin_define
define|#
directive|define
name|R_ARM_SWI24
value|13
end_define

begin_define
define|#
directive|define
name|R_ARM_THM_SWI8
value|14
end_define

begin_define
define|#
directive|define
name|R_ARM_XPC25
value|15
end_define

begin_define
define|#
directive|define
name|R_ARM_THM_XPC22
value|16
end_define

begin_define
define|#
directive|define
name|R_ARM_COPY
value|20
end_define

begin_comment
comment|/* Copy data from shared object. */
end_comment

begin_define
define|#
directive|define
name|R_ARM_GLOB_DAT
value|21
end_define

begin_comment
comment|/* Set GOT entry to data address. */
end_comment

begin_define
define|#
directive|define
name|R_ARM_JUMP_SLOT
value|22
end_define

begin_comment
comment|/* Set GOT entry to code address. */
end_comment

begin_define
define|#
directive|define
name|R_ARM_RELATIVE
value|23
end_define

begin_comment
comment|/* Add load address of shared object. */
end_comment

begin_define
define|#
directive|define
name|R_ARM_GOTOFF
value|24
end_define

begin_comment
comment|/* Add GOT-relative symbol address. * #define	R_ARM_GOTPC		25	/* Add PC-relative GOT table address. */
end_comment

begin_define
define|#
directive|define
name|R_ARM_GOT32
value|26
end_define

begin_comment
comment|/* Add PC-relative GOT offset. */
end_comment

begin_define
define|#
directive|define
name|R_ARM_PLT32
value|27
end_define

begin_comment
comment|/* Add PC-relative PLT offset. */
end_comment

begin_define
define|#
directive|define
name|R_ARM_GNU_VTENTRY
value|100
end_define

begin_define
define|#
directive|define
name|R_ARM_GNU_VTINHERIT
value|101
end_define

begin_define
define|#
directive|define
name|R_ARM_RSBREL32
value|250
end_define

begin_define
define|#
directive|define
name|R_ARM_THM_RPC22
value|251
end_define

begin_define
define|#
directive|define
name|R_ARM_RREL32
value|252
end_define

begin_define
define|#
directive|define
name|R_ARM_RABS32
value|253
end_define

begin_define
define|#
directive|define
name|R_ARM_RPC24
value|254
end_define

begin_define
define|#
directive|define
name|R_ARM_RBASE
value|255
end_define

begin_define
define|#
directive|define
name|R_ARM_COUNT
value|33
end_define

begin_comment
comment|/* Count of defined relocation types. */
end_comment

begin_comment
comment|/* Define "machine" characteristics */
end_comment

begin_define
define|#
directive|define
name|ELF_TARG_CLASS
value|ELFCLASS32
end_define

begin_define
define|#
directive|define
name|ELF_TARG_DATA
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|ELF_TARG_MACH
value|EM_ARM
end_define

begin_define
define|#
directive|define
name|ELF_TARG_VER
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * On the StrongARM we load the dynamic linker where a userland call  * to mmap(0, ...) would put it.  The rationale behind this  * calculation is that it leaves room for the heap to grow to  * its maximum allowed size.  */
end_comment

begin_define
define|#
directive|define
name|ELF_RTLD_ADDR
parameter_list|(
name|vmspace
parameter_list|)
define|\
value|(round_page((vm_offset_t)(vmspace)->vm_daddr + maxdsiz))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ELF_H_ */
end_comment

end_unit

