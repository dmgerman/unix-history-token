begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/* do we need conversion? */
end_comment

begin_define
define|#
directive|define
name|ARCH_NOCONVERT
value|1
end_define

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|ARCH_CONVERT
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARCH_CONVERT
value|ARCH_NOCONVERT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* generic swapping macros */
end_comment

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

begin_define
define|#
directive|define
name|INT_SWAP_UNALIGNED_32
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|{ \ 	((__u8*)(to))[0] = ((__u8*)(from))[3]; \ 	((__u8*)(to))[1] = ((__u8*)(from))[2]; \ 	((__u8*)(to))[2] = ((__u8*)(from))[1]; \ 	((__u8*)(to))[3] = ((__u8*)(from))[0]; \     }
end_define

begin_define
define|#
directive|define
name|INT_SWAP_UNALIGNED_64
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|{ \ 	INT_SWAP_UNALIGNED_32( ((__u8*)(from)) + 4, ((__u8*)(to))); \ 	INT_SWAP_UNALIGNED_32( ((__u8*)(from)), ((__u8*)(to)) + 4); \     }
end_define

begin_comment
comment|/*  * get and set integers from potentially unaligned locations  */
end_comment

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_16_LE
parameter_list|(
name|pointer
parameter_list|)
define|\
value|((__u16)((((__u8*)(pointer))[0]	) | (((__u8*)(pointer))[1]<< 8 )))
end_define

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
name|INT_SET_UNALIGNED_16_LE
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
define|\
value|{ \ 	((__u8*)(pointer))[0] = (((value)     )& 0xff); \ 	((__u8*)(pointer))[1] = (((value)>> 8)& 0xff); \     }
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

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_32_LE
parameter_list|(
name|pointer
parameter_list|)
define|\
value|((__u32)((((__u8*)(pointer))[0]	) | (((__u8*)(pointer))[1]<< 8 ) \ 	   |(((__u8*)(pointer))[2]<< 16) | (((__u8*)(pointer))[3]<< 24)))
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_32_BE
parameter_list|(
name|pointer
parameter_list|)
define|\
value|((__u32)((((__u8*)(pointer))[0]<< 24) | (((__u8*)(pointer))[1]<< 16) \ 	   |(((__u8*)(pointer))[2]<< 8)  | (((__u8*)(pointer))[3]	)))
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_32_LE
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
define|\
value|{ \ 	  INT_SET_UNALIGNED_16_LE(pointer, \ 		((value)& 0xffff)); \ 	  INT_SET_UNALIGNED_16_LE(((__u8*)(pointer))+2, \ 		(((value)>> 16)& 0xffff) ); \     }
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_32_BE
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
define|\
value|{ \ 	  INT_SET_UNALIGNED_16_BE(pointer, \ 	      	(((value)>> 16)& 0xffff) ); \ 	  INT_SET_UNALIGNED_16_BE(((__u8*)(pointer))+2, \ 	      	((value)& 0xffff) ); \     }
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_64_LE
parameter_list|(
name|pointer
parameter_list|)
define|\
value|(((__u64)(INT_GET_UNALIGNED_32_LE(((__u8*)(pointer))+4))<< 32 ) \    |((__u64)(INT_GET_UNALIGNED_32_LE(((__u8*)(pointer))	 ))	  ))
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_64_BE
parameter_list|(
name|pointer
parameter_list|)
define|\
value|(((__u64)(INT_GET_UNALIGNED_32_BE(((__u8*)(pointer))	 ))<< 32  ) \    |((__u64)(INT_GET_UNALIGNED_32_BE(((__u8*)(pointer))+4))	   ))
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_64_LE
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
define|\
value|{ \ 	  INT_SET_UNALIGNED_32_LE(pointer, \ 		((value)& 0xffffffff)); \ 	  INT_SET_UNALIGNED_32_LE(((__u8*)(pointer))+4, \ 		(((value)>> 32)& 0xffffffff) ); \     }
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_64_BE
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
define|\
value|{ \ 	  INT_SET_UNALIGNED_32_BE(pointer, \ 	      	(((value)>> 16)& 0xffff) ); \ 	  INT_SET_UNALIGNED_32_BE(((__u8*)(pointer))+4, \ 	      	((value)& 0xffff) ); \     }
end_define

begin_comment
comment|/*  * now pick the right ones for our MACHINE ARCHITECTURE  */
end_comment

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_16
parameter_list|(
name|pointer
parameter_list|)
value|INT_GET_UNALIGNED_16_LE(pointer)
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_16
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
value|INT_SET_UNALIGNED_16_LE(pointer,value)
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_32
parameter_list|(
name|pointer
parameter_list|)
value|INT_GET_UNALIGNED_32_LE(pointer)
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_32
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
value|INT_SET_UNALIGNED_32_LE(pointer,value)
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_64
parameter_list|(
name|pointer
parameter_list|)
value|INT_GET_UNALIGNED_64_LE(pointer)
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_64
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
value|INT_SET_UNALIGNED_64_LE(pointer,value)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_16
parameter_list|(
name|pointer
parameter_list|)
value|INT_GET_UNALIGNED_16_BE(pointer)
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_16
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
value|INT_SET_UNALIGNED_16_BE(pointer,value)
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_32
parameter_list|(
name|pointer
parameter_list|)
value|INT_GET_UNALIGNED_32_BE(pointer)
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_32
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
value|INT_SET_UNALIGNED_32_BE(pointer,value)
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_64
parameter_list|(
name|pointer
parameter_list|)
value|INT_GET_UNALIGNED_64_BE(pointer)
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_64
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|)
value|INT_SET_UNALIGNED_64_BE(pointer,value)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(void)(((arch) == ARCH_NOCONVERT) \ 	? \ 	    ((reference) code) \ 	: \ 	    ( \ 		(reference) = INT_GET((reference),arch) , \ 		((reference) code), \ 		INT_SET(reference, arch, reference) \ 	    ) \     )
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
value|(void)( \ 	((sizeof(dst) == sizeof(src)) || ((arch) == ARCH_NOCONVERT)) \ 	    ? \ 		((dst) = (src)) \ 	    : \ 		INT_SET(dst, arch, INT_GET(src, arch)) \     )
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

begin_define
define|#
directive|define
name|INT_ISZERO
parameter_list|(
name|reference
parameter_list|,
name|arch
parameter_list|)
define|\
value|((reference) == 0)
end_define

begin_define
define|#
directive|define
name|INT_ZERO
parameter_list|(
name|reference
parameter_list|,
name|arch
parameter_list|)
define|\
value|((reference) = 0)
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_16_ARCH
parameter_list|(
name|pointer
parameter_list|,
name|arch
parameter_list|)
define|\
value|( ((arch) == ARCH_NOCONVERT) \ 	? \ 	    (INT_GET_UNALIGNED_16(pointer)) \ 	: \ 	    (INT_GET_UNALIGNED_16_BE(pointer)) \     )
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_16_ARCH
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|,
name|arch
parameter_list|)
define|\
value|if ((arch) == ARCH_NOCONVERT) { \ 	INT_SET_UNALIGNED_16(pointer,value); \     } else { \ 	INT_SET_UNALIGNED_16_BE(pointer,value); \     }
end_define

begin_define
define|#
directive|define
name|INT_GET_UNALIGNED_64_ARCH
parameter_list|(
name|pointer
parameter_list|,
name|arch
parameter_list|)
define|\
value|( ((arch) == ARCH_NOCONVERT) \ 	? \ 	    (INT_GET_UNALIGNED_64(pointer)) \ 	: \ 	    (INT_GET_UNALIGNED_64_BE(pointer)) \     )
end_define

begin_define
define|#
directive|define
name|INT_SET_UNALIGNED_64_ARCH
parameter_list|(
name|pointer
parameter_list|,
name|value
parameter_list|,
name|arch
parameter_list|)
define|\
value|if ((arch) == ARCH_NOCONVERT) { \ 	INT_SET_UNALIGNED_64(pointer,value); \     } else { \ 	INT_SET_UNALIGNED_64_BE(pointer,value); \     }
end_define

begin_define
define|#
directive|define
name|DIRINO4_GET_ARCH
parameter_list|(
name|pointer
parameter_list|,
name|arch
parameter_list|)
define|\
value|( ((arch) == ARCH_NOCONVERT) \ 	? \ 	    (INT_GET_UNALIGNED_32(pointer)) \ 	: \ 	    (INT_GET_UNALIGNED_32_BE(pointer)) \     )
end_define

begin_if
if|#
directive|if
name|XFS_BIG_INUMS
end_if

begin_define
define|#
directive|define
name|DIRINO_GET_ARCH
parameter_list|(
name|pointer
parameter_list|,
name|arch
parameter_list|)
define|\
value|( ((arch) == ARCH_NOCONVERT) \ 	? \ 	    (INT_GET_UNALIGNED_64(pointer)) \ 	: \ 	    (INT_GET_UNALIGNED_64_BE(pointer)) \     )
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MACHINE ARCHITECTURE dependent */
end_comment

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|DIRINO_GET_ARCH
parameter_list|(
name|pointer
parameter_list|,
name|arch
parameter_list|)
define|\
value|DIRINO4_GET_ARCH((((__u8*)pointer)+4),arch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIRINO_GET_ARCH
parameter_list|(
name|pointer
parameter_list|,
name|arch
parameter_list|)
define|\
value|DIRINO4_GET_ARCH(pointer,arch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIRINO_COPY_ARCH
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|arch
parameter_list|)
define|\
value|if ((arch) == ARCH_NOCONVERT) { \ 	memcpy(to,from,sizeof(xfs_ino_t)); \     } else { \ 	INT_SWAP_UNALIGNED_64(from,to); \     }
end_define

begin_define
define|#
directive|define
name|DIRINO4_COPY_ARCH
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|arch
parameter_list|)
define|\
value|if ((arch) == ARCH_NOCONVERT) { \ 	memcpy(to,(((__u8*)from+4)),sizeof(xfs_dir2_ino4_t)); \     } else { \ 	INT_SWAP_UNALIGNED_32(from,to); \     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_ARCH_H__ */
end_comment

end_unit

