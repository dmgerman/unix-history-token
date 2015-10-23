begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__SPARC_ARCH_H__
end_ifndef

begin_define
define|#
directive|define
name|__SPARC_ARCH_H__
end_define

begin_define
define|#
directive|define
name|SPARCV9_TICK_PRIVILEGED
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SPARCV9_PREFER_FPU
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|SPARCV9_VIS1
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|SPARCV9_VIS2
value|(1<<3)
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|SPARCV9_FMADD
value|(1<<4)
end_define

begin_comment
comment|/* reserved for SPARC64 V */
end_comment

begin_define
define|#
directive|define
name|SPARCV9_BLK
value|(1<<5)
end_define

begin_comment
comment|/* VIS1 block copy */
end_comment

begin_define
define|#
directive|define
name|SPARCV9_VIS3
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|SPARCV9_RANDOM
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|SPARCV9_64BIT_STACK
value|(1<<8)
end_define

begin_comment
comment|/*  * OPENSSL_sparcv9cap_P[1] is copy of Compatibility Feature Register,  * %asr26, SPARC-T4 and later. There is no SPARCV9_CFR bit in  * OPENSSL_sparcv9cap_P[0], as %cfr copy is sufficient...  */
end_comment

begin_define
define|#
directive|define
name|CFR_AES
value|0x00000001
end_define

begin_comment
comment|/* Supports AES opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_DES
value|0x00000002
end_define

begin_comment
comment|/* Supports DES opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_KASUMI
value|0x00000004
end_define

begin_comment
comment|/* Supports KASUMI opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_CAMELLIA
value|0x00000008
end_define

begin_comment
comment|/* Supports CAMELLIA opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_MD5
value|0x00000010
end_define

begin_comment
comment|/* Supports MD5 opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_SHA1
value|0x00000020
end_define

begin_comment
comment|/* Supports SHA1 opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_SHA256
value|0x00000040
end_define

begin_comment
comment|/* Supports SHA256 opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_SHA512
value|0x00000080
end_define

begin_comment
comment|/* Supports SHA512 opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_MPMUL
value|0x00000100
end_define

begin_comment
comment|/* Supports MPMUL opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_MONTMUL
value|0x00000200
end_define

begin_comment
comment|/* Supports MONTMUL opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_MONTSQR
value|0x00000400
end_define

begin_comment
comment|/* Supports MONTSQR opcodes */
end_comment

begin_define
define|#
directive|define
name|CFR_CRC32C
value|0x00000800
end_define

begin_comment
comment|/* Supports CRC32C opcodes */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_PIC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__PIC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__PIC__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SUNPRO_C
argument_list|)
operator|&&
name|defined
argument_list|(
name|__sparcv9
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__arch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__arch64__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPARC_PIC_THUNK
parameter_list|(
name|reg
parameter_list|)
define|\
value|.align  32;             \ .Lpic_thunk:                    \         jmp     %o7 + 8;        \          add    %o7, reg, reg;
end_define

begin_define
define|#
directive|define
name|SPARC_PIC_THUNK_CALL
parameter_list|(
name|reg
parameter_list|)
define|\
value|sethi   %hi(_GLOBAL_OFFSET_TABLE_-4), reg;      \         call    .Lpic_thunk;                            \          or     reg, %lo(_GLOBAL_OFFSET_TABLE_+4), reg;
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|SPARC_SETUP_GOT_REG
parameter_list|(
name|reg
parameter_list|)
value|SPARC_PIC_THUNK_CALL(reg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPARC_SETUP_GOT_REG
parameter_list|(
name|reg
parameter_list|)
define|\
value|sethi   %hi(_GLOBAL_OFFSET_TABLE_-4), reg;      \         call    .+8;                                    \         or      reg,%lo(_GLOBAL_OFFSET_TABLE_+4), reg;  \         add     %o7, reg, reg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPARC_LOAD_ADDRESS
parameter_list|(
name|SYM
parameter_list|,
name|reg
parameter_list|)
define|\
value|setx    SYM, %o7, reg;
end_define

begin_define
define|#
directive|define
name|LDPTR
value|ldx
end_define

begin_define
define|#
directive|define
name|SIZE_T_CC
value|%xcc
end_define

begin_define
define|#
directive|define
name|STACK_FRAME
value|192
end_define

begin_define
define|#
directive|define
name|STACK_BIAS
value|2047
end_define

begin_define
define|#
directive|define
name|STACK_7thARG
value|(STACK_BIAS+176)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPARC_LOAD_ADDRESS
parameter_list|(
name|SYM
parameter_list|,
name|reg
parameter_list|)
define|\
value|set     SYM, reg;
end_define

begin_define
define|#
directive|define
name|LDPTR
value|ld
end_define

begin_define
define|#
directive|define
name|SIZE_T_CC
value|%icc
end_define

begin_define
define|#
directive|define
name|STACK_FRAME
value|112
end_define

begin_define
define|#
directive|define
name|STACK_BIAS
value|0
end_define

begin_define
define|#
directive|define
name|STACK_7thARG
value|92
end_define

begin_define
define|#
directive|define
name|SPARC_LOAD_ADDRESS_LEAF
parameter_list|(
name|SYM
parameter_list|,
name|reg
parameter_list|,
name|tmp
parameter_list|)
value|SPARC_LOAD_ADDRESS(SYM,reg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__PIC__
end_ifdef

begin_undef
undef|#
directive|undef
name|SPARC_LOAD_ADDRESS
end_undef

begin_undef
undef|#
directive|undef
name|SPARC_LOAD_ADDRESS_LEAF
end_undef

begin_define
define|#
directive|define
name|SPARC_LOAD_ADDRESS
parameter_list|(
name|SYM
parameter_list|,
name|reg
parameter_list|)
define|\
value|SPARC_SETUP_GOT_REG(reg);       \         sethi   %hi(SYM), %o7;          \         or      %o7, %lo(SYM), %o7;     \         LDPTR   [reg + %o7], reg;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SPARC_LOAD_ADDRESS_LEAF
end_ifndef

begin_define
define|#
directive|define
name|SPARC_LOAD_ADDRESS_LEAF
parameter_list|(
name|SYM
parameter_list|,
name|reg
parameter_list|,
name|tmp
parameter_list|)
define|\
value|mov     %o7, tmp;                       \         SPARC_LOAD_ADDRESS(SYM, reg)            \         mov     tmp, %o7;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SPARC_ARCH_H__ */
end_comment

end_unit

