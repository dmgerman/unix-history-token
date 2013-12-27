begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_include
include|#
directive|include
file|"ah.h"
end_include

begin_include
include|#
directive|include
file|"ah_internal.h"
end_include

begin_include
include|#
directive|include
file|"ar5416/ar5416.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|int
name|keyType
index|[]
init|=
block|{
literal|1
block|,
comment|/* HAL_CIPHER_WEP */
literal|0
block|,
comment|/* HAL_CIPHER_AES_OCB */
literal|2
block|,
comment|/* HAL_CIPHER_AES_CCM */
literal|0
block|,
comment|/* HAL_CIPHER_CKIP */
literal|3
block|,
comment|/* HAL_CIPHER_TKIP */
literal|0
block|,
comment|/* HAL_CIPHER_CLR */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Clear the specified key cache entry and any associated MIC entry.  */
end_comment

begin_function
name|HAL_BOOL
name|ar5416ResetKeyCacheEntry
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|uint16_t
name|entry
parameter_list|)
block|{
name|struct
name|ath_hal_5416
modifier|*
name|ahp
init|=
name|AH5416
argument_list|(
name|ah
argument_list|)
decl_stmt|;
if|if
condition|(
name|ar5212ResetKeyCacheEntry
argument_list|(
name|ah
argument_list|,
name|entry
argument_list|)
condition|)
block|{
name|ahp
operator|->
name|ah_keytype
index|[
name|entry
index|]
operator|=
name|keyType
index|[
name|HAL_CIPHER_CLR
index|]
expr_stmt|;
return|return
name|AH_TRUE
return|;
block|}
else|else
return|return
name|AH_FALSE
return|;
block|}
end_function

begin_comment
comment|/*  * Sets the contents of the specified key cache entry  * and any associated MIC entry.  */
end_comment

begin_function
name|HAL_BOOL
name|ar5416SetKeyCacheEntry
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|uint16_t
name|entry
parameter_list|,
specifier|const
name|HAL_KEYVAL
modifier|*
name|k
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|mac
parameter_list|,
name|int
name|xorKey
parameter_list|)
block|{
name|struct
name|ath_hal_5416
modifier|*
name|ahp
init|=
name|AH5416
argument_list|(
name|ah
argument_list|)
decl_stmt|;
if|if
condition|(
name|ar5212SetKeyCacheEntry
argument_list|(
name|ah
argument_list|,
name|entry
argument_list|,
name|k
argument_list|,
name|mac
argument_list|,
name|xorKey
argument_list|)
condition|)
block|{
name|ahp
operator|->
name|ah_keytype
index|[
name|entry
index|]
operator|=
name|keyType
index|[
name|k
operator|->
name|kv_type
index|]
expr_stmt|;
return|return
name|AH_TRUE
return|;
block|}
else|else
return|return
name|AH_FALSE
return|;
block|}
end_function

end_unit

