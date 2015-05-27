begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       lzma_common.h
end_comment

begin_comment
comment|/// \brief      Private definitions common to LZMA encoder and decoder
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
name|LZMA_LZMA_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_LZMA_COMMON_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"range_common.h"
end_include

begin_comment
comment|///////////////////
end_comment

begin_comment
comment|// Miscellaneous //
end_comment

begin_comment
comment|///////////////////
end_comment

begin_comment
comment|/// Maximum number of position states. A position state is the lowest pos bits
end_comment

begin_comment
comment|/// number of bits of the current uncompressed offset. In some places there
end_comment

begin_comment
comment|/// are different sets of probabilities for different pos states.
end_comment

begin_define
define|#
directive|define
name|POS_STATES_MAX
value|(1<< LZMA_PB_MAX)
end_define

begin_comment
comment|/// Validates lc, lp, and pb.
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|is_lclppb_valid
parameter_list|(
specifier|const
name|lzma_options_lzma
modifier|*
name|options
parameter_list|)
block|{
return|return
name|options
operator|->
name|lc
operator|<=
name|LZMA_LCLP_MAX
operator|&&
name|options
operator|->
name|lp
operator|<=
name|LZMA_LCLP_MAX
operator|&&
name|options
operator|->
name|lc
operator|+
name|options
operator|->
name|lp
operator|<=
name|LZMA_LCLP_MAX
operator|&&
name|options
operator|->
name|pb
operator|<=
name|LZMA_PB_MAX
return|;
block|}
end_function

begin_comment
comment|///////////
end_comment

begin_comment
comment|// State //
end_comment

begin_comment
comment|///////////
end_comment

begin_comment
comment|/// This enum is used to track which events have occurred most recently and
end_comment

begin_comment
comment|/// in which order. This information is used to predict the next event.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Events:
end_comment

begin_comment
comment|///  - Literal: One 8-bit byte
end_comment

begin_comment
comment|///  - Match: Repeat a chunk of data at some distance
end_comment

begin_comment
comment|///  - Long repeat: Multi-byte match at a recently seen distance
end_comment

begin_comment
comment|///  - Short repeat: One-byte repeat at a recently seen distance
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The event names are in from STATE_oldest_older_previous. REP means
end_comment

begin_comment
comment|/// either short or long repeated match, and NONLIT means any non-literal.
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|STATE_LIT_LIT
block|,
name|STATE_MATCH_LIT_LIT
block|,
name|STATE_REP_LIT_LIT
block|,
name|STATE_SHORTREP_LIT_LIT
block|,
name|STATE_MATCH_LIT
block|,
name|STATE_REP_LIT
block|,
name|STATE_SHORTREP_LIT
block|,
name|STATE_LIT_MATCH
block|,
name|STATE_LIT_LONGREP
block|,
name|STATE_LIT_SHORTREP
block|,
name|STATE_NONLIT_MATCH
block|,
name|STATE_NONLIT_REP
block|, }
name|lzma_lzma_state
typedef|;
end_typedef

begin_comment
comment|/// Total number of states
end_comment

begin_define
define|#
directive|define
name|STATES
value|12
end_define

begin_comment
comment|/// The lowest 7 states indicate that the previous state was a literal.
end_comment

begin_define
define|#
directive|define
name|LIT_STATES
value|7
end_define

begin_comment
comment|/// Indicate that the latest state was a literal.
end_comment

begin_define
define|#
directive|define
name|update_literal
parameter_list|(
name|state
parameter_list|)
define|\
value|state = ((state)<= STATE_SHORTREP_LIT_LIT \ 			? STATE_LIT_LIT \ 			: ((state)<= STATE_LIT_SHORTREP \ 				? (state) - 3 \ 				: (state) - 6))
end_define

begin_comment
comment|/// Indicate that the latest state was a match.
end_comment

begin_define
define|#
directive|define
name|update_match
parameter_list|(
name|state
parameter_list|)
define|\
value|state = ((state)< LIT_STATES ? STATE_LIT_MATCH : STATE_NONLIT_MATCH)
end_define

begin_comment
comment|/// Indicate that the latest state was a long repeated match.
end_comment

begin_define
define|#
directive|define
name|update_long_rep
parameter_list|(
name|state
parameter_list|)
define|\
value|state = ((state)< LIT_STATES ? STATE_LIT_LONGREP : STATE_NONLIT_REP)
end_define

begin_comment
comment|/// Indicate that the latest state was a short match.
end_comment

begin_define
define|#
directive|define
name|update_short_rep
parameter_list|(
name|state
parameter_list|)
define|\
value|state = ((state)< LIT_STATES ? STATE_LIT_SHORTREP : STATE_NONLIT_REP)
end_define

begin_comment
comment|/// Test if the previous state was a literal.
end_comment

begin_define
define|#
directive|define
name|is_literal_state
parameter_list|(
name|state
parameter_list|)
define|\
value|((state)< LIT_STATES)
end_define

begin_comment
comment|/////////////
end_comment

begin_comment
comment|// Literal //
end_comment

begin_comment
comment|/////////////
end_comment

begin_comment
comment|/// Each literal coder is divided in three sections:
end_comment

begin_comment
comment|///   - 0x001-0x0FF: Without match byte
end_comment

begin_comment
comment|///   - 0x101-0x1FF: With match byte; match bit is 0
end_comment

begin_comment
comment|///   - 0x201-0x2FF: With match byte; match bit is 1
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Match byte is used when the previous LZMA symbol was something else than
end_comment

begin_comment
comment|/// a literal (that is, it was some kind of match).
end_comment

begin_define
define|#
directive|define
name|LITERAL_CODER_SIZE
value|0x300
end_define

begin_comment
comment|/// Maximum number of literal coders
end_comment

begin_define
define|#
directive|define
name|LITERAL_CODERS_MAX
value|(1<< LZMA_LCLP_MAX)
end_define

begin_comment
comment|/// Locate the literal coder for the next literal byte. The choice depends on
end_comment

begin_comment
comment|///   - the lowest literal_pos_bits bits of the position of the current
end_comment

begin_comment
comment|///     byte; and
end_comment

begin_comment
comment|///   - the highest literal_context_bits bits of the previous byte.
end_comment

begin_define
define|#
directive|define
name|literal_subcoder
parameter_list|(
name|probs
parameter_list|,
name|lc
parameter_list|,
name|lp_mask
parameter_list|,
name|pos
parameter_list|,
name|prev_byte
parameter_list|)
define|\
value|((probs)[(((pos)& lp_mask)<< lc) + ((prev_byte)>> (8 - lc))])
end_define

begin_decl_stmt
specifier|static
specifier|inline
name|void
name|literal_init
argument_list|(
name|probability
argument_list|(
operator|*
name|probs
argument_list|)
index|[
name|LITERAL_CODER_SIZE
index|]
argument_list|,
name|uint32_t
name|lc
argument_list|,
name|uint32_t
name|lp
argument_list|)
block|{
name|assert
argument_list|(
name|lc
operator|+
name|lp
operator|<=
name|LZMA_LCLP_MAX
argument_list|)
expr_stmt|;
specifier|const
name|uint32_t
name|coders
init|=
literal|1U
operator|<<
operator|(
name|lc
operator|+
name|lp
operator|)
decl_stmt|;
for|for
control|(
name|uint32_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|coders
condition|;
operator|++
name|i
control|)
for|for
control|(
name|uint32_t
name|j
init|=
literal|0
init|;
name|j
operator|<
name|LITERAL_CODER_SIZE
condition|;
operator|++
name|j
control|)
name|bit_reset
argument_list|(
name|probs
index|[
name|i
index|]
index|[
name|j
index|]
argument_list|)
expr_stmt|;
return|return;
block|}
end_decl_stmt

begin_comment
comment|//////////////////
end_comment

begin_comment
comment|// Match length //
end_comment

begin_comment
comment|//////////////////
end_comment

begin_comment
comment|// Minimum length of a match is two bytes.
end_comment

begin_define
define|#
directive|define
name|MATCH_LEN_MIN
value|2
end_define

begin_comment
comment|// Match length is encoded with 4, 5, or 10 bits.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Length   Bits
end_comment

begin_comment
comment|//  2-9      4 = Choice=0 + 3 bits
end_comment

begin_comment
comment|// 10-17     5 = Choice=1 + Choice2=0 + 3 bits
end_comment

begin_comment
comment|// 18-273   10 = Choice=1 + Choice2=1 + 8 bits
end_comment

begin_define
define|#
directive|define
name|LEN_LOW_BITS
value|3
end_define

begin_define
define|#
directive|define
name|LEN_LOW_SYMBOLS
value|(1<< LEN_LOW_BITS)
end_define

begin_define
define|#
directive|define
name|LEN_MID_BITS
value|3
end_define

begin_define
define|#
directive|define
name|LEN_MID_SYMBOLS
value|(1<< LEN_MID_BITS)
end_define

begin_define
define|#
directive|define
name|LEN_HIGH_BITS
value|8
end_define

begin_define
define|#
directive|define
name|LEN_HIGH_SYMBOLS
value|(1<< LEN_HIGH_BITS)
end_define

begin_define
define|#
directive|define
name|LEN_SYMBOLS
value|(LEN_LOW_SYMBOLS + LEN_MID_SYMBOLS + LEN_HIGH_SYMBOLS)
end_define

begin_comment
comment|// Maximum length of a match is 273 which is a result of the encoding
end_comment

begin_comment
comment|// described above.
end_comment

begin_define
define|#
directive|define
name|MATCH_LEN_MAX
value|(MATCH_LEN_MIN + LEN_SYMBOLS - 1)
end_define

begin_comment
comment|////////////////////
end_comment

begin_comment
comment|// Match distance //
end_comment

begin_comment
comment|////////////////////
end_comment

begin_comment
comment|// Different sets of probabilities are used for match distances that have very
end_comment

begin_comment
comment|// short match length: Lengths of 2, 3, and 4 bytes have a separate set of
end_comment

begin_comment
comment|// probabilities for each length. The matches with longer length use a shared
end_comment

begin_comment
comment|// set of probabilities.
end_comment

begin_define
define|#
directive|define
name|DIST_STATES
value|4
end_define

begin_comment
comment|// Macro to get the index of the appropriate probability array.
end_comment

begin_define
define|#
directive|define
name|get_dist_state
parameter_list|(
name|len
parameter_list|)
define|\
value|((len)< DIST_STATES + MATCH_LEN_MIN \ 		? (len) - MATCH_LEN_MIN \ 		: DIST_STATES - 1)
end_define

begin_comment
comment|// The highest two bits of a match distance (distance slot) are encoded
end_comment

begin_comment
comment|// using six bits. See fastpos.h for more explanation.
end_comment

begin_define
define|#
directive|define
name|DIST_SLOT_BITS
value|6
end_define

begin_define
define|#
directive|define
name|DIST_SLOTS
value|(1<< DIST_SLOT_BITS)
end_define

begin_comment
comment|// Match distances up to 127 are fully encoded using probabilities. Since
end_comment

begin_comment
comment|// the highest two bits (distance slot) are always encoded using six bits,
end_comment

begin_comment
comment|// the distances 0-3 don't need any additional bits to encode, since the
end_comment

begin_comment
comment|// distance slot itself is the same as the actual distance. DIST_MODEL_START
end_comment

begin_comment
comment|// indicates the first distance slot where at least one additional bit is
end_comment

begin_comment
comment|// needed.
end_comment

begin_define
define|#
directive|define
name|DIST_MODEL_START
value|4
end_define

begin_comment
comment|// Match distances greater than 127 are encoded in three pieces:
end_comment

begin_comment
comment|//   - distance slot: the highest two bits
end_comment

begin_comment
comment|//   - direct bits: 2-26 bits below the highest two bits
end_comment

begin_comment
comment|//   - alignment bits: four lowest bits
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Direct bits don't use any probabilities.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The distance slot value of 14 is for distances 128-191 (see the table in
end_comment

begin_comment
comment|// fastpos.h to understand why).
end_comment

begin_define
define|#
directive|define
name|DIST_MODEL_END
value|14
end_define

begin_comment
comment|// Distance slots that indicate a distance<= 127.
end_comment

begin_define
define|#
directive|define
name|FULL_DISTANCES_BITS
value|(DIST_MODEL_END / 2)
end_define

begin_define
define|#
directive|define
name|FULL_DISTANCES
value|(1<< FULL_DISTANCES_BITS)
end_define

begin_comment
comment|// For match distances greater than 127, only the highest two bits and the
end_comment

begin_comment
comment|// lowest four bits (alignment) is encoded using probabilities.
end_comment

begin_define
define|#
directive|define
name|ALIGN_BITS
value|4
end_define

begin_define
define|#
directive|define
name|ALIGN_SIZE
value|(1<< ALIGN_BITS)
end_define

begin_define
define|#
directive|define
name|ALIGN_MASK
value|(ALIGN_SIZE - 1)
end_define

begin_comment
comment|// LZMA remembers the four most recent match distances. Reusing these distances
end_comment

begin_comment
comment|// tends to take less space than re-encoding the actual distance value.
end_comment

begin_define
define|#
directive|define
name|REPS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

