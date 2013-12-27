begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * AES (Rijndael) cipher  * Copyright (c) 2003-2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AES_I_H
end_ifndef

begin_define
define|#
directive|define
name|AES_I_H
end_define

begin_include
include|#
directive|include
file|"aes.h"
end_include

begin_comment
comment|/* #define FULL_UNROLL */
end_comment

begin_define
define|#
directive|define
name|AES_SMALL_TABLES
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Te0
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Te1
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Te2
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Te3
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Te4
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Td0
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Td1
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Td2
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Td3
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|Td4
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u32
name|rcon
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u8
name|Td4s
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u8
name|rcons
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|AES_SMALL_TABLES
end_ifndef

begin_define
define|#
directive|define
name|RCON
parameter_list|(
name|i
parameter_list|)
value|rcon[(i)]
end_define

begin_define
define|#
directive|define
name|TE0
parameter_list|(
name|i
parameter_list|)
value|Te0[((i)>> 24)& 0xff]
end_define

begin_define
define|#
directive|define
name|TE1
parameter_list|(
name|i
parameter_list|)
value|Te1[((i)>> 16)& 0xff]
end_define

begin_define
define|#
directive|define
name|TE2
parameter_list|(
name|i
parameter_list|)
value|Te2[((i)>> 8)& 0xff]
end_define

begin_define
define|#
directive|define
name|TE3
parameter_list|(
name|i
parameter_list|)
value|Te3[(i)& 0xff]
end_define

begin_define
define|#
directive|define
name|TE41
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 24)& 0xff]& 0xff000000)
end_define

begin_define
define|#
directive|define
name|TE42
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 16)& 0xff]& 0x00ff0000)
end_define

begin_define
define|#
directive|define
name|TE43
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 8)& 0xff]& 0x0000ff00)
end_define

begin_define
define|#
directive|define
name|TE44
parameter_list|(
name|i
parameter_list|)
value|(Te4[(i)& 0xff]& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TE421
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 16)& 0xff]& 0xff000000)
end_define

begin_define
define|#
directive|define
name|TE432
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 8)& 0xff]& 0x00ff0000)
end_define

begin_define
define|#
directive|define
name|TE443
parameter_list|(
name|i
parameter_list|)
value|(Te4[(i)& 0xff]& 0x0000ff00)
end_define

begin_define
define|#
directive|define
name|TE414
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 24)& 0xff]& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TE411
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 24)& 0xff]& 0xff000000)
end_define

begin_define
define|#
directive|define
name|TE422
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 16)& 0xff]& 0x00ff0000)
end_define

begin_define
define|#
directive|define
name|TE433
parameter_list|(
name|i
parameter_list|)
value|(Te4[((i)>> 8)& 0xff]& 0x0000ff00)
end_define

begin_define
define|#
directive|define
name|TE444
parameter_list|(
name|i
parameter_list|)
value|(Te4[(i)& 0xff]& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TE4
parameter_list|(
name|i
parameter_list|)
value|(Te4[(i)]& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TD0
parameter_list|(
name|i
parameter_list|)
value|Td0[((i)>> 24)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD1
parameter_list|(
name|i
parameter_list|)
value|Td1[((i)>> 16)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD2
parameter_list|(
name|i
parameter_list|)
value|Td2[((i)>> 8)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD3
parameter_list|(
name|i
parameter_list|)
value|Td3[(i)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD41
parameter_list|(
name|i
parameter_list|)
value|(Td4[((i)>> 24)& 0xff]& 0xff000000)
end_define

begin_define
define|#
directive|define
name|TD42
parameter_list|(
name|i
parameter_list|)
value|(Td4[((i)>> 16)& 0xff]& 0x00ff0000)
end_define

begin_define
define|#
directive|define
name|TD43
parameter_list|(
name|i
parameter_list|)
value|(Td4[((i)>> 8)& 0xff]& 0x0000ff00)
end_define

begin_define
define|#
directive|define
name|TD44
parameter_list|(
name|i
parameter_list|)
value|(Td4[(i)& 0xff]& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TD0_
parameter_list|(
name|i
parameter_list|)
value|Td0[(i)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD1_
parameter_list|(
name|i
parameter_list|)
value|Td1[(i)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD2_
parameter_list|(
name|i
parameter_list|)
value|Td2[(i)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD3_
parameter_list|(
name|i
parameter_list|)
value|Td3[(i)& 0xff]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* AES_SMALL_TABLES */
end_comment

begin_define
define|#
directive|define
name|RCON
parameter_list|(
name|i
parameter_list|)
value|(rcons[(i)]<< 24)
end_define

begin_function
specifier|static
specifier|inline
name|u32
name|rotr
parameter_list|(
name|u32
name|val
parameter_list|,
name|int
name|bits
parameter_list|)
block|{
return|return
operator|(
name|val
operator|>>
name|bits
operator|)
operator||
operator|(
name|val
operator|<<
operator|(
literal|32
operator|-
name|bits
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|TE0
parameter_list|(
name|i
parameter_list|)
value|Te0[((i)>> 24)& 0xff]
end_define

begin_define
define|#
directive|define
name|TE1
parameter_list|(
name|i
parameter_list|)
value|rotr(Te0[((i)>> 16)& 0xff], 8)
end_define

begin_define
define|#
directive|define
name|TE2
parameter_list|(
name|i
parameter_list|)
value|rotr(Te0[((i)>> 8)& 0xff], 16)
end_define

begin_define
define|#
directive|define
name|TE3
parameter_list|(
name|i
parameter_list|)
value|rotr(Te0[(i)& 0xff], 24)
end_define

begin_define
define|#
directive|define
name|TE41
parameter_list|(
name|i
parameter_list|)
value|((Te0[((i)>> 24)& 0xff]<< 8)& 0xff000000)
end_define

begin_define
define|#
directive|define
name|TE42
parameter_list|(
name|i
parameter_list|)
value|(Te0[((i)>> 16)& 0xff]& 0x00ff0000)
end_define

begin_define
define|#
directive|define
name|TE43
parameter_list|(
name|i
parameter_list|)
value|(Te0[((i)>> 8)& 0xff]& 0x0000ff00)
end_define

begin_define
define|#
directive|define
name|TE44
parameter_list|(
name|i
parameter_list|)
value|((Te0[(i)& 0xff]>> 8)& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TE421
parameter_list|(
name|i
parameter_list|)
value|((Te0[((i)>> 16)& 0xff]<< 8)& 0xff000000)
end_define

begin_define
define|#
directive|define
name|TE432
parameter_list|(
name|i
parameter_list|)
value|(Te0[((i)>> 8)& 0xff]& 0x00ff0000)
end_define

begin_define
define|#
directive|define
name|TE443
parameter_list|(
name|i
parameter_list|)
value|(Te0[(i)& 0xff]& 0x0000ff00)
end_define

begin_define
define|#
directive|define
name|TE414
parameter_list|(
name|i
parameter_list|)
value|((Te0[((i)>> 24)& 0xff]>> 8)& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TE411
parameter_list|(
name|i
parameter_list|)
value|((Te0[((i)>> 24)& 0xff]<< 8)& 0xff000000)
end_define

begin_define
define|#
directive|define
name|TE422
parameter_list|(
name|i
parameter_list|)
value|(Te0[((i)>> 16)& 0xff]& 0x00ff0000)
end_define

begin_define
define|#
directive|define
name|TE433
parameter_list|(
name|i
parameter_list|)
value|(Te0[((i)>> 8)& 0xff]& 0x0000ff00)
end_define

begin_define
define|#
directive|define
name|TE444
parameter_list|(
name|i
parameter_list|)
value|((Te0[(i)& 0xff]>> 8)& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TE4
parameter_list|(
name|i
parameter_list|)
value|((Te0[(i)]>> 8)& 0x000000ff)
end_define

begin_define
define|#
directive|define
name|TD0
parameter_list|(
name|i
parameter_list|)
value|Td0[((i)>> 24)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD1
parameter_list|(
name|i
parameter_list|)
value|rotr(Td0[((i)>> 16)& 0xff], 8)
end_define

begin_define
define|#
directive|define
name|TD2
parameter_list|(
name|i
parameter_list|)
value|rotr(Td0[((i)>> 8)& 0xff], 16)
end_define

begin_define
define|#
directive|define
name|TD3
parameter_list|(
name|i
parameter_list|)
value|rotr(Td0[(i)& 0xff], 24)
end_define

begin_define
define|#
directive|define
name|TD41
parameter_list|(
name|i
parameter_list|)
value|(Td4s[((i)>> 24)& 0xff]<< 24)
end_define

begin_define
define|#
directive|define
name|TD42
parameter_list|(
name|i
parameter_list|)
value|(Td4s[((i)>> 16)& 0xff]<< 16)
end_define

begin_define
define|#
directive|define
name|TD43
parameter_list|(
name|i
parameter_list|)
value|(Td4s[((i)>> 8)& 0xff]<< 8)
end_define

begin_define
define|#
directive|define
name|TD44
parameter_list|(
name|i
parameter_list|)
value|(Td4s[(i)& 0xff])
end_define

begin_define
define|#
directive|define
name|TD0_
parameter_list|(
name|i
parameter_list|)
value|Td0[(i)& 0xff]
end_define

begin_define
define|#
directive|define
name|TD1_
parameter_list|(
name|i
parameter_list|)
value|rotr(Td0[(i)& 0xff], 8)
end_define

begin_define
define|#
directive|define
name|TD2_
parameter_list|(
name|i
parameter_list|)
value|rotr(Td0[(i)& 0xff], 16)
end_define

begin_define
define|#
directive|define
name|TD3_
parameter_list|(
name|i
parameter_list|)
value|rotr(Td0[(i)& 0xff], 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AES_SMALL_TABLES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|x
parameter_list|)
value|(_lrotl(x, 8)& 0x00ff00ff | _lrotr(x, 8)& 0xff00ff00)
end_define

begin_define
define|#
directive|define
name|GETU32
parameter_list|(
name|p
parameter_list|)
value|SWAP(*((u32 *)(p)))
end_define

begin_define
define|#
directive|define
name|PUTU32
parameter_list|(
name|ct
parameter_list|,
name|st
parameter_list|)
value|{ *((u32 *)(ct)) = SWAP((st)); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GETU32
parameter_list|(
name|pt
parameter_list|)
value|(((u32)(pt)[0]<< 24) ^ ((u32)(pt)[1]<< 16) ^ \ ((u32)(pt)[2]<<  8) ^ ((u32)(pt)[3]))
end_define

begin_define
define|#
directive|define
name|PUTU32
parameter_list|(
name|ct
parameter_list|,
name|st
parameter_list|)
value|{ \ (ct)[0] = (u8)((st)>> 24); (ct)[1] = (u8)((st)>> 16); \ (ct)[2] = (u8)((st)>>  8); (ct)[3] = (u8)(st); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AES_PRIV_SIZE
value|(4 * 4 * 15 + 4)
end_define

begin_define
define|#
directive|define
name|AES_PRIV_NR_POS
value|(4 * 15)
end_define

begin_function_decl
name|int
name|rijndaelKeySetupEnc
parameter_list|(
name|u32
name|rk
index|[]
parameter_list|,
specifier|const
name|u8
name|cipherKey
index|[]
parameter_list|,
name|int
name|keyBits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AES_I_H */
end_comment

end_unit

