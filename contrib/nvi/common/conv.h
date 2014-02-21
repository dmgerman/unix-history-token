begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  * Copyright (c) 2011, 2012  *	Zhihao Yuan.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	$Id: conv.h,v 2.32 2013/03/11 01:20:53 zy Exp $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ICONV
end_ifdef

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ICONV_TRADITIONAL
end_ifdef

begin_typedef
typedef|typedef
name|char
modifier|*
modifier|*
name|iconv_src_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
specifier|const
modifier|*
modifier|*
name|iconv_src_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|iconv_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * We can not use MB_CUR_MAX here, since UTF-8 may report it as 6, but  * a sequence longer than 4 is deprecated by RFC 3629.  */
end_comment

begin_define
define|#
directive|define
name|KEY_NEEDSWIDE
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|(INTISWIDE(ch)&& KEY_LEN(sp, ch)<= 4)
end_define

begin_define
define|#
directive|define
name|KEY_COL
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|(KEY_NEEDSWIDE(sp, ch) ? CHAR_WIDTH(sp, ch) : KEY_LEN(sp, ch))
end_define

begin_enum
enum|enum
block|{
name|IC_FE_CHAR2INT
block|,
name|IC_FE_INT2CHAR
block|,
name|IC_IE_CHAR2INT
block|,
name|IC_IE_TO_UTF16
block|}
enum|;
end_enum

begin_struct
struct|struct
name|_conv_win
block|{
union|union
block|{
name|char
modifier|*
name|c
decl_stmt|;
name|CHAR_T
modifier|*
name|wc
decl_stmt|;
block|}
name|bp1
union|;
name|size_t
name|blen1
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|char2wchar_t
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|ssize_t
parameter_list|,
name|struct
name|_conv_win
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|CHAR_T
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|wchar2char_t
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
specifier|const
name|CHAR_T
modifier|*
parameter_list|,
name|ssize_t
parameter_list|,
name|struct
name|_conv_win
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_conv
block|{
name|char2wchar_t
name|sys2int
decl_stmt|;
name|wchar2char_t
name|int2sys
decl_stmt|;
name|char2wchar_t
name|file2int
decl_stmt|;
name|wchar2char_t
name|int2file
decl_stmt|;
name|char2wchar_t
name|input2int
decl_stmt|;
name|iconv_t
name|id
index|[
name|IC_IE_TO_UTF16
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

