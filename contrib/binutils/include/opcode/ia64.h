begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ia64.h -- Header file for ia64 opcode table    Copyright (C) 1998, 1999 David Mosberger-Tang<davidm@hpl.hp.com>     See the file HP-COPYRIGHT for additional information.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|opcode_ia64_h
end_ifndef

begin_define
define|#
directive|define
name|opcode_ia64_h
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<bfd.h>
end_include

begin_typedef
typedef|typedef
name|BFD_HOST_U_64_BIT
name|ia64_insn
typedef|;
end_typedef

begin_enum
enum|enum
name|ia64_insn_type
block|{
name|IA64_TYPE_NIL
init|=
literal|0
block|,
comment|/* illegal type */
name|IA64_TYPE_A
block|,
comment|/* integer alu (I- or M-unit) */
name|IA64_TYPE_I
block|,
comment|/* non-alu integer (I-unit) */
name|IA64_TYPE_M
block|,
comment|/* memory (M-unit) */
name|IA64_TYPE_B
block|,
comment|/* branch (B-unit) */
name|IA64_TYPE_F
block|,
comment|/* floating-point (F-unit) */
name|IA64_TYPE_X
block|,
comment|/* long encoding (X-unit) */
name|IA64_TYPE_DYN
block|,
comment|/* Dynamic opcode */
name|IA64_NUM_TYPES
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ia64_unit
block|{
name|IA64_UNIT_NIL
init|=
literal|0
block|,
comment|/* illegal unit */
name|IA64_UNIT_I
block|,
comment|/* integer unit */
name|IA64_UNIT_M
block|,
comment|/* memory unit */
name|IA64_UNIT_B
block|,
comment|/* branching unit */
name|IA64_UNIT_F
block|,
comment|/* floating-point unit */
name|IA64_UNIT_L
block|,
comment|/* long "unit" */
name|IA64_UNIT_X
block|,
comment|/* may be integer or branch unit */
name|IA64_NUM_UNITS
block|}
enum|;
end_enum

begin_comment
comment|/* Changes to this enumeration must be propagated to the operand table in    bfd/cpu-ia64-opc.c   */
end_comment

begin_enum
enum|enum
name|ia64_opnd
block|{
name|IA64_OPND_NIL
block|,
comment|/* no operand---MUST BE FIRST!*/
comment|/* constants */
name|IA64_OPND_AR_CCV
block|,
comment|/* application register ccv (ar.ccv) */
name|IA64_OPND_AR_PFS
block|,
comment|/* application register pfs (ar.pfs) */
name|IA64_OPND_C1
block|,
comment|/* the constant 1 */
name|IA64_OPND_C8
block|,
comment|/* the constant 8 */
name|IA64_OPND_C16
block|,
comment|/* the constant 16 */
name|IA64_OPND_GR0
block|,
comment|/* gr0 */
name|IA64_OPND_IP
block|,
comment|/* instruction pointer (ip) */
name|IA64_OPND_PR
block|,
comment|/* predicate register (pr) */
name|IA64_OPND_PR_ROT
block|,
comment|/* rotating predicate register (pr.rot) */
name|IA64_OPND_PSR
block|,
comment|/* processor status register (psr) */
name|IA64_OPND_PSR_L
block|,
comment|/* processor status register L (psr.l) */
name|IA64_OPND_PSR_UM
block|,
comment|/* processor status register UM (psr.um) */
comment|/* register operands: */
name|IA64_OPND_AR3
block|,
comment|/* third application register # (bits 20-26) */
name|IA64_OPND_B1
block|,
comment|/* branch register # (bits 6-8) */
name|IA64_OPND_B2
block|,
comment|/* branch register # (bits 13-15) */
name|IA64_OPND_CR3
block|,
comment|/* third control register # (bits 20-26) */
name|IA64_OPND_F1
block|,
comment|/* first floating-point register # */
name|IA64_OPND_F2
block|,
comment|/* second floating-point register # */
name|IA64_OPND_F3
block|,
comment|/* third floating-point register # */
name|IA64_OPND_F4
block|,
comment|/* fourth floating-point register # */
name|IA64_OPND_P1
block|,
comment|/* first predicate # */
name|IA64_OPND_P2
block|,
comment|/* second predicate # */
name|IA64_OPND_R1
block|,
comment|/* first register # */
name|IA64_OPND_R2
block|,
comment|/* second register # */
name|IA64_OPND_R3
block|,
comment|/* third register # */
name|IA64_OPND_R3_2
block|,
comment|/* third register # (limited to gr0-gr3) */
comment|/* indirect operands: */
name|IA64_OPND_CPUID_R3
block|,
comment|/* cpuid[reg] */
name|IA64_OPND_DBR_R3
block|,
comment|/* dbr[reg] */
name|IA64_OPND_DTR_R3
block|,
comment|/* dtr[reg] */
name|IA64_OPND_ITR_R3
block|,
comment|/* itr[reg] */
name|IA64_OPND_IBR_R3
block|,
comment|/* ibr[reg] */
name|IA64_OPND_MR3
block|,
comment|/* memory at addr of third register # */
name|IA64_OPND_MSR_R3
block|,
comment|/* msr[reg] */
name|IA64_OPND_PKR_R3
block|,
comment|/* pkr[reg] */
name|IA64_OPND_PMC_R3
block|,
comment|/* pmc[reg] */
name|IA64_OPND_PMD_R3
block|,
comment|/* pmd[reg] */
name|IA64_OPND_RR_R3
block|,
comment|/* rr[reg] */
comment|/* immediate operands: */
name|IA64_OPND_CCNT5
block|,
comment|/* 5-bit count (31 - bits 20-24) */
name|IA64_OPND_CNT2a
block|,
comment|/* 2-bit count (1 + bits 27-28) */
name|IA64_OPND_CNT2b
block|,
comment|/* 2-bit count (bits 27-28): 1, 2, 3 */
name|IA64_OPND_CNT2c
block|,
comment|/* 2-bit count (bits 30-31): 0, 7, 15, or 16 */
name|IA64_OPND_CNT5
block|,
comment|/* 5-bit count (bits 14-18) */
name|IA64_OPND_CNT6
block|,
comment|/* 6-bit count (bits 27-32) */
name|IA64_OPND_CPOS6a
block|,
comment|/* 6-bit count (63 - bits 20-25) */
name|IA64_OPND_CPOS6b
block|,
comment|/* 6-bit count (63 - bits 14-19) */
name|IA64_OPND_CPOS6c
block|,
comment|/* 6-bit count (63 - bits 31-36) */
name|IA64_OPND_IMM1
block|,
comment|/* signed 1-bit immediate (bit 36) */
name|IA64_OPND_IMMU2
block|,
comment|/* unsigned 2-bit immediate (bits 13-14) */
name|IA64_OPND_IMMU7a
block|,
comment|/* unsigned 7-bit immediate (bits 13-19) */
name|IA64_OPND_IMMU7b
block|,
comment|/* unsigned 7-bit immediate (bits 20-26) */
name|IA64_OPND_SOF
block|,
comment|/* 8-bit stack frame size */
name|IA64_OPND_SOL
block|,
comment|/* 8-bit size of locals */
name|IA64_OPND_SOR
block|,
comment|/* 6-bit number of rotating registers (scaled by 8) */
name|IA64_OPND_IMM8
block|,
comment|/* signed 8-bit immediate (bits 13-19& 36) */
name|IA64_OPND_IMM8U4
block|,
comment|/* cmp4*u signed 8-bit immediate (bits 13-19& 36) */
name|IA64_OPND_IMM8M1
block|,
comment|/* signed 8-bit immediate -1 (bits 13-19& 36) */
name|IA64_OPND_IMM8M1U4
block|,
comment|/* cmp4*u signed 8-bit immediate -1 (bits 13-19& 36)*/
name|IA64_OPND_IMM8M1U8
block|,
comment|/* cmp*u signed 8-bit immediate -1 (bits 13-19& 36) */
name|IA64_OPND_IMMU9
block|,
comment|/* unsigned 9-bit immediate (bits 33-34, 20-26) */
name|IA64_OPND_IMM9a
block|,
comment|/* signed 9-bit immediate (bits 6-12, 27, 36) */
name|IA64_OPND_IMM9b
block|,
comment|/* signed 9-bit immediate (bits 13-19, 27, 36) */
name|IA64_OPND_IMM14
block|,
comment|/* signed 14-bit immediate (bits 13-19, 27-32, 36) */
name|IA64_OPND_IMM17
block|,
comment|/* signed 17-bit immediate (2*bits 6-12, 24-31, 36) */
name|IA64_OPND_IMMU21
block|,
comment|/* unsigned 21-bit immediate (bits 6-25, 36) */
name|IA64_OPND_IMM22
block|,
comment|/* signed 22-bit immediate (bits 13-19, 22-36) */
name|IA64_OPND_IMMU24
block|,
comment|/* unsigned 24-bit immediate (bits 6-26, 31-32, 36) */
name|IA64_OPND_IMM44
block|,
comment|/* signed 44-bit immediate (2^16*bits 6-32, 36) */
name|IA64_OPND_IMMU62
block|,
comment|/* unsigned 62-bit immediate */
name|IA64_OPND_IMMU64
block|,
comment|/* unsigned 64-bit immediate (lotsa bits...) */
name|IA64_OPND_INC3
block|,
comment|/* signed 3-bit (bits 13-15): +/-1, 4, 8, 16 */
name|IA64_OPND_LEN4
block|,
comment|/* 4-bit count (bits 27-30 + 1) */
name|IA64_OPND_LEN6
block|,
comment|/* 6-bit count (bits 27-32 + 1) */
name|IA64_OPND_MBTYPE4
block|,
comment|/* 4-bit mux type (bits 20-23) */
name|IA64_OPND_MHTYPE8
block|,
comment|/* 8-bit mux type (bits 20-27) */
name|IA64_OPND_POS6
block|,
comment|/* 6-bit count (bits 14-19) */
name|IA64_OPND_TAG13
block|,
comment|/* signed 13-bit tag (ip + 16*bits 6-12, 33-34) */
name|IA64_OPND_TAG13b
block|,
comment|/* signed 13-bit tag (ip + 16*bits 24-32) */
name|IA64_OPND_TGT25
block|,
comment|/* signed 25-bit (ip + 16*bits 6-25, 36) */
name|IA64_OPND_TGT25b
block|,
comment|/* signed 25-bit (ip + 16*bits 6-12, 20-32, 36) */
name|IA64_OPND_TGT25c
block|,
comment|/* signed 25-bit (ip + 16*bits 13-32, 36) */
name|IA64_OPND_TGT64
block|,
comment|/* 64-bit (ip + 16*bits 13-32, 36, 2-40(L)) */
name|IA64_OPND_COUNT
comment|/* # of operand types (MUST BE LAST!) */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ia64_dependency_mode
block|{
name|IA64_DV_RAW
block|,
name|IA64_DV_WAW
block|,
name|IA64_DV_WAR
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ia64_dependency_semantics
block|{
name|IA64_DVS_NONE
block|,
name|IA64_DVS_IMPLIED
block|,
name|IA64_DVS_IMPLIEDF
block|,
name|IA64_DVS_DATA
block|,
name|IA64_DVS_INSTR
block|,
name|IA64_DVS_SPECIFIC
block|,
name|IA64_DVS_STOP
block|,
name|IA64_DVS_OTHER
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ia64_resource_specifier
block|{
name|IA64_RS_ANY
block|,
name|IA64_RS_AR_K
block|,
name|IA64_RS_AR_UNAT
block|,
name|IA64_RS_AR
block|,
comment|/* 8-15, 20, 22-23, 31, 33-35, 37-39, 41-43, 45-47, 67-111 */
name|IA64_RS_ARb
block|,
comment|/* 48-63, 112-127 */
name|IA64_RS_BR
block|,
name|IA64_RS_CFM
block|,
name|IA64_RS_CPUID
block|,
name|IA64_RS_CR_IRR
block|,
name|IA64_RS_CR_LRR
block|,
name|IA64_RS_CR
block|,
comment|/* 3-7,10-15,18,26-63,75-79,82-127 */
name|IA64_RS_DBR
block|,
name|IA64_RS_FR
block|,
name|IA64_RS_FRb
block|,
name|IA64_RS_GR0
block|,
name|IA64_RS_GR
block|,
name|IA64_RS_IBR
block|,
name|IA64_RS_INSERVICE
block|,
comment|/* CR[EOI] or CR[IVR] */
name|IA64_RS_MSR
block|,
name|IA64_RS_PKR
block|,
name|IA64_RS_PMC
block|,
name|IA64_RS_PMD
block|,
name|IA64_RS_PR
block|,
comment|/* non-rotating, 1-15 */
name|IA64_RS_PRr
block|,
comment|/* rotating, 16-62 */
name|IA64_RS_PR63
block|,
name|IA64_RS_RR
block|,
name|IA64_RS_ARX
block|,
comment|/* ARs not in RS_AR or RS_ARb */
name|IA64_RS_CRX
block|,
comment|/* CRs not in RS_CR */
name|IA64_RS_PSR
block|,
comment|/* PSR bits */
name|IA64_RS_RSE
block|,
comment|/* implementation-specific RSE resources */
name|IA64_RS_AR_FPSR
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ia64_rse_resource
block|{
name|IA64_RSE_N_STACKED_PHYS
block|,
name|IA64_RSE_BOF
block|,
name|IA64_RSE_STORE_REG
block|,
name|IA64_RSE_LOAD_REG
block|,
name|IA64_RSE_BSPLOAD
block|,
name|IA64_RSE_RNATBITINDEX
block|,
name|IA64_RSE_CFLE
block|,
name|IA64_RSE_NDIRTY
block|, }
enum|;
end_enum

begin_comment
comment|/* Information about a given resource dependency */
end_comment

begin_struct
struct|struct
name|ia64_dependency
block|{
comment|/* Name of the resource */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Does this dependency need further specification? */
name|enum
name|ia64_resource_specifier
name|specifier
decl_stmt|;
comment|/* Mode of dependency */
name|enum
name|ia64_dependency_mode
name|mode
decl_stmt|;
comment|/* Dependency semantics */
name|enum
name|ia64_dependency_semantics
name|semantics
decl_stmt|;
comment|/* Register index, if applicable (distinguishes AR, CR, and PSR deps) */
define|#
directive|define
name|REG_NONE
value|(-1)
name|int
name|regindex
decl_stmt|;
comment|/* Special info on semantics */
specifier|const
name|char
modifier|*
name|info
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Two arrays of indexes into the ia64_dependency table.    chks are dependencies to check for conflicts when an opcode is    encountered; regs are dependencies to register (mark as used) when an    opcode is used.  chks correspond to readers (RAW) or writers (WAW or    WAR) of a resource, while regs correspond to writers (RAW or WAW) and    readers (WAR) of a resource.  */
end_comment

begin_struct
struct|struct
name|ia64_opcode_dependency
block|{
name|int
name|nchks
decl_stmt|;
specifier|const
name|unsigned
name|short
modifier|*
name|chks
decl_stmt|;
name|int
name|nregs
decl_stmt|;
specifier|const
name|unsigned
name|short
modifier|*
name|regs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* encode/extract the note/index for a dependency */
end_comment

begin_define
define|#
directive|define
name|RDEP
parameter_list|(
name|N
parameter_list|,
name|X
parameter_list|)
value|(((N)<<11)|(X))
end_define

begin_define
define|#
directive|define
name|NOTE
parameter_list|(
name|X
parameter_list|)
value|(((X)>>11)&0x1F)
end_define

begin_define
define|#
directive|define
name|DEP
parameter_list|(
name|X
parameter_list|)
value|((X)&0x7FF)
end_define

begin_comment
comment|/* A template descriptor describes the execution units that are active    for each of the three slots.  It also specifies the location of    instruction group boundaries that may be present between two slots.  */
end_comment

begin_struct
struct|struct
name|ia64_templ_desc
block|{
name|int
name|group_boundary
decl_stmt|;
comment|/* 0=no boundary, 1=between slot 0& 1, etc. */
name|enum
name|ia64_unit
name|exec_unit
index|[
literal|3
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The opcode table is an array of struct ia64_opcode.  */
end_comment

begin_struct
struct|struct
name|ia64_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The type of the instruction: */
name|enum
name|ia64_insn_type
name|type
decl_stmt|;
comment|/* Number of output operands: */
name|int
name|num_outputs
decl_stmt|;
comment|/* The opcode itself.  Those bits which will be filled in with        operands are zeroes.  */
name|ia64_insn
name|opcode
decl_stmt|;
comment|/* The opcode mask.  This is used by the disassembler.  This is a        mask containing ones indicating those bits which must match the        opcode field, and zeroes indicating those bits which need not        match (and are presumably filled in by operands).  */
name|ia64_insn
name|mask
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the        operand table.  They appear in the order which the operands must        appear in assembly code, and are terminated by a zero.  */
name|enum
name|ia64_opnd
name|operands
index|[
literal|5
index|]
decl_stmt|;
comment|/* One bit flags for the opcode.  These are primarily used to        indicate specific processors and environments support the        instructions.  The defined values are listed below. */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* Used by ia64_find_next_opcode (). */
name|short
name|ent_index
decl_stmt|;
comment|/* Opcode dependencies. */
specifier|const
name|struct
name|ia64_opcode_dependency
modifier|*
name|dependencies
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Values defined for the flags field of a struct ia64_opcode.  */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_FIRST
value|(1<<0)
end_define

begin_comment
comment|/* must be first in an insn group */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_X_IN_MLX
value|(1<<1)
end_define

begin_comment
comment|/* insn is allowed in X slot of MLX */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_LAST
value|(1<<2)
end_define

begin_comment
comment|/* must be last in an insn group */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_PRIV
value|(1<<3)
end_define

begin_comment
comment|/* privileged instruct */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_SLOT2
value|(1<<4)
end_define

begin_comment
comment|/* insn allowed in slot 2 only */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_NO_PRED
value|(1<<5)
end_define

begin_comment
comment|/* insn cannot be predicated */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_PSEUDO
value|(1<<6)
end_define

begin_comment
comment|/* insn is a pseudo-op */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_F2_EQ_F3
value|(1<<7)
end_define

begin_comment
comment|/* constraint: F2 == F3 */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_LEN_EQ_64MCNT
value|(1<<8)
end_define

begin_comment
comment|/* constraint: LEN == 64-CNT */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_MOD_RRBS
value|(1<<9)
end_define

begin_comment
comment|/* modifies all rrbs in CFM */
end_comment

begin_define
define|#
directive|define
name|IA64_OPCODE_POSTINC
value|(1<<10)
end_define

begin_comment
comment|/* postincrement MR3 operand */
end_comment

begin_comment
comment|/* A macro to extract the major opcode from an instruction.  */
end_comment

begin_define
define|#
directive|define
name|IA64_OP
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 37)& 0xf)
end_define

begin_enum
enum|enum
name|ia64_operand_class
block|{
name|IA64_OPND_CLASS_CST
block|,
comment|/* constant */
name|IA64_OPND_CLASS_REG
block|,
comment|/* register */
name|IA64_OPND_CLASS_IND
block|,
comment|/* indirect register */
name|IA64_OPND_CLASS_ABS
block|,
comment|/* absolute value */
name|IA64_OPND_CLASS_REL
block|,
comment|/* IP-relative value */
block|}
enum|;
end_enum

begin_comment
comment|/* The operands table is an array of struct ia64_operand.  */
end_comment

begin_struct
struct|struct
name|ia64_operand
block|{
name|enum
name|ia64_operand_class
name|class
decl_stmt|;
comment|/* Set VALUE as the operand bits for the operand of type SELF in the      instruction pointed to by CODE.  If an error occurs, *CODE is not      modified and the returned string describes the cause of the      error.  If no error occurs, NULL is returned.  */
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|insert
function_decl|)
parameter_list|(
specifier|const
name|struct
name|ia64_operand
modifier|*
name|self
parameter_list|,
name|ia64_insn
name|value
parameter_list|,
name|ia64_insn
modifier|*
name|code
parameter_list|)
function_decl|;
comment|/* Extract the operand bits for an operand of type SELF from      instruction CODE store them in *VALUE.  If an error occurs, the      cause of the error is described by the string returned.  If no      error occurs, NULL is returned.  */
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|extract
function_decl|)
parameter_list|(
specifier|const
name|struct
name|ia64_operand
modifier|*
name|self
parameter_list|,
name|ia64_insn
name|code
parameter_list|,
name|ia64_insn
modifier|*
name|value
parameter_list|)
function_decl|;
comment|/* A string whose meaning depends on the operand class.  */
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
struct|struct
name|bit_field
block|{
comment|/* The number of bits in the operand.  */
name|int
name|bits
decl_stmt|;
comment|/* How far the operand is left shifted in the instruction.  */
name|int
name|shift
decl_stmt|;
block|}
name|field
index|[
literal|4
index|]
struct|;
comment|/* no operand has more than this many bit-fields */
name|unsigned
name|int
name|flags
decl_stmt|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* brief description */
block|}
struct|;
end_struct

begin_comment
comment|/* Values defined for the flags field of a struct ia64_operand.  */
end_comment

begin_comment
comment|/* Disassemble as signed decimal (instead of hex): */
end_comment

begin_define
define|#
directive|define
name|IA64_OPND_FLAG_DECIMAL_SIGNED
value|(1<<0)
end_define

begin_comment
comment|/* Disassemble as unsigned decimal (instead of hex): */
end_comment

begin_define
define|#
directive|define
name|IA64_OPND_FLAG_DECIMAL_UNSIGNED
value|(1<<1)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ia64_templ_desc
name|ia64_templ_desc
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The tables are sorted by major opcode number and are otherwise in    the order in which the disassembler should consider instructions.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ia64_opcode
name|ia64_opcodes_a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ia64_opcode
name|ia64_opcodes_i
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ia64_opcode
name|ia64_opcodes_m
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ia64_opcode
name|ia64_opcodes_b
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ia64_opcode
name|ia64_opcodes_f
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ia64_opcode
name|ia64_opcodes_d
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|ia64_opcode
modifier|*
name|ia64_find_opcode
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ia64_opcode
modifier|*
name|ia64_find_next_opcode
parameter_list|(
name|struct
name|ia64_opcode
modifier|*
name|ent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ia64_opcode
modifier|*
name|ia64_dis_opcode
parameter_list|(
name|ia64_insn
name|insn
parameter_list|,
name|enum
name|ia64_insn_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ia64_free_opcode
parameter_list|(
name|struct
name|ia64_opcode
modifier|*
name|ent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|struct
name|ia64_dependency
modifier|*
name|ia64_find_dependency
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* To avoid circular library dependencies, this array is implemented    in bfd/cpu-ia64-opc.c: */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ia64_operand
name|elf64_ia64_operands
index|[
name|IA64_OPND_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* opcode_ia64_h */
end_comment

end_unit

