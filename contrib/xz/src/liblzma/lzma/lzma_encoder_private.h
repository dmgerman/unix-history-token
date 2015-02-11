begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       lzma_encoder_private.h
end_comment

begin_comment
comment|/// \brief      Private definitions for LZMA encoder
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//  Authors:    Igor Pavlov
end_comment

begin_comment
comment|//              Lasse Collin
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
name|LZMA_LZMA_ENCODER_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_LZMA_ENCODER_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"lz_encoder.h"
end_include

begin_include
include|#
directive|include
file|"range_encoder.h"
end_include

begin_include
include|#
directive|include
file|"lzma_common.h"
end_include

begin_include
include|#
directive|include
file|"lzma_encoder.h"
end_include

begin_comment
comment|// Macro to compare if the first two bytes in two buffers differ. This is
end_comment

begin_comment
comment|// needed in lzma_lzma_optimum_*() to test if the match is at least
end_comment

begin_comment
comment|// MATCH_LEN_MIN bytes. Unaligned access gives tiny gain so there's no
end_comment

begin_comment
comment|// reason to not use it when it is supported.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TUKLIB_FAST_UNALIGNED_ACCESS
end_ifdef

begin_define
define|#
directive|define
name|not_equal_16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(*(const uint16_t *)(a) != *(const uint16_t *)(b))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|not_equal_16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((a)[0] != (b)[0] || (a)[1] != (b)[1])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Optimal - Number of entries in the optimum array.
end_comment

begin_define
define|#
directive|define
name|OPTS
value|(1<< 12)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|probability
name|choice
decl_stmt|;
name|probability
name|choice2
decl_stmt|;
name|probability
name|low
index|[
name|POS_STATES_MAX
index|]
index|[
name|LEN_LOW_SYMBOLS
index|]
decl_stmt|;
name|probability
name|mid
index|[
name|POS_STATES_MAX
index|]
index|[
name|LEN_MID_SYMBOLS
index|]
decl_stmt|;
name|probability
name|high
index|[
name|LEN_HIGH_SYMBOLS
index|]
decl_stmt|;
name|uint32_t
name|prices
index|[
name|POS_STATES_MAX
index|]
index|[
name|LEN_SYMBOLS
index|]
decl_stmt|;
name|uint32_t
name|table_size
decl_stmt|;
name|uint32_t
name|counters
index|[
name|POS_STATES_MAX
index|]
decl_stmt|;
block|}
name|lzma_length_encoder
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|lzma_lzma_state
name|state
decl_stmt|;
name|bool
name|prev_1_is_literal
decl_stmt|;
name|bool
name|prev_2
decl_stmt|;
name|uint32_t
name|pos_prev_2
decl_stmt|;
name|uint32_t
name|back_prev_2
decl_stmt|;
name|uint32_t
name|price
decl_stmt|;
name|uint32_t
name|pos_prev
decl_stmt|;
comment|// pos_next;
name|uint32_t
name|back_prev
decl_stmt|;
name|uint32_t
name|backs
index|[
name|REPS
index|]
decl_stmt|;
block|}
name|lzma_optimal
typedef|;
end_typedef

begin_struct
struct|struct
name|lzma_coder_s
block|{
comment|/// Range encoder
name|lzma_range_encoder
name|rc
decl_stmt|;
comment|/// State
name|lzma_lzma_state
name|state
decl_stmt|;
comment|/// The four most recent match distances
name|uint32_t
name|reps
index|[
name|REPS
index|]
decl_stmt|;
comment|/// Array of match candidates
name|lzma_match
name|matches
index|[
name|MATCH_LEN_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/// Number of match candidates in matches[]
name|uint32_t
name|matches_count
decl_stmt|;
comment|/// Variable to hold the length of the longest match between calls
comment|/// to lzma_lzma_optimum_*().
name|uint32_t
name|longest_match_length
decl_stmt|;
comment|/// True if using getoptimumfast
name|bool
name|fast_mode
decl_stmt|;
comment|/// True if the encoder has been initialized by encoding the first
comment|/// byte as a literal.
name|bool
name|is_initialized
decl_stmt|;
comment|/// True if the range encoder has been flushed, but not all bytes
comment|/// have been written to the output buffer yet.
name|bool
name|is_flushed
decl_stmt|;
name|uint32_t
name|pos_mask
decl_stmt|;
comment|///< (1<< pos_bits) - 1
name|uint32_t
name|literal_context_bits
decl_stmt|;
name|uint32_t
name|literal_pos_mask
decl_stmt|;
comment|// These are the same as in lzma_decoder.c. See comments there.
name|probability
name|literal
index|[
name|LITERAL_CODERS_MAX
index|]
index|[
name|LITERAL_CODER_SIZE
index|]
decl_stmt|;
name|probability
name|is_match
index|[
name|STATES
index|]
index|[
name|POS_STATES_MAX
index|]
decl_stmt|;
name|probability
name|is_rep
index|[
name|STATES
index|]
decl_stmt|;
name|probability
name|is_rep0
index|[
name|STATES
index|]
decl_stmt|;
name|probability
name|is_rep1
index|[
name|STATES
index|]
decl_stmt|;
name|probability
name|is_rep2
index|[
name|STATES
index|]
decl_stmt|;
name|probability
name|is_rep0_long
index|[
name|STATES
index|]
index|[
name|POS_STATES_MAX
index|]
decl_stmt|;
name|probability
name|dist_slot
index|[
name|DIST_STATES
index|]
index|[
name|DIST_SLOTS
index|]
decl_stmt|;
name|probability
name|dist_special
index|[
name|FULL_DISTANCES
operator|-
name|DIST_MODEL_END
index|]
decl_stmt|;
name|probability
name|dist_align
index|[
name|ALIGN_SIZE
index|]
decl_stmt|;
comment|// These are the same as in lzma_decoder.c except that the encoders
comment|// include also price tables.
name|lzma_length_encoder
name|match_len_encoder
decl_stmt|;
name|lzma_length_encoder
name|rep_len_encoder
decl_stmt|;
comment|// Price tables
name|uint32_t
name|dist_slot_prices
index|[
name|DIST_STATES
index|]
index|[
name|DIST_SLOTS
index|]
decl_stmt|;
name|uint32_t
name|dist_prices
index|[
name|DIST_STATES
index|]
index|[
name|FULL_DISTANCES
index|]
decl_stmt|;
name|uint32_t
name|dist_table_size
decl_stmt|;
name|uint32_t
name|match_price_count
decl_stmt|;
name|uint32_t
name|align_prices
index|[
name|ALIGN_SIZE
index|]
decl_stmt|;
name|uint32_t
name|align_price_count
decl_stmt|;
comment|// Optimal
name|uint32_t
name|opts_end_index
decl_stmt|;
name|uint32_t
name|opts_current_index
decl_stmt|;
name|lzma_optimal
name|opts
index|[
name|OPTS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|lzma_lzma_optimum_fast
parameter_list|(
name|lzma_coder
modifier|*
specifier|restrict
name|coder
parameter_list|,
name|lzma_mf
modifier|*
specifier|restrict
name|mf
parameter_list|,
name|uint32_t
modifier|*
specifier|restrict
name|back_res
parameter_list|,
name|uint32_t
modifier|*
specifier|restrict
name|len_res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lzma_lzma_optimum_normal
parameter_list|(
name|lzma_coder
modifier|*
specifier|restrict
name|coder
parameter_list|,
name|lzma_mf
modifier|*
specifier|restrict
name|mf
parameter_list|,
name|uint32_t
modifier|*
specifier|restrict
name|back_res
parameter_list|,
name|uint32_t
modifier|*
specifier|restrict
name|len_res
parameter_list|,
name|uint32_t
name|position
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

