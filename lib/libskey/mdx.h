begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|MD5
end_ifdef

begin_comment
comment|/* S/Key can use MD5 now, if defined... */
end_comment

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_define
define|#
directive|define
name|MDXFinal
value|MD5Final
end_define

begin_define
define|#
directive|define
name|MDXInit
value|MD5Init
end_define

begin_define
define|#
directive|define
name|MDXUpdate
value|MD5Update
end_define

begin_define
define|#
directive|define
name|MDX_CTX
value|MD5_CTX
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* By default, use MD4 for compatibility */
end_comment

begin_include
include|#
directive|include
file|<md4.h>
end_include

begin_define
define|#
directive|define
name|MDXFinal
value|MD4Final
end_define

begin_define
define|#
directive|define
name|MDXInit
value|MD4Init
end_define

begin_define
define|#
directive|define
name|MDXUpdate
value|MD4Update
end_define

begin_define
define|#
directive|define
name|MDX_CTX
value|MD4_CTX
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

