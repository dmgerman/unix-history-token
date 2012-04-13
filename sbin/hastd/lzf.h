begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2008 Marc Alexander Lehmann<schmorp@schmorp.de>  *   * Redistribution and use in source and binary forms, with or without modifica-  * tion, are permitted provided that the following conditions are met:  *   *   1.  Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *   *   2.  Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MER-  * CHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO  * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPE-  * CIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTH-  * ERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, the contents of this file may be used under the terms of  * the GNU General Public License ("GPL") version 2 or any later version,  * in which case the provisions of the GPL are applicable instead of  * the above. If you wish to allow the use of your version of this file  * only under the terms of the GPL and not to allow others to use your  * version of this file under the BSD license, indicate your decision  * by deleting the provisions above and replace them with the notice  * and other provisions required by the GPL. If you do not delete the  * provisions above, a recipient may use your version of this file under  * either the BSD or the GPL.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZF_H
end_ifndef

begin_define
define|#
directive|define
name|LZF_H
end_define

begin_comment
comment|/*********************************************************************** ** **	lzf -- an extremely fast/free compression/decompression-method **	http://liblzf.plan9.de/ ** **	This algorithm is believed to be patent-free. ** ***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|LZF_VERSION
value|0x0105
end_define

begin_comment
comment|/* 1.5, API version */
end_comment

begin_comment
comment|/*  * Compress in_len bytes stored at the memory block starting at  * in_data and write the result to out_data, up to a maximum length  * of out_len bytes.  *  * If the output buffer is not large enough or any error occurs return 0,  * otherwise return the number of bytes used, which might be considerably  * more than in_len (but less than 104% of the original size), so it  * makes sense to always use out_len == in_len - 1), to ensure _some_  * compression, and store the data uncompressed otherwise (with a flag, of  * course.  *  * lzf_compress might use different algorithms on different systems and  * even different runs, thus might result in different compressed strings  * depending on the phase of the moon or similar factors. However, all  * these strings are architecture-independent and will result in the  * original data when decompressed using lzf_decompress.  *  * The buffers must not be overlapping.  *  * If the option LZF_STATE_ARG is enabled, an extra argument must be  * supplied which is not reflected in this header file. Refer to lzfP.h  * and lzf_c.c.  *  */
end_comment

begin_function_decl
name|unsigned
name|int
name|lzf_compress
parameter_list|(
specifier|const
name|void
modifier|*
specifier|const
name|in_data
parameter_list|,
name|unsigned
name|int
name|in_len
parameter_list|,
name|void
modifier|*
name|out_data
parameter_list|,
name|unsigned
name|int
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decompress data compressed with some version of the lzf_compress  * function and stored at location in_data and length in_len. The result  * will be stored at out_data up to a maximum of out_len characters.  *  * If the output buffer is not large enough to hold the decompressed  * data, a 0 is returned and errno is set to E2BIG. Otherwise the number  * of decompressed bytes (i.e. the original length of the data) is  * returned.  *  * If an error in the compressed data is detected, a zero is returned and  * errno is set to EINVAL.  *  * This function is very fast, about as fast as a copying loop.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|lzf_decompress
parameter_list|(
specifier|const
name|void
modifier|*
specifier|const
name|in_data
parameter_list|,
name|unsigned
name|int
name|in_len
parameter_list|,
name|void
modifier|*
name|out_data
parameter_list|,
name|unsigned
name|int
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Size of hashtable is (1<< HLOG) * sizeof (char *)  * decompression is independent of the hash table size  * the difference between 15 and 14 is very small  * for small blocks (and 14 is usually a bit faster).  * For a low-memory/faster configuration, use HLOG == 13;  * For best compression, use 15 or 16 (or more, up to 23).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HLOG
end_ifndef

begin_define
define|#
directive|define
name|HLOG
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Sacrifice very little compression quality in favour of compression speed.  * This gives almost the same compression as the default code, and is  * (very roughly) 15% faster. This is the preferred mode of operation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VERY_FAST
end_ifndef

begin_define
define|#
directive|define
name|VERY_FAST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Sacrifice some more compression quality in favour of compression speed.  * (roughly 1-2% worse compression for large blocks and  * 9-10% for small, redundant, blocks and>>20% better speed in both cases)  * In short: when in need for speed, enable this for binary data,  * possibly disable this for text data.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ULTRA_FAST
end_ifndef

begin_define
define|#
directive|define
name|ULTRA_FAST
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Unconditionally aligning does not cost very much, so do it if unsure  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRICT_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|STRICT_ALIGN
value|!(defined(__i386) || defined (__amd64))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * You may choose to pre-set the hash table (might be faster on some  * modern cpus and large (>>64k) blocks, and also makes compression  * deterministic/repeatable when the configuration otherwise is the same).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INIT_HTAB
end_ifndef

begin_define
define|#
directive|define
name|INIT_HTAB
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Avoid assigning values to errno variable? for some embedding purposes  * (linux kernel for example), this is necessary. NOTE: this breaks  * the documentation in lzf.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AVOID_ERRNO
end_ifndef

begin_define
define|#
directive|define
name|AVOID_ERRNO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Wether to pass the LZF_STATE variable as argument, or allocate it  * on the stack. For small-stack environments, define this to 1.  * NOTE: this breaks the prototype in lzf.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZF_STATE_ARG
end_ifndef

begin_define
define|#
directive|define
name|LZF_STATE_ARG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Wether to add extra checks for input validity in lzf_decompress  * and return EINVAL if the input stream has been corrupted. This  * only shields against overflowing the input buffer and will not  * detect most corrupted streams.  * This check is not normally noticeable on modern hardware  * (<1% slowdown), but might slow down older cpus considerably.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHECK_INPUT
end_ifndef

begin_define
define|#
directive|define
name|CHECK_INPUT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* nothing should be changed below */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|u8
modifier|*
name|LZF_STATE
index|[
literal|1
operator|<<
operator|(
name|HLOG
operator|)
index|]
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|STRICT_ALIGN
end_if

begin_comment
comment|/* for unaligned accesses we need a 16 bit datatype. */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
name|USHRT_MAX
operator|==
literal|65535
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u16
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|UINT_MAX
operator|==
literal|65535
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u16
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|STRICT_ALIGN
end_undef

begin_define
define|#
directive|define
name|STRICT_ALIGN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ULTRA_FAST
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VERY_FAST
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|VERY_FAST
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|INIT_HTAB
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

