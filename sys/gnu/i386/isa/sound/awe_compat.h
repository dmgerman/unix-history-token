begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/awe_compat.h  *  * Compat defines for the AWE32/Sound Blaster 32 wave table synth. driver  *   version 0.4.2c; Oct. 7, 1997  *  * Copyright (C) 1996,1997 Takashi Iwai  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*----------------------------------------------------------------  * compatibility macros for AWE32 driver  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* redefine following macros */
end_comment

begin_undef
undef|#
directive|undef
name|IOCTL_IN
end_undef

begin_undef
undef|#
directive|undef
name|IOCTL_OUT
end_undef

begin_undef
undef|#
directive|undef
name|OUTW
end_undef

begin_undef
undef|#
directive|undef
name|COPY_FROM_USER
end_undef

begin_undef
undef|#
directive|undef
name|COPY_TO_USER
end_undef

begin_undef
undef|#
directive|undef
name|GET_BYTE_FROM_USER
end_undef

begin_undef
undef|#
directive|undef
name|GET_SHORT_FROM_USER
end_undef

begin_undef
undef|#
directive|undef
name|IOCTL_TO_USER
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_comment
comment|/*================================================================  * Linux macros  *================================================================*/
end_comment

begin_comment
comment|/* use inline prefix */
end_comment

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_comment
comment|/*----------------------------------------------------------------  * memory management for linux  *----------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AWE_OBSOLETE_VOXWARE
end_ifdef

begin_comment
comment|/* old type linux system */
end_comment

begin_comment
comment|/* i/o requests; nothing */
end_comment

begin_define
define|#
directive|define
name|awe_check_port
parameter_list|()
value|0
end_define

begin_comment
comment|/* always false */
end_comment

begin_define
define|#
directive|define
name|awe_request_region
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|awe_release_region
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_decl_stmt
specifier|static
name|int
name|_mem_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memory pointer for permanent buffers */
end_comment

begin_define
define|#
directive|define
name|my_malloc_init
parameter_list|(
name|memptr
parameter_list|)
value|_mem_start = (memptr)
end_define

begin_define
define|#
directive|define
name|my_malloc_memptr
parameter_list|()
value|_mem_start
end_define

begin_define
define|#
directive|define
name|my_free
parameter_list|(
name|ptr
parameter_list|)
end_define

begin_comment
comment|/* do nothing */
end_comment

begin_define
define|#
directive|define
name|my_realloc
parameter_list|(
name|buf
parameter_list|,
name|oldsize
parameter_list|,
name|size
parameter_list|)
value|NULL
end_define

begin_comment
comment|/* no realloc */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|my_malloc
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|char
modifier|*
name|ptr
decl_stmt|;
name|PERMANENT_MALLOC
argument_list|(
name|ptr
argument_list|,
name|char
operator|*
argument_list|,
name|size
argument_list|,
name|_mem_start
argument_list|)
expr_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
name|ptr
return|;
block|}
end_function

begin_comment
comment|/* allocate buffer only once */
end_comment

begin_define
define|#
directive|define
name|INIT_TABLE
parameter_list|(
name|buffer
parameter_list|,
name|index
parameter_list|,
name|nums
parameter_list|,
name|type
parameter_list|)
value|{\ buffer = my_malloc(sizeof(type) * (nums)); index = (nums);\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AWE_DYNAMIC_BUFFER
end_define

begin_define
define|#
directive|define
name|my_malloc_init
parameter_list|(
name|ptr
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|my_malloc_memptr
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|my_malloc
parameter_list|(
name|size
parameter_list|)
value|vmalloc(size)
end_define

begin_define
define|#
directive|define
name|my_free
parameter_list|(
name|ptr
parameter_list|)
value|if (ptr) {vfree(ptr);}
end_define

begin_function
specifier|static
name|void
modifier|*
name|my_realloc
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|oldsize
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|=
name|vmalloc
argument_list|(
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|memcpy
argument_list|(
name|ptr
argument_list|,
name|buf
argument_list|,
operator|(
operator|(
name|oldsize
operator|<
name|size
operator|)
condition|?
name|oldsize
else|:
name|size
operator|)
argument_list|)
expr_stmt|;
name|vfree
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

begin_comment
comment|/* do not allocate buffer at beginning */
end_comment

begin_define
define|#
directive|define
name|INIT_TABLE
parameter_list|(
name|buffer
parameter_list|,
name|index
parameter_list|,
name|nums
parameter_list|,
name|type
parameter_list|)
value|{buffer=NULL; index=0;}
end_define

begin_comment
comment|/* old type macro */
end_comment

begin_define
define|#
directive|define
name|RET_ERROR
parameter_list|(
name|err
parameter_list|)
value|-err
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*----------------------------------------------------------------  * i/o interfaces for linux  *----------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|OUTW
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
value|outw(data, addr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AWE_NEW_KERNEL_INTERFACE
end_ifdef

begin_define
define|#
directive|define
name|COPY_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|source
parameter_list|,
name|offs
parameter_list|,
name|count
parameter_list|)
define|\
value|copy_from_user(target, (source)+(offs), count)
end_define

begin_define
define|#
directive|define
name|GET_BYTE_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
define|\
value|get_user(target, (unsigned char*)&((addr)[offs]))
end_define

begin_define
define|#
directive|define
name|GET_SHORT_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
define|\
value|get_user(target, (unsigned short*)&((addr)[offs]))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AWE_OSS38
end_ifdef

begin_define
define|#
directive|define
name|IOCTL_TO_USER
parameter_list|(
name|target
parameter_list|,
name|offs
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
define|\
value|memcpy(target, (source)+(offs), count)
end_define

begin_define
define|#
directive|define
name|IO_WRITE_CHECK
parameter_list|(
name|cmd
parameter_list|)
value|(_SIOC_DIR(cmd)& _IOC_WRITE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IOCTL_TO_USER
parameter_list|(
name|target
parameter_list|,
name|offs
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
define|\
value|copy_to_user(target, (source)+(offs), count)
end_define

begin_define
define|#
directive|define
name|IO_WRITE_CHECK
parameter_list|(
name|cmd
parameter_list|)
value|(_IOC_DIR(cmd)& _IOC_WRITE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AWE_OSS38 */
end_comment

begin_define
define|#
directive|define
name|COPY_TO_USER
value|IOCTL_TO_USER
end_define

begin_define
define|#
directive|define
name|IOCTL_IN
parameter_list|(
name|arg
parameter_list|)
value|(*(int*)(arg))
end_define

begin_define
define|#
directive|define
name|IOCTL_OUT
parameter_list|(
name|arg
parameter_list|,
name|val
parameter_list|)
value|(*(int*)(arg) = (val))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* old type i/o */
end_comment

begin_define
define|#
directive|define
name|COPY_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|source
parameter_list|,
name|offs
parameter_list|,
name|count
parameter_list|)
define|\
value|memcpy_fromfs(target, (source)+(offs), (count))
end_define

begin_define
define|#
directive|define
name|GET_BYTE_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
define|\
value|*((char  *)&(target)) = get_fs_byte((addr)+(offs))
end_define

begin_define
define|#
directive|define
name|GET_SHORT_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
define|\
value|*((short *)&(target)) = get_fs_word((addr)+(offs))
end_define

begin_define
define|#
directive|define
name|IOCTL_TO_USER
parameter_list|(
name|target
parameter_list|,
name|offs
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
define|\
value|memcpy_tofs(target, (source)+(offs), (count))
end_define

begin_define
define|#
directive|define
name|COPY_TO_USER
value|IOCTL_TO_USER
end_define

begin_define
define|#
directive|define
name|IO_WRITE_CHECK
parameter_list|(
name|cmd
parameter_list|)
value|(cmd& IOC_IN)
end_define

begin_define
define|#
directive|define
name|IOCTL_IN
parameter_list|(
name|arg
parameter_list|)
value|get_fs_long((long *)(arg))
end_define

begin_define
define|#
directive|define
name|IOCTL_OUT
parameter_list|(
name|arg
parameter_list|,
name|ret
parameter_list|)
value|snd_ioctl_return((int *)arg, ret)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AWE_NEW_KERNEL_INTERFACE */
end_comment

begin_define
define|#
directive|define
name|BZERO
parameter_list|(
name|target
parameter_list|,
name|len
parameter_list|)
value|memset(target, 0, len)
end_define

begin_define
define|#
directive|define
name|MEMCPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
value|memcpy(dst, src, len)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_comment
comment|/*================================================================  * FreeBSD macros  *================================================================*/
end_comment

begin_comment
comment|/* inline is not checked yet.. maybe it'll work */
end_comment

begin_define
define|#
directive|define
name|INLINE
end_define

begin_comment
comment|/*inline*/
end_comment

begin_comment
comment|/*----------------------------------------------------------------  * memory management for freebsd  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* i/o requests; nothing */
end_comment

begin_define
define|#
directive|define
name|awe_check_port
parameter_list|()
value|0
end_define

begin_comment
comment|/* always false */
end_comment

begin_define
define|#
directive|define
name|awe_request_region
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|awe_release_region
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|AWE_DYNAMIC_BUFFER
end_define

begin_define
define|#
directive|define
name|my_malloc_init
parameter_list|(
name|ptr
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|my_malloc_memptr
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|my_malloc
parameter_list|(
name|size
parameter_list|)
value|malloc(size, M_TEMP, M_WAITOK)
end_define

begin_define
define|#
directive|define
name|my_free
parameter_list|(
name|ptr
parameter_list|)
value|if (ptr) {free(ptr, M_TEMP);}
end_define

begin_define
define|#
directive|define
name|INIT_TABLE
parameter_list|(
name|buffer
parameter_list|,
name|index
parameter_list|,
name|nums
parameter_list|,
name|type
parameter_list|)
value|{buffer=NULL; index=0;}
end_define

begin_comment
comment|/* it should be realloc? */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|my_realloc
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|oldsize
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|=
name|my_malloc
argument_list|(
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|memcpy
argument_list|(
name|ptr
argument_list|,
name|buf
argument_list|,
operator|(
operator|(
name|oldsize
operator|<
name|size
operator|)
condition|?
name|oldsize
else|:
name|size
operator|)
argument_list|)
expr_stmt|;
name|my_free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

begin_comment
comment|/*----------------------------------------------------------------  * i/o interfaces for freebsd  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* according to linux rule; the arguments are swapped */
end_comment

begin_define
define|#
directive|define
name|OUTW
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
value|outw(addr, data)
end_define

begin_define
define|#
directive|define
name|COPY_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|source
parameter_list|,
name|offs
parameter_list|,
name|count
parameter_list|)
define|\
value|uiomove(((caddr_t)(target)),(count),((struct uio *)(source)))
end_define

begin_define
define|#
directive|define
name|COPY_TO_USER
parameter_list|(
name|target
parameter_list|,
name|source
parameter_list|,
name|offs
parameter_list|,
name|count
parameter_list|)
define|\
value|uiomove(((caddr_t)(source)),(count),((struct uio *)(target)))
end_define

begin_define
define|#
directive|define
name|GET_BYTE_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
define|\
value|uiomove(((char*)&(target)), 1, ((struct uio *)(addr)))
end_define

begin_define
define|#
directive|define
name|GET_SHORT_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
define|\
value|uiomove(((char*)&(target)), 2, ((struct uio *)(addr)))
end_define

begin_define
define|#
directive|define
name|IOCTL_TO_USER
parameter_list|(
name|target
parameter_list|,
name|offs
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
define|\
value|memcpy(&((target)[offs]), (source), (count))
end_define

begin_define
define|#
directive|define
name|IO_WRITE_CHECK
parameter_list|(
name|cmd
parameter_list|)
value|(cmd& IOC_IN)
end_define

begin_define
define|#
directive|define
name|IOCTL_IN
parameter_list|(
name|arg
parameter_list|)
value|(*(int*)(arg))
end_define

begin_define
define|#
directive|define
name|IOCTL_OUT
parameter_list|(
name|arg
parameter_list|,
name|val
parameter_list|)
value|(*(int*)(arg) = (val))
end_define

begin_define
define|#
directive|define
name|BZERO
parameter_list|(
name|target
parameter_list|,
name|len
parameter_list|)
value|bzero((caddr_t)target, len)
end_define

begin_define
define|#
directive|define
name|MEMCPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
value|bcopy((caddr_t)src, (caddr_t)dst, len)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|AWE_OBSOLETE_VOXWARE
end_ifndef

begin_define
define|#
directive|define
name|printk
value|printf
end_define

begin_define
define|#
directive|define
name|RET_ERROR
parameter_list|(
name|err
parameter_list|)
value|-err
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

