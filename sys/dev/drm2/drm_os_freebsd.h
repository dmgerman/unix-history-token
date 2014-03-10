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
name|int32_t
name|__be32
typedef|;
end_typedef

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
name|DRM_HZ
value|hz
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
name|DRM_MDELAY
parameter_list|(
name|msecs
parameter_list|)
value|do { int loops = (msecs);		\ 				  while (loops--) DELAY(1000);		\ 				} while (0)
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
name|DRM_TIME_SLICE
value|(hz/20)
end_define

begin_comment
comment|/* Time slice for GLXContexts	  */
end_comment

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
name|lower_32_bits
parameter_list|(
name|n
parameter_list|)
value|((u32)(n))
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
value|ERESTART
end_define

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
name|ptr
operator|->
name|x
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
name|__get_unaligned_cpu32
argument_list|(
operator|(
specifier|const
name|u8
operator|*
operator|)
name|p
argument_list|)
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
name|__get_unaligned_le32
argument_list|(
operator|(
specifier|const
name|u8
operator|*
operator|)
name|p
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KIB_NOTYET
parameter_list|()
define|\
value|do {									\ 	if (drm_debug_flag&& drm_notyet_flag)				\ 		printf("NOTYET: %s at %s:%d\n", __func__, __FILE__, __LINE__); \ } while (0)
end_define

end_unit

