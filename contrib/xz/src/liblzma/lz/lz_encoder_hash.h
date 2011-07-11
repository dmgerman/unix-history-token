begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       lz_encoder_hash.h
end_comment

begin_comment
comment|/// \brief      Hash macros for match finders
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Igor Pavlov
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_LZ_ENCODER_HASH_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_LZ_ENCODER_HASH_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WORDS_BIGENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SMALL
argument_list|)
end_if

begin_comment
comment|// This is to make liblzma produce the same output on big endian
end_comment

begin_comment
comment|// systems that it does on little endian systems. lz_encoder.c
end_comment

begin_comment
comment|// takes care of including the actual table.
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|uint32_t
name|lzma_lz_hash_table
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|hash_table
value|lzma_lz_hash_table
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"check.h"
end_include

begin_define
define|#
directive|define
name|hash_table
value|lzma_crc32_table[0]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HASH_2_SIZE
value|(UINT32_C(1)<< 10)
end_define

begin_define
define|#
directive|define
name|HASH_3_SIZE
value|(UINT32_C(1)<< 16)
end_define

begin_define
define|#
directive|define
name|HASH_4_SIZE
value|(UINT32_C(1)<< 20)
end_define

begin_define
define|#
directive|define
name|HASH_2_MASK
value|(HASH_2_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|HASH_3_MASK
value|(HASH_3_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|HASH_4_MASK
value|(HASH_4_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|FIX_3_HASH_SIZE
value|(HASH_2_SIZE)
end_define

begin_define
define|#
directive|define
name|FIX_4_HASH_SIZE
value|(HASH_2_SIZE + HASH_3_SIZE)
end_define

begin_define
define|#
directive|define
name|FIX_5_HASH_SIZE
value|(HASH_2_SIZE + HASH_3_SIZE + HASH_4_SIZE)
end_define

begin_comment
comment|// Endianness doesn't matter in hash_2_calc() (no effect on the output).
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TUKLIB_FAST_UNALIGNED_ACCESS
end_ifdef

begin_define
define|#
directive|define
name|hash_2_calc
parameter_list|()
define|\
value|const uint32_t hash_value = *(const uint16_t *)(cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|hash_2_calc
parameter_list|()
define|\
value|const uint32_t hash_value \ 			= (uint32_t)(cur[0]) | ((uint32_t)(cur[1])<< 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|hash_3_calc
parameter_list|()
define|\
value|const uint32_t temp = hash_table[cur[0]] ^ cur[1]; \ 	const uint32_t hash_2_value = temp& HASH_2_MASK; \ 	const uint32_t hash_value \ 			= (temp ^ ((uint32_t)(cur[2])<< 8))& mf->hash_mask
end_define

begin_define
define|#
directive|define
name|hash_4_calc
parameter_list|()
define|\
value|const uint32_t temp = hash_table[cur[0]] ^ cur[1]; \ 	const uint32_t hash_2_value = temp& HASH_2_MASK; \ 	const uint32_t hash_3_value \ 			= (temp ^ ((uint32_t)(cur[2])<< 8))& HASH_3_MASK; \ 	const uint32_t hash_value = (temp ^ ((uint32_t)(cur[2])<< 8) \ 			^ (hash_table[cur[3]]<< 5))& mf->hash_mask
end_define

begin_comment
comment|// The following are not currently used.
end_comment

begin_define
define|#
directive|define
name|hash_5_calc
parameter_list|()
define|\
value|const uint32_t temp = hash_table[cur[0]] ^ cur[1]; \ 	const uint32_t hash_2_value = temp& HASH_2_MASK; \ 	const uint32_t hash_3_value \ 			= (temp ^ ((uint32_t)(cur[2])<< 8))& HASH_3_MASK; \ 	uint32_t hash_4_value = (temp ^ ((uint32_t)(cur[2])<< 8) ^ \ 			^ hash_table[cur[3]]<< 5); \ 	const uint32_t hash_value \ 			= (hash_4_value ^ (hash_table[cur[4]]<< 3)) \& mf->hash_mask; \ 	hash_4_value&= HASH_4_MASK
end_define

begin_comment
comment|/* #define hash_zip_calc() \ 	const uint32_t hash_value \ 			= (((uint32_t)(cur[0]) | ((uint32_t)(cur[1])<< 8)) \ 				^ hash_table[cur[2]])& 0xFFFF */
end_comment

begin_define
define|#
directive|define
name|hash_zip_calc
parameter_list|()
define|\
value|const uint32_t hash_value \ 			= (((uint32_t)(cur[2]) | ((uint32_t)(cur[0])<< 8)) \ 				^ hash_table[cur[1]])& 0xFFFF
end_define

begin_define
define|#
directive|define
name|mt_hash_2_calc
parameter_list|()
define|\
value|const uint32_t hash_2_value \ 			= (hash_table[cur[0]] ^ cur[1])& HASH_2_MASK
end_define

begin_define
define|#
directive|define
name|mt_hash_3_calc
parameter_list|()
define|\
value|const uint32_t temp = hash_table[cur[0]] ^ cur[1]; \ 	const uint32_t hash_2_value = temp& HASH_2_MASK; \ 	const uint32_t hash_3_value \ 			= (temp ^ ((uint32_t)(cur[2])<< 8))& HASH_3_MASK
end_define

begin_define
define|#
directive|define
name|mt_hash_4_calc
parameter_list|()
define|\
value|const uint32_t temp = hash_table[cur[0]] ^ cur[1]; \ 	const uint32_t hash_2_value = temp& HASH_2_MASK; \ 	const uint32_t hash_3_value \ 			= (temp ^ ((uint32_t)(cur[2])<< 8))& HASH_3_MASK; \ 	const uint32_t hash_4_value = (temp ^ ((uint32_t)(cur[2])<< 8) ^ \ 			(hash_table[cur[3]]<< 5))& HASH_4_MASK
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

