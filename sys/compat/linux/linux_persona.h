begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_PERSONALITY_H
end_ifndef

begin_define
define|#
directive|define
name|LINUX_PERSONALITY_H
end_define

begin_comment
comment|/*  * Flags for bug emulation.  *  * These occupy the top three bytes.  */
end_comment

begin_enum
enum|enum
block|{
name|LINUX_UNAME26
init|=
literal|0x0020000
block|,
name|LINUX_ADDR_NO_RANDOMIZE
init|=
literal|0x0040000
block|,
comment|/* disable randomization 							 * of VA space 							 */
name|LINUX_FDPIC_FUNCPTRS
init|=
literal|0x0080000
block|,
comment|/* userspace function 							 * ptrs point to descriptors 							 * (signal handling) 							 */
name|LINUX_MMAP_PAGE_ZERO
init|=
literal|0x0100000
block|,
name|LINUX_ADDR_COMPAT_LAYOUT
init|=
literal|0x0200000
block|,
name|LINUX_READ_IMPLIES_EXEC
init|=
literal|0x0400000
block|,
name|LINUX_ADDR_LIMIT_32BIT
init|=
literal|0x0800000
block|,
name|LINUX_SHORT_INODE
init|=
literal|0x1000000
block|,
name|LINUX_WHOLE_SECONDS
init|=
literal|0x2000000
block|,
name|LINUX_STICKY_TIMEOUTS
init|=
literal|0x4000000
block|,
name|LINUX_ADDR_LIMIT_3GB
init|=
literal|0x8000000
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Security-relevant compatibility flags that must be  * cleared upon setuid or setgid exec:  */
end_comment

begin_define
define|#
directive|define
name|LINUX_PER_CLEAR_ON_SETID
value|(LINUX_READ_IMPLIES_EXEC  | \ 					LINUX_ADDR_NO_RANDOMIZE  | \ 					LINUX_ADDR_COMPAT_LAYOUT | \ 					LINUX_MMAP_PAGE_ZERO)
end_define

begin_comment
comment|/*  * Personality types.  *  * These go in the low byte.  Avoid using the top bit, it will  * conflict with error returns.  */
end_comment

begin_enum
enum|enum
block|{
name|LINUX_PER_LINUX
init|=
literal|0x0000
block|,
name|LINUX_PER_LINUX_32BIT
init|=
literal|0x0000
operator||
name|LINUX_ADDR_LIMIT_32BIT
block|,
name|LINUX_PER_LINUX_FDPIC
init|=
literal|0x0000
operator||
name|LINUX_FDPIC_FUNCPTRS
block|,
name|LINUX_PER_LINUX32
init|=
literal|0x0008
block|,
name|LINUX_PER_LINUX32_3GB
init|=
literal|0x0008
operator||
name|LINUX_ADDR_LIMIT_3GB
block|,
name|LINUX_PER_MASK
init|=
literal|0x00ff
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_PERSONALITY_H */
end_comment

end_unit

