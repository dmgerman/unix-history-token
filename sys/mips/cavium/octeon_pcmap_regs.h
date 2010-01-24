begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *    This product includes software developed by the University of  *    California, Berkeley and its contributors."  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_PCMAP_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_PCMAP_REGS_H__
end_define

begin_include
include|#
directive|include
file|"opt_cputype.h"
end_include

begin_define
define|#
directive|define
name|OCTEON_CACHE_LINE_SIZE
value|0x80
end_define

begin_comment
comment|/* 128 bytes cache line size */
end_comment

begin_define
define|#
directive|define
name|IS_OCTEON_ALIGNED
parameter_list|(
name|p
parameter_list|)
value|(!((u_long)(p)& 0x7f))
end_define

begin_define
define|#
directive|define
name|OCTEON_ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((u_long)(p) + ((OCTEON_CACHE_LINE_SIZE) - 1))& ~((OCTEON_CACHE_LINE_SIZE) - 1))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/* XXXimp: From Cavium's include/pcpu.h, need to port that over */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OCTEON_SMP
end_ifndef

begin_define
define|#
directive|define
name|OCTEON_CORE_ID
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|struct
name|pcpu
modifier|*
name|cpuid_to_pcpu
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OCTEON_CORE_ID
value|(mips_rd_coreid())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Utility inlines& macros  */
end_comment

begin_comment
comment|/* turn the variable name into a string */
end_comment

begin_define
define|#
directive|define
name|OCTEON_TMP_STR
parameter_list|(
name|x
parameter_list|)
value|OCTEON_TMP_STR2(x)
end_define

begin_define
define|#
directive|define
name|OCTEON_TMP_STR2
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|OCTEON_PREFETCH_PREF0
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
define|\
value|__asm __volatile (	".set mips64\n"	     \ 			".set noreorder\n"   \ 			"pref 0, " OCTEON_TMP_STR(offset) "(%0)\n" \ 			".set reorder\n"     \ 			".set mips0\n"	     \ 			 : \ 			 : "r" (address) );
end_define

begin_define
define|#
directive|define
name|OCTEON_PREFETCH
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|OCTEON_PREFETCH_PREF0(address,offset)
end_define

begin_define
define|#
directive|define
name|OCTEON_PREFETCH0
parameter_list|(
name|address
parameter_list|)
value|OCTEON_PREFETCH(address, 0)
end_define

begin_define
define|#
directive|define
name|OCTEON_PREFETCH128
parameter_list|(
name|address
parameter_list|)
value|OCTEON_PREFETCH(address, 128)
end_define

begin_define
define|#
directive|define
name|OCTEON_SYNCIOBDMA
value|__asm __volatile (".word 0x8f" : : :"memory")
end_define

begin_define
define|#
directive|define
name|OCTEON_SYNCW
value|__asm __volatile (".word  0x10f" : : )
end_define

begin_define
define|#
directive|define
name|OCTEON_SYNCW
value|__asm __volatile (".word  0x10f" : : )
end_define

begin_define
define|#
directive|define
name|OCTEON_SYNCWS
value|__asm __volatile (".word  0x14f" : : )
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_function
specifier|static
specifier|inline
name|void
name|oct_write64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint64_t
name|val64
parameter_list|)
block|{
name|uint64_t
modifier|*
name|ptr
init|=
operator|(
name|uint64_t
operator|*
operator|)
name|csr_addr
decl_stmt|;
operator|*
name|ptr
operator|=
name|val64
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|oct_write64_int64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|int64_t
name|val64i
parameter_list|)
block|{
name|int64_t
modifier|*
name|ptr
init|=
operator|(
name|int64_t
operator|*
operator|)
name|csr_addr
decl_stmt|;
operator|*
name|ptr
operator|=
name|val64i
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|oct_write8_x8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint8_t
name|val8
parameter_list|)
block|{
name|uint64_t
modifier|*
name|ptr
init|=
operator|(
name|uint64_t
operator|*
operator|)
name|csr_addr
decl_stmt|;
operator|*
name|ptr
operator|=
operator|(
name|uint64_t
operator|)
name|val8
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|oct_write8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint8_t
name|val8
parameter_list|)
block|{
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val8
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|oct_write16
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint16_t
name|val16
parameter_list|)
block|{
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val16
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|oct_write32
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint32_t
name|val32
parameter_list|)
block|{
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val32
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint8_t
name|oct_read8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint8_t
modifier|*
name|ptr
init|=
operator|(
name|uint8_t
operator|*
operator|)
name|csr_addr
decl_stmt|;
return|return
operator|(
operator|*
name|ptr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint8_t
name|oct_read16
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint16_t
modifier|*
name|ptr
init|=
operator|(
name|uint16_t
operator|*
operator|)
name|csr_addr
decl_stmt|;
return|return
operator|(
operator|*
name|ptr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|oct_read32
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint32_t
modifier|*
name|ptr
init|=
operator|(
name|uint32_t
operator|*
operator|)
name|csr_addr
decl_stmt|;
return|return
operator|(
operator|*
name|ptr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|oct_read64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint64_t
modifier|*
name|ptr
init|=
operator|(
name|uint64_t
operator|*
operator|)
name|csr_addr
decl_stmt|;
return|return
operator|(
operator|*
name|ptr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int32_t
name|oct_readint32
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|int32_t
modifier|*
name|ptr
init|=
operator|(
name|int32_t
operator|*
operator|)
name|csr_addr
decl_stmt|;
return|return
operator|(
operator|*
name|ptr
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  ABI o32 */
end_comment

begin_comment
comment|/*  * Read/write functions  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|oct_write64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint64_t
name|val64
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|valh
init|=
operator|(
name|uint64_t
operator|)
name|val64
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|vall
init|=
name|val64
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|;
name|uint32_t
name|tmp2
decl_stmt|;
name|uint32_t
name|tmp3
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsll   %1, %5, 32\n"
literal|"dsll   %2, %4, 32\n"
literal|"dsrl   %2, %2, 32\n"
literal|"or     %0, %0, %2\n"
literal|"dsll   %2, %6, 32\n"
literal|"dsrl   %2, %2, 32\n"
literal|"or     %1, %1, %2\n"
literal|"sd     %0, 0(%1)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp3
operator|)
operator|:
literal|"r"
operator|(
name|valh
operator|)
operator|,
literal|"r"
operator|(
name|vall
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
specifier|inline
name|void
name|oct_write64_int64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|int64_t
name|val64i
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|int32_t
name|valh
init|=
operator|(
name|uint64_t
operator|)
name|val64i
operator|>>
literal|32
decl_stmt|;
name|int32_t
name|vall
init|=
name|val64i
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|;
name|uint32_t
name|tmp2
decl_stmt|;
name|uint32_t
name|tmp3
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsll   %1, %5, 32\n"
literal|"dsll   %2, %4, 32\n"
literal|"dsrl   %2, %2, 32\n"
literal|"or     %0, %0, %2\n"
literal|"dsll   %2, %6, 32\n"
literal|"dsrl   %2, %2, 32\n"
literal|"or     %1, %1, %2\n"
literal|"sd     %0, 0(%1)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp3
operator|)
operator|:
literal|"r"
operator|(
name|valh
operator|)
operator|,
literal|"r"
operator|(
name|vall
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_comment
unit|}
comment|/*  * oct_write8_x8  *  * 8 bit data write into IO Space. Written using an 8 bit bus io transaction  */
end_comment

begin_function
unit|static
specifier|inline
name|void
name|oct_write8_x8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint8_t
name|val8
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|;
name|uint32_t
name|tmp2
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsll   %1, %4, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"sb     %2, 0(%0)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|val8
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_comment
unit|}
comment|/*  * oct_write8  *  * 8 bit data write into IO Space. Written using a 64 bit bus io transaction  */
end_comment

begin_function
unit|static
specifier|inline
name|void
name|oct_write8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint8_t
name|val8
parameter_list|)
block|{
if|#
directive|if
literal|1
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val8
argument_list|)
expr_stmt|;
else|#
directive|else
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|;
name|uint32_t
name|tmp2
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsll   %1, %4, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"sb     %2, 0(%0)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|val8
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|}  static
specifier|inline
name|void
name|oct_write16
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint16_t
name|val16
parameter_list|)
block|{
if|#
directive|if
literal|1
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val16
argument_list|)
expr_stmt|;
else|#
directive|else
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|;
name|uint32_t
name|tmp2
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsll   %1, %4, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"sh     %2, 0(%0)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|val16
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|}  static
specifier|inline
name|void
name|oct_write32
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint32_t
name|val32
parameter_list|)
block|{
if|#
directive|if
literal|1
name|oct_write64
argument_list|(
name|csr_addr
argument_list|,
operator|(
name|uint64_t
operator|)
name|val32
argument_list|)
expr_stmt|;
else|#
directive|else
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|;
name|uint32_t
name|tmp2
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsll   %1, %4, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"sw     %2, 0(%0)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|val32
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|}    static
specifier|inline
name|uint8_t
name|oct_read8
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|,
name|tmp2
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %1, %2, 32\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsrl   %0, %0, 32\n"
literal|"or     %1, %1, %0\n"
literal|"lb     %1, 0(%1)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|(
name|uint8_t
operator|)
name|tmp2
operator|)
return|;
end_return

begin_function
unit|}  static
specifier|inline
name|uint8_t
name|oct_read16
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|tmp1
decl_stmt|,
name|tmp2
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %1, %2, 32\n"
literal|"dsll   %0, %3, 32\n"
literal|"dsrl   %0, %0, 32\n"
literal|"or     %1, %1, %0\n"
literal|"lh     %1, 0(%1)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|(
name|uint16_t
operator|)
name|tmp2
operator|)
return|;
end_return

begin_function
unit|}   static
specifier|inline
name|uint32_t
name|oct_read32
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|val32
decl_stmt|;
name|uint32_t
name|tmp
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %2, 32\n"
literal|"dsll   %1, %3, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"lw    %0, 0(%0)\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|val32
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|val32
operator|)
return|;
end_return

begin_function
unit|}   static
specifier|inline
name|uint64_t
name|oct_read64
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|uint32_t
name|valh
decl_stmt|;
name|uint32_t
name|vall
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %2, 32\n"
literal|"dsll   %1, %3, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"ld     %1, 0(%0)\n"
literal|"dsrl   %0, %1, 32\n"
literal|"dsll   %1, %1, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|".set mips0\n"
operator|:
literal|"=&r"
operator|(
name|valh
operator|)
operator|,
literal|"=&r"
operator|(
name|vall
operator|)
operator|:
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|(
name|uint64_t
operator|)
name|valh
operator|<<
literal|32
operator|)
operator||
name|vall
return|;
end_return

begin_function
unit|}   static
specifier|inline
name|int32_t
name|oct_readint32
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
block|{
name|uint32_t
name|csr_addrh
init|=
name|csr_addr
operator|>>
literal|32
decl_stmt|;
name|uint32_t
name|csr_addrl
init|=
name|csr_addr
decl_stmt|;
name|int32_t
name|val32
decl_stmt|;
name|uint32_t
name|tmp
decl_stmt|;
asm|__asm __volatile (
literal|".set mips64\n"
literal|"dsll   %0, %2, 32\n"
literal|"dsll   %1, %3, 32\n"
literal|"dsrl   %1, %1, 32\n"
literal|"or     %0, %0, %1\n"
literal|"lw    %0, 0(%0)\n"
operator|:
literal|"=&r"
operator|(
name|val32
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
literal|"r"
operator|(
name|csr_addrh
operator|)
operator|,
literal|"r"
operator|(
name|csr_addrl
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|val32
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OCTEON_HW_BASE
value|((volatile uint64_t *) 0L)
end_define

begin_define
define|#
directive|define
name|OCTEON_REG_OFFSET
value|(-4 * 1024ll)
end_define

begin_comment
comment|/* local scratchpad reg base */
end_comment

begin_define
define|#
directive|define
name|OCTEON_SCRATCH_BASE
value|((volatile uint8_t *)(OCTEON_HW_BASE +	\                                                       OCTEON_REG_OFFSET))
end_define

begin_define
define|#
directive|define
name|OCTEON_SCR_SCRATCH
value|8
end_define

begin_define
define|#
directive|define
name|OCTEON_SCRATCH_0
value|16
end_define

begin_define
define|#
directive|define
name|OCTEON_SCRATCH_1
value|24
end_define

begin_define
define|#
directive|define
name|OCTEON_SCRATCH_2
value|32
end_define

begin_function
unit|static
specifier|inline
name|uint64_t
name|oct_mf_chord
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|dest
decl_stmt|;
asm|__asm __volatile (	".set push\n"
literal|".set noreorder\n"
literal|".set noat\n"
literal|".set mips64\n"
literal|"dmfc2 $1, 0x400\n"
literal|"move %0, $1\n"
literal|".set pop\n"
operator|:
literal|"=r"
operator|(
name|dest
operator|)
operator|:
operator|:
literal|"$1"
block|)
function|;
end_function

begin_return
return|return
name|dest
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|MIPS64_DMFCz
parameter_list|(
name|cop
parameter_list|,
name|regnum
parameter_list|,
name|cp0reg
parameter_list|,
name|select
parameter_list|)
define|\
value|.word   (0x40200000 | (cop<< 25) | (regnum<< 16) | (cp0reg<< 11) | select)
end_define

begin_define
define|#
directive|define
name|mips64_getcpz_xstr
parameter_list|(
name|s
parameter_list|)
value|mips64_getcpz_str(s)
end_define

begin_define
define|#
directive|define
name|mips64_getcpz_str
parameter_list|(
name|s
parameter_list|)
value|#s
end_define

begin_define
define|#
directive|define
name|mips64_dgetcpz
parameter_list|(
name|cop
parameter_list|,
name|cpzreg
parameter_list|,
name|sel
parameter_list|,
name|val_ptr
parameter_list|)
define|\
value|({ __asm __volatile( \             ".set push\n" \             ".set mips3\n" \             ".set noreorder\n" \             ".set noat\n" \             mips64_getcpz_xstr(MIPS64_DMFCz(cop,1,cpzreg,sel)) "\n" \             "nop\n" \             "nop\n" \             "nop\n" \             "nop\n" \             "sd $1,0(%0)\n" \             ".set pop" \             :
comment|/* no outputs */
value|: "r" (val_ptr) : "$1"); \     })
end_define

begin_define
define|#
directive|define
name|mips64_dgetcp2
parameter_list|(
name|cp2reg
parameter_list|,
name|sel
parameter_list|,
name|retval_ptr
parameter_list|)
define|\
value|mips64_dgetcpz(2,cp2reg,sel,retval_ptr)
end_define

begin_define
define|#
directive|define
name|OCTEON_MF_CHORD
parameter_list|(
name|dest
parameter_list|)
value|mips64_dgetcp2(0x400, 0,&dest)
end_define

begin_define
define|#
directive|define
name|OCTEON_RDHWR
parameter_list|(
name|result
parameter_list|,
name|regstr
parameter_list|)
define|\
value|__asm __volatile (		\         		".set mips3\n"		\ 			"rdhwr %0,$" OCTEON_TMP_STR(regstr) "\n"	\         		".set mips\n"		\ 			 : "=d" (result));
end_define

begin_define
define|#
directive|define
name|CVMX_MF_CHORD
parameter_list|(
name|dest
parameter_list|)
value|OCTEON_RDHWR(dest, 30)
end_define

begin_define
define|#
directive|define
name|OCTEON_CHORD_HEX
parameter_list|(
name|dest_ptr
parameter_list|)
define|\
value|({ __asm __volatile( \             ".set push\n" \             ".set mips3\n" \             ".set noreorder\n" \             ".set noat\n" \ 	    ".word 0x7c02f03b \n"\             "nop\n" \             "nop\n" \             "nop\n" \             "nop\n" \             "sd $2,0(%0)\n" \             ".set pop" \             :
comment|/* no outputs */
value|: "r" (dest_ptr) : "$2"); \     })
end_define

begin_define
define|#
directive|define
name|OCTEON_MF_CHORD_BAD
parameter_list|(
name|dest
parameter_list|)
define|\
value|__asm __volatile (		\         		".set mips3\n"		\ 			"dmfc2 %0, 0x400\n"	\         		".set mips0\n"		\  			: "=&r" (dest) : )
end_define

begin_function
unit|static
specifier|inline
name|uint64_t
name|oct_scratch_read64
parameter_list|(
name|uint64_t
name|address
parameter_list|)
block|{
return|return
operator|(
operator|*
operator|(
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
operator|(
name|OCTEON_SCRATCH_BASE
operator|+
name|address
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|oct_scratch_write64
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
operator|*
operator|(
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
operator|(
name|OCTEON_SCRATCH_BASE
operator|+
name|address
operator|)
operator|)
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|OCTEON_READ_CSR32
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|addr_ptr = addr; \ 	oct_read_32_ptr(&addr_ptr,&val);
end_define

begin_define
define|#
directive|define
name|OCTEON_WRITE_CSR32
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|,
name|val_dummy
parameter_list|)
define|\
value|addr_ptr = addr; \ 	oct_write_32_ptr(&addr_ptr,&val); \ 	oct_read64(OCTEON_MIO_BOOT_BIST_STAT);
end_define

begin_comment
comment|/*  * Octeon Address Space Definitions  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|OCTEON_MIPS_SPACE_XKSEG
init|=
literal|3LL
block|,
name|OCTEON_MIPS_SPACE_XKPHYS
init|=
literal|2LL
block|,
name|OCTEON_MIPS_SPACE_XSSEG
init|=
literal|1LL
block|,
name|OCTEON_MIPS_SPACE_XUSEG
init|=
literal|0LL
block|}
name|octeon_mips_space_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|OCTEON_MIPS_XKSEG_SPACE_KSEG0
init|=
literal|0LL
block|,
name|OCTEON_MIPS_XKSEG_SPACE_KSEG1
init|=
literal|1LL
block|,
name|OCTEON_MIPS_XKSEG_SPACE_SSEG
init|=
literal|2LL
block|,
name|OCTEON_MIPS_XKSEG_SPACE_KSEG3
init|=
literal|3LL
block|}
name|octeon_mips_xkseg_space_t
typedef|;
end_typedef

begin_comment
comment|/* ***********************************************************************  * 32 bit mode alert  * The kseg0 calc below might fail in xkphys.  */
end_comment

begin_comment
comment|/*  * We limit the allocated device physical blocks to low mem. So use Kseg0  */
end_comment

begin_comment
comment|/*  * Need to go back to kernel to find v->p mappings& vice-versa  * We are getting non 1-1 mappings.  * #define OCTEON_PTR2PHYS(addr)  ((unsigned long) addr& 0x7fffffff)  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_PTR2PHYS
parameter_list|(
name|addr
parameter_list|)
value|octeon_ptr_to_phys(addr)
end_define

begin_comment
comment|/*  PTR_SIZE == sizeof(uint32_t)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISA_MIPS32
end_ifdef

begin_define
define|#
directive|define
name|mipsx_addr_size
value|uint32_t
end_define

begin_comment
comment|// u_int64
end_comment

begin_define
define|#
directive|define
name|MIPSX_ADDR_SIZE_KSEGX_BIT_SHIFT
value|30
end_define

begin_comment
comment|// 62
end_comment

begin_define
define|#
directive|define
name|MIPSX_ADDR_SIZE_KSEGX_MASK_REMOVED
value|0x1fffffff
end_define

begin_comment
comment|// 0x1fffffff
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mipsx_addr_size
value|uint64_t
end_define

begin_define
define|#
directive|define
name|MIPSX_ADDR_SIZE_KSEGX_BIT_SHIFT
value|62
end_define

begin_define
define|#
directive|define
name|MIPSX_ADDR_SIZE_KSEGX_MASK_REMOVED
value|0x1fffffffffffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|octeon_ptr_to_phys
parameter_list|(
name|ptr
parameter_list|)
define|\
value|((((mipsx_addr_size) ptr)>> MIPSX_ADDR_SIZE_KSEGX_BIT_SHIFT) == 2) ? \     	((mipsx_addr_size) ptr& MIPSX_ADDR_SIZE_KSEGX_MASK_REMOVED)  :   \     	(vtophys(ptr))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CODE_FOR_64_BIT_NEEDED
end_ifdef

begin_function
specifier|static
specifier|inline
name|mipsx_addr_size
name|octeon_ptr_to_phys
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
if|if
condition|(
operator|(
operator|(
operator|(
name|mipsx_addr_size
operator|)
name|ptr
operator|)
operator|>>
name|MIPSX_ADDR_SIZE_KSEGX_BIT_SHIFT
operator|)
operator|==
literal|2
condition|)
block|{
comment|/*          * KSEG0 based address ?          */
return|return
operator|(
operator|(
name|mipsx_addr_size
operator|)
name|ptr
operator|&
name|MIPSX_ADDR_SIZE_KSEGX_MASK_REMOVED
operator|)
return|;
block|}
else|else
block|{
comment|/*          * Ask kernel/vm to give us the phys translation.          */
return|return
operator|(
name|vtophys
argument_list|(
name|ptr
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OCTEON_IO_SEG
value|OCTEON_MIPS_SPACE_XKPHYS
end_define

begin_define
define|#
directive|define
name|OCTEON_ADD_SEG
parameter_list|(
name|segment
parameter_list|,
name|add
parameter_list|)
value|((((uint64_t)segment)<< 62) | (add))
end_define

begin_define
define|#
directive|define
name|OCTEON_ADD_IO_SEG
parameter_list|(
name|add
parameter_list|)
value|OCTEON_ADD_SEG(OCTEON_IO_SEG, (add))
end_define

begin_define
define|#
directive|define
name|OCTEON_ADDR_DID
parameter_list|(
name|did
parameter_list|)
value|(OCTEON_ADDR_DIDSPACE(did)<< 40)
end_define

begin_define
define|#
directive|define
name|OCTEON_ADDR_DIDSPACE
parameter_list|(
name|did
parameter_list|)
value|(((OCTEON_IO_SEG)<< 22) | ((1ULL)<< 8) | (did))
end_define

begin_define
define|#
directive|define
name|OCTEON_ADDR_FULL_DID
parameter_list|(
name|did
parameter_list|,
name|subdid
parameter_list|)
value|(((did)<< 3) | (subdid))
end_define

begin_define
define|#
directive|define
name|OCTEON_CIU_PP_RST
value|OCTEON_ADD_IO_SEG(0x0001070000000700ull)
end_define

begin_define
define|#
directive|define
name|OCTEON_CIU_SOFT_RST
value|OCTEON_ADD_IO_SEG(0x0001070000000740ull)
end_define

begin_define
define|#
directive|define
name|OCTEON_OCTEON_DID_TAG
value|12ULL
end_define

begin_comment
comment|/*  * octeon_addr_t  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|octeon_mips_space_t
name|R
range|:
literal|2
decl_stmt|;
name|uint64_t
name|offset
range|:
literal|62
decl_stmt|;
block|}
name|sva
struct|;
comment|// mapped or unmapped virtual address
struct|struct
block|{
name|uint64_t
name|zeroes
range|:
literal|33
decl_stmt|;
name|uint64_t
name|offset
range|:
literal|31
decl_stmt|;
block|}
name|suseg
struct|;
comment|// mapped USEG virtual addresses (typically)
struct|struct
block|{
name|uint64_t
name|ones
range|:
literal|33
decl_stmt|;
name|octeon_mips_xkseg_space_t
name|sp
range|:
literal|2
decl_stmt|;
name|uint64_t
name|offset
range|:
literal|29
decl_stmt|;
block|}
name|sxkseg
struct|;
comment|// mapped or unmapped virtual address
struct|struct
block|{
name|octeon_mips_space_t
name|R
range|:
literal|2
decl_stmt|;
comment|// CVMX_MIPS_SPACE_XKPHYS in this case
name|uint64_t
name|cca
range|:
literal|3
decl_stmt|;
comment|// ignored by octeon
name|uint64_t
name|mbz
range|:
literal|10
decl_stmt|;
name|uint64_t
name|pa
range|:
literal|49
decl_stmt|;
comment|// physical address
block|}
name|sxkphys
struct|;
comment|// physical address accessed through xkphys unmapped virtual address
struct|struct
block|{
name|uint64_t
name|mbz
range|:
literal|15
decl_stmt|;
name|uint64_t
name|is_io
range|:
literal|1
decl_stmt|;
comment|// if set, the address is uncached and resides on MCB bus
name|uint64_t
name|did
range|:
literal|8
decl_stmt|;
comment|// the hardware ignores this field when is_io==0, else device ID
name|uint64_t
name|unaddr
range|:
literal|4
decl_stmt|;
comment|// the hardware ignores<39:36> in Octeon I
name|uint64_t
name|offset
range|:
literal|36
decl_stmt|;
block|}
name|sphys
struct|;
comment|// physical address
struct|struct
block|{
name|uint64_t
name|zeroes
range|:
literal|24
decl_stmt|;
comment|// techically,<47:40> are dont-cares
name|uint64_t
name|unaddr
range|:
literal|4
decl_stmt|;
comment|// the hardware ignores<39:36> in Octeon I
name|uint64_t
name|offset
range|:
literal|36
decl_stmt|;
block|}
name|smem
struct|;
comment|// physical mem address
struct|struct
block|{
name|uint64_t
name|mem_region
range|:
literal|2
decl_stmt|;
name|uint64_t
name|mbz
range|:
literal|13
decl_stmt|;
name|uint64_t
name|is_io
range|:
literal|1
decl_stmt|;
comment|// 1 in this case
name|uint64_t
name|did
range|:
literal|8
decl_stmt|;
comment|// the hardware ignores this field when is_io==0, else device ID
name|uint64_t
name|unaddr
range|:
literal|4
decl_stmt|;
comment|// the hardware ignores<39:36> in Octeon I
name|uint64_t
name|offset
range|:
literal|36
decl_stmt|;
block|}
name|sio
struct|;
comment|// physical IO address
struct|struct
block|{
name|uint64_t
name|didspace
range|:
literal|24
decl_stmt|;
name|uint64_t
name|unused
range|:
literal|40
decl_stmt|;
block|}
name|sfilldidspace
struct|;
block|}
name|octeon_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|word32hi
decl_stmt|;
name|uint32_t
name|word32lo
decl_stmt|;
block|}
name|bits
struct|;
block|}
name|octeon_word_t
typedef|;
end_typedef

begin_comment
comment|/*  * octeon_build_io_address  *  * Builds a memory address for I/O based on the Major 5bits and Sub DID 3bits  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|octeon_build_io_address
parameter_list|(
name|uint64_t
name|major_did
parameter_list|,
name|uint64_t
name|sub_did
parameter_list|)
block|{
return|return
operator|(
operator|(
literal|0x1ull
operator|<<
literal|48
operator|)
operator||
operator|(
name|major_did
operator|<<
literal|43
operator|)
operator||
operator|(
name|sub_did
operator|<<
literal|40
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * octeon_build_mask  *  * Builds a bit mask given the required size in bits.  *  * @param bits   Number of bits in the mask  * @return The mask  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|octeon_build_mask
parameter_list|(
name|uint64_t
name|bits
parameter_list|)
block|{
return|return
operator|~
operator|(
operator|(
operator|~
literal|0x0ull
operator|)
operator|<<
name|bits
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * octeon_build_bits  *  * Perform mask and shift to place the supplied value into  * the supplied bit rage.  *  * Example: octeon_build_bits(39,24,value)  *<pre>  * 6       5       4       3       3       2       1  * 3       5       7       9       1       3       5       7      0  * +-------+-------+-------+-------+-------+-------+-------+------+  * 000000000000000000000000___________value000000000000000000000000  *</pre>  *  * @param high_bit Highest bit value can occupy (inclusive) 0-63  * @param low_bit  Lowest bit value can occupy inclusive 0-high_bit  * @param value    Value to use  * @return Value masked and shifted  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|octeon_build_bits
parameter_list|(
name|uint64_t
name|high_bit
parameter_list|,
name|uint64_t
name|low_bit
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
return|return
operator|(
operator|(
name|value
operator|&
name|octeon_build_mask
argument_list|(
name|high_bit
operator|-
name|low_bit
operator|+
literal|1
argument_list|)
operator|)
operator|<<
name|low_bit
operator|)
return|;
block|}
end_function

begin_comment
comment|/**********************  simple spinlocks ***************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|value
decl_stmt|;
block|}
name|octeon_spinlock_t
typedef|;
end_typedef

begin_comment
comment|// note - macros not expanded in inline ASM, so values hardcoded
end_comment

begin_define
define|#
directive|define
name|OCTEON_SPINLOCK_UNLOCKED_VAL
value|0
end_define

begin_define
define|#
directive|define
name|OCTEON_SPINLOCK_LOCKED_VAL
value|1
end_define

begin_comment
comment|/**  * Initialize a spinlock  *  * @param lock   Lock to initialize  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_spinlock_init
parameter_list|(
name|octeon_spinlock_t
modifier|*
name|lock
parameter_list|)
block|{
name|lock
operator|->
name|value
operator|=
name|OCTEON_SPINLOCK_UNLOCKED_VAL
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Releases lock  *  * @param lock   pointer to lock structure  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_spinlock_unlock
parameter_list|(
name|octeon_spinlock_t
modifier|*
name|lock
parameter_list|)
block|{
name|OCTEON_SYNCWS
expr_stmt|;
name|lock
operator|->
name|value
operator|=
literal|0
expr_stmt|;
name|OCTEON_SYNCWS
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Gets lock, spins until lock is taken  *  * @param lock   pointer to lock structure  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_spinlock_lock
parameter_list|(
name|octeon_spinlock_t
modifier|*
name|lock
parameter_list|)
block|{
name|unsigned
name|int
name|tmp
decl_stmt|;
asm|__asm __volatile(
literal|".set noreorder         \n"
literal|"1: ll   %1, %0  \n"
literal|"   bnez %1, 1b     \n"
literal|"   li   %1, 1      \n"
literal|"   sc   %1, %0 \n"
literal|"   beqz %1, 1b     \n"
literal|"   nop                \n"
literal|".set reorder           \n"
operator|:
literal|"+m"
operator|(
name|lock
operator|->
name|value
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_comment
unit|}
comment|/********************** end simple spinlocks ***************/
end_comment

begin_comment
comment|/* ------------------------------------------------------------------- *  *                      octeon_get_chipid()                               *  * ------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|OCTEON_CN31XX_CHIP
value|0x000d0100
end_define

begin_define
define|#
directive|define
name|OCTEON_CN30XX_CHIP
value|0x000d0200
end_define

begin_define
define|#
directive|define
name|OCTEON_CN3020_CHIP
value|0x000d0112
end_define

begin_define
define|#
directive|define
name|OCTEON_CN5020_CHIP
value|0x000d0601
end_define

begin_function
unit|static
specifier|inline
name|uint32_t
name|octeon_get_chipid
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|id
decl_stmt|;
asm|__asm __volatile ("mfc0 %0, $15,0" : "=r" (id));
return|return
operator|(
name|id
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|octeon_get_except_base_reg
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
asm|__asm volatile (
literal|"    .set mips64r2            \n"
literal|"    .set noreorder         \n"
literal|"    mfc0   %0, $15, 1  \n"
literal|"    .set reorder           \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
block|)
function|;
end_function

begin_return
return|return
operator|(
name|tmp
operator|)
return|;
end_return

begin_function
unit|}     static
specifier|inline
name|unsigned
name|int
name|get_coremask
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|~
operator|(
name|oct_read64
argument_list|(
name|OCTEON_CIU_PP_RST
argument_list|)
operator|)
operator|&
literal|0xffff
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|octeon_get_core_num
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0x3FF
operator|&
name|octeon_get_except_base_reg
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|octeon_get_cycle
parameter_list|(
name|void
parameter_list|)
block|{
comment|/*  ABI == 32 */
name|uint32_t
name|tmp_low
decl_stmt|,
name|tmp_hi
decl_stmt|;
asm|__asm __volatile (
literal|"   .set push                  \n"
literal|"   .set mips64r2                \n"
literal|"   .set noreorder               \n"
literal|"   rdhwr %[tmpl], $31           \n"
literal|"   dadd  %[tmph], %[tmpl], $0   \n"
literal|"   dsrl  %[tmph], 32            \n"
literal|"   dsll  %[tmpl], 32            \n"
literal|"   dsrl  %[tmpl], 32            \n"
literal|"   .set pop                 \n"
operator|:
index|[
name|tmpl
index|]
literal|"=&r"
operator|(
name|tmp_low
operator|)
operator|,
index|[
name|tmph
index|]
literal|"=&r"
operator|(
name|tmp_hi
operator|)
operator|:
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|tmp_hi
operator|<<
literal|32
operator|)
operator|+
name|tmp_low
operator|)
return|;
end_return

begin_comment
unit|}
comment|/**  * Wait for the specified number of cycle  *  * @param cycles  */
end_comment

begin_function
unit|static
specifier|inline
name|void
name|octeon_wait
parameter_list|(
name|uint64_t
name|cycles
parameter_list|)
block|{
name|uint64_t
name|done
init|=
name|octeon_get_cycle
argument_list|()
operator|+
name|cycles
decl_stmt|;
while|while
condition|(
name|octeon_get_cycle
argument_list|()
operator|<
name|done
condition|)
block|{
comment|/* Spin */
block|}
block|}
end_function

begin_comment
comment|/*  * octeon_machdep.c  *  * Direct to Board Support level.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_char
parameter_list|(
name|int
name|char_position
parameter_list|,
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_hexchar
parameter_list|(
name|int
name|char_position
parameter_list|,
name|char
name|hexval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_hex
parameter_list|(
name|uint32_t
name|wl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_string
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_uart_write_byte
parameter_list|(
name|int
name|uart_index
parameter_list|,
name|uint8_t
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_uart_write_string
parameter_list|(
name|int
name|uart_index
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_uart_write_hex
parameter_list|(
name|uint32_t
name|wl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_uart_write_hex2
parameter_list|(
name|uint32_t
name|wl
parameter_list|,
name|uint32_t
name|wh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_wait_uart_flush
parameter_list|(
name|int
name|uart_index
parameter_list|,
name|uint8_t
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_uart_write_byte0
parameter_list|(
name|uint8_t
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_write_char0
parameter_list|(
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_led_run_wheel
parameter_list|(
name|int
modifier|*
name|pos
parameter_list|,
name|int
name|led_position
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_debug_symbol
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_disable_interrupt_controls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint32_t
name|octeon_cpu_clock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|octeon_dram
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|octeon_bd_ver
decl_stmt|,
name|octeon_board_rev_major
decl_stmt|,
name|octeon_board_rev_minor
decl_stmt|,
name|octeon_board_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint8_t
name|octeon_mac_addr
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|octeon_core_mask
decl_stmt|,
name|octeon_mac_addr_count
decl_stmt|,
name|octeon_chip_rev_major
decl_stmt|,
name|octeon_chip_rev_minor
decl_stmt|,
name|octeon_chip_type
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|bzero_64
parameter_list|(
name|void
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bzero_32
parameter_list|(
name|void
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bzero_16
parameter_list|(
name|void
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bzero_old
parameter_list|(
name|void
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_ciu_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ciu_disable_intr
parameter_list|(
name|int
name|core_num
parameter_list|,
name|int
name|intx
parameter_list|,
name|int
name|enx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ciu_enable_interrupts
parameter_list|(
name|int
name|core_num
parameter_list|,
name|int
name|intx
parameter_list|,
name|int
name|enx
parameter_list|,
name|uint64_t
name|set_these_interrupt_bits
parameter_list|,
name|int
name|ciu_ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ciu_clear_int_summary
parameter_list|(
name|int
name|core_num
parameter_list|,
name|int
name|intx
parameter_list|,
name|int
name|enx
parameter_list|,
name|uint64_t
name|write_bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|ciu_get_int_summary
parameter_list|(
name|int
name|core_num
parameter_list|,
name|int
name|intx
parameter_list|,
name|int
name|enx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_ciu_start_gtimer
parameter_list|(
name|int
name|timer
parameter_list|,
name|u_int
name|one_shot
parameter_list|,
name|uint64_t
name|time_cycles
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_ciu_stop_gtimer
parameter_list|(
name|int
name|timer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|octeon_board_real
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|octeon_get_clock_rate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|27
decl_stmt|;
comment|/* Not used */
name|uint64_t
name|one_shot
range|:
literal|1
decl_stmt|;
comment|/* Oneshot ? */
name|uint64_t
name|len
range|:
literal|36
decl_stmt|;
comment|/* len of timer in clock cycles - 1 */
block|}
name|bits
struct|;
block|}
name|octeon_ciu_gentimer
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/*  * R4K Address space definitions  */
end_comment

begin_define
define|#
directive|define
name|ADRSPC_K0BASE
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_K0SIZE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_K1BASE
value|(0xA0000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_K1SIZE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_KSBASE
value|(0xC0000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_KSSIZE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_K3BASE
value|(0xE0000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_K3SIZE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_KUBASE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|ADRSPC_KUSIZE
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|KSEG_MSB_ADDR
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|OCTEON_CLOCK_DEFAULT
value|(500 * 1000 * 1000)
end_define

begin_comment
comment|/*  * Octeon Boot Bus BIST Status  * Mostly used for dummy read to ensure all prev I/Os are write-complete.  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_MIO_BOOT_BIST_STAT
value|0x80011800000000F8ull
end_define

begin_comment
comment|/*  * Octeon UART unit  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_MIO_UART0
value|0x8001180000000800ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART1
value|0x8001180000000C00ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART0_THR
value|0x8001180000000840ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART1_THR
value|0x8001180000000C40ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART0_LSR
value|0x8001180000000828ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART1_LSR
value|0x8001180000000C28ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART0_RBR
value|0x8001180000000800ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART1_RBR
value|0x8001180000000C00ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART0_USR
value|0x8001180000000938ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART1_USR
value|0x8001180000000D38ull
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_ADDR_HI24
value|0x800118
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_UART_SIZE
value|0x400ull
end_define

begin_comment
comment|/*  * EBT3000 LED Unit  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_CHAR_LED_BASE_ADDR
value|(0x1d020000 | (0x1ffffffffull<< 31))
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_QUEUES
value|8
end_define

begin_comment
comment|/*  * Octeon FPA I/O Registers  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_FPA_CTL_STATUS
value|0x8001180028000050ull
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_FPF_SIZE
value|0x8001180028000058ull
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_FPF_MARKS
value|0x8001180028000000ull
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_INT_SUMMARY
value|0x8001180028000040ull
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_INT_ENABLE
value|0x8001180028000048ull
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_QUEUE_AVAILABLE
value|0x8001180028000098ull
end_define

begin_define
define|#
directive|define
name|OCTEON_FPA_PAGE_INDEX
value|0x80011800280000f0ull
end_define

begin_comment
comment|/*  * Octeon PKO Unit  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_PKO_REG_FLAGS
value|0x8001180050000000ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_REG_READ_IDX
value|0x8001180050000008ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_CMD_BUF
value|0x8001180050000010ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_GMX_PORT_MODE
value|0x8001180050000018ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_REG_CRC_ENABLE
value|0x8001180050000020ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_QUEUE_MODE
value|0x8001180050000048ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_QUEUE_PTRS
value|0x8001180050001000ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_COUNT0
value|0x8001180050001080ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_COUNT1
value|0x8001180050001088ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG0
value|0x8001180050001100ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG1
value|0x8001180050001108ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG2
value|0x8001180050001110ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG3
value|0x8001180050001118ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG4
value|0x8001180050001120ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG5
value|0x8001180050001128ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG6
value|0x8001180050001130ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG7
value|0x8001180050001138ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG8
value|0x8001180050001140ull
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_MEM_DEBUG9
value|0x8001180050001148ull
end_define

begin_comment
comment|/*  * Octeon IPD Unit  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_IPD_1ST_MBUFF_SKIP
value|0x80014F0000000000ull
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_NOT_1ST_MBUFF_SKIP
value|0x80014F0000000008ull
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_PACKET_MBUFF_SIZE
value|0x80014F0000000010ull
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_1ST_NEXT_PTR_BACK
value|0x80014F0000000150ull
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_2ND_NEXT_PTR_BACK
value|0x80014F0000000158ull
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_WQE_FPA_QUEUE
value|0x80014F0000000020ull
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_CTL_STATUS
value|0x80014F0000000018ull
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_QOSX_RED_MARKS
parameter_list|(
name|queue
parameter_list|)
value|(0x80014F0000000178ull + ((queue) * 8))
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_RED_Q_PARAM
parameter_list|(
name|queue
parameter_list|)
value|(0x80014F00000002E0ull + ((queue) * 8))
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_PORT_BP_PAGE_COUNT
parameter_list|(
name|port
parameter_list|)
value|(0x80014F0000000028ull + ((port) * 8))
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_BP_PORT_RED_END
value|0x80014F0000000328ull
end_define

begin_define
define|#
directive|define
name|OCTEON_IPD_RED_PORT_ENABLE
value|0x80014F00000002D8ull
end_define

begin_comment
comment|/*  * Octeon CIU Unit  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_CIU_ENABLE_BASE_ADDR
value|0x8001070000000200ull
end_define

begin_define
define|#
directive|define
name|OCTEON_CIU_SUMMARY_BASE_ADDR
value|0x8001070000000000ull
end_define

begin_define
define|#
directive|define
name|OCTEON_CIU_SUMMARY_INT1_ADDR
value|0x8001070000000108ull
end_define

begin_define
define|#
directive|define
name|OCTEON_CIU_MBOX_SETX
parameter_list|(
name|offset
parameter_list|)
value|(0x8001070000000600ull+((offset)*8))
end_define

begin_define
define|#
directive|define
name|OCTEON_CIU_MBOX_CLRX
parameter_list|(
name|offset
parameter_list|)
value|(0x8001070000000680ull+((offset)*8))
end_define

begin_define
define|#
directive|define
name|OCTEON_CIU_ENABLE_MBOX_INTR
value|0x0000000300000000ull
end_define

begin_comment
comment|/* bits 32, 33 */
end_comment

begin_define
define|#
directive|define
name|CIU_MIPS_IP2
value|0
end_define

begin_define
define|#
directive|define
name|CIU_MIPS_IP3
value|1
end_define

begin_define
define|#
directive|define
name|CIU_INT_0
value|CIU_MIPS_IP2
end_define

begin_define
define|#
directive|define
name|CIU_INT_1
value|CIU_MIPS_IP3
end_define

begin_define
define|#
directive|define
name|CIU_EN_0
value|0
end_define

begin_define
define|#
directive|define
name|CIU_EN_1
value|1
end_define

begin_define
define|#
directive|define
name|CIU_THIS_CORE
value|-1
end_define

begin_define
define|#
directive|define
name|CIU_UART_BITS_UART0
value|(0x1ull<< 34)
end_define

begin_comment
comment|// Bit 34
end_comment

begin_define
define|#
directive|define
name|CIU_UART_BITS_UART1
value|(0x1ull<< 35)
end_define

begin_comment
comment|// Bit 35
end_comment

begin_define
define|#
directive|define
name|CIU_GENTIMER_BITS_ENABLE
parameter_list|(
name|timer
parameter_list|)
value|(0x1ull<< (52 + (timer)))
end_define

begin_comment
comment|// Bit 52..55
end_comment

begin_define
define|#
directive|define
name|CIU_GENTIMER_NUM_0
value|0
end_define

begin_define
define|#
directive|define
name|CIU_GENTIMER_NUM_1
value|1
end_define

begin_define
define|#
directive|define
name|CIU_GENTIMER_NUM_2
value|2
end_define

begin_define
define|#
directive|define
name|CIU_GENTIMER_NUM_3
value|3
end_define

begin_define
define|#
directive|define
name|OCTEON_GENTIMER_ONESHOT
value|1
end_define

begin_define
define|#
directive|define
name|OCTEON_GENTIMER_PERIODIC
value|0
end_define

begin_define
define|#
directive|define
name|OCTEON_CIU_GENTIMER_ADDR
parameter_list|(
name|timer
parameter_list|)
value|(0x8001070000000480ull + ((timer) * 0x8))
end_define

begin_define
define|#
directive|define
name|OCTEON_GENTIMER_LEN_1MS
value|(0x7a120ull)
end_define

begin_comment
comment|/* Back of envelope. 500Mhz Octeon */
end_comment

begin_comment
comment|// FIXME IF WRONG
end_comment

begin_define
define|#
directive|define
name|OCTEON_GENTIMER_LEN_1SEC
value|((OCTEON_GENTIMER_LEN_1MS) * 1000)
end_define

begin_comment
comment|/*  * Physical Memory Banks  */
end_comment

begin_comment
comment|/* 1st BANK */
end_comment

begin_define
define|#
directive|define
name|OCTEON_DRAM_FIRST_256_START
value|0x00000000ull
end_define

begin_define
define|#
directive|define
name|OCTEON_DRAM_FIRST_256_END
value|(0x10000000ull - 1ull)
end_define

begin_define
define|#
directive|define
name|OCTEON_DRAM_RESERVED_END
value|0X1FFF000ULL
end_define

begin_comment
comment|/* 32 Meg Reserved for Mips Kernel MD Ops */
end_comment

begin_define
define|#
directive|define
name|OCTEON_DRAM_FIRST_BANK_SIZE
value|(OCTEON_DRAM_FIRST_256_END - OCTEON_DRAM_FIRST_256_START + 1)
end_define

begin_comment
comment|/* 2nd BANK */
end_comment

begin_define
define|#
directive|define
name|OCTEON_DRAM_SECOND_256_START
value|(0x0000000410000000ull)
end_define

begin_define
define|#
directive|define
name|OCTEON_DRAM_SECOND_256_END
value|(0x0000000420000000ull - 1ull)
end_define

begin_comment
comment|/* Requires 64 bit paddr */
end_comment

begin_define
define|#
directive|define
name|OCTEON_DRAM_SECOND_BANK_SIZE
value|(OCTEON_DRAM_SECOND_256_END - OCTEON_DRAM_SECOND_256_START + 1ull)
end_define

begin_comment
comment|/* 3rd BANK */
end_comment

begin_define
define|#
directive|define
name|OCTEON_DRAM_ABOVE_512_START
value|0x20000000ull
end_define

begin_define
define|#
directive|define
name|OCTEON_DRAM_ABOVE_512_END
value|(0x0000000300000000ull - 1ull)
end_define

begin_comment
comment|/* To be calculated as remaining */
end_comment

begin_define
define|#
directive|define
name|OCTEON_DRAM_THIRD_BANK_SIZE
value|(OCTEON_DRAM_ABOVE_512_END - OCTEON_DRAM_ABOVE_512_START + 1ull)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !OCTEON_PCMAP_REGS_H__ */
end_comment

end_unit

