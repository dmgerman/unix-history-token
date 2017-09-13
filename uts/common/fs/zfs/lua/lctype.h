begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lctype.h,v 1.12.1.1 2013/04/12 18:48:47 roberto Exp $ ** 'ctype' functions for Lua ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lctype_h
end_ifndef

begin_define
define|#
directive|define
name|lctype_h
end_define

begin_include
include|#
directive|include
file|"lua.h"
end_include

begin_comment
comment|/* ** WARNING: the functions defined here do not necessarily correspond ** to the similar functions in the standard C ctype.h. They are ** optimized for the specific needs of Lua */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LUA_USE_CTYPE
argument_list|)
end_if

begin_if
if|#
directive|if
literal|'A'
operator|==
literal|65
operator|&&
literal|'0'
operator|==
literal|48
end_if

begin_comment
comment|/* ASCII case: can use its own tables; faster and fixed */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_CTYPE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* must use standard C ctype */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_CTYPE
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
operator|!
name|LUA_USE_CTYPE
end_if

begin_comment
comment|/* { */
end_comment

begin_include
include|#
directive|include
file|"llimits.h"
end_include

begin_define
define|#
directive|define
name|ALPHABIT
value|0
end_define

begin_define
define|#
directive|define
name|DIGITBIT
value|1
end_define

begin_define
define|#
directive|define
name|PRINTBIT
value|2
end_define

begin_define
define|#
directive|define
name|SPACEBIT
value|3
end_define

begin_define
define|#
directive|define
name|XDIGITBIT
value|4
end_define

begin_define
define|#
directive|define
name|MASK
parameter_list|(
name|B
parameter_list|)
value|(1<< (B))
end_define

begin_comment
comment|/* ** add 1 to char to allow index -1 (EOZ) */
end_comment

begin_define
define|#
directive|define
name|testprop
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|(luai_ctype_[(c)+1]& (p))
end_define

begin_comment
comment|/* ** 'lalpha' (Lua alphabetic) and 'lalnum' (Lua alphanumeric) both include '_' */
end_comment

begin_define
define|#
directive|define
name|lislalpha
parameter_list|(
name|c
parameter_list|)
value|testprop(c, MASK(ALPHABIT))
end_define

begin_define
define|#
directive|define
name|lislalnum
parameter_list|(
name|c
parameter_list|)
value|testprop(c, (MASK(ALPHABIT) | MASK(DIGITBIT)))
end_define

begin_define
define|#
directive|define
name|lisdigit
parameter_list|(
name|c
parameter_list|)
value|testprop(c, MASK(DIGITBIT))
end_define

begin_define
define|#
directive|define
name|lisspace
parameter_list|(
name|c
parameter_list|)
value|testprop(c, MASK(SPACEBIT))
end_define

begin_define
define|#
directive|define
name|lisprint
parameter_list|(
name|c
parameter_list|)
value|testprop(c, MASK(PRINTBIT))
end_define

begin_define
define|#
directive|define
name|lisxdigit
parameter_list|(
name|c
parameter_list|)
value|testprop(c, MASK(XDIGITBIT))
end_define

begin_comment
comment|/* ** this 'ltolower' only works for alphabetic characters */
end_comment

begin_define
define|#
directive|define
name|ltolower
parameter_list|(
name|c
parameter_list|)
value|((c) | ('A' ^ 'a'))
end_define

begin_comment
comment|/* two more entries for 0 and -1 (EOZ) */
end_comment

begin_decl_stmt
name|LUAI_DDEC
specifier|const
name|lu_byte
name|luai_ctype_
index|[
name|UCHAR_MAX
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_comment
comment|/* ** use standard C ctypes */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_define
define|#
directive|define
name|lislalpha
parameter_list|(
name|c
parameter_list|)
value|(isalpha(c) || (c) == '_')
end_define

begin_define
define|#
directive|define
name|lislalnum
parameter_list|(
name|c
parameter_list|)
value|(isalnum(c) || (c) == '_')
end_define

begin_define
define|#
directive|define
name|lisdigit
parameter_list|(
name|c
parameter_list|)
value|(isdigit(c))
end_define

begin_define
define|#
directive|define
name|lisspace
parameter_list|(
name|c
parameter_list|)
value|(isspace(c))
end_define

begin_define
define|#
directive|define
name|lisprint
parameter_list|(
name|c
parameter_list|)
value|(isprint(c))
end_define

begin_define
define|#
directive|define
name|lisxdigit
parameter_list|(
name|c
parameter_list|)
value|(isxdigit(c))
end_define

begin_define
define|#
directive|define
name|ltolower
parameter_list|(
name|c
parameter_list|)
value|(tolower(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

