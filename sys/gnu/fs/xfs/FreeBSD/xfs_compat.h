begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_COMPAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_COMPAT_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/uuid.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/sbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|__KERNEL__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|printk
value|printf
end_define

begin_define
define|#
directive|define
name|MAJOR
parameter_list|(
name|x
parameter_list|)
value|major(x)
end_define

begin_define
define|#
directive|define
name|MINOR
parameter_list|(
name|x
parameter_list|)
value|minor(x)
end_define

begin_comment
comment|/*  * SYSV compatibility types missing in FreeBSD.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulong
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ushort
typedef|;
end_typedef

begin_comment
comment|/*  * Additional type declarations for XFS.  */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|__s8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|int
name|__s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|__u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|__s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|int
name|__s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|__u64
typedef|;
end_typedef

begin_comment
comment|/* linus now has sparse which expects big endian or little endian */
end_comment

begin_typedef
typedef|typedef
name|__u16
name|__be16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__u32
name|__be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__u64
name|__be64
typedef|;
end_typedef

begin_comment
comment|/*  * Linux types with direct FreeBSD conterparts  */
end_comment

begin_typedef
typedef|typedef
name|off_t
name|loff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|timespec
name|timespec_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|uuid
name|uuid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fid
name|fid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|dev_t
name|os_dev_t
typedef|;
end_typedef

begin_comment
comment|/*  *  Linux block devices are device vnodes in FreeBSD.  */
end_comment

begin_define
define|#
directive|define
name|block_device
value|vnode
end_define

begin_comment
comment|/*  *  Get the current CPU ID.   */
end_comment

begin_define
define|#
directive|define
name|smp_processor_id
parameter_list|()
value|PCPU_GET(cpuid)
end_define

begin_comment
comment|/*  * FreeBSD does not have BITS_PER_LONG defined.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LONG_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|LONG_BIT
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

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

begin_define
define|#
directive|define
name|rol32
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<<(y))|((x)>>(32-(y))))
end_define

begin_comment
comment|/*  * boolean_t is enum on Linux, int on FreeBSD.  * Provide value defines.  */
end_comment

begin_define
define|#
directive|define
name|B_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|B_TRUE
value|1
end_define

begin_comment
comment|/*  * GCC 3.x static branch prediction hints  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|3
end_if

begin_define
define|#
directive|define
name|__builtin_expect
parameter_list|(
name|x
parameter_list|,
name|expected_value
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|likely
end_ifndef

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect((x), 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|unlikely
end_ifndef

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect((x), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ANSI and GCC extension keywords compatibity  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|inline
end_ifndef

begin_define
define|#
directive|define
name|inline
value|__inline__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|asm
end_ifndef

begin_define
define|#
directive|define
name|asm
value|__asm
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|typeof
end_ifndef

begin_define
define|#
directive|define
name|typeof
value|__typeof
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Miscellaneous limit constants  */
end_comment

begin_define
define|#
directive|define
name|MAX_LFS_FILESIZE
value|0x7fffffffffffffffLL
end_define

begin_comment
comment|/*  * Map simple functions to their FreeBSD kernel equivalents  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|copy_to_user
end_ifndef

begin_define
define|#
directive|define
name|copy_to_user
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
value|copyout((src), (dst), (len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|copy_from_user
end_ifndef

begin_define
define|#
directive|define
name|copy_from_user
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
value|copyin((src), (dst), (len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|memmove
end_ifndef

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
value|bcopy((src), (dst), (len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|barrier
end_ifndef

begin_define
define|#
directive|define
name|barrier
parameter_list|()
value|__asm__ __volatile__("": : :"memory")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Map simple global vairables to FreeBSD kernel equivalents  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|xfs_physmem
argument_list|)
end_if

begin_define
define|#
directive|define
name|xfs_physmem
value|physmem
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HZ
end_ifndef

begin_define
define|#
directive|define
name|HZ
value|hz
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These should be implemented properly for all architectures  * we want to support.  */
end_comment

begin_define
define|#
directive|define
name|get_unaligned
parameter_list|(
name|ptr
parameter_list|)
value|(*(ptr))
end_define

begin_define
define|#
directive|define
name|put_unaligned
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|((void)( *(ptr) = (val) ))
end_define

begin_comment
comment|/*  * Linux type-safe min/max macros.  */
end_comment

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
value|MIN((x),(y))
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
value|MAX((x),(y))
end_define

begin_typedef
typedef|typedef
name|struct
name|mtx
name|xfs_mutex_t
typedef|;
end_typedef

begin_comment
comment|/*  * Cedentials manipulation.  */
end_comment

begin_define
define|#
directive|define
name|current_fsuid
parameter_list|(
name|credp
parameter_list|)
value|(credp)->cr_uid
end_define

begin_define
define|#
directive|define
name|current_fsgid
parameter_list|(
name|credp
parameter_list|)
value|(credp)->cr_groups[0]
end_define

begin_define
define|#
directive|define
name|PAGE_CACHE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|IS_ERR
parameter_list|(
name|err
parameter_list|)
value|(err)
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|ffz
parameter_list|(
name|unsigned
name|long
name|val
parameter_list|)
block|{
return|return
name|ffsl
argument_list|(
operator|~
name|val
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_COMPAT_H__ */
end_comment

end_unit

