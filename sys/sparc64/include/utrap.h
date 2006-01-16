begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_UTRAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_UTRAP_H_
end_define

begin_define
define|#
directive|define
name|UT_INSTRUCTION_EXCEPTION
value|1
end_define

begin_define
define|#
directive|define
name|UT_INSTRUCTION_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|UT_INSTRUCTION_PROTECTION
value|3
end_define

begin_define
define|#
directive|define
name|UT_ILLTRAP_INSTRUCTION
value|4
end_define

begin_define
define|#
directive|define
name|UT_ILLEGAL_INSTRUCTION
value|5
end_define

begin_define
define|#
directive|define
name|UT_PRIVILEGED_OPCODE
value|6
end_define

begin_define
define|#
directive|define
name|UT_FP_DISABLED
value|7
end_define

begin_define
define|#
directive|define
name|UT_FP_EXCEPTION_IEEE_754
value|8
end_define

begin_define
define|#
directive|define
name|UT_FP_EXCEPTION_OTHER
value|9
end_define

begin_define
define|#
directive|define
name|UT_TAG_OVERFLOW
value|10
end_define

begin_define
define|#
directive|define
name|UT_DIVISION_BY_ZERO
value|11
end_define

begin_define
define|#
directive|define
name|UT_DATA_EXCEPTION
value|12
end_define

begin_define
define|#
directive|define
name|UT_DATA_ERROR
value|13
end_define

begin_define
define|#
directive|define
name|UT_DATA_PROTECTION
value|14
end_define

begin_define
define|#
directive|define
name|UT_MEM_ADDRESS_NOT_ALIGNED
value|15
end_define

begin_define
define|#
directive|define
name|UT_PRIVILEGED_ACTION
value|16
end_define

begin_define
define|#
directive|define
name|UT_ASYNC_DATA_ERROR
value|17
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_16
value|18
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_17
value|19
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_18
value|20
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_19
value|21
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_20
value|22
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_21
value|23
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_22
value|24
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_23
value|25
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_24
value|26
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_25
value|27
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_26
value|28
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_27
value|29
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_28
value|30
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_29
value|31
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_30
value|32
end_define

begin_define
define|#
directive|define
name|UT_TRAP_INSTRUCTION_31
value|33
end_define

begin_define
define|#
directive|define
name|UT_INSTRUCTION_MISS
value|34
end_define

begin_define
define|#
directive|define
name|UT_DATA_MISS
value|35
end_define

begin_define
define|#
directive|define
name|UT_MAX
value|36
end_define

begin_define
define|#
directive|define
name|ST_SUNOS_SYSCALL
value|0
end_define

begin_define
define|#
directive|define
name|ST_BREAKPOINT
value|1
end_define

begin_define
define|#
directive|define
name|ST_DIVISION_BY_ZERO
value|2
end_define

begin_define
define|#
directive|define
name|ST_FLUSH_WINDOWS
value|3
end_define

begin_comment
comment|/* XXX implement! */
end_comment

begin_define
define|#
directive|define
name|ST_CLEAN_WINDOW
value|4
end_define

begin_define
define|#
directive|define
name|ST_RANGE_CHECK
value|5
end_define

begin_define
define|#
directive|define
name|ST_FIX_ALIGNMENT
value|6
end_define

begin_define
define|#
directive|define
name|ST_INTEGER_OVERFLOW
value|7
end_define

begin_comment
comment|/* 8 is 32-bit ABI syscall (old solaris syscall?) */
end_comment

begin_define
define|#
directive|define
name|ST_BSD_SYSCALL
value|9
end_define

begin_define
define|#
directive|define
name|ST_FP_RESTORE
value|10
end_define

begin_comment
comment|/* 11-15 are available */
end_comment

begin_comment
comment|/* 16 is linux 32 bit syscall (but supposed to be reserved, grr) */
end_comment

begin_comment
comment|/* 17 is old linux 64 bit syscall (but supposed to be reserved, grr) */
end_comment

begin_comment
comment|/* 16-31 are reserved for user applications (utraps) */
end_comment

begin_define
define|#
directive|define
name|ST_GETCC
value|32
end_define

begin_comment
comment|/* XXX implement! */
end_comment

begin_define
define|#
directive|define
name|ST_SETCC
value|33
end_define

begin_comment
comment|/* XXX implement! */
end_comment

begin_define
define|#
directive|define
name|ST_GETPSR
value|34
end_define

begin_comment
comment|/* XXX implement! */
end_comment

begin_define
define|#
directive|define
name|ST_SETPSR
value|35
end_define

begin_comment
comment|/* XXX implement! */
end_comment

begin_comment
comment|/* 36-63 are available */
end_comment

begin_define
define|#
directive|define
name|ST_SOLARIS_SYSCALL
value|64
end_define

begin_define
define|#
directive|define
name|ST_SYSCALL
value|65
end_define

begin_define
define|#
directive|define
name|ST_SYSCALL32
value|66
end_define

begin_comment
comment|/* 67 is reserved to OS source licensee */
end_comment

begin_comment
comment|/* 68 is return from deferred trap (not supported) */
end_comment

begin_comment
comment|/* 69-95 are reserved to SPARC international */
end_comment

begin_comment
comment|/* 96-108 are available */
end_comment

begin_comment
comment|/* 109 is linux 64 bit syscall */
end_comment

begin_comment
comment|/* 110 is linux 64 bit getcontext (?) */
end_comment

begin_comment
comment|/* 111 is linux 64 bit setcontext (?) */
end_comment

begin_comment
comment|/* 112-255 are available */
end_comment

begin_define
define|#
directive|define
name|UTH_NOCHANGE
value|(-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASM__
end_ifndef

begin_typedef
typedef|typedef
name|int
name|utrap_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|utrap_handler_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

