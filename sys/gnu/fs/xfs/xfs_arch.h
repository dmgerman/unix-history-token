begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ARCH_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ARCH_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|XFS_BIG_INUMS
end_ifndef

begin_error
error|#
directive|error
error|XFS_BIG_INUMS must be defined true or false
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|_BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|__user
end_define

begin_comment
comment|/* Compatibiliy defines */
end_comment

begin_define
define|#
directive|define
name|__swab16
value|__bswap16
end_define

begin_define
define|#
directive|define
name|__swab32
value|__bswap32
end_define

begin_define
define|#
directive|define
name|__swab64
value|__bswap64
end_define

begin_define
define|#
directive|define
name|ARCH_NOCONVERT
value|1
end_define

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|!=
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|XFS_NATIVE_HOST
value|1
end_define

begin_define
define|#
directive|define
name|ARCH_CONVERT
value|ARCH_NOCONVERT
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|XFS_NATIVE_HOST
end_undef

begin_define
define|#
directive|define
name|ARCH_CONVERT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XFS_NATIVE_HOST
end_ifdef

begin_define
define|#
directive|define
name|cpu_to_be16
parameter_list|(
name|val
parameter_list|)
value|((__be16)(val))
end_define

begin_define
define|#
directive|define
name|cpu_to_be32
parameter_list|(
name|val
parameter_list|)
value|((__be32)(val))
end_define

begin_define
define|#
directive|define
name|cpu_to_be64
parameter_list|(
name|val
parameter_list|)
value|((__be64)(val))
end_define

begin_define
define|#
directive|define
name|be16_to_cpu
parameter_list|(
name|val
parameter_list|)
value|((__uint16_t)(val))
end_define

begin_define
define|#
directive|define
name|be32_to_cpu
parameter_list|(
name|val
parameter_list|)
value|((__uint32_t)(val))
end_define

begin_define
define|#
directive|define
name|be64_to_cpu
parameter_list|(
name|val
parameter_list|)
value|((__uint64_t)(val))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cpu_to_be16
parameter_list|(
name|val
parameter_list|)
value|(__swab16((__uint16_t)(val)))
end_define

begin_define
define|#
directive|define
name|cpu_to_be32
parameter_list|(
name|val
parameter_list|)
value|(__swab32((__uint32_t)(val)))
end_define

begin_define
define|#
directive|define
name|cpu_to_be64
parameter_list|(
name|val
parameter_list|)
value|(__swab64((__uint64_t)(val)))
end_define

begin_define
define|#
directive|define
name|be16_to_cpu
parameter_list|(
name|val
parameter_list|)
value|(__swab16((__be16)(val)))
end_define

begin_define
define|#
directive|define
name|be32_to_cpu
parameter_list|(
name|val
parameter_list|)
value|(__swab32((__be32)(val)))
end_define

begin_define
define|#
directive|define
name|be64_to_cpu
parameter_list|(
name|val
parameter_list|)
value|(__swab64((__be64)(val)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#endif	/* __KERNEL__ */
end_comment

begin_comment
comment|/* do we need conversion? */
end_comment

begin_comment
comment|//#define ARCH_NOCONVERT 1
end_comment

begin_comment
comment|//#ifdef XFS_NATIVE_HOST
end_comment

begin_comment
comment|//# define ARCH_CONVERT	ARCH_NOCONVERT
end_comment

begin_comment
comment|//#else
end_comment

begin_comment
comment|//# define ARCH_CONVERT	0
end_comment

begin_comment
comment|//#endif
end_comment

begin_comment
comment|/* generic swapping macros */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SWABMACROS
end_ifndef

begin_define
define|#
directive|define
name|INT_SWAP16
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((typeof(type))(__swab16((__u16)(var))))
end_define

begin_define
define|#
directive|define
name|INT_SWAP32
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((typeof(type))(__swab32((__u32)(var))))
end_define

begin_define
define|#
directive|define
name|INT_SWAP64
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((typeof(type))(__swab64((__u64)(var))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INT_SWAP
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
define|\
value|((sizeof(type) == 8) ? INT_SWAP64(type,var) : \     ((sizeof(type) == 4) ? INT_SWAP32(type,var) : \     ((sizeof(type) == 2) ? INT_SWAP16(type,var) : \     (var))))
end_define

begin_comment
comment|/*  * get and set integers from potentially unaligned locations  */
end_comment

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_16_BE
parameter_list|(
name|pointer
parameter_list|)
define|\
value|((__u16)((((__u8*)(pointer))[0]<< 8) | (((__u8*)(pointer))[1])))
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_16_BE
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
define|\
value|{ \ 	((__u8*)(pointer))[0] = (((value)>> 8)& 0xff); \ 	((__u8*)(pointer))[1] = (((value)     )& 0xff); \     }
end_define

begin_comment
comment|/* define generic INT_ macros */
end_comment

begin_define
define|#
directive|define
name|INT_GET
parameter_list|(
name|reference
parameter_list|,
name|arch
parameter_list|)
define|\
value|(((arch) == ARCH_NOCONVERT) \ 	? \ 	    (reference) \ 	: \ 	    INT_SWAP((reference),(reference)) \     )
end_define

begin_comment
comment|/* does not return a value */
end_comment

begin_define
define|#
directive|define
name|INT_SET
parameter_list|(
name|reference
parameter_list|,
name|arch
parameter_list|,
name|valueref
parameter_list|)
define|\
value|(__builtin_constant_p(valueref) ? \ 	(void)( (reference) = ( ((arch) != ARCH_NOCONVERT) ? (INT_SWAP((reference),(valueref))) : (valueref)) ) : \ 	(void)( \ 	    ((reference) = (valueref)), \ 	    ( ((arch) != ARCH_NOCONVERT) ? (reference) = INT_SWAP((reference),(reference)) : 0 ) \ 	) \     )
end_define

begin_comment
comment|/* does not return a value */
end_comment

begin_define
define|#
directive|define
name|INT_MOD_EXPR
parameter_list|(
name|reference
parameter_list|,
name|arch
parameter_list|,
name|code
parameter_list|)
define|\
value|(((arch) == ARCH_NOCONVERT) \ 	? \ 	    (void)((reference) code) \ 	: \ 	    (void)( \ 		(reference) = INT_GET((reference),arch) , \ 		((reference) code), \ 		INT_SET(reference, arch, reference) \ 	    ) \     )
end_define

begin_comment
comment|/* does not return a value */
end_comment

begin_define
define|#
directive|define
name|INT_MOD
parameter_list|(
name|reference
parameter_list|,
name|arch
parameter_list|,
name|delta
parameter_list|)
define|\
value|(void)( \ 	INT_MOD_EXPR(reference,arch,+=(delta)) \     )
end_define

begin_comment
comment|/*  * INT_COPY - copy a value between two locations with the  *	      _same architecture_ but _potentially different sizes_  *  *	    if the types of the two parameters are equal or they are  *		in native architecture, a simple copy is done  *  *	    otherwise, architecture conversions are done  *  */
end_comment

begin_comment
comment|/* does not return a value */
end_comment

begin_define
define|#
directive|define
name|INT_COPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|arch
parameter_list|)
define|\
value|( \ 	((sizeof(dst) == sizeof(src)) || ((arch) == ARCH_NOCONVERT)) \ 	    ? \ 		(void)((dst) = (src)) \ 	    : \ 		INT_SET(dst, arch, INT_GET(src, arch)) \     )
end_define

begin_comment
comment|/*  * INT_XLATE - copy a value in either direction between two locations  *	       with different architectures  *  *		    dir< 0	- copy from memory to buffer (native to arch)  *		    dir> 0	- copy from buffer to memory (arch to native)  */
end_comment

begin_comment
comment|/* does not return a value */
end_comment

begin_define
define|#
directive|define
name|INT_XLATE
parameter_list|(
name|buf
parameter_list|,
name|mem
parameter_list|,
name|dir
parameter_list|,
name|arch
parameter_list|)
value|{\     ASSERT(dir); \     if (dir>0) { \ 	(mem)=INT_GET(buf, arch); \     } else { \ 	INT_SET(buf, arch, mem); \     } \ }
end_define

begin_function
specifier|static
specifier|inline
name|void
name|be16_add
parameter_list|(
name|__be16
modifier|*
name|a
parameter_list|,
name|__s16
name|b
parameter_list|)
block|{
operator|*
name|a
operator|=
name|cpu_to_be16
argument_list|(
name|be16_to_cpu
argument_list|(
operator|*
name|a
argument_list|)
operator|+
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|be32_add
parameter_list|(
name|__be32
modifier|*
name|a
parameter_list|,
name|__s32
name|b
parameter_list|)
block|{
operator|*
name|a
operator|=
name|cpu_to_be32
argument_list|(
name|be32_to_cpu
argument_list|(
operator|*
name|a
argument_list|)
operator|+
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|be64_add
parameter_list|(
name|__be64
modifier|*
name|a
parameter_list|,
name|__s64
name|b
parameter_list|)
block|{
operator|*
name|a
operator|=
name|cpu_to_be64
argument_list|(
name|be64_to_cpu
argument_list|(
operator|*
name|a
argument_list|)
operator|+
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * In directories inode numbers are stored as unaligned arrays of unsigned  * 8bit integers on disk.  *  * For v1 directories or v2 directories that contain inode numbers that  * do not fit into 32bit the array has eight members, but the first member  * is always zero:  *  *  |unused|48-55|40-47|32-39|24-31|16-23| 8-15| 0- 7|  *  * For v2 directories that only contain entries with inode numbers that fit  * into 32bits a four-member array is used:  *  *  |24-31|16-23| 8-15| 0- 7|  */
end_comment

begin_define
define|#
directive|define
name|XFS_GET_DIR_INO4
parameter_list|(
name|di
parameter_list|)
define|\
value|(((__u32)(di).i[0]<< 24) | ((di).i[1]<< 16) | ((di).i[2]<< 8) | ((di).i[3]))
end_define

begin_define
define|#
directive|define
name|XFS_PUT_DIR_INO4
parameter_list|(
name|from
parameter_list|,
name|di
parameter_list|)
define|\
value|do { \ 	(di).i[0] = (((from)& 0xff000000ULL)>> 24); \ 	(di).i[1] = (((from)& 0x00ff0000ULL)>> 16); \ 	(di).i[2] = (((from)& 0x0000ff00ULL)>> 8); \ 	(di).i[3] = ((from)& 0x000000ffULL); \ } while (0)
end_define

begin_define
define|#
directive|define
name|XFS_DI_HI
parameter_list|(
name|di
parameter_list|)
define|\
value|(((__u32)(di).i[1]<< 16) | ((di).i[2]<< 8) | ((di).i[3]))
end_define

begin_define
define|#
directive|define
name|XFS_DI_LO
parameter_list|(
name|di
parameter_list|)
define|\
value|(((__u32)(di).i[4]<< 24) | ((di).i[5]<< 16) | ((di).i[6]<< 8) | ((di).i[7]))
end_define

begin_define
define|#
directive|define
name|XFS_GET_DIR_INO8
parameter_list|(
name|di
parameter_list|)
define|\
value|(((xfs_ino_t)XFS_DI_LO(di)& 0xffffffffULL) | \ 	 ((xfs_ino_t)XFS_DI_HI(di)<< 32))
end_define

begin_define
define|#
directive|define
name|XFS_PUT_DIR_INO8
parameter_list|(
name|from
parameter_list|,
name|di
parameter_list|)
define|\
value|do { \ 	(di).i[0] = 0; \ 	(di).i[1] = (((from)& 0x00ff000000000000ULL)>> 48); \ 	(di).i[2] = (((from)& 0x0000ff0000000000ULL)>> 40); \ 	(di).i[3] = (((from)& 0x000000ff00000000ULL)>> 32); \ 	(di).i[4] = (((from)& 0x00000000ff000000ULL)>> 24); \ 	(di).i[5] = (((from)& 0x0000000000ff0000ULL)>> 16); \ 	(di).i[6] = (((from)& 0x000000000000ff00ULL)>> 8); \ 	(di).i[7] = ((from)& 0x00000000000000ffULL); \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_ARCH_H__ */
end_comment

end_unit

