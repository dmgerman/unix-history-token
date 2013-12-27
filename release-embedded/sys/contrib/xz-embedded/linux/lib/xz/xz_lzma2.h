begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * LZMA2 definitions  *  * Authors: Lasse Collin<lasse.collin@tukaani.org>  *          Igor Pavlov<http://7-zip.org/>  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XZ_LZMA2_H
end_ifndef

begin_define
define|#
directive|define
name|XZ_LZMA2_H
end_define

begin_comment
comment|/* Range coder constants */
end_comment

begin_define
define|#
directive|define
name|RC_SHIFT_BITS
value|8
end_define

begin_define
define|#
directive|define
name|RC_TOP_BITS
value|24
end_define

begin_define
define|#
directive|define
name|RC_TOP_VALUE
value|(1<< RC_TOP_BITS)
end_define

begin_define
define|#
directive|define
name|RC_BIT_MODEL_TOTAL_BITS
value|11
end_define

begin_define
define|#
directive|define
name|RC_BIT_MODEL_TOTAL
value|(1<< RC_BIT_MODEL_TOTAL_BITS)
end_define

begin_define
define|#
directive|define
name|RC_MOVE_BITS
value|5
end_define

begin_comment
comment|/*  * Maximum number of position states. A position state is the lowest pb  * number of bits of the current uncompressed offset. In some places there  * are different sets of probabilities for different position states.  */
end_comment

begin_define
define|#
directive|define
name|POS_STATES_MAX
value|(1<< 4)
end_define

begin_comment
comment|/*  * This enum is used to track which LZMA symbols have occurred most recently  * and in which order. This information is used to predict the next symbol.  *  * Symbols:  *  - Literal: One 8-bit byte  *  - Match: Repeat a chunk of data at some distance  *  - Long repeat: Multi-byte match at a recently seen distance  *  - Short repeat: One-byte repeat at a recently seen distance  *  * The symbol names are in from STATE_oldest_older_previous. REP means  * either short or long repeated match, and NONLIT means any non-literal.  */
end_comment

begin_enum
enum|enum
name|lzma_state
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
block|}
enum|;
end_enum

begin_comment
comment|/* Total number of states */
end_comment

begin_define
define|#
directive|define
name|STATES
value|12
end_define

begin_comment
comment|/* The lowest 7 states indicate that the previous state was a literal. */
end_comment

begin_define
define|#
directive|define
name|LIT_STATES
value|7
end_define

begin_comment
comment|/* Indicate that the latest symbol was a literal. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|lzma_state_literal
parameter_list|(
name|enum
name|lzma_state
modifier|*
name|state
parameter_list|)
block|{
if|if
condition|(
operator|*
name|state
operator|<=
name|STATE_SHORTREP_LIT_LIT
condition|)
operator|*
name|state
operator|=
name|STATE_LIT_LIT
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|state
operator|<=
name|STATE_LIT_SHORTREP
condition|)
operator|*
name|state
operator|-=
literal|3
expr_stmt|;
else|else
operator|*
name|state
operator|-=
literal|6
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Indicate that the latest symbol was a match. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|lzma_state_match
parameter_list|(
name|enum
name|lzma_state
modifier|*
name|state
parameter_list|)
block|{
operator|*
name|state
operator|=
operator|*
name|state
operator|<
name|LIT_STATES
condition|?
name|STATE_LIT_MATCH
else|:
name|STATE_NONLIT_MATCH
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Indicate that the latest state was a long repeated match. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|lzma_state_long_rep
parameter_list|(
name|enum
name|lzma_state
modifier|*
name|state
parameter_list|)
block|{
operator|*
name|state
operator|=
operator|*
name|state
operator|<
name|LIT_STATES
condition|?
name|STATE_LIT_LONGREP
else|:
name|STATE_NONLIT_REP
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Indicate that the latest symbol was a short match. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|lzma_state_short_rep
parameter_list|(
name|enum
name|lzma_state
modifier|*
name|state
parameter_list|)
block|{
operator|*
name|state
operator|=
operator|*
name|state
operator|<
name|LIT_STATES
condition|?
name|STATE_LIT_SHORTREP
else|:
name|STATE_NONLIT_REP
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Test if the previous symbol was a literal. */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|lzma_state_is_literal
parameter_list|(
name|enum
name|lzma_state
name|state
parameter_list|)
block|{
return|return
name|state
operator|<
name|LIT_STATES
return|;
block|}
end_function

begin_comment
comment|/* Each literal coder is divided in three sections:  *   - 0x001-0x0FF: Without match byte  *   - 0x101-0x1FF: With match byte; match bit is 0  *   - 0x201-0x2FF: With match byte; match bit is 1  *  * Match byte is used when the previous LZMA symbol was something else than  * a literal (that is, it was some kind of match).  */
end_comment

begin_define
define|#
directive|define
name|LITERAL_CODER_SIZE
value|0x300
end_define

begin_comment
comment|/* Maximum number of literal coders */
end_comment

begin_define
define|#
directive|define
name|LITERAL_CODERS_MAX
value|(1<< 4)
end_define

begin_comment
comment|/* Minimum length of a match is two bytes. */
end_comment

begin_define
define|#
directive|define
name|MATCH_LEN_MIN
value|2
end_define

begin_comment
comment|/* Match length is encoded with 4, 5, or 10 bits.  *  * Length   Bits  *  2-9      4 = Choice=0 + 3 bits  * 10-17     5 = Choice=1 + Choice2=0 + 3 bits  * 18-273   10 = Choice=1 + Choice2=1 + 8 bits  */
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
comment|/*  * Maximum length of a match is 273 which is a result of the encoding  * described above.  */
end_comment

begin_define
define|#
directive|define
name|MATCH_LEN_MAX
value|(MATCH_LEN_MIN + LEN_SYMBOLS - 1)
end_define

begin_comment
comment|/*  * Different sets of probabilities are used for match distances that have  * very short match length: Lengths of 2, 3, and 4 bytes have a separate  * set of probabilities for each length. The matches with longer length  * use a shared set of probabilities.  */
end_comment

begin_define
define|#
directive|define
name|DIST_STATES
value|4
end_define

begin_comment
comment|/*  * Get the index of the appropriate probability array for decoding  * the distance slot.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|lzma_get_dist_state
parameter_list|(
name|uint32_t
name|len
parameter_list|)
block|{
return|return
name|len
operator|<
name|DIST_STATES
operator|+
name|MATCH_LEN_MIN
condition|?
name|len
operator|-
name|MATCH_LEN_MIN
else|:
name|DIST_STATES
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * The highest two bits of a 32-bit match distance are encoded using six bits.  * This six-bit value is called a distance slot. This way encoding a 32-bit  * value takes 6-36 bits, larger values taking more bits.  */
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
comment|/* Match distances up to 127 are fully encoded using probabilities. Since  * the highest two bits (distance slot) are always encoded using six bits,  * the distances 0-3 don't need any additional bits to encode, since the  * distance slot itself is the same as the actual distance. DIST_MODEL_START  * indicates the first distance slot where at least one additional bit is  * needed.  */
end_comment

begin_define
define|#
directive|define
name|DIST_MODEL_START
value|4
end_define

begin_comment
comment|/*  * Match distances greater than 127 are encoded in three pieces:  *   - distance slot: the highest two bits  *   - direct bits: 2-26 bits below the highest two bits  *   - alignment bits: four lowest bits  *  * Direct bits don't use any probabilities.  *  * The distance slot value of 14 is for distances 128-191.  */
end_comment

begin_define
define|#
directive|define
name|DIST_MODEL_END
value|14
end_define

begin_comment
comment|/* Distance slots that indicate a distance<= 127. */
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
comment|/*  * For match distances greater than 127, only the highest two bits and the  * lowest four bits (alignment) is encoded using probabilities.  */
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
comment|/* Total number of all probability variables */
end_comment

begin_define
define|#
directive|define
name|PROBS_TOTAL
value|(1846 + LITERAL_CODERS_MAX * LITERAL_CODER_SIZE)
end_define

begin_comment
comment|/*  * LZMA remembers the four most recent match distances. Reusing these  * distances tends to take less space than re-encoding the actual  * distance value.  */
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

