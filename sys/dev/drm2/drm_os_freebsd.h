begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drm_os_freebsd.h  * OS abstraction macros.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_DRM_OS_FREEBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRM_OS_FREEBSD_H_
end_define

begin_include
include|#
directive|include
file|<sys/fbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|4321
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__user
end_ifndef

begin_define
define|#
directive|define
name|__user
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__iomem
end_ifndef

begin_define
define|#
directive|define
name|__iomem
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__always_unused
end_ifndef

begin_define
define|#
directive|define
name|__always_unused
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__must_check
end_ifndef

begin_define
define|#
directive|define
name|__must_check
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__force
end_ifndef

begin_define
define|#
directive|define
name|__force
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|uninitialized_var
end_ifndef

begin_define
define|#
directive|define
name|uninitialized_var
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|cpu_to_le16
parameter_list|(
name|x
parameter_list|)
value|htole16(x)
end_define

begin_define
define|#
directive|define
name|le16_to_cpu
parameter_list|(
name|x
parameter_list|)
value|le16toh(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_le32
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
end_define

begin_define
define|#
directive|define
name|le32_to_cpu
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_be16
parameter_list|(
name|x
parameter_list|)
value|htobe16(x)
end_define

begin_define
define|#
directive|define
name|be16_to_cpu
parameter_list|(
name|x
parameter_list|)
value|be16toh(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_be32
parameter_list|(
name|x
parameter_list|)
value|htobe32(x)
end_define

begin_define
define|#
directive|define
name|be32_to_cpu
parameter_list|(
name|x
parameter_list|)
value|be32toh(x)
end_define

begin_define
define|#
directive|define
name|be32_to_cpup
parameter_list|(
name|x
parameter_list|)
value|be32toh(*x)
end_define

begin_typedef
typedef|typedef
name|vm_paddr_t
name|dma_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|vm_paddr_t
name|resource_size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|wait_queue_head_t
value|atomic_t
end_define

begin_typedef
typedef|typedef
name|uint64_t
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|s8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__le16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__le32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__le64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__be16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__be64
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DRM_IRQ_ARGS
value|void *arg
end_define

begin_typedef
typedef|typedef
name|void
name|irqreturn_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IRQ_HANDLED
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|IRQ_NONE
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|__init
end_define

begin_define
define|#
directive|define
name|__exit
end_define

begin_define
define|#
directive|define
name|BUILD_BUG_ON
parameter_list|(
name|x
parameter_list|)
value|CTASSERT(!(x))
end_define

begin_define
define|#
directive|define
name|BUILD_BUG_ON_NOT_POWER_OF_2
parameter_list|(
name|x
parameter_list|)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WARN
end_ifndef

begin_define
define|#
directive|define
name|WARN
parameter_list|(
name|condition
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
value|({				\ 	int __ret_warn_on = !!(condition);			\ 	if (unlikely(__ret_warn_on))				\ 	DRM_ERROR(format, ##__VA_ARGS__);			\ 	unlikely(__ret_warn_on);				\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WARN_ONCE
parameter_list|(
name|condition
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WARN(condition, format, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WARN_ON
parameter_list|(
name|cond
parameter_list|)
value|WARN(cond, "WARN ON: " #cond)
end_define

begin_define
define|#
directive|define
name|WARN_ON_SMP
parameter_list|(
name|cond
parameter_list|)
value|WARN_ON(cond)
end_define

begin_define
define|#
directive|define
name|BUG
parameter_list|()
value|panic("BUG")
end_define

begin_define
define|#
directive|define
name|BUG_ON
parameter_list|(
name|cond
parameter_list|)
value|KASSERT(!(cond), ("BUG ON: " #cond " -> 0x%jx", (uintmax_t)(cond)))
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
end_define

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
end_define

begin_define
define|#
directive|define
name|container_of
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
value|({			\ 	__typeof( ((type *)0)->member ) *__mptr = (ptr);	\ 	(type *)( (char *)__mptr - offsetof(type,member) );})
end_define

begin_define
define|#
directive|define
name|KHZ2PICOS
parameter_list|(
name|a
parameter_list|)
value|(1000000000UL/(a))
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x)/sizeof(x[0]))
end_define

begin_define
define|#
directive|define
name|HZ
value|hz
end_define

begin_define
define|#
directive|define
name|DRM_HZ
value|hz
end_define

begin_define
define|#
directive|define
name|DRM_CURRENTPID
value|curthread->td_proc->p_pid
end_define

begin_define
define|#
directive|define
name|DRM_SUSER
parameter_list|(
name|p
parameter_list|)
value|(priv_check(p, PRIV_DRIVER) == 0)
end_define

begin_define
define|#
directive|define
name|udelay
parameter_list|(
name|usecs
parameter_list|)
value|DELAY(usecs)
end_define

begin_define
define|#
directive|define
name|mdelay
parameter_list|(
name|msecs
parameter_list|)
value|do { int loops = (msecs);		\ 				  while (loops--) DELAY(1000);		\ 				} while (0)
end_define

begin_define
define|#
directive|define
name|DRM_UDELAY
parameter_list|(
name|udelay
parameter_list|)
value|DELAY(udelay)
end_define

begin_define
define|#
directive|define
name|drm_msleep
parameter_list|(
name|x
parameter_list|,
name|msg
parameter_list|)
value|pause((msg), ((int64_t)(x)) * hz / 1000)
end_define

begin_define
define|#
directive|define
name|DRM_MSLEEP
parameter_list|(
name|msecs
parameter_list|)
value|drm_msleep((msecs), "drm_msleep")
end_define

begin_define
define|#
directive|define
name|get_seconds
parameter_list|()
value|time_second
end_define

begin_define
define|#
directive|define
name|ioread8
parameter_list|(
name|addr
parameter_list|)
value|*(volatile uint8_t *)((char *)addr)
end_define

begin_define
define|#
directive|define
name|ioread16
parameter_list|(
name|addr
parameter_list|)
value|*(volatile uint16_t *)((char *)addr)
end_define

begin_define
define|#
directive|define
name|ioread32
parameter_list|(
name|addr
parameter_list|)
value|*(volatile uint32_t *)((char *)addr)
end_define

begin_define
define|#
directive|define
name|iowrite8
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
value|*(volatile uint8_t *)((char *)addr) = data;
end_define

begin_define
define|#
directive|define
name|iowrite16
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
value|*(volatile uint16_t *)((char *)addr) = data;
end_define

begin_define
define|#
directive|define
name|iowrite32
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
value|*(volatile uint32_t *)((char *)addr) = data;
end_define

begin_define
define|#
directive|define
name|DRM_READ8
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
define|\
value|*(volatile u_int8_t *)(((vm_offset_t)(map)->handle) +		\ 	    (vm_offset_t)(offset))
end_define

begin_define
define|#
directive|define
name|DRM_READ16
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
define|\
value|le16toh(*(volatile u_int16_t *)(((vm_offset_t)(map)->handle) +	\ 	    (vm_offset_t)(offset)))
end_define

begin_define
define|#
directive|define
name|DRM_READ32
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
define|\
value|le32toh(*(volatile u_int32_t *)(((vm_offset_t)(map)->handle) +	\ 	    (vm_offset_t)(offset)))
end_define

begin_define
define|#
directive|define
name|DRM_READ64
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
define|\
value|le64toh(*(volatile u_int64_t *)(((vm_offset_t)(map)->handle) +	\ 	    (vm_offset_t)(offset)))
end_define

begin_define
define|#
directive|define
name|DRM_WRITE8
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|*(volatile u_int8_t *)(((vm_offset_t)(map)->handle) +		\ 	    (vm_offset_t)(offset)) = val
end_define

begin_define
define|#
directive|define
name|DRM_WRITE16
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|*(volatile u_int16_t *)(((vm_offset_t)(map)->handle) +		\ 	    (vm_offset_t)(offset)) = htole16(val)
end_define

begin_define
define|#
directive|define
name|DRM_WRITE32
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|*(volatile u_int32_t *)(((vm_offset_t)(map)->handle) +		\ 	    (vm_offset_t)(offset)) = htole32(val)
end_define

begin_define
define|#
directive|define
name|DRM_WRITE64
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|*(volatile u_int64_t *)(((vm_offset_t)(map)->handle) +		\ 	    (vm_offset_t)(offset)) = htole64(val)
end_define

begin_comment
comment|/* DRM_READMEMORYBARRIER() prevents reordering of reads.  * DRM_WRITEMEMORYBARRIER() prevents reordering of writes.  * DRM_MEMORYBARRIER() prevents reordering of reads and writes.  */
end_comment

begin_define
define|#
directive|define
name|DRM_READMEMORYBARRIER
parameter_list|()
value|rmb()
end_define

begin_define
define|#
directive|define
name|DRM_WRITEMEMORYBARRIER
parameter_list|()
value|wmb()
end_define

begin_define
define|#
directive|define
name|DRM_MEMORYBARRIER
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|smp_rmb
parameter_list|()
value|rmb()
end_define

begin_define
define|#
directive|define
name|smp_wmb
parameter_list|()
value|wmb()
end_define

begin_define
define|#
directive|define
name|smp_mb__before_atomic_inc
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|smp_mb__after_atomic_inc
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|barrier
parameter_list|()
value|__compiler_membar()
end_define

begin_define
define|#
directive|define
name|do_div
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) /= (b))
end_define

begin_define
define|#
directive|define
name|div64_u64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) / (b))
end_define

begin_define
define|#
directive|define
name|lower_32_bits
parameter_list|(
name|n
parameter_list|)
value|((u32)(n))
end_define

begin_define
define|#
directive|define
name|upper_32_bits
parameter_list|(
name|n
parameter_list|)
value|((u32)(((n)>> 16)>> 16))
end_define

begin_define
define|#
directive|define
name|__set_bit
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|set_bit((n), (s))
end_define

begin_define
define|#
directive|define
name|__clear_bit
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|clear_bit((n), (s))
end_define

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|({			\ 	type __min1 = (x);			\ 	type __min2 = (y);			\ 	__min1< __min2 ? __min1 : __min2; })
end_define

begin_define
define|#
directive|define
name|max_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|({			\ 	type __max1 = (x);			\ 	type __max2 = (y);			\ 	__max1> __max2 ? __max1 : __max2; })
end_define

begin_define
define|#
directive|define
name|memset_io
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memset((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|memcpy_fromio
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|memcpy_toio
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|VERIFY_READ
value|VM_PROT_READ
end_define

begin_define
define|#
directive|define
name|VERIFY_WRITE
value|VM_PROT_WRITE
end_define

begin_define
define|#
directive|define
name|access_ok
parameter_list|(
name|prot
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|useracc((p), (l), (prot))
end_define

begin_comment
comment|/* XXXKIB what is the right code for the FreeBSD ? */
end_comment

begin_comment
comment|/* kib@ used ENXIO here -- dumbbell@ */
end_comment

begin_define
define|#
directive|define
name|EREMOTEIO
value|EIO
end_define

begin_define
define|#
directive|define
name|ERESTARTSYS
value|512
end_define

begin_comment
comment|/* Same value as Linux. */
end_comment

begin_define
define|#
directive|define
name|KTR_DRM
value|KTR_DEV
end_define

begin_define
define|#
directive|define
name|KTR_DRM_REG
value|KTR_SPARE3
end_define

begin_define
define|#
directive|define
name|DRM_AGP_KERN
value|struct agp_info
end_define

begin_define
define|#
directive|define
name|DRM_AGP_MEM
value|void
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_APPLE
value|0x106b
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_ASUSTEK
value|0x1043
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_ATI
value|0x1002
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_DELL
value|0x1028
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_HP
value|0x103c
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_IBM
value|0x1014
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_INTEL
value|0x8086
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_SERVERWORKS
value|0x1166
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_SONY
value|0x104d
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_VIA
value|0x1106
end_define

begin_define
define|#
directive|define
name|DIV_ROUND_UP
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|)
value|(((n) + (d) - 1) / (d))
end_define

begin_define
define|#
directive|define
name|DIV_ROUND_CLOSEST
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|)
value|(((n) + (d) / 2) / (d))
end_define

begin_define
define|#
directive|define
name|div_u64
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|)
value|((n) / (d))
end_define

begin_define
define|#
directive|define
name|hweight32
parameter_list|(
name|i
parameter_list|)
value|bitcount32(i)
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|roundup_pow_of_two
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
operator|(
literal|1UL
operator|<<
name|flsl
argument_list|(
name|x
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * ror32 - rotate a 32-bit value right  * @word: value to rotate  * @shift: bits to roll  *  * Source: include/linux/bitops.h  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|ror32
parameter_list|(
name|uint32_t
name|word
parameter_list|,
name|unsigned
name|int
name|shift
parameter_list|)
block|{
return|return
operator|(
name|word
operator|>>
name|shift
operator|)
operator||
operator|(
name|word
operator|<<
operator|(
literal|32
operator|-
name|shift
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|IS_ALIGNED
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)& ((y) - 1)) == 0)
end_define

begin_define
define|#
directive|define
name|round_down
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|rounddown2((x), (y))
end_define

begin_define
define|#
directive|define
name|round_up
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|roundup2((x), (y))
end_define

begin_define
define|#
directive|define
name|get_unaligned
parameter_list|(
name|ptr
parameter_list|)
define|\
value|({ __typeof__(*(ptr)) __tmp;                                    \ 	  memcpy(&__tmp, (ptr), sizeof(*(ptr))); __tmp; })
end_define

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_comment
comment|/* Taken from linux/include/linux/unaligned/le_struct.h. */
end_comment

begin_struct
struct|struct
name|__una_u32
block|{
name|u32
name|x
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|u32
name|__get_unaligned_cpu32
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
specifier|const
name|struct
name|__una_u32
modifier|*
name|ptr
init|=
operator|(
specifier|const
expr|struct
name|__una_u32
operator|*
operator|)
name|p
decl_stmt|;
return|return
operator|(
name|ptr
operator|->
name|x
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|get_unaligned_le32
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|__get_unaligned_cpu32
argument_list|(
operator|(
specifier|const
name|u8
operator|*
operator|)
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Taken from linux/include/linux/unaligned/le_byteshift.h. */
end_comment

begin_function
specifier|static
specifier|inline
name|u32
name|__get_unaligned_le32
parameter_list|(
specifier|const
name|u8
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|p
index|[
literal|0
index|]
operator||
name|p
index|[
literal|1
index|]
operator|<<
literal|8
operator||
name|p
index|[
literal|2
index|]
operator|<<
literal|16
operator||
name|p
index|[
literal|3
index|]
operator|<<
literal|24
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|get_unaligned_le32
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|__get_unaligned_le32
argument_list|(
operator|(
specifier|const
name|u8
operator|*
operator|)
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|ilog2
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
operator|(
name|flsl
argument_list|(
name|x
argument_list|)
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int64_t
name|abs64
parameter_list|(
name|int64_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|x
operator|<
literal|0
condition|?
operator|-
name|x
else|:
name|x
operator|)
return|;
block|}
end_function

begin_function_decl
name|int64_t
name|timeval_to_ns
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|timeval
name|ns_to_timeval
parameter_list|(
specifier|const
name|int64_t
name|nsec
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|round_page(addr)
end_define

begin_define
define|#
directive|define
name|page_to_phys
parameter_list|(
name|x
parameter_list|)
value|VM_PAGE_TO_PHYS(x)
end_define

begin_define
define|#
directive|define
name|offset_in_page
parameter_list|(
name|x
parameter_list|)
value|((x)& PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|drm_get_device_from_kdev
parameter_list|(
name|_kdev
parameter_list|)
value|(((struct drm_minor *)(_kdev)->si_drv1)->dev)
end_define

begin_define
define|#
directive|define
name|DRM_IOC_VOID
value|IOC_VOID
end_define

begin_define
define|#
directive|define
name|DRM_IOC_READ
value|IOC_OUT
end_define

begin_define
define|#
directive|define
name|DRM_IOC_WRITE
value|IOC_IN
end_define

begin_define
define|#
directive|define
name|DRM_IOC_READWRITE
value|IOC_INOUT
end_define

begin_define
define|#
directive|define
name|DRM_IOC
parameter_list|(
name|dir
parameter_list|,
name|group
parameter_list|,
name|nr
parameter_list|,
name|size
parameter_list|)
value|_IOC(dir, group, nr, size)
end_define

begin_function
specifier|static
specifier|inline
name|long
name|__copy_to_user
parameter_list|(
name|void
name|__user
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|unsigned
name|long
name|n
parameter_list|)
block|{
return|return
operator|(
name|copyout
argument_list|(
name|from
argument_list|,
name|to
argument_list|,
name|n
argument_list|)
operator|!=
literal|0
condition|?
name|n
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|copy_to_user
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
value|__copy_to_user((to), (from), (n))
end_define

begin_function
specifier|static
specifier|inline
name|int
name|__put_user
parameter_list|(
name|size_t
name|size
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|x
parameter_list|)
block|{
name|size
operator|=
name|copy_to_user
argument_list|(
name|ptr
argument_list|,
name|x
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|size
condition|?
operator|-
name|EFAULT
else|:
name|size
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|put_user
parameter_list|(
name|x
parameter_list|,
name|ptr
parameter_list|)
value|__put_user(sizeof(*ptr), (ptr),&(x))
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|__copy_from_user
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
name|__user
modifier|*
name|from
parameter_list|,
name|unsigned
name|long
name|n
parameter_list|)
block|{
return|return
operator|(
operator|(
name|copyin
argument_list|(
name|__DECONST
argument_list|(
name|void
operator|*
argument_list|,
name|from
argument_list|)
argument_list|,
name|to
argument_list|,
name|n
argument_list|)
operator|!=
literal|0
condition|?
name|n
else|:
literal|0
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|copy_from_user
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
value|__copy_from_user((to), (from), (n))
end_define

begin_function
specifier|static
specifier|inline
name|int
name|__get_user
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|x
parameter_list|)
block|{
name|size
operator|=
name|copy_from_user
argument_list|(
name|x
argument_list|,
name|ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|size
condition|?
operator|-
name|EFAULT
else|:
name|size
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|get_user
parameter_list|(
name|x
parameter_list|,
name|ptr
parameter_list|)
value|__get_user(sizeof(*ptr), (ptr),&(x))
end_define

begin_function
specifier|static
specifier|inline
name|int
name|__copy_to_user_inatomic
parameter_list|(
name|void
name|__user
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|unsigned
name|n
parameter_list|)
block|{
return|return
operator|(
name|copyout_nofault
argument_list|(
name|from
argument_list|,
name|to
argument_list|,
name|n
argument_list|)
operator|!=
literal|0
condition|?
name|n
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__copy_to_user_inatomic_nocache
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
define|\
value|__copy_to_user_inatomic((to), (from), (n))
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|__copy_from_user_inatomic
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
name|__user
modifier|*
name|from
parameter_list|,
name|unsigned
name|long
name|n
parameter_list|)
block|{
comment|/* 	 * XXXKIB.  Equivalent Linux function is implemented using 	 * MOVNTI for aligned moves.  For unaligned head and tail, 	 * normal move is performed.  As such, it is not incorrect, if 	 * only somewhat slower, to use normal copyin.  All uses 	 * except shmem_pwrite_fast() have the destination mapped WC. 	 */
return|return
operator|(
operator|(
name|copyin_nofault
argument_list|(
name|__DECONST
argument_list|(
name|void
operator|*
argument_list|,
name|from
argument_list|)
argument_list|,
name|to
argument_list|,
name|n
argument_list|)
operator|!=
literal|0
condition|?
name|n
else|:
literal|0
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__copy_from_user_inatomic_nocache
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
define|\
value|__copy_from_user_inatomic((to), (from), (n))
end_define

begin_function
specifier|static
specifier|inline
name|int
name|fault_in_multipages_readable
parameter_list|(
specifier|const
name|char
name|__user
modifier|*
name|uaddr
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|char
name|c
decl_stmt|;
name|int
name|ret
init|=
literal|0
decl_stmt|;
specifier|const
name|char
name|__user
modifier|*
name|end
init|=
name|uaddr
operator|+
name|size
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|unlikely
argument_list|(
name|size
operator|==
literal|0
argument_list|)
condition|)
return|return
name|ret
return|;
while|while
condition|(
name|uaddr
operator|<=
name|end
condition|)
block|{
name|ret
operator|=
operator|-
name|copyin
argument_list|(
name|uaddr
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
literal|0
condition|)
return|return
operator|-
name|EFAULT
return|;
name|uaddr
operator|+=
name|PAGE_SIZE
expr_stmt|;
block|}
comment|/* Check whether the range spilled into the next page. */
if|if
condition|(
operator|(
operator|(
name|unsigned
name|long
operator|)
name|uaddr
operator|&
operator|~
name|PAGE_MASK
operator|)
operator|==
operator|(
operator|(
name|unsigned
name|long
operator|)
name|end
operator|&
operator|~
name|PAGE_MASK
operator|)
condition|)
block|{
name|ret
operator|=
operator|-
name|copyin
argument_list|(
name|end
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|fault_in_multipages_writeable
parameter_list|(
name|char
name|__user
modifier|*
name|uaddr
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
name|char
name|__user
modifier|*
name|end
init|=
name|uaddr
operator|+
name|size
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|unlikely
argument_list|(
name|size
operator|==
literal|0
argument_list|)
condition|)
return|return
name|ret
return|;
comment|/* 	 * Writing zeroes into userspace here is OK, because we know that if 	 * the zero gets there, we'll be overwriting it. 	 */
while|while
condition|(
name|uaddr
operator|<=
name|end
condition|)
block|{
name|ret
operator|=
name|subyte
argument_list|(
name|uaddr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
literal|0
condition|)
return|return
operator|-
name|EFAULT
return|;
name|uaddr
operator|+=
name|PAGE_SIZE
expr_stmt|;
block|}
comment|/* Check whether the range spilled into the next page. */
if|if
condition|(
operator|(
operator|(
name|unsigned
name|long
operator|)
name|uaddr
operator|&
operator|~
name|PAGE_MASK
operator|)
operator|==
operator|(
operator|(
name|unsigned
name|long
operator|)
name|end
operator|&
operator|~
name|PAGE_MASK
operator|)
condition|)
name|ret
operator|=
name|subyte
argument_list|(
name|end
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_enum
enum|enum
name|__drm_capabilities
block|{
name|CAP_SYS_ADMIN
block|}
enum|;
end_enum

begin_function
specifier|static
specifier|inline
name|bool
name|capable
parameter_list|(
name|enum
name|__drm_capabilities
name|cap
parameter_list|)
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|CAP_SYS_ADMIN
case|:
return|return
name|DRM_SUSER
argument_list|(
name|curthread
argument_list|)
return|;
default|default:
name|panic
argument_list|(
literal|"%s: unhandled capability: %0x"
argument_list|,
name|__func__
argument_list|,
name|cap
argument_list|)
expr_stmt|;
return|return
operator|(
name|false
operator|)
return|;
block|}
block|}
end_function

begin_define
define|#
directive|define
name|to_user_ptr
parameter_list|(
name|x
parameter_list|)
value|((void *)(uintptr_t)(x))
end_define

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|set
parameter_list|)
value|SIGEMPTYSET(set)
end_define

begin_define
define|#
directive|define
name|sigaddset
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|SIGADDSET(set, sig)
end_define

begin_define
define|#
directive|define
name|DRM_LOCK
parameter_list|(
name|dev
parameter_list|)
value|sx_xlock(&(dev)->dev_struct_lock)
end_define

begin_define
define|#
directive|define
name|DRM_UNLOCK
parameter_list|(
name|dev
parameter_list|)
value|sx_xunlock(&(dev)->dev_struct_lock)
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|drm_linux_timer_hz_mask
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|jiffies
value|ticks
end_define

begin_define
define|#
directive|define
name|jiffies_to_msecs
parameter_list|(
name|x
parameter_list|)
value|(((int64_t)(x)) * 1000 / hz)
end_define

begin_define
define|#
directive|define
name|msecs_to_jiffies
parameter_list|(
name|x
parameter_list|)
value|(((int64_t)(x)) * hz / 1000)
end_define

begin_define
define|#
directive|define
name|timespec_to_jiffies
parameter_list|(
name|x
parameter_list|)
value|(((x)->tv_sec * 1000000 + (x)->tv_nsec) * hz / 1000000)
end_define

begin_define
define|#
directive|define
name|time_after
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(b) - (long)(a)< 0)
end_define

begin_define
define|#
directive|define
name|time_after_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(b) - (long)(a)<= 0)
end_define

begin_define
define|#
directive|define
name|round_jiffies
parameter_list|(
name|j
parameter_list|)
value|((unsigned long)(((j) + drm_linux_timer_hz_mask)& ~drm_linux_timer_hz_mask))
end_define

begin_define
define|#
directive|define
name|round_jiffies_up
parameter_list|(
name|j
parameter_list|)
value|round_jiffies(j)
end_define

begin_comment
comment|/* TODO */
end_comment

begin_define
define|#
directive|define
name|round_jiffies_up_relative
parameter_list|(
name|j
parameter_list|)
value|round_jiffies_up(j)
end_define

begin_comment
comment|/* TODO */
end_comment

begin_define
define|#
directive|define
name|getrawmonotonic
parameter_list|(
name|ts
parameter_list|)
value|getnanouptime(ts)
end_define

begin_define
define|#
directive|define
name|wake_up
parameter_list|(
name|queue
parameter_list|)
value|wakeup_one((void *)queue)
end_define

begin_define
define|#
directive|define
name|wake_up_interruptible
parameter_list|(
name|queue
parameter_list|)
value|wakeup_one((void *)queue)
end_define

begin_define
define|#
directive|define
name|wake_up_all
parameter_list|(
name|queue
parameter_list|)
value|wakeup((void *)queue)
end_define

begin_define
define|#
directive|define
name|wake_up_interruptible_all
parameter_list|(
name|queue
parameter_list|)
value|wakeup((void *)queue)
end_define

begin_struct
struct|struct
name|completion
block|{
name|unsigned
name|int
name|done
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INIT_COMPLETION
parameter_list|(
name|c
parameter_list|)
value|((c).done = 0);
end_define

begin_function
specifier|static
specifier|inline
name|void
name|init_completion
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
block|{
name|mtx_init
argument_list|(
operator|&
name|c
operator|->
name|lock
argument_list|,
literal|"drmcompl"
argument_list|,
name|NULL
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
name|c
operator|->
name|done
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|free_completion
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
block|{
name|mtx_destroy
argument_list|(
operator|&
name|c
operator|->
name|lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|complete_all
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|c
operator|->
name|lock
argument_list|)
expr_stmt|;
name|c
operator|->
name|done
operator|++
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|c
operator|->
name|lock
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|wait_for_completion_interruptible_timeout
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|,
name|unsigned
name|long
name|timeout
parameter_list|)
block|{
name|unsigned
name|long
name|start_jiffies
decl_stmt|,
name|elapsed_jiffies
decl_stmt|;
name|bool
name|timeout_expired
init|=
name|false
decl_stmt|,
name|awakened
init|=
name|false
decl_stmt|;
name|long
name|ret
init|=
name|timeout
decl_stmt|;
name|start_jiffies
operator|=
name|ticks
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|c
operator|->
name|lock
argument_list|)
expr_stmt|;
while|while
condition|(
name|c
operator|->
name|done
operator|==
literal|0
operator|&&
operator|!
name|timeout_expired
condition|)
block|{
name|ret
operator|=
operator|-
name|msleep
argument_list|(
name|c
argument_list|,
operator|&
name|c
operator|->
name|lock
argument_list|,
name|PCATCH
argument_list|,
literal|"drmwco"
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ret
condition|)
block|{
case|case
operator|-
name|EWOULDBLOCK
case|:
name|timeout_expired
operator|=
name|true
expr_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
break|break;
case|case
operator|-
name|EINTR
case|:
case|case
operator|-
name|ERESTART
case|:
name|ret
operator|=
operator|-
name|ERESTARTSYS
expr_stmt|;
break|break;
case|case
literal|0
case|:
name|awakened
operator|=
name|true
expr_stmt|;
break|break;
block|}
block|}
name|mtx_unlock
argument_list|(
operator|&
name|c
operator|->
name|lock
argument_list|)
expr_stmt|;
if|if
condition|(
name|awakened
condition|)
block|{
name|elapsed_jiffies
operator|=
name|ticks
operator|-
name|start_jiffies
expr_stmt|;
name|ret
operator|=
name|timeout
operator|>
name|elapsed_jiffies
condition|?
name|timeout
operator|-
name|elapsed_jiffies
else|:
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_DMA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_SAREA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_DRIVER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MAGIC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MINOR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_IOCTLS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MAPS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_BUFS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_SEGS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_PAGES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_FILES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_QUEUES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_CMDS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MAPPINGS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_BUFLISTS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_AGPLISTS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_CTXBITMAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_SGLISTS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_HASHTAB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_KMS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_VBLANK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|simple_strtol
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strtol((a), (b), (c))
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_pci_id_list
block|{
name|int
name|vendor
decl_stmt|;
name|int
name|device
decl_stmt|;
name|long
name|driver_private
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|drm_pci_id_list_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|CONFIG_X86
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|CONFIG_X86
value|1
end_define

begin_define
define|#
directive|define
name|CONFIG_X86_64
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|CONFIG_IA64
value|1
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
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONFIG_ACPI
end_define

begin_define
define|#
directive|define
name|CONFIG_DRM_I915_KMS
end_define

begin_undef
undef|#
directive|undef
name|CONFIG_INTEL_IOMMU
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_define
define|#
directive|define
name|CONFIG_COMPAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__arm__
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_AGP
value|1
end_define

begin_define
define|#
directive|define
name|CONFIG_MTRR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CONFIG_FB
value|1
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|fb_mode_option
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|CONFIG_DEBUG_FS
end_undef

begin_undef
undef|#
directive|undef
name|CONFIG_VGA_CONSOLE
end_undef

begin_define
define|#
directive|define
name|EXPORT_SYMBOL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EXPORT_SYMBOL_GPL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_AUTHOR
parameter_list|(
name|author
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_DESCRIPTION
parameter_list|(
name|desc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_LICENSE
parameter_list|(
name|license
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_PARM_DESC
parameter_list|(
name|name
parameter_list|,
name|desc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_DEVICE_TABLE
parameter_list|(
name|name
parameter_list|,
name|list
parameter_list|)
end_define

begin_define
define|#
directive|define
name|module_param_named
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|type
parameter_list|,
name|perm
parameter_list|)
end_define

begin_define
define|#
directive|define
name|printk
value|printf
end_define

begin_define
define|#
directive|define
name|pr_err
value|DRM_ERROR
end_define

begin_define
define|#
directive|define
name|pr_warn
value|DRM_WARNING
end_define

begin_define
define|#
directive|define
name|pr_warn_once
value|DRM_WARNING
end_define

begin_define
define|#
directive|define
name|KERN_DEBUG
value|""
end_define

begin_comment
comment|/* I2C compatibility. */
end_comment

begin_define
define|#
directive|define
name|I2C_M_RD
value|IIC_M_RD
end_define

begin_define
define|#
directive|define
name|I2C_M_WR
value|IIC_M_WR
end_define

begin_define
define|#
directive|define
name|I2C_M_NOSTART
value|IIC_M_NOSTART
end_define

begin_function_decl
name|struct
name|fb_info
modifier|*
name|framebuffer_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|framebuffer_release
parameter_list|(
name|struct
name|fb_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|console_lock
parameter_list|()
end_define

begin_define
define|#
directive|define
name|console_unlock
parameter_list|()
end_define

begin_define
define|#
directive|define
name|console_trylock
parameter_list|()
value|true
end_define

begin_define
define|#
directive|define
name|PM_EVENT_SUSPEND
value|0x0002
end_define

begin_define
define|#
directive|define
name|PM_EVENT_QUIESCE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PM_EVENT_PRETHAW
value|PM_EVENT_QUIESCE
end_define

begin_typedef
typedef|typedef
struct|struct
name|pm_message
block|{
name|int
name|event
decl_stmt|;
block|}
name|pm_message_t
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|int
name|pci_read_config_byte
parameter_list|(
name|device_t
name|kdev
parameter_list|,
name|int
name|where
parameter_list|,
name|u8
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
operator|(
name|u8
operator|)
name|pci_read_config
argument_list|(
name|kdev
argument_list|,
name|where
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pci_write_config_byte
parameter_list|(
name|device_t
name|kdev
parameter_list|,
name|int
name|where
parameter_list|,
name|u8
name|val
parameter_list|)
block|{
name|pci_write_config
argument_list|(
name|kdev
argument_list|,
name|where
argument_list|,
name|val
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pci_read_config_word
parameter_list|(
name|device_t
name|kdev
parameter_list|,
name|int
name|where
parameter_list|,
name|uint16_t
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
operator|(
name|uint16_t
operator|)
name|pci_read_config
argument_list|(
name|kdev
argument_list|,
name|where
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pci_write_config_word
parameter_list|(
name|device_t
name|kdev
parameter_list|,
name|int
name|where
parameter_list|,
name|uint16_t
name|val
parameter_list|)
block|{
name|pci_write_config
argument_list|(
name|kdev
argument_list|,
name|where
argument_list|,
name|val
argument_list|,
literal|2
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pci_read_config_dword
parameter_list|(
name|device_t
name|kdev
parameter_list|,
name|int
name|where
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
operator|(
name|uint32_t
operator|)
name|pci_read_config
argument_list|(
name|kdev
argument_list|,
name|where
argument_list|,
literal|4
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pci_write_config_dword
parameter_list|(
name|device_t
name|kdev
parameter_list|,
name|int
name|where
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|pci_write_config
argument_list|(
name|kdev
argument_list|,
name|where
argument_list|,
name|val
argument_list|,
literal|4
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|on_each_cpu
parameter_list|(
name|void
name|callback
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|wait
parameter_list|)
block|{
name|smp_rendezvous
argument_list|(
name|NULL
argument_list|,
name|callback
argument_list|,
name|NULL
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|hex_dump_to_buffer
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|rowsize
parameter_list|,
name|int
name|groupsize
parameter_list|,
name|char
modifier|*
name|linebuf
parameter_list|,
name|size_t
name|linebuflen
parameter_list|,
name|bool
name|ascii
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KIB_NOTYET
parameter_list|()
define|\
value|do {									\ 	if (drm_debug&& drm_notyet)					\ 		printf("NOTYET: %s at %s:%d\n", __func__, __FILE__, __LINE__); \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DRM_OS_FREEBSD_H_ */
end_comment

end_unit

