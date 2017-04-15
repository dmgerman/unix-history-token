begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Przemyslaw Skibinski, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_if
if|#
directive|if
name|ZLIB_VERNUM
operator|<=
literal|0x1240
end_if

begin_decl_stmt
name|ZEXTERN
name|int
name|ZEXPORT
name|gzclose_r
name|OF
argument_list|(
operator|(
name|gzFile
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZEXTERN
name|int
name|ZEXPORT
name|gzclose_w
name|OF
argument_list|(
operator|(
name|gzFile
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZEXTERN
name|int
name|ZEXPORT
name|gzbuffer
name|OF
argument_list|(
operator|(
name|gzFile
name|file
operator|,
name|unsigned
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZEXTERN
name|z_off_t
name|ZEXPORT
name|gzoffset
name|OF
argument_list|(
operator|(
name|gzFile
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|Z_LARGE64
argument_list|)
end_if

begin_define
define|#
directive|define
name|z_off64_t
value|off64_t
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Z_SOLO
argument_list|)
end_if

begin_define
define|#
directive|define
name|z_off64_t
value|__int64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|z_off64_t
value|z_off_t
end_define

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

begin_if
if|#
directive|if
name|ZLIB_VERNUM
operator|<=
literal|0x1250
end_if

begin_struct
struct|struct
name|gzFile_s
block|{
name|unsigned
name|have
decl_stmt|;
name|unsigned
name|char
modifier|*
name|next
decl_stmt|;
name|z_off64_t
name|pos
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ZLIB_VERNUM
operator|<=
literal|0x1270
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Z_SOLO
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* for wchar_t */
end_comment

begin_decl_stmt
name|ZEXTERN
name|gzFile
name|ZEXPORT
name|gzopen_w
name|OF
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
name|path
operator|,
specifier|const
name|char
operator|*
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|ZLIB_VERNUM
operator|<
literal|0x12B0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|Z_SOLO
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|z_size_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|z_longlong
value|long long
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NO_SIZE_T
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|NO_SIZE_T
name|z_size_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|STDC
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_typedef
typedef|typedef
name|size_t
name|z_size_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|z_size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|z_longlong
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|ZEXTERN
name|z_size_t
name|ZEXPORT
name|gzfread
name|OF
argument_list|(
operator|(
name|voidp
name|buf
operator|,
name|z_size_t
name|size
operator|,
name|z_size_t
name|nitems
operator|,
name|gzFile
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZEXTERN
name|z_size_t
name|ZEXPORT
name|gzfwrite
name|OF
argument_list|(
operator|(
name|voidpc
name|buf
operator|,
name|z_size_t
name|size
operator|,
name|z_size_t
name|nitems
operator|,
name|gzFile
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

