begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 2001-2003, 2005, Juniper Networks, Inc.  * All rights reserved.  *  * defs.h -- Simple universal types and definitions for use by the microkernel  * Jim Hayes, November 1996  *  *	JNPR: defs.h,v 1.3.2.1 2007/09/10 08:16:32 girish  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEFS_H__
end_define

begin_comment
comment|/*  * Paranoid compilation. If defined, the PARANOID flag will enable asserts,  * data structure magic stamping and a suite of other debug tools. To disable  * it, comment out its definition.  */
end_comment

begin_define
define|#
directive|define
name|PARANOID
end_define

begin_comment
comment|/*  * This is the ONLY place you should see hardware specific information  * encoded as #ifdefs. (Well, except for stdarg.h, perhaps.)  * I apologize in advance!  */
end_comment

begin_include
include|#
directive|include
file|<machine/defs_mips.h>
end_include

begin_define
define|#
directive|define
name|CPU_GOT_ONE
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_GOT_ONE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"YOU NEED TO SPECIFY ONE CPU TYPE TO USE THIS FILE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
name|boolean_
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
name|boolean
typedef|;
end_typedef

begin_comment
comment|/*  * Make NULL a pointer within the microkernel environment to catch  * pointer semantic miscreants.  *  * The reason it's conditional here is that some of the BSD includes  * define it multiple times as a straight integer and GCC barfs on  * the alternative prototypes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(void *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define some standard sized types.  (Defined in cpu-specific type files  * included above.)  */
end_comment

begin_define
define|#
directive|define
name|MAX_U8
value|255
end_define

begin_define
define|#
directive|define
name|MAX_S8
value|128
end_define

begin_define
define|#
directive|define
name|MIN_S8
value|-127
end_define

begin_define
define|#
directive|define
name|MAX_U16
value|0xffff
end_define

begin_define
define|#
directive|define
name|MIN_S16
value|((int16_t)(1<< 15))
end_define

begin_define
define|#
directive|define
name|MAX_S16
value|((int16_t)~MIN_S16)
end_define

begin_define
define|#
directive|define
name|MAX_U32
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MIN_S32
value|((int32_t)(1<< 31))
end_define

begin_define
define|#
directive|define
name|MAX_S32
value|((int32_t)~MIN_S32)
end_define

begin_define
define|#
directive|define
name|MAX_U64
value|((u_int64_t)0 - 1)
end_define

begin_define
define|#
directive|define
name|MAX_S64
value|((int64_t)(MAX_U64>> 1))
end_define

begin_define
define|#
directive|define
name|MIN_S64
value|(-MAX_S64-1)
end_define

begin_comment
comment|/*  * Solaris uses _SIZE_T to mark the fact that "size_t" has already  * been defined.  _SYS_TYPES_H_ is used by BSD.  *   */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_SYS_TYPES_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SIZE_T
argument_list|)
end_if

begin_typedef
typedef|typedef
name|UNSIGNED_32
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_SYS_TYPES_H_
argument_list|)
end_if

begin_typedef
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UNSIGNED_8
name|u_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SIGNED_8
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UNSIGNED_16
name|u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SIGNED_16
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UNSIGNED_32
name|u_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SIGNED_32
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UNSIGNED_64
name|u_int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SIGNED_64
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UNSIGNED_32
name|u_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UNSIGNED_16
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UNSIGNED_8
name|u_char
typedef|;
end_typedef

begin_comment
comment|/*  * Define the standard terminology used in the diag software  * with regards to bytes, words, etc.  * BYTE = 8 bits  * HWORD (halfword) = 2 bytes or 16 bits  * WORD = 4 bytes or 32 bits  * QUAD = 8 bytes or 64 bits  *  * (The term QUAD seems less-than-intuitive here, but it is  * derived from BSD sources where it is defined as int64_t.)  *  * For consistency use the following defines wherever appropriate.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NBI_BYTE
init|=
operator|(
sizeof|sizeof
argument_list|(
name|u_int8_t
argument_list|)
operator|*
literal|8
operator|)
block|,
name|NBI_HWORD
init|=
operator|(
sizeof|sizeof
argument_list|(
name|u_int16_t
argument_list|)
operator|*
literal|8
operator|)
block|,
name|NBI_WORD
init|=
operator|(
sizeof|sizeof
argument_list|(
name|u_int32_t
argument_list|)
operator|*
literal|8
operator|)
block|,
name|NBI_QUAD
init|=
operator|(
sizeof|sizeof
argument_list|(
name|u_int64_t
argument_list|)
operator|*
literal|8
operator|)
block|}
name|num_bits_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|NBY_BYTE
init|=
sizeof|sizeof
argument_list|(
name|u_int8_t
argument_list|)
block|,
name|NBY_HWORD
init|=
sizeof|sizeof
argument_list|(
name|u_int16_t
argument_list|)
block|,
name|NBY_WORD
init|=
sizeof|sizeof
argument_list|(
name|u_int32_t
argument_list|)
block|,
name|NBY_QUAD
init|=
expr|sizeof
operator|(
name|u_int64_t
operator|)
block|}
name|num_bytes_t
typedef|;
end_typedef

begin_comment
comment|/*  * We assume that pid values are 16 bit integers  */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TYPES_H_ */
end_comment

begin_typedef
typedef|typedef
name|UNSIGNED_32
name|magic_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|status_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BITS_IN_BYTE
value|8
end_define

begin_comment
comment|/*  * Packed definition. We use this for fields in network frames where we  * don't want the compiler to pack out to even alignment  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PACKED
end_ifdef

begin_undef
undef|#
directive|undef
name|PACKED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PACKED
parameter_list|(
name|x
parameter_list|)
value|x __attribute__ ((packed))
end_define

begin_comment
comment|/*  * __unused is a FreeBSDism that prevents the compiler from choking  * on function parameters that remain unused through the life of a  * function.  This is not an issue for the Cygnus toolchain.  In general  * it SHOULD NOT BE USED in the martini embedded software repository.  * It should only be used inside of shared code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__unused
end_ifndef

begin_define
define|#
directive|define
name|__unused
value|__attribute__ ((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Basic memory multiples  */
end_comment

begin_define
define|#
directive|define
name|SIZE_1K
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SIZE_2K
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SIZE_4K
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SIZE_8K
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SIZE_16K
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SIZE_32K
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SIZE_64K
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SIZE_128K
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SIZE_256K
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SIZE_512K
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SIZE_1M
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SIZE_2M
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SIZE_4M
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SIZE_8M
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SIZE_16M
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SIZE_32M
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SIZE_64M
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SIZE_128M
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SIZE_256M
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIZE_512M
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SIZE_1G
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SIZE_2G
value|0x80000000
end_define

begin_comment
comment|/*  * swap16_inline  * swap32_inline  *  * Byteswap a 16 and 32 bit quantities  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int16_t
name|swap16_inline
parameter_list|(
name|u_int16_t
name|data
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|data
operator|&
literal|0x00ff
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|data
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u_int32_t
name|swap32_inline
parameter_list|(
name|u_int32_t
name|data
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|data
operator|&
literal|0x000000ff
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|data
operator|&
literal|0x0000ff00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|data
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
operator|(
name|data
operator|&
literal|0xff000000
operator|)
operator|>>
literal|24
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Define errno_t here as it is needed by the rom and ukernel  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|errno_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EOK
value|0
end_define

begin_comment
comment|/*  * Define the main communication structure used for passing  * information from the rom to the ukernel (done here as it is  * used by them both)  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|rom_info_
name|rom_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * Typedef the return code from the ukernel to the ROM  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|rom_return_t
typedef|;
end_typedef

begin_comment
comment|/*  * Pull in the relevant global environment header file  *  * This file is shared by the uKernel and the system simulation effort.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENV_UKERN
argument_list|)
operator|||
name|defined
argument_list|(
name|ENV_SYS_SIM
argument_list|)
end_if

begin_include
include|#
directive|include
file|"ukern.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENV_UKERN */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENV_ROM
argument_list|)
end_if

begin_include
include|#
directive|include
file|"rom.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DEFS_H__ */
end_comment

end_unit

