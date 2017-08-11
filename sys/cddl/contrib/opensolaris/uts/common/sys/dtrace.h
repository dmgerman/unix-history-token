begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013, Joyent, Inc. All rights reserved.  * Copyright (c) 2013 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DTRACE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * DTrace Dynamic Tracing Software: Kernel Interfaces  *  * Note: The contents of this file are private to the implementation of the  * Solaris system and DTrace subsystem and are subject to change at any time  * without notice.  Applications and drivers using these interfaces will fail  * to run on future releases.  These interfaces should not be used for any  * purpose except those expressly outlined in dtrace(7D) and libdtrace(3LIB).  * Please refer to the "Solaris Dynamic Tracing Guide" for more information.  */
ifndef|#
directive|ifndef
name|_ASM
include|#
directive|include
file|<sys/types.h>
include|#
directive|include
file|<sys/modctl.h>
include|#
directive|include
file|<sys/processor.h>
ifdef|#
directive|ifdef
name|illumos
include|#
directive|include
file|<sys/systm.h>
else|#
directive|else
include|#
directive|include
file|<sys/cpuvar.h>
include|#
directive|include
file|<sys/param.h>
include|#
directive|include
file|<sys/linker.h>
include|#
directive|include
file|<sys/ioccom.h>
include|#
directive|include
file|<sys/ucred.h>
typedef|typedef
name|int
name|model_t
typedef|;
endif|#
directive|endif
include|#
directive|include
file|<sys/ctf_api.h>
ifdef|#
directive|ifdef
name|illumos
include|#
directive|include
file|<sys/cyclic.h>
include|#
directive|include
file|<sys/int_limits.h>
else|#
directive|else
include|#
directive|include
file|<sys/stdint.h>
endif|#
directive|endif
comment|/*  * DTrace Universal Constants and Typedefs  */
define|#
directive|define
name|DTRACE_CPUALL
value|-1
comment|/* all CPUs */
define|#
directive|define
name|DTRACE_IDNONE
value|0
comment|/* invalid probe identifier */
define|#
directive|define
name|DTRACE_EPIDNONE
value|0
comment|/* invalid enabled probe identifier */
define|#
directive|define
name|DTRACE_AGGIDNONE
value|0
comment|/* invalid aggregation identifier */
define|#
directive|define
name|DTRACE_AGGVARIDNONE
value|0
comment|/* invalid aggregation variable ID */
define|#
directive|define
name|DTRACE_CACHEIDNONE
value|0
comment|/* invalid predicate cache */
define|#
directive|define
name|DTRACE_PROVNONE
value|0
comment|/* invalid provider identifier */
define|#
directive|define
name|DTRACE_METAPROVNONE
value|0
comment|/* invalid meta-provider identifier */
define|#
directive|define
name|DTRACE_ARGNONE
value|-1
comment|/* invalid argument index */
define|#
directive|define
name|DTRACE_PROVNAMELEN
value|64
define|#
directive|define
name|DTRACE_MODNAMELEN
value|64
define|#
directive|define
name|DTRACE_FUNCNAMELEN
value|192
define|#
directive|define
name|DTRACE_NAMELEN
value|64
define|#
directive|define
name|DTRACE_FULLNAMELEN
value|(DTRACE_PROVNAMELEN + DTRACE_MODNAMELEN + \ 				DTRACE_FUNCNAMELEN + DTRACE_NAMELEN + 4)
define|#
directive|define
name|DTRACE_ARGTYPELEN
value|128
typedef|typedef
name|uint32_t
name|dtrace_id_t
typedef|;
comment|/* probe identifier */
typedef|typedef
name|uint32_t
name|dtrace_epid_t
typedef|;
comment|/* enabled probe identifier */
typedef|typedef
name|uint32_t
name|dtrace_aggid_t
typedef|;
comment|/* aggregation identifier */
typedef|typedef
name|int64_t
name|dtrace_aggvarid_t
typedef|;
comment|/* aggregation variable identifier */
typedef|typedef
name|uint16_t
name|dtrace_actkind_t
typedef|;
comment|/* action kind */
typedef|typedef
name|int64_t
name|dtrace_optval_t
typedef|;
comment|/* option value */
typedef|typedef
name|uint32_t
name|dtrace_cacheid_t
typedef|;
comment|/* predicate cache identifier */
typedef|typedef
enum|enum
name|dtrace_probespec
block|{
name|DTRACE_PROBESPEC_NONE
init|=
operator|-
literal|1
block|,
name|DTRACE_PROBESPEC_PROVIDER
init|=
literal|0
block|,
name|DTRACE_PROBESPEC_MOD
block|,
name|DTRACE_PROBESPEC_FUNC
block|,
name|DTRACE_PROBESPEC_NAME
block|}
name|dtrace_probespec_t
typedef|;
comment|/*  * DTrace Intermediate Format (DIF)  *  * The following definitions describe the DTrace Intermediate Format (DIF), a  * a RISC-like instruction set and program encoding used to represent  * predicates and actions that can be bound to DTrace probes.  The constants  * below defining the number of available registers are suggested minimums; the  * compiler should use DTRACEIOC_CONF to dynamically obtain the number of  * registers provided by the current DTrace implementation.  */
define|#
directive|define
name|DIF_VERSION_1
value|1
comment|/* DIF version 1: Solaris 10 Beta */
define|#
directive|define
name|DIF_VERSION_2
value|2
comment|/* DIF version 2: Solaris 10 FCS */
define|#
directive|define
name|DIF_VERSION
value|DIF_VERSION_2
comment|/* latest DIF instruction set version */
define|#
directive|define
name|DIF_DIR_NREGS
value|8
comment|/* number of DIF integer registers */
define|#
directive|define
name|DIF_DTR_NREGS
value|8
comment|/* number of DIF tuple registers */
define|#
directive|define
name|DIF_OP_OR
value|1
comment|/* or	r1, r2, rd */
define|#
directive|define
name|DIF_OP_XOR
value|2
comment|/* xor	r1, r2, rd */
define|#
directive|define
name|DIF_OP_AND
value|3
comment|/* and	r1, r2, rd */
define|#
directive|define
name|DIF_OP_SLL
value|4
comment|/* sll	r1, r2, rd */
define|#
directive|define
name|DIF_OP_SRL
value|5
comment|/* srl	r1, r2, rd */
define|#
directive|define
name|DIF_OP_SUB
value|6
comment|/* sub	r1, r2, rd */
define|#
directive|define
name|DIF_OP_ADD
value|7
comment|/* add	r1, r2, rd */
define|#
directive|define
name|DIF_OP_MUL
value|8
comment|/* mul	r1, r2, rd */
define|#
directive|define
name|DIF_OP_SDIV
value|9
comment|/* sdiv	r1, r2, rd */
define|#
directive|define
name|DIF_OP_UDIV
value|10
comment|/* udiv r1, r2, rd */
define|#
directive|define
name|DIF_OP_SREM
value|11
comment|/* srem r1, r2, rd */
define|#
directive|define
name|DIF_OP_UREM
value|12
comment|/* urem r1, r2, rd */
define|#
directive|define
name|DIF_OP_NOT
value|13
comment|/* not	r1, rd */
define|#
directive|define
name|DIF_OP_MOV
value|14
comment|/* mov	r1, rd */
define|#
directive|define
name|DIF_OP_CMP
value|15
comment|/* cmp	r1, r2 */
define|#
directive|define
name|DIF_OP_TST
value|16
comment|/* tst  r1 */
define|#
directive|define
name|DIF_OP_BA
value|17
comment|/* ba	label */
define|#
directive|define
name|DIF_OP_BE
value|18
comment|/* be	label */
define|#
directive|define
name|DIF_OP_BNE
value|19
comment|/* bne	label */
define|#
directive|define
name|DIF_OP_BG
value|20
comment|/* bg	label */
define|#
directive|define
name|DIF_OP_BGU
value|21
comment|/* bgu	label */
define|#
directive|define
name|DIF_OP_BGE
value|22
comment|/* bge	label */
define|#
directive|define
name|DIF_OP_BGEU
value|23
comment|/* bgeu	label */
define|#
directive|define
name|DIF_OP_BL
value|24
comment|/* bl	label */
define|#
directive|define
name|DIF_OP_BLU
value|25
comment|/* blu	label */
define|#
directive|define
name|DIF_OP_BLE
value|26
comment|/* ble	label */
define|#
directive|define
name|DIF_OP_BLEU
value|27
comment|/* bleu	label */
define|#
directive|define
name|DIF_OP_LDSB
value|28
comment|/* ldsb	[r1], rd */
define|#
directive|define
name|DIF_OP_LDSH
value|29
comment|/* ldsh	[r1], rd */
define|#
directive|define
name|DIF_OP_LDSW
value|30
comment|/* ldsw [r1], rd */
define|#
directive|define
name|DIF_OP_LDUB
value|31
comment|/* ldub	[r1], rd */
define|#
directive|define
name|DIF_OP_LDUH
value|32
comment|/* lduh	[r1], rd */
define|#
directive|define
name|DIF_OP_LDUW
value|33
comment|/* lduw	[r1], rd */
define|#
directive|define
name|DIF_OP_LDX
value|34
comment|/* ldx	[r1], rd */
define|#
directive|define
name|DIF_OP_RET
value|35
comment|/* ret	rd */
define|#
directive|define
name|DIF_OP_NOP
value|36
comment|/* nop */
define|#
directive|define
name|DIF_OP_SETX
value|37
comment|/* setx	intindex, rd */
define|#
directive|define
name|DIF_OP_SETS
value|38
comment|/* sets strindex, rd */
define|#
directive|define
name|DIF_OP_SCMP
value|39
comment|/* scmp	r1, r2 */
define|#
directive|define
name|DIF_OP_LDGA
value|40
comment|/* ldga	var, ri, rd */
define|#
directive|define
name|DIF_OP_LDGS
value|41
comment|/* ldgs var, rd */
define|#
directive|define
name|DIF_OP_STGS
value|42
comment|/* stgs var, rs */
define|#
directive|define
name|DIF_OP_LDTA
value|43
comment|/* ldta var, ri, rd */
define|#
directive|define
name|DIF_OP_LDTS
value|44
comment|/* ldts var, rd */
define|#
directive|define
name|DIF_OP_STTS
value|45
comment|/* stts var, rs */
define|#
directive|define
name|DIF_OP_SRA
value|46
comment|/* sra	r1, r2, rd */
define|#
directive|define
name|DIF_OP_CALL
value|47
comment|/* call	subr, rd */
define|#
directive|define
name|DIF_OP_PUSHTR
value|48
comment|/* pushtr type, rs, rr */
define|#
directive|define
name|DIF_OP_PUSHTV
value|49
comment|/* pushtv type, rs, rv */
define|#
directive|define
name|DIF_OP_POPTS
value|50
comment|/* popts */
define|#
directive|define
name|DIF_OP_FLUSHTS
value|51
comment|/* flushts */
define|#
directive|define
name|DIF_OP_LDGAA
value|52
comment|/* ldgaa var, rd */
define|#
directive|define
name|DIF_OP_LDTAA
value|53
comment|/* ldtaa var, rd */
define|#
directive|define
name|DIF_OP_STGAA
value|54
comment|/* stgaa var, rs */
define|#
directive|define
name|DIF_OP_STTAA
value|55
comment|/* sttaa var, rs */
define|#
directive|define
name|DIF_OP_LDLS
value|56
comment|/* ldls	var, rd */
define|#
directive|define
name|DIF_OP_STLS
value|57
comment|/* stls	var, rs */
define|#
directive|define
name|DIF_OP_ALLOCS
value|58
comment|/* allocs r1, rd */
define|#
directive|define
name|DIF_OP_COPYS
value|59
comment|/* copys  r1, r2, rd */
define|#
directive|define
name|DIF_OP_STB
value|60
comment|/* stb	r1, [rd] */
define|#
directive|define
name|DIF_OP_STH
value|61
comment|/* sth	r1, [rd] */
define|#
directive|define
name|DIF_OP_STW
value|62
comment|/* stw	r1, [rd] */
define|#
directive|define
name|DIF_OP_STX
value|63
comment|/* stx	r1, [rd] */
define|#
directive|define
name|DIF_OP_ULDSB
value|64
comment|/* uldsb [r1], rd */
define|#
directive|define
name|DIF_OP_ULDSH
value|65
comment|/* uldsh [r1], rd */
define|#
directive|define
name|DIF_OP_ULDSW
value|66
comment|/* uldsw [r1], rd */
define|#
directive|define
name|DIF_OP_ULDUB
value|67
comment|/* uldub [r1], rd */
define|#
directive|define
name|DIF_OP_ULDUH
value|68
comment|/* ulduh [r1], rd */
define|#
directive|define
name|DIF_OP_ULDUW
value|69
comment|/* ulduw [r1], rd */
define|#
directive|define
name|DIF_OP_ULDX
value|70
comment|/* uldx  [r1], rd */
define|#
directive|define
name|DIF_OP_RLDSB
value|71
comment|/* rldsb [r1], rd */
define|#
directive|define
name|DIF_OP_RLDSH
value|72
comment|/* rldsh [r1], rd */
define|#
directive|define
name|DIF_OP_RLDSW
value|73
comment|/* rldsw [r1], rd */
define|#
directive|define
name|DIF_OP_RLDUB
value|74
comment|/* rldub [r1], rd */
define|#
directive|define
name|DIF_OP_RLDUH
value|75
comment|/* rlduh [r1], rd */
define|#
directive|define
name|DIF_OP_RLDUW
value|76
comment|/* rlduw [r1], rd */
define|#
directive|define
name|DIF_OP_RLDX
value|77
comment|/* rldx  [r1], rd */
define|#
directive|define
name|DIF_OP_XLATE
value|78
comment|/* xlate xlrindex, rd */
define|#
directive|define
name|DIF_OP_XLARG
value|79
comment|/* xlarg xlrindex, rd */
define|#
directive|define
name|DIF_INTOFF_MAX
value|0xffff
comment|/* highest integer table offset */
define|#
directive|define
name|DIF_STROFF_MAX
value|0xffff
comment|/* highest string table offset */
define|#
directive|define
name|DIF_REGISTER_MAX
value|0xff
comment|/* highest register number */
define|#
directive|define
name|DIF_VARIABLE_MAX
value|0xffff
comment|/* highest variable identifier */
define|#
directive|define
name|DIF_SUBROUTINE_MAX
value|0xffff
comment|/* highest subroutine code */
define|#
directive|define
name|DIF_VAR_ARRAY_MIN
value|0x0000
comment|/* lowest numbered array variable */
define|#
directive|define
name|DIF_VAR_ARRAY_UBASE
value|0x0080
comment|/* lowest user-defined array */
define|#
directive|define
name|DIF_VAR_ARRAY_MAX
value|0x00ff
comment|/* highest numbered array variable */
define|#
directive|define
name|DIF_VAR_OTHER_MIN
value|0x0100
comment|/* lowest numbered scalar or assc */
define|#
directive|define
name|DIF_VAR_OTHER_UBASE
value|0x0500
comment|/* lowest user-defined scalar or assc */
define|#
directive|define
name|DIF_VAR_OTHER_MAX
value|0xffff
comment|/* highest numbered scalar or assc */
define|#
directive|define
name|DIF_VAR_ARGS
value|0x0000
comment|/* arguments array */
define|#
directive|define
name|DIF_VAR_REGS
value|0x0001
comment|/* registers array */
define|#
directive|define
name|DIF_VAR_UREGS
value|0x0002
comment|/* user registers array */
define|#
directive|define
name|DIF_VAR_CURTHREAD
value|0x0100
comment|/* thread pointer */
define|#
directive|define
name|DIF_VAR_TIMESTAMP
value|0x0101
comment|/* timestamp */
define|#
directive|define
name|DIF_VAR_VTIMESTAMP
value|0x0102
comment|/* virtual timestamp */
define|#
directive|define
name|DIF_VAR_IPL
value|0x0103
comment|/* interrupt priority level */
define|#
directive|define
name|DIF_VAR_EPID
value|0x0104
comment|/* enabled probe ID */
define|#
directive|define
name|DIF_VAR_ID
value|0x0105
comment|/* probe ID */
define|#
directive|define
name|DIF_VAR_ARG0
value|0x0106
comment|/* first argument */
define|#
directive|define
name|DIF_VAR_ARG1
value|0x0107
comment|/* second argument */
define|#
directive|define
name|DIF_VAR_ARG2
value|0x0108
comment|/* third argument */
define|#
directive|define
name|DIF_VAR_ARG3
value|0x0109
comment|/* fourth argument */
define|#
directive|define
name|DIF_VAR_ARG4
value|0x010a
comment|/* fifth argument */
define|#
directive|define
name|DIF_VAR_ARG5
value|0x010b
comment|/* sixth argument */
define|#
directive|define
name|DIF_VAR_ARG6
value|0x010c
comment|/* seventh argument */
define|#
directive|define
name|DIF_VAR_ARG7
value|0x010d
comment|/* eighth argument */
define|#
directive|define
name|DIF_VAR_ARG8
value|0x010e
comment|/* ninth argument */
define|#
directive|define
name|DIF_VAR_ARG9
value|0x010f
comment|/* tenth argument */
define|#
directive|define
name|DIF_VAR_STACKDEPTH
value|0x0110
comment|/* stack depth */
define|#
directive|define
name|DIF_VAR_CALLER
value|0x0111
comment|/* caller */
define|#
directive|define
name|DIF_VAR_PROBEPROV
value|0x0112
comment|/* probe provider */
define|#
directive|define
name|DIF_VAR_PROBEMOD
value|0x0113
comment|/* probe module */
define|#
directive|define
name|DIF_VAR_PROBEFUNC
value|0x0114
comment|/* probe function */
define|#
directive|define
name|DIF_VAR_PROBENAME
value|0x0115
comment|/* probe name */
define|#
directive|define
name|DIF_VAR_PID
value|0x0116
comment|/* process ID */
define|#
directive|define
name|DIF_VAR_TID
value|0x0117
comment|/* (per-process) thread ID */
define|#
directive|define
name|DIF_VAR_EXECNAME
value|0x0118
comment|/* name of executable */
define|#
directive|define
name|DIF_VAR_ZONENAME
value|0x0119
comment|/* zone name associated with process */
define|#
directive|define
name|DIF_VAR_WALLTIMESTAMP
value|0x011a
comment|/* wall-clock timestamp */
define|#
directive|define
name|DIF_VAR_USTACKDEPTH
value|0x011b
comment|/* user-land stack depth */
define|#
directive|define
name|DIF_VAR_UCALLER
value|0x011c
comment|/* user-level caller */
define|#
directive|define
name|DIF_VAR_PPID
value|0x011d
comment|/* parent process ID */
define|#
directive|define
name|DIF_VAR_UID
value|0x011e
comment|/* process user ID */
define|#
directive|define
name|DIF_VAR_GID
value|0x011f
comment|/* process group ID */
define|#
directive|define
name|DIF_VAR_ERRNO
value|0x0120
comment|/* thread errno */
define|#
directive|define
name|DIF_VAR_EXECARGS
value|0x0121
comment|/* process arguments */
ifndef|#
directive|ifndef
name|illumos
define|#
directive|define
name|DIF_VAR_CPU
value|0x0200
endif|#
directive|endif
define|#
directive|define
name|DIF_SUBR_RAND
value|0
define|#
directive|define
name|DIF_SUBR_MUTEX_OWNED
value|1
define|#
directive|define
name|DIF_SUBR_MUTEX_OWNER
value|2
define|#
directive|define
name|DIF_SUBR_MUTEX_TYPE_ADAPTIVE
value|3
define|#
directive|define
name|DIF_SUBR_MUTEX_TYPE_SPIN
value|4
define|#
directive|define
name|DIF_SUBR_RW_READ_HELD
value|5
define|#
directive|define
name|DIF_SUBR_RW_WRITE_HELD
value|6
define|#
directive|define
name|DIF_SUBR_RW_ISWRITER
value|7
define|#
directive|define
name|DIF_SUBR_COPYIN
value|8
define|#
directive|define
name|DIF_SUBR_COPYINSTR
value|9
define|#
directive|define
name|DIF_SUBR_SPECULATION
value|10
define|#
directive|define
name|DIF_SUBR_PROGENYOF
value|11
define|#
directive|define
name|DIF_SUBR_STRLEN
value|12
define|#
directive|define
name|DIF_SUBR_COPYOUT
value|13
define|#
directive|define
name|DIF_SUBR_COPYOUTSTR
value|14
define|#
directive|define
name|DIF_SUBR_ALLOCA
value|15
define|#
directive|define
name|DIF_SUBR_BCOPY
value|16
define|#
directive|define
name|DIF_SUBR_COPYINTO
value|17
define|#
directive|define
name|DIF_SUBR_MSGDSIZE
value|18
define|#
directive|define
name|DIF_SUBR_MSGSIZE
value|19
define|#
directive|define
name|DIF_SUBR_GETMAJOR
value|20
define|#
directive|define
name|DIF_SUBR_GETMINOR
value|21
define|#
directive|define
name|DIF_SUBR_DDI_PATHNAME
value|22
define|#
directive|define
name|DIF_SUBR_STRJOIN
value|23
define|#
directive|define
name|DIF_SUBR_LLTOSTR
value|24
define|#
directive|define
name|DIF_SUBR_BASENAME
value|25
define|#
directive|define
name|DIF_SUBR_DIRNAME
value|26
define|#
directive|define
name|DIF_SUBR_CLEANPATH
value|27
define|#
directive|define
name|DIF_SUBR_STRCHR
value|28
define|#
directive|define
name|DIF_SUBR_STRRCHR
value|29
define|#
directive|define
name|DIF_SUBR_STRSTR
value|30
define|#
directive|define
name|DIF_SUBR_STRTOK
value|31
define|#
directive|define
name|DIF_SUBR_SUBSTR
value|32
define|#
directive|define
name|DIF_SUBR_INDEX
value|33
define|#
directive|define
name|DIF_SUBR_RINDEX
value|34
define|#
directive|define
name|DIF_SUBR_HTONS
value|35
define|#
directive|define
name|DIF_SUBR_HTONL
value|36
define|#
directive|define
name|DIF_SUBR_HTONLL
value|37
define|#
directive|define
name|DIF_SUBR_NTOHS
value|38
define|#
directive|define
name|DIF_SUBR_NTOHL
value|39
define|#
directive|define
name|DIF_SUBR_NTOHLL
value|40
define|#
directive|define
name|DIF_SUBR_INET_NTOP
value|41
define|#
directive|define
name|DIF_SUBR_INET_NTOA
value|42
define|#
directive|define
name|DIF_SUBR_INET_NTOA6
value|43
define|#
directive|define
name|DIF_SUBR_TOUPPER
value|44
define|#
directive|define
name|DIF_SUBR_TOLOWER
value|45
define|#
directive|define
name|DIF_SUBR_MEMREF
value|46
define|#
directive|define
name|DIF_SUBR_SX_SHARED_HELD
value|47
define|#
directive|define
name|DIF_SUBR_SX_EXCLUSIVE_HELD
value|48
define|#
directive|define
name|DIF_SUBR_SX_ISEXCLUSIVE
value|49
define|#
directive|define
name|DIF_SUBR_MEMSTR
value|50
define|#
directive|define
name|DIF_SUBR_GETF
value|51
define|#
directive|define
name|DIF_SUBR_JSON
value|52
define|#
directive|define
name|DIF_SUBR_STRTOLL
value|53
define|#
directive|define
name|DIF_SUBR_MAX
value|53
comment|/* max subroutine value */
typedef|typedef
name|uint32_t
name|dif_instr_t
typedef|;
define|#
directive|define
name|DIF_INSTR_OP
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 24)& 0xff)
define|#
directive|define
name|DIF_INSTR_R1
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 16)& 0xff)
define|#
directive|define
name|DIF_INSTR_R2
parameter_list|(
name|i
parameter_list|)
value|(((i)>>  8)& 0xff)
define|#
directive|define
name|DIF_INSTR_RD
parameter_list|(
name|i
parameter_list|)
value|((i)& 0xff)
define|#
directive|define
name|DIF_INSTR_RS
parameter_list|(
name|i
parameter_list|)
value|((i)& 0xff)
define|#
directive|define
name|DIF_INSTR_LABEL
parameter_list|(
name|i
parameter_list|)
value|((i)& 0xffffff)
define|#
directive|define
name|DIF_INSTR_VAR
parameter_list|(
name|i
parameter_list|)
value|(((i)>>  8)& 0xffff)
define|#
directive|define
name|DIF_INSTR_INTEGER
parameter_list|(
name|i
parameter_list|)
value|(((i)>>  8)& 0xffff)
define|#
directive|define
name|DIF_INSTR_STRING
parameter_list|(
name|i
parameter_list|)
value|(((i)>>  8)& 0xffff)
define|#
directive|define
name|DIF_INSTR_SUBR
parameter_list|(
name|i
parameter_list|)
value|(((i)>>  8)& 0xffff)
define|#
directive|define
name|DIF_INSTR_TYPE
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 16)& 0xff)
define|#
directive|define
name|DIF_INSTR_XLREF
parameter_list|(
name|i
parameter_list|)
value|(((i)>>  8)& 0xffff)
define|#
directive|define
name|DIF_INSTR_FMT
parameter_list|(
name|op
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|,
name|d
parameter_list|)
define|\
value|(((op)<< 24) | ((r1)<< 16) | ((r2)<< 8) | (d))
define|#
directive|define
name|DIF_INSTR_NOT
parameter_list|(
name|r1
parameter_list|,
name|d
parameter_list|)
value|(DIF_INSTR_FMT(DIF_OP_NOT, r1, 0, d))
define|#
directive|define
name|DIF_INSTR_MOV
parameter_list|(
name|r1
parameter_list|,
name|d
parameter_list|)
value|(DIF_INSTR_FMT(DIF_OP_MOV, r1, 0, d))
define|#
directive|define
name|DIF_INSTR_CMP
parameter_list|(
name|op
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|)
value|(DIF_INSTR_FMT(op, r1, r2, 0))
define|#
directive|define
name|DIF_INSTR_TST
parameter_list|(
name|r1
parameter_list|)
value|(DIF_INSTR_FMT(DIF_OP_TST, r1, 0, 0))
define|#
directive|define
name|DIF_INSTR_BRANCH
parameter_list|(
name|op
parameter_list|,
name|label
parameter_list|)
value|(((op)<< 24) | (label))
define|#
directive|define
name|DIF_INSTR_LOAD
parameter_list|(
name|op
parameter_list|,
name|r1
parameter_list|,
name|d
parameter_list|)
value|(DIF_INSTR_FMT(op, r1, 0, d))
define|#
directive|define
name|DIF_INSTR_STORE
parameter_list|(
name|op
parameter_list|,
name|r1
parameter_list|,
name|d
parameter_list|)
value|(DIF_INSTR_FMT(op, r1, 0, d))
define|#
directive|define
name|DIF_INSTR_SETX
parameter_list|(
name|i
parameter_list|,
name|d
parameter_list|)
value|((DIF_OP_SETX<< 24) | ((i)<< 8) | (d))
define|#
directive|define
name|DIF_INSTR_SETS
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|((DIF_OP_SETS<< 24) | ((s)<< 8) | (d))
define|#
directive|define
name|DIF_INSTR_RET
parameter_list|(
name|d
parameter_list|)
value|(DIF_INSTR_FMT(DIF_OP_RET, 0, 0, d))
define|#
directive|define
name|DIF_INSTR_NOP
value|(DIF_OP_NOP<< 24)
define|#
directive|define
name|DIF_INSTR_LDA
parameter_list|(
name|op
parameter_list|,
name|v
parameter_list|,
name|r
parameter_list|,
name|d
parameter_list|)
value|(DIF_INSTR_FMT(op, v, r, d))
define|#
directive|define
name|DIF_INSTR_LDV
parameter_list|(
name|op
parameter_list|,
name|v
parameter_list|,
name|d
parameter_list|)
value|(((op)<< 24) | ((v)<< 8) | (d))
define|#
directive|define
name|DIF_INSTR_STV
parameter_list|(
name|op
parameter_list|,
name|v
parameter_list|,
name|rs
parameter_list|)
value|(((op)<< 24) | ((v)<< 8) | (rs))
define|#
directive|define
name|DIF_INSTR_CALL
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|((DIF_OP_CALL<< 24) | ((s)<< 8) | (d))
define|#
directive|define
name|DIF_INSTR_PUSHTS
parameter_list|(
name|op
parameter_list|,
name|t
parameter_list|,
name|r2
parameter_list|,
name|rs
parameter_list|)
value|(DIF_INSTR_FMT(op, t, r2, rs))
define|#
directive|define
name|DIF_INSTR_POPTS
value|(DIF_OP_POPTS<< 24)
define|#
directive|define
name|DIF_INSTR_FLUSHTS
value|(DIF_OP_FLUSHTS<< 24)
define|#
directive|define
name|DIF_INSTR_ALLOCS
parameter_list|(
name|r1
parameter_list|,
name|d
parameter_list|)
value|(DIF_INSTR_FMT(DIF_OP_ALLOCS, r1, 0, d))
define|#
directive|define
name|DIF_INSTR_COPYS
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|,
name|d
parameter_list|)
value|(DIF_INSTR_FMT(DIF_OP_COPYS, r1, r2, d))
define|#
directive|define
name|DIF_INSTR_XLATE
parameter_list|(
name|op
parameter_list|,
name|r
parameter_list|,
name|d
parameter_list|)
value|(((op)<< 24) | ((r)<< 8) | (d))
define|#
directive|define
name|DIF_REG_R0
value|0
comment|/* %r0 is always set to zero */
comment|/*  * A DTrace Intermediate Format Type (DIF Type) is used to represent the types  * of variables, function and associative array arguments, and the return type  * for each DIF object (shown below).  It contains a description of the type,  * its size in bytes, and a module identifier.  */
typedef|typedef
struct|struct
name|dtrace_diftype
block|{
name|uint8_t
name|dtdt_kind
decl_stmt|;
comment|/* type kind (see below) */
name|uint8_t
name|dtdt_ckind
decl_stmt|;
comment|/* type kind in CTF */
name|uint8_t
name|dtdt_flags
decl_stmt|;
comment|/* type flags (see below) */
name|uint8_t
name|dtdt_pad
decl_stmt|;
comment|/* reserved for future use */
name|uint32_t
name|dtdt_size
decl_stmt|;
comment|/* type size in bytes (unless string) */
block|}
name|dtrace_diftype_t
typedef|;
define|#
directive|define
name|DIF_TYPE_CTF
value|0
comment|/* type is a CTF type */
define|#
directive|define
name|DIF_TYPE_STRING
value|1
comment|/* type is a D string */
define|#
directive|define
name|DIF_TF_BYREF
value|0x1
comment|/* type is passed by reference */
define|#
directive|define
name|DIF_TF_BYUREF
value|0x2
comment|/* user type is passed by reference */
comment|/*  * A DTrace Intermediate Format variable record is used to describe each of the  * variables referenced by a given DIF object.  It contains an integer variable  * identifier along with variable scope and properties, as shown below.  The  * size of this structure must be sizeof (int) aligned.  */
typedef|typedef
struct|struct
name|dtrace_difv
block|{
name|uint32_t
name|dtdv_name
decl_stmt|;
comment|/* variable name index in dtdo_strtab */
name|uint32_t
name|dtdv_id
decl_stmt|;
comment|/* variable reference identifier */
name|uint8_t
name|dtdv_kind
decl_stmt|;
comment|/* variable kind (see below) */
name|uint8_t
name|dtdv_scope
decl_stmt|;
comment|/* variable scope (see below) */
name|uint16_t
name|dtdv_flags
decl_stmt|;
comment|/* variable flags (see below) */
name|dtrace_diftype_t
name|dtdv_type
decl_stmt|;
comment|/* variable type (see above) */
block|}
name|dtrace_difv_t
typedef|;
define|#
directive|define
name|DIFV_KIND_ARRAY
value|0
comment|/* variable is an array of quantities */
define|#
directive|define
name|DIFV_KIND_SCALAR
value|1
comment|/* variable is a scalar quantity */
define|#
directive|define
name|DIFV_SCOPE_GLOBAL
value|0
comment|/* variable has global scope */
define|#
directive|define
name|DIFV_SCOPE_THREAD
value|1
comment|/* variable has thread scope */
define|#
directive|define
name|DIFV_SCOPE_LOCAL
value|2
comment|/* variable has local scope */
define|#
directive|define
name|DIFV_F_REF
value|0x1
comment|/* variable is referenced by DIFO */
define|#
directive|define
name|DIFV_F_MOD
value|0x2
comment|/* variable is written by DIFO */
comment|/*  * DTrace Actions  *  * The upper byte determines the class of the action; the low bytes determines  * the specific action within that class.  The classes of actions are as  * follows:  *  *   [ no class ]<= May record process- or kernel-related data  *   DTRACEACT_PROC<= Only records process-related data  *   DTRACEACT_PROC_DESTRUCTIVE<= Potentially destructive to processes  *   DTRACEACT_KERNEL<= Only records kernel-related data  *   DTRACEACT_KERNEL_DESTRUCTIVE<= Potentially destructive to the kernel  *   DTRACEACT_SPECULATIVE<= Speculation-related action  *   DTRACEACT_AGGREGATION<= Aggregating action  */
define|#
directive|define
name|DTRACEACT_NONE
value|0
comment|/* no action */
define|#
directive|define
name|DTRACEACT_DIFEXPR
value|1
comment|/* action is DIF expression */
define|#
directive|define
name|DTRACEACT_EXIT
value|2
comment|/* exit() action */
define|#
directive|define
name|DTRACEACT_PRINTF
value|3
comment|/* printf() action */
define|#
directive|define
name|DTRACEACT_PRINTA
value|4
comment|/* printa() action */
define|#
directive|define
name|DTRACEACT_LIBACT
value|5
comment|/* library-controlled action */
define|#
directive|define
name|DTRACEACT_TRACEMEM
value|6
comment|/* tracemem() action */
define|#
directive|define
name|DTRACEACT_TRACEMEM_DYNSIZE
value|7
comment|/* dynamic tracemem() size */
define|#
directive|define
name|DTRACEACT_PRINTM
value|8
comment|/* printm() action (BSD) */
define|#
directive|define
name|DTRACEACT_PROC
value|0x0100
define|#
directive|define
name|DTRACEACT_USTACK
value|(DTRACEACT_PROC + 1)
define|#
directive|define
name|DTRACEACT_JSTACK
value|(DTRACEACT_PROC + 2)
define|#
directive|define
name|DTRACEACT_USYM
value|(DTRACEACT_PROC + 3)
define|#
directive|define
name|DTRACEACT_UMOD
value|(DTRACEACT_PROC + 4)
define|#
directive|define
name|DTRACEACT_UADDR
value|(DTRACEACT_PROC + 5)
define|#
directive|define
name|DTRACEACT_PROC_DESTRUCTIVE
value|0x0200
define|#
directive|define
name|DTRACEACT_STOP
value|(DTRACEACT_PROC_DESTRUCTIVE + 1)
define|#
directive|define
name|DTRACEACT_RAISE
value|(DTRACEACT_PROC_DESTRUCTIVE + 2)
define|#
directive|define
name|DTRACEACT_SYSTEM
value|(DTRACEACT_PROC_DESTRUCTIVE + 3)
define|#
directive|define
name|DTRACEACT_FREOPEN
value|(DTRACEACT_PROC_DESTRUCTIVE + 4)
define|#
directive|define
name|DTRACEACT_PROC_CONTROL
value|0x0300
define|#
directive|define
name|DTRACEACT_KERNEL
value|0x0400
define|#
directive|define
name|DTRACEACT_STACK
value|(DTRACEACT_KERNEL + 1)
define|#
directive|define
name|DTRACEACT_SYM
value|(DTRACEACT_KERNEL + 2)
define|#
directive|define
name|DTRACEACT_MOD
value|(DTRACEACT_KERNEL + 3)
define|#
directive|define
name|DTRACEACT_KERNEL_DESTRUCTIVE
value|0x0500
define|#
directive|define
name|DTRACEACT_BREAKPOINT
value|(DTRACEACT_KERNEL_DESTRUCTIVE + 1)
define|#
directive|define
name|DTRACEACT_PANIC
value|(DTRACEACT_KERNEL_DESTRUCTIVE + 2)
define|#
directive|define
name|DTRACEACT_CHILL
value|(DTRACEACT_KERNEL_DESTRUCTIVE + 3)
define|#
directive|define
name|DTRACEACT_SPECULATIVE
value|0x0600
define|#
directive|define
name|DTRACEACT_SPECULATE
value|(DTRACEACT_SPECULATIVE + 1)
define|#
directive|define
name|DTRACEACT_COMMIT
value|(DTRACEACT_SPECULATIVE + 2)
define|#
directive|define
name|DTRACEACT_DISCARD
value|(DTRACEACT_SPECULATIVE + 3)
define|#
directive|define
name|DTRACEACT_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff00)
define|#
directive|define
name|DTRACEACT_ISDESTRUCTIVE
parameter_list|(
name|x
parameter_list|)
define|\
value|(DTRACEACT_CLASS(x) == DTRACEACT_PROC_DESTRUCTIVE || \ 	DTRACEACT_CLASS(x) == DTRACEACT_KERNEL_DESTRUCTIVE)
define|#
directive|define
name|DTRACEACT_ISSPECULATIVE
parameter_list|(
name|x
parameter_list|)
define|\
value|(DTRACEACT_CLASS(x) == DTRACEACT_SPECULATIVE)
define|#
directive|define
name|DTRACEACT_ISPRINTFLIKE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x) == DTRACEACT_PRINTF || (x) == DTRACEACT_PRINTA || \ 	(x) == DTRACEACT_SYSTEM || (x) == DTRACEACT_FREOPEN)
comment|/*  * DTrace Aggregating Actions  *  * These are functions f(x) for which the following is true:  *  *    f(f(x_0) U f(x_1) U ... U f(x_n)) = f(x_0 U x_1 U ... U x_n)  *  * where x_n is a set of arbitrary data.  Aggregating actions are in their own  * DTrace action class, DTTRACEACT_AGGREGATION.  The macros provided here allow  * for easier processing of the aggregation argument and data payload for a few  * aggregating actions (notably:  quantize(), lquantize(), and ustack()).  */
define|#
directive|define
name|DTRACEACT_AGGREGATION
value|0x0700
define|#
directive|define
name|DTRACEAGG_COUNT
value|(DTRACEACT_AGGREGATION + 1)
define|#
directive|define
name|DTRACEAGG_MIN
value|(DTRACEACT_AGGREGATION + 2)
define|#
directive|define
name|DTRACEAGG_MAX
value|(DTRACEACT_AGGREGATION + 3)
define|#
directive|define
name|DTRACEAGG_AVG
value|(DTRACEACT_AGGREGATION + 4)
define|#
directive|define
name|DTRACEAGG_SUM
value|(DTRACEACT_AGGREGATION + 5)
define|#
directive|define
name|DTRACEAGG_STDDEV
value|(DTRACEACT_AGGREGATION + 6)
define|#
directive|define
name|DTRACEAGG_QUANTIZE
value|(DTRACEACT_AGGREGATION + 7)
define|#
directive|define
name|DTRACEAGG_LQUANTIZE
value|(DTRACEACT_AGGREGATION + 8)
define|#
directive|define
name|DTRACEAGG_LLQUANTIZE
value|(DTRACEACT_AGGREGATION + 9)
define|#
directive|define
name|DTRACEACT_ISAGG
parameter_list|(
name|x
parameter_list|)
define|\
value|(DTRACEACT_CLASS(x) == DTRACEACT_AGGREGATION)
define|#
directive|define
name|DTRACE_QUANTIZE_NBUCKETS
define|\
value|(((sizeof (uint64_t) * NBBY) - 1) * 2 + 1)
define|#
directive|define
name|DTRACE_QUANTIZE_ZEROBUCKET
value|((sizeof (uint64_t) * NBBY) - 1)
define|#
directive|define
name|DTRACE_QUANTIZE_BUCKETVAL
parameter_list|(
name|buck
parameter_list|)
define|\
value|(int64_t)((buck)< DTRACE_QUANTIZE_ZEROBUCKET ?			\ 	-(1LL<< (DTRACE_QUANTIZE_ZEROBUCKET - 1 - (buck))) :		\ 	(buck) == DTRACE_QUANTIZE_ZEROBUCKET ? 0 :			\ 	1LL<< ((buck) - DTRACE_QUANTIZE_ZEROBUCKET - 1))
define|#
directive|define
name|DTRACE_LQUANTIZE_STEPSHIFT
value|48
define|#
directive|define
name|DTRACE_LQUANTIZE_STEPMASK
value|((uint64_t)UINT16_MAX<< 48)
define|#
directive|define
name|DTRACE_LQUANTIZE_LEVELSHIFT
value|32
define|#
directive|define
name|DTRACE_LQUANTIZE_LEVELMASK
value|((uint64_t)UINT16_MAX<< 32)
define|#
directive|define
name|DTRACE_LQUANTIZE_BASESHIFT
value|0
define|#
directive|define
name|DTRACE_LQUANTIZE_BASEMASK
value|UINT32_MAX
define|#
directive|define
name|DTRACE_LQUANTIZE_STEP
parameter_list|(
name|x
parameter_list|)
define|\
value|(uint16_t)(((x)& DTRACE_LQUANTIZE_STEPMASK)>> \ 	DTRACE_LQUANTIZE_STEPSHIFT)
define|#
directive|define
name|DTRACE_LQUANTIZE_LEVELS
parameter_list|(
name|x
parameter_list|)
define|\
value|(uint16_t)(((x)& DTRACE_LQUANTIZE_LEVELMASK)>> \ 	DTRACE_LQUANTIZE_LEVELSHIFT)
define|#
directive|define
name|DTRACE_LQUANTIZE_BASE
parameter_list|(
name|x
parameter_list|)
define|\
value|(int32_t)(((x)& DTRACE_LQUANTIZE_BASEMASK)>> \ 	DTRACE_LQUANTIZE_BASESHIFT)
define|#
directive|define
name|DTRACE_LLQUANTIZE_FACTORSHIFT
value|48
define|#
directive|define
name|DTRACE_LLQUANTIZE_FACTORMASK
value|((uint64_t)UINT16_MAX<< 48)
define|#
directive|define
name|DTRACE_LLQUANTIZE_LOWSHIFT
value|32
define|#
directive|define
name|DTRACE_LLQUANTIZE_LOWMASK
value|((uint64_t)UINT16_MAX<< 32)
define|#
directive|define
name|DTRACE_LLQUANTIZE_HIGHSHIFT
value|16
define|#
directive|define
name|DTRACE_LLQUANTIZE_HIGHMASK
value|((uint64_t)UINT16_MAX<< 16)
define|#
directive|define
name|DTRACE_LLQUANTIZE_NSTEPSHIFT
value|0
define|#
directive|define
name|DTRACE_LLQUANTIZE_NSTEPMASK
value|UINT16_MAX
define|#
directive|define
name|DTRACE_LLQUANTIZE_FACTOR
parameter_list|(
name|x
parameter_list|)
define|\
value|(uint16_t)(((x)& DTRACE_LLQUANTIZE_FACTORMASK)>> \ 	DTRACE_LLQUANTIZE_FACTORSHIFT)
define|#
directive|define
name|DTRACE_LLQUANTIZE_LOW
parameter_list|(
name|x
parameter_list|)
define|\
value|(uint16_t)(((x)& DTRACE_LLQUANTIZE_LOWMASK)>> \ 	DTRACE_LLQUANTIZE_LOWSHIFT)
define|#
directive|define
name|DTRACE_LLQUANTIZE_HIGH
parameter_list|(
name|x
parameter_list|)
define|\
value|(uint16_t)(((x)& DTRACE_LLQUANTIZE_HIGHMASK)>> \ 	DTRACE_LLQUANTIZE_HIGHSHIFT)
define|#
directive|define
name|DTRACE_LLQUANTIZE_NSTEP
parameter_list|(
name|x
parameter_list|)
define|\
value|(uint16_t)(((x)& DTRACE_LLQUANTIZE_NSTEPMASK)>> \ 	DTRACE_LLQUANTIZE_NSTEPSHIFT)
define|#
directive|define
name|DTRACE_USTACK_NFRAMES
parameter_list|(
name|x
parameter_list|)
value|(uint32_t)((x)& UINT32_MAX)
define|#
directive|define
name|DTRACE_USTACK_STRSIZE
parameter_list|(
name|x
parameter_list|)
value|(uint32_t)((x)>> 32)
define|#
directive|define
name|DTRACE_USTACK_ARG
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((((uint64_t)(y))<< 32) | ((x)& UINT32_MAX))
ifndef|#
directive|ifndef
name|_LP64
if|#
directive|if
name|BYTE_ORDER
operator|==
name|_BIG_ENDIAN
define|#
directive|define
name|DTRACE_PTR
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
value|uint32_t name##pad; type *name
else|#
directive|else
define|#
directive|define
name|DTRACE_PTR
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
value|type *name; uint32_t name##pad
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|DTRACE_PTR
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
value|type *name
endif|#
directive|endif
comment|/*  * DTrace Object Format (DOF)  *  * DTrace programs can be persistently encoded in the DOF format so that they  * may be embedded in other programs (for example, in an ELF file) or in the  * dtrace driver configuration file for use in anonymous tracing.  The DOF  * format is versioned and extensible so that it can be revised and so that  * internal data structures can be modified or extended compatibly.  All DOF  * structures use fixed-size types, so the 32-bit and 64-bit representations  * are identical and consumers can use either data model transparently.  *  * The file layout is structured as follows:  *  * +---------------+-------------------+----- ... ----+---- ... ------+  * |   dof_hdr_t   |  dof_sec_t[ ... ] |   loadable   | non-loadable  |  * | (file header) | (section headers) | section data | section data  |  * +---------------+-------------------+----- ... ----+---- ... ------+  * |<------------ dof_hdr.dofh_loadsz --------------->|               |  * |<------------ dof_hdr.dofh_filesz ------------------------------->|  *  * The file header stores meta-data including a magic number, data model for  * the instrumentation, data encoding, and properties of the DIF code within.  * The header describes its own size and the size of the section headers.  By  * convention, an array of section headers follows the file header, and then  * the data for all loadable sections and unloadable sections.  This permits  * consumer code to easily download the headers and all loadable data into the  * DTrace driver in one contiguous chunk, omitting other extraneous sections.  *  * The section headers describe the size, offset, alignment, and section type  * for each section.  Sections are described using a set of #defines that tell  * the consumer what kind of data is expected.  Sections can contain links to  * other sections by storing a dof_secidx_t, an index into the section header  * array, inside of the section data structures.  The section header includes  * an entry size so that sections with data arrays can grow their structures.  *  * The DOF data itself can contain many snippets of DIF (i.e.>1 DIFOs), which  * are represented themselves as a collection of related DOF sections.  This  * permits us to change the set of sections associated with a DIFO over time,  * and also permits us to encode DIFOs that contain different sets of sections.  * When a DOF section wants to refer to a DIFO, it stores the dof_secidx_t of a  * section of type DOF_SECT_DIFOHDR.  This section's data is then an array of  * dof_secidx_t's which in turn denote the sections associated with this DIFO.  *  * This loose coupling of the file structure (header and sections) to the  * structure of the DTrace program itself (ECB descriptions, action  * descriptions, and DIFOs) permits activities such as relocation processing  * to occur in a single pass without having to understand D program structure.  *  * Finally, strings are always stored in ELF-style string tables along with a  * string table section index and string table offset.  Therefore strings in  * DOF are always arbitrary-length and not bound to the current implementation.  */
define|#
directive|define
name|DOF_ID_SIZE
value|16
comment|/* total size of dofh_ident[] in bytes */
typedef|typedef
struct|struct
name|dof_hdr
block|{
name|uint8_t
name|dofh_ident
index|[
name|DOF_ID_SIZE
index|]
decl_stmt|;
comment|/* identification bytes (see below) */
name|uint32_t
name|dofh_flags
decl_stmt|;
comment|/* file attribute flags (if any) */
name|uint32_t
name|dofh_hdrsize
decl_stmt|;
comment|/* size of file header in bytes */
name|uint32_t
name|dofh_secsize
decl_stmt|;
comment|/* size of section header in bytes */
name|uint32_t
name|dofh_secnum
decl_stmt|;
comment|/* number of section headers */
name|uint64_t
name|dofh_secoff
decl_stmt|;
comment|/* file offset of section headers */
name|uint64_t
name|dofh_loadsz
decl_stmt|;
comment|/* file size of loadable portion */
name|uint64_t
name|dofh_filesz
decl_stmt|;
comment|/* file size of entire DOF file */
name|uint64_t
name|dofh_pad
decl_stmt|;
comment|/* reserved for future use */
block|}
name|dof_hdr_t
typedef|;
define|#
directive|define
name|DOF_ID_MAG0
value|0
comment|/* first byte of magic number */
define|#
directive|define
name|DOF_ID_MAG1
value|1
comment|/* second byte of magic number */
define|#
directive|define
name|DOF_ID_MAG2
value|2
comment|/* third byte of magic number */
define|#
directive|define
name|DOF_ID_MAG3
value|3
comment|/* fourth byte of magic number */
define|#
directive|define
name|DOF_ID_MODEL
value|4
comment|/* DOF data model (see below) */
define|#
directive|define
name|DOF_ID_ENCODING
value|5
comment|/* DOF data encoding (see below) */
define|#
directive|define
name|DOF_ID_VERSION
value|6
comment|/* DOF file format major version (see below) */
define|#
directive|define
name|DOF_ID_DIFVERS
value|7
comment|/* DIF instruction set version */
define|#
directive|define
name|DOF_ID_DIFIREG
value|8
comment|/* DIF integer registers used by compiler */
define|#
directive|define
name|DOF_ID_DIFTREG
value|9
comment|/* DIF tuple registers used by compiler */
define|#
directive|define
name|DOF_ID_PAD
value|10
comment|/* start of padding bytes (all zeroes) */
define|#
directive|define
name|DOF_MAG_MAG0
value|0x7F
comment|/* DOF_ID_MAG[0-3] */
define|#
directive|define
name|DOF_MAG_MAG1
value|'D'
define|#
directive|define
name|DOF_MAG_MAG2
value|'O'
define|#
directive|define
name|DOF_MAG_MAG3
value|'F'
define|#
directive|define
name|DOF_MAG_STRING
value|"\177DOF"
define|#
directive|define
name|DOF_MAG_STRLEN
value|4
define|#
directive|define
name|DOF_MODEL_NONE
value|0
comment|/* DOF_ID_MODEL */
define|#
directive|define
name|DOF_MODEL_ILP32
value|1
define|#
directive|define
name|DOF_MODEL_LP64
value|2
ifdef|#
directive|ifdef
name|_LP64
define|#
directive|define
name|DOF_MODEL_NATIVE
value|DOF_MODEL_LP64
else|#
directive|else
define|#
directive|define
name|DOF_MODEL_NATIVE
value|DOF_MODEL_ILP32
endif|#
directive|endif
define|#
directive|define
name|DOF_ENCODE_NONE
value|0
comment|/* DOF_ID_ENCODING */
define|#
directive|define
name|DOF_ENCODE_LSB
value|1
define|#
directive|define
name|DOF_ENCODE_MSB
value|2
if|#
directive|if
name|BYTE_ORDER
operator|==
name|_BIG_ENDIAN
define|#
directive|define
name|DOF_ENCODE_NATIVE
value|DOF_ENCODE_MSB
else|#
directive|else
define|#
directive|define
name|DOF_ENCODE_NATIVE
value|DOF_ENCODE_LSB
endif|#
directive|endif
define|#
directive|define
name|DOF_VERSION_1
value|1
comment|/* DOF version 1: Solaris 10 FCS */
define|#
directive|define
name|DOF_VERSION_2
value|2
comment|/* DOF version 2: Solaris Express 6/06 */
define|#
directive|define
name|DOF_VERSION
value|DOF_VERSION_2
comment|/* Latest DOF version */
define|#
directive|define
name|DOF_FL_VALID
value|0
comment|/* mask of all valid dofh_flags bits */
typedef|typedef
name|uint32_t
name|dof_secidx_t
typedef|;
comment|/* section header table index type */
typedef|typedef
name|uint32_t
name|dof_stridx_t
typedef|;
comment|/* string table index type */
define|#
directive|define
name|DOF_SECIDX_NONE
value|(-1U)
comment|/* null value for section indices */
define|#
directive|define
name|DOF_STRIDX_NONE
value|(-1U)
comment|/* null value for string indices */
typedef|typedef
struct|struct
name|dof_sec
block|{
name|uint32_t
name|dofs_type
decl_stmt|;
comment|/* section type (see below) */
name|uint32_t
name|dofs_align
decl_stmt|;
comment|/* section data memory alignment */
name|uint32_t
name|dofs_flags
decl_stmt|;
comment|/* section flags (if any) */
name|uint32_t
name|dofs_entsize
decl_stmt|;
comment|/* size of section entry (if table) */
name|uint64_t
name|dofs_offset
decl_stmt|;
comment|/* offset of section data within file */
name|uint64_t
name|dofs_size
decl_stmt|;
comment|/* size of section data in bytes */
block|}
name|dof_sec_t
typedef|;
define|#
directive|define
name|DOF_SECT_NONE
value|0
comment|/* null section */
define|#
directive|define
name|DOF_SECT_COMMENTS
value|1
comment|/* compiler comments */
define|#
directive|define
name|DOF_SECT_SOURCE
value|2
comment|/* D program source code */
define|#
directive|define
name|DOF_SECT_ECBDESC
value|3
comment|/* dof_ecbdesc_t */
define|#
directive|define
name|DOF_SECT_PROBEDESC
value|4
comment|/* dof_probedesc_t */
define|#
directive|define
name|DOF_SECT_ACTDESC
value|5
comment|/* dof_actdesc_t array */
define|#
directive|define
name|DOF_SECT_DIFOHDR
value|6
comment|/* dof_difohdr_t (variable length) */
define|#
directive|define
name|DOF_SECT_DIF
value|7
comment|/* uint32_t array of byte code */
define|#
directive|define
name|DOF_SECT_STRTAB
value|8
comment|/* string table */
define|#
directive|define
name|DOF_SECT_VARTAB
value|9
comment|/* dtrace_difv_t array */
define|#
directive|define
name|DOF_SECT_RELTAB
value|10
comment|/* dof_relodesc_t array */
define|#
directive|define
name|DOF_SECT_TYPTAB
value|11
comment|/* dtrace_diftype_t array */
define|#
directive|define
name|DOF_SECT_URELHDR
value|12
comment|/* dof_relohdr_t (user relocations) */
define|#
directive|define
name|DOF_SECT_KRELHDR
value|13
comment|/* dof_relohdr_t (kernel relocations) */
define|#
directive|define
name|DOF_SECT_OPTDESC
value|14
comment|/* dof_optdesc_t array */
define|#
directive|define
name|DOF_SECT_PROVIDER
value|15
comment|/* dof_provider_t */
define|#
directive|define
name|DOF_SECT_PROBES
value|16
comment|/* dof_probe_t array */
define|#
directive|define
name|DOF_SECT_PRARGS
value|17
comment|/* uint8_t array (probe arg mappings) */
define|#
directive|define
name|DOF_SECT_PROFFS
value|18
comment|/* uint32_t array (probe arg offsets) */
define|#
directive|define
name|DOF_SECT_INTTAB
value|19
comment|/* uint64_t array */
define|#
directive|define
name|DOF_SECT_UTSNAME
value|20
comment|/* struct utsname */
define|#
directive|define
name|DOF_SECT_XLTAB
value|21
comment|/* dof_xlref_t array */
define|#
directive|define
name|DOF_SECT_XLMEMBERS
value|22
comment|/* dof_xlmember_t array */
define|#
directive|define
name|DOF_SECT_XLIMPORT
value|23
comment|/* dof_xlator_t */
define|#
directive|define
name|DOF_SECT_XLEXPORT
value|24
comment|/* dof_xlator_t */
define|#
directive|define
name|DOF_SECT_PREXPORT
value|25
comment|/* dof_secidx_t array (exported objs) */
define|#
directive|define
name|DOF_SECT_PRENOFFS
value|26
comment|/* uint32_t array (enabled offsets) */
define|#
directive|define
name|DOF_SECF_LOAD
value|1
comment|/* section should be loaded */
define|#
directive|define
name|DOF_SEC_ISLOADABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x) == DOF_SECT_ECBDESC) || ((x) == DOF_SECT_PROBEDESC) ||	\ 	((x) == DOF_SECT_ACTDESC) || ((x) == DOF_SECT_DIFOHDR) ||	\ 	((x) == DOF_SECT_DIF) || ((x) == DOF_SECT_STRTAB) ||		\ 	((x) == DOF_SECT_VARTAB) || ((x) == DOF_SECT_RELTAB) ||		\ 	((x) == DOF_SECT_TYPTAB) || ((x) == DOF_SECT_URELHDR) ||	\ 	((x) == DOF_SECT_KRELHDR) || ((x) == DOF_SECT_OPTDESC) ||	\ 	((x) == DOF_SECT_PROVIDER) || ((x) == DOF_SECT_PROBES) ||	\ 	((x) == DOF_SECT_PRARGS) || ((x) == DOF_SECT_PROFFS) ||		\ 	((x) == DOF_SECT_INTTAB) || ((x) == DOF_SECT_XLTAB) ||		\ 	((x) == DOF_SECT_XLMEMBERS) || ((x) == DOF_SECT_XLIMPORT) ||	\ 	((x) == DOF_SECT_XLEXPORT) ||  ((x) == DOF_SECT_PREXPORT) || 	\ 	((x) == DOF_SECT_PRENOFFS))
typedef|typedef
struct|struct
name|dof_ecbdesc
block|{
name|dof_secidx_t
name|dofe_probes
decl_stmt|;
comment|/* link to DOF_SECT_PROBEDESC */
name|dof_secidx_t
name|dofe_pred
decl_stmt|;
comment|/* link to DOF_SECT_DIFOHDR */
name|dof_secidx_t
name|dofe_actions
decl_stmt|;
comment|/* link to DOF_SECT_ACTDESC */
name|uint32_t
name|dofe_pad
decl_stmt|;
comment|/* reserved for future use */
name|uint64_t
name|dofe_uarg
decl_stmt|;
comment|/* user-supplied library argument */
block|}
name|dof_ecbdesc_t
typedef|;
typedef|typedef
struct|struct
name|dof_probedesc
block|{
name|dof_secidx_t
name|dofp_strtab
decl_stmt|;
comment|/* link to DOF_SECT_STRTAB section */
name|dof_stridx_t
name|dofp_provider
decl_stmt|;
comment|/* provider string */
name|dof_stridx_t
name|dofp_mod
decl_stmt|;
comment|/* module string */
name|dof_stridx_t
name|dofp_func
decl_stmt|;
comment|/* function string */
name|dof_stridx_t
name|dofp_name
decl_stmt|;
comment|/* name string */
name|uint32_t
name|dofp_id
decl_stmt|;
comment|/* probe identifier (or zero) */
block|}
name|dof_probedesc_t
typedef|;
typedef|typedef
struct|struct
name|dof_actdesc
block|{
name|dof_secidx_t
name|dofa_difo
decl_stmt|;
comment|/* link to DOF_SECT_DIFOHDR */
name|dof_secidx_t
name|dofa_strtab
decl_stmt|;
comment|/* link to DOF_SECT_STRTAB section */
name|uint32_t
name|dofa_kind
decl_stmt|;
comment|/* action kind (DTRACEACT_* constant) */
name|uint32_t
name|dofa_ntuple
decl_stmt|;
comment|/* number of subsequent tuple actions */
name|uint64_t
name|dofa_arg
decl_stmt|;
comment|/* kind-specific argument */
name|uint64_t
name|dofa_uarg
decl_stmt|;
comment|/* user-supplied argument */
block|}
name|dof_actdesc_t
typedef|;
typedef|typedef
struct|struct
name|dof_difohdr
block|{
name|dtrace_diftype_t
name|dofd_rtype
decl_stmt|;
comment|/* return type for this fragment */
name|dof_secidx_t
name|dofd_links
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable length array of indices */
block|}
name|dof_difohdr_t
typedef|;
typedef|typedef
struct|struct
name|dof_relohdr
block|{
name|dof_secidx_t
name|dofr_strtab
decl_stmt|;
comment|/* link to DOF_SECT_STRTAB for names */
name|dof_secidx_t
name|dofr_relsec
decl_stmt|;
comment|/* link to DOF_SECT_RELTAB for relos */
name|dof_secidx_t
name|dofr_tgtsec
decl_stmt|;
comment|/* link to section we are relocating */
block|}
name|dof_relohdr_t
typedef|;
typedef|typedef
struct|struct
name|dof_relodesc
block|{
name|dof_stridx_t
name|dofr_name
decl_stmt|;
comment|/* string name of relocation symbol */
name|uint32_t
name|dofr_type
decl_stmt|;
comment|/* relo type (DOF_RELO_* constant) */
name|uint64_t
name|dofr_offset
decl_stmt|;
comment|/* byte offset for relocation */
name|uint64_t
name|dofr_data
decl_stmt|;
comment|/* additional type-specific data */
block|}
name|dof_relodesc_t
typedef|;
define|#
directive|define
name|DOF_RELO_NONE
value|0
comment|/* empty relocation entry */
define|#
directive|define
name|DOF_RELO_SETX
value|1
comment|/* relocate setx value */
define|#
directive|define
name|DOF_RELO_DOFREL
value|2
comment|/* relocate DOF-relative value */
typedef|typedef
struct|struct
name|dof_optdesc
block|{
name|uint32_t
name|dofo_option
decl_stmt|;
comment|/* option identifier */
name|dof_secidx_t
name|dofo_strtab
decl_stmt|;
comment|/* string table, if string option */
name|uint64_t
name|dofo_value
decl_stmt|;
comment|/* option value or string index */
block|}
name|dof_optdesc_t
typedef|;
typedef|typedef
name|uint32_t
name|dof_attr_t
typedef|;
comment|/* encoded stability attributes */
define|#
directive|define
name|DOF_ATTR
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|(((n)<< 24) | ((d)<< 16) | ((c)<< 8))
define|#
directive|define
name|DOF_ATTR_NAME
parameter_list|(
name|a
parameter_list|)
value|(((a)>> 24)& 0xff)
define|#
directive|define
name|DOF_ATTR_DATA
parameter_list|(
name|a
parameter_list|)
value|(((a)>> 16)& 0xff)
define|#
directive|define
name|DOF_ATTR_CLASS
parameter_list|(
name|a
parameter_list|)
value|(((a)>>  8)& 0xff)
typedef|typedef
struct|struct
name|dof_provider
block|{
name|dof_secidx_t
name|dofpv_strtab
decl_stmt|;
comment|/* link to DOF_SECT_STRTAB section */
name|dof_secidx_t
name|dofpv_probes
decl_stmt|;
comment|/* link to DOF_SECT_PROBES section */
name|dof_secidx_t
name|dofpv_prargs
decl_stmt|;
comment|/* link to DOF_SECT_PRARGS section */
name|dof_secidx_t
name|dofpv_proffs
decl_stmt|;
comment|/* link to DOF_SECT_PROFFS section */
name|dof_stridx_t
name|dofpv_name
decl_stmt|;
comment|/* provider name string */
name|dof_attr_t
name|dofpv_provattr
decl_stmt|;
comment|/* provider attributes */
name|dof_attr_t
name|dofpv_modattr
decl_stmt|;
comment|/* module attributes */
name|dof_attr_t
name|dofpv_funcattr
decl_stmt|;
comment|/* function attributes */
name|dof_attr_t
name|dofpv_nameattr
decl_stmt|;
comment|/* name attributes */
name|dof_attr_t
name|dofpv_argsattr
decl_stmt|;
comment|/* args attributes */
name|dof_secidx_t
name|dofpv_prenoffs
decl_stmt|;
comment|/* link to DOF_SECT_PRENOFFS section */
block|}
name|dof_provider_t
typedef|;
typedef|typedef
struct|struct
name|dof_probe
block|{
name|uint64_t
name|dofpr_addr
decl_stmt|;
comment|/* probe base address or offset */
name|dof_stridx_t
name|dofpr_func
decl_stmt|;
comment|/* probe function string */
name|dof_stridx_t
name|dofpr_name
decl_stmt|;
comment|/* probe name string */
name|dof_stridx_t
name|dofpr_nargv
decl_stmt|;
comment|/* native argument type strings */
name|dof_stridx_t
name|dofpr_xargv
decl_stmt|;
comment|/* translated argument type strings */
name|uint32_t
name|dofpr_argidx
decl_stmt|;
comment|/* index of first argument mapping */
name|uint32_t
name|dofpr_offidx
decl_stmt|;
comment|/* index of first offset entry */
name|uint8_t
name|dofpr_nargc
decl_stmt|;
comment|/* native argument count */
name|uint8_t
name|dofpr_xargc
decl_stmt|;
comment|/* translated argument count */
name|uint16_t
name|dofpr_noffs
decl_stmt|;
comment|/* number of offset entries for probe */
name|uint32_t
name|dofpr_enoffidx
decl_stmt|;
comment|/* index of first is-enabled offset */
name|uint16_t
name|dofpr_nenoffs
decl_stmt|;
comment|/* number of is-enabled offsets */
name|uint16_t
name|dofpr_pad1
decl_stmt|;
comment|/* reserved for future use */
name|uint32_t
name|dofpr_pad2
decl_stmt|;
comment|/* reserved for future use */
block|}
name|dof_probe_t
typedef|;
typedef|typedef
struct|struct
name|dof_xlator
block|{
name|dof_secidx_t
name|dofxl_members
decl_stmt|;
comment|/* link to DOF_SECT_XLMEMBERS section */
name|dof_secidx_t
name|dofxl_strtab
decl_stmt|;
comment|/* link to DOF_SECT_STRTAB section */
name|dof_stridx_t
name|dofxl_argv
decl_stmt|;
comment|/* input parameter type strings */
name|uint32_t
name|dofxl_argc
decl_stmt|;
comment|/* input parameter list length */
name|dof_stridx_t
name|dofxl_type
decl_stmt|;
comment|/* output type string name */
name|dof_attr_t
name|dofxl_attr
decl_stmt|;
comment|/* output stability attributes */
block|}
name|dof_xlator_t
typedef|;
typedef|typedef
struct|struct
name|dof_xlmember
block|{
name|dof_secidx_t
name|dofxm_difo
decl_stmt|;
comment|/* member link to DOF_SECT_DIFOHDR */
name|dof_stridx_t
name|dofxm_name
decl_stmt|;
comment|/* member name */
name|dtrace_diftype_t
name|dofxm_type
decl_stmt|;
comment|/* member type */
block|}
name|dof_xlmember_t
typedef|;
typedef|typedef
struct|struct
name|dof_xlref
block|{
name|dof_secidx_t
name|dofxr_xlator
decl_stmt|;
comment|/* link to DOF_SECT_XLATORS section */
name|uint32_t
name|dofxr_member
decl_stmt|;
comment|/* index of referenced dof_xlmember */
name|uint32_t
name|dofxr_argn
decl_stmt|;
comment|/* index of argument for DIF_OP_XLARG */
block|}
name|dof_xlref_t
typedef|;
comment|/*  * DTrace Intermediate Format Object (DIFO)  *  * A DIFO is used to store the compiled DIF for a D expression, its return  * type, and its string and variable tables.  The string table is a single  * buffer of character data into which sets instructions and variable  * references can reference strings using a byte offset.  The variable table  * is an array of dtrace_difv_t structures that describe the name and type of  * each variable and the id used in the DIF code.  This structure is described  * above in the DIF section of this header file.  The DIFO is used at both  * user-level (in the library) and in the kernel, but the structure is never  * passed between the two: the DOF structures form the only interface.  As a  * result, the definition can change depending on the presence of _KERNEL.  */
typedef|typedef
struct|struct
name|dtrace_difo
block|{
name|dif_instr_t
modifier|*
name|dtdo_buf
decl_stmt|;
comment|/* instruction buffer */
name|uint64_t
modifier|*
name|dtdo_inttab
decl_stmt|;
comment|/* integer table (optional) */
name|char
modifier|*
name|dtdo_strtab
decl_stmt|;
comment|/* string table (optional) */
name|dtrace_difv_t
modifier|*
name|dtdo_vartab
decl_stmt|;
comment|/* variable table (optional) */
name|uint_t
name|dtdo_len
decl_stmt|;
comment|/* length of instruction buffer */
name|uint_t
name|dtdo_intlen
decl_stmt|;
comment|/* length of integer table */
name|uint_t
name|dtdo_strlen
decl_stmt|;
comment|/* length of string table */
name|uint_t
name|dtdo_varlen
decl_stmt|;
comment|/* length of variable table */
name|dtrace_diftype_t
name|dtdo_rtype
decl_stmt|;
comment|/* return type */
name|uint_t
name|dtdo_refcnt
decl_stmt|;
comment|/* owner reference count */
name|uint_t
name|dtdo_destructive
decl_stmt|;
comment|/* invokes destructive subroutines */
ifndef|#
directive|ifndef
name|_KERNEL
name|dof_relodesc_t
modifier|*
name|dtdo_kreltab
decl_stmt|;
comment|/* kernel relocations */
name|dof_relodesc_t
modifier|*
name|dtdo_ureltab
decl_stmt|;
comment|/* user relocations */
name|struct
name|dt_node
modifier|*
modifier|*
name|dtdo_xlmtab
decl_stmt|;
comment|/* translator references */
name|uint_t
name|dtdo_krelen
decl_stmt|;
comment|/* length of krelo table */
name|uint_t
name|dtdo_urelen
decl_stmt|;
comment|/* length of urelo table */
name|uint_t
name|dtdo_xlmlen
decl_stmt|;
comment|/* length of translator table */
endif|#
directive|endif
block|}
name|dtrace_difo_t
typedef|;
comment|/*  * DTrace Enabling Description Structures  *  * When DTrace is tracking the description of a DTrace enabling entity (probe,  * predicate, action, ECB, record, etc.), it does so in a description  * structure.  These structures all end in "desc", and are used at both  * user-level and in the kernel -- but (with the exception of  * dtrace_probedesc_t) they are never passed between them.  Typically,  * user-level will use the description structures when assembling an enabling.  * It will then distill those description structures into a DOF object (see  * above), and send it into the kernel.  The kernel will again use the  * description structures to create a description of the enabling as it reads  * the DOF.  When the description is complete, the enabling will be actually  * created -- turning it into the structures that represent the enabling  * instead of merely describing it.  Not surprisingly, the description  * structures bear a strong resemblance to the DOF structures that act as their  * conduit.  */
struct_decl|struct
name|dtrace_predicate
struct_decl|;
typedef|typedef
struct|struct
name|dtrace_probedesc
block|{
name|dtrace_id_t
name|dtpd_id
decl_stmt|;
comment|/* probe identifier */
name|char
name|dtpd_provider
index|[
name|DTRACE_PROVNAMELEN
index|]
decl_stmt|;
comment|/* probe provider name */
name|char
name|dtpd_mod
index|[
name|DTRACE_MODNAMELEN
index|]
decl_stmt|;
comment|/* probe module name */
name|char
name|dtpd_func
index|[
name|DTRACE_FUNCNAMELEN
index|]
decl_stmt|;
comment|/* probe function name */
name|char
name|dtpd_name
index|[
name|DTRACE_NAMELEN
index|]
decl_stmt|;
comment|/* probe name */
block|}
name|dtrace_probedesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_repldesc
block|{
name|dtrace_probedesc_t
name|dtrpd_match
decl_stmt|;
comment|/* probe descr. to match */
name|dtrace_probedesc_t
name|dtrpd_create
decl_stmt|;
comment|/* probe descr. to create */
block|}
name|dtrace_repldesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_preddesc
block|{
name|dtrace_difo_t
modifier|*
name|dtpdd_difo
decl_stmt|;
comment|/* pointer to DIF object */
name|struct
name|dtrace_predicate
modifier|*
name|dtpdd_predicate
decl_stmt|;
comment|/* pointer to predicate */
block|}
name|dtrace_preddesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_actdesc
block|{
name|dtrace_difo_t
modifier|*
name|dtad_difo
decl_stmt|;
comment|/* pointer to DIF object */
name|struct
name|dtrace_actdesc
modifier|*
name|dtad_next
decl_stmt|;
comment|/* next action */
name|dtrace_actkind_t
name|dtad_kind
decl_stmt|;
comment|/* kind of action */
name|uint32_t
name|dtad_ntuple
decl_stmt|;
comment|/* number in tuple */
name|uint64_t
name|dtad_arg
decl_stmt|;
comment|/* action argument */
name|uint64_t
name|dtad_uarg
decl_stmt|;
comment|/* user argument */
name|int
name|dtad_refcnt
decl_stmt|;
comment|/* reference count */
block|}
name|dtrace_actdesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_ecbdesc
block|{
name|dtrace_actdesc_t
modifier|*
name|dted_action
decl_stmt|;
comment|/* action description(s) */
name|dtrace_preddesc_t
name|dted_pred
decl_stmt|;
comment|/* predicate description */
name|dtrace_probedesc_t
name|dted_probe
decl_stmt|;
comment|/* probe description */
name|uint64_t
name|dted_uarg
decl_stmt|;
comment|/* library argument */
name|int
name|dted_refcnt
decl_stmt|;
comment|/* reference count */
block|}
name|dtrace_ecbdesc_t
typedef|;
comment|/*  * DTrace Metadata Description Structures  *  * DTrace separates the trace data stream from the metadata stream.  The only  * metadata tokens placed in the data stream are the dtrace_rechdr_t (EPID +  * timestamp) or (in the case of aggregations) aggregation identifiers.  To  * determine the structure of the data, DTrace consumers pass the token to the  * kernel, and receive in return a corresponding description of the enabled  * probe (via the dtrace_eprobedesc structure) or the aggregation (via the  * dtrace_aggdesc structure).  Both of these structures are expressed in terms  * of record descriptions (via the dtrace_recdesc structure) that describe the  * exact structure of the data.  Some record descriptions may also contain a  * format identifier; this additional bit of metadata can be retrieved from the  * kernel, for which a format description is returned via the dtrace_fmtdesc  * structure.  Note that all four of these structures must be bitness-neutral  * to allow for a 32-bit DTrace consumer on a 64-bit kernel.  */
typedef|typedef
struct|struct
name|dtrace_recdesc
block|{
name|dtrace_actkind_t
name|dtrd_action
decl_stmt|;
comment|/* kind of action */
name|uint32_t
name|dtrd_size
decl_stmt|;
comment|/* size of record */
name|uint32_t
name|dtrd_offset
decl_stmt|;
comment|/* offset in ECB's data */
name|uint16_t
name|dtrd_alignment
decl_stmt|;
comment|/* required alignment */
name|uint16_t
name|dtrd_format
decl_stmt|;
comment|/* format, if any */
name|uint64_t
name|dtrd_arg
decl_stmt|;
comment|/* action argument */
name|uint64_t
name|dtrd_uarg
decl_stmt|;
comment|/* user argument */
block|}
name|dtrace_recdesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_eprobedesc
block|{
name|dtrace_epid_t
name|dtepd_epid
decl_stmt|;
comment|/* enabled probe ID */
name|dtrace_id_t
name|dtepd_probeid
decl_stmt|;
comment|/* probe ID */
name|uint64_t
name|dtepd_uarg
decl_stmt|;
comment|/* library argument */
name|uint32_t
name|dtepd_size
decl_stmt|;
comment|/* total size */
name|int
name|dtepd_nrecs
decl_stmt|;
comment|/* number of records */
name|dtrace_recdesc_t
name|dtepd_rec
index|[
literal|1
index|]
decl_stmt|;
comment|/* records themselves */
block|}
name|dtrace_eprobedesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_aggdesc
block|{
name|DTRACE_PTR
argument_list|(
name|char
argument_list|,
name|dtagd_name
argument_list|)
expr_stmt|;
comment|/* not filled in by kernel */
name|dtrace_aggvarid_t
name|dtagd_varid
decl_stmt|;
comment|/* not filled in by kernel */
name|int
name|dtagd_flags
decl_stmt|;
comment|/* not filled in by kernel */
name|dtrace_aggid_t
name|dtagd_id
decl_stmt|;
comment|/* aggregation ID */
name|dtrace_epid_t
name|dtagd_epid
decl_stmt|;
comment|/* enabled probe ID */
name|uint32_t
name|dtagd_size
decl_stmt|;
comment|/* size in bytes */
name|int
name|dtagd_nrecs
decl_stmt|;
comment|/* number of records */
name|uint32_t
name|dtagd_pad
decl_stmt|;
comment|/* explicit padding */
name|dtrace_recdesc_t
name|dtagd_rec
index|[
literal|1
index|]
decl_stmt|;
comment|/* record descriptions */
block|}
name|dtrace_aggdesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_fmtdesc
block|{
name|DTRACE_PTR
argument_list|(
name|char
argument_list|,
name|dtfd_string
argument_list|)
expr_stmt|;
comment|/* format string */
name|int
name|dtfd_length
decl_stmt|;
comment|/* length of format string */
name|uint16_t
name|dtfd_format
decl_stmt|;
comment|/* format identifier */
block|}
name|dtrace_fmtdesc_t
typedef|;
define|#
directive|define
name|DTRACE_SIZEOF_EPROBEDESC
parameter_list|(
name|desc
parameter_list|)
define|\
value|(sizeof (dtrace_eprobedesc_t) + ((desc)->dtepd_nrecs ?	\ 	(((desc)->dtepd_nrecs - 1) * sizeof (dtrace_recdesc_t)) : 0))
define|#
directive|define
name|DTRACE_SIZEOF_AGGDESC
parameter_list|(
name|desc
parameter_list|)
define|\
value|(sizeof (dtrace_aggdesc_t) + ((desc)->dtagd_nrecs ?	\ 	(((desc)->dtagd_nrecs - 1) * sizeof (dtrace_recdesc_t)) : 0))
comment|/*  * DTrace Option Interface  *  * Run-time DTrace options are set and retrieved via DOF_SECT_OPTDESC sections  * in a DOF image.  The dof_optdesc structure contains an option identifier and  * an option value.  The valid option identifiers are found below; the mapping  * between option identifiers and option identifying strings is maintained at  * user-level.  Note that the value of DTRACEOPT_UNSET is such that all of the  * following are potentially valid option values:  all positive integers, zero  * and negative one.  Some options (notably "bufpolicy" and "bufresize") take  * predefined tokens as their values; these are defined with  * DTRACEOPT_{option}_{token}.  */
define|#
directive|define
name|DTRACEOPT_BUFSIZE
value|0
comment|/* buffer size */
define|#
directive|define
name|DTRACEOPT_BUFPOLICY
value|1
comment|/* buffer policy */
define|#
directive|define
name|DTRACEOPT_DYNVARSIZE
value|2
comment|/* dynamic variable size */
define|#
directive|define
name|DTRACEOPT_AGGSIZE
value|3
comment|/* aggregation size */
define|#
directive|define
name|DTRACEOPT_SPECSIZE
value|4
comment|/* speculation size */
define|#
directive|define
name|DTRACEOPT_NSPEC
value|5
comment|/* number of speculations */
define|#
directive|define
name|DTRACEOPT_STRSIZE
value|6
comment|/* string size */
define|#
directive|define
name|DTRACEOPT_CLEANRATE
value|7
comment|/* dynvar cleaning rate */
define|#
directive|define
name|DTRACEOPT_CPU
value|8
comment|/* CPU to trace */
define|#
directive|define
name|DTRACEOPT_BUFRESIZE
value|9
comment|/* buffer resizing policy */
define|#
directive|define
name|DTRACEOPT_GRABANON
value|10
comment|/* grab anonymous state, if any */
define|#
directive|define
name|DTRACEOPT_FLOWINDENT
value|11
comment|/* indent function entry/return */
define|#
directive|define
name|DTRACEOPT_QUIET
value|12
comment|/* only output explicitly traced data */
define|#
directive|define
name|DTRACEOPT_STACKFRAMES
value|13
comment|/* number of stack frames */
define|#
directive|define
name|DTRACEOPT_USTACKFRAMES
value|14
comment|/* number of user stack frames */
define|#
directive|define
name|DTRACEOPT_AGGRATE
value|15
comment|/* aggregation snapshot rate */
define|#
directive|define
name|DTRACEOPT_SWITCHRATE
value|16
comment|/* buffer switching rate */
define|#
directive|define
name|DTRACEOPT_STATUSRATE
value|17
comment|/* status rate */
define|#
directive|define
name|DTRACEOPT_DESTRUCTIVE
value|18
comment|/* destructive actions allowed */
define|#
directive|define
name|DTRACEOPT_STACKINDENT
value|19
comment|/* output indent for stack traces */
define|#
directive|define
name|DTRACEOPT_RAWBYTES
value|20
comment|/* always print bytes in raw form */
define|#
directive|define
name|DTRACEOPT_JSTACKFRAMES
value|21
comment|/* number of jstack() frames */
define|#
directive|define
name|DTRACEOPT_JSTACKSTRSIZE
value|22
comment|/* size of jstack() string table */
define|#
directive|define
name|DTRACEOPT_AGGSORTKEY
value|23
comment|/* sort aggregations by key */
define|#
directive|define
name|DTRACEOPT_AGGSORTREV
value|24
comment|/* reverse-sort aggregations */
define|#
directive|define
name|DTRACEOPT_AGGSORTPOS
value|25
comment|/* agg. position to sort on */
define|#
directive|define
name|DTRACEOPT_AGGSORTKEYPOS
value|26
comment|/* agg. key position to sort on */
define|#
directive|define
name|DTRACEOPT_TEMPORAL
value|27
comment|/* temporally ordered output */
define|#
directive|define
name|DTRACEOPT_AGGHIST
value|28
comment|/* histogram aggregation output */
define|#
directive|define
name|DTRACEOPT_AGGPACK
value|29
comment|/* packed aggregation output */
define|#
directive|define
name|DTRACEOPT_AGGZOOM
value|30
comment|/* zoomed aggregation scaling */
define|#
directive|define
name|DTRACEOPT_ZONE
value|31
comment|/* zone in which to enable probes */
define|#
directive|define
name|DTRACEOPT_MAX
value|32
comment|/* number of options */
define|#
directive|define
name|DTRACEOPT_UNSET
value|(dtrace_optval_t)-2
comment|/* unset option */
define|#
directive|define
name|DTRACEOPT_BUFPOLICY_RING
value|0
comment|/* ring buffer */
define|#
directive|define
name|DTRACEOPT_BUFPOLICY_FILL
value|1
comment|/* fill buffer, then stop */
define|#
directive|define
name|DTRACEOPT_BUFPOLICY_SWITCH
value|2
comment|/* switch buffers */
define|#
directive|define
name|DTRACEOPT_BUFRESIZE_AUTO
value|0
comment|/* automatic resizing */
define|#
directive|define
name|DTRACEOPT_BUFRESIZE_MANUAL
value|1
comment|/* manual resizing */
comment|/*  * DTrace Buffer Interface  *  * In order to get a snapshot of the principal or aggregation buffer,  * user-level passes a buffer description to the kernel with the dtrace_bufdesc  * structure.  This describes which CPU user-level is interested in, and  * where user-level wishes the kernel to snapshot the buffer to (the  * dtbd_data field).  The kernel uses the same structure to pass back some  * information regarding the buffer:  the size of data actually copied out, the  * number of drops, the number of errors, the offset of the oldest record,  * and the time of the snapshot.  *  * If the buffer policy is a "switch" policy, taking a snapshot of the  * principal buffer has the additional effect of switching the active and  * inactive buffers.  Taking a snapshot of the aggregation buffer _always_ has  * the additional effect of switching the active and inactive buffers.  */
typedef|typedef
struct|struct
name|dtrace_bufdesc
block|{
name|uint64_t
name|dtbd_size
decl_stmt|;
comment|/* size of buffer */
name|uint32_t
name|dtbd_cpu
decl_stmt|;
comment|/* CPU or DTRACE_CPUALL */
name|uint32_t
name|dtbd_errors
decl_stmt|;
comment|/* number of errors */
name|uint64_t
name|dtbd_drops
decl_stmt|;
comment|/* number of drops */
name|DTRACE_PTR
argument_list|(
name|char
argument_list|,
name|dtbd_data
argument_list|)
expr_stmt|;
comment|/* data */
name|uint64_t
name|dtbd_oldest
decl_stmt|;
comment|/* offset of oldest record */
name|uint64_t
name|dtbd_timestamp
decl_stmt|;
comment|/* hrtime of snapshot */
block|}
name|dtrace_bufdesc_t
typedef|;
comment|/*  * Each record in the buffer (dtbd_data) begins with a header that includes  * the epid and a timestamp.  The timestamp is split into two 4-byte parts  * so that we do not require 8-byte alignment.  */
typedef|typedef
struct|struct
name|dtrace_rechdr
block|{
name|dtrace_epid_t
name|dtrh_epid
decl_stmt|;
comment|/* enabled probe id */
name|uint32_t
name|dtrh_timestamp_hi
decl_stmt|;
comment|/* high bits of hrtime_t */
name|uint32_t
name|dtrh_timestamp_lo
decl_stmt|;
comment|/* low bits of hrtime_t */
block|}
name|dtrace_rechdr_t
typedef|;
define|#
directive|define
name|DTRACE_RECORD_LOAD_TIMESTAMP
parameter_list|(
name|dtrh
parameter_list|)
define|\
value|((dtrh)->dtrh_timestamp_lo +				\ 	((uint64_t)(dtrh)->dtrh_timestamp_hi<< 32))
define|#
directive|define
name|DTRACE_RECORD_STORE_TIMESTAMP
parameter_list|(
name|dtrh
parameter_list|,
name|hrtime
parameter_list|)
value|{		\ 	(dtrh)->dtrh_timestamp_lo = (uint32_t)hrtime;		\ 	(dtrh)->dtrh_timestamp_hi = hrtime>> 32;		\ }
comment|/*  * DTrace Status  *  * The status of DTrace is relayed via the dtrace_status structure.  This  * structure contains members to count drops other than the capacity drops  * available via the buffer interface (see above).  This consists of dynamic  * drops (including capacity dynamic drops, rinsing drops and dirty drops), and  * speculative drops (including capacity speculative drops, drops due to busy  * speculative buffers and drops due to unavailable speculative buffers).  * Additionally, the status structure contains a field to indicate the number  * of "fill"-policy buffers have been filled and a boolean field to indicate  * that exit() has been called.  If the dtst_exiting field is non-zero, no  * further data will be generated until tracing is stopped (at which time any  * enablings of the END action will be processed); if user-level sees that  * this field is non-zero, tracing should be stopped as soon as possible.  */
typedef|typedef
struct|struct
name|dtrace_status
block|{
name|uint64_t
name|dtst_dyndrops
decl_stmt|;
comment|/* dynamic drops */
name|uint64_t
name|dtst_dyndrops_rinsing
decl_stmt|;
comment|/* dyn drops due to rinsing */
name|uint64_t
name|dtst_dyndrops_dirty
decl_stmt|;
comment|/* dyn drops due to dirty */
name|uint64_t
name|dtst_specdrops
decl_stmt|;
comment|/* speculative drops */
name|uint64_t
name|dtst_specdrops_busy
decl_stmt|;
comment|/* spec drops due to busy */
name|uint64_t
name|dtst_specdrops_unavail
decl_stmt|;
comment|/* spec drops due to unavail */
name|uint64_t
name|dtst_errors
decl_stmt|;
comment|/* total errors */
name|uint64_t
name|dtst_filled
decl_stmt|;
comment|/* number of filled bufs */
name|uint64_t
name|dtst_stkstroverflows
decl_stmt|;
comment|/* stack string tab overflows */
name|uint64_t
name|dtst_dblerrors
decl_stmt|;
comment|/* errors in ERROR probes */
name|char
name|dtst_killed
decl_stmt|;
comment|/* non-zero if killed */
name|char
name|dtst_exiting
decl_stmt|;
comment|/* non-zero if exit() called */
name|char
name|dtst_pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* pad out to 64-bit align */
block|}
name|dtrace_status_t
typedef|;
comment|/*  * DTrace Configuration  *  * User-level may need to understand some elements of the kernel DTrace  * configuration in order to generate correct DIF.  This information is  * conveyed via the dtrace_conf structure.  */
typedef|typedef
struct|struct
name|dtrace_conf
block|{
name|uint_t
name|dtc_difversion
decl_stmt|;
comment|/* supported DIF version */
name|uint_t
name|dtc_difintregs
decl_stmt|;
comment|/* # of DIF integer registers */
name|uint_t
name|dtc_diftupregs
decl_stmt|;
comment|/* # of DIF tuple registers */
name|uint_t
name|dtc_ctfmodel
decl_stmt|;
comment|/* CTF data model */
name|uint_t
name|dtc_pad
index|[
literal|8
index|]
decl_stmt|;
comment|/* reserved for future use */
block|}
name|dtrace_conf_t
typedef|;
comment|/*  * DTrace Faults  *  * The constants below DTRACEFLT_LIBRARY indicate probe processing faults;  * constants at or above DTRACEFLT_LIBRARY indicate faults in probe  * postprocessing at user-level.  Probe processing faults induce an ERROR  * probe and are replicated in unistd.d to allow users' ERROR probes to decode  * the error condition using thse symbolic labels.  */
define|#
directive|define
name|DTRACEFLT_UNKNOWN
value|0
comment|/* Unknown fault */
define|#
directive|define
name|DTRACEFLT_BADADDR
value|1
comment|/* Bad address */
define|#
directive|define
name|DTRACEFLT_BADALIGN
value|2
comment|/* Bad alignment */
define|#
directive|define
name|DTRACEFLT_ILLOP
value|3
comment|/* Illegal operation */
define|#
directive|define
name|DTRACEFLT_DIVZERO
value|4
comment|/* Divide-by-zero */
define|#
directive|define
name|DTRACEFLT_NOSCRATCH
value|5
comment|/* Out of scratch space */
define|#
directive|define
name|DTRACEFLT_KPRIV
value|6
comment|/* Illegal kernel access */
define|#
directive|define
name|DTRACEFLT_UPRIV
value|7
comment|/* Illegal user access */
define|#
directive|define
name|DTRACEFLT_TUPOFLOW
value|8
comment|/* Tuple stack overflow */
define|#
directive|define
name|DTRACEFLT_BADSTACK
value|9
comment|/* Bad stack */
define|#
directive|define
name|DTRACEFLT_LIBRARY
value|1000
comment|/* Library-level fault */
comment|/*  * DTrace Argument Types  *  * Because it would waste both space and time, argument types do not reside  * with the probe.  In order to determine argument types for args[X]  * variables, the D compiler queries for argument types on a probe-by-probe  * basis.  (This optimizes for the common case that arguments are either not  * used or used in an untyped fashion.)  Typed arguments are specified with a  * string of the type name in the dtragd_native member of the argument  * description structure.  Typed arguments may be further translated to types  * of greater stability; the provider indicates such a translated argument by  * filling in the dtargd_xlate member with the string of the translated type.  * Finally, the provider may indicate which argument value a given argument  * maps to by setting the dtargd_mapping member -- allowing a single argument  * to map to multiple args[X] variables.  */
typedef|typedef
struct|struct
name|dtrace_argdesc
block|{
name|dtrace_id_t
name|dtargd_id
decl_stmt|;
comment|/* probe identifier */
name|int
name|dtargd_ndx
decl_stmt|;
comment|/* arg number (-1 iff none) */
name|int
name|dtargd_mapping
decl_stmt|;
comment|/* value mapping */
name|char
name|dtargd_native
index|[
name|DTRACE_ARGTYPELEN
index|]
decl_stmt|;
comment|/* native type name */
name|char
name|dtargd_xlate
index|[
name|DTRACE_ARGTYPELEN
index|]
decl_stmt|;
comment|/* translated type name */
block|}
name|dtrace_argdesc_t
typedef|;
comment|/*  * DTrace Stability Attributes  *  * Each DTrace provider advertises the name and data stability of each of its  * probe description components, as well as its architectural dependencies.  * The D compiler can query the provider attributes (dtrace_pattr_t below) in  * order to compute the properties of an input program and report them.  */
typedef|typedef
name|uint8_t
name|dtrace_stability_t
typedef|;
comment|/* stability code (see attributes(5)) */
typedef|typedef
name|uint8_t
name|dtrace_class_t
typedef|;
comment|/* architectural dependency class */
define|#
directive|define
name|DTRACE_STABILITY_INTERNAL
value|0
comment|/* private to DTrace itself */
define|#
directive|define
name|DTRACE_STABILITY_PRIVATE
value|1
comment|/* private to Sun (see docs) */
define|#
directive|define
name|DTRACE_STABILITY_OBSOLETE
value|2
comment|/* scheduled for removal */
define|#
directive|define
name|DTRACE_STABILITY_EXTERNAL
value|3
comment|/* not controlled by Sun */
define|#
directive|define
name|DTRACE_STABILITY_UNSTABLE
value|4
comment|/* new or rapidly changing */
define|#
directive|define
name|DTRACE_STABILITY_EVOLVING
value|5
comment|/* less rapidly changing */
define|#
directive|define
name|DTRACE_STABILITY_STABLE
value|6
comment|/* mature interface from Sun */
define|#
directive|define
name|DTRACE_STABILITY_STANDARD
value|7
comment|/* industry standard */
define|#
directive|define
name|DTRACE_STABILITY_MAX
value|7
comment|/* maximum valid stability */
define|#
directive|define
name|DTRACE_CLASS_UNKNOWN
value|0
comment|/* unknown architectural dependency */
define|#
directive|define
name|DTRACE_CLASS_CPU
value|1
comment|/* CPU-module-specific */
define|#
directive|define
name|DTRACE_CLASS_PLATFORM
value|2
comment|/* platform-specific (uname -i) */
define|#
directive|define
name|DTRACE_CLASS_GROUP
value|3
comment|/* hardware-group-specific (uname -m) */
define|#
directive|define
name|DTRACE_CLASS_ISA
value|4
comment|/* ISA-specific (uname -p) */
define|#
directive|define
name|DTRACE_CLASS_COMMON
value|5
comment|/* common to all systems */
define|#
directive|define
name|DTRACE_CLASS_MAX
value|5
comment|/* maximum valid class */
define|#
directive|define
name|DTRACE_PRIV_NONE
value|0x0000
define|#
directive|define
name|DTRACE_PRIV_KERNEL
value|0x0001
define|#
directive|define
name|DTRACE_PRIV_USER
value|0x0002
define|#
directive|define
name|DTRACE_PRIV_PROC
value|0x0004
define|#
directive|define
name|DTRACE_PRIV_OWNER
value|0x0008
define|#
directive|define
name|DTRACE_PRIV_ZONEOWNER
value|0x0010
define|#
directive|define
name|DTRACE_PRIV_ALL
define|\
value|(DTRACE_PRIV_KERNEL | DTRACE_PRIV_USER | \ 	DTRACE_PRIV_PROC | DTRACE_PRIV_OWNER | DTRACE_PRIV_ZONEOWNER)
typedef|typedef
struct|struct
name|dtrace_ppriv
block|{
name|uint32_t
name|dtpp_flags
decl_stmt|;
comment|/* privilege flags */
name|uid_t
name|dtpp_uid
decl_stmt|;
comment|/* user ID */
name|zoneid_t
name|dtpp_zoneid
decl_stmt|;
comment|/* zone ID */
block|}
name|dtrace_ppriv_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_attribute
block|{
name|dtrace_stability_t
name|dtat_name
decl_stmt|;
comment|/* entity name stability */
name|dtrace_stability_t
name|dtat_data
decl_stmt|;
comment|/* entity data stability */
name|dtrace_class_t
name|dtat_class
decl_stmt|;
comment|/* entity data dependency */
block|}
name|dtrace_attribute_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_pattr
block|{
name|dtrace_attribute_t
name|dtpa_provider
decl_stmt|;
comment|/* provider attributes */
name|dtrace_attribute_t
name|dtpa_mod
decl_stmt|;
comment|/* module attributes */
name|dtrace_attribute_t
name|dtpa_func
decl_stmt|;
comment|/* function attributes */
name|dtrace_attribute_t
name|dtpa_name
decl_stmt|;
comment|/* name attributes */
name|dtrace_attribute_t
name|dtpa_args
decl_stmt|;
comment|/* args[] attributes */
block|}
name|dtrace_pattr_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_providerdesc
block|{
name|char
name|dtvd_name
index|[
name|DTRACE_PROVNAMELEN
index|]
decl_stmt|;
comment|/* provider name */
name|dtrace_pattr_t
name|dtvd_attr
decl_stmt|;
comment|/* stability attributes */
name|dtrace_ppriv_t
name|dtvd_priv
decl_stmt|;
comment|/* privileges required */
block|}
name|dtrace_providerdesc_t
typedef|;
comment|/*  * DTrace Pseudodevice Interface  *  * DTrace is controlled through ioctl(2)'s to the in-kernel dtrace:dtrace  * pseudodevice driver.  These ioctls comprise the user-kernel interface to  * DTrace.  */
ifdef|#
directive|ifdef
name|illumos
define|#
directive|define
name|DTRACEIOC
value|(('d'<< 24) | ('t'<< 16) | ('r'<< 8))
define|#
directive|define
name|DTRACEIOC_PROVIDER
value|(DTRACEIOC | 1)
comment|/* provider query */
define|#
directive|define
name|DTRACEIOC_PROBES
value|(DTRACEIOC | 2)
comment|/* probe query */
define|#
directive|define
name|DTRACEIOC_BUFSNAP
value|(DTRACEIOC | 4)
comment|/* snapshot buffer */
define|#
directive|define
name|DTRACEIOC_PROBEMATCH
value|(DTRACEIOC | 5)
comment|/* match probes */
define|#
directive|define
name|DTRACEIOC_ENABLE
value|(DTRACEIOC | 6)
comment|/* enable probes */
define|#
directive|define
name|DTRACEIOC_AGGSNAP
value|(DTRACEIOC | 7)
comment|/* snapshot agg. */
define|#
directive|define
name|DTRACEIOC_EPROBE
value|(DTRACEIOC | 8)
comment|/* get eprobe desc. */
define|#
directive|define
name|DTRACEIOC_PROBEARG
value|(DTRACEIOC | 9)
comment|/* get probe arg */
define|#
directive|define
name|DTRACEIOC_CONF
value|(DTRACEIOC | 10)
comment|/* get config. */
define|#
directive|define
name|DTRACEIOC_STATUS
value|(DTRACEIOC | 11)
comment|/* get status */
define|#
directive|define
name|DTRACEIOC_GO
value|(DTRACEIOC | 12)
comment|/* start tracing */
define|#
directive|define
name|DTRACEIOC_STOP
value|(DTRACEIOC | 13)
comment|/* stop tracing */
define|#
directive|define
name|DTRACEIOC_AGGDESC
value|(DTRACEIOC | 15)
comment|/* get agg. desc. */
define|#
directive|define
name|DTRACEIOC_FORMAT
value|(DTRACEIOC | 16)
comment|/* get format str */
define|#
directive|define
name|DTRACEIOC_DOFGET
value|(DTRACEIOC | 17)
comment|/* get DOF */
define|#
directive|define
name|DTRACEIOC_REPLICATE
value|(DTRACEIOC | 18)
comment|/* replicate enab */
else|#
directive|else
define|#
directive|define
name|DTRACEIOC_PROVIDER
value|_IOWR('x',1,dtrace_providerdesc_t)
comment|/* provider query */
define|#
directive|define
name|DTRACEIOC_PROBES
value|_IOWR('x',2,dtrace_probedesc_t)
comment|/* probe query */
define|#
directive|define
name|DTRACEIOC_BUFSNAP
value|_IOW('x',4,dtrace_bufdesc_t *)
comment|/* snapshot buffer */
define|#
directive|define
name|DTRACEIOC_PROBEMATCH
value|_IOWR('x',5,dtrace_probedesc_t)
comment|/* match probes */
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|dof
decl_stmt|;
comment|/* DOF userland address written to driver. */
name|int
name|n_matched
decl_stmt|;
comment|/* # matches returned by driver. */
block|}
name|dtrace_enable_io_t
typedef|;
define|#
directive|define
name|DTRACEIOC_ENABLE
value|_IOWR('x',6,dtrace_enable_io_t)
comment|/* enable probes */
define|#
directive|define
name|DTRACEIOC_AGGSNAP
value|_IOW('x',7,dtrace_bufdesc_t *)
comment|/* snapshot agg. */
define|#
directive|define
name|DTRACEIOC_EPROBE
value|_IOW('x',8,dtrace_eprobedesc_t)
comment|/* get eprobe desc. */
define|#
directive|define
name|DTRACEIOC_PROBEARG
value|_IOWR('x',9,dtrace_argdesc_t)
comment|/* get probe arg */
define|#
directive|define
name|DTRACEIOC_CONF
value|_IOR('x',10,dtrace_conf_t)
comment|/* get config. */
define|#
directive|define
name|DTRACEIOC_STATUS
value|_IOR('x',11,dtrace_status_t)
comment|/* get status */
define|#
directive|define
name|DTRACEIOC_GO
value|_IOR('x',12,processorid_t)
comment|/* start tracing */
define|#
directive|define
name|DTRACEIOC_STOP
value|_IOWR('x',13,processorid_t)
comment|/* stop tracing */
define|#
directive|define
name|DTRACEIOC_AGGDESC
value|_IOW('x',15,dtrace_aggdesc_t *)
comment|/* get agg. desc. */
define|#
directive|define
name|DTRACEIOC_FORMAT
value|_IOWR('x',16,dtrace_fmtdesc_t)
comment|/* get format str */
define|#
directive|define
name|DTRACEIOC_DOFGET
value|_IOW('x',17,dof_hdr_t *)
comment|/* get DOF */
define|#
directive|define
name|DTRACEIOC_REPLICATE
value|_IOW('x',18,dtrace_repldesc_t)
comment|/* replicate enab */
endif|#
directive|endif
comment|/*  * DTrace Helpers  *  * In general, DTrace establishes probes in processes and takes actions on  * processes without knowing their specific user-level structures.  Instead of  * existing in the framework, process-specific knowledge is contained by the  * enabling D program -- which can apply process-specific knowledge by making  * appropriate use of DTrace primitives like copyin() and copyinstr() to  * operate on user-level data.  However, there may exist some specific probes  * of particular semantic relevance that the application developer may wish to  * explicitly export.  For example, an application may wish to export a probe  * at the point that it begins and ends certain well-defined transactions.  In  * addition to providing probes, programs may wish to offer assistance for  * certain actions.  For example, in highly dynamic environments (e.g., Java),  * it may be difficult to obtain a stack trace in terms of meaningful symbol  * names (the translation from instruction addresses to corresponding symbol  * names may only be possible in situ); these environments may wish to define  * a series of actions to be applied in situ to obtain a meaningful stack  * trace.  *  * These two mechanisms -- user-level statically defined tracing and assisting  * DTrace actions -- are provided via DTrace _helpers_.  Helpers are specified  * via DOF, but unlike enabling DOF, helper DOF may contain definitions of  * providers, probes and their arguments.  If a helper wishes to provide  * action assistance, probe descriptions and corresponding DIF actions may be  * specified in the helper DOF.  For such helper actions, however, the probe  * description describes the specific helper:  all DTrace helpers have the  * provider name "dtrace" and the module name "helper", and the name of the  * helper is contained in the function name (for example, the ustack() helper  * is named "ustack").  Any helper-specific name may be contained in the name  * (for example, if a helper were to have a constructor, it might be named  * "dtrace:helper:<helper>:init").  Helper actions are only called when the  * action that they are helping is taken.  Helper actions may only return DIF  * expressions, and may only call the following subroutines:  *  *    alloca()<= Allocates memory out of the consumer's scratch space  *    bcopy()<= Copies memory to scratch space  *    copyin()<= Copies memory from user-level into consumer's scratch  *    copyinto()<= Copies memory into a specific location in scratch  *    copyinstr()<= Copies a string into a specific location in scratch  *  * Helper actions may only access the following built-in variables:  *  *    curthread<= Current kthread_t pointer  *    tid<= Current thread identifier  *    pid<= Current process identifier  *    ppid<= Parent process identifier  *    uid<= Current user ID  *    gid<= Current group ID  *    execname<= Current executable name  *    zonename<= Current zone name  *  * Helper actions may not manipulate or allocate dynamic variables, but they  * may have clause-local and statically-allocated global variables.  The  * helper action variable state is specific to the helper action -- variables  * used by the helper action may not be accessed outside of the helper  * action, and the helper action may not access variables that like outside  * of it.  Helper actions may not load from kernel memory at-large; they are  * restricting to loading current user state (via copyin() and variants) and  * scratch space.  As with probe enablings, helper actions are executed in  * program order.  The result of the helper action is the result of the last  * executing helper expression.  *  * Helpers -- composed of either providers/probes or probes/actions (or both)  * -- are added by opening the "helper" minor node, and issuing an ioctl(2)  * (DTRACEHIOC_ADDDOF) that specifies the dof_helper_t structure. This  * encapsulates the name and base address of the user-level library or  * executable publishing the helpers and probes as well as the DOF that  * contains the definitions of those helpers and probes.  *  * The DTRACEHIOC_ADD and DTRACEHIOC_REMOVE are left in place for legacy  * helpers and should no longer be used.  No other ioctls are valid on the  * helper minor node.  */
ifdef|#
directive|ifdef
name|illumos
define|#
directive|define
name|DTRACEHIOC
value|(('d'<< 24) | ('t'<< 16) | ('h'<< 8))
define|#
directive|define
name|DTRACEHIOC_ADD
value|(DTRACEHIOC | 1)
comment|/* add helper */
define|#
directive|define
name|DTRACEHIOC_REMOVE
value|(DTRACEHIOC | 2)
comment|/* remove helper */
define|#
directive|define
name|DTRACEHIOC_ADDDOF
value|(DTRACEHIOC | 3)
comment|/* add helper DOF */
else|#
directive|else
define|#
directive|define
name|DTRACEHIOC_REMOVE
value|_IOW('z', 2, int)
comment|/* remove helper */
define|#
directive|define
name|DTRACEHIOC_ADDDOF
value|_IOWR('z', 3, dof_helper_t)
comment|/* add helper DOF */
endif|#
directive|endif
typedef|typedef
struct|struct
name|dof_helper
block|{
name|char
name|dofhp_mod
index|[
name|DTRACE_MODNAMELEN
index|]
decl_stmt|;
comment|/* executable or library name */
name|uint64_t
name|dofhp_addr
decl_stmt|;
comment|/* base address of object */
name|uint64_t
name|dofhp_dof
decl_stmt|;
comment|/* address of helper DOF */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|pid_t
name|dofhp_pid
decl_stmt|;
comment|/* target process ID */
name|int
name|dofhp_gen
decl_stmt|;
endif|#
directive|endif
block|}
name|dof_helper_t
typedef|;
define|#
directive|define
name|DTRACEMNR_DTRACE
value|"dtrace"
comment|/* node for DTrace ops */
define|#
directive|define
name|DTRACEMNR_HELPER
value|"helper"
comment|/* node for helpers */
define|#
directive|define
name|DTRACEMNRN_DTRACE
value|0
comment|/* minor for DTrace ops */
define|#
directive|define
name|DTRACEMNRN_HELPER
value|1
comment|/* minor for helpers */
define|#
directive|define
name|DTRACEMNRN_CLONE
value|2
comment|/* first clone minor */
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*  * DTrace Provider API  *  * The following functions are implemented by the DTrace framework and are  * used to implement separate in-kernel DTrace providers.  Common functions  * are provided in uts/common/os/dtrace.c.  ISA-dependent subroutines are  * defined in uts/<isa>/dtrace/dtrace_asm.s or uts/<isa>/dtrace/dtrace_isa.c.  *  * The provider API has two halves:  the API that the providers consume from  * DTrace, and the API that providers make available to DTrace.  *  * 1 Framework-to-Provider API  *  * 1.1  Overview  *  * The Framework-to-Provider API is represented by the dtrace_pops structure  * that the provider passes to the framework when registering itself.  This  * structure consists of the following members:  *  *   dtps_provide()<-- Provide all probes, all modules  *   dtps_provide_module()<-- Provide all probes in specified module  *   dtps_enable()<-- Enable specified probe  *   dtps_disable()<-- Disable specified probe  *   dtps_suspend()<-- Suspend specified probe  *   dtps_resume()<-- Resume specified probe  *   dtps_getargdesc()<-- Get the argument description for args[X]  *   dtps_getargval()<-- Get the value for an argX or args[X] variable  *   dtps_usermode()<-- Find out if the probe was fired in user mode  *   dtps_destroy()<-- Destroy all state associated with this probe  *  * 1.2  void dtps_provide(void *arg, const dtrace_probedesc_t *spec)  *  * 1.2.1  Overview  *  *   Called to indicate that the provider should provide all probes.  If the  *   specified description is non-NULL, dtps_provide() is being called because  *   no probe matched a specified probe -- if the provider has the ability to  *   create custom probes, it may wish to create a probe that matches the  *   specified description.  *  * 1.2.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register().  The  *   second argument is a pointer to a probe description that the provider may  *   wish to consider when creating custom probes.  The provider is expected to  *   call back into the DTrace framework via dtrace_probe_create() to create  *   any necessary probes.  dtps_provide() may be called even if the provider  *   has made available all probes; the provider should check the return value  *   of dtrace_probe_create() to handle this case.  Note that the provider need  *   not implement both dtps_provide() and dtps_provide_module(); see  *   "Arguments and Notes" for dtrace_register(), below.  *  * 1.2.3  Return value  *  *   None.  *  * 1.2.4  Caller's context  *  *   dtps_provide() is typically called from open() or ioctl() context, but may  *   be called from other contexts as well.  The DTrace framework is locked in  *   such a way that providers may not register or unregister.  This means that  *   the provider may not call any DTrace API that affects its registration with  *   the framework, including dtrace_register(), dtrace_unregister(),  *   dtrace_invalidate(), and dtrace_condense().  However, the context is such  *   that the provider may (and indeed, is expected to) call probe-related  *   DTrace routines, including dtrace_probe_create(), dtrace_probe_lookup(),  *   and dtrace_probe_arg().  *  * 1.3  void dtps_provide_module(void *arg, modctl_t *mp)  *  * 1.3.1  Overview  *  *   Called to indicate that the provider should provide all probes in the  *   specified module.  *  * 1.3.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register().  The  *   second argument is a pointer to a modctl structure that indicates the  *   module for which probes should be created.  *  * 1.3.3  Return value  *  *   None.  *  * 1.3.4  Caller's context  *  *   dtps_provide_module() may be called from open() or ioctl() context, but  *   may also be called from a module loading context.  mod_lock is held, and  *   the DTrace framework is locked in such a way that providers may not  *   register or unregister.  This means that the provider may not call any  *   DTrace API that affects its registration with the framework, including  *   dtrace_register(), dtrace_unregister(), dtrace_invalidate(), and  *   dtrace_condense().  However, the context is such that the provider may (and  *   indeed, is expected to) call probe-related DTrace routines, including  *   dtrace_probe_create(), dtrace_probe_lookup(), and dtrace_probe_arg().  Note  *   that the provider need not implement both dtps_provide() and  *   dtps_provide_module(); see "Arguments and Notes" for dtrace_register(),  *   below.  *  * 1.4  void dtps_enable(void *arg, dtrace_id_t id, void *parg)  *  * 1.4.1  Overview  *  *   Called to enable the specified probe.  *  * 1.4.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register().  The  *   second argument is the identifier of the probe to be enabled.  The third  *   argument is the probe argument as passed to dtrace_probe_create().  *   dtps_enable() will be called when a probe transitions from not being  *   enabled at all to having one or more ECB.  The number of ECBs associated  *   with the probe may change without subsequent calls into the provider.  *   When the number of ECBs drops to zero, the provider will be explicitly  *   told to disable the probe via dtps_disable().  dtrace_probe() should never  *   be called for a probe identifier that hasn't been explicitly enabled via  *   dtps_enable().  *  * 1.4.3  Return value  *  *   None.  *  * 1.4.4  Caller's context  *  *   The DTrace framework is locked in such a way that it may not be called  *   back into at all.  cpu_lock is held.  mod_lock is not held and may not  *   be acquired.  *  * 1.5  void dtps_disable(void *arg, dtrace_id_t id, void *parg)  *  * 1.5.1  Overview  *  *   Called to disable the specified probe.  *  * 1.5.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register().  The  *   second argument is the identifier of the probe to be disabled.  The third  *   argument is the probe argument as passed to dtrace_probe_create().  *   dtps_disable() will be called when a probe transitions from being enabled  *   to having zero ECBs.  dtrace_probe() should never be called for a probe  *   identifier that has been explicitly enabled via dtps_disable().  *  * 1.5.3  Return value  *  *   None.  *  * 1.5.4  Caller's context  *  *   The DTrace framework is locked in such a way that it may not be called  *   back into at all.  cpu_lock is held.  mod_lock is not held and may not  *   be acquired.  *  * 1.6  void dtps_suspend(void *arg, dtrace_id_t id, void *parg)  *  * 1.6.1  Overview  *  *   Called to suspend the specified enabled probe.  This entry point is for  *   providers that may need to suspend some or all of their probes when CPUs  *   are being powered on or when the boot monitor is being entered for a  *   prolonged period of time.  *  * 1.6.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register().  The  *   second argument is the identifier of the probe to be suspended.  The  *   third argument is the probe argument as passed to dtrace_probe_create().  *   dtps_suspend will only be called on an enabled probe.  Providers that  *   provide a dtps_suspend entry point will want to take roughly the action  *   that it takes for dtps_disable.  *  * 1.6.3  Return value  *  *   None.  *  * 1.6.4  Caller's context  *  *   Interrupts are disabled.  The DTrace framework is in a state such that the  *   specified probe cannot be disabled or destroyed for the duration of  *   dtps_suspend().  As interrupts are disabled, the provider is afforded  *   little latitude; the provider is expected to do no more than a store to  *   memory.  *  * 1.7  void dtps_resume(void *arg, dtrace_id_t id, void *parg)  *  * 1.7.1  Overview  *  *   Called to resume the specified enabled probe.  This entry point is for  *   providers that may need to resume some or all of their probes after the  *   completion of an event that induced a call to dtps_suspend().  *  * 1.7.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register().  The  *   second argument is the identifier of the probe to be resumed.  The  *   third argument is the probe argument as passed to dtrace_probe_create().  *   dtps_resume will only be called on an enabled probe.  Providers that  *   provide a dtps_resume entry point will want to take roughly the action  *   that it takes for dtps_enable.  *  * 1.7.3  Return value  *  *   None.  *  * 1.7.4  Caller's context  *  *   Interrupts are disabled.  The DTrace framework is in a state such that the  *   specified probe cannot be disabled or destroyed for the duration of  *   dtps_resume().  As interrupts are disabled, the provider is afforded  *   little latitude; the provider is expected to do no more than a store to  *   memory.  *  * 1.8  void dtps_getargdesc(void *arg, dtrace_id_t id, void *parg,  *           dtrace_argdesc_t *desc)  *  * 1.8.1  Overview  *  *   Called to retrieve the argument description for an args[X] variable.  *  * 1.8.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register(). The  *   second argument is the identifier of the current probe. The third  *   argument is the probe argument as passed to dtrace_probe_create(). The  *   fourth argument is a pointer to the argument description.  This  *   description is both an input and output parameter:  it contains the  *   index of the desired argument in the dtargd_ndx field, and expects  *   the other fields to be filled in upon return.  If there is no argument  *   corresponding to the specified index, the dtargd_ndx field should be set  *   to DTRACE_ARGNONE.  *  * 1.8.3  Return value  *  *   None.  The dtargd_ndx, dtargd_native, dtargd_xlate and dtargd_mapping  *   members of the dtrace_argdesc_t structure are all output values.  *  * 1.8.4  Caller's context  *  *   dtps_getargdesc() is called from ioctl() context. mod_lock is held, and  *   the DTrace framework is locked in such a way that providers may not  *   register or unregister.  This means that the provider may not call any  *   DTrace API that affects its registration with the framework, including  *   dtrace_register(), dtrace_unregister(), dtrace_invalidate(), and  *   dtrace_condense().  *  * 1.9  uint64_t dtps_getargval(void *arg, dtrace_id_t id, void *parg,  *               int argno, int aframes)  *  * 1.9.1  Overview  *  *   Called to retrieve a value for an argX or args[X] variable.  *  * 1.9.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register(). The  *   second argument is the identifier of the current probe. The third  *   argument is the probe argument as passed to dtrace_probe_create(). The  *   fourth argument is the number of the argument (the X in the example in  *   1.9.1). The fifth argument is the number of stack frames that were used  *   to get from the actual place in the code that fired the probe to  *   dtrace_probe() itself, the so-called artificial frames. This argument may  *   be used to descend an appropriate number of frames to find the correct  *   values. If this entry point is left NULL, the dtrace_getarg() built-in  *   function is used.  *  * 1.9.3  Return value  *  *   The value of the argument.  *  * 1.9.4  Caller's context  *  *   This is called from within dtrace_probe() meaning that interrupts  *   are disabled. No locks should be taken within this entry point.  *  * 1.10  int dtps_usermode(void *arg, dtrace_id_t id, void *parg)  *  * 1.10.1  Overview  *  *   Called to determine if the probe was fired in a user context.  *  * 1.10.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register(). The  *   second argument is the identifier of the current probe. The third  *   argument is the probe argument as passed to dtrace_probe_create().  This  *   entry point must not be left NULL for providers whose probes allow for  *   mixed mode tracing, that is to say those probes that can fire during  *   kernel- _or_ user-mode execution  *  * 1.10.3  Return value  *  *   A bitwise OR that encapsulates both the mode (either DTRACE_MODE_KERNEL  *   or DTRACE_MODE_USER) and the policy when the privilege of the enabling  *   is insufficient for that mode (a combination of DTRACE_MODE_NOPRIV_DROP,  *   DTRACE_MODE_NOPRIV_RESTRICT, and DTRACE_MODE_LIMITEDPRIV_RESTRICT).  If  *   DTRACE_MODE_NOPRIV_DROP bit is set, insufficient privilege will result  *   in the probe firing being silently ignored for the enabling; if the  *   DTRACE_NODE_NOPRIV_RESTRICT bit is set, insufficient privilege will not  *   prevent probe processing for the enabling, but restrictions will be in  *   place that induce a UPRIV fault upon attempt to examine probe arguments  *   or current process state.  If the DTRACE_MODE_LIMITEDPRIV_RESTRICT bit  *   is set, similar restrictions will be placed upon operation if the  *   privilege is sufficient to process the enabling, but does not otherwise  *   entitle the enabling to all zones.  The DTRACE_MODE_NOPRIV_DROP and  *   DTRACE_MODE_NOPRIV_RESTRICT are mutually exclusive (and one of these  *   two policies must be specified), but either may be combined (or not)  *   with DTRACE_MODE_LIMITEDPRIV_RESTRICT.  *  * 1.10.4  Caller's context  *  *   This is called from within dtrace_probe() meaning that interrupts  *   are disabled. No locks should be taken within this entry point.  *  * 1.11 void dtps_destroy(void *arg, dtrace_id_t id, void *parg)  *  * 1.11.1 Overview  *  *   Called to destroy the specified probe.  *  * 1.11.2 Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_register().  The  *   second argument is the identifier of the probe to be destroyed.  The third  *   argument is the probe argument as passed to dtrace_probe_create().  The  *   provider should free all state associated with the probe.  The framework  *   guarantees that dtps_destroy() is only called for probes that have either  *   been disabled via dtps_disable() or were never enabled via dtps_enable().  *   Once dtps_disable() has been called for a probe, no further call will be  *   made specifying the probe.  *  * 1.11.3 Return value  *  *   None.  *  * 1.11.4 Caller's context  *  *   The DTrace framework is locked in such a way that it may not be called  *   back into at all.  mod_lock is held.  cpu_lock is not held, and may not be  *   acquired.  *  *  * 2 Provider-to-Framework API  *  * 2.1  Overview  *  * The Provider-to-Framework API provides the mechanism for the provider to  * register itself with the DTrace framework, to create probes, to lookup  * probes and (most importantly) to fire probes.  The Provider-to-Framework  * consists of:  *  *   dtrace_register()<-- Register a provider with the DTrace framework  *   dtrace_unregister()<-- Remove a provider's DTrace registration  *   dtrace_invalidate()<-- Invalidate the specified provider  *   dtrace_condense()<-- Remove a provider's unenabled probes  *   dtrace_attached()<-- Indicates whether or not DTrace has attached  *   dtrace_probe_create()<-- Create a DTrace probe  *   dtrace_probe_lookup()<-- Lookup a DTrace probe based on its name  *   dtrace_probe_arg()<-- Return the probe argument for a specific probe  *   dtrace_probe()<-- Fire the specified probe  *  * 2.2  int dtrace_register(const char *name, const dtrace_pattr_t *pap,  *          uint32_t priv, cred_t *cr, const dtrace_pops_t *pops, void *arg,  *          dtrace_provider_id_t *idp)  *  * 2.2.1  Overview  *  *   dtrace_register() registers the calling provider with the DTrace  *   framework.  It should generally be called by DTrace providers in their  *   attach(9E) entry point.  *  * 2.2.2  Arguments and Notes  *  *   The first argument is the name of the provider.  The second argument is a  *   pointer to the stability attributes for the provider.  The third argument  *   is the privilege flags for the provider, and must be some combination of:  *  *     DTRACE_PRIV_NONE<= All users may enable probes from this provider  *  *     DTRACE_PRIV_PROC<= Any user with privilege of PRIV_DTRACE_PROC may  *                             enable probes from this provider  *  *     DTRACE_PRIV_USER<= Any user with privilege of PRIV_DTRACE_USER may  *                             enable probes from this provider  *  *     DTRACE_PRIV_KERNEL<= Any user with privilege of PRIV_DTRACE_KERNEL  *                             may enable probes from this provider  *  *     DTRACE_PRIV_OWNER<= This flag places an additional constraint on  *                             the privilege requirements above. These probes  *                             require either (a) a user ID matching the user  *                             ID of the cred passed in the fourth argument  *                             or (b) the PRIV_PROC_OWNER privilege.  *  *     DTRACE_PRIV_ZONEOWNER<= This flag places an additional constraint on  *                             the privilege requirements above. These probes  *                             require either (a) a zone ID matching the zone  *                             ID of the cred passed in the fourth argument  *                             or (b) the PRIV_PROC_ZONE privilege.  *  *   Note that these flags designate the _visibility_ of the probes, not  *   the conditions under which they may or may not fire.  *  *   The fourth argument is the credential that is associated with the  *   provider.  This argument should be NULL if the privilege flags don't  *   include DTRACE_PRIV_OWNER or DTRACE_PRIV_ZONEOWNER.  If non-NULL, the  *   framework stashes the uid and zoneid represented by this credential  *   for use at probe-time, in implicit predicates.  These limit visibility  *   of the probes to users and/or zones which have sufficient privilege to  *   access them.  *  *   The fifth argument is a DTrace provider operations vector, which provides  *   the implementation for the Framework-to-Provider API.  (See Section 1,  *   above.)  This must be non-NULL, and each member must be non-NULL.  The  *   exceptions to this are (1) the dtps_provide() and dtps_provide_module()  *   members (if the provider so desires, _one_ of these members may be left  *   NULL -- denoting that the provider only implements the other) and (2)  *   the dtps_suspend() and dtps_resume() members, which must either both be  *   NULL or both be non-NULL.  *  *   The sixth argument is a cookie to be specified as the first argument for  *   each function in the Framework-to-Provider API.  This argument may have  *   any value.  *  *   The final argument is a pointer to dtrace_provider_id_t.  If  *   dtrace_register() successfully completes, the provider identifier will be  *   stored in the memory pointed to be this argument.  This argument must be  *   non-NULL.  *  * 2.2.3  Return value  *  *   On success, dtrace_register() returns 0 and stores the new provider's  *   identifier into the memory pointed to by the idp argument.  On failure,  *   dtrace_register() returns an errno:  *  *     EINVAL   The arguments passed to dtrace_register() were somehow invalid.  *              This may because a parameter that must be non-NULL was NULL,  *              because the name was invalid (either empty or an illegal  *              provider name) or because the attributes were invalid.  *  *   No other failure code is returned.  *  * 2.2.4  Caller's context  *  *   dtrace_register() may induce calls to dtrace_provide(); the provider must  *   hold no locks across dtrace_register() that may also be acquired by  *   dtrace_provide().  cpu_lock and mod_lock must not be held.  *  * 2.3  int dtrace_unregister(dtrace_provider_t id)  *  * 2.3.1  Overview  *  *   Unregisters the specified provider from the DTrace framework.  It should  *   generally be called by DTrace providers in their detach(9E) entry point.  *  * 2.3.2  Arguments and Notes  *  *   The only argument is the provider identifier, as returned from a  *   successful call to dtrace_register().  As a result of calling  *   dtrace_unregister(), the DTrace framework will call back into the provider  *   via the dtps_destroy() entry point.  Once dtrace_unregister() successfully  *   completes, however, the DTrace framework will no longer make calls through  *   the Framework-to-Provider API.  *  * 2.3.3  Return value  *  *   On success, dtrace_unregister returns 0.  On failure, dtrace_unregister()  *   returns an errno:  *  *     EBUSY    There are currently processes that have the DTrace pseudodevice  *              open, or there exists an anonymous enabling that hasn't yet  *              been claimed.  *  *   No other failure code is returned.  *  * 2.3.4  Caller's context  *  *   Because a call to dtrace_unregister() may induce calls through the  *   Framework-to-Provider API, the caller may not hold any lock across  *   dtrace_register() that is also acquired in any of the Framework-to-  *   Provider API functions.  Additionally, mod_lock may not be held.  *  * 2.4  void dtrace_invalidate(dtrace_provider_id_t id)  *  * 2.4.1  Overview  *  *   Invalidates the specified provider.  All subsequent probe lookups for the  *   specified provider will fail, but its probes will not be removed.  *  * 2.4.2  Arguments and note  *  *   The only argument is the provider identifier, as returned from a  *   successful call to dtrace_register().  In general, a provider's probes  *   always remain valid; dtrace_invalidate() is a mechanism for invalidating  *   an entire provider, regardless of whether or not probes are enabled or  *   not.  Note that dtrace_invalidate() will _not_ prevent already enabled  *   probes from firing -- it will merely prevent any new enablings of the  *   provider's probes.  *  * 2.5 int dtrace_condense(dtrace_provider_id_t id)  *  * 2.5.1  Overview  *  *   Removes all the unenabled probes for the given provider. This function is  *   not unlike dtrace_unregister(), except that it doesn't remove the  *   provider just as many of its associated probes as it can.  *  * 2.5.2  Arguments and Notes  *  *   As with dtrace_unregister(), the sole argument is the provider identifier  *   as returned from a successful call to dtrace_register().  As a result of  *   calling dtrace_condense(), the DTrace framework will call back into the  *   given provider's dtps_destroy() entry point for each of the provider's  *   unenabled probes.  *  * 2.5.3  Return value  *  *   Currently, dtrace_condense() always returns 0.  However, consumers of this  *   function should check the return value as appropriate; its behavior may  *   change in the future.  *  * 2.5.4  Caller's context  *  *   As with dtrace_unregister(), the caller may not hold any lock across  *   dtrace_condense() that is also acquired in the provider's entry points.  *   Also, mod_lock may not be held.  *  * 2.6 int dtrace_attached()  *  * 2.6.1  Overview  *  *   Indicates whether or not DTrace has attached.  *  * 2.6.2  Arguments and Notes  *  *   For most providers, DTrace makes initial contact beyond registration.  *   That is, once a provider has registered with DTrace, it waits to hear  *   from DTrace to create probes.  However, some providers may wish to  *   proactively create probes without first being told by DTrace to do so.  *   If providers wish to do this, they must first call dtrace_attached() to  *   determine if DTrace itself has attached.  If dtrace_attached() returns 0,  *   the provider must not make any other Provider-to-Framework API call.  *  * 2.6.3  Return value  *  *   dtrace_attached() returns 1 if DTrace has attached, 0 otherwise.  *  * 2.7  int dtrace_probe_create(dtrace_provider_t id, const char *mod,  *	    const char *func, const char *name, int aframes, void *arg)  *  * 2.7.1  Overview  *  *   Creates a probe with specified module name, function name, and name.  *  * 2.7.2  Arguments and Notes  *  *   The first argument is the provider identifier, as returned from a  *   successful call to dtrace_register().  The second, third, and fourth  *   arguments are the module name, function name, and probe name,  *   respectively.  Of these, module name and function name may both be NULL  *   (in which case the probe is considered to be unanchored), or they may both  *   be non-NULL.  The name must be non-NULL, and must point to a non-empty  *   string.  *  *   The fifth argument is the number of artificial stack frames that will be  *   found on the stack when dtrace_probe() is called for the new probe.  These  *   artificial frames will be automatically be pruned should the stack() or  *   stackdepth() functions be called as part of one of the probe's ECBs.  If  *   the parameter doesn't add an artificial frame, this parameter should be  *   zero.  *  *   The final argument is a probe argument that will be passed back to the  *   provider when a probe-specific operation is called.  (e.g., via  *   dtps_enable(), dtps_disable(), etc.)  *  *   Note that it is up to the provider to be sure that the probe that it  *   creates does not already exist -- if the provider is unsure of the probe's  *   existence, it should assure its absence with dtrace_probe_lookup() before  *   calling dtrace_probe_create().  *  * 2.7.3  Return value  *  *   dtrace_probe_create() always succeeds, and always returns the identifier  *   of the newly-created probe.  *  * 2.7.4  Caller's context  *  *   While dtrace_probe_create() is generally expected to be called from  *   dtps_provide() and/or dtps_provide_module(), it may be called from other  *   non-DTrace contexts.  Neither cpu_lock nor mod_lock may be held.  *  * 2.8  dtrace_id_t dtrace_probe_lookup(dtrace_provider_t id, const char *mod,  *	    const char *func, const char *name)  *  * 2.8.1  Overview  *  *   Looks up a probe based on provdider and one or more of module name,  *   function name and probe name.  *  * 2.8.2  Arguments and Notes  *  *   The first argument is the provider identifier, as returned from a  *   successful call to dtrace_register().  The second, third, and fourth  *   arguments are the module name, function name, and probe name,  *   respectively.  Any of these may be NULL; dtrace_probe_lookup() will return  *   the identifier of the first probe that is provided by the specified  *   provider and matches all of the non-NULL matching criteria.  *   dtrace_probe_lookup() is generally used by a provider to be check the  *   existence of a probe before creating it with dtrace_probe_create().  *  * 2.8.3  Return value  *  *   If the probe exists, returns its identifier.  If the probe does not exist,  *   return DTRACE_IDNONE.  *  * 2.8.4  Caller's context  *  *   While dtrace_probe_lookup() is generally expected to be called from  *   dtps_provide() and/or dtps_provide_module(), it may also be called from  *   other non-DTrace contexts.  Neither cpu_lock nor mod_lock may be held.  *  * 2.9  void *dtrace_probe_arg(dtrace_provider_t id, dtrace_id_t probe)  *  * 2.9.1  Overview  *  *   Returns the probe argument associated with the specified probe.  *  * 2.9.2  Arguments and Notes  *  *   The first argument is the provider identifier, as returned from a  *   successful call to dtrace_register().  The second argument is a probe  *   identifier, as returned from dtrace_probe_lookup() or  *   dtrace_probe_create().  This is useful if a probe has multiple  *   provider-specific components to it:  the provider can create the probe  *   once with provider-specific state, and then add to the state by looking  *   up the probe based on probe identifier.  *  * 2.9.3  Return value  *  *   Returns the argument associated with the specified probe.  If the  *   specified probe does not exist, or if the specified probe is not provided  *   by the specified provider, NULL is returned.  *  * 2.9.4  Caller's context  *  *   While dtrace_probe_arg() is generally expected to be called from  *   dtps_provide() and/or dtps_provide_module(), it may also be called from  *   other non-DTrace contexts.  Neither cpu_lock nor mod_lock may be held.  *  * 2.10  void dtrace_probe(dtrace_id_t probe, uintptr_t arg0, uintptr_t arg1,  *		uintptr_t arg2, uintptr_t arg3, uintptr_t arg4)  *  * 2.10.1  Overview  *  *   The epicenter of DTrace:  fires the specified probes with the specified  *   arguments.  *  * 2.10.2  Arguments and Notes  *  *   The first argument is a probe identifier as returned by  *   dtrace_probe_create() or dtrace_probe_lookup().  The second through sixth  *   arguments are the values to which the D variables "arg0" through "arg4"  *   will be mapped.  *  *   dtrace_probe() should be called whenever the specified probe has fired --  *   however the provider defines it.  *  * 2.10.3  Return value  *  *   None.  *  * 2.10.4  Caller's context  *  *   dtrace_probe() may be called in virtually any context:  kernel, user,  *   interrupt, high-level interrupt, with arbitrary adaptive locks held, with  *   dispatcher locks held, with interrupts disabled, etc.  The only latitude  *   that must be afforded to DTrace is the ability to make calls within  *   itself (and to its in-kernel subroutines) and the ability to access  *   arbitrary (but mapped) memory.  On some platforms, this constrains  *   context.  For example, on UltraSPARC, dtrace_probe() cannot be called  *   from any context in which TL is greater than zero.  dtrace_probe() may  *   also not be called from any routine which may be called by dtrace_probe()  *   -- which includes functions in the DTrace framework and some in-kernel  *   DTrace subroutines.  All such functions "dtrace_"; providers that  *   instrument the kernel arbitrarily should be sure to not instrument these  *   routines.  */
typedef|typedef
struct|struct
name|dtrace_pops
block|{
name|void
function_decl|(
modifier|*
name|dtps_provide
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_probedesc_t
modifier|*
name|spec
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dtps_provide_module
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|modctl_t
modifier|*
name|mp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dtps_enable
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dtps_disable
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dtps_suspend
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dtps_resume
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dtps_getargdesc
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|,
name|dtrace_argdesc_t
modifier|*
name|desc
parameter_list|)
function_decl|;
name|uint64_t
function_decl|(
modifier|*
name|dtps_getargval
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|,
name|int
name|argno
parameter_list|,
name|int
name|aframes
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dtps_usermode
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dtps_destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|dtrace_id_t
name|id
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
block|}
name|dtrace_pops_t
typedef|;
define|#
directive|define
name|DTRACE_MODE_KERNEL
value|0x01
define|#
directive|define
name|DTRACE_MODE_USER
value|0x02
define|#
directive|define
name|DTRACE_MODE_NOPRIV_DROP
value|0x10
define|#
directive|define
name|DTRACE_MODE_NOPRIV_RESTRICT
value|0x20
define|#
directive|define
name|DTRACE_MODE_LIMITEDPRIV_RESTRICT
value|0x40
typedef|typedef
name|uintptr_t
name|dtrace_provider_id_t
typedef|;
specifier|extern
name|int
name|dtrace_register
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|dtrace_pattr_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|cred_t
modifier|*
parameter_list|,
specifier|const
name|dtrace_pops_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|dtrace_provider_id_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dtrace_unregister
parameter_list|(
name|dtrace_provider_id_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dtrace_condense
parameter_list|(
name|dtrace_provider_id_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_invalidate
parameter_list|(
name|dtrace_provider_id_t
parameter_list|)
function_decl|;
specifier|extern
name|dtrace_id_t
name|dtrace_probe_lookup
parameter_list|(
name|dtrace_provider_id_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dtrace_id_t
name|dtrace_probe_create
parameter_list|(
name|dtrace_provider_id_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|dtrace_probe_arg
parameter_list|(
name|dtrace_provider_id_t
parameter_list|,
name|dtrace_id_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_probe
parameter_list|(
name|dtrace_id_t
parameter_list|,
name|uintptr_t
name|arg0
parameter_list|,
name|uintptr_t
name|arg1
parameter_list|,
name|uintptr_t
name|arg2
parameter_list|,
name|uintptr_t
name|arg3
parameter_list|,
name|uintptr_t
name|arg4
parameter_list|)
function_decl|;
comment|/*  * DTrace Meta Provider API  *  * The following functions are implemented by the DTrace framework and are  * used to implement meta providers. Meta providers plug into the DTrace  * framework and are used to instantiate new providers on the fly. At  * present, there is only one type of meta provider and only one meta  * provider may be registered with the DTrace framework at a time. The  * sole meta provider type provides user-land static tracing facilities  * by taking meta probe descriptions and adding a corresponding provider  * into the DTrace framework.  *  * 1 Framework-to-Provider  *  * 1.1 Overview  *  * The Framework-to-Provider API is represented by the dtrace_mops structure  * that the meta provider passes to the framework when registering itself as  * a meta provider. This structure consists of the following members:  *  *   dtms_create_probe()<-- Add a new probe to a created provider  *   dtms_provide_pid()<-- Create a new provider for a given process  *   dtms_remove_pid()<-- Remove a previously created provider  *  * 1.2  void dtms_create_probe(void *arg, void *parg,  *           dtrace_helper_probedesc_t *probedesc);  *  * 1.2.1  Overview  *  *   Called by the DTrace framework to create a new probe in a provider  *   created by this meta provider.  *  * 1.2.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_meta_register().  *   The second argument is the provider cookie for the associated provider;  *   this is obtained from the return value of dtms_provide_pid(). The third  *   argument is the helper probe description.  *  * 1.2.3  Return value  *  *   None  *  * 1.2.4  Caller's context  *  *   dtms_create_probe() is called from either ioctl() or module load context  *   in the context of a newly-created provider (that is, a provider that  *   is a result of a call to dtms_provide_pid()). The DTrace framework is  *   locked in such a way that meta providers may not register or unregister,  *   such that no other thread can call into a meta provider operation and that  *   atomicity is assured with respect to meta provider operations across  *   dtms_provide_pid() and subsequent calls to dtms_create_probe().  *   The context is thus effectively single-threaded with respect to the meta  *   provider, and that the meta provider cannot call dtrace_meta_register()  *   or dtrace_meta_unregister(). However, the context is such that the  *   provider may (and is expected to) call provider-related DTrace provider  *   APIs including dtrace_probe_create().  *  * 1.3  void *dtms_provide_pid(void *arg, dtrace_meta_provider_t *mprov,  *	      pid_t pid)  *  * 1.3.1  Overview  *  *   Called by the DTrace framework to instantiate a new provider given the  *   description of the provider and probes in the mprov argument. The  *   meta provider should call dtrace_register() to insert the new provider  *   into the DTrace framework.  *  * 1.3.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_meta_register().  *   The second argument is a pointer to a structure describing the new  *   helper provider. The third argument is the process identifier for  *   process associated with this new provider. Note that the name of the  *   provider as passed to dtrace_register() should be the contatenation of  *   the dtmpb_provname member of the mprov argument and the processs  *   identifier as a string.  *  * 1.3.3  Return value  *  *   The cookie for the provider that the meta provider creates. This is  *   the same value that it passed to dtrace_register().  *  * 1.3.4  Caller's context  *  *   dtms_provide_pid() is called from either ioctl() or module load context.  *   The DTrace framework is locked in such a way that meta providers may not  *   register or unregister. This means that the meta provider cannot call  *   dtrace_meta_register() or dtrace_meta_unregister(). However, the context  *   is such that the provider may -- and is expected to --  call  *   provider-related DTrace provider APIs including dtrace_register().  *  * 1.4  void dtms_remove_pid(void *arg, dtrace_meta_provider_t *mprov,  *	     pid_t pid)  *  * 1.4.1  Overview  *  *   Called by the DTrace framework to remove a provider that had previously  *   been instantiated via the dtms_provide_pid() entry point. The meta  *   provider need not remove the provider immediately, but this entry  *   point indicates that the provider should be removed as soon as possible  *   using the dtrace_unregister() API.  *  * 1.4.2  Arguments and notes  *  *   The first argument is the cookie as passed to dtrace_meta_register().  *   The second argument is a pointer to a structure describing the helper  *   provider. The third argument is the process identifier for process  *   associated with this new provider.  *  * 1.4.3  Return value  *  *   None  *  * 1.4.4  Caller's context  *  *   dtms_remove_pid() is called from either ioctl() or exit() context.  *   The DTrace framework is locked in such a way that meta providers may not  *   register or unregister. This means that the meta provider cannot call  *   dtrace_meta_register() or dtrace_meta_unregister(). However, the context  *   is such that the provider may -- and is expected to -- call  *   provider-related DTrace provider APIs including dtrace_unregister().  */
typedef|typedef
struct|struct
name|dtrace_helper_probedesc
block|{
name|char
modifier|*
name|dthpb_mod
decl_stmt|;
comment|/* probe module */
name|char
modifier|*
name|dthpb_func
decl_stmt|;
comment|/* probe function */
name|char
modifier|*
name|dthpb_name
decl_stmt|;
comment|/* probe name */
name|uint64_t
name|dthpb_base
decl_stmt|;
comment|/* base address */
name|uint32_t
modifier|*
name|dthpb_offs
decl_stmt|;
comment|/* offsets array */
name|uint32_t
modifier|*
name|dthpb_enoffs
decl_stmt|;
comment|/* is-enabled offsets array */
name|uint32_t
name|dthpb_noffs
decl_stmt|;
comment|/* offsets count */
name|uint32_t
name|dthpb_nenoffs
decl_stmt|;
comment|/* is-enabled offsets count */
name|uint8_t
modifier|*
name|dthpb_args
decl_stmt|;
comment|/* argument mapping array */
name|uint8_t
name|dthpb_xargc
decl_stmt|;
comment|/* translated argument count */
name|uint8_t
name|dthpb_nargc
decl_stmt|;
comment|/* native argument count */
name|char
modifier|*
name|dthpb_xtypes
decl_stmt|;
comment|/* translated types strings */
name|char
modifier|*
name|dthpb_ntypes
decl_stmt|;
comment|/* native types strings */
block|}
name|dtrace_helper_probedesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_helper_provdesc
block|{
name|char
modifier|*
name|dthpv_provname
decl_stmt|;
comment|/* provider name */
name|dtrace_pattr_t
name|dthpv_pattr
decl_stmt|;
comment|/* stability attributes */
block|}
name|dtrace_helper_provdesc_t
typedef|;
typedef|typedef
struct|struct
name|dtrace_mops
block|{
name|void
function_decl|(
modifier|*
name|dtms_create_probe
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|dtrace_helper_probedesc_t
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|dtms_provide_pid
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|dtrace_helper_provdesc_t
modifier|*
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dtms_remove_pid
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|dtrace_helper_provdesc_t
modifier|*
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
block|}
name|dtrace_mops_t
typedef|;
typedef|typedef
name|uintptr_t
name|dtrace_meta_provider_id_t
typedef|;
specifier|extern
name|int
name|dtrace_meta_register
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|dtrace_mops_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|dtrace_meta_provider_id_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dtrace_meta_unregister
parameter_list|(
name|dtrace_meta_provider_id_t
parameter_list|)
function_decl|;
comment|/*  * DTrace Kernel Hooks  *  * The following functions are implemented by the base kernel and form a set of  * hooks used by the DTrace framework.  DTrace hooks are implemented in either  * uts/common/os/dtrace_subr.c, an ISA-specific assembly file, or in a  * uts/<platform>/os/dtrace_subr.c corresponding to each hardware platform.  */
typedef|typedef
enum|enum
name|dtrace_vtime_state
block|{
name|DTRACE_VTIME_INACTIVE
init|=
literal|0
block|,
comment|/* No DTrace, no TNF */
name|DTRACE_VTIME_ACTIVE
block|,
comment|/* DTrace virtual time, no TNF */
name|DTRACE_VTIME_INACTIVE_TNF
block|,
comment|/* No DTrace, TNF active */
name|DTRACE_VTIME_ACTIVE_TNF
comment|/* DTrace virtual time _and_ TNF */
block|}
name|dtrace_vtime_state_t
typedef|;
ifdef|#
directive|ifdef
name|illumos
specifier|extern
name|dtrace_vtime_state_t
name|dtrace_vtime_active
decl_stmt|;
endif|#
directive|endif
specifier|extern
name|void
name|dtrace_vtime_switch
parameter_list|(
name|kthread_t
modifier|*
name|next
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_vtime_enable_tnf
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_vtime_disable_tnf
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_vtime_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_vtime_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
struct_decl|struct
name|regs
struct_decl|;
struct_decl|struct
name|reg
struct_decl|;
ifdef|#
directive|ifdef
name|illumos
specifier|extern
name|int
function_decl|(
modifier|*
name|dtrace_pid_probe_ptr
function_decl|)
parameter_list|(
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
function_decl|(
modifier|*
name|dtrace_return_probe_ptr
function_decl|)
parameter_list|(
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_fasttrap_fork_ptr
function_decl|)
parameter_list|(
name|proc_t
modifier|*
parameter_list|,
name|proc_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_fasttrap_exec_ptr
function_decl|)
parameter_list|(
name|proc_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_fasttrap_exit_ptr
function_decl|)
parameter_list|(
name|proc_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_fasttrap_fork
parameter_list|(
name|proc_t
modifier|*
parameter_list|,
name|proc_t
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
typedef|typedef
name|uintptr_t
name|dtrace_icookie_t
typedef|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_xcall_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dtrace_icookie_t
name|dtrace_interrupt_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_interrupt_enable
parameter_list|(
name|dtrace_icookie_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_membar_producer
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_membar_consumer
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_cpu_init
function_decl|)
parameter_list|(
name|processorid_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|illumos
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_modload
function_decl|)
parameter_list|(
name|modctl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_modunload
function_decl|)
parameter_list|(
name|modctl_t
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_helpers_cleanup
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_helpers_fork
function_decl|)
parameter_list|(
name|proc_t
modifier|*
name|parent
parameter_list|,
name|proc_t
modifier|*
name|child
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_cpustart_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_cpustart_fini
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_closef
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_debugger_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
function_decl|(
modifier|*
name|dtrace_debugger_fini
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|dtrace_cacheid_t
name|dtrace_predcache_id
decl_stmt|;
ifdef|#
directive|ifdef
name|illumos
specifier|extern
name|hrtime_t
name|dtrace_gethrtime
parameter_list|(
name|void
parameter_list|)
function_decl|;
else|#
directive|else
name|void
name|dtrace_debug_printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
block|)
empty_stmt|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|dtrace_sync
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_toxic_ranges
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_xcall
parameter_list|(
name|processorid_t
parameter_list|,
name|dtrace_xcall_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_vpanic
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_panic
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dtrace_safe_defer_signal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_safe_synchronous_signal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dtrace_mach_aframes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|dtrace_instr_size
parameter_list|(
name|uchar_t
modifier|*
name|instr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dtrace_instr_size_isa
parameter_list|(
name|uchar_t
modifier|*
parameter_list|,
name|model_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_invop_callsite
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|dtrace_invop_add
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|uintptr_t
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_invop_remove
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|uintptr_t
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc
end_ifdef

begin_function_decl
specifier|extern
name|int
name|dtrace_blksuword32
parameter_list|(
name|uintptr_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_getfsr
parameter_list|(
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|illumos
end_ifndef

begin_function_decl
specifier|extern
name|void
name|dtrace_helpers_duplicate
parameter_list|(
name|proc_t
modifier|*
parameter_list|,
name|proc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtrace_helpers_destroy
parameter_list|(
name|proc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DTRACE_CPUFLAG_ISSET
parameter_list|(
name|flag
parameter_list|)
define|\
value|(cpu_core[curcpu].cpuc_dtrace_flags& (flag))
end_define

begin_define
define|#
directive|define
name|DTRACE_CPUFLAG_SET
parameter_list|(
name|flag
parameter_list|)
define|\
value|(cpu_core[curcpu].cpuc_dtrace_flags |= (flag))
end_define

begin_define
define|#
directive|define
name|DTRACE_CPUFLAG_CLEAR
parameter_list|(
name|flag
parameter_list|)
define|\
value|(cpu_core[curcpu].cpuc_dtrace_flags&= ~(flag))
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
comment|/* _ASM */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
end_if

begin_define
define|#
directive|define
name|DTRACE_INVOP_PUSHL_EBP
value|1
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_PUSHQ_RBP
value|DTRACE_INVOP_PUSHL_EBP
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_POPL_EBP
value|2
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_POPQ_RBP
value|DTRACE_INVOP_POPL_EBP
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_LEAVE
value|3
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_NOP
value|4
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_RET
value|5
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|DTRACE_INVOP_RET
value|1
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_BCTR
value|2
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_BLR
value|3
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_JUMP
value|4
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_MFLR_R0
value|5
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_NOP
value|6
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|DTRACE_INVOP_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_MASK
value|((1<< DTRACE_INVOP_SHIFT) - 1)
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_DATA
parameter_list|(
name|x
parameter_list|)
value|((x)>> DTRACE_INVOP_SHIFT)
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_PUSHM
value|1
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_POPM
value|2
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_B
value|3
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INSN_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|B_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|B_DATA_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|B_INSTR
value|0x14000000
end_define

begin_define
define|#
directive|define
name|RET_INSTR
value|0xd65f03c0
end_define

begin_define
define|#
directive|define
name|LDP_STP_MASK
value|0xffc00000
end_define

begin_define
define|#
directive|define
name|STP_32
value|0x29800000
end_define

begin_define
define|#
directive|define
name|STP_64
value|0xa9800000
end_define

begin_define
define|#
directive|define
name|LDP_32
value|0x28c00000
end_define

begin_define
define|#
directive|define
name|LDP_64
value|0xa8c00000
end_define

begin_define
define|#
directive|define
name|LDP_STP_PREIND
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|LDP_STP_DIR
value|(1<< 22)
end_define

begin_comment
comment|/* Load instruction */
end_comment

begin_define
define|#
directive|define
name|ARG1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ARG1_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|ARG2_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|ARG2_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|OFFSET_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|OFFSET_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|OFFSET_MASK
value|((1<< OFFSET_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_PUSHM
value|1
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_RET
value|2
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_B
value|3
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INSN_SIZE
value|4
end_define

begin_comment
comment|/* Load/Store double RA to/from SP */
end_comment

begin_define
define|#
directive|define
name|LDSD_RA_SP_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|LDSD_DATA_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|SD_RA_SP
value|0xffbf0000
end_define

begin_define
define|#
directive|define
name|LD_RA_SP
value|0xdfbf0000
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_SD
value|1
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_LD
value|2
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__riscv
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SD_RA_SP_MASK
value|0x01fff07f
end_define

begin_define
define|#
directive|define
name|SD_RA_SP
value|0x00113023
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_SD
value|1
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_RET
value|2
end_define

begin_define
define|#
directive|define
name|DTRACE_INVOP_NOP
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DTRACE_H */
end_comment

end_unit

