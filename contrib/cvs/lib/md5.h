begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* See md5.c for explanation and copyright information.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MD5_H
end_ifndef

begin_define
define|#
directive|define
name|MD5_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|cvs_MD5Context
value|MD5Context
end_define

begin_define
define|#
directive|define
name|cvs_MD5Init
value|MD5Init
end_define

begin_define
define|#
directive|define
name|cvs_MD5Update
value|MD5Update
end_define

begin_define
define|#
directive|define
name|cvs_MD5Final
value|MD5Final
end_define

begin_define
define|#
directive|define
name|cvs_MD5Transform
value|MD5Transform
end_define

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Unlike previous versions of this code, uint32 need not be exactly    32 bits, merely 32 bits or more.  Choosing a data type which is 32    bits instead of 64 is not important; speed is considerably more    important.  ANSI guarantees that "unsigned long" will be big enough,    and always using it seems to have few disadvantages.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|cvs_uint32
typedef|;
end_typedef

begin_struct
struct|struct
name|cvs_MD5Context
block|{
name|cvs_uint32
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|cvs_uint32
name|bits
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|in
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|cvs_MD5Init
name|PROTO
argument_list|(
operator|(
expr|struct
name|cvs_MD5Context
operator|*
name|context
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cvs_MD5Update
name|PROTO
argument_list|(
operator|(
expr|struct
name|cvs_MD5Context
operator|*
name|context
operator|,
name|unsigned
name|char
specifier|const
operator|*
name|buf
operator|,
name|unsigned
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cvs_MD5Final
name|PROTO
argument_list|(
operator|(
name|unsigned
name|char
name|digest
index|[
literal|16
index|]
operator|,
expr|struct
name|cvs_MD5Context
operator|*
name|context
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cvs_MD5Transform
name|PROTO
argument_list|(
operator|(
name|cvs_uint32
name|buf
index|[
literal|4
index|]
operator|,
specifier|const
name|unsigned
name|char
name|in
index|[
literal|64
index|]
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

begin_comment
comment|/* !MD5_H */
end_comment

end_unit

