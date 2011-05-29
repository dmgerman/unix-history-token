begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2007 Voltaire Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__COMMON_H__
end_ifndef

begin_define
define|#
directive|define
name|__COMMON_H__
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/byteswap.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_function
name|BEGIN_C_DECLS
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
ifndef|#
directive|ifndef
name|ntohll
specifier|static
specifier|inline
name|uint64_t
name|ntohll
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|bswap_64
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|htonll
end_ifndef

begin_function
specifier|static
specifier|inline
name|uint64_t
name|htonll
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|bswap_64
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|ntohll
end_ifndef

begin_function
specifier|static
specifier|inline
name|uint64_t
name|ntohll
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|htonll
end_ifndef

begin_function
specifier|static
specifier|inline
name|uint64_t
name|htonll
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BYTE_ORDER == __BIG_ENDIAN */
end_comment

begin_comment
comment|/*****************************  * COMMON MACHINE INDEPENDENT  */
end_comment

begin_comment
comment|/* Misc. macros: */
end_comment

begin_comment
comment|/** align value \a l to \a size (ceil) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALIGN
end_ifndef

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|l
parameter_list|,
name|size
parameter_list|)
value|(((l) + ((size) - 1)) / (size) * (size))
end_define

begin_comment
comment|/** align value \a l to \a sizeof 32 bit int (ceil) */
end_comment

begin_define
define|#
directive|define
name|ALIGN32
parameter_list|(
name|l
parameter_list|)
value|(ALIGN((l), sizeof(uint32)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** printf style debugging MACRO, conmmon header includes name of function */
end_comment

begin_define
define|#
directive|define
name|IBWARN
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|ibwarn(__FUNCTION__, fmt, ## args)
end_define

begin_comment
comment|/** printf style debugging MACRO, conmmon header includes name of function */
end_comment

begin_define
define|#
directive|define
name|LOG
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|logmsg(__FUNCTION__, fmt, ## args)
end_define

begin_comment
comment|/** printf style abort MACRO, common header includes name of function */
end_comment

begin_define
define|#
directive|define
name|IBPANIC
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|ibpanic(__FUNCTION__, fmt, ## args)
end_define

begin_comment
comment|/** abort program if expression \a x is \b false */
end_comment

begin_define
define|#
directive|define
name|SANITY
parameter_list|(
name|x
parameter_list|)
value|if (common.sanity&& !(x))\ 					ibpanic(__FUNCTION__,\ 					"sanity check<%s> failed: line %d",\ 					(x), __LINE__)
end_define

begin_comment
comment|/** avoid unused compilation warning  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USED
end_ifndef

begin_define
define|#
directive|define
name|USED
parameter_list|(
name|x
parameter_list|)
value|while(0) {void *v =&(x); printf("%p", v);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** define index macro for string array generated by enumstr.awk */
end_comment

begin_define
define|#
directive|define
name|ENUM_STR_DEF
parameter_list|(
name|enumname
parameter_list|,
name|last
parameter_list|,
name|val
parameter_list|)
value|(((unsigned)(val)< last) ? enumname ## _str[val] : "???")
end_define

begin_define
define|#
directive|define
name|ENUM_STR_ARRAY
parameter_list|(
name|name
parameter_list|)
value|char * name ## _str[]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|IBCOMMON_STRICT_FORMAT
value|__attribute__((format(printf, 2, 3)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IBCOMMON_STRICT_FORMAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* util.c: debugging and tracing */
end_comment

begin_decl_stmt
name|void
name|ibwarn
argument_list|(
specifier|const
name|char
operator|*
specifier|const
name|fn
argument_list|,
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
name|IBCOMMON_STRICT_FORMAT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ibpanic
argument_list|(
specifier|const
name|char
operator|*
specifier|const
name|fn
argument_list|,
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
name|IBCOMMON_STRICT_FORMAT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|logmsg
argument_list|(
specifier|const
name|char
operator|*
specifier|const
name|fn
argument_list|,
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
name|IBCOMMON_STRICT_FORMAT
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|xdump
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sysfs.c: /sys utilities */
end_comment

begin_function_decl
name|int
name|sys_read_string
parameter_list|(
name|char
modifier|*
name|dir_name
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|int
name|max_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sys_read_guid
parameter_list|(
name|char
modifier|*
name|dir_name
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|uint64_t
modifier|*
name|net_guid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sys_read_gid
parameter_list|(
name|char
modifier|*
name|dir_name
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|uint8_t
modifier|*
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sys_read_uint64
parameter_list|(
name|char
modifier|*
name|dir_name
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|uint64_t
modifier|*
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sys_read_uint
parameter_list|(
name|char
modifier|*
name|dir_name
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|unsigned
modifier|*
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sys_scandir
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|,
name|struct
name|dirent
modifier|*
modifier|*
modifier|*
name|namelist
parameter_list|,
name|int
function_decl|(
modifier|*
name|select
function_decl|)
parameter_list|(
specifier|const
name|struct
name|dirent
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|compar
function_decl|)
parameter_list|(
specifier|const
name|struct
name|dirent
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|dirent
modifier|*
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stack.c */
end_comment

begin_function_decl
name|void
name|stack_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enable_stack_dump
parameter_list|(
name|int
name|loop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* time.c */
end_comment

begin_function_decl
name|uint64_t
name|getcurrenttime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* hash.c */
end_comment

begin_function_decl
name|uint32_t
name|fhash
parameter_list|(
name|uint8_t
modifier|*
name|k
parameter_list|,
name|int
name|length
parameter_list|,
name|uint32_t
name|initval
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __COMMON_H__ */
end_comment

end_unit

